
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint aep_rsa_mod_exp(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (aep_dso == 0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar10 = 0x6f;
    uVar2 = 0x309;
  }
  else {
    iVar12 = *(int *)(param_3 + 0x20);
    if (((iVar12 != 0) && (iVar13 = *(int *)(param_3 + 0x24), iVar13 != 0)) &&
       (iVar14 = *(int *)(param_3 + 0x28), iVar14 != 0)) {
      iVar15 = *(int *)(param_3 + 0x2c);
      if (iVar15 != 0) {
        uVar2 = *(undefined4 *)(param_3 + 0x1c);
        iVar3 = aep_get_connection(&local_30);
        if (iVar3 == 0) {
          iVar12 = (*p_AEP_ModExpCrt)(local_30,param_2,uVar2,iVar12,iVar13,iVar14,iVar15,param_1,0);
          if (iVar12 == 0) {
            (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_aep.c",0x3dc);
            piVar5 = (int *)(aep_app_conn_table + 4);
            iVar12 = 0;
            do {
              iVar13 = iVar12 + 1;
              if (local_30 == *piVar5) {
                *(undefined4 *)(aep_app_conn_table + iVar12 * 8) = 1;
                break;
              }
              piVar5 = piVar5 + 2;
              iVar12 = iVar13;
            } while (iVar13 != 0x100);
            (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_aep.c",1000);
            uVar4 = 1;
            goto LAB_005ce050;
          }
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x69,0x6d,"e_aep.c",0x2a5);
          (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_aep.c",0x3f2);
          piVar5 = (int *)(aep_app_conn_table + 4);
          iVar12 = 0;
          do {
            iVar13 = iVar12 + 1;
            if (local_30 == *piVar5) {
              iVar13 = (*p_AEP_CloseConnection)(local_30);
              if (iVar13 == 0) {
                *(undefined4 *)(aep_app_conn_table + iVar12 * 8) = 0;
                *(undefined4 *)(aep_app_conn_table + iVar12 * 8 + 4) = 0;
              }
              break;
            }
            piVar5 = piVar5 + 2;
            iVar12 = iVar13;
          } while (iVar13 != 0x100);
          (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_aep.c",0x403);
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x69,0x69,"e_aep.c",0x29a);
        }
        iVar12 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a7aec)();
        uVar4 = (**(code **)(iVar12 + 0x14))(param_1,param_2,param_3,param_4);
        goto LAB_005ce050;
      }
    }
    iVar12 = *(int *)(param_3 + 0x18);
    if (iVar12 != 0) {
      iVar13 = *(int *)(param_3 + 0x10);
      if (iVar13 != 0) {
        iVar14 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar13);
        if (iVar14 < 0x881) {
          iVar12 = aep_mod_exp_part_0(param_1,param_2,iVar12,iVar13,param_4);
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x68,0x74,"e_aep.c",0x265);
          iVar12 = (*(code *)PTR_BN_mod_exp_006a795c)(param_1,param_2,iVar12,iVar13,param_4);
        }
        uVar4 = (uint)(iVar12 == 0);
        goto LAB_005ce050;
      }
    }
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar10 = 0x6c;
    uVar2 = 0x31c;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(AEPHK_lib_error_code,0x6b,uVar10,"e_aep.c",uVar2);
  uVar4 = 0;
LAB_005ce050:
  if (local_2c == *(int *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar12 = (*(code *)PTR_ENGINE_new_006a87cc)();
  if (iVar12 != 0) {
    iVar13 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar12,&DAT_00673488);
    if (iVar13 != 0) {
      iVar13 = (*(code *)PTR_ENGINE_set_name_006a88c8)(iVar12,"Aep hardware engine support");
      if (iVar13 != 0) {
        iVar13 = (*(code *)PTR_ENGINE_set_RSA_006a9544)(iVar12,aep_rsa);
        if (iVar13 != 0) {
          iVar13 = (*(code *)PTR_ENGINE_set_DSA_006a9558)(iVar12,aep_dsa);
          if (iVar13 != 0) {
            iVar13 = (*(code *)PTR_ENGINE_set_DH_006a955c)(iVar12,aep_dh);
            if (iVar13 != 0) {
              iVar13 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)(iVar12,aep_init);
              if (iVar13 != 0) {
                iVar13 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)(iVar12,aep_destroy);
                if (iVar13 != 0) {
                  iVar13 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)(iVar12,aep_finish);
                  if (iVar13 != 0) {
                    iVar13 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)(iVar12,aep_ctrl);
                    if (iVar13 != 0) {
                      iVar13 = (*(code *)PTR_ENGINE_set_cmd_defns_006a88dc)(iVar12,aep_cmd_defns);
                      if (iVar13 != 0) {
                        iVar13 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a7aec)();
                        aep_rsa._4_4_ = *(undefined4 *)(iVar13 + 4);
                        aep_rsa._8_4_ = *(undefined4 *)(iVar13 + 8);
                        aep_rsa._12_4_ = *(undefined4 *)(iVar13 + 0xc);
                        aep_rsa._16_4_ = *(undefined4 *)(iVar13 + 0x10);
                        iVar13 = (*(code *)PTR_DSA_OpenSSL_006a874c)();
                        aep_dsa._4_4_ = *(undefined4 *)(iVar13 + 4);
                        aep_dsa._8_4_ = *(undefined4 *)(iVar13 + 8);
                        aep_dsa._12_4_ = *(undefined4 *)(iVar13 + 0xc);
                        puVar6 = (undefined4 *)(*(code *)PTR_DSA_get_default_method_006a9560)();
                        puVar7 = puVar6;
                        puVar9 = (undefined4 *)aep_dsa;
                        do {
                          puVar8 = puVar7 + 4;
                          uVar11 = puVar7[1];
                          uVar10 = puVar7[2];
                          uVar2 = puVar7[3];
                          *puVar9 = *puVar7;
                          puVar9[1] = uVar11;
                          puVar9[2] = uVar10;
                          puVar9[3] = uVar2;
                          puVar7 = puVar8;
                          puVar9 = puVar9 + 4;
                        } while (puVar8 != puVar6 + 0xc);
                        aep_dsa._16_4_ = aep_dsa_mod_exp;
                        aep_dsa._20_4_ = aep_mod_exp_dsa;
                        iVar13 = (*(code *)PTR_DH_OpenSSL_006a8788)();
                        aep_dh._4_4_ = *(undefined4 *)(iVar13 + 4);
                        aep_dh._8_4_ = *(undefined4 *)(iVar13 + 8);
                        aep_dh._12_4_ = *(undefined4 *)(iVar13 + 0xc);
                        if (AEPHK_lib_error_code == 0) {
                          AEPHK_lib_error_code =
                               (*(code *)PTR_ERR_get_next_error_library_006a9538)();
                        }
                        if (AEPHK_error_init != 0) {
                          AEPHK_error_init = 0;
                          (*(code *)PTR_ERR_load_strings_006a8444)
                                    (AEPHK_lib_error_code,AEPHK_str_functs);
                          (*(code *)PTR_ERR_load_strings_006a8444)
                                    (AEPHK_lib_error_code,AEPHK_str_reasons);
                        }
                        (*(code *)PTR_ENGINE_add_006a88b8)(iVar12);
                        (*(code *)PTR_ENGINE_free_006a6e84)(iVar12);
                    /* WARNING: Could not recover jumptable at 0x005ce610. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                        uVar4 = (*(code *)PTR_ERR_clear_error_006a6ee0)();
                        return uVar4;
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
                    /* WARNING: Could not recover jumptable at 0x005ce3cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar4 = (*(code *)PTR_ENGINE_free_006a6e84)(iVar12);
    return uVar4;
  }
  return 0;
}

