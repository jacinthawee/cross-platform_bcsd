
void CRYPTO_mem_leaks(bio_st *bio)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  bio_st *bio_00;
  bio_st *local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((mh != 0) || (amih != 0)) {
    CRYPTO_mem_ctrl_constprop_5();
    local_20 = 0;
    local_24 = 0;
    local_28 = bio;
    if ((mh == 0) ||
       ((*(code *)PTR_lh_doall_arg_006a83a0)(mh,print_leak_LHASH_DOALL_ARG,&local_28), local_24 == 0
       )) {
      CRYPTO_lock(9,0x14,"mem_dbg.c",0x2eb);
      uVar2 = mh_mode;
      mh_mode = 0;
      if (mh != 0) {
        (*(code *)PTR_lh_free_006a7418)();
        mh = 0;
      }
      if ((amih != 0) && (iVar3 = (*(code *)PTR_lh_num_items_006a8330)(), iVar3 == 0)) {
        (*(code *)PTR_lh_free_006a7418)(amih);
        amih = 0;
      }
      mh_mode = uVar2;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x300);
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)(bio,"%ld bytes leaked in %d chunks\n",local_20);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((mh_mode & 1) != 0) && (iVar3 = num_disable + -1, num_disable != 0)) &&
       (num_disable = iVar3, iVar3 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    bio = (bio_st *)&DAT_0000000a;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
  if (local_1c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (mh != 0) {
    CRYPTO_mem_ctrl_constprop_5();
    uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    bio_00 = (bio_st *)(*(code *)PTR_BIO_new_006a6ea4)(uVar4);
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((mh_mode & 1) == 0) || (iVar3 = num_disable + -1, num_disable == 0)) ||
       (num_disable = iVar3, iVar3 != 0)) {
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    }
    else {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    }
    if (bio_00 != (bio_st *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(bio_00,0x6a,0,bio);
      CRYPTO_mem_leaks(bio_00);
                    /* WARNING: Could not recover jumptable at 0x004bfb34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_BIO_free_006a6e70)(bio_00);
      return;
    }
  }
  return;
}

