
bool ssleay_rand_status(void)

{
  double dVar1;
  undefined *puVar2;
  double dVar3;
  bool bVar5;
  int iVar4;
  undefined1 *puVar6;
  undefined auStack_2c [8];
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  puVar6 = (undefined1 *)0x680000;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_CRYPTO_THREADID_current_006a95ac)(auStack_2c);
  if (crypto_lock_rand != 0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(5,0x13,"md_rand.c",0x239);
    iVar4 = (*(code *)PTR_CRYPTO_THREADID_cmp_006a95a0)(&locking_threadid,auStack_2c);
    (*(code *)PTR_CRYPTO_lock_006a926c)(6,0x13,"md_rand.c",0x23b);
    if (iVar4 == 0) {
      puVar6 = &_ITM_registerTMCloneTable;
      if (initialized == 0) goto LAB_00605368;
      bVar5 = DAT_00679d90 <= entropy;
      goto LAB_006052a4;
    }
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x12,"md_rand.c",0x242);
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x13,"md_rand.c",0x245);
  (*(code *)PTR_CRYPTO_THREADID_cpy_006a95a8)(&locking_threadid,auStack_2c);
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x13,"md_rand.c",0x247);
  crypto_lock_rand = 1;
  if (initialized == 0) {
    RAND_poll();
    initialized = 1;
    bVar5 = DAT_00679d90 <= entropy;
  }
  else {
    bVar5 = true;
    if (entropy < DAT_00679d90) {
      bVar5 = false;
    }
  }
  crypto_lock_rand = 0;
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x12,"md_rand.c",600);
LAB_006052a4:
  while (local_24 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00605368:
    RAND_poll();
    dVar3 = entropy;
    dVar1 = DAT_00679d90;
    *(undefined4 *)(puVar6 + -0xa00) = 1;
    bVar5 = dVar1 <= dVar3;
  }
  return bVar5;
}

