
int SMIME_write_CMS(BIO *bio,CMS_ContentInfo *cms,BIO *data,int flags)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  pAVar2 = CMS_get0_eContentType(cms);
  uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar2);
  if (iVar1 == 0x16) {
    uVar4 = *(undefined4 *)(*(int *)(cms + 4) + 4);
  }
  else {
    uVar4 = 0;
  }
  iVar1 = (*(code *)PTR_SMIME_write_ASN1_006a91c0)
                    (bio,cms,data,flags,iVar1,uVar3,uVar4,PTR_CMS_ContentInfo_it_006a92d0);
  return iVar1;
}

