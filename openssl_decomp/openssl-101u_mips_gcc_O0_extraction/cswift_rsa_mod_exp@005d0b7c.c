
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 *
cswift_rsa_mod_exp(undefined4 **param_1,undefined4 *param_2,undefined4 **param_3,undefined4 *param_4
                  )

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
  undefined4 **unaff_s3;
  undefined4 *unaff_s4;
  undefined4 *unaff_s5;
  undefined4 *unaff_s6;
  char *unaff_s7;
  code *pcVar16;
  undefined4 *unaff_s8;
  undefined4 uStack_1e0;
  int iStack_1dc;
  undefined4 uStack_1d8;
  int *piStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 *puStack_1a4;
  int iStack_1a0;
  undefined4 uStack_19c;
  int iStack_198;
  undefined auStack_194 [16];
  int iStack_184;
  undefined *puStack_180;
  undefined4 *puStack_17c;
  undefined4 **ppuStack_178;
  undefined4 **ppuStack_174;
  undefined4 *puStack_170;
  undefined4 *puStack_16c;
  undefined4 *puStack_168;
  undefined *puStack_164;
  char *pcStack_160;
  code *pcStack_15c;
  char *pcStack_154;
  undefined4 **ppuStack_148;
  undefined4 uStack_144;
  undefined *puStack_140;
  int iStack_134;
  undefined4 uStack_12c;
  undefined4 *puStack_128;
  int iStack_124;
  undefined4 *puStack_120;
  undefined4 *puStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 *puStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 *apuStack_ec [4];
  int iStack_dc;
  undefined *puStack_d8;
  undefined4 *puStack_d4;
  undefined4 **ppuStack_d0;
  undefined4 **ppuStack_cc;
  undefined4 *puStack_c8;
  undefined4 *puStack_c4;
  undefined4 *puStack_c0;
  char *pcStack_bc;
  undefined4 *puStack_b8;
  code *pcStack_b4;
  undefined4 **local_a0;
  undefined4 local_9c;
  undefined *local_98;
  undefined4 **local_8c;
  undefined4 *local_88;
  int local_84;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 *local_70;
  undefined4 *local_6c;
  undefined4 local_68;
  uint local_64;
  int local_60;
  uint local_5c;
  int local_58;
  uint local_54;
  int local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  int local_40;
  undefined4 *apuStack_3c [4];
  int local_2c;
  
  puStack_180 = PTR___stack_chk_guard_006a9ae8;
  local_98 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_178 = param_1;
  if ((((param_3[7] == (undefined4 *)0x0) || (unaff_s3 = param_3, param_3[8] == (undefined4 *)0x0))
      || (param_3[9] == (undefined4 *)0x0)) ||
     ((param_3[10] == (undefined4 *)0x0 || (param_3[0xb] == (undefined4 *)0x0)))) {
    param_3 = unaff_s3;
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppuVar5 = (undefined4 **)&DAT_00000069;
    pcVar15 = "e_cswift.c";
    local_a0 = (undefined4 **)0x2e3;
    pcStack_160 = &DAT_0000006b;
    (**(code **)(local_98 + -0x6eac))(CSWIFT_lib_error_code);
    puVar2 = (undefined4 *)0x0;
    puStack_d4 = (undefined4 *)&_gp_1;
  }
  else {
    pcVar15 = (char *)param_4;
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    if ((((iVar1 < 0x401) && (iVar1 = (**(code **)(local_98 + -0x7bec))(param_3[8]), iVar1 < 0x401))
        && ((iVar1 = (**(code **)(local_98 + -0x7bec))(param_3[9]), iVar1 < 0x401 &&
            ((iVar1 = (**(code **)(local_98 + -0x7bec))(param_3[10]), iVar1 < 0x401 &&
             (iVar1 = (**(code **)(local_98 + -0x7bec))(param_3[0xb]), iVar1 < 0x401)))))) ||
       (iVar1 = (**(code **)(local_98 + -0x72f4))(), pcVar15 = (char *)param_4, iVar1 == 0)) {
      unaff_s5 = param_3[7];
      unaff_s6 = param_3[8];
      unaff_s8 = param_3[9];
      local_8c = (undefined4 **)param_3[10];
      local_60 = 0;
      local_58 = 0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      local_88 = param_3[0xb];
      iVar1 = (*p_CSwift_AcquireAccContext)(&local_7c);
      if (iVar1 == 0) {
        unaff_s4 = (undefined4 *)(**(code **)(local_98 + -0x7c2c))();
        param_3 = (undefined4 **)(**(code **)(local_98 + -0x7c2c))();
        if ((param_3 == (undefined4 **)0x0) || (unaff_s4 == (undefined4 *)0x0)) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(local_98 + -0x58a8))();
          }
          param_1 = (undefined4 **)0x66;
          pcVar15 = "e_cswift.c";
          local_a0 = (undefined4 **)0x279;
          pcStack_160 = &DAT_0000006a;
          ppuStack_178 = (undefined4 **)0x1;
          (**(code **)(local_98 + -0x6eac))(CSWIFT_lib_error_code);
          puVar2 = (undefined4 *)0x0;
        }
        else {
          local_68 = 1;
          iVar4 = (**(code **)(local_98 + -0x7bec))(unaff_s5);
          iVar1 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar1 = iVar4 + 0xe;
          }
          local_64 = iVar1 >> 3;
          if ((local_64 & 0x1f) == 0) {
            local_60 = (**(code **)(local_98 + -0x7dd8))(local_64,"e_cswift.c",0x24d);
            if (local_60 == 0) goto LAB_005d13bc;
            (**(code **)(local_98 + -0x7be0))(unaff_s5,local_60);
LAB_005d0e08:
            unaff_s7 = "encrypt";
            iVar4 = (**(code **)(local_98 + -0x7bec))(unaff_s6);
            iVar1 = iVar4 + 7;
            if (iVar4 + 7 < 0) {
              iVar1 = iVar4 + 0xe;
            }
            local_5c = iVar1 >> 3;
            if ((local_5c & 0x1f) == 0) {
              local_58 = (**(code **)(local_98 + -0x7dd8))(local_5c,"e_cswift.c",0x24d);
              if (local_58 != 0) {
                (**(code **)(local_98 + -0x7be0))(unaff_s6,local_58);
                goto LAB_005d0eb0;
              }
            }
            else {
              local_84 = 0;
              do {
                local_5c = local_5c + 1;
                local_84 = local_84 + 1;
              } while ((local_5c & 0x1f) != 0);
              local_58 = (**(code **)(local_98 + -0x7dd8))(local_5c,"e_cswift.c",0x24d);
              if (local_58 != 0) {
                (**(code **)(local_98 + -0x7be0))(unaff_s6,local_58 + local_84);
                (**(code **)(local_98 + -0x53ec))(local_58,0,local_84);
LAB_005d0eb0:
                iVar4 = (**(code **)(local_98 + -0x7bec))(unaff_s8);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                local_54 = iVar1 >> 3;
                if ((local_54 & 0x1f) == 0) {
                  local_50 = (**(code **)(local_98 + -0x7dd8))(local_54,"e_cswift.c",0x24d);
                  if (local_50 == 0) goto LAB_005d1450;
                  (**(code **)(local_98 + -0x7be0))(unaff_s8,local_50);
                }
                else {
                  local_84 = 0;
                  do {
                    local_54 = local_54 + 1;
                    local_84 = local_84 + 1;
                  } while ((local_54 & 0x1f) != 0);
                  local_50 = (**(code **)(local_98 + -0x7dd8))(local_54,"e_cswift.c",0x24d);
                  if (local_50 == 0) {
LAB_005d1450:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(local_98 + -0x58a8))();
                    }
                    pcVar16 = *(code **)(local_98 + -0x6eac);
                    local_a0 = (undefined4 **)0x292;
                    goto LAB_005d13f8;
                  }
                  (**(code **)(local_98 + -0x7be0))(unaff_s8,local_50 + local_84);
                  (**(code **)(local_98 + -0x53ec))(local_50,0,local_84);
                }
                iVar4 = (**(code **)(local_98 + -0x7bec))(local_8c);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                local_4c = iVar1 >> 3;
                if ((local_4c & 0x1f) == 0) {
                  local_48 = (**(code **)(local_98 + -0x7dd8))(local_4c,"e_cswift.c",0x24d);
                  if (local_48 == 0) goto LAB_005d14fc;
                  (**(code **)(local_98 + -0x7be0))(local_8c,local_48);
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    local_4c = local_4c + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((local_4c & 0x1f) != 0);
                  local_48 = (**(code **)(local_98 + -0x7dd8))(local_4c,"e_cswift.c",0x24d);
                  if (local_48 == 0) {
LAB_005d14fc:
                    if (CSWIFT_lib_error_code == 0) {
                      CSWIFT_lib_error_code = (**(code **)(local_98 + -0x58a8))();
                    }
                    pcVar16 = *(code **)(local_98 + -0x6eac);
                    local_a0 = (undefined4 **)0x296;
                    goto LAB_005d13f8;
                  }
                  (**(code **)(local_98 + -0x7be0))(local_8c,local_48 + (int)unaff_s8);
                  (**(code **)(local_98 + -0x53ec))(local_48,0,unaff_s8);
                }
                iVar4 = (**(code **)(local_98 + -0x7bec))(local_88);
                iVar1 = iVar4 + 7;
                if (iVar4 + 7 < 0) {
                  iVar1 = iVar4 + 0xe;
                }
                local_44 = iVar1 >> 3;
                if ((local_44 & 0x1f) == 0) {
                  local_40 = (**(code **)(local_98 + -0x7dd8))(local_44,"e_cswift.c",0x24d);
                  if (local_40 == 0) goto LAB_005d15a4;
                  (**(code **)(local_98 + -0x7be0))(local_88,local_40);
LAB_005d1090:
                  if (((int)unaff_s4[2] < (int)param_2[1]) &&
                     (iVar1 = (**(code **)(local_98 + -0x68bc))(unaff_s4), iVar1 == 0)) {
                    param_1 = (undefined4 **)0x29e;
                    goto LAB_005d15a8;
                  }
                  if (((int)param_3[2] < (int)(unaff_s6[1] + unaff_s5[1])) &&
                     (iVar1 = (**(code **)(local_98 + -0x68bc))(param_3), iVar1 == 0)) {
                    param_1 = (undefined4 **)0x29e;
                    goto LAB_005d15a8;
                  }
                  ppuVar5 = (undefined4 **)(*p_CSwift_AttachKeyParam)(local_7c,&local_68);
                  if (ppuVar5 != (undefined4 **)0xffffd8ea) {
                    if (ppuVar5 == (undefined4 **)0x0) {
                      local_78 = (**(code **)(local_98 + -0x7be0))(param_2,*unaff_s4);
                      local_74 = *unaff_s4;
                      iVar4 = (**(code **)(local_98 + -0x7bec))(unaff_s5);
                      iVar1 = iVar4 + 7;
                      if (iVar4 + 7 < 0) {
                        iVar1 = iVar4 + 0xe;
                      }
                      local_70 = (undefined4 *)((iVar1 >> 3) << 1);
                      (**(code **)(local_98 + -0x53ec))(*param_3,0,local_70);
                      local_6c = *param_3;
                      pcVar15 = (char *)0x1;
                      local_a0 = &local_70;
                      local_9c = 1;
                      ppuVar5 = (undefined4 **)(*p_CSwift_SimpleRequest)(local_7c,1,&local_78);
                      if (ppuVar5 == (undefined4 **)0x0) {
                        ppuStack_178 = (undefined4 **)0x1;
                        puVar2 = (undefined4 *)0x1;
                        pcStack_160 = (char *)local_70;
                        (**(code **)(local_98 + -0x74dc))(*param_3);
                        goto LAB_005d1298;
                      }
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2bd);
                      pcVar16 = *(code **)(local_98 + -0x54b0);
                      local_a0 = ppuVar5;
                    }
                    else {
                      local_8c = ppuVar5;
                      ERR_CSWIFT_error_constprop_3(0x6a,0x6b,0x2ad);
                      pcVar16 = *(code **)(local_98 + -0x54b0);
                      local_a0 = local_8c;
                    }
                    pcVar15 = &DAT_0066f118;
                    param_1 = apuStack_3c;
                    (*pcVar16)(param_1,1,0xd);
                    pcStack_160 = "CryptoSwift error number is ";
                    ppuStack_178 = (undefined4 **)0x1;
                    puVar2 = (undefined4 *)0x0;
                    (**(code **)(local_98 + -0x6ca4))(2);
                    goto LAB_005d1298;
                  }
                  param_1 = (undefined4 **)0x2a8;
                  pcStack_160 = &DAT_00000065;
                }
                else {
                  unaff_s8 = (undefined4 *)0x0;
                  do {
                    local_44 = local_44 + 1;
                    unaff_s8 = (undefined4 *)((int)unaff_s8 + 1);
                  } while ((local_44 & 0x1f) != 0);
                  local_40 = (**(code **)(local_98 + -0x7dd8))(local_44,"e_cswift.c",0x24d);
                  if (local_40 != 0) {
                    (**(code **)(local_98 + -0x7be0))(local_88,local_40 + (int)unaff_s8);
                    (**(code **)(local_98 + -0x53ec))(local_40,0,unaff_s8);
                    goto LAB_005d1090;
                  }
LAB_005d15a4:
                  param_1 = (undefined4 **)0x29a;
LAB_005d15a8:
                  pcStack_160 = (char *)0x67;
                }
                ppuStack_178 = (undefined4 **)0x1;
                ERR_CSWIFT_error_constprop_3(0x6a);
                puVar2 = (undefined4 *)0x0;
                goto LAB_005d1298;
              }
            }
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(local_98 + -0x58a8))();
            }
            pcVar16 = *(code **)(local_98 + -0x6eac);
            local_a0 = (undefined4 **)0x28e;
          }
          else {
            local_84 = 0;
            do {
              local_64 = local_64 + 1;
              local_84 = local_84 + 1;
            } while ((local_64 & 0x1f) != 0);
            local_60 = (**(code **)(local_98 + -0x7dd8))(local_64,"e_cswift.c",0x24d);
            if (local_60 != 0) {
              (**(code **)(local_98 + -0x7be0))(unaff_s5,local_60 + local_84);
              (**(code **)(local_98 + -0x53ec))(local_60,0,local_84);
              goto LAB_005d0e08;
            }
LAB_005d13bc:
            pcVar16 = *(code **)(local_98 + -0x6eac);
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(local_98 + -0x58a8))();
              pcVar16 = *(code **)(local_98 + -0x6eac);
            }
            local_a0 = (undefined4 **)0x28a;
          }
LAB_005d13f8:
          pcVar15 = "e_cswift.c";
          unaff_s7 = "encrypt";
          param_1 = (undefined4 **)0x67;
          pcStack_160 = &DAT_0000006a;
          ppuStack_178 = (undefined4 **)0x1;
          (*pcVar16)(CSWIFT_lib_error_code);
          puVar2 = (undefined4 *)0x0;
        }
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(local_98 + -0x58a8))();
        }
        param_1 = (undefined4 **)&DAT_0000006c;
        pcVar15 = "e_cswift.c";
        local_a0 = (undefined4 **)0x270;
        pcStack_160 = &DAT_0000006a;
        ppuStack_178 = (undefined4 **)0x0;
        (**(code **)(local_98 + -0x6eac))(CSWIFT_lib_error_code);
        puVar2 = (undefined4 *)0x0;
        unaff_s4 = (undefined4 *)0x0;
        param_3 = (undefined4 **)0x0;
      }
LAB_005d1298:
      ppuVar5 = param_1;
      if (local_60 != 0) {
        (**(code **)(local_98 + -0x7f58))();
        ppuVar5 = param_1;
      }
      if (local_58 != 0) {
        (**(code **)(local_98 + -0x7f58))();
      }
      if (local_50 != 0) {
        (**(code **)(local_98 + -0x7f58))();
      }
      if (local_48 != 0) {
        (**(code **)(local_98 + -0x7f58))();
      }
      if (local_40 != 0) {
        (**(code **)(local_98 + -0x7f58))();
      }
      if (param_3 != (undefined4 **)0x0) {
        (**(code **)(local_98 + -0x7dc4))(param_3);
      }
      if (unaff_s4 != (undefined4 *)0x0) {
        (**(code **)(local_98 + -0x7dc4))(unaff_s4);
      }
      puStack_d4 = puVar2;
      if (ppuStack_178 != (undefined4 **)0x0) {
        (*p_CSwift_ReleaseAccContext)(local_7c);
      }
    }
    else {
      pcStack_160 = (char *)param_2;
      ppuVar5 = param_3;
      puVar2 = (undefined4 *)(**(code **)(iVar1 + 0x14))(param_1);
      puStack_d4 = param_2;
      unaff_s4 = param_4;
    }
  }
  if (local_2c == *(int *)puStack_180) {
    return puVar2;
  }
  pcStack_b4 = cswift_dsa_sign;
  iStack_134 = local_2c;
  (**(code **)(local_98 + -0x5330))();
  puStack_164 = PTR___stack_chk_guard_006a9ae8;
  puStack_140 = &_gp;
  puStack_d8 = puStack_180;
  iStack_dc = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_154 = pcStack_160;
  ppuVar13 = ppuVar5;
  ppuStack_d0 = ppuStack_178;
  ppuStack_cc = param_3;
  puStack_c8 = unaff_s4;
  puStack_c4 = unaff_s5;
  puStack_c0 = unaff_s6;
  pcStack_bc = unaff_s7;
  puStack_b8 = unaff_s8;
  puVar3 = (undefined *)(*(code *)PTR_BN_CTX_new_006a794c)();
  if (puVar3 == (undefined *)0x0) {
    puStack_17c = (undefined4 *)0x0;
  }
  else {
    iVar1 = (*p_CSwift_AcquireAccContext)(&uStack_12c);
    if (iVar1 == 0) {
      (**(code **)(puStack_140 + -0x68b8))(puVar3);
      param_3 = (undefined4 **)(**(code **)(puStack_140 + -0x68b4))(puVar3);
      unaff_s4 = (undefined4 *)(**(code **)(puStack_140 + -0x68b4))(puVar3);
      unaff_s5 = (undefined4 *)(**(code **)(puStack_140 + -0x68b4))(puVar3);
      unaff_s6 = (undefined4 *)(**(code **)(puStack_140 + -0x68b4))(puVar3);
      ppuStack_178 = (undefined4 **)(**(code **)(puStack_140 + -0x68b4))(puVar3);
      if (ppuStack_178 == (undefined4 **)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x58a8))();
        }
        pcVar16 = *(code **)(puStack_140 + -0x6eac);
        ppuVar13 = (undefined4 **)0x66;
        ppuStack_148 = (undefined4 **)0x339;
LAB_005d1ad4:
        pcVar15 = "e_cswift.c";
        pcStack_154 = &DAT_00000065;
        puStack_17c = (undefined4 *)0x0;
        (*pcVar16)(CSWIFT_lib_error_code);
      }
      else {
        if (((int)param_3[2] < (int)ppuVar5[3][1]) &&
           (iVar1 = (**(code **)(puStack_140 + -0x68bc))(param_3), iVar1 == 0)) {
LAB_005d1afc:
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x58a8))();
          }
          pcVar16 = *(code **)(puStack_140 + -0x6eac);
          ppuVar13 = (undefined4 **)0x67;
          ppuStack_148 = (undefined4 **)0x341;
          goto LAB_005d1ad4;
        }
        pcVar16 = *(code **)(puStack_140 + -0x68bc);
        if ((int)unaff_s4[2] < (int)ppuVar5[4][1]) {
          iVar1 = (*pcVar16)(unaff_s4);
          if (iVar1 != 0) {
            pcVar16 = *(code **)(puStack_140 + -0x68bc);
            if ((int)unaff_s5[2] < (int)ppuVar5[5][1]) goto LAB_005d1b4c;
            goto LAB_005d17d4;
          }
          goto LAB_005d1afc;
        }
        if ((int)unaff_s5[2] < (int)ppuVar5[5][1]) {
LAB_005d1b4c:
          iVar1 = (*pcVar16)(unaff_s5);
          if (iVar1 == 0) goto LAB_005d1afc;
          pcVar16 = *(code **)(puStack_140 + -0x68bc);
          if ((int)unaff_s6[2] < (int)ppuVar5[7][1]) goto LAB_005d1b74;
LAB_005d17ec:
          puVar2 = ppuVar5[3];
          pcVar16 = *(code **)(puStack_140 + -0x68bc);
          if ((int)ppuStack_178[2] < (int)puVar2[1]) {
LAB_005d1ba0:
            iVar1 = (*pcVar16)(ppuStack_178);
            if (iVar1 == 0) goto LAB_005d1afc;
            puVar2 = ppuVar5[3];
          }
        }
        else {
LAB_005d17d4:
          pcVar16 = *(code **)(puStack_140 + -0x68bc);
          if ((int)ppuVar5[7][1] <= (int)unaff_s6[2]) goto LAB_005d17ec;
LAB_005d1b74:
          iVar1 = (*pcVar16)(unaff_s6);
          if (iVar1 == 0) goto LAB_005d1afc;
          puVar2 = ppuVar5[3];
          if ((int)ppuStack_178[2] < (int)puVar2[1]) {
            pcVar16 = *(code **)(puStack_140 + -0x68bc);
            goto LAB_005d1ba0;
          }
        }
        uStack_118 = 3;
        uStack_114 = (**(code **)(puStack_140 + -0x7be0))(puVar2,*param_3);
        puStack_110 = *param_3;
        uStack_10c = (**(code **)(puStack_140 + -0x7be0))(ppuVar5[4],*unaff_s4);
        uStack_108 = *unaff_s4;
        uStack_104 = (**(code **)(puStack_140 + -0x7be0))(ppuVar5[5],*unaff_s5);
        uStack_100 = *unaff_s5;
        uStack_fc = (**(code **)(puStack_140 + -0x7be0))(ppuVar5[7],*unaff_s6);
        uStack_f8 = *unaff_s6;
        param_3 = (undefined4 **)(*p_CSwift_AttachKeyParam)(uStack_12c,&uStack_118);
        if (param_3 == (undefined4 **)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x58a8))();
          }
          pcVar16 = *(code **)(puStack_140 + -0x6eac);
          ppuVar13 = (undefined4 **)&DAT_00000065;
          ppuStack_148 = (undefined4 **)0x354;
          goto LAB_005d1ad4;
        }
        if (param_3 == (undefined4 **)0x0) {
          iStack_124 = iStack_134;
          puStack_128 = (undefined4 *)pcStack_160;
          iVar4 = (**(code **)(puStack_140 + -0x7bec))(ppuVar5[3]);
          iVar1 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar1 = iVar4 + 0xe;
          }
          puStack_120 = (undefined4 *)(iVar1 >> 3);
          (**(code **)(puStack_140 + -0x53ec))(*ppuStack_178,0,puStack_120);
          puStack_11c = *ppuStack_178;
          pcVar15 = (char *)0x1;
          ppuVar13 = &puStack_128;
          pcStack_154 = (char *)0x3;
          ppuStack_148 = &puStack_120;
          uStack_144 = 1;
          ppuVar5 = (undefined4 **)(*p_CSwift_SimpleRequest)(uStack_12c);
          if (ppuVar5 != (undefined4 **)0x0) {
            ppuStack_178 = (undefined4 **)&_gp_1;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x58a8))();
            }
            ppuStack_148 = (undefined4 **)0x36a;
            (**(code **)(puStack_140 + -0x6eac))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
            pcVar16 = *(code **)(puStack_140 + -0x54b0);
            ppuStack_148 = ppuVar5;
            goto LAB_005d1a08;
          }
          puStack_17c = (undefined4 *)(**(code **)(puStack_140 + -0x6684))();
          if (puStack_17c != (undefined4 *)0x0) {
            uVar6 = (**(code **)(puStack_140 + -0x74dc))(*ppuStack_178,0x14,0);
            ppuVar13 = (undefined4 **)0x0;
            pcStack_154 = &DAT_00000014;
            puVar2 = *ppuStack_178;
            *puStack_17c = uVar6;
            uVar6 = (**(code **)(puStack_140 + -0x74dc))(puVar2 + 5);
            puStack_17c[1] = uVar6;
          }
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x58a8))();
          }
          ppuStack_148 = (undefined4 **)0x359;
          (**(code **)(puStack_140 + -0x6eac))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
          pcVar16 = *(code **)(puStack_140 + -0x54b0);
          ppuStack_148 = param_3;
LAB_005d1a08:
          pcVar15 = &DAT_0066f118;
          ppuVar13 = apuStack_ec;
          (*pcVar16)(ppuVar13,1,0xd);
          pcStack_154 = "CryptoSwift error number is ";
          puStack_17c = (undefined4 *)0x0;
          (**(code **)(puStack_140 + -0x6ca4))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(uStack_12c);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(puStack_140 + -0x58a8))();
      }
      ppuVar13 = (undefined4 **)&DAT_0000006c;
      pcVar15 = "e_cswift.c";
      ppuStack_148 = (undefined4 **)0x32d;
      pcStack_154 = &DAT_00000065;
      puStack_17c = (undefined4 *)0x0;
      (**(code **)(puStack_140 + -0x6eac))(CSWIFT_lib_error_code);
    }
    (**(code **)(puStack_140 + -0x68b0))(puVar3);
    (**(code **)(puStack_140 + -0x748c))(puVar3);
    puStack_180 = puVar3;
  }
  if (iStack_dc == *(int *)puStack_164) {
    return puStack_17c;
  }
  pcStack_15c = cswift_dsa_verify;
  iVar1 = iStack_dc;
  (**(code **)(puStack_140 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_184 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_174 = param_3;
  puStack_170 = unaff_s4;
  puStack_16c = unaff_s5;
  puStack_168 = unaff_s6;
  iVar4 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar4 == 0) {
    puVar2 = (undefined4 *)0xffffffff;
    goto LAB_005d202c;
  }
  iVar7 = (*p_CSwift_AcquireAccContext)(&uStack_1e0);
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
      if (((int)puVar2[2] < *(int *)(*(int *)((int)pcVar15 + 0xc) + 4)) &&
         (iVar7 = (*(code *)PTR_bn_expand2_006a8524)(puVar2), iVar7 == 0)) {
LAB_005d2174:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar14 = 0x67;
        uVar6 = 0x3a7;
        goto LAB_005d2148;
      }
      if ((int)puVar8[2] < *(int *)(*(int *)((int)pcVar15 + 0x10) + 4)) {
        iVar7 = (*(code *)PTR_bn_expand2_006a8524)(puVar8);
        if (iVar7 != 0) {
          if ((int)puVar9[2] < *(int *)(*(int *)((int)pcVar15 + 0x14) + 4)) goto LAB_005d21d8;
          goto LAB_005d1e14;
        }
        goto LAB_005d2174;
      }
      if ((int)puVar9[2] < *(int *)(*(int *)((int)pcVar15 + 0x14) + 4)) {
LAB_005d21d8:
        iVar7 = (*(code *)PTR_bn_expand2_006a8524)(puVar9);
        if (iVar7 == 0) goto LAB_005d2174;
        if ((int)puVar10[2] < *(int *)(*(int *)((int)pcVar15 + 0x18) + 4)) goto LAB_005d2200;
LAB_005d1e2c:
        iVar7 = piVar11[2];
      }
      else {
LAB_005d1e14:
        if (*(int *)(*(int *)((int)pcVar15 + 0x18) + 4) <= (int)puVar10[2]) goto LAB_005d1e2c;
LAB_005d2200:
        iVar7 = (*(code *)PTR_bn_expand2_006a8524)(puVar10);
        if (iVar7 == 0) goto LAB_005d2174;
        iVar7 = piVar11[2];
      }
      if ((iVar7 < 0x28) && (iVar7 = (*(code *)PTR_bn_expand2_006a8524)(piVar11,0x28), iVar7 == 0))
      goto LAB_005d2174;
      uStack_1d0 = 3;
      uStack_1cc = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)pcVar15 + 0xc),*puVar2);
      uStack_1c8 = *puVar2;
      uStack_1c4 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)pcVar15 + 0x10),*puVar8);
      uStack_1c0 = *puVar8;
      uStack_1bc = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)pcVar15 + 0x14),*puVar9);
      uStack_1b8 = *puVar9;
      uStack_1b4 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)pcVar15 + 0x18),*puVar10);
      uStack_1b0 = *puVar10;
      iVar7 = (*p_CSwift_AttachKeyParam)(uStack_1e0,&uStack_1d0);
      if (iVar7 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar14 = 0x65;
        uVar6 = 0x3ba;
        goto LAB_005d2148;
      }
      if (iVar7 == 0) {
        iStack_198 = *piVar11;
        puStack_1a4 = (undefined4 *)pcStack_154;
        uStack_19c = 0x28;
        iStack_1a0 = iVar1;
        (*(code *)PTR_memset_006a99f4)(iStack_198,0,0x28);
        iVar1 = iStack_198;
        puVar2 = *ppuVar13;
        iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a7200)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x14);
        iVar1 = iStack_198;
        puVar2 = ppuVar13[1];
        iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(puVar2);
        iVar7 = iVar12 + 7;
        if (iVar12 + 7 < 0) {
          iVar7 = iVar12 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a7200)(puVar2,(iVar1 - (iVar7 >> 3)) + 0x28);
        uStack_1d8 = 4;
        piStack_1d4 = &iStack_1dc;
        iVar7 = (*p_CSwift_SimpleRequest)(uStack_1e0,4,&puStack_1a4,2,&uStack_1d8,1);
        if (iVar7 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          uVar6 = 0x3d4;
          goto LAB_005d20c8;
        }
        puVar2 = (undefined4 *)(uint)(iStack_1dc != 0);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar6 = 0x3bf;
LAB_005d20c8:
        (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",uVar6);
        (*(code *)PTR___sprintf_chk_006a9930)(auStack_194,1,0xd,&DAT_0066f118,iVar7);
        puVar2 = (undefined4 *)0xffffffff;
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"CryptoSwift error number is ",auStack_194);
      }
    }
    (*p_CSwift_ReleaseAccContext)(uStack_1e0);
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
  if (iStack_184 == *(int *)puVar3) {
    return puVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar1 = (*(code *)PTR_ENGINE_new_006a87cc)();
  if (iVar1 != 0) {
    iVar4 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar1,"cswift");
    if (((((iVar4 != 0) &&
          (iVar4 = (*(code *)PTR_ENGINE_set_name_006a88c8)
                             (iVar1,"CryptoSwift hardware engine support"), iVar4 != 0)) &&
         (iVar4 = (*(code *)PTR_ENGINE_set_RSA_006a9544)(iVar1,cswift_rsa), iVar4 != 0)) &&
        (((iVar4 = (*(code *)PTR_ENGINE_set_DSA_006a9558)(iVar1,cswift_dsa), iVar4 != 0 &&
          (iVar4 = (*(code *)PTR_ENGINE_set_DH_006a955c)(iVar1,cswift_dh), iVar4 != 0)) &&
         ((iVar4 = (*(code *)PTR_ENGINE_set_RAND_006a9548)(iVar1,cswift_random), iVar4 != 0 &&
          ((iVar4 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)(iVar1,cswift_destroy),
           iVar4 != 0 &&
           (iVar4 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)(iVar1,cswift_init), iVar4 != 0)
           ))))))) &&
       ((iVar4 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)(iVar1,cswift_finish), iVar4 != 0
        && ((iVar4 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)(iVar1,cswift_ctrl), iVar4 != 0
            && (iVar4 = (*(code *)PTR_ENGINE_set_cmd_defns_006a88dc)(iVar1,cswift_cmd_defns),
               iVar4 != 0)))))) {
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

