
int CMS_decrypt_set1_pkey(CMS_ContentInfo *cms,EVP_PKEY *pk,X509 *cert)

{
  stack_st_CMS_RecipientInfo *psVar1;
  int iVar2;
  CMS_RecipientInfo *pCVar3;
  int iVar4;
  int iVar5;
  
  psVar1 = CMS_get0_RecipientInfos(cms);
  if ((psVar1 == (stack_st_CMS_RecipientInfo *)0x0) ||
     (*(int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 0x18) == 0)) {
    iVar5 = 0;
    if (cert == (X509 *)0x0) {
      while (iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar1), iVar5 < iVar2) {
        iVar4 = iVar5 + 1;
        pCVar3 = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar1,iVar5);
        iVar2 = CMS_RecipientInfo_type(pCVar3);
        iVar5 = iVar4;
        if (iVar2 == 0) {
          CMS_RecipientInfo_set0_pkey(pCVar3,pk);
          CMS_RecipientInfo_decrypt(cms,pCVar3);
          CMS_RecipientInfo_set0_pkey(pCVar3,(EVP_PKEY *)0x0);
        }
      }
    }
    else {
      do {
        iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar1);
        if (iVar2 <= iVar5) goto LAB_005ba47c;
        iVar4 = iVar5 + 1;
        pCVar3 = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar1,iVar5);
        iVar2 = CMS_RecipientInfo_type(pCVar3);
        iVar5 = iVar4;
      } while ((iVar2 != 0) || (iVar2 = CMS_RecipientInfo_ktri_cert_cmp(pCVar3,cert), iVar2 != 0));
      CMS_RecipientInfo_set0_pkey(pCVar3,pk);
      CMS_RecipientInfo_decrypt(cms,pCVar3);
      CMS_RecipientInfo_set0_pkey(pCVar3,(EVP_PKEY *)0x0);
    }
    iVar5 = 1;
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
  }
  else {
    iVar2 = 0;
    if (cert == (X509 *)0x0) {
      for (iVar5 = 0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(psVar1), iVar5 < iVar2;
          iVar5 = iVar5 + 1) {
        pCVar3 = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar1,iVar5);
        iVar2 = CMS_RecipientInfo_type(pCVar3);
        if (iVar2 == 0) {
          CMS_RecipientInfo_set0_pkey(pCVar3,pk);
          iVar2 = CMS_RecipientInfo_decrypt(cms,pCVar3);
          CMS_RecipientInfo_set0_pkey(pCVar3,(EVP_PKEY *)0x0);
          if (0 < iVar2) {
            return 1;
          }
        }
      }
LAB_005ba47c:
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x72,0x84,"cms_smime.c",0x298);
      return 0;
    }
    do {
      iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar1);
      if (iVar5 <= iVar2) goto LAB_005ba47c;
      iVar4 = iVar2 + 1;
      pCVar3 = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar1,iVar2);
      iVar5 = CMS_RecipientInfo_type(pCVar3);
      iVar2 = iVar4;
    } while ((iVar5 != 0) || (iVar5 = CMS_RecipientInfo_ktri_cert_cmp(pCVar3,cert), iVar5 != 0));
    CMS_RecipientInfo_set0_pkey(pCVar3,pk);
    iVar2 = CMS_RecipientInfo_decrypt(cms,pCVar3);
    CMS_RecipientInfo_set0_pkey(pCVar3,(EVP_PKEY *)0x0);
    if (0 < iVar2) {
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x72,0x70,"cms_smime.c",0x285);
  }
  return iVar5;
}

