
void engine_pkey_meths_free(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_24;
  int local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (*(code **)(param_1 + 0x2c) != (code *)0x0) {
    iVar2 = (**(code **)(param_1 + 0x2c))(param_1,0,&local_20,0);
    if (0 < iVar2) {
      iVar4 = 0;
      do {
        while( true ) {
          iVar3 = (**(code **)(param_1 + 0x2c))
                            (param_1,&local_24,0,*(undefined4 *)(local_20 + iVar4 * 4));
          if (iVar3 == 0) break;
          iVar4 = iVar4 + 1;
          (*(code *)PTR_EVP_PKEY_meth_free_006a8868)(local_24);
          if (iVar2 == iVar4) goto LAB_0051c920;
        }
        iVar4 = iVar4 + 1;
      } while (iVar2 != iVar4);
    }
  }
LAB_0051c920:
  if (local_1c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x0051c970. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_cleanup_006a8858)(&pkey_asn1_meth_table);
  return;
}

