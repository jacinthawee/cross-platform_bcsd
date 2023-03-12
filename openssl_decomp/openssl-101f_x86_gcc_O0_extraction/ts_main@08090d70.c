
bool ts_main(int param_1,int param_2)

{
  char *pcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  void *pvVar7;
  int iVar8;
  BIO *pBVar9;
  BIO *pBVar10;
  uint *puVar11;
  uint uVar12;
  X509_STORE *ctx;
  X509_LOOKUP_METHOD *pXVar13;
  X509_LOOKUP *pXVar14;
  int iVar15;
  BIO_METHOD *type;
  PKCS7 *pPVar16;
  ASN1_INTEGER **ppAVar17;
  undefined4 uVar18;
  int iVar19;
  ASN1_TYPE *pAVar20;
  uchar *puVar21;
  char **ppcVar22;
  ASN1_INTEGER *pAVar23;
  ASN1_INTEGER *a;
  ASN1_OBJECT *pAVar24;
  CONF *conf;
  char *pcVar25;
  char *pcVar26;
  int in_GS_OFFSET;
  bool bVar27;
  byte bVar28;
  BIO *local_a0;
  BIO *local_9c;
  char *local_98;
  X509_ALGOR *local_94;
  char *local_90;
  char *local_88;
  char *local_84;
  char *local_7c;
  char *local_78;
  char *local_74;
  EVP_MD *local_70;
  char *local_6c;
  char *local_64;
  char *local_60;
  undefined4 local_54;
  char *local_50;
  char *local_4c;
  char *local_48;
  char *local_44;
  char *local_40;
  void *local_3c;
  void *local_38;
  uchar local_34 [4];
  char local_30;
  char local_2f;
  char local_2e;
  char local_2d;
  int local_20;
  
  bVar28 = 0;
  local_3c = (void *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ERR_load_crypto_strings();
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err != (BIO *)0x0) {
LAB_08090db9:
    iVar8 = load_config(bio_err,0);
    if (iVar8 == 0) {
      bVar27 = true;
      app_RAND_write_file(0,bio_err);
      NCONF_free((CONF *)0x0);
      CRYPTO_free(local_3c);
      OBJ_cleanup();
      goto LAB_08090dfe;
    }
    bVar2 = false;
LAB_08090e28:
    ppcVar22 = (char **)(param_2 + 4);
    param_1 = param_1 + -1;
    if (0 < param_1) {
      bVar5 = false;
      bVar6 = false;
      local_40 = (char *)0x0;
      local_44 = (char *)0x0;
      local_60 = (char *)0x0;
      local_64 = (char *)0x0;
      local_48 = (char *)0x0;
      local_4c = (char *)0x0;
      local_50 = (char *)0x0;
      local_88 = (char *)0x0;
      local_7c = (char *)0x0;
      bVar4 = false;
      local_6c = (char *)0x0;
      local_74 = (char *)0x0;
      local_54 = 0;
      bVar3 = false;
      local_78 = (char *)0x0;
      local_84 = (char *)0x0;
      local_70 = (EVP_MD *)0x0;
      local_90 = (char *)0x0;
      local_94 = (X509_ALGOR *)0x0;
      local_9c = (BIO *)0x0;
      local_98 = (char *)0x0;
LAB_08090f17:
      bVar27 = param_1 == 0;
      pcVar1 = *ppcVar22;
      iVar8 = 8;
      pcVar25 = pcVar1;
      pcVar26 = "-config";
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        bVar27 = *pcVar25 == *pcVar26;
        pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
        pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
      } while (bVar27);
      if (bVar27) {
        ppcVar22 = ppcVar22 + 1;
        param_1 = param_1 + -1;
      }
      else {
        iVar8 = 9;
        pcVar25 = pcVar1;
        pcVar26 = "-section";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar27 = *pcVar25 == *pcVar26;
          pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
          pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
        } while (bVar27);
        if (bVar27) {
          local_98 = ppcVar22[1];
          param_1 = param_1 + -2;
          ppcVar22 = ppcVar22 + 2;
          goto joined_r0x08090f52;
        }
        iVar8 = 7;
        pcVar25 = pcVar1;
        pcVar26 = "-query";
        do {
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          bVar27 = *pcVar25 == *pcVar26;
          pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
          pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
        } while (bVar27);
        if (bVar27) {
          if (local_9c != (BIO *)0x0) goto LAB_080913df;
          local_9c = (BIO *)0x1;
        }
        else {
          iVar8 = 6;
          pcVar25 = pcVar1;
          pcVar26 = "-data";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar27 = *pcVar25 == *pcVar26;
            pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
            pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
          } while (bVar27);
          if (bVar27) {
            local_94 = (X509_ALGOR *)ppcVar22[1];
            param_1 = param_1 + -1;
            ppcVar22 = ppcVar22 + 1;
            goto LAB_08090f0d;
          }
          iVar8 = 8;
          pcVar25 = pcVar1;
          pcVar26 = "-digest";
          do {
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            bVar27 = *pcVar25 == *pcVar26;
            pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
            pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
          } while (bVar27);
          if (bVar27) {
            local_90 = ppcVar22[1];
            param_1 = param_1 + -1;
            ppcVar22 = ppcVar22 + 1;
          }
          else {
            iVar8 = 6;
            pcVar25 = pcVar1;
            pcVar26 = "-rand";
            do {
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              bVar27 = *pcVar25 == *pcVar26;
              pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
              pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
            } while (bVar27);
            if (bVar27) {
              local_84 = ppcVar22[1];
              param_1 = param_1 + -1;
              ppcVar22 = ppcVar22 + 1;
            }
            else {
              iVar8 = 8;
              pcVar25 = pcVar1;
              pcVar26 = "-policy";
              do {
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                bVar27 = *pcVar25 == *pcVar26;
                pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
              } while (bVar27);
              if (bVar27) {
                local_78 = ppcVar22[1];
                param_1 = param_1 + -1;
                ppcVar22 = ppcVar22 + 1;
              }
              else {
                iVar8 = 10;
                pcVar25 = pcVar1;
                pcVar26 = "-no_nonce";
                do {
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  bVar27 = *pcVar25 == *pcVar26;
                  pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                  pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                } while (bVar27);
                if (bVar27) {
                  bVar3 = true;
                }
                else {
                  iVar8 = 6;
                  pcVar25 = pcVar1;
                  pcVar26 = "-cert";
                  do {
                    if (iVar8 == 0) break;
                    iVar8 = iVar8 + -1;
                    bVar27 = *pcVar25 == *pcVar26;
                    pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                    pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                  } while (bVar27);
                  if (bVar27) {
                    local_54 = 1;
                  }
                  else {
                    bVar27 = *pcVar1 == '-';
                    if ((((bVar27) && (bVar27 = pcVar1[1] == 'i', bVar27)) &&
                        (bVar27 = pcVar1[2] == 'n', bVar27)) && (bVar27 = pcVar1[3] == '\0', bVar27)
                       ) {
                      local_74 = ppcVar22[1];
                      param_1 = param_1 + -1;
                      ppcVar22 = ppcVar22 + 1;
                    }
                    else {
                      iVar8 = 10;
                      pcVar25 = pcVar1;
                      pcVar26 = "-token_in";
                      do {
                        if (iVar8 == 0) break;
                        iVar8 = iVar8 + -1;
                        bVar27 = *pcVar25 == *pcVar26;
                        pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                        pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                      } while (bVar27);
                      if (bVar27) {
                        bVar6 = true;
                      }
                      else {
                        iVar8 = 5;
                        pcVar25 = pcVar1;
                        pcVar26 = "-out";
                        do {
                          if (iVar8 == 0) break;
                          iVar8 = iVar8 + -1;
                          bVar27 = *pcVar25 == *pcVar26;
                          pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                          pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                        } while (bVar27);
                        if (bVar27) {
                          local_6c = ppcVar22[1];
                          param_1 = param_1 + -1;
                          ppcVar22 = ppcVar22 + 1;
                        }
                        else {
                          iVar8 = 0xb;
                          pcVar25 = pcVar1;
                          pcVar26 = "-token_out";
                          do {
                            if (iVar8 == 0) break;
                            iVar8 = iVar8 + -1;
                            bVar27 = *pcVar25 == *pcVar26;
                            pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                            pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                          } while (bVar27);
                          if (bVar27) {
                            bVar5 = true;
                          }
                          else {
                            iVar8 = 6;
                            pcVar25 = pcVar1;
                            pcVar26 = "-text";
                            do {
                              if (iVar8 == 0) break;
                              iVar8 = iVar8 + -1;
                              bVar27 = *pcVar25 == *pcVar26;
                              pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                              pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                            } while (bVar27);
                            if (bVar27) {
                              bVar4 = true;
                            }
                            else {
                              iVar8 = 7;
                              pcVar25 = pcVar1;
                              pcVar26 = "-reply";
                              do {
                                if (iVar8 == 0) break;
                                iVar8 = iVar8 + -1;
                                bVar27 = *pcVar25 == *pcVar26;
                                pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                              } while (bVar27);
                              if (bVar27) {
                                if (local_9c != (BIO *)0x0) goto LAB_080913df;
                                local_9c = (BIO *)0x2;
                              }
                              else {
                                iVar8 = 0xb;
                                pcVar25 = pcVar1;
                                pcVar26 = "-queryfile";
                                do {
                                  if (iVar8 == 0) break;
                                  iVar8 = iVar8 + -1;
                                  bVar27 = *pcVar25 == *pcVar26;
                                  pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                  pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                } while (bVar27);
                                if (bVar27) {
                                  local_7c = ppcVar22[1];
                                  param_1 = param_1 + -1;
                                  ppcVar22 = ppcVar22 + 1;
                                }
                                else {
                                  iVar8 = 8;
                                  pcVar25 = pcVar1;
                                  pcVar26 = "-passin";
                                  do {
                                    if (iVar8 == 0) break;
                                    iVar8 = iVar8 + -1;
                                    bVar27 = *pcVar25 == *pcVar26;
                                    pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                    pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                  } while (bVar27);
                                  if (bVar27) {
                                    local_88 = ppcVar22[1];
                                    param_1 = param_1 + -1;
                                    ppcVar22 = ppcVar22 + 1;
                                  }
                                  else {
                                    iVar8 = 7;
                                    pcVar25 = pcVar1;
                                    pcVar26 = "-inkey";
                                    do {
                                      if (iVar8 == 0) break;
                                      iVar8 = iVar8 + -1;
                                      bVar27 = *pcVar25 == *pcVar26;
                                      pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                      pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                    } while (bVar27);
                                    if (bVar27) {
                                      local_50 = ppcVar22[1];
                                      param_1 = param_1 + -1;
                                      ppcVar22 = ppcVar22 + 1;
                                    }
                                    else {
                                      iVar8 = 8;
                                      pcVar25 = pcVar1;
                                      pcVar26 = "-signer";
                                      do {
                                        if (iVar8 == 0) break;
                                        iVar8 = iVar8 + -1;
                                        bVar27 = *pcVar25 == *pcVar26;
                                        pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                        pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                      } while (bVar27);
                                      if (bVar27) {
                                        local_4c = ppcVar22[1];
                                        param_1 = param_1 + -1;
                                        ppcVar22 = ppcVar22 + 1;
                                      }
                                      else {
                                        iVar8 = 7;
                                        pcVar25 = pcVar1;
                                        pcVar26 = "-chain";
                                        do {
                                          if (iVar8 == 0) break;
                                          iVar8 = iVar8 + -1;
                                          bVar27 = *pcVar25 == *pcVar26;
                                          pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                          pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                        } while (bVar27);
                                        if (bVar27) {
                                          local_48 = ppcVar22[1];
                                          param_1 = param_1 + -1;
                                          ppcVar22 = ppcVar22 + 1;
                                        }
                                        else {
                                          iVar8 = 8;
                                          pcVar25 = pcVar1;
                                          pcVar26 = "-verify";
                                          do {
                                            if (iVar8 == 0) break;
                                            iVar8 = iVar8 + -1;
                                            bVar27 = *pcVar25 == *pcVar26;
                                            pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                            pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                          } while (bVar27);
                                          if (bVar27) {
                                            if (local_9c != (BIO *)0x0) goto LAB_080913df;
                                            local_9c = (BIO *)0x3;
                                          }
                                          else {
                                            iVar8 = 8;
                                            pcVar25 = pcVar1;
                                            pcVar26 = "-CApath";
                                            do {
                                              if (iVar8 == 0) break;
                                              iVar8 = iVar8 + -1;
                                              bVar27 = *pcVar25 == *pcVar26;
                                              pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                              pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                            } while (bVar27);
                                            if (bVar27) {
                                              local_64 = ppcVar22[1];
                                              param_1 = param_1 + -1;
                                              ppcVar22 = ppcVar22 + 1;
                                            }
                                            else {
                                              iVar8 = 8;
                                              pcVar25 = pcVar1;
                                              pcVar26 = "-CAfile";
                                              do {
                                                if (iVar8 == 0) break;
                                                iVar8 = iVar8 + -1;
                                                bVar27 = *pcVar25 == *pcVar26;
                                                pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                                pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                              } while (bVar27);
                                              if (bVar27) {
                                                local_60 = ppcVar22[1];
                                                param_1 = param_1 + -1;
                                                ppcVar22 = ppcVar22 + 1;
                                              }
                                              else {
                                                iVar8 = 0xb;
                                                pcVar25 = pcVar1;
                                                pcVar26 = "-untrusted";
                                                do {
                                                  if (iVar8 == 0) break;
                                                  iVar8 = iVar8 + -1;
                                                  bVar27 = *pcVar25 == *pcVar26;
                                                  pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                                  pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                                } while (bVar27);
                                                if (bVar27) {
                                                  local_44 = ppcVar22[1];
                                                  param_1 = param_1 + -1;
                                                  ppcVar22 = ppcVar22 + 1;
                                                }
                                                else {
                                                  iVar8 = 8;
                                                  pcVar25 = pcVar1;
                                                  pcVar26 = "-engine";
                                                  do {
                                                    if (iVar8 == 0) break;
                                                    iVar8 = iVar8 + -1;
                                                    bVar27 = *pcVar25 == *pcVar26;
                                                    pcVar25 = pcVar25 + (uint)bVar28 * -2 + 1;
                                                    pcVar26 = pcVar26 + (uint)bVar28 * -2 + 1;
                                                  } while (bVar27);
                                                  if (bVar27) {
                                                    local_40 = ppcVar22[1];
                                                    param_1 = param_1 + -1;
                                                    ppcVar22 = ppcVar22 + 1;
                                                  }
                                                  else {
                                                    local_70 = EVP_get_digestbyname(pcVar1 + 1);
                                                    if (local_70 == (EVP_MD *)0x0)
                                                    goto LAB_080913df;
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
LAB_08090f0d:
      param_1 = param_1 + -1;
      ppcVar22 = ppcVar22 + 1;
joined_r0x08090f52:
      if (param_1 < 1) goto LAB_08090f54;
      goto LAB_08090f17;
    }
LAB_080913df:
    conf = (CONF *)0x0;
    bVar27 = true;
LAB_080913e6:
    BIO_printf(bio_err,
               "usage:\nts -query [-rand file%cfile%c...] [-config configfile] [-data file_to_hash] [-digest digest_bytes][-md2|-md4|-md5|-sha|-sha1|-mdc2|-ripemd160] [-policy object_id] [-no_nonce] [-cert] [-in request.tsq] [-out request.tsq] [-text]\n"
               ,0x3a,0x3a);
    BIO_printf(bio_err,
               "or\nts -reply [-config configfile] [-section tsa_section] [-queryfile request.tsq] [-passin password] [-signer tsa_cert.pem] [-inkey private_key.pem] [-chain certs_file.pem] [-policy object_id] [-in response.tsr] [-token_in] [-out response.tsr] [-token_out] [-text] [-engine id]\n"
              );
    BIO_printf(bio_err,
               "or\nts -verify [-data file_to_hash] [-digest digest_bytes] [-queryfile request.tsq] -in response.tsr [-token_in] -CApath ca_path -CAfile ca_file.pem -untrusted cert_file.pem\n"
              );
    goto LAB_08091421;
  }
  type = BIO_s_file();
  bio_err = BIO_new(type);
  if (bio_err == (BIO *)0x0) goto LAB_08090db9;
  BIO_ctrl(bio_err,0x6a,0x10,stderr);
  iVar8 = load_config(bio_err,0);
  if (iVar8 != 0) {
    bVar2 = true;
    goto LAB_08090e28;
  }
  app_RAND_write_file(0,bio_err);
  NCONF_free((CONF *)0x0);
  bVar27 = true;
  CRYPTO_free(local_3c);
  OBJ_cleanup();
  goto LAB_08091457;
LAB_08090f54:
  if (local_9c == (BIO *)0x1 && !bVar3) {
    iVar8 = app_RAND_load_file(0,bio_err,1);
    if (iVar8 == 0) {
      if (local_84 == (char *)0x0) {
        BIO_printf(bio_err,"warning, not much extra random data, consider using the -rand option\n")
        ;
      }
      else {
LAB_08091356:
        uVar18 = app_RAND_load_files(local_84);
        BIO_printf(bio_err,"%ld semi-random bytes loaded\n",uVar18);
      }
    }
    else if (local_84 != (char *)0x0) goto LAB_08091356;
  }
  if ((local_9c == (BIO *)0x2 && local_88 != (char *)0x0) &&
     (iVar8 = app_passwd(bio_err,local_88,0,&local_3c,0), iVar8 == 0)) {
    conf = (CONF *)0x0;
    bVar27 = true;
    BIO_printf(bio_err,"Error getting password.\n");
  }
  else {
    if (local_9c != (BIO *)0x1) {
      if (local_9c == (BIO *)0x0) goto LAB_080913df;
      if (local_9c != (BIO *)0x2) {
        if (local_9c != (BIO *)0x3) {
          conf = (CONF *)0x0;
          bVar27 = true;
          goto LAB_08091421;
        }
        bVar27 = local_94 != (X509_ALGOR *)0x0;
        if ((((((local_7c == (char *)0x0) || (bVar27)) &&
              ((local_94 == (X509_ALGOR *)0x0 || (local_7c != (char *)0x0)))) ||
             (local_90 != (char *)0x0)) &&
            ((local_90 == (char *)0x0 || bVar27 || (local_7c != (char *)0x0)))) ||
           (local_74 == (char *)0x0)) goto LAB_080913df;
        pBVar9 = BIO_new_file(local_74,"rb");
        if (pBVar9 == (BIO *)0x0) {
LAB_08091955:
          local_a0 = (BIO *)0x0;
          local_9c = (BIO *)0x0;
LAB_0809181a:
          puVar11 = (uint *)0x0;
          __printf_chk(1,"Verification: ");
LAB_0809182e:
          bVar27 = true;
          puts("FAILED");
          ERR_print_errors(bio_err);
        }
        else {
          if (bVar6) {
            local_9c = (BIO *)d2i_PKCS7_bio(pBVar9,(PKCS7 **)0x0);
            local_a0 = (BIO *)0x0;
            if (local_9c == (BIO *)0x0) goto LAB_08091955;
          }
          else {
            local_a0 = (BIO *)d2i_TS_RESP_bio(pBVar9,0);
            if (local_a0 == (BIO *)0x0) goto LAB_08091955;
            local_9c = (BIO *)0x0;
          }
          if ((local_90 == (char *)0x0) && (!bVar27)) {
            if (local_7c != (char *)0x0) {
              pBVar10 = BIO_new_file(local_7c,"rb");
              if (pBVar10 != (BIO *)0x0) {
                iVar8 = d2i_TS_REQ_bio(pBVar10,0);
                if (iVar8 == 0) {
                  puVar11 = (uint *)0x0;
                }
                else {
                  puVar11 = (uint *)TS_REQ_to_TS_VERIFY_CTX(iVar8,0);
                  if (puVar11 != (uint *)0x0) {
                    uVar12 = *puVar11 | 1;
                    goto LAB_080910c1;
                  }
                }
                goto LAB_080917fe;
              }
              goto LAB_080917f8;
            }
            goto LAB_0809181a;
          }
          puVar11 = (uint *)TS_VERIFY_CTX_new();
          if (puVar11 == (uint *)0x0) {
LAB_080917f8:
            iVar8 = 0;
            pBVar10 = (BIO *)0x0;
            puVar11 = (uint *)0x0;
LAB_080917fe:
            TS_VERIFY_CTX_free(puVar11);
            BIO_free_all(pBVar10);
            TS_REQ_free(iVar8);
            goto LAB_0809181a;
          }
          if (local_94 == (X509_ALGOR *)0x0) {
            if (local_90 == (char *)0x0) {
              *puVar11 = 0x42;
              uVar12 = 0x43;
              iVar8 = 0;
              pBVar10 = (BIO *)0x0;
              goto LAB_080910c1;
            }
            *puVar11 = 0x4a;
            puVar21 = string_to_hex(local_90,(long *)&local_38);
            puVar11[5] = (uint)puVar21;
            if (puVar21 != (uchar *)0x0) {
              puVar11[6] = (uint)local_38;
              goto LAB_08091b4d;
            }
            iVar8 = 0;
            pBVar10 = (BIO *)0x0;
            BIO_printf(bio_err,"invalid digest string\n");
            goto LAB_080917fe;
          }
          *puVar11 = 0x52;
          pBVar10 = BIO_new_file((char *)local_94,"rb");
          puVar11[7] = (uint)pBVar10;
          if (pBVar10 == (BIO *)0x0) {
            iVar8 = 0;
            pBVar10 = (BIO *)0x0;
            goto LAB_080917fe;
          }
LAB_08091b4d:
          iVar8 = 0;
          pBVar10 = (BIO *)0x0;
          uVar12 = *puVar11 | 1;
LAB_080910c1:
          *puVar11 = uVar12;
          ctx = X509_STORE_new();
          X509_STORE_set_verify_cb(ctx,verify_cb);
          if (local_64 != (char *)0x0) {
            pXVar13 = X509_LOOKUP_hash_dir();
            pXVar14 = X509_STORE_add_lookup(ctx,pXVar13);
            if (pXVar14 == (X509_LOOKUP *)0x0) {
LAB_08092064:
              BIO_printf(bio_err,"memory allocation failure\n");
            }
            else {
              iVar15 = X509_LOOKUP_ctrl(pXVar14,2,local_64,1,(char **)0x0);
              if (iVar15 != 0) goto LAB_0809111b;
              BIO_printf(bio_err,"Error loading directory %s\n",local_64);
            }
LAB_0809204c:
            X509_STORE_free(ctx);
            puVar11[1] = 0;
            goto LAB_080917fe;
          }
LAB_0809111b:
          if (local_60 != (char *)0x0) {
            pXVar13 = X509_LOOKUP_file();
            pXVar14 = X509_STORE_add_lookup(ctx,pXVar13);
            if (pXVar14 == (X509_LOOKUP *)0x0) goto LAB_08092064;
            iVar15 = X509_LOOKUP_ctrl(pXVar14,1,local_60,1,(char **)0x0);
            if (iVar15 == 0) {
              BIO_printf(bio_err,"Error loading file %s\n",local_60);
              goto LAB_0809204c;
            }
          }
          puVar11[1] = (uint)ctx;
          if (ctx == (X509_STORE *)0x0) goto LAB_080917fe;
          if (local_44 != (char *)0x0) {
            uVar12 = TS_CONF_load_certs(local_44);
            puVar11[2] = uVar12;
            if (uVar12 == 0) goto LAB_080917fe;
          }
          BIO_free_all(pBVar10);
          TS_REQ_free(iVar8);
          if (bVar6) {
            iVar8 = TS_RESP_verify_token(puVar11,local_9c);
          }
          else {
            iVar8 = TS_RESP_verify_response(puVar11,local_a0);
          }
          __printf_chk(1,"Verification: ");
          if (iVar8 == 0) goto LAB_0809182e;
          bVar27 = false;
          puts("OK");
        }
        BIO_free_all(pBVar9);
        PKCS7_free((PKCS7 *)local_9c);
        TS_RESP_free(local_a0);
        conf = (CONF *)0x0;
        TS_VERIFY_CTX_free(puVar11);
        goto LAB_08091421;
      }
      conf = (CONF *)load_config_file();
      pvVar7 = local_3c;
      if (local_74 == (char *)0x0) {
        if (((bool)(bVar6 | local_7c == (char *)0x0)) || (conf == (CONF *)0x0)) {
          bVar27 = true;
          goto LAB_080913e6;
        }
        pBVar9 = BIO_new_file(local_7c,"rb");
        if (((pBVar9 == (BIO *)0x0) || (iVar8 = TS_CONF_get_tsa_section(conf,local_98), iVar8 == 0))
           || (iVar15 = TS_RESP_CTX_new(), iVar15 == 0)) {
          iVar15 = 0;
        }
        else {
          iVar19 = TS_CONF_set_serial(conf,iVar8,serial_cb,iVar15);
          if ((((iVar19 != 0) &&
               (iVar19 = TS_CONF_set_crypto_device(conf,iVar8,local_40), iVar19 != 0)) &&
              ((iVar19 = TS_CONF_set_signer_cert(conf,iVar8,local_4c,iVar15), iVar19 != 0 &&
               ((iVar19 = TS_CONF_set_certs(conf,iVar8,local_48,iVar15), iVar19 != 0 &&
                (iVar19 = TS_CONF_set_signer_key(conf,iVar8,local_50,pvVar7,iVar15), iVar19 != 0))))
              )) && ((iVar19 = TS_CONF_set_def_policy(conf,iVar8,local_78,iVar15), iVar19 != 0 &&
                     (((((iVar19 = TS_CONF_set_policies(conf,iVar8,iVar15), iVar19 != 0 &&
                         (iVar19 = TS_CONF_set_digests(conf,iVar8,iVar15), iVar19 != 0)) &&
                        (iVar19 = TS_CONF_set_accuracy(conf,iVar8,iVar15), iVar19 != 0)) &&
                       ((iVar19 = TS_CONF_set_clock_precision_digits(conf,iVar8,iVar15), iVar19 != 0
                        && (iVar19 = TS_CONF_set_ordering(conf,iVar8,iVar15), iVar19 != 0)))) &&
                      ((iVar19 = TS_CONF_set_tsa_name(conf,iVar8,iVar15), iVar19 != 0 &&
                       ((iVar8 = TS_CONF_set_ess_cert_id_chain(conf,iVar8,iVar15), iVar8 != 0 &&
                        (iVar8 = TS_RESP_create_response(iVar15,pBVar9), iVar8 != 0)))))))))) {
            TS_RESP_CTX_free(iVar15);
            BIO_free_all(pBVar9);
            BIO_printf(bio_err,"Response has been generated.\n");
            local_a0 = (BIO *)0x0;
            goto LAB_080916ea;
          }
        }
        TS_RESP_free(0);
        bVar27 = true;
        TS_RESP_CTX_free(iVar15);
        pBVar10 = (BIO *)0x0;
        BIO_free_all(pBVar9);
        iVar8 = 0;
        BIO_printf(bio_err,"Response is not generated.\n");
        local_a0 = (BIO *)0x0;
LAB_08091748:
        ERR_print_errors(bio_err);
        BIO_free_all(local_a0);
        BIO_free_all((BIO *)0x0);
        BIO_free_all((BIO *)0x0);
        BIO_free_all((BIO *)0x0);
        BIO_free_all(pBVar10);
        TS_RESP_free(iVar8);
        goto LAB_08091421;
      }
      bVar27 = local_7c != (char *)0x0;
      if (!bVar27) {
        local_a0 = BIO_new_file(local_74,"rb");
        if (local_a0 == (BIO *)0x0) {
          bVar27 = true;
          pBVar10 = (BIO *)0x0;
          iVar8 = 0;
        }
        else {
          if (bVar6) {
            pPVar16 = d2i_PKCS7_bio(local_a0,(PKCS7 **)0x0);
            if (pPVar16 == (PKCS7 *)0x0) {
              ppAVar17 = (ASN1_INTEGER **)0x0;
              iVar8 = 0;
              local_9c = (BIO *)0x0;
LAB_080916b6:
              PKCS7_free(pPVar16);
              TS_TST_INFO_free(local_9c);
              TS_RESP_free(iVar8);
              iVar8 = 0;
            }
            else {
              local_9c = (BIO *)PKCS7_to_TS_TST_INFO(pPVar16);
              if (local_9c == (BIO *)0x0) {
                ppAVar17 = (ASN1_INTEGER **)0x0;
                iVar8 = 0;
                goto LAB_080916b6;
              }
              iVar8 = TS_RESP_new();
              if (iVar8 == 0) {
                ppAVar17 = (ASN1_INTEGER **)0x0;
                goto LAB_080916b6;
              }
              ppAVar17 = (ASN1_INTEGER **)TS_STATUS_INFO_new();
              if (((ppAVar17 == (ASN1_INTEGER **)0x0) ||
                  (iVar15 = ASN1_INTEGER_set(*ppAVar17,0), iVar15 == 0)) ||
                 (iVar15 = TS_RESP_set_status_info(iVar8,ppAVar17), iVar15 == 0)) goto LAB_080916b6;
              TS_RESP_set_tst_info(iVar8,pPVar16,local_9c);
              PKCS7_free((PKCS7 *)0x0);
              TS_TST_INFO_free(0);
            }
            TS_STATUS_INFO_free(ppAVar17);
          }
          else {
            iVar8 = d2i_TS_RESP_bio(local_a0,0);
          }
          if (iVar8 == 0) {
            bVar27 = true;
            pBVar10 = (BIO *)0x0;
          }
          else {
LAB_080916ea:
            if (local_6c == (char *)0x0) {
              pBVar10 = BIO_new_fp(stdout,0);
            }
            else {
              pBVar10 = BIO_new_file(local_6c,"wb");
            }
            if (pBVar10 == (BIO *)0x0) {
              bVar27 = true;
            }
            else if (bVar4) {
              if (bVar5) {
                uVar18 = TS_RESP_get_tst_info(iVar8);
                iVar15 = TS_TST_INFO_print_bio(pBVar10,uVar18);
                bVar27 = iVar15 == 0;
              }
              else {
                iVar15 = TS_RESP_print_bio(pBVar10,iVar8);
                bVar27 = iVar15 == 0;
              }
            }
            else if (bVar5) {
              pPVar16 = (PKCS7 *)TS_RESP_get_token(iVar8);
              iVar15 = i2d_PKCS7_bio(pBVar10,pPVar16);
              bVar27 = iVar15 == 0;
            }
            else {
              iVar15 = i2d_TS_RESP_bio(pBVar10,iVar8);
              bVar27 = iVar15 == 0;
            }
          }
        }
        goto LAB_08091748;
      }
      goto LAB_080913e6;
    }
    if (local_94 != (X509_ALGOR *)0x0) {
      conf = (CONF *)0x0;
      bVar27 = true;
      if (local_90 != (char *)0x0) goto LAB_080913e6;
    }
    conf = (CONF *)load_config_file();
    if (local_74 == (char *)0x0) {
      local_9c = (BIO *)0x0;
      if (local_90 == (char *)0x0) {
        if (local_94 == (X509_ALGOR *)0x0) {
          local_9c = BIO_new_fp(stdin,0);
        }
        else {
          local_9c = BIO_new_file((char *)local_94,"rb");
        }
        if (local_9c == (BIO *)0x0) goto LAB_08091b8b;
      }
      local_38 = (void *)0x0;
      if (((local_70 == (EVP_MD *)0x0) &&
          (local_70 = EVP_get_digestbyname("sha1"), local_70 == (EVP_MD *)0x0)) ||
         (local_a0 = (BIO *)TS_REQ_new(), local_a0 == (BIO *)0x0)) {
        pAVar23 = (ASN1_INTEGER *)0x0;
        pAVar24 = (ASN1_OBJECT *)0x0;
        local_94 = (X509_ALGOR *)0x0;
        local_98 = (char *)0x0;
        local_a0 = (BIO *)0x0;
LAB_080919e9:
        TS_REQ_free(local_a0);
        BIO_printf(bio_err,"could not create query\n");
        local_a0 = (BIO *)0x0;
        a = pAVar23;
      }
      else {
        iVar8 = TS_REQ_set_version(local_a0,1);
        if (iVar8 == 0) {
          pAVar24 = (ASN1_OBJECT *)0x0;
          local_94 = (X509_ALGOR *)0x0;
          local_98 = (char *)0x0;
          pAVar23 = (ASN1_INTEGER *)0x0;
          goto LAB_080919e9;
        }
        local_98 = (char *)TS_MSG_IMPRINT_new();
        if (local_98 == (char *)0x0) {
          pAVar23 = (ASN1_INTEGER *)0x0;
          pAVar24 = (ASN1_OBJECT *)0x0;
          local_94 = (X509_ALGOR *)0x0;
          goto LAB_080919e9;
        }
        local_94 = X509_ALGOR_new();
        if (local_94 == (X509_ALGOR *)0x0) {
LAB_0809227e:
          pAVar23 = (ASN1_INTEGER *)0x0;
          pAVar24 = (ASN1_OBJECT *)0x0;
          goto LAB_080919e9;
        }
        iVar8 = EVP_MD_type(local_70);
        pAVar24 = OBJ_nid2obj(iVar8);
        local_94->algorithm = pAVar24;
        if (pAVar24 == (ASN1_OBJECT *)0x0) goto LAB_0809227e;
        pAVar20 = ASN1_TYPE_new();
        local_94->parameter = pAVar20;
        if (pAVar20 == (ASN1_TYPE *)0x0) goto LAB_0809227e;
        pAVar20->type = 5;
        pAVar24 = (ASN1_OBJECT *)0x0;
        pAVar23 = (ASN1_INTEGER *)0x0;
        iVar8 = TS_MSG_IMPRINT_set_algo(local_98,local_94);
        if (((iVar8 == 0) || (iVar8 = create_digest(&local_38), iVar8 == 0)) ||
           (iVar8 = TS_MSG_IMPRINT_set_msg(local_98,local_38,iVar8), iVar8 == 0)) goto LAB_080919e9;
        iVar8 = TS_REQ_set_msg_imprint(local_a0,local_98);
        if (iVar8 == 0) goto LAB_0809227e;
        if (local_78 != (char *)0x0) {
          pAVar24 = OBJ_txt2obj(local_78,0);
          if (pAVar24 == (ASN1_OBJECT *)0x0) {
            BIO_printf(bio_err,"cannot convert %s to OID\n",local_78);
          }
          else {
            iVar8 = TS_REQ_set_policy_id(local_a0,pAVar24);
            pAVar23 = (ASN1_INTEGER *)0x0;
            if (iVar8 != 0) goto LAB_08091cf6;
          }
          goto LAB_080919e9;
        }
        pAVar24 = (ASN1_OBJECT *)0x0;
LAB_08091cf6:
        a = (ASN1_INTEGER *)0x0;
        if (!bVar3) {
          iVar8 = RAND_bytes(local_34,8);
          if (iVar8 < 1) {
LAB_080922ba:
            a = (ASN1_INTEGER *)0x0;
          }
          else {
            if (local_34[0] == '\0') {
              if (local_34[1] == '\0') {
                if (local_34[2] == '\0') {
                  if (local_34[3] == '\0') {
                    if (local_30 == '\0') {
                      if (local_2f == '\0') {
                        if (local_2e == '\0') {
                          iVar8 = ~-(uint)(local_2d == '\0') + 8;
                        }
                        else {
                          iVar8 = 6;
                        }
                      }
                      else {
                        iVar8 = 5;
                      }
                    }
                    else {
                      iVar8 = 4;
                    }
                  }
                  else {
                    iVar8 = 3;
                  }
                }
                else {
                  iVar8 = 2;
                }
              }
              else {
                iVar8 = 1;
              }
            }
            else {
              iVar8 = 0;
            }
            a = ASN1_INTEGER_new();
            if (a == (ASN1_INTEGER *)0x0) goto LAB_080922ba;
            CRYPTO_free(a->data);
            a->length = 8 - iVar8;
            puVar21 = (uchar *)CRYPTO_malloc(9 - iVar8,"ts.c",0x294);
            a->data = puVar21;
            if (puVar21 != (uchar *)0x0) {
              memcpy(puVar21,local_34 + iVar8,a->length);
              iVar8 = TS_REQ_set_nonce(local_a0,a);
              pAVar23 = a;
              if (iVar8 == 0) goto LAB_080919e9;
              goto LAB_08091d04;
            }
          }
          BIO_printf(bio_err,"could not create nonce\n");
          pAVar23 = (ASN1_INTEGER *)0x0;
          ASN1_INTEGER_free(a);
          goto LAB_080919e9;
        }
LAB_08091d04:
        iVar8 = TS_REQ_set_cert_req(local_a0,local_54);
        pAVar23 = a;
        if (iVar8 == 0) goto LAB_080919e9;
      }
      pBVar9 = (BIO *)0x0;
      TS_MSG_IMPRINT_free(local_98);
      X509_ALGOR_free(local_94);
      CRYPTO_free(local_38);
      ASN1_OBJECT_free(pAVar24);
      ASN1_INTEGER_free(a);
LAB_08091542:
      if (local_a0 == (BIO *)0x0) {
        bVar27 = true;
        pBVar10 = (BIO *)0x0;
      }
      else {
        if (local_6c == (char *)0x0) {
          pBVar10 = BIO_new_fp(stdout,0);
        }
        else {
          pBVar10 = BIO_new_file(local_6c,"wb");
        }
        if (pBVar10 == (BIO *)0x0) {
          bVar27 = true;
        }
        else if (bVar4) {
          iVar8 = TS_REQ_print_bio(pBVar10,local_a0);
          bVar27 = iVar8 == 0;
        }
        else {
          iVar8 = i2d_TS_REQ_bio(pBVar10,local_a0);
          bVar27 = iVar8 == 0;
        }
      }
    }
    else {
      pBVar9 = BIO_new_file(local_74,"rb");
      if (pBVar9 != (BIO *)0x0) {
        local_a0 = (BIO *)d2i_TS_REQ_bio(pBVar9,0);
        local_9c = (BIO *)0x0;
        goto LAB_08091542;
      }
LAB_08091b8b:
      bVar27 = true;
      pBVar10 = (BIO *)0x0;
      local_9c = (BIO *)0x0;
      pBVar9 = (BIO *)0x0;
      local_a0 = (BIO *)0x0;
    }
    ERR_print_errors(bio_err);
    BIO_free_all(pBVar9);
    BIO_free_all(local_9c);
    BIO_free_all(pBVar10);
    TS_REQ_free(local_a0);
  }
LAB_08091421:
  app_RAND_write_file(0,bio_err);
  NCONF_free(conf);
  CRYPTO_free(local_3c);
  OBJ_cleanup();
  if (!bVar2) goto LAB_08090dfe;
LAB_08091457:
  BIO_free_all(bio_err);
  bio_err = (BIO *)0x0;
LAB_08090dfe:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return bVar27;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

