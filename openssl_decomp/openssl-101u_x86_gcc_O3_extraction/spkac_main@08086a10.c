
undefined4 spkac_main(int param_1,undefined4 *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  byte **ppbVar7;
  undefined4 uVar8;
  size_t len;
  EVP_MD *md;
  CONF *conf;
  EVP_PKEY *r;
  byte *pbVar9;
  BIO *bp;
  BIO *out;
  byte *pbVar10;
  byte *pbVar11;
  NETSCAPE_SPKI *spki;
  byte *pbVar12;
  int in_GS_OFFSET;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  byte bVar16;
  char *pcVar17;
  int local_60;
  byte *local_5c;
  byte *local_58;
  byte *local_54;
  byte *local_4c;
  byte *local_44;
  byte *local_40;
  byte *local_3c;
  void *local_24;
  int local_20;
  
  bVar16 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar6 = load_config(bio_err,0);
  if (iVar6 != 0) {
    local_60 = param_1 + -1;
    ppbVar7 = (byte **)(param_2 + 1);
    if (0 < local_60) {
      local_3c = (byte *)0x0;
      local_54 = (byte *)0x0;
      pbVar9 = (byte *)0x0;
      local_4c = (byte *)0x0;
      local_40 = (byte *)0x822e832;
      local_44 = (byte *)0x8227a66;
      local_58 = (byte *)0x0;
      local_5c = (byte *)0x0;
      bVar3 = false;
      bVar1 = false;
      bVar2 = false;
      bVar5 = false;
LAB_08086b09:
      pbVar11 = *ppbVar7;
      bVar13 = *pbVar11 < 0x2d;
      bVar15 = *pbVar11 == 0x2d;
      bVar4 = bVar5;
      if (bVar15) {
        bVar13 = pbVar11[1] < 0x69;
        bVar15 = pbVar11[1] == 0x69;
        if (!bVar15) goto LAB_08086b10;
        bVar13 = pbVar11[2] < 0x6e;
        bVar15 = pbVar11[2] == 0x6e;
        if (!bVar15) goto LAB_08086b10;
        bVar13 = false;
        bVar15 = pbVar11[3] == 0;
        if (!bVar15) goto LAB_08086b10;
        local_60 = local_60 + -1;
        if (local_60 == 0) goto LAB_08086b57;
        pbVar9 = ppbVar7[1];
        ppbVar7 = ppbVar7 + 1;
      }
      else {
LAB_08086b10:
        iVar6 = 5;
        pbVar10 = pbVar11;
        pbVar12 = &DAT_081eab75;
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar13 = *pbVar10 < *pbVar12;
          bVar15 = *pbVar10 == *pbVar12;
          pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
          pbVar12 = pbVar12 + (uint)bVar16 * -2 + 1;
        } while (bVar15);
        bVar14 = (!bVar13 && !bVar15) < bVar13;
        bVar13 = (!bVar13 && !bVar15) == bVar13;
        if (bVar13) {
          if (local_60 == 1) goto LAB_08086b57;
          local_60 = local_60 + -2;
          local_5c = ppbVar7[1];
          ppbVar7 = ppbVar7 + 2;
          goto joined_r0x08086b49;
        }
        iVar6 = 8;
        pbVar10 = pbVar11;
        pbVar12 = (byte *)"-passin";
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar14 = *pbVar10 < *pbVar12;
          bVar13 = *pbVar10 == *pbVar12;
          pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
          pbVar12 = pbVar12 + (uint)bVar16 * -2 + 1;
        } while (bVar13);
        if (bVar13) {
          local_60 = local_60 + -1;
          if (local_60 == 0) goto LAB_08086b57;
          local_58 = ppbVar7[1];
          ppbVar7 = ppbVar7 + 1;
        }
        else {
          iVar6 = 5;
          pbVar10 = pbVar11;
          pbVar12 = (byte *)0x8228a07;
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar14 = *pbVar10 < *pbVar12;
            bVar13 = *pbVar10 == *pbVar12;
            pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
            pbVar12 = pbVar12 + (uint)bVar16 * -2 + 1;
          } while (bVar13);
          if (bVar13) {
            local_60 = local_60 + -1;
            if (local_60 == 0) goto LAB_08086b57;
            local_54 = ppbVar7[1];
            ppbVar7 = ppbVar7 + 1;
          }
          else {
            iVar6 = 0xb;
            pbVar10 = pbVar11;
            pbVar12 = (byte *)"-challenge";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar14 = *pbVar10 < *pbVar12;
              bVar13 = *pbVar10 == *pbVar12;
              pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
              pbVar12 = pbVar12 + (uint)bVar16 * -2 + 1;
            } while (bVar13);
            if (bVar13) {
              local_60 = local_60 + -1;
              if (local_60 != 0) {
                local_4c = ppbVar7[1];
                ppbVar7 = ppbVar7 + 1;
                goto LAB_08086aff;
              }
              goto LAB_08086b57;
            }
            iVar6 = 7;
            pbVar10 = pbVar11;
            pbVar12 = (byte *)"-spkac";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar14 = *pbVar10 < *pbVar12;
              bVar13 = *pbVar10 == *pbVar12;
              pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
              pbVar12 = pbVar12 + (uint)bVar16 * -2 + 1;
            } while (bVar13);
            if (bVar13) {
              local_60 = local_60 + -1;
              if (local_60 == 0) goto LAB_08086b57;
              local_44 = ppbVar7[1];
              ppbVar7 = ppbVar7 + 1;
            }
            else {
              iVar6 = 9;
              pbVar10 = pbVar11;
              pbVar12 = (byte *)"-spksect";
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar14 = *pbVar10 < *pbVar12;
                bVar13 = *pbVar10 == *pbVar12;
                pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
                pbVar12 = pbVar12 + (uint)bVar16 * -2 + 1;
              } while (bVar13);
              if (bVar13) {
                local_60 = local_60 + -1;
                if (local_60 == 0) goto LAB_08086b57;
                local_40 = ppbVar7[1];
                ppbVar7 = ppbVar7 + 1;
              }
              else {
                iVar6 = 8;
                pbVar10 = pbVar11;
                pbVar12 = (byte *)"-engine";
                do {
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  bVar14 = *pbVar10 < *pbVar12;
                  bVar13 = *pbVar10 == *pbVar12;
                  pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
                  pbVar12 = pbVar12 + (uint)bVar16 * -2 + 1;
                } while (bVar13);
                if (bVar13) {
                  local_60 = local_60 + -1;
                  if (local_60 == 0) goto LAB_08086b57;
                  local_3c = ppbVar7[1];
                  ppbVar7 = ppbVar7 + 1;
                }
                else {
                  iVar6 = 7;
                  pbVar10 = pbVar11;
                  pbVar12 = (byte *)"-noout";
                  do {
                    if (iVar6 == 0) break;
                    iVar6 = iVar6 + -1;
                    bVar14 = *pbVar10 < *pbVar12;
                    bVar13 = *pbVar10 == *pbVar12;
                    pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
                    pbVar12 = pbVar12 + (uint)bVar16 * -2 + 1;
                  } while (bVar13);
                  if (bVar13) {
                    bVar1 = true;
                  }
                  else {
                    iVar6 = 8;
                    pbVar10 = pbVar11;
                    pbVar12 = (byte *)"-pubkey";
                    do {
                      if (iVar6 == 0) break;
                      iVar6 = iVar6 + -1;
                      bVar14 = *pbVar10 < *pbVar12;
                      bVar13 = *pbVar10 == *pbVar12;
                      pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
                      pbVar12 = pbVar12 + (uint)bVar16 * -2 + 1;
                    } while (bVar13);
                    if (bVar13) {
                      bVar3 = true;
                    }
                    else {
                      iVar6 = 8;
                      pbVar10 = (byte *)"-verify";
                      do {
                        if (iVar6 == 0) break;
                        iVar6 = iVar6 + -1;
                        bVar14 = *pbVar11 < *pbVar10;
                        bVar13 = *pbVar11 == *pbVar10;
                        pbVar11 = pbVar11 + (uint)bVar16 * -2 + 1;
                        pbVar10 = pbVar10 + (uint)bVar16 * -2 + 1;
                      } while (bVar13);
                      bVar4 = true;
                      if ((!bVar14 && !bVar13) == bVar14) {
                        bVar2 = true;
                        bVar4 = bVar5;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
LAB_08086aff:
      local_60 = local_60 + -1;
      ppbVar7 = ppbVar7 + 1;
      bVar5 = bVar4;
joined_r0x08086b49:
      if (local_60 == 0) goto LAB_08086b4b;
      goto LAB_08086b09;
    }
    local_44 = (byte *)0x8227a66;
    bVar1 = false;
    pbVar9 = (byte *)0x0;
    local_5c = (byte *)0x0;
    local_58 = (byte *)0x0;
    local_40 = (byte *)0x822e832;
    local_4c = (byte *)0x0;
    local_54 = (byte *)0x0;
    local_3c = (byte *)0x0;
    bVar3 = false;
    bVar2 = false;
    goto LAB_08086dec;
  }
LAB_08086c37:
  r = (EVP_PKEY *)0x0;
  spki = (NETSCAPE_SPKI *)0x0;
  conf = (CONF *)0x0;
  out = (BIO *)0x0;
  bp = (BIO *)0x0;
  local_60 = 1;
LAB_08086c49:
  NCONF_free(conf);
  NETSCAPE_SPKI_free(spki);
  BIO_free(bp);
  BIO_free_all(out);
  EVP_PKEY_free(r);
  if (local_24 != (void *)0x0) {
    CRYPTO_free(local_24);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_60;
LAB_08086b4b:
  if (bVar5) {
LAB_08086b57:
    BIO_printf(bio_err,"%s [options]\n",*param_2);
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
    pcVar17 = " -engine e      use engine e, possibly a hardware device.\n";
  }
  else {
LAB_08086dec:
    ERR_load_crypto_strings();
    iVar6 = app_passwd(bio_err,local_58,0,&local_24,0);
    if (iVar6 != 0) {
      uVar8 = setup_engine(bio_err,local_3c,0);
      if (local_54 == (byte *)0x0) {
        if (pbVar9 == (byte *)0x0) {
          bp = BIO_new_fp(stdin,0);
        }
        else {
          bp = BIO_new_file((char *)pbVar9,"r");
        }
        if (bp == (BIO *)0x0) {
          r = (EVP_PKEY *)0x0;
          spki = (NETSCAPE_SPKI *)0x0;
          out = (BIO *)0x0;
          BIO_printf(bio_err,"Error opening input file\n");
          ERR_print_errors(bio_err);
          conf = (CONF *)0x0;
          local_60 = 1;
        }
        else {
          conf = NCONF_new((CONF_METHOD *)0x0);
          pbVar9 = (byte *)0x0;
          iVar6 = NCONF_load_bio(conf,bp,(long *)0x0);
          if (iVar6 == 0) {
            pcVar17 = "Error parsing config file\n";
            local_44 = pbVar9;
          }
          else {
            pcVar17 = NCONF_get_string(conf,(char *)local_40,(char *)local_44);
            if (pcVar17 != (char *)0x0) {
              spki = NETSCAPE_SPKI_b64_decode(pcVar17,-1);
              if (spki == (NETSCAPE_SPKI *)0x0) {
                r = (EVP_PKEY *)0x0;
                out = (BIO *)0x0;
                BIO_printf(bio_err,"Error loading SPKAC\n");
                ERR_print_errors(bio_err);
                local_60 = 1;
              }
              else {
                if (local_5c == (byte *)0x0) {
                  out = BIO_new_fp(stdout,0);
                }
                else {
                  out = BIO_new_file((char *)local_5c,"w");
                }
                if (out == (BIO *)0x0) {
                  r = (EVP_PKEY *)0x0;
                  BIO_printf(bio_err,"Error opening output file\n");
                  ERR_print_errors(bio_err);
                  local_60 = 1;
                }
                else {
                  if (!bVar1) {
                    NETSCAPE_SPKI_print(out,spki);
                  }
                  r = NETSCAPE_SPKI_get_pubkey(spki);
                  if (bVar2) {
                    iVar6 = NETSCAPE_SPKI_verify(spki,r);
                    if (iVar6 < 1) {
                      BIO_printf(bio_err,"Signature Failure\n");
                      ERR_print_errors(bio_err);
                      local_60 = 1;
                      goto LAB_08086c49;
                    }
                    BIO_printf(bio_err,"Signature OK\n");
                  }
                  local_60 = 0;
                  if (bVar3) {
                    PEM_write_bio_PUBKEY(out,r);
                  }
                }
              }
              goto LAB_08086c49;
            }
            pcVar17 = "Can\'t find SPKAC called \"%s\"\n";
          }
          r = (EVP_PKEY *)0x0;
          spki = (NETSCAPE_SPKI *)0x0;
          out = (BIO *)0x0;
          BIO_printf(bio_err,pcVar17,local_44);
          ERR_print_errors(bio_err);
          local_60 = 1;
        }
        goto LAB_08086c49;
      }
      if ((*local_54 == 0x2d) && (local_54[1] == 0)) {
        local_54 = (byte *)0x0;
      }
      r = (EVP_PKEY *)load_key(bio_err,local_54,3,1,local_24,uVar8,"private key");
      if (r != (EVP_PKEY *)0x0) {
        spki = NETSCAPE_SPKI_new();
        if (local_4c != (byte *)0x0) {
          len = strlen((char *)local_4c);
          ASN1_STRING_set(spki->spkac->challenge,local_4c,len);
        }
        NETSCAPE_SPKI_set_pubkey(spki,r);
        md = EVP_md5();
        NETSCAPE_SPKI_sign(spki,r,md);
        pcVar17 = NETSCAPE_SPKI_b64_encode(spki);
        if (local_5c == (byte *)0x0) {
          out = BIO_new_fp(stdout,0);
        }
        else {
          out = BIO_new_file((char *)local_5c,"w");
        }
        if (out == (BIO *)0x0) {
          bp = (BIO *)0x0;
          BIO_printf(bio_err,"Error opening output file\n");
          ERR_print_errors(bio_err);
          conf = (CONF *)0x0;
          local_60 = 1;
        }
        else {
          BIO_printf(out,"SPKAC=%s\n",pcVar17);
          bp = (BIO *)0x0;
          CRYPTO_free(pcVar17);
          conf = (CONF *)0x0;
          local_60 = 0;
        }
        goto LAB_08086c49;
      }
      goto LAB_08086c37;
    }
    pcVar17 = "Error getting password\n";
  }
  BIO_printf(bio_err,pcVar17);
  goto LAB_08086c37;
}

