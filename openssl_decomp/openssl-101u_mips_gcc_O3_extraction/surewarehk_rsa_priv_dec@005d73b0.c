
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint surewarehk_rsa_priv_dec
               (uint param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined *param_5)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  char *unaff_s6;
  code *pcVar13;
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
  uint uStack_b4;
  undefined4 *puStack_b0;
  undefined *puStack_ac;
  undefined *puStack_a8;
  undefined4 uStack_a4;
  uint uStack_a0;
  char *pcStack_9c;
  uint local_68;
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
  int local_24;
  
  puStack_ac = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
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
  local_64 = s_ENGINE_rsa_priv_dec_006744a0._0_4_;
  local_60 = s_ENGINE_rsa_priv_dec_006744a0._4_4_;
  local_5c = s_ENGINE_rsa_priv_dec_006744a0._8_4_;
  local_58 = s_ENGINE_rsa_priv_dec_006744a0._12_4_;
  local_54 = s_ENGINE_rsa_priv_dec_006744a0._16_4_;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c");
  }
  else {
    iVar4 = (*(code *)PTR_RSA_get_ex_data_006a9534)(param_4,rsaHndidx);
    if (iVar4 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar9 = 0x6e;
      uStack_b4 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c");
      goto LAB_005d74cc;
    }
  }
  unaff_s6 = (char *)0x1;
  if (param_5 == (undefined *)0x1) {
    uStack_b4 = (*p_surewarehk_Rsa_Priv_Dec)(&local_64,param_1,param_2,&local_68);
    uVar9 = 0x6e;
    surewarehk_error_handling(&local_64,0x6e,uStack_b4);
    param_2 = &local_64;
    if (uStack_b4 == 1) {
      uStack_b4 = local_68;
    }
    goto LAB_005d74cc;
  }
  uStack_b4 = (*p_surewarehk_Rsa_Priv_Dec)(&local_64,param_1,param_2);
  uVar9 = 0x6e;
  surewarehk_error_handling(&local_64,0x6e,uStack_b4);
  param_2 = &local_64;
  if (uStack_b4 != 1) goto LAB_005d74cc;
  unaff_s6 = "encrypt";
  param_2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(local_68,"e_sureware.c",0x3ac);
  if (param_2 == (undefined4 *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar9 = 0x6e;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c");
    param_2 = (undefined4 *)&_gp_1;
    goto LAB_005d74cc;
  }
  (*(code *)PTR_memcpy_006a9aec)(param_2,param_3,local_68);
  pcVar13 = (code *)PTR_RSA_padding_check_none_006a86e8;
  if (param_5 == (undefined *)0x3) {
LAB_005d7738:
    uStack_b4 = (*pcVar13)(param_3,local_68,param_2,param_1);
LAB_005d76d8:
    if ((int)uStack_b4 < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c");
      goto LAB_005d7630;
    }
  }
  else {
    if (param_5 == (undefined *)0x4) {
      uStack_b4 = (*(code *)PTR_RSA_padding_check_PKCS1_OAEP_006a8710)(param_3,local_68,param_2);
      goto LAB_005d76d8;
    }
    bVar1 = param_5 == (undefined *)0x2;
    param_5 = &_gp_1;
    pcVar13 = (code *)PTR_RSA_padding_check_SSLv23_006a8718;
    if (bVar1) goto LAB_005d7738;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c");
LAB_005d7630:
    param_5 = &_gp_1;
  }
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(param_2,local_68);
  (*(code *)PTR_CRYPTO_free_006a6e88)(param_2);
  uVar9 = local_68;
LAB_005d74cc:
  if (local_24 == *(int *)puStack_ac) {
    return uStack_b4;
  }
  iVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_bc = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_140 = 0;
  cStack_141 = '\0';
  uStack_13c = s_ENGINE_load_pubkey_006744e0._0_4_;
  uStack_138 = s_ENGINE_load_pubkey_006744e0._4_4_;
  uStack_134 = s_ENGINE_load_pubkey_006744e0._8_4_;
  uStack_130 = s_ENGINE_load_pubkey_006744e0._12_4_;
  uStack_12c = s_ENGINE_load_pubkey_006744e0._16_2_;
  cStack_12a = s_ENGINE_load_pubkey_006744e0[18];
  puStack_b0 = param_2;
  puStack_a8 = param_5;
  uStack_a4 = param_3;
  uStack_a0 = param_1;
  pcStack_9c = unaff_s6;
  (*(code *)PTR_memset_006a99f4)(auStack_129,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar12 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
  }
  else {
    iVar5 = (*p_surewarehk_Info_Pubkey)(&uStack_13c,uVar9,&uStack_140,&cStack_141);
    uVar10 = uStack_140;
    if (iVar5 == 1) {
      param_1 = (uint)cStack_141;
      uStack_fc = s_sureware_load_public_00674520._0_4_;
      uStack_f8 = s_sureware_load_public_00674520._4_4_;
      uStack_f4 = s_sureware_load_public_00674520._8_4_;
      uStack_f0 = s_sureware_load_public_00674520._12_4_;
      uStack_ec = s_sureware_load_public_00674520._16_4_;
      cStack_e8 = s_sureware_load_public_00674520[20];
      (*(code *)PTR_memset_006a99f4)(auStack_e7,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar12 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
      }
      else if (param_1 == 1) {
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
          uVar12 = uVar10 >> 2;
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar4 + 0x14),uVar12);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar4 + 0x10),uVar12);
          if ((uVar12 == (*(undefined4 **)(iVar4 + 0x14))[2]) &&
             (uVar12 == (*(undefined4 **)(iVar4 + 0x10))[2])) {
            iVar5 = (*p_surewarehk_Load_Rsa_Pubkey)
                              (&uStack_fc,uVar9,uVar10,**(undefined4 **)(iVar4 + 0x10),
                               **(undefined4 **)(iVar4 + 0x14));
            surewarehk_error_handling(&uStack_fc,0x6a,iVar5);
            if (iVar5 == 1) {
              piVar11 = *(int **)(iVar4 + 0x14);
              piVar11[1] = uVar12;
              if (uVar12 == 0) {
                *(undefined4 *)(*(int *)(iVar4 + 0x10) + 4) = 0;
              }
              else {
                iVar5 = (uVar10 & 0xfffffffc) - 4;
                piVar8 = (int *)(*piVar11 + iVar5);
                uVar9 = uVar12;
                do {
                  uVar10 = uVar9 - 1;
                  if (*piVar8 != 0) break;
                  piVar8 = piVar8 + -1;
                  uVar9 = uVar10;
                } while (uVar10 != 0);
                piVar8 = *(int **)(iVar4 + 0x10);
                piVar11[1] = uVar9;
                piVar8[1] = uVar12;
                piVar11 = (int *)(*piVar8 + iVar5);
                do {
                  uVar9 = uVar12 - 1;
                  if (*piVar11 != 0) break;
                  piVar11 = piVar11 + -1;
                  uVar12 = uVar9;
                } while (uVar9 != 0);
                piVar8[1] = uVar12;
              }
              uVar12 = (*(code *)PTR_EVP_PKEY_new_006a7620)();
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
        uVar12 = 0;
        (*(code *)PTR_RSA_free_006a7600)(iVar4);
      }
      else if (param_1 == 2) {
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
          uVar12 = uVar10 >> 2;
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(iVar4 + 0x18),uVar12);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar4 + 0xc),uVar12);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar4 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(iVar4 + 0x14),uVar12);
          param_1 = uVar12;
          if (((uVar12 == (*(undefined4 **)(iVar4 + 0x18))[2]) &&
              (uVar12 == (*(undefined4 **)(iVar4 + 0xc))[2])) &&
             (((*(undefined4 **)(iVar4 + 0x10))[2] == 5 &&
              (uVar12 == (*(undefined4 **)(iVar4 + 0x14))[2])))) {
            iVar5 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&uStack_fc,uVar9,uVar10,**(undefined4 **)(iVar4 + 0x18),
                               **(undefined4 **)(iVar4 + 0xc),**(undefined4 **)(iVar4 + 0x10),
                               **(undefined4 **)(iVar4 + 0x14));
            surewarehk_error_handling(&uStack_fc,0x6a,iVar5);
            if (iVar5 == 1) {
              piVar11 = *(int **)(iVar4 + 0x18);
              piVar11[1] = uVar12;
              if (uVar12 == 0) goto LAB_005d7f80;
              iVar5 = (uVar10 & 0xfffffffc) - 4;
              piVar8 = (int *)(*piVar11 + iVar5);
              uVar9 = uVar12;
              do {
                uVar10 = uVar9 - 1;
                if (*piVar8 != 0) break;
                piVar8 = piVar8 + -1;
                uVar9 = uVar10;
              } while (uVar10 != 0);
              piVar8 = *(int **)(iVar4 + 0xc);
              piVar11[1] = uVar9;
              piVar8[1] = uVar12;
              piVar11 = (int *)(*piVar8 + iVar5);
              uVar9 = uVar12;
              do {
                uVar10 = uVar9 - 1;
                if (*piVar11 != 0) break;
                piVar11 = piVar11 + -1;
                uVar9 = uVar10;
              } while (uVar10 != 0);
              piVar8[1] = uVar9;
              goto LAB_005d7dc4;
            }
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
          }
        }
        uVar12 = 0;
        (*(code *)PTR_DSA_free_006a7530)(iVar4);
      }
      else {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar12 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
      }
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar12 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      (*(code *)PTR_ERR_add_error_data_006a813c)(1,&uStack_13c);
    }
  }
  do {
    if (iStack_bc == *(int *)puVar3) {
      return uVar12;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005d7f80:
    *(undefined4 *)(*(int *)(iVar4 + 0xc) + 4) = 0;
LAB_005d7dc4:
    piVar11 = *(int **)(iVar4 + 0x10);
    iVar7 = 5;
    piVar11[1] = 5;
    iVar5 = *piVar11 + 0xc;
    do {
      if (*(int *)(iVar5 + 4) != 0) break;
      iVar7 = iVar7 + -1;
      iVar5 = iVar5 + -4;
    } while (iVar7 != 0);
    piVar8 = *(int **)(iVar4 + 0x14);
    piVar11[1] = iVar7;
    piVar8[1] = uVar12;
    if (0 < (int)uVar12) {
      iVar5 = *piVar8 + uVar12 * 4 + -8;
      do {
        if (*(int *)(iVar5 + 4) != 0) break;
        param_1 = param_1 - 1;
        iVar5 = iVar5 + -4;
      } while (param_1 != 0);
      piVar8[1] = param_1;
    }
    uVar12 = (*(code *)PTR_EVP_PKEY_new_006a7620)();
    uVar6 = 0x74;
LAB_005d7f4c:
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(uVar12,uVar6,iVar4);
  } while( true );
}

