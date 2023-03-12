
_LHASH * int_err_get(_LHASH *param_1)

{
  _LHASH *p_Var1;
  
  CRYPTO_lock(9,1,"err.c",0x162);
  p_Var1 = int_error_hash;
  if ((int_error_hash == (_LHASH *)0x0) && (p_Var1 = param_1, param_1 != (_LHASH *)0x0)) {
    CRYPTO_push_info_("int_err_get (err.c)","err.c",0x165);
    int_error_hash = lh_new(err_string_data_LHASH_HASH + 1,err_string_data_LHASH_COMP + 1);
    CRYPTO_pop_info();
    p_Var1 = int_error_hash;
  }
  CRYPTO_lock(10,1,"err.c",0x16b);
  return p_Var1;
}

