
undefined4 dhparam_main(int param_1,char **param_2)

{
  char cVar1;
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
  char **ppcVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  char *local_84;
  char *local_78;
  char *local_70;
  int local_68;
  char *local_58;
  int local_3c;
  uint local_38;
  undefined4 local_34;
  code *local_30;
  int local_2c;
  
  puVar8 = PTR___stack_chk_guard_006aabf0;
  puVar7 = PTR_bio_err_006a7f3c;
  local_3c = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar15 = *(int *)puVar7;
  if (iVar15 == 0) {
    uVar11 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar15 = (*(code *)PTR_BIO_new_006a7fa4)(uVar11);
    *(int *)puVar7 = iVar15;
    if (iVar15 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar15,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar15 = *(int *)puVar7;
    }
  }
  iVar15 = (*(code *)PTR_load_config_006a7f64)(iVar15,0);
  if (iVar15 == 0) goto LAB_0042a30c;
  pcVar9 = *param_2;
  param_1 = param_1 + -1;
  ppcVar12 = param_2 + 1;
  local_68 = 0;
  local_70 = (char *)0x0;
  iVar17 = 3;
  local_58 = (char *)0x0;
  iVar15 = 3;
  local_78 = (char *)0x0;
  local_84 = (char *)0x0;
  bVar5 = false;
  bVar6 = false;
  bVar4 = false;
  bVar2 = false;
  bVar3 = false;
  if (0 < param_1) {
LAB_0042a15c:
    do {
      param_2 = (char **)*ppcVar12;
      iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-inform");
      if (iVar10 == 0) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          iVar15 = (*(code *)PTR_str2fmt_006a7f4c)(ppcVar12[1]);
          ppcVar12 = ppcVar12 + 1;
          goto LAB_0042a150;
        }
LAB_0042a4f4:
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"%s [options] [numbits]\n",pcVar9);
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"where options are\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -inform arg   input format - one of DER PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -outform arg  output format - one of DER PEM\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7," -in arg       input file\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7," -out arg      output file\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " -dsaparam     read or generate DSA parameters, convert to DH\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -check        check the DH parameters\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -text         print a text form of the DH parameters\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7," -C            Output C code\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " -2            generate parameters using  2 as the generator value\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " -5            generate parameters using  5 as the generator value\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " numbits       number of bits in to generate (default 512)\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   " -engine e     use engine e, possibly a hardware device.\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7," -rand file%cfile%c...\n",0x3a,0x3a);
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,
                   "               - load the file (or the files in the directory) into\n");
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,"               the random number generator\n");
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7," -noout        no output\n");
        goto LAB_0042a30c;
      }
      iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-outform");
      if (iVar10 == 0) {
        if (param_1 == 1) goto LAB_0042a4f4;
        param_1 = param_1 + -2;
        iVar17 = (*(code *)PTR_str2fmt_006a7f4c)(ppcVar12[1]);
        param_2 = ppcVar12 + 1;
        ppcVar12 = ppcVar12 + 2;
        if (param_1 == 0) break;
        goto LAB_0042a15c;
      }
      cVar1 = *(char *)param_2;
      if ((((cVar1 == '-') && (*(char *)((int)param_2 + 1) == 'i')) &&
          (*(char *)((int)param_2 + 2) == 'n')) && (*(char *)((int)param_2 + 3) == '\0')) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0042a4f4;
        local_84 = ppcVar12[1];
        ppcVar12 = ppcVar12 + 1;
      }
      else {
        iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,&DAT_00632edc);
        if (iVar10 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0042a4f4;
          local_78 = ppcVar12[1];
          ppcVar12 = ppcVar12 + 1;
        }
        else {
          iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-engine");
          if (iVar10 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0042a4f4;
            local_70 = ppcVar12[1];
            ppcVar12 = ppcVar12 + 1;
          }
          else {
            iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-check");
            if (iVar10 == 0) {
              bVar4 = true;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-text");
              if (iVar10 == 0) {
                bVar3 = true;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-dsaparam");
                if (iVar10 == 0) {
                  bVar2 = true;
                }
                else if (cVar1 == '-') {
                  cVar1 = *(char *)((int)param_2 + 1);
                  if ((cVar1 == 'C') && (*(char *)((int)param_2 + 2) == '\0')) {
                    bVar5 = true;
                  }
                  else {
                    iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-noout");
                    if (iVar10 == 0) {
                      bVar6 = true;
                    }
                    else if (cVar1 == '2') {
                      if (*(char *)((int)param_2 + 2) != '\0') {
LAB_0042a490:
                        iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-rand");
                        if (iVar10 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_58 = ppcVar12[1];
                            ppcVar12 = ppcVar12 + 1;
                            goto LAB_0042a150;
                          }
                        }
                        else {
                          iVar10 = (*(code *)PTR___isoc99_sscanf_006aab10)(param_2,"%d",&local_3c);
                          if ((iVar10 != 0) && (0 < local_3c)) goto LAB_0042a150;
                        }
                        goto LAB_0042a4f4;
                      }
                      local_68 = 2;
                    }
                    else {
                      if ((cVar1 != '5') || (*(char *)((int)param_2 + 2) != '\0'))
                      goto LAB_0042a490;
                      local_68 = 5;
                    }
                  }
                }
                else {
                  iVar10 = (*(code *)PTR_strcmp_006aac20)(param_2,"-noout");
                  if (iVar10 != 0) goto LAB_0042a490;
                  bVar6 = true;
                }
              }
            }
          }
        }
      }
LAB_0042a150:
      param_1 = param_1 + -1;
      param_2 = ppcVar12;
      ppcVar12 = ppcVar12 + 1;
    } while (param_1 != 0);
  }
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar7,local_70,0);
  if (local_68 == 0) {
    if (!bVar2) {
      if (local_3c == 0) goto LAB_0042a6d4;
      local_68 = 2;
      goto LAB_0042a20c;
    }
    if (local_3c != 0) goto LAB_0042a20c;
LAB_0042a6d4:
    uVar11 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar10 = (*(code *)PTR_BIO_new_006a7fa4)(uVar11);
    if (iVar10 == 0) goto LAB_0042a2fc;
    if (local_84 != (char *)0x0) {
      iVar13 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar10,0x6c,3,local_84);
      if (0 < iVar13) goto LAB_0042a724;
      (*(code *)PTR_perror_006aab88)(local_84);
      goto LAB_0042a74c;
    }
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar10,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
LAB_0042a724:
    if (iVar15 != 1) {
      if (iVar15 == 3) {
        if (!bVar2) {
          param_2 = (char **)(*(code *)PTR_PEM_read_bio_DHparams_006a8608)(iVar10,0,0,0);
          goto LAB_0042aa7c;
        }
        iVar15 = (*(code *)PTR_PEM_read_bio_DSAparams_006a8634)(iVar10,0,0,0);
LAB_0042a980:
        if (iVar15 != 0) {
          param_2 = (char **)(*(code *)PTR_DSA_dup_DH_006a8638)(iVar15);
          (*(code *)PTR_DSA_free_006a862c)(iVar15);
          if (param_2 != (char **)0x0) goto LAB_0042a9b4;
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
          goto LAB_0042a74c;
        }
        uVar11 = *(undefined4 *)puVar7;
        pcVar9 = "unable to load DSA parameters\n";
LAB_0042aa94:
        param_2 = (char **)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(uVar11,pcVar9);
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"bad input format specified\n");
LAB_0042a74c:
        param_2 = (char **)0x0;
      }
LAB_0042a750:
      (*(code *)PTR_BIO_free_006a7f70)(iVar10);
      goto LAB_0042a760;
    }
    if (bVar2) {
      iVar15 = (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                         (PTR_DSA_new_006a8624,PTR_d2i_DSAparams_006a863c,iVar10,0);
      goto LAB_0042a980;
    }
    param_2 = (char **)(*(code *)PTR_ASN1_d2i_bio_006a82c4)
                                 (PTR_DH_new_006a8618,PTR_d2i_DHparams_006a8614,iVar10,0);
LAB_0042aa7c:
    if (param_2 == (char **)0x0) {
      uVar11 = *(undefined4 *)puVar7;
      pcVar9 = "unable to load DH parameters\n";
      goto LAB_0042aa94;
    }
LAB_0042a9b4:
    uVar11 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar15 = (*(code *)PTR_BIO_new_006a7fa4)(uVar11);
    if (iVar15 == 0) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      goto LAB_0042a750;
    }
  }
  else {
    if (local_3c == 0) {
      local_3c = 0x200;
    }
    if (bVar2) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar7,"generator may not be chosen for DSA parameters\n");
      goto LAB_0042a30c;
    }
LAB_0042a20c:
    local_34 = *(undefined4 *)puVar7;
    local_38 = 2;
    local_30 = dh_cb;
    iVar15 = (*(code *)PTR_app_RAND_load_file_006a7fcc)(0,local_34,1);
    if (iVar15 == 0) {
      if (local_58 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,
                   "warning, not much extra random data, consider using the -rand option\n");
      }
      else {
LAB_0042a250:
        uVar16 = *(undefined4 *)puVar7;
        uVar11 = (*(code *)PTR_app_RAND_load_files_006a8038)(local_58);
        (*(code *)PTR_BIO_printf_006a7f38)(uVar16,"%ld semi-random bytes loaded\n",uVar11);
      }
    }
    else if (local_58 != (char *)0x0) goto LAB_0042a250;
    if (bVar2) {
      ppcVar12 = (char **)(*(code *)PTR_DSA_new_006a8624)();
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar7,"Generating DSA parameters, %d bit long prime\n",local_3c);
      param_2 = ppcVar12;
      if (ppcVar12 != (char **)0x0) {
        iVar15 = (*(code *)PTR_DSA_generate_parameters_ex_006a8628)
                           (ppcVar12,local_3c,0,0,0,0,&local_38);
        if (iVar15 != 0) {
          param_2 = (char **)(*(code *)PTR_DSA_dup_DH_006a8638)(ppcVar12);
          (*(code *)PTR_DSA_free_006a862c)(ppcVar12);
          if (param_2 == (char **)0x0) {
            (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
            goto LAB_0042a30c;
          }
          goto LAB_0042a848;
        }
        (*(code *)PTR_DSA_free_006a862c)(ppcVar12);
      }
LAB_0042a2fc:
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
LAB_0042a30c:
      uVar11 = 1;
      while (local_2c != *(int *)puVar8) {
        (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0042b138:
        uVar11 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
LAB_0042a768:
        (*(code *)PTR_DH_free_006a8604)(param_2);
      }
      return uVar11;
    }
    param_2 = (char **)(*(code *)PTR_DH_new_006a8618)();
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar7,
               "Generating DH parameters, %d bit long safe prime, generator %d\n",local_3c,local_68)
    ;
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"This is going to take a long time\n");
    if ((param_2 == (char **)0x0) ||
       (iVar15 = (*(code *)PTR_DH_generate_parameters_ex_006a8630)
                           (param_2,local_3c,local_68,&local_38), iVar15 == 0)) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
LAB_0042a760:
      uVar11 = 1;
      if (param_2 != (char **)0x0) goto LAB_0042a768;
      goto LAB_0042a30c;
    }
LAB_0042a848:
    (*(code *)PTR_app_RAND_write_file_006a804c)(0,*(undefined4 *)puVar7);
    uVar11 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar15 = (*(code *)PTR_BIO_new_006a7fa4)(uVar11);
    if (iVar15 == 0) goto LAB_0042b138;
    iVar10 = 0;
  }
  if (local_78 == (char *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar15,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
  }
  else {
    iVar13 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar15,0x6c,5,local_78);
    if (iVar13 < 1) {
      uVar11 = 1;
      (*(code *)PTR_perror_006aab88)(local_78);
      goto LAB_0042a90c;
    }
  }
  if (bVar3) {
    (*(code *)PTR_DHparams_print_006a860c)(iVar15,param_2);
  }
  if (bVar4) {
    iVar13 = (*(code *)PTR_DH_check_006a8610)(param_2,&local_38);
    if (iVar13 == 0) {
      uVar11 = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      goto LAB_0042a90c;
    }
    if ((local_38 & 1) != 0) {
      (*(code *)PTR_puts_006aab60)("p value is not prime");
    }
    if ((local_38 & 2) != 0) {
      (*(code *)PTR_puts_006aab60)("p value is not a safe prime");
    }
    if ((local_38 & 4) != 0) {
      (*(code *)PTR_puts_006aab60)("unable to check the generator value");
    }
    if ((local_38 & 8) != 0) {
      (*(code *)PTR_puts_006aab60)("the g value is not a generator");
    }
    if (local_38 == 0) {
      (*(code *)PTR_puts_006aab60)("DH parameters appear to be ok.");
    }
  }
  if (bVar5) {
    iVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(param_2[2]);
    uVar11 = (*(code *)PTR_BN_num_bits_006a82f4)(param_2[2]);
    iVar13 = iVar14 + 7;
    if (iVar14 + 7 < 0) {
      iVar13 = iVar14 + 0xe;
    }
    iVar13 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar13 >> 3,"dhparam.c",0x1d2);
    if (iVar13 == 0) {
      uVar11 = 1;
      (*(code *)PTR_perror_006aab88)("OPENSSL_malloc");
      goto LAB_0042a90c;
    }
    (*(code *)PTR_puts_006aab60)("#ifndef HEADER_DH_H\n#include <openssl/dh.h>\n#endif");
    (*(code *)PTR___printf_chk_006aaad0)(1,"DH *get_dh%d()\n\t{\n",uVar11);
    iVar14 = (*(code *)PTR_BN_bn2bin_006a8300)(param_2[2],iVar13);
    (*(code *)PTR___printf_chk_006aaad0)(1,"\tstatic unsigned char dh%d_p[]={",uVar11);
    local_38 = 0;
    if (0 < iVar14) {
      do {
        if (local_38 == ((int)local_38 / 0xc) * 0xc) {
          (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00634efc);
        }
        (*(code *)PTR___printf_chk_006aaad0)(1,"0x%02X,",*(undefined *)(iVar13 + local_38));
        local_38 = local_38 + 1;
      } while ((int)local_38 < iVar14);
    }
    (*(code *)PTR_puts_006aab60)("\n\t\t};");
    iVar14 = (*(code *)PTR_BN_bn2bin_006a8300)(param_2[3],iVar13);
    (*(code *)PTR___printf_chk_006aaad0)(1,"\tstatic unsigned char dh%d_g[]={",uVar11);
    local_38 = 0;
    if (0 < iVar14) {
      do {
        if (local_38 == ((int)local_38 / 0xc) * 0xc) {
          (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00634efc);
        }
        (*(code *)PTR___printf_chk_006aaad0)(1,"0x%02X,",*(undefined *)(iVar13 + local_38));
        local_38 = local_38 + 1;
      } while ((int)local_38 < iVar14);
    }
    (*(code *)PTR_puts_006aab60)("\n\t\t};");
    (*(code *)PTR_puts_006aab60)("\tDH *dh;\n");
    (*(code *)PTR_puts_006aab60)("\tif ((dh=DH_new()) == NULL) return(NULL);");
    (*(code *)PTR___printf_chk_006aaad0)
              (1,"\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",uVar11,uVar11);
    (*(code *)PTR___printf_chk_006aaad0)
              (1,"\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",uVar11,uVar11);
    (*(code *)PTR_puts_006aab60)("\tif ((dh->p == NULL) || (dh->g == NULL))");
    (*(code *)PTR_puts_006aab60)("\t\t{ DH_free(dh); return(NULL); }");
    if (param_2[4] != (char *)0x0) {
      (*(code *)PTR___printf_chk_006aaad0)(1,"\tdh->length = %ld;\n");
    }
    (*(code *)PTR_puts_006aab60)("\treturn(dh);\n\t}");
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar13);
  }
  if (!bVar6) {
    if (iVar17 == 1) {
      local_38 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_DHparams_006a861c,iVar15,param_2);
    }
    else {
      if (iVar17 != 3) {
        uVar11 = 1;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,"bad output format specified for outfile\n");
        goto LAB_0042a90c;
      }
      local_38 = (*(code *)PTR_PEM_write_bio_DHparams_006a8620)(iVar15,param_2);
    }
    if (local_38 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"unable to write DH parameters\n");
      uVar11 = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      goto LAB_0042a90c;
    }
  }
  uVar11 = 0;
LAB_0042a90c:
  if (iVar10 != 0) {
    (*(code *)PTR_BIO_free_006a7f70)(iVar10);
  }
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar15);
  goto LAB_0042a768;
}

