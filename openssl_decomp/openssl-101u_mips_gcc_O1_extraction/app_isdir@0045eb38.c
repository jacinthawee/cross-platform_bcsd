
uint app_isdir(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined auStack_9c [20];
  uint local_88;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR___xstat_006a9a84)(3,param_1,auStack_9c);
  if (iVar2 == 0) {
    uVar3 = (uint)((local_88 & 0xf000) == 0x4000);
  }
  else {
    uVar3 = 0xffffffff;
  }
  if (local_c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar4 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)PTR_stdin_006a9a14);
                    /* WARNING: Could not recover jumptable at 0x0045ec10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_read_006a9b10)(uVar4,iVar2,param_1);
  return uVar3;
}

