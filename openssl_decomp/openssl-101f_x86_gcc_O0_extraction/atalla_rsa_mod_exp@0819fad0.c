
undefined4 atalla_rsa_mod_exp(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (atalla_dso == 0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(ATALLA_lib_error_code,0x68,0x69,"e_atalla.c",0x20a);
  }
  else {
    if ((*(int *)(param_3 + 0x18) != 0) && (*(int *)(param_3 + 0x10) != 0)) {
      uVar1 = atalla_mod_exp();
      return uVar1;
    }
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(ATALLA_lib_error_code,0x68,0x68,"e_atalla.c",0x20f);
  }
  return 0;
}

