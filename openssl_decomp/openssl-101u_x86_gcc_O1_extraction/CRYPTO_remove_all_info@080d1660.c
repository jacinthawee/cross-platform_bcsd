
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_remove_all_info(void)

{
  void *data;
  int iVar1;
  _LHASH *ptr;
  uint uVar2;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_3c [3];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if ((mh_mode & 1) == 0) {
LAB_080d167c:
    iVar1 = 0;
LAB_080d167e:
    if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
      return iVar1;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  CRYPTO_THREADID_current(local_3c);
  CRYPTO_lock(iVar1,5,&DAT_00000014,(int)"mem_dbg.c");
  if ((mh_mode & 2) == 0) {
    iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,local_3c);
    CRYPTO_lock(iVar1,6,&DAT_00000014,(int)"mem_dbg.c");
    if (iVar1 == 0) goto LAB_080d167c;
  }
  else {
    CRYPTO_lock(iVar1,6,&DAT_00000014,(int)"mem_dbg.c");
  }
  ptr = (_LHASH *)CRYPTO_mem_ctrl_constprop_5();
  iVar1 = 0;
joined_r0x080d16f5:
  if (amih != (_LHASH *)0x0) {
    do {
      CRYPTO_THREADID_current(local_3c);
      ptr = (_LHASH *)lh_delete(amih,local_3c);
      if (ptr == (_LHASH *)0x0) break;
      data = (void *)ptr->p;
      if (data == (void *)0x0) {
        uVar2 = ptr->pmax - 1;
        ptr->pmax = uVar2;
        if (0 < (int)uVar2) goto LAB_080d1700;
        ptr->p = 0;
      }
      else {
        *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + 1;
        lh_insert(amih,data);
        uVar2 = ptr->pmax - 1;
        ptr->pmax = uVar2;
        if (0 < (int)uVar2) goto LAB_080d1700;
        ptr->p = 0;
        *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + -1;
      }
      iVar1 = iVar1 + 1;
      CRYPTO_free(ptr);
      ptr = amih;
      if (amih == (_LHASH *)0x0) break;
    } while( true );
  }
  CRYPTO_lock((int)ptr,9,&DAT_00000014,(int)"mem_dbg.c");
  uVar2 = mh_mode;
  if ((((mh_mode & 1) != 0) && (num_disable != 0)) &&
     (num_disable = num_disable + -1, num_disable == 0)) {
    uVar2 = mh_mode | 2;
    mh_mode = uVar2;
    CRYPTO_lock(uVar2,10,(char *)0x1b,(int)"mem_dbg.c");
  }
  CRYPTO_lock(uVar2,10,&DAT_00000014,(int)"mem_dbg.c");
  goto LAB_080d167e;
LAB_080d1700:
  iVar1 = iVar1 + 1;
  ptr = amih;
  goto joined_r0x080d16f5;
}

