
undefined4 surewarehk_ctrl(undefined4 param_1,int param_2,undefined4 param_3,BIO *param_4)

{
  int iVar1;
  
  if (param_2 == 1) {
    CRYPTO_lock(1,9,(char *)0x1e,(int)"e_sureware.c");
    if (logstream != (BIO *)0x0) {
      BIO_free(logstream);
      logstream = (BIO *)0x0;
    }
    iVar1 = CRYPTO_add_lock(&param_4->references,1,0x15,"e_sureware.c",0x19f);
    if (iVar1 < 2) {
      if (SUREWARE_lib_error_code == (BIO *)0x0) {
        SUREWARE_lib_error_code = (BIO *)ERR_get_next_error_library();
      }
      param_4 = SUREWARE_lib_error_code;
      ERR_put_error((int)SUREWARE_lib_error_code,100,100,"e_sureware.c",0x1a3);
    }
    else {
      logstream = param_4;
    }
    CRYPTO_lock((int)param_4,10,(char *)0x1e,(int)"e_sureware.c");
    return 1;
  }
  if (param_2 == 0x65) {
    CRYPTO_lock(0x65,9,(char *)0x1e,(int)"e_sureware.c");
    threadsafe = 0;
    CRYPTO_lock(param_2,10,(char *)0x1e,(int)"e_sureware.c");
    return 1;
  }
  if (SUREWARE_lib_error_code == (BIO *)0x0) {
    SUREWARE_lib_error_code = (BIO *)ERR_get_next_error_library();
  }
  ERR_put_error((int)SUREWARE_lib_error_code,100,0x77,"e_sureware.c",0x1b7);
  return 0;
}

