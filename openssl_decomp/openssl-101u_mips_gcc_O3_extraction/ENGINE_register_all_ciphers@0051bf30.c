
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_ciphers(void)

{
  undefined *puVar1;
  ENGINE *pEVar2;
  int iVar3;
  int iVar4;
  ENGINE *in_a0;
  undefined4 uStack_58;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pEVar2 = ENGINE_get_first();
  if (pEVar2 != (ENGINE *)0x0) {
    do {
      in_a0 = pEVar2;
      if ((*(code **)(in_a0 + 0x24) != (code *)0x0) &&
         (iVar3 = (**(code **)(in_a0 + 0x24))(in_a0,0,&local_20,0), 0 < iVar3)) {
        (*(code *)PTR_engine_table_register_006a8860)
                  (&cipher_table,engine_unregister_all_ciphers,in_a0,local_20);
      }
      pEVar2 = ENGINE_get_next(in_a0);
    } while (pEVar2 != (ENGINE *)0x0);
  }
  if (local_1c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    puVar1 = PTR___stack_chk_guard_006a9ae8;
    iVar3 = *(int *)PTR___stack_chk_guard_006a9ae8;
    if ((*(code **)(in_a0 + 0x24) != (code *)0x0) &&
       (iVar4 = (**(code **)(in_a0 + 0x24))(), 0 < iVar4)) {
      (*(code *)PTR_engine_table_register_006a8860)
                (&cipher_table,engine_unregister_all_ciphers,in_a0,uStack_58,iVar4,1);
    }
    if (iVar3 != *(int *)puVar1) {
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x0051c0ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_engine_table_select_006a8864)(&cipher_table,iVar3);
      return;
    }
    return;
  }
  return;
}

