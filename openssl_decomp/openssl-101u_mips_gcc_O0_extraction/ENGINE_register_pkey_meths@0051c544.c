
int ENGINE_register_pkey_meths(ENGINE *e)

{
  undefined *puVar1;
  int iVar2;
  ENGINE *pEVar3;
  int iVar4;
  ENGINE *e_00;
  ENGINE *unaff_s1;
  undefined4 uStack_90;
  undefined4 uStack_58;
  int iStack_54;
  undefined *puStack_50;
  ENGINE *pEStack_4c;
  undefined4 local_18;
  ENGINE *local_14;
  
  puStack_50 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(ENGINE **)PTR___stack_chk_guard_006a9ae8;
  if (*(code **)(e + 0x2c) == (code *)0x0) {
LAB_0051c590:
    iVar2 = 1;
    e = unaff_s1;
  }
  else {
    iVar2 = (**(code **)(e + 0x2c))(e,0,&local_18,0);
    unaff_s1 = e;
    if (iVar2 < 1) goto LAB_0051c590;
    iVar2 = (*(code *)PTR_engine_table_register_006a8860)
                      (&pkey_meth_table,engine_unregister_all_pkey_meths,e,local_18);
  }
  if (local_14 == *(ENGINE **)puStack_50) {
    return iVar2;
  }
  e_00 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_54 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pEStack_4c = e;
  pEVar3 = ENGINE_get_first();
  if (pEVar3 != (ENGINE *)0x0) {
    do {
      e_00 = pEVar3;
      if (*(code **)(e_00 + 0x2c) != (code *)0x0) {
        iVar2 = (**(code **)(e_00 + 0x2c))(e_00,0,&uStack_58,0);
        if (0 < iVar2) {
          (*(code *)PTR_engine_table_register_006a8860)
                    (&pkey_meth_table,engine_unregister_all_pkey_meths,e_00,uStack_58);
        }
      }
      pEVar3 = ENGINE_get_next(e_00);
    } while (pEVar3 != (ENGINE *)0x0);
  }
  if (iStack_54 == *(int *)puVar1) {
    return *(int *)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar2 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (*(code **)(e_00 + 0x2c) != (code *)0x0) {
    iVar4 = (**(code **)(e_00 + 0x2c))();
    if (0 < iVar4) {
      iVar4 = (*(code *)PTR_engine_table_register_006a8860)
                        (&pkey_meth_table,engine_unregister_all_pkey_meths,e_00,uStack_90,iVar4,1);
      goto LAB_0051c738;
    }
  }
  iVar4 = 1;
LAB_0051c738:
  if (iVar2 == *(int *)puVar1) {
    return iVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x0051c7ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_engine_table_select_006a8864)(&pkey_meth_table,iVar2);
  return iVar2;
}

