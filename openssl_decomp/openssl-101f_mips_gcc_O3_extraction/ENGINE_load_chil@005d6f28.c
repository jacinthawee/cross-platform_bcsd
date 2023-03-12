
void ENGINE_load_chil(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar1 == 0) {
    return;
  }
  iVar2 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar1,&DAT_00673910);
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ENGINE_set_name_006a99e8)(iVar1,"CHIL hardware engine support");
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar1,hwcrhk_rsa);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar1,hwcrhk_dh);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_ENGINE_set_RAND_006aa654)(iVar1,hwcrhk_rand);
          if (iVar2 != 0) {
            iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar1,hwcrhk_destroy);
            if (iVar2 != 0) {
              iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar1,hwcrhk_init);
              if (iVar2 != 0) {
                iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar1,hwcrhk_finish);
                if (iVar2 != 0) {
                  iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar1,hwcrhk_ctrl);
                  if (iVar2 != 0) {
                    iVar2 = (*(code *)PTR_ENGINE_set_load_privkey_function_006aa65c)
                                      (iVar1,hwcrhk_load_privkey);
                    if (iVar2 != 0) {
                      iVar2 = (*(code *)PTR_ENGINE_set_load_pubkey_function_006aa660)
                                        (iVar1,hwcrhk_load_pubkey);
                      if (iVar2 != 0) {
                        iVar2 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar1,hwcrhk_cmd_defns)
                        ;
                        if (iVar2 != 0) {
                          iVar2 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
                          hwcrhk_rsa._4_4_ = *(undefined4 *)(iVar2 + 4);
                          hwcrhk_rsa._8_4_ = *(undefined4 *)(iVar2 + 8);
                          hwcrhk_rsa._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                          hwcrhk_rsa._16_4_ = *(undefined4 *)(iVar2 + 0x10);
                          iVar2 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
                          hwcrhk_dh._4_4_ = *(undefined4 *)(iVar2 + 4);
                          hwcrhk_dh._8_4_ = *(undefined4 *)(iVar2 + 8);
                          if (HWCRHK_lib_error_code == 0) {
                            HWCRHK_lib_error_code =
                                 (*(code *)PTR_ERR_get_next_error_library_006aa644)();
                          }
                          if (HWCRHK_error_init != 0) {
                            HWCRHK_error_init = 0;
                            (*(code *)PTR_ERR_load_strings_006a9564)
                                      (HWCRHK_lib_error_code,HWCRHK_str_functs);
                            (*(code *)PTR_ERR_load_strings_006a9564)
                                      (HWCRHK_lib_error_code,HWCRHK_str_reasons);
                            HWCRHK_lib_name._0_4_ = HWCRHK_lib_error_code << 0x18;
                            (*(code *)PTR_ERR_load_strings_006a9564)(0,HWCRHK_lib_name);
                          }
                          (*(code *)PTR_ENGINE_add_006a99d8)(iVar1);
                          (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005d71d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                          (*(code *)PTR_ERR_clear_error_006a7fe0)();
                          return;
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
  }
                    /* WARNING: Could not recover jumptable at 0x005d6f90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
  return;
}

