
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 *
cswift_mod_exp_mont(undefined4 **param_1,undefined4 *param_2,undefined4 **param_3,
                   undefined4 **param_4,undefined4 **param_5,undefined4 *param_6)

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
  undefined4 *unaff_s7;
  code *pcVar17;
  undefined4 *unaff_s8;
  undefined4 uStack_288;
  int iStack_284;
  undefined4 uStack_280;
  int *piStack_27c;
  undefined4 uStack_278;
  undefined4 uStack_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  undefined4 uStack_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 *puStack_24c;
  int iStack_248;
  undefined4 uStack_244;
  int iStack_240;
  undefined auStack_23c [16];
  int iStack_22c;
  undefined *puStack_228;
  undefined4 *puStack_224;
  undefined4 **ppuStack_220;
  undefined4 **ppuStack_21c;
  undefined4 **ppuStack_218;
  undefined4 **ppuStack_214;
  undefined4 *puStack_210;
  undefined *puStack_20c;
  char *pcStack_208;
  code *pcStack_204;
  char *pcStack_1fc;
  undefined4 **ppuStack_1f0;
  undefined4 uStack_1ec;
  undefined *puStack_1e8;
  int iStack_1dc;
  undefined4 uStack_1d4;
  undefined4 *puStack_1d0;
  int iStack_1cc;
  undefined4 *puStack_1c8;
  undefined4 *puStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 *puStack_1b8;
  undefined4 uStack_1b4;
  undefined4 *puStack_1b0;
  undefined4 uStack_1ac;
  undefined4 *puStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 *apuStack_194 [4];
  int iStack_184;
  undefined *puStack_180;
  char *pcStack_17c;
  undefined4 **ppuStack_178;
  undefined4 **ppuStack_174;
  undefined4 **ppuStack_170;
  undefined4 **ppuStack_16c;
  undefined4 *puStack_168;
  undefined4 *puStack_164;
  undefined4 *puStack_160;
  code *pcStack_15c;
  undefined4 **ppuStack_148;
  undefined4 uStack_144;
  undefined *puStack_140;
  undefined4 **ppuStack_134;
  undefined4 *puStack_130;
  int iStack_12c;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 *puStack_11c;
  undefined4 *puStack_118;
  undefined4 *puStack_114;
  undefined4 uStack_110;
  uint uStack_10c;
  int iStack_108;
  uint uStack_104;
  int iStack_100;
  uint uStack_fc;
  int iStack_f8;
  uint uStack_f4;
  int iStack_f0;
  uint uStack_ec;
  int iStack_e8;
  undefined4 *apuStack_e4 [4];
  int iStack_d4;
  undefined4 **ppuStack_d0;
  undefined *puStack_cc;
  undefined4 *puStack_c8;
  undefined4 **ppuStack_c4;
  undefined4 **ppuStack_c0;
  undefined4 **ppuStack_bc;
  undefined4 *puStack_b8;
  undefined4 *puStack_b4;
  undefined4 *puStack_b0;
  code *pcStack_ac;
  undefined4 **local_98;
  undefined4 *local_94;
  undefined *local_90;
  undefined4 **local_84;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 *local_74;
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
  iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)();
  if ((((iVar1 < 0x801) && (iVar1 = (**(code **)(local_90 + -0x7bec))(param_2), iVar1 < 0x801)) &&
      (iVar1 = (**(code **)(local_90 + -0x7bec))(param_4), iVar1 < 0x801)) ||
     (iVar1 = (**(code **)(local_90 + -0x7308))(), iVar1 == 0)) {
    iVar1 = (*p_CSwift_AcquireAccContext)(&local_7c);
    if (iVar1 == 0) {
      (**(code **)(local_90 + -0x689c))(param_5);
      param_6 = (undefined4 *)(**(code **)(local_90 + -0x6898))(param_5);
      unaff_s7 = (undefined4 *)(**(code **)(local_90 + -0x6898))(param_5);
      local_84 = (undefined4 **)(**(code **)(local_90 + -0x6898))(param_5);
      unaff_s8 = (undefined4 *)(**(code **)(local_90 + -0x6898))(param_5);
      if (unaff_s8 == (undefined4 *)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
        }
        pcVar17 = *(code **)(local_90 + -0x6eb0);
        ppuStack_21c = (undefined4 **)0x66;
        local_98 = (undefined4 **)0x20a;
LAB_005d2f9c:
        pcVar15 = "e_cswift.c";
        pcStack_17c = &DAT_00000069;
        puVar2 = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if ((((((int)param_6[2] < (int)param_4[1]) &&
              (iVar1 = (**(code **)(local_90 + -0x6860))(param_6), iVar1 == 0)) ||
             (((int)unaff_s7[2] < (int)param_3[1] &&
              (iVar1 = (**(code **)(local_90 + -0x6860))(unaff_s7), iVar1 == 0)))) ||
            (((int)local_84[2] < (int)param_2[1] &&
             (iVar1 = (**(code **)(local_90 + -0x6860))(local_84), iVar1 == 0)))) ||
           (((int)unaff_s8[2] < (int)param_4[1] &&
            (iVar1 = (**(code **)(local_90 + -0x6860))(unaff_s8), iVar1 == 0)))) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
          }
          pcVar17 = *(code **)(local_90 + -0x6eb0);
          ppuStack_21c = (undefined4 **)0x67;
          local_98 = (undefined4 **)0x210;
          goto LAB_005d2f9c;
        }
        local_68 = 2;
        local_64 = (**(code **)(local_90 + -0x7be0))(param_4,*param_6);
        local_60 = *param_6;
        local_5c = (**(code **)(local_90 + -0x7be0))(param_3,*unaff_s7);
        local_58 = *unaff_s7;
        ppuVar13 = (undefined4 **)(*p_CSwift_AttachKeyParam)(local_7c,&local_68);
        param_3 = local_84;
        if (ppuVar13 == (undefined4 **)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
          }
          pcVar17 = *(code **)(local_90 + -0x6eb0);
          ppuStack_21c = (undefined4 **)&DAT_00000065;
          local_98 = (undefined4 **)0x221;
          param_3 = ppuVar13;
          goto LAB_005d2f9c;
        }
        if (ppuVar13 == (undefined4 **)0x0) {
          local_78 = (**(code **)(local_90 + -0x7be0))(param_2,*local_84);
          local_74 = *param_3;
          iVar4 = (**(code **)(local_90 + -0x7bec))(param_4);
          iVar1 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar1 = iVar4 + 0xe;
          }
          local_70 = (undefined4 *)(iVar1 >> 3);
          (**(code **)(local_90 + -0x53e0))(*unaff_s8,0,local_70);
          local_6c = *unaff_s8;
          pcVar15 = (char *)0x1;
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
            goto LAB_005d3034;
          }
          puVar2 = (undefined4 *)0x1;
          pcStack_17c = (char *)local_70;
          ppuStack_21c = param_1;
          (**(code **)(local_90 + -0x74f0))(*unaff_s8);
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
          }
          local_98 = (undefined4 **)0x226;
          (**(code **)(local_90 + -0x6eb0))(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(local_90 + -0x54a0);
          param_3 = ppuVar13;
          local_98 = ppuVar13;
LAB_005d3034:
          pcVar15 = &DAT_0066fa28;
          ppuStack_21c = apuStack_3c;
          (*pcVar17)(ppuStack_21c,1,0xd);
          pcStack_17c = "CryptoSwift error number is ";
          puVar2 = (undefined4 *)0x0;
          (**(code **)(local_90 + -0x6c7c))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(local_7c);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
      }
      ppuStack_21c = (undefined4 **)&DAT_0000006c;
      pcVar15 = "e_cswift.c";
      local_98 = (undefined4 **)0x1fe;
      pcStack_17c = &DAT_00000069;
      puVar2 = (undefined4 *)0x0;
      (**(code **)(local_90 + -0x6eb0))(CSWIFT_lib_error_code);
    }
    (**(code **)(local_90 + -0x688c))(param_5);
    puStack_c8 = puVar2;
  }
  else {
    local_94 = param_6;
    local_98 = param_5;
    pcStack_17c = (char *)param_2;
    ppuStack_21c = param_3;
    pcVar15 = (char *)param_4;
    puVar2 = (undefined4 *)(**(code **)(iVar1 + 0x18))(param_1);
    puStack_c8 = param_2;
  }
  if (local_2c == *(undefined4 ***)puStack_cc) {
    return puVar2;
  }
  pcStack_ac = cswift_rsa_mod_exp;
  ppuVar13 = local_2c;
  (**(code **)(local_90 + -0x5328))();
  puStack_228 = PTR___stack_chk_guard_006aabf0;
  ppuStack_d0 = param_5;
  puStack_140 = &_gp;
  iStack_d4 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuStack_220 = ppuVar13;
  ppuStack_c4 = param_4;
  ppuStack_c0 = param_3;
  ppuStack_bc = param_1;
  puStack_b8 = param_6;
  puStack_b4 = unaff_s7;
  puStack_b0 = unaff_s8;
  if ((((ppuStack_21c[7] == (undefined4 *)0x0) ||
       (param_4 = ppuStack_21c, ppuStack_21c[8] == (undefined4 *)0x0)) ||
      (ppuStack_21c[9] == (undefined4 *)0x0)) ||
     ((ppuStack_21c[10] == (undefined4 *)0x0 || (ppuStack_21c[0xb] == (undefined4 *)0x0)))) {
    ppuStack_21c = param_4;
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppuVar5 = (undefined4 **)&DAT_00000069;
    pcVar16 = "e_cswift.c";
    ppuStack_148 = (undefined4 **)0x2ed;
    pcStack_208 = &DAT_0000006b;
    (**(code **)(puStack_140 + -0x6eb0))(CSWIFT_lib_error_code);
    puVar2 = (undefined4 *)0x0;
    pcStack_17c = &_ITM_registerTMCloneTable;
  }
  else {
    pcVar16 = pcVar15;
    iVar1 = (*(code *)PTR_BN_num_bits_006a82f4)();
    if ((((iVar1 < 0x401) &&
         (iVar1 = (**(code **)(puStack_140 + -0x7bec))(ppuStack_21c[8]), iVar1 < 0x401)) &&
        ((iVar1 = (**(code **)(puStack_140 + -0x7bec))(ppuStack_21c[9]), iVar1 < 0x401 &&
         ((iVar1 = (**(code **)(puStack_140 + -0x7bec))(ppuStack_21c[10]), iVar1 < 0x401 &&
          (iVar1 = (**(code **)(puStack_140 + -0x7bec))(ppuStack_21c[0xb]), iVar1 < 0x401)))))) ||
       (iVar1 = (**(code **)(puStack_140 + -0x7308))(), pcVar16 = pcVar15, iVar1 == 0)) {
      param_1 = (undefined4 **)ppuStack_21c[7];
      param_6 = ppuStack_21c[8];
      unaff_s8 = ppuStack_21c[9];
      ppuStack_134 = (undefined4 **)ppuStack_21c[10];
      iStack_108 = 0;
      iStack_100 = 0;
      iStack_f8 = 0;
      iStack_f0 = 0;
      iStack_e8 = 0;
      puStack_130 = ppuStack_21c[0xb];
      iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_124);
      if (iVar1 == 0) {
        param_3 = (undefined4 **)(**(code **)(puStack_140 + -0x7c2c))();
        ppuStack_21c = (undefined4 **)(**(code **)(puStack_140 + -0x7c2c))();
        if ((ppuStack_21c == (undefined4 **)0x0) || (param_3 == (undefined4 **)0x0)) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x589c))();
          }
          ppuVar13 = (undefined4 **)0x66;
          pcVar16 = "e_cswift.c";
          ppuStack_148 = (undefined4 **)0x280;
          pcStack_208 = &DAT_0000006a;
          ppuStack_220 = (undefined4 **)0x1;
          (**(code **)(puStack_140 + -0x6eb0))(CSWIFT_lib_error_code);
          puVar2 = (undefined4 *)0x0;
        }
        else {
          uStack_110 = 1;
          iVar4 = (**(code **)(puStack_140 + -0x7bec))(param_1);
          iVar1 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar1 = iVar4 + 0xe;
          }
          uStack_10c = iVar1 >> 3;
          if ((uStack_10c & 0x1f) == 0) {
            iStack_108 = (**(code **)(puStack_140 + -0x7dd8))(uStack_10c,"e_cswift.c",0x252);
            if (iStack_108 == 0) goto LAB_005d398c;
            (**(code **)(puStack_140 + -0x7be0))(param_1,iStack_108);
LAB_005d33d8:
            unaff_s7 = (undefined4 *)0x670000;
            iVar4 = (**(code **)(puStack_140 + -0x7bec))(param_6);
            iVar1 = iVar4 + 7;
            if (iVar4 + 7 < 0) {
              iVar1 = iVar4 + 0xe;
            }
            uStack_104 = iVar1 >> 3;
            if ((uStack_104 & 0x1f) == 0) {
              iStack_100 = (**(code **)(puStack_140 + -0x7dd8))(uStack_104,"e_cswift.c",0x252);
              if (iStack_100 != 0) {
                (**(code **)(puStack_140 + -0x7be0))(param_6,iStack_100);
                goto LAB_005d3480;
              }
            }
            else {
              iStack_12c = 0;
              do {
                uStack_104 = uStack_104 + 1;
                iStack_12c = iStack_12c + 1;
              } while ((uStack_104 & 0x1f) != 0);
              iStack_100 = (**(code **)(puStack_140 + -0x7dd8))(uStack_104,"e_cswift.c",0x252);
              if (iStack_100 != 0) {
                (**(code **)(puStack_140 + -0x7be0))(param_6,iStack_100 + iStack_12c);
                (**(code **)(puStack_140 + -0x53e0))(iStack_100,0,iStack_12c);
LAB_005d3480:
                iVar4 = (**(code **)(puStack_140 + -0x7bec))(unaff_s8);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                uStack_fc = iVar1 >> 3;
                if ((uStack_fc & 0x1f) == 0) {
                  iStack_f8 = (**(code **)(puStack_140 + -0x7dd8))(uStack_fc,"e_cswift.c",0x252);
                  if (iStack_f8 == 0) goto LAB_005d3a20;
                  (**(code **)(puStack_140 + -0x7be0))(unaff_s8,iStack_f8);
                }
                else {
                  iStack_12c = 0;
                  do {
                    uStack_fc = uStack_fc + 1;
                    iStack_12c = iStack_12c + 1;
                  } while ((uStack_fc & 0x1f) != 0);
                  iStack_f8 = (**(code **)(puStack_140 + -0x7dd8))(uStack_fc,"e_cswift.c",0x252);
                  if (iStack_f8 == 0) {
LAB_005d3a20:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x589c))();
                    }
                    pcVar17 = *(code **)(puStack_140 + -0x6eb0);
                    ppuStack_148 = (undefined4 **)0x297;
                    goto LAB_005d39c8;
                  }
                  (**(code **)(puStack_140 + -0x7be0))(unaff_s8,iStack_f8 + iStack_12c);
                  (**(code **)(puStack_140 + -0x53e0))(iStack_f8,0,iStack_12c);
                }
                iVar4 = (**(code **)(puStack_140 + -0x7bec))(ppuStack_134);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                uStack_f4 = iVar1 >> 3;
                if ((uStack_f4 & 0x1f) == 0) {
                  iStack_f0 = (**(code **)(puStack_140 + -0x7dd8))(uStack_f4,"e_cswift.c",0x252);
                  if (iStack_f0 == 0) goto LAB_005d3acc;
                  (**(code **)(puStack_140 + -0x7be0))(ppuStack_134,iStack_f0);
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_f4 = uStack_f4 + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_f4 & 0x1f) != 0);
                  iStack_f0 = (**(code **)(puStack_140 + -0x7dd8))(uStack_f4,"e_cswift.c",0x252);
                  if (iStack_f0 == 0) {
LAB_005d3acc:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x589c))();
                    }
                    pcVar17 = *(code **)(puStack_140 + -0x6eb0);
                    ppuStack_148 = (undefined4 **)0x29c;
                    goto LAB_005d39c8;
                  }
                  (**(code **)(puStack_140 + -0x7be0))(ppuStack_134,iStack_f0 + (int)unaff_s8);
                  (**(code **)(puStack_140 + -0x53e0))(iStack_f0,0,unaff_s8);
                }
                iVar4 = (**(code **)(puStack_140 + -0x7bec))(puStack_130);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                uStack_ec = iVar1 >> 3;
                if ((uStack_ec & 0x1f) == 0) {
                  iStack_e8 = (**(code **)(puStack_140 + -0x7dd8))(uStack_ec,"e_cswift.c",0x252);
                  if (iStack_e8 == 0) goto LAB_005d3b74;
                  (**(code **)(puStack_140 + -0x7be0))(puStack_130,iStack_e8);
LAB_005d3660:
                  if (((int)param_3[2] < *(int *)((int)pcStack_17c + 4)) &&
                     (iVar1 = (**(code **)(puStack_140 + -0x6860))(param_3), iVar1 == 0)) {
                    ppuVar13 = (undefined4 **)0x2a7;
                    goto LAB_005d3b78;
                  }
                  if (((int)ppuStack_21c[2] < param_6[1] + (int)param_1[1]) &&
                     (iVar1 = (**(code **)(puStack_140 + -0x6860))(ppuStack_21c), iVar1 == 0)) {
                    ppuVar13 = (undefined4 **)0x2a7;
                    goto LAB_005d3b78;
                  }
                  ppuVar5 = (undefined4 **)(*p_CSwift_AttachKeyParam)(uStack_124,&uStack_110);
                  if (ppuVar5 != (undefined4 **)0xffffd8ea) {
                    if (ppuVar5 == (undefined4 **)0x0) {
                      uStack_120 = (**(code **)(puStack_140 + -0x7be0))(pcStack_17c,*param_3);
                      puStack_11c = *param_3;
                      iVar4 = (**(code **)(puStack_140 + -0x7bec))(param_1);
                      iVar1 = iVar4 + 7;
                      if (iVar4 + 7 < 0) {
                        iVar1 = iVar4 + 0xe;
                      }
                      puStack_118 = (undefined4 *)((iVar1 >> 3) << 1);
                      (**(code **)(puStack_140 + -0x53e0))(*ppuStack_21c,0,puStack_118);
                      puStack_114 = *ppuStack_21c;
                      pcVar16 = (char *)0x1;
                      ppuStack_148 = &puStack_118;
                      uStack_144 = 1;
                      ppuVar5 = (undefined4 **)(*p_CSwift_SimpleRequest)(uStack_124,1,&uStack_120);
                      if (ppuVar5 == (undefined4 **)0x0) {
                        ppuStack_220 = (undefined4 **)0x1;
                        puVar2 = (undefined4 *)0x1;
                        pcStack_208 = (char *)puStack_118;
                        (**(code **)(puStack_140 + -0x74f0))(*ppuStack_21c);
                        goto LAB_005d3868;
                      }
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2c8);
                      pcVar17 = *(code **)(puStack_140 + -0x54a0);
                      ppuStack_148 = ppuVar5;
                    }
                    else {
                      ppuStack_134 = ppuVar5;
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2b7);
                      pcVar17 = *(code **)(puStack_140 + -0x54a0);
                      ppuStack_148 = ppuStack_134;
                    }
                    pcVar16 = &DAT_0066fa28;
                    ppuVar13 = apuStack_e4;
                    (*pcVar17)(ppuVar13,1,0xd);
                    pcStack_208 = "CryptoSwift error number is ";
                    ppuStack_220 = (undefined4 **)0x1;
                    puVar2 = (undefined4 *)0x0;
                    (**(code **)(puStack_140 + -0x6c7c))(2);
                    goto LAB_005d3868;
                  }
                  ppuVar13 = (undefined4 **)0x2b2;
                  pcStack_208 = &DAT_00000065;
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    uStack_ec = uStack_ec + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((uStack_ec & 0x1f) != 0);
                  iStack_e8 = (**(code **)(puStack_140 + -0x7dd8))(uStack_ec,"e_cswift.c",0x252);
                  if (iStack_e8 != 0) {
                    (**(code **)(puStack_140 + -0x7be0))(puStack_130,iStack_e8 + (int)unaff_s8);
                    (**(code **)(puStack_140 + -0x53e0))(iStack_e8,0,unaff_s8);
                    goto LAB_005d3660;
                  }
LAB_005d3b74:
                  ppuVar13 = (undefined4 **)0x2a1;
LAB_005d3b78:
                  pcStack_208 = (char *)0x67;
                }
                ppuStack_220 = (undefined4 **)0x1;
                ERR_CSWIFT_error_constprop_3(0x6a);
                puVar2 = (undefined4 *)0x0;
                goto LAB_005d3868;
              }
            }
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x589c))();
            }
            pcVar17 = *(code **)(puStack_140 + -0x6eb0);
            ppuStack_148 = (undefined4 **)0x292;
          }
          else {
            iStack_12c = 0;
            do {
              uStack_10c = uStack_10c + 1;
              iStack_12c = iStack_12c + 1;
            } while ((uStack_10c & 0x1f) != 0);
            iStack_108 = (**(code **)(puStack_140 + -0x7dd8))(uStack_10c,"e_cswift.c",0x252);
            if (iStack_108 != 0) {
              (**(code **)(puStack_140 + -0x7be0))(param_1,iStack_108 + iStack_12c);
              (**(code **)(puStack_140 + -0x53e0))(iStack_108,0,iStack_12c);
              goto LAB_005d33d8;
            }
LAB_005d398c:
            pcVar17 = *(code **)(puStack_140 + -0x6eb0);
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x589c))();
              pcVar17 = *(code **)(puStack_140 + -0x6eb0);
            }
            ppuStack_148 = (undefined4 **)0x28d;
          }
LAB_005d39c8:
          pcVar16 = "e_cswift.c";
          unaff_s7 = (undefined4 *)0x670000;
          ppuVar13 = (undefined4 **)0x67;
          pcStack_208 = &DAT_0000006a;
          ppuStack_220 = (undefined4 **)0x1;
          (*pcVar17)(CSWIFT_lib_error_code);
          puVar2 = (undefined4 *)0x0;
        }
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x589c))();
        }
        ppuVar13 = (undefined4 **)&DAT_0000006c;
        pcVar16 = "e_cswift.c";
        ppuStack_148 = (undefined4 **)0x276;
        pcStack_208 = &DAT_0000006a;
        ppuStack_220 = (undefined4 **)0x0;
        (**(code **)(puStack_140 + -0x6eb0))(CSWIFT_lib_error_code);
        puVar2 = (undefined4 *)0x0;
        param_3 = (undefined4 **)0x0;
        ppuStack_21c = (undefined4 **)0x0;
      }
LAB_005d3868:
      ppuVar5 = ppuVar13;
      if (iStack_108 != 0) {
        (**(code **)(puStack_140 + -0x7f58))();
        ppuVar5 = ppuVar13;
      }
      if (iStack_100 != 0) {
        (**(code **)(puStack_140 + -0x7f58))();
      }
      if (iStack_f8 != 0) {
        (**(code **)(puStack_140 + -0x7f58))();
      }
      if (iStack_f0 != 0) {
        (**(code **)(puStack_140 + -0x7f58))();
      }
      if (iStack_e8 != 0) {
        (**(code **)(puStack_140 + -0x7f58))();
      }
      if (ppuStack_21c != (undefined4 **)0x0) {
        (**(code **)(puStack_140 + -0x7dc4))(ppuStack_21c);
      }
      if (param_3 != (undefined4 **)0x0) {
        (**(code **)(puStack_140 + -0x7dc4))(param_3);
      }
      pcStack_17c = (char *)puVar2;
      if (ppuStack_220 != (undefined4 **)0x0) {
        (*p_CSwift_ReleaseAccContext)(uStack_124);
      }
    }
    else {
      pcStack_208 = pcStack_17c;
      ppuVar5 = ppuStack_21c;
      puVar2 = (undefined4 *)(**(code **)(iVar1 + 0x14))(ppuVar13);
      param_3 = (undefined4 **)pcVar15;
    }
  }
  if (iStack_d4 == *(int *)puStack_228) {
    return puVar2;
  }
  pcStack_15c = cswift_dsa_sign;
  iStack_1dc = iStack_d4;
  (**(code **)(puStack_140 + -0x5328))();
  puStack_20c = PTR___stack_chk_guard_006aabf0;
  puStack_1e8 = &_gp;
  puStack_180 = puStack_228;
  iStack_184 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_1fc = pcStack_208;
  ppuVar13 = ppuVar5;
  ppuStack_178 = ppuStack_220;
  ppuStack_174 = ppuStack_21c;
  ppuStack_170 = param_3;
  ppuStack_16c = param_1;
  puStack_168 = param_6;
  puStack_164 = unaff_s7;
  puStack_160 = unaff_s8;
  puVar3 = (undefined *)(*(code *)PTR_BN_CTX_new_006a8a38)();
  if (puVar3 == (undefined *)0x0) {
    puStack_224 = (undefined4 *)0x0;
  }
  else {
    iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_1d4);
    if (iVar1 == 0) {
      (**(code **)(puStack_1e8 + -0x689c))(puVar3);
      ppuStack_21c = (undefined4 **)(**(code **)(puStack_1e8 + -0x6898))(puVar3);
      param_3 = (undefined4 **)(**(code **)(puStack_1e8 + -0x6898))(puVar3);
      param_1 = (undefined4 **)(**(code **)(puStack_1e8 + -0x6898))(puVar3);
      param_6 = (undefined4 *)(**(code **)(puStack_1e8 + -0x6898))(puVar3);
      ppuStack_220 = (undefined4 **)(**(code **)(puStack_1e8 + -0x6898))(puVar3);
      if (ppuStack_220 == (undefined4 **)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
        }
        pcVar17 = *(code **)(puStack_1e8 + -0x6eb0);
        ppuVar13 = (undefined4 **)0x66;
        ppuStack_1f0 = (undefined4 **)0x348;
LAB_005d40a4:
        pcVar16 = "e_cswift.c";
        pcStack_1fc = &DAT_00000065;
        puStack_224 = (undefined4 *)0x0;
        (*pcVar17)(CSWIFT_lib_error_code);
      }
      else {
        if (((int)ppuStack_21c[2] < (int)ppuVar5[3][1]) &&
           (iVar1 = (**(code **)(puStack_1e8 + -0x6860))(ppuStack_21c), iVar1 == 0)) {
LAB_005d40cc:
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_1e8 + -0x6eb0);
          ppuVar13 = (undefined4 **)0x67;
          ppuStack_1f0 = (undefined4 **)0x351;
          goto LAB_005d40a4;
        }
        pcVar17 = *(code **)(puStack_1e8 + -0x6860);
        if ((int)param_3[2] < (int)ppuVar5[4][1]) {
          iVar1 = (*pcVar17)(param_3);
          if (iVar1 != 0) {
            pcVar17 = *(code **)(puStack_1e8 + -0x6860);
            if ((int)param_1[2] < (int)ppuVar5[5][1]) goto LAB_005d411c;
            goto LAB_005d3da4;
          }
          goto LAB_005d40cc;
        }
        if ((int)param_1[2] < (int)ppuVar5[5][1]) {
LAB_005d411c:
          iVar1 = (*pcVar17)(param_1);
          if (iVar1 == 0) goto LAB_005d40cc;
          pcVar17 = *(code **)(puStack_1e8 + -0x6860);
          if ((int)param_6[2] < (int)ppuVar5[7][1]) goto LAB_005d4144;
LAB_005d3dbc:
          puVar2 = ppuVar5[3];
          pcVar17 = *(code **)(puStack_1e8 + -0x6860);
          if ((int)ppuStack_220[2] < (int)puVar2[1]) {
LAB_005d4170:
            iVar1 = (*pcVar17)(ppuStack_220);
            if (iVar1 == 0) goto LAB_005d40cc;
            puVar2 = ppuVar5[3];
          }
        }
        else {
LAB_005d3da4:
          pcVar17 = *(code **)(puStack_1e8 + -0x6860);
          if ((int)ppuVar5[7][1] <= (int)param_6[2]) goto LAB_005d3dbc;
LAB_005d4144:
          iVar1 = (*pcVar17)(param_6);
          if (iVar1 == 0) goto LAB_005d40cc;
          puVar2 = ppuVar5[3];
          if ((int)ppuStack_220[2] < (int)puVar2[1]) {
            pcVar17 = *(code **)(puStack_1e8 + -0x6860);
            goto LAB_005d4170;
          }
        }
        uStack_1c0 = 3;
        uStack_1bc = (**(code **)(puStack_1e8 + -0x7be0))(puVar2,*ppuStack_21c);
        puStack_1b8 = *ppuStack_21c;
        uStack_1b4 = (**(code **)(puStack_1e8 + -0x7be0))(ppuVar5[4],*param_3);
        puStack_1b0 = *param_3;
        uStack_1ac = (**(code **)(puStack_1e8 + -0x7be0))(ppuVar5[5],*param_1);
        puStack_1a8 = *param_1;
        uStack_1a4 = (**(code **)(puStack_1e8 + -0x7be0))(ppuVar5[7],*param_6);
        uStack_1a0 = *param_6;
        ppuStack_21c = (undefined4 **)(*p_CSwift_AttachKeyParam)(uStack_1d4,&uStack_1c0);
        if (ppuStack_21c == (undefined4 **)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
          }
          pcVar17 = *(code **)(puStack_1e8 + -0x6eb0);
          ppuVar13 = (undefined4 **)&DAT_00000065;
          ppuStack_1f0 = (undefined4 **)0x368;
          goto LAB_005d40a4;
        }
        if (ppuStack_21c == (undefined4 **)0x0) {
          iStack_1cc = iStack_1dc;
          puStack_1d0 = (undefined4 *)pcStack_208;
          iVar4 = (**(code **)(puStack_1e8 + -0x7bec))(ppuVar5[3]);
          iVar1 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar1 = iVar4 + 0xe;
          }
          puStack_1c8 = (undefined4 *)(iVar1 >> 3);
          (**(code **)(puStack_1e8 + -0x53e0))(*ppuStack_220,0,puStack_1c8);
          puStack_1c4 = *ppuStack_220;
          pcVar16 = (char *)0x1;
          ppuVar13 = &puStack_1d0;
          pcStack_1fc = (char *)0x3;
          ppuStack_1f0 = &puStack_1c8;
          uStack_1ec = 1;
          ppuVar5 = (undefined4 **)(*p_CSwift_SimpleRequest)(uStack_1d4);
          if (ppuVar5 != (undefined4 **)0x0) {
            ppuStack_220 = (undefined4 **)&_ITM_registerTMCloneTable;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
            }
            ppuStack_1f0 = (undefined4 **)0x37f;
            (**(code **)(puStack_1e8 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
            pcVar17 = *(code **)(puStack_1e8 + -0x54a0);
            ppuStack_1f0 = ppuVar5;
            goto LAB_005d3fd8;
          }
          puStack_224 = (undefined4 *)(**(code **)(puStack_1e8 + -0x6660))();
          if (puStack_224 != (undefined4 *)0x0) {
            uVar6 = (**(code **)(puStack_1e8 + -0x74f0))(*ppuStack_220,0x14,0);
            ppuVar13 = (undefined4 **)0x0;
            pcStack_1fc = &DAT_00000014;
            puVar2 = *ppuStack_220;
            *puStack_224 = uVar6;
            uVar6 = (**(code **)(puStack_1e8 + -0x74f0))(puVar2 + 5);
            puStack_224[1] = uVar6;
          }
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
          }
          ppuStack_1f0 = (undefined4 **)0x36d;
          (**(code **)(puStack_1e8 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
          pcVar17 = *(code **)(puStack_1e8 + -0x54a0);
          ppuStack_1f0 = ppuStack_21c;
LAB_005d3fd8:
          pcVar16 = &DAT_0066fa28;
          ppuVar13 = apuStack_194;
          (*pcVar17)(ppuVar13,1,0xd);
          pcStack_1fc = "CryptoSwift error number is ";
          puStack_224 = (undefined4 *)0x0;
          (**(code **)(puStack_1e8 + -0x6c7c))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_1d4);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_1e8 + -0x589c))();
      }
      ppuVar13 = (undefined4 **)&DAT_0000006c;
      pcVar16 = "e_cswift.c";
      ppuStack_1f0 = (undefined4 **)0x33b;
      pcStack_1fc = &DAT_00000065;
      puStack_224 = (undefined4 *)0x0;
      (**(code **)(puStack_1e8 + -0x6eb0))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_1e8 + -0x688c))(puVar3);
    (**(code **)(puStack_1e8 + -0x74a0))(puVar3);
    puStack_228 = puVar3;
  }
  if (iStack_184 == *(int *)puStack_20c) {
    return puStack_224;
  }
  pcStack_204 = cswift_dsa_verify;
  iVar1 = iStack_184;
  (**(code **)(puStack_1e8 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_22c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuStack_218 = param_3;
  ppuStack_214 = param_1;
  puStack_210 = param_6;
  iVar4 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar4 == 0) {
    puVar2 = (undefined4 *)0xffffffff;
    goto LAB_005d45fc;
  }
  iVar7 = (*p_CSwift_AcquireAccContext)(&uStack_288);
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
      uStack_278 = 3;
      uStack_274 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0xc),*puVar2);
      uStack_270 = *puVar2;
      uStack_26c = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x10),*puVar8);
      uStack_268 = *puVar8;
      uStack_264 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x14),*puVar9);
      uStack_260 = *puVar9;
      uStack_25c = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 **)((int)pcVar16 + 0x18),*puVar10)
      ;
      uStack_258 = *puVar10;
      iVar7 = (*p_CSwift_AttachKeyParam)(uStack_288,&uStack_278);
      if (iVar7 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar14 = 0x65;
        uVar6 = 0x3d7;
        goto LAB_005d4718;
      }
      if (iVar7 == 0) {
        iStack_240 = *piVar11;
        puStack_24c = (undefined4 *)pcStack_1fc;
        uStack_244 = 0x28;
        iStack_248 = iVar1;
        (*(code *)PTR_memset_006aab00)(iStack_240,0,0x28);
        iVar1 = iStack_240;
        puVar2 = *ppuVar13;
        iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x14);
        iVar1 = iStack_240;
        puVar2 = ppuVar13[1];
        iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x28);
        uStack_280 = 4;
        piStack_27c = &iStack_284;
        iVar7 = (*p_CSwift_SimpleRequest)(uStack_288,4,&puStack_24c,2,&uStack_280,1);
        if (iVar7 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          uVar6 = 0x3f2;
          goto LAB_005d4698;
        }
        puVar2 = (undefined4 *)(uint)(iStack_284 != 0);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar6 = 0x3dc;
LAB_005d4698:
        (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",uVar6);
        (*(code *)PTR___sprintf_chk_006aaa40)(auStack_23c,1,0xd,&DAT_0066fa28,iVar7);
        puVar2 = (undefined4 *)0xffffffff;
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"CryptoSwift error number is ",auStack_23c);
      }
    }
    (*p_CSwift_ReleaseAccContext)(uStack_288);
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
  if (iStack_22c == *(int *)puVar3) {
    return puVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar1 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar1 != 0) {
    iVar4 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar1,"cswift");
    if (((((iVar4 != 0) &&
          (iVar4 = (*(code *)PTR_ENGINE_set_name_006a99e8)
                             (iVar1,"CryptoSwift hardware engine support"), iVar4 != 0)) &&
         (iVar4 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar1,cswift_rsa), iVar4 != 0)) &&
        (((iVar4 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar1,cswift_dsa), iVar4 != 0 &&
          (iVar4 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar1,cswift_dh), iVar4 != 0)) &&
         ((iVar4 = (*(code *)PTR_ENGINE_set_RAND_006aa654)(iVar1,cswift_random), iVar4 != 0 &&
          ((iVar4 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar1,cswift_destroy),
           iVar4 != 0 &&
           (iVar4 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar1,cswift_init), iVar4 != 0)
           ))))))) &&
       ((iVar4 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar1,cswift_finish), iVar4 != 0
        && ((iVar4 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar1,cswift_ctrl), iVar4 != 0
            && (iVar4 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar1,cswift_cmd_defns),
               iVar4 != 0)))))) {
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

