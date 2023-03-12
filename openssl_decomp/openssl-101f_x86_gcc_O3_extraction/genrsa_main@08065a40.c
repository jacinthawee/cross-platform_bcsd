
bool genrsa_main(int param_1,int param_2)

{
  ulong *puVar1;
  char cVar2;
  BIGNUM *a;
  int iVar3;
  BIO_METHOD *pBVar4;
  ENGINE *engine;
  long lVar5;
  undefined4 uVar6;
  RSA *rsa;
  ulong *puVar7;
  ulong uVar8;
  undefined4 extraout_ECX;
  char **ppcVar9;
  char *pcVar10;
  char *pcVar11;
  int in_GS_OFFSET;
  bool bVar12;
  byte bVar13;
  char *parg;
  char *pcVar14;
  BIO *local_54;
  ulong local_50;
  char *local_4c;
  char *local_48;
  EVP_CIPHER *local_44;
  char *local_40;
  int local_3c;
  void *local_38;
  void *local_34;
  char *local_30;
  BN_GENCB local_2c;
  int local_20;
  
  bVar13 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_3c = 0x400;
  local_38 = (void *)0x0;
  a = BN_new();
  if (a != (BIGNUM *)0x0) {
    signal(0xd,(__sighandler_t)0x1);
    local_2c.ver = 2;
    local_2c.cb.cb_1 = genrsa_cb;
    local_2c.arg = bio_err;
    if (bio_err == (BIO *)0x0) {
      pBVar4 = BIO_s_file();
      bio_err = BIO_new(pBVar4);
      if (bio_err != (BIO *)0x0) {
        BIO_ctrl(bio_err,0x6a,0x10,stderr);
      }
    }
    iVar3 = load_config(bio_err,0);
    local_54 = (BIO *)0x0;
    if (iVar3 != 0) {
      pBVar4 = BIO_s_file();
      local_54 = BIO_new(pBVar4);
      if (local_54 != (BIO *)0x0) {
        ppcVar9 = (char **)(param_2 + 4);
        param_1 = param_1 + -1;
        bVar12 = param_1 == 0;
        if (0 < param_1) {
          local_48 = (char *)0x0;
          local_4c = (char *)0x0;
          local_40 = (char *)0x0;
          parg = (char *)0x0;
          local_50 = 0x10001;
          local_44 = (EVP_CIPHER *)0x0;
LAB_08065baa:
          pcVar14 = *ppcVar9;
          iVar3 = 5;
          pcVar10 = pcVar14;
          pcVar11 = "-out";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar12 = *pcVar10 == *pcVar11;
            pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
            pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
          } while (bVar12);
          if (bVar12) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              parg = ppcVar9[1];
              ppcVar9 = ppcVar9 + 1;
              goto LAB_08065ba2;
            }
            goto LAB_08065e00;
          }
          bVar12 = *pcVar14 == '-';
          if (bVar12) {
            cVar2 = pcVar14[1];
            if (cVar2 == '3') {
              bVar12 = pcVar14[2] == '\0';
              if (!bVar12) goto LAB_08065bc5;
              local_50 = 3;
            }
            else {
              if ((((cVar2 != 'F') && (bVar12 = cVar2 == 'f', !bVar12)) ||
                  (bVar12 = pcVar14[2] == '4', !bVar12)) || (bVar12 = pcVar14[3] == '\0', !bVar12))
              goto LAB_08065bc5;
              local_50 = 0x10001;
            }
          }
          else {
LAB_08065bc5:
            iVar3 = 8;
            pcVar10 = pcVar14;
            pcVar11 = "-engine";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar12 = *pcVar10 == *pcVar11;
              pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
              pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
            } while (bVar12);
            if (bVar12) {
              if (param_1 == 1) goto LAB_08065e00;
              local_4c = ppcVar9[1];
              param_1 = param_1 + -2;
              ppcVar9 = ppcVar9 + 2;
              goto joined_r0x08065bf2;
            }
            iVar3 = 6;
            pcVar10 = pcVar14;
            pcVar11 = "-rand";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar12 = *pcVar10 == *pcVar11;
              pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
              pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
            } while (bVar12);
            if (bVar12) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_08065e00;
              local_48 = ppcVar9[1];
              ppcVar9 = ppcVar9 + 1;
            }
            else {
              iVar3 = 5;
              pcVar10 = pcVar14;
              pcVar11 = "-des";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar12 = *pcVar10 == *pcVar11;
                pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
              } while (bVar12);
              if (bVar12) {
                local_44 = EVP_des_cbc();
              }
              else {
                iVar3 = 6;
                pcVar10 = pcVar14;
                pcVar11 = "-des3";
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar12 = *pcVar10 == *pcVar11;
                  pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                  pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                } while (bVar12);
                if (bVar12) {
                  local_44 = EVP_des_ede3_cbc();
                }
                else {
                  iVar3 = 6;
                  pcVar10 = pcVar14;
                  pcVar11 = "-idea";
                  do {
                    if (iVar3 == 0) break;
                    iVar3 = iVar3 + -1;
                    bVar12 = *pcVar10 == *pcVar11;
                    pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                    pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                  } while (bVar12);
                  if (bVar12) {
                    local_44 = EVP_idea_cbc();
                  }
                  else {
                    iVar3 = 6;
                    pcVar10 = pcVar14;
                    pcVar11 = "-seed";
                    do {
                      if (iVar3 == 0) break;
                      iVar3 = iVar3 + -1;
                      bVar12 = *pcVar10 == *pcVar11;
                      pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                      pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                    } while (bVar12);
                    if (bVar12) {
                      local_44 = EVP_seed_cbc();
                    }
                    else {
                      iVar3 = 8;
                      pcVar10 = pcVar14;
                      pcVar11 = "-aes128";
                      do {
                        if (iVar3 == 0) break;
                        iVar3 = iVar3 + -1;
                        bVar12 = *pcVar10 == *pcVar11;
                        pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                        pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                      } while (bVar12);
                      if (bVar12) {
                        local_44 = EVP_aes_128_cbc();
                      }
                      else {
                        iVar3 = 8;
                        pcVar10 = pcVar14;
                        pcVar11 = "-aes192";
                        do {
                          if (iVar3 == 0) break;
                          iVar3 = iVar3 + -1;
                          bVar12 = *pcVar10 == *pcVar11;
                          pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                          pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                        } while (bVar12);
                        if (bVar12) {
                          local_44 = EVP_aes_192_cbc();
                        }
                        else {
                          iVar3 = 8;
                          pcVar10 = pcVar14;
                          pcVar11 = "-aes256";
                          do {
                            if (iVar3 == 0) break;
                            iVar3 = iVar3 + -1;
                            bVar12 = *pcVar10 == *pcVar11;
                            pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                            pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                          } while (bVar12);
                          if (bVar12) {
                            local_44 = EVP_aes_256_cbc();
                          }
                          else {
                            iVar3 = 0xd;
                            pcVar10 = pcVar14;
                            pcVar11 = "-camellia128";
                            do {
                              if (iVar3 == 0) break;
                              iVar3 = iVar3 + -1;
                              bVar12 = *pcVar10 == *pcVar11;
                              pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                              pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                            } while (bVar12);
                            if (bVar12) {
                              local_44 = EVP_camellia_128_cbc();
                            }
                            else {
                              iVar3 = 0xd;
                              pcVar10 = pcVar14;
                              pcVar11 = "-camellia192";
                              do {
                                if (iVar3 == 0) break;
                                iVar3 = iVar3 + -1;
                                bVar12 = *pcVar10 == *pcVar11;
                                pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                                pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                              } while (bVar12);
                              if (!bVar12) {
                                iVar3 = 0xd;
                                pcVar10 = pcVar14;
                                pcVar11 = "-camellia256";
                                do {
                                  if (iVar3 == 0) break;
                                  iVar3 = iVar3 + -1;
                                  bVar12 = *pcVar10 == *pcVar11;
                                  pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                                  pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                                } while (bVar12);
                                if (bVar12) {
                                  local_44 = EVP_camellia_256_cbc();
                                  goto LAB_08065ba2;
                                }
                                iVar3 = 9;
                                pcVar10 = pcVar14;
                                pcVar11 = "-passout";
                                do {
                                  if (iVar3 == 0) break;
                                  iVar3 = iVar3 + -1;
                                  bVar12 = *pcVar10 == *pcVar11;
                                  pcVar10 = pcVar10 + (uint)bVar13 * -2 + 1;
                                  pcVar11 = pcVar11 + (uint)bVar13 * -2 + 1;
                                } while (bVar12);
                                if (bVar12) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_40 = ppcVar9[1];
                                    ppcVar9 = ppcVar9 + 1;
                                    goto LAB_08065ba2;
                                  }
                                }
                                else {
                                  iVar3 = __isoc99_sscanf(pcVar14,"%d",&local_3c);
                                  if ((iVar3 != 0) && (-1 < local_3c)) goto LAB_08065bf8;
                                }
LAB_08065e00:
                                BIO_printf(bio_err,"usage: genrsa [args] [numbits]\n");
                                BIO_printf(bio_err,
                                           " -des            encrypt the generated key with DES in cbc mode\n"
                                          );
                                BIO_printf(bio_err,
                                           " -des3           encrypt the generated key with DES in ede cbc mode (168 bit key)\n"
                                          );
                                BIO_printf(bio_err,
                                           " -idea           encrypt the generated key with IDEA in cbc mode\n"
                                          );
                                BIO_printf(bio_err," -seed\n");
                                BIO_printf(bio_err,
                                           "                 encrypt PEM output with cbc seed\n");
                                BIO_printf(bio_err," -aes128, -aes192, -aes256\n");
                                BIO_printf(bio_err,
                                           "                 encrypt PEM output with cbc aes\n");
                                BIO_printf(bio_err," -camellia128, -camellia192, -camellia256\n");
                                BIO_printf(bio_err,
                                           "                 encrypt PEM output with cbc camellia\n"
                                          );
                                BIO_printf(bio_err," -out file       output the key to \'file\n");
                                BIO_printf(bio_err,
                                           " -passout arg    output file pass phrase source\n");
                                BIO_printf(bio_err,
                                           " -f4             use F4 (0x10001) for the E value\n");
                                BIO_printf(bio_err," -3              use 3 for the E value\n");
                                BIO_printf(bio_err,
                                           " -engine e       use engine e, possibly a hardware device.\n"
                                          );
                                BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
                                BIO_printf(bio_err,
                                           "                 load the file (or the files in the directory) into\n"
                                          );
                                BIO_printf(bio_err,"                 the random number generator\n")
                                ;
                                goto LAB_08065ac2;
                              }
                              local_44 = EVP_camellia_192_cbc();
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
LAB_08065ba2:
          param_1 = param_1 + -1;
          ppcVar9 = ppcVar9 + 1;
joined_r0x08065bf2:
          bVar12 = param_1 == 0;
          if (bVar12) goto LAB_08065bf8;
          goto LAB_08065baa;
        }
        ERR_load_crypto_strings();
        iVar3 = app_passwd(bio_err,0,0,0,&local_38);
        if (iVar3 != 0) {
          engine = (ENGINE *)setup_engine(bio_err,0,0);
          local_44 = (EVP_CIPHER *)0x0;
          local_50 = 0x10001;
          local_48 = (char *)0x0;
          goto LAB_08066221;
        }
        goto LAB_08066048;
      }
      BIO_printf(bio_err,"unable to create BIO for output\n");
    }
    goto LAB_08065ac2;
  }
  bVar12 = true;
  if (local_38 != (void *)0x0) goto LAB_08065af5;
  goto LAB_08065d31;
LAB_08065bf8:
  ERR_load_crypto_strings();
  iVar3 = app_passwd(bio_err,0,local_40,0,&local_38);
  if (iVar3 == 0) {
LAB_08066048:
    BIO_printf(bio_err,"Error getting password\n");
LAB_08065ac2:
    bVar12 = true;
    BN_free(a);
    if (local_54 != (BIO *)0x0) goto LAB_08065ade;
  }
  else {
    engine = (ENGINE *)setup_engine(bio_err,local_4c,0);
    if (parg == (char *)0x0) {
LAB_08066221:
      parg = stdout;
      BIO_ctrl(local_54,0x6a,0,stdout);
      pcVar14 = (char *)0x0;
    }
    else {
      pcVar14 = parg;
      lVar5 = BIO_ctrl(local_54,0x6c,5,parg);
      if (lVar5 < 1) {
        perror(pcVar14);
        goto LAB_08065ac2;
      }
    }
    iVar3 = app_RAND_load_file(0,bio_err,1,parg,pcVar14);
    if (iVar3 == 0) {
      if (local_48 == (char *)0x0) {
        iVar3 = RAND_status();
        if (iVar3 == 0) {
          BIO_printf(bio_err,
                     "warning, not much extra random data, consider using the -rand option\n",
                     extraout_ECX,extraout_ECX);
        }
      }
      else {
LAB_08065c8b:
        uVar6 = app_RAND_load_files(local_48);
        BIO_printf(bio_err,"%ld semi-random bytes loaded\n",uVar6);
      }
    }
    else if (local_48 != (char *)0x0) goto LAB_08065c8b;
    BIO_printf(bio_err,"Generating RSA private key, %d bit long modulus\n",local_3c);
    rsa = RSA_new_method(engine);
    if (rsa == (RSA *)0x0) goto LAB_08065ac2;
    bVar12 = true;
    iVar3 = BN_set_word(a,local_50);
    if ((iVar3 != 0) && (iVar3 = RSA_generate_key_ex(rsa,local_3c,a,&local_2c), iVar3 != 0)) {
      app_RAND_write_file(0,bio_err);
      iVar3 = rsa->e->top;
      if (iVar3 < 1) {
        uVar8 = 0;
      }
      else {
        puVar7 = rsa->e->d;
        puVar1 = puVar7 + iVar3;
        do {
          uVar8 = *puVar7;
          puVar7 = puVar7 + 1;
        } while (puVar1 != puVar7);
      }
      BIO_printf(bio_err,"e is %ld (0x%lX)\n",uVar8,uVar8);
      local_34 = local_38;
      local_30 = pcVar14;
      iVar3 = PEM_write_bio_RSAPrivateKey
                        (local_54,rsa,local_44,(uchar *)0x0,0,password_callback,&local_34);
      bVar12 = iVar3 == 0;
    }
    BN_free(a);
    RSA_free(rsa);
LAB_08065ade:
    BIO_free_all(local_54);
  }
  if (local_38 != (void *)0x0) {
LAB_08065af5:
    CRYPTO_free(local_38);
  }
  if (bVar12 == false) goto LAB_08065b09;
LAB_08065d31:
  ERR_print_errors(bio_err);
LAB_08065b09:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

