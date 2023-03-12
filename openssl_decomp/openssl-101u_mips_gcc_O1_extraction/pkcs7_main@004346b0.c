
undefined4 pkcs7_main(int param_1,undefined4 *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char **ppcVar13;
  char *pcVar14;
  int iVar15;
  int iVar16;
  char **ppcVar17;
  char *local_54;
  char *local_50;
  char *local_3c;
  
  puVar5 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar12 = *(int *)puVar5;
  if (iVar12 == 0) {
    uVar7 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar12 = (*(code *)PTR_BIO_new_006a6ea4)(uVar7);
    *(int *)puVar5 = iVar12;
    if (iVar12 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar12,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar12 = *(int *)puVar5;
    }
  }
  iVar12 = (*(code *)PTR_load_config_006a6e64)(iVar12,0);
  if (iVar12 == 0) {
    return 1;
  }
  uVar7 = *param_2;
  param_1 = param_1 + -1;
  ppcVar17 = (char **)(param_2 + 1);
  local_3c = (char *)0x0;
  bVar1 = false;
  iVar15 = 3;
  bVar3 = false;
  iVar12 = 3;
  bVar4 = false;
  bVar2 = false;
  local_50 = (char *)0x0;
  local_54 = (char *)0x0;
  if (0 < param_1) {
    do {
      while( true ) {
        pcVar14 = *ppcVar17;
        iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-inform");
        if (iVar8 != 0) break;
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_004349e0;
        ppcVar13 = ppcVar17 + 1;
        iVar12 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar17[1]);
LAB_004347b0:
        param_1 = param_1 + -1;
        ppcVar17 = ppcVar13 + 1;
        if (param_1 == 0) goto LAB_0043481c;
      }
      iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-outform");
      if (iVar8 != 0) {
        if ((((*pcVar14 == '-') && (pcVar14[1] == 'i')) && (pcVar14[2] == 'n')) &&
           (pcVar14[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_004349e0;
          local_54 = ppcVar17[1];
          ppcVar13 = ppcVar17 + 1;
        }
        else {
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,&DAT_00632514);
          if (iVar8 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_004349e0;
            local_50 = ppcVar17[1];
            ppcVar13 = ppcVar17 + 1;
          }
          else {
            iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-noout");
            ppcVar13 = ppcVar17;
            if (iVar8 == 0) {
              bVar3 = true;
            }
            else {
              iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-text");
              if (iVar8 == 0) {
                bVar4 = true;
              }
              else {
                iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-print");
                if (iVar8 == 0) {
                  bVar1 = true;
                }
                else {
                  iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-print_certs");
                  if (iVar8 == 0) {
                    bVar2 = true;
                  }
                  else {
                    iVar8 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-engine");
                    if (iVar8 != 0) {
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5,"unknown option %s\n",pcVar14);
LAB_004349e0:
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5,"%s [options] <infile >outfile\n",uVar7);
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5,"where options are\n");
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5," -inform arg   input format - DER or PEM\n")
                      ;
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5," -outform arg  output format - DER or PEM\n"
                                );
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5," -in arg       input file\n");
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5," -out arg      output file\n");
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5,
                                 " -print_certs  print any certs or crl in the input\n");
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5,
                                 " -text         print full details of certificates\n");
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5," -noout        don\'t output encoded data\n"
                                );
                      (*(code *)PTR_BIO_printf_006a6e38)
                                (*(undefined4 *)puVar5,
                                 " -engine e     use engine e, possibly a hardware device.\n");
                      return 1;
                    }
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_004349e0;
                    local_3c = ppcVar17[1];
                    ppcVar13 = ppcVar17 + 1;
                  }
                }
              }
            }
          }
        }
        goto LAB_004347b0;
      }
      if (param_1 == 1) goto LAB_004349e0;
      ppcVar13 = ppcVar17 + 1;
      param_1 = param_1 + -2;
      ppcVar17 = ppcVar17 + 2;
      iVar15 = (*(code *)PTR_str2fmt_006a6e4c)(*ppcVar13);
    } while (param_1 != 0);
  }
LAB_0043481c:
  puVar6 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar5,local_3c,0);
  uVar7 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar8 = (*(code *)PTR_BIO_new_006a6ea4)(uVar7);
  uVar7 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar9 = (*(code *)PTR_BIO_new_006a6ea4)(uVar7);
  if (iVar8 == 0) {
    uVar7 = 1;
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar6);
    goto LAB_004348f8;
  }
  if (iVar9 == 0) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar6);
LAB_004348e4:
    uVar7 = 1;
  }
  else {
    if (local_54 == (char *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar8,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
    }
    else {
      iVar10 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar8,0x6c,3,local_54);
      if (iVar10 < 1) {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar6,"unable to load input file\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar6);
        goto LAB_004348e4;
      }
    }
    if (iVar12 == 1) {
      iVar12 = (*(code *)PTR_d2i_PKCS7_bio_006a75a0)(iVar8,0);
    }
    else {
      if (iVar12 != 3) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar5,"bad input format specified for pkcs7 object\n");
        goto LAB_004348e4;
      }
      iVar12 = (*(code *)PTR_PEM_read_bio_PKCS7_006a75ac)(iVar8,0,0,0);
    }
    if (iVar12 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"unable to load PKCS7 object\n");
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar5);
      goto LAB_004348e4;
    }
    if (local_50 == (char *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar9,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
LAB_00434c88:
      if (bVar1) {
        (*(code *)PTR_PKCS7_print_ctx_006a75a4)(iVar9,iVar12,0,0);
      }
      if (bVar2) {
        iVar15 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)(iVar12 + 0x10));
        if ((iVar15 == 0x16) || (uVar7 = 0, iVar15 == 0x18)) {
          iVar15 = *(int *)(iVar12 + 0x14);
          if (iVar15 != 0) {
            iVar10 = *(int *)(iVar15 + 8);
            iVar15 = *(int *)(iVar15 + 0xc);
            if (iVar10 == 0) {
              if (iVar15 != 0) {
                if (!bVar3) goto LAB_00434d68;
LAB_00434ed0:
                for (iVar10 = 0; iVar16 = (*(code *)PTR_sk_num_006a6e2c)(iVar15), iVar10 < iVar16;
                    iVar10 = iVar10 + 1) {
                  uVar7 = (*(code *)PTR_sk_value_006a6e24)(iVar15,iVar10);
                  (*(code *)PTR_X509_CRL_print_006a75b0)(iVar9,uVar7);
                  (*(code *)PTR_BIO_puts_006a6f58)(iVar9,"\n");
                }
                uVar7 = 0;
                goto LAB_00434cd8;
              }
            }
            else if (bVar3) {
              iVar16 = 0;
              if (bVar4) {
                for (; iVar11 = (*(code *)PTR_sk_num_006a6e2c)(iVar10), iVar16 < iVar11;
                    iVar16 = iVar16 + 1) {
                  uVar7 = (*(code *)PTR_sk_value_006a6e24)(iVar10,iVar16);
                  (*(code *)PTR_X509_print_006a70c0)(iVar9,uVar7);
                  (*(code *)PTR_BIO_puts_006a6f58)(iVar9,"\n");
                }
              }
              else {
                for (; iVar11 = (*(code *)PTR_sk_num_006a6e2c)(iVar10), iVar16 < iVar11;
                    iVar16 = iVar16 + 1) {
                  uVar7 = (*(code *)PTR_sk_value_006a6e24)(iVar10,iVar16);
                  (*(code *)PTR_dump_cert_text_006a721c)(iVar9,uVar7);
                  (*(code *)PTR_BIO_puts_006a6f58)(iVar9,"\n");
                }
              }
              if (iVar15 != 0) goto LAB_00434ed0;
            }
            else {
              iVar16 = 0;
              if (bVar4) {
                while( true ) {
                  iVar11 = (*(code *)PTR_sk_num_006a6e2c)(iVar10);
                  if (iVar11 <= iVar16) break;
                  uVar7 = (*(code *)PTR_sk_value_006a6e24)(iVar10,iVar16);
                  (*(code *)PTR_X509_print_006a70c0)(iVar9,uVar7);
                  (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar9,uVar7);
                  (*(code *)PTR_BIO_puts_006a6f58)(iVar9,"\n");
                  iVar16 = iVar16 + 1;
                }
              }
              else {
                for (; iVar11 = (*(code *)PTR_sk_num_006a6e2c)(iVar10), iVar16 < iVar11;
                    iVar16 = iVar16 + 1) {
                  uVar7 = (*(code *)PTR_sk_value_006a6e24)(iVar10,iVar16);
                  (*(code *)PTR_dump_cert_text_006a721c)(iVar9,uVar7);
                  (*(code *)PTR_PEM_write_bio_X509_006a6f20)(iVar9,uVar7);
                  (*(code *)PTR_BIO_puts_006a6f58)(iVar9,"\n");
                }
              }
              if (iVar15 == 0) {
                uVar7 = 0;
                goto LAB_00434cd8;
              }
LAB_00434d68:
              iVar10 = 0;
              while( true ) {
                iVar16 = (*(code *)PTR_sk_num_006a6e2c)(iVar15);
                if (iVar16 <= iVar10) break;
                uVar7 = (*(code *)PTR_sk_value_006a6e24)(iVar15,iVar10);
                (*(code *)PTR_X509_CRL_print_006a75b0)(iVar9,uVar7);
                (*(code *)PTR_PEM_write_bio_X509_CRL_006a7114)(iVar9,uVar7);
                (*(code *)PTR_BIO_puts_006a6f58)(iVar9,"\n");
                iVar10 = iVar10 + 1;
              }
            }
          }
LAB_00434de8:
          uVar7 = 0;
        }
      }
      else {
        uVar7 = 0;
        if (!bVar3) {
          if (iVar15 == 1) {
            iVar15 = (*(code *)PTR_i2d_PKCS7_bio_006a75a8)(iVar9,iVar12);
          }
          else {
            if (iVar15 != 3) {
              uVar7 = 1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar5,"bad output format specified for outfile\n");
              goto LAB_00434cd8;
            }
            iVar15 = (*(code *)PTR_PEM_write_bio_PKCS7_006a75b4)(iVar9,iVar12);
          }
          if (iVar15 != 0) goto LAB_00434de8;
          uVar7 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar5,"unable to write pkcs7 object\n")
          ;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar5);
        }
      }
    }
    else {
      iVar10 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar9,0x6c,5,local_50);
      if (0 < iVar10) goto LAB_00434c88;
      uVar7 = 1;
      (*(code *)PTR_perror_006a9a80)(local_50);
    }
LAB_00434cd8:
    (*(code *)PTR_PKCS7_free_006a723c)(iVar12);
  }
  (*(code *)PTR_BIO_free_006a6e70)(iVar8);
LAB_004348f8:
  if (iVar9 != 0) {
    (*(code *)PTR_BIO_free_all_006a6e74)(iVar9);
    return uVar7;
  }
  return uVar7;
}

