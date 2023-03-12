
bool aep_ctrl(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 != 200) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,100,0x67,"e_aep.c",0x255);
    return false;
  }
  if (param_4 == 0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar2 = 0x43;
    uVar1 = 0x248;
  }
  else {
    if (aep_dso == 0) {
      if (AEP_LIBNAME != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      AEP_LIBNAME = 0;
      AEP_LIBNAME = (*(code *)PTR_BUF_strdup_006a80dc)(param_4);
      return AEP_LIBNAME != 0;
    }
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar2 = 100;
    uVar1 = 0x24e;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(AEPHK_lib_error_code,100,uVar2,"e_aep.c",uVar1);
  return false;
}

