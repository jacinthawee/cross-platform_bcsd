
/* WARNING: Restarted to delay deadcode elimination for space: ram */

bool hwcrhk_ctrl(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_2 == 0x65) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2d7);
    uVar4 = 0x2d9;
    disable_mutex_callbacks = 1;
    goto LAB_005d5adc;
  }
  if (param_2 < 0x66) {
    if (param_2 == 4) {
LAB_005d5c88:
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2ba);
      uVar4 = 700;
      password_context._4_4_ = param_4;
      goto LAB_005d5adc;
    }
    if (param_2 < 5) {
      if (param_2 == 1) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2a6);
        if (logstream != 0) {
          (*(code *)PTR_BIO_free_006a7f70)();
          logstream = 0;
        }
        iVar2 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(param_4 + 0x2c,1,0x15,"e_chil.c",0x2ac);
        iVar1 = param_4;
        if (iVar2 < 2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,100,0x65,"e_chil.c",0x2af);
          iVar1 = logstream;
        }
        logstream = iVar1;
        uVar4 = 0x2b1;
      }
      else {
        if (param_2 != 2) goto LAB_005d5d0c;
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2b4);
        uVar4 = 0x2b6;
        password_context._0_4_ = param_5;
      }
      goto LAB_005d5adc;
    }
    if (param_2 == 5) {
LAB_005d5b78:
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2c0);
      uVar4 = 0x2c2;
      password_context._8_4_ = param_4;
      goto LAB_005d5adc;
    }
    if (param_2 != 100) goto LAB_005d5d0c;
  }
  else {
    if (param_2 == 0xca) {
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2dc);
      uVar4 = 0x2de;
      disable_mutex_callbacks = (uint)(param_3 != 0);
      goto LAB_005d5adc;
    }
    if (0xca < param_2) {
      if (param_2 != 0xcb) {
        if (param_2 != 0xcc) goto LAB_005d5d0c;
        goto LAB_005d5b78;
      }
      goto LAB_005d5c88;
    }
    if (param_2 == 200) {
      if (hwcrhk_dso == 0) {
        if (param_4 != 0) {
          if (HWCRHK_LIBNAME != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          HWCRHK_LIBNAME = 0;
          HWCRHK_LIBNAME = (*(code *)PTR_BUF_strdup_006a80dc)(param_4);
          return HWCRHK_LIBNAME != 0;
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar3 = 0x43;
        uVar4 = 0x29e;
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar3 = 100;
        uVar4 = 0x299;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,100,uVar3,"e_chil.c",uVar4);
      return false;
    }
    if (param_2 != 0xc9) {
LAB_005d5d0c:
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,100,0x67,"e_chil.c",0x2e4);
      return false;
    }
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2c8);
  if (param_3 == 0) {
    hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ & 0xffffffef;
  }
  else {
    hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ | 0x10;
  }
  uVar4 = 0x2cf;
LAB_005d5adc:
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"e_chil.c",uVar4);
  return true;
}

