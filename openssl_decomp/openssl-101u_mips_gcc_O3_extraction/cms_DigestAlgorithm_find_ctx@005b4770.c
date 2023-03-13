
int cms_DigestAlgorithm_find_ctx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_X509_ALGOR_get0_006a87a4)(&local_24,0,0,param_3);
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(local_24);
  do {
    iVar5 = (*(code *)PTR_BIO_find_type_006a8320)(param_2,0x208);
    if (iVar5 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x73,0x83,"cms_lib.c",0x188);
      iVar2 = 0;
LAB_005b48c0:
      if (local_1c == *(undefined4 **)puVar1) {
        return iVar2;
      }
      puVar6 = local_1c;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar6);
      if (iVar2 == 0x16) {
        piVar7 = (int *)(puVar6[1] + 0xc);
      }
      else {
        if (iVar2 != 0x17) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x80,0x98,"cms_lib.c",0x1a4);
          return 0;
        }
        piVar7 = *(int **)(puVar6[1] + 4);
      }
      if (piVar7 == (int *)0x0) {
        return 0;
      }
      if (*piVar7 == 0) {
        iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
        *piVar7 = iVar2;
        if (iVar2 == 0) {
          return 0;
        }
      }
      iVar2 = (*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_CertificateChoices_it_006a92ec);
      if (iVar2 == 0) {
        return 0;
      }
      iVar5 = (*(code *)PTR_sk_push_006a6fa8)(*piVar7,iVar2);
      if (iVar5 == 0) {
        (*(code *)PTR_ASN1_item_free_006a8658)(iVar2,PTR_CMS_CertificateChoices_it_006a92ec);
        return 0;
      }
      return iVar2;
    }
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar5,0x78,0,&local_20);
    uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(local_20);
    iVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar3);
    if (iVar2 == iVar4) {
LAB_005b48ac:
      iVar2 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(param_1,local_20);
      goto LAB_005b48c0;
    }
    uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(local_20);
    iVar4 = (*(code *)PTR_EVP_MD_pkey_type_006a9160)(uVar3);
    if (iVar2 == iVar4) goto LAB_005b48ac;
    param_2 = (*(code *)PTR_BIO_next_006a9154)(iVar5);
  } while( true );
}

