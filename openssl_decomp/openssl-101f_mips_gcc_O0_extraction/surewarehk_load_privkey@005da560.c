
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 surewarehk_load_privkey(uint param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  int *piVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  uint unaff_s5;
  uint uVar16;
  char local_b5;
  uint local_b4;
  uint local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  char local_58;
  undefined auStack_57 [43];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_b4 = 0;
  local_b0 = 0;
  local_b5 = '\0';
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_ac = s_ENGINE_load_privkey_00674e50._0_4_;
  local_a8 = s_ENGINE_load_privkey_00674e50._4_4_;
  local_a4 = s_ENGINE_load_privkey_00674e50._8_4_;
  local_a0 = s_ENGINE_load_privkey_00674e50._12_4_;
  local_9c = s_ENGINE_load_privkey_00674e50._16_4_;
  if (p_surewarehk_Load_Privkey == (code *)0x0) {
    puVar14 = &_ITM_registerTMCloneTable;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar5 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x69,0x75,"e_sureware.c",0x310);
  }
  else {
    iVar4 = (*p_surewarehk_Load_Privkey)(&local_ac,param_2,&local_b0,&local_b4,&local_b5);
    uVar9 = local_b0;
    uVar16 = local_b4;
    cVar3 = local_b5;
    if (iVar4 == 1) {
      local_6c = s_sureware_load_public_00674e10._0_4_;
      local_68 = s_sureware_load_public_00674e10._4_4_;
      local_64 = s_sureware_load_public_00674e10._8_4_;
      local_60 = s_sureware_load_public_00674e10._12_4_;
      local_5c = s_sureware_load_public_00674e10._16_4_;
      local_58 = s_sureware_load_public_00674e10[20];
      (*(code *)PTR_memset_006aab00)(auStack_57,0,0x2b);
      unaff_s5 = uVar9;
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        puVar14 = &_ITM_registerTMCloneTable;
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar5 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)
                  (SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",0x299);
      }
      else if (cVar3 == '\x01') {
        uVar15 = uVar16 >> 2;
        puVar14 = (undefined1 *)(*(code *)PTR_RSA_new_method_006a881c)(param_1);
        (*(code *)PTR_RSA_set_ex_data_006aa648)(puVar14,rsaHndidx,uVar9);
        puVar1 = PTR_BN_new_006a82b4;
        *(uint *)(puVar14 + 0x3c) = *(uint *)(puVar14 + 0x3c) | 0x20;
        uVar5 = (*(code *)puVar1)();
        puVar1 = PTR_BN_new_006a82b4;
        *(undefined4 *)(puVar14 + 0x14) = uVar5;
        uVar5 = (*(code *)puVar1)();
        puVar1 = PTR_bn_expand2_006a9680;
        *(undefined4 *)(puVar14 + 0x10) = uVar5;
        (*(code *)puVar1)(*(undefined4 *)(puVar14 + 0x14),uVar15);
        (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar14 + 0x10),uVar15);
        puVar6 = *(undefined4 **)(puVar14 + 0x14);
        unaff_s5 = uVar15;
        if ((((puVar6 != (undefined4 *)0x0) && (uVar15 == puVar6[2])) &&
            (puVar7 = *(undefined4 **)(puVar14 + 0x10), puVar7 != (undefined4 *)0x0)) &&
           (uVar15 == puVar7[2])) {
          iVar4 = (*p_surewarehk_Load_Rsa_Pubkey)(&local_6c,param_2,uVar16,*puVar7,*puVar6);
          surewarehk_error_handling(&local_6c,0x6a,iVar4);
          if (iVar4 == 1) {
            piVar12 = *(int **)(puVar14 + 0x14);
            piVar12[1] = uVar15;
            if (uVar15 == 0) {
              *(undefined4 *)(*(int *)(puVar14 + 0x10) + 4) = 0;
            }
            else {
              iVar4 = (uVar16 & 0xfffffffc) - 4;
              piVar11 = (int *)(*piVar12 + iVar4);
              uVar16 = uVar15;
              do {
                uVar9 = uVar16 - 1;
                if (*piVar11 != 0) break;
                piVar11 = piVar11 + -1;
                uVar16 = uVar9;
              } while (uVar9 != 0);
              piVar11 = *(int **)(puVar14 + 0x10);
              piVar12[1] = uVar16;
              piVar11[1] = uVar15;
              piVar12 = (int *)(*piVar11 + iVar4);
              do {
                uVar16 = unaff_s5 - 1;
                if (*piVar12 != 0) break;
                piVar12 = piVar12 + -1;
                unaff_s5 = uVar16;
              } while (uVar16 != 0);
              piVar11[1] = unaff_s5;
            }
            uVar5 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
            uVar10 = 6;
            goto LAB_005dac00;
          }
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)
                    (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2b3);
        }
        uVar5 = 0;
        (*(code *)PTR_RSA_free_006a86f0)(puVar14);
        param_1 = uVar15;
      }
      else {
        puVar14 = &_ITM_registerTMCloneTable;
        if (cVar3 == '\x02') {
          uVar15 = uVar16 >> 2;
          puVar14 = (undefined1 *)(*(code *)PTR_DSA_new_method_006aa688)(param_1);
          (*(code *)PTR_DSA_set_ex_data_006aa68c)(puVar14,dsaHndidx,uVar9);
          uVar5 = (*(code *)PTR_BN_new_006a82b4)();
          puVar1 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar14 + 0x18) = uVar5;
          uVar5 = (*(code *)puVar1)();
          puVar1 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar14 + 0xc) = uVar5;
          uVar5 = (*(code *)puVar1)();
          puVar1 = PTR_BN_new_006a82b4;
          *(undefined4 *)(puVar14 + 0x10) = uVar5;
          uVar5 = (*(code *)puVar1)();
          puVar1 = PTR_bn_expand2_006a9680;
          *(undefined4 *)(puVar14 + 0x14) = uVar5;
          (*(code *)puVar1)(*(undefined4 *)(puVar14 + 0x18),uVar15);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar14 + 0xc),uVar15);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar14 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(puVar14 + 0x14),uVar15);
          puVar6 = *(undefined4 **)(puVar14 + 0x18);
          unaff_s5 = uVar15;
          if ((((puVar6 != (undefined4 *)0x0) && (uVar15 == puVar6[2])) &&
              (puVar7 = *(undefined4 **)(puVar14 + 0xc), puVar7 != (undefined4 *)0x0)) &&
             (((uVar15 == puVar7[2] &&
               (puVar13 = *(undefined4 **)(puVar14 + 0x10), puVar13 != (undefined4 *)0x0)) &&
              ((puVar13[2] == 5 &&
               ((puVar8 = *(undefined4 **)(puVar14 + 0x14), puVar8 != (undefined4 *)0x0 &&
                (uVar15 == puVar8[2])))))))) {
            iVar4 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&local_6c,param_2,uVar16,*puVar6,*puVar7,*puVar13,*puVar8);
            surewarehk_error_handling(&local_6c,0x6a,iVar4);
            if (iVar4 == 1) goto LAB_005dac34;
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x2df);
          }
          uVar5 = 0;
          (*(code *)PTR_DSA_free_006a862c)(puVar14);
          param_1 = uVar15;
        }
        else {
          if (SUREWARE_lib_error_code == 0) {
            SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          uVar5 = 0;
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
      uVar5 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(SUREWARE_lib_error_code,0x69,0x80,"e_sureware.c",0x317);
      (*(code *)PTR_ERR_add_error_data_006a9264)(1,&local_ac);
    }
  }
  do {
    if (local_2c == *(int *)puVar2) {
      return uVar5;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    uVar15 = param_1;
LAB_005dac34:
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
        uVar9 = uVar16 - 1;
        if (*piVar11 != 0) break;
        piVar11 = piVar11 + -1;
        uVar16 = uVar9;
      } while (uVar9 != 0);
      piVar11 = *(int **)(puVar14 + 0xc);
      piVar12[1] = uVar16;
      piVar11[1] = uVar15;
      piVar12 = (int *)(*piVar11 + iVar4);
      uVar16 = uVar15;
      do {
        uVar9 = uVar16 - 1;
        if (*piVar12 != 0) break;
        piVar12 = piVar12 + -1;
        uVar16 = uVar9;
      } while (uVar9 != 0);
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
        uVar16 = unaff_s5 - 1;
        if (*piVar11 != 0) break;
        piVar11 = piVar11 + -1;
        unaff_s5 = uVar16;
      } while (uVar16 != 0);
      piVar12[1] = unaff_s5;
    }
    uVar5 = (*(code *)PTR_EVP_PKEY_new_006a8710)();
    uVar10 = 0x74;
LAB_005dac00:
    (*(code *)PTR_EVP_PKEY_assign_006a94e4)(uVar5,uVar10,puVar14);
    param_1 = uVar15;
  } while( true );
}

