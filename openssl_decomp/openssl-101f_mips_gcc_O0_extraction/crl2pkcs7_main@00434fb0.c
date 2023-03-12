
undefined4 crl2pkcs7_main(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  undefined4 uVar12;
  char **ppcVar13;
  char *pcVar14;
  int iVar15;
  int iVar16;
  char **ppcVar17;
  int iVar18;
  code *pcVar19;
  char *local_44;
  int local_40;
  char *local_34;
  
  puVar2 = PTR_bio_err_006a7f3c;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  if (*(int *)puVar2 == 0) {
    uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar15 = (*(code *)PTR_BIO_new_006a7fa4)(uVar4);
    *(int *)puVar2 = iVar15;
    if (iVar15 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar15,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
    }
  }
  uVar4 = *param_2;
  param_1 = param_1 + -1;
  ppcVar17 = (char **)(param_2 + 1);
  bVar1 = false;
  local_40 = 0;
  iVar16 = 3;
  local_34 = (char *)0x0;
  iVar15 = 3;
  local_44 = (char *)0x0;
  if (0 < param_1) {
    do {
      while( true ) {
        pcVar14 = *ppcVar17;
        iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-inform");
        if (iVar5 != 0) break;
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_004352fc;
        ppcVar13 = ppcVar17 + 1;
        iVar15 = (*(code *)PTR_str2fmt_006a7f4c)(ppcVar17[1]);
LAB_0043508c:
        param_1 = param_1 + -1;
        ppcVar17 = ppcVar13 + 1;
        if (param_1 == 0) goto LAB_004350f8;
      }
      iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-outform");
      if (iVar5 != 0) {
        if ((((*pcVar14 == '-') && (pcVar14[1] == 'i')) && (pcVar14[2] == 'n')) &&
           (pcVar14[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_004352fc;
          local_44 = ppcVar17[1];
          ppcVar13 = ppcVar17 + 1;
        }
        else {
          iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-nocrl");
          if (iVar5 == 0) {
            bVar1 = true;
            ppcVar13 = ppcVar17;
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,&DAT_00632edc);
            if (iVar5 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_004352fc;
              local_34 = ppcVar17[1];
              ppcVar13 = ppcVar17 + 1;
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"-certfile");
              if (iVar5 != 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"unknown option %s\n",pcVar14);
LAB_004352fc:
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"%s [options] <infile >outfile\n",uVar4);
                (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"where options are\n");
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2," -inform arg    input format - DER or PEM\n");
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2," -outform arg   output format - DER or PEM\n");
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2," -in arg        input file\n");
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2," -out arg       output file\n");
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,
                           " -certfile arg  certificates file of chain to a trusted CA\n");
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,"                (can be used more than once)\n");
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)puVar2,
                           " -nocrl         no crl to load, just certs from \'-certfile\'\n");
                return 1;
              }
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_004352fc;
              if (local_40 == 0) {
                local_40 = (*(code *)PTR_sk_new_null_006a80a4)();
              }
              (*(code *)PTR_sk_push_006a80a8)(local_40,ppcVar17[1]);
              ppcVar13 = ppcVar17 + 1;
            }
          }
        }
        goto LAB_0043508c;
      }
      if (param_1 == 1) goto LAB_004352fc;
      ppcVar13 = ppcVar17 + 1;
      param_1 = param_1 + -2;
      ppcVar17 = ppcVar17 + 2;
      iVar16 = (*(code *)PTR_str2fmt_006a7f4c)(*ppcVar13);
    } while (param_1 != 0);
  }
LAB_004350f8:
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar5 = (*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  uVar4 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar6 = (*(code *)PTR_BIO_new_006a7fa4)(uVar4);
  if (iVar5 == 0) {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
    if (iVar6 == 0) {
      return 1;
    }
    iVar15 = 0;
    iVar7 = 0;
    uVar4 = 1;
  }
  else {
    if (iVar6 == 0) {
      local_44 = *(char **)puVar2;
      pcVar19 = (code *)PTR_ERR_print_errors_006a7f40;
LAB_004356fc:
      uVar4 = 1;
      (*pcVar19)(local_44);
      iVar7 = 0;
      iVar15 = 0;
      goto LAB_004351b8;
    }
    if (bVar1) {
      iVar7 = 0;
    }
    else {
      if (local_44 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a7f18)(iVar5,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
      }
      else {
        iVar7 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar5,0x6c,3,local_44);
        pcVar19 = (code *)PTR_perror_006aab88;
        if (iVar7 < 1) goto LAB_004356fc;
      }
      if (iVar15 == 1) {
        iVar7 = (*(code *)PTR_d2i_X509_CRL_bio_006a86c0)(iVar5,0);
      }
      else {
        if (iVar15 != 3) {
          uVar4 = 1;
          iVar7 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)puVar2,"bad input format specified for input crl\n");
          iVar15 = 0;
          goto LAB_004351b8;
        }
        iVar7 = (*(code *)PTR_PEM_read_bio_X509_CRL_006a86bc)(iVar5,0,0,0);
      }
      if (iVar7 == 0) {
        uVar4 = 1;
        iVar15 = 0;
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"unable to load CRL\n");
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
        goto LAB_004351b8;
      }
    }
    iVar15 = (*(code *)PTR_PKCS7_new_006a86ac)();
    if ((iVar15 == 0) ||
       (puVar8 = (undefined4 *)(*(code *)PTR_PKCS7_SIGNED_new_006a86b0)(),
       puVar8 == (undefined4 *)0x0)) {
LAB_00435554:
      uVar4 = 1;
    }
    else {
      uVar4 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x16);
      *(undefined4 **)(iVar15 + 0x14) = puVar8;
      *(undefined4 *)(iVar15 + 0x10) = uVar4;
      iVar18 = puVar8[5];
      uVar4 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x15);
      puVar3 = PTR_ASN1_INTEGER_set_006a8264;
      uVar12 = *puVar8;
      *(undefined4 *)(iVar18 + 0x10) = uVar4;
      iVar18 = (*(code *)puVar3)(uVar12,1);
      if ((iVar18 == 0) || (iVar18 = (*(code *)PTR_sk_new_null_006a80a4)(), iVar18 == 0))
      goto LAB_00435554;
      puVar8[3] = iVar18;
      if (iVar7 != 0) {
        (*(code *)PTR_sk_push_006a80a8)(iVar18,iVar7);
      }
      iVar7 = (*(code *)PTR_sk_new_null_006a80a4)();
      if (iVar7 == 0) {
LAB_004357e8:
        uVar4 = 1;
        iVar7 = 0;
      }
      else {
        puVar8[2] = iVar7;
        if (local_40 != 0) {
          local_44 = (char *)0x0;
          while (iVar18 = (*(code *)PTR_sk_num_006a7f2c)(local_40), (int)local_44 < iVar18) {
            uVar4 = (*(code *)PTR_sk_value_006a7f24)(local_40,local_44);
            uVar12 = (*(code *)PTR_BIO_s_file_006a7fa0)();
            iVar18 = (*(code *)PTR_BIO_new_006a7fa4)(uVar12);
            if (iVar18 == 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"error opening the file, %s\n",uVar4);
LAB_004357c0:
              (*(code *)PTR_BIO_printf_006a7f38)
                        (*(undefined4 *)puVar2,"error loading certificates\n");
              (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
              goto LAB_004357e8;
            }
            iVar9 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6c,3,uVar4);
            if (iVar9 < 1) {
              uVar12 = *(undefined4 *)puVar2;
              pcVar14 = "error opening the file, %s\n";
LAB_004357a4:
              (*(code *)PTR_BIO_printf_006a7f38)(uVar12,pcVar14,uVar4);
              (*(code *)PTR_BIO_free_006a7f70)(iVar18);
              goto LAB_004357c0;
            }
            iVar9 = (*(code *)PTR_PEM_X509_INFO_read_bio_006a86b4)(iVar18,0,0,0);
            if (iVar9 == 0) {
              uVar12 = *(undefined4 *)puVar2;
              pcVar14 = "error reading the file, %s\n";
              goto LAB_004357a4;
            }
            while (iVar11 = (*(code *)PTR_sk_num_006a7f2c)(iVar9), iVar11 != 0) {
              piVar10 = (int *)(*(code *)PTR_sk_shift_006a8360)(iVar9);
              if (*piVar10 != 0) {
                (*(code *)PTR_sk_push_006a80a8)(iVar7,*piVar10);
                *piVar10 = 0;
              }
              (*(code *)PTR_X509_INFO_free_006a86b8)(piVar10);
            }
            local_44 = (char *)((int)local_44 + 1);
            (*(code *)PTR_BIO_free_006a7f70)(iVar18);
            (*(code *)PTR_sk_free_006a7f80)(iVar9);
          }
        }
        (*(code *)PTR_sk_free_006a7f80)(local_40);
        if (local_34 == (char *)0x0) {
          (*(code *)PTR_BIO_ctrl_006a7f18)(iVar6,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
        }
        else {
          iVar7 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar6,0x6c,5,local_34);
          if (iVar7 < 1) {
            uVar4 = 1;
            iVar7 = 0;
            (*(code *)PTR_perror_006aab88)(local_34);
            goto LAB_004351b8;
          }
        }
        if (iVar16 == 1) {
          iVar16 = (*(code *)PTR_i2d_PKCS7_bio_006a869c)(iVar6,iVar15);
        }
        else {
          if (iVar16 != 3) {
            uVar4 = 1;
            iVar7 = 0;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)puVar2,"bad output format specified for outfile\n");
            goto LAB_004351b8;
          }
          iVar16 = (*(code *)PTR_PEM_write_bio_PKCS7_006a86a8)(iVar6,iVar15);
        }
        if (iVar16 == 0) {
          uVar4 = 1;
          iVar7 = 0;
          (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar2,"unable to write pkcs7 object\n")
          ;
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar2);
        }
        else {
          uVar4 = 0;
          iVar7 = 0;
        }
      }
    }
LAB_004351b8:
    (*(code *)PTR_BIO_free_006a7f70)(iVar5);
    if (iVar6 == 0) goto LAB_004351dc;
  }
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar6);
LAB_004351dc:
  if (iVar15 != 0) {
    (*(code *)PTR_PKCS7_free_006a8350)(iVar15);
  }
  if (iVar7 != 0) {
    (*(code *)PTR_X509_CRL_free_006a8160)(iVar7);
    return uVar4;
  }
  return uVar4;
}

