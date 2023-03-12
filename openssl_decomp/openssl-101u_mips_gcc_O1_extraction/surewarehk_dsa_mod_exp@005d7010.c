
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int * surewarehk_dsa_mod_exp
                (undefined4 param_1,int *param_2,int *param_3,int *param_4,int *param_5,
                undefined4 *param_6,undefined4 *param_7,undefined *param_8)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  char *pcVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  code *pcVar18;
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
  undefined *puStack_160;
  int *piStack_15c;
  int *piStack_158;
  char *pcStack_154;
  int *piStack_150;
  code *pcStack_14c;
  int *piStack_138;
  int iStack_134;
  undefined *puStack_130;
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
  int iStack_dc;
  int *piStack_d8;
  undefined4 *puStack_d4;
  int *piStack_d0;
  undefined *puStack_cc;
  int *piStack_c8;
  int *piStack_c4;
  char *pcStack_c0;
  code *pcStack_bc;
  undefined *local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  undefined *local_98;
  undefined *local_90;
  int *local_8c;
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
  int *local_2c;
  
  puStack_cc = PTR___stack_chk_guard_006a9ae8;
  pcStack_154 = "encrypt";
  local_88 = param_5;
  piStack_d0 = &local_80;
  local_84 = param_6;
  piStack_c8 = aiStack_5e;
  local_98 = &_gp;
  local_90 = param_8;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  local_8c = param_3;
  (*(code *)PTR_BN_init_006a857c)(piStack_d0);
  piStack_15c = (int *)&DAT_00000032;
  piVar11 = (int *)0x0;
  local_6c = DAT_0067430c;
  local_68 = DAT_00674310;
  local_64 = DAT_00674314;
  local_60 = DAT_00674318;
  pcVar14 = (char *)DAT_00674314;
  (**(code **)(local_98 + -0x53ec))(piStack_c8);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
LAB_005d72d4:
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(local_98 + -0x58a8))();
    }
    piStack_15c = (int *)0x75;
    pcVar14 = "e_sureware.c";
    local_a8 = (undefined *)0x435;
    piVar11 = (int *)&DAT_0000006b;
    (**(code **)(local_98 + -0x6eac))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
LAB_005d7108:
    param_2 = piVar11;
    piStack_d8 = (int *)0x0;
    piStack_c4 = param_4;
  }
  else {
    if (param_2 == (int *)0x0) goto LAB_005d7108;
    (**(code **)(local_98 + -0x68bc))(param_2,param_7[1]);
    piVar11 = (int *)param_2[2];
    if (piVar11 != (int *)param_7[1]) goto LAB_005d7108;
    local_a8 = (undefined *)*param_4;
    local_9c = *param_2;
    pcVar14 = (char *)(param_4[1] << 2);
    local_a0 = *local_8c;
    local_a4 = local_8c[1] << 2;
    local_8c = &local_6c;
    param_4 = (int *)(*p_surewarehk_Mod_Exp)(&local_6c,(int)piVar11 << 2,*param_7,pcVar14);
    piVar11 = (int *)&DAT_0000006b;
    piStack_15c = param_4;
    surewarehk_error_handling(local_8c);
    if (param_4 == (int *)0x1) {
      iVar4 = param_7[1];
      param_2[1] = iVar4;
      if (0 < iVar4) {
        iVar5 = *param_2 + iVar4 * 4 + -8;
        do {
          if (*(int *)(iVar5 + 4) != 0) break;
          iVar4 = iVar4 + -1;
          iVar5 = iVar5 + -4;
        } while (iVar4 != 0);
        param_2[1] = iVar4;
      }
    }
    else if (param_4 == (int *)0x0) goto LAB_005d7108;
    piStack_15c = (int *)&DAT_00000032;
    local_6c = DAT_0067430c;
    local_68 = DAT_00674310;
    local_64 = DAT_00674314;
    local_60 = DAT_00674318;
    pcVar14 = (char *)DAT_00674314;
    (**(code **)(local_98 + -0x53ec))(piStack_c8,0);
    if (p_surewarehk_Mod_Exp == (code *)0x0) goto LAB_005d72d4;
    (**(code **)(local_98 + -0x68bc))(piStack_d0,param_7[1]);
    piStack_c4 = local_8c;
    piVar11 = local_78;
    if (local_78 != (int *)param_7[1]) goto LAB_005d7108;
    local_a0 = *local_88;
    local_a4 = local_88[1] << 2;
    local_a8 = (undefined *)*local_84;
    pcVar14 = (char *)(local_84[1] << 2);
    local_9c = local_80;
    piStack_c8 = (int *)(*p_surewarehk_Mod_Exp)(local_8c,(int)local_78 << 2,*param_7,pcVar14);
    piVar11 = (int *)&DAT_0000006b;
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
      if (piStack_c8 == (int *)0x0) goto LAB_005d7108;
    }
    local_a8 = local_90;
    piStack_15c = piStack_d0;
    pcVar14 = (char *)param_7;
    iVar4 = (**(code **)(local_98 + -0x686c))(param_2,param_2,piStack_d0,param_7);
    piStack_d8 = (int *)(uint)(iVar4 != 0);
  }
  (**(code **)(local_98 + -0x7dc4))(piStack_d0);
  if (local_2c == *(int **)puStack_cc) {
    return piStack_d8;
  }
  pcStack_bc = surewarehk_rsa_priv_dec;
  piVar11 = local_2c;
  (**(code **)(local_98 + -0x5330))();
  puStack_160 = local_a8;
  puStack_164 = PTR___stack_chk_guard_006a9ae8;
  puStack_d4 = param_7;
  iStack_dc = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_c0 = "encrypt";
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
  iStack_11c = s_ENGINE_rsa_priv_dec_006744a0._0_4_;
  uStack_118 = s_ENGINE_rsa_priv_dec_006744a0._4_4_;
  uStack_114 = s_ENGINE_rsa_priv_dec_006744a0._8_4_;
  uStack_110 = s_ENGINE_rsa_priv_dec_006744a0._12_4_;
  uStack_10c = s_ENGINE_rsa_priv_dec_006744a0._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    piStack_138 = (int *)0x38f;
    (**(code **)(puStack_128 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
    iVar4 = 0;
  }
  else {
    iVar4 = (*(code *)PTR_RSA_get_ex_data_006a9534)(pcVar14,rsaHndidx);
    if (iVar4 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x58a8))();
      }
      piStack_138 = (int *)0x394;
      piVar12 = (int *)&DAT_0000006e;
      piStack_16c = (int *)0x0;
      (**(code **)(puStack_128 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d74cc;
    }
  }
  pcStack_154 = (char *)0x1;
  piStack_138 = piStack_15c;
  iStack_134 = iVar4;
  if (puStack_160 == (undefined *)0x1) {
    puStack_130 = puStack_160;
    piStack_16c = (int *)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_11c,piVar11,param_2,&piStack_120);
    piVar12 = (int *)&DAT_0000006e;
    surewarehk_error_handling(&iStack_11c,0x6e,piStack_16c);
    param_2 = &iStack_11c;
    if (piStack_16c == (int *)0x1) {
      piStack_16c = piStack_120;
    }
    goto LAB_005d74cc;
  }
  puStack_130 = (undefined *)0x0;
  piStack_16c = (int *)(*p_surewarehk_Rsa_Priv_Dec)(&iStack_11c,piVar11,param_2);
  piVar12 = (int *)&DAT_0000006e;
  surewarehk_error_handling(&iStack_11c,0x6e,piStack_16c);
  param_2 = &iStack_11c;
  if (piStack_16c != (int *)0x1) goto LAB_005d74cc;
  pcStack_154 = "encrypt";
  param_2 = (int *)(**(code **)(puStack_128 + -0x7dd8))(piStack_120,"e_sureware.c",0x3ac);
  if (param_2 == (int *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x58a8))();
    }
    piVar12 = (int *)&DAT_0000006e;
    piStack_138 = (int *)0x3ae;
    (**(code **)(puStack_128 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    param_2 = (int *)&_gp_1;
    goto LAB_005d74cc;
  }
  (**(code **)(puStack_128 + -0x52f4))(param_2,piStack_15c,piStack_120);
  if (puStack_160 == (undefined *)0x3) {
    pcVar18 = *(code **)(puStack_128 + -0x66f8);
LAB_005d7738:
    piStack_138 = piStack_120;
    piStack_16c = (int *)(*pcVar18)(piStack_15c,piStack_120,param_2,piVar11);
LAB_005d76d8:
    pcVar18 = *(code **)(puStack_128 + -0x7d6c);
    if ((int)piStack_16c < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x58a8))();
      }
      piStack_138 = (int *)0x3cb;
      (**(code **)(puStack_128 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d7630;
    }
  }
  else {
    if (puStack_160 == (undefined *)0x4) {
      puStack_130 = (undefined *)0x0;
      iStack_134 = 0;
      piStack_138 = piStack_120;
      piStack_16c = (int *)(**(code **)(puStack_128 + -0x66d0))(piStack_15c,piStack_120,param_2);
      goto LAB_005d76d8;
    }
    bVar1 = puStack_160 == (undefined *)0x2;
    puStack_160 = &_gp_1;
    if (bVar1) {
      pcVar18 = *(code **)(puStack_128 + -0x66c8);
      goto LAB_005d7738;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_128 + -0x58a8))();
    }
    piStack_138 = (int *)0x3c6;
    (**(code **)(puStack_128 + -0x6eac))(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d7630:
    puStack_160 = &_gp_1;
    pcVar18 = *(code **)(puStack_128 + -0x7d6c);
  }
  (*pcVar18)(param_2,piStack_120);
  (**(code **)(puStack_128 + -0x7f58))(param_2);
  piVar12 = piStack_120;
LAB_005d74cc:
  if (iStack_dc == *(int *)puStack_164) {
    return piStack_16c;
  }
  pcStack_14c = surewarehk_load_pubkey;
  iVar4 = iStack_dc;
  (**(code **)(puStack_128 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_174 = *(int *)PTR___stack_chk_guard_006a9ae8;
  piStack_150 = &DAT_0067430c;
  uStack_1f8 = 0;
  cStack_1f9 = '\0';
  uStack_1f4 = s_ENGINE_load_pubkey_006744e0._0_4_;
  uStack_1f0 = s_ENGINE_load_pubkey_006744e0._4_4_;
  uStack_1ec = s_ENGINE_load_pubkey_006744e0._8_4_;
  uStack_1e8 = s_ENGINE_load_pubkey_006744e0._12_4_;
  uStack_1e4 = s_ENGINE_load_pubkey_006744e0._16_2_;
  cStack_1e2 = s_ENGINE_load_pubkey_006744e0[18];
  piStack_168 = param_2;
  piStack_158 = piVar11;
  (*(code *)PTR_memset_006a99f4)(auStack_1e1,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    piVar15 = (int *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
  }
  else {
    iVar5 = (*p_surewarehk_Info_Pubkey)(&uStack_1f4,piVar12,&uStack_1f8,&cStack_1f9);
    uVar17 = uStack_1f8;
    if (iVar5 == 1) {
      piVar11 = (int *)(int)cStack_1f9;
      uStack_1b4 = s_sureware_load_public_00674520._0_4_;
      uStack_1b0 = s_sureware_load_public_00674520._4_4_;
      uStack_1ac = s_sureware_load_public_00674520._8_4_;
      uStack_1a8 = s_sureware_load_public_00674520._12_4_;
      uStack_1a4 = s_sureware_load_public_00674520._16_4_;
      cStack_1a0 = s_sureware_load_public_00674520[20];
      (*(code *)PTR_memset_006a99f4)(auStack_19f,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        piVar15 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
      }
      else if (piVar11 == (int *)0x1) {
        iVar4 = (*(code *)PTR_RSA_new_method_006a772c)(iVar4);
        (*(code *)PTR_RSA_set_ex_data_006a953c)(iVar4,rsaHndidx,0);
        puVar2 = PTR_BN_new_006a71b4;
        *(uint *)(iVar4 + 0x3c) = *(uint *)(iVar4 + 0x3c) | 0x20;
        uVar6 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar4 + 0x14) = uVar6;
        iVar5 = (*(code *)puVar2)();
        *(int *)(iVar4 + 0x10) = iVar5;
        if ((*(int *)(iVar4 + 0x14) != 0) && (iVar5 != 0)) {
          uVar16 = uVar17 >> 2;
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar4 + 0x14),uVar16);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar4 + 0x10),uVar16);
          if ((uVar16 == (*(undefined4 **)(iVar4 + 0x14))[2]) &&
             (uVar16 == (*(undefined4 **)(iVar4 + 0x10))[2])) {
            iVar5 = (*p_surewarehk_Load_Rsa_Pubkey)
                              (&uStack_1b4,piVar12,uVar17,**(undefined4 **)(iVar4 + 0x10),
                               **(undefined4 **)(iVar4 + 0x14));
            surewarehk_error_handling(&uStack_1b4,0x6a,iVar5);
            if (iVar5 == 1) {
              piVar12 = *(int **)(iVar4 + 0x14);
              piVar12[1] = uVar16;
              if (uVar16 == 0) {
                *(undefined4 *)(*(int *)(iVar4 + 0x10) + 4) = 0;
              }
              else {
                iVar5 = (uVar17 & 0xfffffffc) - 4;
                piVar15 = (int *)(*piVar12 + iVar5);
                uVar17 = uVar16;
                do {
                  uVar10 = uVar17 - 1;
                  if (*piVar15 != 0) break;
                  piVar15 = piVar15 + -1;
                  uVar17 = uVar10;
                } while (uVar10 != 0);
                piVar15 = *(int **)(iVar4 + 0x10);
                piVar12[1] = uVar17;
                piVar15[1] = uVar16;
                piVar12 = (int *)(*piVar15 + iVar5);
                do {
                  uVar17 = uVar16 - 1;
                  if (*piVar12 != 0) break;
                  piVar12 = piVar12 + -1;
                  uVar16 = uVar17;
                } while (uVar17 != 0);
                piVar15[1] = uVar16;
              }
              piVar15 = (int *)(*(code *)PTR_EVP_PKEY_new_006a7620)();
              uVar6 = 6;
              goto LAB_005d7f4c;
            }
            if (SUREWARE_lib_error_code == 0) {
              SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            (*(code *)PTR_ERR_put_error_006a7f34)
                      (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2d8);
          }
        }
        piVar15 = (int *)0x0;
        (*(code *)PTR_RSA_free_006a7600)(iVar4);
      }
      else if (piVar11 == (int *)&SUB_00000002) {
        iVar4 = (*(code *)PTR_DSA_new_method_006a957c)(iVar4);
        (*(code *)PTR_DSA_set_ex_data_006a9580)(iVar4,dsaHndidx,0);
        uVar6 = (*(code *)PTR_BN_new_006a71b4)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar4 + 0x18) = uVar6;
        uVar6 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar4 + 0xc) = uVar6;
        uVar6 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a71b4;
        *(undefined4 *)(iVar4 + 0x10) = uVar6;
        iVar5 = (*(code *)puVar2)();
        *(int *)(iVar4 + 0x14) = iVar5;
        if ((((*(int *)(iVar4 + 0x18) != 0) && (*(int *)(iVar4 + 0xc) != 0)) &&
            (*(int *)(iVar4 + 0x10) != 0)) && (iVar5 != 0)) {
          piVar15 = (int *)(uVar17 >> 2);
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar4 + 0x18),piVar15);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar4 + 0xc),piVar15);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar4 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar4 + 0x14),piVar15);
          piVar11 = piVar15;
          if (((piVar15 == (int *)(*(undefined4 **)(iVar4 + 0x18))[2]) &&
              (piVar15 == (int *)(*(undefined4 **)(iVar4 + 0xc))[2])) &&
             (((*(undefined4 **)(iVar4 + 0x10))[2] == 5 &&
              (piVar15 == (int *)(*(undefined4 **)(iVar4 + 0x14))[2])))) {
            iVar5 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_1b4,piVar12,uVar17,**(undefined4 **)(iVar4 + 0x18),
                               **(undefined4 **)(iVar4 + 0xc),**(undefined4 **)(iVar4 + 0x10),
                               **(undefined4 **)(iVar4 + 0x14));
            surewarehk_error_handling(&uStack_1b4,0x6a,iVar5);
            if (iVar5 == 1) {
              piVar12 = *(int **)(iVar4 + 0x18);
              piVar12[1] = (int)piVar15;
              if (piVar15 == (int *)0x0) goto LAB_005d7f80;
              iVar5 = (uVar17 & 0xfffffffc) - 4;
              piVar9 = (int *)(*piVar12 + iVar5);
              piVar8 = piVar15;
              do {
                piVar13 = (int *)((int)piVar8 + -1);
                if (*piVar9 != 0) break;
                piVar9 = piVar9 + -1;
                piVar8 = piVar13;
              } while (piVar13 != (int *)0x0);
              piVar13 = *(int **)(iVar4 + 0xc);
              piVar12[1] = (int)piVar8;
              piVar13[1] = (int)piVar15;
              piVar12 = (int *)(*piVar13 + iVar5);
              piVar9 = piVar15;
              do {
                piVar8 = (int *)((int)piVar9 + -1);
                if (*piVar12 != 0) break;
                piVar12 = piVar12 + -1;
                piVar9 = piVar8;
              } while (piVar8 != (int *)0x0);
              piVar13[1] = (int)piVar9;
              goto LAB_005d7dc4;
            }
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
          }
        }
        piVar15 = (int *)0x0;
        (*(code *)PTR_DSA_free_006a7530)(iVar4);
      }
      else {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        piVar15 = (int *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
      }
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      piVar15 = (int *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      (*(code *)PTR_ERR_add_error_data_006a813c)(1,&uStack_1f4);
    }
  }
  do {
    if (iStack_174 == *(int *)puVar3) {
      return piVar15;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005d7f80:
    *(undefined4 *)(*(int *)(iVar4 + 0xc) + 4) = 0;
LAB_005d7dc4:
    piVar12 = *(int **)(iVar4 + 0x10);
    iVar7 = 5;
    piVar12[1] = 5;
    iVar5 = *piVar12 + 0xc;
    do {
      if (*(int *)(iVar5 + 4) != 0) break;
      iVar7 = iVar7 + -1;
      iVar5 = iVar5 + -4;
    } while (iVar7 != 0);
    piVar9 = *(int **)(iVar4 + 0x14);
    piVar12[1] = iVar7;
    piVar9[1] = (int)piVar15;
    if (0 < (int)piVar15) {
      iVar5 = *piVar9 + (int)piVar15 * 4 + -8;
      do {
        if (*(int *)(iVar5 + 4) != 0) break;
        piVar11 = (int *)((int)piVar11 + -1);
        iVar5 = iVar5 + -4;
      } while (piVar11 != (int *)0x0);
      piVar9[1] = (int)piVar11;
    }
    piVar15 = (int *)(*(code *)PTR_EVP_PKEY_new_006a7620)();
    uVar6 = 0x74;
LAB_005d7f4c:
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(piVar15,uVar6,iVar4);
  } while( true );
}

