
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void s_client_main(int param_1,char **param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  char cVar9;
  SSL_CTX *pkey;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  SSL_CTX *ctx;
  SSL *to;
  BIO *pBVar13;
  SSL_SESSION *pSVar14;
  long lVar15;
  BIO_METHOD *pBVar16;
  BIO *pBVar17;
  uint uVar18;
  int iVar19;
  int *piVar20;
  uint uVar21;
  size_t sVar22;
  size_t sVar23;
  ushort **ppuVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  char **ppcVar28;
  char *pcVar29;
  uint uVar30;
  bool bVar31;
  SSL_CTX *local_234;
  SSL_CTX *local_230;
  SSL_CTX *local_22c;
  SSL_CTX *local_228;
  SSL_METHOD *local_224;
  int local_218;
  undefined4 local_214;
  SSL_CTX *local_210;
  SSL_CTX *local_20c;
  uint local_208;
  char *local_204;
  char *local_200;
  undefined4 local_1fc;
  SSL_CTX *local_1f8;
  int local_1f4;
  char *local_1f0;
  char *local_1ec;
  char *local_1e8;
  char *local_1e4;
  timeval *local_1e0;
  int local_1dc;
  long local_1d8;
  int local_1d4;
  char *local_1d0;
  char *local_1cc;
  char *local_1c8;
  undefined4 local_1b4;
  char **local_1a8;
  int local_1a4;
  short local_1a0 [4];
  char *local_198 [2];
  void *local_190 [2];
  X509_VERIFY_PARAM *local_188 [2];
  int local_180 [2];
  socklen_t local_178 [2];
  int local_170;
  undefined4 local_16c;
  BIO *local_168;
  undefined4 local_164;
  timeval local_160;
  void *local_158;
  char *local_154;
  int local_150;
  int local_14c;
  int local_148;
  long local_144;
  fd_set fStack_13c;
  fd_set fStack_bc;
  sockaddr sStack_3c;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_198[0] = "localhost";
  local_158 = (void *)0x0;
  local_154 = (char *)0x0;
  local_150 = 0;
  local_14c = 0;
  local_148 = 0;
  local_144 = 0x400;
  local_1a0[0] = 0x1151;
  local_190[0] = (void *)0x0;
  local_178[0] = 0x10;
  local_188[0] = (X509_VERIFY_PARAM *)0x0;
  local_180[0] = 0;
  local_168 = (BIO *)0x0;
  local_164 = 0;
  local_1a8 = param_2;
  local_1a4 = param_1;
  local_224 = SSLv23_client_method();
  signal(0xd,(__sighandler_t)0x1);
  c_Pause = 0;
  c_quiet = 0;
  c_ign_eof = 0;
  c_debug = 0;
  c_msg = 0;
  c_showcerts = 0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  pkey = (SSL_CTX *)load_config(bio_err,0);
  ctx = pkey;
  local_234 = pkey;
  local_230 = pkey;
  local_22c = pkey;
  local_228 = pkey;
  if (pkey != (SSL_CTX *)0x0) {
    local_230 = (SSL_CTX *)CRYPTO_malloc(0x2000,"s_client.c",0x2c4);
    if ((local_230 == (SSL_CTX *)0x0) ||
       (local_234 = (SSL_CTX *)CRYPTO_malloc(0x2000,"s_client.c",0x2c5), local_234 == (SSL_CTX *)0x0
       )) {
      local_234 = (SSL_CTX *)0x0;
    }
    else {
      local_22c = (SSL_CTX *)CRYPTO_malloc(0x2000,"s_client.c",0x2c6);
      if (local_22c != (SSL_CTX *)0x0) {
        local_214 = 3;
        local_1a4 = local_1a4 + -1;
        verify_depth = 0;
        local_1a8 = local_1a8 + 1;
        local_1e0 = (timeval *)0x0;
        bVar1 = false;
        c_nbio = 0;
        local_1d8 = 0;
        verify_error = 0;
        bVar7 = false;
        bVar3 = false;
        local_200 = (char *)0x0;
        local_204 = (char *)0x0;
        local_210 = (SSL_CTX *)0x0;
        local_1e4 = (char *)0x0;
        local_20c = (SSL_CTX *)0x0;
        local_1ec = (char *)0x0;
        local_1e8 = (char *)0x0;
        bVar5 = false;
        local_1f4 = 0;
        bVar4 = false;
        bVar6 = false;
        bVar31 = false;
        local_218 = 0;
        local_1dc = 0;
        local_1c8 = (char *)0x0;
        local_1cc = (char *)0x0;
        local_1d0 = (char *)0x0;
        local_1f0 = (char *)0x0;
        local_1f8 = (SSL_CTX *)0x0;
        local_228 = (SSL_CTX *)0x0;
        bVar2 = false;
        local_1fc = 3;
        local_1d4 = 0;
        local_208 = 0;
        local_1b4 = 1;
LAB_0002a8c2:
        iVar27 = local_1a4;
        ppcVar28 = local_1a8;
        if (local_1a4 < 1) {
          SSL_library_init();
          SSL_load_error_strings();
          next_proto._8_4_ = 0xffffffff;
          if (local_210 == (SSL_CTX *)0x0) {
            next_proto._0_4_ = local_210;
          }
          else {
            pkey = (SSL_CTX *)next_protos_parse(0x195288,local_210);
            next_proto._0_4_ = pkey;
            if (pkey == (SSL_CTX *)0x0) {
              BIO_printf(bio_err,"Error parsing -nextprotoneg argument\n");
              ctx = pkey;
              local_228 = pkey;
              goto LAB_0002a746;
            }
          }
          uVar12 = setup_engine(bio_err,local_1ec,1);
          if ((local_20c != (SSL_CTX *)0x0) &&
             (pkey = (SSL_CTX *)ENGINE_by_id((char *)local_20c), local_20c = pkey,
             pkey == (SSL_CTX *)0x0)) {
            BIO_printf(bio_err,"Error getting client auth engine\n");
            ctx = pkey;
            local_228 = pkey;
            goto LAB_0002a746;
          }
          pkey = (SSL_CTX *)app_passwd(bio_err,local_1f0,0,local_190,0);
          if (pkey == (SSL_CTX *)0x0) {
            BIO_printf(bio_err,"Error getting password\n");
            ctx = pkey;
            local_228 = pkey;
            goto LAB_0002a746;
          }
          if ((local_1f8 != (SSL_CTX *)0x0) ||
             (local_1f8 = local_228, pkey = local_228, local_228 != (SSL_CTX *)0x0)) {
            pkey = (SSL_CTX *)
                   load_key(bio_err,local_1f8,local_214,0,local_190[0],uVar12,
                            "client certificate private key file");
            if (pkey == (SSL_CTX *)0x0) {
              ERR_print_errors(bio_err);
              ctx = pkey;
              local_228 = pkey;
              goto LAB_0002a746;
            }
            if ((local_228 != (SSL_CTX *)0x0) &&
               (local_228 = (SSL_CTX *)
                            load_cert(bio_err,local_228,local_1fc,0,uVar12,"client certificate file"
                                     ), local_228 == (SSL_CTX *)0x0)) {
              ERR_print_errors(bio_err);
              ctx = local_228;
              goto LAB_0002a746;
            }
          }
          iVar27 = app_RAND_load_file(0,bio_err,1);
          pBVar13 = bio_err;
          if (iVar27 == 0) {
            if (local_1e8 == (char *)0x0) {
              iVar27 = RAND_status();
              if (iVar27 == 0) {
                BIO_printf(bio_err,
                           "warning, not much extra random data, consider using the -rand option\n")
                ;
              }
            }
            else {
LAB_0002af5c:
              uVar12 = app_RAND_load_files(local_1e8);
              BIO_printf(pBVar13,"%ld semi-random bytes loaded\n",uVar12);
            }
          }
          else if (local_1e8 != (char *)0x0) goto LAB_0002af5c;
          if (bio_c_out == (BIO *)0x0) {
            if (((c_quiet == 0) || (c_debug != 0)) || (c_msg != 0)) {
              bio_c_out = BIO_new_fp(stdout,0);
            }
            else {
              pBVar16 = BIO_s_null();
              bio_c_out = BIO_new(pBVar16);
            }
          }
          ctx = (SSL_CTX *)app_passwd(bio_err,local_1e0,0,&local_158,0);
          if (ctx == (SSL_CTX *)0x0) {
            BIO_printf(bio_err,"Error getting password\n");
            goto LAB_0002a746;
          }
          ctx = SSL_CTX_new(local_224);
          if (ctx == (SSL_CTX *)0x0) {
            ERR_print_errors(bio_err);
            goto LAB_0002a746;
          }
          if (local_188[0] != (X509_VERIFY_PARAM *)0x0) {
            SSL_CTX_set1_param(ctx,local_188[0]);
          }
          if (local_20c != (SSL_CTX *)0x0) {
            iVar27 = SSL_CTX_set_client_cert_engine(ctx,(ENGINE *)local_20c);
            if (iVar27 == 0) {
              BIO_puts(bio_err,"Error setting client auth engine\n");
              ERR_print_errors(bio_err);
              ENGINE_free((ENGINE *)local_20c);
              goto LAB_0002a746;
            }
            ENGINE_free((ENGINE *)local_20c);
          }
          if (psk_key != (char *)0x0) {
            if (c_debug != 0) {
              BIO_printf(bio_c_out,"PSK key given or JPAKE in use, setting client callback\n");
            }
            SSL_CTX_set_psk_client_callback(ctx,psk_client_cb + 1);
          }
          if (srtp_profiles != (char *)0x0) {
            SSL_CTX_set_tlsext_use_srtp(ctx,srtp_profiles);
          }
          if (bVar31) {
            SSL_CTX_ctrl(ctx,0x20,local_208 | 0x80000bff,(void *)0x0);
          }
          else {
            SSL_CTX_ctrl(ctx,0x20,local_208,(void *)0x0);
          }
          if (local_1d4 != 0) {
            SSL_CTX_ctrl(ctx,0x4d,local_1d4,(void *)0x0);
          }
          if (next_proto._0_4_ != (SSL_CTX *)0x0) {
            SSL_CTX_set_next_proto_select_cb(ctx,next_proto_cb + 1,PTR_next_proto_0002b408);
          }
          if (bVar2) {
            SSL_CTX_set_info_callback(ctx,apps_ssl_info_callback + 1);
          }
          if ((local_1c8 != (char *)0x0) &&
             (iVar27 = SSL_CTX_set_cipher_list(ctx,local_1c8), iVar27 == 0)) {
            BIO_printf(bio_err,"error setting cipher list\n");
            ERR_print_errors(bio_err);
            goto LAB_0002a746;
          }
          SSL_CTX_set_verify(ctx,local_218,verify_callback + 1);
          iVar27 = set_cert_key_stuff(ctx,local_228,pkey);
          if (iVar27 == 0) goto LAB_0002a746;
          if ((local_1cc != (char *)0x0 || local_1d0 != (char *)0x0) &&
             (iVar27 = SSL_CTX_load_verify_locations(ctx,local_1cc,local_1d0), iVar27 == 0)) {
            ERR_print_errors(bio_err);
          }
          iVar27 = SSL_CTX_set_default_verify_paths(ctx);
          if (iVar27 == 0) {
            ERR_print_errors(bio_err);
          }
          if (local_1e4 != (char *)0x0) {
            local_168 = bio_err;
            SSL_CTX_callback_ctrl(ctx,0x35,ssl_servername_cb + 1);
            SSL_CTX_ctrl(ctx,0x36,0,&local_168);
          }
          if (local_154 != (char *)0x0) {
            if ((!bVar1) && (iVar27 = SSL_CTX_set_srp_username(ctx), iVar27 == 0)) {
              BIO_printf(bio_err,"Unable to set SRP username\n");
              goto LAB_0002a746;
            }
            local_14c = c_debug;
            local_150 = c_msg;
            SSL_CTX_set_srp_cb_arg(ctx,&local_158);
            SSL_CTX_set_srp_client_pwd_callback(ctx,0x2a5c5);
            SSL_CTX_set_srp_strength(ctx,local_144);
            if (((c_msg != 0) || (c_debug != 0)) || (local_148 == 0)) {
              SSL_CTX_set_srp_verify_param_callback(ctx,0x29c91);
            }
          }
          to = SSL_new(ctx);
          if (local_204 != (char *)0x0) {
            pBVar13 = BIO_new_file(local_204,"r");
            if (pBVar13 != (BIO *)0x0) {
              pSVar14 = PEM_read_bio_SSL_SESSION
                                  (pBVar13,(SSL_SESSION **)0x0,(undefined1 *)0x0,(void *)0x0);
              BIO_free(pBVar13);
              if (pSVar14 != (SSL_SESSION *)0x0) {
                SSL_set_session(to,pSVar14);
                SSL_SESSION_free(pSVar14);
                goto LAB_0002b25a;
              }
            }
            BIO_printf(bio_err,"Can\'t open session file %s\n",local_204);
            ERR_print_errors(bio_err);
            iVar27 = 1;
            goto LAB_0002b6b6;
          }
LAB_0002b25a:
          if (bVar3) {
            SSL_ctrl(to,0x21,0x80,(void *)0x0);
          }
          if ((local_1e4 == (char *)0x0) || (lVar15 = SSL_ctrl(to,0x37,0,local_1e4), lVar15 != 0)) {
            local_204 = (char *)0x1;
            local_1e8 = (char *)0x1;
            goto LAB_0002b2b8;
          }
          iVar27 = 1;
          BIO_printf(bio_err,"Unable to set TLS servername extension.\n");
          ERR_print_errors(bio_err);
          goto LAB_0002b6b6;
        }
        pcVar29 = *local_1a8;
        iVar10 = strcmp(pcVar29,"-host");
        if (iVar10 == 0) {
          local_1a4 = iVar27 + -1;
          if (local_1a4 != 0) {
            local_198[0] = ppcVar28[1];
            iVar27 = local_1a4;
            ppcVar28 = ppcVar28 + 1;
            uVar21 = c_ign_eof;
            goto LAB_0002a8ba;
          }
          goto LAB_0002a95e;
        }
        iVar10 = strcmp(pcVar29,"-port");
        if (iVar10 == 0) {
          local_1a4 = iVar27 + -1;
          if (local_1a4 == 0) goto LAB_0002a95e;
          local_1a8 = ppcVar28 + 1;
          uVar11 = strtol(ppcVar28[1],(char **)0x0,10);
          uVar11 = uVar11 & 0xffff;
          local_1a0[0] = (short)uVar11;
joined_r0x0002a90a:
          iVar27 = local_1a4;
          ppcVar28 = local_1a8;
          uVar21 = c_ign_eof;
          if (uVar11 == 0) goto LAB_0002a95e;
        }
        else {
          iVar10 = strcmp(pcVar29,"-connect");
          if (iVar10 == 0) {
            local_1a4 = iVar27 + -1;
            if (local_1a4 != 0) {
              local_1a8 = ppcVar28 + 1;
              uVar11 = extract_host_port(ppcVar28[1],local_198,0,local_1a0);
              goto joined_r0x0002a90a;
            }
            goto LAB_0002a95e;
          }
          iVar10 = strcmp(pcVar29,"-verify");
          if (iVar10 == 0) {
            local_1a4 = iVar27 + -1;
            if (local_1a4 != 0) {
              local_1a8 = ppcVar28 + 1;
              verify_depth = strtol(ppcVar28[1],(char **)0x0,10);
              BIO_printf(bio_err,"verify depth is %d\n",verify_depth);
              local_218 = 1;
              iVar27 = local_1a4;
              ppcVar28 = local_1a8;
              uVar21 = c_ign_eof;
              goto LAB_0002a8ba;
            }
            goto LAB_0002a95e;
          }
          iVar10 = strcmp(pcVar29,"-cert");
          if (iVar10 == 0) {
            local_1a4 = iVar27 + -1;
            if (local_1a4 != 0) {
              local_228 = (SSL_CTX *)ppcVar28[1];
              iVar27 = local_1a4;
              ppcVar28 = ppcVar28 + 1;
              uVar21 = c_ign_eof;
              goto LAB_0002a8ba;
            }
            goto LAB_0002a95e;
          }
          iVar10 = strcmp(pcVar29,"-sess_out");
          if (iVar10 == 0) {
            local_1a4 = iVar27 + -1;
            if (local_1a4 != 0) {
              local_200 = ppcVar28[1];
              iVar27 = local_1a4;
              ppcVar28 = ppcVar28 + 1;
              uVar21 = c_ign_eof;
              goto LAB_0002a8ba;
            }
            goto LAB_0002a95e;
          }
          iVar10 = strcmp(pcVar29,"-sess_in");
          if (iVar10 == 0) {
            local_1a4 = iVar27 + -1;
            if (local_1a4 != 0) {
              local_204 = ppcVar28[1];
              iVar27 = local_1a4;
              ppcVar28 = ppcVar28 + 1;
              uVar21 = c_ign_eof;
              goto LAB_0002a8ba;
            }
            goto LAB_0002a95e;
          }
          iVar10 = strcmp(pcVar29,"-certform");
          if (iVar10 == 0) {
            local_1a4 = iVar27 + -1;
            if (local_1a4 != 0) {
              local_1a8 = ppcVar28 + 1;
              local_1fc = str2fmt(ppcVar28[1]);
              iVar27 = local_1a4;
              ppcVar28 = local_1a8;
              uVar21 = c_ign_eof;
              goto LAB_0002a8ba;
            }
            goto LAB_0002a95e;
          }
          iVar27 = args_verify(&local_1a8,&local_1a4,local_180,bio_err,local_188);
          ppcVar28 = local_1a8;
          if (iVar27 != 0) {
            if (local_180[0] != 0) goto LAB_0002a95e;
            goto LAB_0002a8c2;
          }
          pcVar29 = *local_1a8;
          iVar27 = strcmp(pcVar29,"-verify_return_error");
          if (iVar27 == 0) {
            verify_return_error = 1;
            iVar27 = local_1a4;
            uVar21 = c_ign_eof;
          }
          else {
            iVar27 = strcmp(pcVar29,"-prexit");
            if (iVar27 == 0) {
              bVar5 = true;
              iVar27 = local_1a4;
              uVar21 = c_ign_eof;
            }
            else {
              iVar27 = strcmp(pcVar29,"-crlf");
              if (iVar27 == 0) {
                bVar6 = true;
                iVar27 = local_1a4;
                uVar21 = c_ign_eof;
              }
              else {
                iVar27 = strcmp(pcVar29,"-quiet");
                if (iVar27 == 0) {
                  c_quiet = 1;
                  c_ign_eof = 1;
                  iVar27 = local_1a4;
                  uVar21 = c_ign_eof;
                }
                else {
                  iVar27 = strcmp(pcVar29,"-ign_eof");
                  if (iVar27 == 0) {
                    c_ign_eof = 1;
                    iVar27 = local_1a4;
                    uVar21 = c_ign_eof;
                  }
                  else {
                    uVar21 = strcmp(pcVar29,"-no_ign_eof");
                    iVar27 = local_1a4;
                    if (uVar21 != 0) {
                      iVar27 = strcmp(pcVar29,"-pause");
                      if (iVar27 == 0) {
                        c_Pause = 1;
                        iVar27 = local_1a4;
                        uVar21 = c_ign_eof;
                      }
                      else {
                        iVar27 = strcmp(pcVar29,"-debug");
                        if (iVar27 == 0) {
                          c_debug = 1;
                          iVar27 = local_1a4;
                          uVar21 = c_ign_eof;
                        }
                        else {
                          iVar27 = strcmp(pcVar29,"-tlsextdebug");
                          if (iVar27 == 0) {
                            c_tlsextdebug = 1;
                            iVar27 = local_1a4;
                            uVar21 = c_ign_eof;
                          }
                          else {
                            iVar27 = strcmp(pcVar29,"-status");
                            if (iVar27 == 0) {
                              c_status_req = 1;
                              iVar27 = local_1a4;
                              uVar21 = c_ign_eof;
                            }
                            else {
                              iVar27 = strcmp(pcVar29,"-msg");
                              if (iVar27 == 0) {
                                c_msg = 1;
                                iVar27 = local_1a4;
                                uVar21 = c_ign_eof;
                              }
                              else {
                                iVar27 = strcmp(pcVar29,"-showcerts");
                                if (iVar27 == 0) {
                                  c_showcerts = 1;
                                  iVar27 = local_1a4;
                                  uVar21 = c_ign_eof;
                                }
                                else {
                                  iVar27 = strcmp(pcVar29,"-nbio_test");
                                  if (iVar27 == 0) {
                                    bVar4 = true;
                                    iVar27 = local_1a4;
                                    uVar21 = c_ign_eof;
                                  }
                                  else {
                                    iVar27 = strcmp(pcVar29,"-state");
                                    if (iVar27 == 0) {
                                      bVar2 = true;
                                      iVar27 = local_1a4;
                                      uVar21 = c_ign_eof;
                                    }
                                    else {
                                      iVar27 = strcmp(pcVar29,"-psk_identity");
                                      if (iVar27 == 0) {
                                        local_1a4 = local_1a4 + -1;
                                        if (local_1a4 < 1) goto LAB_0002a95e;
                                        psk_identity = ppcVar28[1];
                                        iVar27 = local_1a4;
                                        ppcVar28 = ppcVar28 + 1;
                                        uVar21 = c_ign_eof;
                                      }
                                      else {
                                        sVar22 = strcmp(pcVar29,"-psk");
                                        if (sVar22 == 0) {
                                          iVar27 = local_1a4 + -1;
                                          local_1a4 = iVar27;
                                          if (iVar27 < 1) goto LAB_0002a95e;
                                          pcVar29 = ppcVar28[1];
                                          ppcVar28 = ppcVar28 + 1;
                                          psk_key = pcVar29;
                                          local_1a8 = ppcVar28;
                                          sVar23 = strlen(pcVar29);
                                          for (; uVar21 = c_ign_eof, sVar22 != sVar23;
                                              sVar22 = sVar22 + 1) {
                                            ppuVar24 = __ctype_b_loc();
                                            if (((*ppuVar24)[(byte)pcVar29[sVar22]] & 0x1000) == 0)
                                            {
                                              BIO_printf(bio_err,"Not a hex number \'%s\'\n",pcVar29
                                                        );
                                              goto LAB_0002a95e;
                                            }
                                          }
                                        }
                                        else {
                                          iVar27 = strcmp(pcVar29,"-srpuser");
                                          if (iVar27 == 0) {
                                            local_1a4 = local_1a4 + -1;
                                            if (local_1a4 < 1) goto LAB_0002a95e;
                                            local_154 = ppcVar28[1];
                                            local_1a8 = ppcVar28 + 1;
                                            local_224 = TLSv1_client_method();
                                            iVar27 = local_1a4;
                                            ppcVar28 = local_1a8;
                                            uVar21 = c_ign_eof;
                                          }
                                          else {
                                            iVar27 = strcmp(pcVar29,"-srppass");
                                            if (iVar27 == 0) {
                                              local_1a4 = local_1a4 + -1;
                                              if (local_1a4 < 1) goto LAB_0002a95e;
                                              local_1a8 = ppcVar28 + 1;
                                              local_1e0 = (timeval *)ppcVar28[1];
                                              local_224 = TLSv1_client_method();
                                              iVar27 = local_1a4;
                                              ppcVar28 = local_1a8;
                                              uVar21 = c_ign_eof;
                                            }
                                            else {
                                              iVar27 = strcmp(pcVar29,"-srp_strength");
                                              if (iVar27 == 0) {
                                                local_1a4 = local_1a4 + -1;
                                                if (local_1a4 < 1) goto LAB_0002a95e;
                                                local_1a8 = ppcVar28 + 1;
                                                local_144 = strtol(ppcVar28[1],(char **)0x0,10);
                                                BIO_printf(bio_err,
                                                  "SRP minimal length for N is %d\n",local_144);
                                                local_224 = TLSv1_client_method();
                                                iVar27 = local_1a4;
                                                ppcVar28 = local_1a8;
                                                uVar21 = c_ign_eof;
                                              }
                                              else {
                                                iVar27 = strcmp(pcVar29,"-srp_lateuser");
                                                if (iVar27 == 0) {
                                                  local_224 = TLSv1_client_method();
                                                  bVar1 = true;
                                                  iVar27 = local_1a4;
                                                  ppcVar28 = local_1a8;
                                                  uVar21 = c_ign_eof;
                                                }
                                                else {
                                                  iVar27 = strcmp(pcVar29,"-srp_moregroups");
                                                  if (iVar27 == 0) {
                                                    local_148 = 1;
                                                    local_224 = TLSv1_client_method();
                                                    iVar27 = local_1a4;
                                                    ppcVar28 = local_1a8;
                                                    uVar21 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar27 = strcmp(pcVar29,"-ssl3");
                                                    if (iVar27 == 0) {
                                                      local_224 = SSLv3_client_method();
                                                      iVar27 = local_1a4;
                                                      ppcVar28 = local_1a8;
                                                      uVar21 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar27 = strcmp(pcVar29,"-tls1_2");
                                                      if (iVar27 == 0) {
                                                        local_224 = TLSv1_2_client_method();
                                                        iVar27 = local_1a4;
                                                        ppcVar28 = local_1a8;
                                                        uVar21 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar27 = strcmp(pcVar29,"-tls1_1");
                                                        if (iVar27 == 0) {
                                                          local_224 = TLSv1_1_client_method();
                                                          iVar27 = local_1a4;
                                                          ppcVar28 = local_1a8;
                                                          uVar21 = c_ign_eof;
                                                        }
                                                        else {
                                                          iVar27 = strcmp(pcVar29,"-tls1");
                                                          if (iVar27 == 0) {
                                                            local_224 = TLSv1_client_method();
                                                            iVar27 = local_1a4;
                                                            ppcVar28 = local_1a8;
                                                            uVar21 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar27 = strcmp(pcVar29,"-dtls1");
                                                            if (iVar27 == 0) {
                                                              local_224 = DTLSv1_client_method();
                                                              local_1b4 = 2;
                                                              iVar27 = local_1a4;
                                                              ppcVar28 = local_1a8;
                                                              uVar21 = c_ign_eof;
                                                            }
                                                            else {
                                                              iVar27 = strcmp(pcVar29,
                                                  "-fallback_scsv");
                                                  if (iVar27 == 0) {
                                                    bVar3 = true;
                                                    iVar27 = local_1a4;
                                                    uVar21 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar27 = strcmp(pcVar29,"-timeout");
                                                    if (iVar27 == 0) {
                                                      bVar7 = true;
                                                      iVar27 = local_1a4;
                                                      uVar21 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar27 = strcmp(pcVar29,"-mtu");
                                                      if (iVar27 == 0) {
                                                        local_1a4 = local_1a4 + -1;
                                                        if (local_1a4 < 1) goto LAB_0002a95e;
                                                        local_1a8 = ppcVar28 + 1;
                                                        local_1d8 = strtol(ppcVar28[1],(char **)0x0,
                                                                           10);
                                                        iVar27 = local_1a4;
                                                        ppcVar28 = local_1a8;
                                                        uVar21 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar27 = strcmp(pcVar29,"-bugs");
                                                        if (iVar27 == 0) {
                                                          bVar31 = true;
                                                          iVar27 = local_1a4;
                                                          uVar21 = c_ign_eof;
                                                        }
                                                        else {
                                                          iVar27 = strcmp(pcVar29,"-keyform");
                                                          if (iVar27 == 0) {
                                                            local_1a4 = local_1a4 + -1;
                                                            if (local_1a4 < 1) goto LAB_0002a95e;
                                                            local_1a8 = ppcVar28 + 1;
                                                            local_214 = str2fmt(ppcVar28[1]);
                                                            iVar27 = local_1a4;
                                                            ppcVar28 = local_1a8;
                                                            uVar21 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar27 = strcmp(pcVar29,"-pass");
                                                            if (iVar27 == 0) {
                                                              local_1a4 = local_1a4 + -1;
                                                              if (local_1a4 < 1) goto LAB_0002a95e;
                                                              local_1f0 = ppcVar28[1];
                                                              iVar27 = local_1a4;
                                                              ppcVar28 = ppcVar28 + 1;
                                                              uVar21 = c_ign_eof;
                                                            }
                                                            else {
                                                              iVar27 = strcmp(pcVar29,"-key");
                                                              if (iVar27 == 0) {
                                                                local_1a4 = local_1a4 + -1;
                                                                if (local_1a4 < 1)
                                                                goto LAB_0002a95e;
                                                                local_1f8 = (SSL_CTX *)ppcVar28[1];
                                                                iVar27 = local_1a4;
                                                                ppcVar28 = ppcVar28 + 1;
                                                                uVar21 = c_ign_eof;
                                                              }
                                                              else {
                                                                iVar27 = strcmp(pcVar29,"-reconnect"
                                                                               );
                                                                if (iVar27 == 0) {
                                                                  local_1dc = 5;
                                                                  iVar27 = local_1a4;
                                                                  uVar21 = c_ign_eof;
                                                                }
                                                                else {
                                                                  iVar27 = strcmp(pcVar29,"-CApath")
                                                                  ;
                                                                  if (iVar27 == 0) {
                                                                    local_1a4 = local_1a4 + -1;
                                                                    if (local_1a4 < 1)
                                                                    goto LAB_0002a95e;
                                                                    local_1d0 = ppcVar28[1];
                                                                    iVar27 = local_1a4;
                                                                    ppcVar28 = ppcVar28 + 1;
                                                                    uVar21 = c_ign_eof;
                                                                  }
                                                                  else {
                                                                    iVar27 = strcmp(pcVar29,
                                                  "-CAfile");
                                                  if (iVar27 == 0) {
                                                    local_1a4 = local_1a4 + -1;
                                                    if (local_1a4 < 1) goto LAB_0002a95e;
                                                    local_1cc = ppcVar28[1];
                                                    iVar27 = local_1a4;
                                                    ppcVar28 = ppcVar28 + 1;
                                                    uVar21 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar27 = strcmp(pcVar29,"-no_tls1_2");
                                                    if (iVar27 == 0) {
                                                      local_208 = local_208 | 0x8000000;
                                                      iVar27 = local_1a4;
                                                      uVar21 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar27 = strcmp(pcVar29,"-no_tls1_1");
                                                      if (iVar27 == 0) {
                                                        local_208 = local_208 | 0x10000000;
                                                        iVar27 = local_1a4;
                                                        uVar21 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar27 = strcmp(pcVar29,"-no_tls1");
                                                        if (iVar27 == 0) {
                                                          local_208 = local_208 | 0x4000000;
                                                          iVar27 = local_1a4;
                                                          uVar21 = c_ign_eof;
                                                        }
                                                        else {
                                                          iVar27 = strcmp(pcVar29,"-no_ssl3");
                                                          if (iVar27 == 0) {
                                                            local_208 = local_208 | 0x2000000;
                                                            iVar27 = local_1a4;
                                                            uVar21 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar27 = strcmp(pcVar29,"-no_ssl2");
                                                            if (iVar27 == 0) {
                                                              local_208 = local_208 | 0x1000000;
                                                              iVar27 = local_1a4;
                                                              uVar21 = c_ign_eof;
                                                            }
                                                            else {
                                                              iVar27 = strcmp(pcVar29,"-no_comp");
                                                              if (iVar27 == 0) {
                                                                local_208 = local_208 | 0x20000;
                                                                iVar27 = local_1a4;
                                                                uVar21 = c_ign_eof;
                                                              }
                                                              else {
                                                                iVar27 = strcmp(pcVar29,"-no_ticket"
                                                                               );
                                                                if (iVar27 == 0) {
                                                                  local_208 = local_208 | 0x4000;
                                                                  iVar27 = local_1a4;
                                                                  uVar21 = c_ign_eof;
                                                                }
                                                                else {
                                                                  iVar27 = strcmp(pcVar29,
                                                  "-nextprotoneg");
                                                  if (iVar27 == 0) {
                                                    local_1a4 = local_1a4 + -1;
                                                    if (local_1a4 < 1) goto LAB_0002a95e;
                                                    local_210 = (SSL_CTX *)ppcVar28[1];
                                                    iVar27 = local_1a4;
                                                    ppcVar28 = ppcVar28 + 1;
                                                    uVar21 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar27 = strcmp(pcVar29,"-serverpref");
                                                    if (iVar27 == 0) {
                                                      local_208 = local_208 | 0x400000;
                                                      iVar27 = local_1a4;
                                                      uVar21 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar27 = strcmp(pcVar29,
                                                  "-legacy_renegotiation");
                                                  if (iVar27 == 0) {
                                                    local_208 = local_208 | 0x40000;
                                                    iVar27 = local_1a4;
                                                    uVar21 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar27 = strcmp(pcVar29,"-legacy_server_connect"
                                                                   );
                                                    if (iVar27 == 0) {
                                                      local_208 = local_208 | 4;
                                                      iVar27 = local_1a4;
                                                      uVar21 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar27 = strcmp(pcVar29,
                                                  "-no_legacy_server_connect");
                                                  if (iVar27 == 0) {
                                                    local_1d4 = 4;
                                                    iVar27 = local_1a4;
                                                    uVar21 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar27 = strcmp(pcVar29,"-cipher");
                                                    if (iVar27 == 0) {
                                                      local_1a4 = local_1a4 + -1;
                                                      if (local_1a4 < 1) goto LAB_0002a95e;
                                                      local_1c8 = ppcVar28[1];
                                                      iVar27 = local_1a4;
                                                      ppcVar28 = ppcVar28 + 1;
                                                      uVar21 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar27 = strcmp(pcVar29,"-nbio");
                                                      if (iVar27 == 0) {
                                                        c_nbio = 1;
                                                        iVar27 = local_1a4;
                                                        uVar21 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar27 = strcmp(pcVar29,"-starttls");
                                                        if (iVar27 == 0) {
                                                          iVar27 = local_1a4 + -1;
                                                          local_1a4 = iVar27;
                                                          if (iVar27 < 1) goto LAB_0002a95e;
                                                          pcVar29 = ppcVar28[1];
                                                          ppcVar28 = ppcVar28 + 1;
                                                          local_1a8 = ppcVar28;
                                                          iVar10 = strcmp(pcVar29,"smtp");
                                                          if (iVar10 == 0) {
                                                            local_1f4 = 1;
                                                            uVar21 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar10 = strcmp(pcVar29,"pop3");
                                                            if (iVar10 == 0) {
                                                              local_1f4 = 2;
                                                              uVar21 = c_ign_eof;
                                                            }
                                                            else {
                                                              iVar10 = strcmp(pcVar29,"imap");
                                                              uVar21 = c_ign_eof;
                                                              if (iVar10 == 0) {
                                                                local_1f4 = 3;
                                                              }
                                                              else {
                                                                if ((((*pcVar29 == 'f') &&
                                                                     (pcVar29[1] == 't')) &&
                                                                    (pcVar29[2] == 'p')) &&
                                                                   (pcVar29[3] == '\0')) {
                                                                  local_1f4 = 4;
                                                                  goto LAB_0002a8ba;
                                                                }
                                                                iVar10 = strcmp(pcVar29,"xmpp");
                                                                if (iVar10 != 0) goto LAB_0002a95e;
                                                                local_1f4 = 5;
                                                                uVar21 = c_ign_eof;
                                                              }
                                                            }
                                                          }
                                                        }
                                                        else {
                                                          iVar27 = strcmp(pcVar29,"-engine");
                                                          if (iVar27 == 0) {
                                                            local_1a4 = local_1a4 + -1;
                                                            if (local_1a4 < 1) goto LAB_0002a95e;
                                                            local_1ec = ppcVar28[1];
                                                            iVar27 = local_1a4;
                                                            ppcVar28 = ppcVar28 + 1;
                                                            uVar21 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar27 = strcmp(pcVar29,
                                                  "-ssl_client_engine");
                                                  if (iVar27 == 0) {
                                                    local_1a4 = local_1a4 + -1;
                                                    if (local_1a4 < 1) goto LAB_0002a95e;
                                                    local_20c = (SSL_CTX *)ppcVar28[1];
                                                    iVar27 = local_1a4;
                                                    ppcVar28 = ppcVar28 + 1;
                                                    uVar21 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar27 = strcmp(pcVar29,"-rand");
                                                    if (iVar27 == 0) {
                                                      local_1a4 = local_1a4 + -1;
                                                      if (local_1a4 < 1) goto LAB_0002a95e;
                                                      local_1e8 = ppcVar28[1];
                                                      iVar27 = local_1a4;
                                                      ppcVar28 = ppcVar28 + 1;
                                                      uVar21 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar27 = strcmp(pcVar29,"-servername");
                                                      if (iVar27 == 0) {
                                                        local_1a4 = local_1a4 + -1;
                                                        if (local_1a4 < 1) goto LAB_0002a95e;
                                                        local_1e4 = ppcVar28[1];
                                                        iVar27 = local_1a4;
                                                        ppcVar28 = ppcVar28 + 1;
                                                        uVar21 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar27 = strcmp(pcVar29,"-use_srtp");
                                                        if (iVar27 == 0) {
                                                          local_1a4 = local_1a4 + -1;
                                                          if (local_1a4 < 1) goto LAB_0002a95e;
                                                          srtp_profiles = ppcVar28[1];
                                                          iVar27 = local_1a4;
                                                          ppcVar28 = ppcVar28 + 1;
                                                          uVar21 = c_ign_eof;
                                                        }
                                                        else {
                                                          iVar27 = strcmp(pcVar29,"-keymatexport");
                                                          if (iVar27 != 0) {
                                                            iVar27 = strcmp(pcVar29,
                                                  "-keymatexportlen");
                                                  if (iVar27 == 0) {
                                                    local_1a4 = local_1a4 + -1;
                                                    if (0 < local_1a4) {
                                                      local_1a8 = ppcVar28 + 1;
                                                      keymatexportlen =
                                                           strtol(ppcVar28[1],(char **)0x0,10);
                                                      uVar11 = keymatexportlen;
                                                      goto joined_r0x0002a90a;
                                                    }
                                                  }
                                                  else {
                                                    BIO_printf(bio_err,"unknown option %s\n",pcVar29
                                                              );
                                                  }
                                                  goto LAB_0002a95e;
                                                  }
                                                  local_1a4 = local_1a4 + -1;
                                                  if (local_1a4 < 1) goto LAB_0002a95e;
                                                  keymatexportlabel = ppcVar28[1];
                                                  iVar27 = local_1a4;
                                                  ppcVar28 = ppcVar28 + 1;
                                                  uVar21 = c_ign_eof;
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
LAB_0002a8ba:
        c_ign_eof = uVar21;
        local_1a4 = iVar27 + -1;
        local_1a8 = ppcVar28 + 1;
        goto LAB_0002a8c2;
      }
    }
    BIO_printf(bio_err,"out of memory\n");
    pkey = (SSL_CTX *)0x0;
    local_228 = (SSL_CTX *)0x0;
    local_22c = (SSL_CTX *)0x0;
    ctx = (SSL_CTX *)0x0;
  }
LAB_0002a746:
  iVar27 = 1;
LAB_0002a748:
  if (next_proto._0_4_ != (SSL_CTX *)0x0) {
    CRYPTO_free(next_proto._0_4_);
  }
  if (ctx != (SSL_CTX *)0x0) {
    SSL_CTX_free(ctx);
  }
  if (local_228 != (SSL_CTX *)0x0) {
    X509_free((X509 *)local_228);
  }
  if (pkey != (SSL_CTX *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)pkey);
  }
  if (local_190[0] != (void *)0x0) {
    CRYPTO_free(local_190[0]);
  }
  CRYPTO_free(local_158);
  if (local_188[0] != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(local_188[0]);
  }
  if (local_230 != (SSL_CTX *)0x0) {
    OPENSSL_cleanse(local_230,0x2000);
    CRYPTO_free(local_230);
  }
  if (local_234 != (SSL_CTX *)0x0) {
    OPENSSL_cleanse(local_234,0x2000);
    CRYPTO_free(local_234);
  }
  if (local_22c != (SSL_CTX *)0x0) {
    OPENSSL_cleanse(local_22c,0x2000);
    CRYPTO_free(local_22c);
  }
  if (bio_c_out != (BIO *)0x0) {
    BIO_free(bio_c_out);
    bio_c_out = (BIO *)0x0;
  }
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar27);
LAB_0002b2b8:
  iVar27 = init_client(&local_170,local_198[0],(int)local_1a0[0],local_1b4);
  pBVar13 = bio_err;
  if (iVar27 == 0) {
    iVar27 = 1;
    piVar20 = __errno_location();
    BIO_printf(pBVar13,"connect:errno=%d\n",*piVar20);
    shutdown(local_170,0);
    close(local_170);
  }
  else {
    BIO_printf(bio_c_out,"CONNECTED(%08X)\n",local_170);
    if (c_nbio != 0) {
      iVar27 = 1;
      local_16c = 1;
      BIO_printf(bio_c_out,"turning on non blocking io\n");
      iVar10 = BIO_socket_ioctl(local_170,0x5421,&local_16c);
      if (iVar10 < 0) {
        ERR_print_errors(bio_err);
        goto LAB_0002b6b6;
      }
    }
    if (c_Pause << 0x1f < 0) {
      SSL_set_debug(to,1);
    }
    iVar27 = SSL_version(to);
    if (iVar27 != 0xfeff) {
      pBVar13 = BIO_new_socket(local_170,0);
LAB_0002b312:
      if (bVar4) {
        pBVar16 = BIO_f_nbio_test();
        pBVar17 = BIO_new(pBVar16);
        pBVar13 = BIO_push(pBVar17,pBVar13);
      }
      if (c_debug != 0) {
        SSL_set_debug(to,1);
        BIO_set_callback(pBVar13,bio_dump_callback + 1);
        BIO_set_callback_arg(pBVar13,(char *)bio_c_out);
      }
      if (c_msg != 0) {
        SSL_set_msg_callback(to,msg_cb + 1);
        SSL_ctrl(to,0x10,0,bio_c_out);
      }
      if (c_tlsextdebug != 0) {
        SSL_callback_ctrl(to,0x38,tlsext_cb + 1);
        SSL_ctrl(to,0x39,0,bio_c_out);
      }
      if (c_status_req != 0) {
        SSL_ctrl(to,0x41,1,(void *)0x0);
        SSL_CTX_callback_ctrl(ctx,0x3f,ocsp_resp_cb + 1);
        SSL_CTX_ctrl(ctx,0x40,0,bio_c_out);
      }
      SSL_set_bio(to,pBVar13,pBVar13);
      SSL_set_connect_state(to);
      iVar27 = SSL_get_fd(to);
      if (local_1f4 == 1) {
        pBVar16 = BIO_f_buffer();
        pBVar17 = BIO_new(pBVar16);
        BIO_push(pBVar17,pBVar13);
        do {
          iVar10 = BIO_gets(pBVar17,(char *)local_22c,0x2000);
          if (iVar10 < 4) break;
        } while (*(char *)((int)&local_22c->method + 3) == '-');
        bVar1 = false;
        BIO_printf(pBVar17,"EHLO openssl.client.net\r\n");
        BIO_ctrl(pBVar17,0xb,0,(void *)0x0);
        do {
          iVar10 = BIO_gets(pBVar17,(char *)local_22c,0x2000);
          pcVar29 = strstr((char *)local_22c,"STARTTLS");
          if (pcVar29 != (char *)0x0) {
            bVar1 = true;
          }
        } while ((3 < iVar10) && (*(char *)((int)&local_22c->method + 3) == '-'));
        BIO_ctrl(pBVar17,0xb,0,(void *)0x0);
        BIO_pop(pBVar17);
        BIO_free(pBVar17);
        if (!bVar1) {
          BIO_printf(bio_err,"didn\'t found starttls in server response, try anyway...\n");
        }
        pcVar29 = "STARTTLS\r\n";
      }
      else if (local_1f4 == 2) {
        BIO_read(pBVar13,local_22c,0x2000);
        pcVar29 = "STLS\r\n";
      }
      else if (local_1f4 == 3) {
        pBVar16 = BIO_f_buffer();
        bVar1 = false;
        pBVar17 = BIO_new(pBVar16);
        BIO_push(pBVar17,pBVar13);
        BIO_gets(pBVar17,(char *)local_22c,0x2000);
        BIO_printf(pBVar17,". CAPABILITY\r\n");
        BIO_ctrl(pBVar17,0xb,0,(void *)0x0);
        do {
          iVar10 = BIO_gets(pBVar17,(char *)local_22c,0x2000);
          pcVar29 = strstr((char *)local_22c,"STARTTLS");
          if (pcVar29 != (char *)0x0) {
            bVar1 = true;
          }
        } while ((3 < iVar10) && (*(char *)&local_22c->method != '.'));
        BIO_ctrl(pBVar17,0xb,0,(void *)0x0);
        BIO_pop(pBVar17);
        BIO_free(pBVar17);
        if (!bVar1) {
          BIO_printf(bio_err,"didn\'t found STARTTLS in server response, try anyway...\n");
        }
        pcVar29 = ". STARTTLS\r\n";
      }
      else {
        if (local_1f4 != 4) {
          if (local_1f4 != 5) goto LAB_0002b40c;
          BIO_printf(pBVar13,
                     "<stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\' xmlns=\'jabber:client\' to=\'%s\' version=\'1.0\'>"
                     ,local_198[0]);
          iVar10 = BIO_read(pBVar13,local_22c,0x2000);
          *(char *)((int)&local_22c->method + iVar10) = '\0';
          while (pcVar29 = strstr((char *)local_22c,
                                  "<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'"),
                pcVar29 == (char *)0x0) {
            pcVar29 = strstr((char *)local_22c,"/stream:features>");
            if (pcVar29 != (char *)0x0) goto LAB_0002c1b4;
            iVar10 = BIO_read(pBVar13,local_22c,0x2000);
            *(char *)((int)&local_22c->method + iVar10) = '\0';
          }
          BIO_printf(pBVar13,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'/>");
          iVar10 = BIO_read(pBVar13,local_234,0x2000);
          *(char *)((int)&local_234->method + iVar10) = '\0';
          pcVar29 = strstr((char *)local_234,"<proceed");
          if (pcVar29 != (char *)0x0) {
            *(char *)&local_22c->method = '\0';
            goto LAB_0002b40c;
          }
LAB_0002c1b4:
          iVar27 = 1;
          goto LAB_0002b68a;
        }
        pBVar16 = BIO_f_buffer();
        pBVar17 = BIO_new(pBVar16);
        BIO_push(pBVar17,pBVar13);
        do {
          iVar10 = BIO_gets(pBVar17,(char *)local_22c,0x2000);
          if (iVar10 < 4) break;
        } while (*(char *)((int)&local_22c->method + 3) == '-');
        BIO_ctrl(pBVar17,0xb,0,(void *)0x0);
        BIO_pop(pBVar17);
        BIO_free(pBVar17);
        pcVar29 = "AUTH TLS\r\n";
      }
      BIO_printf(pBVar13,pcVar29);
      BIO_read(pBVar13,local_234,0x2000);
LAB_0002b40c:
      bVar1 = true;
      local_20c = (SSL_CTX *)0x0;
      local_1e4 = (char *)0x0;
      local_1ec = (char *)0x0;
      local_208 = 0;
      uVar11 = 0;
      uVar21 = 1;
      uVar30 = 1;
switchD_0002bacc_caseD_7:
      memset(&fStack_13c,0,0x80);
      memset(&fStack_bc,0,0x80);
      iVar10 = SSL_version(to);
      if (iVar10 == 0xfeff) {
        local_1e0 = &local_160;
        lVar15 = SSL_ctrl(to,0x49,0,local_1e0);
        if (lVar15 == 0) {
          local_1e0 = (timeval *)0x0;
        }
      }
      else {
        local_1e0 = (timeval *)0x0;
      }
      uVar18 = SSL_state(to);
      if (((uVar18 & 0x3000) == 0) || (lVar15 = SSL_ctrl(to,0xc,0,(void *)0x0), lVar15 != 0)) {
        if (local_204 != (char *)0x0) {
          if (local_200 != (char *)0x0) {
            pBVar13 = BIO_new_file(local_200,"w");
            if (pBVar13 == (BIO *)0x0) {
              BIO_printf(bio_err,"Error writing session file %s\n",local_200);
            }
            else {
              pSVar14 = SSL_get_session(to);
              PEM_write_bio_SSL_SESSION(pBVar13,pSVar14);
              BIO_free(pBVar13);
            }
          }
          if (local_1e8 == (char *)0x1) {
            local_1e8 = (char *)0x0;
          }
          print_stuff(bio_c_out,to);
          if (local_1f4 != 0) {
            BIO_printf(bio_err,"%s",local_22c);
          }
          if (local_1dc != 0) goto LAB_0002c1d8;
          local_1f4 = local_1dc;
          local_204 = (char *)local_1dc;
        }
        lVar15 = 1;
        if (bVar1) goto LAB_0002b556;
LAB_0002b4d2:
        if (lVar15 != 0) {
          if (uVar30 != 0) {
            fileno(stdin);
            iVar10 = __fdelt_chk();
            uVar25 = fStack_13c.fds_bits[iVar10];
            uVar18 = fileno(stdin);
            uVar18 = uVar18 & 0x8000001f;
            if ((int)uVar18 < 0) {
              uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
            }
            fStack_13c.fds_bits[iVar10] = uVar25 | 1 << (uVar18 & 0xff);
          }
          if (local_20c != (SSL_CTX *)0x0) {
            fileno(stdout);
            iVar10 = __fdelt_chk();
            uVar25 = fStack_bc.fds_bits[iVar10];
            uVar18 = fileno(stdout);
            uVar18 = uVar18 & 0x8000001f;
            if ((int)uVar18 < 0) {
              uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
            }
            fStack_bc.fds_bits[iVar10] = uVar25 | 1 << (uVar18 & 0xff);
          }
        }
        if (bVar1) {
          SSL_get_fd(to);
          iVar10 = __fdelt_chk();
          uVar25 = fStack_13c.fds_bits[iVar10];
          uVar18 = SSL_get_fd(to);
          uVar18 = uVar18 & 0x8000001f;
          if ((int)uVar18 < 0) {
            uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
          }
          fStack_13c.fds_bits[iVar10] = uVar25 | 1 << (uVar18 & 0xff);
        }
        if (uVar21 != 0) {
          SSL_get_fd(to);
          iVar10 = __fdelt_chk();
          uVar25 = fStack_bc.fds_bits[iVar10];
          uVar18 = SSL_get_fd(to);
          uVar18 = uVar18 & 0x8000001f;
          if ((int)uVar18 < 0) {
            uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
          }
          fStack_bc.fds_bits[iVar10] = uVar25 | 1 << (uVar18 & 0xff);
        }
        iVar10 = select(iVar27 + 1,&fStack_13c,&fStack_bc,(fd_set *)0x0,local_1e0);
        if (iVar10 < 0) {
          piVar20 = __errno_location();
          iVar27 = 1;
          BIO_printf(bio_err,"bad select %d\n",*piVar20);
          goto LAB_0002b68a;
        }
        bVar31 = false;
      }
      else {
        local_204 = (char *)0x1;
        if (!bVar1) goto LAB_0002b4d2;
LAB_0002b556:
        iVar10 = SSL_pending(to);
        if (iVar10 == 0) goto LAB_0002b4d2;
        bVar31 = true;
      }
      iVar10 = SSL_version(to);
      if ((iVar10 == 0xfeff) && (lVar15 = SSL_ctrl(to,0x4a,0,(void *)0x0), 0 < lVar15)) {
        BIO_printf(bio_err,"TIMEOUT occured\n");
      }
      if (bVar31) {
LAB_0002b57e:
        iVar10 = SSL_read(to,local_234,0x400);
        iVar19 = SSL_get_error(to,iVar10);
        switch(iVar19) {
        case 0:
          if (iVar10 < 1) goto LAB_0002c1c6;
          bVar1 = false;
          local_1e4 = (char *)0x0;
          local_20c = (SSL_CTX *)0x1;
          local_1ec = (char *)iVar10;
          break;
        case 1:
          goto switchD_0002bacc_caseD_1;
        case 2:
          BIO_printf(bio_c_out,"read R BLOCK\n");
          local_20c = (SSL_CTX *)(uVar21 | uVar30);
          if (local_20c == (SSL_CTX *)0x0) {
            uVar21 = 1;
            bVar1 = true;
            uVar30 = (uint)local_20c;
          }
          else {
            bVar1 = true;
            local_20c = (SSL_CTX *)0x0;
          }
          break;
        case 3:
          uVar21 = 1;
          BIO_printf(bio_c_out,"read W BLOCK\n");
          uVar30 = 0;
          break;
        case 4:
          BIO_printf(bio_c_out,"read X BLOCK\n");
          break;
        case 5:
          piVar20 = __errno_location();
          iVar27 = *piVar20;
          BIO_printf(bio_err,"read:errno=%d\n",iVar27);
          goto LAB_0002b68a;
        case 6:
          iVar27 = 0;
          BIO_printf(bio_c_out,"closed\n");
          goto LAB_0002b68a;
        }
      }
      else {
        SSL_get_fd(to);
        iVar10 = __fdelt_chk();
        uVar25 = fStack_bc.fds_bits[iVar10];
        uVar18 = SSL_get_fd(to);
        uVar18 = uVar18 & 0x8000001f;
        if ((int)uVar18 < 0) {
          uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
        }
        if ((1 << (uVar18 & 0xff) & uVar25) != 0) goto LAB_0002baae;
        fileno(stdout);
        iVar10 = __fdelt_chk();
        uVar25 = fStack_bc.fds_bits[iVar10];
        uVar18 = fileno(stdout);
        uVar18 = uVar18 & 0x8000001f;
        if ((int)uVar18 < 0) {
          uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
        }
        if ((1 << (uVar18 & 0xff) & uVar25) == 0) {
          SSL_get_fd(to);
          iVar10 = __fdelt_chk();
          uVar25 = fStack_13c.fds_bits[iVar10];
          uVar18 = SSL_get_fd(to);
          uVar18 = uVar18 & 0x8000001f;
          if ((int)uVar18 < 0) {
            uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
          }
          if ((1 << (uVar18 & 0xff) & uVar25) != 0) goto LAB_0002b57e;
          fileno(stdin);
          iVar10 = __fdelt_chk();
          uVar25 = fStack_13c.fds_bits[iVar10];
          uVar18 = fileno(stdin);
          uVar18 = uVar18 & 0x8000001f;
          if ((int)uVar18 < 0) {
            uVar18 = (uVar18 - 1 | 0xffffffe0) + 1;
          }
          if ((1 << (uVar18 & 0xff) & uVar25) != 0) {
            if (bVar6) {
              uVar11 = raw_read_stdin(local_230,0x1000);
              iVar10 = 0;
              iVar19 = 0;
              while (iVar19 < (int)uVar11) {
                pcVar29 = (char *)((int)&local_230->method + iVar19);
                iVar19 = iVar19 + 1;
                if (*pcVar29 == '\n') {
                  iVar10 = iVar10 + 1;
                }
              }
              iVar19 = uVar11 - 1;
              while (-1 < iVar19) {
                *(char *)((int)&local_230->method + iVar10 + iVar19) =
                     *(char *)((int)&local_230->method + iVar19);
                cVar9 = *(char *)((int)&local_230->method + iVar19);
                iVar26 = iVar19 + -1;
                bVar31 = cVar9 == '\n';
                if (bVar31) {
                  iVar10 = iVar10 + -1;
                  uVar11 = uVar11 + 1;
                  cVar9 = '\r';
                }
                iVar8 = iVar10 + iVar19;
                iVar19 = iVar26;
                if (bVar31) {
                  *(char *)((int)&local_230->method + iVar8) = cVar9;
                }
              }
              if (iVar10 != 0) {
                    /* WARNING: Subroutine does not return */
                __assert_fail("lf_num == 0","s_client.c",0x724,"s_client_main");
              }
            }
            else {
              uVar11 = raw_read_stdin(local_230,0x2000);
            }
            uVar30 = c_ign_eof;
            if (c_ign_eof == 0) {
              if (((int)uVar11 < 1) || (cVar9 = *(char *)&local_230->method, cVar9 == 'Q')) {
                iVar27 = 0;
                BIO_printf(bio_err,"DONE\n");
                goto LAB_0002b68a;
              }
              if (cVar9 == 'R') {
                BIO_printf(bio_err,"RENEGOTIATING\n");
                SSL_renegotiate(to);
                uVar11 = uVar30;
                uVar21 = 1;
              }
              else if (cVar9 == 'B') {
                BIO_printf(bio_err,"HEARTBEATING\n");
                SSL_ctrl(to,0x55,0,(void *)0x0);
                uVar11 = uVar30;
                uVar21 = 1;
              }
              else {
                uVar21 = 1;
                local_208 = c_ign_eof;
              }
            }
            else {
              local_208 = 0;
              uVar21 = 1;
              uVar30 = 0;
            }
          }
        }
        else {
          iVar10 = raw_write_stdout((char *)((int)&local_234->method + (int)local_1e4),local_1ec);
          if (iVar10 < 1) {
            iVar27 = 0;
            BIO_printf(bio_c_out,"DONE\n");
            goto LAB_0002b68a;
          }
          local_1ec = (char *)((int)local_1ec - iVar10);
          local_1e4 = (char *)((int)local_1e4 + iVar10);
          if ((int)local_1ec < 1) {
            local_20c = (SSL_CTX *)0x0;
            bVar1 = true;
          }
        }
      }
      goto switchD_0002bacc_caseD_7;
    }
    pBVar13 = BIO_new_dgram(local_170,0);
    iVar27 = getsockname(local_170,&sStack_3c,local_178);
    if (iVar27 < 0) {
      piVar20 = __errno_location();
      iVar27 = 1;
      BIO_printf(bio_err,"getsockname:errno=%d\n",*piVar20);
      shutdown(local_170,0);
      close(local_170);
    }
    else {
      BIO_ctrl(pBVar13,0x20,1,&sStack_3c);
      if (bVar7) {
        local_160.tv_sec = 0;
        local_160.tv_usec = 250000;
        BIO_ctrl(pBVar13,0x21,0,&local_160);
        local_160.tv_usec = 250000;
        local_160.tv_sec = 0;
        BIO_ctrl(pBVar13,0x23,0,&local_160);
      }
      if (local_1d8 == 0) {
        BIO_ctrl(pBVar13,0x27,0,(void *)0x0);
        goto LAB_0002b312;
      }
      lVar15 = SSL_ctrl(to,0x79,0,(void *)0x0);
      pBVar17 = bio_err;
      if (local_1d8 < lVar15) {
        iVar27 = 1;
        lVar15 = SSL_ctrl(to,0x79,0,(void *)0x0);
        BIO_printf(pBVar17,"MTU too small. Must be at least %ld\n",lVar15);
        BIO_free(pBVar13);
      }
      else {
        SSL_ctrl(to,0x20,0x1000,(void *)0x0);
        lVar15 = SSL_ctrl(to,0x78,local_1d8,(void *)0x0);
        if (lVar15 != 0) goto LAB_0002b312;
        iVar27 = 1;
        BIO_printf(bio_err,"Failed to set MTU\n");
        BIO_free(pBVar13);
      }
LAB_0002b68a:
      if (local_204 != (char *)0x0) {
        print_stuff(bio_c_out,to,local_1e8);
      }
      SSL_shutdown(to);
      iVar10 = SSL_get_fd(to);
      shutdown(iVar10,0);
      iVar10 = SSL_get_fd(to);
      close(iVar10);
    }
  }
  goto LAB_0002b6b6;
LAB_0002c1d8:
  local_1dc = local_1dc + -1;
  BIO_printf(bio_c_out,"drop connection and then reconnect\n");
  SSL_shutdown(to);
  SSL_set_connect_state(to);
  iVar27 = SSL_get_fd(to);
  shutdown(iVar27,0);
  iVar27 = SSL_get_fd(to);
  local_204 = (char *)0x0;
  close(iVar27);
  local_1f4 = 0;
  goto LAB_0002b2b8;
LAB_0002baae:
  uVar18 = SSL_write(to,(char *)((int)&local_230->method + local_208),uVar11);
  iVar10 = SSL_get_error(to,uVar18);
  switch(iVar10) {
  case 0:
    uVar11 = uVar11 - uVar18;
    local_208 = local_208 + uVar18;
    if ((int)uVar18 < 1) {
LAB_0002c1c6:
      iVar27 = 1;
      goto LAB_0002b6b6;
    }
    uVar21 = (uint)(0 < (int)uVar11);
    uVar30 = (uint)(0 >= (int)uVar11);
    break;
  case 1:
switchD_0002bacc_caseD_1:
    iVar27 = 1;
    ERR_print_errors(bio_err);
    goto LAB_0002b68a;
  case 2:
    uVar21 = 0;
    BIO_printf(bio_c_out,"write R BLOCK\n");
    bVar1 = true;
    local_20c = (SSL_CTX *)0x0;
    break;
  case 3:
    uVar21 = 1;
    BIO_printf(bio_c_out,"write W BLOCK\n");
    uVar30 = 0;
    break;
  case 4:
    BIO_printf(bio_c_out,"write X BLOCK\n");
    break;
  case 5:
    uVar11 = uVar18 | uVar11;
    if (uVar11 != 0) {
      piVar20 = __errno_location();
      iVar27 = 1;
      BIO_printf(bio_err,"write:errno=%d\n",*piVar20);
      goto LAB_0002b68a;
    }
    uVar21 = uVar11;
    uVar30 = 1;
    break;
  case 6:
    if (uVar11 != 0) {
      iVar27 = 0;
      BIO_printf(bio_c_out,"shutdown\n");
      goto LAB_0002b68a;
    }
    uVar21 = uVar11;
    uVar30 = 1;
  }
  goto switchD_0002bacc_caseD_7;
LAB_0002b6b6:
  if (to != (SSL *)0x0) {
    if (bVar5) {
      print_stuff(bio_c_out,to,1);
    }
    SSL_free(to);
  }
  goto LAB_0002a748;
LAB_0002a95e:
  BIO_printf(bio_err,"usage: s_client args\n");
  BIO_printf(bio_err,"\n");
  BIO_printf(bio_err," -host host     - use -connect instead\n");
  BIO_printf(bio_err," -port port     - use -connect instead\n");
  BIO_printf(bio_err," -connect host:port - who to connect to (default is %s:%s)\n","localhost",
             &DAT_0012f708);
  BIO_printf(bio_err," -verify arg   - turn on peer certificate verification\n");
  BIO_printf(bio_err," -verify_return_error - return verification errors\n");
  BIO_printf(bio_err," -cert arg     - certificate file to use, PEM format assumed\n");
  BIO_printf(bio_err," -certform arg - certificate format (PEM or DER) PEM default\n");
  BIO_printf(bio_err," -key arg      - Private key file to use, in cert file if\n");
  BIO_printf(bio_err,"                 not specified but cert file is.\n");
  BIO_printf(bio_err," -keyform arg  - key format (PEM or DER) PEM default\n");
  BIO_printf(bio_err," -pass arg     - private key file pass phrase source\n");
  BIO_printf(bio_err," -CApath arg   - PEM format directory of CA\'s\n");
  BIO_printf(bio_err," -CAfile arg   - PEM format file of CA\'s\n");
  BIO_printf(bio_err," -no_alt_chains - only ever use the first certificate chain found\n");
  BIO_printf(bio_err," -reconnect    - Drop and re-make the connection with the same Session-ID\n");
  BIO_printf(bio_err," -pause        - sleep(1) after each read(2) and write(2) system call\n");
  BIO_printf(bio_err," -prexit       - print session information even on connection failure\n");
  BIO_printf(bio_err," -showcerts    - show all certificates in the chain\n");
  BIO_printf(bio_err," -debug        - extra output\n");
  BIO_printf(bio_err," -msg          - Show protocol messages\n");
  BIO_printf(bio_err," -nbio_test    - more ssl protocol testing\n");
  BIO_printf(bio_err," -state        - print the \'ssl\' states\n");
  BIO_printf(bio_err," -nbio         - Run with non-blocking IO\n");
  BIO_printf(bio_err," -crlf         - convert LF from terminal into CRLF\n");
  BIO_printf(bio_err," -quiet        - no s_client output\n");
  BIO_printf(bio_err," -ign_eof      - ignore input eof (default when -quiet)\n");
  BIO_printf(bio_err," -no_ign_eof   - don\'t ignore input eof\n");
  BIO_printf(bio_err," -psk_identity arg - PSK identity\n");
  BIO_printf(bio_err," -psk arg      - PSK in hex (without 0x)\n");
  BIO_printf(bio_err," -srpuser user     - SRP authentification for \'user\'\n");
  BIO_printf(bio_err," -srppass arg      - password for \'user\'\n");
  BIO_printf(bio_err," -srp_lateuser     - SRP username into second ClientHello message\n");
  BIO_printf(bio_err," -srp_moregroups   - Tolerate other than the known g N values.\n");
  pkey = (SSL_CTX *)0x0;
  BIO_printf(bio_err," -srp_strength int - minimal length in bits for N (default %d).\n",0x400);
  BIO_printf(bio_err," -ssl2         - just use SSLv2\n");
  BIO_printf(bio_err," -ssl3         - just use SSLv3\n");
  BIO_printf(bio_err," -tls1_2       - just use TLSv1.2\n");
  BIO_printf(bio_err," -tls1_1       - just use TLSv1.1\n");
  BIO_printf(bio_err," -tls1         - just use TLSv1\n");
  BIO_printf(bio_err," -dtls1        - just use DTLSv1\n");
  BIO_printf(bio_err," -fallback_scsv - send TLS_FALLBACK_SCSV\n");
  BIO_printf(bio_err," -mtu          - set the link layer MTU\n");
  BIO_printf(bio_err," -no_tls1_2/-no_tls1_1/-no_tls1/-no_ssl3/-no_ssl2 - turn off that protocol\n")
  ;
  BIO_printf(bio_err," -bugs         - Switch on all SSL implementation bug workarounds\n");
  BIO_printf(bio_err," -serverpref   - Use server\'s cipher preferences (only SSLv2)\n");
  BIO_printf(bio_err," -cipher       - preferred cipher to use, use the \'openssl ciphers\'\n");
  BIO_printf(bio_err,"                 command to see what is available\n");
  BIO_printf(bio_err," -starttls prot - use the STARTTLS command before starting TLS\n");
  BIO_printf(bio_err,"                 for those protocols that support it, where\n");
  BIO_printf(bio_err,"                 \'prot\' defines which one to assume.  Currently,\n");
  BIO_printf(bio_err,"                 only \"smtp\", \"pop3\", \"imap\", \"ftp\" and \"xmpp\"\n");
  BIO_printf(bio_err,"                 are supported.\n");
  BIO_printf(bio_err," -engine id    - Initialise and use the specified engine\n");
  BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
  BIO_printf(bio_err," -sess_out arg - file to write SSL session to\n");
  BIO_printf(bio_err," -sess_in arg  - file to read SSL session from\n");
  BIO_printf(bio_err," -servername host  - Set TLS extension servername in ClientHello\n");
  BIO_printf(bio_err," -tlsextdebug      - hex dump of all TLS extensions received\n");
  BIO_printf(bio_err," -status           - request certificate status from server\n");
  BIO_printf(bio_err," -no_ticket        - disable use of RFC4507bis session tickets\n");
  BIO_printf(bio_err,
             " -nextprotoneg arg - enable NPN extension, considering named protocols supported (comma-separated list)\n"
            );
  BIO_printf(bio_err," -legacy_renegotiation - enable use of legacy renegotiation (dangerous)\n");
  BIO_printf(bio_err,
             " -use_srtp profiles - Offer SRTP key management with a colon-separated profile list\n"
            );
  BIO_printf(bio_err," -keymatexport label   - Export keying material using label\n");
  BIO_printf(bio_err," -keymatexportlen len  - Export len bytes of keying material (default 20)\n");
  local_228 = (SSL_CTX *)0x0;
  ctx = (SSL_CTX *)0x0;
  goto LAB_0002a746;
}

