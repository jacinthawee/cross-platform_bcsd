
void engine_table_cleanup(int *param_1)

{
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"eng_table.c",0xe3);
  if (*param_1 != 0) {
    (*(code *)PTR_lh_doall_006a95b0)(*param_1,int_cleanup_cb_LHASH_DOALL);
    (*(code *)PTR_lh_free_006a8518)(*param_1);
    *param_1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0060472c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"eng_table.c",0xeb);
  return;
}

