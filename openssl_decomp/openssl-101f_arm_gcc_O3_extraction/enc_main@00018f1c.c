
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void enc_main(int param_1,undefined4 *param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  BIO *pBVar9;
  void *data;
  BIO_METHOD *pBVar10;
  long lVar11;
  size_t sVar12;
  int iVar13;
  ulong uVar14;
  char *pcVar15;
  FILE *__stream;
  BIO *pBVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  BIO *pBVar20;
  BIO *pBVar21;
  uchar *puVar22;
  byte **ppbVar23;
  BIO *b;
  byte *local_19c;
  EVP_MD *local_198;
  BIO *local_194;
  BIO *local_190;
  BIO *local_18c;
  uint local_188;
  uchar *local_184;
  BIO *local_180;
  byte *local_17c;
  BIO *local_178;
  byte *local_174;
  int local_170;
  BIO *local_16c;
  byte *local_164;
  BIO *local_160;
  int local_15c;
  BIO *local_158;
  BIO *local_154;
  BIO *local_148;
  EVP_CIPHER_CTX *local_144;
  undefined auStack_140 [7];
  uchar uStack_139;
  uchar local_138 [8];
  uchar auStack_130 [16];
  char local_120;
  char local_11f;
  char local_11e;
  char local_11d;
  uchar auStack_f4 [200];
  int local_2c;
  
  local_2c = __TMC_END__;
  local_148 = (BIO *)0x0;
  local_144 = (EVP_CIPHER_CTX *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar10 = BIO_s_file();
    bio_err = BIO_new(pBVar10);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar8 = load_config(bio_err,0);
  if (iVar8 == 0) {
LAB_00018f5a:
    iVar8 = 1;
    ERR_print_errors(bio_err);
    goto LAB_00018f62;
  }
  program_name(*param_2,&local_120,0x28);
  iVar8 = strcmp(&local_120,"base64");
  if (iVar8 == 0) {
    local_16c = (BIO *)0x1;
    local_180 = (BIO *)EVP_get_cipherbyname(&local_120);
  }
  else {
    local_180 = (BIO *)EVP_get_cipherbyname(&local_120);
    if (local_180 == (BIO *)0x0) {
      if ((((local_120 != 'e') || (local_11f != 'n')) || (local_11e != 'c')) ||
         (local_16c = local_180, local_11d != '\0')) {
        BIO_printf(bio_err,"%s is an unknown cipher\n",&local_120);
LAB_00019112:
        BIO_printf(bio_err,"options are\n");
        BIO_printf(bio_err,"%-14s input file\n","-in <file>");
        BIO_printf(bio_err,"%-14s output file\n","-out <file>");
        BIO_printf(bio_err,"%-14s pass phrase source\n","-pass <arg>");
        BIO_printf(bio_err,"%-14s encrypt\n",&DAT_00127c10);
        BIO_printf(bio_err,"%-14s decrypt\n",&DAT_00127c24);
        BIO_printf(bio_err,"%-14s base64 encode/decode, depending on encryption flag\n","-a/-base64"
                  );
        BIO_printf(bio_err,"%-14s passphrase is the next argument\n",&DAT_00127c98);
        BIO_printf(bio_err,"%-14s passphrase is the first line of the file argument\n","-kfile");
        BIO_printf(bio_err,"%-14s the next argument is the md to use to create a key\n",
                   &DAT_00127d1c);
        BIO_printf(bio_err,"%-14s   from a passphrase.  One of md2, md5, sha or sha1\n","");
        BIO_printf(bio_err,"%-14s salt in hex is the next argument\n",&DAT_00127d84);
        BIO_printf(bio_err,"%-14s key/iv in hex is the next argument\n","-K/-iv");
        BIO_printf(bio_err,"%-14s print the iv/key (then exit if -P)\n","-[pP]");
        BIO_printf(bio_err,"%-14s buffer size\n","-bufsize <n>");
        BIO_printf(bio_err,"%-14s disable standard block padding\n","-nopad");
        BIO_printf(bio_err,"%-14s use engine e, possibly a hardware device.\n","-engine e");
        BIO_printf(bio_err,"Cipher Types\n");
        OBJ_NAME_do_all_sorted(2,show_ciphers + 1,bio_err);
        BIO_printf(bio_err,"\n");
        goto LAB_00018f5a;
      }
    }
    else {
      local_16c = (BIO *)0x0;
    }
  }
  param_1 = param_1 + -1;
  ppbVar23 = (byte **)(param_2 + 1);
  if (param_1 < 1) {
    local_198 = (EVP_MD *)0x0;
    bVar5 = false;
    local_18c = (BIO *)0x1;
    local_190 = (BIO *)0x0;
    local_194 = (BIO *)0x0;
    local_160 = (BIO *)0x0;
    bVar7 = false;
    bVar4 = false;
    local_15c = 0;
    local_17c = (byte *)0x0;
    local_154 = (BIO *)0x0;
    local_158 = (BIO *)0x0;
    local_164 = (byte *)0x0;
    local_19c = (byte *)0x0;
    local_178 = (BIO *)0x0;
    bVar6 = false;
    local_170 = 0;
    local_174 = (byte *)local_198;
  }
  else {
    local_194 = (BIO *)0x0;
    bVar5 = false;
    local_198 = (EVP_MD *)0x0;
    local_190 = (BIO *)0x0;
    local_160 = (BIO *)0x0;
    bVar7 = false;
    bVar4 = false;
    local_15c = 0;
    local_17c = (byte *)0x0;
    local_154 = (BIO *)0x0;
    local_158 = (BIO *)0x0;
    local_164 = (byte *)0x0;
    local_19c = (byte *)0x0;
    local_178 = (BIO *)0x0;
    bVar6 = false;
    local_170 = 0;
    local_174 = (byte *)0x0;
    pBVar21 = (BIO *)0x1;
    do {
      while( true ) {
        pbVar19 = *ppbVar23;
        bVar2 = *pbVar19;
        pBVar20 = (BIO *)(0x2d - (uint)bVar2);
        local_18c = pBVar21;
        pBVar9 = local_160;
        if (pBVar20 == (BIO *)0x0) break;
LAB_00018ff4:
        iVar8 = strcmp((char *)pbVar19,"-out");
        if (iVar8 == 0) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_00019112;
          local_190 = (BIO *)ppbVar23[1];
          ppbVar23 = ppbVar23 + 1;
        }
        else {
          iVar8 = strcmp((char *)pbVar19,"-pass");
          if (iVar8 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_00019112;
            local_19c = ppbVar23[1];
            ppbVar23 = ppbVar23 + 1;
          }
          else {
            iVar8 = strcmp((char *)pbVar19,"-engine");
            if (iVar8 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_00019112;
              local_198 = (EVP_MD *)ppbVar23[1];
              ppbVar23 = ppbVar23 + 1;
            }
            else {
              if (pBVar20 == (BIO *)0x0) {
                bVar3 = pbVar19[1];
                if (bVar3 != 100) {
                  if (bVar3 == 0x70) {
                    if (pbVar19[2] != 0) goto LAB_00019330;
                    local_15c = 1;
                  }
                  else {
                    if ((bVar3 != 0x76) || (pbVar19[2] != 0)) goto LAB_00019330;
                    local_170 = 1;
                  }
                  goto LAB_00019018;
                }
                local_18c = pBVar20;
                if (pbVar19[2] == 0) goto LAB_00019018;
              }
LAB_00019330:
              iVar8 = strcmp((char *)pbVar19,"-nopad");
              if (iVar8 == 0) {
                bVar6 = true;
                local_18c = pBVar21;
              }
              else {
                pBVar9 = (BIO *)strcmp((char *)pbVar19,"-salt");
                local_18c = pBVar21;
                if (pBVar9 != (BIO *)0x0) {
                  iVar8 = strcmp((char *)pbVar19,"-nosalt");
                  if (iVar8 == 0) {
                    local_160 = (BIO *)0x1;
                    pBVar9 = local_160;
                  }
                  else {
                    iVar8 = strcmp((char *)pbVar19,"-debug");
                    if (iVar8 == 0) {
                      bVar4 = true;
                      pBVar9 = local_160;
                    }
                    else {
                      if (pBVar20 == (BIO *)0x0) {
                        bVar3 = pbVar19[1];
                        if (bVar3 != 0x50) {
                          if (bVar3 == 0x41) {
                            if (pbVar19[2] != 0) goto LAB_00019386;
                            bVar7 = true;
                            pBVar9 = local_160;
                          }
                          else {
                            if ((bVar3 != 0x61) || (pbVar19[2] != 0)) goto LAB_00019386;
                            local_16c = (BIO *)0x1;
                            pBVar9 = local_160;
                          }
                          goto LAB_00019018;
                        }
                        if (pbVar19[2] == 0) {
                          local_15c = 2;
                          pBVar9 = local_160;
                          goto LAB_00019018;
                        }
                      }
LAB_00019386:
                      iVar8 = strcmp((char *)pbVar19,"-base64");
                      if (iVar8 == 0) {
                        local_16c = (BIO *)0x1;
                        pBVar9 = local_160;
                      }
                      else {
                        iVar8 = strcmp((char *)pbVar19,"-bufsize");
                        if (iVar8 == 0) {
                          param_1 = param_1 + -1;
                          if (param_1 == 0) goto LAB_00019112;
                          local_174 = ppbVar23[1];
                          ppbVar23 = ppbVar23 + 1;
                          pBVar9 = local_160;
                        }
                        else {
                          if (pBVar20 != (BIO *)0x0) {
                            iVar8 = strcmp((char *)pbVar19,"-kfile");
                            if (iVar8 != 0) goto LAB_00019dd4;
LAB_00019d0e:
                            param_1 = param_1 + -1;
                            if (param_1 == 0) goto LAB_00019112;
                            pbVar19 = ppbVar23[1];
                            ppbVar23 = ppbVar23 + 1;
                            __stream = fopen((char *)pbVar19,"r");
                            if (__stream != (FILE *)0x0) {
                              buf_19125[0] = 0;
                              pcVar15 = fgets(PTR_buf_19125_00019f58,0x80,__stream);
                              if (pcVar15 != (char *)0x0) {
                                fclose(__stream);
                                sVar12 = strlen(PTR_buf_19125_00019f58);
                                if (0 < (int)sVar12) {
                                  cVar1 = *(char *)((int)&n_18884 + sVar12 + 3);
                                  if ((cVar1 != '\r') && (cVar1 != '\n')) {
LAB_00019da4:
                                    local_178 = (BIO *)PTR_buf_19125_00019f58;
                                    pBVar9 = local_160;
                                    goto LAB_00019018;
                                  }
                                  *(undefined *)((int)&n_18884 + sVar12 + 3) = 0;
                                  if (sVar12 != 1) {
                                    cVar1 = *(char *)((int)&n_18884 + sVar12 + 2);
                                    if ((cVar1 != '\r') && (cVar1 != '\n')) {
                                      local_178 = (BIO *)PTR_buf_19125_00019f58;
                                      pBVar9 = local_160;
                                      goto LAB_00019018;
                                    }
                                    *(undefined *)((int)&n_18884 + sVar12 + 2) = 0;
                                    if (0 < (int)(sVar12 - 2)) goto LAB_00019da4;
                                  }
                                }
                                BIO_printf(bio_err,"zero length password\n");
                                goto LAB_00019112;
                              }
                            }
                            BIO_printf(bio_err,"unable to read key from \'%s\'\n",pbVar19);
                            goto LAB_00019112;
                          }
                          bVar3 = pbVar19[1];
                          if ((bVar3 == 0x6b) && (pbVar19[2] == 0)) {
                            param_1 = param_1 + -1;
                            if (param_1 == 0) goto LAB_00019112;
                            local_178 = (BIO *)ppbVar23[1];
                            ppbVar23 = ppbVar23 + 1;
                            pBVar9 = local_160;
                          }
                          else {
                            iVar8 = strcmp((char *)pbVar19,"-kfile");
                            if (iVar8 == 0) goto LAB_00019d0e;
                            if (bVar3 == 0x4b) {
                              if (pbVar19[2] != 0) goto LAB_00019dd4;
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_00019112;
                              local_164 = ppbVar23[1];
                              ppbVar23 = ppbVar23 + 1;
                              pBVar9 = local_160;
                            }
                            else if (bVar3 == 0x53) {
                              if (pbVar19[2] != 0) goto LAB_00019dd4;
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_00019112;
                              local_154 = (BIO *)ppbVar23[1];
                              ppbVar23 = ppbVar23 + 1;
                              pBVar9 = local_160;
                            }
                            else if (bVar3 == 0x69) {
                              if ((pbVar19[2] == 0x76) && (pbVar19[3] == 0)) {
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_00019112;
                                local_158 = (BIO *)ppbVar23[1];
                                ppbVar23 = ppbVar23 + 1;
                                pBVar9 = local_160;
                              }
                              else {
LAB_00019dd4:
                                iVar8 = strcmp((char *)pbVar19,"-non-fips-allow");
                                if (iVar8 == 0) {
                                  bVar5 = true;
                                  pBVar9 = local_160;
                                }
                                else {
                                  if (bVar2 == 0x2d) {
                                    local_180 = (BIO *)EVP_get_cipherbyname((char *)(pbVar19 + 1));
                                    pBVar9 = local_160;
                                    if (local_180 != (BIO *)0x0) goto LAB_00019018;
                                    pbVar19 = *ppbVar23;
                                  }
                                  local_180 = (BIO *)strcmp((char *)pbVar19,"-none");
                                  pBVar9 = local_160;
                                  if (local_180 != (BIO *)0x0) {
                                    BIO_printf(bio_err,"unknown option \'%s\'\n",pbVar19);
                                    goto LAB_00019112;
                                  }
                                }
                              }
                            }
                            else {
                              if (((bVar3 != 0x6d) || (pbVar19[2] != 100)) || (pbVar19[3] != 0))
                              goto LAB_00019dd4;
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_00019112;
                              local_17c = ppbVar23[1];
                              ppbVar23 = ppbVar23 + 1;
                              pBVar9 = local_160;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
LAB_00019018:
        local_160 = pBVar9;
        param_1 = param_1 + -1;
        ppbVar23 = ppbVar23 + 1;
        pBVar21 = local_18c;
        if (param_1 < 1) goto LAB_0001907a;
      }
      if (pbVar19[1] == 0x65) {
        if (pbVar19[2] != 0) goto LAB_00018ff4;
        local_18c = (BIO *)0x1;
        goto LAB_00019018;
      }
      if (((pbVar19[1] != 0x69) || (pbVar19[2] != 0x6e)) || (pbVar19[3] != 0)) goto LAB_00018ff4;
      if (param_1 == 1) goto LAB_00019112;
      param_1 = param_1 + -2;
      local_194 = (BIO *)ppbVar23[1];
      ppbVar23 = ppbVar23 + 2;
    } while (0 < param_1);
  }
LAB_0001907a:
  setup_engine(bio_err,local_198,0);
  if (local_17c == (byte *)0x0) {
    local_198 = EVP_md5();
  }
  else {
    local_198 = EVP_get_digestbyname((char *)local_17c);
    if (local_198 == (EVP_MD *)0x0) {
      BIO_printf(bio_err,"%s is an unsupported message digest type\n",local_17c);
      goto LAB_00018f5a;
    }
  }
  if (local_174 == (byte *)0x0) {
    iVar8 = 0x2c52;
    local_188 = 0x2000;
  }
  else {
    local_188 = (uint)*local_174;
    if (local_188 == 0) {
      uVar17 = 1;
    }
    else {
      uVar17 = 0;
      uVar18 = local_188;
      do {
        pbVar19 = local_174;
        local_188 = uVar17;
        if (uVar18 - 0x30 < 10) {
          local_188 = (uVar18 + local_188 * 10) - 0x30;
        }
        else if (uVar18 == 0x6b) {
          if (pbVar19[1] != 0) {
            BIO_printf(bio_err,"invalid \'bufsize\' specified.\n");
            goto LAB_00018f5a;
          }
          local_188 = local_188 << 10;
          break;
        }
        uVar18 = (uint)pbVar19[1];
        uVar17 = local_188;
        local_174 = pbVar19 + 1;
      } while (uVar18 != 0);
      local_174 = pbVar19 + 1;
      if (local_188 < 0x50) {
        uVar17 = 1;
      }
      else {
        uVar17 = 0;
      }
    }
    if (((uint)local_16c & uVar17) == 0) {
      iVar8 = ((int)local_188 / 0x30 + ((int)(local_188 + 2) / 3) * 2 + 0x29) * 2;
    }
    else {
      iVar8 = 0xc0;
      local_188 = 0x50;
    }
    if (local_170 != 0) {
      BIO_printf(bio_err,"bufsize=%d\n",local_188);
    }
  }
  pBVar9 = (BIO *)CRYPTO_malloc(0x200,"enc.c",0x176);
  data = CRYPTO_malloc(iVar8,"enc.c",0x177);
  pBVar21 = (BIO *)(uint)(data == (void *)0x0 || pBVar9 == (BIO *)0x0);
  if (data != (void *)0x0 && pBVar9 != (BIO *)0x0) {
    pBVar10 = BIO_s_file();
    b = BIO_new(pBVar10);
    pBVar10 = BIO_s_file();
    pBVar20 = BIO_new(pBVar10);
    if (b != (BIO *)0x0 && pBVar20 != (BIO *)0x0) {
      if (bVar4) {
        BIO_set_callback(b,BIO_debug_callback + 1);
        BIO_set_callback(pBVar20,BIO_debug_callback + 1);
        BIO_set_callback_arg(b,(char *)bio_err);
        BIO_set_callback_arg(pBVar20,(char *)bio_err);
      }
      if (local_194 == (BIO *)0x0) {
        if (local_174 != (byte *)0x0) {
          setvbuf(stdin,(char *)0x0,2,0);
        }
        BIO_ctrl(b,0x6a,0,stdin);
      }
      else {
        lVar11 = BIO_ctrl(b,0x6c,3,local_194);
        if (lVar11 < 1) {
          pBVar21 = (BIO *)0x0;
          perror((char *)local_194);
          iVar8 = 1;
          local_16c = (BIO *)0x0;
          goto LAB_00019614;
        }
      }
      uVar17 = count_leading_zeroes(local_178);
      uVar17 = uVar17 >> 5;
      if (local_19c == (byte *)0x0) {
        uVar18 = 0;
      }
      else {
        uVar18 = uVar17 & 1;
      }
      if (uVar18 != 0) {
        pBVar21 = (BIO *)app_passwd(bio_err,local_19c,0,&local_148,0);
        if (pBVar21 == (BIO *)0x0) {
          BIO_printf(bio_err,"Error getting password\n");
          iVar8 = 1;
          local_16c = pBVar21;
          goto LAB_00019614;
        }
        local_178 = local_148;
        uVar17 = count_leading_zeroes(local_148);
        uVar17 = uVar17 >> 5;
      }
      pBVar16 = local_180;
      if (local_180 != (BIO *)0x0) {
        pBVar16 = (BIO *)0x1;
      }
      if ((uVar17 & (uint)pBVar16) != 0) {
        if (local_164 == (byte *)0x0) {
          if (local_18c == (BIO *)0x0) {
            do {
              iVar8 = EVP_CIPHER_nid((EVP_CIPHER *)local_180);
              pcVar15 = OBJ_nid2ln(iVar8);
              BIO_snprintf((char *)auStack_f4,200,"enter %s %s password:",pcVar15,"decryption");
              *(byte *)&pBVar9->method = 0;
              iVar8 = EVP_read_pw_string((char *)pBVar9,0x200,(char *)auStack_f4,0);
              if (iVar8 == 0) goto LAB_00019b14;
            } while (-1 < iVar8);
          }
          else {
            do {
              local_184 = auStack_f4;
              iVar8 = EVP_CIPHER_nid((EVP_CIPHER *)local_180);
              pcVar15 = OBJ_nid2ln(iVar8);
              BIO_snprintf((char *)local_184,200,"enter %s %s password:",pcVar15,"encryption");
              *(byte *)&pBVar9->method = 0;
              iVar8 = EVP_read_pw_string((char *)pBVar9,0x200,(char *)local_184,(int)local_18c);
              if (iVar8 == 0) goto LAB_00019b14;
            } while (-1 < iVar8);
          }
          BIO_printf(bio_err,"bad password read\n");
          goto LAB_00019b84;
        }
        local_178 = (BIO *)0x0;
        uVar17 = uVar17 & (uint)pBVar16;
      }
      goto LAB_00019582;
    }
    iVar8 = 1;
    ERR_print_errors(bio_err);
    local_16c = pBVar21;
    goto LAB_00019614;
  }
  BIO_printf(bio_err,"OPENSSL_malloc failure %ld\n",iVar8);
  ERR_print_errors(bio_err);
  if (pBVar9 != (BIO *)0x0) {
    pBVar21 = (BIO *)0x0;
    iVar8 = 1;
    local_16c = (BIO *)0x0;
    pBVar20 = (BIO *)0x0;
    b = (BIO *)0x0;
    goto LAB_0001948c;
  }
  iVar8 = 1;
  local_16c = pBVar9;
  pBVar20 = pBVar9;
  b = pBVar9;
LAB_00019492:
  if (data != (void *)0x0) {
    CRYPTO_free(data);
  }
  if (b != (BIO *)0x0) {
    BIO_free(b);
  }
  if (pBVar20 != (BIO *)0x0) {
    BIO_free_all(pBVar20);
  }
  if (pBVar9 != (BIO *)0x0) {
    BIO_free(pBVar9);
  }
  if (local_16c != (BIO *)0x0) {
    BIO_free(local_16c);
  }
LAB_00018f62:
  if (local_148 != (BIO *)0x0) {
    CRYPTO_free(local_148);
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar8);
  }
  return;
LAB_00019b14:
  if (*(byte *)&pBVar9->method == 0) {
LAB_00019b84:
    pBVar21 = (BIO *)0x0;
    iVar8 = 1;
    local_16c = (BIO *)0x0;
    goto LAB_00019614;
  }
  uVar17 = 0;
  local_178 = pBVar9;
LAB_00019582:
  if (local_190 == (BIO *)0x0) {
    BIO_ctrl(pBVar20,0x6a,0,stdout);
    if (local_174 != (byte *)0x0) {
      setvbuf(stdout,(char *)0x0,2,0);
    }
  }
  else {
    lVar11 = BIO_ctrl(pBVar20,0x6c,5,local_190);
    if (lVar11 < 1) {
      pBVar21 = (BIO *)0x0;
      perror((char *)local_190);
      iVar8 = 1;
      local_16c = (BIO *)0x0;
      goto LAB_00019614;
    }
  }
  local_194 = pBVar20;
  local_190 = b;
  if (local_16c != (BIO *)0x0) {
    pBVar10 = BIO_f_base64();
    pBVar21 = BIO_new(pBVar10);
    local_16c = pBVar21;
    if (pBVar21 == (BIO *)0x0) {
      iVar8 = 1;
      goto LAB_00019614;
    }
    if (bVar4) {
      BIO_set_callback(pBVar21,BIO_debug_callback + 1);
      BIO_set_callback_arg(pBVar21,(char *)bio_err);
    }
    if (bVar7) {
      BIO_set_flags(pBVar21,0x100);
    }
    if (local_18c == (BIO *)0x0) {
      local_190 = BIO_push(pBVar21,b);
    }
    else {
      local_194 = BIO_push(pBVar21,pBVar20);
    }
  }
  if (pBVar16 == (BIO *)0x0) {
LAB_00019830:
    do {
      iVar8 = BIO_read(local_190,data,local_188);
      pBVar21 = pBVar16;
      if (iVar8 < 1) {
        lVar11 = BIO_ctrl(local_194,0xb,0,(void *)0x0);
        pBVar16 = bio_err;
        if (lVar11 == 0) {
          iVar8 = 1;
          BIO_printf(bio_err,"bad decrypt\n");
        }
        else {
          iVar8 = local_170;
          if (local_170 != 0) {
            uVar14 = BIO_number_read(b);
            BIO_printf(pBVar16,"bytes read   :%8ld\n",uVar14);
            pBVar16 = bio_err;
            iVar8 = 0;
            uVar14 = BIO_number_written(pBVar20);
            BIO_printf(pBVar16,"bytes written:%8ld\n",uVar14);
          }
        }
        goto LAB_00019614;
      }
      iVar13 = BIO_write(local_194,data,iVar8);
    } while (iVar13 == iVar8);
    iVar8 = 1;
    BIO_printf(bio_err,"error writing output file\n");
  }
  else if (local_178 == (BIO *)0x0) {
LAB_000196a2:
    if (local_158 == (BIO *)0x0) {
      if ((uVar17 == 0) || (iVar8 = EVP_CIPHER_iv_length((EVP_CIPHER *)local_180), iVar8 == 0))
      goto LAB_000196bc;
      iVar8 = 1;
      BIO_printf(bio_err,"iv undefined\n");
      pBVar21 = local_158;
    }
    else {
      pBVar21 = (BIO *)set_hex(local_158,auStack_130,0x10);
      if (pBVar21 == (BIO *)0x0) {
        iVar8 = 1;
        BIO_printf(bio_err,"invalid hex iv value\n");
      }
      else {
LAB_000196bc:
        if ((local_164 == (byte *)0x0) ||
           (pBVar21 = (BIO *)set_hex(local_164,auStack_f4,0x40), pBVar21 != (BIO *)0x0)) {
          pBVar10 = BIO_f_cipher();
          pBVar16 = BIO_new(pBVar10);
          pBVar21 = pBVar16;
          iVar8 = 1;
          if (pBVar16 != (BIO *)0x0) {
            BIO_ctrl(pBVar16,0x81,0,&local_144);
            if (bVar5) {
              EVP_CIPHER_CTX_set_flags(local_144,0x8000);
            }
            iVar8 = EVP_CipherInit_ex(local_144,(EVP_CIPHER *)local_180,(ENGINE *)0x0,(uchar *)0x0,
                                      (uchar *)0x0,(int)local_18c);
            if (iVar8 != 0) {
              if (bVar6) {
                EVP_CIPHER_CTX_set_padding(local_144,0);
              }
              iVar8 = EVP_CipherInit_ex(local_144,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_f4,
                                        auStack_130,(int)local_18c);
              if (iVar8 != 0) {
                if (bVar4) {
                  BIO_set_callback(pBVar16,BIO_debug_callback + 1);
                  BIO_set_callback_arg(pBVar16,(char *)bio_err);
                }
                if (local_15c != 0) {
                  if (local_160 == (BIO *)0x0) {
                    __printf_chk(1,"salt=");
                    puVar22 = &uStack_139;
                    do {
                      puVar22 = puVar22 + 1;
                      __printf_chk(1,&DAT_00128000,*puVar22);
                    } while (puVar22 != local_138 + 7);
                    putchar(10);
                  }
                  if (0 < (int)local_180->cb_arg) {
                    __printf_chk(1,&DAT_00128008);
                    if (0 < (int)local_180->cb_arg) {
                      iVar8 = 0;
                      do {
                        __printf_chk(1,&DAT_00128000,auStack_f4[iVar8]);
                        iVar8 = iVar8 + 1;
                      } while (iVar8 < (int)local_180->cb_arg);
                    }
                    putchar(10);
                  }
                  if (0 < local_180->init) {
                    __printf_chk(1,&DAT_00128010);
                    if (0 < local_180->init) {
                      iVar8 = 0;
                      do {
                        puVar22 = auStack_130 + iVar8;
                        iVar8 = iVar8 + 1;
                        __printf_chk(1,&DAT_00128000,*puVar22);
                      } while (iVar8 < local_180->init);
                    }
                    putchar(10);
                  }
                  if (local_15c == 2) {
                    iVar8 = 0;
                    goto LAB_00019614;
                  }
                }
                local_194 = BIO_push(pBVar16,local_194);
                goto LAB_00019830;
              }
            }
            pBVar16 = bio_err;
            iVar8 = 1;
            iVar13 = EVP_CIPHER_nid((EVP_CIPHER *)local_180);
            pcVar15 = OBJ_nid2sn(iVar13);
            BIO_printf(pBVar16,"Error setting cipher %s\n",pcVar15);
            ERR_print_errors(bio_err);
          }
        }
        else {
          iVar8 = 1;
          BIO_printf(bio_err,"invalid hex key value\n");
        }
      }
    }
  }
  else {
    if (local_160 != (BIO *)0x0) {
      puVar22 = (uchar *)0x0;
LAB_0001966a:
      sVar12 = strlen((char *)local_178);
      EVP_BytesToKey((EVP_CIPHER *)local_180,local_198,puVar22,(uchar *)local_178,sVar12,1,
                     auStack_f4,auStack_130);
      if (local_178 == pBVar9) {
        OPENSSL_cleanse(pBVar9,0x200);
      }
      else {
        sVar12 = strlen((char *)local_178);
        OPENSSL_cleanse(local_178,sVar12);
      }
      goto LAB_000196a2;
    }
    if (local_18c == (BIO *)0x0) {
      iVar8 = BIO_read(local_190,auStack_140,8);
      if (iVar8 == 8) {
        puVar22 = local_138;
        iVar8 = BIO_read(local_190,puVar22,8);
        if (iVar8 == 8) {
          iVar8 = memcmp(auStack_140,"Salted__",8);
          if (iVar8 != 0) {
            iVar8 = 1;
            BIO_printf(bio_err,"bad magic number\n");
            pBVar21 = local_18c;
            goto LAB_00019614;
          }
          goto LAB_0001966a;
        }
      }
      pBVar21 = (BIO *)0x0;
      BIO_printf(bio_err,"error reading input file\n");
      iVar8 = 1;
    }
    else {
      puVar22 = local_138;
      if (local_154 == (BIO *)0x0) {
        iVar8 = RAND_pseudo_bytes(puVar22,8);
        if (-1 < iVar8) goto LAB_000195e4;
        iVar8 = 1;
        pBVar21 = local_154;
      }
      else {
        iVar8 = set_hex(local_154,puVar22,8);
        if (iVar8 == 0) {
          iVar8 = 1;
          BIO_printf(bio_err,"invalid hex salt value\n");
          pBVar21 = local_160;
        }
        else {
LAB_000195e4:
          if ((local_15c == 2) ||
             ((iVar8 = BIO_write(local_194,"Salted__",8), iVar8 == 8 &&
              (iVar8 = BIO_write(local_194,puVar22,8), iVar8 == 8)))) goto LAB_0001966a;
          BIO_printf(bio_err,"error writing output file\n");
          pBVar21 = (BIO *)0x0;
          iVar8 = 1;
        }
      }
    }
  }
LAB_00019614:
  ERR_print_errors(bio_err);
LAB_0001948c:
  CRYPTO_free(pBVar9);
  pBVar9 = pBVar21;
  goto LAB_00019492;
}

