
int X509_PURPOSE_set(int *p,int purpose)

{
  undefined *puVar1;
  int iVar2;
  int local_30 [7];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (purpose - 1U < 9) {
LAB_00594df4:
    iVar2 = 1;
    *p = purpose;
  }
  else {
    local_30[0] = purpose;
    if (xptable != 0) {
      iVar2 = (*(code *)PTR_sk_find_006a8044)(xptable,local_30);
      if ((iVar2 != -1) && (iVar2 != -10)) goto LAB_00594df4;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x8d,0x92,"v3_purp.c",0x94);
    iVar2 = 0;
  }
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (xptable != 0) {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)();
    return iVar2 + 9;
  }
  return 9;
}

