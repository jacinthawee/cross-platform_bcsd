
undefined4 ubsec_destroy(void)

{
  if (UBSEC_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  UBSEC_LIBNAME = 0;
  if (UBSEC_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006a9530)(UBSEC_lib_error_code,UBSEC_str_functs);
    (*(code *)PTR_ERR_unload_strings_006a9530)(UBSEC_lib_error_code,UBSEC_str_reasons);
    (*(code *)PTR_ERR_unload_strings_006a9530)(0,UBSEC_lib_name);
    UBSEC_error_init = 1;
  }
  return 1;
}

