
bool aep_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  int reason;
  int line;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x248;
      reason = 0x43;
    }
    else {
      if (aep_dso == 0) {
        if (AEP_LIBNAME != (char *)0x0) {
          CRYPTO_free(AEP_LIBNAME);
        }
        AEP_LIBNAME = (char *)0x0;
        AEP_LIBNAME = BUF_strdup(param_4);
        return AEP_LIBNAME != (char *)0x0;
      }
      if (AEPHK_lib_error_code == 0) {
        AEPHK_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x24e;
      reason = 100;
    }
  }
  else if (AEPHK_lib_error_code == 0) {
    AEPHK_lib_error_code = ERR_get_next_error_library();
    line = 0x255;
    reason = 0x67;
  }
  else {
    line = 0x255;
    reason = 0x67;
  }
  ERR_put_error(AEPHK_lib_error_code,100,reason,"e_aep.c",line);
  return false;
}

