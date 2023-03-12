
void ERR_GOST_error(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (GOST_lib_error_code == 0) {
    GOST_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
  }
  (*(code *)PTR_ERR_put_error_006a9030)(GOST_lib_error_code,param_1,param_2,param_3,param_4);
  return;
}

