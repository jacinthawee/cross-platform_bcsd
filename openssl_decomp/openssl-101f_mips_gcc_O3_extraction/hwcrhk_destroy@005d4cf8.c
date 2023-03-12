
undefined4 hwcrhk_destroy(void)

{
  if (HWCRHK_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  HWCRHK_LIBNAME = 0;
  if (HWCRHK_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006aa63c)(HWCRHK_lib_error_code,HWCRHK_str_functs);
    (*(code *)PTR_ERR_unload_strings_006aa63c)(HWCRHK_lib_error_code,HWCRHK_str_reasons);
    (*(code *)PTR_ERR_unload_strings_006aa63c)(0,HWCRHK_lib_name);
    HWCRHK_error_init = 1;
  }
  return 1;
}

