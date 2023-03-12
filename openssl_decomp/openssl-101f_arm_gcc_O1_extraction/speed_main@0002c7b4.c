
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
  int iVar9;
  BIO_METHOD *type;
  EC_KEY *pEVar10;
  int iVar11;
  EC_KEY *key;
  void *__ptr;
  __pid_t _Var12;
  EC_GROUP *group;
  EC_POINT *pEVar13;
  uint uVar14;
  FILE *pFVar15;
  long lVar16;
  RSA_METHOD *meth;
  int *piVar17;
  uint uVar18;
  byte *pbVar19;
  byte *pbVar20;
  undefined4 uVar21;
  double *pdVar22;
  double *pdVar23;
  EVP_MD *pEVar24;
  RSA **ppRVar25;
  DSA **ppDVar26;
  EC_KEY **ppEVar27;
  char **ppcVar28;
  size_t sVar29;
  byte *pbVar30;
  byte *pbVar31;
  DSA *dsa;
  double *pdVar32;
  char *pcVar33;
  size_t *psVar34;
  undefined *puVar35;
  EVP_MD *pEVar36;
  undefined4 *puVar37;
  uint *puVar38;
  undefined4 *puVar39;
  EVP_MD *pEVar40;
  bool bVar41;
  double dVar42;
  double dVar43;
  double *local_2828;
  char *local_2824;
  double *local_281c;
  char *local_2818;
  char *local_2814;
  int local_2810;
  char *local_280c;
  char *local_2804;
  char *local_2800;
  char *local_27fc;
  EVP_MD *local_27f8;
  char *local_27f0;
  uint local_27e8;
  DSA *local_27e4;
  DSA *local_27e0 [3];
  int local_27d4 [2];
  RSA *local_27cc;
  RSA *local_27c8 [4];
  int local_27b8 [5];
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
  undefined local_440 [3];
  byte local_43d;
  byte local_43c [1024];
  uint local_3c;
  
  local_3c = __TMC_END__;
  usertime = -1;
  signal(0xd,(__sighandler_t)0x1);
  memset(PTR_results_0002ca6c,0,0x4b0);
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
    data = (uchar *)CRYPTO_malloc(0x2001,"speed.c",0x29b);
    if (data != (uchar *)0x0) {
      out = (uchar *)CRYPTO_malloc(0x2001,"speed.c",0x2a0);
      if (out == (uchar *)0x0) {
        uVar21 = 1;
        BIO_printf(bio_err,"out of memory\n");
        ERR_print_errors(bio_err);
        CRYPTO_free(data);
        goto LAB_0002c856;
      }
      memset(auStack_1b50,0,600);
      local_820 = 0;
      local_81c = 0;
      local_818 = 0;
      local_814 = 0;
      local_810 = 0;
      local_80c = 0;
      local_8b0 = 0;
      local_808 = 0;
      local_8ac = 0;
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
      local_2800 = (char *)(param_1 + -1);
      _Var12 = usertime;
      local_2804 = local_2800;
      local_27f8 = (EVP_MD *)local_2800;
      if ((EVP_MD *)local_2800 != (EVP_MD *)0x0) {
        pEVar36 = (EVP_MD *)0x0;
        local_2810 = 0;
        pEVar40 = (EVP_MD *)0x0;
        local_27f8 = (EVP_MD *)0x0;
LAB_0002c9e0:
        pcVar33 = *ppcVar28;
        if ((int)local_2800 < 1) {
LAB_0002ed74:
          iVar7 = strcmp(pcVar33,"mdc2");
          if (iVar7 == 0) {
            local_2644 = (EVP_MD *)0x1;
          }
          else {
            cVar1 = *pcVar33;
            if ((cVar1 == 'm') && (pcVar33[1] == 'd')) {
              if (pcVar33[2] == '4') {
                if (pcVar33[3] != '\0') goto LAB_0002edb2;
                local_2640 = 1;
              }
              else {
                if ((pcVar33[2] != '5') || (pcVar33[3] != '\0')) goto LAB_0002edb2;
                local_263c = 1;
              }
            }
            else {
LAB_0002edb2:
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
                                                        uVar21 = 1;
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
                                                  "ecdhp160  ecdhp192  ecdhp224  ecdhp256  ecdhp384  ecdhp521\n"
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
                                                  goto LAB_0002ee08;
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
            usertime = 0;
            goto LAB_0002c9d4;
          }
          iVar7 = strcmp(pcVar33,"-evp");
          if (iVar7 == 0) {
            if ((EVP_MD *)local_2800 == (EVP_MD *)0x1) {
              uVar21 = 1;
              BIO_printf(bio_err,"no EVP given\n");
              goto LAB_0002ee08;
            }
            pEVar36 = (EVP_MD *)EVP_get_cipherbyname(ppcVar28[1]);
            if ((pEVar36 == (EVP_MD *)0x0) &&
               (local_27f8 = EVP_get_digestbyname(ppcVar28[1]), local_27f8 == (EVP_MD *)0x0)) {
              uVar21 = 1;
              BIO_printf(bio_err,"%s is an unknown cipher or digest\n",ppcVar28[1]);
              goto LAB_0002ee08;
            }
            local_2800 = (char *)((int)&((EVP_MD *)((int)local_2800 + -0x4c))->md_ctrl + 2);
            ppcVar28 = ppcVar28 + 2;
            local_25f0 = 1;
            _Var12 = usertime;
            goto joined_r0x0002ca38;
          }
          iVar7 = strcmp(pcVar33,"-decrypt");
          if (iVar7 == 0) {
            iVar6 = iVar6 + -1;
            pEVar40 = (EVP_MD *)0x1;
          }
          else {
            iVar7 = strcmp(pcVar33,"-engine");
            if (iVar7 == 0) {
              local_2800 = (char *)((int)&((EVP_MD *)((int)local_2800 + -0x4c))->md_ctrl + 3);
              if ((EVP_MD *)local_2800 == (EVP_MD *)0x0) {
                uVar21 = 1;
                BIO_printf(bio_err,"no engine given\n");
                goto LAB_0002ee08;
              }
              iVar6 = iVar6 + -1;
              setup_engine(bio_err,ppcVar28[1],0);
              ppcVar28 = ppcVar28 + 1;
            }
            else {
              iVar7 = strcmp(pcVar33,"-multi");
              if (iVar7 != 0) {
                if ((((*pcVar33 != '-') || (pcVar33[1] != 'm')) || (pcVar33[2] != 'r')) ||
                   (pcVar33[3] != '\0')) goto LAB_0002ed74;
                iVar6 = iVar6 + -1;
                mr = 1;
                goto LAB_0002c9d4;
              }
              local_2800 = (char *)((int)&((EVP_MD *)((int)local_2800 + -0x4c))->md_ctrl + 3);
              if ((EVP_MD *)local_2800 == (EVP_MD *)0x0) {
                uVar21 = 1;
                BIO_printf(bio_err,"no multi count given\n");
                goto LAB_0002ee08;
              }
              local_2810 = strtol(ppcVar28[1],(char **)0x0,10);
              if (local_2810 < 1) {
                uVar21 = 1;
                BIO_printf(bio_err,"bad multi count\n");
                goto LAB_0002ee08;
              }
              iVar6 = iVar6 + -1;
              ppcVar28 = ppcVar28 + 1;
            }
          }
        }
LAB_0002c9d4:
        local_2800 = (char *)((int)&((EVP_MD *)((int)local_2800 + -0x4c))->md_ctrl + 3);
        ppcVar28 = ppcVar28 + 1;
        _Var12 = usertime;
joined_r0x0002ca38:
        iVar6 = iVar6 + 1;
        usertime = _Var12;
        if ((EVP_MD *)local_2800 == (EVP_MD *)0x0) goto LAB_0002ca3a;
        goto LAB_0002c9e0;
      }
      goto LAB_0002ca62;
    }
    BIO_printf(bio_err,"out of memory\n");
  }
  uVar21 = 1;
  ERR_print_errors(bio_err);
LAB_0002c856:
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
  if (local_3c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar21);
LAB_0002ca3a:
  if (local_2810 == 0) {
LAB_0002ca5e:
    local_2804 = (char *)pEVar36;
    local_2800 = (char *)pEVar40;
    if (iVar6 == 0) {
LAB_0002ca62:
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
    local_27fc = (char *)&local_18f8;
    piVar17 = local_2688 + 0xf;
    local_27f0 = (char *)0x0;
    do {
      piVar17 = piVar17 + 1;
      if (*piVar17 != 0) {
        local_27f0 = local_27f0 + 1;
      }
    } while (piVar17 != &local_25d4);
    if ((_Var12 == 0) && (mr == 0)) {
      BIO_printf(bio_err,"You have chosen to measure elapsed time instead of user CPU time.\n");
    }
    iVar6 = 0;
    iVar7 = 0;
    do {
      pRVar8 = d2i_RSAPrivateKey((RSA **)0x0,(uchar **)local_27fc,
                                 *(long *)(rsa_data_length_20461 + iVar6));
      *(RSA **)((int)local_27c8 + iVar6) = pRVar8;
      if (pRVar8 == (RSA *)0x0) {
        uVar21 = 1;
        BIO_printf(bio_err,"internal error loading RSA key number %d\n",iVar7);
        goto LAB_0002ee08;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar7 != 4);
    local_27e0[0] = (DSA *)get_dsa512();
    local_27e0[1] = (DSA *)get_dsa1024();
    local_27e0[2] = (DSA *)get_dsa2048();
    DES_set_key_unchecked((const_DES_cblock *)PTR_key_20443_0002ce00,&DStack_2550);
    DES_set_key_unchecked((const_DES_cblock *)PTR_key2_20444_0002ce04,&DStack_24d0);
    DES_set_key_unchecked((const_DES_cblock *)PTR_key3_20445_0002ce08,&DStack_2450);
    AES_set_encrypt_key(PTR_key16_20436_0002ce0c,0x80,&AStack_2274);
    AES_set_encrypt_key(PTR_key24_20437_0002ce10,0xc0,&AStack_2180);
    AES_set_encrypt_key(PTR_key32_20438_0002ce14,0x100,&AStack_208c);
    Camellia_set_key(PTR_key16_20436_0002ce0c,0x80,&CStack_1e98);
    Camellia_set_key(PTR_ckey24_20439_0002ce18,0xc0,&CStack_1d80);
    Camellia_set_key(PTR_ckey32_20440_0002ce1c,0x100,&CStack_1c68);
    idea_set_encrypt_key(PTR_key16_20436_0002ce0c,&IStack_234c);
    SEED_set_key(PTR_key16_20436_0002ce0c,&SStack_25d0);
    RC4_set_key((RC4_KEY *)local_440,0x10,PTR_key16_20436_0002ce0c);
    RC2_set_key(&RStack_1f98,0x10,PTR_key16_20436_0002ce0c,0x80);
    BF_set_key((BF_KEY *)local_27fc,0x10,PTR_key16_20436_0002ce0c);
    CAST_set_key(&CStack_23d0,0x10,PTR_key16_20436_0002ce0c);
    local_27b8[4] = 0;
    local_27a4 = 0;
    local_27a0 = 0;
    local_279c = 0;
    local_2798 = 0;
    local_2794 = 0;
    local_2790 = 0;
    local_278c = (EC_KEY *)0x0;
    signal(0xe,sig_done + 1);
    pdVar32 = DAT_0002f114;
    if (local_2644 == (EVP_MD *)0x0) {
      pdVar22 = (double *)&run;
      pEVar40 = local_2644;
      dVar42 = DAT_0002cdf8;
    }
    else {
      pdVar22 = DAT_0002f114 + -6;
      local_281c = DAT_0002f114;
      local_2828 = (double *)DAT_0002f118;
      local_280c = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar32 + 0x91) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._4_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._4_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          pEVar36 = (EVP_MD *)EVP_mdc2();
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          EVP_Digest(data,sVar29,auStack_8a8,(uint *)0x0,pEVar36,(ENGINE *)0x0);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002f11c;
        pcVar33 = local_280c;
        if (*(int *)(pdVar32 + 0x91) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._4_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_2640 != 0) {
      local_2828 = (double *)DAT_0002ce20;
      local_281c = DAT_0002ce24;
      local_280c = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._8_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._8_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          pEVar36 = EVP_md4();
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          EVP_Digest(data,sVar29,auStack_898,(uint *)0x0,pEVar36,(ENGINE *)0x0);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002ce28;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._8_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_263c != 0) {
      local_2828 = (double *)DAT_0002ce20;
      local_281c = DAT_0002ce2c;
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._12_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._12_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          pEVar36 = EVP_get_digestbyname("md5");
          EVP_Digest(data,sVar29,auStack_888,(uint *)0x0,pEVar36,(ENGINE *)0x0);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002d1b0;
        pcVar33 = "%d %s\'s in %.2fs\n";
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._12_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_2638 != 0) {
      local_2828 = (double *)DAT_00030dd4;
      local_281c = DAT_00030dd8;
      HMAC_CTX_init((HMAC_CTX *)local_540);
      pEVar40 = EVP_md5();
      HMAC_Init_ex((HMAC_CTX *)local_540,"This is a key...",0x10,pEVar40,(ENGINE *)0x0);
      local_280c = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._16_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._16_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          HMAC_Init_ex((HMAC_CTX *)local_540,(void *)0x0,0,(EVP_MD *)0x0,(ENGINE *)0x0);
          HMAC_Update((HMAC_CTX *)local_540,data,sVar29);
          HMAC_Final((HMAC_CTX *)local_540,auStack_878,(uint *)0x0);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._16_4_,dVar42);
        bVar41 = local_2828 != (double *)DAT_00030de0;
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (bVar41);
      HMAC_CTX_cleanup((HMAC_CTX *)local_540);
    }
    if (local_2634 != 0) {
      local_2828 = (double *)DAT_0002d1b4;
      local_281c = DAT_0002d1b8;
      local_280c = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._20_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._20_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          pEVar36 = EVP_sha1();
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          EVP_Digest(data,sVar29,auStack_868,(uint *)0x0,pEVar36,(ENGINE *)0x0);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002d1b0;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._20_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_25ec != 0) {
      local_2828 = DAT_0002d1bc;
      local_2814 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d1b4;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._92_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._92_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          SHA256(data,sVar29,auStack_840);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002d1b0;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._92_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_25e8 != 0) {
      local_2828 = DAT_0002d1c0;
      local_2814 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d1b4;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._96_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._96_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          SHA512(data,sVar29,auStack_7c0);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002d528;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._96_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_25e4 != 0) {
      local_2828 = DAT_0002d52c;
      local_2814 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d530;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._100_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._100_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          WHIRLPOOL(data,sVar29,auStack_780);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002d528;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._100_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_2630 != 0) {
      local_2828 = (double *)DAT_0002d530;
      local_281c = DAT_0002d534;
      local_280c = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._24_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._24_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          pEVar36 = EVP_ripemd160();
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          EVP_Digest(data,sVar29,auStack_854,(uint *)0x0,pEVar36,(ENGINE *)0x0);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002d528;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._24_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_262c != 0) {
      local_2828 = DAT_0002d538;
      local_2814 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d530;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._28_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._28_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          RC4((RC4_KEY *)local_440,sVar29,data,data);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002d894;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._28_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_2628 != 0) {
      local_2828 = DAT_0002d898;
      local_2814 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d8a4;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._32_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._32_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          DES_ncbc_encrypt(data,data,sVar29,&DStack_2550,(DES_cblock *)&local_8b0,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002d894;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._32_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_2624 != 0) {
      local_2828 = DAT_0002d89c;
      local_2814 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d8a4;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._36_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._36_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          DES_ede3_cbc_encrypt
                    (data,data,sVar29,&DStack_2550,&DStack_24d0,&DStack_2450,
                     (DES_cblock *)&local_8b0,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002d894;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._36_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_2608 != 0) {
      local_2828 = DAT_0002d8a0;
      local_2814 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002d8a4;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._64_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._64_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          AES_cbc_encrypt(data,data,sVar29,&AStack_2274,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002dc00;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._64_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_2604 != 0) {
      local_2828 = DAT_0002dc04;
      local_2814 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002dc10;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._68_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._68_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          AES_cbc_encrypt(data,data,sVar29,&AStack_2180,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002dc00;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._68_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_2600 != 0) {
      local_2828 = DAT_0002dc08;
      local_2814 = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002dc10;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._72_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._72_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          AES_cbc_encrypt(data,data,sVar29,&AStack_208c,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002dc00;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._72_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_25e0 != 0) {
      local_2828 = DAT_0002dc0c;
      local_280c = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002dc10;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._104_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._104_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          AES_ige_encrypt(data,out,sVar29,&AStack_2274,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002dfa8;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._104_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_25dc != 0) {
      local_2828 = DAT_0002dfac;
      local_280c = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002dfb8;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._108_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._108_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          AES_ige_encrypt(data,out,sVar29,&AStack_2180,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002dfa8;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._108_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    if (local_25d8 != 0) {
      local_2828 = DAT_0002dfb0;
      local_280c = "%d %s\'s in %.2fs\n";
      psVar34 = DAT_0002dfb8;
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._112_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._112_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          AES_ige_encrypt(data,out,sVar29,&AStack_208c,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_0002dfa8;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._112_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
    }
    local_2828 = DAT_00030ddc;
    if (local_25d4 != 0) {
      uVar21 = CRYPTO_gcm128_new(&AStack_2274,AES_encrypt);
      psVar34 = DAT_00030dd4;
      CRYPTO_gcm128_setiv(uVar21,"0123456789ab",0xc);
      local_2814 = "%d %s\'s in %.2fs\n";
      do {
        psVar34 = psVar34 + 1;
        sVar29 = *psVar34;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._116_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._116_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          CRYPTO_gcm128_aad(uVar21,data,sVar29);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar4 = DAT_00030de0;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._116_4_,dVar42);
        *local_2828 = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_2828 = local_2828 + 1;
      } while (psVar34 != psVar4);
      CRYPTO_gcm128_release(uVar21);
    }
    if (local_25fc != 0) {
      local_281c = DAT_0002dfb4;
      local_280c = "%d %s\'s in %.2fs\n";
      local_2828 = (double *)DAT_0002dfb8;
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._76_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._76_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          Camellia_cbc_encrypt(data,data,sVar29,&CStack_1e98,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e338;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._76_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_25f8 != 0) {
      local_281c = DAT_0002e33c;
      local_280c = "%d %s\'s in %.2fs\n";
      local_2828 = (double *)DAT_0002e348;
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._80_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._80_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          Camellia_cbc_encrypt(data,data,sVar29,&CStack_1d80,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e338;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._80_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_25f4 != 0) {
      local_281c = DAT_0002e340;
      local_280c = "%d %s\'s in %.2fs\n";
      local_2828 = (double *)DAT_0002e348;
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._84_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._84_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          Camellia_cbc_encrypt(data,data,sVar29,&CStack_1c68,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e338;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._84_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_2620 != 0) {
      local_281c = DAT_0002e344;
      local_280c = "%d %s\'s in %.2fs\n";
      local_2828 = (double *)DAT_0002e348;
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._40_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._40_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          idea_cbc_encrypt(data,data,sVar29,&IStack_234c,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e6c4;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._40_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_261c != 0) {
      local_281c = DAT_0002e6c8;
      local_280c = "%d %s\'s in %.2fs\n";
      local_2828 = (double *)DAT_0002e6d4;
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._44_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._44_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          SEED_cbc_encrypt(data,data,sVar29,&SStack_25d0,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e6c4;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._44_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_2618 != 0) {
      local_281c = DAT_0002e6cc;
      local_280c = "%d %s\'s in %.2fs\n";
      local_2828 = (double *)DAT_0002e6d4;
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._48_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._48_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          RC2_cbc_encrypt(data,data,sVar29,&RStack_1f98,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002e6c4;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._48_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_2610 != 0) {
      local_2828 = (double *)DAT_0002e6d4;
      local_281c = DAT_0002e6d0;
      local_280c = "%d %s\'s in %.2fs\n";
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._56_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._56_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          BF_cbc_encrypt(data,data,sVar29,(BF_KEY *)local_27fc,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002ea28;
        pcVar33 = local_280c;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._56_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    if (local_260c != 0) {
      local_281c = DAT_0002ea2c;
      local_2814 = "%d %s\'s in %.2fs\n";
      local_2828 = (double *)DAT_0002ea38;
      do {
        local_2828 = (double *)((int)local_2828 + 4);
        sVar29 = *(size_t *)local_2828;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._60_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        else {
          BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._60_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          app_tminterval(0,usertime);
        }
        run = 1;
        pEVar40 = (EVP_MD *)0x0;
        do {
          CAST_cbc_encrypt(data,data,sVar29,&CStack_23d0,(uchar *)&local_820,1);
          pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
          if (*(int *)pdVar22 == 0) break;
        } while (pEVar40 != (EVP_MD *)0x7fffffff);
        dVar42 = (double)app_tminterval(1,usertime);
        psVar34 = DAT_0002ea28;
        pcVar33 = local_2814;
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._60_4_,dVar42);
        *local_281c = ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
        local_281c = local_281c + 1;
      } while (local_2828 != (double *)psVar34);
    }
    puVar5 = PTR_results_0002ea30;
    if (local_25f0 != 0) {
      local_2828 = (double *)0x0;
      local_2818 = "Doing %s for %ds on %d size blocks: ";
      do {
        if ((EVP_MD *)local_2804 == (EVP_MD *)0x0) {
          sVar29 = *(size_t *)(PTR_lengths_000307d8 + (int)local_2828);
        }
        else {
          names._88_4_ = OBJ_nid2ln(*(int *)local_2804);
          sVar29 = *(size_t *)(PTR_lengths_0002ea3c + (int)local_2828);
          pcVar33 = local_2818;
          if (*(int *)(pdVar22 + 0x97) != 0) {
            pcVar33 = "+DT:%s:%d:%d\n";
          }
          BIO_printf(bio_err,pcVar33,names._88_4_,3,sVar29);
          BIO_ctrl(bio_err,0xb,0,(void *)0x0);
          alarm(3);
          EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)local_540);
          if ((EVP_MD *)local_2800 == (EVP_MD *)0x0) {
            EVP_EncryptInit_ex((EVP_CIPHER_CTX *)local_540,(EVP_CIPHER *)local_2804,(ENGINE *)0x0,
                               PTR_key16_20436_000307d0,(uchar *)&local_820);
            EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)local_540,0);
            app_tminterval(0,usertime);
            *(undefined4 *)pdVar22 = 1;
            pEVar40 = (EVP_MD *)local_2800;
            do {
              pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
              EVP_EncryptUpdate((EVP_CIPHER_CTX *)local_540,data,(int *)&local_27e4,data,sVar29);
              if (*(int *)pdVar22 == 0) break;
            } while (pEVar40 != (EVP_MD *)0x7fffffff);
            EVP_EncryptFinal_ex((EVP_CIPHER_CTX *)local_540,data,(int *)&local_27e4);
          }
          else {
            pEVar40 = (EVP_MD *)0x0;
            EVP_DecryptInit_ex((EVP_CIPHER_CTX *)local_540,(EVP_CIPHER *)local_2804,(ENGINE *)0x0,
                               PTR_key16_20436_0002ea34,(uchar *)&local_820);
            EVP_CIPHER_CTX_set_padding((EVP_CIPHER_CTX *)local_540,0);
            app_tminterval(0,usertime);
            *(undefined4 *)pdVar22 = 1;
            do {
              pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
              EVP_DecryptUpdate((EVP_CIPHER_CTX *)local_540,data,(int *)&local_27e4,data,sVar29);
              if (*(int *)pdVar22 == 0) break;
            } while (pEVar40 != (EVP_MD *)0x7fffffff);
            EVP_DecryptFinal_ex((EVP_CIPHER_CTX *)local_540,data,(int *)&local_27e4);
          }
          dVar42 = (double)app_tminterval(1,usertime);
          EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)local_540);
        }
        if (local_27f8 != (EVP_MD *)0x0) {
          names._88_4_ = OBJ_nid2ln(local_27f8->type);
          if (*(int *)(pdVar22 + 0x97) == 0) {
            BIO_printf(bio_err,"Doing %s for %ds on %d size blocks: ",names._88_4_,3,sVar29);
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(3);
            app_tminterval(0,usertime);
          }
          else {
            BIO_printf(bio_err,"+DT:%s:%d:%d\n",names._88_4_,3,sVar29);
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(3);
            app_tminterval(0,usertime);
          }
          run = 1;
          pEVar40 = (EVP_MD *)0x0;
          do {
            pEVar40 = (EVP_MD *)((int)&pEVar40->type + 1);
            EVP_Digest(data,sVar29,auStack_800,(uint *)0x0,local_27f8,(ENGINE *)0x0);
            if (*(int *)pdVar22 == 0) break;
          } while (pEVar40 != (EVP_MD *)0x7fffffff);
          dVar42 = (double)app_tminterval(1,usertime);
        }
        pcVar33 = "%d %s\'s in %.2fs\n";
        if (*(int *)(pdVar22 + 0x97) != 0) {
          pcVar33 = "+R:%d:%s:%f\n";
        }
        BIO_printf(bio_err,pcVar33,pEVar40,names._88_4_,dVar42);
        iVar6 = (int)local_2828 * 2;
        local_2828 = (double *)((int)local_2828 + 4);
        *(double *)(puVar5 + iVar6 + 0x370) =
             ((double)(longlong)(int)pEVar40 / dVar42) * (double)(longlong)(int)sVar29;
      } while (local_2828 != (double *)0x14);
    }
    RAND_pseudo_bytes(data,0x24);
    local_27fc = "%ld %d bit public RSA\'s in %.2fs\n";
    iVar6 = 0;
    do {
      if (local_27b8[iVar6] != 0) {
        pRVar8 = local_27c8[iVar6];
        iVar7 = RSA_sign(0x72,data,0x24,out,&local_27e8,pRVar8);
        if (iVar7 == 0) {
          local_2818 = (char *)0x1;
          BIO_printf(bio_err,"RSA sign failure.  No RSA sign will be done.\n");
          ERR_print_errors(bio_err);
        }
        else {
          iVar7 = *(int *)(pdVar22 + 0x97);
          uVar21 = *(undefined4 *)(rsa_bits_20459 + iVar6 * 4);
          if (iVar7 == 0) {
            BIO_printf(bio_err,"Doing %d bit %s %s\'s for %ds: ",uVar21,"private","rsa");
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
          }
          else {
            BIO_printf(bio_err,"+DTP:%d:%s:%s:%d\n",uVar21,"private","rsa");
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
            iVar7 = 0;
          }
          local_2818 = (char *)0x0;
          app_tminterval(iVar7,usertime);
          run = 1;
          while (iVar7 = RSA_sign(0x72,data,0x24,out,&local_27e8,pRVar8), iVar7 != 0) {
            local_2818 = (char *)((int)local_2818 + 1);
            if ((*(int *)pdVar22 == 0) || (local_2818 == (char *)0x7fffffff)) goto LAB_0002f064;
          }
          local_2818 = (char *)0x1;
          BIO_printf(bio_err,"RSA sign failure\n");
          ERR_print_errors(bio_err);
LAB_0002f064:
          dVar42 = (double)app_tminterval(1,usertime);
          pcVar33 = "%ld %d bit private RSA\'s in %.2fs\n";
          if (*(int *)(pdVar22 + 0x97) != 0) {
            pcVar33 = "+R1:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar33,local_2818,uVar21,dVar42);
          *(double *)(PTR_rsa_results_0002f124 + iVar6 * 0x10) =
               dVar42 / (double)(longlong)(int)local_2818;
        }
        iVar7 = RSA_verify(0x72,data,0x24,out,local_27e8,pRVar8);
        if (iVar7 < 1) {
          BIO_printf(bio_err,"RSA verify failure.  No RSA verify will be done.\n");
          ERR_print_errors(bio_err);
          local_27b8[iVar6] = 0;
        }
        else {
          uVar21 = *(undefined4 *)(rsa_bits_20459 + iVar6 * 4);
          if (*(int *)(pdVar22 + 0x97) == 0) {
            BIO_printf(bio_err,"Doing %d bit %s %s\'s for %ds: ",uVar21,"public","rsa");
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
            app_tminterval(0,usertime);
          }
          else {
            BIO_printf(bio_err,"+DTP:%d:%s:%s:%d\n",uVar21,"public","rsa");
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
            app_tminterval(0,usertime);
          }
          run = 1;
          iVar7 = 0;
          while (iVar9 = RSA_verify(0x72,data,0x24,out,local_27e8,pRVar8), 0 < iVar9) {
            iVar7 = iVar7 + 1;
            if ((*(int *)pdVar22 == 0) || (iVar7 == 0x7fffffff)) goto LAB_0002ec42;
          }
          iVar7 = 1;
          BIO_printf(bio_err,"RSA verify failure\n");
          ERR_print_errors(bio_err);
LAB_0002ec42:
          dVar42 = (double)app_tminterval(1,usertime);
          pcVar33 = local_27fc;
          if (*(int *)(pdVar22 + 0x97) != 0) {
            pcVar33 = "+R2:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar33,iVar7,uVar21,dVar42);
          *(double *)(PTR_rsa_results_0002f124 + iVar6 * 0x10 + 8) =
               dVar42 / (double)(longlong)iVar7;
        }
        if (local_2818 == (char *)0x1) {
          if (iVar6 + 1 == 4) break;
          iVar9 = iVar6 + 2;
          local_27b8[iVar6 + 1] = 0;
          iVar7 = iVar6;
          if (3 < iVar9) {
            iVar7 = iVar9;
          }
          iVar6 = iVar7;
          if (iVar9 == 3 || iVar6 + -1 < 0 != SBORROW4(iVar9,3)) {
            local_27b8[iVar9] = 0;
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
      RAND_seed(PTR_rnd_seed_0002f120,0x40);
      *(undefined4 *)(pdVar22 + 0xd6) = 1;
    }
    local_27fc = "%ld %d bit DSA verify in %.2fs\n";
    iVar6 = 0;
    do {
      if (local_27d4[iVar6] == 0) {
LAB_0002f128:
        iVar6 = iVar6 + 1;
      }
      else {
        dsa = local_27e0[iVar6];
        iVar7 = DSA_sign(0x74,data,0x14,out,(uint *)&local_27e4,dsa);
        if (iVar7 == 0) {
          local_2818 = (char *)0x1;
          BIO_printf(bio_err,"DSA sign failure.  No DSA sign will be done.\n");
          ERR_print_errors(bio_err);
        }
        else {
          iVar7 = *(int *)(pdVar22 + 0x97);
          uVar21 = *(undefined4 *)(dsa_bits_20464 + iVar6 * 4);
          if (iVar7 == 0) {
            BIO_printf(bio_err,"Doing %d bit %s %s\'s for %ds: ",uVar21,"sign",&DAT_001250d0);
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
          }
          else {
            BIO_printf(bio_err,"+DTP:%d:%s:%s:%d\n",uVar21,"sign",&DAT_001250d0);
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
            iVar7 = 0;
          }
          local_2818 = (char *)0x0;
          app_tminterval(iVar7,usertime);
          run = 1;
          while (iVar7 = DSA_sign(0x74,data,0x14,out,(uint *)&local_27e4,dsa), iVar7 != 0) {
            local_2818 = (char *)((int)local_2818 + 1);
            if ((*(int *)pdVar22 == 0) || (local_2818 == (char *)0x7fffffff)) goto LAB_0002f38a;
          }
          local_2818 = (char *)0x1;
          BIO_printf(bio_err,"DSA sign failure\n");
          ERR_print_errors(bio_err);
LAB_0002f38a:
          dVar42 = (double)app_tminterval(1,usertime);
          pcVar33 = "%ld %d bit DSA signs in %.2fs\n";
          if (*(int *)(pdVar22 + 0x97) != 0) {
            pcVar33 = "+R3:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar33,local_2818,uVar21,dVar42);
          *(double *)(PTR_dsa_results_0002f754 + iVar6 * 0x10) =
               dVar42 / (double)(longlong)(int)local_2818;
        }
        iVar7 = DSA_verify(0x74,data,0x14,out,(int)local_27e4,dsa);
        if (iVar7 < 1) {
          BIO_printf(bio_err,"DSA verify failure.  No DSA verify will be done.\n");
          ERR_print_errors(bio_err);
          local_27d4[iVar6] = 0;
        }
        else {
          uVar21 = *(undefined4 *)(dsa_bits_20464 + iVar6 * 4);
          if (*(int *)(pdVar22 + 0x97) == 0) {
            BIO_printf(bio_err,"Doing %d bit %s %s\'s for %ds: ",uVar21,"verify",&DAT_001250d0);
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
            app_tminterval(0,usertime);
          }
          else {
            BIO_printf(bio_err,"+DTP:%d:%s:%s:%d\n",uVar21,"verify",&DAT_001250d0);
            BIO_ctrl(bio_err,0xb,0,(void *)0x0);
            alarm(10);
            app_tminterval(0,usertime);
          }
          run = 1;
          iVar7 = 0;
          while (iVar9 = DSA_verify(0x74,data,0x14,out,(int)local_27e4,dsa), 0 < iVar9) {
            iVar7 = iVar7 + 1;
            if ((*(int *)pdVar22 == 0) || (iVar7 == 0x7fffffff)) goto LAB_0002f24e;
          }
          iVar7 = 1;
          BIO_printf(bio_err,"DSA verify failure\n");
          ERR_print_errors(bio_err);
LAB_0002f24e:
          dVar42 = (double)app_tminterval(1,usertime);
          pcVar33 = local_27fc;
          if (*(int *)(pdVar22 + 0x97) != 0) {
            pcVar33 = "+R4:%ld:%d:%.2f\n";
          }
          BIO_printf(bio_err,pcVar33,iVar7,uVar21,dVar42);
          *(double *)(PTR_dsa_results_0002f754 + iVar6 * 0x10 + 8) =
               dVar42 / (double)(longlong)iVar7;
        }
        if (local_2818 != (char *)0x1) goto LAB_0002f128;
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
    if (*(int *)(pdVar22 + 0xd6) != 0) {
      RAND_cleanup();
    }
    iVar6 = RAND_status();
    if (iVar6 != 1) {
      RAND_seed(PTR_rnd_seed_0002f74c,0x40);
      *(undefined4 *)(pdVar22 + 0xd6) = 1;
    }
    iVar6 = 0;
    local_2800 = "%ld %d bit ECDSA verify in %.2fs\n";
    do {
      iVar7 = iVar6;
      if (local_26c8[iVar6] != 0) {
        iVar9 = iVar6 * 4;
        pEVar10 = EC_KEY_new_by_curve_name(*(int *)(test_curves_20465 + iVar9));
        local_2788[iVar6] = pEVar10;
        if (pEVar10 == (EC_KEY *)0x0) {
          BIO_printf(bio_err,"ECDSA failure.\n");
          ERR_print_errors(bio_err);
        }
        else {
          EC_KEY_precompute_mult(pEVar10,(BN_CTX *)0x0);
          EC_KEY_generate_key(pEVar10);
          iVar11 = ECDSA_sign(0,data,0x14,auStack_740,(uint *)&local_27e4,pEVar10);
          if (iVar11 == 0) {
            local_2818 = (char *)0x1;
            BIO_printf(bio_err,"ECDSA sign failure.  No ECDSA sign will be done.\n");
            ERR_print_errors(bio_err);
          }
          else {
            uVar21 = *(undefined4 *)(test_curves_bits_20467 + iVar9);
            if (*(int *)(pdVar22 + 0x97) == 0) {
              BIO_printf(bio_err,"Doing %d bit %s %s\'s for %ds: ",uVar21,"sign","ecdsa");
              BIO_ctrl(bio_err,0xb,0,(void *)0x0);
              alarm(10);
              app_tminterval(0,usertime);
            }
            else {
              BIO_printf(bio_err,"+DTP:%d:%s:%s:%d\n",uVar21,"sign","ecdsa");
              BIO_ctrl(bio_err,0xb,0,(void *)0x0);
              alarm(10);
              app_tminterval(0,usertime);
            }
            run = 1;
            local_2818 = (char *)0x0;
            while (iVar11 = ECDSA_sign(0,data,0x14,auStack_740,(uint *)&local_27e4,pEVar10),
                  iVar11 != 0) {
              local_2818 = (char *)((int)local_2818 + 1);
              if ((*(int *)pdVar22 == 0) || (local_2818 == (char *)0x7fffffff)) goto LAB_0002f698;
            }
            local_2818 = (char *)0x1;
            BIO_printf(bio_err,"ECDSA sign failure\n");
            ERR_print_errors(bio_err);
LAB_0002f698:
            puVar5 = PTR_ecdsa_results_0002f758;
            dVar42 = (double)app_tminterval(1,usertime);
            pcVar33 = "%ld %d bit ECDSA signs in %.2fs \n";
            if (*(int *)(pdVar22 + 0x97) != 0) {
              pcVar33 = "+R5:%ld:%d:%.2f\n";
            }
            BIO_printf(bio_err,pcVar33,local_2818,uVar21,dVar42);
            *(double *)(puVar5 + iVar6 * 0x10) = dVar42 / (double)(longlong)(int)local_2818;
          }
          iVar11 = ECDSA_verify(0,data,0x14,auStack_740,(int)local_27e4,pEVar10);
          if (iVar11 == 1) {
            uVar21 = *(undefined4 *)(test_curves_bits_20467 + iVar9);
            if (*(int *)(pdVar22 + 0x97) == 0) {
              BIO_printf(bio_err,"Doing %d bit %s %s\'s for %ds: ",uVar21,"verify","ecdsa");
              BIO_ctrl(bio_err,0xb,0,(void *)0x0);
              alarm(10);
              app_tminterval(0,usertime);
            }
            else {
              BIO_printf(bio_err,"+DTP:%d:%s:%s:%d\n",uVar21,"verify","ecdsa");
              BIO_ctrl(bio_err,0xb,0,(void *)0x0);
              alarm(10);
              app_tminterval(0,usertime);
            }
            run = 1;
            iVar9 = 0;
            while (iVar11 = ECDSA_verify(0,data,0x14,auStack_740,(int)local_27e4,pEVar10),
                  iVar11 == 1) {
              iVar9 = iVar9 + 1;
              if ((*(int *)pdVar22 == 0) || (iVar9 == 0x7fffffff)) goto LAB_000306aa;
            }
            iVar9 = 1;
            BIO_printf(bio_err,"ECDSA verify failure\n");
            ERR_print_errors(bio_err);
LAB_000306aa:
            puVar5 = PTR_ecdsa_results_000307d4;
            dVar42 = (double)app_tminterval(1,usertime);
            pcVar33 = local_2800;
            if (*(int *)(pdVar22 + 0x97) != 0) {
              pcVar33 = "+R6:%ld:%d:%.2f\n";
            }
            BIO_printf(bio_err,pcVar33,iVar9,uVar21,dVar42);
            *(double *)(puVar5 + iVar6 * 0x10 + 8) = dVar42 / (double)(longlong)iVar9;
          }
          else {
            BIO_printf(bio_err,"ECDSA verify failure.  No ECDSA verify will be done.\n");
            ERR_print_errors(bio_err);
            local_26c8[iVar6] = 0;
          }
          if (local_2818 == (char *)0x1) {
            if (iVar6 + 1 == 0x10) break;
            iVar7 = iVar6 + 2;
            local_26c8[iVar6 + 1] = 0;
            if (iVar7 < 0x10) {
              iVar9 = iVar6 + 3;
              local_26c8[iVar7] = 0;
              iVar7 = iVar9;
              if (iVar9 < 0x10) {
                iVar7 = iVar6 + 4;
                local_26c8[iVar9] = 0;
                if (iVar7 < 0x10) {
                  iVar9 = iVar6 + 5;
                  local_26c8[iVar7] = 0;
                  iVar7 = iVar9;
                  if (iVar9 < 0x10) {
                    iVar7 = iVar6 + 6;
                    local_26c8[iVar9] = 0;
                    if (iVar7 < 0x10) {
                      iVar9 = iVar6 + 7;
                      local_26c8[iVar7] = 0;
                      iVar7 = iVar9;
                      if (iVar9 < 0x10) {
                        iVar7 = iVar6 + 8;
                        local_26c8[iVar9] = 0;
                        if (iVar7 < 0x10) {
                          iVar9 = iVar6 + 9;
                          local_26c8[iVar7] = 0;
                          iVar7 = iVar9;
                          if (iVar9 < 0x10) {
                            iVar7 = iVar6 + 10;
                            local_26c8[iVar9] = 0;
                            if (iVar7 < 0x10) {
                              iVar9 = iVar6 + 0xb;
                              local_26c8[iVar7] = 0;
                              iVar7 = iVar9;
                              if (iVar9 < 0x10) {
                                iVar7 = iVar6 + 0xc;
                                local_26c8[iVar9] = 0;
                                if (iVar7 < 0x10) {
                                  iVar9 = iVar6 + 0xd;
                                  local_26c8[iVar7] = 0;
                                  iVar7 = iVar9;
                                  if (iVar9 < 0x10) {
                                    iVar7 = iVar6 + 0xe;
                                    local_26c8[iVar9] = 0;
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
    if (*(int *)(pdVar22 + 0xd6) != 0) {
      RAND_cleanup();
    }
    iVar6 = RAND_status();
    if (iVar6 != 1) {
      RAND_seed(PTR_rnd_seed_0002f74c,0x40);
      *(undefined4 *)(pdVar22 + 0xd6) = 1;
    }
    puVar5 = PTR_ecdh_results_0002f750;
    iVar6 = 0;
    local_2804 = "%ld %d-bit ECDH ops in %.2fs\n";
    do {
      iVar7 = iVar6;
      if (local_2688[iVar6] != 0) {
        iVar9 = *(int *)(test_curves_20465 + iVar6 * 4);
        pEVar10 = EC_KEY_new_by_curve_name(iVar9);
        local_2748[iVar6] = pEVar10;
        key = EC_KEY_new_by_curve_name(iVar9);
        local_2708[iVar6] = key;
        if ((pEVar10 == (EC_KEY *)0x0) || (key == (EC_KEY *)0x0)) {
          BIO_printf(bio_err,"ECDH failure.\n");
          ERR_print_errors(bio_err);
        }
        else {
          iVar9 = EC_KEY_generate_key(pEVar10);
          if ((iVar9 == 0) || (iVar9 = EC_KEY_generate_key(key), iVar9 == 0)) {
            BIO_printf(bio_err,"ECDH key generation failure.\n");
            ERR_print_errors(bio_err);
          }
          else {
            group = EC_KEY_get0_group(pEVar10);
            iVar9 = EC_GROUP_get_degree(group);
            if (iVar9 < 0xc1) {
              sVar29 = 0x14;
              local_2818 = (char *)(KDF1_SHA1 + 1);
            }
            else {
              sVar29 = iVar9 + 7 >> 3;
              local_2818 = (char *)0x0;
            }
            pEVar13 = EC_KEY_get0_public_key(key);
            iVar9 = ECDH_compute_key(local_640,sVar29,pEVar13,pEVar10,(KDF *)local_2818);
            pEVar13 = EC_KEY_get0_public_key(pEVar10);
            iVar11 = ECDH_compute_key(local_540,sVar29,pEVar13,key,(KDF *)local_2818);
            uVar14 = count_leading_zeroes(iVar9 - iVar11);
            uVar14 = uVar14 >> 5;
            if (iVar9 < 1) {
              uVar18 = 0;
            }
            else {
              uVar18 = uVar14 & 1;
            }
            if (uVar18 != 0) {
              iVar11 = 0;
              do {
                pbVar30 = local_640 + iVar11;
                pbVar31 = local_540 + iVar11;
                iVar11 = iVar11 + 1;
                uVar14 = count_leading_zeroes((uint)*pbVar30 - (uint)*pbVar31);
                uVar14 = uVar14 >> 5;
                if (iVar11 < iVar9) {
                  uVar18 = uVar14 & 1;
                }
                else {
                  uVar18 = 0;
                }
              } while (uVar18 != 0);
            }
            if (uVar14 == 0) {
              BIO_printf(bio_err,"ECDH computations don\'t match.\n");
              ERR_print_errors(bio_err);
            }
            iVar9 = *(int *)(pdVar22 + 0x97);
            uVar21 = *(undefined4 *)(test_curves_bits_20467 + iVar6 * 4);
            if (iVar9 == 0) {
              BIO_printf(bio_err,"Doing %d bit %s %s\'s for %ds: ",uVar21,"",&DAT_00131acc);
              BIO_ctrl(bio_err,0xb,0,(void *)0x0);
              alarm(10);
            }
            else {
              BIO_printf(bio_err,"+DTP:%d:%s:%s:%d\n",uVar21,"",&DAT_00131acc);
              BIO_ctrl(bio_err,0xb,0,(void *)0x0);
              alarm(10);
              iVar9 = 0;
            }
            iVar11 = 0;
            app_tminterval(iVar9,usertime);
            run = 1;
            do {
              iVar11 = iVar11 + 1;
              pEVar13 = EC_KEY_get0_public_key(key);
              ECDH_compute_key(local_640,sVar29,pEVar13,pEVar10,(KDF *)local_2818);
              if (*(int *)pdVar22 == 0) break;
            } while (iVar11 != 0x7fffffff);
            dVar42 = (double)app_tminterval(1,usertime);
            pcVar33 = local_2804;
            if (*(int *)(pdVar22 + 0x97) != 0) {
              pcVar33 = "+R7:%ld:%d:%.2f\n";
            }
            BIO_printf(bio_err,pcVar33,iVar11,uVar21,dVar42);
            *(double *)(puVar5 + iVar6 * 8) = dVar42 / (double)(longlong)iVar11;
            if (iVar11 != 1) goto LAB_0002f75c;
          }
        }
        if (iVar6 + 1 == 0x10) break;
        iVar7 = iVar6 + 2;
        local_2688[iVar6 + 1] = 0;
        if (iVar7 < 0x10) {
          iVar9 = iVar6 + 3;
          local_2688[iVar7] = 0;
          iVar7 = iVar9;
          if (iVar9 < 0x10) {
            iVar7 = iVar6 + 4;
            local_2688[iVar9] = 0;
            if (iVar7 < 0x10) {
              iVar9 = iVar6 + 5;
              local_2688[iVar7] = 0;
              iVar7 = iVar9;
              if (iVar9 < 0x10) {
                iVar7 = iVar6 + 6;
                local_2688[iVar9] = 0;
                if (iVar7 < 0x10) {
                  iVar9 = iVar6 + 7;
                  local_2688[iVar7] = 0;
                  iVar7 = iVar9;
                  if (iVar9 < 0x10) {
                    iVar7 = iVar6 + 8;
                    local_2688[iVar9] = 0;
                    if (iVar7 < 0x10) {
                      iVar9 = iVar6 + 9;
                      local_2688[iVar7] = 0;
                      iVar7 = iVar9;
                      if (iVar9 < 0x10) {
                        iVar7 = iVar6 + 10;
                        local_2688[iVar9] = 0;
                        if (iVar7 < 0x10) {
                          iVar9 = iVar6 + 0xb;
                          local_2688[iVar7] = 0;
                          iVar7 = iVar9;
                          if (iVar9 < 0x10) {
                            iVar7 = iVar6 + 0xc;
                            local_2688[iVar9] = 0;
                            if (iVar7 < 0x10) {
                              iVar9 = iVar6 + 0xd;
                              local_2688[iVar7] = 0;
                              iVar7 = iVar9;
                              if (iVar9 < 0x10) {
                                iVar7 = iVar6 + 0xe;
                                local_2688[iVar9] = 0;
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
LAB_0002f75c:
      iVar6 = iVar7 + 1;
    } while (iVar6 < 0x10);
    if (*(int *)(pdVar22 + 0xd6) != 0) {
      RAND_cleanup();
    }
  }
  else {
    __ptr = malloc(local_2810 << 2);
    local_2804 = (char *)((int)__ptr + -4);
    puVar38 = (uint *)local_2804;
    do {
      iVar7 = pipe((int *)&local_18f8);
      if (iVar7 == -1) {
        fwrite("pipe failure\n",1,0xd,stderr);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      fflush(stdout);
      fflush(stderr);
      _Var12 = fork();
      if (_Var12 == 0) {
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
        usertime = _Var12;
        free(__ptr);
        goto LAB_0002ca5e;
      }
      close(local_18f8.P[1]);
      pEVar24 = (EVP_MD *)((int)(int *)local_2800 + 1);
      puVar38 = puVar38 + 1;
      *puVar38 = local_18f8.P[0];
      __printf_chk(1,"Forked child %d\n",local_2800);
      puVar5 = PTR_results_0003129c;
      local_2800 = (char *)pEVar24;
    } while ((int)pEVar24 < local_2810);
    iVar6 = 0;
    do {
      local_2804 = (char *)((int)local_2804 + 4);
      pFVar15 = fdopen(*(uint *)local_2804,"r");
LAB_0003102c:
      local_27f0 = fgets(local_440,0x400,pFVar15);
      if (local_27f0 != (char *)0x0) {
        while( true ) {
          pcVar33 = strchr(local_440,10);
          if (pcVar33 != (char *)0x0) {
            *pcVar33 = '\0';
          }
          if (local_440[0] == '+') break;
          __fprintf_chk(stderr,1,"Don\'t understand line \'%s\' from child %d\n",local_440,iVar6);
          local_27f0 = fgets(local_440,0x400,pFVar15);
          if (local_27f0 == (char *)0x0) goto LAB_00031078;
        }
        __printf_chk(1,"Got: %s from %d\n",local_440,iVar6);
        iVar7 = strncmp(local_440,"+F:",3);
        if (iVar7 == 0) {
          pbVar30 = (byte *)(uint)local_43d;
          if (pbVar30 == (byte *)0x0) {
            pbVar31 = &local_43d;
          }
          else {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar31 = PTR_sep_21673_000312a0;
            bVar2 = (byte)sep_21673;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar31 = pbVar31 + 1;
              bVar2 = *pbVar31;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = &local_43d;
            pbVar31 = pbVar30;
            pbVar20 = pbVar30;
            if (*pcVar33 == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              pbVar20 = pbVar31;
              if (*pbVar31 == 0) goto LAB_000311a0;
            }
            pbVar31 = pbVar20 + 1;
            *pbVar20 = 0;
          }
LAB_000311a0:
          lVar16 = strtol((char *)pbVar30,(char **)0x0,10);
          pbVar30 = (byte *)(uint)*pbVar31;
          if (pbVar30 != (byte *)0x0) {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar20 = PTR_sep_21673_000312a0;
            bVar2 = (byte)sep_21673;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar20 = pbVar20 + 1;
              bVar2 = *pbVar20;
            }
            pbVar20 = pbVar31;
            if (local_540[(int)pbVar30] == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
                pbVar30 = (byte *)(uint)*pbVar31;
              } while (local_540[(int)pbVar30] == '\0');
              pbVar20 = pbVar31;
              if (pbVar30 == (byte *)0x0) goto LAB_00031204;
            }
            pbVar31 = pbVar20 + 1;
            *pbVar20 = 0;
            pbVar30 = (byte *)(uint)pbVar20[1];
          }
LAB_00031204:
          iVar7 = 5;
          pdVar22 = (double *)(puVar5 + lVar16 * 0x28);
          do {
            dVar42 = *pdVar22;
            pbVar20 = pbVar31;
            if (pbVar30 != (byte *)0x0) {
              memset(local_540,0,0x100);
              local_540[0] = 1;
              pbVar19 = PTR_sep_21673_000312a0;
              bVar2 = (byte)sep_21673;
              while (bVar2 != 0) {
                local_540[bVar2] = 1;
                pbVar19 = pbVar19 + 1;
                bVar2 = *pbVar19;
              }
              pbVar19 = pbVar31;
              if (local_540[(int)pbVar30] == '\0') {
                do {
                  pbVar20 = pbVar20 + 1;
                } while (local_540[*pbVar20] == '\0');
                pbVar30 = pbVar31;
                pbVar19 = pbVar20;
                if (*pbVar20 == 0) goto LAB_0003126c;
              }
              pbVar20 = pbVar19 + 1;
              *pbVar19 = 0;
              pbVar30 = pbVar31;
            }
LAB_0003126c:
            dVar43 = strtod((char *)pbVar30,(char **)0x0);
            iVar7 = iVar7 + -1;
            *pdVar22 = dVar42 + dVar43;
            if (iVar7 == 0) goto LAB_0003102c;
            pbVar30 = (byte *)(uint)*pbVar20;
            pbVar31 = pbVar20;
            pdVar22 = pdVar22 + 1;
          } while( true );
        }
        iVar7 = strncmp(local_440,"+F2:",4);
        if (iVar7 == 0) {
          pbVar30 = (byte *)(uint)local_43c[0];
          if (pbVar30 == (byte *)0x0) {
            pbVar31 = local_43c;
          }
          else {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar31 = PTR_sep_21673_000315c0;
            bVar2 = (byte)sep_21673;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar31 = pbVar31 + 1;
              bVar2 = *pbVar31;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = local_43c;
            pbVar31 = pbVar30;
            pbVar20 = pbVar30;
            if (*pcVar33 == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              pbVar20 = pbVar31;
              if (*pbVar31 == 0) goto LAB_000312f8;
            }
            pbVar31 = pbVar20 + 1;
            *pbVar20 = 0;
          }
LAB_000312f8:
          lVar16 = strtol((char *)pbVar30,(char **)0x0,10);
          pbVar30 = (byte *)(uint)*pbVar31;
          if (pbVar30 != (byte *)0x0) {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar20 = PTR_sep_21673_000315c0;
            bVar2 = (byte)sep_21673;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar20 = pbVar20 + 1;
              bVar2 = *pbVar20;
            }
            if (local_540[(int)pbVar30] == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              if (*pbVar31 != 0) goto LAB_0003155c;
            }
            else {
LAB_0003155c:
              pbVar30 = pbVar31 + 1;
              *pbVar31 = 0;
              bVar2 = pbVar31[1];
              pbVar31 = pbVar30;
              if (bVar2 != 0) {
                memset(local_540,0,0x100);
                local_540[0] = 1;
                pbVar20 = PTR_sep_21673_000315c0;
                bVar3 = (byte)sep_21673;
                while (bVar3 != 0) {
                  local_540[bVar3] = 1;
                  pbVar20 = pbVar20 + 1;
                  bVar3 = *pbVar20;
                }
                pbVar20 = pbVar30;
                if (local_540[bVar2] == '\0') {
                  do {
                    pbVar31 = pbVar31 + 1;
                  } while (local_540[*pbVar31] == '\0');
                  pbVar20 = pbVar31;
                  if (*pbVar31 == 0) goto LAB_00031354;
                }
                pbVar31 = pbVar20 + 1;
                *pbVar20 = 0;
                goto LAB_00031354;
              }
            }
            pbVar30 = (byte *)0x0;
          }
LAB_00031354:
          dVar42 = strtod((char *)pbVar30,(char **)0x0);
          if (iVar6 == 0) {
            iVar7 = lVar16 << 4;
            puVar35 = PTR_rsa_results_00031ca0;
          }
          else {
            iVar7 = lVar16 * 0x10;
            dVar42 = 1.0 / (1.0 / *(double *)(PTR_rsa_results_000315c4 + iVar7) + 1.0 / dVar42);
            puVar35 = PTR_rsa_results_000315c4;
          }
          pbVar30 = (byte *)(uint)*pbVar31;
          *(double *)(puVar35 + iVar7) = dVar42;
          if (pbVar30 == (byte *)0x0) goto LAB_000313d4;
          memset(local_540,0,0x100);
          local_540[0] = 1;
          pbVar20 = PTR_sep_21673_000315c0;
          bVar2 = (byte)sep_21673;
          while (bVar2 != 0) {
            local_540[bVar2] = 1;
            pbVar20 = pbVar20 + 1;
            bVar2 = *pbVar20;
          }
          pcVar33 = local_540 + (int)pbVar30;
          pbVar30 = pbVar31;
          if (*pcVar33 == '\0') {
            do {
              pbVar31 = pbVar31 + 1;
              uVar14 = (uint)*pbVar31;
            } while (local_540[uVar14] == '\0');
            goto LAB_000313d0;
          }
LAB_00031404:
          local_540[0] = 1;
          *pbVar31 = 0;
        }
        else {
          iVar7 = strncmp(local_440,"+F3:",4);
          if (iVar7 == 0) {
            pbVar30 = (byte *)(uint)local_43c[0];
            if (pbVar30 == (byte *)0x0) {
              pbVar31 = local_43c;
            }
            else {
              memset(local_540,0,0x100);
              local_540[0] = 1;
              pbVar31 = PTR_sep_21673_000315c0;
              bVar2 = (byte)sep_21673;
              while (bVar2 != 0) {
                local_540[bVar2] = 1;
                pbVar31 = pbVar31 + 1;
                bVar2 = *pbVar31;
              }
              pcVar33 = local_540 + (int)pbVar30;
              pbVar30 = local_43c;
              pbVar31 = pbVar30;
              pbVar20 = pbVar30;
              if (*pcVar33 == '\0') {
                do {
                  pbVar31 = pbVar31 + 1;
                } while (local_540[*pbVar31] == '\0');
                pbVar20 = pbVar31;
                if (*pbVar31 == 0) goto LAB_0003147c;
              }
              pbVar31 = pbVar20 + 1;
              *pbVar20 = 0;
            }
LAB_0003147c:
            lVar16 = strtol((char *)pbVar30,(char **)0x0,10);
            pbVar30 = (byte *)(uint)*pbVar31;
            if (pbVar30 != (byte *)0x0) {
              memset(local_540,0,0x100);
              local_540[0] = 1;
              pbVar20 = PTR_sep_21673_000315c0;
              bVar2 = (byte)sep_21673;
              while (bVar2 != 0) {
                local_540[bVar2] = 1;
                pbVar20 = pbVar20 + 1;
                bVar2 = *pbVar20;
              }
              if (local_540[(int)pbVar30] == '\0') {
                do {
                  pbVar31 = pbVar31 + 1;
                } while (local_540[*pbVar31] == '\0');
                if (*pbVar31 != 0) goto LAB_000317fe;
              }
              else {
LAB_000317fe:
                pbVar30 = pbVar31 + 1;
                *pbVar31 = 0;
                bVar2 = pbVar31[1];
                pbVar31 = pbVar30;
                if (bVar2 != 0) {
                  memset(local_540,0,0x100);
                  local_540[0] = 1;
                  pbVar20 = PTR_sep_21673_000318d8;
                  bVar3 = (byte)sep_21673;
                  while (bVar3 != 0) {
                    local_540[bVar3] = 1;
                    pbVar20 = pbVar20 + 1;
                    bVar3 = *pbVar20;
                  }
                  pbVar20 = pbVar30;
                  if (local_540[bVar2] == '\0') {
                    do {
                      pbVar31 = pbVar31 + 1;
                    } while (local_540[*pbVar31] == '\0');
                    pbVar20 = pbVar31;
                    if (*pbVar31 == 0) goto LAB_000314d8;
                  }
                  pbVar31 = pbVar20 + 1;
                  *pbVar20 = 0;
                  goto LAB_000314d8;
                }
              }
              pbVar30 = (byte *)0x0;
            }
LAB_000314d8:
            dVar42 = strtod((char *)pbVar30,(char **)0x0);
            if (iVar6 == 0) {
              iVar7 = lVar16 << 4;
              puVar35 = PTR_dsa_results_00031ca4;
            }
            else {
              iVar7 = lVar16 * 0x10;
              dVar42 = 1.0 / (1.0 / *(double *)(PTR_dsa_results_000315c8 + iVar7) + 1.0 / dVar42);
              puVar35 = PTR_dsa_results_000315c8;
            }
            pbVar30 = (byte *)(uint)*pbVar31;
            *(double *)(puVar35 + iVar7) = dVar42;
            if (pbVar30 == (byte *)0x0) goto LAB_000313d4;
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar20 = PTR_sep_21673_000315c0;
            bVar2 = (byte)sep_21673;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar20 = pbVar20 + 1;
              bVar2 = *pbVar20;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = pbVar31;
            if (*pcVar33 == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
                uVar14 = (uint)*pbVar31;
              } while (local_540[uVar14] == '\0');
              goto LAB_000313d0;
            }
            goto LAB_00031404;
          }
          iVar7 = strncmp(local_440,"+F4:",4);
          if (iVar7 != 0) {
            iVar7 = strncmp(local_440,"+F5:",4);
            if (iVar7 == 0) {
              pbVar30 = (byte *)(uint)local_43c[0];
              if (pbVar30 == (byte *)0x0) {
                pbVar31 = local_43c;
              }
              else {
                memset(local_540,0,0x100);
                local_540[0] = 1;
                pbVar31 = PTR_sep_21673_000318d8;
                bVar2 = (byte)sep_21673;
                while (bVar2 != 0) {
                  local_540[bVar2] = 1;
                  pbVar31 = pbVar31 + 1;
                  bVar2 = *pbVar31;
                }
                pcVar33 = local_540 + (int)pbVar30;
                pbVar30 = local_43c;
                pbVar31 = pbVar30;
                pbVar20 = pbVar30;
                if (*pcVar33 == '\0') {
                  do {
                    pbVar31 = pbVar31 + 1;
                  } while (local_540[*pbVar31] == '\0');
                  pbVar20 = pbVar31;
                  if (*pbVar31 == 0) goto LAB_00031760;
                }
                pbVar31 = pbVar20 + 1;
                *pbVar20 = 0;
              }
LAB_00031760:
              lVar16 = strtol((char *)pbVar30,(char **)0x0,10);
              pbVar30 = (byte *)(uint)*pbVar31;
              if (pbVar30 != (byte *)0x0) {
                memset(local_540,0,0x100);
                local_540[0] = 1;
                pbVar20 = PTR_sep_21673_000318d8;
                bVar2 = (byte)sep_21673;
                while (bVar2 != 0) {
                  local_540[bVar2] = 1;
                  pbVar20 = pbVar20 + 1;
                  bVar2 = *pbVar20;
                }
                if (local_540[(int)pbVar30] == '\0') {
                  do {
                    pbVar31 = pbVar31 + 1;
                  } while (local_540[*pbVar31] == '\0');
                  if (*pbVar31 != 0) goto LAB_0003197a;
                }
                else {
LAB_0003197a:
                  pbVar30 = pbVar31 + 1;
                  *pbVar31 = 0;
                  bVar2 = pbVar31[1];
                  if (bVar2 != 0) {
                    memset(local_540,0,0x100);
                    local_540[0] = 1;
                    pbVar31 = PTR_sep_21673_00031c98;
                    bVar3 = (byte)sep_21673;
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
                      if (*pbVar31 == 0) goto LAB_000317b6;
                    }
                    *pbVar31 = 0;
                    goto LAB_000317b6;
                  }
                }
                pbVar30 = (byte *)0x0;
              }
LAB_000317b6:
              dVar42 = strtod((char *)pbVar30,(char **)0x0);
              if (iVar6 == 0) {
                *(double *)(puVar5 + lVar16 * 8 + 0x628) = dVar42;
              }
              else {
                *(double *)(puVar5 + lVar16 * 8 + 0x628) =
                     1.0 / (1.0 / *(double *)(puVar5 + lVar16 * 8 + 0x628) + 1.0 / dVar42);
              }
            }
            else {
              iVar7 = strncmp(local_440,"+H:",3);
              if (iVar7 != 0) {
                __fprintf_chk(stderr,1,"Unknown type \'%s\' from child %d\n",local_440,iVar6);
              }
            }
            goto LAB_0003102c;
          }
          pbVar30 = (byte *)(uint)local_43c[0];
          if (pbVar30 == (byte *)0x0) {
            pbVar31 = local_43c;
          }
          else {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar31 = PTR_sep_21673_000318d8;
            bVar2 = (byte)sep_21673;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar31 = pbVar31 + 1;
              bVar2 = *pbVar31;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = local_43c;
            pbVar31 = pbVar30;
            pbVar20 = pbVar30;
            if (*pcVar33 == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              pbVar20 = pbVar31;
              if (*pbVar31 == 0) goto LAB_00031620;
            }
            pbVar31 = pbVar20 + 1;
            *pbVar20 = 0;
          }
LAB_00031620:
          lVar16 = strtol((char *)pbVar30,(char **)0x0,10);
          pbVar30 = (byte *)(uint)*pbVar31;
          if (pbVar30 != (byte *)0x0) {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar20 = PTR_sep_21673_000318d8;
            bVar2 = (byte)sep_21673;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar20 = pbVar20 + 1;
              bVar2 = *pbVar20;
            }
            if (local_540[(int)pbVar30] == '\0') {
              do {
                pbVar31 = pbVar31 + 1;
              } while (local_540[*pbVar31] == '\0');
              if (*pbVar31 != 0) goto LAB_00031870;
            }
            else {
LAB_00031870:
              pbVar30 = pbVar31 + 1;
              *pbVar31 = 0;
              bVar2 = pbVar31[1];
              pbVar31 = pbVar30;
              if (bVar2 != 0) {
                memset(local_540,0,0x100);
                local_540[0] = 1;
                pbVar20 = PTR_sep_21673_000318d8;
                bVar3 = (byte)sep_21673;
                while (bVar3 != 0) {
                  local_540[bVar3] = 1;
                  pbVar20 = pbVar20 + 1;
                  bVar3 = *pbVar20;
                }
                pbVar20 = pbVar30;
                if (local_540[bVar2] == '\0') {
                  do {
                    pbVar31 = pbVar31 + 1;
                  } while (local_540[*pbVar31] == '\0');
                  pbVar20 = pbVar31;
                  if (*pbVar31 == 0) goto LAB_0003167c;
                }
                pbVar31 = pbVar20 + 1;
                *pbVar20 = 0;
                goto LAB_0003167c;
              }
            }
            pbVar30 = (byte *)0x0;
          }
LAB_0003167c:
          dVar42 = strtod((char *)pbVar30,(char **)0x0);
          if (iVar6 == 0) {
            iVar7 = lVar16 << 4;
            puVar35 = PTR_ecdsa_results_00031c9c;
          }
          else {
            iVar7 = lVar16 * 0x10;
            dVar42 = 1.0 / (1.0 / *(double *)(PTR_ecdsa_results_000318dc + iVar7) + 1.0 / dVar42);
            puVar35 = PTR_ecdsa_results_000318dc;
          }
          pbVar30 = (byte *)(uint)*pbVar31;
          *(double *)(puVar35 + iVar7) = dVar42;
          if (pbVar30 != (byte *)0x0) {
            memset(local_540,0,0x100);
            local_540[0] = 1;
            pbVar20 = PTR_sep_21673_000318d8;
            bVar2 = (byte)sep_21673;
            while (bVar2 != 0) {
              local_540[bVar2] = 1;
              pbVar20 = pbVar20 + 1;
              bVar2 = *pbVar20;
            }
            pcVar33 = local_540 + (int)pbVar30;
            pbVar30 = pbVar31;
            if (*pcVar33 != '\0') goto LAB_00031404;
            do {
              pbVar31 = pbVar31 + 1;
              uVar14 = (uint)*pbVar31;
            } while (local_540[uVar14] == '\0');
LAB_000313d0:
            local_540[0] = 1;
            if (uVar14 != 0) goto LAB_00031404;
          }
        }
LAB_000313d4:
        dVar42 = strtod((char *)pbVar30,(char **)0x0);
        if (iVar6 == 0) {
          *(double *)(puVar35 + iVar7 + 8) = dVar42;
        }
        else {
          *(double *)(puVar35 + iVar7 + 8) =
               1.0 / (1.0 / *(double *)(puVar35 + iVar7 + 8) + 1.0 / dVar42);
        }
        goto LAB_0003102c;
      }
LAB_00031078:
      fclose(pFVar15);
      iVar6 = iVar6 + 1;
    } while (iVar6 < local_2810);
    free(__ptr);
    pdVar22 = (double *)&run;
  }
  pFVar15 = stdout;
  if (*(int *)(pdVar22 + 0x97) == 0) {
    pcVar33 = SSLeay_version(0);
    __fprintf_chk(pFVar15,1,"%s\n",pcVar33);
    pFVar15 = stdout;
    pcVar33 = SSLeay_version(3);
    __fprintf_chk(pFVar15,1,"%s\n",pcVar33);
    __printf_chk(1,"options:");
    pcVar33 = BN_options();
    __printf_chk(1,&DAT_00132278,pcVar33);
    pcVar33 = RC4_options();
    __printf_chk(1,&DAT_00132278,pcVar33);
    pcVar33 = DES_options();
    __printf_chk(1,&DAT_00132278,pcVar33);
    pcVar33 = AES_options();
    __printf_chk(1,&DAT_00132278,pcVar33);
    pcVar33 = idea_options();
    __printf_chk(1,&DAT_00132278,pcVar33);
    pcVar33 = BF_options();
    __printf_chk(1,&DAT_00132278,pcVar33);
    pFVar15 = stdout;
    pcVar33 = SSLeay_version(2);
    __fprintf_chk(pFVar15,1,&DAT_0013227c,pcVar33);
  }
  if (local_27f0 != (char *)0x0) {
    if (*(int *)(pdVar22 + 0x97) == 0) {
      fwrite("The \'numbers\' are in 1000s of bytes per second processed.\n",1,0x3a,stdout);
      fwrite("type        ",1,0xc,stdout);
    }
    else {
      fwrite(&DAT_00132284,1,2,stdout);
    }
    puVar37 = DAT_0002fcc4 + 5;
    puVar39 = DAT_0002fcc4;
    do {
      puVar39 = puVar39 + 1;
      pcVar33 = "%7d bytes";
      if (*(int *)(pdVar22 + 0x97) != 0) {
        pcVar33 = ":%d";
      }
      __fprintf_chk(stdout,1,pcVar33,*puVar39);
    } while (puVar39 != puVar37);
    fputc(10,stdout);
  }
  dVar42 = DAT_0002fc98;
  iVar6 = 0;
  local_2824 = " %11.2f ";
  iVar7 = 0;
  pdVar32 = (double *)PTR_results_0002fca8;
  do {
    if (*(int *)((int)&local_2648 + iVar6) != 0) {
      if (*(int *)(pdVar22 + 0x97) == 0) {
        __fprintf_chk(stdout,1,"%-13s",*(undefined4 *)(PTR_names_00030054 + iVar6));
      }
      else {
        __fprintf_chk(stdout,1,"+F:%d:%s",iVar7,*(undefined4 *)(PTR_names_0002fcac + iVar6));
      }
      iVar9 = 5;
      pdVar23 = pdVar32;
      do {
        dVar43 = *pdVar23;
        pdVar23 = pdVar23 + 1;
        if (dVar43 < dVar42) {
          pcVar33 = local_2824;
          if (*(int *)(pdVar22 + 0x97) != 0) {
            pcVar33 = ":%.2f";
          }
LAB_0002f9e8:
          __fprintf_chk(stdout,1,pcVar33);
        }
        else {
          if (*(int *)(pdVar22 + 0x97) != 0) {
            pcVar33 = ":%.2f";
            goto LAB_0002f9e8;
          }
          __fprintf_chk(stdout,1," %11.2fk");
        }
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      fputc(10,stdout);
    }
    puVar5 = PTR_rsa_bits_20459_0002fcc8;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 1;
    pdVar32 = pdVar32 + 5;
  } while (iVar6 != 0x78);
  iVar7 = 0;
  iVar9 = 0;
  iVar6 = 1;
  pdVar32 = DAT_0002fcb0;
  do {
    if (*(int *)((int)local_27b8 + iVar7) != 0) {
      if (iVar6 == 0) {
LAB_0002fd12:
        iVar6 = *(int *)(pdVar22 + 0x97);
        if (iVar6 == 0) {
          __fprintf_chk(stdout,1,"rsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",
                        *(undefined4 *)(puVar5 + iVar7),pdVar32[-1],*pdVar32,1.0 / pdVar32[-1],
                        1.0 / *pdVar32);
          goto LAB_0002fa78;
        }
        iVar6 = 0;
      }
      else if (*(int *)(pdVar22 + 0x97) == 0) {
        __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_00131dd0);
        goto LAB_0002fd12;
      }
      __fprintf_chk(stdout,1,"+F2:%u:%u:%f:%f\n",iVar9,*(undefined4 *)(puVar5 + iVar7));
    }
LAB_0002fa78:
    puVar35 = PTR_dsa_bits_20464_0002fccc;
    iVar7 = iVar7 + 4;
    iVar9 = iVar9 + 1;
    pdVar32 = pdVar32 + 2;
  } while (iVar7 != 0x10);
  iVar7 = 0;
  iVar9 = 0;
  iVar6 = 1;
  pdVar32 = DAT_0002fcb4;
  do {
    if (*(int *)((int)local_27d4 + iVar7) != 0) {
      if (iVar6 == 0) {
LAB_0002fdaa:
        iVar6 = *(int *)(pdVar22 + 0x97);
        iVar11 = 0;
        if (iVar6 == 0) {
          __fprintf_chk(stdout,1,"dsa %4u bits %8.6fs %8.6fs %8.1f %8.1f\n",
                        *(undefined4 *)(puVar35 + iVar7),pdVar32[-1],*pdVar32,1.0 / pdVar32[-1],
                        1.0 / *pdVar32);
          goto LAB_0002fae0;
        }
      }
      else {
        iVar11 = 1;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          __printf_chk(1,"%18ssign    verify    sign/s verify/s\n",&DAT_00131dd0);
          goto LAB_0002fdaa;
        }
      }
      iVar6 = iVar11;
      __fprintf_chk(stdout,1,"+F3:%u:%u:%f:%f\n",iVar9,*(undefined4 *)(puVar35 + iVar7));
    }
LAB_0002fae0:
    puVar5 = PTR_test_curves_bits_20467_0002fcd0;
    iVar7 = iVar7 + 4;
    iVar9 = iVar9 + 1;
    pdVar32 = pdVar32 + 2;
  } while (iVar7 != 0xc);
  iVar7 = 0;
  iVar6 = 1;
  iVar9 = 0;
LAB_0002fb4c:
  do {
    if (*(int *)((int)local_26c8 + iVar7) != 0) {
      if (iVar6 == 0) {
LAB_0002fb58:
        iVar6 = *(int *)(pdVar22 + 0x97);
        if (iVar6 == 0) {
          puVar39 = (undefined4 *)(PTR_test_curves_names_20466_0002fcbc + iVar7);
          iVar9 = iVar9 + 1;
          puVar37 = (undefined4 *)(puVar5 + iVar7);
          iVar7 = iVar7 + 4;
          __fprintf_chk(stdout,1,"%4u bit ecdsa (%s) %8.4fs %8.4fs %8.1f %8.1f\n",*puVar37,*puVar39)
          ;
          if (iVar7 == 0x40) break;
          goto LAB_0002fb4c;
        }
        iVar6 = 0;
      }
      else {
        iVar6 = 1;
        if (*(int *)(pdVar22 + 0x97) == 0) {
          __printf_chk(1,"%30ssign    verify    sign/s verify/s\n",&DAT_00131dd0);
          goto LAB_0002fb58;
        }
      }
      __fprintf_chk(stdout,1,"+F4:%u:%u:%f:%f\n",iVar9,*(undefined4 *)(puVar5 + iVar7));
    }
    iVar7 = iVar7 + 4;
    iVar9 = iVar9 + 1;
  } while (iVar7 != 0x40);
  puVar5 = PTR_test_curves_bits_20467_0002fcd0;
  iVar6 = 0;
  iVar7 = 0;
  local_2828 = (double *)0x1;
LAB_0002fc14:
  do {
    if (*(int *)((int)local_2688 + iVar6) != 0) {
      if (local_2828 == (double *)0x0) {
LAB_0002fc22:
        local_2828 = *(double **)(pdVar22 + 0x97);
        if (local_2828 == (double *)0x0) {
          iVar7 = iVar7 + 1;
          puVar39 = (undefined4 *)(PTR_test_curves_names_20466_0002fcbc + iVar6);
          puVar37 = (undefined4 *)(puVar5 + iVar6);
          iVar6 = iVar6 + 4;
          __fprintf_chk(stdout,1,"%4u bit ecdh (%s) %8.4fs %8.1f\n",*puVar37,*puVar39);
          if (iVar6 == 0x40) break;
          goto LAB_0002fc14;
        }
        local_2828 = (double *)0x0;
      }
      else {
        if (*(int *)(pdVar22 + 0x97) == 0) {
          __printf_chk(1,"%30sop      op/s\n",&DAT_00131dd0);
          goto LAB_0002fc22;
        }
        local_2828 = (double *)0x1;
      }
      __fprintf_chk(stdout,1,"+F5:%u:%u:%f:%f\n",iVar7,*(undefined4 *)(puVar5 + iVar6));
    }
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 1;
  } while (iVar6 != 0x40);
  uVar21 = 0;
LAB_0002ee08:
  ERR_print_errors(bio_err);
  CRYPTO_free(data);
  CRYPTO_free(out);
  goto LAB_0002c856;
}

