
void * int_err_del_item(void *param_1)

{
  _LHASH *lh;
  void *pvVar1;
  
  if (err_fns == (code **)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (code **)0x0) {
      err_fns = (code **)&err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  lh = (_LHASH *)(**err_fns)(0);
  if (lh != (_LHASH *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x1a7);
    pvVar1 = lh_delete(lh,param_1);
    CRYPTO_lock(10,1,"err.c",0x1a9);
    return pvVar1;
  }
  return (void *)0x0;
}

