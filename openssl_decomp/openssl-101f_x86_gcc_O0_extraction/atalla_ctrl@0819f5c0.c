
bool atalla_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  int reason;
  int line;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x1ac;
      reason = 0x43;
    }
    else {
      if (atalla_dso == 0) {
        if (ATALLA_LIBNAME != (char *)0x0) {
          CRYPTO_free(ATALLA_LIBNAME);
        }
        ATALLA_LIBNAME = (char *)0x0;
        ATALLA_LIBNAME = BUF_strdup(param_4);
        return ATALLA_LIBNAME != (char *)0x0;
      }
      if (ATALLA_lib_error_code == 0) {
        ATALLA_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x1b1;
      reason = 100;
    }
  }
  else if (ATALLA_lib_error_code == 0) {
    ATALLA_lib_error_code = ERR_get_next_error_library();
    line = 0x1b8;
    reason = 0x67;
  }
  else {
    line = 0x1b8;
    reason = 0x67;
  }
  ERR_put_error(ATALLA_lib_error_code,100,reason,"e_atalla.c",line);
  return false;
}

