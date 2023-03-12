
int CMS_decrypt_set1_pkey(CMS_ContentInfo *cms,EVP_PKEY *pk,X509 *cert)

{
  stack_st_CMS_RecipientInfo *psVar1;
  int iVar2;
  CMS_RecipientInfo *pCVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  psVar1 = CMS_get0_RecipientInfos(cms);
  if (psVar1 == (stack_st_CMS_RecipientInfo *)0x0) {
    iVar6 = 0;
    if (cert == (X509 *)0x0) goto LAB_005b7b3c;
    iVar4 = 0;
  }
  else {
    iVar6 = *(int *)(*(int *)(*(int *)(cms + 4) + 0xc) + 0x18);
    if (cert == (X509 *)0x0) {
      iVar4 = 0;
      if (iVar6 != 0) {
        for (; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(psVar1), iVar4 < iVar6; iVar4 = iVar4 + 1) {
          pCVar3 = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a6e24)(psVar1,iVar4);
          iVar6 = CMS_RecipientInfo_type(pCVar3);
          if (iVar6 == 0) {
            CMS_RecipientInfo_set0_pkey(pCVar3,pk);
            iVar6 = CMS_RecipientInfo_decrypt(cms,pCVar3);
            CMS_RecipientInfo_set0_pkey(pCVar3,(EVP_PKEY *)0x0);
            if (0 < iVar6) {
              return 1;
            }
          }
        }
        goto LAB_005b7ad8;
      }
      cert = (X509 *)0x0;
LAB_005b7b3c:
      iVar6 = 0;
      while (iVar4 = (*(code *)PTR_sk_num_006a6e2c)(psVar1), iVar6 < iVar4) {
        iVar2 = iVar6 + 1;
        pCVar3 = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a6e24)(psVar1,iVar6);
        iVar4 = CMS_RecipientInfo_type(pCVar3);
        iVar6 = iVar2;
        if (iVar4 == 0) {
          cert = (X509 *)0x1;
          CMS_RecipientInfo_set0_pkey(pCVar3,pk);
          CMS_RecipientInfo_decrypt(cms,pCVar3);
          CMS_RecipientInfo_set0_pkey(pCVar3,(EVP_PKEY *)0x0);
        }
      }
      if (cert == (X509 *)0x0) {
LAB_005b7ad8:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x72,0x84,"cms_smime.c",0x26d);
        return 0;
      }
      goto LAB_005b7c78;
    }
    iVar4 = 0;
  }
  do {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar1);
    if (iVar2 <= iVar4) goto LAB_005b7ad8;
    iVar5 = iVar4 + 1;
    pCVar3 = (CMS_RecipientInfo *)(*(code *)PTR_sk_value_006a6e24)(psVar1,iVar4);
    iVar2 = CMS_RecipientInfo_type(pCVar3);
    iVar4 = iVar5;
  } while ((iVar2 != 0) || (iVar2 = CMS_RecipientInfo_ktri_cert_cmp(pCVar3,cert), iVar2 != 0));
  CMS_RecipientInfo_set0_pkey(pCVar3,pk);
  iVar4 = CMS_RecipientInfo_decrypt(cms,pCVar3);
  CMS_RecipientInfo_set0_pkey(pCVar3,(EVP_PKEY *)0x0);
  if (iVar6 != 0) {
    if (iVar4 < 1) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x72,0x70,"cms_smime.c",0x25b);
      return 0;
    }
    return 1;
  }
LAB_005b7c78:
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  return 1;
}

