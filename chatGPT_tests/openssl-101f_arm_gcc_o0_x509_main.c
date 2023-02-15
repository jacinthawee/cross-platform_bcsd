
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
  ulong uVar17;
  uchar *puVar18;
  X509_STORE_CTX *serial;
  X509_NAME *pXVar19;
  ASN1_TIME *pAVar20;
  size_t sVar21;
  ASN1_INTEGER *pAVar22;
  BIGNUM *a;
  time_t tVar23;
  EVP_PKEY *pEVar24;
  char *pcVar25;
  uint uVar26;
  X509_STORE_CTX *pXVar27;
  _func_1844 *p_Var28;
  uint uVar29;
  undefined4 uVar30;
  undefined **ppuVar31;
  char *pcVar32;
  X509_STORE_CTX *pXVar33;
  char **ppcVar34;
  X509_STORE_CTX *st;
  X509_STORE *pXVar35;
  bool bVar36;
  X509_STORE_CTX *local_318;
  X509_STORE_CTX *local_314;
  X509_STORE_CTX *local_310;
  X509_STORE_CTX *local_30c;
  X509_STORE_CTX *local_308;
  X509_STORE_CTX *local_304;
  X509_STORE_CTX *local_300;
  X509_STORE_CTX *local_2fc;
  X509_STORE_CTX *local_2f8;
  undefined4 local_2f0;
  X509_STORE_CTX *local_2ec;
  undefined4 local_2e8;
  int local_2e4;
  int local_2e0;
  X509_STORE_CTX *local_2dc;
  char *local_2d8;
  BIGNUM *local_2d4;
  uchar *local_2d0;
  char *local_2cc;
  char *local_2c8;
  long local_2c4;
  X509_STORE_CTX *local_2c0;
  EVP_MD *local_2bc;
  X509_STORE_CTX *local_2b8;
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
  
  local_2c = __TMC_END__;
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
    bVar36 = true;
    pXVar11 = ctx;
    x = ctx;
    pXVar27 = ctx;
    st = ctx;
    local_318 = ctx;
    local_314 = ctx;
    local_310 = ctx;
    local_30c = ctx;
    local_308 = ctx;
    local_304 = ctx;
    local_300 = ctx;
    local_2fc = ctx;
    local_2f8 = ctx;
    goto LAB_00022ebe;
  }
  local_2f8 = (X509_STORE_CTX *)BIO_new_fp(stdout,0);
  ctx = (X509_STORE_CTX *)X509_STORE_new();
  if (ctx == (X509_STORE_CTX *)0x0) {
    bVar36 = true;
    pXVar11 = ctx;
    x = ctx;
    pXVar27 = ctx;
    st = ctx;
    local_318 = ctx;
    local_314 = ctx;
    local_310 = ctx;
    local_30c = ctx;
    local_308 = ctx;
    local_304 = ctx;
    local_300 = ctx;
    local_2fc = ctx;
    goto LAB_00022ebe;
  }
  param_1 = param_1 + -1;
  ppcVar34 = (char **)(param_2 + 4);
  X509_STORE_set_verify_cb((X509_STORE *)ctx,callb + 1);
  local_318 = (X509_STORE_CTX *)0x0;
  st = (X509_STORE_CTX *)0x0;
  local_234 = 0;
  bVar36 = false;
  bVar5 = false;
  local_2c8 = (char *)0x0;
  local_2dc = (X509_STORE_CTX *)0x0;
  local_2cc = (char *)0x0;
  local_2bc = (EVP_MD *)0x0;
  local_238 = (X509_STORE_CTX *)0x0;
  local_23c = (X509_STORE_CTX *)0x0;
  local_240 = (X509_STORE_CTX *)0x0;
  local_244 = (X509_STORE_CTX *)0x0;
  local_26c = (X509_STORE_CTX *)0x0;
  local_248 = (X509_STORE_CTX *)0x0;
  bVar6 = false;
  local_24c = (X509_STORE_CTX *)0x0;
  local_2b4 = (X509_STORE_CTX *)0x0;
  local_2b8 = (X509_STORE_CTX *)0x0;
  bVar7 = false;
  local_270 = (X509_STORE_CTX *)0x0;
  local_274 = (X509_STORE_CTX *)0x0;
  local_250 = (X509_STORE_CTX *)0x0;
  local_2a4 = (X509_STORE_CTX *)0x0;
  local_294 = (X509_STORE_CTX *)0x0;
  local_2c0 = (X509_STORE_CTX *)0x0;
  local_254 = (X509_STORE_CTX *)0x0;
  local_258 = (X509_STORE_CTX *)0x0;
  local_25c = (X509_STORE_CTX *)0x0;
  local_260 = (X509_STORE_CTX *)0x0;
  local_264 = (X509_STORE_CTX *)0x0;
  local_2a8 = (X509_STORE_CTX *)0x0;
  local_278 = (X509_STORE_CTX *)0x0;
  local_2f0 = 3;
  local_27c = (X509_STORE_CTX *)0x0;
  local_280 = (X509_STORE_CTX *)0x0;
  local_284 = (X509_STORE_CTX *)0x0;
  local_288 = (X509_STORE_CTX *)0x0;
  local_28c = (X509_STORE_CTX *)0x0;
  local_2d0 = (uchar *)0x0;
  local_298 = (char *)0x0;
  local_2ac = (char *)0x0;
  local_2b0 = (char *)0x0;
  local_29c = (char *)0x0;
  local_2d4 = (BIGNUM *)0x0;
  local_2d8 = (char *)0x0;
  local_2fc = (X509_STORE_CTX *)0x0;
  local_300 = (X509_STORE_CTX *)0x0;
  local_2ec = (X509_STORE_CTX *)0x0;
  local_304 = (X509_STORE_CTX *)0x0;
  local_2e0 = 3;
  local_2e8 = 3;
  local_2e4 = 3;
  local_308 = (X509_STORE_CTX *)0x3;
  local_2c4 = 0x1e;
  if (0 < param_1) {
    local_2e4 = 3;
    local_308 = (X509_STORE_CTX *)0x3;
    do {
      pcVar32 = *ppcVar34;
      iVar9 = strcmp(pcVar32,"-inform");
      if (iVar9 != 0) {
        iVar9 = strcmp(pcVar32,"-outform");
        if (iVar9 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_000231ae;
          local_2e4 = str2fmt(ppcVar34[1]);
          ppcVar34 = ppcVar34 + 1;
          goto LAB_00023052;
        }
        iVar9 = strcmp(pcVar32,"-keyform");
        if (iVar9 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_000231ae;
          local_2e8 = str2fmt(ppcVar34[1]);
          ppcVar34 = ppcVar34 + 1;
          goto LAB_00023052;
        }
        iVar9 = strcmp(pcVar32,"-req");
        if (iVar9 == 0) {
          reqfile = (X509_STORE_CTX *)0x1;
          bVar5 = true;
          goto LAB_00023052;
        }
        iVar9 = strcmp(pcVar32,"-CAform");
        if (iVar9 == 0) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            local_2e0 = str2fmt(ppcVar34[1]);
            ppcVar34 = ppcVar34 + 1;
            goto LAB_00023052;
          }
        }
        else {
          iVar9 = strcmp(pcVar32,"-CAkeyform");
          if (iVar9 == 0) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              local_2f0 = str2fmt(ppcVar34[1]);
              ppcVar34 = ppcVar34 + 1;
              goto LAB_00023052;
            }
          }
          else {
            iVar9 = strcmp(pcVar32,"-sigopt");
            if (iVar9 == 0) {
              if ((param_1 != 1) &&
                 ((st != (X509_STORE_CTX *)0x0 ||
                  (st = (X509_STORE_CTX *)sk_new_null(), st != (X509_STORE_CTX *)0x0)))) {
                pXVar11 = (X509_STORE_CTX *)sk_push((_STACK *)st,ppcVar34[1]);
                goto joined_r0x00023210;
              }
            }
            else {
              iVar9 = strcmp(pcVar32,"-days");
              if (iVar9 == 0) {
                param_1 = param_1 + -1;
                if (param_1 != 0) {
                  local_2c4 = strtol(ppcVar34[1],(char **)0x0,10);
                  ppcVar34 = ppcVar34 + 1;
                  if (local_2c4 != 0) goto LAB_00023052;
                  BIO_printf(bio_err,"bad number of days\n");
                }
              }
              else {
                iVar9 = strcmp(pcVar32,"-passin");
                if (iVar9 == 0) {
                  param_1 = param_1 + -1;
                  if (param_1 != 0) {
                    local_2c8 = ppcVar34[1];
                    ppcVar34 = ppcVar34 + 1;
                    goto LAB_00023052;
                  }
                }
                else {
                  iVar9 = strcmp(pcVar32,"-extfile");
                  if (iVar9 == 0) {
                    param_1 = param_1 + -1;
                    if (param_1 != 0) {
                      local_2dc = (X509_STORE_CTX *)ppcVar34[1];
                      ppcVar34 = ppcVar34 + 1;
                      goto LAB_00023052;
                    }
                  }
                  else {
                    iVar9 = strcmp(pcVar32,"-extensions");
                    if (iVar9 == 0) {
                      param_1 = param_1 + -1;
                      if (param_1 != 0) {
                        local_2cc = ppcVar34[1];
                        ppcVar34 = ppcVar34 + 1;
                        goto LAB_00023052;
                      }
                    }
                    else {
                      cVar2 = *pcVar32;
                      if ((((cVar2 == '-') && (pcVar32[1] == 'i')) && (pcVar32[2] == 'n')) &&
                         (pcVar32[3] == '\0')) {
                        param_1 = param_1 + -1;
                        if (param_1 != 0) {
                          local_2d8 = ppcVar34[1];
                          ppcVar34 = ppcVar34 + 1;
                          goto LAB_00023052;
                        }
                      }
                      else {
                        iVar9 = strcmp(pcVar32,"-out");
                        if (iVar9 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            local_2d4 = (BIGNUM *)ppcVar34[1];
                            ppcVar34 = ppcVar34 + 1;
                            goto LAB_00023052;
                          }
                        }
                        else {
                          iVar9 = strcmp(pcVar32,"-signkey");
                          if (iVar9 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_29c = ppcVar34[1];
                              bVar5 = true;
                              local_2ec = (X509_STORE_CTX *)((int)&local_2ec->ctx + 1);
                              ppcVar34 = ppcVar34 + 1;
                              local_294 = local_2ec;
                              goto LAB_00023052;
                            }
                          }
                          else if (((cVar2 == '-') && (pcVar32[1] == 'C')) &&
                                  ((pcVar32[2] == 'A' && (pcVar32[3] == '\0')))) {
                            param_1 = param_1 + -1;
                            if (param_1 != 0) {
                              local_2b0 = ppcVar34[1];
                              bVar5 = true;
                              local_2ec = (X509_STORE_CTX *)((int)&local_2ec->ctx + 1);
                              ppcVar34 = ppcVar34 + 1;
                              local_2a4 = local_2ec;
                              goto LAB_00023052;
                            }
                          }
                          else {
                            iVar9 = strcmp(pcVar32,"-CAkey");
                            if (iVar9 == 0) {
                              param_1 = param_1 + -1;
                              if (param_1 != 0) {
                                local_2ac = ppcVar34[1];
                                ppcVar34 = ppcVar34 + 1;
                                goto LAB_00023052;
                              }
                            }
                            else {
                              iVar9 = strcmp(pcVar32,"-CAserial");
                              if (iVar9 == 0) {
                                param_1 = param_1 + -1;
                                if (param_1 != 0) {
                                  local_298 = ppcVar34[1];
                                  ppcVar34 = ppcVar34 + 1;
                                  goto LAB_00023052;
                                }
                              }
                              else {
                                iVar9 = strcmp(pcVar32,"-set_serial");
                                if (iVar9 == 0) {
                                  if (param_1 != 1) {
                                    local_304 = (X509_STORE_CTX *)
                                                s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,
                                                                 ppcVar34[1]);
                                    pXVar11 = local_304;
                                    goto joined_r0x00023210;
                                  }
                                }
                                else {
                                  iVar9 = strcmp(pcVar32,"-addtrust");
                                  if (iVar9 == 0) {
                                    param_1 = param_1 + -1;
                                    if (param_1 != 0) {
                                      pAVar15 = OBJ_txt2obj(ppcVar34[1],0);
                                      if (pAVar15 != (ASN1_OBJECT *)0x0) {
                                        if (local_300 == (X509_STORE_CTX *)0x0) {
                                          local_300 = (X509_STORE_CTX *)sk_new_null();
                                        }
                                        sk_push((_STACK *)local_300,pAVar15);
                                        bVar7 = true;
                                        ppcVar34 = ppcVar34 + 1;
                                        goto LAB_00023052;
                                      }
                                      BIO_printf(bio_err,"Invalid trust object value %s\n",
                                                 ppcVar34[1]);
                                    }
                                  }
                                  else {
                                    iVar9 = strcmp(pcVar32,"-addreject");
                                    if (iVar9 == 0) {
                                      param_1 = param_1 + -1;
                                      if (param_1 != 0) {
                                        pAVar15 = OBJ_txt2obj(ppcVar34[1],0);
                                        if (pAVar15 != (ASN1_OBJECT *)0x0) {
                                          if (local_2fc == (X509_STORE_CTX *)0x0) {
                                            local_2fc = (X509_STORE_CTX *)sk_new_null();
                                          }
                                          sk_push((_STACK *)local_2fc,pAVar15);
                                          bVar7 = true;
                                          ppcVar34 = ppcVar34 + 1;
                                          goto LAB_00023052;
                                        }
                                        BIO_printf(bio_err,"Invalid reject object value %s\n",
                                                   ppcVar34[1]);
                                      }
                                    }
                                    else {
                                      iVar9 = strcmp(pcVar32,"-setalias");
                                      if (iVar9 == 0) {
                                        param_1 = param_1 + -1;
                                        if (param_1 != 0) {
                                          local_2d0 = (uchar *)ppcVar34[1];
                                          ppcVar34 = ppcVar34 + 1;
                                          bVar7 = true;
                                          goto LAB_00023052;
                                        }
                                      }
                                      else {
                                        iVar9 = strcmp(pcVar32,"-certopt");
                                        if (iVar9 == 0) {
                                          if (param_1 != 1) {
                                            pXVar11 = (X509_STORE_CTX *)
                                                      set_cert_ex(&local_214,ppcVar34[1]);
joined_r0x00023210:
                                            param_1 = param_1 + -1;
                                            ppcVar34 = ppcVar34 + 1;
                                            if (pXVar11 != (X509_STORE_CTX *)0x0) goto LAB_00023052;
                                          }
                                        }
                                        else {
                                          iVar9 = strcmp(pcVar32,"-nameopt");
                                          if (iVar9 != 0) {
                                            iVar9 = strcmp(pcVar32,"-engine");
                                            if (iVar9 == 0) {
                                              param_1 = param_1 + -1;
                                              if (param_1 == 0) goto LAB_000231ae;
                                              local_318 = (X509_STORE_CTX *)ppcVar34[1];
                                              ppcVar34 = ppcVar34 + 1;
                                            }
                                            else if (((cVar2 == '-') && (pcVar32[1] == 'C')) &&
                                                    (pcVar32[2] == '\0')) {
                                              local_2ec = (X509_STORE_CTX *)
                                                          ((int)&local_2ec->ctx + 1);
                                              local_248 = local_2ec;
                                            }
                                            else {
                                              iVar9 = strcmp(pcVar32,"-email");
                                              if (iVar9 == 0) {
                                                local_2ec = (X509_STORE_CTX *)
                                                            ((int)&local_2ec->ctx + 1);
                                                local_274 = local_2ec;
                                              }
                                              else {
                                                iVar9 = strcmp(pcVar32,"-ocsp_uri");
                                                if (iVar9 == 0) {
                                                  local_2ec = (X509_STORE_CTX *)
                                                              ((int)&local_2ec->ctx + 1);
                                                  local_270 = local_2ec;
                                                }
                                                else {
                                                  iVar9 = strcmp(pcVar32,"-serial");
                                                  if (iVar9 == 0) {
                                                    local_2ec = (X509_STORE_CTX *)
                                                                ((int)&local_2ec->ctx + 1);
                                                    local_288 = local_2ec;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar32,"-next_serial");
                                                    if (iVar9 == 0) {
                                                      local_2ec = (X509_STORE_CTX *)
                                                                  ((int)&local_2ec->ctx + 1);
                                                      local_2a8 = local_2ec;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(pcVar32,"-modulus");
                                                      if (iVar9 == 0) {
                                                        local_2ec = (X509_STORE_CTX *)
                                                                    ((int)&local_2ec->ctx + 1);
                                                        local_244 = local_2ec;
                                                      }
                                                      else {
                                                        iVar9 = strcmp(pcVar32,"-pubkey");
                                                        if (iVar9 == 0) {
                                                          local_2ec = (X509_STORE_CTX *)
                                                                      ((int)&local_2ec->ctx + 1);
                                                          local_240 = local_2ec;
                                                        }
                                                        else {
                                                          iVar9 = strcmp(pcVar32,"-x509toreq");
                                                          if (iVar9 == 0) {
                                                            local_2ec = (X509_STORE_CTX *)
                                                                        ((int)&local_2ec->ctx + 1);
                                                            local_26c = local_2ec;
                                                          }
                                                          else {
                                                            iVar9 = strcmp(pcVar32,"-text");
                                                            if (iVar9 == 0) {
                                                              local_2ec = (X509_STORE_CTX *)
                                                                          ((int)&local_2ec->ctx + 1)
                                                              ;
                                                              local_28c = local_2ec;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(pcVar32,"-hash");
                                                              if ((iVar9 == 0) ||
                                                                 (iVar9 = strcmp(pcVar32,
                                                  "-subject_hash"), iVar9 == 0)) {
                                                    local_2ec = (X509_STORE_CTX *)
                                                                ((int)&local_2ec->ctx + 1);
                                                    local_264 = local_2ec;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar32,"-subject_hash_old");
                                                    if (iVar9 == 0) {
                                                      local_2ec = (X509_STORE_CTX *)
                                                                  ((int)&local_2ec->ctx + 1);
                                                      local_258 = local_2ec;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(pcVar32,"-issuer_hash");
                                                      if (iVar9 == 0) {
                                                        local_2ec = (X509_STORE_CTX *)
                                                                    ((int)&local_2ec->ctx + 1);
                                                        local_260 = local_2ec;
                                                      }
                                                      else {
                                                        iVar9 = strcmp(pcVar32,"-issuer_hash_old");
                                                        if (iVar9 == 0) {
                                                          local_2ec = (X509_STORE_CTX *)
                                                                      ((int)&local_2ec->ctx + 1);
                                                          local_254 = local_2ec;
                                                        }
                                                        else {
                                                          iVar9 = strcmp(pcVar32,"-subject");
                                                          if (iVar9 == 0) {
                                                            local_2ec = (X509_STORE_CTX *)
                                                                        ((int)&local_2ec->ctx + 1);
                                                            local_284 = local_2ec;
                                                          }
                                                          else {
                                                            iVar9 = strcmp(pcVar32,"-issuer");
                                                            if (iVar9 == 0) {
                                                              local_2ec = (X509_STORE_CTX *)
                                                                          ((int)&local_2ec->ctx + 1)
                                                              ;
                                                              local_280 = local_2ec;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(pcVar32,"-fingerprint")
                                                              ;
                                                              if (iVar9 == 0) {
                                                                local_2ec = (X509_STORE_CTX *)
                                                                            ((int)&local_2ec->ctx +
                                                                            1);
                                                                local_238 = local_2ec;
                                                              }
                                                              else {
                                                                iVar9 = strcmp(pcVar32,"-dates");
                                                                if (iVar9 == 0) {
                                                                  local_27c = (X509_STORE_CTX *)
                                                                              ((int)&local_2ec->ctx
                                                                              + 1);
                                                                  local_2ec = (X509_STORE_CTX *)
                                                                              ((int)&local_2ec->ctx
                                                                              + 2);
                                                                  local_278 = local_2ec;
                                                                }
                                                                else {
                                                                  iVar9 = strcmp(pcVar32,"-purpose")
                                                                  ;
                                                                  if (iVar9 == 0) {
                                                                    local_2ec = (X509_STORE_CTX *)
                                                                                ((int)&local_2ec->
                                                                                       ctx + 1);
                                                                    local_23c = local_2ec;
                                                                  }
                                                                  else {
                                                                    iVar9 = strcmp(pcVar32,
                                                  "-startdate");
                                                  if (iVar9 == 0) {
                                                    local_2ec = (X509_STORE_CTX *)
                                                                ((int)&local_2ec->ctx + 1);
                                                    local_27c = local_2ec;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar32,"-enddate");
                                                    if (iVar9 == 0) {
                                                      local_2ec = (X509_STORE_CTX *)
                                                                  ((int)&local_2ec->ctx + 1);
                                                      local_278 = local_2ec;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(pcVar32,"-checkend");
                                                      if (iVar9 == 0) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 == 0) goto LAB_000231ae;
                                                        local_234 = strtol(ppcVar34[1],(char **)0x0,
                                                                           10);
                                                        ppcVar34 = ppcVar34 + 1;
                                                        bVar36 = true;
                                                      }
                                                      else {
                                                        iVar9 = strcmp(pcVar32,"-noout");
                                                        if (iVar9 == 0) {
                                                          local_2ec = (X509_STORE_CTX *)
                                                                      ((int)&local_2ec->ctx + 1);
                                                          local_2c0 = local_2ec;
                                                        }
                                                        else {
                                                          iVar9 = strcmp(pcVar32,"-trustout");
                                                          if (iVar9 == 0) {
                                                            bVar7 = true;
                                                          }
                                                          else {
                                                            iVar9 = strcmp(pcVar32,"-clrtrust");
                                                            if (iVar9 == 0) {
                                                              local_2ec = (X509_STORE_CTX *)
                                                                          ((int)&local_2ec->ctx + 1)
                                                              ;
                                                              local_2b8 = local_2ec;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(pcVar32,"-clrreject");
                                                              if (iVar9 == 0) {
                                                                local_2ec = (X509_STORE_CTX *)
                                                                            ((int)&local_2ec->ctx +
                                                                            1);
                                                                local_2b4 = local_2ec;
                                                              }
                                                              else {
                                                                iVar9 = strcmp(pcVar32,"-alias");
                                                                if (iVar9 == 0) {
                                                                  local_2ec = (X509_STORE_CTX *)
                                                                              ((int)&local_2ec->ctx
                                                                              + 1);
                                                                  local_24c = local_2ec;
                                                                }
                                                                else {
                                                                  iVar9 = strcmp(pcVar32,
                                                  "-CAcreateserial");
                                                  if (iVar9 == 0) {
                                                    local_2ec = (X509_STORE_CTX *)
                                                                ((int)&local_2ec->ctx + 1);
                                                    local_250 = local_2ec;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar32,"-clrext");
                                                    if (iVar9 == 0) {
                                                      bVar6 = true;
                                                    }
                                                    else {
                                                      iVar9 = strcmp(pcVar32,"-crlext");
                                                      if (iVar9 == 0) {
                                                        BIO_printf(bio_err,
                                                  "use -clrext instead of -crlext\n");
                                                  bVar6 = true;
                                                  }
                                                  else {
                                                    iVar9 = strcmp(pcVar32,"-ocspid");
                                                    if (iVar9 == 0) {
                                                      local_2ec = (X509_STORE_CTX *)
                                                                  ((int)&local_2ec->ctx + 1);
                                                      local_25c = local_2ec;
                                                    }
                                                    else {
                                                      local_2bc = EVP_get_digestbyname(pcVar32 + 1);
                                                      if (local_2bc == (EVP_MD *)0x0) {
                                                        BIO_printf(bio_err,"unknown option %s\n",
                                                                   *ppcVar34);
                                                        goto LAB_000231ae;
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
                                            goto LAB_00023052;
                                          }
                                          if (param_1 != 1) {
                                            pXVar11 = (X509_STORE_CTX *)
                                                      set_name_ex(&local_218,ppcVar34[1]);
                                            goto joined_r0x00023210;
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
LAB_000231ae:
        ppuVar31 = &x509_usage;
        do {
          BIO_printf(bio_err,"%s");
          ppuVar31 = (undefined **)((X509_STORE_CTX **)ppuVar31 + 1);
          pXVar11 = (X509_STORE_CTX *)*ppuVar31;
        } while (pXVar11 != (X509_STORE_CTX *)0x0);
        bVar36 = true;
        x = pXVar11;
        pXVar27 = pXVar11;
        local_318 = pXVar11;
        local_314 = pXVar11;
        local_310 = pXVar11;
        local_30c = pXVar11;
        local_308 = pXVar11;
        goto LAB_00023190;
      }
      param_1 = param_1 + -1;
      if (param_1 == 0) goto LAB_000231ae;
      ppcVar1 = ppcVar34 + 1;
      ppcVar34 = ppcVar34 + 1;
      local_308 = (X509_STORE_CTX *)str2fmt(*ppcVar1);
LAB_00023052:
      param_1 = param_1 + -1;
      ppcVar34 = ppcVar34 + 1;
    } while (0 < param_1);
  }
  uVar10 = setup_engine(bio_err,local_318,0);
  if (bVar5) {
    app_RAND_load_file(0,bio_err,0);
  }
  ERR_load_crypto_strings();
  pXVar11 = (X509_STORE_CTX *)app_passwd(bio_err,local_2c8,0,&local_21c,0);
  if (pXVar11 == (X509_STORE_CTX *)0x0) {
    BIO_printf(bio_err,"Error getting password\n");
LAB_0002317e:
    bVar36 = true;
    x = pXVar11;
    pXVar27 = pXVar11;
    local_318 = pXVar11;
    local_314 = pXVar11;
    local_310 = pXVar11;
    local_30c = pXVar11;
    local_308 = pXVar11;
  }
  else {
    pXVar11 = (X509_STORE_CTX *)X509_STORE_set_default_paths((X509_STORE *)ctx);
    if (pXVar11 == (X509_STORE_CTX *)0x0) {
      ERR_print_errors(bio_err);
      goto LAB_0002317e;
    }
    local_310 = local_2a4;
    if (local_2a4 != (X509_STORE_CTX *)0x0) {
      local_310 = (X509_STORE_CTX *)0x1;
    }
    if (local_2ac == (char *)0x0) {
      uVar26 = (uint)local_310 & 1;
    }
    else {
      uVar26 = 0;
    }
    if (uVar26 != 0) {
      if (local_2e0 != 3) {
        BIO_printf(bio_err,"need to specify a CAkey if using the CA command\n");
        pXVar11 = (X509_STORE_CTX *)0x0;
        goto LAB_0002317e;
      }
      local_2ac = local_2b0;
    }
    pXVar11 = local_2dc;
    if (local_2dc == (X509_STORE_CTX *)0x0) {
LAB_000233b2:
      pXVar27 = reqfile;
      if (reqfile == (X509_STORE_CTX *)0x0) {
        x = (X509_STORE_CTX *)load_cert(bio_err,local_2d8,local_308,0,uVar10,"Certificate");
        if (x == (X509_STORE_CTX *)0x0) {
          bVar36 = true;
          pXVar27 = x;
          local_318 = x;
          local_314 = x;
          local_310 = x;
          local_30c = x;
          local_308 = x;
        }
        else {
          local_308 = pXVar27;
LAB_00023534:
          if ((local_310 == (X509_STORE_CTX *)0x0) ||
             (local_310 = (X509_STORE_CTX *)
                          load_cert(bio_err,local_2b0,local_2e0,0,uVar10,"CA Certificate"),
             local_310 != (X509_STORE_CTX *)0x0)) {
            if ((local_2c0 == (X509_STORE_CTX *)0x0) ||
               ((local_28c != (X509_STORE_CTX *)0x0 || (local_2a8 != (X509_STORE_CTX *)0x0)))) {
              OBJ_create("2.99999.3","SET.ex3","SET x509v3 extension 3");
              pBVar12 = BIO_s_file();
              local_318 = (X509_STORE_CTX *)BIO_new(pBVar12);
              if (local_318 == (X509_STORE_CTX *)0x0) {
                bVar36 = true;
                ERR_print_errors(bio_err);
                pXVar27 = local_318;
                local_314 = local_318;
                local_30c = local_318;
                goto LAB_00023190;
              }
              if (local_2d4 == (BIGNUM *)0x0) {
                BIO_ctrl((BIO *)local_318,0x6a,0,stdout);
              }
              else {
                lVar13 = BIO_ctrl((BIO *)local_318,0x6c,5,local_2d4);
                if (lVar13 < 1) {
                  perror((char *)local_2d4);
                  bVar36 = true;
                  local_30c = (X509_STORE_CTX *)0x0;
                  local_314 = (X509_STORE_CTX *)0x0;
                  pXVar27 = (X509_STORE_CTX *)0x0;
                  goto LAB_00023190;
                }
              }
            }
            else {
              local_318 = local_2a8;
            }
            if (local_2d0 != (uchar *)0x0) {
              X509_alias_set1((X509 *)x,local_2d0,-1);
            }
            if (local_2b8 != (X509_STORE_CTX *)0x0) {
              X509_trust_clear((X509 *)x);
            }
            if (local_2b4 != (X509_STORE_CTX *)0x0) {
              X509_reject_clear((X509 *)x);
            }
            if (local_300 != (X509_STORE_CTX *)0x0) {
              for (iVar9 = 0; iVar14 = sk_num((_STACK *)local_300), iVar9 < iVar14;
                  iVar9 = iVar9 + 1) {
                pAVar15 = (ASN1_OBJECT *)sk_value((_STACK *)local_300,iVar9);
                X509_add1_trust_object((X509 *)x,pAVar15);
              }
            }
            if (local_2fc != (X509_STORE_CTX *)0x0) {
              for (iVar9 = 0; iVar14 = sk_num((_STACK *)local_2fc), iVar9 < iVar14;
                  iVar9 = iVar9 + 1) {
                pAVar15 = (ASN1_OBJECT *)sk_value((_STACK *)local_2fc,iVar9);
                X509_add1_reject_object((X509 *)x,pAVar15);
              }
            }
            if (local_2ec != (X509_STORE_CTX *)0x0) {
              pXVar33 = (X509_STORE_CTX *)0x1;
              pXVar27 = (X509_STORE_CTX *)0x0;
              local_30c = (X509_STORE_CTX *)0x0;
              local_314 = (X509_STORE_CTX *)0x0;
LAB_0002372a:
              if (local_280 == pXVar33) {
                pXVar19 = X509_get_issuer_name((X509 *)x);
                print_name(local_2f8,"issuer= ",pXVar19,local_218);
              }
              else if (local_284 == pXVar33) {
                pXVar19 = X509_get_subject_name((X509 *)x);
                print_name(local_2f8,"subject= ",pXVar19,local_218);
              }
              else if (local_288 == pXVar33) {
                BIO_printf((BIO *)local_2f8,"serial=");
                pAVar22 = X509_get_serialNumber((X509 *)x);
                i2a_ASN1_INTEGER((BIO *)local_2f8,pAVar22);
                BIO_printf((BIO *)local_2f8,"\n");
              }
              else if (local_2a8 == pXVar33) {
                pAVar22 = X509_get_serialNumber((X509 *)x);
                a = ASN1_INTEGER_to_BN(pAVar22,(BIGNUM *)0x0);
                if (((a == (BIGNUM *)0x0) || (iVar9 = BN_add_word(a,1), iVar9 == 0)) ||
                   (pAVar22 = BN_to_ASN1_INTEGER(a,(ASN1_INTEGER *)0x0),
                   pAVar22 == (ASN1_INTEGER *)0x0)) goto LAB_00023966;
                BN_free(a);
                i2a_ASN1_INTEGER((BIO *)local_318,pAVar22);
                ASN1_INTEGER_free(pAVar22);
                BIO_puts((BIO *)local_318,"\n");
              }
              else {
                uVar29 = count_leading_zeroes((int)local_274 - (int)pXVar33);
                uVar29 = uVar29 >> 5;
                uVar26 = uVar29;
                if (local_270 == pXVar33) {
                  uVar26 = uVar29 | 1;
                }
                if (uVar26 == 0) {
                  if (local_24c == pXVar33) {
                    puVar18 = X509_alias_get0((X509 *)x,(int *)0x0);
                    if (puVar18 == (uchar *)0x0) {
                      BIO_puts((BIO *)local_2f8,"<No Alias>\n");
                    }
                    else {
                      BIO_printf((BIO *)local_2f8,"%s\n",puVar18);
                    }
                  }
                  else {
                    if (local_264 == pXVar33) {
                      uVar17 = X509_subject_name_hash((X509 *)x);
                    }
                    else if (local_258 == pXVar33) {
                      uVar17 = X509_subject_name_hash_old((X509 *)x);
                    }
                    else if (local_260 == pXVar33) {
                      uVar17 = X509_issuer_name_hash((X509 *)x);
                    }
                    else {
                      if (local_254 != pXVar33) {
                        if (local_23c == pXVar33) {
                          local_2d4 = (BIGNUM *)0x0;
                          BIO_printf((BIO *)local_2f8,"Certificate purposes:\n");
                          for (; iVar9 = X509_PURPOSE_get_count(), (int)local_2d4 < iVar9;
                              local_2d4 = (BIGNUM *)((int)local_2d4 + 1)) {
                            xp = X509_PURPOSE_get0((int)local_2d4);
                            iVar9 = X509_PURPOSE_get_id(xp);
                            pcVar32 = X509_PURPOSE_get0_name(xp);
                            iVar14 = X509_check_purpose((X509 *)x,iVar9,0);
                            BIO_printf((BIO *)local_2f8,"%s%s : ",pcVar32,"");
                            if (iVar14 == 1) {
                              BIO_printf((BIO *)local_2f8,"Yes\n");
                            }
                            else if (iVar14 == 0) {
                              BIO_printf((BIO *)local_2f8,"No\n");
                            }
                            else {
                              BIO_printf((BIO *)local_2f8,"Yes (WARNING code=%d)\n",iVar14);
                            }
                            iVar9 = X509_check_purpose((X509 *)x,iVar9,1);
                            BIO_printf((BIO *)local_2f8,"%s%s : ",pcVar32,&DAT_0012c988);
                            if (iVar9 == 1) {
                              BIO_printf((BIO *)local_2f8,"Yes\n");
                            }
                            else if (iVar9 == 0) {
                              BIO_printf((BIO *)local_2f8,"No\n");
                            }
                            else {
                              BIO_printf((BIO *)local_2f8,"Yes (WARNING code=%d)\n",iVar9);
                            }
                          }
                        }
                        else if (local_244 == pXVar33) {
                          pEVar24 = X509_get_pubkey((X509 *)x);
                          if (pEVar24 == (EVP_PKEY *)0x0) {
                            bVar36 = true;
                            BIO_printf(bio_err,"Modulus=unavailable\n");
                            ERR_print_errors(bio_err);
                            goto LAB_00023190;
                          }
                          BIO_printf((BIO *)local_2f8,"Modulus=");
                          if (pEVar24->type == 6) {
                            BN_print(local_2f8,((pEVar24->pkey).rsa)->n);
                          }
                          else if (pEVar24->type == 0x74) {
                            BN_print(local_2f8,((pEVar24->pkey).rsa)->d);
                          }
                          else {
                            BIO_printf((BIO *)local_2f8,"Wrong Algorithm type");
                          }
                          BIO_printf((BIO *)local_2f8,"\n");
                          EVP_PKEY_free(pEVar24);
                        }
                        else if (local_240 == pXVar33) {
                          pEVar24 = X509_get_pubkey((X509 *)x);
                          if (pEVar24 == (EVP_PKEY *)0x0) {
                            bVar36 = true;
                            BIO_printf(bio_err,"Error getting public key\n");
                            ERR_print_errors(bio_err);
                            goto LAB_00023190;
                          }
                          PEM_write_bio_PUBKEY((BIO *)local_2f8,pEVar24);
                          EVP_PKEY_free(pEVar24);
                        }
                        else if (local_248 == pXVar33) {
                          pXVar19 = X509_get_subject_name((X509 *)x);
                          X509_NAME_oneline(pXVar19,acStack_12c,0x100);
                          BIO_printf((BIO *)local_2f8,"/* subject:%s */\n",acStack_12c);
                          pXVar19 = X509_get_issuer_name((X509 *)x);
                          X509_NAME_oneline(pXVar19,acStack_12c,0x100);
                          BIO_printf((BIO *)local_2f8,"/* issuer :%s */\n",acStack_12c);
                          iVar9 = i2d_X509((X509 *)x,(uchar **)0x0);
                          pXVar35 = (X509_STORE *)CRYPTO_malloc(iVar9,"x509.c",0x369);
                          local_1f4.ctx = pXVar35;
                          pXVar19 = X509_get_subject_name((X509 *)x);
                          uVar26 = i2d_X509_NAME(pXVar19,(uchar **)&local_1f4);
                          BIO_printf((BIO *)local_2f8,"unsigned char XXX_subject_name[%d]={\n",
                                     uVar26);
                          local_1f4.ctx = pXVar35;
                          for (uVar29 = 0; (int)uVar29 < (int)uVar26; uVar29 = uVar29 + 1) {
                            BIO_printf((BIO *)local_2f8,"0x%02X,",
                                       (uint)*(byte *)((int)&(local_1f4.ctx)->cache + uVar29));
                            if ((uVar29 & 0xf) == 0xf) {
                              BIO_printf((BIO *)local_2f8,"\n");
                            }
                          }
                          if ((uVar26 & ~((int)uVar26 >> 0x1f) & 0xf) != 0) {
                            BIO_printf((BIO *)local_2f8,"\n");
                          }
                          BIO_printf((BIO *)local_2f8,"};\n");
                          uVar26 = i2d_X509_PUBKEY((X509_PUBKEY *)x->ctx->get_issuer,
                                                   (uchar **)&local_1f4);
                          BIO_printf((BIO *)local_2f8,"unsigned char XXX_public_key[%d]={\n",uVar26)
                          ;
                          local_1f4.ctx = pXVar35;
                          for (uVar29 = 0; (int)uVar29 < (int)uVar26; uVar29 = uVar29 + 1) {
                            BIO_printf((BIO *)local_2f8,"0x%02X,",
                                       (uint)*(byte *)((int)&(local_1f4.ctx)->cache + uVar29));
                            if ((uVar29 & 0xf) == 0xf) {
                              BIO_printf((BIO *)local_2f8,"\n");
                            }
                          }
                          if ((uVar26 & ~((int)uVar26 >> 0x1f) & 0xf) != 0) {
                            BIO_printf((BIO *)local_2f8,"\n");
                          }
                          BIO_printf((BIO *)local_2f8,"};\n");
                          uVar26 = i2d_X509((X509 *)x,(uchar **)&local_1f4);
                          BIO_printf((BIO *)local_2f8,"unsigned char XXX_certificate[%d]={\n",uVar26
                                    );
                          local_1f4.ctx = pXVar35;
                          for (uVar29 = 0; (int)uVar29 < (int)uVar26; uVar29 = uVar29 + 1) {
                            BIO_printf((BIO *)local_2f8,"0x%02X,",
                                       (uint)*(byte *)((int)&(local_1f4.ctx)->cache + uVar29));
                            if ((uVar29 & 0xf) == 0xf) {
                              BIO_printf((BIO *)local_2f8,"\n");
                            }
                          }
                          if ((uVar26 & ~((int)uVar26 >> 0x1f) & 0xf) != 0) {
                            BIO_printf((BIO *)local_2f8,"\n");
                          }
                          BIO_printf((BIO *)local_2f8,"};\n");
                          CRYPTO_free(pXVar35);
                        }
                        else {
                          if (local_28c != pXVar33) {
                            if (local_27c == pXVar33) {
                              BIO_puts((BIO *)local_2f8,"notBefore=");
                              pAVar20 = *(ASN1_TIME **)x->ctx->verify;
                            }
                            else {
                              if (local_278 != pXVar33) {
                                if (local_238 == pXVar33) {
                                  type = local_2bc;
                                  if (local_2bc == (EVP_MD *)0x0) {
                                    type = EVP_sha1();
                                  }
                                  iVar9 = X509_digest((X509 *)x,type,local_16c,(uint *)&local_1f4);
                                  if (iVar9 != 0) {
                                    pXVar35 = (X509_STORE *)0x0;
                                    iVar9 = EVP_MD_type(type);
                                    pcVar32 = OBJ_nid2sn(iVar9);
                                    BIO_printf((BIO *)local_2f8,"%s Fingerprint=",pcVar32);
                                    while ((int)pXVar35 < (int)local_1f4.ctx) {
                                      pbVar3 = local_16c + (int)pXVar35;
                                      pXVar35 = (X509_STORE *)((int)&pXVar35->cache + 1);
                                      if (local_1f4.ctx == pXVar35) {
                                        uVar30 = 10;
                                      }
                                      else {
                                        uVar30 = 0x3a;
                                      }
                                      BIO_printf((BIO *)local_2f8,"%02X%c",(uint)*pbVar3,uVar30);
                                    }
                                    goto LAB_0002379e;
                                  }
                                  bVar36 = true;
                                  BIO_printf(bio_err,"out of memory\n");
                                  goto LAB_00023190;
                                }
                                if (local_294 == pXVar33 && local_26c == (X509_STORE_CTX *)0x0) {
                                  BIO_printf(bio_err,"Getting Private key\n");
                                  if ((local_314 != (X509_STORE_CTX *)0x0) ||
                                     (local_314 = (X509_STORE_CTX *)
                                                  load_key(bio_err,local_29c,local_2e8,0,local_21c,
                                                           uVar10,"Private key"),
                                     local_314 != (X509_STORE_CTX *)0x0)) {
                                    if (!bVar5) {
                    /* WARNING: Subroutine does not return */
                                      __assert_fail("need_rand","x509.c",0x3c6,"x509_main");
                                    }
                                    pEVar24 = X509_get_pubkey((X509 *)x);
                                    EVP_PKEY_copy_parameters(pEVar24,(EVP_PKEY *)local_314);
                                    EVP_PKEY_save_parameters(pEVar24,1);
                                    EVP_PKEY_free(pEVar24);
                                    pXVar19 = X509_get_subject_name((X509 *)x);
                                    iVar9 = X509_set_issuer_name((X509 *)x,pXVar19);
                                    if (((iVar9 != 0) &&
                                        (pAVar20 = X509_gmtime_adj(*(ASN1_TIME **)x->ctx->verify,0),
                                        pAVar20 != (ASN1_TIME *)0x0)) &&
                                       ((pAVar20 = X509_gmtime_adj(*(ASN1_TIME **)
                                                                    (x->ctx->verify + 4),
                                                                   local_2c4 * 0x15180),
                                        pAVar20 != (ASN1_TIME *)0x0 &&
                                        (iVar9 = X509_set_pubkey((X509 *)x,(EVP_PKEY *)local_314),
                                        iVar9 != 0)))) {
                                      if (bVar6) {
                                        while (iVar9 = X509_get_ext_count((X509 *)x), 0 < iVar9) {
                                          X509_delete_ext((X509 *)x,0);
                                        }
                                      }
                                      if (pXVar11 != (X509_STORE_CTX *)0x0) {
                                        X509_set_version((X509 *)x,2);
                                        X509V3_set_ctx((X509V3_CTX *)&local_1f4,(X509 *)x,(X509 *)x,
                                                       (X509_REQ *)0x0,(X509_CRL *)0x0,0);
                                        X509V3_set_nconf((X509V3_CTX *)&local_1f4,(CONF *)pXVar11);
                                        iVar9 = X509V3_EXT_add_nconf
                                                          ((CONF *)pXVar11,(X509V3_CTX *)&local_1f4,
                                                           local_2cc,(X509 *)x);
                                        if (iVar9 == 0) goto LAB_000238fe;
                                      }
                                      iVar9 = X509_sign((X509 *)x,(EVP_PKEY *)local_314,local_2bc);
                                      if (iVar9 != 0) goto LAB_0002379e;
                                    }
LAB_000238fe:
                                    bVar36 = true;
                                    ERR_print_errors(bio_err);
                                    goto LAB_00023190;
                                  }
                                }
                                else {
                                  if (local_2a4 != pXVar33) {
                                    if (local_26c != pXVar33) {
                                      if (local_25c == pXVar33) {
                                        X509_ocspid_print((BIO *)local_318,(X509 *)x);
                                      }
                                      goto LAB_0002379e;
                                    }
                                    BIO_printf(bio_err,"Getting request Private Key\n");
                                    if (local_29c == (char *)0x0) {
                                      bVar36 = true;
                                      BIO_printf(bio_err,"no request key file specified\n");
                                      goto LAB_00023190;
                                    }
                                    pEVar24 = (EVP_PKEY *)
                                              load_key(bio_err,local_29c,local_2e8,0,local_21c,
                                                       uVar10,"request key");
                                    if (pEVar24 == (EVP_PKEY *)0x0) goto LAB_00023966;
                                    BIO_printf(bio_err,"Generating certificate request\n");
                                    pXVar27 = (X509_STORE_CTX *)
                                              X509_to_X509_REQ((X509 *)x,pEVar24,local_2bc);
                                    EVP_PKEY_free(pEVar24);
                                    if (pXVar27 == (X509_STORE_CTX *)0x0) {
                                      bVar36 = true;
                                      ERR_print_errors(bio_err);
                                      goto LAB_00023190;
                                    }
                                    if (local_2c0 == (X509_STORE_CTX *)0x0) {
                                      X509_REQ_print((BIO *)local_318,(X509_REQ *)pXVar27);
                                      PEM_write_bio_X509_REQ((BIO *)local_318,(X509_REQ *)pXVar27);
                                      local_2c0 = (X509_STORE_CTX *)0x1;
                                    }
                                    else {
                                      local_2c0 = (X509_STORE_CTX *)0x1;
                                    }
                                    goto LAB_0002379e;
                                  }
                                  BIO_printf(bio_err,"Getting CA Private Key\n");
                                  if ((local_2ac != (char *)0x0) &&
                                     (local_30c = (X509_STORE_CTX *)
                                                  load_key(bio_err,local_2ac,local_2f0,0,local_21c,
                                                           uVar10,"CA Private Key"),
                                     local_30c == (X509_STORE_CTX *)0x0)) goto LAB_00023966;
                                  if (!bVar5) {
                    /* WARNING: Subroutine does not return */
                                    __assert_fail("need_rand","x509.c",0x3d6,"x509_main");
                                  }
                                  pEVar24 = X509_get_pubkey((X509 *)local_310);
                                  EVP_PKEY_copy_parameters(pEVar24,(EVP_PKEY *)local_30c);
                                  EVP_PKEY_free(pEVar24);
                                  serial = (X509_STORE_CTX *)
                                           X509_STORE_CTX_init(&local_1f4,(X509_STORE *)ctx,
                                                               (X509 *)x,(stack_st_X509 *)0x0);
                                  if (serial == (X509_STORE_CTX *)0x0) {
                                    BIO_printf(bio_err,"Error initialising X509 store\n");
LAB_00023f84:
                                    bVar4 = false;
                                    X509_STORE_CTX_cleanup(&local_1f4);
                                    ERR_print_errors(bio_err);
                                  }
                                  else {
                                    serial = local_304;
                                    if (local_304 == (X509_STORE_CTX *)0x0) {
                                      local_210.flags = (int)local_304;
                                      if (local_298 == (char *)0x0) {
                                        sVar21 = strlen(local_2b0);
                                        sVar21 = sVar21 + 6;
                                        pcVar32 = (char *)CRYPTO_malloc(sVar21,"x509.c",0x45d);
                                        if (pcVar32 == (char *)0x0) goto LAB_000240d0;
                                        BUF_strlcpy(pcVar32,local_2b0,sVar21);
                                        pcVar8 = pcVar32;
                                        do {
                                          pcVar25 = pcVar8;
                                          if (*pcVar25 == '\0') goto LAB_00024126;
                                          pcVar8 = pcVar25 + 1;
                                        } while (*pcVar25 != '.');
                                        *pcVar25 = '\0';
LAB_00024126:
                                        BUF_strlcat(pcVar32,".srl",sVar21);
LAB_00024090:
                                        local_2d4 = (BIGNUM *)load_serial(pcVar32,local_250,0);
                                        if (local_2d4 != (BIGNUM *)0x0) {
                                          iVar9 = BN_add_word(local_2d4,1);
                                          if (iVar9 == 0) {
                                            BIO_printf(bio_err,"add_word failure\n");
                                          }
                                          else {
                                            save_serial(pcVar32,0,local_2d4,&local_210);
                                          }
                                        }
                                        CRYPTO_free(pcVar32);
                                      }
                                      else {
                                        sVar21 = strlen(local_298);
                                        pcVar32 = (char *)CRYPTO_malloc(sVar21 + 1,"x509.c",0x45d);
                                        if (pcVar32 != (char *)0x0) {
                                          BUF_strlcpy(pcVar32,local_298,sVar21 + 1);
                                          goto LAB_00024090;
                                        }
LAB_000240d0:
                                        local_2d4 = (BIGNUM *)0x0;
                                        BIO_printf(bio_err,"out of mem\n");
                                      }
                                      BN_free(local_2d4);
                                      serial = (X509_STORE_CTX *)local_210.flags;
                                      if ((X509_STORE_CTX *)local_210.flags == (X509_STORE_CTX *)0x0
                                         ) goto LAB_00023f84;
                                    }
                                    X509_STORE_CTX_set_cert(&local_1f4,(X509 *)x);
                                    X509_STORE_CTX_set_flags(&local_1f4,0x4000);
                                    if ((reqfile == (X509_STORE_CTX *)0x0) &&
                                       (iVar9 = X509_verify_cert(&local_1f4), iVar9 < 1))
                                    goto LAB_00023f84;
                                    iVar9 = X509_check_private_key
                                                      ((X509 *)local_310,(EVP_PKEY *)local_30c);
                                    if (iVar9 == 0) {
                                      BIO_printf(bio_err,
                                                 "CA certificate and CA private key do not match\n")
                                      ;
                                      goto LAB_00023f84;
                                    }
                                    pXVar19 = X509_get_subject_name((X509 *)local_310);
                                    iVar9 = X509_set_issuer_name((X509 *)x,pXVar19);
                                    if ((((iVar9 == 0) ||
                                         (iVar9 = X509_set_serialNumber
                                                            ((X509 *)x,(ASN1_INTEGER *)serial),
                                         iVar9 == 0)) ||
                                        (pAVar20 = X509_gmtime_adj(*(ASN1_TIME **)x->ctx->verify,0),
                                        pAVar20 == (ASN1_TIME *)0x0)) ||
                                       (pAVar20 = X509_time_adj_ex(*(ASN1_TIME **)
                                                                    (x->ctx->verify + 4),local_2c4,0
                                                                   ,(time_t *)0x0),
                                       pAVar20 == (ASN1_TIME *)0x0)) goto LAB_00023f84;
                                    if (bVar6) {
                                      while (iVar9 = X509_get_ext_count((X509 *)x), 0 < iVar9) {
                                        X509_delete_ext((X509 *)x,0);
                                      }
                                    }
                                    if (pXVar11 != (X509_STORE_CTX *)0x0) {
                                      X509_set_version((X509 *)x,2);
                                      X509V3_set_ctx(&local_210,(X509 *)local_310,(X509 *)x,
                                                     (X509_REQ *)0x0,(X509_CRL *)0x0,0);
                                      X509V3_set_nconf(&local_210,(CONF *)pXVar11);
                                      iVar9 = X509V3_EXT_add_nconf
                                                        ((CONF *)pXVar11,&local_210,local_2cc,
                                                         (X509 *)x);
                                      if (iVar9 == 0) goto LAB_00023f84;
                                    }
                                    iVar9 = do_X509_sign(bio_err,x,local_30c,local_2bc,st);
                                    if (iVar9 == 0) goto LAB_00023f84;
                                    bVar4 = true;
                                    X509_STORE_CTX_cleanup(&local_1f4);
                                  }
                                  if (local_304 == (X509_STORE_CTX *)0x0) {
                                    ASN1_INTEGER_free((ASN1_INTEGER *)serial);
                                  }
                                  if (bVar4) goto LAB_0002379e;
                                }
LAB_00023966:
                                bVar36 = true;
                                goto LAB_00023190;
                              }
                              BIO_puts((BIO *)local_2f8,"notAfter=");
                              pAVar20 = *(ASN1_TIME **)(x->ctx->verify + 4);
                            }
                            ASN1_TIME_print((BIO *)local_2f8,pAVar20);
                            BIO_puts((BIO *)local_2f8,"\n");
                            goto LAB_0002379e;
                          }
                          X509_print_ex((BIO *)local_2f8,(X509 *)x,local_218,local_214);
                        }
                        goto LAB_0002379e;
                      }
                      uVar17 = X509_issuer_name_hash_old((X509 *)x);
                    }
                    BIO_printf((BIO *)local_2f8,"%08lx\n",uVar17);
                  }
                }
                else {
                  if (uVar29 == 0) {
                    sk = (_STACK *)X509_get1_ocsp((X509 *)x);
                  }
                  else {
                    sk = (_STACK *)X509_get1_email((X509 *)x);
                  }
                  for (iVar9 = 0; iVar14 = sk_num(sk), iVar9 < iVar14; iVar9 = iVar9 + 1) {
                    pvVar16 = sk_value(sk,iVar9);
                    BIO_printf((BIO *)local_2f8,"%s\n",pvVar16);
                  }
                  X509_email_free((stack_st_OPENSSL_STRING *)sk);
                }
              }
LAB_0002379e:
              pXVar33 = (X509_STORE_CTX *)((int)&pXVar33->ctx + 1);
              if ((int)local_2ec < (int)pXVar33) goto LAB_0002360e;
              goto LAB_0002372a;
            }
            local_30c = local_2ec;
            local_314 = local_2ec;
            pXVar27 = local_2ec;
LAB_0002360e:
            if (bVar36) {
              tVar23 = time((time_t *)0x0);
              local_1f4.ctx = (X509_STORE *)(local_234 + tVar23);
              iVar9 = X509_cmp_time(*(ASN1_TIME **)(x->ctx->verify + 4),(time_t *)&local_1f4);
              bVar36 = iVar9 < 0;
              if (bVar36) {
                pcVar32 = "Certificate will expire\n";
              }
              else {
                pcVar32 = "Certificate will not expire\n";
              }
              BIO_printf((BIO *)local_318,pcVar32);
            }
            else {
              if (local_2c0 == (X509_STORE_CTX *)0x0) {
                if (local_2e4 == 1) {
                  iVar9 = i2d_X509_bio((BIO *)local_318,(X509 *)x);
                }
                else if (local_2e4 == 3) {
                  if (bVar7) {
                    iVar9 = PEM_write_bio_X509_AUX((BIO *)local_318,(X509 *)x);
                  }
                  else {
                    iVar9 = PEM_write_bio_X509((BIO *)local_318,(X509 *)x);
                  }
                }
                else {
                  if (local_2e4 != 4) {
                    bVar36 = true;
                    BIO_printf(bio_err,"bad output format specified for outfile\n");
                    goto LAB_00023190;
                  }
                  local_1f4.cert = (X509 *)0x13e480;
                  local_210.flags = (int)&local_1f4;
                  local_1f4.ctx = (X509_STORE *)0xb;
                  local_210.issuer_cert = (X509 *)x;
                  iVar9 = ASN1_item_i2d_bio((ASN1_ITEM *)&NETSCAPE_X509_it,(BIO *)local_318,
                                            &local_210);
                }
                if (iVar9 == 0) {
                  bVar36 = true;
                  BIO_printf(bio_err,"unable to write certificate\n");
                  ERR_print_errors(bio_err);
                  goto LAB_00023190;
                }
              }
              bVar36 = false;
            }
          }
          else {
            bVar36 = true;
            pXVar27 = local_310;
            local_318 = local_310;
            local_314 = local_310;
            local_30c = local_310;
          }
        }
      }
      else {
        pXVar27 = (X509_STORE_CTX *)((uint)local_2a4 | (uint)local_294);
        if (pXVar27 == (X509_STORE_CTX *)0x0) {
          BIO_printf(bio_err,"We need a private key to sign with\n");
LAB_000233da:
          bVar36 = true;
          x = pXVar27;
          local_318 = pXVar27;
          local_314 = pXVar27;
          local_310 = pXVar27;
          local_30c = pXVar27;
          local_308 = pXVar27;
        }
        else {
          pBVar12 = BIO_s_file();
          x = (X509_STORE_CTX *)BIO_new(pBVar12);
          if (x == (X509_STORE_CTX *)0x0) {
            bVar36 = true;
            ERR_print_errors(bio_err);
            pXVar27 = x;
            local_318 = x;
            local_314 = x;
            local_310 = x;
            local_30c = x;
            local_308 = x;
          }
          else {
            if (local_2d8 == (char *)0x0) {
              BIO_ctrl((BIO *)x,0x6a,0x10,stdin);
            }
            else {
              lVar13 = BIO_ctrl((BIO *)x,0x6c,3,local_2d8);
              if (lVar13 < 1) {
                pXVar27 = (X509_STORE_CTX *)0x0;
                perror(local_2d8);
                BIO_free((BIO *)x);
                goto LAB_000233da;
              }
            }
            local_308 = (X509_STORE_CTX *)
                        PEM_read_bio_X509_REQ
                                  ((BIO *)x,(X509_REQ **)0x0,(undefined1 *)0x0,(void *)0x0);
            BIO_free((BIO *)x);
            if (local_308 == (X509_STORE_CTX *)0x0) {
              ERR_print_errors(bio_err);
              bVar36 = true;
              x = local_308;
              pXVar27 = local_308;
              local_318 = local_308;
              local_314 = local_308;
              local_310 = local_308;
              local_30c = local_308;
            }
            else {
              if ((((local_308->ctx == (X509_STORE *)0x0) ||
                   (p_Var28 = local_308->ctx->verify_cb, p_Var28 == (_func_1844 *)0x0)) ||
                  (iVar9 = *(int *)(p_Var28 + 4), iVar9 == 0)) || (*(int *)(iVar9 + 8) == 0)) {
                pXVar27 = (X509_STORE_CTX *)0x0;
                BIO_printf(bio_err,"The certificate request appears to corrupted\n");
                BIO_printf(bio_err,"It does not contain a public key\n");
              }
              else {
                x = (X509_STORE_CTX *)X509_REQ_get_pubkey((X509_REQ *)local_308);
                if (x == (X509_STORE_CTX *)0x0) {
                  BIO_printf(bio_err,"error unpacking public key\n");
                  pXVar27 = x;
                  local_318 = local_304;
LAB_00024570:
                  local_304 = local_318;
                  bVar36 = true;
                  local_318 = pXVar27;
                  local_314 = pXVar27;
                  local_310 = pXVar27;
                  local_30c = pXVar27;
                  goto LAB_00023190;
                }
                pXVar27 = (X509_STORE_CTX *)X509_REQ_verify((X509_REQ *)local_308,(EVP_PKEY *)x);
                EVP_PKEY_free((EVP_PKEY *)x);
                if ((int)pXVar27 < 0) {
                  pXVar27 = (X509_STORE_CTX *)0x0;
                  BIO_printf(bio_err,"Signature verification error\n");
                  ERR_print_errors(bio_err);
                }
                else {
                  if (pXVar27 != (X509_STORE_CTX *)0x0) {
                    BIO_printf(bio_err,"Signature ok\n");
                    print_name(bio_err,"subject=",local_308->ctx->verify,local_218);
                    x = (X509_STORE_CTX *)X509_new();
                    if (x == (X509_STORE_CTX *)0x0) {
                      bVar36 = true;
                      pXVar27 = x;
                      local_318 = x;
                      local_314 = x;
                      local_310 = x;
                      local_30c = x;
                    }
                    else if (local_304 == (X509_STORE_CTX *)0x0) {
                      local_318 = (X509_STORE_CTX *)ASN1_INTEGER_new();
                      if (local_318 != (X509_STORE_CTX *)0x0) {
                        pXVar27 = (X509_STORE_CTX *)rand_serial(0,local_318);
                        if ((pXVar27 == (X509_STORE_CTX *)0x0) ||
                           (pXVar27 = (X509_STORE_CTX *)
                                      X509_set_serialNumber((X509 *)x,(ASN1_INTEGER *)local_318),
                           pXVar27 == (X509_STORE_CTX *)0x0)) goto LAB_00024570;
                        ASN1_INTEGER_free((ASN1_INTEGER *)local_318);
                        goto LAB_00024534;
                      }
                      bVar36 = true;
                      pXVar27 = local_318;
                      local_314 = local_318;
                      local_310 = local_318;
                      local_30c = local_318;
                      local_304 = local_318;
                    }
                    else {
                      pXVar27 = (X509_STORE_CTX *)
                                X509_set_serialNumber((X509 *)x,(ASN1_INTEGER *)local_304);
                      if (pXVar27 != (X509_STORE_CTX *)0x0) {
LAB_00024534:
                        pXVar27 = (X509_STORE_CTX *)
                                  X509_set_issuer_name
                                            ((X509 *)x,(X509_NAME *)local_308->ctx->verify);
                        if ((pXVar27 != (X509_STORE_CTX *)0x0) &&
                           (pXVar27 = (X509_STORE_CTX *)
                                      X509_set_subject_name
                                                ((X509 *)x,(X509_NAME *)local_308->ctx->verify),
                           pXVar27 != (X509_STORE_CTX *)0x0)) {
                          X509_gmtime_adj(*(ASN1_TIME **)x->ctx->verify,0);
                          X509_time_adj_ex(*(ASN1_TIME **)(x->ctx->verify + 4),local_2c4,0,
                                           (time_t *)0x0);
                          pEVar24 = X509_REQ_get_pubkey((X509_REQ *)local_308);
                          X509_set_pubkey((X509 *)x,pEVar24);
                          EVP_PKEY_free(pEVar24);
                          goto LAB_00023534;
                        }
                      }
                      bVar36 = true;
                      local_318 = pXVar27;
                      local_314 = pXVar27;
                      local_310 = pXVar27;
                      local_30c = pXVar27;
                    }
                    goto LAB_00023190;
                  }
                  BIO_printf(bio_err,"Signature did not match the certificate request\n");
                }
              }
              bVar36 = true;
              x = pXVar27;
              local_318 = pXVar27;
              local_314 = pXVar27;
              local_310 = pXVar27;
              local_30c = pXVar27;
            }
          }
        }
      }
    }
    else {
      local_210.flags = -1;
      pXVar11 = (X509_STORE_CTX *)NCONF_new((CONF_METHOD *)0x0);
      iVar9 = NCONF_load((CONF *)pXVar11,(char *)local_2dc,&local_210.flags);
      if (iVar9 == 0) {
        if (local_210.flags < 1) {
          BIO_printf(bio_err,"error loading the config file \'%s\'\n",local_2dc);
        }
        else {
          BIO_printf(bio_err,"error on line %ld of config file \'%s\'\n",local_210.flags,local_2dc);
        }
      }
      else {
        if ((local_2cc == (char *)0x0) &&
           (local_2cc = NCONF_get_string((CONF *)pXVar11,"default","extensions"),
           local_2cc == (char *)0x0)) {
          ERR_clear_error();
          local_2cc = "default";
        }
        X509V3_set_ctx((X509V3_CTX *)&local_1f4,(X509 *)0x0,(X509 *)0x0,(X509_REQ *)0x0,
                       (X509_CRL *)0x0,1);
        X509V3_set_nconf((X509V3_CTX *)&local_1f4,(CONF *)pXVar11);
        iVar9 = X509V3_EXT_add_nconf((CONF *)pXVar11,(X509V3_CTX *)&local_1f4,local_2cc,(X509 *)0x0)
        ;
        if (iVar9 != 0) goto LAB_000233b2;
        BIO_printf(bio_err,"Error Loading extension section %s\n",local_2cc);
        ERR_print_errors(bio_err);
      }
      bVar36 = true;
      local_318 = (X509_STORE_CTX *)0x0;
      local_30c = (X509_STORE_CTX *)0x0;
      local_314 = (X509_STORE_CTX *)0x0;
      local_310 = (X509_STORE_CTX *)0x0;
      local_308 = (X509_STORE_CTX *)0x0;
      x = (X509_STORE_CTX *)0x0;
      pXVar27 = (X509_STORE_CTX *)0x0;
    }
  }
LAB_00023190:
  if (bVar5) {
    app_RAND_write_file(0,bio_err);
  }
LAB_00022ebe:
  OBJ_cleanup();
  NCONF_free((CONF *)pXVar11);
  BIO_free_all((BIO *)local_318);
  BIO_free_all((BIO *)local_2f8);
  X509_STORE_free((X509_STORE *)ctx);
  X509_REQ_free((X509_REQ *)local_308);
  X509_free((X509 *)x);
  X509_free((X509 *)local_310);
  EVP_PKEY_free((EVP_PKEY *)local_314);
  EVP_PKEY_free((EVP_PKEY *)local_30c);
  if (st != (X509_STORE_CTX *)0x0) {
    sk_free((_STACK *)st);
  }
  X509_REQ_free((X509_REQ *)pXVar27);
  ASN1_INTEGER_free((ASN1_INTEGER *)local_304);
  sk_pop_free((_STACK *)local_300,ASN1_OBJECT_free + 1);
  sk_pop_free((_STACK *)local_2fc,ASN1_OBJECT_free + 1);
  if (local_21c != (void *)0x0) {
    CRYPTO_free(local_21c);
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(bVar36);
}

