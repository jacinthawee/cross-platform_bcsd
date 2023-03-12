
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ****** surewarehk_dsa_do_sign(int **param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  char **ppcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  int **ppiVar10;
  undefined4 *puVar11;
  int **ppiVar12;
  int iVar13;
  undefined4 *puVar14;
  int ******ppppppiVar15;
  uint uVar16;
  int *piVar17;
  char *pcVar18;
  undefined4 *puVar19;
  undefined1 *puVar20;
  uint uVar21;
  int unaff_s5;
  uint uVar22;
  uint uVar23;
  int unaff_s6;
  code *pcVar24;
  char cStack_311;
  uint uStack_310;
  undefined4 uStack_30c;
  undefined4 uStack_308;
  undefined4 uStack_304;
  undefined4 uStack_300;
  undefined2 uStack_2fc;
  char cStack_2fa;
  undefined auStack_2f9 [45];
  undefined4 uStack_2cc;
  undefined4 uStack_2c8;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined4 uStack_2bc;
  char cStack_2b8;
  undefined auStack_2b7 [43];
  int iStack_28c;
  int ******ppppppiStack_284;
  int *piStack_280;
  undefined *puStack_27c;
  int *****pppppiStack_278;
  int ******ppppppiStack_274;
  uint uStack_270;
  char *pcStack_26c;
  int ****ppppiStack_268;
  code *pcStack_264;
  int ******ppppppiStack_250;
  int iStack_24c;
  int *****pppppiStack_248;
  undefined *puStack_240;
  int ******ppppppiStack_238;
  int iStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  uint uStack_1f4;
  int ******ppppppiStack_1f0;
  undefined4 *puStack_1ec;
  int ******ppppppiStack_1e8;
  undefined *puStack_1e4;
  int ******ppppppiStack_1e0;
  int ******ppppppiStack_1dc;
  char *pcStack_1d8;
  code *pcStack_1d4;
  int *****pppppiStack_1c0;
  int iStack_1bc;
  int *****pppppiStack_1b8;
  int *****pppppiStack_1b4;
  undefined *puStack_1b0;
  int ******ppppppiStack_1a8;
  int *****pppppiStack_1a4;
  int **ppiStack_1a0;
  undefined4 *puStack_19c;
  int *****pppppiStack_198;
  int iStack_194;
  int *piStack_190;
  int *****pppppiStack_184;
  undefined4 uStack_180;
  undefined4 *puStack_17c;
  undefined2 uStack_178;
  int *****apppppiStack_176 [12];
  uint uStack_144;
  int ******ppppppiStack_140;
  undefined *puStack_13c;
  undefined4 *puStack_138;
  int **ppiStack_134;
  int iStack_130;
  undefined4 uStack_12c;
  int iStack_128;
  int **ppiStack_108;
  undefined4 *puStack_104;
  undefined4 *puStack_100;
  int *****pppppiStack_fc;
  int ******ppppppiStack_f0;
  int *piStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  int iStack_ac;
  int **ppiStack_a4;
  undefined *puStack_a0;
  undefined4 *puStack_9c;
  int **ppiStack_98;
  int iStack_94;
  int iStack_90;
  code *pcStack_8c;
  undefined4 *local_78;
  int local_74;
  undefined *local_70;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  undefined2 local_54;
  undefined local_52;
  undefined auStack_51 [45];
  int local_24;
  
  puStack_a0 = PTR___stack_chk_guard_006aabf0;
  puStack_9c = (undefined4 *)&_ITM_registerTMCloneTable;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_70 = &_gp;
  ppiStack_108 = (int **)&DAT_0000002d;
  local_64 = DAT_00674d10;
  local_60 = DAT_00674d14;
  local_5c = DAT_00674d18;
  local_58 = DAT_00674d1c;
  local_54 = DAT_00674d20;
  local_52 = DAT_00674d22;
  pcVar7 = DAT_00674d1c;
  (*(code *)PTR_memset_006aab00)(auStack_51,0);
  if (p_surewarehk_Dsa_Sign == (code *)0x0) {
    ppiStack_a4 = (int **)&_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(local_70 + -0x589c))();
    }
    ppiStack_108 = (int **)0x75;
    pcVar7 = "e_sureware.c";
    local_78 = (undefined4 *)0x3d0;
    uStack_12c = 0x65;
    (**(code **)(local_70 + -0x6eb0))(SUREWARE_lib_error_code,0x65,0x75,"e_sureware.c");
  }
  else {
    unaff_s5 = (**(code **)(local_70 + -0x585c))(param_3,dsaHndidx);
    if (unaff_s5 == 0) {
      ppiStack_a4 = (int **)&_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(local_70 + -0x589c))();
      }
      ppiStack_108 = (int **)&DAT_00000069;
      pcVar7 = "e_sureware.c";
      local_78 = (undefined4 *)0x3d6;
      uStack_12c = 0x65;
      (**(code **)(local_70 + -0x6eb0))(SUREWARE_lib_error_code,0x65,0x69,"e_sureware.c");
    }
    else {
      ppiStack_a4 = (int **)(**(code **)(local_70 + -0x6660))();
      if (ppiStack_a4 == (int **)0x0) {
        ppiStack_a4 = (int **)&_ITM_registerTMCloneTable;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (**(code **)(local_70 + -0x589c))();
        }
        ppiStack_108 = (int **)&DAT_00000041;
        pcVar7 = "e_sureware.c";
        local_78 = (undefined4 *)0x3dd;
        uStack_12c = 0x65;
        (**(code **)(local_70 + -0x6eb0))(SUREWARE_lib_error_code,0x65,0x41,"e_sureware.c");
      }
      else {
        piVar4 = (int *)(**(code **)(local_70 + -0x7c2c))();
        pcVar24 = *(code **)(local_70 + -0x7c2c);
        *ppiStack_a4 = piVar4;
        piVar4 = (int *)(*pcVar24)();
        pcVar24 = *(code **)(local_70 + -0x6860);
        ppiStack_a4[1] = piVar4;
        (*pcVar24)(*ppiStack_a4,5);
        uStack_12c = 5;
        (**(code **)(local_70 + -0x6860))(ppiStack_a4[1]);
        ppcVar5 = (char **)*ppiStack_a4;
        if ((ppcVar5 == (char **)0x0) || (ppcVar5[2] != &DAT_00000005)) {
LAB_005d911c:
          pcVar24 = *(code **)(local_70 + -0x6664);
        }
        else {
          piVar4 = ppiStack_a4[1];
          pcVar24 = *(code **)(local_70 + -0x6664);
          if ((piVar4 != (int *)0x0) &&
             (unaff_s6 = piVar4[2], ppiStack_108 = param_1, unaff_s6 == 5)) {
            pcVar7 = *ppcVar5;
            puStack_9c = &local_64;
            local_78 = (undefined4 *)*piVar4;
            local_74 = unaff_s5;
            ppiStack_108 = (int **)(*p_surewarehk_Dsa_Sign)(puStack_9c,param_2,param_1,pcVar7);
            uStack_12c = 0x65;
            surewarehk_error_handling(puStack_9c);
            ppiVar12 = (int **)*ppiStack_a4;
            ppiVar12[1] = (int *)&DAT_00000005;
            piVar4 = *ppiVar12;
            if (piVar4[4] == 0) {
              if (piVar4[3] == 0) {
                if (piVar4[2] == 0) {
                  if (piVar4[1] == 0) {
                    piVar4 = (int *)(uint)(*piVar4 != 0);
                  }
                  else {
                    piVar4 = (int *)&SUB_00000002;
                  }
                }
                else {
                  piVar4 = (int *)0x3;
                }
              }
              else {
                piVar4 = (int *)&SUB_00000004;
              }
            }
            else {
              piVar4 = (int *)&DAT_00000005;
            }
            ppiVar10 = (int **)ppiStack_a4[1];
            ppiVar12[1] = piVar4;
            ppiVar10[1] = (int *)&DAT_00000005;
            piVar4 = *ppiVar10;
            if (piVar4[4] == 0) {
              if (piVar4[3] == 0) {
                if (piVar4[2] == 0) {
                  if (piVar4[1] == 0) {
                    ppiVar10[1] = (int *)(uint)(*piVar4 != 0);
                  }
                  else {
                    ppiVar10[1] = (int *)&SUB_00000002;
                  }
                }
                else {
                  ppiVar10[1] = (int *)0x3;
                }
              }
              else {
                ppiVar10[1] = (int *)&SUB_00000004;
              }
            }
            else {
              ppiVar10[1] = (int *)&DAT_00000005;
            }
            goto LAB_005d911c;
          }
        }
        (*pcVar24)(ppiStack_a4);
      }
    }
  }
  if (local_24 == *(int *)puStack_a0) {
    return (int ******)0x0;
  }
  pcStack_8c = surewarehk_rsa_sign;
  iVar8 = local_24;
  (**(code **)(local_70 + -0x5328))();
  puStack_138 = local_78;
  puStack_13c = PTR___stack_chk_guard_006aabf0;
  iStack_ac = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_dc = 0;
  uStack_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_cc = 0;
  uStack_c8 = 0;
  uStack_c4 = 0;
  uStack_c0 = 0;
  uStack_bc = 0;
  uStack_b8 = 0;
  uStack_b4 = 0;
  uStack_b0 = 0;
  piStack_ec = s_ENGINE_rsa_sign_00674d50._0_4_;
  uStack_e8 = s_ENGINE_rsa_sign_00674d50._4_4_;
  uStack_e4 = s_ENGINE_rsa_sign_00674d50._8_4_;
  uStack_e0 = s_ENGINE_rsa_sign_00674d50._12_4_;
  ppiStack_134 = ppiStack_108;
  ppiStack_98 = param_1;
  iStack_94 = param_2;
  iStack_90 = unaff_s5;
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    ppppppiStack_140 = (int ******)&_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppppppiStack_1a8 = (int ******)0x75;
    pcVar7 = "e_sureware.c";
    ppiStack_108 = (int **)0x3ad;
    piStack_280 = (int *)&DAT_0000006f;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code);
    ppppppiVar15 = (int ******)0x0;
  }
  else {
    puVar6 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006aa640)(pcVar7,rsaHndidx);
    param_2 = iVar8;
    if (puVar6 == (undefined4 *)0x0) {
      ppppppiStack_140 = (int ******)&_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      ppppppiStack_1a8 = (int ******)&DAT_00000069;
      pcVar7 = "e_sureware.c";
      ppiStack_108 = (int **)0x3b2;
      piStack_280 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code);
      ppppppiVar15 = (int ******)0x0;
    }
    else if (puStack_138 == (undefined4 *)0x1) {
      pcVar7 = (char *)&ppppppiStack_f0;
      puStack_100 = puStack_138;
      ppppppiStack_140 = (int ******)(*p_surewarehk_Rsa_Sign)(&piStack_ec,iVar8,uStack_12c);
      piStack_280 = (int *)&DAT_0000006f;
      ppppppiStack_1a8 = ppppppiStack_140;
      surewarehk_error_handling(&piStack_ec);
      ppppppiVar15 = ppppppiStack_140;
      ppiStack_134 = &piStack_ec;
      puStack_104 = puVar6;
      if (ppppppiStack_140 == (int ******)0x1) {
        ppppppiVar15 = ppppppiStack_f0;
      }
    }
    else {
      ppppppiStack_140 = (int ******)&_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      ppppppiStack_1a8 = (int ******)&DAT_0000006b;
      pcVar7 = "e_sureware.c";
      ppiStack_108 = (int **)0x3be;
      piStack_280 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code);
      ppppppiVar15 = (int ******)0x0;
    }
  }
  if (iStack_ac == *(int *)puStack_13c) {
    return ppppppiVar15;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1e4 = PTR___stack_chk_guard_006aabf0;
  pcStack_26c = "r";
  ppiStack_1a0 = ppiStack_108;
  ppppppiStack_1e8 = &pppppiStack_198;
  puStack_19c = puStack_104;
  ppppppiStack_1e0 = apppppiStack_176;
  puStack_1b0 = &_gp;
  pppppiStack_1a4 = pppppiStack_fc;
  uStack_144 = *(uint *)PTR___stack_chk_guard_006aabf0;
  iStack_130 = param_2;
  iStack_128 = unaff_s6;
  (*(code *)PTR_BN_init_006a96a0)(ppppppiStack_1e8);
  ppppppiStack_274 = (int ******)0x32;
  pppppiStack_184 = (int *****)DAT_00674bfc;
  uStack_180 = DAT_00674c00;
  puStack_17c = DAT_00674c04;
  uStack_178 = DAT_00674c08;
  pcVar18 = (char *)DAT_00674c04;
  (**(code **)(puStack_1b0 + -0x53e0))(ppppppiStack_1e0,0);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_005d98a8:
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_1b0 + -0x589c))();
    }
    ppppppiStack_274 = (int ******)0x75;
    pcVar18 = "e_sureware.c";
    pppppiStack_1c0 = (int *****)0x403;
    piVar4 = (int *)&DAT_0000006b;
    (**(code **)(puStack_1b0 + -0x6eb0))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
LAB_005d96e0:
    piStack_280 = piVar4;
    ppppppiStack_1f0 = (int ******)0x0;
    ppppppiStack_1dc = (int ******)pcVar7;
  }
  else {
    piVar4 = (int *)puStack_100[1];
    (**(code **)(puStack_1b0 + -0x6860))(piStack_280);
    if ((piStack_280 == (int *)0x0) ||
       (piVar4 = (int *)piStack_280[2], ppppppiStack_274 = ppppppiStack_1a8,
       piVar4 != (int *)puStack_100[1])) goto LAB_005d96e0;
    pppppiStack_1c0 = *(int ******)pcVar7;
    pppppiStack_1b4 = (int *****)*piStack_280;
    pcVar18 = (char *)((int)*(int ******)((int)pcVar7 + 4) << 2);
    pppppiStack_1b8 = *ppppppiStack_1a8;
    iStack_1bc = (int)ppppppiStack_1a8[1] << 2;
    ppppppiStack_1a8 = &pppppiStack_184;
    pcVar7 = (char *)(*p_surewarehk_Mod_Exp)(&pppppiStack_184,(int)piVar4 << 2,*puStack_100,pcVar18)
    ;
    piVar4 = (int *)&DAT_0000006b;
    ppppppiStack_274 = (int ******)pcVar7;
    surewarehk_error_handling(ppppppiStack_1a8);
    if ((int ******)pcVar7 == (int ******)0x1) {
      iVar8 = puStack_100[1];
      piStack_280[1] = iVar8;
      if (0 < iVar8) {
        iVar13 = *piStack_280 + iVar8 * 4 + -8;
        do {
          if (*(int *)(iVar13 + 4) != 0) break;
          iVar8 = iVar8 + -1;
          iVar13 = iVar13 + -4;
        } while (iVar8 != 0);
        piStack_280[1] = iVar8;
      }
    }
    else if ((int ******)pcVar7 == (int ******)0x0) goto LAB_005d96e0;
    ppppppiStack_274 = (int ******)0x32;
    pppppiStack_184 = (int *****)DAT_00674bfc;
    uStack_180 = DAT_00674c00;
    puStack_17c = DAT_00674c04;
    uStack_178 = DAT_00674c08;
    pcVar18 = (char *)DAT_00674c04;
    (**(code **)(puStack_1b0 + -0x53e0))(ppppppiStack_1e0,0);
    if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_005d98a8;
    (**(code **)(puStack_1b0 + -0x6860))(ppppppiStack_1e8,puStack_100[1]);
    ppppppiStack_1dc = ppppppiStack_1a8;
    piVar4 = piStack_190;
    if (piStack_190 != (int *)puStack_100[1]) goto LAB_005d96e0;
    pppppiStack_1b8 = (int *****)*ppiStack_1a0;
    iStack_1bc = (int)ppiStack_1a0[1] << 2;
    pppppiStack_1c0 = (int *****)*puStack_19c;
    pcVar18 = (char *)(puStack_19c[1] << 2);
    pppppiStack_1b4 = pppppiStack_198;
    ppppppiStack_1e0 =
         (int ******)
         (*p_surewarehk_Mod_Exp)(ppppppiStack_1a8,(int)piStack_190 << 2,*puStack_100,pcVar18);
    piVar4 = (int *)&DAT_0000006b;
    ppppppiStack_274 = ppppppiStack_1e0;
    surewarehk_error_handling(ppppppiStack_1dc);
    if (ppppppiStack_1e0 == (int ******)0x1) {
      iStack_194 = puStack_100[1];
      if (0 < iStack_194) {
        pppppiStack_198 = pppppiStack_198 + iStack_194 + -2;
        do {
          if (pppppiStack_198[1] != (int ****)0x0) break;
          iStack_194 = iStack_194 + -1;
          pppppiStack_198 = pppppiStack_198 + -1;
        } while (iStack_194 != 0);
      }
    }
    else {
      pcVar7 = (char *)ppppppiStack_1dc;
      if (ppppppiStack_1e0 == (int ******)0x0) goto LAB_005d96e0;
    }
    pppppiStack_1c0 = pppppiStack_1a4;
    ppppppiStack_274 = ppppppiStack_1e8;
    pcVar18 = (char *)puStack_100;
    iVar8 = (**(code **)(puStack_1b0 + -0x6848))
                      (piStack_280,piStack_280,ppppppiStack_1e8,puStack_100);
    ppppppiStack_1f0 = (int ******)(uint)(iVar8 != 0);
  }
  (**(code **)(puStack_1b0 + -0x7dc4))(ppppppiStack_1e8);
  if (uStack_144 == *(uint *)puStack_1e4) {
    return ppppppiStack_1f0;
  }
  pcStack_1d4 = surewarehk_rsa_priv_dec;
  uVar22 = uStack_144;
  (**(code **)(puStack_1b0 + -0x5328))();
  pppppiStack_278 = pppppiStack_1c0;
  puStack_27c = PTR___stack_chk_guard_006aabf0;
  puStack_1ec = puStack_100;
  uStack_1f4 = *(uint *)PTR___stack_chk_guard_006aabf0;
  pcStack_1d8 = "r";
  puStack_240 = &_gp;
  uStack_220 = 0;
  uStack_21c = 0;
  uStack_218 = 0;
  uStack_214 = 0;
  uStack_210 = 0;
  uStack_20c = 0;
  uStack_208 = 0;
  uStack_204 = 0;
  uStack_200 = 0;
  uStack_1fc = 0;
  uStack_1f8 = 0;
  iStack_234 = s_ENGINE_rsa_priv_dec_00674d90._0_4_;
  uStack_230 = s_ENGINE_rsa_priv_dec_00674d90._4_4_;
  uStack_22c = s_ENGINE_rsa_priv_dec_00674d90._8_4_;
  uStack_228 = s_ENGINE_rsa_priv_dec_00674d90._12_4_;
  uStack_224 = s_ENGINE_rsa_priv_dec_00674d90._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppppppiStack_250 = (int ******)0x366;
    (**(code **)(puStack_240 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
    iVar8 = 0;
  }
  else {
    iVar8 = (*(code *)PTR_RSA_get_ex_data_006aa640)(pcVar18,rsaHndidx);
    if (iVar8 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_240 + -0x589c))();
      }
      ppppppiStack_250 = (int ******)0x36b;
      ppppppiVar15 = (int ******)&DAT_0000006e;
      ppppppiStack_284 = (int ******)0x0;
      (**(code **)(puStack_240 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d9aa0;
    }
  }
  pcStack_26c = (char *)0x1;
  ppppppiStack_250 = ppppppiStack_274;
  iStack_24c = iVar8;
  if (pppppiStack_278 == (int *****)0x1) {
    pppppiStack_248 = pppppiStack_278;
    ppppppiStack_284 =
         (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_234,uVar22,piStack_280,&ppppppiStack_238);
    ppppppiVar15 = (int ******)&DAT_0000006e;
    surewarehk_error_handling(&iStack_234,0x6e,ppppppiStack_284);
    piStack_280 = &iStack_234;
    if (ppppppiStack_284 == (int ******)0x1) {
      ppppppiStack_284 = ppppppiStack_238;
    }
    goto LAB_005d9aa0;
  }
  pppppiStack_248 = (int *****)0x0;
  ppppppiStack_284 = (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_234,uVar22,piStack_280);
  ppppppiVar15 = (int ******)&DAT_0000006e;
  surewarehk_error_handling(&iStack_234,0x6e,ppppppiStack_284);
  piStack_280 = &iStack_234;
  if (ppppppiStack_284 != (int ******)0x1) goto LAB_005d9aa0;
  pcStack_26c = "r";
  piStack_280 = (int *)(**(code **)(puStack_240 + -0x7dd8))(ppppppiStack_238,"e_sureware.c",0x37f);
  if (piStack_280 == (int *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_240 + -0x589c))();
    }
    ppppppiVar15 = (int ******)&DAT_0000006e;
    ppppppiStack_250 = (int ******)0x381;
    (**(code **)(puStack_240 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    piStack_280 = (int *)&_ITM_registerTMCloneTable;
    goto LAB_005d9aa0;
  }
  (**(code **)(puStack_240 + -0x52ec))(piStack_280,ppppppiStack_274,ppppppiStack_238);
  if (pppppiStack_278 == (int *****)0x3) {
    pcVar24 = *(code **)(puStack_240 + -0x66d4);
LAB_005d9d0c:
    ppppppiStack_250 = ppppppiStack_238;
    ppppppiStack_284 = (int ******)(*pcVar24)(ppppppiStack_274,ppppppiStack_238,piStack_280,uVar22);
LAB_005d9cac:
    pcVar24 = *(code **)(puStack_240 + -0x7d6c);
    if ((int)ppppppiStack_284 < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_240 + -0x589c))();
      }
      ppppppiStack_250 = (int ******)0x397;
      (**(code **)(puStack_240 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d9c04;
    }
  }
  else {
    if (pppppiStack_278 == (int *****)0x4) {
      pppppiStack_248 = (int *****)0x0;
      iStack_24c = 0;
      ppppppiStack_250 = ppppppiStack_238;
      ppppppiStack_284 =
           (int ******)
           (**(code **)(puStack_240 + -0x66ac))(ppppppiStack_274,ppppppiStack_238,piStack_280);
      goto LAB_005d9cac;
    }
    bVar1 = pppppiStack_278 == (int *****)0x2;
    pppppiStack_278 = (int *****)&_ITM_registerTMCloneTable;
    if (bVar1) {
      pcVar24 = *(code **)(puStack_240 + -0x66a4);
      goto LAB_005d9d0c;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_240 + -0x589c))();
    }
    ppppppiStack_250 = (int ******)0x393;
    (**(code **)(puStack_240 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d9c04:
    pppppiStack_278 = (int *****)&_ITM_registerTMCloneTable;
    pcVar24 = *(code **)(puStack_240 + -0x7d6c);
  }
  (*pcVar24)(piStack_280,ppppppiStack_238);
  (**(code **)(puStack_240 + -0x7f58))(piStack_280);
  ppppppiVar15 = ppppppiStack_238;
LAB_005d9aa0:
  if (uStack_1f4 == *(uint *)puStack_27c) {
    return ppppppiStack_284;
  }
  pcStack_264 = surewarehk_load_pubkey;
  uVar23 = uStack_1f4;
  (**(code **)(puStack_240 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_28c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppppiStack_268 = &DAT_00674bfc;
  uStack_310 = 0;
  cStack_311 = '\0';
  uStack_30c = s_ENGINE_load_pubkey_00674dd0._0_4_;
  uStack_308 = s_ENGINE_load_pubkey_00674dd0._4_4_;
  uStack_304 = s_ENGINE_load_pubkey_00674dd0._8_4_;
  uStack_300 = s_ENGINE_load_pubkey_00674dd0._12_4_;
  uStack_2fc = s_ENGINE_load_pubkey_00674dd0._16_2_;
  cStack_2fa = s_ENGINE_load_pubkey_00674dd0[18];
  uStack_270 = uVar22;
  (*(code *)PTR_memset_006aab00)(auStack_2f9,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    puVar20 = &_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppppppiVar15 = (int ******)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x32c);
  }
  else {
    iVar8 = (*p_surewarehk_Info_Pubkey)(&uStack_30c,ppppppiVar15,&uStack_310,&cStack_311);
    uVar16 = uStack_310;
    if (iVar8 == 1) {
      uVar22 = (uint)cStack_311;
      uStack_2cc = s_sureware_load_public_00674e10._0_4_;
      uStack_2c8 = s_sureware_load_public_00674e10._4_4_;
      uStack_2c4 = s_sureware_load_public_00674e10._8_4_;
      uStack_2c0 = s_sureware_load_public_00674e10._12_4_;
      uStack_2bc = s_sureware_load_public_00674e10._16_4_;
      cStack_2b8 = s_sureware_load_public_00674e10[20];
      (*(code *)PTR_memset_006aab00)(auStack_2b7,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        puVar20 = &_ITM_registerTMCloneTable;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        ppppppiVar15 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)
                  (SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",0x299);
      }
      else if (uVar22 == 1) {
        uVar21 = uVar16 >> 2;
        puVar20 = (undefined1 *)(*(code *)PTR_RSA_new_method_006a881c)(uVar23);
        (*(code *)PTR_RSA_set_ex_data_006aa648)(puVar20,rsaHndidx,0);
        puVar2 = PTR_BN_new_006a82b4;
        *(uint *)(puVar20 + 0x3c) = *(uint *)(puVar20 + 0x3c) | 0x20;
        uVar9 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a82b4;
        *(undefined4 *)(puVar20 + 0x14) = uVar9;
        uVar9 = (*(code *)puVar2)();
        puVar2 = PTR_bn_expand2_006a9680;
        *(undefined4 *)(puVar20 + 0x10) = uVar9;
        (*(code *)puVar2)(*(undefined4 *)(puVar20 + 0x14),uVar21);
        (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar20 + 0x10),uVar21);
        puVar6 = *(undefined4 **)(puVar20 + 0x14);
        if ((((puVar6 != (undefined4 *)0x0) && (uVar21 == puVar6[2])) &&
            (puVar11 = *(undefined4 **)(puVar20 + 0x10), puVar11 != (undefined4 *)0x0)) &&
           (uVar21 == puVar11[2])) {
          iVar8 = (*p_surewarehk_Load_Rsa_Pubkey)(&uStack_2cc,ppppppiVar15,uVar16,*puVar11,*puVar6);
          surewarehk_error_handling(&uStack_2cc,0x6a,iVar8);
          if (iVar8 == 1) {
            piVar4 = *(int **)(puVar20 + 0x14);
            piVar4[1] = uVar21;
            if (uVar21 == 0) {
              *(undefined4 *)(*(int *)(puVar20 + 0x10) + 4) = 0;
            }
            else {
              iVar8 = (uVar16 & 0xfffffffc) - 4;
              piVar17 = (int *)(*piVar4 + iVar8);
              uVar23 = uVar21;
              do {
                uVar16 = uVar23 - 1;
                if (*piVar17 != 0) break;
                piVar17 = piVar17 + -1;
                uVar23 = uVar16;
              } while (uVar16 != 0);
              piVar17 = *(int **)(puVar20 + 0x10);
              piVar4[1] = uVar23;
              piVar17[1] = uVar21;
              piVar4 = (int *)(*piVar17 + iVar8);
              uVar23 = uVar21;
              do {
                uVar16 = uVar23 - 1;
                if (*piVar4 != 0) break;
                piVar4 = piVar4 + -1;
                uVar23 = uVar16;
              } while (uVar16 != 0);
              piVar17[1] = uVar23;
            }
            ppppppiVar15 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a8710)();
            uVar9 = 6;
            goto LAB_005da414;
          }
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2b3);
        }
        ppppppiVar15 = (int ******)0x0;
        (*(code *)PTR_RSA_free_006a86f0)(puVar20);
        uVar23 = uVar21;
      }
      else {
        puVar20 = &_ITM_registerTMCloneTable;
        if (uVar22 == 2) {
          uVar21 = uVar16 >> 2;
          puVar20 = (undefined1 *)(*(code *)PTR_DSA_new_method_006aa688)(uVar23);
          (*(code *)PTR_DSA_set_ex_data_006aa68c)(puVar20,dsaHndidx,0);
          uVar9 = (*(code *)PTR_BN_new_006a82b4)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar20 + 0x18) = uVar9;
          uVar9 = (*(code *)puVar2)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar20 + 0xc) = uVar9;
          uVar9 = (*(code *)puVar2)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar20 + 0x10) = uVar9;
          uVar9 = (*(code *)puVar2)();
          puVar2 = PTR_bn_expand2_006a9680;
          *(undefined4 *)(puVar20 + 0x14) = uVar9;
          (*(code *)puVar2)(*(undefined4 *)(puVar20 + 0x18),uVar21);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar20 + 0xc),uVar21);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar20 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar20 + 0x14),uVar21);
          puVar6 = *(undefined4 **)(puVar20 + 0x18);
          uVar22 = uVar21;
          if ((((puVar6 != (undefined4 *)0x0) && (uVar21 == puVar6[2])) &&
              (puVar11 = *(undefined4 **)(puVar20 + 0xc), puVar11 != (undefined4 *)0x0)) &&
             (((uVar21 == puVar11[2] &&
               (puVar19 = *(undefined4 **)(puVar20 + 0x10), puVar19 != (undefined4 *)0x0)) &&
              ((puVar19[2] == 5 &&
               ((puVar14 = *(undefined4 **)(puVar20 + 0x14), puVar14 != (undefined4 *)0x0 &&
                (uVar21 == puVar14[2])))))))) {
            iVar8 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_2cc,ppppppiVar15,uVar16,*puVar6,*puVar11,*puVar19,*puVar14);
            surewarehk_error_handling(&uStack_2cc,0x6a,iVar8);
            if (iVar8 == 1) goto LAB_005da448;
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x2df);
          }
          ppppppiVar15 = (int ******)0x0;
          (*(code *)PTR_DSA_free_006a862c)(puVar20);
          uVar23 = uVar21;
        }
        else {
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          ppppppiVar15 = (int ******)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",0x2f4);
        }
      }
    }
    else {
      puVar20 = &_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      ppppppiVar15 = (int ******)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x334);
      (*(code *)PTR_ERR_add_error_data_006a9264)(1,&uStack_30c);
    }
  }
  do {
    if (iStack_28c == *(int *)puVar3) {
      return ppppppiVar15;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar21 = uVar23;
LAB_005da448:
    piVar4 = *(int **)(puVar20 + 0x18);
    piVar4[1] = uVar21;
    if ((int)uVar21 < 1) {
      *(undefined4 *)(*(int *)(puVar20 + 0xc) + 4) = 0;
    }
    else {
      iVar8 = uVar21 * 4 + -4;
      piVar17 = (int *)(*piVar4 + iVar8);
      uVar23 = uVar21;
      do {
        uVar16 = uVar23 - 1;
        if (*piVar17 != 0) break;
        piVar17 = piVar17 + -1;
        uVar23 = uVar16;
      } while (uVar16 != 0);
      piVar17 = *(int **)(puVar20 + 0xc);
      piVar4[1] = uVar23;
      piVar17[1] = uVar21;
      piVar4 = (int *)(*piVar17 + iVar8);
      uVar23 = uVar21;
      do {
        uVar16 = uVar23 - 1;
        if (*piVar4 != 0) break;
        piVar4 = piVar4 + -1;
        uVar23 = uVar16;
      } while (uVar16 != 0);
      piVar17[1] = uVar23;
    }
    piVar17 = *(int **)(puVar20 + 0x10);
    iVar8 = 5;
    piVar17[1] = 5;
    piVar4 = (int *)(*piVar17 + 0x10);
    do {
      if (*piVar4 != 0) break;
      iVar8 = iVar8 + -1;
      piVar4 = piVar4 + -1;
    } while (iVar8 != 0);
    piVar4 = *(int **)(puVar20 + 0x14);
    piVar17[1] = iVar8;
    piVar4[1] = uVar21;
    if (0 < (int)uVar21) {
      piVar17 = (int *)(*piVar4 + uVar21 * 4 + -4);
      do {
        uVar23 = uVar22 - 1;
        if (*piVar17 != 0) break;
        piVar17 = piVar17 + -1;
        uVar22 = uVar23;
      } while (uVar23 != 0);
      piVar4[1] = uVar22;
    }
    ppppppiVar15 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a8710)();
    uVar9 = 0x74;
LAB_005da414:
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(ppppppiVar15,uVar9,puVar20);
    uVar23 = uVar21;
  } while( true );
}

