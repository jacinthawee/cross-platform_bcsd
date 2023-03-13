
int cms_DigestAlgorithm_init_bio(undefined4 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int unaff_s0;
  int *piVar9;
  int unaff_s2;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 *puStack_54;
  int iStack_50;
  undefined *puStack_4c;
  int iStack_48;
  undefined4 local_18;
  int local_14;
  
  puStack_4c = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_X509_ALGOR_get0_006a87a4)(&local_18,0,0,param_1);
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(local_18);
  uVar2 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar2);
  iStack_48 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar2);
  if (iStack_48 == 0) {
    uVar2 = 0x95;
  }
  else {
    uVar2 = (*(code *)PTR_BIO_f_md_006a74d8)();
    unaff_s0 = (*(code *)PTR_BIO_new_006a6ea4)(uVar2);
    if (unaff_s0 != 0) {
      uVar2 = 0;
      uVar8 = 0x6f;
      iVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(unaff_s0,0x6f,0,iStack_48);
      iVar6 = unaff_s0;
      if (iVar3 == 0) {
        uVar2 = 0x77;
        uVar8 = 0x74;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x74,0x77,"cms_lib.c");
        (*(code *)PTR_BIO_free_006a6e70)(unaff_s0);
        iVar6 = 0;
      }
      goto LAB_005b46f0;
    }
    uVar2 = 0x77;
    unaff_s2 = iStack_48;
  }
  uVar8 = 0x74;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x74,uVar2,"cms_lib.c");
  iVar6 = 0;
  iStack_48 = unaff_s2;
LAB_005b46f0:
  if (local_14 == *(int *)puStack_4c) {
    return iVar6;
  }
  iVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_54 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iStack_50 = unaff_s0;
  (*(code *)PTR_X509_ALGOR_get0_006a87a4)(&uStack_5c,0,0,uVar2);
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(uStack_5c);
  do {
    iVar5 = (*(code *)PTR_BIO_find_type_006a8320)(uVar8,0x208);
    if (iVar5 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x73,0x83,"cms_lib.c",0x188);
      iVar6 = 0;
LAB_005b48c0:
      if (puStack_54 == *(undefined4 **)puVar1) {
        return iVar6;
      }
      puVar7 = puStack_54;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      iVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar7);
      if (iVar6 == 0x16) {
        piVar9 = (int *)(puVar7[1] + 0xc);
      }
      else {
        if (iVar6 != 0x17) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x80,0x98,"cms_lib.c",0x1a4);
          return 0;
        }
        piVar9 = *(int **)(puVar7[1] + 4);
      }
      if (piVar9 == (int *)0x0) {
        return 0;
      }
      if (*piVar9 == 0) {
        iVar6 = (*(code *)PTR_sk_new_null_006a6fa4)();
        *piVar9 = iVar6;
        if (iVar6 == 0) {
          return 0;
        }
      }
      iVar6 = (*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_CertificateChoices_it_006a92ec);
      if (iVar6 == 0) {
        return 0;
      }
      iVar3 = (*(code *)PTR_sk_push_006a6fa8)(*piVar9,iVar6);
      if (iVar3 == 0) {
        (*(code *)PTR_ASN1_item_free_006a8658)(iVar6,PTR_CMS_CertificateChoices_it_006a92ec);
        return 0;
      }
      return iVar6;
    }
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar5,0x78,0,&uStack_58);
    uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(uStack_58);
    iVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(uVar2);
    if (iVar3 == iVar4) {
LAB_005b48ac:
      iVar6 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(iVar6,uStack_58);
      goto LAB_005b48c0;
    }
    uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(uStack_58);
    iVar4 = (*(code *)PTR_EVP_MD_pkey_type_006a9160)(uVar2);
    if (iVar3 == iVar4) goto LAB_005b48ac;
    uVar8 = (*(code *)PTR_BIO_next_006a9154)(iVar5);
  } while( true );
}

