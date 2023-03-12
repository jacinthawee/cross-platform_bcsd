
void ENGINE_load_ubsec(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar1 == 0) {
    return;
  }
  iVar2 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar1,"ubsec");
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ENGINE_set_name_006a99e8)(iVar1,"UBSEC hardware engine support");
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar1,ubsec_rsa);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_ENGINE_set_DSA_006aa664)(iVar1,ubsec_dsa);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_ENGINE_set_DH_006aa668)(iVar1,ubsec_dh);
          if (iVar2 != 0) {
            iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar1,ubsec_destroy);
            if (iVar2 != 0) {
              iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar1,ubsec_init);
              if (iVar2 != 0) {
                iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar1,ubsec_finish);
                if (iVar2 != 0) {
                  iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar1,ubsec_ctrl);
                  if (iVar2 != 0) {
                    iVar2 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar1,ubsec_cmd_defns);
                    if (iVar2 != 0) {
                      iVar2 = (*(code *)PTR_RSA_PKCS1_SSLeay_006a8bd8)();
                      ubsec_rsa._4_4_ = *(undefined4 *)(iVar2 + 4);
                      ubsec_rsa._8_4_ = *(undefined4 *)(iVar2 + 8);
                      ubsec_rsa._12_4_ = *(undefined4 *)(iVar2 + 0xc);
                      ubsec_rsa._16_4_ = *(undefined4 *)(iVar2 + 0x10);
                      iVar2 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
                      ubsec_dh._4_4_ = *(undefined4 *)(iVar2 + 4);
                      ubsec_dh._8_4_ = *(undefined4 *)(iVar2 + 8);
                      if (UBSEC_lib_error_code == 0) {
                        UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
                      }
                      if (UBSEC_error_init != 0) {
                        UBSEC_error_init = 0;
                        (*(code *)PTR_ERR_load_strings_006a9564)
                                  (UBSEC_lib_error_code,UBSEC_str_functs);
                        (*(code *)PTR_ERR_load_strings_006a9564)
                                  (UBSEC_lib_error_code,UBSEC_str_reasons);
                        UBSEC_lib_name._0_4_ = UBSEC_lib_error_code << 0x18;
                        (*(code *)PTR_ERR_load_strings_006a9564)(0,UBSEC_lib_name);
                      }
                      (*(code *)PTR_ENGINE_add_006a99d8)(iVar1);
                      (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005ddc94. Too many branches */
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
                    /* WARNING: Could not recover jumptable at 0x005ddaf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
  return;
}

