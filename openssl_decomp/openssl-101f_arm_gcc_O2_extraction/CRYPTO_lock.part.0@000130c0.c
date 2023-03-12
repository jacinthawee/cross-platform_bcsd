
void CRYPTO_lock_part_0(void)

{
  int *piVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  CONF *pCVar5;
  ulong uVar6;
  _LHASH *lh;
  void *pvVar7;
  uint uVar8;
  BIO_METHOD *type;
  size_t sVar9;
  char *pcVar10;
  int *extraout_r1;
  undefined *__nmemb;
  undefined4 *puVar11;
  int iVar12;
  char *pcStack_484;
  undefined4 uStack_47c;
  undefined4 *puStack_478;
  long lStack_474;
  void *pvStack_470;
  undefined4 uStack_46c;
  undefined auStack_468 [4];
  undefined *puStack_464;
  undefined auStack_45c [40];
  char acStack_434 [1024];
  undefined4 uStack_34;
  
  pcVar2 = "cryptlib.c";
  OpenSSLDie("cryptlib.c",0x253,"pointer != NULL");
  uStack_34 = __TMC_END__;
  pvStack_470 = (void *)0x0;
  uStack_46c = 0;
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  pcVar3 = getenv("OPENSSL_DEBUG_MEMORY");
  if (pcVar3 != (char *)0x0) {
    pcVar3 = getenv("OPENSSL_DEBUG_MEMORY");
    if ((((*pcVar3 == 'o') && (pcVar3[1] == 'f')) && (pcVar3[2] == 'f')) && (pcVar3[3] == '\0')) {
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
  pcVar3 = getenv("OPENSSL_FIPS");
  if (pcVar3 != (char *)0x0) {
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
  if ((pcVar4 == (char *)0x0) &&
     (pcVar10 = getenv("SSLEAY_CONF"), pcVar3 = pcVar4, pcVar4 = pcVar10, pcVar10 == (char *)0x0)) {
    pcVar3 = (char *)make_config_name();
    pcVar4 = pcVar3;
  }
  default_config_file = pcVar4;
  config = NCONF_new((CONF_METHOD *)0x0);
  pCVar5 = (CONF *)NCONF_load(config,pcVar4,&lStack_474);
  if (pCVar5 == (CONF *)0x0) {
    uVar6 = ERR_peek_last_error();
    if ((uVar6 & 0xfff) != 0x72) {
      ERR_print_errors(bio_err);
      NCONF_free(config);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    BIO_printf(bio_err,"WARNING: can\'t open config file: %s\n",pcVar4);
    ERR_clear_error();
    NCONF_free(config);
    config = pCVar5;
  }
  __nmemb = PTR_s_verify_0018a20c;
  if (PTR_s_verify_0018a20c != (undefined *)0x0) {
    __nmemb = (undefined *)0x0;
    puVar11 = &functions;
    do {
      piVar1 = puVar11 + 4;
      __nmemb = __nmemb + 1;
      puVar11 = puVar11 + 3;
    } while (*piVar1 != 0);
  }
  puVar11 = &functions;
  qsort(&functions,(size_t)__nmemb,0xc,SortFnByName + 1);
  lh = lh_new(function_LHASH_HASH + 1,function_LHASH_COMP + 1);
  if (lh != (_LHASH *)0x0) {
    for (; puVar11[1] != 0; puVar11 = puVar11 + 3) {
      lh_insert(lh,puVar11);
    }
  }
  program_name(*extraout_r1,auStack_45c,0x28);
  puStack_464 = auStack_45c;
  pvVar7 = lh_retrieve(lh,auStack_468);
  if (pvVar7 == (void *)0x0) {
    if (pcVar2 == (char *)0x1) {
      pcVar2 = acStack_434;
      iVar12 = 0x400;
      pcStack_484 = ">";
      while( true ) {
        pcVar4 = pcStack_484;
        if (pvVar7 == (void *)0x0) {
          pcVar4 = "OpenSSL> ";
        }
        *pcVar2 = '\0';
        fputs(pcVar4,stdout);
        fflush(stdout);
        pcVar4 = fgets(pcVar2,iVar12,stdin);
        if ((pcVar4 == (char *)0x0) || (*pcVar2 == '\0')) break;
        sVar9 = strlen(pcVar2);
        if (((int)sVar9 < 2) || (pcVar2[sVar9 - 2] != '\\')) {
          iVar12 = chopup_args(&pvStack_470,acStack_434,&uStack_47c,&puStack_478);
          if (iVar12 == 0) {
            uVar8 = 1;
            BIO_printf(bio_err,"bad exit\n");
            goto LAB_000132f6;
          }
          iVar12 = do_cmd(lh,uStack_47c,puStack_478);
          if (iVar12 < 0) break;
          if (iVar12 != 0) {
            BIO_printf(bio_err,"error in %s\n",*puStack_478);
          }
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          pcVar2 = acStack_434;
          pvVar7 = (void *)0x0;
          iVar12 = 0x400;
        }
        else {
          pvVar7 = (void *)(sVar9 - 2);
          pcVar2 = pcVar2 + (int)pvVar7;
          iVar12 = iVar12 - (int)pvVar7;
        }
      }
      uVar8 = 0;
    }
    else {
      uVar8 = do_cmd(lh,pcVar2 + -1,extraout_r1 + 1);
      uVar8 = uVar8 & ~((int)uVar8 >> 0x1f);
    }
  }
  else {
    *extraout_r1 = (int)auStack_45c;
    uVar8 = (**(code **)((int)pvVar7 + 8))(pcVar2,extraout_r1);
  }
LAB_000132f6:
  if (pcVar3 != (char *)0x0) {
    CRYPTO_free(pcVar3);
  }
  if (config != (CONF *)0x0) {
    NCONF_free(config);
    config = (CONF *)0x0;
  }
  if (lh != (_LHASH *)0x0) {
    lh_free(lh);
  }
  if (pvStack_470 != (void *)0x0) {
    CRYPTO_free(pvStack_470);
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
  exit(uVar8);
}

