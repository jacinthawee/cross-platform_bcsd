
void int_cleanup(void)

{
  _LHASH *mode;
  
  if (ex_data == (_LHASH *)0x0) {
    mode = ex_data;
    CRYPTO_lock(0,9,(char *)0x2,(int)"ex_data.c");
    if ((ex_data == (_LHASH *)0x0) &&
       (mode = lh_new(ex_class_item_LHASH_HASH,ex_class_item_LHASH_COMP), ex_data = mode,
       mode == (_LHASH *)0x0)) {
      CRYPTO_lock(0,10,(char *)0x2,(int)"ex_data.c");
      return;
    }
    CRYPTO_lock((int)mode,10,(char *)0x2,(int)"ex_data.c");
  }
  lh_doall(ex_data,def_cleanup_cb);
  lh_free(ex_data);
  impl = 0;
  ex_data = (_LHASH *)0x0;
  return;
}

