
CMS_SignerInfo *
CMS_add1_signer(CMS_ContentInfo *cms,X509 *signer,EVP_PKEY *pk,EVP_MD *md,uint flags)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined4 *puVar11;
  code *pcVar12;
  stack_st_X509_ALGOR *local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = (*(code *)PTR_X509_check_private_key_006a707c)(signer,pk);
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x66,0x88,"cms_sd.c",0x11d);
    puVar4 = (undefined4 *)0x0;
    goto LAB_005baed0;
  }
  if (*(int *)(cms + 4) == 0) {
    puVar4 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_SignedData_it_006a9380);
    *(undefined4 **)(cms + 4) = puVar4;
    puVar1 = PTR_OBJ_nid2obj_006a7140;
    if (puVar4 != (undefined4 *)0x0) {
      puVar7 = (undefined4 *)puVar4[2];
      *puVar4 = 1;
      uVar9 = (*(code *)puVar1)(0x15);
      *puVar7 = uVar9;
      puVar1 = PTR_ASN1_OBJECT_free_006a7004;
      uVar9 = *(undefined4 *)cms;
      *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
      (*(code *)puVar1)(uVar9);
      uVar9 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x16);
      piVar10 = *(int **)(cms + 4);
      *(undefined4 *)cms = uVar9;
      goto LAB_005bac7c;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x95,0x41,"cms_sd.c",0x52);
  }
  else {
    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
    if (iVar3 == 0x16) {
      piVar10 = *(int **)(cms + 4);
LAB_005bac7c:
      if (piVar10 != (int *)0x0) {
        puVar4 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_SignerInfo_it_006a93a8)
        ;
        if (puVar4 == (undefined4 *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x66,0x41,"cms_sd.c",0x198);
        }
        else {
          (*(code *)PTR_X509_check_purpose_006a771c)(signer,0xffffffff,0xffffffff);
          (*(code *)PTR_CRYPTO_add_lock_006a805c)(&pk->references,1,10,"cms_sd.c",0x128);
          (*(code *)PTR_CRYPTO_add_lock_006a805c)(&signer->references,1,3,"cms_sd.c",0x129);
          puVar4[8] = pk;
          puVar4[7] = signer;
          if ((int)(flags << 0xf) < 0) {
            iVar3 = *piVar10;
            *puVar4 = 3;
            if (iVar3 < 3) {
              *piVar10 = 3;
              uVar9 = 1;
            }
            else {
              uVar9 = 1;
            }
          }
          else {
            uVar9 = 0;
            *puVar4 = 1;
          }
          iVar3 = cms_set1_SignerIdentifier(puVar4[1],signer,uVar9);
          if (iVar3 != 0) {
            if (md == (EVP_MD *)0x0) {
              iVar3 = (*(code *)PTR_EVP_PKEY_get_default_digest_nid_006a7098)(pk,&local_30);
              if (0 < iVar3) {
                uVar9 = (*(code *)PTR_OBJ_nid2sn_006a709c)(local_30);
                md = (EVP_MD *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar9);
                if (md != (EVP_MD *)0x0) goto LAB_005bad40;
                (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x66,0x80,"cms_sd.c",0x141);
              }
            }
            else {
LAB_005bad40:
              cms_DigestAlgorithm_set(puVar4[2],md);
              for (iVar3 = 0; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(piVar10[1]), iVar3 < iVar6;
                  iVar3 = iVar3 + 1) {
                uVar9 = (*(code *)PTR_sk_value_006a6e24)(piVar10[1],iVar3);
                (*(code *)PTR_X509_ALGOR_get0_006a87a4)(&local_30,0,0,uVar9);
                iVar6 = (*(code *)PTR_OBJ_obj2nid_006a712c)(local_30);
                iVar5 = (*(code *)PTR_EVP_MD_type_006a73cc)(md);
                if (iVar6 == iVar5) break;
              }
              iVar6 = (*(code *)PTR_sk_num_006a6e2c)(piVar10[1]);
              if (iVar3 == iVar6) {
                iVar3 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
                if (iVar3 != 0) {
                  cms_DigestAlgorithm_set(iVar3,md);
                  iVar6 = (*(code *)PTR_sk_push_006a6fa8)(piVar10[1],iVar3);
                  if (iVar6 != 0) goto LAB_005bade8;
                  (*(code *)PTR_X509_ALGOR_free_006a7ea4)(iVar3);
                }
              }
              else {
LAB_005bade8:
                if ((pk->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
                   (pcVar12 = *(code **)(pk->ameth + 0x58), pcVar12 != (code *)0x0)) {
                  iVar3 = (*pcVar12)(pk,5,0,puVar4);
                  if (iVar3 == -2) {
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x66,0x7d,"cms_sd.c",0x165);
                  }
                  else {
                    if (0 < iVar3) goto LAB_005bae24;
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x66,0x6f,"cms_sd.c",0x169);
                  }
                  goto LAB_005baeb8;
                }
LAB_005bae24:
                if ((flags & 0x100) == 0) {
                  if (puVar4[3] == 0) {
                    iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
                    puVar4[3] = iVar3;
                    if (iVar3 == 0) goto LAB_005bae94;
                  }
                  if ((flags & 0x200) == 0) {
                    local_34 = (stack_st_X509_ALGOR *)0x0;
                    iVar3 = CMS_add_standard_smimecap(&local_34);
                    if (iVar3 != 0) {
                      local_30 = 0;
                      iVar3 = (*(code *)PTR_i2d_X509_ALGORS_006a93a4)(local_34,&local_30);
                      if (0 < iVar3) {
                        iVar3 = (*(code *)PTR_CMS_signed_add1_attr_by_NID_006a9390)
                                          (puVar4,0xa7,0x10,local_30,iVar3);
                        (*(code *)PTR_CRYPTO_free_006a6e88)(local_30);
                        (*(code *)PTR_sk_pop_free_006a7058)(local_34,PTR_X509_ALGOR_free_006a7ea4);
                        if (iVar3 == 0) goto LAB_005bae94;
                        goto LAB_005bae50;
                      }
                    }
                    (*(code *)PTR_sk_pop_free_006a7058)(local_34,PTR_X509_ALGOR_free_006a7ea4);
                    goto LAB_005bae94;
                  }
LAB_005bae50:
                  if ((flags & 0x8000) != 0) {
                    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
                    if (iVar3 == 0x16) {
                      uVar9 = 0;
                      if (*(int *)(cms + 4) != 0) {
                        uVar9 = *(undefined4 *)(*(int *)(cms + 4) + 0x14);
                      }
                    }
                    else {
                      uVar9 = 0;
                      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
                    }
                    for (iVar3 = 0; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(uVar9), iVar3 < iVar6;
                        iVar3 = iVar3 + 1) {
                      puVar7 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(uVar9,iVar3);
                      if (((puVar4 != puVar7) &&
                          (iVar6 = (*(code *)PTR_CMS_signed_get_attr_count_006a9334)(puVar7),
                          -1 < iVar6)) &&
                         (iVar6 = (*(code *)PTR_OBJ_cmp_006a8cc4)
                                            (*(undefined4 *)puVar4[2],*(undefined4 *)puVar7[2]),
                         iVar6 == 0)) {
                        uVar9 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x33);
                        iVar3 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006a93a0)
                                          (puVar7,uVar9,0xfffffffd,4);
                        if (iVar3 == 0) {
                          (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x6c,0x72,"cms_sd.c",0xb5);
                          goto LAB_005baeb8;
                        }
                        iVar3 = (*(code *)PTR_CMS_signed_add1_attr_by_NID_006a9390)
                                          (puVar4,0x33,4,iVar3,0xffffffff);
                        if ((iVar3 == 0) ||
                           (((flags & 0x4000) == 0 &&
                            (iVar3 = CMS_SignerInfo_sign((CMS_SignerInfo *)puVar4), iVar3 == 0))))
                        goto LAB_005baeb8;
                        goto LAB_005bae64;
                      }
                    }
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x6c,0x83,"cms_sd.c",0xc0);
                    goto LAB_005baeb8;
                  }
                }
LAB_005bae64:
                if ((flags & 2) == 0) {
                  iVar3 = CMS_add1_cert(cms,signer);
                  if (iVar3 == 0) goto LAB_005bae94;
                  iVar3 = piVar10[5];
                }
                else {
                  iVar3 = piVar10[5];
                }
                if (iVar3 == 0) {
                  iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
                  piVar10[5] = iVar3;
                  if (iVar3 == 0) goto LAB_005bae94;
                }
                iVar3 = (*(code *)PTR_sk_push_006a6fa8)(iVar3,puVar4);
                if (iVar3 != 0) goto LAB_005baed0;
              }
LAB_005bae94:
              (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x66,0x41,"cms_sd.c",0x198);
            }
          }
LAB_005baeb8:
          (*(code *)PTR_ASN1_item_free_006a8658)(puVar4,PTR_CMS_SignerInfo_it_006a93a8);
        }
      }
    }
    else {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
    }
  }
  puVar4 = (undefined4 *)0x0;
LAB_005baed0:
  if (local_2c == *(int *)puVar2) {
    return (CMS_SignerInfo *)puVar4;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar4 = (undefined4 *)CMS_ContentInfo_new();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar7 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_DigestedData_it_006a93b0);
    if (puVar7 == (undefined4 *)0x0) {
      CMS_ContentInfo_free((CMS_ContentInfo *)puVar4);
      return (CMS_SignerInfo *)0x0;
    }
    uVar9 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x19);
    puVar4[1] = puVar7;
    *puVar4 = uVar9;
    *puVar7 = 0;
    puVar11 = (undefined4 *)puVar7[2];
    uVar9 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
    uVar8 = puVar7[1];
    *puVar11 = uVar9;
    cms_DigestAlgorithm_set(uVar8,iVar3);
  }
  return (CMS_SignerInfo *)puVar4;
}

