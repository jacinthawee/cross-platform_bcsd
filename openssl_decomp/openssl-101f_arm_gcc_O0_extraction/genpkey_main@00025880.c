
int genpkey_main(undefined4 param_1,int param_2)

{
  char **ppcVar1;
  int iVar2;
  int iVar3;
  BIO *bp;
  EVP_PKEY *pkey;
  EVP_PKEY_CTX *ctx;
  char **ppcVar4;
  BIO *pBVar5;
  char *pcVar6;
  int iVar7;
  ENGINE *e;
  char *filename;
  char *pcVar8;
  int local_48;
  EVP_CIPHER *local_44;
  EVP_PKEY *local_34;
  EVP_PKEY_CTX *local_30;
  void *local_2c [2];
  
  local_34 = (EVP_PKEY *)0x0;
  local_30 = (EVP_PKEY_CTX *)0x0;
  local_2c[0] = (void *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar2 = load_config(bio_err,0);
  if (iVar2 == 0) {
LAB_000258aa:
    local_48 = 1;
    pBVar5 = (BIO *)0x0;
  }
  else {
    iVar7 = 0;
    ppcVar4 = (char **)(param_2 + 4);
    pcVar6 = (char *)0x0;
    filename = (char *)0x0;
    e = (ENGINE *)0x0;
    iVar2 = 3;
    ERR_load_crypto_strings();
    OPENSSL_add_all_algorithms_noconf();
    local_48 = 0;
    local_44 = (EVP_CIPHER *)0x0;
LAB_000258f6:
    pcVar8 = *ppcVar4;
    if (pcVar8 != (char *)0x0) {
      do {
        if (*pcVar8 != '-') break;
        iVar3 = strcmp(pcVar8,"-outform");
        if (iVar3 == 0) {
          if (ppcVar4[1] == (char *)0x0) goto LAB_00025ab8;
          iVar2 = str2fmt();
          ppcVar4 = ppcVar4 + 1;
        }
        else {
          iVar3 = strcmp(pcVar8,"-pass");
          if (iVar3 == 0) {
            pcVar6 = ppcVar4[1];
            if (pcVar6 == (char *)0x0) goto LAB_00025ab8;
LAB_00025a0e:
            ppcVar4 = ppcVar4 + 1;
          }
          else {
            iVar3 = strcmp(pcVar8,"-engine");
            if (iVar3 == 0) {
              if (ppcVar4[1] == (char *)0x0) goto LAB_00025ab8;
              e = (ENGINE *)setup_engine(bio_err,ppcVar4[1],0);
              ppcVar4 = ppcVar4 + 1;
            }
            else {
              iVar3 = strcmp(pcVar8,"-paramfile");
              pBVar5 = bio_err;
              if (iVar3 == 0) {
                pcVar8 = ppcVar4[1];
                if ((pcVar8 == (char *)0x0) || (iVar7 != 0)) goto LAB_00025ab8;
                if (local_30 == (EVP_PKEY_CTX *)0x0) {
                  bp = BIO_new_file(pcVar8,"r");
                  if (bp == (BIO *)0x0) {
                    BIO_printf(pBVar5,"Can\'t open parameter file %s\n");
                  }
                  else {
                    pkey = PEM_read_bio_Parameters(bp,(EVP_PKEY **)0x0);
                    BIO_free(bp);
                    if (pkey == (EVP_PKEY *)0x0) {
                      BIO_printf(bio_err,"Error reading parameter file %s\n",pcVar8);
                    }
                    else {
                      ctx = EVP_PKEY_CTX_new(pkey,e);
                      if (ctx == (EVP_PKEY_CTX *)0x0) {
                        BIO_puts(pBVar5,"Error initializing context\n");
                        ERR_print_errors(pBVar5);
                      }
                      else {
                        iVar3 = EVP_PKEY_keygen_init(ctx);
                        if (0 < iVar3) {
                          ppcVar4 = ppcVar4 + 1;
                          EVP_PKEY_free(pkey);
                          local_30 = ctx;
                          goto LAB_0002592a;
                        }
                        BIO_puts(pBVar5,"Error initializing context\n");
                        ERR_print_errors(pBVar5);
                        EVP_PKEY_CTX_free(ctx);
                      }
                      EVP_PKEY_free(pkey);
                    }
                  }
                }
                else {
                  BIO_puts(bio_err,"Parameters already set!\n");
                }
                goto LAB_000258aa;
              }
              iVar3 = strcmp(pcVar8,"-out");
              if (iVar3 == 0) {
                filename = ppcVar4[1];
                if (filename != (char *)0x0) goto LAB_00025a0e;
                goto LAB_00025ab8;
              }
              iVar3 = strcmp(pcVar8,"-algorithm");
              if (iVar3 == 0) {
                ppcVar1 = ppcVar4 + 1;
                if (*ppcVar1 == (char *)0x0) goto LAB_00025ab8;
                ppcVar4 = ppcVar4 + 1;
                iVar3 = init_gen_str(bio_err,&local_30,*ppcVar1,e,iVar7);
                if (iVar3 == 0) goto LAB_000258aa;
              }
              else {
                iVar3 = strcmp(pcVar8,"-pkeyopt");
                if (iVar3 == 0) {
                  if (ppcVar4[1] == (char *)0x0) goto LAB_00025ab8;
                  if (local_30 == (EVP_PKEY_CTX *)0x0) {
                    BIO_puts(bio_err,"No keytype specified\n");
                    goto LAB_00025ab8;
                  }
                  iVar3 = pkey_ctrl_string();
                  ppcVar4 = ppcVar4 + 1;
                  if (iVar3 < 1) {
                    local_48 = 1;
                    BIO_puts(bio_err,"parameter setting error\n");
                    ERR_print_errors(bio_err);
                    pBVar5 = (BIO *)0x0;
                    goto LAB_000258ae;
                  }
                }
                else {
                  iVar3 = strcmp(pcVar8,"-genparam");
                  if (iVar3 == 0) {
                    if (local_30 != (EVP_PKEY_CTX *)0x0) goto LAB_00025ab8;
                    iVar7 = 1;
                  }
                  else {
                    iVar3 = strcmp(pcVar8,"-text");
                    if (iVar3 != 0) goto LAB_00025d28;
                    local_48 = 1;
                  }
                }
              }
            }
          }
        }
LAB_0002592a:
        ppcVar4 = ppcVar4 + 1;
        pcVar8 = *ppcVar4;
        if (pcVar8 == (char *)0x0) break;
      } while( true );
    }
    if (local_30 != (EVP_PKEY_CTX *)0x0) {
      pBVar5 = (BIO *)app_passwd(bio_err,pcVar6,0,local_2c,0);
      if (pBVar5 == (BIO *)0x0) {
        local_48 = 1;
        BIO_puts(bio_err,"Error getting password\n");
        goto LAB_000258ae;
      }
      if (filename == (char *)0x0) {
        pBVar5 = BIO_new_fp(stdout,0);
      }
      else {
        pBVar5 = BIO_new_file(filename,"wb");
        if (pBVar5 == (BIO *)0x0) {
          BIO_printf(bio_err,"Can\'t open output file %s\n",filename);
          local_48 = 1;
          goto LAB_000258ae;
        }
      }
      EVP_PKEY_CTX_set_cb(local_30,genpkey_cb + 1);
      EVP_PKEY_CTX_set_app_data(local_30,bio_err);
      if (iVar7 == 0) {
        iVar3 = EVP_PKEY_keygen(local_30,&local_34);
        if (iVar3 < 1) {
          local_48 = 1;
          BIO_puts(bio_err,"Error generating key\n");
          ERR_print_errors(bio_err);
          goto LAB_000258ae;
        }
        if (iVar2 == 3) {
          iVar2 = PEM_write_bio_PrivateKey
                            (pBVar5,local_34,local_44,(uchar *)0x0,0,(undefined1 *)0x0,local_2c[0]);
        }
        else {
          if (iVar2 != 1) {
            local_48 = 1;
            BIO_printf(bio_err,"Bad format specified for key\n");
            goto LAB_000258ae;
          }
          iVar2 = i2d_PrivateKey_bio(pBVar5,local_34);
        }
      }
      else {
        iVar2 = EVP_PKEY_paramgen(local_30,&local_34);
        if (iVar2 < 1) {
          local_48 = 1;
          BIO_puts(bio_err,"Error generating parameters\n");
          ERR_print_errors(bio_err);
          goto LAB_000258ae;
        }
        iVar2 = PEM_write_bio_Parameters(pBVar5,local_34);
      }
      if (iVar2 < 1) {
        BIO_puts(bio_err,"Error writing key\n");
        ERR_print_errors(bio_err);
      }
      if (local_48 != 0) {
        if (iVar7 == 0) {
          iVar2 = EVP_PKEY_print_private(pBVar5,local_34,0,(ASN1_PCTX *)0x0);
        }
        else {
          iVar2 = EVP_PKEY_print_params(pBVar5,local_34,0,(ASN1_PCTX *)0x0);
        }
        if (iVar2 < 1) {
          local_48 = 0;
          BIO_puts(bio_err,"Error printing key\n");
          ERR_print_errors(bio_err);
        }
        else {
          local_48 = 0;
        }
      }
      goto LAB_000258ae;
    }
LAB_00025ab8:
    local_48 = 1;
    BIO_printf(bio_err,"Usage: genpkey [options]\n");
    BIO_printf(bio_err,"where options may be\n");
    BIO_printf(bio_err,"-out file          output file\n");
    BIO_printf(bio_err,"-outform X         output format (DER or PEM)\n");
    BIO_printf(bio_err,"-pass arg          output file pass phrase source\n");
    BIO_printf(bio_err,"-<cipher>          use cipher <cipher> to encrypt the key\n");
    BIO_printf(bio_err,"-engine e          use engine e, possibly a hardware device.\n");
    BIO_printf(bio_err,"-paramfile file    parameters file\n");
    BIO_printf(bio_err,"-algorithm alg     the public key algorithm\n");
    BIO_printf(bio_err,
               "-pkeyopt opt:value set the public key algorithm option <opt>\n                   to value <value>\n"
              );
    BIO_printf(bio_err,"-genparam          generate parameters, not key\n");
    BIO_printf(bio_err,"-text              print the in text\n");
    BIO_printf(bio_err,"NB: options order may be important!  See the manual page.\n");
    pBVar5 = (BIO *)0x0;
  }
LAB_000258ae:
  if (local_34 != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(local_34);
  }
  if (local_30 != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(local_30);
  }
  if (pBVar5 != (BIO *)0x0) {
    BIO_free_all(pBVar5);
  }
  BIO_free((BIO *)0x0);
  if (local_2c[0] != (void *)0x0) {
    CRYPTO_free(local_2c[0]);
  }
  return local_48;
LAB_00025d28:
  local_44 = EVP_get_cipherbyname(pcVar8 + 1);
  if (local_44 == (EVP_CIPHER *)0x0) {
    BIO_printf(bio_err,"Unknown cipher %s\n",*ppcVar4 + 1);
  }
  if ((iVar7 != 0) || (ppcVar4 = ppcVar4 + 1, local_44 == (EVP_CIPHER *)0x0)) goto LAB_00025ab8;
  goto LAB_000258f6;
}

