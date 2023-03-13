
/* WARNING: Could not reconcile some variable overlaps */

undefined4 enc_main(int param_1,undefined4 *param_2)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  EVP_CIPHER *pEVar4;
  EVP_CIPHER *pEVar5;
  int iVar6;
  ulong uVar7;
  EVP_MD *md;
  FILE *pFVar8;
  BIO_METHOD *pBVar9;
  FILE *pFVar10;
  long lVar11;
  size_t sVar12;
  int iVar13;
  char *pcVar14;
  FILE *pFVar15;
  undefined4 uVar16;
  FILE **ppFVar17;
  FILE *pFVar18;
  FILE *pFVar19;
  FILE *pFVar20;
  int in_GS_OFFSET;
  undefined uVar21;
  undefined uVar22;
  bool bVar23;
  byte bVar24;
  char *pcVar25;
  FILE *pFVar26;
  byte *pbVar27;
  byte *pbVar28;
  uint uVar29;
  undefined auStack_19c [4];
  FILE *local_198;
  FILE *local_194;
  FILE *local_190;
  FILE *local_18c;
  FILE *local_188;
  FILE *local_184;
  EVP_CIPHER *local_180;
  FILE *local_17c;
  FILE *local_178;
  FILE *local_174;
  undefined1 *local_170;
  int local_16c;
  int local_168;
  int local_164;
  FILE *local_160;
  FILE *local_15c;
  int local_158;
  int local_154;
  FILE *local_150;
  int local_14c;
  int local_148;
  int local_144;
  FILE *local_140;
  FILE *local_138;
  EVP_CIPHER_CTX *local_134;
  undefined local_130 [8];
  byte local_128 [8];
  byte local_120 [16];
  char local_110;
  char local_10f;
  char local_10e;
  char local_10d;
  FILE local_e8;
  int local_20;
  
  bVar24 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_138 = (FILE *)0x0;
  local_134 = (EVP_CIPHER_CTX *)0x0;
  signal(0xd,(__sighandler_t)0x1);
  if (bio_err == (BIO *)0x0) {
    pBVar9 = BIO_s_file();
    bio_err = BIO_new(pBVar9);
    if (bio_err != (BIO *)0x0) {
      BIO_ctrl(bio_err,0x6a,0x10,stderr);
    }
  }
  iVar6 = load_config(bio_err,0);
  if (iVar6 == 0) goto LAB_08053fcb;
  uVar21 = auStack_19c < &DAT_00000004;
  uVar22 = &stack0x00000000 == (undefined *)0x1a0;
  pFVar26 = (FILE *)&DAT_00000028;
  pFVar15 = (FILE *)&local_110;
  program_name(*param_2,pFVar15,0x28);
  iVar6 = 7;
  pFVar10 = pFVar15;
  pbVar27 = (byte *)0x81ecec2;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    uVar21 = *(byte *)&pFVar10->_flags < *pbVar27;
    uVar22 = *(byte *)&pFVar10->_flags == *pbVar27;
    pFVar10 = (FILE *)((int)pFVar10 + (uint)bVar24 * -2 + 1);
    pbVar27 = pbVar27 + (uint)bVar24 * -2 + 1;
  } while ((bool)uVar22);
  if ((!(bool)uVar21 && !(bool)uVar22) == (bool)uVar21) {
    local_180 = EVP_get_cipherbyname((char *)pFVar15);
    local_158 = 1;
    pFVar15 = pFVar26;
  }
  else {
    local_180 = EVP_get_cipherbyname((char *)pFVar15);
    if ((local_180 == (EVP_CIPHER *)0x0) &&
       ((((local_110 != 'e' || (local_10f != 'n')) || (local_10e != 'c')) || (local_10d != '\0'))))
    {
      BIO_printf(bio_err,"%s is an unknown cipher\n",pFVar15);
LAB_0805429d:
      BIO_printf(bio_err,"options are\n",pFVar15);
      BIO_printf(bio_err,"%-14s input file\n","-in <file>");
      BIO_printf(bio_err,"%-14s output file\n","-out <file>");
      BIO_printf(bio_err,"%-14s pass phrase source\n","-pass <arg>");
      BIO_printf(bio_err,"%-14s encrypt\n",&DAT_081ece9a);
      BIO_printf(bio_err,"%-14s decrypt\n",&DAT_081eceac);
      BIO_printf(bio_err,"%-14s base64 encode/decode, depending on encryption flag\n","-a/-base64");
      BIO_printf(bio_err,"%-14s passphrase is the next argument\n",&DAT_081ecec9);
      BIO_printf(bio_err,"%-14s passphrase is the first line of the file argument\n","-kfile");
      BIO_printf(bio_err,"%-14s the next argument is the md to use to create a key\n",&DAT_081ececc)
      ;
      BIO_printf(bio_err,"%-14s   from a passphrase.  One of md2, md5, sha or sha1\n",&DAT_081eca46)
      ;
      BIO_printf(bio_err,"%-14s salt in hex is the next argument\n",&DAT_081eced0);
      BIO_printf(bio_err,"%-14s key/iv in hex is the next argument\n","-K/-iv");
      BIO_printf(bio_err,"%-14s print the iv/key (then exit if -P)\n","-[pP]");
      BIO_printf(bio_err,"%-14s buffer size\n","-bufsize <n>");
      BIO_printf(bio_err,"%-14s disable standard block padding\n","-nopad");
      BIO_printf(bio_err,"%-14s use engine e, possibly a hardware device.\n","-engine e");
      BIO_printf(bio_err,"Cipher Types\n");
      OBJ_NAME_do_all_sorted(2,show_ciphers,bio_err);
      BIO_printf(bio_err,"\n");
      goto LAB_08053fcb;
    }
    local_158 = 0;
    pFVar15 = pFVar26;
  }
  ppFVar17 = (FILE **)(param_2 + 1);
  local_144 = 0;
  local_17c = (FILE *)0x0;
  local_188 = (FILE *)0x0;
  local_18c = (FILE *)0x0;
  local_154 = 0;
  pFVar10 = (FILE *)(param_1 + -1);
  local_148 = 0;
  local_164 = 0;
  local_168 = 0;
  local_190 = (FILE *)0x1;
  local_174 = (FILE *)0x0;
  local_150 = (FILE *)0x0;
  local_160 = (FILE *)0x0;
  local_15c = (FILE *)0x0;
  local_184 = (FILE *)0x0;
  local_170 = (undefined1 *)0x0;
  local_14c = 0;
  local_16c = 0;
  local_178 = (FILE *)0x0;
  if (0 < (int)pFVar10) {
LAB_0805413f:
    pFVar26 = *ppFVar17;
    local_198 = (FILE *)(0x2d - (uint)*(byte *)&pFVar26->_flags);
    bVar23 = local_198 == (FILE *)0x0;
    local_194 = (FILE *)((uint)local_194 & 0xffffff00 | (uint)*(byte *)&pFVar26->_flags);
    if (bVar23) {
      cVar1 = *(char *)((int)&pFVar26->_flags + 1);
      if (cVar1 == 'e') {
        bVar23 = *(char *)((int)&pFVar26->_flags + 2) == '\0';
        if (!bVar23) goto LAB_08054110;
        local_190 = (FILE *)0x1;
      }
      else {
        bVar23 = cVar1 == 'i';
        if (((!bVar23) || (bVar23 = *(char *)((int)&pFVar26->_flags + 2) == 'n', !bVar23)) ||
           (bVar23 = *(char *)((int)&pFVar26->_flags + 3) == '\0', !bVar23)) goto LAB_08054110;
        pFVar10 = (FILE *)(pFVar10[-1]._unused2 + 0x27);
        if (pFVar10 == (FILE *)0x0) goto LAB_0805429d;
        local_18c = ppFVar17[1];
        ppFVar17 = ppFVar17 + 1;
      }
    }
    else {
LAB_08054110:
      iVar6 = 5;
      pFVar8 = pFVar26;
      pcVar25 = "-out";
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar23 = *(char *)&pFVar8->_flags == *pcVar25;
        pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar24 * -2 + 1);
        pcVar25 = pcVar25 + (uint)bVar24 * -2 + 1;
      } while (bVar23);
      if (bVar23) {
        if ((FILE *)(pFVar10[-1]._unused2 + 0x27) == (FILE *)0x0) goto LAB_0805429d;
        local_188 = ppFVar17[1];
        ppFVar17 = ppFVar17 + 1;
        pFVar10 = (FILE *)(pFVar10[-1]._unused2 + 0x27);
      }
      else {
        iVar6 = 6;
        pFVar8 = pFVar26;
        pcVar25 = "-pass";
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar23 = *(char *)&pFVar8->_flags == *pcVar25;
          pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar24 * -2 + 1);
          pcVar25 = pcVar25 + (uint)bVar24 * -2 + 1;
        } while (bVar23);
        if (bVar23) {
          if ((FILE *)(pFVar10[-1]._unused2 + 0x27) == (FILE *)0x0) goto LAB_0805429d;
          local_184 = ppFVar17[1];
          ppFVar17 = ppFVar17 + 1;
          pFVar10 = (FILE *)(pFVar10[-1]._unused2 + 0x27);
        }
        else {
          iVar6 = 8;
          pFVar8 = pFVar26;
          pcVar25 = "-engine";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar23 = *(char *)&pFVar8->_flags == *pcVar25;
            pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar24 * -2 + 1);
            pcVar25 = pcVar25 + (uint)bVar24 * -2 + 1;
          } while (bVar23);
          if (bVar23) {
            if ((FILE *)(pFVar10[-1]._unused2 + 0x27) == (FILE *)0x0) goto LAB_0805429d;
            local_17c = ppFVar17[1];
            ppFVar17 = ppFVar17 + 1;
            pFVar10 = (FILE *)(pFVar10[-1]._unused2 + 0x27);
          }
          else {
            bVar23 = local_198 == (FILE *)0x0;
            if (bVar23) {
              cVar1 = *(char *)((int)&pFVar26->_flags + 1);
              if (cVar1 != 'd') {
                if (cVar1 == 'p') {
                  bVar23 = *(char *)((int)&pFVar26->_flags + 2) == '\0';
                  if (!bVar23) goto LAB_0805451c;
                  local_168 = 1;
                }
                else {
                  bVar23 = cVar1 == 'v';
                  if ((!bVar23) || (bVar23 = *(char *)((int)&pFVar26->_flags + 2) == '\0', !bVar23))
                  goto LAB_0805451c;
                  local_16c = 1;
                }
                goto joined_r0x0805413d;
              }
              bVar23 = *(char *)((int)&pFVar26->_flags + 2) == '\0';
              if (bVar23) {
                local_190 = (FILE *)0x0;
                goto joined_r0x0805413d;
              }
            }
LAB_0805451c:
            iVar6 = 7;
            pFVar8 = pFVar26;
            pcVar25 = "-nopad";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar23 = *(char *)&pFVar8->_flags == *pcVar25;
              pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar24 * -2 + 1);
              pcVar25 = pcVar25 + (uint)bVar24 * -2 + 1;
            } while (bVar23);
            if (bVar23) {
              local_14c = 1;
            }
            else {
              iVar6 = 6;
              pFVar8 = pFVar26;
              pcVar25 = "-salt";
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar23 = *(char *)&pFVar8->_flags == *pcVar25;
                pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar24 * -2 + 1);
                pcVar25 = pcVar25 + (uint)bVar24 * -2 + 1;
              } while (bVar23);
              if (bVar23) {
                local_154 = 0;
              }
              else {
                iVar6 = 8;
                pFVar8 = pFVar26;
                pcVar25 = "-nosalt";
                do {
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  bVar23 = *(char *)&pFVar8->_flags == *pcVar25;
                  pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar24 * -2 + 1);
                  pcVar25 = pcVar25 + (uint)bVar24 * -2 + 1;
                } while (bVar23);
                if (bVar23) {
                  local_154 = 1;
                }
                else {
                  iVar6 = 7;
                  pFVar8 = pFVar26;
                  pFVar18 = (FILE *)&DAT_081ece03;
                  do {
                    pFVar19 = pFVar8;
                    pFVar20 = pFVar18;
                    if (iVar6 == 0) break;
                    iVar6 = iVar6 + -1;
                    pFVar20 = (FILE *)((int)pFVar18 + (uint)bVar24 * -2 + 1);
                    pFVar19 = (FILE *)((int)pFVar8 + (uint)bVar24 * -2 + 1);
                    bVar23 = *(char *)&pFVar8->_flags == *(char *)&pFVar18->_flags;
                    pFVar8 = pFVar19;
                    pFVar18 = pFVar20;
                  } while (bVar23);
                  if (bVar23) {
                    local_164 = 1;
                  }
                  else {
                    if (local_198 == (FILE *)0x0) {
                      cVar1 = *(char *)((int)&pFVar26->_flags + 1);
                      if (cVar1 == 'P') {
                        if (*(char *)((int)&pFVar26->_flags + 2) == '\0') {
                          local_168 = 2;
                          goto joined_r0x0805413d;
                        }
                        goto LAB_08054578;
                      }
                      if (cVar1 == 'A') {
                        if (*(char *)((int)&pFVar26->_flags + 2) == '\0') {
                          local_148 = 1;
                          goto joined_r0x0805413d;
                        }
                        goto LAB_08054578;
                      }
                      if ((cVar1 != 'a') || (*(char *)((int)&pFVar26->_flags + 2) != '\0'))
                      goto LAB_08054578;
                    }
                    else {
LAB_08054578:
                      pFVar15 = pFVar10;
                      local_140 = pFVar10;
                      pFVar8 = (FILE *)strcmp((char *)pFVar26,"-base64");
                      pFVar10 = local_140;
                      if (pFVar8 != (FILE *)0x0) {
                        pFVar15 = (FILE *)strcmp((char *)pFVar26,"-bufsize");
                        if (pFVar15 == (FILE *)0x0) {
                          pFVar15 = pFVar8;
                          if ((FILE *)(local_140[-1]._unused2 + 0x27) == (FILE *)0x0)
                          goto LAB_0805429d;
                          local_178 = ppFVar17[1];
                          ppFVar17 = ppFVar17 + 1;
                          pFVar10 = (FILE *)(local_140[-1]._unused2 + 0x27);
                        }
                        else {
                          if (local_198 != (FILE *)0x0) {
                            local_198 = local_140;
                            pFVar10 = (FILE *)strcmp((char *)pFVar26,"-kfile");
                            if (pFVar10 != (FILE *)0x0) goto LAB_0805547d;
LAB_080553a7:
                            local_198 = (FILE *)(local_198[-1]._unused2 + 0x27);
                            if (local_198 == (FILE *)0x0) goto LAB_0805429d;
                            pFVar10 = ppFVar17[1];
                            ppFVar17 = ppFVar17 + 1;
                            pFVar8 = fopen((char *)pFVar10,"r");
                            pFVar26 = pFVar8;
                            if (pFVar8 != (FILE *)0x0) {
                              buf_16523[0] = 0;
                              pFVar15 = pFVar8;
                              pFVar26 = (FILE *)fgets(buf_16523,0x80,pFVar8);
                              if (pFVar26 != (FILE *)0x0) {
                                fclose(pFVar8);
                                uVar29 = 0xffffffff;
                                pcVar25 = buf_16523;
                                do {
                                  if (uVar29 == 0) break;
                                  uVar29 = uVar29 - 1;
                                  cVar1 = *pcVar25;
                                  pcVar25 = pcVar25 + (uint)bVar24 * -2 + 1;
                                } while (cVar1 != '\0');
                                pFVar26 = (FILE *)~uVar29;
                                pFVar10 = pFVar26;
                                if (0 < (int)(pFVar26[-1]._unused2 + 0x27)) {
                                  pFVar10 = (FILE *)(pFVar26[-1]._unused2 + 0x26);
                                  cVar1 = *(char *)((int)&pFVar26[0xe2947]._IO_write_base + 2);
                                  if ((cVar1 != '\n') && (cVar1 != '\r')) {
LAB_0805544e:
                                    local_170 = buf_16523;
                                    pFVar10 = local_198;
                                    goto joined_r0x0805413d;
                                  }
                                  *(undefined *)((int)&pFVar26[0xe2947]._IO_write_base + 2) = 0;
                                  if (pFVar10 != (FILE *)0x0) {
                                    pFVar10 = (FILE *)(pFVar26[-1]._unused2 + 0x25);
                                    cVar1 = *(char *)((int)&pFVar26[0xe2947]._IO_write_base + 1);
                                    if (((cVar1 != '\n') && (cVar1 != '\r')) ||
                                       (*(undefined *)((int)&pFVar26[0xe2947]._IO_write_base + 1) =
                                             0, pFVar10 != (FILE *)0x0)) goto LAB_0805544e;
                                  }
                                }
                                BIO_printf(bio_err,"zero length password\n",pFVar10,pFVar10);
                                pFVar15 = pFVar10;
                                goto LAB_0805429d;
                              }
                            }
                            BIO_printf(bio_err,"unable to read key from \'%s\'\n",pFVar10,pFVar26);
                            pFVar15 = pFVar10;
                            goto LAB_0805429d;
                          }
                          if ((*(char *)((int)&pFVar26->_flags + 1) == 'k') &&
                             (*(char *)((int)&pFVar26->_flags + 2) == '\0')) {
                            pFVar15 = pFVar8;
                            if ((FILE *)(local_140[-1]._unused2 + 0x27) != (FILE *)0x0) {
                              local_170 = (undefined1 *)ppFVar17[1];
                              ppFVar17 = ppFVar17 + 1;
                              pFVar10 = (FILE *)(local_140[-1]._unused2 + 0x27);
                              goto joined_r0x0805413d;
                            }
                            goto LAB_0805429d;
                          }
                          local_198 = local_140;
                          pFVar15 = local_140;
                          iVar6 = strcmp((char *)pFVar26,"-kfile");
                          if (iVar6 == 0) goto LAB_080553a7;
                          bVar2 = *(byte *)((int)&pFVar26->_flags + 1);
                          pFVar10 = (FILE *)(uint)bVar2;
                          if (bVar2 == 0x4b) {
                            if (*(char *)((int)&pFVar26->_flags + 2) != '\0') goto LAB_0805547d;
                            if ((FILE *)(local_198[-1]._unused2 + 0x27) == (FILE *)0x0)
                            goto LAB_0805429d;
                            local_15c = ppFVar17[1];
                            ppFVar17 = ppFVar17 + 1;
                            pFVar10 = (FILE *)(local_198[-1]._unused2 + 0x27);
                          }
                          else if (bVar2 == 0x53) {
                            if (*(char *)((int)&pFVar26->_flags + 2) != '\0') goto LAB_0805547d;
                            pFVar10 = (FILE *)(local_198[-1]._unused2 + 0x27);
                            if (pFVar10 == (FILE *)0x0) goto LAB_0805429d;
                            local_150 = ppFVar17[1];
                            ppFVar17 = ppFVar17 + 1;
                          }
                          else if (bVar2 == 0x69) {
                            if ((*(char *)((int)&pFVar26->_flags + 2) == 'v') &&
                               (*(char *)((int)&pFVar26->_flags + 3) == '\0')) {
                              pFVar10 = (FILE *)(local_198[-1]._unused2 + 0x27);
                              if (pFVar10 == (FILE *)0x0) goto LAB_0805429d;
                              local_160 = ppFVar17[1];
                              ppFVar17 = ppFVar17 + 1;
                            }
                            else {
LAB_0805547d:
                              iVar6 = strcmp((char *)pFVar26,"-non-fips-allow");
                              if (iVar6 == 0) {
                                local_144 = 1;
                                pFVar15 = pFVar10;
                                pFVar10 = local_198;
                              }
                              else {
                                if ((char)local_194 == '-') {
                                  local_180 = EVP_get_cipherbyname
                                                        ((char *)((int)&pFVar26->_flags + 1));
                                  pFVar15 = pFVar10;
                                  pFVar10 = local_198;
                                  if (local_180 != (EVP_CIPHER *)0x0) goto joined_r0x0805413d;
                                  pFVar26 = *ppFVar17;
                                }
                                iVar6 = strcmp((char *)pFVar26,"-none");
                                if (iVar6 != 0) {
                                  BIO_printf(bio_err,"unknown option \'%s\'\n",pFVar26,pFVar19);
                                  pFVar15 = pFVar26;
                                  goto LAB_0805429d;
                                }
                                local_180 = (EVP_CIPHER *)0x0;
                                pFVar15 = pFVar20;
                                pFVar10 = local_198;
                              }
                            }
                          }
                          else {
                            if (((bVar2 != 0x6d) || (*(char *)((int)&pFVar26->_flags + 2) != 'd'))
                               || (*(char *)((int)&pFVar26->_flags + 3) != '\0')) goto LAB_0805547d;
                            pFVar10 = (FILE *)(local_198[-1]._unused2 + 0x27);
                            if (pFVar10 == (FILE *)0x0) goto LAB_0805429d;
                            local_174 = ppFVar17[1];
                            ppFVar17 = ppFVar17 + 1;
                          }
                        }
                        goto joined_r0x0805413d;
                      }
                    }
                    local_158 = 1;
                  }
                }
              }
            }
          }
        }
      }
    }
joined_r0x0805413d:
    pFVar10 = (FILE *)(pFVar10[-1]._unused2 + 0x27);
    ppFVar17 = ppFVar17 + 1;
    if (pFVar10 == (FILE *)0x0) goto LAB_08054178;
    goto LAB_0805413f;
  }
LAB_08054178:
  setup_engine(bio_err,local_17c,0);
  if (local_180 != (EVP_CIPHER *)0x0) {
    uVar7 = EVP_CIPHER_flags(local_180);
    if ((uVar7 & 0x200000) == 0) {
      uVar7 = EVP_CIPHER_flags(local_180);
      if ((uVar7 & 0xf0007) != 0x10001) goto LAB_080541cd;
      BIO_printf(bio_err,"Ciphers in XTS mode are not supported by the enc utility\n");
    }
    else {
      BIO_printf(bio_err,"AEAD ciphers not supported by the enc utility\n");
    }
LAB_08053fcb:
    uVar16 = 1;
    ERR_print_errors(bio_err);
    goto LAB_08053fe1;
  }
LAB_080541cd:
  if (local_174 == (FILE *)0x0) {
    md = EVP_md5();
  }
  else {
    md = EVP_get_digestbyname((char *)local_174);
    if (md == (EVP_MD *)0x0) {
      BIO_printf(bio_err,"%s is an unsupported message digest type\n",local_174);
      goto LAB_08053fcb;
    }
  }
  if (local_178 == (FILE *)0x0) {
    iVar6 = 0x2c52;
    local_174 = (FILE *)0x2000;
  }
  else {
    bVar24 = *(byte *)&local_178->_flags;
    if (bVar24 == 0) {
      bVar23 = true;
      pFVar15 = (FILE *)0x0;
    }
    else {
      pFVar15 = (FILE *)0x0;
      do {
        if (bVar24 - 0x30 < 10) {
          pFVar15 = (FILE *)((bVar24 - 0x30) + (int)pFVar15 * 10);
        }
        else if (bVar24 == 0x6b) {
          if (*(char *)((int)&local_178->_flags + 1) != '\0') {
            BIO_printf(bio_err,"invalid \'bufsize\' specified.\n");
            goto LAB_08053fcb;
          }
          pFVar15 = (FILE *)((int)pFVar15 * 0x400);
          local_178 = (FILE *)((int)&local_178->_flags + 1);
          bVar23 = pFVar15 < (FILE *)0x50;
          goto LAB_08054634;
        }
        local_178 = (FILE *)((int)&local_178->_flags + 1);
        bVar24 = *(byte *)&local_178->_flags;
      } while (bVar24 != 0);
      bVar23 = pFVar15 < (FILE *)0x50;
    }
LAB_08054634:
    if (local_158 == 0) {
LAB_08054975:
      iVar6 = ((int)pFVar15 / 0x30 + 0x29 + ((int)((int)&pFVar15->_flags + 2) / 3) * 2) * 2;
      local_174 = pFVar15;
    }
    else {
      iVar6 = 0xc0;
      local_174 = (FILE *)0x50;
      if (!bVar23) goto LAB_08054975;
    }
    if (local_16c != 0) {
      BIO_printf(bio_err,"bufsize=%d\n",local_174);
    }
  }
  pFVar15 = (FILE *)CRYPTO_malloc(0x200,"enc.c",0x179);
  local_194 = pFVar15;
  local_198 = (FILE *)CRYPTO_malloc(iVar6,"enc.c",0x17a);
  if ((local_198 == (FILE *)0x0) || (pFVar15 == (FILE *)0x0)) {
    BIO_printf(bio_err,"OPENSSL_malloc failure %ld\n",iVar6);
    ERR_print_errors(bio_err);
    if (local_194 != (FILE *)0x0) {
      CRYPTO_free(local_194);
    }
    if (local_198 == (FILE *)0x0) {
      uVar16 = 1;
      goto LAB_08053fe1;
    }
    pFVar15 = (FILE *)0x0;
    pFVar10 = (FILE *)0x0;
    local_17c = (FILE *)0x0;
    uVar16 = 1;
    pFVar26 = (FILE *)0x0;
  }
  else {
    pBVar9 = BIO_s_file();
    pFVar10 = (FILE *)BIO_new(pBVar9);
    pBVar9 = BIO_s_file();
    local_17c = (FILE *)BIO_new(pBVar9);
    if (pFVar10 == (FILE *)0x0 || local_17c == (FILE *)0x0) {
      pFVar26 = (FILE *)0x0;
      pFVar15 = (FILE *)0x0;
      uVar16 = 1;
      ERR_print_errors(bio_err);
    }
    else {
      if (local_164 != 0) {
        BIO_set_callback((BIO *)pFVar10,BIO_debug_callback);
        pFVar15 = local_17c;
        BIO_set_callback((BIO *)local_17c,BIO_debug_callback);
        BIO_set_callback_arg((BIO *)pFVar10,(char *)bio_err);
        BIO_set_callback_arg((BIO *)pFVar15,(char *)bio_err);
      }
      if (local_18c == (FILE *)0x0) {
        if (local_178 != (FILE *)0x0) {
          setvbuf(stdin,(char *)0x0,2,0);
        }
        BIO_ctrl((BIO *)pFVar10,0x6a,0,stdin);
LAB_0805470f:
        bVar23 = (FILE *)local_170 == (FILE *)0x0;
        if ((local_184 == (FILE *)0x0) || (!bVar23)) {
LAB_08054728:
          bVar3 = (bool)(local_180 != (EVP_CIPHER *)0x0 & bVar23);
          if ((!bVar3) || (local_170 = (undefined1 *)0x0, bVar23 = bVar3, local_15c != (FILE *)0x0))
          {
LAB_0805474b:
            if (local_188 == (FILE *)0x0) {
              pbVar27 = (byte *)0x0;
              BIO_ctrl((BIO *)local_17c,0x6a,0,stdout);
              if (local_178 != (FILE *)0x0) {
                pbVar27 = (byte *)0x2;
                setvbuf(stdout,(char *)0x0,2,0);
              }
            }
            else {
              pbVar27 = (byte *)0x5;
              lVar11 = BIO_ctrl((BIO *)local_17c,0x6c,5,local_188);
              pFVar15 = local_188;
              if (lVar11 < 1) goto LAB_08054fde;
            }
            if (local_158 != 0) {
              pBVar9 = BIO_f_base64();
              pFVar15 = (FILE *)BIO_new(pBVar9);
              if (pFVar15 != (FILE *)0x0) {
                if (local_164 != 0) {
                  BIO_set_callback((BIO *)pFVar15,BIO_debug_callback);
                  BIO_set_callback_arg((BIO *)pFVar15,(char *)bio_err);
                }
                if (local_148 != 0) {
                  BIO_set_flags((BIO *)pFVar15,0x100);
                }
                if (local_190 == (FILE *)0x0) {
                  local_188 = (FILE *)BIO_push((BIO *)pFVar15,(BIO *)pFVar10);
                  local_18c = local_17c;
                }
                else {
                  local_18c = (FILE *)BIO_push((BIO *)pFVar15,(BIO *)local_17c);
                  local_188 = pFVar10;
                }
                goto LAB_0805478d;
              }
LAB_080551d0:
              pFVar26 = (FILE *)0x0;
              uVar16 = 1;
              goto LAB_0805482b;
            }
            pFVar15 = (FILE *)0x0;
            local_18c = local_17c;
            local_188 = pFVar10;
LAB_0805478d:
            if (local_180 == (EVP_CIPHER *)0x0) {
              local_184 = (FILE *)0x0;
              pFVar8 = local_198;
              pFVar18 = local_18c;
              pFVar19 = local_188;
              local_190 = pFVar15;
              local_188 = pFVar10;
LAB_08054dc6:
              do {
                iVar6 = BIO_read((BIO *)pFVar19,pFVar8,(int)local_174);
                pFVar26 = local_184;
                pFVar10 = local_188;
                pFVar15 = local_190;
                if (iVar6 < 1) {
                  lVar11 = BIO_ctrl((BIO *)local_18c,0xb,0,(void *)0x0);
                  if (lVar11 == 0) {
                    uVar16 = 1;
                    BIO_printf(bio_err,"bad decrypt\n");
                  }
                  else {
                    uVar16 = 0;
                    if (local_16c != 0) {
                      uVar7 = BIO_number_read((BIO *)pFVar10);
                      BIO_printf(bio_err,"bytes read   :%8ld\n",uVar7);
                      uVar7 = BIO_number_written((BIO *)local_17c);
                      BIO_printf(bio_err,"bytes written:%8ld\n",uVar7);
                    }
                  }
                  goto LAB_0805482b;
                }
                iVar13 = BIO_write((BIO *)pFVar18,pFVar8,iVar6);
                pFVar26 = local_184;
                pFVar10 = local_188;
                pFVar15 = local_190;
              } while (iVar6 == iVar13);
              uVar16 = 1;
              BIO_printf(bio_err,"error writing output file\n");
            }
            else if ((FILE *)local_170 == (FILE *)0x0) {
              if (local_160 == (FILE *)0x0) {
                if ((bVar23) && (iVar6 = EVP_CIPHER_iv_length(local_180), iVar6 != 0)) {
                  pcVar25 = "iv undefined\n";
                  goto LAB_08054816;
                }
              }
              else {
LAB_08054b66:
                iVar6 = EVP_CIPHER_iv_length(local_180);
                if (iVar6 == 0) {
                  BIO_printf(bio_err,"warning: iv not use by this cipher\n");
                }
                else {
                  pbVar27 = &DAT_00000010;
                  iVar6 = set_hex(local_160,local_120,0x10);
                  if (iVar6 == 0) {
                    pcVar25 = "invalid hex iv value\n";
                    goto LAB_08054816;
                  }
                }
              }
LAB_08054b93:
              if (local_15c != (FILE *)0x0) {
                pbVar27 = (byte *)EVP_CIPHER_key_length(local_180);
                iVar6 = set_hex(local_15c,&local_e8,pbVar27);
                if (iVar6 == 0) {
                  pcVar25 = "invalid hex key value\n";
                  goto LAB_08054816;
                }
              }
              pBVar9 = BIO_f_cipher();
              uVar16 = 1;
              pFVar26 = (FILE *)BIO_new(pBVar9);
              if (pFVar26 != (FILE *)0x0) {
                uVar29 = 0;
                BIO_ctrl((BIO *)pFVar26,0x81,0,&local_134);
                if (local_144 != 0) {
                  EVP_CIPHER_CTX_set_flags(local_134,0x8000);
                }
                iVar6 = EVP_CipherInit_ex(local_134,local_180,(ENGINE *)0x0,(uchar *)0x0,
                                          (uchar *)0x0,(int)local_190);
                if (iVar6 != 0) {
                  if (local_14c != 0) {
                    EVP_CIPHER_CTX_set_padding(local_134,0);
                  }
                  pFVar8 = local_190;
                  local_190 = &local_e8;
                  iVar6 = EVP_CipherInit_ex(local_134,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                            (uchar *)local_190,local_120,(int)pFVar8);
                  if (iVar6 != 0) {
                    if (local_164 != 0) {
                      BIO_set_callback((BIO *)pFVar26,BIO_debug_callback);
                      BIO_set_callback_arg((BIO *)pFVar26,(char *)bio_err);
                    }
                    if (local_168 != 0) {
                      if (local_154 == 0) {
                        uVar16 = 1;
                        __printf_chk(1,"salt=",1,1);
                        pbVar27 = local_128;
                        do {
                          uVar29 = (uint)*pbVar27;
                          pbVar27 = pbVar27 + 1;
                          __printf_chk(1,&DAT_08226f10,uVar29,uVar16);
                        } while (pbVar27 != local_120);
                        putchar(10);
                      }
                      pEVar4 = local_180;
                      if (0 < local_180->key_len) {
                        __printf_chk(1,&DAT_081ed04b,uVar29);
                        pEVar5 = local_180;
                        if (0 < pEVar4->key_len) {
                          iVar6 = 0;
                          local_184 = pFVar15;
                          do {
                            uVar29 = (uint)(byte)local_190->_shortbuf[iVar6 + -0x47];
                            iVar6 = iVar6 + 1;
                            __printf_chk(1,&DAT_08226f10,uVar29);
                            pFVar15 = local_184;
                          } while (pEVar5->key_len != iVar6 && iVar6 <= pEVar5->key_len);
                        }
                        putchar(10);
                      }
                      if (0 < local_180->iv_len) {
                        iVar6 = 0;
                        __printf_chk(1,&DAT_081ed050,uVar29);
                        if (0 < local_180->iv_len) {
                          do {
                            pbVar27 = local_120 + iVar6;
                            iVar6 = iVar6 + 1;
                            __printf_chk(1,&DAT_08226f10,*pbVar27);
                          } while (local_180->iv_len != iVar6 && iVar6 <= local_180->iv_len);
                        }
                        putchar(10);
                      }
                      uVar16 = 0;
                      if (local_168 == 2) goto LAB_0805482b;
                    }
                    local_18c = (FILE *)BIO_push((BIO *)pFVar26,(BIO *)local_18c);
                    pFVar8 = local_198;
                    pFVar18 = local_18c;
                    pFVar19 = local_188;
                    local_190 = pFVar15;
                    local_188 = pFVar10;
                    local_184 = pFVar26;
                    goto LAB_08054dc6;
                  }
                }
                iVar6 = EVP_CIPHER_nid(local_180);
                pcVar25 = OBJ_nid2sn(iVar6);
                BIO_printf(bio_err,"Error setting cipher %s\n",pcVar25);
                uVar16 = 1;
                ERR_print_errors(bio_err);
              }
            }
            else {
              if (local_154 != 0) {
                pbVar27 = (byte *)0x0;
LAB_08054b04:
                sVar12 = strlen(local_170);
                EVP_BytesToKey(local_180,md,pbVar27,local_170,sVar12,1,(uchar *)&local_e8,local_120)
                ;
                pFVar26 = (FILE *)local_170;
                if ((FILE *)local_170 == local_194) {
                  OPENSSL_cleanse(local_194,0x200);
                }
                else {
                  sVar12 = strlen(local_170);
                  OPENSSL_cleanse(pFVar26,sVar12);
                }
                if (local_160 != (FILE *)0x0) goto LAB_08054b66;
                goto LAB_08054b93;
              }
              if (local_190 == (FILE *)0x0) {
                pbVar28 = &DAT_00000008;
                iVar6 = BIO_read((BIO *)local_188,local_130,8);
                if (iVar6 == 8) {
                  pbVar28 = &DAT_00000008;
                  pbVar27 = local_128;
                  iVar6 = BIO_read((BIO *)local_188,pbVar27,8);
                  if (iVar6 == 8) {
                    iVar6 = memcmp(local_130,"Salted__",8);
                    if (iVar6 != 0) {
                      pcVar25 = "bad magic number\n";
                      goto LAB_08054816;
                    }
                    goto LAB_08054b04;
                  }
                }
                pbVar27 = pbVar28;
                pcVar25 = "error reading input file\n";
              }
              else {
                if (local_150 == (FILE *)0x0) {
                  iVar6 = RAND_bytes(local_128,8);
                  if (iVar6 < 1) goto LAB_080551d0;
                }
                else {
                  pbVar27 = &DAT_00000008;
                  iVar6 = set_hex(local_150,local_128,8);
                  if (iVar6 == 0) {
                    pcVar25 = "invalid hex salt value\n";
                    goto LAB_08054816;
                  }
                }
                pbVar27 = local_128;
                if (local_168 == 2) goto LAB_08054b04;
                pbVar28 = &DAT_00000008;
                iVar6 = BIO_write((BIO *)local_18c,"Salted__",8);
                if (iVar6 == 8) {
                  pbVar28 = &DAT_00000008;
                  iVar6 = BIO_write((BIO *)local_18c,pbVar27,8);
                  if (iVar6 == 8) goto LAB_08054b04;
                }
                pcVar25 = "error writing output file\n";
                pbVar27 = pbVar28;
              }
LAB_08054816:
              pFVar26 = (FILE *)0x0;
              uVar16 = 1;
              BIO_printf(bio_err,pcVar25,pbVar27);
            }
            goto LAB_0805482b;
          }
          pcVar25 = "decryption";
          if (local_190 != (FILE *)0x0) {
            pcVar25 = "encryption";
          }
          do {
            iVar6 = EVP_CIPHER_nid(local_180);
            pcVar14 = OBJ_nid2ln(iVar6);
            BIO_snprintf((char *)&local_e8,200,"enter %s %s password:",pcVar14,pcVar25);
            *(undefined *)&local_194->_flags = 0;
            iVar6 = EVP_read_pw_string((char *)local_194,0x200,(char *)&local_e8,(int)local_190);
            if (iVar6 == 0) {
              if (*(char *)&local_194->_flags == '\0') goto LAB_0805500a;
              bVar23 = false;
              local_170 = (undefined1 *)local_194;
              goto LAB_0805474b;
            }
          } while (-1 < iVar6);
          pcVar25 = "bad password read\n";
        }
        else {
          iVar6 = app_passwd(bio_err,local_184,0,&local_138,0);
          if (iVar6 != 0) {
            local_170 = (undefined1 *)local_138;
            bVar23 = local_138 == (FILE *)0x0;
            goto LAB_08054728;
          }
          pcVar25 = "Error getting password\n";
        }
        BIO_printf(bio_err,pcVar25);
LAB_0805500a:
        pFVar26 = (FILE *)0x0;
        pFVar15 = (FILE *)0x0;
        uVar16 = 1;
      }
      else {
        lVar11 = BIO_ctrl((BIO *)pFVar10,0x6c,3,local_18c);
        pFVar15 = local_18c;
        if (0 < lVar11) goto LAB_0805470f;
LAB_08054fde:
        perror((char *)pFVar15);
        pFVar26 = (FILE *)0x0;
        pFVar15 = (FILE *)0x0;
        uVar16 = 1;
      }
    }
LAB_0805482b:
    ERR_print_errors(bio_err);
    CRYPTO_free(local_194);
  }
  CRYPTO_free(local_198);
  if (pFVar10 != (FILE *)0x0) {
    BIO_free((BIO *)pFVar10);
  }
  if (local_17c != (FILE *)0x0) {
    BIO_free_all((BIO *)local_17c);
  }
  if (pFVar26 != (FILE *)0x0) {
    BIO_free((BIO *)pFVar26);
  }
  if (pFVar15 != (FILE *)0x0) {
    BIO_free((BIO *)pFVar15);
  }
LAB_08053fe1:
  if (local_138 != (FILE *)0x0) {
    CRYPTO_free(local_138);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar16;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

