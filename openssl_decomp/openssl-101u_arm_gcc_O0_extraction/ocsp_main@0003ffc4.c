
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void ocsp_main(undefined4 param_1,int param_2)

{
  X509 *issuer;
  int iVar1;
  OCSP_BASICRESP *rsp;
  OCSP_ONEREQ *pOVar2;
  OCSP_CERTID *cid;
  int n;
  char *pcVar3;
  EVP_MD *dgst;
  ASN1_GENERALIZEDTIME *pAVar4;
  BIGNUM *a;
  OPENSSL_STRING *ppcVar5;
  OCSP_SINGLERESP *x;
  X509 *pXVar6;
  BIO *pBVar7;
  BIO_METHOD *type;
  long lVar8;
  X509 *pXVar9;
  void *pvVar10;
  X509_NAME *issuerName;
  ASN1_BIT_STRING *issuerKey;
  ASN1_INTEGER *serialNumber;
  X509 *pXVar11;
  int iVar12;
  uint uVar13;
  X509 *pXVar14;
  X509 *pXVar15;
  X509 *pXVar16;
  X509 *pXVar17;
  X509 *pXVar18;
  int iVar19;
  OCSP_CERTID *pOVar20;
  X509 *pXVar21;
  X509 *pXVar22;
  X509 *pXVar23;
  X509 *local_194;
  X509 *local_190;
  X509 *local_18c;
  X509 *local_188;
  X509 *local_184;
  X509 *local_180;
  X509 *local_17c;
  X509 *local_178;
  ASN1_TIME *local_174;
  X509 *local_170;
  X509 *local_16c;
  X509 *local_168;
  X509 *local_160;
  X509 *local_15c;
  X509 *local_158;
  X509 *local_154;
  X509 *local_150;
  X509 *local_14c;
  long local_148;
  X509 *local_144;
  X509 *local_13c;
  X509 *local_138;
  X509 *local_134;
  long local_130;
  X509 *local_12c;
  X509 *local_128;
  X509 *local_120;
  X509 *local_11c;
  X509 *local_10c;
  X509 *local_104;
  X509 *local_100;
  X509 *local_fc;
  X509 *local_f8;
  X509 *local_f4;
  X509 *local_f0;
  X509 *local_e8;
  long local_e4;
  long local_e0;
  X509 *local_dc;
  X509 *local_d8;
  X509 *local_c8;
  X509 *local_c4;
  X509 *local_c0;
  int local_bc;
  _STACK *local_b8;
  X509 *local_b4;
  BIO *local_b0;
  ASN1_INTEGER *local_ac;
  ASN1_OBJECT *local_a8;
  ASN1_OBJECT *local_a4;
  ASN1_TIME *local_a0;
  ASN1_GENERALIZEDTIME *local_9c;
  ASN1_GENERALIZEDTIME *local_98;
  ASN1_GENERALIZEDTIME *local_94;
  ASN1_GENERALIZEDTIME *local_90;
  ASN1_GENERALIZEDTIME *local_8c;
  ASN1_GENERALIZEDTIME *local_88;
  ASN1_GENERALIZEDTIME *local_84;
  char acStack_80 [84];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_c0 = (X509 *)&DAT_0012d4ec;
  local_c8 = (X509 *)0x0;
  local_c4 = (X509 *)0x0;
  local_b8 = (_STACK *)0x0;
  local_b4 = (X509 *)0x0;
  local_b0 = (BIO *)0x0;
  local_bc = -1;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  local_180 = (X509 *)load_config(bio_err,0);
  if (local_180 == (X509 *)0x0) {
    pXVar18 = local_180;
    pXVar17 = local_180;
    pXVar11 = (X509 *)0x1;
    pXVar9 = local_180;
    pXVar6 = local_180;
    issuer = local_180;
    local_194 = local_180;
    local_190 = local_180;
    local_18c = local_180;
    local_188 = local_180;
    local_184 = local_180;
    local_17c = local_180;
    local_178 = local_180;
    local_16c = local_180;
    local_168 = local_180;
    local_160 = local_180;
    local_158 = local_180;
    local_154 = local_180;
    local_150 = local_180;
    local_14c = local_180;
    goto LAB_0004003c;
  }
  SSL_load_error_strings();
  iVar12 = param_2 + 4;
  SSL_library_init();
  local_14c = (X509 *)sk_new_null();
  local_150 = (X509 *)sk_new_null();
  pXVar17 = *(X509 **)(param_2 + 4);
  if (pXVar17 == (X509 *)0x0) {
    local_144 = (X509 *)0xffffffff;
    local_148 = -1;
    local_e0 = -1;
    local_130 = -1;
    local_e4 = 300;
    local_174 = (ASN1_TIME *)0x1;
    pXVar11 = pXVar17;
    local_194 = pXVar17;
    local_190 = pXVar17;
    local_18c = pXVar17;
    local_180 = pXVar17;
    local_17c = pXVar17;
    local_178 = pXVar17;
    local_170 = pXVar17;
    local_16c = pXVar17;
    local_15c = pXVar17;
    local_158 = pXVar17;
    local_154 = pXVar17;
    local_13c = pXVar17;
    local_138 = pXVar17;
    local_134 = pXVar17;
    local_12c = pXVar17;
    local_128 = pXVar17;
    local_120 = pXVar17;
    local_11c = pXVar17;
    local_10c = pXVar17;
    local_104 = pXVar17;
    local_100 = pXVar17;
    local_fc = pXVar17;
    local_f8 = pXVar17;
    local_f4 = pXVar17;
    local_f0 = pXVar17;
    local_e8 = pXVar17;
    local_dc = pXVar17;
    local_d8 = pXVar17;
  }
  else {
    if (*(char *)&pXVar17->cert_info == '-') {
      local_180 = (X509 *)0x0;
      local_194 = (X509 *)0x0;
      local_148 = -1;
      local_170 = (X509 *)0x0;
      local_104 = (X509 *)0x0;
      local_fc = (X509 *)0x0;
      local_17c = (X509 *)0x0;
      local_100 = (X509 *)0x0;
      local_f8 = (X509 *)0x0;
      local_11c = (X509 *)0x0;
      local_12c = (X509 *)0x0;
      local_f0 = (X509 *)0x0;
      local_134 = (X509 *)0x0;
      local_d8 = (X509 *)0x0;
      local_dc = (X509 *)0x0;
      local_10c = (X509 *)0x0;
      local_128 = (X509 *)0x0;
      local_158 = (X509 *)0x0;
      local_154 = (X509 *)0x0;
      local_e8 = (X509 *)0x0;
      local_190 = (X509 *)0x0;
      local_18c = (X509 *)0x0;
      local_15c = (X509 *)0x0;
      local_13c = (X509 *)0x0;
      local_138 = (X509 *)0x0;
      local_120 = (X509 *)0x0;
      local_f4 = (X509 *)0x0;
      local_16c = (X509 *)0x0;
      local_144 = (X509 *)0xffffffff;
      local_e0 = -1;
      local_130 = -1;
      local_e4 = 300;
      local_174 = (ASN1_TIME *)0x1;
      local_178 = (X509 *)0x0;
      local_184 = (X509 *)0x0;
      pXVar18 = pXVar17;
      pXVar9 = (X509 *)0x0;
      do {
        pXVar17 = (X509 *)strcmp((char *)pXVar18,"-out");
        pXVar11 = pXVar9;
        if (pXVar17 == (X509 *)0x0) {
          pXVar11 = *(X509 **)(iVar12 + 4);
          if (pXVar11 == (X509 *)0x0) goto LAB_0004027c;
          iVar1 = iVar12 + 4;
        }
        else {
          pXVar17 = (X509 *)strcmp((char *)pXVar18,"-timeout");
          if (pXVar17 == (X509 *)0x0) {
            if (*(char **)(iVar12 + 4) == (char *)0x0) goto LAB_0004027c;
            local_130 = strtol(*(char **)(iVar12 + 4),(char **)0x0,10);
            if (-1 < local_130) goto LAB_000401ea;
            BIO_printf(bio_err,"Illegal timeout value %s\n",*(undefined4 *)(iVar12 + 4));
            pXVar17 = (X509 *)0x1;
            iVar1 = iVar12 + 4;
          }
          else {
            iVar1 = strcmp((char *)pXVar18,"-url");
            if (iVar1 == 0) {
              if (local_17c != (X509 *)0x0) {
                CRYPTO_free(local_17c);
              }
              if (local_178 != (X509 *)0x0) {
                CRYPTO_free(local_178);
              }
              if (local_180 != (X509 *)0x0) {
                CRYPTO_free(local_180);
              }
              if (*(char **)(iVar12 + 4) == (char *)0x0) goto LAB_0004027c;
              iVar12 = OCSP_parse_url(*(char **)(iVar12 + 4),(char **)&local_c8,(char **)&local_c4,
                                      (char **)&local_c0,&local_bc);
              if (iVar12 == 0) {
                BIO_printf(bio_err,"Error parsing URL\n");
              }
              pXVar17 = (X509 *)(uint)(iVar12 == 0);
              iVar1 = iVar12 + 4;
              local_180 = local_c0;
              local_17c = local_c8;
              local_178 = local_c4;
            }
            else {
              pXVar17 = (X509 *)strcmp((char *)pXVar18,"-host");
              if (pXVar17 == (X509 *)0x0) {
                if (*(X509 **)(iVar12 + 4) == (X509 *)0x0) goto LAB_0004027c;
                iVar1 = iVar12 + 4;
                local_c8 = *(X509 **)(iVar12 + 4);
              }
              else {
                pXVar17 = (X509 *)strcmp((char *)pXVar18,"-port");
                if (pXVar17 == (X509 *)0x0) {
                  if (*(X509 **)(iVar12 + 4) == (X509 *)0x0) goto LAB_0004027c;
                  iVar1 = iVar12 + 4;
                  local_c4 = *(X509 **)(iVar12 + 4);
                }
                else {
                  pXVar17 = (X509 *)strcmp((char *)pXVar18,"-header");
                  if (pXVar17 == (X509 *)0x0) {
                    if ((*(char **)(iVar12 + 4) == (char *)0x0) ||
                       (*(char **)(iVar12 + 8) == (char *)0x0)) goto LAB_0004027c;
                    pXVar18 = (X509 *)X509V3_add_value(*(char **)(iVar12 + 4),*(char **)(iVar12 + 8)
                                                       ,(stack_st_CONF_VALUE **)&local_b8);
                    if (pXVar18 == (X509 *)0x0) {
LAB_000414fa:
                      pXVar17 = pXVar18;
                      pXVar11 = (X509 *)0x1;
                      pXVar9 = pXVar18;
                      pXVar6 = pXVar18;
                      issuer = pXVar18;
                      local_194 = pXVar18;
                      local_190 = pXVar18;
                      local_18c = pXVar18;
                      local_188 = pXVar18;
                      local_184 = pXVar18;
                      local_16c = pXVar18;
                      local_168 = pXVar18;
                      local_160 = pXVar18;
                      goto LAB_0004003c;
                    }
                    iVar1 = iVar12 + 8;
                  }
                  else {
                    pXVar17 = (X509 *)strcmp((char *)pXVar18,"-ignore_err");
                    iVar1 = iVar12;
                    if (pXVar17 == (X509 *)0x0) {
                      local_fc = (X509 *)0x1;
                    }
                    else {
                      pXVar17 = (X509 *)strcmp((char *)pXVar18,"-noverify");
                      if (pXVar17 == (X509 *)0x0) {
                        local_e8 = (X509 *)0x1;
                      }
                      else {
                        pXVar17 = (X509 *)strcmp((char *)pXVar18,"-nonce");
                        if (pXVar17 == (X509 *)0x0) {
                          local_174 = (ASN1_TIME *)0x2;
                        }
                        else {
                          iVar19 = strcmp((char *)pXVar18,"-no_nonce");
                          if (iVar19 == 0) {
                            pXVar17 = (X509 *)0x0;
                            local_174 = (ASN1_TIME *)0x0;
                          }
                          else {
                            pXVar17 = (X509 *)strcmp((char *)pXVar18,"-resp_no_certs");
                            if (pXVar17 == (X509 *)0x0) {
                              local_100 = (X509 *)((uint)local_100 | 1);
                            }
                            else {
                              pXVar17 = (X509 *)strcmp((char *)pXVar18,"-resp_key_id");
                              if (pXVar17 == (X509 *)0x0) {
                                local_100 = (X509 *)((uint)local_100 | 0x400);
                              }
                              else {
                                pXVar17 = (X509 *)strcmp((char *)pXVar18,"-no_certs");
                                if (pXVar17 == (X509 *)0x0) {
                                  local_11c = (X509 *)0x1;
                                }
                                else {
                                  pXVar17 = (X509 *)strcmp((char *)pXVar18,"-no_signature_verify");
                                  if (pXVar17 == (X509 *)0x0) {
                                    local_f8 = (X509 *)((uint)local_f8 | 4);
                                  }
                                  else {
                                    pXVar17 = (X509 *)strcmp((char *)pXVar18,"-no_cert_verify");
                                    if (pXVar17 == (X509 *)0x0) {
                                      local_f8 = (X509 *)((uint)local_f8 | 0x10);
                                    }
                                    else {
                                      pXVar17 = (X509 *)strcmp((char *)pXVar18,"-no_chain");
                                      if (pXVar17 == (X509 *)0x0) {
                                        local_f8 = (X509 *)((uint)local_f8 | 8);
                                      }
                                      else {
                                        pXVar17 = (X509 *)strcmp((char *)pXVar18,"-no_cert_checks");
                                        if (pXVar17 == (X509 *)0x0) {
                                          local_f8 = (X509 *)((uint)local_f8 | 0x100);
                                        }
                                        else {
                                          pXVar17 = (X509 *)strcmp((char *)pXVar18,"-no_explicit");
                                          if (pXVar17 == (X509 *)0x0) {
                                            local_f8 = (X509 *)((uint)local_f8 | 0x20);
                                          }
                                          else {
                                            pXVar17 = (X509 *)strcmp((char *)pXVar18,"-trust_other")
                                            ;
                                            if (pXVar17 == (X509 *)0x0) {
                                              local_f8 = (X509 *)((uint)local_f8 | 0x200);
                                            }
                                            else {
                                              pXVar17 = (X509 *)strcmp((char *)pXVar18,"-no_intern")
                                              ;
                                              if (pXVar17 == (X509 *)0x0) {
                                                local_f8 = (X509 *)((uint)local_f8 | 2);
                                              }
                                              else {
                                                pXVar17 = (X509 *)strcmp((char *)pXVar18,"-text");
                                                if (pXVar17 == (X509 *)0x0) {
                                                  local_10c = (X509 *)0x1;
                                                  local_128 = (X509 *)0x1;
                                                }
                                                else {
                                                  pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                           "-req_text");
                                                  if (pXVar17 == (X509 *)0x0) {
                                                    local_128 = (X509 *)0x1;
                                                  }
                                                  else {
                                                    pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                             "-resp_text");
                                                    if (pXVar17 == (X509 *)0x0) {
                                                      local_10c = (X509 *)0x1;
                                                    }
                                                    else {
                                                      pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                               "-reqin");
                                                      if (pXVar17 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar12 + 4) != (X509 *)0x0) {
                                                          iVar1 = iVar12 + 4;
                                                          local_16c = *(X509 **)(iVar12 + 4);
                                                          goto LAB_00040198;
                                                        }
                                                      }
                                                      else {
                                                        pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                                 "-respin");
                                                        if (pXVar17 == (X509 *)0x0) {
                                                          if (*(X509 **)(iVar12 + 4) != (X509 *)0x0)
                                                          {
                                                            iVar1 = iVar12 + 4;
                                                            local_f4 = *(X509 **)(iVar12 + 4);
                                                            goto LAB_00040198;
                                                          }
                                                        }
                                                        else {
                                                          pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                                   "-signer");
                                                          if (pXVar17 == (X509 *)0x0) {
                                                            if (*(X509 **)(iVar12 + 4) !=
                                                                (X509 *)0x0) {
                                                              iVar1 = iVar12 + 4;
                                                              local_13c = *(X509 **)(iVar12 + 4);
                                                              goto LAB_00040198;
                                                            }
                                                          }
                                                          else {
                                                            pXVar17 = (X509 *)strcmp((char *)pXVar18
                                                                                     ,"-VAfile");
                                                            if (pXVar17 == (X509 *)0x0) {
                                                              if (*(X509 **)(iVar12 + 4) !=
                                                                  (X509 *)0x0) {
                                                                local_f8 = (X509 *)((uint)local_f8 |
                                                                                   0x200);
                                                                iVar1 = iVar12 + 4;
                                                                local_f0 = *(X509 **)(iVar12 + 4);
                                                                goto LAB_00040198;
                                                              }
                                                            }
                                                            else {
                                                              pXVar17 = (X509 *)strcmp((char *)
                                                  pXVar18,"-sign_other");
                                                  if (pXVar17 == (X509 *)0x0) {
                                                    if (*(X509 **)(iVar12 + 4) != (X509 *)0x0) {
                                                      iVar1 = iVar12 + 4;
                                                      local_134 = *(X509 **)(iVar12 + 4);
                                                      goto LAB_00040198;
                                                    }
                                                  }
                                                  else {
                                                    pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                             "-verify_other");
                                                    if (pXVar17 == (X509 *)0x0) {
                                                      if (*(X509 **)(iVar12 + 4) != (X509 *)0x0) {
                                                        iVar1 = iVar12 + 4;
                                                        local_f0 = *(X509 **)(iVar12 + 4);
                                                        goto LAB_00040198;
                                                      }
                                                    }
                                                    else {
                                                      pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                               "-CAfile");
                                                      if (pXVar17 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar12 + 4) != (X509 *)0x0) {
                                                          iVar1 = iVar12 + 4;
                                                          local_dc = *(X509 **)(iVar12 + 4);
                                                          goto LAB_00040198;
                                                        }
                                                      }
                                                      else {
                                                        pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                                 "-CApath");
                                                        if (pXVar17 == (X509 *)0x0) {
                                                          if (*(X509 **)(iVar12 + 4) != (X509 *)0x0)
                                                          {
                                                            iVar1 = iVar12 + 4;
                                                            local_d8 = *(X509 **)(iVar12 + 4);
                                                            goto LAB_00040198;
                                                          }
                                                        }
                                                        else {
                                                          pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                                                                                                                      
                                                  "-validity_period");
                                                  if (pXVar17 == (X509 *)0x0) {
                                                    if (*(char **)(iVar12 + 4) != (char *)0x0) {
                                                      local_e4 = strtol(*(char **)(iVar12 + 4),
                                                                        (char **)0x0,10);
                                                      if (local_e4 < 0) {
                                                        BIO_printf(bio_err,
                                                  "Illegal validity period %s\n",
                                                  *(undefined4 *)(iVar12 + 4));
                                                  pXVar17 = (X509 *)0x1;
                                                  iVar1 = iVar12 + 4;
                                                  }
                                                  else {
LAB_000401ea:
                                                    iVar1 = iVar12 + 4;
                                                  }
                                                  goto LAB_00040198;
                                                  }
                                                  }
                                                  else {
                                                    pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                             "-status_age");
                                                    if (pXVar17 == (X509 *)0x0) {
                                                      if (*(char **)(iVar12 + 4) != (char *)0x0) {
                                                        local_e0 = strtol(*(char **)(iVar12 + 4),
                                                                          (char **)0x0,10);
                                                        if (-1 < local_e0) goto LAB_000401ea;
                                                        BIO_printf(bio_err,
                                                  "Illegal validity age %s\n",
                                                  *(undefined4 *)(iVar12 + 4));
                                                  pXVar17 = (X509 *)0x1;
                                                  iVar1 = iVar12 + 4;
                                                  goto LAB_00040198;
                                                  }
                                                  }
                                                  else {
                                                    pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                             "-signkey");
                                                    if (pXVar17 == (X509 *)0x0) {
                                                      if (*(X509 **)(iVar12 + 4) != (X509 *)0x0) {
                                                        iVar1 = iVar12 + 4;
                                                        local_15c = *(X509 **)(iVar12 + 4);
                                                        goto LAB_00040198;
                                                      }
                                                    }
                                                    else {
                                                      pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                               "-reqout");
                                                      if (pXVar17 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar12 + 4) != (X509 *)0x0) {
                                                          iVar1 = iVar12 + 4;
                                                          local_120 = *(X509 **)(iVar12 + 4);
                                                          goto LAB_00040198;
                                                        }
                                                      }
                                                      else {
                                                        pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                                 "-respout");
                                                        if (pXVar17 == (X509 *)0x0) {
                                                          if (*(X509 **)(iVar12 + 4) != (X509 *)0x0)
                                                          {
                                                            iVar1 = iVar12 + 4;
                                                            local_138 = *(X509 **)(iVar12 + 4);
                                                            goto LAB_00040198;
                                                          }
                                                        }
                                                        else {
                                                          pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                                   "-path");
                                                          if (pXVar17 == (X509 *)0x0) {
                                                            if (*(X509 **)(iVar12 + 4) !=
                                                                (X509 *)0x0) {
                                                              iVar1 = iVar12 + 4;
                                                              local_c0 = *(X509 **)(iVar12 + 4);
                                                              goto LAB_00040198;
                                                            }
                                                          }
                                                          else {
                                                            iVar19 = strcmp((char *)pXVar18,
                                                                            "-issuer");
                                                            if (iVar19 == 0) {
                                                              if (*(int *)(iVar12 + 4) != 0) {
                                                                X509_free(local_154);
                                                                local_154 = (X509 *)load_cert(
                                                  bio_err,*(undefined4 *)(iVar12 + 4),3,0,0,
                                                  "issuer certificate");
                                                  if (local_154 == (X509 *)0x0) {
                                                    pXVar18 = (X509 *)0x0;
                                                    goto LAB_000414fa;
                                                  }
LAB_00041902:
                                                  pXVar17 = (X509 *)0x0;
                                                  iVar1 = iVar12 + 4;
                                                  goto LAB_00040198;
                                                  }
                                                  }
                                                  else {
                                                    iVar19 = strcmp((char *)pXVar18,"-cert");
                                                    if (iVar19 == 0) {
                                                      if (*(int *)(iVar12 + 4) != 0) {
                                                        X509_free(local_158);
                                                        local_168 = (X509 *)load_cert(bio_err,*(
                                                  undefined4 *)(iVar12 + 4),3,0,0,"certificate");
                                                  local_158 = local_168;
                                                  if (local_168 != (X509 *)0x0) {
                                                    if (local_184 == (X509 *)0x0) {
                                                      local_184 = (X509 *)EVP_sha1();
                                                    }
                                                    if (local_154 == (X509 *)0x0) {
LAB_000419aa:
                                                      BIO_printf(bio_err,
                                                  "No issuer certificate specified\n");
                                                  }
                                                  else {
                                                    if ((local_b4 != (X509 *)0x0) ||
                                                       (local_b4 = (X509 *)OCSP_REQUEST_new(),
                                                       local_b4 != (X509 *)0x0)) {
                                                      pOVar20 = OCSP_cert_to_id((EVP_MD *)local_184,
                                                                                local_168,local_154)
                                                      ;
joined_r0x0004196a:
                                                      if (((pOVar20 != (OCSP_CERTID *)0x0) &&
                                                          (iVar1 = sk_push((_STACK *)local_150,
                                                                           pOVar20), iVar1 != 0)) &&
                                                         (pOVar2 = OCSP_request_add0_id
                                                                             ((OCSP_REQUEST *)
                                                                              local_b4,pOVar20),
                                                         pOVar2 != (OCSP_ONEREQ *)0x0)) {
                                                        pXVar18 = (X509 *)sk_push((_STACK *)
                                                                                  local_14c,
                                                                                  *(void **)(iVar12 
                                                  + 4));
                                                  if (pXVar18 == (X509 *)0x0) goto LAB_000414fa;
                                                  goto LAB_00041902;
                                                  }
                                                  }
LAB_0004197a:
                                                  BIO_printf(bio_err,"Error Creating OCSP request\n"
                                                            );
                                                  }
LAB_00041998:
                                                  pXVar18 = (X509 *)0x0;
                                                  goto LAB_000414fa;
                                                  }
                                                  goto LAB_0004103e;
                                                  }
                                                  }
                                                  else {
                                                    iVar19 = strcmp((char *)pXVar18,"-serial");
                                                    if (iVar19 != 0) {
                                                      pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                               "-index");
                                                      if (pXVar17 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar12 + 4) == (X509 *)0x0)
                                                        goto LAB_0004027c;
                                                        iVar1 = iVar12 + 4;
                                                        local_104 = *(X509 **)(iVar12 + 4);
                                                      }
                                                      else if (((*(char *)((int)&pXVar18->cert_info
                                                                          + 1) == 'C') &&
                                                               (*(char *)((int)&pXVar18->cert_info +
                                                                         2) == 'A')) &&
                                                              (pXVar17 = (X509 *)(uint)*(byte *)((
                                                  int)&pXVar18->cert_info + 3),
                                                  pXVar17 == (X509 *)0x0)) {
                                                    if (*(X509 **)(iVar12 + 4) == (X509 *)0x0)
                                                    goto LAB_0004027c;
                                                    iVar1 = iVar12 + 4;
                                                    local_170 = *(X509 **)(iVar12 + 4);
                                                  }
                                                  else {
                                                    pXVar6 = (X509 *)strcmp((char *)pXVar18,"-nmin")
                                                    ;
                                                    if (pXVar6 == (X509 *)0x0) {
                                                      pXVar17 = *(X509 **)(iVar12 + 4);
                                                      if (pXVar17 != (X509 *)0x0) {
                                                        local_194 = (X509 *)strtol((char *)pXVar17,
                                                                                   (char **)0x0,10);
                                                        iVar1 = iVar12 + 4;
                                                        pXVar17 = pXVar6;
                                                        if ((int)local_194 < 0) {
                                                          BIO_printf(bio_err,
                                                  "Illegal update period %s\n",
                                                  *(undefined4 *)(iVar12 + 4));
                                                  pXVar17 = (X509 *)0x1;
                                                  }
                                                  }
                                                  iVar12 = iVar1;
                                                  if (local_148 != -1) goto LAB_0004027c;
                                                  local_148 = 0;
                                                  }
                                                  else {
                                                    pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                             "-nrequest");
                                                    if (pXVar17 == (X509 *)0x0) {
                                                      if (*(char **)(iVar12 + 4) == (char *)0x0)
                                                      goto LAB_0004027c;
                                                      local_144 = (X509 *)strtol(*(char **)(iVar12 +
                                                                                           4),
                                                                                 (char **)0x0,10);
                                                      if (-1 < (int)local_144) goto LAB_000401ea;
                                                      BIO_printf(bio_err,"Illegal accept count %s\n"
                                                                 ,*(undefined4 *)(iVar12 + 4));
                                                      pXVar17 = (X509 *)0x1;
                                                      iVar1 = iVar12 + 4;
                                                    }
                                                    else {
                                                      pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                               "-ndays");
                                                      if (pXVar17 == (X509 *)0x0) {
                                                        if (*(char **)(iVar12 + 4) == (char *)0x0)
                                                        goto LAB_0004027c;
                                                        local_148 = strtol(*(char **)(iVar12 + 4),
                                                                           (char **)0x0,10);
                                                        if (-1 < local_148) goto LAB_000401ea;
                                                        BIO_printf(bio_err,
                                                  "Illegal update period %s\n",
                                                  *(undefined4 *)(iVar12 + 4));
                                                  pXVar17 = (X509 *)0x1;
                                                  iVar1 = iVar12 + 4;
                                                  }
                                                  else {
                                                    pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                             "-rsigner");
                                                    if (pXVar17 == (X509 *)0x0) {
                                                      if (*(X509 **)(iVar12 + 4) == (X509 *)0x0)
                                                      goto LAB_0004027c;
                                                      iVar1 = iVar12 + 4;
                                                      local_18c = *(X509 **)(iVar12 + 4);
                                                    }
                                                    else {
                                                      pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                               "-rkey");
                                                      if (pXVar17 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar12 + 4) == (X509 *)0x0)
                                                        goto LAB_0004027c;
                                                        iVar1 = iVar12 + 4;
                                                        local_190 = *(X509 **)(iVar12 + 4);
                                                      }
                                                      else {
                                                        pXVar17 = (X509 *)strcmp((char *)pXVar18,
                                                                                 "-rother");
                                                        if (pXVar17 == (X509 *)0x0) {
                                                          if (*(X509 **)(iVar12 + 4) == (X509 *)0x0)
                                                          goto LAB_0004027c;
                                                          iVar1 = iVar12 + 4;
                                                          local_12c = *(X509 **)(iVar12 + 4);
                                                        }
                                                        else {
                                                          local_184 = (X509 *)EVP_get_digestbyname
                                                                                        ((char *)((
                                                  int)&pXVar18->cert_info + 1));
                                                  uVar13 = count_leading_zeroes(local_184);
                                                  pXVar17 = (X509 *)(uVar13 >> 5);
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00040198;
                                                  }
                                                  pcVar3 = *(char **)(iVar12 + 4);
                                                  if (pcVar3 != (char *)0x0) {
                                                    if (local_184 == (X509 *)0x0) {
                                                      local_184 = (X509 *)EVP_sha1();
                                                      pcVar3 = *(char **)(iVar12 + 4);
                                                    }
                                                    if (local_154 == (X509 *)0x0) goto LAB_000419aa;
                                                    if ((local_b4 == (X509 *)0x0) &&
                                                       (local_b4 = (X509 *)OCSP_REQUEST_new(),
                                                       local_b4 == (X509 *)0x0)) goto LAB_0004197a;
                                                    issuerName = X509_get_subject_name(local_154);
                                                    issuerKey = X509_get0_pubkey_bitstr(local_154);
                                                    serialNumber = s2i_ASN1_INTEGER((
                                                  X509V3_EXT_METHOD *)0x0,pcVar3);
                                                  if (serialNumber != (ASN1_INTEGER *)0x0) {
                                                    pOVar20 = OCSP_cert_id_new((EVP_MD *)local_184,
                                                                               issuerName,issuerKey,
                                                                               serialNumber);
                                                    ASN1_INTEGER_free(serialNumber);
                                                    goto joined_r0x0004196a;
                                                  }
                                                  BIO_printf(bio_err,
                                                  "Error converting serial number %s\n",pcVar3);
                                                  goto LAB_00041998;
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
LAB_0004027c:
                                                  pXVar17 = (X509 *)0x1;
                                                  iVar1 = iVar12;
                                                  pXVar11 = pXVar9;
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
LAB_00040198:
        iVar12 = iVar1 + 4;
        if (pXVar17 != (X509 *)0x0) {
          pXVar17 = (X509 *)0x1;
          goto LAB_000402ce;
        }
        pXVar18 = *(X509 **)(iVar1 + 4);
        if ((pXVar18 == (X509 *)0x0) || (pXVar9 = pXVar11, *(char *)&pXVar18->cert_info != '-'))
        goto LAB_000402ce;
      } while( true );
    }
    pXVar17 = (X509 *)0x0;
    local_194 = (X509 *)0x0;
    local_148 = -1;
    local_144 = (X509 *)0xffffffff;
    local_e0 = -1;
    local_130 = -1;
    local_170 = (X509 *)0x0;
    local_104 = (X509 *)0x0;
    local_fc = (X509 *)0x0;
    local_100 = (X509 *)0x0;
    local_f8 = (X509 *)0x0;
    local_11c = (X509 *)0x0;
    local_12c = (X509 *)0x0;
    local_f0 = (X509 *)0x0;
    local_134 = (X509 *)0x0;
    local_d8 = (X509 *)0x0;
    local_dc = (X509 *)0x0;
    local_10c = (X509 *)0x0;
    local_128 = (X509 *)0x0;
    local_158 = (X509 *)0x0;
    local_154 = (X509 *)0x0;
    local_e8 = (X509 *)0x0;
    local_190 = (X509 *)0x0;
    local_18c = (X509 *)0x0;
    local_15c = (X509 *)0x0;
    local_13c = (X509 *)0x0;
    local_138 = (X509 *)0x0;
    local_120 = (X509 *)0x0;
    local_f4 = (X509 *)0x0;
    local_16c = (X509 *)0x0;
    local_180 = (X509 *)0x0;
    local_178 = (X509 *)0x0;
    local_17c = (X509 *)0x0;
    local_e4 = 300;
    local_174 = (ASN1_TIME *)0x1;
    pXVar11 = pXVar17;
  }
LAB_000402ce:
  if ((((local_b4 == (X509 *)0x0) && (local_16c == (X509 *)0x0 && local_f4 == (X509 *)0x0)) &&
      ((local_c4 == (X509 *)0x0 || (local_104 == (X509 *)0x0)))) || (pXVar17 != (X509 *)0x0)) {
    BIO_printf(bio_err,"OCSP utility\n");
    BIO_printf(bio_err,"Usage ocsp [options]\n");
    BIO_printf(bio_err,"where options are\n");
    BIO_printf(bio_err,"-out file            output filename\n");
    BIO_printf(bio_err,"-issuer file         issuer certificate\n");
    BIO_printf(bio_err,"-cert file           certificate to check\n");
    BIO_printf(bio_err,"-serial n            serial number to check\n");
    BIO_printf(bio_err,"-signer file         certificate to sign OCSP request with\n");
    BIO_printf(bio_err,"-signkey file        private key to sign OCSP request with\n");
    BIO_printf(bio_err,"-sign_other file     additional certificates to include in signed request\n"
              );
    BIO_printf(bio_err,"-no_certs            don\'t include any certificates in signed request\n");
    BIO_printf(bio_err,"-req_text            print text form of request\n");
    BIO_printf(bio_err,"-resp_text           print text form of response\n");
    BIO_printf(bio_err,"-text                print text form of request and response\n");
    BIO_printf(bio_err,"-reqout file         write DER encoded OCSP request to \"file\"\n");
    BIO_printf(bio_err,"-respout file        write DER encoded OCSP reponse to \"file\"\n");
    BIO_printf(bio_err,"-reqin file          read DER encoded OCSP request from \"file\"\n");
    BIO_printf(bio_err,"-respin file         read DER encoded OCSP reponse from \"file\"\n");
    BIO_printf(bio_err,"-nonce               add OCSP nonce to request\n");
    BIO_printf(bio_err,"-no_nonce            don\'t add OCSP nonce to request\n");
    BIO_printf(bio_err,"-url URL             OCSP responder URL\n");
    BIO_printf(bio_err,"-host host:n         send OCSP request to host on port n\n");
    BIO_printf(bio_err,"-path                path to use in OCSP request\n");
    BIO_printf(bio_err,"-CApath dir          trusted certificates directory\n");
    BIO_printf(bio_err,"-CAfile file         trusted certificates file\n");
    BIO_printf(bio_err,"-no_alt_chains       only ever use the first certificate chain found\n");
    BIO_printf(bio_err,"-VAfile file         validator certificates file\n");
    BIO_printf(bio_err,"-validity_period n   maximum validity discrepancy in seconds\n");
    BIO_printf(bio_err,"-status_age n        maximum status age in seconds\n");
    BIO_printf(bio_err,"-noverify            don\'t verify response at all\n");
    BIO_printf(bio_err,"-verify_other file   additional certificates to search for signer\n");
    BIO_printf(bio_err,"-trust_other         don\'t verify additional certificates\n");
    BIO_printf(bio_err,
               "-no_intern           don\'t search certificates contained in response for signer\n")
    ;
    BIO_printf(bio_err,"-no_signature_verify don\'t check signature on response\n");
    BIO_printf(bio_err,"-no_cert_verify      don\'t check signing certificate\n");
    BIO_printf(bio_err,"-no_chain            don\'t chain verify response\n");
    BIO_printf(bio_err,"-no_cert_checks      don\'t do additional checks on signing certificate\n");
    BIO_printf(bio_err,"-port num            port to run responder on\n");
    BIO_printf(bio_err,"-index file          certificate status index file\n");
    BIO_printf(bio_err,"-CA file             CA certificate\n");
    BIO_printf(bio_err,"-rsigner file        responder certificate to sign responses with\n");
    BIO_printf(bio_err,"-rkey file           responder key to sign responses with\n");
    BIO_printf(bio_err,"-rother file         other certificates to include in response\n");
    BIO_printf(bio_err,"-resp_no_certs       don\'t include any certificates in response\n");
    BIO_printf(bio_err,"-nmin n              number of minutes before next update\n");
    BIO_printf(bio_err,"-ndays n             number of days before next update\n");
    BIO_printf(bio_err,"-resp_key_id         identify reponse by signing certificate key ID\n");
    BIO_printf(bio_err,"-nrequest n          number of requests to accept (default unlimited)\n");
    BIO_printf(bio_err,"-<dgst alg>          use specified digest in the request\n");
    BIO_printf(bio_err,"-timeout n           timeout connection to OCSP responder after n seconds\n"
              );
    local_188 = (X509 *)0x0;
    local_168 = (X509 *)0x0;
    goto LAB_00040cf0;
  }
  if (pXVar11 == (X509 *)0x0) {
    local_168 = (X509 *)BIO_new_fp(stdout,0);
  }
  else {
    local_168 = (X509 *)BIO_new_file((char *)pXVar11,"w");
  }
  pXVar18 = local_c4;
  if (local_168 == (X509 *)0x0) {
    BIO_printf(bio_err,"Error opening output file\n");
LAB_0004103e:
    pXVar18 = local_168;
    pXVar17 = local_168;
    pXVar11 = (X509 *)0x1;
    pXVar9 = local_168;
    pXVar6 = local_168;
    issuer = local_168;
    local_194 = local_168;
    local_190 = local_168;
    local_18c = local_168;
    local_188 = local_168;
    local_184 = local_168;
    local_16c = local_168;
    local_160 = local_168;
    goto LAB_0004003c;
  }
  if (local_b4 == (X509 *)0x0) {
    if (local_174 != (ASN1_TIME *)0x2) {
      local_174 = (ASN1_TIME *)0x0;
    }
    if (local_16c != (X509 *)0x0) {
      local_188 = (X509 *)BIO_new_file((char *)local_16c,"rb");
      if (local_188 == (X509 *)0x0) {
        BIO_printf(bio_err,"Error Opening OCSP request file\n");
      }
      else {
        local_b4 = (X509 *)ASN1_d2i_bio(OCSP_REQUEST_new,d2i_OCSP_REQUEST + 1,(BIO *)local_188,
                                        (void **)0x0);
        BIO_free((BIO *)local_188);
        local_188 = local_b4;
        if (local_b4 != (X509 *)0x0) goto LAB_00040302;
        BIO_printf(bio_err,"Error reading OCSP request\n");
      }
LAB_00040cf0:
      pXVar18 = local_188;
      pXVar17 = local_188;
      pXVar11 = (X509 *)0x1;
      pXVar9 = local_188;
      pXVar6 = local_188;
      issuer = local_188;
      local_194 = local_188;
      local_190 = local_188;
      local_18c = local_188;
      local_184 = local_188;
      local_16c = local_188;
      local_160 = local_188;
      goto LAB_0004003c;
    }
    if (local_c4 != (X509 *)0x0) {
      type = BIO_f_buffer();
      pXVar17 = (X509 *)BIO_new(type);
      local_184 = local_16c;
      if ((pXVar17 != (X509 *)0x0) &&
         (local_184 = (X509 *)BIO_new_accept((char *)pXVar18), local_184 != (X509 *)0x0)) {
        BIO_ctrl((BIO *)local_184,0x76,2,pXVar17);
        lVar8 = BIO_ctrl((BIO *)local_184,0x65,0,(void *)0x0);
        if (0 < lVar8) goto LAB_00040306;
        BIO_printf(bio_err,"Error setting up accept BIO\n");
        ERR_print_errors(bio_err);
        pXVar17 = local_16c;
      }
      BIO_free_all((BIO *)local_184);
      local_184 = (X509 *)0x0;
      BIO_free((BIO *)pXVar17);
      local_194 = (X509 *)0x0;
      local_188 = (X509 *)0x0;
      local_160 = (X509 *)0x0;
      local_18c = (X509 *)0x0;
      local_16c = (X509 *)0x0;
      local_190 = (X509 *)0x0;
      pXVar18 = (X509 *)0x0;
      pXVar17 = (X509 *)0x0;
      pXVar11 = (X509 *)0x1;
      pXVar9 = (X509 *)0x0;
      pXVar6 = (X509 *)0x0;
      issuer = (X509 *)0x0;
      goto LAB_0004003c;
    }
    local_184 = local_16c;
  }
  else {
LAB_00040302:
    local_184 = (X509 *)0x0;
  }
LAB_00040306:
  if (local_18c == (X509 *)0x0) {
    local_160 = local_18c;
    local_16c = local_18c;
    issuer = local_18c;
    local_12c = local_18c;
  }
  else {
    local_16c = (X509 *)load_cert(bio_err,local_18c,3,0,0,"responder certificate");
    if (local_190 == (X509 *)0x0) {
      local_190 = local_18c;
    }
    if (local_16c == (X509 *)0x0) {
      BIO_printf(bio_err,"Error loading responder certificate\n");
      pXVar18 = local_16c;
      pXVar17 = local_16c;
      pXVar11 = (X509 *)0x1;
      pXVar9 = local_16c;
      pXVar6 = local_16c;
      issuer = local_16c;
      local_194 = local_16c;
      local_190 = local_16c;
      local_18c = local_16c;
      local_188 = local_16c;
      local_160 = local_16c;
      goto LAB_0004003c;
    }
    issuer = (X509 *)load_cert(bio_err,local_170,3,0,0,"CA certificate");
    if ((local_12c != (X509 *)0x0) &&
       (local_12c = (X509 *)load_certs(bio_err,local_12c,3,0,0,"responder other certificates"),
       local_12c == (X509 *)0x0)) {
      pXVar18 = local_12c;
      pXVar17 = local_12c;
      pXVar11 = (X509 *)0x1;
      pXVar9 = local_12c;
      pXVar6 = local_12c;
      local_194 = local_12c;
      local_190 = local_12c;
      local_18c = local_12c;
      local_188 = local_12c;
      local_160 = local_12c;
      goto LAB_0004003c;
    }
    local_160 = (X509 *)load_key(bio_err,local_190,3,0,0,0,"responder private key");
    if (local_160 == (X509 *)0x0) {
      pXVar18 = local_160;
      pXVar17 = local_160;
      pXVar11 = (X509 *)0x1;
      pXVar9 = local_160;
      pXVar6 = local_160;
      local_194 = local_160;
      local_190 = local_160;
      local_18c = local_160;
      local_188 = local_160;
      goto LAB_0004003c;
    }
  }
  if (local_184 != (X509 *)0x0) {
    BIO_printf(bio_err,"Waiting for OCSP client connections...\n");
  }
  uVar13 = (uint)local_174;
  if (local_174 != (ASN1_TIME *)0x0) {
    uVar13 = 1;
  }
  iVar12 = (int)local_194 * 0x3c;
  local_194 = (X509 *)0x0;
  pXVar21 = local_104;
  if (local_104 != (X509 *)0x0) {
    pXVar21 = (X509 *)0x1;
  }
  pXVar14 = local_13c;
  if (local_13c != (X509 *)0x0) {
    pXVar14 = (X509 *)0x1;
  }
  pXVar22 = local_120;
  if (local_120 != (X509 *)0x0) {
    pXVar22 = (X509 *)0x1;
  }
  local_188 = (X509 *)0x0;
  local_18c = (X509 *)0x0;
  local_190 = (X509 *)0x0;
  pXVar15 = (X509 *)(uint)(local_160 == (X509 *)0x0 || local_16c == (X509 *)0x0);
  pXVar16 = (X509 *)0x0;
LAB_00040432:
  pXVar23 = pXVar16;
  if (local_184 == (X509 *)0x0) goto LAB_00040806;
LAB_0004043a:
  pXVar18 = (X509 *)do_responder_isra_0(&local_b4,&local_b0,local_184);
  if (pXVar18 != (X509 *)0x0) {
    pXVar23 = pXVar16;
    if (local_b4 == (X509 *)0x0) {
      pXVar6 = (X509 *)OCSP_response_create(1,(OCSP_BASICRESP *)0x0);
      pBVar7 = local_b0;
      memcpy(acStack_80,
             "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
             ,0x51);
      if (pBVar7 == (BIO *)0x0) goto LAB_00040788;
      iVar1 = i2d_OCSP_RESPONSE((OCSP_RESPONSE *)pXVar6,(uchar **)0x0);
      BIO_printf(pBVar7,acStack_80,iVar1);
      ASN1_i2d_bio((undefined1 *)0xdf1b9,pBVar7,(uchar *)pXVar6);
      BIO_ctrl(pBVar7,0xb,0,(void *)0x0);
      goto LAB_00040788;
    }
LAB_00040452:
    if (uVar13 != 0) {
      OCSP_request_add1_nonce((OCSP_REQUEST *)local_b4,(uchar *)0x0,-1);
    }
LAB_0004045a:
    pXVar6 = pXVar23;
    if (pXVar14 != (X509 *)0x0) {
      local_190 = (X509 *)load_cert(bio_err,local_13c,3,0,0,"signer certificate");
      if (local_15c == (X509 *)0x0) {
        local_15c = local_13c;
      }
      if (local_190 == (X509 *)0x0) {
        BIO_printf(bio_err,"Error loading signer certificate\n");
        pXVar18 = local_190;
        pXVar17 = local_190;
        pXVar11 = (X509 *)0x1;
        pXVar9 = local_190;
      }
      else if (((local_134 == (X509 *)0x0) ||
               (pXVar18 = (X509 *)load_certs(bio_err,local_134,3,0,0,"signer certificates"),
               local_188 = pXVar18, pXVar18 != (X509 *)0x0)) &&
              (pXVar18 = (X509 *)load_key(bio_err,local_15c,3,0,0,0,"signer private key"),
              local_18c = pXVar18, pXVar18 != (X509 *)0x0)) {
        pXVar18 = (X509 *)OCSP_request_sign((OCSP_REQUEST *)local_b4,local_190,(EVP_PKEY *)pXVar18,
                                            (EVP_MD *)0x0,(stack_st_X509 *)local_188,
                                            (ulong)local_11c);
        if (pXVar18 != (X509 *)0x0) goto LAB_00040504;
        BIO_printf(bio_err,"Error signing OCSP request\n");
        pXVar17 = pXVar18;
        pXVar11 = (X509 *)0x1;
        pXVar9 = pXVar18;
      }
      else {
LAB_00040f9c:
        pXVar17 = pXVar18;
        pXVar11 = (X509 *)0x1;
        pXVar9 = pXVar18;
      }
      goto LAB_0004003c;
    }
LAB_00040504:
    if ((local_128 != (X509 *)0x0) && (local_b4 != (X509 *)0x0)) {
      OCSP_REQUEST_print((BIO *)local_168,(OCSP_REQUEST *)local_b4,0);
    }
    if (pXVar22 != (X509 *)0x0) {
      pXVar18 = (X509 *)BIO_new_file((char *)local_120,"wb");
      pXVar17 = local_120;
      if (pXVar18 != (X509 *)0x0) {
        ASN1_i2d_bio(i2d_OCSP_REQUEST + 1,(BIO *)pXVar18,(uchar *)local_b4);
        BIO_free((BIO *)pXVar18);
        goto LAB_00040544;
      }
LAB_000410ac:
      BIO_printf(bio_err,"Error opening file %s\n",pXVar17);
      pXVar17 = pXVar18;
      pXVar11 = (X509 *)0x1;
      pXVar9 = pXVar18;
      goto LAB_0004003c;
    }
LAB_00040544:
    if (pXVar21 == (X509 *)0x0) {
      if (local_194 == (X509 *)0x0) {
        if (local_c8 == (X509 *)0x0) {
          pXVar18 = local_194;
          pXVar17 = local_194;
          pXVar11 = local_194;
          pXVar9 = local_194;
          if (local_f4 == (X509 *)0x0) goto LAB_0004003c;
          pBVar7 = BIO_new_file((char *)local_f4,"rb");
          if (pBVar7 == (BIO *)0x0) {
            BIO_printf(bio_err,"Error Opening OCSP response file\n");
            pXVar18 = local_194;
            pXVar17 = local_194;
            pXVar11 = (X509 *)0x1;
            pXVar9 = local_194;
            goto LAB_0004003c;
          }
          pXVar6 = (X509 *)ASN1_d2i_bio(OCSP_RESPONSE_new + 1,d2i_OCSP_RESPONSE + 1,pBVar7,
                                        (void **)0x0);
          BIO_free(pBVar7);
          if (pXVar6 == (X509 *)0x0) {
            BIO_printf(bio_err,"Error reading OCSP response\n");
            pXVar18 = pXVar6;
            pXVar17 = pXVar6;
            pXVar11 = (X509 *)0x1;
            pXVar9 = pXVar6;
            goto LAB_0004003c;
          }
        }
        else {
          pXVar6 = (X509 *)process_responder(bio_err,local_b4,local_c8,local_c0,local_c4,local_bc,
                                             local_b8,local_130);
          if (pXVar6 == (X509 *)0x0) {
            pXVar18 = pXVar6;
            pXVar17 = pXVar6;
            pXVar11 = (X509 *)0x1;
            pXVar9 = pXVar6;
            goto LAB_0004003c;
          }
        }
        goto LAB_00040788;
      }
    }
    else {
      if ((pXVar15 != (X509 *)0x0) || (issuer == (X509 *)0x0)) {
        pcVar3 = "Need a responder certificate, key and CA for this operation!\n";
        goto LAB_00040836;
      }
      if (local_194 == (X509 *)0x0) {
        pXVar18 = (X509 *)load_index(local_104,0);
        local_194 = pXVar18;
        if (pXVar18 == (X509 *)0x0) goto LAB_00040f9c;
        iVar1 = index_index();
        if (iVar1 != 0) goto LAB_00040564;
        pXVar18 = pXVar15;
        pXVar17 = pXVar15;
        pXVar11 = (X509 *)0x1;
        pXVar9 = pXVar15;
        goto LAB_0004003c;
      }
    }
LAB_00040564:
    pXVar18 = local_b4;
    iVar1 = OCSP_request_onereq_count((OCSP_REQUEST *)local_b4);
    if (iVar1 < 1) {
      rsp = (OCSP_BASICRESP *)0x0;
      pXVar6 = (X509 *)OCSP_response_create(1,(OCSP_BASICRESP *)0x0);
      pOVar20 = (OCSP_CERTID *)0x0;
      local_170 = (X509 *)0x0;
      local_174 = (ASN1_TIME *)0x0;
    }
    else {
      rsp = OCSP_BASICRESP_new();
      local_174 = X509_gmtime_adj((ASN1_TIME *)0x0,0);
      if (local_148 == -1) {
        local_170 = (X509 *)0x0;
      }
      else {
        local_170 = (X509 *)X509_time_adj_ex((ASN1_TIME *)0x0,local_148,iVar12,(time_t *)0x0);
      }
      pOVar20 = (OCSP_CERTID *)0x0;
      iVar19 = 0;
      do {
        while( true ) {
          pOVar2 = OCSP_request_onereq_get0((OCSP_REQUEST *)pXVar18,iVar19);
          cid = OCSP_onereq_get0_id(pOVar2);
          OCSP_id_get0_info((ASN1_OCTET_STRING **)0x0,&local_a8,(ASN1_OCTET_STRING **)0x0,
                            (ASN1_INTEGER **)0x0,cid);
          n = OBJ_obj2nid(local_a8);
          pcVar3 = OBJ_nid2sn(n);
          dgst = EVP_get_digestbyname(pcVar3);
          if (dgst == (EVP_MD *)0x0) {
            pXVar6 = (X509 *)OCSP_response_create(2,(OCSP_BASICRESP *)0x0);
            goto LAB_00040730;
          }
          if (pOVar20 != (OCSP_CERTID *)0x0) {
            OCSP_CERTID_free(pOVar20);
          }
          pOVar20 = OCSP_cert_to_id(dgst,(X509 *)0x0,issuer);
          pAVar4 = (ASN1_GENERALIZEDTIME *)OCSP_id_issuer_cmp(pOVar20,cid);
          if (pAVar4 == (ASN1_GENERALIZEDTIME *)0x0) break;
          OCSP_basic_add1_status(rsp,cid,2,0,(ASN1_TIME *)0x0,local_174,(ASN1_TIME *)local_170);
LAB_000405c2:
          iVar19 = iVar19 + 1;
          if (iVar19 == iVar1) goto LAB_00040702;
        }
        OCSP_id_get0_info((ASN1_OCTET_STRING **)0x0,(ASN1_OBJECT **)0x0,(ASN1_OCTET_STRING **)0x0,
                          &local_ac,cid);
        local_98 = pAVar4;
        local_94 = pAVar4;
        local_90 = pAVar4;
        local_8c = pAVar4;
        local_88 = pAVar4;
        local_84 = pAVar4;
        a = ASN1_INTEGER_to_BN(local_ac,(BIGNUM *)0x0);
        if (a == (BIGNUM *)0x0) {
          OpenSSLDie("ocsp.c",0x445,"bn");
        }
        if (a->top == 0) {
          pcVar3 = BUF_strdup("00");
        }
        else {
          pcVar3 = BN_bn2hex(a);
        }
        local_8c = (ASN1_GENERALIZEDTIME *)pcVar3;
        BN_free(a);
        ppcVar5 = TXT_DB_get_by_index((TXT_DB *)local_194->sig_alg,3,(OPENSSL_STRING *)&local_98);
        CRYPTO_free(pcVar3);
        if (ppcVar5 == (OPENSSL_STRING *)0x0) {
          OCSP_basic_add1_status(rsp,cid,2,0,(ASN1_TIME *)0x0,local_174,(ASN1_TIME *)local_170);
          goto LAB_000405c2;
        }
        if (**ppcVar5 == 'V') {
          OCSP_basic_add1_status(rsp,cid,0,0,(ASN1_TIME *)0x0,local_174,(ASN1_TIME *)local_170);
          goto LAB_000405c2;
        }
        if (**ppcVar5 != 'R') goto LAB_000405c2;
        local_a4 = (ASN1_OBJECT *)0x0;
        local_a0 = (ASN1_TIME *)0x0;
        local_9c = (ASN1_GENERALIZEDTIME *)0x0;
        local_98 = (ASN1_GENERALIZEDTIME *)0xffffffff;
        unpack_revinfo(&local_a0,&local_98,&local_a4,&local_9c,ppcVar5[2]);
        x = OCSP_basic_add1_status
                      (rsp,cid,1,(int)local_98,local_a0,local_174,(ASN1_TIME *)local_170);
        if (local_9c == (ASN1_GENERALIZEDTIME *)0x0) {
          if (local_a4 != (ASN1_OBJECT *)0x0) {
            OCSP_SINGLERESP_add1_ext_i2d(x,0x1ae,local_a4,0,0);
          }
        }
        else {
          OCSP_SINGLERESP_add1_ext_i2d(x,0x8e,local_9c,0,0);
        }
        ASN1_OBJECT_free(local_a4);
        ASN1_TIME_free(local_a0);
        iVar19 = iVar19 + 1;
        ASN1_GENERALIZEDTIME_free(local_9c);
      } while (iVar19 != iVar1);
LAB_00040702:
      OCSP_copy_nonce(rsp,(OCSP_REQUEST *)pXVar18);
      OCSP_basic_sign(rsp,local_16c,(EVP_PKEY *)local_160,(EVP_MD *)0x0,(stack_st_X509 *)local_12c,
                      (ulong)local_100);
      pXVar6 = (X509 *)OCSP_response_create(0,rsp);
    }
LAB_00040730:
    ASN1_TIME_free(local_174);
    ASN1_TIME_free((ASN1_TIME *)local_170);
    OCSP_CERTID_free(pOVar20);
    OCSP_BASICRESP_free(rsp);
    pBVar7 = local_b0;
    if (local_b0 != (BIO *)0x0) {
      memcpy(acStack_80,
             "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
             ,0x51);
      iVar1 = i2d_OCSP_RESPONSE((OCSP_RESPONSE *)pXVar6,(uchar **)0x0);
      BIO_printf(pBVar7,acStack_80,iVar1);
      ASN1_i2d_bio((undefined1 *)0xdf1b9,pBVar7,(uchar *)pXVar6);
      BIO_ctrl(pBVar7,0xb,0,(void *)0x0);
    }
LAB_00040788:
    if (local_138 != (X509 *)0x0) {
      pXVar18 = (X509 *)BIO_new_file((char *)local_138,"wb");
      pXVar17 = local_138;
      if (pXVar18 == (X509 *)0x0) goto LAB_000410ac;
      ASN1_i2d_bio((undefined1 *)0xdf1b9,(BIO *)pXVar18,(uchar *)pXVar6);
      BIO_free((BIO *)pXVar18);
    }
    iVar1 = OCSP_response_status((OCSP_RESPONSE *)pXVar6);
    if (iVar1 != 0) {
      pcVar3 = OCSP_response_status_str(iVar1);
      BIO_printf((BIO *)local_168,"Responder Error: %s (%d)\n",pcVar3,iVar1);
      pXVar18 = local_fc;
      pXVar17 = local_fc;
      pXVar11 = local_fc;
      pXVar9 = local_fc;
      pXVar16 = pXVar6;
      if (local_fc != (X509 *)0x0) goto LAB_00040432;
      goto LAB_0004003c;
    }
    if (local_10c != (X509 *)0x0) {
      OCSP_RESPONSE_print((BIO *)local_168,(OCSP_RESPONSE *)pXVar6,0);
    }
    if (local_b0 == (BIO *)0x0) {
      pXVar9 = (X509 *)setup_verify(bio_err,local_dc,local_d8);
      if (pXVar9 == (X509 *)0x0) {
        pXVar18 = pXVar9;
        pXVar17 = pXVar9;
        pXVar11 = (X509 *)0x1;
        goto LAB_0004003c;
      }
      if ((local_f0 != (X509 *)0x0) &&
         (local_f0 = (X509 *)load_certs(bio_err,local_f0,3,0,0,"validator certificate"),
         local_f0 == (X509 *)0x0)) {
        pXVar18 = local_f0;
        pXVar17 = local_f0;
        pXVar11 = (X509 *)0x1;
        goto LAB_0004003c;
      }
      pXVar17 = (X509 *)OCSP_response_get1_basic((OCSP_RESPONSE *)pXVar6);
      pXVar18 = local_f0;
      if (pXVar17 == (X509 *)0x0) {
        BIO_printf(bio_err,"Error parsing response\n");
        pXVar11 = (X509 *)0x1;
        goto LAB_0004003c;
      }
      if (local_e8 == (X509 *)0x0) {
        if ((local_b4 != (X509 *)0x0) &&
           (iVar12 = OCSP_check_nonce((OCSP_REQUEST *)local_b4,(OCSP_BASICRESP *)pXVar17),
           iVar12 < 1)) {
          if (iVar12 != -1) {
            BIO_printf(bio_err,"Nonce Verify error\n");
            pXVar11 = (X509 *)0x1;
            goto LAB_0004003c;
          }
          BIO_printf(bio_err,"WARNING: no nonce in response\n");
        }
        iVar12 = OCSP_basic_verify((OCSP_BASICRESP *)pXVar17,(stack_st_X509 *)local_f0,
                                   (X509_STORE *)pXVar9,(ulong)local_f8);
        if (iVar12 < 0) {
          iVar12 = OCSP_basic_verify((OCSP_BASICRESP *)pXVar17,(stack_st_X509 *)0x0,
                                     (X509_STORE *)pXVar9,0);
        }
        if (iVar12 < 1) {
          BIO_printf(bio_err,"Response Verify Failure\n");
          ERR_print_errors(bio_err);
        }
        else {
          BIO_printf(bio_err,"Response verify OK\n");
        }
      }
      if (((local_b4 != (X509 *)0x0) && (iVar12 = sk_num((_STACK *)local_14c), iVar12 != 0)) &&
         (iVar12 = sk_num((_STACK *)local_150), iVar12 != 0)) {
        for (iVar12 = 0; iVar1 = sk_num((_STACK *)local_150), iVar12 < iVar1; iVar12 = iVar12 + 1) {
          pOVar20 = (OCSP_CERTID *)sk_value((_STACK *)local_150,iVar12);
          pvVar10 = sk_value((_STACK *)local_14c,iVar12);
          BIO_printf((BIO *)local_168,"%s: ",pvVar10);
          iVar1 = OCSP_resp_find_status
                            ((OCSP_BASICRESP *)pXVar17,pOVar20,(int *)&local_a8,(int *)&local_a4,
                             &local_a0,&local_9c,&local_98);
          if (iVar1 == 0) {
            BIO_puts((BIO *)local_168,"ERROR: No Status found.\n");
          }
          else {
            iVar1 = OCSP_check_validity(local_9c,local_98,local_e4,local_e0);
            if (iVar1 == 0) {
              BIO_puts((BIO *)local_168,"WARNING: Status times invalid.\n");
              ERR_print_errors(local_168);
            }
            pcVar3 = OCSP_cert_status_str((long)local_a8);
            BIO_printf((BIO *)local_168,"%s\n",pcVar3);
            BIO_puts((BIO *)local_168,"\tThis Update: ");
            ASN1_GENERALIZEDTIME_print((BIO *)local_168,local_9c);
            BIO_puts((BIO *)local_168,"\n");
            if (local_98 != (ASN1_GENERALIZEDTIME *)0x0) {
              BIO_puts((BIO *)local_168,"\tNext Update: ");
              ASN1_GENERALIZEDTIME_print((BIO *)local_168,local_98);
              BIO_puts((BIO *)local_168,"\n");
            }
            if (local_a8 == (ASN1_OBJECT *)0x1) {
              if (local_a4 != (ASN1_OBJECT *)0xffffffff) {
                pcVar3 = OCSP_crl_reason_str((long)local_a4);
                BIO_printf((BIO *)local_168,"\tReason: %s\n",pcVar3);
              }
              BIO_puts((BIO *)local_168,"\tRevocation Time: ");
              ASN1_GENERALIZEDTIME_print((BIO *)local_168,local_a0);
              BIO_puts((BIO *)local_168,"\n");
            }
          }
        }
      }
      pXVar11 = (X509 *)0x0;
      goto LAB_0004003c;
    }
    if (0 < (int)local_144) {
      local_144 = (X509 *)((int)&local_144[-1].aux + 3);
    }
    if (local_144 == (X509 *)0x0) {
      pXVar18 = local_144;
      pXVar17 = local_144;
      pXVar11 = (X509 *)0x1;
      pXVar9 = local_144;
      goto LAB_0004003c;
    }
    BIO_free_all(local_b0);
    pXVar16 = (X509 *)0x0;
    local_b0 = (BIO *)0x0;
    OCSP_REQUEST_free((OCSP_REQUEST *)local_b4);
    local_b4 = (X509 *)0x0;
    pXVar23 = (X509 *)0x0;
    OCSP_RESPONSE_free((OCSP_RESPONSE *)pXVar6);
    if (local_184 != (X509 *)0x0) goto LAB_0004043a;
LAB_00040806:
    if (local_b4 == (X509 *)0x0) goto code_r0x0004080e;
    goto LAB_00040452;
  }
  pXVar17 = pXVar18;
  pXVar11 = (X509 *)0x1;
  pXVar9 = pXVar18;
  pXVar6 = pXVar16;
LAB_0004003c:
  ERR_print_errors(bio_err);
  X509_free(local_190);
  X509_STORE_free((X509_STORE *)pXVar9);
  EVP_PKEY_free((EVP_PKEY *)local_18c);
  EVP_PKEY_free((EVP_PKEY *)local_160);
  X509_free(local_154);
  X509_free(local_158);
  X509_free(local_16c);
  X509_free(issuer);
  free_index(local_194);
  BIO_free_all(local_b0);
  BIO_free_all((BIO *)local_184);
  BIO_free((BIO *)local_168);
  OCSP_REQUEST_free((OCSP_REQUEST *)local_b4);
  OCSP_RESPONSE_free((OCSP_RESPONSE *)pXVar6);
  OCSP_BASICRESP_free((OCSP_BASICRESP *)pXVar17);
  sk_free((_STACK *)local_14c);
  sk_free((_STACK *)local_150);
  sk_pop_free((_STACK *)local_188,X509_free);
  sk_pop_free((_STACK *)pXVar18,X509_free);
  sk_pop_free(local_b8,X509V3_conf_free + 1);
  if (local_17c != (X509 *)0x0) {
    CRYPTO_free(local_17c);
  }
  if (local_178 != (X509 *)0x0) {
    CRYPTO_free(local_178);
  }
  if (local_180 != (X509 *)0x0) {
    CRYPTO_free(local_180);
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pXVar11);
code_r0x0004080e:
  if (((((uint)pXVar22 | (uint)pXVar14) != 0) || (local_c8 != (X509 *)0x0)) ||
     ((uVar13 | (uint)pXVar21) != 0)) {
    pcVar3 = "Need an OCSP request for this operation!\n";
LAB_00040836:
    BIO_printf(bio_err,pcVar3);
    pXVar18 = (X509 *)0x0;
    pXVar17 = (X509 *)0x0;
    pXVar11 = (X509 *)0x1;
    pXVar9 = (X509 *)0x0;
    pXVar6 = pXVar23;
    goto LAB_0004003c;
  }
  goto LAB_0004045a;
}

