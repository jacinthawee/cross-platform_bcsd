
void * int_err_set_item(void *param_1)

{
  _LHASH *lh;
  void *mode;
  code **mode_00;
  
  if ((code **)err_fns == (code **)0x0) {
    mode_00 = (code **)err_fns;
    CRYPTO_lock(0,9,(char *)0x1,(int)"err.c");
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    CRYPTO_lock((int)mode_00,10,(char *)0x1,(int)"err.c");
  }
  lh = (_LHASH *)(**(code **)err_fns)(1);
  if (lh == (_LHASH *)0x0) {
    mode = (void *)0x0;
  }
  else {
    CRYPTO_lock((int)lh,9,(char *)0x1,(int)"err.c");
    mode = lh_insert(lh,param_1);
    CRYPTO_lock((int)mode,10,(char *)0x1,(int)"err.c");
  }
  return mode;
}

