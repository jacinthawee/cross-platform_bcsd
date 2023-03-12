
undefined4 atalla_destroy(void)

{
  if (ATALLA_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  ATALLA_LIBNAME = 0;
  if (ATALLA_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006a9530)(ATALLA_lib_error_code,ATALLA_str_functs);
    (*(code *)PTR_ERR_unload_strings_006a9530)(ATALLA_lib_error_code,ATALLA_str_reasons);
    (*(code *)PTR_ERR_unload_strings_006a9530)(0,ATALLA_lib_name);
    ATALLA_error_init = 1;
  }
  return 1;
}

