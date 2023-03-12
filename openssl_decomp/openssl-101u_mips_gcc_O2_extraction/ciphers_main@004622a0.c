
undefined4 ciphers_main(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  undefined *puVar6;
  undefined *puVar7;
  SSL_METHOD *pSVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  undefined4 uVar17;
  undefined1 *puVar18;
  char *pcVar19;
  char *pcVar20;
  char **ppcVar21;
  char *local_244;
  char *local_23c;
  undefined auStack_22c [512];
  int local_2c;
  
  puVar7 = PTR___stack_chk_guard_006a9ae8;
  puVar6 = PTR_bio_err_006a6e3c;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pSVar8 = (SSL_METHOD *)(*(code *)PTR_SSLv23_server_method_006a788c)();
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  if (*(int *)puVar6 == 0) {
    uVar17 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(undefined4 *)puVar6 = uVar17;
  }
  iVar9 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
  pcVar15 = (char *)0x0;
  iVar10 = load_config(*(undefined4 *)puVar6);
  if (iVar10 == 0) {
LAB_0046251c:
    uVar17 = 1;
  }
  else {
    param_1 = param_1 + -1;
    ppcVar21 = (char **)(param_2 + 4);
    if (param_1 < 1) {
      (*(code *)PTR_SSL_library_init_006a7898)();
      iVar10 = (*(code *)PTR_SSL_CTX_new_006a78a0)(pSVar8);
      if (iVar10 == 0) goto LAB_004624fc;
      iVar11 = (*(code *)PTR_SSL_new_006a77e0)(iVar10);
      if (iVar11 == 0) goto LAB_004626cc;
LAB_0046248c:
      iVar16 = 0;
      while (iVar12 = (*(code *)PTR_SSL_get_cipher_list_006a7c8c)(iVar11,iVar16), iVar12 != 0) {
        if (iVar16 != 0) {
          (*(code *)PTR_BIO_printf_006a6e38)(iVar9,":");
        }
        iVar16 = iVar16 + 1;
        (*(code *)PTR_BIO_printf_006a6e38)(iVar9,"%s",iVar12);
      }
      pcVar15 = "\n";
      (*(code *)PTR_BIO_printf_006a6e38)(iVar9,"\n",0);
LAB_00462664:
      uVar17 = 0;
      (*(code *)PTR_SSL_CTX_free_006a7890)(iVar10);
      (*(code *)PTR_SSL_free_006a7810)(iVar11);
    }
    else {
      local_23c = (char *)0x0;
      bVar5 = false;
      bVar4 = false;
      local_244 = "-tls1";
      do {
        pcVar20 = *ppcVar21;
        cVar3 = *pcVar20;
        if (cVar3 != '-') {
LAB_004623a8:
          pcVar15 = "-ssl3";
          iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar20);
          if (iVar10 == 0) {
            pSVar8 = SSLv3_client_method();
            goto LAB_0046241c;
          }
          pcVar15 = local_244;
          iVar10 = (*(code *)PTR_strcmp_006a9b18)(pcVar20);
          if (iVar10 == 0) {
            pSVar8 = (SSL_METHOD *)(*(code *)PTR_TLSv1_client_method_006a79cc)();
            goto LAB_0046241c;
          }
          pcVar15 = "-h";
          iVar10 = (*(code *)PTR_strncmp_006a9970)(pcVar20,&DAT_006412e0,2);
          if ((iVar10 != 0) &&
             (((local_23c = pcVar20, cVar3 != '-' || (pcVar20[1] != '?')) || (pcVar20[2] != '\0'))))
          goto LAB_0046241c;
          if (ciphers_usage._0_4_ != 0) {
            puVar18 = ciphers_usage;
            do {
              puVar18 = (undefined1 *)((int)puVar18 + 4);
              pcVar15 = "%s";
              (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar6);
            } while (*(int *)puVar18 != 0);
            uVar17 = 1;
            goto LAB_00462520;
          }
          goto LAB_0046251c;
        }
        if (pcVar20[1] == 'v') {
          if (pcVar20[2] != '\0') goto LAB_004623a8;
          bVar4 = true;
        }
        else {
          if ((pcVar20[1] != 'V') || (pcVar20[2] != '\0')) goto LAB_004623a8;
          bVar4 = true;
          bVar5 = true;
        }
LAB_0046241c:
        param_1 = param_1 + -1;
        ppcVar21 = ppcVar21 + 1;
      } while (param_1 != 0);
      (*(code *)PTR_SSL_library_init_006a7898)();
      iVar10 = (*(code *)PTR_SSL_CTX_new_006a78a0)(pSVar8);
      if (iVar10 == 0) {
LAB_004624fc:
        (*(code *)PTR_SSL_load_error_strings_006a7588)();
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar6);
        goto LAB_0046251c;
      }
      if ((local_23c == (char *)0x0) ||
         (iVar11 = (*(code *)PTR_SSL_CTX_set_cipher_list_006a78d4)(iVar10), pcVar15 = local_23c,
         iVar11 != 0)) {
        iVar11 = (*(code *)PTR_SSL_new_006a77e0)(iVar10);
        if (iVar11 != 0) {
          if (!bVar4) goto LAB_0046248c;
          uVar17 = (*(code *)PTR_SSL_get_ciphers_006a7860)(iVar11);
          for (iVar16 = 0; iVar12 = (*(code *)PTR_sk_num_006a6e2c)(uVar17), iVar16 < iVar12;
              iVar16 = iVar16 + 1) {
            uVar13 = (*(code *)PTR_sk_value_006a6e24)(uVar17,iVar16);
            if (bVar5) {
              uVar14 = (*(code *)PTR_SSL_CIPHER_get_id_006a7c94)(uVar13);
              uVar1 = (uVar14 << 8) >> 0x18;
              uVar2 = (uVar14 << 0x10) >> 0x18;
              if ((uVar14 & 0xff000000) == 0x2000000) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (iVar9,"     0x%02X,0x%02X,0x%02X - ",uVar1,uVar2,uVar14 & 0xff);
              }
              else if ((uVar14 & 0xff000000) == 0x3000000) {
                (*(code *)PTR_BIO_printf_006a6e38)(iVar9,"          0x%02X,0x%02X - ",uVar2);
              }
              else {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (iVar9,"0x%02X,0x%02X,0x%02X,0x%02X - ",uVar14 >> 0x18,uVar1,uVar2,
                           uVar14 & 0xff);
              }
            }
            pcVar15 = (char *)(*(code *)PTR_SSL_CIPHER_description_006a7c90)
                                        (uVar13,auStack_22c,0x200);
            (*(code *)PTR_BIO_puts_006a6f58)(iVar9);
          }
          goto LAB_00462664;
        }
      }
      else {
        pcVar15 = "Error in cipher list\n";
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar6);
      }
LAB_004626cc:
      (*(code *)PTR_SSL_load_error_strings_006a7588)();
      uVar17 = 1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar6);
      (*(code *)PTR_SSL_CTX_free_006a7890)(iVar10);
    }
  }
LAB_00462520:
  if (iVar9 != 0) {
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar9);
  }
  if (local_2c == *(int *)puVar7) {
    return uVar17;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar6 = PTR_bio_err_006a6e3c;
  if (*(int *)PTR_bio_err_006a6e3c == 0) {
    uVar17 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *(undefined4 *)puVar6 = uVar17;
  }
  ppcVar21 = (char **)(pcVar15 + 4);
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  bVar4 = false;
  pcVar20 = (char *)0x0;
  pcVar19 = (char *)0x0;
  pcVar15 = *ppcVar21;
  while ((pcVar15 != (char *)0x0 && (*pcVar15 == '-'))) {
    iVar9 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,"-toseq");
    if (iVar9 == 0) {
      bVar4 = true;
    }
    else {
      if (((pcVar15[1] == 'i') && (pcVar15[2] == 'n')) && (pcVar15[3] == '\0')) {
        pcVar19 = ppcVar21[1];
        pcVar15 = pcVar19;
      }
      else {
        iVar9 = (*(code *)PTR_strcmp_006a9b18)(pcVar15,&DAT_00632514);
        if (iVar9 != 0) goto LAB_00462ab4;
        pcVar20 = ppcVar21[1];
        pcVar15 = pcVar20;
      }
      if (pcVar15 == (char *)0x0) {
LAB_00462ab4:
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar6,"Netscape certificate sequence utility\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar6,"Usage nseq [options]\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar6,"where options are\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar6,"-in file  input file\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar6,"-out file output file\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar6,"-toseq    output NS Sequence file\n");
        return 1;
      }
      ppcVar21 = ppcVar21 + 1;
    }
    ppcVar21 = ppcVar21 + 1;
    pcVar15 = *ppcVar21;
  }
  if (pcVar19 == (char *)0x0) {
    iVar9 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdin_006a9a14,0);
    if (pcVar20 != (char *)0x0) goto LAB_0046297c;
LAB_00462c60:
    iVar10 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stdout_006a99c8,0);
    if (!bVar4) goto LAB_004629a4;
LAB_00462b7c:
    iVar11 = (*(code *)PTR_NETSCAPE_CERT_SEQUENCE_new_006a7c98)();
    uVar17 = (*(code *)PTR_sk_new_null_006a6fa4)();
    *(undefined4 *)(iVar11 + 4) = uVar17;
    while (iVar16 = (*(code *)PTR_PEM_read_bio_X509_006a6fcc)(iVar9,0,0,0), iVar16 != 0) {
      (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)(iVar11 + 4),iVar16);
    }
    iVar16 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar11 + 4));
    if (iVar16 != 0) {
      uVar17 = 0;
      (*(code *)PTR_PEM_write_bio_NETSCAPE_CERT_SEQUENCE_006a7ca4)(iVar10,iVar11);
      goto LAB_00462a30;
    }
    uVar17 = *(undefined4 *)puVar6;
    pcVar15 = "Error reading certs file %s\n";
  }
  else {
    iVar9 = (*(code *)PTR_BIO_new_file_006a6eac)(pcVar19,"r");
    if (iVar9 == 0) {
      uVar17 = 1;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar6,"Can\'t open input file %s\n",pcVar19);
      iVar11 = 0;
      iVar10 = 0;
      goto LAB_00462a30;
    }
    if (pcVar20 == (char *)0x0) goto LAB_00462c60;
LAB_0046297c:
    iVar10 = (*(code *)PTR_BIO_new_file_006a6eac)(pcVar20,"w");
    if (iVar10 == 0) {
      uVar17 = 1;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar6,"Can\'t open output file %s\n",pcVar20);
      iVar11 = 0;
      goto LAB_00462a30;
    }
    if (bVar4) goto LAB_00462b7c;
LAB_004629a4:
    iVar11 = (*(code *)PTR_PEM_read_bio_NETSCAPE_CERT_SEQUENCE_006a7c9c)(iVar9,0,0,0);
    if (iVar11 != 0) {
      iVar16 = 0;
      while( true ) {
        iVar12 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(iVar11 + 4));
        if (iVar12 <= iVar16) break;
        uVar17 = (*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(iVar11 + 4),iVar16);
        dump_cert_text(iVar10,uVar17);
        (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar10,uVar17);
        iVar16 = iVar16 + 1;
      }
      uVar17 = 0;
      goto LAB_00462a30;
    }
    uVar17 = *(undefined4 *)puVar6;
    pcVar15 = "Error reading sequence file %s\n";
  }
  (*(code *)PTR_BIO_printf_006a6e38)(uVar17,pcVar15,pcVar19);
  uVar17 = 1;
  (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar6);
LAB_00462a30:
  (*(code *)PTR_BIO_free_006a6e70)(iVar9);
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar10);
  (*(code *)PTR_NETSCAPE_CERT_SEQUENCE_free_006a7ca0)(iVar11);
  return uVar17;
}

