
void ENGINE_load_4758cca(void)

{
  ENGINE *e;
  int iVar1;
  
  e = ENGINE_new();
  if (e == (ENGINE *)0x0) {
    return;
  }
  iVar1 = ENGINE_set_id(e,"4758cca");
  if ((((((iVar1 != 0) &&
         (iVar1 = ENGINE_set_name(e,"IBM 4758 CCA hardware engine support"), iVar1 != 0)) &&
        (iVar1 = ENGINE_set_RSA(e,(RSA_METHOD *)ibm_4758_cca_rsa), iVar1 != 0)) &&
       ((iVar1 = ENGINE_set_RAND(e,(RAND_METHOD *)ibm_4758_cca_rand), iVar1 != 0 &&
        (iVar1 = ENGINE_set_destroy_function(e,(ENGINE_GEN_INT_FUNC_PTR)&ibm_4758_cca_destroy_1),
        iVar1 != 0)))) &&
      ((iVar1 = ENGINE_set_init_function(e,(ENGINE_GEN_INT_FUNC_PTR)&ibm_4758_cca_init_1),
       iVar1 != 0 &&
       ((iVar1 = ENGINE_set_finish_function(e,ibm_4758_cca_finish + 1), iVar1 != 0 &&
        (iVar1 = ENGINE_set_ctrl_function(e,ibm_4758_cca_ctrl + 1), iVar1 != 0)))))) &&
     ((iVar1 = ENGINE_set_load_privkey_function(e,ibm_4758_load_privkey + 1), iVar1 != 0 &&
      ((iVar1 = ENGINE_set_load_pubkey_function(e,ibm_4758_load_pubkey + 1), iVar1 != 0 &&
       (iVar1 = ENGINE_set_cmd_defns(e,(ENGINE_CMD_DEFN *)PTR_cca4758_cmd_defns_000ee1c4),
       iVar1 != 0)))))) {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = ERR_get_next_error_library();
    }
    if (CCA4758_error_init != 0) {
      CCA4758_error_init = 0;
      ERR_load_strings(CCA4758_lib_error_code,(ERR_STRING_DATA *)CCA4758_str_functs);
      ERR_load_strings(CCA4758_lib_error_code,(ERR_STRING_DATA *)CCA4758_str_reasons);
    }
    ENGINE_add(e);
    ENGINE_free(e);
    ERR_clear_error();
    return;
  }
  ENGINE_free(e);
  return;
}

