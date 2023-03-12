
void load_pkcs12_constprop_3
               (BIO *param_1,BIO *param_2,undefined4 param_3,code *param_4,undefined4 param_5,
               EVP_PKEY **param_6,X509 **param_7)

{
  PKCS12 *p12;
  int iVar1;
  PKCS12 *pPVar2;
  char *pass;
  char acStack_42c [1024];
  int local_2c;
  
  local_2c = __TMC_END__;
  p12 = d2i_PKCS12_bio(param_2,(PKCS12 **)0x0);
  if (p12 == (PKCS12 *)0x0) {
    BIO_printf(param_1,"Error loading PKCS12 file for %s\n",param_3);
    goto LAB_00033470;
  }
  iVar1 = PKCS12_verify_mac(p12,"",0);
  if ((iVar1 == 0) &&
     (pPVar2 = (PKCS12 *)PKCS12_verify_mac(p12,(char *)0x0,0), pPVar2 == (PKCS12 *)0x0)) {
    if (param_4 == (code *)0x0) {
      param_4 = password_callback + 1;
    }
    iVar1 = (*param_4)(acStack_42c,0x400,0);
    if (iVar1 < 0) {
      BIO_printf(param_1,"Passpharse callback error for %s\n",param_3);
    }
    else {
      if (iVar1 < 0x400) {
        acStack_42c[iVar1] = '\0';
      }
      pPVar2 = (PKCS12 *)PKCS12_verify_mac(p12,acStack_42c,iVar1);
      pass = acStack_42c;
      if (pPVar2 != (PKCS12 *)0x0) goto LAB_0003345a;
      BIO_printf(param_1,"Mac verify error (wrong password?) in PKCS12 file for %s\n",param_3);
    }
  }
  else {
    pass = "";
LAB_0003345a:
    pPVar2 = (PKCS12 *)PKCS12_parse(p12,pass,param_6,param_7,(stack_st_X509 **)0x0);
  }
  PKCS12_free(p12);
  p12 = pPVar2;
LAB_00033470:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(p12);
  }
  return;
}

