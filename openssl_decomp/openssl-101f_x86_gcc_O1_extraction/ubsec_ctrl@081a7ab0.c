
bool ubsec_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  int reason;
  int line;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x21c;
      reason = 0x43;
    }
    else {
      if (ubsec_dso == 0) {
        if (UBSEC_LIBNAME != (char *)0x0) {
          CRYPTO_free(UBSEC_LIBNAME);
        }
        UBSEC_LIBNAME = (char *)0x0;
        UBSEC_LIBNAME = BUF_strdup(param_4);
        return UBSEC_LIBNAME != (char *)0x0;
      }
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x221;
      reason = 100;
    }
  }
  else if (UBSEC_lib_error_code == 0) {
    UBSEC_lib_error_code = ERR_get_next_error_library();
    line = 0x228;
    reason = 0x66;
  }
  else {
    line = 0x228;
    reason = 0x66;
  }
  ERR_put_error(UBSEC_lib_error_code,100,reason,"e_ubsec.c",line);
  return false;
}

