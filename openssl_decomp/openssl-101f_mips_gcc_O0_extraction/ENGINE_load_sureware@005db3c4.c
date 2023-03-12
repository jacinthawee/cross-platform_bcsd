
void ENGINE_load_sureware(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar1 == 0) {
    return;
  }
  iVar2 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar1,"sureware");
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ENGINE_set_name_006a99e8)(iVar1,"SureWare hardware engine support");
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar1,surewarehk_rsa);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar1,surewarehk_dsa);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar1,surewarehk_dh);
          if (iVar2 != 0) {
            iVar2 = (*(code *)PTR_ENGINE_set_RAND_006aa654)(iVar1,surewarehk_rand);
            if (iVar2 != 0) {
              iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar1,surewarehk_destroy);
              if (iVar2 != 0) {
                iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar1,surewarehk_init);
                if (iVar2 != 0) {
                  iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)
                                    (iVar1,surewarehk_finish);
                  if (iVar2 != 0) {
                    iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar1,surewarehk_ctrl);
                    if (iVar2 != 0) {
                      iVar2 = (*(code *)PTR_ENGINE_set_load_privkey_function_006aa65c)
                                        (iVar1,surewarehk_load_privkey);
                      if (iVar2 != 0) {
                        iVar2 = (*(code *)PTR_ENGINE_set_load_pubkey_function_006aa660)
                                          (iVar1,surewarehk_load_pubkey);
                        if (iVar2 != 0) {
                          iVar2 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
                          if (iVar2 != 0) {
                            surewarehk_rsa._4_4_ = *(undefined4 *)(iVar2 + 4);
                            surewarehk_rsa._8_4_ = *(undefined4 *)(iVar2 + 8);
                          }
                          iVar2 = (*(code *)PTR_DSA_OpenSSL_006a9870)();
                          if (iVar2 != 0) {
                            surewarehk_dsa._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                          }
                          iVar2 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
                          if (iVar2 != 0) {
                            surewarehk_dh._4_4_ = *(undefined4 *)(iVar2 + 4);
                            surewarehk_dh._8_4_ = *(undefined4 *)(iVar2 + 8);
                          }
                          if (SUREWARE_lib_error_code == 0) {
                            SUREWARE_lib_error_code =
                                 (*(code *)PTR_ERR_get_next_error_library_006aa644)();
                          }
                          if (SUREWARE_error_init != 0) {
                            SUREWARE_error_init = 0;
                            (*(code *)PTR_ERR_load_strings_006a9564)
                                      (SUREWARE_lib_error_code,SUREWARE_str_functs);
                            (*(code *)PTR_ERR_load_strings_006a9564)
                                      (SUREWARE_lib_error_code,SUREWARE_str_reasons);
                            SUREWARE_lib_name._0_4_ = SUREWARE_lib_error_code << 0x18;
                            (*(code *)PTR_ERR_load_strings_006a9564)(0,SUREWARE_lib_name);
                          }
                          (*(code *)PTR_ENGINE_add_006a99d8)(iVar1);
                          (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005db6a4. Too many branches */
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
                    /* WARNING: Could not recover jumptable at 0x005db434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
  return;
}
