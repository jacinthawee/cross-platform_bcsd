
char * ubsec_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  
  if (param_2 != 200) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,100,0x66,"e_ubsec.c",0x232);
    return (char *)0x0;
  }
  if (param_4 == (char *)0x0) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,100,0x43,"e_ubsec.c",0x227);
  }
  else {
    if (ubsec_dso == 0) {
      if (UBSEC_LIBNAME != (char *)0x0) {
        CRYPTO_free(UBSEC_LIBNAME);
      }
      UBSEC_LIBNAME = (char *)0x0;
      pcVar1 = BUF_strdup(param_4);
      UBSEC_LIBNAME = pcVar1;
      if (pcVar1 != (char *)0x0) {
        pcVar1 = (char *)0x1;
      }
      return pcVar1;
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,100,100,"e_ubsec.c",0x22b);
  }
  return (char *)0x0;
}

