
void ERR_CSWIFT_error_constprop_3(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (CSWIFT_lib_error_code == 0) {
    CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(CSWIFT_lib_error_code,param_1,param_2,"e_cswift.c",param_3);
  return;
}

