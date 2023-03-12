
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void x509_main(int param_1,int param_2)

{
  char **ppcVar1;
  char cVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  char *pcVar8;
  X509_STORE_CTX *ctx;
  int iVar9;
  undefined4 uVar10;
  X509_STORE_CTX *pXVar11;
  BIO_METHOD *pBVar12;
  X509_STORE_CTX *x;
  long lVar13;
  int iVar14;
  ASN1_OBJECT *pAVar15;
  _STACK *sk;
  void *pvVar16;
  EVP_MD *type;
  X509_PURPOSE *xp;
  int iVar17;
  ulong uVar18;
  uchar *puVar19;
  X509_STORE_CTX *to;
  X509_NAME *pXVar20;
  ASN1_TIME *pAVar21;
  size_t sVar22;
  BIGNUM *pBVar23;
  ASN1_INTEGER *pAVar24;
  time_t tVar25;
  EVP_PKEY *pEVar26;
  char *pcVar27;
  uint uVar28;
  X509_STORE_CTX *pXVar29;
  _func_1844 *p_Var30;
  uint uVar31;
  undefined **ppuVar32;
  char *pcVar33;
  X509_STORE_CTX *pXVar34;
  char **ppcVar35;
  X509_STORE_CTX *st;
  X509_STORE *pXVar36;
  undefined4 uVar37;
  bool bVar38;
  X509_STORE_CTX *local_314;
  X509_STORE_CTX *local_310;
  X509_STORE_CTX *local_30c;
  X509_STORE_CTX *local_308;
  X509_STORE_CTX *local_304;
  X509_STORE_CTX *local_300;
  X509_STORE_CTX *local_2fc;
  X509_STORE_CTX *local_2f8;
  X509_STORE_CTX *local_2f4;
  undefined4 local_2ec;
  X509_STORE_CTX *local_2e8;
  undefined4 local_2e4;
  int local_2e0;
  X509_STORE_CTX *local_2dc;
  char *local_2d8;
  char *local_2d4;
  char *local_2d0;
  X509_STORE_CTX *local_2cc;
  char *local_2c8;
  uchar *local_2c4;
  long local_2c0;
  X509_STORE_CTX *local_2bc;
  EVP_MD *local_2b8;
  X509_STORE_CTX *local_2b4;
  char *local_2b0;
  char *local_2ac;
  X509_STORE_CTX *local_2a8;
  X509_STORE_CTX *local_2a4;
  char *local_29c;
  char *local_298;
  X509_STORE_CTX *local_294;
  X509_STORE_CTX *local_28c;
  X509_STORE_CTX *local_288;
  X509_STORE_CTX *local_284;
  X509_STORE_CTX *local_280;
  X509_STORE_CTX *local_27c;
  X509_STORE_CTX *local_278;
  X509_STORE_CTX *local_274;
  X509_STORE_CTX *local_270;
  X509_STORE_CTX *local_26c;
  X509_STORE_CTX *local_264;
  X509_STORE_CTX *local_260;
  X509_STORE_CTX *local_25c;
  X509_STORE_CTX *local_258;
  X509_STORE_CTX *local_254;
  X509_STORE_CTX *local_250;
  X509_STORE_CTX *local_24c;
  X509_STORE_CTX *local_248;
  X509_STORE_CTX *local_244;
  X509_STORE_CTX *local_240;
  X509_STORE_CTX *local_23c;
  X509_STORE_CTX *local_238;
  long local_234;
  void *local_21c;
  ulong local_218;
  ulong local_214;
  X509V3_CTX local_210;
  X509_STORE_CTX local_1f4;
  byte local_16c [64];
  char acStack_12c [256];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  reqfile = (X509_STORE_CTX *)0x0;
  local_21c = (void *)0x0;
  local_218 = 0;
  local_214 = 0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  ctx = (X509_STORE_CTX *)load_config(bio_err,0);
  if (ctx == (X509_STORE_CTX *)0x0) {
    bVar38 = true;
    pXVar11 = ctx;
    x = ctx;
    pXVar29 = ctx;
    st = ctx;
    local_314 = ctx;
    local_310 = ctx;
    local_30c = ctx;
    local_308 = ctx;
    local_304 = ctx;
    local_300 = ctx;
    local_2fc = ctx;
    local_2f8 = ctx;
    local_2f4 = ctx;
    goto LAB_0002316e;
  }
  local_2f4 = (X509_STORE_CTX *)BIO_new_fp(stdout,0);
  ctx = (X509_STORE_CTX *)X509_STORE_new();
  if (ctx == (X509_STORE_CTX *)0x0) {
    bVar38 = true;
    pXVar11 = ctx;
    x = ctx;
    pXVar29 = ctx;
    st = ctx;
    local_314 = ctx;
    local_310 = ctx;
    local_30c = ctx;
    local_308 = ctx;
    local_304 = ctx;
    local_300 = ctx;
    local_2fc = ctx;
    local_2f8 = ctx;
    goto LAB_0002316e;
  }
  param_1 = param_1 + -1;
  ppcVar35 = (char **)(param_2 + 4);
  X509_STORE_set_verify_cb((X509_STORE *)ctx,callb + 1);
  local_314 = (X509_STORE_CTX *)0x0;
  local_234 = 0;
  st = (X509_STORE_CTX *)0x0;
  bVar38 = false;
  uVar37 = 3;
  bVar5 = false;
  local_2d0 = (char *)0x0;
  local_304 = (X509_STORE_CTX *)0x0;
  local_2c8 = (char *)0x0;
  local_2b8 = (EVP_MD *)0x0;
  local_238 = (X509_STORE_CTX *)0x0;
  local_23c = (X509_STORE_CTX *)0x0;
  local_240 = (X509_STORE_CTX *)0x0;
  local_244 = (X509_STORE_CTX *)0x0;
  local_26c = (X509_STORE_CTX *)0x0;
  local_248 = (X509_STORE_CTX *)0x0;
  bVar6 = false;
  local_24c = (X509_STORE_CTX *)0x0;
  local_2b4 = (X509_STORE_CTX *)0x0;
  local_2cc = (X509_STORE_CTX *)0x0;
  bVar7 = false;
  local_270 = (X509_STORE_CTX *)0x0;
  local_274 = (X509_STORE_CTX *)0x0;
  local_250 = (X509_STORE_CTX *)0x0;
  local_2a4 = (X509_STORE_CTX *)0x0;
  local_294 = (X509_STORE_CTX *)0x0;
  local_2bc = (X509_STORE_CTX *)0x0;
  local_254 = (X509_STORE_CTX *)0x0;
  local_258 = (X509_STORE_CTX *)0x0;
  local_25c = (X509_STORE_CTX *)0x0;
  local_260 = (X509_STORE_CTX *)0x0;
  local_264 = (X509_STORE_CTX *)0x0;
  local_2a8 = (X509_STORE_CTX *)0x0;
  local_278 = (X509_STORE_CTX *)0x0;
  local_2ec = 3;
  local_27c = (X509_STORE_CTX *)0x0;
  local_280 = (X509_STORE_CTX *)0x0;
  local_284 = (X509_STORE_CTX *)0x0;
  local_288 = (X509_STORE_CTX *)0x0;
  local_28c = (X509_STORE_CTX *)0x0;
  local_2c4 = (uchar *)0x0;
  local_298 = (char *)0x0;
  local_2ac = (char *)0x0;
  local_2b0 = (char *)0x0;
  local_29c = (char *)0x0;
  local_2d4 = (char *)0x0;
  local_2d8 = (char *)0x0;
  local_2f8 = (X509_STORE_CTX *)0x0;
  local_2fc = (X509_STORE_CTX *)0x0;
  local_2e8 = (X509_STORE_CTX *)0x0;
  local_300 = (X509_STORE_CTX *)0x0;
  local_2dc = (X509_STORE_CTX *)0x3;
  local_2e4 = 3;
  local_2e0 = 3;
  local_2c0 = 0x1e;
  if (0 < param_1) {
    local_2e0 = 3;
    uVar37 = 3;
    do {
      pcVar33 = *ppcVar35;
      iVar9 = strcmp(pcVar33,"-inform");
      if (iVar9 != 0) {
        iVar9 = strcmp(pcVar33,"-outform");
        if (iVar9 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0002346e;
          local_2e0 = str2fmt(ppcVar35[1]);
          ppcVar35 = ppcVar35 + 1;
          goto LAB_00023300;
        }
        iVar9 = strcmp(pcVar33,"-keyform");
        if (iVar9 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0002346e;
          local_2e4 = str2fmt(ppcVar35[1]);
          ppcVar35 = ppcVar35 + 1;
          goto LAB_00023300;
        }
        iVar9 = strcmp(pcVar33,"-req");
        if (iVar9 == 0) {
          reqfile = (X509_STORE_CTX *)0x1;
          bVar5 = true;
          goto LAB_00023300;
        }
        iVar9 = strcmp(pcVar33,"-CAform");
        if (iVar9 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            local_2dc = (X509_STORE_CTX *)str2fmt(ppcVar35[1]);
            ppcVar35 = ppcVar35 + 1;
            goto LAB_00023300;
          }
        }
        else {
          iVar9 = strcmp(pcVar33,"-CAkeyform");
          if (iVar9 == 0) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              local_2ec = str2fmt(ppcVar35[1]);
              ppcVar35 = ppcVar35 + 1;
              goto LAB_00023300;
            }
          }
          else {
            iVar9 = strcmp(pcVar33,"-sigopt");
            if (iVar9 == 0) {
              if ((param_1 != 1) &&
                 ((st != (X509_STORE_CTX *)0x0 ||
                  (st = (X509_STORE_CTX *)sk_new_null(), st != (X509_STORE_CTX *)0x0)))) {
                pXVar11 = (X509_STORE_CTX *)sk_push((_STACK *)st,ppcVar35[1]);
                goto joined_r0x000234d0;
              }
            }
            else {
              iVar9 = strcmp(pcVar33,"-days");
              if (iVar9 == 0) {
                param_1 = param_1 + -1;
                if (param_1 != 0) {
                  local_2c0 = strtol(ppcVar35[1],(char **)0x0,10);
                  ppcVar35 = ppcVar35 + 1;
                  if (local_2c0 != 0) goto LAB_00023300;
                  BIO_printf(bio_err,"bad number of days\n");
                }
              }
              else {
                iVar9 = strcmp(pcVar33,"-passin");
                if (iVar9 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 != 0) {
                    local_2d0 = ppcVar35[1];
                    ppcVar35 = ppcVar35 + 1;
                    goto LAB_00023300;
                  }
                }
                else {
                  iVar9 = strcmp(pcVar33,"-extfile");
                  if (iVar9 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      local_304 = (X509_STORE_CTX *)ppcVar35[1];
                      ppcVar35 = ppcVar35 + 1;
                      goto LAB_00023300;
                    }
                  }
                  else {
                    iVar9 = strcmp(pcVar33,"-extensions");
                    if (iVar9 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_2c8 = ppcVar35[1];
                        ppcVar35 = ppcVar35 + 1;
                        goto LAB_00023300;
                      }
                    }
                    else {
                      cVar2 = *pcVar33;
                      if ((((cVar2 == '-') && (pcVar33[1] == 'i')) && (pcVar33[2] == 'n')) &&
                         (pcVar33[3] == '\0')) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          local_2d8 = ppcVar35[1];
                          ppcVar35 = ppcVar35 + 1;
                          goto LAB_00023300;
                        }
                      }
                      else {
                        iVar9 = strcmp(pcVar33,"-out");
                        if (iVar9 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_2d4 = ppcVar35[1];
                            ppcVar35 = ppcVar35 + 1;
                            goto LAB_00023300;
                          }
                        }
                        else {
                          iVar9 = strcmp(pcVar33,"-signkey");
                          if (iVar9 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_29c = ppcVar35[1];
                              bVar5 = true;
                              local_2e8 = (X509_STORE_CTX *)((int)&local_2e8->ctx + 1);
                              ppcVar35 = ppcVar35 + 1;
                              local_294 = local_2e8;
                              goto LAB_00023300;
                            }
                          }
                          else if (((cVar2 == '-') && (pcVar33[1] == 'C')) &&
                                  ((pcVar33[2] == 'A' && (pcVar33[3] == '\0')))) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_2b0 = ppcVar35[1];
                              bVar5 = true;
                              local_2e8 = (X509_STORE_CTX *)((int)&local_2e8->ctx + 1);
                              ppcVar35 = ppcVar35 + 1;
                              local_2a4 = local_2e8;
                              goto LAB_00023300;
                            }
                          }
                          else {
                            iVar9 = strcmp(pcVar33,"-CAkey");
                            if (iVar9 == 0) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_2ac = ppcVar35[1];
                                ppcVar35 = ppcVar35 + 1;
                                goto LAB_00023300;
                              }
                            }
                            else {
                              iVar9 = strcmp(pcVar33,"-CAserial");
                              if (iVar9 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_298 = ppcVar35[1];
                                  ppcVar35 = ppcVar35 + 1;
                                  goto LAB_00023300;
                                }
                              }
                              else {
                                iVar9 = strcmp(pcVar33,"-set_serial");
                                if (iVar9 == 0) {
                                  if (param_1 != 1) {
                                    local_300 = (X509_STORE_CTX *)
                                                s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                                 ppcVar35[1]);
                                    pXVar11 = local_300;
                                    goto joined_r0x000234d0;
                                  }
                                }
                                else {
                                  iVar9 = strcmp(pcVar33,"-addtrust");
                                  if (iVar9 == 0) {
                                    param_1 = param_1 + -1;
                                    if (param_1 != 0) {
                                      pAVar15 = OBJ_txt2obj(ppcVar35[1],0);
                                      if (pAVar15 != (ASN1_OBJECT *)0x0) {
                                        if (local_2fc == (X509_STORE_CTX *)0x0) {
                                          local_2fc = (X509_STORE_CTX *)sk_new_null();
                                        }
                                        sk_push((_STACK *)local_2fc,pAVar15);
                                        bVar7 = true;
                                        ppcVar35 = ppcVar35 + 1;
                                        goto LAB_00023300;
                                      }
                                      BIO_printf(bio_err,"Invalid trust object value %s\n",
                                                 ppcVar35[1]);
                                    }
                                  }
                                  else {
                                    iVar9 = strcmp(pcVar33,"-addreject");
                                    if (iVar9 == 0) {
                                      param_1 = param_1 + -1;
                                      if (param_1 != 0) {
                                        pAVar15 = OBJ_txt2obj(ppcVar35[1],0);
                                        if (pAVar15 != (ASN1_OBJECT *)0x0) {
                                          if (local_2f8 == (X509_STORE_CTX *)0x0) {
                                            local_2f8 = (X509_STORE_CTX *)sk_new_null();
                                          }
                                          sk_push((_STACK *)local_2f8,pAVar15);
                                          bVar7 = true;
                                          ppcVar35 = ppcVar35 + 1;
                                          goto LAB_00023300;
                                        }
                                        BIO_printf(bio_err,"Invalid reject object value %s\n",
                                                   ppcVar35[1]);
                                      }
                                    }
                                    else {
                                      iVar9 = strcmp(pcVar33,"-setalias");
                                      if (iVar9 == 0) {
                                        param_1 = param_1 + -1;
                                        if (param_1 != 0) {
                                          local_2c4 = (uchar *)ppcVar35[1];
                                          ppcVar35 = ppcVar35 + 1;
                                          bVar7 = true;
                                          goto LAB_00023300;
                                        }
                                      }
                                      else {
                                        iVar9 = strcmp(pcVar33,"-certopt");
                                        if (iVar9 == 0) {
                                          if (param_1 != 1) {
                                            pXVar11 = (X509_STORE_CTX *)
                                                      set_cert_ex(&local_214,ppcVar35[1]);
joined_r0x000234d0:
                                            param_1 = param_1 + -1;
                                            ppcVar35 = ppcVar35 + 1;
                                            if (pXVar11 != (X509_STORE_CTX *)0x0) goto LAB_00023300;
                                          }
                                        }
                                        else {
                                          iVar9 = strcmp(pcVar33,"-nameopt");
                                          if (iVar9 != 0) {
                                            iVar9 = strcmp(pcVar33,"-engine");
                                            if (iVar9 == 0) {
                                              param_1 = param_1 + -1;
                                              if (param_1 == 0) goto LAB_0002346e;
                                              local_314 = (X509_STORE_CTX *)ppcVar35[1];
                                              ppcVar35 = ppcVar35 + 1;
                                            }
                                            else if (((cVar2 == '-') && (pcVar33[1] == 'C')) &&
                                                    (pcVar33[2] == '\0')) {
                                              local_2e8 = (X509_STORE_CTX *)
                                                          ((int)&local_2e8->ctx + 1);
                                              local_248 = local_2e8;
                                            }
                                            else {
                                              iVar9 = strcmp(pcVar33,"-email");
                                              if (iVar9 == 0) {
                                                local_2e8 = (X509_STORE_CTX *)
                                                            ((int)&local_2e8->ctx + 1);
                                                local_274 = local_2e8;
                                              }
                                              else {
                                                iVar9 = strcmp(pcVar33,"-ocsp_uri");
                                                if (iVar9 == 0) {
                                                  local_2e8 = (X509_STORE_CTX *)
                                                              ((int)&local_2e8->ctx + 1);
                                                  local_270 = local_2e8;
                                                }
                                                else {
                                                  iVar9 = strcmp(pcVar33,"-serial");
                                                  if (iVar9 == 0) {
                                                    local_2e8 = (X509_STORE_CTX *)
                                                                ((int)&local_2e8->ctx + 1);
                                                    local_288 = local_2e8;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar33,"-next_serial");
                                                    if (iVar9 == 0) {
                                                      local_2e8 = (X509_STORE_CTX *)
                                                                  ((int)&local_2e8->ctx + 1);
                                                      local_2a8 = local_2e8;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(pcVar33,"-modulus");
                                                      if (iVar9 == 0) {
                                                        local_2e8 = (X509_STORE_CTX *)
                                                                    ((int)&local_2e8->ctx + 1);
                                                        local_244 = local_2e8;
                                                      }
                                                      else {
                                                        iVar9 = strcmp(pcVar33,"-pubkey");
                                                        if (iVar9 == 0) {
                                                          local_2e8 = (X509_STORE_CTX *)
                                                                      ((int)&local_2e8->ctx + 1);
                                                          local_240 = local_2e8;
                                                        }
                                                        else {
                                                          iVar9 = strcmp(pcVar33,"-x509toreq");
                                                          if (iVar9 == 0) {
                                                            local_2e8 = (X509_STORE_CTX *)
                                                                        ((int)&local_2e8->ctx + 1);
                                                            local_26c = local_2e8;
                                                          }
                                                          else {
                                                            iVar9 = strcmp(pcVar33,"-text");
                                                            if (iVar9 == 0) {
                                                              local_2e8 = (X509_STORE_CTX *)
                                                                          ((int)&local_2e8->ctx + 1)
                                                              ;
                                                              local_28c = local_2e8;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(pcVar33,"-hash");
                                                              if ((iVar9 == 0) ||
                                                                 (iVar9 = strcmp(pcVar33,
                                                  "-subject_hash"), iVar9 == 0)) {
                                                    local_2e8 = (X509_STORE_CTX *)
                                                                ((int)&local_2e8->ctx + 1);
                                                    local_264 = local_2e8;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar33,"-subject_hash_old");
                                                    if (iVar9 == 0) {
                                                      local_2e8 = (X509_STORE_CTX *)
                                                                  ((int)&local_2e8->ctx + 1);
                                                      local_258 = local_2e8;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(pcVar33,"-issuer_hash");
                                                      if (iVar9 == 0) {
                                                        local_2e8 = (X509_STORE_CTX *)
                                                                    ((int)&local_2e8->ctx + 1);
                                                        local_260 = local_2e8;
                                                      }
                                                      else {
                                                        iVar9 = strcmp(pcVar33,"-issuer_hash_old");
                                                        if (iVar9 == 0) {
                                                          local_2e8 = (X509_STORE_CTX *)
                                                                      ((int)&local_2e8->ctx + 1);
                                                          local_254 = local_2e8;
                                                        }
                                                        else {
                                                          iVar9 = strcmp(pcVar33,"-subject");
                                                          if (iVar9 == 0) {
                                                            local_2e8 = (X509_STORE_CTX *)
                                                                        ((int)&local_2e8->ctx + 1);
                                                            local_284 = local_2e8;
                                                          }
                                                          else {
                                                            iVar9 = strcmp(pcVar33,"-issuer");
                                                            if (iVar9 == 0) {
                                                              local_2e8 = (X509_STORE_CTX *)
                                                                          ((int)&local_2e8->ctx + 1)
                                                              ;
                                                              local_280 = local_2e8;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(pcVar33,"-fingerprint")
                                                              ;
                                                              if (iVar9 == 0) {
                                                                local_2e8 = (X509_STORE_CTX *)
                                                                            ((int)&local_2e8->ctx +
                                                                            1);
                                                                local_238 = local_2e8;
                                                              }
                                                              else {
                                                                iVar9 = strcmp(pcVar33,"-dates");
                                                                if (iVar9 == 0) {
                                                                  local_27c = (X509_STORE_CTX *)
                                                                              ((int)&local_2e8->ctx
                                                                              + 1);
                                                                  local_2e8 = (X509_STORE_CTX *)
                                                                              ((int)&local_2e8->ctx
                                                                              + 2);
                                                                  local_278 = local_2e8;
                                                                }
                                                                else {
                                                                  iVar9 = strcmp(pcVar33,"-purpose")
                                                                  ;
                                                                  if (iVar9 == 0) {
                                                                    local_2e8 = (X509_STORE_CTX *)
                                                                                ((int)&local_2e8->
                                                                                       ctx + 1);
                                                                    local_23c = local_2e8;
                                                                  }
                                                                  else {
                                                                    iVar9 = strcmp(pcVar33,
                                                  "-startdate");
                                                  if (iVar9 == 0) {
                                                    local_2e8 = (X509_STORE_CTX *)
                                                                ((int)&local_2e8->ctx + 1);
                                                    local_27c = local_2e8;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar33,"-enddate");
                                                    if (iVar9 == 0) {
                                                      local_2e8 = (X509_STORE_CTX *)
                                                                  ((int)&local_2e8->ctx + 1);
                                                      local_278 = local_2e8;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(pcVar33,"-checkend");
                                                      if (iVar9 == 0) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 == 0) goto LAB_0002346e;
                                                        local_234 = strtol(ppcVar35[1],(char **)0x0,
                                                                           10);
                                                        ppcVar35 = ppcVar35 + 1;
                                                        bVar38 = true;
                                                      }
                                                      else {
                                                        iVar9 = strcmp(pcVar33,"-noout");
                                                        if (iVar9 == 0) {
                                                          local_2e8 = (X509_STORE_CTX *)
                                                                      ((int)&local_2e8->ctx + 1);
                                                          local_2bc = local_2e8;
                                                        }
                                                        else {
                                                          iVar9 = strcmp(pcVar33,"-trustout");
                                                          if (iVar9 == 0) {
                                                            bVar7 = true;
                                                          }
                                                          else {
                                                            iVar9 = strcmp(pcVar33,"-clrtrust");
                                                            if (iVar9 == 0) {
                                                              local_2e8 = (X509_STORE_CTX *)
                                                                          ((int)&local_2e8->ctx + 1)
                                                              ;
                                                              local_2cc = local_2e8;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(pcVar33,"-clrreject");
                                                              if (iVar9 == 0) {
                                                                local_2e8 = (X509_STORE_CTX *)
                                                                            ((int)&local_2e8->ctx +
                                                                            1);
                                                                local_2b4 = local_2e8;
                                                              }
                                                              else {
                                                                iVar9 = strcmp(pcVar33,"-alias");
                                                                if (iVar9 == 0) {
                                                                  local_2e8 = (X509_STORE_CTX *)
                                                                              ((int)&local_2e8->ctx
                                                                              + 1);
                                                                  local_24c = local_2e8;
                                                                }
                                                                else {
                                                                  iVar9 = strcmp(pcVar33,
                                                  "-CAcreateserial");
                                                  if (iVar9 == 0) {
                                                    local_2e8 = (X509_STORE_CTX *)
                                                                ((int)&local_2e8->ctx + 1);
                                                    local_250 = local_2e8;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar33,"-clrext");
                                                    if (iVar9 == 0) {
                                                      bVar6 = true;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(pcVar33,"-crlext");
                                                      if (iVar9 == 0) {
                                                        BIO_printf(bio_err,
                                                  "use -clrext instead of -crlext\n");
                                                  bVar6 = true;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar33,"-ocspid");
                                                    if (iVar9 == 0) {
                                                      local_2e8 = (X509_STORE_CTX *)
                                                                  ((int)&local_2e8->ctx + 1);
                                                      local_25c = local_2e8;
                                                    }
                                                    else {
                                                      local_2b8 = EVP_get_digestbyname(pcVar33 + 1);
                                                      if (local_2b8 == (EVP_MD *)0x0) {
                                                        BIO_printf(bio_err,"unknown option %s\n",
                                                                   *ppcVar35);
                                                        goto LAB_0002346e;
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
                                            goto LAB_00023300;
                                          }
                                          if (param_1 != 1) {
                                            pXVar11 = (X509_STORE_CTX *)
                                                      set_name_ex(&local_218,ppcVar35[1]);
                                            goto joined_r0x000234d0;
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
LAB_0002346e:
        ppuVar32 = &x509_usage;
        pXVar11 = (X509_STORE_CTX *)x509_usage;
        while (pXVar11 != (X509_STORE_CTX *)0x0) {
          BIO_printf(bio_err,"%s");
          ppuVar32 = (undefined **)((X509_STORE_CTX **)ppuVar32 + 1);
          pXVar11 = (X509_STORE_CTX *)*ppuVar32;
        }
        bVar38 = true;
        x = pXVar11;
        pXVar29 = pXVar11;
        local_314 = pXVar11;
        local_310 = pXVar11;
        local_30c = pXVar11;
        local_308 = pXVar11;
        local_304 = pXVar11;
        goto LAB_00023450;
      }
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_0002346e;
      ppcVar1 = ppcVar35 + 1;
      ppcVar35 = ppcVar35 + 1;
      uVar37 = str2fmt(*ppcVar1);
LAB_00023300:
      param_1 = param_1 + -1;
      ppcVar35 = ppcVar35 + 1;
    } while (0 < param_1);
  }
  uVar10 = setup_engine(bio_err,local_314,0);
  if (bVar5) {
    app_RAND_load_file(0,bio_err,0);
  }
  ERR_load_crypto_strings();
  pXVar11 = (X509_STORE_CTX *)app_passwd(bio_err,local_2d0,0,&local_21c,0);
  if (pXVar11 == (X509_STORE_CTX *)0x0) {
    BIO_printf(bio_err,"Error getting password\n");
LAB_0002343e:
    bVar38 = true;
    x = pXVar11;
    pXVar29 = pXVar11;
    local_314 = pXVar11;
    local_310 = pXVar11;
    local_30c = pXVar11;
    local_308 = pXVar11;
    local_304 = pXVar11;
  }
  else {
    pXVar11 = (X509_STORE_CTX *)X509_STORE_set_default_paths((X509_STORE *)ctx);
    if (pXVar11 == (X509_STORE_CTX *)0x0) {
      ERR_print_errors(bio_err);
      goto LAB_0002343e;
    }
    local_30c = local_2a4;
    if (local_2a4 != (X509_STORE_CTX *)0x0) {
      local_30c = (X509_STORE_CTX *)0x1;
    }
    if (local_2ac == (char *)0x0) {
      uVar28 = (uint)local_30c & 1;
    }
    else {
      uVar28 = 0;
    }
    if (uVar28 != 0) {
      if (local_2dc != (X509_STORE_CTX *)0x3) {
        BIO_printf(bio_err,"need to specify a CAkey if using the CA command\n");
        pXVar11 = (X509_STORE_CTX *)0x0;
        goto LAB_0002343e;
      }
      local_2ac = local_2b0;
    }
    pXVar11 = local_304;
    if (local_304 == (X509_STORE_CTX *)0x0) {
LAB_00023692:
      local_304 = reqfile;
      if (reqfile == (X509_STORE_CTX *)0x0) {
        x = (X509_STORE_CTX *)load_cert(bio_err,local_2d8,uVar37,0,uVar10,"Certificate");
        if (x == (X509_STORE_CTX *)0x0) {
          bVar38 = true;
          pXVar29 = x;
          local_314 = x;
          local_310 = x;
          local_30c = x;
          local_308 = x;
          local_304 = x;
        }
        else {
LAB_00023808:
          if ((local_30c == (X509_STORE_CTX *)0x0) ||
             (local_30c = (X509_STORE_CTX *)
                          load_cert(bio_err,local_2b0,local_2dc,0,uVar10,"CA Certificate"),
             local_30c != (X509_STORE_CTX *)0x0)) {
            if ((local_2bc == (X509_STORE_CTX *)0x0) ||
               ((local_28c != (X509_STORE_CTX *)0x0 || (local_2a8 != (X509_STORE_CTX *)0x0)))) {
              OBJ_create("2.99999.3","SET.ex3","SET x509v3 extension 3");
              pBVar12 = BIO_s_file();
              local_314 = (X509_STORE_CTX *)BIO_new(pBVar12);
              if (local_314 == (X509_STORE_CTX *)0x0) {
                bVar38 = true;
                ERR_print_errors(bio_err);
                pXVar29 = local_314;
                local_310 = local_314;
                local_308 = local_314;
                goto LAB_00023450;
              }
              if (local_2d4 == (char *)0x0) {
                BIO_ctrl((BIO *)local_314,0x6a,0,stdout);
              }
              else {
                lVar13 = BIO_ctrl((BIO *)local_314,0x6c,5,local_2d4);
                if (lVar13 < 1) {
                  perror(local_2d4);
                  bVar38 = true;
                  local_308 = (X509_STORE_CTX *)0x0;
                  local_310 = (X509_STORE_CTX *)0x0;
                  pXVar29 = (X509_STORE_CTX *)0x0;
                  goto LAB_00023450;
                }
              }
            }
            else {
              local_314 = local_2a8;
            }
            if (local_2c4 != (uchar *)0x0) {
              X509_alias_set1((X509 *)x,local_2c4,-1);
            }
            if (local_2cc != (X509_STORE_CTX *)0x0) {
              X509_trust_clear((X509 *)x);
            }
            if (local_2b4 != (X509_STORE_CTX *)0x0) {
              X509_reject_clear((X509 *)x);
            }
            if (local_2fc != (X509_STORE_CTX *)0x0) {
              for (iVar9 = 0; iVar14 = sk_num((_STACK *)local_2fc), iVar9 < iVar14;
                  iVar9 = iVar9 + 1) {
                pAVar15 = (ASN1_OBJECT *)sk_value((_STACK *)local_2fc,iVar9);
                X509_add1_trust_object((X509 *)x,pAVar15);
              }
            }
            if (local_2f8 != (X509_STORE_CTX *)0x0) {
              for (iVar9 = 0; iVar14 = sk_num((_STACK *)local_2f8), iVar9 < iVar14;
                  iVar9 = iVar9 + 1) {
                pAVar15 = (ASN1_OBJECT *)sk_value((_STACK *)local_2f8,iVar9);
                X509_add1_reject_object((X509 *)x,pAVar15);
              }
            }
            if (local_2e8 != (X509_STORE_CTX *)0x0) {
              pXVar34 = (X509_STORE_CTX *)0x1;
              local_308 = (X509_STORE_CTX *)0x0;
              local_310 = (X509_STORE_CTX *)0x0;
              local_2dc = (X509_STORE_CTX *)0x0;
LAB_000239ee:
              if (local_280 == pXVar34) {
                pXVar20 = X509_get_issuer_name((X509 *)x);
                print_name(local_2f4,"issuer= ",pXVar20,local_218);
              }
              else if (local_284 == pXVar34) {
                pXVar20 = X509_get_subject_name((X509 *)x);
                print_name(local_2f4,"subject= ",pXVar20,local_218);
              }
              else if (local_288 == pXVar34) {
                BIO_printf((BIO *)local_2f4,"serial=");
                pAVar24 = X509_get_serialNumber((X509 *)x);
                i2a_ASN1_INTEGER((BIO *)local_2f4,pAVar24);
                BIO_printf((BIO *)local_2f4,"\n");
              }
              else {
                pXVar29 = local_2dc;
                if (local_2a8 == pXVar34) {
                  pAVar24 = X509_get_serialNumber((X509 *)x);
                  pBVar23 = ASN1_INTEGER_to_BN(pAVar24,(BIGNUM *)0x0);
                  if (((pBVar23 == (BIGNUM *)0x0) || (iVar9 = BN_add_word(pBVar23,1), iVar9 == 0))
                     || (pAVar24 = BN_to_ASN1_INTEGER(pBVar23,(ASN1_INTEGER *)0x0),
                        pAVar24 == (ASN1_INTEGER *)0x0)) goto LAB_00023c40;
                  BN_free(pBVar23);
                  i2a_ASN1_INTEGER((BIO *)local_314,pAVar24);
                  ASN1_INTEGER_free(pAVar24);
                  BIO_puts((BIO *)local_314,"\n");
                }
                else {
                  uVar31 = count_leading_zeroes((int)local_274 - (int)pXVar34);
                  uVar31 = uVar31 >> 5;
                  uVar28 = uVar31;
                  if (local_270 == pXVar34) {
                    uVar28 = uVar31 | 1;
                  }
                  if (uVar28 == 0) {
                    if (local_24c == pXVar34) {
                      puVar19 = X509_alias_get0((X509 *)x,(int *)0x0);
                      if (puVar19 == (uchar *)0x0) {
                        BIO_puts((BIO *)local_2f4,"<No Alias>\n");
                      }
                      else {
                        BIO_printf((BIO *)local_2f4,"%s\n",puVar19);
                      }
                    }
                    else {
                      if (local_264 == pXVar34) {
                        uVar18 = X509_subject_name_hash((X509 *)x);
                      }
                      else if (local_258 == pXVar34) {
                        uVar18 = X509_subject_name_hash_old((X509 *)x);
                      }
                      else if (local_260 == pXVar34) {
                        uVar18 = X509_issuer_name_hash((X509 *)x);
                      }
                      else {
                        if (local_254 != pXVar34) {
                          if (local_23c == pXVar34) {
                            BIO_printf((BIO *)local_2f4,"Certificate purposes:\n");
                            for (iVar9 = 0; iVar14 = X509_PURPOSE_get_count(), iVar9 < iVar14;
                                iVar9 = iVar9 + 1) {
                              xp = X509_PURPOSE_get0(iVar9);
                              iVar14 = X509_PURPOSE_get_id(xp);
                              pcVar33 = X509_PURPOSE_get0_name(xp);
                              iVar17 = X509_check_purpose((X509 *)x,iVar14,0);
                              BIO_printf((BIO *)local_2f4,"%s%s : ",pcVar33,"");
                              if (iVar17 == 1) {
                                BIO_printf((BIO *)local_2f4,"Yes\n");
                              }
                              else if (iVar17 == 0) {
                                BIO_printf((BIO *)local_2f4,"No\n");
                              }
                              else {
                                BIO_printf((BIO *)local_2f4,"Yes (WARNING code=%d)\n",iVar17);
                              }
                              iVar14 = X509_check_purpose((X509 *)x,iVar14,1);
                              BIO_printf((BIO *)local_2f4,"%s%s : ",pcVar33,&DAT_0012b7e0);
                              if (iVar14 == 1) {
                                BIO_printf((BIO *)local_2f4,"Yes\n");
                              }
                              else if (iVar14 == 0) {
                                BIO_printf((BIO *)local_2f4,"No\n");
                              }
                              else {
                                BIO_printf((BIO *)local_2f4,"Yes (WARNING code=%d)\n",iVar14);
                              }
                            }
                          }
                          else if (local_244 == pXVar34) {
                            pEVar26 = X509_get_pubkey((X509 *)x);
                            if (pEVar26 == (EVP_PKEY *)0x0) {
                              bVar38 = true;
                              BIO_printf(bio_err,"Modulus=unavailable\n");
                              ERR_print_errors(bio_err);
                              goto LAB_00023450;
                            }
                            BIO_printf((BIO *)local_2f4,"Modulus=");
                            if (pEVar26->type == 6) {
                              BN_print(local_2f4,((pEVar26->pkey).rsa)->n);
                            }
                            else if (pEVar26->type == 0x74) {
                              BN_print(local_2f4,((pEVar26->pkey).rsa)->d);
                            }
                            else {
                              BIO_printf((BIO *)local_2f4,"Wrong Algorithm type");
                            }
                            BIO_printf((BIO *)local_2f4,"\n");
                            EVP_PKEY_free(pEVar26);
                          }
                          else if (local_240 == pXVar34) {
                            pEVar26 = X509_get_pubkey((X509 *)x);
                            if (pEVar26 == (EVP_PKEY *)0x0) {
                              bVar38 = true;
                              BIO_printf(bio_err,"Error getting public key\n");
                              ERR_print_errors(bio_err);
                              goto LAB_00023450;
                            }
                            PEM_write_bio_PUBKEY((BIO *)local_2f4,pEVar26);
                            EVP_PKEY_free(pEVar26);
                          }
                          else if (local_248 == pXVar34) {
                            pXVar20 = X509_get_subject_name((X509 *)x);
                            X509_NAME_oneline(pXVar20,acStack_12c,0x100);
                            BIO_printf((BIO *)local_2f4,"/* subject:%s */\n",acStack_12c);
                            pXVar20 = X509_get_issuer_name((X509 *)x);
                            X509_NAME_oneline(pXVar20,acStack_12c,0x100);
                            BIO_printf((BIO *)local_2f4,"/* issuer :%s */\n",acStack_12c);
                            iVar9 = i2d_X509((X509 *)x,(uchar **)0x0);
                            pXVar36 = (X509_STORE *)CRYPTO_malloc(iVar9,"x509.c",0x311);
                            if (pXVar36 == (X509_STORE *)0x0) {
                              bVar38 = true;
                              BIO_printf(bio_err,"Out of memory\n");
                              ERR_print_errors(bio_err);
                              goto LAB_00023450;
                            }
                            local_1f4.ctx = pXVar36;
                            pXVar20 = X509_get_subject_name((X509 *)x);
                            uVar28 = i2d_X509_NAME(pXVar20,(uchar **)&local_1f4);
                            BIO_printf((BIO *)local_2f4,"unsigned char XXX_subject_name[%d]={\n",
                                       uVar28);
                            local_1f4.ctx = pXVar36;
                            for (uVar31 = 0; (int)uVar31 < (int)uVar28; uVar31 = uVar31 + 1) {
                              BIO_printf((BIO *)local_2f4,"0x%02X,",
                                         (uint)*(byte *)((int)&(local_1f4.ctx)->cache + uVar31));
                              if ((uVar31 & 0xf) == 0xf) {
                                BIO_printf((BIO *)local_2f4,"\n");
                              }
                            }
                            if ((uVar28 & ~((int)uVar28 >> 0x1f) & 0xf) != 0) {
                              BIO_printf((BIO *)local_2f4,"\n");
                            }
                            BIO_printf((BIO *)local_2f4,"};\n");
                            uVar28 = i2d_X509_PUBKEY((X509_PUBKEY *)x->ctx->get_issuer,
                                                     (uchar **)&local_1f4);
                            BIO_printf((BIO *)local_2f4,"unsigned char XXX_public_key[%d]={\n",
                                       uVar28);
                            local_1f4.ctx = pXVar36;
                            for (uVar31 = 0; (int)uVar31 < (int)uVar28; uVar31 = uVar31 + 1) {
                              BIO_printf((BIO *)local_2f4,"0x%02X,",
                                         (uint)*(byte *)((int)&(local_1f4.ctx)->cache + uVar31));
                              if ((uVar31 & 0xf) == 0xf) {
                                BIO_printf((BIO *)local_2f4,"\n");
                              }
                            }
                            if ((uVar28 & ~((int)uVar28 >> 0x1f) & 0xf) != 0) {
                              BIO_printf((BIO *)local_2f4,"\n");
                            }
                            BIO_printf((BIO *)local_2f4,"};\n");
                            uVar28 = i2d_X509((X509 *)x,(uchar **)&local_1f4);
                            BIO_printf((BIO *)local_2f4,"unsigned char XXX_certificate[%d]={\n",
                                       uVar28);
                            local_1f4.ctx = pXVar36;
                            for (uVar31 = 0; (int)uVar31 < (int)uVar28; uVar31 = uVar31 + 1) {
                              BIO_printf((BIO *)local_2f4,"0x%02X,",
                                         (uint)*(byte *)((int)&(local_1f4.ctx)->cache + uVar31));
                              if ((uVar31 & 0xf) == 0xf) {
                                BIO_printf((BIO *)local_2f4,"\n");
                              }
                            }
                            if ((uVar28 & ~((int)uVar28 >> 0x1f) & 0xf) != 0) {
                              BIO_printf((BIO *)local_2f4,"\n");
                            }
                            BIO_printf((BIO *)local_2f4,"};\n");
                            CRYPTO_free(pXVar36);
                          }
                          else {
                            if (local_28c != pXVar34) {
                              if (local_27c == pXVar34) {
                                BIO_puts((BIO *)local_2f4,"notBefore=");
                                pAVar21 = *(ASN1_TIME **)x->ctx->verify;
                              }
                              else {
                                if (local_278 != pXVar34) {
                                  if (local_238 == pXVar34) {
                                    type = local_2b8;
                                    if (local_2b8 == (EVP_MD *)0x0) {
                                      type = EVP_sha1();
                                    }
                                    iVar9 = X509_digest((X509 *)x,type,local_16c,(uint *)&local_1f4)
                                    ;
                                    if (iVar9 != 0) {
                                      pXVar36 = (X509_STORE *)0x0;
                                      iVar9 = EVP_MD_type(type);
                                      pcVar33 = OBJ_nid2sn(iVar9);
                                      BIO_printf((BIO *)local_2f4,"%s Fingerprint=",pcVar33);
                                      while ((int)pXVar36 < (int)local_1f4.ctx) {
                                        pbVar3 = local_16c + (int)pXVar36;
                                        pXVar36 = (X509_STORE *)((int)&pXVar36->cache + 1);
                                        if (local_1f4.ctx == pXVar36) {
                                          uVar37 = 10;
                                        }
                                        else {
                                          uVar37 = 0x3a;
                                        }
                                        BIO_printf((BIO *)local_2f4,"%02X%c",(uint)*pbVar3,uVar37);
                                      }
                                      goto LAB_00023a62;
                                    }
                                    bVar38 = true;
                                    BIO_printf(bio_err,"out of memory\n");
                                    goto LAB_00023450;
                                  }
                                  if (local_294 == pXVar34 && local_26c == (X509_STORE_CTX *)0x0) {
                                    BIO_printf(bio_err,"Getting Private key\n");
                                    if ((local_310 != (X509_STORE_CTX *)0x0) ||
                                       (local_310 = (X509_STORE_CTX *)
                                                    load_key(bio_err,local_29c,local_2e4,0,local_21c
                                                             ,uVar10,"Private key"),
                                       local_310 != (X509_STORE_CTX *)0x0)) {
                                      if (!bVar5) {
                    /* WARNING: Subroutine does not return */
                                        __assert_fail("need_rand","x509.c",0x36a,"x509_main");
                                      }
                                      pEVar26 = X509_get_pubkey((X509 *)x);
                                      if (pEVar26 != (EVP_PKEY *)0x0) {
                                        EVP_PKEY_copy_parameters(pEVar26,(EVP_PKEY *)local_310);
                                        EVP_PKEY_save_parameters(pEVar26,1);
                                        EVP_PKEY_free(pEVar26);
                                        pXVar20 = X509_get_subject_name((X509 *)x);
                                        iVar9 = X509_set_issuer_name((X509 *)x,pXVar20);
                                        if (((iVar9 != 0) &&
                                            (pAVar21 = X509_gmtime_adj(*(ASN1_TIME **)x->ctx->verify
                                                                       ,0),
                                            pAVar21 != (ASN1_TIME *)0x0)) &&
                                           ((pAVar21 = X509_time_adj_ex(*(ASN1_TIME **)
                                                                         (x->ctx->verify + 4),
                                                                        local_2c0,0,(time_t *)0x0),
                                            pAVar21 != (ASN1_TIME *)0x0 &&
                                            (iVar9 = X509_set_pubkey((X509 *)x,(EVP_PKEY *)local_310
                                                                    ), iVar9 != 0)))) {
                                          if (bVar6) {
                                            while (iVar9 = X509_get_ext_count((X509 *)x), 0 < iVar9)
                                            {
                                              X509_delete_ext((X509 *)x,0);
                                            }
                                          }
                                          if (pXVar11 != (X509_STORE_CTX *)0x0) {
                                            X509_set_version((X509 *)x,2);
                                            X509V3_set_ctx((X509V3_CTX *)&local_1f4,(X509 *)x,
                                                           (X509 *)x,(X509_REQ *)0x0,(X509_CRL *)0x0
                                                           ,0);
                                            X509V3_set_nconf((X509V3_CTX *)&local_1f4,
                                                             (CONF *)pXVar11);
                                            iVar9 = X509V3_EXT_add_nconf
                                                              ((CONF *)pXVar11,
                                                               (X509V3_CTX *)&local_1f4,local_2c8,
                                                               (X509 *)x);
                                            if (iVar9 == 0) goto LAB_00023b58;
                                          }
                                          iVar9 = X509_sign((X509 *)x,(EVP_PKEY *)local_310,
                                                            local_2b8);
                                          if (iVar9 != 0) goto LAB_00023a62;
                                        }
                                      }
LAB_00023b58:
                                      bVar38 = true;
                                      ERR_print_errors(bio_err);
                                      goto LAB_00023450;
                                    }
                                  }
                                  else {
                                    if (local_2a4 != pXVar34) {
                                      if (local_26c != pXVar34) {
                                        if (local_25c == pXVar34) {
                                          X509_ocspid_print((BIO *)local_314,(X509 *)x);
                                        }
                                        goto LAB_00023a62;
                                      }
                                      BIO_printf(bio_err,"Getting request Private Key\n");
                                      if (local_29c == (char *)0x0) {
                                        bVar38 = true;
                                        BIO_printf(bio_err,"no request key file specified\n");
                                        goto LAB_00023450;
                                      }
                                      pEVar26 = (EVP_PKEY *)
                                                load_key(bio_err,local_29c,local_2e4,0,local_21c,
                                                         uVar10,"request key");
                                      if (pEVar26 == (EVP_PKEY *)0x0) goto LAB_00023c40;
                                      BIO_printf(bio_err,"Generating certificate request\n");
                                      local_2dc = (X509_STORE_CTX *)
                                                  X509_to_X509_REQ((X509 *)x,pEVar26,local_2b8);
                                      EVP_PKEY_free(pEVar26);
                                      if (local_2dc == (X509_STORE_CTX *)0x0) {
                                        bVar38 = true;
                                        ERR_print_errors(bio_err);
                                        pXVar29 = local_2dc;
                                        goto LAB_00023450;
                                      }
                                      if (local_2bc == (X509_STORE_CTX *)0x0) {
                                        X509_REQ_print((BIO *)local_314,(X509_REQ *)local_2dc);
                                        PEM_write_bio_X509_REQ
                                                  ((BIO *)local_314,(X509_REQ *)local_2dc);
                                        local_2bc = (X509_STORE_CTX *)0x1;
                                      }
                                      else {
                                        local_2bc = (X509_STORE_CTX *)0x1;
                                      }
                                      goto LAB_00023a62;
                                    }
                                    BIO_printf(bio_err,"Getting CA Private Key\n");
                                    if ((local_2ac != (char *)0x0) &&
                                       (local_308 = (X509_STORE_CTX *)
                                                    load_key(bio_err,local_2ac,local_2ec,0,local_21c
                                                             ,uVar10,"CA Private Key"),
                                       local_308 == (X509_STORE_CTX *)0x0)) goto LAB_00023c40;
                                    if (!bVar5) {
                    /* WARNING: Subroutine does not return */
                                      __assert_fail("need_rand","x509.c",0x377,"x509_main");
                                    }
                                    to = (X509_STORE_CTX *)X509_get_pubkey((X509 *)local_30c);
                                    if (to == (X509_STORE_CTX *)0x0) {
                                      BIO_printf(bio_err,"Error obtaining CA X509 public key\n");
LAB_0002429a:
                                      bVar4 = false;
                                      X509_STORE_CTX_cleanup(&local_1f4);
                                      ERR_print_errors(bio_err);
                                    }
                                    else {
                                      EVP_PKEY_copy_parameters((EVP_PKEY *)to,(EVP_PKEY *)local_308)
                                      ;
                                      EVP_PKEY_free((EVP_PKEY *)to);
                                      to = (X509_STORE_CTX *)
                                           X509_STORE_CTX_init(&local_1f4,(X509_STORE *)ctx,
                                                               (X509 *)x,(stack_st_X509 *)0x0);
                                      if (to == (X509_STORE_CTX *)0x0) {
                                        BIO_printf(bio_err,"Error initialising X509 store\n");
                                        goto LAB_0002429a;
                                      }
                                      to = local_300;
                                      if (local_300 == (X509_STORE_CTX *)0x0) {
                                        local_210.flags = (int)local_300;
                                        if (local_298 == (char *)0x0) {
                                          sVar22 = strlen(local_2b0);
                                          sVar22 = sVar22 + 6;
                                          pcVar33 = (char *)CRYPTO_malloc(sVar22,"x509.c",0x3f0);
                                          if (pcVar33 == (char *)0x0) goto LAB_000243e6;
                                          BUF_strlcpy(pcVar33,local_2b0,sVar22);
                                          pcVar8 = pcVar33;
                                          do {
                                            pcVar27 = pcVar8;
                                            if (*pcVar27 == '\0') goto LAB_0002443c;
                                            pcVar8 = pcVar27 + 1;
                                          } while (*pcVar27 != '.');
                                          *pcVar27 = '\0';
LAB_0002443c:
                                          BUF_strlcat(pcVar33,".srl",sVar22);
LAB_000243a6:
                                          pBVar23 = (BIGNUM *)load_serial(pcVar33,local_250,0);
                                          if (pBVar23 != (BIGNUM *)0x0) {
                                            iVar9 = BN_add_word(pBVar23,1);
                                            if (iVar9 == 0) {
                                              BIO_printf(bio_err,"add_word failure\n");
                                            }
                                            else {
                                              save_serial(pcVar33,0,pBVar23,&local_210);
                                            }
                                          }
                                          CRYPTO_free(pcVar33);
                                        }
                                        else {
                                          sVar22 = strlen(local_298);
                                          pcVar33 = (char *)CRYPTO_malloc(sVar22 + 1,"x509.c",0x3f0)
                                          ;
                                          if (pcVar33 != (char *)0x0) {
                                            BUF_strlcpy(pcVar33,local_298,sVar22 + 1);
                                            goto LAB_000243a6;
                                          }
LAB_000243e6:
                                          pBVar23 = (BIGNUM *)0x0;
                                          BIO_printf(bio_err,"out of mem\n");
                                        }
                                        BN_free(pBVar23);
                                        to = (X509_STORE_CTX *)local_210.flags;
                                        if ((X509_STORE_CTX *)local_210.flags ==
                                            (X509_STORE_CTX *)0x0) goto LAB_0002429a;
                                      }
                                      X509_STORE_CTX_set_cert(&local_1f4,(X509 *)x);
                                      X509_STORE_CTX_set_flags(&local_1f4,0x4000);
                                      if ((reqfile == (X509_STORE_CTX *)0x0) &&
                                         (iVar9 = X509_verify_cert(&local_1f4), iVar9 < 1))
                                      goto LAB_0002429a;
                                      iVar9 = X509_check_private_key
                                                        ((X509 *)local_30c,(EVP_PKEY *)local_308);
                                      if (iVar9 == 0) {
                                        BIO_printf(bio_err,
                                                  "CA certificate and CA private key do not match\n"
                                                  );
                                        goto LAB_0002429a;
                                      }
                                      pXVar20 = X509_get_subject_name((X509 *)local_30c);
                                      iVar9 = X509_set_issuer_name((X509 *)x,pXVar20);
                                      if ((((iVar9 == 0) ||
                                           (iVar9 = X509_set_serialNumber
                                                              ((X509 *)x,(ASN1_INTEGER *)to),
                                           iVar9 == 0)) ||
                                          (pAVar21 = X509_gmtime_adj(*(ASN1_TIME **)x->ctx->verify,0
                                                                    ), pAVar21 == (ASN1_TIME *)0x0))
                                         || (pAVar21 = X509_time_adj_ex(*(ASN1_TIME **)
                                                                         (x->ctx->verify + 4),
                                                                        local_2c0,0,(time_t *)0x0),
                                            pAVar21 == (ASN1_TIME *)0x0)) goto LAB_0002429a;
                                      if (bVar6) {
                                        while (iVar9 = X509_get_ext_count((X509 *)x), 0 < iVar9) {
                                          X509_delete_ext((X509 *)x,0);
                                        }
                                      }
                                      if (pXVar11 != (X509_STORE_CTX *)0x0) {
                                        X509_set_version((X509 *)x,2);
                                        X509V3_set_ctx(&local_210,(X509 *)local_30c,(X509 *)x,
                                                       (X509_REQ *)0x0,(X509_CRL *)0x0,0);
                                        X509V3_set_nconf(&local_210,(CONF *)pXVar11);
                                        iVar9 = X509V3_EXT_add_nconf
                                                          ((CONF *)pXVar11,&local_210,local_2c8,
                                                           (X509 *)x);
                                        if (iVar9 == 0) goto LAB_0002429a;
                                      }
                                      iVar9 = do_X509_sign(bio_err,x,local_308,local_2b8,st);
                                      if (iVar9 == 0) goto LAB_0002429a;
                                      bVar4 = true;
                                      X509_STORE_CTX_cleanup(&local_1f4);
                                    }
                                    if (local_300 == (X509_STORE_CTX *)0x0) {
                                      ASN1_INTEGER_free((ASN1_INTEGER *)to);
                                    }
                                    if (bVar4) goto LAB_00023a62;
                                  }
LAB_00023c40:
                                  bVar38 = true;
                                  goto LAB_00023450;
                                }
                                BIO_puts((BIO *)local_2f4,"notAfter=");
                                pAVar21 = *(ASN1_TIME **)(x->ctx->verify + 4);
                              }
                              ASN1_TIME_print((BIO *)local_2f4,pAVar21);
                              BIO_puts((BIO *)local_2f4,"\n");
                              goto LAB_00023a62;
                            }
                            X509_print_ex((BIO *)local_2f4,(X509 *)x,local_218,local_214);
                          }
                          goto LAB_00023a62;
                        }
                        uVar18 = X509_issuer_name_hash_old((X509 *)x);
                      }
                      BIO_printf((BIO *)local_2f4,"%08lx\n",uVar18);
                    }
                  }
                  else {
                    if (uVar31 == 0) {
                      sk = (_STACK *)X509_get1_ocsp((X509 *)x);
                    }
                    else {
                      sk = (_STACK *)X509_get1_email((X509 *)x);
                    }
                    for (iVar9 = 0; iVar14 = sk_num(sk), iVar9 < iVar14; iVar9 = iVar9 + 1) {
                      pvVar16 = sk_value(sk,iVar9);
                      BIO_printf((BIO *)local_2f4,"%s\n",pvVar16);
                    }
                    X509_email_free((stack_st_OPENSSL_STRING *)sk);
                  }
                }
              }
LAB_00023a62:
              pXVar34 = (X509_STORE_CTX *)((int)&pXVar34->ctx + 1);
              if ((int)local_2e8 < (int)pXVar34) goto LAB_000238de;
              goto LAB_000239ee;
            }
            local_308 = local_2e8;
            local_310 = local_2e8;
            local_2dc = local_2e8;
LAB_000238de:
            pXVar29 = local_2dc;
            if (bVar38) {
              tVar25 = time((time_t *)0x0);
              local_1f4.ctx = (X509_STORE *)(local_234 + tVar25);
              iVar9 = X509_cmp_time(*(ASN1_TIME **)(x->ctx->verify + 4),(time_t *)&local_1f4);
              bVar38 = iVar9 < 0;
              if (bVar38) {
                pcVar33 = "Certificate will expire\n";
              }
              else {
                pcVar33 = "Certificate will not expire\n";
              }
              BIO_printf((BIO *)local_314,pcVar33);
            }
            else {
              if (local_2bc == (X509_STORE_CTX *)0x0) {
                if (local_2e0 == 1) {
                  iVar9 = i2d_X509_bio((BIO *)local_314,(X509 *)x);
                }
                else if (local_2e0 == 3) {
                  if (bVar7) {
                    iVar9 = PEM_write_bio_X509_AUX((BIO *)local_314,(X509 *)x);
                  }
                  else {
                    iVar9 = PEM_write_bio_X509((BIO *)local_314,(X509 *)x);
                  }
                }
                else {
                  if (local_2e0 != 4) {
                    bVar38 = true;
                    BIO_printf(bio_err,"bad output format specified for outfile\n");
                    goto LAB_00023450;
                  }
                  local_1f4.cert = (X509 *)0x13cf48;
                  local_210.flags = (int)&local_1f4;
                  local_1f4.ctx = (X509_STORE *)0xb;
                  local_210.issuer_cert = (X509 *)x;
                  iVar9 = ASN1_item_i2d_bio((ASN1_ITEM *)&NETSCAPE_X509_it,(BIO *)local_314,
                                            &local_210);
                }
                if (iVar9 == 0) {
                  bVar38 = true;
                  BIO_printf(bio_err,"unable to write certificate\n");
                  ERR_print_errors(bio_err);
                  goto LAB_00023450;
                }
              }
              bVar38 = false;
            }
          }
          else {
            bVar38 = true;
            pXVar29 = local_30c;
            local_314 = local_30c;
            local_310 = local_30c;
            local_308 = local_30c;
          }
        }
      }
      else {
        pXVar29 = (X509_STORE_CTX *)((uint)local_2a4 | (uint)local_294);
        if (pXVar29 == (X509_STORE_CTX *)0x0) {
          BIO_printf(bio_err,"We need a private key to sign with\n");
LAB_000236ba:
          bVar38 = true;
          x = pXVar29;
          local_314 = pXVar29;
          local_310 = pXVar29;
          local_30c = pXVar29;
          local_308 = pXVar29;
          local_304 = pXVar29;
        }
        else {
          pBVar12 = BIO_s_file();
          x = (X509_STORE_CTX *)BIO_new(pBVar12);
          if (x == (X509_STORE_CTX *)0x0) {
            bVar38 = true;
            ERR_print_errors(bio_err);
            pXVar29 = x;
            local_314 = x;
            local_310 = x;
            local_30c = x;
            local_308 = x;
            local_304 = x;
          }
          else {
            if (local_2d8 == (char *)0x0) {
              BIO_ctrl((BIO *)x,0x6a,0x10,stdin);
            }
            else {
              lVar13 = BIO_ctrl((BIO *)x,0x6c,3,local_2d8);
              if (lVar13 < 1) {
                pXVar29 = (X509_STORE_CTX *)0x0;
                perror(local_2d8);
                BIO_free((BIO *)x);
                goto LAB_000236ba;
              }
            }
            local_304 = (X509_STORE_CTX *)
                        PEM_read_bio_X509_REQ
                                  ((BIO *)x,(X509_REQ **)0x0,(undefined1 *)0x0,(void *)0x0);
            BIO_free((BIO *)x);
            if (local_304 == (X509_STORE_CTX *)0x0) {
              ERR_print_errors(bio_err);
              bVar38 = true;
              x = local_304;
              pXVar29 = local_304;
              local_314 = local_304;
              local_310 = local_304;
              local_30c = local_304;
              local_308 = local_304;
            }
            else {
              if ((((local_304->ctx == (X509_STORE *)0x0) ||
                   (p_Var30 = local_304->ctx->verify_cb, p_Var30 == (_func_1844 *)0x0)) ||
                  (iVar9 = *(int *)(p_Var30 + 4), iVar9 == 0)) || (*(int *)(iVar9 + 8) == 0)) {
                pXVar29 = (X509_STORE_CTX *)0x0;
                BIO_printf(bio_err,"The certificate request appears to corrupted\n");
                BIO_printf(bio_err,"It does not contain a public key\n");
              }
              else {
                x = (X509_STORE_CTX *)X509_REQ_get_pubkey((X509_REQ *)local_304);
                if (x == (X509_STORE_CTX *)0x0) {
                  BIO_printf(bio_err,"error unpacking public key\n");
                  pXVar29 = x;
                  local_314 = local_300;
LAB_000248aa:
                  local_300 = local_314;
                  bVar38 = true;
                  local_314 = pXVar29;
                  local_310 = pXVar29;
                  local_30c = pXVar29;
                  local_308 = pXVar29;
                  goto LAB_00023450;
                }
                pXVar29 = (X509_STORE_CTX *)X509_REQ_verify((X509_REQ *)local_304,(EVP_PKEY *)x);
                EVP_PKEY_free((EVP_PKEY *)x);
                if ((int)pXVar29 < 0) {
                  pXVar29 = (X509_STORE_CTX *)0x0;
                  BIO_printf(bio_err,"Signature verification error\n");
                  ERR_print_errors(bio_err);
                }
                else {
                  if (pXVar29 != (X509_STORE_CTX *)0x0) {
                    BIO_printf(bio_err,"Signature ok\n");
                    print_name(bio_err,"subject=",local_304->ctx->verify,local_218);
                    x = (X509_STORE_CTX *)X509_new();
                    if (x == (X509_STORE_CTX *)0x0) {
                      bVar38 = true;
                      pXVar29 = x;
                      local_314 = x;
                      local_310 = x;
                      local_30c = x;
                      local_308 = x;
                    }
                    else if (local_300 == (X509_STORE_CTX *)0x0) {
                      local_314 = (X509_STORE_CTX *)ASN1_INTEGER_new();
                      if (local_314 != (X509_STORE_CTX *)0x0) {
                        pXVar29 = (X509_STORE_CTX *)rand_serial(0,local_314);
                        if ((pXVar29 == (X509_STORE_CTX *)0x0) ||
                           (pXVar29 = (X509_STORE_CTX *)
                                      X509_set_serialNumber((X509 *)x,(ASN1_INTEGER *)local_314),
                           pXVar29 == (X509_STORE_CTX *)0x0)) goto LAB_000248aa;
                        ASN1_INTEGER_free((ASN1_INTEGER *)local_314);
                        goto LAB_0002486e;
                      }
                      bVar38 = true;
                      pXVar29 = local_314;
                      local_310 = local_314;
                      local_30c = local_314;
                      local_308 = local_314;
                      local_300 = local_314;
                    }
                    else {
                      pXVar29 = (X509_STORE_CTX *)
                                X509_set_serialNumber((X509 *)x,(ASN1_INTEGER *)local_300);
                      if (pXVar29 != (X509_STORE_CTX *)0x0) {
LAB_0002486e:
                        pXVar29 = (X509_STORE_CTX *)
                                  X509_set_issuer_name
                                            ((X509 *)x,(X509_NAME *)local_304->ctx->verify);
                        if ((pXVar29 != (X509_STORE_CTX *)0x0) &&
                           (pXVar29 = (X509_STORE_CTX *)
                                      X509_set_subject_name
                                                ((X509 *)x,(X509_NAME *)local_304->ctx->verify),
                           pXVar29 != (X509_STORE_CTX *)0x0)) {
                          X509_gmtime_adj(*(ASN1_TIME **)x->ctx->verify,0);
                          X509_time_adj_ex(*(ASN1_TIME **)(x->ctx->verify + 4),local_2c0,0,
                                           (time_t *)0x0);
                          pEVar26 = X509_REQ_get_pubkey((X509_REQ *)local_304);
                          X509_set_pubkey((X509 *)x,pEVar26);
                          EVP_PKEY_free(pEVar26);
                          goto LAB_00023808;
                        }
                      }
                      bVar38 = true;
                      local_314 = pXVar29;
                      local_310 = pXVar29;
                      local_30c = pXVar29;
                      local_308 = pXVar29;
                    }
                    goto LAB_00023450;
                  }
                  BIO_printf(bio_err,"Signature did not match the certificate request\n");
                }
              }
              bVar38 = true;
              x = pXVar29;
              local_314 = pXVar29;
              local_310 = pXVar29;
              local_30c = pXVar29;
              local_308 = pXVar29;
            }
          }
        }
      }
    }
    else {
      local_210.flags = -1;
      pXVar11 = (X509_STORE_CTX *)NCONF_new((CONF_METHOD *)0x0);
      iVar9 = NCONF_load((CONF *)pXVar11,(char *)local_304,&local_210.flags);
      if (iVar9 == 0) {
        if (local_210.flags < 1) {
          BIO_printf(bio_err,"error loading the config file \'%s\'\n",local_304);
        }
        else {
          BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_210.flags,local_304);
        }
      }
      else {
        if ((local_2c8 == (char *)0x0) &&
           (local_2c8 = NCONF_get_string((CONF *)pXVar11,"default","extensions"),
           local_2c8 == (char *)0x0)) {
          ERR_clear_error();
          local_2c8 = "default";
        }
        X509V3_set_ctx((X509V3_CTX *)&local_1f4,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,
                       (X509_CRL *)0x0,1);
        X509V3_set_nconf((X509V3_CTX *)&local_1f4,(CONF *)pXVar11);
        iVar9 = X509V3_EXT_add_nconf((CONF *)pXVar11,(X509V3_CTX *)&local_1f4,local_2c8,(X509 *)0x0)
        ;
        if (iVar9 != 0) goto LAB_00023692;
        BIO_printf(bio_err,"Error Loading extension section %s\n",local_2c8);
        ERR_print_errors(bio_err);
      }
      bVar38 = true;
      local_314 = (X509_STORE_CTX *)0x0;
      local_308 = (X509_STORE_CTX *)0x0;
      local_310 = (X509_STORE_CTX *)0x0;
      local_30c = (X509_STORE_CTX *)0x0;
      local_304 = (X509_STORE_CTX *)0x0;
      x = (X509_STORE_CTX *)0x0;
      pXVar29 = (X509_STORE_CTX *)0x0;
    }
  }
LAB_00023450:
  if (bVar5) {
    app_RAND_write_file(0,bio_err);
  }
LAB_0002316e:
  OBJ_cleanup();
  NCONF_free((CONF *)pXVar11);
  BIO_free_all((BIO *)local_314);
  BIO_free_all((BIO *)local_2f4);
  X509_STORE_free((X509_STORE *)ctx);
  X509_REQ_free((X509_REQ *)local_304);
  X509_free((X509 *)x);
  X509_free((X509 *)local_30c);
  EVP_PKEY_free((EVP_PKEY *)local_310);
  EVP_PKEY_free((EVP_PKEY *)local_308);
  if (st != (X509_STORE_CTX *)0x0) {
    sk_free((_STACK *)st);
  }
  X509_REQ_free((X509_REQ *)pXVar29);
  ASN1_INTEGER_free((ASN1_INTEGER *)local_300);
  sk_pop_free((_STACK *)local_2fc,ASN1_OBJECT_free + 1);
  sk_pop_free((_STACK *)local_2f8,ASN1_OBJECT_free + 1);
  if (local_21c != (void *)0x0) {
    CRYPTO_free(local_21c);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(bVar38);
}

