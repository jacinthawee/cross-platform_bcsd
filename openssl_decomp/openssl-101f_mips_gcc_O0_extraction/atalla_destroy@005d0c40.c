
undefined4 atalla_destroy(void)

{
  if (ATALLA_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  ATALLA_LIBNAME = 0;
  if (ATALLA_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006aa63c)(ATALLA_lib_error_code,ATALLA_str_functs);
    (*(code *)PTR_ERR_unload_strings_006aa63c)(ATALLA_lib_error_code,ATALLA_str_reasons);
    (*(code *)PTR_ERR_unload_strings_006aa63c)(0,ATALLA_lib_name);
    ATALLA_error_init = 1;
  }
  return 1;
}

