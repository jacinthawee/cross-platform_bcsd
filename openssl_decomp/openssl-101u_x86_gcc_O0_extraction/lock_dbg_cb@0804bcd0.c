
void lock_dbg_cb(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = param_1 & 0xc;
  if ((uVar1 - 4 & 0xfffffff8) == 0) {
    if (0x28 < param_2) {
      pcVar2 = "type out of bounds";
      goto LAB_0804bcfd;
    }
    if ((param_1 & 1) != 0) {
      if (*(int *)(modes_17465 + param_2 * 4) == 0) {
        *(uint *)(modes_17465 + param_2 * 4) = uVar1;
        return;
      }
      pcVar2 = "already locked";
      goto LAB_0804bcfd;
    }
    if ((param_1 & 2) != 0) {
      if (*(uint *)(modes_17465 + param_2 * 4) == 0) {
        pcVar2 = "not locked";
      }
      else {
        if (uVar1 == *(uint *)(modes_17465 + param_2 * 4)) {
          *(undefined4 *)(modes_17465 + param_2 * 4) = 0;
          return;
        }
        pcVar2 = "CRYPTO_r_unlock on write lock";
        if (uVar1 != 4) {
          pcVar2 = "CRYPTO_w_unlock on read lock";
        }
        *(undefined4 *)(modes_17465 + param_2 * 4) = 0;
      }
      goto LAB_0804bcfd;
    }
  }
  pcVar2 = "invalid mode";
LAB_0804bcfd:
  __fprintf_chk(stderr,1,"openssl (lock_dbg_cb): %s (mode=%d, type=%d) at %s:%d\n",pcVar2,param_1,
                param_2,param_3,param_4);
  return;
}

