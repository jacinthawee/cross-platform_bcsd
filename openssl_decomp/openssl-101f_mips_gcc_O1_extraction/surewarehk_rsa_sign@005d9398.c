
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
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  int ******ppppppiVar12;
  uint uVar13;
  int *piVar14;
  char *pcVar15;
  undefined4 *puVar16;
  undefined1 *puVar17;
  uint uVar18;
  undefined4 unaff_s4;
  uint uVar19;
  uint uVar20;
  code *pcVar21;
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
  uint uStack_1e8;
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
  uint uStack_16c;
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
  int ******ppppppiStack_120;
  int *****pppppiStack_11c;
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
  uint uStack_bc;
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
  
  puStack_b4 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
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
  local_64 = s_ENGINE_rsa_sign_00674d70._0_4_;
  local_60 = s_ENGINE_rsa_sign_00674d70._4_4_;
  local_5c = s_ENGINE_rsa_sign_00674d70._8_4_;
  local_58 = s_ENGINE_rsa_sign_00674d70._12_4_;
  ppiStack_ac = param_3;
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    ppppppiStack_b8 = (int ******)&_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppppppiStack_120 = (int ******)0x75;
    pcVar5 = "e_sureware.c";
    local_80 = (int **)0x3ad;
    piStack_1f8 = (int *)&DAT_0000006f;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code);
    ppppppiVar12 = (int ******)0x0;
  }
  else {
    puVar4 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006aa640)(param_4,rsaHndidx);
    unaff_s4 = param_1;
    if (puVar4 == (undefined4 *)0x0) {
      ppppppiStack_b8 = (int ******)&_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      ppppppiStack_120 = (int ******)&DAT_00000069;
      pcVar5 = "e_sureware.c";
      local_80 = (int **)0x3b2;
      piStack_1f8 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code);
      ppppppiVar12 = (int ******)0x0;
    }
    else if (param_5 == (undefined4 *)0x1) {
      pcVar5 = (char *)&local_68;
      local_78 = param_5;
      ppppppiStack_b8 = (int ******)(*p_surewarehk_Rsa_Sign)(&local_64,param_1,param_2);
      piStack_1f8 = (int *)&DAT_0000006f;
      ppppppiStack_120 = ppppppiStack_b8;
      surewarehk_error_handling(&local_64);
      ppppppiVar12 = ppppppiStack_b8;
      ppiStack_ac = &local_64;
      local_80 = param_3;
      local_7c = puVar4;
      if (ppppppiStack_b8 == (int ******)0x1) {
        ppppppiVar12 = local_68;
      }
    }
    else {
      ppppppiStack_b8 = (int ******)&_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      ppppppiStack_120 = (int ******)&DAT_0000006b;
      pcVar5 = "e_sureware.c";
      local_80 = (int **)0x3be;
      piStack_1f8 = (int *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code);
      ppppppiVar12 = (int ******)0x0;
    }
  }
  if (local_24 == *(int *)puStack_b4) {
    return ppppppiVar12;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_15c = PTR___stack_chk_guard_006aabf0;
  pcStack_1e4 = "7 datafinal";
  ppiStack_118 = local_80;
  puStack_b0 = param_5;
  ppppppiStack_160 = &pppppiStack_110;
  puStack_114 = local_7c;
  ppppppiStack_158 = apppppiStack_ee;
  puStack_128 = &_gp;
  pppppiStack_11c = pppppiStack_74;
  uStack_bc = *(uint *)PTR___stack_chk_guard_006aabf0;
  uStack_a8 = unaff_s4;
  uStack_a4 = param_2;
  (*(code *)PTR_BN_init_006a96a0)(ppppppiStack_160);
  ppppppiStack_1ec = (int ******)0x32;
  pppppiStack_fc = (int *****)DAT_00674c1c;
  uStack_f8 = DAT_00674c20;
  puStack_f4 = DAT_00674c24;
  uStack_f0 = DAT_00674c28;
  pcVar15 = (char *)DAT_00674c24;
  (**(code **)(puStack_128 + -0x53e0))(ppppppiStack_158,0);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_005d98a8:
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x589c))();
    }
    ppppppiStack_1ec = (int ******)0x75;
    pcVar15 = "e_sureware.c";
    pppppiStack_138 = (int *****)0x403;
    piVar11 = (int *)&DAT_0000006b;
    (**(code **)(puStack_128 + -0x6eb0))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
LAB_005d96e0:
    piStack_1f8 = piVar11;
    ppppppiStack_168 = (int ******)0x0;
    ppppppiStack_154 = (int ******)pcVar5;
  }
  else {
    piVar11 = (int *)local_78[1];
    (**(code **)(puStack_128 + -0x6860))(piStack_1f8);
    if ((piStack_1f8 == (int *)0x0) ||
       (piVar11 = (int *)piStack_1f8[2], ppppppiStack_1ec = ppppppiStack_120,
       piVar11 != (int *)local_78[1])) goto LAB_005d96e0;
    pppppiStack_138 = *(int ******)pcVar5;
    pppppiStack_12c = (int *****)*piStack_1f8;
    pcVar15 = (char *)((int)*(int ******)((int)pcVar5 + 4) << 2);
    pppppiStack_130 = *ppppppiStack_120;
    iStack_134 = (int)ppppppiStack_120[1] << 2;
    ppppppiStack_120 = &pppppiStack_fc;
    pcVar5 = (char *)(*p_surewarehk_Mod_Exp)(&pppppiStack_fc,(int)piVar11 << 2,*local_78,pcVar15);
    piVar11 = (int *)&DAT_0000006b;
    ppppppiStack_1ec = (int ******)pcVar5;
    surewarehk_error_handling(ppppppiStack_120);
    if ((int ******)pcVar5 == (int ******)0x1) {
      iVar6 = local_78[1];
      piStack_1f8[1] = iVar6;
      if (0 < iVar6) {
        iVar9 = *piStack_1f8 + iVar6 * 4 + -8;
        do {
          if (*(int *)(iVar9 + 4) != 0) break;
          iVar6 = iVar6 + -1;
          iVar9 = iVar9 + -4;
        } while (iVar6 != 0);
        piStack_1f8[1] = iVar6;
      }
    }
    else if ((int ******)pcVar5 == (int ******)0x0) goto LAB_005d96e0;
    ppppppiStack_1ec = (int ******)0x32;
    pppppiStack_fc = (int *****)DAT_00674c1c;
    uStack_f8 = DAT_00674c20;
    puStack_f4 = DAT_00674c24;
    uStack_f0 = DAT_00674c28;
    pcVar15 = (char *)DAT_00674c24;
    (**(code **)(puStack_128 + -0x53e0))(ppppppiStack_158,0);
    if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_005d98a8;
    (**(code **)(puStack_128 + -0x6860))(ppppppiStack_160,local_78[1]);
    ppppppiStack_154 = ppppppiStack_120;
    piVar11 = piStack_108;
    if (piStack_108 != (int *)local_78[1]) goto LAB_005d96e0;
    pppppiStack_130 = (int *****)*ppiStack_118;
    iStack_134 = (int)ppiStack_118[1] << 2;
    pppppiStack_138 = (int *****)*puStack_114;
    pcVar15 = (char *)(puStack_114[1] << 2);
    pppppiStack_12c = pppppiStack_110;
    ppppppiStack_158 =
         (int ******)
         (*p_surewarehk_Mod_Exp)(ppppppiStack_120,(int)piStack_108 << 2,*local_78,pcVar15);
    piVar11 = (int *)&DAT_0000006b;
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
      if (ppppppiStack_158 == (int ******)0x0) goto LAB_005d96e0;
    }
    pppppiStack_138 = pppppiStack_11c;
    ppppppiStack_1ec = ppppppiStack_160;
    pcVar15 = (char *)local_78;
    iVar6 = (**(code **)(puStack_128 + -0x6848))(piStack_1f8,piStack_1f8,ppppppiStack_160,local_78);
    ppppppiStack_168 = (int ******)(uint)(iVar6 != 0);
  }
  (**(code **)(puStack_128 + -0x7dc4))(ppppppiStack_160);
  if (uStack_bc == *(uint *)puStack_15c) {
    return ppppppiStack_168;
  }
  pcStack_14c = surewarehk_rsa_priv_dec;
  uVar19 = uStack_bc;
  (**(code **)(puStack_128 + -0x5328))();
  pppppiStack_1f0 = pppppiStack_138;
  puStack_1f4 = PTR___stack_chk_guard_006aabf0;
  puStack_164 = local_78;
  uStack_16c = *(uint *)PTR___stack_chk_guard_006aabf0;
  pcStack_150 = "7 datafinal";
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
  iStack_1ac = s_ENGINE_rsa_priv_dec_00674db0._0_4_;
  uStack_1a8 = s_ENGINE_rsa_priv_dec_00674db0._4_4_;
  uStack_1a4 = s_ENGINE_rsa_priv_dec_00674db0._8_4_;
  uStack_1a0 = s_ENGINE_rsa_priv_dec_00674db0._12_4_;
  uStack_19c = s_ENGINE_rsa_priv_dec_00674db0._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppppppiStack_1c8 = (int ******)0x366;
    (**(code **)(puStack_1b8 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
    iVar6 = 0;
  }
  else {
    iVar6 = (*(code *)PTR_RSA_get_ex_data_006aa640)(pcVar15,rsaHndidx);
    if (iVar6 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_1b8 + -0x589c))();
      }
      ppppppiStack_1c8 = (int ******)0x36b;
      ppppppiVar12 = (int ******)&DAT_0000006e;
      ppppppiStack_1fc = (int ******)0x0;
      (**(code **)(puStack_1b8 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d9aa0;
    }
  }
  pcStack_1e4 = (char *)0x1;
  ppppppiStack_1c8 = ppppppiStack_1ec;
  iStack_1c4 = iVar6;
  if (pppppiStack_1f0 == (int *****)0x1) {
    pppppiStack_1c0 = pppppiStack_1f0;
    ppppppiStack_1fc =
         (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_1ac,uVar19,piStack_1f8,&ppppppiStack_1b0);
    ppppppiVar12 = (int ******)&DAT_0000006e;
    surewarehk_error_handling(&iStack_1ac,0x6e,ppppppiStack_1fc);
    piStack_1f8 = &iStack_1ac;
    if (ppppppiStack_1fc == (int ******)0x1) {
      ppppppiStack_1fc = ppppppiStack_1b0;
    }
    goto LAB_005d9aa0;
  }
  pppppiStack_1c0 = (int *****)0x0;
  ppppppiStack_1fc = (int ******)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_1ac,uVar19,piStack_1f8);
  ppppppiVar12 = (int ******)&DAT_0000006e;
  surewarehk_error_handling(&iStack_1ac,0x6e,ppppppiStack_1fc);
  piStack_1f8 = &iStack_1ac;
  if (ppppppiStack_1fc != (int ******)0x1) goto LAB_005d9aa0;
  pcStack_1e4 = "7 datafinal";
  piStack_1f8 = (int *)(**(code **)(puStack_1b8 + -0x7dd8))(ppppppiStack_1b0,"e_sureware.c",0x37f);
  if (piStack_1f8 == (int *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_1b8 + -0x589c))();
    }
    ppppppiVar12 = (int ******)&DAT_0000006e;
    ppppppiStack_1c8 = (int ******)0x381;
    (**(code **)(puStack_1b8 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    piStack_1f8 = (int *)&_ITM_registerTMCloneTable;
    goto LAB_005d9aa0;
  }
  (**(code **)(puStack_1b8 + -0x52ec))(piStack_1f8,ppppppiStack_1ec,ppppppiStack_1b0);
  if (pppppiStack_1f0 == (int *****)0x3) {
    pcVar21 = *(code **)(puStack_1b8 + -0x66d4);
LAB_005d9d0c:
    ppppppiStack_1c8 = ppppppiStack_1b0;
    ppppppiStack_1fc = (int ******)(*pcVar21)(ppppppiStack_1ec,ppppppiStack_1b0,piStack_1f8,uVar19);
LAB_005d9cac:
    pcVar21 = *(code **)(puStack_1b8 + -0x7d6c);
    if ((int)ppppppiStack_1fc < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_1b8 + -0x589c))();
      }
      ppppppiStack_1c8 = (int ******)0x397;
      (**(code **)(puStack_1b8 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d9c04;
    }
  }
  else {
    if (pppppiStack_1f0 == (int *****)0x4) {
      pppppiStack_1c0 = (int *****)0x0;
      iStack_1c4 = 0;
      ppppppiStack_1c8 = ppppppiStack_1b0;
      ppppppiStack_1fc =
           (int ******)
           (**(code **)(puStack_1b8 + -0x66ac))(ppppppiStack_1ec,ppppppiStack_1b0,piStack_1f8);
      goto LAB_005d9cac;
    }
    bVar1 = pppppiStack_1f0 == (int *****)0x2;
    pppppiStack_1f0 = (int *****)&_ITM_registerTMCloneTable;
    if (bVar1) {
      pcVar21 = *(code **)(puStack_1b8 + -0x66a4);
      goto LAB_005d9d0c;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_1b8 + -0x589c))();
    }
    ppppppiStack_1c8 = (int ******)0x393;
    (**(code **)(puStack_1b8 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d9c04:
    pppppiStack_1f0 = (int *****)&_ITM_registerTMCloneTable;
    pcVar21 = *(code **)(puStack_1b8 + -0x7d6c);
  }
  (*pcVar21)(piStack_1f8,ppppppiStack_1b0);
  (**(code **)(puStack_1b8 + -0x7f58))(piStack_1f8);
  ppppppiVar12 = ppppppiStack_1b0;
LAB_005d9aa0:
  if (uStack_16c == *(uint *)puStack_1f4) {
    return ppppppiStack_1fc;
  }
  pcStack_1dc = surewarehk_load_pubkey;
  uVar20 = uStack_16c;
  (**(code **)(puStack_1b8 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_204 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppppiStack_1e0 = &DAT_00674c1c;
  uStack_288 = 0;
  cStack_289 = '\0';
  uStack_284 = s_ENGINE_load_pubkey_00674df0._0_4_;
  uStack_280 = s_ENGINE_load_pubkey_00674df0._4_4_;
  uStack_27c = s_ENGINE_load_pubkey_00674df0._8_4_;
  uStack_278 = s_ENGINE_load_pubkey_00674df0._12_4_;
  uStack_274 = s_ENGINE_load_pubkey_00674df0._16_2_;
  cStack_272 = s_ENGINE_load_pubkey_00674df0[18];
  uStack_1e8 = uVar19;
  (*(code *)PTR_memset_006aab00)(auStack_271,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    puVar17 = &_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    ppppppiVar12 = (int ******)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x32c);
  }
  else {
    iVar6 = (*p_surewarehk_Info_Pubkey)(&uStack_284,ppppppiVar12,&uStack_288,&cStack_289);
    uVar13 = uStack_288;
    if (iVar6 == 1) {
      uVar19 = (uint)cStack_289;
      uStack_244 = s_sureware_load_public_00674e30._0_4_;
      uStack_240 = s_sureware_load_public_00674e30._4_4_;
      uStack_23c = s_sureware_load_public_00674e30._8_4_;
      uStack_238 = s_sureware_load_public_00674e30._12_4_;
      uStack_234 = s_sureware_load_public_00674e30._16_4_;
      cStack_230 = s_sureware_load_public_00674e30[20];
      (*(code *)PTR_memset_006aab00)(auStack_22f,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        puVar17 = &_ITM_registerTMCloneTable;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        ppppppiVar12 = (int ******)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)
                  (SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",0x299);
      }
      else if (uVar19 == 1) {
        uVar18 = uVar13 >> 2;
        puVar17 = (undefined1 *)(*(code *)PTR_RSA_new_method_006a881c)(uVar20);
        (*(code *)PTR_RSA_set_ex_data_006aa648)(puVar17,rsaHndidx,0);
        puVar2 = PTR_BN_new_006a82b4;
        *(uint *)(puVar17 + 0x3c) = *(uint *)(puVar17 + 0x3c) | 0x20;
        uVar7 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a82b4;
        *(undefined4 *)(puVar17 + 0x14) = uVar7;
        uVar7 = (*(code *)puVar2)();
        puVar2 = PTR_bn_expand2_006a9680;
        *(undefined4 *)(puVar17 + 0x10) = uVar7;
        (*(code *)puVar2)(*(undefined4 *)(puVar17 + 0x14),uVar18);
        (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar17 + 0x10),uVar18);
        puVar4 = *(undefined4 **)(puVar17 + 0x14);
        if ((((puVar4 != (undefined4 *)0x0) && (uVar18 == puVar4[2])) &&
            (puVar8 = *(undefined4 **)(puVar17 + 0x10), puVar8 != (undefined4 *)0x0)) &&
           (uVar18 == puVar8[2])) {
          iVar6 = (*p_surewarehk_Load_Rsa_Pubkey)(&uStack_244,ppppppiVar12,uVar13,*puVar8,*puVar4);
          surewarehk_error_handling(&uStack_244,0x6a,iVar6);
          if (iVar6 == 1) {
            piVar11 = *(int **)(puVar17 + 0x14);
            piVar11[1] = uVar18;
            if (uVar18 == 0) {
              *(undefined4 *)(*(int *)(puVar17 + 0x10) + 4) = 0;
            }
            else {
              iVar6 = (uVar13 & 0xfffffffc) - 4;
              piVar14 = (int *)(*piVar11 + iVar6);
              uVar20 = uVar18;
              do {
                uVar13 = uVar20 - 1;
                if (*piVar14 != 0) break;
                piVar14 = piVar14 + -1;
                uVar20 = uVar13;
              } while (uVar13 != 0);
              piVar14 = *(int **)(puVar17 + 0x10);
              piVar11[1] = uVar20;
              piVar14[1] = uVar18;
              piVar11 = (int *)(*piVar14 + iVar6);
              uVar20 = uVar18;
              do {
                uVar13 = uVar20 - 1;
                if (*piVar11 != 0) break;
                piVar11 = piVar11 + -1;
                uVar20 = uVar13;
              } while (uVar13 != 0);
              piVar14[1] = uVar20;
            }
            ppppppiVar12 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a8710)();
            uVar7 = 6;
            goto LAB_005da414;
          }
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2b3);
        }
        ppppppiVar12 = (int ******)0x0;
        (*(code *)PTR_RSA_free_006a86f0)(puVar17);
        uVar20 = uVar18;
      }
      else {
        puVar17 = &_ITM_registerTMCloneTable;
        if (uVar19 == 2) {
          uVar18 = uVar13 >> 2;
          puVar17 = (undefined1 *)(*(code *)PTR_DSA_new_method_006aa688)(uVar20);
          (*(code *)PTR_DSA_set_ex_data_006aa68c)(puVar17,dsaHndidx,0);
          uVar7 = (*(code *)PTR_BN_new_006a82b4)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar17 + 0x18) = uVar7;
          uVar7 = (*(code *)puVar2)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar17 + 0xc) = uVar7;
          uVar7 = (*(code *)puVar2)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar17 + 0x10) = uVar7;
          uVar7 = (*(code *)puVar2)();
          puVar2 = PTR_bn_expand2_006a9680;
          *(undefined4 *)(puVar17 + 0x14) = uVar7;
          (*(code *)puVar2)(*(undefined4 *)(puVar17 + 0x18),uVar18);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar17 + 0xc),uVar18);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar17 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar17 + 0x14),uVar18);
          puVar4 = *(undefined4 **)(puVar17 + 0x18);
          uVar19 = uVar18;
          if ((((puVar4 != (undefined4 *)0x0) && (uVar18 == puVar4[2])) &&
              (puVar8 = *(undefined4 **)(puVar17 + 0xc), puVar8 != (undefined4 *)0x0)) &&
             (((uVar18 == puVar8[2] &&
               (puVar16 = *(undefined4 **)(puVar17 + 0x10), puVar16 != (undefined4 *)0x0)) &&
              ((puVar16[2] == 5 &&
               ((puVar10 = *(undefined4 **)(puVar17 + 0x14), puVar10 != (undefined4 *)0x0 &&
                (uVar18 == puVar10[2])))))))) {
            iVar6 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_244,ppppppiVar12,uVar13,*puVar4,*puVar8,*puVar16,*puVar10);
            surewarehk_error_handling(&uStack_244,0x6a,iVar6);
            if (iVar6 == 1) goto LAB_005da448;
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x2df);
          }
          ppppppiVar12 = (int ******)0x0;
          (*(code *)PTR_DSA_free_006a862c)(puVar17);
          uVar20 = uVar18;
        }
        else {
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          ppppppiVar12 = (int ******)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",0x2f4);
        }
      }
    }
    else {
      puVar17 = &_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      ppppppiVar12 = (int ******)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x334);
      (*(code *)PTR_ERR_add_error_data_006a9264)(1,&uStack_284);
    }
  }
  do {
    if (iStack_204 == *(int *)puVar3) {
      return ppppppiVar12;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar18 = uVar20;
LAB_005da448:
    piVar11 = *(int **)(puVar17 + 0x18);
    piVar11[1] = uVar18;
    if ((int)uVar18 < 1) {
      *(undefined4 *)(*(int *)(puVar17 + 0xc) + 4) = 0;
    }
    else {
      iVar6 = uVar18 * 4 + -4;
      piVar14 = (int *)(*piVar11 + iVar6);
      uVar20 = uVar18;
      do {
        uVar13 = uVar20 - 1;
        if (*piVar14 != 0) break;
        piVar14 = piVar14 + -1;
        uVar20 = uVar13;
      } while (uVar13 != 0);
      piVar14 = *(int **)(puVar17 + 0xc);
      piVar11[1] = uVar20;
      piVar14[1] = uVar18;
      piVar11 = (int *)(*piVar14 + iVar6);
      uVar20 = uVar18;
      do {
        uVar13 = uVar20 - 1;
        if (*piVar11 != 0) break;
        piVar11 = piVar11 + -1;
        uVar20 = uVar13;
      } while (uVar13 != 0);
      piVar14[1] = uVar20;
    }
    piVar14 = *(int **)(puVar17 + 0x10);
    iVar6 = 5;
    piVar14[1] = 5;
    piVar11 = (int *)(*piVar14 + 0x10);
    do {
      if (*piVar11 != 0) break;
      iVar6 = iVar6 + -1;
      piVar11 = piVar11 + -1;
    } while (iVar6 != 0);
    piVar11 = *(int **)(puVar17 + 0x14);
    piVar14[1] = iVar6;
    piVar11[1] = uVar18;
    if (0 < (int)uVar18) {
      piVar14 = (int *)(*piVar11 + uVar18 * 4 + -4);
      do {
        uVar20 = uVar19 - 1;
        if (*piVar14 != 0) break;
        piVar14 = piVar14 + -1;
        uVar19 = uVar20;
      } while (uVar20 != 0);
      piVar11[1] = uVar19;
    }
    ppppppiVar12 = (int ******)(*(code *)PTR_EVP_PKEY_new_006a8710)();
    uVar7 = 0x74;
LAB_005da414:
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(ppppppiVar12,uVar7,puVar17);
    uVar20 = uVar18;
  } while( true );
}

