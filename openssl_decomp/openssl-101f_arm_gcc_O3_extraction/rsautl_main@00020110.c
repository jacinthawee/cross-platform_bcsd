
int rsautl_main(int param_1,int param_2)

{
  char **ppcVar1;
  uchar uVar2;
  bool bVar3;
  bool bVar4;
  rsa_st *rsa;
  int iVar5;
  undefined4 uVar6;
  rsa_st *b;
  BIO *bp;
  uchar *from;
  uchar *to;
  EVP_PKEY *pkey;
  X509 *x;
  uchar *puVar7;
  uchar *puVar8;
  uchar *puVar9;
  char *filename;
  char *__s1;
  char *pcVar10;
  int iVar11;
  char **ppcVar12;
  char *pcVar13;
  char *local_54;
  int local_50;
  char *local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  int local_34;
  void *local_2c [2];
  
  local_2c[0] = (void *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  rsa = (rsa_st *)load_config(bio_err,0);
  b = rsa;
  if (rsa == (rsa_st *)0x0) {
LAB_00020206:
    local_3c = 1;
    RSA_free(rsa);
    BIO_free((BIO *)b);
    BIO_free_all((BIO *)0x0);
    goto LAB_0002021c;
  }
  param_1 = param_1 + -1;
  ERR_load_crypto_strings();
  OPENSSL_add_all_algorithms_noconf();
  if (param_1 < 1) {
    pcVar13 = (char *)0x0;
    iVar11 = 1;
    pcVar10 = (char *)0x0;
    filename = (char *)0x0;
    local_3c = 0;
    local_34 = 0;
    bVar4 = false;
    local_48 = (char *)0x0;
    local_54 = (char *)0x0;
    local_50 = 1;
    local_44 = 3;
    local_40 = 2;
  }
  else {
    ppcVar12 = (char **)(param_2 + 4);
    local_40 = 2;
    iVar11 = 1;
    local_3c = 0;
    pcVar10 = (char *)0x0;
    local_34 = 0;
    filename = (char *)0x0;
    bVar4 = false;
    bVar3 = false;
    pcVar13 = (char *)0x0;
    local_48 = (char *)0x0;
    local_54 = (char *)0x0;
    local_50 = 1;
    local_44 = 3;
LAB_000201a4:
    do {
      __s1 = *ppcVar12;
      if ((((*__s1 == '-') && (__s1[1] == 'i')) && (__s1[2] == 'n')) && (__s1[3] == '\0')) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          filename = ppcVar12[1];
          ppcVar12 = ppcVar12 + 1;
          goto LAB_00020198;
        }
LAB_000202a8:
        rsa = (RSA *)0x0;
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
        BIO_printf(bio_err,"-passin arg    pass phrase source\n");
        b = (rsa_st *)0x0;
        goto LAB_00020206;
      }
      iVar5 = strcmp(__s1,"-out");
      if (iVar5 != 0) {
        iVar5 = strcmp(__s1,"-inkey");
        if (iVar5 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_000202a8;
          pcVar10 = ppcVar12[1];
          ppcVar12 = ppcVar12 + 1;
        }
        else {
          iVar5 = strcmp(__s1,"-passin");
          if (iVar5 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_000202a8;
            pcVar13 = ppcVar12[1];
            ppcVar12 = ppcVar12 + 1;
          }
          else {
            iVar5 = strcmp(__s1,"-keyform");
            if (iVar5 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_000202a8;
              ppcVar1 = ppcVar12 + 1;
              ppcVar12 = ppcVar12 + 1;
              local_44 = str2fmt(*ppcVar1);
            }
            else {
              iVar5 = strcmp(__s1,"-engine");
              if (iVar5 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_000202a8;
                local_48 = ppcVar12[1];
                ppcVar12 = ppcVar12 + 1;
              }
              else {
                iVar5 = strcmp(__s1,"-pubin");
                if (iVar5 == 0) {
                  local_50 = 2;
                }
                else {
                  iVar5 = strcmp(__s1,"-certin");
                  if (iVar5 == 0) {
                    local_50 = 3;
                  }
                  else {
                    iVar5 = strcmp(__s1,"-asn1parse");
                    if (iVar5 == 0) {
                      local_3c = 1;
                    }
                    else {
                      iVar5 = strcmp(__s1,"-hexdump");
                      if (iVar5 == 0) {
                        local_34 = 1;
                      }
                      else {
                        iVar5 = strcmp(__s1,"-raw");
                        if (iVar5 == 0) {
                          iVar11 = 3;
                        }
                        else {
                          iVar5 = strcmp(__s1,"-oaep");
                          if (iVar5 == 0) {
                            iVar11 = 4;
                          }
                          else {
                            iVar5 = strcmp(__s1,"-ssl");
                            if (iVar5 == 0) {
                              iVar11 = 2;
                            }
                            else {
                              iVar5 = strcmp(__s1,"-pkcs");
                              if (iVar5 == 0) {
                                iVar11 = 1;
                              }
                              else {
                                iVar5 = strcmp(__s1,"-x931");
                                if (iVar5 == 0) {
                                  iVar11 = 5;
                                }
                                else {
                                  iVar5 = strcmp(__s1,"-sign");
                                  if (iVar5 == 0) {
                                    bVar3 = true;
                                    local_40 = 1;
                                  }
                                  else {
                                    iVar5 = strcmp(__s1,"-verify");
                                    if (iVar5 == 0) {
                                      local_40 = 2;
                                    }
                                    else {
                                      iVar5 = strcmp(__s1,"-rev");
                                      if (iVar5 == 0) {
                                        bVar4 = true;
                                      }
                                      else {
                                        iVar5 = strcmp(__s1,"-encrypt");
                                        if (iVar5 == 0) {
                                          local_40 = 3;
                                        }
                                        else {
                                          iVar5 = strcmp(__s1,"-decrypt");
                                          if (iVar5 != 0) goto LAB_000202a8;
                                          bVar3 = true;
                                          local_40 = 4;
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
LAB_00020198:
        param_1 = param_1 + -1;
        ppcVar12 = ppcVar12 + 1;
        if (param_1 < 1) break;
        goto LAB_000201a4;
      }
      if (param_1 == 1) goto LAB_000202a8;
      param_1 = param_1 + -2;
      local_54 = ppcVar12[1];
      ppcVar12 = ppcVar12 + 2;
    } while (0 < param_1);
    if (local_50 == 1) {
      bVar3 = false;
    }
    if (bVar3) {
      rsa = (RSA *)0x0;
      BIO_printf(bio_err,"A private key is needed for this operation\n");
      b = (rsa_st *)0x0;
      goto LAB_00020206;
    }
  }
  uVar6 = setup_engine(bio_err,local_48);
  rsa = (rsa_st *)app_passwd(bio_err,pcVar13,0,local_2c,0);
  if (rsa == (rsa_st *)0x0) {
    BIO_printf(bio_err,"Error getting password\n");
    b = rsa;
    goto LAB_00020206;
  }
  app_RAND_load_file(0,bio_err,0);
  if (local_50 == 2) {
    pkey = (EVP_PKEY *)load_pubkey(bio_err,pcVar10,local_44,0,0,uVar6,"Public Key");
  }
  else if (local_50 == 3) {
    x = (X509 *)load_cert(bio_err,pcVar10,local_44,0,uVar6,"Certificate");
    if (x == (X509 *)0x0) {
      return 1;
    }
    pkey = X509_get_pubkey(x);
    X509_free(x);
  }
  else {
    if (local_50 != 1) {
      return 1;
    }
    pkey = (EVP_PKEY *)load_key(bio_err,pcVar10,local_44,0,local_2c[0],uVar6,"Private Key");
  }
  if (pkey == (EVP_PKEY *)0x0) {
    return 1;
  }
  rsa = EVP_PKEY_get1_RSA(pkey);
  EVP_PKEY_free(pkey);
  if (rsa == (rsa_st *)0x0) {
    BIO_printf(bio_err,"Error getting RSA key\n");
    ERR_print_errors(bio_err);
    b = rsa;
    goto LAB_00020206;
  }
  if (filename == (char *)0x0) {
    b = (rsa_st *)BIO_new_fp(stdin,0);
  }
  else {
    b = (rsa_st *)BIO_new_file(filename,"rb");
    if (b == (rsa_st *)0x0) {
      BIO_printf(bio_err,"Error Reading Input File\n");
      ERR_print_errors(bio_err);
      goto LAB_00020206;
    }
  }
  if (local_54 == (char *)0x0) {
    bp = BIO_new_fp(stdout,0);
  }
  else {
    bp = BIO_new_file(local_54,"wb");
    if (bp == (BIO *)0x0) {
      BIO_printf(bio_err,"Error Reading Output File\n");
      ERR_print_errors(bio_err);
      goto LAB_00020206;
    }
  }
  iVar5 = RSA_size(rsa);
  from = (uchar *)CRYPTO_malloc(iVar5 << 1,"rsautl.c",0x104);
  to = (uchar *)CRYPTO_malloc(iVar5,"rsautl.c",0x105);
  iVar5 = BIO_read((BIO *)b,from,iVar5 << 1);
  if (iVar5 < 1) {
    BIO_printf(bio_err,"Error reading input Data\n");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if ((bVar4) && (iVar5 >> 1 != 0)) {
    puVar7 = from + iVar5;
    puVar8 = from;
    do {
      uVar2 = *puVar8;
      puVar9 = puVar8 + 1;
      *puVar8 = puVar7[-1];
      puVar7 = puVar7 + -1;
      *puVar7 = uVar2;
      puVar8 = puVar9;
    } while (puVar9 != from + (iVar5 >> 1));
  }
  switch(local_40) {
  case 1:
    iVar11 = RSA_private_encrypt(iVar5,from,to,rsa,iVar11);
    break;
  case 2:
    iVar11 = RSA_public_decrypt(iVar5,from,to,rsa,iVar11);
    break;
  case 3:
    iVar11 = RSA_public_encrypt(iVar5,from,to,rsa,iVar11);
    break;
  case 4:
    iVar11 = RSA_private_decrypt(iVar5,from,to,rsa,iVar11);
    break;
  default:
    goto switchD_0002064c_caseD_4;
  }
  if (iVar11 < 1) {
switchD_0002064c_caseD_4:
    BIO_printf(bio_err,"RSA operation error\n");
    ERR_print_errors(bio_err);
    local_3c = 1;
  }
  else if (local_3c == 0) {
    if (local_34 == 0) {
      BIO_write(bp,to,iVar11);
      local_3c = local_34;
    }
    else {
      BIO_dump(bp,(char *)to,iVar11);
    }
  }
  else {
    iVar11 = ASN1_parse_dump(bp,to,iVar11,1,-1);
    local_3c = 0;
    if (iVar11 == 0) {
      ERR_print_errors(bio_err);
      local_3c = iVar11;
    }
  }
  RSA_free(rsa);
  BIO_free((BIO *)b);
  BIO_free_all(bp);
  if (from != (uchar *)0x0) {
    CRYPTO_free(from);
  }
  if (to != (uchar *)0x0) {
    CRYPTO_free(to);
  }
LAB_0002021c:
  if (local_2c[0] == (void *)0x0) {
    return local_3c;
  }
  CRYPTO_free(local_2c[0]);
  return local_3c;
}

