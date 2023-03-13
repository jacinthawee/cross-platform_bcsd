
undefined4 rsa_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  BIO_METHOD *pBVar8;
  BIO *a;
  EVP_PKEY *pEVar9;
  rsa_st *key;
  long lVar10;
  char *pcVar11;
  ulong uVar12;
  uchar *data;
  char **ppcVar13;
  char *pcVar14;
  char *pcVar15;
  int in_GS_OFFSET;
  bool bVar16;
  byte bVar17;
  int local_70;
  int local_6c;
  char *local_68;
  char *local_64;
  char *local_60;
  char *local_58;
  char *local_54;
  uint local_50;
  int local_4c;
  uint local_44;
  int local_40;
  EVP_CIPHER *local_38;
  void *local_2c;
  void *local_28;
  uchar *local_24;
  int local_20;
  
  bVar17 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = (void *)0x0;
  local_28 = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar8 = BIO_s_file();
    bio_err = BIO_new(pBVar8);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar6 = load_config(bio_err,0);
  if (iVar6 != 0) {
    uVar7 = *param_2;
    ppcVar13 = (char **)(param_2 + 1);
    param_1 = param_1 + -1;
    bVar16 = param_1 == 0;
    if (param_1 < 1) {
      local_60 = (char *)0x0;
      local_64 = (char *)0x0;
      local_68 = (char *)0x0;
      local_6c = 3;
      local_70 = 3;
      local_40 = 2;
      bVar4 = false;
      local_54 = (char *)0x0;
      local_58 = (char *)0x0;
      local_44 = 0;
      local_50 = 0;
      bVar5 = false;
      bVar2 = false;
      bVar3 = false;
      local_4c = 0;
      local_38 = (EVP_CIPHER *)0x0;
    }
    else {
      local_40 = 2;
      bVar4 = false;
      local_54 = (char *)0x0;
      local_58 = (char *)0x0;
      local_60 = (char *)0x0;
      local_64 = (char *)0x0;
      local_68 = (char *)0x0;
      local_44 = 0;
      local_50 = 0;
      bVar5 = false;
      bVar2 = false;
      bVar3 = false;
      local_6c = 3;
      local_70 = 3;
      local_38 = (EVP_CIPHER *)0x0;
      local_4c = 0;
LAB_0805e126:
      do {
        pcVar11 = *ppcVar13;
        iVar6 = 8;
        pcVar14 = pcVar11;
        pcVar15 = "-inform";
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar16 = *pcVar14 == *pcVar15;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
        } while (bVar16);
        if (bVar16) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            ppcVar1 = ppcVar13 + 1;
            ppcVar13 = ppcVar13 + 1;
            local_70 = str2fmt(*ppcVar1);
            goto LAB_0805e11e;
          }
LAB_0805e2d0:
          BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar7);
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
          goto LAB_0805e1e8;
        }
        iVar6 = 9;
        pcVar14 = pcVar11;
        pcVar15 = "-outform";
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar16 = *pcVar14 == *pcVar15;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
        } while (bVar16);
        if (!bVar16) {
          bVar16 = *pcVar11 == '-';
          if ((((bVar16) && (bVar16 = pcVar11[1] == 'i', bVar16)) &&
              (bVar16 = pcVar11[2] == 'n', bVar16)) && (bVar16 = pcVar11[3] == '\0', bVar16)) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0805e2d0;
            local_68 = ppcVar13[1];
            ppcVar13 = ppcVar13 + 1;
          }
          else {
            iVar6 = 5;
            pcVar14 = pcVar11;
            pcVar15 = "-out";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar16 = *pcVar14 == *pcVar15;
              pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
              pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
            } while (bVar16);
            if (bVar16) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0805e2d0;
              local_64 = ppcVar13[1];
              ppcVar13 = ppcVar13 + 1;
            }
            else {
              iVar6 = 8;
              pcVar14 = pcVar11;
              pcVar15 = "-passin";
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar16 = *pcVar14 == *pcVar15;
                pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
              } while (bVar16);
              if (bVar16) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_0805e2d0;
                local_60 = ppcVar13[1];
                ppcVar13 = ppcVar13 + 1;
              }
              else {
                iVar6 = 9;
                pcVar14 = pcVar11;
                pcVar15 = "-passout";
                do {
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  bVar16 = *pcVar14 == *pcVar15;
                  pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                  pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                } while (bVar16);
                if (bVar16) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_0805e2d0;
                  local_58 = ppcVar13[1];
                  ppcVar13 = ppcVar13 + 1;
                }
                else {
                  iVar6 = 8;
                  pcVar14 = pcVar11;
                  pcVar15 = "-engine";
                  do {
                    if (iVar6 == 0) break;
                    iVar6 = iVar6 + -1;
                    bVar16 = *pcVar14 == *pcVar15;
                    pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                    pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                  } while (bVar16);
                  if (bVar16) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_0805e2d0;
                    local_54 = ppcVar13[1];
                    ppcVar13 = ppcVar13 + 1;
                  }
                  else {
                    iVar6 = 8;
                    pcVar14 = pcVar11;
                    pcVar15 = "-sgckey";
                    do {
                      if (iVar6 == 0) break;
                      iVar6 = iVar6 + -1;
                      bVar16 = *pcVar14 == *pcVar15;
                      pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                      pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                    } while (bVar16);
                    if (bVar16) {
                      local_4c = 1;
                    }
                    else {
                      iVar6 = 7;
                      pcVar14 = pcVar11;
                      pcVar15 = "-pubin";
                      do {
                        if (iVar6 == 0) break;
                        iVar6 = iVar6 + -1;
                        bVar16 = *pcVar14 == *pcVar15;
                        pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                        pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                      } while (bVar16);
                      if (bVar16) {
                        local_50 = 1;
                      }
                      else {
                        iVar6 = 8;
                        pcVar14 = pcVar11;
                        pcVar15 = "-pubout";
                        do {
                          if (iVar6 == 0) break;
                          iVar6 = iVar6 + -1;
                          bVar16 = *pcVar14 == *pcVar15;
                          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                        } while (bVar16);
                        if (bVar16) {
                          local_44 = 1;
                        }
                        else {
                          iVar6 = 0x11;
                          pcVar14 = pcVar11;
                          pcVar15 = "-RSAPublicKey_in";
                          do {
                            if (iVar6 == 0) break;
                            iVar6 = iVar6 + -1;
                            bVar16 = *pcVar14 == *pcVar15;
                            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                          } while (bVar16);
                          if (bVar16) {
                            local_50 = 2;
                          }
                          else {
                            iVar6 = 0x12;
                            pcVar14 = pcVar11;
                            pcVar15 = "-RSAPublicKey_out";
                            do {
                              if (iVar6 == 0) break;
                              iVar6 = iVar6 + -1;
                              bVar16 = *pcVar14 == *pcVar15;
                              pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                              pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                            } while (bVar16);
                            if (bVar16) {
                              local_44 = 2;
                            }
                            else {
                              iVar6 = 0xc;
                              pcVar14 = pcVar11;
                              pcVar15 = "-pvk-strong";
                              do {
                                if (iVar6 == 0) break;
                                iVar6 = iVar6 + -1;
                                bVar16 = *pcVar14 == *pcVar15;
                                pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                              } while (bVar16);
                              if (bVar16) {
                                local_40 = 2;
                              }
                              else {
                                iVar6 = 10;
                                pcVar14 = pcVar11;
                                pcVar15 = "-pvk-weak";
                                do {
                                  if (iVar6 == 0) break;
                                  iVar6 = iVar6 + -1;
                                  bVar16 = *pcVar14 == *pcVar15;
                                  pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                  pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                                } while (bVar16);
                                if (bVar16) {
                                  local_40 = 1;
                                }
                                else {
                                  iVar6 = 10;
                                  pcVar14 = pcVar11;
                                  pcVar15 = "-pvk-none";
                                  do {
                                    if (iVar6 == 0) break;
                                    iVar6 = iVar6 + -1;
                                    bVar16 = *pcVar14 == *pcVar15;
                                    pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                    pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                                  } while (bVar16);
                                  if (bVar16) {
                                    local_40 = 0;
                                  }
                                  else {
                                    iVar6 = 7;
                                    pcVar14 = pcVar11;
                                    pcVar15 = "-noout";
                                    do {
                                      if (iVar6 == 0) break;
                                      iVar6 = iVar6 + -1;
                                      bVar16 = *pcVar14 == *pcVar15;
                                      pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                      pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                                    } while (bVar16);
                                    if (bVar16) {
                                      bVar5 = true;
                                    }
                                    else {
                                      iVar6 = 6;
                                      pcVar14 = pcVar11;
                                      pcVar15 = "-text";
                                      do {
                                        if (iVar6 == 0) break;
                                        iVar6 = iVar6 + -1;
                                        bVar16 = *pcVar14 == *pcVar15;
                                        pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                        pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                                      } while (bVar16);
                                      if (bVar16) {
                                        bVar3 = true;
                                      }
                                      else {
                                        iVar6 = 9;
                                        pcVar14 = pcVar11;
                                        pcVar15 = "-modulus";
                                        do {
                                          if (iVar6 == 0) break;
                                          iVar6 = iVar6 + -1;
                                          bVar16 = *pcVar14 == *pcVar15;
                                          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                                        } while (bVar16);
                                        if (bVar16) {
                                          bVar4 = true;
                                        }
                                        else {
                                          iVar6 = 7;
                                          pcVar14 = pcVar11;
                                          pcVar15 = "-check";
                                          do {
                                            if (iVar6 == 0) break;
                                            iVar6 = iVar6 + -1;
                                            bVar16 = *pcVar14 == *pcVar15;
                                            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                                          } while (bVar16);
                                          if (bVar16) {
                                            bVar2 = true;
                                          }
                                          else {
                                            local_38 = EVP_get_cipherbyname(pcVar11 + 1);
                                            if (local_38 == (EVP_CIPHER *)0x0) {
                                              BIO_printf(bio_err,"unknown option %s\n",*ppcVar13);
                                              goto LAB_0805e2d0;
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
LAB_0805e11e:
          param_1 = param_1 + -1;
          bVar16 = param_1 == 0;
          ppcVar13 = ppcVar13 + 1;
          if (bVar16) break;
          goto LAB_0805e126;
        }
        if (param_1 == 1) goto LAB_0805e2d0;
        local_6c = str2fmt(ppcVar13[1]);
        param_1 = param_1 + -2;
        bVar16 = param_1 == 0;
        ppcVar13 = ppcVar13 + 2;
      } while (!bVar16);
    }
    ERR_load_crypto_strings();
    uVar7 = setup_engine(bio_err,local_54,0);
    iVar6 = app_passwd(bio_err,local_60,local_58,&local_2c,&local_28);
    if (iVar6 == 0) {
      BIO_printf(bio_err,"Error getting passwords\n");
    }
    else if ((bVar2) && (local_50 != 0)) {
      BIO_printf(bio_err,"Only private keys can be checked\n");
    }
    else {
      pBVar8 = BIO_s_file();
      a = BIO_new(pBVar8);
      if (local_50 == 0) {
        if ((local_70 != 4) || (iVar6 = 8, local_4c == 0)) {
          iVar6 = local_70;
        }
        pEVar9 = (EVP_PKEY *)load_key(bio_err,local_68,iVar6,1,local_2c,uVar7,"Private Key");
      }
      else {
        if (local_50 == 2) {
          if (local_70 == 3) {
            local_70 = 9;
            iVar6 = local_70;
          }
          else {
            iVar6 = -1;
            if (local_70 == 1) {
              iVar6 = 10;
            }
          }
        }
        else {
          iVar6 = local_70;
          if ((local_70 == 4) && (iVar6 = 8, local_4c == 0)) {
            iVar6 = local_70;
          }
        }
        local_70 = iVar6;
        pEVar9 = (EVP_PKEY *)load_pubkey(bio_err,local_68,local_70,1,local_2c,uVar7,"Public Key");
      }
      if (pEVar9 == (EVP_PKEY *)0x0) {
        EVP_PKEY_free((EVP_PKEY *)0x0);
      }
      else {
        key = EVP_PKEY_get1_RSA(pEVar9);
        EVP_PKEY_free(pEVar9);
        if (key != (rsa_st *)0x0) {
          if (local_64 == (char *)0x0) {
            BIO_ctrl(a,0x6a,0,stdout);
LAB_0805e700:
            if ((bVar3) && (iVar6 = RSA_print(a,key,0), iVar6 == 0)) {
              perror(local_64);
LAB_0805e938:
              uVar7 = 1;
              ERR_print_errors(bio_err);
            }
            else {
              if (bVar4) {
                BIO_printf(a,"Modulus=");
                BN_print(a,key->n);
                BIO_printf(a,"\n");
              }
              if (bVar2) {
                iVar6 = RSA_check_key(key);
                if (iVar6 == 1) {
                  BIO_printf(a,"RSA key ok\n");
LAB_0805e9da:
                  uVar12 = ERR_peek_error();
                  if (uVar12 == 0) goto LAB_0805e724;
                }
                else {
                  if (iVar6 == 0) {
                    while ((((uVar12 = ERR_peek_error(), uVar12 != 0 && (uVar12 >> 0x18 == 4)) &&
                            ((uVar12 >> 0xc & 0xfff) == 0x7b)) && ((uVar12 & 0xfff) != 0x41))) {
                      pcVar11 = ERR_reason_error_string(uVar12);
                      BIO_printf(a,"RSA key error: %s\n",pcVar11);
                      ERR_get_error();
                    }
                    goto LAB_0805e9da;
                  }
                  if (iVar6 != -1) goto LAB_0805e9da;
                }
                uVar7 = 1;
                ERR_print_errors(bio_err);
              }
              else {
LAB_0805e724:
                if (!bVar5) {
                  BIO_printf(bio_err,"writing RSA key\n");
                  if (local_6c == 1) {
                    if ((local_50 | local_44) == 0) {
                      iVar6 = i2d_RSAPrivateKey_bio(a,key);
                    }
                    else if (local_44 == 2) {
                      iVar6 = i2d_RSAPublicKey_bio(a,key);
                    }
                    else {
                      iVar6 = i2d_RSA_PUBKEY_bio(a,key);
                    }
                  }
                  else {
                    if (local_6c == 4) {
                      iVar6 = i2d_RSA_NET(key,(uchar **)0x0,(cb *)0x0,local_4c);
                      data = (uchar *)CRYPTO_malloc(iVar6,"rsa.c",0x17c);
                      local_24 = data;
                      if (data == (uchar *)0x0) {
                        uVar7 = 1;
                        BIO_printf(bio_err,"Memory allocation failure\n");
                      }
                      else {
                        i2d_RSA_NET(key,&local_24,(cb *)0x0,local_4c);
                        uVar7 = 0;
                        BIO_write(a,data,iVar6);
                        CRYPTO_free(data);
                      }
                      goto joined_r0x0805eb7f;
                    }
                    if (local_6c == 3) {
                      if ((local_50 | local_44) == 0) {
                        iVar6 = PEM_write_bio_RSAPrivateKey
                                          (a,key,local_38,(uchar *)0x0,0,(undefined1 *)0x0,local_28)
                        ;
                      }
                      else if (local_44 == 2) {
                        iVar6 = PEM_write_bio_RSAPublicKey(a,key);
                      }
                      else {
                        iVar6 = PEM_write_bio_RSA_PUBKEY(a,key);
                      }
                    }
                    else {
                      if (1 < local_6c - 0xbU) {
                        uVar7 = 1;
                        BIO_printf(bio_err,"bad output format specified for outfile\n");
                        goto joined_r0x0805eb7f;
                      }
                      pEVar9 = EVP_PKEY_new();
                      EVP_PKEY_set1_RSA(pEVar9,key);
                      if (local_6c == 0xc) {
                        iVar6 = i2b_PVK_bio(a,pEVar9,local_40,(undefined1 *)0x0,local_28);
                      }
                      else if ((local_50 | local_44) == 0) {
                        iVar6 = i2b_PrivateKey_bio(a,pEVar9);
                      }
                      else {
                        iVar6 = i2b_PublicKey_bio(a,pEVar9);
                      }
                      EVP_PKEY_free(pEVar9);
                    }
                  }
                  if (iVar6 < 1) {
                    BIO_printf(bio_err,"unable to write key\n");
                    goto LAB_0805e938;
                  }
                }
                uVar7 = 0;
              }
            }
          }
          else {
            lVar10 = BIO_ctrl(a,0x6c,5,local_64);
            if (0 < lVar10) goto LAB_0805e700;
            uVar7 = 1;
            perror(local_64);
          }
joined_r0x0805eb7f:
          if (a != (BIO *)0x0) {
            BIO_free_all(a);
          }
          RSA_free(key);
          goto LAB_0805e1ed;
        }
      }
      ERR_print_errors(bio_err);
      if (a != (BIO *)0x0) {
        BIO_free_all(a);
      }
    }
  }
LAB_0805e1e8:
  uVar7 = 1;
LAB_0805e1ed:
  if (local_2c != (void *)0x0) {
    CRYPTO_free(local_2c);
  }
  if (local_28 != (void *)0x0) {
    CRYPTO_free(local_28);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}

