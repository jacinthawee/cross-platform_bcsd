
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
  int iVar7;
  char cVar8;
  SSL_CTX *pkey;
  SSL_CTX *__haystack;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  SSL_CTX *ctx;
  SSL *to;
  BIO *pBVar12;
  SSL_SESSION *pSVar13;
  long lVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  BIO_METHOD *pBVar18;
  BIO *pBVar19;
  int *piVar20;
  size_t sVar21;
  size_t sVar22;
  ushort **ppuVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  char **ppcVar27;
  char *pcVar28;
  uint uVar29;
  bool bVar30;
  SSL_CTX *local_22c;
  SSL_CTX *local_228;
  SSL_CTX *local_224;
  SSL_METHOD *local_220;
  int local_214;
  undefined4 local_210;
  SSL_CTX *local_20c;
  SSL_CTX *local_208;
  uint local_204;
  char *local_200;
  char *local_1fc;
  undefined4 local_1f8;
  SSL_CTX *local_1f4;
  int local_1f0;
  char *local_1ec;
  char *local_1e8;
  char *local_1e4;
  timeval *local_1e0;
  int local_1dc;
  char *local_1d8;
  int local_1d4;
  char *local_1d0;
  int local_1c8;
  long local_1c4;
  char *local_1bc;
  char *local_1b8;
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
  undefined4 local_158;
  char *local_154;
  int local_150;
  int local_14c;
  int local_148;
  long local_144;
  fd_set fStack_13c;
  fd_set fStack_bc;
  sockaddr sStack_3c;
  int local_2c;
  
  local_2c = __TMC_END__;
  local_198[0] = "localhost";
  local_158 = 0;
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
  local_220 = SSLv23_client_method();
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
  __haystack = pkey;
  local_22c = pkey;
  local_228 = pkey;
  local_224 = pkey;
  if (pkey != (SSL_CTX *)0x0) {
    local_22c = (SSL_CTX *)CRYPTO_malloc(0x2000,"s_client.c",0x285);
    if ((local_22c == (SSL_CTX *)0x0) ||
       (__haystack = (SSL_CTX *)CRYPTO_malloc(0x2000,"s_client.c",0x286),
       __haystack == (SSL_CTX *)0x0)) {
      __haystack = (SSL_CTX *)0x0;
    }
    else {
      local_228 = (SSL_CTX *)CRYPTO_malloc(0x2000,"s_client.c",0x287);
      if (local_228 != (SSL_CTX *)0x0) {
        verify_depth = 0;
        local_210 = 3;
        local_1a4 = local_1a4 + -1;
        bVar2 = false;
        local_1a8 = local_1a8 + 1;
        local_1d8 = (char *)0x0;
        c_nbio = 0;
        local_1c4 = 0;
        verify_error = 0;
        bVar6 = false;
        local_1fc = (char *)0x0;
        local_200 = (char *)0x0;
        local_20c = (SSL_CTX *)0x0;
        local_1e0 = (timeval *)0x0;
        local_208 = (SSL_CTX *)0x0;
        local_1e8 = (char *)0x0;
        local_1e4 = (char *)0x0;
        bVar4 = false;
        local_1f0 = 0;
        bVar3 = false;
        bVar5 = false;
        bVar1 = false;
        local_214 = 0;
        local_1dc = 0;
        local_1d0 = (char *)0x0;
        local_1b8 = (char *)0x0;
        local_1bc = (char *)0x0;
        local_1ec = (char *)0x0;
        local_1f4 = (SSL_CTX *)0x0;
        local_224 = (SSL_CTX *)0x0;
        bVar30 = false;
        local_1d4 = 0;
        local_204 = 0;
        local_1f8 = 3;
        local_1c8 = 1;
LAB_0002a472:
        iVar26 = local_1a4;
        ppcVar27 = local_1a8;
        if (local_1a4 < 1) {
          SSL_library_init();
          SSL_load_error_strings();
          next_proto._8_4_ = 0xffffffff;
          if (local_20c == (SSL_CTX *)0x0) {
            next_proto._0_4_ = local_20c;
          }
          else {
            pkey = (SSL_CTX *)next_protos_parse(0x196398,local_20c);
            next_proto._0_4_ = pkey;
            if (pkey == (SSL_CTX *)0x0) {
              BIO_printf(bio_err,"Error parsing -nextprotoneg argument\n");
              ctx = pkey;
              local_224 = pkey;
              goto LAB_0002a300;
            }
          }
          uVar11 = setup_engine(bio_err,local_1e8,1);
          if ((local_208 != (SSL_CTX *)0x0) &&
             (pkey = (SSL_CTX *)ENGINE_by_id((char *)local_208), local_208 = pkey,
             pkey == (SSL_CTX *)0x0)) {
            BIO_printf(bio_err,"Error getting client auth engine\n");
            ctx = pkey;
            local_224 = pkey;
            goto LAB_0002a300;
          }
          pkey = (SSL_CTX *)app_passwd(bio_err,local_1ec,0,local_190,0);
          if (pkey == (SSL_CTX *)0x0) {
            BIO_printf(bio_err,"Error getting password\n");
            ctx = pkey;
            local_224 = pkey;
            goto LAB_0002a300;
          }
          if ((local_1f4 != (SSL_CTX *)0x0) ||
             (local_1f4 = local_224, pkey = local_224, local_224 != (SSL_CTX *)0x0)) {
            pkey = (SSL_CTX *)
                   load_key(bio_err,local_1f4,local_210,0,local_190[0],uVar11,
                            "client certificate private key file");
            if (pkey == (SSL_CTX *)0x0) {
              ERR_print_errors(bio_err);
              ctx = pkey;
              local_224 = pkey;
              goto LAB_0002a300;
            }
            if ((local_224 != (SSL_CTX *)0x0) &&
               (local_224 = (SSL_CTX *)
                            load_cert(bio_err,local_224,local_1f8,0,uVar11,"client certificate file"
                                     ), local_224 == (SSL_CTX *)0x0)) {
              ERR_print_errors(bio_err);
              ctx = local_224;
              goto LAB_0002a300;
            }
          }
          iVar26 = app_RAND_load_file(0,bio_err,1);
          pBVar12 = bio_err;
          if (iVar26 == 0) {
            if (local_1e4 == (char *)0x0) {
              iVar26 = RAND_status();
              if (iVar26 == 0) {
                BIO_printf(bio_err,
                           "warning, not much extra random data, consider using the -rand option\n")
                ;
              }
            }
            else {
LAB_0002aace:
              uVar11 = app_RAND_load_files(local_1e4);
              BIO_printf(pBVar12,"%ld semi-random bytes loaded\n",uVar11);
            }
          }
          else if (local_1e4 != (char *)0x0) goto LAB_0002aace;
          if (bio_c_out == (BIO *)0x0) {
            if (((c_quiet == 0) || (c_debug != 0)) || (c_msg != 0)) {
              bio_c_out = BIO_new_fp(stdout,0);
            }
            else {
              pBVar18 = BIO_s_null();
              bio_c_out = BIO_new(pBVar18);
            }
          }
          ctx = (SSL_CTX *)app_passwd(bio_err,local_1d8,0,&local_158,0);
          if (ctx == (SSL_CTX *)0x0) {
            BIO_printf(bio_err,"Error getting password\n");
            goto LAB_0002a300;
          }
          ctx = SSL_CTX_new(local_220);
          if (ctx == (SSL_CTX *)0x0) {
            ERR_print_errors(bio_err);
            goto LAB_0002a300;
          }
          if (local_188[0] != (X509_VERIFY_PARAM *)0x0) {
            SSL_CTX_set1_param(ctx,local_188[0]);
          }
          if (local_208 != (SSL_CTX *)0x0) {
            iVar26 = SSL_CTX_set_client_cert_engine(ctx,(ENGINE *)local_208);
            if (iVar26 == 0) {
              BIO_puts(bio_err,"Error setting client auth engine\n");
              ERR_print_errors(bio_err);
              ENGINE_free((ENGINE *)local_208);
              goto LAB_0002a300;
            }
            ENGINE_free((ENGINE *)local_208);
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
          if (bVar1) {
            SSL_CTX_ctrl(ctx,0x20,local_204 | 0x80000bff,(void *)0x0);
          }
          else {
            SSL_CTX_ctrl(ctx,0x20,local_204,(void *)0x0);
          }
          if (local_1d4 != 0) {
            SSL_CTX_ctrl(ctx,0x4d,local_1d4,(void *)0x0);
          }
          if (local_1c8 == 2) {
            SSL_CTX_ctrl(ctx,0x29,1,(void *)0x0);
          }
          if (next_proto._0_4_ != (SSL_CTX *)0x0) {
            SSL_CTX_set_next_proto_select_cb(ctx,next_proto_cb + 1,PTR_next_proto_0002afac);
          }
          if (bVar30) {
            SSL_CTX_set_info_callback(ctx,apps_ssl_info_callback + 1);
          }
          if ((local_1d0 != (char *)0x0) &&
             (iVar26 = SSL_CTX_set_cipher_list(ctx,local_1d0), iVar26 == 0)) {
            BIO_printf(bio_err,"error setting cipher list\n");
            ERR_print_errors(bio_err);
            goto LAB_0002a300;
          }
          SSL_CTX_set_verify(ctx,local_214,verify_callback + 1);
          iVar26 = set_cert_key_stuff(ctx,local_224,pkey);
          if (iVar26 == 0) goto LAB_0002a300;
          iVar26 = SSL_CTX_load_verify_locations(ctx,local_1b8,local_1bc);
          if ((iVar26 == 0) || (iVar26 = SSL_CTX_set_default_verify_paths(ctx), iVar26 == 0)) {
            ERR_print_errors(bio_err);
          }
          if (local_1e0 != (timeval *)0x0) {
            local_168 = bio_err;
            SSL_CTX_callback_ctrl(ctx,0x35,ssl_servername_cb + 1);
            SSL_CTX_ctrl(ctx,0x36,0,&local_168);
          }
          if (local_154 != (char *)0x0) {
            if ((!bVar2) && (iVar26 = SSL_CTX_set_srp_username(ctx), iVar26 == 0)) {
              BIO_printf(bio_err,"Unable to set SRP username\n");
              goto LAB_0002a300;
            }
            local_14c = c_debug;
            local_150 = c_msg;
            SSL_CTX_set_srp_cb_arg(ctx,&local_158);
            SSL_CTX_set_srp_client_pwd_callback(ctx,0x299f5);
            SSL_CTX_set_srp_strength(ctx,local_144);
            if (((c_msg != 0) || (c_debug != 0)) || (local_148 == 0)) {
              SSL_CTX_set_srp_verify_param_callback(ctx,0x29869);
            }
          }
          to = SSL_new(ctx);
          if (local_200 != (char *)0x0) {
            pBVar12 = BIO_new_file(local_200,"r");
            if (pBVar12 != (BIO *)0x0) {
              pSVar13 = PEM_read_bio_SSL_SESSION
                                  (pBVar12,(SSL_SESSION **)0x0,(undefined1 *)0x0,(void *)0x0);
              BIO_free(pBVar12);
              if (pSVar13 != (SSL_SESSION *)0x0) {
                SSL_set_session(to,pSVar13);
                SSL_SESSION_free(pSVar13);
                goto LAB_0002adce;
              }
            }
            BIO_printf(bio_err,"Can\'t open session file %s\n",local_200);
            ERR_print_errors(bio_err);
            iVar26 = 1;
            goto LAB_0002b120;
          }
LAB_0002adce:
          if ((local_1e0 == (timeval *)0x0) || (lVar14 = SSL_ctrl(to,0x37,0,local_1e0), lVar14 != 0)
             ) {
            local_204 = 1;
            local_1e8 = (char *)0x1;
            goto LAB_0002ae1c;
          }
          iVar26 = 1;
          BIO_printf(bio_err,"Unable to set TLS servername extension.\n");
          ERR_print_errors(bio_err);
          goto LAB_0002b120;
        }
        pcVar28 = *local_1a8;
        iVar9 = strcmp(pcVar28,"-host");
        if (iVar9 == 0) {
          local_1a4 = iVar26 + -1;
          if (local_1a4 != 0) {
            local_198[0] = ppcVar27[1];
            ppcVar27 = ppcVar27 + 1;
            iVar26 = local_1a4;
            uVar17 = c_ign_eof;
            goto LAB_0002a46a;
          }
          goto LAB_0002a50e;
        }
        iVar9 = strcmp(pcVar28,"-port");
        if (iVar9 == 0) {
          local_1a4 = iVar26 + -1;
          if (local_1a4 == 0) goto LAB_0002a50e;
          local_1a8 = ppcVar27 + 1;
          uVar10 = strtol(ppcVar27[1],(char **)0x0,10);
          uVar10 = uVar10 & 0xffff;
          local_1a0[0] = (short)uVar10;
joined_r0x0002a4ba:
          ppcVar27 = local_1a8;
          iVar26 = local_1a4;
          uVar17 = c_ign_eof;
          if (uVar10 == 0) goto LAB_0002a50e;
        }
        else {
          iVar9 = strcmp(pcVar28,"-connect");
          if (iVar9 == 0) {
            local_1a4 = iVar26 + -1;
            if (local_1a4 != 0) {
              local_1a8 = ppcVar27 + 1;
              uVar10 = extract_host_port(ppcVar27[1],local_198,0,local_1a0);
              goto joined_r0x0002a4ba;
            }
            goto LAB_0002a50e;
          }
          iVar9 = strcmp(pcVar28,"-verify");
          if (iVar9 == 0) {
            local_1a4 = iVar26 + -1;
            if (local_1a4 != 0) {
              local_1a8 = ppcVar27 + 1;
              verify_depth = strtol(ppcVar27[1],(char **)0x0,10);
              BIO_printf(bio_err,"verify depth is %d\n",verify_depth);
              local_214 = 1;
              ppcVar27 = local_1a8;
              iVar26 = local_1a4;
              uVar17 = c_ign_eof;
              goto LAB_0002a46a;
            }
            goto LAB_0002a50e;
          }
          iVar9 = strcmp(pcVar28,"-cert");
          if (iVar9 == 0) {
            local_1a4 = iVar26 + -1;
            if (local_1a4 != 0) {
              local_224 = (SSL_CTX *)ppcVar27[1];
              ppcVar27 = ppcVar27 + 1;
              iVar26 = local_1a4;
              uVar17 = c_ign_eof;
              goto LAB_0002a46a;
            }
            goto LAB_0002a50e;
          }
          iVar9 = strcmp(pcVar28,"-sess_out");
          if (iVar9 == 0) {
            local_1a4 = iVar26 + -1;
            if (local_1a4 != 0) {
              local_1fc = ppcVar27[1];
              ppcVar27 = ppcVar27 + 1;
              iVar26 = local_1a4;
              uVar17 = c_ign_eof;
              goto LAB_0002a46a;
            }
            goto LAB_0002a50e;
          }
          iVar9 = strcmp(pcVar28,"-sess_in");
          if (iVar9 == 0) {
            local_1a4 = iVar26 + -1;
            if (local_1a4 != 0) {
              local_200 = ppcVar27[1];
              ppcVar27 = ppcVar27 + 1;
              iVar26 = local_1a4;
              uVar17 = c_ign_eof;
              goto LAB_0002a46a;
            }
            goto LAB_0002a50e;
          }
          iVar9 = strcmp(pcVar28,"-certform");
          if (iVar9 == 0) {
            local_1a4 = iVar26 + -1;
            if (local_1a4 != 0) {
              local_1a8 = ppcVar27 + 1;
              local_1f8 = str2fmt(ppcVar27[1]);
              ppcVar27 = local_1a8;
              iVar26 = local_1a4;
              uVar17 = c_ign_eof;
              goto LAB_0002a46a;
            }
            goto LAB_0002a50e;
          }
          iVar26 = args_verify(&local_1a8,&local_1a4,local_180,bio_err,local_188);
          ppcVar27 = local_1a8;
          if (iVar26 != 0) {
            if (local_180[0] != 0) goto LAB_0002a50e;
            goto LAB_0002a472;
          }
          pcVar28 = *local_1a8;
          iVar26 = strcmp(pcVar28,"-verify_return_error");
          if (iVar26 == 0) {
            verify_return_error = 1;
            iVar26 = local_1a4;
            uVar17 = c_ign_eof;
          }
          else {
            iVar26 = strcmp(pcVar28,"-prexit");
            if (iVar26 == 0) {
              bVar4 = true;
              iVar26 = local_1a4;
              uVar17 = c_ign_eof;
            }
            else {
              iVar26 = strcmp(pcVar28,"-crlf");
              if (iVar26 == 0) {
                bVar5 = true;
                iVar26 = local_1a4;
                uVar17 = c_ign_eof;
              }
              else {
                iVar26 = strcmp(pcVar28,"-quiet");
                if (iVar26 == 0) {
                  c_quiet = 1;
                  c_ign_eof = 1;
                  iVar26 = local_1a4;
                  uVar17 = c_ign_eof;
                }
                else {
                  iVar26 = strcmp(pcVar28,"-ign_eof");
                  if (iVar26 == 0) {
                    c_ign_eof = 1;
                    iVar26 = local_1a4;
                    uVar17 = c_ign_eof;
                  }
                  else {
                    uVar17 = strcmp(pcVar28,"-no_ign_eof");
                    iVar26 = local_1a4;
                    if (uVar17 != 0) {
                      iVar26 = strcmp(pcVar28,"-pause");
                      if (iVar26 == 0) {
                        c_Pause = 1;
                        iVar26 = local_1a4;
                        uVar17 = c_ign_eof;
                      }
                      else {
                        iVar26 = strcmp(pcVar28,"-debug");
                        if (iVar26 == 0) {
                          c_debug = 1;
                          iVar26 = local_1a4;
                          uVar17 = c_ign_eof;
                        }
                        else {
                          iVar26 = strcmp(pcVar28,"-tlsextdebug");
                          if (iVar26 == 0) {
                            c_tlsextdebug = 1;
                            iVar26 = local_1a4;
                            uVar17 = c_ign_eof;
                          }
                          else {
                            iVar26 = strcmp(pcVar28,"-status");
                            if (iVar26 == 0) {
                              c_status_req = 1;
                              iVar26 = local_1a4;
                              uVar17 = c_ign_eof;
                            }
                            else {
                              iVar26 = strcmp(pcVar28,"-msg");
                              if (iVar26 == 0) {
                                c_msg = 1;
                                iVar26 = local_1a4;
                                uVar17 = c_ign_eof;
                              }
                              else {
                                iVar26 = strcmp(pcVar28,"-showcerts");
                                if (iVar26 == 0) {
                                  c_showcerts = 1;
                                  iVar26 = local_1a4;
                                  uVar17 = c_ign_eof;
                                }
                                else {
                                  iVar26 = strcmp(pcVar28,"-nbio_test");
                                  if (iVar26 == 0) {
                                    bVar3 = true;
                                    iVar26 = local_1a4;
                                    uVar17 = c_ign_eof;
                                  }
                                  else {
                                    iVar26 = strcmp(pcVar28,"-state");
                                    if (iVar26 == 0) {
                                      bVar30 = true;
                                      iVar26 = local_1a4;
                                      uVar17 = c_ign_eof;
                                    }
                                    else {
                                      iVar26 = strcmp(pcVar28,"-psk_identity");
                                      if (iVar26 == 0) {
                                        local_1a4 = local_1a4 + -1;
                                        if (local_1a4 < 1) goto LAB_0002a50e;
                                        psk_identity = ppcVar27[1];
                                        ppcVar27 = ppcVar27 + 1;
                                        iVar26 = local_1a4;
                                        uVar17 = c_ign_eof;
                                      }
                                      else {
                                        sVar21 = strcmp(pcVar28,"-psk");
                                        if (sVar21 == 0) {
                                          iVar26 = local_1a4 + -1;
                                          local_1a4 = iVar26;
                                          if (iVar26 < 1) goto LAB_0002a50e;
                                          pcVar28 = ppcVar27[1];
                                          ppcVar27 = ppcVar27 + 1;
                                          psk_key = pcVar28;
                                          local_1a8 = ppcVar27;
                                          sVar22 = strlen(pcVar28);
                                          for (; uVar17 = c_ign_eof, sVar21 != sVar22;
                                              sVar21 = sVar21 + 1) {
                                            ppuVar23 = __ctype_b_loc();
                                            if (((*ppuVar23)[(byte)pcVar28[sVar21]] & 0x1000) == 0)
                                            {
                                              BIO_printf(bio_err,"Not a hex number \'%s\'\n",pcVar28
                                                        );
                                              goto LAB_0002a50e;
                                            }
                                          }
                                        }
                                        else {
                                          iVar26 = strcmp(pcVar28,"-srpuser");
                                          if (iVar26 == 0) {
                                            local_1a4 = local_1a4 + -1;
                                            if (local_1a4 < 1) goto LAB_0002a50e;
                                            local_154 = ppcVar27[1];
                                            local_1a8 = ppcVar27 + 1;
                                            local_220 = TLSv1_client_method();
                                            ppcVar27 = local_1a8;
                                            iVar26 = local_1a4;
                                            uVar17 = c_ign_eof;
                                          }
                                          else {
                                            iVar26 = strcmp(pcVar28,"-srppass");
                                            if (iVar26 == 0) {
                                              local_1a4 = local_1a4 + -1;
                                              if (local_1a4 < 1) goto LAB_0002a50e;
                                              local_1a8 = ppcVar27 + 1;
                                              local_1d8 = ppcVar27[1];
                                              local_220 = TLSv1_client_method();
                                              ppcVar27 = local_1a8;
                                              iVar26 = local_1a4;
                                              uVar17 = c_ign_eof;
                                            }
                                            else {
                                              iVar26 = strcmp(pcVar28,"-srp_strength");
                                              if (iVar26 == 0) {
                                                local_1a4 = local_1a4 + -1;
                                                if (local_1a4 < 1) goto LAB_0002a50e;
                                                local_1a8 = ppcVar27 + 1;
                                                local_144 = strtol(ppcVar27[1],(char **)0x0,10);
                                                BIO_printf(bio_err,
                                                  "SRP minimal length for N is %d\n",local_144);
                                                local_220 = TLSv1_client_method();
                                                ppcVar27 = local_1a8;
                                                iVar26 = local_1a4;
                                                uVar17 = c_ign_eof;
                                              }
                                              else {
                                                iVar26 = strcmp(pcVar28,"-srp_lateuser");
                                                if (iVar26 == 0) {
                                                  local_220 = TLSv1_client_method();
                                                  bVar2 = true;
                                                  ppcVar27 = local_1a8;
                                                  iVar26 = local_1a4;
                                                  uVar17 = c_ign_eof;
                                                }
                                                else {
                                                  iVar26 = strcmp(pcVar28,"-srp_moregroups");
                                                  if (iVar26 == 0) {
                                                    local_148 = 1;
                                                    local_220 = TLSv1_client_method();
                                                    ppcVar27 = local_1a8;
                                                    iVar26 = local_1a4;
                                                    uVar17 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar26 = strcmp(pcVar28,"-ssl2");
                                                    if (iVar26 == 0) {
                                                      local_220 = SSLv2_client_method();
                                                      ppcVar27 = local_1a8;
                                                      iVar26 = local_1a4;
                                                      uVar17 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar26 = strcmp(pcVar28,"-ssl3");
                                                      if (iVar26 == 0) {
                                                        local_220 = SSLv3_client_method();
                                                        ppcVar27 = local_1a8;
                                                        iVar26 = local_1a4;
                                                        uVar17 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar26 = strcmp(pcVar28,"-tls1_2");
                                                        if (iVar26 == 0) {
                                                          local_220 = TLSv1_2_client_method();
                                                          ppcVar27 = local_1a8;
                                                          iVar26 = local_1a4;
                                                          uVar17 = c_ign_eof;
                                                        }
                                                        else {
                                                          iVar26 = strcmp(pcVar28,"-tls1_1");
                                                          if (iVar26 == 0) {
                                                            local_220 = TLSv1_1_client_method();
                                                            ppcVar27 = local_1a8;
                                                            iVar26 = local_1a4;
                                                            uVar17 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar26 = strcmp(pcVar28,"-tls1");
                                                            if (iVar26 == 0) {
                                                              local_220 = TLSv1_client_method();
                                                              ppcVar27 = local_1a8;
                                                              iVar26 = local_1a4;
                                                              uVar17 = c_ign_eof;
                                                            }
                                                            else {
                                                              iVar26 = strcmp(pcVar28,"-dtls1");
                                                              if (iVar26 == 0) {
                                                                local_220 = DTLSv1_client_method();
                                                                local_1c8 = 2;
                                                                ppcVar27 = local_1a8;
                                                                iVar26 = local_1a4;
                                                                uVar17 = c_ign_eof;
                                                              }
                                                              else {
                                                                iVar26 = strcmp(pcVar28,"-timeout");
                                                                if (iVar26 == 0) {
                                                                  bVar6 = true;
                                                                  iVar26 = local_1a4;
                                                                  uVar17 = c_ign_eof;
                                                                }
                                                                else {
                                                                  iVar26 = strcmp(pcVar28,"-mtu");
                                                                  if (iVar26 == 0) {
                                                                    local_1a4 = local_1a4 + -1;
                                                                    if (local_1a4 < 1)
                                                                    goto LAB_0002a50e;
                                                                    local_1a8 = ppcVar27 + 1;
                                                                    local_1c4 = strtol(ppcVar27[1],
                                                                                       (char **)0x0,
                                                                                       10);
                                                                    ppcVar27 = local_1a8;
                                                                    iVar26 = local_1a4;
                                                                    uVar17 = c_ign_eof;
                                                                  }
                                                                  else {
                                                                    iVar26 = strcmp(pcVar28,"-bugs")
                                                                    ;
                                                                    if (iVar26 == 0) {
                                                                      bVar1 = true;
                                                                      iVar26 = local_1a4;
                                                                      uVar17 = c_ign_eof;
                                                                    }
                                                                    else {
                                                                      iVar26 = strcmp(pcVar28,
                                                  "-keyform");
                                                  if (iVar26 == 0) {
                                                    local_1a4 = local_1a4 + -1;
                                                    if (local_1a4 < 1) goto LAB_0002a50e;
                                                    local_1a8 = ppcVar27 + 1;
                                                    local_210 = str2fmt(ppcVar27[1]);
                                                    ppcVar27 = local_1a8;
                                                    iVar26 = local_1a4;
                                                    uVar17 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar26 = strcmp(pcVar28,"-pass");
                                                    if (iVar26 == 0) {
                                                      local_1a4 = local_1a4 + -1;
                                                      if (local_1a4 < 1) goto LAB_0002a50e;
                                                      local_1ec = ppcVar27[1];
                                                      ppcVar27 = ppcVar27 + 1;
                                                      iVar26 = local_1a4;
                                                      uVar17 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar26 = strcmp(pcVar28,"-key");
                                                      if (iVar26 == 0) {
                                                        local_1a4 = local_1a4 + -1;
                                                        if (local_1a4 < 1) goto LAB_0002a50e;
                                                        local_1f4 = (SSL_CTX *)ppcVar27[1];
                                                        ppcVar27 = ppcVar27 + 1;
                                                        iVar26 = local_1a4;
                                                        uVar17 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar26 = strcmp(pcVar28,"-reconnect");
                                                        if (iVar26 == 0) {
                                                          local_1dc = 5;
                                                          iVar26 = local_1a4;
                                                          uVar17 = c_ign_eof;
                                                        }
                                                        else {
                                                          iVar26 = strcmp(pcVar28,"-CApath");
                                                          if (iVar26 == 0) {
                                                            local_1a4 = local_1a4 + -1;
                                                            if (local_1a4 < 1) goto LAB_0002a50e;
                                                            local_1bc = ppcVar27[1];
                                                            ppcVar27 = ppcVar27 + 1;
                                                            iVar26 = local_1a4;
                                                            uVar17 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar26 = strcmp(pcVar28,"-CAfile");
                                                            if (iVar26 == 0) {
                                                              local_1a4 = local_1a4 + -1;
                                                              if (local_1a4 < 1) goto LAB_0002a50e;
                                                              local_1b8 = ppcVar27[1];
                                                              ppcVar27 = ppcVar27 + 1;
                                                              iVar26 = local_1a4;
                                                              uVar17 = c_ign_eof;
                                                            }
                                                            else {
                                                              iVar26 = strcmp(pcVar28,"-no_tls1_2");
                                                              if (iVar26 == 0) {
                                                                local_204 = local_204 | 0x8000000;
                                                                iVar26 = local_1a4;
                                                                uVar17 = c_ign_eof;
                                                              }
                                                              else {
                                                                iVar26 = strcmp(pcVar28,"-no_tls1_1"
                                                                               );
                                                                if (iVar26 == 0) {
                                                                  local_204 = local_204 | 0x10000000
                                                                  ;
                                                                  iVar26 = local_1a4;
                                                                  uVar17 = c_ign_eof;
                                                                }
                                                                else {
                                                                  iVar26 = strcmp(pcVar28,"-no_tls1"
                                                                                 );
                                                                  if (iVar26 == 0) {
                                                                    local_204 = local_204 |
                                                                                0x4000000;
                                                                    iVar26 = local_1a4;
                                                                    uVar17 = c_ign_eof;
                                                                  }
                                                                  else {
                                                                    iVar26 = strcmp(pcVar28,
                                                  "-no_ssl3");
                                                  if (iVar26 == 0) {
                                                    local_204 = local_204 | 0x2000000;
                                                    iVar26 = local_1a4;
                                                    uVar17 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar26 = strcmp(pcVar28,"-no_ssl2");
                                                    if (iVar26 == 0) {
                                                      local_204 = local_204 | 0x1000000;
                                                      iVar26 = local_1a4;
                                                      uVar17 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar26 = strcmp(pcVar28,"-no_comp");
                                                      if (iVar26 == 0) {
                                                        local_204 = local_204 | 0x20000;
                                                        iVar26 = local_1a4;
                                                        uVar17 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar26 = strcmp(pcVar28,"-no_ticket");
                                                        if (iVar26 == 0) {
                                                          local_204 = local_204 | 0x4000;
                                                          iVar26 = local_1a4;
                                                          uVar17 = c_ign_eof;
                                                        }
                                                        else {
                                                          iVar26 = strcmp(pcVar28,"-nextprotoneg");
                                                          if (iVar26 == 0) {
                                                            local_1a4 = local_1a4 + -1;
                                                            if (local_1a4 < 1) goto LAB_0002a50e;
                                                            local_20c = (SSL_CTX *)ppcVar27[1];
                                                            ppcVar27 = ppcVar27 + 1;
                                                            iVar26 = local_1a4;
                                                            uVar17 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar26 = strcmp(pcVar28,"-serverpref");
                                                            if (iVar26 == 0) {
                                                              local_204 = local_204 | 0x400000;
                                                              iVar26 = local_1a4;
                                                              uVar17 = c_ign_eof;
                                                            }
                                                            else {
                                                              iVar26 = strcmp(pcVar28,
                                                  "-legacy_renegotiation");
                                                  if (iVar26 == 0) {
                                                    local_204 = local_204 | 0x40000;
                                                    iVar26 = local_1a4;
                                                    uVar17 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar26 = strcmp(pcVar28,"-legacy_server_connect"
                                                                   );
                                                    if (iVar26 == 0) {
                                                      local_204 = local_204 | 4;
                                                      iVar26 = local_1a4;
                                                      uVar17 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar26 = strcmp(pcVar28,
                                                  "-no_legacy_server_connect");
                                                  if (iVar26 == 0) {
                                                    local_1d4 = 4;
                                                    iVar26 = local_1a4;
                                                    uVar17 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar26 = strcmp(pcVar28,"-cipher");
                                                    if (iVar26 == 0) {
                                                      local_1a4 = local_1a4 + -1;
                                                      if (local_1a4 < 1) goto LAB_0002a50e;
                                                      local_1d0 = ppcVar27[1];
                                                      ppcVar27 = ppcVar27 + 1;
                                                      iVar26 = local_1a4;
                                                      uVar17 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar26 = strcmp(pcVar28,"-nbio");
                                                      if (iVar26 == 0) {
                                                        c_nbio = 1;
                                                        iVar26 = local_1a4;
                                                        uVar17 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar26 = strcmp(pcVar28,"-starttls");
                                                        if (iVar26 == 0) {
                                                          iVar26 = local_1a4 + -1;
                                                          local_1a4 = iVar26;
                                                          if (iVar26 < 1) goto LAB_0002a50e;
                                                          pcVar28 = ppcVar27[1];
                                                          ppcVar27 = ppcVar27 + 1;
                                                          local_1a8 = ppcVar27;
                                                          iVar9 = strcmp(pcVar28,"smtp");
                                                          if (iVar9 == 0) {
                                                            local_1f0 = 1;
                                                            uVar17 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar9 = strcmp(pcVar28,"pop3");
                                                            if (iVar9 == 0) {
                                                              local_1f0 = 2;
                                                              uVar17 = c_ign_eof;
                                                            }
                                                            else {
                                                              iVar9 = strcmp(pcVar28,"imap");
                                                              uVar17 = c_ign_eof;
                                                              if (iVar9 == 0) {
                                                                local_1f0 = 3;
                                                              }
                                                              else {
                                                                if ((((*pcVar28 == 'f') &&
                                                                     (pcVar28[1] == 't')) &&
                                                                    (pcVar28[2] == 'p')) &&
                                                                   (pcVar28[3] == '\0')) {
                                                                  local_1f0 = 4;
                                                                  goto LAB_0002a46a;
                                                                }
                                                                iVar9 = strcmp(pcVar28,"xmpp");
                                                                if (iVar9 != 0) goto LAB_0002a50e;
                                                                local_1f0 = 5;
                                                                uVar17 = c_ign_eof;
                                                              }
                                                            }
                                                          }
                                                        }
                                                        else {
                                                          iVar26 = strcmp(pcVar28,"-engine");
                                                          if (iVar26 == 0) {
                                                            local_1a4 = local_1a4 + -1;
                                                            if (local_1a4 < 1) goto LAB_0002a50e;
                                                            local_1e8 = ppcVar27[1];
                                                            ppcVar27 = ppcVar27 + 1;
                                                            iVar26 = local_1a4;
                                                            uVar17 = c_ign_eof;
                                                          }
                                                          else {
                                                            iVar26 = strcmp(pcVar28,
                                                  "-ssl_client_engine");
                                                  if (iVar26 == 0) {
                                                    local_1a4 = local_1a4 + -1;
                                                    if (local_1a4 < 1) goto LAB_0002a50e;
                                                    local_208 = (SSL_CTX *)ppcVar27[1];
                                                    ppcVar27 = ppcVar27 + 1;
                                                    iVar26 = local_1a4;
                                                    uVar17 = c_ign_eof;
                                                  }
                                                  else {
                                                    iVar26 = strcmp(pcVar28,"-rand");
                                                    if (iVar26 == 0) {
                                                      local_1a4 = local_1a4 + -1;
                                                      if (local_1a4 < 1) goto LAB_0002a50e;
                                                      local_1e4 = ppcVar27[1];
                                                      ppcVar27 = ppcVar27 + 1;
                                                      iVar26 = local_1a4;
                                                      uVar17 = c_ign_eof;
                                                    }
                                                    else {
                                                      iVar26 = strcmp(pcVar28,"-servername");
                                                      if (iVar26 == 0) {
                                                        local_1a4 = local_1a4 + -1;
                                                        if (local_1a4 < 1) goto LAB_0002a50e;
                                                        local_1e0 = (timeval *)ppcVar27[1];
                                                        ppcVar27 = ppcVar27 + 1;
                                                        iVar26 = local_1a4;
                                                        uVar17 = c_ign_eof;
                                                      }
                                                      else {
                                                        iVar26 = strcmp(pcVar28,"-use_srtp");
                                                        if (iVar26 == 0) {
                                                          local_1a4 = local_1a4 + -1;
                                                          if (local_1a4 < 1) goto LAB_0002a50e;
                                                          srtp_profiles = ppcVar27[1];
                                                          ppcVar27 = ppcVar27 + 1;
                                                          iVar26 = local_1a4;
                                                          uVar17 = c_ign_eof;
                                                        }
                                                        else {
                                                          iVar26 = strcmp(pcVar28,"-keymatexport");
                                                          if (iVar26 != 0) {
                                                            iVar26 = strcmp(pcVar28,
                                                  "-keymatexportlen");
                                                  if (iVar26 == 0) {
                                                    local_1a4 = local_1a4 + -1;
                                                    if (0 < local_1a4) {
                                                      local_1a8 = ppcVar27 + 1;
                                                      keymatexportlen =
                                                           strtol(ppcVar27[1],(char **)0x0,10);
                                                      uVar10 = keymatexportlen;
                                                      goto joined_r0x0002a4ba;
                                                    }
                                                  }
                                                  else {
                                                    BIO_printf(bio_err,"unknown option %s\n",pcVar28
                                                              );
                                                  }
                                                  goto LAB_0002a50e;
                                                  }
                                                  local_1a4 = local_1a4 + -1;
                                                  if (local_1a4 < 1) goto LAB_0002a50e;
                                                  keymatexportlabel = ppcVar27[1];
                                                  ppcVar27 = ppcVar27 + 1;
                                                  iVar26 = local_1a4;
                                                  uVar17 = c_ign_eof;
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
LAB_0002a46a:
        c_ign_eof = uVar17;
        local_1a4 = iVar26 + -1;
        local_1a8 = ppcVar27 + 1;
        goto LAB_0002a472;
      }
    }
    BIO_printf(bio_err,"out of memory\n");
    pkey = (SSL_CTX *)0x0;
    local_224 = (SSL_CTX *)0x0;
    local_228 = (SSL_CTX *)0x0;
    ctx = (SSL_CTX *)0x0;
  }
LAB_0002a300:
  iVar26 = 1;
LAB_0002a302:
  if (next_proto._0_4_ != (SSL_CTX *)0x0) {
    CRYPTO_free(next_proto._0_4_);
  }
  if (ctx != (SSL_CTX *)0x0) {
    SSL_CTX_free(ctx);
  }
  if (local_224 != (SSL_CTX *)0x0) {
    X509_free((X509 *)local_224);
  }
  if (pkey != (SSL_CTX *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)pkey);
  }
  if (local_190[0] != (void *)0x0) {
    CRYPTO_free(local_190[0]);
  }
  if (local_188[0] != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(local_188[0]);
  }
  if (local_22c != (SSL_CTX *)0x0) {
    OPENSSL_cleanse(local_22c,0x2000);
    CRYPTO_free(local_22c);
  }
  if (__haystack != (SSL_CTX *)0x0) {
    OPENSSL_cleanse(__haystack,0x2000);
    CRYPTO_free(__haystack);
  }
  if (local_228 != (SSL_CTX *)0x0) {
    OPENSSL_cleanse(local_228,0x2000);
    CRYPTO_free(local_228);
  }
  if (bio_c_out != (BIO *)0x0) {
    BIO_free(bio_c_out);
    bio_c_out = (BIO *)0x0;
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar26);
LAB_0002ae1c:
  iVar26 = init_client(&local_170,local_198[0],(int)local_1a0[0],local_1c8);
  pBVar12 = bio_err;
  if (iVar26 == 0) goto LAB_0002bd68;
  BIO_printf(bio_c_out,"CONNECTED(%08X)\n",local_170);
  if (c_nbio != 0) {
    iVar26 = 1;
    local_16c = 1;
    BIO_printf(bio_c_out,"turning on non blocking io\n");
    iVar9 = BIO_socket_ioctl(local_170,0x5421,&local_16c);
    if (iVar9 < 0) {
      ERR_print_errors(bio_err);
      goto LAB_0002b120;
    }
  }
  if (c_Pause << 0x1f < 0) {
    SSL_set_debug(to,1);
  }
  iVar26 = SSL_version(to);
  if (iVar26 == 0xfeff) {
    pBVar12 = BIO_new_dgram(local_170,0);
    iVar26 = getsockname(local_170,&sStack_3c,local_178);
    if (iVar26 < 0) {
      piVar20 = __errno_location();
      iVar26 = 1;
      BIO_printf(bio_err,"getsockname:errno=%d\n",*piVar20);
      shutdown(local_170,0);
      close(local_170);
      goto LAB_0002b120;
    }
    BIO_ctrl(pBVar12,0x20,1,&sStack_3c);
    if (bVar6) {
      local_160.tv_sec = 0;
      local_160.tv_usec = 250000;
      BIO_ctrl(pBVar12,0x21,0,&local_160);
      local_160.tv_usec = 250000;
      local_160.tv_sec = 0;
      BIO_ctrl(pBVar12,0x23,0,&local_160);
    }
    if (local_1c4 < 0x1d) {
      BIO_ctrl(pBVar12,0x27,0,(void *)0x0);
    }
    else {
      SSL_ctrl(to,0x20,0x1000,(void *)0x0);
      SSL_ctrl(to,0x11,local_1c4 + -0x1c,(void *)0x0);
    }
  }
  else {
    pBVar12 = BIO_new_socket(local_170,0);
  }
  if (bVar3) {
    pBVar18 = BIO_f_nbio_test();
    pBVar19 = BIO_new(pBVar18);
    pBVar12 = BIO_push(pBVar19,pBVar12);
  }
  if (c_debug != 0) {
    SSL_set_debug(to,1);
    BIO_set_callback(pBVar12,bio_dump_callback + 1);
    BIO_set_callback_arg(pBVar12,(char *)bio_c_out);
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
  SSL_set_bio(to,pBVar12,pBVar12);
  SSL_set_connect_state(to);
  iVar26 = SSL_get_fd(to);
  if (local_1f0 == 1) {
    pBVar18 = BIO_f_buffer();
    pBVar19 = BIO_new(pBVar18);
    BIO_push(pBVar19,pBVar12);
    do {
      iVar9 = BIO_gets(pBVar19,(char *)local_228,0x2000);
      if (iVar9 < 4) break;
    } while (*(char *)((int)&local_228->method + 3) == '-');
    bVar1 = false;
    BIO_printf(pBVar19,"EHLO openssl.client.net\r\n");
    BIO_ctrl(pBVar19,0xb,0,(void *)0x0);
    do {
      iVar9 = BIO_gets(pBVar19,(char *)local_228,0x2000);
      pcVar28 = strstr((char *)local_228,"STARTTLS");
      if (pcVar28 != (char *)0x0) {
        bVar1 = true;
      }
    } while ((3 < iVar9) && (*(char *)((int)&local_228->method + 3) == '-'));
    BIO_ctrl(pBVar19,0xb,0,(void *)0x0);
    BIO_pop(pBVar19);
    BIO_free(pBVar19);
    if (!bVar1) {
      BIO_printf(bio_err,"didn\'t found starttls in server response, try anyway...\n");
    }
    pcVar28 = "STARTTLS\r\n";
  }
  else if (local_1f0 == 2) {
    BIO_read(pBVar12,local_228,0x2000);
    pcVar28 = "STLS\r\n";
  }
  else if (local_1f0 == 3) {
    pBVar18 = BIO_f_buffer();
    bVar1 = false;
    pBVar19 = BIO_new(pBVar18);
    BIO_push(pBVar19,pBVar12);
    BIO_gets(pBVar19,(char *)local_228,0x2000);
    BIO_printf(pBVar19,". CAPABILITY\r\n");
    BIO_ctrl(pBVar19,0xb,0,(void *)0x0);
    do {
      iVar9 = BIO_gets(pBVar19,(char *)local_228,0x2000);
      pcVar28 = strstr((char *)local_228,"STARTTLS");
      if (pcVar28 != (char *)0x0) {
        bVar1 = true;
      }
    } while ((3 < iVar9) && (*(char *)&local_228->method != '.'));
    BIO_ctrl(pBVar19,0xb,0,(void *)0x0);
    BIO_pop(pBVar19);
    BIO_free(pBVar19);
    if (!bVar1) {
      BIO_printf(bio_err,"didn\'t found STARTTLS in server response, try anyway...\n");
    }
    pcVar28 = ". STARTTLS\r\n";
  }
  else {
    if (local_1f0 != 4) {
      if (local_1f0 != 5) goto LAB_0002aee4;
      BIO_printf(pBVar12,
                 "<stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\' xmlns=\'jabber:client\' to=\'%s\' version=\'1.0\'>"
                 ,local_198[0]);
      iVar9 = BIO_read(pBVar12,local_228,0x2000);
      *(char *)((int)&local_228->method + iVar9) = '\0';
      while (pcVar28 = strstr((char *)local_228,
                              "<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'"),
            pcVar28 == (char *)0x0) {
        pcVar28 = strstr((char *)local_228,"/stream:features>");
        if (pcVar28 != (char *)0x0) goto LAB_0002b7d0;
        iVar9 = BIO_read(pBVar12,local_228,0x2000);
        *(char *)((int)&local_228->method + iVar9) = '\0';
      }
      BIO_printf(pBVar12,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'/>");
      iVar9 = BIO_read(pBVar12,__haystack,0x2000);
      *(char *)((int)&__haystack->method + iVar9) = '\0';
      pcVar28 = strstr((char *)__haystack,"<proceed");
      if (pcVar28 == (char *)0x0) {
LAB_0002b7d0:
        iVar26 = 1;
LAB_0002b0fc:
        if (local_204 != 0) {
          print_stuff(bio_c_out,to,local_1e8);
        }
        SSL_shutdown(to);
        iVar9 = SSL_get_fd(to);
        shutdown(iVar9,0);
        iVar9 = SSL_get_fd(to);
        close(iVar9);
        goto LAB_0002b120;
      }
      *(char *)&local_228->method = '\0';
      goto LAB_0002aee4;
    }
    pBVar18 = BIO_f_buffer();
    pBVar19 = BIO_new(pBVar18);
    BIO_push(pBVar19,pBVar12);
    do {
      iVar9 = BIO_gets(pBVar19,(char *)local_228,0x2000);
      if (iVar9 < 4) break;
    } while (*(char *)((int)&local_228->method + 3) == '-');
    BIO_ctrl(pBVar19,0xb,0,(void *)0x0);
    BIO_pop(pBVar19);
    BIO_free(pBVar19);
    pcVar28 = "AUTH TLS\r\n";
  }
  BIO_printf(pBVar12,pcVar28);
  BIO_read(pBVar12,__haystack,0x2000);
LAB_0002aee4:
  bVar1 = true;
  local_20c = (SSL_CTX *)0x0;
  local_1e4 = (char *)0x0;
  local_1ec = (char *)0x0;
  local_208 = (SSL_CTX *)0x0;
  uVar10 = 0;
  uVar17 = 1;
  uVar29 = 1;
switchD_0002b890_caseD_7:
  memset(&fStack_13c,0,0x80);
  memset(&fStack_bc,0,0x80);
  iVar9 = SSL_version(to);
  if (iVar9 == 0xfeff) {
    local_1e0 = &local_160;
    lVar14 = SSL_ctrl(to,0x49,0,local_1e0);
    if (lVar14 == 0) {
      local_1e0 = (timeval *)0x0;
    }
  }
  else {
    local_1e0 = (timeval *)0x0;
  }
  uVar15 = SSL_state(to);
  if (((uVar15 & 0x3000) == 0) || (lVar14 = SSL_ctrl(to,0xc,0,(void *)0x0), lVar14 != 0)) {
    if (local_204 != 0) {
      if (local_1fc != (char *)0x0) {
        pBVar12 = BIO_new_file(local_1fc,"w");
        if (pBVar12 == (BIO *)0x0) {
          BIO_printf(bio_err,"Error writing session file %s\n",local_1fc);
        }
        else {
          pSVar13 = SSL_get_session(to);
          PEM_write_bio_SSL_SESSION(pBVar12,pSVar13);
          BIO_free(pBVar12);
        }
      }
      if (local_1e8 == (char *)0x1) {
        local_1e8 = (char *)0x0;
      }
      print_stuff(bio_c_out,to);
      if (local_1f0 != 0) {
        BIO_printf(bio_err,"%s",local_228);
      }
      if (local_1dc != 0) goto LAB_0002b570;
      local_1f0 = local_1dc;
      local_204 = local_1dc;
    }
    lVar14 = 1;
    if (bVar1) goto LAB_0002b0c8;
LAB_0002af9e:
    if (lVar14 != 0) {
      if (uVar29 != 0) {
        fileno(stdin);
        iVar9 = __fdelt_chk();
        uVar24 = fStack_13c.fds_bits[iVar9];
        uVar15 = fileno(stdin);
        uVar15 = uVar15 & 0x8000001f;
        if ((int)uVar15 < 0) {
          uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
        }
        fStack_13c.fds_bits[iVar9] = uVar24 | 1 << (uVar15 & 0xff);
      }
      if (local_20c != (SSL_CTX *)0x0) {
        fileno(stdout);
        iVar9 = __fdelt_chk();
        uVar24 = fStack_bc.fds_bits[iVar9];
        uVar15 = fileno(stdout);
        uVar15 = uVar15 & 0x8000001f;
        if ((int)uVar15 < 0) {
          uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
        }
        fStack_bc.fds_bits[iVar9] = uVar24 | 1 << (uVar15 & 0xff);
      }
    }
    if (bVar1) {
      SSL_get_fd(to);
      iVar9 = __fdelt_chk();
      uVar24 = fStack_13c.fds_bits[iVar9];
      uVar15 = SSL_get_fd(to);
      uVar15 = uVar15 & 0x8000001f;
      if ((int)uVar15 < 0) {
        uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
      }
      fStack_13c.fds_bits[iVar9] = uVar24 | 1 << (uVar15 & 0xff);
    }
    if (uVar17 != 0) {
      SSL_get_fd(to);
      iVar9 = __fdelt_chk();
      uVar24 = fStack_bc.fds_bits[iVar9];
      uVar15 = SSL_get_fd(to);
      uVar15 = uVar15 & 0x8000001f;
      if ((int)uVar15 < 0) {
        uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
      }
      fStack_bc.fds_bits[iVar9] = uVar24 | 1 << (uVar15 & 0xff);
    }
    iVar9 = select(iVar26 + 1,&fStack_13c,&fStack_bc,(fd_set *)0x0,local_1e0);
    if (iVar9 < 0) {
      piVar20 = __errno_location();
      iVar26 = 1;
      BIO_printf(bio_err,"bad select %d\n",*piVar20);
      goto LAB_0002b0fc;
    }
    bVar30 = false;
  }
  else {
    local_204 = 1;
    if (!bVar1) goto LAB_0002af9e;
LAB_0002b0c8:
    iVar9 = SSL_pending(to);
    if (iVar9 == 0) goto LAB_0002af9e;
    bVar30 = true;
  }
  iVar9 = SSL_version(to);
  if ((iVar9 == 0xfeff) && (lVar14 = SSL_ctrl(to,0x4a,0,(void *)0x0), 0 < lVar14)) {
    BIO_printf(bio_err,"TIMEOUT occured\n");
  }
  if (bVar30) {
LAB_0002b036:
    iVar9 = SSL_read(to,__haystack,0x400);
    iVar16 = SSL_get_error(to,iVar9);
    switch(iVar16) {
    case 0:
      if (iVar9 < 1) goto LAB_0002be14;
      bVar1 = false;
      local_1e4 = (char *)0x0;
      local_20c = (SSL_CTX *)0x1;
      local_1ec = (char *)iVar9;
      break;
    case 1:
      goto switchD_0002b890_caseD_1;
    case 2:
      BIO_printf(bio_c_out,"read R BLOCK\n");
      local_20c = (SSL_CTX *)(uVar17 | uVar29);
      if (local_20c == (SSL_CTX *)0x0) {
        uVar17 = 1;
        bVar1 = true;
        uVar29 = (uint)local_20c;
      }
      else {
        bVar1 = true;
        local_20c = (SSL_CTX *)0x0;
      }
      break;
    case 3:
      uVar17 = 1;
      BIO_printf(bio_c_out,"read W BLOCK\n");
      uVar29 = 0;
      break;
    case 4:
      BIO_printf(bio_c_out,"read X BLOCK\n");
      break;
    case 5:
      piVar20 = __errno_location();
      iVar26 = *piVar20;
      BIO_printf(bio_err,"read:errno=%d\n",iVar26);
      goto LAB_0002b0fc;
    case 6:
      iVar26 = 0;
      BIO_printf(bio_c_out,"closed\n");
      goto LAB_0002b0fc;
    }
  }
  else {
    SSL_get_fd(to);
    iVar9 = __fdelt_chk();
    uVar24 = fStack_bc.fds_bits[iVar9];
    uVar15 = SSL_get_fd(to);
    uVar15 = uVar15 & 0x8000001f;
    if ((int)uVar15 < 0) {
      uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
    }
    if ((1 << (uVar15 & 0xff) & uVar24) != 0) goto LAB_0002b872;
    fileno(stdout);
    iVar9 = __fdelt_chk();
    uVar24 = fStack_bc.fds_bits[iVar9];
    uVar15 = fileno(stdout);
    uVar15 = uVar15 & 0x8000001f;
    if ((int)uVar15 < 0) {
      uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
    }
    if ((1 << (uVar15 & 0xff) & uVar24) == 0) {
      SSL_get_fd(to);
      iVar9 = __fdelt_chk();
      uVar24 = fStack_13c.fds_bits[iVar9];
      uVar15 = SSL_get_fd(to);
      uVar15 = uVar15 & 0x8000001f;
      if ((int)uVar15 < 0) {
        uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
      }
      if ((1 << (uVar15 & 0xff) & uVar24) != 0) goto LAB_0002b036;
      fileno(stdin);
      iVar9 = __fdelt_chk();
      uVar24 = fStack_13c.fds_bits[iVar9];
      uVar15 = fileno(stdin);
      uVar15 = uVar15 & 0x8000001f;
      if ((int)uVar15 < 0) {
        uVar15 = (uVar15 - 1 | 0xffffffe0) + 1;
      }
      if ((1 << (uVar15 & 0xff) & uVar24) != 0) {
        if (bVar5) {
          uVar10 = raw_read_stdin(local_22c,0x1000);
          iVar9 = 0;
          iVar16 = 0;
          while (iVar16 < (int)uVar10) {
            pcVar28 = (char *)((int)&local_22c->method + iVar16);
            iVar16 = iVar16 + 1;
            if (*pcVar28 == '\n') {
              iVar9 = iVar9 + 1;
            }
          }
          iVar16 = uVar10 - 1;
          while (-1 < iVar16) {
            *(char *)((int)&local_22c->method + iVar9 + iVar16) =
                 *(char *)((int)&local_22c->method + iVar16);
            cVar8 = *(char *)((int)&local_22c->method + iVar16);
            iVar25 = iVar16 + -1;
            bVar30 = cVar8 == '\n';
            if (bVar30) {
              iVar9 = iVar9 + -1;
              uVar10 = uVar10 + 1;
              cVar8 = '\r';
            }
            iVar7 = iVar9 + iVar16;
            iVar16 = iVar25;
            if (bVar30) {
              *(char *)((int)&local_22c->method + iVar7) = cVar8;
            }
          }
          if (iVar9 != 0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("lf_num == 0","s_client.c",0x738,"s_client_main");
          }
        }
        else {
          uVar10 = raw_read_stdin(local_22c,0x2000);
        }
        uVar29 = c_ign_eof;
        if (c_ign_eof == 0) {
          if (((int)uVar10 < 1) || (cVar8 = *(char *)&local_22c->method, cVar8 == 'Q')) {
            iVar26 = 0;
            BIO_printf(bio_err,"DONE\n");
            goto LAB_0002b0fc;
          }
          if (cVar8 == 'R') {
            BIO_printf(bio_err,"RENEGOTIATING\n");
            SSL_renegotiate(to);
            uVar10 = uVar29;
            uVar17 = 1;
          }
          else if (cVar8 == 'B') {
            BIO_printf(bio_err,"HEARTBEATING\n");
            SSL_ctrl(to,0x55,0,(void *)0x0);
            uVar10 = uVar29;
            uVar17 = 1;
          }
          else {
            uVar17 = 1;
            local_208 = (SSL_CTX *)c_ign_eof;
          }
        }
        else {
          local_208 = (SSL_CTX *)0x0;
          uVar17 = 1;
          uVar29 = 0;
        }
      }
    }
    else {
      iVar9 = raw_write_stdout((char *)((int)&__haystack->method + (int)local_1e4),local_1ec);
      if (iVar9 < 1) {
        iVar26 = 0;
        BIO_printf(bio_c_out,"DONE\n");
        goto LAB_0002b0fc;
      }
      local_1ec = (char *)((int)local_1ec - iVar9);
      local_1e4 = (char *)((int)local_1e4 + iVar9);
      if ((int)local_1ec < 1) {
        local_20c = (SSL_CTX *)0x0;
        bVar1 = true;
      }
    }
  }
  goto switchD_0002b890_caseD_7;
LAB_0002bd68:
  iVar26 = 1;
  piVar20 = __errno_location();
  BIO_printf(pBVar12,"connect:errno=%d\n",*piVar20);
  shutdown(local_170,0);
  close(local_170);
LAB_0002b120:
  if (to != (SSL *)0x0) {
    if (bVar4) {
      print_stuff(bio_c_out,to,1);
    }
    SSL_free(to);
  }
  goto LAB_0002a302;
LAB_0002b570:
  local_1dc = local_1dc + -1;
  BIO_printf(bio_c_out,"drop connection and then reconnect\n");
  SSL_shutdown(to);
  SSL_set_connect_state(to);
  iVar26 = SSL_get_fd(to);
  shutdown(iVar26,0);
  iVar26 = SSL_get_fd(to);
  local_204 = 0;
  close(iVar26);
  local_1f0 = 0;
  goto LAB_0002ae1c;
LAB_0002b872:
  uVar15 = SSL_write(to,(char *)((int)&local_22c->method + (int)local_208),uVar10);
  iVar9 = SSL_get_error(to,uVar15);
  switch(iVar9) {
  case 0:
    uVar10 = uVar10 - uVar15;
    local_208 = (SSL_CTX *)((int)local_208 + uVar15);
    if ((int)uVar15 < 1) {
LAB_0002be14:
      iVar26 = 1;
      goto LAB_0002b120;
    }
    uVar17 = (uint)(0 < (int)uVar10);
    uVar29 = (uint)(0 >= (int)uVar10);
    break;
  case 1:
switchD_0002b890_caseD_1:
    iVar26 = 1;
    ERR_print_errors(bio_err);
    goto LAB_0002b0fc;
  case 2:
    uVar17 = 0;
    BIO_printf(bio_c_out,"write R BLOCK\n");
    bVar1 = true;
    local_20c = (SSL_CTX *)0x0;
    break;
  case 3:
    uVar17 = 1;
    BIO_printf(bio_c_out,"write W BLOCK\n");
    uVar29 = 0;
    break;
  case 4:
    BIO_printf(bio_c_out,"write X BLOCK\n");
    break;
  case 5:
    uVar10 = uVar15 | uVar10;
    if (uVar10 != 0) {
      piVar20 = __errno_location();
      iVar26 = 1;
      BIO_printf(bio_err,"write:errno=%d\n",*piVar20);
      goto LAB_0002b0fc;
    }
    uVar17 = uVar10;
    uVar29 = 1;
    break;
  case 6:
    if (uVar10 != 0) {
      iVar26 = 0;
      BIO_printf(bio_c_out,"shutdown\n");
      goto LAB_0002b0fc;
    }
    uVar17 = uVar10;
    uVar29 = 1;
  }
  goto switchD_0002b890_caseD_7;
LAB_0002a50e:
  BIO_printf(bio_err,"usage: s_client args\n");
  BIO_printf(bio_err,"\n");
  BIO_printf(bio_err," -host host     - use -connect instead\n");
  BIO_printf(bio_err," -port port     - use -connect instead\n");
  BIO_printf(bio_err," -connect host:port - who to connect to (default is %s:%s)\n","localhost",
             &DAT_00130680);
  BIO_printf(bio_err," -verify arg   - turn on peer certificate verification\n");
  BIO_printf(bio_err," -cert arg     - certificate file to use, PEM format assumed\n");
  BIO_printf(bio_err," -certform arg - certificate format (PEM or DER) PEM default\n");
  BIO_printf(bio_err," -key arg      - Private key file to use, in cert file if\n");
  BIO_printf(bio_err,"                 not specified but cert file is.\n");
  BIO_printf(bio_err," -keyform arg  - key format (PEM or DER) PEM default\n");
  BIO_printf(bio_err," -pass arg     - private key file pass phrase source\n");
  BIO_printf(bio_err," -CApath arg   - PEM format directory of CA\'s\n");
  BIO_printf(bio_err," -CAfile arg   - PEM format file of CA\'s\n");
  BIO_printf(bio_err," -reconnect    - Drop and re-make the connection with the same Session-ID\n");
  BIO_printf(bio_err," -pause        - sleep(1) after each read(2) and write(2) system call\n");
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
  BIO_printf(bio_err," -srp_strength int - minimal mength in bits for N (default %d).\n",0x400);
  BIO_printf(bio_err," -ssl2         - just use SSLv2\n");
  BIO_printf(bio_err," -ssl3         - just use SSLv3\n");
  BIO_printf(bio_err," -tls1_2       - just use TLSv1.2\n");
  BIO_printf(bio_err," -tls1_1       - just use TLSv1.1\n");
  BIO_printf(bio_err," -tls1         - just use TLSv1\n");
  BIO_printf(bio_err," -dtls1        - just use DTLSv1\n");
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
  local_224 = (SSL_CTX *)0x0;
  ctx = (SSL_CTX *)0x0;
  goto LAB_0002a300;
}

