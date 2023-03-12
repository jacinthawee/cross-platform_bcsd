
int pkey_dh_paramgen(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined auStack_28 [12];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar5 = *(undefined4 **)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x1c) == 0) {
    puVar4 = (undefined *)0x0;
    iVar2 = (*(code *)PTR_DH_new_006a751c)();
  }
  else {
    puVar4 = auStack_28;
    (*(code *)PTR_evp_pkey_set_cb_translate_006a9734)(puVar4,param_1);
    iVar2 = (*(code *)PTR_DH_new_006a751c)();
  }
  if (iVar2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*(code *)PTR_DH_generate_parameters_ex_006a7534)(iVar2,*puVar5,puVar5[1],puVar4);
    if (iVar3 == 0) {
      (*(code *)PTR_DH_free_006a7508)(iVar2);
      iVar3 = 0;
    }
    else {
      (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_2,0x1c,iVar2);
    }
  }
  if (local_1c != *(int *)puVar1) {
    iVar2 = local_1c;
    iVar3 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (*(int *)(iVar2 + 0x14) == 0) {
      return iVar3;
    }
                    /* WARNING: Could not recover jumptable at 0x0060026c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(code *)PTR_CRYPTO_free_006a6e88)();
    return iVar2;
  }
  return iVar3;
}

