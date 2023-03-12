
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool ssleay_rand_status(void)

{
  bool bVar1;
  int mode;
  int mode_00;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_18;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  mode = 0;
  CRYPTO_THREADID_current(&local_18);
  if (crypto_lock_rand != 0) {
    CRYPTO_lock(mode,5,(char *)0x13,(int)"md_rand.c");
    mode_00 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&locking_threadid,&local_18);
    mode = mode_00;
    CRYPTO_lock(mode_00,6,(char *)0x13,(int)"md_rand.c");
    if (mode_00 == 0) {
      if (initialized == 0) {
        RAND_poll();
        initialized = 1;
      }
      bVar1 = _DAT_0823ab48 <= (float)entropy;
      goto LAB_081c83b3;
    }
  }
  CRYPTO_lock(mode,9,(char *)0x12,(int)"md_rand.c");
  CRYPTO_lock(mode,9,(char *)0x13,(int)"md_rand.c");
  CRYPTO_THREADID_cpy((CRYPTO_THREADID *)&locking_threadid,&local_18);
  CRYPTO_lock(mode,10,(char *)0x13,(int)"md_rand.c");
  crypto_lock_rand = 1;
  if (initialized == 0) {
    mode = RAND_poll();
    initialized = 1;
  }
  crypto_lock_rand = 0;
  bVar1 = _DAT_0823ab48 <= (float)entropy;
  CRYPTO_lock(mode,10,(char *)0x12,(int)"md_rand.c");
LAB_081c83b3:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

