
void __regparm3 int_err_del(int param_1)

{
  _LHASH *mode;
  
  CRYPTO_lock(param_1,9,(char *)0x1,(int)"err.c");
  mode = int_error_hash;
  if (int_error_hash != (_LHASH *)0x0) {
    lh_free(int_error_hash);
    int_error_hash = (_LHASH *)0x0;
  }
  CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
  return;
}

