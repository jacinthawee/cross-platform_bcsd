
undefined4 crl_main(int param_1,int param_2)

{
  char **ppcVar1;
  ASN1_TIME *a;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  BIO_METHOD *pBVar6;
  BIO *pBVar7;
  long lVar8;
  X509_LOOKUP_METHOD *pXVar9;
  X509_LOOKUP *pXVar10;
  ASN1_INTEGER *a_00;
  int iVar11;
  char **ppcVar12;
  undefined4 uVar13;
  undefined1 *puVar14;
  X509_STORE *v;
  char *pcVar15;
  char *pcVar16;
  int in_GS_OFFSET;
  bool bVar17;
  byte bVar18;
  char *pcVar19;
  X509_NAME *name;
  X509_CRL *local_144;
  int local_140;
  char *local_13c;
  char *local_138;
  int local_134;
  int local_130;
  int local_12c;
  EVP_MD *local_124;
  char *local_120;
  int local_11c;
  char *local_118;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  undefined4 local_f8;
  uint local_f4;
  X509_OBJECT local_f0;
  X509_STORE_CTX local_e8;
  byte local_60 [64];
  int local_20;
  
  bVar18 = 0;
  local_f8 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_124 = EVP_sha1();
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar6 = BIO_s_file();
    bio_err = BIO_new(pBVar6);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar5 = load_config(bio_err,0);
  if (iVar5 != 0) {
    if (bio_out == (BIO *)0x0) {
      pBVar6 = BIO_s_file();
      bio_out = BIO_new(pBVar6);
      if (bio_out != (BIO *)0x0) {
        BIO_ctrl(bio_out,0x6a,0,stdout);
      }
    }
    ppcVar12 = (char **)(param_2 + 4);
    bVar3 = false;
    param_1 = param_1 + -1;
    bVar17 = param_1 == 0;
    if (param_1 < 1) {
      local_104 = 0;
      local_108 = 0;
      bVar4 = false;
      local_110 = 0;
      local_10c = 0;
      local_12c = 0;
      local_130 = 0;
      local_134 = 0;
      local_138 = (char *)0x0;
      local_13c = (char *)0x0;
      local_140 = 3;
      local_144 = (X509_CRL *)0x3;
      local_11c = 0;
      local_120 = (char *)0x0;
      local_118 = (char *)0x0;
      local_100 = 0;
    }
    else {
      local_100 = 0;
      local_104 = 0;
      local_108 = 0;
      bVar4 = false;
      local_110 = 0;
      local_10c = 0;
      local_12c = 0;
      local_130 = 0;
      local_134 = 0;
      local_138 = (char *)0x0;
      local_13c = (char *)0x0;
      local_140 = 3;
      local_144 = (X509_CRL *)0x3;
      local_11c = 0;
      local_120 = (char *)0x0;
      local_118 = (char *)0x0;
LAB_0805d326:
      do {
        pcVar19 = *ppcVar12;
        iVar5 = 8;
        pcVar15 = pcVar19;
        pcVar16 = "-inform";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar17 = *pcVar15 == *pcVar16;
          pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
          pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
        } while (bVar17);
        if (bVar17) {
          param_1 = param_1 + -1;
          if (param_1 != 0) {
            ppcVar1 = ppcVar12 + 1;
            ppcVar12 = ppcVar12 + 1;
            local_144 = (X509_CRL *)str2fmt(*ppcVar1);
            goto LAB_0805d31e;
          }
LAB_0805d670:
          puVar14 = crl_usage;
          iVar5 = crl_usage._0_4_;
          while (iVar5 != 0) {
            puVar14 = (undefined1 *)((int)puVar14 + 4);
            BIO_printf(bio_err,"%s",iVar5);
            iVar5 = *(int *)puVar14;
          }
          goto LAB_0805d570;
        }
        iVar5 = 9;
        pcVar15 = pcVar19;
        pcVar16 = "-outform";
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          bVar17 = *pcVar15 == *pcVar16;
          pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
          pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
        } while (bVar17);
        if (bVar17) {
          if (param_1 == 1) goto LAB_0805d670;
          local_140 = str2fmt(ppcVar12[1]);
          param_1 = param_1 + -2;
          bVar17 = param_1 == 0;
          ppcVar12 = ppcVar12 + 2;
          if (bVar17) break;
          goto LAB_0805d326;
        }
        bVar17 = *pcVar19 == '-';
        if ((((bVar17) && (bVar17 = pcVar19[1] == 'i', bVar17)) &&
            (bVar17 = pcVar19[2] == 'n', bVar17)) && (bVar17 = pcVar19[3] == '\0', bVar17)) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0805d670;
          local_13c = ppcVar12[1];
          ppcVar12 = ppcVar12 + 1;
        }
        else {
          iVar5 = 5;
          pcVar15 = pcVar19;
          pcVar16 = "-out";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar17 = *pcVar15 == *pcVar16;
            pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
            pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
          } while (bVar17);
          if (bVar17) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0805d670;
            local_138 = ppcVar12[1];
            ppcVar12 = ppcVar12 + 1;
          }
          else {
            iVar5 = 8;
            pcVar15 = pcVar19;
            pcVar16 = "-CApath";
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar17 = *pcVar15 == *pcVar16;
              pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
              pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
            } while (bVar17);
            if (bVar17) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0805d670;
              local_120 = ppcVar12[1];
              ppcVar12 = ppcVar12 + 1;
              bVar3 = true;
            }
            else {
              iVar5 = 8;
              pcVar15 = pcVar19;
              pcVar16 = "-CAfile";
              do {
                if (iVar5 == 0) break;
                iVar5 = iVar5 + -1;
                bVar17 = *pcVar15 == *pcVar16;
                pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
              } while (bVar17);
              if (bVar17) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_0805d670;
                local_118 = ppcVar12[1];
                ppcVar12 = ppcVar12 + 1;
                bVar3 = true;
              }
              else {
                iVar5 = 8;
                pcVar15 = pcVar19;
                pcVar16 = "-verify";
                do {
                  if (iVar5 == 0) break;
                  iVar5 = iVar5 + -1;
                  bVar17 = *pcVar15 == *pcVar16;
                  pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                  pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                } while (bVar17);
                if (bVar17) {
                  bVar3 = true;
                }
                else {
                  iVar5 = 6;
                  pcVar15 = pcVar19;
                  pcVar16 = "-text";
                  do {
                    if (iVar5 == 0) break;
                    iVar5 = iVar5 + -1;
                    bVar17 = *pcVar15 == *pcVar16;
                    pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                    pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                  } while (bVar17);
                  if (bVar17) {
                    bVar4 = true;
                  }
                  else {
                    iVar5 = 6;
                    pcVar15 = pcVar19;
                    pcVar16 = "-hash";
                    do {
                      if (iVar5 == 0) break;
                      iVar5 = iVar5 + -1;
                      bVar17 = *pcVar15 == *pcVar16;
                      pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                      pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                    } while (bVar17);
                    if (bVar17) {
                      local_134 = local_11c + 1;
                      local_11c = local_134;
                    }
                    else {
                      iVar5 = 10;
                      pcVar15 = pcVar19;
                      pcVar16 = "-hash_old";
                      do {
                        if (iVar5 == 0) break;
                        iVar5 = iVar5 + -1;
                        bVar17 = *pcVar15 == *pcVar16;
                        pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                        pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                      } while (bVar17);
                      if (bVar17) {
                        local_11c = local_11c + 1;
                        local_108 = local_11c;
                      }
                      else {
                        iVar5 = 9;
                        pcVar15 = pcVar19;
                        pcVar16 = "-nameopt";
                        do {
                          if (iVar5 == 0) break;
                          iVar5 = iVar5 + -1;
                          bVar17 = *pcVar15 == *pcVar16;
                          pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                          pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                        } while (bVar17);
                        if (bVar17) {
                          param_1 = param_1 + -1;
                          if (param_1 != 0) {
                            ppcVar1 = ppcVar12 + 1;
                            ppcVar12 = ppcVar12 + 1;
                            iVar5 = set_name_ex(&local_f8,*ppcVar1);
                            if (iVar5 != 0) goto LAB_0805d31e;
                          }
                          goto LAB_0805d670;
                        }
                        iVar5 = 8;
                        pcVar15 = pcVar19;
                        pcVar16 = "-issuer";
                        do {
                          if (iVar5 == 0) break;
                          iVar5 = iVar5 + -1;
                          bVar17 = *pcVar15 == *pcVar16;
                          pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                          pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                        } while (bVar17);
                        if (bVar17) {
                          local_130 = local_11c + 1;
                          local_11c = local_130;
                        }
                        else {
                          iVar5 = 0xc;
                          pcVar15 = pcVar19;
                          pcVar16 = "-lastupdate";
                          do {
                            if (iVar5 == 0) break;
                            iVar5 = iVar5 + -1;
                            bVar17 = *pcVar15 == *pcVar16;
                            pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                            pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                          } while (bVar17);
                          if (bVar17) {
                            local_12c = local_11c + 1;
                            local_11c = local_12c;
                          }
                          else {
                            iVar5 = 0xc;
                            pcVar15 = pcVar19;
                            pcVar16 = "-nextupdate";
                            do {
                              if (iVar5 == 0) break;
                              iVar5 = iVar5 + -1;
                              bVar17 = *pcVar15 == *pcVar16;
                              pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                              pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                            } while (bVar17);
                            if (bVar17) {
                              local_11c = local_11c + 1;
                              local_10c = local_11c;
                            }
                            else {
                              iVar5 = 7;
                              pcVar15 = pcVar19;
                              pcVar16 = "-noout";
                              do {
                                if (iVar5 == 0) break;
                                iVar5 = iVar5 + -1;
                                bVar17 = *pcVar15 == *pcVar16;
                                pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                                pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                              } while (bVar17);
                              if (bVar17) {
                                local_11c = local_11c + 1;
                                local_110 = local_11c;
                              }
                              else {
                                iVar5 = 0xd;
                                pcVar15 = pcVar19;
                                pcVar16 = "-fingerprint";
                                do {
                                  if (iVar5 == 0) break;
                                  iVar5 = iVar5 + -1;
                                  bVar17 = *pcVar15 == *pcVar16;
                                  pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                                  pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                                } while (bVar17);
                                if (bVar17) {
                                  local_11c = local_11c + 1;
                                  local_104 = local_11c;
                                }
                                else {
                                  iVar5 = 0xb;
                                  pcVar15 = pcVar19;
                                  pcVar16 = "-crlnumber";
                                  do {
                                    if (iVar5 == 0) break;
                                    iVar5 = iVar5 + -1;
                                    bVar17 = *pcVar15 == *pcVar16;
                                    pcVar15 = pcVar15 + (uint)bVar18 * -2 + 1;
                                    pcVar16 = pcVar16 + (uint)bVar18 * -2 + 1;
                                  } while (bVar17);
                                  if (bVar17) {
                                    local_11c = local_11c + 1;
                                    local_100 = local_11c;
                                  }
                                  else {
                                    local_124 = EVP_get_digestbyname(pcVar19 + 1);
                                    if (local_124 == (EVP_MD *)0x0) {
                                      BIO_printf(bio_err,"unknown option %s\n",*ppcVar12);
                                      goto LAB_0805d670;
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
LAB_0805d31e:
        param_1 = param_1 + -1;
        bVar17 = param_1 == 0;
        ppcVar12 = ppcVar12 + 1;
      } while (!bVar17);
    }
    ERR_load_crypto_strings();
    pBVar6 = BIO_s_file();
    pBVar7 = BIO_new(pBVar6);
    if (pBVar7 == (BIO *)0x0) {
      ERR_print_errors(bio_err);
    }
    else {
      if (local_13c == (char *)0x0) {
        name = (X509_NAME *)0x0;
        BIO_ctrl(pBVar7,0x6a,0,stdin);
      }
      else {
        name = (X509_NAME *)0x3;
        lVar8 = BIO_ctrl(pBVar7,0x6c,3,local_13c);
        if (lVar8 < 1) {
          perror(local_13c);
          goto LAB_0805d560;
        }
      }
      if (local_144 == (X509_CRL *)0x1) {
        local_144 = d2i_X509_CRL_bio(pBVar7,(X509_CRL **)0x0);
      }
      else {
        if (local_144 != (X509_CRL *)0x3) {
          BIO_printf(bio_err,"bad input format specified for input crl\n");
          goto LAB_0805d560;
        }
        name = (X509_NAME *)0x0;
        local_144 = PEM_read_bio_X509_CRL(pBVar7,(X509_CRL **)0x0,(undefined1 *)0x0,(void *)0x0);
      }
      if (local_144 != (X509_CRL *)0x0) {
        v = (X509_STORE *)0x0;
        BIO_free(pBVar7);
        if (bVar3) {
          v = X509_STORE_new();
          pXVar9 = X509_LOOKUP_file();
          pXVar10 = X509_STORE_add_lookup(v,pXVar9);
          if (pXVar10 != (X509_LOOKUP *)0x0) {
            iVar5 = X509_LOOKUP_ctrl(pXVar10,1,local_118,1,(char **)0x0);
            if (iVar5 == 0) {
              X509_LOOKUP_ctrl(pXVar10,1,(char *)0x0,3,(char **)0x0);
            }
            pXVar9 = X509_LOOKUP_hash_dir();
            pXVar10 = X509_STORE_add_lookup(v,pXVar9);
            if (pXVar10 != (X509_LOOKUP *)0x0) {
              iVar5 = X509_LOOKUP_ctrl(pXVar10,2,local_120,1,(char **)0x0);
              if (iVar5 == 0) {
                X509_LOOKUP_ctrl(pXVar10,2,(char *)0x0,3,(char **)0x0);
              }
              ERR_clear_error();
              iVar5 = X509_STORE_CTX_init(&local_e8,v,(X509 *)0x0,(stack_st_X509 *)0x0);
              if (iVar5 == 0) {
                pcVar19 = "Error initialising X509 store\n";
              }
              else {
                name = local_144->crl->issuer;
                iVar5 = X509_STORE_get_by_subject(&local_e8,1,name,&local_f0);
                if (0 < iVar5) {
                  pBVar7 = (BIO *)X509_get_pubkey(local_f0.data.x509);
                  X509_OBJECT_free_contents(&local_f0);
                  if (pBVar7 == (BIO *)0x0) {
                    uVar13 = 1;
                    BIO_printf(bio_err,"Error getting CRL issuer public key\n");
                    goto LAB_0805d500;
                  }
                  iVar5 = X509_CRL_verify(local_144,(EVP_PKEY *)pBVar7);
                  EVP_PKEY_free((EVP_PKEY *)pBVar7);
                  if (-1 < iVar5) {
                    if (iVar5 == 0) {
                      BIO_printf(bio_err,"verify failure\n");
                    }
                    else {
                      BIO_printf(bio_err,"verify OK\n");
                    }
                    goto LAB_0805d406;
                  }
                  goto LAB_0805d9ac;
                }
                pcVar19 = "Error getting CRL issuer certificate\n";
              }
LAB_0805d90a:
              pBVar7 = (BIO *)0x0;
              uVar13 = 1;
              BIO_printf(bio_err,pcVar19);
              goto LAB_0805d500;
            }
          }
LAB_0805d9ac:
          pBVar7 = (BIO *)0x0;
          uVar13 = 1;
        }
        else {
LAB_0805d406:
          iVar5 = 1;
          if (local_11c != 0) {
            do {
              if (local_130 == iVar5) {
                name = local_144->crl->issuer;
                print_name(bio_out,"issuer=",name,local_f8);
              }
              if (local_100 == iVar5) {
                name = (X509_NAME *)0x0;
                a_00 = (ASN1_INTEGER *)X509_CRL_get_ext_d2i(local_144,0x58,(int *)0x0,(int *)0x0);
                BIO_printf(bio_out,"crlNumber=");
                if (a_00 == (ASN1_INTEGER *)0x0) {
                  BIO_puts(bio_out,"<NONE>");
                }
                else {
                  i2a_ASN1_INTEGER(bio_out,a_00);
                  ASN1_INTEGER_free(a_00);
                }
                BIO_printf(bio_out,"\n");
              }
              if (local_134 == iVar5) {
                name = (X509_NAME *)X509_NAME_hash(local_144->crl->issuer);
                BIO_printf(bio_out,"%08lx\n",name);
              }
              if (iVar5 == local_108) {
                name = (X509_NAME *)X509_NAME_hash_old(local_144->crl->issuer);
                BIO_printf(bio_out,"%08lx\n",name);
              }
              if (local_12c == iVar5) {
                BIO_printf(bio_out,"lastUpdate=",name);
                ASN1_TIME_print(bio_out,local_144->crl->lastUpdate);
                BIO_printf(bio_out,"\n");
              }
              if (iVar5 == local_10c) {
                BIO_printf(bio_out,"nextUpdate=",name);
                a = local_144->crl->nextUpdate;
                if (a == (ASN1_TIME *)0x0) {
                  BIO_printf(bio_out,"NONE",name);
                }
                else {
                  ASN1_TIME_print(bio_out,a);
                }
                BIO_printf(bio_out,"\n");
              }
              if (iVar5 == local_104) {
                iVar11 = X509_CRL_digest(local_144,local_124,local_60,&local_f4);
                if (iVar11 == 0) {
                  pcVar19 = "out of memory\n";
                  goto LAB_0805d90a;
                }
                iVar11 = EVP_MD_type(local_124);
                name = (X509_NAME *)OBJ_nid2sn(iVar11);
                BIO_printf(bio_out,"%s Fingerprint=",name);
                if (0 < (int)local_f4) {
                  local_13c = (char *)0x0;
                  do {
                    uVar2 = (int)local_13c + 1;
                    uVar13 = 10;
                    if (uVar2 != local_f4) {
                      uVar13 = 0x3a;
                    }
                    name = (X509_NAME *)(uint)local_60[(int)local_13c];
                    BIO_printf(bio_out,"%02X%c",name,uVar13);
                    local_13c = (char *)uVar2;
                  } while ((int)uVar2 < (int)local_f4);
                }
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 <= local_11c);
          }
          pBVar6 = BIO_s_file();
          pBVar7 = BIO_new(pBVar6);
          if (pBVar7 == (BIO *)0x0) {
            uVar13 = 1;
            ERR_print_errors(bio_err);
          }
          else {
            if (local_138 == (char *)0x0) {
              BIO_ctrl(pBVar7,0x6a,0,stdout);
            }
            else {
              lVar8 = BIO_ctrl(pBVar7,0x6c,5,local_138);
              if (lVar8 < 1) {
                uVar13 = 1;
                perror(local_138);
                goto LAB_0805d500;
              }
            }
            if (bVar4) {
              X509_CRL_print(pBVar7,local_144);
            }
            uVar13 = 0;
            if (local_110 == 0) {
              if (local_140 == 1) {
                iVar5 = i2d_X509_CRL_bio(pBVar7,local_144);
              }
              else {
                if (local_140 != 3) {
                  uVar13 = 1;
                  BIO_printf(bio_err,"bad output format specified for outfile\n");
                  goto LAB_0805d500;
                }
                iVar5 = PEM_write_bio_X509_CRL(pBVar7,local_144);
              }
              uVar13 = 0;
              if (iVar5 == 0) {
                uVar13 = 1;
                BIO_printf(bio_err,"unable to write CRL\n");
              }
            }
          }
        }
LAB_0805d500:
        BIO_free_all(pBVar7);
        BIO_free_all(bio_out);
        bio_out = (BIO *)0x0;
        X509_CRL_free(local_144);
        if (v != (X509_STORE *)0x0) {
          X509_STORE_CTX_cleanup(&local_e8);
          X509_STORE_free(v);
        }
        goto LAB_0805d5a4;
      }
      BIO_printf(bio_err,"unable to load CRL\n");
      ERR_print_errors(bio_err);
    }
LAB_0805d560:
    BIO_free(pBVar7);
  }
LAB_0805d570:
  uVar13 = 1;
  BIO_free_all((BIO *)0x0);
  BIO_free_all(bio_out);
  bio_out = (BIO *)0x0;
  X509_CRL_free((X509_CRL *)0x0);
LAB_0805d5a4:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar13;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

