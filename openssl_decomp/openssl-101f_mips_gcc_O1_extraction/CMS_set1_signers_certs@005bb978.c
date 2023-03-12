
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
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
  if (iVar1 != 0x16) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
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
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar1 + 0x14));
    if (0 < iVar3) {
      do {
        iVar3 = (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(iVar1 + 0x14),iVar10);
        if (*(int *)(iVar3 + 0x1c) == 0) {
          for (iVar9 = 0; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(certs), iVar9 < iVar4;
              iVar9 = iVar9 + 1) {
            iVar4 = (*(code *)PTR_sk_value_006a7f24)(certs,iVar9);
            piVar11 = *(int **)(iVar3 + 4);
            if (*piVar11 == 0) {
              uVar7 = *(undefined4 *)piVar11[1];
              uVar6 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(iVar4,0xffffffff,0xffffffff);
              iVar5 = (*(code *)PTR_X509_NAME_cmp_006a918c)(uVar7,uVar6);
              if (iVar5 == 0) {
                uVar7 = *(undefined4 *)(piVar11[1] + 4);
                uVar6 = (*(code *)PTR_X509_get_serialNumber_006a809c)(iVar4);
                iVar5 = (*(code *)PTR_ASN1_INTEGER_cmp_006a9e58)(uVar7,uVar6);
joined_r0x005bbc44:
                if (iVar5 == 0) {
                  if (iVar4 != 0) {
                    (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar4 + 0x10,1,3,"cms_sd.c",0x215);
                    if (*(int *)(iVar3 + 0x20) != 0) {
                      (*(code *)PTR_EVP_PKEY_free_006a7f78)();
                    }
                    uVar6 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar4);
                    *(undefined4 *)(iVar3 + 0x20) = uVar6;
                  }
                  if (*(int *)(iVar3 + 0x1c) != 0) {
                    (*(code *)PTR_X509_free_006a7f90)();
                  }
                  *(int *)(iVar3 + 0x1c) = iVar4;
                  local_40 = local_40 + 1;
                  if (iVar4 != 0) goto LAB_005bba40;
                  goto LAB_005bbba4;
                }
              }
            }
            else if (*piVar11 == 1) {
              (*(code *)PTR_X509_check_purpose_006a87e8)();
              if (*(int *)(iVar4 + 0x38) != 0) {
                iVar5 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)
                                  (piVar11[1],*(int *)(iVar4 + 0x38));
                goto joined_r0x005bbc44;
              }
            }
          }
          if (*(int *)(iVar3 + 0x1c) == 0) {
LAB_005bbba4:
            iVar9 = 0;
            if ((flags & 0x10) == 0) {
              for (; iVar4 = (*(code *)PTR_sk_num_006a7f2c)(uVar2), iVar9 < iVar4; iVar9 = iVar9 + 1
                  ) {
                piVar11 = (int *)(*(code *)PTR_sk_value_006a7f24)(uVar2,iVar9);
                if (*piVar11 == 0) {
                  piVar8 = *(int **)(iVar3 + 4);
                  iVar4 = piVar11[1];
                  if (*piVar8 == 0) {
                    uVar7 = *(undefined4 *)piVar8[1];
                    uVar6 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(iVar4,0xffffffff);
                    iVar5 = (*(code *)PTR_X509_NAME_cmp_006a918c)(uVar7,uVar6);
                    if (iVar5 == 0) {
                      uVar7 = *(undefined4 *)(piVar8[1] + 4);
                      uVar6 = (*(code *)PTR_X509_get_serialNumber_006a809c)(iVar4);
                      iVar5 = (*(code *)PTR_ASN1_INTEGER_cmp_006a9e58)(uVar7,uVar6);
joined_r0x005bbdb0:
                      if (iVar5 == 0) {
                        if (iVar4 != 0) {
                          (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar4 + 0x10,1,3,"cms_sd.c",0x215)
                          ;
                          if (*(int *)(iVar3 + 0x20) != 0) {
                            (*(code *)PTR_EVP_PKEY_free_006a7f78)();
                          }
                          uVar6 = (*(code *)PTR_X509_get_pubkey_006a8008)(iVar4);
                          *(undefined4 *)(iVar3 + 0x20) = uVar6;
                        }
                        if (*(int *)(iVar3 + 0x1c) != 0) {
                          (*(code *)PTR_X509_free_006a7f90)();
                        }
                        *(int *)(iVar3 + 0x1c) = iVar4;
                        local_40 = local_40 + 1;
                        break;
                      }
                    }
                  }
                  else if (*piVar8 == 1) {
                    (*(code *)PTR_X509_check_purpose_006a87e8)(iVar4,0xffffffff,0xffffffff);
                    if (*(int *)(iVar4 + 0x38) != 0) {
                      iVar5 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc)
                                        (piVar8[1],*(int *)(iVar4 + 0x38));
                      goto joined_r0x005bbdb0;
                    }
                  }
                }
              }
            }
          }
        }
LAB_005bba40:
        iVar10 = iVar10 + 1;
        iVar3 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar1 + 0x14));
      } while (iVar10 < iVar3);
    }
  }
  return local_40;
}

