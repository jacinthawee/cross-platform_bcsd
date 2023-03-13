
undefined4 dsa_cb(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  undefined *puVar13;
  int iVar14;
  undefined4 *puVar15;
  char *pcVar16;
  char **ppcVar17;
  char *pcVar18;
  undefined *puVar19;
  char *unaff_s3;
  undefined4 uVar20;
  int iVar21;
  int iVar22;
  char **ppcVar23;
  char *pcStack_b0;
  char *pcStack_a4;
  char *pcStack_9c;
  int iStack_80;
  char *pcStack_74;
  int iStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  code *pcStack_60;
  int iStack_5c;
  undefined *puStack_58;
  int iStack_54;
  undefined local_15;
  int local_14;
  
  puStack_58 = PTR___stack_chk_guard_006a9ae8;
  local_15 = 0x2a;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_1 == 0) {
    local_15 = 0x2e;
  }
  else if (param_1 == 1) {
    local_15 = 0x2b;
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    local_15 = 10;
  }
  (*(code *)PTR_BIO_write_006a6e14)(*(undefined4 *)(param_3 + 4),&local_15,1);
  pcVar16 = (char *)0x0;
  puVar15 = (undefined4 *)&DAT_0000000b;
  (*(code *)PTR_BIO_ctrl_006a6e18)(*(undefined4 *)(param_3 + 4),0xb,0,0);
  if (local_14 == *(int *)puStack_58) {
    return 1;
  }
  iVar22 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar9 = PTR___stack_chk_guard_006a9ae8;
  puVar8 = PTR_bio_err_006a6e3c;
  iStack_5c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_54 = param_3;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar14 = *(int *)puVar8;
  if (iVar14 == 0) {
    uVar10 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar14 = (*(code *)PTR_BIO_new_006a6ea4)(uVar10);
    *(int *)puVar8 = iVar14;
    if (iVar14 != 0) {
      pcVar16 = *(char **)PTR_stderr_006a9af8;
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar14,0x6a,0x10,pcVar16);
      iVar14 = *(int *)puVar8;
    }
  }
  iVar14 = (*(code *)PTR_load_config_006a6e64)(iVar14,0);
  if (iVar14 == 0) {
LAB_00439c4c:
    uVar10 = 1;
  }
  else {
    uVar10 = *puVar15;
    iVar22 = iVar22 + -1;
    ppcVar23 = (char **)(puVar15 + 1);
    pcStack_9c = (char *)0x0;
    bVar3 = false;
    iVar21 = 3;
    bVar7 = false;
    iVar14 = 3;
    pcStack_74 = (char *)0x0;
    pcStack_a4 = (char *)0x0;
    iStack_80 = -1;
    pcStack_b0 = (char *)0x0;
    bVar5 = false;
    bVar6 = false;
    bVar4 = false;
    if (0 < iVar22) {
      unaff_s3 = "-outform";
LAB_0043994c:
      do {
        pcVar18 = *ppcVar23;
        iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar18,"-inform");
        if (iVar11 == 0) {
          iVar22 = iVar22 + -1;
          if (iVar22 != 0) {
            ppcVar17 = ppcVar23 + 1;
            iVar14 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar23[1]);
            goto LAB_00439940;
          }
LAB_00439b10:
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8,"%s [options] [bits] <infile >outfile\n",uVar10);
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"where options are\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8," -inform arg   input format - DER or PEM\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8," -outform arg  output format - DER or PEM\n");
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8," -in arg       input file\n");
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8," -out arg      output file\n");
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8," -text         print as text\n")
          ;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8," -C            Output C code\n")
          ;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8," -noout        no output\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8," -genkey       generate a DSA key\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8," -rand         files to use for random number input\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8,
                     " -engine e     use engine e, possibly a hardware device.\n");
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar8,
                     " number        number of bits to use for generating private key\n");
          goto LAB_00439c4c;
        }
        iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar18,"-outform");
        if (iVar11 == 0) {
          if (iVar22 == 1) goto LAB_00439b10;
          ppcVar17 = ppcVar23 + 1;
          iVar22 = iVar22 + -2;
          ppcVar23 = ppcVar23 + 2;
          iVar21 = (*(code *)PTR_str2fmt_006a6e4c)(*ppcVar17);
          if (iVar22 == 0) break;
          goto LAB_0043994c;
        }
        cVar1 = *pcVar18;
        if ((((cVar1 == '-') && (pcVar18[1] == 'i')) && (pcVar18[2] == 'n')) && (pcVar18[3] == '\0')
           ) {
          iVar22 = iVar22 + -1;
          if (iVar22 == 0) goto LAB_00439b10;
          pcStack_b0 = ppcVar23[1];
          ppcVar17 = ppcVar23 + 1;
        }
        else {
          iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar18,&DAT_00632514);
          if (iVar11 == 0) {
            iVar22 = iVar22 + -1;
            if (iVar22 == 0) goto LAB_00439b10;
            pcStack_a4 = ppcVar23[1];
            ppcVar17 = ppcVar23 + 1;
          }
          else {
            iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar18,"-engine");
            if (iVar11 == 0) {
              iVar22 = iVar22 + -1;
              if (iVar22 == 0) goto LAB_00439b10;
              pcStack_9c = ppcVar23[1];
              ppcVar17 = ppcVar23 + 1;
            }
            else {
              iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar18,"-text");
              ppcVar17 = ppcVar23;
              if (iVar11 == 0) {
                bVar4 = true;
              }
              else if (((cVar1 == '-') && (pcVar18[1] == 'C')) && (pcVar18[2] == '\0')) {
                bVar5 = true;
              }
              else {
                iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar18,"-genkey");
                if (iVar11 == 0) {
                  bVar3 = true;
                  bVar7 = true;
                }
                else {
                  iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar18,"-rand");
                  if (iVar11 == 0) {
                    iVar22 = iVar22 + -1;
                    if (iVar22 == 0) goto LAB_00439b10;
                    pcStack_74 = ppcVar23[1];
                    bVar3 = true;
                    ppcVar17 = ppcVar23 + 1;
                  }
                  else {
                    iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar18,"-noout");
                    if (iVar11 == 0) {
                      bVar6 = true;
                    }
                    else {
                      iVar11 = (*(code *)PTR___isoc99_sscanf_006a9a04)(pcVar18,"%d",&iStack_6c);
                      if (iVar11 != 1) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar8,"unknown option %s\n",*ppcVar23);
                        goto LAB_00439b10;
                      }
                      iStack_80 = iStack_6c;
                      bVar3 = true;
                    }
                  }
                }
              }
            }
          }
        }
LAB_00439940:
        iVar22 = iVar22 + -1;
        ppcVar23 = ppcVar17 + 1;
      } while (iVar22 != 0);
    }
    (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
    uVar10 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar22 = (*(code *)PTR_BIO_new_006a6ea4)(uVar10);
    uVar10 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar11 = (*(code *)PTR_BIO_new_006a6ea4)(uVar10);
    if (iVar22 == 0) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar8);
      if (iVar11 == 0) goto LAB_00439c4c;
      unaff_s3 = (char *)0x0;
      uVar10 = 1;
LAB_00439acc:
      (*(code *)PTR_BIO_free_all_006a6e74)(iVar11);
    }
    else {
      if (iVar11 == 0) {
        unaff_s3 = (char *)0x0;
        uVar10 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar8);
        goto LAB_00439ab8;
      }
      if (pcStack_b0 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar22,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
      }
      else {
        pcVar16 = pcStack_b0;
        iVar12 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar22,0x6c,3,pcStack_b0);
        if (iVar12 < 1) {
          uVar10 = 1;
          unaff_s3 = (char *)0x0;
          (*(code *)PTR_perror_006a9a80)(pcStack_b0);
          goto LAB_00439ab8;
        }
      }
      if (pcStack_a4 == (char *)0x0) {
        pcVar16 = *(char **)PTR_stdout_006a99c8;
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar11,0x6a,0,pcVar16);
      }
      else {
        pcVar16 = pcStack_a4;
        iVar12 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar11,0x6c,5,pcStack_a4);
        if (iVar12 < 1) {
          uVar10 = 1;
          unaff_s3 = (char *)0x0;
          (*(code *)PTR_perror_006a9a80)(pcStack_a4);
          goto LAB_00439ab8;
        }
      }
      unaff_s3 = PTR_bio_err_006a6e3c;
      (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar8,pcStack_9c,0);
      if (bVar3) {
        (*(code *)PTR_app_RAND_load_file_006a6ecc)
                  (0,*(undefined4 *)unaff_s3,pcStack_74 != (char *)0x0);
        if (pcStack_74 != (char *)0x0) {
          uVar20 = *(undefined4 *)unaff_s3;
          uVar10 = (*(code *)PTR_app_RAND_load_files_006a6f38)(pcStack_74);
          (*(code *)PTR_BIO_printf_006a6e38)(uVar20,"%ld semi-random bytes loaded\n",uVar10);
        }
        puVar13 = PTR_bio_err_006a6e3c;
        if (iStack_80 < 1) goto LAB_00439a88;
        uStack_64 = *(undefined4 *)puVar8;
        uStack_68 = 2;
        pcStack_60 = dsa_cb;
        unaff_s3 = (char *)(*(code *)PTR_DSA_new_006a7528)();
        if ((undefined4 *)unaff_s3 == (undefined4 *)0x0) {
          uVar10 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"Error allocating DSA object\n")
          ;
          goto LAB_00439ab8;
        }
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar13,"Generating DSA parameters, %d bit long prime\n",iStack_6c
                  );
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar13,"This could take some time\n");
        pcVar16 = (char *)0x0;
        iVar14 = (*(code *)PTR_DSA_generate_parameters_ex_006a752c)
                           (unaff_s3,iStack_6c,0,0,0,0,&uStack_68);
        if (iVar14 == 0) {
          uVar10 = 1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar13);
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar13,"Error, DSA key generation failed\n");
          goto LAB_00439ab8;
        }
LAB_00439ff8:
        if (bVar4) {
          (*(code *)PTR_DSAparams_print_006a7674)(iVar11,unaff_s3);
        }
        if (bVar5) {
          iVar12 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)((int)unaff_s3 + 0xc));
          pcVar18 = (char *)(*(code *)PTR_BN_num_bits_006a71f4)
                                      (*(undefined4 *)((int)unaff_s3 + 0xc));
          iVar14 = iVar12 + 7;
          if (iVar12 + 7 < 0) {
            iVar14 = iVar12 + 0xe;
          }
          puVar13 = (undefined *)
                    (*(code *)PTR_CRYPTO_malloc_006a7008)((iVar14 >> 3) + 0x14,"dsaparam.c",0x155);
          if (puVar13 == (undefined *)0x0) {
            uVar10 = 1;
            (*(code *)PTR_perror_006a9a80)("OPENSSL_malloc");
            goto LAB_00439ab8;
          }
          iVar14 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)unaff_s3 + 0xc),puVar13);
          (*(code *)PTR___printf_chk_006a99c4)(1,"static unsigned char dsa%d_p[]={",pcVar18);
          if (0 < iVar14) {
            iVar12 = 0;
            puVar19 = puVar13;
            do {
              if (iVar12 == (iVar12 / 0xc) * 0xc) {
                (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_006340fc);
              }
              uVar2 = *puVar19;
              iVar12 = iVar12 + 1;
              puVar19 = puVar19 + 1;
              (*(code *)PTR___printf_chk_006a99c4)(1,"0x%02X,",uVar2);
            } while (iVar14 != iVar12);
          }
          (*(code *)PTR_puts_006a9a54)(&DAT_006340d4);
          iVar14 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)unaff_s3 + 0x10),puVar13);
          (*(code *)PTR___printf_chk_006a99c4)(1,"static unsigned char dsa%d_q[]={",pcVar18);
          if (0 < iVar14) {
            iVar12 = 0;
            puVar19 = puVar13;
            do {
              if (iVar12 == (iVar12 / 0xc) * 0xc) {
                (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_006340fc);
              }
              uVar2 = *puVar19;
              iVar12 = iVar12 + 1;
              puVar19 = puVar19 + 1;
              (*(code *)PTR___printf_chk_006a99c4)(1,"0x%02X,",uVar2);
            } while (iVar14 != iVar12);
          }
          (*(code *)PTR_puts_006a9a54)(&DAT_006340d4);
          iVar14 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)unaff_s3 + 0x14),puVar13);
          (*(code *)PTR___printf_chk_006a99c4)(1,"static unsigned char dsa%d_g[]={",pcVar18);
          if (0 < iVar14) {
            iVar12 = 0;
            do {
              if (iVar12 == (iVar12 / 0xc) * 0xc) {
                (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_006340fc);
              }
              uVar2 = *puVar13;
              iVar12 = iVar12 + 1;
              puVar13 = puVar13 + 1;
              (*(code *)PTR___printf_chk_006a99c4)(1,"0x%02X,",uVar2);
            } while (iVar14 != iVar12);
          }
          (*(code *)PTR_puts_006a9a54)("\n\t};\n");
          (*(code *)PTR___printf_chk_006a99c4)(1,"DSA *get_dsa%d()\n\t{\n",pcVar18);
          (*(code *)PTR_puts_006a9a54)("\tDSA *dsa;\n");
          (*(code *)PTR_puts_006a9a54)("\tif ((dsa=DSA_new()) == NULL) return(NULL);");
          (*(code *)PTR___printf_chk_006a99c4)
                    (1,"\tdsa->p=BN_bin2bn(dsa%d_p,sizeof(dsa%d_p),NULL);\n",pcVar18,pcVar18);
          (*(code *)PTR___printf_chk_006a99c4)
                    (1,"\tdsa->q=BN_bin2bn(dsa%d_q,sizeof(dsa%d_q),NULL);\n",pcVar18,pcVar18);
          (*(code *)PTR___printf_chk_006a99c4)
                    (1,"\tdsa->g=BN_bin2bn(dsa%d_g,sizeof(dsa%d_g),NULL);\n",pcVar18,pcVar18);
          (*(code *)PTR_puts_006a9a54)
                    ("\tif ((dsa->p == NULL) || (dsa->q == NULL) || (dsa->g == NULL))");
          (*(code *)PTR_puts_006a9a54)("\t\t{ DSA_free(dsa); return(NULL); }");
          (*(code *)PTR_puts_006a9a54)("\treturn(dsa);\n\t}");
          pcVar16 = pcVar18;
        }
        if (!bVar6) {
          if (iVar21 == 1) {
            iVar14 = (*(code *)PTR_ASN1_i2d_bio_006a7198)
                               (PTR_i2d_DSAparams_006a7684,iVar11,unaff_s3);
          }
          else {
            if (iVar21 != 3) {
              uVar10 = 1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar8,"bad output format specified for outfile\n");
              goto LAB_00439ab8;
            }
            iVar14 = (*(code *)PTR_PEM_write_bio_DSAparams_006a7680)(iVar11,unaff_s3);
          }
          if (iVar14 == 0) {
            uVar10 = *(undefined4 *)puVar8;
            pcVar18 = "unable to write DSA parameters\n";
            goto LAB_0043a0fc;
          }
        }
        if (bVar7) {
          if (!bVar3) {
            uVar10 = (*(code *)PTR___assert_fail_006a993c)
                               ("need_rand","dsaparam.c",0x196,"dsaparam_main");
            return uVar10;
          }
          iVar14 = (*(code *)PTR_DSAparams_dup_006a7678)(unaff_s3);
          if (iVar14 == 0) goto LAB_0043a118;
          iVar12 = (*(code *)PTR_DSA_generate_key_006a767c)(iVar14);
          if (iVar12 != 0) {
            if (iVar21 == 1) {
              (*(code *)PTR_i2d_DSAPrivateKey_bio_006a766c)(iVar11,iVar14);
            }
            else {
              if (iVar21 != 3) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar8,"bad output format specified for outfile\n");
                goto LAB_0043a0ac;
              }
              pcVar16 = (char *)0x0;
              (*(code *)PTR_PEM_write_bio_DSAPrivateKey_006a7670)(iVar11,iVar14,0,0,0,0,0);
            }
            (*(code *)PTR_DSA_free_006a7530)(iVar14);
            goto LAB_0043a670;
          }
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar8);
LAB_0043a0ac:
          uVar10 = 1;
          (*(code *)PTR_DSA_free_006a7530)(iVar14);
        }
        else if (bVar3) {
LAB_0043a670:
          uVar10 = 0;
          (*(code *)PTR_app_RAND_write_file_006a6f4c)(0,*(undefined4 *)puVar8);
        }
        else {
          uVar10 = 0;
        }
      }
      else {
        pcVar16 = "-check_ss_sig";
        if (0 < iStack_80) goto LAB_0043a724;
LAB_00439a88:
        if (iVar14 == 1) {
          pcVar16 = (char *)0x0;
          unaff_s3 = (char *)(*(code *)PTR_ASN1_d2i_bio_006a71c4)
                                       (PTR_DSA_new_006a7528,PTR_d2i_DSAparams_006a7540,iVar22,0);
LAB_0043a0e4:
          if ((undefined4 *)unaff_s3 != (undefined4 *)0x0) goto LAB_00439ff8;
          uVar10 = *(undefined4 *)puVar8;
          pcVar18 = "unable to load DSA parameters\n";
LAB_0043a0fc:
          (*(code *)PTR_BIO_printf_006a6e38)(uVar10,pcVar18);
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar8);
LAB_0043a118:
          uVar10 = 1;
        }
        else {
          if (iVar14 == 3) {
            pcVar16 = (char *)0x0;
            unaff_s3 = (char *)(*(code *)PTR_PEM_read_bio_DSAparams_006a7538)(iVar22,0,0,0);
            goto LAB_0043a0e4;
          }
          unaff_s3 = (char *)0x0;
          uVar10 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"bad input format specified\n");
        }
      }
LAB_00439ab8:
      (*(code *)PTR_BIO_free_006a6e70)(iVar22);
      if (iVar11 != 0) goto LAB_00439acc;
    }
    if ((undefined4 *)unaff_s3 != (undefined4 *)0x0) {
      (*(code *)PTR_DSA_free_006a7530)(unaff_s3);
    }
  }
  if (iStack_5c == *(int *)puVar9) {
    return uVar10;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0043a724:
  uStack_64 = *(undefined4 *)unaff_s3;
  uStack_68 = 2;
  pcStack_60 = dsa_cb;
  uVar10 = (*(code *)PTR___assert_fail_006a993c)("need_rand","dsaparam.c",0x118,pcVar16 + -32000);
  return uVar10;
}

