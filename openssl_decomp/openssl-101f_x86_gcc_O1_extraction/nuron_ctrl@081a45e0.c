
bool nuron_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  int reason;
  int line;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = ERR_get_next_error_library();
      }
      line = 0xb0;
      reason = 0x43;
    }
    else {
      if (pvDSOHandle == 0) {
        if (NURON_LIBNAME != (char *)0x0) {
          CRYPTO_free(NURON_LIBNAME);
        }
        NURON_LIBNAME = (char *)0x0;
        NURON_LIBNAME = BUF_strdup(param_4);
        return NURON_LIBNAME != (char *)0x0;
      }
      if (NURON_lib_error_code == 0) {
        NURON_lib_error_code = ERR_get_next_error_library();
      }
      line = 0xb5;
      reason = 100;
    }
  }
  else if (NURON_lib_error_code == 0) {
    NURON_lib_error_code = ERR_get_next_error_library();
    line = 0xbc;
    reason = 0x65;
  }
  else {
    line = 0xbc;
    reason = 0x65;
  }
  ERR_put_error(NURON_lib_error_code,100,reason,"e_nuron.c",line);
  return false;
}

