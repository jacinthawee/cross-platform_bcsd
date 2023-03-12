
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 * cswift_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 **ppuVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  undefined4 **ppuVar13;
  undefined4 uVar14;
  char *pcVar15;
  char *pcVar16;
  code *unaff_s6;
  undefined4 *unaff_s7;
  code *pcVar17;
  undefined4 *unaff_s8;
  undefined4 uStack_380;
  int iStack_37c;
  undefined4 uStack_378;
  int *piStack_374;
  undefined4 uStack_370;
  undefined4 uStack_36c;
  undefined4 uStack_368;
  undefined4 uStack_364;
  undefined4 uStack_360;
  undefined4 uStack_35c;
  undefined4 uStack_358;
  undefined4 uStack_354;
  undefined4 uStack_350;
  undefined4 *puStack_344;
  int iStack_340;
  undefined4 uStack_33c;
  int iStack_338;
  undefined auStack_334 [16];
  int iStack_324;
  undefined *puStack_320;
  undefined4 *puStack_31c;
  undefined4 **ppuStack_318;
  undefined4 **ppuStack_314;
  undefined4 **ppuStack_310;
  undefined4 **ppuStack_30c;
  undefined4 *puStack_308;
  undefined *puStack_304;
  char *pcStack_300;
  code *pcStack_2fc;
  char *pcStack_2f4;
  undefined4 **ppuStack_2e8;
  undefined4 uStack_2e4;
  undefined *puStack_2e0;
  int iStack_2d4;
  undefined4 uStack_2cc;
  undefined4 *puStack_2c8;
  int iStack_2c4;
  undefined4 *puStack_2c0;
  undefined4 *puStack_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 *puStack_2b0;
  undefined4 uStack_2ac;
  undefined4 *puStack_2a8;
  undefined4 uStack_2a4;
  undefined4 *puStack_2a0;
  undefined4 uStack_29c;
  undefined4 uStack_298;
  undefined4 *apuStack_28c [4];
  int iStack_27c;
  undefined *puStack_278;
  char *pcStack_274;
  undefined4 **ppuStack_270;
  undefined4 **ppuStack_26c;
  undefined4 **ppuStack_268;
  undefined4 **ppuStack_264;
  undefined4 *puStack_260;
  undefined4 *puStack_25c;
  undefined4 *puStack_258;
  code *pcStack_254;
  undefined4 **ppuStack_240;
  undefined4 uStack_23c;
  undefined *puStack_238;
  undefined4 **ppuStack_22c;
  undefined4 *puStack_228;
  int iStack_224;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 *puStack_214;
  undefined4 *puStack_210;
  undefined4 *puStack_20c;
  undefined4 uStack_208;
  uint uStack_204;
  int iStack_200;
  uint uStack_1fc;
  int iStack_1f8;
  uint uStack_1f4;
  int iStack_1f0;
  uint uStack_1ec;
  int iStack_1e8;
  uint uStack_1e4;
  int iStack_1e0;
  undefined4 *apuStack_1dc [4];
  int iStack_1cc;
  undefined4 **ppuStack_1c8;
  undefined *puStack_1c4;
  char *pcStack_1c0;
  char *pcStack_1bc;
  undefined4 **ppuStack_1b8;
  undefined4 **ppuStack_1b4;
  undefined4 *puStack_1b0;
  undefined4 *puStack_1ac;
  undefined4 *puStack_1a8;
  code *pcStack_1a4;
  undefined4 **ppuStack_190;
  undefined4 *puStack_18c;
  undefined *puStack_188;
  undefined4 **ppuStack_17c;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 *puStack_16c;
  undefined4 *puStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 *apuStack_134 [4];
  undefined4 **ppuStack_124;
  undefined4 uStack_120;
  undefined *puStack_11c;
  undefined4 *puStack_118;
  char *pcStack_114;
  undefined4 *puStack_110;
  undefined4 *puStack_10c;
  int iStack_108;
  undefined4 *puStack_104;
  undefined4 *puStack_100;
  code *pcStack_fc;
  undefined4 **ppuStack_e8;
  undefined4 *puStack_e4;
  undefined *puStack_e0;
  char *pcStack_d4;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 *puStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 *apuStack_8c [4];
  undefined4 **ppuStack_7c;
  undefined1 *puStack_78;
  undefined *puStack_74;
  undefined1 *puStack_70;
  undefined1 *puStack_6c;
  undefined1 *puStack_68;
  undefined1 *puStack_64;
  code *pcStack_60;
  undefined4 *puStack_5c;
  undefined4 *puStack_58;
  code *pcStack_54;
  int local_40;
  undefined4 uStack_3c;
  undefined *local_38;
  undefined4 local_30;
  int local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (cswift_dso == 0) {
    pcVar15 = CSWIFT_LIBNAME;
    if (CSWIFT_LIBNAME == (char *)0x0) {
      pcVar15 = "swift";
    }
    pcStack_114 = (char *)0x0;
    iStack_108 = 0;
    cswift_dso = (*(code *)PTR_DSO_load_006a99a4)(0,pcVar15);
    if (cswift_dso == 0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(local_38 + -0x589c))();
      }
      pcVar17 = *(code **)(local_38 + -0x6eb0);
      iStack_108 = 0x6a;
      local_40 = 0x18d;
      goto LAB_005d23cc;
    }
    unaff_s6 = (code *)(**(code **)(local_38 + -0x6534))(cswift_dso,"swAcquireAccContext");
    if (((unaff_s6 == (code *)0x0) ||
        (unaff_s7 = (undefined4 *)(**(code **)(local_38 + -0x6534))(cswift_dso,"swAttachKeyParam"),
        unaff_s7 == (undefined4 *)0x0)) ||
       (unaff_s8 = (undefined4 *)(**(code **)(local_38 + -0x6534))(cswift_dso,"swSimpleRequest"),
       unaff_s8 == (undefined4 *)0x0)) {
LAB_005d25a8:
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(local_38 + -0x589c))();
      }
      pcVar17 = *(code **)(local_38 + -0x6eb0);
      iStack_108 = 0x6a;
      local_40 = 0x199;
      goto LAB_005d23cc;
    }
    pcStack_d4 = "swReleaseAccContext";
    pcVar17 = (code *)(**(code **)(local_38 + -0x6534))(cswift_dso);
    if (pcVar17 == (code *)0x0) goto LAB_005d25a8;
    p_CSwift_ReleaseAccContext = pcVar17;
    p_CSwift_SimpleRequest = unaff_s8;
    p_CSwift_AttachKeyParam = unaff_s7;
    p_CSwift_AcquireAccContext = unaff_s6;
    iVar3 = (*unaff_s6)(&local_30);
    if (iVar3 != 0) {
      unaff_s6 = (code *)&_ITM_registerTMCloneTable;
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(local_38 + -0x589c))();
      }
      iStack_108 = 0x6c;
      pcStack_114 = "e_cswift.c";
      local_40 = 0x1a5;
      pcStack_d4 = &DAT_00000068;
      (**(code **)(local_38 + -0x6eb0))(CSWIFT_lib_error_code);
      goto LAB_005d23ec;
    }
    (*p_CSwift_ReleaseAccContext)(local_30);
    puVar1 = (undefined4 *)0x1;
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    pcVar17 = *(code **)(local_38 + -0x6eb0);
    iStack_108 = 100;
    local_40 = 0x186;
LAB_005d23cc:
    pcStack_114 = "e_cswift.c";
    pcStack_d4 = &DAT_00000068;
    (*pcVar17)(CSWIFT_lib_error_code);
LAB_005d23ec:
    if (cswift_dso != 0) {
      (**(code **)(local_38 + -0x654c))();
      cswift_dso = 0;
    }
    puVar1 = (undefined4 *)0x0;
    p_CSwift_AcquireAccContext = (code *)0x0;
    p_CSwift_AttachKeyParam = (undefined4 *)0x0;
    p_CSwift_SimpleRequest = (undefined4 *)0x0;
    p_CSwift_ReleaseAccContext = (code *)0x0;
  }
  puStack_10c = (undefined4 *)&_ITM_registerTMCloneTable;
  puStack_110 = (undefined4 *)&_ITM_registerTMCloneTable;
  if (local_2c == *(int *)puStack_74) {
    return puVar1;
  }
  pcStack_54 = cswift_mod_exp_dh;
  (**(code **)(local_38 + -0x5328))();
  iVar3 = local_40;
  puStack_11c = PTR___stack_chk_guard_006aabf0;
  puStack_6c = &_ITM_registerTMCloneTable;
  puStack_70 = &_ITM_registerTMCloneTable;
  puStack_78 = &_ITM_registerTMCloneTable;
  puStack_e0 = &_gp;
  puStack_64 = &_ITM_registerTMCloneTable;
  puStack_68 = &_ITM_registerTMCloneTable;
  ppuStack_7c = *(undefined4 ***)PTR___stack_chk_guard_006aabf0;
  pcStack_60 = unaff_s6;
  puStack_5c = unaff_s7;
  puStack_58 = unaff_s8;
  iVar2 = (*p_CSwift_AcquireAccContext)(&uStack_cc);
  if (iVar2 == 0) {
    (**(code **)(puStack_e0 + -0x689c))(uStack_3c);
    puStack_110 = (undefined4 *)(**(code **)(puStack_e0 + -0x6898))(uStack_3c);
    unaff_s7 = (undefined4 *)(**(code **)(puStack_e0 + -0x6898))(uStack_3c);
    unaff_s8 = (undefined4 *)(**(code **)(puStack_e0 + -0x6898))(uStack_3c);
    puStack_10c = (undefined4 *)(**(code **)(puStack_e0 + -0x6898))(uStack_3c);
    if (puStack_10c == (undefined4 *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_e0 + -0x589c))();
      }
      pcVar17 = *(code **)(puStack_e0 + -0x6eb0);
      ppuStack_310 = (undefined4 **)0x66;
      ppuStack_e8 = (undefined4 **)0x20a;
LAB_005d29fc:
      pcStack_1bc = "e_cswift.c";
      pcStack_1c0 = &DAT_00000069;
      puStack_118 = (undefined4 *)0x0;
      (*pcVar17)(CSWIFT_lib_error_code);
    }
    else {
      pcVar17 = *(code **)(puStack_e0 + -0x6860);
      if ((int)puStack_110[2] < *(int *)(iVar3 + 4)) {
        iVar2 = (*pcVar17)(puStack_110);
        if (iVar2 != 0) {
          if ((int)unaff_s7[2] < (int)*(undefined4 **)((int)pcStack_114 + 4)) {
            pcVar17 = *(code **)(puStack_e0 + -0x6860);
            goto LAB_005d2a4c;
          }
          goto LAB_005d27e0;
        }
LAB_005d299c:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_e0 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_e0 + -0x6eb0);
        ppuStack_310 = (undefined4 **)0x67;
        ppuStack_e8 = (undefined4 **)0x210;
        goto LAB_005d29fc;
      }
      if ((int)unaff_s7[2] < (int)*(undefined4 **)((int)pcStack_114 + 4)) {
LAB_005d2a4c:
        iVar2 = (*pcVar17)(unaff_s7);
        if (iVar2 == 0) goto LAB_005d299c;
      }
LAB_005d27e0:
      if ((((int)unaff_s8[2] < *(int *)(iStack_108 + 4)) &&
          (iVar2 = (**(code **)(puStack_e0 + -0x6860))(unaff_s8), iVar2 == 0)) ||
         (((int)puStack_10c[2] < *(int *)(iVar3 + 4) &&
          (iVar2 = (**(code **)(puStack_e0 + -0x6860))(puStack_10c), iVar2 == 0))))
      goto LAB_005d299c;
      uStack_b8 = 2;
      uStack_b4 = (**(code **)(puStack_e0 + -0x7be0))(iVar3,*puStack_110);
      uStack_b0 = *puStack_110;
      uStack_ac = (**(code **)(puStack_e0 + -0x7be0))(pcStack_114,*unaff_s7);
      uStack_a8 = *unaff_s7;
      pcStack_114 = (char *)(*(code *)p_CSwift_AttachKeyParam)(uStack_cc,&uStack_b8);
      if ((undefined4 **)pcStack_114 == (undefined4 **)0xffffd8ea) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_e0 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_e0 + -0x6eb0);
        ppuStack_310 = (undefined4 **)&DAT_00000065;
        ppuStack_e8 = (undefined4 **)0x221;
        goto LAB_005d29fc;
      }
      if ((undefined4 **)pcStack_114 == (undefined4 **)0x0) {
        uStack_c8 = (**(code **)(puStack_e0 + -0x7be0))(iStack_108,*unaff_s8);
        uStack_c4 = *unaff_s8;
        iVar2 = (**(code **)(puStack_e0 + -0x7bec))(iVar3);
        iVar3 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar3 = iVar2 + 0xe;
        }
        puStack_c0 = (undefined4 *)(iVar3 >> 3);
        (**(code **)(puStack_e0 + -0x53e0))(*puStack_10c,0,puStack_c0);
        uStack_bc = *puStack_10c;
        pcStack_1bc = (char *)0x1;
        ppuStack_e8 = &puStack_c0;
        puStack_e4 = (undefined4 *)0x1;
        ppuVar13 = (undefined4 **)(*(code *)p_CSwift_SimpleRequest)(uStack_cc,2,&uStack_c8);
        if (ppuVar13 != (undefined4 **)0x0) {
          pcStack_114 = &_ITM_registerTMCloneTable;
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_e0 + -0x589c))();
          }
          ppuStack_e8 = (undefined4 **)0x237;
          (**(code **)(puStack_e0 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_e0 + -0x54a0);
          ppuStack_e8 = ppuVar13;
          goto LAB_005d2ac0;
        }
        puStack_118 = (undefined4 *)0x1;
        pcStack_1c0 = (char *)puStack_c0;
        ppuStack_310 = (undefined4 **)pcStack_d4;
        (**(code **)(puStack_e0 + -0x74f0))(*puStack_10c);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_e0 + -0x589c))();
        }
        ppuStack_e8 = (undefined4 **)0x226;
        (**(code **)(puStack_e0 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
        pcVar17 = *(code **)(puStack_e0 + -0x54a0);
        ppuStack_e8 = (undefined4 **)pcStack_114;
LAB_005d2ac0:
        pcStack_1bc = &DAT_0066fa48;
        ppuStack_310 = apuStack_8c;
        (*pcVar17)(ppuStack_310,1,0xd);
        pcStack_1c0 = "CryptoSwift error number is ";
        puStack_118 = (undefined4 *)0x0;
        (**(code **)(puStack_e0 + -0x6c7c))(2);
      }
    }
    (*p_CSwift_ReleaseAccContext)(uStack_cc);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (**(code **)(puStack_e0 + -0x589c))();
    }
    ppuStack_310 = (undefined4 **)&DAT_0000006c;
    pcStack_1bc = "e_cswift.c";
    ppuStack_e8 = (undefined4 **)0x1fe;
    pcStack_1c0 = &DAT_00000069;
    puStack_118 = (undefined4 *)0x0;
    (**(code **)(puStack_e0 + -0x6eb0))(CSWIFT_lib_error_code);
  }
  (**(code **)(puStack_e0 + -0x688c))(uStack_3c);
  if (ppuStack_7c == *(undefined4 ***)puStack_11c) {
    return puStack_118;
  }
  pcStack_fc = cswift_mod_exp_mont;
  ppuStack_30c = ppuStack_7c;
  (**(code **)(puStack_e0 + -0x5328))();
  puStack_308 = puStack_e4;
  ppuStack_1c8 = ppuStack_e8;
  puStack_1c4 = PTR___stack_chk_guard_006aabf0;
  uStack_120 = uStack_3c;
  puStack_188 = &_gp;
  ppuStack_124 = *(undefined4 ***)PTR___stack_chk_guard_006aabf0;
  puStack_104 = unaff_s7;
  puStack_100 = unaff_s8;
  iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)();
  if ((((iVar3 < 0x801) &&
       (iVar3 = (**(code **)(puStack_188 + -0x7bec))(pcStack_1c0), iVar3 < 0x801)) &&
      (iVar3 = (**(code **)(puStack_188 + -0x7bec))(pcStack_1bc), iVar3 < 0x801)) ||
     (iVar3 = (**(code **)(puStack_188 + -0x7308))(), iVar3 == 0)) {
    iVar3 = (*p_CSwift_AcquireAccContext)(&uStack_174);
    if (iVar3 == 0) {
      (**(code **)(puStack_188 + -0x689c))(ppuStack_1c8);
      puStack_308 = (undefined4 *)(**(code **)(puStack_188 + -0x6898))(ppuStack_1c8);
      unaff_s7 = (undefined4 *)(**(code **)(puStack_188 + -0x6898))(ppuStack_1c8);
      ppuStack_17c = (undefined4 **)(**(code **)(puStack_188 + -0x6898))(ppuStack_1c8);
      unaff_s8 = (undefined4 *)(**(code **)(puStack_188 + -0x6898))(ppuStack_1c8);
      if (unaff_s8 == (undefined4 *)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_188 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_188 + -0x6eb0);
        ppuStack_314 = (undefined4 **)0x66;
        ppuStack_190 = (undefined4 **)0x20a;
LAB_005d2f9c:
        pcVar15 = "e_cswift.c";
        pcStack_274 = &DAT_00000069;
        puVar1 = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if ((((((int)puStack_308[2] < (int)*(undefined4 **)((int)pcStack_1bc + 4)) &&
              (iVar3 = (**(code **)(puStack_188 + -0x6860))(puStack_308), iVar3 == 0)) ||
             (((int)unaff_s7[2] < (int)ppuStack_310[1] &&
              (iVar3 = (**(code **)(puStack_188 + -0x6860))(unaff_s7), iVar3 == 0)))) ||
            (((int)ppuStack_17c[2] < *(int *)((int)pcStack_1c0 + 4) &&
             (iVar3 = (**(code **)(puStack_188 + -0x6860))(ppuStack_17c), iVar3 == 0)))) ||
           (((int)unaff_s8[2] < (int)*(undefined4 **)((int)pcStack_1bc + 4) &&
            (iVar3 = (**(code **)(puStack_188 + -0x6860))(unaff_s8), iVar3 == 0)))) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_188 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_188 + -0x6eb0);
          ppuStack_314 = (undefined4 **)0x67;
          ppuStack_190 = (undefined4 **)0x210;
          goto LAB_005d2f9c;
        }
        uStack_160 = 2;
        uStack_15c = (**(code **)(puStack_188 + -0x7be0))(pcStack_1bc,*puStack_308);
        uStack_158 = *puStack_308;
        uStack_154 = (**(code **)(puStack_188 + -0x7be0))(ppuStack_310,*unaff_s7);
        uStack_150 = *unaff_s7;
        ppuVar13 = (undefined4 **)(*(code *)p_CSwift_AttachKeyParam)(uStack_174,&uStack_160);
        ppuStack_310 = ppuStack_17c;
        if (ppuVar13 == (undefined4 **)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_188 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_188 + -0x6eb0);
          ppuStack_314 = (undefined4 **)&DAT_00000065;
          ppuStack_190 = (undefined4 **)0x221;
          ppuStack_310 = ppuVar13;
          goto LAB_005d2f9c;
        }
        if (ppuVar13 == (undefined4 **)0x0) {
          uStack_170 = (**(code **)(puStack_188 + -0x7be0))(pcStack_1c0,*ppuStack_17c);
          puStack_16c = *ppuStack_310;
          iVar2 = (**(code **)(puStack_188 + -0x7bec))(pcStack_1bc);
          iVar3 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            iVar3 = iVar2 + 0xe;
          }
          puStack_168 = (undefined4 *)(iVar3 >> 3);
          (**(code **)(puStack_188 + -0x53e0))(*unaff_s8,0,puStack_168);
          uStack_164 = *unaff_s8;
          pcVar15 = (char *)0x1;
          ppuStack_190 = &puStack_168;
          puStack_18c = (undefined4 *)0x1;
          ppuVar13 = (undefined4 **)(*(code *)p_CSwift_SimpleRequest)(uStack_174,2,&uStack_170);
          if (ppuVar13 != (undefined4 **)0x0) {
            pcStack_1bc = &_ITM_registerTMCloneTable;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_188 + -0x589c))();
            }
            ppuStack_190 = (undefined4 **)0x237;
            (**(code **)(puStack_188 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
            pcVar17 = *(code **)(puStack_188 + -0x54a0);
            ppuStack_190 = ppuVar13;
            goto LAB_005d3034;
          }
          puVar1 = (undefined4 *)0x1;
          pcStack_274 = (char *)puStack_168;
          ppuStack_314 = ppuStack_30c;
          (**(code **)(puStack_188 + -0x74f0))(*unaff_s8);
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_188 + -0x589c))();
          }
          ppuStack_190 = (undefined4 **)0x226;
          (**(code **)(puStack_188 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_188 + -0x54a0);
          ppuStack_310 = ppuVar13;
          ppuStack_190 = ppuVar13;
LAB_005d3034:
          pcVar15 = &DAT_0066fa48;
          ppuStack_314 = apuStack_134;
          (*pcVar17)(ppuStack_314,1,0xd);
          pcStack_274 = "CryptoSwift error number is ";
          puVar1 = (undefined4 *)0x0;
          (**(code **)(puStack_188 + -0x6c7c))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_174);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_188 + -0x589c))();
      }
      ppuStack_314 = (undefined4 **)&DAT_0000006c;
      pcVar15 = "e_cswift.c";
      ppuStack_190 = (undefined4 **)0x1fe;
      pcStack_274 = &DAT_00000069;
      puVar1 = (undefined4 *)0x0;
      (**(code **)(puStack_188 + -0x6eb0))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_188 + -0x688c))(ppuStack_1c8);
    pcStack_1c0 = (char *)puVar1;
  }
  else {
    puStack_18c = puStack_308;
    ppuStack_190 = ppuStack_1c8;
    pcStack_274 = pcStack_1c0;
    ppuStack_314 = ppuStack_310;
    pcVar15 = pcStack_1bc;
    puVar1 = (undefined4 *)(**(code **)(iVar3 + 0x18))(ppuStack_30c);
  }
  if (ppuStack_124 == *(undefined4 ***)puStack_1c4) {
    return puVar1;
  }
  pcStack_1a4 = cswift_rsa_mod_exp;
  ppuVar13 = ppuStack_124;
  (**(code **)(puStack_188 + -0x5328))();
  puStack_320 = PTR___stack_chk_guard_006aabf0;
  puStack_238 = &_gp;
  iStack_1cc = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar5 = (undefined4 **)pcStack_1bc;
  ppuStack_318 = ppuVar13;
  ppuStack_1b8 = ppuStack_310;
  ppuStack_1b4 = ppuStack_30c;
  puStack_1b0 = puStack_308;
  puStack_1ac = unaff_s7;
  puStack_1a8 = unaff_s8;
  if ((((ppuStack_314[7] == (undefined4 *)0x0) ||
       (ppuVar5 = ppuStack_314, ppuStack_314[8] == (undefined4 *)0x0)) ||
      (ppuStack_314[9] == (undefined4 *)0x0)) ||
     ((ppuStack_314[10] == (undefined4 *)0x0 || (ppuStack_314[0xb] == (undefined4 *)0x0)))) {
    ppuStack_314 = ppuVar5;
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppuVar5 = (undefined4 **)&DAT_00000069;
    pcVar16 = "e_cswift.c";
    ppuStack_240 = (undefined4 **)0x2ed;
    pcStack_300 = &DAT_0000006b;
    (**(code **)(puStack_238 + -0x6eb0))(CSWIFT_lib_error_code);
    puVar1 = (undefined4 *)0x0;
    pcStack_274 = &_ITM_registerTMCloneTable;
  }
  else {
    pcVar16 = pcVar15;
    iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)();
    if ((((iVar3 < 0x401) &&
         (iVar3 = (**(code **)(puStack_238 + -0x7bec))(ppuStack_314[8]), iVar3 < 0x401)) &&
        ((iVar3 = (**(code **)(puStack_238 + -0x7bec))(ppuStack_314[9]), iVar3 < 0x401 &&
         ((iVar3 = (**(code **)(puStack_238 + -0x7bec))(ppuStack_314[10]), iVar3 < 0x401 &&
          (iVar3 = (**(code **)(puStack_238 + -0x7bec))(ppuStack_314[0xb]), iVar3 < 0x401)))))) ||
       (iVar3 = (**(code **)(puStack_238 + -0x7308))(), pcVar16 = pcVar15, iVar3 == 0)) {
      ppuStack_30c = (undefined4 **)ppuStack_314[7];
      puStack_308 = ppuStack_314[8];
      unaff_s8 = ppuStack_314[9];
      ppuStack_22c = (undefined4 **)ppuStack_314[10];
      iStack_200 = 0;
      iStack_1f8 = 0;
      iStack_1f0 = 0;
      iStack_1e8 = 0;
      iStack_1e0 = 0;
      puStack_228 = ppuStack_314[0xb];
      iVar3 = (*p_CSwift_AcquireAccContext)(&uStack_21c);
      if (iVar3 == 0) {
        ppuStack_310 = (undefined4 **)(**(code **)(puStack_238 + -0x7c2c))();
        ppuStack_314 = (undefined4 **)(**(code **)(puStack_238 + -0x7c2c))();
        if ((ppuStack_314 == (undefined4 **)0x0) || (ppuStack_310 == (undefined4 **)0x0)) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_238 + -0x589c))();
          }
          ppuVar13 = (undefined4 **)0x66;
          pcVar16 = "e_cswift.c";
          ppuStack_240 = (undefined4 **)0x280;
          pcStack_300 = &DAT_0000006a;
          ppuStack_318 = (undefined4 **)0x1;
          (**(code **)(puStack_238 + -0x6eb0))(CSWIFT_lib_error_code);
          puVar1 = (undefined4 *)0x0;
        }
        else {
          uStack_208 = 1;
          iVar2 = (**(code **)(puStack_238 + -0x7bec))(ppuStack_30c);
          iVar3 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            iVar3 = iVar2 + 0xe;
          }
          uStack_204 = iVar3 >> 3;
          if ((uStack_204 & 0x1f) == 0) {
            iStack_200 = (**(code **)(puStack_238 + -0x7dd8))(uStack_204,"e_cswift.c",0x252);
            if (iStack_200 == 0) goto LAB_005d398c;
            (**(code **)(puStack_238 + -0x7be0))(ppuStack_30c,iStack_200);
LAB_005d33d8:
            unaff_s7 = (undefined4 *)0x670000;
            iVar2 = (**(code **)(puStack_238 + -0x7bec))(puStack_308);
            iVar3 = iVar2 + 7;
            if (iVar2 + 7 < 0) {
              iVar3 = iVar2 + 0xe;
            }
            uStack_1fc = iVar3 >> 3;
            if ((uStack_1fc & 0x1f) == 0) {
              iStack_1f8 = (**(code **)(puStack_238 + -0x7dd8))(uStack_1fc,"e_cswift.c",0x252);
              if (iStack_1f8 != 0) {
                (**(code **)(puStack_238 + -0x7be0))(puStack_308,iStack_1f8);
                goto LAB_005d3480;
              }
            }
            else {
              iStack_224 = 0;
              do {
                uStack_1fc = uStack_1fc + 1;
                iStack_224 = iStack_224 + 1;
              } while ((uStack_1fc & 0x1f) != 0);
              iStack_1f8 = (**(code **)(puStack_238 + -0x7dd8))(uStack_1fc,"e_cswift.c",0x252);
              if (iStack_1f8 != 0) {
                (**(code **)(puStack_238 + -0x7be0))(puStack_308,iStack_1f8 + iStack_224);
                (**(code **)(puStack_238 + -0x53e0))(iStack_1f8,0,iStack_224);
LAB_005d3480:
                iVar2 = (**(code **)(puStack_238 + -0x7bec))(unaff_s8);
                iVar3 = iVar2 + 7;
                if (iVar2 + 7 < 0) {
                  iVar3 = iVar2 + 0xe;
                }
                uStack_1f4 = iVar3 >> 3;
                if ((uStack_1f4 & 0x1f) == 0) {
                  iStack_1f0 = (**(code **)(puStack_238 + -0x7dd8))(uStack_1f4,"e_cswift.c",0x252);
                  if (iStack_1f0 == 0) goto LAB_005d3a20;
                  (**(code **)(puStack_238 + -0x7be0))(unaff_s8,iStack_1f0);
                }
                else {
                  iStack_224 = 0;
                  do {
                    uStack_1f4 = uStack_1f4 + 1;
                    iStack_224 = iStack_224 + 1;
                  } while ((uStack_1f4 & 0x1f) != 0);
                  iStack_1f0 = (**(code **)(puStack_238 + -0x7dd8))(uStack_1f4,"e_cswift.c",0x252);
                  if (iStack_1f0 == 0) {
LAB_005d3a20:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_238 + -0x589c))();
                    }
                    pcVar17 = *(code **)(puStack_238 + -0x6eb0);
                    ppuStack_240 = (undefined4 **)0x297;
                    goto LAB_005d39c8;
                  }
                  (**(code **)(puStack_238 + -0x7be0))(unaff_s8,iStack_1f0 + iStack_224);
                  (**(code **)(puStack_238 + -0x53e0))(iStack_1f0,0,iStack_224);
                }
                iVar2 = (**(code **)(puStack_238 + -0x7bec))(ppuStack_22c);
                iVar3 = iVar2 + 7;
                if (iVar2 + 7 < 0) {
                  iVar3 = iVar2 + 0xe;
                }
                uStack_1ec = iVar3 >> 3;
                if ((uStack_1ec & 0x1f) == 0) {
                  iStack_1e8 = (**(code **)(puStack_238 + -0x7dd8))(uStack_1ec,"e_cswift.c",0x252);
                  if (iStack_1e8 == 0) goto LAB_005d3acc;
                  (**(code **)(puStack_238 + -0x7be0))(ppuStack_22c,iStack_1e8);
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_1ec = uStack_1ec + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_1ec & 0x1f) != 0);
                  iStack_1e8 = (**(code **)(puStack_238 + -0x7dd8))(uStack_1ec,"e_cswift.c",0x252);
                  if (iStack_1e8 == 0) {
LAB_005d3acc:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_238 + -0x589c))();
                    }
                    pcVar17 = *(code **)(puStack_238 + -0x6eb0);
                    ppuStack_240 = (undefined4 **)0x29c;
                    goto LAB_005d39c8;
                  }
                  (**(code **)(puStack_238 + -0x7be0))(ppuStack_22c,iStack_1e8 + (int)unaff_s8);
                  (**(code **)(puStack_238 + -0x53e0))(iStack_1e8,0,unaff_s8);
                }
                iVar2 = (**(code **)(puStack_238 + -0x7bec))(puStack_228);
                iVar3 = iVar2 + 7;
                if (iVar2 + 7 < 0) {
                  iVar3 = iVar2 + 0xe;
                }
                uStack_1e4 = iVar3 >> 3;
                if ((uStack_1e4 & 0x1f) == 0) {
                  iStack_1e0 = (**(code **)(puStack_238 + -0x7dd8))(uStack_1e4,"e_cswift.c",0x252);
                  if (iStack_1e0 == 0) goto LAB_005d3b74;
                  (**(code **)(puStack_238 + -0x7be0))(puStack_228,iStack_1e0);
LAB_005d3660:
                  if (((int)ppuStack_310[2] < *(int *)((int)pcStack_274 + 4)) &&
                     (iVar3 = (**(code **)(puStack_238 + -0x6860))(ppuStack_310), iVar3 == 0)) {
                    ppuVar13 = (undefined4 **)0x2a7;
                    goto LAB_005d3b78;
                  }
                  if (((int)ppuStack_314[2] < puStack_308[1] + (int)ppuStack_30c[1]) &&
                     (iVar3 = (**(code **)(puStack_238 + -0x6860))(ppuStack_314), iVar3 == 0)) {
                    ppuVar13 = (undefined4 **)0x2a7;
                    goto LAB_005d3b78;
                  }
                  ppuVar5 = (undefined4 **)
                            (*(code *)p_CSwift_AttachKeyParam)(uStack_21c,&uStack_208);
                  if (ppuVar5 != (undefined4 **)0xffffd8ea) {
                    if (ppuVar5 == (undefined4 **)0x0) {
                      uStack_218 = (**(code **)(puStack_238 + -0x7be0))(pcStack_274,*ppuStack_310);
                      puStack_214 = *ppuStack_310;
                      iVar2 = (**(code **)(puStack_238 + -0x7bec))(ppuStack_30c);
                      iVar3 = iVar2 + 7;
                      if (iVar2 + 7 < 0) {
                        iVar3 = iVar2 + 0xe;
                      }
                      puStack_210 = (undefined4 *)((iVar3 >> 3) << 1);
                      (**(code **)(puStack_238 + -0x53e0))(*ppuStack_314,0,puStack_210);
                      puStack_20c = *ppuStack_314;
                      pcVar16 = (char *)0x1;
                      ppuStack_240 = &puStack_210;
                      uStack_23c = 1;
                      ppuVar5 = (undefined4 **)
                                (*(code *)p_CSwift_SimpleRequest)(uStack_21c,1,&uStack_218);
                      if (ppuVar5 == (undefined4 **)0x0) {
                        ppuStack_318 = (undefined4 **)0x1;
                        puVar1 = (undefined4 *)0x1;
                        pcStack_300 = (char *)puStack_210;
                        (**(code **)(puStack_238 + -0x74f0))(*ppuStack_314);
                        goto LAB_005d3868;
                      }
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2c8);
                      pcVar17 = *(code **)(puStack_238 + -0x54a0);
                      ppuStack_240 = ppuVar5;
                    }
                    else {
                      ppuStack_22c = ppuVar5;
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2b7);
                      pcVar17 = *(code **)(puStack_238 + -0x54a0);
                      ppuStack_240 = ppuStack_22c;
                    }
                    pcVar16 = &DAT_0066fa48;
                    ppuVar13 = apuStack_1dc;
                    (*pcVar17)(ppuVar13,1,0xd);
                    pcStack_300 = "CryptoSwift error number is ";
                    ppuStack_318 = (undefined4 **)0x1;
                    puVar1 = (undefined4 *)0x0;
                    (**(code **)(puStack_238 + -0x6c7c))(2);
                    goto LAB_005d3868;
                  }
                  ppuVar13 = (undefined4 **)0x2b2;
                  pcStack_300 = &DAT_00000065;
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_1e4 = uStack_1e4 + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_1e4 & 0x1f) != 0);
                  iStack_1e0 = (**(code **)(puStack_238 + -0x7dd8))(uStack_1e4,"e_cswift.c",0x252);
                  if (iStack_1e0 != 0) {
                    (**(code **)(puStack_238 + -0x7be0))(puStack_228,iStack_1e0 + (int)unaff_s8);
                    (**(code **)(puStack_238 + -0x53e0))(iStack_1e0,0,unaff_s8);
                    goto LAB_005d3660;
                  }
LAB_005d3b74:
                  ppuVar13 = (undefined4 **)0x2a1;
LAB_005d3b78:
                  pcStack_300 = (char *)0x67;
                }
                ppuStack_318 = (undefined4 **)0x1;
                ERR_CSWIFT_error_constprop_3(0x6a);
                puVar1 = (undefined4 *)0x0;
                goto LAB_005d3868;
              }
            }
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_238 + -0x589c))();
            }
            pcVar17 = *(code **)(puStack_238 + -0x6eb0);
            ppuStack_240 = (undefined4 **)0x292;
          }
          else {
            iStack_224 = 0;
            do {
              uStack_204 = uStack_204 + 1;
              iStack_224 = iStack_224 + 1;
            } while ((uStack_204 & 0x1f) != 0);
            iStack_200 = (**(code **)(puStack_238 + -0x7dd8))(uStack_204,"e_cswift.c",0x252);
            if (iStack_200 != 0) {
              (**(code **)(puStack_238 + -0x7be0))(ppuStack_30c,iStack_200 + iStack_224);
              (**(code **)(puStack_238 + -0x53e0))(iStack_200,0,iStack_224);
              goto LAB_005d33d8;
            }
LAB_005d398c:
            pcVar17 = *(code **)(puStack_238 + -0x6eb0);
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_238 + -0x589c))();
              pcVar17 = *(code **)(puStack_238 + -0x6eb0);
            }
            ppuStack_240 = (undefined4 **)0x28d;
          }
LAB_005d39c8:
          pcVar16 = "e_cswift.c";
          unaff_s7 = (undefined4 *)0x670000;
          ppuVar13 = (undefined4 **)0x67;
          pcStack_300 = &DAT_0000006a;
          ppuStack_318 = (undefined4 **)0x1;
          (*pcVar17)(CSWIFT_lib_error_code);
          puVar1 = (undefined4 *)0x0;
        }
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_238 + -0x589c))();
        }
        ppuVar13 = (undefined4 **)&DAT_0000006c;
        pcVar16 = "e_cswift.c";
        ppuStack_240 = (undefined4 **)0x276;
        pcStack_300 = &DAT_0000006a;
        ppuStack_318 = (undefined4 **)0x0;
        (**(code **)(puStack_238 + -0x6eb0))(CSWIFT_lib_error_code);
        puVar1 = (undefined4 *)0x0;
        ppuStack_310 = (undefined4 **)0x0;
        ppuStack_314 = (undefined4 **)0x0;
      }
LAB_005d3868:
      ppuVar5 = ppuVar13;
      if (iStack_200 != 0) {
        (**(code **)(puStack_238 + -0x7f58))();
        ppuVar5 = ppuVar13;
      }
      if (iStack_1f8 != 0) {
        (**(code **)(puStack_238 + -0x7f58))();
      }
      if (iStack_1f0 != 0) {
        (**(code **)(puStack_238 + -0x7f58))();
      }
      if (iStack_1e8 != 0) {
        (**(code **)(puStack_238 + -0x7f58))();
      }
      if (iStack_1e0 != 0) {
        (**(code **)(puStack_238 + -0x7f58))();
      }
      if (ppuStack_314 != (undefined4 **)0x0) {
        (**(code **)(puStack_238 + -0x7dc4))(ppuStack_314);
      }
      if (ppuStack_310 != (undefined4 **)0x0) {
        (**(code **)(puStack_238 + -0x7dc4))(ppuStack_310);
      }
      pcStack_274 = (char *)puVar1;
      if (ppuStack_318 != (undefined4 **)0x0) {
        (*p_CSwift_ReleaseAccContext)(uStack_21c);
      }
    }
    else {
      pcStack_300 = pcStack_274;
      puVar1 = (undefined4 *)(**(code **)(iVar3 + 0x14))(ppuVar13);
      ppuStack_310 = (undefined4 **)pcVar15;
    }
  }
  if (iStack_1cc == *(int *)puStack_320) {
    return puVar1;
  }
  pcStack_254 = cswift_dsa_sign;
  iStack_2d4 = iStack_1cc;
  (**(code **)(puStack_238 + -0x5328))();
  puStack_304 = PTR___stack_chk_guard_006aabf0;
  puStack_2e0 = &_gp;
  puStack_278 = puStack_320;
  iStack_27c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_2f4 = pcStack_300;
  ppuVar13 = ppuVar5;
  ppuStack_270 = ppuStack_318;
  ppuStack_26c = ppuStack_314;
  ppuStack_268 = ppuStack_310;
  ppuStack_264 = ppuStack_30c;
  puStack_260 = puStack_308;
  puStack_25c = unaff_s7;
  puStack_258 = unaff_s8;
  puVar4 = (undefined *)(*(code *)PTR_BN_CTX_new_006a8a38)();
  if (puVar4 == (undefined *)0x0) {
    puStack_31c = (undefined4 *)0x0;
  }
  else {
    iVar3 = (*p_CSwift_AcquireAccContext)(&uStack_2cc);
    if (iVar3 == 0) {
      (**(code **)(puStack_2e0 + -0x689c))(puVar4);
      ppuStack_314 = (undefined4 **)(**(code **)(puStack_2e0 + -0x6898))(puVar4);
      ppuStack_310 = (undefined4 **)(**(code **)(puStack_2e0 + -0x6898))(puVar4);
      ppuStack_30c = (undefined4 **)(**(code **)(puStack_2e0 + -0x6898))(puVar4);
      puStack_308 = (undefined4 *)(**(code **)(puStack_2e0 + -0x6898))(puVar4);
      ppuStack_318 = (undefined4 **)(**(code **)(puStack_2e0 + -0x6898))(puVar4);
      if (ppuStack_318 == (undefined4 **)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_2e0 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_2e0 + -0x6eb0);
        ppuVar13 = (undefined4 **)0x66;
        ppuStack_2e8 = (undefined4 **)0x348;
LAB_005d40a4:
        pcVar16 = "e_cswift.c";
        pcStack_2f4 = &DAT_00000065;
        puStack_31c = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if (((int)ppuStack_314[2] < (int)ppuVar5[3][1]) &&
           (iVar3 = (**(code **)(puStack_2e0 + -0x6860))(ppuStack_314), iVar3 == 0)) {
LAB_005d40cc:
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_2e0 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_2e0 + -0x6eb0);
          ppuVar13 = (undefined4 **)0x67;
          ppuStack_2e8 = (undefined4 **)0x351;
          goto LAB_005d40a4;
        }
        pcVar17 = *(code **)(puStack_2e0 + -0x6860);
        if ((int)ppuStack_310[2] < (int)ppuVar5[4][1]) {
          iVar3 = (*pcVar17)(ppuStack_310);
          if (iVar3 != 0) {
            pcVar17 = *(code **)(puStack_2e0 + -0x6860);
            if ((int)ppuStack_30c[2] < (int)ppuVar5[5][1]) goto LAB_005d411c;
            goto LAB_005d3da4;
          }
          goto LAB_005d40cc;
        }
        if ((int)ppuStack_30c[2] < (int)ppuVar5[5][1]) {
LAB_005d411c:
          iVar3 = (*pcVar17)(ppuStack_30c);
          if (iVar3 == 0) goto LAB_005d40cc;
          pcVar17 = *(code **)(puStack_2e0 + -0x6860);
          if ((int)puStack_308[2] < (int)ppuVar5[7][1]) goto LAB_005d4144;
LAB_005d3dbc:
          puVar1 = ppuVar5[3];
          pcVar17 = *(code **)(puStack_2e0 + -0x6860);
          if ((int)ppuStack_318[2] < (int)puVar1[1]) {
LAB_005d4170:
            iVar3 = (*pcVar17)(ppuStack_318);
            if (iVar3 == 0) goto LAB_005d40cc;
            puVar1 = ppuVar5[3];
          }
        }
        else {
LAB_005d3da4:
          pcVar17 = *(code **)(puStack_2e0 + -0x6860);
          if ((int)ppuVar5[7][1] <= (int)puStack_308[2]) goto LAB_005d3dbc;
LAB_005d4144:
          iVar3 = (*pcVar17)(puStack_308);
          if (iVar3 == 0) goto LAB_005d40cc;
          puVar1 = ppuVar5[3];
          if ((int)ppuStack_318[2] < (int)puVar1[1]) {
            pcVar17 = *(code **)(puStack_2e0 + -0x6860);
            goto LAB_005d4170;
          }
        }
        uStack_2b8 = 3;
        uStack_2b4 = (**(code **)(puStack_2e0 + -0x7be0))(puVar1,*ppuStack_314);
        puStack_2b0 = *ppuStack_314;
        uStack_2ac = (**(code **)(puStack_2e0 + -0x7be0))(ppuVar5[4],*ppuStack_310);
        puStack_2a8 = *ppuStack_310;
        uStack_2a4 = (**(code **)(puStack_2e0 + -0x7be0))(ppuVar5[5],*ppuStack_30c);
        puStack_2a0 = *ppuStack_30c;
        uStack_29c = (**(code **)(puStack_2e0 + -0x7be0))(ppuVar5[7],*puStack_308);
        uStack_298 = *puStack_308;
        ppuStack_314 = (undefined4 **)(*(code *)p_CSwift_AttachKeyParam)(uStack_2cc,&uStack_2b8);
        if (ppuStack_314 == (undefined4 **)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_2e0 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_2e0 + -0x6eb0);
          ppuVar13 = (undefined4 **)&DAT_00000065;
          ppuStack_2e8 = (undefined4 **)0x368;
          goto LAB_005d40a4;
        }
        if (ppuStack_314 == (undefined4 **)0x0) {
          iStack_2c4 = iStack_2d4;
          puStack_2c8 = (undefined4 *)pcStack_300;
          iVar2 = (**(code **)(puStack_2e0 + -0x7bec))(ppuVar5[3]);
          iVar3 = iVar2 + 7;
          if (iVar2 + 7 < 0) {
            iVar3 = iVar2 + 0xe;
          }
          puStack_2c0 = (undefined4 *)(iVar3 >> 3);
          (**(code **)(puStack_2e0 + -0x53e0))(*ppuStack_318,0,puStack_2c0);
          puStack_2bc = *ppuStack_318;
          pcVar16 = (char *)0x1;
          ppuVar13 = &puStack_2c8;
          pcStack_2f4 = (char *)0x3;
          ppuStack_2e8 = &puStack_2c0;
          uStack_2e4 = 1;
          ppuVar5 = (undefined4 **)(*(code *)p_CSwift_SimpleRequest)(uStack_2cc);
          if (ppuVar5 != (undefined4 **)0x0) {
            ppuStack_318 = (undefined4 **)&_ITM_registerTMCloneTable;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_2e0 + -0x589c))();
            }
            ppuStack_2e8 = (undefined4 **)0x37f;
            (**(code **)(puStack_2e0 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
            pcVar17 = *(code **)(puStack_2e0 + -0x54a0);
            ppuStack_2e8 = ppuVar5;
            goto LAB_005d3fd8;
          }
          puStack_31c = (undefined4 *)(**(code **)(puStack_2e0 + -0x6660))();
          if (puStack_31c != (undefined4 *)0x0) {
            uVar6 = (**(code **)(puStack_2e0 + -0x74f0))(*ppuStack_318,0x14,0);
            ppuVar13 = (undefined4 **)0x0;
            pcStack_2f4 = &DAT_00000014;
            puVar1 = *ppuStack_318;
            *puStack_31c = uVar6;
            uVar6 = (**(code **)(puStack_2e0 + -0x74f0))(puVar1 + 5);
            puStack_31c[1] = uVar6;
          }
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_2e0 + -0x589c))();
          }
          ppuStack_2e8 = (undefined4 **)0x36d;
          (**(code **)(puStack_2e0 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_2e0 + -0x54a0);
          ppuStack_2e8 = ppuStack_314;
LAB_005d3fd8:
          pcVar16 = &DAT_0066fa48;
          ppuVar13 = apuStack_28c;
          (*pcVar17)(ppuVar13,1,0xd);
          pcStack_2f4 = "CryptoSwift error number is ";
          puStack_31c = (undefined4 *)0x0;
          (**(code **)(puStack_2e0 + -0x6c7c))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_2cc);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_2e0 + -0x589c))();
      }
      ppuVar13 = (undefined4 **)&DAT_0000006c;
      pcVar16 = "e_cswift.c";
      ppuStack_2e8 = (undefined4 **)0x33b;
      pcStack_2f4 = &DAT_00000065;
      puStack_31c = (undefined4 *)0x0;
      (**(code **)(puStack_2e0 + -0x6eb0))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_2e0 + -0x688c))(puVar4);
    (**(code **)(puStack_2e0 + -0x74a0))(puVar4);
    puStack_320 = puVar4;
  }
  if (iStack_27c == *(int *)puStack_304) {
    return puStack_31c;
  }
  pcStack_2fc = cswift_dsa_verify;
  iVar3 = iStack_27c;
  (**(code **)(puStack_2e0 + -0x5328))();
  puVar4 = PTR___stack_chk_guard_006aabf0;
  iStack_324 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)0xffffffff;
    goto LAB_005d45fc;
  }
  iVar7 = (*p_CSwift_AcquireAccContext)(&uStack_380);
  if (iVar7 == 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar2);
    puVar1 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar2);
    puVar8 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar2);
    puVar9 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar2);
    puVar10 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar2);
    piVar11 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar2);
    if (piVar11 == (int *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar14 = 0x66;
      uVar6 = 0x3b7;
LAB_005d4718:
      puVar1 = (undefined4 *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,uVar14,"e_cswift.c",uVar6);
    }
    else {
      if (((int)puVar1[2] < (int)(*(undefined4 **)((int)pcVar16 + 0xc))[1]) &&
         (iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar1), iVar7 == 0)) {
LAB_005d4744:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar14 = 0x67;
        uVar6 = 0x3c0;
        goto LAB_005d4718;
      }
      if ((int)puVar8[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x10))[1]) {
        iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar8);
        if (iVar7 != 0) {
          if ((int)puVar9[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x14))[1]) goto LAB_005d47a8;
          goto LAB_005d43e4;
        }
        goto LAB_005d4744;
      }
      if ((int)puVar9[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x14))[1]) {
LAB_005d47a8:
        iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar9);
        if (iVar7 == 0) goto LAB_005d4744;
        if ((int)puVar10[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x18))[1]) goto LAB_005d47d0;
LAB_005d43fc:
        iVar7 = piVar11[2];
      }
      else {
LAB_005d43e4:
        if ((int)(*(undefined4 **)((int)pcVar16 + 0x18))[1] <= (int)puVar10[2]) goto LAB_005d43fc;
LAB_005d47d0:
        iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar10);
        if (iVar7 == 0) goto LAB_005d4744;
        iVar7 = piVar11[2];
      }
      if ((iVar7 < 0x28) && (iVar7 = (*(code *)PTR_bn_expand2_006a9680)(piVar11,0x28), iVar7 == 0))
      goto LAB_005d4744;
      uStack_370 = 3;
      uStack_36c = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0xc),*puVar1);
      uStack_368 = *puVar1;
      uStack_364 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x10),*puVar8);
      uStack_360 = *puVar8;
      uStack_35c = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x14),*puVar9);
      uStack_358 = *puVar9;
      uStack_354 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x18),*puVar10)
      ;
      uStack_350 = *puVar10;
      iVar7 = (*(code *)p_CSwift_AttachKeyParam)(uStack_380,&uStack_370);
      if (iVar7 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar14 = 0x65;
        uVar6 = 0x3d7;
        goto LAB_005d4718;
      }
      if (iVar7 == 0) {
        iStack_338 = *piVar11;
        puStack_344 = (undefined4 *)pcStack_2f4;
        uStack_33c = 0x28;
        iStack_340 = iVar3;
        (*(code *)PTR_memset_006aab00)(iStack_338,0,0x28);
        iVar3 = iStack_338;
        puVar1 = *ppuVar13;
        iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar1);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(puVar1,(iVar3 - (iVar7 >> 3)) + 0x14);
        iVar3 = iStack_338;
        puVar1 = ppuVar13[1];
        iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar1);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(puVar1,(iVar3 - (iVar7 >> 3)) + 0x28);
        uStack_378 = 4;
        piStack_374 = &iStack_37c;
        iVar7 = (*(code *)p_CSwift_SimpleRequest)(uStack_380,4,&puStack_344,2,&uStack_378,1);
        if (iVar7 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          uVar6 = 0x3f2;
          goto LAB_005d4698;
        }
        puVar1 = (undefined4 *)(uint)(iStack_37c != 0);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar6 = 0x3dc;
LAB_005d4698:
        (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",uVar6);
        (*(code *)PTR___sprintf_chk_006aaa40)(auStack_334,1,0xd,&DAT_0066fa48,iVar7);
        puVar1 = (undefined4 *)0xffffffff;
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"CryptoSwift error number is ",auStack_334);
      }
    }
    (*p_CSwift_ReleaseAccContext)(uStack_380);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    puVar1 = (undefined4 *)0xffffffff;
    (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,0x6c,"e_cswift.c",0x3aa);
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(iVar2);
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar2);
LAB_005d45fc:
  if (iStack_324 == *(int *)puVar4) {
    return puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar3 != 0) {
    iVar2 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar3,"cswift");
    if (((((iVar2 != 0) &&
          (iVar2 = (*(code *)PTR_ENGINE_set_name_006a99e8)
                             (iVar3,"CryptoSwift hardware engine support"), iVar2 != 0)) &&
         (iVar2 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar3,cswift_rsa), iVar2 != 0)) &&
        (((iVar2 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar3,cswift_dsa), iVar2 != 0 &&
          (iVar2 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar3,cswift_dh), iVar2 != 0)) &&
         ((iVar2 = (*(code *)PTR_ENGINE_set_RAND_006aa654)(iVar3,cswift_random), iVar2 != 0 &&
          ((iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar3,cswift_destroy),
           iVar2 != 0 &&
           (iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar3,cswift_init), iVar2 != 0)
           ))))))) &&
       ((iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar3,cswift_finish), iVar2 != 0
        && ((iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar3,cswift_ctrl), iVar2 != 0
            && (iVar2 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar3,cswift_cmd_defns),
               iVar2 != 0)))))) {
      iVar2 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
      cswift_rsa._4_4_ = *(undefined4 *)(iVar2 + 4);
      cswift_rsa._8_4_ = *(undefined4 *)(iVar2 + 8);
      cswift_rsa._12_4_ = *(undefined4 *)(iVar2 + 0xc);
      cswift_rsa._16_4_ = *(undefined4 *)(iVar2 + 0x10);
      iVar2 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
      cswift_dh._4_4_ = *(undefined4 *)(iVar2 + 4);
      cswift_dh._8_4_ = *(undefined4 *)(iVar2 + 8);
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      if (CSWIFT_error_init != 0) {
        CSWIFT_error_init = 0;
        (*(code *)PTR_ERR_load_strings_006a9564)(CSWIFT_lib_error_code,CSWIFT_str_functs);
        (*(code *)PTR_ERR_load_strings_006a9564)(CSWIFT_lib_error_code,CSWIFT_str_reasons);
        CSWIFT_lib_name._0_4_ = CSWIFT_lib_error_code << 0x18;
        (*(code *)PTR_ERR_load_strings_006a9564)(0,CSWIFT_lib_name);
      }
      (*(code *)PTR_ENGINE_add_006a99d8)(iVar3);
      (*(code *)PTR_ENGINE_free_006a7f84)(iVar3);
                    /* WARNING: Could not recover jumptable at 0x005d4b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar1 = (undefined4 *)(*(code *)PTR_ERR_clear_error_006a7fe0)();
      return puVar1;
    }
                    /* WARNING: Could not recover jumptable at 0x005d4954. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar1 = (undefined4 *)(*(code *)PTR_ENGINE_free_006a7f84)(iVar3);
    return puVar1;
  }
  return (undefined4 *)0x0;
}

