
undefined1 * app_RAND_write_file(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined auStack_dc [200];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar3 = (undefined1 *)0x0;
  if ((egdsocket == 0) && (puVar3 = seeded, seeded != (undefined1 *)0x0)) {
    if (((param_1 == 0) &&
        (param_1 = (*(code *)PTR_RAND_file_name_006a8d5c)(auStack_dc,200), param_1 == 0)) ||
       (iVar2 = (*(code *)PTR_RAND_write_file_006a8d60)(param_1), iVar2 == 0)) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_2,"unable to write \'random state\'\n");
      puVar3 = (undefined1 *)0x0;
    }
    else {
      puVar3 = (undefined1 *)0x1;
    }
  }
  if (local_14 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    seeded = (undefined1 *)0x1;
    return &_ITM_registerTMCloneTable;
  }
  return puVar3;
}

