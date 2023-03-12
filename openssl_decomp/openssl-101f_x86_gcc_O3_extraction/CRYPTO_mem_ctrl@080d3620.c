
int CRYPTO_mem_ctrl(int mode)

{
  uint uVar1;
  int iVar2;
  int mode_00;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_18;
  int local_10;
  
  uVar1 = mh_mode;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  mode_00 = 0;
  CRYPTO_lock(0,9,&DAT_00000014,(int)"mem_dbg.c");
  if (mode == 1) {
    mh_mode = 3;
    num_disable = 0;
  }
  else if (mode < 2) {
    if (mode == 0) {
      mh_mode = 0;
      num_disable = 0;
    }
  }
  else if (mode == 2) {
    if ((((mh_mode & 1) != 0) && (mode_00 = num_disable, num_disable != 0)) &&
       (mode_00 = num_disable + -1, num_disable = mode_00, mode_00 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(0,10,(char *)0x1b,(int)"mem_dbg.c");
    }
  }
  else if ((mode == 3) && ((mh_mode & 1) != 0)) {
    CRYPTO_THREADID_current(&local_18);
    if ((num_disable == 0) ||
       (mode_00 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&local_18),
       mode_00 != 0)) {
      CRYPTO_lock(mode_00,10,&DAT_00000014,(int)"mem_dbg.c");
      CRYPTO_lock(mode_00,9,(char *)0x1b,(int)"mem_dbg.c");
      iVar2 = 9;
      CRYPTO_lock(mode_00,9,&DAT_00000014,(int)"mem_dbg.c");
      mode_00 = iVar2;
      mh_mode = mh_mode & 0xfffffffd;
      CRYPTO_THREADID_cpy((CRYPTO_THREADID *)&disabling_threadid,&local_18);
    }
    num_disable = num_disable + 1;
  }
  CRYPTO_lock(mode_00,10,&DAT_00000014,(int)"mem_dbg.c");
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}

