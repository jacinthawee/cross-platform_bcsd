
int X509_VERIFY_PARAM_set_purpose(X509_VERIFY_PARAM *param,int purpose)

{
  undefined *puVar1;
  int iVar2;
  int aiStack_30 [7];
  int iStack_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (purpose - 1U < 9) {
LAB_00597b44:
    iVar2 = 1;
    param->purpose = purpose;
  }
  else {
    aiStack_30[0] = purpose;
    if (xptable != 0) {
      iVar2 = (*(code *)PTR_sk_find_006a906c)(xptable,aiStack_30);
      if ((iVar2 != -1) && (iVar2 != -10)) goto LAB_00597b44;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8d,0x92,"v3_purp.c",0x80);
    iVar2 = 0;
  }
  if (iStack_14 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (xptable != 0) {
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)();
    return iVar2 + 9;
  }
  return 9;
}

