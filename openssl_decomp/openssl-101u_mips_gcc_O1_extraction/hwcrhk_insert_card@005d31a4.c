
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint hwcrhk_insert_card(int param_1,char *param_2,char *param_3,char *param_4)

{
  undefined *puVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined *local_2040;
  char local_2025;
  undefined local_2024 [8192];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_4 == (char *)0x0) {
    iVar4 = 0;
    if ((int *)param_3 != (int *)0x0) {
      iVar5 = *(int *)param_3;
      pcVar2 = (char *)0x0;
      pcVar9 = *(char **)((int)param_3 + 4);
      if (iVar5 == 0) goto LAB_005d33ec;
LAB_005d3204:
      pcVar6 = pcVar9;
      if (pcVar9 == (char *)0x0) {
        pcVar6 = pcVar2;
      }
      goto LAB_005d320c;
    }
LAB_005d3400:
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    param_3 = &DAT_0000006c;
    param_2 = "e_chil.c";
    local_2040 = (undefined *)0x4f4;
    pcVar6 = &DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code);
    uVar3 = 0xffffffff;
  }
  else {
    iVar4 = *(int *)(param_4 + 4);
    pcVar2 = *(char **)(param_4 + 8);
    iVar5 = iVar4;
    pcVar6 = pcVar2;
    if ((int *)param_3 != (int *)0x0) {
      iVar5 = *(int *)param_3;
      pcVar9 = *(char **)((int)param_3 + 4);
      if (iVar5 != 0) goto LAB_005d3204;
LAB_005d33ec:
      iVar5 = iVar4;
      pcVar6 = pcVar2;
      if (pcVar9 != (char *)0x0) {
        pcVar6 = pcVar9;
        if (iVar4 != 0) goto LAB_005d320c;
        goto LAB_005d3400;
      }
    }
    if (iVar5 == 0) goto LAB_005d3400;
LAB_005d320c:
    pcVar2 = param_2;
    iVar5 = (*(code *)PTR_UI_new_method_006a7b24)(iVar5);
    if (iVar5 == 0) {
LAB_005d33cc:
      param_2 = param_4;
      pcVar6 = pcVar2;
      uVar3 = 0xffffffff;
    }
    else if ((param_2 == (char *)0x0) || (param_3 = "encrypt", *param_2 == '\0')) {
      local_2024[0] = 0;
      iVar4 = (*(code *)PTR_UI_dup_info_string_006a9570)(iVar5,local_2024);
      param_2 = param_4;
      if (-1 < iVar4) goto LAB_005d3254;
LAB_005d3380:
      (*(code *)PTR_UI_add_user_data_006a956c)(iVar5);
LAB_005d3394:
      (*(code *)PTR_UI_free_006a7b38)(iVar5);
      pcVar2 = pcVar6;
      param_4 = param_2;
      if (iVar4 != -2) goto LAB_005d33cc;
LAB_005d33ac:
      uVar3 = 1;
    }
    else {
      param_3 = "Current card: \"%s\"\n";
      (*(code *)PTR_BIO_snprintf_006a6f60)(local_2024,0x1fff);
      iVar4 = (*(code *)PTR_UI_dup_info_string_006a9570)(iVar5,local_2024);
      if (iVar4 < 0) goto LAB_005d3380;
LAB_005d3254:
      param_3 = "encrypt";
      if (param_1 != 0) {
        (*(code *)PTR_BIO_snprintf_006a6f60)(local_2024,0x1fff,"Insert card \"%s\"",param_1);
        param_2 = "\r\n";
        param_3 = "\n then hit <enter> or C<enter> to cancel\n";
        local_2040 = &DAT_00673ab8;
        iVar4 = (*(code *)PTR_UI_dup_input_boolean_006a9574)(iVar5,local_2024);
        (*(code *)PTR_UI_add_user_data_006a956c)(iVar5);
        if (-1 < iVar4) goto LAB_005d32d4;
        goto LAB_005d3394;
      }
      (*(code *)PTR_UI_add_user_data_006a956c)(iVar5);
LAB_005d32d4:
      iVar4 = (*(code *)PTR_UI_process_006a7b34)(iVar5);
      (*(code *)PTR_UI_free_006a7b38)(iVar5);
      if (iVar4 == -2) goto LAB_005d33ac;
      uVar3 = 0xffffffff;
      if (-1 < iVar4) {
        uVar3 = (uint)(local_2025 == 'C');
      }
    }
  }
  if (local_24 == *(int *)puVar1) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (pcVar6 == &DAT_00000065) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2e9);
    uVar8 = 0x2eb;
    disable_mutex_callbacks = 1;
    goto LAB_005d350c;
  }
  if ((int)pcVar6 < 0x66) {
    if (pcVar6 == &SUB_00000004) {
LAB_005d36b8:
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2ca);
      uVar8 = 0x2cc;
      password_context._4_4_ = param_2;
      goto LAB_005d350c;
    }
    if ((int)pcVar6 < 5) {
      if (pcVar6 == (char *)0x1) {
        (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2b7);
        if (logstream != (char *)0x0) {
          (*(code *)PTR_BIO_free_006a6e70)();
          logstream = (char *)0x0;
        }
        iVar5 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(param_2 + 0x2c,1,0x15,"e_chil.c",700);
        pcVar6 = param_2;
        if (iVar5 < 2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,100,0x65,"e_chil.c",0x2bf);
          pcVar6 = logstream;
        }
        logstream = pcVar6;
        uVar8 = 0x2c1;
      }
      else {
        if (pcVar6 != &SUB_00000002) goto LAB_005d373c;
        (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2c4);
        uVar8 = 0x2c6;
        password_context._0_4_ = local_2040;
      }
      goto LAB_005d350c;
    }
    if (pcVar6 == &DAT_00000005) {
LAB_005d35a8:
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2d0);
      uVar8 = 0x2d2;
      password_context._8_4_ = param_2;
      goto LAB_005d350c;
    }
    if (pcVar6 != &DAT_00000064) goto LAB_005d373c;
  }
  else {
    if (pcVar6 == &DAT_000000ca) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2ee);
      uVar8 = 0x2f0;
      disable_mutex_callbacks = (uint)((int *)param_3 != (int *)0x0);
      goto LAB_005d350c;
    }
    if (0xca < (int)pcVar6) {
      if (pcVar6 != (char *)0xcb) {
        if (pcVar6 != &DAT_000000cc) goto LAB_005d373c;
        goto LAB_005d35a8;
      }
      goto LAB_005d36b8;
    }
    if (pcVar6 == &DAT_000000c8) {
      if (hwcrhk_dso == 0) {
        if (param_2 != (char *)0x0) {
          if (HWCRHK_LIBNAME != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          HWCRHK_LIBNAME = 0;
          HWCRHK_LIBNAME = (*(code *)PTR_BUF_strdup_006a6fdc)(param_2);
          return (uint)(HWCRHK_LIBNAME != 0);
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar7 = 0x43;
        uVar8 = 0x2af;
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar7 = 100;
        uVar8 = 0x2ab;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,100,uVar7,"e_chil.c",uVar8);
      return 0;
    }
    if (pcVar6 != (char *)0xc9) {
LAB_005d373c:
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(HWCRHK_lib_error_code,100,0x67,"e_chil.c",0x2f6);
      return 0;
    }
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_chil.c",0x2da);
  if ((int *)param_3 == (int *)0x0) {
    hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ & 0xffffffef;
  }
  else {
    hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ | 0x10;
  }
  uVar8 = 0x2df;
LAB_005d350c:
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_chil.c",uVar8);
  return 1;
}

