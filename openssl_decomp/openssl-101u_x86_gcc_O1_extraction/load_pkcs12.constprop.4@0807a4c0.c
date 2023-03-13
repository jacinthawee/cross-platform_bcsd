
int __regparm3
load_pkcs12_constprop_4
          (BIO *param_1_00,BIO *param_2_00,undefined4 param_3_00,code *param_1,undefined4 param_2,
          EVP_PKEY **param_3,X509 **param_4)

{
  PKCS12 *p12;
  int iVar1;
  char *pass;
  int in_GS_OFFSET;
  char local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  p12 = d2i_PKCS12_bio(param_2_00,(PKCS12 **)0x0);
  if (p12 == (PKCS12 *)0x0) {
    iVar1 = 0;
    BIO_printf(param_1_00,"Error loading PKCS12 file for %s\n",param_3_00);
    goto LAB_0807a554;
  }
  iVar1 = PKCS12_verify_mac(p12,"",0);
  if (iVar1 == 0) {
    iVar1 = PKCS12_verify_mac(p12,(char *)0x0,0);
    if (iVar1 != 0) goto LAB_0807a52d;
    if (param_1 == (code *)0x0) {
      param_1 = password_callback;
    }
    pass = local_420;
    iVar1 = (*param_1)(pass,0x400,0,param_2);
    if (-1 < iVar1) {
      if (iVar1 < 0x400) {
        local_420[iVar1] = '\0';
      }
      iVar1 = PKCS12_verify_mac(p12,pass,iVar1);
      if (iVar1 == 0) {
        iVar1 = 0;
        BIO_printf(param_1_00,"Mac verify error (wrong password?) in PKCS12 file for %s\n",
                   param_3_00);
        goto LAB_0807a548;
      }
      goto LAB_0807a532;
    }
    iVar1 = 0;
    BIO_printf(param_1_00,"Passpharse callback error for %s\n",param_3_00);
  }
  else {
LAB_0807a52d:
    pass = "";
LAB_0807a532:
    iVar1 = PKCS12_parse(p12,pass,param_3,param_4,(stack_st_X509 **)0x0);
  }
LAB_0807a548:
  PKCS12_free(p12);
LAB_0807a554:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

