
int CMS_decrypt(CMS_ContentInfo *cms,EVP_PKEY *pkey,X509 *cert,BIO *dcont,BIO *out,uint flags)

{
  ASN1_OBJECT *pAVar1;
  int iVar2;
  BIO *pBVar3;
  BIO *pBVar4;
  ASN1_OCTET_STRING **ppAVar5;
  
  pAVar1 = CMS_get0_type(cms);
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar1);
  if (iVar2 != 0x17) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x70,0x92,"cms_smime.c",0x2b3);
    return 0;
  }
  if ((dcont == (BIO *)0x0) &&
     ((ppAVar5 = CMS_get0_content(cms), ppAVar5 == (ASN1_OCTET_STRING **)0x0 ||
      (*ppAVar5 == (ASN1_OCTET_STRING *)0x0)))) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,99,0x7f,"cms_smime.c",0x77);
    return 0;
  }
  if ((int)(flags << 0xe) < 0) {
    *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 0xc) + 0x18) = 1;
  }
  else {
    *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 0xc) + 0x18) = 0;
  }
  if (pkey == (EVP_PKEY *)0x0) {
    if (cert == (X509 *)0x0) {
      if (dcont != (BIO *)0x0) {
        pBVar3 = CMS_dataInit(cms,dcont);
        if (pBVar3 == (BIO *)0x0) {
          return 0;
        }
        iVar2 = cms_copy_content(out,pBVar3,flags);
        goto LAB_005b81ac;
      }
      if (out == (BIO *)0x0) {
        return 1;
      }
      pBVar3 = CMS_dataInit(cms,(BIO *)0x0);
      if (pBVar3 == (BIO *)0x0) {
        return 0;
      }
      iVar2 = cms_copy_content(out,pBVar3,flags);
      goto LAB_005b832c;
    }
  }
  else {
    iVar2 = CMS_decrypt_set1_pkey(cms,pkey,cert);
    if (iVar2 == 0) {
      return 0;
    }
  }
  pBVar3 = CMS_dataInit(cms,dcont);
  if (pBVar3 == (BIO *)0x0) {
    return 0;
  }
  iVar2 = cms_copy_content(out,pBVar3,flags);
  if (dcont != (BIO *)0x0) {
LAB_005b81ac:
    do {
      pBVar4 = (BIO *)(*(code *)PTR_BIO_pop_006a79c8)(pBVar3);
      (*(code *)PTR_BIO_free_006a6e70)(pBVar3);
      if (pBVar4 == (BIO *)0x0) {
        return iVar2;
      }
      pBVar3 = pBVar4;
    } while (dcont != pBVar4);
    return iVar2;
  }
LAB_005b832c:
  (*(code *)PTR_BIO_free_all_006a6e74)(pBVar3);
  return iVar2;
}

