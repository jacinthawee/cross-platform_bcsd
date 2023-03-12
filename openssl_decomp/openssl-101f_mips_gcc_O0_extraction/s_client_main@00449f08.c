
/* WARNING: Removing unreachable block (ram,0x0044c084) */
/* WARNING: Removing unreachable block (ram,0x0044c0c0) */
/* WARNING: Removing unreachable block (ram,0x0044c1b0) */
/* WARNING: Removing unreachable block (ram,0x0044ba20) */
/* WARNING: Removing unreachable block (ram,0x0044b6a0) */
/* WARNING: Removing unreachable block (ram,0x0044b78c) */
/* WARNING: Removing unreachable block (ram,0x0044b7fc) */
/* WARNING: Removing unreachable block (ram,0x0044b860) */
/* WARNING: Removing unreachable block (ram,0x0044b8d0) */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

char * s_client_main(int param_1,char **param_2)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  undefined *puVar9;
  undefined *puVar10;
  undefined *puVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  int iVar15;
  char **ppcVar16;
  undefined4 uVar17;
  undefined4 *puVar18;
  char *pcVar19;
  int iVar20;
  byte *pbVar21;
  int *piVar22;
  int **ppiVar23;
  undefined4 *puVar24;
  char *pcVar25;
  undefined1 *puVar26;
  char *pcVar27;
  byte *pbVar28;
  char *pcVar29;
  code *pcVar30;
  char *pcVar31;
  int local_res0 [4];
  char *local_248;
  int **local_240;
  undefined1 *local_230;
  undefined4 *local_228;
  int local_224;
  char *local_220;
  char *local_21c;
  char *local_218;
  undefined1 *local_214;
  char *local_210;
  undefined4 *local_20c;
  char *local_208;
  char *local_204;
  uint local_200;
  char *local_1fc;
  int local_1f8;
  char *local_1f4;
  undefined4 *local_1f0;
  char *local_1ec;
  uint *local_1e8;
  uint *local_1e4;
  char *local_1e0;
  undefined **local_1dc;
  char *local_1d8;
  int local_1d4;
  char *local_1d0;
  char *local_1cc;
  undefined **local_1c8;
  int local_1c4;
  undefined1 *local_1c0;
  char *local_1bc;
  char *local_1b8;
  char *local_1b4;
  undefined4 *local_1b0;
  int local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  undefined *local_19c;
  undefined1 *local_198;
  char **local_18c [2];
  short local_182;
  undefined4 local_180;
  char *local_17c;
  int local_178;
  int local_174;
  int local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  int *local_15c;
  undefined4 local_158;
  undefined4 local_154;
  char *local_150;
  int local_14c;
  int local_148;
  int local_144;
  undefined4 local_140;
  undefined auStack_13c [16];
  uint auStack_12c [32];
  uint auStack_ac [32];
  int local_2c;
  
  puVar11 = PTR___stack_chk_guard_006aabf0;
  ppiVar23 = (int **)PTR_bio_err_006a7f3c;
  puVar24 = (undefined4 *)0x640000;
  local_182 = 0x1151;
  local_16c = 0x10;
  local_17c = "localhost";
  local_140 = 0x400;
  local_178 = 0;
  local_174 = 0;
  local_170 = 0;
  local_15c = (int *)0x0;
  local_158 = 0;
  local_154 = 0;
  local_150 = (char *)0x0;
  local_14c = 0;
  local_148 = 0;
  local_144 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_res0[0] = param_1;
  local_18c[0] = param_2;
  local_240 = (int **)(*(code *)PTR_SSLv23_client_method_006a8a70)();
  (*(code *)PTR_signal_006aabe0)(0xd,1);
  iVar20 = (int)*ppiVar23;
  local_230 = &_ITM_registerTMCloneTable;
  c_Pause = 0;
  c_quiet = 0;
  c_ign_eof = 0;
  local_228 = (undefined4 *)&_ITM_registerTMCloneTable;
  c_debug = 0;
  c_msg = 0;
  c_showcerts = 0;
  if (iVar20 == 0) {
    iVar20 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
    *ppiVar23 = (int *)iVar20;
  }
  iVar20 = load_config(iVar20,0);
  if (iVar20 == 0) {
    puVar24 = (undefined4 *)0x0;
    pcVar27 = (char *)0x0;
    pcVar29 = (char *)0x0;
    pcVar25 = (char *)0x0;
    puVar26 = (undefined1 *)0x0;
    pcVar31 = (char *)0x0;
  }
  else {
    local_21c = "s\n";
    pcVar31 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x2000,"s_client.c",0x285);
    if ((pcVar31 == (char *)0x0) ||
       (puVar26 = (undefined1 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x2000,"s_client.c",0x286),
       puVar26 == (undefined1 *)0x0)) {
      puVar26 = (undefined1 *)0x0;
    }
    else {
      pcVar25 = (char *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x2000,"s_client.c",0x287);
      puVar9 = PTR_verify_error_006a8a74;
      if (pcVar25 != (char *)0x0) {
        local_19c = (undefined *)0x0;
        local_1cc = (char *)0x0;
        local_198 = &_ITM_registerTMCloneTable;
        local_res0[0] = local_res0[0] + -1;
        local_20c = (undefined4 *)PTR_verify_depth_006a897c;
        pcVar19 = "-host";
        c_nbio = 0;
        local_1a0 = 0;
        *(undefined4 *)PTR_verify_depth_006a897c = 0;
        local_18c[0] = local_18c[0] + 1;
        local_1a4 = 0;
        *(undefined4 *)puVar9 = 0;
        local_1fc = (char *)0x0;
        local_1f4 = (char *)0x0;
        local_204 = (char *)0x0;
        local_1c4 = 2;
        local_1d0 = (char *)0x0;
        local_1e0 = (char *)0x0;
        local_1e4 = (uint *)0x0;
        local_1dc = (undefined **)0x0;
        local_224 = 0;
        local_1f8 = 0;
        local_1a8 = 0;
        local_1ac = 0;
        local_1b0 = (undefined4 *)0x0;
        local_214 = (undefined1 *)0x0;
        local_1d4 = 0;
        local_1b4 = (char *)0x0;
        local_1b8 = (char *)0x0;
        local_1bc = (char *)0x0;
        local_1e8 = (uint *)0x0;
        local_1d8 = (char *)0x3;
        local_1f0 = (undefined4 *)0x3;
        local_1ec = (char *)0x0;
        local_208 = (char *)0x0;
        local_1c0 = (undefined1 *)0x0;
        local_1c8 = (undefined **)0x0;
        local_248 = "-port";
        local_200 = 0;
        local_220 = "s\n";
        local_218 = "-verify";
        local_210 = "Number";
        goto LAB_0044a318;
      }
    }
    puVar24 = (undefined4 *)0x0;
    pcVar27 = (char *)0x0;
    (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"out of memory\n");
    pcVar29 = (char *)0x0;
    pcVar25 = (char *)0x0;
  }
LAB_0044a058:
  local_248 = (char *)0x1;
  if (next_proto._0_4_ == 0) goto LAB_0044a078;
LAB_0044a06c:
  (*(code *)PTR_CRYPTO_free_006a7f88)();
LAB_0044a078:
  if (puVar24 != (undefined4 *)0x0) {
    (*(code *)PTR_SSL_CTX_free_006a8978)(puVar24);
  }
LAB_0044a08c:
  ppcVar16 = (char **)&_ITM_registerTMCloneTable;
  pcVar19 = &_ITM_registerTMCloneTable;
  if (pcVar29 != (char *)0x0) {
    (*(code *)PTR_X509_free_006a7f90)(pcVar29);
  }
  if (pcVar27 != (char *)0x0) {
    (*(code *)PTR_EVP_PKEY_free_006a7f78)(pcVar27);
  }
  if (local_178 != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  if (local_174 != 0) {
    (*(code *)PTR_X509_VERIFY_PARAM_free_006a83cc)();
  }
  if (pcVar31 != (char *)0x0) {
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(pcVar31,0x2000);
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar31);
  }
  if (puVar26 != (undefined1 *)0x0) {
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(puVar26,0x2000);
    (*(code *)PTR_CRYPTO_free_006a7f88)(puVar26);
  }
  if (pcVar25 != (char *)0x0) {
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(pcVar25,0x2000);
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar25);
  }
  if (bio_c_out != (int *)0x0) {
    (*(code *)PTR_BIO_free_006a7f70)();
    bio_c_out = (int *)0x0;
  }
  if (local_2c == *(int *)puVar11) {
    return local_248;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  do {
    iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-ign_eof");
    if (iVar20 == 0) {
      c_ign_eof = 1;
      iVar20 = local_res0[0];
    }
    else {
      iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-no_ign_eof");
      if (iVar20 == 0) {
        c_ign_eof = 0;
        iVar20 = local_res0[0];
      }
      else {
        iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-pause");
        if (iVar20 == 0) {
          c_Pause = 1;
          iVar20 = local_res0[0];
        }
        else {
          iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-debug");
          if (iVar20 == 0) {
            c_debug = 1;
            iVar20 = local_res0[0];
          }
          else {
            iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-tlsextdebug");
            if (iVar20 == 0) {
              c_tlsextdebug = 1;
              iVar20 = local_res0[0];
            }
            else {
              iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-status");
              if (iVar20 == 0) {
                c_status_req = 1;
                iVar20 = local_res0[0];
              }
              else {
                iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,&DAT_0063bf64);
                if (iVar20 == 0) {
                  c_msg = 1;
                  iVar20 = local_res0[0];
                }
                else {
                  iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-showcerts");
                  if (iVar20 == 0) {
                    local_228[-0x1344] = 1;
                    iVar20 = local_res0[0];
                  }
                  else {
                    iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-nbio_test");
                    if (iVar20 == 0) {
                      local_1a8 = 1;
                      iVar20 = local_res0[0];
                    }
                    else {
                      iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-state");
                      if (iVar20 != 0) {
                        iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-psk_identity");
                        if (iVar20 == 0) {
                          local_res0[0] = local_res0[0] + -1;
                          if (0 < local_res0[0]) {
                            psk_identity = ppcVar16[1];
                            ppcVar16 = ppcVar16 + 1;
                            iVar20 = local_res0[0];
                            goto LAB_0044a354;
                          }
                        }
                        else {
                          iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,&DAT_0063bfb8);
                          puVar9 = PTR_strlen_006aab30;
                          if (iVar20 == 0) {
                            iVar20 = local_res0[0] + -1;
                            local_res0[0] = iVar20;
                            if (0 < iVar20) {
                              pbVar28 = (byte *)ppcVar16[1];
                              *(byte **)PTR_psk_key_006a8a54 = pbVar28;
                              local_18c[0] = ppcVar16 + 1;
                              iVar12 = (*(code *)puVar9)(pbVar28);
                              pbVar21 = pbVar28;
                              while (ppcVar16 = ppcVar16 + 1, pbVar21 != pbVar28 + iVar12) {
                                piVar22 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
                                bVar2 = *pbVar21;
                                pbVar21 = pbVar21 + 1;
                                if ((*(ushort *)(*piVar22 + (uint)bVar2 * 2) & 0x10) == 0) {
                                  (*(code *)PTR_BIO_printf_006a7f38)
                                            (*ppiVar23,"Not a hex number \'%s\'\n",pbVar28);
                                  goto LAB_0044a4b4;
                                }
                              }
                              goto LAB_0044a354;
                            }
                          }
                          else {
                            iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-srpuser");
                            if (iVar20 == 0) {
                              local_res0[0] = local_res0[0] + -1;
                              if (0 < local_res0[0]) {
                                local_150 = ppcVar16[1];
                                local_18c[0] = ppcVar16 + 1;
                                pcVar30 = (code *)PTR_TLSv1_client_method_006a8ab8;
                                goto LAB_0044d0f8;
                              }
                            }
                            else {
                              iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-srppass");
                              if (iVar20 == 0) {
                                local_res0[0] = local_res0[0] + -1;
                                if (0 < local_res0[0]) {
                                  local_1cc = ppcVar16[1];
                                  local_18c[0] = ppcVar16 + 1;
                                  pcVar30 = (code *)PTR_TLSv1_client_method_006a8ab8;
                                  goto LAB_0044d0f8;
                                }
                              }
                              else {
                                iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-srp_strength");
                                if (iVar20 != 0) {
                                  iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-srp_lateuser");
                                  if (iVar20 == 0) {
                                    local_240 = (int **)(*(code *)PTR_TLSv1_client_method_006a8ab8)
                                                                  ();
                                    local_19c = (undefined *)0x1;
                                    ppcVar16 = local_18c[0];
                                    iVar20 = local_res0[0];
                                    goto LAB_0044a354;
                                  }
                                  iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-srp_moregroups")
                                  ;
                                  if (iVar20 == 0) {
                                    local_144 = 1;
                                    pcVar30 = (code *)PTR_TLSv1_client_method_006a8ab8;
                                  }
                                  else {
                                    iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-ssl2");
                                    pcVar30 = (code *)PTR_SSLv2_client_method_006a8ac8;
                                    if ((((iVar20 != 0) &&
                                         (iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-ssl3"),
                                         pcVar30 = (code *)PTR_SSLv3_client_method_006a8acc,
                                         iVar20 != 0)) &&
                                        (iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-tls1_2"),
                                        pcVar30 = (code *)PTR_TLSv1_2_client_method_006a8ac4,
                                        iVar20 != 0)) &&
                                       ((iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-tls1_1"),
                                        pcVar30 = (code *)PTR_TLSv1_1_client_method_006a8ac0,
                                        iVar20 != 0 &&
                                        (iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-tls1"),
                                        pcVar30 = (code *)PTR_TLSv1_client_method_006a8ab8,
                                        iVar20 != 0)))) {
                                      iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-dtls1");
                                      if (iVar20 == 0) {
                                        local_240 = (int **)(*(code *)
                                                  PTR_DTLSv1_client_method_006a8abc)();
                                        local_1c4 = 1;
                                        ppcVar16 = local_18c[0];
                                        iVar20 = local_res0[0];
                                      }
                                      else {
                                        iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-timeout");
                                        if (iVar20 == 0) {
                                          local_1a4 = 1;
                                          iVar20 = local_res0[0];
                                        }
                                        else {
                                          iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                             (pcVar27,&DAT_0063c09c);
                                          if (iVar20 == 0) {
                                            local_res0[0] = local_res0[0] + -1;
                                            if (local_res0[0] < 1) goto LAB_0044a4b4;
                                            local_18c[0] = ppcVar16 + 1;
                                            local_1a0 = (*(code *)PTR_strtol_006aaa68)
                                                                  (ppcVar16[1],0,10);
                                            ppcVar16 = local_18c[0];
                                            iVar20 = local_res0[0];
                                          }
                                          else {
                                            iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-bugs")
                                            ;
                                            if (iVar20 == 0) {
                                              local_1b0 = (undefined4 *)0x1;
                                              iVar20 = local_res0[0];
                                            }
                                            else {
                                              iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                 (pcVar27,"-keyform");
                                              if (iVar20 == 0) {
                                                local_res0[0] = local_res0[0] + -1;
                                                if (local_res0[0] < 1) goto LAB_0044a4b4;
                                                local_18c[0] = ppcVar16 + 1;
                                                local_1d8 = (char *)str2fmt(ppcVar16[1]);
                                                ppcVar16 = local_18c[0];
                                                iVar20 = local_res0[0];
                                              }
                                              else {
                                                iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                   (pcVar27,"-pass");
                                                if (iVar20 == 0) {
                                                  local_res0[0] = local_res0[0] + -1;
                                                  if (local_res0[0] < 1) goto LAB_0044a4b4;
                                                  local_1e8 = (uint *)ppcVar16[1];
                                                  ppcVar16 = ppcVar16 + 1;
                                                  iVar20 = local_res0[0];
                                                }
                                                else {
                                                  iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                     (pcVar27,&DAT_006330b4);
                                                  if (iVar20 == 0) {
                                                    local_res0[0] = local_res0[0] + -1;
                                                    if (local_res0[0] < 1) goto LAB_0044a4b4;
                                                    local_1ec = ppcVar16[1];
                                                    ppcVar16 = ppcVar16 + 1;
                                                    iVar20 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,"-reconnect");
                                                    if (iVar20 == 0) {
                                                      local_1d4 = 5;
                                                      iVar20 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar27,"-CApath");
                                                      if (iVar20 == 0) {
                                                        local_res0[0] = local_res0[0] + -1;
                                                        if (local_res0[0] < 1) goto LAB_0044a4b4;
                                                        local_1bc = ppcVar16[1];
                                                        ppcVar16 = ppcVar16 + 1;
                                                        iVar20 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar27,"-CAfile");
                                                        if (iVar20 == 0) {
                                                          local_res0[0] = local_res0[0] + -1;
                                                          if (local_res0[0] < 1) goto LAB_0044a4b4;
                                                          local_1b8 = ppcVar16[1];
                                                          ppcVar16 = ppcVar16 + 1;
                                                          iVar20 = local_res0[0];
                                                        }
                                                        else {
                                                          iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                             (pcVar27,"-no_tls1_2");
                                                          if (iVar20 == 0) {
                                                            local_200 = local_200 | 0x8000000;
                                                            iVar20 = local_res0[0];
                                                          }
                                                          else {
                                                            iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                               (pcVar27,"-no_tls1_1"
                                                                               );
                                                            if (iVar20 == 0) {
                                                              local_200 = local_200 | 0x10000000;
                                                              iVar20 = local_res0[0];
                                                            }
                                                            else {
                                                              iVar20 = (*(code *)PTR_strcmp_006aac20
                                                                       )(pcVar27,"-no_tls1");
                                                              if (iVar20 == 0) {
                                                                local_200 = local_200 | 0x4000000;
                                                                iVar20 = local_res0[0];
                                                              }
                                                              else {
                                                                iVar20 = (*(code *)
                                                  PTR_strcmp_006aac20)(pcVar27,"-no_ssl3");
                                                  if (iVar20 == 0) {
                                                    local_200 = local_200 | 0x2000000;
                                                    iVar20 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,"-no_ssl2");
                                                    if (iVar20 == 0) {
                                                      local_200 = local_200 | 0x1000000;
                                                      iVar20 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar27,"-no_comp");
                                                      if (iVar20 == 0) {
                                                        local_200 = local_200 | 0x20000;
                                                        iVar20 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar27,"-no_ticket");
                                                        if (iVar20 == 0) {
                                                          local_200 = local_200 | 0x4000;
                                                          iVar20 = local_res0[0];
                                                        }
                                                        else {
                                                          iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                             (pcVar27,
                                                  "-nextprotoneg");
                                                  if (iVar20 == 0) {
                                                    local_res0[0] = local_res0[0] + -1;
                                                    if (local_res0[0] < 1) goto LAB_0044a4b4;
                                                    local_204 = ppcVar16[1];
                                                    ppcVar16 = ppcVar16 + 1;
                                                    iVar20 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,"-serverpref");
                                                    if (iVar20 == 0) {
                                                      local_200 = local_200 | 0x400000;
                                                      iVar20 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar27,
                                                  "-legacy_renegotiation");
                                                  if (iVar20 == 0) {
                                                    local_200 = local_200 | 0x40000;
                                                    iVar20 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,
                                                  "-legacy_server_connect");
                                                  if (iVar20 == 0) {
                                                    local_200 = local_200 | 4;
                                                    iVar20 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,
                                                  "-no_legacy_server_connect");
                                                  if (iVar20 == 0) {
                                                    local_1c8 = (undefined **)0x4;
                                                    iVar20 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,"-cipher");
                                                    if (iVar20 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      if (local_res0[0] < 1) goto LAB_0044a4b4;
                                                      local_1b4 = ppcVar16[1];
                                                      ppcVar16 = ppcVar16 + 1;
                                                      iVar20 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar27,"-nbio");
                                                      if (iVar20 != 0) {
                                                        iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar27,"-starttls");
                                                        if (iVar20 == 0) {
                                                          iVar20 = local_res0[0] + -1;
                                                          local_res0[0] = iVar20;
                                                          if (0 < iVar20) {
                                                            pcVar27 = ppcVar16[1];
                                                            ppcVar16 = ppcVar16 + 1;
                                                            local_18c[0] = ppcVar16;
                                                            iVar12 = (*(code *)PTR_strcmp_006aac20)
                                                                               (pcVar27,&
                                                  DAT_0063da48);
                                                  if (iVar12 == 0) {
                                                    local_1f8 = 1;
                                                  }
                                                  else {
                                                    iVar12 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,&DAT_0063da50);
                                                    if (iVar12 == 0) {
                                                      local_1f8 = 2;
                                                    }
                                                    else {
                                                      iVar12 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar27,&DAT_0063da58);
                                                      if (iVar12 == 0) {
                                                        local_1f8 = 3;
                                                      }
                                                      else if (((*pcVar27 == 'f') &&
                                                               (pcVar27[1] == 't')) &&
                                                              ((pcVar27[2] == 'p' &&
                                                               (pcVar27[3] == '\0')))) {
                                                        local_1f8 = 4;
                                                      }
                                                      else {
                                                        iVar12 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar27,&DAT_0063da60);
                                                        if (iVar12 != 0) goto LAB_0044a4b4;
                                                        local_1f8 = 5;
                                                      }
                                                    }
                                                  }
                                                  goto LAB_0044a354;
                                                  }
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,"-engine");
                                                    if (iVar20 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      if (0 < local_res0[0]) {
                                                        local_1e4 = (uint *)ppcVar16[1];
                                                        ppcVar16 = ppcVar16 + 1;
                                                        iVar20 = local_res0[0];
                                                        goto LAB_0044a354;
                                                      }
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar27,
                                                  "-ssl_client_engine");
                                                  if (iVar20 == 0) {
                                                    local_res0[0] = local_res0[0] + -1;
                                                    if (0 < local_res0[0]) {
                                                      local_1e0 = ppcVar16[1];
                                                      ppcVar16 = ppcVar16 + 1;
                                                      iVar20 = local_res0[0];
                                                      goto LAB_0044a354;
                                                    }
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,"-rand");
                                                    if (iVar20 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      if (0 < local_res0[0]) {
                                                        local_1dc = (undefined **)ppcVar16[1];
                                                        ppcVar16 = ppcVar16 + 1;
                                                        iVar20 = local_res0[0];
                                                        goto LAB_0044a354;
                                                      }
                                                    }
                                                    else {
                                                      iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                         (pcVar27,"-servername");
                                                      if (iVar20 == 0) {
                                                        local_res0[0] = local_res0[0] + -1;
                                                        if (0 < local_res0[0]) {
                                                          local_1d0 = ppcVar16[1];
                                                          ppcVar16 = ppcVar16 + 1;
                                                          iVar20 = local_res0[0];
                                                          goto LAB_0044a354;
                                                        }
                                                      }
                                                      else {
                                                        iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                           (pcVar27,"-use_srtp");
                                                        if (iVar20 == 0) {
                                                          local_res0[0] = local_res0[0] + -1;
                                                          if (0 < local_res0[0]) {
                                                            srtp_profiles = ppcVar16[1];
                                                            ppcVar16 = ppcVar16 + 1;
                                                            iVar20 = local_res0[0];
                                                            goto LAB_0044a354;
                                                          }
                                                        }
                                                        else {
                                                          iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                             (pcVar27,
                                                  "-keymatexport");
                                                  if (iVar20 == 0) {
                                                    local_res0[0] = local_res0[0] + -1;
                                                    if (0 < local_res0[0]) {
                                                      keymatexportlabel = ppcVar16[1];
                                                      ppcVar16 = ppcVar16 + 1;
                                                      iVar20 = local_res0[0];
                                                      goto LAB_0044a354;
                                                    }
                                                  }
                                                  else {
                                                    iVar20 = (*(code *)PTR_strcmp_006aac20)
                                                                       (pcVar27,"-keymatexportlen");
                                                    if (iVar20 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      if (0 < local_res0[0]) {
                                                        local_18c[0] = ppcVar16 + 1;
                                                        keymatexportlen =
                                                             (*(code *)PTR_strtol_006aaa68)
                                                                       (ppcVar16[1],0,10);
                                                        iVar12 = keymatexportlen;
                                                        goto joined_r0x0044db00;
                                                      }
                                                    }
                                                    else {
                                                      (*(code *)PTR_BIO_printf_006a7f38)
                                                                (*ppiVar23,"unknown option %s\n",
                                                                 pcVar27);
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_0044a4b4;
                                                  }
                                                  *(undefined4 *)(local_198 + -0x4cf8) = 1;
                                                  iVar20 = local_res0[0];
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
                                      goto LAB_0044a354;
                                    }
                                  }
LAB_0044d0f8:
                                  local_240 = (int **)(*pcVar30)();
                                  ppcVar16 = local_18c[0];
                                  iVar20 = local_res0[0];
                                  goto LAB_0044a354;
                                }
                                local_res0[0] = local_res0[0] + -1;
                                if (0 < local_res0[0]) {
                                  local_18c[0] = ppcVar16 + 1;
                                  local_140 = (*(code *)PTR_strtol_006aaa68)(ppcVar16[1],0,10);
                                  (*(code *)PTR_BIO_printf_006a7f38)
                                            (*ppiVar23,"SRP minimal length for N is %d\n",local_140)
                                  ;
                                  pcVar30 = (code *)PTR_TLSv1_client_method_006a8ab8;
                                  goto LAB_0044d0f8;
                                }
                              }
                            }
                          }
                        }
LAB_0044a4b4:
                        pcVar27 = (char *)0x0;
                        pcVar29 = (char *)0x0;
                        (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"usage: s_client args\n");
                        (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -host host     - use -connect instead\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -port port     - use -connect instead\n");
                        puVar18 = puVar24 + -0x9ba;
                        puVar24 = (undefined4 *)0x0;
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -connect host:port - who to connect to (default is %s:%s)\n",
                                   puVar18,&DAT_0063dae4);
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -verify arg   - turn on peer certificate verification\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -cert arg     - certificate file to use, PEM format assumed\n")
                        ;
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -certform arg - certificate format (PEM or DER) PEM default\n")
                        ;
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -key arg      - Private key file to use, in cert file if\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,"                 not specified but cert file is.\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -keyform arg  - key format (PEM or DER) PEM default\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -pass arg     - private key file pass phrase source\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -CApath arg   - PEM format directory of CA\'s\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -CAfile arg   - PEM format file of CA\'s\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -reconnect    - Drop and re-make the connection with the same Session-ID\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -pause        - sleep(1) after each read(2) and write(2) system call\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -showcerts    - show all certificates in the chain\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -debug        - extra output\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -msg          - Show protocol messages\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -nbio_test    - more ssl protocol testing\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -state        - print the \'ssl\' states\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -nbio         - Run with non-blocking IO\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -crlf         - convert LF from terminal into CRLF\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -quiet        - no s_client output\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -ign_eof      - ignore input eof (default when -quiet)\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -no_ign_eof   - don\'t ignore input eof\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -psk_identity arg - PSK identity\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -psk arg      - PSK in hex (without 0x)\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -srpuser user     - SRP authentification for \'user\'\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -srppass arg      - password for \'user\'\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -srp_lateuser     - SRP username into second ClientHello message\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -srp_moregroups   - Tolerate other than the known g N values.\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -srp_strength int - minimal mength in bits for N (default %d).\n"
                                   ,0x400);
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -ssl2         - just use SSLv2\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -ssl3         - just use SSLv3\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -tls1_2       - just use TLSv1.2\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -tls1_1       - just use TLSv1.1\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -tls1         - just use TLSv1\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -dtls1        - just use DTLSv1\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -mtu          - set the link layer MTU\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -no_tls1_2/-no_tls1_1/-no_tls1/-no_ssl3/-no_ssl2 - turn off that protocol\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -bugs         - Switch on all SSL implementation bug workarounds\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -serverpref   - Use server\'s cipher preferences (only SSLv2)\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -cipher       - preferred cipher to use, use the \'openssl ciphers\'\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,"                 command to see what is available\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -starttls prot - use the STARTTLS command before starting TLS\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   "                 for those protocols that support it, where\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   "                 \'prot\' defines which one to assume.  Currently,\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   "                 only \"smtp\", \"pop3\", \"imap\", \"ftp\" and \"xmpp\"\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,"                 are supported.\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -engine id    - Initialise and use the specified engine\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -rand file%cfile%c...\n",0x3a,0x3a);
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -sess_out arg - file to write SSL session to\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23," -sess_in arg  - file to read SSL session from\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -servername host  - Set TLS extension servername in ClientHello\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -tlsextdebug      - hex dump of all TLS extensions received\n")
                        ;
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -status           - request certificate status from server\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -no_ticket        - disable use of RFC4507bis session tickets\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -nextprotoneg arg - enable NPN extension, considering named protocols supported (comma-separated list)\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -legacy_renegotiation - enable use of legacy renegotiation (dangerous)\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -use_srtp profiles - Offer SRTP key management with a colon-separated profile list\n"
                                  );
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -keymatexport label   - Export keying material using label\n");
                        (*(code *)PTR_BIO_printf_006a7f38)
                                  (*ppiVar23,
                                   " -keymatexportlen len  - Export len bytes of keying material (default 20)\n"
                                  );
                        goto LAB_0044a058;
                      }
                      local_1c0 = (undefined1 *)0x1;
                      iVar20 = local_res0[0];
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_0044a354:
    local_res0[0] = iVar20 + -1;
    local_18c[0] = ppcVar16 + 1;
LAB_0044a318:
    ppcVar16 = local_18c[0];
    iVar20 = local_res0[0];
    if (local_res0[0] < 1) {
      (*(code *)PTR_SSL_library_init_006a8980)();
      (*(code *)PTR_SSL_load_error_strings_006a867c)();
      next_proto._8_4_ = 0xffffffff;
      if (local_204 == (char *)0x0) {
        next_proto._0_4_ = 0;
LAB_0044aca4:
        uVar13 = setup_engine(*ppiVar23,local_1e4,1);
        if (local_1e0 == (char *)0x0) {
          local_248 = (char *)0x0;
        }
        else {
          local_248 = (char *)(*(code *)PTR_ENGINE_by_id_006a7f9c)(local_1e0);
          if (local_248 == (char *)0x0) {
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*(undefined4 *)PTR_bio_err_006a7f3c,"Error getting client auth engine\n");
            goto LAB_0044afb0;
          }
        }
        puVar9 = PTR_bio_err_006a7f3c;
        iVar20 = app_passwd(*ppiVar23,local_1e8,0,&local_178,0);
        if (iVar20 != 0) {
          if (local_1ec == (char *)0x0) {
            pcVar29 = (char *)0x0;
            if (local_208 != (char *)0x0) {
              pcVar27 = (char *)load_key(*(undefined4 *)puVar9,local_208,local_1d8,0,local_178,
                                         uVar13,"client certificate private key file");
              if (pcVar27 != (char *)0x0) goto LAB_0044ad58;
              goto LAB_0044be2c;
            }
            pcVar27 = (char *)0x0;
          }
          else {
            pcVar27 = (char *)load_key(*(undefined4 *)puVar9,local_1ec,local_1d8,0,local_178,uVar13,
                                       "client certificate private key file");
            if (pcVar27 == (char *)0x0) {
LAB_0044be2c:
              (*(code *)PTR_ERR_print_errors_006a7f40)(*ppiVar23);
              goto LAB_0044afb0;
            }
            if (local_208 == (char *)0x0) {
              pcVar29 = (char *)0x0;
            }
            else {
LAB_0044ad58:
              pcVar29 = (char *)load_cert(*ppiVar23,local_208,local_1f0,0,uVar13,
                                          "client certificate file");
              if (pcVar29 == (char *)0x0) {
                puVar24 = (undefined4 *)0x0;
                (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)PTR_bio_err_006a7f3c);
                goto LAB_0044a058;
              }
            }
          }
          iVar20 = app_RAND_load_file(0,*ppiVar23,1);
          if (iVar20 == 0) {
            if (local_1dc == (undefined **)0x0) {
              iVar20 = (*(code *)PTR_RAND_status_006a882c)();
              if (iVar20 == 0) {
                (*(code *)PTR_BIO_printf_006a7f38)
                          (*(undefined4 *)PTR_bio_err_006a7f3c,
                           "warning, not much extra random data, consider using the -rand option\n")
                ;
              }
            }
            else {
LAB_0044adb8:
              piVar22 = *ppiVar23;
              uVar13 = app_RAND_load_files(local_1dc);
              (*(code *)PTR_BIO_printf_006a7f38)(piVar22,"%ld semi-random bytes loaded\n",uVar13);
            }
          }
          else if (local_1dc != (undefined **)0x0) goto LAB_0044adb8;
          if (bio_c_out == (int *)0x0) {
            if (((*(int *)(local_230 + -0x4d1c) == 0) || (c_debug != 0)) || (c_msg != 0)) {
              bio_c_out = (int *)(*(code *)PTR_BIO_new_fp_006a835c)
                                           (*(undefined4 *)PTR_stdout_006aaad4,0);
            }
            else {
              uVar13 = (*(code *)PTR_BIO_s_null_006a89ec)();
              bio_c_out = (int *)(*(code *)PTR_BIO_new_006a7fa4)(uVar13);
            }
          }
          puVar9 = PTR_bio_err_006a7f3c;
          local_230 = PTR_bio_err_006a7f3c;
          local_228 = &local_154;
          iVar20 = app_passwd(*ppiVar23,local_1cc,0,local_228,0);
          if (iVar20 == 0) {
            puVar24 = (undefined4 *)0x0;
            (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar9,"Error getting password\n");
            goto LAB_0044a058;
          }
          puVar24 = (undefined4 *)(*(code *)PTR_SSL_CTX_new_006a8988)(local_240);
          if (puVar24 == (undefined4 *)0x0) {
            (*(code *)PTR_ERR_print_errors_006a7f40)(*(undefined4 *)puVar9);
            goto LAB_0044a058;
          }
          if (local_174 != 0) {
            (*(code *)PTR_SSL_CTX_set1_param_006a89a0)(puVar24);
          }
          if (local_248 != (char *)0x0) {
            iVar20 = (*(code *)PTR_SSL_CTX_set_client_cert_engine_006a8a7c)(puVar24,local_248);
            if (iVar20 == 0) {
              (*(code *)PTR_BIO_puts_006a8058)(*ppiVar23,"Error setting client auth engine\n");
              (*(code *)PTR_ERR_print_errors_006a7f40)(*ppiVar23);
              (*(code *)PTR_ENGINE_free_006a7f84)(local_248);
              goto LAB_0044a058;
            }
            (*(code *)PTR_ENGINE_free_006a7f84)(local_248);
          }
          if (*(int *)PTR_psk_key_006a8a54 != 0) {
            if (c_debug != 0) {
              (*(code *)PTR_BIO_printf_006a7f38)
                        (bio_c_out,"PSK key given or JPAKE in use, setting client callback\n");
            }
            (*(code *)PTR_SSL_CTX_set_psk_client_callback_006a8a80)(puVar24,psk_client_cb);
          }
          if (srtp_profiles != (char *)0x0) {
            (*(code *)PTR_SSL_CTX_set_tlsext_use_srtp_006a8994)(puVar24);
          }
          if (local_1b0 == (undefined4 *)0x0) {
            (*(code *)PTR_SSL_CTX_ctrl_006a884c)(puVar24,0x20,local_200,0);
          }
          else {
            (*(code *)PTR_SSL_CTX_ctrl_006a884c)(puVar24,0x20,local_200 | 0x80000bff);
          }
          if (local_1c8 != (undefined **)0x0) {
            (*(code *)PTR_SSL_CTX_ctrl_006a884c)(puVar24,0x4d,local_1c8,0);
          }
          if (local_1c4 == 1) {
            (*(code *)PTR_SSL_CTX_ctrl_006a884c)(puVar24,0x29,1,0);
          }
          if (next_proto._0_4_ != 0) {
            (*(code *)PTR_SSL_CTX_set_next_proto_select_cb_006a8a84)
                      (puVar24,next_proto_cb,next_proto);
          }
          if (local_1c0 != (undefined1 *)0x0) {
            (*(code *)PTR_SSL_CTX_set_info_callback_006a89e4)
                      (puVar24,PTR_apps_ssl_info_callback_006a89e8);
          }
          if ((local_1b4 != (char *)0x0) &&
             (iVar20 = (*(code *)PTR_SSL_CTX_set_cipher_list_006a89bc)(puVar24,local_1b4),
             iVar20 == 0)) {
            (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"error setting cipher list\n");
            (*(code *)PTR_ERR_print_errors_006a7f40)(*ppiVar23);
            goto LAB_0044a058;
          }
          (*(code *)PTR_SSL_CTX_set_verify_006a89c0)(puVar24,local_214,PTR_verify_callback_006a89c4)
          ;
          iVar20 = set_cert_key_stuff(puVar24,pcVar29,pcVar27);
          if (iVar20 == 0) goto LAB_0044a058;
          iVar20 = (*(code *)PTR_SSL_CTX_load_verify_locations_006a8998)
                             (puVar24,local_1b8,local_1bc);
          if ((iVar20 == 0) ||
             (iVar20 = (*(code *)PTR_SSL_CTX_set_default_verify_paths_006a899c)(puVar24),
             iVar20 == 0)) {
            (*(code *)PTR_ERR_print_errors_006a7f40)(*ppiVar23);
          }
          if (local_1d0 != (char *)0x0) {
            local_15c = *ppiVar23;
            (*(code *)PTR_SSL_CTX_callback_ctrl_006a8910)(puVar24,0x35,ssl_servername_cb);
            (*(code *)PTR_SSL_CTX_ctrl_006a884c)(puVar24,0x36,0,&local_15c);
          }
          if (local_150 != (char *)0x0) {
            if ((local_19c == (undefined *)0x0) &&
               (iVar20 = (*(code *)PTR_SSL_CTX_set_srp_username_006a8a88)(puVar24), iVar20 == 0)) {
              (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"Unable to set SRP username\n");
              goto LAB_0044a058;
            }
            local_14c = c_msg;
            local_148 = c_debug;
            (*(code *)PTR_SSL_CTX_set_srp_cb_arg_006a89f4)(puVar24,local_228);
            (*(code *)PTR_SSL_CTX_set_srp_client_pwd_callback_006a8a8c)
                      (puVar24,ssl_give_srp_client_pwd_cb);
            (*(code *)PTR_SSL_CTX_set_srp_strength_006a8a90)(puVar24,local_140);
            if (((c_msg != 0) || (c_debug != 0)) || (local_144 == 0)) {
              (*(code *)PTR_SSL_CTX_set_srp_verify_param_callback_006a8a94)
                        (puVar24,ssl_srp_verify_param_cb);
            }
          }
          local_240 = (int **)(*(code *)PTR_SSL_new_006a88cc)(puVar24);
          if (local_1f4 == (char *)0x0) {
LAB_0044b308:
            if ((local_1d0 == (char *)0x0) ||
               (iVar20 = (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x37,0,local_1d0), iVar20 != 0))
            {
              local_214 = &_ITM_registerTMCloneTable;
              local_1b0 = &local_180;
              local_20c = (undefined4 *)0x1;
              local_1f4 = (char *)0x1;
              local_1c0 = &_ITM_registerTMCloneTable;
              local_1bc = "s\n";
              local_1b8 = "<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'";
              local_1b4 = "/stream:features>";
              local_1ec = "STARTTLS";
              break;
            }
            (*(code *)PTR_BIO_printf_006a7f38)
                      (*ppiVar23,"Unable to set TLS servername extension.\n");
          }
          else {
            iVar20 = (*(code *)PTR_BIO_new_file_006a7fac)(local_1f4,"r");
            if (iVar20 != 0) {
              iVar12 = (*(code *)PTR_PEM_read_bio_SSL_SESSION_006a8a98)(iVar20,0,0,0);
              (*(code *)PTR_BIO_free_006a7f70)(iVar20);
              if (iVar12 != 0) {
                (*(code *)PTR_SSL_set_session_006a8a9c)(local_240,iVar12);
                (*(code *)PTR_SSL_SESSION_free_006a8aa0)(iVar12);
                goto LAB_0044b308;
              }
            }
            (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"Can\'t open session file %s\n",local_1f4);
          }
          (*(code *)PTR_ERR_print_errors_006a7f40)(*ppiVar23);
          local_248 = (char *)0x1;
          goto LAB_0044bb44;
        }
        (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)puVar9,"Error getting password\n");
      }
      else {
        next_proto._0_4_ = next_protos_parse(0x6ab2d8,local_204);
        if (next_proto._0_4_ != 0) goto LAB_0044aca4;
        (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"Error parsing -nextprotoneg argument\n");
      }
LAB_0044afb0:
      puVar24 = (undefined4 *)0x0;
      pcVar27 = (char *)0x0;
      pcVar29 = (char *)0x0;
      goto LAB_0044a058;
    }
    pcVar27 = *local_18c[0];
    iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar27,pcVar19);
    if (iVar12 == 0) {
      local_res0[0] = iVar20 + -1;
      if (local_res0[0] == 0) goto LAB_0044a4b4;
      local_17c = ppcVar16[1];
      ppcVar16 = ppcVar16 + 1;
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
    iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar27,local_248);
    if (iVar12 == 0) {
      local_res0[0] = iVar20 + -1;
      if (local_res0[0] == 0) goto LAB_0044a4b4;
      local_18c[0] = ppcVar16 + 1;
      local_182 = (*(code *)PTR_strtol_006aaa68)(ppcVar16[1],0,10);
      ppcVar16 = local_18c[0];
      iVar20 = local_res0[0];
      if (local_182 != 0) goto LAB_0044a354;
      goto LAB_0044a4b4;
    }
    iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar27,local_220 + -0x26d4);
    if (iVar12 == 0) {
      local_res0[0] = iVar20 + -1;
      if (local_res0[0] == 0) goto LAB_0044a4b4;
      local_18c[0] = ppcVar16 + 1;
      iVar12 = extract_host_port(ppcVar16[1],&local_17c,0,&local_182);
joined_r0x0044db00:
      ppcVar16 = local_18c[0];
      iVar20 = local_res0[0];
      if (iVar12 == 0) goto LAB_0044a4b4;
      goto LAB_0044a354;
    }
    iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar27,local_218);
    if (iVar12 == 0) {
      local_res0[0] = iVar20 + -1;
      if (local_res0[0] == 0) goto LAB_0044a4b4;
      local_18c[0] = ppcVar16 + 1;
      uVar13 = (*(code *)PTR_strtol_006aaa68)(ppcVar16[1],0,10);
      puVar9 = PTR_BIO_printf_006a7f38;
      piVar22 = *ppiVar23;
      *local_20c = uVar13;
      (*(code *)puVar9)(piVar22,"verify depth is %d\n",uVar13);
      local_214 = (undefined1 *)0x1;
      ppcVar16 = local_18c[0];
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
    iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar27,local_210 + -0xe88);
    if (iVar12 == 0) {
      local_res0[0] = iVar20 + -1;
      if (local_res0[0] == 0) goto LAB_0044a4b4;
      local_208 = ppcVar16[1];
      ppcVar16 = ppcVar16 + 1;
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
    iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-sess_out");
    if (iVar12 == 0) {
      local_res0[0] = iVar20 + -1;
      if (local_res0[0] == 0) goto LAB_0044a4b4;
      local_1fc = ppcVar16[1];
      ppcVar16 = ppcVar16 + 1;
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
    iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-sess_in");
    if (iVar12 == 0) {
      local_res0[0] = iVar20 + -1;
      if (local_res0[0] == 0) goto LAB_0044a4b4;
      local_1f4 = ppcVar16[1];
      ppcVar16 = ppcVar16 + 1;
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
    iVar12 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-certform");
    if (iVar12 == 0) {
      local_res0[0] = iVar20 + -1;
      if (local_res0[0] == 0) goto LAB_0044a4b4;
      local_18c[0] = ppcVar16 + 1;
      local_1f0 = (undefined4 *)str2fmt(ppcVar16[1]);
      ppcVar16 = local_18c[0];
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
    iVar20 = args_verify(local_18c,local_res0,&local_170,*ppiVar23,&local_174);
    ppcVar16 = local_18c[0];
    if (iVar20 != 0) goto code_r0x0044aee4;
    pcVar27 = *local_18c[0];
    iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-verify_return_error");
    if (iVar20 == 0) {
      *(undefined4 *)PTR_verify_return_error_006a8a0c = 1;
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
    iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-prexit");
    if (iVar20 == 0) {
      local_224 = 1;
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
    iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-crlf");
    if (iVar20 == 0) {
      local_1ac = 1;
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
    iVar20 = (*(code *)PTR_strcmp_006aac20)(pcVar27,"-quiet");
    if (iVar20 == 0) {
      *(undefined4 *)(local_230 + -0x4d1c) = 1;
      c_ign_eof = 1;
      iVar20 = local_res0[0];
      goto LAB_0044a354;
    }
  } while( true );
LAB_0044b394:
  iVar20 = init_client(local_1b0,local_17c,(int)local_182,local_1c4);
  local_230 = puVar26;
  local_228 = puVar24;
  local_220 = pcVar29;
  local_218 = pcVar27;
  if (iVar20 == 0) goto LAB_0044c7d4;
  (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"CONNECTED(%08X)\n",local_180);
  if (*(int *)(local_198 + -0x4cf8) != 0) {
    local_168 = 1;
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"turning on non blocking io\n");
    iVar20 = (*(code *)PTR_BIO_socket_ioctl_006a88c8)(local_180,0x667e,&local_168);
    if (iVar20 < 0) {
      (*(code *)PTR_ERR_print_errors_006a7f40)(*ppiVar23);
      local_248 = (char *)0x1;
      goto LAB_0044bb44;
    }
  }
  if ((c_Pause & 1) != 0) {
    (*(code *)PTR_SSL_set_debug_006a8920)(local_240,1);
  }
  iVar20 = (*(code *)PTR_SSL_version_006a88d8)(local_240);
  if (iVar20 == 0xfeff) {
    uVar13 = (*(code *)PTR_BIO_new_dgram_006a892c)(local_180,0);
    iVar20 = (*(code *)PTR_getsockname_006aaaa0)(local_180,auStack_13c,&local_16c);
    if (iVar20 < 0) {
      ppiVar23 = (int **)*ppiVar23;
      puVar18 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
      uVar13 = *puVar18;
      pcVar19 = "getsockname:errno=%d\n";
      goto LAB_0044c810;
    }
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar13,0x20,1,auStack_13c);
    if (local_1a4 != 0) {
      local_164 = 0;
      local_160 = 250000;
      (*(code *)PTR_BIO_ctrl_006a7f18)(uVar13,0x21,0,&local_164);
      local_164 = 0;
      local_160 = 250000;
      (*(code *)PTR_BIO_ctrl_006a7f18)(uVar13,0x23,0,&local_164);
    }
    if (local_1a0 < 0x1d) {
      (*(code *)PTR_BIO_ctrl_006a7f18)(uVar13,0x27,0,0);
    }
    else {
      (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x20,0x1000,0);
      (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x11,local_1a0 + -0x1c,0);
    }
  }
  else {
    uVar13 = (*(code *)PTR_BIO_new_socket_006a88dc)(local_180,0);
  }
  if (local_1a8 != 0) {
    uVar17 = (*(code *)PTR_BIO_f_nbio_test_006a88e0)();
    uVar17 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
    uVar13 = (*(code *)PTR_BIO_push_006a85c0)(uVar17,uVar13);
  }
  if (c_debug != 0) {
    (*(code *)PTR_SSL_set_debug_006a8920)(local_240,1);
    (*(code *)PTR_BIO_set_callback_006a85d8)(uVar13,PTR_bio_dump_callback_006a8928);
    (*(code *)PTR_BIO_set_callback_arg_006a85e0)(uVar13,bio_c_out);
  }
  if (c_msg != 0) {
    (*(code *)PTR_SSL_set_msg_callback_006a88ec)(local_240,PTR_msg_cb_006a891c);
    (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x10,0,bio_c_out);
  }
  if (c_tlsextdebug != 0) {
    (*(code *)PTR_SSL_callback_ctrl_006a8914)(local_240,0x38,PTR_tlsext_cb_006a8918);
    (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x39,0,bio_c_out);
  }
  if (c_status_req != 0) {
    (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x41,1,0);
    (*(code *)PTR_SSL_CTX_callback_ctrl_006a8910)(puVar24,0x3f,ocsp_resp_cb);
    (*(code *)PTR_SSL_CTX_ctrl_006a884c)(puVar24,0x40,0,bio_c_out);
  }
  (*(code *)PTR_SSL_set_bio_006a88e4)(local_240,uVar13,uVar13);
  (*(code *)PTR_SSL_set_connect_state_006a8aa8)(local_240);
  iVar20 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
  local_1e0 = (char *)(iVar20 + 1);
  if (local_1f8 == 1) {
    uVar17 = (*(code *)PTR_BIO_f_buffer_006a8940)();
    uVar17 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
    (*(code *)PTR_BIO_push_006a85c0)(uVar17,uVar13);
    do {
      iVar20 = (*(code *)PTR_BIO_gets_006a85d0)(uVar17,pcVar25,0x2000);
      if (iVar20 < 4) break;
    } while (pcVar25[3] == '-');
    bVar3 = false;
    (*(code *)PTR_BIO_printf_006a7f38)(uVar17,"EHLO openssl.client.net\r\n");
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar17,0xb,0,0);
    do {
      iVar20 = (*(code *)PTR_BIO_gets_006a85d0)(uVar17,pcVar25,0x2000);
      iVar12 = (*(code *)PTR_strstr_006aac24)(pcVar25,"STARTTLS");
      if (iVar12 != 0) {
        bVar3 = true;
      }
    } while ((3 < iVar20) && (pcVar25[3] == '-'));
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar17,0xb,0,0);
    (*(code *)PTR_BIO_pop_006a8ab4)(uVar17);
    (*(code *)PTR_BIO_free_006a7f70)(uVar17);
    if (!bVar3) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*ppiVar23,"didn\'t found starttls in server response, try anyway...\n");
    }
    pcVar19 = "STARTTLS\r\n";
  }
  else if (local_1f8 == 2) {
    (*(code *)PTR_BIO_read_006a85bc)(uVar13,pcVar25,0x2000);
    pcVar19 = "STLS\r\n";
  }
  else if (local_1f8 == 3) {
    bVar3 = false;
    uVar17 = (*(code *)PTR_BIO_f_buffer_006a8940)();
    uVar17 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
    (*(code *)PTR_BIO_push_006a85c0)(uVar17,uVar13);
    (*(code *)PTR_BIO_gets_006a85d0)(uVar17,pcVar25,0x2000);
    (*(code *)PTR_BIO_printf_006a7f38)(uVar17,". CAPABILITY\r\n");
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar17,0xb,0,0);
    do {
      iVar20 = (*(code *)PTR_BIO_gets_006a85d0)(uVar17,pcVar25,0x2000);
      iVar12 = (*(code *)PTR_strstr_006aac24)(pcVar25,"STARTTLS");
      if (iVar12 != 0) {
        bVar3 = true;
      }
    } while ((3 < iVar20) && (*pcVar25 != '.'));
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar17,0xb,0,0);
    (*(code *)PTR_BIO_pop_006a8ab4)(uVar17);
    (*(code *)PTR_BIO_free_006a7f70)(uVar17);
    if (!bVar3) {
      (*(code *)PTR_BIO_printf_006a7f38)
                (*ppiVar23,"didn\'t found STARTTLS in server response, try anyway...\n");
    }
    pcVar19 = ". STARTTLS\r\n";
  }
  else {
    if (local_1f8 != 4) {
      if (local_1f8 != 5) goto LAB_0044b4e0;
      (*(code *)PTR_BIO_printf_006a7f38)
                (uVar13,
                 "<stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\' xmlns=\'jabber:client\' to=\'%s\' version=\'1.0\'>"
                 ,local_17c);
      while( true ) {
        iVar20 = (*(code *)PTR_BIO_read_006a85bc)(uVar13,pcVar25,0x2000);
        pcVar25[iVar20] = '\0';
        iVar20 = (*(code *)PTR_strstr_006aac24)
                           (pcVar25,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'");
        if (iVar20 != 0) break;
        iVar20 = (*(code *)PTR_strstr_006aac24)(pcVar25,"/stream:features>");
        if (iVar20 != 0) goto LAB_0044c2dc;
      }
      (*(code *)PTR_BIO_printf_006a7f38)
                (uVar13,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'/>");
      iVar20 = (*(code *)PTR_BIO_read_006a85bc)(uVar13,puVar26,0x2000);
      puVar26[iVar20] = 0;
      iVar20 = (*(code *)PTR_strstr_006aac24)(puVar26,"<proceed");
      if (iVar20 == 0) {
LAB_0044c2dc:
        local_248 = (char *)0x1;
LAB_0044bae0:
        if (local_20c != (undefined4 *)0x0) {
          print_stuff(bio_c_out,local_240,local_1f4);
        }
        (*(code *)PTR_SSL_shutdown_006a8ab0)(local_240);
        uVar13 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
        (*(code *)PTR_shutdown_006aaa6c)(uVar13,0);
        uVar13 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
        (*(code *)PTR_close_006aaa5c)(uVar13);
        ppiVar23 = local_240;
        goto LAB_0044bb44;
      }
      *pcVar25 = '\0';
      goto LAB_0044b4e0;
    }
    uVar17 = (*(code *)PTR_BIO_f_buffer_006a8940)();
    uVar17 = (*(code *)PTR_BIO_new_006a7fa4)(uVar17);
    (*(code *)PTR_BIO_push_006a85c0)(uVar17,uVar13);
    do {
      iVar20 = (*(code *)PTR_BIO_gets_006a85d0)(uVar17,pcVar25,0x2000);
      if (iVar20 < 4) break;
    } while (pcVar25[3] == '-');
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar17,0xb,0,0);
    (*(code *)PTR_BIO_pop_006a8ab4)(uVar17);
    (*(code *)PTR_BIO_free_006a7f70)(uVar17);
    pcVar19 = "AUTH TLS\r\n";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(uVar13,pcVar19);
  (*(code *)PTR_BIO_read_006a85bc)(uVar13,puVar26,0x2000);
LAB_0044b4e0:
  local_200 = 0;
  local_1e4 = auStack_12c;
  local_204 = (char *)0x0;
  local_208 = (char *)0x0;
  bVar3 = true;
  local_1e8 = auStack_ac;
  bVar4 = true;
  local_1dc = &switchD_0044ba00::switchdataD_0063e8c0;
  iVar20 = 0;
  bVar5 = false;
  local_1d8 = "s\n";
  bVar7 = true;
  local_1d0 = "read R BLOCK\n";
  local_1cc = "s\n";
  local_1c8 = &switchD_0044c96c::switchdataD_0063e8dc;
switchD_0044c96c_caseD_7:
  (*(code *)PTR_memset_006aab00)(local_1e4,0,0x80);
  (*(code *)PTR_memset_006aab00)(local_1e8,0,0x80);
  iVar12 = (*(code *)PTR_SSL_version_006a88d8)(local_240);
  if (iVar12 == 0xfeff) {
    local_1f0 = &local_164;
    iVar12 = (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x49,0,local_1f0);
    if (iVar12 == 0) goto LAB_0044b59c;
  }
  else {
LAB_0044b59c:
    local_1f0 = (undefined4 *)0x0;
  }
  uVar14 = (*(code *)PTR_SSL_state_006a88f4)(local_240);
  local_210 = pcVar25;
  if (((uVar14 & 0x3000) != 0) &&
     (iVar12 = (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0xc,0,0), iVar12 == 0)) {
    local_20c = (undefined4 *)0x1;
    if (bVar7) {
      bVar6 = false;
      goto LAB_0044b98c;
    }
LAB_0044b67c:
    if (bVar3) {
      iVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
      uVar13 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
      iVar15 = (*(code *)PTR___fdelt_chk_006aaba8)(uVar13);
      auStack_ac[iVar15] = auStack_ac[iVar15] | 1 << (iVar12 % 0x20 & 0x1fU);
    }
    iVar12 = (*(code *)PTR_select_006aabcc)(local_1e0,local_1e4,local_1e8,0,local_1f0);
    if (iVar12 < 0) {
      piVar22 = *ppiVar23;
      puVar18 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
      (*(code *)PTR_BIO_printf_006a7f38)(piVar22,"bad select %d\n",*puVar18);
      local_248 = (char *)0x1;
      goto LAB_0044bae0;
    }
    iVar12 = (*(code *)PTR_SSL_version_006a88d8)(local_240);
    if ((iVar12 == 0xfeff) &&
       (iVar12 = (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x4a,0,0), 0 < iVar12)) {
      bVar6 = false;
LAB_0044bec8:
      (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"TIMEOUT occured\n");
      if (bVar6) goto LAB_0044b9bc;
    }
    uVar13 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
    iVar12 = (*(code *)PTR___fdelt_chk_006aaba8)(uVar13);
    local_1f0 = (undefined4 *)auStack_ac[iVar12];
    iVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
    puVar9 = PTR_stdout_006aaad4;
    if ((1 << (iVar12 % 0x20 & 0x1fU) & (uint)local_1f0) != 0) goto LAB_0044c91c;
    uVar13 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)PTR_stdout_006aaad4);
    iVar12 = (*(code *)PTR___fdelt_chk_006aaba8)(uVar13);
    local_1f0 = (undefined4 *)auStack_ac[iVar12];
    iVar12 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)puVar9);
    if ((1 << (iVar12 % 0x20 & 0x1fU) & (uint)local_1f0) == 0) {
      uVar13 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
      iVar12 = (*(code *)PTR___fdelt_chk_006aaba8)(uVar13);
      local_1f0 = (undefined4 *)auStack_12c[iVar12];
      iVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
      puVar9 = PTR_stdin_006aab20;
      if ((1 << (iVar12 % 0x20 & 0x1fU) & (uint)local_1f0) != 0) goto LAB_0044b9bc;
      uVar13 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)PTR_stdin_006aab20);
      iVar12 = (*(code *)PTR___fdelt_chk_006aaba8)(uVar13);
      local_1f0 = (undefined4 *)auStack_12c[iVar12];
      iVar12 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)puVar9);
      if ((1 << (iVar12 % 0x20 & 0x1fU) & (uint)local_1f0) != 0) {
        if (local_1ac == 0) {
          iVar20 = raw_read_stdin(pcVar31,0x2000);
        }
        else {
          iVar20 = raw_read_stdin(pcVar31,0x1000);
          iVar12 = 0;
          pcVar19 = pcVar31;
          while ((int)pcVar19 - (int)pcVar31 < iVar20) {
            cVar1 = *pcVar19;
            pcVar19 = pcVar19 + 1;
            if (cVar1 == '\n') {
              iVar12 = iVar12 + 1;
            }
          }
          iVar15 = iVar20 + -1;
          pcVar19 = pcVar31 + iVar20;
          while (-1 < iVar15) {
            pcVar31[iVar12 + iVar15] = pcVar19[-1];
            if (pcVar19[-1] == '\n') {
              iVar12 = iVar12 + -1;
              iVar20 = iVar20 + 1;
              iVar8 = iVar12 + iVar15;
              iVar15 = iVar15 + -1;
              pcVar31[iVar8] = '\r';
              pcVar19 = pcVar19 + -1;
            }
            else {
              iVar15 = iVar15 + -1;
              pcVar19 = pcVar19 + -1;
            }
          }
          if (iVar12 != 0) {
            pcVar25 = (char *)(*(code *)PTR___assert_fail_006aaa4c)
                                        ("lf_num == 0",local_21c + -0x29b0,0x738,"s_client_main");
            return pcVar25;
          }
        }
        bVar3 = true;
        if (c_ign_eof == 0) {
          if ((iVar20 < 1) || (cVar1 = *pcVar31, cVar1 == 'Q')) {
            piVar22 = *ppiVar23;
            goto LAB_0044c998;
          }
          if (cVar1 == 'R') {
            bVar3 = true;
            bVar4 = false;
            (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"RENEGOTIATING\n");
            iVar20 = 0;
            (*(code *)PTR_SSL_renegotiate_006a8934)(local_240);
            goto switchD_0044c96c_caseD_7;
          }
          if (cVar1 == 'B') {
            bVar3 = true;
            bVar4 = false;
            (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"HEARTBEATING\n");
            iVar20 = 0;
            (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x55,0,0);
            goto switchD_0044c96c_caseD_7;
          }
        }
        local_208 = (char *)0x0;
        bVar4 = false;
      }
    }
    else {
      iVar12 = raw_write_stdout(puVar26 + local_200,local_204);
      piVar22 = bio_c_out;
      if (iVar12 < 1) {
LAB_0044c998:
        (*(code *)PTR_BIO_printf_006a7f38)(piVar22,"DONE\n");
        local_248 = (char *)0x0;
        goto LAB_0044bae0;
      }
      local_204 = local_204 + -iVar12;
      local_200 = local_200 + iVar12;
      if ((int)local_204 < 1) {
        bVar7 = true;
        bVar5 = false;
      }
    }
    goto switchD_0044c96c_caseD_7;
  }
  if (local_20c != (undefined4 *)0x0) {
    if (local_1fc != (char *)0x0) {
      iVar12 = (*(code *)PTR_BIO_new_file_006a7fac)(local_1fc,"w");
      if (iVar12 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"Error writing session file %s\n",local_1fc);
      }
      else {
        uVar13 = (*(code *)PTR_SSL_get_session_006a8898)(local_240);
        (*(code *)PTR_PEM_write_bio_SSL_SESSION_006a889c)(iVar12,uVar13);
        (*(code *)PTR_BIO_free_006a7f70)(iVar12);
      }
    }
    print_stuff(bio_c_out,local_240,local_1f4);
    if (local_1f4 == (char *)0x1) {
      local_1f4 = (char *)0x0;
    }
    if (local_1f8 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"%s",pcVar25);
    }
    if (local_1d4 != 0) goto LAB_0044cfe4;
    local_1f8 = 0;
  }
  local_20c = (undefined4 *)0x0;
  if (!bVar7) {
LAB_0044b664:
    puVar10 = PTR_stdin_006aab20;
    puVar9 = PTR_stdout_006aaad4;
    if (bVar4) {
      local_19c = (undefined *)(*(code *)PTR_fileno_006aaae8)(*(undefined4 *)PTR_stdin_006aab20);
      uVar13 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)puVar10);
      iVar12 = (*(code *)PTR___fdelt_chk_006aaba8)(uVar13);
      puVar9 = PTR_stdout_006aaad4;
      auStack_12c[iVar12] = 1 << ((int)local_19c % 0x20 & 0x1fU) | auStack_12c[iVar12];
      if (bVar5) {
        local_19c = PTR_stdout_006aaad4;
        iVar12 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)PTR_stdout_006aaad4);
        uVar13 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)puVar9);
        goto LAB_0044c0ec;
      }
    }
    else if (bVar5) {
      iVar12 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)PTR_stdout_006aaad4);
      uVar13 = (*(code *)PTR_fileno_006aaae8)(*(undefined4 *)puVar9);
LAB_0044c0ec:
      iVar15 = (*(code *)PTR___fdelt_chk_006aaba8)(uVar13);
      auStack_ac[iVar15] = auStack_ac[iVar15] | 1 << (iVar12 % 0x20 & 0x1fU);
    }
    if (bVar7) {
LAB_0044ba0c:
      iVar12 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
      uVar13 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
      iVar15 = (*(code *)PTR___fdelt_chk_006aaba8)(uVar13);
      auStack_12c[iVar15] = auStack_12c[iVar15] | 1 << (iVar12 % 0x20 & 0x1fU);
    }
    goto LAB_0044b67c;
  }
  bVar6 = true;
LAB_0044b98c:
  iVar12 = (*(code *)PTR_SSL_pending_006a88f0)(local_240);
  if (iVar12 == 0) {
    if (bVar6) goto LAB_0044b664;
    if (!bVar7) goto LAB_0044b67c;
    goto LAB_0044ba0c;
  }
  iVar12 = (*(code *)PTR_SSL_version_006a88d8)(local_240);
  if ((iVar12 == 0xfeff) &&
     (iVar12 = (*(code *)PTR_SSL_ctrl_006a8878)(local_240,0x4a,0,0), 0 < iVar12)) {
    bVar6 = true;
    goto LAB_0044bec8;
  }
LAB_0044b9bc:
  pcVar19 = (char *)(*(code *)PTR_SSL_read_006a8904)(local_240,puVar26,0x400);
  uVar13 = (*(code *)PTR_SSL_get_error_006a8890)(local_240,pcVar19);
  switch(uVar13) {
  case 0:
    if ((int)pcVar19 < 1) goto LAB_0044c014;
    bVar7 = false;
    bVar5 = true;
    local_200 = 0;
    local_204 = pcVar19;
    break;
  case 1:
    goto switchD_0044c96c_caseD_1;
  case 2:
    bVar7 = true;
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"read R BLOCK\n");
    if (bVar4) {
      bVar4 = true;
      bVar5 = false;
    }
    else {
      bVar3 = true;
      bVar5 = false;
    }
    break;
  case 3:
    bVar3 = true;
    bVar4 = false;
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"read W BLOCK\n");
    break;
  case 4:
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"read X BLOCK\n");
    break;
  case 5:
    ppcVar16 = (char **)(*(code *)PTR___errno_location_006aaaf4)();
    local_248 = *ppcVar16;
    (*(code *)PTR_BIO_printf_006a7f38)(*ppiVar23,"read:errno=%d\n",local_248);
    goto LAB_0044bae0;
  case 6:
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"closed\n");
    local_248 = (char *)0x0;
    goto LAB_0044bae0;
  }
  goto switchD_0044c96c_caseD_7;
LAB_0044c7d4:
  ppiVar23 = (int **)*ppiVar23;
  puVar18 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  uVar13 = *puVar18;
  pcVar19 = "connect:errno=%d\n";
LAB_0044c810:
  (*(code *)PTR_BIO_printf_006a7f38)(ppiVar23,pcVar19,uVar13);
  (*(code *)PTR_shutdown_006aaa6c)(local_180,0);
  (*(code *)PTR_close_006aaa5c)(local_180);
  local_248 = (char *)0x1;
LAB_0044bb44:
  if (local_240 != (int **)0x0) {
    if (local_224 != 0) {
      print_stuff(bio_c_out,local_240,1);
    }
    (*(code *)PTR_SSL_free_006a88fc)(local_240);
  }
  if (next_proto._0_4_ != 0) goto LAB_0044a06c;
  (*(code *)PTR_SSL_CTX_free_006a8978)(puVar24);
  goto LAB_0044a08c;
LAB_0044cfe4:
  local_1d4 = local_1d4 + -1;
  (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"drop connection and then reconnect\n");
  (*(code *)PTR_SSL_shutdown_006a8ab0)(local_240);
  (*(code *)PTR_SSL_set_connect_state_006a8aa8)(local_240);
  uVar13 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
  (*(code *)PTR_shutdown_006aaa6c)(uVar13,0);
  uVar13 = (*(code *)PTR_SSL_get_fd_006a8aac)(local_240);
  (*(code *)PTR_close_006aaa5c)(uVar13);
  local_20c = (undefined4 *)0x0;
  local_1f8 = 0;
  goto LAB_0044b394;
LAB_0044c91c:
  iVar12 = (*(code *)PTR_SSL_write_006a890c)(local_240,pcVar31 + (int)local_208,iVar20);
  uVar13 = (*(code *)PTR_SSL_get_error_006a8890)(local_240,iVar12);
  switch(uVar13) {
  case 0:
    iVar20 = iVar20 - iVar12;
    local_208 = local_208 + iVar12;
    if (iVar12 < 1) {
LAB_0044c014:
      local_248 = (char *)0x1;
      goto LAB_0044bb44;
    }
    bVar3 = 0 < iVar20;
    bVar4 = !bVar3;
    goto switchD_0044c96c_caseD_7;
  case 1:
switchD_0044c96c_caseD_1:
    (*(code *)PTR_ERR_print_errors_006a7f40)(*ppiVar23);
    local_248 = (char *)0x1;
    goto LAB_0044bae0;
  case 2:
    bVar7 = true;
    bVar3 = false;
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"write R BLOCK\n");
    bVar5 = false;
    goto switchD_0044c96c_caseD_7;
  case 3:
    bVar3 = true;
    bVar4 = false;
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"write W BLOCK\n");
    goto switchD_0044c96c_caseD_7;
  case 4:
    (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"write X BLOCK\n");
    goto switchD_0044c96c_caseD_7;
  case 5:
    if ((iVar12 != 0) || (iVar20 != 0)) {
      piVar22 = *ppiVar23;
      puVar18 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
      (*(code *)PTR_BIO_printf_006a7f38)(piVar22,"write:errno=%d\n",*puVar18);
      local_248 = (char *)0x1;
      goto LAB_0044bae0;
    }
    break;
  case 6:
    if (iVar20 != 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(bio_c_out,"shutdown\n");
      local_248 = (char *)0x0;
      goto LAB_0044bae0;
    }
    break;
  default:
    goto switchD_0044c96c_caseD_7;
  }
  bVar3 = false;
  bVar4 = true;
  goto switchD_0044c96c_caseD_7;
code_r0x0044aee4:
  if (local_170 != 0) goto LAB_0044a4b4;
  goto LAB_0044a318;
}

