
undefined4 dhparam_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  DH *dh;
  int iVar8;
  DSA *pDVar9;
  BIO_METHOD *pBVar10;
  DH *bp;
  long lVar11;
  int iVar12;
  int iVar13;
  uchar *to;
  undefined4 uVar14;
  char *__s;
  char **ppcVar15;
  char *__s1;
  uint uVar16;
  BIO *pBVar17;
  int iVar18;
  char *local_60;
  char *local_5c;
  char *local_50;
  char *local_48;
  int local_38;
  BN_GENCB local_34;
  
  local_38 = 0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar10 = BIO_s_file();
    bio_err = BIO_new(pBVar10);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  dh = (DH *)load_config(bio_err,0);
  if (dh != (DH *)0x0) {
    param_1 = param_1 + -1;
    ppcVar15 = (char **)(param_2 + 1);
    uVar14 = *param_2;
    iVar18 = 3;
    local_5c = (char *)0x0;
    __s = (char *)0x0;
    uVar16 = 3;
    local_48 = (char *)0x0;
    local_60 = (char *)0x0;
    bVar6 = false;
    bVar7 = false;
    bVar5 = false;
    bVar3 = false;
    bVar4 = false;
    local_50 = (char *)0x0;
    if (0 < param_1) {
      local_50 = (char *)0x0;
      __s = (char *)0x0;
LAB_00018506:
      do {
        __s1 = *ppcVar15;
        iVar8 = strcmp(__s1,"-inform");
        if (iVar8 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            ppcVar1 = ppcVar15 + 1;
            ppcVar15 = ppcVar15 + 1;
            uVar16 = str2fmt(*ppcVar1);
            goto LAB_000184f8;
          }
LAB_00018706:
          BIO_printf(bio_err,"%s [options] [numbits]\n",uVar14);
          BIO_printf(bio_err,"where options are\n");
          BIO_printf(bio_err," -inform arg   input format - one of DER PEM\n");
          BIO_printf(bio_err," -outform arg  output format - one of DER PEM\n");
          BIO_printf(bio_err," -in arg       input file\n");
          BIO_printf(bio_err," -out arg      output file\n");
          BIO_printf(bio_err," -dsaparam     read or generate DSA parameters, convert to DH\n");
          BIO_printf(bio_err," -check        check the DH parameters\n");
          BIO_printf(bio_err," -text         print a text form of the DH parameters\n");
          BIO_printf(bio_err," -C            Output C code\n");
          BIO_printf(bio_err," -2            generate parameters using  2 as the generator value\n")
          ;
          BIO_printf(bio_err," -5            generate parameters using  5 as the generator value\n")
          ;
          BIO_printf(bio_err," numbits       number of bits in to generate (default 512)\n");
          BIO_printf(bio_err," -engine e     use engine e, possibly a hardware device.\n");
          BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
          BIO_printf(bio_err,"               - load the file (or the files in the directory) into\n"
                    );
          BIO_printf(bio_err,"               the random number generator\n");
          BIO_printf(bio_err," -noout        no output\n");
          dh = (DH *)0x0;
          goto LAB_00018618;
        }
        iVar8 = strcmp(__s1,"-outform");
        if (iVar8 == 0) {
          if (param_1 == 1) goto LAB_00018706;
          param_1 = param_1 + -2;
          iVar18 = str2fmt(ppcVar15[1]);
          ppcVar15 = ppcVar15 + 2;
          if (param_1 < 1) break;
          goto LAB_00018506;
        }
        cVar2 = *__s1;
        if ((((cVar2 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00018706;
          __s = ppcVar15[1];
          ppcVar15 = ppcVar15 + 1;
        }
        else {
          iVar8 = strcmp(__s1,"-out");
          if (iVar8 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00018706;
            local_60 = ppcVar15[1];
            ppcVar15 = ppcVar15 + 1;
          }
          else {
            iVar8 = strcmp(__s1,"-engine");
            if (iVar8 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00018706;
              local_5c = ppcVar15[1];
              ppcVar15 = ppcVar15 + 1;
            }
            else {
              iVar8 = strcmp(__s1,"-check");
              if (iVar8 == 0) {
                bVar5 = true;
              }
              else {
                iVar8 = strcmp(__s1,"-text");
                if (iVar8 == 0) {
                  bVar4 = true;
                }
                else {
                  iVar8 = strcmp(__s1,"-dsaparam");
                  if (iVar8 == 0) {
                    bVar3 = true;
                  }
                  else if (cVar2 == '-') {
                    cVar2 = __s1[1];
                    if ((cVar2 == 'C') && (__s1[2] == '\0')) {
                      bVar6 = true;
                    }
                    else {
                      iVar8 = strcmp(__s1,"-noout");
                      if (iVar8 == 0) {
                        bVar7 = true;
                      }
                      else if (cVar2 == '2') {
                        if (__s1[2] != '\0') goto LAB_00018db0;
                        local_50 = (char *)0x2;
                      }
                      else {
                        if ((cVar2 != '5') || (__s1[2] != '\0')) {
LAB_00018db0:
                          iVar8 = strcmp(__s1,"-rand");
                          if (iVar8 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_48 = ppcVar15[1];
                              ppcVar15 = ppcVar15 + 1;
                              goto LAB_000184f8;
                            }
                          }
                          else {
                            iVar8 = __isoc99_sscanf(__s1,"%d",&local_38);
                            if ((iVar8 != 0) && (0 < local_38)) goto LAB_000184f8;
                          }
                          goto LAB_00018706;
                        }
                        local_50 = (char *)0x5;
                      }
                    }
                  }
                  else {
                    iVar8 = strcmp(__s1,"-noout");
                    if (iVar8 != 0) goto LAB_00018db0;
                    bVar7 = true;
                  }
                }
              }
            }
          }
        }
LAB_000184f8:
        param_1 = param_1 + -1;
        ppcVar15 = ppcVar15 + 1;
      } while (0 < param_1);
    }
    ERR_load_crypto_strings();
    setup_engine(bio_err,local_5c,0);
    if (local_50 == (char *)0x0) {
      if (!bVar3) {
        if (local_38 != 0) {
          local_50 = (char *)0x2;
          goto LAB_0001857c;
        }
LAB_0001894e:
        pBVar10 = BIO_s_file();
        pBVar17 = BIO_new(pBVar10);
        if (pBVar17 == (BIO *)0x0) goto LAB_0001860c;
        if (__s == (char *)0x0) {
          BIO_ctrl(pBVar17,0x6a,0,stdin);
LAB_00018974:
          if ((uVar16 & 0xfffffffd) != 1) {
            BIO_printf(bio_err,"bad input format specified\n");
            goto LAB_000189b4;
          }
          if (bVar3) {
            if (uVar16 == 1) {
              pDVar9 = (DSA *)ASN1_d2i_bio(DSA_new,d2i_DSAparams + 1,pBVar17,(void **)0x0);
            }
            else {
              pDVar9 = PEM_read_bio_DSAparams(pBVar17,(DSA **)0x0,(undefined1 *)0x0,(void *)0x0);
            }
            if (pDVar9 == (DSA *)0x0) {
              BIO_printf(bio_err,"unable to load DSA parameters\n");
              ERR_print_errors(bio_err);
              goto LAB_000189b4;
            }
            dh = DSA_dup_DH(pDVar9);
            DSA_free(pDVar9);
            if (dh == (DH *)0x0) goto LAB_000189ae;
          }
          else {
            if (uVar16 == 1) {
              dh = (DH *)ASN1_d2i_bio(DH_new,d2i_DHparams + 1,pBVar17,(void **)0x0);
            }
            else {
              dh = PEM_read_bio_DHparams(pBVar17,(DH **)0x0,(undefined1 *)0x0,(void *)0x0);
            }
            if (dh == (DH *)0x0) {
              BIO_printf(bio_err,"unable to load DH parameters\n");
LAB_000189ae:
              ERR_print_errors(bio_err);
              goto LAB_000189b4;
            }
          }
          goto LAB_00018888;
        }
        lVar11 = BIO_ctrl(pBVar17,0x6c,3,__s);
        if (0 < lVar11) goto LAB_00018974;
        perror(__s);
LAB_000189b4:
        dh = (DH *)0x0;
        uVar14 = 1;
        bp = dh;
LAB_000188f2:
        BIO_free(pBVar17);
LAB_000188f8:
        if (bp != (DH *)0x0) {
          BIO_free_all((BIO *)bp);
        }
        goto LAB_0001861c;
      }
      if (local_38 == 0) goto LAB_0001894e;
LAB_0001857c:
      local_34.cb.cb_1 = dh_cb + 1;
      local_34.arg = bio_err;
      local_34.ver = 2;
      iVar8 = app_RAND_load_file(0,bio_err,1);
      pBVar17 = bio_err;
      if (iVar8 == 0) {
        if (local_48 == (char *)0x0) {
          BIO_printf(bio_err,
                     "warning, not much extra random data, consider using the -rand option\n");
        }
        else {
LAB_000185ac:
          uVar14 = app_RAND_load_files(local_48);
          BIO_printf(pBVar17,"%ld semi-random bytes loaded\n",uVar14);
        }
      }
      else if (local_48 != (char *)0x0) goto LAB_000185ac;
      if (bVar3) {
        pDVar9 = DSA_new();
        BIO_printf(bio_err,"Generating DSA parameters, %d bit long prime\n",local_38);
        if (pDVar9 != (DSA *)0x0) {
          iVar8 = DSA_generate_parameters_ex
                            (pDVar9,local_38,(uchar *)0x0,0,(int *)0x0,(ulong *)0x0,&local_34);
          if (iVar8 != 0) {
            dh = DSA_dup_DH(pDVar9);
            DSA_free(pDVar9);
            if (dh != (DH *)0x0) goto LAB_0001887e;
            ERR_print_errors(bio_err);
            goto LAB_00018618;
          }
          DSA_free(pDVar9);
        }
LAB_0001860c:
        dh = (DH *)0x0;
        ERR_print_errors(bio_err);
      }
      else {
        dh = DH_new();
        BIO_printf(bio_err,"Generating DH parameters, %d bit long safe prime, generator %d\n",
                   local_38,local_50);
        BIO_printf(bio_err,"This is going to take a long time\n");
        if ((dh != (DH *)0x0) &&
           (iVar8 = DH_generate_parameters_ex(dh,local_38,(int)local_50,&local_34), iVar8 != 0)) {
LAB_0001887e:
          app_RAND_write_file(0,bio_err);
          pBVar17 = (BIO *)0x0;
LAB_00018888:
          pBVar10 = BIO_s_file();
          bp = (DH *)BIO_new(pBVar10);
          if (bp == (DH *)0x0) {
LAB_00018c48:
            uVar14 = 1;
            ERR_print_errors(bio_err);
          }
          else if (local_60 == (char *)0x0) {
            BIO_ctrl((BIO *)bp,0x6a,0,stdout);
LAB_000188b0:
            if (bVar4) {
              DHparams_print((BIO *)bp,dh);
            }
            if (bVar5) {
              iVar8 = DH_check(dh,(int *)&local_34);
              if (iVar8 == 0) goto LAB_00018c48;
              if ((int)(local_34.ver << 0x1f) < 0) {
                puts("p value is not prime");
              }
              if ((int)(local_34.ver << 0x1e) < 0) {
                puts("p value is not a safe prime");
              }
              if ((int)(local_34.ver << 0x1d) < 0) {
                puts("unable to check the generator value");
              }
              if ((int)(local_34.ver << 0x1c) < 0) {
                puts("the g value is not a generator");
              }
              if (local_34.ver == 0) {
                puts("DH parameters appear to be ok.");
              }
            }
            if (bVar6) {
              iVar12 = BN_num_bits(dh->p);
              iVar13 = BN_num_bits(dh->p);
              iVar8 = iVar12 + 0xe;
              if (-1 < iVar12 + 7) {
                iVar8 = iVar12 + 7;
              }
              to = (uchar *)CRYPTO_malloc(iVar8 >> 3,"dhparam.c",0x1d2);
              if (to == (uchar *)0x0) {
                uVar14 = 1;
                perror("OPENSSL_malloc");
                goto LAB_000188f0;
              }
              puts("#ifndef HEADER_DH_H\n#include <openssl/dh.h>\n#endif");
              __printf_chk(1,"DH *get_dh%d()\n\t{\n",iVar13);
              iVar8 = BN_bn2bin(dh->p,to);
              __printf_chk(1,"\tstatic unsigned char dh%d_p[]={",iVar13);
              local_34.ver = 0;
              if (0 < iVar8) {
                do {
                  if (local_34.ver == ((int)local_34.ver / 0xc) * 0xc) {
                    __printf_chk(1,&DAT_00127a90);
                  }
                  __printf_chk(1,"0x%02X,",to[local_34.ver]);
                  local_34.ver = local_34.ver + 1;
                } while ((int)local_34.ver < iVar8);
              }
              puts("\n\t\t};");
              iVar8 = BN_bn2bin(dh->g,to);
              __printf_chk(1,"\tstatic unsigned char dh%d_g[]={",iVar13);
              local_34.ver = 0;
              if (0 < iVar8) {
                do {
                  if (local_34.ver == ((int)local_34.ver / 0xc) * 0xc) {
                    __printf_chk(1,&DAT_00127a90);
                  }
                  __printf_chk(1,"0x%02X,",to[local_34.ver]);
                  local_34.ver = local_34.ver + 1;
                } while ((int)local_34.ver < iVar8);
              }
              puts("\n\t\t};");
              puts("\tDH *dh;\n");
              puts("\tif ((dh=DH_new()) == NULL) return(NULL);");
              __printf_chk(1,"\tdh->p=BN_bin2bn(dh%d_p,sizeof(dh%d_p),NULL);\n",iVar13,iVar13);
              __printf_chk(1,"\tdh->g=BN_bin2bn(dh%d_g,sizeof(dh%d_g),NULL);\n",iVar13,iVar13);
              puts("\tif ((dh->p == NULL) || (dh->g == NULL))");
              puts("\t\t{ DH_free(dh); return(NULL); }");
              if (dh->length != 0) {
                __printf_chk(1,"\tdh->length = %ld;\n");
              }
              puts("\treturn(dh);\n\t}");
              CRYPTO_free(to);
            }
            if (!bVar7) {
              if (iVar18 == 1) {
                local_34.ver = ASN1_i2d_bio(i2d_DHparams + 1,(BIO *)bp,(uchar *)dh);
              }
              else {
                if (iVar18 != 3) {
                  uVar14 = 1;
                  BIO_printf(bio_err,"bad output format specified for outfile\n");
                  goto LAB_000188f0;
                }
                local_34.ver = PEM_write_bio_DHparams((BIO *)bp,dh);
              }
              if (local_34.ver == 0) {
                uVar14 = 1;
                BIO_printf(bio_err,"unable to write DH parameters\n");
                ERR_print_errors(bio_err);
                goto LAB_000188f0;
              }
            }
            uVar14 = 0;
          }
          else {
            lVar11 = BIO_ctrl((BIO *)bp,0x6c,5,local_60);
            if (0 < lVar11) goto LAB_000188b0;
            uVar14 = 1;
            perror(local_60);
          }
LAB_000188f0:
          if (pBVar17 != (BIO *)0x0) goto LAB_000188f2;
          goto LAB_000188f8;
        }
        ERR_print_errors(bio_err);
      }
    }
    else {
      if (local_38 == 0) {
        local_38 = 0x200;
      }
      if (!bVar3) goto LAB_0001857c;
      dh = (DH *)0x0;
      BIO_printf(bio_err,"generator may not be chosen for DSA parameters\n");
    }
  }
LAB_00018618:
  uVar14 = 1;
LAB_0001861c:
  if (dh != (DH *)0x0) {
    DH_free(dh);
  }
  return uVar14;
}

