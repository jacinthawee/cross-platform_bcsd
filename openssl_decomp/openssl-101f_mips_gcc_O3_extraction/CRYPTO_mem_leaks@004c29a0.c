
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((mh != 0) || (amih != 0)) {
    CRYPTO_mem_ctrl_constprop_5();
    local_20 = 0;
    local_24 = 0;
    local_28 = bio;
    if ((mh == 0) ||
       ((*(code *)PTR_lh_doall_arg_006a94bc)(mh,print_leak_LHASH_DOALL_ARG,&local_28), local_24 == 0
       )) {
      CRYPTO_lock(9,0x14,"mem_dbg.c",0x31e);
      uVar2 = mh_mode;
      mh_mode = 0;
      if (mh != 0) {
        (*(code *)PTR_lh_free_006a8518)();
        mh = 0;
      }
      if ((amih != 0) && (iVar3 = (*(code *)PTR_lh_num_items_006a9450)(), iVar3 == 0)) {
        (*(code *)PTR_lh_free_006a8518)(amih);
        amih = 0;
      }
      mh_mode = uVar2;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x334);
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)(bio,"%ld bytes leaked in %d chunks\n",local_20);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) != 0) && (iVar3 = num_disable + -1, num_disable != 0)) &&
       (num_disable = iVar3, iVar3 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
    bio = (bio_st *)&DAT_0000000a;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
  if (local_1c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (mh != 0) {
    CRYPTO_mem_ctrl_constprop_5();
    uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    bio_00 = (bio_st *)(*(code *)PTR_BIO_new_006a7fa4)(uVar4);
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) == 0) || (iVar3 = num_disable + -1, num_disable == 0)) ||
       (num_disable = iVar3, iVar3 != 0)) {
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
    }
    else {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
    }
    if (bio_00 != (bio_st *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(bio_00,0x6a,0,bio);
      CRYPTO_mem_leaks(bio_00);
                    /* WARNING: Could not recover jumptable at 0x004c2cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_BIO_free_006a7f70)(bio_00);
      return;
    }
  }
  return;
}

