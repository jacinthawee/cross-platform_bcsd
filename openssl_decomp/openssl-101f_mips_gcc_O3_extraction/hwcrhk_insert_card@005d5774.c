
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_4 == (char *)0x0) {
    iVar4 = 0;
    if ((int *)param_3 != (int *)0x0) {
      iVar5 = *(int *)param_3;
      pcVar2 = (char *)0x0;
      pcVar9 = *(char **)((int)param_3 + 4);
      if (iVar5 == 0) goto LAB_005d59bc;
LAB_005d57d4:
      pcVar6 = pcVar9;
      if (pcVar9 == (char *)0x0) {
        pcVar6 = pcVar2;
      }
      goto LAB_005d57dc;
    }
LAB_005d59d0:
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    param_3 = &DAT_0000006c;
    param_2 = "e_chil.c";
    local_2040 = (undefined *)0x502;
    pcVar6 = &DAT_00000068;
    (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code);
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
      if (iVar5 != 0) goto LAB_005d57d4;
LAB_005d59bc:
      iVar5 = iVar4;
      pcVar6 = pcVar2;
      if (pcVar9 != (char *)0x0) {
        pcVar6 = pcVar9;
        if (iVar4 != 0) goto LAB_005d57dc;
        goto LAB_005d59d0;
      }
    }
    if (iVar5 == 0) goto LAB_005d59d0;
LAB_005d57dc:
    pcVar2 = param_2;
    iVar5 = (*(code *)PTR_UI_new_method_006a8c10)(iVar5);
    if (iVar5 == 0) {
LAB_005d599c:
      param_2 = param_4;
      pcVar6 = pcVar2;
      uVar3 = 0xffffffff;
    }
    else if ((param_2 == (char *)0x0) || (param_3 = "7 datafinal", *param_2 == '\0')) {
      local_2024[0] = 0;
      iVar4 = (*(code *)PTR_UI_dup_info_string_006aa67c)(iVar5,local_2024);
      param_2 = param_4;
      if (-1 < iVar4) goto LAB_005d5824;
LAB_005d5950:
      (*(code *)PTR_UI_add_user_data_006aa678)(iVar5);
LAB_005d5964:
      (*(code *)PTR_UI_free_006a8c24)(iVar5);
      pcVar2 = pcVar6;
      param_4 = param_2;
      if (iVar4 != -2) goto LAB_005d599c;
LAB_005d597c:
      uVar3 = 1;
    }
    else {
      param_3 = "Current card: \"%s\"\n";
      (*(code *)PTR_BIO_snprintf_006a8060)(local_2024,0x1fff);
      iVar4 = (*(code *)PTR_UI_dup_info_string_006aa67c)(iVar5,local_2024);
      if (iVar4 < 0) goto LAB_005d5950;
LAB_005d5824:
      param_3 = "7 datafinal";
      if (param_1 != 0) {
        (*(code *)PTR_BIO_snprintf_006a8060)(local_2024,0x1fff,"Insert card \"%s\"",param_1);
        param_2 = "\r\n";
        param_3 = "\n then hit <enter> or C<enter> to cancel\n";
        local_2040 = &DAT_006743c8;
        iVar4 = (*(code *)PTR_UI_dup_input_boolean_006aa680)(iVar5,local_2024);
        (*(code *)PTR_UI_add_user_data_006aa678)(iVar5);
        if (-1 < iVar4) goto LAB_005d58a4;
        goto LAB_005d5964;
      }
      (*(code *)PTR_UI_add_user_data_006aa678)(iVar5);
LAB_005d58a4:
      iVar4 = (*(code *)PTR_UI_process_006a8c20)(iVar5);
      (*(code *)PTR_UI_free_006a8c24)(iVar5);
      if (iVar4 == -2) goto LAB_005d597c;
      uVar3 = 0xffffffff;
      if (-1 < iVar4) {
        uVar3 = (uint)(local_2025 == 'C');
      }
    }
  }
  if (local_24 == *(int *)puVar1) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (pcVar6 == &DAT_00000065) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2d7);
    uVar8 = 0x2d9;
    disable_mutex_callbacks = 1;
    goto LAB_005d5adc;
  }
  if ((int)pcVar6 < 0x66) {
    if (pcVar6 == &SUB_00000004) {
LAB_005d5c88:
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2ba);
      uVar8 = 700;
      password_context._4_4_ = param_2;
      goto LAB_005d5adc;
    }
    if ((int)pcVar6 < 5) {
      if (pcVar6 == (char *)0x1) {
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2a6);
        if (logstream != (char *)0x0) {
          (*(code *)PTR_BIO_free_006a7f70)();
          logstream = (char *)0x0;
        }
        iVar5 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(param_2 + 0x2c,1,0x15,"e_chil.c",0x2ac);
        pcVar6 = param_2;
        if (iVar5 < 2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,100,0x65,"e_chil.c",0x2af);
          pcVar6 = logstream;
        }
        logstream = pcVar6;
        uVar8 = 0x2b1;
      }
      else {
        if (pcVar6 != &SUB_00000002) goto LAB_005d5d0c;
        (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2b4);
        uVar8 = 0x2b6;
        password_context._0_4_ = local_2040;
      }
      goto LAB_005d5adc;
    }
    if (pcVar6 == &DAT_00000005) {
LAB_005d5b78:
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2c0);
      uVar8 = 0x2c2;
      password_context._8_4_ = param_2;
      goto LAB_005d5adc;
    }
    if (pcVar6 != &DAT_00000064) goto LAB_005d5d0c;
  }
  else {
    if (pcVar6 == &DAT_000000ca) {
      (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2dc);
      uVar8 = 0x2de;
      disable_mutex_callbacks = (uint)((int *)param_3 != (int *)0x0);
      goto LAB_005d5adc;
    }
    if (0xca < (int)pcVar6) {
      if (pcVar6 != (char *)0xcb) {
        if (pcVar6 != &DAT_000000cc) goto LAB_005d5d0c;
        goto LAB_005d5b78;
      }
      goto LAB_005d5c88;
    }
    if (pcVar6 == &DAT_000000c8) {
      if (hwcrhk_dso == 0) {
        if (param_2 != (char *)0x0) {
          if (HWCRHK_LIBNAME != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          HWCRHK_LIBNAME = 0;
          HWCRHK_LIBNAME = (*(code *)PTR_BUF_strdup_006a80dc)(param_2);
          return (uint)(HWCRHK_LIBNAME != 0);
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar7 = 0x43;
        uVar8 = 0x29e;
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        uVar7 = 100;
        uVar8 = 0x299;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,100,uVar7,"e_chil.c",uVar8);
      return 0;
    }
    if (pcVar6 != (char *)0xc9) {
LAB_005d5d0c:
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,100,0x67,"e_chil.c",0x2e4);
      return 0;
    }
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x1e,"e_chil.c",0x2c8);
  if ((int *)param_3 == (int *)0x0) {
    hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ & 0xffffffef;
  }
  else {
    hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ | 0x10;
  }
  uVar8 = 0x2cf;
LAB_005d5adc:
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x1e,"e_chil.c",uVar8);
  return 1;
}

