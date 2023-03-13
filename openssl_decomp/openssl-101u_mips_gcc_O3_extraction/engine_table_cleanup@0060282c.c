
void engine_table_cleanup(int *param_1)

{
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_table.c",0xe5);
  if (*param_1 != 0) {
    (*(code *)PTR_lh_doall_006a8490)(*param_1,int_cleanup_cb_LHASH_DOALL);
    (*(code *)PTR_lh_free_006a7418)(*param_1);
    *param_1 = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x006028bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_table.c",0xec);
  return;
}

