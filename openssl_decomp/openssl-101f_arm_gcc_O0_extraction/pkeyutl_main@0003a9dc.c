
BIO * pkeyutl_main(int param_1,int param_2)

{
  uchar uVar1;
  bool bVar2;
  int iVar3;
  BIO *a;
  size_t siglen;
  BIO *pBVar4;
  void *pvVar5;
  EVP_PKEY *peer;
  X509 *x;
  EVP_PKEY_CTX *pEVar6;
  BIO *pBVar7;
  uint uVar8;
  BIO *pBVar9;
  char **ppcVar10;
  char *pcVar11;
  char *filename;
  char *filename_00;
  uint uVar12;
  BIO *a_00;
  char **ppcVar13;
  uint local_68;
  char *local_64;
  int local_60;
  undefined4 local_5c;
  ENGINE *local_58;
  int local_54;
  char *local_50;
  undefined4 local_4c;
  BIO *local_48;
  BIO *local_40;
  uchar *local_34;
  uchar *local_30;
  void *local_2c [2];
  
  local_34 = (uchar *)0x0;
  local_30 = (uchar *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar3 = load_config(bio_err,0);
  if (iVar3 != 0) {
    param_1 = param_1 + -1;
    ERR_load_crypto_strings();
    OPENSSL_add_all_algorithms_noconf();
    if (0 < param_1) {
      filename_00 = (char *)0x0;
      a_00 = (BIO *)0x0;
      local_5c = 3;
      local_4c = 3;
      ppcVar13 = (char **)(param_2 + 4);
      local_54 = -1;
      local_48 = (BIO *)0x0;
      local_40 = (BIO *)0x0;
      filename = (char *)0x0;
      bVar2 = false;
      local_58 = (ENGINE *)0x0;
      local_64 = (char *)0x0;
      local_60 = 1;
      local_68 = 8;
      local_50 = (char *)0x0;
LAB_0003aaa2:
      pcVar11 = *ppcVar13;
      if ((((*pcVar11 == '-') && (pcVar11[1] == 'i')) && (pcVar11[2] == 'n')) &&
         (pcVar11[3] == '\0')) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          filename_00 = ppcVar13[1];
          ppcVar10 = ppcVar13 + 1;
          goto LAB_0003aa98;
        }
LAB_0003ad6c:
        a = (BIO *)0x0;
        usage();
        local_40 = (BIO *)0x1;
        pBVar9 = (BIO *)0x0;
        pBVar7 = (BIO *)0x0;
        if (a_00 != (BIO *)0x0) goto LAB_0003ad82;
        local_40 = (BIO *)0x1;
        pBVar9 = a_00;
        a = a_00;
        goto LAB_0003aa10;
      }
      iVar3 = strcmp(pcVar11,"-out");
      if (iVar3 == 0) {
        if (param_1 == 1) goto LAB_0003ad6c;
        param_1 = param_1 + -2;
        filename = ppcVar13[1];
        ppcVar13 = ppcVar13 + 2;
      }
      else {
        iVar3 = strcmp(pcVar11,"-sigfile");
        if (iVar3 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            local_64 = ppcVar13[1];
            ppcVar10 = ppcVar13 + 1;
            goto LAB_0003aa98;
          }
          goto LAB_0003ad6c;
        }
        pvVar5 = (void *)strcmp(pcVar11,"-inkey");
        if (pvVar5 == (void *)0x0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0003ad6c;
          pcVar11 = ppcVar13[1];
          local_2c[0] = pvVar5;
          if ((local_68 == 0x200 || local_68 == 8) || (local_68 == 0x400)) {
            if (local_60 != 1) {
              a_00 = (BIO *)0x0;
              BIO_printf(bio_err,"A private key is needed for this operation\n");
              goto LAB_0003ad44;
            }
            iVar3 = app_passwd(bio_err,local_50,0,local_2c,0);
            if (iVar3 != 0) {
LAB_0003ae4a:
              pBVar7 = (BIO *)load_key(bio_err,pcVar11,local_4c,0,local_2c[0],local_58,"Private Key"
                                      );
              goto LAB_0003ae6c;
            }
LAB_0003b2aa:
            a_00 = (BIO *)0x0;
            BIO_printf(bio_err,"Error getting password\n");
          }
          else {
            iVar3 = app_passwd(bio_err,local_50,0,local_2c,0);
            if (iVar3 == 0) goto LAB_0003b2aa;
            if (local_60 == 2) {
              pBVar7 = (BIO *)load_pubkey(bio_err,pcVar11,local_4c,0,0,local_58,"Public Key");
LAB_0003ae6c:
              local_54 = EVP_PKEY_size((EVP_PKEY *)pBVar7);
              a_00 = pBVar7;
              if (pBVar7 != (BIO *)0x0) {
                a_00 = (BIO *)EVP_PKEY_CTX_new((EVP_PKEY *)pBVar7,local_58);
                EVP_PKEY_free((EVP_PKEY *)pBVar7);
                if (a_00 != (BIO *)0x0) {
                  if (local_68 == 0x20) {
                    iVar3 = EVP_PKEY_verify_recover_init((EVP_PKEY_CTX *)a_00);
LAB_0003afa4:
                    if (0 < iVar3) goto LAB_0003ad44;
                  }
                  else {
                    if (0x20 < local_68) {
                      if (local_68 == 0x200) {
                        iVar3 = EVP_PKEY_decrypt_init((EVP_PKEY_CTX *)a_00);
                      }
                      else if (local_68 == 0x400) {
                        iVar3 = EVP_PKEY_derive_init((EVP_PKEY_CTX *)a_00);
                      }
                      else {
                        if (local_68 != 0x100) goto LAB_0003aeba;
                        iVar3 = EVP_PKEY_encrypt_init((EVP_PKEY_CTX *)a_00);
                      }
                      goto LAB_0003afa4;
                    }
                    if (local_68 == 8) {
                      iVar3 = EVP_PKEY_sign_init((EVP_PKEY_CTX *)a_00);
                      goto LAB_0003afa4;
                    }
                    if (local_68 == 0x10) {
                      iVar3 = EVP_PKEY_verify_init((EVP_PKEY_CTX *)a_00);
                      goto LAB_0003afa4;
                    }
                  }
LAB_0003aeba:
                  EVP_PKEY_CTX_free((EVP_PKEY_CTX *)a_00);
                  a_00 = (BIO *)0x0;
                }
              }
            }
            else {
              if (local_60 == 3) {
                x = (X509 *)load_cert(bio_err,pcVar11,local_4c,0,local_58,"Certificate");
                if (x != (X509 *)0x0) {
                  pBVar7 = (BIO *)X509_get_pubkey(x);
                  X509_free(x);
                  goto LAB_0003ae6c;
                }
              }
              else if (local_60 == 1) goto LAB_0003ae4a;
              local_54 = EVP_PKEY_size((EVP_PKEY *)0x0);
              a_00 = (BIO *)0x0;
            }
          }
LAB_0003ad44:
          if (local_2c[0] != (void *)0x0) {
            CRYPTO_free(local_2c[0]);
          }
          ppcVar10 = ppcVar13 + 1;
          if (a_00 == (BIO *)0x0) {
            BIO_puts(bio_err,"Error initializing context\n");
            ERR_print_errors(bio_err);
            goto LAB_0003ad6c;
          }
        }
        else {
          iVar3 = strcmp(pcVar11,"-peerkey");
          pBVar7 = bio_err;
          if (iVar3 == 0) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              ppcVar10 = ppcVar13 + 1;
              pcVar11 = ppcVar13[1];
              if (a_00 == (BIO *)0x0) {
                BIO_puts(bio_err,"-peerkey command before -inkey\n");
              }
              else {
                peer = (EVP_PKEY *)load_pubkey(bio_err,pcVar11,local_5c,0,0,0,"Peer Key");
                if (peer == (EVP_PKEY *)0x0) {
                  BIO_printf(bio_err,"Error reading peer key %s\n",pcVar11);
                  ERR_print_errors(pBVar7);
                }
                else {
                  iVar3 = EVP_PKEY_derive_set_peer((EVP_PKEY_CTX *)a_00,peer);
                  EVP_PKEY_free(peer);
                  if ((0 < iVar3) || (ERR_print_errors(pBVar7), iVar3 != 0)) goto LAB_0003aa98;
                }
              }
            }
            goto LAB_0003ad6c;
          }
          iVar3 = strcmp(pcVar11,"-passin");
          if (iVar3 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0003ad6c;
            local_50 = ppcVar13[1];
            ppcVar10 = ppcVar13 + 1;
          }
          else {
            iVar3 = strcmp(pcVar11,"-peerform");
            if (iVar3 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0003ad6c;
              ppcVar10 = ppcVar13 + 1;
              local_5c = str2fmt(ppcVar13[1]);
            }
            else {
              iVar3 = strcmp(pcVar11,"-keyform");
              if (iVar3 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_0003ad6c;
                local_4c = str2fmt(ppcVar13[1]);
                ppcVar10 = ppcVar13 + 1;
              }
              else {
                iVar3 = strcmp(pcVar11,"-engine");
                if (iVar3 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 == 0) goto LAB_0003ad6c;
                  local_58 = (ENGINE *)setup_engine(bio_err,ppcVar13[1],0);
                  ppcVar10 = ppcVar13 + 1;
                }
                else {
                  iVar3 = strcmp(pcVar11,"-pubin");
                  ppcVar10 = ppcVar13;
                  if (iVar3 == 0) {
                    local_60 = 2;
                  }
                  else {
                    iVar3 = strcmp(pcVar11,"-certin");
                    if (iVar3 == 0) {
                      local_60 = 3;
                    }
                    else {
                      iVar3 = strcmp(pcVar11,"-asn1parse");
                      if (iVar3 == 0) {
                        local_48 = (BIO *)0x1;
                      }
                      else {
                        iVar3 = strcmp(pcVar11,"-hexdump");
                        if (iVar3 == 0) {
                          local_40 = (BIO *)0x1;
                        }
                        else {
                          iVar3 = strcmp(pcVar11,"-sign");
                          if (iVar3 == 0) {
                            local_68 = 8;
                          }
                          else {
                            iVar3 = strcmp(pcVar11,"-verify");
                            if (iVar3 == 0) {
                              local_68 = 0x10;
                            }
                            else {
                              iVar3 = strcmp(pcVar11,"-verifyrecover");
                              if (iVar3 == 0) {
                                local_68 = 0x20;
                              }
                              else {
                                iVar3 = strcmp(pcVar11,"-rev");
                                if (iVar3 == 0) {
                                  bVar2 = true;
                                }
                                else {
                                  iVar3 = strcmp(pcVar11,"-encrypt");
                                  if (iVar3 == 0) {
                                    local_68 = 0x100;
                                  }
                                  else {
                                    iVar3 = strcmp(pcVar11,"-decrypt");
                                    if (iVar3 == 0) {
                                      local_68 = 0x200;
                                    }
                                    else {
                                      iVar3 = strcmp(pcVar11,"-derive");
                                      if (iVar3 != 0) {
                                        iVar3 = strcmp(pcVar11,"-pkeyopt");
                                        if ((iVar3 == 0) && (param_1 = param_1 + -1, param_1 != 0))
                                        {
                                          if (a_00 == (BIO *)0x0) {
                                            BIO_puts(bio_err,"-pkeyopt command before -inkey\n");
                                            goto LAB_0003ad6c;
                                          }
                                          iVar3 = pkey_ctrl_string(a_00,ppcVar13[1]);
                                          ppcVar10 = ppcVar13 + 1;
                                          if (0 < iVar3) goto LAB_0003aa98;
                                          a = (BIO *)0x0;
                                          BIO_puts(bio_err,"parameter setting error\n");
                                          ERR_print_errors(bio_err);
                                          pBVar9 = (BIO *)0x0;
                                          pBVar7 = (BIO *)0x0;
                                          local_40 = (BIO *)0x1;
                                          goto LAB_0003ad82;
                                        }
                                        goto LAB_0003ad6c;
                                      }
                                      local_68 = 0x400;
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
LAB_0003aa98:
        param_1 = param_1 + -1;
        ppcVar13 = ppcVar10 + 1;
      }
      if (param_1 < 1) goto LAB_0003aad8;
      goto LAB_0003aaa2;
    }
    goto LAB_0003b0fa;
  }
LAB_0003aa06:
  local_40 = (BIO *)0x1;
  a_00 = (BIO *)0x0;
  pBVar9 = (BIO *)0x0;
  a = (BIO *)0x0;
LAB_0003aa10:
  BIO_free(a_00);
  BIO_free_all(pBVar9);
  if (local_34 != (uchar *)0x0) {
    CRYPTO_free(local_34);
  }
  if (a != (BIO *)0x0) {
    CRYPTO_free(a);
  }
  if (local_30 != (uchar *)0x0) {
    CRYPTO_free(local_30);
  }
  return local_40;
LAB_0003aad8:
  if (a_00 != (BIO *)0x0) {
    pcVar11 = local_64;
    if (local_64 != (char *)0x0) {
      pcVar11 = (char *)0x1;
    }
    if (local_68 == 0x10) {
      pBVar7 = (BIO *)0x0;
    }
    else {
      pBVar7 = (BIO *)((uint)pcVar11 & 1);
    }
    if (pBVar7 == (BIO *)0x0) {
      uVar12 = count_leading_zeroes(local_68 - 0x10);
      if (local_64 == (char *)0x0) {
        pBVar9 = (BIO *)(uVar12 >> 5 & 1);
      }
      else {
        pBVar9 = (BIO *)0x0;
      }
      if (pBVar9 == (BIO *)0x0) {
        app_RAND_load_file(0,bio_err,0);
        pBVar7 = pBVar9;
        if (local_68 != 0x400) {
          if (filename_00 == (char *)0x0) {
            pBVar7 = BIO_new_fp(stdin,0);
          }
          else {
            pBVar7 = BIO_new_file(filename_00,"rb");
            if (pBVar7 == (BIO *)0x0) {
              local_40 = (BIO *)0x1;
              BIO_puts(bio_err,"Error Opening Input File\n");
              ERR_print_errors(bio_err);
              pBVar9 = pBVar7;
              a = pBVar7;
              goto LAB_0003ad82;
            }
          }
        }
        if (filename == (char *)0x0) {
          pBVar9 = BIO_new_fp(stdout,0);
        }
        else {
          pBVar9 = BIO_new_file(filename,"wb");
          if (pBVar9 == (BIO *)0x0) {
            local_40 = (BIO *)0x1;
            BIO_printf(bio_err,"Error Creating Output File\n");
            ERR_print_errors(bio_err);
            a = pBVar9;
            goto LAB_0003ad82;
          }
        }
        if (pcVar11 == (char *)0x0) {
          siglen = 0xffffffff;
LAB_0003abb4:
          pBVar4 = pBVar7;
          if (pBVar7 != (BIO *)0x0) {
            pBVar4 = (BIO *)bio_to_mem(&local_34,local_54 * 10,pBVar7);
            if ((int)pBVar4 < 1) {
              BIO_printf(bio_err,"Error reading input Data\n");
                    /* WARNING: Subroutine does not return */
              exit(1);
            }
            if (bVar2) {
              if ((uint)pBVar4 >> 1 == 0) {
                pBVar4 = (BIO *)0x1;
              }
              else {
                uVar8 = 0;
                do {
                  pEVar6 = (EVP_PKEY_CTX *)((int)pBVar4 + (-1 - uVar8));
                  uVar1 = local_34[uVar8];
                  local_34[uVar8] = local_34[(int)pEVar6];
                  uVar8 = uVar8 + 1;
                  local_34[(int)pEVar6] = uVar1;
                } while (uVar8 != (uint)pBVar4 >> 1);
              }
            }
          }
          if (uVar12 >> 5 == 0) {
            if (local_68 == 0x100) {
              iVar3 = EVP_PKEY_encrypt((EVP_PKEY_CTX *)a_00,(uchar *)0x0,(size_t *)local_2c,local_34
                                       ,(size_t)pBVar4);
LAB_0003ac36:
              if ((iVar3 < 1) ||
                 (a = (BIO *)CRYPTO_malloc((int)local_2c[0],"pkeyutl.c",0x15b), a == (BIO *)0x0))
              goto LAB_0003b048;
              if (local_68 == 0x100) {
                iVar3 = EVP_PKEY_encrypt((EVP_PKEY_CTX *)a_00,(uchar *)a,(size_t *)local_2c,local_34
                                         ,(size_t)pBVar4);
LAB_0003ac80:
                if (0 < iVar3) {
                  if (local_48 == (BIO *)0x0) {
                    if (local_40 == (BIO *)0x0) {
                      BIO_write(pBVar9,a,(int)local_2c[0]);
                    }
                    else {
                      BIO_dump(pBVar9,(char *)a,(int)local_2c[0]);
                      local_40 = local_48;
                    }
                  }
                  else {
                    pBVar4 = (BIO *)ASN1_parse_dump(pBVar9,(uchar *)a,(long)local_2c[0],1,-1);
                    local_40 = (BIO *)0x0;
                    if (pBVar4 == (BIO *)0x0) {
                      ERR_print_errors(bio_err);
                      local_40 = pBVar4;
                    }
                  }
                  goto LAB_0003ad82;
                }
              }
              else {
                if (0x100 < local_68) {
                  if (local_68 == 0x200) {
                    iVar3 = EVP_PKEY_decrypt((EVP_PKEY_CTX *)a_00,(uchar *)a,(size_t *)local_2c,
                                             local_34,(size_t)pBVar4);
                  }
                  else {
                    if (local_68 != 0x400) goto LAB_0003b04a;
                    iVar3 = EVP_PKEY_derive((EVP_PKEY_CTX *)a_00,(uchar *)a,(size_t *)local_2c);
                  }
                  goto LAB_0003ac80;
                }
                if (local_68 == 8) {
                  iVar3 = EVP_PKEY_sign((EVP_PKEY_CTX *)a_00,(uchar *)a,(size_t *)local_2c,local_34,
                                        (size_t)pBVar4);
                  goto LAB_0003ac80;
                }
                if (local_68 == 0x20) {
                  iVar3 = EVP_PKEY_verify_recover
                                    ((EVP_PKEY_CTX *)a_00,(uchar *)a,(size_t *)local_2c,local_34,
                                     (size_t)pBVar4);
                  goto LAB_0003ac80;
                }
              }
            }
            else {
              if (0x100 < local_68) {
                if (local_68 == 0x200) {
                  iVar3 = EVP_PKEY_decrypt((EVP_PKEY_CTX *)a_00,(uchar *)0x0,(size_t *)local_2c,
                                           local_34,(size_t)pBVar4);
                }
                else {
                  if (local_68 != 0x400) goto LAB_0003b048;
                  iVar3 = EVP_PKEY_derive((EVP_PKEY_CTX *)a_00,(uchar *)0x0,(size_t *)local_2c);
                }
                goto LAB_0003ac36;
              }
              if (local_68 == 8) {
                iVar3 = EVP_PKEY_sign((EVP_PKEY_CTX *)a_00,(uchar *)0x0,(size_t *)local_2c,local_34,
                                      (size_t)pBVar4);
                goto LAB_0003ac36;
              }
              if (local_68 == 0x20) {
                iVar3 = EVP_PKEY_verify_recover
                                  ((EVP_PKEY_CTX *)a_00,(uchar *)0x0,(size_t *)local_2c,local_34,
                                   (size_t)pBVar4);
                goto LAB_0003ac36;
              }
LAB_0003b048:
              a = (BIO *)0x0;
            }
LAB_0003b04a:
            BIO_printf(bio_err,"Public Key operation error\n");
            ERR_print_errors(bio_err);
            local_40 = (BIO *)0x1;
          }
          else {
            pBVar4 = (BIO *)EVP_PKEY_verify((EVP_PKEY_CTX *)a_00,local_30,siglen,local_34,
                                            (size_t)pBVar4);
            if (pBVar4 == (BIO *)0x0) {
              local_40 = (BIO *)0x1;
              BIO_puts(pBVar9,"Signature Verification Failure\n");
              a = pBVar4;
            }
            else if (pBVar4 == (BIO *)0x1) {
              BIO_puts(pBVar9,"Signature Verified Successfully\n");
              a = (BIO *)0x0;
              local_40 = pBVar4;
            }
            else {
              if ((int)pBVar4 < 0) goto LAB_0003b048;
              a = (BIO *)0x0;
              local_40 = (BIO *)0x1;
            }
          }
        }
        else {
          a = BIO_new_file(local_64,"rb");
          if (a == (BIO *)0x0) {
            BIO_printf(bio_err,"Can\'t open signature file %s\n",local_64);
            local_40 = (BIO *)0x1;
          }
          else {
            siglen = bio_to_mem(&local_30,local_54 * 10,a);
            BIO_free(a);
            if (0 < (int)siglen) goto LAB_0003abb4;
            local_40 = (BIO *)0x1;
            BIO_printf(bio_err,"Error reading signature data\n");
            a = (BIO *)0x0;
          }
        }
      }
      else {
        BIO_puts(bio_err,"No signature file specified for verify\n");
        local_40 = (BIO *)0x1;
        pBVar9 = pBVar7;
        a = pBVar7;
      }
    }
    else {
      a = (BIO *)0x0;
      BIO_puts(bio_err,"Signature file specified for non verify\n");
      pBVar9 = (BIO *)0x0;
      pBVar7 = (BIO *)0x0;
      local_40 = (BIO *)0x1;
    }
LAB_0003ad82:
    EVP_PKEY_CTX_free((EVP_PKEY_CTX *)a_00);
    a_00 = pBVar7;
    goto LAB_0003aa10;
  }
LAB_0003b0fa:
  usage();
  goto LAB_0003aa06;
}

