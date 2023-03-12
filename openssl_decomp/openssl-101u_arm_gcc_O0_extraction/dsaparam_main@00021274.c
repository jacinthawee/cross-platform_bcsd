
int dsaparam_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  uchar *puVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  BIO *bio;
  int iVar8;
  int iVar9;
  BIO_METHOD *pBVar10;
  DSA *r;
  BIO *bp;
  long lVar11;
  DSA *a;
  int iVar12;
  uchar *to;
  undefined4 uVar13;
  char **ppcVar14;
  char *__s1;
  char *pcVar15;
  int iVar16;
  DSA *dsa;
  char *local_60;
  char *local_5c;
  int local_50;
  int local_48;
  char *local_40;
  int local_38;
  BN_GENCB local_34;
  
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar10 = BIO_s_file();
    bio_err = BIO_new(pBVar10);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar8 = load_config(bio_err,0);
  if (iVar8 == 0) {
    return 1;
  }
  param_1 = param_1 + -1;
  ppcVar14 = (char **)(param_2 + 1);
  uVar13 = *param_2;
  iVar16 = 3;
  pcVar15 = (char *)0x0;
  iVar8 = 3;
  local_50 = 0;
  bVar7 = false;
  local_40 = (char *)0x0;
  local_5c = (char *)0x0;
  local_60 = (char *)0x0;
  bVar5 = false;
  bVar6 = false;
  bVar4 = false;
  local_48 = -1;
  if (0 < param_1) {
    pcVar15 = (char *)0x0;
    do {
      while( true ) {
        __s1 = *ppcVar14;
        iVar9 = strcmp(__s1,"-inform");
        if (iVar9 != 0) break;
        param_1 = param_1 + -1;
        if (param_1 == 0) {
LAB_00021480:
          BIO_printf(bio_err,"%s [options] [bits] <infile >outfile\n",uVar13);
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
          return 1;
        }
        ppcVar1 = ppcVar14 + 1;
        ppcVar14 = ppcVar14 + 1;
        iVar8 = str2fmt(*ppcVar1);
LAB_000212f0:
        param_1 = param_1 + -1;
        ppcVar14 = ppcVar14 + 1;
        if (param_1 < 1) goto LAB_00021348;
      }
      iVar9 = strcmp(__s1,"-outform");
      if (iVar9 != 0) {
        cVar3 = *__s1;
        if ((((cVar3 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00021480;
          local_60 = ppcVar14[1];
          ppcVar14 = ppcVar14 + 1;
        }
        else {
          iVar9 = strcmp(__s1,"-out");
          if (iVar9 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00021480;
            local_5c = ppcVar14[1];
            ppcVar14 = ppcVar14 + 1;
          }
          else {
            iVar9 = strcmp(__s1,"-engine");
            if (iVar9 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00021480;
              pcVar15 = ppcVar14[1];
              ppcVar14 = ppcVar14 + 1;
            }
            else {
              iVar9 = strcmp(__s1,"-text");
              if (iVar9 == 0) {
                bVar4 = true;
              }
              else if (((cVar3 == '-') && (__s1[1] == 'C')) && (__s1[2] == '\0')) {
                bVar5 = true;
              }
              else {
                iVar9 = strcmp(__s1,"-genkey");
                if (iVar9 == 0) {
                  local_50 = 1;
                  bVar7 = true;
                }
                else {
                  iVar9 = strcmp(__s1,"-rand");
                  if (iVar9 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_00021480;
                    local_40 = ppcVar14[1];
                    local_50 = 1;
                    ppcVar14 = ppcVar14 + 1;
                  }
                  else {
                    iVar9 = strcmp(__s1,"-noout");
                    if (iVar9 == 0) {
                      bVar6 = true;
                    }
                    else {
                      local_50 = __isoc99_sscanf(__s1,"%d",&local_38);
                      if (local_50 != 1) {
                        BIO_printf(bio_err,"unknown option %s\n",*ppcVar14);
                        goto LAB_00021480;
                      }
                      local_48 = local_38;
                    }
                  }
                }
              }
            }
          }
        }
        goto LAB_000212f0;
      }
      if (param_1 == 1) goto LAB_00021480;
      param_1 = param_1 + -2;
      iVar16 = str2fmt(ppcVar14[1]);
      ppcVar14 = ppcVar14 + 2;
    } while (0 < param_1);
  }
LAB_00021348:
  ERR_load_crypto_strings();
  pBVar10 = BIO_s_file();
  r = (DSA *)BIO_new(pBVar10);
  pBVar10 = BIO_s_file();
  bp = BIO_new(pBVar10);
  if (r == (DSA *)0x0 || bp == (BIO *)0x0) {
    ERR_print_errors(bio_err);
    local_50 = 1;
    if (r == (DSA *)0x0) goto LAB_0002165a;
    local_50 = 1;
    dsa = (DSA *)0x0;
  }
  else {
    if (local_60 == (char *)0x0) {
      BIO_ctrl((BIO *)r,0x6a,0,stdin);
    }
    else {
      lVar11 = BIO_ctrl((BIO *)r,0x6c,3,local_60);
      dsa = (DSA *)0x0;
      if (lVar11 < 1) {
        local_50 = 1;
        perror(local_60);
        goto LAB_00021654;
      }
    }
    if (local_5c == (char *)0x0) {
      BIO_ctrl(bp,0x6a,0,stdout);
    }
    else {
      lVar11 = BIO_ctrl(bp,0x6c,5,local_5c);
      if (lVar11 < 1) {
        local_50 = 1;
        perror(local_5c);
        dsa = (DSA *)0x0;
        goto LAB_00021654;
      }
    }
    setup_engine(bio_err,pcVar15,0);
    if (local_50 != 0) {
      pcVar15 = local_40;
      if (local_40 != (char *)0x0) {
        pcVar15 = (char *)0x1;
      }
      app_RAND_load_file(0,bio_err,pcVar15);
      bio = bio_err;
      if (pcVar15 != (char *)0x0) {
        uVar13 = app_RAND_load_files(local_40);
        BIO_printf(bio,"%ld semi-random bytes loaded\n",uVar13);
      }
    }
    if (local_48 < 1) {
      if (iVar8 == 1) {
        dsa = (DSA *)ASN1_d2i_bio(DSA_new,d2i_DSAparams + 1,(BIO *)r,(void **)0x0);
      }
      else {
        if (iVar8 != 3) {
          local_50 = 1;
          BIO_printf(bio_err,"bad input format specified\n");
          dsa = (DSA *)0x0;
          goto LAB_00021654;
        }
        dsa = PEM_read_bio_DSAparams((BIO *)r,(DSA **)0x0,(undefined1 *)0x0,(void *)0x0);
      }
      if (dsa == (DSA *)0x0) {
        local_50 = 1;
        BIO_printf(bio_err,"unable to load DSA parameters\n");
        ERR_print_errors(bio_err);
      }
      else {
LAB_00021436:
        if (bVar4) {
          DSAparams_print(bp,dsa);
        }
        if (bVar5) {
          iVar9 = BN_num_bits(dsa->p);
          iVar12 = BN_num_bits(dsa->p);
          iVar8 = iVar9 + 0xe;
          if (-1 < iVar9 + 7) {
            iVar8 = iVar9 + 7;
          }
          to = (uchar *)CRYPTO_malloc((iVar8 >> 3) + 0x14,"dsaparam.c",0x155);
          if (to == (uchar *)0x0) {
            local_50 = 1;
            perror("OPENSSL_malloc");
            goto LAB_00021654;
          }
          iVar8 = BN_bn2bin(dsa->p,to);
          __printf_chk(1,"static unsigned char dsa%d_p[]={",iVar12);
          if (0 < iVar8) {
            iVar9 = 0;
            do {
              if (iVar9 == (iVar9 / 0xc) * 0xc) {
                __printf_chk(1,&DAT_00126330,(iVar9 / 0xc) * 3,iVar9 * 0x2aaaaaab);
              }
              puVar2 = to + iVar9;
              iVar9 = iVar9 + 1;
              __printf_chk(1,"0x%02X,",*puVar2);
            } while (iVar9 != iVar8);
          }
          puts("\n\t};");
          iVar8 = BN_bn2bin(dsa->q,to);
          __printf_chk(1,"static unsigned char dsa%d_q[]={",iVar12);
          if (0 < iVar8) {
            iVar9 = 0;
            do {
              if (iVar9 == (iVar9 / 0xc) * 0xc) {
                __printf_chk(1,&DAT_00126330,(iVar9 / 0xc) * 3,iVar9 * 0x2aaaaaab);
              }
              puVar2 = to + iVar9;
              iVar9 = iVar9 + 1;
              __printf_chk(1,"0x%02X,",*puVar2);
            } while (iVar9 != iVar8);
          }
          puts("\n\t};");
          iVar8 = BN_bn2bin(dsa->g,to);
          __printf_chk(1,"static unsigned char dsa%d_g[]={",iVar12);
          if (0 < iVar8) {
            iVar9 = 0;
            do {
              if (iVar9 == (iVar9 / 0xc) * 0xc) {
                __printf_chk(1,&DAT_00126330,(iVar9 / 0xc) * 3,iVar9 * 0x2aaaaaab);
              }
              puVar2 = to + iVar9;
              iVar9 = iVar9 + 1;
              __printf_chk(1,"0x%02X,",*puVar2);
            } while (iVar9 != iVar8);
          }
          puts("\n\t};\n");
          __printf_chk(1,"DSA *get_dsa%d()\n\t{\n",iVar12);
          puts("\tDSA *dsa;\n");
          puts("\tif ((dsa=DSA_new()) == NULL) return(NULL);");
          __printf_chk(1,"\tdsa->p=BN_bin2bn(dsa%d_p,sizeof(dsa%d_p),NULL);\n",iVar12,iVar12);
          __printf_chk(1,"\tdsa->q=BN_bin2bn(dsa%d_q,sizeof(dsa%d_q),NULL);\n",iVar12,iVar12);
          __printf_chk(1,"\tdsa->g=BN_bin2bn(dsa%d_g,sizeof(dsa%d_g),NULL);\n",iVar12,iVar12);
          puts("\tif ((dsa->p == NULL) || (dsa->q == NULL) || (dsa->g == NULL))");
          puts("\t\t{ DSA_free(dsa); return(NULL); }");
          puts("\treturn(dsa);\n\t}");
        }
        if (!bVar6) {
          if (iVar16 == 1) {
            iVar8 = ASN1_i2d_bio(i2d_DSAparams + 1,bp,(uchar *)dsa);
          }
          else {
            if (iVar16 != 3) {
              local_50 = 1;
              BIO_printf(bio_err,"bad output format specified for outfile\n");
              goto LAB_00021654;
            }
            iVar8 = PEM_write_bio_DSAparams(bp,dsa);
          }
          if (iVar8 == 0) {
            local_50 = 1;
            BIO_printf(bio_err,"unable to write DSA parameters\n");
            ERR_print_errors(bio_err);
            goto LAB_00021654;
          }
        }
        if (bVar7) {
          if (local_50 == 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("need_rand","dsaparam.c",0x196,"dsaparam_main");
          }
          a = DSAparams_dup(dsa);
          if (a == (DSA *)0x0) goto LAB_00021706;
          iVar8 = DSA_generate_key(a);
          if (iVar8 != 0) {
            if (iVar16 == 1) {
              i2d_DSAPrivateKey_bio(bp,a);
            }
            else {
              if (iVar16 != 3) {
                local_50 = 1;
                BIO_printf(bio_err,"bad output format specified for outfile\n");
                DSA_free(a);
                goto LAB_00021654;
              }
              PEM_write_bio_DSAPrivateKey
                        (bp,a,(EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
            }
            DSA_free(a);
            goto LAB_00021860;
          }
          local_50 = 1;
          ERR_print_errors(bio_err);
          DSA_free(a);
        }
        else if (local_50 != 0) {
LAB_00021860:
          app_RAND_write_file(0,bio_err);
          local_50 = 0;
        }
      }
    }
    else {
      local_34.cb.cb_1 = dsa_cb + 1;
      local_34.ver = 2;
      local_34.arg = bio_err;
      if (local_50 == 0) {
                    /* WARNING: Subroutine does not return */
        __assert_fail("need_rand","dsaparam.c",0x118,"dsaparam_main");
      }
      dsa = DSA_new();
      if (dsa == (DSA *)0x0) {
        BIO_printf(bio_err,"Error allocating DSA object\n");
      }
      else {
        BIO_printf(bio_err,"Generating DSA parameters, %d bit long prime\n",local_38);
        BIO_printf(bio_err,"This could take some time\n");
        iVar8 = DSA_generate_parameters_ex
                          (dsa,local_38,(uchar *)0x0,0,(int *)0x0,(ulong *)0x0,&local_34);
        if (iVar8 != 0) goto LAB_00021436;
        ERR_print_errors(bio_err);
        BIO_printf(bio_err,"Error, DSA key generation failed\n");
      }
LAB_00021706:
      local_50 = 1;
    }
  }
LAB_00021654:
  BIO_free((BIO *)r);
  r = dsa;
LAB_0002165a:
  if (bp != (BIO *)0x0) {
    BIO_free_all(bp);
  }
  if (r != (DSA *)0x0) {
    DSA_free(r);
    return local_50;
  }
  return local_50;
}

