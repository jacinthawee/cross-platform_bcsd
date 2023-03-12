
_LHASH * __regparm1 int_thread_get(int param_1_00,int param_1)

{
  _LHASH *p_Var1;
  
  CRYPTO_lock(param_1_00,9,(char *)0x1,(int)"err.c");
  if ((param_1 != 0) && (int_thread_hash == (_LHASH *)0x0)) {
    CRYPTO_push_info_("int_thread_get (err.c)","err.c",0x1c1);
    int_thread_hash = lh_new(err_state_LHASH_HASH,err_state_LHASH_COMP);
    param_1_00 = CRYPTO_pop_info();
  }
  p_Var1 = int_thread_hash;
  if (int_thread_hash != (_LHASH *)0x0) {
    int_thread_hash_references = int_thread_hash_references + 1;
  }
  CRYPTO_lock(param_1_00,10,(char *)0x1,(int)"err.c");
  return p_Var1;
}

