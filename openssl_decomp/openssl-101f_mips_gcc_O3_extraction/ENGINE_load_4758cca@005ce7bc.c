
void ENGINE_load_4758cca(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_ENGINE_new_006a98ec)();
  if (iVar1 == 0) {
    return;
  }
  iVar2 = (*(code *)PTR_ENGINE_set_id_006a99e4)(iVar1,"4758cca");
  if (iVar2 != 0) {
    iVar2 = (*(code *)PTR_ENGINE_set_name_006a99e8)(iVar1,"IBM 4758 CCA hardware engine support");
    if (iVar2 != 0) {
      iVar2 = (*(code *)PTR_ENGINE_set_RSA_006aa650)(iVar1,ibm_4758_cca_rsa);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_ENGINE_set_RAND_006aa654)(iVar1,ibm_4758_cca_rand);
        if (iVar2 != 0) {
          iVar2 = (*(code *)PTR_ENGINE_set_destroy_function_006aa658)(iVar1,ibm_4758_cca_destroy);
          if (iVar2 != 0) {
            iVar2 = (*(code *)PTR_ENGINE_set_init_function_006a99ec)(iVar1,ibm_4758_cca_init);
            if (iVar2 != 0) {
              iVar2 = (*(code *)PTR_ENGINE_set_finish_function_006a99f0)(iVar1,ibm_4758_cca_finish);
              if (iVar2 != 0) {
                iVar2 = (*(code *)PTR_ENGINE_set_ctrl_function_006a99f4)(iVar1,ibm_4758_cca_ctrl);
                if (iVar2 != 0) {
                  iVar2 = (*(code *)PTR_ENGINE_set_load_privkey_function_006aa65c)
                                    (iVar1,ibm_4758_load_privkey);
                  if (iVar2 != 0) {
                    iVar2 = (*(code *)PTR_ENGINE_set_load_pubkey_function_006aa660)
                                      (iVar1,ibm_4758_load_pubkey);
                    if (iVar2 != 0) {
                      iVar2 = (*(code *)PTR_ENGINE_set_cmd_defns_006a99fc)(iVar1,cca4758_cmd_defns);
                      if (iVar2 != 0) {
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
                        (*(code *)PTR_ENGINE_add_006a99d8)(iVar1);
                        (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
                    /* WARNING: Could not recover jumptable at 0x005ce9d4. Too many branches */
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
                    /* WARNING: Could not recover jumptable at 0x005ce81c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ENGINE_free_006a7f84)(iVar1);
  return;
}

