
undefined4 ec_main(int param_1,undefined4 *param_2)

{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  BIO_METHOD *pBVar9;
  BIO *a;
  BIO *bp;
  long lVar10;
  EC_KEY *key;
  EC_GROUP *x;
  char **ppcVar11;
  undefined4 uVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  int in_GS_OFFSET;
  bool bVar16;
  byte bVar17;
  int local_74;
  int local_70;
  char *local_6c;
  char *local_68;
  char *local_64;
  char *local_5c;
  char *local_58;
  point_conversion_form_t local_4c;
  int local_3c;
  EVP_CIPHER *local_34;
  void *local_28;
  void *local_24;
  int local_20;
  
  bVar17 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = (void *)0x0;
  local_24 = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar9 = BIO_s_file();
    bio_err = BIO_new(pBVar9);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar8 = load_config(bio_err,0);
  if (iVar8 != 0) {
    uVar12 = *param_2;
    ppcVar11 = (char **)(param_2 + 1);
    param_1 = param_1 + -1;
    bVar16 = param_1 == 0;
    if (param_1 < 1) {
      bVar3 = false;
      local_4c = POINT_CONVERSION_UNCOMPRESSED;
      local_5c = (char *)0x0;
      local_64 = (char *)0x0;
      local_58 = (char *)0x0;
      local_68 = (char *)0x0;
      local_6c = (char *)0x0;
      bVar6 = false;
      bVar5 = false;
      local_70 = 3;
      local_74 = 3;
      bVar4 = false;
      local_3c = 1;
      bVar7 = false;
      bVar2 = 0;
      bVar1 = false;
      local_34 = (EVP_CIPHER *)0x0;
    }
    else {
      bVar4 = false;
      local_3c = 1;
      bVar3 = false;
      local_4c = POINT_CONVERSION_UNCOMPRESSED;
      local_5c = (char *)0x0;
      local_64 = (char *)0x0;
      local_58 = (char *)0x0;
      local_68 = (char *)0x0;
      local_6c = (char *)0x0;
      bVar7 = false;
      bVar2 = 0;
      bVar1 = false;
      bVar6 = false;
      bVar5 = false;
      local_70 = 3;
      local_74 = 3;
      local_34 = (EVP_CIPHER *)0x0;
LAB_0806108e:
      do {
        pcVar13 = *ppcVar11;
        iVar8 = 8;
        pcVar14 = pcVar13;
        pcVar15 = "-inform";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar16 = *pcVar14 == *pcVar15;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
        } while (bVar16);
        if (bVar16) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            local_74 = str2fmt(ppcVar11[1]);
            ppcVar11 = ppcVar11 + 1;
            goto LAB_08061086;
          }
LAB_08061280:
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
          goto LAB_08061402;
        }
        iVar8 = 9;
        pcVar14 = pcVar13;
        pcVar15 = "-outform";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar16 = *pcVar14 == *pcVar15;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
        } while (bVar16);
        if (!bVar16) {
          bVar16 = *pcVar13 == '-';
          if ((((bVar16) && (bVar16 = pcVar13[1] == 'i', bVar16)) &&
              (bVar16 = pcVar13[2] == 'n', bVar16)) && (bVar16 = pcVar13[3] == '\0', bVar16)) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_08061280;
            local_6c = ppcVar11[1];
            ppcVar11 = ppcVar11 + 1;
          }
          else {
            iVar8 = 5;
            pcVar14 = pcVar13;
            pcVar15 = "-out";
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              bVar16 = *pcVar14 == *pcVar15;
              pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
              pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
            } while (bVar16);
            if (bVar16) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_08061280;
              local_68 = ppcVar11[1];
              ppcVar11 = ppcVar11 + 1;
            }
            else {
              iVar8 = 8;
              pcVar14 = pcVar13;
              pcVar15 = "-passin";
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar16 = *pcVar14 == *pcVar15;
                pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
              } while (bVar16);
              if (bVar16) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_08061280;
                local_64 = ppcVar11[1];
                ppcVar11 = ppcVar11 + 1;
              }
              else {
                iVar8 = 9;
                pcVar14 = pcVar13;
                pcVar15 = "-passout";
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  bVar16 = *pcVar14 == *pcVar15;
                  pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                  pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                } while (bVar16);
                if (bVar16) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_08061280;
                  local_5c = ppcVar11[1];
                  ppcVar11 = ppcVar11 + 1;
                }
                else {
                  iVar8 = 8;
                  pcVar14 = pcVar13;
                  pcVar15 = "-engine";
                  do {
                    if (iVar8 == 0) break;
                    iVar8 = iVar8 + -1;
                    bVar16 = *pcVar14 == *pcVar15;
                    pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                    pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                  } while (bVar16);
                  if (bVar16) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_08061280;
                    local_58 = ppcVar11[1];
                    ppcVar11 = ppcVar11 + 1;
                  }
                  else {
                    iVar8 = 7;
                    pcVar14 = pcVar13;
                    pcVar15 = "-noout";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar16 = *pcVar14 == *pcVar15;
                      pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                      pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                    } while (bVar16);
                    if (bVar16) {
                      bVar6 = true;
                    }
                    else {
                      iVar8 = 6;
                      pcVar14 = pcVar13;
                      pcVar15 = "-text";
                      do {
                        if (iVar8 == 0) break;
                        iVar8 = iVar8 + -1;
                        bVar16 = *pcVar14 == *pcVar15;
                        pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                        pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                      } while (bVar16);
                      if (bVar16) {
                        bVar5 = true;
                      }
                      else {
                        iVar8 = 0xb;
                        pcVar14 = pcVar13;
                        pcVar15 = "-conv_form";
                        do {
                          if (iVar8 == 0) break;
                          iVar8 = iVar8 + -1;
                          bVar16 = *pcVar14 == *pcVar15;
                          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                        } while (bVar16);
                        if (bVar16) {
                          param_1 = param_1 + -1;
                          bVar16 = param_1 == 0;
                          if (bVar16) goto LAB_08061280;
                          pcVar13 = ppcVar11[1];
                          iVar8 = 0xb;
                          ppcVar11 = ppcVar11 + 1;
                          pcVar14 = pcVar13;
                          pcVar15 = "compressed";
                          do {
                            if (iVar8 == 0) break;
                            iVar8 = iVar8 + -1;
                            bVar16 = *pcVar14 == *pcVar15;
                            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                          } while (bVar16);
                          if (bVar16) {
                            bVar3 = true;
                            local_4c = POINT_CONVERSION_COMPRESSED;
                          }
                          else {
                            iVar8 = 0xd;
                            pcVar14 = pcVar13;
                            pcVar15 = "uncompressed";
                            do {
                              if (iVar8 == 0) break;
                              iVar8 = iVar8 + -1;
                              bVar16 = *pcVar14 == *pcVar15;
                              pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                              pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                            } while (bVar16);
                            if (bVar16) {
                              bVar3 = true;
                              local_4c = POINT_CONVERSION_UNCOMPRESSED;
                            }
                            else {
                              iVar8 = 7;
                              pcVar14 = "hybrid";
                              do {
                                if (iVar8 == 0) break;
                                iVar8 = iVar8 + -1;
                                bVar16 = *pcVar13 == *pcVar14;
                                pcVar13 = pcVar13 + (uint)bVar17 * -2 + 1;
                                pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                              } while (bVar16);
                              if (!bVar16) goto LAB_08061280;
                              bVar3 = true;
                              local_4c = POINT_CONVERSION_HYBRID;
                            }
                          }
                        }
                        else {
                          iVar8 = 0xb;
                          pcVar14 = pcVar13;
                          pcVar15 = "-param_enc";
                          do {
                            if (iVar8 == 0) break;
                            iVar8 = iVar8 + -1;
                            bVar16 = *pcVar14 == *pcVar15;
                            pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                            pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                          } while (bVar16);
                          if (bVar16) {
                            param_1 = param_1 + -1;
                            bVar16 = param_1 == 0;
                            if (bVar16) goto LAB_08061280;
                            iVar8 = 0xc;
                            pcVar13 = ppcVar11[1];
                            pcVar14 = "named_curve";
                            do {
                              if (iVar8 == 0) break;
                              iVar8 = iVar8 + -1;
                              bVar16 = *pcVar13 == *pcVar14;
                              pcVar13 = pcVar13 + (uint)bVar17 * -2 + 1;
                              pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                            } while (bVar16);
                            if (bVar16) {
                              bVar4 = true;
                              local_3c = 1;
                              ppcVar11 = ppcVar11 + 1;
                            }
                            else {
                              iVar8 = 9;
                              pcVar13 = ppcVar11[1];
                              pcVar14 = "explicit";
                              do {
                                if (iVar8 == 0) break;
                                iVar8 = iVar8 + -1;
                                bVar16 = *pcVar13 == *pcVar14;
                                pcVar13 = pcVar13 + (uint)bVar17 * -2 + 1;
                                pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                              } while (bVar16);
                              if (!bVar16) goto LAB_08061280;
                              bVar4 = true;
                              local_3c = 0;
                              ppcVar11 = ppcVar11 + 1;
                            }
                          }
                          else {
                            iVar8 = 0xb;
                            pcVar14 = pcVar13;
                            pcVar15 = "-param_out";
                            do {
                              if (iVar8 == 0) break;
                              iVar8 = iVar8 + -1;
                              bVar16 = *pcVar14 == *pcVar15;
                              pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                              pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                            } while (bVar16);
                            if (bVar16) {
                              bVar7 = true;
                            }
                            else {
                              iVar8 = 7;
                              pcVar14 = pcVar13;
                              pcVar15 = "-pubin";
                              do {
                                if (iVar8 == 0) break;
                                iVar8 = iVar8 + -1;
                                bVar16 = *pcVar14 == *pcVar15;
                                pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                              } while (bVar16);
                              if (bVar16) {
                                bVar1 = true;
                              }
                              else {
                                iVar8 = 8;
                                pcVar14 = pcVar13;
                                pcVar15 = "-pubout";
                                do {
                                  if (iVar8 == 0) break;
                                  iVar8 = iVar8 + -1;
                                  bVar16 = *pcVar14 == *pcVar15;
                                  pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                  pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                                } while (bVar16);
                                if (bVar16) {
                                  bVar2 = 1;
                                }
                                else {
                                  local_34 = EVP_get_cipherbyname(pcVar13 + 1);
                                  if (local_34 == (EVP_CIPHER *)0x0) {
                                    BIO_printf(bio_err,"unknown option %s\n",*ppcVar11);
                                    goto LAB_08061280;
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
LAB_08061086:
          param_1 = param_1 + -1;
          bVar16 = param_1 == 0;
          ppcVar11 = ppcVar11 + 1;
          if (bVar16) break;
          goto LAB_0806108e;
        }
        if (param_1 == 1) goto LAB_08061280;
        local_70 = str2fmt(ppcVar11[1]);
        param_1 = param_1 + -2;
        bVar16 = param_1 == 0;
        ppcVar11 = ppcVar11 + 2;
      } while (!bVar16);
    }
    ERR_load_crypto_strings();
    setup_engine(bio_err,local_58,0);
    iVar8 = app_passwd(bio_err,local_64,local_5c,&local_28,&local_24);
    if (iVar8 != 0) {
      pBVar9 = BIO_s_file();
      a = BIO_new(pBVar9);
      pBVar9 = BIO_s_file();
      bp = BIO_new(pBVar9);
      if ((a == (BIO *)0x0) || (bp == (BIO *)0x0)) {
        ERR_print_errors(bio_err);
        if (a != (BIO *)0x0) {
          BIO_free(a);
        }
        if (bp == (BIO *)0x0) goto LAB_08061402;
        uVar12 = 1;
        key = (EC_KEY *)0x0;
      }
      else {
        if (local_6c != (char *)0x0) {
          lVar10 = BIO_ctrl(a,0x6c,3,local_6c);
          if (0 < lVar10) goto LAB_0806117b;
          key = (EC_KEY *)0x0;
          uVar12 = 1;
          perror(local_6c);
          goto LAB_08061233;
        }
        BIO_ctrl(a,0x6a,0,stdin);
LAB_0806117b:
        BIO_printf(bio_err,"read EC key\n");
        if (local_74 == 1) {
          if (bVar1) {
            key = d2i_EC_PUBKEY_bio(a,(EC_KEY **)0x0);
          }
          else {
            key = d2i_ECPrivateKey_bio(a,(EC_KEY **)0x0);
          }
        }
        else {
          if (local_74 != 3) {
            key = (EC_KEY *)0x0;
            uVar12 = 1;
            BIO_printf(bio_err,"bad input format specified for key\n");
            goto LAB_08061233;
          }
          if (bVar1) {
            key = PEM_read_bio_EC_PUBKEY(a,(EC_KEY **)0x0,(undefined1 *)0x0,(void *)0x0);
          }
          else {
            key = PEM_read_bio_ECPrivateKey(a,(EC_KEY **)0x0,(undefined1 *)0x0,local_28);
          }
        }
        if (key == (EC_KEY *)0x0) {
          BIO_printf(bio_err,"unable to load Key\n");
LAB_08061881:
          uVar12 = 1;
          ERR_print_errors(bio_err);
        }
        else {
          if (local_68 == (char *)0x0) {
            BIO_ctrl(bp,0x6a,0,stdout);
          }
          else {
            lVar10 = BIO_ctrl(bp,0x6c,5,local_68);
            if (lVar10 < 1) {
              uVar12 = 1;
              perror(local_68);
              goto LAB_08061233;
            }
          }
          x = EC_KEY_get0_group(key);
          if (bVar3) {
            EC_KEY_set_conv_form(key,local_4c);
          }
          if (bVar4) {
            EC_KEY_set_asn1_flag(key,local_3c);
          }
          if ((bVar5) && (iVar8 = EC_KEY_print(bp,key,0), iVar8 == 0)) {
            perror(local_68);
            goto LAB_08061881;
          }
          uVar12 = 0;
          if (!bVar6) {
            BIO_printf(bio_err,"writing EC key\n");
            if (local_70 == 1) {
              if (bVar7) {
                iVar8 = ASN1_i2d_bio(i2d_ECPKParameters,bp,(uchar *)x);
              }
              else if ((bool)(bVar1 | bVar2)) {
                iVar8 = i2d_EC_PUBKEY_bio(bp,key);
              }
              else {
                iVar8 = i2d_ECPrivateKey_bio(bp,key);
              }
            }
            else {
              if (local_70 != 3) {
                uVar12 = 1;
                BIO_printf(bio_err,"bad output format specified for outfile\n");
                goto LAB_08061233;
              }
              if (bVar7) {
                iVar8 = PEM_write_bio_ECPKParameters(bp,x);
              }
              else if ((bool)(bVar1 | bVar2)) {
                iVar8 = PEM_write_bio_EC_PUBKEY(bp,key);
              }
              else {
                iVar8 = PEM_write_bio_ECPrivateKey
                                  (bp,key,local_34,(uchar *)0x0,0,(undefined1 *)0x0,local_24);
              }
            }
            uVar12 = 0;
            if (iVar8 == 0) {
              BIO_printf(bio_err,"unable to write private key\n");
              goto LAB_08061881;
            }
          }
        }
LAB_08061233:
        BIO_free(a);
      }
      BIO_free_all(bp);
      if (key != (EC_KEY *)0x0) {
        EC_KEY_free(key);
      }
      goto LAB_08061407;
    }
    BIO_printf(bio_err,"Error getting passwords\n");
  }
LAB_08061402:
  uVar12 = 1;
LAB_08061407:
  if (local_28 != (void *)0x0) {
    CRYPTO_free(local_28);
  }
  if (local_24 != (void *)0x0) {
    CRYPTO_free(local_24);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}

