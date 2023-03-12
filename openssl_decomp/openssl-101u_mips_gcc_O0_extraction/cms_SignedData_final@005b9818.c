
int cms_SignedData_final(undefined4 *param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  CMS_SignerInfo *unaff_s2;
  code *pcVar10;
  undefined auStack_ec [4];
  int iStack_e8;
  undefined auStack_e4 [24];
  undefined4 *puStack_cc;
  undefined *puStack_c4;
  int iStack_c0;
  CMS_SignerInfo *pCStack_bc;
  undefined4 uStack_b8;
  code *pcStack_b4;
  undefined4 local_a0;
  undefined *local_98;
  char *local_90;
  int *local_8c;
  undefined4 local_88;
  undefined auStack_84 [24];
  undefined auStack_6c [64];
  int local_2c;
  
  local_98 = &_gp;
  local_8c = (int *)PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*param_1);
  if (iVar2 == 0x16) {
    uStack_b8 = 0;
    if (param_1[1] != 0) {
      uStack_b8 = *(undefined4 *)(param_1[1] + 0x14);
    }
  }
  else {
    local_a0 = 0x47;
    uStack_b8 = 0;
    (**(code **)(local_98 + -0x6eac))(0x2e,0x85,0x6c,"cms_sd.c");
  }
  iStack_c0 = 0;
  puStack_c4 = auStack_84;
  local_90 = "cms_sd.c";
  iVar2 = (**(code **)(local_98 + -0x7fb4))(uStack_b8);
  if (0 < iVar2) {
    do {
      unaff_s2 = (CMS_SignerInfo *)(**(code **)(local_98 + -0x7fbc))(uStack_b8,iStack_c0);
      (**(code **)(local_98 + -0x7fc4))(puStack_c4);
      if (*(int *)(unaff_s2 + 0x20) == 0) {
        local_a0 = 0x23c;
        (**(code **)(local_98 + -0x6eac))(0x2e,0x96,0x85,"cms_sd.c");
        iVar2 = 0;
        goto LAB_005b9928;
      }
      iVar2 = cms_DigestAlgorithm_find_ctx(puStack_c4,param_2,*(undefined4 *)(unaff_s2 + 8));
      if (iVar2 == 0) {
LAB_005b9914:
        (**(code **)(local_98 + -0x7fac))(puStack_c4);
        iVar2 = 0;
        goto LAB_005b9928;
      }
      iVar2 = (**(code **)(local_98 + -0x5aac))(unaff_s2);
      if (-1 < iVar2) {
        uVar3 = **(undefined4 **)(param_1[1] + 8);
        iVar2 = (**(code **)(local_98 + -0x785c))(puStack_c4,auStack_6c,&local_88);
        if (iVar2 != 0) {
          local_a0 = local_88;
          iVar2 = (**(code **)(local_98 + -0x5a50))(unaff_s2,0x33,4,auStack_6c);
          if (iVar2 != 0) {
            local_a0 = 0xffffffff;
            iVar2 = (**(code **)(local_98 + -0x5a50))(unaff_s2,0x32,6,uVar3);
            if ((0 < iVar2) && (iVar2 = CMS_SignerInfo_sign(unaff_s2), iVar2 != 0)) {
              pcVar10 = *(code **)(local_98 + -0x7fac);
              goto LAB_005b9aa8;
            }
          }
        }
        goto LAB_005b9914;
      }
      uVar3 = (**(code **)(local_98 + -0x78e8))(*(undefined4 *)(unaff_s2 + 0x20));
      iVar2 = (**(code **)(local_98 + -0x7dd8))(uVar3,local_90,0x25a);
      if (iVar2 == 0) {
        local_a0 = 0x25c;
        (**(code **)(local_98 + -0x6eac))(0x2e,0x96,0x41,local_90);
        goto LAB_005b9914;
      }
      iVar4 = (**(code **)(local_98 + -0x6e70))
                        (puStack_c4,iVar2,&local_88,*(undefined4 *)(unaff_s2 + 0x20));
      if (iVar4 == 0) {
        local_a0 = 0x260;
        (**(code **)(local_98 + -0x6eac))(0x2e,0x96,0x8b,local_90);
        (**(code **)(local_98 + -0x7f58))(iVar2);
        goto LAB_005b9914;
      }
      (**(code **)(local_98 + -0x5c9c))(*(undefined4 *)(unaff_s2 + 0x14),iVar2,local_88);
      pcVar10 = *(code **)(local_98 + -0x7fac);
LAB_005b9aa8:
      iStack_c0 = iStack_c0 + 1;
      (*pcVar10)(puStack_c4);
      iVar2 = (**(code **)(local_98 + -0x7fb4))(uStack_b8);
    } while (iStack_c0 < iVar2);
  }
  iVar2 = 1;
  *(undefined4 *)(*(int *)(param_1[1] + 8) + 8) = 0;
LAB_005b9928:
  if (local_2c == *local_8c) {
    return iVar2;
  }
  pcStack_b4 = CMS_SignerInfo_verify;
  iVar2 = local_2c;
  (**(code **)(local_98 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_e8 = 0;
  puStack_cc = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  pCStack_bc = unaff_s2;
  if (*(int *)(iVar2 + 0x20) == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x98,0x86,"cms_sd.c",0x2c7);
    iVar2 = -1;
    goto LAB_005b9cec;
  }
  uVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(iVar2 + 8));
  uVar3 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar3);
  iVar4 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar3);
  if (iVar4 == 0) {
    iVar2 = -1;
    goto LAB_005b9cec;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_e4);
  iVar4 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)
                    (auStack_e4,auStack_ec,iVar4,0,*(undefined4 *)(iVar2 + 0x20));
  if ((iVar4 < 1) ||
     (uVar3 = (*(code *)PTR_ASN1_item_i2d_006a8678)
                        (*(undefined4 *)(iVar2 + 0xc),&iStack_e8,
                         PTR_CMS_Attributes_Verify_it_006a9398), iStack_e8 == 0)) {
LAB_005b9cd4:
    iVar2 = -1;
  }
  else {
    iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_e4,iStack_e8,uVar3);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iStack_e8);
    if (iVar4 < 1) goto LAB_005b9cd4;
    iVar2 = (*(code *)PTR_EVP_DigestVerifyFinal_006a74cc)
                      (auStack_e4,(*(undefined4 **)(iVar2 + 0x14))[2],
                       **(undefined4 **)(iVar2 + 0x14));
    if (iVar2 < 1) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x98,0x9e,"cms_sd.c",0x2df);
    }
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_e4);
LAB_005b9cec:
  if (puStack_cc == *(undefined4 **)puVar1) {
    return iVar2;
  }
  puVar7 = puStack_cc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar7);
  if (iVar2 == 0x16) {
    piVar8 = (int *)puVar7[1];
    if (piVar8 == (int *)0x0) {
      return 0;
    }
    iVar2 = 0;
    if (*(int *)(piVar8[2] + 8) != 0) {
      iVar4 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[3]);
      if (0 < iVar4) {
        do {
          piVar6 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar8[3],iVar2);
          iVar4 = *piVar6;
          if (iVar4 == 4) {
            if (*piVar8 < 5) {
              *piVar8 = 5;
            }
          }
          else if (iVar4 == 3) {
            if (*piVar8 < 4) {
              *piVar8 = 4;
            }
          }
          else if ((iVar4 == 2) && (*piVar8 < 3)) {
            *piVar8 = 3;
          }
          iVar2 = iVar2 + 1;
          iVar4 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[3]);
        } while (iVar2 < iVar4);
      }
      iVar2 = 0;
      while( true ) {
        iVar4 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[4]);
        iVar5 = iVar2 + 1;
        if (iVar4 <= iVar2) break;
        piVar6 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar8[4]);
        iVar2 = iVar5;
        if ((*piVar6 == 1) && (*piVar8 < 5)) {
          *piVar8 = 5;
        }
      }
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)piVar8[2],iVar2);
      if ((iVar2 != 0x15) && (*piVar8 < 3)) {
        *piVar8 = 3;
      }
      iVar4 = 0;
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[5]);
      if (0 < iVar2) {
        do {
          piVar6 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar8[5],iVar4);
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
          iVar4 = iVar4 + 1;
          iVar2 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[5]);
        } while (iVar4 < iVar2);
      }
      if (*piVar8 < 1) {
        *piVar8 = 1;
      }
    }
    iVar9 = 0;
    iVar2 = 0;
    iVar5 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[1]);
    iVar4 = iVar2;
    if (0 < iVar5) {
      do {
        uVar3 = (*(code *)PTR_sk_value_006a6e24)(piVar8[1],iVar9);
        iVar2 = cms_DigestAlgorithm_init_bio(uVar3);
        if (iVar2 == 0) {
          if (iVar4 == 0) {
            return 0;
          }
          (*(code *)PTR_BIO_free_all_006a6e74)(iVar4,0);
          return 0;
        }
        if (iVar4 != 0) {
          (*(code *)PTR_BIO_push_006a74c4)(iVar4);
          iVar2 = iVar4;
        }
        iVar9 = iVar9 + 1;
        iVar5 = (*(code *)PTR_sk_num_006a6e2c)(piVar8[1]);
        iVar4 = iVar2;
      } while (iVar9 < iVar5);
    }
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
  return 0;
}

