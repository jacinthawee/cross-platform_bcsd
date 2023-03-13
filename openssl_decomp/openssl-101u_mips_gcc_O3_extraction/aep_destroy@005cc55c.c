
undefined4 aep_destroy(void)

{
  if (AEP_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  AEP_LIBNAME = 0;
  if (AEPHK_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006a9530)(AEPHK_lib_error_code,AEPHK_str_functs);
    (*(code *)PTR_ERR_unload_strings_006a9530)(AEPHK_lib_error_code,AEPHK_str_reasons);
    AEPHK_error_init = 1;
  }
  return 1;
}

