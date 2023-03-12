
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

X509 * cms_main(undefined4 param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  X509 *oid;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  X509 *bp;
  BIO_METHOD *type;
  undefined4 uVar7;
  _STACK *p_Var8;
  X509 *pXVar9;
  X509 *pXVar10;
  CMS_SignerInfo *si;
  BIO *pBVar11;
  void *pvVar12;
  uchar *puVar13;
  char *pcVar14;
  uint uVar15;
  X509 *pXVar16;
  X509 **ppXVar17;
  X509 *pXVar18;
  X509 *pXVar19;
  X509 *pXVar20;
  uint uVar21;
  X509 *st;
  X509 *pXVar22;
  X509 *pXVar23;
  int iVar24;
  X509 *local_f8;
  X509 *local_f4;
  X509 *local_f0;
  X509 *local_ec;
  X509 *local_e8;
  X509 *local_e4;
  X509 *local_e0;
  X509 *local_dc;
  X509 *local_d8;
  X509 *local_d4;
  X509 *local_d0;
  X509 *local_cc;
  X509 *local_c8;
  X509 *local_c4;
  X509 *local_c0;
  X509 *local_bc;
  uint local_b8;
  int local_b4;
  EVP_CIPHER *local_a8;
  int local_a4;
  X509 *local_a0;
  X509 *local_9c;
  X509 *local_98;
  int local_94;
  X509 *local_90;
  X509 *local_8c;
  undefined4 local_88;
  ASN1_STRING *local_84;
  X509 *local_80;
  X509 *local_7c;
  X509 *local_78;
  EVP_MD *local_74;
  X509 *local_68;
  X509 *local_64;
  ASN1_STRING *local_5c;
  X509 **local_50;
  X509 *local_4c;
  X509 *local_48;
  void *local_44;
  X509_VERIFY_PARAM *local_40;
  CMS_ReceiptRequest *local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  ASN1_STRING *local_2c [2];
  
  local_50 = (X509 **)(param_2 + 4);
  local_4c = (X509 *)0x0;
  local_48 = (X509 *)0x0;
  local_44 = (void *)0x0;
  local_40 = (X509_VERIFY_PARAM *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  oid = (X509 *)load_config(bio_err,0);
  if (oid == (X509 *)0x0) {
    local_68 = (X509 *)0x1;
    pXVar19 = oid;
    pXVar22 = oid;
    st = oid;
    pXVar23 = oid;
    bp = oid;
    local_f8 = oid;
    local_f4 = oid;
    local_f0 = oid;
    local_ec = oid;
    local_e8 = oid;
    local_e4 = oid;
    local_e0 = oid;
    local_dc = oid;
    local_d8 = oid;
    local_d4 = oid;
    local_d0 = oid;
    local_cc = oid;
    local_c8 = oid;
    local_c4 = oid;
    local_c0 = oid;
    goto LAB_0003d5be;
  }
  oid = (X509 *)0x0;
  iVar24 = 6;
  local_5c = (ASN1_STRING *)0x0;
  st = (X509 *)0x0;
  local_84 = (ASN1_STRING *)0x0;
  pXVar16 = (X509 *)0x0;
  local_98 = (X509 *)0x0;
  local_e8 = (X509 *)0x0;
  local_e4 = (X509 *)0x0;
  local_d8 = (X509 *)0x0;
  local_74 = (EVP_MD *)0x0;
  local_c4 = (X509 *)0x0;
  local_c8 = (X509 *)0x0;
  local_dc = (X509 *)0x0;
  local_64 = (X509 *)0x0;
  local_78 = (X509 *)0x0;
  local_7c = (X509 *)0x0;
  local_80 = (X509 *)0x0;
  local_ec = (X509 *)0x0;
  local_68 = (X509 *)0x0;
  local_9c = (X509 *)0x0;
  bVar3 = false;
  bVar2 = false;
  local_a8 = (EVP_CIPHER *)0x0;
  local_8c = (X509 *)0x0;
  local_90 = (X509 *)0x0;
  local_f0 = (X509 *)0x0;
  local_d4 = (X509 *)0x0;
  local_f4 = (X509 *)0x0;
  local_f8 = (X509 *)0x0;
  local_e0 = (X509 *)0x0;
  local_bc = (X509 *)0x0;
  local_d0 = (X509 *)0x0;
  local_a0 = (X509 *)0x0;
  local_cc = (X509 *)0x0;
  local_94 = 6;
  local_a4 = 6;
  local_88 = 3;
  local_b4 = -1;
  local_b8 = 0x40;
LAB_0003cf94:
  pXVar19 = local_48;
  if (local_48 == (X509 *)0x0) {
LAB_0003cf9c:
    ppXVar17 = local_50;
    pXVar22 = *local_50;
    if ((pXVar22 == (X509 *)0x0) || (*(char *)&pXVar22->cert_info != '-')) goto LAB_0003d224;
    iVar4 = strcmp((char *)pXVar22,"-encrypt");
    iVar6 = local_b4;
    if (iVar4 == 0) {
      pXVar16 = (X509 *)0x11;
    }
    else {
      iVar4 = strcmp((char *)pXVar22,"-decrypt");
      if (iVar4 == 0) {
        pXVar16 = (X509 *)0x22;
      }
      else {
        iVar4 = strcmp((char *)pXVar22,"-sign");
        if (iVar4 == 0) {
          pXVar16 = (X509 *)0x53;
        }
        else {
          iVar4 = strcmp((char *)pXVar22,"-sign_receipt");
          if (iVar4 == 0) {
            pXVar16 = (X509 *)0x3f;
          }
          else {
            iVar4 = strcmp((char *)pXVar22,"-resign");
            if (iVar4 == 0) {
              pXVar16 = (X509 *)0x76;
            }
            else {
              iVar4 = strcmp((char *)pXVar22,"-verify");
              if (iVar4 == 0) {
                pXVar16 = (X509 *)&DAT_00000024;
              }
              else {
                iVar4 = strcmp((char *)pXVar22,"-verify_retcode");
                if (iVar4 == 0) {
                  local_9c = (X509 *)0x1;
                }
                else {
                  iVar4 = strcmp((char *)pXVar22,"-verify_receipt");
                  if (iVar4 == 0) {
                    local_d0 = ppXVar17[1];
                    if (local_d0 == (X509 *)0x0) goto LAB_0003d2ac;
                    pXVar16 = (X509 *)0x30;
                    ppXVar17 = ppXVar17 + 1;
                  }
                  else {
                    iVar4 = strcmp((char *)pXVar22,"-cmsout");
                    if (iVar4 == 0) {
                      pXVar16 = (X509 *)0x35;
                    }
                    else {
                      iVar4 = strcmp((char *)pXVar22,"-data_out");
                      if (iVar4 == 0) {
                        pXVar16 = (X509 *)0x27;
                      }
                      else {
                        iVar4 = strcmp((char *)pXVar22,"-data_create");
                        if (iVar4 == 0) {
                          pXVar16 = (X509 *)0x18;
                        }
                        else {
                          iVar4 = strcmp((char *)pXVar22,"-digest_verify");
                          if (iVar4 == 0) {
                            pXVar16 = (X509 *)0x29;
                          }
                          else {
                            iVar4 = strcmp((char *)pXVar22,"-digest_create");
                            if (iVar4 == 0) {
                              pXVar16 = (X509 *)0x1a;
                            }
                            else {
                              iVar4 = strcmp((char *)pXVar22,"-compress");
                              if (iVar4 == 0) {
                                pXVar16 = (X509 *)0x1c;
                              }
                              else {
                                iVar4 = strcmp((char *)pXVar22,"-uncompress");
                                if (iVar4 == 0) {
                                  pXVar16 = (X509 *)0x2b;
                                }
                                else {
                                  iVar4 = strcmp((char *)pXVar22,"-EncryptedData_decrypt");
                                  if (iVar4 == 0) {
                                    pXVar16 = (X509 *)0x2d;
                                  }
                                  else {
                                    iVar4 = strcmp((char *)pXVar22,"-EncryptedData_encrypt");
                                    if (iVar4 == 0) {
                                      pXVar16 = (X509 *)0x1e;
                                    }
                                    else {
                                      iVar4 = strcmp((char *)pXVar22,"-des3");
                                      if (iVar4 == 0) {
                                        local_a8 = EVP_des_ede3_cbc();
                                        ppXVar17 = local_50;
                                        pXVar19 = local_48;
                                      }
                                      else {
                                        iVar4 = strcmp((char *)pXVar22,"-des");
                                        if (iVar4 == 0) {
                                          local_a8 = EVP_des_cbc();
                                          ppXVar17 = local_50;
                                          pXVar19 = local_48;
                                        }
                                        else {
                                          iVar4 = strcmp((char *)pXVar22,"-seed");
                                          if (iVar4 == 0) {
                                            local_a8 = EVP_seed_cbc();
                                            ppXVar17 = local_50;
                                            pXVar19 = local_48;
                                          }
                                          else {
                                            iVar4 = strcmp((char *)pXVar22,"-rc2-40");
                                            if (iVar4 == 0) {
                                              local_a8 = EVP_rc2_40_cbc();
                                              ppXVar17 = local_50;
                                              pXVar19 = local_48;
                                            }
                                            else {
                                              iVar4 = strcmp((char *)pXVar22,"-rc2-128");
                                              if (iVar4 == 0) {
                                                local_a8 = EVP_rc2_cbc();
                                                ppXVar17 = local_50;
                                                pXVar19 = local_48;
                                              }
                                              else {
                                                iVar4 = strcmp((char *)pXVar22,"-rc2-64");
                                                if (iVar4 == 0) {
                                                  local_a8 = EVP_rc2_64_cbc();
                                                  ppXVar17 = local_50;
                                                  pXVar19 = local_48;
                                                }
                                                else {
                                                  iVar4 = strcmp((char *)pXVar22,"-aes128");
                                                  if (iVar4 == 0) {
                                                    local_a8 = EVP_aes_128_cbc();
                                                    ppXVar17 = local_50;
                                                    pXVar19 = local_48;
                                                  }
                                                  else {
                                                    iVar4 = strcmp((char *)pXVar22,"-aes192");
                                                    if (iVar4 == 0) {
                                                      local_a8 = EVP_aes_192_cbc();
                                                      ppXVar17 = local_50;
                                                      pXVar19 = local_48;
                                                    }
                                                    else {
                                                      iVar4 = strcmp((char *)pXVar22,"-aes256");
                                                      if (iVar4 == 0) {
                                                        local_a8 = EVP_aes_256_cbc();
                                                        ppXVar17 = local_50;
                                                        pXVar19 = local_48;
                                                      }
                                                      else {
                                                        iVar4 = strcmp((char *)pXVar22,
                                                                       "-camellia128");
                                                        if (iVar4 == 0) {
                                                          local_a8 = EVP_camellia_128_cbc();
                                                          ppXVar17 = local_50;
                                                          pXVar19 = local_48;
                                                        }
                                                        else {
                                                          iVar4 = strcmp((char *)pXVar22,
                                                                         "-camellia192");
                                                          if (iVar4 == 0) {
                                                            local_a8 = EVP_camellia_192_cbc();
                                                            ppXVar17 = local_50;
                                                            pXVar19 = local_48;
                                                          }
                                                          else {
                                                            iVar4 = strcmp((char *)pXVar22,
                                                                           "-camellia256");
                                                            if (iVar4 == 0) {
                                                              local_a8 = EVP_camellia_256_cbc();
                                                              ppXVar17 = local_50;
                                                              pXVar19 = local_48;
                                                            }
                                                            else {
                                                              iVar4 = strcmp((char *)pXVar22,
                                                                             "-debug_decrypt");
                                                              if (iVar4 == 0) {
                                                                local_b8 = local_b8 | 0x20000;
                                                              }
                                                              else {
                                                                iVar4 = strcmp((char *)pXVar22,
                                                                               "-text");
                                                                if (iVar4 == 0) {
                                                                  local_b8 = local_b8 | 1;
                                                                }
                                                                else {
                                                                  iVar4 = strcmp((char *)pXVar22,
                                                                                 "-nointern");
                                                                  if (iVar4 == 0) {
                                                                    local_b8 = local_b8 | 0x10;
                                                                  }
                                                                  else {
                                                                    iVar4 = strcmp((char *)pXVar22,
                                                                                   "-noverify");
                                                                    if ((iVar4 == 0) ||
                                                                       (iVar4 = strcmp((char *)
                                                  pXVar22,"-no_signer_cert_verify"), iVar4 == 0)) {
                                                    local_b8 = local_b8 | 0x20;
                                                  }
                                                  else {
                                                    iVar4 = strcmp((char *)pXVar22,"-nocerts");
                                                    if (iVar4 == 0) {
                                                      local_b8 = local_b8 | 2;
                                                    }
                                                    else {
                                                      iVar4 = strcmp((char *)pXVar22,"-noattr");
                                                      if (iVar4 == 0) {
                                                        local_b8 = local_b8 | 0x100;
                                                      }
                                                      else {
                                                        iVar4 = strcmp((char *)pXVar22,"-nodetach");
                                                        if (iVar4 == 0) {
                                                          local_b8 = local_b8 & 0xffffffbf;
                                                        }
                                                        else {
                                                          iVar4 = strcmp((char *)pXVar22,
                                                                         "-nosmimecap");
                                                          if (iVar4 == 0) {
                                                            local_b8 = local_b8 | 0x200;
                                                          }
                                                          else {
                                                            iVar4 = strcmp((char *)pXVar22,"-binary"
                                                                          );
                                                            if (iVar4 == 0) {
                                                              local_b8 = local_b8 | 0x80;
                                                            }
                                                            else {
                                                              iVar4 = strcmp((char *)pXVar22,
                                                                             "-keyid");
                                                              if (iVar4 == 0) {
                                                                local_b8 = local_b8 | 0x10000;
                                                              }
                                                              else {
                                                                iVar4 = strcmp((char *)pXVar22,
                                                                               "-nosigs");
                                                                if (iVar4 == 0) {
                                                                  local_b8 = local_b8 | 0xc;
                                                                }
                                                                else {
                                                                  iVar4 = strcmp((char *)pXVar22,
                                                                                                                                                                  
                                                  "-no_content_verify");
                                                  if (iVar4 == 0) {
                                                    local_b8 = local_b8 | 4;
                                                  }
                                                  else {
                                                    iVar4 = strcmp((char *)pXVar22,"-no_attr_verify"
                                                                  );
                                                    if (iVar4 == 0) {
                                                      local_b8 = local_b8 | 8;
                                                    }
                                                    else {
                                                      iVar4 = strcmp((char *)pXVar22,"-stream");
                                                      if (iVar4 == 0) {
                                                        local_b8 = local_b8 | 0x1000;
                                                      }
                                                      else {
                                                        iVar4 = strcmp((char *)pXVar22,"-indef");
                                                        if (iVar4 == 0) {
                                                          local_b8 = local_b8 | 0x1000;
                                                        }
                                                        else {
                                                          iVar4 = strcmp((char *)pXVar22,"-noindef")
                                                          ;
                                                          if (iVar4 == 0) {
                                                            local_b8 = local_b8 & 0xffffefff;
                                                          }
                                                          else {
                                                            iVar4 = strcmp((char *)pXVar22,
                                                                           "-nooldmime");
                                                            if (iVar4 == 0) {
                                                              local_b8 = local_b8 | 0x400;
                                                            }
                                                            else {
                                                              iVar4 = strcmp((char *)pXVar22,
                                                                             "-crlfeol");
                                                              if (iVar4 == 0) {
                                                                local_b8 = local_b8 | 0x800;
                                                              }
                                                              else {
                                                                iVar4 = strcmp((char *)pXVar22,
                                                                               "-noout");
                                                                if (iVar4 == 0) {
                                                                  bVar2 = true;
                                                                }
                                                                else {
                                                                  iVar4 = strcmp((char *)pXVar22,
                                                                                                                                                                  
                                                  "-receipt_request_print");
                                                  if (iVar4 == 0) {
                                                    local_68 = (X509 *)0x1;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)pXVar22,
                                                                   "-receipt_request_all");
                                                    if (iVar6 != 0) {
                                                      iVar6 = strcmp((char *)pXVar22,
                                                                     "-receipt_request_first");
                                                      if (iVar6 == 0) {
                                                        local_b4 = 1;
                                                        iVar6 = local_b4;
                                                      }
                                                      else {
                                                        iVar6 = strcmp((char *)pXVar22,
                                                                       "-receipt_request_from");
                                                        if (iVar6 == 0) {
                                                          if (ppXVar17[1] == (X509 *)0x0)
                                                          goto LAB_0003d2ac;
                                                          local_50 = ppXVar17 + 1;
                                                          if (st == (X509 *)0x0) {
                                                            st = (X509 *)sk_new_null();
                                                          }
                                                          sk_push((_STACK *)st,*local_50);
                                                          ppXVar17 = local_50;
                                                          pXVar19 = local_48;
                                                          iVar6 = local_b4;
                                                        }
                                                        else {
                                                          iVar6 = strcmp((char *)pXVar22,
                                                                         "-receipt_request_to");
                                                          if (iVar6 == 0) {
                                                            if (ppXVar17[1] == (X509 *)0x0)
                                                            goto LAB_0003d2ac;
                                                            local_50 = ppXVar17 + 1;
                                                            if (local_ec == (X509 *)0x0) {
                                                              local_ec = (X509 *)sk_new_null();
                                                            }
                                                            sk_push((_STACK *)local_ec,*local_50);
                                                            ppXVar17 = local_50;
                                                            pXVar19 = local_48;
                                                            iVar6 = local_b4;
                                                          }
                                                          else {
                                                            iVar6 = strcmp((char *)pXVar22,"-print")
                                                            ;
                                                            if (iVar6 == 0) {
                                                              bVar3 = true;
                                                              bVar2 = true;
                                                              iVar6 = local_b4;
                                                            }
                                                            else {
                                                              iVar6 = strcmp((char *)pXVar22,
                                                                             "-secretkey");
                                                              if (iVar6 == 0) {
                                                                if (ppXVar17[1] == (X509 *)0x0)
                                                                goto LAB_0003d2ac;
                                                                local_50 = ppXVar17 + 1;
                                                                local_e4 = (X509 *)string_to_hex((
                                                  char *)ppXVar17[1],(long *)local_2c);
                                                  if (local_e4 == (X509 *)0x0) {
                                                    BIO_printf(bio_err,"Invalid key %s\n",*local_50)
                                                    ;
                                                    goto LAB_0003d2ac;
                                                  }
                                                  local_84 = local_2c[0];
                                                  ppXVar17 = local_50;
                                                  pXVar19 = local_48;
                                                  iVar6 = local_b4;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)pXVar22,"-secretkeyid");
                                                    if (iVar6 == 0) {
                                                      if (ppXVar17[1] == (X509 *)0x0)
                                                      goto LAB_0003d2ac;
                                                      local_50 = ppXVar17 + 1;
                                                      local_e8 = (X509 *)string_to_hex((char *)
                                                  ppXVar17[1],(long *)local_2c);
                                                  if (local_e8 == (X509 *)0x0) {
                                                    BIO_printf(bio_err,"Invalid id %s\n",*local_50);
                                                    goto LAB_0003d2ac;
                                                  }
                                                  local_5c = local_2c[0];
                                                  ppXVar17 = local_50;
                                                  pXVar19 = local_48;
                                                  iVar6 = local_b4;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)pXVar22,"-pwri_password")
                                                    ;
                                                    if (iVar6 == 0) {
                                                      local_98 = ppXVar17[1];
                                                      pXVar22 = local_98;
                                                      goto joined_r0x0003ecf8;
                                                    }
                                                    iVar6 = strcmp((char *)pXVar22,"-econtent_type")
                                                    ;
                                                    if (iVar6 == 0) {
                                                      if (ppXVar17[1] == (X509 *)0x0)
                                                      goto LAB_0003d2ac;
                                                      local_50 = ppXVar17 + 1;
                                                      oid = (X509 *)OBJ_txt2obj((char *)ppXVar17[1],
                                                                                0);
                                                      ppXVar17 = local_50;
                                                      pXVar19 = local_48;
                                                      iVar6 = local_b4;
                                                      if (oid == (X509 *)0x0) {
                                                        BIO_printf(bio_err,"Invalid OID %s\n",
                                                                   *local_50);
                                                        goto LAB_0003d2ac;
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp((char *)pXVar22,"-rand");
                                                      if (iVar6 == 0) {
                                                        local_c8 = ppXVar17[1];
                                                        if (local_c8 == (X509 *)0x0)
                                                        goto LAB_0003d2ac;
                                                        local_c4 = (X509 *)0x1;
                                                        ppXVar17 = ppXVar17 + 1;
                                                        iVar6 = local_b4;
                                                      }
                                                      else {
                                                        iVar6 = strcmp((char *)pXVar22,"-engine");
                                                        if (iVar6 == 0) {
                                                          local_d8 = ppXVar17[1];
                                                          pXVar22 = local_d8;
                                                        }
                                                        else {
                                                          iVar6 = strcmp((char *)pXVar22,"-passin");
                                                          if (iVar6 == 0) {
                                                            local_dc = ppXVar17[1];
                                                            pXVar22 = local_dc;
                                                          }
                                                          else {
                                                            cVar1 = *(char *)((int)&pXVar22->
                                                  cert_info + 1);
                                                  if (((cVar1 == 't') &&
                                                      (*(char *)((int)&pXVar22->cert_info + 2) ==
                                                       'o')) &&
                                                     (*(char *)((int)&pXVar22->cert_info + 3) ==
                                                      '\0')) {
                                                    local_80 = ppXVar17[1];
                                                    pXVar22 = local_80;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)pXVar22,"-from");
                                                    if (iVar6 == 0) {
                                                      local_7c = ppXVar17[1];
                                                      pXVar22 = local_7c;
                                                    }
                                                    else {
                                                      iVar6 = strcmp((char *)pXVar22,"-subject");
                                                      if (iVar6 == 0) {
                                                        local_78 = ppXVar17[1];
                                                        pXVar22 = local_78;
                                                      }
                                                      else {
                                                        iVar6 = strcmp((char *)pXVar22,"-signer");
                                                        if (iVar6 == 0) {
                                                          if (ppXVar17[1] != (X509 *)0x0) {
                                                            if (local_bc != (X509 *)0x0) {
                                                              if (local_f8 == (X509 *)0x0) {
                                                                local_f8 = (X509 *)sk_new_null();
                                                              }
                                                              sk_push((_STACK *)local_f8,local_bc);
                                                              if (local_f0 == (X509 *)0x0) {
                                                                local_f0 = local_bc;
                                                              }
                                                              if (local_f4 == (X509 *)0x0) {
                                                                local_f4 = (X509 *)sk_new_null();
                                                              }
                                                              sk_push((_STACK *)local_f4,local_f0);
                                                              local_f0 = (X509 *)0x0;
                                                              ppXVar17 = local_50;
                                                            }
                                                            local_bc = ppXVar17[1];
                                                            ppXVar17 = ppXVar17 + 1;
                                                            pXVar19 = local_48;
                                                            iVar6 = local_b4;
                                                            goto LAB_0003d218;
                                                          }
                                                          goto LAB_0003d2ac;
                                                        }
                                                        iVar6 = strcmp((char *)pXVar22,"-recip");
                                                        if (iVar6 == 0) {
                                                          local_e0 = ppXVar17[1];
                                                          pXVar22 = local_e0;
                                                        }
                                                        else {
                                                          iVar6 = strcmp((char *)pXVar22,"-certsout"
                                                                        );
                                                          if (iVar6 == 0) {
                                                            local_8c = ppXVar17[1];
                                                            pXVar22 = local_8c;
                                                          }
                                                          else {
                                                            if (((cVar1 == 'm') &&
                                                                (*(char *)((int)&pXVar22->cert_info
                                                                          + 2) == 'd')) &&
                                                               (*(char *)((int)&pXVar22->cert_info +
                                                                         3) == '\0')) {
                                                              if (ppXVar17[1] != (X509 *)0x0) {
                                                                local_50 = ppXVar17 + 1;
                                                                local_74 = EVP_get_digestbyname
                                                                                     ((char *)
                                                  ppXVar17[1]);
                                                  ppXVar17 = local_50;
                                                  pXVar19 = local_48;
                                                  iVar6 = local_b4;
                                                  if (local_74 != (EVP_MD *)0x0) goto LAB_0003d218;
                                                  BIO_printf(bio_err,"Unknown digest %s\n",*local_50
                                                            );
                                                  }
                                                  goto LAB_0003d2ac;
                                                  }
                                                  iVar6 = strcmp((char *)pXVar22,"-inkey");
                                                  if (iVar6 == 0) {
                                                    if (ppXVar17[1] == (X509 *)0x0)
                                                    goto LAB_0003d2ac;
                                                    if (local_f0 != (X509 *)0x0) {
                                                      if (local_bc == (X509 *)0x0)
                                                      goto LAB_0003d70c;
                                                      if (local_f8 == (X509 *)0x0) {
                                                        local_f8 = (X509 *)sk_new_null();
                                                      }
                                                      sk_push((_STACK *)local_f8,local_bc);
                                                      if (local_f4 == (X509 *)0x0) {
                                                        local_f4 = (X509 *)sk_new_null();
                                                      }
                                                      sk_push((_STACK *)local_f4,local_f0);
                                                      local_bc = (X509 *)0x0;
                                                      ppXVar17 = local_50;
                                                    }
                                                    local_f0 = ppXVar17[1];
                                                    ppXVar17 = ppXVar17 + 1;
                                                    pXVar19 = local_48;
                                                    iVar6 = local_b4;
                                                    goto LAB_0003d218;
                                                  }
                                                  iVar6 = strcmp((char *)pXVar22,"-keyform");
                                                  if (iVar6 == 0) {
                                                    if (ppXVar17[1] == (X509 *)0x0)
                                                    goto LAB_0003d2ac;
                                                    local_50 = ppXVar17 + 1;
                                                    local_88 = str2fmt();
                                                    ppXVar17 = local_50;
                                                    pXVar19 = local_48;
                                                    iVar6 = local_b4;
                                                    goto LAB_0003d218;
                                                  }
                                                  iVar6 = strcmp((char *)pXVar22,"-rctform");
                                                  if (iVar6 == 0) {
                                                    if (ppXVar17[1] == (X509 *)0x0)
                                                    goto LAB_0003d2ac;
                                                    local_50 = ppXVar17 + 1;
                                                    iVar24 = str2fmt();
                                                    ppXVar17 = local_50;
                                                    pXVar19 = local_48;
                                                    iVar6 = local_b4;
                                                    goto LAB_0003d218;
                                                  }
                                                  iVar6 = strcmp((char *)pXVar22,"-certfile");
                                                  if (iVar6 == 0) {
                                                    local_d4 = ppXVar17[1];
                                                    pXVar22 = local_d4;
                                                    goto joined_r0x0003ecf8;
                                                  }
                                                  iVar6 = strcmp((char *)pXVar22,"-CAfile");
                                                  if (iVar6 == 0) {
                                                    local_64 = ppXVar17[1];
                                                    pXVar22 = local_64;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)pXVar22,"-CApath");
                                                    if (iVar6 == 0) {
                                                      pXVar22 = ppXVar17[1];
                                                    }
                                                    else if (((cVar1 == 'i') &&
                                                             (*(char *)((int)&pXVar22->cert_info + 2
                                                                       ) == 'n')) &&
                                                            (*(char *)((int)&pXVar22->cert_info + 3)
                                                             == '\0')) {
                                                      local_cc = ppXVar17[1];
                                                      pXVar22 = local_cc;
                                                    }
                                                    else {
                                                      iVar6 = strcmp((char *)pXVar22,"-inform");
                                                      if (iVar6 == 0) {
                                                        if (ppXVar17[1] == (X509 *)0x0)
                                                        goto LAB_0003d2ac;
                                                        local_50 = ppXVar17 + 1;
                                                        local_a4 = str2fmt();
                                                        ppXVar17 = local_50;
                                                        pXVar19 = local_48;
                                                        iVar6 = local_b4;
                                                        goto LAB_0003d218;
                                                      }
                                                      iVar6 = strcmp((char *)pXVar22,"-outform");
                                                      if (iVar6 == 0) {
                                                        if (ppXVar17[1] != (X509 *)0x0) {
                                                          local_50 = ppXVar17 + 1;
                                                          local_94 = str2fmt();
                                                          ppXVar17 = local_50;
                                                          pXVar19 = local_48;
                                                          iVar6 = local_b4;
                                                          goto LAB_0003d218;
                                                        }
                                                        goto LAB_0003d2ac;
                                                      }
                                                      iVar6 = strcmp((char *)pXVar22,"-out");
                                                      if (iVar6 != 0) {
                                                        iVar6 = strcmp((char *)pXVar22,"-content");
                                                        if (iVar6 == 0) {
                                                          local_90 = ppXVar17[1];
                                                          pXVar22 = local_90;
                                                          goto joined_r0x0003ecf8;
                                                        }
                                                        iVar6 = args_verify(&local_50,0,&local_48,
                                                                            bio_err,&local_40);
                                                        if (iVar6 == 0) {
                                                          local_a8 = EVP_get_cipherbyname
                                                                               ((char *)((int)&(*
                                                  local_50)->cert_info + 1));
                                                  ppXVar17 = local_50;
                                                  pXVar19 = local_48;
                                                  iVar6 = local_b4;
                                                  if (local_a8 == (EVP_CIPHER *)0x0) {
                                                    local_48 = (X509 *)0x1;
                                                    pXVar19 = (X509 *)0x1;
                                                  }
                                                  goto LAB_0003d218;
                                                  }
                                                  goto LAB_0003cf94;
                                                  }
                                                  local_a0 = ppXVar17[1];
                                                  pXVar22 = local_a0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
joined_r0x0003ecf8:
                                                  if (pXVar22 == (X509 *)0x0) goto LAB_0003d2ac;
                                                  ppXVar17 = ppXVar17 + 1;
                                                  iVar6 = local_b4;
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
LAB_0003d218:
    local_b4 = iVar6;
    local_50 = ppXVar17 + 1;
    if (pXVar19 != (X509 *)0x0) goto LAB_0003d224;
    goto LAB_0003cf9c;
  }
LAB_0003d224:
  pXVar18 = st;
  if (st != (X509 *)0x0) {
    pXVar18 = (X509 *)0x1;
  }
  if ((st == (X509 *)0x0 && local_b4 == -1) || (local_ec != (X509 *)0x0)) {
    pXVar22 = (X509 *)((uint)pXVar16 & 0x40);
    if (pXVar22 != (X509 *)0x0) {
      uVar15 = count_leading_zeroes(local_bc);
      uVar15 = uVar15 >> 5;
      if (local_f0 == (X509 *)0x0) {
        uVar15 = 0;
      }
      if (uVar15 == 0) {
        if (local_bc != (X509 *)0x0) {
          if (local_f8 == (X509 *)0x0) {
            local_f8 = (X509 *)sk_new_null();
          }
          sk_push((_STACK *)local_f8,local_bc);
          if (local_f4 == (X509 *)0x0) {
            local_f4 = (X509 *)sk_new_null();
          }
          if (local_f0 == (X509 *)0x0) {
            local_f0 = local_bc;
          }
          sk_push((_STACK *)local_f4,local_f0);
        }
        if (local_f8 == (X509 *)0x0) {
          BIO_printf(bio_err,"No signer certificate specified\n");
          local_c4 = (X509 *)0x1;
          goto LAB_0003d6dc;
        }
        local_f0 = (X509 *)0x0;
        local_bc = (X509 *)0x0;
        local_c4 = (X509 *)0x1;
        pXVar19 = local_48;
        pXVar23 = local_f4;
        goto LAB_0003d2a6;
      }
LAB_0003d70c:
      BIO_puts(bio_err,"Illegal -inkey without -signer\n");
      goto LAB_0003d2ac;
    }
    pXVar23 = pXVar18;
    if (local_ec != (X509 *)0x0) {
      pXVar23 = (X509 *)((uint)pXVar18 | 1);
    }
    if (pXVar23 != (X509 *)0x0) {
      BIO_puts(bio_err,"Signed receipts only allowed with -sign\n");
      goto LAB_0003d2ac;
    }
    if (local_f4 != (X509 *)0x0 || local_f8 != (X509 *)0x0) {
      BIO_puts(bio_err,"Multiple signers or keys not allowed\n");
      st = pXVar23;
      local_ec = pXVar23;
      goto LAB_0003d2ac;
    }
    local_f8 = pXVar22;
    pXVar23 = pXVar22;
    if (pXVar16 == (X509 *)0x22) {
      if ((local_f0 == (X509 *)0x0 && local_e0 == (X509 *)0x0) &&
         (local_f0 = pXVar22, local_98 == (X509 *)0x0 && local_e4 == (X509 *)0x0)) {
        local_f4 = (X509 *)0x0;
        BIO_printf(bio_err,"No recipient certificate or key specified\n");
        goto LAB_0003d6dc;
      }
    }
    else if (pXVar16 == (X509 *)0x11) {
      local_f4 = *local_50;
      if ((local_f4 == (X509 *)0x0) && (local_e4 == (X509 *)0x0 && local_98 == (X509 *)0x0)) {
        BIO_printf(bio_err,"No recipient(s) certificate(s) specified\n");
        local_c4 = (X509 *)0x1;
        goto LAB_0003d6dc;
      }
      local_c4 = (X509 *)0x1;
    }
    else {
      local_f4 = pXVar16;
      if (pXVar16 == (X509 *)0x0) {
LAB_0003d6dc:
        local_48 = (X509 *)0x1;
        local_f8 = (X509 *)0x0;
        goto LAB_0003d2ac;
      }
    }
LAB_0003d2a6:
    local_f4 = pXVar23;
    if (pXVar19 != (X509 *)0x0) goto LAB_0003d2ac;
    uVar5 = setup_engine(bio_err,local_d8,0);
    iVar6 = app_passwd(bio_err,local_dc,0,&local_44,0);
    if (iVar6 == 0) {
      pcVar14 = "Error getting password\n";
      goto LAB_0003d56a;
    }
    if (local_c4 != (X509 *)0x0) {
      pXVar19 = local_c8;
      if (local_c8 != (X509 *)0x0) {
        pXVar19 = (X509 *)0x1;
      }
      app_RAND_load_file(0,bio_err,pXVar19);
      pBVar11 = bio_err;
      if (pXVar19 != (X509 *)0x0) {
        uVar7 = app_RAND_load_files(local_c8);
        BIO_printf(pBVar11,"%ld semi-random bytes loaded\n",uVar7);
      }
    }
    if (pXVar22 == (X509 *)0x0) {
      local_b8 = local_b8 & 0xffffffbf;
    }
    if ((int)pXVar16 << 0x1b < 0) {
      local_d8 = (X509 *)"w";
      if (local_94 == 1) {
        local_d8 = (X509 *)"wb";
      }
    }
    else {
      local_d8 = (X509 *)"wb";
      if ((local_b8 & 0x80) == 0) {
        local_d8 = (X509 *)"w";
      }
    }
    pXVar23 = (X509 *)((uint)pXVar16 & 0x20);
    if (pXVar23 == (X509 *)0x0) {
      pcVar14 = "rb";
      if ((local_b8 & 0x80) == 0) {
        pcVar14 = "r";
      }
      local_c0 = pXVar23;
      if (pXVar16 != (X509 *)0x11) goto LAB_0003d7b6;
      if (local_a8 == (EVP_CIPHER *)0x0) {
        local_a8 = EVP_des_ede3_cbc();
      }
      uVar15 = count_leading_zeroes(local_e8);
      uVar15 = uVar15 >> 5;
      if (local_e4 == (X509 *)0x0) {
        uVar15 = 0;
      }
      if (uVar15 == 0) {
        local_c0 = *local_50;
        if (local_c0 != (X509 *)0x0) {
          local_c0 = (X509 *)sk_new_null();
          pXVar19 = *local_50;
          while (pXVar19 != (X509 *)0x0) {
            pXVar19 = (X509 *)load_cert(bio_err,pXVar19,3,0,uVar5,"recipient certificate file");
            if (pXVar19 == (X509 *)0x0) {
              local_68 = (X509 *)0x2;
              pXVar22 = pXVar19;
              pXVar23 = pXVar19;
              bp = pXVar19;
              local_f0 = pXVar19;
              local_e0 = pXVar19;
              local_dc = pXVar19;
              local_d8 = pXVar19;
              local_d4 = pXVar19;
              local_d0 = pXVar19;
              local_cc = pXVar19;
              local_c8 = pXVar19;
              goto LAB_0003d5be;
            }
            sk_push((_STACK *)local_c0,pXVar19);
            pXVar19 = local_50[1];
            local_50 = local_50 + 1;
          }
        }
        goto LAB_0003d7b6;
      }
      local_e8 = (X509 *)0x0;
      BIO_printf(bio_err,"No secret key id\n");
      local_cc = (X509 *)0x0;
      local_d4 = (X509 *)0x0;
      local_c0 = (X509 *)0x0;
LAB_0003dbda:
      local_68 = (X509 *)0x2;
      pXVar19 = local_cc;
      pXVar22 = local_cc;
      pXVar23 = local_cc;
      bp = local_cc;
      local_f0 = local_cc;
      local_e0 = local_cc;
      local_dc = local_cc;
      local_d8 = local_cc;
      local_d0 = local_cc;
      local_c8 = local_cc;
    }
    else {
      pcVar14 = "rb";
      if (local_a4 != 1) {
        pcVar14 = "r";
      }
      local_c0 = (X509 *)0x0;
LAB_0003d7b6:
      if ((local_d4 != (X509 *)0x0) &&
         (local_d4 = (X509 *)load_certs(bio_err,local_d4,3,0,uVar5,"certificate file"),
         local_d4 == (X509 *)0x0)) {
        ERR_print_errors(bio_err);
        local_cc = local_d4;
        goto LAB_0003dbda;
      }
      uVar15 = count_leading_zeroes((undefined *)((int)&pXVar16[-1].nc + 2));
      pXVar19 = (X509 *)(uVar15 >> 5);
      if (local_e0 == (X509 *)0x0) {
        local_c8 = (X509 *)0x0;
      }
      else {
        local_c8 = (X509 *)((uint)pXVar19 & 1);
      }
      if (local_c8 == (X509 *)0x0) {
        if (pXVar16 == (X509 *)0x3f) {
          local_dc = (X509 *)load_cert(bio_err,local_bc,3,0,uVar5,"receipt signer certificate file")
          ;
          if (local_dc == (X509 *)0x0) {
            ERR_print_errors(bio_err);
            local_cc = local_dc;
            goto LAB_0003dbda;
          }
LAB_0003db16:
          if (local_f0 == (X509 *)0x0) {
            local_c8 = (X509 *)0x0;
            local_f0 = local_bc;
            goto joined_r0x0003deba;
          }
          local_c8 = (X509 *)0x0;
          goto LAB_0003db22;
        }
        if (pXVar19 != (X509 *)0x0) goto LAB_0003db8c;
        bp = pXVar19;
        local_dc = pXVar19;
        local_c8 = pXVar19;
        if (pXVar16 == (X509 *)0x53) goto LAB_0003db16;
      }
      else {
        local_c8 = (X509 *)load_cert(bio_err,local_e0,3,0,uVar5,"recipient certificate file");
        if (local_c8 == (X509 *)0x0) {
          local_68 = (X509 *)0x2;
          ERR_print_errors(bio_err);
          pXVar19 = local_c8;
          pXVar22 = local_c8;
          pXVar23 = local_c8;
          bp = local_c8;
          local_f0 = local_c8;
          local_e0 = local_c8;
          local_dc = local_c8;
          local_d8 = local_c8;
          local_d0 = local_c8;
          local_cc = local_c8;
          goto LAB_0003d5be;
        }
LAB_0003db8c:
        if (local_f0 == (X509 *)0x0) {
          local_dc = (X509 *)0x0;
          local_f0 = local_e0;
joined_r0x0003deba:
          bp = local_f0;
          if (local_f0 == (X509 *)0x0) goto LAB_0003d822;
        }
        else {
          local_dc = (X509 *)0x0;
        }
LAB_0003db22:
        bp = (X509 *)load_key(bio_err,local_f0,local_88,0,local_44,uVar5,"signing key file");
        if (bp == (X509 *)0x0) {
          local_68 = (X509 *)0x2;
          pXVar19 = bp;
          pXVar22 = bp;
          pXVar23 = bp;
          local_f0 = bp;
          local_e0 = bp;
          local_d8 = bp;
          local_d0 = bp;
          local_cc = bp;
          goto LAB_0003d5be;
        }
      }
LAB_0003d822:
      local_f0 = bp;
      pXVar9 = local_f0;
      if (local_cc == (X509 *)0x0) {
        local_e0 = (X509 *)BIO_new_fp(stdin,0);
LAB_0003d838:
        if (pXVar23 == (X509 *)0x0) {
LAB_0003daac:
          if (local_d0 == (X509 *)0x0) {
            local_cc = local_d0;
          }
          else {
            if (iVar24 == 1) {
              local_cc = (X509 *)BIO_new_file((char *)local_d0,"rb");
              if (local_cc == (X509 *)0x0) goto LAB_0003de8e;
              local_d0 = (X509 *)d2i_CMS_bio((BIO *)local_cc,(CMS_ContentInfo **)0x0);
            }
            else {
              local_cc = (X509 *)BIO_new_file((char *)local_d0,"r");
              if (local_cc == (X509 *)0x0) {
LAB_0003de8e:
                BIO_printf(bio_err,"Can\'t open receipt file %s\n",local_d0);
                bp = (X509 *)0x0;
                goto LAB_0003dea2;
              }
              if (iVar24 == 6) {
                local_d0 = (X509 *)SMIME_read_CMS((BIO *)local_cc,(BIO **)0x0);
              }
              else {
                if (iVar24 != 3) {
                  BIO_printf(bio_err,"Bad input format for receipt\n");
                  local_d8 = (X509 *)0x0;
                  local_d0 = (X509 *)0x0;
                  local_68 = (X509 *)0x2;
                  pXVar19 = (X509 *)0x0;
                  pXVar22 = (X509 *)0x0;
                  bp = (X509 *)0x0;
                  goto LAB_0003d5be;
                }
                local_d0 = (X509 *)PEM_read_bio_CMS((BIO *)local_cc,(CMS_ContentInfo **)0x0,
                                                    (undefined1 *)0x0,(void *)0x0);
              }
            }
            if (local_d0 == (X509 *)0x0) {
              local_68 = (X509 *)0x2;
              BIO_printf(bio_err,"Error reading receipt\n");
              local_d8 = local_d0;
              pXVar19 = local_d0;
              pXVar22 = local_d0;
              bp = local_d0;
              goto LAB_0003d5be;
            }
          }
          if (local_a0 == (X509 *)0x0) {
            bp = (X509 *)BIO_new_fp(stdout,0);
          }
          else {
            bp = (X509 *)BIO_new_file((char *)local_a0,(char *)local_d8);
            if (bp == (X509 *)0x0) {
              BIO_printf(bio_err,"Can\'t open output file %s\n",local_a0);
              local_68 = (X509 *)0x2;
              pXVar19 = bp;
              pXVar22 = bp;
              local_d8 = bp;
              goto LAB_0003d5be;
            }
          }
          uVar15 = count_leading_zeroes(&pXVar16[-1].nc);
          pXVar20 = (X509 *)(uVar15 >> 5);
          uVar21 = count_leading_zeroes(&pXVar16[-1].policy_cache);
          local_d8 = (X509 *)((uVar21 | uVar15) >> 5);
          if (local_d8 != (X509 *)0x0) {
            local_d8 = (X509 *)setup_verify(bio_err,local_64);
            if (local_d8 == (X509 *)0x0) {
              local_68 = (X509 *)0x2;
              pXVar19 = local_d8;
              pXVar22 = local_d8;
              goto LAB_0003d5be;
            }
            X509_STORE_set_verify_cb((X509_STORE *)local_d8,cms_cb + 1);
            if (local_40 != (X509_VERIFY_PARAM *)0x0) {
              X509_STORE_set1_param((X509_STORE *)local_d8,local_40);
            }
          }
          if (pXVar16 == (X509 *)0x18) {
            pXVar22 = (X509 *)0x0;
            pXVar23 = (X509 *)CMS_data_create((BIO *)local_e0,local_b8);
LAB_0003defc:
            if (pXVar23 == (X509 *)0x0) {
              BIO_printf(bio_err,"Error creating CMS structure\n");
              local_68 = (X509 *)0x3;
              pXVar19 = pXVar23;
              goto LAB_0003d5be;
            }
          }
          else {
            if (pXVar16 == (X509 *)0x1a) {
              pXVar22 = (X509 *)0x0;
              pXVar23 = (X509 *)CMS_digest_create((BIO *)local_e0,local_74,local_b8);
              goto LAB_0003defc;
            }
            if (pXVar16 == (X509 *)0x1c) {
              pXVar22 = (X509 *)0x0;
              pXVar23 = (X509 *)CMS_compress((BIO *)local_e0,-1,local_b8);
              goto LAB_0003defc;
            }
            if (pXVar16 != (X509 *)0x11) {
              if (pXVar16 == (X509 *)0x1e) {
                pXVar22 = (X509 *)0x0;
                pXVar23 = (X509 *)CMS_EncryptedData_encrypt
                                            ((BIO *)local_e0,local_a8,(uchar *)local_e4,
                                             (size_t)local_84,local_b8);
              }
              else {
                if (pXVar16 == (X509 *)0x3f) {
                  pXVar22 = (X509 *)CMS_get0_SignerInfos((CMS_ContentInfo *)pXVar23);
                  if (pXVar22 != (X509 *)0x0) {
                    si = (CMS_SignerInfo *)sk_value((_STACK *)pXVar22,0);
                    pXVar22 = (X509 *)CMS_sign_receipt(si,local_dc,(EVP_PKEY *)local_f0,
                                                       (stack_st_X509 *)local_d4,local_b8);
                    if (pXVar22 != (X509 *)0x0) {
                      CMS_ContentInfo_free((CMS_ContentInfo *)pXVar23);
                      uVar15 = local_b8;
                      pXVar23 = pXVar22;
                      goto LAB_0003e046;
                    }
                  }
                  local_68 = (X509 *)0x3;
                  pXVar19 = pXVar22;
                  goto LAB_0003d5be;
                }
                if (pXVar22 != (X509 *)0x0) {
                  if (pXVar16 == (X509 *)0x53) {
                    if (((int)(local_b8 << 0x19) < 0) && (local_94 == 6)) {
                      local_b8 = local_b8 | 0x1000;
                    }
                    local_b8 = local_b8 | 0x4000;
                    pXVar23 = (X509 *)CMS_sign((X509 *)0x0,(EVP_PKEY *)0x0,(stack_st_X509 *)local_d4
                                               ,(BIO *)local_e0,local_b8);
                    if (pXVar23 == (X509 *)0x0) goto LAB_0003e3c0;
                    if (oid != (X509 *)0x0) {
                      CMS_set1_eContentType((CMS_ContentInfo *)pXVar23,(ASN1_OBJECT *)oid);
                    }
                    pXVar22 = local_ec;
                    if ((local_ec != (X509 *)0x0) &&
                       ((iVar24 = make_names_stack(local_ec), iVar24 == 0 ||
                        (((pXVar18 != (X509 *)0x0 &&
                          (pXVar18 = (X509 *)make_names_stack(st), pXVar18 == (X509 *)0x0)) ||
                         (pXVar22 = (X509 *)CMS_ReceiptRequest_create0
                                                      (0,0xffffffff,local_b4,pXVar18,iVar24),
                         pXVar22 == (X509 *)0x0)))))) {
                      BIO_puts(bio_err,"Signed Receipt Request Creation Error\n");
                      local_68 = (X509 *)0x3;
                      pXVar19 = (X509 *)0x0;
                      pXVar22 = (X509 *)0x0;
                      goto LAB_0003d5be;
                    }
                  }
                  else {
                    local_b8 = local_b8 | 0x8000;
                    pXVar22 = (X509 *)0x0;
                  }
                  local_f0 = (X509 *)0x0;
                  while (iVar24 = sk_num((_STACK *)local_f8), (int)local_f0 < iVar24) {
                    local_bc = (X509 *)sk_value((_STACK *)local_f8,(int)local_f0);
                    pvVar12 = sk_value((_STACK *)local_f4,(int)local_f0);
                    local_f0 = (X509 *)((int)local_f0 + 1);
                    pXVar18 = (X509 *)load_cert(bio_err,local_bc,3,0,uVar5,"signer certificate");
                    local_dc = pXVar18;
                    if (pXVar18 == (X509 *)0x0) {
                      local_68 = (X509 *)0x3;
                      pXVar19 = pXVar18;
                      local_f0 = pXVar9;
                      goto LAB_0003d5be;
                    }
                    pXVar9 = (X509 *)load_key(bio_err,pvVar12,local_88,0,local_44,uVar5,
                                              "signing key file");
                    if (pXVar9 == (X509 *)0x0) {
                      local_68 = (X509 *)0x3;
                      pXVar19 = pXVar9;
                      local_f0 = pXVar9;
                      goto LAB_0003d5be;
                    }
                    pXVar10 = (X509 *)CMS_add1_signer((CMS_ContentInfo *)pXVar23,pXVar18,
                                                      (EVP_PKEY *)pXVar9,local_74,local_b8);
                    if (pXVar10 == (X509 *)0x0) {
                      local_68 = (X509 *)0x3;
                      pXVar19 = pXVar10;
                      local_f0 = pXVar9;
                      goto LAB_0003d5be;
                    }
                    if ((pXVar22 != (X509 *)0x0) &&
                       (pXVar10 = (X509 *)CMS_add1_ReceiptRequest(pXVar10,pXVar22),
                       pXVar10 == (X509 *)0x0)) {
                      local_68 = (X509 *)0x3;
                      pXVar19 = pXVar10;
                      local_f0 = pXVar9;
                      goto LAB_0003d5be;
                    }
                    local_dc = (X509 *)0x0;
                    X509_free(pXVar18);
                    EVP_PKEY_free((EVP_PKEY *)pXVar9);
                    pXVar9 = (X509 *)0x0;
                  }
                  local_f0 = pXVar9;
                  if (((pXVar16 == (X509 *)0x53) && ((local_b8 & 0x1000) == 0)) &&
                     (pXVar18 = (X509 *)CMS_final((CMS_ContentInfo *)pXVar23,(BIO *)local_e0,
                                                  (BIO *)0x0,local_b8), pXVar18 == (X509 *)0x0)) {
                    local_68 = (X509 *)0x3;
                    pXVar19 = pXVar18;
                    goto LAB_0003d5be;
                  }
                }
              }
              goto LAB_0003defc;
            }
            uVar15 = local_b8 | 0x4000;
            pXVar23 = (X509 *)CMS_encrypt((stack_st_X509 *)local_c0,(BIO *)local_e0,local_a8,uVar15)
            ;
            if (pXVar23 == (X509 *)0x0) {
LAB_0003e3c0:
              local_68 = (X509 *)0x3;
              pXVar19 = pXVar23;
              pXVar22 = pXVar23;
              goto LAB_0003d5be;
            }
            if (local_e4 != (X509 *)0x0) {
              pXVar22 = (X509 *)CMS_add0_recipient_key
                                          ((CMS_ContentInfo *)pXVar23,0,(uchar *)local_e4,
                                           (size_t)local_84,(uchar *)local_e8,(size_t)local_5c,
                                           (ASN1_GENERALIZEDTIME *)0x0,(ASN1_OBJECT *)0x0,
                                           (ASN1_TYPE *)0x0);
              if (pXVar22 == (X509 *)0x0) {
                local_68 = (X509 *)0x3;
                pXVar19 = pXVar22;
                goto LAB_0003d5be;
              }
              local_e8 = (X509 *)0x0;
            }
            if (local_98 != (X509 *)0x0) {
              pXVar22 = (X509 *)BUF_strdup((char *)local_98);
              if (pXVar22 == (X509 *)0x0) {
                local_68 = (X509 *)0x3;
                pXVar19 = pXVar22;
                local_e4 = pXVar22;
              }
              else {
                local_e4 = (X509 *)CMS_add0_recipient_password
                                             ((CMS_ContentInfo *)pXVar23,-1,0,0,(uchar *)pXVar22,-1,
                                              (EVP_CIPHER *)0x0);
                if (local_e4 != (X509 *)0x0) goto LAB_0003e038;
                local_68 = (X509 *)0x3;
                pXVar19 = pXVar22;
                pXVar22 = local_e4;
              }
              goto LAB_0003d5be;
            }
LAB_0003e038:
            local_e4 = (X509 *)(local_b8 & 0x1000);
            if (local_e4 == (X509 *)0x0) {
              pXVar22 = (X509 *)CMS_final((CMS_ContentInfo *)pXVar23,(BIO *)local_e0,(BIO *)0x0,
                                          uVar15);
              if (pXVar22 == (X509 *)0x0) {
                local_68 = (X509 *)0x3;
                pXVar19 = pXVar22;
                local_e4 = pXVar22;
                goto LAB_0003d5be;
              }
            }
            else {
              local_e4 = (X509 *)0x0;
            }
LAB_0003e046:
            pXVar22 = (X509 *)0x0;
            local_b8 = uVar15;
          }
          if (pXVar19 == (X509 *)0x0) {
            if (pXVar16 == (X509 *)0x27) {
              iVar24 = CMS_data((CMS_ContentInfo *)pXVar23,(BIO *)bp,local_b8);
joined_r0x0003e434:
              local_68 = pXVar19;
              if (iVar24 != 0) goto LAB_0003d5c4;
            }
            else {
              if (pXVar16 == (X509 *)0x2b) {
                iVar24 = CMS_uncompress((CMS_ContentInfo *)pXVar23,(BIO *)local_4c,(BIO *)bp,
                                        local_b8);
                goto joined_r0x0003e434;
              }
              if (pXVar16 == (X509 *)0x29) {
                iVar24 = CMS_digest_verify((CMS_ContentInfo *)pXVar23,(BIO *)local_4c,(BIO *)bp,
                                           local_b8);
                if (0 < iVar24) {
                  BIO_printf(bio_err,"Verification successful\n");
                  local_68 = pXVar19;
                  goto LAB_0003d5c4;
                }
                local_68 = (X509 *)&DAT_00000004;
                BIO_printf(bio_err,"Verification failure\n");
                goto LAB_0003d5be;
              }
              if (pXVar16 == (X509 *)0x2d) {
                iVar24 = CMS_EncryptedData_decrypt
                                   ((CMS_ContentInfo *)pXVar23,(uchar *)local_e4,(size_t)local_84,
                                    (BIO *)local_4c,(BIO *)bp,local_b8);
                goto joined_r0x0003e434;
              }
              if (pXVar20 != (X509 *)0x0) {
                iVar24 = CMS_verify((CMS_ContentInfo *)pXVar23,(stack_st_X509 *)local_d4,
                                    (X509_STORE *)local_d8,(BIO *)local_4c,(BIO *)bp,local_b8);
                if (0 < iVar24) {
                  BIO_printf(bio_err,"Verification successful\n");
                  if (local_bc != (X509 *)0x0) {
                    p_Var8 = (_STACK *)CMS_get0_signers((CMS_ContentInfo *)pXVar23);
                    pBVar11 = BIO_new_file((char *)local_bc,"w");
                    if (pBVar11 == (BIO *)0x0) {
                      local_68 = (X509 *)0x5;
                      BIO_printf(bio_err,"Error writing signers to %s\n",local_bc);
                      goto LAB_0003d5be;
                    }
                    while( true ) {
                      iVar24 = sk_num(p_Var8);
                      if (iVar24 <= (int)pXVar19) break;
                      pXVar16 = (X509 *)sk_value(p_Var8,(int)pXVar19);
                      PEM_write_bio_X509(pBVar11,pXVar16);
                      pXVar19 = (X509 *)((int)&pXVar19->cert_info + 1);
                    }
                    BIO_free(pBVar11);
                    sk_free(p_Var8);
                  }
                  pBVar11 = bio_err;
                  pXVar19 = local_68;
                  if (local_68 != (X509 *)0x0) {
                    p_Var8 = (_STACK *)CMS_get0_SignerInfos((CMS_ContentInfo *)pXVar23);
                    iVar24 = 0;
                    while (iVar6 = sk_num(p_Var8), iVar24 < iVar6) {
                      pvVar12 = sk_value(p_Var8,iVar24);
                      iVar6 = CMS_get1_ReceiptRequest(pvVar12,&local_3c);
                      iVar24 = iVar24 + 1;
                      BIO_printf(bio_err,"Signer %d:\n",iVar24);
                      if (iVar6 == 0) {
                        BIO_puts(bio_err,"  No Receipt Request\n");
                      }
                      else if (iVar6 < 0) {
                        BIO_puts(bio_err,"  Receipt Request Parse Error\n");
                        ERR_print_errors(bio_err);
                      }
                      else {
                        CMS_ReceiptRequest_get0_values
                                  (local_3c,local_2c,&local_38,&local_30,&local_34);
                        BIO_puts(pBVar11,"  Signed Content ID:\n");
                        iVar6 = ASN1_STRING_length(local_2c[0]);
                        puVar13 = ASN1_STRING_data(local_2c[0]);
                        BIO_dump_indent(pBVar11,puVar13,iVar6,4);
                        BIO_puts(pBVar11,"  Receipts From");
                        if (local_30 == 0) {
                          if (local_38 == 1) {
                            BIO_puts(pBVar11,": First Tier\n");
                          }
                          else if (local_38 == 0) {
                            BIO_puts(pBVar11,": All\n");
                          }
                          else {
                            BIO_printf(pBVar11," Unknown (%d)\n");
                          }
                        }
                        else {
                          BIO_puts(pBVar11," List:\n");
                          gnames_stack_print(pBVar11,local_30);
                        }
                        BIO_puts(pBVar11,"  Receipts To:\n");
                        gnames_stack_print(pBVar11,local_34);
                      }
                      if (local_3c != (CMS_ReceiptRequest *)0x0) {
                        CMS_ReceiptRequest_free(local_3c);
                      }
                    }
                    local_68 = (X509 *)0x0;
                    pXVar19 = (X509 *)0x0;
                  }
                  goto LAB_0003d5c4;
                }
                BIO_printf(bio_err,"Verification failure\n");
                if (local_9c == (X509 *)0x0) {
                  local_68 = (X509 *)&DAT_00000004;
                  pXVar19 = local_9c;
                }
                else {
                  local_68 = (X509 *)(verify_err + 0x20);
                  if (local_68 == (X509 *)0x0) goto LAB_0003d5c4;
                }
                goto LAB_0003d5be;
              }
              if (uVar21 >> 5 == 0) {
                if (bVar2) {
                  if (bVar3) {
                    CMS_ContentInfo_print_ctx
                              ((BIO *)bp,(CMS_ContentInfo *)pXVar23,0,(ASN1_PCTX *)0x0);
                  }
                  goto LAB_0003df44;
                }
                if (local_94 == 6) {
                  if (local_80 != (X509 *)0x0) {
                    BIO_printf((BIO *)bp,"To: %s\n");
                  }
                  if (local_7c != (X509 *)0x0) {
                    BIO_printf((BIO *)bp,"From: %s\n");
                  }
                  if (local_78 != (X509 *)0x0) {
                    BIO_printf((BIO *)bp,"Subject: %s\n");
                  }
                  pXVar19 = local_4c;
                  if (pXVar16 != (X509 *)0x76) {
                    pXVar19 = local_e0;
                  }
                  iVar24 = SMIME_write_CMS((BIO *)bp,(CMS_ContentInfo *)pXVar23,(BIO *)pXVar19,
                                           local_b8);
                }
                else if (local_94 == 3) {
                  iVar24 = PEM_write_bio_CMS_stream
                                     ((BIO *)bp,(CMS_ContentInfo *)pXVar23,(BIO *)local_e0,local_b8)
                  ;
                }
                else {
                  if (local_94 != 1) {
                    BIO_printf(bio_err,"Bad output format for CMS file\n");
                    local_68 = (X509 *)&DAT_00000004;
                    pXVar19 = (X509 *)0x0;
                    goto LAB_0003d5be;
                  }
                  iVar24 = i2d_CMS_bio_stream((BIO *)bp,(CMS_ContentInfo *)pXVar23,(BIO *)local_e0,
                                              local_b8);
                }
                if (0 < iVar24) goto LAB_0003df44;
                local_68 = (X509 *)0x6;
                pXVar19 = (X509 *)0x0;
                goto LAB_0003d5be;
              }
              iVar24 = CMS_verify_receipt((CMS_ContentInfo *)local_d0,(CMS_ContentInfo *)pXVar23,
                                          (stack_st_X509 *)local_d4,(X509_STORE *)local_d8,local_b8)
              ;
              pXVar19 = pXVar20;
              if (0 < iVar24) {
                BIO_printf(bio_err,"Verification successful\n");
                local_68 = pXVar20;
                goto LAB_0003d5c4;
              }
              BIO_printf(bio_err,"Verification failure\n");
            }
            local_68 = (X509 *)&DAT_00000004;
          }
          else {
            if ((int)(local_b8 << 0xe) < 0) {
              CMS_decrypt((CMS_ContentInfo *)pXVar23,(EVP_PKEY *)0x0,(X509 *)0x0,(BIO *)0x0,
                          (BIO *)0x0,local_b8);
            }
            if ((local_e4 == (X509 *)0x0) ||
               (pXVar19 = (X509 *)CMS_decrypt_set1_key
                                            ((CMS_ContentInfo *)pXVar23,(uchar *)local_e4,
                                             (size_t)local_84,(uchar *)local_e8,(size_t)local_5c),
               pXVar19 != (X509 *)0x0)) {
              if ((local_f0 == (X509 *)0x0) ||
                 (pXVar19 = (X509 *)CMS_decrypt_set1_pkey
                                              ((CMS_ContentInfo *)pXVar23,(EVP_PKEY *)local_f0,
                                               local_c8), pXVar19 != (X509 *)0x0)) {
                if ((local_98 == (X509 *)0x0) ||
                   (pXVar19 = (X509 *)CMS_decrypt_set1_password
                                                ((CMS_ContentInfo *)pXVar23,(uchar *)local_98,-1),
                   pXVar19 != (X509 *)0x0)) {
                  pXVar19 = (X509 *)CMS_decrypt((CMS_ContentInfo *)pXVar23,(EVP_PKEY *)0x0,
                                                (X509 *)0x0,(BIO *)local_4c,(BIO *)bp,local_b8);
                  if (pXVar19 != (X509 *)0x0) {
LAB_0003df44:
                    local_68 = (X509 *)0x0;
                    pXVar19 = (X509 *)0x0;
                    goto LAB_0003d5c4;
                  }
                  local_68 = (X509 *)&DAT_00000004;
                  BIO_printf(bio_err,"Error decrypting CMS structure\n");
                }
                else {
                  local_68 = (X509 *)&DAT_00000004;
                  BIO_puts(bio_err,"Error decrypting CMS using password\n");
                }
              }
              else {
                local_68 = (X509 *)&DAT_00000004;
                BIO_puts(bio_err,"Error decrypting CMS using private key\n");
              }
            }
            else {
              local_68 = (X509 *)&DAT_00000004;
              BIO_puts(bio_err,"Error decrypting CMS using secret key\n");
            }
          }
        }
        else {
          if (local_a4 == 6) {
            pXVar23 = (X509 *)SMIME_read_CMS((BIO *)local_e0,(BIO **)&local_4c);
          }
          else if (local_a4 == 3) {
            pXVar23 = (X509 *)PEM_read_bio_CMS((BIO *)local_e0,(CMS_ContentInfo **)0x0,
                                               (undefined1 *)0x0,(void *)0x0);
          }
          else {
            if (local_a4 != 1) {
              bp = (X509 *)0x0;
              BIO_printf(bio_err,"Bad input format for CMS file\n");
              goto LAB_0003d864;
            }
            pXVar23 = (X509 *)d2i_CMS_bio((BIO *)local_e0,(CMS_ContentInfo **)0x0);
          }
          if (pXVar23 == (X509 *)0x0) {
            BIO_printf(bio_err,"Error reading S/MIME message\n");
            local_68 = (X509 *)0x2;
            pXVar19 = pXVar23;
            pXVar22 = pXVar23;
            bp = pXVar23;
            local_d8 = pXVar23;
            local_d0 = pXVar23;
            local_cc = pXVar23;
            goto LAB_0003d5be;
          }
          if (local_90 == (X509 *)0x0) {
LAB_0003da52:
            if (local_8c != (X509 *)0x0) {
              p_Var8 = (_STACK *)CMS_get1_certs((CMS_ContentInfo *)pXVar23);
              bp = (X509 *)BIO_new_file((char *)local_8c,"w");
              if (bp == (X509 *)0x0) {
                local_68 = (X509 *)0x5;
                BIO_printf(bio_err,"Error writing certs to %s\n",local_8c);
                pXVar19 = bp;
                pXVar22 = bp;
                local_d8 = bp;
                local_d0 = bp;
                local_cc = bp;
                goto LAB_0003d5be;
              }
              iVar6 = 0;
              while( true ) {
                iVar4 = sk_num(p_Var8);
                if (iVar4 <= iVar6) break;
                pXVar20 = (X509 *)sk_value(p_Var8,iVar6);
                PEM_write_bio_X509((BIO *)bp,pXVar20);
                iVar6 = iVar6 + 1;
              }
              BIO_free((BIO *)bp);
              sk_pop_free(p_Var8,X509_free);
            }
            goto LAB_0003daac;
          }
          BIO_free((BIO *)local_4c);
          bp = (X509 *)BIO_new_file((char *)local_90,"rb");
          local_4c = bp;
          if (bp != (X509 *)0x0) goto LAB_0003da52;
          BIO_printf(bio_err,"Can\'t read content file %s\n",local_90);
LAB_0003dea2:
          local_68 = (X509 *)0x2;
          pXVar19 = bp;
          pXVar22 = bp;
          local_d8 = bp;
          local_d0 = bp;
          local_cc = bp;
        }
      }
      else {
        bp = (X509 *)BIO_new_file((char *)local_cc,pcVar14);
        local_e0 = bp;
        if (bp != (X509 *)0x0) goto LAB_0003d838;
        BIO_printf(bio_err,"Can\'t open input file %s\n",local_cc);
LAB_0003d864:
        local_68 = (X509 *)0x2;
        pXVar19 = bp;
        pXVar22 = bp;
        pXVar23 = bp;
        local_d8 = bp;
        local_d0 = bp;
        local_cc = bp;
      }
    }
  }
  else {
    BIO_puts(bio_err,"No Signed Receipts Recipients\n");
LAB_0003d2ac:
    pXVar19 = (X509 *)0x0;
    BIO_printf(bio_err,"Usage cms [options] cert.pem ...\n");
    BIO_printf(bio_err,"where options are\n");
    BIO_printf(bio_err,"-encrypt       encrypt message\n");
    BIO_printf(bio_err,"-decrypt       decrypt encrypted message\n");
    BIO_printf(bio_err,"-sign          sign message\n");
    BIO_printf(bio_err,"-verify        verify signed message\n");
    BIO_printf(bio_err,"-cmsout        output CMS structure\n");
    BIO_printf(bio_err,"-des3          encrypt with triple DES\n");
    BIO_printf(bio_err,"-des           encrypt with DES\n");
    BIO_printf(bio_err,"-seed          encrypt with SEED\n");
    BIO_printf(bio_err,"-rc2-40        encrypt with RC2-40 (default)\n");
    BIO_printf(bio_err,"-rc2-64        encrypt with RC2-64\n");
    BIO_printf(bio_err,"-rc2-128       encrypt with RC2-128\n");
    BIO_printf(bio_err,"-aes128, -aes192, -aes256\n");
    BIO_printf(bio_err,"               encrypt PEM output with cbc aes\n");
    BIO_printf(bio_err,"-camellia128, -camellia192, -camellia256\n");
    BIO_printf(bio_err,"               encrypt PEM output with cbc camellia\n");
    BIO_printf(bio_err,"-nointern      don\'t search certificates in message for signer\n");
    BIO_printf(bio_err,"-nosigs        don\'t verify message signature\n");
    BIO_printf(bio_err,"-noverify      don\'t verify signers certificate\n");
    BIO_printf(bio_err,"-nocerts       don\'t include signers certificate when signing\n");
    BIO_printf(bio_err,"-nodetach      use opaque signing\n");
    BIO_printf(bio_err,"-noattr        don\'t include any signed attributes\n");
    BIO_printf(bio_err,"-binary        don\'t translate message to text\n");
    BIO_printf(bio_err,"-certfile file other certificates file\n");
    BIO_printf(bio_err,"-certsout file certificate output file\n");
    BIO_printf(bio_err,"-signer file   signer certificate file\n");
    BIO_printf(bio_err,"-recip  file   recipient certificate file for decryption\n");
    BIO_printf(bio_err,"-keyid         use subject key identifier\n");
    BIO_printf(bio_err,"-in file       input file\n");
    BIO_printf(bio_err,"-inform arg    input format SMIME (default), PEM or DER\n");
    BIO_printf(bio_err,"-inkey file    input private key (if not signer or recipient)\n");
    BIO_printf(bio_err,"-keyform arg   input private key format (PEM or ENGINE)\n");
    BIO_printf(bio_err,"-out file      output file\n");
    BIO_printf(bio_err,"-outform arg   output format SMIME (default), PEM or DER\n");
    BIO_printf(bio_err,"-content file  supply or override content for detached signature\n");
    BIO_printf(bio_err,"-to addr       to address\n");
    BIO_printf(bio_err,"-from ad       from address\n");
    BIO_printf(bio_err,"-subject s     subject\n");
    BIO_printf(bio_err,"-text          include or delete text MIME headers\n");
    BIO_printf(bio_err,"-CApath dir    trusted certificates directory\n");
    BIO_printf(bio_err,"-CAfile file   trusted certificates file\n");
    BIO_printf(bio_err,
               "-crl_check     check revocation status of signer\'s certificate using CRLs\n");
    BIO_printf(bio_err,
               "-crl_check_all check revocation status of signer\'s certificate chain using CRLs\n")
    ;
    BIO_printf(bio_err,"-engine e      use engine e, possibly a hardware device.\n");
    BIO_printf(bio_err,"-passin arg    input file pass phrase source\n");
    BIO_printf(bio_err,"-rand file%cfile%c...\n",0x3a,0x3a);
    BIO_printf(bio_err,"               load the file (or the files in the directory) into\n");
    BIO_printf(bio_err,"               the random number generator\n");
    pcVar14 = "cert.pem       recipient certificate(s) for encryption\n";
LAB_0003d56a:
    BIO_printf(bio_err,pcVar14);
    local_68 = (X509 *)0x1;
    pXVar22 = pXVar19;
    pXVar23 = pXVar19;
    bp = pXVar19;
    local_f0 = pXVar19;
    local_e0 = pXVar19;
    local_dc = pXVar19;
    local_d8 = pXVar19;
    local_d4 = pXVar19;
    local_d0 = pXVar19;
    local_cc = pXVar19;
    local_c8 = pXVar19;
    local_c0 = pXVar19;
  }
LAB_0003d5be:
  ERR_print_errors(bio_err);
LAB_0003d5c4:
  if (local_c4 != (X509 *)0x0) {
    app_RAND_write_file(0,bio_err);
  }
  sk_pop_free((_STACK *)local_c0,X509_free);
  sk_pop_free((_STACK *)local_d4,X509_free);
  if (local_40 != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(local_40);
  }
  if (local_f8 != (X509 *)0x0) {
    sk_free((_STACK *)local_f8);
  }
  if (local_f4 != (X509 *)0x0) {
    sk_free((_STACK *)local_f4);
  }
  if (local_e4 != (X509 *)0x0) {
    CRYPTO_free(local_e4);
  }
  if (local_e8 != (X509 *)0x0) {
    CRYPTO_free(local_e8);
  }
  if (pXVar19 != (X509 *)0x0) {
    CRYPTO_free(pXVar19);
  }
  if (oid != (X509 *)0x0) {
    ASN1_OBJECT_free((ASN1_OBJECT *)oid);
  }
  if (pXVar22 != (X509 *)0x0) {
    CMS_ReceiptRequest_free((CMS_ReceiptRequest *)pXVar22);
  }
  if (local_ec != (X509 *)0x0) {
    sk_free((_STACK *)local_ec);
  }
  if (st != (X509 *)0x0) {
    sk_free((_STACK *)st);
  }
  X509_STORE_free((X509_STORE *)local_d8);
  X509_free((X509 *)0x0);
  X509_free(local_c8);
  X509_free(local_dc);
  EVP_PKEY_free((EVP_PKEY *)local_f0);
  CMS_ContentInfo_free((CMS_ContentInfo *)pXVar23);
  CMS_ContentInfo_free((CMS_ContentInfo *)local_d0);
  BIO_free((BIO *)local_cc);
  BIO_free((BIO *)local_e0);
  BIO_free((BIO *)local_4c);
  BIO_free_all((BIO *)bp);
  if (local_44 != (void *)0x0) {
    CRYPTO_free(local_44);
  }
  return local_68;
}

