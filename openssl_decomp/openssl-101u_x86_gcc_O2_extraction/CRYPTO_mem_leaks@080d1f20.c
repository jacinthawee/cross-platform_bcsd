
void CRYPTO_mem_leaks(bio_st *bio)

{
  uint uVar1;
  _LHASH *p_Var2;
  int in_GS_OFFSET;
  bio_st *local_1c;
  _LHASH *local_18;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if ((mh != (_LHASH *)0x0) || (amih != (_LHASH *)0x0)) {
    CRYPTO_mem_ctrl_constprop_5();
    local_1c = bio;
    local_14 = 0;
    local_18 = (_LHASH *)0x0;
    p_Var2 = mh;
    if ((mh == (_LHASH *)0x0) ||
       (lh_doall_arg(mh,print_leak_LHASH_DOALL_ARG,&local_1c), p_Var2 = local_18,
       local_18 == (_LHASH *)0x0)) {
      CRYPTO_lock((int)p_Var2,9,&DAT_00000014,(int)"mem_dbg.c");
      uVar1 = mh_mode;
      mh_mode = 0;
      if (mh != (_LHASH *)0x0) {
        lh_free(mh);
        mh = (_LHASH *)0x0;
      }
      p_Var2 = amih;
      if ((amih != (_LHASH *)0x0) &&
         (p_Var2 = (_LHASH *)lh_num_items(amih), p_Var2 == (_LHASH *)0x0)) {
        lh_free(amih);
        amih = (_LHASH *)0x0;
      }
      mh_mode = uVar1;
      CRYPTO_lock((int)p_Var2,10,&DAT_00000014,(int)"mem_dbg.c");
    }
    else {
      p_Var2 = (_LHASH *)BIO_printf(bio,"%ld bytes leaked in %d chunks\n",local_14,local_18);
    }
    CRYPTO_lock((int)p_Var2,9,&DAT_00000014,(int)"mem_dbg.c");
    if ((((mh_mode & 1) != 0) && (p_Var2 = num_disable, num_disable != (_LHASH *)0x0)) &&
       (p_Var2 = (_LHASH *)((int)&num_disable[-1].error + 3), num_disable = p_Var2,
       p_Var2 == (_LHASH *)0x0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(0,10,(char *)0x1b,(int)"mem_dbg.c");
    }
    CRYPTO_lock((int)p_Var2,10,&DAT_00000014,(int)"mem_dbg.c");
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

