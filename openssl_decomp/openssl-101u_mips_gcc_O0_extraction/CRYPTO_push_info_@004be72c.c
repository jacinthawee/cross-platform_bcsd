
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
  undefined *unaff_s7;
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
  undefined *puStack_154;
  CRYPTO_THREADID aCStack_150 [3];
  CRYPTO_THREADID *pCStack_134;
  undefined *puStack_130;
  CRYPTO_THREADID *pCStack_12c;
  int iStack_128;
  char *pcStack_124;
  CRYPTO_THREADID *pCStack_120;
  undefined *puStack_11c;
  char *pcStack_118;
  undefined *puStack_114;
  char *pcStack_110;
  code *pcStack_10c;
  undefined *puStack_f8;
  CRYPTO_THREADID aCStack_f0 [3];
  CRYPTO_THREADID *pCStack_d4;
  undefined *puStack_d0;
  undefined *puStack_cc;
  int iStack_c8;
  char *pcStack_c4;
  CRYPTO_THREADID *pCStack_c0;
  char *pcStack_bc;
  char *pcStack_b8;
  undefined *puStack_b4;
  CRYPTO_THREADID aCStack_90 [3];
  int iStack_74;
  CRYPTO_THREADID *pCStack_6c;
  undefined *puStack_68;
  undefined *puStack_64;
  char *pcStack_60;
  CRYPTO_THREADID *pCStack_5c;
  char *pcStack_58;
  code *pcStack_54;
  undefined *local_40;
  CRYPTO_THREADID CStack_34;
  int local_2c;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  local_40 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pCVar2 = (CRYPTO_THREADID *)file;
  pcVar11 = (char *)line;
  pCStack_c0 = unaff_s4;
  pcStack_bc = unaff_s5;
  pcStack_1e4 = unaff_s6;
  if ((mh_mode & 1) != 0) {
    CRYPTO_THREADID_current(&CStack_34);
    unaff_s3 = "TBEX";
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    pCStack_c0 = (CRYPTO_THREADID *)info;
    pcStack_bc = file;
    pcStack_1e4 = (char *)line;
    if ((mh_mode & 2) == 0) {
      unaff_s0 = (CRYPTO_THREADID *)
                 CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_34);
      in_a3 = (char *)0x122;
      pcVar11 = "mem_dbg.c";
      pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (unaff_s0 == (CRYPTO_THREADID *)0x0) goto LAB_004be780;
    }
    else {
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    CRYPTO_mem_ctrl_constprop_5();
    unaff_s0 = (CRYPTO_THREADID *)CRYPTO_malloc(0x1c,"mem_dbg.c",0x18d);
    if (unaff_s0 != (CRYPTO_THREADID *)0x0) {
      unaff_s7 = &_gp_1;
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
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    in_a3 = (char *)0x112;
    pcVar11 = "mem_dbg.c";
    pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
LAB_004be780:
  if (local_2c == *(int *)puStack_68) {
    return 0;
  }
  pcStack_54 = CRYPTO_pop_info;
  (**(code **)(local_40 + -0x5330))();
  puStack_130 = PTR___stack_chk_guard_006a9ae8;
  pCStack_18c = (CRYPTO_THREADID *)&_gp_1;
  puStack_64 = &_gp_1;
  iStack_74 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_c8 = 0;
  pcStack_124 = unaff_s3;
  pCStack_6c = unaff_s0;
  pcStack_60 = unaff_s3;
  pCStack_5c = pCStack_c0;
  pcStack_58 = pcStack_bc;
  if ((mh_mode & 1) != 0) {
    pcStack_124 = "TBEX";
    CRYPTO_THREADID_current(aCStack_90);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((mh_mode & 2) == 0) {
      pCStack_c0 = (CRYPTO_THREADID *)
                   CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_90);
      in_a3 = (char *)0x122;
      pcVar11 = "mem_dbg.c";
      pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (pCStack_c0 == (CRYPTO_THREADID *)0x0) {
        iStack_c8 = 0;
        goto LAB_004be9f8;
      }
    }
    else {
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    pcStack_bc = &_gp_1;
    CRYPTO_mem_ctrl_constprop_5();
    if (amih == 0) {
LAB_004bec10:
      iStack_c8 = 0;
    }
    else {
      CRYPTO_THREADID_current(aCStack_90);
      pvVar5 = (void *)(*(code *)PTR_lh_delete_006a8390)(amih,aCStack_90);
      iVar4 = amih;
      puVar1 = PTR_lh_insert_006a7414;
      if (pvVar5 == (void *)0x0) goto LAB_004bec10;
      pCStack_c0 = *(CRYPTO_THREADID **)((int)pvVar5 + 0x14);
      if (pCStack_c0 == (CRYPTO_THREADID *)0x0) {
        iVar4 = *(int *)((int)pvVar5 + 0x18) + -1;
        *(int *)((int)pvVar5 + 0x18) = iVar4;
        if (0 < iVar4) goto LAB_004beafc;
        *(undefined4 *)((int)pvVar5 + 0x14) = 0;
LAB_004beb9c:
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
          goto LAB_004beb9c;
        }
LAB_004beafc:
        iStack_c8 = 1;
      }
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    in_a3 = (char *)0x112;
    pcVar11 = "mem_dbg.c";
    pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
LAB_004be9f8:
  if (iStack_74 == *(int *)puStack_130) {
    return iStack_c8;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_11c = PTR___stack_chk_guard_006a9ae8;
  puStack_cc = &_gp_1;
  puStack_d0 = puStack_130;
  puStack_f8 = &_gp;
  pCStack_d4 = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006a9ae8;
  iStack_128 = 0;
  pCStack_120 = pCStack_c0;
  pcStack_c4 = pcStack_124;
  pcStack_b8 = pcStack_1e4;
  puStack_b4 = unaff_s7;
  if ((mh_mode & 1) != 0) {
    pCStack_120 = aCStack_f0;
    unaff_s8 = "TBEX";
    CRYPTO_THREADID_current(pCStack_120);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((mh_mode & 2) == 0) {
      puStack_130 = (undefined *)
                    CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_120);
      in_a3 = (char *)0x122;
      pcVar11 = "mem_dbg.c";
      pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (puStack_130 == (undefined *)0x0) {
        iStack_128 = 0;
        goto LAB_004bec7c;
      }
    }
    else {
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    pcStack_124 = &_gp_1;
    CRYPTO_mem_ctrl_constprop_5();
    iStack_128 = 0;
    if (amih != 0) {
      pcStack_1e4 = &_gp_1;
      do {
        while( true ) {
          CRYPTO_THREADID_current(pCStack_120);
          puStack_130 = (undefined *)(**(code **)(puStack_f8 + -0x6a50))(amih,pCStack_120);
          iVar4 = amih;
          if (puStack_130 == (undefined *)0x0) goto LAB_004bedd0;
          pCStack_18c = *(CRYPTO_THREADID **)(puStack_130 + 0x14);
          if (pCStack_18c == (CRYPTO_THREADID *)0x0) break;
          pcVar12 = *(code **)(puStack_f8 + -0x79cc);
          pCStack_18c[3].ptr = (void *)((int)pCStack_18c[3].ptr + 1);
          (*pcVar12)(iVar4,pCStack_18c);
          iVar4 = *(int *)(puStack_130 + 0x18);
          *(int *)(puStack_130 + 0x18) = iVar4 + -1;
          if (0 < iVar4 + -1) goto LAB_004bed34;
          pvVar5 = pCStack_18c[3].ptr;
          *(undefined4 *)(puStack_130 + 0x14) = 0;
          pCStack_18c[3].ptr = (void *)((int)pvVar5 + -1);
LAB_004bedb4:
          iStack_128 = iStack_128 + 1;
          CRYPTO_free(puStack_130);
          if (amih == 0) goto LAB_004bedd0;
        }
        iVar4 = *(int *)(puStack_130 + 0x18);
        *(int *)(puStack_130 + 0x18) = iVar4 + -1;
        if (iVar4 + -1 < 1) {
          *(undefined4 *)(puStack_130 + 0x14) = 0;
          goto LAB_004bedb4;
        }
LAB_004bed34:
        iStack_128 = iStack_128 + 1;
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
    pcVar11 = "mem_dbg.c";
    pCVar2 = (CRYPTO_THREADID *)&DAT_00000014;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
LAB_004bec7c:
  if (pCStack_d4 == *(CRYPTO_THREADID **)puStack_11c) {
    return iStack_128;
  }
  pcStack_10c = CRYPTO_dbg_malloc;
  pCStack_188 = pCStack_d4;
  (**(code **)(puStack_f8 + -0x5330))();
  puStack_190 = PTR___stack_chk_guard_006a9ae8;
  puStack_114 = &_gp_1;
  puStack_160 = &_gp;
  ptr = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006a9ae8;
  pCVar6 = pCVar2;
  num = pcVar11;
  file_00 = in_a3;
  pcStack_184 = pcStack_124;
  pCStack_1ec = pCStack_120;
  pCStack_17c = (CRYPTO_THREADID *)puStack_11c;
  pcStack_1e0 = &_gp_1;
  pCStack_134 = ptr;
  pCStack_12c = pCStack_18c;
  pcStack_118 = pcStack_1e4;
  pcStack_110 = unaff_s8;
  if ((((uint)puStack_f8 & 0x7f) == 1) && (pCStack_188 != (CRYPTO_THREADID *)0x0)) {
    pcStack_184 = &_gp_1;
    if ((mh_mode & 1) != 0) {
      pCStack_158 = aCStack_150;
      CRYPTO_THREADID_current(aCStack_150);
      pcStack_1e4 = "TBEX";
      CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
      pCStack_1ec = pCVar2;
      pCStack_17c = (CRYPTO_THREADID *)pcVar11;
      pcStack_1e0 = in_a3;
      if ((mh_mode & 2) == 0) {
        pCStack_18c = (CRYPTO_THREADID *)
                      CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_158);
        file_00 = (char *)0x122;
        num = "mem_dbg.c";
        pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
        ptr = (CRYPTO_THREADID *)&DAT_00000006;
        CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
        if (pCStack_18c == (CRYPTO_THREADID *)0x0) goto LAB_004bef3c;
      }
      else {
        CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      }
      CRYPTO_mem_ctrl_constprop_5();
      pCStack_18c = (CRYPTO_THREADID *)CRYPTO_malloc(0x24,"mem_dbg.c",0x1e1);
      if (pCStack_18c == (CRYPTO_THREADID *)0x0) {
        CRYPTO_free(pCStack_188);
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
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
          puStack_154 = &_gp_1;
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
            uVar8 = *(uint *)(puStack_154 + -0x5384);
          }
          pCStack_18c[3].ptr = order;
          if ((uVar8 & 1) == 0) {
            order = (void *)((int)order + 1);
            pCStack_18c[3].val = 0;
          }
          else {
            order = (void *)((int)order + 1);
            uVar3 = (**(code **)(puStack_160 + -0x5304))(0);
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
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      }
      if ((((mh_mode & 1) != 0) && (num_disable != 0)) &&
         (num_disable = num_disable - 1, num_disable == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
      }
      file_00 = (char *)0x112;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      ptr = (CRYPTO_THREADID *)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    }
  }
LAB_004bef3c:
  pCVar2 = *(CRYPTO_THREADID **)puStack_190;
  if (pCStack_134 == pCVar2) {
    return (int)pCVar2;
  }
  pcStack_174 = CRYPTO_dbg_free;
  (**(code **)(puStack_160 + -0x5330))();
  puStack_1fc = PTR___stack_chk_guard_006a9ae8;
  puStack_1c8 = &_gp;
  iStack_194 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pCStackY_258 = ptr;
  pCStack_1f8 = pCStack_18c;
  pCStack_1f4 = pCStack_188;
  pcStackY_254 = pcStack_184;
  pCStack_1e8 = pCStack_17c;
  pCStack_180 = pCStack_1ec;
  pcStack_178 = pcStack_1e4;
  if (((pCVar6 == (CRYPTO_THREADID *)0x0) && (pCStack_1f8 = ptr, ptr != (CRYPTO_THREADID *)0x0)) &&
     (pCStack_1f4 = (CRYPTO_THREADID *)&_gp_1, (mh_mode & 1) != 0)) {
    pCStack_1e8 = aCStack_1b8;
    pcStackY_254 = "TBEX";
    CRYPTO_THREADID_current(pCStack_1e8);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((mh_mode & 2) == 0) {
      pCStack_1ec = (CRYPTO_THREADID *)
                    CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_1e8);
      file_00 = (char *)0x122;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_258 = (CRYPTO_THREADID *)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (pCStack_1ec == (CRYPTO_THREADID *)0x0) goto LAB_004bf31c;
    }
    else {
      file_00 = (char *)0x122;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_258 = (CRYPTO_THREADID *)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    pCStack_1ec = (CRYPTO_THREADID *)&_gp_1;
    if (mh != 0) {
      CRYPTO_mem_ctrl_constprop_5();
      aCStack_1b8[0].ptr = ptr;
      pvVar5 = (void *)(**(code **)(puStack_1c8 + -0x6a50))(mh,pCStack_1e8);
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
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
         (num_disable = uVar8, uVar8 == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
      }
      file_00 = (char *)0x112;
      num = "mem_dbg.c";
      pCVar6 = (CRYPTO_THREADID *)&DAT_00000014;
      pCStackY_258 = (CRYPTO_THREADID *)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      pCStack_1f8 = ptr;
    }
  }
LAB_004bf31c:
  iVar4 = *(int *)puStack_1fc;
  if (iStack_194 == iVar4) {
    return iVar4;
  }
  pcStack_1dc = CRYPTO_dbg_realloc;
  (**(code **)(puStack_1c8 + -0x5330))();
  puStackY_260 = PTR___stack_chk_guard_006a9ae8;
  pCStack_204 = *(CRYPTO_THREADID **)PTR___stack_chk_guard_006a9ae8;
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
      pcStackY_254 = &_gp_1;
      if ((mh_mode & 1) != 0) {
        CRYPTO_THREADID_current(aCStack_228);
        CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
        if ((mh_mode & 2) == 0) {
          iVar4 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_228);
          pCVar2 = (CRYPTO_THREADID *)&DAT_00000006;
          CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
          if (iVar4 == 0) goto LAB_004bf63c;
        }
        else {
          CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
        }
        CRYPTO_mem_ctrl_constprop_5();
        aCStack_228[0].ptr = pCStackY_258;
        ppCVar7 = (CRYPTO_THREADID **)(*(code *)PTR_lh_delete_006a8390)(mh,aCStack_228);
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
        pCVar2 = (CRYPTO_THREADID *)&DAT_0000000a;
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      }
    }
  }
LAB_004bf63c:
  pCVar6 = *(CRYPTO_THREADID **)puStackY_260;
  if (pCStack_204 == pCVar6) {
    return (int)pCVar6;
  }
  pcStackY_24c = CRYPTO_mem_leaks;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStackY_264 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((mh != 0) || (amih != 0)) {
    CRYPTO_mem_ctrl_constprop_5();
    uStackY_268 = 0;
    iStackY_26c = 0;
    pCStackY_270 = pCVar2;
    if ((mh == 0) ||
       ((*(code *)PTR_lh_doall_arg_006a83a0)(mh,print_leak_LHASH_DOALL_ARG,&pCStackY_270),
       iStackY_26c == 0)) {
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
      (*(code *)PTR_BIO_printf_006a6e38)(pCVar2,"%ld bytes leaked in %d chunks\n",uStackY_268);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((mh_mode & 1) != 0) && (uVar8 = num_disable - 1, num_disable != 0)) &&
       (num_disable = uVar8, uVar8 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    pCVar2 = (CRYPTO_THREADID *)&DAT_0000000a;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
  if (iStackY_264 != *(int *)puVar1) {
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
        (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0x6a,0,pCVar2);
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

