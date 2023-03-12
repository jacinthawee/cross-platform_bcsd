
int pkeyparam_main(undefined4 param_1,int param_2)

{
  bool bVar1;
  BIO *x;
  int iVar2;
  BIO *bp;
  BIO *bp_00;
  char *pcVar3;
  char **ppcVar4;
  char *filename;
  char *pcVar5;
  char *filename_00;
  int iVar6;
  
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  x = (BIO *)load_config(bio_err,0);
  if (x == (BIO *)0x0) {
    iVar6 = 1;
    bp = x;
    bp_00 = x;
  }
  else {
    pcVar5 = (char *)0x0;
    ERR_load_crypto_strings();
    OPENSSL_add_all_algorithms_noconf();
    bVar1 = false;
    iVar6 = 0;
    filename_00 = (char *)0x0;
    filename = (char *)0x0;
    for (ppcVar4 = (char **)(param_2 + 4);
        (pcVar3 = *ppcVar4, pcVar3 != (char *)0x0 && (*pcVar3 == '-')); ppcVar4 = ppcVar4 + 1) {
      if ((pcVar3[1] == 'i') && ((pcVar3[2] == 'n' && (pcVar3[3] == '\0')))) {
        filename = ppcVar4[1];
        pcVar3 = filename;
joined_r0x0003a3be:
        if (pcVar3 == (char *)0x0) {
          BIO_printf(bio_err,"Usage pkeyparam [options]\n");
          BIO_printf(bio_err,"where options are\n");
          BIO_printf(bio_err,"-in file        input file\n");
          BIO_printf(bio_err,"-out file       output file\n");
          BIO_printf(bio_err,"-text           print parameters as text\n");
          BIO_printf(bio_err,"-noout          don\'t output encoded parameters\n");
          BIO_printf(bio_err,"-engine e       use engine e, possibly a hardware device.\n");
          return 1;
        }
        ppcVar4 = ppcVar4 + 1;
      }
      else {
        iVar2 = strcmp(pcVar3,"-out");
        if (iVar2 == 0) {
          filename_00 = ppcVar4[1];
          pcVar3 = filename_00;
          goto joined_r0x0003a3be;
        }
        iVar2 = strcmp(pcVar3,"-engine");
        if (iVar2 == 0) {
          pcVar5 = ppcVar4[1];
          pcVar3 = pcVar5;
          goto joined_r0x0003a3be;
        }
        iVar2 = strcmp(pcVar3,"-text");
        if (iVar2 == 0) {
          iVar6 = 1;
        }
        else {
          iVar2 = strcmp(pcVar3,"-noout");
          if (iVar2 == 0) {
            bVar1 = true;
          }
        }
      }
    }
    setup_engine(bio_err,pcVar5,0);
    if (filename == (char *)0x0) {
      bp = BIO_new_fp(stdin,0);
    }
    else {
      x = BIO_new_file(filename,"r");
      bp = x;
      if (x == (BIO *)0x0) {
        BIO_printf(bio_err,"Can\'t open input file %s\n",filename);
        iVar6 = 1;
        bp_00 = x;
        goto LAB_0003a3e2;
      }
    }
    if (filename_00 == (char *)0x0) {
      bp_00 = BIO_new_fp(stdout,0);
    }
    else {
      x = BIO_new_file(filename_00,"w");
      bp_00 = x;
      if (x == (BIO *)0x0) {
        BIO_printf(bio_err,"Can\'t open output file %s\n",filename_00);
        iVar6 = 1;
        goto LAB_0003a3e2;
      }
    }
    x = (BIO *)PEM_read_bio_Parameters(bp,(EVP_PKEY **)0x0);
    if (x == (BIO *)0x0) {
      iVar6 = 1;
      BIO_printf(bio_err,"Error reading parameters\n");
      ERR_print_errors(bio_err);
    }
    else {
      if (!bVar1) {
        PEM_write_bio_Parameters(bp_00,(EVP_PKEY *)x);
      }
      if (iVar6 != 0) {
        EVP_PKEY_print_params(bp_00,(EVP_PKEY *)x,0,(ASN1_PCTX *)0x0);
        iVar6 = 0;
      }
    }
  }
LAB_0003a3e2:
  EVP_PKEY_free((EVP_PKEY *)x);
  BIO_free_all(bp_00);
  BIO_free(bp);
  return iVar6;
}

