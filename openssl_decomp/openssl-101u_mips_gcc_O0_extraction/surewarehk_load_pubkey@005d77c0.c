
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint surewarehk_load_pubkey(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  uint unaff_s5;
  uint uVar10;
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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_b0 = 0;
  local_b1 = '\0';
  local_ac = s_ENGINE_load_pubkey_006744e0._0_4_;
  local_a8 = s_ENGINE_load_pubkey_006744e0._4_4_;
  local_a4 = s_ENGINE_load_pubkey_006744e0._8_4_;
  local_a0 = s_ENGINE_load_pubkey_006744e0._12_4_;
  local_9c = s_ENGINE_load_pubkey_006744e0._16_2_;
  local_9a = s_ENGINE_load_pubkey_006744e0[18];
  (*(code *)PTR_memset_006a99f4)(auStack_99,0,0x2d);
  if (p_surewarehk_Info_Pubkey == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar9 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x75,"e_sureware.c",0x357);
  }
  else {
    iVar3 = (*p_surewarehk_Info_Pubkey)(&local_ac,param_2,&local_b0,&local_b1);
    uVar10 = local_b0;
    if (iVar3 == 1) {
      unaff_s5 = (uint)local_b1;
      local_6c = s_sureware_load_public_00674520._0_4_;
      local_68 = s_sureware_load_public_00674520._4_4_;
      local_64 = s_sureware_load_public_00674520._8_4_;
      local_60 = s_sureware_load_public_00674520._12_4_;
      local_5c = s_sureware_load_public_00674520._16_4_;
      local_58 = s_sureware_load_public_00674520[20];
      (*(code *)PTR_memset_006a99f4)(auStack_57,0,0x2b);
      if ((p_surewarehk_Load_Rsa_Pubkey == (code *)0x0) ||
         (p_surewarehk_Load_Dsa_Pubkey == (code *)0x0)) {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar9 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x75,"e_sureware.c",700);
      }
      else if (unaff_s5 == 1) {
        param_1 = (*(code *)PTR_RSA_new_method_006a772c)(param_1);
        (*(code *)PTR_RSA_set_ex_data_006a953c)(param_1,rsaHndidx,0);
        puVar1 = PTR_BN_new_006a71b4;
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x20;
        uVar4 = (*(code *)puVar1)();
        puVar1 = PTR_BN_new_006a71b4;
        *(undefined4 *)(param_1 + 0x14) = uVar4;
        iVar3 = (*(code *)puVar1)();
        *(int *)(param_1 + 0x10) = iVar3;
        if ((*(int *)(param_1 + 0x14) != 0) && (iVar3 != 0)) {
          uVar9 = uVar10 >> 2;
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(param_1 + 0x14),uVar9);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(param_1 + 0x10),uVar9);
          if ((uVar9 == (*(undefined4 **)(param_1 + 0x14))[2]) &&
             (uVar9 == (*(undefined4 **)(param_1 + 0x10))[2])) {
            iVar3 = (*p_surewarehk_Load_Rsa_Pubkey)
                              (&local_6c,param_2,uVar10,**(undefined4 **)(param_1 + 0x10),
                               **(undefined4 **)(param_1 + 0x14));
            surewarehk_error_handling(&local_6c,0x6a,iVar3);
            if (iVar3 == 1) {
              piVar8 = *(int **)(param_1 + 0x14);
              piVar8[1] = uVar9;
              if (uVar9 == 0) {
                *(undefined4 *)(*(int *)(param_1 + 0x10) + 4) = 0;
              }
              else {
                iVar3 = (uVar10 & 0xfffffffc) - 4;
                piVar6 = (int *)(*piVar8 + iVar3);
                uVar10 = uVar9;
                do {
                  uVar7 = uVar10 - 1;
                  if (*piVar6 != 0) break;
                  piVar6 = piVar6 + -1;
                  uVar10 = uVar7;
                } while (uVar7 != 0);
                piVar6 = *(int **)(param_1 + 0x10);
                piVar8[1] = uVar10;
                piVar6[1] = uVar9;
                piVar8 = (int *)(*piVar6 + iVar3);
                do {
                  uVar10 = uVar9 - 1;
                  if (*piVar8 != 0) break;
                  piVar8 = piVar8 + -1;
                  uVar9 = uVar10;
                } while (uVar10 != 0);
                piVar6[1] = uVar9;
              }
              uVar9 = (*(code *)PTR_EVP_PKEY_new_006a7620)();
              uVar4 = 6;
              goto LAB_005d7f4c;
            }
            if (SUREWARE_lib_error_code == 0) {
              SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            (*(code *)PTR_ERR_put_error_006a7f34)
                      (SUREWARE_lib_error_code,0x6a,0x81,"e_sureware.c",0x2d8);
          }
        }
        uVar9 = 0;
        (*(code *)PTR_RSA_free_006a7600)(param_1);
      }
      else if (unaff_s5 == 2) {
        param_1 = (*(code *)PTR_DSA_new_method_006a957c)(param_1);
        (*(code *)PTR_DSA_set_ex_data_006a9580)(param_1,dsaHndidx,0);
        uVar4 = (*(code *)PTR_BN_new_006a71b4)();
        puVar1 = PTR_BN_new_006a71b4;
        *(undefined4 *)(param_1 + 0x18) = uVar4;
        uVar4 = (*(code *)puVar1)();
        puVar1 = PTR_BN_new_006a71b4;
        *(undefined4 *)(param_1 + 0xc) = uVar4;
        uVar4 = (*(code *)puVar1)();
        puVar1 = PTR_BN_new_006a71b4;
        *(undefined4 *)(param_1 + 0x10) = uVar4;
        iVar3 = (*(code *)puVar1)();
        *(int *)(param_1 + 0x14) = iVar3;
        if ((((*(int *)(param_1 + 0x18) != 0) && (*(int *)(param_1 + 0xc) != 0)) &&
            (*(int *)(param_1 + 0x10) != 0)) && (iVar3 != 0)) {
          uVar9 = uVar10 >> 2;
          (*(code *)PTR_bn_expand2_006a8524)(*(int *)(param_1 + 0x18),uVar9);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(param_1 + 0xc),uVar9);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(param_1 + 0x10),5);
          (*(code *)PTR_bn_expand2_006a8524)(*(undefined4 *)(param_1 + 0x14),uVar9);
          unaff_s5 = uVar9;
          if (((uVar9 == (*(undefined4 **)(param_1 + 0x18))[2]) &&
              (uVar9 == (*(undefined4 **)(param_1 + 0xc))[2])) &&
             (((*(undefined4 **)(param_1 + 0x10))[2] == 5 &&
              (uVar9 == (*(undefined4 **)(param_1 + 0x14))[2])))) {
            iVar3 = (*p_surewarehk_Load_Dsa_Pubkey)
                              (&local_6c,param_2,uVar10,**(undefined4 **)(param_1 + 0x18),
                               **(undefined4 **)(param_1 + 0xc),**(undefined4 **)(param_1 + 0x10),
                               **(undefined4 **)(param_1 + 0x14));
            surewarehk_error_handling(&local_6c,0x6a,iVar3);
            if (iVar3 == 1) {
              piVar8 = *(int **)(param_1 + 0x18);
              piVar8[1] = uVar9;
              if (uVar9 == 0) goto LAB_005d7f80;
              iVar3 = (uVar10 & 0xfffffffc) - 4;
              piVar6 = (int *)(*piVar8 + iVar3);
              uVar10 = uVar9;
              do {
                uVar7 = uVar10 - 1;
                if (*piVar6 != 0) break;
                piVar6 = piVar6 + -1;
                uVar10 = uVar7;
              } while (uVar7 != 0);
              piVar6 = *(int **)(param_1 + 0xc);
              piVar8[1] = uVar10;
              piVar6[1] = uVar9;
              piVar8 = (int *)(*piVar6 + iVar3);
              uVar10 = uVar9;
              do {
                uVar7 = uVar10 - 1;
                if (*piVar8 != 0) break;
                piVar8 = piVar8 + -1;
                uVar10 = uVar7;
              } while (uVar7 != 0);
              piVar6[1] = uVar10;
              goto LAB_005d7dc4;
            }
            ERR_SUREWARE_error_constprop_5(0x6a,0x81,0x30a);
          }
        }
        uVar9 = 0;
        (*(code *)PTR_DSA_free_006a7530)(param_1);
      }
      else {
        if (SUREWARE_lib_error_code == 0) {
          SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar9 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6a,0x80,"e_sureware.c",800);
      }
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar9 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x71,0x81,"e_sureware.c",0x35d);
      (*(code *)PTR_ERR_add_error_data_006a813c)(1,&local_ac);
    }
  }
  do {
    if (local_2c == *(int *)puVar2) {
      return uVar9;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005d7f80:
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 4) = 0;
LAB_005d7dc4:
    piVar8 = *(int **)(param_1 + 0x10);
    iVar5 = 5;
    piVar8[1] = 5;
    iVar3 = *piVar8 + 0xc;
    do {
      if (*(int *)(iVar3 + 4) != 0) break;
      iVar5 = iVar5 + -1;
      iVar3 = iVar3 + -4;
    } while (iVar5 != 0);
    piVar6 = *(int **)(param_1 + 0x14);
    piVar8[1] = iVar5;
    piVar6[1] = uVar9;
    if (0 < (int)uVar9) {
      iVar3 = *piVar6 + uVar9 * 4 + -8;
      do {
        if (*(int *)(iVar3 + 4) != 0) break;
        unaff_s5 = unaff_s5 - 1;
        iVar3 = iVar3 + -4;
      } while (unaff_s5 != 0);
      piVar6[1] = unaff_s5;
    }
    uVar9 = (*(code *)PTR_EVP_PKEY_new_006a7620)();
    uVar4 = 0x74;
LAB_005d7f4c:
    (*(code *)PTR_EVP_PKEY_assign_006a83cc)(uVar9,uVar4,param_1);
  } while( true );
}

