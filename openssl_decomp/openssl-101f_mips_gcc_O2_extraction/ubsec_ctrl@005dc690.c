
bool ubsec_ctrl(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 != 200) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,100,0x66,"e_ubsec.c",0x228);
    return false;
  }
  if (param_4 == 0) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar2 = 0x43;
    uVar1 = 0x21c;
  }
  else {
    if (ubsec_dso == 0) {
      if (UBSEC_LIBNAME != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      UBSEC_LIBNAME = 0;
      UBSEC_LIBNAME = (*(code *)PTR_BUF_strdup_006a80dc)(param_4);
      return UBSEC_LIBNAME != 0;
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar2 = 100;
    uVar1 = 0x221;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,100,uVar2,"e_ubsec.c",uVar1);
  return false;
}

