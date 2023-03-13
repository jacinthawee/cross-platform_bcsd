
int CMS_add_smimecap(CMS_SignerInfo *si,stack_st_X509_ALGOR *algs)

{
  int len;
  int iVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (uchar *)0x0;
  len = i2d_X509_ALGORS(algs,&local_14);
  iVar1 = 0;
  if (0 < len) {
    iVar1 = CMS_signed_add1_attr_by_NID(si,0xa7,0x10,local_14,len);
    CRYPTO_free(local_14);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

