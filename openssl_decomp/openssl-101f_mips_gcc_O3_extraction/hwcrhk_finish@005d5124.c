
undefined4 hwcrhk_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (HWCRHK_LIBNAME != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  HWCRHK_LIBNAME = 0;
  if (hwcrhk_dso == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar2 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x65,0x6b,"e_chil.c",0x273);
  }
  else {
    (*p_hwcrhk_Finish)(hwcrhk_context);
    iVar1 = (*(code *)PTR_DSO_free_006a9994)(hwcrhk_dso);
    if (iVar1 == 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x65,0x68,"e_chil.c",0x27a);
    }
    else {
      uVar2 = 1;
    }
  }
  if (logstream != 0) {
    (*(code *)PTR_BIO_free_006a7f70)();
  }
  hwcrhk_dso = 0;
  p_hwcrhk_Init = 0;
  p_hwcrhk_Finish = (code *)0x0;
  p_hwcrhk_ModExp = 0;
  p_hwcrhk_RandomBytes = 0;
  p_hwcrhk_RSA = 0;
  p_hwcrhk_RSALoadKey = 0;
  p_hwcrhk_RSAGetPublicKey = 0;
  p_hwcrhk_RSAUnloadKey = 0;
  p_hwcrhk_ModExpCRT = 0;
  return uVar2;
}

