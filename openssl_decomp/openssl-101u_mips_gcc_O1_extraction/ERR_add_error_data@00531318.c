
void ERR_add_error_data(int num,...)

{
  undefined *puVar1;
  int iVar2;
  ERR_STATE *pEVar3;
  undefined4 in_a1;
  undefined4 in_a2;
  undefined4 in_a3;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar2 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_res4 = in_a1;
  local_res8 = in_a2;
  local_resc = in_a3;
  ERR_add_error_vdata(num,&local_res4);
  if (iVar2 == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pEVar3 = ERR_get_state();
  iVar2 = pEVar3->top;
  if (pEVar3->bottom != iVar2) {
    pEVar3->err_flags[iVar2] = pEVar3->err_flags[iVar2] | 1;
    return;
  }
  return;
}

