
void engine_table_unregister(int *param_1,undefined4 param_2)

{
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_table.c",0xd0);
  if (*param_1 != 0) {
    (*(code *)PTR_lh_doall_arg_006a94bc)(*param_1,int_unregister_cb_LHASH_DOALL_ARG,param_2);
  }
                    /* WARNING: Could not recover jumptable at 0x00604694. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_table.c",0xd5);
  return;
}

