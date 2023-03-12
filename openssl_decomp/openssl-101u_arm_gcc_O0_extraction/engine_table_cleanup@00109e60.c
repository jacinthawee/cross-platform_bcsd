
void engine_table_cleanup(_LHASH **param_1)

{
  CRYPTO_lock(9,0x1e,"eng_table.c",0xe5);
  if (*param_1 != (_LHASH *)0x0) {
    lh_doall(*param_1,int_cleanup_cb_LHASH_DOALL + 1);
    lh_free(*param_1);
    *param_1 = (_LHASH *)0x0;
  }
  CRYPTO_lock(10,0x1e,"eng_table.c",0xec);
  return;
}

