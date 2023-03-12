
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void speed_main(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  size_t *psVar4;
  undefined *puVar5;
  int iVar6;
  uchar *data;
  uchar *out;
  int iVar7;
  RSA *pRVar8;
  EVP_MD *pEVar9;
  int iVar10;
  BIO_METHOD *type;
  EC_KEY *pEVar11;
  int iVar12;
  EC_KEY *key;
  void *__ptr;
  __pid_t _Var13;
  EC_GROUP *group;
  EC_POINT *pEVar14;
  uint uVar15;
  FILE *pFVar16;
  long lVar17;
  RSA_METHOD *meth;
  int *piVar18;
  uint uVar19;
  byte *pbVar20;
  byte *pbVar21;
  undefined4 uVar22;
  double *pdVar23;
  double *pdVar24;
  RSA **ppRVar25;
  DSA **ppDVar26;
  EC_KEY **ppEVar27;
  char **ppcVar28;
  size_t sVar29;
  byte *pbVar30;
  byte *pbVar31;
  double *pdVar32;
  char *pcVar33;
  size_t *psVar34;
  uint *puVar35;
  undefined *puVar36;
  undefined4 *puVar37;
  EVP_MD *pEVar38;
  DSA *dsa;
  undefined4 *puVar39;
  bool bVar40;
  double dVar41;
  double dVar42;
  char *local_2828;
  char *local_2820;
  char *local_281c;
  char *local_2818;
  char *local_2814;
  char *local_2810;
  EVP_MD *local_2804;
  char *local_27fc;
  char *local_27f8;
  char *local_27f4;
  char *local_27ec;
  uint local_27e8;
  DSA *local_27e4;
  DSA *local_27e0 [3];
  int local_27d4 [2];
  RSA *local_27cc;
  RSA *local_27c8 [4];
  int local_27b8 [4];
  undefined4 local_27a8;
  undefined4 local_27a4;
  undefined4 local_27a0;
  undefined4 local_279c;
  undefined4 local_2798;
  undefined4 local_2794;
  undefined4 local_2790;
  EC_KEY *local_278c;
  EC_KEY *local_2788 [16];
  EC_KEY *local_2748 [16];
  EC_KEY *local_2708 [16];
  int local_26c8 [16];
  int local_2688 [16];
  int local_2648;
  EVP_MD *local_2644;
  int local_2640;
  int local_263c;
  int local_2638;
  int local_2634;
  int local_2630;
  int local_262c;
  int local_2628;
  int local_2624;
  int local_2620;
  int local_261c;
  int local_2618;
  int local_2610;
  int local_260c;
  int local_2608;
  int local_2604;
  int local_2600;
  int local_25fc;
  int local_25f8;
  int local_25f4;
  int local_25f0;
  int local_25ec;
  int local_25e8;
  int local_25e4;
  int local_25e0;
  int local_25dc;
  int local_25d8;
  int local_25d4;
  SEED_KEY_SCHEDULE SStack_25d0;
  DES_key_schedule DStack_2550;
  DES_key_schedule DStack_24d0;
  DES_key_schedule DStack_2450;
  CAST_KEY CStack_23d0;
  IDEA_KEY_SCHEDULE IStack_234c;
  AES_KEY AStack_2274;
  AES_KEY AStack_2180;
  AES_KEY AStack_208c;
  RC2_KEY RStack_1f98;
  CAMELLIA_KEY CStack_1e98;
  CAMELLIA_KEY CStack_1d80;
  CAMELLIA_KEY CStack_1c68;
  undefined auStack_1b50 [600];
  BF_KEY local_18f8;
  undefined4 local_8b0;
  undefined4 local_8ac;
  uchar auStack_8a8 [16];
  uchar auStack_898 [16];
  uchar auStack_888 [16];
  uchar auStack_878 [16];
  uchar auStack_868 [20];
  uchar auStack_854 [20];
  uchar auStack_840 [32];
  undefined4 local_820;
  undefined4 local_81c;
  undefined4 local_818;
  undefined4 local_814;
  undefined4 local_810;
  undefined4 local_80c;
  undefined4 local_808;
  undefined4 local_804;
  uchar auStack_800 [64];
  uchar auStack_7c0 [64];
  uchar auStack_780 [64];
  uchar auStack_740 [256];
  byte local_640 [256];
  undefined local_540 [256];
  undefined auStack_440 [3];
  byte bStack_43d;
  byte local_43c [1024];
  uint local_3c;
  
  local_3c = __stack_chk_guard;
  usertime = -1;
  signal(0xd,(__sighandler_t)0x1);
  memset(PTR_results_0002cf48,0,0x4b0);
  local_27e0[0] = (DSA *)0x0;
  local_27e0[1] = (DSA *)0x0;
  local_27e0[2] = (DSA *)0x0;
  memset(local_2788,0,0x40);
  memset(local_2748,0,0x40);
  memset(local_2708,0,0x40);
  if (bio_err == (BIO *)0x0) {
    type = BIO_s_file();
    bio_err = BIO_new(type);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar6 = load_config(bio_err,0);
  if (iVar6 != 0) {
    iVar6 = 0;
    local_27c8[0] = (RSA *)0x0;
    local_27c8[1] = (RSA *)0x0;
    local_27c8[2] = (RSA *)0x0;
    local_27c8[3] = (RSA *)0x0;
    data = (uchar *)CRYPTO_malloc(0x2001,"speed.c",0x2ab);
    if (data != (uchar *)0x0) {
      out = (uchar *)CRYPTO_malloc(0x2001,"speed.c",0x2af);
      if (out == (uchar *)0x0) {
        uVar22 = 1;
        BIO_printf(bio_err,"out of memory\n");
        ERR_print_errors(bio_err);
        CRYPTO_free(data);
        goto LAB_0002cd3e;
      }
      memset(auStack_1b50,0,600);
      local_820 = 0;
      local_81c = 0;
      local_818 = 0;
      local_814 = 0;
      local_8b0 = 0;
      local_810 = 0;
      local_8ac = 0;
      local_80c = 0;
      local_808 = 0;
      local_804 = 0;
      memset(&local_2648,0,0x78);
      local_27b8[0] = 0;
      ppcVar28 = (char **)(param_2 + 4);
      local_27b8[1] = 0;
      local_27b8[2] = 0;
      local_27b8[3] = 0;
      local_27d4[0] = 0;
      local_27d4[1] = 0;
      local_27cc = (RSA *)0x0;
      memset(local_26c8,0,0x40);
      memset(local_2688,0,0x40);
      local_2804 = (EVP_MD *)(param_1 + -1);
      _Var13 = usertime;
      local_27fc = (char *)local_2804;
      local_27f4 = (char *)local_2804;
      if (local_2804 != (EVP_MD *)0x0) {
        pEVar38 = (EVP_MD *)0x0;
        local_2820 = (char *)0x0;
        local_27fc = (char *)0x0;
        local_27f4 = (char *)0x0;
LAB_0002cec2:
        pcVar33 = *ppcVar28;
        if ((int)local_2804 < 1) {
LAB_0002f188:
          iVar7 = strcmp(pcVar33,"mdc2");
          if (iVar7 == 0) {
            local_2644 = (EVP_MD *)0x1;
          }
          else {
            cVar1 = *pcVar33;
            if ((cVar1 == 'm') && (pcVar33[1] == 'd')) {
              if (pcVar33[2] == '4') {
                if (pcVar33[3] != '\0') goto LAB_0002f1cc;
                local_2640 = 1;
              }
              else {
                if ((pcVar33[2] != '5') || (pcVar33[3] != '\0')) goto LAB_0002f1cc;
                local_263c = 1;
              }
            }
            else {
LAB_0002f1cc:
              iVar7 = strcmp(pcVar33,"hmac");
              if (iVar7 == 0) {
                local_2638 = 1;
              }
              else {
                iVar7 = strcmp(pcVar33,"sha1");
                if (iVar7 == 0) {
                  local_2634 = 1;
                }
                else if ((((cVar1 == 's') && (pcVar33[1] == 'h')) && (pcVar33[2] == 'a')) &&
                        (pcVar33[3] == '\0')) {
                  local_2634 = 1;
                  local_25ec = 1;
                  local_25e8 = 1;
                }
                else {
                  iVar7 = strcmp(pcVar33,"sha256");
                  if (iVar7 == 0) {
                    local_25ec = 1;
                  }
                  else {
                    iVar7 = strcmp(pcVar33,"sha512");
                    if (iVar7 == 0) {
                      local_25e8 = 1;
                    }
                    else {
                      iVar7 = strcmp(pcVar33,"whirlpool");
                      if (iVar7 == 0) {
                        local_25e4 = 1;
                      }
                      else {
                        iVar7 = strcmp(pcVar33,"ripemd");
                        if (((iVar7 == 0) || (iVar7 = strcmp(pcVar33,"rmd160"), iVar7 == 0)) ||
                           (iVar7 = strcmp(pcVar33,"ripemd160"), iVar7 == 0)) {
                          local_2630 = 1;
                        }
                        else if (((cVar1 == 'r') && (pcVar33[1] == 'c')) &&
                                ((pcVar33[2] == '4' && (pcVar33[3] == '\0')))) {
                          local_262c = 1;
                        }
                        else {
                          iVar7 = strcmp(pcVar33,"des-cbc");
                          if (iVar7 == 0) {
                            local_2628 = 1;
                          }
                          else {
                            iVar7 = strcmp(pcVar33,"des-ede3");
                            if (iVar7 == 0) {
                              local_2624 = 1;
                            }
                            else {
                              iVar7 = strcmp(pcVar33,"aes-128-cbc");
                              if (iVar7 == 0) {
                                local_2608 = 1;
                              }
                              else {
                                iVar7 = strcmp(pcVar33,"aes-192-cbc");
                                if (iVar7 == 0) {
                                  local_2604 = 1;
                                }
                                else {
                                  iVar7 = strcmp(pcVar33,"aes-256-cbc");
                                  if (iVar7 == 0) {
                                    local_2600 = 1;
                                  }
                                  else {
                                    iVar7 = strcmp(pcVar33,"aes-128-ige");
                                    if (iVar7 == 0) {
                                      local_25e0 = 1;
                                    }
                                    else {
                                      iVar7 = strcmp(pcVar33,"aes-192-ige");
                                      if (iVar7 == 0) {
                                        local_25dc = 1;
                                      }
                                      else {
                                        iVar7 = strcmp(pcVar33,"aes-256-ige");
                                        if (iVar7 == 0) {
                                          local_25d8 = 1;
                                        }
                                        else {
                                          iVar7 = strcmp(pcVar33,"camellia-128-cbc");
                                          if (iVar7 == 0) {
                                            local_25fc = 1;
                                          }
                                          else {
                                            iVar7 = strcmp(pcVar33,"camellia-192-cbc");
                                            if (iVar7 == 0) {
                                              local_25f8 = 1;
                                            }
                                            else {
                                              iVar7 = strcmp(pcVar33,"camellia-256-cbc");
                                              if (iVar7 == 0) {
                                                local_25f4 = 1;
                                              }
                                              else {
                                                iVar7 = strcmp(pcVar33,"openssl");
                                                if (iVar7 == 0) {
                                                  meth = RSA_PKCS1_SSLeay();
                                                  iVar6 = iVar6 + -1;
                                                  RSA_set_default_method(meth);
                                                }
                                                else {
                                                  iVar7 = strcmp(pcVar33,"dsa512");
                                                  if (iVar7 == 0) {
                                                    local_27d4[0] = 2;
                                                  }
                                                  else {
                                                    iVar7 = strcmp(pcVar33,"dsa1024");
                                                    if (iVar7 == 0) {
                                                      local_27d4[1] = 2;
                                                    }
                                                    else {
                                                      iVar7 = strcmp(pcVar33,"dsa2048");
                                                      if (iVar7 == 0) {
                                                        local_27cc = (RSA *)0x2;
                                                      }
                                                      else {
                                                        iVar7 = strcmp(pcVar33,"rsa512");
                                                        if (iVar7 == 0) {
                                                          local_27b8[0] = 2;
                                                        }
                                                        else {
                                                          iVar7 = strcmp(pcVar33,"rsa1024");
                                                          if (iVar7 == 0) {
                                                            local_27b8[1] = 2;
                                                          }
                                                          else {
                                                            iVar7 = strcmp(pcVar33,"rsa2048");
                                                            if (iVar7 == 0) {
                                                              local_27b8[2] = 2;
                                                            }
                                                            else {
                                                              iVar7 = strcmp(pcVar33,"rsa4096");
                                                              if (iVar7 == 0) {
                                                                local_27b8[3] = 2;
                                                              }
                                                              else {
                                                                iVar7 = strcmp(pcVar33,"rc2-cbc");
                                                                if ((iVar7 == 0) ||
                                                                   ((((cVar1 == 'r' &&
                                                                      (pcVar33[1] == 'c')) &&
                                                                     (pcVar33[2] == '2')) &&
                                                                    (pcVar33[3] == '\0')))) {
                                                                  local_2618 = 1;
                                                                }
                                                                else {
                                                                  iVar7 = strcmp(pcVar33,"idea-cbc")
                                                                  ;
                                                                  if ((iVar7 == 0) ||
                                                                     (iVar7 = strcmp(pcVar33,"idea")
                                                                     , iVar7 == 0)) {
                                                                    local_2620 = 1;
                                                                  }
                                                                  else {
                                                                    iVar7 = strcmp(pcVar33,
                                                  "seed-cbc");
                                                  if ((iVar7 == 0) ||
                                                     (iVar7 = strcmp(pcVar33,"seed"), iVar7 == 0)) {
                                                    local_261c = 1;
                                                  }
                                                  else {
                                                    iVar7 = strcmp(pcVar33,"bf-cbc");
                                                    if (((iVar7 == 0) ||
                                                        (iVar7 = strcmp(pcVar33,"blowfish"),
                                                        iVar7 == 0)) ||
                                                       ((cVar1 == 'b' &&
                                                        ((pcVar33[1] == 'f' && (pcVar33[2] == '\0'))
                                                        )))) {
                                                      local_2610 = 1;
                                                    }
                                                    else {
                                                      iVar7 = strcmp(pcVar33,"cast-cbc");
                                                      if (((iVar7 == 0) ||
                                                          (iVar7 = strcmp(pcVar33,"cast"),
                                                          iVar7 == 0)) ||
                                                         (iVar7 = strcmp(pcVar33,"cast5"),
                                                         iVar7 == 0)) {
                                                        local_260c = 1;
                                                      }
                                                      else if (((cVar1 == 'd') &&
                                                               (pcVar33[1] == 'e')) &&
                                                              ((pcVar33[2] == 's' &&
                                                               (pcVar33[3] == '\0')))) {
                                                        local_2628 = 1;
                                                        local_2624 = 1;
                                                      }
                                                      else if ((((cVar1 == 'a') &&
                                                                (pcVar33[1] == 'e')) &&
                                                               (pcVar33[2] == 's')) &&
                                                              (pcVar33[3] == '\0')) {
                                                        local_2608 = 1;
                                                        local_2604 = 1;
                                                        local_2600 = 1;
                                                      }
                                                      else {
                                                        iVar7 = strcmp(pcVar33,"ghash");
                                                        if (iVar7 == 0) {
                                                          local_25d4 = 1;
                                                        }
                                                        else {
                                                          iVar7 = strcmp(pcVar33,"camellia");
                                                          if (iVar7 == 0) {
                                                            local_25fc = 1;
                                                            local_25f8 = 1;
                                                            local_25f4 = 1;
                                                          }
                                                          else if ((((cVar1 == 'r') &&
                                                                    (pcVar33[1] == 's')) &&
                                                                   (pcVar33[2] == 'a')) &&
                                                                  (pcVar33[3] == '\0')) {
                                                            local_27b8[0] = 1;
                                                            local_27b8[1] = 1;
                                                            local_27b8[2] = 1;
                                                            local_27b8[3] = 1;
                                                          }
                                                          else if (((cVar1 == 'd') &&
                                                                   (pcVar33[1] == 's')) &&
                                                                  ((pcVar33[2] == 'a' &&
                                                                   (pcVar33[3] == '\0')))) {
                                                            local_27d4[0] = 1;
                                                            local_27d4[1] = 1;
                                                            local_27cc = (RSA *)0x1;
                                                          }
                                                          else {
                                                            iVar7 = strcmp(pcVar33,"ecdsap160");
                                                            if (iVar7 == 0) {
                                                              local_26c8[0] = 2;
                                                            }
                                                            else {
                                                              iVar7 = strcmp(pcVar33,"ecdsap192");
                                                              if (iVar7 == 0) {
                                                                local_26c8[1] = 2;
                                                              }
                                                              else {
                                                                iVar7 = strcmp(pcVar33,"ecdsap224");
                                                                if (iVar7 == 0) {
                                                                  local_26c8[2] = 2;
                                                                }
                                                                else {
                                                                  iVar7 = strcmp(pcVar33,"ecdsap256"
                                                                                );
                                                                  if (iVar7 == 0) {
                                                                    local_26c8[3] = 2;
                                                                  }
                                                                  else {
                                                                    iVar7 = strcmp(pcVar33,
                                                  "ecdsap384");
                                                  if (iVar7 == 0) {
                                                    local_26c8[4] = 2;
                                                  }
                                                  else {
                                                    iVar7 = strcmp(pcVar33,"ecdsap521");
                                                    if (iVar7 == 0) {
                                                      local_26c8[5] = 2;
                                                    }
                                                    else {
                                                      iVar7 = strcmp(pcVar33,"ecdsak163");
                                                      if (iVar7 == 0) {
                                                        local_26c8[6] = 2;
                                                      }
                                                      else {
                                                        iVar7 = strcmp(pcVar33,"ecdsak233");
                                                        if (iVar7 == 0) {
                                                          local_26c8[7] = 2;
                                                        }
                                                        else {
                                                          iVar7 = strcmp(pcVar33,"ecdsak283");
                                                          if (iVar7 == 0) {
                                                            local_26c8[8] = 2;
                                                          }
                                                          else {
                                                            iVar7 = strcmp(pcVar33,"ecdsak409");
                                                            if (iVar7 == 0) {
                                                              local_26c8[9] = 2;
                                                            }
                                                            else {
                                                              iVar7 = strcmp(pcVar33,"ecdsak571");
                                                              if (iVar7 == 0) {
                                                                local_26c8[10] = 2;
                                                              }
                                                              else {
                                                                iVar7 = strcmp(pcVar33,"ecdsab163");
                                                                if (iVar7 == 0) {
                                                                  local_26c8[11] = 2;
                                                                }
                                                                else {
                                                                  iVar7 = strcmp(pcVar33,"ecdsab233"
                                                                                );
                                                                  if (iVar7 == 0) {
                                                                    local_26c8[12] = 2;
                                                                  }
                                                                  else {
                                                                    iVar7 = strcmp(pcVar33,
                                                  "ecdsab283");
                                                  if (iVar7 == 0) {
                                                    local_26c8[13] = 2;
                                                  }
                                                  else {
                                                    iVar7 = strcmp(pcVar33,"ecdsab409");
                                                    if (iVar7 == 0) {
                                                      local_26c8[14] = 2;
                                                    }
                                                    else {
                                                      iVar7 = strcmp(pcVar33,"ecdsab571");
                                                      if (iVar7 == 0) {
                                                        local_26c8[15] = 2;
                                                      }
                                                      else {
                                                        iVar7 = strcmp(pcVar33,"ecdsa");
                                                        if (iVar7 == 0) {
                                                          local_26c8[0] = 1;
                                                          local_26c8[1] = 1;
                                                          local_26c8[2] = 1;
                                                          local_26c8[3] = 1;
                                                          local_26c8[4] = 1;
                                                          local_26c8[5] = 1;
                                                          local_26c8[6] = 1;
                                                          local_26c8[7] = 1;
                                                          local_26c8[8] = 1;
                                                          local_26c8[9] = 1;
                                                          local_26c8[10] = 1;
                                                          local_26c8[11] = 1;
                                                          local_26c8[12] = 1;
                                                          local_26c8[13] = 1;
                                                          local_26c8[14] = 1;
                                                          local_26c8[15] = 1;
                                                        }
                                                        else {
                                                          iVar7 = strcmp(pcVar33,"ecdhp160");
                                                          if (iVar7 == 0) {
                                                            local_2688[0] = 2;
                                                          }
                                                          else {
                                                            iVar7 = strcmp(pcVar33,"ecdhp192");
                                                            if (iVar7 == 0) {
                                                              local_2688[1] = 2;
                                                            }
                                                            else {
                                                              iVar7 = strcmp(pcVar33,"ecdhp224");
                                                              if (iVar7 == 0) {
                                                                local_2688[2] = 2;
                                                              }
                                                              else {
                                                                iVar7 = strcmp(pcVar33,"ecdhp256");
                                                                if (iVar7 == 0) {
                                                                  local_2688[3] = 2;
                                                                }
                                                                else {
                                                                  iVar7 = strcmp(pcVar33,"ecdhp384")
                                                                  ;
                                                                  if (iVar7 == 0) {
                                                                    local_2688[4] = 2;
                                                                  }
                                                                  else {
                                                                    iVar7 = strcmp(pcVar33,
                                                  "ecdhp521");
                                                  if (iVar7 == 0) {
                                                    local_2688[5] = 2;
                                                  }
                                                  else {
                                                    iVar7 = strcmp(pcVar33,"ecdhk163");
                                                    if (iVar7 == 0) {
                                                      local_2688[6] = 2;
                                                    }
                                                    else {
                                                      iVar7 = strcmp(pcVar33,"ecdhk233");
                                                      if (iVar7 == 0) {
                                                        local_2688[7] = 2;
                                                      }
                                                      else {
                                                        iVar7 = strcmp(pcVar33,"ecdhk283");
                                                        if (iVar7 == 0) {
                                                          local_2688[8] = 2;
                                                        }
                                                        else {
                                                          iVar7 = strcmp(pcVar33,"ecdhk409");
                                                          if (iVar7 == 0) {
                                                            local_2688[9] = 2;
                                                          }
                                                          else {
                                                            iVar7 = strcmp(pcVar33,"ecdhk571");
                                                            if (iVar7 == 0) {
                                                              local_2688[10] = 2;
                                                            }
                                                            else {
                                                              iVar7 = strcmp(pcVar33,"ecdhb163");
                                                              if (iVar7 == 0) {
                                                                local_2688[11] = 2;
                                                              }
                                                              else {
                                                                iVar7 = strcmp(pcVar33,"ecdhb233");
                                                                if (iVar7 == 0) {
                                                                  local_2688[12] = 2;
                                                                }
                                                                else {
                                                                  iVar7 = strcmp(pcVar33,"ecdhb283")
                                                                  ;
                                                                  if (iVar7 == 0) {
                                                                    local_2688[13] = 2;
                                                                  }
                                                                  else {
                                                                    iVar7 = strcmp(pcVar33,
                                                  "ecdhb409");
                                                  if (iVar7 == 0) {
                                                    local_2688[14] = 2;
                                                  }
                                                  else {
                                                    iVar7 = strcmp(pcVar33,"ecdhb571");
                                                    if (iVar7 == 0) {
                                                      local_2688[15] = 2;
                                                    }
                                                    else {
                                                      iVar7 = strcmp(pcVar33,"ecdh");
                                                      if (iVar7 != 0) {
                                                        uVar22 = 1;
                                                        BIO_printf(bio_err,
                                                  "Error: bad option or value\n");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"Available values:\n");
                                                  BIO_printf(bio_err,"mdc2     ");
                                                  BIO_printf(bio_err,"md4      ");
                                                  BIO_printf(bio_err,"md5      ");
                                                  BIO_printf(bio_err,"hmac     ");
                                                  BIO_printf(bio_err,"sha1     ");
                                                  BIO_printf(bio_err,"sha256   ");
                                                  BIO_printf(bio_err,"sha512   ");
                                                  BIO_printf(bio_err,"whirlpool");
                                                  BIO_printf(bio_err,"rmd160");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"idea-cbc ");
                                                  BIO_printf(bio_err,"seed-cbc ");
                                                  BIO_printf(bio_err,"rc2-cbc  ");
                                                  BIO_printf(bio_err,"bf-cbc");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"des-cbc  des-ede3 ");
                                                  BIO_printf(bio_err,
                                                  "aes-128-cbc aes-192-cbc aes-256-cbc ");
                                                  BIO_printf(bio_err,
                                                  "aes-128-ige aes-192-ige aes-256-ige ");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,
                                                  "camellia-128-cbc camellia-192-cbc camellia-256-cbc "
                                                  );
                                                  BIO_printf(bio_err,"rc4");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,
                                                  "rsa512   rsa1024  rsa2048  rsa4096\n");
                                                  BIO_printf(bio_err,"dsa512   dsa1024  dsa2048\n");
                                                  BIO_printf(bio_err,
                                                  "ecdsap160 ecdsap192 ecdsap224 ecdsap256 ecdsap384 ecdsap521\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "ecdsak163 ecdsak233 ecdsak283 ecdsak409 ecdsak571\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "ecdsab163 ecdsab233 ecdsab283 ecdsab409 ecdsab571\n"
                                                  );
                                                  BIO_printf(bio_err,"ecdsa\n");
                                                  BIO_printf(bio_err,
                                                  "ecdhp160  ecdhp192  ecdhp224 ecdhp256  ecdhp384  ecdhp521\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "ecdhk163  ecdhk233  ecdhk283  ecdhk409  ecdhk571\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "ecdhb163  ecdhb233  ecdhb283  ecdhb409  ecdhb571\n"
                                                  );
                                                  BIO_printf(bio_err,"ecdh\n");
                                                  BIO_printf(bio_err,"idea     ");
                                                  BIO_printf(bio_err,"seed     ");
                                                  BIO_printf(bio_err,"rc2      ");
                                                  BIO_printf(bio_err,"des      ");
                                                  BIO_printf(bio_err,"aes      ");
                                                  BIO_printf(bio_err,"camellia ");
                                                  BIO_printf(bio_err,"rsa      ");
                                                  BIO_printf(bio_err,"blowfish");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"\n");
                                                  BIO_printf(bio_err,"Available options:\n");
                                                  BIO_printf(bio_err,
                                                  "-engine e       use engine e, possibly a hardware device.\n"
                                                  );
                                                  BIO_printf(bio_err,"-evp e          use EVP e.\n")
                                                  ;
                                                  BIO_printf(bio_err,
                                                  "-decrypt        time decryption instead of encryption (only EVP).\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "-mr             produce machine readable output.\n"
                                                  );
                                                  BIO_printf(bio_err,
                                                  "-multi n        run n benchmarks in parallel.\n")
                                                  ;
                                                  goto LAB_0002f222;
                                                  }
                                                  local_2688[0] = 1;
                                                  local_2688[1] = 1;
                                                  local_2688[2] = 1;
                                                  local_2688[3] = 1;
                                                  local_2688[4] = 1;
                                                  local_2688[5] = 1;
                                                  local_2688[6] = 1;
                                                  local_2688[7] = 1;
                                                  local_2688[8] = 1;
                                                  local_2688[9] = 1;
                                                  local_2688[10] = 1;
                                                  local_2688[11] = 1;
                                                  local_2688[12] = 1;
                                                  local_2688[13] = 1;
                                                  local_2688[14] = 1;
                                                  local_2688[15] = 1;
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
        else {
          iVar7 = strcmp(pcVar33,"-elapsed");
          if (iVar7 == 0) {
            iVar6 = iVar6 + -1;
            usertime = iVar7;
            goto LAB_0002ceb6;
          }
          iVar7 = strcmp(pcVar33,"-evp");
          if (iVar7 == 0) {
            if (local_2804 == (EVP_MD *)0x1) {
              uVar22 = 1;
              BIO_printf(bio_err,"no EVP given\n");
              goto LAB_0002f222;
            }
            pEVar38 = (EVP_MD *)EVP_get_cipherbyname(ppcVar28[1]);
            if ((pEVar38 == (EVP_MD *)0x0) &&
               (local_27f4 = (char *)EVP_get_digestbyname(ppcVar28[1]),
               (EVP_MD *)local_27f4 == (EVP_MD *)0x0)) {
              uVar22 = 1;
              BIO_printf(bio_err,"%s is an unknown cipher or digest\n",ppcVar28[1]);
              goto LAB_0002f222;
            }
            local_2804 = (EVP_MD *)((int)&local_2804[-1].md_ctrl + 2);
            ppcVar28 = ppcVar28 + 2;
            local_25f0 = 1;
            _Var13 = usertime;
            goto joined_r0x0002cf1a;
          }
          iVar7 = strcmp(pcVar33,"-decrypt");
          if (iVar7 == 0) {
            iVar6 = iVar6 + -1;
            local_27fc = (char *)0x1;
          }
          else {
            iVar7 = strcmp(pcVar33,"-engine");
            if (iVar7 == 0) {
              local_2804 = (EVP_MD *)((int)&local_2804[-1].md_ctrl + 3);
              if (local_2804 == (EVP_MD *)0x0) {
                uVar22 = 1;
                BIO_printf(bio_err,"no engine given\n");
                goto LAB_0002f222;
              }
              iVar6 = iVar6 + -1;
              setup_engine(bio_err,ppcVar28[1],0);
              ppcVar28 = ppcVar28 + 1;
            }
            else {
              iVar7 = strcmp(pcVar33,"-multi");
              if (iVar7 != 0) {
                if ((((*pcVar33 != '-') || (pcVar33[1] != 'm')) || (pcVar33[2] != 'r')) ||
                   (pcVar33[3] != '\0')) goto LAB_0002f188;
                iVar6 = iVar6 + -1;
                mr = 1;
                goto LAB_0002ceb6;
              }
              local_2804 = (EVP_MD *)((int)&local_2804[-1].md_ctrl + 3);
              if (local_2804 == (EVP_MD *)0x0) {
                uVar22 = 1;
                BIO_printf(bio_err,"no multi count given\n");
                goto LAB_0002f222;
              }
              local_2820 = (char *)strtol(ppcVar28[1],(char **)0x0,10);
              if ((int)local_2820 < 1) {
                uVar22 = 1;
                BIO_printf(bio_err,"bad multi count\n");
                goto LAB_0002f222;
              }
              iVar6 = iVar6 + -1;
              ppcVar28 = ppcVar28 + 1;
            }
          }
        }
LAB_0002ceb6:
        local_2804 = (EVP_MD *)((int)&local_2804[-1].md_ctrl + 3);
        ppcVar28 = ppcVar28 + 1;
        _Var13 = usertime;
joined_r0x0002cf1a:
        iVar6 = iVar6 + 1;
        usertime = _Var13;
        if (local_2804 == (EVP_MD *)0x0) goto LAB_0002cf1c;
        goto LAB_0002cec2;
      }
      goto LAB_0002cf40;
    }
    BIO_printf(bio_err,"out of memory\n");
  }
  uVar22 = 1;
  ERR_print_errors(bio_err);
LAB_0002cd3e:
  ppRVar25 = &local_27cc;
  do {
    ppRVar25 = ppRVar25 + 1;
    if (*ppRVar25 != (RSA *)0x0) {
      RSA_free(*ppRVar25);
    }
  } while (ppRVar25 != local_27c8 + 3);
  ppDVar26 = &local_27e4;
  do {
    ppDVar26 = ppDVar26 + 1;
    if (*ppDVar26 != (DSA *)0x0) {
      DSA_free(*ppDVar26);
    }
  } while (ppDVar26 != local_27e0 + 2);
  ppEVar27 = &local_278c;
  do {
    ppEVar27 = ppEVar27 + 1;
    if (*ppEVar27 != (EC_KEY *)0x0) {
      EC_KEY_free(*ppEVar27);
    }
  } while (ppEVar27 != local_2788 + 0xf);
  iVar6 = 0;
  do {
    if (*(EC_KEY **)((int)local_2748 + iVar6) != (EC_KEY *)0x0) {
      EC_KEY_free(*(EC_KEY **)((int)local_2748 + iVar6));
    }
    if (*(EC_KEY **)((int)local_2708 + iVar6) != (EC_KEY *)0x0) {
      EC_KEY_free(*(EC_KEY **)((int)local_2708 + iVar6));
    }
    iVar6 = iVar6 + 4;
  } while (iVar6 != 0x40);
  if (local_3c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar22);
LAB_0002cf1c:
  if (local_2820 == (char *)0x0) {
LAB_0002cf3c:
    local_2804 = pEVar38;
    if (iVar6 == 0) {
LAB_0002cf40:
      iVar7 = 0;
      for (iVar6 = 1; (iVar7 == 0x16 || ((&local_2648)[iVar7] = 1, iVar6 != 0x1e));
          iVar6 = iVar6 + 1) {
        iVar7 = iVar7 + 1;
      }
      local_27b8[0] = 1;
      local_27b8[1] = 1;
      local_27b8[2] = 1;
      local_27b8[3] = 1;
      local_27d4[0] = 1;
      local_27d4[1] = 1;
      local_27cc = (RSA *)0x1;
      local_26c8[0] = 1;
      local_26c8[1] = 1;
      local_26c8[2] = 1;
      local_26c8[3] = 1;
      local_26c8[4] = 1;
      local_26c8[5] = 1;
      local_26c8[6] = 1;
      local_26c8[7] = 1;
      local_26c8[8] = 1;
      local_26c8[9] = 1;
      local_26c8[10] = 1;
      local_26c8[11] = 1;
      local_26c8[12] = 1;
      local_26c8[13] = 1;
      local_26c8[14] = 1;
      local_26c8[15] = 1;
      local_2688[0] = 1;
      local_2688[1] = 1;
      local_2688[2] = 1;
      local_2688[3] = 1;
      local_2688[4] = 1;
      local_2688[5] = 1;
      local_2688[6] = 1;
      local_2688[7] = 1;
      local_2688[8] = 1;
      local_2688[9] = 1;
      local_2688[10] = 1;
      local_2688[11] = 1;
      local_2688[12] = 1;
      local_2688[13] = 1;
      local_2688[14] = 1;
      local_2688[15] = 1;
    }
    local_27f8 = (char *)&local_18f8;
    piVar18 = local_2688 + 0xf;
    local_27ec = (char *)0x0;
    do {
      piVar18 = piVar18 + 1;
      if (*piVar18 != 0) {
        local_27ec = local_27ec + 1;
      }
    } while (piVar18 != &local_25d4);
    if ((_Var13 == 0) && (mr == 0)) {
      BIO_printf(bio_err,"You have chosen to measure elapsed time instead of user CPU time.\n");
    }
    iVar6 = 0;
    iVar7 = 0;
    do {
      pRVar8 = d2i_RSAPrivateKey((RSA **)0x0,(uchar **)local_27f8,
                                 *(long *)(rsa_data_length_20471 + iVar6));
      *(RSA **)((int)local_27c8 + iVar6) = pRVar8;
      if (pRVar8 == (RSA *)0x0) {
        uVar22 = 1;
        BIO_printf(bio_err,"internal error loading RSA key number %d\n",iVar7);
        goto LAB_0002f222;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar7 != 4);
    local_27e0[0] = (DSA *)get_dsa512();
    local_27e0[1] = (DSA *)get_dsa1024();
    local_27e0[2] = (DSA *)get_dsa2048();
    DES_set_key_unchecked((const_DES_cblock *)PTR_key_20453_0002d2d8,&DStack_2550);
    DES_set_key_unchecked((const_DES_cblock *)PTR_key2_20454_0002d2dc,&DStack_24d0);
    DES_set_key_unchecked((const_DES_cblock *)PTR_key3_20455_0002d2e0,&DStack_2450);
    AES_set_encrypt_key(PTR_key16_20446_0002d2e4,0x80,&AStack_2274);
    AES_set_encrypt_key(PTR_key24_20447_0002d2e8,0xc0,&AStack_2180);
    AES_set_encrypt_key(PTR_key32_20448_0002d2ec,0x100,&AStack_208c);
    Camellia_set_key(PTR_key16_20446_0002d2e4,0x80,&CStack_1e98);
    Camellia_set_key(PTR_ckey24_20449_0002d2f0,0xc0,&CStack_1d80);
    Camellia_set_key(PTR_ckey32_20450_0002d2f4,0x100,&CStack_1c68);
    idea_set_encrypt_key(PTR_key16_20446_0002d2e4,&IStack_234c);
    SEED_set_key(PTR_key16_20446_0002d2e4,&SStack_25d0);
    RC4_set_key((RC4_KEY *)auStack_440,0x10,PTR_key16_20446_0002d2e4);
    RC2_set_key(&RStack_1f98,0x10,PTR_key16_20446_0002d2e4,0x80);
    BF_set_key((BF_KEY *)local_27f8,0x10,PTR_key16_20446_0002d2e4);
    CAST_set_key(&CStack_23d0,0x10,PTR_key16_20446_0002d2e4);
    local_27a8 = 0;
    local_27a4 = 0;
    local_27a0 = 0;
    local_279c = 0;
    local_2798 = 0;
    local_2794 = 0;
    local_2790 = 0;
    local_278c = (EC_KEY *)0x0;
    signal(0xe,sig_done + 1);
    pdVar32 = DAT_0002f3b8;
    if (local_2644 == (EVP_MD *)0x0) {
      pdVar23 = (double *)&run;
      pEVar38 = local_2644;
      dVar41 = DAT_0002d2d0;
    }
    else {
      local_2828 = (char *)DAT_0002f3b4;
      local_2810 = "%d %s\'s in %.2fs\n";
      local_2820 = (char *)DAT_0002f3b8;
      pdVar23 = DAT_0002f3b8 + -6;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_281c;
        if (*(int *)(pdVar32 + 0x91) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._4_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            pEVar9 = (EVP_MD *)EVP_mdc2();
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            EVP_Digest(data,sVar29,auStack_8a8,(uint *)0x0,pEVar9,(ENGINE *)0x0);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002f3bc;
        pcVar33 = local_2810;
        if (*(int *)(pdVar32 + 0x91) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._4_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_2640 != 0) {
      local_2828 = (char *)DAT_0002d2f8;
      local_2820 = (char *)DAT_0002d2fc;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._8_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            pEVar9 = EVP_md4();
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            EVP_Digest(data,sVar29,auStack_898,(uint *)0x0,pEVar9,(ENGINE *)0x0);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002d300;
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._8_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_263c != 0) {
      local_2828 = (char *)DAT_0002d2f8;
      local_2820 = (char *)DAT_0002d304;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._12_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            pEVar9 = EVP_get_digestbyname("md5");
            EVP_Digest(data,sVar29,auStack_888,(uint *)0x0,pEVar9,(ENGINE *)0x0);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002d65c;
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._12_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_2638 != 0) {
      local_2828 = (char *)DAT_00030950;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2820 = (char *)DAT_00030958;
      HMAC_CTX_init((HMAC_CTX *)local_540);
      pEVar38 = EVP_md5();
      HMAC_Init_ex((HMAC_CTX *)local_540,"This is a key...",0x10,pEVar38,(ENGINE *)0x0);
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._16_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            HMAC_Init_ex((HMAC_CTX *)local_540,(void *)0x0,0,(EVP_MD *)0x0,(ENGINE *)0x0);
            HMAC_Update((HMAC_CTX *)local_540,data,sVar29);
            HMAC_Final((HMAC_CTX *)local_540,auStack_878,(uint *)0x0);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._16_4_,dVar41);
        bVar40 = (size_t *)local_2828 != DAT_0003095c;
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while (bVar40);
      HMAC_CTX_cleanup((HMAC_CTX *)local_540);
    }
    if (local_2634 != 0) {
      local_2828 = (char *)DAT_0002d660;
      local_2820 = (char *)DAT_0002d664;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._20_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            pEVar9 = EVP_sha1();
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            EVP_Digest(data,sVar29,auStack_868,(uint *)0x0,pEVar9,(ENGINE *)0x0);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002d65c;
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._20_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_25ec != 0) {
      local_2820 = "Doing %s for %ds on %d size blocks: ";
      local_2828 = (char *)DAT_0002d668;
      local_2818 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d660;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        pcVar33 = local_2820;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._92_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            SHA256(data,sVar29,auStack_840);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002d65c;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._92_4_,dVar41);
        *(double *)local_2828 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2828 = (char *)((int)local_2828 + 8);
      } while (psVar34 != psVar4);
    }
    if (local_25e8 != 0) {
      local_2820 = "Doing %s for %ds on %d size blocks: ";
      local_2828 = (char *)DAT_0002d66c;
      local_2818 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d660;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        pcVar33 = local_2820;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._96_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            SHA512(data,sVar29,auStack_7c0);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002d9b8;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._96_4_,dVar41);
        *(double *)local_2828 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2828 = (char *)((int)local_2828 + 8);
      } while (psVar34 != psVar4);
    }
    if (local_25e4 != 0) {
      local_2820 = "Doing %s for %ds on %d size blocks: ";
      local_2828 = (char *)DAT_0002d9bc;
      local_2818 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d9c0;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        pcVar33 = local_2820;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._100_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            WHIRLPOOL(data,sVar29,auStack_780);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002d9b8;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._100_4_,dVar41);
        *(double *)local_2828 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2828 = (char *)((int)local_2828 + 8);
      } while (psVar34 != psVar4);
    }
    if (local_2630 != 0) {
      local_2828 = (char *)DAT_0002d9c0;
      local_2820 = (char *)DAT_0002d9c4;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._24_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            pEVar9 = EVP_ripemd160();
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            EVP_Digest(data,sVar29,auStack_854,(uint *)0x0,pEVar9,(ENGINE *)0x0);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002d9b8;
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._24_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_262c != 0) {
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2828 = (char *)DAT_0002d9c8;
      local_2810 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d9c0;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._28_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            RC4((RC4_KEY *)auStack_440,sVar29,data,data);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002dd24;
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._28_4_,dVar41);
        *(double *)local_2828 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2828 = (char *)((int)local_2828 + 8);
      } while (psVar34 != psVar4);
    }
    if (local_2628 != 0) {
      local_2828 = (char *)DAT_0002dd28;
      local_2820 = (char *)DAT_0002dd2c;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._32_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            DES_ncbc_encrypt(data,data,sVar29,&DStack_2550,(DES_cblock *)&local_8b0,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002dd24;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._32_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_2624 != 0) {
      local_2828 = (char *)DAT_0002dd28;
      local_2820 = (char *)DAT_0002dd30;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._36_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            DES_ede3_cbc_encrypt
                      (data,data,sVar29,&DStack_2550,&DStack_24d0,&DStack_2450,
                       (DES_cblock *)&local_8b0,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002dd24;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._36_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_2608 != 0) {
      local_2828 = (char *)DAT_0002dd28;
      local_2820 = (char *)DAT_0002dd34;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._64_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            AES_cbc_encrypt(data,data,sVar29,&AStack_2274,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e084;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._64_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_2604 != 0) {
      local_2828 = (char *)DAT_0002e088;
      local_2820 = (char *)DAT_0002e08c;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._68_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            AES_cbc_encrypt(data,data,sVar29,&AStack_2180,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e084;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._68_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_2600 != 0) {
      local_2828 = (char *)DAT_0002e088;
      local_2820 = (char *)DAT_0002e090;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._72_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            AES_cbc_encrypt(data,data,sVar29,&AStack_208c,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e084;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._72_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_25e0 != 0) {
      local_2828 = (char *)DAT_0002e088;
      local_2820 = (char *)DAT_0002e094;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._104_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            AES_ige_encrypt(data,out,sVar29,&AStack_2274,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e40c;
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._104_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_25dc != 0) {
      local_2828 = (char *)DAT_0002e410;
      local_2820 = (char *)DAT_0002e414;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._108_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            AES_ige_encrypt(data,out,sVar29,&AStack_2180,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e40c;
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._108_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_25d8 != 0) {
      local_2828 = (char *)DAT_0002e410;
      local_2820 = (char *)DAT_0002e418;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._112_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            AES_ige_encrypt(data,out,sVar29,&AStack_208c,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e40c;
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._112_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    local_2820 = (char *)DAT_00030954;
    if (local_25d4 != 0) {
      local_2828 = (char *)DAT_00030950;
      uVar22 = CRYPTO_gcm128_new(&AStack_2274,AES_encrypt);
      CRYPTO_gcm128_setiv(uVar22,"0123456789ab",0xc);
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._116_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            CRYPTO_gcm128_aad(uVar22,data,sVar29);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._116_4_,dVar41);
        bVar40 = (size_t *)local_2828 != DAT_0003095c;
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while (bVar40);
      CRYPTO_gcm128_release(uVar22);
    }
    if (local_25fc != 0) {
      local_2828 = (char *)DAT_0002e410;
      local_2820 = (char *)DAT_0002e41c;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._76_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            Camellia_cbc_encrypt(data,data,sVar29,&CStack_1e98,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e764;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._76_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_25f8 != 0) {
      local_2828 = (char *)DAT_0002e768;
      local_2820 = (char *)DAT_0002e76c;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._80_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            Camellia_cbc_encrypt(data,data,sVar29,&CStack_1d80,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e764;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._80_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_25f4 != 0) {
      local_2828 = (char *)DAT_0002e768;
      local_2820 = (char *)DAT_0002e770;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._84_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            Camellia_cbc_encrypt(data,data,sVar29,&CStack_1c68,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e764;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._84_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_2620 != 0) {
      local_2828 = (char *)DAT_0002e768;
      local_2820 = (char *)DAT_0002e774;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._40_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            idea_cbc_encrypt(data,data,sVar29,&IStack_234c,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002eac8;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._40_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_261c != 0) {
      local_2828 = (char *)DAT_0002eacc;
      local_2820 = (char *)DAT_0002ead0;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._44_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            SEED_cbc_encrypt(data,data,sVar29,&SStack_25d0,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002eac8;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._44_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_2618 != 0) {
      local_2828 = (char *)DAT_0002eacc;
      local_2820 = (char *)DAT_0002ead4;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_2818 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._48_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            RC2_cbc_encrypt(data,data,sVar29,&RStack_1f98,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002eac8;
        pcVar33 = local_2818;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._48_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    if (local_2610 != 0) {
      local_2820 = (char *)DAT_0002eacc;
      local_2814 = (char *)DAT_0002ead8;
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        local_2820 = (char *)((int)local_2820 + 4);
        sVar29 = *(size_t *)local_2820;
        pcVar33 = local_281c;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._56_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            BF_cbc_encrypt(data,data,sVar29,(BF_KEY *)local_27f8,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002ee1c;
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._56_4_,dVar41);
        *(double *)local_2814 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2814 = (char *)((int)local_2814 + 8);
      } while ((size_t *)local_2820 != psVar34);
    }
    if (local_260c != 0) {
      local_2828 = (char *)DAT_0002ee20;
      local_2820 = (char *)DAT_0002ee24;
      local_2814 = "Doing %s for %ds on %d size blocks: ";
      local_27f8 = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (char *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        pcVar33 = local_2814;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+DT:%s:%d:%d\n";
        }
        BIO_printf(bio_err,pcVar33,names._60_4_,3,sVar29);
        BIO_ctrl(bio_err,0xb,0,(void *)0x0);
        alarm(3);
        app_tminterval(0,usertime);
        *(undefined4 *)pdVar23 = 1;
        pEVar38 = *(EVP_MD **)pdVar23;
        if (pEVar38 != (EVP_MD *)0x0) {
          pEVar38 = (EVP_MD *)0x0;
          do {
            CAST_cbc_encrypt(data,data,sVar29,&CStack_23d0,(uchar *)&local_820,1);
            pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
            if (*(int *)pdVar23 == 0) break;
          } while (pEVar38 != (EVP_MD *)0x7fffffff);
        }
        dVar41 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002ee1c;
        pcVar33 = local_27f8;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._60_4_,dVar41);
        *(double *)local_2820 =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
        local_2820 = (char *)((int)local_2820 + 8);
      } while ((size_t *)local_2828 != psVar34);
    }
    puVar5 = PTR_results_0002ee28;
    if (local_25f0 != 0) {
      local_281c = "Doing %s for %ds on %d size blocks: ";
      local_2820 = (char *)0x0;
      local_2810 = "%d %s\'s in %.2fs\n";
      do {
        if (local_2804 == (EVP_MD *)0x0) {
          sVar29 = *(size_t *)(PTR_lengths_0003048c + (int)local_2820);
        }
        else {
          names._88_4_ = OBJ_nid2ln(local_2804->type);
          sVar29 = *(size_t *)(PTR_lengths_0002ee30 + (int)local_2820);
          pcVar33 = local_281c;
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+DT:%s:%d:%d\n";
          }
          BIO_printf(bio_err,pcVar33,names._88_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)local_540);
          if ((EVP_MD *)local_27fc == (EVP_MD *)0x0) {
            EVP_EncryptInit_ex((EVP_CIPHER_CTX *)local_540,(EVP_CIPHER *)local_2804,(ENGINE *)0x0,
                               PTR_key16_20446_00030484,(uchar *)&local_820);
            EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)local_540,0);
            app_tminterval(0,usertime);
            *(undefined4 *)pdVar23 = 1;
            pEVar38 = (EVP_MD *)local_27fc;
            if (*(int *)pdVar23 != 0) {
              do {
                pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
                EVP_EncryptUpdate((EVP_CIPHER_CTX *)local_540,data,(int *)&local_27e4,data,sVar29);
                if (*(int *)pdVar23 == 0) break;
              } while (pEVar38 != (EVP_MD *)0x7fffffff);
            }
            EVP_EncryptFinal_ex((EVP_CIPHER_CTX *)local_540,data,(int *)&local_27e4);
          }
          else {
            EVP_DecryptInit_ex((EVP_CIPHER_CTX *)local_540,(EVP_CIPHER *)local_2804,(ENGINE *)0x0,
                               PTR_key16_20446_0002ee2c,(uchar *)&local_820);
            EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)local_540,0);
            app_tminterval(0,usertime);
            *(undefined4 *)pdVar23 = 1;
            pEVar38 = *(EVP_MD **)pdVar23;
            if (pEVar38 != (EVP_MD *)0x0) {
              pEVar38 = (EVP_MD *)0x0;
              do {
                pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
                EVP_DecryptUpdate((EVP_CIPHER_CTX *)local_540,data,(int *)&local_27e4,data,sVar29);
                if (*(int *)pdVar23 == 0) break;
              } while (pEVar38 != (EVP_MD *)0x7fffffff);
            }
            EVP_DecryptFinal_ex((EVP_CIPHER_CTX *)local_540,data,(int *)&local_27e4);
          }
          dVar41 = (double)app_tminterval(1,usertime);
          EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)local_540);
        }
        if ((EVP_MD *)local_27f4 != (EVP_MD *)0x0) {
          names._88_4_ = OBJ_nid2ln(*(int *)local_27f4);
          pcVar33 = local_281c;
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+DT:%s:%d:%d\n";
          }
          BIO_printf(bio_err,pcVar33,names._88_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
          *(undefined4 *)pdVar23 = 1;
          pEVar38 = *(EVP_MD **)pdVar23;
          if (pEVar38 != (EVP_MD *)0x0) {
            pEVar38 = (EVP_MD *)0x0;
            do {
              pEVar38 = (EVP_MD *)((int)&pEVar38->type + 1);
              EVP_Digest(data,sVar29,auStack_800,(uint *)0x0,(EVP_MD *)local_27f4,(ENGINE *)0x0);
              if (*(int *)pdVar23 == 0) break;
            } while (pEVar38 != (EVP_MD *)0x7fffffff);
          }
          dVar41 = (double)app_tminterval(1,usertime);
        }
        pcVar33 = local_2810;
        if (*(int *)(pdVar23 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar38,names._88_4_,dVar41);
        iVar6 = (int)local_2820 * 2;
        local_2820 = (char *)((int)local_2820 + 4);
        *(double *)(puVar5 + iVar6 + 0x370) =
             ((double)(longlong)(int)pEVar38 / dVar41) * (double)(longlong)(int)sVar29;
      } while (local_2820 != (char *)0x14);
    }
    RAND_pseudo_bytes(data,0x24);
    iVar6 = 0;
    do {
      if (local_27b8[iVar6] != 0) {
        pRVar8 = local_27c8[iVar6];
        iVar7 = RSA_sign(0x72,data,0x24,out,&local_27e8,pRVar8);
        if (iVar7 == 0) {
          local_2828 = (char *)0x1;
          BIO_printf(bio_err,"RSA sign failure.  No RSA sign will be done.\n");
          ERR_print_errors(bio_err);
        }
        else {
          uVar22 = *(undefined4 *)(rsa_bits_20469 + iVar6 * 4);
          pcVar33 = "Doing %d bit %s %s\'s for %ds: ";
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+DTP:%d:%s:%s:%d\n";
          }
          BIO_printf(bio_err,pcVar33,uVar22,"private","rsa");
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          *(undefined4 *)pdVar23 = 1;
          local_2828 = *(char **)pdVar23;
          if (local_2828 != (char *)0x0) {
            local_2828 = (char *)0x0;
            while (iVar7 = RSA_sign(0x72,data,0x24,out,&local_27e8,local_27c8[iVar6]), iVar7 != 0) {
              local_2828 = (char *)((int)local_2828 + 1);
              if ((*(int *)pdVar23 == 0) || (local_2828 == (char *)0x7fffffff)) goto LAB_0002f486;
            }
            local_2828 = (char *)0x1;
            BIO_printf(bio_err,"RSA sign failure\n");
            ERR_print_errors(bio_err);
          }
LAB_0002f486:
          dVar41 = (double)app_tminterval(1,usertime);
          pcVar33 = "%ld %d bit private RSA\'s in %.2fs\n";
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+R1:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar33,local_2828,uVar22,dVar41);
          *(double *)(PTR_rsa_results_0002f768 + iVar6 * 0x10) =
               dVar41 / (double)(longlong)(int)local_2828;
        }
        iVar7 = RSA_verify(0x72,data,0x24,out,local_27e8,pRVar8);
        if (iVar7 < 1) {
          BIO_printf(bio_err,"RSA verify failure.  No RSA verify will be done.\n");
          ERR_print_errors(bio_err);
          local_27b8[iVar6] = 0;
        }
        else {
          uVar22 = *(undefined4 *)(rsa_bits_20469 + iVar6 * 4);
          pcVar33 = "Doing %d bit %s %s\'s for %ds: ";
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+DTP:%d:%s:%s:%d\n";
          }
          BIO_printf(bio_err,pcVar33,uVar22,"public","rsa");
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          *(undefined4 *)pdVar23 = 1;
          iVar7 = *(int *)pdVar23;
          if (iVar7 != 0) {
            iVar7 = 0;
            while (iVar10 = RSA_verify(0x72,data,0x24,out,local_27e8,pRVar8), 0 < iVar10) {
              iVar7 = iVar7 + 1;
              if ((*(int *)pdVar23 == 0) || (iVar7 == 0x7fffffff)) goto LAB_0002f05c;
            }
            iVar7 = 1;
            BIO_printf(bio_err,"RSA verify failure\n");
            ERR_print_errors(bio_err);
          }
LAB_0002f05c:
          dVar41 = (double)app_tminterval(1,usertime);
          pcVar33 = "%ld %d bit public RSA\'s in %.2fs\n";
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+R2:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar33,iVar7,uVar22,dVar41);
          *(double *)(PTR_rsa_results_0002f3b0 + iVar6 * 0x10 + 8) =
               dVar41 / (double)(longlong)iVar7;
        }
        if ((int)local_2828 < 2) {
          if (iVar6 + 1 == 4) break;
          iVar10 = iVar6 + 2;
          local_27b8[iVar6 + 1] = 0;
          iVar7 = iVar6;
          if (3 < iVar10) {
            iVar7 = iVar10;
          }
          iVar6 = iVar7;
          if (iVar10 == 3 || iVar6 + -1 < 0 != SBORROW4(iVar10,3)) {
            local_27b8[iVar10] = 0;
            iVar6 = iVar7 + 3;
            if (iVar7 == 0) {
              local_27b8[3] = 0;
              iVar6 = 4;
            }
          }
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 4);
    RAND_pseudo_bytes(data,0x14);
    iVar6 = RAND_status();
    if (iVar6 != 1) {
      RAND_seed(PTR_rnd_seed_0002f76c,0x40);
      *(undefined4 *)(pdVar23 + 0xd6) = 1;
    }
    local_27fc = "Doing %d bit %s %s\'s for %ds: ";
    iVar6 = 0;
    local_27f4 = "%ld %d bit DSA verify in %.2fs\n";
    do {
      if (local_27d4[iVar6] == 0) {
LAB_0002f548:
        iVar6 = iVar6 + 1;
      }
      else {
        dsa = local_27e0[iVar6];
        iVar7 = DSA_sign(0x74,data,0x14,out,(uint *)&local_27e4,dsa);
        if (iVar7 == 0) {
          local_2828 = (char *)0x1;
          BIO_printf(bio_err,"DSA sign failure.  No DSA sign will be done.\n");
          ERR_print_errors(bio_err);
        }
        else {
          uVar22 = *(undefined4 *)(dsa_bits_20474 + iVar6 * 4);
          pcVar33 = local_27fc;
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+DTP:%d:%s:%s:%d\n";
          }
          BIO_printf(bio_err,pcVar33,uVar22,"sign",&DAT_00123da0);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          *(undefined4 *)pdVar23 = 1;
          local_2828 = *(char **)pdVar23;
          if (local_2828 != (char *)0x0) {
            local_2828 = (char *)0x0;
            while (iVar7 = DSA_sign(0x74,data,0x14,out,(uint *)&local_27e4,local_27e0[iVar6]),
                  iVar7 != 0) {
              local_2828 = (char *)((int)local_2828 + 1);
              if ((*(int *)pdVar23 == 0) || (local_2828 == (char *)0x7fffffff)) goto LAB_0002f7be;
            }
            local_2828 = (char *)0x1;
            BIO_printf(bio_err,"DSA sign failure\n");
            ERR_print_errors(bio_err);
          }
LAB_0002f7be:
          dVar41 = (double)app_tminterval(1,usertime);
          pcVar33 = "%ld %d bit DSA signs in %.2fs\n";
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+R3:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar33,local_2828,uVar22,dVar41);
          *(double *)(PTR_dsa_results_0002fb2c + iVar6 * 0x10) =
               dVar41 / (double)(longlong)(int)local_2828;
        }
        iVar7 = DSA_verify(0x74,data,0x14,out,(int)local_27e4,dsa);
        if (iVar7 < 1) {
          BIO_printf(bio_err,"DSA verify failure.  No DSA verify will be done.\n");
          ERR_print_errors(bio_err);
          local_27d4[iVar6] = 0;
        }
        else {
          uVar22 = *(undefined4 *)(dsa_bits_20474 + iVar6 * 4);
          pcVar33 = local_27fc;
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+DTP:%d:%s:%s:%d\n";
          }
          BIO_printf(bio_err,pcVar33,uVar22,"verify",&DAT_00123da0);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(10);
          app_tminterval(0,usertime);
          *(undefined4 *)pdVar23 = 1;
          iVar7 = *(int *)pdVar23;
          if (iVar7 != 0) {
            iVar7 = 0;
            while (iVar10 = DSA_verify(0x74,data,0x14,out,(int)local_27e4,dsa), 0 < iVar10) {
              iVar7 = iVar7 + 1;
              if ((*(int *)pdVar23 == 0) || (iVar7 == 0x7fffffff)) goto LAB_0002f67a;
            }
            iVar7 = 1;
            BIO_printf(bio_err,"DSA verify failure\n");
            ERR_print_errors(bio_err);
          }
LAB_0002f67a:
          dVar41 = (double)app_tminterval(1,usertime);
          pcVar33 = local_27f4;
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = "+R4:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar33,iVar7,uVar22,dVar41);
          *(double *)(PTR_dsa_results_0002f770 + iVar6 * 0x10 + 8) =
               dVar41 / (double)(longlong)iVar7;
        }
        if (1 < (int)local_2828) goto LAB_0002f548;
        if (iVar6 + 1 == 3) {
          iVar6 = 4;
        }
        else {
          local_27d4[iVar6 + 1] = 0;
          if (iVar6 == 0) {
            local_27cc = (RSA *)0x0;
            iVar6 = 4;
          }
          else {
            iVar6 = iVar6 + 3;
          }
        }
      }
    } while (iVar6 < 3);
    if (*(int *)(pdVar23 + 0xd6) != 0) {
      RAND_cleanup();
    }
    iVar6 = RAND_status();
    if (iVar6 != 1) {
      RAND_seed(PTR_rnd_seed_0002fb30,0x40);
      *(undefined4 *)(pdVar23 + 0xd6) = 1;
    }
    local_27fc = "Doing %d bit %s %s\'s for %ds: ";
    iVar6 = 0;
    local_27f4 = "%ld %d bit ECDSA verify in %.2fs\n";
    do {
      iVar7 = iVar6;
      if (local_26c8[iVar6] != 0) {
        iVar10 = iVar6 * 4;
        pEVar11 = EC_KEY_new_by_curve_name(*(int *)(test_curves_20475 + iVar10));
        local_2788[iVar6] = pEVar11;
        if (pEVar11 == (EC_KEY *)0x0) {
          BIO_printf(bio_err,"ECDSA failure.\n");
          ERR_print_errors(bio_err);
        }
        else {
          EC_KEY_precompute_mult(pEVar11,(BN_CTX *)0x0);
          EC_KEY_generate_key(pEVar11);
          iVar12 = ECDSA_sign(0,data,0x14,auStack_740,(uint *)&local_27e4,pEVar11);
          if (iVar12 == 0) {
            local_2818 = (char *)0x1;
            BIO_printf(bio_err,"ECDSA sign failure.  No ECDSA sign will be done.\n");
            ERR_print_errors(bio_err);
          }
          else {
            uVar22 = *(undefined4 *)(test_curves_bits_20477 + iVar10);
            pcVar33 = local_27fc;
            if (*(int *)(pdVar23 + 0x97) != 0) {
              pcVar33 = "+DTP:%d:%s:%s:%d\n";
            }
            BIO_printf(bio_err,pcVar33,uVar22,"sign","ecdsa");
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
            app_tminterval(0,usertime);
            *(undefined4 *)pdVar23 = 1;
            local_2818 = *(char **)pdVar23;
            if (local_2818 != (char *)0x0) {
              local_2818 = (char *)0x0;
              while (iVar12 = ECDSA_sign(0,data,0x14,auStack_740,(uint *)&local_27e4,pEVar11),
                    iVar12 != 0) {
                local_2818 = (char *)((int)local_2818 + 1);
                if ((*(int *)pdVar23 == 0) || (local_2818 == (char *)0x7fffffff)) goto LAB_0002fad8;
              }
              local_2818 = (char *)0x1;
              BIO_printf(bio_err,"ECDSA sign failure\n");
              ERR_print_errors(bio_err);
            }
LAB_0002fad8:
            dVar41 = (double)app_tminterval(1,usertime);
            pcVar33 = "%ld %d bit ECDSA signs in %.2fs \n";
            if (*(int *)(pdVar23 + 0x97) != 0) {
              pcVar33 = "+R5:%ld:%d:%.2f\n";
            }
            BIO_printf(bio_err,pcVar33,local_2818,uVar22,dVar41);
            *(double *)(PTR_ecdsa_results_0002fb34 + iVar6 * 0x10) =
                 dVar41 / (double)(longlong)(int)local_2818;
          }
          iVar12 = ECDSA_verify(0,data,0x14,auStack_740,(int)local_27e4,pEVar11);
          if (iVar12 == 1) {
            uVar22 = *(undefined4 *)(test_curves_bits_20477 + iVar10);
            pcVar33 = local_27fc;
            if (*(int *)(pdVar23 + 0x97) != 0) {
              pcVar33 = "+DTP:%d:%s:%s:%d\n";
            }
            BIO_printf(bio_err,pcVar33,uVar22,"verify","ecdsa");
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
            app_tminterval(0,usertime);
            *(undefined4 *)pdVar23 = 1;
            iVar10 = *(int *)pdVar23;
            if (iVar10 != 0) {
              iVar10 = 0;
              while (iVar12 = ECDSA_verify(0,data,0x14,auStack_740,(int)local_27e4,pEVar11),
                    iVar12 == 1) {
                iVar10 = iVar10 + 1;
                if ((*(int *)pdVar23 == 0) || (iVar10 == 0x7fffffff)) goto LAB_000303da;
              }
              iVar10 = 1;
              BIO_printf(bio_err,"ECDSA verify failure\n");
              ERR_print_errors(bio_err);
            }
LAB_000303da:
            dVar41 = (double)app_tminterval(1,usertime);
            pcVar33 = local_27f4;
            if (*(int *)(pdVar23 + 0x97) != 0) {
              pcVar33 = "+R6:%ld:%d:%.2f\n";
            }
            BIO_printf(bio_err,pcVar33,iVar10,uVar22,dVar41);
            *(double *)(PTR_ecdsa_results_00030488 + iVar6 * 0x10 + 8) =
                 dVar41 / (double)(longlong)iVar10;
          }
          else {
            BIO_printf(bio_err,"ECDSA verify failure.  No ECDSA verify will be done.\n");
            ERR_print_errors(bio_err);
            local_26c8[iVar6] = 0;
          }
          if ((int)local_2818 < 2) {
            if (iVar6 + 1 == 0x10) break;
            iVar7 = iVar6 + 2;
            local_26c8[iVar6 + 1] = 0;
            if (iVar7 < 0x10) {
              iVar10 = iVar6 + 3;
              local_26c8[iVar7] = 0;
              iVar7 = iVar10;
              if (iVar10 < 0x10) {
                iVar7 = iVar6 + 4;
                local_26c8[iVar10] = 0;
                if (iVar7 < 0x10) {
                  iVar10 = iVar6 + 5;
                  local_26c8[iVar7] = 0;
                  iVar7 = iVar10;
                  if (iVar10 < 0x10) {
                    iVar7 = iVar6 + 6;
                    local_26c8[iVar10] = 0;
                    if (iVar7 < 0x10) {
                      iVar10 = iVar6 + 7;
                      local_26c8[iVar7] = 0;
                      iVar7 = iVar10;
                      if (iVar10 < 0x10) {
                        iVar7 = iVar6 + 8;
                        local_26c8[iVar10] = 0;
                        if (iVar7 < 0x10) {
                          iVar10 = iVar6 + 9;
                          local_26c8[iVar7] = 0;
                          iVar7 = iVar10;
                          if (iVar10 < 0x10) {
                            iVar7 = iVar6 + 10;
                            local_26c8[iVar10] = 0;
                            if (iVar7 < 0x10) {
                              iVar10 = iVar6 + 0xb;
                              local_26c8[iVar7] = 0;
                              iVar7 = iVar10;
                              if (iVar10 < 0x10) {
                                iVar7 = iVar6 + 0xc;
                                local_26c8[iVar10] = 0;
                                if (iVar7 < 0x10) {
                                  iVar10 = iVar6 + 0xd;
                                  local_26c8[iVar7] = 0;
                                  iVar7 = iVar10;
                                  if (iVar10 < 0x10) {
                                    iVar7 = iVar6 + 0xe;
                                    local_26c8[iVar10] = 0;
                                    if (iVar7 < 0x10) {
                                      local_26c8[iVar7] = 0;
                                      iVar7 = iVar6 + 0xf;
                                      if (iVar6 == 0) {
                                        local_26c8[15] = 0;
                                        iVar7 = 0x10;
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
      iVar6 = iVar7 + 1;
    } while (iVar6 < 0x10);
    if (*(int *)(pdVar23 + 0xd6) != 0) {
      RAND_cleanup();
    }
    iVar6 = RAND_status();
    if (iVar6 != 1) {
      RAND_seed(PTR_rnd_seed_0002fd08,0x40);
      *(undefined4 *)(pdVar23 + 0xd6) = 1;
    }
    puVar5 = PTR_ecdh_results_0002fd0c;
    iVar6 = 0;
    local_2828 = "Doing %d bit %s %s\'s for %ds: ";
    local_27fc = "%ld %d-bit ECDH ops in %.2fs\n";
    do {
      iVar7 = iVar6;
      if (local_2688[iVar6] != 0) {
        iVar10 = *(int *)(test_curves_20475 + iVar6 * 4);
        pEVar11 = EC_KEY_new_by_curve_name(iVar10);
        local_2748[iVar6] = pEVar11;
        key = EC_KEY_new_by_curve_name(iVar10);
        local_2708[iVar6] = key;
        if ((pEVar11 == (EC_KEY *)0x0) || (key == (EC_KEY *)0x0)) {
          BIO_printf(bio_err,"ECDH failure.\n");
          ERR_print_errors(bio_err);
        }
        else {
          iVar10 = EC_KEY_generate_key(pEVar11);
          if ((iVar10 == 0) || (iVar10 = EC_KEY_generate_key(key), iVar10 == 0)) {
            BIO_printf(bio_err,"ECDH key generation failure.\n");
            ERR_print_errors(bio_err);
          }
          else {
            group = EC_KEY_get0_group(pEVar11);
            iVar10 = EC_GROUP_get_degree(group);
            if (iVar10 < 0xc1) {
              sVar29 = 0x14;
              local_281c = (char *)(KDF1_SHA1 + 1);
            }
            else {
              sVar29 = iVar10 + 7 >> 3;
              local_281c = (char *)0x0;
            }
            pEVar14 = EC_KEY_get0_public_key(key);
            iVar10 = ECDH_compute_key(local_640,sVar29,pEVar14,pEVar11,(KDF *)local_281c);
            pEVar14 = EC_KEY_get0_public_key(pEVar11);
            iVar12 = ECDH_compute_key(local_540,sVar29,pEVar14,key,(KDF *)local_281c);
            uVar15 = count_leading_zeroes(iVar10 - iVar12);
            uVar15 = uVar15 >> 5;
            if (iVar10 < 1) {
              uVar19 = 0;
            }
            else {
              uVar19 = uVar15 & 1;
            }
            if (uVar19 != 0) {
              iVar12 = 0;
              do {
                pbVar30 = local_640 + iVar12;
                pbVar31 = local_540 + iVar12;
                iVar12 = iVar12 + 1;
                uVar15 = count_leading_zeroes((uint)*pbVar30 - (uint)*pbVar31);
                uVar15 = uVar15 >> 5;
                if (iVar12 < iVar10) {
                  uVar19 = uVar15 & 1;
                }
                else {
                  uVar19 = 0;
                }
              } while (uVar19 != 0);
            }
            if (uVar15 == 0) {
              BIO_printf(bio_err,"ECDH computations don\'t match.\n");
              ERR_print_errors(bio_err);
            }
            uVar22 = *(undefined4 *)(test_curves_bits_20477 + iVar6 * 4);
            pcVar33 = local_2828;
            if (*(int *)(pdVar23 + 0x97) != 0) {
              pcVar33 = "+DTP:%d:%s:%s:%d\n";
            }
            BIO_printf(bio_err,pcVar33,uVar22,"",&DAT_00130bfc);
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
            app_tminterval(0,usertime);
            *(undefined4 *)pdVar23 = 1;
            iVar10 = *(int *)pdVar23;
            if (iVar10 != 0) {
              iVar10 = 0;
              do {
                iVar10 = iVar10 + 1;
                pEVar14 = EC_KEY_get0_public_key(key);
                ECDH_compute_key(local_640,sVar29,pEVar14,pEVar11,(KDF *)local_281c);
                if (*(int *)pdVar23 == 0) break;
              } while (iVar10 != 0x7fffffff);
            }
            dVar41 = (double)app_tminterval(1,usertime);
            pcVar33 = local_27fc;
            if (*(int *)(pdVar23 + 0x97) != 0) {
              pcVar33 = "+R7:%ld:%d:%.2f\n";
            }
            BIO_printf(bio_err,pcVar33,iVar10,uVar22,dVar41);
            *(double *)(puVar5 + iVar6 * 8) = dVar41 / (double)(longlong)iVar10;
            if (1 < iVar10) goto LAB_0002fb9a;
          }
        }
        if (iVar6 + 1 == 0x10) break;
        iVar7 = iVar6 + 2;
        local_2688[iVar6 + 1] = 0;
        if (iVar7 < 0x10) {
          iVar10 = iVar6 + 3;
          local_2688[iVar7] = 0;
          iVar7 = iVar10;
          if (iVar10 < 0x10) {
            iVar7 = iVar6 + 4;
            local_2688[iVar10] = 0;
            if (iVar7 < 0x10) {
              iVar10 = iVar6 + 5;
              local_2688[iVar7] = 0;
              iVar7 = iVar10;
              if (iVar10 < 0x10) {
                iVar7 = iVar6 + 6;
                local_2688[iVar10] = 0;
                if (iVar7 < 0x10) {
                  iVar10 = iVar6 + 7;
                  local_2688[iVar7] = 0;
                  iVar7 = iVar10;
                  if (iVar10 < 0x10) {
                    iVar7 = iVar6 + 8;
                    local_2688[iVar10] = 0;
                    if (iVar7 < 0x10) {
                      iVar10 = iVar6 + 9;
                      local_2688[iVar7] = 0;
                      iVar7 = iVar10;
                      if (iVar10 < 0x10) {
                        iVar7 = iVar6 + 10;
                        local_2688[iVar10] = 0;
                        if (iVar7 < 0x10) {
                          iVar10 = iVar6 + 0xb;
                          local_2688[iVar7] = 0;
                          iVar7 = iVar10;
                          if (iVar10 < 0x10) {
                            iVar7 = iVar6 + 0xc;
                            local_2688[iVar10] = 0;
                            if (iVar7 < 0x10) {
                              iVar10 = iVar6 + 0xd;
                              local_2688[iVar7] = 0;
                              iVar7 = iVar10;
                              if (iVar10 < 0x10) {
                                iVar7 = iVar6 + 0xe;
                                local_2688[iVar10] = 0;
                                if (iVar7 < 0x10) {
                                  local_2688[iVar7] = 0;
                                  iVar7 = iVar6 + 0xf;
                                  if (iVar6 == 0) {
                                    local_2688[15] = 0;
                                    iVar7 = 0x10;
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
LAB_0002fb9a:
      iVar6 = iVar7 + 1;
    } while (iVar6 < 0x10);
    if (*(int *)(pdVar23 + 0xd6) != 0) {
      RAND_cleanup();
    }
  }
  else {
    __ptr = malloc((int)local_2820 << 2);
    local_281c = (char *)((int)__ptr + -4);
    puVar35 = (uint *)local_281c;
    do {
      iVar7 = pipe((int *)&local_18f8);
      if (iVar7 == -1) {
        fwrite("pipe failure\n",1,0xd,stderr);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      fflush(stdout);
      fflush(stderr);
      _Var13 = fork();
      if (_Var13 == 0) {
        close(local_18f8.P[0]);
        close(1);
        iVar7 = dup(local_18f8.P[1]);
        if (iVar7 == -1) {
          fwrite("dup failed\n",1,0xb,stderr);
                    /* WARNING: Subroutine does not return */
          exit(1);
        }
        close(local_18f8.P[1]);
        mr = 1;
        usertime = _Var13;
        free(__ptr);
        goto LAB_0002cf3c;
      }
      close(local_18f8.P[1]);
      pEVar9 = (EVP_MD *)((int)&local_2804->type + 1);
      puVar35 = puVar35 + 1;
      *puVar35 = local_18f8.P[0];
      __printf_chk(1,"Forked child %d\n",local_2804);
      puVar5 = PTR_results_00030de0;
      local_2804 = pEVar9;
    } while ((int)pEVar9 < (int)local_2820);
    iVar6 = 0;
    do {
      local_281c = (char *)((int)local_281c + 4);
      pFVar16 = fdopen(*(uint *)local_281c,"r");
LAB_00030b6a:
      local_27ec = fgets(auStack_440,0x400,pFVar16);
      if (local_27ec != (char *)0x0) {
        while( true ) {
          pcVar33 = strchr(auStack_440,10);
          if (pcVar33 != (char *)0x0) {
            *pcVar33 = '\0';
          }
          if (auStack_440[0] == '+') break;
          __fprintf_chk(stderr,1,"Don\'t understand line \'%s\' from child %d\n",auStack_440,iVar6);
          local_27ec = fgets(auStack_440,0x400,pFVar16);
          if (local_27ec == (char *)0x0) goto LAB_00030bb6;
        }
        __printf_chk(1,"Got: %s from %d\n",auStack_440,iVar6);
        iVar7 = strncmp(auStack_440,"+F:",3);
        if (iVar7 == 0) {
          pbVar30 = (byte *)(uint)bStack_43d;
          if (pbVar30 == (byte *)0x0) {
            pbVar31 = &bStack_43d;
          }
          else {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar31 = PTR_sep_21683_00030de4;
            bVar2 = (byte)sep_21683;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar31 = pbVar31 + 1;
              bVar2 = *pbVar31;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = &bStack_43d;
            pbVar31 = pbVar30;
            pbVar21 = pbVar30;
            if (*pcVar33 == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              pbVar21 = pbVar31;
              if (*pbVar31 == 0) goto LAB_00030ce6;
            }
            pbVar31 = pbVar21 + 1;
            *pbVar21 = 0;
          }
LAB_00030ce6:
          lVar17 = strtol((char *)pbVar30,(char **)0x0,10);
          pbVar30 = (byte *)(uint)*pbVar31;
          if (pbVar30 != (byte *)0x0) {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar21 = PTR_sep_21683_00030de4;
            bVar2 = (byte)sep_21683;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar21 = pbVar21 + 1;
              bVar2 = *pbVar21;
            }
            pbVar21 = pbVar31;
            if (local_540[(int)pbVar30] == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
                pbVar30 = (byte *)(uint)*pbVar31;
              } while (local_540[(int)pbVar30] == '\0');
              pbVar21 = pbVar31;
              if (pbVar30 == (byte *)0x0) goto LAB_00030d4a;
            }
            pbVar31 = pbVar21 + 1;
            *pbVar21 = 0;
            pbVar30 = (byte *)(uint)pbVar21[1];
          }
LAB_00030d4a:
          iVar7 = 5;
          pdVar23 = (double *)(puVar5 + lVar17 * 0x28);
          do {
            dVar41 = *pdVar23;
            pbVar21 = pbVar31;
            if (pbVar30 != (byte *)0x0) {
              memset(local_540,0,0x100);
              local_540[0] = 1;
              pbVar20 = PTR_sep_21683_00030de4;
              bVar2 = (byte)sep_21683;
              while (bVar2 != 0) {
                local_540[bVar2] = 1;
                pbVar20 = pbVar20 + 1;
                bVar2 = *pbVar20;
              }
              pbVar20 = pbVar31;
              if (local_540[(int)pbVar30] == '\0') {
                do {
                  pbVar21 = pbVar21 + 1;
                } while (local_540[*pbVar21] == '\0');
                pbVar30 = pbVar31;
                pbVar20 = pbVar21;
                if (*pbVar21 == 0) goto LAB_00030db2;
              }
              pbVar21 = pbVar20 + 1;
              *pbVar20 = 0;
              pbVar30 = pbVar31;
            }
LAB_00030db2:
            dVar42 = strtod((char *)pbVar30,(char **)0x0);
            iVar7 = iVar7 + -1;
            *pdVar23 = dVar41 + dVar42;
            if (iVar7 == 0) goto LAB_00030b6a;
            pbVar30 = (byte *)(uint)*pbVar21;
            pbVar31 = pbVar21;
            pdVar23 = pdVar23 + 1;
          } while( true );
        }
        iVar7 = strncmp(auStack_440,"+F2:",4);
        if (iVar7 == 0) {
          pbVar30 = (byte *)(uint)local_43c[0];
          if (pbVar30 == (byte *)0x0) {
            pbVar31 = local_43c;
          }
          else {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar31 = PTR_sep_21683_000310a0;
            bVar2 = (byte)sep_21683;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar31 = pbVar31 + 1;
              bVar2 = *pbVar31;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = local_43c;
            pbVar31 = pbVar30;
            pbVar21 = pbVar30;
            if (*pcVar33 == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              pbVar21 = pbVar31;
              if (*pbVar31 == 0) goto LAB_00030e3c;
            }
            pbVar31 = pbVar21 + 1;
            *pbVar21 = 0;
          }
LAB_00030e3c:
          lVar17 = strtol((char *)pbVar30,(char **)0x0,10);
          pbVar30 = (byte *)(uint)*pbVar31;
          if (pbVar30 != (byte *)0x0) {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar21 = PTR_sep_21683_000310a0;
            bVar2 = (byte)sep_21683;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar21 = pbVar21 + 1;
              bVar2 = *pbVar21;
            }
            if (local_540[(int)pbVar30] == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              if (*pbVar31 != 0) goto LAB_000311ec;
            }
            else {
LAB_000311ec:
              pbVar30 = pbVar31 + 1;
              *pbVar31 = 0;
              bVar2 = pbVar31[1];
              pbVar31 = pbVar30;
              if (bVar2 != 0) {
                memset(local_540,0,0x100);
                local_540[0] = 1;
                pbVar21 = PTR_sep_21683_0003139c;
                bVar3 = (byte)sep_21683;
                while (bVar3 != 0) {
                  local_540[bVar3] = 1;
                  pbVar21 = pbVar21 + 1;
                  bVar3 = *pbVar21;
                }
                pbVar21 = pbVar30;
                if (local_540[bVar2] == '\0') {
                  do {
                    pbVar31 = pbVar31 + 1;
                  } while (local_540[*pbVar31] == '\0');
                  pbVar21 = pbVar31;
                  if (*pbVar31 == 0) goto LAB_00030e98;
                }
                pbVar31 = pbVar21 + 1;
                *pbVar21 = 0;
                goto LAB_00030e98;
              }
            }
            pbVar30 = (byte *)0x0;
          }
LAB_00030e98:
          dVar41 = strtod((char *)pbVar30,(char **)0x0);
          if (iVar6 == 0) {
            iVar7 = lVar17 << 4;
            puVar36 = PTR_rsa_results_00031700;
          }
          else {
            iVar7 = lVar17 * 0x10;
            dVar41 = 1.0 / (1.0 / *(double *)(PTR_rsa_results_000310a4 + iVar7) + 1.0 / dVar41);
            puVar36 = PTR_rsa_results_000310a4;
          }
          pbVar30 = (byte *)(uint)*pbVar31;
          *(double *)(puVar36 + iVar7) = dVar41;
          if (pbVar30 == (byte *)0x0) goto LAB_00030f18;
          memset(local_540,0,0x100);
          local_540[0] = 1;
          pbVar21 = PTR_sep_21683_000310a0;
          bVar2 = (byte)sep_21683;
          while (bVar2 != 0) {
            local_540[bVar2] = 1;
            pbVar21 = pbVar21 + 1;
            bVar2 = *pbVar21;
          }
          pcVar33 = local_540 + (int)pbVar30;
          pbVar30 = pbVar31;
          if (*pcVar33 == '\0') {
            do {
              pbVar31 = pbVar31 + 1;
              uVar15 = (uint)*pbVar31;
            } while (local_540[uVar15] == '\0');
            goto LAB_00030f14;
          }
LAB_00030f48:
          local_540[0] = 1;
          *pbVar31 = 0;
        }
        else {
          iVar7 = strncmp(auStack_440,"+F3:",4);
          if (iVar7 == 0) {
            pbVar30 = (byte *)(uint)local_43c[0];
            if (pbVar30 == (byte *)0x0) {
              pbVar31 = local_43c;
            }
            else {
              memset(local_540,0,0x100);
              local_540[0] = 1;
              pbVar31 = PTR_sep_21683_000310a0;
              bVar2 = (byte)sep_21683;
              while (bVar2 != 0) {
                local_540[bVar2] = 1;
                pbVar31 = pbVar31 + 1;
                bVar2 = *pbVar31;
              }
              pcVar33 = local_540 + (int)pbVar30;
              pbVar30 = local_43c;
              pbVar31 = pbVar30;
              pbVar21 = pbVar30;
              if (*pcVar33 == '\0') {
                do {
                  pbVar31 = pbVar31 + 1;
                } while (local_540[*pbVar31] == '\0');
                pbVar21 = pbVar31;
                if (*pbVar31 == 0) goto LAB_00030fa4;
              }
              pbVar31 = pbVar21 + 1;
              *pbVar21 = 0;
            }
LAB_00030fa4:
            lVar17 = strtol((char *)pbVar30,(char **)0x0,10);
            pbVar30 = (byte *)(uint)*pbVar31;
            if (pbVar30 != (byte *)0x0) {
              memset(local_540,0,0x100);
              local_540[0] = 1;
              pbVar21 = PTR_sep_21683_000310a0;
              bVar2 = (byte)sep_21683;
              while (bVar2 != 0) {
                local_540[bVar2] = 1;
                pbVar21 = pbVar21 + 1;
                bVar2 = *pbVar21;
              }
              if (local_540[(int)pbVar30] == '\0') {
                do {
                  pbVar31 = pbVar31 + 1;
                } while (local_540[*pbVar31] == '\0');
                if (*pbVar31 != 0) goto LAB_00031330;
              }
              else {
LAB_00031330:
                pbVar30 = pbVar31 + 1;
                *pbVar31 = 0;
                bVar2 = pbVar31[1];
                pbVar31 = pbVar30;
                if (bVar2 != 0) {
                  memset(local_540,0,0x100);
                  local_540[0] = 1;
                  pbVar21 = PTR_sep_21683_0003139c;
                  bVar3 = (byte)sep_21683;
                  while (bVar3 != 0) {
                    local_540[bVar3] = 1;
                    pbVar21 = pbVar21 + 1;
                    bVar3 = *pbVar21;
                  }
                  pbVar21 = pbVar30;
                  if (local_540[bVar2] == '\0') {
                    do {
                      pbVar31 = pbVar31 + 1;
                    } while (local_540[*pbVar31] == '\0');
                    pbVar21 = pbVar31;
                    if (*pbVar31 == 0) goto LAB_00031000;
                  }
                  pbVar31 = pbVar21 + 1;
                  *pbVar21 = 0;
                  goto LAB_00031000;
                }
              }
              pbVar30 = (byte *)0x0;
            }
LAB_00031000:
            dVar41 = strtod((char *)pbVar30,(char **)0x0);
            if (iVar6 == 0) {
              iVar7 = lVar17 << 4;
              puVar36 = PTR_dsa_results_000319d8;
            }
            else {
              iVar7 = lVar17 * 0x10;
              dVar41 = 1.0 / (1.0 / *(double *)(PTR_dsa_results_000310a8 + iVar7) + 1.0 / dVar41);
              puVar36 = PTR_dsa_results_000310a8;
            }
            pbVar30 = (byte *)(uint)*pbVar31;
            *(double *)(puVar36 + iVar7) = dVar41;
            if (pbVar30 == (byte *)0x0) goto LAB_00030f18;
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar21 = PTR_sep_21683_000310a0;
            bVar2 = (byte)sep_21683;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar21 = pbVar21 + 1;
              bVar2 = *pbVar21;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = pbVar31;
            if (*pcVar33 == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
                uVar15 = (uint)*pbVar31;
              } while (local_540[uVar15] == '\0');
              goto LAB_00030f14;
            }
            goto LAB_00030f48;
          }
          iVar7 = strncmp(auStack_440,"+F4:",4);
          if (iVar7 != 0) {
            iVar7 = strncmp(auStack_440,"+F5:",4);
            if (iVar7 == 0) {
              pbVar30 = (byte *)(uint)local_43c[0];
              if (pbVar30 == (byte *)0x0) {
                pbVar31 = local_43c;
              }
              else {
                memset(local_540,0,0x100);
                local_540[0] = 1;
                pbVar31 = PTR_sep_21683_0003139c;
                bVar2 = (byte)sep_21683;
                while (bVar2 != 0) {
                  local_540[bVar2] = 1;
                  pbVar31 = pbVar31 + 1;
                  bVar2 = *pbVar31;
                }
                pcVar33 = local_540 + (int)pbVar30;
                pbVar30 = local_43c;
                pbVar31 = pbVar30;
                pbVar21 = pbVar30;
                if (*pcVar33 == '\0') {
                  do {
                    pbVar31 = pbVar31 + 1;
                  } while (local_540[*pbVar31] == '\0');
                  pbVar21 = pbVar31;
                  if (*pbVar31 == 0) goto LAB_0003129a;
                }
                pbVar31 = pbVar21 + 1;
                *pbVar21 = 0;
              }
LAB_0003129a:
              lVar17 = strtol((char *)pbVar30,(char **)0x0,10);
              pbVar30 = (byte *)(uint)*pbVar31;
              if (pbVar30 != (byte *)0x0) {
                memset(local_540,0,0x100);
                local_540[0] = 1;
                pbVar21 = PTR_sep_21683_0003139c;
                bVar2 = (byte)sep_21683;
                while (bVar2 != 0) {
                  local_540[bVar2] = 1;
                  pbVar21 = pbVar21 + 1;
                  bVar2 = *pbVar21;
                }
                if (local_540[(int)pbVar30] == '\0') {
                  do {
                    pbVar31 = pbVar31 + 1;
                  } while (local_540[*pbVar31] == '\0');
                  if (*pbVar31 != 0) goto LAB_0003142e;
                }
                else {
LAB_0003142e:
                  pbVar30 = pbVar31 + 1;
                  *pbVar31 = 0;
                  bVar2 = pbVar31[1];
                  if (bVar2 != 0) {
                    memset(local_540,0,0x100);
                    local_540[0] = 1;
                    pbVar31 = PTR_sep_21683_000316fc;
                    bVar3 = (byte)sep_21683;
                    while (bVar3 != 0) {
                      local_540[bVar3] = 1;
                      pbVar31 = pbVar31 + 1;
                      bVar3 = *pbVar31;
                    }
                    pbVar31 = pbVar30;
                    if (local_540[bVar2] == '\0') {
                      do {
                        pbVar31 = pbVar31 + 1;
                      } while (local_540[*pbVar31] == '\0');
                      if (*pbVar31 == 0) goto LAB_000312f0;
                    }
                    *pbVar31 = 0;
                    goto LAB_000312f0;
                  }
                }
                pbVar30 = (byte *)0x0;
              }
LAB_000312f0:
              dVar41 = strtod((char *)pbVar30,(char **)0x0);
              if (iVar6 == 0) {
                *(double *)(puVar5 + lVar17 * 8 + 0x628) = dVar41;
              }
              else {
                *(double *)(puVar5 + lVar17 * 8 + 0x628) =
                     1.0 / (1.0 / *(double *)(puVar5 + lVar17 * 8 + 0x628) + 1.0 / dVar41);
              }
            }
            else {
              iVar7 = strncmp(auStack_440,"+H:",3);
              if (iVar7 != 0) {
                __fprintf_chk(stderr,1,"Unknown type \'%s\' from child %d\n",auStack_440,iVar6);
              }
            }
            goto LAB_00030b6a;
          }
          pbVar30 = (byte *)(uint)local_43c[0];
          if (pbVar30 == (byte *)0x0) {
            pbVar31 = local_43c;
          }
          else {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar31 = PTR_sep_21683_0003139c;
            bVar2 = (byte)sep_21683;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar31 = pbVar31 + 1;
              bVar2 = *pbVar31;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = local_43c;
            pbVar31 = pbVar30;
            pbVar21 = pbVar30;
            if (*pcVar33 == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              pbVar21 = pbVar31;
              if (*pbVar31 == 0) goto LAB_00031100;
            }
            pbVar31 = pbVar21 + 1;
            *pbVar21 = 0;
          }
LAB_00031100:
          lVar17 = strtol((char *)pbVar30,(char **)0x0,10);
          pbVar30 = (byte *)(uint)*pbVar31;
          if (pbVar30 != (byte *)0x0) {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar21 = PTR_sep_21683_0003139c;
            bVar2 = (byte)sep_21683;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar21 = pbVar21 + 1;
              bVar2 = *pbVar21;
            }
            if (local_540[(int)pbVar30] == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              if (*pbVar31 != 0) goto LAB_000313a4;
            }
            else {
LAB_000313a4:
              pbVar30 = pbVar31 + 1;
              *pbVar31 = 0;
              bVar2 = pbVar31[1];
              pbVar31 = pbVar30;
              if (bVar2 != 0) {
                memset(local_540,0,0x100);
                local_540[0] = 1;
                pbVar21 = PTR_sep_21683_000316fc;
                bVar3 = (byte)sep_21683;
                while (bVar3 != 0) {
                  local_540[bVar3] = 1;
                  pbVar21 = pbVar21 + 1;
                  bVar3 = *pbVar21;
                }
                pbVar21 = pbVar30;
                if (local_540[bVar2] == '\0') {
                  do {
                    pbVar31 = pbVar31 + 1;
                  } while (local_540[*pbVar31] == '\0');
                  pbVar21 = pbVar31;
                  if (*pbVar31 == 0) goto LAB_0003115c;
                }
                pbVar31 = pbVar21 + 1;
                *pbVar21 = 0;
                goto LAB_0003115c;
              }
            }
            pbVar30 = (byte *)0x0;
          }
LAB_0003115c:
          dVar41 = strtod((char *)pbVar30,(char **)0x0);
          if (iVar6 == 0) {
            iVar7 = lVar17 << 4;
            puVar36 = PTR_ecdsa_results_000319dc;
          }
          else {
            iVar7 = lVar17 * 0x10;
            dVar41 = 1.0 / (1.0 / *(double *)(PTR_ecdsa_results_000313a0 + iVar7) + 1.0 / dVar41);
            puVar36 = PTR_ecdsa_results_000313a0;
          }
          pbVar30 = (byte *)(uint)*pbVar31;
          *(double *)(puVar36 + iVar7) = dVar41;
          if (pbVar30 != (byte *)0x0) {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar21 = PTR_sep_21683_0003139c;
            bVar2 = (byte)sep_21683;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar21 = pbVar21 + 1;
              bVar2 = *pbVar21;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = pbVar31;
            if (*pcVar33 != '\0') goto LAB_00030f48;
            do {
              pbVar31 = pbVar31 + 1;
              uVar15 = (uint)*pbVar31;
            } while (local_540[uVar15] == '\0');
LAB_00030f14:
            local_540[0] = 1;
            if (uVar15 != 0) goto LAB_00030f48;
          }
        }
LAB_00030f18:
        dVar41 = strtod((char *)pbVar30,(char **)0x0);
        if (iVar6 == 0) {
          *(double *)(puVar36 + iVar7 + 8) = dVar41;
        }
        else {
          *(double *)(puVar36 + iVar7 + 8) =
               1.0 / (1.0 / *(double *)(puVar36 + iVar7 + 8) + 1.0 / dVar41);
        }
        goto LAB_00030b6a;
      }
LAB_00030bb6:
      iVar6 = iVar6 + 1;
      fclose(pFVar16);
    } while (iVar6 < (int)local_2820);
    free(__ptr);
    pdVar23 = (double *)&run;
  }
  pFVar16 = stdout;
  if (*(int *)(pdVar23 + 0x97) == 0) {
    pcVar33 = SSLeay_version(0);
    __fprintf_chk(pFVar16,1,"%s\n",pcVar33);
    pFVar16 = stdout;
    pcVar33 = SSLeay_version(3);
    __fprintf_chk(pFVar16,1,"%s\n",pcVar33);
    __printf_chk(1,"options:");
    pcVar33 = BN_options();
    __printf_chk(1,&DAT_00131388,pcVar33);
    pcVar33 = RC4_options();
    __printf_chk(1,&DAT_00131388,pcVar33);
    pcVar33 = DES_options();
    __printf_chk(1,&DAT_00131388,pcVar33);
    pcVar33 = AES_options();
    __printf_chk(1,&DAT_00131388,pcVar33);
    pcVar33 = idea_options();
    __printf_chk(1,&DAT_00131388,pcVar33);
    pcVar33 = BF_options();
    __printf_chk(1,&DAT_00131388,pcVar33);
    pFVar16 = stdout;
    pcVar33 = SSLeay_version(2);
    __fprintf_chk(pFVar16,1,&DAT_0013138c,pcVar33);
  }
  if (local_27ec != (char *)0x0) {
    if (*(int *)(pdVar23 + 0x97) == 0) {
      fwrite("The \'numbers\' are in 1000s of bytes per second processed.\n",1,0x3a,stdout);
      fwrite("type        ",1,0xc,stdout);
    }
    else {
      fwrite(&DAT_00131394,1,2,stdout);
    }
    puVar37 = DAT_00030114 + 5;
    puVar39 = DAT_00030114;
    do {
      puVar39 = puVar39 + 1;
      pcVar33 = "%7d bytes";
      if (*(int *)(pdVar23 + 0x97) != 0) {
        pcVar33 = ":%d";
      }
      __fprintf_chk(stdout,1,pcVar33,*puVar39);
    } while (puVar39 != puVar37);
    fputc(10,stdout);
  }
  dVar41 = DAT_000300e8;
  iVar6 = 0;
  local_2828 = " %11.2f ";
  iVar7 = 0;
  pdVar32 = (double *)PTR_results_000300f8;
  do {
    if (*(int *)((int)&local_2648 + iVar6) != 0) {
      if (*(int *)(pdVar23 + 0x97) == 0) {
        __fprintf_chk(stdout,1,"%-13s",*(undefined4 *)(PTR_names_00030480 + iVar6));
      }
      else {
        __fprintf_chk(stdout,1,"+F:%d:%s",iVar7,*(undefined4 *)(PTR_names_000300fc + iVar6));
      }
      iVar10 = 5;
      pdVar24 = pdVar32;
      do {
        dVar42 = *pdVar24;
        pdVar24 = pdVar24 + 1;
        if (dVar42 < dVar41) {
          pcVar33 = local_2828;
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = ":%.2f";
          }
LAB_0002fe30:
          __fprintf_chk(stdout,1,pcVar33);
        }
        else {
          if (*(int *)(pdVar23 + 0x97) != 0) {
            pcVar33 = ":%.2f";
            goto LAB_0002fe30;
          }
          __fprintf_chk(stdout,1," %11.2fk");
        }
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      fputc(10,stdout);
    }
    puVar5 = PTR_rsa_bits_20469_00030118;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 1;
    pdVar32 = pdVar32 + 5;
  } while (iVar6 != 0x78);
  iVar7 = 0;
  iVar10 = 0;
  iVar6 = 1;
  pdVar32 = DAT_00030100;
  do {
    if (*(int *)((int)local_27b8 + iVar7) != 0) {
      if (iVar6 == 0) {
LAB_00030162:
        iVar6 = *(int *)(pdVar23 + 0x97);
        iVar12 = 0;
        if (iVar6 == 0) {
          __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",
                        *(undefined4 *)(puVar5 + iVar7),pdVar32[-1],*pdVar32,1.0 / pdVar32[-1],
                        1.0 / *pdVar32);
          goto LAB_0002fec4;
        }
      }
      else {
        iVar12 = 1;
        if (*(int *)(pdVar23 + 0x97) == 0) {
          __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_00130f00);
          goto LAB_00030162;
        }
      }
      iVar6 = iVar12;
      __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",iVar10,*(undefined4 *)(puVar5 + iVar7));
    }
LAB_0002fec4:
    puVar36 = PTR_dsa_bits_20474_0003011c;
    iVar7 = iVar7 + 4;
    iVar10 = iVar10 + 1;
    pdVar32 = pdVar32 + 2;
  } while (iVar7 != 0x10);
  iVar7 = 0;
  iVar10 = 0;
  iVar6 = 1;
  pdVar32 = DAT_00030104;
  do {
    if (*(int *)((int)local_27d4 + iVar7) != 0) {
      if (iVar6 == 0) {
LAB_000301fe:
        iVar6 = *(int *)(pdVar23 + 0x97);
        iVar12 = 0;
        if (iVar6 == 0) {
          __fprintf_chk(stdout,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",
                        *(undefined4 *)(puVar36 + iVar7),pdVar32[-1],*pdVar32,1.0 / pdVar32[-1],
                        1.0 / *pdVar32);
          goto LAB_0002ff2c;
        }
      }
      else {
        iVar12 = 1;
        if (*(int *)(pdVar23 + 0x97) == 0) {
          __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_00130f00);
          goto LAB_000301fe;
        }
      }
      iVar6 = iVar12;
      __fprintf_chk(stdout,1,"+F3:%u:%u:%f:%f\n",iVar10,*(undefined4 *)(puVar36 + iVar7));
    }
LAB_0002ff2c:
    puVar5 = PTR_test_curves_bits_20477_00030120;
    iVar7 = iVar7 + 4;
    iVar10 = iVar10 + 1;
    pdVar32 = pdVar32 + 2;
  } while (iVar7 != 0xc);
  iVar7 = 0;
  iVar6 = 1;
  iVar10 = 0;
LAB_0002ff98:
  do {
    if (*(int *)((int)local_26c8 + iVar7) != 0) {
      if (iVar6 == 0) {
LAB_0002ffa4:
        iVar6 = *(int *)(pdVar23 + 0x97);
        if (iVar6 == 0) {
          puVar39 = (undefined4 *)(PTR_test_curves_names_20476_0003010c + iVar7);
          iVar10 = iVar10 + 1;
          puVar37 = (undefined4 *)(puVar5 + iVar7);
          iVar7 = iVar7 + 4;
          __fprintf_chk(stdout,1,"%4u bit ecdsa (%s) %8.4fs %8.4fs %8.1f %8.1f\n",*puVar37,*puVar39)
          ;
          if (iVar7 == 0x40) break;
          goto LAB_0002ff98;
        }
        iVar6 = 0;
      }
      else {
        iVar6 = 1;
        if (*(int *)(pdVar23 + 0x97) == 0) {
          __printf_chk(1,"%30ssign    verify    sign/s verify/s\n",&DAT_00130f00);
          goto LAB_0002ffa4;
        }
      }
      __fprintf_chk(stdout,1,"+F4:%u:%u:%f:%f\n",iVar10,*(undefined4 *)(puVar5 + iVar7));
    }
    iVar7 = iVar7 + 4;
    iVar10 = iVar10 + 1;
  } while (iVar7 != 0x40);
  puVar5 = PTR_test_curves_bits_20477_00030120;
  iVar6 = 0;
  iVar7 = 0;
  local_2828 = (char *)0x1;
LAB_00030060:
  do {
    if (*(int *)((int)local_2688 + iVar6) != 0) {
      if (local_2828 == (char *)0x0) {
LAB_0003006e:
        local_2828 = *(char **)(pdVar23 + 0x97);
        if (local_2828 == (char *)0x0) {
          iVar7 = iVar7 + 1;
          puVar39 = (undefined4 *)(PTR_test_curves_names_20476_0003010c + iVar6);
          puVar37 = (undefined4 *)(puVar5 + iVar6);
          iVar6 = iVar6 + 4;
          __fprintf_chk(stdout,1,"%4u bit ecdh (%s) %8.4fs %8.1f\n",*puVar37,*puVar39);
          if (iVar6 == 0x40) break;
          goto LAB_00030060;
        }
        local_2828 = (char *)0x0;
      }
      else {
        if (*(int *)(pdVar23 + 0x97) == 0) {
          __printf_chk(1,"%30sop      op/s\n",&DAT_00130f00);
          goto LAB_0003006e;
        }
        local_2828 = (char *)0x1;
      }
      __fprintf_chk(stdout,1,"+F5:%u:%u:%f:%f\n",iVar7,*(undefined4 *)(puVar5 + iVar6));
    }
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 1;
  } while (iVar6 != 0x40);
  uVar22 = 0;
LAB_0002f222:
  ERR_print_errors(bio_err);
  CRYPTO_free(data);
  CRYPTO_free(out);
  goto LAB_0002cd3e;
}

