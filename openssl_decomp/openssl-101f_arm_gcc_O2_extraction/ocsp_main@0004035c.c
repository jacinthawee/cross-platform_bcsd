
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void ocsp_main(undefined4 param_1,int param_2)

{
  OCSP_BASICRESP *rsp;
  OCSP_ONEREQ *pOVar1;
  OCSP_CERTID *cid;
  int n;
  char *pcVar2;
  EVP_MD *dgst;
  ASN1_GENERALIZEDTIME *pAVar3;
  BIGNUM *a;
  OPENSSL_STRING *ppcVar4;
  OCSP_SINGLERESP *x;
  X509 *pXVar5;
  BIO *pBVar6;
  BIO_METHOD *type;
  long lVar7;
  X509 *pXVar8;
  void *pvVar9;
  X509_NAME *issuerName;
  ASN1_BIT_STRING *issuerKey;
  ASN1_INTEGER *serialNumber;
  int iVar10;
  uint uVar11;
  X509 *pXVar12;
  X509 *pXVar13;
  X509 *pXVar14;
  X509 *pXVar15;
  X509 *pXVar16;
  int iVar17;
  int iVar18;
  OCSP_CERTID *pOVar19;
  X509 *pXVar20;
  X509 *pXVar21;
  X509 *pXVar22;
  X509 *pXVar23;
  X509 *issuer;
  X509 *local_188;
  X509 *local_184;
  X509 *local_180;
  X509 *local_17c;
  X509 *local_178;
  X509 *local_174;
  X509 *local_170;
  ASN1_TIME *local_16c;
  X509 *local_168;
  X509 *local_160;
  X509 *local_15c;
  X509 *local_158;
  X509 *local_154;
  X509 *local_150;
  X509 *local_14c;
  X509 *local_148;
  long local_144;
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
  char *local_c8;
  char *local_c4;
  char *local_c0;
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
  
  local_2c = __TMC_END__;
  local_c0 = "/";
  local_c8 = (char *)0x0;
  local_c4 = (char *)0x0;
  local_b8 = (_STACK *)0x0;
  local_b4 = (X509 *)0x0;
  local_b0 = (BIO *)0x0;
  local_bc = -1;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  local_158 = (X509 *)load_config(bio_err,0);
  if (local_158 == (X509 *)0x0) {
    pXVar16 = local_158;
    pXVar15 = local_158;
    pXVar20 = (X509 *)0x1;
    pXVar8 = local_158;
    pXVar5 = local_158;
    issuer = local_158;
    local_188 = local_158;
    local_184 = local_158;
    local_180 = local_158;
    local_17c = local_158;
    local_178 = local_158;
    local_170 = local_158;
    local_168 = local_158;
    local_160 = local_158;
    local_154 = local_158;
    local_150 = local_158;
    local_14c = local_158;
    goto LAB_000403ce;
  }
  SSL_load_error_strings();
  iVar10 = param_2 + 4;
  SSL_library_init();
  local_14c = (X509 *)sk_new_null();
  local_150 = (X509 *)sk_new_null();
  pXVar15 = *(X509 **)(param_2 + 4);
  if (pXVar15 == (X509 *)0x0) {
    local_148 = (X509 *)0xffffffff;
    local_144 = -1;
    local_e0 = -1;
    local_130 = -1;
    local_e4 = 300;
    local_180 = (X509 *)0x1;
    pXVar20 = pXVar15;
    issuer = pXVar15;
    local_188 = pXVar15;
    local_184 = pXVar15;
    local_17c = pXVar15;
    local_174 = pXVar15;
    local_15c = pXVar15;
    local_158 = pXVar15;
    local_154 = pXVar15;
    local_13c = pXVar15;
    local_138 = pXVar15;
    local_134 = pXVar15;
    local_12c = pXVar15;
    local_128 = pXVar15;
    local_120 = pXVar15;
    local_11c = pXVar15;
    local_10c = pXVar15;
    local_104 = pXVar15;
    local_100 = pXVar15;
    local_fc = pXVar15;
    local_f8 = pXVar15;
    local_f4 = pXVar15;
    local_f0 = pXVar15;
    local_e8 = pXVar15;
    local_dc = pXVar15;
    local_d8 = pXVar15;
  }
  else {
    if (*(char *)&pXVar15->cert_info == '-') {
      local_144 = -1;
      local_188 = (X509 *)0x0;
      pXVar20 = (X509 *)0x0;
      local_17c = (X509 *)0x0;
      issuer = (X509 *)0x0;
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
      local_184 = (X509 *)0x0;
      local_15c = (X509 *)0x0;
      local_13c = (X509 *)0x0;
      local_138 = (X509 *)0x0;
      local_120 = (X509 *)0x0;
      local_f4 = (X509 *)0x0;
      local_174 = (X509 *)0x0;
      local_148 = (X509 *)0xffffffff;
      local_e0 = -1;
      local_130 = -1;
      local_e4 = 300;
      local_180 = (X509 *)0x1;
      local_178 = (X509 *)0x0;
      pXVar16 = pXVar15;
      do {
        pXVar15 = (X509 *)strcmp((char *)pXVar16,"-out");
        if (pXVar15 == (X509 *)0x0) {
          if (*(X509 **)(iVar10 + 4) == (X509 *)0x0) goto LAB_000405ea;
          iVar17 = iVar10 + 4;
          pXVar20 = *(X509 **)(iVar10 + 4);
        }
        else {
          pXVar15 = (X509 *)strcmp((char *)pXVar16,"-timeout");
          if (pXVar15 == (X509 *)0x0) {
            if (*(char **)(iVar10 + 4) == (char *)0x0) goto LAB_000405ea;
            local_130 = strtol(*(char **)(iVar10 + 4),(char **)0x0,10);
            iVar17 = iVar10 + 4;
            if (local_130 < 0) {
              BIO_printf(bio_err,"Illegal timeout value %s\n",*(undefined4 *)(iVar10 + 4));
              pXVar15 = (X509 *)0x1;
            }
          }
          else {
            pXVar15 = (X509 *)strcmp((char *)pXVar16,"-url");
            if (pXVar15 == (X509 *)0x0) {
              if (*(char **)(iVar10 + 4) == (char *)0x0) goto LAB_000405ea;
              iVar17 = OCSP_parse_url(*(char **)(iVar10 + 4),&local_c8,&local_c4,&local_c0,&local_bc
                                     );
              if (iVar17 != 0) goto LAB_000405ae;
              BIO_printf(bio_err,"Error parsing URL\n");
              pXVar15 = (X509 *)0x1;
              iVar17 = iVar10 + 4;
            }
            else {
              pXVar15 = (X509 *)strcmp((char *)pXVar16,"-host");
              if (pXVar15 == (X509 *)0x0) {
                if (*(char **)(iVar10 + 4) == (char *)0x0) goto LAB_000405ea;
                iVar17 = iVar10 + 4;
                local_c8 = *(char **)(iVar10 + 4);
              }
              else {
                pXVar15 = (X509 *)strcmp((char *)pXVar16,"-port");
                if (pXVar15 == (X509 *)0x0) {
                  if (*(char **)(iVar10 + 4) == (char *)0x0) goto LAB_000405ea;
                  iVar17 = iVar10 + 4;
                  local_c4 = *(char **)(iVar10 + 4);
                }
                else {
                  pXVar15 = (X509 *)strcmp((char *)pXVar16,"-header");
                  if (pXVar15 == (X509 *)0x0) {
                    if ((*(char **)(iVar10 + 4) == (char *)0x0) ||
                       (*(char **)(iVar10 + 8) == (char *)0x0)) goto LAB_000405ea;
                    pXVar16 = (X509 *)X509V3_add_value(*(char **)(iVar10 + 4),*(char **)(iVar10 + 8)
                                                       ,(stack_st_CONF_VALUE **)&local_b8);
                    if (pXVar16 == (X509 *)0x0) {
LAB_0004181a:
                      pXVar15 = pXVar16;
                      pXVar20 = (X509 *)0x1;
                      pXVar8 = pXVar16;
                      pXVar5 = pXVar16;
                      issuer = pXVar16;
                      local_188 = pXVar16;
                      local_184 = pXVar16;
                      local_180 = pXVar16;
                      local_17c = pXVar16;
                      local_178 = pXVar16;
                      local_170 = pXVar16;
                      local_168 = pXVar16;
                      local_160 = pXVar16;
                      goto LAB_000403ce;
                    }
                    iVar17 = iVar10 + 8;
                  }
                  else {
                    pXVar15 = (X509 *)strcmp((char *)pXVar16,"-ignore_err");
                    iVar17 = iVar10;
                    if (pXVar15 == (X509 *)0x0) {
                      local_fc = (X509 *)0x1;
                    }
                    else {
                      pXVar15 = (X509 *)strcmp((char *)pXVar16,"-noverify");
                      if (pXVar15 == (X509 *)0x0) {
                        local_e8 = (X509 *)0x1;
                      }
                      else {
                        pXVar15 = (X509 *)strcmp((char *)pXVar16,"-nonce");
                        if (pXVar15 == (X509 *)0x0) {
                          local_180 = (X509 *)0x2;
                        }
                        else {
                          iVar18 = strcmp((char *)pXVar16,"-no_nonce");
                          if (iVar18 == 0) {
                            pXVar15 = (X509 *)0x0;
                            local_180 = (X509 *)0x0;
                          }
                          else {
                            pXVar15 = (X509 *)strcmp((char *)pXVar16,"-resp_no_certs");
                            if (pXVar15 == (X509 *)0x0) {
                              local_100 = (X509 *)((uint)local_100 | 1);
                            }
                            else {
                              pXVar15 = (X509 *)strcmp((char *)pXVar16,"-resp_key_id");
                              if (pXVar15 == (X509 *)0x0) {
                                local_100 = (X509 *)((uint)local_100 | 0x400);
                              }
                              else {
                                pXVar15 = (X509 *)strcmp((char *)pXVar16,"-no_certs");
                                if (pXVar15 == (X509 *)0x0) {
                                  local_11c = (X509 *)0x1;
                                }
                                else {
                                  pXVar15 = (X509 *)strcmp((char *)pXVar16,"-no_signature_verify");
                                  if (pXVar15 == (X509 *)0x0) {
                                    local_f8 = (X509 *)((uint)local_f8 | 4);
                                  }
                                  else {
                                    pXVar15 = (X509 *)strcmp((char *)pXVar16,"-no_cert_verify");
                                    if (pXVar15 == (X509 *)0x0) {
                                      local_f8 = (X509 *)((uint)local_f8 | 0x10);
                                    }
                                    else {
                                      pXVar15 = (X509 *)strcmp((char *)pXVar16,"-no_chain");
                                      if (pXVar15 == (X509 *)0x0) {
                                        local_f8 = (X509 *)((uint)local_f8 | 8);
                                      }
                                      else {
                                        pXVar15 = (X509 *)strcmp((char *)pXVar16,"-no_cert_checks");
                                        if (pXVar15 == (X509 *)0x0) {
                                          local_f8 = (X509 *)((uint)local_f8 | 0x100);
                                        }
                                        else {
                                          pXVar15 = (X509 *)strcmp((char *)pXVar16,"-no_explicit");
                                          if (pXVar15 == (X509 *)0x0) {
                                            local_f8 = (X509 *)((uint)local_f8 | 0x20);
                                          }
                                          else {
                                            pXVar15 = (X509 *)strcmp((char *)pXVar16,"-trust_other")
                                            ;
                                            if (pXVar15 == (X509 *)0x0) {
                                              local_f8 = (X509 *)((uint)local_f8 | 0x200);
                                            }
                                            else {
                                              pXVar15 = (X509 *)strcmp((char *)pXVar16,"-no_intern")
                                              ;
                                              if (pXVar15 == (X509 *)0x0) {
                                                local_f8 = (X509 *)((uint)local_f8 | 2);
                                              }
                                              else {
                                                pXVar15 = (X509 *)strcmp((char *)pXVar16,"-text");
                                                if (pXVar15 == (X509 *)0x0) {
                                                  local_10c = (X509 *)0x1;
                                                  local_128 = (X509 *)0x1;
                                                }
                                                else {
                                                  pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                           "-req_text");
                                                  if (pXVar15 == (X509 *)0x0) {
                                                    local_128 = (X509 *)0x1;
                                                  }
                                                  else {
                                                    pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                             "-resp_text");
                                                    if (pXVar15 == (X509 *)0x0) {
                                                      local_10c = (X509 *)0x1;
                                                    }
                                                    else {
                                                      pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                               "-reqin");
                                                      if (pXVar15 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar10 + 4) != (X509 *)0x0) {
                                                          iVar17 = iVar10 + 4;
                                                          local_174 = *(X509 **)(iVar10 + 4);
                                                          goto LAB_00040516;
                                                        }
                                                      }
                                                      else {
                                                        pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                                 "-respin");
                                                        if (pXVar15 == (X509 *)0x0) {
                                                          if (*(X509 **)(iVar10 + 4) != (X509 *)0x0)
                                                          {
                                                            iVar17 = iVar10 + 4;
                                                            local_f4 = *(X509 **)(iVar10 + 4);
                                                            goto LAB_00040516;
                                                          }
                                                        }
                                                        else {
                                                          pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                                   "-signer");
                                                          if (pXVar15 == (X509 *)0x0) {
                                                            if (*(X509 **)(iVar10 + 4) !=
                                                                (X509 *)0x0) {
                                                              iVar17 = iVar10 + 4;
                                                              local_13c = *(X509 **)(iVar10 + 4);
                                                              goto LAB_00040516;
                                                            }
                                                          }
                                                          else {
                                                            pXVar15 = (X509 *)strcmp((char *)pXVar16
                                                                                     ,"-VAfile");
                                                            if (pXVar15 == (X509 *)0x0) {
                                                              if (*(X509 **)(iVar10 + 4) !=
                                                                  (X509 *)0x0) {
                                                                local_f8 = (X509 *)((uint)local_f8 |
                                                                                   0x200);
                                                                iVar17 = iVar10 + 4;
                                                                local_f0 = *(X509 **)(iVar10 + 4);
                                                                goto LAB_00040516;
                                                              }
                                                            }
                                                            else {
                                                              pXVar15 = (X509 *)strcmp((char *)
                                                  pXVar16,"-sign_other");
                                                  if (pXVar15 == (X509 *)0x0) {
                                                    if (*(X509 **)(iVar10 + 4) != (X509 *)0x0) {
                                                      iVar17 = iVar10 + 4;
                                                      local_134 = *(X509 **)(iVar10 + 4);
                                                      goto LAB_00040516;
                                                    }
                                                  }
                                                  else {
                                                    pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                             "-verify_other");
                                                    if (pXVar15 == (X509 *)0x0) {
                                                      if (*(X509 **)(iVar10 + 4) != (X509 *)0x0) {
                                                        iVar17 = iVar10 + 4;
                                                        local_f0 = *(X509 **)(iVar10 + 4);
                                                        goto LAB_00040516;
                                                      }
                                                    }
                                                    else {
                                                      pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                               "-CAfile");
                                                      if (pXVar15 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar10 + 4) != (X509 *)0x0) {
                                                          iVar17 = iVar10 + 4;
                                                          local_dc = *(X509 **)(iVar10 + 4);
                                                          goto LAB_00040516;
                                                        }
                                                      }
                                                      else {
                                                        pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                                 "-CApath");
                                                        if (pXVar15 == (X509 *)0x0) {
                                                          if (*(X509 **)(iVar10 + 4) != (X509 *)0x0)
                                                          {
                                                            iVar17 = iVar10 + 4;
                                                            local_d8 = *(X509 **)(iVar10 + 4);
                                                            goto LAB_00040516;
                                                          }
                                                        }
                                                        else {
                                                          pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                                                                                                                      
                                                  "-validity_period");
                                                  if (pXVar15 == (X509 *)0x0) {
                                                    if (*(char **)(iVar10 + 4) != (char *)0x0) {
                                                      local_e4 = strtol(*(char **)(iVar10 + 4),
                                                                        (char **)0x0,10);
                                                      if (local_e4 < 0) {
                                                        BIO_printf(bio_err,
                                                  "Illegal validity period %s\n",
                                                  *(undefined4 *)(iVar10 + 4));
                                                  pXVar15 = (X509 *)0x1;
                                                  iVar17 = iVar10 + 4;
                                                  }
                                                  else {
LAB_000405ae:
                                                    iVar17 = iVar10 + 4;
                                                  }
                                                  goto LAB_00040516;
                                                  }
                                                  }
                                                  else {
                                                    pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                             "-status_age");
                                                    if (pXVar15 == (X509 *)0x0) {
                                                      if (*(char **)(iVar10 + 4) != (char *)0x0) {
                                                        local_e0 = strtol(*(char **)(iVar10 + 4),
                                                                          (char **)0x0,10);
                                                        if (-1 < local_e0) goto LAB_000405ae;
                                                        BIO_printf(bio_err,
                                                  "Illegal validity age %s\n",
                                                  *(undefined4 *)(iVar10 + 4));
                                                  pXVar15 = (X509 *)0x1;
                                                  iVar17 = iVar10 + 4;
                                                  goto LAB_00040516;
                                                  }
                                                  }
                                                  else {
                                                    pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                             "-signkey");
                                                    if (pXVar15 == (X509 *)0x0) {
                                                      if (*(X509 **)(iVar10 + 4) != (X509 *)0x0) {
                                                        iVar17 = iVar10 + 4;
                                                        local_15c = *(X509 **)(iVar10 + 4);
                                                        goto LAB_00040516;
                                                      }
                                                    }
                                                    else {
                                                      pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                               "-reqout");
                                                      if (pXVar15 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar10 + 4) != (X509 *)0x0) {
                                                          iVar17 = iVar10 + 4;
                                                          local_120 = *(X509 **)(iVar10 + 4);
                                                          goto LAB_00040516;
                                                        }
                                                      }
                                                      else {
                                                        pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                                 "-respout");
                                                        if (pXVar15 == (X509 *)0x0) {
                                                          if (*(X509 **)(iVar10 + 4) != (X509 *)0x0)
                                                          {
                                                            iVar17 = iVar10 + 4;
                                                            local_138 = *(X509 **)(iVar10 + 4);
                                                            goto LAB_00040516;
                                                          }
                                                        }
                                                        else {
                                                          pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                                   "-path");
                                                          if (pXVar15 == (X509 *)0x0) {
                                                            if (*(char **)(iVar10 + 4) !=
                                                                (char *)0x0) {
                                                              iVar17 = iVar10 + 4;
                                                              local_c0 = *(char **)(iVar10 + 4);
                                                              goto LAB_00040516;
                                                            }
                                                          }
                                                          else {
                                                            iVar18 = strcmp((char *)pXVar16,
                                                                            "-issuer");
                                                            if (iVar18 == 0) {
                                                              if (*(int *)(iVar10 + 4) != 0) {
                                                                X509_free(local_154);
                                                                local_154 = (X509 *)load_cert(
                                                  bio_err,*(undefined4 *)(iVar10 + 4),3,0,0,
                                                  "issuer certificate");
                                                  if (local_154 != (X509 *)0x0) {
LAB_00041c0c:
                                                    pXVar15 = (X509 *)0x0;
                                                    iVar17 = iVar10 + 4;
                                                    goto LAB_00040516;
                                                  }
LAB_00041c9c:
                                                  pXVar16 = (X509 *)0x0;
                                                  goto LAB_0004181a;
                                                  }
                                                  }
                                                  else {
                                                    iVar18 = strcmp((char *)pXVar16,"-cert");
                                                    if (iVar18 == 0) {
                                                      if (*(int *)(iVar10 + 4) != 0) {
                                                        X509_free(local_158);
                                                        local_170 = (X509 *)load_cert(bio_err,*(
                                                  undefined4 *)(iVar10 + 4),3,0,0,"certificate");
                                                  local_158 = local_170;
                                                  if (local_170 != (X509 *)0x0) {
                                                    if (local_178 == (X509 *)0x0) {
                                                      local_178 = (X509 *)EVP_sha1();
                                                    }
                                                    if (local_154 == (X509 *)0x0) {
LAB_00041da0:
                                                      BIO_printf(bio_err,
                                                  "No issuer certificate specified\n");
                                                  goto LAB_00041c9c;
                                                  }
                                                  if ((local_b4 != (X509 *)0x0) ||
                                                     (local_b4 = (X509 *)OCSP_REQUEST_new(),
                                                     local_b4 != (X509 *)0x0)) {
                                                    pOVar19 = OCSP_cert_to_id((EVP_MD *)local_178,
                                                                              local_170,local_154);
joined_r0x00041c7c:
                                                    if (((pOVar19 != (OCSP_CERTID *)0x0) &&
                                                        (iVar17 = sk_push((_STACK *)local_150,
                                                                          pOVar19), iVar17 != 0)) &&
                                                       (pOVar1 = OCSP_request_add0_id
                                                                           ((OCSP_REQUEST *)local_b4
                                                                            ,pOVar19),
                                                       pOVar1 != (OCSP_ONEREQ *)0x0)) {
                                                      pXVar16 = (X509 *)sk_push((_STACK *)local_14c,
                                                                                *(void **)(iVar10 + 
                                                  4));
                                                  if (pXVar16 == (X509 *)0x0) goto LAB_0004181a;
                                                  goto LAB_00041c0c;
                                                  }
                                                  }
LAB_00041c8c:
                                                  BIO_printf(bio_err,"Error Creating OCSP request\n"
                                                            );
                                                  goto LAB_00041c9c;
                                                  }
                                                  goto LAB_000413ba;
                                                  }
                                                  }
                                                  else {
                                                    iVar18 = strcmp((char *)pXVar16,"-serial");
                                                    if (iVar18 != 0) {
                                                      pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                               "-index");
                                                      if (pXVar15 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar10 + 4) == (X509 *)0x0)
                                                        goto LAB_000405ea;
                                                        iVar17 = iVar10 + 4;
                                                        local_104 = *(X509 **)(iVar10 + 4);
                                                      }
                                                      else if (((*(char *)((int)&pXVar16->cert_info
                                                                          + 1) == 'C') &&
                                                               (*(char *)((int)&pXVar16->cert_info +
                                                                         2) == 'A')) &&
                                                              (pXVar15 = (X509 *)(uint)*(byte *)((
                                                  int)&pXVar16->cert_info + 3),
                                                  pXVar15 == (X509 *)0x0)) {
                                                    if (*(X509 **)(iVar10 + 4) == (X509 *)0x0)
                                                    goto LAB_000405ea;
                                                    iVar17 = iVar10 + 4;
                                                    local_17c = *(X509 **)(iVar10 + 4);
                                                  }
                                                  else {
                                                    pXVar8 = (X509 *)strcmp((char *)pXVar16,"-nmin")
                                                    ;
                                                    if (pXVar8 == (X509 *)0x0) {
                                                      pXVar15 = *(X509 **)(iVar10 + 4);
                                                      if (pXVar15 != (X509 *)0x0) {
                                                        local_188 = (X509 *)strtol((char *)pXVar15,
                                                                                   (char **)0x0,10);
                                                        iVar17 = iVar10 + 4;
                                                        pXVar15 = pXVar8;
                                                        if ((int)local_188 < 0) {
                                                          BIO_printf(bio_err,
                                                  "Illegal update period %s\n",
                                                  *(undefined4 *)(iVar10 + 4));
                                                  pXVar15 = (X509 *)0x1;
                                                  }
                                                  }
                                                  iVar10 = iVar17;
                                                  if (local_144 != -1) goto LAB_000405ea;
                                                  local_144 = 0;
                                                  }
                                                  else {
                                                    pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                             "-nrequest");
                                                    if (pXVar15 == (X509 *)0x0) {
                                                      if (*(char **)(iVar10 + 4) == (char *)0x0)
                                                      goto LAB_000405ea;
                                                      local_148 = (X509 *)strtol(*(char **)(iVar10 +
                                                                                           4),
                                                                                 (char **)0x0,10);
                                                      if (-1 < (int)local_148) goto LAB_000405ae;
                                                      BIO_printf(bio_err,"Illegal accept count %s\n"
                                                                 ,*(undefined4 *)(iVar10 + 4));
                                                      pXVar15 = (X509 *)0x1;
                                                      iVar17 = iVar10 + 4;
                                                    }
                                                    else {
                                                      pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                               "-ndays");
                                                      if (pXVar15 == (X509 *)0x0) {
                                                        if (*(char **)(iVar10 + 4) == (char *)0x0)
                                                        goto LAB_000405ea;
                                                        local_144 = strtol(*(char **)(iVar10 + 4),
                                                                           (char **)0x0,10);
                                                        if (-1 < local_144) goto LAB_000405ae;
                                                        BIO_printf(bio_err,
                                                  "Illegal update period %s\n",
                                                  *(undefined4 *)(iVar10 + 4));
                                                  pXVar15 = (X509 *)0x1;
                                                  iVar17 = iVar10 + 4;
                                                  }
                                                  else {
                                                    pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                             "-rsigner");
                                                    if (pXVar15 == (X509 *)0x0) {
                                                      if (*(X509 **)(iVar10 + 4) == (X509 *)0x0)
                                                      goto LAB_000405ea;
                                                      iVar17 = iVar10 + 4;
                                                      issuer = *(X509 **)(iVar10 + 4);
                                                    }
                                                    else {
                                                      pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                               "-rkey");
                                                      if (pXVar15 == (X509 *)0x0) {
                                                        if (*(X509 **)(iVar10 + 4) == (X509 *)0x0)
                                                        goto LAB_000405ea;
                                                        iVar17 = iVar10 + 4;
                                                        local_184 = *(X509 **)(iVar10 + 4);
                                                      }
                                                      else {
                                                        pXVar15 = (X509 *)strcmp((char *)pXVar16,
                                                                                 "-rother");
                                                        if (pXVar15 == (X509 *)0x0) {
                                                          if (*(X509 **)(iVar10 + 4) == (X509 *)0x0)
                                                          goto LAB_000405ea;
                                                          iVar17 = iVar10 + 4;
                                                          local_12c = *(X509 **)(iVar10 + 4);
                                                        }
                                                        else {
                                                          local_178 = (X509 *)EVP_get_digestbyname
                                                                                        ((char *)((
                                                  int)&pXVar16->cert_info + 1));
                                                  uVar11 = count_leading_zeroes(local_178);
                                                  pXVar15 = (X509 *)(uVar11 >> 5);
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_00040516;
                                                  }
                                                  pcVar2 = *(char **)(iVar10 + 4);
                                                  if (pcVar2 != (char *)0x0) {
                                                    if (local_178 == (X509 *)0x0) {
                                                      local_178 = (X509 *)EVP_sha1();
                                                      pcVar2 = *(char **)(iVar10 + 4);
                                                    }
                                                    if (local_154 == (X509 *)0x0) goto LAB_00041da0;
                                                    if ((local_b4 != (X509 *)0x0) ||
                                                       (local_b4 = (X509 *)OCSP_REQUEST_new(),
                                                       local_b4 != (X509 *)0x0)) {
                                                      issuerName = X509_get_subject_name(local_154);
                                                      issuerKey = X509_get0_pubkey_bitstr(local_154)
                                                      ;
                                                      serialNumber = s2i_ASN1_INTEGER((
                                                  X509V3_EXT_METHOD *)0x0,pcVar2);
                                                  if (serialNumber != (ASN1_INTEGER *)0x0) {
                                                    pOVar19 = OCSP_cert_id_new((EVP_MD *)local_178,
                                                                               issuerName,issuerKey,
                                                                               serialNumber);
                                                    ASN1_INTEGER_free(serialNumber);
                                                    goto joined_r0x00041c7c;
                                                  }
                                                  BIO_printf(bio_err,
                                                  "Error converting serial number %s\n",pcVar2);
                                                  goto LAB_00041c9c;
                                                  }
                                                  goto LAB_00041c8c;
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
LAB_000405ea:
                                                  pXVar15 = (X509 *)0x1;
                                                  iVar17 = iVar10;
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
LAB_00040516:
        iVar10 = iVar17 + 4;
        if (pXVar15 != (X509 *)0x0) {
          pXVar15 = (X509 *)0x1;
          goto LAB_0004065a;
        }
        pXVar16 = *(X509 **)(iVar17 + 4);
        if ((pXVar16 == (X509 *)0x0) || (*(char *)&pXVar16->cert_info != '-')) goto LAB_0004065a;
      } while( true );
    }
    local_188 = (X509 *)0x0;
    pXVar15 = (X509 *)0x0;
    local_144 = -1;
    local_148 = (X509 *)0xffffffff;
    local_e0 = -1;
    local_130 = -1;
    local_17c = (X509 *)0x0;
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
    local_184 = (X509 *)0x0;
    local_15c = (X509 *)0x0;
    local_13c = (X509 *)0x0;
    local_138 = (X509 *)0x0;
    local_120 = (X509 *)0x0;
    local_f4 = (X509 *)0x0;
    local_174 = (X509 *)0x0;
    local_e4 = 300;
    local_180 = (X509 *)0x1;
    pXVar20 = (X509 *)0x0;
    issuer = (X509 *)0x0;
  }
LAB_0004065a:
  if ((((local_b4 == (X509 *)0x0) && (local_174 == (X509 *)0x0 && local_f4 == (X509 *)0x0)) &&
      ((local_c4 == (char *)0x0 || (local_104 == (X509 *)0x0)))) || (pXVar15 != (X509 *)0x0)) {
    BIO_printf(bio_err,"OCSP utility\n");
    BIO_printf(bio_err,"Usage ocsp [options]\n");
    BIO_printf(bio_err,"where options are\n");
    BIO_printf(bio_err,"-out file          output filename\n");
    BIO_printf(bio_err,"-issuer file       issuer certificate\n");
    BIO_printf(bio_err,"-cert file         certificate to check\n");
    BIO_printf(bio_err,"-serial n          serial number to check\n");
    BIO_printf(bio_err,"-signer file       certificate to sign OCSP request with\n");
    BIO_printf(bio_err,"-signkey file      private key to sign OCSP request with\n");
    BIO_printf(bio_err,"-sign_other file   additional certificates to include in signed request\n");
    BIO_printf(bio_err,"-no_certs          don\'t include any certificates in signed request\n");
    BIO_printf(bio_err,"-req_text          print text form of request\n");
    BIO_printf(bio_err,"-resp_text         print text form of response\n");
    BIO_printf(bio_err,"-text              print text form of request and response\n");
    BIO_printf(bio_err,"-reqout file       write DER encoded OCSP request to \"file\"\n");
    BIO_printf(bio_err,"-respout file      write DER encoded OCSP reponse to \"file\"\n");
    BIO_printf(bio_err,"-reqin file        read DER encoded OCSP request from \"file\"\n");
    BIO_printf(bio_err,"-respin file       read DER encoded OCSP reponse from \"file\"\n");
    BIO_printf(bio_err,"-nonce             add OCSP nonce to request\n");
    BIO_printf(bio_err,"-no_nonce          don\'t add OCSP nonce to request\n");
    BIO_printf(bio_err,"-url URL           OCSP responder URL\n");
    BIO_printf(bio_err,"-host host:n       send OCSP request to host on port n\n");
    BIO_printf(bio_err,"-path              path to use in OCSP request\n");
    BIO_printf(bio_err,"-CApath dir        trusted certificates directory\n");
    BIO_printf(bio_err,"-CAfile file       trusted certificates file\n");
    BIO_printf(bio_err,"-VAfile file       validator certificates file\n");
    BIO_printf(bio_err,"-validity_period n maximum validity discrepancy in seconds\n");
    BIO_printf(bio_err,"-status_age n      maximum status age in seconds\n");
    BIO_printf(bio_err,"-noverify          don\'t verify response at all\n");
    BIO_printf(bio_err,"-verify_other file additional certificates to search for signer\n");
    BIO_printf(bio_err,"-trust_other       don\'t verify additional certificates\n");
    BIO_printf(bio_err,
               "-no_intern         don\'t search certificates contained in response for signer\n");
    BIO_printf(bio_err,"-no_signature_verify don\'t check signature on response\n");
    BIO_printf(bio_err,"-no_cert_verify    don\'t check signing certificate\n");
    BIO_printf(bio_err,"-no_chain          don\'t chain verify response\n");
    BIO_printf(bio_err,"-no_cert_checks    don\'t do additional checks on signing certificate\n");
    BIO_printf(bio_err,"-port num\t\t port to run responder on\n");
    BIO_printf(bio_err,"-index file\t certificate status index file\n");
    BIO_printf(bio_err,"-CA file\t\t CA certificate\n");
    BIO_printf(bio_err,"-rsigner file\t responder certificate to sign responses with\n");
    BIO_printf(bio_err,"-rkey file\t responder key to sign responses with\n");
    BIO_printf(bio_err,"-rother file\t other certificates to include in response\n");
    BIO_printf(bio_err,"-resp_no_certs     don\'t include any certificates in response\n");
    BIO_printf(bio_err,"-nmin n\t \t number of minutes before next update\n");
    BIO_printf(bio_err,"-ndays n\t \t number of days before next update\n");
    BIO_printf(bio_err,"-resp_key_id       identify reponse by signing certificate key ID\n");
    BIO_printf(bio_err,"-nrequest n        number of requests to accept (default unlimited)\n");
    BIO_printf(bio_err,"-<dgst alg>     use specified digest in the request\n");
    local_17c = (X509 *)0x0;
    local_170 = (X509 *)0x0;
    goto LAB_00041066;
  }
  if (pXVar20 == (X509 *)0x0) {
    local_170 = (X509 *)BIO_new_fp(stdout,0);
  }
  else {
    local_170 = (X509 *)BIO_new_file((char *)pXVar20,"w");
  }
  pcVar2 = local_c4;
  if (local_170 == (X509 *)0x0) {
    BIO_printf(bio_err,"Error opening output file\n");
LAB_000413ba:
    pXVar16 = local_170;
    pXVar15 = local_170;
    pXVar20 = (X509 *)0x1;
    pXVar8 = local_170;
    pXVar5 = local_170;
    issuer = local_170;
    local_188 = local_170;
    local_184 = local_170;
    local_180 = local_170;
    local_17c = local_170;
    local_178 = local_170;
    local_168 = local_170;
    local_160 = local_170;
    goto LAB_000403ce;
  }
  if (local_b4 == (X509 *)0x0) {
    if (local_180 != (X509 *)0x2) {
      local_180 = (X509 *)0x0;
    }
    if (local_174 != (X509 *)0x0) {
      pXVar16 = (X509 *)BIO_new_file((char *)local_174,"rb");
      if (pXVar16 == (X509 *)0x0) {
        BIO_printf(bio_err,"Error Opening OCSP request file\n");
        local_17c = pXVar16;
      }
      else {
        local_b4 = (X509 *)ASN1_d2i_bio(OCSP_REQUEST_new,d2i_OCSP_REQUEST + 1,(BIO *)pXVar16,
                                        (void **)0x0);
        BIO_free((BIO *)pXVar16);
        pXVar16 = local_b4;
        if (local_b4 != (X509 *)0x0) goto LAB_0004068e;
        BIO_printf(bio_err,"Error reading OCSP request\n");
        local_17c = pXVar16;
      }
LAB_00041066:
      pXVar16 = local_17c;
      pXVar15 = local_17c;
      pXVar20 = (X509 *)0x1;
      pXVar8 = local_17c;
      pXVar5 = local_17c;
      issuer = local_17c;
      local_188 = local_17c;
      local_184 = local_17c;
      local_180 = local_17c;
      local_178 = local_17c;
      local_168 = local_17c;
      local_160 = local_17c;
      goto LAB_000403ce;
    }
    if (local_c4 != (char *)0x0) {
      type = BIO_f_buffer();
      pXVar16 = (X509 *)BIO_new(type);
      local_178 = local_174;
      if ((pXVar16 != (X509 *)0x0) &&
         (local_178 = (X509 *)BIO_new_accept(pcVar2), local_178 != (X509 *)0x0)) {
        BIO_ctrl((BIO *)local_178,0x76,2,pXVar16);
        lVar7 = BIO_ctrl((BIO *)local_178,0x65,0,(void *)0x0);
        if (0 < lVar7) goto LAB_00040692;
        BIO_printf(bio_err,"Error setting up accept BIO\n");
        ERR_print_errors(bio_err);
        pXVar16 = local_174;
      }
      BIO_free_all((BIO *)local_178);
      local_178 = (X509 *)0x0;
      BIO_free((BIO *)pXVar16);
      local_188 = (X509 *)0x0;
      local_17c = (X509 *)0x0;
      local_160 = (X509 *)0x0;
      local_180 = (X509 *)0x0;
      local_168 = (X509 *)0x0;
      local_184 = (X509 *)0x0;
      pXVar16 = (X509 *)0x0;
      pXVar15 = (X509 *)0x0;
      pXVar20 = (X509 *)0x1;
      pXVar8 = (X509 *)0x0;
      pXVar5 = (X509 *)0x0;
      issuer = (X509 *)0x0;
      goto LAB_000403ce;
    }
    local_178 = local_174;
  }
  else {
LAB_0004068e:
    local_178 = (X509 *)0x0;
  }
LAB_00040692:
  local_168 = issuer;
  local_160 = issuer;
  pXVar16 = issuer;
  if (issuer != (X509 *)0x0) {
    local_168 = (X509 *)load_cert(bio_err,issuer,3,0,0,"responder certificate");
    if (local_184 == (X509 *)0x0) {
      local_184 = issuer;
    }
    if (local_168 == (X509 *)0x0) {
      BIO_printf(bio_err,"Error loading responder certificate\n");
      pXVar16 = local_168;
      pXVar15 = local_168;
      pXVar20 = (X509 *)0x1;
      pXVar8 = local_168;
      pXVar5 = local_168;
      issuer = local_168;
      local_188 = local_168;
      local_184 = local_168;
      local_180 = local_168;
      local_17c = local_168;
      local_160 = local_168;
      goto LAB_000403ce;
    }
    issuer = (X509 *)load_cert(bio_err,local_17c,3,0,0,"CA certificate");
    if ((local_12c != (X509 *)0x0) &&
       (local_12c = (X509 *)load_certs(bio_err,local_12c,3,0,0,"responder other certificates"),
       local_12c == (X509 *)0x0)) {
      pXVar16 = local_12c;
      pXVar15 = local_12c;
      pXVar20 = (X509 *)0x1;
      pXVar8 = local_12c;
      pXVar5 = local_12c;
      local_188 = local_12c;
      local_184 = local_12c;
      local_180 = local_12c;
      local_17c = local_12c;
      local_160 = local_12c;
      goto LAB_000403ce;
    }
    local_160 = (X509 *)load_key(bio_err,local_184,3,0,0,0,"responder private key");
    pXVar16 = local_12c;
    if (local_160 == (X509 *)0x0) {
      pXVar16 = local_160;
      pXVar15 = local_160;
      pXVar20 = (X509 *)0x1;
      pXVar8 = local_160;
      pXVar5 = local_160;
      local_188 = local_160;
      local_184 = local_160;
      local_180 = local_160;
      local_17c = local_160;
      goto LAB_000403ce;
    }
  }
  local_12c = pXVar16;
  if (local_178 != (X509 *)0x0) {
    BIO_printf(bio_err,"Waiting for OCSP client connections...\n");
  }
  uVar11 = (uint)local_180;
  if (local_180 != (X509 *)0x0) {
    uVar11 = 1;
  }
  pXVar12 = local_104;
  if (local_104 != (X509 *)0x0) {
    pXVar12 = (X509 *)0x1;
  }
  iVar10 = (int)local_188 * 0x3c;
  local_188 = (X509 *)0x0;
  pXVar21 = local_13c;
  if (local_13c != (X509 *)0x0) {
    pXVar21 = (X509 *)0x1;
  }
  pXVar13 = local_120;
  if (local_120 != (X509 *)0x0) {
    pXVar13 = (X509 *)0x1;
  }
  local_17c = (X509 *)0x0;
  local_180 = (X509 *)0x0;
  local_184 = (X509 *)0x0;
  pXVar22 = (X509 *)(uint)(local_160 == (X509 *)0x0 || local_168 == (X509 *)0x0);
  pXVar14 = (X509 *)0x0;
LAB_000407cc:
  pXVar23 = pXVar14;
  if (local_178 == (X509 *)0x0) goto LAB_00040b9c;
LAB_000407d4:
  pXVar16 = (X509 *)do_responder_isra_0(&local_b4,&local_b0,local_178);
  if (pXVar16 != (X509 *)0x0) {
    pXVar23 = pXVar14;
    if (local_b4 == (X509 *)0x0) {
      pXVar5 = (X509 *)OCSP_response_create(1,(OCSP_BASICRESP *)0x0);
      pBVar6 = local_b0;
      memcpy(acStack_80,
             "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
             ,0x51);
      if (pBVar6 == (BIO *)0x0) goto LAB_00040b1e;
      iVar17 = i2d_OCSP_RESPONSE((OCSP_RESPONSE *)pXVar5,(uchar **)0x0);
      BIO_printf(pBVar6,acStack_80,iVar17);
      ASN1_i2d_bio((undefined1 *)0xe12d1,pBVar6,(uchar *)pXVar5);
      BIO_ctrl(pBVar6,0xb,0,(void *)0x0);
      goto LAB_00040b1e;
    }
LAB_000407ec:
    if (uVar11 != 0) {
      OCSP_request_add1_nonce((OCSP_REQUEST *)local_b4,(uchar *)0x0,-1);
    }
LAB_000407f4:
    pXVar5 = pXVar23;
    if (pXVar21 != (X509 *)0x0) {
      local_184 = (X509 *)load_cert(bio_err,local_13c,3,0,0,"signer certificate");
      if (local_15c == (X509 *)0x0) {
        local_15c = local_13c;
      }
      if (local_184 == (X509 *)0x0) {
        BIO_printf(bio_err,"Error loading signer certificate\n");
        pXVar16 = local_184;
        pXVar15 = local_184;
        pXVar20 = (X509 *)0x1;
        pXVar8 = local_184;
      }
      else if (((local_134 == (X509 *)0x0) ||
               (pXVar16 = (X509 *)load_certs(bio_err,local_134,3,0,0,"signer certificates"),
               local_17c = pXVar16, pXVar16 != (X509 *)0x0)) &&
              (pXVar16 = (X509 *)load_key(bio_err,local_15c,3,0,0,0,"signer private key"),
              local_180 = pXVar16, pXVar16 != (X509 *)0x0)) {
        pXVar16 = (X509 *)OCSP_request_sign((OCSP_REQUEST *)local_b4,local_184,(EVP_PKEY *)pXVar16,
                                            (EVP_MD *)0x0,(stack_st_X509 *)local_17c,
                                            (ulong)local_11c);
        if (pXVar16 != (X509 *)0x0) goto LAB_0004089e;
        BIO_printf(bio_err,"Error signing OCSP request\n");
        pXVar15 = pXVar16;
        pXVar20 = (X509 *)0x1;
        pXVar8 = pXVar16;
      }
      else {
LAB_00041314:
        pXVar15 = pXVar16;
        pXVar20 = (X509 *)0x1;
        pXVar8 = pXVar16;
      }
      goto LAB_000403ce;
    }
LAB_0004089e:
    if ((local_128 != (X509 *)0x0) && (local_b4 != (X509 *)0x0)) {
      OCSP_REQUEST_print((BIO *)local_170,(OCSP_REQUEST *)local_b4,0);
    }
    if (pXVar13 != (X509 *)0x0) {
      pXVar16 = (X509 *)BIO_new_file((char *)local_120,"wb");
      pXVar15 = local_120;
      if (pXVar16 != (X509 *)0x0) {
        ASN1_i2d_bio(i2d_OCSP_REQUEST + 1,(BIO *)pXVar16,(uchar *)local_b4);
        BIO_free((BIO *)pXVar16);
        goto LAB_000408de;
      }
LAB_00041428:
      BIO_printf(bio_err,"Error opening file %s\n",pXVar15);
      pXVar15 = pXVar16;
      pXVar20 = (X509 *)0x1;
      pXVar8 = pXVar16;
      goto LAB_000403ce;
    }
LAB_000408de:
    if (pXVar12 == (X509 *)0x0) {
      if (local_188 == (X509 *)0x0) {
        if (local_c8 == (char *)0x0) {
          pXVar16 = local_188;
          pXVar15 = local_188;
          pXVar20 = local_188;
          pXVar8 = local_188;
          if (local_f4 == (X509 *)0x0) goto LAB_000403ce;
          pBVar6 = BIO_new_file((char *)local_f4,"rb");
          if (pBVar6 == (BIO *)0x0) {
            BIO_printf(bio_err,"Error Opening OCSP response file\n");
            pXVar16 = local_188;
            pXVar15 = local_188;
            pXVar20 = (X509 *)0x1;
            pXVar8 = local_188;
            goto LAB_000403ce;
          }
          pXVar5 = (X509 *)ASN1_d2i_bio(OCSP_RESPONSE_new + 1,d2i_OCSP_RESPONSE + 1,pBVar6,
                                        (void **)0x0);
          BIO_free(pBVar6);
          if (pXVar5 == (X509 *)0x0) {
            BIO_printf(bio_err,"Error reading OCSP response\n");
            pXVar16 = pXVar5;
            pXVar15 = pXVar5;
            pXVar20 = (X509 *)0x1;
            pXVar8 = pXVar5;
            goto LAB_000403ce;
          }
        }
        else {
          pXVar5 = (X509 *)process_responder(bio_err,local_b4,local_c8,local_c0,local_c4,local_bc,
                                             local_b8,local_130);
          if (pXVar5 == (X509 *)0x0) {
            pXVar16 = pXVar5;
            pXVar15 = pXVar5;
            pXVar20 = (X509 *)0x1;
            pXVar8 = pXVar5;
            goto LAB_000403ce;
          }
        }
        goto LAB_00040b1e;
      }
    }
    else {
      if ((pXVar22 != (X509 *)0x0) || (issuer == (X509 *)0x0)) {
        pcVar2 = "Need a responder certificate, key and CA for this operation!\n";
        goto LAB_00040bcc;
      }
      if (local_188 == (X509 *)0x0) {
        pXVar16 = (X509 *)load_index(local_104,0);
        local_188 = pXVar16;
        if (pXVar16 == (X509 *)0x0) goto LAB_00041314;
        iVar17 = index_index();
        if (iVar17 != 0) goto LAB_000408fe;
        pXVar16 = pXVar22;
        pXVar15 = pXVar22;
        pXVar20 = (X509 *)0x1;
        pXVar8 = pXVar22;
        goto LAB_000403ce;
      }
    }
LAB_000408fe:
    pXVar16 = local_b4;
    iVar17 = OCSP_request_onereq_count((OCSP_REQUEST *)local_b4);
    if (iVar17 < 1) {
      rsp = (OCSP_BASICRESP *)0x0;
      pXVar5 = (X509 *)OCSP_response_create(1,(OCSP_BASICRESP *)0x0);
      pOVar19 = (OCSP_CERTID *)0x0;
      local_16c = (ASN1_TIME *)0x0;
      local_174 = (X509 *)0x0;
    }
    else {
      rsp = OCSP_BASICRESP_new();
      local_174 = (X509 *)X509_gmtime_adj((ASN1_TIME *)0x0,0);
      if (local_144 == -1) {
        local_16c = (ASN1_TIME *)0x0;
      }
      else {
        local_16c = X509_gmtime_adj((ASN1_TIME *)0x0,local_144 * 0x15180 + iVar10);
      }
      pOVar19 = (OCSP_CERTID *)0x0;
      iVar18 = 0;
      do {
        while( true ) {
          pOVar1 = OCSP_request_onereq_get0((OCSP_REQUEST *)pXVar16,iVar18);
          cid = OCSP_onereq_get0_id(pOVar1);
          OCSP_id_get0_info((ASN1_OCTET_STRING **)0x0,&local_a8,(ASN1_OCTET_STRING **)0x0,
                            (ASN1_INTEGER **)0x0,cid);
          n = OBJ_obj2nid(local_a8);
          pcVar2 = OBJ_nid2sn(n);
          dgst = EVP_get_digestbyname(pcVar2);
          if (dgst == (EVP_MD *)0x0) {
            pXVar5 = (X509 *)OCSP_response_create(2,(OCSP_BASICRESP *)0x0);
            goto LAB_00040ac6;
          }
          if (pOVar19 != (OCSP_CERTID *)0x0) {
            OCSP_CERTID_free(pOVar19);
          }
          pOVar19 = OCSP_cert_to_id(dgst,(X509 *)0x0,issuer);
          pAVar3 = (ASN1_GENERALIZEDTIME *)OCSP_id_issuer_cmp(pOVar19,cid);
          if (pAVar3 == (ASN1_GENERALIZEDTIME *)0x0) break;
          OCSP_basic_add1_status(rsp,cid,2,0,(ASN1_TIME *)0x0,(ASN1_TIME *)local_174,local_16c);
LAB_00040958:
          iVar18 = iVar18 + 1;
          if (iVar18 == iVar17) goto LAB_00040a98;
        }
        OCSP_id_get0_info((ASN1_OCTET_STRING **)0x0,(ASN1_OBJECT **)0x0,(ASN1_OCTET_STRING **)0x0,
                          &local_ac,cid);
        local_98 = pAVar3;
        local_94 = pAVar3;
        local_90 = pAVar3;
        local_8c = pAVar3;
        local_88 = pAVar3;
        local_84 = pAVar3;
        a = ASN1_INTEGER_to_BN(local_ac,(BIGNUM *)0x0);
        if (a == (BIGNUM *)0x0) {
          OpenSSLDie("ocsp.c",0x48d,"bn");
        }
        if (a->top == 0) {
          pcVar2 = BUF_strdup("00");
        }
        else {
          pcVar2 = BN_bn2hex(a);
        }
        local_8c = (ASN1_GENERALIZEDTIME *)pcVar2;
        BN_free(a);
        ppcVar4 = TXT_DB_get_by_index((TXT_DB *)local_188->sig_alg,3,(OPENSSL_STRING *)&local_98);
        CRYPTO_free(pcVar2);
        if (ppcVar4 == (OPENSSL_STRING *)0x0) {
          OCSP_basic_add1_status(rsp,cid,2,0,(ASN1_TIME *)0x0,(ASN1_TIME *)local_174,local_16c);
          goto LAB_00040958;
        }
        if (**ppcVar4 == 'V') {
          OCSP_basic_add1_status(rsp,cid,0,0,(ASN1_TIME *)0x0,(ASN1_TIME *)local_174,local_16c);
          goto LAB_00040958;
        }
        if (**ppcVar4 != 'R') goto LAB_00040958;
        local_a4 = (ASN1_OBJECT *)0x0;
        local_a0 = (ASN1_TIME *)0x0;
        local_9c = (ASN1_GENERALIZEDTIME *)0x0;
        local_98 = (ASN1_GENERALIZEDTIME *)0xffffffff;
        unpack_revinfo(&local_a0,&local_98,&local_a4,&local_9c,ppcVar4[2]);
        x = OCSP_basic_add1_status
                      (rsp,cid,1,(int)local_98,local_a0,(ASN1_TIME *)local_174,local_16c);
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
        iVar18 = iVar18 + 1;
        ASN1_GENERALIZEDTIME_free(local_9c);
      } while (iVar18 != iVar17);
LAB_00040a98:
      OCSP_copy_nonce(rsp,(OCSP_REQUEST *)pXVar16);
      OCSP_basic_sign(rsp,local_168,(EVP_PKEY *)local_160,(EVP_MD *)0x0,(stack_st_X509 *)local_12c,
                      (ulong)local_100);
      pXVar5 = (X509 *)OCSP_response_create(0,rsp);
    }
LAB_00040ac6:
    ASN1_TIME_free((ASN1_TIME *)local_174);
    ASN1_TIME_free(local_16c);
    OCSP_CERTID_free(pOVar19);
    OCSP_BASICRESP_free(rsp);
    pBVar6 = local_b0;
    if (local_b0 != (BIO *)0x0) {
      memcpy(acStack_80,
             "HTTP/1.0 200 OK\r\nContent-type: application/ocsp-response\r\nContent-Length: %d\r\n\r\n"
             ,0x51);
      iVar17 = i2d_OCSP_RESPONSE((OCSP_RESPONSE *)pXVar5,(uchar **)0x0);
      BIO_printf(pBVar6,acStack_80,iVar17);
      ASN1_i2d_bio((undefined1 *)0xe12d1,pBVar6,(uchar *)pXVar5);
      BIO_ctrl(pBVar6,0xb,0,(void *)0x0);
    }
LAB_00040b1e:
    if (local_138 != (X509 *)0x0) {
      pXVar16 = (X509 *)BIO_new_file((char *)local_138,"wb");
      pXVar15 = local_138;
      if (pXVar16 == (X509 *)0x0) goto LAB_00041428;
      ASN1_i2d_bio((undefined1 *)0xe12d1,(BIO *)pXVar16,(uchar *)pXVar5);
      BIO_free((BIO *)pXVar16);
    }
    iVar17 = OCSP_response_status((OCSP_RESPONSE *)pXVar5);
    if (iVar17 != 0) {
      pcVar2 = OCSP_response_status_str(iVar17);
      BIO_printf((BIO *)local_170,"Responder Error: %s (%d)\n",pcVar2,iVar17);
      pXVar16 = local_fc;
      pXVar15 = local_fc;
      pXVar20 = local_fc;
      pXVar8 = local_fc;
      pXVar14 = pXVar5;
      if (local_fc != (X509 *)0x0) goto LAB_000407cc;
      goto LAB_000403ce;
    }
    if (local_10c != (X509 *)0x0) {
      OCSP_RESPONSE_print((BIO *)local_170,(OCSP_RESPONSE *)pXVar5,0);
    }
    if (local_b0 == (BIO *)0x0) {
      pXVar8 = (X509 *)setup_verify(bio_err,local_dc,local_d8);
      if (pXVar8 == (X509 *)0x0) {
        pXVar16 = pXVar8;
        pXVar15 = pXVar8;
        pXVar20 = (X509 *)0x1;
        goto LAB_000403ce;
      }
      if ((local_f0 != (X509 *)0x0) &&
         (local_f0 = (X509 *)load_certs(bio_err,local_f0,3,0,0,"validator certificate"),
         local_f0 == (X509 *)0x0)) {
        pXVar16 = local_f0;
        pXVar15 = local_f0;
        pXVar20 = (X509 *)0x1;
        goto LAB_000403ce;
      }
      pXVar15 = (X509 *)OCSP_response_get1_basic((OCSP_RESPONSE *)pXVar5);
      pXVar16 = local_f0;
      if (pXVar15 == (X509 *)0x0) {
        BIO_printf(bio_err,"Error parsing response\n");
        pXVar20 = (X509 *)0x1;
        goto LAB_000403ce;
      }
      if (local_e8 == (X509 *)0x0) {
        if ((local_b4 != (X509 *)0x0) &&
           (iVar10 = OCSP_check_nonce((OCSP_REQUEST *)local_b4,(OCSP_BASICRESP *)pXVar15),
           iVar10 < 1)) {
          if (iVar10 != -1) {
            BIO_printf(bio_err,"Nonce Verify error\n");
            pXVar20 = (X509 *)0x1;
            goto LAB_000403ce;
          }
          BIO_printf(bio_err,"WARNING: no nonce in response\n");
        }
        iVar10 = OCSP_basic_verify((OCSP_BASICRESP *)pXVar15,(stack_st_X509 *)local_f0,
                                   (X509_STORE *)pXVar8,(ulong)local_f8);
        if (iVar10 < 0) {
          iVar10 = OCSP_basic_verify((OCSP_BASICRESP *)pXVar15,(stack_st_X509 *)0x0,
                                     (X509_STORE *)pXVar8,0);
        }
        if (iVar10 < 1) {
          BIO_printf(bio_err,"Response Verify Failure\n");
          ERR_print_errors(bio_err);
        }
        else {
          BIO_printf(bio_err,"Response verify OK\n");
        }
      }
      if (((local_b4 != (X509 *)0x0) && (iVar10 = sk_num((_STACK *)local_14c), iVar10 != 0)) &&
         (iVar10 = sk_num((_STACK *)local_150), iVar10 != 0)) {
        for (iVar10 = 0; iVar17 = sk_num((_STACK *)local_150), iVar10 < iVar17; iVar10 = iVar10 + 1)
        {
          pOVar19 = (OCSP_CERTID *)sk_value((_STACK *)local_150,iVar10);
          pvVar9 = sk_value((_STACK *)local_14c,iVar10);
          BIO_printf((BIO *)local_170,"%s: ",pvVar9);
          iVar17 = OCSP_resp_find_status
                             ((OCSP_BASICRESP *)pXVar15,pOVar19,(int *)&local_a8,(int *)&local_a4,
                              &local_a0,&local_9c,&local_98);
          if (iVar17 == 0) {
            BIO_puts((BIO *)local_170,"ERROR: No Status found.\n");
          }
          else {
            iVar17 = OCSP_check_validity(local_9c,local_98,local_e4,local_e0);
            if (iVar17 == 0) {
              BIO_puts((BIO *)local_170,"WARNING: Status times invalid.\n");
              ERR_print_errors(local_170);
            }
            pcVar2 = OCSP_cert_status_str((long)local_a8);
            BIO_printf((BIO *)local_170,"%s\n",pcVar2);
            BIO_puts((BIO *)local_170,"\tThis Update: ");
            ASN1_GENERALIZEDTIME_print((BIO *)local_170,local_9c);
            BIO_puts((BIO *)local_170,"\n");
            if (local_98 != (ASN1_GENERALIZEDTIME *)0x0) {
              BIO_puts((BIO *)local_170,"\tNext Update: ");
              ASN1_GENERALIZEDTIME_print((BIO *)local_170,local_98);
              BIO_puts((BIO *)local_170,"\n");
            }
            if (local_a8 == (ASN1_OBJECT *)0x1) {
              if (local_a4 != (ASN1_OBJECT *)0xffffffff) {
                pcVar2 = OCSP_crl_reason_str((long)local_a4);
                BIO_printf((BIO *)local_170,"\tReason: %s\n",pcVar2);
              }
              BIO_puts((BIO *)local_170,"\tRevocation Time: ");
              ASN1_GENERALIZEDTIME_print((BIO *)local_170,local_a0);
              BIO_puts((BIO *)local_170,"\n");
            }
          }
        }
      }
      pXVar20 = (X509 *)0x0;
      goto LAB_000403ce;
    }
    if (0 < (int)local_148) {
      local_148 = (X509 *)((int)&local_148[-1].aux + 3);
    }
    if (local_148 == (X509 *)0x0) {
      pXVar16 = local_148;
      pXVar15 = local_148;
      pXVar20 = (X509 *)0x1;
      pXVar8 = local_148;
      goto LAB_000403ce;
    }
    BIO_free_all(local_b0);
    pXVar14 = (X509 *)0x0;
    local_b0 = (BIO *)0x0;
    OCSP_REQUEST_free((OCSP_REQUEST *)local_b4);
    local_b4 = (X509 *)0x0;
    pXVar23 = (X509 *)0x0;
    OCSP_RESPONSE_free((OCSP_RESPONSE *)pXVar5);
    if (local_178 != (X509 *)0x0) goto LAB_000407d4;
LAB_00040b9c:
    if (local_b4 == (X509 *)0x0) goto code_r0x00040ba4;
    goto LAB_000407ec;
  }
  pXVar15 = pXVar16;
  pXVar20 = (X509 *)0x1;
  pXVar8 = pXVar16;
  pXVar5 = pXVar14;
LAB_000403ce:
  ERR_print_errors(bio_err);
  X509_free(local_184);
  X509_STORE_free((X509_STORE *)pXVar8);
  EVP_PKEY_free((EVP_PKEY *)local_180);
  EVP_PKEY_free((EVP_PKEY *)local_160);
  X509_free(local_154);
  X509_free(local_158);
  X509_free(local_168);
  X509_free(issuer);
  free_index(local_188);
  BIO_free_all(local_b0);
  BIO_free_all((BIO *)local_178);
  BIO_free((BIO *)local_170);
  OCSP_REQUEST_free((OCSP_REQUEST *)local_b4);
  OCSP_RESPONSE_free((OCSP_RESPONSE *)pXVar5);
  OCSP_BASICRESP_free((OCSP_BASICRESP *)pXVar15);
  sk_free((_STACK *)local_14c);
  sk_free((_STACK *)local_150);
  sk_pop_free((_STACK *)local_17c,X509_free);
  sk_pop_free((_STACK *)pXVar16,X509_free);
  sk_pop_free(local_b8,X509V3_conf_free + 1);
  if (local_bc != -1) {
    CRYPTO_free(local_c8);
    CRYPTO_free(local_c4);
    CRYPTO_free(local_c0);
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(pXVar20);
code_r0x00040ba4:
  if (((((uint)pXVar13 | (uint)pXVar21) != 0) || (local_c8 != (char *)0x0)) ||
     ((uVar11 | (uint)pXVar12) != 0)) {
    pcVar2 = "Need an OCSP request for this operation!\n";
LAB_00040bcc:
    BIO_printf(bio_err,pcVar2);
    pXVar16 = (X509 *)0x0;
    pXVar15 = (X509 *)0x0;
    pXVar20 = (X509 *)0x1;
    pXVar8 = (X509 *)0x0;
    pXVar5 = pXVar23;
    goto LAB_000403ce;
  }
  goto LAB_000407f4;
}

