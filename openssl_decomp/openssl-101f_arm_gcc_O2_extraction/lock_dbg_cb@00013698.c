
void lock_dbg_cb(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = param_1 & 0xc;
  if (uVar1 == 8 || uVar1 == 4) {
    if (0x28 < param_2) {
      pcVar2 = "type out of bounds";
      goto LAB_000136c2;
    }
    if ((param_1 & 1) != 0) {
      if (*(int *)(&modes_20067 + param_2 * 4) == 0) {
        *(uint *)(&modes_20067 + param_2 * 4) = uVar1;
        return;
      }
      pcVar2 = "already locked";
      goto LAB_000136c2;
    }
    if ((int)(param_1 << 0x1e) < 0) {
      if (*(uint *)(&modes_20067 + param_2 * 4) == 0) {
        pcVar2 = "not locked";
      }
      else {
        if (uVar1 == *(uint *)(&modes_20067 + param_2 * 4)) {
          *(undefined4 *)(&modes_20067 + param_2 * 4) = 0;
          return;
        }
        pcVar2 = "CRYPTO_w_unlock on read lock";
        *(undefined4 *)(&modes_20067 + param_2 * 4) = 0;
        if (uVar1 == 4) {
          pcVar2 = "CRYPTO_r_unlock on write lock";
        }
      }
      goto LAB_000136c2;
    }
  }
  pcVar2 = "invalid mode";
LAB_000136c2:
  __fprintf_chk(stderr,1,"openssl (lock_dbg_cb): %s (mode=%d, type=%d) at %s:%d\n",pcVar2,param_1,
                param_2,param_3,param_4);
  return;
}

