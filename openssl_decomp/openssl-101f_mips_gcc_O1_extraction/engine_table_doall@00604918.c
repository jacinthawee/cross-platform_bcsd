
void engine_table_doall(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_14 = param_2;
  local_10 = param_3;
  (*(code *)PTR_lh_doall_arg_006a94bc)(param_1,int_cb_LHASH_DOALL_ARG,&local_14);
  if (local_c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  while( true ) {
    iVar2 = (*(code *)PTR_sk_pop_006a9ec4)(initialized_engines);
    if (iVar2 == 0) break;
    (*(code *)PTR_ENGINE_finish_006a80c4)(iVar2);
  }
  (*(code *)PTR_sk_free_006a7f80)(initialized_engines);
  initialized_engines = 0;
  return;
}

