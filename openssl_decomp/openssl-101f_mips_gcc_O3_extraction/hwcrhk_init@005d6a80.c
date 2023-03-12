
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 hwcrhk_init(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  undefined4 uVar12;
  
  if (hwcrhk_dso == 0) {
    pcVar11 = HWCRHK_LIBNAME;
    if (HWCRHK_LIBNAME == (char *)0x0) {
      pcVar11 = "nfhwcrhk";
    }
    hwcrhk_dso = (*(code *)PTR_DSO_load_006a99a4)(0,pcVar11,0,0);
    if (hwcrhk_dso == 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar12 = 0x68;
      uVar1 = 0x215;
    }
    else {
      iVar2 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_Init");
      if (((((iVar2 != 0) &&
            (iVar3 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_Finish"),
            iVar3 != 0)) &&
           (iVar4 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_ModExp"),
           iVar4 != 0)) &&
          (((iVar5 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_RSA"),
            iVar5 != 0 &&
            (iVar6 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_RSALoadKey"),
            iVar6 != 0)) &&
           ((iVar7 = (*(code *)PTR_DSO_bind_func_006a99ac)
                               (hwcrhk_dso,"HWCryptoHook_RSAGetPublicKey"), iVar7 != 0 &&
            ((iVar8 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_RSAUnloadKey"),
             iVar8 != 0 &&
             (iVar9 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_RandomBytes"),
             iVar9 != 0)))))))) &&
         (iVar10 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_ModExpCRT"),
         iVar10 != 0)) {
        p_hwcrhk_ModExpCRT = iVar10;
        p_hwcrhk_RSAUnloadKey = iVar8;
        p_hwcrhk_RSAGetPublicKey = iVar7;
        p_hwcrhk_RSALoadKey = iVar6;
        p_hwcrhk_RandomBytes = iVar9;
        p_hwcrhk_RSA = iVar5;
        p_hwcrhk_ModExp = iVar4;
        p_hwcrhk_Finish = iVar3;
        p_hwcrhk_Init = iVar2;
        if ((((disable_mutex_callbacks == 0) &&
             (iVar2 = (*(code *)PTR_CRYPTO_get_dynlock_create_callback_006a99c8)(), iVar2 != 0)) &&
            (iVar2 = (*(code *)PTR_CRYPTO_get_dynlock_lock_callback_006a99cc)(), iVar2 != 0)) &&
           (iVar2 = (*(code *)PTR_CRYPTO_get_dynlock_destroy_callback_006a99d0)(), iVar2 != 0)) {
          hwcrhk_globals._32_4_ = hwcrhk_mutex_init;
          hwcrhk_globals._36_4_ = hwcrhk_mutex_lock;
          hwcrhk_globals._40_4_ = hwcrhk_mutex_unlock;
          hwcrhk_globals._44_4_ = hwcrhk_mutex_destroy;
        }
        iVar2 = get_context_constprop_2();
        if (iVar2 != 0) {
          if (hndidx_rsa != -1) {
            return 1;
          }
          hndidx_rsa = (*(code *)PTR_RSA_get_ex_new_index_006aa64c)
                                 (0,"nFast HWCryptoHook RSA key handle",0,0,0);
          return 1;
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x67,0x71,"e_chil.c",0x250);
        goto LAB_005d6b1c;
      }
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar12 = 0x68;
      uVar1 = 0x22d;
    }
  }
  else {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar12 = 100;
    uVar1 = 0x20e;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x67,uVar12,"e_chil.c",uVar1);
LAB_005d6b1c:
  if (hwcrhk_dso != 0) {
    (*(code *)PTR_DSO_free_006a9994)();
  }
  hwcrhk_dso = 0;
  p_hwcrhk_Init = 0;
  p_hwcrhk_Finish = 0;
  p_hwcrhk_ModExp = 0;
  p_hwcrhk_RSA = 0;
  p_hwcrhk_RandomBytes = 0;
  p_hwcrhk_RSALoadKey = 0;
  p_hwcrhk_RSAGetPublicKey = 0;
  p_hwcrhk_RSAUnloadKey = 0;
  p_hwcrhk_ModExpCRT = 0;
  return 0;
}

