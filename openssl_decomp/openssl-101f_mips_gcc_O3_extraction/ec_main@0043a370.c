
undefined4 * ec_main(int param_1,char **param_2)

{
  char **ppcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  undefined *puVar9;
  char *pcVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  char *pcVar14;
  char **ppcVar15;
  undefined4 *puVar16;
  int iVar17;
  int iVar18;
  undefined *unaff_s6;
  code *pcVar19;
  char *local_88;
  char *local_80;
  char *local_78;
  char *local_6c;
  char *local_64;
  undefined4 local_58;
  undefined4 local_48;
  int local_40;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar9 = PTR___stack_chk_guard_006aabf0;
  puVar16 = (undefined4 *)PTR_bio_err_006a7f3c;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar13 = *puVar16;
  if (iVar13 == 0) {
    uVar12 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar13 = (*(code *)PTR_BIO_new_006a7fa4)(uVar12);
    *puVar16 = iVar13;
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar13,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar13 = *puVar16;
    }
  }
  iVar13 = (*(code *)PTR_load_config_006a7f64)(iVar13,0);
  if (iVar13 != 0) {
    pcVar10 = *param_2;
    iVar13 = param_1 + -1;
    ppcVar15 = param_2 + 1;
    if (iVar13 < 1) {
      bVar3 = false;
      local_6c = (char *)0x0;
      iVar18 = 3;
      local_78 = (char *)0x0;
      iVar17 = 3;
      local_58 = 4;
      local_64 = (char *)0x0;
      local_80 = (char *)0x0;
      local_88 = (char *)0x0;
      bVar6 = false;
      bVar5 = false;
      bVar4 = false;
      local_48 = 1;
      bVar7 = false;
      bVar8 = false;
      bVar2 = false;
      local_40 = 0;
    }
    else {
      bVar4 = false;
      bVar3 = false;
      local_6c = (char *)0x0;
      local_48 = 1;
      local_78 = (char *)0x0;
      iVar18 = 3;
      local_64 = (char *)0x0;
      iVar17 = 3;
      local_58 = 4;
      local_80 = (char *)0x0;
      param_1 = 0x630000;
      local_88 = (char *)0x0;
      bVar7 = false;
      unaff_s6 = &DAT_00632edc;
      bVar8 = false;
      bVar2 = false;
      bVar6 = false;
      bVar5 = false;
      local_40 = 0;
LAB_0043a4cc:
      do {
        param_2 = (char **)*ppcVar15;
        iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-inform");
        if (iVar11 == 0) {
          iVar13 = iVar13 + -1;
          if (iVar13 != 0) {
            iVar17 = str2fmt(ppcVar15[1]);
            ppcVar15 = ppcVar15 + 1;
            goto LAB_0043a4c0;
          }
LAB_0043a714:
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"%s [options] <infile >outfile\n",pcVar10);
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"where options are\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16," -inform arg     input format - DER or PEM\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16," -outform arg    output format - DER or PEM\n");
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar16," -in arg         input file\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16," -passin arg     input file pass phrase source\n");
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar16," -out arg        output file\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16," -passout arg    output file pass phrase source\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16," -engine e       use engine e, possibly a hardware device.\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16,
                     " -des            encrypt PEM output, instead of \'des\' every other \n                 cipher supported by OpenSSL can be used\n"
                    );
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar16," -text           print the key\n");
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar16," -noout          don\'t print key out\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16," -param_out      print the elliptic curve parameters\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16," -conv_form arg  specifies the point conversion form \n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16,"                 possible values: compressed\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16,"                                  uncompressed (default)\n");
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"                                   hybrid\n")
          ;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16," -param_enc arg  specifies the way the ec parameters are encoded\n");
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"                 in the asn1 der encoding\n")
          ;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16,"                 possible values: named_curve (default)\n");
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*puVar16,"                                  explicit\n");
          goto LAB_0043a910;
        }
        iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-outform");
        if (iVar11 != 0) {
          if ((((*(char *)param_2 == '-') && (*(char *)((int)param_2 + 1) == 'i')) &&
              (*(char *)((int)param_2 + 2) == 'n')) && (*(char *)((int)param_2 + 3) == '\0')) {
            iVar13 = iVar13 + -1;
            param_2 = ppcVar15 + 1;
            if (iVar13 == 0) goto LAB_0043a714;
            local_88 = ppcVar15[1];
            ppcVar15 = param_2;
          }
          else {
            iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_00632edc);
            if (iVar11 == 0) {
              iVar13 = iVar13 + -1;
              param_2 = ppcVar15 + 1;
              if (iVar13 == 0) goto LAB_0043a714;
              local_80 = ppcVar15[1];
              ppcVar15 = param_2;
            }
            else {
              iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-passin");
              if (iVar11 == 0) {
                iVar13 = iVar13 + -1;
                param_2 = ppcVar15 + 1;
                if (iVar13 == 0) goto LAB_0043a714;
                local_78 = ppcVar15[1];
                ppcVar15 = param_2;
              }
              else {
                iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-passout");
                if (iVar11 == 0) {
                  iVar13 = iVar13 + -1;
                  param_2 = ppcVar15 + 1;
                  if (iVar13 == 0) goto LAB_0043a714;
                  local_6c = ppcVar15[1];
                  ppcVar15 = param_2;
                }
                else {
                  iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-engine");
                  if (iVar11 == 0) {
                    iVar13 = iVar13 + -1;
                    param_2 = ppcVar15 + 1;
                    if (iVar13 == 0) goto LAB_0043a714;
                    local_64 = ppcVar15[1];
                    ppcVar15 = param_2;
                  }
                  else {
                    iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-noout");
                    if (iVar11 == 0) {
                      bVar6 = true;
                    }
                    else {
                      iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-text");
                      if (iVar11 == 0) {
                        bVar5 = true;
                      }
                      else {
                        iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-conv_form");
                        if (iVar11 == 0) {
                          iVar13 = iVar13 + -1;
                          if (iVar13 == 0) goto LAB_0043a714;
                          pcVar14 = ppcVar15[1];
                          param_2 = ppcVar15 + 1;
                          iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"compressed");
                          ppcVar15 = param_2;
                          if (iVar11 == 0) {
                            bVar3 = true;
                            local_58 = 2;
                          }
                          else {
                            iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"uncompressed");
                            if (iVar11 == 0) {
                              bVar3 = true;
                              local_58 = 4;
                            }
                            else {
                              iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"hybrid");
                              if (iVar11 != 0) goto LAB_0043a714;
                              bVar3 = true;
                              local_58 = 6;
                            }
                          }
                        }
                        else {
                          iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-param_enc");
                          if (iVar11 == 0) {
                            iVar13 = iVar13 + -1;
                            if (iVar13 == 0) goto LAB_0043a714;
                            pcVar14 = ppcVar15[1];
                            param_2 = ppcVar15 + 1;
                            iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"named_curve");
                            ppcVar15 = param_2;
                            if (iVar11 == 0) {
                              bVar4 = true;
                              local_48 = 1;
                            }
                            else {
                              iVar11 = (*(code *)PTR_strcmp_006aac20)(pcVar14,"explicit");
                              if (iVar11 != 0) goto LAB_0043a714;
                              local_48 = 0;
                              bVar4 = true;
                            }
                          }
                          else {
                            iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-param_out");
                            if (iVar11 == 0) {
                              bVar7 = true;
                            }
                            else {
                              iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-pubin");
                              if (iVar11 == 0) {
                                bVar2 = true;
                              }
                              else {
                                iVar11 = (*(code *)PTR_strcmp_006aac20)(param_2,"-pubout");
                                if (iVar11 == 0) {
                                  bVar8 = true;
                                }
                                else {
                                  local_40 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)
                                                       ((char *)((int)param_2 + 1));
                                  if (local_40 == 0) {
                                    (*(code *)PTR_BIO_printf_006a7f38)
                                              (*puVar16,"unknown option %s\n",*ppcVar15);
                                    goto LAB_0043a714;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LAB_0043a4c0:
          iVar13 = iVar13 + -1;
          ppcVar15 = ppcVar15 + 1;
          if (iVar13 == 0) break;
          goto LAB_0043a4cc;
        }
        if (iVar13 == 1) goto LAB_0043a714;
        ppcVar1 = ppcVar15 + 1;
        iVar13 = iVar13 + -2;
        ppcVar15 = ppcVar15 + 2;
        iVar18 = str2fmt(*ppcVar1);
      } while (iVar13 != 0);
    }
    param_2 = (char **)PTR_bio_err_006a7f3c;
    (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
    (*(code *)PTR_setup_engine_006a7fc4)(*puVar16,local_64,0);
    iVar13 = app_passwd(*puVar16,local_78,local_6c,&local_34,&local_30);
    if (iVar13 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*param_2,"Error getting passwords\n");
    }
    else {
      uVar12 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      unaff_s6 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar12);
      uVar12 = (*(code *)PTR_BIO_s_file_006a7fa0)();
      param_1 = (*(code *)PTR_BIO_new_006a7fa4)(uVar12);
      if (unaff_s6 != (undefined *)0x0) {
        if (param_1 == 0) {
          puVar16 = (undefined4 *)0x1;
          uVar12 = *param_2;
          param_2 = (char **)0x0;
          (*(code *)PTR_ERR_print_errors_006a7f40)(uVar12);
          goto LAB_0043a6bc;
        }
        if (local_88 == (char *)0x0) {
          (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s6,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
        }
        else {
          iVar13 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s6,0x6c,3,local_88);
          if (iVar13 < 1) {
            param_2 = (char **)0x0;
            puVar16 = (undefined4 *)0x1;
            (*(code *)PTR_perror_006aab88)(local_88);
            goto LAB_0043a6bc;
          }
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"read EC key\n");
        if (iVar17 == 1) {
          pcVar19 = (code *)PTR_d2i_ECPrivateKey_bio_006a8790;
          if (bVar2) {
            pcVar19 = (code *)PTR_d2i_EC_PUBKEY_bio_006a8794;
          }
          param_2 = (char **)(*pcVar19)(unaff_s6,0);
        }
        else {
          if (iVar17 != 3) {
            param_2 = (char **)0x0;
            puVar16 = (undefined4 *)0x1;
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)PTR_bio_err_006a7f3c,"bad input format specified for key\n");
            goto LAB_0043a6bc;
          }
          iVar13 = local_34;
          pcVar19 = (code *)PTR_PEM_read_bio_ECPrivateKey_006a8778;
          if (bVar2) {
            iVar13 = 0;
            pcVar19 = (code *)PTR_PEM_read_bio_EC_PUBKEY_006a877c;
          }
          param_2 = (char **)(*pcVar19)(unaff_s6,0,0,iVar13);
        }
        if (param_2 == (char **)0x0) {
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"unable to load Key\n");
        }
        else {
          if (local_80 == (char *)0x0) {
            (*(code *)PTR_BIO_ctrl_006a7f18)(param_1,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
          }
          else {
            iVar13 = (*(code *)PTR_BIO_ctrl_006a7f18)(param_1,0x6c,5,local_80);
            if (iVar13 < 1) {
              puVar16 = (undefined4 *)0x1;
              (*(code *)PTR_perror_006aab88)(local_80);
              goto LAB_0043a6bc;
            }
          }
          uVar12 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(param_2);
          if (bVar3) {
            (*(code *)PTR_EC_KEY_set_conv_form_006a8798)(param_2,local_58);
          }
          if (bVar4) {
            (*(code *)PTR_EC_KEY_set_asn1_flag_006a8784)(param_2,local_48);
          }
          if ((!bVar5) ||
             (iVar13 = (*(code *)PTR_EC_KEY_print_006a8788)(param_1,param_2,0), iVar13 != 0)) {
            if (bVar6) goto LAB_0043a6b8;
            (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"writing EC key\n");
            if (iVar18 != 1) {
              if (iVar18 != 3) {
                puVar16 = (undefined4 *)0x1;
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)PTR_bio_err_006a7f3c,
                           "bad output format specified for outfile\n");
                goto LAB_0043a6bc;
              }
              if (bVar7) {
                iVar13 = (*(code *)PTR_PEM_write_bio_ECPKParameters_006a82bc)(param_1,uVar12);
                goto LAB_0043acb0;
              }
              if ((!bVar2) && (iVar13 = local_30, !bVar8)) goto LAB_0043b070;
              iVar13 = (*(code *)PTR_PEM_write_bio_EC_PUBKEY_006a878c)(param_1,param_2);
              goto LAB_0043acb0;
            }
            if (bVar7) {
              iVar13 = (*(code *)PTR_ASN1_i2d_bio_006a8298)
                                 (PTR_i2d_ECPKParameters_006a82cc,param_1,uVar12);
              goto LAB_0043acb0;
            }
            if ((!bVar2) && (!bVar8)) {
              iVar13 = (*(code *)PTR_i2d_ECPrivateKey_bio_006a82fc)(param_1,param_2);
              goto LAB_0043acb0;
            }
            iVar13 = (*(code *)PTR_i2d_EC_PUBKEY_bio_006a879c)(param_1,param_2);
            goto LAB_0043acb0;
          }
          (*(code *)PTR_perror_006aab88)(local_80);
        }
        uVar12 = *puVar16;
        puVar16 = (undefined4 *)0x1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(uVar12);
        goto LAB_0043a6bc;
      }
      (*(code *)PTR_ERR_print_errors_006a7f40)(*param_2);
      if (param_1 != 0) {
        puVar16 = (undefined4 *)0x1;
        param_2 = (char **)0x0;
        goto LAB_0043a6d0;
      }
    }
  }
LAB_0043a910:
  puVar16 = (undefined4 *)0x1;
  while( true ) {
    if (local_34 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (local_30 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (local_2c == *(int *)puVar9) break;
    iVar13 = (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0043b070:
    iVar13 = (*(code *)PTR_PEM_write_bio_ECPrivateKey_006a82f8)
                       (param_1,param_2,local_40,0,0,0,iVar13);
LAB_0043acb0:
    if (iVar13 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar16,"unable to write private key\n");
      uVar12 = *puVar16;
      puVar16 = (undefined4 *)0x1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(uVar12);
    }
    else {
LAB_0043a6b8:
      puVar16 = (undefined4 *)0x0;
    }
LAB_0043a6bc:
    (*(code *)PTR_BIO_free_006a7f70)(unaff_s6);
    if (param_1 != 0) {
LAB_0043a6d0:
      (*(code *)PTR_BIO_free_all_006a7f74)(param_1);
    }
    if (param_2 != (char **)0x0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)(param_2);
    }
  }
  return puVar16;
}

