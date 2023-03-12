
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void enc_main(int param_1,undefined4 *param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  ulong uVar8;
  BIO *pBVar9;
  void *data;
  BIO_METHOD *pBVar10;
  long lVar11;
  size_t sVar12;
  int iVar13;
  char *pcVar14;
  FILE *__stream;
  uint uVar15;
  byte *pbVar16;
  BIO *pBVar17;
  byte *__s;
  BIO *pBVar18;
  BIO *pBVar19;
  uchar *puVar20;
  uint uVar21;
  BIO *b;
  byte **ppbVar22;
  BIO *local_19c;
  BIO *local_198;
  byte *local_194;
  BIO *local_190;
  EVP_MD *local_18c;
  BIO *local_188;
  BIO *local_184;
  uint local_180;
  byte *local_17c;
  byte *local_178;
  BIO *local_174;
  int local_170;
  byte *local_168;
  int local_164;
  BIO *local_160;
  BIO *local_15c;
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
  
  local_2c = __stack_chk_guard;
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
  iVar7 = load_config(bio_err,0);
  if (iVar7 != 0) {
    program_name(*param_2,&local_120,0x28);
    iVar7 = strcmp(&local_120,"base64");
    if (iVar7 == 0) {
      local_160 = (BIO *)0x1;
      local_198 = (BIO *)EVP_get_cipherbyname(&local_120);
    }
    else {
      local_198 = (BIO *)EVP_get_cipherbyname(&local_120);
      if (local_198 == (BIO *)0x0) {
        if ((((local_120 != 'e') || (local_11f != 'n')) || (local_11e != 'c')) ||
           (local_160 = local_198, local_11d != '\0')) {
          BIO_printf(bio_err,"%s is an unknown cipher\n",&local_120);
LAB_000191d4:
          BIO_printf(bio_err,"options are\n");
          BIO_printf(bio_err,"%-14s input file\n","-in <file>");
          BIO_printf(bio_err,"%-14s output file\n","-out <file>");
          BIO_printf(bio_err,"%-14s pass phrase source\n","-pass <arg>");
          BIO_printf(bio_err,"%-14s encrypt\n",&DAT_00126958);
          BIO_printf(bio_err,"%-14s decrypt\n",&DAT_0012696c);
          BIO_printf(bio_err,"%-14s base64 encode/decode, depending on encryption flag\n",
                     "-a/-base64");
          BIO_printf(bio_err,"%-14s passphrase is the next argument\n",&DAT_001269e0);
          BIO_printf(bio_err,"%-14s passphrase is the first line of the file argument\n","-kfile");
          BIO_printf(bio_err,"%-14s the next argument is the md to use to create a key\n",
                     &DAT_00126a64);
          BIO_printf(bio_err,"%-14s   from a passphrase.  One of md2, md5, sha or sha1\n","");
          BIO_printf(bio_err,"%-14s salt in hex is the next argument\n",&DAT_00126acc);
          BIO_printf(bio_err,"%-14s key/iv in hex is the next argument\n","-K/-iv");
          BIO_printf(bio_err,"%-14s print the iv/key (then exit if -P)\n","-[pP]");
          BIO_printf(bio_err,"%-14s buffer size\n","-bufsize <n>");
          BIO_printf(bio_err,"%-14s disable standard block padding\n","-nopad");
          BIO_printf(bio_err,"%-14s use engine e, possibly a hardware device.\n","-engine e");
          BIO_printf(bio_err,"Cipher Types\n");
          OBJ_NAME_do_all_sorted(2,show_ciphers + 1,bio_err);
          BIO_printf(bio_err,"\n");
          goto LAB_00018ff2;
        }
      }
      else {
        local_160 = (BIO *)0x0;
      }
    }
    param_1 = param_1 + -1;
    ppbVar22 = (byte **)(param_2 + 1);
    if (param_1 < 1) {
      local_19c = (BIO *)0x0;
      __s = (byte *)0x0;
      local_184 = (BIO *)0x1;
      local_188 = (BIO *)0x0;
      local_15c = (BIO *)0x0;
      bVar6 = false;
      bVar4 = false;
      local_164 = 0;
      local_17c = (byte *)0x0;
      local_154 = (BIO *)0x0;
      local_158 = (BIO *)0x0;
      local_168 = (byte *)0x0;
      local_194 = (byte *)0x0;
      local_174 = (BIO *)0x0;
      bVar5 = false;
      local_170 = 0;
      local_190 = (BIO *)0x0;
      local_178 = (byte *)local_19c;
    }
    else {
      local_188 = (BIO *)0x0;
      __s = (byte *)0x0;
      local_19c = (BIO *)0x0;
      local_15c = (BIO *)0x0;
      bVar6 = false;
      bVar4 = false;
      local_164 = 0;
      local_17c = (byte *)0x0;
      local_154 = (BIO *)0x0;
      local_158 = (BIO *)0x0;
      local_168 = (byte *)0x0;
      local_194 = (byte *)0x0;
      local_174 = (BIO *)0x0;
      bVar5 = false;
      local_170 = 0;
      local_190 = (BIO *)0x0;
      local_178 = (byte *)0x0;
      pBVar18 = (BIO *)0x1;
      do {
        while( true ) {
          pbVar16 = *ppbVar22;
          bVar2 = *pbVar16;
          pBVar17 = (BIO *)(0x2d - (uint)bVar2);
          local_184 = pBVar18;
          pBVar9 = local_15c;
          if (pBVar17 == (BIO *)0x0) break;
LAB_0001908a:
          iVar7 = strcmp((char *)pbVar16,"-out");
          if (iVar7 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_000191d4;
            local_188 = (BIO *)ppbVar22[1];
            ppbVar22 = ppbVar22 + 1;
          }
          else {
            iVar7 = strcmp((char *)pbVar16,"-pass");
            if (iVar7 == 0) {
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_000191d4;
              local_194 = ppbVar22[1];
              ppbVar22 = ppbVar22 + 1;
            }
            else {
              iVar7 = strcmp((char *)pbVar16,"-engine");
              if (iVar7 == 0) {
                param_1 = param_1 + -1;
                if (param_1 == 0) goto LAB_000191d4;
                local_19c = (BIO *)ppbVar22[1];
                ppbVar22 = ppbVar22 + 1;
              }
              else {
                if (pBVar17 == (BIO *)0x0) {
                  bVar3 = pbVar16[1];
                  if (bVar3 != 100) {
                    if (bVar3 == 0x70) {
                      if (pbVar16[2] != 0) goto LAB_000193ee;
                      local_164 = 1;
                    }
                    else {
                      if ((bVar3 != 0x76) || (pbVar16[2] != 0)) goto LAB_000193ee;
                      local_170 = 1;
                    }
                    goto LAB_000190ae;
                  }
                  local_184 = pBVar17;
                  if (pbVar16[2] == 0) goto LAB_000190ae;
                }
LAB_000193ee:
                iVar7 = strcmp((char *)pbVar16,"-nopad");
                if (iVar7 == 0) {
                  bVar5 = true;
                  local_184 = pBVar18;
                }
                else {
                  pBVar9 = (BIO *)strcmp((char *)pbVar16,"-salt");
                  local_184 = pBVar18;
                  if (pBVar9 != (BIO *)0x0) {
                    iVar7 = strcmp((char *)pbVar16,"-nosalt");
                    if (iVar7 == 0) {
                      local_15c = (BIO *)0x1;
                      pBVar9 = local_15c;
                    }
                    else {
                      iVar7 = strcmp((char *)pbVar16,"-debug");
                      if (iVar7 == 0) {
                        bVar4 = true;
                        pBVar9 = local_15c;
                      }
                      else {
                        if (pBVar17 == (BIO *)0x0) {
                          bVar3 = pbVar16[1];
                          if (bVar3 != 0x50) {
                            if (bVar3 == 0x41) {
                              if (pbVar16[2] != 0) goto LAB_00019444;
                              bVar6 = true;
                              pBVar9 = local_15c;
                            }
                            else {
                              if ((bVar3 != 0x61) || (pbVar16[2] != 0)) goto LAB_00019444;
                              local_160 = (BIO *)0x1;
                              pBVar9 = local_15c;
                            }
                            goto LAB_000190ae;
                          }
                          if (pbVar16[2] == 0) {
                            local_164 = 2;
                            pBVar9 = local_15c;
                            goto LAB_000190ae;
                          }
                        }
LAB_00019444:
                        iVar7 = strcmp((char *)pbVar16,"-base64");
                        if (iVar7 == 0) {
                          local_160 = (BIO *)0x1;
                          pBVar9 = local_15c;
                        }
                        else {
                          iVar7 = strcmp((char *)pbVar16,"-bufsize");
                          if (iVar7 == 0) {
                            param_1 = param_1 + -1;
                            if (param_1 == 0) goto LAB_000191d4;
                            local_190 = (BIO *)ppbVar22[1];
                            ppbVar22 = ppbVar22 + 1;
                            pBVar9 = local_15c;
                          }
                          else {
                            if (pBVar17 != (BIO *)0x0) {
                              iVar7 = strcmp((char *)pbVar16,"-kfile");
                              if (iVar7 != 0) goto LAB_00019f2c;
LAB_00019e3c:
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_000191d4;
                              pbVar16 = ppbVar22[1];
                              ppbVar22 = ppbVar22 + 1;
                              __stream = fopen((char *)pbVar16,"r");
                              if (__stream != (FILE *)0x0) {
                                buf_19135[0] = 0;
                                pcVar14 = fgets(PTR_buf_19135_0001a068,0x80,__stream);
                                if (pcVar14 != (char *)0x0) {
                                  fclose(__stream);
                                  sVar12 = strlen(PTR_buf_19135_0001a068);
                                  if (0 < (int)sVar12) {
                                    cVar1 = *(char *)((int)&n_18894 + sVar12 + 3);
                                    if ((cVar1 != '\r') && (cVar1 != '\n')) {
LAB_00019ed0:
                                      local_174 = (BIO *)PTR_buf_19135_0001a068;
                                      pBVar9 = local_15c;
                                      goto LAB_000190ae;
                                    }
                                    *(undefined *)((int)&n_18894 + sVar12 + 3) = 0;
                                    if (sVar12 != 1) {
                                      cVar1 = *(char *)((int)&n_18894 + sVar12 + 2);
                                      if ((cVar1 != '\r') && (cVar1 != '\n')) {
                                        local_174 = (BIO *)PTR_buf_19135_0001a068;
                                        pBVar9 = local_15c;
                                        goto LAB_000190ae;
                                      }
                                      *(undefined *)((int)&n_18894 + sVar12 + 2) = 0;
                                      if (0 < (int)(sVar12 - 2)) goto LAB_00019ed0;
                                    }
                                  }
                                  BIO_printf(bio_err,"zero length password\n");
                                  goto LAB_000191d4;
                                }
                              }
                              BIO_printf(bio_err,"unable to read key from \'%s\'\n",pbVar16);
                              goto LAB_000191d4;
                            }
                            bVar3 = pbVar16[1];
                            if ((bVar3 == 0x6b) && (pbVar16[2] == 0)) {
                              param_1 = param_1 + -1;
                              if (param_1 == 0) goto LAB_000191d4;
                              local_174 = (BIO *)ppbVar22[1];
                              ppbVar22 = ppbVar22 + 1;
                              pBVar9 = local_15c;
                            }
                            else {
                              iVar7 = strcmp((char *)pbVar16,"-kfile");
                              if (iVar7 == 0) goto LAB_00019e3c;
                              if (bVar3 == 0x4b) {
                                if (pbVar16[2] != 0) goto LAB_00019f2c;
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_000191d4;
                                local_168 = ppbVar22[1];
                                ppbVar22 = ppbVar22 + 1;
                                pBVar9 = local_15c;
                              }
                              else if (bVar3 == 0x53) {
                                if (pbVar16[2] != 0) goto LAB_00019f2c;
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_000191d4;
                                local_154 = (BIO *)ppbVar22[1];
                                ppbVar22 = ppbVar22 + 1;
                                pBVar9 = local_15c;
                              }
                              else if (bVar3 == 0x69) {
                                if ((pbVar16[2] == 0x76) && (pbVar16[3] == 0)) {
                                  param_1 = param_1 + -1;
                                  if (param_1 == 0) goto LAB_000191d4;
                                  local_158 = (BIO *)ppbVar22[1];
                                  ppbVar22 = ppbVar22 + 1;
                                  pBVar9 = local_15c;
                                }
                                else {
LAB_00019f2c:
                                  iVar7 = strcmp((char *)pbVar16,"-non-fips-allow");
                                  if (iVar7 == 0) {
                                    local_178 = (byte *)0x1;
                                    pBVar9 = local_15c;
                                  }
                                  else {
                                    if (bVar2 == 0x2d) {
                                      local_198 = (BIO *)EVP_get_cipherbyname((char *)(pbVar16 + 1))
                                      ;
                                      pBVar9 = local_15c;
                                      if (local_198 != (BIO *)0x0) goto LAB_000190ae;
                                      pbVar16 = *ppbVar22;
                                    }
                                    local_198 = (BIO *)strcmp((char *)pbVar16,"-none");
                                    pBVar9 = local_15c;
                                    if (local_198 != (BIO *)0x0) {
                                      BIO_printf(bio_err,"unknown option \'%s\'\n",pbVar16);
                                      goto LAB_000191d4;
                                    }
                                  }
                                }
                              }
                              else {
                                if (((bVar3 != 0x6d) || (pbVar16[2] != 100)) || (pbVar16[3] != 0))
                                goto LAB_00019f2c;
                                param_1 = param_1 + -1;
                                if (param_1 == 0) goto LAB_000191d4;
                                local_17c = ppbVar22[1];
                                ppbVar22 = ppbVar22 + 1;
                                pBVar9 = local_15c;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LAB_000190ae:
          local_15c = pBVar9;
          param_1 = param_1 + -1;
          ppbVar22 = ppbVar22 + 1;
          pBVar18 = local_184;
          if (param_1 < 1) goto LAB_00019110;
        }
        if (pbVar16[1] == 0x65) {
          if (pbVar16[2] != 0) goto LAB_0001908a;
          local_184 = (BIO *)0x1;
          goto LAB_000190ae;
        }
        if (((pbVar16[1] != 0x69) || (pbVar16[2] != 0x6e)) || (pbVar16[3] != 0)) goto LAB_0001908a;
        if (param_1 == 1) goto LAB_000191d4;
        param_1 = param_1 + -2;
        __s = ppbVar22[1];
        ppbVar22 = ppbVar22 + 2;
      } while (0 < param_1);
    }
LAB_00019110:
    setup_engine(bio_err,local_19c,0);
    if (local_198 == (BIO *)0x0) {
LAB_00019146:
      if (local_17c == (byte *)0x0) {
        local_18c = EVP_md5();
      }
      else {
        local_18c = EVP_get_digestbyname((char *)local_17c);
        if (local_18c == (EVP_MD *)0x0) {
          BIO_printf(bio_err,"%s is an unsupported message digest type\n",local_17c);
          goto LAB_00018ff2;
        }
      }
      if (local_190 == (BIO *)0x0) {
        iVar7 = 0x2c52;
        local_180 = 0x2000;
      }
      else {
        local_180 = (uint)*(byte *)local_190;
        if (local_180 == 0) {
          uVar21 = 1;
        }
        else {
          uVar21 = 0;
          uVar15 = local_180;
          do {
            local_180 = uVar21;
            if (uVar15 - 0x30 < 10) {
              local_180 = (uVar15 + local_180 * 10) - 0x30;
            }
            else if (uVar15 == 0x6b) {
              if (*(byte *)((int)local_190 + 1) == 0) {
                local_180 = local_180 * 0x400;
                local_190 = (BIO *)((int)local_190 + 1);
                uVar21 = (uint)(local_180 < 0x50);
                goto LAB_000194cc;
              }
              BIO_printf(bio_err,"invalid \'bufsize\' specified.\n");
              goto LAB_00018ff2;
            }
            local_190 = (BIO *)((int)local_190 + 1);
            uVar15 = (uint)*(byte *)local_190;
            uVar21 = local_180;
          } while (uVar15 != 0);
          if (local_180 < 0x50) {
            uVar21 = 1;
          }
          else {
            uVar21 = 0;
          }
        }
LAB_000194cc:
        if (((uint)local_160 & uVar21) == 0) {
          iVar7 = ((int)local_180 / 0x30 + ((int)(local_180 + 2) / 3) * 2 + 0x29) * 2;
        }
        else {
          iVar7 = 0xc0;
          local_180 = 0x50;
        }
        if (local_170 != 0) {
          BIO_printf(bio_err,"bufsize=%d\n",local_180);
        }
      }
      pBVar9 = (BIO *)CRYPTO_malloc(0x200,"enc.c",0x179);
      data = CRYPTO_malloc(iVar7,"enc.c",0x17a);
      pBVar18 = (BIO *)(uint)(data == (void *)0x0 || pBVar9 == (BIO *)0x0);
      if (data != (void *)0x0 && pBVar9 != (BIO *)0x0) {
        pBVar10 = BIO_s_file();
        pBVar17 = BIO_new(pBVar10);
        pBVar10 = BIO_s_file();
        local_19c = BIO_new(pBVar10);
        if (pBVar17 != (BIO *)0x0 && local_19c != (BIO *)0x0) {
          if (bVar4) {
            BIO_set_callback(pBVar17,BIO_debug_callback + 1);
            BIO_set_callback(local_19c,BIO_debug_callback + 1);
            BIO_set_callback_arg(pBVar17,(char *)bio_err);
            BIO_set_callback_arg(local_19c,(char *)bio_err);
          }
          if (__s == (byte *)0x0) {
            if (local_190 != (BIO *)0x0) {
              setvbuf(stdin,(char *)0x0,2,0);
            }
            BIO_ctrl(pBVar17,0x6a,0,stdin);
          }
          else {
            lVar11 = BIO_ctrl(pBVar17,0x6c,3,__s);
            if (lVar11 < 1) {
              pBVar18 = (BIO *)0x0;
              perror((char *)__s);
              local_170 = 1;
              local_160 = (BIO *)0x0;
              goto LAB_000196dc;
            }
          }
          uVar21 = count_leading_zeroes(local_174);
          uVar21 = uVar21 >> 5;
          if (local_194 == (byte *)0x0) {
            uVar15 = 0;
          }
          else {
            uVar15 = uVar21 & 1;
          }
          if (uVar15 != 0) {
            pBVar18 = (BIO *)app_passwd(bio_err,local_194,0,&local_148,0);
            if (pBVar18 == (BIO *)0x0) {
              BIO_printf(bio_err,"Error getting password\n");
              local_170 = 1;
              local_160 = pBVar18;
              goto LAB_000196dc;
            }
            local_174 = local_148;
            uVar21 = count_leading_zeroes(local_148);
            uVar21 = uVar21 >> 5;
          }
          pBVar19 = local_198;
          if (local_198 != (BIO *)0x0) {
            pBVar19 = (BIO *)0x1;
          }
          if ((uVar21 & (uint)pBVar19) != 0) {
            if (local_168 == (byte *)0x0) {
              if (local_184 == (BIO *)0x0) {
                do {
                  iVar7 = EVP_CIPHER_nid((EVP_CIPHER *)local_198);
                  pcVar14 = OBJ_nid2ln(iVar7);
                  BIO_snprintf((char *)auStack_f4,200,"enter %s %s password:",pcVar14,"decryption");
                  *(byte *)&pBVar9->method = 0;
                  iVar7 = EVP_read_pw_string((char *)pBVar9,0x200,(char *)auStack_f4,0);
                  if (iVar7 == 0) goto LAB_00019c2e;
                } while (-1 < iVar7);
              }
              else {
                do {
                  iVar7 = EVP_CIPHER_nid((EVP_CIPHER *)local_198);
                  pcVar14 = OBJ_nid2ln(iVar7);
                  BIO_snprintf((char *)auStack_f4,200,"enter %s %s password:",pcVar14,"encryption");
                  *(byte *)&pBVar9->method = 0;
                  iVar7 = EVP_read_pw_string((char *)pBVar9,0x200,(char *)auStack_f4,(int)local_184)
                  ;
                  if (iVar7 == 0) goto LAB_00019c2e;
                } while (-1 < iVar7);
              }
              BIO_printf(bio_err,"bad password read\n");
              goto LAB_00019c8a;
            }
            local_174 = (BIO *)0x0;
            uVar21 = uVar21 & (uint)pBVar19;
          }
          goto LAB_00019648;
        }
        local_170 = 1;
        ERR_print_errors(bio_err);
        local_160 = pBVar18;
        goto LAB_000196dc;
      }
      BIO_printf(bio_err,"OPENSSL_malloc failure %ld\n",iVar7);
      ERR_print_errors(bio_err);
      if (pBVar9 != (BIO *)0x0) {
        pBVar18 = (BIO *)0x0;
        local_170 = 1;
        local_160 = (BIO *)0x0;
        pBVar17 = (BIO *)0x0;
        local_19c = (BIO *)0x0;
        goto LAB_0001956e;
      }
      local_170 = 1;
      local_160 = pBVar9;
      pBVar17 = pBVar9;
      local_19c = pBVar9;
      goto LAB_00019574;
    }
    uVar8 = EVP_CIPHER_flags((EVP_CIPHER *)local_198);
    if ((int)(uVar8 << 10) < 0) {
      BIO_printf(bio_err,"AEAD ciphers not supported by the enc utility\n");
    }
    else {
      uVar8 = EVP_CIPHER_flags((EVP_CIPHER *)local_198);
      if ((uVar8 & 0xf0007) != 0x10001) goto LAB_00019146;
      BIO_printf(bio_err,"Ciphers in XTS mode are not supported by the enc utility\n");
    }
  }
LAB_00018ff2:
  local_170 = 1;
  ERR_print_errors(bio_err);
LAB_00018ffa:
  if (local_148 != (BIO *)0x0) {
    CRYPTO_free(local_148);
  }
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_170);
  }
  return;
LAB_00019c2e:
  if (*(byte *)&pBVar9->method == 0) {
LAB_00019c8a:
    pBVar18 = (BIO *)0x0;
    local_170 = 1;
    local_160 = (BIO *)0x0;
    goto LAB_000196dc;
  }
  uVar21 = 0;
  local_174 = pBVar9;
LAB_00019648:
  if (local_188 == (BIO *)0x0) {
    BIO_ctrl(local_19c,0x6a,0,stdout);
    if (local_190 != (BIO *)0x0) {
      setvbuf(stdout,(char *)0x0,2,0);
    }
  }
  else {
    lVar11 = BIO_ctrl(local_19c,0x6c,5,local_188);
    if (lVar11 < 1) {
      pBVar18 = (BIO *)0x0;
      perror((char *)local_188);
      local_170 = 1;
      local_160 = (BIO *)0x0;
      goto LAB_000196dc;
    }
  }
  local_190 = local_19c;
  local_188 = pBVar17;
  if (local_160 != (BIO *)0x0) {
    pBVar10 = BIO_f_base64();
    pBVar18 = BIO_new(pBVar10);
    local_160 = pBVar18;
    if (pBVar18 == (BIO *)0x0) {
      local_170 = 1;
      goto LAB_000196dc;
    }
    if (bVar4) {
      BIO_set_callback(pBVar18,BIO_debug_callback + 1);
      BIO_set_callback_arg(pBVar18,(char *)bio_err);
    }
    if (bVar6) {
      BIO_set_flags(pBVar18,0x100);
    }
    if (local_184 == (BIO *)0x0) {
      local_188 = BIO_push(pBVar18,pBVar17);
    }
    else {
      local_190 = BIO_push(pBVar18,local_19c);
    }
  }
  b = local_190;
  if (pBVar19 == (BIO *)0x0) {
LAB_0001992c:
    do {
      iVar7 = BIO_read(local_188,data,local_180);
      pBVar18 = pBVar19;
      if (iVar7 < 1) {
        lVar11 = BIO_ctrl(local_190,0xb,0,(void *)0x0);
        pBVar19 = bio_err;
        if (lVar11 == 0) {
          local_170 = 1;
          BIO_printf(bio_err,"bad decrypt\n");
        }
        else if (local_170 != 0) {
          uVar8 = BIO_number_read(pBVar17);
          BIO_printf(pBVar19,"bytes read   :%8ld\n",uVar8);
          pBVar19 = bio_err;
          uVar8 = BIO_number_written(local_19c);
          local_170 = 0;
          BIO_printf(pBVar19,"bytes written:%8ld\n",uVar8);
        }
        goto LAB_000196dc;
      }
      iVar13 = BIO_write(b,data,iVar7);
    } while (iVar13 == iVar7);
    local_170 = 1;
    BIO_printf(bio_err,"error writing output file\n");
  }
  else if (local_174 == (BIO *)0x0) {
LAB_00019798:
    if (local_158 == (BIO *)0x0) {
      if ((uVar21 != 0) && (iVar7 = EVP_CIPHER_iv_length((EVP_CIPHER *)local_198), iVar7 != 0)) {
        local_170 = 1;
        BIO_printf(bio_err,"iv undefined\n");
        pBVar18 = local_158;
        goto LAB_000196dc;
      }
    }
    else {
      iVar7 = EVP_CIPHER_iv_length((EVP_CIPHER *)local_198);
      if (iVar7 == 0) {
        BIO_printf(bio_err,"warning: iv not use by this cipher\n");
      }
      else {
        pBVar18 = (BIO *)set_hex(local_158,auStack_130,0x10);
        if (pBVar18 == (BIO *)0x0) {
          local_170 = 1;
          BIO_printf(bio_err,"invalid hex iv value\n");
          goto LAB_000196dc;
        }
      }
    }
    if (local_168 != (byte *)0x0) {
      iVar7 = EVP_CIPHER_key_length((EVP_CIPHER *)local_198);
      pBVar18 = (BIO *)set_hex(local_168,auStack_f4,iVar7);
      if (pBVar18 == (BIO *)0x0) {
        local_170 = 1;
        BIO_printf(bio_err,"invalid hex key value\n");
        goto LAB_000196dc;
      }
    }
    pBVar10 = BIO_f_cipher();
    pBVar19 = BIO_new(pBVar10);
    pBVar18 = pBVar19;
    if (pBVar19 == (BIO *)0x0) {
      local_170 = 1;
    }
    else {
      BIO_ctrl(pBVar19,0x81,0,&local_144);
      if (local_178 != (byte *)0x0) {
        EVP_CIPHER_CTX_set_flags(local_144,0x8000);
      }
      iVar7 = EVP_CipherInit_ex(local_144,(EVP_CIPHER *)local_198,(ENGINE *)0x0,(uchar *)0x0,
                                (uchar *)0x0,(int)local_184);
      if (iVar7 != 0) {
        if (bVar5) {
          EVP_CIPHER_CTX_set_padding(local_144,0);
        }
        iVar7 = EVP_CipherInit_ex(local_144,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_f4,auStack_130,
                                  (int)local_184);
        if (iVar7 != 0) {
          if (bVar4) {
            BIO_set_callback(pBVar19,BIO_debug_callback + 1);
            BIO_set_callback_arg(pBVar19,(char *)bio_err);
          }
          if (local_164 != 0) {
            if (local_15c == (BIO *)0x0) {
              __printf_chk(1,"salt=");
              puVar20 = &uStack_139;
              do {
                puVar20 = puVar20 + 1;
                __printf_chk(1,&DAT_00126dd8,*puVar20);
              } while (puVar20 != local_138 + 7);
              putchar(10);
            }
            if (0 < (int)local_198->cb_arg) {
              __printf_chk(1,&DAT_00126de0);
              if (0 < (int)local_198->cb_arg) {
                iVar7 = 0;
                do {
                  puVar20 = auStack_f4 + iVar7;
                  iVar7 = iVar7 + 1;
                  __printf_chk(1,&DAT_00126dd8,*puVar20);
                } while (iVar7 < (int)local_198->cb_arg);
              }
              putchar(10);
            }
            if (0 < local_198->init) {
              __printf_chk(1,&DAT_00126de8);
              if (0 < local_198->init) {
                iVar7 = 0;
                do {
                  __printf_chk(1,&DAT_00126dd8,auStack_130[iVar7]);
                  iVar7 = iVar7 + 1;
                } while (iVar7 < local_198->init);
              }
              putchar(10);
            }
            if (local_164 == 2) {
              local_170 = 0;
              goto LAB_000196dc;
            }
          }
          local_190 = BIO_push(pBVar19,local_190);
          b = local_190;
          goto LAB_0001992c;
        }
      }
      pBVar19 = bio_err;
      local_170 = 1;
      iVar7 = EVP_CIPHER_nid((EVP_CIPHER *)local_198);
      pcVar14 = OBJ_nid2sn(iVar7);
      BIO_printf(pBVar19,"Error setting cipher %s\n",pcVar14);
      ERR_print_errors(bio_err);
    }
  }
  else {
    if (local_15c != (BIO *)0x0) {
      puVar20 = (uchar *)0x0;
LAB_00019760:
      sVar12 = strlen((char *)local_174);
      EVP_BytesToKey((EVP_CIPHER *)local_198,local_18c,puVar20,(uchar *)local_174,sVar12,1,
                     auStack_f4,auStack_130);
      if (local_174 == pBVar9) {
        OPENSSL_cleanse(pBVar9,0x200);
      }
      else {
        sVar12 = strlen((char *)local_174);
        OPENSSL_cleanse(local_174,sVar12);
      }
      goto LAB_00019798;
    }
    if (local_184 == (BIO *)0x0) {
      iVar7 = BIO_read(local_188,auStack_140,8);
      if (iVar7 == 8) {
        puVar20 = local_138;
        iVar7 = BIO_read(local_188,puVar20,8);
        if (iVar7 == 8) {
          iVar7 = memcmp(auStack_140,"Salted__",8);
          if (iVar7 != 0) {
            local_170 = 1;
            BIO_printf(bio_err,"bad magic number\n");
            pBVar18 = local_184;
            goto LAB_000196dc;
          }
          goto LAB_00019760;
        }
      }
      pBVar18 = (BIO *)0x0;
      BIO_printf(bio_err,"error reading input file\n");
      local_170 = 1;
    }
    else if (local_154 == (BIO *)0x0) {
      iVar7 = RAND_bytes(local_138,8);
      if (0 < iVar7) goto LAB_000196ac;
      local_170 = 1;
      pBVar18 = local_154;
    }
    else {
      iVar7 = set_hex(local_154,local_138,8);
      if (iVar7 == 0) {
        local_170 = 1;
        BIO_printf(bio_err,"invalid hex salt value\n");
        pBVar18 = local_15c;
      }
      else {
LAB_000196ac:
        puVar20 = local_138;
        if ((local_164 == 2) ||
           ((iVar7 = BIO_write(local_190,"Salted__",8), iVar7 == 8 &&
            (iVar7 = BIO_write(local_190,puVar20,8), iVar7 == 8)))) goto LAB_00019760;
        BIO_printf(bio_err,"error writing output file\n");
        local_170 = 1;
        pBVar18 = (BIO *)0x0;
      }
    }
  }
LAB_000196dc:
  ERR_print_errors(bio_err);
LAB_0001956e:
  CRYPTO_free(pBVar9);
  pBVar9 = pBVar18;
LAB_00019574:
  if (data != (void *)0x0) {
    CRYPTO_free(data);
  }
  if (pBVar17 != (BIO *)0x0) {
    BIO_free(pBVar17);
  }
  if (local_19c != (BIO *)0x0) {
    BIO_free_all(local_19c);
  }
  if (pBVar9 != (BIO *)0x0) {
    BIO_free(pBVar9);
  }
  if (local_160 != (BIO *)0x0) {
    BIO_free(local_160);
  }
  goto LAB_00018ffa;
}

