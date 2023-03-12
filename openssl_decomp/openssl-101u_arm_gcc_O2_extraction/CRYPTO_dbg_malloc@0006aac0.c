
void CRYPTO_dbg_malloc(void *addr,int num,char *file,int line,int before_p)

{
  _LHASH *lh;
  void **ptr;
  void *pvVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  CRYPTO_THREADID aCStack_3c [3];
  
  if ((((before_p & 0x7fU) == 1) && (addr != (void *)0x0)) && ((int)(mh_mode << 0x1f) < 0)) {
    CRYPTO_THREADID_current(aCStack_3c);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((int)(mh_mode << 0x1e) < 0) {
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    else {
      iVar3 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_3c);
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (iVar3 == 0) {
        return;
      }
    }
    CRYPTO_mem_ctrl_constprop_4();
    ptr = (void **)CRYPTO_malloc(0x24,"mem_dbg.c",0x1e1);
    if (ptr == (void **)0x0) {
      CRYPTO_free(addr);
    }
    else if ((mh == (_LHASH *)0x0) &&
            (mh = lh_new(mem_LHASH_HASH + 1,mem_LHASH_COMP + 1), mh == (_LHASH *)0x0)) {
      CRYPTO_free(addr);
      CRYPTO_free(ptr);
    }
    else {
      uVar2 = options;
      *ptr = addr;
      ptr[2] = file;
      ptr[3] = (void *)line;
      ptr[1] = (void *)num;
      if ((uVar2 & 2) == 0) {
        *(undefined *)(ptr + 4) = 0;
        *(undefined *)((int)ptr + 0x11) = 0;
        *(undefined *)((int)ptr + 0x12) = 0;
        *(undefined *)((int)ptr + 0x13) = 0;
        *(undefined *)(ptr + 5) = 0;
        *(undefined *)((int)ptr + 0x15) = 0;
        *(undefined *)((int)ptr + 0x16) = 0;
        *(undefined *)((int)ptr + 0x17) = 0;
      }
      else {
        CRYPTO_THREADID_current((CRYPTO_THREADID *)(ptr + 4));
        uVar2 = options;
      }
      bVar4 = (uVar2 & 1) != 0;
      if (!bVar4) {
        ptr[7] = (void *)0x0;
      }
      pvVar1 = (void *)((int)order + 1);
      ptr[6] = order;
      order = pvVar1;
      if (bVar4) {
        pvVar1 = (void *)time((time_t *)0x0);
        ptr[7] = pvVar1;
      }
      CRYPTO_THREADID_current(aCStack_3c);
      lh = amih;
      ptr[8] = (void *)0x0;
      if ((lh != (_LHASH *)0x0) && (pvVar1 = lh_retrieve(lh,aCStack_3c), pvVar1 != (void *)0x0)) {
        iVar3 = *(int *)((int)pvVar1 + 0x18);
        ptr[8] = pvVar1;
        *(int *)((int)pvVar1 + 0x18) = iVar3 + 1;
      }
      pvVar1 = lh_insert(mh,ptr);
      if (pvVar1 != (void *)0x0) {
        iVar3 = *(int *)((int)pvVar1 + 0x20);
        if (iVar3 != 0) {
          *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + -1;
        }
        CRYPTO_free(pvVar1);
      }
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
       (num_disable = num_disable + -1, num_disable == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    return;
  }
  return;
}

