
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
  BIO *data;
  int iVar8;
  long lVar9;
  void *pvVar10;
  BIO *b_00;
  BIO *pBVar11;
  EVP_PKEY_ASN1_METHOD *ameth;
  int iVar12;
  EVP_MD *pEVar13;
  bool bVar14;
  char *pcVar15;
  uchar *puVar16;
  char **ppcVar17;
  int iVar18;
  char *pcVar19;
  int local_bc;
  BIO *local_b0;
  BIO *local_ac;
  BIO *local_a4;
  char *local_a0;
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
  
  local_2c = __TMC_END__;
  local_64 = (BIO *)0x0;
  local_60 = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  ptr = (BIO *)CRYPTO_malloc(0x2000,"dgst.c",0x87);
  if (ptr == (BIO *)0x0) {
    BIO_printf(bio_err,"out of memory\n");
    iVar18 = 1;
    b = ptr;
    bp = ptr;
    local_b0 = ptr;
    local_ac = ptr;
    goto LAB_000171c2;
  }
  if (bio_err == (BIO *)0x0) {
    pBVar7 = BIO_s_file();
    bio_err = BIO_new(pBVar7);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  st = (BIO *)load_config(bio_err,0);
  local_ac = st;
  if (st != (BIO *)0x0) {
    ppcVar17 = (char **)(param_2 + 1);
    local_bc = param_1 + -1;
    program_name(*param_2,acStack_54,0x28);
    local_74 = EVP_get_digestbyname(acStack_54);
    if (0 < local_bc) {
      pcVar19 = (char *)param_2[1];
      st = (BIO *)0x0;
      if (*pcVar19 == '-') {
        local_ac = (BIO *)0x0;
        local_8c = (char *)0xffffffff;
        bVar6 = false;
        local_70 = 3;
        local_80 = (char *)0x0;
        local_9c = 0;
        local_84 = (char *)0x0;
        local_90 = (char *)0x0;
        bVar3 = false;
        bVar5 = false;
        local_b0 = (BIO *)0x0;
        local_98 = (BIO *)0x0;
        local_94 = (char *)0x0;
        local_a0 = (char *)0x0;
        bVar4 = false;
        local_78 = (ENGINE *)0x0;
        do {
          cVar1 = pcVar19[1];
          ppcVar2 = ppcVar17;
          pEVar13 = local_74;
          if (cVar1 == 'c') {
            if (pcVar19[2] == '\0') {
              local_9c = 1;
              iVar18 = local_bc;
            }
            else {
LAB_000173c8:
              iVar18 = strcmp(pcVar19,"-rand");
              if (iVar18 == 0) {
                iVar18 = local_bc + -1;
                if (iVar18 == 0) goto LAB_000172b8;
                local_b0 = (BIO *)ppcVar17[1];
                ppcVar2 = ppcVar17 + 1;
              }
              else {
                iVar18 = strcmp(pcVar19,"-out");
                if (iVar18 == 0) {
                  iVar18 = local_bc + -1;
                  if (iVar18 == 0) goto LAB_000172b8;
                  local_a0 = ppcVar17[1];
                  ppcVar2 = ppcVar17 + 1;
                }
                else {
                  iVar18 = strcmp(pcVar19,"-sign");
                  if (iVar18 == 0) {
                    iVar18 = local_bc + -1;
                    if (iVar18 == 0) goto LAB_000172b8;
                    local_94 = ppcVar17[1];
                    ppcVar2 = ppcVar17 + 1;
                  }
                  else {
                    iVar18 = strcmp(pcVar19,"-passin");
                    if (iVar18 == 0) {
                      iVar18 = local_bc + -1;
                      if (iVar18 == 0) goto LAB_000172b8;
                      local_90 = ppcVar17[1];
                      ppcVar2 = ppcVar17 + 1;
                    }
                    else {
                      iVar18 = strcmp(pcVar19,"-verify");
                      if (iVar18 == 0) {
                        iVar18 = local_bc + -1;
                        if (iVar18 == 0) goto LAB_000172b8;
                        local_94 = ppcVar17[1];
                        bVar3 = true;
                        bVar5 = true;
                        ppcVar2 = ppcVar17 + 1;
                      }
                      else {
                        iVar18 = strcmp(pcVar19,"-prverify");
                        if (iVar18 == 0) {
                          iVar18 = local_bc + -1;
                          if (iVar18 == 0) goto LAB_000172b8;
                          local_94 = ppcVar17[1];
                          bVar3 = true;
                          ppcVar2 = ppcVar17 + 1;
                        }
                        else {
                          iVar18 = strcmp(pcVar19,"-signature");
                          if (iVar18 == 0) {
                            iVar18 = local_bc + -1;
                            if (iVar18 == 0) goto LAB_000172b8;
                            local_98 = (BIO *)ppcVar17[1];
                            ppcVar2 = ppcVar17 + 1;
                          }
                          else {
                            iVar18 = strcmp(pcVar19,"-keyform");
                            if (iVar18 == 0) {
                              iVar18 = local_bc + -1;
                              if (iVar18 == 0) goto LAB_000172b8;
                              local_70 = str2fmt(ppcVar17[1]);
                              ppcVar2 = ppcVar17 + 1;
                            }
                            else {
                              iVar18 = strcmp(pcVar19,"-engine");
                              if (iVar18 == 0) {
                                iVar18 = local_bc + -1;
                                if (iVar18 == 0) goto LAB_000172b8;
                                local_78 = (ENGINE *)setup_engine(bio_err,ppcVar17[1],0);
                                ppcVar2 = ppcVar17 + 1;
                              }
                              else {
                                iVar18 = strcmp(pcVar19,"-hex");
                                if (iVar18 == 0) {
                                  local_8c = (char *)0x0;
                                  iVar18 = local_bc;
                                }
                                else {
                                  iVar18 = strcmp(pcVar19,"-binary");
                                  if (iVar18 == 0) {
                                    local_8c = (char *)0x1;
                                    iVar18 = local_bc;
                                  }
                                  else if ((cVar1 == 'd') && (pcVar19[2] == '\0')) {
                                    bVar4 = true;
                                    iVar18 = local_bc;
                                  }
                                  else {
                                    iVar18 = strcmp(pcVar19,"-fips-fingerprint");
                                    if (iVar18 == 0) {
                                      local_84 = "etaonrishdlcupfm";
                                      iVar18 = local_bc;
                                    }
                                    else {
                                      iVar18 = strcmp(pcVar19,"-non-fips-allow");
                                      if (iVar18 == 0) {
                                        bVar6 = true;
                                        iVar18 = local_bc;
                                      }
                                      else {
                                        iVar18 = strcmp(pcVar19,"-hmac");
                                        if (iVar18 == 0) {
                                          iVar18 = local_bc + -1;
                                          if (iVar18 == 0) goto LAB_000172b8;
                                          local_84 = ppcVar17[1];
                                          ppcVar2 = ppcVar17 + 1;
                                        }
                                        else {
                                          iVar18 = strcmp(pcVar19,"-mac");
                                          if (iVar18 == 0) {
                                            iVar18 = local_bc + -1;
                                            if (iVar18 == 0) goto LAB_000172b8;
                                            local_80 = ppcVar17[1];
                                            ppcVar2 = ppcVar17 + 1;
                                          }
                                          else {
                                            iVar18 = strcmp(pcVar19,"-sigopt");
                                            if (iVar18 == 0) {
                                              iVar18 = local_bc + -1;
                                              if ((iVar18 == 0) ||
                                                 ((local_ac == (BIO *)0x0 &&
                                                  (local_ac = (BIO *)sk_new_null(),
                                                  local_ac == (BIO *)0x0)))) goto LAB_000172b8;
                                              iVar8 = sk_push((_STACK *)local_ac,ppcVar17[1]);
                                            }
                                            else {
                                              iVar18 = strcmp(pcVar19,"-macopt");
                                              if (iVar18 != 0) {
                                                pEVar13 = EVP_get_digestbyname(pcVar19 + 1);
                                                iVar18 = local_bc;
                                                if (pEVar13 != (EVP_MD *)0x0)
                                                goto joined_r0x000172b6;
                                                goto LAB_000172b8;
                                              }
                                              iVar18 = local_bc + -1;
                                              if ((iVar18 == 0) ||
                                                 ((st == (BIO *)0x0 &&
                                                  (st = (BIO *)sk_new_null(), st == (BIO *)0x0))))
                                              goto LAB_000172b8;
                                              iVar8 = sk_push((_STACK *)st,ppcVar17[1]);
                                            }
                                            ppcVar2 = ppcVar17 + 1;
                                            iVar18 = local_bc + -1;
                                            if (iVar8 == 0) {
                                              local_bc = local_bc + -1;
                                              ppcVar17 = ppcVar17 + 1;
                                              bVar14 = bVar3;
                                              if (local_98 != (BIO *)0x0) {
                                                bVar14 = false;
                                              }
                                              if (!bVar14) goto LAB_000172d6;
                                              goto LAB_00017448;
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
            if ((cVar1 != 'r') || (pcVar19[2] != '\0')) goto LAB_000173c8;
            local_9c = 2;
            iVar18 = local_bc;
          }
joined_r0x000172b6:
          local_74 = pEVar13;
          local_bc = iVar18 + -1;
          ppcVar17 = ppcVar2 + 1;
          iVar18 = local_bc;
          if ((local_bc == 0) || (pcVar19 = ppcVar2[1], *pcVar19 != '-')) goto LAB_000172b8;
        } while( true );
      }
    }
    st = (BIO *)0x0;
    bVar3 = false;
    local_8c = (char *)0xffffffff;
    bVar6 = false;
    local_80 = (char *)0x0;
    local_84 = (char *)0x0;
    local_90 = (char *)0x0;
    bVar5 = false;
    local_b0 = (BIO *)0x0;
    local_98 = (BIO *)0x0;
    local_94 = (char *)0x0;
    local_a0 = (char *)0x0;
    bVar4 = false;
    local_9c = 0;
    local_78 = (ENGINE *)0x0;
    local_ac = (BIO *)0x0;
    local_70 = 3;
    goto LAB_000172d6;
  }
  goto LAB_000171a4;
LAB_000172b8:
  bVar14 = bVar3;
  if (local_98 != (BIO *)0x0) {
    bVar14 = false;
  }
  local_bc = iVar18;
  if (bVar14) {
LAB_00017448:
    BIO_printf(bio_err,"No signature to verify: use the -signature option\n");
  }
  else {
LAB_000172d6:
    if ((local_bc < 1) || (**ppcVar17 != '-')) {
      pBVar7 = BIO_s_file();
      b = BIO_new(pBVar7);
      pBVar7 = BIO_f_md();
      bp = BIO_new(pBVar7);
      if (bVar4) {
        BIO_set_callback(b,BIO_debug_callback + 1);
        BIO_set_callback_arg(b,(char *)bio_err);
      }
      iVar18 = app_passwd(bio_err,local_90,0,&local_60,0);
      if (iVar18 == 0) {
        BIO_printf(bio_err,"Error getting password\n");
LAB_0001751e:
        OPENSSL_cleanse(ptr,0x2000);
        CRYPTO_free(ptr);
        if (b == (BIO *)0x0) {
          iVar18 = 1;
          ptr = st;
          local_b0 = b;
          goto LAB_000171c2;
        }
        data = (BIO *)0x0;
        iVar18 = 1;
        local_b0 = (BIO *)0x0;
      }
      else {
        if (b == (BIO *)0x0 || bp == (BIO *)0x0) {
          ERR_print_errors(bio_err);
          goto LAB_0001751e;
        }
        if ((local_8c == (char *)0xffffffff) && (local_8c = local_94, local_94 != (char *)0x0)) {
          local_8c = (char *)0x1;
        }
        if (local_b0 != (BIO *)0x0) {
          app_RAND_load_file(local_b0,bio_err,0);
        }
        if (local_a0 == (char *)0x0) {
          local_b0 = BIO_new_fp(stdout,0);
        }
        else if (local_8c == (char *)0x0) {
          local_b0 = BIO_new_file(local_a0,"w");
        }
        else {
          local_b0 = BIO_new_file(local_a0,"wb");
        }
        if (local_b0 == (BIO *)0x0) {
          pcVar19 = "(stdout)";
          if (local_a0 != (char *)0x0) {
            pcVar19 = local_a0;
          }
          BIO_printf(bio_err,"Error opening output file %s\n",pcVar19);
          ERR_print_errors(bio_err);
          iVar18 = 1;
          data = local_b0;
        }
        else {
          pcVar19 = local_80;
          if (local_80 != (char *)0x0) {
            pcVar19 = (char *)0x1;
          }
          pcVar15 = local_94;
          if (local_94 != (char *)0x0) {
            pcVar15 = (char *)0x1;
          }
          puVar16 = (uchar *)local_84;
          if ((uchar *)local_84 != (uchar *)0x0) {
            puVar16 = (uchar *)0x1;
          }
          if ((int)(pcVar19 + (int)pcVar15 + (int)puVar16) < 2) {
            if (pcVar15 == (char *)0x0) {
LAB_0001759c:
              if (pcVar19 == (char *)0x0) {
LAB_000177a4:
                if (bVar6) {
                  BIO_ctrl(bp,0x78,0,&local_58);
                  EVP_MD_CTX_set_flags(local_58,8);
                }
                if (puVar16 == (uchar *)0x0) {
                  if (local_64 != (BIO *)0x0) goto LAB_000177cc;
                  if (local_74 == (EVP_MD *)0x0) {
                    local_74 = EVP_md5();
                  }
                  data = (BIO *)BIO_ctrl(bp,0x6f,0,local_74);
                  pBVar11 = (BIO *)acStack_54;
                  pcVar19 = "Error setting digest %s\n";
                  if (data == (BIO *)0x0) goto LAB_00017a6a;
LAB_0001784e:
                  if (local_98 == (BIO *)0x0) {
                    local_a4 = local_98;
                    data = local_98;
                  }
                  else {
                    if (local_64 != (BIO *)0x0) {
                      b_00 = BIO_new_file((char *)local_98,"rb");
                      iVar18 = EVP_PKEY_size((EVP_PKEY *)local_64);
                      data = (BIO *)CRYPTO_malloc(iVar18,"dgst.c",0x1d9);
                      pBVar11 = local_98;
                      if (b_00 == (BIO *)0x0) {
                        pcVar19 = "Error opening signature file %s\n";
                      }
                      else {
                        local_a4 = (BIO *)BIO_read(b_00,data,iVar18);
                        BIO_free(b_00);
                        if (0 < (int)local_a4) goto LAB_000178b4;
                        pcVar19 = "Error reading signature file %s\n";
                      }
LAB_00017a6a:
                      BIO_printf(bio_err,pcVar19,pBVar11);
                      ERR_print_errors(bio_err);
                      iVar18 = 1;
                      goto LAB_000173b0;
                    }
                    local_a4 = local_64;
                    data = local_64;
                  }
LAB_000178b4:
                  pBVar11 = BIO_push(bp,b);
                  if (local_74 == (EVP_MD *)0x0) {
                    BIO_ctrl(bp,0x78,0,&local_58);
                    local_74 = EVP_MD_CTX_md(local_58);
                  }
                  if (local_bc == 0) {
                    BIO_ctrl(b,0x6a,0,stdin);
                    iVar18 = do_fp(local_b0,ptr,pBVar11,local_9c,local_8c,local_64,data,local_a4,0,0
                                   ,"stdin",bp);
                  }
                  else {
                    local_58 = (EVP_MD_CTX *)0x0;
                    if (local_8c == (char *)0x0) {
                      if ((local_64 != (BIO *)0x0) &&
                         (ameth = EVP_PKEY_get0_asn1((EVP_PKEY *)local_64),
                         ameth != (EVP_PKEY_ASN1_METHOD *)0x0)) {
                        EVP_PKEY_asn1_get0_info
                                  ((int *)0x0,(int *)0x0,(int *)0x0,(char **)0x0,(char **)&local_58,
                                   ameth);
                      }
                      iVar18 = EVP_MD_type(local_74);
                      local_98 = (BIO *)OBJ_nid2sn(iVar18);
                    }
                    else {
                      local_98 = (BIO *)0x0;
                    }
                    iVar18 = 0;
                    if (0 < local_bc) {
                      iVar8 = 0;
                      do {
                        lVar9 = BIO_ctrl(b,0x6c,3,*ppcVar17);
                        if (lVar9 < 1) {
                          iVar18 = iVar18 + 1;
                          perror(*ppcVar17);
                        }
                        else {
                          iVar12 = do_fp(local_b0,ptr,pBVar11,local_9c,local_8c,local_64,data,
                                         local_a4,local_58,local_98,*ppcVar17,bp);
                          if (iVar12 != 0) {
                            iVar18 = iVar12;
                          }
                          BIO_ctrl(bp,1,0,(void *)0x0);
                        }
                        iVar8 = iVar8 + 1;
                        ppcVar17 = ppcVar17 + 1;
                      } while (iVar8 != local_bc);
                    }
                  }
                  goto LAB_000173b0;
                }
                data = (BIO *)EVP_PKEY_new_mac_key(0x357,local_78,(uchar *)local_84,-1);
                local_64 = data;
                if (data != (BIO *)0x0) {
LAB_000177cc:
                  local_5c = (EVP_MD_CTX *)0x0;
                  local_58 = (EVP_MD_CTX *)0x0;
                  lVar9 = BIO_ctrl(bp,0x78,0,&local_5c);
                  if (lVar9 == 0) {
                    BIO_printf(bio_err,"Error getting context\n");
                    ERR_print_errors(bio_err);
                  }
                  else {
                    if (bVar3) {
                      iVar18 = EVP_DigestVerifyInit
                                         (local_5c,(EVP_PKEY_CTX **)&local_58,local_74,local_78,
                                          (EVP_PKEY *)local_64);
                    }
                    else {
                      iVar18 = EVP_DigestSignInit(local_5c,(EVP_PKEY_CTX **)&local_58,local_74,
                                                  local_78,(EVP_PKEY *)local_64);
                    }
                    if (iVar18 != 0) {
                      if (local_ac != (BIO *)0x0) {
                        for (iVar18 = 0; iVar8 = sk_num((_STACK *)local_ac), iVar18 < iVar8;
                            iVar18 = iVar18 + 1) {
                          pvVar10 = sk_value((_STACK *)local_ac,iVar18);
                          iVar8 = pkey_ctrl_string(local_58,pvVar10);
                          if (iVar8 < 1) {
                            BIO_printf(bio_err,"parameter error \"%s\"\n",pvVar10);
                            ERR_print_errors(bio_err);
                            goto LAB_00017638;
                          }
                        }
                      }
                      goto LAB_0001784e;
                    }
                    BIO_printf(bio_err,"Error setting context\n");
                    ERR_print_errors(bio_err);
                  }
                  goto LAB_00017638;
                }
              }
              else {
                iVar18 = 0;
                local_58 = (EVP_MD_CTX *)0x0;
                data = (BIO *)init_gen_str(bio_err,&local_58,local_80,local_78,0);
                if (data != (BIO *)0x0) {
                  if (st != (BIO *)0x0) {
                    for (; iVar8 = sk_num((_STACK *)st), iVar18 < iVar8; iVar18 = iVar18 + 1) {
                      pvVar10 = sk_value((_STACK *)st,iVar18);
                      iVar8 = pkey_ctrl_string(local_58,pvVar10);
                      if (iVar8 < 1) {
                        data = (BIO *)0x0;
                        BIO_printf(bio_err,"MAC parameter error \"%s\"\n",pvVar10);
                        ERR_print_errors(bio_err);
                        goto LAB_0001760a;
                      }
                    }
                  }
                  iVar18 = EVP_PKEY_keygen((EVP_PKEY_CTX *)local_58,(EVP_PKEY **)&local_64);
                  if (iVar18 < 1) {
                    data = (BIO *)0x0;
                    BIO_puts(bio_err,"Error generating key\n");
                    ERR_print_errors(bio_err);
                  }
                  else {
                    data = (BIO *)0x1;
                  }
                }
LAB_0001760a:
                if (local_58 != (EVP_MD_CTX *)0x0) {
                  EVP_PKEY_CTX_free((EVP_PKEY_CTX *)local_58);
                }
                if (data != (BIO *)0x0) goto LAB_000177a4;
              }
              iVar18 = 1;
            }
            else {
              if (bVar5) {
                local_64 = (BIO *)load_pubkey(bio_err,local_94,local_70,0,0,local_78,"key file");
              }
              else {
                local_64 = (BIO *)load_key(bio_err,local_94,local_70,0,local_60,local_78,"key file")
                ;
              }
              if (local_64 != (BIO *)0x0) goto LAB_0001759c;
LAB_00017638:
              iVar18 = 1;
              data = (BIO *)0x0;
            }
          }
          else {
            BIO_printf(bio_err,"MAC and Signing key cannot both be specified\n");
            iVar18 = 1;
            data = (BIO *)0x0;
          }
        }
LAB_000173b0:
        OPENSSL_cleanse(ptr,0x2000);
        CRYPTO_free(ptr);
      }
      BIO_free(b);
      ptr = st;
      b = data;
      goto LAB_000171c2;
    }
    BIO_printf(bio_err,"unknown option \'%s\'\n");
    BIO_printf(bio_err,"options are\n");
    BIO_printf(bio_err,"-c              to output the digest with separating colons\n");
    BIO_printf(bio_err,"-r              to output the digest in coreutils format\n");
    BIO_printf(bio_err,"-d              to output debug info\n");
    BIO_printf(bio_err,"-hex            output as hex dump\n");
    BIO_printf(bio_err,"-binary         output in binary form\n");
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
LAB_000171a4:
  OPENSSL_cleanse(ptr,0x2000);
  iVar18 = 1;
  CRYPTO_free(ptr);
  local_b0 = (BIO *)0x0;
  ptr = st;
  b = (BIO *)0x0;
  bp = (BIO *)0x0;
LAB_000171c2:
  if (local_60 != (void *)0x0) {
    CRYPTO_free(local_60);
  }
  BIO_free_all(local_b0);
  EVP_PKEY_free((EVP_PKEY *)local_64);
  if (local_ac != (BIO *)0x0) {
    sk_free((_STACK *)local_ac);
  }
  if (ptr != (BIO *)0x0) {
    sk_free((_STACK *)ptr);
  }
  if (b != (BIO *)0x0) {
    CRYPTO_free(b);
  }
  if (bp != (BIO *)0x0) {
    BIO_free(bp);
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar18);
}

