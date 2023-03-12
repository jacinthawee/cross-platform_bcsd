
void CRYPTO_dbg_realloc(void *addr1,void *addr2,int num,char *file,int line,int before_p)

{
  undefined *puVar1;
  uint uVar2;
  void **ppvVar3;
  int iVar4;
  undefined4 uVar5;
  bio_st *bio;
  undefined *puVar6;
  void *unaff_s1;
  undefined1 *unaff_s3;
  int unaff_s4;
  undefined *puStackY_98;
  int iStackY_94;
  undefined4 uStackY_90;
  int iStackY_8c;
  undefined *puStackY_88;
  void *pvStackY_84;
  void *pvStackY_80;
  undefined1 *puStackY_7c;
  int iStackY_78;
  code *pcStackY_74;
  CRYPTO_THREADID local_50 [4];
  undefined *local_2c;
  
  puStackY_88 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(undefined **)PTR___stack_chk_guard_006aabf0;
  puVar6 = local_2c;
  pvStackY_84 = unaff_s1;
  iStackY_78 = unaff_s4;
  if ((before_p == 1) && (pvStackY_84 = addr2, addr2 != (void *)0x0)) {
    iStackY_78 = num;
    if (addr1 == (void *)0x0) {
      puVar6 = (undefined *)addr2;
      CRYPTO_dbg_malloc(addr2,num,file,line,0x81);
    }
    else {
      unaff_s3 = &_ITM_registerTMCloneTable;
      if ((mh_mode & 1) != 0) {
        CRYPTO_THREADID_current(local_50);
        CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
        if ((mh_mode & 2) == 0) {
          iVar4 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,local_50);
          puVar6 = &DAT_00000006;
          CRYPTO_lock(6,0x14,"mem_dbg.c",299);
          if (iVar4 == 0) goto LAB_004c27cc;
        }
        else {
          CRYPTO_lock(6,0x14,"mem_dbg.c",299);
        }
        CRYPTO_mem_ctrl_constprop_5();
        local_50[0].ptr = addr1;
        ppvVar3 = (void **)(*(code *)PTR_lh_delete_006a94ac)(mh,local_50);
        iVar4 = mh;
        puVar6 = PTR_lh_insert_006a8514;
        if (ppvVar3 != (void **)0x0) {
          *ppvVar3 = addr2;
          ppvVar3[1] = (void *)num;
          (*(code *)puVar6)(iVar4,ppvVar3);
        }
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
        if ((((mh_mode & 1) != 0) && (iVar4 = num_disable + -1, num_disable != 0)) &&
           (num_disable = iVar4, iVar4 == 0)) {
          mh_mode = mh_mode | 2;
          CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
        }
        puVar6 = &DAT_0000000a;
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      }
    }
  }
LAB_004c27cc:
  if (local_2c == *(undefined **)puStackY_88) {
    return;
  }
  pcStackY_74 = CRYPTO_mem_leaks;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStackY_8c = *(int *)PTR___stack_chk_guard_006aabf0;
  pvStackY_80 = addr1;
  puStackY_7c = unaff_s3;
  if ((mh != 0) || (amih != 0)) {
    CRYPTO_mem_ctrl_constprop_5();
    uStackY_90 = 0;
    iStackY_94 = 0;
    puStackY_98 = puVar6;
    if ((mh == 0) ||
       ((*(code *)PTR_lh_doall_arg_006a94bc)(mh,print_leak_LHASH_DOALL_ARG,&puStackY_98),
       iStackY_94 == 0)) {
      CRYPTO_lock(9,0x14,"mem_dbg.c",0x31e);
      uVar2 = mh_mode;
      mh_mode = 0;
      if (mh != 0) {
        (*(code *)PTR_lh_free_006a8518)();
        mh = 0;
      }
      if ((amih != 0) && (iVar4 = (*(code *)PTR_lh_num_items_006a9450)(), iVar4 == 0)) {
        (*(code *)PTR_lh_free_006a8518)(amih);
        amih = 0;
      }
      mh_mode = uVar2;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x334);
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)(puVar6,"%ld bytes leaked in %d chunks\n",uStackY_90);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) != 0) && (iVar4 = num_disable + -1, num_disable != 0)) &&
       (num_disable = iVar4, iVar4 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
    puVar6 = &DAT_0000000a;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
  if (iStackY_8c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (mh != 0) {
    CRYPTO_mem_ctrl_constprop_5();
    uVar5 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    bio = (bio_st *)(*(code *)PTR_BIO_new_006a7fa4)(uVar5);
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) == 0) || (iVar4 = num_disable + -1, num_disable == 0)) ||
       (num_disable = iVar4, iVar4 != 0)) {
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
    }
    else {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
    }
    if (bio != (bio_st *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0x6a,0,puVar6);
      CRYPTO_mem_leaks(bio);
                    /* WARNING: Could not recover jumptable at 0x004c2cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_BIO_free_006a7f70)(bio);
      return;
    }
  }
  return;
}

