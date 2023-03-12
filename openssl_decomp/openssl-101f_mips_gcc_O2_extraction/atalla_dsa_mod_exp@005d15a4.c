
uint atalla_dsa_mod_exp(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined *param_4,
                       undefined4 param_5,undefined *param_6,undefined4 param_7,undefined4 param_8)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uStack_4c;
  undefined auStack_40 [20];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_BN_init_006a96a0)(auStack_40);
  uVar3 = param_7;
  uVar5 = param_8;
  iVar2 = atalla_mod_exp(param_2,param_3,param_4,param_7);
  if (iVar2 != 0) {
    uVar3 = param_7;
    uVar5 = param_8;
    iVar2 = atalla_mod_exp(auStack_40,param_5,param_6,param_7);
    param_3 = param_5;
    param_4 = param_6;
    if (iVar2 != 0) {
      param_4 = auStack_40;
      iVar2 = (*(code *)PTR_BN_mod_mul_006a9698)(param_2,param_2,auStack_40,param_7);
      uVar4 = (uint)(iVar2 != 0);
      goto LAB_005d163c;
    }
  }
  param_8 = uVar5;
  param_7 = uVar3;
  param_2 = param_3;
  uVar4 = 0;
LAB_005d163c:
  (*(code *)PTR_BN_free_006a811c)(auStack_40);
  if (local_2c == *(int *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar4 = atalla_mod_exp(param_2,param_4,param_7,param_8,uStack_4c);
  return uVar4;
}

