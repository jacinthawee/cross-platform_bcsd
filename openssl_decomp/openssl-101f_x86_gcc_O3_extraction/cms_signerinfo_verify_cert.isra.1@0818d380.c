
undefined4 __regparm3
cms_signerinfo_verify_cert_isra_1
          (CMS_SignerInfo *param_1_00,X509_STORE *param_2,stack_st_X509 *param_3,
          stack_st_X509_CRL *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int in_GS_OFFSET;
  X509 *local_9c;
  X509_STORE_CTX local_98;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  CMS_SignerInfo_get0_algs
            (param_1_00,(EVP_PKEY **)0x0,&local_9c,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
  iVar1 = X509_STORE_CTX_init(&local_98,param_2,local_9c,param_3);
  if (iVar1 == 0) {
    uVar3 = 0;
    ERR_put_error(0x2e,0x99,0x8d,"cms_smime.c",0x124);
  }
  else {
    X509_STORE_CTX_set_default(&local_98,"smime_sign");
    if (param_1 != (stack_st_X509_CRL *)0x0) {
      X509_STORE_CTX_set0_crls(&local_98,param_1);
    }
    uVar3 = 1;
    iVar1 = X509_verify_cert(&local_98);
    if (iVar1 < 1) {
      iVar1 = X509_STORE_CTX_get_error(&local_98);
      ERR_put_error(0x2e,0x99,100,"cms_smime.c",0x130);
      uVar3 = 0;
      pcVar2 = X509_verify_cert_error_string(iVar1);
      ERR_add_error_data(2,"Verify error:",pcVar2);
    }
  }
  X509_STORE_CTX_cleanup(&local_98);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

