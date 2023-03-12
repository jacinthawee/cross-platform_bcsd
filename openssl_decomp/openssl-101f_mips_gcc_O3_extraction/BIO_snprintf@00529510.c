
int BIO_snprintf(char *buf,size_t n,char *format,...)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 in_a3;
  int *piVar4;
  undefined4 local_resc;
  int aiStack_5c [2];
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  undefined *puStack_48;
  code *pcStack_44;
  size_t *apsStack_3c [3];
  char *local_30;
  undefined4 *local_2c;
  undefined *local_28;
  undefined4 *local_20;
  char *local_1c;
  size_t local_18;
  int local_14;
  int local_10;
  int local_c;
  
  puStack_48 = PTR___stack_chk_guard_006aabf0;
  local_2c = &local_resc;
  piVar4 = &local_10;
  piVar3 = &local_14;
  apsStack_3c[0] = &local_18;
  local_28 = &_gp;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_resc = in_a3;
  local_30 = format;
  local_20 = local_2c;
  local_1c = buf;
  local_18 = n;
  _dopr_constprop_0(&local_1c);
  if (local_10 == 0) {
    if (local_14 < 0) {
      local_14 = -1;
    }
  }
  else {
    local_14 = -1;
  }
  if (local_c == *(int *)puStack_48) {
    return local_14;
  }
  pcStack_44 = BIO_vsnprintf;
  aiStack_5c[0] = local_c;
  (**(code **)(local_28 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_4c = *(int *)PTR___stack_chk_guard_006aabf0;
  _dopr_constprop_0(aiStack_5c,apsStack_3c,&iStack_54,&iStack_50,piVar3,piVar4);
  if (iStack_50 == 0) {
    if (iStack_54 < 0) {
      iStack_54 = -1;
    }
  }
  else {
    iStack_54 = -1;
  }
  if (iStack_4c == *(int *)puVar1) {
    return iStack_54;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00529660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_fwrite_006aab7c)();
  return iVar2;
}

