
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
  
  puVar2 = PTR_bio_err_006a6e3c;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  if (*(int *)puVar2 == 0) {
    uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar15 = (*(code *)PTR_BIO_new_006a6ea4)(uVar4);
    *(int *)puVar2 = iVar15;
    if (iVar15 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar15,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
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
      pcVar14 = *ppcVar17;
      iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-inform");
      if (iVar5 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_004354ec;
        ppcVar13 = ppcVar17 + 1;
        iVar15 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar17[1]);
LAB_0043527c:
        param_1 = param_1 + -1;
        ppcVar17 = ppcVar13 + 1;
      }
      else {
        iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-outform");
        if (iVar5 != 0) {
          if ((((*pcVar14 == '-') && (pcVar14[1] == 'i')) && (pcVar14[2] == 'n')) &&
             (pcVar14[3] == '\0')) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_004354ec;
            local_44 = ppcVar17[1];
            ppcVar13 = ppcVar17 + 1;
          }
          else {
            iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-nocrl");
            if (iVar5 == 0) {
              bVar1 = true;
              ppcVar13 = ppcVar17;
            }
            else {
              iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,&DAT_00632514);
              if (iVar5 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_004354ec;
                local_34 = ppcVar17[1];
                ppcVar13 = ppcVar17 + 1;
              }
              else {
                iVar5 = (*(code *)PTR_strcmp_006a9b18)(pcVar14,"-certfile");
                if (iVar5 != 0) {
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar2,"unknown option %s\n",pcVar14);
LAB_004354ec:
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar2,"%s [options] <infile >outfile\n",uVar4);
                  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"where options are\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar2," -inform arg    input format - DER or PEM\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar2," -outform arg   output format - DER or PEM\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar2," -in arg        input file\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar2," -out arg       output file\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar2,
                             " -certfile arg  certificates file of chain to a trusted CA\n");
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar2,"                (can be used more than once)\n")
                  ;
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (*(undefined4 *)puVar2,
                             " -nocrl         no crl to load, just certs from \'-certfile\'\n");
                  return 1;
                }
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_004354ec;
                if ((local_40 == 0) &&
                   (local_40 = (*(code *)PTR_sk_new_null_006a6fa4)(), local_40 == 0)) {
                  return 1;
                }
                iVar5 = (*(code *)PTR_sk_push_006a6fa8)(local_40,ppcVar17[1]);
                ppcVar13 = ppcVar17 + 1;
                if (iVar5 == 0) {
                  (*(code *)PTR_sk_free_006a6e80)(local_40);
                  return 1;
                }
              }
            }
          }
          goto LAB_0043527c;
        }
        if (param_1 == 1) goto LAB_004354ec;
        ppcVar13 = ppcVar17 + 1;
        param_1 = param_1 + -2;
        ppcVar17 = ppcVar17 + 2;
        iVar16 = (*(code *)PTR_str2fmt_006a6e4c)(*ppcVar13);
      }
    } while (param_1 != 0);
  }
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar5 = (*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  if (iVar5 == 0) {
    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
    if (iVar6 == 0) {
      return 1;
    }
    iVar7 = 0;
    iVar15 = 0;
    uVar4 = 1;
  }
  else {
    if (iVar6 == 0) {
      local_44 = *(char **)puVar2;
      pcVar19 = (code *)PTR_ERR_print_errors_006a6e40;
LAB_00435934:
      uVar4 = 1;
      (*pcVar19)(local_44);
      iVar15 = 0;
      iVar7 = 0;
      goto LAB_004353a8;
    }
    if (bVar1) {
      iVar15 = 0;
    }
    else {
      if (local_44 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar5,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
      }
      else {
        iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar5,0x6c,3,local_44);
        pcVar19 = (code *)PTR_perror_006a9a80;
        if (iVar7 < 1) goto LAB_00435934;
      }
      if (iVar15 == 1) {
        iVar15 = (*(code *)PTR_d2i_X509_CRL_bio_006a75cc)(iVar5,0);
      }
      else {
        if (iVar15 != 3) {
          uVar4 = 1;
          iVar15 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar2,"bad input format specified for input crl\n");
          iVar7 = 0;
          goto LAB_004353a8;
        }
        iVar15 = (*(code *)PTR_PEM_read_bio_X509_CRL_006a75b8)(iVar5,0,0,0);
      }
      if (iVar15 == 0) {
        uVar4 = 1;
        iVar7 = 0;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"unable to load CRL\n");
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
        goto LAB_004353a8;
      }
    }
    iVar7 = (*(code *)PTR_PKCS7_new_006a75bc)();
    if ((iVar7 == 0) ||
       (puVar8 = (undefined4 *)(*(code *)PTR_PKCS7_SIGNED_new_006a75c0)(),
       puVar8 == (undefined4 *)0x0)) {
LAB_00435784:
      uVar4 = 1;
    }
    else {
      uVar4 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x16);
      *(undefined4 **)(iVar7 + 0x14) = puVar8;
      *(undefined4 *)(iVar7 + 0x10) = uVar4;
      iVar18 = puVar8[5];
      uVar4 = (*(code *)PTR_OBJ_nid2obj_006a7140)(0x15);
      puVar3 = PTR_ASN1_INTEGER_set_006a7164;
      uVar12 = *puVar8;
      *(undefined4 *)(iVar18 + 0x10) = uVar4;
      iVar18 = (*(code *)puVar3)(uVar12,1);
      if ((iVar18 == 0) || (iVar18 = (*(code *)PTR_sk_new_null_006a6fa4)(), iVar18 == 0))
      goto LAB_00435784;
      puVar8[3] = iVar18;
      if (iVar15 != 0) {
        (*(code *)PTR_sk_push_006a6fa8)(iVar18,iVar15);
      }
      iVar15 = (*(code *)PTR_sk_new_null_006a6fa4)();
      if (iVar15 == 0) {
LAB_004359c4:
        uVar4 = 1;
        iVar15 = 0;
      }
      else {
        puVar8[2] = iVar15;
        if (local_40 != 0) {
          local_44 = (char *)0x0;
          while (iVar18 = (*(code *)PTR_sk_num_006a6e2c)(local_40), (int)local_44 < iVar18) {
            uVar4 = (*(code *)PTR_sk_value_006a6e24)(local_40,local_44);
            uVar12 = (*(code *)PTR_BIO_s_file_006a6ea0)();
            iVar18 = (*(code *)PTR_BIO_new_006a6ea4)(uVar12);
            if (iVar18 == 0) {
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar2,"error opening the file, %s\n",uVar4);
LAB_0043599c:
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar2,"error loading certificates\n");
              (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
              goto LAB_004359c4;
            }
            iVar9 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar18,0x6c,3,uVar4);
            if (iVar9 < 1) {
              uVar12 = *(undefined4 *)puVar2;
              pcVar14 = "error opening the file, %s\n";
LAB_00435980:
              (*(code *)PTR_BIO_printf_006a6e38)(uVar12,pcVar14,uVar4);
              (*(code *)PTR_BIO_free_006a6e70)(iVar18);
              goto LAB_0043599c;
            }
            iVar9 = (*(code *)PTR_PEM_X509_INFO_read_bio_006a75c4)(iVar18,0,0,0);
            if (iVar9 == 0) {
              uVar12 = *(undefined4 *)puVar2;
              pcVar14 = "error reading the file, %s\n";
              goto LAB_00435980;
            }
            while (iVar11 = (*(code *)PTR_sk_num_006a6e2c)(iVar9), iVar11 != 0) {
              piVar10 = (int *)(*(code *)PTR_sk_shift_006a724c)(iVar9);
              if (*piVar10 != 0) {
                (*(code *)PTR_sk_push_006a6fa8)(iVar15,*piVar10);
                *piVar10 = 0;
              }
              (*(code *)PTR_X509_INFO_free_006a75c8)(piVar10);
            }
            local_44 = (char *)((int)local_44 + 1);
            (*(code *)PTR_BIO_free_006a6e70)(iVar18);
            (*(code *)PTR_sk_free_006a6e80)(iVar9);
          }
        }
        (*(code *)PTR_sk_free_006a6e80)(local_40);
        if (local_34 == (char *)0x0) {
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar6,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
        }
        else {
          iVar15 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar6,0x6c,5,local_34);
          if (iVar15 < 1) {
            uVar4 = 1;
            iVar15 = 0;
            (*(code *)PTR_perror_006a9a80)(local_34);
            goto LAB_004353a8;
          }
        }
        if (iVar16 == 1) {
          iVar15 = (*(code *)PTR_i2d_PKCS7_bio_006a75a8)(iVar6,iVar7);
        }
        else {
          if (iVar16 != 3) {
            uVar4 = 1;
            iVar15 = 0;
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*(undefined4 *)puVar2,"bad output format specified for outfile\n");
            goto LAB_004353a8;
          }
          iVar15 = (*(code *)PTR_PEM_write_bio_PKCS7_006a75b4)(iVar6,iVar7);
        }
        if (iVar15 == 0) {
          uVar4 = 1;
          iVar15 = 0;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar2,"unable to write pkcs7 object\n")
          ;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar2);
        }
        else {
          uVar4 = 0;
          iVar15 = 0;
        }
      }
    }
LAB_004353a8:
    (*(code *)PTR_BIO_free_006a6e70)(iVar5);
    if (iVar6 == 0) goto LAB_004353cc;
  }
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar6);
LAB_004353cc:
  if (iVar7 != 0) {
    (*(code *)PTR_PKCS7_free_006a723c)(iVar7);
  }
  if (iVar15 != 0) {
    (*(code *)PTR_X509_CRL_free_006a7060)(iVar15);
    return uVar4;
  }
  return uVar4;
}

