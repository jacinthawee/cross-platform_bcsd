
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
  
  puVar8 = PTR___stack_chk_guard_006a9ae8;
  puVar7 = PTR_bio_err_006a6e3c;
  local_3c = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar15 = *(int *)puVar7;
  if (iVar15 == 0) {
    uVar11 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar15 = (*(code *)PTR_BIO_new_006a6ea4)(uVar11);
    *(int *)puVar7 = iVar15;
    if (iVar15 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar15,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
      iVar15 = *(int *)puVar7;
    }
  }
  iVar15 = (*(code *)PTR_load_config_006a6e64)(iVar15,0);
  if (iVar15 == 0) goto LAB_0042a39c;
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
LAB_0042a1ec:
    do {
      param_2 = (char **)*ppcVar12;
      iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-inform");
      if (iVar10 == 0) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          iVar15 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar12[1]);
          ppcVar12 = ppcVar12 + 1;
          goto LAB_0042a1e0;
        }
LAB_0042a584:
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7,"%s [options] [numbits]\n",pcVar9);
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7,"where options are\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7," -inform arg   input format - one of DER PEM\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7," -outform arg  output format - one of DER PEM\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7," -in arg       input file\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7," -out arg      output file\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7,
                   " -dsaparam     read or generate DSA parameters, convert to DH\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7," -check        check the DH parameters\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7," -text         print a text form of the DH parameters\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7," -C            Output C code\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7,
                   " -2            generate parameters using  2 as the generator value\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7,
                   " -5            generate parameters using  5 as the generator value\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7,
                   " numbits       number of bits in to generate (default 2048)\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7,
                   " -engine e     use engine e, possibly a hardware device.\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7," -rand file%cfile%c...\n",0x3a,0x3a);
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7,
                   "               - load the file (or the files in the directory) into\n");
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7,"               the random number generator\n");
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7," -noout        no output\n");
        goto LAB_0042a39c;
      }
      iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-outform");
      if (iVar10 == 0) {
        if (param_1 == 1) goto LAB_0042a584;
        param_1 = param_1 + -2;
        iVar17 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar12[1]);
        param_2 = ppcVar12 + 1;
        ppcVar12 = ppcVar12 + 2;
        if (param_1 == 0) break;
        goto LAB_0042a1ec;
      }
      cVar1 = *(char *)param_2;
      if ((((cVar1 == '-') && (*(char *)((int)param_2 + 1) == 'i')) &&
          (*(char *)((int)param_2 + 2) == 'n')) && (*(char *)((int)param_2 + 3) == '\0')) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0042a584;
        local_84 = ppcVar12[1];
        ppcVar12 = ppcVar12 + 1;
      }
      else {
        iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,&DAT_00632514);
        if (iVar10 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0042a584;
          local_78 = ppcVar12[1];
          ppcVar12 = ppcVar12 + 1;
        }
        else {
          iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-engine");
          if (iVar10 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0042a584;
            local_70 = ppcVar12[1];
            ppcVar12 = ppcVar12 + 1;
          }
          else {
            iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-check");
            if (iVar10 == 0) {
              bVar4 = true;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-text");
              if (iVar10 == 0) {
                bVar3 = true;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-dsaparam");
                if (iVar10 == 0) {
                  bVar2 = true;
                }
                else if (cVar1 == '-') {
                  cVar1 = *(char *)((int)param_2 + 1);
                  if ((cVar1 == 'C') && (*(char *)((int)param_2 + 2) == '\0')) {
                    bVar5 = true;
                  }
                  else {
                    iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-noout");
                    if (iVar10 == 0) {
                      bVar6 = true;
                    }
                    else if (cVar1 == '2') {
                      if (*(char *)((int)param_2 + 2) != '\0') {
LAB_0042a520:
                        iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-rand");
                        if (iVar10 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_58 = ppcVar12[1];
                            ppcVar12 = ppcVar12 + 1;
                            goto LAB_0042a1e0;
                          }
                        }
                        else {
                          iVar10 = (*(code *)PTR___isoc99_sscanf_006a9a04)(param_2,"%d",&local_3c);
                          if ((iVar10 != 0) && (0 < local_3c)) goto LAB_0042a1e0;
                        }
                        goto LAB_0042a584;
                      }
                      local_68 = 2;
                    }
                    else {
                      if ((cVar1 != '5') || (*(char *)((int)param_2 + 2) != '\0'))
                      goto LAB_0042a520;
                      local_68 = 5;
                    }
                  }
                }
                else {
                  iVar10 = (*(code *)PTR_strcmp_006a9b18)(param_2,"-noout");
                  if (iVar10 != 0) goto LAB_0042a520;
                  bVar6 = true;
                }
              }
            }
          }
        }
      }
LAB_0042a1e0:
      param_1 = param_1 + -1;
      param_2 = ppcVar12;
      ppcVar12 = ppcVar12 + 1;
    } while (param_1 != 0);
  }
  (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
  (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar7,local_70,0);
  if (local_68 == 0) {
    if (!bVar2) {
      if (local_3c == 0) goto LAB_0042a764;
      local_68 = 2;
      goto LAB_0042a29c;
    }
    if (local_3c != 0) goto LAB_0042a29c;
LAB_0042a764:
    uVar11 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar10 = (*(code *)PTR_BIO_new_006a6ea4)(uVar11);
    if (iVar10 == 0) goto LAB_0042a38c;
    if (local_84 != (char *)0x0) {
      iVar13 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar10,0x6c,3,local_84);
      if (0 < iVar13) goto LAB_0042a7b4;
      (*(code *)PTR_perror_006a9a80)(local_84);
      goto LAB_0042a7dc;
    }
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar10,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
LAB_0042a7b4:
    if (iVar15 != 1) {
      if (iVar15 == 3) {
        if (!bVar2) {
          param_2 = (char **)(*(code *)PTR_PEM_read_bio_DHparams_006a750c)(iVar10,0,0,0);
          goto LAB_0042ab0c;
        }
        iVar15 = (*(code *)PTR_PEM_read_bio_DSAparams_006a7538)(iVar10,0,0,0);
LAB_0042aa10:
        if (iVar15 != 0) {
          param_2 = (char **)(*(code *)PTR_DSA_dup_DH_006a753c)(iVar15);
          (*(code *)PTR_DSA_free_006a7530)(iVar15);
          if (param_2 != (char **)0x0) goto LAB_0042aa44;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar7);
          goto LAB_0042a7dc;
        }
        uVar11 = *(undefined4 *)puVar7;
        pcVar9 = "unable to load DSA parameters\n";
LAB_0042ab24:
        param_2 = (char **)0x0;
        (*(code *)PTR_BIO_printf_006a6e38)(uVar11,pcVar9);
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar7);
      }
      else {
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7,"bad input format specified\n");
LAB_0042a7dc:
        param_2 = (char **)0x0;
      }
LAB_0042a7e0:
      (*(code *)PTR_BIO_free_006a6e70)(iVar10);
      goto LAB_0042a7f0;
    }
    if (bVar2) {
      iVar15 = (*(code *)PTR_ASN1_d2i_bio_006a71c4)
                         (PTR_DSA_new_006a7528,PTR_d2i_DSAparams_006a7540,iVar10,0);
      goto LAB_0042aa10;
    }
    param_2 = (char **)(*(code *)PTR_ASN1_d2i_bio_006a71c4)
                                 (PTR_DH_new_006a751c,PTR_d2i_DHparams_006a7518,iVar10,0);
LAB_0042ab0c:
    if (param_2 == (char **)0x0) {
      uVar11 = *(undefined4 *)puVar7;
      pcVar9 = "unable to load DH parameters\n";
      goto LAB_0042ab24;
    }
LAB_0042aa44:
    uVar11 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar15 = (*(code *)PTR_BIO_new_006a6ea4)(uVar11);
    if (iVar15 == 0) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar7);
      goto LAB_0042a7e0;
    }
  }
  else {
    if (local_3c == 0) {
      local_3c = 0x800;
    }
    if (bVar2) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar7,"generator may not be chosen for DSA parameters\n");
      goto LAB_0042a39c;
    }
LAB_0042a29c:
    local_34 = *(undefined4 *)puVar7;
    local_38 = 2;
    local_30 = dh_cb;
    iVar15 = (*(code *)PTR_app_RAND_load_file_006a6ecc)(0,local_34,1);
    if (iVar15 == 0) {
      if (local_58 == (char *)0x0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)PTR_bio_err_006a6e3c,
                   "warning, not much extra random data, consider using the -rand option\n");
      }
      else {
LAB_0042a2e0:
        uVar16 = *(undefined4 *)puVar7;
        uVar11 = (*(code *)PTR_app_RAND_load_files_006a6f38)(local_58);
        (*(code *)PTR_BIO_printf_006a6e38)(uVar16,"%ld semi-random bytes loaded\n",uVar11);
      }
    }
    else if (local_58 != (char *)0x0) goto LAB_0042a2e0;
    if (bVar2) {
      ppcVar12 = (char **)(*(code *)PTR_DSA_new_006a7528)();
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar7,"Generating DSA parameters, %d bit long prime\n",local_3c);
      param_2 = ppcVar12;
      if (ppcVar12 != (char **)0x0) {
        iVar15 = (*(code *)PTR_DSA_generate_parameters_ex_006a752c)
                           (ppcVar12,local_3c,0,0,0,0,&local_38);
        if (iVar15 != 0) {
          param_2 = (char **)(*(code *)PTR_DSA_dup_DH_006a753c)(ppcVar12);
          (*(code *)PTR_DSA_free_006a7530)(ppcVar12);
          if (param_2 == (char **)0x0) {
            (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
            goto LAB_0042a39c;
          }
          goto LAB_0042a8d8;
        }
        (*(code *)PTR_DSA_free_006a7530)(ppcVar12);
      }
LAB_0042a38c:
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar7);
LAB_0042a39c:
      uVar11 = 1;
      while (local_2c != *(int *)puVar8) {
        (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0042b1c8:
        uVar11 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
LAB_0042a7f8:
        (*(code *)PTR_DH_free_006a7508)(param_2);
      }
      return uVar11;
    }
    param_2 = (char **)(*(code *)PTR_DH_new_006a751c)();
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)puVar7,
               "Generating DH parameters, %d bit long safe prime, generator %d\n",local_3c,local_68)
    ;
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7,"This is going to take a long time\n");
    if ((param_2 == (char **)0x0) ||
       (iVar15 = (*(code *)PTR_DH_generate_parameters_ex_006a7534)
                           (param_2,local_3c,local_68,&local_38), iVar15 == 0)) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar7);
LAB_0042a7f0:
      uVar11 = 1;
      if (param_2 != (char **)0x0) goto LAB_0042a7f8;
      goto LAB_0042a39c;
    }
LAB_0042a8d8:
    (*(code *)PTR_app_RAND_write_file_006a6f4c)(0,*(undefined4 *)puVar7);
    uVar11 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar15 = (*(code *)PTR_BIO_new_006a6ea4)(uVar11);
    if (iVar15 == 0) goto LAB_0042b1c8;
    iVar10 = 0;
  }
  if (local_78 == (char *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar15,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
  }
  else {
    iVar13 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar15,0x6c,5,local_78);
    if (iVar13 < 1) {
      uVar11 = 1;
      (*(code *)PTR_perror_006a9a80)(local_78);
      goto LAB_0042a99c;
    }
  }
  if (bVar3) {
    (*(code *)PTR_DHparams_print_006a7510)(iVar15,param_2);
  }
  if (bVar4) {
    iVar13 = (*(code *)PTR_DH_check_006a7514)(param_2,&local_38);
    if (iVar13 == 0) {
      uVar11 = 1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar7);
      goto LAB_0042a99c;
    }
    if ((local_38 & 1) != 0) {
      (*(code *)PTR_puts_006a9a54)("p value is not prime");
    }
    if ((local_38 & 2) != 0) {
      (*(code *)PTR_puts_006a9a54)("p value is not a safe prime");
    }
    if ((local_38 & 4) != 0) {
      (*(code *)PTR_puts_006a9a54)("unable to check the generator value");
    }
    if ((local_38 & 8) != 0) {
      (*(code *)PTR_puts_006a9a54)("the g value is not a generator");
    }
    if (local_38 == 0) {
      (*(code *)PTR_puts_006a9a54)("DH parameters appear to be ok.");
    }
  }
  if (bVar5) {
    iVar14 = (*(code *)PTR_BN_num_bits_006a71f4)(param_2[2]);
    uVar11 = (*(code *)PTR_BN_num_bits_006a71f4)(param_2[2]);
    iVar13 = iVar14 + 7;
    if (iVar14 + 7 < 0) {
      iVar13 = iVar14 + 0xe;
    }
    iVar13 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar13 >> 3,"dhparam.c",0x1c0);
    if (iVar13 == 0) {
      uVar11 = 1;
      (*(code *)PTR_perror_006a9a80)("OPENSSL_malloc");
      goto LAB_0042a99c;
    }
    (*(code *)PTR_puts_006a9a54)("#ifndef HEADER_DH_H\n#include <openssl/dh.h>\n#endif");
    (*(code *)PTR___printf_chk_006a99c4)(1,"DH *get_dh%d()\n\t{\n",uVar11);
    iVar14 = (*(code *)PTR_BN_bn2bin_006a7200)(param_2[2],iVar13);
    (*(code *)PTR___printf_chk_006a99c4)(1,"\tstatic unsigned char dh%d_p[]={",uVar11);
    local_38 = 0;
    if (0 < iVar14) {
      do {
        if (local_38 == ((int)local_38 / 0xc) * 0xc) {
          (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_006345a4);
        }
        (*(code *)PTR___printf_chk_006a99c4)(1,"0x%02X,",*(undefined *)(iVar13 + local_38));
        local_38 = local_38 + 1;
      } while ((int)local_38 < iVar14);
    }
    (*(code *)PTR_puts_006a9a54)("\n\t\t};");
    iVar14 = (*(code *)PTR_BN_bn2bin_006a7200)(param_2[3],iVar13);
    (*(code *)PTR___printf_chk_006a99c4)(1,"\tstatic unsigned char dh%d_g[]={",uVar11);
    local_38 = 0;
    if (0 < iVar14) {
      do {
        if (local_38 == ((int)local_38 / 0xc) * 0xc) {
          (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_006345a4);
        }
        (*(code *)PTR___printf_chk_006a99c4)(1,"0x%02X,",*(undefined *)(iVar13 + local_38));
        local_38 = local_38 + 1;
      } while ((int)local_38 < iVar14);
    }
    (*(code *)PTR_puts_006a9a54)("\n\t\t};");
    (*(code *)PTR_puts_006a9a54)("\tDH *dh;\n");
    (*(code *)PTR_puts_006a9a54)("\tif ((dh=DH_new()) == NULL) return(NULL);");
    (*(code *)PTR___printf_chk_006a99c4)
              (1,"\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",uVar11,uVar11);
    (*(code *)PTR___printf_chk_006a99c4)
              (1,"\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",uVar11,uVar11);
    (*(code *)PTR_puts_006a9a54)("\tif ((dh->p == NULL) || (dh->g == NULL))");
    (*(code *)PTR_puts_006a9a54)("\t\t{ DH_free(dh); return(NULL); }");
    if (param_2[4] != (char *)0x0) {
      (*(code *)PTR___printf_chk_006a99c4)(1,"\tdh->length = %ld;\n");
    }
    (*(code *)PTR_puts_006a9a54)("\treturn(dh);\n\t}");
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar13);
  }
  if (!bVar6) {
    if (iVar17 == 1) {
      local_38 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_DHparams_006a7520,iVar15,param_2);
    }
    else {
      if (iVar17 != 3) {
        uVar11 = 1;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar7,"bad output format specified for outfile\n");
        goto LAB_0042a99c;
      }
      local_38 = (*(code *)PTR_PEM_write_bio_DHparams_006a7524)(iVar15,param_2);
    }
    if (local_38 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar7,"unable to write DH parameters\n");
      uVar11 = 1;
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar7);
      goto LAB_0042a99c;
    }
  }
  uVar11 = 0;
LAB_0042a99c:
  if (iVar10 != 0) {
    (*(code *)PTR_BIO_free_006a6e70)(iVar10);
  }
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar15);
  goto LAB_0042a7f8;
}

