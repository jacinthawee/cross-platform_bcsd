
void ERR_load_GOST_strings(void)

{
  if (GOST_lib_error_code == 0) {
    GOST_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
  }
  if (GOST_error_init == 0) {
    return;
  }
  GOST_error_init = 0;
  (*(code *)PTR_ERR_load_strings_006a8444)(GOST_lib_error_code,GOST_str_functs);
                    /* WARNING: Could not recover jumptable at 0x00611a00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ERR_load_strings_006a8444)(GOST_lib_error_code,GOST_str_reasons);
  return;
}

