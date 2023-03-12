
undefined4 surewarehk_destroy(void)

{
  if (SUREWARE_error_init == 0) {
    (*(code *)PTR_ERR_unload_strings_006a9530)(SUREWARE_lib_error_code,SUREWARE_str_functs);
    (*(code *)PTR_ERR_unload_strings_006a9530)(SUREWARE_lib_error_code,SUREWARE_str_reasons);
    (*(code *)PTR_ERR_unload_strings_006a9530)(0,SUREWARE_lib_name);
    SUREWARE_error_init = 1;
  }
  return 1;
}

