
int CMS_set1_signers_certs(CMS_ContentInfo *cms,stack_st_X509 *certs,uint flags)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int local_40;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  if (iVar1 != 0x16) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
    return -1;
  }
  iVar1 = *(int *)(cms + 4);
  if (iVar1 == 0) {
    local_40 = -1;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0xc);
    local_40 = 0;
    iVar10 = 0;
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar1 + 0x14));
    if (0 < iVar3) {
      do {
        iVar3 = (*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(iVar1 + 0x14),iVar10);
        if (*(int *)(iVar3 + 0x1c) == 0) {
          for (iVar9 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(certs), iVar9 < iVar4;
              iVar9 = iVar9 + 1) {
            iVar4 = (*(code *)PTR_sk_value_006a6e24)(certs,iVar9);
            piVar11 = *(int **)(iVar3 + 4);
            if (*piVar11 == 0) {
              uVar7 = *(undefined4 *)piVar11[1];
              uVar6 = (*(code *)PTR_X509_get_issuer_name_006a76e4)(iVar4,0xffffffff,0xffffffff);
              iVar5 = (*(code *)PTR_X509_NAME_cmp_006a8030)(uVar7,uVar6);
              if (iVar5 == 0) {
                uVar7 = *(undefined4 *)(piVar11[1] + 4);
                uVar6 = (*(code *)PTR_X509_get_serialNumber_006a6f9c)(iVar4);
                iVar5 = (*(code *)PTR_ASN1_INTEGER_cmp_006a8d38)(uVar7,uVar6);
joined_r0x005b92a4:
                if (iVar5 == 0) {
                  if (iVar4 != 0) {
                    (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar4 + 0x10,1,3,"cms_sd.c",0x1e2);
                    if (*(int *)(iVar3 + 0x20) != 0) {
                      (*(code *)PTR_EVP_PKEY_free_006a6e78)();
                    }
                    uVar6 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar4);
                    *(undefined4 *)(iVar3 + 0x20) = uVar6;
                  }
                  if (*(int *)(iVar3 + 0x1c) != 0) {
                    (*(code *)PTR_X509_free_006a6e90)();
                  }
                  *(int *)(iVar3 + 0x1c) = iVar4;
                  local_40 = local_40 + 1;
                  if (iVar4 != 0) goto LAB_005b90a0;
                  goto LAB_005b9204;
                }
              }
            }
            else if (*piVar11 == 1) {
              (*(code *)PTR_X509_check_purpose_006a771c)();
              if (*(int *)(iVar4 + 0x38) != 0) {
                iVar5 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)
                                  (piVar11[1],*(int *)(iVar4 + 0x38));
                goto joined_r0x005b92a4;
              }
            }
          }
          if (*(int *)(iVar3 + 0x1c) == 0) {
LAB_005b9204:
            iVar9 = 0;
            if ((flags & 0x10) == 0) {
              for (; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(uVar2), iVar9 < iVar4; iVar9 = iVar9 + 1
                  ) {
                piVar11 = (int *)(*(code *)PTR_sk_value_006a6e24)(uVar2,iVar9);
                if (*piVar11 == 0) {
                  piVar8 = *(int **)(iVar3 + 4);
                  iVar4 = piVar11[1];
                  if (*piVar8 == 0) {
                    uVar7 = *(undefined4 *)piVar8[1];
                    uVar6 = (*(code *)PTR_X509_get_issuer_name_006a76e4)(iVar4,0xffffffff);
                    iVar5 = (*(code *)PTR_X509_NAME_cmp_006a8030)(uVar7,uVar6);
                    if (iVar5 == 0) {
                      uVar7 = *(undefined4 *)(piVar8[1] + 4);
                      uVar6 = (*(code *)PTR_X509_get_serialNumber_006a6f9c)(iVar4);
                      iVar5 = (*(code *)PTR_ASN1_INTEGER_cmp_006a8d38)(uVar7,uVar6);
joined_r0x005b9410:
                      if (iVar5 == 0) {
                        if (iVar4 != 0) {
                          (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar4 + 0x10,1,3,"cms_sd.c",0x1e2)
                          ;
                          if (*(int *)(iVar3 + 0x20) != 0) {
                            (*(code *)PTR_EVP_PKEY_free_006a6e78)();
                          }
                          uVar6 = (*(code *)PTR_X509_get_pubkey_006a6f08)(iVar4);
                          *(undefined4 *)(iVar3 + 0x20) = uVar6;
                        }
                        if (*(int *)(iVar3 + 0x1c) != 0) {
                          (*(code *)PTR_X509_free_006a6e90)();
                        }
                        *(int *)(iVar3 + 0x1c) = iVar4;
                        local_40 = local_40 + 1;
                        break;
                      }
                    }
                  }
                  else if (*piVar8 == 1) {
                    (*(code *)PTR_X509_check_purpose_006a771c)(iVar4,0xffffffff,0xffffffff);
                    if (*(int *)(iVar4 + 0x38) != 0) {
                      iVar5 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)
                                        (piVar8[1],*(int *)(iVar4 + 0x38));
                      goto joined_r0x005b9410;
                    }
                  }
                }
              }
            }
          }
        }
LAB_005b90a0:
        iVar10 = iVar10 + 1;
        iVar3 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar1 + 0x14));
      } while (iVar10 < iVar3);
    }
  }
  return local_40;
}

