
int cms_signerinfo_verify_cert_isra_1
              (CMS_SignerInfo *param_1,X509_STORE *param_2,stack_st_X509 *param_3,
              stack_st_X509_CRL *param_4)

{
  int iVar1;
  int n;
  char *pcVar2;
  X509 *local_a4;
  X509_STORE_CTX XStack_a0;
  
  CMS_SignerInfo_get0_algs(param_1,(EVP_PKEY **)0x0,&local_a4,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0)
  ;
  iVar1 = X509_STORE_CTX_init(&XStack_a0,param_2,local_a4,param_3);
  if (iVar1 == 0) {
    ERR_put_error(0x2e,0x99,0x8d,"cms_smime.c",0x113);
  }
  else {
    X509_STORE_CTX_set_default(&XStack_a0,"smime_sign");
    if (param_4 != (stack_st_X509_CRL *)0x0) {
      X509_STORE_CTX_set0_crls(&XStack_a0,param_4);
    }
    iVar1 = X509_verify_cert(&XStack_a0);
    if (iVar1 < 1) {
      iVar1 = 0;
      n = X509_STORE_CTX_get_error(&XStack_a0);
      ERR_put_error(0x2e,0x99,100,"cms_smime.c",0x11e);
      pcVar2 = X509_verify_cert_error_string(n);
      ERR_add_error_data(2,"Verify error:",pcVar2);
    }
    else {
      iVar1 = 1;
    }
  }
  X509_STORE_CTX_cleanup(&XStack_a0);
  return iVar1;
}

