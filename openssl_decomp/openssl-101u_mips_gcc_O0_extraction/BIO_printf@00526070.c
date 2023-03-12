
int BIO_printf(BIO *bio,char *format,...)

{
  undefined *puVar1;
  int iVar2;
  undefined4 in_a2;
  char **ppcVar3;
  undefined4 in_a3;
  int *piVar4;
  undefined4 local_res8;
  undefined4 local_resc;
  int aiStack_8c [2];
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  undefined *puStack_78;
  code *pcStack_74;
  undefined4 auStack_6c [3];
  int *piStack_60;
  undefined4 *puStack_5c;
  undefined4 *puStack_58;
  undefined *puStack_50;
  undefined4 *puStack_48;
  int iStack_44;
  char *pcStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  undefined *puStack_30;
  code *pcStack_2c;
  undefined4 uStack_1c;
  undefined *local_18;
  undefined4 *local_10;
  int local_c;
  
  puStack_30 = PTR___stack_chk_guard_006a9ae8;
  puStack_5c = &local_res8;
  local_18 = &_gp;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_res8 = in_a2;
  local_resc = in_a3;
  local_10 = puStack_5c;
  iVar2 = BIO_vprintf(bio,format,puStack_5c);
  if (local_c == *(int *)puStack_30) {
    return iVar2;
  }
  pcStack_2c = BIO_snprintf;
  iStack_44 = local_c;
  (**(code **)(local_18 + -0x5330))();
  puStack_78 = PTR___stack_chk_guard_006a9ae8;
  puStack_58 = &uStack_1c;
  piStack_60 = &iStack_38;
  piVar4 = &iStack_3c;
  ppcVar3 = &pcStack_40;
  auStack_6c[0] = 0;
  puStack_50 = &_gp;
  iStack_34 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_48 = puStack_58;
  pcStack_40 = format;
  uStack_1c = in_a3;
  iVar2 = _dopr(&iStack_44);
  if ((iVar2 == 0) || (iStack_38 != 0)) {
    iStack_3c = -1;
  }
  else if (iStack_3c < 0) {
    iStack_3c = -1;
  }
  if (iStack_34 == *(int *)puStack_78) {
    return iStack_3c;
  }
  pcStack_74 = BIO_vsnprintf;
  aiStack_8c[0] = iStack_34;
  (**(code **)(puStack_50 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = _dopr(aiStack_8c,0,auStack_6c,&iStack_84,&iStack_80,ppcVar3,piVar4);
  if ((iVar2 == 0) || (iStack_80 != 0)) {
    iStack_84 = -1;
  }
  else if (iStack_84 < 0) {
    iStack_84 = -1;
  }
  if (iStack_7c == *(int *)puVar1) {
    return iStack_84;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00526240. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_fwrite_006a9a74)();
  return iVar2;
}

