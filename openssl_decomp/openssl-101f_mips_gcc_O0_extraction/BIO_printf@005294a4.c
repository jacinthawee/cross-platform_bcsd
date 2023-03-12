
int BIO_printf(BIO *bio,char *format,...)

{
  undefined *puVar1;
  int iVar2;
  undefined4 in_a2;
  int *piVar3;
  undefined4 in_a3;
  int *piVar4;
  undefined4 local_res8;
  undefined4 local_resc;
  int aiStack_84 [2];
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  char **appcStack_64 [3];
  undefined4 *puStack_58;
  undefined4 *puStack_54;
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
  
  puStack_30 = PTR___stack_chk_guard_006aabf0;
  puStack_58 = &local_res8;
  local_18 = &_gp;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_res8 = in_a2;
  local_resc = in_a3;
  local_10 = puStack_58;
  iVar2 = BIO_vprintf(bio,format,puStack_58);
  if (local_c == *(int *)puStack_30) {
    return iVar2;
  }
  pcStack_2c = BIO_snprintf;
  iStack_44 = local_c;
  (**(code **)(local_18 + -0x5328))();
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  puStack_54 = &uStack_1c;
  piVar4 = &iStack_38;
  piVar3 = &iStack_3c;
  appcStack_64[0] = &pcStack_40;
  puStack_50 = &_gp;
  iStack_34 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_48 = puStack_54;
  pcStack_40 = format;
  uStack_1c = in_a3;
  _dopr_constprop_0(&iStack_44);
  if (iStack_38 == 0) {
    if (iStack_3c < 0) {
      iStack_3c = -1;
    }
  }
  else {
    iStack_3c = -1;
  }
  if (iStack_34 == *(int *)puStack_70) {
    return iStack_3c;
  }
  pcStack_6c = BIO_vsnprintf;
  aiStack_84[0] = iStack_34;
  (**(code **)(puStack_50 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  _dopr_constprop_0(aiStack_84,appcStack_64,&iStack_7c,&iStack_78,piVar3,piVar4);
  if (iStack_78 == 0) {
    if (iStack_7c < 0) {
      iStack_7c = -1;
    }
  }
  else {
    iStack_7c = -1;
  }
  if (iStack_74 == *(int *)puVar1) {
    return iStack_7c;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00529660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_fwrite_006aab7c)();
  return iVar2;
}

