
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void ts_main(int param_1,int param_2)

{
  bool bVar1;
  CONF *conf;
  int iVar2;
  BIO_METHOD *pBVar3;
  undefined4 uVar4;
  PKCS7 *a;
  BIO *pBVar5;
  BIO *pBVar6;
  X509_STORE *ctx;
  X509_LOOKUP_METHOD *pXVar7;
  X509_LOOKUP *pXVar8;
  PKCS7 *pPVar9;
  int iVar10;
  ASN1_OBJECT *pAVar11;
  uchar *puVar12;
  ASN1_OBJECT *pAVar13;
  ASN1_OBJECT *pAVar14;
  void *pvVar15;
  BIO *pBVar16;
  char **ppcVar17;
  uint uVar18;
  char *pcVar19;
  ASN1_OBJECT *a_00;
  char *pcVar20;
  BIO *pBVar21;
  char *pcVar22;
  PKCS7 *pPVar23;
  char *pcVar24;
  BIO *local_a0;
  BIO *local_9c;
  char *local_98;
  char *local_94;
  char *local_90;
  uint local_8c;
  BIO *local_88;
  char *local_84;
  BIO *local_80;
  ASN1_OBJECT *local_7c;
  PKCS7 *local_78;
  EVP_MD *local_74;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_60;
  undefined4 local_5c;
  char *local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  void *local_48;
  void *local_44;
  uchar local_40 [4];
  char local_3c;
  char local_3b;
  char local_3a;
  char local_39;
  int local_2c;
  
  local_2c = __TMC_END__;
  local_48 = (void *)0x0;
  ERR_load_crypto_strings();
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar3 = BIO_s_file();
    bio_err = BIO_new(pBVar3);
    local_a0 = bio_err;
    if (bio_err != (BIO *)0x0) {
      local_a0 = (BIO *)0x1;
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  else {
    local_a0 = (BIO *)0x0;
  }
  conf = (CONF *)load_config(bio_err,0);
  if (conf == (CONF *)0x0) {
    uVar18 = 1;
    goto LAB_00042616;
  }
  param_1 = param_1 + -1;
  ppcVar17 = (char **)(param_2 + 4);
  pcVar20 = (char *)0x0;
  if (0 < param_1) {
    local_78 = (PKCS7 *)0x0;
    pcVar24 = (char *)0x0;
    local_4c = (char *)0x0;
    pcVar22 = (char *)0x0;
    local_60 = (char *)0x0;
    local_68 = (char *)0x0;
    local_6c = (char *)0x0;
    local_50 = (char *)0x0;
    local_54 = (char *)0x0;
    local_58 = (char *)0x0;
    local_94 = (char *)0x0;
    local_88 = (BIO *)0x0;
    bVar1 = false;
    local_70 = (char *)0x0;
    local_80 = (BIO *)0x0;
    local_5c = 0;
    local_8c = 0;
    local_7c = (ASN1_OBJECT *)0x0;
    local_90 = (char *)0x0;
    local_74 = (EVP_MD *)0x0;
    local_98 = (char *)0x0;
    local_9c = (BIO *)0x0;
    local_84 = (char *)0x0;
LAB_0004258a:
    pcVar19 = *ppcVar17;
    iVar2 = strcmp(pcVar19,"-config");
    if (iVar2 == 0) {
      pcVar22 = ppcVar17[1];
      param_1 = param_1 + -1;
      ppcVar17 = ppcVar17 + 1;
    }
    else {
      iVar2 = strcmp(pcVar19,"-section");
      if (iVar2 == 0) {
        param_1 = param_1 + -2;
        pcVar24 = ppcVar17[1];
        ppcVar17 = ppcVar17 + 2;
        goto joined_r0x000425c6;
      }
      iVar2 = strcmp(pcVar19,"-query");
      if (iVar2 == 0) {
        if (pcVar20 != (char *)0x0) goto switchD_00042606_caseD_0;
        pcVar20 = (char *)0x1;
      }
      else {
        iVar2 = strcmp(pcVar19,"-data");
        if (iVar2 == 0) {
          local_9c = (BIO *)ppcVar17[1];
          param_1 = param_1 + -1;
          ppcVar17 = ppcVar17 + 1;
        }
        else {
          iVar2 = strcmp(pcVar19,"-digest");
          if (iVar2 == 0) {
            local_98 = ppcVar17[1];
            param_1 = param_1 + -1;
            ppcVar17 = ppcVar17 + 1;
          }
          else {
            iVar2 = strcmp(pcVar19,"-rand");
            if (iVar2 == 0) {
              local_90 = ppcVar17[1];
              param_1 = param_1 + -1;
              ppcVar17 = ppcVar17 + 1;
            }
            else {
              iVar2 = strcmp(pcVar19,"-policy");
              if (iVar2 == 0) {
                local_7c = (ASN1_OBJECT *)ppcVar17[1];
                param_1 = param_1 + -1;
                ppcVar17 = ppcVar17 + 1;
              }
              else {
                iVar2 = strcmp(pcVar19,"-no_nonce");
                if (iVar2 == 0) {
                  local_8c = 1;
                }
                else {
                  iVar2 = strcmp(pcVar19,"-cert");
                  if (iVar2 == 0) {
                    local_5c = 1;
                  }
                  else {
                    if ((((*pcVar19 == '-') && (pcVar19[1] == 'i')) && (pcVar19[2] == 'n')) &&
                       (pcVar19[3] == '\0')) {
                      local_80 = (BIO *)ppcVar17[1];
                      param_1 = param_1 + -1;
                      ppcVar17 = ppcVar17 + 1;
                      goto LAB_0004257e;
                    }
                    iVar2 = strcmp(pcVar19,"-token_in");
                    if (iVar2 == 0) {
                      local_78 = (PKCS7 *)0x1;
                    }
                    else {
                      iVar2 = strcmp(pcVar19,"-out");
                      if (iVar2 == 0) {
                        local_70 = ppcVar17[1];
                        param_1 = param_1 + -1;
                        ppcVar17 = ppcVar17 + 1;
                      }
                      else {
                        iVar2 = strcmp(pcVar19,"-token_out");
                        if (iVar2 == 0) {
                          local_84 = (char *)0x1;
                        }
                        else {
                          iVar2 = strcmp(pcVar19,"-text");
                          if (iVar2 == 0) {
                            bVar1 = true;
                          }
                          else {
                            iVar2 = strcmp(pcVar19,"-reply");
                            if (iVar2 == 0) {
                              if (pcVar20 != (char *)0x0) goto switchD_00042606_caseD_0;
                              pcVar20 = (char *)0x2;
                            }
                            else {
                              iVar2 = strcmp(pcVar19,"-queryfile");
                              if (iVar2 == 0) {
                                local_88 = (BIO *)ppcVar17[1];
                                param_1 = param_1 + -1;
                                ppcVar17 = ppcVar17 + 1;
                              }
                              else {
                                iVar2 = strcmp(pcVar19,"-passin");
                                if (iVar2 == 0) {
                                  local_94 = ppcVar17[1];
                                  param_1 = param_1 + -1;
                                  ppcVar17 = ppcVar17 + 1;
                                }
                                else {
                                  iVar2 = strcmp(pcVar19,"-inkey");
                                  if (iVar2 == 0) {
                                    local_58 = ppcVar17[1];
                                    param_1 = param_1 + -1;
                                    ppcVar17 = ppcVar17 + 1;
                                  }
                                  else {
                                    iVar2 = strcmp(pcVar19,"-signer");
                                    if (iVar2 == 0) {
                                      local_54 = ppcVar17[1];
                                      param_1 = param_1 + -1;
                                      ppcVar17 = ppcVar17 + 1;
                                    }
                                    else {
                                      iVar2 = strcmp(pcVar19,"-chain");
                                      if (iVar2 == 0) {
                                        local_50 = ppcVar17[1];
                                        param_1 = param_1 + -1;
                                        ppcVar17 = ppcVar17 + 1;
                                      }
                                      else {
                                        iVar2 = strcmp(pcVar19,"-verify");
                                        if (iVar2 == 0) {
                                          if (pcVar20 != (char *)0x0) goto switchD_00042606_caseD_0;
                                          pcVar20 = (char *)0x3;
                                        }
                                        else {
                                          iVar2 = strcmp(pcVar19,"-CApath");
                                          if (iVar2 == 0) {
                                            local_6c = ppcVar17[1];
                                            param_1 = param_1 + -1;
                                            ppcVar17 = ppcVar17 + 1;
                                          }
                                          else {
                                            iVar2 = strcmp(pcVar19,"-CAfile");
                                            if (iVar2 == 0) {
                                              local_68 = ppcVar17[1];
                                              param_1 = param_1 + -1;
                                              ppcVar17 = ppcVar17 + 1;
                                            }
                                            else {
                                              iVar2 = strcmp(pcVar19,"-untrusted");
                                              if (iVar2 == 0) {
                                                local_60 = ppcVar17[1];
                                                param_1 = param_1 + -1;
                                                ppcVar17 = ppcVar17 + 1;
                                              }
                                              else {
                                                iVar2 = strcmp(pcVar19,"-engine");
                                                if (iVar2 == 0) {
                                                  local_4c = ppcVar17[1];
                                                  param_1 = param_1 + -1;
                                                  ppcVar17 = ppcVar17 + 1;
                                                }
                                                else {
                                                  local_74 = EVP_get_digestbyname(pcVar19 + 1);
                                                  if (local_74 == (EVP_MD *)0x0)
                                                  goto switchD_00042606_caseD_0;
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
LAB_0004257e:
    param_1 = param_1 + -1;
    ppcVar17 = ppcVar17 + 1;
joined_r0x000425c6:
    if (param_1 < 1) goto LAB_000425c8;
    goto LAB_0004258a;
  }
  a_00 = (ASN1_OBJECT *)0x1;
  local_78 = (PKCS7 *)0x0;
  local_4c = (char *)0x0;
  pcVar19 = (char *)0x0;
  local_60 = (char *)0x0;
  local_68 = (char *)0x0;
  local_6c = (char *)0x0;
  local_50 = (char *)0x0;
  local_54 = (char *)0x0;
  local_58 = (char *)0x0;
  local_88 = (BIO *)0x0;
  bVar1 = false;
  local_70 = (char *)0x0;
  local_80 = (BIO *)0x0;
  local_5c = 0;
  local_7c = (ASN1_OBJECT *)0x0;
  local_74 = (EVP_MD *)0x0;
  local_98 = (char *)0x0;
  local_9c = (BIO *)0x0;
  local_84 = pcVar20;
  pcVar22 = pcVar20;
  pcVar24 = pcVar20;
  goto LAB_000425fe;
LAB_000425c8:
  uVar18 = count_leading_zeroes(pcVar20 + -2);
  a_00 = (ASN1_OBJECT *)(local_8c ^ 1);
  uVar18 = uVar18 >> 5;
  if (local_94 == (char *)0x0) {
    uVar18 = 0;
  }
  pAVar13 = a_00;
  if (pcVar20 != (char *)0x1) {
    pAVar13 = (ASN1_OBJECT *)0x0;
  }
  if (pAVar13 != (ASN1_OBJECT *)0x0) {
    iVar2 = app_RAND_load_file(0,bio_err);
    pBVar21 = bio_err;
    if (iVar2 == 0) {
      if (local_90 == (char *)0x0) {
        BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n")
        ;
      }
      else {
LAB_00042ba8:
        app_RAND_load_files(local_90);
        BIO_printf(pBVar21,"%ld semi-random bytes loaded\n");
      }
    }
    else if (local_90 != (char *)0x0) goto LAB_00042ba8;
  }
  pcVar19 = pcVar20;
  if ((uVar18 != 0) &&
     (conf = (CONF *)app_passwd(bio_err,local_94,0,&local_48,0), conf == (CONF *)0x0)) {
    uVar18 = 1;
    BIO_printf(bio_err,"Error getting password.\n");
    goto LAB_00042616;
  }
LAB_000425fe:
  switch(pcVar19) {
  case (char *)0x0:
    break;
  case (char *)0x1:
    if (local_98 == (char *)0x0 || local_9c == (BIO *)0x0) {
      conf = (CONF *)load_config_file(pcVar22);
      if (local_80 == (BIO *)0x0) {
        if (local_98 == (char *)0x0) {
          if (local_9c == (BIO *)0x0) {
            local_80 = BIO_new_fp(stdin,0);
          }
          else {
            local_80 = BIO_new_file((char *)local_9c,"rb");
          }
          if (local_80 == (BIO *)0x0) goto LAB_00042e42;
        }
        local_44 = (void *)0x0;
        if (((local_74 == (EVP_MD *)0x0) &&
            (local_74 = EVP_get_digestbyname("sha1"), local_74 == (EVP_MD *)0x0)) ||
           (pBVar21 = (BIO *)TS_REQ_new(), pBVar21 == (BIO *)0x0)) {
          local_9c = (BIO *)0x0;
          pAVar11 = (ASN1_OBJECT *)0x0;
          pBVar21 = (BIO *)0x0;
          pAVar13 = (ASN1_OBJECT *)0x0;
          pAVar14 = (ASN1_OBJECT *)0x0;
LAB_00042da6:
          TS_REQ_free(pBVar21);
          BIO_printf(bio_err,"could not create query\n");
          a_00 = pAVar13;
          pBVar21 = (BIO *)0x0;
          local_7c = pAVar14;
        }
        else {
          pAVar11 = (ASN1_OBJECT *)TS_REQ_set_version(pBVar21,1);
          pAVar13 = pAVar11;
          pAVar14 = pAVar11;
          local_9c = (BIO *)pAVar11;
          if (((pAVar11 == (ASN1_OBJECT *)0x0) ||
              (pAVar11 = (ASN1_OBJECT *)TS_MSG_IMPRINT_new(), pAVar13 = pAVar11, pAVar14 = pAVar11,
              local_9c = (BIO *)pAVar11, pAVar11 == (ASN1_OBJECT *)0x0)) ||
             (local_9c = (BIO *)X509_ALGOR_new(), pAVar13 = (ASN1_OBJECT *)local_9c,
             pAVar14 = (ASN1_OBJECT *)local_9c, local_9c == (BIO *)0x0)) goto LAB_00042da6;
          iVar2 = EVP_MD_type(local_74);
          pAVar13 = OBJ_nid2obj(iVar2);
          ((ASN1_OBJECT *)local_9c)->sn = (char *)pAVar13;
          pAVar14 = pAVar13;
          if (pAVar13 == (ASN1_OBJECT *)0x0) goto LAB_00042da6;
          pAVar13 = (ASN1_OBJECT *)ASN1_TYPE_new();
          ((ASN1_OBJECT *)local_9c)->ln = (char **)pAVar13;
          pAVar14 = pAVar13;
          if (pAVar13 == (ASN1_OBJECT *)0x0) goto LAB_00042da6;
          pAVar13->sn = (char *)0x5;
          pAVar13 = (ASN1_OBJECT *)TS_MSG_IMPRINT_set_algo(pAVar11,local_9c);
          pAVar14 = pAVar13;
          if (((pAVar13 == (ASN1_OBJECT *)0x0) ||
              (pAVar13 = (ASN1_OBJECT *)create_digest(local_80,local_98,local_74,&local_44),
              pAVar14 = pAVar13, pAVar13 == (ASN1_OBJECT *)0x0)) ||
             (pAVar13 = (ASN1_OBJECT *)TS_MSG_IMPRINT_set_msg(pAVar11,local_44,pAVar13),
             pAVar14 = pAVar13, pAVar13 == (ASN1_OBJECT *)0x0)) goto LAB_00042da6;
          iVar2 = TS_REQ_set_msg_imprint(pBVar21,pAVar11);
          if (iVar2 == 0) {
            pAVar13 = (ASN1_OBJECT *)0x0;
            pAVar14 = (ASN1_OBJECT *)0x0;
            goto LAB_00042da6;
          }
          if (local_7c != (ASN1_OBJECT *)0x0) {
            pAVar14 = OBJ_txt2obj((char *)local_7c,0);
            if (pAVar14 == (ASN1_OBJECT *)0x0) {
              BIO_printf(bio_err,"cannot convert %s to OID\n",local_7c);
              pAVar13 = pAVar14;
            }
            else {
              pAVar13 = (ASN1_OBJECT *)TS_REQ_set_policy_id(pBVar21,pAVar14);
              local_7c = pAVar14;
              if (pAVar13 != (ASN1_OBJECT *)0x0) goto LAB_00043052;
            }
            goto LAB_00042da6;
          }
LAB_00043052:
          pAVar14 = local_7c;
          if (a_00 != (ASN1_OBJECT *)0x0) {
            iVar2 = RAND_bytes(local_40,8);
            if (iVar2 < 1) {
LAB_00043320:
              a_00 = (ASN1_OBJECT *)0x0;
            }
            else {
              if (local_40[0] == '\0') {
                if (local_40[1] == '\0') {
                  if (local_40[2] == '\0') {
                    if (local_40[3] == '\0') {
                      if (local_3c == '\0') {
                        if (local_3b == '\0') {
                          if (local_3a == '\0') {
                            if (local_39 == '\0') {
                              iVar2 = 8;
                            }
                            else {
                              iVar2 = 7;
                            }
                          }
                          else {
                            iVar2 = 6;
                          }
                        }
                        else {
                          iVar2 = 5;
                        }
                      }
                      else {
                        iVar2 = 4;
                      }
                    }
                    else {
                      iVar2 = 3;
                    }
                  }
                  else {
                    iVar2 = 2;
                  }
                }
                else {
                  iVar2 = 1;
                }
              }
              else {
                iVar2 = 0;
              }
              a_00 = (ASN1_OBJECT *)ASN1_INTEGER_new();
              if (a_00 == (ASN1_OBJECT *)0x0) goto LAB_00043320;
              CRYPTO_free((void *)a_00->nid);
              a_00->sn = (char *)(8 - iVar2);
              pvVar15 = CRYPTO_malloc(9 - iVar2,"ts.c",0x294);
              a_00->nid = (int)pvVar15;
              if (pvVar15 != (void *)0x0) {
                memcpy(pvVar15,local_40 + iVar2,(size_t)a_00->sn);
                iVar2 = TS_REQ_set_nonce(pBVar21,a_00);
                pAVar13 = a_00;
                if (iVar2 == 0) goto LAB_00042da6;
                goto LAB_00043056;
              }
            }
            BIO_printf(bio_err,"could not create nonce\n");
            ASN1_INTEGER_free((ASN1_INTEGER *)a_00);
            pAVar13 = (ASN1_OBJECT *)0x0;
            goto LAB_00042da6;
          }
LAB_00043056:
          iVar2 = TS_REQ_set_cert_req(pBVar21,local_5c);
          pAVar13 = a_00;
          if (iVar2 == 0) goto LAB_00042da6;
        }
        pBVar16 = (BIO *)0x0;
        TS_MSG_IMPRINT_free(pAVar11);
        X509_ALGOR_free((X509_ALGOR *)local_9c);
        CRYPTO_free(local_44);
        ASN1_OBJECT_free(local_7c);
        ASN1_INTEGER_free((ASN1_INTEGER *)a_00);
LAB_0004287c:
        if (pBVar21 == (BIO *)0x0) {
          uVar18 = 1;
          pBVar5 = pBVar21;
        }
        else {
          if (local_70 == (char *)0x0) {
            pBVar5 = BIO_new_fp(stdout,0);
          }
          else {
            pBVar5 = BIO_new_file(local_70,"wb");
          }
          if (pBVar5 == (BIO *)0x0) {
            uVar18 = 1;
          }
          else if (bVar1) {
            uVar4 = TS_REQ_print_bio();
            uVar18 = count_leading_zeroes(uVar4);
            uVar18 = uVar18 >> 5;
          }
          else {
            uVar4 = i2d_TS_REQ_bio(pBVar5,pBVar21);
            uVar18 = count_leading_zeroes(uVar4);
            uVar18 = uVar18 >> 5;
          }
        }
      }
      else {
        pBVar16 = BIO_new_file((char *)local_80,"rb");
        if (pBVar16 != (BIO *)0x0) {
          local_80 = (BIO *)0x0;
          pBVar21 = (BIO *)d2i_TS_REQ_bio(pBVar16,0);
          goto LAB_0004287c;
        }
LAB_00042e42:
        pBVar5 = (BIO *)0x0;
        uVar18 = 1;
        local_80 = (BIO *)0x0;
        pBVar21 = pBVar5;
        pBVar16 = pBVar5;
      }
      ERR_print_errors(bio_err);
      BIO_free_all(pBVar16);
      BIO_free_all(local_80);
      BIO_free_all(pBVar5);
      TS_REQ_free(pBVar21);
      goto LAB_00042616;
    }
    break;
  case (char *)0x2:
    conf = (CONF *)load_config_file(pcVar22);
    pvVar15 = local_48;
    if (local_80 == (BIO *)0x0) {
      if ((conf != (CONF *)0x0 && local_88 != (BIO *)0x0) && (local_78 == (PKCS7 *)0x0)) {
        pBVar21 = BIO_new_file((char *)local_88,"rb");
        if (pBVar21 != (BIO *)0x0) {
          iVar2 = TS_CONF_get_tsa_section(conf,pcVar24);
          if ((iVar2 == 0) || (local_78 = (PKCS7 *)TS_RESP_CTX_new(), local_78 == (PKCS7 *)0x0)) {
            local_78 = (PKCS7 *)0x0;
          }
          else {
            iVar10 = TS_CONF_set_serial(conf,iVar2,0x42471,local_78);
            if ((((((iVar10 != 0) &&
                   (iVar10 = TS_CONF_set_crypto_device(conf,iVar2,local_4c), iVar10 != 0)) &&
                  (iVar10 = TS_CONF_set_signer_cert(conf,iVar2,local_54,local_78), iVar10 != 0)) &&
                 (((iVar10 = TS_CONF_set_certs(conf,iVar2,local_50,local_78), iVar10 != 0 &&
                   (iVar10 = TS_CONF_set_signer_key(conf,iVar2,local_58,pvVar15,local_78),
                   iVar10 != 0)) &&
                  ((iVar10 = TS_CONF_set_def_policy(conf,iVar2,local_7c,local_78), iVar10 != 0 &&
                   ((iVar10 = TS_CONF_set_policies(conf,iVar2,local_78), iVar10 != 0 &&
                    (iVar10 = TS_CONF_set_digests(conf,iVar2,local_78), iVar10 != 0)))))))) &&
                (iVar10 = TS_CONF_set_accuracy(conf,iVar2,local_78), iVar10 != 0)) &&
               ((((iVar10 = TS_CONF_set_clock_precision_digits(conf,iVar2,local_78), iVar10 != 0 &&
                  (iVar10 = TS_CONF_set_ordering(conf,iVar2,local_78), iVar10 != 0)) &&
                 (iVar10 = TS_CONF_set_tsa_name(conf,iVar2,local_78), iVar10 != 0)) &&
                ((iVar2 = TS_CONF_set_ess_cert_id_chain(conf,iVar2,local_78), iVar2 != 0 &&
                 (pBVar16 = (BIO *)TS_RESP_create_response(local_78,pBVar21), pBVar16 != (BIO *)0x0)
                 ))))) {
              pBVar5 = (BIO *)0x0;
              TS_RESP_CTX_free(local_78);
              BIO_free_all(pBVar21);
              BIO_printf(bio_err,"Response has been generated.\n");
              goto LAB_0004297c;
            }
          }
        }
        pBVar6 = (BIO *)0x0;
        TS_RESP_free();
        pBVar16 = (BIO *)0x0;
        TS_RESP_CTX_free(local_78);
        BIO_free_all(pBVar21);
        BIO_printf(bio_err,"Response is not generated.\n");
        pBVar5 = (BIO *)0x0;
LAB_00042d3a:
        uVar18 = 1;
        local_88 = pBVar16;
        pBVar16 = pBVar6;
        goto LAB_000429c6;
      }
    }
    else if (local_88 == (BIO *)0x0) {
      pBVar5 = BIO_new_file((char *)local_80,"rb");
      if (pBVar5 == (BIO *)0x0) {
        uVar18 = 1;
        pBVar16 = local_88;
      }
      else {
        if (local_78 == (PKCS7 *)0x0) {
          pBVar16 = (BIO *)d2i_TS_RESP_bio();
        }
        else {
          pPVar23 = d2i_PKCS7_bio(pBVar5,(PKCS7 **)0x0);
          pBVar16 = local_88;
          pBVar21 = local_88;
          if (((pPVar23 == (PKCS7 *)0x0) ||
              (pBVar21 = (BIO *)PKCS7_to_TS_TST_INFO(), pBVar21 == (BIO *)0x0)) ||
             ((pBVar16 = (BIO *)TS_RESP_new(), pBVar16 == (BIO *)0x0 ||
              (((local_88 = (BIO *)TS_STATUS_INFO_new(), local_88 == (BIO *)0x0 ||
                (iVar2 = ASN1_INTEGER_set((ASN1_INTEGER *)local_88->method,0), iVar2 == 0)) ||
               (iVar2 = TS_RESP_set_status_info(pBVar16,local_88), iVar2 == 0)))))) {
            PKCS7_free(pPVar23);
            TS_TST_INFO_free(pBVar21);
            TS_RESP_free(pBVar16);
            pBVar16 = (BIO *)0x0;
          }
          else {
            TS_RESP_set_tst_info(pBVar16,pPVar23,pBVar21);
            PKCS7_free((PKCS7 *)0x0);
            TS_TST_INFO_free(0);
          }
          TS_STATUS_INFO_free(local_88);
        }
        if (pBVar16 == (BIO *)0x0) {
          uVar18 = 1;
          local_88 = pBVar16;
        }
        else {
LAB_0004297c:
          if (local_70 == (char *)0x0) {
            pBVar6 = BIO_new_fp(stdout,0);
          }
          else {
            pBVar6 = BIO_new_file(local_70,"wb");
          }
          if (pBVar6 == (BIO *)0x0) goto LAB_00042d3a;
          local_88 = pBVar16;
          if (bVar1) {
            if (local_84 == (char *)0x0) {
              uVar4 = TS_RESP_print_bio(pBVar6,pBVar16);
              uVar18 = count_leading_zeroes(uVar4);
              uVar18 = uVar18 >> 5;
              pBVar16 = pBVar6;
            }
            else {
              uVar4 = TS_RESP_get_tst_info(pBVar16);
              uVar4 = TS_TST_INFO_print_bio(pBVar6,uVar4);
              uVar18 = count_leading_zeroes(uVar4);
              uVar18 = uVar18 >> 5;
              pBVar16 = pBVar6;
            }
          }
          else if (local_84 == (char *)0x0) {
            uVar4 = i2d_TS_RESP_bio(pBVar6,pBVar16);
            uVar18 = count_leading_zeroes(uVar4);
            uVar18 = uVar18 >> 5;
            pBVar16 = pBVar6;
          }
          else {
            pPVar23 = (PKCS7 *)TS_RESP_get_token(pBVar16);
            iVar2 = i2d_PKCS7_bio(pBVar6,pPVar23);
            uVar18 = count_leading_zeroes(iVar2);
            uVar18 = uVar18 >> 5;
            pBVar16 = pBVar6;
          }
        }
      }
LAB_000429c6:
      ERR_print_errors(bio_err);
      BIO_free_all(pBVar5);
      BIO_free_all((BIO *)0x0);
      BIO_free_all((BIO *)0x0);
      BIO_free_all((BIO *)0x0);
      BIO_free_all(pBVar16);
      TS_RESP_free(local_88);
      goto LAB_00042616;
    }
    goto LAB_0004277a;
  case (char *)0x3:
    pBVar21 = local_9c;
    if (local_9c != (BIO *)0x0) {
      pBVar21 = (BIO *)0x1;
    }
    pBVar16 = pBVar21;
    if (local_88 == (BIO *)0x0) {
      pBVar16 = (BIO *)((uint)pBVar21 | 1);
    }
    if (pBVar16 == (BIO *)0x0) {
LAB_00042a22:
      if (local_98 != (char *)0x0) {
        pBVar16 = pBVar21;
        if (local_88 != (BIO *)0x0) {
          pBVar16 = (BIO *)((uint)pBVar21 | 1);
        }
        if (pBVar16 != (BIO *)0x0) break;
      }
    }
    else {
      pBVar16 = local_88;
      if (local_88 != (BIO *)0x0) {
        pBVar16 = (BIO *)0x1;
      }
      pBVar5 = pBVar16;
      if (local_9c == (BIO *)0x0) {
        pBVar5 = (BIO *)((uint)pBVar16 | 1);
      }
      if (pBVar5 == (BIO *)0x0) goto LAB_00042a22;
      if ((((uint)pBVar16 | (uint)pBVar21) != 0) || (local_98 == (char *)0x0)) break;
    }
    if (local_80 != (BIO *)0x0) {
      pBVar16 = BIO_new_file((char *)local_80,"rb");
      if (pBVar16 == (BIO *)0x0) {
LAB_00042c64:
        pPVar23 = (PKCS7 *)0x0;
        a = (PKCS7 *)0x0;
LAB_00042c68:
        pBVar6 = (BIO *)0x0;
        __printf_chk(1,"Verification: ");
LAB_00042c78:
        uVar18 = 1;
        puts("FAILED");
        ERR_print_errors(bio_err);
      }
      else {
        if (local_78 == (PKCS7 *)0x0) {
          pPVar23 = (PKCS7 *)d2i_TS_RESP_bio(pBVar16,0);
          a = local_78;
          pPVar9 = pPVar23;
        }
        else {
          pPVar23 = (PKCS7 *)0x0;
          a = d2i_PKCS7_bio(pBVar16,(PKCS7 **)0x0);
          pPVar9 = a;
        }
        if (pPVar9 == (PKCS7 *)0x0) goto LAB_00042c64;
        pcVar20 = local_98;
        if (local_98 != (char *)0x0) {
          pcVar20 = (char *)0x1;
        }
        if (((uint)pcVar20 | (uint)pBVar21) == 0) {
          if (local_88 != (BIO *)0x0) {
            pBVar5 = BIO_new_file((char *)local_88,"rb");
            if (pBVar5 != (BIO *)0x0) {
              pBVar21 = (BIO *)d2i_TS_REQ_bio(pBVar5,0);
              pBVar6 = pBVar21;
              if ((pBVar21 != (BIO *)0x0) &&
                 (pBVar6 = (BIO *)TS_REQ_to_TS_VERIFY_CTX(pBVar21,0), pBVar6 != (BIO *)0x0)) {
                pBVar3 = (BIO_METHOD *)((uint)pBVar6->method | 1);
                goto LAB_00042ac2;
              }
              goto LAB_00042d60;
            }
            goto LAB_00042e9e;
          }
          goto LAB_00042c68;
        }
        pBVar6 = (BIO *)TS_VERIFY_CTX_new();
        if (pBVar6 == (BIO *)0x0) {
LAB_00042e9e:
          pBVar21 = (BIO *)0x0;
          pBVar6 = (BIO *)0x0;
          pBVar5 = (BIO *)0x0;
LAB_00042d60:
          TS_VERIFY_CTX_free(pBVar6);
          BIO_free_all(pBVar5);
          TS_REQ_free(pBVar21);
          goto LAB_00042c68;
        }
        if (pBVar21 == (BIO *)0x0) {
          pBVar5 = pBVar21;
          if (pcVar20 == (char *)0x0) {
            pBVar6->method = (BIO_METHOD *)0x42;
            pBVar3 = (BIO_METHOD *)0x43;
          }
          else {
            pBVar6->method = (BIO_METHOD *)0x4a;
            puVar12 = string_to_hex(local_98,(long *)&local_44);
            pBVar6->flags = (int)puVar12;
            if (puVar12 == (uchar *)0x0) {
              BIO_printf(bio_err,"invalid digest string\n");
              goto LAB_00042d60;
            }
            pBVar6->retry_reason = (int)local_44;
            pBVar3 = (BIO_METHOD *)((uint)pBVar6->method | 1);
          }
        }
        else {
          pBVar6->method = (BIO_METHOD *)0x52;
          pBVar21 = BIO_new_file((char *)local_9c,"rb");
          pBVar6->num = (int)pBVar21;
          pBVar5 = pBVar21;
          if (pBVar21 == (BIO *)0x0) goto LAB_00042d60;
          pBVar21 = (BIO *)0x0;
          pBVar3 = (BIO_METHOD *)((uint)pBVar6->method | 1);
          pBVar5 = (BIO *)0x0;
        }
LAB_00042ac2:
        pBVar6->method = pBVar3;
        ctx = X509_STORE_new();
        X509_STORE_set_verify_cb(ctx,verify_cb + 1);
        if (local_6c != (char *)0x0) {
          pXVar7 = X509_LOOKUP_hash_dir();
          pXVar8 = X509_STORE_add_lookup(ctx,pXVar7);
          if (pXVar8 == (X509_LOOKUP *)0x0) {
LAB_0004310e:
            BIO_printf(bio_err,"memory allocation failure\n");
          }
          else {
            iVar2 = X509_LOOKUP_ctrl(pXVar8,2,local_6c,1,(char **)0x0);
            if (iVar2 != 0) goto LAB_00042b00;
            BIO_printf(bio_err,"Error loading directory %s\n",local_6c);
          }
LAB_00042d56:
          X509_STORE_free(ctx);
          pBVar6->callback = (_func_603 *)0x0;
          goto LAB_00042d60;
        }
LAB_00042b00:
        if (local_68 != (char *)0x0) {
          pXVar7 = X509_LOOKUP_file();
          pXVar8 = X509_STORE_add_lookup(ctx,pXVar7);
          if (pXVar8 == (X509_LOOKUP *)0x0) goto LAB_0004310e;
          iVar2 = X509_LOOKUP_ctrl(pXVar8,1,local_68,1,(char **)0x0);
          if (iVar2 == 0) {
            BIO_printf(bio_err,"Error loading file %s\n",local_68);
            goto LAB_00042d56;
          }
        }
        pBVar6->callback = (_func_603 *)ctx;
        if (ctx == (X509_STORE *)0x0) goto LAB_00042d60;
        if (local_60 != (char *)0x0) {
          pcVar20 = (char *)TS_CONF_load_certs(local_60);
          pBVar6->cb_arg = pcVar20;
          if (pcVar20 == (char *)0x0) goto LAB_00042d60;
        }
        BIO_free_all(pBVar5);
        TS_REQ_free(pBVar21);
        if (local_78 == (PKCS7 *)0x0) {
          iVar2 = TS_RESP_verify_response(pBVar6,pPVar23);
        }
        else {
          iVar2 = TS_RESP_verify_token(pBVar6,a);
        }
        __printf_chk(1,"Verification: ");
        if (iVar2 == 0) goto LAB_00042c78;
        uVar18 = 0;
        puts("OK");
      }
      conf = (CONF *)0x0;
      BIO_free_all(pBVar16);
      PKCS7_free(a);
      TS_RESP_free(pPVar23);
      TS_VERIFY_CTX_free(pBVar6);
      goto LAB_00042616;
    }
    break;
  default:
    conf = (CONF *)0x0;
    uVar18 = 1;
    goto LAB_00042616;
  }
switchD_00042606_caseD_0:
  conf = (CONF *)0x0;
LAB_0004277a:
  uVar18 = 1;
  BIO_printf(bio_err,
             "usage:\nts -query [-rand file%cfile%c...] [-config configfile] [-data file_to_hash] [-digest digest_bytes][-md2|-md4|-md5|-sha|-sha1|-mdc2|-ripemd160] [-policy object_id] [-no_nonce] [-cert] [-in request.tsq] [-out request.tsq] [-text]\n"
             ,0x3a,0x3a);
  BIO_printf(bio_err,
             "or\nts -reply [-config configfile] [-section tsa_section] [-queryfile request.tsq] [-passin password] [-signer tsa_cert.pem] [-inkey private_key.pem] [-chain certs_file.pem] [-policy object_id] [-in response.tsr] [-token_in] [-out response.tsr] [-token_out] [-text] [-engine id]\n"
            );
  BIO_printf(bio_err,
             "or\nts -verify [-data file_to_hash] [-digest digest_bytes] [-queryfile request.tsq] -in response.tsr [-token_in] -CApath ca_path -CAfile ca_file.pem -untrusted cert_file.pem\n"
            );
LAB_00042616:
  app_RAND_write_file(0,bio_err);
  NCONF_free(conf);
  CRYPTO_free(local_48);
  OBJ_cleanup();
  if (local_a0 != (BIO *)0x0) {
    BIO_free_all(bio_err);
    bio_err = (BIO *)0x0;
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar18);
}

