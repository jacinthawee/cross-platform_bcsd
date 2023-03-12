
uint CRYPTO_mem_ctrl_constprop_5(void)

{
  uint uVar1;
  int iVar2;
  int mode;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_18;
  int local_10;
  
  uVar1 = mh_mode;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  mode = 0;
  CRYPTO_lock(0,9,&DAT_00000014,(int)"mem_dbg.c");
  if ((mh_mode & 1) != 0) {
    CRYPTO_THREADID_current(&local_18);
    if ((num_disable == 0) ||
       (mode = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&local_18), mode != 0)) {
      CRYPTO_lock(mode,10,&DAT_00000014,(int)"mem_dbg.c");
      CRYPTO_lock(mode,9,(char *)0x1b,(int)"mem_dbg.c");
      iVar2 = 9;
      CRYPTO_lock(mode,9,&DAT_00000014,(int)"mem_dbg.c");
      mode = iVar2;
      mh_mode = mh_mode & 0xfffffffd;
      CRYPTO_THREADID_cpy((CRYPTO_THREADID *)&disabling_threadid,&local_18);
    }
    num_disable = num_disable + 1;
  }
  CRYPTO_lock(mode,10,&DAT_00000014,(int)"mem_dbg.c");
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}

