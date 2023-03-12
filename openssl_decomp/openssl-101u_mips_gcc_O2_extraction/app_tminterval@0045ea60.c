
uint app_tminterval(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined auStack_e4 [20];
  uint uStack_d0;
  int iStack_54;
  int iStack_50;
  code *pcStack_4c;
  undefined *local_38;
  int local_2c [4];
  uint local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  piVar5 = local_2c;
  local_38 = &_gp;
  local_1c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  iStack_50 = (*(code *)PTR_times_006a9b08)(piVar5);
  if (param_2 != 0) {
    iStack_50 = local_2c[0];
  }
  iVar2 = iStack_50;
  if (param_1 != 0) {
    piVar5 = (int *)&SUB_00000002;
    (**(code **)(local_38 + -0x5338))(2);
    iStack_50 = iStack_50 - tmstart_17421;
    iVar2 = tmstart_17421;
  }
  tmstart_17421 = iVar2;
  if (local_1c == *(uint *)puVar1) {
    return *(uint *)puVar1;
  }
  pcStack_4c = app_isdir;
  (**(code **)(local_38 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_54 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR___xstat_006a9a84)(3,piVar5,auStack_e4);
  if (iVar2 == 0) {
    uVar3 = (uint)((uStack_d0 & 0xf000) == 0x4000);
  }
  else {
    uVar3 = 0xffffffff;
  }
  if (iStack_54 == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = iStack_54;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar4 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)PTR_stdin_006a9a14);
                    /* WARNING: Could not recover jumptable at 0x0045ec10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_read_006a9b10)(uVar4,iVar2,piVar5);
  return uVar3;
}

