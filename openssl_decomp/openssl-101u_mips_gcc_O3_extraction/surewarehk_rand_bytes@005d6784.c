
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ****** surewarehk_rand_bytes(undefined4 *param_1,char *param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int ******ppppppiVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int **ppiVar10;
  int iVar11;
  int **ppiVar12;
  undefined4 *puVar13;
  int *piVar14;
  uint uVar15;
  int ******ppppppiVar16;
  int ******ppppppiVar17;
  char *pcVar18;
  char *pcVar19;
  int ******ppppppiVar20;
  uint uVar21;
  undefined4 *unaff_s2;
  undefined *unaff_s4;
  int unaff_s5;
  int unaff_s6;
  uint uVar22;
  code *pcVar23;
  char cStack_391;
  uint uStack_390;
  undefined4 uStack_38c;
  undefined4 uStack_388;
  undefined4 uStack_384;
  undefined4 uStack_380;
  undefined2 uStack_37c;
  char cStack_37a;
  undefined auStack_379 [45];
  undefined4 uStack_34c;
  undefined4 uStack_348;
  undefined4 uStack_344;
  undefined4 uStack_340;
  undefined4 uStack_33c;
  char cStack_338;
  undefined auStack_337 [43];
  int iStack_30c;
  int ******ppppppiStack_304;
  int *piStack_300;
  undefined *puStack_2fc;
  int *****pppppiStack_2f8;
  int ******ppppppiStack_2f4;
  int ******ppppppiStack_2f0;
  char *pcStack_2ec;
  int ****ppppiStack_2e8;
  code *pcStack_2e4;
  int ******ppppppiStack_2d0;
  int iStack_2cc;
  int *****pppppiStack_2c8;
  undefined *puStack_2c0;
  int ******ppppppiStack_2b8;
  int iStack_2b4;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  undefined4 uStack_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  undefined4 uStack_29c;
  undefined4 uStack_298;
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  undefined4 uStack_288;
  undefined4 uStack_284;
  undefined4 uStack_280;
  undefined4 uStack_27c;
  undefined4 uStack_278;
  int iStack_274;
  int ******ppppppiStack_270;
  undefined4 *puStack_26c;
  int ******ppppppiStack_268;
  undefined *puStack_264;
  int ******ppppppiStack_260;
  int ******ppppppiStack_25c;
  char *pcStack_258;
  code *pcStack_254;
  int *****pppppiStack_240;
  int iStack_23c;
  int *****pppppiStack_238;
  int *****pppppiStack_234;
  undefined *puStack_230;
  int *****pppppiStack_228;
  int ******ppppppiStack_224;
  int **ppiStack_220;
  undefined4 *puStack_21c;
  int *****pppppiStack_218;
  int iStack_214;
  int *piStack_210;
  int *****pppppiStack_204;
  undefined4 uStack_200;
  undefined4 *puStack_1fc;
  undefined2 uStack_1f8;
  int *****apppppiStack_1f6 [12];
  int ******ppppppiStack_1c4;
  int ******ppppppiStack_1c0;
  undefined *puStack_1bc;
  undefined4 *puStack_1b8;
  int **ppiStack_1b4;
  undefined4 *puStack_1b0;
  undefined4 uStack_1ac;
  int iStack_1a8;
  int **ppiStack_188;
  undefined4 *puStack_184;
  undefined4 *puStack_180;
  int *****pppppiStack_17c;
  int ******ppppppiStack_170;
  int *piStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  int iStack_12c;
  int **ppiStack_124;
  undefined *puStack_120;
  undefined4 *puStack_11c;
  int iStack_118;
  undefined4 *puStack_114;
  int iStack_110;
  code *pcStack_10c;
  undefined4 *puStack_f8;
  int iStack_f4;
  undefined *puStack_f0;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  char *pcStack_d8;
  undefined2 uStack_d4;
  undefined uStack_d2;
  undefined auStack_d1 [45];
  undefined4 *puStack_a4;
  undefined *puStack_a0;
  undefined *puStack_9c;
  undefined4 *puStack_98;
  char *pcStack_94;
  undefined *puStack_90;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined2 local_4c;
  undefined auStack_4a [46];
  int local_1c;
  
  puStack_9c = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_5c = s_ENGINE_rand_bytes_006743c4._0_4_;
  local_58 = s_ENGINE_rand_bytes_006743c4._4_4_;
  local_54 = s_ENGINE_rand_bytes_006743c4._8_4_;
  local_50 = s_ENGINE_rand_bytes_006743c4._12_4_;
  local_4c = s_ENGINE_rand_bytes_006743c4._16_2_;
  (*(code *)PTR_memset_006a99f4)(auStack_4a,0,0x2e);
  if (p_surewarehk_Rand_Bytes == (code *)0x0) {
    puStack_a0 = &_gp_1;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    pcVar18 = (char *)0x75;
    param_1 = (undefined4 *)&DAT_0000006c;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6c,0x75,"e_sureware.c");
    ppppppiVar4 = (int ******)0x0;
  }
  else {
    unaff_s2 = &local_5c;
    pcVar18 = param_2;
    puStack_a0 = (undefined *)(*p_surewarehk_Rand_Bytes)(unaff_s2,param_1,param_2);
    switch(puStack_a0) {
    case (undefined *)0x1:
      ppppppiVar4 = (int ******)0x1;
      goto LAB_005d685c;
    case (undefined *)0xfffffffb:
      pcVar18 = (char *)0x6a;
      break;
    case (undefined *)0xfffffffc:
      pcVar18 = (char *)0x67;
      break;
    case (undefined *)0xfffffffd:
      pcVar18 = (char *)0x68;
      break;
    case (undefined *)0xfffffffe:
      pcVar18 = (char *)0x66;
      break;
    default:
      pcVar18 = (char *)0x65;
    }
    param_2 = "encrypt";
    param_1 = (undefined4 *)&DAT_0000006c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0x6c,pcVar18,"e_sureware.c");
    if (local_5c._0_1_ != '\0') {
      unaff_s4 = &_gp_1;
      param_1 = unaff_s2;
      (*(code *)PTR_ERR_add_error_data_006a813c)(1);
      if (logstream != 0) {
        puStack_a0 = (undefined *)((uint)puStack_a0 ^ 1);
        (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x15,"e_sureware.c",0x286);
        uVar9 = (*(code *)PTR_strlen_006a9a24)(unaff_s2);
        (*(code *)PTR_BIO_write_006a6e14)(logstream,unaff_s2,uVar9);
        pcVar18 = "e_sureware.c";
        param_1 = (undefined4 *)&DAT_00000015;
        (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x15,"e_sureware.c",0x288);
        ppppppiVar4 = (int ******)(uint)(puStack_a0 == (undefined *)0x0);
        goto LAB_005d685c;
      }
    }
    puStack_a0 = (undefined *)((uint)puStack_a0 ^ 1);
    ppppppiVar4 = (int ******)(uint)(puStack_a0 == (undefined *)0x0);
  }
LAB_005d685c:
  if (local_1c == *(int *)puStack_9c) {
    return ppppppiVar4;
  }
  iStack_118 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_120 = PTR___stack_chk_guard_006a9ae8;
  puStack_11c = (undefined4 *)&_gp_1;
  puStack_a4 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  puStack_f0 = &_gp;
  ppiStack_188 = (int **)&DAT_0000002d;
  uStack_e4 = DAT_00674420;
  uStack_e0 = DAT_00674424;
  uStack_dc = DAT_00674428;
  pcStack_d8 = DAT_0067442c;
  uStack_d4 = DAT_00674430;
  uStack_d2 = DAT_00674432;
  pcVar19 = DAT_0067442c;
  puStack_98 = unaff_s2;
  pcStack_94 = param_2;
  puStack_90 = unaff_s4;
  (*(code *)PTR_memset_006a99f4)(auStack_d1,0);
  if (p_surewarehk_Dsa_Sign == (code *)0x0) {
    ppiStack_124 = (int **)&_gp_1;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_f0 + -0x58a8))();
    }
    ppiStack_188 = (int **)0x75;
    pcVar19 = "e_sureware.c";
    puStack_f8 = (undefined4 *)0x404;
    uStack_1ac = 0x65;
    (**(code **)(puStack_f0 + -0x6eac))(SUREWARE_lib_error_code,0x65,0x75,"e_sureware.c");
  }
  else {
    uStack_1ac = dsaHndidx;
    unaff_s5 = (**(code **)(puStack_f0 + -0x5868))(pcVar18);
    if (unaff_s5 == 0) {
      ppiStack_124 = (int **)&_gp_1;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_f0 + -0x58a8))();
      }
      ppiStack_188 = (int **)&DAT_00000069;
      pcVar19 = "e_sureware.c";
      puStack_f8 = (undefined4 *)0x40a;
      uStack_1ac = 0x65;
      (**(code **)(puStack_f0 + -0x6eac))(SUREWARE_lib_error_code,0x65,0x69,"e_sureware.c");
    }
    else {
      ppiStack_124 = (int **)(**(code **)(puStack_f0 + -0x6684))();
      if (ppiStack_124 == (int **)0x0) {
        ppiStack_124 = (int **)&_gp_1;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (**(code **)(puStack_f0 + -0x58a8))();
        }
        ppiStack_188 = (int **)&DAT_00000041;
        pcVar19 = "e_sureware.c";
        puStack_f8 = (undefined4 *)0x40f;
        uStack_1ac = 0x65;
        (**(code **)(puStack_f0 + -0x6eac))(SUREWARE_lib_error_code,0x65,0x41,"e_sureware.c");
      }
      else {
        piVar5 = (int *)(**(code **)(puStack_f0 + -0x7c2c))();
        pcVar23 = *(code **)(puStack_f0 + -0x7c2c);
        *ppiStack_124 = piVar5;
        piVar5 = (int *)(*pcVar23)();
        ppiStack_124[1] = piVar5;
        if ((*ppiStack_124 == (int *)0x0) || (piVar5 == (int *)0x0)) {
LAB_005d6b4c:
          pcVar23 = *(code **)(puStack_f0 + -0x6688);
        }
        else {
          (**(code **)(puStack_f0 + -0x68bc))(*ppiStack_124,5);
          uStack_1ac = 5;
          (**(code **)(puStack_f0 + -0x68bc))(ppiStack_124[1]);
          if ((char *)(*ppiStack_124)[2] != &DAT_00000005) goto LAB_005d6b4c;
          unaff_s6 = ppiStack_124[1][2];
          pcVar23 = *(code **)(puStack_f0 + -0x6688);
          if (unaff_s6 == 5) {
            pcVar19 = (char *)**ppiStack_124;
            puStack_11c = &uStack_e4;
            puStack_f8 = (undefined4 *)*ppiStack_124[1];
            iStack_f4 = unaff_s5;
            ppiStack_188 = (int **)(*p_surewarehk_Dsa_Sign)(puStack_11c,param_1,iStack_118,pcVar19);
            uStack_1ac = 0x65;
            surewarehk_error_handling(puStack_11c);
            ppiVar12 = (int **)*ppiStack_124;
            ppiVar12[1] = (int *)&DAT_00000005;
            piVar5 = *ppiVar12;
            if (piVar5[4] == 0) {
              if (piVar5[3] == 0) {
                if (piVar5[2] == 0) {
                  if (piVar5[1] == 0) {
                    piVar5 = (int *)(uint)(*piVar5 != 0);
                  }
                  else {
                    piVar5 = (int *)&SUB_00000002;
                  }
                }
                else {
                  piVar5 = (int *)0x3;
                }
              }
              else {
                piVar5 = (int *)&SUB_00000004;
              }
            }
            else {
              piVar5 = (int *)&DAT_00000005;
            }
            ppiVar10 = (int **)ppiStack_124[1];
            ppiVar12[1] = piVar5;
            ppiVar10[1] = (int *)&DAT_00000005;
            piVar5 = *ppiVar10;
            if (piVar5[4] == 0) {
              if (piVar5[3] == 0) {
                if (piVar5[2] == 0) {
                  if (piVar5[1] == 0) {
                    ppiVar10[1] = (int *)(uint)(*piVar5 != 0);
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
        (*pcVar23)(ppiStack_124);
      }
    }
  }
  if (puStack_a4 == *(undefined4 **)puStack_120) {
    return (int ******)0x0;
  }
  pcStack_10c = surewarehk_rsa_sign;
  puVar13 = puStack_a4;
  (**(code **)(puStack_f0 + -0x5330))();
  puStack_1b8 = puStack_f8;
  puStack_1bc = PTR___stack_chk_guard_006a9ae8;
  iStack_12c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_15c = 0;
  uStack_158 = 0;
  uStack_154 = 0;
  uStack_150 = 0;
  uStack_14c = 0;
  uStack_148 = 0;
  uStack_144 = 0;
  uStack_140 = 0;
  uStack_13c = 0;
  uStack_138 = 0;
  uStack_134 = 0;
  uStack_130 = 0;
  piStack_16c = s_ENGINE_rsa_sign_00674460._0_4_;
  uStack_168 = s_ENGINE_rsa_sign_00674460._4_4_;
  uStack_164 = s_ENGINE_rsa_sign_00674460._8_4_;
  uStack_160 = s_ENGINE_rsa_sign_00674460._12_4_;
  ppiStack_1b4 = ppiStack_188;
  puStack_114 = param_1;
  iStack_110 = unaff_s5;
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    ppppppiStack_1c0 = (int ******)&_gp_1;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiStack_224 = (int ******)0x75;
    pcVar18 = "e_sureware.c";
    ppiStack_188 = (int **)0x3df;
    piStack_300 = (int *)&DAT_0000006f;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
    ppppppiVar4 = (int ******)0x0;
  }
  else {
    puVar6 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006a9534)(pcVar19,rsaHndidx);
    param_1 = puVar13;
    if (puVar6 == (undefined4 *)0x0) {
      ppppppiStack_1c0 = (int ******)&_gp_1;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      ppppppiStack_224 = (int ******)&DAT_00000069;
      pcVar18 = "e_sureware.c";
      ppiStack_188 = (int **)0x3e4;
      piStack_300 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
      ppppppiVar4 = (int ******)0x0;
    }
    else if (puStack_1b8 == (undefined4 *)0x1) {
      pcVar18 = (char *)&ppppppiStack_170;
      puStack_180 = puStack_1b8;
      ppppppiStack_1c0 = (int ******)(*p_surewarehk_Rsa_Sign)(&piStack_16c,puVar13,uStack_1ac);
      piStack_300 = (int *)&DAT_0000006f;
      ppppppiStack_224 = ppppppiStack_1c0;
      surewarehk_error_handling(&piStack_16c);
      ppppppiVar4 = ppppppiStack_1c0;
      ppiStack_1b4 = &piStack_16c;
      puStack_184 = puVar6;
      if (ppppppiStack_1c0 == (int ******)0x1) {
        ppppppiVar4 = ppppppiStack_170;
      }
    }
    else {
      ppppppiStack_1c0 = (int ******)&_gp_1;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      ppppppiStack_224 = (int ******)&DAT_0000006b;
      pcVar18 = "e_sureware.c";
      ppiStack_188 = (int **)0x3f1;
      piStack_300 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
      ppppppiVar4 = (int ******)0x0;
    }
  }
  if (iStack_12c == *(int *)puStack_1bc) {
    return ppppppiVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_264 = PTR___stack_chk_guard_006a9ae8;
  pcStack_2ec = "encrypt";
  ppiStack_220 = ppiStack_188;
  ppppppiStack_268 = &pppppiStack_218;
  puStack_21c = puStack_184;
  ppppppiStack_260 = apppppiStack_1f6;
  puStack_230 = &_gp;
  pppppiStack_228 = pppppiStack_17c;
  ppppppiStack_1c4 = *(int *******)PTR___stack_chk_guard_006a9ae8;
  puStack_1b0 = param_1;
  iStack_1a8 = unaff_s6;
  (*(code *)PTR_BN_init_006a857c)(ppppppiStack_268);
  ppppppiStack_2f4 = (int ******)&DAT_00000032;
  piVar5 = (int *)0x0;
  pppppiStack_204 = (int *****)DAT_0067430c;
  uStack_200 = DAT_00674310;
  puStack_1fc = DAT_00674314;
  uStack_1f8 = DAT_00674318;
  pcVar19 = (char *)DAT_00674314;
  (**(code **)(puStack_230 + -0x53ec))(ppppppiStack_260);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_005d72d4:
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_230 + -0x58a8))();
    }
    ppppppiStack_2f4 = (int ******)0x75;
    pcVar19 = "e_sureware.c";
    pppppiStack_240 = (int *****)0x435;
    piVar5 = (int *)&DAT_0000006b;
    (**(code **)(puStack_230 + -0x6eac))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
LAB_005d7108:
    piStack_300 = piVar5;
    ppppppiStack_270 = (int ******)0x0;
    ppppppiStack_25c = (int ******)pcVar18;
  }
  else {
    if (piStack_300 == (int *)0x0) goto LAB_005d7108;
    (**(code **)(puStack_230 + -0x68bc))(piStack_300,puStack_180[1]);
    piVar5 = (int *)piStack_300[2];
    if (piVar5 != (int *)puStack_180[1]) goto LAB_005d7108;
    pppppiStack_240 = *(int ******)pcVar18;
    pppppiStack_234 = (int *****)*piStack_300;
    pcVar19 = (char *)((int)*(int ******)((int)pcVar18 + 4) << 2);
    pppppiStack_238 = *ppppppiStack_224;
    iStack_23c = (int)ppppppiStack_224[1] << 2;
    ppppppiStack_224 = &pppppiStack_204;
    pcVar18 = (char *)(*p_surewarehk_Mod_Exp)
                                (&pppppiStack_204,(int)piVar5 << 2,*puStack_180,pcVar19);
    piVar5 = (int *)&DAT_0000006b;
    ppppppiStack_2f4 = (int ******)pcVar18;
    surewarehk_error_handling(ppppppiStack_224);
    if ((int ******)pcVar18 == (int ******)0x1) {
      iVar7 = puStack_180[1];
      piStack_300[1] = iVar7;
      if (0 < iVar7) {
        iVar8 = *piStack_300 + iVar7 * 4 + -8;
        do {
          if (*(int *)(iVar8 + 4) != 0) break;
          iVar7 = iVar7 + -1;
          iVar8 = iVar8 + -4;
        } while (iVar7 != 0);
        piStack_300[1] = iVar7;
      }
    }
    else if ((int ******)pcVar18 == (int ******)0x0) goto LAB_005d7108;
    ppppppiStack_2f4 = (int ******)&DAT_00000032;
    pppppiStack_204 = (int *****)DAT_0067430c;
    uStack_200 = DAT_00674310;
    puStack_1fc = DAT_00674314;
    uStack_1f8 = DAT_00674318;
    pcVar19 = (char *)DAT_00674314;
    (**(code **)(puStack_230 + -0x53ec))(ppppppiStack_260,0);
    if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_005d72d4;
    (**(code **)(puStack_230 + -0x68bc))(ppppppiStack_268,puStack_180[1]);
    ppppppiStack_25c = ppppppiStack_224;
    piVar5 = piStack_210;
    if (piStack_210 != (int *)puStack_180[1]) goto LAB_005d7108;
    pppppiStack_238 = (int *****)*ppiStack_220;
    iStack_23c = (int)ppiStack_220[1] << 2;
    pppppiStack_240 = (int *****)*puStack_21c;
    pcVar19 = (char *)(puStack_21c[1] << 2);
    pppppiStack_234 = pppppiStack_218;
    ppppppiStack_260 =
         (int ******)
         (*p_surewarehk_Mod_Exp)(ppppppiStack_224,(int)piStack_210 << 2,*puStack_180,pcVar19);
    piVar5 = (int *)&DAT_0000006b;
    ppppppiStack_2f4 = ppppppiStack_260;
    surewarehk_error_handling(ppppppiStack_25c);
    if (ppppppiStack_260 == (int ******)0x1) {
      iStack_214 = puStack_180[1];
      if (0 < iStack_214) {
        pppppiStack_218 = pppppiStack_218 + iStack_214 + -2;
        do {
          if (pppppiStack_218[1] != (int ****)0x0) break;
          iStack_214 = iStack_214 + -1;
          pppppiStack_218 = pppppiStack_218 + -1;
        } while (iStack_214 != 0);
      }
    }
    else {
      pcVar18 = (char *)ppppppiStack_25c;
      if (ppppppiStack_260 == (int ******)0x0) goto LAB_005d7108;
    }
    pppppiStack_240 = pppppiStack_228;
    ppppppiStack_2f4 = ppppppiStack_268;
    pcVar19 = (char *)puStack_180;
    iVar7 = (**(code **)(puStack_230 + -0x686c))
                      (piStack_300,piStack_300,ppppppiStack_268,puStack_180);
    ppppppiStack_270 = (int ******)(uint)(iVar7 != 0);
  }
  (**(code **)(puStack_230 + -0x7dc4))(ppppppiStack_268);
  if (ppppppiStack_1c4 == *(int *******)puStack_264) {
    return ppppppiStack_270;
  }
  pcStack_254 = surewarehk_rsa_priv_dec;
  ppppppiVar4 = ppppppiStack_1c4;
  (**(code **)(puStack_230 + -0x5330))();
  pppppiStack_2f8 = pppppiStack_240;
  puStack_2fc = PTR___stack_chk_guard_006a9ae8;
  puStack_26c = puStack_180;
  iStack_274 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_258 = "encrypt";
  puStack_2c0 = &_gp;
  uStack_2a0 = 0;
  uStack_29c = 0;
  uStack_298 = 0;
  uStack_294 = 0;
  uStack_290 = 0;
  uStack_28c = 0;
  uStack_288 = 0;
  uStack_284 = 0;
  uStack_280 = 0;
  uStack_27c = 0;
  uStack_278 = 0;
  iStack_2b4 = s_ENGINE_rsa_priv_dec_006744a0._0_4_;
  uStack_2b0 = s_ENGINE_rsa_priv_dec_006744a0._4_4_;
  uStack_2ac = s_ENGINE_rsa_priv_dec_006744a0._8_4_;
  uStack_2a8 = s_ENGINE_rsa_priv_dec_006744a0._12_4_;
  uStack_2a4 = s_ENGINE_rsa_priv_dec_006744a0._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiStack_2d0 = (int ******)0x38f;
    (**(code **)(puStack_2c0 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
    iVar7 = 0;
  }
  else {
    iVar7 = (*(code *)PTR_RSA_get_ex_data_006a9534)(pcVar19,rsaHndidx);
    if (iVar7 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_2c0 + -0x58a8))();
      }
      ppppppiStack_2d0 = (int ******)0x394;
      ppppppiVar16 = (int ******)&DAT_0000006e;
      ppppppiStack_304 = (int ******)0x0;
      (**(code **)(puStack_2c0 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d74cc;
    }
  }
  pcStack_2ec = (char *)0x1;
  ppppppiStack_2d0 = ppppppiStack_2f4;
  iStack_2cc = iVar7;
  if (pppppiStack_2f8 == (int *****)0x1) {
    pppppiStack_2c8 = pppppiStack_2f8;
    ppppppiStack_304 =
         (int ******)
         (*p_surewarehk_Rsa_Priv_Dec)(&iStack_2b4,ppppppiVar4,piStack_300,&ppppppiStack_2b8);
    ppppppiVar16 = (int ******)&DAT_0000006e;
    surewarehk_error_handling(&iStack_2b4,0x6e,ppppppiStack_304);
    piStack_300 = &iStack_2b4;
    if (ppppppiStack_304 == (int ******)0x1) {
      ppppppiStack_304 = ppppppiStack_2b8;
    }
    goto LAB_005d74cc;
  }
  pppppiStack_2c8 = (int *****)0x0;
  ppppppiStack_304 = (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_2b4,ppppppiVar4,piStack_300);
  ppppppiVar16 = (int ******)&DAT_0000006e;
  surewarehk_error_handling(&iStack_2b4,0x6e,ppppppiStack_304);
  piStack_300 = &iStack_2b4;
  if (ppppppiStack_304 != (int ******)0x1) goto LAB_005d74cc;
  pcStack_2ec = "encrypt";
  piStack_300 = (int *)(**(code **)(puStack_2c0 + -0x7dd8))(ppppppiStack_2b8,"e_sureware.c",0x3ac);
  if (piStack_300 == (int *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_2c0 + -0x58a8))();
    }
    ppppppiVar16 = (int ******)&DAT_0000006e;
    ppppppiStack_2d0 = (int ******)0x3ae;
    (**(code **)(puStack_2c0 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    piStack_300 = (int *)&_gp_1;
    goto LAB_005d74cc;
  }
  (**(code **)(puStack_2c0 + -0x52f4))(piStack_300,ppppppiStack_2f4,ppppppiStack_2b8);
  if (pppppiStack_2f8 == (int *****)0x3) {
    pcVar23 = *(code **)(puStack_2c0 + -0x66f8);
LAB_005d7738:
    ppppppiStack_2d0 = ppppppiStack_2b8;
    ppppppiStack_304 =
         (int ******)(*pcVar23)(ppppppiStack_2f4,ppppppiStack_2b8,piStack_300,ppppppiVar4);
LAB_005d76d8:
    pcVar23 = *(code **)(puStack_2c0 + -0x7d6c);
    if ((int)ppppppiStack_304 < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_2c0 + -0x58a8))();
      }
      ppppppiStack_2d0 = (int ******)0x3cb;
      (**(code **)(puStack_2c0 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d7630;
    }
  }
  else {
    if (pppppiStack_2f8 == (int *****)0x4) {
      pppppiStack_2c8 = (int *****)0x0;
      iStack_2cc = 0;
      ppppppiStack_2d0 = ppppppiStack_2b8;
      ppppppiStack_304 =
           (int ******)
           (**(code **)(puStack_2c0 + -0x66d0))(ppppppiStack_2f4,ppppppiStack_2b8,piStack_300);
      goto LAB_005d76d8;
    }
    bVar1 = pppppiStack_2f8 == (int *****)0x2;
    pppppiStack_2f8 = (int *****)&_gp_1;
    if (bVar1) {
      pcVar23 = *(code **)(puStack_2c0 + -0x66c8);
      goto LAB_005d7738;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_2c0 + -0x58a8))();
    }
    ppppppiStack_2d0 = (int ******)0x3c6;
    (**(code **)(puStack_2c0 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d7630:
    pppppiStack_2f8 = (int *****)&_gp_1;
    pcVar23 = *(code **)(puStack_2c0 + -0x7d6c);
  }
  (*pcVar23)(piStack_300,ppppppiStack_2b8);
  (**(code **)(puStack_2c0 + -0x7f58))(piStack_300);
  ppppppiVar16 = ppppppiStack_2b8;
LAB_005d74cc:
  if (iStack_274 == *(int *)puStack_2fc) {
    return ppppppiStack_304;
  }
  pcStack_2e4 = surewarehk_load_pubkey;
  iVar7 = iStack_274;
  (**(code **)(puStack_2c0 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_30c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppppiStack_2e8 = &DAT_0067430c;
  uStack_390 = 0;
  cStack_391 = '\0';
  uStack_38c = s_ENGINE_load_pubkey_006744e0._0_4_;
  uStack_388 = s_ENGINE_load_pubkey_006744e0._4_4_;
  uStack_384 = s_ENGINE_load_pubkey_006744e0._8_4_;
  uStack_380 = s_ENGINE_load_pubkey_006744e0._12_4_;
  uStack_37c = s_ENGINE_load_pubkey_006744e0._16_2_;
  cStack_37a = s_ENGINE_load_pubkey_006744e0[18];
  ppppppiStack_2f0 = ppppppiVar4;
  (*(code *)PTR_memset_006a99f4)(auStack_379,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiVar20 = (int ******)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
  }
  else {
    iVar8 = (*p_surewarehk_Info_Pubkey)(&uStack_38c,ppppppiVar16,&uStack_390,&cStack_391);
    uVar22 = uStack_390;
    if (iVar8 == 1) {
      ppppppiVar4 = (int ******)(int)cStack_391;
      uStack_34c = s_sureware_load_public_00674520._0_4_;
      uStack_348 = s_sureware_load_public_00674520._4_4_;
      uStack_344 = s_sureware_load_public_00674520._8_4_;
      uStack_340 = s_sureware_load_public_00674520._12_4_;
      uStack_33c = s_sureware_load_public_00674520._16_4_;
      cStack_338 = s_sureware_load_public_00674520[20];
      (*(code *)PTR_memset_006a99f4)(auStack_337,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        ppppppiVar20 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
      }
      else if (ppppppiVar4 == (int ******)0x1) {
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
          uVar21 = uVar22 >> 2;
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar7 + 0x14),uVar21);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar7 + 0x10),uVar21);
          if ((uVar21 == (*(undefined4 **)(iVar7 + 0x14))[2]) &&
             (uVar21 == (*(undefined4 **)(iVar7 + 0x10))[2])) {
            iVar8 = (*p_surewarehk_Load_Rsa_Pubkey)
                              (&uStack_34c,ppppppiVar16,uVar22,**(undefined4 **)(iVar7 + 0x10),
                               **(undefined4 **)(iVar7 + 0x14));
            surewarehk_error_handling(&uStack_34c,0x6a,iVar8);
            if (iVar8 == 1) {
              piVar5 = *(int **)(iVar7 + 0x14);
              piVar5[1] = uVar21;
              if (uVar21 == 0) {
                *(undefined4 *)(*(int *)(iVar7 + 0x10) + 4) = 0;
              }
              else {
                iVar8 = (uVar22 & 0xfffffffc) - 4;
                piVar14 = (int *)(*piVar5 + iVar8);
                uVar22 = uVar21;
                do {
                  uVar15 = uVar22 - 1;
                  if (*piVar14 != 0) break;
                  piVar14 = piVar14 + -1;
                  uVar22 = uVar15;
                } while (uVar15 != 0);
                piVar14 = *(int **)(iVar7 + 0x10);
                piVar5[1] = uVar22;
                piVar14[1] = uVar21;
                piVar5 = (int *)(*piVar14 + iVar8);
                do {
                  uVar22 = uVar21 - 1;
                  if (*piVar5 != 0) break;
                  piVar5 = piVar5 + -1;
                  uVar21 = uVar22;
                } while (uVar22 != 0);
                piVar14[1] = uVar21;
              }
              ppppppiVar20 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a7620)();
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
        ppppppiVar20 = (int ******)0x0;
        (*(code *)PTR_RSA_free_006a7600)(iVar7);
      }
      else if (ppppppiVar4 == (int ******)&SUB_00000002) {
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
          ppppppiVar20 = (int ******)(uVar22 >> 2);
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar7 + 0x18),ppppppiVar20);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar7 + 0xc),ppppppiVar20);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar7 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar7 + 0x14),ppppppiVar20);
          ppppppiVar4 = ppppppiVar20;
          if (((ppppppiVar20 == (int ******)(*(undefined4 **)(iVar7 + 0x18))[2]) &&
              (ppppppiVar20 == (int ******)(*(undefined4 **)(iVar7 + 0xc))[2])) &&
             (((*(undefined4 **)(iVar7 + 0x10))[2] == 5 &&
              (ppppppiVar20 == (int ******)(*(undefined4 **)(iVar7 + 0x14))[2])))) {
            iVar8 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_34c,ppppppiVar16,uVar22,**(undefined4 **)(iVar7 + 0x18),
                               **(undefined4 **)(iVar7 + 0xc),**(undefined4 **)(iVar7 + 0x10),
                               **(undefined4 **)(iVar7 + 0x14));
            surewarehk_error_handling(&uStack_34c,0x6a,iVar8);
            if (iVar8 == 1) {
              piVar5 = *(int **)(iVar7 + 0x18);
              piVar5[1] = (int)ppppppiVar20;
              if (ppppppiVar20 == (int ******)0x0) goto LAB_005d7f80;
              iVar8 = (uVar22 & 0xfffffffc) - 4;
              piVar14 = (int *)(*piVar5 + iVar8);
              ppppppiVar16 = ppppppiVar20;
              do {
                ppppppiVar17 = (int ******)((int)ppppppiVar16 + -1);
                if (*piVar14 != 0) break;
                piVar14 = piVar14 + -1;
                ppppppiVar16 = ppppppiVar17;
              } while (ppppppiVar17 != (int ******)0x0);
              piVar14 = *(int **)(iVar7 + 0xc);
              piVar5[1] = (int)ppppppiVar16;
              piVar14[1] = (int)ppppppiVar20;
              piVar5 = (int *)(*piVar14 + iVar8);
              ppppppiVar16 = ppppppiVar20;
              do {
                ppppppiVar17 = (int ******)((int)ppppppiVar16 + -1);
                if (*piVar5 != 0) break;
                piVar5 = piVar5 + -1;
                ppppppiVar16 = ppppppiVar17;
              } while (ppppppiVar17 != (int ******)0x0);
              piVar14[1] = (int)ppppppiVar16;
              goto LAB_005d7dc4;
            }
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
          }
        }
        ppppppiVar20 = (int ******)0x0;
        (*(code *)PTR_DSA_free_006a7530)(iVar7);
      }
      else {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        ppppppiVar20 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
      }
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      ppppppiVar20 = (int ******)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      (*(code *)PTR_ERR_add_error_data_006a813c)(1,&uStack_38c);
    }
  }
  do {
    if (iStack_30c == *(int *)puVar3) {
      return ppppppiVar20;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005d7f80:
    *(undefined4 *)(*(int *)(iVar7 + 0xc) + 4) = 0;
LAB_005d7dc4:
    piVar5 = *(int **)(iVar7 + 0x10);
    iVar11 = 5;
    piVar5[1] = 5;
    iVar8 = *piVar5 + 0xc;
    do {
      if (*(int *)(iVar8 + 4) != 0) break;
      iVar11 = iVar11 + -1;
      iVar8 = iVar8 + -4;
    } while (iVar11 != 0);
    piVar14 = *(int **)(iVar7 + 0x14);
    piVar5[1] = iVar11;
    piVar14[1] = (int)ppppppiVar20;
    if (0 < (int)ppppppiVar20) {
      iVar8 = *piVar14 + (int)ppppppiVar20 * 4 + -8;
      do {
        if (*(int *)(iVar8 + 4) != 0) break;
        ppppppiVar4 = (int ******)((int)ppppppiVar4 + -1);
        iVar8 = iVar8 + -4;
      } while (ppppppiVar4 != (int ******)0x0);
      piVar14[1] = (int)ppppppiVar4;
    }
    ppppppiVar20 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a7620)();
    uVar9 = 0x74;
LAB_005d7f4c:
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(ppppppiVar20,uVar9,iVar7);
  } while( true );
}

