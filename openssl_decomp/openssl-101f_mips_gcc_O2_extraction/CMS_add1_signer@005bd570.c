
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
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = (*(code *)PTR_X509_check_private_key_006a817c)(signer,pk);
  if (iVar3 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x66,0x88,"cms_sd.c",0x137);
    puVar4 = (undefined4 *)0x0;
    goto LAB_005bd85c;
  }
  if (*(int *)(cms + 4) == 0) {
    puVar4 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_SignedData_it_006aa48c);
    *(undefined4 **)(cms + 4) = puVar4;
    puVar1 = PTR_OBJ_nid2obj_006a8240;
    if (puVar4 != (undefined4 *)0x0) {
      puVar7 = (undefined4 *)puVar4[2];
      *puVar4 = 1;
      uVar9 = (*(code *)puVar1)(0x15);
      *puVar7 = uVar9;
      puVar1 = PTR_ASN1_OBJECT_free_006a8104;
      uVar9 = *(undefined4 *)cms;
      *(undefined4 *)(*(int *)(*(int *)(cms + 4) + 8) + 8) = 1;
      (*(code *)puVar1)(uVar9);
      uVar9 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x16);
      piVar10 = *(int **)(cms + 4);
      *(undefined4 *)cms = uVar9;
      goto LAB_005bd608;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x95,0x41,"cms_sd.c",0x54);
  }
  else {
    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
    if (iVar3 == 0x16) {
      piVar10 = *(int **)(cms + 4);
LAB_005bd608:
      if (piVar10 != (int *)0x0) {
        puVar4 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_SignerInfo_it_006aa4b4)
        ;
        if (puVar4 == (undefined4 *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x66,0x41,"cms_sd.c",0x1c6);
        }
        else {
          (*(code *)PTR_X509_check_purpose_006a87e8)(signer,0xffffffff,0xffffffff);
          (*(code *)PTR_CRYPTO_add_lock_006a9080)(&pk->references,1,10,"cms_sd.c",0x142);
          (*(code *)PTR_CRYPTO_add_lock_006a9080)(&signer->references,1,3,"cms_sd.c",0x143);
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
              iVar3 = (*(code *)PTR_EVP_PKEY_get_default_digest_nid_006a8198)(pk,&local_30);
              if (0 < iVar3) {
                uVar9 = (*(code *)PTR_OBJ_nid2sn_006a819c)(local_30);
                md = (EVP_MD *)(*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar9);
                if (md != (EVP_MD *)0x0) goto LAB_005bd6cc;
                (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x66,0x80,"cms_sd.c",0x160);
              }
            }
            else {
LAB_005bd6cc:
              cms_DigestAlgorithm_set(puVar4[2],md);
              for (iVar3 = 0; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(piVar10[1]), iVar3 < iVar6;
                  iVar3 = iVar3 + 1) {
                uVar9 = (*(code *)PTR_sk_value_006a7f24)(piVar10[1],iVar3);
                (*(code *)PTR_X509_ALGOR_get0_006a98c4)(&local_30,0,0,uVar9);
                iVar6 = (*(code *)PTR_OBJ_obj2nid_006a822c)(local_30);
                iVar5 = (*(code *)PTR_EVP_MD_type_006a84cc)(md);
                if (iVar6 == iVar5) break;
              }
              iVar6 = (*(code *)PTR_sk_num_006a7f2c)(piVar10[1]);
              if (iVar3 == iVar6) {
                iVar3 = (*(code *)PTR_X509_ALGOR_new_006a8fb8)();
                if (iVar3 != 0) {
                  cms_DigestAlgorithm_set(iVar3,md);
                  iVar6 = (*(code *)PTR_sk_push_006a80a8)(piVar10[1],iVar3);
                  if (iVar6 != 0) goto LAB_005bd774;
                  (*(code *)PTR_X509_ALGOR_free_006a8f94)(iVar3);
                }
              }
              else {
LAB_005bd774:
                if ((pk->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
                   (pcVar12 = *(code **)(pk->ameth + 0x58), pcVar12 != (code *)0x0)) {
                  iVar3 = (*pcVar12)(pk,5,0,puVar4);
                  if (iVar3 == -2) {
                    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x66,0x7d,"cms_sd.c",0x18b);
                  }
                  else {
                    if (0 < iVar3) goto LAB_005bd7b0;
                    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x66,0x6f,"cms_sd.c",400);
                  }
                  goto LAB_005bd844;
                }
LAB_005bd7b0:
                if ((flags & 0x100) == 0) {
                  if (puVar4[3] == 0) {
                    iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
                    puVar4[3] = iVar3;
                    if (iVar3 == 0) goto LAB_005bd820;
                  }
                  if ((flags & 0x200) == 0) {
                    local_34 = (stack_st_X509_ALGOR *)0x0;
                    iVar3 = CMS_add_standard_smimecap(&local_34);
                    if (iVar3 != 0) {
                      local_30 = 0;
                      iVar3 = (*(code *)PTR_i2d_X509_ALGORS_006aa4b0)(local_34,&local_30);
                      if (0 < iVar3) {
                        iVar3 = (*(code *)PTR_CMS_signed_add1_attr_by_NID_006aa49c)
                                          (puVar4,0xa7,0x10,local_30,iVar3);
                        (*(code *)PTR_CRYPTO_free_006a7f88)(local_30);
                        (*(code *)PTR_sk_pop_free_006a8158)(local_34,PTR_X509_ALGOR_free_006a8f94);
                        if (iVar3 == 0) goto LAB_005bd820;
                        goto LAB_005bd7dc;
                      }
                    }
                    (*(code *)PTR_sk_pop_free_006a8158)(local_34,PTR_X509_ALGOR_free_006a8f94);
                    goto LAB_005bd820;
                  }
LAB_005bd7dc:
                  if ((flags & 0x8000) != 0) {
                    iVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
                    if (iVar3 == 0x16) {
                      uVar9 = 0;
                      if (*(int *)(cms + 4) != 0) {
                        uVar9 = *(undefined4 *)(*(int *)(cms + 4) + 0x14);
                      }
                    }
                    else {
                      uVar9 = 0;
                      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
                    }
                    for (iVar3 = 0; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(uVar9), iVar3 < iVar6;
                        iVar3 = iVar3 + 1) {
                      puVar7 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(uVar9,iVar3);
                      if (((puVar4 != puVar7) &&
                          (iVar6 = (*(code *)PTR_CMS_signed_get_attr_count_006aa440)(puVar7),
                          -1 < iVar6)) &&
                         (iVar6 = (*(code *)PTR_OBJ_cmp_006a9de4)
                                            (*(undefined4 *)puVar4[2],*(undefined4 *)puVar7[2]),
                         iVar6 == 0)) {
                        uVar9 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x33);
                        iVar3 = (*(code *)PTR_CMS_signed_get0_data_by_OBJ_006aa4ac)
                                          (puVar7,uVar9,0xfffffffd,4);
                        if (iVar3 == 0) {
                          (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x6c,0x72,"cms_sd.c",0xc3);
                          goto LAB_005bd844;
                        }
                        iVar3 = (*(code *)PTR_CMS_signed_add1_attr_by_NID_006aa49c)
                                          (puVar4,0x33,4,iVar3,0xffffffff);
                        if ((iVar3 == 0) ||
                           (((flags & 0x4000) == 0 &&
                            (iVar3 = CMS_SignerInfo_sign((CMS_SignerInfo *)puVar4), iVar3 == 0))))
                        goto LAB_005bd844;
                        goto LAB_005bd7f0;
                      }
                    }
                    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x6c,0x83,"cms_sd.c",0xce);
                    goto LAB_005bd844;
                  }
                }
LAB_005bd7f0:
                if ((flags & 2) == 0) {
                  iVar3 = CMS_add1_cert(cms,signer);
                  if (iVar3 == 0) goto LAB_005bd820;
                  iVar3 = piVar10[5];
                }
                else {
                  iVar3 = piVar10[5];
                }
                if (iVar3 == 0) {
                  iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
                  piVar10[5] = iVar3;
                  if (iVar3 == 0) goto LAB_005bd820;
                }
                iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar3,puVar4);
                if (iVar3 != 0) goto LAB_005bd85c;
              }
LAB_005bd820:
              (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x66,0x41,"cms_sd.c",0x1c6);
            }
          }
LAB_005bd844:
          (*(code *)PTR_ASN1_item_free_006a977c)(puVar4,PTR_CMS_SignerInfo_it_006aa4b4);
        }
      }
    }
    else {
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
    }
  }
  puVar4 = (undefined4 *)0x0;
LAB_005bd85c:
  if (local_2c == *(int *)puVar2) {
    return (CMS_SignerInfo *)puVar4;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar4 = (undefined4 *)CMS_ContentInfo_new();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar7 = (undefined4 *)(*(code *)PTR_ASN1_item_new_006a9778)(PTR_CMS_DigestedData_it_006aa4bc);
    if (puVar7 == (undefined4 *)0x0) {
      CMS_ContentInfo_free((CMS_ContentInfo *)puVar4);
      return (CMS_SignerInfo *)0x0;
    }
    uVar9 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x19);
    puVar4[1] = puVar7;
    *puVar4 = uVar9;
    *puVar7 = 0;
    puVar11 = (undefined4 *)puVar7[2];
    uVar9 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x15);
    uVar8 = puVar7[1];
    *puVar11 = uVar9;
    cms_DigestAlgorithm_set(uVar8,iVar3);
  }
  return (CMS_SignerInfo *)puVar4;
}

