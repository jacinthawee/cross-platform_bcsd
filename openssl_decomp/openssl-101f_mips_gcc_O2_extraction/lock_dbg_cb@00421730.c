
void lock_dbg_cb(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = param_1 & 0xc;
  if ((uVar1 == 4) || (uVar1 == 8)) {
    if (0x28 < param_2) {
      pcVar2 = "type out of bounds";
      goto LAB_00421764;
    }
    if ((param_1 & 1) != 0) {
      if (*(uint *)(modes_17428 + param_2 * 4) == 0) {
        *(uint *)(modes_17428 + param_2 * 4) = uVar1;
        return;
      }
      pcVar2 = "already locked";
      goto LAB_00421764;
    }
    if ((param_1 & 2) != 0) {
      iVar4 = param_2 * 4;
      uVar3 = *(uint *)(modes_17428 + iVar4);
      if (uVar3 == 0) {
        pcVar2 = "not locked";
      }
      else {
        if (uVar1 == uVar3) {
          *(uint *)(modes_17428 + iVar4) = 0;
          return;
        }
        if (uVar1 == 4) {
          pcVar2 = "CRYPTO_r_unlock on write lock";
          *(undefined4 *)(modes_17428 + iVar4) = 0;
        }
        else {
          pcVar2 = "CRYPTO_w_unlock on read lock";
          *(undefined4 *)(modes_17428 + iVar4) = 0;
        }
      }
      goto LAB_00421764;
    }
  }
  pcVar2 = "invalid mode";
LAB_00421764:
  (*(code *)PTR___fprintf_chk_006aaa8c)
            (*(undefined4 *)PTR_stderr_006aac00,1,
             "openssl (lock_dbg_cb): %s (mode=%d, type=%d) at %s:%d\n",pcVar2,param_1,param_2,
             param_3,param_4,&_gp);
  return;
}

