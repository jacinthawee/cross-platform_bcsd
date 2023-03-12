
undefined4 dhparam_main(int param_1,byte **param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  DSA *pDVar11;
  BIO_METHOD *pBVar12;
  BIO *bp;
  long lVar13;
  int iVar14;
  uint uVar15;
  uchar *to;
  uint uVar16;
  DH *dh;
  byte **ppbVar17;
  BIO *bp_00;
  byte *pbVar18;
  byte *pbVar19;
  int in_GS_OFFSET;
  bool bVar20;
  bool bVar21;
  byte bVar22;
  char *format;
  uint local_74;
  int local_70;
  byte *local_68;
  byte *local_64;
  byte *local_60;
  int local_58;
  byte *local_4c;
  int local_30;
  BN_GENCB local_2c;
  int local_20;
  
  bVar22 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30 = 0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar12 = BIO_s_file();
    bio_err = BIO_new(pBVar12);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar9 = load_config(bio_err,0);
  if (iVar9 != 0) {
    pbVar2 = *param_2;
    local_58 = 0;
    local_60 = (byte *)0x0;
    local_4c = (byte *)0x0;
    local_64 = (byte *)0x0;
    local_68 = (byte *)0x0;
    bVar7 = false;
    bVar8 = false;
    bVar6 = false;
    local_70 = 3;
    param_1 = param_1 + -1;
    local_74 = 3;
    bVar4 = false;
    bVar5 = false;
    bVar20 = param_1 == 0;
    if (0 < param_1) {
      do {
        ppbVar17 = param_2 + 1;
        pbVar3 = *ppbVar17;
        iVar9 = 8;
        pbVar18 = pbVar3;
        pbVar19 = (byte *)"-inform";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar20 = *pbVar18 == *pbVar19;
          pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
          pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
        } while (bVar20);
        if (bVar20) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_08053248;
          ppbVar17 = param_2 + 2;
          local_74 = str2fmt(param_2[2]);
        }
        else {
          iVar9 = 9;
          pbVar18 = pbVar3;
          pbVar19 = (byte *)"-outform";
          do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            bVar20 = *pbVar18 == *pbVar19;
            pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
            pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
          } while (bVar20);
          if (bVar20) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_08053248;
            ppbVar17 = param_2 + 2;
            local_70 = str2fmt(param_2[2]);
          }
          else {
            bVar1 = *pbVar3;
            bVar20 = 0x2d < bVar1;
            bVar21 = bVar1 == 0x2d;
            if (bVar21) {
              bVar20 = pbVar3[1] < 0x69;
              bVar21 = pbVar3[1] == 0x69;
              if (bVar21) {
                bVar20 = pbVar3[2] < 0x6e;
                bVar21 = pbVar3[2] == 0x6e;
                if (bVar21) {
                  bVar20 = false;
                  bVar21 = pbVar3[3] == 0;
                  if (bVar21) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_08053248;
                    local_68 = param_2[2];
                    ppbVar17 = param_2 + 2;
                    goto LAB_080530ce;
                  }
                }
              }
            }
            iVar9 = 5;
            pbVar18 = pbVar3;
            pbVar19 = &DAT_081ea8e1;
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar20 = *pbVar18 < *pbVar19;
              bVar21 = *pbVar18 == *pbVar19;
              pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
              pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
            } while (bVar21);
            bVar20 = (!bVar20 && !bVar21) == bVar20;
            if (bVar20) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_08053248;
              local_64 = param_2[2];
              ppbVar17 = param_2 + 2;
            }
            else {
              iVar9 = 8;
              pbVar18 = pbVar3;
              pbVar19 = (byte *)"-engine";
              do {
                if (iVar9 == 0) break;
                iVar9 = iVar9 + -1;
                bVar20 = *pbVar18 == *pbVar19;
                pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
              } while (bVar20);
              if (bVar20) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_08053248;
                local_60 = param_2[2];
                ppbVar17 = param_2 + 2;
              }
              else {
                iVar9 = 7;
                pbVar18 = pbVar3;
                pbVar19 = (byte *)"-check";
                do {
                  if (iVar9 == 0) break;
                  iVar9 = iVar9 + -1;
                  bVar20 = *pbVar18 == *pbVar19;
                  pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                  pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                } while (bVar20);
                if (bVar20) {
                  bVar6 = true;
                }
                else {
                  iVar9 = 6;
                  pbVar18 = pbVar3;
                  pbVar19 = (byte *)"-text";
                  do {
                    if (iVar9 == 0) break;
                    iVar9 = iVar9 + -1;
                    bVar20 = *pbVar18 == *pbVar19;
                    pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                    pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                  } while (bVar20);
                  if (bVar20) {
                    bVar5 = true;
                  }
                  else {
                    iVar9 = 10;
                    pbVar18 = pbVar3;
                    pbVar19 = (byte *)"-dsaparam";
                    do {
                      if (iVar9 == 0) break;
                      iVar9 = iVar9 + -1;
                      bVar20 = *pbVar18 == *pbVar19;
                      pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                      pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                    } while (bVar20);
                    if (bVar20) {
                      bVar4 = true;
                    }
                    else {
                      bVar20 = bVar1 == 0x2d;
                      if (bVar20) {
                        bVar20 = pbVar3[1] == 0x43;
                        if ((bVar20) && (bVar20 = pbVar3[2] == 0, bVar20)) {
                          bVar7 = true;
                        }
                        else {
                          iVar9 = 7;
                          pbVar18 = pbVar3;
                          pbVar19 = (byte *)"-noout";
                          do {
                            if (iVar9 == 0) break;
                            iVar9 = iVar9 + -1;
                            bVar20 = *pbVar18 == *pbVar19;
                            pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                            pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                          } while (bVar20);
                          if (bVar20) goto LAB_08053a08;
                          if (pbVar3[1] == 0x32) {
                            bVar20 = pbVar3[2] == 0;
                            if (bVar20) {
                              local_58 = 2;
                            }
                            else {
LAB_0805321c:
                              iVar9 = 6;
                              pbVar18 = pbVar3;
                              pbVar19 = (byte *)"-rand";
                              do {
                                if (iVar9 == 0) break;
                                iVar9 = iVar9 + -1;
                                bVar20 = *pbVar18 == *pbVar19;
                                pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                                pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                              } while (bVar20);
                              if (bVar20) {
                                param_1 = param_1 + -1;
                                if (param_1 == 0) {
LAB_08053248:
                                  BIO_printf(bio_err,"%s [options] [numbits]\n",pbVar2);
                                  BIO_printf(bio_err,"where options are\n");
                                  BIO_printf(bio_err,
                                             " -inform arg   input format - one of DER PEM\n");
                                  BIO_printf(bio_err,
                                             " -outform arg  output format - one of DER PEM\n");
                                  BIO_printf(bio_err," -in arg       input file\n");
                                  BIO_printf(bio_err," -out arg      output file\n");
                                  BIO_printf(bio_err,
                                             " -dsaparam     read or generate DSA parameters, convert to DH\n"
                                            );
                                  BIO_printf(bio_err," -check        check the DH parameters\n");
                                  BIO_printf(bio_err,
                                             " -text         print a text form of the DH parameters\n"
                                            );
                                  BIO_printf(bio_err," -C            Output C code\n");
                                  BIO_printf(bio_err,
                                             " -2            generate parameters using  2 as the generator value\n"
                                            );
                                  BIO_printf(bio_err,
                                             " -5            generate parameters using  5 as the generator value\n"
                                            );
                                  BIO_printf(bio_err,
                                             " numbits       number of bits in to generate (default 512)\n"
                                            );
                                  BIO_printf(bio_err,
                                             " -engine e     use engine e, possibly a hardware device.\n"
                                            );
                                  BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
                                  BIO_printf(bio_err,
                                             "               - load the file (or the files in the directory) into\n"
                                            );
                                  BIO_printf(bio_err,"               the random number generator\n")
                                  ;
                                  BIO_printf(bio_err," -noout        no output\n");
                                  goto LAB_08053090;
                                }
                                local_4c = param_2[2];
                                ppbVar17 = param_2 + 2;
                              }
                              else {
                                iVar9 = __isoc99_sscanf(pbVar3,"%d",&local_30);
                                if ((iVar9 == 0) || (local_30 < 1)) goto LAB_08053248;
                              }
                            }
                          }
                          else {
                            bVar20 = pbVar3[1] == 0x35;
                            if ((!bVar20) || (bVar20 = pbVar3[2] == 0, !bVar20)) goto LAB_0805321c;
                            local_58 = 5;
                          }
                        }
                      }
                      else {
                        iVar9 = 7;
                        pbVar18 = pbVar3;
                        pbVar19 = (byte *)"-noout";
                        do {
                          if (iVar9 == 0) break;
                          iVar9 = iVar9 + -1;
                          bVar20 = *pbVar18 == *pbVar19;
                          pbVar18 = pbVar18 + (uint)bVar22 * -2 + 1;
                          pbVar19 = pbVar19 + (uint)bVar22 * -2 + 1;
                        } while (bVar20);
                        if (!bVar20) goto LAB_0805321c;
LAB_08053a08:
                        bVar8 = true;
                      }
                    }
                  }
                }
              }
            }
          }
        }
LAB_080530ce:
        param_1 = param_1 + -1;
        bVar20 = param_1 == 0;
        param_2 = ppbVar17;
      } while (!bVar20);
    }
    ERR_load_crypto_strings();
    setup_engine(bio_err,local_60,0);
    if (local_58 == 0) {
      if (bVar4) {
        if (local_30 != 0) goto LAB_08052fb4;
LAB_080533c8:
        pBVar12 = BIO_s_file();
        bp_00 = BIO_new(pBVar12);
        if (bp_00 == (BIO *)0x0) goto LAB_08053076;
        if (local_68 != (byte *)0x0) {
          lVar13 = BIO_ctrl(bp_00,0x6c,3,local_68);
          if (0 < lVar13) goto LAB_08053408;
          dh = (DH *)0x0;
          perror((char *)local_68);
LAB_08053474:
          BIO_free(bp_00);
          goto LAB_08053480;
        }
        BIO_ctrl(bp_00,0x6a,0,stdin);
LAB_08053408:
        if ((local_74 & 0xfffffffd) != 1) {
          dh = (DH *)0x0;
          BIO_printf(bio_err,"bad input format specified\n");
          goto LAB_08053474;
        }
        if (bVar4) {
          if (local_74 == 1) {
            pDVar11 = (DSA *)ASN1_d2i_bio(DSA_new,d2i_DSAparams,bp_00,(void **)0x0);
          }
          else {
            pDVar11 = PEM_read_bio_DSAparams(bp_00,(DSA **)0x0,(undefined1 *)0x0,(void *)0x0);
          }
          if (pDVar11 == (DSA *)0x0) {
            format = "unable to load DSA parameters\n";
            goto LAB_08053b3f;
          }
          dh = DSA_dup_DH(pDVar11);
          DSA_free(pDVar11);
          if (dh != (DH *)0x0) goto LAB_08053448;
          dh = (DH *)0x0;
          ERR_print_errors(bio_err);
          goto LAB_08053474;
        }
        if (local_74 == 1) {
          dh = (DH *)ASN1_d2i_bio(DH_new,d2i_DHparams,bp_00,(void **)0x0);
        }
        else {
          dh = PEM_read_bio_DHparams(bp_00,(DH **)0x0,(undefined1 *)0x0,(void *)0x0);
        }
        if (dh == (DH *)0x0) {
          format = "unable to load DH parameters\n";
LAB_08053b3f:
          dh = (DH *)0x0;
          BIO_printf(bio_err,format);
          ERR_print_errors(bio_err);
          goto LAB_08053474;
        }
LAB_08053448:
        pBVar12 = BIO_s_file();
        bp = BIO_new(pBVar12);
        if (bp == (BIO *)0x0) {
          ERR_print_errors(bio_err);
          goto LAB_08053474;
        }
LAB_08053562:
        if (local_64 == (byte *)0x0) {
          BIO_ctrl(bp,0x6a,0,stdout);
LAB_08053587:
          if (bVar5) {
            DHparams_print(bp,dh);
          }
          if (bVar6) {
            iVar9 = DH_check(dh,(int *)&local_2c);
            if (iVar9 == 0) {
              uVar10 = 1;
              ERR_print_errors(bio_err);
              goto LAB_080535e8;
            }
            if ((local_2c.ver & 1) != 0) {
              puts("p value is not prime");
            }
            if ((local_2c.ver & 2) != 0) {
              puts("p value is not a safe prime");
            }
            if ((local_2c.ver & 4) != 0) {
              puts("unable to check the generator value");
            }
            if ((local_2c.ver & 8) != 0) {
              puts("the g value is not a generator");
            }
            if (local_2c.ver == 0) {
              puts("DH parameters appear to be ok.");
            }
          }
          if (bVar7) {
            iVar14 = BN_num_bits(dh->p);
            uVar15 = BN_num_bits(dh->p);
            iVar9 = iVar14 + 0xe;
            if (-1 < iVar14 + 7) {
              iVar9 = iVar14 + 7;
            }
            to = (uchar *)CRYPTO_malloc(iVar9 >> 3,"dhparam.c",0x1d2);
            if (to == (uchar *)0x0) {
              uVar10 = 1;
              perror("OPENSSL_malloc");
              goto LAB_080535e8;
            }
            puts("#ifndef HEADER_DH_H\n#include <openssl/dh.h>\n#endif");
            __printf_chk(1,"DH *get_dh%d()\n\t{\n",uVar15);
            iVar9 = BN_bn2bin(dh->p,to);
            uVar16 = uVar15;
            __printf_chk(1,"\tstatic unsigned char dh%d_p[]={",uVar15);
            local_2c.ver = 0;
            if (0 < iVar9) {
              do {
                if (local_2c.ver == ((int)local_2c.ver / 0xc) * 0xc) {
                  __printf_chk(1,&DAT_081ec747,uVar16);
                }
                uVar16 = (uint)to[local_2c.ver];
                __printf_chk(1,"0x%02X,",uVar16);
                local_2c.ver = local_2c.ver + 1;
              } while ((int)local_2c.ver < iVar9);
            }
            puts("\n\t\t};");
            iVar9 = BN_bn2bin(dh->g,to);
            uVar16 = uVar15;
            __printf_chk(1,"\tstatic unsigned char dh%d_g[]={",uVar15);
            local_2c.ver = 0;
            if (0 < iVar9) {
              do {
                if (local_2c.ver == ((int)local_2c.ver / 0xc) * 0xc) {
                  __printf_chk(1,&DAT_081ec747,uVar16);
                }
                uVar16 = (uint)to[local_2c.ver];
                __printf_chk(1,"0x%02X,",uVar16);
                local_2c.ver = local_2c.ver + 1;
              } while ((int)local_2c.ver < iVar9);
            }
            puts("\n\t\t};");
            puts("\tDH *dh;\n");
            puts("\tif ((dh=DH_new()) == NULL) return(NULL);");
            __printf_chk(1,"\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",uVar15,uVar15);
            __printf_chk(1,"\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",uVar15,uVar15);
            puts("\tif ((dh->p == NULL) || (dh->g == NULL))");
            puts("\t\t{ DH_free(dh); return(NULL); }");
            if (dh->length != 0) {
              __printf_chk(1,"\tdh->length = %ld;\n",dh->length,uVar15);
            }
            puts("\treturn(dh);\n\t}");
            CRYPTO_free(to);
          }
          if (!bVar8) {
            if (local_70 == 1) {
              local_2c.ver = ASN1_i2d_bio(i2d_DHparams,bp,(uchar *)dh);
            }
            else {
              if (local_70 != 3) {
                uVar10 = 1;
                BIO_printf(bio_err,"bad output format specified for outfile\n");
                goto LAB_080535e8;
              }
              local_2c.ver = PEM_write_bio_DHparams(bp,dh);
            }
            if (local_2c.ver == 0) {
              BIO_printf(bio_err,"unable to write DH parameters\n");
              uVar10 = 1;
              ERR_print_errors(bio_err);
              goto LAB_080535e8;
            }
          }
          uVar10 = 0;
        }
        else {
          lVar13 = BIO_ctrl(bp,0x6c,5,local_64);
          if (0 < lVar13) goto LAB_08053587;
          uVar10 = 1;
          perror((char *)local_64);
        }
LAB_080535e8:
        if (bp_00 != (BIO *)0x0) {
          BIO_free(bp_00);
        }
        BIO_free_all(bp);
      }
      else {
        if (local_30 == 0) goto LAB_080533c8;
        local_58 = 2;
LAB_08052fb4:
        local_2c.ver = 2;
        local_2c.cb.cb_1 = dh_cb;
        local_2c.arg = bio_err;
        iVar9 = app_RAND_load_file(0,bio_err,1);
        if (iVar9 == 0) {
          if (local_4c == (byte *)0x0) {
            BIO_printf(bio_err,
                       "warning, not much extra random data, consider using the -rand option\n");
          }
          else {
LAB_08052ff1:
            uVar10 = app_RAND_load_files(local_4c);
            BIO_printf(bio_err,"%ld semi-random bytes loaded\n",uVar10);
          }
        }
        else if (local_4c != (byte *)0x0) goto LAB_08052ff1;
        if (bVar4) {
          pDVar11 = DSA_new();
          BIO_printf(bio_err,"Generating DSA parameters, %d bit long prime\n",local_30);
          if (pDVar11 != (DSA *)0x0) {
            iVar9 = DSA_generate_parameters_ex
                              (pDVar11,local_30,(uchar *)0x0,0,(int *)0x0,(ulong *)0x0,&local_2c);
            if (iVar9 == 0) {
              DSA_free(pDVar11);
            }
            else {
              dh = DSA_dup_DH(pDVar11);
              DSA_free(pDVar11);
              if (dh != (DH *)0x0) goto LAB_08053536;
            }
          }
LAB_08053076:
          ERR_print_errors(bio_err);
          goto LAB_08053090;
        }
        dh = DH_new();
        BIO_printf(bio_err,"Generating DH parameters, %d bit long safe prime, generator %d\n",
                   local_30,local_58);
        BIO_printf(bio_err,"This is going to take a long time\n");
        if ((dh == (DH *)0x0) ||
           (iVar9 = DH_generate_parameters_ex(dh,local_30,local_58,&local_2c), iVar9 == 0)) {
          ERR_print_errors(bio_err);
LAB_08053480:
          if (dh == (DH *)0x0) goto LAB_08053090;
          uVar10 = 1;
        }
        else {
LAB_08053536:
          app_RAND_write_file(0,bio_err);
          pBVar12 = BIO_s_file();
          bp = BIO_new(pBVar12);
          if (bp != (BIO *)0x0) {
            bp_00 = (BIO *)0x0;
            goto LAB_08053562;
          }
          uVar10 = 1;
          ERR_print_errors(bio_err);
        }
      }
      DH_free(dh);
      goto LAB_08053095;
    }
    if (local_30 == 0) {
      local_30 = 0x200;
    }
    if (!bVar4) goto LAB_08052fb4;
    BIO_printf(bio_err,"generator may not be chosen for DSA parameters\n");
  }
LAB_08053090:
  uVar10 = 1;
LAB_08053095:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}

