
undefined4 dsaparam_main(int param_1,byte **param_2)

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
  BIO_METHOD *pBVar10;
  BIO *a;
  BIO *bp;
  long lVar11;
  DSA *a_00;
  int iVar12;
  uchar *to;
  uint uVar13;
  undefined4 uVar14;
  DSA *dsa;
  byte **ppbVar15;
  byte *pbVar16;
  byte *pbVar17;
  int in_GS_OFFSET;
  bool bVar18;
  bool bVar19;
  byte bVar20;
  char *format;
  uint uVar21;
  int local_74;
  int local_70;
  byte *local_68;
  byte *local_64;
  byte *local_60;
  int local_4c;
  byte *local_40;
  int local_30;
  BN_GENCB local_2c;
  int local_20;
  
  bVar20 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar10 = BIO_s_file();
    bio_err = BIO_new(pBVar10);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar9 = load_config(bio_err,0);
  if (iVar9 == 0) {
LAB_08060712:
    uVar14 = 1;
    goto LAB_08060717;
  }
  pbVar2 = *param_2;
  local_60 = (byte *)0x0;
  bVar4 = false;
  bVar8 = false;
  local_4c = -1;
  local_40 = (byte *)0x0;
  local_64 = (byte *)0x0;
  local_68 = (byte *)0x0;
  bVar6 = false;
  bVar7 = false;
  param_1 = param_1 + -1;
  local_70 = 3;
  local_74 = 3;
  bVar5 = false;
  bVar18 = param_1 == 0;
  if (0 < param_1) {
    do {
      ppbVar15 = param_2 + 1;
      pbVar3 = *ppbVar15;
      iVar9 = 8;
      pbVar16 = pbVar3;
      pbVar17 = (byte *)"-inform";
      do {
        if (iVar9 == 0) break;
        iVar9 = iVar9 + -1;
        bVar18 = *pbVar16 == *pbVar17;
        pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
        pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
      } while (bVar18);
      if (bVar18) {
        param_1 = param_1 + -1;
        if (param_1 == 0) {
LAB_08060620:
          BIO_printf(bio_err,"%s [options] [bits] <infile >outfile\n",pbVar2);
          BIO_printf(bio_err,"where options are\n");
          BIO_printf(bio_err," -inform arg   input format - DER or PEM\n");
          BIO_printf(bio_err," -outform arg  output format - DER or PEM\n");
          BIO_printf(bio_err," -in arg       input file\n");
          BIO_printf(bio_err," -out arg      output file\n");
          BIO_printf(bio_err," -text         print as text\n");
          BIO_printf(bio_err," -C            Output C code\n");
          BIO_printf(bio_err," -noout        no output\n");
          BIO_printf(bio_err," -genkey       generate a DSA key\n");
          BIO_printf(bio_err," -rand         files to use for random number input\n");
          BIO_printf(bio_err," -engine e     use engine e, possibly a hardware device.\n");
          BIO_printf(bio_err," number        number of bits to use for generating private key\n");
          goto LAB_08060712;
        }
        ppbVar15 = param_2 + 2;
        local_74 = str2fmt(param_2[2]);
      }
      else {
        iVar9 = 9;
        pbVar16 = pbVar3;
        pbVar17 = (byte *)"-outform";
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar18 = *pbVar16 == *pbVar17;
          pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
          pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
        } while (bVar18);
        if (bVar18) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_08060620;
          ppbVar15 = param_2 + 2;
          local_70 = str2fmt(param_2[2]);
        }
        else {
          bVar1 = *pbVar3;
          bVar18 = 0x2d < bVar1;
          bVar19 = bVar1 == 0x2d;
          if (bVar19) {
            bVar18 = pbVar3[1] < 0x69;
            bVar19 = pbVar3[1] == 0x69;
            if (bVar19) {
              bVar18 = pbVar3[2] < 0x6e;
              bVar19 = pbVar3[2] == 0x6e;
              if (bVar19) {
                bVar18 = false;
                bVar19 = pbVar3[3] == 0;
                if (bVar19) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_08060620;
                  local_68 = param_2[2];
                  ppbVar15 = param_2 + 2;
                  goto LAB_0806053e;
                }
              }
            }
          }
          iVar9 = 5;
          pbVar16 = pbVar3;
          pbVar17 = &DAT_081eab75;
          do {
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            bVar18 = *pbVar16 < *pbVar17;
            bVar19 = *pbVar16 == *pbVar17;
            pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
            pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
          } while (bVar19);
          bVar18 = (!bVar18 && !bVar19) == bVar18;
          if (bVar18) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_08060620;
            local_64 = param_2[2];
            ppbVar15 = param_2 + 2;
          }
          else {
            iVar9 = 8;
            pbVar16 = pbVar3;
            pbVar17 = (byte *)"-engine";
            do {
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              bVar18 = *pbVar16 == *pbVar17;
              pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
              pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
            } while (bVar18);
            if (bVar18) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_08060620;
              local_60 = param_2[2];
              ppbVar15 = param_2 + 2;
            }
            else {
              iVar9 = 6;
              pbVar16 = pbVar3;
              pbVar17 = (byte *)"-text";
              do {
                if (iVar9 == 0) break;
                iVar9 = iVar9 + -1;
                bVar18 = *pbVar16 == *pbVar17;
                pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
              } while (bVar18);
              if (bVar18) {
                bVar5 = true;
              }
              else {
                bVar18 = bVar1 == 0x2d;
                if (((bVar18) && (bVar18 = pbVar3[1] == 0x43, bVar18)) &&
                   (bVar18 = pbVar3[2] == 0, bVar18)) {
                  bVar6 = true;
                }
                else {
                  iVar9 = 8;
                  pbVar16 = pbVar3;
                  pbVar17 = (byte *)"-genkey";
                  do {
                    if (iVar9 == 0) break;
                    iVar9 = iVar9 + -1;
                    bVar18 = *pbVar16 == *pbVar17;
                    pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                    pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
                  } while (bVar18);
                  if (bVar18) {
                    bVar4 = true;
                    bVar8 = true;
                  }
                  else {
                    iVar9 = 6;
                    pbVar16 = pbVar3;
                    pbVar17 = (byte *)"-rand";
                    do {
                      if (iVar9 == 0) break;
                      iVar9 = iVar9 + -1;
                      bVar18 = *pbVar16 == *pbVar17;
                      pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                      pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
                    } while (bVar18);
                    if (bVar18) {
                      param_1 = param_1 + -1;
                      if (param_1 == 0) goto LAB_08060620;
                      local_40 = param_2[2];
                      ppbVar15 = param_2 + 2;
                      bVar4 = true;
                    }
                    else {
                      iVar9 = 7;
                      pbVar16 = pbVar3;
                      pbVar17 = (byte *)"-noout";
                      do {
                        if (iVar9 == 0) break;
                        iVar9 = iVar9 + -1;
                        bVar18 = *pbVar16 == *pbVar17;
                        pbVar16 = pbVar16 + (uint)bVar20 * -2 + 1;
                        pbVar17 = pbVar17 + (uint)bVar20 * -2 + 1;
                      } while (bVar18);
                      if (bVar18) {
                        bVar7 = true;
                      }
                      else {
                        iVar9 = __isoc99_sscanf(pbVar3,"%d",&local_30);
                        if (iVar9 != 1) {
                          BIO_printf(bio_err,"unknown option %s\n",*ppbVar15);
                          goto LAB_08060620;
                        }
                        local_4c = local_30;
                        bVar4 = true;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LAB_0806053e:
      param_1 = param_1 + -1;
      bVar18 = param_1 == 0;
      param_2 = ppbVar15;
    } while (!bVar18);
  }
  ERR_load_crypto_strings();
  pBVar10 = BIO_s_file();
  a = BIO_new(pBVar10);
  pBVar10 = BIO_s_file();
  bp = BIO_new(pBVar10);
  if ((a == (BIO *)0x0) || (bp == (BIO *)0x0)) {
    ERR_print_errors(bio_err);
    if (a != (BIO *)0x0) {
      BIO_free(a);
    }
    if (bp == (BIO *)0x0) goto LAB_08060712;
    uVar14 = 1;
    dsa = (DSA *)0x0;
  }
  else {
    if (local_68 == (byte *)0x0) {
      BIO_ctrl(a,0x6a,0,stdin);
LAB_08060464:
      if (local_64 == (byte *)0x0) {
        BIO_ctrl(bp,0x6a,0,stdout);
      }
      else {
        lVar11 = BIO_ctrl(bp,0x6c,5,local_64);
        if (lVar11 < 1) {
          uVar14 = 1;
          dsa = (DSA *)0x0;
          perror((char *)local_64);
          goto LAB_080604eb;
        }
      }
      uVar21 = 0;
      setup_engine(bio_err,local_60,0);
      if (bVar4) {
        uVar21 = (uint)(local_40 != (byte *)0x0);
        app_RAND_load_file(0,bio_err,uVar21);
        if (local_40 != (byte *)0x0) {
          uVar21 = app_RAND_load_files(local_40);
          BIO_printf(bio_err,"%ld semi-random bytes loaded\n",uVar21);
        }
        if (local_4c < 1) goto LAB_080604b8;
        local_2c.ver = 2;
        local_2c.cb.cb_1 = dsa_cb;
        local_2c.arg = bio_err;
        dsa = DSA_new();
        if (dsa == (DSA *)0x0) {
          BIO_printf(bio_err,"Error allocating DSA object\n",uVar21);
LAB_08060a79:
          uVar14 = 1;
          goto LAB_080604eb;
        }
        BIO_printf(bio_err,"Generating DSA parameters, %d bit long prime\n",local_30);
        BIO_printf(bio_err,"This could take some time\n");
        iVar9 = DSA_generate_parameters_ex
                          (dsa,local_30,(uchar *)0x0,0,(int *)0x0,(ulong *)0x0,&local_2c);
        if (iVar9 == 0) {
          ERR_print_errors(bio_err);
          BIO_printf(bio_err,"Error, DSA key generation failed\n");
          goto LAB_08060a79;
        }
LAB_0806097c:
        if (bVar5) {
          DSAparams_print(bp,dsa);
        }
        if (bVar6) {
          iVar12 = BN_num_bits(dsa->p);
          uVar21 = BN_num_bits(dsa->p);
          iVar9 = iVar12 + 0xe;
          if (-1 < iVar12 + 7) {
            iVar9 = iVar12 + 7;
          }
          to = (uchar *)CRYPTO_malloc((iVar9 >> 3) + 0x14,"dsaparam.c",0x155);
          if (to == (uchar *)0x0) {
            uVar14 = 1;
            perror("OPENSSL_malloc");
            goto LAB_080604eb;
          }
          iVar12 = 0;
          iVar9 = BN_bn2bin(dsa->p,to);
          uVar13 = uVar21;
          __printf_chk(1,"static unsigned char dsa%d_p[]={",uVar21);
          if (0 < iVar9) {
            do {
              if (iVar12 == ((iVar12 / 6 + (iVar12 >> 0x1f) >> 1) - (iVar12 >> 0x1f)) * 0xc) {
                __printf_chk(1,&DAT_081ec75e,uVar13);
              }
              uVar13 = (uint)to[iVar12];
              iVar12 = iVar12 + 1;
              __printf_chk(1,"0x%02X,",uVar13);
            } while (iVar9 != iVar12);
          }
          iVar12 = 0;
          puts("\n\t};");
          iVar9 = BN_bn2bin(dsa->q,to);
          uVar13 = uVar21;
          __printf_chk(1,"static unsigned char dsa%d_q[]={",uVar21);
          if (0 < iVar9) {
            do {
              if (iVar12 == ((iVar12 / 6 + (iVar12 >> 0x1f) >> 1) - (iVar12 >> 0x1f)) * 0xc) {
                __printf_chk(1,&DAT_081ec75e,uVar13);
              }
              uVar13 = (uint)to[iVar12];
              iVar12 = iVar12 + 1;
              __printf_chk(1,"0x%02X,",uVar13);
            } while (iVar9 != iVar12);
          }
          iVar12 = 0;
          puts("\n\t};");
          iVar9 = BN_bn2bin(dsa->g,to);
          uVar13 = uVar21;
          __printf_chk(1,"static unsigned char dsa%d_g[]={",uVar21);
          if (0 < iVar9) {
            do {
              if (iVar12 == ((iVar12 / 6 + (iVar12 >> 0x1f) >> 1) - (iVar12 >> 0x1f)) * 0xc) {
                __printf_chk(1,&DAT_081ec75e,uVar13);
              }
              uVar13 = (uint)to[iVar12];
              iVar12 = iVar12 + 1;
              __printf_chk(1,"0x%02X,",uVar13);
            } while (iVar9 != iVar12);
          }
          puts("\n\t};\n");
          __printf_chk(1,"DSA *get_dsa%d()\n\t{\n",uVar21);
          puts("\tDSA *dsa;\n");
          puts("\tif ((dsa=DSA_new()) == NULL) return(NULL);");
          __printf_chk(1,"\tdsa->p=BN_bin2bn(dsa%d_p,sizeof(dsa%d_p),NULL);\n",uVar21,uVar21);
          __printf_chk(1,"\tdsa->q=BN_bin2bn(dsa%d_q,sizeof(dsa%d_q),NULL);\n",uVar21,uVar21);
          __printf_chk(1,"\tdsa->g=BN_bin2bn(dsa%d_g,sizeof(dsa%d_g),NULL);\n",uVar21,uVar21);
          puts("\tif ((dsa->p == NULL) || (dsa->q == NULL) || (dsa->g == NULL))");
          puts("\t\t{ DSA_free(dsa); return(NULL); }");
          puts("\treturn(dsa);\n\t}");
        }
        if (!bVar7) {
          if (local_70 == 1) {
            iVar9 = ASN1_i2d_bio(i2d_DSAparams,bp,(uchar *)dsa);
          }
          else {
            if (local_70 != 3) {
              uVar14 = 1;
              BIO_printf(bio_err,"bad output format specified for outfile\n");
              goto LAB_080604eb;
            }
            iVar9 = PEM_write_bio_DSAparams(bp,dsa);
          }
          if (iVar9 == 0) {
            format = "unable to write DSA parameters\n";
            goto LAB_08060e23;
          }
        }
        if (bVar8) {
          if (!bVar4) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("need_rand","dsaparam.c",0x196,"dsaparam_main");
          }
          uVar14 = 1;
          a_00 = DSAparams_dup(dsa);
          if (a_00 != (DSA *)0x0) {
            iVar9 = DSA_generate_key(a_00);
            if (iVar9 != 0) {
              if (local_70 == 1) {
                i2d_DSAPrivateKey_bio(bp,a_00);
              }
              else {
                if (local_70 != 3) {
                  BIO_printf(bio_err,"bad output format specified for outfile\n");
                  DSA_free(a_00);
                  goto LAB_080604eb;
                }
                PEM_write_bio_DSAPrivateKey
                          (bp,a_00,(EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
              }
              DSA_free(a_00);
              goto LAB_08060ba6;
            }
            ERR_print_errors(bio_err);
            DSA_free(a_00);
          }
        }
        else {
          uVar14 = 0;
          if (bVar4) {
LAB_08060ba6:
            uVar14 = 0;
            app_RAND_write_file(0,bio_err);
          }
        }
      }
      else {
        if (0 < local_4c) {
          local_2c.ver = 2;
          local_2c.cb.cb_1 = dsa_cb;
          local_2c.arg = bio_err;
                    /* WARNING: Subroutine does not return */
          __assert_fail("need_rand","dsaparam.c",0x118,"dsaparam_main");
        }
LAB_080604b8:
        if (local_74 == 1) {
          dsa = (DSA *)ASN1_d2i_bio(DSA_new,d2i_DSAparams,a,(void **)0x0);
        }
        else {
          if (local_74 != 3) {
            uVar14 = 1;
            dsa = (DSA *)0x0;
            BIO_printf(bio_err,"bad input format specified\n",uVar21);
            goto LAB_080604eb;
          }
          dsa = PEM_read_bio_DSAparams(a,(DSA **)0x0,(undefined1 *)0x0,(void *)0x0);
        }
        if (dsa != (DSA *)0x0) goto LAB_0806097c;
        format = "unable to load DSA parameters\n";
LAB_08060e23:
        uVar14 = 1;
        BIO_printf(bio_err,format);
        ERR_print_errors(bio_err);
      }
    }
    else {
      lVar11 = BIO_ctrl(a,0x6c,3,local_68);
      if (0 < lVar11) goto LAB_08060464;
      uVar14 = 1;
      dsa = (DSA *)0x0;
      perror((char *)local_68);
    }
LAB_080604eb:
    BIO_free(a);
  }
  BIO_free_all(bp);
  if (dsa != (DSA *)0x0) {
    DSA_free(dsa);
  }
LAB_08060717:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar14;
}

