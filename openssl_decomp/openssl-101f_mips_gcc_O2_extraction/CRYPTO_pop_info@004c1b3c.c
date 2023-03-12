
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_pop_info(void)

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
  char *unaff_s3;
  CRYPTO_THREADID *unaff_s4;
  undefined1 *unaff_s5;
  char *unaff_s6;
  code *pcVar12;
  char *unaff_s8;
  CRYPTO_THREADID *pCStackY_220;
  int iStackY_21c;
  undefined4 uStackY_218;
  int iStackY_214;
  undefined *puStackY_210;
  CRYPTO_THREADID *pCStackY_20c;
  CRYPTO_THREADID *pCStackY_208;
  char *pcStackY_204;
  CRYPTO_THREADID *pCStackY_200;
  code *pcStackY_1fc;
  CRYPTO_THREADID aCStack_1d8 [4];
  CRYPTO_THREADID *pCStack_1b4;
  undefined *puStack_1ac;
  CRYPTO_THREADID *pCStack_1a8;
  CRYPTO_THREADID *pCStack_1a4;
  char *pcStack_1a0;
  CRYPTO_THREADID *pCStack_19c;
  CRYPTO_THREADID *pCStack_198;
  char *pcStack_194;
  char *pcStack_190;
  code *pcStack_18c;
  undefined *puStack_178;
  int iStack_174;
  void *pvStack_16c;
  CRYPTO_THREADID aCStack_168 [4];
  int iStack_144;
  undefined *puStack_140;
  CRYPTO_THREADID *pCStack_13c;
  CRYPTO_THREADID *pCStack_138;
  char *pcStack_134;
  CRYPTO_THREADID *pCStack_130;
  CRYPTO_THREADID *pCStack_12c;
  char *pcStack_128;
  code *pcStack_124;
  undefined *puStack_110;
  CRYPTO_THREADID *pCStack_108;
  undefined1 *puStack_104;
  CRYPTO_THREADID aCStack_100 [3];
  CRYPTO_THREADID *pCStack_e4;
  undefined *puStack_e0;
  CRYPTO_THREADID *pCStack_dc;
  int iStack_d8;
  char *pcStack_d4;
  CRYPTO_THREADID *pCStack_d0;
  undefined *puStack_cc;
  char *pcStack_c8;
  undefined1 *puStack_c4;
  char *pcStack_c0;
  code *pcStack_bc;
  undefined *puStack_a8;
  CRYPTO_THREADID aCStack_a0 [3];
  CRYPTO_THREADID *pCStack_84;
  undefined *puStack_80;
  undefined1 *puStack_7c;
  int iStack_78;
  char *pcStack_74;
  CRYPTO_THREADID *pCStack_70;
  undefined1 *puStack_6c;
  CRYPTO_THREADID aCStack_40 [3];
  int local_24;
  
  puStack_e0 = PTR___stack_chk_guard_006aabf0;
  pCStack_13c = (CRYPTO_THREADID *)&_ITM_registerTMCloneTable;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_78 = 0;
  if ((mh_mode & 1) != 0) {
    unaff_s3 = "x";
    CRYPTO_THREADID_current(aCStack_40);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
    if ((mh_mode & 2) == 0) {
      unaff_s4 = (CRYPTO_THREADID *)
                 CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_40);
      in_a3 = (char *)0x12b;
      in_a2 = "mem_dbg.c";
      in_a1 = (CRYPTO_THREADID *)&DAT_00000014;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      if (unaff_s4 == (CRYPTO_THREADID *)0x0) {
        iStack_78 = 0;
        goto LAB_004c1b88;
      }
    }
    else {
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    }
    unaff_s5 = &_ITM_registerTMCloneTable;
    CRYPTO_mem_ctrl_constprop_5();
    if (amih == 0) {
LAB_004c1da0:
      iStack_78 = 0;
    }
    else {
      CRYPTO_THREADID_current(aCStack_40);
      pvVar5 = (void *)(*(code *)PTR_lh_delete_006a94ac)(amih,aCStack_40);
      iVar4 = amih;
      puVar1 = PTR_lh_insert_006a8514;
      if (pvVar5 == (void *)0x0) goto LAB_004c1da0;
      unaff_s4 = *(CRYPTO_THREADID **)((int)pvVar5 + 0x14);
      if (unaff_s4 == (CRYPTO_THREADID *)0x0) {
        iVar4 = *(int *)((int)pvVar5 + 0x18) + -1;
        *(int *)((int)pvVar5 + 0x18) = iVar4;
        if (0 < iVar4) goto LAB_004c1c8c;
        *(undefined4 *)((int)pvVar5 + 0x14) = 0;
LAB_004c1d2c:
        iStack_78 = 1;
        CRYPTO_free(pvVar5);
      }
      else {
        unaff_s4[3].ptr = (void *)((int)unaff_s4[3].ptr + 1);
        (*(code *)puVar1)(iVar4,unaff_s4);
        iVar4 = *(int *)((int)pvVar5 + 0x18) + -1;
        *(int *)((int)pvVar5 + 0x18) = iVar4;
        if (iVar4 < 1) {
          pvVar10 = unaff_s4[3].ptr;
          *(undefined4 *)((int)pvVar5 + 0x14) = 0;
          unaff_s4[3].ptr = (void *)((int)pvVar10 + -1);
          goto LAB_004c1d2c;
        }
LAB_004c1c8c:
        iStack_78 = 1;
      }
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
    in_a3 = (char *)0x11a;
    in_a2 = "mem_dbg.c";
    in_a1 = (CRYPTO_THREADID *)&DAT_00000014;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
LAB_004c1b88:
  if (local_24 == *(int *)puStack_e0) {
    return iStack_78;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_cc = PTR___stack_chk_guard_006aabf0;
  puStack_7c = &_ITM_registerTMCloneTable;
  puStack_80 = puStack_e0;
  puStack_a8 = &_gp;
  pCStack_84 = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006aabf0;
  iStack_d8 = 0;
  pCStack_d0 = unaff_s4;
  pcStack_74 = unaff_s3;
  pCStack_70 = unaff_s4;
  puStack_6c = unaff_s5;
  if ((mh_mode & 1) != 0) {
    pCStack_d0 = aCStack_a0;
    unaff_s8 = "x";
    CRYPTO_THREADID_current(pCStack_d0);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
    if ((mh_mode & 2) == 0) {
      puStack_e0 = (undefined *)
                   CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_d0);
      in_a3 = (char *)0x12b;
      in_a2 = "mem_dbg.c";
      in_a1 = (CRYPTO_THREADID *)&DAT_00000014;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      if (puStack_e0 == (undefined *)0x0) {
        iStack_d8 = 0;
        goto LAB_004c1e0c;
      }
    }
    else {
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    }
    unaff_s3 = &_ITM_registerTMCloneTable;
    CRYPTO_mem_ctrl_constprop_5();
    iStack_d8 = 0;
    if (amih != 0) {
      unaff_s6 = &_ITM_registerTMCloneTable;
      do {
        while( true ) {
          CRYPTO_THREADID_current(pCStack_d0);
          puStack_e0 = (undefined *)(**(code **)(puStack_a8 + -0x6a34))(amih,pCStack_d0);
          iVar4 = amih;
          if (puStack_e0 == (undefined *)0x0) goto LAB_004c1f60;
          pCStack_13c = *(CRYPTO_THREADID **)(puStack_e0 + 0x14);
          if (pCStack_13c == (CRYPTO_THREADID *)0x0) break;
          pcVar12 = *(code **)(puStack_a8 + -0x79cc);
          pCStack_13c[3].ptr = (void *)((int)pCStack_13c[3].ptr + 1);
          (*pcVar12)(iVar4,pCStack_13c);
          iVar4 = *(int *)(puStack_e0 + 0x18);
          *(int *)(puStack_e0 + 0x18) = iVar4 + -1;
          if (0 < iVar4 + -1) goto LAB_004c1ec4;
          pvVar5 = pCStack_13c[3].ptr;
          *(undefined4 *)(puStack_e0 + 0x14) = 0;
          pCStack_13c[3].ptr = (void *)((int)pvVar5 + -1);
LAB_004c1f44:
          iStack_d8 = iStack_d8 + 1;
          CRYPTO_free(puStack_e0);
          if (amih == 0) goto LAB_004c1f60;
        }
        iVar4 = *(int *)(puStack_e0 + 0x18);
        *(int *)(puStack_e0 + 0x18) = iVar4 + -1;
        if (iVar4 + -1 < 1) {
          *(undefined4 *)(puStack_e0 + 0x14) = 0;
          goto LAB_004c1f44;
        }
LAB_004c1ec4:
        iStack_d8 = iStack_d8 + 1;
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
    in_a2 = "mem_dbg.c";
    in_a1 = (CRYPTO_THREADID *)&DAT_00000014;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
LAB_004c1e0c:
  if (pCStack_84 == *(CRYPTO_THREADID **)puStack_cc) {
    return iStack_d8;
  }
  pcStack_bc = CRYPTO_dbg_malloc;
  pCStack_138 = pCStack_84;
  (**(code **)(puStack_a8 + -0x5328))();
  puStack_140 = PTR___stack_chk_guard_006aabf0;
  puStack_c4 = &_ITM_registerTMCloneTable;
  puStack_110 = &_gp;
  pCVar11 = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006aabf0;
  pCVar6 = in_a1;
  num = in_a2;
  file = in_a3;
  pcStack_134 = unaff_s3;
  pCStack_19c = pCStack_d0;
  pCStack_12c = (CRYPTO_THREADID *)puStack_cc;
  pcStack_190 = &_ITM_registerTMCloneTable;
  pCStack_e4 = pCVar11;
  pCStack_dc = pCStack_13c;
  pcStack_d4 = unaff_s3;
  pcStack_c8 = unaff_s6;
  pcStack_c0 = unaff_s8;
  if ((((uint)puStack_a8 & 0x7f) == 1) && (pCStack_138 != (CRYPTO_THREADID *)0x0)) {
    pcStack_134 = &_ITM_registerTMCloneTable;
    if ((mh_mode & 1) != 0) {
      pCStack_108 = aCStack_100;
      CRYPTO_THREADID_current(aCStack_100);
      unaff_s6 = "x";
      CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
      pCStack_19c = in_a1;
      pCStack_12c = (CRYPTO_THREADID *)in_a2;
      pcStack_190 = in_a3;
      if ((mh_mode & 2) == 0) {
        pCStack_13c = (CRYPTO_THREADID *)
                      CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_108);
        file = (char *)0x12b;
        num = "mem_dbg.c";
        pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
        pCVar11 = (CRYPTO_THREADID *)&DAT_00000006;
        CRYPTO_lock(6,0x14,"mem_dbg.c",299);
        if (pCStack_13c == (CRYPTO_THREADID *)0x0) goto LAB_004c20cc;
      }
      else {
        CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      }
      CRYPTO_mem_ctrl_constprop_5();
      pCStack_13c = (CRYPTO_THREADID *)CRYPTO_malloc(0x24,"mem_dbg.c",0x1f2);
      if (pCStack_13c == (CRYPTO_THREADID *)0x0) {
        CRYPTO_free(pCStack_138);
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
      }
      else {
        if ((mh == 0) &&
           (mh = (**(code **)(puStack_110 + -0x79d4))(mem_LHASH_HASH,mem_LHASH_COMP), mh == 0)) {
          CRYPTO_free(pCStack_138);
          CRYPTO_free(pCStack_13c);
        }
        else {
          pCStack_13c->ptr = pCStack_138;
          pCStack_13c[1].ptr = in_a2;
          pCStack_13c[1].val = (ulong)in_a3;
          pCStack_13c->val = (ulong)in_a1;
          uVar8 = options;
          puStack_104 = &_ITM_registerTMCloneTable;
          if ((options & 2) == 0) {
            *(char *)&pCStack_13c[2].ptr = '\0';
            *(char *)((int)&pCStack_13c[2].ptr + 1) = '\0';
            *(char *)((int)&pCStack_13c[2].ptr + 2) = '\0';
            *(char *)((int)&pCStack_13c[2].ptr + 3) = '\0';
            *(undefined *)&pCStack_13c[2].val = 0;
            *(undefined *)((int)&pCStack_13c[2].val + 1) = 0;
            *(undefined *)((int)&pCStack_13c[2].val + 2) = 0;
            *(undefined *)((int)&pCStack_13c[2].val + 3) = 0;
          }
          else {
            CRYPTO_THREADID_current(pCStack_13c + 2);
            uVar8 = *(uint *)(puStack_104 + -0x4274);
          }
          pCStack_13c[3].ptr = order;
          if ((uVar8 & 1) == 0) {
            order = (void *)((int)order + 1);
            pCStack_13c[3].val = 0;
          }
          else {
            order = (void *)((int)order + 1);
            uVar3 = (**(code **)(puStack_110 + -0x52fc))(0);
            pCStack_13c[3].val = uVar3;
          }
          pCStack_138 = pCStack_108;
          CRYPTO_THREADID_current(pCStack_108);
          pCStack_13c[4].ptr = (void *)0x0;
          if ((amih != 0) &&
             (pvVar5 = (void *)(**(code **)(puStack_110 + -0x7a30))(amih,pCStack_138),
             pvVar5 != (void *)0x0)) {
            iVar4 = *(int *)((int)pvVar5 + 0x18);
            pCStack_13c[4].ptr = pvVar5;
            *(int *)((int)pvVar5 + 0x18) = iVar4 + 1;
          }
          pvVar5 = (void *)(**(code **)(puStack_110 + -0x79cc))(mh,pCStack_13c);
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
      file = (char *)0x11a;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCVar11 = (CRYPTO_THREADID *)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
    }
  }
LAB_004c20cc:
  pCVar2 = *(CRYPTO_THREADID **)puStack_140;
  if (pCStack_e4 == pCVar2) {
    return (int)pCVar2;
  }
  pcStack_124 = CRYPTO_dbg_free;
  (**(code **)(puStack_110 + -0x5328))();
  puStack_1ac = PTR___stack_chk_guard_006aabf0;
  puStack_178 = &_gp;
  iStack_144 = *(int *)PTR___stack_chk_guard_006aabf0;
  pCStackY_208 = pCVar11;
  pCStack_1a8 = pCStack_13c;
  pCStack_1a4 = pCStack_138;
  pcStackY_204 = pcStack_134;
  pCStack_198 = pCStack_12c;
  pCStack_130 = pCStack_19c;
  pcStack_128 = unaff_s6;
  if (((pCVar6 == (CRYPTO_THREADID *)0x0) &&
      (pCStack_1a8 = pCVar11, pCVar11 != (CRYPTO_THREADID *)0x0)) &&
     (pCStack_1a4 = (CRYPTO_THREADID *)&_ITM_registerTMCloneTable, (mh_mode & 1) != 0)) {
    pCStack_198 = aCStack_168;
    pcStackY_204 = "x";
    CRYPTO_THREADID_current(pCStack_198);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
    if ((mh_mode & 2) == 0) {
      pCStack_19c = (CRYPTO_THREADID *)
                    CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_198);
      file = (char *)0x12b;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_208 = (CRYPTO_THREADID *)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
      if (pCStack_19c == (CRYPTO_THREADID *)0x0) goto LAB_004c24ac;
    }
    else {
      file = (char *)0x12b;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_208 = (CRYPTO_THREADID *)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",299);
    }
    pCStack_19c = (CRYPTO_THREADID *)&_ITM_registerTMCloneTable;
    if (mh != 0) {
      CRYPTO_mem_ctrl_constprop_5();
      aCStack_168[0].ptr = pCVar11;
      pvVar5 = (void *)(**(code **)(puStack_178 + -0x6a34))(mh,pCStack_198);
      if (pvVar5 != (void *)0x0) {
        pCVar11 = *(CRYPTO_THREADID **)((int)pvVar5 + 0x20);
        if ((pCVar11 != (CRYPTO_THREADID *)0x0) &&
           (pvVar10 = (void *)((int)pCVar11[3].ptr + -1), pCVar11[3].ptr = pvVar10, (int)pvVar10 < 1
           )) {
          pCStack_19c = (CRYPTO_THREADID *)pCVar11[2].val;
          pvStack_16c = pvVar5;
          if ((pCStack_19c != (CRYPTO_THREADID *)0x0) &&
             (pvVar5 = (void *)((int)pCStack_19c[3].ptr + -1), pCStack_19c[3].ptr = pvVar5,
             (int)pvVar5 < 1)) {
            pCStack_198 = (CRYPTO_THREADID *)pCStack_19c[2].val;
            if ((pCStack_198 != (CRYPTO_THREADID *)0x0) &&
               (pvVar5 = (void *)((int)pCStack_198[3].ptr + -1), pCStack_198[3].ptr = pvVar5,
               (int)pvVar5 < 1)) {
              unaff_s6 = (char *)pCStack_198[2].val;
              if ((unaff_s6 != (char *)0x0) &&
                 (iVar4 = *(int *)(unaff_s6 + 0x18), *(int *)(unaff_s6 + 0x18) = iVar4 + -1,
                 iVar4 + -1 < 1)) {
                if (*(int *)(unaff_s6 + 0x14) != 0) {
                  app_info_free();
                }
                CRYPTO_free(unaff_s6);
              }
              CRYPTO_free(pCStack_198);
            }
            CRYPTO_free(pCStack_19c);
          }
          CRYPTO_free(pCVar11);
          pvVar5 = pvStack_16c;
        }
        CRYPTO_free(pvVar5);
      }
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
      if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
         (num_disable = uVar8, uVar8 == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
      }
      file = (char *)0x11a;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_208 = (CRYPTO_THREADID *)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      pCStack_1a8 = pCVar11;
    }
  }
LAB_004c24ac:
  iVar4 = *(int *)puStack_1ac;
  if (iStack_144 == iVar4) {
    return iVar4;
  }
  pcStack_18c = CRYPTO_dbg_realloc;
  (**(code **)(puStack_178 + -0x5328))();
  puStackY_210 = PTR___stack_chk_guard_006aabf0;
  pCStack_1b4 = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006aabf0;
  pCVar11 = pCStack_1b4;
  pCStackY_20c = pCStack_1a8;
  pCStackY_200 = pCStack_19c;
  pcStack_1a0 = pcStackY_204;
  pcStack_194 = unaff_s6;
  if ((iStack_174 == 1) && (pCStackY_20c = pCVar6, pCVar6 != (CRYPTO_THREADID *)0x0)) {
    pCStackY_200 = (CRYPTO_THREADID *)num;
    if (pCStackY_208 == (CRYPTO_THREADID *)0x0) {
      pCVar11 = pCVar6;
      CRYPTO_dbg_malloc(pCVar6,(int)num,file,(int)puStack_178,0x81);
    }
    else {
      pcStackY_204 = &_ITM_registerTMCloneTable;
      if ((mh_mode & 1) != 0) {
        CRYPTO_THREADID_current(aCStack_1d8);
        CRYPTO_lock(5,0x14,"mem_dbg.c",0x126);
        if ((mh_mode & 2) == 0) {
          iVar4 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_1d8);
          pCVar11 = (CRYPTO_THREADID *)&DAT_00000006;
          CRYPTO_lock(6,0x14,"mem_dbg.c",299);
          if (iVar4 == 0) goto LAB_004c27cc;
        }
        else {
          CRYPTO_lock(6,0x14,"mem_dbg.c",299);
        }
        CRYPTO_mem_ctrl_constprop_5();
        aCStack_1d8[0].ptr = pCStackY_208;
        ppCVar7 = (CRYPTO_THREADID **)(*(code *)PTR_lh_delete_006a94ac)(mh,aCStack_1d8);
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
        pCVar11 = (CRYPTO_THREADID *)&DAT_0000000a;
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
      }
    }
  }
LAB_004c27cc:
  pCVar6 = *(CRYPTO_THREADID **)puStackY_210;
  if (pCStack_1b4 == pCVar6) {
    return (int)pCVar6;
  }
  pcStackY_1fc = CRYPTO_mem_leaks;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStackY_214 = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((mh != 0) || (amih != 0)) {
    CRYPTO_mem_ctrl_constprop_5();
    uStackY_218 = 0;
    iStackY_21c = 0;
    pCStackY_220 = pCVar11;
    if ((mh == 0) ||
       ((*(code *)PTR_lh_doall_arg_006a94bc)(mh,print_leak_LHASH_DOALL_ARG,&pCStackY_220),
       iStackY_21c == 0)) {
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
      (*(code *)PTR_BIO_printf_006a7f38)(pCVar11,"%ld bytes leaked in %d chunks\n",uStackY_218);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xdc);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x111);
    }
    pCVar11 = (CRYPTO_THREADID *)&DAT_0000000a;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x11a);
  }
  if (iStackY_214 != *(int *)puVar1) {
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
        (*(code *)PTR_BIO_ctrl_006a7f18)(bio,0x6a,0,pCVar11);
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

