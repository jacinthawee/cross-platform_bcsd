
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int surewarehk_rsa_priv_dec
              (uint param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
              undefined1 *param_5)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  uint uVar16;
  char *unaff_s6;
  code *pcVar17;
  char cStack_141;
  uint uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined2 uStack_12c;
  char cStack_12a;
  undefined auStack_129 [45];
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  char cStack_e8;
  undefined auStack_e7 [43];
  int iStack_bc;
  int iStack_b4;
  undefined4 *puStack_b0;
  undefined *puStack_ac;
  undefined1 *puStack_a8;
  undefined4 uStack_a4;
  uint uStack_a0;
  char *pcStack_9c;
  int local_68;
  undefined4 local_64;
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
  uint local_24;
  
  puStack_ac = PTR___stack_chk_guard_006aabf0;
  local_24 = *(uint *)PTR___stack_chk_guard_006aabf0;
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
  local_64 = s_ENGINE_rsa_priv_dec_00674db0._0_4_;
  local_60 = s_ENGINE_rsa_priv_dec_00674db0._4_4_;
  local_5c = s_ENGINE_rsa_priv_dec_00674db0._8_4_;
  local_58 = s_ENGINE_rsa_priv_dec_00674db0._12_4_;
  local_54 = s_ENGINE_rsa_priv_dec_00674db0._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
  }
  else {
    iVar4 = (*(code *)PTR_RSA_get_ex_data_006aa640)(param_4,rsaHndidx);
    if (iVar4 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      iVar4 = 0x6e;
      iStack_b4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d9aa0;
    }
  }
  unaff_s6 = (char *)0x1;
  if (param_5 == (undefined1 *)0x1) {
    iStack_b4 = (*p_surewarehk_Rsa_Priv_Dec)(&local_64,param_1,param_2,&local_68);
    iVar4 = 0x6e;
    surewarehk_error_handling(&local_64,0x6e,iStack_b4);
    param_2 = &local_64;
    if (iStack_b4 == 1) {
      iStack_b4 = local_68;
    }
    goto LAB_005d9aa0;
  }
  iStack_b4 = (*p_surewarehk_Rsa_Priv_Dec)(&local_64,param_1,param_2);
  iVar4 = 0x6e;
  surewarehk_error_handling(&local_64,0x6e,iStack_b4);
  param_2 = &local_64;
  if (iStack_b4 != 1) goto LAB_005d9aa0;
  unaff_s6 = "7 datafinal";
  param_2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(local_68,"e_sureware.c",0x37f);
  if (param_2 == (undefined4 *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    iVar4 = 0x6e;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    param_2 = (undefined4 *)&_ITM_registerTMCloneTable;
    goto LAB_005d9aa0;
  }
  (*(code *)PTR_memcpy_006aabf4)(param_2,param_3,local_68);
  pcVar17 = (code *)PTR_RSA_padding_check_none_006a980c;
  if (param_5 == (undefined1 *)0x3) {
LAB_005d9d0c:
    iStack_b4 = (*pcVar17)(param_3,local_68,param_2,param_1);
LAB_005d9cac:
    if (iStack_b4 < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d9c04;
    }
  }
  else {
    if (param_5 == (undefined1 *)0x4) {
      iStack_b4 = (*(code *)PTR_RSA_padding_check_PKCS1_OAEP_006a9834)(param_3,local_68,param_2);
      goto LAB_005d9cac;
    }
    bVar1 = param_5 == (undefined1 *)0x2;
    param_5 = &_ITM_registerTMCloneTable;
    pcVar17 = (code *)PTR_RSA_padding_check_SSLv23_006a983c;
    if (bVar1) goto LAB_005d9d0c;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d9c04:
    param_5 = &_ITM_registerTMCloneTable;
  }
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(param_2,local_68);
  (*(code *)PTR_CRYPTO_free_006a7f88)(param_2);
  iVar4 = local_68;
LAB_005d9aa0:
  if (local_24 == *(uint *)puStack_ac) {
    return iStack_b4;
  }
  uVar16 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_bc = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_140 = 0;
  cStack_141 = '\0';
  uStack_13c = s_ENGINE_load_pubkey_00674df0._0_4_;
  uStack_138 = s_ENGINE_load_pubkey_00674df0._4_4_;
  uStack_134 = s_ENGINE_load_pubkey_00674df0._8_4_;
  uStack_130 = s_ENGINE_load_pubkey_00674df0._12_4_;
  uStack_12c = s_ENGINE_load_pubkey_00674df0._16_2_;
  cStack_12a = s_ENGINE_load_pubkey_00674df0[18];
  puStack_b0 = param_2;
  puStack_a8 = param_5;
  uStack_a4 = param_3;
  uStack_a0 = param_1;
  pcStack_9c = unaff_s6;
  (*(code *)PTR_memset_006aab00)(auStack_129,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    puVar14 = &_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    iVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x32c);
  }
  else {
    iVar5 = (*p_surewarehk_Info_Pubkey)(&uStack_13c,iVar4,&uStack_140,&cStack_141);
    uVar10 = uStack_140;
    if (iVar5 == 1) {
      param_1 = (uint)cStack_141;
      uStack_fc = s_sureware_load_public_00674e30._0_4_;
      uStack_f8 = s_sureware_load_public_00674e30._4_4_;
      uStack_f4 = s_sureware_load_public_00674e30._8_4_;
      uStack_f0 = s_sureware_load_public_00674e30._12_4_;
      uStack_ec = s_sureware_load_public_00674e30._16_4_;
      cStack_e8 = s_sureware_load_public_00674e30[20];
      (*(code *)PTR_memset_006aab00)(auStack_e7,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        puVar14 = &_ITM_registerTMCloneTable;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        iVar4 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)
                  (SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",0x299);
      }
      else if (param_1 == 1) {
        uVar15 = uVar10 >> 2;
        puVar14 = (undefined1 *)(*(code *)PTR_RSA_new_method_006a881c)(uVar16);
        (*(code *)PTR_RSA_set_ex_data_006aa648)(puVar14,rsaHndidx,0);
        puVar2 = PTR_BN_new_006a82b4;
        *(uint *)(puVar14 + 0x3c) = *(uint *)(puVar14 + 0x3c) | 0x20;
        uVar6 = (*(code *)puVar2)();
        puVar2 = PTR_BN_new_006a82b4;
        *(undefined4 *)(puVar14 + 0x14) = uVar6;
        uVar6 = (*(code *)puVar2)();
        puVar2 = PTR_bn_expand2_006a9680;
        *(undefined4 *)(puVar14 + 0x10) = uVar6;
        (*(code *)puVar2)(*(undefined4 *)(puVar14 + 0x14),uVar15);
        (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar14 + 0x10),uVar15);
        puVar7 = *(undefined4 **)(puVar14 + 0x14);
        if ((((puVar7 != (undefined4 *)0x0) && (uVar15 == puVar7[2])) &&
            (puVar8 = *(undefined4 **)(puVar14 + 0x10), puVar8 != (undefined4 *)0x0)) &&
           (uVar15 == puVar8[2])) {
          iVar4 = (*p_surewarehk_Load_Rsa_Pubkey)(&uStack_fc,iVar4,uVar10,*puVar8,*puVar7);
          surewarehk_error_handling(&uStack_fc,0x6a,iVar4);
          if (iVar4 == 1) {
            piVar12 = *(int **)(puVar14 + 0x14);
            piVar12[1] = uVar15;
            if (uVar15 == 0) {
              *(undefined4 *)(*(int *)(puVar14 + 0x10) + 4) = 0;
            }
            else {
              iVar4 = (uVar10 & 0xfffffffc) - 4;
              piVar11 = (int *)(*piVar12 + iVar4);
              uVar16 = uVar15;
              do {
                uVar10 = uVar16 - 1;
                if (*piVar11 != 0) break;
                piVar11 = piVar11 + -1;
                uVar16 = uVar10;
              } while (uVar10 != 0);
              piVar11 = *(int **)(puVar14 + 0x10);
              piVar12[1] = uVar16;
              piVar11[1] = uVar15;
              piVar12 = (int *)(*piVar11 + iVar4);
              uVar16 = uVar15;
              do {
                uVar10 = uVar16 - 1;
                if (*piVar12 != 0) break;
                piVar12 = piVar12 + -1;
                uVar16 = uVar10;
              } while (uVar10 != 0);
              piVar11[1] = uVar16;
            }
            iVar4 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
            uVar6 = 6;
            goto LAB_005da414;
          }
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2b3);
        }
        iVar4 = 0;
        (*(code *)PTR_RSA_free_006a86f0)(puVar14);
        uVar16 = uVar15;
      }
      else {
        puVar14 = &_ITM_registerTMCloneTable;
        if (param_1 == 2) {
          uVar15 = uVar10 >> 2;
          puVar14 = (undefined1 *)(*(code *)PTR_DSA_new_method_006aa688)(uVar16);
          (*(code *)PTR_DSA_set_ex_data_006aa68c)(puVar14,dsaHndidx,0);
          uVar6 = (*(code *)PTR_BN_new_006a82b4)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar14 + 0x18) = uVar6;
          uVar6 = (*(code *)puVar2)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar14 + 0xc) = uVar6;
          uVar6 = (*(code *)puVar2)();
          puVar2 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar14 + 0x10) = uVar6;
          uVar6 = (*(code *)puVar2)();
          puVar2 = PTR_bn_expand2_006a9680;
          *(undefined4 *)(puVar14 + 0x14) = uVar6;
          (*(code *)puVar2)(*(undefined4 *)(puVar14 + 0x18),uVar15);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar14 + 0xc),uVar15);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar14 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar14 + 0x14),uVar15);
          puVar7 = *(undefined4 **)(puVar14 + 0x18);
          param_1 = uVar15;
          if ((((puVar7 != (undefined4 *)0x0) && (uVar15 == puVar7[2])) &&
              (puVar8 = *(undefined4 **)(puVar14 + 0xc), puVar8 != (undefined4 *)0x0)) &&
             (((uVar15 == puVar8[2] &&
               (puVar13 = *(undefined4 **)(puVar14 + 0x10), puVar13 != (undefined4 *)0x0)) &&
              ((puVar13[2] == 5 &&
               ((puVar9 = *(undefined4 **)(puVar14 + 0x14), puVar9 != (undefined4 *)0x0 &&
                (uVar15 == puVar9[2])))))))) {
            iVar4 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_fc,iVar4,uVar10,*puVar7,*puVar8,*puVar13,*puVar9);
            surewarehk_error_handling(&uStack_fc,0x6a,iVar4);
            if (iVar4 == 1) goto LAB_005da448;
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x2df);
          }
          iVar4 = 0;
          (*(code *)PTR_DSA_free_006a862c)(puVar14);
          uVar16 = uVar15;
        }
        else {
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          iVar4 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",0x2f4);
        }
      }
    }
    else {
      puVar14 = &_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      iVar4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x334);
      (*(code *)PTR_ERR_add_error_data_006a9264)(1,&uStack_13c);
    }
  }
  do {
    if (iStack_bc == *(int *)puVar3) {
      return iVar4;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar15 = uVar16;
LAB_005da448:
    piVar12 = *(int **)(puVar14 + 0x18);
    piVar12[1] = uVar15;
    if ((int)uVar15 < 1) {
      *(undefined4 *)(*(int *)(puVar14 + 0xc) + 4) = 0;
    }
    else {
      iVar4 = uVar15 * 4 + -4;
      piVar11 = (int *)(*piVar12 + iVar4);
      uVar16 = uVar15;
      do {
        uVar10 = uVar16 - 1;
        if (*piVar11 != 0) break;
        piVar11 = piVar11 + -1;
        uVar16 = uVar10;
      } while (uVar10 != 0);
      piVar11 = *(int **)(puVar14 + 0xc);
      piVar12[1] = uVar16;
      piVar11[1] = uVar15;
      piVar12 = (int *)(*piVar11 + iVar4);
      uVar16 = uVar15;
      do {
        uVar10 = uVar16 - 1;
        if (*piVar12 != 0) break;
        piVar12 = piVar12 + -1;
        uVar16 = uVar10;
      } while (uVar10 != 0);
      piVar11[1] = uVar16;
    }
    piVar11 = *(int **)(puVar14 + 0x10);
    iVar4 = 5;
    piVar11[1] = 5;
    piVar12 = (int *)(*piVar11 + 0x10);
    do {
      if (*piVar12 != 0) break;
      iVar4 = iVar4 + -1;
      piVar12 = piVar12 + -1;
    } while (iVar4 != 0);
    piVar12 = *(int **)(puVar14 + 0x14);
    piVar11[1] = iVar4;
    piVar12[1] = uVar15;
    if (0 < (int)uVar15) {
      piVar11 = (int *)(*piVar12 + uVar15 * 4 + -4);
      do {
        uVar16 = param_1 - 1;
        if (*piVar11 != 0) break;
        piVar11 = piVar11 + -1;
        param_1 = uVar16;
      } while (uVar16 != 0);
      piVar12[1] = param_1;
    }
    iVar4 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
    uVar6 = 0x74;
LAB_005da414:
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(iVar4,uVar6,puVar14);
    uVar16 = uVar15;
  } while( true );
}

