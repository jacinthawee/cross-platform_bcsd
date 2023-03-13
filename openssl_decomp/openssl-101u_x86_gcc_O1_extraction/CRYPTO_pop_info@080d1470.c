
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_pop_info(void)

{
  void *data;
  int iVar1;
  void *mode;
  void *ptr;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_2c [3];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if ((mh_mode & 1) == 0) {
LAB_080d148a:
    iVar1 = 0;
    goto LAB_080d148c;
  }
  CRYPTO_THREADID_current(local_2c);
  CRYPTO_lock(iVar1,5,&DAT_00000014,(int)"mem_dbg.c");
  if ((mh_mode & 2) == 0) {
    iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,local_2c);
    CRYPTO_lock(iVar1,6,&DAT_00000014,(int)"mem_dbg.c");
    if (iVar1 == 0) goto LAB_080d148a;
  }
  else {
    CRYPTO_lock(iVar1,6,&DAT_00000014,(int)"mem_dbg.c");
  }
  mode = (void *)CRYPTO_mem_ctrl_constprop_5();
  if (amih == (_LHASH *)0x0) {
LAB_080d1648:
    iVar1 = 0;
  }
  else {
    CRYPTO_THREADID_current(local_2c);
    ptr = lh_delete(amih,local_2c);
    mode = ptr;
    if (ptr == (void *)0x0) goto LAB_080d1648;
    data = *(void **)((int)ptr + 0x14);
    if (data == (void *)0x0) {
      mode = (void *)(*(int *)((int)ptr + 0x18) + -1);
      *(void **)((int)ptr + 0x18) = mode;
      if ((int)mode < 1) {
        *(undefined4 *)((int)ptr + 0x14) = 0;
        goto LAB_080d15db;
      }
    }
    else {
      *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + 1;
      lh_insert(amih,data);
      mode = (void *)(*(int *)((int)ptr + 0x18) + -1);
      *(void **)((int)ptr + 0x18) = mode;
      if ((int)mode < 1) {
        *(undefined4 *)((int)ptr + 0x14) = 0;
        *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + -1;
LAB_080d15db:
        CRYPTO_free(ptr);
      }
    }
    iVar1 = 1;
  }
  CRYPTO_lock((int)mode,9,&DAT_00000014,(int)"mem_dbg.c");
  if ((((mh_mode & 1) != 0) && (mode = num_disable, num_disable != (void *)0x0)) &&
     (mode = (void *)((int)num_disable + -1), num_disable = mode, mode == (void *)0x0)) {
    mh_mode = mh_mode | 2;
    CRYPTO_lock(0,10,(char *)0x1b,(int)"mem_dbg.c");
  }
  CRYPTO_lock((int)mode,10,&DAT_00000014,(int)"mem_dbg.c");
LAB_080d148c:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

