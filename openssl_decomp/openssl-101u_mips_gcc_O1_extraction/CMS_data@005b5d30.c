
int CMS_data(CMS_ContentInfo *cms,BIO *out,uint flags)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  BIO *pBVar3;
  
  pAVar1 = CMS_get0_type(cms);
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar1);
  if (iVar2 == 0x15) {
    pBVar3 = CMS_dataInit(cms,(BIO *)0x0);
    if (pBVar3 != (BIO *)0x0) {
      iVar2 = cms_copy_content(out,pBVar3,flags);
      (*(code *)PTR_BIO_free_all_006a6e74)(pBVar3);
      return iVar2;
    }
  }
  else {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x6d,0x8f,"cms_smime.c",0x90);
  }
  return 0;
}

