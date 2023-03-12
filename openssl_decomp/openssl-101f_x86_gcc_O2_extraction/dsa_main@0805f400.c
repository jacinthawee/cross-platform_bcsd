
undefined4 dsa_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  char *pcVar2;
  bool bVar3;
  byte bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  undefined4 uVar9;
  BIO_METHOD *pBVar10;
  BIO *a;
  BIO *bp;
  long lVar11;
  EVP_PKEY *pEVar12;
  dsa_st *key;
  char **ppcVar13;
  char *pcVar14;
  char *pcVar15;
  int in_GS_OFFSET;
  bool bVar16;
  byte bVar17;
  undefined4 local_68;
  int local_64;
  char *local_60;
  char *local_5c;
  char *local_58;
  char *local_50;
  char *local_4c;
  int local_48;
  EVP_CIPHER *local_3c;
  void *local_28;
  void *local_24;
  int local_20;
  
  bVar17 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = (void *)0x0;
  local_24 = (void *)0x0;
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
    uVar9 = *param_2;
    ppcVar13 = (char **)(param_2 + 1);
    param_1 = param_1 + -1;
    bVar16 = param_1 == 0;
    if (param_1 < 1) {
      local_50 = (char *)0x0;
      local_58 = (char *)0x0;
      local_5c = (char *)0x0;
      local_60 = (char *)0x0;
      local_64 = 3;
      local_68 = 3;
      local_48 = 2;
      bVar6 = false;
      local_4c = (char *)0x0;
      bVar4 = 0;
      bVar3 = false;
      bVar7 = false;
      bVar5 = false;
      local_3c = (EVP_CIPHER *)0x0;
    }
    else {
      local_48 = 2;
      bVar6 = false;
      local_50 = (char *)0x0;
      local_58 = (char *)0x0;
      local_4c = (char *)0x0;
      local_5c = (char *)0x0;
      local_60 = (char *)0x0;
      bVar4 = 0;
      bVar3 = false;
      bVar7 = false;
      bVar5 = false;
      local_64 = 3;
      local_68 = 3;
      local_3c = (EVP_CIPHER *)0x0;
LAB_0805f506:
      do {
        pcVar2 = *ppcVar13;
        iVar8 = 8;
        pcVar14 = pcVar2;
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
            ppcVar1 = ppcVar13 + 1;
            ppcVar13 = ppcVar13 + 1;
            local_68 = str2fmt(*ppcVar1);
            goto LAB_0805f4fe;
          }
LAB_0805f6f8:
          BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar9);
          BIO_printf(bio_err,"where options are\n");
          BIO_printf(bio_err," -inform arg     input format - DER or PEM\n");
          BIO_printf(bio_err," -outform arg    output format - DER or PEM\n");
          BIO_printf(bio_err," -in arg         input file\n");
          BIO_printf(bio_err," -passin arg     input file pass phrase source\n");
          BIO_printf(bio_err," -out arg        output file\n");
          BIO_printf(bio_err," -passout arg    output file pass phrase source\n");
          BIO_printf(bio_err," -engine e       use engine e, possibly a hardware device.\n");
          BIO_printf(bio_err," -des            encrypt PEM output with cbc des\n");
          BIO_printf(bio_err,
                     " -des3           encrypt PEM output with ede cbc des using 168 bit key\n");
          BIO_printf(bio_err," -idea           encrypt PEM output with cbc idea\n");
          BIO_printf(bio_err," -aes128, -aes192, -aes256\n");
          BIO_printf(bio_err,"                 encrypt PEM output with cbc aes\n");
          BIO_printf(bio_err," -camellia128, -camellia192, -camellia256\n");
          BIO_printf(bio_err,"                 encrypt PEM output with cbc camellia\n");
          BIO_printf(bio_err," -seed           encrypt PEM output with cbc seed\n");
          BIO_printf(bio_err," -text           print the key in text\n");
          BIO_printf(bio_err," -noout          don\'t print key out\n");
          BIO_printf(bio_err," -modulus        print the DSA public value\n");
          goto LAB_0805f868;
        }
        iVar8 = 9;
        pcVar14 = pcVar2;
        pcVar15 = "-outform";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar16 = *pcVar14 == *pcVar15;
          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
        } while (bVar16);
        if (!bVar16) {
          bVar16 = *pcVar2 == '-';
          if ((((bVar16) && (bVar16 = pcVar2[1] == 'i', bVar16)) &&
              (bVar16 = pcVar2[2] == 'n', bVar16)) && (bVar16 = pcVar2[3] == '\0', bVar16)) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0805f6f8;
            local_60 = ppcVar13[1];
            ppcVar13 = ppcVar13 + 1;
          }
          else {
            iVar8 = 5;
            pcVar14 = pcVar2;
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
              if (param_1 == 0) goto LAB_0805f6f8;
              local_5c = ppcVar13[1];
              ppcVar13 = ppcVar13 + 1;
            }
            else {
              iVar8 = 8;
              pcVar14 = pcVar2;
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
                if (param_1 == 0) goto LAB_0805f6f8;
                local_58 = ppcVar13[1];
                ppcVar13 = ppcVar13 + 1;
              }
              else {
                iVar8 = 9;
                pcVar14 = pcVar2;
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
                  if (param_1 == 0) goto LAB_0805f6f8;
                  local_50 = ppcVar13[1];
                  ppcVar13 = ppcVar13 + 1;
                }
                else {
                  iVar8 = 8;
                  pcVar14 = pcVar2;
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
                    if (param_1 == 0) goto LAB_0805f6f8;
                    local_4c = ppcVar13[1];
                    ppcVar13 = ppcVar13 + 1;
                  }
                  else {
                    iVar8 = 0xc;
                    pcVar14 = pcVar2;
                    pcVar15 = "-pvk-strong";
                    do {
                      if (iVar8 == 0) break;
                      iVar8 = iVar8 + -1;
                      bVar16 = *pcVar14 == *pcVar15;
                      pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                      pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                    } while (bVar16);
                    if (bVar16) {
                      local_48 = 2;
                    }
                    else {
                      iVar8 = 10;
                      pcVar14 = pcVar2;
                      pcVar15 = "-pvk-weak";
                      do {
                        if (iVar8 == 0) break;
                        iVar8 = iVar8 + -1;
                        bVar16 = *pcVar14 == *pcVar15;
                        pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                        pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                      } while (bVar16);
                      if (bVar16) {
                        local_48 = 1;
                      }
                      else {
                        iVar8 = 10;
                        pcVar14 = pcVar2;
                        pcVar15 = "-pvk-none";
                        do {
                          if (iVar8 == 0) break;
                          iVar8 = iVar8 + -1;
                          bVar16 = *pcVar14 == *pcVar15;
                          pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                          pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                        } while (bVar16);
                        if (bVar16) {
                          local_48 = 0;
                        }
                        else {
                          iVar8 = 7;
                          pcVar14 = pcVar2;
                          pcVar15 = "-noout";
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
                            iVar8 = 6;
                            pcVar14 = pcVar2;
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
                              iVar8 = 9;
                              pcVar14 = pcVar2;
                              pcVar15 = "-modulus";
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
                                iVar8 = 7;
                                pcVar14 = pcVar2;
                                pcVar15 = "-pubin";
                                do {
                                  if (iVar8 == 0) break;
                                  iVar8 = iVar8 + -1;
                                  bVar16 = *pcVar14 == *pcVar15;
                                  pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                  pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                                } while (bVar16);
                                if (bVar16) {
                                  bVar3 = true;
                                }
                                else {
                                  iVar8 = 8;
                                  pcVar14 = pcVar2;
                                  pcVar15 = "-pubout";
                                  do {
                                    if (iVar8 == 0) break;
                                    iVar8 = iVar8 + -1;
                                    bVar16 = *pcVar14 == *pcVar15;
                                    pcVar14 = pcVar14 + (uint)bVar17 * -2 + 1;
                                    pcVar15 = pcVar15 + (uint)bVar17 * -2 + 1;
                                  } while (bVar16);
                                  if (bVar16) {
                                    bVar4 = 1;
                                  }
                                  else {
                                    local_3c = EVP_get_cipherbyname(pcVar2 + 1);
                                    if (local_3c == (EVP_CIPHER *)0x0) {
                                      BIO_printf(bio_err,"unknown option %s\n",*ppcVar13);
                                      goto LAB_0805f6f8;
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
LAB_0805f4fe:
          param_1 = param_1 + -1;
          bVar16 = param_1 == 0;
          ppcVar13 = ppcVar13 + 1;
          if (bVar16) break;
          goto LAB_0805f506;
        }
        if (param_1 == 1) goto LAB_0805f6f8;
        local_64 = str2fmt(ppcVar13[1]);
        param_1 = param_1 + -2;
        bVar16 = param_1 == 0;
        ppcVar13 = ppcVar13 + 2;
      } while (!bVar16);
    }
    ERR_load_crypto_strings();
    uVar9 = setup_engine(bio_err,local_4c,0);
    iVar8 = app_passwd(bio_err,local_58,local_50,&local_28,&local_24);
    if (iVar8 != 0) {
      pBVar10 = BIO_s_file();
      a = BIO_new(pBVar10);
      pBVar10 = BIO_s_file();
      bp = BIO_new(pBVar10);
      if ((a == (BIO *)0x0) || (bp == (BIO *)0x0)) {
        ERR_print_errors(bio_err);
        if (a != (BIO *)0x0) {
          BIO_free(a);
        }
        if (bp == (BIO *)0x0) goto LAB_0805f868;
        key = (dsa_st *)0x0;
        uVar9 = 1;
      }
      else {
        if (local_60 != (char *)0x0) {
          lVar11 = BIO_ctrl(a,0x6c,3,local_60);
          if (0 < lVar11) goto LAB_0805f5ed;
          key = (dsa_st *)0x0;
          uVar9 = 1;
          perror(local_60);
          goto LAB_0805f6aa;
        }
        BIO_ctrl(a,0x6a,0,stdin);
LAB_0805f5ed:
        BIO_printf(bio_err,"read DSA key\n");
        if (bVar3) {
          pEVar12 = (EVP_PKEY *)load_pubkey(bio_err,local_60,local_68,1,local_28,uVar9,"Public Key")
          ;
        }
        else {
          pEVar12 = (EVP_PKEY *)load_key(bio_err,local_60,local_68,1,local_28,uVar9,"Private Key");
        }
        if (pEVar12 == (EVP_PKEY *)0x0) {
LAB_0805fbb8:
          key = (dsa_st *)0x0;
          uVar9 = 1;
          BIO_printf(bio_err,"unable to load Key\n");
          ERR_print_errors(bio_err);
        }
        else {
          key = EVP_PKEY_get1_DSA(pEVar12);
          EVP_PKEY_free(pEVar12);
          if (key == (dsa_st *)0x0) goto LAB_0805fbb8;
          if (local_5c == (char *)0x0) {
            BIO_ctrl(bp,0x6a,0,stdout);
          }
          else {
            lVar11 = BIO_ctrl(bp,0x6c,5,local_5c);
            if (lVar11 < 1) {
              uVar9 = 1;
              perror(local_5c);
              goto LAB_0805f6aa;
            }
          }
          if ((bVar5) && (iVar8 = DSA_print(bp,key,0), iVar8 == 0)) {
            perror(local_5c);
LAB_0805fc96:
            uVar9 = 1;
            ERR_print_errors(bio_err);
          }
          else {
            if (bVar6) {
              fwrite("Public Key=",1,0xb,stdout);
              BN_print(bp,key->pub_key);
              fputc(10,stdout);
            }
            uVar9 = 1;
            if (!bVar7) {
              BIO_printf(bio_err,"writing DSA key\n");
              if (local_64 == 1) {
                if ((bool)(bVar3 | bVar4)) {
                  iVar8 = i2d_DSA_PUBKEY_bio(bp,key);
                }
                else {
                  iVar8 = i2d_DSAPrivateKey_bio(bp,key);
                }
              }
              else if (local_64 == 3) {
                if ((bool)(bVar3 | bVar4)) {
                  iVar8 = PEM_write_bio_DSA_PUBKEY(bp,key);
                }
                else {
                  iVar8 = PEM_write_bio_DSAPrivateKey
                                    (bp,key,local_3c,(uchar *)0x0,0,(undefined1 *)0x0,local_24);
                }
              }
              else {
                if (1 < local_64 - 0xbU) {
                  BIO_printf(bio_err,"bad output format specified for outfile\n");
                  goto LAB_0805f6aa;
                }
                pEVar12 = EVP_PKEY_new();
                EVP_PKEY_set1_DSA(pEVar12,key);
                if (local_64 == 0xc) {
                  iVar8 = i2b_PVK_bio(bp,pEVar12,local_48,(undefined1 *)0x0,local_24);
                }
                else if ((bool)(bVar3 | bVar4)) {
                  iVar8 = i2b_PublicKey_bio(bp,pEVar12);
                }
                else {
                  iVar8 = i2b_PrivateKey_bio(bp,pEVar12);
                }
                EVP_PKEY_free(pEVar12);
              }
              uVar9 = 0;
              if (iVar8 < 1) {
                BIO_printf(bio_err,"unable to write private key\n");
                goto LAB_0805fc96;
              }
            }
          }
        }
LAB_0805f6aa:
        BIO_free(a);
      }
      BIO_free_all(bp);
      if (key != (dsa_st *)0x0) {
        DSA_free(key);
      }
      goto LAB_0805f86d;
    }
    BIO_printf(bio_err,"Error getting passwords\n");
  }
LAB_0805f868:
  uVar9 = 1;
LAB_0805f86d:
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
  return uVar9;
}

