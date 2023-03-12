
undefined4 * dsa_main(int param_1,char **param_2)

{
  char **ppcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined *puVar7;
  undefined *puVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  char **ppcVar13;
  undefined4 *puVar14;
  char *unaff_s3;
  undefined4 uVar15;
  int iVar16;
  undefined *unaff_s6;
  char *local_7c;
  char *local_74;
  char *local_6c;
  char *local_60;
  char *local_58;
  undefined4 local_50;
  int local_48;
  int local_34;
  int local_30;
  int local_2c;
  
  puVar8 = PTR___stack_chk_guard_006aabf0;
  puVar14 = (undefined4 *)PTR_bio_err_006a7f3c;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar12 = *puVar14;
  if (iVar12 == 0) {
    uVar15 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar12 = (*(code *)PTR_BIO_new_006a7fa4)(uVar15);
    *puVar14 = iVar12;
    if (iVar12 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar12,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar12 = *puVar14;
    }
  }
  iVar12 = (*(code *)PTR_load_config_006a7f64)(iVar12,0);
  if (iVar12 == 0) {
LAB_00438bdc:
    puVar14 = (undefined4 *)0x1;
    goto LAB_00438be0;
  }
  pcVar9 = *param_2;
  iVar12 = param_1 + -1;
  ppcVar13 = param_2 + 1;
  if (iVar12 < 1) {
    local_60 = (char *)0x0;
    local_6c = (char *)0x0;
    iVar16 = 3;
    local_74 = (char *)0x0;
    uVar15 = 3;
    local_7c = (char *)0x0;
    local_50 = 2;
    bVar4 = false;
    local_58 = (char *)0x0;
    bVar6 = false;
    bVar2 = false;
    bVar5 = false;
    bVar3 = false;
    local_48 = 0;
  }
  else {
    bVar4 = false;
    local_60 = (char *)0x0;
    local_6c = (char *)0x0;
    local_50 = 2;
    local_58 = (char *)0x0;
    iVar16 = 3;
    local_74 = (char *)0x0;
    uVar15 = 3;
    local_7c = (char *)0x0;
    param_1 = 0x630000;
    bVar6 = false;
    bVar2 = false;
    unaff_s3 = "-outform";
    bVar5 = false;
    unaff_s6 = &DAT_00632edc;
    bVar3 = false;
    local_48 = 0;
LAB_0043879c:
    do {
      param_2 = (char **)*ppcVar13;
      iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-inform");
      if (iVar10 == 0) {
        iVar12 = iVar12 + -1;
        if (iVar12 != 0) {
          uVar15 = (*(code *)PTR_str2fmt_006a7f4c)(ppcVar13[1]);
          ppcVar13 = ppcVar13 + 1;
          goto LAB_00438790;
        }
LAB_004389f8:
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14,"%s [options] <infile >outfile\n",pcVar9);
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14,"where options are\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14," -inform arg     input format - DER or PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14," -outform arg    output format - DER or PEM\n")
        ;
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14," -in arg         input file\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*puVar14," -passin arg     input file pass phrase source\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14," -out arg        output file\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*puVar14," -passout arg    output file pass phrase source\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*puVar14," -engine e       use engine e, possibly a hardware device.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*puVar14," -des            encrypt PEM output with cbc des\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*puVar14,
                   " -des3           encrypt PEM output with ede cbc des using 168 bit key\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*puVar14," -idea           encrypt PEM output with cbc idea\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14," -aes128, -aes192, -aes256\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*puVar14,"                 encrypt PEM output with cbc aes\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14," -camellia128, -camellia192, -camellia256\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*puVar14,"                 encrypt PEM output with cbc camellia\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*puVar14," -seed           encrypt PEM output with cbc seed\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14," -text           print the key in text\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14," -noout          don\'t print key out\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*puVar14," -modulus        print the DSA public value\n")
        ;
        goto LAB_00438bdc;
      }
      iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-outform");
      if (iVar10 != 0) {
        if ((((*(char *)param_2 == '-') && (*(char *)((int)param_2 + 1) == 'i')) &&
            (*(char *)((int)param_2 + 2) == 'n')) && (*(char *)((int)param_2 + 3) == '\0')) {
          iVar12 = iVar12 + -1;
          param_2 = ppcVar13 + 1;
          if (iVar12 == 0) goto LAB_004389f8;
          local_7c = ppcVar13[1];
          ppcVar13 = param_2;
        }
        else {
          iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_00632edc);
          if (iVar10 == 0) {
            iVar12 = iVar12 + -1;
            param_2 = ppcVar13 + 1;
            if (iVar12 == 0) goto LAB_004389f8;
            local_74 = ppcVar13[1];
            ppcVar13 = param_2;
          }
          else {
            iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-passin");
            if (iVar10 == 0) {
              iVar12 = iVar12 + -1;
              param_2 = ppcVar13 + 1;
              if (iVar12 == 0) goto LAB_004389f8;
              local_6c = ppcVar13[1];
              ppcVar13 = param_2;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-passout");
              if (iVar10 == 0) {
                iVar12 = iVar12 + -1;
                param_2 = ppcVar13 + 1;
                if (iVar12 == 0) goto LAB_004389f8;
                local_60 = ppcVar13[1];
                ppcVar13 = param_2;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-engine");
                if (iVar10 == 0) {
                  iVar12 = iVar12 + -1;
                  param_2 = ppcVar13 + 1;
                  if (iVar12 == 0) goto LAB_004389f8;
                  local_58 = ppcVar13[1];
                  ppcVar13 = param_2;
                }
                else {
                  iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-pvk-strong");
                  if (iVar10 == 0) {
                    local_50 = 2;
                  }
                  else {
                    iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-pvk-weak");
                    if (iVar10 == 0) {
                      local_50 = 1;
                    }
                    else {
                      iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-pvk-none");
                      if (iVar10 == 0) {
                        local_50 = 0;
                      }
                      else {
                        iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-noout");
                        if (iVar10 == 0) {
                          bVar5 = true;
                        }
                        else {
                          iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-text");
                          if (iVar10 == 0) {
                            bVar3 = true;
                          }
                          else {
                            iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-modulus");
                            if (iVar10 == 0) {
                              bVar4 = true;
                            }
                            else {
                              iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-pubin");
                              if (iVar10 == 0) {
                                bVar2 = true;
                              }
                              else {
                                iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-pubout");
                                if (iVar10 == 0) {
                                  bVar6 = true;
                                }
                                else {
                                  local_48 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)
                                                       ((char *)((int)param_2 + 1));
                                  if (local_48 == 0) {
                                    (*(code *)PTR_BIO_printf_006a7f38)
                                              (*puVar14,"unknown option %s\n",*ppcVar13);
                                    goto LAB_004389f8;
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
        }
LAB_00438790:
        iVar12 = iVar12 + -1;
        ppcVar13 = ppcVar13 + 1;
        if (iVar12 == 0) break;
        goto LAB_0043879c;
      }
      if (iVar12 == 1) goto LAB_004389f8;
      ppcVar1 = ppcVar13 + 1;
      iVar12 = iVar12 + -2;
      ppcVar13 = ppcVar13 + 2;
      iVar16 = (*(code *)PTR_str2fmt_006a7f4c)(*ppcVar1);
    } while (iVar12 != 0);
  }
  param_2 = (char **)PTR_bio_err_006a7f3c;
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  unaff_s3 = (char *)(*(code *)PTR_setup_engine_006a7fc4)(*puVar14,local_58,0);
  iVar12 = (*(code *)PTR_app_passwd_006a7f54)(*puVar14,local_6c,local_60,&local_34,&local_30);
  if (iVar12 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(*param_2,"Error getting passwords\n");
    goto LAB_00438bdc;
  }
  uVar11 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  unaff_s6 = (undefined *)(*(code *)PTR_BIO_new_006a7fa4)(uVar11);
  uVar11 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  param_1 = (*(code *)PTR_BIO_new_006a7fa4)(uVar11);
  if (unaff_s6 == (undefined *)0x0) {
    (*(code *)PTR_ERR_print_errors_006a7f40)(*param_2);
    if (param_1 != 0) {
      param_2 = (char **)0x0;
      puVar14 = (undefined4 *)0x1;
      goto LAB_004389b4;
    }
    goto LAB_00438bdc;
  }
  if (param_1 == 0) {
    uVar15 = *param_2;
    param_2 = (char **)0x0;
    (*(code *)PTR_ERR_print_errors_006a7f40)(uVar15);
LAB_0043899c:
    puVar14 = (undefined4 *)0x1;
  }
  else {
    if (local_7c == (char *)0x0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s6,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
    }
    else {
      iVar12 = (*(code *)PTR_BIO_ctrl_006a7f18)(unaff_s6,0x6c,3,local_7c);
      if (iVar12 < 1) {
        param_2 = (char **)0x0;
        puVar14 = (undefined4 *)0x1;
        (*(code *)PTR_perror_006aab88)(local_7c);
        goto LAB_004389a0;
      }
    }
    puVar7 = PTR_bio_err_006a7f3c;
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar14,"read DSA key\n");
    if (bVar2) {
      iVar12 = (*(code *)PTR_load_pubkey_006a85e4)
                         (*(undefined4 *)puVar7,local_7c,uVar15,1,local_34,unaff_s3,"Public Key");
    }
    else {
      iVar12 = (*(code *)PTR_load_key_006a7fc8)
                         (*(undefined4 *)puVar7,local_7c,uVar15,1,local_34,unaff_s3,"Private Key");
    }
    if (iVar12 != 0) {
      param_2 = (char **)(*(code *)PTR_EVP_PKEY_get1_DSA_006a8748)(iVar12);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar12);
      if (param_2 != (char **)0x0) {
        if (local_74 == (char *)0x0) {
          (*(code *)PTR_BIO_ctrl_006a7f18)(param_1,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
        }
        else {
          iVar12 = (*(code *)PTR_BIO_ctrl_006a7f18)(param_1,0x6c,5,local_74);
          if (iVar12 < 1) {
            puVar14 = (undefined4 *)0x1;
            (*(code *)PTR_perror_006aab88)(local_74);
            goto LAB_004389a0;
          }
        }
        if ((bVar3) && (iVar12 = (*(code *)PTR_DSA_print_006a874c)(param_1,param_2,0), iVar12 == 0))
        {
          (*(code *)PTR_perror_006aab88)(local_74);
          uVar15 = *puVar14;
          puVar14 = (undefined4 *)0x1;
          (*(code *)PTR_ERR_print_errors_006a7f40)(uVar15);
          goto LAB_004389a0;
        }
        unaff_s3 = PTR_stdout_006aaad4;
        if (bVar4) {
          (*(code *)PTR_fwrite_006aab7c)("Public Key=",1,0xb,*(undefined4 *)PTR_stdout_006aaad4);
          (*(code *)PTR_BN_print_006a8024)(param_1,param_2[6]);
          (*(code *)PTR_fputc_006aaab0)(10,*(undefined4 *)unaff_s3);
        }
        if (!bVar5) {
          (*(code *)PTR_BIO_printf_006a7f38)(*puVar14,"writing DSA key\n");
          if (iVar16 == 1) {
            if ((!bVar2) && (!bVar6)) {
              iVar12 = (*(code *)PTR_i2d_DSAPrivateKey_bio_006a875c)(param_1,param_2);
              goto LAB_00439180;
            }
            iVar12 = (*(code *)PTR_i2d_DSA_PUBKEY_bio_006a8754)(param_1,param_2);
            goto LAB_00439180;
          }
          if (iVar16 == 3) {
            if ((!bVar2) && (!bVar6)) {
              iVar12 = (*(code *)PTR_PEM_write_bio_DSAPrivateKey_006a8760)
                                 (param_1,param_2,local_48,0,0,0,local_30);
              goto LAB_00439180;
            }
            iVar12 = (*(code *)PTR_PEM_write_bio_DSA_PUBKEY_006a8750)(param_1,param_2);
            goto LAB_00439180;
          }
          if (iVar16 - 0xbU < 2) {
            unaff_s3 = (char *)(*(code *)PTR_EVP_PKEY_new_006a8710)();
            (*(code *)PTR_EVP_PKEY_set1_DSA_006a8758)(unaff_s3,param_2);
            if (iVar16 == 0xc) goto LAB_00439280;
            if ((!bVar2) && (!bVar6)) {
              iVar12 = (*(code *)PTR_i2b_PrivateKey_bio_006a872c)(param_1,unaff_s3);
              goto LAB_00439214;
            }
            iVar12 = (*(code *)PTR_i2b_PublicKey_bio_006a8718)(param_1,unaff_s3);
            goto LAB_00439214;
          }
          puVar14 = (undefined4 *)0x1;
          (*(code *)PTR_BIO_printf_006a7f38)
                    (*(undefined4 *)PTR_bio_err_006a7f3c,"bad output format specified for outfile\n"
                    );
          goto LAB_004389a0;
        }
        goto LAB_0043899c;
      }
    }
    param_2 = (char **)0x0;
    (*(code *)PTR_BIO_printf_006a7f38)(*puVar14,"unable to load Key\n");
    uVar15 = *puVar14;
    puVar14 = (undefined4 *)0x1;
    (*(code *)PTR_ERR_print_errors_006a7f40)(uVar15);
  }
LAB_004389a0:
  while( true ) {
    (*(code *)PTR_BIO_free_006a7f70)(unaff_s6);
    if (param_1 != 0) {
LAB_004389b4:
      (*(code *)PTR_BIO_free_all_006a7f74)(param_1);
    }
    if (param_2 != (char **)0x0) {
      (*(code *)PTR_DSA_free_006a862c)(param_2);
    }
LAB_00438be0:
    if (local_34 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (local_30 != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (local_2c == *(int *)puVar8) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00439280:
    iVar12 = (*(code *)PTR_i2b_PVK_bio_006a8728)(param_1,unaff_s3,local_50,0,local_30);
LAB_00439214:
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(unaff_s3);
LAB_00439180:
    if (iVar12 < 1) {
      (*(code *)PTR_BIO_printf_006a7f38)(*puVar14,"unable to write private key\n");
      uVar15 = *puVar14;
      puVar14 = (undefined4 *)0x1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(uVar15);
    }
    else {
      puVar14 = (undefined4 *)0x0;
    }
  }
  return puVar14;
}

