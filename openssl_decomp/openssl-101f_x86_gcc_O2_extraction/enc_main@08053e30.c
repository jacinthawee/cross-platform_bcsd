
/* WARNING: Could not reconcile some variable overlaps */

undefined4 enc_main(int param_1,undefined4 *param_2)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  EVP_CIPHER *pEVar4;
  EVP_CIPHER *pEVar5;
  int iVar6;
  FILE *pFVar7;
  FILE *pFVar8;
  BIO_METHOD *pBVar9;
  long lVar10;
  size_t sVar11;
  int iVar12;
  ulong uVar13;
  char *pcVar14;
  FILE *pFVar15;
  undefined4 uVar16;
  FILE **ppFVar17;
  FILE *pFVar18;
  FILE *pFVar19;
  byte *pbVar20;
  FILE *pFVar21;
  int in_GS_OFFSET;
  undefined uVar22;
  undefined uVar23;
  bool bVar24;
  byte bVar25;
  char *pcVar26;
  FILE *pFVar27;
  uchar *salt;
  uchar *puVar28;
  uint uVar29;
  undefined auStack_19c [4];
  FILE *local_198;
  FILE *local_194;
  FILE *local_190;
  FILE *local_18c;
  FILE *local_188;
  FILE *local_184;
  FILE *local_180;
  FILE *local_17c;
  EVP_CIPHER *local_178;
  FILE *local_174;
  undefined1 *local_170;
  int local_16c;
  int local_168;
  int local_164;
  int local_160;
  int local_15c;
  FILE *local_158;
  FILE *local_154;
  FILE *local_150;
  int local_14c;
  int local_148;
  int local_144;
  FILE *local_140;
  FILE *local_138;
  EVP_CIPHER_CTX *local_134;
  undefined local_130 [8];
  undefined local_128 [24];
  char local_110;
  char local_10f;
  char local_10e;
  char local_10d;
  FILE local_e8;
  int local_20;
  
  bVar25 = 0;
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
  if (iVar6 == 0) {
LAB_08053e8b:
    uVar16 = 1;
    ERR_print_errors(bio_err);
    goto LAB_08053ea1;
  }
  uVar22 = auStack_19c < &DAT_00000004;
  uVar23 = &stack0x00000000 == (undefined *)0x1a0;
  pFVar27 = (FILE *)&DAT_00000028;
  pFVar7 = (FILE *)&local_110;
  program_name(*param_2,pFVar7,0x28);
  iVar6 = 7;
  pFVar15 = pFVar7;
  pbVar20 = (byte *)0x81ecbc2;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    uVar22 = *(byte *)&pFVar15->_flags < *pbVar20;
    uVar23 = *(byte *)&pFVar15->_flags == *pbVar20;
    pFVar15 = (FILE *)((int)pFVar15 + (uint)bVar25 * -2 + 1);
    pbVar20 = pbVar20 + (uint)bVar25 * -2 + 1;
  } while ((bool)uVar23);
  if ((!(bool)uVar22 && !(bool)uVar23) == (bool)uVar22) {
    local_178 = EVP_get_cipherbyname((char *)pFVar7);
    local_168 = 1;
    pFVar7 = pFVar27;
  }
  else {
    local_178 = EVP_get_cipherbyname((char *)pFVar7);
    if ((local_178 == (EVP_CIPHER *)0x0) &&
       ((((local_110 != 'e' || (local_10f != 'n')) || (local_10e != 'c')) || (local_10d != '\0'))))
    {
      BIO_printf(bio_err,"%s is an unknown cipher\n",pFVar7);
LAB_0805411d:
      BIO_printf(bio_err,"options are\n",pFVar7);
      BIO_printf(bio_err,"%-14s input file\n","-in <file>");
      BIO_printf(bio_err,"%-14s output file\n","-out <file>");
      BIO_printf(bio_err,"%-14s pass phrase source\n","-pass <arg>");
      BIO_printf(bio_err,"%-14s encrypt\n",&DAT_081ecb9a);
      BIO_printf(bio_err,"%-14s decrypt\n",&DAT_081ecbac);
      BIO_printf(bio_err,"%-14s base64 encode/decode, depending on encryption flag\n","-a/-base64");
      BIO_printf(bio_err,"%-14s passphrase is the next argument\n",&DAT_081ecbc9);
      BIO_printf(bio_err,"%-14s passphrase is the first line of the file argument\n","-kfile");
      BIO_printf(bio_err,"%-14s the next argument is the md to use to create a key\n",&DAT_081ecbcc)
      ;
      BIO_printf(bio_err,"%-14s   from a passphrase.  One of md2, md5, sha or sha1\n",&DAT_081ec74a)
      ;
      BIO_printf(bio_err,"%-14s salt in hex is the next argument\n",&DAT_081ecbd0);
      BIO_printf(bio_err,"%-14s key/iv in hex is the next argument\n","-K/-iv");
      BIO_printf(bio_err,"%-14s print the iv/key (then exit if -P)\n","-[pP]");
      BIO_printf(bio_err,"%-14s buffer size\n","-bufsize <n>");
      BIO_printf(bio_err,"%-14s disable standard block padding\n","-nopad");
      BIO_printf(bio_err,"%-14s use engine e, possibly a hardware device.\n","-engine e");
      BIO_printf(bio_err,"Cipher Types\n");
      OBJ_NAME_do_all_sorted(2,show_ciphers,bio_err);
      BIO_printf(bio_err,"\n");
      goto LAB_08053e8b;
    }
    local_168 = 0;
    pFVar7 = pFVar27;
  }
  ppFVar17 = (FILE **)(param_2 + 1);
  local_144 = 0;
  local_180 = (FILE *)0x0;
  local_188 = (FILE *)0x0;
  local_18c = (FILE *)0x0;
  local_15c = 0;
  pFVar15 = (FILE *)(param_1 + -1);
  local_148 = 0;
  local_160 = 0;
  local_164 = 0;
  local_190 = (FILE *)0x1;
  local_174 = (FILE *)0x0;
  local_150 = (FILE *)0x0;
  local_158 = (FILE *)0x0;
  local_154 = (FILE *)0x0;
  local_184 = (FILE *)0x0;
  local_170 = (undefined1 *)0x0;
  local_14c = 0;
  local_16c = 0;
  local_17c = (FILE *)0x0;
  if (0 < (int)pFVar15) {
LAB_08053fff:
    pFVar27 = *ppFVar17;
    local_198 = (FILE *)(0x2d - (uint)*(byte *)&pFVar27->_flags);
    bVar24 = local_198 == (FILE *)0x0;
    local_194 = (FILE *)((uint)local_194 & 0xffffff00 | (uint)*(byte *)&pFVar27->_flags);
    if (bVar24) {
      cVar1 = *(char *)((int)&pFVar27->_flags + 1);
      if (cVar1 == 'e') {
        bVar24 = *(char *)((int)&pFVar27->_flags + 2) == '\0';
        if (!bVar24) goto LAB_08053fd0;
        local_190 = (FILE *)0x1;
      }
      else {
        bVar24 = cVar1 == 'i';
        if (((!bVar24) || (bVar24 = *(char *)((int)&pFVar27->_flags + 2) == 'n', !bVar24)) ||
           (bVar24 = *(char *)((int)&pFVar27->_flags + 3) == '\0', !bVar24)) goto LAB_08053fd0;
        pFVar15 = (FILE *)(pFVar15[-1]._unused2 + 0x27);
        if (pFVar15 == (FILE *)0x0) goto LAB_0805411d;
        local_18c = ppFVar17[1];
        ppFVar17 = ppFVar17 + 1;
      }
    }
    else {
LAB_08053fd0:
      iVar6 = 5;
      pFVar8 = pFVar27;
      pcVar26 = "-out";
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar24 = *(char *)&pFVar8->_flags == *pcVar26;
        pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar25 * -2 + 1);
        pcVar26 = pcVar26 + (uint)bVar25 * -2 + 1;
      } while (bVar24);
      if (bVar24) {
        if ((FILE *)(pFVar15[-1]._unused2 + 0x27) == (FILE *)0x0) goto LAB_0805411d;
        local_188 = ppFVar17[1];
        ppFVar17 = ppFVar17 + 1;
        pFVar15 = (FILE *)(pFVar15[-1]._unused2 + 0x27);
      }
      else {
        iVar6 = 6;
        pFVar8 = pFVar27;
        pcVar26 = "-pass";
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar24 = *(char *)&pFVar8->_flags == *pcVar26;
          pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar25 * -2 + 1);
          pcVar26 = pcVar26 + (uint)bVar25 * -2 + 1;
        } while (bVar24);
        if (bVar24) {
          if ((FILE *)(pFVar15[-1]._unused2 + 0x27) == (FILE *)0x0) goto LAB_0805411d;
          local_184 = ppFVar17[1];
          ppFVar17 = ppFVar17 + 1;
          pFVar15 = (FILE *)(pFVar15[-1]._unused2 + 0x27);
        }
        else {
          iVar6 = 8;
          pFVar8 = pFVar27;
          pcVar26 = "-engine";
          do {
            if (iVar6 == 0) break;
            iVar6 = iVar6 + -1;
            bVar24 = *(char *)&pFVar8->_flags == *pcVar26;
            pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar25 * -2 + 1);
            pcVar26 = pcVar26 + (uint)bVar25 * -2 + 1;
          } while (bVar24);
          if (bVar24) {
            if ((FILE *)(pFVar15[-1]._unused2 + 0x27) == (FILE *)0x0) goto LAB_0805411d;
            local_180 = ppFVar17[1];
            ppFVar17 = ppFVar17 + 1;
            pFVar15 = (FILE *)(pFVar15[-1]._unused2 + 0x27);
          }
          else {
            bVar24 = local_198 == (FILE *)0x0;
            if (bVar24) {
              cVar1 = *(char *)((int)&pFVar27->_flags + 1);
              if (cVar1 != 'd') {
                if (cVar1 == 'p') {
                  bVar24 = *(char *)((int)&pFVar27->_flags + 2) == '\0';
                  if (!bVar24) goto LAB_0805439c;
                  local_164 = 1;
                }
                else {
                  bVar24 = cVar1 == 'v';
                  if ((!bVar24) || (bVar24 = *(char *)((int)&pFVar27->_flags + 2) == '\0', !bVar24))
                  goto LAB_0805439c;
                  local_16c = 1;
                }
                goto joined_r0x08053ffd;
              }
              bVar24 = *(char *)((int)&pFVar27->_flags + 2) == '\0';
              if (bVar24) {
                local_190 = (FILE *)0x0;
                goto joined_r0x08053ffd;
              }
            }
LAB_0805439c:
            iVar6 = 7;
            pFVar8 = pFVar27;
            pcVar26 = "-nopad";
            do {
              if (iVar6 == 0) break;
              iVar6 = iVar6 + -1;
              bVar24 = *(char *)&pFVar8->_flags == *pcVar26;
              pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar25 * -2 + 1);
              pcVar26 = pcVar26 + (uint)bVar25 * -2 + 1;
            } while (bVar24);
            if (bVar24) {
              local_14c = 1;
            }
            else {
              iVar6 = 6;
              pFVar8 = pFVar27;
              pcVar26 = "-salt";
              do {
                if (iVar6 == 0) break;
                iVar6 = iVar6 + -1;
                bVar24 = *(char *)&pFVar8->_flags == *pcVar26;
                pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar25 * -2 + 1);
                pcVar26 = pcVar26 + (uint)bVar25 * -2 + 1;
              } while (bVar24);
              if (bVar24) {
                local_15c = 0;
              }
              else {
                iVar6 = 8;
                pFVar8 = pFVar27;
                pcVar26 = "-nosalt";
                do {
                  if (iVar6 == 0) break;
                  iVar6 = iVar6 + -1;
                  bVar24 = *(char *)&pFVar8->_flags == *pcVar26;
                  pFVar8 = (FILE *)((int)pFVar8 + (uint)bVar25 * -2 + 1);
                  pcVar26 = pcVar26 + (uint)bVar25 * -2 + 1;
                } while (bVar24);
                if (bVar24) {
                  local_15c = 1;
                }
                else {
                  iVar6 = 7;
                  pFVar8 = pFVar27;
                  pFVar18 = (FILE *)&DAT_081ecb03;
                  do {
                    pFVar19 = pFVar8;
                    pFVar21 = pFVar18;
                    if (iVar6 == 0) break;
                    iVar6 = iVar6 + -1;
                    pFVar21 = (FILE *)((int)pFVar18 + (uint)bVar25 * -2 + 1);
                    pFVar19 = (FILE *)((int)pFVar8 + (uint)bVar25 * -2 + 1);
                    bVar24 = *(char *)&pFVar8->_flags == *(char *)&pFVar18->_flags;
                    pFVar8 = pFVar19;
                    pFVar18 = pFVar21;
                  } while (bVar24);
                  if (bVar24) {
                    local_160 = 1;
                  }
                  else {
                    if (local_198 == (FILE *)0x0) {
                      cVar1 = *(char *)((int)&pFVar27->_flags + 1);
                      if (cVar1 == 'P') {
                        if (*(char *)((int)&pFVar27->_flags + 2) == '\0') {
                          local_164 = 2;
                          goto joined_r0x08053ffd;
                        }
                        goto LAB_080543f8;
                      }
                      if (cVar1 == 'A') {
                        if (*(char *)((int)&pFVar27->_flags + 2) == '\0') {
                          local_148 = 1;
                          goto joined_r0x08053ffd;
                        }
                        goto LAB_080543f8;
                      }
                      if ((cVar1 != 'a') || (*(char *)((int)&pFVar27->_flags + 2) != '\0'))
                      goto LAB_080543f8;
                    }
                    else {
LAB_080543f8:
                      pFVar7 = pFVar15;
                      local_140 = pFVar15;
                      pFVar8 = (FILE *)strcmp((char *)pFVar27,"-base64");
                      pFVar15 = local_140;
                      if (pFVar8 != (FILE *)0x0) {
                        pFVar7 = (FILE *)strcmp((char *)pFVar27,"-bufsize");
                        if (pFVar7 == (FILE *)0x0) {
                          pFVar7 = pFVar8;
                          if ((FILE *)(local_140[-1]._unused2 + 0x27) == (FILE *)0x0)
                          goto LAB_0805411d;
                          local_17c = ppFVar17[1];
                          ppFVar17 = ppFVar17 + 1;
                          pFVar15 = (FILE *)(local_140[-1]._unused2 + 0x27);
                        }
                        else {
                          if (local_198 != (FILE *)0x0) {
                            local_198 = local_140;
                            pFVar15 = (FILE *)strcmp((char *)pFVar27,"-kfile");
                            if (pFVar15 != (FILE *)0x0) goto LAB_080552ae;
LAB_080551d8:
                            local_198 = (FILE *)(local_198[-1]._unused2 + 0x27);
                            if (local_198 == (FILE *)0x0) goto LAB_0805411d;
                            pFVar15 = ppFVar17[1];
                            ppFVar17 = ppFVar17 + 1;
                            pFVar8 = fopen((char *)pFVar15,"r");
                            pFVar27 = pFVar8;
                            if (pFVar8 != (FILE *)0x0) {
                              buf_16513[0] = 0;
                              pFVar7 = pFVar8;
                              pFVar27 = (FILE *)fgets(buf_16513,0x80,pFVar8);
                              if (pFVar27 != (FILE *)0x0) {
                                fclose(pFVar8);
                                uVar29 = 0xffffffff;
                                pcVar26 = buf_16513;
                                do {
                                  if (uVar29 == 0) break;
                                  uVar29 = uVar29 - 1;
                                  cVar1 = *pcVar26;
                                  pcVar26 = pcVar26 + (uint)bVar25 * -2 + 1;
                                } while (cVar1 != '\0');
                                pFVar27 = (FILE *)~uVar29;
                                pFVar15 = pFVar27;
                                if (0 < (int)(pFVar27[-1]._unused2 + 0x27)) {
                                  pFVar15 = (FILE *)(pFVar27[-1]._unused2 + 0x26);
                                  cVar1 = *(char *)((int)&pFVar27[0xe2911]._mode + 2);
                                  if ((cVar1 != '\n') && (cVar1 != '\r')) {
LAB_0805527f:
                                    local_170 = buf_16513;
                                    pFVar15 = local_198;
                                    goto joined_r0x08053ffd;
                                  }
                                  *(undefined *)((int)&pFVar27[0xe2911]._mode + 2) = 0;
                                  if (pFVar15 != (FILE *)0x0) {
                                    pFVar15 = (FILE *)(pFVar27[-1]._unused2 + 0x25);
                                    cVar1 = *(char *)((int)&pFVar27[0xe2911]._mode + 1);
                                    if (((cVar1 != '\n') && (cVar1 != '\r')) ||
                                       (*(undefined *)((int)&pFVar27[0xe2911]._mode + 1) = 0,
                                       pFVar15 != (FILE *)0x0)) goto LAB_0805527f;
                                  }
                                }
                                BIO_printf(bio_err,"zero length password\n",pFVar15,pFVar15);
                                pFVar7 = pFVar15;
                                goto LAB_0805411d;
                              }
                            }
                            BIO_printf(bio_err,"unable to read key from \'%s\'\n",pFVar15,pFVar27);
                            pFVar7 = pFVar15;
                            goto LAB_0805411d;
                          }
                          if ((*(char *)((int)&pFVar27->_flags + 1) == 'k') &&
                             (*(char *)((int)&pFVar27->_flags + 2) == '\0')) {
                            pFVar7 = pFVar8;
                            if ((FILE *)(local_140[-1]._unused2 + 0x27) != (FILE *)0x0) {
                              local_170 = (undefined1 *)ppFVar17[1];
                              ppFVar17 = ppFVar17 + 1;
                              pFVar15 = (FILE *)(local_140[-1]._unused2 + 0x27);
                              goto joined_r0x08053ffd;
                            }
                            goto LAB_0805411d;
                          }
                          local_198 = local_140;
                          pFVar7 = local_140;
                          iVar6 = strcmp((char *)pFVar27,"-kfile");
                          if (iVar6 == 0) goto LAB_080551d8;
                          bVar2 = *(byte *)((int)&pFVar27->_flags + 1);
                          pFVar15 = (FILE *)(uint)bVar2;
                          if (bVar2 == 0x4b) {
                            if (*(char *)((int)&pFVar27->_flags + 2) != '\0') goto LAB_080552ae;
                            if ((FILE *)(local_198[-1]._unused2 + 0x27) == (FILE *)0x0)
                            goto LAB_0805411d;
                            local_154 = ppFVar17[1];
                            ppFVar17 = ppFVar17 + 1;
                            pFVar15 = (FILE *)(local_198[-1]._unused2 + 0x27);
                          }
                          else if (bVar2 == 0x53) {
                            if (*(char *)((int)&pFVar27->_flags + 2) != '\0') goto LAB_080552ae;
                            pFVar15 = (FILE *)(local_198[-1]._unused2 + 0x27);
                            if (pFVar15 == (FILE *)0x0) goto LAB_0805411d;
                            local_150 = ppFVar17[1];
                            ppFVar17 = ppFVar17 + 1;
                          }
                          else if (bVar2 == 0x69) {
                            if ((*(char *)((int)&pFVar27->_flags + 2) == 'v') &&
                               (*(char *)((int)&pFVar27->_flags + 3) == '\0')) {
                              pFVar15 = (FILE *)(local_198[-1]._unused2 + 0x27);
                              if (pFVar15 == (FILE *)0x0) goto LAB_0805411d;
                              local_158 = ppFVar17[1];
                              ppFVar17 = ppFVar17 + 1;
                            }
                            else {
LAB_080552ae:
                              iVar6 = strcmp((char *)pFVar27,"-non-fips-allow");
                              if (iVar6 == 0) {
                                local_144 = 1;
                                pFVar7 = pFVar15;
                                pFVar15 = local_198;
                              }
                              else {
                                if ((char)local_194 == '-') {
                                  local_178 = EVP_get_cipherbyname
                                                        ((char *)((int)&pFVar27->_flags + 1));
                                  pFVar7 = pFVar15;
                                  pFVar15 = local_198;
                                  if (local_178 != (EVP_CIPHER *)0x0) goto joined_r0x08053ffd;
                                  pFVar27 = *ppFVar17;
                                }
                                iVar6 = strcmp((char *)pFVar27,"-none");
                                if (iVar6 != 0) {
                                  BIO_printf(bio_err,"unknown option \'%s\'\n",pFVar27,pFVar19);
                                  pFVar7 = pFVar27;
                                  goto LAB_0805411d;
                                }
                                local_178 = (EVP_CIPHER *)0x0;
                                pFVar7 = pFVar21;
                                pFVar15 = local_198;
                              }
                            }
                          }
                          else {
                            if (((bVar2 != 0x6d) || (*(char *)((int)&pFVar27->_flags + 2) != 'd'))
                               || (*(char *)((int)&pFVar27->_flags + 3) != '\0')) goto LAB_080552ae;
                            pFVar15 = (FILE *)(local_198[-1]._unused2 + 0x27);
                            if (pFVar15 == (FILE *)0x0) goto LAB_0805411d;
                            local_174 = ppFVar17[1];
                            ppFVar17 = ppFVar17 + 1;
                          }
                        }
                        goto joined_r0x08053ffd;
                      }
                    }
                    local_168 = 1;
                  }
                }
              }
            }
          }
        }
      }
    }
joined_r0x08053ffd:
    pFVar15 = (FILE *)(pFVar15[-1]._unused2 + 0x27);
    ppFVar17 = ppFVar17 + 1;
    if (pFVar15 == (FILE *)0x0) goto LAB_08054038;
    goto LAB_08053fff;
  }
LAB_08054038:
  setup_engine(bio_err,local_180,0);
  if (local_174 == (FILE *)0x0) {
    pFVar7 = (FILE *)EVP_md5();
  }
  else {
    pFVar7 = (FILE *)EVP_get_digestbyname((char *)local_174);
    if (pFVar7 == (FILE *)0x0) {
      BIO_printf(bio_err,"%s is an unsupported message digest type\n",local_174);
      goto LAB_08053e8b;
    }
  }
  if (local_17c == (FILE *)0x0) {
    iVar6 = 0x2c52;
    local_174 = (FILE *)0x2000;
  }
  else {
    bVar25 = *(byte *)&local_17c->_flags;
    if (bVar25 == 0) {
      bVar24 = true;
      pFVar15 = (FILE *)0x0;
    }
    else {
      pFVar15 = (FILE *)0x0;
      do {
        if (bVar25 - 0x30 < 10) {
          pFVar15 = (FILE *)((bVar25 - 0x30) + (int)pFVar15 * 10);
        }
        else if (bVar25 == 0x6b) {
          if (*(uchar *)((int)&local_17c->_flags + 1) != '\0') {
            BIO_printf(bio_err,"invalid \'bufsize\' specified.\n");
            goto LAB_08053e8b;
          }
          pFVar15 = (FILE *)((int)pFVar15 * 0x400);
          local_17c = (FILE *)((int)&local_17c->_flags + 1);
          bVar24 = pFVar15 < (FILE *)0x50;
          goto LAB_08054482;
        }
        local_17c = (FILE *)((int)&local_17c->_flags + 1);
        bVar25 = *(byte *)&local_17c->_flags;
      } while (bVar25 != 0);
      bVar24 = pFVar15 < (FILE *)0x50;
    }
LAB_08054482:
    if (local_168 == 0) {
LAB_080547e7:
      iVar6 = ((int)pFVar15 / 0x30 + 0x29 + ((int)((int)&pFVar15->_flags + 2) / 3) * 2) * 2;
      local_174 = pFVar15;
    }
    else {
      iVar6 = 0xc0;
      local_174 = (FILE *)0x50;
      if (!bVar24) goto LAB_080547e7;
    }
    if (local_16c != 0) {
      BIO_printf(bio_err,"bufsize=%d\n",local_174);
    }
  }
  pFVar15 = (FILE *)CRYPTO_malloc(0x200,"enc.c",0x176);
  local_194 = pFVar15;
  local_198 = (FILE *)CRYPTO_malloc(iVar6,"enc.c",0x177);
  if ((local_198 == (FILE *)0x0) || (pFVar15 == (FILE *)0x0)) {
    BIO_printf(bio_err,"OPENSSL_malloc failure %ld\n",iVar6);
    ERR_print_errors(bio_err);
    if (local_194 != (FILE *)0x0) {
      CRYPTO_free(local_194);
    }
    if (local_198 == (FILE *)0x0) {
      uVar16 = 1;
      goto LAB_08053ea1;
    }
    pFVar15 = (FILE *)0x0;
    pFVar7 = (FILE *)0x0;
    uVar16 = 1;
    local_180 = (FILE *)0x0;
    pFVar27 = (FILE *)0x0;
  }
  else {
    pBVar9 = BIO_s_file();
    pFVar15 = (FILE *)BIO_new(pBVar9);
    pBVar9 = BIO_s_file();
    local_180 = (FILE *)BIO_new(pBVar9);
    if (pFVar15 == (FILE *)0x0 || local_180 == (FILE *)0x0) {
      pFVar7 = (FILE *)0x0;
      pFVar27 = (FILE *)0x0;
      uVar16 = 1;
      ERR_print_errors(bio_err);
    }
    else {
      if (local_160 != 0) {
        BIO_set_callback((BIO *)pFVar15,BIO_debug_callback);
        pFVar27 = local_180;
        BIO_set_callback((BIO *)local_180,BIO_debug_callback);
        BIO_set_callback_arg((BIO *)pFVar15,(char *)bio_err);
        BIO_set_callback_arg((BIO *)pFVar27,(char *)bio_err);
      }
      if (local_18c == (FILE *)0x0) {
        if (local_17c != (FILE *)0x0) {
          setvbuf(stdin,(char *)0x0,2,0);
        }
        BIO_ctrl((BIO *)pFVar15,0x6a,0,stdin);
LAB_0805455d:
        bVar24 = (FILE *)local_170 == (FILE *)0x0;
        if ((local_184 == (FILE *)0x0) || (!bVar24)) {
LAB_08054576:
          pFVar27 = local_194;
          bVar3 = (bool)(local_178 != (EVP_CIPHER *)0x0 & bVar24);
          if ((!bVar3) || (local_170 = (undefined1 *)0x0, bVar24 = bVar3, local_154 != (FILE *)0x0))
          {
LAB_08054599:
            if (local_188 == (FILE *)0x0) {
              salt = (uchar *)0x0;
              BIO_ctrl((BIO *)local_180,0x6a,0,stdout);
              if (local_17c != (FILE *)0x0) {
                salt = (uchar *)0x2;
                setvbuf(stdout,(char *)0x0,2,0);
              }
            }
            else {
              salt = (uchar *)0x5;
              lVar10 = BIO_ctrl((BIO *)local_180,0x6c,5,local_188);
              pFVar27 = local_188;
              if (lVar10 < 1) goto LAB_08054da1;
            }
            if (local_168 != 0) {
              pBVar9 = BIO_f_base64();
              pFVar27 = (FILE *)BIO_new(pBVar9);
              if (pFVar27 != (FILE *)0x0) {
                if (local_160 != 0) {
                  BIO_set_callback((BIO *)pFVar27,BIO_debug_callback);
                  BIO_set_callback_arg((BIO *)pFVar27,(char *)bio_err);
                }
                if (local_148 != 0) {
                  BIO_set_flags((BIO *)pFVar27,0x100);
                }
                if (local_190 == (FILE *)0x0) {
                  local_188 = (FILE *)BIO_push((BIO *)pFVar27,(BIO *)pFVar15);
                  local_18c = local_180;
                }
                else {
                  local_18c = (FILE *)BIO_push((BIO *)pFVar27,(BIO *)local_180);
                  local_188 = pFVar15;
                }
                goto LAB_080545db;
              }
LAB_08054f34:
              pFVar7 = (FILE *)0x0;
              uVar16 = 1;
              goto LAB_08054679;
            }
            pFVar27 = (FILE *)0x0;
            local_18c = local_180;
            local_188 = pFVar15;
LAB_080545db:
            if (local_178 == (EVP_CIPHER *)0x0) {
              local_190 = (FILE *)0x0;
              pFVar8 = local_198;
              pFVar18 = local_18c;
              pFVar19 = local_188;
              local_188 = pFVar15;
              local_184 = pFVar27;
LAB_08054c1e:
              do {
                iVar6 = BIO_read((BIO *)pFVar19,pFVar8,(int)local_174);
                pFVar27 = local_184;
                pFVar15 = local_188;
                pFVar7 = local_190;
                if (iVar6 < 1) {
                  lVar10 = BIO_ctrl((BIO *)local_18c,0xb,0,(void *)0x0);
                  if (lVar10 == 0) {
                    uVar16 = 1;
                    BIO_printf(bio_err,"bad decrypt\n");
                  }
                  else {
                    uVar16 = 0;
                    if (local_16c != 0) {
                      uVar13 = BIO_number_read((BIO *)pFVar15);
                      BIO_printf(bio_err,"bytes read   :%8ld\n",uVar13);
                      uVar13 = BIO_number_written((BIO *)local_180);
                      BIO_printf(bio_err,"bytes written:%8ld\n",uVar13);
                    }
                  }
                  goto LAB_08054679;
                }
                iVar12 = BIO_write((BIO *)pFVar18,pFVar8,iVar6);
                pFVar27 = local_184;
                pFVar15 = local_188;
                pFVar7 = local_190;
              } while (iVar6 == iVar12);
              uVar16 = 1;
              BIO_printf(bio_err,"error writing output file\n");
            }
            else if ((FILE *)local_170 == (FILE *)0x0) {
              if (local_158 == (FILE *)0x0) {
                if ((bVar24) && (iVar6 = EVP_CIPHER_iv_length(local_178), iVar6 != 0)) {
                  pcVar26 = "iv undefined\n";
                  goto LAB_08054664;
                }
              }
              else {
                local_184 = (FILE *)(local_128 + 8);
LAB_080549c1:
                salt = &DAT_00000010;
                iVar6 = set_hex(local_158,local_184,0x10);
                if (iVar6 == 0) {
                  pcVar26 = "invalid hex iv value\n";
                  goto LAB_08054664;
                }
              }
LAB_080549de:
              if (local_154 != (FILE *)0x0) {
                salt = (uchar *)0x40;
                iVar6 = set_hex(local_154,&local_e8,0x40);
                if (iVar6 == 0) {
                  pcVar26 = "invalid hex key value\n";
                  goto LAB_08054664;
                }
              }
              pBVar9 = BIO_f_cipher();
              uVar16 = 1;
              pFVar7 = (FILE *)BIO_new(pBVar9);
              if (pFVar7 != (FILE *)0x0) {
                uVar29 = 0;
                BIO_ctrl((BIO *)pFVar7,0x81,0,&local_134);
                if (local_144 != 0) {
                  EVP_CIPHER_CTX_set_flags(local_134,0x8000);
                }
                iVar6 = EVP_CipherInit_ex(local_134,local_178,(ENGINE *)0x0,(uchar *)0x0,
                                          (uchar *)0x0,(int)local_190);
                if (iVar6 != 0) {
                  if (local_14c != 0) {
                    EVP_CIPHER_CTX_set_padding(local_134,0);
                  }
                  pFVar8 = local_190;
                  local_184 = (FILE *)(local_128 + 8);
                  local_190 = &local_e8;
                  iVar6 = EVP_CipherInit_ex(local_134,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                            (uchar *)local_190,(uchar *)local_184,(int)pFVar8);
                  if (iVar6 != 0) {
                    if (local_160 != 0) {
                      BIO_set_callback((BIO *)pFVar7,BIO_debug_callback);
                      BIO_set_callback_arg((BIO *)pFVar7,(char *)bio_err);
                    }
                    if (local_164 != 0) {
                      if (local_15c == 0) {
                        uVar16 = 1;
                        __printf_chk(1,"salt=",1,1);
                        pFVar8 = (FILE *)local_128;
                        do {
                          uVar29 = (uint)*(byte *)&pFVar8->_flags;
                          pFVar8 = (FILE *)((int)&pFVar8->_flags + 1);
                          __printf_chk(1,&DAT_08226cb0,uVar29,uVar16);
                        } while (pFVar8 != local_184);
                        putchar(10);
                      }
                      pEVar4 = local_178;
                      if (0 < local_178->key_len) {
                        __printf_chk(1,&DAT_081ecd4b,uVar29);
                        pEVar5 = local_178;
                        pFVar8 = local_190;
                        if (0 < pEVar4->key_len) {
                          iVar6 = 0;
                          local_17c = pFVar7;
                          local_170 = (undefined1 *)pFVar27;
                          do {
                            uVar29 = (uint)(byte)pFVar8->_shortbuf[iVar6 + -0x47];
                            iVar6 = iVar6 + 1;
                            __printf_chk(1,&DAT_08226cb0,uVar29);
                            pFVar7 = local_17c;
                            pFVar27 = (FILE *)local_170;
                          } while (pEVar5->key_len != iVar6 && iVar6 <= pEVar5->key_len);
                        }
                        putchar(10);
                      }
                      if (0 < local_178->iv_len) {
                        iVar6 = 0;
                        __printf_chk(1,&DAT_081ecd50,uVar29);
                        if (0 < local_178->iv_len) {
                          do {
                            iVar12 = iVar6 + -0x47;
                            iVar6 = iVar6 + 1;
                            __printf_chk(1,&DAT_08226cb0,local_184->_shortbuf[iVar12]);
                          } while (local_178->iv_len != iVar6 && iVar6 <= local_178->iv_len);
                        }
                        putchar(10);
                      }
                      uVar16 = 0;
                      if (local_164 == 2) goto LAB_08054679;
                    }
                    local_18c = (FILE *)BIO_push((BIO *)pFVar7,(BIO *)local_18c);
                    pFVar8 = local_198;
                    pFVar18 = local_18c;
                    pFVar19 = local_188;
                    local_190 = pFVar7;
                    local_188 = pFVar15;
                    local_184 = pFVar27;
                    goto LAB_08054c1e;
                  }
                }
                iVar6 = EVP_CIPHER_nid(local_178);
                pcVar26 = OBJ_nid2sn(iVar6);
                BIO_printf(bio_err,"Error setting cipher %s\n",pcVar26);
                uVar16 = 1;
                ERR_print_errors(bio_err);
              }
            }
            else {
              if (local_15c != 0) {
                salt = (uchar *)0x0;
LAB_0805495d:
                sVar11 = strlen(local_170);
                local_184 = (FILE *)(local_128 + 8);
                EVP_BytesToKey(local_178,(EVP_MD *)pFVar7,salt,local_170,sVar11,1,(uchar *)&local_e8
                               ,(uchar *)local_184);
                pFVar7 = (FILE *)local_170;
                if ((FILE *)local_170 == local_194) {
                  OPENSSL_cleanse(local_194,0x200);
                }
                else {
                  sVar11 = strlen(local_170);
                  OPENSSL_cleanse(pFVar7,sVar11);
                }
                if (local_158 != (FILE *)0x0) goto LAB_080549c1;
                goto LAB_080549de;
              }
              if (local_190 == (FILE *)0x0) {
                puVar28 = &DAT_00000008;
                iVar6 = BIO_read((BIO *)local_188,local_130,8);
                if (iVar6 == 8) {
                  puVar28 = &DAT_00000008;
                  salt = local_128;
                  iVar6 = BIO_read((BIO *)local_188,salt,8);
                  if (iVar6 == 8) {
                    iVar6 = memcmp(local_130,"Salted__",8);
                    if (iVar6 != 0) {
                      pcVar26 = "bad magic number\n";
                      goto LAB_08054664;
                    }
                    goto LAB_0805495d;
                  }
                }
                salt = puVar28;
                pcVar26 = "error reading input file\n";
              }
              else {
                if (local_150 == (FILE *)0x0) {
                  iVar6 = RAND_pseudo_bytes(local_128,8);
                  if (iVar6 < 0) goto LAB_08054f34;
                }
                else {
                  salt = &DAT_00000008;
                  iVar6 = set_hex(local_150,local_128,8);
                  if (iVar6 == 0) {
                    pcVar26 = "invalid hex salt value\n";
                    goto LAB_08054664;
                  }
                }
                salt = local_128;
                if (local_164 == 2) goto LAB_0805495d;
                puVar28 = &DAT_00000008;
                iVar6 = BIO_write((BIO *)local_18c,"Salted__",8);
                if (iVar6 == 8) {
                  puVar28 = &DAT_00000008;
                  iVar6 = BIO_write((BIO *)local_18c,salt,8);
                  if (iVar6 == 8) goto LAB_0805495d;
                }
                pcVar26 = "error writing output file\n";
                salt = puVar28;
              }
LAB_08054664:
              pFVar7 = (FILE *)0x0;
              uVar16 = 1;
              BIO_printf(bio_err,pcVar26,salt);
            }
            goto LAB_08054679;
          }
          pcVar26 = "decryption";
          if (local_190 != (FILE *)0x0) {
            pcVar26 = "encryption";
          }
          local_18c = pFVar7;
          do {
            iVar6 = EVP_CIPHER_nid(local_178);
            pcVar14 = OBJ_nid2ln(iVar6);
            BIO_snprintf((char *)&local_e8,200,"enter %s %s password:",pcVar14,pcVar26);
            *(uchar *)&pFVar27->_flags = '\0';
            iVar6 = EVP_read_pw_string((char *)pFVar27,0x200,(char *)&local_e8,(int)local_190);
            if (iVar6 == 0) {
              if (*(uchar *)&local_194->_flags == '\0') goto LAB_08054e3e;
              bVar24 = false;
              pFVar7 = local_18c;
              local_170 = (undefined1 *)local_194;
              goto LAB_08054599;
            }
          } while (-1 < iVar6);
          pcVar26 = "bad password read\n";
        }
        else {
          iVar6 = app_passwd(bio_err,local_184,0,&local_138,0);
          if (iVar6 != 0) {
            local_170 = (undefined1 *)local_138;
            bVar24 = local_138 == (FILE *)0x0;
            goto LAB_08054576;
          }
          pcVar26 = "Error getting password\n";
        }
        BIO_printf(bio_err,pcVar26);
LAB_08054e3e:
        pFVar7 = (FILE *)0x0;
        pFVar27 = (FILE *)0x0;
        uVar16 = 1;
      }
      else {
        lVar10 = BIO_ctrl((BIO *)pFVar15,0x6c,3,local_18c);
        pFVar27 = local_18c;
        if (0 < lVar10) goto LAB_0805455d;
LAB_08054da1:
        perror((char *)pFVar27);
        pFVar7 = (FILE *)0x0;
        pFVar27 = (FILE *)0x0;
        uVar16 = 1;
      }
    }
LAB_08054679:
    ERR_print_errors(bio_err);
    CRYPTO_free(local_194);
  }
  CRYPTO_free(local_198);
  if (pFVar15 != (FILE *)0x0) {
    BIO_free((BIO *)pFVar15);
  }
  if (local_180 != (FILE *)0x0) {
    BIO_free_all((BIO *)local_180);
  }
  if (pFVar7 != (FILE *)0x0) {
    BIO_free((BIO *)pFVar7);
  }
  if (pFVar27 != (FILE *)0x0) {
    BIO_free((BIO *)pFVar27);
  }
LAB_08053ea1:
  if (local_138 != (FILE *)0x0) {
    CRYPTO_free(local_138);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar16;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

