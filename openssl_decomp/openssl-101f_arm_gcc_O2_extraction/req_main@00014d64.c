
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void req_main(int param_1,undefined4 *param_2)

{
  uchar *bytes;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  X509 *pXVar9;
  BIO *in;
  X509 *pXVar10;
  BIO_METHOD *pBVar11;
  X509 *bp;
  long lVar12;
  EVP_MD *pEVar13;
  X509_NAME *pXVar14;
  ulong uVar15;
  ASN1_TIME *pAVar16;
  EVP_PKEY *pkey;
  ASN1_INTEGER *pAVar17;
  byte *pbVar18;
  X509 *section;
  void *pvVar19;
  int iVar20;
  char *pcVar21;
  size_t sVar22;
  char *pcVar23;
  int iVar24;
  byte bVar25;
  byte *pbVar26;
  undefined4 uVar27;
  X509_CINF *pXVar28;
  X509 *pXVar29;
  uint uVar30;
  char **ppcVar31;
  char **ppcVar32;
  char *pcVar33;
  X509 *pXVar34;
  int iVar35;
  EVP_MD *pEVar36;
  bool bVar37;
  X509 *local_580;
  X509 *local_57c;
  X509 *local_574;
  X509 *local_570;
  _STACK *local_56c;
  _STACK *local_568;
  char *local_564;
  char *local_560;
  ASN1_INTEGER *local_55c;
  char *local_558;
  X509 *local_554;
  X509 *local_550;
  char *local_54c;
  EVP_CIPHER *local_548;
  X509 *local_540;
  char *local_53c;
  uint local_538;
  EVP_MD *local_534;
  char *local_530;
  X509 *local_52c;
  int local_528;
  X509 *local_524;
  char *local_520;
  char *local_518;
  uint local_510;
  int local_504;
  uint local_500;
  undefined4 local_4fc;
  long local_4f8;
  uint local_4f4;
  ulong local_4d4;
  ulong local_4d0;
  void *local_4cc;
  X509 *local_4c8;
  int local_4c4;
  int local_4c0;
  char *local_4bc;
  char *local_4b8;
  long local_4b4;
  X509V3_CTX local_4b0;
  char acStack_494 [99];
  uchar auStack_431 [1029];
  int local_2c;
  
  local_2c = __TMC_END__;
  local_4c4 = -1;
  req_conf = (CONF *)0x0;
  local_4d4 = 0;
  local_4d0 = 0;
  local_4cc = (void *)0x0;
  local_4c8 = (X509 *)0x0;
  local_4bc = (char *)0x0;
  local_4b8 = (char *)0x0;
  local_4c0 = -1;
  local_548 = EVP_des_ede3_cbc();
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar11 = BIO_s_file();
    bio_err = BIO_new(pBVar11);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  param_1 = param_1 + -1;
  ppcVar31 = (char **)(param_2 + 1);
  uVar27 = *param_2;
  iVar24 = 3;
  pEVar36 = (EVP_MD *)0x0;
  local_570 = (X509 *)0x3;
  if (param_1 < 1) {
    local_4fc = 0;
    local_54c = (char *)0x0;
    iVar35 = 3;
    local_560 = (char *)0x0;
    local_564 = (char *)0x0;
    local_520 = (char *)0x0;
    bVar5 = false;
    local_55c = (ASN1_INTEGER *)0x0;
    local_524 = (X509 *)0x0;
    local_52c = (X509 *)0x0;
    local_580 = (X509 *)0x0;
    local_530 = (char *)0x0;
    local_550 = (X509 *)0x0;
    local_558 = (char *)0x0;
    local_518 = (char *)0x0;
    local_53c = (char *)0x0;
    bVar4 = false;
    bVar3 = false;
    bVar6 = false;
    local_504 = 0;
    bVar7 = false;
    local_500 = 0;
    local_510 = 0;
    local_4f4 = 0;
    bVar2 = false;
    local_554 = (X509 *)0x0;
    local_568 = (_STACK *)0x0;
    local_56c = (_STACK *)0x0;
    local_540 = (X509 *)0x0;
    local_538 = 0;
    local_57c = (X509 *)0x0;
    local_534 = (EVP_MD *)0x0;
    local_528 = 0x1001;
    local_4f8 = 0x1e;
  }
  else {
    local_534 = (EVP_MD *)0x0;
    iVar24 = 3;
    local_4fc = 0;
    iVar35 = 3;
    local_54c = (char *)0x0;
    local_560 = (char *)0x0;
    local_564 = (char *)0x0;
    local_520 = (char *)0x0;
    bVar5 = false;
    local_55c = (ASN1_INTEGER *)0x0;
    local_524 = (X509 *)0x0;
    local_52c = (X509 *)0x0;
    local_580 = (X509 *)0x0;
    local_530 = (char *)0x0;
    local_550 = (X509 *)0x0;
    local_558 = (char *)0x0;
    local_518 = (char *)0x0;
    local_53c = (char *)0x0;
    bVar4 = false;
    bVar3 = false;
    bVar6 = false;
    local_504 = 0;
    bVar7 = false;
    local_500 = 0;
    local_510 = 0;
    local_4f4 = 0;
    bVar2 = false;
    local_554 = (X509 *)0x0;
    local_568 = (_STACK *)0x0;
    local_56c = (_STACK *)0x0;
    local_540 = (X509 *)0x0;
    local_538 = 0;
    local_57c = (X509 *)0x0;
    local_528 = 0x1001;
    local_4f8 = 0x1e;
LAB_00014e7c:
    do {
      pcVar33 = *ppcVar31;
      iVar8 = strcmp(pcVar33,"-inform");
      iVar20 = local_504;
      if (iVar8 == 0) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          iVar35 = str2fmt(ppcVar31[1]);
          ppcVar32 = ppcVar31 + 1;
          goto LAB_00014e74;
        }
LAB_00014fca:
        BIO_printf(bio_err,"%s [options] <infile >outfile\n",uVar27);
        BIO_printf(bio_err,"where options  are\n");
        BIO_printf(bio_err," -inform arg    input format - DER or PEM\n");
        BIO_printf(bio_err," -outform arg   output format - DER or PEM\n");
        BIO_printf(bio_err," -in arg        input file\n");
        BIO_printf(bio_err," -out arg       output file\n");
        BIO_printf(bio_err," -text          text form of request\n");
        BIO_printf(bio_err," -pubkey        output public key\n");
        BIO_printf(bio_err," -noout         do not output REQ\n");
        BIO_printf(bio_err," -verify        verify signature on REQ\n");
        BIO_printf(bio_err," -modulus       RSA modulus\n");
        BIO_printf(bio_err," -nodes         don\'t encrypt the output key\n");
        BIO_printf(bio_err," -engine e      use engine e, possibly a hardware device\n");
        BIO_printf(bio_err," -subject       output the request\'s subject\n");
        BIO_printf(bio_err," -passin        private key password source\n");
        BIO_printf(bio_err," -key file      use the private key contained in file\n");
        BIO_printf(bio_err," -keyform arg   key file format\n");
        BIO_printf(bio_err," -keyout arg    file to send the key to\n");
        BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
        BIO_printf(bio_err,"                load the file (or the files in the directory) into\n");
        BIO_printf(bio_err,"                the random number generator\n");
        BIO_printf(bio_err," -newkey rsa:bits generate a new RSA key of \'bits\' in size\n");
        BIO_printf(bio_err,
                   " -newkey dsa:file generate a new DSA key, parameters taken from CA in \'file\'\n"
                  );
        BIO_printf(bio_err,
                   " -newkey ec:file generate a new EC key, parameters taken from CA in \'file\'\n")
        ;
        BIO_printf(bio_err," -[digest]      Digest to sign with (md5, sha1, md2, mdc2, md4)\n");
        BIO_printf(bio_err," -config file   request template file.\n");
        BIO_printf(bio_err," -subj arg      set or modify request subject\n");
        BIO_printf(bio_err," -multivalue-rdn enable support for multivalued RDNs\n");
        BIO_printf(bio_err," -new           new request.\n");
        BIO_printf(bio_err," -batch         do not ask anything during request generation\n");
        BIO_printf(bio_err," -x509          output a x509 structure instead of a cert. req.\n");
        BIO_printf(bio_err,
                   " -days          number of days a certificate generated by -x509 is valid for.\n"
                  );
        BIO_printf(bio_err,
                   " -set_serial    serial number to use for a certificate generated by -x509.\n");
        BIO_printf(bio_err," -newhdr        output \"NEW\" in the header lines\n");
        BIO_printf(bio_err,
                   " -asn1-kludge   Output the \'request\' in a format that is wrong but some CA\'s\n"
                  );
        BIO_printf(bio_err,"                have been reported as requiring\n");
        BIO_printf(bio_err,
                   " -extensions .. specify certificate extension section (override value in config file)\n"
                  );
        BIO_printf(bio_err,
                   " -reqexts ..    specify request extension section (override value in config file)\n"
                  );
        BIO_printf(bio_err," -utf8          input characters are UTF8 (default ASCII)\n");
        BIO_printf(bio_err," -nameopt arg    - various certificate name options\n");
        pXVar9 = (X509 *)0x0;
        pcVar33 = " -reqopt arg    - various request text options\n\n";
        goto LAB_00015260;
      }
      iVar8 = strcmp(pcVar33,"-outform");
      if (iVar8 == 0) {
        if (param_1 == 1) goto LAB_00014fca;
        param_1 = param_1 + -2;
        iVar24 = str2fmt(ppcVar31[1]);
        ppcVar31 = ppcVar31 + 2;
        if (param_1 < 1) break;
        goto LAB_00014e7c;
      }
      iVar8 = strcmp(pcVar33,"-engine");
      if (iVar8 == 0) {
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_00014fca;
        local_580 = (X509 *)ppcVar31[1];
        ppcVar32 = ppcVar31 + 1;
      }
      else {
        iVar8 = strcmp(pcVar33,"-keygen_engine");
        if (iVar8 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00014fca;
          local_57c = (X509 *)ENGINE_by_id(ppcVar31[1]);
          ppcVar32 = ppcVar31 + 1;
          if (local_57c == (X509 *)0x0) {
            BIO_printf(bio_err,"Can\'t find keygen engine %s\n",ppcVar31[1]);
            pXVar9 = local_57c;
            pXVar10 = local_57c;
            bp = local_57c;
            pXVar34 = local_57c;
            local_574 = local_57c;
            goto LAB_00015270;
          }
        }
        else {
          iVar8 = strcmp(pcVar33,"-key");
          if (iVar8 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00014fca;
            local_558 = ppcVar31[1];
            ppcVar32 = ppcVar31 + 1;
          }
          else {
            iVar8 = strcmp(pcVar33,"-pubkey");
            ppcVar32 = ppcVar31;
            if (iVar8 == 0) {
              bVar4 = true;
            }
            else {
              iVar8 = strcmp(pcVar33,"-new");
              if (iVar8 != 0) {
                iVar8 = strcmp(pcVar33,"-config");
                if (iVar8 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 != 0) {
                    local_550 = (X509 *)ppcVar31[1];
                    ppcVar32 = ppcVar31 + 1;
                    goto LAB_00014e74;
                  }
                }
                else {
                  iVar8 = strcmp(pcVar33,"-keyform");
                  if (iVar8 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      local_570 = (X509 *)str2fmt(ppcVar31[1]);
                      ppcVar32 = ppcVar31 + 1;
                      goto LAB_00014e74;
                    }
                  }
                  else if ((((*pcVar33 == '-') && (pcVar33[1] == 'i')) && (pcVar33[2] == 'n')) &&
                          (pcVar33[3] == '\0')) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      local_53c = ppcVar31[1];
                      ppcVar32 = ppcVar31 + 1;
                      goto LAB_00014e74;
                    }
                  }
                  else {
                    iVar8 = strcmp(pcVar33,"-out");
                    if (iVar8 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_518 = ppcVar31[1];
                        ppcVar32 = ppcVar31 + 1;
                        goto LAB_00014e74;
                      }
                    }
                    else {
                      iVar8 = strcmp(pcVar33,"-keyout");
                      if (iVar8 == 0) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          local_530 = ppcVar31[1];
                          ppcVar32 = ppcVar31 + 1;
                          goto LAB_00014e74;
                        }
                      }
                      else {
                        iVar8 = strcmp(pcVar33,"-passin");
                        if (iVar8 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_564 = ppcVar31[1];
                            ppcVar32 = ppcVar31 + 1;
                            goto LAB_00014e74;
                          }
                        }
                        else {
                          iVar8 = strcmp(pcVar33,"-passout");
                          if (iVar8 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_560 = ppcVar31[1];
                              ppcVar32 = ppcVar31 + 1;
                              goto LAB_00014e74;
                            }
                          }
                          else {
                            iVar8 = strcmp(pcVar33,"-rand");
                            if (iVar8 == 0) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_520 = ppcVar31[1];
                                ppcVar32 = ppcVar31 + 1;
                                goto LAB_00014e74;
                              }
                            }
                            else {
                              iVar8 = strcmp(pcVar33,"-newkey");
                              if (iVar8 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_540 = (X509 *)ppcVar31[1];
                                  local_554 = (X509 *)0x1;
                                  ppcVar32 = ppcVar31 + 1;
                                  goto LAB_00014e74;
                                }
                              }
                              else {
                                iVar8 = strcmp(pcVar33,"-pkeyopt");
                                if (iVar8 == 0) {
                                  if ((param_1 != 1) &&
                                     ((local_56c != (_STACK *)0x0 ||
                                      (local_56c = sk_new_null(), local_56c != (_STACK *)0x0)))) {
                                    pAVar17 = (ASN1_INTEGER *)sk_push(local_56c,ppcVar31[1]);
joined_r0x00016dc0:
                                    param_1 = param_1 + -1;
                                    ppcVar32 = ppcVar31 + 1;
                                    iVar20 = local_504;
                                    if (pAVar17 != (ASN1_INTEGER *)0x0) goto LAB_00014e74;
                                  }
                                }
                                else {
                                  iVar8 = strcmp(pcVar33,"-sigopt");
                                  if (iVar8 != 0) {
                                    iVar8 = strcmp(pcVar33,"-batch");
                                    if (iVar8 == 0) {
                                      batch = 1;
                                    }
                                    else {
                                      iVar8 = strcmp(pcVar33,"-newhdr");
                                      if (iVar8 == 0) {
                                        bVar6 = true;
                                      }
                                      else {
                                        iVar8 = strcmp(pcVar33,"-modulus");
                                        if (iVar8 == 0) {
                                          bVar5 = true;
                                        }
                                        else {
                                          iVar8 = strcmp(pcVar33,"-verify");
                                          if (iVar8 == 0) {
                                            local_4f4 = 1;
                                          }
                                          else {
                                            iVar8 = strcmp(pcVar33,"-nodes");
                                            if (iVar8 == 0) {
                                              bVar7 = true;
                                            }
                                            else {
                                              iVar8 = strcmp(pcVar33,"-noout");
                                              if (iVar8 == 0) {
                                                local_510 = 1;
                                              }
                                              else {
                                                iVar8 = strcmp(pcVar33,"-verbose");
                                                if (iVar8 == 0) {
                                                  bVar2 = true;
                                                }
                                                else {
                                                  iVar8 = strcmp(pcVar33,"-utf8");
                                                  if (iVar8 != 0) {
                                                    iVar8 = strcmp(pcVar33,"-nameopt");
                                                    if (iVar8 == 0) {
                                                      if (param_1 != 1) {
                                                        pAVar17 = (ASN1_INTEGER *)
                                                                  set_name_ex(&local_4d4,ppcVar31[1]
                                                                             );
                                                        goto joined_r0x00016dc0;
                                                      }
                                                    }
                                                    else {
                                                      iVar8 = strcmp(pcVar33,"-reqopt");
                                                      if (iVar8 != 0) {
                                                        iVar8 = strcmp(pcVar33,"-subject");
                                                        if (iVar8 == 0) {
                                                          bVar3 = true;
                                                        }
                                                        else {
                                                          iVar8 = strcmp(pcVar33,"-text");
                                                          if (iVar8 == 0) {
                                                            local_500 = 1;
                                                          }
                                                          else {
                                                            iVar8 = strcmp(pcVar33,"-x509");
                                                            if (iVar8 == 0) {
                                                              local_538 = 1;
                                                            }
                                                            else {
                                                              iVar20 = strcmp(pcVar33,"-asn1-kludge"
                                                                             );
                                                              if (iVar20 == 0) {
                                                                local_504 = 1;
                                                                iVar20 = local_504;
                                                              }
                                                              else {
                                                                iVar20 = strcmp(pcVar33,
                                                  "-no-asn1-kludge");
                                                  if (iVar20 != 0) {
                                                    iVar20 = strcmp(pcVar33,"-subj");
                                                    if (iVar20 == 0) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 == 0) goto LAB_00014fca;
                                                      local_54c = ppcVar31[1];
                                                      ppcVar32 = ppcVar31 + 1;
                                                      iVar20 = local_504;
                                                    }
                                                    else {
                                                      iVar20 = strcmp(pcVar33,"-multivalue-rdn");
                                                      if (iVar20 != 0) {
                                                        iVar20 = strcmp(pcVar33,"-days");
                                                        if (iVar20 == 0) {
                                                          param_1 = param_1 + -1;
                                                          if (param_1 != 0) {
                                                            local_4f8 = strtol(ppcVar31[1],
                                                                               (char **)0x0,10);
                                                            ppcVar32 = ppcVar31 + 1;
                                                            iVar20 = local_504;
                                                            if (local_4f8 == 0) {
                                                              local_4f8 = 0x1e;
                                                            }
                                                            goto LAB_00014e74;
                                                          }
                                                        }
                                                        else {
                                                          iVar20 = strcmp(pcVar33,"-set_serial");
                                                          if (iVar20 == 0) {
                                                            if (param_1 != 1) {
                                                              local_55c = s2i_ASN1_INTEGER((
                                                  X509V3_EXT_METHOD *)0x0,ppcVar31[1]);
                                                  pAVar17 = local_55c;
                                                  goto joined_r0x00016dc0;
                                                  }
                                                  }
                                                  else {
                                                    iVar20 = strcmp(pcVar33,"-extensions");
                                                    if (iVar20 == 0) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 != 0) {
                                                        local_52c = (X509 *)ppcVar31[1];
                                                        ppcVar32 = ppcVar31 + 1;
                                                        iVar20 = local_504;
                                                        goto LAB_00014e74;
                                                      }
                                                    }
                                                    else {
                                                      iVar20 = strcmp(pcVar33,"-reqexts");
                                                      if (iVar20 == 0) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 != 0) {
                                                          local_524 = (X509 *)ppcVar31[1];
                                                          ppcVar32 = ppcVar31 + 1;
                                                          iVar20 = local_504;
                                                          goto LAB_00014e74;
                                                        }
                                                      }
                                                      else {
                                                        pEVar36 = EVP_get_digestbyname(pcVar33 + 1);
                                                        local_534 = pEVar36;
                                                        iVar20 = local_504;
                                                        if (pEVar36 != (EVP_MD *)0x0)
                                                        goto LAB_00014e74;
                                                        BIO_printf(bio_err,"unknown option %s\n",
                                                                   *ppcVar31);
                                                      }
                                                    }
                                                  }
                                                  }
                                                  goto LAB_00014fca;
                                                  }
                                                  local_4fc = 1;
                                                  iVar20 = local_504;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00014e74;
                                                  }
                                                  if (param_1 != 1) {
                                                    pAVar17 = (ASN1_INTEGER *)
                                                              set_cert_ex(&local_4d0,ppcVar31[1]);
                                                    goto joined_r0x00016dc0;
                                                  }
                                                  }
                                                  goto LAB_00014fca;
                                                  }
                                                  local_528 = 0x1000;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                    goto LAB_00014e74;
                                  }
                                  if ((param_1 != 1) &&
                                     ((local_568 != (_STACK *)0x0 ||
                                      (local_568 = sk_new_null(), local_568 != (_STACK *)0x0)))) {
                                    pAVar17 = (ASN1_INTEGER *)sk_push(local_568,ppcVar31[1]);
                                    goto joined_r0x00016dc0;
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
                goto LAB_00014fca;
              }
              local_554 = (X509 *)0x1;
            }
          }
        }
      }
LAB_00014e74:
      local_504 = iVar20;
      param_1 = param_1 + -1;
      ppcVar31 = ppcVar32 + 1;
    } while (0 < param_1);
  }
  ERR_load_crypto_strings();
  pXVar9 = (X509 *)app_passwd(bio_err,local_564,local_560,&local_4bc,&local_4b8);
  if (pXVar9 == (X509 *)0x0) {
    pcVar33 = "Error getting passwords\n";
LAB_00015260:
    BIO_printf(bio_err,pcVar33);
    pXVar10 = pXVar9;
    bp = pXVar9;
    pXVar34 = pXVar9;
    local_574 = pXVar9;
  }
  else if (local_550 == (X509 *)0x0) {
    req_conf = config;
    if (config == (CONF *)0x0) {
      BIO_printf(bio_err,"Unable to load config info from %s\n",default_config_file);
      if (local_554 != (X509 *)0x0) {
        local_574 = local_550;
        local_580 = local_550;
        pXVar9 = local_550;
        pXVar10 = local_550;
        bp = local_550;
        pXVar34 = local_580;
        goto LAB_00015270;
      }
LAB_00014f12:
      if (req_conf != (CONF *)0x0) goto LAB_00014f1a;
    }
    else {
      if (bVar2) {
        BIO_printf(bio_err,"Using configuration from %s\n",default_config_file);
        goto LAB_00014f12;
      }
LAB_00014f1a:
      pXVar9 = (X509 *)load_config(bio_err);
      pXVar10 = pXVar9;
      bp = pXVar9;
      pXVar34 = pXVar9;
      local_574 = pXVar9;
      if (pXVar9 == (X509 *)0x0) goto LAB_00015270;
      pcVar33 = NCONF_get_string(req_conf,(char *)0x0,"oid_file");
      if (pcVar33 == (char *)0x0) {
        ERR_clear_error();
      }
      else {
        in = BIO_new_file(pcVar33,"r");
        if (in != (BIO *)0x0) {
          OBJ_create_objects(in);
          BIO_free(in);
        }
      }
    }
    pXVar9 = (X509 *)add_oid_section(bio_err,req_conf);
    pXVar10 = pXVar9;
    bp = pXVar9;
    pXVar34 = pXVar9;
    local_574 = pXVar9;
    if (pXVar9 != (X509 *)0x0) {
      if (local_534 == (EVP_MD *)0x0) {
        pcVar33 = NCONF_get_string(req_conf,"req","default_md");
        if (pcVar33 == (char *)0x0) {
          ERR_clear_error();
        }
        else {
          pEVar13 = EVP_get_digestbyname(pcVar33);
          if (pEVar13 != (EVP_MD *)0x0) {
            pEVar36 = pEVar13;
          }
        }
      }
      if ((local_52c == (X509 *)0x0) &&
         (local_52c = (X509 *)NCONF_get_string(req_conf,"req","x509_extensions"),
         local_52c == (X509 *)0x0)) {
        ERR_clear_error();
LAB_0001546e:
        if ((local_4bc == (char *)0x0) &&
           (local_4bc = NCONF_get_string(req_conf,"req","input_password"), local_4bc == (char *)0x0)
           ) {
          ERR_clear_error();
        }
        if ((local_4b8 == (char *)0x0) &&
           (local_4b8 = NCONF_get_string(req_conf,"req","output_password"), local_4b8 == (char *)0x0
           )) {
          ERR_clear_error();
        }
        pXVar9 = (X509 *)NCONF_get_string(req_conf,"req","string_mask");
        if (pXVar9 == (X509 *)0x0) {
          ERR_clear_error();
        }
        else {
          pXVar10 = (X509 *)ASN1_STRING_set_default_mask_asc((char *)pXVar9);
          if (pXVar10 == (X509 *)0x0) {
            pcVar33 = "Invalid global string mask setting %s\n";
            goto LAB_0001579c;
          }
        }
        if (local_528 != 0x1000) {
          pcVar33 = NCONF_get_string(req_conf,"req","utf8");
          if (pcVar33 == (char *)0x0) {
            ERR_clear_error();
          }
          else if ((((*pcVar33 == 'y') && (pcVar33[1] == 'e')) && (pcVar33[2] == 's')) &&
                  (pcVar33[3] == '\0')) {
            local_528 = 0x1000;
          }
        }
        if ((local_524 == (X509 *)0x0) &&
           (local_524 = (X509 *)NCONF_get_string(req_conf,"req","req_extensions"),
           local_524 == (X509 *)0x0)) {
          ERR_clear_error();
        }
        else {
          pXVar9 = (X509 *)0x0;
          X509V3_set_ctx(&local_4b0,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,(X509_CRL *)0x0,1);
          X509V3_set_nconf(&local_4b0,req_conf);
          pXVar10 = (X509 *)X509V3_EXT_add_nconf(req_conf,&local_4b0,(char *)local_524,(X509 *)0x0);
          if (pXVar10 == (X509 *)0x0) {
            pcVar33 = "Error Loading request extension section %s\n";
            pXVar9 = local_524;
            goto LAB_0001579c;
          }
        }
        pBVar11 = BIO_s_file();
        local_574 = (X509 *)BIO_new(pBVar11);
        pBVar11 = BIO_s_file();
        bp = (X509 *)BIO_new(pBVar11);
        bVar37 = local_574 == (X509 *)0x0;
        bVar1 = bp == (X509 *)0x0;
        if (bVar37 || bVar1) {
          pXVar9 = (X509 *)0x0;
        }
        local_550 = (X509 *)(uint)(bVar37 || bVar1);
        pXVar10 = pXVar9;
        pXVar34 = pXVar9;
        if (!bVar37 && !bVar1) {
          uVar27 = setup_engine(bio_err,local_580,local_550);
          if (local_558 != (char *)0x0) {
            local_4c8 = (X509 *)load_key(bio_err,local_558,local_570,local_550,local_4bc,uVar27,
                                         "Private Key");
            pXVar9 = local_4c8;
            pXVar10 = local_4c8;
            pXVar34 = local_4c8;
            if (local_4c8 == (X509 *)0x0) goto LAB_00015270;
            pcVar33 = NCONF_get_string(req_conf,"req","RANDFILE");
            if (pcVar33 == (char *)0x0) {
              ERR_clear_error();
            }
            app_RAND_load_file(pcVar33,bio_err,0);
          }
          local_580 = local_554;
          if (local_4c8 != (X509 *)0x0) {
            local_580 = (X509 *)0x0;
          }
          if (local_580 == (X509 *)0x0) {
            if (local_554 == (X509 *)0x0) {
              if (local_53c == (char *)0x0) {
                BIO_ctrl((BIO *)local_574,0x6a,0,stdin);
              }
              else {
                lVar12 = BIO_ctrl((BIO *)local_574,0x6c,3,local_53c);
                if (lVar12 < 1) {
                  perror(local_53c);
                  local_580 = local_554;
                  pXVar9 = local_554;
                  pXVar10 = local_554;
                  pXVar34 = local_580;
                  goto LAB_00015270;
                }
              }
              if (iVar35 == 1) {
                local_580 = (X509 *)d2i_X509_REQ_bio((BIO *)local_574,(X509_REQ **)0x0);
              }
              else {
                if (iVar35 != 3) {
                  BIO_printf(bio_err,"bad input format specified for X509 request\n");
                  local_580 = (X509 *)0x0;
                  pXVar9 = (X509 *)0x0;
                  pXVar10 = (X509 *)0x0;
                  pXVar34 = local_580;
                  goto LAB_00015270;
                }
                local_580 = (X509 *)PEM_read_bio_X509_REQ
                                              ((BIO *)local_574,(X509_REQ **)0x0,(undefined1 *)0x0,
                                               (void *)0x0);
              }
              if (local_580 == (X509 *)0x0) {
                BIO_printf(bio_err,"unable to load X509 request\n");
                pXVar9 = local_580;
                pXVar10 = local_580;
                pXVar34 = local_580;
                goto LAB_00015270;
              }
              local_504 = -1;
            }
LAB_00015914:
            pXVar9 = local_4c8;
            pXVar10 = (X509 *)((uint)local_554 | local_538);
            if (pXVar10 == (X509 *)0x0) {
LAB_00015d0a:
              local_550 = (X509 *)local_538;
              pcVar33 = local_54c;
              if (local_54c != (char *)0x0) {
                pcVar33 = (char *)0x1;
              }
              if (((uint)pcVar33 & local_538) == 0) {
LAB_000159b2:
                pXVar34 = local_580;
                if (((uint)pcVar33 & (local_538 ^ 1)) != 0) {
                  if (bVar2) {
                    BIO_printf(bio_err,"Modifying Request\'s Subject\n");
                    print_name(bio_err,"old subject=",local_580->cert_info->validity,local_4d4);
                  }
                  pXVar9 = (X509 *)build_subject(local_580,local_54c,local_528,local_4fc);
                  if (pXVar9 == (X509 *)0x0) {
                    BIO_printf(bio_err,"ERROR: cannot modify subject\n");
                    goto LAB_00015270;
                  }
                  pXVar28 = local_580->cert_info;
                  pXVar28->signature = (X509_ALGOR *)0x1;
                  if (bVar2) {
                    print_name(bio_err,"new subject=",pXVar28->validity,local_4d4);
                  }
                }
                pXVar29 = local_4c8;
                if (((local_538 ^ 1) & local_4f4) != 0) {
                  if (local_4c8 == (X509 *)0x0) {
                    pXVar9 = (X509 *)X509_REQ_get_pubkey((X509_REQ *)local_580);
                    local_4c8 = pXVar9;
                    if (pXVar9 == (X509 *)0x0) goto LAB_00015270;
                    iVar35 = X509_REQ_verify((X509_REQ *)local_580,(EVP_PKEY *)pXVar9);
                    EVP_PKEY_free((EVP_PKEY *)local_4c8);
                    local_4c8 = pXVar29;
                  }
                  else {
                    iVar35 = X509_REQ_verify((X509_REQ *)local_580,(EVP_PKEY *)local_4c8);
                  }
                  if (iVar35 < 0) {
LAB_00015950:
                    pXVar9 = (X509 *)0x0;
                    pXVar34 = local_580;
                    goto LAB_00015270;
                  }
                  if (iVar35 == 0) {
                    BIO_printf(bio_err,"verify failure\n");
                    ERR_print_errors(bio_err);
                  }
                  else {
                    BIO_printf(bio_err,"verify OK\n");
                  }
                }
                if (((local_510 & (local_500 ^ 1)) == 0) || ((bool)(bVar5 | bVar4 | bVar3))) {
                  if (local_518 == (char *)0x0) {
                    BIO_ctrl((BIO *)bp,0x6a,0,stdout);
                  }
                  else {
                    if ((local_530 == (char *)0x0) ||
                       (iVar35 = strcmp(local_518,local_530), iVar35 != 0)) {
                      pXVar9 = (X509 *)BIO_ctrl((BIO *)bp,0x6c,5,local_518);
                    }
                    else {
                      pXVar9 = (X509 *)BIO_ctrl((BIO *)bp,0x6c,9,local_518);
                    }
                    if (pXVar9 == (X509 *)0x0) {
                      perror(local_518);
                      goto LAB_00015270;
                    }
                  }
                  if (bVar4) {
                    pXVar9 = (X509 *)X509_REQ_get_pubkey((X509_REQ *)local_580);
                    if (pXVar9 == (X509 *)0x0) {
                      BIO_printf(bio_err,"Error getting public key\n");
                      ERR_print_errors(bio_err);
                      goto LAB_00015270;
                    }
                    PEM_write_bio_PUBKEY((BIO *)bp,(EVP_PKEY *)pXVar9);
                    EVP_PKEY_free((EVP_PKEY *)pXVar9);
                  }
                  if (local_500 == 0) {
                    if (bVar3) {
                      if (local_550 == (X509 *)0x0) goto LAB_00015c24;
LAB_00015ac6:
                      pXVar14 = X509_get_subject_name(pXVar10);
                      print_name(bp,"subject=",pXVar14,local_4d4);
                      if (bVar5) goto LAB_00015ae2;
                    }
                    else if (bVar5) {
                      if (local_550 != (X509 *)0x0) goto LAB_00015ae2;
                      goto LAB_00015c42;
                    }
                  }
                  else {
                    if (local_550 == (X509 *)0x0) {
                      X509_REQ_print_ex((BIO *)bp,(X509_REQ *)local_580,local_4d4,local_4d0);
                      if (bVar3) {
LAB_00015c24:
                        print_name(bp,"subject=",local_580->cert_info->validity,local_4d4);
                      }
                      if (!bVar5) goto LAB_00015b36;
LAB_00015c42:
                      pXVar9 = (X509 *)X509_REQ_get_pubkey((X509_REQ *)local_580);
                    }
                    else {
                      X509_print_ex((BIO *)bp,pXVar10,local_4d4,local_4d0);
                      if (bVar3) goto LAB_00015ac6;
                      if (!bVar5) goto LAB_00015b36;
LAB_00015ae2:
                      pXVar9 = (X509 *)X509_get_pubkey(pXVar10);
                    }
                    if (pXVar9 == (X509 *)0x0) {
                      fwrite("Modulus=unavailable\n",1,0x14,stdout);
                      goto LAB_00015270;
                    }
                    fwrite("Modulus=",1,8,stdout);
                    iVar35 = EVP_PKEY_base_id((EVP_PKEY *)pXVar9);
                    if (iVar35 == 6) {
                      BN_print(bp,*(BIGNUM **)(pXVar9->name + 0x10));
                    }
                    else {
                      fwrite("Wrong Algorithm type",1,0x14,stdout);
                    }
                    EVP_PKEY_free((EVP_PKEY *)pXVar9);
                    fputc(10,stdout);
                  }
LAB_00015b36:
                  if ((X509 *)(local_510 | local_538) == (X509 *)0x0) {
                    if (iVar24 == 1) {
                      pXVar9 = (X509 *)i2d_X509_REQ_bio((BIO *)bp,(X509_REQ *)local_580);
                    }
                    else {
                      if (iVar24 != 3) {
                        BIO_printf(bio_err,"bad output format specified for outfile\n");
                        pXVar9 = (X509 *)(local_510 | local_538);
                        goto LAB_00015270;
                      }
                      if (bVar6) {
                        pXVar9 = (X509 *)PEM_write_bio_X509_REQ_NEW((BIO *)bp,(X509_REQ *)local_580)
                        ;
                      }
                      else {
                        pXVar9 = (X509 *)PEM_write_bio_X509_REQ((BIO *)bp,(X509_REQ *)local_580);
                      }
                    }
                    if (pXVar9 == (X509 *)0x0) {
                      BIO_printf(bio_err,"unable to write X509 request\n");
                      goto LAB_00015270;
                    }
                  }
                  if ((((uint)local_550 & (local_510 ^ 1)) != 0) && (pXVar10 != (X509 *)0x0)) {
                    if (iVar24 == 1) {
                      pXVar9 = (X509 *)i2d_X509_bio((BIO *)bp,pXVar10);
                    }
                    else {
                      if (iVar24 != 3) {
                        BIO_printf(bio_err,"bad output format specified for outfile\n");
                        pXVar9 = (X509 *)0x0;
                        goto LAB_00015270;
                      }
                      pXVar9 = (X509 *)PEM_write_bio_X509((BIO *)bp,pXVar10);
                    }
                    if (pXVar9 == (X509 *)0x0) {
                      BIO_printf(bio_err,"unable to write X509 certificate\n");
                      goto LAB_00015270;
                    }
                  }
                }
                pXVar9 = (X509 *)0x0;
                pXVar34 = pXVar9;
                goto LAB_0001527a;
              }
              BIO_printf(bio_err,"Cannot modifiy certificate subject\n");
              pXVar9 = (X509 *)0x0;
              pXVar34 = local_580;
            }
            else if (local_4c8 == (X509 *)0x0) {
              BIO_printf(bio_err,"you need to specify a private key\n");
              pXVar10 = pXVar9;
              pXVar34 = local_580;
            }
            else if (local_580 == (X509 *)0x0) {
              local_580 = (X509 *)X509_REQ_new();
              pXVar29 = local_4c8;
              pXVar9 = local_580;
              pXVar10 = local_580;
              pXVar34 = local_580;
              if (local_580 != (X509 *)0x0) {
                pbVar18 = (byte *)NCONF_get_string(req_conf,"req","prompt");
                if (pbVar18 == (byte *)0x0) {
                  ERR_clear_error();
                }
                else {
                  iVar35 = 0x6e - (uint)*pbVar18;
                  if ((iVar35 == 0) && (iVar35 = 0x6f - (uint)pbVar18[1], iVar35 == 0)) {
                    iVar35 = -(uint)pbVar18[2];
                  }
                  uVar30 = count_leading_zeroes(iVar35);
                  pbVar18 = (byte *)(uVar30 >> 5);
                }
                pXVar9 = (X509 *)NCONF_get_string(req_conf,"req","distinguished_name");
                if (pXVar9 == (X509 *)0x0) {
                  BIO_printf(bio_err,"unable to find \'%s\' in config\n","distinguished_name");
                }
                else {
                  pXVar10 = (X509 *)NCONF_get_section(req_conf,(char *)pXVar9);
                  if (pXVar10 == (X509 *)0x0) {
                    BIO_printf(bio_err,"unable to get \'%s\' section\n",pXVar9);
                    pXVar9 = pXVar10;
                  }
                  else {
                    section = (X509 *)NCONF_get_string(req_conf,"req","attributes");
                    if (section == (X509 *)0x0) {
                      ERR_clear_error();
                      local_570 = section;
                    }
                    else {
                      local_570 = (X509 *)NCONF_get_section(req_conf,(char *)section);
                      if (local_570 == (X509 *)0x0) {
                        BIO_printf(bio_err,"unable to get \'%s\' section\n",section);
                        pXVar9 = local_570;
                        goto LAB_000162c6;
                      }
                    }
                    iVar35 = X509_REQ_set_version((X509_REQ *)local_580,0);
                    if (iVar35 != 0) {
                      if (pbVar18 == (byte *)0x0) {
                        if (local_54c == (char *)0x0) {
                          pXVar14 = (X509_NAME *)local_580->cert_info->validity;
                          if (batch == 0) {
                            BIO_printf(bio_err,
                                       "You are about to be asked to enter information that will be incorporated\n"
                                      );
                            BIO_printf(bio_err,"into your certificate request.\n");
                            BIO_printf(bio_err,
                                       "What you are about to enter is what is called a Distinguished Name or a DN.\n"
                                      );
                            BIO_printf(bio_err,
                                       "There are quite a few fields but you can leave some blank\n"
                                      );
                            BIO_printf(bio_err,"For some fields there will be a default value,\n");
                            BIO_printf(bio_err,"If you enter \'.\', the field will be left blank.\n"
                                      );
                            BIO_printf(bio_err,"-----\n");
                          }
                          iVar35 = sk_num((_STACK *)pXVar10);
                          if (iVar35 != 0) {
                            local_53c = (char *)0xffffffff;
LAB_000164bc:
                            do {
                              do {
                                do {
                                  local_53c = (char *)((int)local_53c + 1);
                                  iVar35 = sk_num((_STACK *)pXVar10);
                                  if (iVar35 <= (int)local_53c) {
                                    iVar35 = X509_NAME_entry_count(pXVar14);
                                    if (iVar35 == 0) goto LAB_0001689a;
                                    if (((local_538 ^ 1) == 0) || (local_570 == (X509 *)0x0))
                                    goto LAB_00016368;
                                    iVar35 = sk_num((_STACK *)local_570);
                                    if ((iVar35 < 1) || (batch != 0)) {
                                      if (local_570 == (X509 *)0x0) goto LAB_00016368;
                                    }
                                    else {
                                      BIO_printf(bio_err,
                                                 "\nPlease enter the following \'extra\' attributes\n"
                                                );
                                      BIO_printf(bio_err,
                                                 "to be sent with your certificate request\n");
                                    }
                                    local_540 = (X509 *)0x0;
                                    goto LAB_0001686c;
                                  }
                                  pvVar19 = sk_value((_STACK *)pXVar10,(int)local_53c);
                                  pbVar18 = *(byte **)((int)pvVar19 + 4);
                                  iVar35 = check_end(pbVar18,&DAT_00126aa8);
                                } while ((((iVar35 == 0) ||
                                          (iVar35 = check_end(pbVar18,&DAT_00126ab0), iVar35 == 0))
                                         || (iVar35 = check_end(pbVar18,"_default"), iVar35 == 0))
                                        || (iVar35 = check_end(pbVar18,"_value"), iVar35 == 0));
                                local_534 = (EVP_MD *)(uint)*pbVar18;
                                if (local_534 != (EVP_MD *)0x0) {
                                  pbVar26 = pbVar18;
                                  if (local_534 != (EVP_MD *)0x3a &&
                                      ((uint)local_534 & 0xfd) != 0x2c) {
                                    do {
                                      pbVar26 = pbVar26 + 1;
                                      bVar25 = *pbVar26;
                                      if (bVar25 == 0) goto LAB_0001655c;
                                    } while (bVar25 != 0x3a && (bVar25 & 0xfd) != 0x2c);
                                  }
                                  if (pbVar26[1] != 0) {
                                    local_534 = (EVP_MD *)(uint)pbVar26[1];
                                    pbVar18 = pbVar26 + 1;
                                  }
LAB_0001655c:
                                  if (local_534 == (EVP_MD *)0x2b) {
                                    pbVar18 = pbVar18 + 1;
                                    local_534 = (EVP_MD *)0xffffffff;
                                  }
                                  else {
                                    local_534 = (EVP_MD *)0x0;
                                  }
                                }
                                iVar35 = OBJ_txt2nid((char *)pbVar18);
                              } while (iVar35 == 0);
                              iVar20 = BIO_snprintf(acStack_494,100,"%s_default",
                                                    *(undefined4 *)((int)pvVar19 + 4));
                              if (99 < iVar20) {
                                BIO_printf(bio_err,"Name \'%s\' too long\n",
                                           *(undefined4 *)((int)pvVar19 + 4));
                                goto LAB_000162c4;
                              }
                              pcVar33 = NCONF_get_string(req_conf,(char *)pXVar9,acStack_494);
                              if (pcVar33 == (char *)0x0) {
                                ERR_clear_error();
                                pcVar33 = "";
                              }
                              BIO_snprintf(acStack_494,100,"%s_value",
                                           *(undefined4 *)((int)pvVar19 + 4));
                              pcVar21 = NCONF_get_string(req_conf,(char *)pXVar9,acStack_494);
                              if (pcVar21 == (char *)0x0) {
                                ERR_clear_error();
                              }
                              BIO_snprintf(acStack_494,100,"%s_min",
                                           *(undefined4 *)((int)pvVar19 + 4));
                              iVar20 = NCONF_get_number_e(req_conf,(char *)pXVar9,acStack_494,
                                                          &local_4b4);
                              if (iVar20 == 0) {
                                ERR_clear_error();
                                local_4b4 = -1;
                              }
                              BIO_snprintf(acStack_494,100,"%s_max",
                                           *(undefined4 *)((int)pvVar19 + 4));
                              iVar20 = NCONF_get_number_e(req_conf,(char *)pXVar9,acStack_494,
                                                          &local_4b0.flags);
                              if (iVar20 == 0) {
                                ERR_clear_error();
                                local_4b0.flags = -1;
                              }
                              iVar20 = local_4b0.flags;
                              lVar12 = local_4b4;
                              uVar27 = *(undefined4 *)((int)pvVar19 + 8);
                              bytes = auStack_431 + 1;
                              do {
                                if (batch == 0) {
                                  BIO_printf(bio_err,"%s [%s]:",uVar27,pcVar33);
                                }
                                BIO_ctrl(bio_err,0xb,0,(void *)0x0);
                                if (pcVar21 == (char *)0x0) {
                                  auStack_431[1] = '\0';
                                  if (batch == 0) {
                                    pcVar23 = fgets((char *)bytes,0x400,stdin);
                                    if (pcVar23 != (char *)0x0) goto LAB_000166aa;
                                    goto LAB_000162c4;
                                  }
                                  auStack_431[2] = '\0';
                                  auStack_431[1] = '\n';
LAB_000167d0:
                                  if (*pcVar33 == '\0') goto LAB_000164bc;
                                  BUF_strlcpy((char *)bytes,pcVar33,0x400);
                                  BUF_strlcat((char *)bytes,"\n",0x400);
                                }
                                else {
                                  BUF_strlcpy((char *)bytes,pcVar21,0x400);
                                  BUF_strlcat((char *)bytes,"\n",0x400);
                                  BIO_printf(bio_err,"%s\n",pcVar21);
LAB_000166aa:
                                  if (auStack_431[1] == '\0') goto LAB_000162c4;
                                  if (auStack_431[1] == '\n') goto LAB_000167d0;
                                  if ((auStack_431[1] == '.') && (auStack_431[2] == '\n'))
                                  goto LAB_000164bc;
                                }
                                sVar22 = strlen((char *)bytes);
                                iVar8 = sVar22 - 1;
                                if (bytes[iVar8] != '\n') {
                                  BIO_printf(bio_err,"weird input :-(\n");
                                  goto LAB_000162c4;
                                }
                                bytes[iVar8] = '\0';
                                iVar8 = req_check_len(iVar8,lVar12,iVar20);
                              } while (iVar8 == 0);
                              iVar35 = X509_NAME_add_entry_by_NID
                                                 (pXVar14,iVar35,local_528,bytes,-1,-1,
                                                  (int)local_534);
                              if (iVar35 == 0) goto LAB_000162c4;
                            } while( true );
                          }
                          BIO_printf(bio_err,"No template, please set one up.\n");
                        }
                        else {
                          iVar35 = build_subject(local_580,local_54c,local_528,local_4fc);
                          if (iVar35 != 0) goto LAB_00016368;
                        }
                      }
                      else {
                        pXVar14 = (X509_NAME *)local_580->cert_info->validity;
                        for (iVar35 = 0; iVar20 = sk_num((_STACK *)pXVar10), iVar35 < iVar20;
                            iVar35 = iVar35 + 1) {
                          pvVar19 = sk_value((_STACK *)pXVar10,iVar35);
                          pbVar18 = *(byte **)((int)pvVar19 + 4);
                          bVar25 = *pbVar18;
                          if (bVar25 != 0) {
                            pbVar26 = pbVar18;
                            if (bVar25 != 0x3a && (bVar25 & 0xfd) != 0x2c) {
                              do {
                                pbVar26 = pbVar26 + 1;
                                bVar25 = *pbVar26;
                                if (bVar25 == 0) goto LAB_0001675a;
                              } while (bVar25 != 0x3a && (bVar25 & 0xfd) != 0x2c);
                            }
                            bVar25 = pbVar26[1];
                            if (bVar25 != 0) {
                              pbVar18 = pbVar26 + 1;
                            }
                          }
LAB_0001675a:
                          iVar20 = -1;
                          if (bVar25 != 0x2b) {
                            iVar20 = 0;
                          }
                          iVar20 = X509_NAME_add_entry_by_txt
                                             (pXVar14,(char *)pbVar18,local_528,
                                              *(uchar **)((int)pvVar19 + 8),-1,-1,iVar20);
                          if (iVar20 == 0) goto LAB_000162c4;
                        }
                        iVar35 = X509_NAME_entry_count(pXVar14);
                        if (iVar35 != 0) {
                          if ((local_538 ^ 1) != 0) {
                            for (iVar35 = 0; iVar20 = sk_num((_STACK *)local_570), iVar35 < iVar20;
                                iVar35 = iVar35 + 1) {
                              pvVar19 = sk_value((_STACK *)local_570,iVar35);
                              iVar20 = X509_REQ_add1_attr_by_txt
                                                 ((X509_REQ *)local_580,*(char **)((int)pvVar19 + 4)
                                                  ,local_528,*(uchar **)((int)pvVar19 + 8),-1);
                              if (iVar20 == 0) goto LAB_000162c4;
                            }
                          }
LAB_00016368:
                          pXVar9 = (X509 *)X509_REQ_set_pubkey((X509_REQ *)local_580,
                                                               (EVP_PKEY *)pXVar29);
                          if (pXVar9 != (X509 *)0x0) {
                            pXVar9 = (X509 *)0x1;
                          }
                          goto LAB_000162c6;
                        }
LAB_0001689a:
                        BIO_printf(bio_err,"error, no objects specified in config file\n");
                      }
                    }
LAB_000162c4:
                    pXVar9 = (X509 *)0x0;
                  }
                }
LAB_000162c6:
                if ((0 < local_504) &&
                   (iVar35 = sk_num((_STACK *)local_580->cert_info->key), iVar35 == 0)) {
                  sk_free((_STACK *)local_580->cert_info->key);
                  local_580->cert_info->key = (X509_PUBKEY *)0x0;
                }
                if (pXVar9 != (X509 *)0x0) {
                  local_54c = (char *)0x0;
                  goto LAB_00015930;
                }
                BIO_printf(bio_err,"problems making Certificate Request\n");
                pXVar10 = pXVar9;
              }
            }
            else {
LAB_00015930:
              if (local_538 != 0) {
                pXVar10 = X509_new();
                if ((pXVar10 != (X509 *)0x0) &&
                   ((local_52c == (X509 *)0x0 || (iVar35 = X509_set_version(pXVar10,2), iVar35 != 0)
                    ))) {
                  if (local_55c == (ASN1_INTEGER *)0x0) {
                    pAVar17 = X509_get_serialNumber(pXVar10);
                    iVar35 = rand_serial(0,pAVar17);
                  }
                  else {
                    iVar35 = X509_set_serialNumber(pXVar10,local_55c);
                  }
                  if ((((iVar35 != 0) &&
                       (iVar35 = X509_set_issuer_name
                                           (pXVar10,(X509_NAME *)local_580->cert_info->validity),
                       iVar35 != 0)) &&
                      (pAVar16 = X509_gmtime_adj(pXVar10->cert_info->validity->notBefore,0),
                      pAVar16 != (ASN1_TIME *)0x0)) &&
                     (((pAVar16 = X509_time_adj_ex(pXVar10->cert_info->validity->notAfter,local_4f8,
                                                   0,(time_t *)0x0), pAVar16 != (ASN1_TIME *)0x0 &&
                       (iVar35 = X509_set_subject_name
                                           (pXVar10,(X509_NAME *)local_580->cert_info->validity),
                       iVar35 != 0)) &&
                      ((pkey = X509_REQ_get_pubkey((X509_REQ *)local_580), pkey != (EVP_PKEY *)0x0
                       && (iVar35 = X509_set_pubkey(pXVar10,pkey), iVar35 != 0)))))) {
                    EVP_PKEY_free(pkey);
                    X509V3_set_ctx(&local_4b0,pXVar10,pXVar10,(X509_REQ *)0x0,(X509_CRL *)0x0,0);
                    X509V3_set_nconf(&local_4b0,req_conf);
                    if ((local_52c == (X509 *)0x0) ||
                       (iVar35 = X509V3_EXT_add_nconf(req_conf,&local_4b0,(char *)local_52c,pXVar10)
                       , iVar35 != 0)) {
                      iVar35 = do_X509_sign(bio_err,pXVar10,local_4c8,pEVar36,local_568);
                      if (iVar35 != 0) goto LAB_00015d0a;
                      ERR_print_errors(bio_err);
                    }
                    else {
                      BIO_printf(bio_err,"Error Loading extension section %s\n",local_52c);
                    }
                  }
                }
                goto LAB_00015950;
              }
              X509V3_set_ctx(&local_4b0,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)local_580,
                             (X509_CRL *)0x0,0);
              X509V3_set_nconf(&local_4b0,req_conf);
              if ((local_524 == (X509 *)0x0) ||
                 (iVar35 = X509V3_EXT_REQ_add_nconf
                                     (req_conf,&local_4b0,(char *)local_524,(X509_REQ *)local_580),
                 iVar35 != 0)) {
                iVar35 = do_X509_REQ_sign(bio_err,local_580,local_4c8,pEVar36,local_568);
                if (iVar35 != 0) {
                  pXVar10 = (X509 *)0x0;
                  pcVar33 = local_54c;
                  if (local_54c != (char *)0x0) {
                    pcVar33 = (char *)0x1;
                  }
                  goto LAB_000159b2;
                }
                ERR_print_errors(bio_err);
              }
              else {
                BIO_printf(bio_err,"Error Loading extension section %s\n",local_524);
              }
              pXVar9 = (X509 *)0x0;
              pXVar10 = (X509 *)0x0;
              pXVar34 = local_580;
            }
          }
          else {
            pcVar33 = NCONF_get_string(req_conf,"req","RANDFILE");
            if (pcVar33 == (char *)0x0) {
              ERR_clear_error();
            }
            app_RAND_load_file(pcVar33,bio_err,0);
            if (local_520 != (char *)0x0) {
              app_RAND_load_files(local_520);
            }
            if ((local_540 == (X509 *)0x0) ||
               (local_540 = (X509 *)set_keygen_ctx(bio_err,local_540,&local_4c4,&local_4c0,
                                                   &local_4cc,local_57c), pXVar9 = local_540,
               pXVar10 = local_540, pXVar34 = local_540, local_540 != (X509 *)0x0)) {
              if ((local_4c0 < 1) &&
                 (iVar35 = NCONF_get_number_e(req_conf,"req","default_bits",&local_4c0), iVar35 == 0
                 )) {
                local_4c0 = 0x200;
              }
              else if ((local_4c0 < 0x180) && (local_4c4 == 6 || local_4c4 == 0x74)) {
                local_580 = (X509 *)0x0;
                BIO_printf(bio_err,"private key length is too short,\n");
                BIO_printf(bio_err,"it needs to be at least %d bits, not %ld\n",0x180,local_4c0);
                pXVar9 = local_540;
                pXVar10 = (X509 *)0x0;
                pXVar34 = local_580;
                goto LAB_00015270;
              }
              if ((local_540 != (X509 *)0x0) ||
                 (local_540 = (X509 *)set_keygen_ctx(bio_err,0,&local_4c4,&local_4c0,&local_4cc,
                                                     local_57c), pXVar9 = local_540,
                 pXVar10 = local_540, pXVar34 = local_540, local_540 != (X509 *)0x0)) {
                iVar35 = 0;
                pXVar9 = local_540;
                if ((local_56c != (_STACK *)0x0) && (iVar20 = sk_num(local_56c), 0 < iVar20)) {
                  do {
                    pvVar19 = sk_value(local_56c,iVar35);
                    iVar20 = pkey_ctrl_string(local_540,pvVar19);
                    if (iVar20 < 1) {
                      BIO_printf(bio_err,"parameter error \"%s\"\n",pvVar19);
                      local_580 = (X509 *)0x0;
                      ERR_print_errors(bio_err);
                      pXVar10 = (X509 *)0x0;
                      pXVar34 = local_580;
                      goto LAB_00015270;
                    }
                    iVar35 = iVar35 + 1;
                    iVar20 = sk_num(local_56c);
                  } while (iVar35 < iVar20);
                }
                BIO_printf(bio_err,"Generating a %ld bit %s private key\n",local_4c0,local_4cc);
                EVP_PKEY_CTX_set_cb((EVP_PKEY_CTX *)local_540,genpkey_cb + 1);
                EVP_PKEY_CTX_set_app_data((EVP_PKEY_CTX *)local_540,bio_err);
                iVar35 = EVP_PKEY_keygen((EVP_PKEY_CTX *)local_540,(EVP_PKEY **)&local_4c8);
                if (0 < iVar35) {
                  EVP_PKEY_CTX_free((EVP_PKEY_CTX *)local_540);
                  app_RAND_write_file(pcVar33,bio_err);
                  if ((local_530 == (char *)0x0) &&
                     (local_530 = NCONF_get_string(req_conf,"req","default_keyfile"),
                     local_530 == (char *)0x0)) {
                    ERR_clear_error();
                    BIO_printf(bio_err,"writing new private key to stdout\n");
                    BIO_ctrl((BIO *)bp,0x6a,0,stdout);
                  }
                  else {
                    BIO_printf(bio_err,"writing new private key to \'%s\'\n",local_530);
                    lVar12 = BIO_ctrl((BIO *)bp,0x6c,5,local_530);
                    if (lVar12 < 1) {
                      perror(local_530);
                      local_580 = (X509 *)0x0;
                      pXVar9 = (X509 *)0x0;
                      pXVar10 = (X509 *)0x0;
                      pXVar34 = local_580;
                      goto LAB_00015270;
                    }
                  }
                  pcVar33 = NCONF_get_string(req_conf,"req","encrypt_rsa_key");
                  if (pcVar33 == (char *)0x0) {
                    ERR_clear_error();
                    pcVar33 = NCONF_get_string(req_conf,"req","encrypt_key");
                    if (pcVar33 != (char *)0x0) goto LAB_00015e80;
                    ERR_clear_error();
                  }
                  else {
LAB_00015e80:
                    if (((*pcVar33 == 'n') && (pcVar33[1] == 'o')) && (pcVar33[2] == '\0')) {
                      local_548 = (EVP_CIPHER *)0x0;
                    }
                  }
                  pXVar29 = (X509 *)&DAT_00000004;
                  if (bVar7) {
                    local_548 = (EVP_CIPHER *)0x0;
                  }
                  while (pXVar9 = (X509 *)PEM_write_bio_PrivateKey
                                                    ((BIO *)bp,(EVP_PKEY *)local_4c8,local_548,
                                                     (uchar *)0x0,0,(undefined1 *)0x0,local_4b8),
                        pXVar9 == (X509 *)0x0) {
                    uVar15 = ERR_peek_error();
                    pXVar10 = pXVar9;
                    pXVar34 = pXVar9;
                    if (((uVar15 & 0xfff) != 0x6d) ||
                       (pXVar29 = (X509 *)((int)&pXVar29[-1].aux + 3), pXVar9 = pXVar29,
                       pXVar10 = pXVar29, pXVar34 = pXVar29, pXVar29 == (X509 *)0x0))
                    goto LAB_00015270;
                    ERR_clear_error();
                  }
                  local_580 = (X509 *)0x0;
                  BIO_printf(bio_err,"-----\n");
                  goto LAB_00015914;
                }
                local_580 = (X509 *)0x0;
                BIO_puts(bio_err,"Error Generating Key\n");
                pXVar10 = (X509 *)0x0;
                pXVar34 = local_580;
              }
            }
          }
        }
      }
      else {
        X509V3_set_ctx(&local_4b0,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,(X509_CRL *)0x0,1);
        X509V3_set_nconf(&local_4b0,req_conf);
        pXVar10 = (X509 *)X509V3_EXT_add_nconf(req_conf,&local_4b0,(char *)local_52c,(X509 *)0x0);
        if (pXVar10 != (X509 *)0x0) goto LAB_0001546e;
        pcVar33 = "Error Loading extension section %s\n";
        pXVar9 = local_52c;
LAB_0001579c:
        BIO_printf(bio_err,pcVar33,pXVar9);
        pXVar9 = pXVar10;
        bp = pXVar10;
        pXVar34 = pXVar10;
        local_574 = pXVar10;
      }
    }
  }
  else {
    local_4b0.flags = -1;
    if (bVar2) {
      BIO_printf(bio_err,"Using configuration from %s\n");
    }
    req_conf = NCONF_new((CONF_METHOD *)0x0);
    pXVar9 = (X509 *)NCONF_load(req_conf,(char *)local_550,&local_4b0.flags);
    if (pXVar9 != (X509 *)0x0) goto LAB_00014f12;
    BIO_printf(bio_err,"error on line %ld of %s\n",local_4b0.flags,local_550);
    pXVar10 = pXVar9;
    bp = pXVar9;
    pXVar34 = pXVar9;
    local_574 = pXVar9;
  }
LAB_00015270:
  local_580 = pXVar34;
  ERR_print_errors(bio_err);
  pXVar34 = (X509 *)0x1;
LAB_0001527a:
  if ((req_conf != (CONF *)0x0) && (req_conf != config)) {
    NCONF_free(req_conf);
  }
  BIO_free((BIO *)local_574);
  BIO_free_all((BIO *)bp);
  EVP_PKEY_free((EVP_PKEY *)local_4c8);
  if (pXVar9 != (X509 *)0x0) {
    EVP_PKEY_CTX_free((EVP_PKEY_CTX *)pXVar9);
  }
  if (local_56c != (_STACK *)0x0) {
    sk_free(local_56c);
  }
  if (local_568 != (_STACK *)0x0) {
    sk_free(local_568);
  }
  if (local_57c != (X509 *)0x0) {
    ENGINE_free((ENGINE *)local_57c);
  }
  if (local_4cc != (void *)0x0) {
    CRYPTO_free(local_4cc);
  }
  X509_REQ_free((X509_REQ *)local_580);
  X509_free(pXVar10);
  ASN1_INTEGER_free(local_55c);
  if ((local_564 != (char *)0x0) && (local_4bc != (char *)0x0)) {
    CRYPTO_free(local_4bc);
  }
  if ((local_560 != (char *)0x0) && (local_4b8 != (char *)0x0)) {
    CRYPTO_free(local_4b8);
  }
  OBJ_cleanup();
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pXVar34);
LAB_0001686c:
  iVar35 = sk_num((_STACK *)local_570);
  if (iVar35 <= (int)local_540) goto LAB_00016368;
  pvVar19 = sk_value((_STACK *)local_570,(int)local_540);
  pcVar33 = *(char **)((int)pvVar19 + 4);
  iVar35 = OBJ_txt2nid(pcVar33);
  if (iVar35 != 0) {
    iVar20 = BIO_snprintf(acStack_494,100,"%s_default",pcVar33);
    if (99 < iVar20) {
      BIO_printf(bio_err,"Name \'%s\' too long\n",*(undefined4 *)((int)pvVar19 + 4));
      goto LAB_000162c4;
    }
    pcVar21 = NCONF_get_string(req_conf,(char *)section,acStack_494);
    if (pcVar21 == (char *)0x0) {
      ERR_clear_error();
      pcVar21 = "";
    }
    BIO_snprintf(acStack_494,100,"%s_value",pcVar33);
    pcVar23 = NCONF_get_string(req_conf,(char *)section,acStack_494);
    if (pcVar23 == (char *)0x0) {
      ERR_clear_error();
    }
    BIO_snprintf(acStack_494,100,"%s_min",pcVar33);
    iVar20 = NCONF_get_number_e(req_conf,(char *)section,acStack_494,&local_4b4);
    if (iVar20 == 0) {
      ERR_clear_error();
      local_4b4 = -1;
    }
    BIO_snprintf(acStack_494,100,"%s_max",pcVar33);
    iVar20 = NCONF_get_number_e(req_conf,(char *)section,acStack_494,&local_4b0.flags);
    if (iVar20 == 0) {
      ERR_clear_error();
      local_4b0.flags = -1;
    }
    iVar20 = local_4b0.flags;
    lVar12 = local_4b4;
    uVar27 = *(undefined4 *)((int)pvVar19 + 8);
    do {
      if (batch == 0) {
        BIO_printf(bio_err,"%s [%s]:",uVar27,pcVar21);
      }
      BIO_ctrl(bio_err,0xb,0,(void *)0x0);
      if (pcVar23 == (char *)0x0) {
        buf_19352[0] = '\0';
        if (batch == 0) {
          pcVar33 = fgets(PTR_buf_19352_00016cac,0x400,stdin);
          if (pcVar33 != (char *)0x0) goto LAB_000169f2;
          goto LAB_000162c4;
        }
        buf_19352[1] = '\0';
        buf_19352[0] = '\n';
LAB_00016a9c:
        if (*pcVar21 == '\0') goto LAB_00016892;
        BUF_strlcpy(PTR_buf_19352_00016cac,pcVar21,0x400);
        BUF_strlcat(PTR_buf_19352_00016cac,"\n",0x400);
      }
      else {
        BUF_strlcpy(PTR_buf_19352_00016cac,pcVar23,0x400);
        BUF_strlcat(PTR_buf_19352_00016cac,"\n",0x400);
        BIO_printf(bio_err,"%s\n",pcVar23);
LAB_000169f2:
        if (buf_19352[0] == '\0') goto LAB_000162c4;
        if (buf_19352[0] == '\n') goto LAB_00016a9c;
        if ((buf_19352[0] == '.') && (buf_19352[1] == '\n')) goto LAB_00016892;
      }
      sVar22 = strlen(PTR_buf_19352_00016cac);
      if (*(char *)((int)&batch + sVar22 + 3) != '\n') {
        BIO_printf(bio_err,"weird input :-(\n");
        goto LAB_000162c4;
      }
      *(undefined *)((int)&batch + sVar22 + 3) = 0;
      iVar8 = req_check_len(sVar22 - 1,lVar12,iVar20);
    } while (iVar8 == 0);
    iVar35 = X509_REQ_add1_attr_by_NID
                       ((X509_REQ *)local_580,iVar35,local_528,PTR_buf_19352_00016cac,-1);
    if (iVar35 == 0) {
      BIO_printf(bio_err,"Error adding attribute\n");
      ERR_print_errors(bio_err);
      goto LAB_000162c4;
    }
  }
LAB_00016892:
  local_540 = (X509 *)((int)local_540 + 1);
  goto LAB_0001686c;
}

