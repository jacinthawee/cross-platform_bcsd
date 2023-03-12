
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ibm_4758_cca_destroy(void)

{
  if (CCA4758_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006a9530)(CCA4758_lib_error_code,CCA4758_str_functs);
    (*(code *)PTR_ERR_unload_strings_006a9530)(CCA4758_lib_error_code,CCA4758_str_reasons);
    CCA4758_error_init = 1;
  }
  if (CCA4758_LIB_NAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  CCA4758_LIB_NAME = 0;
  return 1;
}

