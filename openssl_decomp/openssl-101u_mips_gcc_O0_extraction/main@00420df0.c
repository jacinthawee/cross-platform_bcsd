
void main(int param_1,int *param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined4 local_474;
  undefined4 *local_470;
  undefined auStack_46c [4];
  int local_468;
  undefined4 local_464;
  undefined auStack_460 [4];
  undefined *local_45c;
  undefined auStack_454 [40];
  char local_42c [1024];
  undefined4 local_2c;
  
  local_468 = 0;
  local_464 = 0;
  local_2c = *(undefined4 *)PTR___stack_chk_guard_006a9ae8;
  if (bio_err == 0) {
    uVar9 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    bio_err = (*(code *)PTR_BIO_new_006a6ea4)(uVar9);
    if (bio_err != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(bio_err,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
    }
  }
  iVar5 = (*(code *)PTR_getenv_006a9a60)("OPENSSL_DEBUG_MEMORY");
  if (iVar5 != 0) {
    pcVar6 = (char *)(*(code *)PTR_getenv_006a9a60)("OPENSSL_DEBUG_MEMORY");
    if ((((*pcVar6 == 'o') && (pcVar6[1] == 'f')) && (pcVar6[2] == 'f')) && (pcVar6[3] == '\0')) {
      (*(code *)PTR_CRYPTO_set_mem_debug_functions_006a73d4)(0,0,0,0,0);
    }
    else {
      (*(code *)PTR_CRYPTO_set_mem_debug_functions_006a73d4)
                (PTR_CRYPTO_dbg_malloc_006a73f0,PTR_CRYPTO_dbg_realloc_006a73ec,
                 PTR_CRYPTO_dbg_free_006a73e8,PTR_CRYPTO_dbg_set_options_006a73e4,
                 PTR_CRYPTO_dbg_get_options_006a73e0);
      (*(code *)PTR_CRYPTO_set_mem_debug_options_006a73f4)(3);
    }
  }
  (*(code *)PTR_CRYPTO_mem_ctrl_006a73d8)(1);
  (*(code *)PTR_CRYPTO_set_locking_callback_006a73dc)(lock_dbg_cb);
  iVar5 = (*(code *)PTR_getenv_006a9a60)("OPENSSL_FIPS");
  if (iVar5 != 0) {
    (*(code *)PTR_fwrite_006a9a74)
              ("FIPS mode not supported.\n",1,0x19,*(undefined4 *)PTR_stderr_006a9af8);
    (*(code *)PTR_exit_006a9a40)(1);
    return;
  }
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  (*(code *)PTR_CRYPTO_set_mem_functions_006a73f8)
            (PTR_malloc_006a9a58,PTR_realloc_006a9a5c,PTR_free_006a9af0);
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  (*(code *)PTR_OPENSSL_add_all_algorithms_noconf_006a73fc)();
  (*(code *)PTR_ENGINE_load_builtin_engines_006a7400)();
  (*(code *)PTR_setup_ui_method_006a7404)();
  iVar5 = (*(code *)PTR_getenv_006a9a60)("OPENSSL_CONF");
  if (iVar5 == 0) {
    iVar12 = (*(code *)PTR_getenv_006a9a60)("SSLEAY_CONF");
    if (iVar12 == 0) {
      iVar12 = (*(code *)PTR_make_config_name_006a7448)();
      iVar5 = iVar12;
    }
  }
  else {
    iVar12 = iVar5;
    iVar5 = 0;
  }
  default_config_file = iVar12;
  config = (*(code *)PTR_NCONF_new_006a6e58)(0);
  iVar7 = (*(code *)PTR_NCONF_load_006a6e5c)(config,iVar12,auStack_46c);
  if (iVar7 == 0) {
    uVar8 = (*(code *)PTR_ERR_peek_last_error_006a7408)();
    if ((uVar8 & 0xfff) != 0x72) {
      (*(code *)PTR_ERR_print_errors_006a6e40)();
      (*(code *)PTR_NCONF_free_006a6e6c)(config);
      (*(code *)PTR_exit_006a9a40)(1);
      return;
    }
    (*(code *)PTR_BIO_printf_006a6e38)(bio_err,"WARNING: can\'t open config file: %s\n",iVar12);
    (*(code *)PTR_ERR_clear_error_006a6ee0)();
    (*(code *)PTR_NCONF_free_006a6e6c)(config);
    config = 0;
  }
  puVar13 = functions;
  iVar12 = 0;
  puVar2 = puVar13;
  iVar7 = functions._4_4_;
  while (iVar7 != 0) {
    iVar12 = iVar12 + 1;
    iVar7 = *(int *)(puVar2 + 0x10);
    puVar2 = puVar2 + 0xc;
  }
  (*(code *)PTR_qsort_006a9988)(functions,iVar12,0xc,SortFnByName);
  iVar7 = (*(code *)PTR_lh_new_006a740c)(function_LHASH_HASH,function_LHASH_COMP);
  iVar12 = functions._4_4_;
  if (iVar7 == 0) {
    iVar7 = 0;
  }
  else {
    while (iVar12 != 0) {
      (*(code *)PTR_lh_insert_006a7414)(iVar7,puVar13);
      piVar1 = (int *)(puVar13 + 0x10);
      puVar13 = puVar13 + 0xc;
      iVar12 = *piVar1;
    }
  }
  (*(code *)PTR_program_name_006a7410)(*param_2,auStack_454,0x28);
  local_45c = auStack_454;
  iVar12 = (*(code *)PTR_lh_retrieve_006a73b0)(iVar7,auStack_460);
  puVar4 = PTR_stdin_006a9a14;
  puVar3 = PTR_stdout_006a99c8;
  if (iVar12 == 0) {
    if (param_1 == 1) {
      while( true ) {
        iVar12 = 0;
        iVar14 = 0x400;
        pcVar6 = local_42c;
        while( true ) {
          *pcVar6 = '\0';
          if (iVar12 == 0) {
            pcVar11 = "OpenSSL> ";
          }
          else {
            pcVar11 = ">";
          }
          (*(code *)PTR_fputs_006a9954)(pcVar11,*(undefined4 *)puVar3);
          (*(code *)PTR_fflush_006a9b04)(*(undefined4 *)puVar3);
          iVar12 = (*(code *)PTR_fgets_006a9ae0)(pcVar6,iVar14,*(undefined4 *)puVar4);
          if ((iVar12 == 0) || (*pcVar6 == '\0')) goto LAB_00421438;
          iVar10 = (*(code *)PTR_strlen_006a9a24)(pcVar6);
          if ((iVar10 < 2) || (iVar12 = iVar10 + -2, pcVar6[iVar10 + -2] != '\\')) break;
          pcVar6 = pcVar6 + iVar12;
          iVar14 = iVar14 - iVar12;
        }
        iVar12 = (*(code *)PTR_chopup_args_006a7444)(&local_468,local_42c,&local_474,&local_470);
        if (iVar12 == 0) {
          iVar12 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(bio_err,"bad exit\n");
          goto LAB_004211b0;
        }
        iVar12 = do_cmd(iVar7,local_474,local_470);
        if (iVar12 < 0) break;
        if (iVar12 != 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(bio_err,"error in %s\n",*local_470);
        }
        (*(code *)PTR_BIO_ctrl_006a6e18)(bio_err,0xb,0,0);
      }
LAB_00421438:
      iVar12 = 0;
    }
    else {
      iVar12 = do_cmd(iVar7,param_1 + -1,param_2 + 1);
      if (iVar12 < 0) {
        iVar12 = 0;
      }
    }
  }
  else {
    *param_2 = (int)auStack_454;
    iVar12 = (**(code **)(iVar12 + 8))(param_1,param_2);
  }
LAB_004211b0:
  if (iVar5 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
  }
  if (config != 0) {
    (*(code *)PTR_NCONF_free_006a6e6c)();
    config = 0;
  }
  if (iVar7 != 0) {
    (*(code *)PTR_lh_free_006a7418)(iVar7);
  }
  if (local_468 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  (*(code *)PTR_CONF_modules_unload_006a741c)(1);
  (*(code *)PTR_destroy_ui_method_006a7420)();
  (*(code *)PTR_OBJ_cleanup_006a6e98)();
  (*(code *)PTR_EVP_cleanup_006a7424)();
  (*(code *)PTR_ENGINE_cleanup_006a7428)();
  (*(code *)PTR_CRYPTO_cleanup_all_ex_data_006a742c)();
  (*(code *)PTR_ERR_remove_thread_state_006a7430)(0);
  (*(code *)PTR_RAND_cleanup_006a7434)();
  (*(code *)PTR_ERR_free_strings_006a7438)();
  (*(code *)PTR_COMP_zlib_cleanup_006a743c)();
  (*(code *)PTR_CRYPTO_mem_leaks_006a7440)(bio_err);
  if (bio_err != 0) {
    (*(code *)PTR_BIO_free_006a6e70)();
    bio_err = 0;
  }
  (*(code *)PTR_exit_006a9a40)(iVar12);
  return;
}
