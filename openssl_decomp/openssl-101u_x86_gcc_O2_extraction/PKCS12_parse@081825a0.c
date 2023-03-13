
int PKCS12_parse(PKCS12 *p12,char *pass,EVP_PKEY **pkey,X509 **cert,stack_st_X509 **ca)

{
  int iVar1;
  _STACK *st;
  _STACK *p_Var2;
  int iVar3;
  PKCS7 *p7;
  _STACK *st_00;
  X509 *pXVar4;
  
  if (p12 == (PKCS12 *)0x0) {
    ERR_put_error(0x23,0x76,0x69,"p12_kiss.c",0x5b);
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
        iVar1 = 0x73;
        goto LAB_08182957;
      }
    }
LAB_0818260c:
    st = sk_new_null();
    if (st == (_STACK *)0x0) {
      ERR_put_error(0x23,0x76,0x41,"p12_kiss.c",0x7f);
      return 0;
    }
    p_Var2 = (_STACK *)PKCS12_unpack_authsafes(p12);
    if (p_Var2 == (_STACK *)0x0) {
LAB_081826e1:
      ERR_put_error(0x23,0x76,0x72,"p12_kiss.c",0x84);
      goto LAB_081826fc;
    }
    for (iVar1 = 0; iVar3 = sk_num(p_Var2), iVar1 < iVar3; iVar1 = iVar1 + 1) {
      p7 = (PKCS7 *)sk_value(p_Var2,iVar1);
      iVar3 = OBJ_obj2nid(p7->type);
      if (iVar3 == 0x15) {
        st_00 = (_STACK *)PKCS12_unpack_p7data(p7);
joined_r0x081826ce:
        if (st_00 == (_STACK *)0x0) {
          sk_pop_free(p_Var2,PKCS7_free);
          goto LAB_081826e1;
        }
        iVar3 = parse_bags_constprop_1(st);
        if (iVar3 == 0) {
          sk_pop_free(st_00,PKCS12_SAFEBAG_free);
          sk_pop_free(p_Var2,PKCS7_free);
          goto LAB_081826e1;
        }
        sk_pop_free(st_00,PKCS12_SAFEBAG_free);
      }
      else if (iVar3 == 0x1a) {
        st_00 = (_STACK *)PKCS12_unpack_p7encdata(p7,pass,-1);
        goto joined_r0x081826ce;
      }
    }
    sk_pop_free(p_Var2,PKCS7_free);
    if (pkey == (EVP_PKEY **)0x0) goto LAB_08182864;
LAB_0818273d:
    if (ca == (stack_st_X509 **)0x0) {
      while( true ) {
        pXVar4 = (X509 *)sk_pop(st);
        if (pXVar4 == (X509 *)0x0) goto LAB_08182998;
        if (((*pkey == (EVP_PKEY *)0x0) || (cert == (X509 **)0x0)) || (*cert != (X509 *)0x0))
        goto LAB_0818284c;
        ERR_set_mark();
        iVar1 = X509_check_private_key(pXVar4,*pkey);
        if (iVar1 == 0) break;
        *cert = pXVar4;
        ERR_pop_to_mark();
      }
      ERR_pop_to_mark();
LAB_0818284c:
      do {
        X509_free(pXVar4);
        if (pkey != (EVP_PKEY **)0x0) goto LAB_0818273d;
LAB_08182864:
        if (ca != (stack_st_X509 **)0x0) goto LAB_08182878;
        pXVar4 = (X509 *)sk_pop(st);
        if (pXVar4 == (X509 *)0x0) goto LAB_08182998;
      } while( true );
    }
LAB_08182758:
    do {
      pXVar4 = (X509 *)sk_pop(st);
      if (pXVar4 == (X509 *)0x0) {
LAB_08182998:
        sk_pop_free(st,X509_free);
        return 1;
      }
      if (((*pkey != (EVP_PKEY *)0x0) && (cert != (X509 **)0x0)) && (*cert == (X509 *)0x0)) {
        ERR_set_mark();
        iVar1 = X509_check_private_key(pXVar4,*pkey);
        if (iVar1 != 0) {
          *cert = pXVar4;
          ERR_pop_to_mark();
          goto LAB_08182758;
        }
        ERR_pop_to_mark();
      }
      p_Var2 = (_STACK *)*ca;
      if (p_Var2 == (_STACK *)0x0) {
        p_Var2 = sk_new_null();
        *ca = (stack_st_X509 *)p_Var2;
        if (p_Var2 == (_STACK *)0x0) break;
      }
      iVar1 = sk_push(p_Var2,pXVar4);
    } while (iVar1 != 0);
  }
  else {
    iVar1 = PKCS12_verify_mac(p12,pass,-1);
    if (iVar1 != 0) goto LAB_0818260c;
    iVar1 = 0x77;
LAB_08182957:
    st = (_STACK *)0x0;
    ERR_put_error(0x23,0x76,0x71,"p12_kiss.c",iVar1);
LAB_081826fc:
    pXVar4 = (X509 *)0x0;
    if (pkey == (EVP_PKEY **)0x0) {
      if (cert == (X509 **)0x0) goto LAB_081827ea;
      goto LAB_081827c4;
    }
  }
  if (*pkey != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(*pkey);
  }
  if (cert != (X509 **)0x0) {
LAB_081827c4:
    if (*cert != (X509 *)0x0) {
      X509_free(*cert);
    }
  }
  if (pXVar4 == (X509 *)0x0) goto LAB_081827ea;
  goto LAB_081827de;
LAB_08182878:
  do {
    pXVar4 = (X509 *)sk_pop(st);
    if (pXVar4 == (X509 *)0x0) goto LAB_08182998;
    p_Var2 = (_STACK *)*ca;
    if (p_Var2 == (_STACK *)0x0) {
      p_Var2 = sk_new_null();
      *ca = (stack_st_X509 *)p_Var2;
      if (p_Var2 == (_STACK *)0x0) break;
    }
    iVar1 = sk_push(p_Var2,pXVar4);
  } while (iVar1 != 0);
  if (cert != (X509 **)0x0) goto LAB_081827c4;
LAB_081827de:
  X509_free(pXVar4);
LAB_081827ea:
  if (st != (_STACK *)0x0) {
    sk_pop_free(st,X509_free);
  }
  return 0;
}

