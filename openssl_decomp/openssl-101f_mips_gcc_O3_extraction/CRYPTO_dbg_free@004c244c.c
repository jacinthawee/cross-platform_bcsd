
void CRYPTO_dbg_free(void *addr,int before_p)

{
  undefined *puVar1;
  uint uVar2;
  void *ptr;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  bio_st *bio;
  void *pvVar6;
  undefined *puVar7;
  char *in_a2;
  char *in_a3;
  undefined *unaff_s1;
  undefined1 *unaff_s2;
  char *unaff_s3;
  char *unaff_s4;
  CRYPTO_THREADID *unaff_s5;
  void *unaff_s6;
  undefined *puStackY_100;
  int iStackY_fc;
  undefined4 uStackY_f8;
  int iStackY_f4;
  undefined *puStackY_f0;
  undefined *puStackY_ec;
  undefined *puStackY_e8;
  char *pcStackY_e4;
  char *pcStackY_e0;
  code *pcStackY_dc;
  CRYPTO_THREADID aCStack_b8 [4];
  undefined *puStack_94;
  undefined *puStack_8c;
  undefined *puStack_88;
  undefined1 *puStack_84;
  char *pcStack_80;
  char *pcStack_7c;
  CRYPTO_THREADID *pCStack_78;
  void *pvStack_74;
  int iStack_54;
  CRYPTO_THREADID local_48 [4];
  int local_24;
  
  puStack_8c = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStackY_e8 = (undefined *)addr;
  puStack_88 = unaff_s1;
  if (((before_p == 0) && (puStack_88 = (undefined *)addr, addr != (void *)0x0)) &&
     (unaff_s2 = &_ITM_registerTMCloneTable, (mh_mode & 1) != 0)) {
    unaff_s5 = local_48;
    unaff_s3 = "x";
    CRYPTO_THREADID_current(unaff_s5);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
    if ((mh_mode & 2) == 0) {
      unaff_s4 = (char *)CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,unaff_s5);
      in_a3 = (char *)0x12b;
      in_a2 = "mem_dbg.c";
      before_p = (int)&DAT_00000014;
      puStackY_e8 = &DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      if (unaff_s4 == (char *)0x0) goto LAB_004c24ac;
    }
    else {
      in_a3 = (char *)0x12b;
      in_a2 = "mem_dbg.c";
      before_p = (int)&DAT_00000014;
      puStackY_e8 = &DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    }
    unaff_s4 = &_ITM_registerTMCloneTable;
    if (mh != 0) {
      CRYPTO_mem_ctrl_constprop_5();
      local_48[0].ptr = addr;
      ptr = (void *)(*(code *)PTR_lh_delete_006a94ac)(mh,unaff_s5);
      if (ptr != (void *)0x0) {
        addr = *(void **)((int)ptr + 0x20);
        if (((undefined *)addr != (undefined *)0x0) &&
           (iVar4 = *(int *)((int)addr + 0x18), *(int *)((int)addr + 0x18) = iVar4 + -1,
           iVar4 + -1 < 1)) {
          unaff_s4 = *(char **)((int)addr + 0x14);
          if ((unaff_s4 != (char *)0x0) &&
             (iVar4 = *(int *)(unaff_s4 + 0x18), *(int *)(unaff_s4 + 0x18) = iVar4 + -1,
             iVar4 + -1 < 1)) {
            unaff_s5 = *(CRYPTO_THREADID **)(unaff_s4 + 0x14);
            if ((unaff_s5 != (CRYPTO_THREADID *)0x0) &&
               (pvVar6 = (void *)((int)unaff_s5[3].ptr + -1), unaff_s5[3].ptr = pvVar6,
               (int)pvVar6 < 1)) {
              unaff_s6 = (void *)unaff_s5[2].val;
              if ((unaff_s6 != (void *)0x0) &&
                 (iVar4 = *(int *)((int)unaff_s6 + 0x18) + -1,
                 *(int *)((int)unaff_s6 + 0x18) = iVar4, iVar4 < 1)) {
                if (*(int *)((int)unaff_s6 + 0x14) != 0) {
                  app_info_free();
                }
                CRYPTO_free(unaff_s6);
              }
              CRYPTO_free(unaff_s5);
            }
            CRYPTO_free(unaff_s4);
          }
          CRYPTO_free(addr);
        }
        CRYPTO_free(ptr);
      }
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
      if ((((mh_mode & 1) != 0) && (iVar4 = num_disable + -1, num_disable != 0)) &&
         (num_disable = iVar4, iVar4 == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
      }
      in_a3 = (char *)0x11a;
      in_a2 = "mem_dbg.c";
      before_p = (int)&DAT_00000014;
      puStackY_e8 = &DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      puStack_88 = (undefined *)addr;
    }
  }
LAB_004c24ac:
  if (local_24 == *(int *)puStack_8c) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStackY_f0 = PTR___stack_chk_guard_006aabf0;
  puStack_94 = *(undefined **)PTR___stack_chk_guard_006aabf0;
  puVar7 = puStack_94;
  puStackY_ec = puStack_88;
  pcStackY_e4 = unaff_s3;
  pcStackY_e0 = unaff_s4;
  puStack_84 = unaff_s2;
  pcStack_80 = unaff_s3;
  pcStack_7c = unaff_s4;
  pCStack_78 = unaff_s5;
  pvStack_74 = unaff_s6;
  if ((iStack_54 == 1) &&
     (puStackY_ec = (undefined *)before_p, (undefined *)before_p != (undefined *)0x0)) {
    pcStackY_e0 = in_a2;
    if (puStackY_e8 == (undefined *)0x0) {
      puVar7 = (undefined *)before_p;
      CRYPTO_dbg_malloc((void *)before_p,(int)in_a2,in_a3,(int)&_gp,0x81);
    }
    else {
      pcStackY_e4 = &_ITM_registerTMCloneTable;
      if ((mh_mode & 1) != 0) {
        CRYPTO_THREADID_current(aCStack_b8);
        CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
        if ((mh_mode & 2) == 0) {
          iVar4 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_b8);
          puVar7 = &DAT_00000006;
          CRYPTO_lock(6,0x14,"mem_dbg.c",299);
          if (iVar4 == 0) goto LAB_004c27cc;
        }
        else {
          CRYPTO_lock(6,0x14,"mem_dbg.c",299);
        }
        CRYPTO_mem_ctrl_constprop_5();
        aCStack_b8[0].ptr = puStackY_e8;
        puVar3 = (undefined4 *)(*(code *)PTR_lh_delete_006a94ac)(mh,aCStack_b8);
        iVar4 = mh;
        puVar7 = PTR_lh_insert_006a8514;
        if (puVar3 != (undefined4 *)0x0) {
          *puVar3 = before_p;
          puVar3[1] = in_a2;
          (*(code *)puVar7)(iVar4,puVar3);
        }
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
        if ((((mh_mode & 1) != 0) && (iVar4 = num_disable + -1, num_disable != 0)) &&
           (num_disable = iVar4, iVar4 == 0)) {
          mh_mode = mh_mode | 2;
          CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
        }
        puVar7 = &DAT_0000000a;
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      }
    }
  }
LAB_004c27cc:
  if (puStack_94 == *(undefined **)puStackY_f0) {
    return;
  }
  pcStackY_dc = CRYPTO_mem_leaks;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStackY_f4 = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((mh != 0) || (amih != 0)) {
    CRYPTO_mem_ctrl_constprop_5();
    uStackY_f8 = 0;
    iStackY_fc = 0;
    puStackY_100 = puVar7;
    if ((mh == 0) ||
       ((*(code *)PTR_lh_doall_arg_006a94bc)(mh,print_leak_LHASH_DOALL_ARG,&puStackY_100),
       iStackY_fc == 0)) {
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
      (*(code *)PTR_BIO_printf_006a7f38)(puVar7,"%ld bytes leaked in %d chunks\n",uStackY_f8);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) != 0) && (iVar4 = num_disable + -1, num_disable != 0)) &&
       (num_disable = iVar4, iVar4 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
    puVar7 = &DAT_0000000a;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
  if (iStackY_f4 == *(int *)puVar1) {
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
      (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0x6a,0,puVar7);
      CRYPTO_mem_leaks(bio);
                    /* WARNING: Could not recover jumptable at 0x004c2cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_BIO_free_006a7f70)(bio);
      return;
    }
  }
  return;
}

