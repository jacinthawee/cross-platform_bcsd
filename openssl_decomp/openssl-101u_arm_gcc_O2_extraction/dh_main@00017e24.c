
undefined4 dh_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  BIO_METHOD *pBVar9;
  DH *dh;
  BIO *bp;
  long lVar10;
  int iVar11;
  uchar *to;
  undefined4 uVar12;
  char **ppcVar13;
  char *__s1;
  char *pcVar14;
  int iVar15;
  DH *x;
  char *local_4c;
  char *local_48;
  int local_2c [2];
  
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar9 = BIO_s_file();
    bio_err = BIO_new(pBVar9);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar7 = load_config(bio_err,0);
  if (iVar7 == 0) {
    return 1;
  }
  param_1 = param_1 + -1;
  ppcVar13 = (char **)(param_2 + 1);
  uVar12 = *param_2;
  iVar15 = 3;
  pcVar14 = (char *)0x0;
  iVar7 = 3;
  local_48 = (char *)0x0;
  local_4c = (char *)0x0;
  bVar5 = false;
  bVar6 = false;
  bVar4 = false;
  bVar3 = false;
  if (0 < param_1) {
    pcVar14 = (char *)0x0;
    do {
      while( true ) {
        __s1 = *ppcVar13;
        iVar8 = strcmp(__s1,"-inform");
        if (iVar8 != 0) break;
        param_1 = param_1 + -1;
        if (param_1 == 0) {
LAB_00017f96:
          BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar12);
          BIO_printf(bio_err,"where options are\n");
          BIO_printf(bio_err," -inform arg   input format - one of DER PEM\n");
          BIO_printf(bio_err," -outform arg  output format - one of DER PEM\n");
          BIO_printf(bio_err," -in arg       input file\n");
          BIO_printf(bio_err," -out arg      output file\n");
          BIO_printf(bio_err," -check        check the DH parameters\n");
          BIO_printf(bio_err," -text         print a text form of the DH parameters\n");
          BIO_printf(bio_err," -C            Output C code\n");
          BIO_printf(bio_err," -noout        no output\n");
          BIO_printf(bio_err," -engine e     use engine e, possibly a hardware device.\n");
          return 1;
        }
        ppcVar1 = ppcVar13 + 1;
        ppcVar13 = ppcVar13 + 1;
        iVar7 = str2fmt(*ppcVar1);
LAB_00017e96:
        param_1 = param_1 + -1;
        ppcVar13 = ppcVar13 + 1;
        if (param_1 < 1) goto LAB_00017eec;
      }
      iVar8 = strcmp(__s1,"-outform");
      if (iVar8 != 0) {
        cVar2 = *__s1;
        if ((((cVar2 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00017f96;
          local_4c = ppcVar13[1];
          ppcVar13 = ppcVar13 + 1;
        }
        else {
          iVar8 = strcmp(__s1,"-out");
          if (iVar8 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00017f96;
            local_48 = ppcVar13[1];
            ppcVar13 = ppcVar13 + 1;
          }
          else {
            iVar8 = strcmp(__s1,"-engine");
            if (iVar8 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00017f96;
              pcVar14 = ppcVar13[1];
              ppcVar13 = ppcVar13 + 1;
            }
            else {
              iVar8 = strcmp(__s1,"-check");
              if (iVar8 == 0) {
                bVar4 = true;
              }
              else {
                iVar8 = strcmp(__s1,"-text");
                if (iVar8 == 0) {
                  bVar3 = true;
                }
                else if (((cVar2 == '-') && (__s1[1] == 'C')) && (__s1[2] == '\0')) {
                  bVar5 = true;
                }
                else {
                  iVar8 = strcmp(__s1,"-noout");
                  if (iVar8 != 0) {
                    BIO_printf(bio_err,"unknown option %s\n",__s1);
                    goto LAB_00017f96;
                  }
                  bVar6 = true;
                }
              }
            }
          }
        }
        goto LAB_00017e96;
      }
      if (param_1 == 1) goto LAB_00017f96;
      param_1 = param_1 + -2;
      iVar15 = str2fmt(ppcVar13[1]);
      ppcVar13 = ppcVar13 + 2;
    } while (0 < param_1);
  }
LAB_00017eec:
  ERR_load_crypto_strings();
  setup_engine(bio_err,pcVar14,0);
  pBVar9 = BIO_s_file();
  dh = (DH *)BIO_new(pBVar9);
  pBVar9 = BIO_s_file();
  bp = BIO_new(pBVar9);
  if (dh == (DH *)0x0 || bp == (BIO *)0x0) {
    ERR_print_errors(bio_err);
    uVar12 = 1;
    if (dh == (DH *)0x0) goto LAB_00018132;
    uVar12 = 1;
    x = (DH *)0x0;
  }
  else {
    if (local_4c == (char *)0x0) {
      BIO_ctrl((BIO *)dh,0x6a,0,stdin);
    }
    else {
      lVar10 = BIO_ctrl((BIO *)dh,0x6c,3,local_4c);
      x = (DH *)0x0;
      if (lVar10 < 1) {
        uVar12 = 1;
        perror(local_4c);
        goto LAB_0001812c;
      }
    }
    if (local_48 == (char *)0x0) {
      BIO_ctrl(bp,0x6a,0,stdout);
    }
    else {
      lVar10 = BIO_ctrl(bp,0x6c,5,local_48);
      if (lVar10 < 1) {
        uVar12 = 1;
        perror(local_48);
        x = (DH *)0x0;
        goto LAB_0001812c;
      }
    }
    if (iVar7 == 1) {
      x = (DH *)ASN1_d2i_bio(DH_new + 1,d2i_DHparams + 1,(BIO *)dh,(void **)0x0);
    }
    else {
      if (iVar7 != 3) {
        uVar12 = 1;
        BIO_printf(bio_err,"bad input format specified\n");
        x = (DH *)0x0;
        goto LAB_0001812c;
      }
      x = PEM_read_bio_DHparams((BIO *)dh,(DH **)0x0,(undefined1 *)0x0,(void *)0x0);
    }
    if (x == (DH *)0x0) {
      uVar12 = 1;
      BIO_printf(bio_err,"unable to load DH parameters\n");
      ERR_print_errors(bio_err);
    }
    else {
      if (bVar3) {
        DHparams_print(bp,x);
      }
      if (bVar4) {
        iVar7 = DH_check(x,local_2c);
        if (iVar7 == 0) {
          uVar12 = 1;
          ERR_print_errors(bio_err);
          goto LAB_0001812c;
        }
        if (local_2c[0] << 0x1f < 0) {
          puts("p value is not prime");
        }
        if (local_2c[0] << 0x1e < 0) {
          puts("p value is not a safe prime");
        }
        if (local_2c[0] << 0x1d < 0) {
          puts("unable to check the generator value");
        }
        if (local_2c[0] << 0x1c < 0) {
          puts("the g value is not a generator");
        }
        if (local_2c[0] == 0) {
          puts("DH parameters appear to be ok.");
        }
      }
      if (bVar5) {
        iVar8 = BN_num_bits(x->p);
        iVar11 = BN_num_bits(x->p);
        iVar7 = iVar8 + 0xe;
        if (-1 < iVar8 + 7) {
          iVar7 = iVar8 + 7;
        }
        to = (uchar *)CRYPTO_malloc(iVar7 >> 3,"dh.c",0x10d);
        if (to == (uchar *)0x0) {
          uVar12 = 1;
          perror("OPENSSL_malloc");
          goto LAB_0001812c;
        }
        iVar7 = BN_bn2bin(x->p,to);
        __printf_chk(1,"static unsigned char dh%d_p[]={",iVar11);
        local_2c[0] = 0;
        if (0 < iVar7) {
          do {
            if (local_2c[0] == (local_2c[0] / 0xc) * 0xc) {
              __printf_chk(1,&DAT_00126330);
            }
            __printf_chk(1,"0x%02X,",to[local_2c[0]]);
            local_2c[0] = local_2c[0] + 1;
          } while (local_2c[0] < iVar7);
        }
        puts("\n\t};");
        iVar7 = BN_bn2bin(x->g,to);
        __printf_chk(1,"static unsigned char dh%d_g[]={",iVar11);
        local_2c[0] = 0;
        if (0 < iVar7) {
          do {
            if (local_2c[0] == (local_2c[0] / 0xc) * 0xc) {
              __printf_chk(1,&DAT_00126330);
            }
            __printf_chk(1,"0x%02X,",to[local_2c[0]]);
            local_2c[0] = local_2c[0] + 1;
          } while (local_2c[0] < iVar7);
        }
        puts("\n\t};\n");
        __printf_chk(1,"DH *get_dh%d()\n\t{\n",iVar11);
        puts("\tDH *dh;\n");
        puts("\tif ((dh=DH_new()) == NULL) return(NULL);");
        __printf_chk(1,"\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",iVar11,iVar11);
        __printf_chk(1,"\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",iVar11,iVar11);
        puts("\tif ((dh->p == NULL) || (dh->g == NULL))");
        puts("\t\treturn(NULL);");
        puts("\treturn(dh);\n\t}");
        CRYPTO_free(to);
      }
      if (!bVar6) {
        if (iVar15 == 1) {
          local_2c[0] = ASN1_i2d_bio(i2d_DHparams + 1,bp,(uchar *)x);
        }
        else {
          if (iVar15 != 3) {
            uVar12 = 1;
            BIO_printf(bio_err,"bad output format specified for outfile\n");
            goto LAB_0001812c;
          }
          local_2c[0] = PEM_write_bio_DHparams(bp,x);
        }
        if (local_2c[0] == 0) {
          uVar12 = 1;
          BIO_printf(bio_err,"unable to write DH parameters\n");
          ERR_print_errors(bio_err);
          goto LAB_0001812c;
        }
      }
      uVar12 = 0;
    }
  }
LAB_0001812c:
  BIO_free((BIO *)dh);
  dh = x;
LAB_00018132:
  if (bp != (BIO *)0x0) {
    BIO_free_all(bp);
  }
  if (dh != (DH *)0x0) {
    DH_free(dh);
    return uVar12;
  }
  return uVar12;
}

