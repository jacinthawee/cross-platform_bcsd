
/* WARNING: Restarted to delay deadcode elimination for space: ram */

bool hwcrhk_ctrl(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_2 == 0x65) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2e9);
    uVar4 = 0x2eb;
    disable_mutex_callbacks = 1;
    goto LAB_005d350c;
  }
  if (param_2 < 0x66) {
    if (param_2 == 4) {
LAB_005d36b8:
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2ca);
      uVar4 = 0x2cc;
      password_context._4_4_ = param_4;
      goto LAB_005d350c;
    }
    if (param_2 < 5) {
      if (param_2 == 1) {
        (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2b7);
        if (logstream != 0) {
          (*(code *)PTR_BIO_free_006a6e70)();
          logstream = 0;
        }
        iVar2 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(param_4 + 0x2c,1,0x15,"e_chil.c",700);
        iVar1 = param_4;
        if (iVar2 < 2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,100,0x65,"e_chil.c",0x2bf);
          iVar1 = logstream;
        }
        logstream = iVar1;
        uVar4 = 0x2c1;
      }
      else {
        if (param_2 != 2) goto LAB_005d373c;
        (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2c4);
        uVar4 = 0x2c6;
        password_context._0_4_ = param_5;
      }
      goto LAB_005d350c;
    }
    if (param_2 == 5) {
LAB_005d35a8:
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2d0);
      uVar4 = 0x2d2;
      password_context._8_4_ = param_4;
      goto LAB_005d350c;
    }
    if (param_2 != 100) goto LAB_005d373c;
  }
  else {
    if (param_2 == 0xca) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2ee);
      uVar4 = 0x2f0;
      disable_mutex_callbacks = (uint)(param_3 != 0);
      goto LAB_005d350c;
    }
    if (0xca < param_2) {
      if (param_2 != 0xcb) {
        if (param_2 != 0xcc) goto LAB_005d373c;
        goto LAB_005d35a8;
      }
      goto LAB_005d36b8;
    }
    if (param_2 == 200) {
      if (hwcrhk_dso == 0) {
        if (param_4 != 0) {
          if (HWCRHK_LIBNAME != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          HWCRHK_LIBNAME = 0;
          HWCRHK_LIBNAME = (*(code *)PTR_BUF_strdup_006a6fdc)(param_4);
          return HWCRHK_LIBNAME != 0;
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar3 = 0x43;
        uVar4 = 0x2af;
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar3 = 100;
        uVar4 = 0x2ab;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,100,uVar3,"e_chil.c",uVar4);
      return false;
    }
    if (param_2 != 0xc9) {
LAB_005d373c:
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,100,0x67,"e_chil.c",0x2f6);
      return false;
    }
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2da);
  if (param_3 == 0) {
    hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ & 0xffffffef;
  }
  else {
    hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ | 0x10;
  }
  uVar4 = 0x2df;
LAB_005d350c:
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_chil.c",uVar4);
  return true;
}

