
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ******
surewarehk_rsa_sign(undefined4 param_1,undefined4 param_2,int **param_3,undefined4 param_4,
                   undefined4 *param_5)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  int ******ppppppiVar13;
  int ******ppppppiVar14;
  char *pcVar15;
  int ******ppppppiVar16;
  uint uVar17;
  undefined4 unaff_s4;
  int ******ppppppiVar18;
  uint uVar19;
  code *pcVar20;
  char cStack_289;
  uint uStack_288;
  undefined4 uStack_284;
  undefined4 uStack_280;
  undefined4 uStack_27c;
  undefined4 uStack_278;
  undefined2 uStack_274;
  char cStack_272;
  undefined auStack_271 [45];
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  char cStack_230;
  undefined auStack_22f [43];
  int iStack_204;
  int ******ppppppiStack_1fc;
  int *piStack_1f8;
  undefined *puStack_1f4;
  int *****pppppiStack_1f0;
  int ******ppppppiStack_1ec;
  int ******ppppppiStack_1e8;
  char *pcStack_1e4;
  int ****ppppiStack_1e0;
  code *pcStack_1dc;
  int ******ppppppiStack_1c8;
  int iStack_1c4;
  int *****pppppiStack_1c0;
  undefined *puStack_1b8;
  int ******ppppppiStack_1b0;
  int iStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined4 uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  int iStack_16c;
  int ******ppppppiStack_168;
  undefined4 *puStack_164;
  int ******ppppppiStack_160;
  undefined *puStack_15c;
  int ******ppppppiStack_158;
  int ******ppppppiStack_154;
  char *pcStack_150;
  code *pcStack_14c;
  int *****pppppiStack_138;
  int iStack_134;
  int *****pppppiStack_130;
  int *****pppppiStack_12c;
  undefined *puStack_128;
  int *****pppppiStack_120;
  int ******ppppppiStack_11c;
  int **ppiStack_118;
  undefined4 *puStack_114;
  int *****pppppiStack_110;
  int iStack_10c;
  int *piStack_108;
  int *****pppppiStack_fc;
  undefined4 uStack_f8;
  undefined4 *puStack_f4;
  undefined2 uStack_f0;
  int *****apppppiStack_ee [12];
  int ******ppppppiStack_bc;
  int ******ppppppiStack_b8;
  undefined *puStack_b4;
  undefined4 *puStack_b0;
  int **ppiStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  int **local_80;
  undefined4 *local_7c;
  undefined4 *local_78;
  int *****pppppiStack_74;
  int ******local_68;
  int *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  puStack_b4 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_64 = s_ENGINE_rsa_sign_00674460._0_4_;
  local_60 = s_ENGINE_rsa_sign_00674460._4_4_;
  local_5c = s_ENGINE_rsa_sign_00674460._8_4_;
  local_58 = s_ENGINE_rsa_sign_00674460._12_4_;
  ppiStack_ac = param_3;
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    ppppppiStack_b8 = (int ******)&_gp_1;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiStack_11c = (int ******)0x75;
    pcVar5 = "e_sureware.c";
    local_80 = (int **)0x3df;
    piStack_1f8 = (int *)&DAT_0000006f;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
    ppppppiVar18 = (int ******)0x0;
  }
  else {
    puVar4 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006a9534)(param_4,rsaHndidx);
    unaff_s4 = param_1;
    if (puVar4 == (undefined4 *)0x0) {
      ppppppiStack_b8 = (int ******)&_gp_1;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      ppppppiStack_11c = (int ******)&DAT_00000069;
      pcVar5 = "e_sureware.c";
      local_80 = (int **)0x3e4;
      piStack_1f8 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
      ppppppiVar18 = (int ******)0x0;
    }
    else if (param_5 == (undefined4 *)0x1) {
      pcVar5 = (char *)&local_68;
      local_78 = param_5;
      ppppppiStack_b8 = (int ******)(*p_surewarehk_Rsa_Sign)(&local_64,param_1,param_2);
      piStack_1f8 = (int *)&DAT_0000006f;
      ppppppiStack_11c = ppppppiStack_b8;
      surewarehk_error_handling(&local_64);
      ppppppiVar18 = ppppppiStack_b8;
      ppiStack_ac = &local_64;
      local_80 = param_3;
      local_7c = puVar4;
      if (ppppppiStack_b8 == (int ******)0x1) {
        ppppppiVar18 = local_68;
      }
    }
    else {
      ppppppiStack_b8 = (int ******)&_gp_1;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      ppppppiStack_11c = (int ******)&DAT_0000006b;
      pcVar5 = "e_sureware.c";
      local_80 = (int **)0x3f1;
      piStack_1f8 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code);
      ppppppiVar18 = (int ******)0x0;
    }
  }
  if (local_24 == *(int *)puStack_b4) {
    return ppppppiVar18;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_15c = PTR___stack_chk_guard_006a9ae8;
  pcStack_1e4 = "encrypt";
  ppiStack_118 = local_80;
  puStack_b0 = param_5;
  ppppppiStack_160 = &pppppiStack_110;
  puStack_114 = local_7c;
  ppppppiStack_158 = apppppiStack_ee;
  puStack_128 = &_gp;
  pppppiStack_120 = pppppiStack_74;
  ppppppiStack_bc = *(int *******)PTR___stack_chk_guard_006a9ae8;
  uStack_a8 = unaff_s4;
  uStack_a4 = param_2;
  (*(code *)PTR_BN_init_006a857c)(ppppppiStack_160);
  ppppppiStack_1ec = (int ******)&DAT_00000032;
  piVar12 = (int *)0x0;
  pppppiStack_fc = (int *****)DAT_0067430c;
  uStack_f8 = DAT_00674310;
  puStack_f4 = DAT_00674314;
  uStack_f0 = DAT_00674318;
  pcVar15 = (char *)DAT_00674314;
  (**(code **)(puStack_128 + -0x53ec))(ppppppiStack_158);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_005d72d4:
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x58a8))();
    }
    ppppppiStack_1ec = (int ******)0x75;
    pcVar15 = "e_sureware.c";
    pppppiStack_138 = (int *****)0x435;
    piVar12 = (int *)&DAT_0000006b;
    (**(code **)(puStack_128 + -0x6eac))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
LAB_005d7108:
    piStack_1f8 = piVar12;
    ppppppiStack_168 = (int ******)0x0;
    ppppppiStack_154 = (int ******)pcVar5;
  }
  else {
    if (piStack_1f8 == (int *)0x0) goto LAB_005d7108;
    (**(code **)(puStack_128 + -0x68bc))(piStack_1f8,local_78[1]);
    piVar12 = (int *)piStack_1f8[2];
    if (piVar12 != (int *)local_78[1]) goto LAB_005d7108;
    pppppiStack_138 = *(int ******)pcVar5;
    pppppiStack_12c = (int *****)*piStack_1f8;
    pcVar15 = (char *)((int)*(int ******)((int)pcVar5 + 4) << 2);
    pppppiStack_130 = *ppppppiStack_11c;
    iStack_134 = (int)ppppppiStack_11c[1] << 2;
    ppppppiStack_11c = &pppppiStack_fc;
    pcVar5 = (char *)(*p_surewarehk_Mod_Exp)(&pppppiStack_fc,(int)piVar12 << 2,*local_78,pcVar15);
    piVar12 = (int *)&DAT_0000006b;
    ppppppiStack_1ec = (int ******)pcVar5;
    surewarehk_error_handling(ppppppiStack_11c);
    if ((int ******)pcVar5 == (int ******)0x1) {
      iVar6 = local_78[1];
      piStack_1f8[1] = iVar6;
      if (0 < iVar6) {
        iVar7 = *piStack_1f8 + iVar6 * 4 + -8;
        do {
          if (*(int *)(iVar7 + 4) != 0) break;
          iVar6 = iVar6 + -1;
          iVar7 = iVar7 + -4;
        } while (iVar6 != 0);
        piStack_1f8[1] = iVar6;
      }
    }
    else if ((int ******)pcVar5 == (int ******)0x0) goto LAB_005d7108;
    ppppppiStack_1ec = (int ******)&DAT_00000032;
    pppppiStack_fc = (int *****)DAT_0067430c;
    uStack_f8 = DAT_00674310;
    puStack_f4 = DAT_00674314;
    uStack_f0 = DAT_00674318;
    pcVar15 = (char *)DAT_00674314;
    (**(code **)(puStack_128 + -0x53ec))(ppppppiStack_158,0);
    if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_005d72d4;
    (**(code **)(puStack_128 + -0x68bc))(ppppppiStack_160,local_78[1]);
    ppppppiStack_154 = ppppppiStack_11c;
    piVar12 = piStack_108;
    if (piStack_108 != (int *)local_78[1]) goto LAB_005d7108;
    pppppiStack_130 = (int *****)*ppiStack_118;
    iStack_134 = (int)ppiStack_118[1] << 2;
    pppppiStack_138 = (int *****)*puStack_114;
    pcVar15 = (char *)(puStack_114[1] << 2);
    pppppiStack_12c = pppppiStack_110;
    ppppppiStack_158 =
         (int ******)
         (*p_surewarehk_Mod_Exp)(ppppppiStack_11c,(int)piStack_108 << 2,*local_78,pcVar15);
    piVar12 = (int *)&DAT_0000006b;
    ppppppiStack_1ec = ppppppiStack_158;
    surewarehk_error_handling(ppppppiStack_154);
    if (ppppppiStack_158 == (int ******)0x1) {
      iStack_10c = local_78[1];
      if (0 < iStack_10c) {
        pppppiStack_110 = pppppiStack_110 + iStack_10c + -2;
        do {
          if (pppppiStack_110[1] != (int ****)0x0) break;
          iStack_10c = iStack_10c + -1;
          pppppiStack_110 = pppppiStack_110 + -1;
        } while (iStack_10c != 0);
      }
    }
    else {
      pcVar5 = (char *)ppppppiStack_154;
      if (ppppppiStack_158 == (int ******)0x0) goto LAB_005d7108;
    }
    pppppiStack_138 = pppppiStack_120;
    ppppppiStack_1ec = ppppppiStack_160;
    pcVar15 = (char *)local_78;
    iVar6 = (**(code **)(puStack_128 + -0x686c))(piStack_1f8,piStack_1f8,ppppppiStack_160,local_78);
    ppppppiStack_168 = (int ******)(uint)(iVar6 != 0);
  }
  (**(code **)(puStack_128 + -0x7dc4))(ppppppiStack_160);
  if (ppppppiStack_bc == *(int *******)puStack_15c) {
    return ppppppiStack_168;
  }
  pcStack_14c = surewarehk_rsa_priv_dec;
  ppppppiVar18 = ppppppiStack_bc;
  (**(code **)(puStack_128 + -0x5330))();
  pppppiStack_1f0 = pppppiStack_138;
  puStack_1f4 = PTR___stack_chk_guard_006a9ae8;
  puStack_164 = local_78;
  iStack_16c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_150 = "encrypt";
  puStack_1b8 = &_gp;
  uStack_198 = 0;
  uStack_194 = 0;
  uStack_190 = 0;
  uStack_18c = 0;
  uStack_188 = 0;
  uStack_184 = 0;
  uStack_180 = 0;
  uStack_17c = 0;
  uStack_178 = 0;
  uStack_174 = 0;
  uStack_170 = 0;
  iStack_1ac = s_ENGINE_rsa_priv_dec_006744a0._0_4_;
  uStack_1a8 = s_ENGINE_rsa_priv_dec_006744a0._4_4_;
  uStack_1a4 = s_ENGINE_rsa_priv_dec_006744a0._8_4_;
  uStack_1a0 = s_ENGINE_rsa_priv_dec_006744a0._12_4_;
  uStack_19c = s_ENGINE_rsa_priv_dec_006744a0._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiStack_1c8 = (int ******)0x38f;
    (**(code **)(puStack_1b8 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
    iVar6 = 0;
  }
  else {
    iVar6 = (*(code *)PTR_RSA_get_ex_data_006a9534)(pcVar15,rsaHndidx);
    if (iVar6 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_1b8 + -0x58a8))();
      }
      ppppppiStack_1c8 = (int ******)0x394;
      ppppppiVar13 = (int ******)&DAT_0000006e;
      ppppppiStack_1fc = (int ******)0x0;
      (**(code **)(puStack_1b8 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d74cc;
    }
  }
  pcStack_1e4 = (char *)0x1;
  ppppppiStack_1c8 = ppppppiStack_1ec;
  iStack_1c4 = iVar6;
  if (pppppiStack_1f0 == (int *****)0x1) {
    pppppiStack_1c0 = pppppiStack_1f0;
    ppppppiStack_1fc =
         (int ******)
         (*p_surewarehk_Rsa_Priv_Dec)(&iStack_1ac,ppppppiVar18,piStack_1f8,&ppppppiStack_1b0);
    ppppppiVar13 = (int ******)&DAT_0000006e;
    surewarehk_error_handling(&iStack_1ac,0x6e,ppppppiStack_1fc);
    piStack_1f8 = &iStack_1ac;
    if (ppppppiStack_1fc == (int ******)0x1) {
      ppppppiStack_1fc = ppppppiStack_1b0;
    }
    goto LAB_005d74cc;
  }
  pppppiStack_1c0 = (int *****)0x0;
  ppppppiStack_1fc = (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_1ac,ppppppiVar18,piStack_1f8);
  ppppppiVar13 = (int ******)&DAT_0000006e;
  surewarehk_error_handling(&iStack_1ac,0x6e,ppppppiStack_1fc);
  piStack_1f8 = &iStack_1ac;
  if (ppppppiStack_1fc != (int ******)0x1) goto LAB_005d74cc;
  pcStack_1e4 = "encrypt";
  piStack_1f8 = (int *)(**(code **)(puStack_1b8 + -0x7dd8))(ppppppiStack_1b0,"e_sureware.c",0x3ac);
  if (piStack_1f8 == (int *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_1b8 + -0x58a8))();
    }
    ppppppiVar13 = (int ******)&DAT_0000006e;
    ppppppiStack_1c8 = (int ******)0x3ae;
    (**(code **)(puStack_1b8 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    piStack_1f8 = (int *)&_gp_1;
    goto LAB_005d74cc;
  }
  (**(code **)(puStack_1b8 + -0x52f4))(piStack_1f8,ppppppiStack_1ec,ppppppiStack_1b0);
  if (pppppiStack_1f0 == (int *****)0x3) {
    pcVar20 = *(code **)(puStack_1b8 + -0x66f8);
LAB_005d7738:
    ppppppiStack_1c8 = ppppppiStack_1b0;
    ppppppiStack_1fc =
         (int ******)(*pcVar20)(ppppppiStack_1ec,ppppppiStack_1b0,piStack_1f8,ppppppiVar18);
LAB_005d76d8:
    pcVar20 = *(code **)(puStack_1b8 + -0x7d6c);
    if ((int)ppppppiStack_1fc < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_1b8 + -0x58a8))();
      }
      ppppppiStack_1c8 = (int ******)0x3cb;
      (**(code **)(puStack_1b8 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d7630;
    }
  }
  else {
    if (pppppiStack_1f0 == (int *****)0x4) {
      pppppiStack_1c0 = (int *****)0x0;
      iStack_1c4 = 0;
      ppppppiStack_1c8 = ppppppiStack_1b0;
      ppppppiStack_1fc =
           (int ******)
           (**(code **)(puStack_1b8 + -0x66d0))(ppppppiStack_1ec,ppppppiStack_1b0,piStack_1f8);
      goto LAB_005d76d8;
    }
    bVar1 = pppppiStack_1f0 == (int *****)0x2;
    pppppiStack_1f0 = (int *****)&_gp_1;
    if (bVar1) {
      pcVar20 = *(code **)(puStack_1b8 + -0x66c8);
      goto LAB_005d7738;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_1b8 + -0x58a8))();
    }
    ppppppiStack_1c8 = (int ******)0x3c6;
    (**(code **)(puStack_1b8 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d7630:
    pppppiStack_1f0 = (int *****)&_gp_1;
    pcVar20 = *(code **)(puStack_1b8 + -0x7d6c);
  }
  (*pcVar20)(piStack_1f8,ppppppiStack_1b0);
  (**(code **)(puStack_1b8 + -0x7f58))(piStack_1f8);
  ppppppiVar13 = ppppppiStack_1b0;
LAB_005d74cc:
  if (iStack_16c == *(int *)puStack_1f4) {
    return ppppppiStack_1fc;
  }
  pcStack_1dc = surewarehk_load_pubkey;
  iVar6 = iStack_16c;
  (**(code **)(puStack_1b8 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_204 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppppiStack_1e0 = &DAT_0067430c;
  uStack_288 = 0;
  cStack_289 = '\0';
  uStack_284 = s_ENGINE_load_pubkey_006744e0._0_4_;
  uStack_280 = s_ENGINE_load_pubkey_006744e0._4_4_;
  uStack_27c = s_ENGINE_load_pubkey_006744e0._8_4_;
  uStack_278 = s_ENGINE_load_pubkey_006744e0._12_4_;
  uStack_274 = s_ENGINE_load_pubkey_006744e0._16_2_;
  cStack_272 = s_ENGINE_load_pubkey_006744e0[18];
  ppppppiStack_1e8 = ppppppiVar18;
  (*(code *)PTR_memset_006a99f4)(auStack_271,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    ppppppiVar16 = (int ******)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
  }
  else {
    iVar7 = (*p_surewarehk_Info_Pubkey)(&uStack_284,ppppppiVar13,&uStack_288,&cStack_289);
    uVar19 = uStack_288;
    if (iVar7 == 1) {
      ppppppiVar18 = (int ******)(int)cStack_289;
      uStack_244 = s_sureware_load_public_00674520._0_4_;
      uStack_240 = s_sureware_load_public_00674520._4_4_;
      uStack_23c = s_sureware_load_public_00674520._8_4_;
      uStack_238 = s_sureware_load_public_00674520._12_4_;
      uStack_234 = s_sureware_load_public_00674520._16_4_;
      cStack_230 = s_sureware_load_public_00674520[20];
      (*(code *)PTR_memset_006a99f4)(auStack_22f,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        ppppppiVar16 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
      }
      else if (ppppppiVar18 == (int ******)0x1) {
        iVar6 = (*(code *)PTR_RSA_new_method_006a772c)(iVar6);
        (*(code *)PTR_RSA_set_ex_data_006a953c)(iVar6,rsaHndidx,0);
        puVar2 = PTR_BN_new_006a71b4;
        *(uint *)(iVar6 + 0x3c) = *(uint *)(iVar6 + 0x3c) | 0x20;
        uVar8 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar6 + 0x14) = uVar8;
        iVar7 = (*(code *)puVar2)();
        *(int *)(iVar6 + 0x10) = iVar7;
        if ((*(int *)(iVar6 + 0x14) != 0) && (iVar7 != 0)) {
          uVar17 = uVar19 >> 2;
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar6 + 0x14),uVar17);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar6 + 0x10),uVar17);
          if ((uVar17 == (*(undefined4 **)(iVar6 + 0x14))[2]) &&
             (uVar17 == (*(undefined4 **)(iVar6 + 0x10))[2])) {
            iVar7 = (*p_surewarehk_Load_Rsa_Pubkey)
                              (&uStack_244,ppppppiVar13,uVar19,**(undefined4 **)(iVar6 + 0x10),
                               **(undefined4 **)(iVar6 + 0x14));
            surewarehk_error_handling(&uStack_244,0x6a,iVar7);
            if (iVar7 == 1) {
              piVar12 = *(int **)(iVar6 + 0x14);
              piVar12[1] = uVar17;
              if (uVar17 == 0) {
                *(undefined4 *)(*(int *)(iVar6 + 0x10) + 4) = 0;
              }
              else {
                iVar7 = (uVar19 & 0xfffffffc) - 4;
                piVar10 = (int *)(*piVar12 + iVar7);
                uVar19 = uVar17;
                do {
                  uVar11 = uVar19 - 1;
                  if (*piVar10 != 0) break;
                  piVar10 = piVar10 + -1;
                  uVar19 = uVar11;
                } while (uVar11 != 0);
                piVar10 = *(int **)(iVar6 + 0x10);
                piVar12[1] = uVar19;
                piVar10[1] = uVar17;
                piVar12 = (int *)(*piVar10 + iVar7);
                do {
                  uVar19 = uVar17 - 1;
                  if (*piVar12 != 0) break;
                  piVar12 = piVar12 + -1;
                  uVar17 = uVar19;
                } while (uVar19 != 0);
                piVar10[1] = uVar17;
              }
              ppppppiVar16 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a7620)();
              uVar8 = 6;
              goto LAB_005d7f4c;
            }
            if (SUREWARE_lib_error_code == 0) {
              SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            (*(code *)PTR_ERR_put_error_006a7f34)
                      (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2d8);
          }
        }
        ppppppiVar16 = (int ******)0x0;
        (*(code *)PTR_RSA_free_006a7600)(iVar6);
      }
      else if (ppppppiVar18 == (int ******)&SUB_00000002) {
        iVar6 = (*(code *)PTR_DSA_new_method_006a957c)(iVar6);
        (*(code *)PTR_DSA_set_ex_data_006a9580)(iVar6,dsaHndidx,0);
        uVar8 = (*(code *)PTR_BN_new_006a71b4)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar6 + 0x18) = uVar8;
        uVar8 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar6 + 0xc) = uVar8;
        uVar8 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar6 + 0x10) = uVar8;
        iVar7 = (*(code *)puVar2)();
        *(int *)(iVar6 + 0x14) = iVar7;
        if ((((*(int *)(iVar6 + 0x18) != 0) && (*(int *)(iVar6 + 0xc) != 0)) &&
            (*(int *)(iVar6 + 0x10) != 0)) && (iVar7 != 0)) {
          ppppppiVar16 = (int ******)(uVar19 >> 2);
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar6 + 0x18),ppppppiVar16);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar6 + 0xc),ppppppiVar16);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar6 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar6 + 0x14),ppppppiVar16);
          ppppppiVar18 = ppppppiVar16;
          if (((ppppppiVar16 == (int ******)(*(undefined4 **)(iVar6 + 0x18))[2]) &&
              (ppppppiVar16 == (int ******)(*(undefined4 **)(iVar6 + 0xc))[2])) &&
             (((*(undefined4 **)(iVar6 + 0x10))[2] == 5 &&
              (ppppppiVar16 == (int ******)(*(undefined4 **)(iVar6 + 0x14))[2])))) {
            iVar7 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_244,ppppppiVar13,uVar19,**(undefined4 **)(iVar6 + 0x18),
                               **(undefined4 **)(iVar6 + 0xc),**(undefined4 **)(iVar6 + 0x10),
                               **(undefined4 **)(iVar6 + 0x14));
            surewarehk_error_handling(&uStack_244,0x6a,iVar7);
            if (iVar7 == 1) {
              piVar12 = *(int **)(iVar6 + 0x18);
              piVar12[1] = (int)ppppppiVar16;
              if (ppppppiVar16 == (int ******)0x0) goto LAB_005d7f80;
              iVar7 = (uVar19 & 0xfffffffc) - 4;
              piVar10 = (int *)(*piVar12 + iVar7);
              ppppppiVar13 = ppppppiVar16;
              do {
                ppppppiVar14 = (int ******)((int)ppppppiVar13 + -1);
                if (*piVar10 != 0) break;
                piVar10 = piVar10 + -1;
                ppppppiVar13 = ppppppiVar14;
              } while (ppppppiVar14 != (int ******)0x0);
              piVar10 = *(int **)(iVar6 + 0xc);
              piVar12[1] = (int)ppppppiVar13;
              piVar10[1] = (int)ppppppiVar16;
              piVar12 = (int *)(*piVar10 + iVar7);
              ppppppiVar13 = ppppppiVar16;
              do {
                ppppppiVar14 = (int ******)((int)ppppppiVar13 + -1);
                if (*piVar12 != 0) break;
                piVar12 = piVar12 + -1;
                ppppppiVar13 = ppppppiVar14;
              } while (ppppppiVar14 != (int ******)0x0);
              piVar10[1] = (int)ppppppiVar13;
              goto LAB_005d7dc4;
            }
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
          }
        }
        ppppppiVar16 = (int ******)0x0;
        (*(code *)PTR_DSA_free_006a7530)(iVar6);
      }
      else {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        ppppppiVar16 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
      }
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      ppppppiVar16 = (int ******)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      (*(code *)PTR_ERR_add_error_data_006a813c)(1,&uStack_284);
    }
  }
  do {
    if (iStack_204 == *(int *)puVar3) {
      return ppppppiVar16;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005d7f80:
    *(undefined4 *)(*(int *)(iVar6 + 0xc) + 4) = 0;
LAB_005d7dc4:
    piVar12 = *(int **)(iVar6 + 0x10);
    iVar9 = 5;
    piVar12[1] = 5;
    iVar7 = *piVar12 + 0xc;
    do {
      if (*(int *)(iVar7 + 4) != 0) break;
      iVar9 = iVar9 + -1;
      iVar7 = iVar7 + -4;
    } while (iVar9 != 0);
    piVar10 = *(int **)(iVar6 + 0x14);
    piVar12[1] = iVar9;
    piVar10[1] = (int)ppppppiVar16;
    if (0 < (int)ppppppiVar16) {
      iVar7 = *piVar10 + (int)ppppppiVar16 * 4 + -8;
      do {
        if (*(int *)(iVar7 + 4) != 0) break;
        ppppppiVar18 = (int ******)((int)ppppppiVar18 + -1);
        iVar7 = iVar7 + -4;
      } while (ppppppiVar18 != (int ******)0x0);
      piVar10[1] = (int)ppppppiVar18;
    }
    ppppppiVar16 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a7620)();
    uVar8 = 0x74;
LAB_005d7f4c:
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(ppppppiVar16,uVar8,iVar6);
  } while( true );
}

