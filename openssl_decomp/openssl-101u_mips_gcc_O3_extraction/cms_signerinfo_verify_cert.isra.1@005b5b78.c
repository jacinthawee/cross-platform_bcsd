
undefined4
cms_signerinfo_verify_cert_isra_1
          (CMS_SignerInfo *param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  ASN1_OBJECT *pAVar4;
  BIO *pBVar5;
  CMS_ContentInfo *cms;
  char *pcVar6;
  undefined4 uVar7;
  X509 *local_a8;
  undefined auStack_a4 [136];
  CMS_ContentInfo *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(CMS_ContentInfo **)PTR___stack_chk_guard_006a9ae8;
  CMS_SignerInfo_get0_algs(param_1,(EVP_PKEY **)0x0,&local_a8,(X509_ALGOR **)0x0,(X509_ALGOR **)0x0)
  ;
  iVar2 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)(auStack_a4,param_2,local_a8,param_3);
  if (iVar2 == 0) {
    local_a8 = (X509 *)0x8d;
    pcVar6 = (char *)0x99;
    uVar7 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x99,0x8d,"cms_smime.c",0x113);
  }
  else {
    pcVar6 = "smime_sign";
    (*(code *)PTR_X509_STORE_CTX_set_default_006a8378)(auStack_a4,"smime_sign");
    if (param_4 != (char *)0x0) {
      (*(code *)PTR_X509_STORE_CTX_set0_crls_006a7468)(auStack_a4,param_4);
      pcVar6 = param_4;
    }
    iVar2 = (*(code *)PTR_X509_verify_cert_006a728c)(auStack_a4);
    if (iVar2 < 1) {
      uVar3 = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(auStack_a4);
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x99,100,"cms_smime.c",0x11e);
      uVar7 = 0;
      local_a8 = (X509 *)(*(code *)PTR_X509_verify_cert_error_string_006a72a0)(uVar3);
      pcVar6 = "Verify error:";
      (*(code *)PTR_ERR_add_error_data_006a813c)(2,"Verify error:",local_a8);
    }
    else {
      uVar7 = 1;
    }
  }
  (*(code *)PTR_X509_STORE_CTX_cleanup_006a7294)(auStack_a4);
  if (local_1c != *(CMS_ContentInfo **)puVar1) {
    cms = local_1c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    pAVar4 = CMS_get0_type(cms);
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pAVar4);
    if (iVar2 == 0x15) {
      pBVar5 = CMS_dataInit(cms,(BIO *)0x0);
      if (pBVar5 != (BIO *)0x0) {
        uVar7 = cms_copy_content(pcVar6,pBVar5,local_a8);
        (*(code *)PTR_BIO_free_all_006a6e74)(pBVar5);
        return uVar7;
      }
    }
    else {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x6d,0x8f,"cms_smime.c",0x90);
    }
    return 0;
  }
  return uVar7;
}

