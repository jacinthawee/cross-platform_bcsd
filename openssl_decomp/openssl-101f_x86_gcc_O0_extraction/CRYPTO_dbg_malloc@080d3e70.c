
void CRYPTO_dbg_malloc(void *addr,int num,char *file,int line,int before_p)

{
  int *piVar1;
  uint uVar2;
  _LHASH *ptr;
  void *pvVar3;
  _LHASH *p_Var4;
  ulong uVar5;
  int mode;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_3c [3];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = before_p & 0x7f;
  if (((uVar2 == 1) && (addr != (void *)0x0)) && ((mh_mode & 1) != 0)) {
    CRYPTO_THREADID_current(local_3c);
    CRYPTO_lock(uVar2,5,&DAT_00000014,(int)"mem_dbg.c");
    if ((mh_mode & 2) == 0) {
      mode = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,local_3c);
      CRYPTO_lock(mode,6,&DAT_00000014,(int)"mem_dbg.c");
      if (mode == 0) goto LAB_080d3ea4;
    }
    else {
      CRYPTO_lock(uVar2,6,&DAT_00000014,(int)"mem_dbg.c");
    }
    CRYPTO_mem_ctrl_constprop_5();
    ptr = (_LHASH *)CRYPTO_malloc(0x24,"mem_dbg.c",0x1f2);
    if (ptr == (_LHASH *)0x0) {
      CRYPTO_free(addr);
      CRYPTO_lock((int)ptr,9,&DAT_00000014,(int)"mem_dbg.c");
      p_Var4 = ptr;
    }
    else {
      if ((mh == (_LHASH *)0x0) &&
         (p_Var4 = lh_new(mem_LHASH_HASH,mem_LHASH_COMP), mh = p_Var4, p_Var4 == (_LHASH *)0x0)) {
        CRYPTO_free(addr);
        CRYPTO_free(ptr);
      }
      else {
        ptr->b = (LHASH_NODE **)addr;
        ptr->hash = (LHASH_HASH_FN_TYPE)file;
        ptr->num_nodes = line;
        ptr->comp = (LHASH_COMP_FN_TYPE)num;
        uVar2 = options;
        if ((options & 2) == 0) {
          ptr->num_alloc_nodes = 0;
          ptr->p = 0;
        }
        else {
          CRYPTO_THREADID_current((CRYPTO_THREADID *)&ptr->num_alloc_nodes);
          uVar2 = options;
        }
        ptr->pmax = order;
        if ((uVar2 & 1) == 0) {
          order = order + 1;
          ptr->up_load = 0;
        }
        else {
          order = order + 1;
          uVar5 = time((time_t *)0x0);
          ptr->up_load = uVar5;
        }
        CRYPTO_THREADID_current(local_3c);
        p_Var4 = amih;
        ptr->down_load = 0;
        if ((p_Var4 != (_LHASH *)0x0) &&
           (pvVar3 = lh_retrieve(p_Var4,local_3c), pvVar3 != (void *)0x0)) {
          ptr->down_load = (ulong)pvVar3;
          *(int *)((int)pvVar3 + 0x18) = *(int *)((int)pvVar3 + 0x18) + 1;
        }
        p_Var4 = (_LHASH *)lh_insert(mh,ptr);
        if (p_Var4 != (_LHASH *)0x0) {
          if (p_Var4->down_load != 0) {
            piVar1 = (int *)(p_Var4->down_load + 0x18);
            *piVar1 = *piVar1 + -1;
          }
          CRYPTO_free(p_Var4);
        }
      }
      CRYPTO_lock((int)p_Var4,9,&DAT_00000014,(int)"mem_dbg.c");
    }
    if ((((mh_mode & 1) != 0) && (p_Var4 = num_disable, num_disable != (_LHASH *)0x0)) &&
       (p_Var4 = (_LHASH *)((int)&num_disable[-1].error + 3), num_disable = p_Var4,
       p_Var4 == (_LHASH *)0x0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(0,10,(char *)0x1b,(int)"mem_dbg.c");
    }
    CRYPTO_lock((int)p_Var4,10,&DAT_00000014,(int)"mem_dbg.c");
  }
LAB_080d3ea4:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

