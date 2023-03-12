
undefined4 ndef_prefix(undefined4 param_1,int *param_2,int *param_3,int *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar4 = (char *)param_2;
  piVar5 = param_3;
  if (param_4 != (int *)0x0) {
    puVar6 = (undefined4 *)*param_4;
    uVar3 = (*(code *)PTR_ASN1_item_ndef_i2d_006a910c)(*puVar6,0,puVar6[1]);
    piVar5 = (int *)&DAT_000000a4;
    pcVar4 = "bio_ndef.c";
    local_20 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar3);
    puVar2 = PTR_ASN1_item_ndef_i2d_006a910c;
    if (local_20 != 0) {
      pcVar4 = (char *)&local_20;
      puVar6[5] = local_20;
      *param_2 = local_20;
      piVar5 = (int *)puVar6[1];
      (*(code *)puVar2)(*puVar6);
      if (*(int *)puVar6[4] != 0) {
        uVar3 = 1;
        *param_3 = *(int *)puVar6[4] - *param_2;
        goto LAB_0060b024;
      }
    }
  }
  uVar3 = 0;
LAB_0060b024:
  if (local_1c == *(int *)puVar1) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (param_4 != (int *)0x0) {
    iVar7 = *param_4;
    if (*(int *)(iVar7 + 0x14) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    puVar1 = PTR_CRYPTO_free_006a6e88;
    *(undefined4 *)(iVar7 + 0x14) = 0;
    *(int *)pcVar4 = 0;
    *piVar5 = 0;
    (*(code *)puVar1)(*param_4);
    *param_4 = 0;
    return 1;
  }
  return 0;
}

