
int CRYPTO_push_info_(char *info,char *file,int line)

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
  CRYPTO_THREADID *ptr;
  char *pcVar11;
  char *num;
  char *in_a3;
  char *file_00;
  CRYPTO_THREADID *unaff_s0;
  char *unaff_s3;
  CRYPTO_THREADID *unaff_s4;
  char *unaff_s5;
  char *unaff_s6;
  undefined1 *unaff_s7;
  code *pcVar12;
  char *unaff_s8;
  CRYPTO_THREADID *pCStackY_270;
  int iStackY_26c;
  undefined4 uStackY_268;
  int iStackY_264;
  undefined *puStackY_260;
  CRYPTO_THREADID *pCStackY_25c;
  CRYPTO_THREADID *pCStackY_258;
  char *pcStackY_254;
  CRYPTO_THREADID *pCStackY_250;
  code *pcStackY_24c;
  CRYPTO_THREADID aCStack_228 [4];
  CRYPTO_THREADID *pCStack_204;
  undefined *puStack_1fc;
  CRYPTO_THREADID *pCStack_1f8;
  CRYPTO_THREADID *pCStack_1f4;
  char *pcStack_1f0;
  CRYPTO_THREADID *pCStack_1ec;
  CRYPTO_THREADID *pCStack_1e8;
  char *pcStack_1e4;
  char *pcStack_1e0;
  code *pcStack_1dc;
  undefined *puStack_1c8;
  int iStack_1c4;
  void *pvStack_1bc;
  CRYPTO_THREADID aCStack_1b8 [4];
  int iStack_194;
  undefined *puStack_190;
  CRYPTO_THREADID *pCStack_18c;
  CRYPTO_THREADID *pCStack_188;
  char *pcStack_184;
  CRYPTO_THREADID *pCStack_180;
  CRYPTO_THREADID *pCStack_17c;
  char *pcStack_178;
  code *pcStack_174;
  undefined *puStack_160;
  CRYPTO_THREADID *pCStack_158;
  undefined1 *puStack_154;
  CRYPTO_THREADID aCStack_150 [3];
  CRYPTO_THREADID *pCStack_134;
  undefined *puStack_130;
  CRYPTO_THREADID *pCStack_12c;
  int iStack_128;
  char *pcStack_124;
  CRYPTO_THREADID *pCStack_120;
  undefined *puStack_11c;
  char *pcStack_118;
  undefined1 *puStack_114;
  char *pcStack_110;
  code *pcStack_10c;
  undefined *puStack_f8;
  CRYPTO_THREADID aCStack_f0 [3];
  CRYPTO_THREADID *pCStack_d4;
  undefined *puStack_d0;
  undefined1 *puStack_cc;
  int iStack_c8;
  char *pcStack_c4;
  CRYPTO_THREADID *pCStack_c0;
  char *pcStack_bc;
  char *pcStack_b8;
  undefined1 *puStack_b4;
  CRYPTO_THREADID aCStack_90 [3];
  int iStack_74;
  CRYPTO_THREADID *pCStack_6c;
  undefined *puStack_68;
  undefined1 *puStack_64;
  char *pcStack_60;
  CRYPTO_THREADID *pCStack_5c;
  char *pcStack_58;
  code *pcStack_54;
  undefined *local_40;
  CRYPTO_THREADID CStack_34;
  int local_2c;
  
  puStack_68 = PTR___stack_chk_guard_006aabf0;
  local_40 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pCVar2 = (CRYPTO_THREADID *)file;
  pcVar11 = (char *)line;
  pCStack_c0 = unaff_s4;
  pcStack_bc = unaff_s5;
  pcStack_1e4 = unaff_s6;
  if ((mh_mode & 1) != 0) {
    CRYPTO_THREADID_current(&CStack_34);
    unaff_s3 = "Number";
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
    pCStack_c0 = (CRYPTO_THREADID *)info;
    pcStack_bc = file;
    pcStack_1e4 = (char *)line;
    if ((mh_mode & 2) == 0) {
      unaff_s0 = (CRYPTO_THREADID *)
                 CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_34);
      in_a3 = (char *)0x12b;
      pcVar11 = "mem_dbg.c";
      pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      if (unaff_s0 == (CRYPTO_THREADID *)0x0) goto LAB_004c1910;
    }
    else {
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    }
    CRYPTO_mem_ctrl_constprop_5();
    unaff_s0 = (CRYPTO_THREADID *)CRYPTO_malloc(0x1c,"mem_dbg.c",0x196);
    if (unaff_s0 != (CRYPTO_THREADID *)0x0) {
      unaff_s7 = &_ITM_registerTMCloneTable;
      if ((amih == 0) &&
         (amih = (**(code **)(local_40 + -0x79d4))(app_info_LHASH_HASH,app_info_LHASH_COMP),
         amih == 0)) {
        CRYPTO_free(unaff_s0);
      }
      else {
        CRYPTO_THREADID_current(unaff_s0);
        iVar4 = amih;
        unaff_s0[1].ptr = file;
        unaff_s0[1].val = line;
        unaff_s0[2].ptr = info;
        unaff_s0[3].ptr = (void *)0x1;
        pcVar12 = *(code **)(local_40 + -0x79cc);
        unaff_s0[2].val = 0;
        uVar3 = (*pcVar12)(iVar4,unaff_s0);
        if (uVar3 != 0) {
          unaff_s0[2].val = uVar3;
        }
      }
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
    in_a3 = (char *)0x11a;
    pcVar11 = "mem_dbg.c";
    pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
LAB_004c1910:
  if (local_2c == *(int *)puStack_68) {
    return 0;
  }
  pcStack_54 = CRYPTO_pop_info;
  (**(code **)(local_40 + -0x5328))();
  puStack_130 = PTR___stack_chk_guard_006aabf0;
  pCStack_18c = (CRYPTO_THREADID *)&_ITM_registerTMCloneTable;
  puStack_64 = &_ITM_registerTMCloneTable;
  iStack_74 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_c8 = 0;
  pcStack_124 = unaff_s3;
  pCStack_6c = unaff_s0;
  pcStack_60 = unaff_s3;
  pCStack_5c = pCStack_c0;
  pcStack_58 = pcStack_bc;
  if ((mh_mode & 1) != 0) {
    pcStack_124 = "Number";
    CRYPTO_THREADID_current(aCStack_90);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
    if ((mh_mode & 2) == 0) {
      pCStack_c0 = (CRYPTO_THREADID *)
                   CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_90);
      in_a3 = (char *)0x12b;
      pcVar11 = "mem_dbg.c";
      pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      if (pCStack_c0 == (CRYPTO_THREADID *)0x0) {
        iStack_c8 = 0;
        goto LAB_004c1b88;
      }
    }
    else {
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    }
    pcStack_bc = &_ITM_registerTMCloneTable;
    CRYPTO_mem_ctrl_constprop_5();
    if (amih == 0) {
LAB_004c1da0:
      iStack_c8 = 0;
    }
    else {
      CRYPTO_THREADID_current(aCStack_90);
      pvVar5 = (void *)(*(code *)PTR_lh_delete_006a94ac)(amih,aCStack_90);
      iVar4 = amih;
      puVar1 = PTR_lh_insert_006a8514;
      if (pvVar5 == (void *)0x0) goto LAB_004c1da0;
      pCStack_c0 = *(CRYPTO_THREADID **)((int)pvVar5 + 0x14);
      if (pCStack_c0 == (CRYPTO_THREADID *)0x0) {
        iVar4 = *(int *)((int)pvVar5 + 0x18) + -1;
        *(int *)((int)pvVar5 + 0x18) = iVar4;
        if (0 < iVar4) goto LAB_004c1c8c;
        *(undefined4 *)((int)pvVar5 + 0x14) = 0;
LAB_004c1d2c:
        iStack_c8 = 1;
        CRYPTO_free(pvVar5);
      }
      else {
        pCStack_c0[3].ptr = (void *)((int)pCStack_c0[3].ptr + 1);
        (*(code *)puVar1)(iVar4,pCStack_c0);
        iVar4 = *(int *)((int)pvVar5 + 0x18) + -1;
        *(int *)((int)pvVar5 + 0x18) = iVar4;
        if (iVar4 < 1) {
          pvVar10 = pCStack_c0[3].ptr;
          *(undefined4 *)((int)pvVar5 + 0x14) = 0;
          pCStack_c0[3].ptr = (void *)((int)pvVar10 + -1);
          goto LAB_004c1d2c;
        }
LAB_004c1c8c:
        iStack_c8 = 1;
      }
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
    in_a3 = (char *)0x11a;
    pcVar11 = "mem_dbg.c";
    pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
LAB_004c1b88:
  if (iStack_74 == *(int *)puStack_130) {
    return iStack_c8;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_11c = PTR___stack_chk_guard_006aabf0;
  puStack_cc = &_ITM_registerTMCloneTable;
  puStack_d0 = puStack_130;
  puStack_f8 = &_gp;
  pCStack_d4 = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006aabf0;
  iStack_128 = 0;
  pCStack_120 = pCStack_c0;
  pcStack_c4 = pcStack_124;
  pcStack_b8 = pcStack_1e4;
  puStack_b4 = unaff_s7;
  if ((mh_mode & 1) != 0) {
    pCStack_120 = aCStack_f0;
    unaff_s8 = "Number";
    CRYPTO_THREADID_current(pCStack_120);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
    if ((mh_mode & 2) == 0) {
      puStack_130 = (undefined *)
                    CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_120);
      in_a3 = (char *)0x12b;
      pcVar11 = "mem_dbg.c";
      pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      if (puStack_130 == (undefined *)0x0) {
        iStack_128 = 0;
        goto LAB_004c1e0c;
      }
    }
    else {
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    }
    pcStack_124 = &_ITM_registerTMCloneTable;
    CRYPTO_mem_ctrl_constprop_5();
    iStack_128 = 0;
    if (amih != 0) {
      pcStack_1e4 = &_ITM_registerTMCloneTable;
      do {
        while( true ) {
          CRYPTO_THREADID_current(pCStack_120);
          puStack_130 = (undefined *)(**(code **)(puStack_f8 + -0x6a34))(amih,pCStack_120);
          iVar4 = amih;
          if (puStack_130 == (undefined *)0x0) goto LAB_004c1f60;
          pCStack_18c = *(CRYPTO_THREADID **)(puStack_130 + 0x14);
          if (pCStack_18c == (CRYPTO_THREADID *)0x0) break;
          pcVar12 = *(code **)(puStack_f8 + -0x79cc);
          pCStack_18c[3].ptr = (void *)((int)pCStack_18c[3].ptr + 1);
          (*pcVar12)(iVar4,pCStack_18c);
          iVar4 = *(int *)(puStack_130 + 0x18);
          *(int *)(puStack_130 + 0x18) = iVar4 + -1;
          if (0 < iVar4 + -1) goto LAB_004c1ec4;
          pvVar5 = pCStack_18c[3].ptr;
          *(undefined4 *)(puStack_130 + 0x14) = 0;
          pCStack_18c[3].ptr = (void *)((int)pvVar5 + -1);
LAB_004c1f44:
          iStack_128 = iStack_128 + 1;
          CRYPTO_free(puStack_130);
          if (amih == 0) goto LAB_004c1f60;
        }
        iVar4 = *(int *)(puStack_130 + 0x18);
        *(int *)(puStack_130 + 0x18) = iVar4 + -1;
        if (iVar4 + -1 < 1) {
          *(undefined4 *)(puStack_130 + 0x14) = 0;
          goto LAB_004c1f44;
        }
LAB_004c1ec4:
        iStack_128 = iStack_128 + 1;
      } while (amih != 0);
    }
LAB_004c1f60:
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
    in_a3 = (char *)0x11a;
    pcVar11 = "mem_dbg.c";
    pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
LAB_004c1e0c:
  if (pCStack_d4 == *(CRYPTO_THREADID **)puStack_11c) {
    return iStack_128;
  }
  pcStack_10c = CRYPTO_dbg_malloc;
  pCStack_188 = pCStack_d4;
  (**(code **)(puStack_f8 + -0x5328))();
  puStack_190 = PTR___stack_chk_guard_006aabf0;
  puStack_114 = &_ITM_registerTMCloneTable;
  puStack_160 = &_gp;
  ptr = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006aabf0;
  pCVar6 = pCVar2;
  num = pcVar11;
  file_00 = in_a3;
  pcStack_184 = pcStack_124;
  pCStack_1ec = pCStack_120;
  pCStack_17c = (CRYPTO_THREADID *)puStack_11c;
  pcStack_1e0 = &_ITM_registerTMCloneTable;
  pCStack_134 = ptr;
  pCStack_12c = pCStack_18c;
  pcStack_118 = pcStack_1e4;
  pcStack_110 = unaff_s8;
  if ((((uint)puStack_f8 & 0x7f) == 1) && (pCStack_188 != (CRYPTO_THREADID *)0x0)) {
    pcStack_184 = &_ITM_registerTMCloneTable;
    if ((mh_mode & 1) != 0) {
      pCStack_158 = aCStack_150;
      CRYPTO_THREADID_current(aCStack_150);
      pcStack_1e4 = "Number";
      CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
      pCStack_1ec = pCVar2;
      pCStack_17c = (CRYPTO_THREADID *)pcVar11;
      pcStack_1e0 = in_a3;
      if ((mh_mode & 2) == 0) {
        pCStack_18c = (CRYPTO_THREADID *)
                      CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_158);
        file_00 = (char *)0x12b;
        num = "mem_dbg.c";
        pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
        ptr = (CRYPTO_THREADID *)&DAT_00000006;
        CRYPTO_lock(6,0x14,"mem_dbg.c",299);
        if (pCStack_18c == (CRYPTO_THREADID *)0x0) goto LAB_004c20cc;
      }
      else {
        CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      }
      CRYPTO_mem_ctrl_constprop_5();
      pCStack_18c = (CRYPTO_THREADID *)CRYPTO_malloc(0x24,"mem_dbg.c",0x1f2);
      if (pCStack_18c == (CRYPTO_THREADID *)0x0) {
        CRYPTO_free(pCStack_188);
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
      }
      else {
        if ((mh == 0) &&
           (mh = (**(code **)(puStack_160 + -0x79d4))(mem_LHASH_HASH,mem_LHASH_COMP), mh == 0)) {
          CRYPTO_free(pCStack_188);
          CRYPTO_free(pCStack_18c);
        }
        else {
          pCStack_18c->ptr = pCStack_188;
          pCStack_18c[1].ptr = pcVar11;
          pCStack_18c[1].val = (ulong)in_a3;
          pCStack_18c->val = (ulong)pCVar2;
          uVar8 = options;
          puStack_154 = &_ITM_registerTMCloneTable;
          if ((options & 2) == 0) {
            *(char *)&pCStack_18c[2].ptr = '\0';
            *(char *)((int)&pCStack_18c[2].ptr + 1) = '\0';
            *(char *)((int)&pCStack_18c[2].ptr + 2) = '\0';
            *(char *)((int)&pCStack_18c[2].ptr + 3) = '\0';
            *(undefined *)&pCStack_18c[2].val = 0;
            *(undefined *)((int)&pCStack_18c[2].val + 1) = 0;
            *(undefined *)((int)&pCStack_18c[2].val + 2) = 0;
            *(undefined *)((int)&pCStack_18c[2].val + 3) = 0;
          }
          else {
            CRYPTO_THREADID_current(pCStack_18c + 2);
            uVar8 = *(uint *)(puStack_154 + -0x4274);
          }
          pCStack_18c[3].ptr = order;
          if ((uVar8 & 1) == 0) {
            order = (void *)((int)order + 1);
            pCStack_18c[3].val = 0;
          }
          else {
            order = (void *)((int)order + 1);
            uVar3 = (**(code **)(puStack_160 + -0x52fc))(0);
            pCStack_18c[3].val = uVar3;
          }
          pCStack_188 = pCStack_158;
          CRYPTO_THREADID_current(pCStack_158);
          pCStack_18c[4].ptr = (void *)0x0;
          if ((amih != 0) &&
             (pvVar5 = (void *)(**(code **)(puStack_160 + -0x7a30))(amih,pCStack_188),
             pvVar5 != (void *)0x0)) {
            iVar4 = *(int *)((int)pvVar5 + 0x18);
            pCStack_18c[4].ptr = pvVar5;
            *(int *)((int)pvVar5 + 0x18) = iVar4 + 1;
          }
          pvVar5 = (void *)(**(code **)(puStack_160 + -0x79cc))(mh,pCStack_18c);
          if (pvVar5 != (void *)0x0) {
            iVar4 = *(int *)((int)pvVar5 + 0x20);
            if (iVar4 != 0) {
              *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + -1;
            }
            CRYPTO_free(pvVar5);
          }
        }
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
      }
      if ((((mh_mode & 1) != 0) && (num_disable != 0)) &&
         (num_disable = num_disable - 1, num_disable == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
      }
      file_00 = (char *)0x11a;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      ptr = (CRYPTO_THREADID *)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
    }
  }
LAB_004c20cc:
  pCVar2 = *(CRYPTO_THREADID **)puStack_190;
  if (pCStack_134 == pCVar2) {
    return (int)pCVar2;
  }
  pcStack_174 = CRYPTO_dbg_free;
  (**(code **)(puStack_160 + -0x5328))();
  puStack_1fc = PTR___stack_chk_guard_006aabf0;
  puStack_1c8 = &_gp;
  iStack_194 = *(int *)PTR___stack_chk_guard_006aabf0;
  pCStackY_258 = ptr;
  pCStack_1f8 = pCStack_18c;
  pCStack_1f4 = pCStack_188;
  pcStackY_254 = pcStack_184;
  pCStack_1e8 = pCStack_17c;
  pCStack_180 = pCStack_1ec;
  pcStack_178 = pcStack_1e4;
  if (((pCVar6 == (CRYPTO_THREADID *)0x0) && (pCStack_1f8 = ptr, ptr != (CRYPTO_THREADID *)0x0)) &&
     (pCStack_1f4 = (CRYPTO_THREADID *)&_ITM_registerTMCloneTable, (mh_mode & 1) != 0)) {
    pCStack_1e8 = aCStack_1b8;
    pcStackY_254 = "Number";
    CRYPTO_THREADID_current(pCStack_1e8);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
    if ((mh_mode & 2) == 0) {
      pCStack_1ec = (CRYPTO_THREADID *)
                    CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_1e8);
      file_00 = (char *)0x12b;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_258 = (CRYPTO_THREADID *)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      if (pCStack_1ec == (CRYPTO_THREADID *)0x0) goto LAB_004c24ac;
    }
    else {
      file_00 = (char *)0x12b;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_258 = (CRYPTO_THREADID *)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    }
    pCStack_1ec = (CRYPTO_THREADID *)&_ITM_registerTMCloneTable;
    if (mh != 0) {
      CRYPTO_mem_ctrl_constprop_5();
      aCStack_1b8[0].ptr = ptr;
      pvVar5 = (void *)(**(code **)(puStack_1c8 + -0x6a34))(mh,pCStack_1e8);
      if (pvVar5 != (void *)0x0) {
        ptr = *(CRYPTO_THREADID **)((int)pvVar5 + 0x20);
        if ((ptr != (CRYPTO_THREADID *)0x0) &&
           (pvVar10 = (void *)((int)ptr[3].ptr + -1), ptr[3].ptr = pvVar10, (int)pvVar10 < 1)) {
          pCStack_1ec = (CRYPTO_THREADID *)ptr[2].val;
          pvStack_1bc = pvVar5;
          if ((pCStack_1ec != (CRYPTO_THREADID *)0x0) &&
             (pvVar5 = (void *)((int)pCStack_1ec[3].ptr + -1), pCStack_1ec[3].ptr = pvVar5,
             (int)pvVar5 < 1)) {
            pCStack_1e8 = (CRYPTO_THREADID *)pCStack_1ec[2].val;
            if ((pCStack_1e8 != (CRYPTO_THREADID *)0x0) &&
               (pvVar5 = (void *)((int)pCStack_1e8[3].ptr + -1), pCStack_1e8[3].ptr = pvVar5,
               (int)pvVar5 < 1)) {
              pcStack_1e4 = (char *)pCStack_1e8[2].val;
              if ((pcStack_1e4 != (char *)0x0) &&
                 (iVar4 = *(int *)(pcStack_1e4 + 0x18), *(int *)(pcStack_1e4 + 0x18) = iVar4 + -1,
                 iVar4 + -1 < 1)) {
                if (*(int *)(pcStack_1e4 + 0x14) != 0) {
                  app_info_free();
                }
                CRYPTO_free(pcStack_1e4);
              }
              CRYPTO_free(pCStack_1e8);
            }
            CRYPTO_free(pCStack_1ec);
          }
          CRYPTO_free(ptr);
          pvVar5 = pvStack_1bc;
        }
        CRYPTO_free(pvVar5);
      }
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
      if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
         (num_disable = uVar8, uVar8 == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
      }
      file_00 = (char *)0x11a;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_258 = (CRYPTO_THREADID *)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      pCStack_1f8 = ptr;
    }
  }
LAB_004c24ac:
  iVar4 = *(int *)puStack_1fc;
  if (iStack_194 == iVar4) {
    return iVar4;
  }
  pcStack_1dc = CRYPTO_dbg_realloc;
  (**(code **)(puStack_1c8 + -0x5328))();
  puStackY_260 = PTR___stack_chk_guard_006aabf0;
  pCStack_204 = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006aabf0;
  pCVar2 = pCStack_204;
  pCStackY_25c = pCStack_1f8;
  pCStackY_250 = pCStack_1ec;
  pcStack_1f0 = pcStackY_254;
  if ((iStack_1c4 == 1) && (pCStackY_25c = pCVar6, pCVar6 != (CRYPTO_THREADID *)0x0)) {
    pCStackY_250 = (CRYPTO_THREADID *)num;
    if (pCStackY_258 == (CRYPTO_THREADID *)0x0) {
      pCVar2 = pCVar6;
      CRYPTO_dbg_malloc(pCVar6,(int)num,file_00,(int)puStack_1c8,0x81);
    }
    else {
      pcStackY_254 = &_ITM_registerTMCloneTable;
      if ((mh_mode & 1) != 0) {
        CRYPTO_THREADID_current(aCStack_228);
        CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
        if ((mh_mode & 2) == 0) {
          iVar4 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_228);
          pCVar2 = (CRYPTO_THREADID *)&DAT_00000006;
          CRYPTO_lock(6,0x14,"mem_dbg.c",299);
          if (iVar4 == 0) goto LAB_004c27cc;
        }
        else {
          CRYPTO_lock(6,0x14,"mem_dbg.c",299);
        }
        CRYPTO_mem_ctrl_constprop_5();
        aCStack_228[0].ptr = pCStackY_258;
        ppCVar7 = (CRYPTO_THREADID **)(*(code *)PTR_lh_delete_006a94ac)(mh,aCStack_228);
        uVar8 = mh;
        puVar1 = PTR_lh_insert_006a8514;
        if (ppCVar7 != (CRYPTO_THREADID **)0x0) {
          *ppCVar7 = pCVar6;
          ppCVar7[1] = (CRYPTO_THREADID *)num;
          (*(code *)puVar1)(uVar8,ppCVar7);
        }
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
        if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
           (num_disable = uVar8, uVar8 == 0)) {
          mh_mode = mh_mode | 2;
          CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
        }
        pCVar2 = (CRYPTO_THREADID *)&DAT_0000000a;
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      }
    }
  }
LAB_004c27cc:
  pCVar6 = *(CRYPTO_THREADID **)puStackY_260;
  if (pCStack_204 == pCVar6) {
    return (int)pCVar6;
  }
  pcStackY_24c = CRYPTO_mem_leaks;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStackY_264 = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((mh != 0) || (amih != 0)) {
    CRYPTO_mem_ctrl_constprop_5();
    uStackY_268 = 0;
    iStackY_26c = 0;
    pCStackY_270 = pCVar2;
    if ((mh == 0) ||
       ((*(code *)PTR_lh_doall_arg_006a94bc)(mh,print_leak_LHASH_DOALL_ARG,&pCStackY_270),
       iStackY_26c == 0)) {
      CRYPTO_lock(9,0x14,"mem_dbg.c",0x31e);
      uVar8 = mh_mode;
      mh_mode = 0;
      if (mh != 0) {
        (*(code *)PTR_lh_free_006a8518)();
        mh = 0;
      }
      if ((amih != 0) && (iVar4 = (*(code *)PTR_lh_num_items_006a9450)(), iVar4 == 0)) {
        (*(code *)PTR_lh_free_006a8518)(amih);
        amih = 0;
      }
      mh_mode = uVar8;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x334);
    }
    else {
      (*(code *)PTR_BIO_printf_006a7f38)(pCVar2,"%ld bytes leaked in %d chunks\n",uStackY_268);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
    pCVar2 = (CRYPTO_THREADID *)&DAT_0000000a;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
  if (iStackY_264 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar8 = mh;
    if (mh != 0) {
      CRYPTO_mem_ctrl_constprop_5();
      uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      bio = (bio_st *)(*(code *)PTR_BIO_new_006a7fa4)(uVar9);
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
      uVar8 = mh_mode & 1;
      if (((uVar8 == 0) || (uVar8 = num_disable - 1, num_disable == 0)) ||
         (num_disable = uVar8, uVar8 != 0)) {
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      }
      else {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      }
      if (bio != (bio_st *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0x6a,0,pCVar2);
        CRYPTO_mem_leaks(bio);
                    /* WARNING: Could not recover jumptable at 0x004c2cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar4 = (*(code *)PTR_BIO_free_006a7f70)(bio);
        return iVar4;
      }
    }
    return uVar8;
  }
  return *(int *)puVar1;
}

