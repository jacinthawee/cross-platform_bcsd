
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ****** surewarehk_rand_seed(undefined4 *param_1,undefined *param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int ******ppppppiVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
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
  undefined *unaff_s4;
  int unaff_s5;
  int unaff_s6;
  uint uVar22;
  code *pcVar23;
  char cStack_411;
  uint uStack_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 uStack_404;
  undefined4 uStack_400;
  undefined2 uStack_3fc;
  char cStack_3fa;
  undefined auStack_3f9 [45];
  undefined4 uStack_3cc;
  undefined4 uStack_3c8;
  undefined4 uStack_3c4;
  undefined4 uStack_3c0;
  undefined4 uStack_3bc;
  char cStack_3b8;
  undefined auStack_3b7 [43];
  int iStack_38c;
  int ******ppppppiStack_384;
  int *piStack_380;
  undefined *puStack_37c;
  int *****pppppiStack_378;
  int ******ppppppiStack_374;
  int ******ppppppiStack_370;
  char *pcStack_36c;
  int ****ppppiStack_368;
  code *pcStack_364;
  int ******ppppppiStack_350;
  int iStack_34c;
  int *****pppppiStack_348;
  undefined *puStack_340;
  int ******ppppppiStack_338;
  int iStack_334;
  undefined4 uStack_330;
  undefined4 uStack_32c;
  undefined4 uStack_328;
  undefined4 uStack_324;
  undefined4 uStack_320;
  undefined4 uStack_31c;
  undefined4 uStack_318;
  undefined4 uStack_314;
  undefined4 uStack_310;
  undefined4 uStack_30c;
  undefined4 uStack_308;
  undefined4 uStack_304;
  undefined4 uStack_300;
  undefined4 uStack_2fc;
  undefined4 uStack_2f8;
  int iStack_2f4;
  int ******ppppppiStack_2f0;
  undefined4 *puStack_2ec;
  int ******ppppppiStack_2e8;
  undefined *puStack_2e4;
  int ******ppppppiStack_2e0;
  int ******ppppppiStack_2dc;
  char *pcStack_2d8;
  code *pcStack_2d4;
  int *****pppppiStack_2c0;
  int iStack_2bc;
  int *****pppppiStack_2b8;
  int *****pppppiStack_2b4;
  undefined *puStack_2b0;
  int *****pppppiStack_2a8;
  int ******ppppppiStack_2a4;
  int **ppiStack_2a0;
  undefined4 *puStack_29c;
  int *****pppppiStack_298;
  int iStack_294;
  int *piStack_290;
  int *****pppppiStack_284;
  undefined4 uStack_280;
  undefined4 *puStack_27c;
  undefined2 uStack_278;
  int *****apppppiStack_276 [12];
  int ******ppppppiStack_244;
  int ******ppppppiStack_240;
  undefined *puStack_23c;
  undefined4 *puStack_238;
  int **ppiStack_234;
  undefined4 *puStack_230;
  undefined4 uStack_22c;
  int iStack_228;
  int **ppiStack_208;
  undefined4 *puStack_204;
  undefined4 *puStack_200;
  int *****pppppiStack_1fc;
  int ******ppppppiStack_1f0;
  int *piStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  undefined4 uStack_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  int iStack_1ac;
  int **ppiStack_1a4;
  undefined *puStack_1a0;
  undefined4 *puStack_19c;
  int iStack_198;
  undefined4 *puStack_194;
  int iStack_190;
  code *pcStack_18c;
  undefined4 *puStack_178;
  int iStack_174;
  undefined *puStack_170;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  char *pcStack_158;
  undefined2 uStack_154;
  undefined uStack_152;
  undefined auStack_151 [45];
  undefined4 *puStack_124;
  undefined *puStack_120;
  undefined *puStack_11c;
  undefined4 *puStack_118;
  undefined4 *puStack_114;
  undefined *puStack_110;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined2 uStack_cc;
  undefined auStack_ca [46];
  int iStack_9c;
  undefined *puStack_98;
  undefined4 *puStack_94;
  undefined4 *puStack_90;
  undefined *puStack_8c;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  char local_4c;
  undefined auStack_4b [47];
  int ******local_1c;
  
  puStack_98 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *******)PTR___stack_chk_guard_006a9ae8;
  local_5c = s_ENGINE_rand_seed_0067434c._0_4_;
  local_58 = s_ENGINE_rand_seed_0067434c._4_4_;
  local_54 = s_ENGINE_rand_seed_0067434c._8_4_;
  local_50 = s_ENGINE_rand_seed_0067434c._12_4_;
  local_4c = s_ENGINE_rand_seed_0067434c[16];
  (*(code *)PTR_memset_006a99f4)(auStack_4b,0,0x2f);
  if (p_surewarehk_Rand_Seed == (code *)0x0) {
    puStack_94 = (undefined4 *)&_gp_1;
    if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
      SUREWARE_lib_error_code = (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    puStack_114 = (undefined4 *)&DAT_0000006d;
    puStack_230 = SUREWARE_lib_error_code;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6d,0x75,"e_sureware.c");
  }
  else {
    puStack_94 = &local_5c;
    puStack_230 = puStack_94;
    puStack_114 = param_1;
    uVar4 = (*p_surewarehk_Rand_Seed)(puStack_94,param_1,param_2);
    switch(uVar4) {
    case 1:
      goto switchD_005d65e8_caseD_1;
    case 0xfffffffb:
      uVar4 = 0x6a;
      break;
    case 0xfffffffc:
      uVar4 = 0x67;
      break;
    case 0xfffffffd:
      uVar4 = 0x68;
      break;
    case 0xfffffffe:
      uVar4 = 0x66;
      break;
    default:
      uVar4 = 0x65;
    }
    param_1 = (undefined4 *)0x670000;
    puStack_114 = (undefined4 *)&DAT_0000006d;
    puStack_230 = (undefined4 *)0x26;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0x6d,uVar4,"e_sureware.c");
    if (local_5c._0_1_ != '\0') {
      param_2 = &_gp_1;
      puStack_230 = (undefined4 *)0x1;
      puStack_114 = puStack_94;
      (*(code *)PTR_ERR_add_error_data_006a813c)();
      if (logstream != 0) {
        (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x15,"e_sureware.c",0x286);
        uVar4 = (*(code *)PTR_strlen_006a9a24)(puStack_94);
        (*(code *)PTR_BIO_write_006a6e14)(logstream,puStack_94,uVar4);
        puStack_114 = (undefined4 *)&DAT_00000015;
        puStack_230 = (undefined4 *)&DAT_0000000a;
        (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x15,"e_sureware.c",0x288);
      }
    }
  }
switchD_005d65e8_caseD_1:
  ppppppiVar5 = *(int *******)puStack_98;
  if (local_1c == ppppppiVar5) {
    return ppppppiVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_11c = PTR___stack_chk_guard_006a9ae8;
  iStack_9c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_dc = s_ENGINE_rand_bytes_006743c4._0_4_;
  uStack_d8 = s_ENGINE_rand_bytes_006743c4._4_4_;
  uStack_d4 = s_ENGINE_rand_bytes_006743c4._8_4_;
  uStack_d0 = s_ENGINE_rand_bytes_006743c4._12_4_;
  uStack_cc = s_ENGINE_rand_bytes_006743c4._16_2_;
  puStack_90 = param_1;
  puStack_8c = param_2;
  (*(code *)PTR_memset_006a99f4)(auStack_ca,0,0x2e);
  if (p_surewarehk_Rand_Bytes == (code *)0x0) {
    puStack_120 = &_gp_1;
    if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
      SUREWARE_lib_error_code = (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    pcVar18 = (char *)0x75;
    puStack_230 = (undefined4 *)&DAT_0000006c;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6c,0x75,"e_sureware.c");
    ppppppiVar5 = (int ******)0x0;
  }
  else {
    param_1 = &uStack_dc;
    pcVar18 = (char *)puStack_114;
    puStack_120 = (undefined *)(*p_surewarehk_Rand_Bytes)(param_1,puStack_230,puStack_114);
    switch(puStack_120) {
    case (undefined *)0x1:
      ppppppiVar5 = (int ******)0x1;
      goto LAB_005d685c;
    case (undefined *)0xfffffffb:
      pcVar18 = &DAT_0000006a;
      break;
    case (undefined *)0xfffffffc:
      pcVar18 = (char *)0x67;
      break;
    case (undefined *)0xfffffffd:
      pcVar18 = &DAT_00000068;
      break;
    case (undefined *)0xfffffffe:
      pcVar18 = (char *)0x66;
      break;
    default:
      pcVar18 = &DAT_00000065;
    }
    puStack_114 = (undefined4 *)0x670000;
    puStack_230 = (undefined4 *)&DAT_0000006c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0x6c,pcVar18,"e_sureware.c");
    if (uStack_dc._0_1_ != '\0') {
      unaff_s4 = &_gp_1;
      puStack_230 = param_1;
      (*(code *)PTR_ERR_add_error_data_006a813c)(1);
      if (logstream != 0) {
        puStack_120 = (undefined *)((uint)puStack_120 ^ 1);
        (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x15,"e_sureware.c",0x286);
        uVar4 = (*(code *)PTR_strlen_006a9a24)(param_1);
        (*(code *)PTR_BIO_write_006a6e14)(logstream,param_1,uVar4);
        pcVar18 = "e_sureware.c";
        puStack_230 = (undefined4 *)&DAT_00000015;
        (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x15,"e_sureware.c",0x288);
        ppppppiVar5 = (int ******)(uint)(puStack_120 == (undefined *)0x0);
        goto LAB_005d685c;
      }
    }
    puStack_120 = (undefined *)((uint)puStack_120 ^ 1);
    ppppppiVar5 = (int ******)(uint)(puStack_120 == (undefined *)0x0);
  }
LAB_005d685c:
  if (iStack_9c == *(int *)puStack_11c) {
    return ppppppiVar5;
  }
  iStack_198 = iStack_9c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1a0 = PTR___stack_chk_guard_006a9ae8;
  puStack_19c = (undefined4 *)&_gp_1;
  puStack_124 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  puStack_170 = &_gp;
  ppiStack_208 = (int **)&DAT_0000002d;
  uStack_164 = DAT_00674420;
  uStack_160 = DAT_00674424;
  uStack_15c = DAT_00674428;
  pcStack_158 = DAT_0067442c;
  uStack_154 = DAT_00674430;
  uStack_152 = DAT_00674432;
  pcVar19 = DAT_0067442c;
  puStack_118 = param_1;
  puStack_110 = unaff_s4;
  (*(code *)PTR_memset_006a99f4)(auStack_151,0);
  if (p_surewarehk_Dsa_Sign == (code *)0x0) {
    ppiStack_1a4 = (int **)&_gp_1;
    if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
      SUREWARE_lib_error_code = (undefined4 *)(**(code **)(puStack_170 + -0x58a8))();
    }
    ppiStack_208 = (int **)0x75;
    pcVar19 = "e_sureware.c";
    puStack_178 = (undefined4 *)0x404;
    uStack_22c = 0x65;
    (**(code **)(puStack_170 + -0x6eac))(SUREWARE_lib_error_code,0x65,0x75,"e_sureware.c");
  }
  else {
    uStack_22c = dsaHndidx;
    unaff_s5 = (**(code **)(puStack_170 + -0x5868))(pcVar18);
    if (unaff_s5 == 0) {
      ppiStack_1a4 = (int **)&_gp_1;
      if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
        SUREWARE_lib_error_code = (undefined4 *)(**(code **)(puStack_170 + -0x58a8))();
      }
      ppiStack_208 = (int **)&DAT_00000069;
      pcVar19 = "e_sureware.c";
      puStack_178 = (undefined4 *)0x40a;
      uStack_22c = 0x65;
      (**(code **)(puStack_170 + -0x6eac))(SUREWARE_lib_error_code,0x65,0x69,"e_sureware.c");
    }
    else {
      ppiStack_1a4 = (int **)(**(code **)(puStack_170 + -0x6684))();
      if (ppiStack_1a4 == (int **)0x0) {
        ppiStack_1a4 = (int **)&_gp_1;
        if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
          SUREWARE_lib_error_code = (undefined4 *)(**(code **)(puStack_170 + -0x58a8))();
        }
        ppiStack_208 = (int **)&DAT_00000041;
        pcVar19 = "e_sureware.c";
        puStack_178 = (undefined4 *)0x40f;
        uStack_22c = 0x65;
        (**(code **)(puStack_170 + -0x6eac))(SUREWARE_lib_error_code,0x65,0x41,"e_sureware.c");
      }
      else {
        piVar6 = (int *)(**(code **)(puStack_170 + -0x7c2c))();
        pcVar23 = *(code **)(puStack_170 + -0x7c2c);
        *ppiStack_1a4 = piVar6;
        piVar6 = (int *)(*pcVar23)();
        ppiStack_1a4[1] = piVar6;
        if ((*ppiStack_1a4 == (int *)0x0) || (piVar6 == (int *)0x0)) {
LAB_005d6b4c:
          pcVar23 = *(code **)(puStack_170 + -0x6688);
        }
        else {
          (**(code **)(puStack_170 + -0x68bc))(*ppiStack_1a4,5);
          uStack_22c = 5;
          (**(code **)(puStack_170 + -0x68bc))(ppiStack_1a4[1]);
          if ((char *)(*ppiStack_1a4)[2] != &DAT_00000005) goto LAB_005d6b4c;
          unaff_s6 = ppiStack_1a4[1][2];
          pcVar23 = *(code **)(puStack_170 + -0x6688);
          if (unaff_s6 == 5) {
            pcVar19 = (char *)**ppiStack_1a4;
            puStack_19c = &uStack_164;
            puStack_178 = (undefined4 *)*ppiStack_1a4[1];
            iStack_174 = unaff_s5;
            ppiStack_208 = (int **)(*p_surewarehk_Dsa_Sign)
                                             (puStack_19c,puStack_230,iStack_198,pcVar19);
            uStack_22c = 0x65;
            surewarehk_error_handling(puStack_19c);
            ppiVar12 = (int **)*ppiStack_1a4;
            ppiVar12[1] = (int *)&DAT_00000005;
            piVar6 = *ppiVar12;
            if (piVar6[4] == 0) {
              if (piVar6[3] == 0) {
                if (piVar6[2] == 0) {
                  if (piVar6[1] == 0) {
                    piVar6 = (int *)(uint)(*piVar6 != 0);
                  }
                  else {
                    piVar6 = (int *)&SUB_00000002;
                  }
                }
                else {
                  piVar6 = (int *)0x3;
                }
              }
              else {
                piVar6 = (int *)&SUB_00000004;
              }
            }
            else {
              piVar6 = (int *)&DAT_00000005;
            }
            ppiVar10 = (int **)ppiStack_1a4[1];
            ppiVar12[1] = piVar6;
            ppiVar10[1] = (int *)&DAT_00000005;
            piVar6 = *ppiVar10;
            if (piVar6[4] == 0) {
              if (piVar6[3] == 0) {
                if (piVar6[2] == 0) {
                  if (piVar6[1] == 0) {
                    ppiVar10[1] = (int *)(uint)(*piVar6 != 0);
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
        (*pcVar23)(ppiStack_1a4);
      }
    }
  }
  if (puStack_124 == *(undefined4 **)puStack_1a0) {
    return (int ******)0x0;
  }
  pcStack_18c = surewarehk_rsa_sign;
  puVar13 = puStack_124;
  (**(code **)(puStack_170 + -0x5330))();
  puStack_238 = puStack_178;
  puStack_23c = PTR___stack_chk_guard_006a9ae8;
  iStack_1ac = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_1dc = 0;
  uStack_1d8 = 0;
  uStack_1d4 = 0;
  uStack_1d0 = 0;
  uStack_1cc = 0;
  uStack_1c8 = 0;
  uStack_1c4 = 0;
  uStack_1c0 = 0;
  uStack_1bc = 0;
  uStack_1b8 = 0;
  uStack_1b4 = 0;
  uStack_1b0 = 0;
  piStack_1ec = s_ENGINE_rsa_sign_00674460._0_4_;
  uStack_1e8 = s_ENGINE_rsa_sign_00674460._4_4_;
  uStack_1e4 = s_ENGINE_rsa_sign_00674460._8_4_;
  uStack_1e0 = s_ENGINE_rsa_sign_00674460._12_4_;
  ppiStack_234 = ppiStack_208;
  puStack_194 = puStack_230;
  iStack_190 = unaff_s5;
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    ppppppiStack_240 = (int ******)&_gp_1;
    if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
      SUREWARE_lib_error_code = (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiStack_2a4 = (int ******)0x75;
    pcVar18 = "e_sureware.c";
    ppiStack_208 = (int **)0x3df;
    piStack_380 = (int *)&DAT_0000006f;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
    ppppppiVar5 = (int ******)0x0;
  }
  else {
    puVar7 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006a9534)(pcVar19,rsaHndidx);
    puStack_230 = puVar13;
    if (puVar7 == (undefined4 *)0x0) {
      ppppppiStack_240 = (int ******)&_gp_1;
      if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
        SUREWARE_lib_error_code = (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)()
        ;
      }
      ppppppiStack_2a4 = (int ******)&DAT_00000069;
      pcVar18 = "e_sureware.c";
      ppiStack_208 = (int **)0x3e4;
      piStack_380 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
      ppppppiVar5 = (int ******)0x0;
    }
    else if (puStack_238 == (undefined4 *)0x1) {
      pcVar18 = (char *)&ppppppiStack_1f0;
      puStack_200 = puStack_238;
      ppppppiStack_240 = (int ******)(*p_surewarehk_Rsa_Sign)(&piStack_1ec,puVar13,uStack_22c);
      piStack_380 = (int *)&DAT_0000006f;
      ppppppiStack_2a4 = ppppppiStack_240;
      surewarehk_error_handling(&piStack_1ec);
      ppppppiVar5 = ppppppiStack_240;
      ppiStack_234 = &piStack_1ec;
      puStack_204 = puVar7;
      if (ppppppiStack_240 == (int ******)0x1) {
        ppppppiVar5 = ppppppiStack_1f0;
      }
    }
    else {
      ppppppiStack_240 = (int ******)&_gp_1;
      if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
        SUREWARE_lib_error_code = (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)()
        ;
      }
      ppppppiStack_2a4 = (int ******)&DAT_0000006b;
      pcVar18 = "e_sureware.c";
      ppiStack_208 = (int **)0x3f1;
      piStack_380 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
      ppppppiVar5 = (int ******)0x0;
    }
  }
  if (iStack_1ac == *(int *)puStack_23c) {
    return ppppppiVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_2e4 = PTR___stack_chk_guard_006a9ae8;
  pcStack_36c = "encrypt";
  ppiStack_2a0 = ppiStack_208;
  ppppppiStack_2e8 = &pppppiStack_298;
  puStack_29c = puStack_204;
  ppppppiStack_2e0 = apppppiStack_276;
  puStack_2b0 = &_gp;
  pppppiStack_2a8 = pppppiStack_1fc;
  ppppppiStack_244 = *(int *******)PTR___stack_chk_guard_006a9ae8;
  iStack_228 = unaff_s6;
  (*(code *)PTR_BN_init_006a857c)(ppppppiStack_2e8);
  ppppppiStack_374 = (int ******)&DAT_00000032;
  piVar6 = (int *)0x0;
  pppppiStack_284 = (int *****)DAT_0067430c;
  uStack_280 = DAT_00674310;
  puStack_27c = DAT_00674314;
  uStack_278 = DAT_00674318;
  pcVar19 = (char *)DAT_00674314;
  (**(code **)(puStack_2b0 + -0x53ec))(ppppppiStack_2e0);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_005d72d4:
    if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
      SUREWARE_lib_error_code = (undefined4 *)(**(code **)(puStack_2b0 + -0x58a8))();
    }
    ppppppiStack_374 = (int ******)0x75;
    pcVar19 = "e_sureware.c";
    pppppiStack_2c0 = (int *****)0x435;
    piVar6 = (int *)&DAT_0000006b;
    (**(code **)(puStack_2b0 + -0x6eac))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
LAB_005d7108:
    piStack_380 = piVar6;
    ppppppiStack_2f0 = (int ******)0x0;
    ppppppiStack_2dc = (int ******)pcVar18;
  }
  else {
    if (piStack_380 == (int *)0x0) goto LAB_005d7108;
    (**(code **)(puStack_2b0 + -0x68bc))(piStack_380,puStack_200[1]);
    piVar6 = (int *)piStack_380[2];
    if (piVar6 != (int *)puStack_200[1]) goto LAB_005d7108;
    pppppiStack_2c0 = *(int ******)pcVar18;
    pppppiStack_2b4 = (int *****)*piStack_380;
    pcVar19 = (char *)((int)*(int ******)((int)pcVar18 + 4) << 2);
    pppppiStack_2b8 = *ppppppiStack_2a4;
    iStack_2bc = (int)ppppppiStack_2a4[1] << 2;
    ppppppiStack_2a4 = &pppppiStack_284;
    pcVar18 = (char *)(*p_surewarehk_Mod_Exp)
                                (&pppppiStack_284,(int)piVar6 << 2,*puStack_200,pcVar19);
    piVar6 = (int *)&DAT_0000006b;
    ppppppiStack_374 = (int ******)pcVar18;
    surewarehk_error_handling(ppppppiStack_2a4);
    if ((int ******)pcVar18 == (int ******)0x1) {
      iVar8 = puStack_200[1];
      piStack_380[1] = iVar8;
      if (0 < iVar8) {
        iVar9 = *piStack_380 + iVar8 * 4 + -8;
        do {
          if (*(int *)(iVar9 + 4) != 0) break;
          iVar8 = iVar8 + -1;
          iVar9 = iVar9 + -4;
        } while (iVar8 != 0);
        piStack_380[1] = iVar8;
      }
    }
    else if ((int ******)pcVar18 == (int ******)0x0) goto LAB_005d7108;
    ppppppiStack_374 = (int ******)&DAT_00000032;
    pppppiStack_284 = (int *****)DAT_0067430c;
    uStack_280 = DAT_00674310;
    puStack_27c = DAT_00674314;
    uStack_278 = DAT_00674318;
    pcVar19 = (char *)DAT_00674314;
    (**(code **)(puStack_2b0 + -0x53ec))(ppppppiStack_2e0,0);
    if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_005d72d4;
    (**(code **)(puStack_2b0 + -0x68bc))(ppppppiStack_2e8,puStack_200[1]);
    ppppppiStack_2dc = ppppppiStack_2a4;
    piVar6 = piStack_290;
    if (piStack_290 != (int *)puStack_200[1]) goto LAB_005d7108;
    pppppiStack_2b8 = (int *****)*ppiStack_2a0;
    iStack_2bc = (int)ppiStack_2a0[1] << 2;
    pppppiStack_2c0 = (int *****)*puStack_29c;
    pcVar19 = (char *)(puStack_29c[1] << 2);
    pppppiStack_2b4 = pppppiStack_298;
    ppppppiStack_2e0 =
         (int ******)
         (*p_surewarehk_Mod_Exp)(ppppppiStack_2a4,(int)piStack_290 << 2,*puStack_200,pcVar19);
    piVar6 = (int *)&DAT_0000006b;
    ppppppiStack_374 = ppppppiStack_2e0;
    surewarehk_error_handling(ppppppiStack_2dc);
    if (ppppppiStack_2e0 == (int ******)0x1) {
      iStack_294 = puStack_200[1];
      if (0 < iStack_294) {
        pppppiStack_298 = pppppiStack_298 + iStack_294 + -2;
        do {
          if (pppppiStack_298[1] != (int ****)0x0) break;
          iStack_294 = iStack_294 + -1;
          pppppiStack_298 = pppppiStack_298 + -1;
        } while (iStack_294 != 0);
      }
    }
    else {
      pcVar18 = (char *)ppppppiStack_2dc;
      if (ppppppiStack_2e0 == (int ******)0x0) goto LAB_005d7108;
    }
    pppppiStack_2c0 = pppppiStack_2a8;
    ppppppiStack_374 = ppppppiStack_2e8;
    pcVar19 = (char *)puStack_200;
    iVar8 = (**(code **)(puStack_2b0 + -0x686c))
                      (piStack_380,piStack_380,ppppppiStack_2e8,puStack_200);
    ppppppiStack_2f0 = (int ******)(uint)(iVar8 != 0);
  }
  (**(code **)(puStack_2b0 + -0x7dc4))(ppppppiStack_2e8);
  if (ppppppiStack_244 == *(int *******)puStack_2e4) {
    return ppppppiStack_2f0;
  }
  pcStack_2d4 = surewarehk_rsa_priv_dec;
  ppppppiVar5 = ppppppiStack_244;
  (**(code **)(puStack_2b0 + -0x5330))();
  pppppiStack_378 = pppppiStack_2c0;
  puStack_37c = PTR___stack_chk_guard_006a9ae8;
  puStack_2ec = puStack_200;
  iStack_2f4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_2d8 = "encrypt";
  puStack_340 = &_gp;
  uStack_320 = 0;
  uStack_31c = 0;
  uStack_318 = 0;
  uStack_314 = 0;
  uStack_310 = 0;
  uStack_30c = 0;
  uStack_308 = 0;
  uStack_304 = 0;
  uStack_300 = 0;
  uStack_2fc = 0;
  uStack_2f8 = 0;
  iStack_334 = s_ENGINE_rsa_priv_dec_006744a0._0_4_;
  uStack_330 = s_ENGINE_rsa_priv_dec_006744a0._4_4_;
  uStack_32c = s_ENGINE_rsa_priv_dec_006744a0._8_4_;
  uStack_328 = s_ENGINE_rsa_priv_dec_006744a0._12_4_;
  uStack_324 = s_ENGINE_rsa_priv_dec_006744a0._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
      SUREWARE_lib_error_code = (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiStack_350 = (int ******)0x38f;
    (**(code **)(puStack_340 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
    iVar8 = 0;
  }
  else {
    iVar8 = (*(code *)PTR_RSA_get_ex_data_006a9534)(pcVar19,rsaHndidx);
    if (iVar8 == 0) {
      if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
        SUREWARE_lib_error_code = (undefined4 *)(**(code **)(puStack_340 + -0x58a8))();
      }
      ppppppiStack_350 = (int ******)0x394;
      ppppppiVar16 = (int ******)&DAT_0000006e;
      ppppppiStack_384 = (int ******)0x0;
      (**(code **)(puStack_340 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d74cc;
    }
  }
  pcStack_36c = (char *)0x1;
  ppppppiStack_350 = ppppppiStack_374;
  iStack_34c = iVar8;
  if (pppppiStack_378 == (int *****)0x1) {
    pppppiStack_348 = pppppiStack_378;
    ppppppiStack_384 =
         (int ******)
         (*p_surewarehk_Rsa_Priv_Dec)(&iStack_334,ppppppiVar5,piStack_380,&ppppppiStack_338);
    ppppppiVar16 = (int ******)&DAT_0000006e;
    surewarehk_error_handling(&iStack_334,0x6e,ppppppiStack_384);
    piStack_380 = &iStack_334;
    if (ppppppiStack_384 == (int ******)0x1) {
      ppppppiStack_384 = ppppppiStack_338;
    }
    goto LAB_005d74cc;
  }
  pppppiStack_348 = (int *****)0x0;
  ppppppiStack_384 = (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_334,ppppppiVar5,piStack_380);
  ppppppiVar16 = (int ******)&DAT_0000006e;
  surewarehk_error_handling(&iStack_334,0x6e,ppppppiStack_384);
  piStack_380 = &iStack_334;
  if (ppppppiStack_384 != (int ******)0x1) goto LAB_005d74cc;
  pcStack_36c = "encrypt";
  piStack_380 = (int *)(**(code **)(puStack_340 + -0x7dd8))(ppppppiStack_338,"e_sureware.c",0x3ac);
  if (piStack_380 == (int *)0x0) {
    if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
      SUREWARE_lib_error_code = (undefined4 *)(**(code **)(puStack_340 + -0x58a8))();
    }
    ppppppiVar16 = (int ******)&DAT_0000006e;
    ppppppiStack_350 = (int ******)0x3ae;
    (**(code **)(puStack_340 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    piStack_380 = (int *)&_gp_1;
    goto LAB_005d74cc;
  }
  (**(code **)(puStack_340 + -0x52f4))(piStack_380,ppppppiStack_374,ppppppiStack_338);
  if (pppppiStack_378 == (int *****)0x3) {
    pcVar23 = *(code **)(puStack_340 + -0x66f8);
LAB_005d7738:
    ppppppiStack_350 = ppppppiStack_338;
    ppppppiStack_384 =
         (int ******)(*pcVar23)(ppppppiStack_374,ppppppiStack_338,piStack_380,ppppppiVar5);
LAB_005d76d8:
    pcVar23 = *(code **)(puStack_340 + -0x7d6c);
    if ((int)ppppppiStack_384 < 0) {
      if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
        SUREWARE_lib_error_code = (undefined4 *)(**(code **)(puStack_340 + -0x58a8))();
      }
      ppppppiStack_350 = (int ******)0x3cb;
      (**(code **)(puStack_340 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d7630;
    }
  }
  else {
    if (pppppiStack_378 == (int *****)0x4) {
      pppppiStack_348 = (int *****)0x0;
      iStack_34c = 0;
      ppppppiStack_350 = ppppppiStack_338;
      ppppppiStack_384 =
           (int ******)
           (**(code **)(puStack_340 + -0x66d0))(ppppppiStack_374,ppppppiStack_338,piStack_380);
      goto LAB_005d76d8;
    }
    bVar1 = pppppiStack_378 == (int *****)0x2;
    pppppiStack_378 = (int *****)&_gp_1;
    if (bVar1) {
      pcVar23 = *(code **)(puStack_340 + -0x66c8);
      goto LAB_005d7738;
    }
    if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
      SUREWARE_lib_error_code = (undefined4 *)(**(code **)(puStack_340 + -0x58a8))();
    }
    ppppppiStack_350 = (int ******)0x3c6;
    (**(code **)(puStack_340 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d7630:
    pppppiStack_378 = (int *****)&_gp_1;
    pcVar23 = *(code **)(puStack_340 + -0x7d6c);
  }
  (*pcVar23)(piStack_380,ppppppiStack_338);
  (**(code **)(puStack_340 + -0x7f58))(piStack_380);
  ppppppiVar16 = ppppppiStack_338;
LAB_005d74cc:
  if (iStack_2f4 == *(int *)puStack_37c) {
    return ppppppiStack_384;
  }
  pcStack_364 = surewarehk_load_pubkey;
  iVar8 = iStack_2f4;
  (**(code **)(puStack_340 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_38c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppppiStack_368 = &DAT_0067430c;
  uStack_410 = 0;
  cStack_411 = '\0';
  uStack_40c = s_ENGINE_load_pubkey_006744e0._0_4_;
  uStack_408 = s_ENGINE_load_pubkey_006744e0._4_4_;
  uStack_404 = s_ENGINE_load_pubkey_006744e0._8_4_;
  uStack_400 = s_ENGINE_load_pubkey_006744e0._12_4_;
  uStack_3fc = s_ENGINE_load_pubkey_006744e0._16_2_;
  cStack_3fa = s_ENGINE_load_pubkey_006744e0[18];
  ppppppiStack_370 = ppppppiVar5;
  (*(code *)PTR_memset_006a99f4)(auStack_3f9,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
      SUREWARE_lib_error_code = (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiVar20 = (int ******)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
  }
  else {
    iVar9 = (*p_surewarehk_Info_Pubkey)(&uStack_40c,ppppppiVar16,&uStack_410,&cStack_411);
    uVar22 = uStack_410;
    if (iVar9 == 1) {
      ppppppiVar5 = (int ******)(int)cStack_411;
      uStack_3cc = s_sureware_load_public_00674520._0_4_;
      uStack_3c8 = s_sureware_load_public_00674520._4_4_;
      uStack_3c4 = s_sureware_load_public_00674520._8_4_;
      uStack_3c0 = s_sureware_load_public_00674520._12_4_;
      uStack_3bc = s_sureware_load_public_00674520._16_4_;
      cStack_3b8 = s_sureware_load_public_00674520[20];
      (*(code *)PTR_memset_006a99f4)(auStack_3b7,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
          SUREWARE_lib_error_code =
               (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        ppppppiVar20 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
      }
      else if (ppppppiVar5 == (int ******)0x1) {
        iVar8 = (*(code *)PTR_RSA_new_method_006a772c)(iVar8);
        (*(code *)PTR_RSA_set_ex_data_006a953c)(iVar8,rsaHndidx,0);
        puVar2 = PTR_BN_new_006a71b4;
        *(uint *)(iVar8 + 0x3c) = *(uint *)(iVar8 + 0x3c) | 0x20;
        uVar4 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar8 + 0x14) = uVar4;
        iVar9 = (*(code *)puVar2)();
        *(int *)(iVar8 + 0x10) = iVar9;
        if ((*(int *)(iVar8 + 0x14) != 0) && (iVar9 != 0)) {
          uVar21 = uVar22 >> 2;
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar8 + 0x14),uVar21);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar8 + 0x10),uVar21);
          if ((uVar21 == (*(undefined4 **)(iVar8 + 0x14))[2]) &&
             (uVar21 == (*(undefined4 **)(iVar8 + 0x10))[2])) {
            iVar9 = (*p_surewarehk_Load_Rsa_Pubkey)
                              (&uStack_3cc,ppppppiVar16,uVar22,**(undefined4 **)(iVar8 + 0x10),
                               **(undefined4 **)(iVar8 + 0x14));
            surewarehk_error_handling(&uStack_3cc,0x6a,iVar9);
            if (iVar9 == 1) {
              piVar6 = *(int **)(iVar8 + 0x14);
              piVar6[1] = uVar21;
              if (uVar21 == 0) {
                *(undefined4 *)(*(int *)(iVar8 + 0x10) + 4) = 0;
              }
              else {
                iVar9 = (uVar22 & 0xfffffffc) - 4;
                piVar14 = (int *)(*piVar6 + iVar9);
                uVar22 = uVar21;
                do {
                  uVar15 = uVar22 - 1;
                  if (*piVar14 != 0) break;
                  piVar14 = piVar14 + -1;
                  uVar22 = uVar15;
                } while (uVar15 != 0);
                piVar14 = *(int **)(iVar8 + 0x10);
                piVar6[1] = uVar22;
                piVar14[1] = uVar21;
                piVar6 = (int *)(*piVar14 + iVar9);
                do {
                  uVar22 = uVar21 - 1;
                  if (*piVar6 != 0) break;
                  piVar6 = piVar6 + -1;
                  uVar21 = uVar22;
                } while (uVar22 != 0);
                piVar14[1] = uVar21;
              }
              ppppppiVar20 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a7620)();
              uVar4 = 6;
              goto LAB_005d7f4c;
            }
            if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
              SUREWARE_lib_error_code =
                   (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            (*(code *)PTR_ERR_put_error_006a7f34)
                      (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2d8);
          }
        }
        ppppppiVar20 = (int ******)0x0;
        (*(code *)PTR_RSA_free_006a7600)(iVar8);
      }
      else if (ppppppiVar5 == (int ******)&SUB_00000002) {
        iVar8 = (*(code *)PTR_DSA_new_method_006a957c)(iVar8);
        (*(code *)PTR_DSA_set_ex_data_006a9580)(iVar8,dsaHndidx,0);
        uVar4 = (*(code *)PTR_BN_new_006a71b4)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar8 + 0x18) = uVar4;
        uVar4 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar8 + 0xc) = uVar4;
        uVar4 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar8 + 0x10) = uVar4;
        iVar9 = (*(code *)puVar2)();
        *(int *)(iVar8 + 0x14) = iVar9;
        if ((((*(int *)(iVar8 + 0x18) != 0) && (*(int *)(iVar8 + 0xc) != 0)) &&
            (*(int *)(iVar8 + 0x10) != 0)) && (iVar9 != 0)) {
          ppppppiVar20 = (int ******)(uVar22 >> 2);
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar8 + 0x18),ppppppiVar20);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar8 + 0xc),ppppppiVar20);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar8 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar8 + 0x14),ppppppiVar20);
          ppppppiVar5 = ppppppiVar20;
          if (((ppppppiVar20 == (int ******)(*(undefined4 **)(iVar8 + 0x18))[2]) &&
              (ppppppiVar20 == (int ******)(*(undefined4 **)(iVar8 + 0xc))[2])) &&
             (((*(undefined4 **)(iVar8 + 0x10))[2] == 5 &&
              (ppppppiVar20 == (int ******)(*(undefined4 **)(iVar8 + 0x14))[2])))) {
            iVar9 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_3cc,ppppppiVar16,uVar22,**(undefined4 **)(iVar8 + 0x18),
                               **(undefined4 **)(iVar8 + 0xc),**(undefined4 **)(iVar8 + 0x10),
                               **(undefined4 **)(iVar8 + 0x14));
            surewarehk_error_handling(&uStack_3cc,0x6a,iVar9);
            if (iVar9 == 1) {
              piVar6 = *(int **)(iVar8 + 0x18);
              piVar6[1] = (int)ppppppiVar20;
              if (ppppppiVar20 == (int ******)0x0) goto LAB_005d7f80;
              iVar9 = (uVar22 & 0xfffffffc) - 4;
              piVar14 = (int *)(*piVar6 + iVar9);
              ppppppiVar16 = ppppppiVar20;
              do {
                ppppppiVar17 = (int ******)((int)ppppppiVar16 + -1);
                if (*piVar14 != 0) break;
                piVar14 = piVar14 + -1;
                ppppppiVar16 = ppppppiVar17;
              } while (ppppppiVar17 != (int ******)0x0);
              piVar14 = *(int **)(iVar8 + 0xc);
              piVar6[1] = (int)ppppppiVar16;
              piVar14[1] = (int)ppppppiVar20;
              piVar6 = (int *)(*piVar14 + iVar9);
              ppppppiVar16 = ppppppiVar20;
              do {
                ppppppiVar17 = (int ******)((int)ppppppiVar16 + -1);
                if (*piVar6 != 0) break;
                piVar6 = piVar6 + -1;
                ppppppiVar16 = ppppppiVar17;
              } while (ppppppiVar17 != (int ******)0x0);
              piVar14[1] = (int)ppppppiVar16;
              goto LAB_005d7dc4;
            }
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
          }
        }
        ppppppiVar20 = (int ******)0x0;
        (*(code *)PTR_DSA_free_006a7530)(iVar8);
      }
      else {
        if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
          SUREWARE_lib_error_code =
               (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        ppppppiVar20 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
      }
    }
    else {
      if (SUREWARE_lib_error_code == (undefined4 *)0x0) {
        SUREWARE_lib_error_code = (undefined4 *)(*(code *)PTR_ERR_get_next_error_library_006a9538)()
        ;
      }
      ppppppiVar20 = (int ******)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      (*(code *)PTR_ERR_add_error_data_006a813c)(1,&uStack_40c);
    }
  }
  do {
    if (iStack_38c == *(int *)puVar3) {
      return ppppppiVar20;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005d7f80:
    *(undefined4 *)(*(int *)(iVar8 + 0xc) + 4) = 0;
LAB_005d7dc4:
    piVar6 = *(int **)(iVar8 + 0x10);
    iVar11 = 5;
    piVar6[1] = 5;
    iVar9 = *piVar6 + 0xc;
    do {
      if (*(int *)(iVar9 + 4) != 0) break;
      iVar11 = iVar11 + -1;
      iVar9 = iVar9 + -4;
    } while (iVar11 != 0);
    piVar14 = *(int **)(iVar8 + 0x14);
    piVar6[1] = iVar11;
    piVar14[1] = (int)ppppppiVar20;
    if (0 < (int)ppppppiVar20) {
      iVar9 = *piVar14 + (int)ppppppiVar20 * 4 + -8;
      do {
        if (*(int *)(iVar9 + 4) != 0) break;
        ppppppiVar5 = (int ******)((int)ppppppiVar5 + -1);
        iVar9 = iVar9 + -4;
      } while (ppppppiVar5 != (int ******)0x0);
      piVar14[1] = (int)ppppppiVar5;
    }
    ppppppiVar20 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a7620)();
    uVar4 = 0x74;
LAB_005d7f4c:
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(ppppppiVar20,uVar4,iVar8);
  } while( true );
}

