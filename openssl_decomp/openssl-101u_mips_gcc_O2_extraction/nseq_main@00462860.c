
undefined4 nseq_main(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char **ppcVar12;
  
  puVar2 = PTR_bio_err_006a6e3c;
  if (*(int *)PTR_bio_err_006a6e3c == 0) {
    uVar8 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(undefined4 *)puVar2 = uVar8;
  }
  ppcVar12 = (char **)(param_2 + 4);
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  bVar1 = false;
  pcVar11 = (char *)0x0;
  pcVar9 = (char *)0x0;
  pcVar10 = *ppcVar12;
  while ((pcVar10 != (char *)0x0 && (*pcVar10 == '-'))) {
    iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"-toseq");
    if (iVar3 == 0) {
      bVar1 = true;
    }
    else {
      if (((pcVar10[1] == 'i') && (pcVar10[2] == 'n')) && (pcVar10[3] == '\0')) {
        pcVar9 = ppcVar12[1];
        pcVar10 = pcVar9;
      }
      else {
        iVar3 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,&DAT_00632514);
        if (iVar3 != 0) goto LAB_00462ab4;
        pcVar11 = ppcVar12[1];
        pcVar10 = pcVar11;
      }
      if (pcVar10 == (char *)0x0) {
LAB_00462ab4:
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar2,"Netscape certificate sequence utility\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Usage nseq [options]\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"where options are\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"-in file  input file\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"-out file output file\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar2,"-toseq    output NS Sequence file\n");
        return 1;
      }
      ppcVar12 = ppcVar12 + 1;
    }
    ppcVar12 = ppcVar12 + 1;
    pcVar10 = *ppcVar12;
  }
  if (pcVar9 == (char *)0x0) {
    iVar3 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14,0);
    if (pcVar11 != (char *)0x0) goto LAB_0046297c;
LAB_00462c60:
    iVar4 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
    if (!bVar1) goto LAB_004629a4;
LAB_00462b7c:
    iVar5 = (*(code *)PTR_NETSCAPE_CERT_SEQUENCE_new_006a7c98)();
    uVar8 = (*(code *)PTR_sk_new_null_006a6fa4)();
    *(undefined4 *)(iVar5 + 4) = uVar8;
    while (iVar7 = (*(code *)PTR_PEM_read_bio_X509_006a6fcc)(iVar3,0,0,0), iVar7 != 0) {
      (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)(iVar5 + 4),iVar7);
    }
    iVar7 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar5 + 4));
    if (iVar7 != 0) {
      uVar8 = 0;
      (*(code *)PTR_PEM_write_bio_NETSCAPE_CERT_SEQUENCE_006a7ca4)(iVar4,iVar5);
      goto LAB_00462a30;
    }
    uVar8 = *(undefined4 *)puVar2;
    pcVar10 = "Error reading certs file %s\n";
  }
  else {
    iVar3 = (*(code *)PTR_BIO_new_file_006a6eac)(pcVar9,"r");
    if (iVar3 == 0) {
      uVar8 = 1;
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"Can\'t open input file %s\n",pcVar9)
      ;
      iVar5 = 0;
      iVar4 = 0;
      goto LAB_00462a30;
    }
    if (pcVar11 == (char *)0x0) goto LAB_00462c60;
LAB_0046297c:
    iVar4 = (*(code *)PTR_BIO_new_file_006a6eac)(pcVar11,"w");
    if (iVar4 == 0) {
      uVar8 = 1;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar2,"Can\'t open output file %s\n",pcVar11);
      iVar5 = 0;
      goto LAB_00462a30;
    }
    if (bVar1) goto LAB_00462b7c;
LAB_004629a4:
    iVar5 = (*(code *)PTR_PEM_read_bio_NETSCAPE_CERT_SEQUENCE_006a7c9c)(iVar3,0,0,0);
    if (iVar5 != 0) {
      iVar7 = 0;
      while( true ) {
        iVar6 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar5 + 4));
        if (iVar6 <= iVar7) break;
        uVar8 = (*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(iVar5 + 4),iVar7);
        dump_cert_text(iVar4,uVar8);
        (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar4,uVar8);
        iVar7 = iVar7 + 1;
      }
      uVar8 = 0;
      goto LAB_00462a30;
    }
    uVar8 = *(undefined4 *)puVar2;
    pcVar10 = "Error reading sequence file %s\n";
  }
  (*(code *)PTR_BIO_printf_006a6e38)(uVar8,pcVar10,pcVar9);
  uVar8 = 1;
  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
LAB_00462a30:
  (*(code *)PTR_BIO_free_006a6e70)(iVar3);
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar4);
  (*(code *)PTR_NETSCAPE_CERT_SEQUENCE_free_006a7ca0)(iVar5);
  return uVar8;
}

