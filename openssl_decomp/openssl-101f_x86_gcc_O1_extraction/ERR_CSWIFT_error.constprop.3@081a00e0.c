
void __regparm3 ERR_CSWIFT_error_constprop_3(int param_1,int param_2,int param_3)

{
  if (CSWIFT_lib_error_code == 0) {
    CSWIFT_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(CSWIFT_lib_error_code,param_1,param_2,"e_cswift.c",param_3);
  return;
}

