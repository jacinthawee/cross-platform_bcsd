
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_is_mem_check_on(void)

{
  int mode;
  uint uVar1;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_18;
  int local_10;
  
  uVar1 = 0;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  mode = 0;
  if (((byte)mh_mode & 1) != 0) {
    uVar1 = 1;
    CRYPTO_THREADID_current(&local_18);
    CRYPTO_lock(mode,5,&DAT_00000014,(int)"mem_dbg.c");
    if (((byte)mh_mode & 2) == 0) {
      mode = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&local_18);
      uVar1 = (uint)(mode != 0);
    }
    CRYPTO_lock(mode,6,&DAT_00000014,(int)"mem_dbg.c");
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

