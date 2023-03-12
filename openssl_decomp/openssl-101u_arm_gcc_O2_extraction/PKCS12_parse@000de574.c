
int PKCS12_parse(PKCS12 *p12,char *pass,EVP_PKEY **pkey,X509 **cert,stack_st_X509 **ca)

{
  int iVar1;
  X509 *st;
  _STACK *p_Var2;
  int iVar3;
  PKCS7 *p7;
  _STACK *st_00;
  X509 *x509;
  stack_st_X509 **ppsVar4;
  X509 *a;
  X509 *pXVar5;
  X509 *pXVar6;
  char *local_2c;
  
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
    if (iVar1 == 0) {
      a = (X509 *)PKCS12_verify_mac(p12,"",0);
      if (a == (X509 *)0x0) {
        iVar1 = 0x73;
        goto LAB_000de786;
      }
      local_2c = "";
    }
    else {
      local_2c = (char *)0x0;
    }
  }
  else {
    a = (X509 *)PKCS12_verify_mac(p12,pass,-1);
    local_2c = pass;
    if (a == (X509 *)0x0) {
      iVar1 = 0x77;
LAB_000de786:
      ERR_put_error(0x23,0x76,0x71,"p12_kiss.c",iVar1);
      st = a;
      goto LAB_000de688;
    }
  }
  st = (X509 *)sk_new_null();
  if (st == (X509 *)0x0) {
    ERR_put_error(0x23,0x76,0x41,"p12_kiss.c",0x7f);
    return 0;
  }
  p_Var2 = (_STACK *)PKCS12_unpack_authsafes(p12);
  if (p_Var2 != (_STACK *)0x0) {
    for (iVar1 = 0; iVar3 = sk_num(p_Var2), iVar1 < iVar3; iVar1 = iVar1 + 1) {
      p7 = (PKCS7 *)sk_value(p_Var2,iVar1);
      iVar3 = OBJ_obj2nid(p7->type);
      if (iVar3 == 0x15) {
        st_00 = (_STACK *)PKCS12_unpack_p7data(p7);
joined_r0x000de660:
        if (st_00 == (_STACK *)0x0) {
          sk_pop_free(p_Var2,PKCS7_free + 1);
          goto LAB_000de670;
        }
        iVar3 = parse_bags_constprop_1(st_00,local_2c,pkey,st);
        if (iVar3 == 0) {
          sk_pop_free(st_00,PKCS12_SAFEBAG_free + 1);
          sk_pop_free(p_Var2,PKCS7_free + 1);
          goto LAB_000de670;
        }
        sk_pop_free(st_00,PKCS12_SAFEBAG_free + 1);
      }
      else if (iVar3 == 0x1a) {
        st_00 = (_STACK *)PKCS12_unpack_p7encdata(p7,local_2c,-1);
        goto joined_r0x000de660;
      }
    }
    sk_pop_free(p_Var2,PKCS7_free + 1);
LAB_000de6d2:
    x509 = (X509 *)sk_pop((_STACK *)st);
    do {
      if (x509 == (X509 *)0x0) {
        sk_pop_free((_STACK *)st,X509_free);
        return 1;
      }
      if ((((pkey == (EVP_PKEY **)0x0) || (*pkey == (EVP_PKEY *)0x0)) || (cert == (X509 **)0x0)) ||
         (a = *cert, a != (X509 *)0x0)) {
        ppsVar4 = ca;
        if (ca != (stack_st_X509 **)0x0) {
          ppsVar4 = (stack_st_X509 **)0x1;
        }
        a = x509;
        if (ppsVar4 != (stack_st_X509 **)0x0) goto LAB_000de720;
      }
      else {
        ERR_set_mark();
        iVar1 = X509_check_private_key(x509,*pkey);
        if (iVar1 == 0) {
          a = x509;
          pXVar5 = (X509 *)ca;
          pXVar6 = (X509 *)0x1;
          if (ca != (stack_st_X509 **)0x0) {
            pXVar5 = (X509 *)0x1;
          }
        }
        else {
          *cert = x509;
          pXVar5 = a;
          pXVar6 = a;
        }
        ERR_pop_to_mark();
        if (pXVar5 != (X509 *)0x0) goto LAB_000de720;
        if (pXVar6 == (X509 *)0x0) goto LAB_000de6d2;
      }
      X509_free(a);
      x509 = (X509 *)sk_pop((_STACK *)st);
    } while( true );
  }
LAB_000de670:
  a = (X509 *)0x0;
  ERR_put_error(0x23,0x76,0x72,"p12_kiss.c",0x84);
LAB_000de688:
  if ((pkey != (EVP_PKEY **)0x0) && (*pkey != (EVP_PKEY *)0x0)) {
    EVP_PKEY_free(*pkey);
  }
  if ((cert != (X509 **)0x0) && (*cert != (X509 *)0x0)) {
    X509_free(*cert);
  }
  if (a != (X509 *)0x0) {
    X509_free(a);
  }
  if (st != (X509 *)0x0) {
    sk_pop_free((_STACK *)st,X509_free);
  }
  return 0;
LAB_000de720:
  p_Var2 = (_STACK *)*ca;
  if (p_Var2 == (_STACK *)0x0) {
    p_Var2 = sk_new_null();
    *ca = (stack_st_X509 *)p_Var2;
    if (p_Var2 == (_STACK *)0x0) goto LAB_000de688;
  }
  iVar1 = sk_push(p_Var2,a);
  if (iVar1 == 0) goto LAB_000de688;
  goto LAB_000de6d2;
}

