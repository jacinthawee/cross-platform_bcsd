
undefined4 pkeyutl_main(int param_1,int param_2)

{
  char **ppcVar1;
  uchar *puVar2;
  uchar uVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  X509 *x;
  EVP_PKEY *pEVar8;
  uint uVar9;
  char **ppcVar10;
  BIO *pBVar11;
  BIO *a;
  char *pcVar12;
  undefined4 uVar13;
  char *pcVar14;
  uint tbslen;
  int in_GS_OFFSET;
  bool bVar15;
  byte bVar16;
  undefined8 uVar17;
  BIO *bp;
  char *pcVar18;
  char *local_60;
  EVP_PKEY_CTX *local_5c;
  char *local_58;
  char *local_54;
  uint local_50;
  ENGINE *local_4c;
  int local_48;
  char *local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uchar *local_2c;
  uchar *local_28;
  void *local_24;
  int local_20;
  
  bVar16 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = (uchar *)0x0;
  local_28 = (uchar *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar7 = load_config(bio_err,0);
  if (iVar7 != 0) {
    param_1 = param_1 + -1;
    ERR_load_crypto_strings();
    OPENSSL_add_all_algorithms_noconf();
    if (0 < param_1) {
      ppcVar10 = (char **)(param_2 + 4);
      local_40 = -1;
      local_44 = (char *)0x0;
      local_5c = (EVP_PKEY_CTX *)0x0;
      bVar5 = false;
      bVar6 = false;
      bVar4 = false;
      local_38 = 3;
      local_3c = 3;
      local_48 = 1;
      local_50 = 8;
      local_4c = (ENGINE *)0x0;
      local_54 = (char *)0x0;
      local_58 = (char *)0x0;
      local_60 = (char *)0x0;
LAB_08085b7f:
      pBVar11 = bio_err;
      pcVar18 = *ppcVar10;
      bVar15 = *pcVar18 == '-';
      if ((((bVar15) && (bVar15 = pcVar18[1] == 'i', bVar15)) &&
          (bVar15 = pcVar18[2] == 'n', bVar15)) && (bVar15 = pcVar18[3] == '\0', bVar15)) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          local_60 = ppcVar10[1];
          ppcVar10 = ppcVar10 + 1;
          goto LAB_08085b75;
        }
LAB_08085e80:
        usage();
        if (local_5c == (EVP_PKEY_CTX *)0x0) goto LAB_08085a46;
        bp = (BIO *)0x0;
        pBVar11 = (BIO *)0x0;
        goto LAB_08085e95;
      }
      iVar7 = 5;
      pcVar12 = pcVar18;
      pcVar14 = "-out";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar15 = *pcVar12 == *pcVar14;
        pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
        pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
      } while (bVar15);
      if (bVar15) {
        if (param_1 == 1) goto LAB_08085e80;
        local_58 = ppcVar10[1];
        param_1 = param_1 + -2;
        ppcVar10 = ppcVar10 + 2;
joined_r0x08085b7d:
        if (param_1 < 1) goto LAB_08085bb8;
        goto LAB_08085b7f;
      }
      iVar7 = 9;
      pcVar12 = pcVar18;
      pcVar14 = "-sigfile";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar15 = *pcVar12 == *pcVar14;
        pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
        pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
      } while (bVar15);
      if (bVar15) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          local_54 = ppcVar10[1];
          ppcVar10 = ppcVar10 + 1;
          goto LAB_08085b75;
        }
        goto LAB_08085e80;
      }
      iVar7 = 7;
      pcVar12 = pcVar18;
      pcVar14 = "-inkey";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar15 = *pcVar12 == *pcVar14;
        pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
        pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
      } while (bVar15);
      if (bVar15) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_08085e80;
        ppcVar1 = ppcVar10 + 1;
        local_24 = (void *)0x0;
        pcVar18 = ppcVar10[1];
        if (((local_50 - 0x200 & 0xfffffdf8) == 0) || (local_50 == 8)) {
          if (local_48 != 1) {
            BIO_printf(bio_err,"A private key is needed for this operation\n");
            goto joined_r0x08085f35;
          }
          iVar7 = app_passwd(bio_err,local_44,0,&local_24,0);
          if (iVar7 != 0) {
LAB_0808632f:
            pEVar8 = (EVP_PKEY *)
                     load_key(bio_err,pcVar18,local_3c,0,local_24,local_4c,"Private Key");
            goto LAB_08085d47;
          }
LAB_08085f19:
          BIO_printf(bio_err,"Error getting password\n");
        }
        else {
          iVar7 = app_passwd(bio_err,local_44,0,&local_24,0);
          if (iVar7 == 0) goto LAB_08085f19;
          if (local_48 == 2) {
            pEVar8 = (EVP_PKEY *)load_pubkey(bio_err,pcVar18,local_3c,0,0,local_4c,"Public Key");
LAB_08085d47:
            local_40 = EVP_PKEY_size(pEVar8);
            if (pEVar8 != (EVP_PKEY *)0x0) {
              local_5c = EVP_PKEY_CTX_new(pEVar8,local_4c);
              EVP_PKEY_free(pEVar8);
              if (local_5c != (EVP_PKEY_CTX *)0x0) {
                if (local_50 == 0x20) {
                  iVar7 = EVP_PKEY_verify_recover_init(local_5c);
LAB_080862d0:
                  if (0 < iVar7) {
                    ppcVar10 = ppcVar1;
                    if (local_24 != (void *)0x0) {
                      CRYPTO_free(local_24);
                    }
                    goto LAB_08085b75;
                  }
                }
                else {
                  if (0x20 < local_50) {
                    if (local_50 == 0x200) {
                      iVar7 = EVP_PKEY_decrypt_init(local_5c);
                    }
                    else if (local_50 == 0x400) {
                      iVar7 = EVP_PKEY_derive_init(local_5c);
                    }
                    else {
                      if (local_50 != 0x100) goto LAB_08085dc1;
                      iVar7 = EVP_PKEY_encrypt_init(local_5c);
                    }
                    goto LAB_080862d0;
                  }
                  if (local_50 == 8) {
                    iVar7 = EVP_PKEY_sign_init(local_5c);
                    goto LAB_080862d0;
                  }
                  if (local_50 == 0x10) {
                    iVar7 = EVP_PKEY_verify_init(local_5c);
                    goto LAB_080862d0;
                  }
                }
LAB_08085dc1:
                EVP_PKEY_CTX_free(local_5c);
              }
            }
          }
          else {
            if (local_48 == 3) {
              x = (X509 *)load_cert(bio_err,pcVar18,local_3c,0,local_4c,"Certificate");
              if (x != (X509 *)0x0) {
                pEVar8 = X509_get_pubkey(x);
                X509_free(x);
                goto LAB_08085d47;
              }
            }
            else if (local_48 == 1) goto LAB_0808632f;
            EVP_PKEY_size((EVP_PKEY *)0x0);
          }
        }
joined_r0x08085f35:
        if (local_24 != (void *)0x0) {
          CRYPTO_free(local_24);
        }
        BIO_puts(bio_err,"Error initializing context\n");
        ERR_print_errors(bio_err);
        local_5c = (EVP_PKEY_CTX *)0x0;
        goto LAB_08085e80;
      }
      iVar7 = 9;
      pcVar12 = pcVar18;
      pcVar14 = "-peerkey";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar15 = *pcVar12 == *pcVar14;
        pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
        pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
      } while (bVar15);
      if (bVar15) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          ppcVar1 = ppcVar10 + 1;
          pcVar18 = ppcVar10[1];
          if (local_5c == (EVP_PKEY_CTX *)0x0) {
            BIO_puts(bio_err,"-peerkey command before -inkey\n");
          }
          else {
            pEVar8 = (EVP_PKEY *)load_pubkey(bio_err,pcVar18,local_38,0,0,0,"Peer Key");
            if (pEVar8 == (EVP_PKEY *)0x0) {
              BIO_printf(bio_err,"Error reading peer key %s\n",pcVar18);
              ERR_print_errors(pBVar11);
            }
            else {
              iVar7 = EVP_PKEY_derive_set_peer(local_5c,pEVar8);
              EVP_PKEY_free(pEVar8);
              ppcVar10 = ppcVar1;
              if ((0 < iVar7) || (ERR_print_errors(pBVar11), iVar7 != 0)) goto LAB_08085b75;
            }
          }
        }
        goto LAB_08085e80;
      }
      iVar7 = 8;
      pcVar12 = pcVar18;
      pcVar14 = "-passin";
      do {
        if (iVar7 == 0) break;
        iVar7 = iVar7 + -1;
        bVar15 = *pcVar12 == *pcVar14;
        pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
        pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
      } while (bVar15);
      if (bVar15) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_08085e80;
        local_44 = ppcVar10[1];
        ppcVar10 = ppcVar10 + 1;
      }
      else {
        iVar7 = 10;
        pcVar12 = pcVar18;
        pcVar14 = "-peerform";
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar15 = *pcVar12 == *pcVar14;
          pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
          pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
        } while (bVar15);
        if (bVar15) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_08085e80;
          ppcVar1 = ppcVar10 + 1;
          ppcVar10 = ppcVar10 + 1;
          local_38 = str2fmt(*ppcVar1);
        }
        else {
          iVar7 = 9;
          pcVar12 = pcVar18;
          pcVar14 = "-keyform";
          do {
            if (iVar7 == 0) break;
            iVar7 = iVar7 + -1;
            bVar15 = *pcVar12 == *pcVar14;
            pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
            pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
          } while (bVar15);
          if (bVar15) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_08085e80;
            local_3c = str2fmt(ppcVar10[1]);
            ppcVar10 = ppcVar10 + 1;
          }
          else {
            iVar7 = 8;
            pcVar12 = pcVar18;
            pcVar14 = "-engine";
            do {
              if (iVar7 == 0) break;
              iVar7 = iVar7 + -1;
              bVar15 = *pcVar12 == *pcVar14;
              pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
              pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
            } while (bVar15);
            if (bVar15) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_08085e80;
              local_4c = (ENGINE *)setup_engine(bio_err,ppcVar10[1],0);
              ppcVar10 = ppcVar10 + 1;
            }
            else {
              iVar7 = 7;
              pcVar12 = pcVar18;
              pcVar14 = "-pubin";
              do {
                if (iVar7 == 0) break;
                iVar7 = iVar7 + -1;
                bVar15 = *pcVar12 == *pcVar14;
                pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
                pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
              } while (bVar15);
              if (bVar15) {
                local_48 = 2;
              }
              else {
                iVar7 = 8;
                pcVar12 = pcVar18;
                pcVar14 = "-certin";
                do {
                  if (iVar7 == 0) break;
                  iVar7 = iVar7 + -1;
                  bVar15 = *pcVar12 == *pcVar14;
                  pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
                  pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                } while (bVar15);
                if (bVar15) {
                  local_48 = 3;
                }
                else {
                  iVar7 = 0xb;
                  pcVar12 = pcVar18;
                  pcVar14 = "-asn1parse";
                  do {
                    if (iVar7 == 0) break;
                    iVar7 = iVar7 + -1;
                    bVar15 = *pcVar12 == *pcVar14;
                    pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
                    pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                  } while (bVar15);
                  if (bVar15) {
                    bVar5 = true;
                  }
                  else {
                    iVar7 = 9;
                    pcVar12 = pcVar18;
                    pcVar14 = "-hexdump";
                    do {
                      if (iVar7 == 0) break;
                      iVar7 = iVar7 + -1;
                      bVar15 = *pcVar12 == *pcVar14;
                      pcVar12 = pcVar12 + (uint)bVar16 * -2 + 1;
                      pcVar14 = pcVar14 + (uint)bVar16 * -2 + 1;
                    } while (bVar15);
                    if (bVar15) {
                      bVar6 = true;
                    }
                    else {
                      iVar7 = strcmp(pcVar18,"-sign");
                      if (iVar7 == 0) {
                        local_50 = 8;
                      }
                      else {
                        iVar7 = strcmp(pcVar18,"-verify");
                        if (iVar7 == 0) {
                          local_50 = 0x10;
                        }
                        else {
                          iVar7 = strcmp(pcVar18,"-verifyrecover");
                          if (iVar7 == 0) {
                            local_50 = 0x20;
                          }
                          else {
                            iVar7 = strcmp(pcVar18,"-rev");
                            if (iVar7 == 0) {
                              bVar4 = true;
                            }
                            else {
                              iVar7 = strcmp(pcVar18,"-encrypt");
                              if (iVar7 == 0) {
                                local_50 = 0x100;
                              }
                              else {
                                iVar7 = strcmp(pcVar18,"-decrypt");
                                if (iVar7 == 0) {
                                  local_50 = 0x200;
                                }
                                else {
                                  iVar7 = strcmp(pcVar18,"-derive");
                                  if (iVar7 != 0) {
                                    iVar7 = strcmp(pcVar18,"-pkeyopt");
                                    if ((iVar7 == 0) && (param_1 = param_1 + -1, param_1 != 0)) {
                                      if (local_5c == (EVP_PKEY_CTX *)0x0) {
                                        BIO_puts(bio_err,"-pkeyopt command before -inkey\n");
                                        goto LAB_08085e80;
                                      }
                                      iVar7 = pkey_ctrl_string(local_5c,ppcVar10[1],0,0);
                                      ppcVar10 = ppcVar10 + 1;
                                      if (0 < iVar7) goto LAB_08085b75;
                                      BIO_puts(bio_err,"parameter setting error\n");
                                      ERR_print_errors(bio_err);
                                      goto LAB_08085c01;
                                    }
                                    goto LAB_08085e80;
                                  }
                                  local_50 = 0x400;
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
LAB_08085b75:
      param_1 = param_1 + -1;
      ppcVar10 = ppcVar10 + 1;
      goto joined_r0x08085b7d;
    }
    goto LAB_08086511;
  }
LAB_08085a46:
  BIO_free((BIO *)0x0);
  bp = (BIO *)0x0;
LAB_08085a57:
  BIO_free_all(bp);
  a = (BIO *)0x0;
  uVar13 = 1;
  if (local_2c == (uchar *)0x0) goto LAB_08085a8a;
LAB_08085a6e:
  CRYPTO_free(local_2c);
LAB_08085a7a:
  if (a != (BIO *)0x0) {
    CRYPTO_free(a);
  }
LAB_08085a8a:
  if (local_28 != (uchar *)0x0) {
    CRYPTO_free(local_28);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar13;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_08085bb8:
  if (local_5c == (EVP_PKEY_CTX *)0x0) {
LAB_08086511:
    usage();
    goto LAB_08085a46;
  }
  if ((local_54 == (char *)0x0) || (local_50 == 0x10)) {
    if ((local_54 == (char *)0x0) && (local_50 == 0x10)) {
      pcVar18 = "No signature file specified for verify\n";
      goto LAB_08085bf6;
    }
    app_RAND_load_file(0,bio_err,0);
    if (local_50 != 0x400) {
      if (local_60 == (char *)0x0) {
        pBVar11 = BIO_new_fp(stdin,0);
        goto LAB_0808609a;
      }
      pBVar11 = BIO_new_file(local_60,"rb");
      if (pBVar11 != (BIO *)0x0) goto LAB_0808609a;
      uVar13 = 1;
      bp = (BIO *)0x0;
      BIO_puts(bio_err,"Error Opening Input File\n");
      a = (BIO *)0x0;
      ERR_print_errors(bio_err);
      goto LAB_08085c0f;
    }
    pBVar11 = (BIO *)0x0;
LAB_0808609a:
    if (local_58 == (char *)0x0) {
      bp = BIO_new_fp(stdout,0);
    }
    else {
      bp = BIO_new_file(local_58,"wb");
      if (bp == (BIO *)0x0) {
        uVar13 = 1;
        a = (BIO *)0x0;
        BIO_printf(bio_err,"Error Creating Output File\n");
        ERR_print_errors(bio_err);
        goto LAB_08085c0f;
      }
    }
    if (local_54 != (char *)0x0) {
      a = BIO_new_file(local_54,"rb");
      if (a == (BIO *)0x0) {
        uVar13 = 1;
        BIO_printf(bio_err,"Can\'t open signature file %s\n",local_54);
      }
      else {
        local_58 = (char *)bio_to_mem(&local_28,local_40 * 10,a);
        BIO_free(a);
        if (0 < (int)local_58) goto LAB_08086119;
        uVar13 = 1;
        a = (BIO *)0x0;
        BIO_printf(bio_err,"Error reading signature data\n");
      }
      goto LAB_08085c0f;
    }
    local_58 = (char *)0xffffffff;
LAB_08086119:
    if (pBVar11 == (BIO *)0x0) {
      tbslen = 0;
    }
    else {
      uVar17 = bio_to_mem(&local_2c,local_40 * 10,pBVar11);
      uVar13 = (undefined4)((ulonglong)uVar17 >> 0x20);
      tbslen = (uint)uVar17;
      if ((int)tbslen < 1) {
        BIO_printf(bio_err,"Error reading input Data\n",uVar13,uVar13);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      if (bVar4) {
        if (tbslen >> 1 == 0) {
          tbslen = 1;
        }
        else {
          uVar9 = 0;
          do {
            iVar7 = (tbslen - 1) - uVar9;
            puVar2 = local_2c + uVar9;
            uVar9 = uVar9 + 1;
            uVar3 = *puVar2;
            *puVar2 = local_2c[iVar7];
            local_2c[iVar7] = uVar3;
          } while (uVar9 != tbslen >> 1);
        }
      }
    }
    if (local_50 != 0x10) {
      if (local_50 == 0x100) {
        iVar7 = EVP_PKEY_encrypt(local_5c,(uchar *)0x0,(size_t *)&local_24,local_2c,tbslen);
LAB_080861f7:
        if ((iVar7 < 1) ||
           (a = (BIO *)CRYPTO_malloc((int)local_24,"pkeyutl.c",0x136), a == (BIO *)0x0))
        goto LAB_0808639f;
        if (local_50 == 0x100) {
          iVar7 = EVP_PKEY_encrypt(local_5c,(uchar *)a,(size_t *)&local_24,local_2c,tbslen);
LAB_08086269:
          if (0 < iVar7) {
            if (bVar5) {
              uVar13 = 0;
              iVar7 = ASN1_parse_dump(bp,(uchar *)a,(long)local_24,1,-1);
              if (iVar7 == 0) {
                ERR_print_errors(bio_err);
              }
            }
            else if (bVar6) {
              uVar13 = 0;
              BIO_dump(bp,(char *)a,(int)local_24);
            }
            else {
              uVar13 = 0;
              BIO_write(bp,a,(int)local_24);
            }
            goto LAB_08085c0f;
          }
        }
        else {
          if (0x100 < local_50) {
            if (local_50 == 0x200) {
              iVar7 = EVP_PKEY_decrypt(local_5c,(uchar *)a,(size_t *)&local_24,local_2c,tbslen);
            }
            else {
              if (local_50 != 0x400) goto LAB_080863a1;
              iVar7 = EVP_PKEY_derive(local_5c,(uchar *)a,(size_t *)&local_24);
            }
            goto LAB_08086269;
          }
          if (local_50 == 8) {
            iVar7 = EVP_PKEY_sign(local_5c,(uchar *)a,(size_t *)&local_24,local_2c,tbslen);
            goto LAB_08086269;
          }
          if (local_50 == 0x20) {
            iVar7 = EVP_PKEY_verify_recover(local_5c,(uchar *)a,(size_t *)&local_24,local_2c,tbslen)
            ;
            goto LAB_08086269;
          }
        }
      }
      else {
        if (0x100 < local_50) {
          if (local_50 == 0x200) {
            iVar7 = EVP_PKEY_decrypt(local_5c,(uchar *)0x0,(size_t *)&local_24,local_2c,tbslen);
          }
          else {
            if (local_50 != 0x400) goto LAB_0808639f;
            iVar7 = EVP_PKEY_derive(local_5c,(uchar *)0x0,(size_t *)&local_24);
          }
          goto LAB_080861f7;
        }
        if (local_50 == 8) {
          iVar7 = EVP_PKEY_sign(local_5c,(uchar *)0x0,(size_t *)&local_24,local_2c,tbslen);
          goto LAB_080861f7;
        }
        if (local_50 == 0x20) {
          iVar7 = EVP_PKEY_verify_recover(local_5c,(uchar *)0x0,(size_t *)&local_24,local_2c,tbslen)
          ;
          goto LAB_080861f7;
        }
LAB_0808639f:
        a = (BIO *)0x0;
      }
LAB_080863a1:
      uVar13 = 1;
      BIO_printf(bio_err,"Public Key operation error\n");
      ERR_print_errors(bio_err);
      goto LAB_08085c0f;
    }
    iVar7 = EVP_PKEY_verify(local_5c,local_28,(size_t)local_58,local_2c,tbslen);
    if (iVar7 != 0) {
      if (iVar7 == 1) {
        uVar13 = 1;
        a = (BIO *)0x0;
        BIO_puts(bp,"Signature Verified Successfully\n");
      }
      else {
        a = (BIO *)0x0;
        uVar13 = 1;
        if (iVar7 < 0) goto LAB_0808639f;
      }
      goto LAB_08085c0f;
    }
    BIO_puts(bp,"Signature Verification Failure\n");
LAB_08085e95:
    EVP_PKEY_CTX_free(local_5c);
    BIO_free(pBVar11);
    goto LAB_08085a57;
  }
  pcVar18 = "Signature file specified for non verify\n";
LAB_08085bf6:
  BIO_puts(bio_err,pcVar18);
LAB_08085c01:
  uVar13 = 1;
  a = (BIO *)0x0;
  bp = (BIO *)0x0;
  pBVar11 = (BIO *)0x0;
LAB_08085c0f:
  EVP_PKEY_CTX_free(local_5c);
  BIO_free(pBVar11);
  BIO_free_all(bp);
  if (local_2c != (uchar *)0x0) goto LAB_08085a6e;
  goto LAB_08085a7a;
}

