
bool atalla_ctrl(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 != 200) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(ATALLA_lib_error_code,100,0x67,"e_atalla.c",0x1c6);
    return false;
  }
  if (param_4 == 0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar2 = 0x43;
    uVar1 = 0x1bb;
  }
  else {
    if (atalla_dso == 0) {
      if (ATALLA_LIBNAME != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      ATALLA_LIBNAME = 0;
      ATALLA_LIBNAME = (*(code *)PTR_BUF_strdup_006a6fdc)(param_4);
      return ATALLA_LIBNAME != 0;
    }
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar2 = 100;
    uVar1 = 0x1bf;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(ATALLA_lib_error_code,100,uVar2,"e_atalla.c",uVar1);
  return false;
}

