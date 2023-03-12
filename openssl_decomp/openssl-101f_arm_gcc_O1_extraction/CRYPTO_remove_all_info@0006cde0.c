
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_remove_all_info(void)

{
  _LHASH *lh;
  void *ptr;
  int iVar1;
  void *data;
  _LHASH *p_Var2;
  CRYPTO_THREADID aCStack_3c [4];
  
  if (-1 < (int)(mh_mode << 0x1f)) {
    return 0;
  }
  CRYPTO_THREADID_current(aCStack_3c);
  CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
  if ((int)(mh_mode << 0x1e) < 0) {
    CRYPTO_lock(6,0x14,"mem_dbg.c",299);
  }
  else {
    iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_3c);
    CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    if (iVar1 == 0) {
      return 0;
    }
  }
  CRYPTO_mem_ctrl_constprop_4();
  p_Var2 = amih;
  if (amih != (_LHASH *)0x0) {
    p_Var2 = (_LHASH *)0x0;
    do {
      while( true ) {
        CRYPTO_THREADID_current(aCStack_3c);
        ptr = lh_delete(amih,aCStack_3c);
        lh = amih;
        if (ptr == (void *)0x0) goto LAB_0006ce98;
        data = *(void **)((int)ptr + 0x14);
        if (data != (void *)0x0) {
          *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + 1;
          lh_insert(lh,data);
        }
        iVar1 = *(int *)((int)ptr + 0x18) + -1;
        *(int *)((int)ptr + 0x18) = iVar1;
        if (0 < iVar1) break;
        *(undefined4 *)((int)ptr + 0x14) = 0;
        if (data != (void *)0x0) {
          *(int *)((int)data + 0x18) = *(int *)((int)data + 0x18) + -1;
        }
        CRYPTO_free(ptr);
        p_Var2 = (_LHASH *)((int)&p_Var2->b + 1);
        if (amih == (_LHASH *)0x0) goto LAB_0006ce98;
      }
      p_Var2 = (_LHASH *)((int)&p_Var2->b + 1);
    } while (amih != (_LHASH *)0x0);
  }
LAB_0006ce98:
  CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
  if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
     (num_disable = num_disable + -1, num_disable == 0)) {
    mh_mode = mh_mode | 2;
    CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
  }
  CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  return (int)p_Var2;
}

