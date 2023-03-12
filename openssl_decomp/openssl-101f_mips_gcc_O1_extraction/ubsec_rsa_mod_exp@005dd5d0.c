
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ubsec_rsa_mod_exp(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  undefined4 *puVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  undefined4 *puVar22;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar22 = *(undefined4 **)(param_3 + 0x1c);
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((((puVar22 == (undefined4 *)0x0) ||
       (puVar16 = *(undefined4 **)(param_3 + 0x20), puVar16 == (undefined4 *)0x0)) ||
      (puVar17 = *(undefined4 **)(param_3 + 0x24), puVar17 == (undefined4 *)0x0)) ||
     ((puVar19 = *(undefined4 **)(param_3 + 0x28), puVar19 == (undefined4 *)0x0 ||
      (puVar21 = *(undefined4 **)(param_3 + 0x2c), puVar21 == (undefined4 *)0x0)))) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6c,0x68,"e_ubsec.c",0x262);
    uVar4 = 0;
  }
  else {
    local_30 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar22);
    iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar16);
    local_30 = local_30 + iVar3;
    if (max_key_len < local_30) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6e,0x6b,"e_ubsec.c",0x27f);
    }
    else {
      if (((int)param_1[2] <= (int)(puVar22[1] + puVar16[1])) &&
         (iVar3 = (*(code *)PTR_bn_expand2_006a9680)(param_1,puVar22[1] + puVar16[1] + 1),
         iVar3 == 0)) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6e,0x65,"e_ubsec.c",0x284);
        uVar4 = 0;
        goto LAB_005dd848;
      }
      iVar3 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
      pcVar2 = p_UBSEC_rsa_mod_exp_crt_ioctl;
      if (iVar3 < 1) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6e,0x6c,"e_ubsec.c",0x28a);
      }
      else {
        uVar12 = *param_2;
        uVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(param_2);
        uVar13 = *puVar21;
        uVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar21);
        uVar18 = *puVar17;
        uVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar17);
        uVar14 = *puVar22;
        uVar7 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar22);
        uVar20 = *puVar19;
        uVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar19);
        uVar15 = *puVar16;
        uVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar16);
        iVar10 = (*pcVar2)(iVar3,uVar12,uVar4,uVar13,uVar5,uVar18,uVar6,uVar14,uVar7,uVar20,uVar8,
                           uVar15,uVar9,*param_1,&local_30);
        if (iVar10 == 0) {
          (*p_UBSEC_ubsec_close)(iVar3);
          iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar22);
          iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar16);
          uVar4 = 1;
          iVar3 = iVar10 + iVar11 + 0x1f;
          if (iVar3 < 0) {
            iVar3 = iVar10 + iVar11 + 0x3e;
          }
          param_1[1] = iVar3 >> 5;
          goto LAB_005dd848;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6e,0x6a,"e_ubsec.c",0x296);
        (*p_UBSEC_ubsec_close)(iVar3);
      }
    }
    iVar3 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
    uVar4 = (**(code **)(iVar3 + 0x14))(param_1,param_2,param_3,param_4);
  }
LAB_005dd848:
  if (local_2c == *(int *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar3 == 0) {
    return 0;
  }
  iVar10 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar3,"ubsec");
  if (((((iVar10 != 0) &&
        (iVar10 = (*(code *)PTR_ENGINE_set_name_006a99e8)(iVar3,"UBSEC hardware engine support"),
        iVar10 != 0)) &&
       (iVar10 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar3,ubsec_rsa), iVar10 != 0)) &&
      ((((iVar10 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar3,ubsec_dsa), iVar10 != 0 &&
         (iVar10 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar3,ubsec_dh), iVar10 != 0)) &&
        ((iVar10 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar3,ubsec_destroy),
         iVar10 != 0 &&
         ((iVar10 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar3,ubsec_init), iVar10 != 0
          && (iVar10 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar3,ubsec_finish),
             iVar10 != 0)))))) &&
       (iVar10 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar3,ubsec_ctrl), iVar10 != 0))))
     && (iVar10 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar3,ubsec_cmd_defns), iVar10 != 0))
  {
    iVar10 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
    ubsec_rsa._4_4_ = *(undefined4 *)(iVar10 + 4);
    ubsec_rsa._8_4_ = *(undefined4 *)(iVar10 + 8);
    ubsec_rsa._12_4_ = *(undefined4 *)(iVar10 + 0xc);
    ubsec_rsa._16_4_ = *(undefined4 *)(iVar10 + 0x10);
    iVar10 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
    ubsec_dh._4_4_ = *(undefined4 *)(iVar10 + 4);
    ubsec_dh._8_4_ = *(undefined4 *)(iVar10 + 8);
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    if (UBSEC_error_init != 0) {
      UBSEC_error_init = 0;
      (*(code *)PTR_ERR_load_strings_006a9564)(UBSEC_lib_error_code,UBSEC_str_functs);
      (*(code *)PTR_ERR_load_strings_006a9564)(UBSEC_lib_error_code,UBSEC_str_reasons);
      UBSEC_lib_name._0_4_ = UBSEC_lib_error_code << 0x18;
      (*(code *)PTR_ERR_load_strings_006a9564)(0,UBSEC_lib_name);
    }
    (*(code *)PTR_ENGINE_add_006a99d8)(iVar3);
    (*(code *)PTR_ENGINE_free_006a7f84)(iVar3);
                    /* WARNING: Could not recover jumptable at 0x005ddc94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)PTR_ERR_clear_error_006a7fe0)();
    return uVar4;
  }
                    /* WARNING: Could not recover jumptable at 0x005ddaf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*(code *)PTR_ENGINE_free_006a7f84)(iVar3);
  return uVar4;
}

