
void main(int param_1,int *param_2)

{
  int *piVar1;
  char *pcVar2;
  char *pcVar3;
  CONF *pCVar4;
  ulong uVar5;
  _LHASH *lh;
  void *pvVar6;
  uint uVar7;
  BIO_METHOD *type;
  char *pcVar8;
  size_t sVar9;
  undefined *__nmemb;
  undefined4 *puVar10;
  int iVar11;
  char *local_47c;
  undefined4 local_474;
  undefined4 *local_470;
  long lStack_46c;
  void *local_468;
  undefined4 local_464;
  undefined auStack_460 [4];
  undefined *local_45c;
  undefined auStack_454 [40];
  char local_42c [1024];
  undefined4 local_2c;
  
  local_2c = __TMC_END__;
  local_468 = (void *)0x0;
  local_464 = 0;
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  pcVar2 = getenv("OPENSSL_DEBUG_MEMORY");
  if (pcVar2 != (char *)0x0) {
    pcVar2 = getenv("OPENSSL_DEBUG_MEMORY");
    if ((((*pcVar2 == 'o') && (pcVar2[1] == 'f')) && (pcVar2[2] == 'f')) && (pcVar2[3] == '\0')) {
      CRYPTO_set_mem_debug_functions((m *)0x0,(r *)0x0,(f *)0x0,(so *)0x0,(go *)0x0);
    }
    else {
      CRYPTO_set_mem_debug_functions
                (CRYPTO_dbg_malloc + 1,CRYPTO_dbg_realloc + 1,CRYPTO_dbg_free + 1,
                 CRYPTO_dbg_set_options + 1,CRYPTO_dbg_get_options + 1);
      CRYPTO_set_mem_debug_options(3);
    }
  }
  CRYPTO_mem_ctrl(1);
  CRYPTO_set_locking_callback(lock_dbg_cb + 1);
  pcVar2 = getenv("OPENSSL_FIPS");
  if (pcVar2 != (char *)0x0) {
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
  pcVar3 = getenv("OPENSSL_CONF");
  if ((pcVar3 == (char *)0x0) &&
     (pcVar8 = getenv("SSLEAY_CONF"), pcVar2 = pcVar3, pcVar3 = pcVar8, pcVar8 == (char *)0x0)) {
    pcVar2 = (char *)make_config_name();
    pcVar3 = pcVar2;
  }
  default_config_file = pcVar3;
  config = NCONF_new((CONF_METHOD *)0x0);
  pCVar4 = (CONF *)NCONF_load(config,pcVar3,&lStack_46c);
  if (pCVar4 == (CONF *)0x0) {
    uVar5 = ERR_peek_last_error();
    if ((uVar5 & 0xfff) != 0x72) {
      ERR_print_errors(bio_err);
      NCONF_free(config);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    BIO_printf(bio_err,"WARNING: can\'t open config file: %s\n",pcVar3);
    ERR_clear_error();
    NCONF_free(config);
    config = pCVar4;
  }
  __nmemb = PTR_s_verify_0018a20c;
  if (PTR_s_verify_0018a20c != (undefined *)0x0) {
    __nmemb = (undefined *)0x0;
    puVar10 = &functions;
    do {
      piVar1 = puVar10 + 4;
      __nmemb = __nmemb + 1;
      puVar10 = puVar10 + 3;
    } while (*piVar1 != 0);
  }
  puVar10 = &functions;
  qsort(&functions,(size_t)__nmemb,0xc,SortFnByName + 1);
  lh = lh_new(function_LHASH_HASH + 1,function_LHASH_COMP + 1);
  if (lh != (_LHASH *)0x0) {
    for (; puVar10[1] != 0; puVar10 = puVar10 + 3) {
      lh_insert(lh,puVar10);
    }
  }
  program_name(*param_2,auStack_454,0x28);
  local_45c = auStack_454;
  pvVar6 = lh_retrieve(lh,auStack_460);
  if (pvVar6 == (void *)0x0) {
    if (param_1 == 1) {
      pcVar3 = local_42c;
      iVar11 = 0x400;
      local_47c = ">";
      while( true ) {
        pcVar8 = local_47c;
        if (pvVar6 == (void *)0x0) {
          pcVar8 = "OpenSSL> ";
        }
        *pcVar3 = '\0';
        fputs(pcVar8,stdout);
        fflush(stdout);
        pcVar8 = fgets(pcVar3,iVar11,stdin);
        if ((pcVar8 == (char *)0x0) || (*pcVar3 == '\0')) break;
        sVar9 = strlen(pcVar3);
        if (((int)sVar9 < 2) || (pcVar3[sVar9 - 2] != '\\')) {
          iVar11 = chopup_args(&local_468,local_42c,&local_474,&local_470);
          if (iVar11 == 0) {
            uVar7 = 1;
            BIO_printf(bio_err,"bad exit\n");
            goto LAB_000132f6;
          }
          iVar11 = do_cmd(lh,local_474,local_470);
          if (iVar11 < 0) break;
          if (iVar11 != 0) {
            BIO_printf(bio_err,"error in %s\n",*local_470);
          }
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          pcVar3 = local_42c;
          pvVar6 = (void *)0x0;
          iVar11 = 0x400;
        }
        else {
          pvVar6 = (void *)(sVar9 - 2);
          pcVar3 = pcVar3 + (int)pvVar6;
          iVar11 = iVar11 - (int)pvVar6;
        }
      }
      uVar7 = 0;
    }
    else {
      uVar7 = do_cmd(lh,param_1 + -1,param_2 + 1);
      uVar7 = uVar7 & ~((int)uVar7 >> 0x1f);
    }
  }
  else {
    *param_2 = (int)auStack_454;
    uVar7 = (**(code **)((int)pvVar6 + 8))(param_1,param_2);
  }
LAB_000132f6:
  if (pcVar2 != (char *)0x0) {
    CRYPTO_free(pcVar2);
  }
  if (config != (CONF *)0x0) {
    NCONF_free(config);
    config = (CONF *)0x0;
  }
  if (lh != (_LHASH *)0x0) {
    lh_free(lh);
  }
  if (local_468 != (void *)0x0) {
    CRYPTO_free(local_468);
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
  exit(uVar7);
}

