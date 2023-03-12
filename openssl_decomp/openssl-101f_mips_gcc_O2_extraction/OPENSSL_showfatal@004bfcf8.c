
int OPENSSL_showfatal(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar2 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  (*(code *)PTR___vfprintf_chk_006aac1c)(*(undefined4 *)PTR_stderr_006aac00,1,param_1,&local_res4);
  if (iVar2 == *(int *)puVar1) {
    return *(int *)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return 0;
}

