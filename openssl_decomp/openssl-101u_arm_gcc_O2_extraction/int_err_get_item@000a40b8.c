
void * int_err_get_item(void *param_1)

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
    CRYPTO_lock(5,1,"err.c",0x189);
    pvVar1 = lh_retrieve(lh,param_1);
    CRYPTO_lock(6,1,"err.c",0x18b);
    return pvVar1;
  }
  return (void *)0x0;
}

