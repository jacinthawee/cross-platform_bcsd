
int CMS_decrypt_set1_key(CMS_ContentInfo *cms,uchar *key,size_t keylen,uchar *id,size_t idlen)

{
  stack_st_CMS_RecipientInfo *psVar1;
  int iVar2;
  CMS_RecipientInfo *pCVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  psVar1 = CMS_get0_RecipientInfos(cms);
  if (id == (uchar *)0x0) {
    while (iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar1), iVar4 < iVar2) {
      pCVar3 = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a6e24)(psVar1,iVar4);
      iVar2 = CMS_RecipientInfo_type(pCVar3);
      if (iVar2 == 2) {
        CMS_RecipientInfo_set0_key(pCVar3,key,keylen);
        iVar2 = CMS_RecipientInfo_decrypt(cms,pCVar3);
        CMS_RecipientInfo_set0_key(pCVar3,(uchar *)0x0,0);
        if (0 < iVar2) {
          return 1;
        }
        iVar4 = iVar4 + 1;
        (*(code *)PTR_ERR_clear_error_006a6ee0)();
      }
      else {
        iVar4 = iVar4 + 1;
      }
    }
  }
  else {
    while (iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar1), iVar4 < iVar2) {
      iVar5 = iVar4 + 1;
      pCVar3 = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a6e24)(psVar1,iVar4);
      iVar2 = CMS_RecipientInfo_type(pCVar3);
      iVar4 = iVar5;
      if ((iVar2 == 2) && (iVar2 = CMS_RecipientInfo_kekri_id_cmp(pCVar3,id,idlen), iVar2 == 0)) {
        CMS_RecipientInfo_set0_key(pCVar3,key,keylen);
        iVar4 = CMS_RecipientInfo_decrypt(cms,pCVar3);
        CMS_RecipientInfo_set0_key(pCVar3,(uchar *)0x0,0);
        if (0 < iVar4) {
          return 1;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x71,0x70,"cms_smime.c",0x28a);
        return 0;
      }
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x71,0x84,"cms_smime.c",0x291);
  return 0;
}

