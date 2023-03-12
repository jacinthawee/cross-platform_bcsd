
void ERR_SUREWARE_error_constprop_5(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if (SUREWARE_lib_error_code == 0) {
    SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
  }
  (*(code *)PTR_ERR_put_error_006a7f34)
            (SUREWARE_lib_error_code,param_1,param_2,"e_sureware.c",param_3);
  return;
}

