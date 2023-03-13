
void main(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  ulong uVar6;
  undefined1 *puVar7;
  void *__status;
  BIO_METHOD *type;
  void *pvVar8;
  char *pcVar9;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar10;
  undefined4 extraout_ECX_01;
  int iVar11;
  uint uVar12;
  size_t __nmemb;
  undefined4 extraout_EDX;
  int in_GS_OFFSET;
  byte bVar13;
  undefined8 uVar14;
  _LHASH *local_47c;
  char *local_478;
  undefined local_46c [4];
  undefined4 *local_468;
  long local_464;
  void *local_460;
  undefined4 local_45c;
  undefined local_458 [4];
  undefined *local_454;
  undefined local_44c [37];
  char acStack_427 [1027];
  undefined4 local_24;
  undefined4 *puStack_18;
  
  piVar3 = param_2;
  iVar11 = param_1;
  bVar13 = 0;
  puStack_18 = &param_1;
  local_460 = (void *)0x0;
  local_45c = 0;
  local_24 = *(undefined4 *)(in_GS_OFFSET + 0x14);
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  pcVar4 = getenv("OPENSSL_DEBUG_MEMORY");
  if (pcVar4 != (char *)0x0) {
    pcVar4 = getenv("OPENSSL_DEBUG_MEMORY");
    if ((((*pcVar4 == 'o') && (pcVar4[1] == 'f')) && (pcVar4[2] == 'f')) && (pcVar4[3] == '\0')) {
      CRYPTO_set_mem_debug_functions((m *)0x0,(r *)0x0,(f *)0x0,(so *)0x0,(go *)0x0);
    }
    else {
      CRYPTO_set_mem_debug_functions
                (CRYPTO_dbg_malloc,CRYPTO_dbg_realloc,CRYPTO_dbg_free,CRYPTO_dbg_set_options,
                 CRYPTO_dbg_get_options);
      CRYPTO_set_mem_debug_options(3);
    }
  }
  CRYPTO_mem_ctrl(1);
  CRYPTO_set_locking_callback(lock_dbg_cb);
  pcVar4 = getenv("OPENSSL_FIPS");
  if (pcVar4 != (char *)0x0) {
    fwrite("FIPS mode not supported.\n",1,0x19,stderr);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  signal(0xd,(__sighandler_t)0x1);
  CRYPTO_set_mem_functions(malloc,realloc,free);
  ERR_load_crypto_strings();
  OPENSSL_add_all_algorithms_noconf();
  ENGINE_load_builtin_engines();
  setup_ui_method();
  pcVar4 = getenv("OPENSSL_CONF");
  if (pcVar4 == (char *)0x0) {
    pcVar9 = getenv("SSLEAY_CONF");
    local_478 = pcVar4;
    if (pcVar9 == (char *)0x0) {
      pcVar9 = (char *)make_config_name();
      local_478 = pcVar9;
    }
  }
  else {
    local_478 = (char *)0x0;
    pcVar9 = pcVar4;
  }
  default_config_file = pcVar9;
  config = NCONF_new((CONF_METHOD *)0x0);
  iVar5 = NCONF_load(config,pcVar9,&local_464);
  if (iVar5 == 0) {
    uVar6 = ERR_peek_last_error();
    if ((uVar6 & 0xfff) != 0x72) {
      ERR_print_errors(bio_err);
      NCONF_free(config);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    BIO_printf(bio_err,"WARNING: can\'t open config file: %s\n",pcVar9);
    ERR_clear_error();
    NCONF_free(config);
    config = (CONF *)0x0;
  }
  __nmemb = 0;
  if (functions._4_4_ != 0) {
    puVar7 = functions;
    do {
      piVar1 = (int *)(puVar7 + 0x10);
      __nmemb = __nmemb + 1;
      puVar7 = puVar7 + 0xc;
    } while (*piVar1 != 0);
  }
  qsort(functions,__nmemb,0xc,SortFnByName);
  local_47c = lh_new(function_LHASH_HASH,function_LHASH_COMP);
  uVar10 = extraout_ECX;
  if (local_47c == (_LHASH *)0x0) {
    local_47c = (_LHASH *)0x0;
  }
  else if (functions._4_4_ != 0) {
    puVar7 = functions;
    do {
      lh_insert(local_47c,puVar7);
      piVar1 = (int *)(puVar7 + 0x10);
      uVar10 = extraout_ECX_00;
      puVar7 = puVar7 + 0xc;
    } while (*piVar1 != 0);
  }
  program_name(*piVar3,local_44c,0x28,uVar10);
  local_454 = local_44c;
  __status = lh_retrieve(local_47c,local_458);
  if (__status == (void *)0x0) {
    if (iVar11 == 1) {
LAB_0804bad9:
      pcVar4 = acStack_427 + 3;
      iVar11 = 0;
      iVar5 = 0x400;
      do {
        pcVar9 = "OpenSSL> ";
        if (iVar11 != 0) {
          pcVar9 = ">";
        }
        *pcVar4 = '\0';
        fputs(pcVar9,stdout);
        fflush(stdout);
        pcVar9 = fgets(pcVar4,iVar5,stdin);
        if ((pcVar9 == (char *)0x0) || (*pcVar4 == '\0')) goto LAB_0804bb59;
        uVar12 = 0xffffffff;
        pcVar9 = pcVar4;
        do {
          if (uVar12 == 0) break;
          uVar12 = uVar12 - 1;
          cVar2 = *pcVar9;
          pcVar9 = pcVar9 + (uint)bVar13 * -2 + 1;
        } while (cVar2 != '\0');
        uVar12 = ~uVar12;
        if (((int)(uVar12 - 1) < 2) || (pcVar4[uVar12 - 3] != '\\')) goto LAB_0804ba74;
        iVar11 = uVar12 - 3;
        pcVar4 = pcVar4 + iVar11;
        iVar5 = iVar5 - iVar11;
      } while( true );
    }
    pvVar8 = (void *)do_cmd();
    if (-1 < (int)pvVar8) {
      __status = pvVar8;
    }
  }
  else {
    *piVar3 = (int)local_44c;
    __status = (void *)(**(code **)((int)__status + 8))(iVar11,piVar3,extraout_EDX,extraout_EDX);
  }
LAB_0804b938:
  if (local_478 != (char *)0x0) {
    CRYPTO_free(local_478);
  }
  if (config != (CONF *)0x0) {
    NCONF_free(config);
    config = (CONF *)0x0;
  }
  if (local_47c != (_LHASH *)0x0) {
    lh_free(local_47c);
  }
  if (local_460 != (void *)0x0) {
    CRYPTO_free(local_460);
  }
  CONF_modules_unload(1);
  destroy_ui_method();
  OBJ_cleanup();
  EVP_cleanup();
  ENGINE_cleanup();
  CRYPTO_cleanup_all_ex_data();
  ERR_remove_thread_state((CRYPTO_THREADID *)0x0);
  RAND_cleanup();
  ERR_free_strings();
  COMP_zlib_cleanup();
  CRYPTO_mem_leaks(bio_err);
  if (bio_err != (BIO *)0x0) {
    BIO_free(bio_err);
    bio_err = (BIO *)0x0;
  }
                    /* WARNING: Subroutine does not return */
  exit((int)__status);
LAB_0804ba74:
  uVar14 = chopup_args(&local_460,acStack_427 + 3,local_46c,&local_468);
  uVar10 = (undefined4)((ulonglong)uVar14 >> 0x20);
  if ((int)uVar14 == 0) {
    BIO_printf(bio_err,"bad exit\n",uVar10,uVar10);
    __status = (void *)0x1;
    goto LAB_0804b938;
  }
  iVar11 = do_cmd();
  if (iVar11 < 0) goto LAB_0804bb59;
  if (iVar11 != 0) {
    BIO_printf(bio_err,"error in %s\n",*local_468,extraout_ECX_01);
  }
  BIO_ctrl(bio_err,0xb,0,(void *)0x0);
  goto LAB_0804bad9;
LAB_0804bb59:
  __status = (void *)0x0;
  goto LAB_0804b938;
}

