
int pkey_dsa_sign(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  undefined auStack_68 [12];
  int iStack_5c;
  undefined *puStack_58;
  undefined4 uStack_54;
  undefined4 *puStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  code *pcStack_44;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined *local_28;
  undefined4 local_20;
  int local_1c;
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  local_28 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x14);
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x14) == 0) {
    uVar2 = 0x40;
  }
  else {
    uVar2 = (*(code *)PTR_EVP_MD_type_006a84cc)();
  }
  local_30 = &local_20;
  uVar5 = param_4;
  local_2c = uStack_48;
  iVar3 = (**(code **)(local_28 + -0x7364))(uVar2,param_4,param_5,param_2);
  if (0 < iVar3) {
    iVar3 = 1;
    *param_3 = local_20;
  }
  if (local_1c != *(int *)puStack_58) {
    pcStack_44 = pkey_dsa_paramgen;
    iVar3 = local_1c;
    (**(code **)(local_28 + -0x5328))();
    puVar1 = PTR___stack_chk_guard_006aabf0;
    iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
    puVar7 = *(undefined4 **)(iVar3 + 0x14);
    uStack_54 = param_4;
    puStack_50 = param_3;
    uStack_4c = param_2;
    if (*(int *)(iVar3 + 0x1c) == 0) {
      puVar6 = (undefined *)0x0;
      iVar3 = (*(code *)PTR_DSA_new_006a8624)();
    }
    else {
      puVar6 = auStack_68;
      (*(code *)PTR_evp_pkey_set_cb_translate_006aa83c)(puVar6,iVar3);
      iVar3 = (*(code *)PTR_DSA_new_006a8624)();
    }
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(code *)PTR_dsa_builtin_paramgen_006aa864)
                        (iVar3,*puVar7,puVar7[1],puVar7[2],0,0,0,0,0,puVar6);
      if (iVar4 == 0) {
        (*(code *)PTR_DSA_free_006a862c)(iVar3);
        iVar4 = 0;
      }
      else {
        (*(code *)PTR_EVP_PKEY_assign_006a94e4)(uVar5,0x74,iVar3);
      }
    }
    if (iStack_5c != *(int *)puVar1) {
      iVar3 = iStack_5c;
      iVar4 = (*(code *)PTR___stack_chk_fail_006aabb8)();
      if (*(int *)(iVar3 + 0x14) == 0) {
        return iVar4;
      }
                    /* WARNING: Could not recover jumptable at 0x00600128. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (*(code *)PTR_CRYPTO_free_006a7f88)();
      return iVar3;
    }
    return iVar4;
  }
  return iVar3;
}

