
int CMS_decrypt_set1_password(CMS_ContentInfo *cms,uchar *pass,ssize_t passlen)

{
  stack_st_CMS_RecipientInfo *psVar1;
  int iVar2;
  CMS_RecipientInfo *ri;
  int iVar3;
  int iVar4;
  
  psVar1 = CMS_get0_RecipientInfos(cms);
  iVar3 = 0;
  do {
    do {
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar1);
      if (iVar2 <= iVar3) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0xa6,0x84,"cms_smime.c",0x2d7);
        return 0;
      }
      iVar4 = iVar3 + 1;
      ri = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar1,iVar3);
      iVar2 = CMS_RecipientInfo_type(ri);
      iVar3 = iVar4;
    } while (iVar2 != 3);
    CMS_RecipientInfo_set0_password(ri,pass,passlen);
    iVar2 = CMS_RecipientInfo_decrypt(cms,ri);
    CMS_RecipientInfo_set0_password(ri,(uchar *)0x0,0);
  } while (iVar2 < 1);
  return 1;
}

