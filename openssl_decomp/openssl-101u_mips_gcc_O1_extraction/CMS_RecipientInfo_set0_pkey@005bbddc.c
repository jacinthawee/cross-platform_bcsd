
int CMS_RecipientInfo_set0_pkey(CMS_RecipientInfo *ri,EVP_PKEY *pkey)

{
  if (*(int *)ri == 0) {
    *(EVP_PKEY **)(*(int *)(ri + 4) + 0x14) = pkey;
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x91,0x7c,"cms_env.c",0x115);
  return 0;
}

