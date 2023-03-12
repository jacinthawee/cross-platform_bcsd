
int ENGINE_register_ciphers(ENGINE *e)

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
  
  puStack_50 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(ENGINE **)PTR___stack_chk_guard_006aabf0;
  if (*(code **)(e + 0x24) == (code *)0x0) {
LAB_0051ddb0:
    iVar2 = 1;
    e = unaff_s1;
  }
  else {
    iVar2 = (**(code **)(e + 0x24))(e,0,&local_18,0);
    unaff_s1 = e;
    if (iVar2 < 1) goto LAB_0051ddb0;
    iVar2 = (*(code *)PTR_engine_table_register_006a9980)
                      (&cipher_table,engine_unregister_all_ciphers,e,local_18);
  }
  if (local_14 == *(ENGINE **)puStack_50) {
    return iVar2;
  }
  e_00 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_54 = *(int *)PTR___stack_chk_guard_006aabf0;
  pEStack_4c = e;
  pEVar3 = ENGINE_get_first();
  if (pEVar3 != (ENGINE *)0x0) {
    do {
      e_00 = pEVar3;
      if (*(code **)(e_00 + 0x24) != (code *)0x0) {
        iVar2 = (**(code **)(e_00 + 0x24))(e_00,0,&uStack_58,0);
        if (0 < iVar2) {
          (*(code *)PTR_engine_table_register_006a9980)
                    (&cipher_table,engine_unregister_all_ciphers,e_00,uStack_58);
        }
      }
      pEVar3 = ENGINE_get_next(e_00);
    } while (pEVar3 != (ENGINE *)0x0);
  }
  if (iStack_54 == *(int *)puVar1) {
    return *(int *)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar2 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (*(code **)(e_00 + 0x24) != (code *)0x0) {
    iVar4 = (**(code **)(e_00 + 0x24))();
    if (0 < iVar4) {
      iVar4 = (*(code *)PTR_engine_table_register_006a9980)
                        (&cipher_table,engine_unregister_all_ciphers,e_00,uStack_90,iVar4,1);
      goto LAB_0051df58;
    }
  }
  iVar4 = 1;
LAB_0051df58:
  if (iVar2 == *(int *)puVar1) {
    return iVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x0051dfcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_engine_table_select_006a9984)(&cipher_table,iVar2);
  return iVar2;
}

