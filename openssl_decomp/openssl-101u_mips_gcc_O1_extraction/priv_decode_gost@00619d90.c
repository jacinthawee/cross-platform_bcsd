
int priv_decode_gost(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  char *local_50;
  char *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined auStack_3c [31];
  undefined local_1d;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_50 = (char *)0x0;
  local_4c = (char *)0x0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_PKCS8_pkey_get0_006a87a0)(&local_40,&local_50,&local_48,&local_44,param_2);
  if (iVar2 != 0) {
    local_4c = local_50;
    iVar2 = decode_gost_algor_params(param_1,local_44);
    if (iVar2 != 0) {
      if (*local_4c == '\x04') {
        piVar5 = (int *)(*(code *)PTR_d2i_ASN1_OCTET_STRING_006a83f8)(0,&local_4c,local_48);
        if ((piVar5 != (int *)0x0) && (*piVar5 == 0x20)) {
          iVar2 = 0;
          puVar8 = &local_1d;
          do {
            puVar7 = (undefined *)(piVar5[2] + iVar2);
            iVar2 = iVar2 + 1;
            *puVar8 = *puVar7;
            puVar8 = puVar8 + -1;
          } while (iVar2 != 0x20);
          (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar5);
          iVar2 = (*(code *)PTR_getbnfrombuf_006a9810)(auStack_3c,0x20);
          goto LAB_00619ea4;
        }
        uVar4 = 0x13f;
LAB_00619f5c:
        ERR_GOST_error(0x84,0x72,"gost_ameth.c",uVar4);
      }
      else {
        iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a83f4)(0,&local_4c,local_48);
        if (iVar6 != 0) {
          iVar2 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a7014)(iVar6,0);
          (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar6);
          if (iVar2 == 0) {
            uVar4 = 0x14e;
            goto LAB_00619f5c;
          }
LAB_00619ea4:
          iVar6 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_1);
          if (iVar6 == 0x32b) {
            iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_1);
            if (iVar6 == 0) {
              iVar6 = (*(code *)PTR_EC_KEY_new_006a71a8)();
              uVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_1);
              (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,uVar4,iVar6);
            }
            iVar3 = (*(code *)PTR_EC_KEY_set_private_key_006a7fbc)(iVar6,iVar2);
            if (iVar3 != 0) {
              iVar3 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a7170)(param_1);
              if (iVar3 != 0) goto LAB_00619f08;
              gost2001_compute_public(iVar6);
              iVar3 = 1;
            }
          }
          else {
            iVar3 = 1;
            if (iVar6 == 0x32c) {
              iVar6 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(param_1);
              if (iVar6 == 0) {
                iVar6 = (*(code *)PTR_DSA_new_006a7528)();
                uVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(param_1);
                (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,uVar4,iVar6);
              }
              uVar4 = (*(code *)PTR_BN_dup_006a8218)(iVar2);
              puVar8 = PTR_EVP_PKEY_missing_parameters_006a7170;
              *(undefined4 *)(iVar6 + 0x1c) = uVar4;
              iVar3 = (*(code *)puVar8)(param_1);
              if (iVar3 == 0) {
                (*(code *)PTR_gost94_compute_public_006a9864)(iVar6);
                iVar3 = 1;
              }
              else {
LAB_00619f08:
                iVar3 = 1;
              }
            }
          }
          (*(code *)PTR_BN_free_006a701c)(iVar2);
          goto LAB_00619e04;
        }
      }
    }
  }
  iVar3 = 0;
LAB_00619e04:
  if (local_1c == *(int *)puVar1) {
    return iVar3;
  }
  iVar2 = local_1c;
  iVar6 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (*(int *)(iVar2 + 0x14) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0061a0e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(code *)PTR_DSA_free_006a7530)();
    return iVar2;
  }
  return iVar6;
}

