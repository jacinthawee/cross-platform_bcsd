
int PKCS12_parse(PKCS12 *p12,char *pass,EVP_PKEY **pkey,X509 **cert,stack_st_X509 **ca)

{
  EVP_PKEY *pkey_00;
  int iVar1;
  _STACK *p_Var2;
  int iVar3;
  PKCS7 *p7;
  _STACK *st;
  X509 *pXVar4;
  _STACK *local_20;
  
  if (p12 == (PKCS12 *)0x0) {
    ERR_put_error(0x23,0x76,0x69,"p12_kiss.c",0x59);
    return 0;
  }
  if (pkey != (EVP_PKEY **)0x0) {
    *pkey = (EVP_PKEY *)0x0;
  }
  if (cert != (X509 **)0x0) {
    *cert = (X509 *)0x0;
  }
  if ((pass == (char *)0x0) || (*pass == '\0')) {
    iVar1 = PKCS12_verify_mac(p12,(char *)0x0,0);
    pass = (char *)0x0;
    if (iVar1 == 0) {
      iVar1 = PKCS12_verify_mac(p12,"",0);
      pass = "";
      if (iVar1 == 0) {
        iVar1 = 0x6e;
        goto LAB_081844cf;
      }
    }
LAB_08184188:
    local_20 = sk_new_null();
    if (local_20 == (_STACK *)0x0) {
      ERR_put_error(0x23,0x76,0x41,"p12_kiss.c",0x7b);
      return 0;
    }
    p_Var2 = (_STACK *)PKCS12_unpack_authsafes(p12);
    if (p_Var2 != (_STACK *)0x0) {
      for (iVar1 = 0; iVar3 = sk_num(p_Var2), iVar1 < iVar3; iVar1 = iVar1 + 1) {
        p7 = (PKCS7 *)sk_value(p_Var2,iVar1);
        iVar3 = OBJ_obj2nid(p7->type);
        if (iVar3 == 0x15) {
          st = (_STACK *)PKCS12_unpack_p7data(p7);
joined_r0x08184253:
          if (st == (_STACK *)0x0) {
            sk_pop_free(p_Var2,PKCS7_free);
            goto LAB_0818426a;
          }
          iVar3 = parse_bags_constprop_1(local_20);
          if (iVar3 == 0) {
            sk_pop_free(st,PKCS12_SAFEBAG_free);
            sk_pop_free(p_Var2,PKCS7_free);
            goto LAB_0818426a;
          }
          sk_pop_free(st,PKCS12_SAFEBAG_free);
        }
        else if (iVar3 == 0x1a) {
          st = (_STACK *)PKCS12_unpack_p7encdata(p7,pass,-1);
          goto joined_r0x08184253;
        }
      }
      sk_pop_free(p_Var2,PKCS7_free);
      do {
        if (pkey == (EVP_PKEY **)0x0) {
          if (ca != (stack_st_X509 **)0x0) goto LAB_081843f0;
          pXVar4 = (X509 *)sk_pop(local_20);
          if (pXVar4 == (X509 *)0x0) goto LAB_08184500;
        }
        else {
          if (ca != (stack_st_X509 **)0x0) goto LAB_08184328;
          while( true ) {
            pXVar4 = (X509 *)sk_pop(local_20);
            if (pXVar4 == (X509 *)0x0) goto LAB_08184500;
            if (((cert == (X509 **)0x0) || (*pkey == (EVP_PKEY *)0x0)) ||
               ((*cert != (X509 *)0x0 || (iVar1 = X509_check_private_key(pXVar4,*pkey), iVar1 == 0))
               )) break;
            *cert = pXVar4;
          }
        }
        X509_free(pXVar4);
      } while( true );
    }
LAB_0818426a:
    ERR_put_error(0x23,0x76,0x72,"p12_kiss.c",0x81);
  }
  else {
    iVar1 = PKCS12_verify_mac(p12,pass,-1);
    if (iVar1 != 0) goto LAB_08184188;
    iVar1 = 0x72;
LAB_081844cf:
    ERR_put_error(0x23,0x76,0x71,"p12_kiss.c",iVar1);
    local_20 = (_STACK *)0x0;
  }
  pXVar4 = (X509 *)0x0;
  if (pkey != (EVP_PKEY **)0x0) goto LAB_08184293;
  if (cert == (X509 **)0x0) goto LAB_081842cf;
LAB_081842ad:
  if (*cert != (X509 *)0x0) {
    X509_free(*cert);
  }
  goto LAB_081842bf;
LAB_081843f0:
  do {
    pXVar4 = (X509 *)sk_pop(local_20);
    if (pXVar4 == (X509 *)0x0) goto LAB_08184500;
    p_Var2 = (_STACK *)*ca;
    if (p_Var2 == (_STACK *)0x0) {
      p_Var2 = sk_new_null();
      *ca = (stack_st_X509 *)p_Var2;
      if (p_Var2 == (_STACK *)0x0) break;
    }
    iVar1 = sk_push(p_Var2,pXVar4);
  } while (iVar1 != 0);
  if (cert != (X509 **)0x0) goto LAB_081842ad;
  goto LAB_081842c3;
  while( true ) {
    p_Var2 = (_STACK *)*ca;
    if (p_Var2 == (_STACK *)0x0) {
      p_Var2 = sk_new_null();
      *ca = (stack_st_X509 *)p_Var2;
      if (p_Var2 == (_STACK *)0x0) {
        pkey_00 = *pkey;
        goto joined_r0x081844a3;
      }
    }
    iVar1 = sk_push(p_Var2,pXVar4);
    if (iVar1 == 0) break;
LAB_08184328:
    pXVar4 = (X509 *)sk_pop(local_20);
    if (pXVar4 == (X509 *)0x0) {
LAB_08184500:
      sk_pop_free(local_20,X509_free);
      return 1;
    }
    if ((((*pkey != (EVP_PKEY *)0x0) && (cert != (X509 **)0x0)) && (*cert == (X509 *)0x0)) &&
       (iVar1 = X509_check_private_key(pXVar4,*pkey), iVar1 != 0)) {
      *cert = pXVar4;
      goto LAB_08184328;
    }
  }
LAB_08184293:
  pkey_00 = *pkey;
joined_r0x081844a3:
  if (pkey_00 != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey_00);
  }
  if (cert != (X509 **)0x0) goto LAB_081842ad;
LAB_081842bf:
  if (pXVar4 != (X509 *)0x0) {
LAB_081842c3:
    X509_free(pXVar4);
  }
LAB_081842cf:
  if (local_20 != (_STACK *)0x0) {
    sk_pop_free(local_20,X509_free);
  }
  return 0;
}

