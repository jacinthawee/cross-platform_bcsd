
int CMS_RecipientInfo_ktri_get0_algs
              (CMS_RecipientInfo *ri,EVP_PKEY **pk,X509 **recip,X509_ALGOR **palg)

{
  int iVar1;
  
  if (*(int *)ri != 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x8e,0x7c,"cms_env.c",0xf3);
    return 0;
  }
  iVar1 = *(int *)(ri + 4);
  if (pk != (EVP_PKEY **)0x0) {
    *pk = *(EVP_PKEY **)(iVar1 + 0x14);
  }
  if (recip != (X509 **)0x0) {
    *recip = *(X509 **)(iVar1 + 0x10);
  }
  if (palg != (X509_ALGOR **)0x0) {
    *palg = *(X509_ALGOR **)(iVar1 + 8);
    return 1;
  }
  return 1;
}

