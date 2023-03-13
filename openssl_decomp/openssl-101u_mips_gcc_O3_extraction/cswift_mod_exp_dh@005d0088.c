
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
  
  puStack_cc = PTR___stack_chk_guard_006a9ae8;
  local_90 = &_gp;
  local_2c = *(undefined4 ***)PTR___stack_chk_guard_006a9ae8;
  local_84 = param_2;
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_7c);
  if (iVar1 == 0) {
    (**(code **)(local_90 + -0x68b8))(param_6);
    unaff_s4 = (undefined4 *)(**(code **)(local_90 + -0x68b4))(param_6);
    unaff_s7 = (undefined4 *)(**(code **)(local_90 + -0x68b4))(param_6);
    unaff_s8 = (undefined4 *)(**(code **)(local_90 + -0x68b4))(param_6);
    unaff_s5 = (undefined4 *)(**(code **)(local_90 + -0x68b4))(param_6);
    if (unaff_s5 == (undefined4 *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(local_90 + -0x58a8))();
      }
      pcVar17 = *(code **)(local_90 + -0x6eac);
      ppuStack_2c0 = (undefined4 **)0x66;
      local_98 = (undefined4 **)0x20a;
LAB_005d042c:
      pcStack_16c = "e_cswift.c";
      pcStack_170 = &DAT_00000069;
      puStack_c8 = (undefined4 *)0x0;
      (*pcVar17)(CSWIFT_lib_error_code);
    }
    else {
      pcVar17 = *(code **)(local_90 + -0x68bc);
      if ((int)unaff_s4[2] < *(int *)(param_5 + 4)) {
        iVar1 = (*pcVar17)(unaff_s4);
        if (iVar1 != 0) {
          if ((int)unaff_s7[2] < (int)param_4[1]) {
            pcVar17 = *(code **)(local_90 + -0x68bc);
            goto LAB_005d047c;
          }
          goto LAB_005d0210;
        }
LAB_005d03cc:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(local_90 + -0x58a8))();
        }
        pcVar17 = *(code **)(local_90 + -0x6eac);
        ppuStack_2c0 = (undefined4 **)0x67;
        local_98 = (undefined4 **)0x20f;
        goto LAB_005d042c;
      }
      if ((int)unaff_s7[2] < (int)param_4[1]) {
LAB_005d047c:
        iVar1 = (*pcVar17)(unaff_s7);
        if (iVar1 == 0) goto LAB_005d03cc;
      }
LAB_005d0210:
      if ((((int)unaff_s8[2] < *(int *)(param_3 + 4)) &&
          (iVar1 = (**(code **)(local_90 + -0x68bc))(unaff_s8), iVar1 == 0)) ||
         (((int)unaff_s5[2] < *(int *)(param_5 + 4) &&
          (iVar1 = (**(code **)(local_90 + -0x68bc))(unaff_s5), iVar1 == 0)))) goto LAB_005d03cc;
      local_68 = 2;
      local_64 = (**(code **)(local_90 + -0x7be0))(param_5,*unaff_s4);
      local_60 = *unaff_s4;
      local_5c = (**(code **)(local_90 + -0x7be0))(param_4,*unaff_s7);
      local_58 = *unaff_s7;
      param_4 = (undefined4 **)(*p_CSwift_AttachKeyParam)(local_7c,&local_68);
      if (param_4 == (undefined4 **)0xffffd8ea) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(local_90 + -0x58a8))();
        }
        pcVar17 = *(code **)(local_90 + -0x6eac);
        ppuStack_2c0 = (undefined4 **)&DAT_00000065;
        local_98 = (undefined4 **)0x21f;
        goto LAB_005d042c;
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
        (**(code **)(local_90 + -0x53ec))(*unaff_s5,0,local_70);
        local_6c = *unaff_s5;
        pcStack_16c = (char *)0x1;
        local_98 = &local_70;
        local_94 = (undefined4 *)0x1;
        ppuVar13 = (undefined4 **)(*p_CSwift_SimpleRequest)(local_7c,2,&local_78);
        if (ppuVar13 != (undefined4 **)0x0) {
          param_4 = (undefined4 **)&_gp_1;
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(local_90 + -0x58a8))();
          }
          local_98 = (undefined4 **)0x234;
          (**(code **)(local_90 + -0x6eac))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(local_90 + -0x54b0);
          local_98 = ppuVar13;
          goto LAB_005d04f0;
        }
        puStack_c8 = (undefined4 *)0x1;
        pcStack_170 = (char *)local_70;
        ppuStack_2c0 = local_84;
        (**(code **)(local_90 + -0x74dc))(*unaff_s5);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(local_90 + -0x58a8))();
        }
        local_98 = (undefined4 **)0x224;
        (**(code **)(local_90 + -0x6eac))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
        pcVar17 = *(code **)(local_90 + -0x54b0);
        local_98 = param_4;
LAB_005d04f0:
        pcStack_16c = &DAT_0066f118;
        ppuStack_2c0 = apuStack_3c;
        (*pcVar17)(ppuStack_2c0,1,0xd);
        pcStack_170 = "CryptoSwift error number is ";
        puStack_c8 = (undefined4 *)0x0;
        (**(code **)(local_90 + -0x6ca4))(2);
      }
    }
    (*p_CSwift_ReleaseAccContext)(local_7c);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (**(code **)(local_90 + -0x58a8))();
    }
    ppuStack_2c0 = (undefined4 **)&DAT_0000006c;
    pcStack_16c = "e_cswift.c";
    local_98 = (undefined4 **)0x1ff;
    pcStack_170 = &DAT_00000069;
    puStack_c8 = (undefined4 *)0x0;
    (**(code **)(local_90 + -0x6eac))(CSWIFT_lib_error_code);
  }
  (**(code **)(local_90 + -0x68b0))(param_6);
  if (local_2c == *(undefined4 ***)puStack_cc) {
    return puStack_c8;
  }
  pcStack_ac = cswift_mod_exp_mont;
  ppuStack_2bc = local_2c;
  (**(code **)(local_90 + -0x5330))();
  puStack_2b8 = local_94;
  ppuStack_178 = local_98;
  puStack_174 = PTR___stack_chk_guard_006a9ae8;
  uStack_d0 = param_6;
  puStack_138 = &_gp;
  ppuStack_d4 = *(undefined4 ***)PTR___stack_chk_guard_006a9ae8;
  ppuStack_c4 = param_4;
  puStack_c0 = unaff_s4;
  puStack_bc = unaff_s5;
  iStack_b8 = param_3;
  puStack_b4 = unaff_s7;
  puStack_b0 = unaff_s8;
  iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
  if ((((iVar1 < 0x801) &&
       (iVar1 = (**(code **)(puStack_138 + -0x7bec))(pcStack_170), iVar1 < 0x801)) &&
      (iVar1 = (**(code **)(puStack_138 + -0x7bec))(pcStack_16c), iVar1 < 0x801)) ||
     (iVar1 = (**(code **)(puStack_138 + -0x72f4))(), iVar1 == 0)) {
    iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_124);
    if (iVar1 == 0) {
      (**(code **)(puStack_138 + -0x68b8))(ppuStack_178);
      puStack_2b8 = (undefined4 *)(**(code **)(puStack_138 + -0x68b4))(ppuStack_178);
      unaff_s7 = (undefined4 *)(**(code **)(puStack_138 + -0x68b4))(ppuStack_178);
      ppuStack_12c = (undefined4 **)(**(code **)(puStack_138 + -0x68b4))(ppuStack_178);
      unaff_s8 = (undefined4 *)(**(code **)(puStack_138 + -0x68b4))(ppuStack_178);
      if (unaff_s8 == (undefined4 *)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x58a8))();
        }
        pcVar17 = *(code **)(puStack_138 + -0x6eac);
        ppuStack_2c4 = (undefined4 **)0x66;
        ppuStack_140 = (undefined4 **)0x20a;
LAB_005d09cc:
        pcVar15 = "e_cswift.c";
        pcStack_224 = &DAT_00000069;
        puVar2 = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if (((((int)puStack_2b8[2] < (int)*(undefined4 **)((int)pcStack_16c + 4)) &&
             (iVar1 = (**(code **)(puStack_138 + -0x68bc))(puStack_2b8), iVar1 == 0)) ||
            ((((int)unaff_s7[2] < (int)ppuStack_2c0[1] &&
              (iVar1 = (**(code **)(puStack_138 + -0x68bc))(unaff_s7), iVar1 == 0)) ||
             (((int)ppuStack_12c[2] < *(int *)((int)pcStack_170 + 4) &&
              (iVar1 = (**(code **)(puStack_138 + -0x68bc))(ppuStack_12c), iVar1 == 0)))))) ||
           (((int)unaff_s8[2] < (int)*(undefined4 **)((int)pcStack_16c + 4) &&
            (iVar1 = (**(code **)(puStack_138 + -0x68bc))(unaff_s8), iVar1 == 0)))) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x58a8))();
          }
          pcVar17 = *(code **)(puStack_138 + -0x6eac);
          ppuStack_2c4 = (undefined4 **)0x67;
          ppuStack_140 = (undefined4 **)0x20f;
          goto LAB_005d09cc;
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
            CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x58a8))();
          }
          pcVar17 = *(code **)(puStack_138 + -0x6eac);
          ppuStack_2c4 = (undefined4 **)&DAT_00000065;
          ppuStack_140 = (undefined4 **)0x21f;
          ppuStack_2c0 = ppuVar13;
          goto LAB_005d09cc;
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
          (**(code **)(puStack_138 + -0x53ec))(*unaff_s8,0,puStack_118);
          uStack_114 = *unaff_s8;
          pcVar15 = (char *)0x1;
          ppuStack_140 = &puStack_118;
          puStack_13c = (undefined4 *)0x1;
          ppuVar13 = (undefined4 **)(*p_CSwift_SimpleRequest)(uStack_124,2,&uStack_120);
          if (ppuVar13 != (undefined4 **)0x0) {
            pcStack_16c = &_gp_1;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x58a8))();
            }
            ppuStack_140 = (undefined4 **)0x234;
            (**(code **)(puStack_138 + -0x6eac))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
            pcVar17 = *(code **)(puStack_138 + -0x54b0);
            ppuStack_140 = ppuVar13;
            goto LAB_005d0a64;
          }
          puVar2 = (undefined4 *)0x1;
          pcStack_224 = (char *)puStack_118;
          ppuStack_2c4 = ppuStack_2bc;
          (**(code **)(puStack_138 + -0x74dc))(*unaff_s8);
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x58a8))();
          }
          ppuStack_140 = (undefined4 **)0x224;
          (**(code **)(puStack_138 + -0x6eac))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_138 + -0x54b0);
          ppuStack_2c0 = ppuVar13;
          ppuStack_140 = ppuVar13;
LAB_005d0a64:
          pcVar15 = &DAT_0066f118;
          ppuStack_2c4 = apuStack_e4;
          (*pcVar17)(ppuStack_2c4,1,0xd);
          pcStack_224 = "CryptoSwift error number is ";
          puVar2 = (undefined4 *)0x0;
          (**(code **)(puStack_138 + -0x6ca4))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_124);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_138 + -0x58a8))();
      }
      ppuStack_2c4 = (undefined4 **)&DAT_0000006c;
      pcVar15 = "e_cswift.c";
      ppuStack_140 = (undefined4 **)0x1ff;
      pcStack_224 = &DAT_00000069;
      puVar2 = (undefined4 *)0x0;
      (**(code **)(puStack_138 + -0x6eac))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_138 + -0x68b0))(ppuStack_178);
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
  (**(code **)(puStack_138 + -0x5330))();
  puStack_2d0 = PTR___stack_chk_guard_006a9ae8;
  puStack_1e8 = &_gp;
  iStack_17c = *(int *)PTR___stack_chk_guard_006a9ae8;
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
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppuVar5 = (undefined4 **)&DAT_00000069;
    pcVar16 = "e_cswift.c";
    ppuStack_1f0 = (undefined4 **)0x2e3;
    pcStack_2b0 = &DAT_0000006b;
    (**(code **)(puStack_1e8 + -0x6eac))(CSWIFT_lib_error_code);
    puVar2 = (undefined4 *)0x0;
    pcStack_224 = &_gp_1;
  }
  else {
    pcVar16 = pcVar15;
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    if ((((iVar1 < 0x401) &&
         (iVar1 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2c4[8]), iVar1 < 0x401)) &&
        ((iVar1 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2c4[9]), iVar1 < 0x401 &&
         ((iVar1 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2c4[10]), iVar1 < 0x401 &&
          (iVar1 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_2c4[0xb]), iVar1 < 0x401)))))) ||
       (iVar1 = (**(code **)(puStack_1e8 + -0x72f4))(), pcVar16 = pcVar15, iVar1 == 0)) {
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
            CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x58a8))();
          }
          ppuVar13 = (undefined4 **)0x66;
          pcVar16 = "e_cswift.c";
          ppuStack_1f0 = (undefined4 **)0x279;
          pcStack_2b0 = &DAT_0000006a;
          ppuStack_2c8 = (undefined4 **)0x1;
          (**(code **)(puStack_1e8 + -0x6eac))(CSWIFT_lib_error_code);
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
            iStack_1b0 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1b4,"e_cswift.c",0x24d);
            if (iStack_1b0 == 0) goto LAB_005d13bc;
            (**(code **)(puStack_1e8 + -0x7be0))(ppuStack_2bc,iStack_1b0);
LAB_005d0e08:
            unaff_s7 = (undefined4 *)0x670000;
            iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(puStack_2b8);
            iVar1 = iVar4 + 7;
            if (iVar4 + 7 < 0) {
              iVar1 = iVar4 + 0xe;
            }
            uStack_1ac = iVar1 >> 3;
            if ((uStack_1ac & 0x1f) == 0) {
              iStack_1a8 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1ac,"e_cswift.c",0x24d);
              if (iStack_1a8 != 0) {
                (**(code **)(puStack_1e8 + -0x7be0))(puStack_2b8,iStack_1a8);
                goto LAB_005d0eb0;
              }
            }
            else {
              iStack_1d4 = 0;
              do {
                uStack_1ac = uStack_1ac + 1;
                iStack_1d4 = iStack_1d4 + 1;
              } while ((uStack_1ac & 0x1f) != 0);
              iStack_1a8 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1ac,"e_cswift.c",0x24d);
              if (iStack_1a8 != 0) {
                (**(code **)(puStack_1e8 + -0x7be0))(puStack_2b8,iStack_1a8 + iStack_1d4);
                (**(code **)(puStack_1e8 + -0x53ec))(iStack_1a8,0,iStack_1d4);
LAB_005d0eb0:
                iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(unaff_s8);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                uStack_1a4 = iVar1 >> 3;
                if ((uStack_1a4 & 0x1f) == 0) {
                  iStack_1a0 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1a4,"e_cswift.c",0x24d);
                  if (iStack_1a0 == 0) goto LAB_005d1450;
                  (**(code **)(puStack_1e8 + -0x7be0))(unaff_s8,iStack_1a0);
                }
                else {
                  iStack_1d4 = 0;
                  do {
                    uStack_1a4 = uStack_1a4 + 1;
                    iStack_1d4 = iStack_1d4 + 1;
                  } while ((uStack_1a4 & 0x1f) != 0);
                  iStack_1a0 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1a4,"e_cswift.c",0x24d);
                  if (iStack_1a0 == 0) {
LAB_005d1450:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x58a8))();
                    }
                    pcVar17 = *(code **)(puStack_1e8 + -0x6eac);
                    ppuStack_1f0 = (undefined4 **)0x292;
                    goto LAB_005d13f8;
                  }
                  (**(code **)(puStack_1e8 + -0x7be0))(unaff_s8,iStack_1a0 + iStack_1d4);
                  (**(code **)(puStack_1e8 + -0x53ec))(iStack_1a0,0,iStack_1d4);
                }
                iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(ppuStack_1dc);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                uStack_19c = iVar1 >> 3;
                if ((uStack_19c & 0x1f) == 0) {
                  iStack_198 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_19c,"e_cswift.c",0x24d);
                  if (iStack_198 == 0) goto LAB_005d14fc;
                  (**(code **)(puStack_1e8 + -0x7be0))(ppuStack_1dc,iStack_198);
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_19c = uStack_19c + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_19c & 0x1f) != 0);
                  iStack_198 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_19c,"e_cswift.c",0x24d);
                  if (iStack_198 == 0) {
LAB_005d14fc:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x58a8))();
                    }
                    pcVar17 = *(code **)(puStack_1e8 + -0x6eac);
                    ppuStack_1f0 = (undefined4 **)0x296;
                    goto LAB_005d13f8;
                  }
                  (**(code **)(puStack_1e8 + -0x7be0))(ppuStack_1dc,iStack_198 + (int)unaff_s8);
                  (**(code **)(puStack_1e8 + -0x53ec))(iStack_198,0,unaff_s8);
                }
                iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(puStack_1d8);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                uStack_194 = iVar1 >> 3;
                if ((uStack_194 & 0x1f) == 0) {
                  iStack_190 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_194,"e_cswift.c",0x24d);
                  if (iStack_190 == 0) goto LAB_005d15a4;
                  (**(code **)(puStack_1e8 + -0x7be0))(puStack_1d8,iStack_190);
LAB_005d1090:
                  if (((int)ppuStack_2c0[2] < *(int *)((int)pcStack_224 + 4)) &&
                     (iVar1 = (**(code **)(puStack_1e8 + -0x68bc))(ppuStack_2c0), iVar1 == 0)) {
                    ppuVar13 = (undefined4 **)0x29e;
                    goto LAB_005d15a8;
                  }
                  if (((int)ppuStack_2c4[2] < puStack_2b8[1] + (int)ppuStack_2bc[1]) &&
                     (iVar1 = (**(code **)(puStack_1e8 + -0x68bc))(ppuStack_2c4), iVar1 == 0)) {
                    ppuVar13 = (undefined4 **)0x29e;
                    goto LAB_005d15a8;
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
                      (**(code **)(puStack_1e8 + -0x53ec))(*ppuStack_2c4,0,puStack_1c0);
                      puStack_1bc = *ppuStack_2c4;
                      pcVar16 = (char *)0x1;
                      ppuStack_1f0 = &puStack_1c0;
                      uStack_1ec = 1;
                      ppuVar5 = (undefined4 **)(*p_CSwift_SimpleRequest)(uStack_1cc,1,&uStack_1c8);
                      if (ppuVar5 == (undefined4 **)0x0) {
                        ppuStack_2c8 = (undefined4 **)0x1;
                        puVar2 = (undefined4 *)0x1;
                        pcStack_2b0 = (char *)puStack_1c0;
                        (**(code **)(puStack_1e8 + -0x74dc))(*ppuStack_2c4);
                        goto LAB_005d1298;
                      }
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2bd);
                      pcVar17 = *(code **)(puStack_1e8 + -0x54b0);
                      ppuStack_1f0 = ppuVar5;
                    }
                    else {
                      ppuStack_1dc = ppuVar5;
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2ad);
                      pcVar17 = *(code **)(puStack_1e8 + -0x54b0);
                      ppuStack_1f0 = ppuStack_1dc;
                    }
                    pcVar16 = &DAT_0066f118;
                    ppuVar13 = apuStack_18c;
                    (*pcVar17)(ppuVar13,1,0xd);
                    pcStack_2b0 = "CryptoSwift error number is ";
                    ppuStack_2c8 = (undefined4 **)0x1;
                    puVar2 = (undefined4 *)0x0;
                    (**(code **)(puStack_1e8 + -0x6ca4))(2);
                    goto LAB_005d1298;
                  }
                  ppuVar13 = (undefined4 **)0x2a8;
                  pcStack_2b0 = &DAT_00000065;
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_194 = uStack_194 + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_194 & 0x1f) != 0);
                  iStack_190 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_194,"e_cswift.c",0x24d);
                  if (iStack_190 != 0) {
                    (**(code **)(puStack_1e8 + -0x7be0))(puStack_1d8,iStack_190 + (int)unaff_s8);
                    (**(code **)(puStack_1e8 + -0x53ec))(iStack_190,0,unaff_s8);
                    goto LAB_005d1090;
                  }
LAB_005d15a4:
                  ppuVar13 = (undefined4 **)0x29a;
LAB_005d15a8:
                  pcStack_2b0 = (char *)0x67;
                }
                ppuStack_2c8 = (undefined4 **)0x1;
                ERR_CSWIFT_error_constprop_3(0x6a);
                puVar2 = (undefined4 *)0x0;
                goto LAB_005d1298;
              }
            }
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x58a8))();
            }
            pcVar17 = *(code **)(puStack_1e8 + -0x6eac);
            ppuStack_1f0 = (undefined4 **)0x28e;
          }
          else {
            iStack_1d4 = 0;
            do {
              uStack_1b4 = uStack_1b4 + 1;
              iStack_1d4 = iStack_1d4 + 1;
            } while ((uStack_1b4 & 0x1f) != 0);
            iStack_1b0 = (**(code **)(puStack_1e8 + -0x7dd8))(uStack_1b4,"e_cswift.c",0x24d);
            if (iStack_1b0 != 0) {
              (**(code **)(puStack_1e8 + -0x7be0))(ppuStack_2bc,iStack_1b0 + iStack_1d4);
              (**(code **)(puStack_1e8 + -0x53ec))(iStack_1b0,0,iStack_1d4);
              goto LAB_005d0e08;
            }
LAB_005d13bc:
            pcVar17 = *(code **)(puStack_1e8 + -0x6eac);
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x58a8))();
              pcVar17 = *(code **)(puStack_1e8 + -0x6eac);
            }
            ppuStack_1f0 = (undefined4 **)0x28a;
          }
LAB_005d13f8:
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
          CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x58a8))();
        }
        ppuVar13 = (undefined4 **)&DAT_0000006c;
        pcVar16 = "e_cswift.c";
        ppuStack_1f0 = (undefined4 **)0x270;
        pcStack_2b0 = &DAT_0000006a;
        ppuStack_2c8 = (undefined4 **)0x0;
        (**(code **)(puStack_1e8 + -0x6eac))(CSWIFT_lib_error_code);
        puVar2 = (undefined4 *)0x0;
        ppuStack_2c0 = (undefined4 **)0x0;
        ppuStack_2c4 = (undefined4 **)0x0;
      }
LAB_005d1298:
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
  (**(code **)(puStack_1e8 + -0x5330))();
  puStack_2b4 = PTR___stack_chk_guard_006a9ae8;
  puStack_290 = &_gp;
  puStack_228 = puStack_2d0;
  iStack_22c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_2a4 = pcStack_2b0;
  ppuVar13 = ppuVar5;
  ppuStack_220 = ppuStack_2c8;
  ppuStack_21c = ppuStack_2c4;
  ppuStack_218 = ppuStack_2c0;
  ppuStack_214 = ppuStack_2bc;
  puStack_210 = puStack_2b8;
  puStack_20c = unaff_s7;
  puStack_208 = unaff_s8;
  puVar3 = (undefined *)(*(code *)PTR_BN_CTX_new_006a794c)();
  if (puVar3 == (undefined *)0x0) {
    puStack_2cc = (undefined4 *)0x0;
  }
  else {
    iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_27c);
    if (iVar1 == 0) {
      (**(code **)(puStack_290 + -0x68b8))(puVar3);
      ppuStack_2c4 = (undefined4 **)(**(code **)(puStack_290 + -0x68b4))(puVar3);
      ppuStack_2c0 = (undefined4 **)(**(code **)(puStack_290 + -0x68b4))(puVar3);
      ppuStack_2bc = (undefined4 **)(**(code **)(puStack_290 + -0x68b4))(puVar3);
      puStack_2b8 = (undefined4 *)(**(code **)(puStack_290 + -0x68b4))(puVar3);
      ppuStack_2c8 = (undefined4 **)(**(code **)(puStack_290 + -0x68b4))(puVar3);
      if (ppuStack_2c8 == (undefined4 **)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x58a8))();
        }
        pcVar17 = *(code **)(puStack_290 + -0x6eac);
        ppuVar13 = (undefined4 **)0x66;
        ppuStack_298 = (undefined4 **)0x339;
LAB_005d1ad4:
        pcVar16 = "e_cswift.c";
        pcStack_2a4 = &DAT_00000065;
        puStack_2cc = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if (((int)ppuStack_2c4[2] < (int)ppuVar5[3][1]) &&
           (iVar1 = (**(code **)(puStack_290 + -0x68bc))(ppuStack_2c4), iVar1 == 0)) {
LAB_005d1afc:
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x58a8))();
          }
          pcVar17 = *(code **)(puStack_290 + -0x6eac);
          ppuVar13 = (undefined4 **)0x67;
          ppuStack_298 = (undefined4 **)0x341;
          goto LAB_005d1ad4;
        }
        pcVar17 = *(code **)(puStack_290 + -0x68bc);
        if ((int)ppuStack_2c0[2] < (int)ppuVar5[4][1]) {
          iVar1 = (*pcVar17)(ppuStack_2c0);
          if (iVar1 != 0) {
            pcVar17 = *(code **)(puStack_290 + -0x68bc);
            if ((int)ppuStack_2bc[2] < (int)ppuVar5[5][1]) goto LAB_005d1b4c;
            goto LAB_005d17d4;
          }
          goto LAB_005d1afc;
        }
        if ((int)ppuStack_2bc[2] < (int)ppuVar5[5][1]) {
LAB_005d1b4c:
          iVar1 = (*pcVar17)(ppuStack_2bc);
          if (iVar1 == 0) goto LAB_005d1afc;
          pcVar17 = *(code **)(puStack_290 + -0x68bc);
          if ((int)puStack_2b8[2] < (int)ppuVar5[7][1]) goto LAB_005d1b74;
LAB_005d17ec:
          puVar2 = ppuVar5[3];
          pcVar17 = *(code **)(puStack_290 + -0x68bc);
          if ((int)ppuStack_2c8[2] < (int)puVar2[1]) {
LAB_005d1ba0:
            iVar1 = (*pcVar17)(ppuStack_2c8);
            if (iVar1 == 0) goto LAB_005d1afc;
            puVar2 = ppuVar5[3];
          }
        }
        else {
LAB_005d17d4:
          pcVar17 = *(code **)(puStack_290 + -0x68bc);
          if ((int)ppuVar5[7][1] <= (int)puStack_2b8[2]) goto LAB_005d17ec;
LAB_005d1b74:
          iVar1 = (*pcVar17)(puStack_2b8);
          if (iVar1 == 0) goto LAB_005d1afc;
          puVar2 = ppuVar5[3];
          if ((int)ppuStack_2c8[2] < (int)puVar2[1]) {
            pcVar17 = *(code **)(puStack_290 + -0x68bc);
            goto LAB_005d1ba0;
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
            CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x58a8))();
          }
          pcVar17 = *(code **)(puStack_290 + -0x6eac);
          ppuVar13 = (undefined4 **)&DAT_00000065;
          ppuStack_298 = (undefined4 **)0x354;
          goto LAB_005d1ad4;
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
          (**(code **)(puStack_290 + -0x53ec))(*ppuStack_2c8,0,puStack_270);
          puStack_26c = *ppuStack_2c8;
          pcVar16 = (char *)0x1;
          ppuVar13 = &puStack_278;
          pcStack_2a4 = (char *)0x3;
          ppuStack_298 = &puStack_270;
          uStack_294 = 1;
          ppuVar5 = (undefined4 **)(*p_CSwift_SimpleRequest)(uStack_27c);
          if (ppuVar5 != (undefined4 **)0x0) {
            ppuStack_2c8 = (undefined4 **)&_gp_1;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x58a8))();
            }
            ppuStack_298 = (undefined4 **)0x36a;
            (**(code **)(puStack_290 + -0x6eac))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
            pcVar17 = *(code **)(puStack_290 + -0x54b0);
            ppuStack_298 = ppuVar5;
            goto LAB_005d1a08;
          }
          puStack_2cc = (undefined4 *)(**(code **)(puStack_290 + -0x6684))();
          if (puStack_2cc != (undefined4 *)0x0) {
            uVar6 = (**(code **)(puStack_290 + -0x74dc))(*ppuStack_2c8,0x14,0);
            ppuVar13 = (undefined4 **)0x0;
            pcStack_2a4 = &DAT_00000014;
            puVar2 = *ppuStack_2c8;
            *puStack_2cc = uVar6;
            uVar6 = (**(code **)(puStack_290 + -0x74dc))(puVar2 + 5);
            puStack_2cc[1] = uVar6;
          }
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x58a8))();
          }
          ppuStack_298 = (undefined4 **)0x359;
          (**(code **)(puStack_290 + -0x6eac))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_290 + -0x54b0);
          ppuStack_298 = ppuStack_2c4;
LAB_005d1a08:
          pcVar16 = &DAT_0066f118;
          ppuVar13 = apuStack_23c;
          (*pcVar17)(ppuVar13,1,0xd);
          pcStack_2a4 = "CryptoSwift error number is ";
          puStack_2cc = (undefined4 *)0x0;
          (**(code **)(puStack_290 + -0x6ca4))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_27c);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_290 + -0x58a8))();
      }
      ppuVar13 = (undefined4 **)&DAT_0000006c;
      pcVar16 = "e_cswift.c";
      ppuStack_298 = (undefined4 **)0x32d;
      pcStack_2a4 = &DAT_00000065;
      puStack_2cc = (undefined4 *)0x0;
      (**(code **)(puStack_290 + -0x6eac))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_290 + -0x68b0))(puVar3);
    (**(code **)(puStack_290 + -0x748c))(puVar3);
    puStack_2d0 = puVar3;
  }
  if (iStack_22c == *(int *)puStack_2b4) {
    return puStack_2cc;
  }
  pcStack_2ac = cswift_dsa_verify;
  iVar1 = iStack_22c;
  (**(code **)(puStack_290 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_2d4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar4 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar4 == 0) {
    puVar2 = (undefined4 *)0xffffffff;
    goto LAB_005d202c;
  }
  iVar7 = (*p_CSwift_AcquireAccContext)(&uStack_330);
  if (iVar7 == 0) {
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar4);
    puVar2 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar4);
    puVar8 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar4);
    puVar9 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar4);
    puVar10 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar4);
    piVar11 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar4);
    if (piVar11 == (int *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar14 = 0x66;
      uVar6 = 0x39f;
LAB_005d2148:
      puVar2 = (undefined4 *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,0x66,uVar14,"e_cswift.c",uVar6);
    }
    else {
      if (((int)puVar2[2] < (int)(*(undefined4 **)((int)pcVar16 + 0xc))[1]) &&
         (iVar7 = (*(code *)PTR_bn_expand2_006a8524)(puVar2), iVar7 == 0)) {
LAB_005d2174:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar14 = 0x67;
        uVar6 = 0x3a7;
        goto LAB_005d2148;
      }
      if ((int)puVar8[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x10))[1]) {
        iVar7 = (*(code *)PTR_bn_expand2_006a8524)(puVar8);
        if (iVar7 != 0) {
          if ((int)puVar9[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x14))[1]) goto LAB_005d21d8;
          goto LAB_005d1e14;
        }
        goto LAB_005d2174;
      }
      if ((int)puVar9[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x14))[1]) {
LAB_005d21d8:
        iVar7 = (*(code *)PTR_bn_expand2_006a8524)(puVar9);
        if (iVar7 == 0) goto LAB_005d2174;
        if ((int)puVar10[2] < (int)(*(undefined4 **)((int)pcVar16 + 0x18))[1]) goto LAB_005d2200;
LAB_005d1e2c:
        iVar7 = piVar11[2];
      }
      else {
LAB_005d1e14:
        if ((int)(*(undefined4 **)((int)pcVar16 + 0x18))[1] <= (int)puVar10[2]) goto LAB_005d1e2c;
LAB_005d2200:
        iVar7 = (*(code *)PTR_bn_expand2_006a8524)(puVar10);
        if (iVar7 == 0) goto LAB_005d2174;
        iVar7 = piVar11[2];
      }
      if ((iVar7 < 0x28) && (iVar7 = (*(code *)PTR_bn_expand2_006a8524)(piVar11,0x28), iVar7 == 0))
      goto LAB_005d2174;
      uStack_320 = 3;
      uStack_31c = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 **)((int)pcVar16 + 0xc),*puVar2);
      uStack_318 = *puVar2;
      uStack_314 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 **)((int)pcVar16 + 0x10),*puVar8);
      uStack_310 = *puVar8;
      uStack_30c = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 **)((int)pcVar16 + 0x14),*puVar9);
      uStack_308 = *puVar9;
      uStack_304 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 **)((int)pcVar16 + 0x18),*puVar10)
      ;
      uStack_300 = *puVar10;
      iVar7 = (*p_CSwift_AttachKeyParam)(uStack_330,&uStack_320);
      if (iVar7 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar14 = 0x65;
        uVar6 = 0x3ba;
        goto LAB_005d2148;
      }
      if (iVar7 == 0) {
        iStack_2e8 = *piVar11;
        puStack_2f4 = (undefined4 *)pcStack_2a4;
        uStack_2ec = 0x28;
        iStack_2f0 = iVar1;
        (*(code *)PTR_memset_006a99f4)(iStack_2e8,0,0x28);
        iVar1 = iStack_2e8;
        puVar2 = *ppuVar13;
        iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a7200)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x14);
        iVar1 = iStack_2e8;
        puVar2 = ppuVar13[1];
        iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a7200)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x28);
        uStack_328 = 4;
        piStack_324 = &iStack_32c;
        iVar7 = (*p_CSwift_SimpleRequest)(uStack_330,4,&puStack_2f4,2,&uStack_328,1);
        if (iVar7 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          uVar6 = 0x3d4;
          goto LAB_005d20c8;
        }
        puVar2 = (undefined4 *)(uint)(iStack_32c != 0);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar6 = 0x3bf;
LAB_005d20c8:
        (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",uVar6);
        (*(code *)PTR___sprintf_chk_006a9930)(auStack_2e4,1,0xd,&DAT_0066f118,iVar7);
        puVar2 = (undefined4 *)0xffffffff;
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"CryptoSwift error number is ",auStack_2e4);
      }
    }
    (*p_CSwift_ReleaseAccContext)(uStack_330);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    puVar2 = (undefined4 *)0xffffffff;
    (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,0x66,0x6c,"e_cswift.c",0x393);
  }
  (*(code *)PTR_BN_CTX_end_006a8530)(iVar4);
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar4);
LAB_005d202c:
  if (iStack_2d4 == *(int *)puVar3) {
    return puVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar1 = (*(code *)PTR_ENGINE_new_006a87cc)();
  if (iVar1 != 0) {
    iVar4 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar1,"cswift");
    if ((((iVar4 != 0) &&
         (iVar4 = (*(code *)PTR_ENGINE_set_name_006a88c8)
                            (iVar1,"CryptoSwift hardware engine support"), iVar4 != 0)) &&
        (iVar4 = (*(code *)PTR_ENGINE_set_RSA_006a9544)(iVar1,cswift_rsa), iVar4 != 0)) &&
       (((((iVar4 = (*(code *)PTR_ENGINE_set_DSA_006a9558)(iVar1,cswift_dsa), iVar4 != 0 &&
           (iVar4 = (*(code *)PTR_ENGINE_set_DH_006a955c)(iVar1,cswift_dh), iVar4 != 0)) &&
          ((iVar4 = (*(code *)PTR_ENGINE_set_RAND_006a9548)(iVar1,cswift_random), iVar4 != 0 &&
           ((iVar4 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)(iVar1,cswift_destroy),
            iVar4 != 0 &&
            (iVar4 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)(iVar1,cswift_init), iVar4 != 0
            )))))) &&
         (iVar4 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)(iVar1,cswift_finish),
         iVar4 != 0)) &&
        ((iVar4 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)(iVar1,cswift_ctrl), iVar4 != 0 &&
         (iVar4 = (*(code *)PTR_ENGINE_set_cmd_defns_006a88dc)(iVar1,cswift_cmd_defns), iVar4 != 0))
        )))) {
      iVar4 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a7aec)();
      cswift_rsa._4_4_ = *(undefined4 *)(iVar4 + 4);
      cswift_rsa._8_4_ = *(undefined4 *)(iVar4 + 8);
      cswift_rsa._12_4_ = *(undefined4 *)(iVar4 + 0xc);
      cswift_rsa._16_4_ = *(undefined4 *)(iVar4 + 0x10);
      iVar4 = (*(code *)PTR_DH_OpenSSL_006a8788)();
      cswift_dh._4_4_ = *(undefined4 *)(iVar4 + 4);
      cswift_dh._8_4_ = *(undefined4 *)(iVar4 + 8);
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      if (CSWIFT_error_init != 0) {
        CSWIFT_error_init = 0;
        (*(code *)PTR_ERR_load_strings_006a8444)(CSWIFT_lib_error_code,CSWIFT_str_functs);
        (*(code *)PTR_ERR_load_strings_006a8444)(CSWIFT_lib_error_code,CSWIFT_str_reasons);
        CSWIFT_lib_name._0_4_ = CSWIFT_lib_error_code << 0x18;
        (*(code *)PTR_ERR_load_strings_006a8444)(0,CSWIFT_lib_name);
      }
      (*(code *)PTR_ENGINE_add_006a88b8)(iVar1);
      (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005d25b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar2 = (undefined4 *)(*(code *)PTR_ERR_clear_error_006a6ee0)();
      return puVar2;
    }
                    /* WARNING: Could not recover jumptable at 0x005d2384. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar2 = (undefined4 *)(*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
    return puVar2;
  }
  return (undefined4 *)0x0;
}

