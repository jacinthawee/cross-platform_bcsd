
/* WARNING: Restarted to delay deadcode elimination for space: ram */

BIO * spkac_main(int param_1,undefined4 *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  BIO *bp;
  BIO *r;
  BIO *spki;
  size_t len;
  EVP_MD *md;
  BIO *out;
  BIO *conf;
  undefined4 uVar5;
  char **ppcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *name;
  char *local_58;
  char *local_54;
  char *local_50;
  char *local_48;
  BIO *local_38;
  void *local_2c [2];
  
  local_2c[0] = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar4 = load_config(bio_err,0);
  if (iVar4 == 0) {
LAB_0003b0c4:
    local_38 = (BIO *)0x1;
    bp = (BIO *)0x0;
    spki = (BIO *)0x0;
    out = (BIO *)0x0;
    r = (BIO *)0x0;
    conf = (BIO *)0x0;
  }
  else {
    param_1 = param_1 + -1;
    ppcVar6 = (char **)(param_2 + 1);
    uVar5 = *param_2;
    pcVar9 = (char *)0x0;
    if (param_1 < 1) {
      local_54 = (char *)0x0;
      local_48 = (char *)0x0;
      pcVar7 = (char *)0x0;
      local_50 = (char *)0x0;
      local_38 = (BIO *)0x0;
      name = "SPKAC";
      bVar2 = false;
      bVar3 = false;
      local_58 = "default";
      pcVar10 = pcVar9;
LAB_0003b1c0:
      ERR_load_crypto_strings();
      bp = (BIO *)app_passwd(bio_err,pcVar7,0,local_2c,0);
      if (bp != (BIO *)0x0) {
        uVar5 = setup_engine(bio_err,pcVar10,0);
        if (local_54 == (char *)0x0) {
          if (pcVar9 == (char *)0x0) {
            bp = BIO_new_fp(stdin,0);
          }
          else {
            bp = BIO_new_file(pcVar9,"r");
          }
          if (bp == (BIO *)0x0) {
            BIO_printf(bio_err,"Error opening input file\n");
            ERR_print_errors(bio_err);
            local_38 = (BIO *)0x1;
            spki = bp;
            out = bp;
            r = bp;
            conf = bp;
          }
          else {
            conf = (BIO *)NCONF_new((CONF_METHOD *)0x0);
            spki = (BIO *)NCONF_load_bio((CONF *)conf,bp,(long *)0x0);
            if (spki == (BIO *)0x0) {
              BIO_printf(bio_err,"Error parsing config file\n");
              ERR_print_errors(bio_err);
              local_38 = (BIO *)0x1;
              out = spki;
              r = spki;
            }
            else {
              spki = (BIO *)NCONF_get_string((CONF *)conf,local_58,name);
              if (spki == (BIO *)0x0) {
                BIO_printf(bio_err,"Can\'t find SPKAC called \"%s\"\n",name);
                ERR_print_errors(bio_err);
                local_38 = (BIO *)0x1;
                out = spki;
                r = spki;
              }
              else {
                spki = (BIO *)NETSCAPE_SPKI_b64_decode((char *)spki,-1);
                if (spki == (BIO *)0x0) {
                  BIO_printf(bio_err,"Error loading SPKAC\n");
                  ERR_print_errors(bio_err);
                  local_38 = (BIO *)0x1;
                  out = spki;
                  r = spki;
                }
                else {
                  if (local_50 == (char *)0x0) {
                    out = BIO_new_fp(stdout,0);
                  }
                  else {
                    out = BIO_new_file(local_50,"w");
                  }
                  if (out == (BIO *)0x0) {
                    BIO_printf(bio_err,"Error opening output file\n");
                    ERR_print_errors(bio_err);
                    local_38 = (BIO *)0x1;
                    r = out;
                  }
                  else {
                    if (!bVar2) {
                      NETSCAPE_SPKI_print(out,(NETSCAPE_SPKI *)spki);
                    }
                    r = (BIO *)NETSCAPE_SPKI_get_pubkey((NETSCAPE_SPKI *)spki);
                    if (bVar3) {
                      iVar4 = NETSCAPE_SPKI_verify((NETSCAPE_SPKI *)spki,(EVP_PKEY *)r);
                      if (iVar4 < 1) {
                        local_38 = (BIO *)0x1;
                        BIO_printf(bio_err,"Signature Failure\n");
                        ERR_print_errors(bio_err);
                        goto LAB_0003b0d4;
                      }
                      BIO_printf(bio_err,"Signature OK\n");
                    }
                    if (local_38 != (BIO *)0x0) {
                      PEM_write_bio_PUBKEY(out,(EVP_PKEY *)r);
                      local_38 = (BIO *)0x0;
                    }
                  }
                }
              }
            }
          }
          goto LAB_0003b0d4;
        }
        if ((*local_54 == '-') && (local_54[1] == '\0')) {
          local_54 = (char *)0x0;
        }
        r = (BIO *)load_key(bio_err,local_54,3,1,local_2c[0],uVar5,"private key");
        if (r != (BIO *)0x0) {
          spki = (BIO *)NETSCAPE_SPKI_new();
          if (local_48 != (char *)0x0) {
            len = strlen(local_48);
            ASN1_STRING_set((ASN1_STRING *)spki->method->name,local_48,len);
          }
          NETSCAPE_SPKI_set_pubkey((NETSCAPE_SPKI *)spki,(EVP_PKEY *)r);
          md = EVP_md5();
          NETSCAPE_SPKI_sign((NETSCAPE_SPKI *)spki,(EVP_PKEY *)r,md);
          pcVar9 = NETSCAPE_SPKI_b64_encode((NETSCAPE_SPKI *)spki);
          if (local_50 == (char *)0x0) {
            out = BIO_new_fp(stdout,0);
          }
          else {
            out = BIO_new_file(local_50,"w");
          }
          if (out == (BIO *)0x0) {
            BIO_printf(bio_err,"Error opening output file\n");
            ERR_print_errors(bio_err);
            local_38 = (BIO *)0x1;
            bp = out;
            conf = out;
          }
          else {
            BIO_printf(out,"SPKAC=%s\n",pcVar9);
            local_38 = (BIO *)0x0;
            CRYPTO_free(pcVar9);
            bp = local_38;
            conf = (BIO *)0x0;
          }
          goto LAB_0003b0d4;
        }
        goto LAB_0003b0c4;
      }
      pcVar9 = "Error getting password\n";
    }
    else {
      local_54 = (char *)0x0;
      local_48 = (char *)0x0;
      pcVar10 = (char *)0x0;
      pcVar8 = (char *)0x0;
      local_38 = (BIO *)0x0;
      name = "SPKAC";
      bVar2 = false;
      local_50 = (char *)0x0;
      bVar3 = false;
      bVar1 = false;
      local_58 = "default";
LAB_0003b172:
      do {
        pcVar7 = *ppcVar6;
        if ((((*pcVar7 == '-') && (pcVar7[1] == 'i')) && (pcVar7[2] == 'n')) && (pcVar7[3] == '\0'))
        {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0003b36a;
          pcVar8 = ppcVar6[1];
          ppcVar6 = ppcVar6 + 1;
        }
        else {
          iVar4 = strcmp(pcVar7,"-out");
          if (iVar4 == 0) {
            if (param_1 == 1) goto LAB_0003b36a;
            param_1 = param_1 + -2;
            local_50 = ppcVar6[1];
            ppcVar6 = ppcVar6 + 2;
            pcVar7 = pcVar9;
            if (param_1 < 1) break;
            goto LAB_0003b172;
          }
          iVar4 = strcmp(pcVar7,"-passin");
          if (iVar4 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0003b36a;
            pcVar9 = ppcVar6[1];
            ppcVar6 = ppcVar6 + 1;
          }
          else {
            iVar4 = strcmp(pcVar7,"-key");
            if (iVar4 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0003b36a;
              local_54 = ppcVar6[1];
              ppcVar6 = ppcVar6 + 1;
            }
            else {
              iVar4 = strcmp(pcVar7,"-challenge");
              if (iVar4 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_0003b36a;
                local_48 = ppcVar6[1];
                ppcVar6 = ppcVar6 + 1;
              }
              else {
                iVar4 = strcmp(pcVar7,"-spkac");
                if (iVar4 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_0003b36a;
                  name = ppcVar6[1];
                  ppcVar6 = ppcVar6 + 1;
                }
                else {
                  iVar4 = strcmp(pcVar7,"-spksect");
                  if (iVar4 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 == 0) goto LAB_0003b36a;
                    local_58 = ppcVar6[1];
                    ppcVar6 = ppcVar6 + 1;
                  }
                  else {
                    iVar4 = strcmp(pcVar7,"-engine");
                    if (iVar4 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 == 0) goto LAB_0003b36a;
                      pcVar10 = ppcVar6[1];
                      ppcVar6 = ppcVar6 + 1;
                    }
                    else {
                      iVar4 = strcmp(pcVar7,"-noout");
                      if (iVar4 == 0) {
                        bVar2 = true;
                      }
                      else {
                        iVar4 = strcmp(pcVar7,"-pubkey");
                        if (iVar4 == 0) {
                          local_38 = (BIO *)0x1;
                        }
                        else {
                          iVar4 = strcmp(pcVar7,"-verify");
                          if (iVar4 == 0) {
                            bVar3 = true;
                          }
                          else {
                            bVar1 = true;
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
        param_1 = param_1 + -1;
        ppcVar6 = ppcVar6 + 1;
        pcVar7 = pcVar9;
      } while (0 < param_1);
      pcVar9 = pcVar8;
      if (!bVar1) goto LAB_0003b1c0;
LAB_0003b36a:
      BIO_printf(bio_err,"%s [options]\n",uVar5);
      BIO_printf(bio_err,"where options are\n");
      BIO_printf(bio_err," -in arg        input file\n");
      BIO_printf(bio_err," -out arg       output file\n");
      BIO_printf(bio_err," -key arg       create SPKAC using private key\n");
      BIO_printf(bio_err," -passin arg    input file pass phrase source\n");
      BIO_printf(bio_err," -challenge arg challenge string\n");
      BIO_printf(bio_err," -spkac arg     alternative SPKAC name\n");
      BIO_printf(bio_err," -noout         don\'t print SPKAC\n");
      BIO_printf(bio_err," -pubkey        output public key\n");
      BIO_printf(bio_err," -verify        verify SPKAC signature\n");
      bp = (BIO *)0x0;
      pcVar9 = " -engine e      use engine e, possibly a hardware device.\n";
    }
    BIO_printf(bio_err,pcVar9);
    local_38 = (BIO *)0x1;
    spki = bp;
    out = bp;
    r = bp;
    conf = bp;
  }
LAB_0003b0d4:
  NCONF_free((CONF *)conf);
  NETSCAPE_SPKI_free((NETSCAPE_SPKI *)spki);
  BIO_free(bp);
  BIO_free_all(out);
  EVP_PKEY_free((EVP_PKEY *)r);
  if (local_2c[0] != (void *)0x0) {
    CRYPTO_free(local_2c[0]);
  }
  return local_38;
}

