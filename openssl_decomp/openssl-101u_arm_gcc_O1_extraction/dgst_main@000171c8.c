
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void dgst_main(int param_1,undefined4 *param_2)

{
  char cVar1;
  char **ppcVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  BIO *ptr;
  BIO *st;
  BIO_METHOD *pBVar7;
  BIO *b;
  BIO *bp;
  BIO *pBVar8;
  BIO *data;
  int iVar9;
  long lVar10;
  void *pvVar11;
  BIO *b_00;
  BIO *pBVar12;
  EVP_PKEY_ASN1_METHOD *ameth;
  EVP_MD *pEVar13;
  bool bVar14;
  int iVar15;
  uchar *puVar16;
  char *pcVar17;
  char *pcVar18;
  char **ppcVar19;
  int iVar20;
  int local_b8;
  BIO *local_a8;
  BIO *local_a0;
  undefined4 local_9c;
  BIO *local_98;
  char *local_94;
  char *local_90;
  char *local_8c;
  char *local_84;
  char *local_80;
  ENGINE *local_78;
  EVP_MD *local_74;
  undefined4 local_70;
  BIO *local_64;
  void *local_60;
  EVP_MD_CTX *local_5c;
  EVP_MD_CTX *local_58;
  char acStack_54 [40];
  bio_st *local_2c;
  
  local_2c = __stack_chk_guard;
  local_64 = (BIO *)0x0;
  local_60 = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  ptr = (BIO *)CRYPTO_malloc(0x2000,"dgst.c",0x87);
  if (ptr == (BIO *)0x0) {
    BIO_printf(bio_err,"out of memory\n");
    iVar15 = 1;
    b = ptr;
    bp = ptr;
    data = ptr;
    local_a8 = ptr;
    goto LAB_00017240;
  }
  if (bio_err == (BIO *)0x0) {
    pBVar7 = BIO_s_file();
    bio_err = BIO_new(pBVar7);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  st = (BIO *)load_config(bio_err,0);
  local_a8 = st;
  if (st != (BIO *)0x0) {
    ppcVar19 = (char **)(param_2 + 1);
    local_b8 = param_1 + -1;
    program_name(*param_2,acStack_54,0x28);
    local_74 = EVP_get_digestbyname(acStack_54);
    if ((0 < local_b8) && (pcVar17 = (char *)param_2[1], *pcVar17 == '-')) {
      local_9c = 0;
      pcVar18 = (char *)0x0;
      local_90 = (char *)0xffffffff;
      st = (BIO *)0x0;
      local_a8 = (BIO *)0x0;
      local_70 = 3;
      bVar6 = false;
      local_80 = (char *)0x0;
      local_84 = (char *)0x0;
      local_8c = (char *)0x0;
      bVar3 = false;
      bVar5 = false;
      local_98 = (BIO *)0x0;
      local_94 = (char *)0x0;
      local_a0 = (BIO *)0x0;
      bVar4 = false;
      local_78 = (ENGINE *)0x0;
      do {
        cVar1 = pcVar17[1];
        ppcVar2 = ppcVar19;
        pEVar13 = local_74;
        if (cVar1 == 'c') {
          if (pcVar17[2] == '\0') {
            local_9c = 1;
            iVar15 = local_b8;
          }
          else {
LAB_00017446:
            iVar15 = strcmp(pcVar17,"-rand");
            if (iVar15 == 0) {
              iVar15 = local_b8 + -1;
              if (iVar15 == 0) goto LAB_0001733a;
              pcVar18 = ppcVar19[1];
              ppcVar2 = ppcVar19 + 1;
            }
            else {
              iVar15 = strcmp(pcVar17,"-out");
              if (iVar15 == 0) {
                iVar15 = local_b8 + -1;
                if (iVar15 == 0) goto LAB_0001733a;
                local_a0 = (BIO *)ppcVar19[1];
                ppcVar2 = ppcVar19 + 1;
              }
              else {
                iVar15 = strcmp(pcVar17,"-sign");
                if (iVar15 == 0) {
                  iVar15 = local_b8 + -1;
                  if (iVar15 == 0) goto LAB_0001733a;
                  local_94 = ppcVar19[1];
                  ppcVar2 = ppcVar19 + 1;
                }
                else {
                  iVar15 = strcmp(pcVar17,"-passin");
                  if (iVar15 == 0) {
                    iVar15 = local_b8 + -1;
                    if (iVar15 == 0) goto LAB_0001733a;
                    local_8c = ppcVar19[1];
                    ppcVar2 = ppcVar19 + 1;
                  }
                  else {
                    iVar15 = strcmp(pcVar17,"-verify");
                    if (iVar15 == 0) {
                      iVar15 = local_b8 + -1;
                      if (iVar15 == 0) goto LAB_0001733a;
                      local_94 = ppcVar19[1];
                      bVar3 = true;
                      bVar5 = true;
                      ppcVar2 = ppcVar19 + 1;
                    }
                    else {
                      iVar15 = strcmp(pcVar17,"-prverify");
                      if (iVar15 == 0) {
                        iVar15 = local_b8 + -1;
                        if (iVar15 == 0) goto LAB_0001733a;
                        local_94 = ppcVar19[1];
                        bVar3 = true;
                        ppcVar2 = ppcVar19 + 1;
                      }
                      else {
                        iVar15 = strcmp(pcVar17,"-signature");
                        if (iVar15 == 0) {
                          iVar15 = local_b8 + -1;
                          if (iVar15 == 0) goto LAB_0001733a;
                          local_98 = (BIO *)ppcVar19[1];
                          ppcVar2 = ppcVar19 + 1;
                        }
                        else {
                          iVar15 = strcmp(pcVar17,"-keyform");
                          if (iVar15 == 0) {
                            iVar15 = local_b8 + -1;
                            if (iVar15 == 0) goto LAB_0001733a;
                            local_70 = str2fmt(ppcVar19[1]);
                            ppcVar2 = ppcVar19 + 1;
                          }
                          else {
                            iVar15 = strcmp(pcVar17,"-engine");
                            if (iVar15 == 0) {
                              iVar15 = local_b8 + -1;
                              if (iVar15 == 0) goto LAB_0001733a;
                              local_78 = (ENGINE *)setup_engine(bio_err,ppcVar19[1],0);
                              ppcVar2 = ppcVar19 + 1;
                            }
                            else {
                              iVar15 = strcmp(pcVar17,"-hex");
                              if (iVar15 == 0) {
                                local_90 = (char *)0x0;
                                iVar15 = local_b8;
                              }
                              else {
                                iVar15 = strcmp(pcVar17,"-binary");
                                if (iVar15 == 0) {
                                  local_90 = (char *)0x1;
                                  iVar15 = local_b8;
                                }
                                else if ((cVar1 == 'd') && (pcVar17[2] == '\0')) {
                                  bVar4 = true;
                                  iVar15 = local_b8;
                                }
                                else {
                                  iVar15 = strcmp(pcVar17,"-fips-fingerprint");
                                  if (iVar15 == 0) {
                                    local_84 = "etaonrishdlcupfm";
                                    iVar15 = local_b8;
                                  }
                                  else {
                                    iVar15 = strcmp(pcVar17,"-non-fips-allow");
                                    if (iVar15 == 0) {
                                      bVar6 = true;
                                      iVar15 = local_b8;
                                    }
                                    else {
                                      iVar15 = strcmp(pcVar17,"-hmac");
                                      if (iVar15 == 0) {
                                        iVar15 = local_b8 + -1;
                                        if (iVar15 == 0) goto LAB_0001733a;
                                        local_84 = ppcVar19[1];
                                        ppcVar2 = ppcVar19 + 1;
                                      }
                                      else {
                                        iVar15 = strcmp(pcVar17,"-mac");
                                        if (iVar15 == 0) {
                                          iVar15 = local_b8 + -1;
                                          if (iVar15 == 0) goto LAB_0001733a;
                                          local_80 = ppcVar19[1];
                                          ppcVar2 = ppcVar19 + 1;
                                        }
                                        else {
                                          iVar15 = strcmp(pcVar17,"-sigopt");
                                          if (iVar15 == 0) {
                                            iVar15 = local_b8 + -1;
                                            if ((iVar15 == 0) ||
                                               ((local_a8 == (BIO *)0x0 &&
                                                (local_a8 = (BIO *)sk_new_null(),
                                                local_a8 == (BIO *)0x0)))) goto LAB_0001733a;
                                            iVar9 = sk_push((_STACK *)local_a8,ppcVar19[1]);
                                          }
                                          else {
                                            iVar15 = strcmp(pcVar17,"-macopt");
                                            if (iVar15 != 0) {
                                              pEVar13 = EVP_get_digestbyname(pcVar17 + 1);
                                              iVar15 = local_b8;
                                              if (pEVar13 != (EVP_MD *)0x0) goto joined_r0x00017338;
                                              goto LAB_0001733a;
                                            }
                                            iVar15 = local_b8 + -1;
                                            if ((iVar15 == 0) ||
                                               ((st == (BIO *)0x0 &&
                                                (st = (BIO *)sk_new_null(), st == (BIO *)0x0))))
                                            goto LAB_0001733a;
                                            iVar9 = sk_push((_STACK *)st,ppcVar19[1]);
                                          }
                                          ppcVar2 = ppcVar19 + 1;
                                          iVar15 = local_b8 + -1;
                                          if (iVar9 == 0) {
                                            local_b8 = local_b8 + -1;
                                            ppcVar19 = ppcVar19 + 1;
                                            bVar14 = bVar3;
                                            if (local_98 != (BIO *)0x0) {
                                              bVar14 = false;
                                            }
                                            if (!bVar14) goto LAB_00017358;
                                            goto LAB_000174d4;
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
        }
        else {
          if ((cVar1 != 'r') || (pcVar17[2] != '\0')) goto LAB_00017446;
          local_9c = 2;
          iVar15 = local_b8;
        }
joined_r0x00017338:
        local_74 = pEVar13;
        local_b8 = iVar15 + -1;
        ppcVar19 = ppcVar2 + 1;
        iVar15 = local_b8;
        if ((local_b8 == 0) || (pcVar17 = ppcVar2[1], *pcVar17 != '-')) goto LAB_0001733a;
      } while( true );
    }
    bVar3 = false;
    local_90 = (char *)0xffffffff;
    pcVar18 = (char *)0x0;
    bVar6 = false;
    local_80 = (char *)0x0;
    local_84 = (char *)0x0;
    st = (BIO *)0x0;
    local_8c = (char *)0x0;
    bVar5 = false;
    local_98 = (BIO *)0x0;
    local_94 = (char *)0x0;
    local_a0 = (BIO *)0x0;
    bVar4 = false;
    local_9c = 0;
    local_78 = (ENGINE *)0x0;
    local_a8 = (BIO *)0x0;
    local_70 = 3;
    goto LAB_00017358;
  }
  goto LAB_00017226;
LAB_0001733a:
  bVar14 = bVar3;
  if (local_98 != (BIO *)0x0) {
    bVar14 = false;
  }
  local_b8 = iVar15;
  if (bVar14) {
LAB_000174d4:
    BIO_printf(bio_err,"No signature to verify: use the -signature option\n");
  }
  else {
LAB_00017358:
    if ((local_b8 < 1) || (**ppcVar19 != '-')) {
      pBVar7 = BIO_s_file();
      b = BIO_new(pBVar7);
      pBVar7 = BIO_f_md();
      bp = BIO_new(pBVar7);
      if (b == (BIO *)0x0 || bp == (BIO *)0x0) {
        ERR_print_errors(bio_err);
        OPENSSL_cleanse(ptr,0x2000);
        CRYPTO_free(ptr);
        if (b == (BIO *)0x0) {
          iVar15 = 1;
          ptr = st;
          data = b;
          goto LAB_00017240;
        }
        pBVar8 = (BIO *)0x0;
        data = (BIO *)0x0;
        iVar15 = 1;
      }
      else {
        if (bVar4) {
          BIO_set_callback(b,BIO_debug_callback + 1);
          BIO_set_callback_arg(b,(char *)bio_err);
        }
        pBVar8 = (BIO *)app_passwd(bio_err,local_8c,0,&local_60,0);
        if (pBVar8 == (BIO *)0x0) {
          BIO_printf(bio_err,"Error getting password\n");
          iVar15 = 1;
          data = pBVar8;
        }
        else {
          if ((local_90 == (char *)0xffffffff) && (local_90 = local_94, local_94 != (char *)0x0)) {
            local_90 = (char *)0x1;
          }
          if (pcVar18 != (char *)0x0) {
            app_RAND_load_file(pcVar18,bio_err,0);
          }
          if (local_a0 == (BIO *)0x0) {
            pBVar8 = BIO_new_fp(stdout,0);
          }
          else if (local_90 == (char *)0x0) {
            pBVar8 = BIO_new_file((char *)local_a0,"w");
          }
          else {
            pBVar8 = BIO_new_file((char *)local_a0,"wb");
          }
          if (pBVar8 == (BIO *)0x0) {
            pcVar17 = "(stdout)";
            if (local_a0 != (BIO *)0x0) {
              pcVar17 = (char *)local_a0;
            }
            BIO_printf(bio_err,"Error opening output file %s\n",pcVar17);
            ERR_print_errors(bio_err);
            iVar15 = 1;
            data = pBVar8;
          }
          else {
            pcVar17 = local_80;
            if (local_80 != (char *)0x0) {
              pcVar17 = (char *)0x1;
            }
            pcVar18 = local_94;
            if (local_94 != (char *)0x0) {
              pcVar18 = (char *)0x1;
            }
            puVar16 = (uchar *)local_84;
            if ((uchar *)local_84 != (uchar *)0x0) {
              puVar16 = (uchar *)0x1;
            }
            if ((int)(pcVar17 + (int)pcVar18 + (int)puVar16) < 2) {
              if (pcVar18 == (char *)0x0) {
LAB_00017618:
                if (pcVar17 == (char *)0x0) {
LAB_0001781c:
                  if (bVar6) {
                    BIO_ctrl(bp,0x78,0,&local_58);
                    EVP_MD_CTX_set_flags(local_58,8);
                  }
                  if (puVar16 == (uchar *)0x0) {
                    if (local_64 != (BIO *)0x0) goto LAB_00017844;
                    if (local_74 == (EVP_MD *)0x0) {
                      local_74 = EVP_md5();
                    }
                    data = (BIO *)BIO_ctrl(bp,0x6f,0,local_74);
                    pBVar12 = (BIO *)acStack_54;
                    pcVar17 = "Error setting digest %s\n";
                    if (data == (BIO *)0x0) {
LAB_00017ae0:
                      BIO_printf(bio_err,pcVar17,pBVar12);
                      ERR_print_errors(bio_err);
                      iVar15 = 1;
                    }
                    else {
LAB_000178c6:
                      if (local_98 == (BIO *)0x0) {
                        local_a0 = local_98;
                        data = local_98;
                      }
                      else {
                        if (local_64 != (BIO *)0x0) {
                          b_00 = BIO_new_file((char *)local_98,"rb");
                          iVar15 = EVP_PKEY_size((EVP_PKEY *)local_64);
                          data = (BIO *)CRYPTO_malloc(iVar15,"dgst.c",0x1bd);
                          pBVar12 = local_98;
                          if (b_00 == (BIO *)0x0) {
                            pcVar17 = "Error opening signature file %s\n";
                          }
                          else {
                            if (data == (BIO *)0x0) {
                              BIO_printf(bio_err,"Out of memory\n");
                              ERR_print_errors(bio_err);
                              iVar15 = 1;
                              goto LAB_0001742e;
                            }
                            local_a0 = (BIO *)BIO_read(b_00,data,iVar15);
                            BIO_free(b_00);
                            if (0 < (int)local_a0) goto LAB_00017928;
                            pcVar17 = "Error reading signature file %s\n";
                          }
                          goto LAB_00017ae0;
                        }
                        local_a0 = local_64;
                        data = local_64;
                      }
LAB_00017928:
                      pBVar12 = BIO_push(bp,b);
                      if (local_74 == (EVP_MD *)0x0) {
                        BIO_ctrl(bp,0x78,0,&local_58);
                        local_74 = EVP_MD_CTX_md(local_58);
                      }
                      if (local_b8 == 0) {
                        BIO_ctrl(b,0x6a,0,stdin);
                        iVar15 = do_fp(pBVar8,ptr,pBVar12,local_9c,local_90,local_64,data,local_a0,0
                                       ,0,"stdin",bp);
                      }
                      else {
                        local_58 = (EVP_MD_CTX *)0x0;
                        if (local_90 == (char *)0x0) {
                          if ((local_64 != (BIO *)0x0) &&
                             (ameth = EVP_PKEY_get0_asn1((EVP_PKEY *)local_64),
                             ameth != (EVP_PKEY_ASN1_METHOD *)0x0)) {
                            EVP_PKEY_asn1_get0_info
                                      ((int *)0x0,(int *)0x0,(int *)0x0,(char **)0x0,
                                       (char **)&local_58,ameth);
                          }
                          iVar15 = EVP_MD_type(local_74);
                          local_98 = (BIO *)OBJ_nid2sn(iVar15);
                        }
                        else {
                          local_98 = (BIO *)0x0;
                        }
                        iVar9 = 0;
                        iVar15 = 0;
                        if (0 < local_b8) {
                          iVar20 = 0;
                          do {
                            lVar10 = BIO_ctrl(b,0x6c,3,*ppcVar19);
                            if (lVar10 < 1) {
                              iVar9 = iVar9 + 1;
                              perror(*ppcVar19);
                            }
                            else {
                              iVar15 = do_fp(pBVar8,ptr,pBVar12,local_9c,local_90,local_64,data,
                                             local_a0,local_58,local_98,*ppcVar19,bp);
                              if (iVar15 != 0) {
                                iVar9 = iVar15;
                              }
                              BIO_ctrl(bp,1,0,(void *)0x0);
                            }
                            iVar20 = iVar20 + 1;
                            iVar15 = iVar9;
                            ppcVar19 = ppcVar19 + 1;
                          } while (iVar20 != local_b8);
                        }
                      }
                    }
                    goto LAB_0001742e;
                  }
                  data = (BIO *)EVP_PKEY_new_mac_key(0x357,local_78,(uchar *)local_84,-1);
                  local_64 = data;
                  if (data != (BIO *)0x0) {
LAB_00017844:
                    local_5c = (EVP_MD_CTX *)0x0;
                    local_58 = (EVP_MD_CTX *)0x0;
                    lVar10 = BIO_ctrl(bp,0x78,0,&local_5c);
                    if (lVar10 == 0) {
                      BIO_printf(bio_err,"Error getting context\n");
                      ERR_print_errors(bio_err);
                    }
                    else {
                      if (bVar3) {
                        iVar15 = EVP_DigestVerifyInit
                                           (local_5c,(EVP_PKEY_CTX **)&local_58,local_74,
                                            (ENGINE *)0x0,(EVP_PKEY *)local_64);
                      }
                      else {
                        iVar15 = EVP_DigestSignInit(local_5c,(EVP_PKEY_CTX **)&local_58,local_74,
                                                    (ENGINE *)0x0,(EVP_PKEY *)local_64);
                      }
                      if (iVar15 != 0) {
                        if (local_a8 != (BIO *)0x0) {
                          for (iVar15 = 0; iVar9 = sk_num((_STACK *)local_a8), iVar15 < iVar9;
                              iVar15 = iVar15 + 1) {
                            pvVar11 = sk_value((_STACK *)local_a8,iVar15);
                            iVar9 = pkey_ctrl_string(local_58,pvVar11);
                            if (iVar9 < 1) {
                              BIO_printf(bio_err,"parameter error \"%s\"\n",pvVar11);
                              ERR_print_errors(bio_err);
                              goto LAB_000176ac;
                            }
                          }
                        }
                        goto LAB_000178c6;
                      }
                      BIO_printf(bio_err,"Error setting context\n");
                      ERR_print_errors(bio_err);
                    }
                    goto LAB_000176ac;
                  }
                }
                else {
                  iVar15 = 0;
                  local_58 = (EVP_MD_CTX *)0x0;
                  data = (BIO *)init_gen_str(bio_err,&local_58,local_80,local_78,0);
                  if (data != (BIO *)0x0) {
                    if (st != (BIO *)0x0) {
                      for (; iVar9 = sk_num((_STACK *)st), iVar15 < iVar9; iVar15 = iVar15 + 1) {
                        pvVar11 = sk_value((_STACK *)st,iVar15);
                        iVar9 = pkey_ctrl_string(local_58,pvVar11);
                        if (iVar9 < 1) {
                          data = (BIO *)0x0;
                          BIO_printf(bio_err,"MAC parameter error \"%s\"\n",pvVar11);
                          ERR_print_errors(bio_err);
                          goto LAB_00017684;
                        }
                      }
                    }
                    iVar15 = EVP_PKEY_keygen((EVP_PKEY_CTX *)local_58,(EVP_PKEY **)&local_64);
                    if (iVar15 < 1) {
                      data = (BIO *)0x0;
                      BIO_puts(bio_err,"Error generating key\n");
                      ERR_print_errors(bio_err);
                    }
                    else {
                      data = (BIO *)0x1;
                    }
                  }
LAB_00017684:
                  if (local_58 != (EVP_MD_CTX *)0x0) {
                    EVP_PKEY_CTX_free((EVP_PKEY_CTX *)local_58);
                  }
                  if (data != (BIO *)0x0) goto LAB_0001781c;
                }
                iVar15 = 1;
              }
              else {
                if (bVar5) {
                  local_64 = (BIO *)load_pubkey(bio_err,local_94,local_70,0,0,local_78,"key file");
                }
                else {
                  local_64 = (BIO *)load_key(bio_err,local_94,local_70,0,local_60,local_78,
                                             "key file");
                }
                if (local_64 != (BIO *)0x0) goto LAB_00017618;
LAB_000176ac:
                iVar15 = 1;
                data = (BIO *)0x0;
              }
            }
            else {
              BIO_printf(bio_err,"MAC and Signing key cannot both be specified\n");
              iVar15 = 1;
              data = (BIO *)0x0;
            }
          }
        }
LAB_0001742e:
        OPENSSL_cleanse(ptr,0x2000);
        CRYPTO_free(ptr);
      }
      BIO_free(b);
      ptr = st;
      b = pBVar8;
      goto LAB_00017240;
    }
    BIO_printf(bio_err,"unknown option \'%s\'\n");
    BIO_printf(bio_err,"options are\n");
    BIO_printf(bio_err,"-c              to output the digest with separating colons\n");
    BIO_printf(bio_err,"-r              to output the digest in coreutils format\n");
    BIO_printf(bio_err,"-d              to output debug info\n");
    BIO_printf(bio_err,"-hex            output as hex dump\n");
    BIO_printf(bio_err,"-binary         output in binary form\n");
    BIO_printf(bio_err,"-hmac arg       set the HMAC key to arg\n");
    BIO_printf(bio_err,"-non-fips-allow allow use of non FIPS digest\n");
    BIO_printf(bio_err,"-sign   file    sign digest using private key in file\n");
    BIO_printf(bio_err,"-verify file    verify a signature using public key in file\n");
    BIO_printf(bio_err,"-prverify file  verify a signature using private key in file\n");
    BIO_printf(bio_err,"-keyform arg    key file format (PEM or ENGINE)\n");
    BIO_printf(bio_err,"-out filename   output to filename rather than stdout\n");
    BIO_printf(bio_err,"-signature file signature to verify\n");
    BIO_printf(bio_err,"-sigopt nm:v    signature parameter\n");
    BIO_printf(bio_err,"-hmac key       create hashed MAC with key\n");
    BIO_printf(bio_err,"-mac algorithm  create MAC (not neccessarily HMAC)\n");
    BIO_printf(bio_err,"-macopt nm:v    MAC algorithm parameters or key\n");
    BIO_printf(bio_err,"-engine e       use engine e, possibly a hardware device.\n");
    EVP_MD_do_all_sorted(list_md_fn + 1,bio_err);
  }
LAB_00017226:
  OPENSSL_cleanse(ptr,0x2000);
  CRYPTO_free(ptr);
  iVar15 = 1;
  ptr = st;
  b = (BIO *)0x0;
  bp = (BIO *)0x0;
  data = (BIO *)0x0;
LAB_00017240:
  if (local_60 != (void *)0x0) {
    CRYPTO_free(local_60);
  }
  BIO_free_all(b);
  EVP_PKEY_free((EVP_PKEY *)local_64);
  if (local_a8 != (BIO *)0x0) {
    sk_free((_STACK *)local_a8);
  }
  if (ptr != (BIO *)0x0) {
    sk_free((_STACK *)ptr);
  }
  if (data != (BIO *)0x0) {
    CRYPTO_free(data);
  }
  if (bp != (BIO *)0x0) {
    BIO_free(bp);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar15);
}

