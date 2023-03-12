
_LHASH * int_thread_set_item(void *param_1)

{
  _LHASH *p_Var1;
  _LHASH *local_14;
  
  if (err_fns == (undefined1 *)0x0) {
    CRYPTO_lock(9,1,"err.c",0x127);
    if (err_fns == (undefined1 *)0x0) {
      err_fns = &err_defaults;
    }
    CRYPTO_lock(10,1,"err.c",0x12a);
  }
  p_Var1 = (_LHASH *)(**(code **)(err_fns + 0x14))(1);
  if (p_Var1 != (_LHASH *)0x0) {
    local_14 = p_Var1;
    CRYPTO_lock(9,1,"err.c",0x201);
    p_Var1 = (_LHASH *)lh_insert(local_14,param_1);
    CRYPTO_lock(10,1,"err.c",0x203);
    (**(code **)(err_fns + 0x18))(&local_14);
  }
  return p_Var1;
}

