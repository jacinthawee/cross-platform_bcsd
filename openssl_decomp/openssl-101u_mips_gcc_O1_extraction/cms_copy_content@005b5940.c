
undefined4 cms_copy_content(undefined *param_1,undefined4 param_2,uint param_3,char *param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  ASN1_OBJECT *pAVar5;
  BIO *pBVar6;
  CMS_SignerInfo *si;
  CMS_ContentInfo *cms;
  undefined *puVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  X509 *pXStack_10f0;
  undefined auStack_10ec [136];
  CMS_ContentInfo *pCStack_1064;
  undefined4 uStack_1060;
  undefined *puStack_105c;
  undefined4 uStack_1058;
  undefined *puStack_1054;
  uint uStack_1050;
  code *pcStack_104c;
  undefined4 local_1038;
  undefined *local_1030;
  undefined auStack_1024 [4096];
  CMS_SignerInfo *local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1030 = &_gp;
  local_24 = *(CMS_SignerInfo **)PTR___stack_chk_guard_006a9ae8;
  if (param_1 == (undefined *)0x0) {
    uVar10 = (*(code *)PTR_BIO_s_null_006a7908)();
    puStack_105c = (undefined *)(**(code **)(local_1030 + -0x7f3c))(uVar10);
joined_r0x005b5b5c:
    if (puStack_105c == (undefined *)0x0) {
      iVar9 = 0x41;
      param_4 = "cms_smime.c";
      local_1038 = 0x4e;
      puVar7 = &DAT_0000006b;
      uStack_1060 = 0;
      (**(code **)(local_1030 + -0x6eac))(0x2e,0x6b,0x41);
      goto LAB_005b59f0;
    }
  }
  else {
    puStack_105c = param_1;
    if ((param_3 & 1) != 0) {
      uVar10 = (*(code *)PTR_BIO_s_mem_006a7c18)();
      puStack_105c = (undefined *)(**(code **)(local_1030 + -0x7f3c))(uVar10);
      param_4 = (char *)0x0;
      (**(code **)(local_1030 + -0x7fc8))(puStack_105c,0x82,0);
      goto joined_r0x005b5b5c;
    }
  }
  do {
    iVar9 = 0x1000;
    puVar7 = auStack_1024;
    iVar2 = (**(code **)(local_1030 + -0x7920))(param_2,auStack_1024,0x1000);
    if (iVar2 < 1) {
      iVar3 = (**(code **)(local_1030 + -0x6ab8))(param_2);
      if (iVar3 == 0x20a) {
        param_4 = (char *)0x0;
        iVar9 = 0;
        puVar7 = (undefined *)0x71;
        iVar3 = (**(code **)(local_1030 + -0x7fc8))(param_2,0x71,0);
        if (iVar3 == 0) {
          uStack_1060 = 0;
          goto LAB_005b59dc;
        }
      }
      if (iVar2 == 0) {
        param_3 = param_3 & 1;
        if ((param_3 == 0) ||
           (puVar7 = param_1, iVar2 = (**(code **)(local_1030 + -0x5c48))(puStack_105c,param_1),
           iVar2 != 0)) {
          uStack_1060 = 1;
        }
        else {
          iVar9 = 0x8c;
          param_4 = "cms_smime.c";
          local_1038 = 0x65;
          puVar7 = &DAT_0000006b;
          uStack_1060 = 0;
          (**(code **)(local_1030 + -0x6eac))(0x2e,0x6b,0x8c);
        }
        goto LAB_005b59dc;
      }
      break;
    }
    puVar7 = auStack_1024;
    iVar9 = iVar2;
    iVar3 = (**(code **)(local_1030 + -0x7fcc))(puStack_105c,auStack_1024,iVar2);
  } while (iVar2 == iVar3);
  uStack_1060 = 0;
LAB_005b59dc:
  if (param_1 != puStack_105c) {
    (**(code **)(local_1030 + -0x7f70))(puStack_105c);
  }
LAB_005b59f0:
  if (local_24 == *(CMS_SignerInfo **)puVar1) {
    return uStack_1060;
  }
  pcStack_104c = cms_signerinfo_verify_cert_isra_1;
  si = local_24;
  (**(code **)(local_1030 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pCStack_1064 = *(CMS_ContentInfo **)PTR___stack_chk_guard_006a9ae8;
  uStack_1058 = param_2;
  puStack_1054 = param_1;
  uStack_1050 = param_3;
  CMS_SignerInfo_get0_algs(si,(EVP_PKEY **)0x0,&pXStack_10f0,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0);
  iVar9 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(auStack_10ec,puVar7,pXStack_10f0,iVar9);
  if (iVar9 == 0) {
    pXStack_10f0 = (X509 *)0x8d;
    pcVar8 = (char *)0x99;
    uVar10 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x99,0x8d,"cms_smime.c",0x113);
  }
  else {
    pcVar8 = "smime_sign";
    (*(code *)PTR_X509_STORE_CTX_set_default_006a8378)(auStack_10ec,"smime_sign");
    if (param_4 != (char *)0x0) {
      (*(code *)PTR_X509_STORE_CTX_set0_crls_006a7468)(auStack_10ec,param_4);
      pcVar8 = param_4;
    }
    iVar9 = (*(code *)PTR_X509_verify_cert_006a728c)(auStack_10ec);
    if (iVar9 < 1) {
      uVar4 = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(auStack_10ec);
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x99,100,"cms_smime.c",0x11e);
      uVar10 = 0;
      pXStack_10f0 = (X509 *)(*(code *)PTR_X509_verify_cert_error_string_006a72a0)(uVar4);
      pcVar8 = "Verify error:";
      (*(code *)PTR_ERR_add_error_data_006a813c)(2,"Verify error:",pXStack_10f0);
    }
    else {
      uVar10 = 1;
    }
  }
  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_10ec);
  if (pCStack_1064 == *(CMS_ContentInfo **)puVar1) {
    return uVar10;
  }
  cms = pCStack_1064;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pAVar5 = CMS_get0_type(cms);
  iVar9 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar5);
  if (iVar9 == 0x15) {
    pBVar6 = CMS_dataInit(cms,(BIO *)0x0);
    if (pBVar6 != (BIO *)0x0) {
      uVar10 = cms_copy_content(pcVar8,pBVar6,pXStack_10f0);
      (*(code *)PTR_BIO_free_all_006a6e74)(pBVar6);
      return uVar10;
    }
  }
  else {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x6d,0x8f,"cms_smime.c",0x90);
  }
  return 0;
}

