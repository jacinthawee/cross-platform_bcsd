
int CMS_RecipientInfo_set0_key(CMS_RecipientInfo *ri,uchar *key,size_t keylen)

{
  int iVar1;
  
  if (*(int *)ri == 2) {
    iVar1 = *(int *)(ri + 4);
    *(uchar **)(iVar1 + 0x10) = key;
    *(size_t *)(iVar1 + 0x14) = keylen;
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x90,0x7b,"cms_env.c",0x27a);
  return 0;
}

