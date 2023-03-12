
void ENGINE_load_sureware(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_ENGINE_new_006a87cc)();
  if (iVar1 == 0) {
    return;
  }
  iVar2 = (*(code *)PTR_ENGINE_set_id_006a88c4)(iVar1,"sureware");
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ENGINE_set_name_006a88c8)(iVar1,"SureWare hardware engine support");
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_ENGINE_set_RSA_006a9544)(iVar1,surewarehk_rsa);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_ENGINE_set_DSA_006a9558)(iVar1,surewarehk_dsa);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_ENGINE_set_DH_006a955c)(iVar1,surewarehk_dh);
          if (iVar2 != 0) {
            iVar2 = (*(code *)PTR_ENGINE_set_RAND_006a9548)(iVar1,surewarehk_rand);
            if (iVar2 != 0) {
              iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006a954c)(iVar1,surewarehk_destroy);
              if (iVar2 != 0) {
                iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a88cc)(iVar1,surewarehk_init);
                if (iVar2 != 0) {
                  iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a88d0)
                                    (iVar1,surewarehk_finish);
                  if (iVar2 != 0) {
                    iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a88d4)(iVar1,surewarehk_ctrl);
                    if (iVar2 != 0) {
                      iVar2 = (*(code *)PTR_ENGINE_set_load_privkey_function_006a9550)
                                        (iVar1,surewarehk_load_privkey);
                      if (iVar2 != 0) {
                        iVar2 = (*(code *)PTR_ENGINE_set_load_pubkey_function_006a9554)
                                          (iVar1,surewarehk_load_pubkey);
                        if (iVar2 != 0) {
                          iVar2 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a7aec)();
                          if (iVar2 != 0) {
                            surewarehk_rsa._4_4_ = *(undefined4 *)(iVar2 + 4);
                            surewarehk_rsa._8_4_ = *(undefined4 *)(iVar2 + 8);
                          }
                          iVar2 = (*(code *)PTR_DSA_OpenSSL_006a874c)();
                          if (iVar2 != 0) {
                            surewarehk_dsa._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                          }
                          iVar2 = (*(code *)PTR_DH_OpenSSL_006a8788)();
                          if (iVar2 != 0) {
                            surewarehk_dh._4_4_ = *(undefined4 *)(iVar2 + 4);
                            surewarehk_dh._8_4_ = *(undefined4 *)(iVar2 + 8);
                          }
                          if (SUREWARE_lib_error_code == 0) {
                            SUREWARE_lib_error_code =
                                 (*(code *)PTR_ERR_get_next_error_library_006a9538)();
                          }
                          if (SUREWARE_error_init != 0) {
                            SUREWARE_error_init = 0;
                            (*(code *)PTR_ERR_load_strings_006a8444)
                                      (SUREWARE_lib_error_code,SUREWARE_str_functs);
                            (*(code *)PTR_ERR_load_strings_006a8444)
                                      (SUREWARE_lib_error_code,SUREWARE_str_reasons);
                            SUREWARE_lib_name._0_4_ = SUREWARE_lib_error_code << 0x18;
                            (*(code *)PTR_ERR_load_strings_006a8444)(0,SUREWARE_lib_name);
                          }
                          (*(code *)PTR_ENGINE_add_006a88b8)(iVar1);
                          (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005d90d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                          (*(code *)PTR_ERR_clear_error_006a6ee0)();
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
                    /* WARNING: Could not recover jumptable at 0x005d8e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ENGINE_free_006a6e84)(iVar1);
  return;
}

