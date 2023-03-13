
uint cca_rsa_sign(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5,
                 undefined4 param_6)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int local_84;
  int local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c;
  int local_68;
  int *local_64;
  int *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 *local_50;
  int local_4c [2];
  undefined4 local_44;
  undefined auStack_3c [8];
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_30 = DAT_00673470;
  local_34 = DAT_0067346c;
  local_7c = 0;
  local_78 = 1;
  local_74 = 0x100;
  puVar2 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006a9534)(param_6,hndidx);
  local_6c = 0x24;
  local_70 = *puVar2;
  if ((param_1 == 4) || (param_1 == 0x40)) {
    local_64 = &local_54;
    local_54 = (*(code *)PTR_OBJ_nid2obj_006a7140)(param_1);
    if (local_54 != 0) {
      uVar7 = *(uint *)(local_54 + 0xc);
      if (uVar7 == 0) {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x69,0x65,"e_4758cca.c",0x2f7);
        goto LAB_005cbdd8;
      }
      local_58 = 0;
      local_5c = 5;
      local_50 = &local_5c;
      local_60 = local_4c;
      local_4c[0] = param_3;
      local_44 = param_2;
      local_6c = (*(code *)PTR_i2d_X509_SIG_006a8734)(&local_64,0);
      iVar3 = (*(code *)PTR_RSA_size_006a7640)(param_6);
      if (iVar3 < local_6c + -1) goto LAB_005cbe9c;
      goto LAB_005cbdb4;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar6 = 0x6d;
    uVar4 = 0x2f1;
  }
  else {
    iVar3 = (*(code *)PTR_RSA_size_006a7640)(param_6);
    if (local_6c + -1 <= iVar3) {
LAB_005cbdb4:
      if (param_1 == 0x40) {
        iVar5 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3 + 1,"e_4758cca.c",0x326);
        if (iVar5 == 0) {
          local_68 = iVar5;
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          uVar7 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)
                    (CCA4758_lib_error_code,0x69,0x41,"e_4758cca.c",0x328);
          goto LAB_005cbdd8;
        }
LAB_005cbf9c:
        local_68 = iVar5;
        (*(code *)PTR_i2d_X509_SIG_006a8734)(&local_64,&local_68);
        (*digitalSignatureGenerate)
                  (&local_84,&local_80,&local_7c,auStack_3c,&local_78,&local_34,&local_70,puVar2 + 1
                   ,&local_6c,iVar5,&local_74,&local_68,param_4);
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar5,iVar3 + 1);
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
LAB_005cbf58:
        *param_5 = local_74;
        if (local_84 == 0) {
          uVar7 = (uint)(local_80 == 0);
          goto LAB_005cbdd8;
        }
      }
      else {
        if (param_1 == 0x72) {
          if (param_3 != 0x24) {
            if (CCA4758_lib_error_code == 0) {
              CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            uVar6 = 0x6b;
            uVar4 = 0x312;
            goto LAB_005cbed8;
          }
          local_6c = param_3;
          (*digitalSignatureGenerate)
                    (&local_84,&local_80,&local_7c,auStack_3c,&local_78,&local_34,&local_70,
                     puVar2 + 1,&local_6c,param_2,&local_74,&local_68,param_4);
          goto LAB_005cbf58;
        }
        if (param_1 == 4) {
          iVar5 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3 + 1,"e_4758cca.c",0x31b);
          if (iVar5 == 0) {
            local_68 = iVar5;
            if (CCA4758_lib_error_code == 0) {
              CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
            }
            uVar7 = 0;
            (*(code *)PTR_ERR_put_error_006a7f34)
                      (CCA4758_lib_error_code,0x69,0x41,"e_4758cca.c",0x31d);
            goto LAB_005cbdd8;
          }
          goto LAB_005cbf9c;
        }
      }
      uVar7 = 0;
      goto LAB_005cbdd8;
    }
LAB_005cbe9c:
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar6 = 0x6b;
    uVar4 = 0x30a;
  }
LAB_005cbed8:
  uVar7 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x69,uVar6,"e_4758cca.c",uVar4);
LAB_005cbdd8:
  if (local_2c == *(int *)puVar1) {
    return uVar7;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = (*(code *)PTR_ENGINE_new_006a87cc)();
  if (iVar3 != 0) {
    iVar5 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar3,"4758cca");
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_ENGINE_set_name_006a88c8)(iVar3,"IBM 4758 CCA hardware engine support");
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_ENGINE_set_RSA_006a9544)(iVar3,ibm_4758_cca_rsa);
        if (iVar5 != 0) {
          iVar5 = (*(code *)PTR_ENGINE_set_RAND_006a9548)(iVar3,ibm_4758_cca_rand);
          if (iVar5 != 0) {
            iVar5 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)(iVar3,ibm_4758_cca_destroy);
            if (iVar5 != 0) {
              iVar5 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)(iVar3,ibm_4758_cca_init);
              if (iVar5 != 0) {
                iVar5 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)
                                  (iVar3,ibm_4758_cca_finish);
                if (iVar5 != 0) {
                  iVar5 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)(iVar3,ibm_4758_cca_ctrl);
                  if (iVar5 != 0) {
                    iVar5 = (*(code *)PTR_ENGINE_set_load_privkey_function_006a9550)
                                      (iVar3,ibm_4758_load_privkey);
                    if (iVar5 != 0) {
                      iVar5 = (*(code *)PTR_ENGINE_set_load_pubkey_function_006a9554)
                                        (iVar3,ibm_4758_load_pubkey);
                      if (iVar5 != 0) {
                        iVar5 = (*(code *)PTR_ENGINE_set_cmd_defns_006a88dc)
                                          (iVar3,cca4758_cmd_defns);
                        if (iVar5 != 0) {
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
                          (*(code *)PTR_ENGINE_add_006a88b8)(iVar3);
                          (*(code *)PTR_ENGINE_free_006a6e84)(iVar3);
                    /* WARNING: Could not recover jumptable at 0x005cc3f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                          uVar7 = (*(code *)PTR_ERR_clear_error_006a6ee0)();
                          return uVar7;
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
    uVar7 = (*(code *)PTR_ENGINE_free_006a6e84)(iVar3);
    return uVar7;
  }
  return 0;
}

