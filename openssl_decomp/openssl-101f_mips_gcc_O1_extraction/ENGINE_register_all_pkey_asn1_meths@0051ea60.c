
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ENGINE_register_all_pkey_asn1_meths(void)

{
  undefined *puVar1;
  ENGINE *pEVar2;
  int iVar3;
  int iVar4;
  ENGINE *in_a0;
  undefined4 uStack_58;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  pEVar2 = ENGINE_get_first();
  if (pEVar2 != (ENGINE *)0x0) {
    do {
      in_a0 = pEVar2;
      if ((*(code **)(in_a0 + 0x30) != (code *)0x0) &&
         (iVar3 = (**(code **)(in_a0 + 0x30))(in_a0,0,&local_20,0), 0 < iVar3)) {
        (*(code *)PTR_engine_table_register_006a9980)
                  (&pkey_asn1_meth_table,engine_unregister_all_pkey_asn1_meths,in_a0,local_20);
      }
      pEVar2 = ENGINE_get_next(in_a0);
    } while (pEVar2 != (ENGINE *)0x0);
  }
  if (local_1c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    puVar1 = PTR___stack_chk_guard_006aabf0;
    iVar3 = *(int *)PTR___stack_chk_guard_006aabf0;
    if ((*(code **)(in_a0 + 0x30) != (code *)0x0) &&
       (iVar4 = (**(code **)(in_a0 + 0x30))(), 0 < iVar4)) {
      (*(code *)PTR_engine_table_register_006a9980)
                (&pkey_asn1_meth_table,engine_unregister_all_pkey_asn1_meths,in_a0,uStack_58,iVar4,1
                );
    }
    if (iVar3 != *(int *)puVar1) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x0051ec1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_engine_table_select_006a9984)(&pkey_asn1_meth_table,iVar3);
      return;
    }
    return;
  }
  return;
}

