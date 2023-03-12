
_LHASH * int_thread_get(int param_1)

{
  _LHASH *p_Var1;
  
  CRYPTO_lock(9,1,"err.c",0x1c4);
  if (int_thread_hash == (_LHASH *)0x0) {
    if (param_1 == 0) goto LAB_000a3ee6;
    CRYPTO_push_info_("int_thread_get (err.c)","err.c",0x1c6);
    int_thread_hash = lh_new(err_state_LHASH_HASH + 1,err_state_LHASH_COMP + 1);
    CRYPTO_pop_info();
    if (int_thread_hash == (_LHASH *)0x0) goto LAB_000a3ee6;
  }
  int_thread_hash_references = int_thread_hash_references + 1;
LAB_000a3ee6:
  p_Var1 = int_thread_hash;
  CRYPTO_lock(10,1,"err.c",0x1ce);
  return p_Var1;
}

