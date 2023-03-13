
uint cca_rsa_verify(int *param_1,undefined4 param_2,int *param_3,char *param_4,undefined4 param_5,
                   undefined4 param_6)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  uint uVar10;
  int iStack_13c;
  int iStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 *puStack_124;
  int iStack_120;
  int *piStack_11c;
  undefined4 **ppuStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  int iStack_10c;
  undefined4 *puStack_108;
  undefined4 *apuStack_104 [2];
  int *piStack_fc;
  undefined auStack_f4 [8];
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  int iStack_e4;
  int *piStack_e0;
  undefined *puStack_dc;
  uint uStack_d8;
  int *piStack_d4;
  char *pcStack_d0;
  undefined4 uStack_cc;
  undefined4 *puStack_c8;
  undefined4 uStack_c4;
  undefined4 *local_a8;
  undefined4 *local_a4;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int *local_6c;
  int local_68;
  int *local_64;
  int **local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 *local_50;
  int *local_4c [2];
  undefined4 local_44;
  char acStack_3c [8];
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  puStack_dc = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_7c = param_5;
  puVar7 = (undefined4 *)0x1;
  local_34 = DAT_0067346c;
  local_78 = 0;
  local_74 = 1;
  local_30 = DAT_00673470;
  piVar6 = hndidx;
  pcVar9 = param_4;
  puStack_c8 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006a9534)(param_6);
  local_6c = (int *)&DAT_00000024;
  local_70 = *puStack_c8;
  if ((param_1 == (int *)&SUB_00000004) || (param_1 == (int *)&DAT_00000040)) {
    local_64 = &local_54;
    local_54 = (*(code *)PTR_OBJ_nid2obj_006a7140)(param_1);
    if (local_54 != 0) {
      uStack_d8 = *(uint *)(local_54 + 0xc);
      if (uStack_d8 != 0) {
        piVar6 = (int *)0x0;
        local_58 = 0;
        local_5c = 5;
        local_50 = &local_5c;
        local_60 = local_4c;
        local_4c[0] = param_3;
        local_44 = param_2;
        local_6c = (int *)(*(code *)PTR_i2d_X509_SIG_006a8734)(&local_64);
        iVar2 = (*(code *)PTR_RSA_size_006a7640)(param_6);
        if (iVar2 < (int)((int)local_6c + -1)) goto LAB_005cb9a4;
        goto LAB_005cb8c0;
      }
      param_1 = (int *)&_gp_1;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      puVar7 = (undefined4 *)&DAT_00000065;
      pcVar9 = "e_4758cca.c";
      local_a8 = (undefined4 *)0x286;
      piVar6 = (int *)&DAT_0000006a;
      (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code);
      goto LAB_005cb8e4;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    puVar7 = (undefined4 *)&DAT_0000006d;
    local_a8 = (undefined4 *)0x280;
LAB_005cb9e0:
    pcVar9 = "e_4758cca.c";
    param_1 = (int *)&_gp_1;
    piVar6 = (int *)&DAT_0000006a;
    uStack_d8 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code);
  }
  else {
    iVar2 = (*(code *)PTR_RSA_size_006a7640)(param_6);
    if (iVar2 < (int)((int)local_6c + -1)) {
LAB_005cb9a4:
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      puVar7 = (undefined4 *)&DAT_0000006b;
      local_a8 = (undefined4 *)0x299;
      goto LAB_005cb9e0;
    }
LAB_005cb8c0:
    puStack_c8 = puStack_c8 + 1;
    if (param_1 == (int *)&DAT_00000040) {
      param_3 = (int *)0x670000;
      iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 + 1,"e_4758cca.c",0x2b7);
      if (iVar4 != 0) {
LAB_005cba94:
        param_1 = (int *)(iVar2 + 1);
        param_3 = &local_68;
        local_68 = iVar4;
        (*(code *)PTR_i2d_X509_SIG_006a8734)(&local_64,param_3);
        pcVar9 = acStack_3c;
        puVar7 = &local_78;
        (*digitalSignatureVerify)(&local_80,param_3);
        piVar6 = param_1;
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar4);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar4);
        goto LAB_005cba58;
      }
      param_1 = (int *)&_gp_1;
      local_68 = iVar4;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      pcVar9 = "e_4758cca.c";
      puVar7 = (undefined4 *)&DAT_00000041;
      piVar6 = (int *)&DAT_0000006a;
      local_a8 = (undefined4 *)0x2b9;
      uStack_d8 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code);
    }
    else {
      if (param_1 == (int *)0x72) {
        if (param_3 != (int *)&DAT_00000024) {
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          puVar7 = (undefined4 *)&DAT_0000006b;
          local_a8 = (undefined4 *)0x2a1;
          goto LAB_005cb9e0;
        }
        pcVar9 = acStack_3c;
        puVar7 = &local_78;
        piVar6 = &local_68;
        local_6c = param_3;
        (*digitalSignatureVerify)(&local_80);
LAB_005cba58:
        local_a4 = &local_34;
        local_a8 = &local_74;
        if (local_80 == 0) {
          uStack_d8 = (uint)(local_68 == 0);
          goto LAB_005cb8e4;
        }
      }
      else if (param_1 == (int *)&SUB_00000004) {
        param_3 = (int *)0x670000;
        iVar4 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 + 1,"e_4758cca.c",0x2ab);
        if (iVar4 != 0) goto LAB_005cba94;
        param_1 = (int *)&_gp_1;
        local_68 = iVar4;
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        pcVar9 = "e_4758cca.c";
        puVar7 = (undefined4 *)&DAT_00000041;
        piVar6 = (int *)&DAT_0000006a;
        local_a8 = (undefined4 *)0x2ad;
        uStack_d8 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code);
        goto LAB_005cb8e4;
      }
      uStack_d8 = 0;
    }
  }
LAB_005cb8e4:
  if (local_2c == *(int *)puStack_dc) {
    return uStack_d8;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_c4 = param_6;
  uStack_e8 = DAT_00673470;
  uStack_ec = DAT_0067346c;
  uStack_134 = 0;
  uStack_130 = 1;
  uStack_12c = 0x100;
  piStack_e0 = param_1;
  piStack_d4 = param_3;
  pcStack_d0 = param_4;
  uStack_cc = param_2;
  puVar3 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006a9534)(local_a4,hndidx);
  puStack_124 = (undefined4 *)&DAT_00000024;
  uStack_128 = *puVar3;
  if ((iVar2 == 4) || (iVar2 == 0x40)) {
    piStack_11c = &iStack_10c;
    iStack_10c = (*(code *)PTR_OBJ_nid2obj_006a7140)(iVar2);
    if (iStack_10c != 0) {
      uVar10 = *(uint *)(iStack_10c + 0xc);
      if (uVar10 == 0) {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x69,0x65,"e_4758cca.c",0x2f7);
        goto LAB_005cbdd8;
      }
      uStack_110 = 0;
      uStack_114 = 5;
      puStack_108 = &uStack_114;
      ppuStack_118 = apuStack_104;
      apuStack_104[0] = puVar7;
      piStack_fc = piVar6;
      puStack_124 = (undefined4 *)(*(code *)PTR_i2d_X509_SIG_006a8734)(&piStack_11c,0);
      iVar4 = (*(code *)PTR_RSA_size_006a7640)(local_a4);
      if (iVar4 < (int)((int)puStack_124 + -1)) goto LAB_005cbe9c;
      goto LAB_005cbdb4;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar8 = 0x6d;
    uVar5 = 0x2f1;
  }
  else {
    iVar4 = (*(code *)PTR_RSA_size_006a7640)(local_a4);
    if ((int)((int)puStack_124 + -1) <= iVar4) {
LAB_005cbdb4:
      if (iVar2 == 0x40) {
        iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4 + 1,"e_4758cca.c",0x326);
        if (iVar2 == 0) {
          iStack_120 = iVar2;
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          uVar10 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)
                    (CCA4758_lib_error_code,0x69,0x41,"e_4758cca.c",0x328);
          goto LAB_005cbdd8;
        }
LAB_005cbf9c:
        iStack_120 = iVar2;
        (*(code *)PTR_i2d_X509_SIG_006a8734)(&piStack_11c,&iStack_120);
        (*digitalSignatureGenerate)
                  (&iStack_13c,&iStack_138,&uStack_134,auStack_f4,&uStack_130,&uStack_ec,&uStack_128
                   ,puVar3 + 1,&puStack_124,iVar2,&uStack_12c,&iStack_120,pcVar9);
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar2,iVar4 + 1);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
LAB_005cbf58:
        *local_a8 = uStack_12c;
        if (iStack_13c == 0) {
          uVar10 = (uint)(iStack_138 == 0);
          goto LAB_005cbdd8;
        }
      }
      else {
        if (iVar2 == 0x72) {
          if (puVar7 != (undefined4 *)&DAT_00000024) {
            if (CCA4758_lib_error_code == 0) {
              CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            uVar8 = 0x6b;
            uVar5 = 0x312;
            goto LAB_005cbed8;
          }
          puStack_124 = puVar7;
          (*digitalSignatureGenerate)
                    (&iStack_13c,&iStack_138,&uStack_134,auStack_f4,&uStack_130,&uStack_ec,
                     &uStack_128,puVar3 + 1,&puStack_124,piVar6,&uStack_12c,&iStack_120,pcVar9);
          goto LAB_005cbf58;
        }
        if (iVar2 == 4) {
          iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4 + 1,"e_4758cca.c",0x31b);
          if (iVar2 == 0) {
            iStack_120 = iVar2;
            if (CCA4758_lib_error_code == 0) {
              CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            uVar10 = 0;
            (*(code *)PTR_ERR_put_error_006a7f34)
                      (CCA4758_lib_error_code,0x69,0x41,"e_4758cca.c",0x31d);
            goto LAB_005cbdd8;
          }
          goto LAB_005cbf9c;
        }
      }
      uVar10 = 0;
      goto LAB_005cbdd8;
    }
LAB_005cbe9c:
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar8 = 0x6b;
    uVar5 = 0x30a;
  }
LAB_005cbed8:
  uVar10 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x69,uVar8,"e_4758cca.c",uVar5);
LAB_005cbdd8:
  if (iStack_e4 == *(int *)puVar1) {
    return uVar10;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = (*(code *)PTR_ENGINE_new_006a87cc)();
  if (iVar2 != 0) {
    iVar4 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar2,"4758cca");
    if (iVar4 != 0) {
      iVar4 = (*(code *)PTR_ENGINE_set_name_006a88c8)(iVar2,"IBM 4758 CCA hardware engine support");
      if (iVar4 != 0) {
        iVar4 = (*(code *)PTR_ENGINE_set_RSA_006a9544)(iVar2,ibm_4758_cca_rsa);
        if (iVar4 != 0) {
          iVar4 = (*(code *)PTR_ENGINE_set_RAND_006a9548)(iVar2,ibm_4758_cca_rand);
          if (iVar4 != 0) {
            iVar4 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)(iVar2,ibm_4758_cca_destroy);
            if (iVar4 != 0) {
              iVar4 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)(iVar2,ibm_4758_cca_init);
              if (iVar4 != 0) {
                iVar4 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)
                                  (iVar2,ibm_4758_cca_finish);
                if (iVar4 != 0) {
                  iVar4 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)(iVar2,ibm_4758_cca_ctrl);
                  if (iVar4 != 0) {
                    iVar4 = (*(code *)PTR_ENGINE_set_load_privkey_function_006a9550)
                                      (iVar2,ibm_4758_load_privkey);
                    if (iVar4 != 0) {
                      iVar4 = (*(code *)PTR_ENGINE_set_load_pubkey_function_006a9554)
                                        (iVar2,ibm_4758_load_pubkey);
                      if (iVar4 != 0) {
                        iVar4 = (*(code *)PTR_ENGINE_set_cmd_defns_006a88dc)
                                          (iVar2,cca4758_cmd_defns);
                        if (iVar4 != 0) {
                          if (CCA4758_lib_error_code == 0) {
                            CCA4758_lib_error_code =
                                 (*(code *)PTR_ERR_get_next_error_library_006a9538)();
                          }
                          if (CCA4758_error_init != 0) {
                            CCA4758_error_init = 0;
                            (*(code *)PTR_ERR_load_strings_006a8444)
                                      (CCA4758_lib_error_code,CCA4758_str_functs);
                            (*(code *)PTR_ERR_load_strings_006a8444)
                                      (CCA4758_lib_error_code,CCA4758_str_reasons);
                          }
                          (*(code *)PTR_ENGINE_add_006a88b8)(iVar2);
                          (*(code *)PTR_ENGINE_free_006a6e84)(iVar2);
                    /* WARNING: Could not recover jumptable at 0x005cc3f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                          uVar10 = (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          return uVar10;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
                    /* WARNING: Could not recover jumptable at 0x005cc23c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar10 = (*(code *)PTR_ENGINE_free_006a6e84)(iVar2);
    return uVar10;
  }
  return 0;
}

