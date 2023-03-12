
int CMS_verify_receipt(CMS_ContentInfo *rcms,CMS_ContentInfo *ocms,stack_st_X509 *certs,
                      X509_STORE *store,uint flags)

{
  bool bVar1;
  undefined *puVar2;
  ASN1_OCTET_STRING **ppAVar3;
  stack_st_CMS_SignerInfo *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  CMS_SignerInfo *pCVar9;
  undefined4 uVar10;
  BIO *chain;
  stack_st_X509_CRL *psVar11;
  stack_st_X509 *psVar12;
  X509 *local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppAVar3 = CMS_get0_content(rcms);
  if ((ppAVar3 == (ASN1_OCTET_STRING **)0x0) || (*ppAVar3 == (ASN1_OCTET_STRING *)0x0)) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,99,0x7f,"cms_smime.c",0x7f);
    iVar5 = 0;
    goto LAB_005b97bc;
  }
  psVar4 = CMS_get0_SignerInfos(rcms);
  iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar4);
  if (iVar5 < 1) {
    uVar10 = 0x87;
    uVar8 = 0x150;
  }
  else {
    iVar5 = 0;
    iVar7 = 0;
    while (iVar6 = (*(code *)PTR_sk_num_006a7f2c)(psVar4), iVar7 < iVar6) {
      iVar6 = iVar7 + 1;
      pCVar9 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar4,iVar7);
      CMS_SignerInfo_get0_algs
                (pCVar9,(EVP_PKEY **)0x0,&local_30,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
      iVar7 = iVar6;
      if (local_30 != (X509 *)0x0) {
        iVar5 = iVar5 + 1;
      }
    }
    iVar7 = (*(code *)PTR_sk_num_006a7f2c)(psVar4);
    if (iVar5 != iVar7) {
      iVar7 = CMS_set1_signers_certs(rcms,certs,flags & 0xffffffbe);
      iVar7 = iVar5 + iVar7;
    }
    iVar5 = (*(code *)PTR_sk_num_006a7f2c)(psVar4);
    if (iVar5 == iVar7) {
      psVar11 = (stack_st_X509_CRL *)0x0;
      if ((flags & 0x20) == 0) {
        psVar12 = CMS_get1_certs(rcms);
        if ((flags & 0x2000) == 0) {
          psVar11 = CMS_get1_crls(rcms);
        }
        else {
          psVar11 = (stack_st_X509_CRL *)0x0;
        }
        for (iVar5 = 0; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(psVar4), iVar5 < iVar7;
            iVar5 = iVar5 + 1) {
          uVar8 = (*(code *)PTR_sk_value_006a7f24)(psVar4,iVar5);
          iVar7 = cms_signerinfo_verify_cert_isra_1(uVar8,store,psVar12,psVar11);
          if (iVar7 == 0) goto LAB_005b9924;
        }
      }
      else {
        psVar12 = (stack_st_X509 *)0x0;
      }
      if ((flags & 8) == 0) {
        for (iVar5 = 0; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(psVar4), iVar5 < iVar7;
            iVar5 = iVar5 + 1) {
          pCVar9 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar4,iVar5);
          iVar7 = (*(code *)PTR_CMS_signed_get_attr_count_006aa440)(pCVar9);
          if ((-1 < iVar7) && (iVar7 = CMS_SignerInfo_verify(pCVar9), iVar7 < 1)) goto LAB_005b9924;
        }
      }
      chain = CMS_dataInit(rcms,(BIO *)0x0);
      if ((chain == (BIO *)0x0) ||
         (iVar5 = cms_copy_content(0,chain,flags & 0xffffffbe), iVar5 == 0)) goto LAB_005b9928;
      if ((flags & 4) == 0) {
        for (iVar5 = 0; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(psVar4), iVar5 < iVar7;
            iVar5 = iVar5 + 1) {
          pCVar9 = (CMS_SignerInfo *)(*(code *)PTR_sk_value_006a7f24)(psVar4,iVar5);
          iVar7 = CMS_SignerInfo_verify_content(pCVar9,chain);
          if (iVar7 < 1) {
            bVar1 = false;
            (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9d,0x6d,"cms_smime.c",0x1a9);
            goto LAB_005b992c;
          }
        }
      }
      bVar1 = true;
      goto LAB_005b992c;
    }
    uVar10 = 0x8a;
    uVar8 = 0x161;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x9d,uVar10,"cms_smime.c",uVar8);
  (*(code *)PTR_BIO_free_all_006a7f74)(0);
  iVar5 = 0;
LAB_005b97bc:
  while (local_2c != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005b9a90:
    iVar5 = 0;
  }
  return iVar5;
LAB_005b9924:
  chain = (BIO *)0x0;
LAB_005b9928:
  bVar1 = false;
LAB_005b992c:
  (*(code *)PTR_BIO_free_all_006a7f74)(chain);
  if (psVar12 != (stack_st_X509 *)0x0) {
    (*(code *)PTR_sk_pop_free_006a8158)(psVar12,PTR_X509_free_006a7f90);
  }
  if (psVar11 != (stack_st_X509_CRL *)0x0) {
    (*(code *)PTR_sk_pop_free_006a8158)(psVar11,PTR_X509_CRL_free_006a8160);
  }
  if (!bVar1) goto LAB_005b9a90;
  iVar5 = cms_Receipt_verify(rcms,ocms);
  goto LAB_005b97bc;
}

