
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_30 = DAT_00673d80;
  local_34 = DAT_00673d7c;
  local_7c = 0;
  local_78 = 1;
  local_74 = 0x100;
  puVar2 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006aa640)(param_6,hndidx);
  local_6c = 0x24;
  local_70 = *puVar2;
  if ((param_1 == 4) || (param_1 == 0x40)) {
    local_64 = &local_54;
    local_54 = (*(code *)PTR_OBJ_nid2obj_006a8240)(param_1);
    if (local_54 != 0) {
      uVar7 = *(uint *)(local_54 + 0xc);
      if (uVar7 == 0) {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(CCA4758_lib_error_code,0x69,0x65,"e_4758cca.c",0x30f);
        goto LAB_005ce3b8;
      }
      local_58 = 0;
      local_5c = 5;
      local_50 = &local_5c;
      local_60 = local_4c;
      local_4c[0] = param_3;
      local_44 = param_2;
      local_6c = (*(code *)PTR_i2d_X509_SIG_006a9858)(&local_64,0);
      iVar3 = (*(code *)PTR_RSA_size_006a8730)(param_6);
      if (iVar3 < local_6c + -1) goto LAB_005ce47c;
      goto LAB_005ce394;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar6 = 0x6d;
    uVar4 = 0x308;
  }
  else {
    iVar3 = (*(code *)PTR_RSA_size_006a8730)(param_6);
    if (local_6c + -1 <= iVar3) {
LAB_005ce394:
      if (param_1 == 0x40) {
        iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3 + 1,"e_4758cca.c",0x345);
        if (iVar5 == 0) {
          local_68 = iVar5;
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          uVar7 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)
                    (CCA4758_lib_error_code,0x69,0x41,"e_4758cca.c",0x349);
          goto LAB_005ce3b8;
        }
LAB_005ce57c:
        local_68 = iVar5;
        (*(code *)PTR_i2d_X509_SIG_006a9858)(&local_64,&local_68);
        (*digitalSignatureGenerate)
                  (&local_84,&local_80,&local_7c,auStack_3c,&local_78,&local_34,&local_70,puVar2 + 1
                   ,&local_6c,iVar5,&local_74,&local_68,param_4);
        (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar5,iVar3 + 1);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
LAB_005ce538:
        *param_5 = local_74;
        if (local_84 == 0) {
          uVar7 = (uint)(local_80 == 0);
          goto LAB_005ce3b8;
        }
      }
      else {
        if (param_1 == 0x72) {
          if (param_3 != 0x24) {
            if (CCA4758_lib_error_code == 0) {
              CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
            }
            uVar6 = 0x6b;
            uVar4 = 0x32d;
            goto LAB_005ce4b8;
          }
          local_6c = param_3;
          (*digitalSignatureGenerate)
                    (&local_84,&local_80,&local_7c,auStack_3c,&local_78,&local_34,&local_70,
                     puVar2 + 1,&local_6c,param_2,&local_74,&local_68,param_4);
          goto LAB_005ce538;
        }
        if (param_1 == 4) {
          iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3 + 1,"e_4758cca.c",0x337);
          if (iVar5 == 0) {
            local_68 = iVar5;
            if (CCA4758_lib_error_code == 0) {
              CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
            }
            uVar7 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)
                      (CCA4758_lib_error_code,0x69,0x41,"e_4758cca.c",0x33b);
            goto LAB_005ce3b8;
          }
          goto LAB_005ce57c;
        }
      }
      uVar7 = 0;
      goto LAB_005ce3b8;
    }
LAB_005ce47c:
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar6 = 0x6b;
    uVar4 = 0x323;
  }
LAB_005ce4b8:
  uVar7 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(CCA4758_lib_error_code,0x69,uVar6,"e_4758cca.c",uVar4);
LAB_005ce3b8:
  if (local_2c == *(int *)puVar1) {
    return uVar7;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar3 != 0) {
    iVar5 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar3,"4758cca");
    if (iVar5 != 0) {
      iVar5 = (*(code *)PTR_ENGINE_set_name_006a99e8)(iVar3,"IBM 4758 CCA hardware engine support");
      if (iVar5 != 0) {
        iVar5 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar3,ibm_4758_cca_rsa);
        if (iVar5 != 0) {
          iVar5 = (*(code *)PTR_ENGINE_set_RAND_006aa654)(iVar3,ibm_4758_cca_rand);
          if (iVar5 != 0) {
            iVar5 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar3,ibm_4758_cca_destroy);
            if (iVar5 != 0) {
              iVar5 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar3,ibm_4758_cca_init);
              if (iVar5 != 0) {
                iVar5 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)
                                  (iVar3,ibm_4758_cca_finish);
                if (iVar5 != 0) {
                  iVar5 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar3,ibm_4758_cca_ctrl);
                  if (iVar5 != 0) {
                    iVar5 = (*(code *)PTR_ENGINE_set_load_privkey_function_006aa65c)
                                      (iVar3,ibm_4758_load_privkey);
                    if (iVar5 != 0) {
                      iVar5 = (*(code *)PTR_ENGINE_set_load_pubkey_function_006aa660)
                                        (iVar3,ibm_4758_load_pubkey);
                      if (iVar5 != 0) {
                        iVar5 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)
                                          (iVar3,cca4758_cmd_defns);
                        if (iVar5 != 0) {
                          if (CCA4758_lib_error_code == 0) {
                            CCA4758_lib_error_code =
                                 (*(code *)PTR_ERR_get_next_error_library_006aa644)();
                          }
                          if (CCA4758_error_init != 0) {
                            CCA4758_error_init = 0;
                            (*(code *)PTR_ERR_load_strings_006a9564)
                                      (CCA4758_lib_error_code,CCA4758_str_functs);
                            (*(code *)PTR_ERR_load_strings_006a9564)
                                      (CCA4758_lib_error_code,CCA4758_str_reasons);
                          }
                          (*(code *)PTR_ENGINE_add_006a99d8)(iVar3);
                          (*(code *)PTR_ENGINE_free_006a7f84)(iVar3);
                    /* WARNING: Could not recover jumptable at 0x005ce9d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                          uVar7 = (*(code *)PTR_ERR_clear_error_006a7fe0)();
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
                    /* WARNING: Could not recover jumptable at 0x005ce81c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar7 = (*(code *)PTR_ENGINE_free_006a7f84)(iVar3);
    return uVar7;
  }
  return 0;
}

