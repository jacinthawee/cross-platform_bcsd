
int ENGINE_set_default_ciphers(ENGINE *e)

{
  undefined *puVar1;
  int iVar2;
  undefined4 local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*(code **)(e + 0x24) != (code *)0x0) {
    iVar2 = (**(code **)(e + 0x24))(e,0,&local_18,0);
    if (0 < iVar2) {
      iVar2 = (*(code *)PTR_engine_table_register_006a9980)
                        (&cipher_table,engine_unregister_all_ciphers,e,local_18,iVar2,1);
      goto LAB_0051df58;
    }
  }
  iVar2 = 1;
LAB_0051df58:
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x0051dfcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_engine_table_select_006a9984)(&cipher_table,iVar2);
  return iVar2;
}

