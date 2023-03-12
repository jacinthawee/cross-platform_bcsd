
/* WARNING: Restarted to delay deadcode elimination for space: ram */

_LHASH * int_err_get(int param_1)

{
  _LHASH *p_Var1;
  
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x162);
  if ((int_error_hash == (_LHASH *)0x0) && (param_1 != 0)) {
    (*(code *)PTR_CRYPTO_push_info__006a9a14)("int_err_get (err.c)","err.c",0x165);
    int_error_hash = lh_new(err_string_data_LHASH_HASH,err_string_data_LHASH_COMP);
    (*(code *)PTR_CRYPTO_pop_info_006a9a18)();
  }
  p_Var1 = int_error_hash;
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x16b);
  return p_Var1;
}

