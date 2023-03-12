
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_50 = (char *)0x0;
  local_4c = (char *)0x0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_PKCS8_pkey_get0_006a98c0)(&local_40,&local_50,&local_48,&local_44,param_2);
  if (iVar2 != 0) {
    local_4c = local_50;
    iVar2 = decode_gost_algor_params(param_1,local_44);
    if (iVar2 != 0) {
      if (*local_4c == '\x04') {
        piVar5 = (int *)(*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(0,&local_4c,local_48);
        if ((piVar5 != (int *)0x0) && (*piVar5 == 0x20)) {
          iVar2 = 0;
          puVar8 = &local_1d;
          do {
            puVar7 = (undefined *)(piVar5[2] + iVar2);
            iVar2 = iVar2 + 1;
            *puVar8 = *puVar7;
            puVar8 = puVar8 + -1;
          } while (iVar2 != 0x20);
          (*(code *)PTR_ASN1_STRING_free_006a98bc)(piVar5);
          iVar2 = (*(code *)PTR_getbnfrombuf_006aa920)(auStack_3c,0x20);
          goto LAB_0061a990;
        }
        uVar4 = 0x14f;
LAB_0061aa48:
        ERR_GOST_error(0x84,0x72,"gost_ameth.c",uVar4);
      }
      else {
        iVar6 = (*(code *)PTR_d2i_ASN1_INTEGER_006a950c)(0,&local_4c,local_48);
        if (iVar6 != 0) {
          iVar2 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(iVar6,0);
          (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar6);
          if (iVar2 == 0) {
            uVar4 = 0x162;
            goto LAB_0061aa48;
          }
LAB_0061a990:
          iVar6 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_1);
          if (iVar6 == 0x32b) {
            iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
            if (iVar6 == 0) {
              iVar6 = (*(code *)PTR_EC_KEY_new_006a82a8)();
              uVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_1);
              (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,uVar4,iVar6);
            }
            iVar3 = (*(code *)PTR_EC_KEY_set_private_key_006a913c)(iVar6,iVar2);
            if (iVar3 != 0) {
              iVar3 = (*(code *)PTR_EVP_PKEY_missing_parameters_006a8270)(param_1);
              if (iVar3 != 0) goto LAB_0061a9f4;
              gost2001_compute_public(iVar6);
              iVar3 = 1;
            }
          }
          else {
            iVar3 = 1;
            if (iVar6 == 0x32c) {
              iVar6 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_1);
              if (iVar6 == 0) {
                iVar6 = (*(code *)PTR_DSA_new_006a8624)();
                uVar4 = (*(code *)PTR_EVP_PKEY_base_id_006a800c)(param_1);
                (*(code *)PTR_EVP_PKEY_assign_006a94e4)(param_1,uVar4,iVar6);
              }
              uVar4 = (*(code *)PTR_BN_dup_006a9100)(iVar2);
              puVar8 = PTR_EVP_PKEY_missing_parameters_006a8270;
              *(undefined4 *)(iVar6 + 0x1c) = uVar4;
              iVar3 = (*(code *)puVar8)(param_1);
              if (iVar3 == 0) {
                (*(code *)PTR_gost94_compute_public_006aa974)(iVar6);
                iVar3 = 1;
              }
              else {
LAB_0061a9f4:
                iVar3 = 1;
              }
            }
          }
          (*(code *)PTR_BN_free_006a811c)(iVar2);
          goto LAB_0061a8f0;
        }
      }
    }
  }
  iVar3 = 0;
LAB_0061a8f0:
  if (local_1c == *(int *)puVar1) {
    return iVar3;
  }
  iVar2 = local_1c;
  iVar6 = (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (*(int *)(iVar2 + 0x14) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0061abd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(code *)PTR_DSA_free_006a862c)();
    return iVar2;
  }
  return iVar6;
}

