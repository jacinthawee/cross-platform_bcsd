
int pkey_rsa_keygen(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined auStack_28 [12];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puVar5 = *(undefined4 **)(param_1 + 0x14);
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (puVar5[1] == 0) {
    iVar2 = (*(code *)PTR_BN_new_006a71b4)();
    puVar5[1] = iVar2;
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_BN_set_word_006a7730)(iVar2,0x10001);
      if (iVar2 != 0) goto LAB_005fb344;
    }
  }
  else {
LAB_005fb344:
    iVar2 = (*(code *)PTR_RSA_new_006a787c)();
    if (iVar2 != 0) {
      if (*(int *)(param_1 + 0x1c) == 0) {
        puVar4 = (undefined *)0x0;
      }
      else {
        puVar4 = auStack_28;
        (*(code *)PTR_evp_pkey_set_cb_translate_006a9734)(puVar4,param_1);
      }
      iVar3 = (*(code *)PTR_RSA_generate_key_ex_006a7734)(iVar2,*puVar5,puVar5[1],puVar4);
      if (iVar3 < 1) {
        (*(code *)PTR_RSA_free_006a7600)(iVar2);
      }
      else {
        (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_2,6,iVar2);
      }
      goto LAB_005fb3bc;
    }
  }
  iVar3 = 0;
LAB_005fb3bc:
  if (local_1c == *(int *)puVar1) {
    return iVar3;
  }
  iVar2 = local_1c;
  iVar3 = (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = *(int *)(iVar2 + 0x14);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 4) != 0) {
      (*(code *)PTR_BN_free_006a701c)();
    }
    if (*(int *)(iVar2 + 0x20) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
                    /* WARNING: Could not recover jumptable at 0x005fb4ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
    return iVar2;
  }
  return iVar3;
}

