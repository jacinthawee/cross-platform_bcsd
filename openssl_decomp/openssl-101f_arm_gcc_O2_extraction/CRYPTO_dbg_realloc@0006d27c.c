
void CRYPTO_dbg_realloc(void *addr1,void *addr2,int num,char *file,int line,int before_p)

{
  void **data;
  int iVar1;
  CRYPTO_THREADID local_3c [4];
  
  if ((before_p == 1) && (addr2 != (void *)0x0)) {
    if (addr1 == (void *)0x0) {
      CRYPTO_dbg_malloc(addr2,num,file,line,0x81);
    }
    else if ((int)(mh_mode << 0x1f) < 0) {
      CRYPTO_THREADID_current(local_3c);
      CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
      if ((int)(mh_mode << 0x1e) < 0) {
        CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      }
      else {
        iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,local_3c);
        CRYPTO_lock(6,0x14,"mem_dbg.c",299);
        if (iVar1 == 0) {
          return;
        }
      }
      CRYPTO_mem_ctrl_constprop_4();
      local_3c[0].ptr = addr1;
      data = (void **)lh_delete(mh,local_3c);
      if (data != (void **)0x0) {
        *data = addr2;
        data[1] = (void *)num;
        lh_insert(mh,data);
      }
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
      if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
         (num_disable = num_disable + -1, num_disable == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
      }
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      return;
    }
  }
  return;
}

