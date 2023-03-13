
void ERR_unload_GOST_strings(void)

{
  if (GOST_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006a9530)(GOST_lib_error_code,GOST_str_functs);
    (*(code *)PTR_ERR_unload_strings_006a9530)(GOST_lib_error_code,GOST_str_reasons);
    GOST_error_init = 1;
  }
  return;
}

