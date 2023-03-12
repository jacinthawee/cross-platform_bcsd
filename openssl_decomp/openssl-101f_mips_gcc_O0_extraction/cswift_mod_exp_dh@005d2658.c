
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 *
cswift_mod_exp_dh(undefined4 param_1,undefined4 **param_2,int param_3,undefined4 **param_4,
                 int param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
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
  undefined4 *unaff_s4;
  undefined4 *unaff_s5;
  undefined4 *unaff_s7;
  code *pcVar17;
  undefined4 *unaff_s8;
  undefined4 uStack_330;
  int iStack_32c;
  undefined4 uStack_328;
  int *piStack_324;
  undefined4 uStack_320;
  undefined4 uStack_31c;
  undefined4 uStack_318;
  undefined4 uStack_314;
  undefined4 uStack_310;
  undefined4 uStack_30c;
  undefined4 uStack_308;
  undefined4 uStack_304;
  undefined4 uStack_300;
  undefined4 *puStack_2f4;
  int iStack_2f0;
  undefined4 uStack_2ec;
  int iStack_2e8;
  undefined auStack_2e4 [16];
  int iStack_2d4;
  undefined *puStack_2d0;
  undefined4 *puStack_2cc;
  undefined4 **ppuStack_2c8;
  undefined4 **ppuStack_2c4;
  undefined4 **ppuStack_2c0;
  undefined4 **ppuStack_2bc;
  undefined4 *puStack_2b8;
  undefined *puStack_2b4;
  char *pcStack_2b0;
  code *pcStack_2ac;
  char *pcStack_2a4;
  undefined4 **ppuStack_298;
  undefined4 uStack_294;
  undefined *puStack_290;
  int iStack_284;
  undefined4 uStack_27c;
  undefined4 *puStack_278;
  int iStack_274;
  undefined4 *puStack_270;
  undefined4 *puStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 *puStack_260;
  undefined4 uStack_25c;
  undefined4 *puStack_258;
  undefined4 uStack_254;
  undefined4 *puStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 *apuStack_23c [4];
  int iStack_22c;
  undefined *puStack_228;
  char *pcStack_224;
  undefined4 **ppuStack_220;
  undefined4 **ppuStack_21c;
  undefined4 **ppuStack_218;
  undefined4 **ppuStack_214;
  undefined4 *puStack_210;
  undefined4 *puStack_20c;
  undefined4 *puStack_208;
  code *pcStack_204;
  undefined4 **ppuStack_1f0;
  undefined4 uStack_1ec;
  undefined *puStack_1e8;
  undefined4 **ppuStack_1dc;
  undefined4 *puStack_1d8;
  int iStack_1d4;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 *puStack_1c4;
  undefined4 *puStack_1c0;
  undefined4 *puStack_1bc;
  undefined4 uStack_1b8;
  uint uStack_1b4;
  int iStack_1b0;
  uint uStack_1ac;
  int iStack_1a8;
  uint uStack_1a4;
  int iStack_1a0;
  uint uStack_19c;
  int iStack_198;
  uint uStack_194;
  int iStack_190;
  undefined4 *apuStack_18c [4];
  int iStack_17c;
  undefined4 **ppuStack_178;
  undefined *puStack_174;
  char *pcStack_170;
  char *pcStack_16c;
  undefined4 **ppuStack_168;
  undefined4 **ppuStack_164;
  undefined4 *puStack_160;
  undefined4 *puStack_15c;
  undefined4 *puStack_158;
  code *pcStack_154;
  undefined4 **ppuStack_140;
  undefined4 *puStack_13c;
  undefined *puStack_138;
  undefined4 **ppuStack_12c;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 *puStack_11c;
  undefined4 *puStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 *apuStack_e4 [4];
  undefined4 **ppuStack_d4;
  undefined4 uStack_d0;
  undefined *puStack_cc;
  undefined4 *puStack_c8;
  undefined4 **ppuStack_c4;
  undefined4 *puStack_c0;
  undefined4 *puStack_bc;
  int iStack_b8;
  undefined4 *puStack_b4;
  undefined4 *puStack_b0;
  code *pcStack_ac;
  undefined4 **local_98;
  undefined4 *local_94;
  undefined *local_90;
  undefined4 **local_84;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 *local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 *apuStack_3c [4];
  undefined4 **local_2c;
  
  puStack_cc = PTR___stack_chk_guard_006aabf0;
  local_90 = &_gp;
  local_2c = *(undefined4 ***)PTR___stack_chk_guard_006aabf0;
  local_84 = param_2;
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_7c);
  if (iVar1 == 0) {
    (**(code **)(local_90 + -0x689c))(param_6);
    unaff_s4 = (undefined4 *)(**(code **)(local_90 + -0x6898))(param_6);
    unaff_s7 = (undefined4 *)(**(code **)(local_90 + -0x6898))(param_6);
    unaff_s8 = (undefined4 *)(**(code **)(local_90 + -0x6898))(param_6);
    unaff_s5 = (undefined4 *)(**(code **)(local_90 + -0x6898))(param_6);
    if (unaff_s5 == (undefined4 *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
      }
      pcVar17 = *(code **)(local_90 + -0x6eb0);
      ppuStack_2c0 = (undefined4 **)0x66;
      local_98 = (undefined4 **)0x20a;
LAB_005d29fc:
      pcStack_16c = "e_cswift.c";
      pcStack_170 = &DAT_00000069;
      puStack_c8 = (undefined4 *)0x0;
      (*pcVar17)(CSWIFT_lib_error_code);
    }
    else {
      pcVar17 = *(code **)(local_90 + -0x6860);
      if ((int)unaff_s4[2] < *(int *)(param_5 + 4)) {
        iVar1 = (*pcVar17)(unaff_s4);
        if (iVar1 != 0) {
          if ((int)unaff_s7[2] < (int)param_4[1]) {
            pcVar17 = *(code **)(local_90 + -0x6860);
            goto LAB_005d2a4c;
          }
          goto LAB_005d27e0;
        }
LAB_005d299c:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
        }
        pcVar17 = *(code **)(local_90 + -0x6eb0);
        ppuStack_2c0 = (undefined4 **)0x67;
        local_98 = (undefined4 **)0x210;
        goto LAB_005d29fc;
      }
      if ((int)unaff_s7[2] < (int)param_4[1]) {
LAB_005d2a4c:
        iVar1 = (*pcVar17)(unaff_s7);
        if (iVar1 == 0) goto LAB_005d299c;
      }
LAB_005d27e0:
      if ((((int)unaff_s8[2] < *(int *)(param_3 + 4)) &&
          (iVar1 = (**(code **)(local_90 + -0x6860))(unaff_s8), iVar1 == 0)) ||
         (((int)unaff_s5[2] < *(int *)(param_5 + 4) &&
          (iVar1 = (**(code **)(local_90 + -0x6860))(unaff_s5), iVar1 == 0)))) goto LAB_005d299c;
      local_68 = 2;
      local_64 = (**(code **)(local_90 + -0x7be0))(param_5,*unaff_s4);
      local_60 = *unaff_s4;
      local_5c = (**(code **)(local_90 + -0x7be0))(param_4,*unaff_s7);
      local_58 = *unaff_s7;
      param_4 = (undefined4 **)(*p_CSwift_AttachKeyParam)(local_7c,&local_68);
      if (param_4 == (undefined4 **)0xffffd8ea) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
        }
        pcVar17 = *(code **)(local_90 + -0x6eb0);
        ppuStack_2c0 = (undefined4 **)&DAT_00000065;
        local_98 = (undefined4 **)0x221;
        goto LAB_005d29fc;
      }
      if (param_4 == (undefined4 **)0x0) {
        local_78 = (**(code **)(local_90 + -0x7be0))(param_3,*unaff_s8);
        local_74 = *unaff_s8;
        iVar4 = (**(code **)(local_90 + -0x7bec))(param_5);
        iVar1 = iVar4 + 7;
        if (iVar4 + 7 < 0) {
          iVar1 = iVar4 + 0xe;
        }
        local_70 = (undefined4 *)(iVar1 >> 3);
        (**(code **)(local_90 + -0x53e0))(*unaff_s5,0,local_70);
        local_6c = *unaff_s5;
        pcStack_16c = (char *)0x1;
        local_98 = &local_70;
        local_94 = (undefined4 *)0x1;
        ppuVar13 = (undefined4 **)(*p_CSwift_SimpleRequest)(local_7c,2,&local_78);
        if (ppuVar13 != (undefined4 **)0x0) {
          param_4 = (undefined4 **)&_ITM_registerTMCloneTable;
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
          }
          local_98 = (undefined4 **)0x237;
          (**(code **)(local_90 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(local_90 + -0x54a0);
          local_98 = ppuVar13;
          goto LAB_005d2ac0;
        }
        puStack_c8 = (undefined4 *)0x1;
        pcStack_170 = (char *)local_70;
        ppuStack_2c0 = local_84;
        (**(code **)(local_90 + -0x74f0))(*unaff_s5);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
        }
        local_98 = (undefined4 **)0x226;
        (**(code **)(local_90 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
        pcVar17 = *(code **)(local_90 + -0x54a0);
        local_98 = param_4;
LAB_005d2ac0:
        pcStack_16c = &DAT_0066fa28;
        ppuStack_2c0 = apuStack_3c;
        (*pcVar17)(ppuStack_2c0,1,0xd);
        pcStack_170 = "CryptoSwift error number is ";
        puStack_c8 = (undefined4 *)0x0;
        (**(code **)(local_90 + -0x6c7c))(2);
      }
    }
    (*p_CSwift_ReleaseAccContext)(local_7c);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
    }
    ppuStack_2c0 = (undefined4 **)&DAT_0000006c;
    pcStack_16c = "e_cswift.c";
    local_98 = (undefined4 **)0x1fe;
    pcStack_170 = &DAT_00000069;
    puStack_c8 = (undefined4 *)0x0;
    (**(code **)(local_90 + -0x6eb0))(CSWIFT_lib_error_code);
  }
  (**(code **)(local_90 + -0x688c))(param_6);
  if (local_2c == *(undefined4 ***)puStack_cc) {
    return puStack_c8;
  }
  pcStack_ac = cswift_mod_exp_mont;
  ppuStack_2bc = local_2c;
  (**(code **)(local_90 + -0x5328))();
  puStack_2b8 = local_94;
  ppuStack_178 = local_98;
  puStack_174 = PTR___stack_chk_guard_006aabf0;
  uStack_d0 = param_6;
  puStack_138 = &_gp;
  ppuStack_d4 = *(undefined4 ***)PTR___stack_chk_guard_006aabf0;
  ppuStack_c4 = param_4;
  puStack_c0 = unaff_s4;
  puStack_bc = unaff_s5;
  iStack_b8 = param_3;
  puStack_b4 = unaff_s7;
  puStack_b0 = unaff_s8;
  iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)();
  if ((((iVar1 < 0x801) &&
       (iVar1 = (**(code **)(puStack_138 + -0x7bec))(pcStack_170), iVar1 < 0x801)) &&
      (iVar1 = (**(code **)(puStack_138 + -0x7bec))(pcStack_16c), iVar1 < 0x801)) ||
     (iVar1 = (**(code **)(puStack_138 + -0x7308))(), iVar1 == 0)) {
    iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_124);
    if (iVar1 == 0) {
      (**(code **)(puStack_138 + -0x689c))(ppuStack_178);
      puStack_2b8 = (undefined4 *)(**(code **)(puStack_138 + -0x6898))(ppuStack_178);
      unaff_s7 = (undefined4 *)(**(code **)(puStack_138 + -0x6898))(ppuStack_178);
      ppuStack_12c = (undefined4 **)(**(code **)(puStack_138 + -0x6898))(ppuStack_178);
      unaff_s8 = (undefined4 *)(**(code **)(puStack_138 + -0x6898))(ppuStack_178);
      if (unaff_s8 == (undefined4 *)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_138 + -0x6eb0);
        ppuStack_2c4 = (undefined4 **)0x66;
        ppuStack_140 = (undefined4 **)0x20a;
LAB_005d2f9c:
        pcVar15 = "e_cswift.c";
        pcStack_224 = &DAT_00000069;
        puVar2 = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if (((((int)puStack_2b8[2] < (int)*(undefined4 **)((int)pcStack_16c + 4)) &&
             (iVar1 = (**(code **)(puStack_138 + -0x6860))(puStack_2b8), iVar1 == 0)) ||
            ((((int)unaff_s7[2] < (int)ppuStack_2c0[1] &&
              (iVar1 = (**(code **)(puStack_138 + -0x6860))(unaff_s7), iVar1 == 0)) ||
             (((int)ppuStack_12c[2] < *(int *)((int)pcStack_170 + 4) &&
              (iVar1 = (**(code **)(puStack_138 + -0x6860))(ppuStack_12c), iVar1 == 0)))))) ||
           (((int)unaff_s8[2] < (int)*(undefined4 **)((int)pcStack_16c + 4) &&
            (iVar1 = (**(code **)(puStack_138 + -0x6860))(unaff_s8), iVar1 == 0)))) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_138 + -0x6eb0);
          ppuStack_2c4 = (undefined4 **)0x67;
          ppuStack_140 = (undefined4 **)0x210;
          goto LAB_005d2f9c;
        }
        uStack_110 = 2;
        uStack_10c = (**(code **)(puStack_138 + -0x7be0))(pcStack_16c,*puStack_2b8);
        uStack_108 = *puStack_2b8;
        uStack_104 = (**(code **)(puStack_138 + -0x7be0))(ppuStack_2c0,*unaff_s7);
        uStack_100 = *unaff_s7;
        ppuVar13 = (undefined4 **)(*p_CSwift_AttachKeyParam)(uStack_124,&uStack_110);
        ppuStack_2c0 = ppuStack_12c;
        if (ppuVar13 == (undefined4 **)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_138 + -0x6eb0);
          ppuStack_2c4 = (undefined4 **)&DAT_00000065;
          ppuStack_140 = (undefined4 **)0x221;
          ppuStack_2c0 = ppuVar13;
          goto LAB_005d2f9c;
        }
        if (ppuVar13 == (undefined4 **)0x0) {
          uStack_120 = (**(code **)(puStack_138 + -0x7be0))(pcStack_170,*ppuStack_12c);
          puStack_11c = *ppuStack_2c0;
          iVar4 = (**(code **)(puStack_138 + -0x7bec))(pcStack_16c);
          iVar1 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar1 = iVar4 + 0xe;
          }
          puStack_118 = (undefined4 *)(iVar1 >> 3);
          (**(code **)(puStack_138 + -0x53e0))(*unaff_s8,0,puStack_118);
          uStack_114 = *unaff_s8;
          pcVar15 = (char *)0x1;
          ppuStack_140 = &puStack_118;
          puStack_13c = (undefined4 *)0x1;
          ppuVar13 = (undefined4 **)(*p_CSwift_SimpleRequest)(uStack_124,2,&uStack_120);
          if (ppuVar13 != (undefined4 **)0x0) {
            pcStack_16c = &_ITM_registerTMCloneTable;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x589c))();
            }
            ppuStack_140 = (undefined4 **)0x237;
            (**(code **)(puStack_138 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
            pcVar17 = *(code **)(puStack_138 + -0x54a0);
            ppuStack_140 = ppuVar13;
            goto LAB_005d3034;
          }
          puVar2 = (undefined4 *)0x1;
          pcStack_224 = (char *)puStack_118;
          ppuStack_2c4 = ppuStack_2bc;
          (**(code **)(puStack_138 + -0x74f0))(*unaff_s8);
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x589c))();
          }
          ppuStack_140 = (undefined4 **)0x226;
          (**(code **)(puStack_138 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_138 + -0x54a0);
          ppuStack_2c0 = ppuVar13;
          ppuStack_140 = ppuVar13;
LAB_005d3034:
          pcVar15 = &DAT_0066fa28;
          ppuStack_2c4 = apuStack_e4;
          (*pcVar17)(ppuStack_2c4,1,0xd);
          pcStack_224 = "CryptoSwift error number is ";
          puVar2 = (undefined4 *)0x0;
          (**(code **)(puStack_138 + -0x6c7c))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_124);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x589c))();
      }
      ppuStack_2c4 = (undefined4 **)&DAT_0000006c;
      pcVar15 = "e_cswift.c";
      ppuStack_140 = (undefined4 **)0x1fe;
      pcStack_224 = &DAT_00000069;
      puVar2 = (undefined4 *)0x0;
      (**(code **)(puStack_138 + -0x6eb0))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_138 + -0x688c))(ppuStack_178);
    pcStack_170 = (char *)puVar2;
  }
  else {
    puStack_13c = puStack_2b8;
    ppuStack_140 = ppuStack_178;
    pcStack_224 = pcStack_170;
    ppuStack_2c4 = ppuStack_2c0;
    pcVar15 = pcStack_16c;
    puVar2 = (undefined4 *)(**(code **)(iVar1 + 0x18))(ppuStack_2bc);
  }
  if (ppuStack_d4 == *(undefined4 ***)puStack_174) {
    return puVar2;
  }
  pcStack_154 = cswift_rsa_mod_exp;
  ppuVar13 = ppuStack_d4;
  (**(code **)(puStack_138 + -0x5328))();
  puStack_2d0 = PTR___stack_chk_guard_006aabf0;
  puStack_1e8 = &_gp;
  iStack_17c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar5 = (undefined4 **)pcStack_16c;
  ppuStack_2c8 = ppuVar13;
  ppuStack_168 = ppuStack_2c0;
  ppuStack_164 = ppuStack_2bc;
  puStack_160 = puStack_2b8;
  puStack_15c = unaff_s7;
  puStack_158 = unaff_s8;
  if ((((ppuStack_2c4[7] == (undefined4 *)0x0) ||
       (ppuVar5 = ppuStack_2c4, ppuStack_2c4[8] == (undefined4 *)0x0)) ||
      (ppuStack_2c4[9] == (undefined4 *)0x0)) ||
     ((ppuStack_2c4[10] == (undefined4 *)0x0 || (ppuStack_2c4[0xb] == (undefined4 *)0x0)))) {
    ppuStack_2c4 = ppuVar5;
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppuVar5 = (undefined4 **)&DAT_00000069;
    pcVar16 = "e_cswift.c";
    ppuStack_1f0 = (undefined4 **)0x2ed;
    pcStack_2b0 = &DAT_0000006b;
    (**(code **)(puStack_1e8 + -0x6eb0))(CSWIFT_lib_error_code);
    puVar2 = (undefined4 *)0x0;
    pcStack_224 = &_ITM_registerTMCloneTable;
  }
  else {
    pcVar16 = pcVar15;
    iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)();
    if ((((iVar1 < 0x401) &&
         (iVar1 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2c4[8]), iVar1 < 0x401)) &&
        ((iVar1 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2c4[9]), iVar1 < 0x401 &&
         ((iVar1 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2c4[10]), iVar1 < 0x401 &&
          (iVar1 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2c4[0xb]), iVar1 < 0x401)))))) ||
       (iVar1 = (**(code **)(puStack_1e8 + -0x7308))(), pcVar16 = pcVar15, iVar1 == 0)) {
      ppuStack_2bc = (undefined4 **)ppuStack_2c4[7];
      puStack_2b8 = ppuStack_2c4[8];
      unaff_s8 = ppuStack_2c4[9];
      ppuStack_1dc = (undefined4 **)ppuStack_2c4[10];
      iStack_1b0 = 0;
      iStack_1a8 = 0;
      iStack_1a0 = 0;
      iStack_198 = 0;
      iStack_190 = 0;
      puStack_1d8 = ppuStack_2c4[0xb];
      iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_1cc);
      if (iVar1 == 0) {
        ppuStack_2c0 = (undefined4 **)(**(code **)(puStack_1e8 + -0x7c2c))();
        ppuStack_2c4 = (undefined4 **)(**(code **)(puStack_1e8 + -0x7c2c))();
        if ((ppuStack_2c4 == (undefined4 **)0x0) || (ppuStack_2c0 == (undefined4 **)0x0)) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
          }
          ppuVar13 = (undefined4 **)0x66;
          pcVar16 = "e_cswift.c";
          ppuStack_1f0 = (undefined4 **)0x280;
          pcStack_2b0 = &DAT_0000006a;
          ppuStack_2c8 = (undefined4 **)0x1;
          (**(code **)(puStack_1e8 + -0x6eb0))(CSWIFT_lib_error_code);
          puVar2 = (undefined4 *)0x0;
        }
        else {
          uStack_1b8 = 1;
          iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2bc);
          iVar1 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar1 = iVar4 + 0xe;
          }
          uStack_1b4 = iVar1 >> 3;
          if ((uStack_1b4 & 0x1f) == 0) {
            iStack_1b0 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1b4,"e_cswift.c",0x252);
            if (iStack_1b0 == 0) goto LAB_005d398c;
            (**(code **)(puStack_1e8 + -0x7be0))(ppuStack_2bc,iStack_1b0);
LAB_005d33d8:
            unaff_s7 = (undefined4 *)0x670000;
            iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(puStack_2b8);
            iVar1 = iVar4 + 7;
            if (iVar4 + 7 < 0) {
              iVar1 = iVar4 + 0xe;
            }
            uStack_1ac = iVar1 >> 3;
            if ((uStack_1ac & 0x1f) == 0) {
              iStack_1a8 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1ac,"e_cswift.c",0x252);
              if (iStack_1a8 != 0) {
                (**(code **)(puStack_1e8 + -0x7be0))(puStack_2b8,iStack_1a8);
                goto LAB_005d3480;
              }
            }
            else {
              iStack_1d4 = 0;
              do {
                uStack_1ac = uStack_1ac + 1;
                iStack_1d4 = iStack_1d4 + 1;
              } while ((uStack_1ac & 0x1f) != 0);
              iStack_1a8 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1ac,"e_cswift.c",0x252);
              if (iStack_1a8 != 0) {
                (**(code **)(puStack_1e8 + -0x7be0))(puStack_2b8,iStack_1a8 + iStack_1d4);
                (**(code **)(puStack_1e8 + -0x53e0))(iStack_1a8,0,iStack_1d4);
LAB_005d3480:
                iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(unaff_s8);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                uStack_1a4 = iVar1 >> 3;
                if ((uStack_1a4 & 0x1f) == 0) {
                  iStack_1a0 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1a4,"e_cswift.c",0x252);
                  if (iStack_1a0 == 0) goto LAB_005d3a20;
                  (**(code **)(puStack_1e8 + -0x7be0))(unaff_s8,iStack_1a0);
                }
                else {
                  iStack_1d4 = 0;
                  do {
                    uStack_1a4 = uStack_1a4 + 1;
                    iStack_1d4 = iStack_1d4 + 1;
                  } while ((uStack_1a4 & 0x1f) != 0);
                  iStack_1a0 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1a4,"e_cswift.c",0x252);
                  if (iStack_1a0 == 0) {
LAB_005d3a20:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
                    }
                    pcVar17 = *(code **)(puStack_1e8 + -0x6eb0);
                    ppuStack_1f0 = (undefined4 **)0x297;
                    goto LAB_005d39c8;
                  }
                  (**(code **)(puStack_1e8 + -0x7be0))(unaff_s8,iStack_1a0 + iStack_1d4);
                  (**(code **)(puStack_1e8 + -0x53e0))(iStack_1a0,0,iStack_1d4);
                }
                iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_1dc);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                uStack_19c = iVar1 >> 3;
                if ((uStack_19c & 0x1f) == 0) {
                  iStack_198 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_19c,"e_cswift.c",0x252);
                  if (iStack_198 == 0) goto LAB_005d3acc;
                  (**(code **)(puStack_1e8 + -0x7be0))(ppuStack_1dc,iStack_198);
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_19c = uStack_19c + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_19c & 0x1f) != 0);
                  iStack_198 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_19c,"e_cswift.c",0x252);
                  if (iStack_198 == 0) {
LAB_005d3acc:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
                    }
                    pcVar17 = *(code **)(puStack_1e8 + -0x6eb0);
                    ppuStack_1f0 = (undefined4 **)0x29c;
                    goto LAB_005d39c8;
                  }
                  (**(code **)(puStack_1e8 + -0x7be0))(ppuStack_1dc,iStack_198 + (int)unaff_s8);
                  (**(code **)(puStack_1e8 + -0x53e0))(iStack_198,0,unaff_s8);
                }
                iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(puStack_1d8);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                uStack_194 = iVar1 >> 3;
                if ((uStack_194 & 0x1f) == 0) {
                  iStack_190 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_194,"e_cswift.c",0x252);
                  if (iStack_190 == 0) goto LAB_005d3b74;
                  (**(code **)(puStack_1e8 + -0x7be0))(puStack_1d8,iStack_190);
LAB_005d3660:
                  if (((int)ppuStack_2c0[2] < *(int *)((int)pcStack_224 + 4)) &&
                     (iVar1 = (**(code **)(puStack_1e8 + -0x6860))(ppuStack_2c0), iVar1 == 0)) {
                    ppuVar13 = (undefined4 **)0x2a7;
                    goto LAB_005d3b78;
                  }
                  if (((int)ppuStack_2c4[2] < puStack_2b8[1] + (int)ppuStack_2bc[1]) &&
                     (iVar1 = (**(code **)(puStack_1e8 + -0x6860))(ppuStack_2c4), iVar1 == 0)) {
                    ppuVar13 = (undefined4 **)0x2a7;
                    goto LAB_005d3b78;
                  }
                  ppuVar5 = (undefined4 **)(*p_CSwift_AttachKeyParam)(uStack_1cc,&uStack_1b8);
                  if (ppuVar5 != (undefined4 **)0xffffd8ea) {
                    if (ppuVar5 == (undefined4 **)0x0) {
                      uStack_1c8 = (**(code **)(puStack_1e8 + -0x7be0))(pcStack_224,*ppuStack_2c0);
                      puStack_1c4 = *ppuStack_2c0;
                      iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2bc);
                      iVar1 = iVar4 + 7;
                      if (iVar4 + 7 < 0) {
                        iVar1 = iVar4 + 0xe;
                      }
                      puStack_1c0 = (undefined4 *)((iVar1 >> 3) << 1);
                      (**(code **)(puStack_1e8 + -0x53e0))(*ppuStack_2c4,0,puStack_1c0);
                      puStack_1bc = *ppuStack_2c4;
                      pcVar16 = (char *)0x1;
                      ppuStack_1f0 = &puStack_1c0;
                      uStack_1ec = 1;
                      ppuVar5 = (undefined4 **)(*p_CSwift_SimpleRequest)(uStack_1cc,1,&uStack_1c8);
                      if (ppuVar5 == (undefined4 **)0x0) {
                        ppuStack_2c8 = (undefined4 **)0x1;
                        puVar2 = (undefined4 *)0x1;
                        pcStack_2b0 = (char *)puStack_1c0;
                        (**(code **)(puStack_1e8 + -0x74f0))(*ppuStack_2c4);
                        goto LAB_005d3868;
                      }
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2c8);
                      pcVar17 = *(code **)(puStack_1e8 + -0x54a0);
                      ppuStack_1f0 = ppuVar5;
                    }
                    else {
                      ppuStack_1dc = ppuVar5;
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2b7);
                      pcVar17 = *(code **)(puStack_1e8 + -0x54a0);
                      ppuStack_1f0 = ppuStack_1dc;
                    }
                    pcVar16 = &DAT_0066fa28;
                    ppuVar13 = apuStack_18c;
                    (*pcVar17)(ppuVar13,1,0xd);
                    pcStack_2b0 = "CryptoSwift error number is ";
                    ppuStack_2c8 = (undefined4 **)0x1;
                    puVar2 = (undefined4 *)0x0;
                    (**(code **)(puStack_1e8 + -0x6c7c))(2);
                    goto LAB_005d3868;
                  }
                  ppuVar13 = (undefined4 **)0x2b2;
                  pcStack_2b0 = &DAT_00000065;
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_194 = uStack_194 + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_194 & 0x1f) != 0);
                  iStack_190 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_194,"e_cswift.c",0x252);
                  if (iStack_190 != 0) {
                    (**(code **)(puStack_1e8 + -0x7be0))(puStack_1d8,iStack_190 + (int)unaff_s8);
                    (**(code **)(puStack_1e8 + -0x53e0))(iStack_190,0,unaff_s8);
                    goto LAB_005d3660;
                  }
LAB_005d3b74:
                  ppuVar13 = (undefined4 **)0x2a1;
LAB_005d3b78:
                  pcStack_2b0 = (char *)0x67;
                }
                ppuStack_2c8 = (undefined4 **)0x1;
                ERR_CSWIFT_error_constprop_3(0x6a);
                puVar2 = (undefined4 *)0x0;
                goto LAB_005d3868;
              }
            }
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
            }
            pcVar17 = *(code **)(puStack_1e8 + -0x6eb0);
            ppuStack_1f0 = (undefined4 **)0x292;
          }
          else {
            iStack_1d4 = 0;
            do {
              uStack_1b4 = uStack_1b4 + 1;
              iStack_1d4 = iStack_1d4 + 1;
            } while ((uStack_1b4 & 0x1f) != 0);
            iStack_1b0 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1b4,"e_cswift.c",0x252);
            if (iStack_1b0 != 0) {
              (**(code **)(puStack_1e8 + -0x7be0))(ppuStack_2bc,iStack_1b0 + iStack_1d4);
              (**(code **)(puStack_1e8 + -0x53e0))(iStack_1b0,0,iStack_1d4);
              goto LAB_005d33d8;
            }
LAB_005d398c:
            pcVar17 = *(code **)(puStack_1e8 + -0x6eb0);
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
              pcVar17 = *(code **)(puStack_1e8 + -0x6eb0);
            }
            ppuStack_1f0 = (undefined4 **)0x28d;
          }
LAB_005d39c8:
          pcVar16 = "e_cswift.c";
          unaff_s7 = (undefined4 *)0x670000;
          ppuVar13 = (undefined4 **)0x67;
          pcStack_2b0 = &DAT_0000006a;
          ppuStack_2c8 = (undefined4 **)0x1;
          (*pcVar17)(CSWIFT_lib_error_code);
          puVar2 = (undefined4 *)0x0;
        }
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
        }
        ppuVar13 = (undefined4 **)&DAT_0000006c;
        pcVar16 = "e_cswift.c";
        ppuStack_1f0 = (undefined4 **)0x276;
        pcStack_2b0 = &DAT_0000006a;
        ppuStack_2c8 = (undefined4 **)0x0;
        (**(code **)(puStack_1e8 + -0x6eb0))(CSWIFT_lib_error_code);
        puVar2 = (undefined4 *)0x0;
        ppuStack_2c0 = (undefined4 **)0x0;
        ppuStack_2c4 = (undefined4 **)0x0;
      }
LAB_005d3868:
      ppuVar5 = ppuVar13;
      if (iStack_1b0 != 0) {
        (**(code **)(puStack_1e8 + -0x7f58))();
        ppuVar5 = ppuVar13;
      }
      if (iStack_1a8 != 0) {
        (**(code **)(puStack_1e8 + -0x7f58))();
      }
      if (iStack_1a0 != 0) {
        (**(code **)(puStack_1e8 + -0x7f58))();
      }
      if (iStack_198 != 0) {
        (**(code **)(puStack_1e8 + -0x7f58))();
      }
      if (iStack_190 != 0) {
        (**(code **)(puStack_1e8 + -0x7f58))();
      }
      if (ppuStack_2c4 != (undefined4 **)0x0) {
        (**(code **)(puStack_1e8 + -0x7dc4))(ppuStack_2c4);
      }
      if (ppuStack_2c0 != (undefined4 **)0x0) {
        (**(code **)(puStack_1e8 + -0x7dc4))(ppuStack_2c0);
      }
      pcStack_224 = (char *)puVar2;
      if (ppuStack_2c8 != (undefined4 **)0x0) {
        (*p_CSwift_ReleaseAccContext)(uStack_1cc);
      }
    }
    else {
      pcStack_2b0 = pcStack_224;
      puVar2 = (undefined4 *)(**(code **)(iVar1 + 0x14))(ppuVar13);
      ppuStack_2c0 = (undefined4 **)pcVar15;
    }
  }
  if (iStack_17c == *(int *)puStack_2d0) {
    return puVar2;
  }
  pcStack_204 = cswift_dsa_sign;
  iStack_284 = iStack_17c;
  (**(code **)(puStack_1e8 + -0x5328))();
  puStack_2b4 = PTR___stack_chk_guard_006aabf0;
  puStack_290 = &_gp;
  puStack_228 = puStack_2d0;
  iStack_22c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_2a4 = pcStack_2b0;
  ppuVar13 = ppuVar5;
  ppuStack_220 = ppuStack_2c8;
  ppuStack_21c = ppuStack_2c4;
  ppuStack_218 = ppuStack_2c0;
  ppuStack_214 = ppuStack_2bc;
  puStack_210 = puStack_2b8;
  puStack_20c = unaff_s7;
  puStack_208 = unaff_s8;
  puVar3 = (undefined *)(*(code *)PTR_BN_CTX_new_006a8a38)();
  if (puVar3 == (undefined *)0x0) {
    puStack_2cc = (undefined4 *)0x0;
  }
  else {
    iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_27c);
    if (iVar1 == 0) {
      (**(code **)(puStack_290 + -0x689c))(puVar3);
      ppuStack_2c4 = (undefined4 **)(**(code **)(puStack_290 + -0x6898))(puVar3);
      ppuStack_2c0 = (undefined4 **)(**(code **)(puStack_290 + -0x6898))(puVar3);
      ppuStack_2bc = (undefined4 **)(**(code **)(puStack_290 + -0x6898))(puVar3);
      puStack_2b8 = (undefined4 *)(**(code **)(puStack_290 + -0x6898))(puVar3);
      ppuStack_2c8 = (undefined4 **)(**(code **)(puStack_290 + -0x6898))(puVar3);
      if (ppuStack_2c8 == (undefined4 **)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_290 + -0x6eb0);
        ppuVar13 = (undefined4 **)0x66;
        ppuStack_298 = (undefined4 **)0x348;
LAB_005d40a4:
        pcVar16 = "e_cswift.c";
        pcStack_2a4 = &DAT_00000065;
        puStack_2cc = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if (((int)ppuStack_2c4[2] < (int)ppuVar5[3][1]) &&
           (iVar1 = (**(code **)(puStack_290 + -0x6860))(ppuStack_2c4), iVar1 == 0)) {
LAB_005d40cc:
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_290 + -0x6eb0);
          ppuVar13 = (undefined4 **)0x67;
          ppuStack_298 = (undefined4 **)0x351;
          goto LAB_005d40a4;
        }
        pcVar17 = *(code **)(puStack_290 + -0x6860);
        if ((int)ppuStack_2c0[2] < (int)ppuVar5[4][1]) {
          iVar1 = (*pcVar17)(ppuStack_2c0);
          if (iVar1 != 0) {
            pcVar17 = *(code **)(puStack_290 + -0x6860);
            if ((int)ppuStack_2bc[2] < (int)ppuVar5[5][1]) goto LAB_005d411c;
            goto LAB_005d3da4;
          }
          goto LAB_005d40cc;
        }
        if ((int)ppuStack_2bc[2] < (int)ppuVar5[5][1]) {
LAB_005d411c:
          iVar1 = (*pcVar17)(ppuStack_2bc);
          if (iVar1 == 0) goto LAB_005d40cc;
          pcVar17 = *(code **)(puStack_290 + -0x6860);
          if ((int)puStack_2b8[2] < (int)ppuVar5[7][1]) goto LAB_005d4144;
LAB_005d3dbc:
          puVar2 = ppuVar5[3];
          pcVar17 = *(code **)(puStack_290 + -0x6860);
          if ((int)ppuStack_2c8[2] < (int)puVar2[1]) {
LAB_005d4170:
            iVar1 = (*pcVar17)(ppuStack_2c8);
            if (iVar1 == 0) goto LAB_005d40cc;
            puVar2 = ppuVar5[3];
          }
        }
        else {
LAB_005d3da4:
          pcVar17 = *(code **)(puStack_290 + -0x6860);
          if ((int)ppuVar5[7][1] <= (int)puStack_2b8[2]) goto LAB_005d3dbc;
LAB_005d4144:
          iVar1 = (*pcVar17)(puStack_2b8);
          if (iVar1 == 0) goto LAB_005d40cc;
          puVar2 = ppuVar5[3];
          if ((int)ppuStack_2c8[2] < (int)puVar2[1]) {
            pcVar17 = *(code **)(puStack_290 + -0x6860);
            goto LAB_005d4170;
          }
        }
        uStack_268 = 3;
        uStack_264 = (**(code **)(puStack_290 + -0x7be0))(puVar2,*ppuStack_2c4);
        puStack_260 = *ppuStack_2c4;
        uStack_25c = (**(code **)(puStack_290 + -0x7be0))(ppuVar5[4],*ppuStack_2c0);
        puStack_258 = *ppuStack_2c0;
        uStack_254 = (**(code **)(puStack_290 + -0x7be0))(ppuVar5[5],*ppuStack_2bc);
        puStack_250 = *ppuStack_2bc;
        uStack_24c = (**(code **)(puStack_290 + -0x7be0))(ppuVar5[7],*puStack_2b8);
        uStack_248 = *puStack_2b8;
        ppuStack_2c4 = (undefined4 **)(*p_CSwift_AttachKeyParam)(uStack_27c,&uStack_268);
        if (ppuStack_2c4 == (undefined4 **)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_290 + -0x6eb0);
          ppuVar13 = (undefined4 **)&DAT_00000065;
          ppuStack_298 = (undefined4 **)0x368;
          goto LAB_005d40a4;
        }
        if (ppuStack_2c4 == (undefined4 **)0x0) {
          iStack_274 = iStack_284;
          puStack_278 = (undefined4 *)pcStack_2b0;
          iVar4 = (**(code **)(puStack_290 + -0x7bec))(ppuVar5[3]);
          iVar1 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar1 = iVar4 + 0xe;
          }
          puStack_270 = (undefined4 *)(iVar1 >> 3);
          (**(code **)(puStack_290 + -0x53e0))(*ppuStack_2c8,0,puStack_270);
          puStack_26c = *ppuStack_2c8;
          pcVar16 = (char *)0x1;
          ppuVar13 = &puStack_278;
          pcStack_2a4 = (char *)0x3;
          ppuStack_298 = &puStack_270;
          uStack_294 = 1;
          ppuVar5 = (undefined4 **)(*p_CSwift_SimpleRequest)(uStack_27c);
          if (ppuVar5 != (undefined4 **)0x0) {
            ppuStack_2c8 = (undefined4 **)&_ITM_registerTMCloneTable;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x589c))();
            }
            ppuStack_298 = (undefined4 **)0x37f;
            (**(code **)(puStack_290 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
            pcVar17 = *(code **)(puStack_290 + -0x54a0);
            ppuStack_298 = ppuVar5;
            goto LAB_005d3fd8;
          }
          puStack_2cc = (undefined4 *)(**(code **)(puStack_290 + -0x6660))();
          if (puStack_2cc != (undefined4 *)0x0) {
            uVar6 = (**(code **)(puStack_290 + -0x74f0))(*ppuStack_2c8,0x14,0);
            ppuVar13 = (undefined4 **)0x0;
            pcStack_2a4 = &DAT_00000014;
            puVar2 = *ppuStack_2c8;
            *puStack_2cc = uVar6;
            uVar6 = (**(code **)(puStack_290 + -0x74f0))(puVar2 + 5);
            puStack_2cc[1] = uVar6;
          }
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x589c))();
          }
          ppuStack_298 = (undefined4 **)0x36d;
          (**(code **)(puStack_290 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_290 + -0x54a0);
          ppuStack_298 = ppuStack_2c4;
LAB_005d3fd8:
          pcVar16 = &DAT_0066fa28;
          ppuVar13 = apuStack_23c;
          (*pcVar17)(ppuVar13,1,0xd);
          pcStack_2a4 = "CryptoSwift error number is ";
          puStack_2cc = (undefined4 *)0x0;
          (**(code **)(puStack_290 + -0x6c7c))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_27c);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x589c))();
      }
      ppuVar13 = (undefined4 **)&DAT_0000006c;
      pcVar16 = "e_cswift.c";
      ppuStack_298 = (undefined4 **)0x33b;
      pcStack_2a4 = &DAT_00000065;
      puStack_2cc = (undefined4 *)0x0;
      (**(code **)(puStack_290 + -0x6eb0))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_290 + -0x688c))(puVar3);
    (**(code **)(puStack_290 + -0x74a0))(puVar3);
    puStack_2d0 = puVar3;
  }
  if (iStack_22c == *(int *)puStack_2b4) {
    return puStack_2cc;
  }
  pcStack_2ac = cswift_dsa_verify;
  iVar1 = iStack_22c;
  (**(code **)(puStack_290 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_2d4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar4 == 0) {
    puVar2 = (undefined4 *)0xffffffff;
    goto LAB_005d45fc;
  }
  iVar7 = (*p_CSwift_AcquireAccContext)(&uStack_330);
  if (iVar7 == 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar4);
    puVar2 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar4);
    puVar8 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar4);
    puVar9 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar4);
    puVar10 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar4);
    piVar11 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar4);
    if (piVar11 == (int *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar14 = 0x66;
      uVar6 = 0x3b7;
LAB_005d4718:
      puVar2 = (undefined4 *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,uVar14,"e_cswift.c",uVar6);
    }
    else {
      if (((int)puVar2[2] < (int)(*(undefined4 **)((int)pcVar16 + 0xc))[1]) &&
         (iVar7 = (*(code *)PTR_bn_expand2_006a9680)(puVar2), iVar7 == 0)) {
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
      uStack_320 = 3;
      uStack_31c = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0xc),*puVar2);
      uStack_318 = *puVar2;
      uStack_314 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x10),*puVar8);
      uStack_310 = *puVar8;
      uStack_30c = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x14),*puVar9);
      uStack_308 = *puVar9;
      uStack_304 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x18),*puVar10)
      ;
      uStack_300 = *puVar10;
      iVar7 = (*p_CSwift_AttachKeyParam)(uStack_330,&uStack_320);
      if (iVar7 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar14 = 0x65;
        uVar6 = 0x3d7;
        goto LAB_005d4718;
      }
      if (iVar7 == 0) {
        iStack_2e8 = *piVar11;
        puStack_2f4 = (undefined4 *)pcStack_2a4;
        uStack_2ec = 0x28;
        iStack_2f0 = iVar1;
        (*(code *)PTR_memset_006aab00)(iStack_2e8,0,0x28);
        iVar1 = iStack_2e8;
        puVar2 = *ppuVar13;
        iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x14);
        iVar1 = iStack_2e8;
        puVar2 = ppuVar13[1];
        iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x28);
        uStack_328 = 4;
        piStack_324 = &iStack_32c;
        iVar7 = (*p_CSwift_SimpleRequest)(uStack_330,4,&puStack_2f4,2,&uStack_328,1);
        if (iVar7 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          uVar6 = 0x3f2;
          goto LAB_005d4698;
        }
        puVar2 = (undefined4 *)(uint)(iStack_32c != 0);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar6 = 0x3dc;
LAB_005d4698:
        (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",uVar6);
        (*(code *)PTR___sprintf_chk_006aaa40)(auStack_2e4,1,0xd,&DAT_0066fa28,iVar7);
        puVar2 = (undefined4 *)0xffffffff;
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"CryptoSwift error number is ",auStack_2e4);
      }
    }
    (*p_CSwift_ReleaseAccContext)(uStack_330);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    puVar2 = (undefined4 *)0xffffffff;
    (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,0x6c,"e_cswift.c",0x3aa);
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(iVar4);
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar4);
LAB_005d45fc:
  if (iStack_2d4 == *(int *)puVar3) {
    return puVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar1 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar1 != 0) {
    iVar4 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar1,"cswift");
    if ((((iVar4 != 0) &&
         (iVar4 = (*(code *)PTR_ENGINE_set_name_006a99e8)
                            (iVar1,"CryptoSwift hardware engine support"), iVar4 != 0)) &&
        (iVar4 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar1,cswift_rsa), iVar4 != 0)) &&
       (((((iVar4 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar1,cswift_dsa), iVar4 != 0 &&
           (iVar4 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar1,cswift_dh), iVar4 != 0)) &&
          ((iVar4 = (*(code *)PTR_ENGINE_set_RAND_006aa654)(iVar1,cswift_random), iVar4 != 0 &&
           ((iVar4 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar1,cswift_destroy),
            iVar4 != 0 &&
            (iVar4 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar1,cswift_init), iVar4 != 0
            )))))) &&
         (iVar4 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar1,cswift_finish),
         iVar4 != 0)) &&
        ((iVar4 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar1,cswift_ctrl), iVar4 != 0 &&
         (iVar4 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar1,cswift_cmd_defns), iVar4 != 0))
        )))) {
      iVar4 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
      cswift_rsa._4_4_ = *(undefined4 *)(iVar4 + 4);
      cswift_rsa._8_4_ = *(undefined4 *)(iVar4 + 8);
      cswift_rsa._12_4_ = *(undefined4 *)(iVar4 + 0xc);
      cswift_rsa._16_4_ = *(undefined4 *)(iVar4 + 0x10);
      iVar4 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
      cswift_dh._4_4_ = *(undefined4 *)(iVar4 + 4);
      cswift_dh._8_4_ = *(undefined4 *)(iVar4 + 8);
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
      (*(code *)PTR_ENGINE_add_006a99d8)(iVar1);
      (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005d4b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar2 = (undefined4 *)(*(code *)PTR_ERR_clear_error_006a7fe0)();
      return puVar2;
    }
                    /* WARNING: Could not recover jumptable at 0x005d4954. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar2 = (undefined4 *)(*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
    return puVar2;
  }
  return (undefined4 *)0x0;
}

