
void __regparm1 engine_table_unregister(int param_1_00,_LHASH **param_1,void *param_2)

{
  _LHASH *lh;
  
  CRYPTO_lock(param_1_00,9,(char *)0x1e,(int)"eng_table.c");
  lh = *param_1;
  if (lh != (_LHASH *)0x0) {
    lh_doall_arg(lh,int_unregister_cb_LHASH_DOALL_ARG,param_2);
  }
  CRYPTO_lock((int)lh,10,(char *)0x1e,(int)"eng_table.c");
  return;
}

