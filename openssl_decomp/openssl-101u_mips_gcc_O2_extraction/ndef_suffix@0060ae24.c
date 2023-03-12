
undefined4 ndef_suffix(undefined4 param_1,int *param_2,int *param_3,int **param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  int *unaff_s0;
  int *piVar9;
  int *unaff_s2;
  code *pcVar10;
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
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  local_38 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar6 = (char *)param_2;
  piVar3 = param_3;
  piStack_54 = unaff_s2;
  if (param_4 == (int **)0x0) {
LAB_0060af34:
    uVar5 = 0;
  }
  else {
    unaff_s0 = *param_4;
    param_4 = &local_28;
    piVar3 = (int *)unaff_s0[1];
    local_24 = unaff_s0[2];
    local_28 = (int *)unaff_s0[3];
    local_20 = unaff_s0[4];
    pcVar6 = (char *)unaff_s0;
    iVar4 = (**(code **)(piVar3[4] + 0x10))(0xb);
    piStack_54 = param_2;
    if (iVar4 < 1) goto LAB_0060af34;
    uVar5 = (**(code **)(local_38 + -0x5cd4))(*unaff_s0,0,unaff_s0[1]);
    piVar3 = (int *)0xea;
    pcVar6 = "bio_ndef.c";
    local_2c = (**(code **)(local_38 + -0x7dd8))(uVar5);
    if (local_2c == 0) goto LAB_0060af34;
    pcVar10 = *(code **)(local_38 + -0x5cd4);
    pcVar6 = (char *)&local_2c;
    unaff_s0[5] = local_2c;
    *param_2 = local_2c;
    piVar3 = (int *)unaff_s0[1];
    iVar4 = (*pcVar10)(*unaff_s0);
    if (*(int *)unaff_s0[4] == 0) goto LAB_0060af34;
    *param_2 = *(int *)unaff_s0[4];
    uVar5 = 1;
    pcVar6 = (char *)unaff_s0[5];
    *param_3 = iVar4 - (*(int *)unaff_s0[4] - (int)pcVar6);
  }
  if (local_1c == *(int *)puStack_58) {
    return uVar5;
  }
  pcStack_4c = ndef_prefix;
  (**(code **)(local_38 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_64 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar7 = pcVar6;
  piVar8 = piVar3;
  piStack_5c = unaff_s0;
  piStack_50 = param_3;
  if (param_4 != (int **)0x0) {
    piVar9 = *param_4;
    uVar5 = (*(code *)PTR_ASN1_item_ndef_i2d_006a910c)(*piVar9,0,piVar9[1]);
    piVar8 = (int *)&DAT_000000a4;
    pcVar7 = "bio_ndef.c";
    iStack_68 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar5);
    puVar2 = PTR_ASN1_item_ndef_i2d_006a910c;
    if (iStack_68 != 0) {
      pcVar7 = (char *)&iStack_68;
      piVar9[5] = iStack_68;
      *(int *)pcVar6 = iStack_68;
      piVar8 = (int *)piVar9[1];
      (*(code *)puVar2)(*piVar9);
      if (*(int *)piVar9[4] != 0) {
        uVar5 = 1;
        *piVar3 = *(int *)piVar9[4] - *(int *)pcVar6;
        goto LAB_0060b024;
      }
    }
  }
  uVar5 = 0;
LAB_0060b024:
  if (iStack_64 == *(int *)puVar1) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (param_4 != (int **)0x0) {
    piVar3 = *param_4;
    if (piVar3[5] != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar1 = PTR_CRYPTO_free_006a6e88;
    piVar3[5] = 0;
    *(int *)pcVar7 = 0;
    *piVar8 = 0;
    (*(code *)puVar1)(*param_4);
    *param_4 = (int *)0x0;
    return 1;
  }
  return 0;
}

