
int PKCS12_parse(PKCS12 *p12,char *pass,EVP_PKEY **pkey,X509 **cert,stack_st_X509 **ca)

{
  int iVar1;
  X509 *st;
  _STACK *p_Var2;
  int iVar3;
  PKCS7 *p7;
  _STACK *st_00;
  X509 *pXVar4;
  
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
    pass = (char *)0x0;
    iVar1 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar1 == 0) {
      pXVar4 = (X509 *)PKCS12_verify_mac(p12,"",0);
      pass = "";
      if (pXVar4 == (X509 *)0x0) {
        iVar1 = 0x6e;
        goto LAB_000e0866;
      }
    }
LAB_000e065c:
    st = (X509 *)sk_new_null();
    if (st == (X509 *)0x0) {
      ERR_put_error(0x23,0x76,0x41,"p12_kiss.c",0x7b);
      return 0;
    }
    p_Var2 = (_STACK *)PKCS12_unpack_authsafes(p12);
    if (p_Var2 == (_STACK *)0x0) {
LAB_000e06f0:
      pXVar4 = (X509 *)0x0;
      ERR_put_error(0x23,0x76,0x72,"p12_kiss.c",0x81);
    }
    else {
      for (iVar1 = 0; iVar3 = sk_num(p_Var2), iVar1 < iVar3; iVar1 = iVar1 + 1) {
        p7 = (PKCS7 *)sk_value(p_Var2,iVar1);
        iVar3 = OBJ_obj2nid(p7->type);
        if (iVar3 == 0x15) {
          st_00 = (_STACK *)PKCS12_unpack_p7data(p7);
joined_r0x000e06e0:
          if (st_00 == (_STACK *)0x0) {
            sk_pop_free(p_Var2,PKCS7_free + 1);
            goto LAB_000e06f0;
          }
          iVar3 = parse_bags_constprop_1(st_00,pass,pkey,st);
          if (iVar3 == 0) {
            sk_pop_free(st_00,PKCS12_SAFEBAG_free + 1);
            sk_pop_free(p_Var2,PKCS7_free + 1);
            goto LAB_000e06f0;
          }
          sk_pop_free(st_00,PKCS12_SAFEBAG_free + 1);
        }
        else if (iVar3 == 0x1a) {
          st_00 = (_STACK *)PKCS12_unpack_p7encdata(p7,pass,-1);
          goto joined_r0x000e06e0;
        }
      }
      sk_pop_free(p_Var2,PKCS7_free + 1);
      if (ca == (stack_st_X509 **)0x0) {
        do {
          if ((cert == (X509 **)0x0) || (pkey == (EVP_PKEY **)0x0)) {
            pXVar4 = (X509 *)sk_pop((_STACK *)st);
            if (pXVar4 == (X509 *)0x0) goto LAB_000e0832;
          }
          else {
            while( true ) {
              pXVar4 = (X509 *)sk_pop((_STACK *)st);
              if (pXVar4 == (X509 *)0x0) goto LAB_000e0832;
              if (((*pkey == (EVP_PKEY *)0x0) || (*cert != (X509 *)0x0)) ||
                 (iVar1 = X509_check_private_key(pXVar4,*pkey), iVar1 == 0)) break;
              *cert = pXVar4;
            }
          }
          X509_free(pXVar4);
        } while( true );
      }
      if (pkey == (EVP_PKEY **)0x0) {
        do {
          pXVar4 = (X509 *)sk_pop((_STACK *)st);
          if (pXVar4 == (X509 *)0x0) {
LAB_000e0832:
            sk_pop_free((_STACK *)st,X509_free);
            return 1;
          }
          p_Var2 = (_STACK *)*ca;
          if (p_Var2 == (_STACK *)0x0) {
            p_Var2 = sk_new_null();
            *ca = (stack_st_X509 *)p_Var2;
            if (p_Var2 == (_STACK *)0x0) break;
          }
          iVar1 = sk_push(p_Var2,pXVar4);
        } while (iVar1 != 0);
        goto LAB_000e0718;
      }
      if (cert == (X509 **)0x0) {
        do {
          pXVar4 = (X509 *)sk_pop((_STACK *)st);
          if (pXVar4 == (X509 *)0x0) goto LAB_000e0832;
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
        do {
          while( true ) {
            pXVar4 = (X509 *)sk_pop((_STACK *)st);
            if (pXVar4 == (X509 *)0x0) goto LAB_000e0832;
            if (((*pkey == (EVP_PKEY *)0x0) || (*cert != (X509 *)0x0)) ||
               (iVar1 = X509_check_private_key(pXVar4,*pkey), iVar1 == 0)) break;
            *cert = pXVar4;
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
    }
  }
  else {
    pXVar4 = (X509 *)PKCS12_verify_mac(p12,pass,-1);
    if (pXVar4 != (X509 *)0x0) goto LAB_000e065c;
    iVar1 = 0x72;
LAB_000e0866:
    ERR_put_error(0x23,0x76,0x71,"p12_kiss.c",iVar1);
    st = pXVar4;
  }
  if ((pkey != (EVP_PKEY **)0x0) && (*pkey != (EVP_PKEY *)0x0)) {
    EVP_PKEY_free(*pkey);
  }
LAB_000e0718:
  if ((cert != (X509 **)0x0) && (*cert != (X509 *)0x0)) {
    X509_free(*cert);
  }
  if (pXVar4 != (X509 *)0x0) {
    X509_free(pXVar4);
  }
  if (st != (X509 *)0x0) {
    sk_pop_free((_STACK *)st,X509_free);
  }
  return 0;
}

