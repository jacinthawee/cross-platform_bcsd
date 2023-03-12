
undefined4 genpkey_main(undefined4 param_1,int param_2)

{
  char **ppcVar1;
  bool bVar2;
  int iVar3;
  BIO *bp;
  EVP_PKEY *pkey;
  EVP_PKEY_CTX *ctx;
  BIO *pBVar4;
  char **ppcVar5;
  char *pcVar6;
  undefined4 uVar7;
  char *pcVar8;
  char *pcVar9;
  int in_GS_OFFSET;
  bool bVar10;
  byte bVar11;
  char *pcVar12;
  int local_4c;
  ENGINE *local_48;
  int local_44;
  char *local_40;
  EVP_CIPHER *local_38;
  EVP_PKEY *local_2c;
  EVP_PKEY_CTX *local_28;
  void *local_24;
  int local_20;
  
  bVar11 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = (EVP_PKEY *)0x0;
  local_28 = (EVP_PKEY_CTX *)0x0;
  local_24 = (void *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar3 = load_config(bio_err,0);
  if (iVar3 == 0) {
LAB_08066ca2:
    uVar7 = 1;
    pBVar4 = (BIO *)0x0;
    goto LAB_08066ca9;
  }
  ppcVar5 = (char **)(param_2 + 4);
  pcVar6 = (char *)0x0;
  ERR_load_crypto_strings();
  OPENSSL_add_all_algorithms_noconf();
  pcVar12 = *ppcVar5;
  local_44 = 0;
  bVar2 = false;
  local_4c = 3;
  local_38 = (EVP_CIPHER *)0x0;
  local_40 = (char *)0x0;
  local_48 = (ENGINE *)0x0;
  pBVar4 = bio_err;
  while ((bio_err = pBVar4, pcVar12 != (char *)0x0 && (bVar10 = *pcVar12 == '-', bVar10))) {
    iVar3 = 9;
    pcVar8 = pcVar12;
    pcVar9 = "-outform";
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar10 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
      pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
    } while (bVar10);
    if (bVar10) {
      ppcVar1 = ppcVar5 + 1;
      if (*ppcVar1 == (char *)0x0) goto LAB_08067000;
      ppcVar5 = ppcVar5 + 1;
      local_4c = str2fmt(*ppcVar1);
    }
    else {
      iVar3 = 6;
      pcVar8 = pcVar12;
      pcVar9 = "-pass";
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar10 = *pcVar8 == *pcVar9;
        pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
        pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
      } while (bVar10);
      if (bVar10) {
        pcVar6 = ppcVar5[1];
        if (pcVar6 == (char *)0x0) goto LAB_08067000;
LAB_08066edb:
        ppcVar5 = ppcVar5 + 1;
      }
      else {
        iVar3 = 8;
        pcVar8 = pcVar12;
        pcVar9 = "-engine";
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar10 = *pcVar8 == *pcVar9;
          pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
          pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
        } while (bVar10);
        if (bVar10) {
          ppcVar1 = ppcVar5 + 1;
          if (*ppcVar1 == (char *)0x0) goto LAB_08067000;
          ppcVar5 = ppcVar5 + 1;
          local_48 = (ENGINE *)setup_engine(pBVar4,*ppcVar1,0);
        }
        else {
          iVar3 = 0xb;
          pcVar8 = pcVar12;
          pcVar9 = "-paramfile";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar10 = *pcVar8 == *pcVar9;
            pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
            pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            pcVar12 = ppcVar5[1];
            if ((pcVar12 == (char *)0x0) || (local_44 == 1)) goto LAB_08067000;
            if (local_28 == (EVP_PKEY_CTX *)0x0) {
              bp = BIO_new_file(pcVar12,"r");
              if (bp == (BIO *)0x0) {
                BIO_printf(pBVar4,"Can\'t open parameter file %s\n",pcVar12);
              }
              else {
                pkey = PEM_read_bio_Parameters(bp,(EVP_PKEY **)0x0);
                BIO_free(bp);
                if (pkey == (EVP_PKEY *)0x0) {
                  BIO_printf(bio_err,"Error reading parameter file %s\n",pcVar12);
                }
                else {
                  ctx = EVP_PKEY_CTX_new(pkey,local_48);
                  if (ctx == (EVP_PKEY_CTX *)0x0) {
                    BIO_puts(pBVar4,"Error initializing context\n");
                    ERR_print_errors(pBVar4);
                  }
                  else {
                    iVar3 = EVP_PKEY_keygen_init(ctx);
                    if (0 < iVar3) {
                      ppcVar5 = ppcVar5 + 1;
                      EVP_PKEY_free(pkey);
                      local_28 = ctx;
                      goto LAB_08066d9f;
                    }
                    BIO_puts(pBVar4,"Error initializing context\n");
                    ERR_print_errors(pBVar4);
                    EVP_PKEY_CTX_free(ctx);
                  }
                  EVP_PKEY_free(pkey);
                }
              }
            }
            else {
              BIO_puts(pBVar4,"Parameters already set!\n");
            }
            goto LAB_08066ca2;
          }
          iVar3 = 5;
          pcVar8 = pcVar12;
          pcVar9 = "-out";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar10 = *pcVar8 == *pcVar9;
            pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
            pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            local_40 = ppcVar5[1];
            if (local_40 != (char *)0x0) goto LAB_08066edb;
            goto LAB_08067000;
          }
          iVar3 = 0xb;
          pcVar8 = pcVar12;
          pcVar9 = "-algorithm";
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar10 = *pcVar8 == *pcVar9;
            pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
            pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
          } while (bVar10);
          if (bVar10) {
            ppcVar1 = ppcVar5 + 1;
            if (*ppcVar1 == (char *)0x0) goto LAB_08067000;
            ppcVar5 = ppcVar5 + 1;
            iVar3 = init_gen_str(pBVar4,&local_28,*ppcVar1,local_48,local_44);
            if (iVar3 == 0) goto LAB_08066ca2;
          }
          else {
            iVar3 = 9;
            pcVar8 = pcVar12;
            pcVar9 = "-pkeyopt";
            do {
              if (iVar3 == 0) break;
              iVar3 = iVar3 + -1;
              bVar10 = *pcVar8 == *pcVar9;
              pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
              pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
            } while (bVar10);
            if (bVar10) {
              ppcVar1 = ppcVar5 + 1;
              if (*ppcVar1 == (char *)0x0) goto LAB_08067000;
              if (local_28 == (EVP_PKEY_CTX *)0x0) {
                BIO_puts(pBVar4,"No keytype specified\n");
                goto LAB_08067000;
              }
              ppcVar5 = ppcVar5 + 1;
              iVar3 = pkey_ctrl_string(local_28,*ppcVar1);
              if (iVar3 < 1) {
                uVar7 = 1;
                pBVar4 = (BIO *)0x0;
                BIO_puts(bio_err,"parameter setting error\n");
                ERR_print_errors(bio_err);
                goto LAB_08066ca9;
              }
            }
            else {
              iVar3 = 10;
              pcVar8 = pcVar12;
              pcVar9 = "-genparam";
              do {
                if (iVar3 == 0) break;
                iVar3 = iVar3 + -1;
                bVar10 = *pcVar8 == *pcVar9;
                pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
                pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
              } while (bVar10);
              if (bVar10) {
                if (local_28 != (EVP_PKEY_CTX *)0x0) goto LAB_08067000;
                local_44 = 1;
              }
              else {
                iVar3 = 6;
                pcVar8 = pcVar12;
                pcVar9 = "-text";
                do {
                  if (iVar3 == 0) break;
                  iVar3 = iVar3 + -1;
                  bVar10 = *pcVar8 == *pcVar9;
                  pcVar8 = pcVar8 + (uint)bVar11 * -2 + 1;
                  pcVar9 = pcVar9 + (uint)bVar11 * -2 + 1;
                } while (bVar10);
                if (bVar10) {
                  bVar2 = true;
                }
                else {
                  local_38 = EVP_get_cipherbyname(pcVar12 + 1);
                  if (local_38 == (EVP_CIPHER *)0x0) {
                    BIO_printf(bio_err,"Unknown cipher %s\n",*ppcVar5 + 1,0);
                    goto LAB_08067000;
                  }
                  if (local_44 == 1) goto LAB_08067000;
                }
              }
            }
          }
        }
      }
    }
LAB_08066d9f:
    ppcVar5 = ppcVar5 + 1;
    pBVar4 = bio_err;
    pcVar12 = *ppcVar5;
  }
  if (local_28 == (EVP_PKEY_CTX *)0x0) {
LAB_08067000:
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
    pBVar4 = (BIO *)0x0;
    BIO_printf(bio_err,"-genparam          generate parameters, not key\n");
    uVar7 = 1;
    BIO_printf(bio_err,"-text              print the in text\n");
    BIO_printf(bio_err,"NB: options order may be important!  See the manual page.\n");
    goto LAB_08066ca9;
  }
  iVar3 = app_passwd(pBVar4,pcVar6,0,&local_24,0);
  if (iVar3 == 0) {
    uVar7 = 1;
    pBVar4 = (BIO *)0x0;
    BIO_puts(bio_err,"Error getting password\n");
    goto LAB_08066ca9;
  }
  if (local_40 == (char *)0x0) {
    pBVar4 = BIO_new_fp(stdout,0);
  }
  else {
    pBVar4 = BIO_new_file(local_40,"wb");
    if (pBVar4 == (BIO *)0x0) {
      uVar7 = 1;
      BIO_printf(bio_err,"Can\'t open output file %s\n",local_40);
      goto LAB_08066ca9;
    }
  }
  EVP_PKEY_CTX_set_cb(local_28,genpkey_cb);
  EVP_PKEY_CTX_set_app_data(local_28,bio_err);
  if (local_44 == 0) {
    iVar3 = EVP_PKEY_keygen(local_28,&local_2c);
    if (iVar3 < 1) {
      pcVar12 = "Error generating key\n";
      goto LAB_0806741f;
    }
    if (local_4c == 3) {
      iVar3 = PEM_write_bio_PrivateKey
                        (pBVar4,local_2c,local_38,(uchar *)0x0,0,(undefined1 *)0x0,local_24);
    }
    else {
      if (local_4c != 1) {
        uVar7 = 1;
        BIO_printf(bio_err,"Bad format specified for key\n");
        goto LAB_08066ca9;
      }
      iVar3 = i2d_PrivateKey_bio(pBVar4,local_2c);
    }
  }
  else {
    iVar3 = EVP_PKEY_paramgen(local_28,&local_2c);
    if (iVar3 < 1) {
      pcVar12 = "Error generating parameters\n";
LAB_0806741f:
      uVar7 = 1;
      BIO_puts(bio_err,pcVar12);
      ERR_print_errors(bio_err);
      goto LAB_08066ca9;
    }
    iVar3 = PEM_write_bio_Parameters(pBVar4,local_2c);
  }
  if (iVar3 < 1) {
    BIO_puts(bio_err,"Error writing key\n");
    ERR_print_errors(bio_err);
  }
  uVar7 = 0;
  if (bVar2) {
    if (local_44 == 0) {
      iVar3 = EVP_PKEY_print_private(pBVar4,local_2c,0,(ASN1_PCTX *)0x0);
    }
    else {
      iVar3 = EVP_PKEY_print_params(pBVar4,local_2c,0,(ASN1_PCTX *)0x0);
    }
    uVar7 = 0;
    if (iVar3 < 1) {
      BIO_puts(bio_err,"Error printing key\n");
      ERR_print_errors(bio_err);
    }
  }
LAB_08066ca9:
  if (local_2c != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(local_2c);
  }
  if (local_28 != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(local_28);
  }
  if (pBVar4 != (BIO *)0x0) {
    BIO_free_all(pBVar4);
  }
  BIO_free((BIO *)0x0);
  if (local_24 != (void *)0x0) {
    CRYPTO_free(local_24);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar7;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

