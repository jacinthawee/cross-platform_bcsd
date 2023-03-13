
int ENGINE_set_default_pkey_meths(ENGINE *e)

{
  undefined *puVar1;
  int iVar2;
  undefined4 local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (*(code **)(e + 0x2c) != (code *)0x0) {
    iVar2 = (**(code **)(e + 0x2c))(e,0,&local_18,0);
    if (0 < iVar2) {
      iVar2 = (*(code *)PTR_engine_table_register_006a8860)
                        (&pkey_meth_table,engine_unregister_all_pkey_meths,e,local_18,iVar2,1);
      goto LAB_0051c738;
    }
  }
  iVar2 = 1;
LAB_0051c738:
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x0051c7ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_engine_table_select_006a8864)(&pkey_meth_table,iVar2);
  return iVar2;
}

