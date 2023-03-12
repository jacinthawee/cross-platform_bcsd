
void * ERR_remove_state(void)

{
  undefined *puVar1;
  _LHASH *lh;
  void *pvVar2;
  undefined *data;
  undefined auStack_1ac [400];
  void *pvStack_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  data = auStack_1ac;
  pvStack_1c = *(void **)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(data);
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
  }
  (**(code **)((int)err_fns + 0x24))();
  if (pvStack_1c == *(void **)puVar1) {
    return *(void **)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,1,"err.c",0x12a);
  }
  lh = (_LHASH *)(**(code **)err_fns)(0);
  if (lh == (_LHASH *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    (*(code *)PTR_CRYPTO_lock_006a926c)(5,1,"err.c",0x185);
    pvVar2 = lh_retrieve(lh,data);
    (*(code *)PTR_CRYPTO_lock_006a926c)(6,1,"err.c",0x187);
  }
  return pvVar2;
}

