
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ****** surewarehk_dsa_do_sign(undefined4 param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int **ppiVar10;
  int iVar11;
  int **ppiVar12;
  int *piVar13;
  uint uVar14;
  int ******ppppppiVar15;
  int ******ppppppiVar16;
  char *pcVar17;
  int ******ppppppiVar18;
  uint uVar19;
  int unaff_s5;
  int ******ppppppiVar20;
  int unaff_s6;
  uint uVar21;
  code *pcVar22;
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
  int ******ppppppiStack_270;
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
  int iStack_1f4;
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
  int *****pppppiStack_1a8;
  int ******ppppppiStack_1a4;
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
  int ******ppppppiStack_144;
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
  undefined4 uStack_98;
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
  
  puStack_a0 = PTR___stack_chk_guard_006a9ae8;
  puStack_9c = (undefined4 *)&_gp_1;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_70 = &_gp;
  ppiStack_108 = (int **)&DAT_0000002d;
  local_64 = DAT_00674420;
  local_60 = DAT_00674424;
  local_5c = DAT_00674428;
  local_58 = DAT_0067442c;
  local_54 = DAT_00674430;
  local_52 = DAT_00674432;
  pcVar6 = DAT_0067442c;
  (*(code *)PTR_memset_006a99f4)(auStack_51,0);
  if (p_surewarehk_Dsa_Sign == (code *)0x0) {
    ppiStack_a4 = (int **)&_gp_1;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(local_70 + -0x58a8))();
    }
    ppiStack_108 = (int **)0x75;
    pcVar6 = "e_sureware.c";
    local_78 = (undefined4 *)0x404;
    uStack_12c = 0x65;
    (**(code **)(local_70 + -0x6eac))(SUREWARE_lib_error_code,0x65,0x75,"e_sureware.c");
  }
  else {
    uStack_12c = dsaHndidx;
    unaff_s5 = (**(code **)(local_70 + -0x5868))(param_3);
    if (unaff_s5 == 0) {
      ppiStack_a4 = (int **)&_gp_1;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(local_70 + -0x58a8))();
      }
      ppiStack_108 = (int **)&DAT_00000069;
      pcVar6 = "e_sureware.c";
      local_78 = (undefined4 *)0x40a;
      uStack_12c = 0x65;
      (**(code **)(local_70 + -0x6eac))(SUREWARE_lib_error_code,0x65,0x69,"e_sureware.c");
    }
    else {
      ppiStack_a4 = (int **)(**(code **)(local_70 + -0x6684))();
      if (ppiStack_a4 == (int **)0x0) {
        ppiStack_a4 = (int **)&_gp_1;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (**(code **)(local_70 + -0x58a8))();
        }
        ppiStack_108 = (int **)&DAT_00000041;
        pcVar6 = "e_sureware.c";
        local_78 = (undefined4 *)0x40f;
        uStack_12c = 0x65;
        (**(code **)(local_70 + -0x6eac))(SUREWARE_lib_error_code,0x65,0x41,"e_sureware.c");
      }
      else {
        piVar4 = (int *)(**(code **)(local_70 + -0x7c2c))();
        pcVar22 = *(code **)(local_70 + -0x7c2c);
        *ppiStack_a4 = piVar4;
        piVar4 = (int *)(*pcVar22)();
        ppiStack_a4[1] = piVar4;
        if ((*ppiStack_a4 == (int *)0x0) || (piVar4 == (int *)0x0)) {
LAB_005d6b4c:
          pcVar22 = *(code **)(local_70 + -0x6688);
        }
        else {
          (**(code **)(local_70 + -0x68bc))(*ppiStack_a4,5);
          uStack_12c = 5;
          (**(code **)(local_70 + -0x68bc))(ppiStack_a4[1]);
          if ((char *)(*ppiStack_a4)[2] != &DAT_00000005) goto LAB_005d6b4c;
          unaff_s6 = ppiStack_a4[1][2];
          pcVar22 = *(code **)(local_70 + -0x6688);
          if (unaff_s6 == 5) {
            pcVar6 = (char *)**ppiStack_a4;
            puStack_9c = &local_64;
            local_78 = (undefined4 *)*ppiStack_a4[1];
            local_74 = unaff_s5;
            ppiStack_108 = (int **)(*p_surewarehk_Dsa_Sign)(puStack_9c,param_2,param_1,pcVar6);
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
            goto LAB_005d6b4c;
          }
        }
        (*pcVar22)(ppiStack_a4);
      }
    }
  }
  if (local_24 == *(int *)puStack_a0) {
    return (int ******)0x0;
  }
  pcStack_8c = surewarehk_rsa_sign;
  iVar7 = local_24;
  (**(code **)(local_70 + -0x5330))();
  puStack_138 = local_78;
  puStack_13c = PTR___stack_chk_guard_006a9ae8;
  iStack_ac = *(int *)PTR___stack_chk_guard_006a9ae8;
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
  piStack_ec = s_ENGINE_rsa_sign_00674460._0_4_;
  uStack_e8 = s_ENGINE_rsa_sign_00674460._4_4_;
  uStack_e4 = s_ENGINE_rsa_sign_00674460._8_4_;
  uStack_e0 = s_ENGINE_rsa_sign_00674460._12_4_;
  ppiStack_134 = ppiStack_108;
  uStack_98 = param_1;
  iStack_94 = param_2;
  iStack_90 = unaff_s5;
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    ppppppiStack_140 = (int ******)&_gp_1;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiStack_1a4 = (int ******)0x75;
    pcVar6 = "e_sureware.c";
    ppiStack_108 = (int **)0x3df;
    piStack_280 = (int *)&DAT_0000006f;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
    ppppppiVar20 = (int ******)0x0;
  }
  else {
    puVar5 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006a9534)(pcVar6,rsaHndidx);
    param_2 = iVar7;
    if (puVar5 == (undefined4 *)0x0) {
      ppppppiStack_140 = (int ******)&_gp_1;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      ppppppiStack_1a4 = (int ******)&DAT_00000069;
      pcVar6 = "e_sureware.c";
      ppiStack_108 = (int **)0x3e4;
      piStack_280 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
      ppppppiVar20 = (int ******)0x0;
    }
    else if (puStack_138 == (undefined4 *)0x1) {
      pcVar6 = (char *)&ppppppiStack_f0;
      puStack_100 = puStack_138;
      ppppppiStack_140 = (int ******)(*p_surewarehk_Rsa_Sign)(&piStack_ec,iVar7,uStack_12c);
      piStack_280 = (int *)&DAT_0000006f;
      ppppppiStack_1a4 = ppppppiStack_140;
      surewarehk_error_handling(&piStack_ec);
      ppppppiVar20 = ppppppiStack_140;
      ppiStack_134 = &piStack_ec;
      puStack_104 = puVar5;
      if (ppppppiStack_140 == (int ******)0x1) {
        ppppppiVar20 = ppppppiStack_f0;
      }
    }
    else {
      ppppppiStack_140 = (int ******)&_gp_1;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      ppppppiStack_1a4 = (int ******)&DAT_0000006b;
      pcVar6 = "e_sureware.c";
      ppiStack_108 = (int **)0x3f1;
      piStack_280 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
      ppppppiVar20 = (int ******)0x0;
    }
  }
  if (iStack_ac == *(int *)puStack_13c) {
    return ppppppiVar20;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1e4 = PTR___stack_chk_guard_006a9ae8;
  pcStack_26c = "encrypt";
  ppiStack_1a0 = ppiStack_108;
  ppppppiStack_1e8 = &pppppiStack_198;
  puStack_19c = puStack_104;
  ppppppiStack_1e0 = apppppiStack_176;
  puStack_1b0 = &_gp;
  pppppiStack_1a8 = pppppiStack_fc;
  ppppppiStack_144 = *(int *******)PTR___stack_chk_guard_006a9ae8;
  iStack_130 = param_2;
  iStack_128 = unaff_s6;
  (*(code *)PTR_BN_init_006a857c)(ppppppiStack_1e8);
  ppppppiStack_274 = (int ******)&DAT_00000032;
  piVar4 = (int *)0x0;
  pppppiStack_184 = (int *****)DAT_0067430c;
  uStack_180 = DAT_00674310;
  puStack_17c = DAT_00674314;
  uStack_178 = DAT_00674318;
  pcVar17 = (char *)DAT_00674314;
  (**(code **)(puStack_1b0 + -0x53ec))(ppppppiStack_1e0);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_005d72d4:
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_1b0 + -0x58a8))();
    }
    ppppppiStack_274 = (int ******)0x75;
    pcVar17 = "e_sureware.c";
    pppppiStack_1c0 = (int *****)0x435;
    piVar4 = (int *)&DAT_0000006b;
    (**(code **)(puStack_1b0 + -0x6eac))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
LAB_005d7108:
    piStack_280 = piVar4;
    ppppppiStack_1f0 = (int ******)0x0;
    ppppppiStack_1dc = (int ******)pcVar6;
  }
  else {
    if (piStack_280 == (int *)0x0) goto LAB_005d7108;
    (**(code **)(puStack_1b0 + -0x68bc))(piStack_280,puStack_100[1]);
    piVar4 = (int *)piStack_280[2];
    if (piVar4 != (int *)puStack_100[1]) goto LAB_005d7108;
    pppppiStack_1c0 = *(int ******)pcVar6;
    pppppiStack_1b4 = (int *****)*piStack_280;
    pcVar17 = (char *)((int)*(int ******)((int)pcVar6 + 4) << 2);
    pppppiStack_1b8 = *ppppppiStack_1a4;
    iStack_1bc = (int)ppppppiStack_1a4[1] << 2;
    ppppppiStack_1a4 = &pppppiStack_184;
    pcVar6 = (char *)(*p_surewarehk_Mod_Exp)(&pppppiStack_184,(int)piVar4 << 2,*puStack_100,pcVar17)
    ;
    piVar4 = (int *)&DAT_0000006b;
    ppppppiStack_274 = (int ******)pcVar6;
    surewarehk_error_handling(ppppppiStack_1a4);
    if ((int ******)pcVar6 == (int ******)0x1) {
      iVar7 = puStack_100[1];
      piStack_280[1] = iVar7;
      if (0 < iVar7) {
        iVar8 = *piStack_280 + iVar7 * 4 + -8;
        do {
          if (*(int *)(iVar8 + 4) != 0) break;
          iVar7 = iVar7 + -1;
          iVar8 = iVar8 + -4;
        } while (iVar7 != 0);
        piStack_280[1] = iVar7;
      }
    }
    else if ((int ******)pcVar6 == (int ******)0x0) goto LAB_005d7108;
    ppppppiStack_274 = (int ******)&DAT_00000032;
    pppppiStack_184 = (int *****)DAT_0067430c;
    uStack_180 = DAT_00674310;
    puStack_17c = DAT_00674314;
    uStack_178 = DAT_00674318;
    pcVar17 = (char *)DAT_00674314;
    (**(code **)(puStack_1b0 + -0x53ec))(ppppppiStack_1e0,0);
    if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_005d72d4;
    (**(code **)(puStack_1b0 + -0x68bc))(ppppppiStack_1e8,puStack_100[1]);
    ppppppiStack_1dc = ppppppiStack_1a4;
    piVar4 = piStack_190;
    if (piStack_190 != (int *)puStack_100[1]) goto LAB_005d7108;
    pppppiStack_1b8 = (int *****)*ppiStack_1a0;
    iStack_1bc = (int)ppiStack_1a0[1] << 2;
    pppppiStack_1c0 = (int *****)*puStack_19c;
    pcVar17 = (char *)(puStack_19c[1] << 2);
    pppppiStack_1b4 = pppppiStack_198;
    ppppppiStack_1e0 =
         (int ******)
         (*p_surewarehk_Mod_Exp)(ppppppiStack_1a4,(int)piStack_190 << 2,*puStack_100,pcVar17);
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
      pcVar6 = (char *)ppppppiStack_1dc;
      if (ppppppiStack_1e0 == (int ******)0x0) goto LAB_005d7108;
    }
    pppppiStack_1c0 = pppppiStack_1a8;
    ppppppiStack_274 = ppppppiStack_1e8;
    pcVar17 = (char *)puStack_100;
    iVar7 = (**(code **)(puStack_1b0 + -0x686c))
                      (piStack_280,piStack_280,ppppppiStack_1e8,puStack_100);
    ppppppiStack_1f0 = (int ******)(uint)(iVar7 != 0);
  }
  (**(code **)(puStack_1b0 + -0x7dc4))(ppppppiStack_1e8);
  if (ppppppiStack_144 == *(int *******)puStack_1e4) {
    return ppppppiStack_1f0;
  }
  pcStack_1d4 = surewarehk_rsa_priv_dec;
  ppppppiVar20 = ppppppiStack_144;
  (**(code **)(puStack_1b0 + -0x5330))();
  pppppiStack_278 = pppppiStack_1c0;
  puStack_27c = PTR___stack_chk_guard_006a9ae8;
  puStack_1ec = puStack_100;
  iStack_1f4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_1d8 = "encrypt";
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
  iStack_234 = s_ENGINE_rsa_priv_dec_006744a0._0_4_;
  uStack_230 = s_ENGINE_rsa_priv_dec_006744a0._4_4_;
  uStack_22c = s_ENGINE_rsa_priv_dec_006744a0._8_4_;
  uStack_228 = s_ENGINE_rsa_priv_dec_006744a0._12_4_;
  uStack_224 = s_ENGINE_rsa_priv_dec_006744a0._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiStack_250 = (int ******)0x38f;
    (**(code **)(puStack_240 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
    iVar7 = 0;
  }
  else {
    iVar7 = (*(code *)PTR_RSA_get_ex_data_006a9534)(pcVar17,rsaHndidx);
    if (iVar7 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_240 + -0x58a8))();
      }
      ppppppiStack_250 = (int ******)0x394;
      ppppppiVar15 = (int ******)&DAT_0000006e;
      ppppppiStack_284 = (int ******)0x0;
      (**(code **)(puStack_240 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d74cc;
    }
  }
  pcStack_26c = (char *)0x1;
  ppppppiStack_250 = ppppppiStack_274;
  iStack_24c = iVar7;
  if (pppppiStack_278 == (int *****)0x1) {
    pppppiStack_248 = pppppiStack_278;
    ppppppiStack_284 =
         (int ******)
         (*p_surewarehk_Rsa_Priv_Dec)(&iStack_234,ppppppiVar20,piStack_280,&ppppppiStack_238);
    ppppppiVar15 = (int ******)&DAT_0000006e;
    surewarehk_error_handling(&iStack_234,0x6e,ppppppiStack_284);
    piStack_280 = &iStack_234;
    if (ppppppiStack_284 == (int ******)0x1) {
      ppppppiStack_284 = ppppppiStack_238;
    }
    goto LAB_005d74cc;
  }
  pppppiStack_248 = (int *****)0x0;
  ppppppiStack_284 = (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_234,ppppppiVar20,piStack_280);
  ppppppiVar15 = (int ******)&DAT_0000006e;
  surewarehk_error_handling(&iStack_234,0x6e,ppppppiStack_284);
  piStack_280 = &iStack_234;
  if (ppppppiStack_284 != (int ******)0x1) goto LAB_005d74cc;
  pcStack_26c = "encrypt";
  piStack_280 = (int *)(**(code **)(puStack_240 + -0x7dd8))(ppppppiStack_238,"e_sureware.c",0x3ac);
  if (piStack_280 == (int *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_240 + -0x58a8))();
    }
    ppppppiVar15 = (int ******)&DAT_0000006e;
    ppppppiStack_250 = (int ******)0x3ae;
    (**(code **)(puStack_240 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    piStack_280 = (int *)&_gp_1;
    goto LAB_005d74cc;
  }
  (**(code **)(puStack_240 + -0x52f4))(piStack_280,ppppppiStack_274,ppppppiStack_238);
  if (pppppiStack_278 == (int *****)0x3) {
    pcVar22 = *(code **)(puStack_240 + -0x66f8);
LAB_005d7738:
    ppppppiStack_250 = ppppppiStack_238;
    ppppppiStack_284 =
         (int ******)(*pcVar22)(ppppppiStack_274,ppppppiStack_238,piStack_280,ppppppiVar20);
LAB_005d76d8:
    pcVar22 = *(code **)(puStack_240 + -0x7d6c);
    if ((int)ppppppiStack_284 < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_240 + -0x58a8))();
      }
      ppppppiStack_250 = (int ******)0x3cb;
      (**(code **)(puStack_240 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d7630;
    }
  }
  else {
    if (pppppiStack_278 == (int *****)0x4) {
      pppppiStack_248 = (int *****)0x0;
      iStack_24c = 0;
      ppppppiStack_250 = ppppppiStack_238;
      ppppppiStack_284 =
           (int ******)
           (**(code **)(puStack_240 + -0x66d0))(ppppppiStack_274,ppppppiStack_238,piStack_280);
      goto LAB_005d76d8;
    }
    bVar1 = pppppiStack_278 == (int *****)0x2;
    pppppiStack_278 = (int *****)&_gp_1;
    if (bVar1) {
      pcVar22 = *(code **)(puStack_240 + -0x66c8);
      goto LAB_005d7738;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_240 + -0x58a8))();
    }
    ppppppiStack_250 = (int ******)0x3c6;
    (**(code **)(puStack_240 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d7630:
    pppppiStack_278 = (int *****)&_gp_1;
    pcVar22 = *(code **)(puStack_240 + -0x7d6c);
  }
  (*pcVar22)(piStack_280,ppppppiStack_238);
  (**(code **)(puStack_240 + -0x7f58))(piStack_280);
  ppppppiVar15 = ppppppiStack_238;
LAB_005d74cc:
  if (iStack_1f4 == *(int *)puStack_27c) {
    return ppppppiStack_284;
  }
  pcStack_264 = surewarehk_load_pubkey;
  iVar7 = iStack_1f4;
  (**(code **)(puStack_240 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_28c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppppiStack_268 = &DAT_0067430c;
  uStack_310 = 0;
  cStack_311 = '\0';
  uStack_30c = s_ENGINE_load_pubkey_006744e0._0_4_;
  uStack_308 = s_ENGINE_load_pubkey_006744e0._4_4_;
  uStack_304 = s_ENGINE_load_pubkey_006744e0._8_4_;
  uStack_300 = s_ENGINE_load_pubkey_006744e0._12_4_;
  uStack_2fc = s_ENGINE_load_pubkey_006744e0._16_2_;
  cStack_2fa = s_ENGINE_load_pubkey_006744e0[18];
  ppppppiStack_270 = ppppppiVar20;
  (*(code *)PTR_memset_006a99f4)(auStack_2f9,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiVar18 = (int ******)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
  }
  else {
    iVar8 = (*p_surewarehk_Info_Pubkey)(&uStack_30c,ppppppiVar15,&uStack_310,&cStack_311);
    uVar21 = uStack_310;
    if (iVar8 == 1) {
      ppppppiVar20 = (int ******)(int)cStack_311;
      uStack_2cc = s_sureware_load_public_00674520._0_4_;
      uStack_2c8 = s_sureware_load_public_00674520._4_4_;
      uStack_2c4 = s_sureware_load_public_00674520._8_4_;
      uStack_2c0 = s_sureware_load_public_00674520._12_4_;
      uStack_2bc = s_sureware_load_public_00674520._16_4_;
      cStack_2b8 = s_sureware_load_public_00674520[20];
      (*(code *)PTR_memset_006a99f4)(auStack_2b7,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        ppppppiVar18 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
      }
      else if (ppppppiVar20 == (int ******)0x1) {
        iVar7 = (*(code *)PTR_RSA_new_method_006a772c)(iVar7);
        (*(code *)PTR_RSA_set_ex_data_006a953c)(iVar7,rsaHndidx,0);
        puVar2 = PTR_BN_new_006a71b4;
        *(uint *)(iVar7 + 0x3c) = *(uint *)(iVar7 + 0x3c) | 0x20;
        uVar9 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar7 + 0x14) = uVar9;
        iVar8 = (*(code *)puVar2)();
        *(int *)(iVar7 + 0x10) = iVar8;
        if ((*(int *)(iVar7 + 0x14) != 0) && (iVar8 != 0)) {
          uVar19 = uVar21 >> 2;
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar7 + 0x14),uVar19);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar7 + 0x10),uVar19);
          if ((uVar19 == (*(undefined4 **)(iVar7 + 0x14))[2]) &&
             (uVar19 == (*(undefined4 **)(iVar7 + 0x10))[2])) {
            iVar8 = (*p_surewarehk_Load_Rsa_Pubkey)
                              (&uStack_2cc,ppppppiVar15,uVar21,**(undefined4 **)(iVar7 + 0x10),
                               **(undefined4 **)(iVar7 + 0x14));
            surewarehk_error_handling(&uStack_2cc,0x6a,iVar8);
            if (iVar8 == 1) {
              piVar4 = *(int **)(iVar7 + 0x14);
              piVar4[1] = uVar19;
              if (uVar19 == 0) {
                *(undefined4 *)(*(int *)(iVar7 + 0x10) + 4) = 0;
              }
              else {
                iVar8 = (uVar21 & 0xfffffffc) - 4;
                piVar13 = (int *)(*piVar4 + iVar8);
                uVar21 = uVar19;
                do {
                  uVar14 = uVar21 - 1;
                  if (*piVar13 != 0) break;
                  piVar13 = piVar13 + -1;
                  uVar21 = uVar14;
                } while (uVar14 != 0);
                piVar13 = *(int **)(iVar7 + 0x10);
                piVar4[1] = uVar21;
                piVar13[1] = uVar19;
                piVar4 = (int *)(*piVar13 + iVar8);
                do {
                  uVar21 = uVar19 - 1;
                  if (*piVar4 != 0) break;
                  piVar4 = piVar4 + -1;
                  uVar19 = uVar21;
                } while (uVar21 != 0);
                piVar13[1] = uVar19;
              }
              ppppppiVar18 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a7620)();
              uVar9 = 6;
              goto LAB_005d7f4c;
            }
            if (SUREWARE_lib_error_code == 0) {
              SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            (*(code *)PTR_ERR_put_error_006a7f34)
                      (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2d8);
          }
        }
        ppppppiVar18 = (int ******)0x0;
        (*(code *)PTR_RSA_free_006a7600)(iVar7);
      }
      else if (ppppppiVar20 == (int ******)&SUB_00000002) {
        iVar7 = (*(code *)PTR_DSA_new_method_006a957c)(iVar7);
        (*(code *)PTR_DSA_set_ex_data_006a9580)(iVar7,dsaHndidx,0);
        uVar9 = (*(code *)PTR_BN_new_006a71b4)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar7 + 0x18) = uVar9;
        uVar9 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar7 + 0xc) = uVar9;
        uVar9 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar7 + 0x10) = uVar9;
        iVar8 = (*(code *)puVar2)();
        *(int *)(iVar7 + 0x14) = iVar8;
        if ((((*(int *)(iVar7 + 0x18) != 0) && (*(int *)(iVar7 + 0xc) != 0)) &&
            (*(int *)(iVar7 + 0x10) != 0)) && (iVar8 != 0)) {
          ppppppiVar18 = (int ******)(uVar21 >> 2);
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar7 + 0x18),ppppppiVar18);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar7 + 0xc),ppppppiVar18);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar7 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar7 + 0x14),ppppppiVar18);
          ppppppiVar20 = ppppppiVar18;
          if (((ppppppiVar18 == (int ******)(*(undefined4 **)(iVar7 + 0x18))[2]) &&
              (ppppppiVar18 == (int ******)(*(undefined4 **)(iVar7 + 0xc))[2])) &&
             (((*(undefined4 **)(iVar7 + 0x10))[2] == 5 &&
              (ppppppiVar18 == (int ******)(*(undefined4 **)(iVar7 + 0x14))[2])))) {
            iVar8 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_2cc,ppppppiVar15,uVar21,**(undefined4 **)(iVar7 + 0x18),
                               **(undefined4 **)(iVar7 + 0xc),**(undefined4 **)(iVar7 + 0x10),
                               **(undefined4 **)(iVar7 + 0x14));
            surewarehk_error_handling(&uStack_2cc,0x6a,iVar8);
            if (iVar8 == 1) {
              piVar4 = *(int **)(iVar7 + 0x18);
              piVar4[1] = (int)ppppppiVar18;
              if (ppppppiVar18 == (int ******)0x0) goto LAB_005d7f80;
              iVar8 = (uVar21 & 0xfffffffc) - 4;
              piVar13 = (int *)(*piVar4 + iVar8);
              ppppppiVar15 = ppppppiVar18;
              do {
                ppppppiVar16 = (int ******)((int)ppppppiVar15 + -1);
                if (*piVar13 != 0) break;
                piVar13 = piVar13 + -1;
                ppppppiVar15 = ppppppiVar16;
              } while (ppppppiVar16 != (int ******)0x0);
              piVar13 = *(int **)(iVar7 + 0xc);
              piVar4[1] = (int)ppppppiVar15;
              piVar13[1] = (int)ppppppiVar18;
              piVar4 = (int *)(*piVar13 + iVar8);
              ppppppiVar15 = ppppppiVar18;
              do {
                ppppppiVar16 = (int ******)((int)ppppppiVar15 + -1);
                if (*piVar4 != 0) break;
                piVar4 = piVar4 + -1;
                ppppppiVar15 = ppppppiVar16;
              } while (ppppppiVar16 != (int ******)0x0);
              piVar13[1] = (int)ppppppiVar15;
              goto LAB_005d7dc4;
            }
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
          }
        }
        ppppppiVar18 = (int ******)0x0;
        (*(code *)PTR_DSA_free_006a7530)(iVar7);
      }
      else {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        ppppppiVar18 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
      }
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      ppppppiVar18 = (int ******)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      (*(code *)PTR_ERR_add_error_data_006a813c)(1,&uStack_30c);
    }
  }
  do {
    if (iStack_28c == *(int *)puVar3) {
      return ppppppiVar18;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005d7f80:
    *(undefined4 *)(*(int *)(iVar7 + 0xc) + 4) = 0;
LAB_005d7dc4:
    piVar4 = *(int **)(iVar7 + 0x10);
    iVar11 = 5;
    piVar4[1] = 5;
    iVar8 = *piVar4 + 0xc;
    do {
      if (*(int *)(iVar8 + 4) != 0) break;
      iVar11 = iVar11 + -1;
      iVar8 = iVar8 + -4;
    } while (iVar11 != 0);
    piVar13 = *(int **)(iVar7 + 0x14);
    piVar4[1] = iVar11;
    piVar13[1] = (int)ppppppiVar18;
    if (0 < (int)ppppppiVar18) {
      iVar8 = *piVar13 + (int)ppppppiVar18 * 4 + -8;
      do {
        if (*(int *)(iVar8 + 4) != 0) break;
        ppppppiVar20 = (int ******)((int)ppppppiVar20 + -1);
        iVar8 = iVar8 + -4;
      } while (ppppppiVar20 != (int ******)0x0);
      piVar13[1] = (int)ppppppiVar20;
    }
    ppppppiVar18 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a7620)();
    uVar9 = 0x74;
LAB_005d7f4c:
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(ppppppiVar18,uVar9,iVar7);
  } while( true );
}

