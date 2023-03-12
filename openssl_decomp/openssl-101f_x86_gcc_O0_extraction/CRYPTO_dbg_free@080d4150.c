
void CRYPTO_dbg_free(void *addr,int before_p)

{
  void *ptr;
  void *ptr_00;
  void *ptr_01;
  void *ptr_02;
  int iVar1;
  void *ptr_03;
  void *mode;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_44 [4];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if (((before_p == 0) && (addr != (void *)0x0)) && ((mh_mode & 1) != 0)) {
    CRYPTO_THREADID_current(local_44);
    CRYPTO_lock(iVar1,5,&DAT_00000014,(int)"mem_dbg.c");
    if ((mh_mode & 2) == 0) {
      iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,local_44);
      CRYPTO_lock(iVar1,6,&DAT_00000014,(int)"mem_dbg.c");
      if (iVar1 == 0) goto LAB_080d417c;
    }
    else {
      CRYPTO_lock(iVar1,6,&DAT_00000014,(int)"mem_dbg.c");
    }
    if (mh != (_LHASH *)0x0) {
      CRYPTO_mem_ctrl_constprop_5();
      local_44[0].ptr = addr;
      ptr_03 = lh_delete(mh,local_44);
      mode = ptr_03;
      if (ptr_03 != (void *)0x0) {
        ptr = *(void **)((int)ptr_03 + 0x20);
        if (ptr != (void *)0x0) {
          mode = (void *)(*(int *)((int)ptr + 0x18) + -1);
          *(void **)((int)ptr + 0x18) = mode;
          if ((int)mode < 1) {
            ptr_00 = *(void **)((int)ptr + 0x14);
            if (ptr_00 != (void *)0x0) {
              mode = (void *)(*(int *)((int)ptr_00 + 0x18) + -1);
              *(void **)((int)ptr_00 + 0x18) = mode;
              if ((int)mode < 1) {
                ptr_01 = *(void **)((int)ptr_00 + 0x14);
                if (ptr_01 != (void *)0x0) {
                  mode = (void *)(*(int *)((int)ptr_01 + 0x18) + -1);
                  *(void **)((int)ptr_01 + 0x18) = mode;
                  if ((int)mode < 1) {
                    ptr_02 = *(void **)((int)ptr_01 + 0x14);
                    if (ptr_02 != (void *)0x0) {
                      mode = (void *)(*(int *)((int)ptr_02 + 0x18) + -1);
                      *(void **)((int)ptr_02 + 0x18) = mode;
                      if ((int)mode < 1) {
                        mode = *(void **)((int)ptr_02 + 0x14);
                        if (mode != (void *)0x0) {
                          mode = (void *)app_info_free();
                        }
                        CRYPTO_free(ptr_02);
                      }
                    }
                    CRYPTO_free(ptr_01);
                  }
                }
                CRYPTO_free(ptr_00);
              }
            }
            CRYPTO_free(ptr);
          }
        }
        CRYPTO_free(ptr_03);
      }
      CRYPTO_lock((int)mode,9,&DAT_00000014,(int)"mem_dbg.c");
      if ((((mh_mode & 1) != 0) && (mode = num_disable, num_disable != (void *)0x0)) &&
         (mode = (void *)((int)num_disable + -1), num_disable = mode, mode == (void *)0x0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(0,10,(char *)0x1b,(int)"mem_dbg.c");
      }
      CRYPTO_lock((int)mode,10,&DAT_00000014,(int)"mem_dbg.c");
    }
  }
LAB_080d417c:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

