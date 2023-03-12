
undefined4 dh_cb(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  char *pcVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  int iStack_b4;
  int iStack_a8;
  undefined4 uStack_a0;
  int iStack_98;
  int iStack_88;
  int iStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  code *pcStack_60;
  int iStack_5c;
  undefined *puStack_58;
  int iStack_54;
  undefined local_15;
  int local_14;
  
  puStack_58 = PTR___stack_chk_guard_006aabf0;
  local_15 = 0x2a;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_1 == 0) {
    local_15 = 0x2e;
  }
  else if (param_1 == 1) {
    local_15 = 0x2b;
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    local_15 = 10;
  }
  (*(code *)PTR_BIO_write_006a7f14)(*(undefined4 *)(param_3 + 4),&local_15,1);
  puVar14 = (undefined4 *)&DAT_0000000b;
  (*(code *)PTR_BIO_ctrl_006a7f18)(*(undefined4 *)(param_3 + 4),0xb,0,0);
  if (local_14 == *(int *)puStack_58) {
    return 1;
  }
  iVar18 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar8 = PTR___stack_chk_guard_006aabf0;
  puVar7 = PTR_bio_err_006a7f3c;
  iStack_6c = 0;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_54 = param_3;
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar13 = *(int *)puVar7;
  if (iVar13 == 0) {
    uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar13 = (*(code *)PTR_BIO_new_006a7fa4)(uVar9);
    *(int *)puVar7 = iVar13;
    if (iVar13 != 0) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(iVar13,0x6a,0x10,*(undefined4 *)PTR_stderr_006aac00);
      iVar13 = *(int *)puVar7;
    }
  }
  iVar13 = (*(code *)PTR_load_config_006a7f64)(iVar13,0);
  if (iVar13 == 0) goto LAB_0042a30c;
  uVar9 = *puVar14;
  iVar18 = iVar18 + -1;
  puVar11 = puVar14 + 1;
  iStack_98 = 0;
  uStack_a0 = 0;
  iVar17 = 3;
  iStack_88 = 0;
  iVar13 = 3;
  iStack_a8 = 0;
  iStack_b4 = 0;
  bVar5 = false;
  bVar6 = false;
  bVar4 = false;
  bVar2 = false;
  bVar3 = false;
  if (0 < iVar18) {
LAB_0042a15c:
    do {
      puVar14 = (undefined4 *)*puVar11;
      iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-inform");
      if (iVar10 == 0) {
        iVar18 = iVar18 + -1;
        if (iVar18 != 0) {
          iVar13 = (*(code *)PTR_str2fmt_006a7f4c)(puVar11[1]);
          puVar11 = puVar11 + 1;
          goto LAB_0042a150;
        }
LAB_0042a4f4:
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"%s [options] [numbits]\n",uVar9);
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
      iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-outform");
      if (iVar10 == 0) {
        if (iVar18 == 1) goto LAB_0042a4f4;
        iVar18 = iVar18 + -2;
        iVar17 = (*(code *)PTR_str2fmt_006a7f4c)(puVar11[1]);
        puVar14 = puVar11 + 1;
        puVar11 = puVar11 + 2;
        if (iVar18 == 0) break;
        goto LAB_0042a15c;
      }
      cVar1 = *(char *)puVar14;
      if ((((cVar1 == '-') && (*(char *)((int)puVar14 + 1) == 'i')) &&
          (*(char *)((int)puVar14 + 2) == 'n')) && (*(char *)((int)puVar14 + 3) == '\0')) {
        iVar18 = iVar18 + -1;
        if (iVar18 == 0) goto LAB_0042a4f4;
        iStack_b4 = puVar11[1];
        puVar11 = puVar11 + 1;
      }
      else {
        iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,&DAT_00632edc);
        if (iVar10 == 0) {
          iVar18 = iVar18 + -1;
          if (iVar18 == 0) goto LAB_0042a4f4;
          iStack_a8 = puVar11[1];
          puVar11 = puVar11 + 1;
        }
        else {
          iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-engine");
          if (iVar10 == 0) {
            iVar18 = iVar18 + -1;
            if (iVar18 == 0) goto LAB_0042a4f4;
            uStack_a0 = puVar11[1];
            puVar11 = puVar11 + 1;
          }
          else {
            iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-check");
            if (iVar10 == 0) {
              bVar4 = true;
            }
            else {
              iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-text");
              if (iVar10 == 0) {
                bVar3 = true;
              }
              else {
                iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-dsaparam");
                if (iVar10 == 0) {
                  bVar2 = true;
                }
                else if (cVar1 == '-') {
                  cVar1 = *(char *)((int)puVar14 + 1);
                  if ((cVar1 == 'C') && (*(char *)((int)puVar14 + 2) == '\0')) {
                    bVar5 = true;
                  }
                  else {
                    iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-noout");
                    if (iVar10 == 0) {
                      bVar6 = true;
                    }
                    else if (cVar1 == '2') {
                      if (*(char *)((int)puVar14 + 2) != '\0') {
LAB_0042a490:
                        iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-rand");
                        if (iVar10 == 0) {
                          iVar18 = iVar18 + -1;
                          if (iVar18 != 0) {
                            iStack_88 = puVar11[1];
                            puVar11 = puVar11 + 1;
                            goto LAB_0042a150;
                          }
                        }
                        else {
                          iVar10 = (*(code *)PTR___isoc99_sscanf_006aab10)(puVar14,"%d",&iStack_6c);
                          if ((iVar10 != 0) && (0 < iStack_6c)) goto LAB_0042a150;
                        }
                        goto LAB_0042a4f4;
                      }
                      iStack_98 = 2;
                    }
                    else {
                      if ((cVar1 != '5') || (*(char *)((int)puVar14 + 2) != '\0'))
                      goto LAB_0042a490;
                      iStack_98 = 5;
                    }
                  }
                }
                else {
                  iVar10 = (*(code *)PTR_strcmp_006aac20)(puVar14,"-noout");
                  if (iVar10 != 0) goto LAB_0042a490;
                  bVar6 = true;
                }
              }
            }
          }
        }
      }
LAB_0042a150:
      iVar18 = iVar18 + -1;
      puVar14 = puVar11;
      puVar11 = puVar11 + 1;
    } while (iVar18 != 0);
  }
  (*(code *)PTR_ERR_load_crypto_strings_006a7f50)();
  (*(code *)PTR_setup_engine_006a7fc4)(*(undefined4 *)puVar7,uStack_a0,0);
  if (iStack_98 == 0) {
    if (!bVar2) {
      if (iStack_6c == 0) goto LAB_0042a6d4;
      iStack_98 = 2;
      goto LAB_0042a20c;
    }
    if (iStack_6c != 0) goto LAB_0042a20c;
LAB_0042a6d4:
    uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar18 = (*(code *)PTR_BIO_new_006a7fa4)(uVar9);
    if (iVar18 == 0) goto LAB_0042a2fc;
    if (iStack_b4 != 0) {
      iVar10 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6c,3,iStack_b4);
      if (0 < iVar10) goto LAB_0042a724;
      (*(code *)PTR_perror_006aab88)(iStack_b4);
      goto LAB_0042a74c;
    }
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar18,0x6a,0,*(undefined4 *)PTR_stdin_006aab20);
LAB_0042a724:
    if (iVar13 != 1) {
      if (iVar13 == 3) {
        if (!bVar2) {
          puVar14 = (undefined4 *)(*(code *)PTR_PEM_read_bio_DHparams_006a8608)(iVar18,0,0,0);
          goto LAB_0042aa7c;
        }
        iVar13 = (*(code *)PTR_PEM_read_bio_DSAparams_006a8634)(iVar18,0,0,0);
LAB_0042a980:
        if (iVar13 != 0) {
          puVar14 = (undefined4 *)(*(code *)PTR_DSA_dup_DH_006a8638)(iVar13);
          (*(code *)PTR_DSA_free_006a862c)(iVar13);
          if (puVar14 != (undefined4 *)0x0) goto LAB_0042a9b4;
          (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
          goto LAB_0042a74c;
        }
        uVar9 = *(undefined4 *)puVar7;
        pcVar15 = "unable to load DSA parameters\n";
LAB_0042aa94:
        puVar14 = (undefined4 *)0x0;
        (*(code *)PTR_BIO_printf_006a7f38)(uVar9,pcVar15);
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      }
      else {
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"bad input format specified\n");
LAB_0042a74c:
        puVar14 = (undefined4 *)0x0;
      }
LAB_0042a750:
      (*(code *)PTR_BIO_free_006a7f70)(iVar18);
      goto LAB_0042a760;
    }
    if (bVar2) {
      iVar13 = (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                         (PTR_DSA_new_006a8624,PTR_d2i_DSAparams_006a863c,iVar18,0);
      goto LAB_0042a980;
    }
    puVar14 = (undefined4 *)
              (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                        (PTR_DH_new_006a8618,PTR_d2i_DHparams_006a8614,iVar18,0);
LAB_0042aa7c:
    if (puVar14 == (undefined4 *)0x0) {
      uVar9 = *(undefined4 *)puVar7;
      pcVar15 = "unable to load DH parameters\n";
      goto LAB_0042aa94;
    }
LAB_0042a9b4:
    uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar13 = (*(code *)PTR_BIO_new_006a7fa4)(uVar9);
    if (iVar13 == 0) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      goto LAB_0042a750;
    }
  }
  else {
    if (iStack_6c == 0) {
      iStack_6c = 0x200;
    }
    if (bVar2) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar7,"generator may not be chosen for DSA parameters\n");
      goto LAB_0042a30c;
    }
LAB_0042a20c:
    uStack_64 = *(undefined4 *)puVar7;
    uStack_68 = 2;
    pcStack_60 = dh_cb;
    iVar18 = (*(code *)PTR_app_RAND_load_file_006a7fcc)(0,uStack_64,1);
    if (iVar18 == 0) {
      if (iStack_88 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)PTR_bio_err_006a7f3c,
                   "warning, not much extra random data, consider using the -rand option\n");
      }
      else {
LAB_0042a250:
        uVar16 = *(undefined4 *)puVar7;
        uVar9 = (*(code *)PTR_app_RAND_load_files_006a8038)(iStack_88);
        (*(code *)PTR_BIO_printf_006a7f38)(uVar16,"%ld semi-random bytes loaded\n",uVar9);
      }
    }
    else if (iStack_88 != 0) goto LAB_0042a250;
    if (bVar2) {
      puVar11 = (undefined4 *)(*(code *)PTR_DSA_new_006a8624)();
      (*(code *)PTR_BIO_printf_006a7f38)
                (*(undefined4 *)puVar7,"Generating DSA parameters, %d bit long prime\n",iStack_6c);
      puVar14 = puVar11;
      if (puVar11 != (undefined4 *)0x0) {
        iVar18 = (*(code *)PTR_DSA_generate_parameters_ex_006a8628)
                           (puVar11,iStack_6c,0,0,0,0,&uStack_68);
        if (iVar18 != 0) {
          puVar14 = (undefined4 *)(*(code *)PTR_DSA_dup_DH_006a8638)(puVar11);
          (*(code *)PTR_DSA_free_006a862c)(puVar11);
          if (puVar14 == (undefined4 *)0x0) {
            (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
            goto LAB_0042a30c;
          }
          goto LAB_0042a848;
        }
        (*(code *)PTR_DSA_free_006a862c)(puVar11);
      }
LAB_0042a2fc:
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
LAB_0042a30c:
      uVar9 = 1;
      while (iStack_5c != *(int *)puVar8) {
        (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0042b138:
        uVar9 = 1;
        (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
LAB_0042a768:
        (*(code *)PTR_DH_free_006a8604)(puVar14);
      }
      return uVar9;
    }
    puVar14 = (undefined4 *)(*(code *)PTR_DH_new_006a8618)();
    (*(code *)PTR_BIO_printf_006a7f38)
              (*(undefined4 *)puVar7,
               "Generating DH parameters, %d bit long safe prime, generator %d\n",iStack_6c,
               iStack_98);
    (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"This is going to take a long time\n");
    if ((puVar14 == (undefined4 *)0x0) ||
       (iVar18 = (*(code *)PTR_DH_generate_parameters_ex_006a8630)
                           (puVar14,iStack_6c,iStack_98,&uStack_68), iVar18 == 0)) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
LAB_0042a760:
      uVar9 = 1;
      if (puVar14 != (undefined4 *)0x0) goto LAB_0042a768;
      goto LAB_0042a30c;
    }
LAB_0042a848:
    (*(code *)PTR_app_RAND_write_file_006a804c)(0,*(undefined4 *)puVar7);
    uVar9 = (*(code *)PTR_BIO_s_file_006a7fa0)();
    iVar13 = (*(code *)PTR_BIO_new_006a7fa4)(uVar9);
    if (iVar13 == 0) goto LAB_0042b138;
    iVar18 = 0;
  }
  if (iStack_a8 == 0) {
    (*(code *)PTR_BIO_ctrl_006a7f18)(iVar13,0x6a,0,*(undefined4 *)PTR_stdout_006aaad4);
  }
  else {
    iVar10 = (*(code *)PTR_BIO_ctrl_006a7f18)(iVar13,0x6c,5,iStack_a8);
    if (iVar10 < 1) {
      uVar9 = 1;
      (*(code *)PTR_perror_006aab88)(iStack_a8);
      goto LAB_0042a90c;
    }
  }
  if (bVar3) {
    (*(code *)PTR_DHparams_print_006a860c)(iVar13,puVar14);
  }
  if (bVar4) {
    iVar10 = (*(code *)PTR_DH_check_006a8610)(puVar14,&uStack_68);
    if (iVar10 == 0) {
      uVar9 = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      goto LAB_0042a90c;
    }
    if ((uStack_68 & 1) != 0) {
      (*(code *)PTR_puts_006aab60)("p value is not prime");
    }
    if ((uStack_68 & 2) != 0) {
      (*(code *)PTR_puts_006aab60)("p value is not a safe prime");
    }
    if ((uStack_68 & 4) != 0) {
      (*(code *)PTR_puts_006aab60)("unable to check the generator value");
    }
    if ((uStack_68 & 8) != 0) {
      (*(code *)PTR_puts_006aab60)("the g value is not a generator");
    }
    if (uStack_68 == 0) {
      (*(code *)PTR_puts_006aab60)("DH parameters appear to be ok.");
    }
  }
  if (bVar5) {
    iVar12 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar14[2]);
    uVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar14[2]);
    iVar10 = iVar12 + 7;
    if (iVar12 + 7 < 0) {
      iVar10 = iVar12 + 0xe;
    }
    iVar10 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar10 >> 3,"dhparam.c",0x1d2);
    if (iVar10 == 0) {
      uVar9 = 1;
      (*(code *)PTR_perror_006aab88)("OPENSSL_malloc");
      goto LAB_0042a90c;
    }
    (*(code *)PTR_puts_006aab60)("#ifndef HEADER_DH_H\n#include <openssl/dh.h>\n#endif");
    (*(code *)PTR___printf_chk_006aaad0)(1,"DH *get_dh%d()\n\t{\n",uVar9);
    iVar12 = (*(code *)PTR_BN_bn2bin_006a8300)(puVar14[2],iVar10);
    (*(code *)PTR___printf_chk_006aaad0)(1,"\tstatic unsigned char dh%d_p[]={",uVar9);
    uStack_68 = 0;
    if (0 < iVar12) {
      do {
        if (uStack_68 == ((int)uStack_68 / 0xc) * 0xc) {
          (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00634efc);
        }
        (*(code *)PTR___printf_chk_006aaad0)(1,"0x%02X,",*(undefined *)(iVar10 + uStack_68));
        uStack_68 = uStack_68 + 1;
      } while ((int)uStack_68 < iVar12);
    }
    (*(code *)PTR_puts_006aab60)("\n\t\t};");
    iVar12 = (*(code *)PTR_BN_bn2bin_006a8300)(puVar14[3],iVar10);
    (*(code *)PTR___printf_chk_006aaad0)(1,"\tstatic unsigned char dh%d_g[]={",uVar9);
    uStack_68 = 0;
    if (0 < iVar12) {
      do {
        if (uStack_68 == ((int)uStack_68 / 0xc) * 0xc) {
          (*(code *)PTR___printf_chk_006aaad0)(1,&DAT_00634efc);
        }
        (*(code *)PTR___printf_chk_006aaad0)(1,"0x%02X,",*(undefined *)(iVar10 + uStack_68));
        uStack_68 = uStack_68 + 1;
      } while ((int)uStack_68 < iVar12);
    }
    (*(code *)PTR_puts_006aab60)("\n\t\t};");
    (*(code *)PTR_puts_006aab60)("\tDH *dh;\n");
    (*(code *)PTR_puts_006aab60)("\tif ((dh=DH_new()) == NULL) return(NULL);");
    (*(code *)PTR___printf_chk_006aaad0)
              (1,"\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",uVar9,uVar9);
    (*(code *)PTR___printf_chk_006aaad0)
              (1,"\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",uVar9,uVar9);
    (*(code *)PTR_puts_006aab60)("\tif ((dh->p == NULL) || (dh->g == NULL))");
    (*(code *)PTR_puts_006aab60)("\t\t{ DH_free(dh); return(NULL); }");
    if (puVar14[4] != 0) {
      (*(code *)PTR___printf_chk_006aaad0)(1,"\tdh->length = %ld;\n");
    }
    (*(code *)PTR_puts_006aab60)("\treturn(dh);\n\t}");
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar10);
  }
  if (!bVar6) {
    if (iVar17 == 1) {
      uStack_68 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_DHparams_006a861c,iVar13,puVar14);
    }
    else {
      if (iVar17 != 3) {
        uVar9 = 1;
        (*(code *)PTR_BIO_printf_006a7f38)
                  (*(undefined4 *)puVar7,"bad output format specified for outfile\n");
        goto LAB_0042a90c;
      }
      uStack_68 = (*(code *)PTR_PEM_write_bio_DHparams_006a8620)(iVar13,puVar14);
    }
    if (uStack_68 == 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar7,"unable to write DH parameters\n");
      uVar9 = 1;
      (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar7);
      goto LAB_0042a90c;
    }
  }
  uVar9 = 0;
LAB_0042a90c:
  if (iVar18 != 0) {
    (*(code *)PTR_BIO_free_006a7f70)(iVar18);
  }
  (*(code *)PTR_BIO_free_all_006a7f74)(iVar13);
  goto LAB_0042a768;
}

