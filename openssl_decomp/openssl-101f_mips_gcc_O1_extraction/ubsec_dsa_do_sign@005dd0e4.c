
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int * ubsec_dsa_do_sign(int param_1,undefined4 *param_2,int param_3,char *param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  undefined4 uVar22;
  undefined4 *puVar23;
  undefined1 *unaff_s6;
  code *pcVar24;
  char *unaff_s8;
  undefined4 *puVar25;
  int iStack_e8;
  int iStack_e4;
  undefined4 *puStack_e0;
  undefined4 *puStack_dc;
  int *piStack_d8;
  int iStack_d4;
  undefined *puStack_d0;
  undefined4 *puStack_cc;
  undefined1 *puStack_c8;
  undefined *puStack_c4;
  char *pcStack_c0;
  code *pcStack_bc;
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
  undefined4 *local_7c;
  undefined4 local_78;
  undefined4 *local_74;
  undefined *local_70;
  code *local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined auStack_40 [20];
  undefined4 *local_2c;
  
  puStack_c4 = PTR___stack_chk_guard_006aabf0;
  puStack_d0 = auStack_40;
  local_48 = 0xa0;
  local_44 = 0xa0;
  local_70 = &_gp;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  puVar13 = param_2;
  iVar2 = param_3;
  (*(code *)PTR_BN_init_006a96a0)(puStack_d0);
  puStack_e0 = (undefined4 *)(**(code **)(local_70 + -0x7c2c))();
  puStack_dc = (undefined4 *)(**(code **)(local_70 + -0x7c2c))();
  if (puStack_e0 == (undefined4 *)0x0) {
    pcVar24 = *(code **)(local_70 + -0x7dc4);
    param_3 = iVar2;
    if (puStack_dc != (undefined4 *)0x0) {
LAB_005dd400:
      (*pcVar24)(puStack_dc);
      param_3 = iVar2;
      if (puStack_e0 != (undefined4 *)0x0) goto LAB_005dd410;
    }
    piStack_d8 = (int *)0x0;
  }
  else if (puStack_dc == (undefined4 *)0x0) {
LAB_005dd410:
    param_3 = iVar2;
    piStack_d8 = (int *)0x0;
    (**(code **)(local_70 + -0x7dc4))(puStack_e0);
  }
  else {
    unaff_s8 = (char *)(*p_UBSEC_ubsec_bytes_to_bits)(param_1,param_2);
    if ((((int)puStack_dc[2] < 5) &&
        (iVar2 = (**(code **)(local_70 + -0x6860))(puStack_dc,5), iVar2 == 0)) ||
       (((int)puStack_e0[2] < 5 &&
        (iVar2 = (**(code **)(local_70 + -0x6860))(puStack_e0,5), iVar2 == 0)))) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (**(code **)(local_70 + -0x589c))();
      }
      param_3 = 0x65;
      param_4 = "e_ubsec.c";
      local_a8 = 0x2f6;
      puVar13 = (undefined4 *)0x66;
      (**(code **)(local_70 + -0x6eb0))(UBSEC_lib_error_code);
LAB_005dd3fc:
      pcVar24 = *(code **)(local_70 + -0x7dc4);
      iVar2 = param_3;
      goto LAB_005dd400;
    }
    iVar2 = (**(code **)(local_70 + -0x74f0))(param_1,param_2,puStack_d0);
    if (iVar2 == 0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (**(code **)(local_70 + -0x589c))();
      }
      param_3 = 0x65;
      param_4 = "e_ubsec.c";
      local_a8 = 0x2fb;
      puVar13 = (undefined4 *)0x66;
      (**(code **)(local_70 + -0x6eb0))(UBSEC_lib_error_code);
      goto LAB_005dd3fc;
    }
    unaff_s6 = (undefined1 *)(*p_UBSEC_ubsec_open)("/dev/ubskey");
    if ((int)unaff_s6 < 1) {
      unaff_s6 = &_ITM_registerTMCloneTable;
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (**(code **)(local_70 + -0x589c))();
      }
      param_4 = "e_ubsec.c";
      local_a8 = 0x302;
      (**(code **)(local_70 + -0x6eb0))(UBSEC_lib_error_code,0x66,0x6c);
LAB_005dd3d0:
      iVar2 = (**(code **)(local_70 + -0x6670))();
      puVar13 = param_2;
      piStack_d8 = (int *)(**(code **)(iVar2 + 4))(param_1);
      if (piStack_d8 == (int *)0x0) goto LAB_005dd3fc;
    }
    else {
      local_4c = **(undefined4 **)(param_3 + 0xc);
      local_68 = p_UBSEC_dsa_sign_ioctl;
      local_50 = (**(code **)(local_70 + -0x7bec))(*(undefined4 **)(param_3 + 0xc));
      local_54 = **(undefined4 **)(param_3 + 0x10);
      local_58 = (**(code **)(local_70 + -0x7bec))(*(undefined4 **)(param_3 + 0x10));
      local_5c = **(undefined4 **)(param_3 + 0x14);
      local_60 = (**(code **)(local_70 + -0x7bec))(*(undefined4 **)(param_3 + 0x14));
      local_64 = **(undefined4 **)(param_3 + 0x1c);
      local_84 = (**(code **)(local_70 + -0x7bec))(*(undefined4 **)(param_3 + 0x1c));
      local_74 = &local_48;
      local_7c = &local_44;
      puVar13 = (undefined4 *)0x0;
      local_78 = *puStack_e0;
      local_80 = *puStack_dc;
      local_88 = local_64;
      local_8c = local_60;
      local_90 = local_5c;
      local_94 = local_58;
      local_98 = local_54;
      local_9c = local_50;
      local_a0 = local_4c;
      local_a4 = 0;
      local_a8 = 0;
      iVar2 = param_1;
      param_4 = unaff_s8;
      iVar3 = (*local_68)(unaff_s6);
      if (iVar3 != 0) {
        unaff_s8 = &_ITM_registerTMCloneTable;
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (**(code **)(local_70 + -0x589c))();
        }
        param_4 = "e_ubsec.c";
        local_a8 = 0x313;
        (**(code **)(local_70 + -0x6eb0))(UBSEC_lib_error_code,0x66,0x6a);
        (*p_UBSEC_ubsec_close)(unaff_s6);
        goto LAB_005dd3d0;
      }
      (*p_UBSEC_ubsec_close)(unaff_s6);
      puStack_dc[1] = 5;
      pcVar24 = *(code **)(local_70 + -0x6660);
      puStack_e0[1] = 5;
      piStack_d8 = (int *)(*pcVar24)();
      if (piStack_d8 == (int *)0x0) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (**(code **)(local_70 + -0x589c))();
        }
        param_3 = 0x65;
        param_4 = "e_ubsec.c";
        local_a8 = 0x322;
        puVar13 = (undefined4 *)0x66;
        (**(code **)(local_70 + -0x6eb0))(UBSEC_lib_error_code);
        goto LAB_005dd3fc;
      }
      *piStack_d8 = (int)puStack_dc;
      piStack_d8[1] = (int)puStack_e0;
      param_3 = iVar2;
    }
  }
  (**(code **)(local_70 + -0x6db0))(puStack_d0);
  if (local_2c == *(undefined4 **)puStack_c4) {
    return piStack_d8;
  }
  pcStack_bc = ubsec_rsa_mod_exp;
  puVar11 = local_2c;
  (**(code **)(local_70 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar25 = *(undefined4 **)(param_3 + 0x1c);
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_d4 = param_1;
  puStack_cc = param_2;
  puStack_c8 = unaff_s6;
  pcStack_c0 = unaff_s8;
  if ((((puVar25 == (undefined4 *)0x0) ||
       (puVar18 = *(undefined4 **)(param_3 + 0x20), puVar18 == (undefined4 *)0x0)) ||
      (puVar19 = *(undefined4 **)(param_3 + 0x24), puVar19 == (undefined4 *)0x0)) ||
     ((puVar21 = *(undefined4 **)(param_3 + 0x28), puVar21 == (undefined4 *)0x0 ||
      (puVar23 = *(undefined4 **)(param_3 + 0x2c), puVar23 == (undefined4 *)0x0)))) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6c,0x68,"e_ubsec.c",0x262);
    piVar12 = (int *)0x0;
  }
  else {
    iStack_e8 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar25);
    iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar18);
    iStack_e8 = iStack_e8 + iVar2;
    if (max_key_len < iStack_e8) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6e,0x6b,"e_ubsec.c",0x27f);
    }
    else {
      if (((int)puVar11[2] <= (int)(puVar25[1] + puVar18[1])) &&
         (iVar2 = (*(code *)PTR_bn_expand2_006a9680)(puVar11,puVar25[1] + puVar18[1] + 1),
         iVar2 == 0)) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6e,0x65,"e_ubsec.c",0x284);
        piVar12 = (int *)0x0;
        goto LAB_005dd848;
      }
      iVar2 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
      pcVar24 = p_UBSEC_rsa_mod_exp_crt_ioctl;
      if (iVar2 < 1) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6e,0x6c,"e_ubsec.c",0x28a);
      }
      else {
        uVar14 = *puVar13;
        uVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar13);
        uVar15 = *puVar23;
        uVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar23);
        uVar20 = *puVar19;
        uVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar19);
        uVar16 = *puVar25;
        uVar7 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar25);
        uVar22 = *puVar21;
        uVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar21);
        uVar17 = *puVar18;
        uVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar18);
        iVar3 = (*pcVar24)(iVar2,uVar14,uVar4,uVar15,uVar5,uVar20,uVar6,uVar16,uVar7,uVar22,uVar8,
                           uVar17,uVar9,*puVar11,&iStack_e8);
        if (iVar3 == 0) {
          (*p_UBSEC_ubsec_close)(iVar2);
          iVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar25);
          iVar10 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar18);
          piVar12 = (int *)0x1;
          iVar2 = iVar3 + iVar10 + 0x1f;
          if (iVar2 < 0) {
            iVar2 = iVar3 + iVar10 + 0x3e;
          }
          puVar11[1] = iVar2 >> 5;
          goto LAB_005dd848;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6e,0x6a,"e_ubsec.c",0x296);
        (*p_UBSEC_ubsec_close)(iVar2);
      }
    }
    iVar2 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
    piVar12 = (int *)(**(code **)(iVar2 + 0x14))(puVar11,puVar13,param_3,param_4);
  }
LAB_005dd848:
  if (iStack_e4 == *(int *)puVar1) {
    return piVar12;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar2 == 0) {
    return (int *)0x0;
  }
  iVar3 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar2,"ubsec");
  if (((((iVar3 != 0) &&
        (iVar3 = (*(code *)PTR_ENGINE_set_name_006a99e8)(iVar2,"UBSEC hardware engine support"),
        iVar3 != 0)) &&
       (iVar3 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar2,ubsec_rsa), iVar3 != 0)) &&
      ((((iVar3 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar2,ubsec_dsa), iVar3 != 0 &&
         (iVar3 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar2,ubsec_dh), iVar3 != 0)) &&
        ((iVar3 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar2,ubsec_destroy),
         iVar3 != 0 &&
         ((iVar3 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar2,ubsec_init), iVar3 != 0 &&
          (iVar3 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar2,ubsec_finish),
          iVar3 != 0)))))) &&
       (iVar3 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar2,ubsec_ctrl), iVar3 != 0))))
     && (iVar3 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar2,ubsec_cmd_defns), iVar3 != 0)) {
    iVar3 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
    ubsec_rsa._4_4_ = *(undefined4 *)(iVar3 + 4);
    ubsec_rsa._8_4_ = *(undefined4 *)(iVar3 + 8);
    ubsec_rsa._12_4_ = *(undefined4 *)(iVar3 + 0xc);
    ubsec_rsa._16_4_ = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
    ubsec_dh._4_4_ = *(undefined4 *)(iVar3 + 4);
    ubsec_dh._8_4_ = *(undefined4 *)(iVar3 + 8);
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
    (*(code *)PTR_ENGINE_add_006a99d8)(iVar2);
    (*(code *)PTR_ENGINE_free_006a7f84)(iVar2);
                    /* WARNING: Could not recover jumptable at 0x005ddc94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    piVar12 = (int *)(*(code *)PTR_ERR_clear_error_006a7fe0)();
    return piVar12;
  }
                    /* WARNING: Could not recover jumptable at 0x005ddaf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  piVar12 = (int *)(*(code *)PTR_ENGINE_free_006a7f84)(iVar2);
  return piVar12;
}

