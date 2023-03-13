
int dgst_main(int param_1,undefined4 *param_2)

{
  byte bVar1;
  char **ppcVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  void *ptr;
  int iVar7;
  BIO_METHOD *pBVar8;
  BIO *b;
  int iVar9;
  long lVar10;
  BIO *pBVar11;
  EVP_PKEY_ASN1_METHOD *ameth;
  int iVar12;
  _STACK *p_Var13;
  EVP_MD *pEVar14;
  _STACK *extraout_ECX;
  _STACK *extraout_EDX;
  void *pvVar15;
  _STACK *__s1;
  char **ppcVar16;
  _STACK *p_Var17;
  BIO *bp;
  byte *pbVar18;
  int in_GS_OFFSET;
  bool bVar19;
  bool bVar20;
  byte bVar21;
  char *pcVar22;
  _STACK *p_Var23;
  char *pcVar24;
  BIO *local_b0;
  undefined4 local_ac;
  _STACK *local_a8;
  _STACK *local_a4;
  char *local_9c;
  char *local_94;
  char *local_8c;
  char *local_88;
  uint local_84;
  char *local_80;
  char *local_78;
  char *local_74;
  ENGINE *local_6c;
  EVP_MD *local_68;
  undefined4 local_64;
  EVP_PKEY *local_58;
  void *local_54;
  EVP_MD_CTX *local_50;
  EVP_MD_CTX *local_4c;
  char local_48 [40];
  int local_20;
  
  bVar21 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_58 = (EVP_PKEY *)0x0;
  local_54 = (void *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  ptr = CRYPTO_malloc(0x2000,"dgst.c",0x87);
  if (ptr != (void *)0x0) {
    if (bio_err == (BIO *)0x0) {
      pBVar8 = BIO_s_file();
      bio_err = BIO_new(pBVar8);
      if (bio_err != (BIO *)0x0) {
        BIO_ctrl(bio_err,0x6a,0x10,stderr);
      }
    }
    iVar7 = load_config(bio_err,0);
    local_a4 = (_STACK *)0x0;
    local_a8 = (_STACK *)0x0;
    if (iVar7 != 0) {
      ppcVar16 = (char **)(param_2 + 1);
      p_Var23 = (_STACK *)&DAT_00000028;
      pcVar24 = local_48;
      program_name(*param_2,pcVar24,0x28);
      local_68 = EVP_get_digestbyname(local_48);
      param_1 = param_1 + -1;
      if (param_1 < 1) {
        bVar6 = false;
        local_78 = (char *)0x0;
        local_74 = (char *)0x0;
        local_80 = (char *)0x0;
        bVar3 = false;
        bVar5 = false;
        local_84 = 0xffffffff;
        local_9c = (char *)0x0;
        local_88 = (char *)0x0;
        local_8c = (char *)0x0;
        local_94 = (char *)0x0;
        local_64 = 3;
        bVar4 = false;
        local_ac = 0;
        local_6c = (ENGINE *)0x0;
      }
      else {
        __s1 = (_STACK *)param_2[1];
        bVar6 = false;
        local_78 = (char *)0x0;
        local_74 = (char *)0x0;
        local_80 = (char *)0x0;
        bVar3 = false;
        bVar5 = false;
        local_84 = 0xffffffff;
        local_9c = (char *)0x0;
        local_88 = (char *)0x0;
        local_8c = (char *)0x0;
        local_94 = (char *)0x0;
        local_64 = 3;
        bVar4 = false;
        local_ac = 0;
        local_6c = (ENGINE *)0x0;
        local_b0 = (BIO *)param_1;
        if (*(char *)&__s1->num == '-') {
          do {
            bVar1 = *(byte *)((int)&__s1->num + 1);
            iVar7 = (int)local_b0;
            ppcVar2 = ppcVar16;
            pEVar14 = local_68;
            if (bVar1 == 99) {
              bVar19 = false;
              bVar20 = *(char *)((int)&__s1->num + 2) == '\0';
              if (!bVar20) goto LAB_08051531;
              local_ac = 1;
            }
            else {
              bVar19 = bVar1 < 0x72;
              bVar20 = bVar1 == 0x72;
              if (bVar20) {
                bVar19 = false;
                bVar20 = *(char *)((int)&__s1->num + 2) == '\0';
                if (bVar20) {
                  local_ac = 2;
                  goto joined_r0x0805156a;
                }
              }
LAB_08051531:
              iVar9 = 6;
              p_Var13 = __s1;
              pbVar18 = (byte *)"-rand";
              do {
                if (iVar9 == 0) break;
                iVar9 = iVar9 + -1;
                bVar19 = *(byte *)&p_Var13->num < *pbVar18;
                bVar20 = *(byte *)&p_Var13->num == *pbVar18;
                p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                pbVar18 = pbVar18 + (uint)bVar21 * -2 + 1;
              } while (bVar20);
              bVar19 = (!bVar19 && !bVar20) == bVar19;
              if (bVar19) {
                local_b0 = (BIO *)((int)local_b0 + -1);
                if (local_b0 == (BIO *)0x0) goto LAB_08051597;
                local_9c = ppcVar16[1];
                ppcVar2 = ppcVar16 + 1;
                iVar7 = (int)local_b0;
              }
              else {
                iVar9 = 5;
                p_Var13 = __s1;
                pcVar22 = "-out";
                do {
                  if (iVar9 == 0) break;
                  iVar9 = iVar9 + -1;
                  bVar19 = *(char *)&p_Var13->num == *pcVar22;
                  p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                  pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                } while (bVar19);
                if (bVar19) {
                  local_b0 = (BIO *)((int)local_b0 + -1);
                  if (local_b0 == (BIO *)0x0) goto LAB_08051597;
                  local_94 = ppcVar16[1];
                  ppcVar2 = ppcVar16 + 1;
                  iVar7 = (int)local_b0;
                }
                else {
                  iVar9 = 6;
                  p_Var13 = __s1;
                  pcVar22 = "-sign";
                  do {
                    if (iVar9 == 0) break;
                    iVar9 = iVar9 + -1;
                    bVar19 = *(char *)&p_Var13->num == *pcVar22;
                    p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                    pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                  } while (bVar19);
                  if (bVar19) {
                    local_b0 = (BIO *)((int)local_b0 + -1);
                    if (local_b0 == (BIO *)0x0) goto LAB_08051597;
                    local_8c = ppcVar16[1];
                    ppcVar2 = ppcVar16 + 1;
                    iVar7 = (int)local_b0;
                  }
                  else {
                    iVar9 = 8;
                    p_Var13 = __s1;
                    pcVar22 = "-passin";
                    do {
                      if (iVar9 == 0) break;
                      iVar9 = iVar9 + -1;
                      bVar19 = *(char *)&p_Var13->num == *pcVar22;
                      p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                      pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                    } while (bVar19);
                    if (bVar19) {
                      local_b0 = (BIO *)((int)local_b0 + -1);
                      if (local_b0 == (BIO *)0x0) goto LAB_08051597;
                      local_80 = ppcVar16[1];
                      ppcVar2 = ppcVar16 + 1;
                      iVar7 = (int)local_b0;
                    }
                    else {
                      iVar9 = 8;
                      p_Var13 = __s1;
                      pcVar22 = "-verify";
                      do {
                        if (iVar9 == 0) break;
                        iVar9 = iVar9 + -1;
                        bVar19 = *(char *)&p_Var13->num == *pcVar22;
                        p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                        pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                      } while (bVar19);
                      if (bVar19) {
                        local_b0 = (BIO *)((int)local_b0 + -1);
                        if (local_b0 == (BIO *)0x0) goto LAB_08051597;
                        local_8c = ppcVar16[1];
                        bVar3 = true;
                        bVar5 = true;
                        ppcVar2 = ppcVar16 + 1;
                        iVar7 = (int)local_b0;
                      }
                      else {
                        iVar9 = 10;
                        p_Var13 = __s1;
                        pcVar22 = "-prverify";
                        do {
                          if (iVar9 == 0) break;
                          iVar9 = iVar9 + -1;
                          bVar19 = *(char *)&p_Var13->num == *pcVar22;
                          p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                          pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                        } while (bVar19);
                        if (bVar19) {
                          local_b0 = (BIO *)((int)local_b0 + -1);
                          if (local_b0 == (BIO *)0x0) goto LAB_08051597;
                          local_8c = ppcVar16[1];
                          bVar3 = true;
                          ppcVar2 = ppcVar16 + 1;
                          iVar7 = (int)local_b0;
                        }
                        else {
                          iVar9 = 0xb;
                          p_Var13 = __s1;
                          pcVar22 = "-signature";
                          do {
                            if (iVar9 == 0) break;
                            iVar9 = iVar9 + -1;
                            bVar19 = *(char *)&p_Var13->num == *pcVar22;
                            p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                            pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                          } while (bVar19);
                          if (bVar19) {
                            iVar7 = (int)local_b0 + -1;
                            if (iVar7 == 0) goto LAB_0805255f;
                            local_88 = ppcVar16[1];
                            ppcVar2 = ppcVar16 + 1;
                          }
                          else {
                            iVar9 = 9;
                            p_Var13 = __s1;
                            pcVar22 = "-keyform";
                            do {
                              if (iVar9 == 0) break;
                              iVar9 = iVar9 + -1;
                              bVar19 = *(char *)&p_Var13->num == *pcVar22;
                              p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                              pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                            } while (bVar19);
                            if (bVar19) {
                              iVar7 = (int)local_b0 + -1;
                              if (iVar7 == 0) goto LAB_0805255f;
                              local_64 = str2fmt(ppcVar16[1],pcVar24,p_Var23);
                              ppcVar2 = ppcVar16 + 1;
                            }
                            else {
                              iVar9 = 8;
                              p_Var13 = __s1;
                              pcVar22 = "-engine";
                              do {
                                if (iVar9 == 0) break;
                                iVar9 = iVar9 + -1;
                                bVar19 = *(char *)&p_Var13->num == *pcVar22;
                                p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                                pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                              } while (bVar19);
                              if (bVar19) {
                                iVar7 = (int)local_b0 + -1;
                                if (iVar7 == 0) goto LAB_0805255f;
                                p_Var23 = (_STACK *)0x0;
                                pcVar24 = ppcVar16[1];
                                local_6c = (ENGINE *)setup_engine(bio_err,pcVar24,0);
                                ppcVar2 = ppcVar16 + 1;
                              }
                              else {
                                iVar9 = 5;
                                p_Var13 = __s1;
                                pcVar22 = "-hex";
                                do {
                                  if (iVar9 == 0) break;
                                  iVar9 = iVar9 + -1;
                                  bVar19 = *(char *)&p_Var13->num == *pcVar22;
                                  p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                                  pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                                } while (bVar19);
                                if (bVar19) {
                                  local_84 = 0;
                                }
                                else {
                                  iVar9 = 8;
                                  p_Var13 = __s1;
                                  pcVar22 = "-binary";
                                  do {
                                    if (iVar9 == 0) break;
                                    iVar9 = iVar9 + -1;
                                    bVar19 = *(char *)&p_Var13->num == *pcVar22;
                                    p_Var13 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                                    pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                                  } while (bVar19);
                                  if (bVar19) {
                                    local_84 = 1;
                                  }
                                  else {
                                    bVar19 = bVar1 == 100;
                                    if ((bVar19) &&
                                       (bVar19 = *(char *)((int)&__s1->num + 2) == '\0', bVar19)) {
                                      bVar4 = true;
                                    }
                                    else {
                                      iVar9 = 0x12;
                                      p_Var13 = __s1;
                                      pcVar22 = "-fips-fingerprint";
                                      do {
                                        p_Var17 = p_Var13;
                                        if (iVar9 == 0) break;
                                        iVar9 = iVar9 + -1;
                                        p_Var17 = (_STACK *)((int)p_Var13 + (uint)bVar21 * -2 + 1);
                                        bVar19 = *(char *)&p_Var13->num == *pcVar22;
                                        p_Var13 = p_Var17;
                                        pcVar22 = pcVar22 + (uint)bVar21 * -2 + 1;
                                      } while (bVar19);
                                      if (bVar19) {
                                        local_74 = "etaonrishdlcupfm";
                                      }
                                      else {
                                        pcVar24 = "-non-fips-allow";
                                        iVar9 = strcmp((char *)__s1,"-non-fips-allow");
                                        if (iVar9 != 0) {
                                          pcVar24 = "-hmac";
                                          p_Var23 = extraout_ECX;
                                          iVar9 = strcmp((char *)__s1,"-hmac");
                                          if (iVar9 == 0) {
                                            iVar7 = (int)local_b0 + -1;
                                            if (iVar7 != 0) {
                                              local_74 = ppcVar16[1];
                                              ppcVar2 = ppcVar16 + 1;
                                              goto joined_r0x0805156a;
                                            }
                                          }
                                          else {
                                            pcVar24 = "-mac";
                                            p_Var13 = extraout_EDX;
                                            p_Var23 = (_STACK *)strcmp((char *)__s1,"-mac");
                                            if (p_Var23 == (_STACK *)0x0) {
                                              iVar7 = (int)local_b0 + -1;
                                              p_Var23 = p_Var13;
                                              if (iVar7 != 0) {
                                                local_78 = ppcVar16[1];
                                                ppcVar2 = ppcVar16 + 1;
                                                goto joined_r0x0805156a;
                                              }
                                            }
                                            else {
                                              p_Var13 = (_STACK *)strcmp((char *)__s1,"-sigopt");
                                              if (p_Var13 == (_STACK *)0x0) {
                                                iVar7 = (int)local_b0 + -1;
                                                if ((iVar7 != 0) &&
                                                   ((local_a8 != (_STACK *)0x0 ||
                                                    (p_Var13 = sk_new_null(), local_a8 = p_Var13,
                                                    p_Var13 != (_STACK *)0x0)))) {
                                                  pcVar24 = ppcVar16[1];
                                                  iVar9 = sk_push(local_a8,pcVar24);
                                                  p_Var23 = p_Var13;
joined_r0x080525cf:
                                                  ppcVar2 = ppcVar16 + 1;
                                                  iVar7 = (int)local_b0 + -1;
                                                  if (iVar9 != 0) goto joined_r0x0805156a;
                                                  local_b0 = (BIO *)((int)local_b0 + -1);
                                                  ppcVar16 = ppcVar16 + 1;
                                                  bVar19 = (bool)(local_88 == (char *)0x0 & bVar3);
                                                  goto LAB_080515a8;
                                                }
                                              }
                                              else {
                                                pcVar24 = "-macopt";
                                                p_Var17 = (_STACK *)strcmp((char *)__s1,"-macopt");
                                                if (p_Var17 == (_STACK *)0x0) {
                                                  iVar7 = (int)local_b0 + -1;
                                                  p_Var23 = p_Var13;
                                                  if ((iVar7 != 0) &&
                                                     ((local_a4 != (_STACK *)0x0 ||
                                                      (p_Var17 = sk_new_null(), p_Var23 = p_Var13,
                                                      local_a4 = p_Var17, p_Var17 != (_STACK *)0x0))
                                                     )) {
                                                    pcVar24 = ppcVar16[1];
                                                    iVar9 = sk_push(local_a4,pcVar24);
                                                    p_Var23 = p_Var17;
                                                    goto joined_r0x080525cf;
                                                  }
                                                }
                                                else {
                                                  pEVar14 = EVP_get_digestbyname
                                                                      ((char *)((int)&__s1->num + 1)
                                                                      );
                                                  p_Var23 = p_Var13;
                                                  if (pEVar14 != (EVP_MD *)0x0)
                                                  goto joined_r0x0805156a;
                                                }
                                              }
                                            }
                                          }
LAB_0805255f:
                                          local_b0 = (BIO *)iVar7;
                                          bVar19 = (bool)(local_88 == (char *)0x0 & bVar3);
                                          goto LAB_080515a8;
                                        }
                                        bVar6 = true;
                                        p_Var23 = p_Var17;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
joined_r0x0805156a:
            local_68 = pEVar14;
            local_b0 = (BIO *)(iVar7 + -1);
            ppcVar16 = ppcVar2 + 1;
            if ((local_b0 == (BIO *)0x0) ||
               (__s1 = (_STACK *)ppcVar2[1], *(char *)&__s1->num != '-')) goto LAB_08051597;
          } while( true );
        }
      }
      goto LAB_080515b0;
    }
    goto LAB_08051392;
  }
  BIO_printf(bio_err,"out of memory\n");
  if (local_54 == (void *)0x0) {
    iVar7 = 1;
    BIO_free_all((BIO *)0x0);
    EVP_PKEY_free(local_58);
    goto LAB_08051435;
  }
  local_a4 = (_STACK *)0x0;
  pvVar15 = (void *)0x0;
  iVar7 = 1;
  local_b0 = (BIO *)0x0;
  local_a8 = (_STACK *)0x0;
  bp = (BIO *)0x0;
LAB_080513c8:
  CRYPTO_free(local_54);
  goto LAB_080513d4;
LAB_08051597:
  bVar19 = (bool)(local_88 == (char *)0x0 & bVar3);
LAB_080515a8:
  param_1 = (int)local_b0;
  if (bVar19) {
    BIO_printf(bio_err,"No signature to verify: use the -signature option\n",p_Var23);
LAB_08051392:
    pvVar15 = (void *)0x0;
    iVar7 = 1;
    OPENSSL_cleanse(ptr,0x2000);
    bp = (BIO *)0x0;
    CRYPTO_free(ptr);
    local_b0 = (BIO *)0x0;
  }
  else {
LAB_080515b0:
    if ((0 < param_1) && (**ppcVar16 == '-')) {
      BIO_printf(bio_err,"unknown option \'%s\'\n",*ppcVar16);
      BIO_printf(bio_err,"options are\n");
      BIO_printf(bio_err,"-c              to output the digest with separating colons\n");
      BIO_printf(bio_err,"-r              to output the digest in coreutils format\n");
      BIO_printf(bio_err,"-d              to output debug info\n");
      BIO_printf(bio_err,"-hex            output as hex dump\n");
      BIO_printf(bio_err,"-binary         output in binary form\n");
      BIO_printf(bio_err,"-hmac arg       set the HMAC key to arg\n");
      BIO_printf(bio_err,"-non-fips-allow allow use of non FIPS digest\n");
      BIO_printf(bio_err,"-sign   file    sign digest using private key in file\n");
      BIO_printf(bio_err,"-verify file    verify a signature using public key in file\n");
      BIO_printf(bio_err,"-prverify file  verify a signature using private key in file\n");
      BIO_printf(bio_err,"-keyform arg    key file format (PEM or ENGINE)\n");
      BIO_printf(bio_err,"-out filename   output to filename rather than stdout\n");
      BIO_printf(bio_err,"-signature file signature to verify\n");
      BIO_printf(bio_err,"-sigopt nm:v    signature parameter\n");
      BIO_printf(bio_err,"-hmac key       create hashed MAC with key\n");
      BIO_printf(bio_err,"-mac algorithm  create MAC (not neccessarily HMAC)\n");
      BIO_printf(bio_err,"-macopt nm:v    MAC algorithm parameters or key\n");
      BIO_printf(bio_err,"-engine e       use engine e, possibly a hardware device.\n");
      EVP_MD_do_all_sorted(list_md_fn,bio_err);
      goto LAB_08051392;
    }
    pBVar8 = BIO_s_file();
    b = BIO_new(pBVar8);
    pBVar8 = BIO_f_md();
    bp = BIO_new(pBVar8);
    if ((b == (BIO *)0x0) || (bp == (BIO *)0x0)) {
      ERR_print_errors(bio_err);
      OPENSSL_cleanse(ptr,0x2000);
      CRYPTO_free(ptr);
      if (b != (BIO *)0x0) {
        iVar7 = 1;
        pvVar15 = (void *)0x0;
        local_b0 = (BIO *)0x0;
        goto LAB_08051713;
      }
      pvVar15 = (void *)0x0;
      iVar7 = 1;
      local_b0 = (BIO *)0x0;
    }
    else {
      if (bVar4) {
        BIO_set_callback(b,BIO_debug_callback);
        BIO_set_callback_arg(b,(char *)bio_err);
      }
      iVar7 = app_passwd(bio_err,local_80,0,&local_54,0);
      if (iVar7 == 0) {
        pvVar15 = (void *)0x0;
        iVar7 = 1;
        BIO_printf(bio_err,"Error getting password\n");
        local_b0 = (BIO *)0x0;
      }
      else {
        if (local_84 == 0xffffffff) {
          local_84 = (uint)(local_8c != (char *)0x0);
        }
        if (local_9c != (char *)0x0) {
          app_RAND_load_file(local_9c,bio_err,0);
        }
        if (local_94 == (char *)0x0) {
          local_b0 = BIO_new_fp(stdout,0);
          if (local_b0 == (BIO *)0x0) {
            local_94 = "(stdout)";
            goto LAB_080520b7;
          }
        }
        else {
          if (local_84 == 0) {
            local_b0 = BIO_new_file(local_94,"w");
          }
          else {
            local_b0 = BIO_new_file(local_94,"wb");
          }
          if (local_b0 == (BIO *)0x0) {
LAB_080520b7:
            pvVar15 = (void *)0x0;
            iVar7 = 1;
            BIO_printf(bio_err,"Error opening output file %s\n",local_94);
            ERR_print_errors(bio_err);
            local_b0 = (BIO *)0x0;
            goto LAB_080516f6;
          }
        }
        if ((byte)(((uchar *)local_74 != (uchar *)0x0) +
                  (local_78 != (char *)0x0) + (local_8c != (char *)0x0)) < 2) {
          if (local_8c == (char *)0x0) {
LAB_08051a09:
            if (local_78 == (char *)0x0) {
LAB_08051aee:
              if (bVar6) {
                BIO_ctrl(bp,0x78,0,&local_4c);
                EVP_MD_CTX_set_flags(local_4c,8);
              }
              if ((uchar *)local_74 == (uchar *)0x0) {
                if (local_58 != (EVP_PKEY *)0x0) goto LAB_08051b2e;
                if (local_68 == (EVP_MD *)0x0) {
                  local_68 = EVP_md5();
                }
                lVar10 = BIO_ctrl(bp,0x6f,0,local_68);
                if (lVar10 == 0) {
                  iVar7 = 1;
                  BIO_printf(bio_err,"Error setting digest %s\n",local_48);
                  pvVar15 = (void *)0x0;
                  ERR_print_errors(bio_err);
                  goto LAB_080516f6;
                }
LAB_08051bfe:
                if ((local_88 == (char *)0x0) || (local_58 == (EVP_PKEY *)0x0)) {
                  local_9c = (char *)0x0;
                  pvVar15 = (void *)0x0;
LAB_08051c96:
                  pBVar11 = BIO_push(bp,b);
                  if (local_68 == (EVP_MD *)0x0) {
                    BIO_ctrl(bp,0x78,0,&local_4c);
                    local_68 = EVP_MD_CTX_md(local_4c);
                  }
                  if (param_1 == 0) {
                    BIO_ctrl(b,0x6a,0,stdin);
                    iVar7 = do_fp(local_b0,ptr,pBVar11,local_ac,local_84,local_58,pvVar15,local_9c,0
                                  ,0,"stdin",bp);
                  }
                  else {
                    local_4c = (EVP_MD_CTX *)0x0;
                    local_94 = (char *)0x0;
                    if (local_84 == 0) {
                      if ((local_58 != (EVP_PKEY *)0x0) &&
                         (ameth = EVP_PKEY_get0_asn1(local_58), ameth != (EVP_PKEY_ASN1_METHOD *)0x0
                         )) {
                        EVP_PKEY_asn1_get0_info
                                  ((int *)0x0,(int *)0x0,(int *)0x0,(char **)0x0,(char **)&local_4c,
                                   ameth);
                      }
                      iVar7 = EVP_MD_type(local_68);
                      local_94 = OBJ_nid2sn(iVar7);
                    }
                    iVar7 = 0;
                    if (0 < param_1) {
                      iVar9 = 0;
                      do {
                        lVar10 = BIO_ctrl(b,0x6c,3,ppcVar16[iVar9]);
                        if (lVar10 < 1) {
                          iVar7 = iVar7 + 1;
                          perror(ppcVar16[iVar9]);
                        }
                        else {
                          iVar12 = do_fp(local_b0,ptr,pBVar11,local_ac,local_84,local_58,pvVar15,
                                         local_9c,local_4c,local_94,ppcVar16[iVar9],bp);
                          if (iVar12 != 0) {
                            iVar7 = iVar12;
                          }
                          BIO_ctrl(bp,1,0,(void *)0x0);
                        }
                        iVar9 = iVar9 + 1;
                      } while (param_1 != iVar9);
                    }
                  }
                }
                else {
                  pBVar11 = BIO_new_file(local_88,"rb");
                  iVar7 = EVP_PKEY_size(local_58);
                  pcVar24 = (char *)0x1bd;
                  pvVar15 = CRYPTO_malloc(iVar7,"dgst.c",0x1bd);
                  if (pBVar11 == (BIO *)0x0) {
                    pcVar22 = "Error opening signature file %s\n";
                  }
                  else if (pvVar15 == (void *)0x0) {
                    pcVar22 = "Out of memory\n";
                    local_88 = pcVar24;
                  }
                  else {
                    local_9c = (char *)BIO_read(pBVar11,pvVar15,iVar7);
                    BIO_free(pBVar11);
                    if (0 < (int)local_9c) goto LAB_08051c96;
                    pcVar22 = "Error reading signature file %s\n";
                  }
                  iVar7 = 1;
                  BIO_printf(bio_err,pcVar22,local_88);
                  ERR_print_errors(bio_err);
                }
                goto LAB_080516f6;
              }
              local_58 = EVP_PKEY_new_mac_key(0x357,local_6c,(uchar *)local_74,-1);
              if (local_58 != (EVP_PKEY *)0x0) {
LAB_08051b2e:
                local_50 = (EVP_MD_CTX *)0x0;
                local_4c = (EVP_MD_CTX *)0x0;
                pvVar15 = (void *)0x0;
                lVar10 = BIO_ctrl(bp,0x78,0,&local_50);
                if (lVar10 == 0) {
                  pcVar24 = "Error getting context\n";
                }
                else {
                  if (bVar3) {
                    iVar7 = EVP_DigestVerifyInit
                                      (local_50,(EVP_PKEY_CTX **)&local_4c,local_68,(ENGINE *)0x0,
                                       local_58);
                  }
                  else {
                    iVar7 = EVP_DigestSignInit(local_50,(EVP_PKEY_CTX **)&local_4c,local_68,
                                               (ENGINE *)0x0,local_58);
                  }
                  if (iVar7 != 0) {
                    if (local_a8 != (_STACK *)0x0) {
                      for (iVar7 = 0; iVar9 = sk_num(local_a8), iVar7 < iVar9; iVar7 = iVar7 + 1) {
                        pvVar15 = sk_value(local_a8,iVar7);
                        iVar9 = pkey_ctrl_string(local_4c,pvVar15);
                        if (iVar9 < 1) {
                          pcVar24 = "parameter error \"%s\"\n";
                          goto LAB_08051e10;
                        }
                      }
                    }
                    goto LAB_08051bfe;
                  }
                  pcVar24 = "Error setting context\n";
                }
LAB_08051e10:
                BIO_printf(bio_err,pcVar24,pvVar15);
                ERR_print_errors(bio_err);
              }
            }
            else {
              local_4c = (EVP_MD_CTX *)0x0;
              iVar7 = init_gen_str(bio_err,&local_4c,local_78,local_6c,0);
              if (iVar7 != 0) {
                if (local_a4 != (_STACK *)0x0) {
                  for (iVar7 = 0; iVar9 = sk_num(local_a4), iVar7 < iVar9; iVar7 = iVar7 + 1) {
                    pvVar15 = sk_value(local_a4,iVar7);
                    iVar9 = pkey_ctrl_string(local_4c,pvVar15);
                    if (iVar9 < 1) {
                      BIO_printf(bio_err,"MAC parameter error \"%s\"\n",pvVar15);
                      ERR_print_errors(bio_err);
                      goto LAB_08052025;
                    }
                  }
                }
                iVar7 = EVP_PKEY_keygen((EVP_PKEY_CTX *)local_4c,&local_58);
                if (0 < iVar7) {
                  if (local_4c != (EVP_MD_CTX *)0x0) {
                    EVP_PKEY_CTX_free((EVP_PKEY_CTX *)local_4c);
                  }
                  goto LAB_08051aee;
                }
                BIO_puts(bio_err,"Error generating key\n");
                ERR_print_errors(bio_err);
              }
LAB_08052025:
              if (local_4c != (EVP_MD_CTX *)0x0) {
                EVP_PKEY_CTX_free((EVP_PKEY_CTX *)local_4c);
              }
            }
          }
          else {
            if (bVar5) {
              local_58 = (EVP_PKEY *)load_pubkey(bio_err,local_8c,local_64,0,0,local_6c,"key file");
            }
            else {
              local_58 = (EVP_PKEY *)
                         load_key(bio_err,local_8c,local_64,0,local_54,local_6c,"key file");
            }
            if (local_58 != (EVP_PKEY *)0x0) goto LAB_08051a09;
          }
          pvVar15 = (void *)0x0;
          iVar7 = 1;
        }
        else {
          pvVar15 = (void *)0x0;
          iVar7 = 1;
          BIO_printf(bio_err,"MAC and Signing key cannot both be specified\n");
        }
      }
LAB_080516f6:
      OPENSSL_cleanse(ptr,0x2000);
      CRYPTO_free(ptr);
LAB_08051713:
      BIO_free(b);
    }
  }
  if (local_54 != (void *)0x0) goto LAB_080513c8;
LAB_080513d4:
  BIO_free_all(local_b0);
  EVP_PKEY_free(local_58);
  if (local_a8 != (_STACK *)0x0) {
    sk_free(local_a8);
  }
  if (local_a4 != (_STACK *)0x0) {
    sk_free(local_a4);
  }
  if (pvVar15 != (void *)0x0) {
    CRYPTO_free(pvVar15);
  }
  if (bp != (BIO *)0x0) {
    BIO_free(bp);
  }
LAB_08051435:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}

