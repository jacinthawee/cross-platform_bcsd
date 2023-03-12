
undefined4 cswift_destroy(void)

{
  if (CSWIFT_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  CSWIFT_LIBNAME = 0;
  if (CSWIFT_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006a9530)(CSWIFT_lib_error_code,CSWIFT_str_functs);
    (*(code *)PTR_ERR_unload_strings_006a9530)(CSWIFT_lib_error_code,CSWIFT_str_reasons);
    (*(code *)PTR_ERR_unload_strings_006a9530)(0,CSWIFT_lib_name);
    CSWIFT_error_init = 1;
  }
  return 1;
}

