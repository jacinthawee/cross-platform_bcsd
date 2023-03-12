
bool cswift_ctrl(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 != 200) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,100,0x68,"e_cswift.c",0x1e1);
    return false;
  }
  if (param_4 == 0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar2 = 0x43;
    uVar1 = 0x1d5;
  }
  else {
    if (cswift_dso == 0) {
      if (CSWIFT_LIBNAME != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      CSWIFT_LIBNAME = 0;
      CSWIFT_LIBNAME = (*(code *)PTR_BUF_strdup_006a80dc)(param_4);
      return CSWIFT_LIBNAME != 0;
    }
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar2 = 100;
    uVar1 = 0x1da;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(CSWIFT_lib_error_code,100,uVar2,"e_cswift.c",uVar1);
  return false;
}

