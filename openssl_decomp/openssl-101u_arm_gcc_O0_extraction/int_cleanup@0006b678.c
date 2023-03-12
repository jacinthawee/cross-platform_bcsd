
void int_cleanup(void)

{
  if (ex_data == (_LHASH *)0x0) {
    CRYPTO_lock(9,2,"ex_data.c",0x116);
    if (ex_data == (_LHASH *)0x0) {
      ex_data = lh_new(ex_class_item_LHASH_HASH + 1,ex_class_item_LHASH_COMP + 1);
      if (ex_data == (_LHASH *)0x0) {
        CRYPTO_lock(10,2,"ex_data.c",0x119);
        return;
      }
    }
    CRYPTO_lock(10,2,"ex_data.c",0x119);
  }
  lh_doall(ex_data,def_cleanup_cb + 1);
  lh_free(ex_data);
  ex_data = (_LHASH *)0x0;
  impl = 0;
  return;
}

