
char * cswift_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  
  if (param_2 != 200) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,100,0x68,"e_cswift.c",0x1e1);
    return (char *)0x0;
  }
  if (param_4 == (char *)0x0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,100,0x43,"e_cswift.c",0x1d5);
  }
  else {
    if (cswift_dso == 0) {
      if (CSWIFT_LIBNAME != (char *)0x0) {
        CRYPTO_free(CSWIFT_LIBNAME);
      }
      CSWIFT_LIBNAME = (char *)0x0;
      pcVar1 = BUF_strdup(param_4);
      CSWIFT_LIBNAME = pcVar1;
      if (pcVar1 != (char *)0x0) {
        pcVar1 = (char *)0x1;
      }
      return pcVar1;
    }
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,100,100,"e_cswift.c",0x1da);
  }
  return (char *)0x0;
}

