
undefined4 nseq_main(undefined4 param_1,int param_2)

{
  bool bVar1;
  BIO *bp;
  NETSCAPE_CERT_SEQUENCE *x;
  X509 *pXVar2;
  int iVar3;
  _STACK *p_Var4;
  int iVar5;
  char **ppcVar6;
  undefined4 uVar7;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  byte bVar11;
  char *pcVar12;
  char *local_28;
  char *local_24;
  BIO *local_20;
  
  bVar11 = 0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  ERR_load_crypto_strings();
  bVar1 = false;
  local_24 = (char *)0x0;
  local_28 = (char *)0x0;
  ppcVar6 = (char **)(param_2 + 4);
  pcVar12 = *ppcVar6;
  while ((pcVar12 != (char *)0x0 && (bVar10 = *pcVar12 == '-', bVar10))) {
    iVar5 = 7;
    pcVar8 = pcVar12;
    pcVar9 = "-toseq";
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar10 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
      pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
    } while (bVar10);
    if (bVar10) {
      bVar1 = true;
    }
    else {
      bVar10 = pcVar12[1] == 'i';
      if (((bVar10) && (bVar10 = pcVar12[2] == 'n', bVar10)) &&
         (bVar10 = pcVar12[3] == '\0', bVar10)) {
        local_28 = ppcVar6[1];
        pcVar12 = local_28;
      }
      else {
        iVar5 = 5;
        pcVar8 = "-out";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar10 = *pcVar12 == *pcVar8;
          pcVar12 = pcVar12 + (uint)bVar11 * -2 + 1;
          pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
        } while (bVar10);
        if (!bVar10) goto LAB_08080447;
        local_24 = ppcVar6[1];
        pcVar12 = local_24;
      }
      if (pcVar12 == (char *)0x0) {
LAB_08080447:
        BIO_printf(bio_err,"Netscape certificate sequence utility\n");
        BIO_printf(bio_err,"Usage nseq [options]\n");
        BIO_printf(bio_err,"where options are\n");
        BIO_printf(bio_err,"-in file  input file\n");
        BIO_printf(bio_err,"-out file output file\n");
        BIO_printf(bio_err,"-toseq    output NS Sequence file\n");
        return 1;
      }
      ppcVar6 = ppcVar6 + 1;
    }
    ppcVar6 = ppcVar6 + 1;
    pcVar12 = *ppcVar6;
  }
  if (local_28 == (char *)0x0) {
    local_20 = BIO_new_fp(stdin,0);
    if (local_24 != (char *)0x0) goto LAB_0808036a;
LAB_08080588:
    bp = BIO_new_fp(stdout,0);
  }
  else {
    local_20 = BIO_new_file(local_28,"r");
    if (local_20 == (BIO *)0x0) {
      uVar7 = 1;
      x = (NETSCAPE_CERT_SEQUENCE *)0x0;
      bp = (BIO *)0x0;
      BIO_printf(bio_err,"Can\'t open input file %s\n",local_28);
      goto LAB_080803ea;
    }
    if (local_24 == (char *)0x0) goto LAB_08080588;
LAB_0808036a:
    bp = BIO_new_file(local_24,"w");
    if (bp == (BIO *)0x0) {
      uVar7 = 1;
      x = (NETSCAPE_CERT_SEQUENCE *)0x0;
      BIO_printf(bio_err,"Can\'t open output file %s\n",local_24);
      goto LAB_080803ea;
    }
  }
  if (bVar1) {
    x = NETSCAPE_CERT_SEQUENCE_new();
    p_Var4 = sk_new_null();
    x->certs = (stack_st_X509 *)p_Var4;
    while (pXVar2 = PEM_read_bio_X509(local_20,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0),
          pXVar2 != (X509 *)0x0) {
      sk_push((_STACK *)x->certs,pXVar2);
    }
    iVar5 = sk_num((_STACK *)x->certs);
    if (iVar5 != 0) {
      uVar7 = 0;
      PEM_write_bio_NETSCAPE_CERT_SEQUENCE(bp,x);
      goto LAB_080803ea;
    }
    pcVar12 = "Error reading certs file %s\n";
  }
  else {
    x = PEM_read_bio_NETSCAPE_CERT_SEQUENCE
                  (local_20,(NETSCAPE_CERT_SEQUENCE **)0x0,(undefined1 *)0x0,(void *)0x0);
    if (x != (NETSCAPE_CERT_SEQUENCE *)0x0) {
      for (iVar5 = 0; iVar3 = sk_num((_STACK *)x->certs), iVar5 < iVar3; iVar5 = iVar5 + 1) {
        pXVar2 = (X509 *)sk_value((_STACK *)x->certs,iVar5);
        dump_cert_text(bp,pXVar2);
        PEM_write_bio_X509(bp,pXVar2);
      }
      uVar7 = 0;
      goto LAB_080803ea;
    }
    pcVar12 = "Error reading sequence file %s\n";
  }
  uVar7 = 1;
  BIO_printf(bio_err,pcVar12,local_28);
  ERR_print_errors(bio_err);
LAB_080803ea:
  BIO_free(local_20);
  BIO_free_all(bp);
  NETSCAPE_CERT_SEQUENCE_free(x);
  return uVar7;
}

