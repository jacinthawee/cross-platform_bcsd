
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 surewarehk_load_pubkey(uint param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  uint unaff_s5;
  uint uVar15;
  char local_b1;
  uint local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined2 local_9c;
  char local_9a;
  undefined auStack_99 [45];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  char local_58;
  undefined auStack_57 [43];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_b0 = 0;
  local_b1 = '\0';
  local_ac = s_ENGINE_load_pubkey_00674dd0._0_4_;
  local_a8 = s_ENGINE_load_pubkey_00674dd0._4_4_;
  local_a4 = s_ENGINE_load_pubkey_00674dd0._8_4_;
  local_a0 = s_ENGINE_load_pubkey_00674dd0._12_4_;
  local_9c = s_ENGINE_load_pubkey_00674dd0._16_2_;
  local_9a = s_ENGINE_load_pubkey_00674dd0[18];
  (*(code *)PTR_memset_006aab00)(auStack_99,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    puVar13 = &_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x32c);
  }
  else {
    iVar3 = (*p_surewarehk_Info_Pubkey)(&local_ac,param_2,&local_b0,&local_b1);
    uVar15 = local_b0;
    if (iVar3 == 1) {
      unaff_s5 = (uint)local_b1;
      local_6c = s_sureware_load_public_00674e10._0_4_;
      local_68 = s_sureware_load_public_00674e10._4_4_;
      local_64 = s_sureware_load_public_00674e10._8_4_;
      local_60 = s_sureware_load_public_00674e10._12_4_;
      local_5c = s_sureware_load_public_00674e10._16_4_;
      local_58 = s_sureware_load_public_00674e10[20];
      (*(code *)PTR_memset_006aab00)(auStack_57,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        puVar13 = &_ITM_registerTMCloneTable;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar4 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)
                  (SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",0x299);
      }
      else if (unaff_s5 == 1) {
        uVar14 = uVar15 >> 2;
        puVar13 = (undefined1 *)(*(code *)PTR_RSA_new_method_006a881c)(param_1);
        (*(code *)PTR_RSA_set_ex_data_006aa648)(puVar13,rsaHndidx,0);
        puVar1 = PTR_BN_new_006a82b4;
        *(uint *)(puVar13 + 0x3c) = *(uint *)(puVar13 + 0x3c) | 0x20;
        uVar4 = (*(code *)puVar1)();
        puVar1 = PTR_BN_new_006a82b4;
        *(undefined4 *)(puVar13 + 0x14) = uVar4;
        uVar4 = (*(code *)puVar1)();
        puVar1 = PTR_bn_expand2_006a9680;
        *(undefined4 *)(puVar13 + 0x10) = uVar4;
        (*(code *)puVar1)(*(undefined4 *)(puVar13 + 0x14),uVar14);
        (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar13 + 0x10),uVar14);
        puVar5 = *(undefined4 **)(puVar13 + 0x14);
        if ((((puVar5 != (undefined4 *)0x0) && (uVar14 == puVar5[2])) &&
            (puVar6 = *(undefined4 **)(puVar13 + 0x10), puVar6 != (undefined4 *)0x0)) &&
           (uVar14 == puVar6[2])) {
          iVar3 = (*p_surewarehk_Load_Rsa_Pubkey)(&local_6c,param_2,uVar15,*puVar6,*puVar5);
          surewarehk_error_handling(&local_6c,0x6a,iVar3);
          if (iVar3 == 1) {
            piVar11 = *(int **)(puVar13 + 0x14);
            piVar11[1] = uVar14;
            if (uVar14 == 0) {
              *(undefined4 *)(*(int *)(puVar13 + 0x10) + 4) = 0;
            }
            else {
              iVar3 = (uVar15 & 0xfffffffc) - 4;
              piVar10 = (int *)(*piVar11 + iVar3);
              uVar15 = uVar14;
              do {
                uVar8 = uVar15 - 1;
                if (*piVar10 != 0) break;
                piVar10 = piVar10 + -1;
                uVar15 = uVar8;
              } while (uVar8 != 0);
              piVar10 = *(int **)(puVar13 + 0x10);
              piVar11[1] = uVar15;
              piVar10[1] = uVar14;
              piVar11 = (int *)(*piVar10 + iVar3);
              uVar15 = uVar14;
              do {
                uVar8 = uVar15 - 1;
                if (*piVar11 != 0) break;
                piVar11 = piVar11 + -1;
                uVar15 = uVar8;
              } while (uVar8 != 0);
              piVar10[1] = uVar15;
            }
            uVar4 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
            uVar9 = 6;
            goto LAB_005da414;
          }
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2b3);
        }
        uVar4 = 0;
        (*(code *)PTR_RSA_free_006a86f0)(puVar13);
        param_1 = uVar14;
      }
      else {
        puVar13 = &_ITM_registerTMCloneTable;
        if (unaff_s5 == 2) {
          uVar14 = uVar15 >> 2;
          puVar13 = (undefined1 *)(*(code *)PTR_DSA_new_method_006aa688)(param_1);
          (*(code *)PTR_DSA_set_ex_data_006aa68c)(puVar13,dsaHndidx,0);
          uVar4 = (*(code *)PTR_BN_new_006a82b4)();
          puVar1 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar13 + 0x18) = uVar4;
          uVar4 = (*(code *)puVar1)();
          puVar1 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar13 + 0xc) = uVar4;
          uVar4 = (*(code *)puVar1)();
          puVar1 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar13 + 0x10) = uVar4;
          uVar4 = (*(code *)puVar1)();
          puVar1 = PTR_bn_expand2_006a9680;
          *(undefined4 *)(puVar13 + 0x14) = uVar4;
          (*(code *)puVar1)(*(undefined4 *)(puVar13 + 0x18),uVar14);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar13 + 0xc),uVar14);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar13 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar13 + 0x14),uVar14);
          puVar5 = *(undefined4 **)(puVar13 + 0x18);
          unaff_s5 = uVar14;
          if ((((puVar5 != (undefined4 *)0x0) && (uVar14 == puVar5[2])) &&
              (puVar6 = *(undefined4 **)(puVar13 + 0xc), puVar6 != (undefined4 *)0x0)) &&
             (((uVar14 == puVar6[2] &&
               (puVar12 = *(undefined4 **)(puVar13 + 0x10), puVar12 != (undefined4 *)0x0)) &&
              ((puVar12[2] == 5 &&
               ((puVar7 = *(undefined4 **)(puVar13 + 0x14), puVar7 != (undefined4 *)0x0 &&
                (uVar14 == puVar7[2])))))))) {
            iVar3 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&local_6c,param_2,uVar15,*puVar5,*puVar6,*puVar12,*puVar7);
            surewarehk_error_handling(&local_6c,0x6a,iVar3);
            if (iVar3 == 1) goto LAB_005da448;
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x2df);
          }
          uVar4 = 0;
          (*(code *)PTR_DSA_free_006a862c)(puVar13);
          param_1 = uVar14;
        }
        else {
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          uVar4 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",0x2f4);
        }
      }
    }
    else {
      puVar13 = &_ITM_registerTMCloneTable;
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x334);
      (*(code *)PTR_ERR_add_error_data_006a9264)(1,&local_ac);
    }
  }
  do {
    if (local_2c == *(int *)puVar2) {
      return uVar4;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar14 = param_1;
LAB_005da448:
    piVar11 = *(int **)(puVar13 + 0x18);
    piVar11[1] = uVar14;
    if ((int)uVar14 < 1) {
      *(undefined4 *)(*(int *)(puVar13 + 0xc) + 4) = 0;
    }
    else {
      iVar3 = uVar14 * 4 + -4;
      piVar10 = (int *)(*piVar11 + iVar3);
      uVar15 = uVar14;
      do {
        uVar8 = uVar15 - 1;
        if (*piVar10 != 0) break;
        piVar10 = piVar10 + -1;
        uVar15 = uVar8;
      } while (uVar8 != 0);
      piVar10 = *(int **)(puVar13 + 0xc);
      piVar11[1] = uVar15;
      piVar10[1] = uVar14;
      piVar11 = (int *)(*piVar10 + iVar3);
      uVar15 = uVar14;
      do {
        uVar8 = uVar15 - 1;
        if (*piVar11 != 0) break;
        piVar11 = piVar11 + -1;
        uVar15 = uVar8;
      } while (uVar8 != 0);
      piVar10[1] = uVar15;
    }
    piVar10 = *(int **)(puVar13 + 0x10);
    iVar3 = 5;
    piVar10[1] = 5;
    piVar11 = (int *)(*piVar10 + 0x10);
    do {
      if (*piVar11 != 0) break;
      iVar3 = iVar3 + -1;
      piVar11 = piVar11 + -1;
    } while (iVar3 != 0);
    piVar11 = *(int **)(puVar13 + 0x14);
    piVar10[1] = iVar3;
    piVar11[1] = uVar14;
    if (0 < (int)uVar14) {
      piVar10 = (int *)(*piVar11 + uVar14 * 4 + -4);
      do {
        uVar15 = unaff_s5 - 1;
        if (*piVar10 != 0) break;
        piVar10 = piVar10 + -1;
        unaff_s5 = uVar15;
      } while (uVar15 != 0);
      piVar11[1] = unaff_s5;
    }
    uVar4 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
    uVar9 = 0x74;
LAB_005da414:
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(uVar4,uVar9,puVar13);
    param_1 = uVar14;
  } while( true );
}

