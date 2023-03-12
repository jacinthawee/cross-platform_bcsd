
void CRYPTO_dbg_realloc(void *addr1,void *addr2,int num,char *file,int line,int before_p)

{
  void **data;
  int mode;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_44 [4];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((before_p == 1) && (addr2 != (void *)0x0)) {
    if (addr1 == (void *)0x0) {
      CRYPTO_dbg_malloc(addr2,num,file,line,0x81);
    }
    else if ((mh_mode & 1) != 0) {
      CRYPTO_THREADID_current(local_44);
      CRYPTO_lock((int)file,5,&DAT_00000014,(int)"mem_dbg.c");
      if ((mh_mode & 2) == 0) {
        mode = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,local_44);
        CRYPTO_lock(mode,6,&DAT_00000014,(int)"mem_dbg.c");
        if (mode == 0) goto LAB_080d43bc;
      }
      else {
        CRYPTO_lock((int)file,6,&DAT_00000014,(int)"mem_dbg.c");
      }
      CRYPTO_mem_ctrl_constprop_5();
      local_44[0].ptr = addr1;
      data = (void **)lh_delete(mh,local_44);
      if (data != (void **)0x0) {
        *data = addr2;
        data[1] = (void *)num;
        data = (void **)lh_insert(mh,data);
      }
      CRYPTO_lock((int)data,9,&DAT_00000014,(int)"mem_dbg.c");
      if ((((mh_mode & 1) != 0) && (data = num_disable, num_disable != (void **)0x0)) &&
         (data = (void **)((int)num_disable + -1), num_disable = data, data == (void **)0x0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(0,10,(char *)0x1b,(int)"mem_dbg.c");
      }
      CRYPTO_lock((int)data,10,&DAT_00000014,(int)"mem_dbg.c");
    }
  }
LAB_080d43bc:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

