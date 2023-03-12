
undefined4 ndef_suffix(undefined4 param_1,int *param_2,int *param_3,int **param_4)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *unaff_s0;
  int *piVar8;
  int *unaff_s2;
  int iStack_68;
  int iStack_64;
  int *piStack_5c;
  undefined *puStack_58;
  int *piStack_54;
  int *piStack_50;
  code *pcStack_4c;
  undefined *local_38;
  int local_2c;
  int *local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar5 = param_2;
  piVar2 = param_3;
  piStack_54 = unaff_s2;
  if (param_4 == (int **)0x0) {
LAB_0060ccc0:
    uVar4 = 0;
  }
  else {
    unaff_s0 = *param_4;
    param_4 = &local_28;
    piVar2 = (int *)unaff_s0[1];
    local_24 = unaff_s0[2];
    local_28 = (int *)unaff_s0[3];
    local_20 = unaff_s0[4];
    piVar5 = unaff_s0;
    iVar3 = (**(code **)(piVar2[4] + 0x10))(0xb);
    piStack_54 = param_2;
    if (iVar3 < 1) goto LAB_0060ccc0;
    uVar4 = (**(code **)(local_38 + -0x5cb8))(*unaff_s0,0,unaff_s0[1]);
    local_2c = (**(code **)(local_38 + -0x7dd8))(uVar4,"bio_ndef.c",0xe8);
    piVar5 = &local_2c;
    unaff_s0[5] = local_2c;
    *param_2 = local_2c;
    piVar2 = (int *)unaff_s0[1];
    iVar3 = (**(code **)(local_38 + -0x5cb8))(*unaff_s0);
    if (*(int *)unaff_s0[4] == 0) goto LAB_0060ccc0;
    *param_2 = *(int *)unaff_s0[4];
    uVar4 = 1;
    piVar5 = (int *)unaff_s0[5];
    *param_3 = iVar3 - (*(int *)unaff_s0[4] - (int)piVar5);
  }
  if (local_1c == *(int *)puStack_58) {
    return uVar4;
  }
  pcStack_4c = ndef_prefix;
  (**(code **)(local_38 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar6 = piVar5;
  piVar7 = piVar2;
  piStack_5c = unaff_s0;
  piStack_50 = param_3;
  if (param_4 != (int **)0x0) {
    piVar8 = *param_4;
    uVar4 = (*(code *)PTR_ASN1_item_ndef_i2d_006aa228)(*piVar8,0,piVar8[1]);
    iStack_68 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar4,"bio_ndef.c",0xa7);
    piVar6 = &iStack_68;
    piVar8[5] = iStack_68;
    *piVar5 = iStack_68;
    piVar7 = (int *)piVar8[1];
    (*(code *)PTR_ASN1_item_ndef_i2d_006aa228)(*piVar8);
    if (*(int *)piVar8[4] != 0) {
      uVar4 = 1;
      *piVar2 = *(int *)piVar8[4] - *piVar5;
      goto LAB_0060cdac;
    }
  }
  uVar4 = 0;
LAB_0060cdac:
  if (iStack_64 == *(int *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (param_4 != (int **)0x0) {
    piVar5 = *param_4;
    if (piVar5[5] != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar1 = PTR_CRYPTO_free_006a7f88;
    piVar5[5] = 0;
    *piVar6 = 0;
    *piVar7 = 0;
    (*(code *)puVar1)(*param_4);
    *param_4 = (int *)0x0;
    return 1;
  }
  return 0;
}

