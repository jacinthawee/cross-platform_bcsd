
/* WARNING: Restarted to delay deadcode elimination for space: ram */

X509 * ca_main(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  CONF *pCVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  X509 *pXVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  BIO *pBVar13;
  X509 *pXVar14;
  BIO_METHOD *pBVar15;
  X509 *pXVar16;
  byte *pbVar17;
  size_t sVar18;
  X509_REQ *pXVar19;
  __int32_t **pp_Var20;
  OPENSSL_STRING *ppcVar21;
  X509 *pXVar22;
  char **ppcVar23;
  ASN1_UTCTIME *s;
  ASN1_TIME *pAVar24;
  long lVar25;
  X509 *pXVar26;
  _STACK *p_Var27;
  void *pvVar28;
  X509 *pXVar29;
  EVP_PKEY *pEVar30;
  ASN1_TIME *pAVar31;
  X509_REVOKED *x;
  EVP_MD *md;
  undefined *puVar32;
  byte *pbVar33;
  X509_NAME *pXVar34;
  uchar *bytes;
  ASN1_INTEGER *pAVar35;
  char *pcVar36;
  char *pcVar37;
  undefined **ppuVar38;
  uint uVar39;
  X509 *pXVar40;
  uint uVar41;
  X509 *pXVar42;
  X509 *pXVar43;
  char *pcVar44;
  void **ppvVar45;
  byte *pbVar46;
  char **ppcVar47;
  bool bVar48;
  bool bVar49;
  int local_440;
  X509 *local_434;
  X509 *local_430;
  X509 *local_42c;
  char *local_428;
  X509 *local_424;
  _STACK *local_420;
  X509 *local_41c;
  X509 *local_414;
  X509 *local_410;
  int local_40c;
  NETSCAPE_SPKI *local_408;
  X509 *local_404;
  X509 *local_400;
  char *local_3fc;
  char *local_3f8;
  int local_3f4;
  char *local_3f0;
  X509 *local_3ec;
  X509 *local_3e8;
  char *local_3e4;
  X509 *local_3e0;
  char *local_3dc;
  char *local_3d8;
  X509 *local_3d4;
  undefined4 local_3d0;
  X509 *local_3cc;
  char *local_3c8;
  X509 *local_3c4;
  char *local_3c0;
  int local_3bc;
  X509 *local_3b8;
  undefined4 local_3b4;
  char *local_3b0;
  uint local_3ac;
  uint local_3a8;
  X509 *local_3a4;
  char *local_39c;
  int local_398;
  undefined4 local_390;
  X509 *local_380;
  char *local_370;
  X509 *local_36c;
  uint local_368;
  int local_364;
  X509 *local_360;
  long local_35c;
  undefined4 local_358;
  undefined4 local_354;
  undefined4 local_350;
  X509 *local_34c;
  undefined4 local_348;
  X509V3_CTX XStack_344;
  X509V3_CTX local_328 [18];
  char acStack_128 [256];
  char acStack_28 [4];
  
  local_370 = (char *)0x0;
  local_364 = -1;
  local_36c = (X509 *)0x0;
  local_368 = 0;
  local_360 = (X509 *)0x0;
  local_35c = 0;
  local_358 = 0;
  local_354 = 0;
  local_350 = 0;
  local_34c = (X509 *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  local_370 = (char *)0x0;
  conf = (CONF *)0x0;
  section = (X509 *)0x0;
  preserve = 0;
  msie_hack = 0;
  if (bio_err == (BIO *)0x0) {
    pBVar15 = BIO_s_file();
    bio_err = BIO_new(pBVar15);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  param_1 = param_1 + -1;
  ppcVar47 = (char **)(param_2 + 4);
  pcVar44 = (char *)0x0;
  if (0 < param_1) {
    local_40c = 0x1001;
    local_3f8 = (char *)0x3;
    local_420 = (_STACK *)0x0;
    local_3a8 = 0;
    local_440 = 0;
    bVar4 = false;
    pXVar43 = (X509 *)0x0;
    local_3e0 = (X509 *)0x0;
    local_3cc = (X509 *)0x0;
    local_3f0 = (char *)0x0;
    local_3b0 = (char *)0x0;
    local_3b4 = 0;
    local_3c0 = (char *)0x0;
    local_3d0 = 0;
    local_428 = (char *)0x0;
    local_3dc = (char *)0x0;
    local_3d8 = (char *)0x0;
    local_3d4 = (X509 *)0x0;
    local_3e4 = (char *)0x0;
    local_434 = (X509 *)0x0;
    local_3c8 = (char *)0x0;
    local_3fc = (char *)0x0;
    local_3c4 = (X509 *)0x0;
    local_3e8 = (X509 *)0x0;
    local_430 = (X509 *)0x0;
    local_400 = (X509 *)0x0;
    local_404 = (X509 *)0x0;
    local_3ac = 0;
    bVar3 = false;
    local_3a4 = (X509 *)0x0;
    local_3b8 = (X509 *)0x0;
    local_3ec = (X509 *)0x0;
    local_408 = (NETSCAPE_SPKI *)0x0;
    local_42c = (X509 *)0x0;
    local_3bc = 1;
LAB_0001bd1c:
    pcVar37 = *ppcVar47;
    iVar10 = strcmp(pcVar37,"-verbose");
    iVar11 = local_3bc;
    ppcVar23 = ppcVar47;
    if (iVar10 == 0) {
      local_440 = 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-config");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      pXVar43 = (X509 *)ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-name");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      section = (X509 *)ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-subj");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_428 = ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-utf8");
    if (iVar10 == 0) {
      local_40c = 0x1000;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-create_serial");
    if (iVar10 == 0) {
      local_408 = (NETSCAPE_SPKI *)0x1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-multivalue-rdn");
    if (iVar10 == 0) {
      local_3d0 = 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-startdate");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_3f0 = ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-enddate");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_3cc = (X509 *)ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-days");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_35c = strtol(ppcVar47[1],(char **)0x0,10);
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    cVar1 = *pcVar37;
    if ((((cVar1 == '-') && (pcVar37[1] == 'm')) && (pcVar37[2] == 'd')) && (pcVar37[3] == '\0')) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_404 = (X509 *)ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-policy");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_400 = (X509 *)ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-keyfile");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_430 = (X509 *)ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-keyform");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_3f8 = (char *)str2fmt(ppcVar47[1]);
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-passin");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_42c = (X509 *)ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-key");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_370 = ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-cert");
    if (iVar10 == 0) {
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0001c02c;
      local_3e8 = (X509 *)ppcVar47[1];
      ppcVar23 = ppcVar47 + 1;
      goto joined_r0x0001bd1a;
    }
    iVar10 = strcmp(pcVar37,"-selfsign");
    if (iVar10 == 0) {
      local_3a8 = 1;
      goto joined_r0x0001bd1a;
    }
    if (((cVar1 == '-') && (pcVar37[1] == 'i')) && ((pcVar37[2] == 'n' && (pcVar37[3] == '\0')))) {
      param_1 = param_1 + -1;
      if (param_1 != 0) {
        local_3c4 = (X509 *)ppcVar47[1];
        local_3ec = (X509 *)0x1;
        ppcVar23 = ppcVar47 + 1;
        goto joined_r0x0001bd1a;
      }
    }
    else {
      iVar10 = strcmp(pcVar37,"-out");
      if (iVar10 == 0) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          local_3e4 = ppcVar47[1];
          ppcVar23 = ppcVar47 + 1;
          goto joined_r0x0001bd1a;
        }
      }
      else {
        iVar10 = strcmp(pcVar37,"-outdir");
        if (iVar10 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            local_3d4 = (X509 *)ppcVar47[1];
            ppcVar23 = ppcVar47 + 1;
            goto joined_r0x0001bd1a;
          }
        }
        else {
          iVar10 = strcmp(pcVar37,"-sigopt");
          if (iVar10 != 0) {
            iVar10 = strcmp(pcVar37,"-notext");
            if (iVar10 == 0) {
              bVar4 = true;
            }
            else {
              iVar10 = strcmp(pcVar37,"-batch");
              if (iVar10 == 0) {
                local_3e0 = (X509 *)0x1;
              }
              else {
                iVar10 = strcmp(pcVar37,"-preserveDN");
                if (iVar10 == 0) {
                  preserve = 1;
                }
                else {
                  iVar11 = strcmp(pcVar37,"-noemailDN");
                  if (iVar11 == 0) goto joined_r0x0001bd1a;
                  iVar11 = strcmp(pcVar37,"-gencrl");
                  if (iVar11 == 0) {
                    local_3b8 = (X509 *)0x1;
                    iVar11 = local_3bc;
                  }
                  else {
                    iVar11 = strcmp(pcVar37,"-msie_hack");
                    if (iVar11 == 0) {
                      msie_hack = 1;
                      iVar11 = local_3bc;
                    }
                    else {
                      iVar11 = strcmp(pcVar37,"-crldays");
                      if (iVar11 == 0) {
                        param_1 = param_1 + -1;
                        if (param_1 == 0) goto LAB_0001c02c;
                        local_36c = (X509 *)strtol(ppcVar47[1],(char **)0x0,10);
                        iVar11 = local_3bc;
                        ppcVar23 = ppcVar47 + 1;
                      }
                      else {
                        iVar11 = strcmp(pcVar37,"-crlhours");
                        if (iVar11 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 == 0) goto LAB_0001c02c;
                          local_368 = strtol(ppcVar47[1],(char **)0x0,10);
                          iVar11 = local_3bc;
                          ppcVar23 = ppcVar47 + 1;
                        }
                        else {
                          iVar11 = strcmp(pcVar37,"-crlsec");
                          if (iVar11 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 == 0) goto LAB_0001c02c;
                            local_3ac = strtol(ppcVar47[1],(char **)0x0,10);
                            iVar11 = local_3bc;
                            ppcVar23 = ppcVar47 + 1;
                          }
                          else {
                            iVar11 = strcmp(pcVar37,"-infiles");
                            if (iVar11 == 0) {
                              param_1 = param_1 + -1;
                              ppcVar47 = ppcVar47 + 1;
                              local_3ec = (X509 *)0x1;
                              goto LAB_0001bd4c;
                            }
                            iVar11 = strcmp(pcVar37,"-ss_cert");
                            if (iVar11 == 0) {
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_0001c02c;
                              local_3c8 = ppcVar47[1];
                              local_3ec = (X509 *)0x1;
                              iVar11 = local_3bc;
                              ppcVar23 = ppcVar47 + 1;
                            }
                            else {
                              iVar11 = strcmp(pcVar37,"-spkac");
                              if (iVar11 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_0001c02c;
                                local_3fc = ppcVar47[1];
                                local_3ec = (X509 *)0x1;
                                iVar11 = local_3bc;
                                ppcVar23 = ppcVar47 + 1;
                              }
                              else {
                                iVar11 = strcmp(pcVar37,"-revoke");
                                if (iVar11 == 0) {
                                  param_1 = param_1 + -1;
                                  if (param_1 == 0) goto LAB_0001c02c;
                                  local_3c4 = (X509 *)ppcVar47[1];
                                  local_3a4 = (X509 *)0x1;
                                  iVar11 = local_3bc;
                                  ppcVar23 = ppcVar47 + 1;
                                }
                                else {
                                  iVar11 = strcmp(pcVar37,"-extensions");
                                  if (iVar11 == 0) {
                                    param_1 = param_1 + -1;
                                    if (param_1 == 0) goto LAB_0001c02c;
                                    local_3d8 = ppcVar47[1];
                                    iVar11 = local_3bc;
                                    ppcVar23 = ppcVar47 + 1;
                                  }
                                  else {
                                    iVar11 = strcmp(pcVar37,"-extfile");
                                    if (iVar11 == 0) {
                                      param_1 = param_1 + -1;
                                      if (param_1 == 0) goto LAB_0001c02c;
                                      local_3dc = ppcVar47[1];
                                      iVar11 = local_3bc;
                                      ppcVar23 = ppcVar47 + 1;
                                    }
                                    else {
                                      iVar11 = strcmp(pcVar37,"-status");
                                      if (iVar11 == 0) {
                                        param_1 = param_1 + -1;
                                        if (param_1 == 0) goto LAB_0001c02c;
                                        local_434 = (X509 *)ppcVar47[1];
                                        iVar11 = local_3bc;
                                        ppcVar23 = ppcVar47 + 1;
                                      }
                                      else {
                                        iVar11 = strcmp(pcVar37,"-updatedb");
                                        if (iVar11 == 0) {
                                          bVar3 = true;
                                          iVar11 = local_3bc;
                                        }
                                        else {
                                          iVar11 = strcmp(pcVar37,"-crlexts");
                                          if (iVar11 == 0) {
                                            param_1 = param_1 + -1;
                                            if (param_1 == 0) goto LAB_0001c02c;
                                            local_3c0 = ppcVar47[1];
                                            iVar11 = local_3bc;
                                            ppcVar23 = ppcVar47 + 1;
                                          }
                                          else {
                                            iVar11 = strcmp(pcVar37,"-crl_reason");
                                            if (iVar11 == 0) {
                                              param_1 = param_1 + -1;
                                              if (param_1 == 0) goto LAB_0001c02c;
                                              local_3b0 = ppcVar47[1];
                                              local_3b4 = 1;
                                              iVar11 = local_3bc;
                                              ppcVar23 = ppcVar47 + 1;
                                            }
                                            else {
                                              iVar11 = strcmp(pcVar37,"-crl_hold");
                                              if (iVar11 == 0) {
                                                param_1 = param_1 + -1;
                                                if (param_1 == 0) goto LAB_0001c02c;
                                                local_3b0 = ppcVar47[1];
                                                local_3b4 = 2;
                                                iVar11 = local_3bc;
                                                ppcVar23 = ppcVar47 + 1;
                                              }
                                              else {
                                                iVar11 = strcmp(pcVar37,"-crl_compromise");
                                                if (iVar11 == 0) {
                                                  param_1 = param_1 + -1;
                                                  if (param_1 == 0) goto LAB_0001c02c;
                                                  local_3b0 = ppcVar47[1];
                                                  local_3b4 = 3;
                                                  iVar11 = local_3bc;
                                                  ppcVar23 = ppcVar47 + 1;
                                                }
                                                else {
                                                  iVar11 = strcmp(pcVar37,"-crl_CA_compromise");
                                                  if (iVar11 == 0) {
                                                    param_1 = param_1 + -1;
                                                    if (param_1 == 0) goto LAB_0001c02c;
                                                    local_3b0 = ppcVar47[1];
                                                    local_3b4 = 4;
                                                    iVar11 = local_3bc;
                                                    ppcVar23 = ppcVar47 + 1;
                                                  }
                                                  else {
                                                    iVar11 = strcmp(pcVar37,"-engine");
                                                    if ((iVar11 != 0) ||
                                                       (param_1 = param_1 + -1, param_1 == 0))
                                                    goto LAB_0001c02c;
                                                    pcVar44 = ppcVar47[1];
                                                    iVar11 = local_3bc;
                                                    ppcVar23 = ppcVar47 + 1;
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
              }
            }
joined_r0x0001bd1a:
            local_3bc = iVar11;
            param_1 = param_1 + -1;
            ppcVar47 = ppcVar23 + 1;
            if (param_1 < 1) goto LAB_0001bd4c;
            goto LAB_0001bd1c;
          }
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            if ((local_420 == (_STACK *)0x0) &&
               (local_420 = sk_new_null(), local_420 == (_STACK *)0x0)) {
              pcVar37 = *ppcVar47;
            }
            else {
              iVar10 = sk_push(local_420,ppcVar47[1]);
              ppcVar23 = ppcVar47 + 1;
              if (iVar10 != 0) goto joined_r0x0001bd1a;
              pcVar37 = ppcVar47[1];
            }
          }
        }
      }
    }
LAB_0001c02c:
    ppuVar38 = &ca_usage;
    BIO_printf(bio_err,"unknown option %s\n",pcVar37);
    puVar32 = ca_usage;
    while (puVar32 != (undefined *)0x0) {
      BIO_printf(bio_err,"%s");
      ppuVar38 = ppuVar38 + 1;
      puVar32 = *ppuVar38;
    }
    goto LAB_0001c05c;
  }
  local_3a8 = 0;
  local_40c = 0x1001;
  bVar4 = false;
  local_3e0 = (X509 *)0x0;
  pXVar43 = (X509 *)0x0;
  local_3cc = (X509 *)0x0;
  local_3f0 = (char *)0x0;
  local_3b0 = (char *)0x0;
  local_3b4 = 0;
  local_3c0 = (char *)0x0;
  local_3d0 = 0;
  local_428 = (char *)0x0;
  local_3dc = (char *)0x0;
  local_3d8 = (char *)0x0;
  local_3d4 = (X509 *)0x0;
  local_3e4 = (char *)0x0;
  local_434 = (X509 *)0x0;
  local_3c8 = (char *)0x0;
  local_3fc = (char *)0x0;
  local_3c4 = (X509 *)0x0;
  local_3e8 = (X509 *)0x0;
  local_430 = (X509 *)0x0;
  local_400 = (X509 *)0x0;
  local_404 = (X509 *)0x0;
  local_3ac = 0;
  bVar3 = false;
  local_3a4 = (X509 *)0x0;
  local_3b8 = (X509 *)0x0;
  local_440 = 0;
  local_408 = (NETSCAPE_SPKI *)0x0;
  local_42c = (X509 *)0x0;
  local_420 = (_STACK *)0x0;
  local_3ec = (X509 *)0x0;
  local_3f8 = (char *)0x3;
  local_3bc = 1;
LAB_0001bd4c:
  ERR_load_crypto_strings();
  if (((pXVar43 == (X509 *)0x0) &&
      (pXVar43 = (X509 *)getenv("OPENSSL_CONF"), pXVar43 == (X509 *)0x0)) &&
     (pXVar43 = (X509 *)getenv("SSLEAY_CONF"), pXVar43 == (X509 *)0x0)) {
    pcVar37 = X509_get_default_cert_area();
    sVar18 = strlen(pcVar37);
    sVar18 = sVar18 + 0xd;
    pXVar14 = (X509 *)CRYPTO_malloc(sVar18,"ca.c",0x254);
    BUF_strlcpy((char *)pXVar14,pcVar37,sVar18);
    BUF_strlcat((char *)pXVar14,"/",sVar18);
    BUF_strlcat((char *)pXVar14,"openssl.cnf",sVar18);
    BIO_printf(bio_err,"Using configuration from %s\n",pXVar14);
    conf = NCONF_new((CONF_METHOD *)0x0);
    iVar11 = NCONF_load(conf,(char *)pXVar14,&local_364);
    pXVar43 = pXVar14;
    if (iVar11 < 1) goto LAB_0001c254;
    if (pXVar14 != (X509 *)0x0) {
      CRYPTO_free(pXVar14);
    }
LAB_0001bd7e:
    iVar11 = load_config(bio_err,conf);
    if (iVar11 != 0) {
      uVar12 = setup_engine(bio_err,pcVar44,0);
      if ((section != (X509 *)0x0) ||
         (pXVar43 = (X509 *)NCONF_get_string(conf,"ca","default_ca"), section = pXVar43,
         pXVar43 != (X509 *)0x0)) {
        if (conf != (CONF *)0x0) {
          pcVar44 = NCONF_get_string(conf,(char *)0x0,"oid_file");
          if ((pcVar44 == (char *)0x0) ||
             (pBVar13 = BIO_new_file(pcVar44,"r"), pBVar13 == (BIO *)0x0)) {
            ERR_clear_error();
          }
          else {
            OBJ_create_objects(pBVar13);
            BIO_free(pBVar13);
          }
          pXVar43 = (X509 *)add_oid_section(bio_err,conf);
          if (pXVar43 == (X509 *)0x0) {
            ERR_print_errors(bio_err);
            goto LAB_0001c278;
          }
        }
        pXVar14 = (X509 *)NCONF_get_string(conf,"ca","RANDFILE");
        if (pXVar14 == (X509 *)0x0) {
          ERR_clear_error();
        }
        app_RAND_load_file(pXVar14,bio_err,0);
        pcVar44 = NCONF_get_string(conf,(char *)section,"string_mask");
        if (pcVar44 == (char *)0x0) {
          ERR_clear_error();
        }
        else {
          pXVar43 = (X509 *)ASN1_STRING_set_default_mask_asc(pcVar44);
          if (pXVar43 == (X509 *)0x0) {
            BIO_printf(bio_err,"Invalid global string mask setting %s\n",pcVar44);
            pXVar40 = (X509 *)0x1;
            pXVar16 = pXVar43;
            local_3e8 = pXVar43;
            local_3ec = pXVar43;
            pXVar9 = pXVar43;
            local_430 = pXVar43;
            local_42c = pXVar43;
            local_424 = pXVar43;
            local_41c = pXVar43;
            local_414 = pXVar43;
            local_410 = pXVar43;
            goto LAB_0001c078;
          }
        }
        if (local_40c != 0x1000) {
          pcVar44 = NCONF_get_string(conf,(char *)section,"utf8");
          if (pcVar44 == (char *)0x0) {
            ERR_clear_error();
          }
          else if ((((*pcVar44 == 'y') && (pcVar44[1] == 'e')) && (pcVar44[2] == 's')) &&
                  (pcVar44[3] == '\0')) {
            local_40c = 0x1000;
          }
        }
        local_348 = 1;
        pcVar44 = NCONF_get_string(conf,(char *)section,"unique_subject");
        if (pcVar44 == (char *)0x0) {
          ERR_clear_error();
        }
        else {
          local_348 = parse_yesno(pcVar44,1);
        }
        pBVar15 = BIO_s_file();
        local_410 = (X509 *)BIO_new(pBVar15);
        pBVar15 = BIO_s_file();
        local_414 = (X509 *)BIO_new(pBVar15);
        pBVar15 = BIO_s_file();
        local_41c = (X509 *)BIO_new(pBVar15);
        pBVar15 = BIO_s_file();
        pXVar43 = (X509 *)BIO_new(pBVar15);
        if (local_414 == (X509 *)0x0 || local_410 == (X509 *)0x0) {
LAB_0001c294:
          pXVar16 = (X509 *)0x0;
          ERR_print_errors(bio_err);
          pXVar26 = pXVar16;
          local_3ec = pXVar16;
          local_434 = pXVar16;
          local_430 = pXVar16;
          local_42c = pXVar16;
          local_424 = pXVar16;
        }
        else {
          bVar48 = pXVar43 == (X509 *)0x0 || local_41c == (X509 *)0x0;
          pXVar26 = (X509 *)(uint)bVar48;
          if (bVar48) goto LAB_0001c294;
          if (local_434 == (X509 *)0x0) {
            if ((local_430 == (X509 *)0x0) &&
               (pXVar16 = (X509 *)NCONF_get_string(conf,(char *)section,"private_key"),
               local_430 = pXVar16, pXVar16 == (X509 *)0x0)) {
              BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,"private_key");
              pXVar26 = pXVar16;
              local_3ec = pXVar16;
              local_434 = pXVar16;
              local_42c = pXVar16;
              local_424 = pXVar16;
            }
            else {
              if (local_370 == (char *)0x0) {
                pXVar16 = (X509 *)app_passwd(bio_err,local_42c,0,&local_370,0);
                if (pXVar16 == (X509 *)0x0) {
                  BIO_printf(bio_err,"Error getting password\n");
                  pXVar40 = (X509 *)0x1;
                  local_424 = (X509 *)0x1;
                  local_3e8 = pXVar16;
                  local_3ec = pXVar16;
                  pXVar9 = pXVar16;
                  local_430 = pXVar16;
                  local_42c = pXVar16;
                  goto LAB_0001c078;
                }
                local_424 = (X509 *)0x1;
              }
              else {
                local_424 = (X509 *)0x0;
              }
              local_42c = (X509 *)load_key(bio_err,local_430,local_3f8,0,local_370,uVar12,
                                           "CA private key");
              pcVar44 = local_370;
              if (local_370 != (char *)0x0) {
                sVar18 = strlen(local_370);
                OPENSSL_cleanse(pcVar44,sVar18);
              }
              if (local_42c == (X509 *)0x0) {
                pXVar40 = (X509 *)0x1;
                pXVar16 = local_42c;
                local_3e8 = local_42c;
                local_3ec = local_42c;
                pXVar9 = local_42c;
                local_430 = local_42c;
                goto LAB_0001c078;
              }
              pcVar44 = local_3fc;
              if (local_3fc != (char *)0x0) {
                pcVar44 = (char *)0x1;
              }
              if ((local_3a8 ^ 1 | (uint)pcVar44) != 0) {
LAB_0001c78c:
                if ((local_3e8 == (X509 *)0x0) &&
                   (local_3e8 = (X509 *)NCONF_get_string(conf,(char *)section,"certificate"),
                   local_3e8 == (X509 *)0x0)) {
                  BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,"certificate");
                  pXVar40 = (X509 *)0x1;
                  pXVar16 = local_3e8;
                  local_3ec = local_3e8;
                  pXVar9 = local_3e8;
                  local_430 = local_3e8;
                  goto LAB_0001c078;
                }
                local_434 = (X509 *)load_cert(bio_err,local_3e8,3,0,uVar12,"CA certificate");
                if (local_434 == (X509 *)0x0) {
                  pXVar40 = (X509 *)0x1;
                  pXVar16 = local_434;
                  local_3e8 = local_434;
                  local_3ec = local_434;
                  pXVar9 = local_434;
                  local_430 = local_434;
                  goto LAB_0001c078;
                }
                pXVar16 = (X509 *)X509_check_private_key(local_434,(EVP_PKEY *)local_42c);
                if (pXVar16 != (X509 *)0x0) {
                  local_380 = local_434;
                  if ((local_3a8 ^ 1) == 0) goto LAB_0001c4a0;
                  goto LAB_0001c4a4;
                }
                pcVar44 = "CA certificate and CA private key do not match\n";
LAB_0001c94c:
                BIO_printf(bio_err,pcVar44);
                pXVar26 = pXVar16;
                local_3ec = pXVar16;
                local_430 = pXVar16;
                goto LAB_0001c2b2;
              }
              local_434 = local_3b8;
              if (local_3c8 != (char *)0x0) {
                local_434 = (X509 *)0x1;
              }
              if (local_434 != (X509 *)0x0) goto LAB_0001c78c;
LAB_0001c4a0:
              local_380 = (X509 *)0x0;
LAB_0001c4a4:
              pbVar17 = (byte *)NCONF_get_string(conf,"ca","preserve");
              if (pbVar17 == (byte *)0x0) {
                ERR_clear_error();
              }
              else if ((*pbVar17 & 0xdf) == 0x59) {
                preserve = 1;
              }
              pbVar17 = (byte *)NCONF_get_string(conf,"ca","msie_hack");
              if (pbVar17 == (byte *)0x0) {
                ERR_clear_error();
              }
              else if ((*pbVar17 & 0xdf) == 0x59) {
                msie_hack = 1;
              }
              pcVar37 = NCONF_get_string(conf,(char *)section,"name_opt");
              pXVar9 = local_434;
              if (pcVar37 != (char *)0x0) {
                pXVar16 = (X509 *)set_name_ex(&local_358,pcVar37);
                if (pXVar16 != (X509 *)0x0) {
                  local_390 = 0;
                  goto LAB_0001c536;
                }
                pcVar44 = "Invalid name options: \"%s\"\n";
LAB_0001dc7c:
                BIO_printf(bio_err,pcVar44,pcVar37);
                pXVar40 = (X509 *)0x1;
                local_3e8 = pXVar16;
                local_3ec = pXVar16;
                local_430 = pXVar16;
                goto LAB_0001c078;
              }
              ERR_clear_error();
              local_390 = 1;
LAB_0001c536:
              pcVar37 = NCONF_get_string(conf,(char *)section,"cert_opt");
              if (pcVar37 == (char *)0x0) {
                ERR_clear_error();
              }
              else {
                pXVar16 = (X509 *)set_cert_ex(&local_354,pcVar37);
                if (pXVar16 == (X509 *)0x0) {
                  pcVar44 = "Invalid certificate options: \"%s\"\n";
                  goto LAB_0001dc7c;
                }
                local_390 = 0;
              }
              pcVar37 = NCONF_get_string(conf,(char *)section,"copy_extensions");
              if (pcVar37 == (char *)0x0) {
                ERR_clear_error();
              }
              else {
                pXVar16 = (X509 *)set_ext_copy(&local_350,pcVar37);
                if (pXVar16 == (X509 *)0x0) {
                  pcVar44 = "Invalid extension copy option: \"%s\"\n";
                  goto LAB_0001dc7c;
                }
              }
              pXVar16 = local_3ec;
              if (local_3d4 != (X509 *)0x0) {
                pXVar16 = (X509 *)0x0;
              }
              if (pXVar16 != (X509 *)0x0) {
                local_3d4 = (X509 *)NCONF_get_string(conf,(char *)section,"new_certs_dir");
                if (local_3d4 != (X509 *)0x0) {
                  pXVar16 = (X509 *)access((char *)local_3d4,7);
                  if (pXVar16 == (X509 *)0x0) {
                    iVar11 = app_isdir(local_3d4);
                    if (0 < iVar11) goto LAB_0001c952;
                    BIO_printf(bio_err,"%s need to be a directory\n",local_3d4);
                    perror((char *)local_3d4);
                    pXVar26 = pXVar16;
                    local_3ec = pXVar16;
                    local_430 = pXVar16;
                  }
                  else {
                    BIO_printf(bio_err,"I am unable to access the %s directory\n",local_3d4);
                    pXVar16 = (X509 *)0x0;
                    perror((char *)local_3d4);
                    pXVar26 = pXVar16;
                    local_3ec = pXVar16;
                    local_430 = pXVar16;
                  }
                  goto LAB_0001c2b2;
                }
                pcVar44 = 
                "there needs to be defined a directory for new certificate to be placed in\n";
                pXVar16 = local_3d4;
                goto LAB_0001c94c;
              }
LAB_0001c952:
              pXVar22 = (X509 *)NCONF_get_string(conf,(char *)section,"database");
              if (pXVar22 == (X509 *)0x0) {
                BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,"database");
                pXVar40 = (X509 *)0x1;
                pXVar16 = pXVar22;
                local_3e8 = pXVar22;
                local_3ec = pXVar22;
                local_430 = pXVar22;
                goto LAB_0001c078;
              }
              local_430 = (X509 *)load_index(pXVar22,&local_348);
              if (local_430 == (X509 *)0x0) {
                pXVar40 = (X509 *)0x1;
                pXVar16 = local_430;
                local_3e8 = local_430;
                local_3ec = local_430;
                goto LAB_0001c078;
              }
              for (iVar11 = 0; iVar10 = sk_num((_STACK *)local_430->sig_alg->parameter),
                  iVar11 < iVar10; iVar11 = iVar11 + 1) {
                ppcVar23 = (char **)sk_value((_STACK *)local_430->sig_alg->parameter,iVar11);
                if (**ppcVar23 == 'R') {
                  local_3e8 = (X509 *)make_revoked(0,ppcVar23[2]);
                  if (local_3e8 == (X509 *)0x0) {
                    local_400 = (X509 *)(iVar11 + 1);
                    pcVar44 = " in entry %d\n";
                    goto LAB_0001ca7c;
                  }
                }
                else if (*ppcVar23[2] != '\0') {
                  local_3dc = (char *)(iVar11 + 1);
                  pcVar44 = "entry %d: not revoked yet, but has a revocation date\n";
                  goto LAB_0001caa0;
                }
                local_3e8 = (X509 *)ASN1_TIME_set_string((ASN1_TIME *)0x0,ppcVar23[1]);
                if (local_3e8 == (X509 *)0x0) {
                  local_400 = (X509 *)(iVar11 + 1);
                  pcVar44 = "entry %d: invalid expiry date\n";
                  goto LAB_0001ca7c;
                }
                pbVar33 = (byte *)ppcVar23[3];
                pcVar37 = (char *)strlen((char *)pbVar33);
                pbVar17 = pbVar33;
                if (*pbVar33 == 0x2d) {
                  pcVar37 = pcVar37 + -1;
                  pbVar17 = pbVar33 + 1;
                }
                if (((int)pcVar37 << 0x1f < 0) || ((int)pcVar37 < 2)) {
                  pcVar44 = "entry %d: bad serial number length (%d)\n";
                  iVar11 = iVar11 + 1;
                  local_3dc = pcVar37;
                  goto LAB_0001ca52;
                }
                bVar2 = *pbVar17;
                while (uVar41 = (uint)bVar2, uVar41 != 0) {
                  uVar39 = (uVar41 & 0xffffffdf) - 0x41;
                  bVar49 = 4 < uVar39;
                  bVar48 = uVar39 == 5;
                  if (5 < uVar39) {
                    bVar49 = 8 < uVar41 - 0x30;
                    bVar48 = uVar41 - 0x30 == 9;
                  }
                  if (bVar49 && !bVar48) {
                    BIO_printf(bio_err,
                               "entry %d: bad serial number characters, char pos %ld, char is \'%c\'\n"
                               ,iVar11 + 1,(int)pbVar17 - (int)pbVar33,uVar41);
                    pXVar40 = (X509 *)0x1;
                    pXVar16 = (X509 *)0x0;
                    local_3e8 = (X509 *)0x0;
                    local_3ec = (X509 *)0x0;
                    goto LAB_0001c078;
                  }
                  pbVar17 = pbVar17 + 1;
                  bVar2 = *pbVar17;
                }
              }
              if (local_440 != 0) {
                BIO_ctrl((BIO *)local_414,0x6a,0x10,stdout);
                TXT_DB_write((BIO *)local_414,(TXT_DB *)local_430->sig_alg);
                pBVar13 = bio_err;
                iVar11 = sk_num((_STACK *)local_430->sig_alg->parameter);
                BIO_printf(pBVar13,"%d entries loaded from the database\n",iVar11);
                BIO_printf(bio_err,"generating index\n");
              }
              pXVar16 = (X509 *)index_index(local_430);
              if (pXVar16 == (X509 *)0x0) {
LAB_0001db20:
                pXVar40 = (X509 *)0x1;
                local_3e8 = pXVar16;
                local_3ec = pXVar16;
                goto LAB_0001c078;
              }
              if (bVar3) {
                if (local_440 != 0) {
                  BIO_printf(bio_err,"Updating %s ...\n",pXVar22);
                }
                s = ASN1_UTCTIME_new();
                pAVar24 = X509_gmtime_adj(s,0);
                pXVar16 = (X509 *)CRYPTO_malloc(pAVar24->length + 1,"ca.c",0xa44);
                if (pXVar16 != (X509 *)0x0) {
                  local_3f4 = 0;
                  memcpy(pXVar16,pAVar24->data,pAVar24->length);
                  pXVar16->sha1_hash[pAVar24->length + -0x58] = '\0';
                  local_398 = 0;
                  iVar11 = strncmp((char *)pXVar16,"49",2);
                  for (; iVar10 = sk_num((_STACK *)local_430->sig_alg->parameter),
                      local_398 < iVar10; local_398 = local_398 + 1) {
                    ppcVar23 = (char **)sk_value((_STACK *)local_430->sig_alg->parameter,local_398);
                    pcVar37 = *ppcVar23;
                    if (*pcVar37 == 'V') {
                      pcVar36 = ppcVar23[1];
                      iVar10 = strncmp(pcVar36,"49",2);
                      if (iVar10 < 1 == iVar11 < 1) {
                        iVar10 = strcmp(pcVar36,(char *)pXVar16);
                        if (iVar10 < 1) {
                          *pcVar37 = 'E';
                          goto LAB_0001db5e;
                        }
                      }
                      else if ((iVar10 < 1) < (iVar11 < 1)) {
                        *pcVar37 = 'E';
LAB_0001db5e:
                        local_3f4 = local_3f4 + 1;
                        (*ppcVar23)[1] = '\0';
                        BIO_printf(bio_err,"%s=Expired\n",ppcVar23[3]);
                      }
                    }
                  }
                  ASN1_UTCTIME_free(pAVar24);
                  CRYPTO_free(pXVar16);
                  if (local_3f4 == 0) {
                    if (local_440 != 0) {
                      BIO_printf(bio_err,"No entries found to mark expired\n");
                    }
                  }
                  else {
                    pXVar16 = (X509 *)save_index(pXVar22,"new",local_430);
                    if ((pXVar16 == (X509 *)0x0) ||
                       (pXVar16 = (X509 *)rotate_index(pXVar22,"new","old"), pXVar16 == (X509 *)0x0)
                       ) goto LAB_0001db20;
                    if (local_440 != 0) {
                      BIO_printf(bio_err,"Done. %d entries marked as expired\n",local_3f4);
                    }
                  }
                  goto LAB_0001cc2e;
                }
                ASN1_UTCTIME_free(pAVar24);
                CRYPTO_free((void *)0x0);
                pcVar37 = "Malloc failure\n";
                goto LAB_0001cef2;
              }
LAB_0001cc2e:
              if (local_3dc != (char *)0x0) {
                extconf = NCONF_new((CONF_METHOD *)0x0);
                iVar11 = NCONF_load(extconf,local_3dc,&local_364);
                if (iVar11 < 1) {
                  if (local_364 < 1) {
                    pcVar44 = "ERROR: loading the config file \'%s\'\n";
LAB_0001caa0:
                    BIO_printf(bio_err,pcVar44,local_3dc);
                    pXVar40 = (X509 *)0x1;
                    pXVar16 = (X509 *)0x0;
                    local_3e8 = (X509 *)0x0;
                    local_3ec = (X509 *)0x0;
                  }
                  else {
                    pcVar44 = "ERROR: on line %ld of config file \'%s\'\n";
                    iVar11 = local_364;
LAB_0001ca52:
                    BIO_printf(bio_err,pcVar44,iVar11,local_3dc);
                    pXVar40 = (X509 *)0x1;
                    pXVar16 = (X509 *)0x0;
                    local_3e8 = (X509 *)0x0;
                    local_3ec = (X509 *)0x0;
                  }
                  goto LAB_0001c078;
                }
                if (local_440 != 0) {
                  BIO_printf(bio_err,"Successfully loaded extensions file %s\n",local_3dc);
                }
                if (local_3d8 == (char *)0x0) {
                  local_3d8 = NCONF_get_string(extconf,"default","extensions");
                  if (local_3d8 == (char *)0x0) {
                    local_3d8 = "default";
                  }
                }
              }
              if (((uint)local_3b8 | (uint)local_3ec) != 0) {
                if (local_3e4 == (char *)0x0) {
                  BIO_ctrl((BIO *)local_41c,0x6a,0x10,stdout);
                }
                else {
                  lVar25 = BIO_ctrl((BIO *)local_41c,0x6c,5,local_3e4);
                  if (lVar25 < 1) {
                    perror(local_3e4);
                    pXVar40 = (X509 *)0x1;
                    pXVar16 = (X509 *)0x0;
                    local_3e8 = (X509 *)0x0;
                    local_3ec = (X509 *)0x0;
                    goto LAB_0001c078;
                  }
                }
              }
              if ((local_404 == (X509 *)0x0) &&
                 (pXVar16 = (X509 *)NCONF_get_string(conf,(char *)section,"default_md"),
                 local_404 = pXVar16, pXVar16 == (X509 *)0x0)) {
                pcVar44 = "default_md";
                goto LAB_0001da0a;
              }
              pXVar16 = (X509 *)strcmp((char *)local_404,"default");
              if (pXVar16 == (X509 *)0x0) {
                iVar11 = EVP_PKEY_get_default_digest_nid((EVP_PKEY *)local_42c,&local_328[0].flags);
                if (iVar11 < 1) {
                  BIO_puts(bio_err,"no default digest\n");
                  pXVar40 = (X509 *)0x1;
                  local_3e8 = pXVar16;
                  local_3ec = pXVar16;
                  goto LAB_0001c078;
                }
                local_404 = (X509 *)OBJ_nid2sn(local_328[0].flags);
              }
              local_3e8 = (X509 *)EVP_get_digestbyname((char *)local_404);
              if (local_3e8 == (X509 *)0x0) {
                pcVar44 = "%s is an unsupported message digest type\n";
                local_400 = local_404;
LAB_0001ca7c:
                BIO_printf(bio_err,pcVar44,local_400);
                pXVar40 = (X509 *)0x1;
                pXVar16 = local_3e8;
                local_3ec = local_3e8;
                goto LAB_0001c078;
              }
              if (local_3ec == (X509 *)0x0) goto LAB_0001d4c2;
              if ((local_3bc == 1) &&
                 (pbVar17 = (byte *)NCONF_get_string(conf,(char *)section,"email_in_dn"),
                 pbVar17 != (byte *)0x0)) {
                local_3bc = 0x6e - (uint)*pbVar17;
                if ((local_3bc == 0) && (local_3bc = 0x6f - (uint)pbVar17[1], local_3bc == 0)) {
                  local_3bc = -(uint)pbVar17[2];
                }
                if (local_3bc != 0) {
                  local_3bc = 1;
                }
              }
              pBVar13 = bio_err;
              if (local_440 != 0) {
                pcVar37 = OBJ_nid2ln((int)local_3e8->cert_info);
                BIO_printf(pBVar13,"message digest is %s\n",pcVar37);
              }
              if ((local_400 == (X509 *)0x0) &&
                 (pXVar16 = (X509 *)NCONF_get_string(conf,(char *)section,"policy"),
                 local_400 = pXVar16, pXVar16 == (X509 *)0x0)) {
                pcVar44 = "policy";
              }
              else {
                if (local_440 != 0) {
                  BIO_printf(bio_err,"policy is %s\n",local_400);
                }
                pXVar26 = (X509 *)NCONF_get_string(conf,(char *)section,"serial");
                if (pXVar26 != (X509 *)0x0) {
                  if (extconf == (CONF *)0x0) {
                    if ((local_3d8 == (char *)0x0) &&
                       (local_3d8 = NCONF_get_string(conf,(char *)section,"x509_extensions"),
                       local_3d8 == (char *)0x0)) {
                      ERR_clear_error();
                    }
                    else {
                      X509V3_set_ctx(local_328,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,
                                     (X509_CRL *)0x0,1);
                      X509V3_set_nconf(local_328,conf);
                      pXVar16 = (X509 *)X509V3_EXT_add_nconf(conf,local_328,local_3d8,(X509 *)0x0);
                      pXVar40 = (X509 *)0x1;
                      if (pXVar16 == (X509 *)0x0) {
                        BIO_printf(bio_err,"Error Loading extension section %s\n",local_3d8);
                        local_3e8 = pXVar16;
                        local_3ec = pXVar16;
                        goto LAB_0001c078;
                      }
                    }
                  }
                  if ((local_3f0 == (char *)0x0) &&
                     (local_3f0 = NCONF_get_string(conf,(char *)section,"default_startdate"),
                     local_3f0 == (char *)0x0)) {
                    ERR_clear_error();
                    local_3f0 = "today";
                  }
                  else {
                    pXVar16 = (X509 *)ASN1_TIME_set_string((ASN1_TIME *)0x0,local_3f0);
                    if (pXVar16 == (X509 *)0x0) {
                      pcVar37 = 
                      "start date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n";
                      goto LAB_0001cef2;
                    }
                  }
                  if ((local_3cc == (X509 *)0x0) &&
                     (local_3cc = (X509 *)NCONF_get_string(conf,(char *)section,"default_enddate"),
                     local_3cc == (X509 *)0x0)) {
                    ERR_clear_error();
                  }
                  else {
                    pXVar16 = (X509 *)ASN1_TIME_set_string((ASN1_TIME *)0x0,(char *)local_3cc);
                    if (pXVar16 == (X509 *)0x0) {
                      pcVar37 = 
                      "end date is invalid, it should be YYMMDDHHMMSSZ or YYYYMMDDHHMMSSZ\n";
                      goto LAB_0001cef2;
                    }
                  }
                  if ((local_35c == 0) &&
                     (iVar11 = NCONF_get_number_e(conf,(char *)section,"default_days",&local_35c),
                     iVar11 == 0)) {
                    local_35c = iVar11;
                  }
                  if ((local_3cc != (X509 *)0x0) ||
                     (pcVar37 = "cannot lookup how many days to certify for\n", pXVar16 = local_3cc,
                     local_35c != 0)) {
                    local_360 = (X509 *)load_serial(pXVar26,local_408,0);
                    pcVar37 = "error while loading serial number\n";
                    pXVar16 = local_360;
                    if (local_360 != (X509 *)0x0) {
                      if (local_440 != 0) {
                        if (local_360->sig_alg == (X509_ALGOR *)0x0) {
                          BIO_printf(bio_err,"next serial number is 00\n");
                        }
                        else {
                          pXVar16 = (X509 *)BN_bn2hex((BIGNUM *)local_360);
                          if (pXVar16 == (X509 *)0x0) {
                            pXVar40 = (X509 *)0x1;
                            local_3e8 = pXVar16;
                            local_3ec = pXVar16;
                            goto LAB_0001c078;
                          }
                          BIO_printf(bio_err,"next serial number is %s\n",pXVar16);
                          CRYPTO_free(pXVar16);
                        }
                      }
                      pXVar40 = (X509 *)NCONF_get_section(conf,(char *)local_400);
                      if (pXVar40 == (X509 *)0x0) {
                        pcVar44 = "unable to find \'section\' for %s\n";
                        local_3e8 = pXVar40;
                        goto LAB_0001ca7c;
                      }
                      local_3ec = (X509 *)sk_new_null();
                      uVar8 = local_350;
                      uVar7 = local_354;
                      uVar6 = local_358;
                      lVar25 = local_35c;
                      pXVar29 = local_360;
                      pCVar5 = conf;
                      if (local_3ec == (X509 *)0x0) {
                        BIO_printf(bio_err,"Memory allocation failure\n");
                        pXVar40 = (X509 *)0x1;
                        pXVar16 = local_3ec;
                        local_3e8 = local_3ec;
                        goto LAB_0001c078;
                      }
                      if (pcVar44 != (char *)0x0) {
                        pXVar16 = (X509 *)CONF_load((lhash_st_CONF_VALUE *)0x0,local_3fc,
                                                    &local_328[0].flags);
                        if (pXVar16 == (X509 *)0x0) {
                          pXVar40 = (X509 *)0x1;
                          BIO_printf(bio_err,"error on line %ld of %s\n",local_328[0].flags,
                                     local_3fc);
                          ERR_print_errors(bio_err);
                          local_3e8 = pXVar16;
                          goto LAB_0001c078;
                        }
                        p_Var27 = (_STACK *)
                                  CONF_get_section((lhash_st_CONF_VALUE *)pXVar16,"default");
                        iVar11 = sk_num(p_Var27);
                        if (iVar11 == 0) {
                          BIO_printf(bio_err,"no name/value pairs found in %s\n",local_3fc);
                          CONF_free((lhash_st_CONF_VALUE *)pXVar16);
LAB_0001e07a:
                          local_404 = (X509 *)0xffffffff;
                          local_408 = (NETSCAPE_SPKI *)0x0;
                        }
                        else {
                          pXVar19 = X509_REQ_new();
                          if (pXVar19 == (X509_REQ *)0x0) {
                            ERR_print_errors(bio_err);
                            goto LAB_0001e07a;
                          }
                          local_408 = (NETSCAPE_SPKI *)0x0;
                          pXVar34 = pXVar19->req_info->subject;
                          for (iVar11 = 0; iVar10 = sk_num(p_Var27), iVar11 < iVar10;
                              iVar11 = iVar11 + 1) {
                            pvVar28 = sk_value(p_Var27,iVar11);
                            pbVar17 = *(byte **)((int)pvVar28 + 4);
                            bVar2 = *pbVar17;
                            if (bVar2 != 0) {
                              pbVar33 = pbVar17;
                              if (bVar2 != 0x3a && (bVar2 & 0xfd) != 0x2c) {
                                do {
                                  pbVar33 = pbVar33 + 1;
                                  bVar2 = *pbVar33;
                                  if (bVar2 == 0) goto LAB_0001cea8;
                                } while (bVar2 != 0x3a && (bVar2 & 0xfd) != 0x2c);
                              }
                              if (pbVar33[1] != 0) {
                                pbVar17 = pbVar33 + 1;
                              }
                            }
LAB_0001cea8:
                            bytes = *(uchar **)((int)pvVar28 + 8);
                            iVar10 = OBJ_txt2nid((char *)pbVar17);
                            if (iVar10 == 0) {
                              iVar10 = strcmp((char *)pbVar17,"SPKAC");
                              if ((iVar10 == 0) &&
                                 (local_408 = NETSCAPE_SPKI_b64_decode
                                                        (*(char **)((int)pvVar28 + 8),-1),
                                 local_408 == (NETSCAPE_SPKI *)0x0)) {
                                BIO_printf(bio_err,"unable to load Netscape SPKAC structure\n");
                                local_404 = (X509 *)0xffffffff;
                                ERR_print_errors(bio_err);
                                goto LAB_0001cfd2;
                              }
                            }
                            else {
                              iVar10 = X509_NAME_add_entry_by_NID
                                                 (pXVar34,iVar10,local_40c,bytes,-1,-1,0);
                              if (iVar10 == 0) {
                                local_404 = (X509 *)0xffffffff;
                                goto LAB_0001cfd2;
                              }
                            }
                          }
                          if (local_408 == (NETSCAPE_SPKI *)0x0) {
                            BIO_printf(bio_err,"Netscape SPKAC structure not found in %s\n",
                                       local_3fc);
                            local_404 = (X509 *)0xffffffff;
                          }
                          else {
                            BIO_printf(bio_err,
                                       "Check that the SPKAC request matches the signature\n");
                            pEVar30 = NETSCAPE_SPKI_get_pubkey(local_408);
                            if (pEVar30 == (EVP_PKEY *)0x0) {
                              local_404 = (X509 *)0xffffffff;
                              BIO_printf(bio_err,"error unpacking SPKAC public key\n");
                            }
                            else {
                              iVar11 = NETSCAPE_SPKI_verify(local_408,pEVar30);
                              if (iVar11 < 1) {
                                local_404 = (X509 *)0xffffffff;
                                BIO_printf(bio_err,
                                           "signature verification failed on SPKAC public key\n");
                              }
                              else {
                                BIO_printf(bio_err,"Signature ok\n");
                                X509_REQ_set_pubkey(pXVar19,pEVar30);
                                EVP_PKEY_free(pEVar30);
                                local_404 = (X509 *)do_body(&local_34c,local_42c,local_434,local_3e8
                                                            ,local_420,pXVar40,local_430,pXVar29,
                                                            local_428,local_40c,local_3d0,local_3bc,
                                                            local_3f0,local_3cc,lVar25,1,local_440,
                                                            pXVar19,local_3d8,pCVar5,uVar7,uVar6,
                                                            local_390,uVar8,0);
                              }
                            }
                          }
LAB_0001cfd2:
                          X509_REQ_free(pXVar19);
                        }
                        CONF_free((lhash_st_CONF_VALUE *)pXVar16);
                        if (local_408 != (NETSCAPE_SPKI *)0x0) {
                          NETSCAPE_SPKI_free(local_408);
                        }
                        if ((int)local_404 < 0) goto LAB_0001de6a;
                        if (local_404 == (X509 *)0x0) {
                          local_400 = (X509 *)0x2;
                          pcVar44 = (char *)0x1;
                          local_408 = (NETSCAPE_SPKI *)0x1;
                          local_3e4 = (char *)0x2;
                          local_39c = (char *)0x3;
                          local_3f8 = (char *)local_404;
                          goto LAB_0001d068;
                        }
                        BIO_printf(bio_err,"\n");
                        pXVar16 = (X509 *)BN_add_word((BIGNUM *)local_360,1);
                        if (pXVar16 != (X509 *)0x0) {
                          pXVar16 = (X509 *)sk_push((_STACK *)local_3ec,local_34c);
                          if (pXVar16 != (X509 *)0x0) {
                            if (local_3e4 == (char *)0x0) {
                              local_400 = (X509 *)0x3;
                              local_408 = (NETSCAPE_SPKI *)0x2;
                              local_404 = (X509 *)0x1;
                              local_3f8 = local_3e4;
                              pcVar44 = (char *)0x1;
                              local_39c = (char *)0x3;
                              local_3e4 = (char *)0x2;
                            }
                            else {
                              local_400 = (X509 *)0x3;
                              local_408 = (NETSCAPE_SPKI *)0x2;
                              local_3e0 = (X509 *)0x1;
                              local_39c = (char *)0x3;
                              local_3e4 = (char *)0x2;
                              local_3f8 = (char *)0x1;
                              pcVar44 = (char *)0x1;
                              local_404 = (X509 *)0x1;
                            }
                            goto LAB_0001d068;
                          }
LAB_0001de08:
                          BIO_printf(bio_err,"Memory allocation failure\n");
                          pXVar26 = pXVar16;
                          goto LAB_0001c2b2;
                        }
LAB_0001d014:
                        pXVar40 = (X509 *)0x1;
                        local_3e8 = pXVar16;
                        goto LAB_0001c078;
                      }
                      local_400 = (X509 *)0x2;
                      local_408 = (NETSCAPE_SPKI *)0x1;
                      local_39c = (char *)0x2;
                      local_3e4 = (char *)0x1;
                      local_404 = (X509 *)pcVar44;
                      local_3f8 = pcVar44;
LAB_0001d068:
                      uVar8 = local_350;
                      uVar7 = local_354;
                      uVar6 = local_358;
                      lVar25 = local_35c;
                      pXVar16 = local_360;
                      pCVar5 = conf;
                      pcVar37 = local_3e4;
                      if (local_3c8 != (char *)0x0) {
                        pXVar29 = (X509 *)load_cert(bio_err,local_3c8,3,0,uVar12,local_3c8);
                        if (pXVar29 != (X509 *)0x0) {
                          if (local_440 != 0) {
                            X509_print(bio_err,pXVar29);
                          }
                          BIO_printf(bio_err,"Check that the request matches the signature\n");
                          pEVar30 = X509_get_pubkey(pXVar29);
                          if (pEVar30 == (EVP_PKEY *)0x0) {
                            iVar11 = -1;
                            BIO_printf(bio_err,"error unpacking public key\n");
                          }
                          else {
                            iVar11 = X509_verify(pXVar29,pEVar30);
                            EVP_PKEY_free(pEVar30);
                            if (iVar11 < 0) {
                              iVar11 = 0;
                              BIO_printf(bio_err,"Signature verification problems....\n");
                            }
                            else if (iVar11 == 0) {
                              BIO_printf(bio_err,"Signature did not match the certificate\n");
                            }
                            else {
                              BIO_printf(bio_err,"Signature ok\n");
                              md = EVP_md5();
                              pXVar19 = X509_to_X509_REQ(pXVar29,(EVP_PKEY *)0x0,md);
                              if (pXVar19 == (X509_REQ *)0x0) {
                                iVar11 = -1;
                                if (pXVar29 == (X509 *)0x0) goto LAB_0001de6a;
                              }
                              else {
                                iVar11 = do_body(&local_34c,local_42c,local_434,local_3e8,local_420,
                                                 pXVar40,local_430,pXVar16,local_428,local_40c,
                                                 local_3d0,local_3bc,local_3f0,local_3cc,lVar25,
                                                 local_3e0,local_440,pXVar19,local_3d8,pCVar5,uVar7,
                                                 uVar6,local_390,uVar8,0);
                                X509_REQ_free(pXVar19);
                              }
                            }
                          }
                          X509_free(pXVar29);
                          if (-1 < iVar11) {
                            pcVar37 = local_39c;
                            pcVar44 = local_3e4;
                            if (iVar11 != 0) {
                              BIO_printf(bio_err,"\n");
                              pXVar16 = (X509 *)BN_add_word((BIGNUM *)local_360,1);
                              if (pXVar16 == (X509 *)0x0) goto LAB_0001d014;
                              pXVar16 = (X509 *)sk_push((_STACK *)local_3ec,local_34c);
                              if (pXVar16 == (X509 *)0x0) goto LAB_0001de08;
                              local_404 = (X509 *)local_408;
                              local_408 = (NETSCAPE_SPKI *)local_400;
                            }
                            goto LAB_0001d162;
                          }
                        }
LAB_0001de6a:
                        pXVar40 = (X509 *)0x1;
                        pXVar16 = (X509 *)0x0;
                        local_3e8 = (X509 *)0x0;
                        goto LAB_0001c078;
                      }
LAB_0001d162:
                      local_3e4 = pcVar44;
                      if (local_3c4 != (X509 *)0x0) {
                        iVar11 = certify(&local_34c,local_3c4,local_42c,local_380,local_3e8,
                                         local_420,pXVar40,local_430,local_360,local_428,local_40c,
                                         local_3d0,local_3bc,local_3f0,local_3cc,local_35c,local_3e0
                                         ,local_3d8,conf,local_440,local_354,local_358,local_390,
                                         local_350,local_3a8);
                        if (iVar11 < 0) goto LAB_0001de6a;
                        local_3e4 = pcVar37;
                        if (iVar11 != 0) {
                          BIO_printf(bio_err,"\n");
                          pXVar16 = (X509 *)BN_add_word((BIGNUM *)local_360,1);
                          if (pXVar16 == (X509 *)0x0) goto LAB_0001d014;
                          pXVar16 = (X509 *)sk_push((_STACK *)local_3ec,local_34c);
                          if (pXVar16 == (X509 *)0x0) goto LAB_0001de08;
                          local_404 = (X509 *)local_408;
                        }
                      }
                      if (0 < param_1) {
                        pcVar44 = local_3e4 + param_1;
                        ppcVar47 = ppcVar47 + -1;
                        do {
                          ppcVar47 = ppcVar47 + 1;
                          local_3e4 = local_3e4 + 1;
                          iVar11 = certify(&local_34c,*ppcVar47,local_42c,local_380,local_3e8,
                                           local_420,pXVar40,local_430,local_360,local_428,local_40c
                                           ,local_3d0,local_3bc,local_3f0,local_3cc,local_35c,
                                           local_3e0,local_3d8,conf,local_440,local_354,local_358,
                                           local_390,local_350,local_3a8);
                          if (iVar11 < 0) goto LAB_0001de6a;
                          if (iVar11 != 0) {
                            local_404 = (X509 *)((int)local_404 + 1);
                            BIO_printf(bio_err,"\n");
                            pXVar16 = (X509 *)BN_add_word((BIGNUM *)local_360,1);
                            if (pXVar16 == (X509 *)0x0) {
                              pXVar40 = (X509 *)0x1;
                              local_3e8 = pXVar16;
                              goto LAB_0001c078;
                            }
                            pXVar16 = (X509 *)sk_push((_STACK *)local_3ec,local_34c);
                            if (pXVar16 == (X509 *)0x0) goto LAB_0001de08;
                          }
                        } while (local_3e4 != pcVar44);
                      }
                      iVar11 = sk_num((_STACK *)local_3ec);
                      if (0 < iVar11) {
                        if (local_3e0 == (X509 *)0x0) {
                          BIO_printf(bio_err,
                                     "\n%d out of %d certificate requests certified, commit? [y/n]",
                                     local_404,local_3e4);
                          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
                          local_328[0].flags = local_328[0].flags & 0xffffff00;
                          pcVar44 = fgets((char *)local_328,10,stdin);
                          pXVar16 = local_3e0;
                          pXVar40 = local_3e0;
                          if (pcVar44 == (char *)0x0) {
                            BIO_printf(bio_err,"CERTIFICATION CANCELED: I/O error\n");
                            local_3e8 = local_3e0;
                            goto LAB_0001c078;
                          }
                          if ((local_328[0].flags & 0xdfU) != 0x59) {
                            BIO_printf(bio_err,"CERTIFICATION CANCELED\n");
                            local_3e8 = local_3e0;
                            goto LAB_0001c078;
                          }
                        }
                        pBVar13 = bio_err;
                        iVar11 = sk_num((_STACK *)local_3ec);
                        BIO_printf(pBVar13,"Write out database with %d new entries\n",iVar11);
                        pXVar16 = (X509 *)save_serial(pXVar26,"new",local_360,0);
                        if ((pXVar16 == (X509 *)0x0) ||
                           (pXVar16 = (X509 *)save_index(pXVar22,"new",local_430),
                           pXVar16 == (X509 *)0x0)) goto LAB_0001d014;
                      }
                      if (local_440 != 0) {
                        BIO_printf(bio_err,"writing new certificates\n");
                      }
                      for (iVar11 = 0; iVar10 = sk_num((_STACK *)local_3ec), iVar11 < iVar10;
                          iVar11 = iVar11 + 1) {
                        local_34c = (X509 *)sk_value((_STACK *)local_3ec,iVar11);
                        pAVar35 = local_34c->cert_info->serialNumber;
                        iVar10 = pAVar35->length;
                        pbVar17 = pAVar35->data;
                        sVar18 = strlen((char *)local_3d4);
                        uVar41 = (0x7d - iVar10) * 2;
                        if (iVar10 == 0) {
                          uVar41 = 0xf8;
                        }
                        if (uVar41 <= sVar18) {
                          BIO_printf(bio_err,"certificate file name too long\n");
                          pXVar40 = (X509 *)0x1;
                          pXVar16 = (X509 *)0x0;
                          local_3e8 = (X509 *)0x0;
                          goto LAB_0001c078;
                        }
                        __memcpy_chk(acStack_128,local_3d4,sVar18 + 1,0x100);
                        BUF_strlcat(acStack_128,"/",0x100);
                        sVar18 = strlen(acStack_128);
                        pcVar44 = acStack_128 + sVar18;
                        if (iVar10 < 1) {
                          pcVar44 = acStack_128 + sVar18 + 2;
                          acStack_128[sVar18] = '0';
                          acStack_128[sVar18 + 1] = '0';
                        }
                        else if (pcVar44 < acStack_28) {
                          pcVar37 = pcVar44;
                          pbVar33 = pbVar17;
                          pcVar36 = acStack_128 + sVar18 + 2;
                          do {
                            pcVar44 = pcVar36;
                            pbVar46 = pbVar33 + 1;
                            BIO_snprintf(pcVar37,(int)acStack_28 - (int)pcVar37,"%02X",
                                         (uint)*pbVar33);
                            if (pbVar46 == pbVar17 + iVar10) break;
                            pcVar37 = pcVar44;
                            pbVar33 = pbVar46;
                            pcVar36 = pcVar44 + 2;
                          } while (pbVar46 !=
                                   pbVar17 + ((uint)(acStack_28 +
                                                    (1 - (int)(acStack_128 + sVar18 + 2))) >> 1) + 1
                                  );
                        }
                        *pcVar44 = '.';
                        pcVar44[1] = 'p';
                        pcVar44[2] = 'e';
                        pcVar44[3] = 'm';
                        pcVar44[4] = '\0';
                        if (local_440 != 0) {
                          BIO_printf(bio_err,"writing %s\n",acStack_128);
                        }
                        lVar25 = BIO_ctrl((BIO *)pXVar43,0x6c,5,acStack_128);
                        pXVar16 = local_34c;
                        if (lVar25 < 1) {
                          perror(acStack_128);
                          pXVar40 = (X509 *)0x1;
                          pXVar16 = (X509 *)0x0;
                          local_3e8 = (X509 *)0x0;
                          goto LAB_0001c078;
                        }
                        if (bVar4) {
                          PEM_write_bio_X509((BIO *)pXVar43,local_34c);
                          pXVar16 = local_34c;
                          if (local_3f8 == (char *)0x0) goto LAB_0001d4a4;
LAB_0001df68:
                          i2d_X509_bio((BIO *)local_41c,local_34c);
                        }
                        else {
                          X509_print((BIO *)pXVar43,local_34c);
                          PEM_write_bio_X509((BIO *)pXVar43,pXVar16);
                          pXVar16 = local_34c;
                          if (local_3f8 != (char *)0x0) goto LAB_0001df68;
                          X509_print((BIO *)local_41c,local_34c);
LAB_0001d4a4:
                          PEM_write_bio_X509((BIO *)local_41c,pXVar16);
                        }
                      }
                      iVar11 = sk_num((_STACK *)local_3ec);
                      if (iVar11 != 0) {
                        pXVar16 = (X509 *)rotate_serial(pXVar26,"new","old");
                        if ((pXVar16 == (X509 *)0x0) ||
                           (pXVar16 = (X509 *)rotate_index(pXVar22,"new","old"),
                           pXVar16 == (X509 *)0x0)) goto LAB_0001d014;
                        BIO_printf(bio_err,"Data Base Updated\n");
                      }
LAB_0001d4c2:
                      pXVar16 = local_3b8;
                      if (local_3b8 == (X509 *)0x0) {
LAB_0001d7ba:
                        pXVar40 = local_3a4;
                        local_3e8 = local_3a4;
                        if (local_3a4 == (X509 *)0x0) goto LAB_0001c078;
                        if (local_3c4 == (X509 *)0x0) {
                          BIO_printf(bio_err,"no input files\n");
                          pXVar40 = (X509 *)0x1;
                          local_3e8 = local_3c4;
                          goto LAB_0001c078;
                        }
                        pXVar26 = (X509 *)load_cert(bio_err,local_3c4,3,0,uVar12,local_3c4);
                        if (pXVar26 != (X509 *)0x0) {
                          iVar11 = do_revoke(pXVar26,local_430,local_3b4,local_3b0);
                          if (iVar11 < 1) {
                            pXVar26 = (X509 *)0x0;
                          }
                          else {
                            X509_free(pXVar26);
                            pXVar26 = (X509 *)save_index(pXVar22,"new",local_430);
                            if ((pXVar26 != (X509 *)0x0) &&
                               (pXVar26 = (X509 *)rotate_index(pXVar22,"new","old"),
                               pXVar26 != (X509 *)0x0)) {
                              BIO_printf(bio_err,"Data Base Updated\n");
                              pXVar40 = (X509 *)0x0;
                              local_3e8 = (X509 *)0x0;
                              goto LAB_0001c078;
                            }
                          }
                        }
                      }
                      else {
                        if ((local_3c0 == (char *)0x0) &&
                           (local_3c0 = NCONF_get_string(conf,(char *)section,"crl_extensions"),
                           local_3c0 == (char *)0x0)) {
                          ERR_clear_error();
                        }
                        else {
                          X509V3_set_ctx(&XStack_344,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,
                                         (X509_CRL *)0x0,1);
                          X509V3_set_nconf(&XStack_344,conf);
                          pXVar16 = (X509 *)X509V3_EXT_add_nconf
                                                      (conf,&XStack_344,local_3c0,(X509 *)0x0);
                          if (pXVar16 == (X509 *)0x0) {
                            BIO_printf(bio_err,"Error Loading CRL extension section %s\n",local_3c0)
                            ;
                            pXVar40 = (X509 *)0x1;
                            local_3e8 = pXVar16;
                            goto LAB_0001c078;
                          }
                        }
                        pXVar40 = (X509 *)NCONF_get_string(conf,(char *)section,"crlnumber");
                        pXVar26 = pXVar40;
                        if ((pXVar40 != (X509 *)0x0) &&
                           (pXVar26 = (X509 *)load_serial(pXVar40,0,0), pXVar26 == (X509 *)0x0)) {
                          BIO_printf(bio_err,"error while loading CRL number\n");
                          pXVar40 = (X509 *)0x1;
                          pXVar16 = pXVar26;
                          local_3e8 = pXVar26;
                          goto LAB_0001c078;
                        }
                        if ((local_3ac | local_368 | (uint)local_36c) == 0) {
                          pXVar16 = (X509 *)NCONF_get_number_e(conf,(char *)section,
                                                               "default_crl_days",(long *)&local_36c
                                                              );
                          if (pXVar16 == (X509 *)0x0) {
                            local_36c = pXVar16;
                          }
                          uVar41 = NCONF_get_number_e(conf,(char *)section,"default_crl_hours",
                                                      (long *)&local_368);
                          if (uVar41 == 0) {
                            local_368 = uVar41;
                          }
                          ERR_clear_error();
                        }
                        pXVar16 = local_36c;
                        if ((local_36c == (X509 *)0x0) && ((local_3ac | local_368) == 0)) {
                          BIO_printf(bio_err,"cannot lookup how long until the next CRL is issued\n"
                                    );
                          pXVar40 = (X509 *)0x1;
                          local_3e8 = pXVar26;
                          goto LAB_0001c078;
                        }
                        if (local_440 != 0) {
                          BIO_printf(bio_err,"making CRL\n");
                        }
                        pXVar16 = (X509 *)X509_CRL_new();
                        if (pXVar16 != (X509 *)0x0) {
                          pXVar34 = X509_get_subject_name(local_434);
                          iVar11 = X509_CRL_set_issuer_name((X509_CRL *)pXVar16,pXVar34);
                          if ((iVar11 != 0) &&
                             (pAVar24 = ASN1_TIME_new(), pAVar24 != (ASN1_TIME *)0x0)) {
                            X509_gmtime_adj(pAVar24,0);
                            X509_CRL_set_lastUpdate((X509_CRL *)pXVar16,pAVar24);
                            pAVar31 = X509_time_adj_ex(pAVar24,(int)local_36c,
                                                       local_368 * 0xe10 + local_3ac,(time_t *)0x0);
                            if (pAVar31 == (ASN1_TIME *)0x0) {
                              BIO_puts(bio_err,"error setting CRL nextUpdate\n");
                              pXVar40 = (X509 *)0x1;
                              local_3e8 = pXVar26;
                              goto LAB_0001c078;
                            }
                            X509_CRL_set_nextUpdate((X509_CRL *)pXVar16,pAVar24);
                            ASN1_TIME_free(pAVar24);
                            pXVar29 = (X509 *)0x0;
                            local_40c = 0;
                            while( true ) {
                              iVar11 = sk_num((_STACK *)local_430->sig_alg->parameter);
                              iVar10 = local_40c + 1;
                              if (iVar11 <= local_40c) break;
                              ppcVar47 = (char **)sk_value((_STACK *)local_430->sig_alg->parameter,
                                                           local_40c);
                              local_40c = iVar10;
                              if (**ppcVar47 == 'R') {
                                x = X509_REVOKED_new();
                                if (x == (X509_REVOKED *)0x0) goto LAB_0001c2b2;
                                iVar11 = make_revoked(x,ppcVar47[2]);
                                if (iVar11 == 2) {
                                  pXVar29 = (X509 *)0x1;
                                }
                                if ((iVar11 == 0) ||
                                   (iVar11 = BN_hex2bn((BIGNUM **)&local_360,ppcVar47[3]),
                                   iVar11 == 0)) goto LAB_0001c2b2;
                                pAVar35 = BN_to_ASN1_INTEGER((BIGNUM *)local_360,(ASN1_INTEGER *)0x0
                                                            );
                                BN_free((BIGNUM *)local_360);
                                local_360 = (X509 *)0x0;
                                if (pAVar35 == (ASN1_INTEGER *)0x0) goto LAB_0001c2b2;
                                X509_REVOKED_set_serialNumber(x,pAVar35);
                                ASN1_INTEGER_free(pAVar35);
                                X509_CRL_add0_revoked((X509_CRL *)pXVar16,x);
                              }
                            }
                            X509_CRL_sort((X509_CRL *)pXVar16);
                            if (local_440 != 0) {
                              BIO_printf(bio_err,"signing CRL\n");
                            }
                            pcVar44 = local_3c0;
                            if (local_3c0 != (char *)0x0) {
                              pcVar44 = (char *)0x1;
                            }
                            pXVar42 = pXVar40;
                            if (pXVar40 != (X509 *)0x0) {
                              pXVar42 = (X509 *)0x1;
                            }
                            if (((uint)pcVar44 | (uint)pXVar42) == 0) {
LAB_0001d6ce:
                              if (((pXVar29 == (X509 *)0x0) ||
                                  (iVar11 = X509_CRL_set_version((X509_CRL *)pXVar16,1), iVar11 != 0
                                  )) && ((pXVar42 == (X509 *)0x0 ||
                                         (iVar11 = save_serial(pXVar40,"new",pXVar26,0), iVar11 != 0
                                         )))) {
                                if (pXVar26 != (X509 *)0x0) {
                                  BN_free((BIGNUM *)pXVar26);
                                }
                                pXVar26 = (X509 *)do_X509_CRL_sign(bio_err,pXVar16,local_42c,
                                                                   local_3e8,local_420);
                                if ((pXVar26 != (X509 *)0x0) &&
                                   ((PEM_write_bio_X509_CRL((BIO *)local_41c,(X509_CRL *)pXVar16),
                                    pXVar42 == (X509 *)0x0 ||
                                    (pXVar26 = (X509 *)rotate_serial(pXVar40,"new","old"),
                                    pXVar26 != (X509 *)0x0)))) goto LAB_0001d7ba;
                              }
                            }
                            else {
                              X509V3_set_ctx(&XStack_344,local_434,(X509 *)0x0,(X509_REQ *)0x0,
                                             (X509_CRL *)pXVar16,0);
                              X509V3_set_nconf(&XStack_344,conf);
                              if ((pcVar44 == (char *)0x0) ||
                                 (iVar11 = X509V3_EXT_CRL_add_nconf
                                                     (conf,&XStack_344,local_3c0,(X509_CRL *)pXVar16
                                                     ), iVar11 != 0)) {
                                if (pXVar42 == (X509 *)0x0) {
                                  pXVar29 = (X509 *)((uint)pXVar29 | (uint)pcVar44);
                                  goto LAB_0001d6ce;
                                }
                                pAVar35 = BN_to_ASN1_INTEGER((BIGNUM *)pXVar26,(ASN1_INTEGER *)0x0);
                                if (pAVar35 != (ASN1_INTEGER *)0x0) {
                                  X509_CRL_add1_ext_i2d((X509_CRL *)pXVar16,0x58,pAVar35,0,0);
                                  ASN1_INTEGER_free(pAVar35);
                                  iVar11 = BN_add_word((BIGNUM *)pXVar26,1);
                                  pXVar29 = pXVar42;
                                  if (iVar11 != 0) goto LAB_0001d6ce;
                                }
                              }
                            }
                          }
                        }
                      }
                      goto LAB_0001c2b2;
                    }
                  }
LAB_0001cef2:
                  BIO_printf(bio_err,pcVar37);
                  pXVar40 = (X509 *)0x1;
                  local_3e8 = pXVar16;
                  local_3ec = pXVar16;
                  goto LAB_0001c078;
                }
                pcVar44 = "serial";
                pXVar16 = pXVar26;
              }
LAB_0001da0a:
              BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,pcVar44);
              pXVar26 = pXVar16;
              local_3ec = pXVar16;
            }
          }
          else {
            pXVar16 = (X509 *)NCONF_get_string(conf,(char *)section,"database");
            if (pXVar16 == (X509 *)0x0) {
              BIO_printf(bio_err,"variable lookup failed for %s::%s\n",section,"database");
              pXVar26 = pXVar16;
              local_3ec = pXVar16;
              local_434 = pXVar16;
              local_430 = pXVar16;
              local_42c = pXVar16;
              local_424 = pXVar16;
            }
            else {
              local_430 = (X509 *)load_index(pXVar16,&local_348);
              if (local_430 == (X509 *)0x0) {
                pXVar40 = (X509 *)0x1;
                pXVar16 = local_430;
                local_3e8 = local_430;
                local_3ec = local_430;
                pXVar9 = local_430;
                local_42c = local_430;
                local_424 = local_430;
                goto LAB_0001c078;
              }
              pXVar16 = (X509 *)index_index();
              pXVar40 = (X509 *)0x1;
              local_3e8 = pXVar16;
              local_3ec = pXVar16;
              pXVar9 = pXVar16;
              local_42c = pXVar16;
              local_424 = pXVar16;
              if (pXVar16 == (X509 *)0x0) goto LAB_0001c078;
              local_328[0].flags = (int)pXVar26;
              local_328[0].issuer_cert = pXVar26;
              local_328[0].subject_cert = pXVar26;
              local_328[0].subject_req = (X509_REQ *)pXVar26;
              local_328[0].crl = (X509_CRL *)pXVar26;
              local_328[0].db_meth = (X509V3_CONF_METHOD *)pXVar26;
              sVar18 = strlen((char *)local_434);
              pXVar19 = (X509_REQ *)CRYPTO_malloc(sVar18 + 2,"ca.c",0x9eb);
              local_328[0].subject_req = pXVar19;
              if (pXVar19 == (X509_REQ *)0x0) {
                pXVar40 = (X509 *)0xffffffff;
                BIO_printf(bio_err,"Malloc failure\n");
              }
              else {
                sVar18 = strlen((char *)local_434);
                if ((sVar18 & 1) == 0) {
                  memcpy(pXVar19,local_434,sVar18);
                  sVar18 = strlen((char *)local_434);
                  *(undefined *)((int)&(local_328[0].subject_req)->req_info + sVar18) = 0;
                }
                else {
                  *(undefined *)&pXVar19->req_info = 0x30;
                  sVar18 = strlen((char *)local_434);
                  memcpy((void *)((int)&(local_328[0].subject_req)->req_info + 1),local_434,sVar18);
                  sVar18 = strlen((char *)local_434);
                  *(bool *)((int)&(local_328[0].subject_req)->req_info + sVar18 + 1) = bVar48;
                }
                pXVar19 = local_328[0].subject_req;
                uVar41 = (uint)*(byte *)&(local_328[0].subject_req)->req_info;
                if (uVar41 != 0) {
                  pp_Var20 = __ctype_toupper_loc();
                  iVar11 = 0;
                  do {
                    iVar11 = iVar11 + 1;
                    *(char *)&pXVar19->req_info = (char)(*pp_Var20)[uVar41];
                    pXVar19 = (X509_REQ *)((int)&(local_328[0].subject_req)->req_info + iVar11);
                    uVar41 = (uint)*(byte *)((int)&(local_328[0].subject_req)->req_info + iVar11);
                  } while (uVar41 != 0);
                }
                ppcVar21 = TXT_DB_get_by_index((TXT_DB *)local_430->sig_alg,3,
                                               (OPENSSL_STRING *)local_328);
                if (ppcVar21 == (OPENSSL_STRING *)0x0) {
                  BIO_printf(bio_err,"Serial %s not present in db.\n",local_328[0].subject_req);
                  pXVar40 = (X509 *)0xffffffff;
                }
                else {
                  cVar1 = **ppcVar21;
                  if (cVar1 == 'V') {
                    pXVar40 = (X509 *)0x1;
                    BIO_printf(bio_err,"%s=Valid (%c)\n",local_328[0].subject_req);
                  }
                  else if (cVar1 == 'R') {
                    pXVar40 = (X509 *)0x1;
                    BIO_printf(bio_err,"%s=Revoked (%c)\n",local_328[0].subject_req);
                  }
                  else if (cVar1 == 'E') {
                    pXVar40 = (X509 *)0x1;
                    BIO_printf(bio_err,"%s=Expired (%c)\n",local_328[0].subject_req);
                  }
                  else {
                    if (cVar1 == 'S') {
                      pcVar44 = "%s=Suspended (%c)\n";
                      pXVar40 = (X509 *)0x1;
                    }
                    else {
                      pcVar44 = "%s=Unknown (%c).\n";
                      pXVar40 = (X509 *)0xffffffff;
                    }
                    BIO_printf(bio_err,pcVar44);
                  }
                }
              }
              ppvVar45 = &XStack_344.db;
              do {
                ppvVar45 = ppvVar45 + 1;
                if (*ppvVar45 != (void *)0x0) {
                  CRYPTO_free(*ppvVar45);
                }
              } while ((X509V3_CONF_METHOD **)ppvVar45 != &local_328[0].db_meth);
              if (pXVar40 == (X509 *)0x1) {
                pXVar16 = (X509 *)0x0;
                local_3e8 = pXVar16;
                local_3ec = pXVar16;
                pXVar9 = pXVar16;
                local_42c = pXVar16;
                local_424 = pXVar16;
                goto LAB_0001c078;
              }
              pXVar16 = (X509 *)0x0;
              BIO_printf(bio_err,"Error verifying serial %s!\n",local_434);
              pXVar26 = pXVar16;
              local_3ec = pXVar16;
              local_434 = pXVar16;
              local_42c = pXVar16;
              local_424 = pXVar16;
            }
          }
        }
LAB_0001c2b2:
        pXVar40 = (X509 *)0x1;
        local_3e8 = pXVar26;
        pXVar9 = local_434;
        goto LAB_0001c078;
      }
      BIO_printf(bio_err,"variable lookup failed for %s::%s\n","ca","default_ca");
      goto LAB_0001c278;
    }
LAB_0001c05c:
    pXVar43 = (X509 *)0x0;
  }
  else {
    BIO_printf(bio_err,"Using configuration from %s\n",pXVar43);
    conf = NCONF_new((CONF_METHOD *)0x0);
    iVar11 = NCONF_load(conf,(char *)pXVar43,&local_364);
    if (0 < iVar11) goto LAB_0001bd7e;
    pXVar14 = (X509 *)0x0;
LAB_0001c254:
    if (local_364 < 1) {
      BIO_printf(bio_err,"error loading the config file \'%s\'\n",pXVar43);
    }
    else {
      BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_364,pXVar43);
    }
    pXVar43 = pXVar14;
    if (pXVar14 != (X509 *)0x0) {
      pXVar43 = (X509 *)0x0;
      CRYPTO_free(pXVar14);
LAB_0001c278:
      pXVar40 = (X509 *)0x1;
      pXVar14 = pXVar43;
      pXVar16 = pXVar43;
      local_3e8 = pXVar43;
      local_3ec = pXVar43;
      pXVar9 = pXVar43;
      local_430 = pXVar43;
      local_42c = pXVar43;
      local_424 = pXVar43;
      local_41c = pXVar43;
      local_414 = pXVar43;
      local_410 = pXVar43;
      goto LAB_0001c078;
    }
  }
  pXVar40 = (X509 *)0x1;
  pXVar14 = pXVar43;
  pXVar16 = pXVar43;
  local_3e8 = pXVar43;
  local_3ec = pXVar43;
  pXVar9 = pXVar43;
  local_430 = pXVar43;
  local_42c = pXVar43;
  local_424 = pXVar43;
  local_41c = pXVar43;
  local_414 = pXVar43;
  local_410 = pXVar43;
LAB_0001c078:
  local_434 = pXVar9;
  BIO_free_all((BIO *)pXVar43);
  BIO_free_all((BIO *)local_41c);
  BIO_free_all((BIO *)local_414);
  BIO_free_all((BIO *)local_410);
  if (local_3ec != (X509 *)0x0) {
    sk_pop_free((_STACK *)local_3ec,X509_free);
  }
  if (pXVar40 != (X509 *)0x0) {
    ERR_print_errors(bio_err);
  }
  app_RAND_write_file(pXVar14,bio_err);
  if ((local_424 != (X509 *)0x0) && (local_370 != (char *)0x0)) {
    CRYPTO_free(local_370);
  }
  BN_free((BIGNUM *)local_360);
  BN_free((BIGNUM *)local_3e8);
  free_index(local_430);
  if (local_420 != (_STACK *)0x0) {
    sk_free(local_420);
  }
  EVP_PKEY_free((EVP_PKEY *)local_42c);
  if (local_434 != (X509 *)0x0) {
    X509_free(local_434);
  }
  X509_CRL_free((X509_CRL *)pXVar16);
  NCONF_free(conf);
  NCONF_free(extconf);
  OBJ_cleanup();
  return pXVar40;
}

