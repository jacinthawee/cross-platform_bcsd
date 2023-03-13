
int BIO_snprintf(char *buf,size_t n,char *format,...)

{
  undefined *puVar1;
  int iVar2;
  size_t *psVar3;
  undefined4 in_a3;
  int *piVar4;
  undefined4 local_resc;
  int aiStack_64 [2];
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  undefined *puStack_50;
  code *pcStack_4c;
  undefined4 auStack_44 [3];
  int *local_38;
  char *local_34;
  undefined4 *local_30;
  undefined *local_28;
  undefined4 *local_20;
  char *local_1c;
  size_t local_18;
  int local_14;
  int local_10;
  int local_c;
  
  puStack_50 = PTR___stack_chk_guard_006a9ae8;
  local_30 = &local_resc;
  local_38 = &local_10;
  piVar4 = &local_14;
  psVar3 = &local_18;
  auStack_44[0] = 0;
  local_28 = &_gp;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_resc = in_a3;
  local_34 = format;
  local_20 = local_30;
  local_1c = buf;
  local_18 = n;
  iVar2 = _dopr(&local_1c);
  if ((iVar2 == 0) || (local_10 != 0)) {
    local_14 = -1;
  }
  else if (local_14 < 0) {
    local_14 = -1;
  }
  if (local_c == *(int *)puStack_50) {
    return local_14;
  }
  pcStack_4c = BIO_vsnprintf;
  aiStack_64[0] = local_c;
  (**(code **)(local_28 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_54 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = _dopr(aiStack_64,0,auStack_44,&iStack_5c,&iStack_58,psVar3,piVar4);
  if ((iVar2 == 0) || (iStack_58 != 0)) {
    iStack_5c = -1;
  }
  else if (iStack_5c < 0) {
    iStack_5c = -1;
  }
  if (iStack_54 == *(int *)puVar1) {
    return iStack_5c;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00526240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_fwrite_006a9a74)();
  return iVar2;
}

