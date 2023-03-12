
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int * surewarehk_dsa_mod_exp
                (undefined4 param_1,int *param_2,int *param_3,int *param_4,int *param_5,
                undefined4 *param_6,undefined4 *param_7,undefined1 *param_8)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  uint uVar11;
  int *piVar12;
  char *pcVar13;
  undefined4 *puVar14;
  undefined1 *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  code *pcVar19;
  char cStack_1f9;
  uint uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined2 uStack_1e4;
  char cStack_1e2;
  undefined auStack_1e1 [45];
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  char cStack_1a0;
  undefined auStack_19f [43];
  int iStack_174;
  int *piStack_16c;
  int *piStack_168;
  undefined *puStack_164;
  undefined1 *puStack_160;
  int *piStack_15c;
  uint uStack_158;
  char *pcStack_154;
  int *piStack_150;
  code *pcStack_14c;
  int *piStack_138;
  int iStack_134;
  undefined1 *puStack_130;
  undefined *puStack_128;
  int *piStack_120;
  int iStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  uint uStack_dc;
  int *piStack_d8;
  undefined4 *puStack_d4;
  int *piStack_d0;
  undefined *puStack_cc;
  int *piStack_c8;
  int *piStack_c4;
  char *pcStack_c0;
  code *pcStack_bc;
  undefined1 *local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  undefined *local_98;
  int *local_90;
  undefined1 *local_8c;
  int *local_88;
  undefined4 *local_84;
  int local_80;
  int local_7c;
  int *local_78;
  int local_6c;
  undefined4 local_68;
  undefined4 *local_64;
  undefined2 local_60;
  int aiStack_5e [12];
  uint local_2c;
  
  puStack_cc = PTR___stack_chk_guard_006aabf0;
  pcStack_154 = "7 datafinal";
  local_88 = param_5;
  piStack_d0 = &local_80;
  local_84 = param_6;
  piStack_c8 = aiStack_5e;
  local_98 = &_gp;
  local_8c = param_8;
  local_2c = *(uint *)PTR___stack_chk_guard_006aabf0;
  local_90 = param_3;
  (*(code *)PTR_BN_init_006a96a0)(piStack_d0);
  piStack_15c = (int *)0x32;
  local_6c = DAT_00674c1c;
  local_68 = DAT_00674c20;
  local_64 = DAT_00674c24;
  local_60 = DAT_00674c28;
  pcVar13 = (char *)DAT_00674c24;
  (**(code **)(local_98 + -0x53e0))(piStack_c8,0);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_005d98a8:
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(local_98 + -0x589c))();
    }
    piStack_15c = (int *)0x75;
    pcVar13 = "e_sureware.c";
    local_a8 = (undefined1 *)0x403;
    piVar10 = (int *)&DAT_0000006b;
    (**(code **)(local_98 + -0x6eb0))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
LAB_005d96e0:
    param_2 = piVar10;
    piStack_d8 = (int *)0x0;
    piStack_c4 = param_4;
  }
  else {
    piVar10 = (int *)param_7[1];
    (**(code **)(local_98 + -0x6860))(param_2);
    if ((param_2 == (int *)0x0) ||
       (piVar10 = (int *)param_2[2], piStack_15c = local_90, piVar10 != (int *)param_7[1]))
    goto LAB_005d96e0;
    local_a8 = (undefined1 *)*param_4;
    local_9c = *param_2;
    pcVar13 = (char *)(param_4[1] << 2);
    local_a0 = *local_90;
    local_a4 = local_90[1] << 2;
    local_90 = &local_6c;
    param_4 = (int *)(*p_surewarehk_Mod_Exp)(&local_6c,(int)piVar10 << 2,*param_7,pcVar13);
    piVar10 = (int *)&DAT_0000006b;
    piStack_15c = param_4;
    surewarehk_error_handling(local_90);
    if (param_4 == (int *)0x1) {
      iVar4 = param_7[1];
      param_2[1] = iVar4;
      if (0 < iVar4) {
        iVar8 = *param_2 + iVar4 * 4 + -8;
        do {
          if (*(int *)(iVar8 + 4) != 0) break;
          iVar4 = iVar4 + -1;
          iVar8 = iVar8 + -4;
        } while (iVar4 != 0);
        param_2[1] = iVar4;
      }
    }
    else if (param_4 == (int *)0x0) goto LAB_005d96e0;
    piStack_15c = (int *)0x32;
    local_6c = DAT_00674c1c;
    local_68 = DAT_00674c20;
    local_64 = DAT_00674c24;
    local_60 = DAT_00674c28;
    pcVar13 = (char *)DAT_00674c24;
    (**(code **)(local_98 + -0x53e0))(piStack_c8,0);
    if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_005d98a8;
    (**(code **)(local_98 + -0x6860))(piStack_d0,param_7[1]);
    piStack_c4 = local_90;
    piVar10 = local_78;
    if (local_78 != (int *)param_7[1]) goto LAB_005d96e0;
    local_a0 = *local_88;
    local_a4 = local_88[1] << 2;
    local_a8 = (undefined1 *)*local_84;
    pcVar13 = (char *)(local_84[1] << 2);
    local_9c = local_80;
    piStack_c8 = (int *)(*p_surewarehk_Mod_Exp)(local_90,(int)local_78 << 2,*param_7,pcVar13);
    piVar10 = (int *)&DAT_0000006b;
    piStack_15c = piStack_c8;
    surewarehk_error_handling(piStack_c4);
    if (piStack_c8 == (int *)0x1) {
      local_7c = param_7[1];
      if (0 < local_7c) {
        iVar4 = local_80 + local_7c * 4 + -8;
        do {
          if (*(int *)(iVar4 + 4) != 0) break;
          local_7c = local_7c + -1;
          iVar4 = iVar4 + -4;
        } while (local_7c != 0);
      }
    }
    else {
      param_4 = piStack_c4;
      if (piStack_c8 == (int *)0x0) goto LAB_005d96e0;
    }
    local_a8 = local_8c;
    piStack_15c = piStack_d0;
    pcVar13 = (char *)param_7;
    iVar4 = (**(code **)(local_98 + -0x6848))(param_2,param_2,piStack_d0,param_7);
    piStack_d8 = (int *)(uint)(iVar4 != 0);
  }
  (**(code **)(local_98 + -0x7dc4))(piStack_d0);
  if (local_2c == *(uint *)puStack_cc) {
    return piStack_d8;
  }
  pcStack_bc = surewarehk_rsa_priv_dec;
  uVar17 = local_2c;
  (**(code **)(local_98 + -0x5328))();
  puStack_160 = local_a8;
  puStack_164 = PTR___stack_chk_guard_006aabf0;
  puStack_d4 = param_7;
  uStack_dc = *(uint *)PTR___stack_chk_guard_006aabf0;
  pcStack_c0 = "7 datafinal";
  puStack_128 = &_gp;
  uStack_108 = 0;
  uStack_104 = 0;
  uStack_100 = 0;
  uStack_fc = 0;
  uStack_f8 = 0;
  uStack_f4 = 0;
  uStack_f0 = 0;
  uStack_ec = 0;
  uStack_e8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  iStack_11c = s_ENGINE_rsa_priv_dec_00674db0._0_4_;
  uStack_118 = s_ENGINE_rsa_priv_dec_00674db0._4_4_;
  uStack_114 = s_ENGINE_rsa_priv_dec_00674db0._8_4_;
  uStack_110 = s_ENGINE_rsa_priv_dec_00674db0._12_4_;
  uStack_10c = s_ENGINE_rsa_priv_dec_00674db0._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    piStack_138 = (int *)0x366;
    (**(code **)(puStack_128 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
    iVar4 = 0;
  }
  else {
    iVar4 = (*(code *)PTR_RSA_get_ex_data_006aa640)(pcVar13,rsaHndidx);
    if (iVar4 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x589c))();
      }
      piStack_138 = (int *)0x36b;
      piVar10 = (int *)&DAT_0000006e;
      piStack_16c = (int *)0x0;
      (**(code **)(puStack_128 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d9aa0;
    }
  }
  pcStack_154 = (char *)0x1;
  piStack_138 = piStack_15c;
  iStack_134 = iVar4;
  if (puStack_160 == (undefined1 *)0x1) {
    puStack_130 = puStack_160;
    piStack_16c = (int *)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_11c,uVar17,param_2,&piStack_120);
    piVar10 = (int *)&DAT_0000006e;
    surewarehk_error_handling(&iStack_11c,0x6e,piStack_16c);
    param_2 = &iStack_11c;
    if (piStack_16c == (int *)0x1) {
      piStack_16c = piStack_120;
    }
    goto LAB_005d9aa0;
  }
  puStack_130 = (undefined1 *)0x0;
  piStack_16c = (int *)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_11c,uVar17,param_2);
  piVar10 = (int *)&DAT_0000006e;
  surewarehk_error_handling(&iStack_11c,0x6e,piStack_16c);
  param_2 = &iStack_11c;
  if (piStack_16c != (int *)0x1) goto LAB_005d9aa0;
  pcStack_154 = "7 datafinal";
  param_2 = (int *)(**(code **)(puStack_128 + -0x7dd8))(piStack_120,"e_sureware.c",0x37f);
  if (param_2 == (int *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x589c))();
    }
    piVar10 = (int *)&DAT_0000006e;
    piStack_138 = (int *)0x381;
    (**(code **)(puStack_128 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    param_2 = (int *)&_ITM_registerTMCloneTable;
    goto LAB_005d9aa0;
  }
  (**(code **)(puStack_128 + -0x52ec))(param_2,piStack_15c,piStack_120);
  if (puStack_160 == (undefined1 *)0x3) {
    pcVar19 = *(code **)(puStack_128 + -0x66d4);
LAB_005d9d0c:
    piStack_138 = piStack_120;
    piStack_16c = (int *)(*pcVar19)(piStack_15c,piStack_120,param_2,uVar17);
LAB_005d9cac:
    pcVar19 = *(code **)(puStack_128 + -0x7d6c);
    if ((int)piStack_16c < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x589c))();
      }
      piStack_138 = (int *)0x397;
      (**(code **)(puStack_128 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d9c04;
    }
  }
  else {
    if (puStack_160 == (undefined1 *)0x4) {
      puStack_130 = (undefined1 *)0x0;
      iStack_134 = 0;
      piStack_138 = piStack_120;
      piStack_16c = (int *)(**(code **)(puStack_128 + -0x66ac))(piStack_15c,piStack_120,param_2);
      goto LAB_005d9cac;
    }
    bVar1 = puStack_160 == (undefined1 *)0x2;
    puStack_160 = &_ITM_registerTMCloneTable;
    if (bVar1) {
      pcVar19 = *(code **)(puStack_128 + -0x66a4);
      goto LAB_005d9d0c;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x589c))();
    }
    piStack_138 = (int *)0x393;
    (**(code **)(puStack_128 + -0x6eb0))(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d9c04:
    puStack_160 = &_ITM_registerTMCloneTable;
    pcVar19 = *(code **)(puStack_128 + -0x7d6c);
  }
  (*pcVar19)(param_2,piStack_120);
  (**(code **)(puStack_128 + -0x7f58))(param_2);
  piVar10 = piStack_120;
LAB_005d9aa0:
  if (uStack_dc == *(uint *)puStack_164) {
    return piStack_16c;
  }
  pcStack_14c = surewarehk_load_pubkey;
  uVar18 = uStack_dc;
  (**(code **)(puStack_128 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_174 = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_150 = &DAT_00674c1c;
  uStack_1f8 = 0;
  cStack_1f9 = '\0';
  uStack_1f4 = s_ENGINE_load_pubkey_00674df0._0_4_;
  uStack_1f0 = s_ENGINE_load_pubkey_00674df0._4_4_;
  uStack_1ec = s_ENGINE_load_pubkey_00674df0._8_4_;
  uStack_1e8 = s_ENGINE_load_pubkey_00674df0._12_4_;
  uStack_1e4 = s_ENGINE_load_pubkey_00674df0._16_2_;
  cStack_1e2 = s_ENGINE_load_pubkey_00674df0[18];
  piStack_168 = param_2;
  uStack_158 = uVar17;
  (*(code *)PTR_memset_006aab00)(auStack_1e1,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    puVar15 = &_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    piVar10 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x32c);
  }
  else {
    iVar4 = (*p_surewarehk_Info_Pubkey)(&uStack_1f4,piVar10,&uStack_1f8,&cStack_1f9);
    uVar11 = uStack_1f8;
    if (iVar4 == 1) {
      uVar17 = (uint)cStack_1f9;
      uStack_1b4 = s_sureware_load_public_00674e30._0_4_;
      uStack_1b0 = s_sureware_load_public_00674e30._4_4_;
      uStack_1ac = s_sureware_load_public_00674e30._8_4_;
      uStack_1a8 = s_sureware_load_public_00674e30._12_4_;
      uStack_1a4 = s_sureware_load_public_00674e30._16_4_;
      cStack_1a0 = s_sureware_load_public_00674e30[20];
      (*(code *)PTR_memset_006aab00)(auStack_19f,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        puVar15 = &_ITM_registerTMCloneTable;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        piVar10 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)
                  (SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",0x299);
      }
      else if (uVar17 == 1) {
        uVar16 = uVar11 >> 2;
        puVar15 = (undefined1 *)(*(code *)PTR_RSA_new_method_006a881c)(uVar18);
        (*(code *)PTR_RSA_set_ex_data_006aa648)(puVar15,rsaHndidx,0);
        puVar2 = PTR_BN_new_006a82b4;
        *(uint *)(puVar15 + 0x3c) = *(uint *)(puVar15 + 0x3c) | 0x20;
        uVar5 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a82b4;
        *(undefined4 *)(puVar15 + 0x14) = uVar5;
        uVar5 = (*(code *)puVar2)();
        puVar2 = PTR_bn_expand2_006a9680;
        *(undefined4 *)(puVar15 + 0x10) = uVar5;
        (*(code *)puVar2)(*(undefined4 *)(puVar15 + 0x14),uVar16);
        (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar15 + 0x10),uVar16);
        puVar6 = *(undefined4 **)(puVar15 + 0x14);
        if ((((puVar6 != (undefined4 *)0x0) && (uVar16 == puVar6[2])) &&
            (puVar7 = *(undefined4 **)(puVar15 + 0x10), puVar7 != (undefined4 *)0x0)) &&
           (uVar16 == puVar7[2])) {
          iVar4 = (*p_surewarehk_Load_Rsa_Pubkey)(&uStack_1b4,piVar10,uVar11,*puVar7,*puVar6);
          surewarehk_error_handling(&uStack_1b4,0x6a,iVar4);
          if (iVar4 == 1) {
            piVar10 = *(int **)(puVar15 + 0x14);
            piVar10[1] = uVar16;
            if (uVar16 == 0) {
              *(undefined4 *)(*(int *)(puVar15 + 0x10) + 4) = 0;
            }
            else {
              iVar4 = (uVar11 & 0xfffffffc) - 4;
              piVar12 = (int *)(*piVar10 + iVar4);
              uVar18 = uVar16;
              do {
                uVar11 = uVar18 - 1;
                if (*piVar12 != 0) break;
                piVar12 = piVar12 + -1;
                uVar18 = uVar11;
              } while (uVar11 != 0);
              piVar12 = *(int **)(puVar15 + 0x10);
              piVar10[1] = uVar18;
              piVar12[1] = uVar16;
              piVar10 = (int *)(*piVar12 + iVar4);
              uVar18 = uVar16;
              do {
                uVar11 = uVar18 - 1;
                if (*piVar10 != 0) break;
                piVar10 = piVar10 + -1;
                uVar18 = uVar11;
              } while (uVar11 != 0);
              piVar12[1] = uVar18;
            }
            piVar10 = (int *)(*(code *)PTR_EVP_PKEY_new_006a8710)();
            uVar5 = 6;
            goto LAB_005da414;
          }
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2b3);
        }
        piVar10 = (int *)0x0;
        (*(code *)PTR_RSA_free_006a86f0)(puVar15);
        uVar18 = uVar16;
      }
      else {
        puVar15 = &_ITM_registerTMCloneTable;
        if (uVar17 == 2) {
          uVar16 = uVar11 >> 2;
          puVar15 = (undefined1 *)(*(code *)PTR_DSA_new_method_006aa688)(uVar18);
          (*(code *)PTR_DSA_set_ex_data_006aa68c)(puVar15,dsaHndidx,0);
          uVar5 = (*(code *)PTR_BN_new_006a82b4)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar15 + 0x18) = uVar5;
          uVar5 = (*(code *)puVar2)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar15 + 0xc) = uVar5;
          uVar5 = (*(code *)puVar2)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar15 + 0x10) = uVar5;
          uVar5 = (*(code *)puVar2)();
          puVar2 = PTR_bn_expand2_006a9680;
          *(undefined4 *)(puVar15 + 0x14) = uVar5;
          (*(code *)puVar2)(*(undefined4 *)(puVar15 + 0x18),uVar16);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar15 + 0xc),uVar16);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar15 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar15 + 0x14),uVar16);
          puVar6 = *(undefined4 **)(puVar15 + 0x18);
          uVar17 = uVar16;
          if ((((puVar6 != (undefined4 *)0x0) && (uVar16 == puVar6[2])) &&
              (puVar7 = *(undefined4 **)(puVar15 + 0xc), puVar7 != (undefined4 *)0x0)) &&
             (((uVar16 == puVar7[2] &&
               (puVar14 = *(undefined4 **)(puVar15 + 0x10), puVar14 != (undefined4 *)0x0)) &&
              ((puVar14[2] == 5 &&
               ((puVar9 = *(undefined4 **)(puVar15 + 0x14), puVar9 != (undefined4 *)0x0 &&
                (uVar16 == puVar9[2])))))))) {
            iVar4 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_1b4,piVar10,uVar11,*puVar6,*puVar7,*puVar14,*puVar9);
            surewarehk_error_handling(&uStack_1b4,0x6a,iVar4);
            if (iVar4 == 1) goto LAB_005da448;
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x2df);
          }
          piVar10 = (int *)0x0;
          (*(code *)PTR_DSA_free_006a862c)(puVar15);
          uVar18 = uVar16;
        }
        else {
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          piVar10 = (int *)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",0x2f4);
        }
      }
    }
    else {
      puVar15 = &_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      piVar10 = (int *)0x0;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x334);
      (*(code *)PTR_ERR_add_error_data_006a9264)(1,&uStack_1f4);
    }
  }
  do {
    if (iStack_174 == *(int *)puVar3) {
      return piVar10;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar16 = uVar18;
LAB_005da448:
    piVar10 = *(int **)(puVar15 + 0x18);
    piVar10[1] = uVar16;
    if ((int)uVar16 < 1) {
      *(undefined4 *)(*(int *)(puVar15 + 0xc) + 4) = 0;
    }
    else {
      iVar4 = uVar16 * 4 + -4;
      piVar12 = (int *)(*piVar10 + iVar4);
      uVar18 = uVar16;
      do {
        uVar11 = uVar18 - 1;
        if (*piVar12 != 0) break;
        piVar12 = piVar12 + -1;
        uVar18 = uVar11;
      } while (uVar11 != 0);
      piVar12 = *(int **)(puVar15 + 0xc);
      piVar10[1] = uVar18;
      piVar12[1] = uVar16;
      piVar10 = (int *)(*piVar12 + iVar4);
      uVar18 = uVar16;
      do {
        uVar11 = uVar18 - 1;
        if (*piVar10 != 0) break;
        piVar10 = piVar10 + -1;
        uVar18 = uVar11;
      } while (uVar11 != 0);
      piVar12[1] = uVar18;
    }
    piVar12 = *(int **)(puVar15 + 0x10);
    iVar4 = 5;
    piVar12[1] = 5;
    piVar10 = (int *)(*piVar12 + 0x10);
    do {
      if (*piVar10 != 0) break;
      iVar4 = iVar4 + -1;
      piVar10 = piVar10 + -1;
    } while (iVar4 != 0);
    piVar10 = *(int **)(puVar15 + 0x14);
    piVar12[1] = iVar4;
    piVar10[1] = uVar16;
    if (0 < (int)uVar16) {
      piVar12 = (int *)(*piVar10 + uVar16 * 4 + -4);
      do {
        uVar18 = uVar17 - 1;
        if (*piVar12 != 0) break;
        piVar12 = piVar12 + -1;
        uVar17 = uVar18;
      } while (uVar18 != 0);
      piVar10[1] = uVar17;
    }
    piVar10 = (int *)(*(code *)PTR_EVP_PKEY_new_006a8710)();
    uVar5 = 0x74;
LAB_005da414:
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(piVar10,uVar5,puVar15);
    uVar18 = uVar16;
  } while( true );
}

