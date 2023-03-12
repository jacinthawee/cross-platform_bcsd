
bool ssleay_rand_status(void)

{
  double dVar1;
  undefined *puVar2;
  double dVar3;
  bool bVar5;
  int iVar4;
  undefined *puVar6;
  undefined auStack_2c [8];
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar6 = (undefined *)0x680000;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_CRYPTO_THREADID_current_006a848c)(auStack_2c);
  if (crypto_lock_rand != 0) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(5,0x13,"md_rand.c",0x22f);
    iVar4 = (*(code *)PTR_CRYPTO_THREADID_cmp_006a8480)(&locking_threadid,auStack_2c);
    (*(code *)PTR_CRYPTO_lock_006a8144)(6,0x13,"md_rand.c",0x231);
    if (iVar4 == 0) {
      puVar6 = &_gp_1;
      if (initialized == 0) goto LAB_006034f8;
      bVar5 = DAT_006794e0 <= entropy;
      goto LAB_00603434;
    }
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x12,"md_rand.c",0x236);
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x13,"md_rand.c",0x23b);
  (*(code *)PTR_CRYPTO_THREADID_cpy_006a8488)(&locking_threadid,auStack_2c);
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x13,"md_rand.c",0x23d);
  crypto_lock_rand = 1;
  if (initialized == 0) {
    RAND_poll();
    initialized = 1;
    bVar5 = DAT_006794e0 <= entropy;
  }
  else {
    bVar5 = true;
    if (entropy < DAT_006794e0) {
      bVar5 = false;
    }
  }
  crypto_lock_rand = 0;
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x12,"md_rand.c",0x24c);
LAB_00603434:
  while (local_24 != *(int *)puVar2) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_006034f8:
    RAND_poll();
    dVar3 = entropy;
    dVar1 = DAT_006794e0;
    *(undefined4 *)(puVar6 + -0x1bd0) = 1;
    bVar5 = dVar1 <= dVar3;
  }
  return bVar5;
}

