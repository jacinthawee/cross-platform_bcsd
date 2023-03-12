
_LHASH * __regparm1 int_err_get(int param_1_00,int param_1)

{
  _LHASH *p_Var1;
  
  CRYPTO_lock(param_1_00,9,(char *)0x1,(int)"err.c");
  if ((param_1 != 0) && (int_error_hash == (_LHASH *)0x0)) {
    CRYPTO_push_info_("int_err_get (err.c)","err.c",0x165);
    int_error_hash = lh_new(err_string_data_LHASH_HASH,err_string_data_LHASH_COMP);
    param_1_00 = CRYPTO_pop_info();
  }
  p_Var1 = int_error_hash;
  CRYPTO_lock(param_1_00,10,(char *)0x1,(int)"err.c");
  return p_Var1;
}

