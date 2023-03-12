
uint cswift_dsa_verify(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  int *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined auStack_3c [16];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar2 == 0) {
    uVar12 = 0xffffffff;
    goto LAB_005d202c;
  }
  iVar3 = (*p_CSwift_AcquireAccContext)(&local_88);
  if (iVar3 == 0) {
    (*(code *)PTR_BN_CTX_start_006a8528)(iVar2);
    puVar4 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
    puVar5 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
    puVar6 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
    puVar7 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
    piVar8 = (int *)(*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
    if (piVar8 == (int *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar11 = 0x66;
      uVar13 = 0x39f;
LAB_005d2148:
      uVar12 = 0xffffffff;
      (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,0x66,uVar11,"e_cswift.c",uVar13);
    }
    else {
      if (((int)puVar4[2] < *(int *)(*(int *)(param_4 + 0xc) + 4)) &&
         (iVar3 = (*(code *)PTR_bn_expand2_006a8524)(puVar4), iVar3 == 0)) {
LAB_005d2174:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar11 = 0x67;
        uVar13 = 0x3a7;
        goto LAB_005d2148;
      }
      if ((int)puVar5[2] < *(int *)(*(int *)(param_4 + 0x10) + 4)) {
        iVar3 = (*(code *)PTR_bn_expand2_006a8524)(puVar5);
        if (iVar3 != 0) {
          if ((int)puVar6[2] < *(int *)(*(int *)(param_4 + 0x14) + 4)) goto LAB_005d21d8;
          goto LAB_005d1e14;
        }
        goto LAB_005d2174;
      }
      if ((int)puVar6[2] < *(int *)(*(int *)(param_4 + 0x14) + 4)) {
LAB_005d21d8:
        iVar3 = (*(code *)PTR_bn_expand2_006a8524)(puVar6);
        if (iVar3 == 0) goto LAB_005d2174;
        if ((int)puVar7[2] < *(int *)(*(int *)(param_4 + 0x18) + 4)) goto LAB_005d2200;
LAB_005d1e2c:
        iVar3 = piVar8[2];
      }
      else {
LAB_005d1e14:
        if (*(int *)(*(int *)(param_4 + 0x18) + 4) <= (int)puVar7[2]) goto LAB_005d1e2c;
LAB_005d2200:
        iVar3 = (*(code *)PTR_bn_expand2_006a8524)(puVar7);
        if (iVar3 == 0) goto LAB_005d2174;
        iVar3 = piVar8[2];
      }
      if ((iVar3 < 0x28) && (iVar3 = (*(code *)PTR_bn_expand2_006a8524)(piVar8,0x28), iVar3 == 0))
      goto LAB_005d2174;
      local_78 = 3;
      local_74 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)(param_4 + 0xc),*puVar4);
      local_70 = *puVar4;
      local_6c = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)(param_4 + 0x10),*puVar5);
      local_68 = *puVar5;
      local_64 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)(param_4 + 0x14),*puVar6);
      local_60 = *puVar6;
      local_5c = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)(param_4 + 0x18),*puVar7);
      local_58 = *puVar7;
      iVar3 = (*p_CSwift_AttachKeyParam)(local_88,&local_78);
      if (iVar3 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar11 = 0x65;
        uVar13 = 0x3ba;
        goto LAB_005d2148;
      }
      if (iVar3 == 0) {
        local_40 = *piVar8;
        local_44 = 0x28;
        local_4c = param_2;
        local_48 = param_1;
        (*(code *)PTR_memset_006a99f4)(local_40,0,0x28);
        iVar3 = local_40;
        uVar13 = *param_3;
        iVar9 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar13);
        iVar10 = iVar9 + 7;
        if (iVar9 + 7 < 0) {
          iVar10 = iVar9 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a7200)(uVar13,(iVar3 - (iVar10 >> 3)) + 0x14);
        iVar3 = local_40;
        uVar13 = param_3[1];
        iVar9 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar13);
        iVar10 = iVar9 + 7;
        if (iVar9 + 7 < 0) {
          iVar10 = iVar9 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a7200)(uVar13,(iVar3 - (iVar10 >> 3)) + 0x28);
        local_80 = 4;
        local_7c = &local_84;
        iVar3 = (*p_CSwift_SimpleRequest)(local_88,4,&local_4c,2,&local_80,1);
        if (iVar3 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          uVar13 = 0x3d4;
          goto LAB_005d20c8;
        }
        uVar12 = (uint)(local_84 != 0);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar13 = 0x3bf;
LAB_005d20c8:
        (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",uVar13);
        (*(code *)PTR___sprintf_chk_006a9930)(auStack_3c,1,0xd,&DAT_0066f118,iVar3);
        uVar12 = 0xffffffff;
        (*(code *)PTR_ERR_add_error_data_006a813c)(2,"CryptoSwift error number is ",auStack_3c);
      }
    }
    (*p_CSwift_ReleaseAccContext)(local_88);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar12 = 0xffffffff;
    (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,0x66,0x6c,"e_cswift.c",0x393);
  }
  (*(code *)PTR_BN_CTX_end_006a8530)(iVar2);
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar2);
LAB_005d202c:
  if (local_2c == *(int *)puVar1) {
    return uVar12;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = (*(code *)PTR_ENGINE_new_006a87cc)();
  if (iVar2 != 0) {
    iVar3 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar2,"cswift");
    if ((((((iVar3 != 0) &&
           (iVar3 = (*(code *)PTR_ENGINE_set_name_006a88c8)
                              (iVar2,"CryptoSwift hardware engine support"), iVar3 != 0)) &&
          (iVar3 = (*(code *)PTR_ENGINE_set_RSA_006a9544)(iVar2,cswift_rsa), iVar3 != 0)) &&
         ((iVar3 = (*(code *)PTR_ENGINE_set_DSA_006a9558)(iVar2,cswift_dsa), iVar3 != 0 &&
          (iVar3 = (*(code *)PTR_ENGINE_set_DH_006a955c)(iVar2,cswift_dh), iVar3 != 0)))) &&
        ((iVar3 = (*(code *)PTR_ENGINE_set_RAND_006a9548)(iVar2,cswift_random), iVar3 != 0 &&
         ((iVar3 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)(iVar2,cswift_destroy),
          iVar3 != 0 &&
          (iVar3 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)(iVar2,cswift_init), iVar3 != 0))
         )))) && ((iVar3 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)(iVar2,cswift_finish),
                  iVar3 != 0 &&
                  ((iVar3 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)(iVar2,cswift_ctrl),
                   iVar3 != 0 &&
                   (iVar3 = (*(code *)PTR_ENGINE_set_cmd_defns_006a88dc)(iVar2,cswift_cmd_defns),
                   iVar3 != 0)))))) {
      iVar3 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a7aec)();
      cswift_rsa._4_4_ = *(undefined4 *)(iVar3 + 4);
      cswift_rsa._8_4_ = *(undefined4 *)(iVar3 + 8);
      cswift_rsa._12_4_ = *(undefined4 *)(iVar3 + 0xc);
      cswift_rsa._16_4_ = *(undefined4 *)(iVar3 + 0x10);
      iVar3 = (*(code *)PTR_DH_OpenSSL_006a8788)();
      cswift_dh._4_4_ = *(undefined4 *)(iVar3 + 4);
      cswift_dh._8_4_ = *(undefined4 *)(iVar3 + 8);
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      if (CSWIFT_error_init != 0) {
        CSWIFT_error_init = 0;
        (*(code *)PTR_ERR_load_strings_006a8444)(CSWIFT_lib_error_code,CSWIFT_str_functs);
        (*(code *)PTR_ERR_load_strings_006a8444)(CSWIFT_lib_error_code,CSWIFT_str_reasons);
        CSWIFT_lib_name._0_4_ = CSWIFT_lib_error_code << 0x18;
        (*(code *)PTR_ERR_load_strings_006a8444)(0,CSWIFT_lib_name);
      }
      (*(code *)PTR_ENGINE_add_006a88b8)(iVar2);
      (*(code *)PTR_ENGINE_free_006a6e84)(iVar2);
                    /* WARNING: Could not recover jumptable at 0x005d25b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar12 = (*(code *)PTR_ERR_clear_error_006a6ee0)();
      return uVar12;
    }
                    /* WARNING: Could not recover jumptable at 0x005d2384. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar12 = (*(code *)PTR_ENGINE_free_006a6e84)(iVar2);
    return uVar12;
  }
  return 0;
}

