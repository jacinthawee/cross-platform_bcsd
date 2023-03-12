
undefined4 * cswift_dsa_sign(undefined4 param_1,char *param_2,char **param_3,char *param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  char *pcVar12;
  char **ppcVar13;
  undefined4 uVar14;
  int unaff_s0;
  int *unaff_s2;
  int *unaff_s3;
  undefined4 *unaff_s4;
  undefined4 *unaff_s5;
  undefined4 *unaff_s6;
  code *pcVar15;
  undefined4 uStack_130;
  int iStack_12c;
  undefined4 uStack_128;
  int *piStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  char *pcStack_f4;
  int iStack_f0;
  undefined4 uStack_ec;
  int iStack_e8;
  undefined auStack_e4 [16];
  int iStack_d4;
  int iStack_d0;
  undefined4 *puStack_cc;
  int *piStack_c8;
  int *piStack_c4;
  undefined4 *puStack_c0;
  undefined4 *puStack_bc;
  undefined4 *puStack_b8;
  undefined *puStack_b4;
  char *pcStack_b0;
  code *pcStack_ac;
  char *pcStack_a4;
  int *local_98;
  undefined4 local_94;
  undefined *local_90;
  undefined4 local_84;
  undefined4 local_7c;
  char *local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  char *apcStack_3c [4];
  int local_2c;
  
  puStack_b4 = PTR___stack_chk_guard_006aabf0;
  local_90 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pcStack_a4 = param_2;
  ppcVar13 = param_3;
  local_84 = param_1;
  iVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar2 == 0) {
    puStack_cc = (undefined4 *)0x0;
  }
  else {
    iVar3 = (*p_CSwift_AcquireAccContext)(&local_7c);
    if (iVar3 == 0) {
      (**(code **)(local_90 + -0x689c))(iVar2);
      unaff_s3 = (int *)(**(code **)(local_90 + -0x6898))(iVar2);
      unaff_s4 = (undefined4 *)(**(code **)(local_90 + -0x6898))(iVar2);
      unaff_s5 = (undefined4 *)(**(code **)(local_90 + -0x6898))(iVar2);
      unaff_s6 = (undefined4 *)(**(code **)(local_90 + -0x6898))(iVar2);
      unaff_s2 = (int *)(**(code **)(local_90 + -0x6898))(iVar2);
      if (unaff_s2 == (int *)0x0) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
        }
        pcVar15 = *(code **)(local_90 + -0x6eb0);
        ppcVar13 = (char **)0x66;
        local_98 = (int *)0x348;
LAB_005d40a4:
        param_4 = "e_cswift.c";
        pcStack_a4 = (char *)0x65;
        puStack_cc = (undefined4 *)0x0;
        (*pcVar15)(CSWIFT_lib_error_code);
      }
      else {
        if ((unaff_s3[2] < *(int *)(param_3[3] + 4)) &&
           (iVar3 = (**(code **)(local_90 + -0x6860))(unaff_s3), iVar3 == 0)) {
LAB_005d40cc:
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
          }
          pcVar15 = *(code **)(local_90 + -0x6eb0);
          ppcVar13 = (char **)0x67;
          local_98 = (int *)0x351;
          goto LAB_005d40a4;
        }
        pcVar15 = *(code **)(local_90 + -0x6860);
        if ((int)unaff_s4[2] < *(int *)(param_3[4] + 4)) {
          iVar3 = (*pcVar15)(unaff_s4);
          if (iVar3 != 0) {
            pcVar15 = *(code **)(local_90 + -0x6860);
            if ((int)unaff_s5[2] < *(int *)(param_3[5] + 4)) goto LAB_005d411c;
            goto LAB_005d3da4;
          }
          goto LAB_005d40cc;
        }
        if ((int)unaff_s5[2] < *(int *)(param_3[5] + 4)) {
LAB_005d411c:
          iVar3 = (*pcVar15)(unaff_s5);
          if (iVar3 == 0) goto LAB_005d40cc;
          pcVar15 = *(code **)(local_90 + -0x6860);
          if ((int)unaff_s6[2] < *(int *)(param_3[7] + 4)) goto LAB_005d4144;
LAB_005d3dbc:
          pcVar12 = param_3[3];
          pcVar15 = *(code **)(local_90 + -0x6860);
          if (unaff_s2[2] < *(int *)(pcVar12 + 4)) {
LAB_005d4170:
            iVar3 = (*pcVar15)(unaff_s2);
            if (iVar3 == 0) goto LAB_005d40cc;
            pcVar12 = param_3[3];
          }
        }
        else {
LAB_005d3da4:
          pcVar15 = *(code **)(local_90 + -0x6860);
          if (*(int *)(param_3[7] + 4) <= (int)unaff_s6[2]) goto LAB_005d3dbc;
LAB_005d4144:
          iVar3 = (*pcVar15)(unaff_s6);
          if (iVar3 == 0) goto LAB_005d40cc;
          pcVar12 = param_3[3];
          if (unaff_s2[2] < *(int *)(pcVar12 + 4)) {
            pcVar15 = *(code **)(local_90 + -0x6860);
            goto LAB_005d4170;
          }
        }
        local_68 = 3;
        local_64 = (**(code **)(local_90 + -0x7be0))(pcVar12,*unaff_s3);
        local_60 = *unaff_s3;
        local_5c = (**(code **)(local_90 + -0x7be0))(param_3[4],*unaff_s4);
        local_58 = *unaff_s4;
        local_54 = (**(code **)(local_90 + -0x7be0))(param_3[5],*unaff_s5);
        local_50 = *unaff_s5;
        local_4c = (**(code **)(local_90 + -0x7be0))(param_3[7],*unaff_s6);
        local_48 = *unaff_s6;
        unaff_s3 = (int *)(*p_CSwift_AttachKeyParam)(local_7c,&local_68);
        if (unaff_s3 == (int *)0xffffd8ea) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
          }
          pcVar15 = *(code **)(local_90 + -0x6eb0);
          ppcVar13 = (char **)&DAT_00000065;
          local_98 = (int *)0x368;
          goto LAB_005d40a4;
        }
        if (unaff_s3 == (int *)0x0) {
          local_74 = local_84;
          local_78 = param_2;
          iVar3 = (**(code **)(local_90 + -0x7bec))(param_3[3]);
          local_70 = iVar3 + 7;
          if (iVar3 + 7 < 0) {
            local_70 = iVar3 + 0xe;
          }
          local_70 = local_70 >> 3;
          (**(code **)(local_90 + -0x53e0))(*unaff_s2,0,local_70);
          local_6c = *unaff_s2;
          param_4 = (char *)0x1;
          ppcVar13 = &local_78;
          pcStack_a4 = (char *)0x3;
          local_98 = &local_70;
          local_94 = 1;
          piVar4 = (int *)(*p_CSwift_SimpleRequest)(local_7c);
          if (piVar4 != (int *)0x0) {
            unaff_s2 = (int *)&_ITM_registerTMCloneTable;
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
            }
            local_98 = (int *)0x37f;
            (**(code **)(local_90 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
            pcVar15 = *(code **)(local_90 + -0x54a0);
            local_98 = piVar4;
            goto LAB_005d3fd8;
          }
          puStack_cc = (undefined4 *)(**(code **)(local_90 + -0x6660))();
          if (puStack_cc != (undefined4 *)0x0) {
            uVar5 = (**(code **)(local_90 + -0x74f0))(*unaff_s2,0x14,0);
            ppcVar13 = (char **)0x0;
            pcStack_a4 = (char *)0x14;
            iVar3 = *unaff_s2;
            *puStack_cc = uVar5;
            uVar5 = (**(code **)(local_90 + -0x74f0))(iVar3 + 0x14);
            puStack_cc[1] = uVar5;
          }
        }
        else {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
          }
          local_98 = (int *)0x36d;
          (**(code **)(local_90 + -0x6eb0))(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c");
          pcVar15 = *(code **)(local_90 + -0x54a0);
          local_98 = unaff_s3;
LAB_005d3fd8:
          param_4 = "%ld";
          ppcVar13 = apcStack_3c;
          (*pcVar15)(ppcVar13,1,0xd);
          pcStack_a4 = "CryptoSwift error number is ";
          puStack_cc = (undefined4 *)0x0;
          (**(code **)(local_90 + -0x6c7c))(2);
        }
      }
      (*p_CSwift_ReleaseAccContext)(local_7c);
    }
    else {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (**(code **)(local_90 + -0x589c))();
      }
      ppcVar13 = (char **)&DAT_0000006c;
      param_4 = "e_cswift.c";
      local_98 = (int *)0x33b;
      pcStack_a4 = (char *)0x65;
      puStack_cc = (undefined4 *)0x0;
      (**(code **)(local_90 + -0x6eb0))(CSWIFT_lib_error_code);
    }
    (**(code **)(local_90 + -0x688c))(iVar2);
    (**(code **)(local_90 + -0x74a0))(iVar2);
    unaff_s0 = iVar2;
  }
  if (local_2c == *(int *)puStack_b4) {
    return puStack_cc;
  }
  pcStack_ac = cswift_dsa_verify;
  iVar2 = local_2c;
  (**(code **)(local_90 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_d4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_d0 = unaff_s0;
  piStack_c8 = unaff_s2;
  piStack_c4 = unaff_s3;
  puStack_c0 = unaff_s4;
  puStack_bc = unaff_s5;
  puStack_b8 = unaff_s6;
  pcStack_b0 = param_2;
  iVar3 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  if (iVar3 == 0) {
    puVar7 = (undefined4 *)0xffffffff;
    goto LAB_005d45fc;
  }
  iVar6 = (*p_CSwift_AcquireAccContext)(&uStack_130);
  if (iVar6 == 0) {
    (*(code *)PTR_BN_CTX_start_006a9644)(iVar3);
    puVar7 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    puVar8 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    puVar9 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    puVar10 = (undefined4 *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    piVar4 = (int *)(*(code *)PTR_BN_CTX_get_006a9648)(iVar3);
    if (piVar4 == (int *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar14 = 0x66;
      uVar5 = 0x3b7;
LAB_005d4718:
      puVar7 = (undefined4 *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,uVar14,"e_cswift.c",uVar5);
    }
    else {
      if (((int)puVar7[2] < *(int *)(*(int *)(param_4 + 0xc) + 4)) &&
         (iVar6 = (*(code *)PTR_bn_expand2_006a9680)(puVar7), iVar6 == 0)) {
LAB_005d4744:
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar14 = 0x67;
        uVar5 = 0x3c0;
        goto LAB_005d4718;
      }
      if ((int)puVar8[2] < *(int *)(*(int *)(param_4 + 0x10) + 4)) {
        iVar6 = (*(code *)PTR_bn_expand2_006a9680)(puVar8);
        if (iVar6 != 0) {
          if ((int)puVar9[2] < *(int *)(*(int *)(param_4 + 0x14) + 4)) goto LAB_005d47a8;
          goto LAB_005d43e4;
        }
        goto LAB_005d4744;
      }
      if ((int)puVar9[2] < *(int *)(*(int *)(param_4 + 0x14) + 4)) {
LAB_005d47a8:
        iVar6 = (*(code *)PTR_bn_expand2_006a9680)(puVar9);
        if (iVar6 == 0) goto LAB_005d4744;
        if ((int)puVar10[2] < *(int *)(*(int *)(param_4 + 0x18) + 4)) goto LAB_005d47d0;
LAB_005d43fc:
        iVar6 = piVar4[2];
      }
      else {
LAB_005d43e4:
        if (*(int *)(*(int *)(param_4 + 0x18) + 4) <= (int)puVar10[2]) goto LAB_005d43fc;
LAB_005d47d0:
        iVar6 = (*(code *)PTR_bn_expand2_006a9680)(puVar10);
        if (iVar6 == 0) goto LAB_005d4744;
        iVar6 = piVar4[2];
      }
      if ((iVar6 < 0x28) && (iVar6 = (*(code *)PTR_bn_expand2_006a9680)(piVar4,0x28), iVar6 == 0))
      goto LAB_005d4744;
      uStack_120 = 3;
      uStack_11c = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 *)(param_4 + 0xc),*puVar7);
      uStack_118 = *puVar7;
      uStack_114 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 *)(param_4 + 0x10),*puVar8);
      uStack_110 = *puVar8;
      uStack_10c = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 *)(param_4 + 0x14),*puVar9);
      uStack_108 = *puVar9;
      uStack_104 = (*(code *)PTR_BN_bn2bin_006a8300)(*(undefined4 *)(param_4 + 0x18),*puVar10);
      uStack_100 = *puVar10;
      iVar6 = (*p_CSwift_AttachKeyParam)(uStack_130,&uStack_120);
      if (iVar6 == -0x2716) {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar14 = 0x65;
        uVar5 = 0x3d7;
        goto LAB_005d4718;
      }
      if (iVar6 == 0) {
        iStack_e8 = *piVar4;
        pcStack_f4 = pcStack_a4;
        uStack_ec = 0x28;
        iStack_f0 = iVar2;
        (*(code *)PTR_memset_006aab00)(iStack_e8,0,0x28);
        iVar2 = iStack_e8;
        pcVar12 = *ppcVar13;
        iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(pcVar12);
        iVar6 = iVar11 + 7;
        if (iVar11 + 7 < 0) {
          iVar6 = iVar11 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(pcVar12,(iVar2 - (iVar6 >> 3)) + 0x14);
        iVar2 = iStack_e8;
        pcVar12 = ppcVar13[1];
        iVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(pcVar12);
        iVar6 = iVar11 + 7;
        if (iVar11 + 7 < 0) {
          iVar6 = iVar11 + 0xe;
        }
        (*(code *)PTR_BN_bn2bin_006a8300)(pcVar12,(iVar2 - (iVar6 >> 3)) + 0x28);
        uStack_128 = 4;
        piStack_124 = &iStack_12c;
        iVar6 = (*p_CSwift_SimpleRequest)(uStack_130,4,&pcStack_f4,2,&uStack_128,1);
        if (iVar6 != 0) {
          if (CSWIFT_lib_error_code == 0) {
            CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          uVar5 = 0x3f2;
          goto LAB_005d4698;
        }
        puVar7 = (undefined4 *)(uint)(iStack_12c != 0);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar5 = 0x3dc;
LAB_005d4698:
        (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",uVar5);
        (*(code *)PTR___sprintf_chk_006aaa40)(auStack_e4,1,0xd,&DAT_0066fa28,iVar6);
        puVar7 = (undefined4 *)0xffffffff;
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"CryptoSwift error number is ",auStack_e4);
      }
    }
    (*p_CSwift_ReleaseAccContext)(uStack_130);
  }
  else {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    puVar7 = (undefined4 *)0xffffffff;
    (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,0x66,0x6c,"e_cswift.c",0x3aa);
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(iVar3);
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar3);
LAB_005d45fc:
  if (iStack_d4 == *(int *)puVar1) {
    return puVar7;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar2 != 0) {
    iVar3 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar2,"cswift");
    if ((((((iVar3 != 0) &&
           (iVar3 = (*(code *)PTR_ENGINE_set_name_006a99e8)
                              (iVar2,"CryptoSwift hardware engine support"), iVar3 != 0)) &&
          (iVar3 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar2,cswift_rsa), iVar3 != 0)) &&
         ((iVar3 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar2,cswift_dsa), iVar3 != 0 &&
          (iVar3 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar2,cswift_dh), iVar3 != 0)))) &&
        ((iVar3 = (*(code *)PTR_ENGINE_set_RAND_006aa654)(iVar2,cswift_random), iVar3 != 0 &&
         ((iVar3 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar2,cswift_destroy),
          iVar3 != 0 &&
          (iVar3 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar2,cswift_init), iVar3 != 0))
         )))) && ((iVar3 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar2,cswift_finish),
                  iVar3 != 0 &&
                  ((iVar3 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar2,cswift_ctrl),
                   iVar3 != 0 &&
                   (iVar3 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar2,cswift_cmd_defns),
                   iVar3 != 0)))))) {
      iVar3 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
      cswift_rsa._4_4_ = *(undefined4 *)(iVar3 + 4);
      cswift_rsa._8_4_ = *(undefined4 *)(iVar3 + 8);
      cswift_rsa._12_4_ = *(undefined4 *)(iVar3 + 0xc);
      cswift_rsa._16_4_ = *(undefined4 *)(iVar3 + 0x10);
      iVar3 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
      cswift_dh._4_4_ = *(undefined4 *)(iVar3 + 4);
      cswift_dh._8_4_ = *(undefined4 *)(iVar3 + 8);
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      if (CSWIFT_error_init != 0) {
        CSWIFT_error_init = 0;
        (*(code *)PTR_ERR_load_strings_006a9564)(CSWIFT_lib_error_code,CSWIFT_str_functs);
        (*(code *)PTR_ERR_load_strings_006a9564)(CSWIFT_lib_error_code,CSWIFT_str_reasons);
        CSWIFT_lib_name._0_4_ = CSWIFT_lib_error_code << 0x18;
        (*(code *)PTR_ERR_load_strings_006a9564)(0,CSWIFT_lib_name);
      }
      (*(code *)PTR_ENGINE_add_006a99d8)(iVar2);
      (*(code *)PTR_ENGINE_free_006a7f84)(iVar2);
                    /* WARNING: Could not recover jumptable at 0x005d4b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      puVar7 = (undefined4 *)(*(code *)PTR_ERR_clear_error_006a7fe0)();
      return puVar7;
    }
                    /* WARNING: Could not recover jumptable at 0x005d4954. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    puVar7 = (undefined4 *)(*(code *)PTR_ENGINE_free_006a7f84)(iVar2);
    return puVar7;
  }
  return (undefined4 *)0x0;
}

