
/* WARNING: Type propagation algorithm not settling */

X509 * smime_main(undefined4 param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  X509 *pXVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  BIO_METHOD *type;
  undefined4 uVar7;
  void *pvVar8;
  X509 *pkey;
  PKCS7_SIGNER_INFO *pPVar9;
  _STACK *p_Var10;
  BIO *pBVar11;
  X509 *pXVar12;
  char *format;
  X509 *pXVar13;
  X509 **ppXVar14;
  uint uVar15;
  X509 *pXVar16;
  X509 *pXVar17;
  X509 *pXVar18;
  X509 *store;
  X509 *pXVar19;
  bool bVar20;
  X509 *local_a8;
  X509 *local_a4;
  X509 *local_a0;
  X509 *local_9c;
  X509 *local_98;
  X509 *local_94;
  uint local_8c;
  int local_88;
  EVP_CIPHER *local_84;
  X509 *local_80;
  int local_7c;
  undefined4 local_78;
  X509 *local_74;
  EVP_MD *local_70;
  X509 *local_6c;
  int local_68;
  X509 *local_64;
  X509 *local_60;
  X509 *local_5c;
  X509 *local_58;
  X509 *local_54;
  char *local_48;
  char *local_44;
  X509 **local_3c;
  X509 *local_38;
  X509 *local_34;
  void *local_30;
  X509_VERIFY_PARAM *local_2c [2];
  
  local_3c = (X509 **)(param_2 + 4);
  local_38 = (X509 *)0x0;
  local_34 = (X509 *)0x0;
  local_30 = (void *)0x0;
  local_2c[0] = (X509_VERIFY_PARAM *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  pXVar3 = (X509 *)load_config(bio_err,0);
  if (pXVar3 == (X509 *)0x0) {
    pXVar17 = (X509 *)0x1;
    pXVar18 = pXVar3;
    pXVar16 = pXVar3;
    pkey = pXVar3;
    pXVar12 = pXVar3;
    pXVar19 = pXVar3;
    local_a8 = pXVar3;
    local_a4 = pXVar3;
    local_a0 = pXVar3;
    local_9c = pXVar3;
    local_98 = pXVar3;
  }
  else {
    pXVar17 = (X509 *)0x0;
    pXVar16 = (X509 *)0x0;
    pXVar19 = (X509 *)0x0;
    pXVar13 = (X509 *)0x0;
    local_70 = (EVP_MD *)0x0;
    local_88 = 6;
    local_7c = 6;
    local_68 = 0;
    local_78 = 3;
    bVar2 = false;
    local_98 = (X509 *)0x0;
    local_9c = (X509 *)0x0;
    local_54 = (X509 *)0x0;
    local_58 = (X509 *)0x0;
    local_5c = (X509 *)0x0;
    local_60 = (X509 *)0x0;
    local_64 = (X509 *)0x0;
    local_84 = (EVP_CIPHER *)0x0;
    local_6c = (X509 *)0x0;
    local_a8 = (X509 *)0x0;
    local_a0 = (X509 *)0x0;
    local_a4 = (X509 *)0x0;
    local_94 = (X509 *)0x0;
    local_74 = (X509 *)0x0;
    local_80 = (X509 *)0x0;
    local_8c = 0x40;
LAB_0003bb1e:
    pXVar3 = local_34;
    if (local_34 == (X509 *)0x0) {
LAB_0003bb22:
      ppXVar14 = local_3c;
      pXVar18 = *local_3c;
      if ((pXVar18 == (X509 *)0x0) || (*(char *)&pXVar18->cert_info != '-')) goto LAB_0003bba4;
      iVar4 = strcmp((char *)pXVar18,"-encrypt");
      iVar6 = local_68;
      if (iVar4 == 0) {
        pXVar13 = (X509 *)0x11;
      }
      else {
        iVar4 = strcmp((char *)pXVar18,"-decrypt");
        if (iVar4 == 0) {
          pXVar13 = (X509 *)0x22;
        }
        else {
          iVar4 = strcmp((char *)pXVar18,"-sign");
          if (iVar4 == 0) {
            pXVar13 = (X509 *)0x53;
          }
          else {
            iVar4 = strcmp((char *)pXVar18,"-resign");
            if (iVar4 == 0) {
              pXVar13 = (X509 *)0x76;
            }
            else {
              iVar4 = strcmp((char *)pXVar18,"-verify");
              if (iVar4 == 0) {
                pXVar13 = (X509 *)&DAT_00000024;
              }
              else {
                iVar4 = strcmp((char *)pXVar18,"-pk7out");
                if (iVar4 == 0) {
                  pXVar13 = (X509 *)0x35;
                }
                else {
                  iVar4 = strcmp((char *)pXVar18,"-des3");
                  if (iVar4 == 0) {
                    local_84 = EVP_des_ede3_cbc();
                    ppXVar14 = local_3c;
                    pXVar3 = local_34;
                  }
                  else {
                    iVar4 = strcmp((char *)pXVar18,"-des");
                    if (iVar4 == 0) {
                      local_84 = EVP_des_cbc();
                      ppXVar14 = local_3c;
                      pXVar3 = local_34;
                    }
                    else {
                      iVar4 = strcmp((char *)pXVar18,"-seed");
                      if (iVar4 == 0) {
                        local_84 = EVP_seed_cbc();
                        ppXVar14 = local_3c;
                        pXVar3 = local_34;
                      }
                      else {
                        iVar4 = strcmp((char *)pXVar18,"-rc2-40");
                        if (iVar4 == 0) {
                          local_84 = EVP_rc2_40_cbc();
                          ppXVar14 = local_3c;
                          pXVar3 = local_34;
                        }
                        else {
                          iVar4 = strcmp((char *)pXVar18,"-rc2-128");
                          if (iVar4 == 0) {
                            local_84 = EVP_rc2_cbc();
                            ppXVar14 = local_3c;
                            pXVar3 = local_34;
                          }
                          else {
                            iVar4 = strcmp((char *)pXVar18,"-rc2-64");
                            if (iVar4 == 0) {
                              local_84 = EVP_rc2_64_cbc();
                              ppXVar14 = local_3c;
                              pXVar3 = local_34;
                            }
                            else {
                              iVar4 = strcmp((char *)pXVar18,"-aes128");
                              if (iVar4 == 0) {
                                local_84 = EVP_aes_128_cbc();
                                ppXVar14 = local_3c;
                                pXVar3 = local_34;
                              }
                              else {
                                iVar4 = strcmp((char *)pXVar18,"-aes192");
                                if (iVar4 == 0) {
                                  local_84 = EVP_aes_192_cbc();
                                  ppXVar14 = local_3c;
                                  pXVar3 = local_34;
                                }
                                else {
                                  iVar4 = strcmp((char *)pXVar18,"-aes256");
                                  if (iVar4 == 0) {
                                    local_84 = EVP_aes_256_cbc();
                                    ppXVar14 = local_3c;
                                    pXVar3 = local_34;
                                  }
                                  else {
                                    iVar4 = strcmp((char *)pXVar18,"-camellia128");
                                    if (iVar4 == 0) {
                                      local_84 = EVP_camellia_128_cbc();
                                      ppXVar14 = local_3c;
                                      pXVar3 = local_34;
                                    }
                                    else {
                                      iVar4 = strcmp((char *)pXVar18,"-camellia192");
                                      if (iVar4 == 0) {
                                        local_84 = EVP_camellia_192_cbc();
                                        ppXVar14 = local_3c;
                                        pXVar3 = local_34;
                                      }
                                      else {
                                        iVar4 = strcmp((char *)pXVar18,"-camellia256");
                                        if (iVar4 == 0) {
                                          local_84 = EVP_camellia_256_cbc();
                                          ppXVar14 = local_3c;
                                          pXVar3 = local_34;
                                        }
                                        else {
                                          iVar4 = strcmp((char *)pXVar18,"-text");
                                          if (iVar4 == 0) {
                                            local_8c = local_8c | 1;
                                          }
                                          else {
                                            iVar4 = strcmp((char *)pXVar18,"-nointern");
                                            if (iVar4 == 0) {
                                              local_8c = local_8c | 0x10;
                                            }
                                            else {
                                              iVar4 = strcmp((char *)pXVar18,"-noverify");
                                              if (iVar4 == 0) {
                                                local_8c = local_8c | 0x20;
                                              }
                                              else {
                                                iVar4 = strcmp((char *)pXVar18,"-nochain");
                                                if (iVar4 == 0) {
                                                  local_8c = local_8c | 8;
                                                }
                                                else {
                                                  iVar4 = strcmp((char *)pXVar18,"-nocerts");
                                                  if (iVar4 == 0) {
                                                    local_8c = local_8c | 2;
                                                  }
                                                  else {
                                                    iVar4 = strcmp((char *)pXVar18,"-noattr");
                                                    if (iVar4 == 0) {
                                                      local_8c = local_8c | 0x100;
                                                    }
                                                    else {
                                                      iVar4 = strcmp((char *)pXVar18,"-nodetach");
                                                      if (iVar4 == 0) {
                                                        local_8c = local_8c & 0xffffffbf;
                                                      }
                                                      else {
                                                        iVar4 = strcmp((char *)pXVar18,"-nosmimecap"
                                                                      );
                                                        if (iVar4 == 0) {
                                                          local_8c = local_8c | 0x200;
                                                        }
                                                        else {
                                                          iVar4 = strcmp((char *)pXVar18,"-binary");
                                                          if (iVar4 == 0) {
                                                            local_8c = local_8c | 0x80;
                                                          }
                                                          else {
                                                            iVar4 = strcmp((char *)pXVar18,"-nosigs"
                                                                          );
                                                            if (iVar4 == 0) {
                                                              local_8c = local_8c | 4;
                                                            }
                                                            else {
                                                              iVar6 = strcmp((char *)pXVar18,
                                                                             "-stream");
                                                              if (iVar6 == 0) {
                                                                local_68 = 1;
                                                                iVar6 = local_68;
                                                              }
                                                              else {
                                                                iVar6 = strcmp((char *)pXVar18,
                                                                               "-indef");
                                                                if (iVar6 == 0) {
                                                                  local_68 = 1;
                                                                  iVar6 = local_68;
                                                                }
                                                                else {
                                                                  iVar6 = strcmp((char *)pXVar18,
                                                                                 "-noindef");
                                                                  if (iVar6 != 0) {
                                                                    iVar6 = strcmp((char *)pXVar18,
                                                                                   "-nooldmime");
                                                                    if (iVar6 == 0) {
                                                                      local_8c = local_8c | 0x400;
                                                                      iVar6 = local_68;
                                                                    }
                                                                    else {
                                                                      iVar6 = strcmp((char *)pXVar18
                                                                                     ,"-crlfeol");
                                                                      if (iVar6 == 0) {
                                                                        local_8c = local_8c | 0x800;
                                                                        iVar6 = local_68;
                                                                      }
                                                                      else {
                                                                        iVar6 = strcmp((char *)
                                                  pXVar18,"-rand");
                                                  if (iVar6 == 0) {
                                                    local_98 = ppXVar14[1];
                                                    if (local_98 == (X509 *)0x0) goto LAB_0003bbdc;
                                                    bVar2 = true;
                                                    ppXVar14 = ppXVar14 + 1;
                                                    iVar6 = local_68;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)pXVar18,"-engine");
                                                    if (iVar6 == 0) {
                                                      pXVar17 = ppXVar14[1];
                                                      pXVar18 = pXVar17;
                                                    }
                                                    else {
                                                      iVar6 = strcmp((char *)pXVar18,"-passin");
                                                      if (iVar6 == 0) {
                                                        local_9c = ppXVar14[1];
                                                        pXVar18 = local_9c;
                                                      }
                                                      else {
                                                        cVar1 = *(char *)((int)&pXVar18->cert_info +
                                                                         1);
                                                        if (((cVar1 == 't') &&
                                                            (*(char *)((int)&pXVar18->cert_info + 2)
                                                             == 'o')) &&
                                                           (*(char *)((int)&pXVar18->cert_info + 3)
                                                            == '\0')) {
                                                          local_64 = ppXVar14[1];
                                                          pXVar18 = local_64;
                                                        }
                                                        else {
                                                          iVar6 = strcmp((char *)pXVar18,"-from");
                                                          if (iVar6 == 0) {
                                                            local_60 = ppXVar14[1];
                                                            pXVar18 = local_60;
                                                          }
                                                          else {
                                                            iVar6 = strcmp((char *)pXVar18,
                                                                           "-subject");
                                                            if (iVar6 == 0) {
                                                              local_5c = ppXVar14[1];
                                                              pXVar18 = local_5c;
                                                            }
                                                            else {
                                                              iVar6 = strcmp((char *)pXVar18,
                                                                             "-signer");
                                                              if (iVar6 == 0) {
                                                                if (ppXVar14[1] == (X509 *)0x0)
                                                                goto LAB_0003bbdc;
                                                                if (local_94 != (X509 *)0x0) {
                                                                  if (pXVar19 == (X509 *)0x0) {
                                                                    pXVar19 = (X509 *)sk_new_null();
                                                                  }
                                                                  sk_push((_STACK *)pXVar19,local_94
                                                                         );
                                                                  if (local_a8 == (X509 *)0x0) {
                                                                    local_a8 = local_94;
                                                                  }
                                                                  if (pXVar16 == (X509 *)0x0) {
                                                                    pXVar16 = (X509 *)sk_new_null();
                                                                  }
                                                                  sk_push((_STACK *)pXVar16,local_a8
                                                                         );
                                                                  local_a8 = (X509 *)0x0;
                                                                  ppXVar14 = local_3c;
                                                                }
                                                                local_94 = ppXVar14[1];
                                                                ppXVar14 = ppXVar14 + 1;
                                                                pXVar3 = local_34;
                                                                iVar6 = local_68;
                                                                goto LAB_0003bb9c;
                                                              }
                                                              iVar6 = strcmp((char *)pXVar18,
                                                                             "-recip");
                                                              if (iVar6 == 0) {
                                                                local_a4 = ppXVar14[1];
                                                                pXVar18 = local_a4;
                                                                goto joined_r0x0003cc32;
                                                              }
                                                              if (((cVar1 == 'm') &&
                                                                  (*(char *)((int)&pXVar18->
                                                  cert_info + 2) == 'd')) &&
                                                  (*(char *)((int)&pXVar18->cert_info + 3) == '\0'))
                                                  {
                                                    if (ppXVar14[1] != (X509 *)0x0) {
                                                      local_3c = ppXVar14 + 1;
                                                      local_70 = EVP_get_digestbyname
                                                                           ((char *)ppXVar14[1]);
                                                      ppXVar14 = local_3c;
                                                      pXVar3 = local_34;
                                                      iVar6 = local_68;
                                                      if (local_70 != (EVP_MD *)0x0)
                                                      goto LAB_0003bb9c;
                                                      BIO_printf(bio_err,"Unknown digest %s\n",
                                                                 *local_3c);
                                                    }
                                                    goto LAB_0003bbdc;
                                                  }
                                                  iVar6 = strcmp((char *)pXVar18,"-inkey");
                                                  if (iVar6 == 0) {
                                                    if (ppXVar14[1] == (X509 *)0x0)
                                                    goto LAB_0003bbdc;
                                                    if (local_a8 != (X509 *)0x0) {
                                                      if (local_94 == (X509 *)0x0)
                                                      goto LAB_0003c214;
                                                      if (pXVar19 == (X509 *)0x0) {
                                                        pXVar19 = (X509 *)sk_new_null();
                                                      }
                                                      sk_push((_STACK *)pXVar19,local_94);
                                                      if (pXVar16 == (X509 *)0x0) {
                                                        pXVar16 = (X509 *)sk_new_null();
                                                      }
                                                      sk_push((_STACK *)pXVar16,local_a8);
                                                      local_94 = (X509 *)0x0;
                                                      ppXVar14 = local_3c;
                                                    }
                                                    local_a8 = ppXVar14[1];
                                                    ppXVar14 = ppXVar14 + 1;
                                                    pXVar3 = local_34;
                                                    iVar6 = local_68;
                                                    goto LAB_0003bb9c;
                                                  }
                                                  iVar6 = strcmp((char *)pXVar18,"-keyform");
                                                  if (iVar6 == 0) {
                                                    if (ppXVar14[1] == (X509 *)0x0)
                                                    goto LAB_0003bbdc;
                                                    local_3c = ppXVar14 + 1;
                                                    local_78 = str2fmt();
                                                    ppXVar14 = local_3c;
                                                    pXVar3 = local_34;
                                                    iVar6 = local_68;
                                                    goto LAB_0003bb9c;
                                                  }
                                                  iVar6 = strcmp((char *)pXVar18,"-certfile");
                                                  if (iVar6 == 0) {
                                                    local_a0 = ppXVar14[1];
                                                    pXVar18 = local_a0;
                                                  }
                                                  else {
                                                    iVar6 = strcmp((char *)pXVar18,"-CAfile");
                                                    if (iVar6 == 0) {
                                                      local_58 = ppXVar14[1];
                                                      pXVar18 = local_58;
                                                    }
                                                    else {
                                                      iVar6 = strcmp((char *)pXVar18,"-CApath");
                                                      if (iVar6 == 0) {
                                                        local_54 = ppXVar14[1];
                                                        pXVar18 = local_54;
                                                      }
                                                      else {
                                                        if (((cVar1 == 'i') &&
                                                            (*(char *)((int)&pXVar18->cert_info + 2)
                                                             == 'n')) &&
                                                           (*(char *)((int)&pXVar18->cert_info + 3)
                                                            == '\0')) {
                                                          local_80 = ppXVar14[1];
                                                          pXVar18 = local_80;
                                                          goto joined_r0x0003cc32;
                                                        }
                                                        iVar6 = strcmp((char *)pXVar18,"-inform");
                                                        if (iVar6 == 0) {
                                                          if (ppXVar14[1] == (X509 *)0x0)
                                                          goto LAB_0003bbdc;
                                                          local_3c = ppXVar14 + 1;
                                                          local_7c = str2fmt();
                                                          ppXVar14 = local_3c;
                                                          pXVar3 = local_34;
                                                          iVar6 = local_68;
                                                          goto LAB_0003bb9c;
                                                        }
                                                        iVar6 = strcmp((char *)pXVar18,"-outform");
                                                        if (iVar6 == 0) {
                                                          if (ppXVar14[1] != (X509 *)0x0) {
                                                            local_3c = ppXVar14 + 1;
                                                            local_88 = str2fmt();
                                                            ppXVar14 = local_3c;
                                                            pXVar3 = local_34;
                                                            iVar6 = local_68;
                                                            goto LAB_0003bb9c;
                                                          }
                                                          goto LAB_0003bbdc;
                                                        }
                                                        iVar6 = strcmp((char *)pXVar18,"-out");
                                                        if (iVar6 != 0) {
                                                          iVar6 = strcmp((char *)pXVar18,"-content")
                                                          ;
                                                          if (iVar6 == 0) {
                                                            local_6c = ppXVar14[1];
                                                            pXVar18 = local_6c;
                                                            goto joined_r0x0003cc32;
                                                          }
                                                          iVar6 = args_verify(&local_3c,0,&local_34,
                                                                              bio_err,local_2c);
                                                          if (iVar6 == 0) {
                                                            local_84 = EVP_get_cipherbyname
                                                                                 ((char *)((int)&(*
                                                  local_3c)->cert_info + 1));
                                                  ppXVar14 = local_3c;
                                                  pXVar3 = local_34;
                                                  iVar6 = local_68;
                                                  if (local_84 == (EVP_CIPHER *)0x0) {
                                                    local_34 = (X509 *)0x1;
                                                    pXVar3 = (X509 *)0x1;
                                                  }
                                                  goto LAB_0003bb9c;
                                                  }
                                                  goto LAB_0003bb1e;
                                                  }
                                                  local_74 = ppXVar14[1];
                                                  pXVar18 = local_74;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
joined_r0x0003cc32:
                                                  if (pXVar18 == (X509 *)0x0) goto LAB_0003bbdc;
                                                  ppXVar14 = ppXVar14 + 1;
                                                  iVar6 = local_68;
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
LAB_0003bb9c:
      local_68 = iVar6;
      local_3c = ppXVar14 + 1;
      if (pXVar3 != (X509 *)0x0) goto LAB_0003bba4;
      goto LAB_0003bb22;
    }
LAB_0003bba4:
    store = (X509 *)((uint)pXVar13 & 0x40);
    if (store == (X509 *)0x0) {
      if (pXVar16 != (X509 *)0x0 || pXVar19 != (X509 *)0x0) {
        BIO_puts(bio_err,"Multiple signers or keys not allowed\n");
        goto LAB_0003bbdc;
      }
      pXVar16 = store;
      pXVar19 = store;
      if (pXVar13 == (X509 *)0x22) {
        if (local_a8 == (X509 *)0x0 && local_a4 == (X509 *)0x0) {
          BIO_printf(bio_err,"No recipient certificate or key specified\n");
          pXVar13 = (X509 *)0x0;
          goto LAB_0003bbd8;
        }
      }
      else if (pXVar13 == (X509 *)0x11) {
        pXVar18 = *local_3c;
        if (pXVar18 == (X509 *)0x0) {
          BIO_printf(bio_err,"No recipient(s) certificate(s) specified\n");
          bVar2 = true;
          pXVar13 = pXVar18;
          goto LAB_0003bbd8;
        }
        bVar2 = true;
      }
      else if (pXVar13 == (X509 *)0x0) {
LAB_0003bbd8:
        local_34 = (X509 *)0x1;
        pXVar19 = (X509 *)0x0;
        pXVar16 = pXVar13;
        goto LAB_0003bbdc;
      }
LAB_0003c0c8:
      if (pXVar3 != (X509 *)0x0) goto LAB_0003bbdc;
      uVar5 = setup_engine(bio_err,pXVar17,0);
      iVar6 = app_passwd(bio_err,local_9c,0,&local_30,0);
      if (iVar6 == 0) {
        format = "Error getting password\n";
        goto LAB_0003be7e;
      }
      if (bVar2) {
        pXVar3 = local_98;
        if (local_98 != (X509 *)0x0) {
          pXVar3 = (X509 *)0x1;
        }
        app_RAND_load_file(0,bio_err,pXVar3);
        pBVar11 = bio_err;
        if (pXVar3 != (X509 *)0x0) {
          uVar7 = app_RAND_load_files(local_98);
          BIO_printf(pBVar11,"%ld semi-random bytes loaded\n",uVar7);
        }
      }
      if (store == (X509 *)0x0) {
        local_8c = local_8c & 0xffffffbf;
      }
      if ((int)pXVar13 << 0x1b < 0) {
        local_44 = "w";
        if (local_88 == 1) {
          local_44 = "wb";
        }
      }
      else {
        local_44 = "wb";
        if ((local_8c & 0x80) == 0) {
          local_44 = "w";
        }
      }
      pXVar18 = (X509 *)((uint)pXVar13 & 0x20);
      if (pXVar18 == (X509 *)0x0) {
        local_48 = "r";
        if ((local_8c & 0x80) != 0) {
          local_48 = "rb";
        }
        local_98 = pXVar18;
        if (pXVar13 == (X509 *)0x11) {
          if (local_84 == (EVP_CIPHER *)0x0) {
            local_84 = EVP_rc2_40_cbc();
          }
          local_98 = (X509 *)sk_new_null();
          pXVar3 = *local_3c;
          while (pXVar3 != (X509 *)0x0) {
            pXVar3 = (X509 *)load_cert(bio_err,pXVar3,3,0,uVar5,"recipient certificate file");
            if (pXVar3 == (X509 *)0x0) {
              pXVar17 = (X509 *)0x2;
              pXVar18 = pXVar3;
              pkey = pXVar3;
              pXVar12 = pXVar3;
              local_a8 = pXVar3;
              local_a4 = pXVar3;
              local_a0 = pXVar3;
              local_9c = pXVar3;
              goto LAB_0003be94;
            }
            sk_push((_STACK *)local_98,pXVar3);
            pXVar3 = local_3c[1];
            local_3c = local_3c + 1;
          }
        }
      }
      else {
        local_48 = "rb";
        if (local_7c != 1) {
          local_48 = "r";
        }
        local_98 = (X509 *)0x0;
      }
      if ((local_a0 == (X509 *)0x0) ||
         (pXVar3 = (X509 *)load_certs(bio_err,local_a0,3,0,uVar5,"certificate file"),
         local_a0 = pXVar3, pXVar3 != (X509 *)0x0)) {
        uVar15 = count_leading_zeroes((undefined *)((int)&pXVar13[-1].nc + 2));
        pXVar17 = (X509 *)(uVar15 >> 5);
        if (local_a4 == (X509 *)0x0) {
          local_9c = (X509 *)0x0;
        }
        else {
          local_9c = (X509 *)((uint)pXVar17 & 1);
        }
        if (local_9c == (X509 *)0x0) {
          if ((pXVar17 != (X509 *)0x0) ||
             (pkey = pXVar17, local_9c = pXVar17, local_a4 = local_94, pXVar13 == (X509 *)0x53)) {
joined_r0x0003c580:
            if (((local_a8 != (X509 *)0x0) ||
                (pkey = local_a4, local_a8 = local_a4, local_a4 != (X509 *)0x0)) &&
               (pXVar3 = (X509 *)load_key(bio_err,local_a8,local_78,0,local_30,uVar5,
                                          "signing key file"), pkey = pXVar3, pXVar3 == (X509 *)0x0)
               ) {
              pXVar17 = (X509 *)0x2;
              pXVar18 = pXVar3;
              pXVar12 = pXVar3;
              local_a8 = pXVar3;
              local_a4 = pXVar3;
              goto LAB_0003be94;
            }
          }
          if (local_80 == (X509 *)0x0) {
            local_a4 = (X509 *)BIO_new_fp(stdin,0);
          }
          else {
            pXVar3 = (X509 *)BIO_new_file((char *)local_80,local_48);
            local_a4 = pXVar3;
            if (pXVar3 == (X509 *)0x0) {
              BIO_printf(bio_err,"Can\'t open input file %s\n",local_80);
              pXVar17 = (X509 *)0x2;
              pXVar18 = pXVar3;
              pXVar12 = pXVar3;
              local_a8 = pXVar3;
              goto LAB_0003be94;
            }
          }
          local_a8 = pXVar18;
          if (pXVar18 != (X509 *)0x0) {
            if (local_7c == 6) {
              local_a8 = (X509 *)SMIME_read_PKCS7((BIO *)local_a4,(BIO **)&local_38);
            }
            else if (local_7c == 3) {
              local_a8 = (X509 *)PEM_read_bio_PKCS7((BIO *)local_a4,(PKCS7 **)0x0,(undefined1 *)0x0,
                                                    (void *)0x0);
            }
            else {
              if (local_7c != 1) {
                BIO_printf(bio_err,"Bad input format for PKCS#7 file\n");
                local_a8 = (X509 *)0x0;
                pXVar17 = (X509 *)0x2;
                pXVar3 = (X509 *)0x0;
                pXVar18 = (X509 *)0x0;
                pXVar12 = (X509 *)0x0;
                goto LAB_0003be94;
              }
              local_a8 = (X509 *)d2i_PKCS7_bio((BIO *)local_a4,(PKCS7 **)0x0);
            }
            if (local_a8 == (X509 *)0x0) {
              BIO_printf(bio_err,"Error reading S/MIME message\n");
              pXVar17 = (X509 *)0x2;
              pXVar3 = local_a8;
              pXVar18 = local_a8;
              pXVar12 = local_a8;
              goto LAB_0003be94;
            }
            if (local_6c != (X509 *)0x0) {
              BIO_free((BIO *)local_38);
              pXVar3 = (X509 *)BIO_new_file((char *)local_6c,"rb");
              local_38 = pXVar3;
              if (pXVar3 == (X509 *)0x0) {
                BIO_printf(bio_err,"Can\'t read content file %s\n",local_6c);
                pXVar17 = (X509 *)0x2;
                pXVar18 = pXVar3;
                pXVar12 = pXVar3;
                goto LAB_0003be94;
              }
            }
          }
          if (local_74 == (X509 *)0x0) {
            pXVar18 = (X509 *)BIO_new_fp(stdout,0);
          }
          else {
            pXVar18 = (X509 *)BIO_new_file((char *)local_74,local_44);
            if (pXVar18 == (X509 *)0x0) {
              BIO_printf(bio_err,"Can\'t open output file %s\n",local_74);
              pXVar17 = (X509 *)0x2;
              pXVar3 = pXVar18;
              pXVar12 = pXVar18;
              goto LAB_0003be94;
            }
          }
          if (pXVar13 == (X509 *)&DAT_00000024) {
            pXVar3 = (X509 *)setup_verify(bio_err,local_58,local_54);
            if (pXVar3 == (X509 *)0x0) {
              pXVar17 = (X509 *)0x2;
              pXVar12 = pXVar3;
            }
            else {
              X509_STORE_set_verify_cb((X509_STORE *)pXVar3,smime_cb + 1);
              if (local_2c[0] != (X509_VERIFY_PARAM *)0x0) {
                X509_STORE_set1_param((X509_STORE *)pXVar3,local_2c[0]);
              }
              bVar20 = store == (X509 *)0x0;
              store = pXVar3;
              if (bVar20) goto LAB_0003c4d2;
LAB_0003c3f8:
              local_8c = local_8c | 0x8000;
LAB_0003c400:
              iVar6 = 0;
              while (iVar4 = sk_num((_STACK *)pXVar19), iVar6 < iVar4) {
                local_94 = (X509 *)sk_value((_STACK *)pXVar19,iVar6);
                pvVar8 = sk_value((_STACK *)pXVar16,iVar6);
                pXVar12 = (X509 *)load_cert(bio_err,local_94,3,0,uVar5,"signer certificate");
                if (((pXVar12 == (X509 *)0x0) ||
                    (pkey = (X509 *)load_key(bio_err,pvVar8,local_78,0,local_30,uVar5,
                                             "signing key file"), pkey == (X509 *)0x0)) ||
                   (pPVar9 = PKCS7_sign_add_signer
                                       ((PKCS7 *)local_a8,pXVar12,(EVP_PKEY *)pkey,local_70,local_8c
                                       ), pPVar9 == (PKCS7_SIGNER_INFO *)0x0)) {
                  pXVar17 = (X509 *)0x3;
                  goto LAB_0003be94;
                }
                X509_free(pXVar12);
                EVP_PKEY_free((EVP_PKEY *)pkey);
                pkey = (X509 *)0x0;
                iVar6 = iVar6 + 1;
              }
              store = pXVar3;
              if (pXVar13 == (X509 *)0x53) {
                if (((int)(local_8c << 0x13) < 0) ||
                   (pXVar12 = (X509 *)PKCS7_final((PKCS7 *)local_a8,(BIO *)local_a4,local_8c),
                   pXVar12 != (X509 *)0x0)) goto LAB_0003c66e;
                pXVar17 = (X509 *)0x3;
              }
              else {
LAB_0003c4d2:
                pXVar3 = store;
                if (local_a8 == (X509 *)0x0) goto LAB_0003c676;
                if (pXVar17 == (X509 *)0x0) {
                  pXVar12 = pXVar17;
                  if (pXVar13 == (X509 *)&DAT_00000024) {
                    iVar6 = PKCS7_verify((PKCS7 *)local_a8,(stack_st_X509 *)local_a0,
                                         (X509_STORE *)store,(BIO *)local_38,(BIO *)pXVar18,local_8c
                                        );
                    if (iVar6 == 0) {
                      pXVar17 = (X509 *)&DAT_00000004;
                      BIO_printf(bio_err,"Verification failure\n");
                    }
                    else {
                      BIO_printf(bio_err,"Verification successful\n");
                      p_Var10 = (_STACK *)
                                PKCS7_get0_signers((PKCS7 *)local_a8,(stack_st_X509 *)local_a0,
                                                   local_8c);
                      if (local_94 != (X509 *)0x0) {
                        pBVar11 = BIO_new_file((char *)local_94,"w");
                        if (pBVar11 == (BIO *)0x0) {
                          pXVar17 = (X509 *)0x5;
                          BIO_printf(bio_err,"Error writing signers to %s\n",local_94);
                          goto LAB_0003be94;
                        }
                        while( true ) {
                          iVar6 = sk_num(p_Var10);
                          if (iVar6 <= (int)pXVar17) break;
                          pXVar12 = (X509 *)sk_value(p_Var10,(int)pXVar17);
                          PEM_write_bio_X509(pBVar11,pXVar12);
                          pXVar17 = (X509 *)((int)&pXVar17->cert_info + 1);
                        }
                        BIO_free(pBVar11);
                      }
                      sk_free(p_Var10);
                      pXVar17 = (X509 *)0x0;
                      pXVar12 = (X509 *)0x0;
                    }
                  }
                  else {
                    if (pXVar13 != (X509 *)0x35) goto LAB_0003c4ee;
                    PEM_write_bio_PKCS7((BIO *)pXVar18,(PKCS7 *)local_a8);
                  }
                }
                else {
                  pXVar17 = (X509 *)0x0;
                  pXVar13 = (X509 *)PKCS7_decrypt((PKCS7 *)local_a8,(EVP_PKEY *)pkey,local_9c,
                                                  (BIO *)pXVar18,local_8c);
                  pXVar12 = (X509 *)0x0;
                  if (pXVar13 == (X509 *)0x0) {
                    pXVar17 = (X509 *)&DAT_00000004;
                    BIO_printf(bio_err,"Error decrypting PKCS#7 structure\n");
                    pXVar12 = pXVar13;
                  }
                }
              }
            }
          }
          else if (pXVar13 == (X509 *)0x11) {
            if (local_68 != 0) {
              local_8c = local_8c | 0x1000;
            }
            pXVar3 = (X509 *)0x0;
            local_a8 = (X509 *)PKCS7_encrypt((stack_st_X509 *)local_98,(BIO *)local_a4,local_84,
                                             local_8c);
LAB_0003c66e:
            if (local_a8 == (X509 *)0x0) {
LAB_0003c676:
              BIO_printf(bio_err,"Error creating PKCS#7 structure\n");
              pXVar17 = (X509 *)0x3;
              local_a8 = (X509 *)0x0;
              pXVar12 = (X509 *)0x0;
            }
            else {
LAB_0003c4ee:
              if (local_64 != (X509 *)0x0) {
                BIO_printf((BIO *)pXVar18,"To: %s\n",local_64);
              }
              if (local_60 != (X509 *)0x0) {
                BIO_printf((BIO *)pXVar18,"From: %s\n");
              }
              if (local_5c != (X509 *)0x0) {
                BIO_printf((BIO *)pXVar18,"Subject: %s\n");
                local_60 = local_5c;
              }
              if (local_88 == 6) {
                if (pXVar13 == (X509 *)0x76) {
                  local_60 = local_38;
                }
                if (pXVar13 != (X509 *)0x76) {
                  local_60 = local_a4;
                }
                SMIME_write_PKCS7((BIO *)pXVar18,(PKCS7 *)local_a8,(BIO *)local_60,local_8c);
                pXVar17 = (X509 *)0x0;
                pXVar12 = (X509 *)0x0;
              }
              else if (local_88 == 3) {
                PEM_write_bio_PKCS7_stream
                          ((BIO *)pXVar18,(PKCS7 *)local_a8,(BIO *)local_a4,local_8c);
                pXVar17 = (X509 *)0x0;
                pXVar12 = (X509 *)0x0;
              }
              else if (local_88 == 1) {
                i2d_PKCS7_bio_stream((BIO *)pXVar18,(PKCS7 *)local_a8,(BIO *)local_a4,local_8c);
                pXVar17 = (X509 *)0x0;
                pXVar12 = (X509 *)0x0;
              }
              else {
                BIO_printf(bio_err,"Bad output format for PKCS#7 file\n");
                pXVar17 = (X509 *)&DAT_00000004;
                pXVar12 = (X509 *)0x0;
              }
            }
          }
          else {
            if (store == (X509 *)0x0) goto LAB_0003c4d2;
            if (pXVar13 != (X509 *)0x53) {
              pXVar3 = (X509 *)0x0;
              goto LAB_0003c3f8;
            }
            if ((int)(local_8c << 0x19) < 0) {
              if (local_88 == 6) {
LAB_0003c8e2:
                local_8c = local_8c | 0x1000;
              }
            }
            else if (local_68 != 0) goto LAB_0003c8e2;
            local_8c = local_8c | 0x4000;
            local_a8 = (X509 *)PKCS7_sign((X509 *)0x0,(EVP_PKEY *)0x0,(stack_st_X509 *)local_a0,
                                          (BIO *)local_a4,local_8c);
            pXVar3 = (X509 *)0x0;
            if (local_a8 != (X509 *)0x0) goto LAB_0003c400;
            pXVar17 = (X509 *)0x3;
            pXVar3 = local_a8;
            pXVar12 = local_a8;
          }
        }
        else {
          pXVar3 = (X509 *)load_cert(bio_err,local_a4,3,0,uVar5,"recipient certificate file");
          local_9c = pXVar3;
          if (pXVar3 != (X509 *)0x0) goto joined_r0x0003c580;
          pXVar17 = (X509 *)0x2;
          ERR_print_errors(bio_err);
          pXVar18 = pXVar3;
          pkey = pXVar3;
          pXVar12 = pXVar3;
          local_a8 = pXVar3;
          local_a4 = pXVar3;
        }
      }
      else {
        pXVar17 = (X509 *)0x2;
        ERR_print_errors(bio_err);
        pXVar18 = pXVar3;
        pkey = pXVar3;
        pXVar12 = pXVar3;
        local_a8 = pXVar3;
        local_a4 = pXVar3;
        local_9c = pXVar3;
      }
    }
    else {
      uVar15 = count_leading_zeroes(local_94);
      uVar15 = uVar15 >> 5;
      if (local_a8 == (X509 *)0x0) {
        uVar15 = 0;
      }
      if (uVar15 == 0) {
        if (local_94 != (X509 *)0x0) {
          if (pXVar19 == (X509 *)0x0) {
            pXVar19 = (X509 *)sk_new_null();
          }
          sk_push((_STACK *)pXVar19,local_94);
          if (pXVar16 == (X509 *)0x0) {
            pXVar16 = (X509 *)sk_new_null();
          }
          if (local_a8 == (X509 *)0x0) {
            local_a8 = local_94;
          }
          sk_push((_STACK *)pXVar16,local_a8);
        }
        if (pXVar19 == (X509 *)0x0) {
          BIO_printf(bio_err,"No signer certificate specified\n");
          bVar2 = true;
          pXVar13 = pXVar16;
          goto LAB_0003bbd8;
        }
        local_a8 = (X509 *)0x0;
        local_94 = (X509 *)0x0;
        bVar2 = true;
        pXVar3 = local_34;
        goto LAB_0003c0c8;
      }
LAB_0003c214:
      BIO_puts(bio_err,"Illegal -inkey without -signer\n");
LAB_0003bbdc:
      pXVar3 = (X509 *)0x0;
      BIO_printf(bio_err,"Usage smime [options] cert.pem ...\n");
      BIO_printf(bio_err,"where options are\n");
      BIO_printf(bio_err,"-encrypt       encrypt message\n");
      BIO_printf(bio_err,"-decrypt       decrypt encrypted message\n");
      BIO_printf(bio_err,"-sign          sign message\n");
      BIO_printf(bio_err,"-verify        verify signed message\n");
      BIO_printf(bio_err,"-pk7out        output PKCS#7 structure\n");
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
      BIO_printf(bio_err,"-signer file   signer certificate file\n");
      BIO_printf(bio_err,"-recip  file   recipient certificate file for decryption\n");
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
                 "-crl_check_all check revocation status of signer\'s certificate chain using CRLs\n"
                );
      BIO_printf(bio_err,"-engine e      use engine e, possibly a hardware device.\n");
      BIO_printf(bio_err,"-passin arg    input file pass phrase source\n");
      BIO_printf(bio_err,"-rand file%cfile%c...\n",0x3a,0x3a);
      BIO_printf(bio_err,"               load the file (or the files in the directory) into\n");
      BIO_printf(bio_err,"               the random number generator\n");
      format = "cert.pem       recipient certificate(s) for encryption\n";
LAB_0003be7e:
      BIO_printf(bio_err,format);
      pXVar17 = (X509 *)0x1;
      pXVar18 = pXVar3;
      pkey = pXVar3;
      pXVar12 = pXVar3;
      local_a8 = pXVar3;
      local_a4 = pXVar3;
      local_a0 = pXVar3;
      local_9c = pXVar3;
      local_98 = pXVar3;
    }
LAB_0003be94:
    if (bVar2) {
      app_RAND_write_file(0,bio_err);
    }
    if (pXVar17 == (X509 *)0x0) goto LAB_0003beca;
  }
  ERR_print_errors(bio_err);
LAB_0003beca:
  sk_pop_free((_STACK *)local_98,X509_free);
  sk_pop_free((_STACK *)local_a0,X509_free);
  if (local_2c[0] != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(local_2c[0]);
  }
  if (pXVar19 != (X509 *)0x0) {
    sk_free((_STACK *)pXVar19);
  }
  if (pXVar16 != (X509 *)0x0) {
    sk_free((_STACK *)pXVar16);
  }
  X509_STORE_free((X509_STORE *)pXVar3);
  X509_free((X509 *)0x0);
  X509_free(local_9c);
  X509_free(pXVar12);
  EVP_PKEY_free((EVP_PKEY *)pkey);
  PKCS7_free((PKCS7 *)local_a8);
  BIO_free((BIO *)local_a4);
  BIO_free((BIO *)local_38);
  BIO_free_all((BIO *)pXVar18);
  if (local_30 != (void *)0x0) {
    CRYPTO_free(local_30);
  }
  return pXVar17;
}

