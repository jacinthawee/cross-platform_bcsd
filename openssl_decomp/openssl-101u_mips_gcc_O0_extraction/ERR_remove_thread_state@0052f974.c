
void ERR_remove_thread_state(CRYPTO_THREADID *tid)

{
  undefined *puVar1;
  _LHASH *lh;
  undefined *data;
  undefined4 unaff_s3;
  undefined auStack_374 [400];
  int iStack_1e4;
  undefined *puStack_1dc;
  undefined *puStack_1d8;
  undefined *puStack_1d4;
  undefined4 uStack_1d0;
  code *pcStack_1cc;
  undefined *local_1b8;
  undefined auStack_1ac [400];
  int local_1c;
  
  puStack_1dc = PTR___stack_chk_guard_006a9ae8;
  local_1b8 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (tid == (CRYPTO_THREADID *)0x0) {
    (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(auStack_1ac);
  }
  else {
    (*(code *)PTR_CRYPTO_THREADID_cpy_006a8488)(auStack_1ac,tid);
  }
  if ((code **)err_fns == (code **)0x0) {
    unaff_s3 = 0x660000;
    (**(code **)(local_1b8 + -0x6c9c))(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (**(code **)(local_1b8 + -0x6c9c))(10,1,"err.c",0x12a);
  }
  puStack_1d8 = auStack_1ac;
  (**(code **)((int)err_fns + 0x24))(puStack_1d8);
  if (local_1c == *(int *)puStack_1dc) {
    return;
  }
  pcStack_1cc = ERR_remove_state;
  (**(code **)(local_1b8 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_1d4 = &_gp_1;
  data = auStack_374;
  iStack_1e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_1d0 = unaff_s3;
  (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(data);
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  }
  (**(code **)((int)err_fns + 0x24))();
  if (iStack_1e4 == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((code **)err_fns == (code **)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,1,"err.c",0x127);
    if ((code **)err_fns == (code **)0x0) {
      err_fns = err_defaults;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,1,"err.c",0x12a);
  }
  lh = (_LHASH *)(**(code **)err_fns)(0);
  if (lh != (_LHASH *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(5,1,"err.c",0x189);
    lh_retrieve(lh,data);
    (*(code *)PTR_CRYPTO_lock_006a8144)(6,1,"err.c",0x18b);
  }
  return;
}

