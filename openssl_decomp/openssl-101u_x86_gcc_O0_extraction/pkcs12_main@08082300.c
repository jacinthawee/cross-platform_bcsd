
/* WARNING: Could not reconcile some variable overlaps */

undefined4 pkcs12_main(undefined4 param_1,int param_2)

{
  char **ppcVar1;
  int *piVar2;
  uchar **ppuVar3;
  ASN1_INTEGER *a;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  _STACK *st;
  _STACK *p_Var12;
  uchar *name;
  X509 *pXVar13;
  long lVar14;
  X509_STORE *ctx;
  void *pvVar15;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  BIO *bp;
  undefined4 uVar19;
  EVP_MD *md_type;
  PKCS12 *p12;
  char *pcVar20;
  int in_GS_OFFSET;
  bool bVar21;
  byte bVar22;
  undefined8 uVar23;
  char *pcVar24;
  char *pcVar25;
  BIO *local_188;
  EVP_PKEY *local_184;
  X509 *local_180;
  int local_17c;
  _STACK *local_178;
  char local_172;
  bool local_171;
  int local_170;
  char *local_16c;
  char *local_168;
  char *local_164;
  char *local_160;
  int local_154;
  int local_150;
  int local_148;
  int local_144;
  uchar *local_140;
  char *local_138;
  char *local_134;
  int local_130;
  char *local_12c;
  char *local_124;
  char *local_120;
  int local_11c;
  char *local_114;
  char *local_110;
  X509_STORE_CTX local_10c;
  char local_84 [50];
  char local_52 [50];
  int local_20;
  
  bVar22 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_114 = (char *)0x0;
  local_110 = (char *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  enc = EVP_des_ede3_cbc();
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar11 = load_config(bio_err,0);
  if (iVar11 == 0) {
    uVar19 = 1;
    BIO_free((BIO *)0x0);
    BIO_free_all((BIO *)0x0);
    goto LAB_0808289e;
  }
  iVar11 = param_2 + 4;
  pcVar24 = *(char **)(param_2 + 4);
  local_11c = 0x95;
  if (pcVar24 != (char *)0x0) {
    local_160 = (char *)0x0;
    local_120 = (char *)0x0;
    local_124 = (char *)0x0;
    local_138 = (char *)0x0;
    local_170 = 0;
    local_16c = (char *)0x0;
    local_150 = 0;
    local_154 = 0;
    local_178 = (_STACK *)0x0;
    bVar9 = false;
    bVar10 = true;
    local_17c = 0;
    bVar6 = false;
    local_144 = 0x800;
    local_130 = 0x800;
    bVar5 = false;
    bVar7 = false;
    local_184 = (EVP_PKEY *)0x0;
    local_180 = (X509 *)0x0;
    bVar8 = false;
    local_140 = (uchar *)0x0;
    local_134 = (char *)0x0;
    local_148 = 0;
    local_12c = (char *)0x0;
    local_164 = (char *)0x0;
    local_168 = (char *)0x0;
    do {
      bVar21 = *pcVar24 == '-';
      if (!bVar21) goto LAB_08082460;
      iVar16 = 8;
      pcVar25 = pcVar24;
      pcVar20 = "-nokeys";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar25 == *pcVar20;
        pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        pcVar24 = *(char **)(iVar11 + 4);
        local_184 = (EVP_PKEY *)((uint)local_184 | 1);
      }
      else {
        iVar16 = 7;
        pcVar25 = pcVar24;
        pcVar20 = "-keyex";
        do {
          if (iVar16 == 0) break;
          iVar16 = iVar16 + -1;
          bVar21 = *pcVar25 == *pcVar20;
          pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
          pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        } while (bVar21);
        bVar4 = bVar5;
        if (bVar21) {
          local_17c = 0x10;
        }
        else {
          iVar16 = 8;
          pcVar25 = pcVar24;
          pcVar20 = "-keysig";
          do {
            if (iVar16 == 0) break;
            iVar16 = iVar16 + -1;
            bVar21 = *pcVar25 == *pcVar20;
            pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
            pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
          } while (bVar21);
          if (bVar21) {
            local_17c = 0x80;
          }
          else {
            iVar16 = 9;
            pcVar25 = pcVar24;
            pcVar20 = "-nocerts";
            do {
              if (iVar16 == 0) break;
              iVar16 = iVar16 + -1;
              bVar21 = *pcVar25 == *pcVar20;
              pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
              pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
            } while (bVar21);
            if (bVar21) {
              local_184 = (EVP_PKEY *)((uint)local_184 | 2);
            }
            else {
              iVar16 = 9;
              pcVar25 = pcVar24;
              pcVar20 = "-clcerts";
              do {
                if (iVar16 == 0) break;
                iVar16 = iVar16 + -1;
                bVar21 = *pcVar25 == *pcVar20;
                pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
                pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
              } while (bVar21);
              if (bVar21) {
                local_184 = (EVP_PKEY *)((uint)local_184 | 8);
              }
              else {
                iVar16 = 9;
                pcVar25 = pcVar24;
                pcVar20 = "-cacerts";
                do {
                  if (iVar16 == 0) break;
                  iVar16 = iVar16 + -1;
                  bVar21 = *pcVar25 == *pcVar20;
                  pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
                  pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
                } while (bVar21);
                if (bVar21) {
                  local_184 = (EVP_PKEY *)((uint)local_184 | 0x10);
                }
                else {
                  iVar16 = 7;
                  pcVar25 = pcVar24;
                  pcVar20 = "-noout";
                  do {
                    if (iVar16 == 0) break;
                    iVar16 = iVar16 + -1;
                    bVar21 = *pcVar25 == *pcVar20;
                    pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
                    pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
                  } while (bVar21);
                  if (bVar21) {
                    local_184 = (EVP_PKEY *)((uint)local_184 | 3);
                  }
                  else {
                    iVar16 = 6;
                    pcVar25 = pcVar24;
                    pcVar20 = "-info";
                    do {
                      if (iVar16 == 0) break;
                      iVar16 = iVar16 + -1;
                      bVar21 = *pcVar25 == *pcVar20;
                      pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
                      pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
                    } while (bVar21);
                    if (bVar21) {
                      local_184 = (EVP_PKEY *)((uint)local_184 | 4);
                    }
                    else {
                      iVar16 = 7;
                      pcVar25 = pcVar24;
                      pcVar20 = "-chain";
                      do {
                        if (iVar16 == 0) break;
                        iVar16 = iVar16 + -1;
                        bVar21 = *pcVar25 == *pcVar20;
                        pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
                        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
                      } while (bVar21);
                      if (bVar21) {
                        bVar7 = true;
                      }
                      else {
                        iVar16 = 9;
                        pcVar25 = pcVar24;
                        pcVar20 = "-twopass";
                        do {
                          if (iVar16 == 0) break;
                          iVar16 = iVar16 + -1;
                          bVar21 = *pcVar25 == *pcVar20;
                          pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
                          pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
                        } while (bVar21);
                        if (bVar21) {
                          bVar6 = true;
                        }
                        else {
                          iVar16 = 10;
                          pcVar25 = pcVar24;
                          pcVar20 = "-nomacver";
                          do {
                            if (iVar16 == 0) break;
                            iVar16 = iVar16 + -1;
                            bVar21 = *pcVar25 == *pcVar20;
                            pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
                            pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
                          } while (bVar21);
                          if (bVar21) {
                            bVar10 = false;
                          }
                          else {
                            iVar16 = 9;
                            pcVar25 = pcVar24;
                            pcVar20 = "-descert";
                            do {
                              if (iVar16 == 0) break;
                              iVar16 = iVar16 + -1;
                              bVar21 = *pcVar25 == *pcVar20;
                              pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
                              pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
                            } while (bVar21);
                            if (bVar21) {
                              local_11c = 0x92;
                            }
                            else {
                              iVar16 = 8;
                              pcVar25 = pcVar24;
                              pcVar20 = "-export";
                              do {
                                if (iVar16 == 0) break;
                                iVar16 = iVar16 + -1;
                                bVar21 = *pcVar25 == *pcVar20;
                                pcVar25 = pcVar25 + (uint)bVar22 * -2 + 1;
                                pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
                              } while (bVar21);
                              if (bVar21) {
                                local_180 = (X509 *)0x1;
                              }
                              else {
                                iVar16 = strcmp(pcVar24,"-des");
                                if (iVar16 == 0) {
                                  enc = EVP_des_cbc();
                                }
                                else {
                                  iVar16 = strcmp(pcVar24,"-des3");
                                  if (iVar16 == 0) {
                                    enc = EVP_des_ede3_cbc();
                                  }
                                  else {
                                    iVar16 = strcmp(pcVar24,"-idea");
                                    if (iVar16 == 0) {
                                      enc = EVP_idea_cbc();
                                    }
                                    else {
                                      iVar16 = strcmp(pcVar24,"-seed");
                                      if (iVar16 == 0) {
                                        enc = EVP_seed_cbc();
                                      }
                                      else {
                                        iVar16 = strcmp(pcVar24,"-aes128");
                                        if (iVar16 == 0) {
                                          enc = EVP_aes_128_cbc();
                                        }
                                        else {
                                          iVar16 = strcmp(pcVar24,"-aes192");
                                          if (iVar16 == 0) {
                                            enc = EVP_aes_192_cbc();
                                          }
                                          else {
                                            iVar16 = strcmp(pcVar24,"-aes256");
                                            if (iVar16 == 0) {
                                              enc = EVP_aes_256_cbc();
                                            }
                                            else {
                                              iVar16 = strcmp(pcVar24,"-camellia128");
                                              if (iVar16 == 0) {
                                                enc = EVP_camellia_128_cbc();
                                              }
                                              else {
                                                iVar16 = strcmp(pcVar24,"-camellia192");
                                                if (iVar16 == 0) {
                                                  enc = EVP_camellia_192_cbc();
                                                }
                                                else {
                                                  iVar16 = strcmp(pcVar24,"-camellia256");
                                                  if (iVar16 == 0) {
                                                    enc = EVP_camellia_256_cbc();
                                                  }
                                                  else {
                                                    iVar16 = strcmp(pcVar24,"-noiter");
                                                    if (iVar16 == 0) {
                                                      local_130 = 1;
                                                    }
                                                    else {
                                                      iVar16 = strcmp(pcVar24,"-maciter");
                                                      if (iVar16 == 0) {
                                                        local_144 = 0x800;
                                                      }
                                                      else {
                                                        iVar16 = strcmp(pcVar24,"-nomaciter");
                                                        if (iVar16 == 0) {
                                                          local_144 = 1;
                                                        }
                                                        else {
                                                          iVar16 = strcmp(pcVar24,"-nomac");
                                                          if (iVar16 == 0) {
                                                            local_144 = -1;
                                                          }
                                                          else {
                                                            iVar16 = strcmp(pcVar24,"-macalg");
                                                            if (iVar16 == 0) {
                                                              ppcVar1 = (char **)(iVar11 + 4);
                                                              if (*ppcVar1 == (char *)0x0)
                                                              goto LAB_08082460;
                                                              iVar11 = iVar11 + 4;
                                                              local_138 = *ppcVar1;
                                                            }
                                                            else {
                                                              iVar16 = strcmp(pcVar24,"-nodes");
                                                              if (iVar16 == 0) {
                                                                enc = (EVP_CIPHER *)0x0;
                                                              }
                                                              else {
                                                                iVar16 = strcmp(pcVar24,"-certpbe");
                                                                if ((iVar16 == 0) ||
                                                                   (iVar16 = strcmp(pcVar24,
                                                  "-keypbe"), iVar16 == 0)) {
                                                    iVar11 = iVar11 + 4;
                                                    iVar16 = set_pbe_isra_0();
                                                    bVar4 = true;
                                                    if (iVar16 != 0) {
                                                      bVar4 = bVar5;
                                                    }
                                                  }
                                                  else {
                                                    iVar16 = strcmp(pcVar24,"-rand");
                                                    if (iVar16 == 0) {
                                                      piVar2 = (int *)(iVar11 + 4);
                                                      if (*piVar2 == 0) goto LAB_08082460;
                                                      iVar11 = iVar11 + 4;
                                                      local_170 = *piVar2;
                                                    }
                                                    else {
                                                      iVar16 = strcmp(pcVar24,"-inkey");
                                                      if (iVar16 == 0) {
                                                        ppcVar1 = (char **)(iVar11 + 4);
                                                        if (*ppcVar1 == (char *)0x0)
                                                        goto LAB_08082460;
                                                        iVar11 = iVar11 + 4;
                                                        local_12c = *ppcVar1;
                                                      }
                                                      else {
                                                        iVar16 = strcmp(pcVar24,"-certfile");
                                                        if (iVar16 == 0) {
                                                          piVar2 = (int *)(iVar11 + 4);
                                                          if (*piVar2 == 0) goto LAB_08082460;
                                                          iVar11 = iVar11 + 4;
                                                          local_148 = *piVar2;
                                                        }
                                                        else {
                                                          iVar16 = strcmp(pcVar24,"-name");
                                                          if (iVar16 == 0) {
                                                            ppcVar1 = (char **)(iVar11 + 4);
                                                            if (*ppcVar1 == (char *)0x0)
                                                            goto LAB_08082460;
                                                            iVar11 = iVar11 + 4;
                                                            local_134 = *ppcVar1;
                                                          }
                                                          else {
                                                            iVar16 = strcmp(pcVar24,"-LMK");
                                                            if (iVar16 == 0) {
                                                              bVar8 = true;
                                                            }
                                                            else {
                                                              iVar16 = strcmp(pcVar24,"-CSP");
                                                              if (iVar16 == 0) {
                                                                ppuVar3 = (uchar **)(iVar11 + 4);
                                                                if (*ppuVar3 == (uchar *)0x0)
                                                                goto LAB_08082460;
                                                                iVar11 = iVar11 + 4;
                                                                local_140 = *ppuVar3;
                                                              }
                                                              else {
                                                                iVar16 = strcmp(pcVar24,"-caname");
                                                                if (iVar16 == 0) {
                                                                  if (*(int *)(iVar11 + 4) == 0)
                                                                  goto LAB_08082460;
                                                                  if (local_178 == (_STACK *)0x0) {
                                                                    local_178 = sk_new_null();
                                                                  }
                                                                  sk_push(local_178,
                                                                          *(void **)(iVar11 + 4));
                                                                  iVar11 = iVar11 + 4;
                                                                }
                                                                else if (((pcVar24[1] == 'i') &&
                                                                         (pcVar24[2] == 'n')) &&
                                                                        (pcVar24[3] == '\0')) {
                                                                  ppcVar1 = (char **)(iVar11 + 4);
                                                                  if (*ppcVar1 == (char *)0x0)
                                                                  goto LAB_08082460;
                                                                  iVar11 = iVar11 + 4;
                                                                  local_168 = *ppcVar1;
                                                                }
                                                                else {
                                                                  iVar16 = strcmp(pcVar24,"-out");
                                                                  if (iVar16 == 0) {
                                                                    ppcVar1 = (char **)(iVar11 + 4);
                                                                    if (*ppcVar1 == (char *)0x0)
                                                                    goto LAB_08082460;
                                                                    iVar11 = iVar11 + 4;
                                                                    local_164 = *ppcVar1;
                                                                  }
                                                                  else {
                                                                    iVar16 = strcmp(pcVar24,
                                                  "-passin");
                                                  if (iVar16 == 0) {
                                                    piVar2 = (int *)(iVar11 + 4);
                                                    if (*piVar2 == 0) goto LAB_08082460;
                                                    iVar11 = iVar11 + 4;
                                                    local_154 = *piVar2;
                                                  }
                                                  else {
                                                    iVar16 = strcmp(pcVar24,"-passout");
                                                    if (iVar16 == 0) {
                                                      piVar2 = (int *)(iVar11 + 4);
                                                      if (*piVar2 == 0) goto LAB_08082460;
                                                      iVar11 = iVar11 + 4;
                                                      local_150 = *piVar2;
                                                    }
                                                    else {
                                                      iVar16 = strcmp(pcVar24,"-password");
                                                      if (iVar16 == 0) {
                                                        piVar2 = (int *)(iVar11 + 4);
                                                        if (*piVar2 == 0) goto LAB_08082460;
                                                        iVar11 = iVar11 + 4;
                                                        bVar9 = true;
                                                        local_16c = (char *)*piVar2;
                                                      }
                                                      else {
                                                        iVar16 = strcmp(pcVar24,"-CApath");
                                                        if (iVar16 == 0) {
                                                          ppcVar1 = (char **)(iVar11 + 4);
                                                          if (*ppcVar1 == (char *)0x0)
                                                          goto LAB_08082460;
                                                          iVar11 = iVar11 + 4;
                                                          local_124 = *ppcVar1;
                                                        }
                                                        else {
                                                          iVar16 = strcmp(pcVar24,"-CAfile");
                                                          if (iVar16 == 0) {
                                                            ppcVar1 = (char **)(iVar11 + 4);
                                                            if (*ppcVar1 == (char *)0x0) {
LAB_08082460:
                                                              bVar4 = true;
                                                            }
                                                            else {
                                                              iVar11 = iVar11 + 4;
                                                              local_120 = *ppcVar1;
                                                            }
                                                          }
                                                          else {
                                                            iVar16 = strcmp(pcVar24,"-engine");
                                                            if ((iVar16 != 0) ||
                                                               (piVar2 = (int *)(iVar11 + 4),
                                                               *piVar2 == 0)) goto LAB_08082460;
                                                            iVar11 = iVar11 + 4;
                                                            local_160 = (char *)*piVar2;
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
        pcVar24 = *(char **)(iVar11 + 4);
        bVar5 = bVar4;
      }
      if (pcVar24 == (char *)0x0) goto LAB_080824a0;
      iVar11 = iVar11 + 4;
    } while( true );
  }
  local_171 = false;
  local_172 = '\0';
  local_160 = (char *)0x0;
  local_120 = (char *)0x0;
  local_124 = (char *)0x0;
  local_138 = (char *)0x0;
  local_170 = 0;
  local_16c = (char *)0x0;
  local_150 = 0;
  local_154 = 0;
  local_178 = (_STACK *)0x0;
  bVar9 = false;
  bVar10 = true;
  local_17c = 0;
  bVar6 = false;
  local_144 = 0x800;
  local_130 = 0x800;
  bVar7 = false;
  local_184 = (EVP_PKEY *)0x0;
  local_180 = (X509 *)0x0;
  bVar8 = false;
  local_140 = (uchar *)0x0;
  local_134 = (char *)0x0;
  local_148 = 0;
  local_12c = (char *)0x0;
  local_164 = (char *)0x0;
  local_168 = (char *)0x0;
LAB_08082a50:
  pcVar24 = (char *)0x0;
  uVar19 = setup_engine(bio_err,local_160,0);
  if (local_16c != (char *)0x0) {
    if (local_180 == (X509 *)0x0) {
      iVar11 = app_passwd(bio_err,local_16c,local_150,&local_114,&local_110);
      if (iVar11 != 0) goto LAB_08082ab2;
    }
    else {
      iVar11 = app_passwd(bio_err,local_154,local_16c,&local_114,&local_110);
      if (iVar11 != 0) goto LAB_08082e21;
    }
LAB_08082ec0:
    pcVar24 = "Error getting passwords\n";
    goto LAB_08082819;
  }
  iVar11 = app_passwd(bio_err,local_154,local_150,&local_114,&local_110);
  if (iVar11 == 0) goto LAB_08082ec0;
  if (local_180 == (X509 *)0x0) {
LAB_08082ab2:
    local_160 = local_114;
    if (local_114 == (char *)0x0) {
LAB_08082f99:
      local_16c = local_52;
      local_160 = local_84;
    }
    else {
      local_16c = local_114;
      bVar9 = true;
    }
    if ((local_171 != false) || (local_172 != '\0')) goto LAB_08082e3d;
  }
  else {
LAB_08082e21:
    local_16c = local_110;
    if (local_110 == (char *)0x0) goto LAB_08082f99;
    local_160 = local_110;
    bVar9 = true;
LAB_08082e3d:
    pcVar24 = (char *)(uint)local_171;
    app_RAND_load_file(0,bio_err,pcVar24);
    if (local_171 != false) {
      pcVar24 = (char *)app_RAND_load_files(local_170);
      BIO_printf(bio_err,"%ld semi-random bytes loaded\n",pcVar24);
    }
  }
  ERR_load_crypto_strings();
  if (local_168 != (char *)0x0) {
    local_188 = BIO_new_file(local_168,"rb");
    pcVar25 = local_168;
    if (local_188 != (BIO *)0x0) goto LAB_08082b15;
LAB_08083135:
    bp = (BIO *)0x0;
    BIO_printf(bio_err,"Error opening input file %s\n",pcVar25);
    perror(local_168);
    local_188 = (BIO *)0x0;
    goto LAB_08082831;
  }
  local_188 = BIO_new_fp(stdin,0);
  if (local_188 == (BIO *)0x0) {
    pcVar25 = "<stdin>";
    goto LAB_08083135;
  }
LAB_08082b15:
  if (local_164 == (char *)0x0) {
    bp = BIO_new_fp(stdout,0);
    if (bp == (BIO *)0x0) {
      pcVar25 = "<stdout>";
      goto LAB_08083187;
    }
  }
  else {
    bp = BIO_new_file(local_164,"wb");
    pcVar25 = local_164;
    if (bp == (BIO *)0x0) {
LAB_08083187:
      bp = (BIO *)0x0;
      BIO_printf(bio_err,"Error opening output file %s\n",pcVar25);
      perror(local_164);
      goto LAB_08082831;
    }
  }
  if (bVar6) {
    pcVar24 = "Enter MAC Password:";
    iVar11 = EVP_read_pw_string(local_52,0x32,"Enter MAC Password:",(int)local_180);
    if (iVar11 != 0) {
      BIO_printf(bio_err,"Can\'t read Password\n");
      goto LAB_08082831;
    }
  }
  if (local_172 == '\0') {
    p12 = d2i_PKCS12_bio(local_188,(PKCS12 **)0x0);
    if (p12 == (PKCS12 *)0x0) {
      ERR_print_errors(bio_err);
      goto LAB_08082831;
    }
    if ((bVar9) ||
       (iVar11 = EVP_read_pw_string(local_84,0x32,"Enter Import Password:",0), iVar11 == 0)) {
      if (!bVar6) {
        BUF_strlcpy(local_52,local_84,0x32);
      }
      if ((((uint)local_184 & 4) != 0) && (p12->mac != (PKCS12_MAC_DATA *)0x0)) {
        a = p12->mac->iter;
        lVar14 = 1;
        if (a != (ASN1_INTEGER *)0x0) {
          lVar14 = ASN1_INTEGER_get(a);
        }
        BIO_printf(bio_err,"MAC Iteration %ld\n",lVar14);
      }
      if (bVar10) {
        if ((*local_16c == '\0') && (iVar11 = PKCS12_verify_mac(p12,(char *)0x0,0), iVar11 != 0)) {
          pcVar24 = (char *)0x0;
          if (bVar6) {
            pcVar24 = local_160;
          }
LAB_080830a7:
          local_160 = pcVar24;
          BIO_printf(bio_err,"MAC verified OK\n");
          goto LAB_080830bd;
        }
        iVar11 = PKCS12_verify_mac(p12,local_16c,-1);
        pcVar24 = local_160;
        if (iVar11 != 0) goto LAB_080830a7;
        pcVar24 = "Mac verify error: invalid password?\n";
      }
      else {
LAB_080830bd:
        uVar19 = 0;
        iVar11 = dump_certs_keys_p12(bp,p12,local_160,0xffffffff,local_184,local_110);
        if (iVar11 != 0) goto LAB_08082dc9;
        pcVar24 = "Error outputting keys and certificates\n";
      }
      uVar19 = 1;
      BIO_printf(bio_err,pcVar24);
      ERR_print_errors(bio_err);
    }
    else {
      uVar19 = 1;
      BIO_printf(bio_err,"Can\'t read Password\n");
    }
LAB_08082dc9:
    PKCS12_free(p12);
    goto LAB_08082836;
  }
  if (((uint)local_184 & 3) == 3) {
    BIO_printf(bio_err,"Nothing to do!\n");
LAB_0808295b:
    uVar19 = 1;
  }
  else {
    uVar18 = (uint)local_184 & 2;
    if (uVar18 == 0) {
      if (((uint)local_184 & 1) != 0) {
        st = (_STACK *)load_certs(bio_err,local_168,3,0,uVar19,"certificates");
        if (st == (_STACK *)0x0) goto LAB_0808295b;
        local_184 = (EVP_PKEY *)0x0;
        local_180 = (X509 *)0x0;
LAB_08082bbb:
        if (local_148 == 0) {
LAB_08082c21:
          if (!bVar7) goto LAB_08082c2d;
          ctx = X509_STORE_new();
          if (ctx == (X509_STORE *)0x0) {
            pcVar25 = "Memory allocation error\n";
            goto LAB_080832ea;
          }
          iVar11 = X509_STORE_load_locations(ctx,local_120,local_124);
          if (iVar11 == 0) {
            X509_STORE_set_default_paths(ctx);
          }
          iVar11 = X509_STORE_CTX_init(&local_10c,ctx,local_180,(stack_st_X509 *)0x0);
          if (iVar11 == 0) {
            X509_STORE_free(ctx);
          }
          else {
            iVar11 = X509_verify_cert(&local_10c);
            if (0 < iVar11) {
              p_Var12 = (_STACK *)X509_STORE_CTX_get1_chain(&local_10c);
              X509_STORE_CTX_cleanup(&local_10c);
              X509_STORE_free(ctx);
              for (iVar11 = 1; iVar16 = sk_num(p_Var12), iVar11 < iVar16; iVar11 = iVar11 + 1) {
                pvVar15 = sk_value(p_Var12,iVar11);
                sk_push(st,pvVar15);
              }
              pXVar13 = (X509 *)sk_value(p_Var12,0);
              X509_free(pXVar13);
              sk_free(p_Var12);
              goto LAB_08082c2d;
            }
            iVar11 = X509_STORE_CTX_get_error(&local_10c);
            if (iVar11 == 0) {
              X509_STORE_CTX_cleanup(&local_10c);
              X509_STORE_free(ctx);
            }
            else {
              X509_STORE_CTX_cleanup(&local_10c);
              X509_STORE_free(ctx);
              if (iVar11 != 1) {
                pcVar24 = X509_verify_cert_error_string(iVar11);
                pcVar25 = "Error %s getting chain.\n";
                goto LAB_080832ea;
              }
            }
          }
          uVar19 = 1;
          p12 = (PKCS12 *)0x0;
          ERR_print_errors(bio_err);
        }
        else {
          p_Var12 = (_STACK *)load_certs(bio_err,local_148,3,0,uVar19,"certificates from certfile");
          if (p_Var12 != (_STACK *)0x0) goto LAB_08082c05;
          uVar19 = 1;
          p12 = (PKCS12 *)0x0;
        }
        goto LAB_08082d81;
      }
LAB_08082f0a:
      if (local_12c == (char *)0x0) {
        local_12c = local_168;
      }
      pcVar24 = "private key";
      uVar23 = load_key(bio_err,local_12c,3,1,local_114,uVar19,"private key");
      uVar17 = (undefined4)((ulonglong)uVar23 >> 0x20);
      local_184 = (EVP_PKEY *)uVar23;
      if (local_184 == (EVP_PKEY *)0x0) goto LAB_0808295b;
      if (uVar18 != 0) {
        st = (_STACK *)0x0;
        local_180 = (X509 *)0x0;
        goto LAB_08082bbb;
      }
      st = (_STACK *)load_certs(bio_err,local_168,3,0,uVar19,"certificates",uVar17,uVar17);
      if (st == (_STACK *)0x0) {
        local_180 = (X509 *)0x0;
        uVar19 = 1;
        p12 = (PKCS12 *)0x0;
      }
      else {
        for (iVar11 = 0; iVar16 = sk_num(st), iVar11 < iVar16; iVar11 = iVar11 + 1) {
          local_180 = (X509 *)sk_value(st,iVar11);
          iVar16 = X509_check_private_key(local_180,local_184);
          if (iVar16 != 0) {
            X509_keyid_set1(local_180,(uchar *)0x0,0);
            pcVar24 = (char *)0x0;
            X509_alias_set1(local_180,(uchar *)0x0,0);
            sk_delete(st,iVar11);
            if (local_180 != (X509 *)0x0) goto LAB_08082bbb;
            break;
          }
        }
        uVar19 = 1;
        p12 = (PKCS12 *)0x0;
        BIO_printf(bio_err,"No certificate matches private key\n");
        local_180 = (X509 *)0x0;
      }
LAB_08082d89:
      EVP_PKEY_free(local_184);
    }
    else {
      bVar7 = false;
      if (((uint)local_184 & 1) == 0) goto LAB_08082f0a;
      if (local_148 != 0) {
        p_Var12 = (_STACK *)load_certs(bio_err,local_148,3,0,uVar19,"certificates from certfile");
        if (p_Var12 == (_STACK *)0x0) goto LAB_0808295b;
        st = (_STACK *)0x0;
        local_180 = (X509 *)0x0;
        local_184 = (EVP_PKEY *)0x0;
LAB_08082c05:
        while (iVar11 = sk_num(p_Var12), 0 < iVar11) {
          pvVar15 = sk_shift(p_Var12);
          sk_push(st,pvVar15);
        }
        sk_free(p_Var12);
        goto LAB_08082c21;
      }
      local_184 = (EVP_PKEY *)0x0;
      st = (_STACK *)0x0;
      local_180 = (X509 *)0x0;
LAB_08082c2d:
      for (iVar11 = 0; iVar16 = sk_num(local_178), iVar11 < iVar16; iVar11 = iVar11 + 1) {
        name = (uchar *)sk_value(local_178,iVar11);
        pXVar13 = (X509 *)sk_value(st,iVar11);
        X509_alias_set1(pXVar13,name,-1);
      }
      if ((local_140 != (uchar *)0x0) && (local_184 != (EVP_PKEY *)0x0)) {
        EVP_PKEY_add1_attr_by_NID(local_184,0x1a1,0x1001,local_140,-1);
      }
      if ((bVar8) && (local_184 != (EVP_PKEY *)0x0)) {
        EVP_PKEY_add1_attr_by_NID(local_184,0x358,0,(uchar *)0x0,-1);
      }
      if (!bVar9) {
        pcVar24 = "Enter Export Password:";
        iVar11 = EVP_read_pw_string(local_84,0x32,"Enter Export Password:",1);
        if (iVar11 != 0) {
          pcVar25 = "Can\'t read Password\n";
LAB_080832ea:
          uVar19 = 1;
          p12 = (PKCS12 *)0x0;
          BIO_printf(bio_err,pcVar25,pcVar24);
          goto LAB_08082d81;
        }
      }
      if (!bVar6) {
        BUF_strlcpy(local_52,local_84,0x32);
      }
      p12 = PKCS12_create(local_160,local_134,local_184,local_180,(stack_st_X509 *)st,0x92,local_11c
                          ,local_130,-1,local_17c);
      if (p12 == (PKCS12 *)0x0) {
        uVar19 = 1;
        ERR_print_errors(bio_err);
      }
      else {
        md_type = (EVP_MD *)0x0;
        if ((local_138 != (char *)0x0) &&
           (md_type = EVP_get_digestbyname(local_138), md_type == (EVP_MD *)0x0)) {
          BIO_printf(bio_err,"Unknown digest algorithm %s\n",local_138);
        }
        if (local_144 != -1) {
          PKCS12_set_mac(p12,local_16c,-1,(uchar *)0x0,0,local_144,md_type);
        }
        uVar19 = 0;
        i2d_PKCS12_bio(bp,p12);
      }
LAB_08082d81:
      if (local_184 != (EVP_PKEY *)0x0) goto LAB_08082d89;
    }
    if (st != (_STACK *)0x0) {
      sk_pop_free(st,X509_free);
    }
    if (local_180 != (X509 *)0x0) {
      X509_free(local_180);
    }
    if (p12 != (PKCS12 *)0x0) goto LAB_08082dc9;
  }
LAB_08082960:
  app_RAND_write_file(0,bio_err);
LAB_0808284c:
  BIO_free(local_188);
  BIO_free_all(bp);
  if (local_178 != (_STACK *)0x0) {
    sk_free(local_178);
  }
LAB_0808289e:
  if (local_114 != (char *)0x0) {
    CRYPTO_free(local_114);
  }
  if (local_110 != (char *)0x0) {
    CRYPTO_free(local_110);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar19;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_080824a0:
  local_171 = local_170 != 0;
  local_172 = (char)local_180;
  if (!bVar5) goto LAB_08082a50;
  BIO_printf(bio_err,"Usage: pkcs12 [options]\n");
  BIO_printf(bio_err,"where options are\n");
  BIO_printf(bio_err,"-export       output PKCS12 file\n");
  BIO_printf(bio_err,"-chain        add certificate chain\n");
  BIO_printf(bio_err,"-inkey file   private key if not infile\n");
  BIO_printf(bio_err,"-certfile f   add all certs in f\n");
  BIO_printf(bio_err,"-CApath arg   - PEM format directory of CA\'s\n");
  BIO_printf(bio_err,"-CAfile arg   - PEM format file of CA\'s\n");
  BIO_printf(bio_err,"-name \"name\"  use name as friendly name\n");
  BIO_printf(bio_err,"-caname \"nm\"  use nm as CA friendly name (can be used more than once).\n");
  BIO_printf(bio_err,"-in  infile   input filename\n");
  BIO_printf(bio_err,"-out outfile  output filename\n");
  BIO_printf(bio_err,"-noout        don\'t output anything, just verify.\n");
  BIO_printf(bio_err,"-nomacver     don\'t verify MAC.\n");
  BIO_printf(bio_err,"-nocerts      don\'t output certificates.\n");
  BIO_printf(bio_err,"-clcerts      only output client certificates.\n");
  BIO_printf(bio_err,"-cacerts      only output CA certificates.\n");
  BIO_printf(bio_err,"-nokeys       don\'t output private keys.\n");
  BIO_printf(bio_err,"-info         give info about PKCS#12 structure.\n");
  BIO_printf(bio_err,"-des          encrypt private keys with DES\n");
  BIO_printf(bio_err,"-des3         encrypt private keys with triple DES (default)\n");
  BIO_printf(bio_err,"-idea         encrypt private keys with idea\n");
  BIO_printf(bio_err,"-seed         encrypt private keys with seed\n");
  BIO_printf(bio_err,"-aes128, -aes192, -aes256\n");
  BIO_printf(bio_err,"              encrypt PEM output with cbc aes\n");
  BIO_printf(bio_err,"-camellia128, -camellia192, -camellia256\n");
  BIO_printf(bio_err,"              encrypt PEM output with cbc camellia\n");
  BIO_printf(bio_err,"-nodes        don\'t encrypt private keys\n");
  BIO_printf(bio_err,"-noiter       don\'t use encryption iteration\n");
  BIO_printf(bio_err,"-nomaciter    don\'t use MAC iteration\n");
  BIO_printf(bio_err,"-maciter      use MAC iteration\n");
  BIO_printf(bio_err,"-nomac        don\'t generate MAC\n");
  BIO_printf(bio_err,"-twopass      separate MAC, encryption passwords\n");
  BIO_printf(bio_err,"-descert      encrypt PKCS#12 certificates with triple DES (default RC2-40)\n"
            );
  BIO_printf(bio_err,"-certpbe alg  specify certificate PBE algorithm (default RC2-40)\n");
  BIO_printf(bio_err,"-keypbe alg   specify private key PBE algorithm (default 3DES)\n");
  BIO_printf(bio_err,"-macalg alg   digest algorithm used in MAC (default SHA1)\n");
  BIO_printf(bio_err,"-keyex        set MS key exchange type\n");
  BIO_printf(bio_err,"-keysig       set MS key signature type\n");
  BIO_printf(bio_err,"-password p   set import/export password source\n");
  BIO_printf(bio_err,"-passin p     input file pass phrase source\n");
  BIO_printf(bio_err,"-passout p    output file pass phrase source\n");
  BIO_printf(bio_err,"-engine e     use engine e, possibly a hardware device.\n");
  BIO_printf(bio_err,"-rand file%cfile%c...\n",0x3a,0x3a);
  BIO_printf(bio_err,"              load the file (or the files in the directory) into\n");
  BIO_printf(bio_err,"              the random number generator\n");
  BIO_printf(bio_err,"-CSP name     Microsoft CSP name\n");
  pcVar24 = "-LMK          Add local machine keyset attribute to private key\n";
LAB_08082819:
  bp = (BIO *)0x0;
  BIO_printf(bio_err,pcVar24);
  local_188 = (BIO *)0x0;
LAB_08082831:
  uVar19 = 1;
LAB_08082836:
  if ((local_172 != '\0') || (local_171 != false)) goto LAB_08082960;
  goto LAB_0808284c;
}

