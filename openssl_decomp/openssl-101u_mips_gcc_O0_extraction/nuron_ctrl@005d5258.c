
bool nuron_ctrl(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 != 200) {
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(NURON_lib_error_code,100,0x65,"e_nuron.c",0xb9);
    return false;
  }
  if (param_4 == 0) {
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar2 = 0x43;
    uVar1 = 0xae;
  }
  else {
    if (pvDSOHandle == 0) {
      if (NURON_LIBNAME != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      NURON_LIBNAME = 0;
      NURON_LIBNAME = (*(code *)PTR_BUF_strdup_006a6fdc)(param_4);
      return NURON_LIBNAME != 0;
    }
    if (NURON_lib_error_code == 0) {
      NURON_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar2 = 100;
    uVar1 = 0xb2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(NURON_lib_error_code,100,uVar2,"e_nuron.c",uVar1);
  return false;
}

