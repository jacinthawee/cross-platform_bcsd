
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 hwcrhk_rsa_mod_exp(int *param_1,undefined4 *param_2,int param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  uint uVar12;
  int iVar13;
  char *pcVar14;
  undefined4 uVar15;
  undefined *local_464;
  undefined4 local_460;
  undefined4 local_45c;
  int local_458;
  undefined4 local_454;
  int local_450;
  undefined4 local_44c;
  int local_448;
  undefined4 local_444;
  int local_440;
  undefined4 local_43c;
  int local_438;
  undefined4 local_434;
  int local_430;
  int local_42c;
  uint local_428;
  undefined auStack_424 [1024];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_464 = auStack_424;
  local_460 = 0x400;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x6d,0x6a,"e_chil.c",0x3c4);
    uVar4 = 0;
  }
  else {
    puVar2 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006aa640)(param_3,hndidx_rsa);
    if (puVar2 == (undefined4 *)0x0) {
      if ((((*(int *)(param_3 + 0x1c) == 0) || (*(int *)(param_3 + 0x20) == 0)) ||
          (*(int *)(param_3 + 0x24) == 0)) ||
         ((*(int *)(param_3 + 0x28) == 0 || (*(int *)(param_3 + 0x2c) == 0)))) {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x6d,0x69,"e_chil.c",0x3fd);
        uVar4 = 0;
      }
      else {
        (*(code *)PTR_bn_expand2_006a9680)(param_1,*(undefined4 *)(*(int *)(param_3 + 0x10) + 4));
        local_428 = param_1[2] << 2;
        local_450 = (*(undefined4 **)(param_3 + 0x1c))[1] << 2;
        local_448 = (*(undefined4 **)(param_3 + 0x20))[1] << 2;
        local_440 = (*(undefined4 **)(param_3 + 0x24))[1] << 2;
        local_454 = **(undefined4 **)(param_3 + 0x1c);
        local_438 = (*(undefined4 **)(param_3 + 0x28))[1] << 2;
        local_43c = **(undefined4 **)(param_3 + 0x28);
        local_430 = (*(undefined4 **)(param_3 + 0x2c))[1] << 2;
        local_434 = **(undefined4 **)(param_3 + 0x2c);
        local_458 = param_2[1] << 2;
        local_44c = **(undefined4 **)(param_3 + 0x20);
        local_444 = **(undefined4 **)(param_3 + 0x24);
        local_45c = *param_2;
        local_42c = *param_1;
        iVar3 = (*p_hwcrhk_ModExpCRT)
                          (hwcrhk_context,local_45c,local_458,local_454,local_450,local_44c,
                           local_448,local_444,local_440,local_43c,local_438,local_434,local_430,
                           &local_42c,&local_464);
        uVar12 = local_428 >> 2;
        param_1[1] = uVar12;
        if (uVar12 != 0) {
          iVar13 = *param_1 + (local_428 & 0xfffffffc) + -8;
          do {
            if (*(int *)(iVar13 + 4) != 0) break;
            uVar12 = uVar12 - 1;
            iVar13 = iVar13 + -4;
          } while (uVar12 != 0);
          param_1[1] = uVar12;
        }
        if (iVar3 < 0) {
          if (iVar3 == -2) {
            if (HWCRHK_lib_error_code == 0) {
              HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
            }
            (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x6d,0x70,"e_chil.c",0x41b);
          }
          else {
            if (HWCRHK_lib_error_code == 0) {
              HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
            }
            (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x6d,0x6f,"e_chil.c",0x420);
          }
          goto LAB_005d66f8;
        }
LAB_005d6678:
        uVar4 = 1;
      }
    }
    else if (*(int *)(param_3 + 0x10) == 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x6d,0x69,"e_chil.c",0x3d3);
      uVar4 = 0;
    }
    else {
      (*(code *)PTR_bn_expand2_006a9680)(param_1,*(undefined4 *)(*(int *)(param_3 + 0x10) + 4));
      local_42c = *param_1;
      local_428 = param_1[2] << 2;
      local_434 = *param_2;
      local_430 = param_2[1] << 2;
      iVar3 = (*p_hwcrhk_RSA)(local_434,local_430,*puVar2,&local_42c,&local_464);
      uVar12 = local_428 >> 2;
      param_1[1] = uVar12;
      if (uVar12 != 0) {
        iVar13 = *param_1 + (local_428 & 0xfffffffc) + -8;
        do {
          if (*(int *)(iVar13 + 4) != 0) break;
          uVar12 = uVar12 - 1;
          iVar13 = iVar13 + -4;
        } while (uVar12 != 0);
        param_1[1] = uVar12;
      }
      if (-1 < iVar3) goto LAB_005d6678;
      if (iVar3 == -2) {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x6d,0x70,"e_chil.c",0x3eb);
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x6d,0x6f,"e_chil.c",0x3f0);
      }
LAB_005d66f8:
      (*(code *)PTR_ERR_add_error_data_006a9264)(1,local_464);
      uVar4 = 0;
    }
  }
  if (local_24 == *(int *)puVar1) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (hwcrhk_dso == 0) {
    pcVar14 = HWCRHK_LIBNAME;
    if (HWCRHK_LIBNAME == (char *)0x0) {
      pcVar14 = "nfhwcrhk";
    }
    hwcrhk_dso = (*(code *)PTR_DSO_load_006a99a4)(0,pcVar14,0,0);
    if (hwcrhk_dso == 0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      uVar15 = 0x68;
      uVar4 = 0x215;
    }
    else {
      iVar3 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_Init");
      if (((((iVar3 != 0) &&
            (iVar13 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_Finish"),
            iVar13 != 0)) &&
           ((iVar5 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_ModExp"),
            iVar5 != 0 &&
            (((pcVar6 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_RSA")
              , pcVar6 != (code *)0x0 &&
              (iVar7 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_RSALoadKey"),
              iVar7 != 0)) &&
             (iVar8 = (*(code *)PTR_DSO_bind_func_006a99ac)
                                (hwcrhk_dso,"HWCryptoHook_RSAGetPublicKey"), iVar8 != 0)))))) &&
          ((iVar9 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_RSAUnloadKey"),
           iVar9 != 0 &&
           (iVar10 = (*(code *)PTR_DSO_bind_func_006a99ac)(hwcrhk_dso,"HWCryptoHook_RandomBytes"),
           iVar10 != 0)))) &&
         (pcVar11 = (code *)(*(code *)PTR_DSO_bind_func_006a99ac)
                                      (hwcrhk_dso,"HWCryptoHook_ModExpCRT"), pcVar11 != (code *)0x0)
         ) {
        p_hwcrhk_ModExpCRT = pcVar11;
        p_hwcrhk_RSAUnloadKey = iVar9;
        p_hwcrhk_RSAGetPublicKey = iVar8;
        p_hwcrhk_RSALoadKey = iVar7;
        p_hwcrhk_RandomBytes = iVar10;
        p_hwcrhk_RSA = pcVar6;
        p_hwcrhk_ModExp = iVar5;
        p_hwcrhk_Finish = iVar13;
        p_hwcrhk_Init = iVar3;
        if (((disable_mutex_callbacks == 0) &&
            (iVar3 = (*(code *)PTR_CRYPTO_get_dynlock_create_callback_006a99c8)(), iVar3 != 0)) &&
           ((iVar3 = (*(code *)PTR_CRYPTO_get_dynlock_lock_callback_006a99cc)(), iVar3 != 0 &&
            (iVar3 = (*(code *)PTR_CRYPTO_get_dynlock_destroy_callback_006a99d0)(), iVar3 != 0)))) {
          hwcrhk_globals._32_4_ = hwcrhk_mutex_init;
          hwcrhk_globals._36_4_ = hwcrhk_mutex_lock;
          hwcrhk_globals._40_4_ = hwcrhk_mutex_unlock;
          hwcrhk_globals._44_4_ = hwcrhk_mutex_destroy;
        }
        iVar3 = get_context_constprop_2();
        if (iVar3 != 0) {
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
      uVar15 = 0x68;
      uVar4 = 0x22d;
    }
  }
  else {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar15 = 100;
    uVar4 = 0x20e;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x67,uVar15,"e_chil.c",uVar4);
LAB_005d6b1c:
  if (hwcrhk_dso != 0) {
    (*(code *)PTR_DSO_free_006a9994)();
  }
  hwcrhk_dso = 0;
  p_hwcrhk_Init = 0;
  p_hwcrhk_Finish = 0;
  p_hwcrhk_ModExp = 0;
  p_hwcrhk_RSA = (code *)0x0;
  p_hwcrhk_RandomBytes = 0;
  p_hwcrhk_RSALoadKey = 0;
  p_hwcrhk_RSAGetPublicKey = 0;
  p_hwcrhk_RSAUnloadKey = 0;
  p_hwcrhk_ModExpCRT = (code *)0x0;
  return 0;
}

