
char * aep_ctrl(undefined4 param_1,int param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  
  if (param_2 != 200) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,100,0x67,"e_aep.c",0x255);
    return (char *)0x0;
  }
  if (param_4 == (char *)0x0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,100,0x43,"e_aep.c",0x248);
  }
  else {
    if (aep_dso == 0) {
      if (AEP_LIBNAME != (char *)0x0) {
        CRYPTO_free(AEP_LIBNAME);
      }
      AEP_LIBNAME = (char *)0x0;
      pcVar1 = BUF_strdup(param_4);
      AEP_LIBNAME = pcVar1;
      if (pcVar1 != (char *)0x0) {
        pcVar1 = (char *)0x1;
      }
      return pcVar1;
    }
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,100,100,"e_aep.c",0x24e);
  }
  return (char *)0x0;
}

