
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ****** surewarehk_rand_bytes(undefined4 *param_1,char *param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int ******ppppppiVar4;
  int *piVar5;
  char **ppcVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int **ppiVar11;
  int **ppiVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  char *pcVar16;
  int *piVar17;
  char *pcVar18;
  undefined4 *puVar19;
  undefined1 *puVar20;
  undefined4 *unaff_s2;
  uint uVar21;
  undefined1 *unaff_s4;
  int unaff_s5;
  uint uVar22;
  uint uVar23;
  int unaff_s6;
  code *pcVar24;
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
  uint uStack_2f0;
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
  uint uStack_274;
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
  int ******ppppppiStack_228;
  int *****pppppiStack_224;
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
  uint uStack_1c4;
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
  int **ppiStack_118;
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
  undefined1 *puStack_a0;
  undefined *puStack_9c;
  undefined4 *puStack_98;
  char *pcStack_94;
  undefined1 *puStack_90;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined2 local_4c;
  undefined auStack_4a [46];
  int **local_1c;
  
  puStack_9c = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int ***)PTR___stack_chk_guard_006aabf0;
  local_5c = DAT_00674cb4;
  local_58 = DAT_00674cb8;
  local_54 = DAT_00674cbc;
  local_50 = DAT_00674cc0;
  local_4c = DAT_00674cc4;
  (*(code *)PTR_memset_006aab00)(auStack_4a,0,0x2e);
  if (p_surewarehk_Rand_Bytes == (code *)0x0) {
    puStack_a0 = &_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    pcVar16 = (char *)0x75;
    param_1 = (undefined4 *)&DAT_0000006c;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x6c,0x75,"e_sureware.c");
    ppppppiVar4 = (int ******)0x0;
  }
  else {
    unaff_s2 = &local_5c;
    pcVar16 = param_2;
    puStack_a0 = (undefined1 *)(*p_surewarehk_Rand_Bytes)(unaff_s2,param_1,param_2);
    switch(puStack_a0) {
    case (undefined1 *)0x1:
      ppppppiVar4 = (int ******)0x1;
      goto LAB_005d8e2c;
    case (undefined1 *)0xfffffffb:
      pcVar16 = (char *)0x6a;
      break;
    case (undefined1 *)0xfffffffc:
      pcVar16 = (char *)0x67;
      break;
    case (undefined1 *)0xfffffffd:
      pcVar16 = (char *)0x68;
      break;
    case (undefined1 *)0xfffffffe:
      pcVar16 = (char *)0x66;
      break;
    default:
      pcVar16 = (char *)0x65;
    }
    param_2 = "r";
    param_1 = (undefined4 *)&DAT_0000006c;
    (*(code *)PTR_ERR_put_error_006a9030)(0x26,0x6c,pcVar16,"e_sureware.c");
    if (local_5c._0_1_ != '\0') {
      unaff_s4 = &_ITM_registerTMCloneTable;
      param_1 = unaff_s2;
      (*(code *)PTR_ERR_add_error_data_006a9264)(1);
      if (logstream != 0) {
        puStack_a0 = (undefined1 *)((uint)puStack_a0 ^ 1);
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x15,"e_sureware.c",0x261);
        uVar9 = (*(code *)PTR_strlen_006aab30)(unaff_s2);
        (*(code *)PTR_BIO_write_006a7f14)(logstream,unaff_s2,uVar9);
        pcVar16 = "e_sureware.c";
        param_1 = (undefined4 *)&DAT_00000015;
        (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x15,"e_sureware.c",0x263);
        ppppppiVar4 = (int ******)(uint)(puStack_a0 == (undefined1 *)0x0);
        goto LAB_005d8e2c;
      }
    }
    puStack_a0 = (undefined1 *)((uint)puStack_a0 ^ 1);
    ppppppiVar4 = (int ******)(uint)(puStack_a0 == (undefined1 *)0x0);
  }
LAB_005d8e2c:
  if (local_1c == *(int ***)puStack_9c) {
    return ppppppiVar4;
  }
  ppiStack_118 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_120 = PTR___stack_chk_guard_006aabf0;
  puStack_11c = (undefined4 *)&_ITM_registerTMCloneTable;
  puStack_a4 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  puStack_f0 = &_gp;
  ppiStack_188 = (int **)&DAT_0000002d;
  uStack_e4 = DAT_00674d10;
  uStack_e0 = DAT_00674d14;
  uStack_dc = DAT_00674d18;
  pcStack_d8 = DAT_00674d1c;
  uStack_d4 = DAT_00674d20;
  uStack_d2 = DAT_00674d22;
  pcVar18 = DAT_00674d1c;
  puStack_98 = unaff_s2;
  pcStack_94 = param_2;
  puStack_90 = unaff_s4;
  (*(code *)PTR_memset_006aab00)(auStack_d1,0);
  if (p_surewarehk_Dsa_Sign == (code *)0x0) {
    ppiStack_124 = (int **)&_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_f0 + -0x589c))();
    }
    ppiStack_188 = (int **)0x75;
    pcVar18 = "e_sureware.c";
    puStack_f8 = (undefined4 *)0x3d0;
    uStack_1ac = 0x65;
    (**(code **)(puStack_f0 + -0x6eb0))(SUREWARE_lib_error_code,0x65,0x75,"e_sureware.c");
  }
  else {
    unaff_s5 = (**(code **)(puStack_f0 + -0x585c))(pcVar16,dsaHndidx);
    if (unaff_s5 == 0) {
      ppiStack_124 = (int **)&_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_f0 + -0x589c))();
      }
      ppiStack_188 = (int **)&DAT_00000069;
      pcVar18 = "e_sureware.c";
      puStack_f8 = (undefined4 *)0x3d6;
      uStack_1ac = 0x65;
      (**(code **)(puStack_f0 + -0x6eb0))(SUREWARE_lib_error_code,0x65,0x69,"e_sureware.c");
    }
    else {
      ppiStack_124 = (int **)(**(code **)(puStack_f0 + -0x6660))();
      if (ppiStack_124 == (int **)0x0) {
        ppiStack_124 = (int **)&_ITM_registerTMCloneTable;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (**(code **)(puStack_f0 + -0x589c))();
        }
        ppiStack_188 = (int **)&DAT_00000041;
        pcVar18 = "e_sureware.c";
        puStack_f8 = (undefined4 *)0x3dd;
        uStack_1ac = 0x65;
        (**(code **)(puStack_f0 + -0x6eb0))(SUREWARE_lib_error_code,0x65,0x41,"e_sureware.c");
      }
      else {
        piVar5 = (int *)(**(code **)(puStack_f0 + -0x7c2c))();
        pcVar24 = *(code **)(puStack_f0 + -0x7c2c);
        *ppiStack_124 = piVar5;
        piVar5 = (int *)(*pcVar24)();
        pcVar24 = *(code **)(puStack_f0 + -0x6860);
        ppiStack_124[1] = piVar5;
        (*pcVar24)(*ppiStack_124,5);
        uStack_1ac = 5;
        (**(code **)(puStack_f0 + -0x6860))(ppiStack_124[1]);
        ppcVar6 = (char **)*ppiStack_124;
        if ((ppcVar6 == (char **)0x0) || (ppcVar6[2] != &DAT_00000005)) {
LAB_005d911c:
          pcVar24 = *(code **)(puStack_f0 + -0x6664);
        }
        else {
          piVar5 = ppiStack_124[1];
          pcVar24 = *(code **)(puStack_f0 + -0x6664);
          if ((piVar5 != (int *)0x0) &&
             (unaff_s6 = piVar5[2], ppiStack_188 = ppiStack_118, unaff_s6 == 5)) {
            pcVar18 = *ppcVar6;
            puStack_11c = &uStack_e4;
            puStack_f8 = (undefined4 *)*piVar5;
            iStack_f4 = unaff_s5;
            ppiStack_188 = (int **)(*p_surewarehk_Dsa_Sign)
                                             (puStack_11c,param_1,ppiStack_118,pcVar18);
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
            ppiVar11 = (int **)ppiStack_124[1];
            ppiVar12[1] = piVar5;
            ppiVar11[1] = (int *)&DAT_00000005;
            piVar5 = *ppiVar11;
            if (piVar5[4] == 0) {
              if (piVar5[3] == 0) {
                if (piVar5[2] == 0) {
                  if (piVar5[1] == 0) {
                    ppiVar11[1] = (int *)(uint)(*piVar5 != 0);
                  }
                  else {
                    ppiVar11[1] = (int *)&SUB_00000002;
                  }
                }
                else {
                  ppiVar11[1] = (int *)0x3;
                }
              }
              else {
                ppiVar11[1] = (int *)&SUB_00000004;
              }
            }
            else {
              ppiVar11[1] = (int *)&DAT_00000005;
            }
            goto LAB_005d911c;
          }
        }
        (*pcVar24)(ppiStack_124);
      }
    }
  }
  if (puStack_a4 == *(undefined4 **)puStack_120) {
    return (int ******)0x0;
  }
  pcStack_10c = surewarehk_rsa_sign;
  puVar10 = puStack_a4;
  (**(code **)(puStack_f0 + -0x5328))();
  puStack_1b8 = puStack_f8;
  puStack_1bc = PTR___stack_chk_guard_006aabf0;
  iStack_12c = *(int *)PTR___stack_chk_guard_006aabf0;
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
  piStack_16c = s_ENGINE_rsa_sign_00674d50._0_4_;
  uStack_168 = s_ENGINE_rsa_sign_00674d50._4_4_;
  uStack_164 = s_ENGINE_rsa_sign_00674d50._8_4_;
  uStack_160 = s_ENGINE_rsa_sign_00674d50._12_4_;
  ppiStack_1b4 = ppiStack_188;
  puStack_114 = param_1;
  iStack_110 = unaff_s5;
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    ppppppiStack_1c0 = (int ******)&_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppppppiStack_228 = (int ******)0x75;
    pcVar16 = "e_sureware.c";
    ppiStack_188 = (int **)0x3ad;
    piStack_300 = (int *)&DAT_0000006f;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code);
    ppppppiVar4 = (int ******)0x0;
  }
  else {
    puVar7 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006aa640)(pcVar18,rsaHndidx);
    param_1 = puVar10;
    if (puVar7 == (undefined4 *)0x0) {
      ppppppiStack_1c0 = (int ******)&_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      ppppppiStack_228 = (int ******)&DAT_00000069;
      pcVar16 = "e_sureware.c";
      ppiStack_188 = (int **)0x3b2;
      piStack_300 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code);
      ppppppiVar4 = (int ******)0x0;
    }
    else if (puStack_1b8 == (undefined4 *)0x1) {
      pcVar16 = (char *)&ppppppiStack_170;
      puStack_180 = puStack_1b8;
      ppppppiStack_1c0 = (int ******)(*p_surewarehk_Rsa_Sign)(&piStack_16c,puVar10,uStack_1ac);
      piStack_300 = (int *)&DAT_0000006f;
      ppppppiStack_228 = ppppppiStack_1c0;
      surewarehk_error_handling(&piStack_16c);
      ppppppiVar4 = ppppppiStack_1c0;
      ppiStack_1b4 = &piStack_16c;
      puStack_184 = puVar7;
      if (ppppppiStack_1c0 == (int ******)0x1) {
        ppppppiVar4 = ppppppiStack_170;
      }
    }
    else {
      ppppppiStack_1c0 = (int ******)&_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      ppppppiStack_228 = (int ******)&DAT_0000006b;
      pcVar16 = "e_sureware.c";
      ppiStack_188 = (int **)0x3be;
      piStack_300 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code);
      ppppppiVar4 = (int ******)0x0;
    }
  }
  if (iStack_12c == *(int *)puStack_1bc) {
    return ppppppiVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_264 = PTR___stack_chk_guard_006aabf0;
  pcStack_2ec = "r";
  ppiStack_220 = ppiStack_188;
  ppppppiStack_268 = &pppppiStack_218;
  puStack_21c = puStack_184;
  ppppppiStack_260 = apppppiStack_1f6;
  puStack_230 = &_gp;
  pppppiStack_224 = pppppiStack_17c;
  uStack_1c4 = *(uint *)PTR___stack_chk_guard_006aabf0;
  puStack_1b0 = param_1;
  iStack_1a8 = unaff_s6;
  (*(code *)PTR_BN_init_006a96a0)(ppppppiStack_268);
  ppppppiStack_2f4 = (int ******)0x32;
  pppppiStack_204 = (int *****)DAT_00674bfc;
  uStack_200 = DAT_00674c00;
  puStack_1fc = DAT_00674c04;
  uStack_1f8 = DAT_00674c08;
  pcVar18 = (char *)DAT_00674c04;
  (**(code **)(puStack_230 + -0x53e0))(ppppppiStack_260,0);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_005d98a8:
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_230 + -0x589c))();
    }
    ppppppiStack_2f4 = (int ******)0x75;
    pcVar18 = "e_sureware.c";
    pppppiStack_240 = (int *****)0x403;
    piVar5 = (int *)&DAT_0000006b;
    (**(code **)(puStack_230 + -0x6eb0))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
LAB_005d96e0:
    piStack_300 = piVar5;
    ppppppiStack_270 = (int ******)0x0;
    ppppppiStack_25c = (int ******)pcVar16;
  }
  else {
    piVar5 = (int *)puStack_180[1];
    (**(code **)(puStack_230 + -0x6860))(piStack_300);
    if ((piStack_300 == (int *)0x0) ||
       (piVar5 = (int *)piStack_300[2], ppppppiStack_2f4 = ppppppiStack_228,
       piVar5 != (int *)puStack_180[1])) goto LAB_005d96e0;
    pppppiStack_240 = *(int ******)pcVar16;
    pppppiStack_234 = (int *****)*piStack_300;
    pcVar18 = (char *)((int)*(int ******)((int)pcVar16 + 4) << 2);
    pppppiStack_238 = *ppppppiStack_228;
    iStack_23c = (int)ppppppiStack_228[1] << 2;
    ppppppiStack_228 = &pppppiStack_204;
    pcVar16 = (char *)(*p_surewarehk_Mod_Exp)
                                (&pppppiStack_204,(int)piVar5 << 2,*puStack_180,pcVar18);
    piVar5 = (int *)&DAT_0000006b;
    ppppppiStack_2f4 = (int ******)pcVar16;
    surewarehk_error_handling(ppppppiStack_228);
    if ((int ******)pcVar16 == (int ******)0x1) {
      iVar8 = puStack_180[1];
      piStack_300[1] = iVar8;
      if (0 < iVar8) {
        iVar13 = *piStack_300 + iVar8 * 4 + -8;
        do {
          if (*(int *)(iVar13 + 4) != 0) break;
          iVar8 = iVar8 + -1;
          iVar13 = iVar13 + -4;
        } while (iVar8 != 0);
        piStack_300[1] = iVar8;
      }
    }
    else if ((int ******)pcVar16 == (int ******)0x0) goto LAB_005d96e0;
    ppppppiStack_2f4 = (int ******)0x32;
    pppppiStack_204 = (int *****)DAT_00674bfc;
    uStack_200 = DAT_00674c00;
    puStack_1fc = DAT_00674c04;
    uStack_1f8 = DAT_00674c08;
    pcVar18 = (char *)DAT_00674c04;
    (**(code **)(puStack_230 + -0x53e0))(ppppppiStack_260,0);
    if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_005d98a8;
    (**(code **)(puStack_230 + -0x6860))(ppppppiStack_268,puStack_180[1]);
    ppppppiStack_25c = ppppppiStack_228;
    piVar5 = piStack_210;
    if (piStack_210 != (int *)puStack_180[1]) goto LAB_005d96e0;
    pppppiStack_238 = (int *****)*ppiStack_220;
    iStack_23c = (int)ppiStack_220[1] << 2;
    pppppiStack_240 = (int *****)*puStack_21c;
    pcVar18 = (char *)(puStack_21c[1] << 2);
    pppppiStack_234 = pppppiStack_218;
    ppppppiStack_260 =
         (int ******)
         (*p_surewarehk_Mod_Exp)(ppppppiStack_228,(int)piStack_210 << 2,*puStack_180,pcVar18);
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
      pcVar16 = (char *)ppppppiStack_25c;
      if (ppppppiStack_260 == (int ******)0x0) goto LAB_005d96e0;
    }
    pppppiStack_240 = pppppiStack_224;
    ppppppiStack_2f4 = ppppppiStack_268;
    pcVar18 = (char *)puStack_180;
    iVar8 = (**(code **)(puStack_230 + -0x6848))
                      (piStack_300,piStack_300,ppppppiStack_268,puStack_180);
    ppppppiStack_270 = (int ******)(uint)(iVar8 != 0);
  }
  (**(code **)(puStack_230 + -0x7dc4))(ppppppiStack_268);
  if (uStack_1c4 == *(uint *)puStack_264) {
    return ppppppiStack_270;
  }
  pcStack_254 = surewarehk_rsa_priv_dec;
  uVar22 = uStack_1c4;
  (**(code **)(puStack_230 + -0x5328))();
  pppppiStack_2f8 = pppppiStack_240;
  puStack_2fc = PTR___stack_chk_guard_006aabf0;
  puStack_26c = puStack_180;
  uStack_274 = *(uint *)PTR___stack_chk_guard_006aabf0;
  pcStack_258 = "r";
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
  iStack_2b4 = s_ENGINE_rsa_priv_dec_00674d90._0_4_;
  uStack_2b0 = s_ENGINE_rsa_priv_dec_00674d90._4_4_;
  uStack_2ac = s_ENGINE_rsa_priv_dec_00674d90._8_4_;
  uStack_2a8 = s_ENGINE_rsa_priv_dec_00674d90._12_4_;
  uStack_2a4 = s_ENGINE_rsa_priv_dec_00674d90._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppppppiStack_2d0 = (int ******)0x366;
    (**(code **)(puStack_2c0 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
    iVar8 = 0;
  }
  else {
    iVar8 = (*(code *)PTR_RSA_get_ex_data_006aa640)(pcVar18,rsaHndidx);
    if (iVar8 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_2c0 + -0x589c))();
      }
      ppppppiStack_2d0 = (int ******)0x36b;
      ppppppiVar4 = (int ******)&DAT_0000006e;
      ppppppiStack_304 = (int ******)0x0;
      (**(code **)(puStack_2c0 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d9aa0;
    }
  }
  pcStack_2ec = (char *)0x1;
  ppppppiStack_2d0 = ppppppiStack_2f4;
  iStack_2cc = iVar8;
  if (pppppiStack_2f8 == (int *****)0x1) {
    pppppiStack_2c8 = pppppiStack_2f8;
    ppppppiStack_304 =
         (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_2b4,uVar22,piStack_300,&ppppppiStack_2b8);
    ppppppiVar4 = (int ******)&DAT_0000006e;
    surewarehk_error_handling(&iStack_2b4,0x6e,ppppppiStack_304);
    piStack_300 = &iStack_2b4;
    if (ppppppiStack_304 == (int ******)0x1) {
      ppppppiStack_304 = ppppppiStack_2b8;
    }
    goto LAB_005d9aa0;
  }
  pppppiStack_2c8 = (int *****)0x0;
  ppppppiStack_304 = (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_2b4,uVar22,piStack_300);
  ppppppiVar4 = (int ******)&DAT_0000006e;
  surewarehk_error_handling(&iStack_2b4,0x6e,ppppppiStack_304);
  piStack_300 = &iStack_2b4;
  if (ppppppiStack_304 != (int ******)0x1) goto LAB_005d9aa0;
  pcStack_2ec = "r";
  piStack_300 = (int *)(**(code **)(puStack_2c0 + -0x7dd8))(ppppppiStack_2b8,"e_sureware.c",0x37f);
  if (piStack_300 == (int *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_2c0 + -0x589c))();
    }
    ppppppiVar4 = (int ******)&DAT_0000006e;
    ppppppiStack_2d0 = (int ******)0x381;
    (**(code **)(puStack_2c0 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    piStack_300 = (int *)&_ITM_registerTMCloneTable;
    goto LAB_005d9aa0;
  }
  (**(code **)(puStack_2c0 + -0x52ec))(piStack_300,ppppppiStack_2f4,ppppppiStack_2b8);
  if (pppppiStack_2f8 == (int *****)0x3) {
    pcVar24 = *(code **)(puStack_2c0 + -0x66d4);
LAB_005d9d0c:
    ppppppiStack_2d0 = ppppppiStack_2b8;
    ppppppiStack_304 = (int ******)(*pcVar24)(ppppppiStack_2f4,ppppppiStack_2b8,piStack_300,uVar22);
LAB_005d9cac:
    pcVar24 = *(code **)(puStack_2c0 + -0x7d6c);
    if ((int)ppppppiStack_304 < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_2c0 + -0x589c))();
      }
      ppppppiStack_2d0 = (int ******)0x397;
      (**(code **)(puStack_2c0 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d9c04;
    }
  }
  else {
    if (pppppiStack_2f8 == (int *****)0x4) {
      pppppiStack_2c8 = (int *****)0x0;
      iStack_2cc = 0;
      ppppppiStack_2d0 = ppppppiStack_2b8;
      ppppppiStack_304 =
           (int ******)
           (**(code **)(puStack_2c0 + -0x66ac))(ppppppiStack_2f4,ppppppiStack_2b8,piStack_300);
      goto LAB_005d9cac;
    }
    bVar1 = pppppiStack_2f8 == (int *****)0x2;
    pppppiStack_2f8 = (int *****)&_ITM_registerTMCloneTable;
    if (bVar1) {
      pcVar24 = *(code **)(puStack_2c0 + -0x66a4);
      goto LAB_005d9d0c;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_2c0 + -0x589c))();
    }
    ppppppiStack_2d0 = (int ******)0x393;
    (**(code **)(puStack_2c0 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d9c04:
    pppppiStack_2f8 = (int *****)&_ITM_registerTMCloneTable;
    pcVar24 = *(code **)(puStack_2c0 + -0x7d6c);
  }
  (*pcVar24)(piStack_300,ppppppiStack_2b8);
  (**(code **)(puStack_2c0 + -0x7f58))(piStack_300);
  ppppppiVar4 = ppppppiStack_2b8;
LAB_005d9aa0:
  if (uStack_274 == *(uint *)puStack_2fc) {
    return ppppppiStack_304;
  }
  pcStack_2e4 = surewarehk_load_pubkey;
  uVar23 = uStack_274;
  (**(code **)(puStack_2c0 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_30c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppppiStack_2e8 = &DAT_00674bfc;
  uStack_390 = 0;
  cStack_391 = '\0';
  uStack_38c = s_ENGINE_load_pubkey_00674dd0._0_4_;
  uStack_388 = s_ENGINE_load_pubkey_00674dd0._4_4_;
  uStack_384 = s_ENGINE_load_pubkey_00674dd0._8_4_;
  uStack_380 = s_ENGINE_load_pubkey_00674dd0._12_4_;
  uStack_37c = s_ENGINE_load_pubkey_00674dd0._16_2_;
  cStack_37a = s_ENGINE_load_pubkey_00674dd0[18];
  uStack_2f0 = uVar22;
  (*(code *)PTR_memset_006aab00)(auStack_379,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    puVar20 = &_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppppppiVar4 = (int ******)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x32c);
  }
  else {
    iVar8 = (*p_surewarehk_Info_Pubkey)(&uStack_38c,ppppppiVar4,&uStack_390,&cStack_391);
    uVar15 = uStack_390;
    if (iVar8 == 1) {
      uVar22 = (uint)cStack_391;
      uStack_34c = s_sureware_load_public_00674e10._0_4_;
      uStack_348 = s_sureware_load_public_00674e10._4_4_;
      uStack_344 = s_sureware_load_public_00674e10._8_4_;
      uStack_340 = s_sureware_load_public_00674e10._12_4_;
      uStack_33c = s_sureware_load_public_00674e10._16_4_;
      cStack_338 = s_sureware_load_public_00674e10[20];
      (*(code *)PTR_memset_006aab00)(auStack_337,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        puVar20 = &_ITM_registerTMCloneTable;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        ppppppiVar4 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)
                  (SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",0x299);
      }
      else if (uVar22 == 1) {
        uVar21 = uVar15 >> 2;
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
        puVar10 = *(undefined4 **)(puVar20 + 0x14);
        if ((((puVar10 != (undefined4 *)0x0) && (uVar21 == puVar10[2])) &&
            (puVar7 = *(undefined4 **)(puVar20 + 0x10), puVar7 != (undefined4 *)0x0)) &&
           (uVar21 == puVar7[2])) {
          iVar8 = (*p_surewarehk_Load_Rsa_Pubkey)(&uStack_34c,ppppppiVar4,uVar15,*puVar7,*puVar10);
          surewarehk_error_handling(&uStack_34c,0x6a,iVar8);
          if (iVar8 == 1) {
            piVar5 = *(int **)(puVar20 + 0x14);
            piVar5[1] = uVar21;
            if (uVar21 == 0) {
              *(undefined4 *)(*(int *)(puVar20 + 0x10) + 4) = 0;
            }
            else {
              iVar8 = (uVar15 & 0xfffffffc) - 4;
              piVar17 = (int *)(*piVar5 + iVar8);
              uVar23 = uVar21;
              do {
                uVar15 = uVar23 - 1;
                if (*piVar17 != 0) break;
                piVar17 = piVar17 + -1;
                uVar23 = uVar15;
              } while (uVar15 != 0);
              piVar17 = *(int **)(puVar20 + 0x10);
              piVar5[1] = uVar23;
              piVar17[1] = uVar21;
              piVar5 = (int *)(*piVar17 + iVar8);
              uVar23 = uVar21;
              do {
                uVar15 = uVar23 - 1;
                if (*piVar5 != 0) break;
                piVar5 = piVar5 + -1;
                uVar23 = uVar15;
              } while (uVar15 != 0);
              piVar17[1] = uVar23;
            }
            ppppppiVar4 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a8710)();
            uVar9 = 6;
            goto LAB_005da414;
          }
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2b3);
        }
        ppppppiVar4 = (int ******)0x0;
        (*(code *)PTR_RSA_free_006a86f0)(puVar20);
        uVar23 = uVar21;
      }
      else {
        puVar20 = &_ITM_registerTMCloneTable;
        if (uVar22 == 2) {
          uVar21 = uVar15 >> 2;
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
          puVar10 = *(undefined4 **)(puVar20 + 0x18);
          uVar22 = uVar21;
          if ((((puVar10 != (undefined4 *)0x0) && (uVar21 == puVar10[2])) &&
              (puVar7 = *(undefined4 **)(puVar20 + 0xc), puVar7 != (undefined4 *)0x0)) &&
             (((uVar21 == puVar7[2] &&
               (puVar19 = *(undefined4 **)(puVar20 + 0x10), puVar19 != (undefined4 *)0x0)) &&
              ((puVar19[2] == 5 &&
               ((puVar14 = *(undefined4 **)(puVar20 + 0x14), puVar14 != (undefined4 *)0x0 &&
                (uVar21 == puVar14[2])))))))) {
            iVar8 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_34c,ppppppiVar4,uVar15,*puVar10,*puVar7,*puVar19,*puVar14);
            surewarehk_error_handling(&uStack_34c,0x6a,iVar8);
            if (iVar8 == 1) goto LAB_005da448;
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x2df);
          }
          ppppppiVar4 = (int ******)0x0;
          (*(code *)PTR_DSA_free_006a862c)(puVar20);
          uVar23 = uVar21;
        }
        else {
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          ppppppiVar4 = (int ******)0x0;
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
      ppppppiVar4 = (int ******)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x334);
      (*(code *)PTR_ERR_add_error_data_006a9264)(1,&uStack_38c);
    }
  }
  do {
    if (iStack_30c == *(int *)puVar3) {
      return ppppppiVar4;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar21 = uVar23;
LAB_005da448:
    piVar5 = *(int **)(puVar20 + 0x18);
    piVar5[1] = uVar21;
    if ((int)uVar21 < 1) {
      *(undefined4 *)(*(int *)(puVar20 + 0xc) + 4) = 0;
    }
    else {
      iVar8 = uVar21 * 4 + -4;
      piVar17 = (int *)(*piVar5 + iVar8);
      uVar23 = uVar21;
      do {
        uVar15 = uVar23 - 1;
        if (*piVar17 != 0) break;
        piVar17 = piVar17 + -1;
        uVar23 = uVar15;
      } while (uVar15 != 0);
      piVar17 = *(int **)(puVar20 + 0xc);
      piVar5[1] = uVar23;
      piVar17[1] = uVar21;
      piVar5 = (int *)(*piVar17 + iVar8);
      uVar23 = uVar21;
      do {
        uVar15 = uVar23 - 1;
        if (*piVar5 != 0) break;
        piVar5 = piVar5 + -1;
        uVar23 = uVar15;
      } while (uVar15 != 0);
      piVar17[1] = uVar23;
    }
    piVar17 = *(int **)(puVar20 + 0x10);
    iVar8 = 5;
    piVar17[1] = 5;
    piVar5 = (int *)(*piVar17 + 0x10);
    do {
      if (*piVar5 != 0) break;
      iVar8 = iVar8 + -1;
      piVar5 = piVar5 + -1;
    } while (iVar8 != 0);
    piVar5 = *(int **)(puVar20 + 0x14);
    piVar17[1] = iVar8;
    piVar5[1] = uVar21;
    if (0 < (int)uVar21) {
      piVar17 = (int *)(*piVar5 + uVar21 * 4 + -4);
      do {
        uVar23 = uVar22 - 1;
        if (*piVar17 != 0) break;
        piVar17 = piVar17 + -1;
        uVar22 = uVar23;
      } while (uVar23 != 0);
      piVar5[1] = uVar22;
    }
    ppppppiVar4 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a8710)();
    uVar9 = 0x74;
LAB_005da414:
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(ppppppiVar4,uVar9,puVar20);
    uVar23 = uVar21;
  } while( true );
}

