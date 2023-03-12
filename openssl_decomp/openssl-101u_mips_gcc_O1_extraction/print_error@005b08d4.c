
/* WARNING: Removing unreachable block (ram,0x005b0ad8) */

int print_error(undefined4 param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char *pcVar7;
  char *pcVar8;
  int iStack_34;
  int iStack_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  piVar6 = &local_2c;
  pcVar7 = &DAT_00000005;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_2c = 5;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar3 = 0;
  local_28 = param_1;
  if (*(code **)(*param_3 + 8) != (code *)0x0) {
    iVar3 = (**(code **)(*param_3 + 8))(param_3);
    iVar3 = -(uint)(iVar3 == 0);
  }
  if (local_c == *(int *)puVar2) {
    return iVar3;
  }
  iVar3 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pcVar7 == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x6c,0x43,"ui_lib.c",0xc4);
    return -1;
  }
  cVar1 = *pcVar7;
  pcVar8 = pcVar7;
  while (cVar1 != '\0') {
    while( true ) {
      pcVar8 = pcVar8 + 1;
      iVar4 = (*(code *)PTR_strchr_006a9a28)(&_gp);
      if (iVar4 == 0) break;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x6c,0x68,"ui_lib.c",0xcb);
      if (*pcVar8 == '\0') goto LAB_005b0a28;
    }
    cVar1 = *pcVar8;
  }
LAB_005b0a28:
  if (piVar6 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x6d,0x43,"ui_lib.c",0x8f);
    return -1;
  }
  if (local_2c != 0) {
    piVar5 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x20,"ui_lib.c",0x93);
    if (piVar5 == (int *)0x0) {
      return -1;
    }
    piVar5[1] = (int)piVar6;
    *piVar5 = 3;
    piVar5[3] = local_2c;
    iVar4 = *(int *)(iVar3 + 4);
    piVar5[2] = iStack_30;
    piVar5[7] = (uint)(iStack_34 != 0);
    if (iVar4 == 0) {
      iVar4 = (*(code *)PTR_sk_new_null_006a6fa4)();
      *(int *)(iVar3 + 4) = iVar4;
      if (iVar4 == 0) {
        if (((piVar5[7] & 1U) != 0) &&
           ((*(code *)PTR_CRYPTO_free_006a6e88)(piVar5[1]), *piVar5 == 3)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar5[4]);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar5[5]);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar5[6]);
        }
        (*(code *)PTR_CRYPTO_free_006a6e88)(piVar5);
        return -1;
      }
    }
    puVar2 = PTR_sk_push_006a6fa8;
    piVar5[4] = (int)param_3;
    piVar5[5] = (int)pcVar7;
    piVar5[6] = (int)&_gp;
    iVar3 = (*(code *)puVar2)(iVar4,piVar5);
    return iVar3 - (uint)(iVar3 < 1);
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x6d,0x69,"ui_lib.c",0x92);
  return -1;
}

