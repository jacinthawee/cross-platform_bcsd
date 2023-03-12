
undefined4 nuron_destroy(void)

{
  if (NURON_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  NURON_LIBNAME = 0;
  if (NURON_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006aa63c)(NURON_lib_error_code,NURON_str_functs);
    (*(code *)PTR_ERR_unload_strings_006aa63c)(NURON_lib_error_code,NURON_str_reasons);
    (*(code *)PTR_ERR_unload_strings_006aa63c)(0,NURON_lib_name);
    NURON_error_init = 1;
  }
  return 1;
}

