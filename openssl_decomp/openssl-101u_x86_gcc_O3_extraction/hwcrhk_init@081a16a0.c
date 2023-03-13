
undefined4 hwcrhk_init(void)

{
  char *filename;
  DSO_FUNC_TYPE pDVar1;
  DSO_FUNC_TYPE pDVar2;
  DSO_FUNC_TYPE pDVar3;
  DSO_FUNC_TYPE pDVar4;
  CRYPTO_dynlock_value *l;
  CRYPTO_dynlock_value *l_00;
  DSO_FUNC_TYPE file;
  DSO_FUNC_TYPE line;
  DSO_FUNC_TYPE pDVar5;
  int iVar6;
  CRYPTO_dynlock_value *pCVar7;
  
  if (hwcrhk_dso == (DSO *)0x0) {
    filename = HWCRHK_LIBNAME;
    if (HWCRHK_LIBNAME == (char *)0x0) {
      filename = "nfhwcrhk";
    }
    hwcrhk_dso = DSO_load((DSO *)0x0,filename,(DSO_METHOD *)0x0,0);
    if (hwcrhk_dso == (DSO *)0x0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar6 = 0x22c;
    }
    else {
      pDVar1 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_Init");
      if (((((pDVar1 != (DSO_FUNC_TYPE)0x0) &&
            (pDVar2 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_Finish"), pDVar2 != (DSO_FUNC_TYPE)0x0)
            ) && (pDVar3 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_ModExp"),
                 pDVar3 != (DSO_FUNC_TYPE)0x0)) &&
          (((pDVar4 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RSA"), pDVar4 != (DSO_FUNC_TYPE)0x0 &&
            (l = (CRYPTO_dynlock_value *)DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RSALoadKey"),
            l != (CRYPTO_dynlock_value *)0x0)) &&
           ((l_00 = (CRYPTO_dynlock_value *)DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RSAGetPublicKey")
            , l_00 != (CRYPTO_dynlock_value *)0x0 &&
            ((file = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RSAUnloadKey"),
             file != (DSO_FUNC_TYPE)0x0 &&
             (line = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_RandomBytes"),
             line != (DSO_FUNC_TYPE)0x0)))))))) &&
         (pDVar5 = DSO_bind_func(hwcrhk_dso,"HWCryptoHook_ModExpCRT"), pDVar5 != (DSO_FUNC_TYPE)0x0)
         ) {
        p_hwcrhk_ModExpCRT = pDVar5;
        p_hwcrhk_RSAUnloadKey = file;
        p_hwcrhk_RSAGetPublicKey = l_00;
        p_hwcrhk_RSALoadKey = l;
        p_hwcrhk_RandomBytes = line;
        p_hwcrhk_RSA = pDVar4;
        p_hwcrhk_ModExp = pDVar3;
        p_hwcrhk_Finish = pDVar2;
        p_hwcrhk_Init = pDVar1;
        if ((((disable_mutex_callbacks == 0) &&
             (pCVar7 = CRYPTO_get_dynlock_create_callback((char *)l,(int)l_00),
             pCVar7 != (CRYPTO_dynlock_value *)0x0)) &&
            (CRYPTO_get_dynlock_lock_callback((int)l,l_00,(char *)file,(int)line),
            pCVar7 != (CRYPTO_dynlock_value *)0x0)) &&
           (CRYPTO_get_dynlock_destroy_callback(l,(char *)l_00,(int)file),
           pCVar7 != (CRYPTO_dynlock_value *)0x0)) {
          hwcrhk_globals._32_4_ = hwcrhk_mutex_init;
          hwcrhk_globals._36_4_ = hwcrhk_mutex_lock;
          hwcrhk_globals._40_4_ = hwcrhk_mutex_unlock;
          hwcrhk_globals._44_4_ = hwcrhk_mutex_destroy;
        }
        iVar6 = get_context_constprop_2();
        if (iVar6 != 0) {
          if (hndidx_rsa != -1) {
            return 1;
          }
          hndidx_rsa = RSA_get_ex_new_index
                                 (0,"nFast HWCryptoHook RSA key handle",(undefined1 *)0x0,
                                  (undefined1 *)0x0,(undefined1 *)0x0);
          return 1;
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x67,0x71,"e_chil.c",0x266);
        goto LAB_081a16dc;
      }
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar6 = 0x243;
    }
    ERR_put_error(HWCRHK_lib_error_code,0x67,0x68,"e_chil.c",iVar6);
  }
  else {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x67,100,"e_chil.c",0x226);
  }
LAB_081a16dc:
  if (hwcrhk_dso != (DSO *)0x0) {
    DSO_free(hwcrhk_dso);
  }
  hwcrhk_dso = (DSO *)0x0;
  p_hwcrhk_Init = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_Finish = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_ModExp = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_RSA = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_RandomBytes = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_RSALoadKey = (CRYPTO_dynlock_value *)0x0;
  p_hwcrhk_RSAGetPublicKey = (CRYPTO_dynlock_value *)0x0;
  p_hwcrhk_RSAUnloadKey = (DSO_FUNC_TYPE)0x0;
  p_hwcrhk_ModExpCRT = (DSO_FUNC_TYPE)0x0;
  return 0;
}

