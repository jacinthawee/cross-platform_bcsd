
void __regparm1 engine_table_cleanup(int param_1_00,_LHASH **param_1)

{
  _LHASH *lh;
  
  CRYPTO_lock(param_1_00,9,(char *)0x1e,(int)"eng_table.c");
  lh = *param_1;
  if (lh != (_LHASH *)0x0) {
    lh_doall(lh,int_cleanup_cb_LHASH_DOALL);
    lh_free(*param_1);
    *param_1 = (_LHASH *)0x0;
  }
  CRYPTO_lock((int)lh,10,(char *)0x1e,(int)"eng_table.c");
  return;
}

