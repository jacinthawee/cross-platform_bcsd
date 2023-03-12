
undefined4 dsaparam_main(int param_1,undefined4 *param_2,undefined4 param_3,char *param_4)

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
  int iVar13;
  undefined *puVar14;
  int iVar15;
  char **ppcVar16;
  char *pcVar17;
  undefined *puVar18;
  char *unaff_s3;
  undefined4 uVar19;
  int iVar20;
  char **ppcVar21;
  char *local_80;
  char *local_74;
  char *local_6c;
  int local_50;
  char *local_44;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  code *local_30;
  int local_2c;
  
  puVar9 = PTR___stack_chk_guard_006a9ae8;
  puVar8 = PTR_bio_err_006a6e3c;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar15 = *(int *)puVar8;
  if (iVar15 == 0) {
    uVar10 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar15 = (*(code *)PTR_BIO_new_006a6ea4)(uVar10);
    *(int *)puVar8 = iVar15;
    if (iVar15 != 0) {
      param_4 = *(char **)PTR_stderr_006a9af8;
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar15,0x6a,0x10,param_4);
      iVar15 = *(int *)puVar8;
    }
  }
  iVar15 = (*(code *)PTR_load_config_006a6e64)(iVar15,0);
  if (iVar15 == 0) {
LAB_00439c4c:
    uVar10 = 1;
  }
  else {
    uVar10 = *param_2;
    param_1 = param_1 + -1;
    ppcVar21 = (char **)(param_2 + 1);
    local_6c = (char *)0x0;
    bVar3 = false;
    iVar20 = 3;
    bVar7 = false;
    iVar15 = 3;
    local_44 = (char *)0x0;
    local_74 = (char *)0x0;
    local_50 = -1;
    local_80 = (char *)0x0;
    bVar5 = false;
    bVar6 = false;
    bVar4 = false;
    if (0 < param_1) {
      unaff_s3 = "-outform";
LAB_0043994c:
      do {
        pcVar17 = *ppcVar21;
        iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar17,"-inform");
        if (iVar11 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            ppcVar16 = ppcVar21 + 1;
            iVar15 = (*(code *)PTR_str2fmt_006a6e4c)(ppcVar21[1]);
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
        iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar17,"-outform");
        if (iVar11 == 0) {
          if (param_1 == 1) goto LAB_00439b10;
          ppcVar16 = ppcVar21 + 1;
          param_1 = param_1 + -2;
          ppcVar21 = ppcVar21 + 2;
          iVar20 = (*(code *)PTR_str2fmt_006a6e4c)(*ppcVar16);
          if (param_1 == 0) break;
          goto LAB_0043994c;
        }
        cVar1 = *pcVar17;
        if ((((cVar1 == '-') && (pcVar17[1] == 'i')) && (pcVar17[2] == 'n')) && (pcVar17[3] == '\0')
           ) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00439b10;
          local_80 = ppcVar21[1];
          ppcVar16 = ppcVar21 + 1;
        }
        else {
          iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar17,&DAT_00632514);
          if (iVar11 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00439b10;
            local_74 = ppcVar21[1];
            ppcVar16 = ppcVar21 + 1;
          }
          else {
            iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar17,"-engine");
            if (iVar11 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00439b10;
              local_6c = ppcVar21[1];
              ppcVar16 = ppcVar21 + 1;
            }
            else {
              iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar17,"-text");
              ppcVar16 = ppcVar21;
              if (iVar11 == 0) {
                bVar4 = true;
              }
              else if (((cVar1 == '-') && (pcVar17[1] == 'C')) && (pcVar17[2] == '\0')) {
                bVar5 = true;
              }
              else {
                iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar17,"-genkey");
                if (iVar11 == 0) {
                  bVar3 = true;
                  bVar7 = true;
                }
                else {
                  iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar17,"-rand");
                  if (iVar11 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_00439b10;
                    local_44 = ppcVar21[1];
                    bVar3 = true;
                    ppcVar16 = ppcVar21 + 1;
                  }
                  else {
                    iVar11 = (*(code *)PTR_strcmp_006a9b18)(pcVar17,"-noout");
                    if (iVar11 == 0) {
                      bVar6 = true;
                    }
                    else {
                      iVar11 = (*(code *)PTR___isoc99_sscanf_006a9a04)(pcVar17,"%d",&local_3c);
                      if (iVar11 != 1) {
                        (*(code *)PTR_BIO_printf_006a6e38)
                                  (*(undefined4 *)puVar8,"unknown option %s\n",*ppcVar21);
                        goto LAB_00439b10;
                      }
                      local_50 = local_3c;
                      bVar3 = true;
                    }
                  }
                }
              }
            }
          }
        }
LAB_00439940:
        param_1 = param_1 + -1;
        ppcVar21 = ppcVar16 + 1;
      } while (param_1 != 0);
    }
    (*(code *)PTR_ERR_load_crypto_strings_006a6e50)();
    uVar10 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar11 = (*(code *)PTR_BIO_new_006a6ea4)(uVar10);
    uVar10 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar12 = (*(code *)PTR_BIO_new_006a6ea4)(uVar10);
    if (iVar11 == 0) {
      (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar8);
      if (iVar12 == 0) goto LAB_00439c4c;
      unaff_s3 = (char *)0x0;
      uVar10 = 1;
LAB_00439acc:
      (*(code *)PTR_BIO_free_all_006a6e74)(iVar12);
    }
    else {
      if (iVar12 == 0) {
        unaff_s3 = (char *)0x0;
        uVar10 = 1;
        (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar8);
        goto LAB_00439ab8;
      }
      if (local_80 == (char *)0x0) {
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar11,0x6a,0,*(undefined4 *)PTR_stdin_006a9a14);
      }
      else {
        param_4 = local_80;
        iVar13 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar11,0x6c,3,local_80);
        if (iVar13 < 1) {
          uVar10 = 1;
          unaff_s3 = (char *)0x0;
          (*(code *)PTR_perror_006a9a80)(local_80);
          goto LAB_00439ab8;
        }
      }
      if (local_74 == (char *)0x0) {
        param_4 = *(char **)PTR_stdout_006a99c8;
        (*(code *)PTR_BIO_ctrl_006a6e18)(iVar12,0x6a,0,param_4);
      }
      else {
        param_4 = local_74;
        iVar13 = (*(code *)PTR_BIO_ctrl_006a6e18)(iVar12,0x6c,5,local_74);
        if (iVar13 < 1) {
          uVar10 = 1;
          unaff_s3 = (char *)0x0;
          (*(code *)PTR_perror_006a9a80)(local_74);
          goto LAB_00439ab8;
        }
      }
      unaff_s3 = PTR_bio_err_006a6e3c;
      (*(code *)PTR_setup_engine_006a6ec4)(*(undefined4 *)puVar8,local_6c,0);
      if (bVar3) {
        (*(code *)PTR_app_RAND_load_file_006a6ecc)
                  (0,*(undefined4 *)unaff_s3,local_44 != (char *)0x0);
        if (local_44 != (char *)0x0) {
          uVar19 = *(undefined4 *)unaff_s3;
          uVar10 = (*(code *)PTR_app_RAND_load_files_006a6f38)(local_44);
          (*(code *)PTR_BIO_printf_006a6e38)(uVar19,"%ld semi-random bytes loaded\n",uVar10);
        }
        puVar14 = PTR_bio_err_006a6e3c;
        if (local_50 < 1) goto LAB_00439a88;
        local_34 = *(undefined4 *)puVar8;
        local_38 = 2;
        local_30 = dsa_cb;
        unaff_s3 = (char *)(*(code *)PTR_DSA_new_006a7528)();
        if ((undefined4 *)unaff_s3 == (undefined4 *)0x0) {
          uVar10 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar14,"Error allocating DSA object\n")
          ;
          goto LAB_00439ab8;
        }
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)puVar14,"Generating DSA parameters, %d bit long prime\n",local_3c)
        ;
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar14,"This could take some time\n");
        param_4 = (char *)0x0;
        iVar15 = (*(code *)PTR_DSA_generate_parameters_ex_006a752c)
                           (unaff_s3,local_3c,0,0,0,0,&local_38);
        if (iVar15 == 0) {
          uVar10 = 1;
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar14);
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*(undefined4 *)puVar14,"Error, DSA key generation failed\n");
          goto LAB_00439ab8;
        }
LAB_00439ff8:
        if (bVar4) {
          (*(code *)PTR_DSAparams_print_006a7674)(iVar12,unaff_s3);
        }
        if (bVar5) {
          iVar13 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)((int)unaff_s3 + 0xc));
          pcVar17 = (char *)(*(code *)PTR_BN_num_bits_006a71f4)
                                      (*(undefined4 *)((int)unaff_s3 + 0xc));
          iVar15 = iVar13 + 7;
          if (iVar13 + 7 < 0) {
            iVar15 = iVar13 + 0xe;
          }
          puVar14 = (undefined *)
                    (*(code *)PTR_CRYPTO_malloc_006a7008)((iVar15 >> 3) + 0x14,"dsaparam.c",0x155);
          if (puVar14 == (undefined *)0x0) {
            uVar10 = 1;
            (*(code *)PTR_perror_006a9a80)("OPENSSL_malloc");
            goto LAB_00439ab8;
          }
          iVar15 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)unaff_s3 + 0xc),puVar14);
          (*(code *)PTR___printf_chk_006a99c4)(1,"static unsigned char dsa%d_p[]={",pcVar17);
          if (0 < iVar15) {
            iVar13 = 0;
            puVar18 = puVar14;
            do {
              if (iVar13 == (iVar13 / 0xc) * 0xc) {
                (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_006340fc);
              }
              uVar2 = *puVar18;
              iVar13 = iVar13 + 1;
              puVar18 = puVar18 + 1;
              (*(code *)PTR___printf_chk_006a99c4)(1,"0x%02X,",uVar2);
            } while (iVar15 != iVar13);
          }
          (*(code *)PTR_puts_006a9a54)(&DAT_006340d4);
          iVar15 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)unaff_s3 + 0x10),puVar14);
          (*(code *)PTR___printf_chk_006a99c4)(1,"static unsigned char dsa%d_q[]={",pcVar17);
          if (0 < iVar15) {
            iVar13 = 0;
            puVar18 = puVar14;
            do {
              if (iVar13 == (iVar13 / 0xc) * 0xc) {
                (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_006340fc);
              }
              uVar2 = *puVar18;
              iVar13 = iVar13 + 1;
              puVar18 = puVar18 + 1;
              (*(code *)PTR___printf_chk_006a99c4)(1,"0x%02X,",uVar2);
            } while (iVar15 != iVar13);
          }
          (*(code *)PTR_puts_006a9a54)(&DAT_006340d4);
          iVar15 = (*(code *)PTR_BN_bn2bin_006a7200)(*(undefined4 *)((int)unaff_s3 + 0x14),puVar14);
          (*(code *)PTR___printf_chk_006a99c4)(1,"static unsigned char dsa%d_g[]={",pcVar17);
          if (0 < iVar15) {
            iVar13 = 0;
            do {
              if (iVar13 == (iVar13 / 0xc) * 0xc) {
                (*(code *)PTR___printf_chk_006a99c4)(1,&DAT_006340fc);
              }
              uVar2 = *puVar14;
              iVar13 = iVar13 + 1;
              puVar14 = puVar14 + 1;
              (*(code *)PTR___printf_chk_006a99c4)(1,"0x%02X,",uVar2);
            } while (iVar15 != iVar13);
          }
          (*(code *)PTR_puts_006a9a54)("\n\t};\n");
          (*(code *)PTR___printf_chk_006a99c4)(1,"DSA *get_dsa%d()\n\t{\n",pcVar17);
          (*(code *)PTR_puts_006a9a54)("\tDSA *dsa;\n");
          (*(code *)PTR_puts_006a9a54)("\tif ((dsa=DSA_new()) == NULL) return(NULL);");
          (*(code *)PTR___printf_chk_006a99c4)
                    (1,"\tdsa->p=BN_bin2bn(dsa%d_p,sizeof(dsa%d_p),NULL);\n",pcVar17,pcVar17);
          (*(code *)PTR___printf_chk_006a99c4)
                    (1,"\tdsa->q=BN_bin2bn(dsa%d_q,sizeof(dsa%d_q),NULL);\n",pcVar17,pcVar17);
          (*(code *)PTR___printf_chk_006a99c4)
                    (1,"\tdsa->g=BN_bin2bn(dsa%d_g,sizeof(dsa%d_g),NULL);\n",pcVar17,pcVar17);
          (*(code *)PTR_puts_006a9a54)
                    ("\tif ((dsa->p == NULL) || (dsa->q == NULL) || (dsa->g == NULL))");
          (*(code *)PTR_puts_006a9a54)("\t\t{ DSA_free(dsa); return(NULL); }");
          (*(code *)PTR_puts_006a9a54)("\treturn(dsa);\n\t}");
          param_4 = pcVar17;
        }
        if (!bVar6) {
          if (iVar20 == 1) {
            iVar15 = (*(code *)PTR_ASN1_i2d_bio_006a7198)
                               (PTR_i2d_DSAparams_006a7684,iVar12,unaff_s3);
          }
          else {
            if (iVar20 != 3) {
              uVar10 = 1;
              (*(code *)PTR_BIO_printf_006a6e38)
                        (*(undefined4 *)puVar8,"bad output format specified for outfile\n");
              goto LAB_00439ab8;
            }
            iVar15 = (*(code *)PTR_PEM_write_bio_DSAparams_006a7680)(iVar12,unaff_s3);
          }
          if (iVar15 == 0) {
            uVar10 = *(undefined4 *)puVar8;
            pcVar17 = "unable to write DSA parameters\n";
            goto LAB_0043a0fc;
          }
        }
        if (bVar7) {
          if (!bVar3) {
            uVar10 = (*(code *)PTR___assert_fail_006a993c)
                               ("need_rand","dsaparam.c",0x196,"dsaparam_main");
            return uVar10;
          }
          iVar15 = (*(code *)PTR_DSAparams_dup_006a7678)(unaff_s3);
          if (iVar15 == 0) goto LAB_0043a118;
          iVar13 = (*(code *)PTR_DSA_generate_key_006a767c)(iVar15);
          if (iVar13 != 0) {
            if (iVar20 == 1) {
              (*(code *)PTR_i2d_DSAPrivateKey_bio_006a766c)(iVar12,iVar15);
            }
            else {
              if (iVar20 != 3) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar8,"bad output format specified for outfile\n");
                goto LAB_0043a0ac;
              }
              param_4 = (char *)0x0;
              (*(code *)PTR_PEM_write_bio_DSAPrivateKey_006a7670)(iVar12,iVar15,0,0,0,0,0);
            }
            (*(code *)PTR_DSA_free_006a7530)(iVar15);
            goto LAB_0043a670;
          }
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar8);
LAB_0043a0ac:
          uVar10 = 1;
          (*(code *)PTR_DSA_free_006a7530)(iVar15);
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
        param_4 = "-check_ss_sig";
        if (0 < local_50) goto LAB_0043a724;
LAB_00439a88:
        if (iVar15 == 1) {
          param_4 = (char *)0x0;
          unaff_s3 = (char *)(*(code *)PTR_ASN1_d2i_bio_006a71c4)
                                       (PTR_DSA_new_006a7528,PTR_d2i_DSAparams_006a7540,iVar11,0);
LAB_0043a0e4:
          if ((undefined4 *)unaff_s3 != (undefined4 *)0x0) goto LAB_00439ff8;
          uVar10 = *(undefined4 *)puVar8;
          pcVar17 = "unable to load DSA parameters\n";
LAB_0043a0fc:
          (*(code *)PTR_BIO_printf_006a6e38)(uVar10,pcVar17);
          (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar8);
LAB_0043a118:
          uVar10 = 1;
        }
        else {
          if (iVar15 == 3) {
            param_4 = (char *)0x0;
            unaff_s3 = (char *)(*(code *)PTR_PEM_read_bio_DSAparams_006a7538)(iVar11,0,0,0);
            goto LAB_0043a0e4;
          }
          unaff_s3 = (char *)0x0;
          uVar10 = 1;
          (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar8,"bad input format specified\n");
        }
      }
LAB_00439ab8:
      (*(code *)PTR_BIO_free_006a6e70)(iVar11);
      if (iVar12 != 0) goto LAB_00439acc;
    }
    if ((undefined4 *)unaff_s3 != (undefined4 *)0x0) {
      (*(code *)PTR_DSA_free_006a7530)(unaff_s3);
    }
  }
  if (local_2c == *(int *)puVar9) {
    return uVar10;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0043a724:
  local_34 = *(undefined4 *)unaff_s3;
  local_38 = 2;
  local_30 = dsa_cb;
  uVar10 = (*(code *)PTR___assert_fail_006a993c)("need_rand","dsaparam.c",0x118,param_4 + -32000);
  return uVar10;
}

