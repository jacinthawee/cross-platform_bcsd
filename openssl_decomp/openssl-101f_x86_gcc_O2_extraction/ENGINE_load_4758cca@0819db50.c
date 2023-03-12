
void ENGINE_load_4758cca(void)

{
  ENGINE *e;
  int iVar1;
  ENGINE *e_00;
  
  e = ENGINE_new();
  if (e != (ENGINE *)0x0) {
    iVar1 = ENGINE_set_id(e,"4758cca");
    if (iVar1 != 0) {
      iVar1 = ENGINE_set_name(e,"IBM 4758 CCA hardware engine support");
      if (iVar1 != 0) {
        iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)ibm_4758_cca_rsa);
        if (iVar1 != 0) {
          iVar1 = ENGINE_set_RAND(e,(RAND_METHOD *)ibm_4758_cca_rand);
          if (iVar1 != 0) {
            iVar1 = ENGINE_set_destroy_function(e,ibm_4758_cca_destroy);
            if (iVar1 != 0) {
              iVar1 = ENGINE_set_init_function(e,ibm_4758_cca_init);
              if (iVar1 != 0) {
                iVar1 = ENGINE_set_finish_function(e,ibm_4758_cca_finish);
                if (iVar1 != 0) {
                  iVar1 = ENGINE_set_ctrl_function(e,ibm_4758_cca_ctrl);
                  if (iVar1 != 0) {
                    iVar1 = ENGINE_set_load_privkey_function(e,ibm_4758_load_privkey);
                    if (iVar1 != 0) {
                      iVar1 = ENGINE_set_load_pubkey_function(e,ibm_4758_load_pubkey);
                      if (iVar1 != 0) {
                        e_00 = (ENGINE *)
                               ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)cca4758_cmd_defns);
                        if (e_00 != (ENGINE *)0x0) {
                          if (CCA4758_lib_error_code == (ENGINE *)0x0) {
                            e_00 = (ENGINE *)ERR_get_next_error_library();
                            CCA4758_lib_error_code = e_00;
                          }
                          if (CCA4758_error_init != 0) {
                            CCA4758_error_init = 0;
                            ERR_load_strings((int)CCA4758_lib_error_code,
                                             (ERR_STRING_DATA *)CCA4758_str_functs);
                            ERR_load_strings((int)CCA4758_lib_error_code,
                                             (ERR_STRING_DATA *)CCA4758_str_reasons);
                          }
                          ENGINE_add(e_00);
                          ENGINE_free(e);
                          ERR_clear_error();
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
    ENGINE_free(e);
  }
  return;
}

