
undefined4 policy_cache_find_data(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined auStack_24 [4];
  undefined4 local_20;
  uint *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  local_20 = param_2;
  iVar2 = (*(code *)PTR_sk_find_006a8044)(*(undefined4 *)(param_1 + 4),auStack_24);
  if (iVar2 == -1) {
    uVar3 = 0;
  }
  else {
    uVar3 = (*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(param_1 + 4),iVar2);
  }
  if (local_14 == *(uint **)puVar1) {
    return uVar3;
  }
  puVar4 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(puVar4[1]);
  if ((*puVar4 & 4) == 0) {
    (*(code *)PTR_sk_pop_free_006a7058)(puVar4[2],PTR_POLICYQUALINFO_free_006a90ac);
  }
  (*(code *)PTR_sk_pop_free_006a7058)(puVar4[3],PTR_ASN1_OBJECT_free_006a7004);
                    /* WARNING: Could not recover jumptable at 0x00598e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
  return uVar3;
}

