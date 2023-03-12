
/* WARNING: Restarted to delay deadcode elimination for space: ram */

_LHASH * int_thread_get(int param_1)

{
  _LHASH *p_Var1;
  
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x1c4);
  p_Var1 = int_thread_hash;
  if (int_thread_hash == (_LHASH *)0x0) {
    if (param_1 == 0) goto LAB_0052dafc;
    (*(code *)PTR_CRYPTO_push_info__006a88f4)("int_thread_get (err.c)","err.c",0x1c6);
    int_thread_hash = lh_new(err_state_LHASH_HASH,err_state_LHASH_COMP);
    (*(code *)PTR_CRYPTO_pop_info_006a88f8)();
    if (int_thread_hash == (_LHASH *)0x0) goto LAB_0052dafc;
  }
  int_thread_hash_references = int_thread_hash_references + 1;
  p_Var1 = int_thread_hash;
LAB_0052dafc:
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x1ce);
  return p_Var1;
}

