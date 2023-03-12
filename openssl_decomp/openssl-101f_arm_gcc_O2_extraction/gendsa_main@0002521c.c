
undefined4 gendsa_main(int param_1,int param_2)

{
  char cVar1;
  DSA *bp;
  int iVar2;
  BIO_METHOD *pBVar3;
  BIO *pBVar4;
  long lVar5;
  DSA *a;
  char **ppcVar6;
  undefined4 uVar7;
  char *__s1;
  char *__s;
  char *pcVar8;
  char *pcVar9;
  bool bVar10;
  char *local_3c;
  EVP_CIPHER *local_38;
  char *local_34;
  void *local_2c [2];
  
  local_2c[0] = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar3 = BIO_s_file();
    bio_err = BIO_new(pBVar3);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  bp = (DSA *)load_config(bio_err,0);
  a = bp;
  if (bp == (DSA *)0x0) goto LAB_0002530e;
  param_1 = param_1 + -1;
  ppcVar6 = (char **)(param_2 + 4);
  if (0 < param_1) {
    pcVar8 = (char *)0x0;
    local_38 = (EVP_CIPHER *)0x0;
    pcVar9 = (char *)0x0;
    local_34 = (char *)0x0;
    local_3c = (char *)0x0;
    __s = (char *)0x0;
LAB_00025286:
    __s1 = *ppcVar6;
    iVar2 = strcmp(__s1,"-out");
    if (iVar2 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0002533a;
      __s = ppcVar6[1];
      ppcVar6 = ppcVar6 + 1;
    }
    else {
      iVar2 = strcmp(__s1,"-passout");
      if (iVar2 == 0) {
        if (param_1 == 1) goto LAB_0002533a;
        param_1 = param_1 + -2;
        pcVar9 = ppcVar6[1];
        ppcVar6 = ppcVar6 + 2;
        goto joined_r0x000252c6;
      }
      iVar2 = strcmp(__s1,"-engine");
      if (iVar2 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0002533a;
        pcVar8 = ppcVar6[1];
        ppcVar6 = ppcVar6 + 1;
      }
      else {
        iVar2 = strcmp(__s1,"-rand");
        if (iVar2 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            local_3c = ppcVar6[1];
            ppcVar6 = ppcVar6 + 1;
            goto LAB_0002527a;
          }
          goto LAB_0002533a;
        }
        cVar1 = *__s1;
        if ((cVar1 == '-') && (__s1[1] == '\0')) goto LAB_0002533a;
        iVar2 = strcmp(__s1,"-des");
        if (iVar2 == 0) {
          local_38 = EVP_des_cbc();
        }
        else {
          iVar2 = strcmp(__s1,"-des3");
          if (iVar2 == 0) {
            local_38 = EVP_des_ede3_cbc();
          }
          else {
            iVar2 = strcmp(__s1,"-idea");
            if (iVar2 == 0) {
              local_38 = EVP_idea_cbc();
            }
            else {
              iVar2 = strcmp(__s1,"-seed");
              if (iVar2 == 0) {
                local_38 = EVP_seed_cbc();
              }
              else {
                iVar2 = strcmp(__s1,"-aes128");
                if (iVar2 == 0) {
                  local_38 = EVP_aes_128_cbc();
                }
                else {
                  iVar2 = strcmp(__s1,"-aes192");
                  if (iVar2 == 0) {
                    local_38 = EVP_aes_192_cbc();
                  }
                  else {
                    iVar2 = strcmp(__s1,"-aes256");
                    if (iVar2 == 0) {
                      local_38 = EVP_aes_256_cbc();
                    }
                    else {
                      iVar2 = strcmp(__s1,"-camellia128");
                      if (iVar2 == 0) {
                        local_38 = EVP_camellia_128_cbc();
                      }
                      else {
                        iVar2 = strcmp(__s1,"-camellia192");
                        if (iVar2 == 0) {
                          local_38 = EVP_camellia_192_cbc();
                        }
                        else {
                          iVar2 = strcmp(__s1,"-camellia256");
                          if (iVar2 == 0) {
                            local_38 = EVP_camellia_256_cbc();
                          }
                          else if ((cVar1 == '-') ||
                                  (bVar10 = local_34 != (char *)0x0, local_34 = __s1, bVar10))
                          goto LAB_0002533a;
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
LAB_0002527a:
    param_1 = param_1 + -1;
    ppcVar6 = ppcVar6 + 1;
joined_r0x000252c6:
    if (param_1 < 1) goto LAB_000252c8;
    goto LAB_00025286;
  }
LAB_0002533a:
  bp = (DSA *)0x0;
  BIO_printf(bio_err,"usage: gendsa [args] dsaparam-file\n");
  BIO_printf(bio_err," -out file - output the key to \'file\'\n");
  BIO_printf(bio_err," -des      - encrypt the generated key with DES in cbc mode\n");
  BIO_printf(bio_err,
             " -des3     - encrypt the generated key with DES in ede cbc mode (168 bit key)\n");
  BIO_printf(bio_err," -idea     - encrypt the generated key with IDEA in cbc mode\n");
  BIO_printf(bio_err," -seed\n");
  BIO_printf(bio_err,"                 encrypt PEM output with cbc seed\n");
  BIO_printf(bio_err," -aes128, -aes192, -aes256\n");
  BIO_printf(bio_err,"                 encrypt PEM output with cbc aes\n");
  BIO_printf(bio_err," -camellia128, -camellia192, -camellia256\n");
  BIO_printf(bio_err,"                 encrypt PEM output with cbc camellia\n");
  BIO_printf(bio_err," -engine e - use engine e, possibly a hardware device.\n");
  BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
  BIO_printf(bio_err,"           - load the file (or the files in the directory) into\n");
  BIO_printf(bio_err,"             the random number generator\n");
  BIO_printf(bio_err," dsaparam-file\n");
  BIO_printf(bio_err,"           - a DSA parameter file as generated by the dsaparam command\n");
  a = (DSA *)0x0;
LAB_0002530e:
  uVar7 = 1;
  ERR_print_errors(bio_err);
  if (bp != (DSA *)0x0) goto LAB_00025318;
LAB_0002531e:
  if (a != (DSA *)0x0) {
    DSA_free(a);
  }
LAB_0002532a:
  if (local_2c[0] != (void *)0x0) {
    CRYPTO_free(local_2c[0]);
  }
  return uVar7;
LAB_000252c8:
  if (local_34 == (char *)0x0) goto LAB_0002533a;
  setup_engine(bio_err,pcVar8,0);
  bp = (DSA *)app_passwd(bio_err,0,pcVar9,0,local_2c);
  if (bp == (DSA *)0x0) {
    BIO_printf(bio_err,"Error getting password\n");
    a = bp;
    goto LAB_0002530e;
  }
  pBVar3 = BIO_s_file();
  pBVar4 = BIO_new(pBVar3);
  lVar5 = BIO_ctrl(pBVar4,0x6c,3,local_34);
  if (lVar5 == 0) {
    perror(local_34);
LAB_0002569a:
    ERR_print_errors(bio_err);
    if (pBVar4 != (BIO *)0x0) {
      BIO_free(pBVar4);
    }
    uVar7 = 1;
    goto LAB_0002532a;
  }
  a = PEM_read_bio_DSAparams(pBVar4,(DSA **)0x0,(undefined1 *)0x0,(void *)0x0);
  if (a == (DSA *)0x0) {
    BIO_printf(bio_err,"unable to load DSA parameter file\n");
    goto LAB_0002569a;
  }
  BIO_free(pBVar4);
  pBVar3 = BIO_s_file();
  bp = (DSA *)BIO_new(pBVar3);
  if (bp == (DSA *)0x0) goto LAB_0002530e;
  if (__s == (char *)0x0) {
    BIO_ctrl((BIO *)bp,0x6a,0,stdout);
  }
  else {
    lVar5 = BIO_ctrl((BIO *)bp,0x6c,5,__s);
    if (lVar5 < 1) {
      perror(__s);
      goto LAB_0002530e;
    }
  }
  iVar2 = app_RAND_load_file(0,bio_err,1);
  pBVar4 = bio_err;
  if (iVar2 == 0) {
    if (local_3c == (char *)0x0) {
      BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n");
    }
    else {
LAB_0002561e:
      uVar7 = app_RAND_load_files(local_3c);
      BIO_printf(pBVar4,"%ld semi-random bytes loaded\n",uVar7);
    }
  }
  else if (local_3c != (char *)0x0) goto LAB_0002561e;
  pBVar4 = bio_err;
  iVar2 = BN_num_bits(a->p);
  BIO_printf(pBVar4,"Generating DSA key, %d bits\n",iVar2);
  iVar2 = DSA_generate_key(a);
  if (iVar2 == 0) goto LAB_0002530e;
  app_RAND_write_file(0,bio_err);
  uVar7 = 0;
  iVar2 = PEM_write_bio_DSAPrivateKey
                    ((BIO *)bp,a,local_38,(uchar *)0x0,0,(undefined1 *)0x0,local_2c[0]);
  if (iVar2 == 0) goto LAB_0002530e;
LAB_00025318:
  BIO_free_all((BIO *)bp);
  goto LAB_0002531e;
}

