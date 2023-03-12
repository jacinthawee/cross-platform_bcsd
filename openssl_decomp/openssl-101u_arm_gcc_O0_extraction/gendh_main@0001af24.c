
undefined4 gendh_main(int param_1,int param_2)

{
  BIO *bio;
  int iVar1;
  BIO_METHOD *pBVar2;
  BIO *bp;
  long lVar3;
  int iVar4;
  undefined4 uVar5;
  DH *dh;
  char **ppcVar6;
  char *__s1;
  char *__s;
  char *pcVar7;
  char *pcVar8;
  int local_38;
  BN_GENCB local_34;
  
  local_38 = 0x800;
  signal(0xd,(__sighandler_t)0x1);
  local_34.ver = 2;
  local_34.arg = bio_err;
  local_34.cb.cb_1 = dh_cb + 1;
  if (bio_err == (BIO *)0x0) {
    pBVar2 = BIO_s_file();
    bio_err = BIO_new(pBVar2);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar1 = load_config(bio_err,0);
  if (iVar1 == 0) {
LAB_0001b186:
    ERR_print_errors(bio_err);
    return 1;
  }
  param_1 = param_1 + -1;
  pcVar7 = (char *)0x0;
  ppcVar6 = (char **)(param_2 + 4);
  iVar1 = 2;
  pcVar8 = (char *)0x0;
  __s = (char *)0x0;
  if (0 < param_1) {
LAB_0001b070:
    __s1 = *ppcVar6;
    iVar4 = strcmp(__s1,"-out");
    if (iVar4 == 0) {
      param_1 = param_1 + -1;
      if (param_1 != 0) {
        __s = ppcVar6[1];
        ppcVar6 = ppcVar6 + 1;
        goto LAB_0001b068;
      }
    }
    else {
      if (*__s1 == '-') {
        if (__s1[1] == '2') {
          if (__s1[2] != '\0') goto LAB_0001b08a;
          iVar1 = 2;
        }
        else {
          if ((__s1[1] != '5') || (__s1[2] != '\0')) goto LAB_0001b08a;
          iVar1 = 5;
        }
LAB_0001b068:
        param_1 = param_1 + -1;
        ppcVar6 = ppcVar6 + 1;
        if (param_1 < 1) goto LAB_0001af82;
        goto LAB_0001b070;
      }
LAB_0001b08a:
      iVar4 = strcmp(__s1,"-engine");
      if (iVar4 == 0) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          pcVar7 = ppcVar6[1];
          ppcVar6 = ppcVar6 + 1;
          goto LAB_0001b068;
        }
      }
      else {
        iVar4 = strcmp(__s1,"-rand");
        if (iVar4 != 0) {
          iVar4 = __isoc99_sscanf(__s1,"%d",&local_38);
          if ((iVar4 == 0) || (local_38 < 0)) goto LAB_0001b102;
          goto LAB_0001af82;
        }
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          pcVar8 = ppcVar6[1];
          ppcVar6 = ppcVar6 + 1;
          goto LAB_0001b068;
        }
      }
    }
LAB_0001b102:
    BIO_printf(bio_err,"usage: gendh [args] [numbits]\n");
    BIO_printf(bio_err," -out file - output the key to \'file\n");
    BIO_printf(bio_err," -2        - use 2 as the generator value\n");
    BIO_printf(bio_err," -5        - use 5 as the generator value\n");
    BIO_printf(bio_err," -engine e - use engine e, possibly a hardware device.\n");
    BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
    BIO_printf(bio_err,"           - load the file (or the files in the directory) into\n");
    BIO_printf(bio_err,"             the random number generator\n");
    goto LAB_0001b186;
  }
LAB_0001af82:
  setup_engine(bio_err,pcVar7,0);
  pBVar2 = BIO_s_file();
  bp = BIO_new(pBVar2);
  if (bp == (BIO *)0x0) {
    ERR_print_errors(bio_err);
    goto LAB_0001b186;
  }
  if (__s == (char *)0x0) {
    BIO_ctrl(bp,0x6a,0,stdout);
LAB_0001afbc:
    iVar4 = app_RAND_load_file(0,bio_err,1);
    bio = bio_err;
    if (iVar4 == 0) {
      if (pcVar8 == (char *)0x0) {
        BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n")
        ;
      }
      else {
LAB_0001afde:
        uVar5 = app_RAND_load_files(pcVar8);
        BIO_printf(bio,"%ld semi-random bytes loaded\n",uVar5);
      }
    }
    else if (pcVar8 != (char *)0x0) goto LAB_0001afde;
    BIO_printf(bio_err,"Generating DH parameters, %d bit long safe prime, generator %d\n",local_38,
               iVar1);
    BIO_printf(bio_err,"This is going to take a long time\n");
    dh = DH_new();
    if ((dh != (DH *)0x0) &&
       (iVar1 = DH_generate_parameters_ex(dh,local_38,iVar1,&local_34), iVar1 != 0)) {
      app_RAND_write_file(0,bio_err);
      iVar1 = PEM_write_bio_DHparams(bp,dh);
      if (iVar1 != 0) {
        uVar5 = 0;
        goto LAB_0001b046;
      }
    }
  }
  else {
    lVar3 = BIO_ctrl(bp,0x6c,5,__s);
    if (0 < lVar3) goto LAB_0001afbc;
    dh = (DH *)0x0;
    perror(__s);
  }
  uVar5 = 1;
  ERR_print_errors(bio_err);
LAB_0001b046:
  BIO_free_all(bp);
  if (dh == (DH *)0x0) {
    return uVar5;
  }
  DH_free(dh);
  return uVar5;
}

