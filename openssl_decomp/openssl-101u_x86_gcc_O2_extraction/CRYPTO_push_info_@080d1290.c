
int CRYPTO_push_info_(char *info,char *file,int line)

{
  int iVar1;
  _LHASH *id;
  _LHASH *mode;
  int in_GS_OFFSET;
  CRYPTO_THREADID local_18;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = 0;
  if ((mh_mode & 1) != 0) {
    CRYPTO_THREADID_current(&local_18);
    CRYPTO_lock(iVar1,5,&DAT_00000014,(int)"mem_dbg.c");
    if ((mh_mode & 2) == 0) {
      iVar1 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&local_18);
      CRYPTO_lock(iVar1,6,&DAT_00000014,(int)"mem_dbg.c");
      if (iVar1 == 0) goto LAB_080d12b3;
    }
    else {
      CRYPTO_lock(iVar1,6,&DAT_00000014,(int)"mem_dbg.c");
    }
    CRYPTO_mem_ctrl_constprop_5();
    id = (_LHASH *)CRYPTO_malloc(0x1c,"mem_dbg.c",0x18d);
    mode = id;
    if (id != (_LHASH *)0x0) {
      if ((amih == (_LHASH *)0x0) &&
         (mode = lh_new(app_info_LHASH_HASH,app_info_LHASH_COMP), amih = mode, mode == (_LHASH *)0x0
         )) {
        CRYPTO_free(id);
      }
      else {
        CRYPTO_THREADID_current((CRYPTO_THREADID *)id);
        id->hash = (LHASH_HASH_FN_TYPE)file;
        id->num_alloc_nodes = (uint)info;
        id->pmax = 1;
        id->p = 0;
        id->num_nodes = line;
        mode = (_LHASH *)lh_insert(amih,id);
        if (mode != (_LHASH *)0x0) {
          id->p = (uint)mode;
        }
      }
    }
    CRYPTO_lock((int)mode,9,&DAT_00000014,(int)"mem_dbg.c");
    if ((((mh_mode & 1) != 0) && (mode = num_disable, num_disable != (_LHASH *)0x0)) &&
       (mode = (_LHASH *)((int)&num_disable[-1].error + 3), num_disable = mode,
       mode == (_LHASH *)0x0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(0,10,(char *)0x1b,(int)"mem_dbg.c");
    }
    CRYPTO_lock((int)mode,10,&DAT_00000014,(int)"mem_dbg.c");
  }
LAB_080d12b3:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}

