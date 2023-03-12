
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 * surewarehk_load_privkey(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined4 *unaff_s4;
  undefined4 *puVar13;
  char local_b5;
  uint local_b4;
  undefined4 *local_b0;
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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_b4 = 0;
  local_b0 = (undefined4 *)0x0;
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
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_ac = s_ENGINE_load_privkey_00674560._0_4_;
  local_a8 = s_ENGINE_load_privkey_00674560._4_4_;
  local_a4 = s_ENGINE_load_privkey_00674560._8_4_;
  local_a0 = s_ENGINE_load_privkey_00674560._12_4_;
  local_9c = s_ENGINE_load_privkey_00674560._16_4_;
  if (p_surewarehk_Load_Privkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    puVar12 = (undefined4 *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x69,0x75,"e_sureware.c",0x33d);
  }
  else {
    unaff_s4 = &local_ac;
    iVar5 = (*p_surewarehk_Load_Privkey)(unaff_s4,param_2,&local_b0,&local_b4,&local_b5);
    puVar13 = local_b0;
    uVar4 = local_b4;
    cVar3 = local_b5;
    if (iVar5 == 1) {
      local_6c = s_sureware_load_public_00674520._0_4_;
      local_68 = s_sureware_load_public_00674520._4_4_;
      local_64 = s_sureware_load_public_00674520._8_4_;
      local_60 = s_sureware_load_public_00674520._12_4_;
      local_5c = s_sureware_load_public_00674520._16_4_;
      local_58 = s_sureware_load_public_00674520[20];
      (*(code *)PTR_memset_006a99f4)(auStack_57,0,0x2b);
      unaff_s4 = puVar13;
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        puVar12 = (undefined4 *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
      }
      else if (cVar3 == '\x01') {
        param_1 = (*(code *)PTR_RSA_new_method_006a772c)(param_1);
        (*(code *)PTR_RSA_set_ex_data_006a953c)(param_1,rsaHndidx,puVar13);
        puVar1 = PTR_BN_new_006a71b4;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
        uVar6 = (*(code *)puVar1)();
        puVar1 = PTR_BN_new_006a71b4;
        *(undefined4 *)(param_1 + 0x14) = uVar6;
        iVar5 = (*(code *)puVar1)();
        *(int *)(param_1 + 0x10) = iVar5;
        if ((*(int *)(param_1 + 0x14) != 0) && (iVar5 != 0)) {
          puVar13 = (undefined4 *)(uVar4 >> 2);
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(param_1 + 0x14),puVar13);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(param_1 + 0x10),puVar13);
          if ((puVar13 == (undefined4 *)(*(undefined4 **)(param_1 + 0x14))[2]) &&
             (puVar13 == (undefined4 *)(*(undefined4 **)(param_1 + 0x10))[2])) {
            iVar5 = (*p_surewarehk_Load_Rsa_Pubkey)
                              (&local_6c,param_2,uVar4,**(undefined4 **)(param_1 + 0x10),
                               **(undefined4 **)(param_1 + 0x14));
            surewarehk_error_handling(&local_6c,0x6a,iVar5);
            if (iVar5 == 1) {
              piVar11 = *(int **)(param_1 + 0x14);
              piVar11[1] = (int)puVar13;
              if (puVar13 == (undefined4 *)0x0) {
                *(undefined4 *)(*(int *)(param_1 + 0x10) + 4) = 0;
              }
              else {
                iVar5 = (uVar4 & 0xfffffffc) - 4;
                piVar8 = (int *)(*piVar11 + iVar5);
                puVar12 = puVar13;
                do {
                  puVar9 = (undefined4 *)((int)puVar12 - 1);
                  if (*piVar8 != 0) break;
                  piVar8 = piVar8 + -1;
                  puVar12 = puVar9;
                } while (puVar9 != (undefined4 *)0x0);
                piVar8 = *(int **)(param_1 + 0x10);
                piVar11[1] = (int)puVar12;
                piVar8[1] = (int)puVar13;
                piVar11 = (int *)(*piVar8 + iVar5);
                do {
                  puVar12 = (undefined4 *)((int)puVar13 - 1);
                  if (*piVar11 != 0) break;
                  piVar11 = piVar11 + -1;
                  puVar13 = puVar12;
                } while (puVar12 != (undefined4 *)0x0);
                piVar8[1] = (int)puVar13;
              }
              puVar12 = (undefined4 *)(*(code *)PTR_EVP_PKEY_new_006a7620)();
              uVar6 = 6;
              goto LAB_005d8738;
            }
            if (SUREWARE_lib_error_code == 0) {
              SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            (*(code *)PTR_ERR_put_error_006a7f34)
                      (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2d8);
          }
        }
        puVar12 = (undefined4 *)0x0;
        (*(code *)PTR_RSA_free_006a7600)(param_1);
        unaff_s4 = puVar13;
      }
      else if (cVar3 == '\x02') {
        param_1 = (*(code *)PTR_DSA_new_method_006a957c)(param_1);
        (*(code *)PTR_DSA_set_ex_data_006a9580)(param_1,dsaHndidx,puVar13);
        uVar6 = (*(code *)PTR_BN_new_006a71b4)();
        puVar1 = PTR_BN_new_006a71b4;
        *(undefined4 *)(param_1 + 0x18) = uVar6;
        uVar6 = (*(code *)puVar1)();
        puVar1 = PTR_BN_new_006a71b4;
        *(undefined4 *)(param_1 + 0xc) = uVar6;
        uVar6 = (*(code *)puVar1)();
        puVar1 = PTR_BN_new_006a71b4;
        *(undefined4 *)(param_1 + 0x10) = uVar6;
        iVar5 = (*(code *)puVar1)();
        *(int *)(param_1 + 0x14) = iVar5;
        if ((((*(int *)(param_1 + 0x18) != 0) && (*(int *)(param_1 + 0xc) != 0)) &&
            (*(int *)(param_1 + 0x10) != 0)) && (iVar5 != 0)) {
          puVar12 = (undefined4 *)(uVar4 >> 2);
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(param_1 + 0x18),puVar12);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(param_1 + 0xc),puVar12);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(param_1 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(param_1 + 0x14),puVar12);
          puVar13 = puVar12;
          if (((puVar12 == (undefined4 *)(*(undefined4 **)(param_1 + 0x18))[2]) &&
              (puVar12 == (undefined4 *)(*(undefined4 **)(param_1 + 0xc))[2])) &&
             (((*(undefined4 **)(param_1 + 0x10))[2] == 5 &&
              (puVar12 == (undefined4 *)(*(undefined4 **)(param_1 + 0x14))[2])))) {
            iVar5 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&local_6c,param_2,uVar4,**(undefined4 **)(param_1 + 0x18),
                               **(undefined4 **)(param_1 + 0xc),**(undefined4 **)(param_1 + 0x10),
                               **(undefined4 **)(param_1 + 0x14));
            surewarehk_error_handling(&local_6c,0x6a,iVar5);
            if (iVar5 == 1) {
              piVar11 = *(int **)(param_1 + 0x18);
              piVar11[1] = (int)puVar12;
              unaff_s4 = puVar12;
              if (puVar12 == (undefined4 *)0x0) goto LAB_005d876c;
              iVar5 = (uVar4 & 0xfffffffc) - 4;
              piVar8 = (int *)(*piVar11 + iVar5);
              puVar9 = puVar12;
              do {
                puVar10 = (undefined4 *)((int)puVar9 - 1);
                if (*piVar8 != 0) break;
                piVar8 = piVar8 + -1;
                puVar9 = puVar10;
              } while (puVar10 != (undefined4 *)0x0);
              piVar8 = *(int **)(param_1 + 0xc);
              piVar11[1] = (int)puVar9;
              piVar8[1] = (int)puVar12;
              piVar11 = (int *)(*piVar8 + iVar5);
              puVar9 = puVar12;
              do {
                puVar10 = (undefined4 *)((int)puVar9 - 1);
                if (*piVar11 != 0) break;
                piVar11 = piVar11 + -1;
                puVar9 = puVar10;
              } while (puVar10 != (undefined4 *)0x0);
              piVar8[1] = (int)puVar9;
              goto LAB_005d85b0;
            }
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
          }
        }
        puVar12 = (undefined4 *)0x0;
        (*(code *)PTR_DSA_free_006a7530)(param_1);
        unaff_s4 = puVar13;
      }
      else {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        puVar12 = (undefined4 *)0x0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
      }
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      puVar12 = (undefined4 *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x69,0x80,"e_sureware.c",0x342);
      (*(code *)PTR_ERR_add_error_data_006a813c)(1,unaff_s4);
    }
  }
  do {
    if (local_2c == *(int *)puVar2) {
      return puVar12;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005d876c:
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 4) = 0;
    puVar13 = unaff_s4;
LAB_005d85b0:
    piVar11 = *(int **)(param_1 + 0x10);
    iVar7 = 5;
    piVar11[1] = 5;
    iVar5 = *piVar11 + 0xc;
    do {
      if (*(int *)(iVar5 + 4) != 0) break;
      iVar7 = iVar7 + -1;
      iVar5 = iVar5 + -4;
    } while (iVar7 != 0);
    piVar8 = *(int **)(param_1 + 0x14);
    piVar11[1] = iVar7;
    piVar8[1] = (int)puVar12;
    if (0 < (int)puVar12) {
      iVar5 = *piVar8 + (int)puVar12 * 4 + -8;
      do {
        if (*(int *)(iVar5 + 4) != 0) break;
        puVar13 = (undefined4 *)((int)puVar13 - 1);
        iVar5 = iVar5 + -4;
      } while (puVar13 != (undefined4 *)0x0);
      piVar8[1] = (int)puVar13;
    }
    puVar12 = (undefined4 *)(*(code *)PTR_EVP_PKEY_new_006a7620)();
    uVar6 = 0x74;
LAB_005d8738:
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(puVar12,uVar6,param_1);
    unaff_s4 = puVar13;
  } while( true );
}

