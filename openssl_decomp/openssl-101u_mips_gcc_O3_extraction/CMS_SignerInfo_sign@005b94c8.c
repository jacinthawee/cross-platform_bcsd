
int CMS_SignerInfo_sign(CMS_SignerInfo *si)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char *in_a1;
  undefined4 *puVar8;
  int *piVar9;
  undefined *unaff_s1;
  int iVar10;
  undefined4 *unaff_s3;
  char *unaff_s4;
  code *pcVar11;
  undefined auStack_14c [4];
  int iStack_148;
  undefined auStack_144 [24];
  undefined4 *puStack_12c;
  undefined *puStack_124;
  int iStack_120;
  CMS_SignerInfo *pCStack_11c;
  undefined4 uStack_118;
  code *pcStack_114;
  undefined4 uStack_100;
  undefined *puStack_f8;
  char *pcStack_f0;
  int *piStack_ec;
  undefined4 uStack_e8;
  undefined auStack_e4 [24];
  undefined auStack_cc [64];
  int iStack_8c;
  CMS_SignerInfo *pCStack_88;
  undefined *puStack_84;
  undefined *puStack_80;
  undefined4 *puStack_7c;
  char *pcStack_78;
  undefined4 local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined auStack_34 [24];
  undefined4 *local_1c;
  
  pCStack_11c = (CMS_SignerInfo *)PTR___stack_chk_guard_006a9ae8;
  local_3c = (undefined4 *)0x0;
  local_1c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(si + 8));
  uVar2 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar2);
  puVar3 = (undefined4 *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    iVar4 = 0;
  }
  else {
    unaff_s1 = auStack_34;
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(unaff_s1);
    iVar4 = (*(code *)PTR_CMS_signed_get_attr_by_NID_006a9388)(si,0x34,0xffffffff);
    if (iVar4 < 0) {
      unaff_s4 = (char *)(*(code *)PTR_X509_gmtime_adj_006a6f8c)(0,0);
      if ((unaff_s4 != (char *)0x0) &&
         (iVar4 = (*(code *)PTR_CMS_signed_add1_attr_by_NID_006a9390)
                            (si,0x34,*(undefined4 *)(unaff_s4 + 4),unaff_s4), 0 < iVar4)) {
        (*(code *)PTR_ASN1_TIME_free_006a7050)(unaff_s4);
        goto LAB_005b9574;
      }
      (*(code *)PTR_ASN1_TIME_free_006a7050)(unaff_s4);
      puVar8 = (undefined4 *)0x67;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x67,0x41,"cms_sd.c");
LAB_005b96f0:
      in_a1 = (char *)puVar8;
      if (local_3c != (undefined4 *)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
        in_a1 = (char *)puVar8;
      }
    }
    else {
LAB_005b9574:
      puVar8 = &local_40;
      iVar4 = (*(code *)PTR_EVP_DigestSignInit_006a6e20)(unaff_s1,puVar8,puVar3,0);
      if (iVar4 < 1) goto LAB_005b96f0;
      iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(local_40,0xffffffff,8,0xb);
      if (iVar4 < 1) {
        puVar8 = (undefined4 *)&DAT_00000097;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x97,0x6e,"cms_sd.c");
        goto LAB_005b96f0;
      }
      uVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)
                        (*(undefined4 *)(si + 0xc),&local_3c,PTR_CMS_Attributes_Sign_it_006a938c);
      in_a1 = (char *)local_3c;
      if (local_3c != (undefined4 *)0x0) {
        puVar8 = local_3c;
        iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s1,local_3c,uVar2);
        if (0 < iVar4) {
          puVar3 = &local_38;
          puVar8 = (undefined4 *)0x0;
          iVar4 = (*(code *)PTR_EVP_DigestSignFinal_006a74d0)(unaff_s1,0,puVar3);
          if (0 < iVar4) {
            unaff_s4 = "encrypt";
            (*(code *)PTR_CRYPTO_free_006a6e88)(local_3c);
            in_a1 = "cms_sd.c";
            puVar8 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(local_38,"cms_sd.c",0x2a4);
            local_3c = puVar8;
            if (puVar8 == (undefined4 *)0x0) goto LAB_005b9708;
            iVar4 = (*(code *)PTR_EVP_DigestSignFinal_006a74d0)(unaff_s1,puVar8,puVar3);
            if (0 < iVar4) {
              iVar4 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(local_40,0xffffffff,8,0xb);
              if (0 < iVar4) {
                (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(unaff_s1);
                in_a1 = (char *)local_3c;
                (*(code *)PTR_ASN1_STRING_set0_006a9144)
                          (*(undefined4 *)(si + 0x14),local_3c,local_38);
                iVar4 = 1;
                unaff_s3 = puVar3;
                goto LAB_005b971c;
              }
              puVar8 = (undefined4 *)&DAT_00000097;
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x97,0x6e,"cms_sd.c");
            }
          }
        }
        goto LAB_005b96f0;
      }
    }
LAB_005b9708:
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(unaff_s1);
    iVar4 = 0;
    unaff_s3 = puVar3;
  }
LAB_005b971c:
  if (local_1c == *(undefined4 **)pCStack_11c) {
    return iVar4;
  }
  puVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_f8 = &_gp;
  piStack_ec = (int *)PTR___stack_chk_guard_006a9ae8;
  puStack_80 = pCStack_11c;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pCStack_88 = si;
  puStack_84 = unaff_s1;
  puStack_7c = unaff_s3;
  pcStack_78 = unaff_s4;
  iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar3);
  if (iVar4 == 0x16) {
    uStack_118 = 0;
    if (puVar3[1] != 0) {
      uStack_118 = *(undefined4 *)(puVar3[1] + 0x14);
    }
  }
  else {
    uStack_100 = 0x47;
    uStack_118 = 0;
    (**(code **)(puStack_f8 + -0x6eac))(0x2e,0x85,0x6c,"cms_sd.c");
  }
  iStack_120 = 0;
  puStack_124 = auStack_e4;
  pcStack_f0 = "cms_sd.c";
  iVar4 = (**(code **)(puStack_f8 + -0x7fb4))(uStack_118);
  if (0 < iVar4) {
    do {
      pCStack_11c = (CMS_SignerInfo *)(**(code **)(puStack_f8 + -0x7fbc))(uStack_118,iStack_120);
      (**(code **)(puStack_f8 + -0x7fc4))(puStack_124);
      if (*(int *)(pCStack_11c + 0x20) == 0) {
        uStack_100 = 0x23c;
        (**(code **)(puStack_f8 + -0x6eac))(0x2e,0x96,0x85,"cms_sd.c");
        iVar4 = 0;
        goto LAB_005b9928;
      }
      iVar4 = cms_DigestAlgorithm_find_ctx(puStack_124,in_a1,*(undefined4 *)(pCStack_11c + 8));
      if (iVar4 == 0) {
LAB_005b9914:
        (**(code **)(puStack_f8 + -0x7fac))(puStack_124);
        iVar4 = 0;
        goto LAB_005b9928;
      }
      iVar4 = (**(code **)(puStack_f8 + -0x5aac))(pCStack_11c);
      if (-1 < iVar4) {
        uVar2 = **(undefined4 **)(puVar3[1] + 8);
        iVar4 = (**(code **)(puStack_f8 + -0x785c))(puStack_124,auStack_cc,&uStack_e8);
        if (iVar4 != 0) {
          uStack_100 = uStack_e8;
          iVar4 = (**(code **)(puStack_f8 + -0x5a50))(pCStack_11c,0x33,4,auStack_cc);
          if (iVar4 != 0) {
            uStack_100 = 0xffffffff;
            iVar4 = (**(code **)(puStack_f8 + -0x5a50))(pCStack_11c,0x32,6,uVar2);
            if ((0 < iVar4) && (iVar4 = CMS_SignerInfo_sign(pCStack_11c), iVar4 != 0)) {
              pcVar11 = *(code **)(puStack_f8 + -0x7fac);
              goto LAB_005b9aa8;
            }
          }
        }
        goto LAB_005b9914;
      }
      uVar2 = (**(code **)(puStack_f8 + -0x78e8))(*(undefined4 *)(pCStack_11c + 0x20));
      iVar4 = (**(code **)(puStack_f8 + -0x7dd8))(uVar2,pcStack_f0,0x25a);
      if (iVar4 == 0) {
        uStack_100 = 0x25c;
        (**(code **)(puStack_f8 + -0x6eac))(0x2e,0x96,0x41,pcStack_f0);
        goto LAB_005b9914;
      }
      iVar5 = (**(code **)(puStack_f8 + -0x6e70))
                        (puStack_124,iVar4,&uStack_e8,*(undefined4 *)(pCStack_11c + 0x20));
      if (iVar5 == 0) {
        uStack_100 = 0x260;
        (**(code **)(puStack_f8 + -0x6eac))(0x2e,0x96,0x8b,pcStack_f0);
        (**(code **)(puStack_f8 + -0x7f58))(iVar4);
        goto LAB_005b9914;
      }
      (**(code **)(puStack_f8 + -0x5c9c))(*(undefined4 *)(pCStack_11c + 0x14),iVar4,uStack_e8);
      pcVar11 = *(code **)(puStack_f8 + -0x7fac);
LAB_005b9aa8:
      iStack_120 = iStack_120 + 1;
      (*pcVar11)(puStack_124);
      iVar4 = (**(code **)(puStack_f8 + -0x7fb4))(uStack_118);
    } while (iStack_120 < iVar4);
  }
  iVar4 = 1;
  *(undefined4 *)(*(int *)(puVar3[1] + 8) + 8) = 0;
LAB_005b9928:
  if (iStack_8c == *piStack_ec) {
    return iVar4;
  }
  pcStack_114 = CMS_SignerInfo_verify;
  iVar4 = iStack_8c;
  (**(code **)(puStack_f8 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_148 = 0;
  puStack_12c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  if (*(int *)(iVar4 + 0x20) == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x98,0x86,"cms_sd.c",0x2c7);
    iVar4 = -1;
    goto LAB_005b9cec;
  }
  uVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(**(undefined4 **)(iVar4 + 8));
  uVar2 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar2);
  iVar5 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar2);
  if (iVar5 == 0) {
    iVar4 = -1;
    goto LAB_005b9cec;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_144);
  iVar5 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)
                    (auStack_144,auStack_14c,iVar5,0,*(undefined4 *)(iVar4 + 0x20));
  if ((iVar5 < 1) ||
     (uVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)
                        (*(undefined4 *)(iVar4 + 0xc),&iStack_148,
                         PTR_CMS_Attributes_Verify_it_006a9398), iStack_148 == 0)) {
LAB_005b9cd4:
    iVar4 = -1;
  }
  else {
    iVar5 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_144,iStack_148,uVar2);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iStack_148);
    if (iVar5 < 1) goto LAB_005b9cd4;
    iVar4 = (*(code *)PTR_EVP_DigestVerifyFinal_006a74cc)
                      (auStack_144,(*(undefined4 **)(iVar4 + 0x14))[2],
                       **(undefined4 **)(iVar4 + 0x14));
    if (iVar4 < 1) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x98,0x9e,"cms_sd.c",0x2df);
    }
  }
  (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_144);
LAB_005b9cec:
  if (puStack_12c == *(undefined4 **)puVar1) {
    return iVar4;
  }
  puVar3 = puStack_12c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar3);
  if (iVar4 == 0x16) {
    piVar9 = (int *)puVar3[1];
    if (piVar9 == (int *)0x0) {
      return 0;
    }
    iVar4 = 0;
    if (*(int *)(piVar9[2] + 8) != 0) {
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(piVar9[3]);
      if (0 < iVar5) {
        do {
          piVar7 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar9[3],iVar4);
          iVar5 = *piVar7;
          if (iVar5 == 4) {
            if (*piVar9 < 5) {
              *piVar9 = 5;
            }
          }
          else if (iVar5 == 3) {
            if (*piVar9 < 4) {
              *piVar9 = 4;
            }
          }
          else if ((iVar5 == 2) && (*piVar9 < 3)) {
            *piVar9 = 3;
          }
          iVar4 = iVar4 + 1;
          iVar5 = (*(code *)PTR_sk_num_006a6e2c)(piVar9[3]);
        } while (iVar4 < iVar5);
      }
      iVar4 = 0;
      while( true ) {
        iVar5 = (*(code *)PTR_sk_num_006a6e2c)(piVar9[4]);
        iVar6 = iVar4 + 1;
        if (iVar5 <= iVar4) break;
        piVar7 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar9[4]);
        iVar4 = iVar6;
        if ((*piVar7 == 1) && (*piVar9 < 5)) {
          *piVar9 = 5;
        }
      }
      iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)piVar9[2],iVar4);
      if ((iVar4 != 0x15) && (*piVar9 < 3)) {
        *piVar9 = 3;
      }
      iVar5 = 0;
      iVar4 = (*(code *)PTR_sk_num_006a6e2c)(piVar9[5]);
      if (0 < iVar4) {
        do {
          piVar7 = (int *)(*(code *)PTR_sk_value_006a6e24)(piVar9[5],iVar5);
          if (*(int *)piVar7[1] == 1) {
            if (*piVar7 < 3) {
              *piVar7 = 3;
            }
            if (*piVar9 < 3) {
              *piVar9 = 3;
            }
          }
          else if (*piVar7 < 1) {
            *piVar7 = 1;
          }
          iVar5 = iVar5 + 1;
          iVar4 = (*(code *)PTR_sk_num_006a6e2c)(piVar9[5]);
        } while (iVar5 < iVar4);
      }
      if (*piVar9 < 1) {
        *piVar9 = 1;
      }
    }
    iVar10 = 0;
    iVar4 = 0;
    iVar6 = (*(code *)PTR_sk_num_006a6e2c)(piVar9[1]);
    iVar5 = iVar4;
    if (0 < iVar6) {
      do {
        uVar2 = (*(code *)PTR_sk_value_006a6e24)(piVar9[1],iVar10);
        iVar4 = cms_DigestAlgorithm_init_bio(uVar2);
        if (iVar4 == 0) {
          if (iVar5 == 0) {
            return 0;
          }
          (*(code *)PTR_BIO_free_all_006a6e74)(iVar5,0);
          return 0;
        }
        if (iVar5 != 0) {
          (*(code *)PTR_BIO_push_006a74c4)(iVar5);
          iVar4 = iVar5;
        }
        iVar10 = iVar10 + 1;
        iVar6 = (*(code *)PTR_sk_num_006a6e2c)(piVar9[1]);
        iVar5 = iVar4;
      } while (iVar10 < iVar6);
    }
    return iVar4;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
  return 0;
}

