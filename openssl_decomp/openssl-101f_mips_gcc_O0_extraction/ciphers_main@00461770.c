
undefined4 ciphers_main(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  char *pcVar14;
  undefined1 *puVar15;
  undefined4 uVar16;
  int iVar17;
  char *pcVar18;
  char *pcVar19;
  char **ppcVar20;
  SSL_METHOD *local_24c;
  char *local_248;
  char *local_238;
  char *local_234;
  undefined auStack_22c [512];
  int local_2c;
  
  puVar7 = PTR___stack_chk_guard_006aabf0;
  puVar6 = PTR_bio_err_006a7f3c;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_24c = (SSL_METHOD *)(*(code *)PTR_SSLv23_server_method_006a8974)();
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  if (*(int *)puVar6 == 0) {
    uVar16 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(undefined4 *)puVar6 = uVar16;
  }
  iVar8 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
  pcVar14 = (char *)0x0;
  iVar9 = load_config(*(undefined4 *)puVar6);
  if (iVar9 == 0) {
LAB_00461a60:
    uVar16 = 1;
  }
  else {
    param_1 = param_1 + -1;
    ppcVar20 = (char **)(param_2 + 4);
    if (param_1 < 1) {
      (*(code *)PTR_SSL_library_init_006a8980)();
      iVar9 = (*(code *)PTR_SSL_CTX_new_006a8988)(local_24c);
      if (iVar9 != 0) {
        iVar10 = (*(code *)PTR_SSL_new_006a88cc)(iVar9);
        if (iVar10 == 0) goto LAB_00461a30;
LAB_00461980:
        iVar17 = 0;
        while (iVar11 = (*(code *)PTR_SSL_get_cipher_list_006a8d7c)(iVar10,iVar17), iVar11 != 0) {
          if (iVar17 != 0) {
            (*(code *)PTR_BIO_printf_006a7f38)(iVar8,":");
          }
          iVar17 = iVar17 + 1;
          (*(code *)PTR_BIO_printf_006a7f38)(iVar8,"%s",iVar11);
        }
        pcVar14 = "\n";
        (*(code *)PTR_BIO_printf_006a7f38)(iVar8,"\n",0);
LAB_00461bc0:
        uVar16 = 0;
        (*(code *)PTR_SSL_CTX_free_006a8978)(iVar9);
        (*(code *)PTR_SSL_free_006a88fc)(iVar10);
        goto LAB_00461a64;
      }
    }
    else {
      local_238 = (char *)0x0;
      bVar5 = false;
      bVar4 = false;
      local_248 = "-ssl3";
      local_234 = "-h";
      do {
        pcVar19 = *ppcVar20;
        cVar3 = *pcVar19;
        if (cVar3 != '-') {
LAB_00461884:
          pcVar14 = "-ssl2";
          iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar19);
          if (iVar9 == 0) {
            local_24c = SSLv2_client_method();
            goto LAB_00461910;
          }
          pcVar14 = local_248;
          iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar19);
          if (iVar9 == 0) {
            local_24c = (SSL_METHOD *)(*(code *)PTR_SSLv3_client_method_006a8acc)();
            goto LAB_00461910;
          }
          pcVar14 = "-tls1";
          iVar9 = (*(code *)PTR_strcmp_006aac20)(pcVar19);
          if (iVar9 == 0) {
            local_24c = (SSL_METHOD *)(*(code *)PTR_TLSv1_client_method_006a8ab8)();
            goto LAB_00461910;
          }
          pcVar14 = local_234;
          iVar9 = (*(code *)PTR_strncmp_006aaa7c)(pcVar19,&DAT_00641850,2);
          if ((iVar9 != 0) &&
             (((local_238 = pcVar19, cVar3 != '-' || (pcVar19[1] != '?')) || (pcVar19[2] != '\0'))))
          goto LAB_00461910;
          if (ciphers_usage._0_4_ != 0) {
            puVar15 = ciphers_usage;
            do {
              puVar15 = (undefined1 *)((int)puVar15 + 4);
              pcVar14 = "%s";
              (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6);
            } while (*(int *)puVar15 != 0);
            uVar16 = 1;
            goto LAB_00461a64;
          }
          goto LAB_00461a60;
        }
        if (pcVar19[1] == 'v') {
          if (pcVar19[2] != '\0') goto LAB_00461884;
          bVar4 = true;
        }
        else {
          if ((pcVar19[1] != 'V') || (pcVar19[2] != '\0')) goto LAB_00461884;
          bVar4 = true;
          bVar5 = true;
        }
LAB_00461910:
        param_1 = param_1 + -1;
        ppcVar20 = ppcVar20 + 1;
      } while (param_1 != 0);
      (*(code *)PTR_SSL_library_init_006a8980)();
      iVar9 = (*(code *)PTR_SSL_CTX_new_006a8988)(local_24c);
      if (iVar9 != 0) {
        if ((local_238 == (char *)0x0) ||
           (iVar10 = (*(code *)PTR_SSL_CTX_set_cipher_list_006a89bc)(iVar9), pcVar14 = local_238,
           iVar10 != 0)) {
          iVar10 = (*(code *)PTR_SSL_new_006a88cc)(iVar9);
          if (iVar10 != 0) {
            if (!bVar4) goto LAB_00461980;
            uVar16 = (*(code *)PTR_SSL_get_ciphers_006a894c)(iVar10);
            for (iVar17 = 0; iVar11 = (*(code *)PTR_sk_num_006a7f2c)(uVar16), iVar17 < iVar11;
                iVar17 = iVar17 + 1) {
              uVar12 = (*(code *)PTR_sk_value_006a7f24)(uVar16,iVar17);
              if (bVar5) {
                uVar13 = (*(code *)PTR_SSL_CIPHER_get_id_006a8d84)(uVar12);
                uVar1 = (uVar13 << 8) >> 0x18;
                uVar2 = (uVar13 << 0x10) >> 0x18;
                if ((uVar13 & 0xff000000) == 0x2000000) {
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (iVar8,"     0x%02X,0x%02X,0x%02X - ",uVar1,uVar2,uVar13 & 0xff);
                }
                else if ((uVar13 & 0xff000000) == 0x3000000) {
                  (*(code *)PTR_BIO_printf_006a7f38)(iVar8,"          0x%02X,0x%02X - ",uVar2);
                }
                else {
                  (*(code *)PTR_BIO_printf_006a7f38)
                            (iVar8,"0x%02X,0x%02X,0x%02X,0x%02X - ",uVar13 >> 0x18,uVar1,uVar2,
                             uVar13 & 0xff);
                }
              }
              pcVar14 = (char *)(*(code *)PTR_SSL_CIPHER_description_006a8d80)
                                          (uVar12,auStack_22c,0x200);
              (*(code *)PTR_BIO_puts_006a8058)(iVar8);
            }
            goto LAB_00461bc0;
          }
        }
        else {
          pcVar14 = "Error in cipher list\n";
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6);
        }
LAB_00461a30:
        (*(code *)PTR_SSL_load_error_strings_006a867c)();
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar6);
        (*(code *)PTR_SSL_CTX_free_006a8978)(iVar9);
        goto LAB_00461a60;
      }
    }
    uVar16 = 1;
    (*(code *)PTR_SSL_load_error_strings_006a867c)();
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar6);
  }
LAB_00461a64:
  if (iVar8 != 0) {
    (*(code *)PTR_BIO_free_all_006a7f74)(iVar8);
  }
  if (local_2c == *(int *)puVar7) {
    return uVar16;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar6 = PTR_bio_err_006a7f3c;
  if (*(int *)PTR_bio_err_006a7f3c == 0) {
    uVar16 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *(undefined4 *)puVar6 = uVar16;
  }
  ppcVar20 = (char **)(pcVar14 + 4);
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  bVar4 = false;
  pcVar19 = (char *)0x0;
  pcVar18 = (char *)0x0;
  pcVar14 = *ppcVar20;
  while ((pcVar14 != (char *)0x0 && (*pcVar14 == '-'))) {
    iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-toseq");
    if (iVar8 == 0) {
      bVar4 = true;
    }
    else {
      if (((pcVar14[1] == 'i') && (pcVar14[2] == 'n')) && (pcVar14[3] == '\0')) {
        pcVar18 = ppcVar20[1];
        pcVar14 = pcVar18;
      }
      else {
        iVar8 = (*(code *)PTR_strcmp_006aac20)(pcVar14,&DAT_00632edc);
        if (iVar8 != 0) goto LAB_00461fc4;
        pcVar19 = ppcVar20[1];
        pcVar14 = pcVar19;
      }
      if (pcVar14 == (char *)0x0) {
LAB_00461fc4:
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar6,"Netscape certificate sequence utility\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"Usage nseq [options]\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"where options are\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"-in file  input file\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar6,"-out file output file\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar6,"-toseq    output NS Sequence file\n");
        return 1;
      }
      ppcVar20 = ppcVar20 + 1;
    }
    ppcVar20 = ppcVar20 + 1;
    pcVar14 = *ppcVar20;
  }
  if (pcVar18 == (char *)0x0) {
    iVar8 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdin_006aab20,0);
    if (pcVar19 != (char *)0x0) goto LAB_00461e8c;
LAB_00462170:
    iVar9 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stdout_006aaad4,0);
    if (!bVar4) goto LAB_00461eb4;
LAB_0046208c:
    iVar10 = (*(code *)PTR_NETSCAPE_CERT_SEQUENCE_new_006a8d88)();
    uVar16 = (*(code *)PTR_sk_new_null_006a80a4)();
    *(undefined4 *)(iVar10 + 4) = uVar16;
    while (iVar17 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)(iVar8,0,0,0), iVar17 != 0) {
      (*(code *)PTR_sk_push_006a80a8)(*(undefined4 *)(iVar10 + 4),iVar17);
    }
    iVar17 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar10 + 4));
    if (iVar17 != 0) {
      uVar16 = 0;
      (*(code *)PTR_PEM_write_bio_NETSCAPE_CERT_SEQUENCE_006a8d94)(iVar9,iVar10);
      goto LAB_00461f40;
    }
    uVar16 = *(undefined4 *)puVar6;
    pcVar14 = "Error reading certs file %s\n";
  }
  else {
    iVar8 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar18,"r");
    if (iVar8 == 0) {
      uVar16 = 1;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar6,"Can\'t open input file %s\n",pcVar18);
      iVar10 = 0;
      iVar9 = 0;
      goto LAB_00461f40;
    }
    if (pcVar19 == (char *)0x0) goto LAB_00462170;
LAB_00461e8c:
    iVar9 = (*(code *)PTR_BIO_new_file_006a7fac)(pcVar19,"w");
    if (iVar9 == 0) {
      uVar16 = 1;
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar6,"Can\'t open output file %s\n",pcVar19);
      iVar10 = 0;
      goto LAB_00461f40;
    }
    if (bVar4) goto LAB_0046208c;
LAB_00461eb4:
    iVar10 = (*(code *)PTR_PEM_read_bio_NETSCAPE_CERT_SEQUENCE_006a8d8c)(iVar8,0,0,0);
    if (iVar10 != 0) {
      iVar17 = 0;
      while( true ) {
        iVar11 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(iVar10 + 4));
        if (iVar11 <= iVar17) break;
        uVar16 = (*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(iVar10 + 4),iVar17);
        dump_cert_text(iVar9,uVar16);
        (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar9,uVar16);
        iVar17 = iVar17 + 1;
      }
      uVar16 = 0;
      goto LAB_00461f40;
    }
    uVar16 = *(undefined4 *)puVar6;
    pcVar14 = "Error reading sequence file %s\n";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(uVar16,pcVar14,pcVar18);
  uVar16 = 1;
  (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar6);
LAB_00461f40:
  (*(code *)PTR_BIO_free_006a7f70)(iVar8);
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar9);
  (*(code *)PTR_NETSCAPE_CERT_SEQUENCE_free_006a8d90)(iVar10);
  return uVar16;
}

