
int rsa_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  BIO_METHOD *pBVar6;
  BIO *bp;
  EVP_PKEY *pEVar7;
  rsa_st *key;
  long lVar8;
  ulong uVar9;
  uchar *data;
  undefined4 uVar10;
  uint uVar11;
  char **ppcVar12;
  char *__s1;
  int iVar13;
  char *pcVar14;
  char *pcVar15;
  char *local_6c;
  char *local_68;
  char *local_60;
  uint local_5c;
  char *local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  EVP_CIPHER *local_40;
  void *local_34;
  void *local_30;
  uchar *local_2c [2];
  
  local_34 = (void *)0x0;
  local_30 = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar6 = BIO_s_file();
    bio_err = BIO_new(pBVar6);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar3 = load_config(bio_err,0);
  if (iVar3 != 0) {
    param_1 = param_1 + -1;
    ppcVar12 = (char **)(param_2 + 1);
    uVar10 = *param_2;
    pcVar14 = (char *)0x0;
    iVar3 = 3;
    local_58 = (char *)0x0;
    local_60 = (char *)0x0;
    local_68 = (char *)0x0;
    local_6c = (char *)0x0;
    local_48 = 0;
    local_50 = 0;
    local_54 = 0;
    local_5c = 0;
    bVar2 = false;
    if (param_1 < 1) {
      local_4c = 0;
      local_40 = (EVP_CIPHER *)0x0;
      local_44 = 2;
      iVar13 = iVar3;
      pcVar15 = pcVar14;
      pcVar14 = (char *)0x0;
    }
    else {
      local_40 = (EVP_CIPHER *)0x0;
      local_4c = 0;
      iVar13 = 3;
      local_44 = 2;
      pcVar15 = (char *)0x0;
LAB_0001fbae:
      do {
        __s1 = *ppcVar12;
        iVar4 = strcmp(__s1,"-inform");
        iVar5 = local_44;
        if (iVar4 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            ppcVar1 = ppcVar12 + 1;
            ppcVar12 = ppcVar12 + 1;
            iVar13 = str2fmt(*ppcVar1);
            goto LAB_0001fba0;
          }
LAB_0001fd9e:
          BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar10);
          BIO_printf(bio_err,"where options are\n");
          BIO_printf(bio_err," -inform arg     input format - one of DER NET PEM\n");
          BIO_printf(bio_err," -outform arg    output format - one of DER NET PEM\n");
          BIO_printf(bio_err," -in arg         input file\n");
          BIO_printf(bio_err," -sgckey         Use IIS SGC key format\n");
          BIO_printf(bio_err," -passin arg     input file pass phrase source\n");
          BIO_printf(bio_err," -out arg        output file\n");
          BIO_printf(bio_err," -passout arg    output file pass phrase source\n");
          BIO_printf(bio_err," -des            encrypt PEM output with cbc des\n");
          BIO_printf(bio_err,
                     " -des3           encrypt PEM output with ede cbc des using 168 bit key\n");
          BIO_printf(bio_err," -idea           encrypt PEM output with cbc idea\n");
          BIO_printf(bio_err," -seed           encrypt PEM output with cbc seed\n");
          BIO_printf(bio_err," -aes128, -aes192, -aes256\n");
          BIO_printf(bio_err,"                 encrypt PEM output with cbc aes\n");
          BIO_printf(bio_err," -camellia128, -camellia192, -camellia256\n");
          BIO_printf(bio_err,"                 encrypt PEM output with cbc camellia\n");
          BIO_printf(bio_err," -text           print the key in text\n");
          BIO_printf(bio_err," -noout          don\'t print key out\n");
          BIO_printf(bio_err," -modulus        print the RSA key modulus\n");
          BIO_printf(bio_err," -check          verify key consistency\n");
          BIO_printf(bio_err," -pubin          expect a public key in input file\n");
          BIO_printf(bio_err," -pubout         output a public key\n");
          BIO_printf(bio_err," -engine e       use engine e, possibly a hardware device.\n");
          goto LAB_0001fd04;
        }
        iVar4 = strcmp(__s1,"-outform");
        if (iVar4 == 0) {
          if (param_1 == 1) goto LAB_0001fd9e;
          param_1 = param_1 + -2;
          iVar3 = str2fmt(ppcVar12[1]);
          ppcVar12 = ppcVar12 + 2;
          if (param_1 < 1) break;
          goto LAB_0001fbae;
        }
        if ((((*__s1 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0001fd9e;
          pcVar14 = ppcVar12[1];
          ppcVar12 = ppcVar12 + 1;
        }
        else {
          iVar4 = strcmp(__s1,"-out");
          if (iVar4 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0001fd9e;
            local_6c = ppcVar12[1];
            ppcVar12 = ppcVar12 + 1;
          }
          else {
            iVar4 = strcmp(__s1,"-passin");
            if (iVar4 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0001fd9e;
              local_68 = ppcVar12[1];
              ppcVar12 = ppcVar12 + 1;
            }
            else {
              iVar4 = strcmp(__s1,"-passout");
              if (iVar4 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_0001fd9e;
                local_60 = ppcVar12[1];
                ppcVar12 = ppcVar12 + 1;
              }
              else {
                iVar4 = strcmp(__s1,"-engine");
                if (iVar4 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_0001fd9e;
                  local_58 = ppcVar12[1];
                  ppcVar12 = ppcVar12 + 1;
                }
                else {
                  iVar4 = strcmp(__s1,"-sgckey");
                  if (iVar4 == 0) {
                    local_4c = 1;
                  }
                  else {
                    iVar4 = strcmp(__s1,"-pubin");
                    if (iVar4 == 0) {
                      local_50 = 1;
                    }
                    else {
                      iVar4 = strcmp(__s1,"-pubout");
                      if (iVar4 == 0) {
                        local_48 = 1;
                      }
                      else {
                        iVar4 = strcmp(__s1,"-RSAPublicKey_in");
                        if (iVar4 == 0) {
                          local_50 = 2;
                        }
                        else {
                          iVar4 = strcmp(__s1,"-RSAPublicKey_out");
                          if (iVar4 == 0) {
                            local_48 = 2;
                          }
                          else {
                            iVar5 = strcmp(__s1,"-pvk-strong");
                            if (iVar5 == 0) {
                              local_44 = 2;
                              iVar5 = local_44;
                            }
                            else {
                              iVar5 = strcmp(__s1,"-pvk-weak");
                              if (iVar5 == 0) {
                                local_44 = 1;
                                iVar5 = local_44;
                              }
                              else {
                                iVar5 = strcmp(__s1,"-pvk-none");
                                if (iVar5 != 0) {
                                  iVar5 = strcmp(__s1,"-noout");
                                  if (iVar5 == 0) {
                                    local_54 = 1;
                                    iVar5 = local_44;
                                  }
                                  else {
                                    iVar5 = strcmp(__s1,"-text");
                                    if (iVar5 == 0) {
                                      bVar2 = true;
                                      iVar5 = local_44;
                                    }
                                    else {
                                      iVar5 = strcmp(__s1,"-modulus");
                                      if (iVar5 == 0) {
                                        pcVar15 = (char *)0x1;
                                        iVar5 = local_44;
                                      }
                                      else {
                                        iVar5 = strcmp(__s1,"-check");
                                        if (iVar5 == 0) {
                                          local_5c = 1;
                                          iVar5 = local_44;
                                        }
                                        else {
                                          local_40 = EVP_get_cipherbyname(__s1 + 1);
                                          iVar5 = local_44;
                                          if (local_40 == (EVP_CIPHER *)0x0) {
                                            BIO_printf(bio_err,"unknown option %s\n",*ppcVar12);
                                            goto LAB_0001fd9e;
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
                }
              }
            }
          }
        }
LAB_0001fba0:
        local_44 = iVar5;
        param_1 = param_1 + -1;
        ppcVar12 = ppcVar12 + 1;
      } while (0 < param_1);
    }
    ERR_load_crypto_strings();
    uVar10 = setup_engine(bio_err,local_58,0);
    iVar5 = app_passwd(bio_err,local_68,local_60,&local_34,&local_30);
    if (iVar5 == 0) {
      BIO_printf(bio_err,"Error getting passwords\n");
    }
    else {
      uVar11 = local_50;
      if (local_50 != 0) {
        uVar11 = 1;
      }
      if ((uVar11 & local_5c) == 0) {
        pBVar6 = BIO_s_file();
        bp = BIO_new(pBVar6);
        if (uVar11 == 0) {
          uVar11 = local_4c ^ 1;
          if (iVar13 != 4) {
            uVar11 = 1;
          }
          if (uVar11 == 0) {
            iVar13 = 8;
          }
          pEVar7 = (EVP_PKEY *)load_key(bio_err,pcVar14,iVar13,1,local_34,uVar10,"Private Key");
        }
        else {
          if (local_50 == 2) {
            if (iVar13 == 3) {
              iVar13 = 9;
            }
            else if (iVar13 == 1) {
              iVar13 = 10;
            }
            else {
              iVar13 = -1;
            }
          }
          else {
            uVar11 = local_4c;
            if (iVar13 != 4) {
              uVar11 = 0;
            }
            if (uVar11 != 0) {
              iVar13 = 8;
            }
          }
          pEVar7 = (EVP_PKEY *)load_pubkey(bio_err,pcVar14,iVar13,1,local_34,uVar10,"Public Key");
        }
        if (pEVar7 == (EVP_PKEY *)0x0) {
          EVP_PKEY_free((EVP_PKEY *)0x0);
LAB_000200e4:
          key = (rsa_st *)0x0;
          ERR_print_errors(bio_err);
          local_54 = 1;
        }
        else {
          key = EVP_PKEY_get1_RSA(pEVar7);
          EVP_PKEY_free(pEVar7);
          if (key == (rsa_st *)0x0) goto LAB_000200e4;
          if (local_6c == (char *)0x0) {
            BIO_ctrl(bp,0x6a,0,stdout);
LAB_0001fcc0:
            if ((bVar2) && (iVar13 = RSA_print(bp,key,0), iVar13 == 0)) {
              local_54 = 1;
              perror(local_6c);
              ERR_print_errors(bio_err);
            }
            else {
              if (pcVar15 != (char *)0x0) {
                BIO_printf(bp,"Modulus=");
                BN_print(bp,key->n);
                BIO_printf(bp,"\n");
              }
              if (local_5c == 0) {
LAB_0001fcd6:
                if (local_54 == 0) {
                  BIO_printf(bio_err,"writing RSA key\n");
                  if (iVar3 == 1) {
                    if ((local_48 | local_50) == 0) {
                      iVar3 = i2d_RSAPrivateKey_bio(bp,key);
                    }
                    else if (local_48 == 2) {
                      iVar3 = i2d_RSAPublicKey_bio(bp,key);
                    }
                    else {
                      iVar3 = i2d_RSA_PUBKEY_bio(bp,key);
                    }
                  }
                  else {
                    if (iVar3 == 4) {
                      iVar3 = i2d_RSA_NET(key,(uchar **)0x0,(cb *)0x0,local_4c);
                      data = (uchar *)CRYPTO_malloc(iVar3,"rsa.c",0x17c);
                      local_2c[0] = data;
                      if (data == (uchar *)0x0) {
                        local_54 = 1;
                        BIO_printf(bio_err,"Memory allocation failure\n");
                      }
                      else {
                        i2d_RSA_NET(key,local_2c,(cb *)0x0,local_4c);
                        BIO_write(bp,data,iVar3);
                        CRYPTO_free(data);
                      }
                      goto LAB_0001fce0;
                    }
                    if (iVar3 == 3) {
                      if ((local_48 | local_50) == 0) {
                        iVar3 = PEM_write_bio_RSAPrivateKey
                                          (bp,key,local_40,(uchar *)0x0,0,(undefined1 *)0x0,local_30
                                          );
                      }
                      else if (local_48 == 2) {
                        iVar3 = PEM_write_bio_RSAPublicKey(bp,key);
                      }
                      else {
                        iVar3 = PEM_write_bio_RSA_PUBKEY(bp,key);
                      }
                    }
                    else {
                      if (1 < iVar3 - 0xbU) {
                        local_54 = 1;
                        BIO_printf(bio_err,"bad output format specified for outfile\n");
                        goto LAB_0001fce0;
                      }
                      pEVar7 = EVP_PKEY_new();
                      EVP_PKEY_set1_RSA(pEVar7,key);
                      if (iVar3 == 0xc) {
                        iVar3 = i2b_PVK_bio(bp,pEVar7,local_44,(undefined1 *)0x0,local_30);
                      }
                      else if ((local_48 | local_50) == 0) {
                        iVar3 = i2b_PrivateKey_bio(bp,pEVar7);
                      }
                      else {
                        iVar3 = i2b_PublicKey_bio(bp,pEVar7);
                      }
                      EVP_PKEY_free(pEVar7);
                    }
                  }
                  if (iVar3 < 1) {
                    local_54 = 1;
                    BIO_printf(bio_err,"unable to write key\n");
                    ERR_print_errors(bio_err);
                    goto LAB_0001fce0;
                  }
                }
                local_54 = 0;
              }
              else {
                iVar13 = RSA_check_key(key);
                if (iVar13 == 1) {
                  BIO_printf(bp,"RSA key ok\n");
LAB_0002010a:
                  uVar9 = ERR_peek_error();
                  if (uVar9 == 0) goto LAB_0001fcd6;
                }
                else {
                  if (iVar13 == 0) {
                    while( true ) {
                      uVar9 = ERR_peek_error();
                      if (((uVar9 == 0) || (uVar9 >> 0x18 != 4)) ||
                         (((uVar9 << 8) >> 0x14 != 0x7b || ((uVar9 & 0xfff) == 0x41)))) break;
                      pcVar14 = ERR_reason_error_string(uVar9);
                      BIO_printf(bp,"RSA key error: %s\n",pcVar14);
                      ERR_get_error();
                    }
                    goto LAB_0002010a;
                  }
                  if (iVar13 != -1) goto LAB_0002010a;
                }
                local_54 = 1;
                ERR_print_errors(bio_err);
              }
            }
          }
          else {
            lVar8 = BIO_ctrl(bp,0x6c,5,local_6c);
            if (0 < lVar8) goto LAB_0001fcc0;
            local_54 = 1;
            perror(local_6c);
          }
        }
LAB_0001fce0:
        if (bp != (BIO *)0x0) {
          BIO_free_all(bp);
        }
        if (key != (rsa_st *)0x0) {
          RSA_free(key);
        }
        goto LAB_0001fd06;
      }
      BIO_printf(bio_err,"Only private keys can be checked\n");
    }
  }
LAB_0001fd04:
  local_54 = 1;
LAB_0001fd06:
  if (local_34 != (void *)0x0) {
    CRYPTO_free(local_34);
  }
  if (local_30 != (void *)0x0) {
    CRYPTO_free(local_30);
  }
  return local_54;
}

