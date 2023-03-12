
bool ibm_4758_cca_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  int reason;
  int line;
  
  if (param_2 == 200) {
    if (param_4 == (char *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x178;
      reason = 0x43;
    }
    else {
      if (dso == 0) {
        if (CCA4758_LIB_NAME != (char *)0x0) {
          CRYPTO_free(CCA4758_LIB_NAME);
        }
        CCA4758_LIB_NAME = (char *)0x0;
        CCA4758_LIB_NAME = BUF_strdup(param_4);
        return CCA4758_LIB_NAME != (char *)0x0;
      }
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = ERR_get_next_error_library();
      }
      line = 0x17e;
      reason = 100;
    }
  }
  else if (CCA4758_lib_error_code == 0) {
    CCA4758_lib_error_code = ERR_get_next_error_library();
    line = 0x186;
    reason = 0x66;
  }
  else {
    line = 0x186;
    reason = 0x66;
  }
  ERR_put_error(CCA4758_lib_error_code,100,reason,"e_4758cca.c",line);
  return false;
}

