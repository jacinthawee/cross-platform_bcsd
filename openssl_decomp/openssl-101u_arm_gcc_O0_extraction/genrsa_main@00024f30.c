
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint genrsa_main(int param_1,int param_2)

{
  char cVar1;
  BIO *bio;
  BIGNUM *a;
  BIO *bp;
  BIO_METHOD *pBVar2;
  int iVar3;
  ENGINE *engine;
  long lVar4;
  undefined4 uVar5;
  RSA *rsa;
  ulong *puVar6;
  ulong *puVar7;
  uint uVar9;
  char *__s1;
  char *__s;
  char *pcVar10;
  char **ppcVar11;
  ulong uVar12;
  char *local_58;
  EVP_CIPHER *local_50;
  char *local_4c;
  int local_44;
  void *local_40;
  void *local_3c;
  char *local_38;
  BN_GENCB local_34;
  ulong *puVar8;
  
  local_44 = 0x400;
  local_40 = (void *)0x0;
  a = BN_new();
  if (a == (BIGNUM *)0x0) {
LAB_00025160:
    uVar9 = 1;
  }
  else {
    signal(0xd,(__sighandler_t)0x1);
    local_34.ver = 2;
    local_34.arg = bio_err;
    local_34.cb.cb_1 = genrsa_cb + 1;
    if (bio_err == (BIO *)0x0) {
      pBVar2 = BIO_s_file();
      bio_err = BIO_new(pBVar2);
      if (bio_err != (BIO *)0x0) {
        BIO_ctrl(bio_err,0x6a,0x10,stderr);
      }
    }
    bp = (BIO *)load_config(bio_err,0);
    if (bp == (BIO *)0x0) {
LAB_00024f84:
      uVar9 = 1;
      BN_free(a);
      if (bp == (BIO *)0x0) goto LAB_00025160;
    }
    else {
      pBVar2 = BIO_s_file();
      bp = BIO_new(pBVar2);
      if (bp == (BIO *)0x0) {
        BIO_printf(bio_err,"unable to create BIO for output\n");
        goto LAB_00024f84;
      }
      param_1 = param_1 + -1;
      ppcVar11 = (char **)(param_2 + 4);
      pcVar10 = (char *)0x0;
      uVar12 = 0x10001;
      local_58 = (char *)0x0;
      local_4c = (char *)0x0;
      __s = (char *)0x0;
      local_50 = (EVP_CIPHER *)0x0;
      if (0 < param_1) {
        uVar12 = 0x10001;
LAB_00025010:
        __s1 = *ppcVar11;
        iVar3 = strcmp(__s1,"-out");
        if (iVar3 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            __s = ppcVar11[1];
            ppcVar11 = ppcVar11 + 1;
            goto LAB_00025002;
          }
          goto LAB_000252a8;
        }
        if (*__s1 == '-') {
          cVar1 = __s1[1];
          if (cVar1 == '3') {
            if (__s1[2] != '\0') goto LAB_0002502e;
            uVar12 = 3;
          }
          else {
            if ((((cVar1 != 'F') && (cVar1 != 'f')) || (__s1[2] != '4')) || (__s1[3] != '\0'))
            goto LAB_0002502e;
            uVar12 = 0x10001;
          }
        }
        else {
LAB_0002502e:
          iVar3 = strcmp(__s1,"-engine");
          if (iVar3 == 0) {
            if (param_1 == 1) goto LAB_000252a8;
            local_58 = ppcVar11[1];
            param_1 = param_1 + -2;
            ppcVar11 = ppcVar11 + 2;
            goto joined_r0x0002500e;
          }
          iVar3 = strcmp(__s1,"-rand");
          if (iVar3 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_000252a8;
            pcVar10 = ppcVar11[1];
            ppcVar11 = ppcVar11 + 1;
          }
          else {
            iVar3 = strcmp(__s1,"-des");
            if (iVar3 == 0) {
              local_50 = EVP_des_cbc();
            }
            else {
              iVar3 = strcmp(__s1,"-des3");
              if (iVar3 == 0) {
                local_50 = EVP_des_ede3_cbc();
              }
              else {
                iVar3 = strcmp(__s1,"-idea");
                if (iVar3 == 0) {
                  local_50 = EVP_idea_cbc();
                }
                else {
                  iVar3 = strcmp(__s1,"-seed");
                  if (iVar3 == 0) {
                    local_50 = EVP_seed_cbc();
                  }
                  else {
                    iVar3 = strcmp(__s1,"-aes128");
                    if (iVar3 == 0) {
                      local_50 = EVP_aes_128_cbc();
                    }
                    else {
                      iVar3 = strcmp(__s1,"-aes192");
                      if (iVar3 == 0) {
                        local_50 = EVP_aes_192_cbc();
                      }
                      else {
                        iVar3 = strcmp(__s1,"-aes256");
                        if (iVar3 == 0) {
                          local_50 = EVP_aes_256_cbc();
                        }
                        else {
                          iVar3 = strcmp(__s1,"-camellia128");
                          if (iVar3 == 0) {
                            local_50 = EVP_camellia_128_cbc();
                          }
                          else {
                            iVar3 = strcmp(__s1,"-camellia192");
                            if (iVar3 != 0) {
                              iVar3 = strcmp(__s1,"-camellia256");
                              if (iVar3 == 0) {
                                local_50 = EVP_camellia_256_cbc();
                                goto LAB_00025002;
                              }
                              iVar3 = strcmp(__s1,"-passout");
                              if (iVar3 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_4c = ppcVar11[1];
                                  ppcVar11 = ppcVar11 + 1;
                                  goto LAB_00025002;
                                }
                              }
                              else {
                                iVar3 = __isoc99_sscanf(__s1,"%d",&local_44);
                                if ((iVar3 != 0) && (-1 < local_44)) goto LAB_00025066;
                              }
LAB_000252a8:
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
                                         "                 encrypt PEM output with cbc camellia\n");
                              BIO_printf(bio_err," -out file       output the key to \'file\n");
                              BIO_printf(bio_err," -passout arg    output file pass phrase source\n"
                                        );
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
                              BIO_printf(bio_err,"                 the random number generator\n");
                              goto LAB_00024f84;
                            }
                            local_50 = EVP_camellia_192_cbc();
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
LAB_00025002:
        param_1 = param_1 + -1;
        ppcVar11 = ppcVar11 + 1;
joined_r0x0002500e:
        if (param_1 < 1) goto LAB_00025066;
        goto LAB_00025010;
      }
LAB_00025066:
      ERR_load_crypto_strings();
      iVar3 = app_passwd(bio_err,0,local_4c,0,&local_40);
      if (iVar3 == 0) {
        BIO_printf(bio_err,"Error getting password\n");
        goto LAB_00024f84;
      }
      engine = (ENGINE *)setup_engine(bio_err,local_58,0);
      if (__s == (char *)0x0) {
        BIO_ctrl(bp,0x6a,0,stdout);
      }
      else {
        lVar4 = BIO_ctrl(bp,0x6c,5,__s);
        if (lVar4 < 1) {
          perror(__s);
          goto LAB_00024f84;
        }
      }
      iVar3 = app_RAND_load_file(0,bio_err,1);
      bio = bio_err;
      if (iVar3 == 0) {
        if (pcVar10 == (char *)0x0) {
          iVar3 = RAND_status();
          if (iVar3 == 0) {
            BIO_printf(bio_err,
                       "warning, not much extra random data, consider using the -rand option\n");
          }
        }
        else {
LAB_000250f2:
          uVar5 = app_RAND_load_files(pcVar10);
          BIO_printf(bio,"%ld semi-random bytes loaded\n",uVar5);
        }
      }
      else if (pcVar10 != (char *)0x0) goto LAB_000250f2;
      BIO_printf(bio_err,"Generating RSA private key, %d bit long modulus\n",local_44);
      rsa = RSA_new_method(engine);
      if (rsa == (RSA *)0x0) goto LAB_00024f84;
      iVar3 = BN_set_word(a,uVar12);
      if ((iVar3 == 0) || (iVar3 = RSA_generate_key_ex(rsa,local_44,a,&local_34), iVar3 == 0)) {
        uVar9 = 1;
      }
      else {
        app_RAND_write_file(0,bio_err);
        iVar3 = rsa->e->top;
        if (iVar3 < 1) {
          uVar12 = 0;
        }
        else {
          puVar6 = rsa->e->d;
          puVar7 = puVar6;
          do {
            puVar8 = puVar7 + 1;
            uVar12 = *puVar7;
            puVar7 = puVar8;
          } while (puVar8 != puVar6 + iVar3);
        }
        BIO_printf(bio_err,"e is %ld (0x%lX)\n",uVar12,uVar12);
        local_3c = local_40;
        local_38 = __s;
        iVar3 = PEM_write_bio_RSAPrivateKey
                          (bp,rsa,local_50,(uchar *)0x0,0,password_callback + 1,&local_3c);
        uVar9 = count_leading_zeroes(iVar3);
        uVar9 = uVar9 >> 5;
      }
      BN_free(a);
      RSA_free(rsa);
    }
    BIO_free_all(bp);
  }
  if (local_40 != (void *)0x0) {
    CRYPTO_free(local_40);
  }
  if (uVar9 != 0) {
    ERR_print_errors(bio_err);
  }
  return uVar9;
}

