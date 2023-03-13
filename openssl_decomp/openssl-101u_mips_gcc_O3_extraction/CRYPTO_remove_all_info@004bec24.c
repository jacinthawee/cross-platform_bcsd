
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_remove_all_info(void)

{
  undefined *puVar1;
  CRYPTO_THREADID *pCVar2;
  ulong uVar3;
  int iVar4;
  void *pvVar5;
  CRYPTO_THREADID *pCVar6;
  CRYPTO_THREADID **ppCVar7;
  uint uVar8;
  undefined4 uVar9;
  bio_st *bio;
  void *pvVar10;
  CRYPTO_THREADID *pCVar11;
  CRYPTO_THREADID *in_a1;
  char *in_a2;
  char *num;
  char *in_a3;
  char *file;
  void *unaff_s0;
  CRYPTO_THREADID *unaff_s1;
  char *unaff_s3;
  CRYPTO_THREADID *unaff_s4;
  char *unaff_s6;
  code *pcVar12;
  char *unaff_s8;
  CRYPTO_THREADID *pCStackY_1c8;
  int iStackY_1c4;
  undefined4 uStackY_1c0;
  int iStackY_1bc;
  undefined *puStackY_1b8;
  CRYPTO_THREADID *pCStackY_1b4;
  CRYPTO_THREADID *pCStackY_1b0;
  char *pcStackY_1ac;
  CRYPTO_THREADID *pCStackY_1a8;
  code *pcStackY_1a4;
  CRYPTO_THREADID aCStack_180 [4];
  CRYPTO_THREADID *pCStack_15c;
  undefined *puStack_154;
  CRYPTO_THREADID *pCStack_150;
  CRYPTO_THREADID *pCStack_14c;
  char *pcStack_148;
  CRYPTO_THREADID *pCStack_144;
  CRYPTO_THREADID *pCStack_140;
  char *pcStack_13c;
  char *pcStack_138;
  code *pcStack_134;
  undefined *puStack_120;
  int iStack_11c;
  void *pvStack_114;
  CRYPTO_THREADID aCStack_110 [4];
  int iStack_ec;
  undefined *puStack_e8;
  CRYPTO_THREADID *pCStack_e4;
  CRYPTO_THREADID *pCStack_e0;
  char *pcStack_dc;
  CRYPTO_THREADID *pCStack_d8;
  CRYPTO_THREADID *pCStack_d4;
  char *pcStack_d0;
  code *pcStack_cc;
  undefined *puStack_b8;
  CRYPTO_THREADID *pCStack_b0;
  undefined *puStack_ac;
  CRYPTO_THREADID aCStack_a8 [3];
  CRYPTO_THREADID *pCStack_8c;
  void *pvStack_88;
  CRYPTO_THREADID *pCStack_84;
  int iStack_80;
  char *pcStack_7c;
  CRYPTO_THREADID *pCStack_78;
  undefined *puStack_74;
  char *pcStack_70;
  undefined *puStack_6c;
  char *pcStack_68;
  code *pcStack_64;
  undefined *local_50;
  CRYPTO_THREADID aCStack_48 [3];
  CRYPTO_THREADID *local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_50 = &_gp;
  local_2c = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006a9ae8;
  iStack_80 = 0;
  if ((mh_mode & 1) != 0) {
    unaff_s4 = aCStack_48;
    unaff_s8 = "TBEX";
    CRYPTO_THREADID_current(unaff_s4);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((mh_mode & 2) == 0) {
      unaff_s0 = (void *)CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,unaff_s4);
      in_a3 = (char *)0x122;
      in_a2 = "mem_dbg.c";
      in_a1 = (CRYPTO_THREADID *)&DAT_00000014;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (unaff_s0 == (void *)0x0) {
        iStack_80 = 0;
        goto LAB_004bec7c;
      }
    }
    else {
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    unaff_s3 = &_gp_1;
    CRYPTO_mem_ctrl_constprop_5();
    iStack_80 = 0;
    if (amih != 0) {
      unaff_s6 = &_gp_1;
      do {
        while( true ) {
          CRYPTO_THREADID_current(unaff_s4);
          unaff_s0 = (void *)(**(code **)(local_50 + -0x6a50))(amih,unaff_s4);
          iVar4 = amih;
          if (unaff_s0 == (void *)0x0) goto LAB_004bedd0;
          unaff_s1 = *(CRYPTO_THREADID **)((int)unaff_s0 + 0x14);
          if (unaff_s1 == (CRYPTO_THREADID *)0x0) break;
          pcVar12 = *(code **)(local_50 + -0x79cc);
          unaff_s1[3].ptr = (void *)((int)unaff_s1[3].ptr + 1);
          (*pcVar12)(iVar4,unaff_s1);
          iVar4 = *(int *)((int)unaff_s0 + 0x18) + -1;
          *(int *)((int)unaff_s0 + 0x18) = iVar4;
          if (0 < iVar4) goto LAB_004bed34;
          pvVar5 = unaff_s1[3].ptr;
          *(undefined4 *)((int)unaff_s0 + 0x14) = 0;
          unaff_s1[3].ptr = (void *)((int)pvVar5 + -1);
LAB_004bedb4:
          iStack_80 = iStack_80 + 1;
          CRYPTO_free(unaff_s0);
          if (amih == 0) goto LAB_004bedd0;
        }
        iVar4 = *(int *)((int)unaff_s0 + 0x18) + -1;
        *(int *)((int)unaff_s0 + 0x18) = iVar4;
        if (iVar4 < 1) {
          *(undefined4 *)((int)unaff_s0 + 0x14) = 0;
          goto LAB_004bedb4;
        }
LAB_004bed34:
        iStack_80 = iStack_80 + 1;
      } while (amih != 0);
    }
LAB_004bedd0:
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    in_a3 = (char *)0x112;
    in_a2 = "mem_dbg.c";
    in_a1 = (CRYPTO_THREADID *)&DAT_00000014;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
LAB_004bec7c:
  if (local_2c == *(CRYPTO_THREADID **)puStack_74) {
    return iStack_80;
  }
  pcStack_64 = CRYPTO_dbg_malloc;
  pCStack_e0 = local_2c;
  (**(code **)(local_50 + -0x5330))();
  puStack_e8 = PTR___stack_chk_guard_006a9ae8;
  puStack_6c = &_gp_1;
  puStack_b8 = &_gp;
  pCVar11 = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006a9ae8;
  pCVar6 = in_a1;
  num = in_a2;
  file = in_a3;
  pcStack_dc = unaff_s3;
  pCStack_144 = unaff_s4;
  pCStack_d4 = (CRYPTO_THREADID *)puStack_74;
  pcStack_138 = &_gp_1;
  pCStack_8c = pCVar11;
  pvStack_88 = unaff_s0;
  pCStack_84 = unaff_s1;
  pcStack_7c = unaff_s3;
  pCStack_78 = unaff_s4;
  pcStack_70 = unaff_s6;
  pcStack_68 = unaff_s8;
  if ((((uint)local_50 & 0x7f) == 1) && (pCStack_e0 != (CRYPTO_THREADID *)0x0)) {
    pcStack_dc = &_gp_1;
    if ((mh_mode & 1) != 0) {
      pCStack_b0 = aCStack_a8;
      CRYPTO_THREADID_current(aCStack_a8);
      unaff_s6 = "TBEX";
      CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
      pCStack_144 = in_a1;
      pCStack_d4 = (CRYPTO_THREADID *)in_a2;
      pcStack_138 = in_a3;
      if ((mh_mode & 2) == 0) {
        unaff_s1 = (CRYPTO_THREADID *)
                   CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_b0);
        file = (char *)0x122;
        num = "mem_dbg.c";
        pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
        pCVar11 = (CRYPTO_THREADID *)&DAT_00000006;
        CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
        if (unaff_s1 == (CRYPTO_THREADID *)0x0) goto LAB_004bef3c;
      }
      else {
        CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      }
      CRYPTO_mem_ctrl_constprop_5();
      unaff_s1 = (CRYPTO_THREADID *)CRYPTO_malloc(0x24,"mem_dbg.c",0x1e1);
      if (unaff_s1 == (CRYPTO_THREADID *)0x0) {
        CRYPTO_free(pCStack_e0);
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      }
      else {
        if ((mh == 0) &&
           (mh = (**(code **)(puStack_b8 + -0x79d4))(mem_LHASH_HASH,mem_LHASH_COMP), mh == 0)) {
          CRYPTO_free(pCStack_e0);
          CRYPTO_free(unaff_s1);
        }
        else {
          unaff_s1->ptr = pCStack_e0;
          unaff_s1[1].ptr = in_a2;
          unaff_s1[1].val = (ulong)in_a3;
          unaff_s1->val = (ulong)in_a1;
          uVar8 = options;
          puStack_ac = &_gp_1;
          if ((options & 2) == 0) {
            *(char *)&unaff_s1[2].ptr = '\0';
            *(char *)((int)&unaff_s1[2].ptr + 1) = '\0';
            *(char *)((int)&unaff_s1[2].ptr + 2) = '\0';
            *(char *)((int)&unaff_s1[2].ptr + 3) = '\0';
            *(undefined *)&unaff_s1[2].val = 0;
            *(undefined *)((int)&unaff_s1[2].val + 1) = 0;
            *(undefined *)((int)&unaff_s1[2].val + 2) = 0;
            *(undefined *)((int)&unaff_s1[2].val + 3) = 0;
          }
          else {
            CRYPTO_THREADID_current(unaff_s1 + 2);
            uVar8 = *(uint *)(puStack_ac + -0x5384);
          }
          unaff_s1[3].ptr = order;
          if ((uVar8 & 1) == 0) {
            order = (void *)((int)order + 1);
            unaff_s1[3].val = 0;
          }
          else {
            order = (void *)((int)order + 1);
            uVar3 = (**(code **)(puStack_b8 + -0x5304))(0);
            unaff_s1[3].val = uVar3;
          }
          pCStack_e0 = pCStack_b0;
          CRYPTO_THREADID_current(pCStack_b0);
          unaff_s1[4].ptr = (void *)0x0;
          if ((amih != 0) &&
             (pvVar5 = (void *)(**(code **)(puStack_b8 + -0x7a30))(amih,pCStack_e0),
             pvVar5 != (void *)0x0)) {
            iVar4 = *(int *)((int)pvVar5 + 0x18);
            unaff_s1[4].ptr = pvVar5;
            *(int *)((int)pvVar5 + 0x18) = iVar4 + 1;
          }
          pvVar5 = (void *)(**(code **)(puStack_b8 + -0x79cc))(mh,unaff_s1);
          if (pvVar5 != (void *)0x0) {
            iVar4 = *(int *)((int)pvVar5 + 0x20);
            if (iVar4 != 0) {
              *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + -1;
            }
            CRYPTO_free(pvVar5);
          }
        }
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      }
      if ((((mh_mode & 1) != 0) && (num_disable != 0)) &&
         (num_disable = num_disable - 1, num_disable == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
      }
      file = (char *)0x112;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCVar11 = (CRYPTO_THREADID *)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    }
  }
LAB_004bef3c:
  pCVar2 = *(CRYPTO_THREADID **)puStack_e8;
  if (pCStack_8c == pCVar2) {
    return (int)pCVar2;
  }
  pcStack_cc = CRYPTO_dbg_free;
  (**(code **)(puStack_b8 + -0x5330))();
  puStack_154 = PTR___stack_chk_guard_006a9ae8;
  puStack_120 = &_gp;
  iStack_ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  pCStackY_1b0 = pCVar11;
  pCStack_150 = unaff_s1;
  pCStack_14c = pCStack_e0;
  pcStackY_1ac = pcStack_dc;
  pCStack_140 = pCStack_d4;
  pCStack_e4 = unaff_s1;
  pCStack_d8 = pCStack_144;
  pcStack_d0 = unaff_s6;
  if (((pCVar6 == (CRYPTO_THREADID *)0x0) &&
      (pCStack_150 = pCVar11, pCVar11 != (CRYPTO_THREADID *)0x0)) &&
     (pCStack_14c = (CRYPTO_THREADID *)&_gp_1, (mh_mode & 1) != 0)) {
    pCStack_140 = aCStack_110;
    pcStackY_1ac = "TBEX";
    CRYPTO_THREADID_current(pCStack_140);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((mh_mode & 2) == 0) {
      pCStack_144 = (CRYPTO_THREADID *)
                    CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_140);
      file = (char *)0x122;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_1b0 = (CRYPTO_THREADID *)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (pCStack_144 == (CRYPTO_THREADID *)0x0) goto LAB_004bf31c;
    }
    else {
      file = (char *)0x122;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_1b0 = (CRYPTO_THREADID *)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    pCStack_144 = (CRYPTO_THREADID *)&_gp_1;
    if (mh != 0) {
      CRYPTO_mem_ctrl_constprop_5();
      aCStack_110[0].ptr = pCVar11;
      pvVar5 = (void *)(**(code **)(puStack_120 + -0x6a50))(mh,pCStack_140);
      if (pvVar5 != (void *)0x0) {
        pCVar11 = *(CRYPTO_THREADID **)((int)pvVar5 + 0x20);
        if ((pCVar11 != (CRYPTO_THREADID *)0x0) &&
           (pvVar10 = (void *)((int)pCVar11[3].ptr + -1), pCVar11[3].ptr = pvVar10, (int)pvVar10 < 1
           )) {
          pCStack_144 = (CRYPTO_THREADID *)pCVar11[2].val;
          pvStack_114 = pvVar5;
          if ((pCStack_144 != (CRYPTO_THREADID *)0x0) &&
             (pvVar5 = (void *)((int)pCStack_144[3].ptr + -1), pCStack_144[3].ptr = pvVar5,
             (int)pvVar5 < 1)) {
            pCStack_140 = (CRYPTO_THREADID *)pCStack_144[2].val;
            if ((pCStack_140 != (CRYPTO_THREADID *)0x0) &&
               (pvVar5 = (void *)((int)pCStack_140[3].ptr + -1), pCStack_140[3].ptr = pvVar5,
               (int)pvVar5 < 1)) {
              unaff_s6 = (char *)pCStack_140[2].val;
              if ((unaff_s6 != (char *)0x0) &&
                 (iVar4 = *(int *)(unaff_s6 + 0x18), *(int *)(unaff_s6 + 0x18) = iVar4 + -1,
                 iVar4 + -1 < 1)) {
                if (*(int *)(unaff_s6 + 0x14) != 0) {
                  app_info_free();
                }
                CRYPTO_free(unaff_s6);
              }
              CRYPTO_free(pCStack_140);
            }
            CRYPTO_free(pCStack_144);
          }
          CRYPTO_free(pCVar11);
          pvVar5 = pvStack_114;
        }
        CRYPTO_free(pvVar5);
      }
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
         (num_disable = uVar8, uVar8 == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
      }
      file = (char *)0x112;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_1b0 = (CRYPTO_THREADID *)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      pCStack_150 = pCVar11;
    }
  }
LAB_004bf31c:
  iVar4 = *(int *)puStack_154;
  if (iStack_ec == iVar4) {
    return iVar4;
  }
  pcStack_134 = CRYPTO_dbg_realloc;
  (**(code **)(puStack_120 + -0x5330))();
  puStackY_1b8 = PTR___stack_chk_guard_006a9ae8;
  pCStack_15c = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006a9ae8;
  pCVar11 = pCStack_15c;
  pCStackY_1b4 = pCStack_150;
  pCStackY_1a8 = pCStack_144;
  pcStack_148 = pcStackY_1ac;
  pcStack_13c = unaff_s6;
  if ((iStack_11c == 1) && (pCStackY_1b4 = pCVar6, pCVar6 != (CRYPTO_THREADID *)0x0)) {
    pCStackY_1a8 = (CRYPTO_THREADID *)num;
    if (pCStackY_1b0 == (CRYPTO_THREADID *)0x0) {
      pCVar11 = pCVar6;
      CRYPTO_dbg_malloc(pCVar6,(int)num,file,(int)puStack_120,0x81);
    }
    else {
      pcStackY_1ac = &_gp_1;
      if ((mh_mode & 1) != 0) {
        CRYPTO_THREADID_current(aCStack_180);
        CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
        if ((mh_mode & 2) == 0) {
          iVar4 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_180);
          pCVar11 = (CRYPTO_THREADID *)&DAT_00000006;
          CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
          if (iVar4 == 0) goto LAB_004bf63c;
        }
        else {
          CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
        }
        CRYPTO_mem_ctrl_constprop_5();
        aCStack_180[0].ptr = pCStackY_1b0;
        ppCVar7 = (CRYPTO_THREADID **)(*(code *)PTR_lh_delete_006a8390)(mh,aCStack_180);
        uVar8 = mh;
        puVar1 = PTR_lh_insert_006a7414;
        if (ppCVar7 != (CRYPTO_THREADID **)0x0) {
          *ppCVar7 = pCVar6;
          ppCVar7[1] = (CRYPTO_THREADID *)num;
          (*(code *)puVar1)(uVar8,ppCVar7);
        }
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
        if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
           (num_disable = uVar8, uVar8 == 0)) {
          mh_mode = mh_mode | 2;
          CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
        }
        pCVar11 = (CRYPTO_THREADID *)&DAT_0000000a;
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      }
    }
  }
LAB_004bf63c:
  pCVar6 = *(CRYPTO_THREADID **)puStackY_1b8;
  if (pCStack_15c == pCVar6) {
    return (int)pCVar6;
  }
  pcStackY_1a4 = CRYPTO_mem_leaks;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStackY_1bc = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((mh != 0) || (amih != 0)) {
    CRYPTO_mem_ctrl_constprop_5();
    uStackY_1c0 = 0;
    iStackY_1c4 = 0;
    pCStackY_1c8 = pCVar11;
    if ((mh == 0) ||
       ((*(code *)PTR_lh_doall_arg_006a83a0)(mh,print_leak_LHASH_DOALL_ARG,&pCStackY_1c8),
       iStackY_1c4 == 0)) {
      CRYPTO_lock(9,0x14,"mem_dbg.c",0x2eb);
      uVar8 = mh_mode;
      mh_mode = 0;
      if (mh != 0) {
        (*(code *)PTR_lh_free_006a7418)();
        mh = 0;
      }
      if ((amih != 0) && (iVar4 = (*(code *)PTR_lh_num_items_006a8330)(), iVar4 == 0)) {
        (*(code *)PTR_lh_free_006a7418)(amih);
        amih = 0;
      }
      mh_mode = uVar8;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x300);
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)(pCVar11,"%ld bytes leaked in %d chunks\n",uStackY_1c0);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    pCVar11 = (CRYPTO_THREADID *)&DAT_0000000a;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
  if (iStackY_1bc != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    uVar8 = mh;
    if (mh != 0) {
      CRYPTO_mem_ctrl_constprop_5();
      uVar9 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      bio = (bio_st *)(*(code *)PTR_BIO_new_006a6ea4)(uVar9);
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      uVar8 = mh_mode & 1;
      if (((uVar8 == 0) || (uVar8 = num_disable - 1, num_disable == 0)) ||
         (num_disable = uVar8, uVar8 != 0)) {
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      }
      else {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      }
      if (bio != (bio_st *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0x6a,0,pCVar11);
        CRYPTO_mem_leaks(bio);
                    /* WARNING: Could not recover jumptable at 0x004bfb34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar4 = (*(code *)PTR_BIO_free_006a6e70)(bio);
        return iVar4;
      }
    }
    return uVar8;
  }
  return *(int *)puVar1;
}

