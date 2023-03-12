
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 dsa_main(int param_1,undefined4 *param_2)

{
  char **ppcVar1;
  bool bVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  BIO_METHOD *pBVar9;
  dsa_st *r;
  BIO *bp;
  long lVar10;
  EVP_PKEY *pEVar11;
  undefined4 uVar12;
  char **ppcVar13;
  char *__s1;
  undefined4 uVar14;
  char *__s;
  char *pcVar15;
  dsa_st *key;
  char *local_5c;
  char *local_54;
  char *local_50;
  char *local_4c;
  int local_44;
  EVP_CIPHER *local_38;
  void *local_30;
  void *local_2c [2];
  
  local_30 = (void *)0x0;
  local_2c[0] = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar9 = BIO_s_file();
    bio_err = BIO_new(pBVar9);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar6 = load_config(bio_err,0);
  if (iVar6 != 0) {
    param_1 = param_1 + -1;
    ppcVar13 = (char **)(param_2 + 1);
    uVar12 = *param_2;
    __s = (char *)0x0;
    iVar6 = 3;
    local_50 = (char *)0x0;
    uVar14 = 3;
    local_54 = (char *)0x0;
    local_4c = (char *)0x0;
    local_5c = (char *)0x0;
    bVar3 = 0;
    bVar2 = false;
    bVar5 = false;
    bVar4 = false;
    local_38 = (EVP_CIPHER *)0x0;
    if (param_1 < 1) {
      local_44 = 2;
      pcVar15 = __s;
      __s = (char *)0x0;
    }
    else {
      local_44 = 2;
      pcVar15 = (char *)0x0;
LAB_0002090a:
      do {
        __s1 = *ppcVar13;
        iVar7 = strcmp(__s1,"-inform");
        iVar8 = local_44;
        if (iVar7 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            ppcVar1 = ppcVar13 + 1;
            ppcVar13 = ppcVar13 + 1;
            uVar14 = str2fmt(*ppcVar1);
            goto LAB_000208fc;
          }
LAB_00020a9c:
          BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar12);
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
          goto LAB_00020bb6;
        }
        iVar7 = strcmp(__s1,"-outform");
        if (iVar7 != 0) {
          if ((((*__s1 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00020a9c;
            __s = ppcVar13[1];
            ppcVar13 = ppcVar13 + 1;
          }
          else {
            iVar7 = strcmp(__s1,"-out");
            if (iVar7 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00020a9c;
              local_5c = ppcVar13[1];
              ppcVar13 = ppcVar13 + 1;
            }
            else {
              iVar7 = strcmp(__s1,"-passin");
              if (iVar7 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_00020a9c;
                local_54 = ppcVar13[1];
                ppcVar13 = ppcVar13 + 1;
              }
              else {
                iVar7 = strcmp(__s1,"-passout");
                if (iVar7 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_00020a9c;
                  local_50 = ppcVar13[1];
                  ppcVar13 = ppcVar13 + 1;
                }
                else {
                  iVar7 = strcmp(__s1,"-engine");
                  if (iVar7 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_00020a9c;
                    local_4c = ppcVar13[1];
                    ppcVar13 = ppcVar13 + 1;
                  }
                  else {
                    iVar8 = strcmp(__s1,"-pvk-strong");
                    if (iVar8 == 0) {
                      local_44 = 2;
                      iVar8 = local_44;
                    }
                    else {
                      iVar8 = strcmp(__s1,"-pvk-weak");
                      if (iVar8 == 0) {
                        local_44 = 1;
                        iVar8 = local_44;
                      }
                      else {
                        iVar8 = strcmp(__s1,"-pvk-none");
                        if (iVar8 != 0) {
                          iVar8 = strcmp(__s1,"-noout");
                          if (iVar8 == 0) {
                            bVar5 = true;
                            iVar8 = local_44;
                          }
                          else {
                            iVar8 = strcmp(__s1,"-text");
                            if (iVar8 == 0) {
                              bVar4 = true;
                              iVar8 = local_44;
                            }
                            else {
                              iVar8 = strcmp(__s1,"-modulus");
                              if (iVar8 == 0) {
                                pcVar15 = (char *)0x1;
                                iVar8 = local_44;
                              }
                              else {
                                iVar8 = strcmp(__s1,"-pubin");
                                if (iVar8 == 0) {
                                  bVar2 = true;
                                  iVar8 = local_44;
                                }
                                else {
                                  iVar8 = strcmp(__s1,"-pubout");
                                  if (iVar8 == 0) {
                                    bVar3 = 1;
                                    iVar8 = local_44;
                                  }
                                  else {
                                    local_38 = EVP_get_cipherbyname(__s1 + 1);
                                    iVar8 = local_44;
                                    if (local_38 == (EVP_CIPHER *)0x0) {
                                      BIO_printf(bio_err,"unknown option %s\n",*ppcVar13);
                                      goto LAB_00020a9c;
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
LAB_000208fc:
          local_44 = iVar8;
          param_1 = param_1 + -1;
          ppcVar13 = ppcVar13 + 1;
          if (param_1 < 1) break;
          goto LAB_0002090a;
        }
        if (param_1 == 1) goto LAB_00020a9c;
        param_1 = param_1 + -2;
        iVar6 = str2fmt(ppcVar13[1]);
        ppcVar13 = ppcVar13 + 2;
      } while (0 < param_1);
    }
    ERR_load_crypto_strings();
    uVar12 = setup_engine(bio_err,local_4c,0);
    iVar8 = app_passwd(bio_err,local_54,local_50,&local_30,local_2c);
    if (iVar8 != 0) {
      pBVar9 = BIO_s_file();
      r = (dsa_st *)BIO_new(pBVar9);
      pBVar9 = BIO_s_file();
      bp = BIO_new(pBVar9);
      if (r == (dsa_st *)0x0 || bp == (BIO *)0x0) {
        ERR_print_errors(bio_err);
        uVar14 = 1;
        if (r != (dsa_st *)0x0) {
          key = (dsa_st *)0x0;
LAB_00020a6c:
          uVar14 = 1;
          goto LAB_00020a6e;
        }
      }
      else {
        key = (dsa_st *)0x0;
        if (__s == (char *)0x0) {
          BIO_ctrl((BIO *)r,0x6a,0,stdin);
LAB_000209e0:
          BIO_printf(bio_err,"read DSA key\n");
          if (bVar2) {
            pEVar11 = (EVP_PKEY *)load_pubkey(bio_err,__s,uVar14,1,local_30,uVar12,"Public Key");
          }
          else {
            pEVar11 = (EVP_PKEY *)load_key(bio_err,__s,uVar14,1,local_30,uVar12,"Private Key");
          }
          if (pEVar11 != (EVP_PKEY *)0x0) {
            key = EVP_PKEY_get1_DSA(pEVar11);
            EVP_PKEY_free(pEVar11);
            if (key != (dsa_st *)0x0) {
              if (local_5c == (char *)0x0) {
                BIO_ctrl(bp,0x6a,0,stdout);
              }
              else {
                lVar10 = BIO_ctrl(bp,0x6c,5,local_5c);
                if (lVar10 < 1) {
                  uVar14 = 1;
                  perror(local_5c);
                  goto LAB_00020a6e;
                }
              }
              if ((bVar4) && (iVar8 = DSA_print(bp,key,0), iVar8 == 0)) {
                uVar14 = 1;
                perror(local_5c);
                ERR_print_errors(bio_err);
              }
              else {
                if (pcVar15 != (char *)0x0) {
                  fwrite("Public Key=",1,0xb,stdout);
                  BN_print(bp,key->pub_key);
                  fputc(10,stdout);
                }
                if (bVar5) goto LAB_00020a6c;
                BIO_printf(bio_err,"writing DSA key\n");
                if (iVar6 == 1) {
                  if ((bool)(bVar3 | bVar2)) {
                    iVar6 = i2d_DSA_PUBKEY_bio(bp,key);
                  }
                  else {
                    iVar6 = i2d_DSAPrivateKey_bio(bp,key);
                  }
                }
                else if (iVar6 == 3) {
                  if ((bool)(bVar3 | bVar2)) {
                    iVar6 = PEM_write_bio_DSA_PUBKEY(bp,key);
                  }
                  else {
                    iVar6 = PEM_write_bio_DSAPrivateKey
                                      (bp,key,local_38,(uchar *)0x0,0,(undefined1 *)0x0,local_2c[0])
                    ;
                  }
                }
                else {
                  if (1 < iVar6 - 0xbU) {
                    uVar14 = 1;
                    BIO_printf(bio_err,"bad output format specified for outfile\n");
                    goto LAB_00020a6e;
                  }
                  pEVar11 = EVP_PKEY_new();
                  EVP_PKEY_set1_DSA(pEVar11,key);
                  if (iVar6 == 0xc) {
                    iVar6 = i2b_PVK_bio(bp,pEVar11,local_44,(undefined1 *)0x0,local_2c[0]);
                  }
                  else if ((bool)(bVar3 | bVar2)) {
                    iVar6 = i2b_PublicKey_bio(bp,pEVar11);
                  }
                  else {
                    iVar6 = i2b_PrivateKey_bio(bp,pEVar11);
                  }
                  EVP_PKEY_free(pEVar11);
                }
                if (iVar6 < 1) {
                  uVar14 = 1;
                  BIO_printf(bio_err,"unable to write private key\n");
                  ERR_print_errors(bio_err);
                }
                else {
                  uVar14 = 0;
                }
              }
              goto LAB_00020a6e;
            }
          }
          key = (dsa_st *)0x0;
          BIO_printf(bio_err,"unable to load Key\n");
          ERR_print_errors(bio_err);
          uVar14 = 1;
        }
        else {
          lVar10 = BIO_ctrl((BIO *)r,0x6c,3,__s);
          if (0 < lVar10) goto LAB_000209e0;
          perror(__s);
          uVar14 = 1;
        }
LAB_00020a6e:
        BIO_free((BIO *)r);
        r = key;
      }
      if (bp != (BIO *)0x0) {
        BIO_free_all(bp);
      }
      if (r != (dsa_st *)0x0) {
        DSA_free(r);
      }
      goto LAB_00020bb8;
    }
    BIO_printf(bio_err,"Error getting passwords\n");
  }
LAB_00020bb6:
  uVar14 = 1;
LAB_00020bb8:
  if (local_30 != (void *)0x0) {
    CRYPTO_free(local_30);
  }
  if (local_2c[0] != (void *)0x0) {
    CRYPTO_free(local_2c[0]);
  }
  return uVar14;
}

