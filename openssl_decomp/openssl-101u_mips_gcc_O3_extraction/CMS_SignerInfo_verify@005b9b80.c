
int CMS_SignerInfo_verify(CMS_SignerInfo *si)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  undefined auStack_3c [4];
  int local_38;
  undefined auStack_34 [24];
  undefined4 *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_38 = 0;
  local_1c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  if (*(int *)(si + 0x20) == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x98,0x86,"cms_sd.c",0x2c7);
    iVar3 = -1;
    goto LAB_005b9cec;
  }
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(si + 8));
  uVar2 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar2);
  iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar2);
  if (iVar3 == 0) {
    iVar3 = -1;
    goto LAB_005b9cec;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_34);
  iVar3 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)
                    (auStack_34,auStack_3c,iVar3,0,*(undefined4 *)(si + 0x20));
  if ((iVar3 < 1) ||
     (uVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)
                        (*(undefined4 *)(si + 0xc),&local_38,PTR_CMS_Attributes_Verify_it_006a9398),
     local_38 == 0)) {
LAB_005b9cd4:
    iVar3 = -1;
  }
  else {
    iVar3 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_34,local_38,uVar2);
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_38);
    if (iVar3 < 1) goto LAB_005b9cd4;
    iVar3 = (*(code *)PTR_EVP_DigestVerifyFinal_006a74cc)
                      (auStack_34,(*(undefined4 **)(si + 0x14))[2],**(undefined4 **)(si + 0x14));
    if (iVar3 < 1) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x98,0x9e,"cms_sd.c",0x2df);
    }
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_34);
LAB_005b9cec:
  if (local_1c == *(undefined4 **)puVar1) {
    return iVar3;
  }
  puVar7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar7);
  if (iVar3 == 0x16) {
    piVar8 = (int *)puVar7[1];
    if (piVar8 == (int *)0x0) {
      return 0;
    }
    iVar3 = 0;
    if (*(int *)(piVar8[2] + 8) != 0) {
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[3]);
      if (0 < iVar5) {
        do {
          piVar6 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar8[3],iVar3);
          iVar5 = *piVar6;
          if (iVar5 == 4) {
            if (*piVar8 < 5) {
              *piVar8 = 5;
            }
          }
          else if (iVar5 == 3) {
            if (*piVar8 < 4) {
              *piVar8 = 4;
            }
          }
          else if ((iVar5 == 2) && (*piVar8 < 3)) {
            *piVar8 = 3;
          }
          iVar3 = iVar3 + 1;
          iVar5 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[3]);
        } while (iVar3 < iVar5);
      }
      iVar3 = 0;
      while( true ) {
        iVar5 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[4]);
        iVar4 = iVar3 + 1;
        if (iVar5 <= iVar3) break;
        piVar6 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar8[4]);
        iVar3 = iVar4;
        if ((*piVar6 == 1) && (*piVar8 < 5)) {
          *piVar8 = 5;
        }
      }
      iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)piVar8[2],iVar3);
      if ((iVar3 != 0x15) && (*piVar8 < 3)) {
        *piVar8 = 3;
      }
      iVar5 = 0;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[5]);
      if (0 < iVar3) {
        do {
          piVar6 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar8[5],iVar5);
          if (*(int *)piVar6[1] == 1) {
            if (*piVar6 < 3) {
              *piVar6 = 3;
            }
            if (*piVar8 < 3) {
              *piVar8 = 3;
            }
          }
          else if (*piVar6 < 1) {
            *piVar6 = 1;
          }
          iVar5 = iVar5 + 1;
          iVar3 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[5]);
        } while (iVar5 < iVar3);
      }
      if (*piVar8 < 1) {
        *piVar8 = 1;
      }
    }
    iVar9 = 0;
    iVar3 = 0;
    iVar4 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[1]);
    iVar5 = iVar3;
    if (0 < iVar4) {
      do {
        uVar2 = (*(code *)PTR_sk_value_006a6e24)(piVar8[1],iVar9);
        iVar3 = cms_DigestAlgorithm_init_bio(uVar2);
        if (iVar3 == 0) {
          if (iVar5 == 0) {
            return 0;
          }
          (*(code *)PTR_BIO_free_all_006a6e74)(iVar5,0);
          return 0;
        }
        if (iVar5 != 0) {
          (*(code *)PTR_BIO_push_006a74c4)(iVar5);
          iVar3 = iVar5;
        }
        iVar9 = iVar9 + 1;
        iVar4 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[1]);
        iVar5 = iVar3;
      } while (iVar9 < iVar4);
    }
    return iVar3;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
  return 0;
}

