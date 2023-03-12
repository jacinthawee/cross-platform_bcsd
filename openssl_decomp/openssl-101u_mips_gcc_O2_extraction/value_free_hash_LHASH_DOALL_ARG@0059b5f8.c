
void value_free_hash_LHASH_DOALL_ARG(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0059b614. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_lh_delete_006a8390)(param_2,param_1);
    return;
  }
  return;
}

