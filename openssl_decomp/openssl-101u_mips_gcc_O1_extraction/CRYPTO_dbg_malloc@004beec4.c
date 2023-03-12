
void CRYPTO_dbg_malloc(void *addr,int num,char *file,int line,int before_p)

{
  undefined *puVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  bio_st *bio;
  void *pvVar7;
  void **ppvVar8;
  void **addr_00;
  char *num_00;
  char *file_00;
  void **unaff_s1;
  char *unaff_s3;
  char *unaff_s4;
  CRYPTO_THREADID *unaff_s5;
  char *unaff_s6;
  int unaff_s7;
  void **ppvStackY_168;
  int iStackY_164;
  undefined4 uStackY_160;
  int iStackY_15c;
  undefined *puStackY_158;
  void **ppvStackY_154;
  void **ppvStackY_150;
  char *pcStackY_14c;
  char *pcStackY_148;
  code *pcStackY_144;
  CRYPTO_THREADID aCStack_120 [4];
  void **ppvStack_fc;
  undefined *puStack_f4;
  void **ppvStack_f0;
  CRYPTO_THREADID *pCStack_ec;
  char *pcStack_e8;
  char *pcStack_e4;
  CRYPTO_THREADID *pCStack_e0;
  char *pcStack_dc;
  int iStack_d8;
  code *pcStack_d4;
  undefined *puStack_c0;
  int iStack_bc;
  void *pvStack_b4;
  CRYPTO_THREADID aCStack_b0 [4];
  int iStack_8c;
  undefined *puStack_88;
  void **ppvStack_84;
  CRYPTO_THREADID *pCStack_80;
  char *pcStack_7c;
  char *pcStack_78;
  CRYPTO_THREADID *pCStack_74;
  char *pcStack_70;
  code *pcStack_6c;
  undefined *local_58;
  CRYPTO_THREADID *local_50;
  undefined *local_4c;
  CRYPTO_THREADID aCStack_48 [3];
  void **local_2c;
  
  puStack_88 = PTR___stack_chk_guard_006a9ae8;
  local_58 = &_gp;
  ppvVar8 = *(void ***)PTR___stack_chk_guard_006a9ae8;
  addr_00 = (void **)num;
  num_00 = file;
  file_00 = (char *)line;
  pcStack_e4 = unaff_s4;
  pCStack_74 = unaff_s5;
  iStack_d8 = unaff_s7;
  local_2c = ppvVar8;
  if (((before_p & 0x7fU) == 1) && (addr != (void *)0x0)) {
    unaff_s3 = &_gp_1;
    if ((mh_mode & 1) != 0) {
      local_50 = aCStack_48;
      CRYPTO_THREADID_current(aCStack_48);
      unaff_s6 = "TBEX";
      CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
      pcStack_e4 = (char *)num;
      pCStack_74 = (CRYPTO_THREADID *)file;
      iStack_d8 = line;
      if ((mh_mode & 2) == 0) {
        unaff_s1 = (void **)CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,local_50);
        file_00 = (char *)0x122;
        num_00 = "mem_dbg.c";
        addr_00 = (void **)&DAT_00000014;
        ppvVar8 = (void **)&DAT_00000006;
        CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
        if (unaff_s1 == (void **)0x0) goto LAB_004bef3c;
      }
      else {
        CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      }
      CRYPTO_mem_ctrl_constprop_5();
      unaff_s1 = (void **)CRYPTO_malloc(0x24,"mem_dbg.c",0x1e1);
      if (unaff_s1 == (void **)0x0) {
        CRYPTO_free(addr);
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      }
      else {
        if ((mh == 0) &&
           (mh = (**(code **)(local_58 + -0x79d4))(mem_LHASH_HASH,mem_LHASH_COMP), mh == 0)) {
          CRYPTO_free(addr);
          CRYPTO_free(unaff_s1);
        }
        else {
          *unaff_s1 = addr;
          unaff_s1[2] = file;
          unaff_s1[3] = (void *)line;
          unaff_s1[1] = (void *)num;
          uVar2 = options;
          local_4c = &_gp_1;
          if ((options & 2) == 0) {
            *(undefined *)(unaff_s1 + 4) = 0;
            *(undefined *)((int)unaff_s1 + 0x11) = 0;
            *(undefined *)((int)unaff_s1 + 0x12) = 0;
            *(undefined *)((int)unaff_s1 + 0x13) = 0;
            *(undefined *)(unaff_s1 + 5) = 0;
            *(undefined *)((int)unaff_s1 + 0x15) = 0;
            *(undefined *)((int)unaff_s1 + 0x16) = 0;
            *(undefined *)((int)unaff_s1 + 0x17) = 0;
          }
          else {
            CRYPTO_THREADID_current((CRYPTO_THREADID *)(unaff_s1 + 4));
            uVar2 = *(uint *)(local_4c + -0x5384);
          }
          unaff_s1[6] = order;
          if ((uVar2 & 1) == 0) {
            order = (void *)((int)order + 1);
            unaff_s1[7] = (void *)0x0;
          }
          else {
            order = (void *)((int)order + 1);
            pvVar3 = (void *)(**(code **)(local_58 + -0x5304))(0);
            unaff_s1[7] = pvVar3;
          }
          addr = local_50;
          CRYPTO_THREADID_current(local_50);
          unaff_s1[8] = (void *)0x0;
          if ((amih != 0) &&
             (pvVar3 = (void *)(**(code **)(local_58 + -0x7a30))(amih,addr), pvVar3 != (void *)0x0))
          {
            iVar5 = *(int *)((int)pvVar3 + 0x18);
            unaff_s1[8] = pvVar3;
            *(int *)((int)pvVar3 + 0x18) = iVar5 + 1;
          }
          pvVar3 = (void *)(**(code **)(local_58 + -0x79cc))(mh,unaff_s1);
          if (pvVar3 != (void *)0x0) {
            iVar5 = *(int *)((int)pvVar3 + 0x20);
            if (iVar5 != 0) {
              *(int *)(iVar5 + 0x18) = *(int *)(iVar5 + 0x18) + -1;
            }
            CRYPTO_free(pvVar3);
          }
        }
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      }
      if ((((mh_mode & 1) != 0) && (num_disable != 0)) &&
         (num_disable = num_disable + -1, num_disable == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
      }
      file_00 = (char *)0x112;
      num_00 = "mem_dbg.c";
      addr_00 = (void **)&DAT_00000014;
      ppvVar8 = (void **)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
    }
  }
LAB_004bef3c:
  if (local_2c == *(void ***)puStack_88) {
    return;
  }
  pcStack_6c = CRYPTO_dbg_free;
  (**(code **)(local_58 + -0x5330))();
  puStack_f4 = PTR___stack_chk_guard_006a9ae8;
  puStack_c0 = &_gp;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppvStackY_150 = ppvVar8;
  ppvStack_f0 = unaff_s1;
  pCStack_ec = (CRYPTO_THREADID *)addr;
  pcStackY_14c = unaff_s3;
  pCStack_e0 = pCStack_74;
  ppvStack_84 = unaff_s1;
  pCStack_80 = (CRYPTO_THREADID *)addr;
  pcStack_7c = unaff_s3;
  pcStack_78 = pcStack_e4;
  pcStack_70 = unaff_s6;
  if (((addr_00 == (void **)0x0) && (ppvStack_f0 = ppvVar8, ppvVar8 != (void **)0x0)) &&
     (pCStack_ec = (CRYPTO_THREADID *)&_gp_1, (mh_mode & 1) != 0)) {
    pCStack_e0 = aCStack_b0;
    pcStackY_14c = "TBEX";
    CRYPTO_THREADID_current(pCStack_e0);
    CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
    if ((mh_mode & 2) == 0) {
      pcStack_e4 = (char *)CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,pCStack_e0);
      file_00 = (char *)0x122;
      num_00 = "mem_dbg.c";
      addr_00 = (void **)&DAT_00000014;
      ppvStackY_150 = (void **)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
      if (pcStack_e4 == (char *)0x0) goto LAB_004bf31c;
    }
    else {
      file_00 = (char *)0x122;
      num_00 = "mem_dbg.c";
      addr_00 = (void **)&DAT_00000014;
      ppvStackY_150 = (void **)&DAT_00000006;
      CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    }
    pcStack_e4 = &_gp_1;
    if (mh != 0) {
      CRYPTO_mem_ctrl_constprop_5();
      aCStack_b0[0].ptr = ppvVar8;
      pvVar3 = (void *)(**(code **)(puStack_c0 + -0x6a50))(mh,pCStack_e0);
      if (pvVar3 != (void *)0x0) {
        ppvVar8 = *(void ***)((int)pvVar3 + 0x20);
        if ((ppvVar8 != (void **)0x0) &&
           (pvVar7 = ppvVar8[6], ppvVar8[6] = (void *)((int)pvVar7 + -1),
           (int)(void *)((int)pvVar7 + -1) < 1)) {
          pcStack_e4 = (char *)ppvVar8[5];
          pvStack_b4 = pvVar3;
          if ((pcStack_e4 != (char *)0x0) &&
             (iVar5 = *(int *)(pcStack_e4 + 0x18), *(int *)(pcStack_e4 + 0x18) = iVar5 + -1,
             iVar5 + -1 < 1)) {
            pCStack_e0 = *(CRYPTO_THREADID **)(pcStack_e4 + 0x14);
            if ((pCStack_e0 != (CRYPTO_THREADID *)0x0) &&
               (pvVar3 = (void *)((int)pCStack_e0[3].ptr + -1), pCStack_e0[3].ptr = pvVar3,
               (int)pvVar3 < 1)) {
              unaff_s6 = (char *)pCStack_e0[2].val;
              if ((unaff_s6 != (char *)0x0) &&
                 (iVar5 = *(int *)(unaff_s6 + 0x18), *(int *)(unaff_s6 + 0x18) = iVar5 + -1,
                 iVar5 + -1 < 1)) {
                if (*(int *)(unaff_s6 + 0x14) != 0) {
                  app_info_free();
                }
                CRYPTO_free(unaff_s6);
              }
              CRYPTO_free(pCStack_e0);
            }
            CRYPTO_free(pcStack_e4);
          }
          CRYPTO_free(ppvVar8);
          pvVar3 = pvStack_b4;
        }
        CRYPTO_free(pvVar3);
      }
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      if ((((mh_mode & 1) != 0) && (iVar5 = num_disable + -1, num_disable != 0)) &&
         (num_disable = iVar5, iVar5 == 0)) {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
      }
      file_00 = (char *)0x112;
      num_00 = "mem_dbg.c";
      addr_00 = (void **)&DAT_00000014;
      ppvStackY_150 = (void **)&DAT_0000000a;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      ppvStack_f0 = ppvVar8;
    }
  }
LAB_004bf31c:
  if (iStack_8c == *(int *)puStack_f4) {
    return;
  }
  pcStack_d4 = CRYPTO_dbg_realloc;
  (**(code **)(puStack_c0 + -0x5330))();
  puStackY_158 = PTR___stack_chk_guard_006a9ae8;
  ppvStack_fc = *(void ***)PTR___stack_chk_guard_006a9ae8;
  ppvVar8 = ppvStack_fc;
  ppvStackY_154 = ppvStack_f0;
  pcStackY_148 = pcStack_e4;
  pcStack_e8 = pcStackY_14c;
  pcStack_dc = unaff_s6;
  if ((iStack_bc == 1) && (ppvStackY_154 = addr_00, addr_00 != (void **)0x0)) {
    pcStackY_148 = num_00;
    if (ppvStackY_150 == (void **)0x0) {
      ppvVar8 = addr_00;
      CRYPTO_dbg_malloc(addr_00,(int)num_00,file_00,(int)puStack_c0,0x81);
    }
    else {
      pcStackY_14c = &_gp_1;
      if ((mh_mode & 1) != 0) {
        CRYPTO_THREADID_current(aCStack_120);
        CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
        if ((mh_mode & 2) == 0) {
          iVar5 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,aCStack_120);
          ppvVar8 = (void **)&DAT_00000006;
          CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
          if (iVar5 == 0) goto LAB_004bf63c;
        }
        else {
          CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
        }
        CRYPTO_mem_ctrl_constprop_5();
        aCStack_120[0].ptr = ppvStackY_150;
        puVar4 = (undefined4 *)(*(code *)PTR_lh_delete_006a8390)(mh,aCStack_120);
        iVar5 = mh;
        puVar1 = PTR_lh_insert_006a7414;
        if (puVar4 != (undefined4 *)0x0) {
          *puVar4 = addr_00;
          puVar4[1] = num_00;
          (*(code *)puVar1)(iVar5,puVar4);
        }
        CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
        if ((((mh_mode & 1) != 0) && (iVar5 = num_disable + -1, num_disable != 0)) &&
           (num_disable = iVar5, iVar5 == 0)) {
          mh_mode = mh_mode | 2;
          CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
        }
        ppvVar8 = (void **)&DAT_0000000a;
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      }
    }
  }
LAB_004bf63c:
  if (ppvStack_fc == *(void ***)puStackY_158) {
    return;
  }
  pcStackY_144 = CRYPTO_mem_leaks;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStackY_15c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((mh != 0) || (amih != 0)) {
    CRYPTO_mem_ctrl_constprop_5();
    uStackY_160 = 0;
    iStackY_164 = 0;
    ppvStackY_168 = ppvVar8;
    if ((mh == 0) ||
       ((*(code *)PTR_lh_doall_arg_006a83a0)(mh,print_leak_LHASH_DOALL_ARG,&ppvStackY_168),
       iStackY_164 == 0)) {
      CRYPTO_lock(9,0x14,"mem_dbg.c",0x2eb);
      uVar2 = mh_mode;
      mh_mode = 0;
      if (mh != 0) {
        (*(code *)PTR_lh_free_006a7418)();
        mh = 0;
      }
      if ((amih != 0) && (iVar5 = (*(code *)PTR_lh_num_items_006a8330)(), iVar5 == 0)) {
        (*(code *)PTR_lh_free_006a7418)(amih);
        amih = 0;
      }
      mh_mode = uVar2;
      CRYPTO_lock(10,0x14,"mem_dbg.c",0x300);
    }
    else {
      (*(code *)PTR_BIO_printf_006a6e38)(ppvVar8,"%ld bytes leaked in %d chunks\n",uStackY_160);
    }
    CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
    if ((((mh_mode & 1) != 0) && (iVar5 = num_disable + -1, num_disable != 0)) &&
       (num_disable = iVar5, iVar5 == 0)) {
      mh_mode = mh_mode | 2;
      CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
    }
    ppvVar8 = (void **)&DAT_0000000a;
    CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  }
  if (iStackY_15c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    if (mh != 0) {
      CRYPTO_mem_ctrl_constprop_5();
      uVar6 = (*(code *)PTR_BIO_s_file_006a6ea0)();
      bio = (bio_st *)(*(code *)PTR_BIO_new_006a6ea4)(uVar6);
      CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
      if ((((mh_mode & 1) == 0) || (iVar5 = num_disable + -1, num_disable == 0)) ||
         (num_disable = iVar5, iVar5 != 0)) {
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      }
      else {
        mh_mode = mh_mode | 2;
        CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
        CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
      }
      if (bio != (bio_st *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(bio,0x6a,0,ppvVar8);
        CRYPTO_mem_leaks(bio);
                    /* WARNING: Could not recover jumptable at 0x004bfb34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)PTR_BIO_free_006a6e70)(bio);
        return;
      }
    }
    return;
  }
  return;
}

