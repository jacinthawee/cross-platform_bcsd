
char * hwcrhk_ctrl(undefined4 param_1,int param_2,int param_3,BIO *param_4,undefined4 param_5)

{
  BIO *pBVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 == 0x65) {
    CRYPTO_lock(9,0x1e,"e_chil.c",0x2d7);
    disable_mutex_callbacks = 1;
    CRYPTO_lock(10,0x1e,"e_chil.c",0x2d9);
    return (char *)0x1;
  }
  if (param_2 < 0x66) {
    if (param_2 == 4) {
LAB_000f4462:
      CRYPTO_lock(9,0x1e,"e_chil.c",0x2ba);
      password_context._4_4_ = param_4;
      CRYPTO_lock(10,0x1e,"e_chil.c",700);
      return (char *)0x1;
    }
    if (param_2 < 5) {
      if (param_2 == 1) {
        CRYPTO_lock(9,0x1e,"e_chil.c",0x2a6);
        if (logstream != (BIO *)0x0) {
          BIO_free(logstream);
          logstream = (BIO *)0x0;
        }
        iVar2 = CRYPTO_add_lock(&param_4->references,1,0x15,"e_chil.c",0x2ac);
        pBVar1 = param_4;
        if (iVar2 < 2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(HWCRHK_lib_error_code,100,0x65,"e_chil.c",0x2af);
          pBVar1 = logstream;
        }
        logstream = pBVar1;
        CRYPTO_lock(10,0x1e,"e_chil.c",0x2b1);
        return (char *)0x1;
      }
      if (param_2 == 2) {
        CRYPTO_lock(9,0x1e,"e_chil.c",0x2b4);
        password_context._0_4_ = param_5;
        CRYPTO_lock(10,0x1e,"e_chil.c",0x2b6);
        return (char *)0x1;
      }
    }
    else {
      if (param_2 == 5) {
LAB_000f4374:
        CRYPTO_lock(9,0x1e,"e_chil.c",0x2c0);
        password_context._8_4_ = param_4;
        CRYPTO_lock(10,0x1e,"e_chil.c",0x2c2);
        return (char *)0x1;
      }
      if (param_2 == 100) goto LAB_000f441a;
    }
  }
  else {
    if (param_2 == 0xca) {
      CRYPTO_lock(9,0x1e,"e_chil.c",0x2dc);
      if (param_3 != 0) {
        param_3 = 1;
      }
      disable_mutex_callbacks = param_3;
      CRYPTO_lock(10,0x1e,"e_chil.c",0x2de);
      return (char *)0x1;
    }
    if (param_2 < 0xcb) {
      if (param_2 == 200) {
        if (hwcrhk_dso == 0) {
          if (param_4 == (BIO *)0x0) {
            if (HWCRHK_lib_error_code == 0) {
              HWCRHK_lib_error_code = ERR_get_next_error_library();
            }
            ERR_put_error(HWCRHK_lib_error_code,100,0x43,"e_chil.c",0x29e);
            pcVar3 = (char *)0x0;
          }
          else {
            if (HWCRHK_LIBNAME != (char *)0x0) {
              CRYPTO_free(HWCRHK_LIBNAME);
            }
            HWCRHK_LIBNAME = (char *)0x0;
            HWCRHK_LIBNAME = BUF_strdup((char *)param_4);
            pcVar3 = HWCRHK_LIBNAME;
            if (HWCRHK_LIBNAME != (char *)0x0) {
              pcVar3 = (char *)0x1;
            }
          }
        }
        else {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(HWCRHK_lib_error_code,100,100,"e_chil.c",0x299);
          pcVar3 = (char *)0x0;
        }
        return pcVar3;
      }
      if (param_2 == 0xc9) {
LAB_000f441a:
        CRYPTO_lock(9,0x1e,"e_chil.c",0x2c8);
        if (param_3 == 0) {
          hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ & 0xffffffef;
        }
        else {
          hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ | 0x10;
        }
        CRYPTO_lock(10,0x1e,"e_chil.c",0x2cf);
        return (char *)0x1;
      }
    }
    else {
      if (param_2 == 0xcb) goto LAB_000f4462;
      if (param_2 == 0xcc) goto LAB_000f4374;
    }
  }
  if (HWCRHK_lib_error_code == 0) {
    HWCRHK_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(HWCRHK_lib_error_code,100,0x67,"e_chil.c",0x2e4);
  return (char *)0x0;
}

