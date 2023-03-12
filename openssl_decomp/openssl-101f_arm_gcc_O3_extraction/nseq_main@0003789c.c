
X509 * nseq_main(undefined4 param_1,int param_2)

{
  int iVar1;
  BIO *x;
  _STACK *p_Var2;
  BIO *pBVar3;
  char *pcVar4;
  X509 *pXVar5;
  char **ppcVar6;
  NETSCAPE_CERT_SEQUENCE **x_00;
  char *filename;
  char *filename_00;
  BIO *pBVar7;
  
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  ppcVar6 = (char **)(param_2 + 4);
  ERR_load_crypto_strings();
  x_00 = (NETSCAPE_CERT_SEQUENCE **)0x0;
  filename_00 = (char *)0x0;
  filename = (char *)0x0;
  pcVar4 = *ppcVar6;
  while ((pcVar4 != (char *)0x0 && (*pcVar4 == '-'))) {
    iVar1 = strcmp(pcVar4,"-toseq");
    if (iVar1 == 0) {
      x_00 = (NETSCAPE_CERT_SEQUENCE **)0x1;
    }
    else {
      if (((pcVar4[1] == 'i') && (pcVar4[2] == 'n')) && (pcVar4[3] == '\0')) {
        filename = ppcVar6[1];
        pcVar4 = filename;
      }
      else {
        iVar1 = strcmp(pcVar4,"-out");
        if (iVar1 != 0) goto LAB_000379be;
        filename_00 = ppcVar6[1];
        pcVar4 = filename_00;
      }
      if (pcVar4 == (char *)0x0) {
LAB_000379be:
        BIO_printf(bio_err,"Netscape certificate sequence utility\n");
        BIO_printf(bio_err,"Usage nseq [options]\n");
        BIO_printf(bio_err,"where options are\n");
        BIO_printf(bio_err,"-in file  input file\n");
        BIO_printf(bio_err,"-out file output file\n");
        BIO_printf(bio_err,"-toseq    output NS Sequence file\n");
        return (X509 *)0x1;
      }
      ppcVar6 = ppcVar6 + 1;
    }
    ppcVar6 = ppcVar6 + 1;
    pcVar4 = *ppcVar6;
  }
  if (filename == (char *)0x0) {
    x = BIO_new_fp(stdin,0);
    pBVar7 = x;
    if (filename_00 != (char *)0x0) goto LAB_00037928;
LAB_00037a84:
    pBVar3 = BIO_new_fp(stdout,(int)filename_00);
    pBVar7 = x;
    if (x_00 != (NETSCAPE_CERT_SEQUENCE **)0x0) goto LAB_00037a18;
LAB_00037944:
    x = (BIO *)PEM_read_bio_NETSCAPE_CERT_SEQUENCE(pBVar7,x_00,(undefined1 *)x_00,x_00);
    if (x != (BIO *)0x0) {
      while( true ) {
        iVar1 = sk_num((_STACK *)x->callback);
        if (iVar1 <= (int)x_00) break;
        pXVar5 = (X509 *)sk_value((_STACK *)x->callback,(int)x_00);
        dump_cert_text(pBVar3,pXVar5);
        PEM_write_bio_X509(pBVar3,pXVar5);
        x_00 = (NETSCAPE_CERT_SEQUENCE **)((int)x_00 + 1);
      }
      pXVar5 = (X509 *)0x0;
      goto LAB_00037986;
    }
    pcVar4 = "Error reading sequence file %s\n";
  }
  else {
    x = BIO_new_file(filename,"r");
    pBVar7 = x;
    if (x == (BIO *)0x0) {
      BIO_printf(bio_err,"Can\'t open input file %s\n",filename);
      pXVar5 = (X509 *)0x1;
      pBVar3 = x;
      goto LAB_00037986;
    }
    if (filename_00 == (char *)0x0) goto LAB_00037a84;
LAB_00037928:
    x = BIO_new_file(filename_00,"w");
    pBVar3 = x;
    if (x == (BIO *)0x0) {
      BIO_printf(bio_err,"Can\'t open output file %s\n",filename_00);
      pXVar5 = (X509 *)0x1;
      goto LAB_00037986;
    }
    if (x_00 == (NETSCAPE_CERT_SEQUENCE **)0x0) goto LAB_00037944;
LAB_00037a18:
    x = (BIO *)NETSCAPE_CERT_SEQUENCE_new();
    p_Var2 = sk_new_null();
    x->callback = (_func_603 *)p_Var2;
    while( true ) {
      pXVar5 = PEM_read_bio_X509(pBVar7,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0);
      if (pXVar5 == (X509 *)0x0) break;
      sk_push((_STACK *)x->callback,pXVar5);
    }
    iVar1 = sk_num((_STACK *)x->callback);
    if (iVar1 != 0) {
      PEM_write_bio_NETSCAPE_CERT_SEQUENCE(pBVar3,(NETSCAPE_CERT_SEQUENCE *)x);
      goto LAB_00037986;
    }
    pcVar4 = "Error reading certs file %s\n";
  }
  pXVar5 = (X509 *)0x1;
  BIO_printf(bio_err,pcVar4,filename);
  ERR_print_errors(bio_err);
LAB_00037986:
  BIO_free(pBVar7);
  BIO_free_all(pBVar3);
  NETSCAPE_CERT_SEQUENCE_free((NETSCAPE_CERT_SEQUENCE *)x);
  return pXVar5;
}

