
int CMS_digest_verify(CMS_ContentInfo *cms,BIO *dcont,BIO *out,uint flags)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  BIO *pBVar3;
  BIO *pBVar4;
  ASN1_OCTET_STRING **ppAVar5;
  
  pAVar1 = CMS_get0_type(cms);
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar1);
  if (iVar2 != 0x19) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x76,0x90,"cms_smime.c",0xb0);
    return 0;
  }
  if ((dcont == (BIO *)0x0) &&
     ((ppAVar5 = CMS_get0_content(cms), ppAVar5 == (ASN1_OCTET_STRING **)0x0 ||
      (*ppAVar5 == (ASN1_OCTET_STRING *)0x0)))) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,99,0x7f,"cms_smime.c",0x77);
    iVar2 = 0;
  }
  else {
    pBVar3 = CMS_dataInit(cms,dcont);
    if (pBVar3 == (BIO *)0x0) {
      return 0;
    }
    iVar2 = cms_copy_content(out,pBVar3,flags);
    if (iVar2 != 0) {
      iVar2 = cms_DigestedData_do_final(cms,pBVar3,1);
    }
    if (dcont == (BIO *)0x0) {
      (*(code *)PTR_BIO_free_all_006a6e74)(pBVar3);
    }
    else {
      do {
        pBVar4 = (BIO *)(*(code *)PTR_BIO_pop_006a79c8)(pBVar3);
        (*(code *)PTR_BIO_free_006a6e70)(pBVar3);
        if (pBVar4 == (BIO *)0x0) {
          return iVar2;
        }
        pBVar3 = pBVar4;
      } while (dcont != pBVar4);
    }
  }
  return iVar2;
}

