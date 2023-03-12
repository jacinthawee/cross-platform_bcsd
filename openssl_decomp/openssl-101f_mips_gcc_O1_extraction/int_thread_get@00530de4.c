
/* WARNING: Restarted to delay deadcode elimination for space: ram */

_LHASH * int_thread_get(int param_1)

{
  _LHASH *p_Var1;
  
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x1be);
  p_Var1 = int_thread_hash;
  if (int_thread_hash == (_LHASH *)0x0) {
    if (param_1 == 0) goto LAB_00530e4c;
    (*(code *)PTR_CRYPTO_push_info__006a9a14)("int_thread_get (err.c)","err.c",0x1c1);
    int_thread_hash = lh_new(err_state_LHASH_HASH,err_state_LHASH_COMP);
    (*(code *)PTR_CRYPTO_pop_info_006a9a18)();
    if (int_thread_hash == (_LHASH *)0x0) goto LAB_00530e4c;
  }
  int_thread_hash_references = int_thread_hash_references + 1;
  p_Var1 = int_thread_hash;
LAB_00530e4c:
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x1ca);
  return p_Var1;
}

