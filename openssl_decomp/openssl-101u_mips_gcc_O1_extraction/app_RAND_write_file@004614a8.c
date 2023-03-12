
undefined * app_RAND_write_file(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  undefined auStack_dc [200];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar3 = (undefined *)0x0;
  if ((egdsocket == 0) && (puVar3 = seeded, seeded != (undefined *)0x0)) {
    if (((param_1 == 0) &&
        (param_1 = (*(code *)PTR_RAND_file_name_006a7c6c)(auStack_dc,200), param_1 == 0)) ||
       (iVar2 = (*(code *)PTR_RAND_write_file_006a7c70)(param_1), iVar2 == 0)) {
      (*(code *)PTR_BIO_printf_006a6e38)(param_2,"unable to write \'random state\'\n");
      puVar3 = (undefined *)0x0;
    }
    else {
      puVar3 = (undefined *)0x1;
    }
  }
  if (local_14 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    seeded = (undefined *)0x1;
    return &_gp_1;
  }
  return puVar3;
}

