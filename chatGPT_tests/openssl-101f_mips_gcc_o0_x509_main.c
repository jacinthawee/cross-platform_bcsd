
/* WARNING: Heritage AFTER dead removal. Example location: r0x006aac60 : 0x0043cfdc */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 x509_main(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  BIO_METHOD *pBVar8;
  long lVar9;
  X509_PUBKEY *pXVar10;
  ASN1_BIT_STRING *pAVar11;
  X509 *pXVar12;
  int iVar13;
  ASN1_OBJECT *pAVar14;
  EVP_PKEY *pEVar15;
  EVP_PKEY *pEVar16;
  size_t sVar17;
  char *pcVar18;
  X509_NAME *pXVar19;
  ASN1_TIME *pAVar20;
  EVP_MD *type;
  int iVar21;
  X509_PURPOSE *xp;
  int iVar22;
  uchar *puVar23;
  _STACK *sk;
  void *pvVar24;
  ASN1_INTEGER *pAVar25;
  BIGNUM *a;
  time_t tVar26;
  byte *pbVar27;
  uint uVar28;
  X509 *x;
  uint uVar29;
  undefined4 uVar30;
  char **ppcVar31;
  undefined1 *puVar32;
  X509_STORE_CTX *pXVar33;
  BIO *bp;
  char *pcVar34;
  EVP_PKEY *pEVar35;
  _STACK *p_Var36;
  X509_STORE *pXVar37;
  code *pcVar38;
  X509_STORE *local_32c;
  X509 *local_328;
  X509_REQ *local_324;
  X509_STORE_CTX *local_320;
  _STACK *local_31c;
  _STACK *local_318;
  _STACK *local_314;
  BIO *local_310;
  int local_304;
  undefined4 local_300;
  int local_2fc;
  EVP_PKEY *local_2f8;
  X509_REQ *local_2f4;
  undefined4 local_2ec;
  char *local_2e8;
  int local_2e4;
  int local_2e0;
  BIGNUM *local_2dc;
  char *local_2d8;
  int local_2d4;
  int local_2d0;
  int local_2cc;
  int local_2c8;
  int local_2c4;
  int local_2bc;
  long local_2b8;
  EVP_MD *local_2b4;
  int local_2b0;
  BIO *local_2ac;
  char *local_2a8;
  char *local_2a4;
  char *local_2a0;
  int local_29c;
  int local_298;
  int local_294;
  int local_290;
  int local_28c;
  int local_288;
  int local_284;
  int local_280;
  int local_27c;
  int local_278;
  int local_274;
  int local_26c;
  int local_268;
  int local_264;
  int local_260;
  char *local_25c;
  char *local_258;
  char *local_254;
  uchar *local_250;
  int local_24c;
  int local_248;
  int local_244;
  long local_23c;
  void *local_21c;
  undefined local_218 [8];
  X509V3_CTX local_210;
  X509_STORE_CTX local_1f4;
  byte local_16c [64];
  char acStack_12c [256];
  int local_2c;
  
  reqfile = 0;
  local_21c = (void *)0x0;
  local_218._0_4_ = 0;
  local_218._4_4_ = (char **)0x0;
  local_2c = __stack_chk_guard;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar6 = load_config(bio_err,0);
  if (iVar6 == 0) {
    local_32c = (X509_STORE *)0x0;
    local_310 = (BIO *)0x0;
  }
  else {
    local_310 = BIO_new_fp(stdout,0);
    local_32c = X509_STORE_new();
    if (local_32c != (X509_STORE *)0x0) {
      param_1 = param_1 + -1;
      X509_STORE_set_verify_cb(local_32c,callb);
      ppcVar31 = (char **)(param_2 + 4);
      local_254 = (char *)0x0;
      local_23c = 0;
      bVar3 = false;
      bVar2 = false;
      local_258 = (char *)0x0;
      local_25c = (char *)0x0;
      local_2e8 = (char *)0x0;
      if (param_1 < 1) {
        local_2b0 = 0;
        local_260 = 0;
        local_264 = 0;
        local_2b8 = 0x1e;
        local_268 = 0;
        local_2bc = 0;
        uVar30 = 3;
        local_26c = 0;
        bVar4 = false;
        local_274 = 0;
        local_244 = 0;
        local_248 = 0;
        bVar5 = false;
        local_278 = 0;
        local_27c = 0;
        local_24c = 0;
        local_2e4 = 0;
        local_2c4 = 0;
        local_2e0 = 0;
        local_280 = 0;
        local_284 = 0;
        local_28c = 0;
        local_290 = 0;
        local_2c8 = 0;
        local_2cc = 0;
        local_2d0 = 0;
        local_294 = 0;
        local_298 = 0;
        local_29c = 0;
        local_2d4 = 0;
        local_250 = (uchar *)0x0;
        local_2a0 = (char *)0x0;
        local_2a4 = (char *)0x0;
        local_2d8 = (char *)0x0;
        local_2a8 = (char *)0x0;
        local_2ac = (BIO *)0x0;
        local_2dc = (BIGNUM *)0x0;
        local_2ec = 3;
        local_2f4 = (X509_REQ *)0x3;
        local_300 = 3;
        local_304 = 3;
        local_314 = (_STACK *)0x0;
        local_318 = (_STACK *)0x0;
        local_2fc = 0;
        local_320 = (X509_STORE_CTX *)0x0;
        local_2b4 = (EVP_MD *)0x0;
        local_288 = 0;
        p_Var36 = (_STACK *)0x0;
      }
      else {
        local_2b4 = (EVP_MD *)0x0;
        local_2b0 = 0;
        local_260 = 0;
        local_2b8 = 0x1e;
        local_264 = 0;
        local_268 = 0;
        local_2bc = 0;
        local_26c = 0;
        bVar4 = false;
        local_274 = 0;
        local_244 = 0;
        local_248 = 0;
        bVar5 = false;
        local_278 = 0;
        local_27c = 0;
        local_24c = 0;
        local_2e4 = 0;
        local_2c4 = 0;
        local_2e0 = 0;
        local_280 = 0;
        local_284 = 0;
        local_288 = 0;
        local_28c = 0;
        local_290 = 0;
        local_2c8 = 0;
        local_2cc = 0;
        local_2d0 = 0;
        local_294 = 0;
        local_298 = 0;
        local_29c = 0;
        local_2d4 = 0;
        local_250 = (uchar *)0x0;
        local_2a0 = (char *)0x0;
        local_2ec = 3;
        local_2f4 = (X509_REQ *)0x3;
        local_300 = 3;
        local_304 = 3;
        local_31c = (_STACK *)0x0;
        uVar30 = 3;
        local_2a4 = (char *)0x0;
        local_2d8 = (char *)0x0;
        local_2a8 = (char *)0x0;
        local_2ac = (BIO *)0x0;
        local_2dc = (BIGNUM *)0x0;
        local_314 = (_STACK *)0x0;
        local_318 = (_STACK *)0x0;
        local_2fc = 0;
        local_320 = (X509_STORE_CTX *)0x0;
        do {
          pcVar34 = *ppcVar31;
          iVar6 = strcmp(pcVar34,"-inform");
          p_Var36 = local_31c;
          if (iVar6 != 0) {
            iVar6 = strcmp(pcVar34,"-outform");
            if (iVar6 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0043d084;
              local_304 = str2fmt(ppcVar31[1]);
              ppcVar31 = ppcVar31 + 1;
              goto LAB_0043ce1c;
            }
            iVar6 = strcmp(pcVar34,"-keyform");
            if (iVar6 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0043d084;
              local_300 = str2fmt(ppcVar31[1]);
              ppcVar31 = ppcVar31 + 1;
              goto LAB_0043ce1c;
            }
            iVar6 = strcmp(pcVar34,"-req");
            if (iVar6 == 0) {
              bVar2 = true;
              reqfile = 1;
              goto LAB_0043ce1c;
            }
            iVar6 = strcmp(pcVar34,"-CAform");
            if (iVar6 == 0) {
              param_1 = param_1 + -1;
              if (param_1 != 0) {
                local_2f4 = (X509_REQ *)str2fmt(ppcVar31[1]);
                ppcVar31 = ppcVar31 + 1;
                goto LAB_0043ce1c;
              }
            }
            else {
              iVar6 = strcmp(pcVar34,"-CAkeyform");
              if (iVar6 == 0) {
                param_1 = param_1 + -1;
                if (param_1 != 0) {
                  local_2ec = str2fmt(ppcVar31[1]);
                  ppcVar31 = ppcVar31 + 1;
                  goto LAB_0043ce1c;
                }
              }
              else {
                iVar6 = strcmp(pcVar34,"-sigopt");
                if (iVar6 == 0) {
                  if ((param_1 != 1) &&
                     ((local_31c != (_STACK *)0x0 ||
                      (local_31c = sk_new_null(), p_Var36 = local_31c, local_31c != (_STACK *)0x0)))
                     ) {
                    pcVar38 = sk_push;
                    p_Var36 = local_31c;
                    goto LAB_0043d0cc;
                  }
                }
                else {
                  iVar6 = strcmp(pcVar34,"-days");
                  if (iVar6 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      local_2b8 = strtol(ppcVar31[1],(char **)0x0,10);
                      ppcVar31 = ppcVar31 + 1;
                      if (local_2b8 != 0) goto LAB_0043ce1c;
                      BIO_printf(bio_err,"bad number of days\n");
                    }
                  }
                  else {
                    iVar6 = strcmp(pcVar34,"-passin");
                    if (iVar6 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_258 = ppcVar31[1];
                        ppcVar31 = ppcVar31 + 1;
                        goto LAB_0043ce1c;
                      }
                    }
                    else {
                      iVar6 = strcmp(pcVar34,"-extfile");
                      if (iVar6 == 0) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          local_25c = ppcVar31[1];
                          ppcVar31 = ppcVar31 + 1;
                          goto LAB_0043ce1c;
                        }
                      }
                      else {
                        iVar6 = strcmp(pcVar34,"-extensions");
                        if (iVar6 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_2e8 = ppcVar31[1];
                            ppcVar31 = ppcVar31 + 1;
                            goto LAB_0043ce1c;
                          }
                        }
                        else {
                          cVar1 = *pcVar34;
                          if ((((cVar1 == '-') && (pcVar34[1] == 'i')) && (pcVar34[2] == 'n')) &&
                             (pcVar34[3] == '\0')) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_2dc = (BIGNUM *)ppcVar31[1];
                              ppcVar31 = ppcVar31 + 1;
                              goto LAB_0043ce1c;
                            }
                          }
                          else {
                            iVar6 = strcmp(pcVar34,"-out");
                            if (iVar6 == 0) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_2ac = (BIO *)ppcVar31[1];
                                ppcVar31 = ppcVar31 + 1;
                                goto LAB_0043ce1c;
                              }
                            }
                            else {
                              iVar6 = strcmp(pcVar34,"-signkey");
                              if (iVar6 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_2a8 = ppcVar31[1];
                                  local_2fc = local_2fc + 1;
                                  bVar2 = true;
                                  ppcVar31 = ppcVar31 + 1;
                                  local_2c4 = local_2fc;
                                  goto LAB_0043ce1c;
                                }
                              }
                              else if (((cVar1 == '-') && (pcVar34[1] == 'C')) &&
                                      ((pcVar34[2] == 'A' && (pcVar34[3] == '\0')))) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_2d8 = ppcVar31[1];
                                  local_2fc = local_2fc + 1;
                                  bVar2 = true;
                                  ppcVar31 = ppcVar31 + 1;
                                  local_2e4 = local_2fc;
                                  goto LAB_0043ce1c;
                                }
                              }
                              else {
                                iVar6 = strcmp(pcVar34,"-CAkey");
                                if (iVar6 == 0) {
                                  param_1 = param_1 + -1;
                                  if (param_1 != 0) {
                                    local_2a4 = ppcVar31[1];
                                    ppcVar31 = ppcVar31 + 1;
                                    goto LAB_0043ce1c;
                                  }
                                }
                                else {
                                  iVar6 = strcmp(pcVar34,"-CAserial");
                                  if (iVar6 == 0) {
                                    param_1 = param_1 + -1;
                                    if (param_1 != 0) {
                                      local_2a0 = ppcVar31[1];
                                      ppcVar31 = ppcVar31 + 1;
                                      goto LAB_0043ce1c;
                                    }
                                  }
                                  else {
                                    iVar6 = strcmp(pcVar34,"-set_serial");
                                    if (iVar6 == 0) {
                                      if (param_1 != 1) {
                                        local_320 = (X509_STORE_CTX *)
                                                    s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                                     ppcVar31[1]);
                                        pXVar33 = local_320;
joined_r0x0043d0d8:
                                        param_1 = param_1 + -1;
                                        ppcVar31 = ppcVar31 + 1;
                                        p_Var36 = local_31c;
                                        if (pXVar33 != (X509_STORE_CTX *)0x0) goto LAB_0043ce1c;
                                      }
                                    }
                                    else {
                                      iVar6 = strcmp(pcVar34,"-addtrust");
                                      if (iVar6 == 0) {
                                        param_1 = param_1 + -1;
                                        if (param_1 != 0) {
                                          pAVar14 = OBJ_txt2obj(ppcVar31[1],0);
                                          if (pAVar14 != (ASN1_OBJECT *)0x0) {
                                            if (local_318 == (_STACK *)0x0) {
                                              local_318 = sk_new_null();
                                            }
                                            sk_push(local_318,pAVar14);
                                            bVar5 = true;
                                            ppcVar31 = ppcVar31 + 1;
                                            goto LAB_0043ce1c;
                                          }
                                          BIO_printf(bio_err,"Invalid trust object value %s\n",
                                                     ppcVar31[1]);
                                        }
                                      }
                                      else {
                                        iVar6 = strcmp(pcVar34,"-addreject");
                                        if (iVar6 == 0) {
                                          param_1 = param_1 + -1;
                                          if (param_1 != 0) {
                                            pAVar14 = OBJ_txt2obj(ppcVar31[1],0);
                                            if (pAVar14 != (ASN1_OBJECT *)0x0) {
                                              if (local_314 == (_STACK *)0x0) {
                                                local_314 = sk_new_null();
                                              }
                                              sk_push(local_314,pAVar14);
                                              bVar5 = true;
                                              ppcVar31 = ppcVar31 + 1;
                                              goto LAB_0043ce1c;
                                            }
                                            BIO_printf(bio_err,"Invalid reject object value %s\n",
                                                       ppcVar31[1]);
                                          }
                                        }
                                        else {
                                          iVar6 = strcmp(pcVar34,"-setalias");
                                          if (iVar6 == 0) {
                                            param_1 = param_1 + -1;
                                            if (param_1 != 0) {
                                              local_250 = (uchar *)ppcVar31[1];
                                              bVar5 = true;
                                              ppcVar31 = ppcVar31 + 1;
                                              goto LAB_0043ce1c;
                                            }
                                          }
                                          else {
                                            iVar6 = strcmp(pcVar34,"-certopt");
                                            if (iVar6 == 0) {
                                              pcVar38 = set_cert_ex;
                                              if (param_1 != 1) {
                                                p_Var36 = (_STACK *)(local_218 + 4);
LAB_0043d0cc:
                                                pXVar33 = (X509_STORE_CTX *)
                                                          (*pcVar38)(p_Var36,ppcVar31[1]);
                                                goto joined_r0x0043d0d8;
                                              }
                                            }
                                            else {
                                              iVar6 = strcmp(pcVar34,"-nameopt");
                                              if (iVar6 != 0) {
                                                iVar6 = strcmp(pcVar34,"-engine");
                                                if (iVar6 == 0) {
                                                  param_1 = param_1 + -1;
                                                  if (param_1 == 0) goto LAB_0043d084;
                                                  local_254 = ppcVar31[1];
                                                  ppcVar31 = ppcVar31 + 1;
                                                }
                                                else if (((cVar1 == '-') && (pcVar34[1] == 'C')) &&
                                                        (pcVar34[2] == '\0')) {
                                                  local_2fc = local_2fc + 1;
                                                  local_26c = local_2fc;
                                                }
                                                else {
                                                  iVar6 = strcmp(pcVar34,"-email");
                                                  if (iVar6 == 0) {
                                                    local_2fc = local_2fc + 1;
                                                    local_27c = local_2fc;
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar34,"-ocsp_uri");
                                                    if (iVar6 == 0) {
                                                      local_2fc = local_2fc + 1;
                                                      local_278 = local_2fc;
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar34,"-serial");
                                                      if (iVar6 == 0) {
                                                        local_2fc = local_2fc + 1;
                                                        local_29c = local_2fc;
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar34,"-next_serial");
                                                        if (iVar6 == 0) {
                                                          local_2fc = local_2fc + 1;
                                                          local_2c8 = local_2fc;
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar34,"-modulus");
                                                          if (iVar6 == 0) {
                                                            local_2fc = local_2fc + 1;
                                                            local_268 = local_2fc;
                                                          }
                                                          else {
                                                            iVar6 = strcmp(pcVar34,"-pubkey");
                                                            if (iVar6 == 0) {
                                                              local_2fc = local_2fc + 1;
                                                              local_264 = local_2fc;
                                                            }
                                                            else {
                                                              iVar6 = strcmp(pcVar34,"-x509toreq");
                                                              if (iVar6 == 0) {
                                                                local_2fc = local_2fc + 1;
                                                                local_2bc = local_2fc;
                                                              }
                                                              else {
                                                                iVar6 = strcmp(pcVar34,"-text");
                                                                if (iVar6 == 0) {
                                                                  local_2fc = local_2fc + 1;
                                                                  local_2d4 = local_2fc;
                                                                }
                                                                else {
                                                                  iVar6 = strcmp(pcVar34,"-hash");
                                                                  if ((iVar6 == 0) ||
                                                                     (iVar6 = strcmp(pcVar34,
                                                  "-subject_hash"), iVar6 == 0)) {
                                                    local_2fc = local_2fc + 1;
                                                    local_290 = local_2fc;
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar34,"-subject_hash_old");
                                                    if (iVar6 == 0) {
                                                      local_2fc = local_2fc + 1;
                                                      local_284 = local_2fc;
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar34,"-issuer_hash");
                                                      if (iVar6 == 0) {
                                                        local_2fc = local_2fc + 1;
                                                        local_28c = local_2fc;
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar34,"-issuer_hash_old");
                                                        if (iVar6 == 0) {
                                                          local_2fc = local_2fc + 1;
                                                          local_280 = local_2fc;
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar34,"-subject");
                                                          if (iVar6 == 0) {
                                                            local_2fc = local_2fc + 1;
                                                            local_298 = local_2fc;
                                                          }
                                                          else {
                                                            iVar6 = strcmp(pcVar34,"-issuer");
                                                            if (iVar6 == 0) {
                                                              local_2fc = local_2fc + 1;
                                                              local_294 = local_2fc;
                                                            }
                                                            else {
                                                              iVar6 = strcmp(pcVar34,"-fingerprint")
                                                              ;
                                                              if (iVar6 == 0) {
                                                                local_2fc = local_2fc + 1;
                                                                local_2b0 = local_2fc;
                                                              }
                                                              else {
                                                                iVar6 = strcmp(pcVar34,"-dates");
                                                                if (iVar6 == 0) {
                                                                  local_2d0 = local_2fc + 1;
                                                                  local_2fc = local_2fc + 2;
                                                                  local_2cc = local_2fc;
                                                                }
                                                                else {
                                                                  iVar6 = strcmp(pcVar34,"-purpose")
                                                                  ;
                                                                  if (iVar6 == 0) {
                                                                    local_2fc = local_2fc + 1;
                                                                    local_260 = local_2fc;
                                                                  }
                                                                  else {
                                                                    iVar6 = strcmp(pcVar34,
                                                  "-startdate");
                                                  if (iVar6 == 0) {
                                                    local_2fc = local_2fc + 1;
                                                    local_2d0 = local_2fc;
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar34,"-enddate");
                                                    if (iVar6 == 0) {
                                                      local_2fc = local_2fc + 1;
                                                      local_2cc = local_2fc;
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar34,"-checkend");
                                                      if (iVar6 == 0) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 == 0) goto LAB_0043d084;
                                                        local_23c = strtol(ppcVar31[1],(char **)0x0,
                                                                           10);
                                                        bVar3 = true;
                                                        ppcVar31 = ppcVar31 + 1;
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar34,"-noout");
                                                        if (iVar6 == 0) {
                                                          local_2fc = local_2fc + 1;
                                                          local_2e0 = local_2fc;
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar34,"-trustout");
                                                          if (iVar6 == 0) {
                                                            bVar5 = true;
                                                          }
                                                          else {
                                                            iVar6 = strcmp(pcVar34,"-clrtrust");
                                                            if (iVar6 == 0) {
                                                              local_2fc = local_2fc + 1;
                                                              local_248 = local_2fc;
                                                            }
                                                            else {
                                                              iVar6 = strcmp(pcVar34,"-clrreject");
                                                              if (iVar6 == 0) {
                                                                local_2fc = local_2fc + 1;
                                                                local_244 = local_2fc;
                                                              }
                                                              else {
                                                                iVar6 = strcmp(pcVar34,"-alias");
                                                                if (iVar6 == 0) {
                                                                  local_2fc = local_2fc + 1;
                                                                  local_274 = local_2fc;
                                                                }
                                                                else {
                                                                  iVar6 = strcmp(pcVar34,
                                                  "-CAcreateserial");
                                                  if (iVar6 == 0) {
                                                    local_2fc = local_2fc + 1;
                                                    local_24c = local_2fc;
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar34,"-clrext");
                                                    if (iVar6 == 0) {
                                                      bVar4 = true;
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar34,"-crlext");
                                                      if (iVar6 == 0) {
                                                        BIO_printf(bio_err,
                                                  "use -clrext instead of -crlext\n");
                                                  bVar4 = true;
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar34,"-ocspid");
                                                    if (iVar6 == 0) {
                                                      local_2fc = local_2fc + 1;
                                                      local_288 = local_2fc;
                                                    }
                                                    else {
                                                      local_2b4 = EVP_get_digestbyname(pcVar34 + 1);
                                                      if (local_2b4 == (EVP_MD *)0x0) {
                                                        BIO_printf(bio_err,"unknown option %s\n",
                                                                   *ppcVar31);
                                                        goto LAB_0043d084;
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
                                                goto LAB_0043ce1c;
                                              }
                                              pcVar38 = set_name_ex;
                                              if (param_1 != 1) {
                                                p_Var36 = (_STACK *)local_218;
                                                goto LAB_0043d0cc;
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
LAB_0043d084:
            puVar32 = x509_usage;
            do {
              puVar32 = (undefined1 *)((int)puVar32 + 4);
              BIO_printf(bio_err,"%s");
            } while (*(int *)puVar32 != 0);
            local_31c = (_STACK *)0x0;
            goto LAB_0043cff4;
          }
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0043d084;
          uVar30 = str2fmt(ppcVar31[1]);
          ppcVar31 = ppcVar31 + 1;
LAB_0043ce1c:
          param_1 = param_1 + -1;
          ppcVar31 = ppcVar31 + 1;
          p_Var36 = local_31c;
        } while (param_1 != 0);
      }
      uVar7 = setup_engine(bio_err,local_254,0);
      if (bVar2) {
        app_RAND_load_file(0,bio_err,0);
      }
      ERR_load_crypto_strings();
      iVar6 = app_passwd(bio_err,local_258,0,&local_21c,0);
      if (iVar6 == 0) {
        pcVar34 = "Error getting password\n";
LAB_0043cfe4:
        BIO_printf(bio_err,pcVar34);
LAB_0043cff0:
        local_31c = (_STACK *)0x0;
LAB_0043cff4:
        local_2f4 = (X509_REQ *)0x0;
        local_328 = (X509 *)0x0;
        bp = (BIO *)0x0;
        local_324 = (X509_REQ *)0x0;
        local_2f8 = (EVP_PKEY *)0x0;
        pEVar35 = (EVP_PKEY *)0x0;
        x = (X509 *)0x0;
        uVar30 = 1;
      }
      else {
        iVar6 = X509_STORE_set_default_paths(local_32c);
        if (iVar6 == 0) {
          ERR_print_errors(bio_err);
          goto LAB_0043cff0;
        }
        if ((local_2a4 == (char *)0x0) && (local_2e4 != 0)) {
          if (local_2f4 != (X509_REQ *)0x3) {
            pcVar34 = "need to specify a CAkey if using the CA command\n";
            goto LAB_0043cfe4;
          }
          local_2a4 = local_2d8;
        }
        if (local_25c != (char *)0x0) {
          local_210.flags = -1;
          local_31c = (_STACK *)NCONF_new((CONF_METHOD *)0x0);
          iVar6 = NCONF_load((CONF *)local_31c,local_25c,&local_210.flags);
          if (iVar6 == 0) {
            if (local_210.flags < 1) {
              BIO_printf(bio_err,"error loading the config file \'%s\'\n",local_25c);
            }
            else {
              BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_210.flags,
                         local_25c);
            }
          }
          else {
            if ((local_2e8 == (char *)0x0) &&
               (local_2e8 = NCONF_get_string((CONF *)local_31c,"default","extensions"),
               local_2e8 == (char *)0x0)) {
              local_2e8 = "default";
              ERR_clear_error();
            }
            X509V3_set_ctx((X509V3_CTX *)&local_1f4,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,
                           (X509_CRL *)0x0,1);
            X509V3_set_nconf((X509V3_CTX *)&local_1f4,(CONF *)local_31c);
            iVar6 = X509V3_EXT_add_nconf
                              ((CONF *)local_31c,(X509V3_CTX *)&local_1f4,local_2e8,(X509 *)0x0);
            if (iVar6 != 0) goto LAB_0043d320;
            BIO_printf(bio_err,"Error Loading extension section %s\n",local_2e8);
            ERR_print_errors(bio_err);
          }
          goto LAB_0043cff4;
        }
        local_31c = (_STACK *)0x0;
LAB_0043d320:
        if (reqfile == 0) {
          x = (X509 *)load_cert(bio_err,local_2dc,uVar30,0,uVar7,"Certificate");
          if (x == (X509 *)0x0) {
LAB_0043f208:
            local_2f4 = (X509_REQ *)0x0;
            local_328 = (X509 *)0x0;
            bp = (BIO *)0x0;
            local_324 = (X509_REQ *)0x0;
            local_2f8 = (EVP_PKEY *)0x0;
            pEVar35 = (EVP_PKEY *)0x0;
            uVar30 = 1;
          }
          else {
            local_324 = (X509_REQ *)0x0;
LAB_0043d5ec:
            if (local_2e4 == 0) {
              local_328 = (X509 *)0x0;
            }
            else {
              local_328 = (X509 *)load_cert(bio_err,local_2d8,local_2f4,0,uVar7,"CA Certificate");
              if (local_328 == (X509 *)0x0) {
                local_2f4 = (X509_REQ *)0x0;
                bp = (BIO *)0x0;
                local_2f8 = (EVP_PKEY *)0x0;
                pEVar35 = (EVP_PKEY *)0x0;
                uVar30 = 1;
                goto LAB_0043d014;
              }
            }
            if (((local_2e0 == 0) || (local_2d4 != 0)) || (local_2c8 != 0)) {
              OBJ_create("2.99999.3","SET.ex3","SET x509v3 extension 3");
              pBVar8 = BIO_s_file();
              bp = BIO_new(pBVar8);
              if (bp == (BIO *)0x0) {
                pcVar38 = ERR_print_errors;
                local_2ac = bio_err;
LAB_0043f41c:
                local_2f4 = (X509_REQ *)0x0;
                (*pcVar38)(local_2ac);
                local_2f8 = (EVP_PKEY *)0x0;
                pEVar35 = (EVP_PKEY *)0x0;
                uVar30 = 1;
                goto LAB_0043d014;
              }
              if (local_2ac == (BIO *)0x0) {
                BIO_ctrl(bp,0x6a,0,stdout);
              }
              else {
                lVar9 = BIO_ctrl(bp,0x6c,5,local_2ac);
                if (lVar9 < 1) {
                  pcVar38 = perror;
                  goto LAB_0043f41c;
                }
              }
            }
            else {
              bp = (BIO *)0x0;
            }
            if (local_250 != (uchar *)0x0) {
              X509_alias_set1(x,local_250,-1);
            }
            if (local_248 != 0) {
              X509_trust_clear(x);
            }
            if (local_244 != 0) {
              X509_reject_clear(x);
            }
            if (local_318 != (_STACK *)0x0) {
              for (iVar6 = 0; iVar13 = sk_num(local_318), iVar6 < iVar13; iVar6 = iVar6 + 1) {
                pAVar14 = (ASN1_OBJECT *)sk_value(local_318,iVar6);
                X509_add1_trust_object(x,pAVar14);
              }
            }
            if (local_314 != (_STACK *)0x0) {
              for (iVar6 = 0; iVar13 = sk_num(local_314), iVar6 < iVar13; iVar6 = iVar6 + 1) {
                pAVar14 = (ASN1_OBJECT *)sk_value(local_314,iVar6);
                X509_add1_reject_object(x,pAVar14);
              }
            }
            if (local_2fc != 0) {
              local_2f4 = (X509_REQ *)0x0;
              pEVar35 = (EVP_PKEY *)0x0;
              local_2f8 = (EVP_PKEY *)0x0;
              iVar6 = 1;
LAB_0043db50:
              if (local_294 == iVar6) {
                pXVar19 = X509_get_issuer_name(x);
                print_name(local_310,"issuer= ",pXVar19,local_218._0_4_);
              }
              else if (local_298 == iVar6) {
                pXVar19 = X509_get_subject_name(x);
                print_name(local_310,"subject= ",pXVar19,local_218._0_4_);
              }
              else if (local_29c == iVar6) {
                BIO_printf(local_310,"serial=");
                pAVar25 = X509_get_serialNumber(x);
                i2a_ASN1_INTEGER(local_310,pAVar25);
                pcVar38 = BIO_printf;
LAB_0043e128:
                (*pcVar38)(local_310,"\n");
              }
              else {
                if (local_2c8 == iVar6) {
                  pAVar25 = X509_get_serialNumber(x);
                  a = ASN1_INTEGER_to_BN(pAVar25,(BIGNUM *)0x0);
                  if (((a == (BIGNUM *)0x0) || (iVar13 = BN_add_word(a,1), iVar13 == 0)) ||
                     (pAVar25 = BN_to_ASN1_INTEGER(a,(ASN1_INTEGER *)0x0),
                     pAVar25 == (ASN1_INTEGER *)0x0)) goto LAB_0043e0d8;
                  BN_free(a);
                  i2a_ASN1_INTEGER(bp,pAVar25);
                  ASN1_INTEGER_free(pAVar25);
                  BIO_puts(bp,"\n");
                  goto LAB_0043dc0c;
                }
                if (local_27c == iVar6) {
                  sk = (_STACK *)X509_get1_email(x);
                }
                else {
                  if (local_278 != iVar6) {
                    if (local_274 == iVar6) {
                      puVar23 = X509_alias_get0(x,(int *)0x0);
                      if (puVar23 == (uchar *)0x0) {
                        BIO_puts(local_310,"<No Alias>\n");
                      }
                      else {
                        BIO_printf(local_310,"%s\n",puVar23);
                      }
                      goto LAB_0043dc0c;
                    }
                    if (local_290 == iVar6) {
                      pcVar38 = X509_subject_name_hash;
                    }
                    else if (local_284 == iVar6) {
                      pcVar38 = X509_subject_name_hash_old;
                    }
                    else if (local_28c == iVar6) {
                      pcVar38 = X509_issuer_name_hash;
                    }
                    else {
                      if (local_280 != iVar6) {
                        if (local_260 == iVar6) {
                          BIO_printf(local_310,"Certificate purposes:\n");
                          for (iVar13 = 0; iVar21 = X509_PURPOSE_get_count(), iVar13 < iVar21;
                              iVar13 = iVar13 + 1) {
                            xp = X509_PURPOSE_get0(iVar13);
                            iVar21 = X509_PURPOSE_get_id(xp);
                            pcVar34 = X509_PURPOSE_get0_name(xp);
                            iVar22 = X509_check_purpose(x,iVar21,0);
                            BIO_printf(local_310,"%s%s : ",pcVar34,"");
                            if (iVar22 == 1) {
                              BIO_printf(local_310,"Yes\n");
                            }
                            else if (iVar22 == 0) {
                              BIO_printf(local_310,"No\n");
                            }
                            else {
                              BIO_printf(local_310,"Yes (WARNING code=%d)\n",iVar22);
                            }
                            iVar21 = X509_check_purpose(x,iVar21,1);
                            BIO_printf(local_310,"%s%s : ",pcVar34,&DAT_00639de0);
                            if (iVar21 == 1) {
                              BIO_printf(local_310,"Yes\n");
                            }
                            else if (iVar21 == 0) {
                              BIO_printf(local_310,"No\n");
                            }
                            else {
                              BIO_printf(local_310,"Yes (WARNING code=%d)\n",iVar21);
                            }
                          }
                          goto LAB_0043dc0c;
                        }
                        if (iVar6 == local_268) {
                          pEVar15 = X509_get_pubkey(x);
                          if (pEVar15 == (EVP_PKEY *)0x0) {
                            pcVar34 = "Modulus=unavailable\n";
                            goto LAB_0043eba4;
                          }
                          BIO_printf(local_310,"Modulus=");
                          if (pEVar15->type == 6) {
                            BN_print(local_310,((pEVar15->pkey).rsa)->n);
                          }
                          else if (pEVar15->type == 0x74) {
                            BN_print(local_310,((pEVar15->pkey).rsa)->d);
                          }
                          else {
                            BIO_printf(local_310,"Wrong Algorithm type");
                          }
                          pcVar38 = BIO_printf;
                          pEVar16 = (EVP_PKEY *)0x63bac8;
                        }
                        else {
                          if (iVar6 != local_264) {
                            if (local_26c == iVar6) {
                              pXVar19 = X509_get_subject_name(x);
                              X509_NAME_oneline(pXVar19,acStack_12c,0x100);
                              BIO_printf(local_310,"/* subject:%s */\n",acStack_12c);
                              pXVar19 = X509_get_issuer_name(x);
                              X509_NAME_oneline(pXVar19,acStack_12c,0x100);
                              BIO_printf(local_310,"/* issuer :%s */\n",acStack_12c);
                              iVar13 = i2d_X509(x,(uchar **)0x0);
                              pXVar37 = (X509_STORE *)CRYPTO_malloc(iVar13,"x509.c",0x369);
                              local_1f4.ctx = pXVar37;
                              pXVar19 = X509_get_subject_name(x);
                              uVar28 = i2d_X509_NAME(pXVar19,(uchar **)&local_1f4);
                              BIO_printf(local_310,"unsigned char XXX_subject_name[%d]={\n",uVar28);
                              local_1f4.ctx = pXVar37;
                              for (uVar29 = 0; (int)uVar29 < (int)uVar28; uVar29 = uVar29 + 1) {
                                BIO_printf(local_310,"0x%02X,",
                                           (uint)*(byte *)((int)&(local_1f4.ctx)->cache + uVar29));
                                if ((uVar29 & 0xf) == 0xf) {
                                  BIO_printf(local_310,"\n");
                                }
                              }
                              if ((int)uVar28 < 0) {
                                uVar28 = 0;
                              }
                              if ((uVar28 & 0xf) != 0) {
                                BIO_printf(local_310,"\n");
                              }
                              BIO_printf(local_310,"};\n");
                              uVar28 = i2d_X509_PUBKEY(x->cert_info->key,(uchar **)&local_1f4);
                              BIO_printf(local_310,"unsigned char XXX_public_key[%d]={\n",uVar28);
                              local_1f4.ctx = pXVar37;
                              for (uVar29 = 0; (int)uVar29 < (int)uVar28; uVar29 = uVar29 + 1) {
                                BIO_printf(local_310,"0x%02X,",
                                           (uint)*(byte *)((int)&(local_1f4.ctx)->cache + uVar29));
                                if ((uVar29 & 0xf) == 0xf) {
                                  BIO_printf(local_310,"\n");
                                }
                              }
                              if ((int)uVar28 < 0) {
                                uVar28 = 0;
                              }
                              if ((uVar28 & 0xf) != 0) {
                                BIO_printf(local_310,"\n");
                              }
                              BIO_printf(local_310,"};\n");
                              uVar28 = i2d_X509(x,(uchar **)&local_1f4);
                              BIO_printf(local_310,"unsigned char XXX_certificate[%d]={\n",uVar28);
                              local_1f4.ctx = pXVar37;
                              for (uVar29 = 0; (int)uVar29 < (int)uVar28; uVar29 = uVar29 + 1) {
                                BIO_printf(local_310,"0x%02X,",
                                           (uint)*(byte *)((int)&(local_1f4.ctx)->cache + uVar29));
                                if ((uVar29 & 0xf) == 0xf) {
                                  BIO_printf(local_310,"\n");
                                }
                              }
                              if ((int)uVar28 < 0) {
                                uVar28 = 0;
                              }
                              if ((uVar28 & 0xf) != 0) {
                                BIO_printf(local_310,"\n");
                              }
                              BIO_printf(local_310,"};\n");
                              CRYPTO_free(pXVar37);
                              goto LAB_0043dc0c;
                            }
                            if (local_2d4 != iVar6) {
                              if (local_2d0 == iVar6) {
                                BIO_puts(local_310,"notBefore=");
                                pAVar20 = x->cert_info->validity->notBefore;
                              }
                              else {
                                if (local_2cc != iVar6) {
                                  if (local_2b0 == iVar6) {
                                    type = local_2b4;
                                    if (local_2b4 == (EVP_MD *)0x0) {
                                      type = EVP_sha1();
                                    }
                                    iVar13 = X509_digest(x,type,local_16c,(uint *)&local_1f4);
                                    if (iVar13 != 0) {
                                      pXVar37 = (X509_STORE *)0x0;
                                      iVar13 = EVP_MD_type(type);
                                      pcVar34 = OBJ_nid2sn(iVar13);
                                      BIO_printf(local_310,"%s Fingerprint=",pcVar34);
                                      while (pbVar27 = local_16c + (int)pXVar37,
                                            (int)pXVar37 < (int)local_1f4.ctx) {
                                        pXVar37 = (X509_STORE *)((int)&pXVar37->cache + 1);
                                        uVar30 = 10;
                                        if (local_1f4.ctx != pXVar37) {
                                          uVar30 = 0x3a;
                                        }
                                        BIO_printf(local_310,"%02X%c",(uint)*pbVar27,uVar30);
                                      }
                                      goto LAB_0043dc0c;
                                    }
                                    uVar30 = 1;
                                    BIO_printf(bio_err,"out of memory\n");
                                    goto LAB_0043d014;
                                  }
                                  if ((local_2c4 == iVar6) && (local_2bc == 0)) {
                                    BIO_printf(bio_err,"Getting Private key\n");
                                    if ((pEVar35 == (EVP_PKEY *)0x0) &&
                                       (pEVar35 = (EVP_PKEY *)
                                                  load_key(bio_err,local_2a8,local_300,0,local_21c,
                                                           uVar7,"Private key"),
                                       pEVar35 == (EVP_PKEY *)0x0)) {
LAB_0043e0d8:
                                      uVar30 = 1;
                                    }
                                    else {
                                      if (!bVar2) {
                                        uVar28 = 0x3c6;
LAB_0043e080:
                    /* WARNING: Subroutine does not return */
                                        __assert_fail("need_rand","x509.c",uVar28,
                                                      __PRETTY_FUNCTION___16748);
                                      }
                                      pEVar15 = X509_get_pubkey(x);
                                      EVP_PKEY_copy_parameters(pEVar15,pEVar35);
                                      EVP_PKEY_save_parameters(pEVar15,1);
                                      EVP_PKEY_free(pEVar15);
                                      pXVar19 = X509_get_subject_name(x);
                                      iVar13 = X509_set_issuer_name(x,pXVar19);
                                      if ((((iVar13 != 0) &&
                                           (pAVar20 = X509_gmtime_adj(x->cert_info->validity->
                                                                      notBefore,0),
                                           pAVar20 != (ASN1_TIME *)0x0)) &&
                                          (pAVar20 = X509_gmtime_adj(x->cert_info->validity->
                                                                     notAfter,local_2b8 * 0x15180),
                                          pAVar20 != (ASN1_TIME *)0x0)) &&
                                         (iVar13 = X509_set_pubkey(x,pEVar35), iVar13 != 0)) {
                                        if (bVar4) {
                                          while (iVar13 = X509_get_ext_count(x), 0 < iVar13) {
                                            X509_delete_ext(x,0);
                                          }
                                        }
                                        if (local_31c != (_STACK *)0x0) {
                                          X509_set_version(x,2);
                                          X509V3_set_ctx((X509V3_CTX *)&local_1f4,x,x,
                                                         (X509_REQ *)0x0,(X509_CRL *)0x0,0);
                                          X509V3_set_nconf((X509V3_CTX *)&local_1f4,
                                                           (CONF *)local_31c);
                                          iVar13 = X509V3_EXT_add_nconf
                                                             ((CONF *)local_31c,
                                                              (X509V3_CTX *)&local_1f4,local_2e8,x);
                                          if (iVar13 == 0) goto LAB_0043e020;
                                        }
                                        iVar13 = X509_sign(x,pEVar35,local_2b4);
                                        if (iVar13 != 0) goto LAB_0043dc0c;
                                      }
LAB_0043e020:
                                      uVar30 = 1;
                                      ERR_print_errors(bio_err);
                                    }
                                    goto LAB_0043d014;
                                  }
                                  if (local_2e4 == iVar6) {
                                    BIO_printf(bio_err,"Getting CA Private Key\n");
                                    if ((local_2a4 != (char *)0x0) &&
                                       (local_2f8 = (EVP_PKEY *)
                                                    load_key(bio_err,local_2a4,local_2ec,0,local_21c
                                                             ,uVar7,"CA Private Key"),
                                       local_2f8 == (EVP_PKEY *)0x0)) goto LAB_0043e0d8;
                                    if (!bVar2) {
                                      uVar28 = 0x3d6;
                                      goto LAB_0043e080;
                                    }
                                    pEVar15 = X509_get_pubkey(local_328);
                                    EVP_PKEY_copy_parameters(pEVar15,local_2f8);
                                    EVP_PKEY_free(pEVar15);
                                    iVar13 = X509_STORE_CTX_init(&local_1f4,local_32c,x,
                                                                 (stack_st_X509 *)0x0);
                                    if (iVar13 == 0) {
                                      pXVar33 = (X509_STORE_CTX *)0x0;
                                      BIO_printf(bio_err,"Error initialising X509 store\n");
LAB_0043de44:
                                      X509_STORE_CTX_cleanup(&local_1f4);
                                      ERR_print_errors(bio_err);
                                      if (local_320 != (X509_STORE_CTX *)0x0) goto LAB_0043d848;
                                    }
                                    else {
                                      pXVar33 = local_320;
                                      if (local_320 != (X509_STORE_CTX *)0x0) {
LAB_0043ddd0:
                                        X509_STORE_CTX_set_cert(&local_1f4,x);
                                        X509_STORE_CTX_set_flags(&local_1f4,0x4000);
                                        if ((reqfile != 0) ||
                                           (iVar13 = X509_verify_cert(&local_1f4), 0 < iVar13)) {
                                          iVar13 = X509_check_private_key(local_328,local_2f8);
                                          if (iVar13 == 0) {
                                            BIO_printf(bio_err,
                                                  "CA certificate and CA private key do not match\n"
                                                  );
                                          }
                                          else {
                                            pXVar19 = X509_get_subject_name(local_328);
                                            iVar13 = X509_set_issuer_name(x,pXVar19);
                                            if ((((iVar13 != 0) &&
                                                 (iVar13 = X509_set_serialNumber
                                                                     (x,(ASN1_INTEGER *)pXVar33),
                                                 iVar13 != 0)) &&
                                                (pAVar20 = X509_gmtime_adj(x->cert_info->validity->
                                                                           notBefore,0),
                                                pAVar20 != (ASN1_TIME *)0x0)) &&
                                               (pAVar20 = X509_time_adj_ex(x->cert_info->validity->
                                                                           notAfter,local_2b8,0,
                                                                           (time_t *)0x0),
                                               pAVar20 != (ASN1_TIME *)0x0)) {
                                              if (bVar4) {
                                                while (iVar13 = X509_get_ext_count(x), 0 < iVar13) {
                                                  X509_delete_ext(x,0);
                                                }
                                              }
                                              if (local_31c != (_STACK *)0x0) {
                                                X509_set_version(x,2);
                                                X509V3_set_ctx(&local_210,local_328,x,
                                                               (X509_REQ *)0x0,(X509_CRL *)0x0,0);
                                                X509V3_set_nconf(&local_210,(CONF *)local_31c);
                                                iVar13 = X509V3_EXT_add_nconf
                                                                   ((CONF *)local_31c,&local_210,
                                                                    local_2e8,x);
                                                if (iVar13 == 0) goto LAB_0043de44;
                                              }
                                              iVar13 = do_X509_sign(bio_err,x,local_2f8,local_2b4,
                                                                    p_Var36);
                                              if (iVar13 != 0) {
                                                X509_STORE_CTX_cleanup(&local_1f4);
                                                if (local_320 == (X509_STORE_CTX *)0x0) {
                                                  ASN1_INTEGER_free((ASN1_INTEGER *)pXVar33);
                                                }
                                                goto LAB_0043dc0c;
                                              }
                                            }
                                          }
                                        }
                                        goto LAB_0043de44;
                                      }
                                      local_210.flags = 0;
                                      if (local_2a0 == (char *)0x0) {
                                        sVar17 = strlen(local_2d8);
                                        sVar17 = sVar17 + 6;
                                        pcVar34 = (char *)CRYPTO_malloc(sVar17,"x509.c",0x45d);
                                        if (pcVar34 != (char *)0x0) {
                                          BUF_strlcpy(pcVar34,local_2d8,sVar17);
                                          for (pcVar18 = pcVar34; *pcVar18 != '\0';
                                              pcVar18 = pcVar18 + 1) {
                                            if (*pcVar18 == '.') {
                                              *pcVar18 = '\0';
                                              break;
                                            }
                                          }
                                          BUF_strlcat(pcVar34,".srl",sVar17);
                                          goto LAB_0043e6d8;
                                        }
LAB_0043e784:
                                        BIO_printf(bio_err,"out of mem\n");
                                        local_2dc = (BIGNUM *)0x0;
                                      }
                                      else {
                                        sVar17 = strlen(local_2a0);
                                        pcVar34 = (char *)CRYPTO_malloc(sVar17 + 1,"x509.c",0x45d);
                                        if (pcVar34 == (char *)0x0) goto LAB_0043e784;
                                        BUF_strlcpy(pcVar34,local_2a0,sVar17 + 1);
LAB_0043e6d8:
                                        local_2dc = (BIGNUM *)load_serial(pcVar34,local_24c,0);
                                        if (local_2dc != (BIGNUM *)0x0) {
                                          iVar13 = BN_add_word(local_2dc,1);
                                          if (iVar13 == 0) {
                                            BIO_printf(bio_err,"add_word failure\n");
                                          }
                                          else {
                                            save_serial(pcVar34,0,local_2dc,&local_210);
                                          }
                                        }
                                        CRYPTO_free(pcVar34);
                                      }
                                      BN_free(local_2dc);
                                      pXVar33 = (X509_STORE_CTX *)local_210.flags;
                                      if ((X509_STORE_CTX *)local_210.flags != (X509_STORE_CTX *)0x0
                                         ) goto LAB_0043ddd0;
                                      X509_STORE_CTX_cleanup(&local_1f4);
                                      ERR_print_errors(bio_err);
                                    }
                                    uVar30 = 1;
                                    ASN1_INTEGER_free((ASN1_INTEGER *)pXVar33);
                                    goto LAB_0043d014;
                                  }
                                  if (local_2bc == iVar6) {
                                    BIO_printf(bio_err,"Getting request Private Key\n");
                                    if (local_2a8 == (char *)0x0) {
                                      uVar30 = 1;
                                      BIO_printf(bio_err,"no request key file specified\n");
                                    }
                                    else {
                                      pEVar15 = (EVP_PKEY *)
                                                load_key(bio_err,local_2a8,local_300,0,local_21c,
                                                         uVar7,"request key");
                                      if (pEVar15 == (EVP_PKEY *)0x0) goto LAB_0043e0d8;
                                      BIO_printf(bio_err,"Generating certificate request\n");
                                      local_2f4 = X509_to_X509_REQ(x,pEVar15,local_2b4);
                                      EVP_PKEY_free(pEVar15);
                                      if (local_2f4 != (X509_REQ *)0x0) {
                                        if (local_2e0 == 0) {
                                          X509_REQ_print(bp,local_2f4);
                                          PEM_write_bio_X509_REQ(bp,local_2f4);
                                          local_2e0 = 1;
                                        }
                                        else {
                                          local_2e0 = 1;
                                        }
                                        goto LAB_0043dc0c;
                                      }
                                      uVar30 = 1;
                                      ERR_print_errors(bio_err);
                                    }
                                    goto LAB_0043d014;
                                  }
                                  if (local_288 == iVar6) {
                                    X509_ocspid_print(bp,x);
                                  }
                                  goto LAB_0043dc0c;
                                }
                                BIO_puts(local_310,"notAfter=");
                                pAVar20 = x->cert_info->validity->notAfter;
                              }
                              ASN1_TIME_print(local_310,pAVar20);
                              pcVar38 = BIO_puts;
                              goto LAB_0043e128;
                            }
                            X509_print_ex(local_310,x,local_218._0_4_,(ulong)local_218._4_4_);
                            goto LAB_0043dc0c;
                          }
                          pEVar16 = X509_get_pubkey(x);
                          if (pEVar16 == (EVP_PKEY *)0x0) {
                            pcVar34 = "Error getting public key\n";
                            goto LAB_0043eba4;
                          }
                          pcVar38 = PEM_write_bio_PUBKEY;
                          pEVar15 = pEVar16;
                        }
                        (*pcVar38)(local_310,pEVar16);
                        EVP_PKEY_free(pEVar15);
                        goto LAB_0043dc0c;
                      }
                      pcVar38 = X509_issuer_name_hash_old;
                    }
                    uVar30 = (*pcVar38)(x);
                    BIO_printf(local_310,"%08lx\n",uVar30);
                    goto LAB_0043dc0c;
                  }
                  sk = (_STACK *)X509_get1_ocsp(x);
                }
                for (iVar13 = 0; iVar21 = sk_num(sk), iVar13 < iVar21; iVar13 = iVar13 + 1) {
                  pvVar24 = sk_value(sk,iVar13);
                  BIO_printf(local_310,"%s\n",pvVar24);
                }
                X509_email_free((stack_st_OPENSSL_STRING *)sk);
              }
LAB_0043dc0c:
              iVar6 = iVar6 + 1;
              if (local_2fc < iVar6) goto LAB_0043d794;
              goto LAB_0043db50;
            }
            local_2f4 = (X509_REQ *)0x0;
            local_2f8 = (EVP_PKEY *)0x0;
            pEVar35 = (EVP_PKEY *)0x0;
LAB_0043d794:
            if (bVar3) {
              tVar26 = time((time_t *)0x0);
              local_1f4.ctx = (X509_STORE *)(local_23c + tVar26);
              iVar6 = X509_cmp_time(x->cert_info->validity->notAfter,(time_t *)&local_1f4);
              if (iVar6 < 0) {
                uVar30 = 1;
                BIO_printf(bp,"Certificate will expire\n");
              }
              else {
                uVar30 = 0;
                BIO_printf(bp,"Certificate will not expire\n");
              }
            }
            else {
              if (local_2e0 == 0) {
                if (local_304 == 1) {
                  iVar6 = i2d_X509_bio(bp,x);
                }
                else if (local_304 == 3) {
                  if (bVar5) {
                    iVar6 = PEM_write_bio_X509_AUX(bp,x);
                  }
                  else {
                    iVar6 = PEM_write_bio_X509(bp,x);
                  }
                }
                else {
                  if (local_304 != 4) {
                    uVar30 = 1;
                    BIO_printf(bio_err,"bad output format specified for outfile\n");
                    goto LAB_0043d014;
                  }
                  local_1f4.ctx = (X509_STORE *)&DAT_0000000b;
                  local_1f4.cert = (X509 *)0x64ae8c;
                  local_210.flags = (int)&local_1f4;
                  local_210.issuer_cert = x;
                  iVar6 = ASN1_item_i2d_bio((ASN1_ITEM *)NETSCAPE_X509_it,bp,&local_210);
                }
                if (iVar6 == 0) {
                  pcVar34 = "unable to write certificate\n";
LAB_0043eba4:
                  uVar30 = 1;
                  BIO_printf(bio_err,pcVar34);
                  ERR_print_errors(bio_err);
                  goto LAB_0043d014;
                }
              }
              uVar30 = 0;
            }
          }
        }
        else {
          if ((local_2c4 == 0) && (local_2e4 == 0)) {
            BIO_printf(bio_err,"We need a private key to sign with\n");
            goto LAB_0043cff4;
          }
          pBVar8 = BIO_s_file();
          x = (X509 *)BIO_new(pBVar8);
          if (x == (X509 *)0x0) {
            ERR_print_errors(bio_err);
            goto LAB_0043f208;
          }
          if (local_2dc == (BIGNUM *)0x0) {
            BIO_ctrl((BIO *)x,0x6a,0x10,stdin);
          }
          else {
            lVar9 = BIO_ctrl((BIO *)x,0x6c,3,local_2dc);
            if (lVar9 < 1) {
              perror((char *)local_2dc);
              BIO_free((BIO *)x);
              goto LAB_0043cff4;
            }
          }
          local_324 = PEM_read_bio_X509_REQ((BIO *)x,(X509_REQ **)0x0,(undefined1 *)0x0,(void *)0x0)
          ;
          BIO_free((BIO *)x);
          if (local_324 == (X509_REQ *)0x0) {
            ERR_print_errors(bio_err);
          }
          else {
            if ((((local_324->req_info != (X509_REQ_INFO *)0x0) &&
                 (pXVar10 = local_324->req_info->pubkey, pXVar10 != (X509_PUBKEY *)0x0)) &&
                (pAVar11 = pXVar10->public_key, pAVar11 != (ASN1_BIT_STRING *)0x0)) &&
               (pAVar11->data != (uchar *)0x0)) {
              x = (X509 *)X509_REQ_get_pubkey(local_324);
              pXVar33 = local_320;
              if (x == (X509 *)0x0) {
                BIO_printf(bio_err,"error unpacking public key\n");
              }
              else {
                pXVar12 = (X509 *)X509_REQ_verify(local_324,(EVP_PKEY *)x);
                EVP_PKEY_free((EVP_PKEY *)x);
                if ((int)pXVar12 < 0) {
                  local_2f4 = (X509_REQ *)0x0;
                  bp = (BIO *)0x0;
                  BIO_printf(bio_err,"Signature verification error\n");
                  local_2f8 = (EVP_PKEY *)0x0;
                  pEVar35 = (EVP_PKEY *)0x0;
                  x = (X509 *)0x0;
                  uVar30 = 1;
                  ERR_print_errors(bio_err);
                  local_328 = (X509 *)0x0;
                  goto LAB_0043d014;
                }
                if (pXVar12 == (X509 *)0x0) {
                  BIO_printf(bio_err,"Signature did not match the certificate request\n");
                  x = pXVar12;
                }
                else {
                  BIO_printf(bio_err,"Signature ok\n");
                  print_name(bio_err,"subject=",local_324->req_info->subject,local_218._0_4_);
                  x = X509_new();
                  if (x != (X509 *)0x0) {
                    if (local_320 == (X509_STORE_CTX *)0x0) {
                      pXVar33 = (X509_STORE_CTX *)ASN1_INTEGER_new();
                      if (pXVar33 == (X509_STORE_CTX *)0x0) {
                        local_320 = (X509_STORE_CTX *)0x0;
                        pXVar33 = local_320;
                      }
                      else {
                        iVar6 = rand_serial(0,pXVar33);
                        if ((iVar6 != 0) &&
                           (iVar6 = X509_set_serialNumber(x,(ASN1_INTEGER *)pXVar33), iVar6 != 0)) {
                          ASN1_INTEGER_free((ASN1_INTEGER *)pXVar33);
                          goto LAB_0043d9ec;
                        }
                      }
                    }
                    else {
                      iVar6 = X509_set_serialNumber(x,(ASN1_INTEGER *)local_320);
                      if (iVar6 != 0) {
LAB_0043d9ec:
                        iVar6 = X509_set_issuer_name(x,local_324->req_info->subject);
                        pXVar33 = local_320;
                        if ((iVar6 != 0) &&
                           (iVar6 = X509_set_subject_name(x,local_324->req_info->subject),
                           iVar6 != 0)) {
                          X509_gmtime_adj(x->cert_info->validity->notBefore,0);
                          X509_time_adj_ex(x->cert_info->validity->notAfter,local_2b8,0,
                                           (time_t *)0x0);
                          pEVar35 = X509_REQ_get_pubkey(local_324);
                          X509_set_pubkey(x,pEVar35);
                          EVP_PKEY_free(pEVar35);
                          goto LAB_0043d5ec;
                        }
                      }
                    }
                  }
                }
              }
              local_320 = pXVar33;
              local_2f4 = (X509_REQ *)0x0;
              local_328 = (X509 *)0x0;
              bp = (BIO *)0x0;
              local_2f8 = (EVP_PKEY *)0x0;
              pEVar35 = (EVP_PKEY *)0x0;
              uVar30 = 1;
              goto LAB_0043d014;
            }
            BIO_printf(bio_err,"The certificate request appears to corrupted\n");
            BIO_printf(bio_err,"It does not contain a public key\n");
          }
          local_2f4 = (X509_REQ *)0x0;
          local_328 = (X509 *)0x0;
          bp = (BIO *)0x0;
          local_2f8 = (EVP_PKEY *)0x0;
          pEVar35 = (EVP_PKEY *)0x0;
          x = (X509 *)0x0;
LAB_0043d848:
          uVar30 = 1;
        }
      }
LAB_0043d014:
      if (bVar2) {
        app_RAND_write_file(0,bio_err);
      }
      goto LAB_0043cafc;
    }
  }
  local_314 = (_STACK *)0x0;
  local_318 = (_STACK *)0x0;
  local_31c = (_STACK *)0x0;
  local_2f4 = (X509_REQ *)0x0;
  bp = (BIO *)0x0;
  local_320 = (X509_STORE_CTX *)0x0;
  local_2f8 = (EVP_PKEY *)0x0;
  local_328 = (X509 *)0x0;
  pEVar35 = (EVP_PKEY *)0x0;
  local_324 = (X509_REQ *)0x0;
  p_Var36 = (_STACK *)0x0;
  x = (X509 *)0x0;
  uVar30 = 1;
LAB_0043cafc:
  OBJ_cleanup();
  NCONF_free((CONF *)local_31c);
  BIO_free_all(bp);
  BIO_free_all(local_310);
  X509_STORE_free(local_32c);
  X509_REQ_free(local_324);
  X509_free(x);
  X509_free(local_328);
  EVP_PKEY_free(pEVar35);
  EVP_PKEY_free(local_2f8);
  if (p_Var36 != (_STACK *)0x0) {
    sk_free(p_Var36);
  }
  X509_REQ_free(local_2f4);
  ASN1_INTEGER_free((ASN1_INTEGER *)local_320);
  sk_pop_free(local_318,ASN1_OBJECT_free);
  sk_pop_free(local_314,ASN1_OBJECT_free);
  if (local_21c != (void *)0x0) {
    CRYPTO_free(local_21c);
  }
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar30;
}

