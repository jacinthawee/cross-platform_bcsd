
undefined4 rsautl_main(int param_1,int param_2)

{
  char **ppcVar1;
  uchar uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  uchar *from;
  uchar *to;
  uchar *puVar8;
  uchar *puVar9;
  EVP_PKEY *pkey;
  X509 *x;
  undefined4 extraout_ECX;
  uchar *puVar10;
  char **ppcVar11;
  undefined4 uVar12;
  rsa_st *rsa;
  char *pcVar13;
  BIO *b;
  char *pcVar14;
  int in_GS_OFFSET;
  bool bVar15;
  byte bVar16;
  char *pcVar17;
  char *local_50;
  char *local_4c;
  BIO *local_48;
  char *local_44;
  char *local_40;
  undefined4 local_3c;
  char local_37;
  byte local_35;
  byte local_34;
  void *local_24;
  int local_20;
  
  bVar16 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = (void *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar7 = load_config(bio_err,0);
  if (iVar7 == 0) {
    rsa = (RSA *)0x0;
    b = (BIO *)0x0;
LAB_0805eaa4:
    uVar12 = 1;
    RSA_free(rsa);
    BIO_free(b);
    BIO_free_all((BIO *)0x0);
  }
  else {
    param_1 = param_1 + -1;
    ERR_load_crypto_strings();
    OPENSSL_add_all_algorithms_noconf();
    if (0 < param_1) {
      ppcVar11 = (char **)(param_2 + 4);
      local_44 = (char *)0x0;
      local_34 = 1;
      bVar5 = false;
      bVar6 = false;
      bVar4 = false;
      bVar3 = false;
      local_3c = 3;
      local_37 = '\x01';
      local_35 = 2;
      local_48 = (BIO *)0x0;
      local_40 = (char *)0x0;
      local_4c = (char *)0x0;
      local_50 = (char *)0x0;
LAB_0805ea3f:
      do {
        pcVar17 = *ppcVar11;
        bVar15 = *pcVar17 == '-';
        if ((((bVar15) && (bVar15 = pcVar17[1] == 'i', bVar15)) &&
            (bVar15 = pcVar17[2] == 'n', bVar15)) && (bVar15 = pcVar17[3] == '\0', bVar15)) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            local_50 = ppcVar11[1];
            ppcVar11 = ppcVar11 + 1;
            goto LAB_0805ea35;
          }
LAB_0805eb90:
          BIO_printf(bio_err,"Usage: rsautl [options]\n");
          BIO_printf(bio_err,"-in file        input file\n");
          BIO_printf(bio_err,"-out file       output file\n");
          BIO_printf(bio_err,"-inkey file     input key\n");
          BIO_printf(bio_err,"-keyform arg    private key format - default PEM\n");
          BIO_printf(bio_err,"-pubin          input is an RSA public\n");
          BIO_printf(bio_err,"-certin         input is a certificate carrying an RSA public key\n");
          BIO_printf(bio_err,"-ssl            use SSL v2 padding\n");
          BIO_printf(bio_err,"-raw            use no padding\n");
          BIO_printf(bio_err,"-pkcs           use PKCS#1 v1.5 padding (default)\n");
          BIO_printf(bio_err,"-oaep           use PKCS#1 OAEP\n");
          BIO_printf(bio_err,"-sign           sign with private key\n");
          BIO_printf(bio_err,"-verify         verify with public key\n");
          BIO_printf(bio_err,"-encrypt        encrypt with public key\n");
          BIO_printf(bio_err,"-decrypt        decrypt with private key\n");
          BIO_printf(bio_err,"-hexdump        hex dump output\n");
          BIO_printf(bio_err,"-engine e       use engine e, possibly a hardware device.\n");
          pcVar17 = "-passin arg    pass phrase source\n";
          goto LAB_0805ecca;
        }
        iVar7 = 5;
        pcVar13 = pcVar17;
        pcVar14 = "-out";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar15 = *pcVar13 == *pcVar14;
          pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
        } while (bVar15);
        if (bVar15) {
          if (param_1 == 1) goto LAB_0805eb90;
          local_4c = ppcVar11[1];
          param_1 = param_1 + -2;
          ppcVar11 = ppcVar11 + 2;
          if (param_1 < 1) break;
          goto LAB_0805ea3f;
        }
        iVar7 = 7;
        pcVar13 = pcVar17;
        pcVar14 = "-inkey";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar15 = *pcVar13 == *pcVar14;
          pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
        } while (bVar15);
        if (bVar15) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0805eb90;
          local_48 = (BIO *)ppcVar11[1];
          ppcVar11 = ppcVar11 + 1;
        }
        else {
          iVar7 = 8;
          pcVar13 = pcVar17;
          pcVar14 = "-passin";
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar15 = *pcVar13 == *pcVar14;
            pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
            pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
          } while (bVar15);
          if (bVar15) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0805eb90;
            local_44 = ppcVar11[1];
            ppcVar11 = ppcVar11 + 1;
          }
          else {
            iVar7 = 9;
            pcVar13 = pcVar17;
            pcVar14 = "-keyform";
            do {
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              bVar15 = *pcVar13 == *pcVar14;
              pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
              pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
            } while (bVar15);
            if (bVar15) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0805eb90;
              ppcVar1 = ppcVar11 + 1;
              ppcVar11 = ppcVar11 + 1;
              local_3c = str2fmt(*ppcVar1);
            }
            else {
              iVar7 = 8;
              pcVar13 = pcVar17;
              pcVar14 = "-engine";
              do {
                if (iVar7 == 0) break;
                iVar7 = iVar7 + -1;
                bVar15 = *pcVar13 == *pcVar14;
                pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
              } while (bVar15);
              if (bVar15) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_0805eb90;
                local_40 = ppcVar11[1];
                ppcVar11 = ppcVar11 + 1;
              }
              else {
                iVar7 = 7;
                pcVar13 = pcVar17;
                pcVar14 = "-pubin";
                do {
                  if (iVar7 == 0) break;
                  iVar7 = iVar7 + -1;
                  bVar15 = *pcVar13 == *pcVar14;
                  pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                  pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                } while (bVar15);
                if (bVar15) {
                  local_37 = '\x02';
                }
                else {
                  iVar7 = 8;
                  pcVar13 = pcVar17;
                  pcVar14 = "-certin";
                  do {
                    if (iVar7 == 0) break;
                    iVar7 = iVar7 + -1;
                    bVar15 = *pcVar13 == *pcVar14;
                    pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                    pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                  } while (bVar15);
                  if (bVar15) {
                    local_37 = '\x03';
                  }
                  else {
                    iVar7 = 0xb;
                    pcVar13 = pcVar17;
                    pcVar14 = "-asn1parse";
                    do {
                      if (iVar7 == 0) break;
                      iVar7 = iVar7 + -1;
                      bVar15 = *pcVar13 == *pcVar14;
                      pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                      pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                    } while (bVar15);
                    if (bVar15) {
                      bVar5 = true;
                    }
                    else {
                      iVar7 = 9;
                      pcVar13 = pcVar17;
                      pcVar14 = "-hexdump";
                      do {
                        if (iVar7 == 0) break;
                        iVar7 = iVar7 + -1;
                        bVar15 = *pcVar13 == *pcVar14;
                        pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                        pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                      } while (bVar15);
                      if (bVar15) {
                        bVar6 = true;
                      }
                      else {
                        iVar7 = 5;
                        pcVar13 = pcVar17;
                        pcVar14 = "-raw";
                        do {
                          if (iVar7 == 0) break;
                          iVar7 = iVar7 + -1;
                          bVar15 = *pcVar13 == *pcVar14;
                          pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                          pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                        } while (bVar15);
                        if (bVar15) {
                          local_34 = 3;
                        }
                        else {
                          iVar7 = 6;
                          pcVar13 = pcVar17;
                          pcVar14 = "-oaep";
                          do {
                            if (iVar7 == 0) break;
                            iVar7 = iVar7 + -1;
                            bVar15 = *pcVar13 == *pcVar14;
                            pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                            pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                          } while (bVar15);
                          if (bVar15) {
                            local_34 = 4;
                          }
                          else {
                            iVar7 = 5;
                            pcVar13 = pcVar17;
                            pcVar14 = "-ssl";
                            do {
                              if (iVar7 == 0) break;
                              iVar7 = iVar7 + -1;
                              bVar15 = *pcVar13 == *pcVar14;
                              pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                              pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                            } while (bVar15);
                            if (bVar15) {
                              local_34 = 2;
                            }
                            else {
                              iVar7 = 6;
                              pcVar13 = pcVar17;
                              pcVar14 = "-pkcs";
                              do {
                                if (iVar7 == 0) break;
                                iVar7 = iVar7 + -1;
                                bVar15 = *pcVar13 == *pcVar14;
                                pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                                pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                              } while (bVar15);
                              if (bVar15) {
                                local_34 = 1;
                              }
                              else {
                                iVar7 = 6;
                                pcVar13 = pcVar17;
                                pcVar14 = "-x931";
                                do {
                                  if (iVar7 == 0) break;
                                  iVar7 = iVar7 + -1;
                                  bVar15 = *pcVar13 == *pcVar14;
                                  pcVar13 = pcVar13 + (uint)bVar16 * -2 + 1;
                                  pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                                } while (bVar15);
                                if (bVar15) {
                                  local_34 = 5;
                                }
                                else {
                                  iVar7 = strcmp(pcVar17,"-sign");
                                  if (iVar7 == 0) {
                                    bVar3 = true;
                                    local_35 = 1;
                                  }
                                  else {
                                    iVar7 = strcmp(pcVar17,"-verify");
                                    if (iVar7 == 0) {
                                      local_35 = 2;
                                    }
                                    else {
                                      iVar7 = strcmp(pcVar17,"-rev");
                                      if (iVar7 == 0) {
                                        bVar4 = true;
                                      }
                                      else {
                                        iVar7 = strcmp(pcVar17,"-encrypt");
                                        local_35 = 3;
                                        if (iVar7 != 0) {
                                          iVar7 = strcmp(pcVar17,"-decrypt");
                                          if (iVar7 != 0) goto LAB_0805eb90;
                                          bVar3 = true;
                                          local_35 = 4;
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
            }
          }
        }
LAB_0805ea35:
        param_1 = param_1 + -1;
        ppcVar11 = ppcVar11 + 1;
      } while (0 < param_1);
      if ((!bVar3) || (local_37 == '\x01')) goto LAB_0805ed68;
      pcVar17 = "A private key is needed for this operation\n";
LAB_0805ecca:
      rsa = (RSA *)0x0;
      b = (BIO *)0x0;
      BIO_printf(bio_err,pcVar17);
      goto LAB_0805eaa4;
    }
    local_35 = 2;
    local_3c = 3;
    bVar6 = false;
    bVar5 = false;
    local_34 = 1;
    local_44 = (char *)0x0;
    local_50 = (char *)0x0;
    local_48 = (BIO *)0x0;
    local_37 = '\x01';
    bVar4 = false;
    local_4c = (char *)0x0;
    local_40 = (char *)0x0;
LAB_0805ed68:
    uVar12 = setup_engine(bio_err,local_40,0);
    iVar7 = app_passwd(bio_err,local_44,0,&local_24,0);
    if (iVar7 == 0) {
      pcVar17 = "Error getting password\n";
      goto LAB_0805ecca;
    }
    app_RAND_load_file(0,bio_err,0);
    if (local_37 != '\x02') {
      if (local_37 == '\x03') {
        x = (X509 *)load_cert(bio_err,local_48,local_3c,0,uVar12,"Certificate");
        if (x != (X509 *)0x0) {
          pkey = X509_get_pubkey(x);
          X509_free(x);
          goto LAB_0805efa1;
        }
      }
      else if (local_37 == '\x01') {
        pkey = (EVP_PKEY *)load_key(bio_err,local_48,local_3c,0,local_24,uVar12,"Private Key");
        goto LAB_0805efa1;
      }
LAB_0805ef66:
      uVar12 = 1;
      goto LAB_0805eadd;
    }
    pkey = (EVP_PKEY *)load_pubkey(bio_err,local_48,local_3c,0,0,uVar12,"Public Key");
LAB_0805efa1:
    if (pkey == (EVP_PKEY *)0x0) goto LAB_0805ef66;
    rsa = EVP_PKEY_get1_RSA(pkey);
    EVP_PKEY_free(pkey);
    if (rsa == (rsa_st *)0x0) {
      BIO_printf(bio_err,"Error getting RSA key\n");
      b = (BIO *)0x0;
      ERR_print_errors(bio_err);
      goto LAB_0805eaa4;
    }
    if (local_50 != (char *)0x0) {
      b = BIO_new_file(local_50,"rb");
      if (b != (BIO *)0x0) goto LAB_0805efea;
      pcVar17 = "Error Reading Input File\n";
LAB_0805f35b:
      BIO_printf(bio_err,pcVar17);
      ERR_print_errors(bio_err);
      goto LAB_0805eaa4;
    }
    b = BIO_new_fp(stdin,0);
LAB_0805efea:
    if (local_4c == (char *)0x0) {
      local_48 = BIO_new_fp(stdout,0);
    }
    else {
      local_48 = BIO_new_file(local_4c,"wb");
      if (local_48 == (BIO *)0x0) {
        pcVar17 = "Error Reading Output File\n";
        goto LAB_0805f35b;
      }
    }
    iVar7 = RSA_size(rsa);
    from = (uchar *)CRYPTO_malloc(iVar7 * 2,"rsautl.c",0x104);
    to = (uchar *)CRYPTO_malloc(iVar7,"rsautl.c",0x105);
    iVar7 = BIO_read(b,from,iVar7 * 2);
    if (iVar7 < 1) {
      BIO_printf(bio_err,"Error reading input Data\n",extraout_ECX,extraout_ECX);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    if (bVar4) {
      if (iVar7 >> 1 != 0) {
        puVar8 = from;
        puVar10 = from + iVar7 + -1;
        do {
          uVar2 = *puVar8;
          puVar9 = puVar8 + 1;
          *puVar8 = *puVar10;
          *puVar10 = uVar2;
          puVar8 = puVar9;
          puVar10 = puVar10 + -1;
        } while (puVar9 != from + (iVar7 >> 1));
      }
    }
    if (local_35 == 2) {
      iVar7 = RSA_public_decrypt(iVar7,from,to,rsa,(uint)local_34);
LAB_0805f0e9:
      if (iVar7 < 1) goto LAB_0805f2e6;
      if (bVar5) {
        uVar12 = 0;
        iVar7 = ASN1_parse_dump(local_48,to,iVar7,1,-1);
        if (iVar7 == 0) {
          ERR_print_errors(bio_err);
        }
      }
      else if (bVar6) {
        uVar12 = 0;
        BIO_dump(local_48,(char *)to,iVar7);
      }
      else {
        uVar12 = 0;
        BIO_write(local_48,to,iVar7);
      }
    }
    else {
      if (2 < local_35) {
        if (local_35 == 3) {
          iVar7 = RSA_public_encrypt(iVar7,from,to,rsa,(uint)local_34);
        }
        else {
          if (local_35 != 4) goto LAB_0805f2e6;
          iVar7 = RSA_private_decrypt(iVar7,from,to,rsa,(uint)local_34);
        }
        goto LAB_0805f0e9;
      }
      if (local_35 == 1) {
        iVar7 = RSA_private_encrypt(iVar7,from,to,rsa,(uint)local_34);
        goto LAB_0805f0e9;
      }
LAB_0805f2e6:
      uVar12 = 1;
      BIO_printf(bio_err,"RSA operation error\n");
      ERR_print_errors(bio_err);
    }
    RSA_free(rsa);
    BIO_free(b);
    BIO_free_all(local_48);
    if (from != (uchar *)0x0) {
      CRYPTO_free(from);
    }
    if (to != (uchar *)0x0) {
      CRYPTO_free(to);
    }
  }
  if (local_24 != (void *)0x0) {
    CRYPTO_free(local_24);
  }
LAB_0805eadd:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar12;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

