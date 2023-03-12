
undefined4 ndef_prefix(undefined4 param_1,int *param_2,int *param_3,int *param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar3 = param_2;
  piVar4 = param_3;
  if (param_4 != (int *)0x0) {
    puVar5 = (undefined4 *)*param_4;
    uVar2 = (*(code *)PTR_ASN1_item_ndef_i2d_006aa228)(*puVar5,0,puVar5[1]);
    local_20 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar2,"bio_ndef.c",0xa7);
    piVar3 = &local_20;
    puVar5[5] = local_20;
    *param_2 = local_20;
    piVar4 = (int *)puVar5[1];
    (*(code *)PTR_ASN1_item_ndef_i2d_006aa228)(*puVar5);
    if (*(int *)puVar5[4] != 0) {
      uVar2 = 1;
      *param_3 = *(int *)puVar5[4] - *param_2;
      goto LAB_0060cdac;
    }
  }
  uVar2 = 0;
LAB_0060cdac:
  if (local_1c == *(int *)puVar1) {
    return uVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (param_4 != (int *)0x0) {
    iVar6 = *param_4;
    if (*(int *)(iVar6 + 0x14) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    puVar1 = PTR_CRYPTO_free_006a7f88;
    *(undefined4 *)(iVar6 + 0x14) = 0;
    *piVar3 = 0;
    *piVar4 = 0;
    (*(code *)puVar1)(*param_4);
    *param_4 = 0;
    return 1;
  }
  return 0;
}

