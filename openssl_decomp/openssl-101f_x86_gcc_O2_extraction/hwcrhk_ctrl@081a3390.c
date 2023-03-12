
bool hwcrhk_ctrl(undefined4 param_1,BIO *param_2,int param_3,BIO *param_4,BIO *param_5)

{
  int iVar1;
  int line;
  
  if (param_2 == (BIO *)0x65) {
    CRYPTO_lock(0x65,9,(char *)0x1e,(int)"e_chil.c");
    disable_mutex_callbacks = (BIO *)0x1;
    param_5 = param_2;
    goto LAB_081a33e4;
  }
  if ((int)param_2 < 0x66) {
    if (param_2 == (BIO *)&DAT_00000004) {
LAB_081a3570:
      CRYPTO_lock((int)param_2,9,(char *)0x1e,(int)"e_chil.c");
      password_context._4_4_ = param_4;
      param_5 = param_4;
LAB_081a33e4:
      CRYPTO_lock((int)param_5,10,(char *)0x1e,(int)"e_chil.c");
      return true;
    }
    if ((int)param_2 < 5) {
      if (param_2 == (BIO *)0x1) {
        CRYPTO_lock(1,9,(char *)0x1e,(int)"e_chil.c");
        if (logstream != (BIO *)0x0) {
          BIO_free(logstream);
          logstream = (BIO *)0x0;
        }
        iVar1 = CRYPTO_add_lock(&param_4->references,1,0x15,"e_chil.c",0x2ac);
        if (iVar1 < 2) {
          if (HWCRHK_lib_error_code == (BIO *)0x0) {
            HWCRHK_lib_error_code = (BIO *)ERR_get_next_error_library();
          }
          param_4 = HWCRHK_lib_error_code;
          ERR_put_error((int)HWCRHK_lib_error_code,100,0x65,"e_chil.c",0x2af);
        }
        else {
          logstream = param_4;
        }
        goto LAB_081a3505;
      }
      if (param_2 == (BIO *)0x2) {
        CRYPTO_lock(2,9,(char *)0x1e,(int)"e_chil.c");
        password_context._0_4_ = param_5;
        goto LAB_081a33e4;
      }
    }
    else {
      if (param_2 == (BIO *)0x5) {
LAB_081a346e:
        CRYPTO_lock((int)param_2,9,(char *)0x1e,(int)"e_chil.c");
        password_context._8_4_ = param_4;
        param_5 = param_4;
        goto LAB_081a33e4;
      }
      if (param_2 == (BIO *)0x64) {
LAB_081a3532:
        CRYPTO_lock((int)param_2,9,(char *)0x1e,(int)"e_chil.c");
        if (param_3 == 0) {
          param_4 = (BIO *)((uint)hwcrhk_globals._0_4_ & 0xffffffef);
          hwcrhk_globals._0_4_ = param_4;
        }
        else {
          param_4 = (BIO *)((uint)hwcrhk_globals._0_4_ | 0x10);
          hwcrhk_globals._0_4_ = param_4;
        }
LAB_081a3505:
        CRYPTO_lock((int)param_4,10,(char *)0x1e,(int)"e_chil.c");
        return true;
      }
    }
  }
  else {
    if (param_2 == (BIO *)0xca) {
      CRYPTO_lock(0xca,9,(char *)0x1e,(int)"e_chil.c");
      param_4 = (BIO *)(uint)(param_3 != 0);
      disable_mutex_callbacks = param_4;
      goto LAB_081a3505;
    }
    if ((int)param_2 < 0xcb) {
      if (param_2 == (BIO *)0xc8) {
        if (hwcrhk_dso == 0) {
          if (param_4 != (BIO *)0x0) {
            if (HWCRHK_LIBNAME != (char *)0x0) {
              CRYPTO_free(HWCRHK_LIBNAME);
            }
            HWCRHK_LIBNAME = (char *)0x0;
            HWCRHK_LIBNAME = BUF_strdup((char *)param_4);
            return HWCRHK_LIBNAME != (char *)0x0;
          }
          if (HWCRHK_lib_error_code == (BIO *)0x0) {
            HWCRHK_lib_error_code = (BIO *)ERR_get_next_error_library();
          }
          line = 0x29e;
          iVar1 = 0x43;
        }
        else {
          if (HWCRHK_lib_error_code == (BIO *)0x0) {
            HWCRHK_lib_error_code = (BIO *)ERR_get_next_error_library();
          }
          line = 0x299;
          iVar1 = 100;
        }
        goto LAB_081a3441;
      }
      if (param_2 == (BIO *)0xc9) goto LAB_081a3532;
    }
    else {
      if (param_2 == (BIO *)0xcb) goto LAB_081a3570;
      if (param_2 == (BIO *)0xcc) goto LAB_081a346e;
    }
  }
  if (HWCRHK_lib_error_code == (BIO *)0x0) {
    HWCRHK_lib_error_code = (BIO *)ERR_get_next_error_library();
  }
  line = 0x2e4;
  iVar1 = 0x67;
LAB_081a3441:
  ERR_put_error((int)HWCRHK_lib_error_code,100,iVar1,"e_chil.c",line);
  return false;
}

