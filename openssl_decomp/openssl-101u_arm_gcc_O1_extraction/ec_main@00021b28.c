
undefined4 ec_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  bool bVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  BIO_METHOD *pBVar10;
  BIO *bp;
  BIO *bp_00;
  long lVar11;
  EC_GROUP *x;
  undefined4 uVar12;
  char **ppcVar13;
  char *pcVar14;
  char *__s;
  int iVar15;
  char *pcVar16;
  BIO *key;
  char *local_68;
  char *local_64;
  char *local_5c;
  char *local_58;
  point_conversion_form_t local_48;
  EVP_CIPHER *local_40;
  int local_38;
  void *local_30;
  void *local_2c [2];
  
  local_30 = (void *)0x0;
  local_2c[0] = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar10 = BIO_s_file();
    bio_err = BIO_new(pBVar10);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar8 = load_config(bio_err,0);
  if (iVar8 != 0) {
    param_1 = param_1 + -1;
    ppcVar13 = (char **)(param_2 + 1);
    uVar12 = *param_2;
    __s = (char *)0x0;
    iVar15 = 3;
    bVar4 = false;
    iVar8 = 3;
    local_5c = (char *)0x0;
    local_64 = (char *)0x0;
    local_58 = (char *)0x0;
    local_68 = (char *)0x0;
    bVar7 = false;
    bVar3 = 0;
    bVar2 = false;
    bVar6 = false;
    bVar5 = false;
    local_40 = (EVP_CIPHER *)0x0;
    if (param_1 < 1) {
      local_38 = 1;
      local_48 = POINT_CONVERSION_UNCOMPRESSED;
      pcVar16 = __s;
      __s = (char *)0x0;
    }
    else {
      local_38 = 1;
      iVar8 = 3;
      local_48 = POINT_CONVERSION_UNCOMPRESSED;
      pcVar16 = (char *)0x0;
LAB_00021bc4:
      do {
        pcVar14 = *ppcVar13;
        iVar9 = strcmp(pcVar14,"-inform");
        if (iVar9 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            ppcVar1 = ppcVar13 + 1;
            ppcVar13 = ppcVar13 + 1;
            iVar8 = str2fmt(*ppcVar1);
            goto LAB_00021bb6;
          }
LAB_00021d42:
          BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar12);
          BIO_printf(bio_err,"where options are\n");
          BIO_printf(bio_err," -inform arg     input format - DER or PEM\n");
          BIO_printf(bio_err," -outform arg    output format - DER or PEM\n");
          BIO_printf(bio_err," -in arg         input file\n");
          BIO_printf(bio_err," -passin arg     input file pass phrase source\n");
          BIO_printf(bio_err," -out arg        output file\n");
          BIO_printf(bio_err," -passout arg    output file pass phrase source\n");
          BIO_printf(bio_err," -engine e       use engine e, possibly a hardware device.\n");
          BIO_printf(bio_err,
                     " -des            encrypt PEM output, instead of \'des\' every other \n                 cipher supported by OpenSSL can be used\n"
                    );
          BIO_printf(bio_err," -text           print the key\n");
          BIO_printf(bio_err," -noout          don\'t print key out\n");
          BIO_printf(bio_err," -param_out      print the elliptic curve parameters\n");
          BIO_printf(bio_err," -conv_form arg  specifies the point conversion form \n");
          BIO_printf(bio_err,"                 possible values: compressed\n");
          BIO_printf(bio_err,"                                  uncompressed (default)\n");
          BIO_printf(bio_err,"                                   hybrid\n");
          BIO_printf(bio_err," -param_enc arg  specifies the way the ec parameters are encoded\n");
          BIO_printf(bio_err,"                 in the asn1 der encoding\n");
          BIO_printf(bio_err,"                 possible values: named_curve (default)\n");
          BIO_printf(bio_err,"                                  explicit\n");
          goto LAB_00021e6a;
        }
        iVar9 = strcmp(pcVar14,"-outform");
        if (iVar9 != 0) {
          if ((((*pcVar14 == '-') && (pcVar14[1] == 'i')) && (pcVar14[2] == 'n')) &&
             (pcVar14[3] == '\0')) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00021d42;
            __s = ppcVar13[1];
            ppcVar13 = ppcVar13 + 1;
          }
          else {
            iVar9 = strcmp(pcVar14,"-out");
            if (iVar9 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00021d42;
              local_68 = ppcVar13[1];
              ppcVar13 = ppcVar13 + 1;
            }
            else {
              iVar9 = strcmp(pcVar14,"-passin");
              if (iVar9 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_00021d42;
                local_64 = ppcVar13[1];
                ppcVar13 = ppcVar13 + 1;
              }
              else {
                iVar9 = strcmp(pcVar14,"-passout");
                if (iVar9 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_00021d42;
                  local_5c = ppcVar13[1];
                  ppcVar13 = ppcVar13 + 1;
                }
                else {
                  iVar9 = strcmp(pcVar14,"-engine");
                  if (iVar9 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_00021d42;
                    local_58 = ppcVar13[1];
                    ppcVar13 = ppcVar13 + 1;
                  }
                  else {
                    iVar9 = strcmp(pcVar14,"-noout");
                    if (iVar9 == 0) {
                      bVar6 = true;
                    }
                    else {
                      iVar9 = strcmp(pcVar14,"-text");
                      if (iVar9 == 0) {
                        bVar5 = true;
                      }
                      else {
                        iVar9 = strcmp(pcVar14,"-conv_form");
                        if (iVar9 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 == 0) goto LAB_00021d42;
                          pcVar14 = ppcVar13[1];
                          ppcVar13 = ppcVar13 + 1;
                          iVar9 = strcmp(pcVar14,"compressed");
                          if (iVar9 == 0) {
                            bVar4 = true;
                            local_48 = POINT_CONVERSION_COMPRESSED;
                          }
                          else {
                            iVar9 = strcmp(pcVar14,"uncompressed");
                            if (iVar9 == 0) {
                              bVar4 = true;
                              local_48 = POINT_CONVERSION_UNCOMPRESSED;
                            }
                            else {
                              iVar9 = strcmp(pcVar14,"hybrid");
                              if (iVar9 != 0) goto LAB_00021d42;
                              bVar4 = true;
                              local_48 = POINT_CONVERSION_HYBRID;
                            }
                          }
                        }
                        else {
                          iVar9 = strcmp(pcVar14,"-param_enc");
                          if (iVar9 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 == 0) goto LAB_00021d42;
                            pcVar16 = ppcVar13[1];
                            ppcVar13 = ppcVar13 + 1;
                            iVar9 = strcmp(pcVar16,"named_curve");
                            if (iVar9 == 0) {
                              pcVar16 = (char *)0x1;
                              local_38 = 1;
                            }
                            else {
                              local_38 = strcmp(pcVar16,"explicit");
                              if (local_38 != 0) goto LAB_00021d42;
                              pcVar16 = (char *)0x1;
                            }
                          }
                          else {
                            iVar9 = strcmp(pcVar14,"-param_out");
                            if (iVar9 == 0) {
                              bVar7 = true;
                            }
                            else {
                              iVar9 = strcmp(pcVar14,"-pubin");
                              if (iVar9 == 0) {
                                bVar2 = true;
                              }
                              else {
                                iVar9 = strcmp(pcVar14,"-pubout");
                                if (iVar9 == 0) {
                                  bVar3 = 1;
                                }
                                else {
                                  local_40 = EVP_get_cipherbyname(pcVar14 + 1);
                                  if (local_40 == (EVP_CIPHER *)0x0) {
                                    BIO_printf(bio_err,"unknown option %s\n",*ppcVar13);
                                    goto LAB_00021d42;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LAB_00021bb6:
          param_1 = param_1 + -1;
          ppcVar13 = ppcVar13 + 1;
          if (param_1 < 1) break;
          goto LAB_00021bc4;
        }
        if (param_1 == 1) goto LAB_00021d42;
        param_1 = param_1 + -2;
        iVar15 = str2fmt(ppcVar13[1]);
        ppcVar13 = ppcVar13 + 2;
      } while (0 < param_1);
    }
    ERR_load_crypto_strings();
    setup_engine(bio_err,local_58,0);
    iVar9 = app_passwd(bio_err,local_64,local_5c,&local_30,local_2c);
    if (iVar9 != 0) {
      pBVar10 = BIO_s_file();
      bp = BIO_new(pBVar10);
      pBVar10 = BIO_s_file();
      bp_00 = BIO_new(pBVar10);
      if (bp == (BIO *)0x0 || bp_00 == (BIO *)0x0) {
        ERR_print_errors(bio_err);
        uVar12 = 1;
        if (bp != (BIO *)0x0) {
          key = (BIO *)0x0;
          uVar12 = 1;
          goto LAB_00021d10;
        }
      }
      else {
        if (__s == (char *)0x0) {
          BIO_ctrl(bp,0x6a,0,stdin);
        }
        else {
          lVar11 = BIO_ctrl(bp,0x6c,3,__s);
          key = (BIO *)0x0;
          if (lVar11 < 1) {
            uVar12 = 1;
            perror(__s);
            goto LAB_00021d10;
          }
        }
        BIO_printf(bio_err,"read EC key\n");
        if (iVar8 == 1) {
          if (bVar2) {
            key = (BIO *)d2i_EC_PUBKEY_bio(bp,(EC_KEY **)0x0);
          }
          else {
            key = (BIO *)d2i_ECPrivateKey_bio(bp,(EC_KEY **)0x0);
          }
        }
        else {
          if (iVar8 != 3) {
            key = (BIO *)0x0;
            BIO_printf(bio_err,"bad input format specified for key\n");
            uVar12 = 1;
            goto LAB_00021d10;
          }
          if (bVar2) {
            key = (BIO *)PEM_read_bio_EC_PUBKEY(bp,(EC_KEY **)0x0,(undefined1 *)0x0,(void *)0x0);
          }
          else {
            key = (BIO *)PEM_read_bio_ECPrivateKey(bp,(EC_KEY **)0x0,(undefined1 *)0x0,local_30);
          }
        }
        if (key == (BIO *)0x0) {
          uVar12 = 1;
          BIO_printf(bio_err,"unable to load Key\n");
          ERR_print_errors(bio_err);
        }
        else {
          if (local_68 == (char *)0x0) {
            BIO_ctrl(bp_00,0x6a,0,stdout);
          }
          else {
            lVar11 = BIO_ctrl(bp_00,0x6c,5,local_68);
            if (lVar11 < 1) {
              uVar12 = 1;
              perror(local_68);
              goto LAB_00021d10;
            }
          }
          x = EC_KEY_get0_group((EC_KEY *)key);
          if (bVar4) {
            EC_KEY_set_conv_form((EC_KEY *)key,local_48);
          }
          if (pcVar16 != (char *)0x0) {
            EC_KEY_set_asn1_flag((EC_KEY *)key,local_38);
          }
          if ((bVar5) && (iVar8 = EC_KEY_print(bp_00,(EC_KEY *)key,0), iVar8 == 0)) {
            uVar12 = 1;
            perror(local_68);
            ERR_print_errors(bio_err);
          }
          else {
            if (!bVar6) {
              BIO_printf(bio_err,"writing EC key\n");
              if (iVar15 == 1) {
                if (bVar7) {
                  iVar8 = ASN1_i2d_bio(i2d_ECPKParameters + 1,bp_00,(uchar *)x);
                }
                else if ((bool)(bVar3 | bVar2)) {
                  iVar8 = i2d_EC_PUBKEY_bio(bp_00,(EC_KEY *)key);
                }
                else {
                  iVar8 = i2d_ECPrivateKey_bio(bp_00,(EC_KEY *)key);
                }
              }
              else {
                if (iVar15 != 3) {
                  uVar12 = 1;
                  BIO_printf(bio_err,"bad output format specified for outfile\n");
                  goto LAB_00021d10;
                }
                if (bVar7) {
                  iVar8 = PEM_write_bio_ECPKParameters(bp_00,x);
                }
                else if ((bool)(bVar3 | bVar2)) {
                  iVar8 = PEM_write_bio_EC_PUBKEY(bp_00,(EC_KEY *)key);
                }
                else {
                  iVar8 = PEM_write_bio_ECPrivateKey
                                    (bp_00,(EC_KEY *)key,local_40,(uchar *)0x0,0,(undefined1 *)0x0,
                                     local_2c[0]);
                }
              }
              if (iVar8 == 0) {
                uVar12 = 1;
                BIO_printf(bio_err,"unable to write private key\n");
                ERR_print_errors(bio_err);
                goto LAB_00021d10;
              }
            }
            uVar12 = 0;
          }
        }
LAB_00021d10:
        BIO_free(bp);
        bp = key;
      }
      if (bp_00 != (BIO *)0x0) {
        BIO_free_all(bp_00);
      }
      if (bp != (BIO *)0x0) {
        EC_KEY_free((EC_KEY *)bp);
      }
      goto LAB_00021e6c;
    }
    BIO_printf(bio_err,"Error getting passwords\n");
  }
LAB_00021e6a:
  uVar12 = 1;
LAB_00021e6c:
  if (local_30 != (void *)0x0) {
    CRYPTO_free(local_30);
  }
  if (local_2c[0] != (void *)0x0) {
    CRYPTO_free(local_2c[0]);
  }
  return uVar12;
}

