
bool cswift_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  int reason;
  int line;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x1d5;
      reason = 0x43;
    }
    else {
      if (cswift_dso == 0) {
        if (CSWIFT_LIBNAME != (char *)0x0) {
          CRYPTO_free(CSWIFT_LIBNAME);
        }
        CSWIFT_LIBNAME = (char *)0x0;
        CSWIFT_LIBNAME = BUF_strdup(param_4);
        return CSWIFT_LIBNAME != (char *)0x0;
      }
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x1da;
      reason = 100;
    }
  }
  else if (CSWIFT_lib_error_code == 0) {
    CSWIFT_lib_error_code = ERR_get_next_error_library();
    line = 0x1e1;
    reason = 0x68;
  }
  else {
    line = 0x1e1;
    reason = 0x68;
  }
  ERR_put_error(CSWIFT_lib_error_code,100,reason,"e_cswift.c",line);
  return false;
}

