
void * int_err_del_item(void *param_1)

{
  _LHASH *lh;
  void *pvVar1;
  
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  }
  lh = (_LHASH *)(**(code **)err_fns)(0);
  if (lh == (_LHASH *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x1ab);
    pvVar1 = lh_delete(lh,param_1);
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x1ad);
  }
  return pvVar1;
}

