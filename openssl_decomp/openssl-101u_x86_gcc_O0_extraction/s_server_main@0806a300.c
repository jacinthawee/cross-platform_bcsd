
int s_server_main(int param_1,char **param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  SSL_CTX *pSVar11;
  SSL_CTX *pSVar12;
  BIO *bp;
  BIGNUM *pBVar13;
  BIO_METHOD *type;
  stack_st_X509_NAME *psVar14;
  ushort **ppuVar15;
  int iVar16;
  uint uVar17;
  DH *extraout_EDX;
  X509 *a;
  X509 *a_00;
  char **ppcVar18;
  DH *pkey;
  char *pcVar19;
  DH *pkey_00;
  int in_GS_OFFSET;
  bool bVar21;
  byte bVar22;
  char *pcVar23;
  char *pcVar24;
  DH *pDVar25;
  code *pcVar26;
  DH *pDVar27;
  DH *local_b8;
  X509 *local_b4;
  SSL_METHOD *local_b0;
  char *local_ac;
  int local_a8;
  uint local_a4;
  undefined4 local_9c;
  char *local_98;
  char *local_94;
  char *local_90;
  char *local_8c;
  undefined4 local_88;
  undefined4 local_84;
  DH *local_80;
  char *local_70;
  char *local_6c;
  undefined4 local_68;
  char *local_58;
  char **local_50 [2];
  short local_48;
  ushort local_46;
  X509_VERIFY_PARAM *local_44;
  int local_40;
  void *local_3c;
  void *local_38;
  int local_34;
  uint local_30;
  char *local_2c;
  BIO *local_28;
  undefined4 local_24;
  int local_20;
  char *pcVar20;
  
  bVar22 = 0;
  local_44 = (X509_VERIFY_PARAM *)0x0;
  local_40 = 0;
  local_3c = (void *)0x0;
  local_38 = (void *)0x0;
  local_2c = (char *)0x0;
  local_50[0] = param_2;
  local_28 = (BIO *)0x0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = 1;
  local_48 = 0x1151;
  local_b0 = SSLv23_server_method();
  local_argc = param_1;
  local_argv = local_50[0];
  signal(0xd,(__sighandler_t)0x1);
  accept_socket = 0xffffffff;
  cipher = (char *)0x0;
  s_server_verify = 0;
  s_dcert_file = (char *)0x0;
  s_dkey_file = (char *)0x0;
  s_cert_file = s_server_pem_081f4f4c;
  s_key_file = (char *)0x0;
  s_cert_file2 = s_server2_pem_081f4f57;
  s_key_file2 = (char *)0x0;
  ctx2 = (SSL_CTX *)0x0;
  s_nbio = 0;
  s_nbio_test = 0;
  ctx = (SSL_CTX *)0x0;
  www = 0;
  bio_s_out = (BIO *)0x0;
  s_debug = 0;
  s_msg = 0;
  s_quiet = (DH *)0x0;
  hack = 0;
  engine_id = (char *)0x0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar9 = load_config(bio_err,0);
  if (iVar9 != 0) {
    verify_depth = 0;
    s_nbio = 0;
    s_nbio_test = 0;
    local_50[0] = local_50[0] + 1;
    local_70 = (char *)0x0;
    param_1 = param_1 + -1;
    local_58 = (char *)0x0;
    local_8c = (char *)0x0;
    bVar5 = false;
    local_84 = 3;
    local_88 = 3;
    local_b4 = (X509 *)0x0;
    local_b8 = (DH *)0x0;
    local_68 = 3;
    local_9c = 3;
    local_94 = (char *)0x0;
    local_a8 = 1;
    bVar4 = false;
    bVar7 = false;
    bVar2 = false;
    bVar6 = false;
    bVar8 = false;
    local_a4 = 0;
    bVar3 = false;
    local_90 = (char *)0x0;
    local_6c = (char *)0x0;
    local_ac = (char *)0x0;
    local_98 = (char *)0x0;
    local_80 = (DH *)0x0;
LAB_0806a629:
    do {
      ppcVar18 = local_50[0];
      iVar9 = param_1;
      bVar21 = param_1 == 0;
      if (param_1 < 1) {
        if ((www != 0) && (local_a8 == 2)) {
          BIO_printf(bio_err,"Can\'t use -HTTP, -www or -WWW with DTLS\n");
          break;
        }
        SSL_load_error_strings();
        SSL_library_init();
        uVar10 = setup_engine(bio_err,engine_id,1);
        iVar9 = app_passwd(bio_err,local_b8,local_b4,&local_3c,&local_38);
        if (iVar9 == 0) {
          BIO_printf(bio_err,"Error getting password\n");
          break;
        }
        if (s_key_file == (char *)0x0) {
          s_key_file = s_cert_file;
        }
        if (s_key_file2 == (char *)0x0) {
          s_key_file2 = s_cert_file2;
        }
        if (bVar2) {
          a = (X509 *)0x0;
          pkey = (DH *)0x0;
          local_b8 = (DH *)0x0;
          local_b4 = (X509 *)0x0;
        }
        else {
          local_b8 = (DH *)load_key(bio_err,s_key_file,local_68,0,local_3c,uVar10,
                                    "server certificate private key file");
          if (local_b8 == (DH *)0x0) {
            ERR_print_errors(bio_err);
            break;
          }
          local_b4 = (X509 *)load_cert(bio_err,s_cert_file,local_9c,0,uVar10,
                                       "server certificate file");
          if (local_b4 == (X509 *)0x0) {
            ERR_print_errors(bio_err);
            if (ctx != (SSL_CTX *)0x0) {
              a = (X509 *)0x0;
              pkey = (DH *)0x0;
              pkey_00 = (DH *)0x0;
              a_00 = (X509 *)0x0;
              local_b0 = (SSL_METHOD *)0x1;
              goto LAB_0806a72d;
            }
            pkey_00 = (DH *)0x0;
            a = (X509 *)0x0;
            pkey = (DH *)0x0;
            local_b0 = (SSL_METHOD *)0x1;
            goto LAB_0806a768;
          }
          if (local_2c == (char *)0x0) {
            a = (X509 *)0x0;
            pkey = (DH *)0x0;
          }
          else {
            pkey = (DH *)load_key(bio_err,s_key_file2,local_68,0,local_3c,uVar10,
                                  "second server certificate private key file");
            if ((pkey == (DH *)0x0) ||
               (a = (X509 *)load_cert(bio_err,s_cert_file2,local_9c,0,uVar10,
                                      "second server certificate file"), a == (X509 *)0x0)) {
              a = (X509 *)0x0;
              pkey_00 = (DH *)0x0;
              a_00 = (X509 *)0x0;
              ERR_print_errors(bio_err);
              local_b0 = (SSL_METHOD *)0x1;
              if (ctx != (SSL_CTX *)0x0) goto LAB_0806a72d;
              goto LAB_0806a741;
            }
          }
        }
        if (local_8c == (char *)0x0) {
          local_34 = 0;
LAB_0806b0bb:
          if (s_dcert_file == (char *)0x0) {
            pkey_00 = (DH *)0x0;
            a_00 = (X509 *)0x0;
LAB_0806b132:
            pDVar25 = (DH *)0x1;
            iVar9 = app_RAND_load_file(0,bio_err,1);
            if (iVar9 == 0) {
              if (local_94 == (char *)0x0) {
                pDVar27 = (DH *)RAND_status();
                if (pDVar27 == (DH *)0x0) {
                  BIO_printf(bio_err,
                             "warning, not much extra random data, consider using the -rand option\n"
                             ,0,0);
                  pDVar25 = pDVar27;
                }
              }
              else {
LAB_0806b15b:
                pDVar25 = (DH *)app_RAND_load_files(local_94);
                BIO_printf(bio_err,"%ld semi-random bytes loaded\n",pDVar25);
              }
            }
            else if (local_94 != (char *)0x0) goto LAB_0806b15b;
            if (bio_s_out == (BIO *)0x0) {
              if (((s_quiet == (DH *)0x0) || (s_debug != 0)) || (s_msg != 0)) {
                pDVar25 = s_quiet;
                bio_s_out = BIO_new_fp(stdout,0);
              }
              else {
                type = BIO_s_null();
                bio_s_out = BIO_new(type);
              }
            }
            if (bVar2) {
              s_cert_file = (undefined *)0x0;
              s_key_file = (char *)0x0;
              s_dcert_file = (char *)0x0;
              s_dkey_file = (char *)0x0;
              s_cert_file2 = (undefined *)0x0;
              s_key_file2 = (char *)0x0;
            }
            pSVar11 = SSL_CTX_new(local_b0);
            ctx = pSVar11;
            if (pSVar11 == (SSL_CTX *)0x0) goto LAB_0806bc96;
            if (session_id_prefix != (char *)0x0) {
              pSVar12 = (SSL_CTX *)strlen(session_id_prefix);
              if (pSVar12 < (SSL_CTX *)0x20) {
                if ((SSL_CTX *)&DAT_0000000f < pSVar12) {
                  pSVar12 = (SSL_CTX *)
                            BIO_printf(bio_err,"warning: id_prefix is too long if you use SSLv2\n",
                                       pDVar25);
                  pSVar11 = ctx;
                }
              }
              else {
                pSVar12 = (SSL_CTX *)
                          BIO_printf(bio_err,
                                     "warning: id_prefix is too long, only one new session will be possible\n"
                                     ,pDVar25);
                pSVar11 = ctx;
              }
              iVar9 = SSL_CTX_set_generate_session_id(pSVar12,(GEN_SESSION_CB)pSVar11);
              if (iVar9 != 0) {
                BIO_printf(bio_err,"id_prefix \'%s\' set.\n",session_id_prefix);
                goto LAB_0806b257;
              }
LAB_0806b7db:
              pcVar23 = "error setting \'id_prefix\'\n";
              goto LAB_0806b7e3;
            }
LAB_0806b257:
            SSL_CTX_set_quiet_shutdown(ctx,1);
            if (bVar3) {
              SSL_CTX_ctrl(ctx,0x20,-0x7ffff401,(void *)0x0);
            }
            if (hack != 0) {
              SSL_CTX_ctrl(ctx,0x20,0x40000000,(void *)0x0);
            }
            SSL_CTX_ctrl(ctx,0x20,local_a4,(void *)0x0);
            if (bVar4) {
              SSL_CTX_set_info_callback(ctx,apps_ssl_info_callback);
            }
            if (bVar5) {
              pDVar27 = (DH *)0x0;
              SSL_CTX_ctrl(ctx,0x2c,0,(void *)0x0);
            }
            else {
              pDVar27 = (DH *)0x0;
              SSL_CTX_ctrl(ctx,0x2a,0x80,(void *)0x0);
            }
            if (srtp_profiles != (char *)0x0) {
              SSL_CTX_set_tlsext_use_srtp(ctx,srtp_profiles);
            }
            pDVar25 = local_80;
            iVar9 = SSL_CTX_load_verify_locations(ctx,local_98,(char *)local_80);
            if ((iVar9 == 0) || (iVar9 = SSL_CTX_set_default_verify_paths(ctx), iVar9 == 0)) {
              ERR_print_errors(bio_err);
            }
            if (local_44 != (X509_VERIFY_PARAM *)0x0) {
              SSL_CTX_set1_param(ctx,local_44);
            }
            if (a == (X509 *)0x0) {
              if (ctx2 != (SSL_CTX *)0x0) goto LAB_0806b35c;
            }
            else {
              ctx2 = SSL_CTX_new(local_b0);
              if (ctx2 == (SSL_CTX *)0x0) goto LAB_0806bc96;
LAB_0806b35c:
              BIO_printf(bio_s_out,"Setting secondary ctx parameters\n");
              if (session_id_prefix != (char *)0x0) {
                pSVar11 = (SSL_CTX *)strlen(session_id_prefix);
                if (pSVar11 < (SSL_CTX *)0x20) {
                  if ((SSL_CTX *)&DAT_0000000f < pSVar11) {
                    pSVar11 = (SSL_CTX *)
                              BIO_printf(bio_err,"warning: id_prefix is too long if you use SSLv2\n"
                                        );
                  }
                }
                else {
                  pSVar11 = (SSL_CTX *)
                            BIO_printf(bio_err,
                                       "warning: id_prefix is too long, only one new session will be possible\n"
                                      );
                }
                iVar9 = SSL_CTX_set_generate_session_id(pSVar11,(GEN_SESSION_CB)ctx2);
                if (iVar9 == 0) goto LAB_0806b7db;
                BIO_printf(bio_err,"id_prefix \'%s\' set.\n",session_id_prefix);
              }
              SSL_CTX_set_quiet_shutdown(ctx2,1);
              if (bVar3) {
                SSL_CTX_ctrl(ctx2,0x20,-0x7ffff401,(void *)0x0);
              }
              if (hack != 0) {
                SSL_CTX_ctrl(ctx2,0x20,0x40000000,(void *)0x0);
              }
              SSL_CTX_ctrl(ctx2,0x20,local_a4,(void *)0x0);
              if (bVar4) {
                SSL_CTX_set_info_callback(ctx2,apps_ssl_info_callback);
              }
              if (bVar5) {
                pDVar27 = (DH *)0x0;
                SSL_CTX_ctrl(ctx2,0x2c,0,(void *)0x0);
              }
              else {
                pDVar27 = (DH *)0x0;
                SSL_CTX_ctrl(ctx2,0x2a,0x80,(void *)0x0);
              }
              iVar9 = SSL_CTX_load_verify_locations(ctx2,local_98,(char *)local_80);
              if ((iVar9 == 0) || (iVar9 = SSL_CTX_set_default_verify_paths(ctx2), iVar9 == 0)) {
                ERR_print_errors(bio_err);
              }
              if (local_44 != (X509_VERIFY_PARAM *)0x0) {
                SSL_CTX_set1_param(ctx2,local_44);
              }
            }
            if (local_34 != 0) {
              SSL_CTX_set_next_protos_advertised_cb(ctx,next_proto_cb,&local_34);
            }
            if (!bVar6) {
              if (local_6c == (char *)0x0) {
                if (s_cert_file != (undefined *)0x0) {
                  local_b0 = (SSL_METHOD *)load_dh_param();
                  goto LAB_0806b52d;
                }
LAB_0806bc1f:
                BIO_printf(bio_s_out,"Using default temp DH parameters\n");
                local_b0 = (SSL_METHOD *)DH_new();
                if (local_b0 != (SSL_METHOD *)0x0) {
                  pBVar13 = BN_bin2bn(dh2048_p,0x100,(BIGNUM *)0x0);
                  ((DH *)local_b0)->p = pBVar13;
                  pBVar13 = BN_bin2bn("\x02",1,(BIGNUM *)0x0);
                  ((DH *)local_b0)->g = pBVar13;
                  if ((((DH *)local_b0)->p != (BIGNUM *)0x0) && (pBVar13 != (BIGNUM *)0x0))
                  goto LAB_0806b54f;
                  DH_free((DH *)local_b0);
                }
LAB_0806bc96:
                ERR_print_errors(bio_err);
                local_b0 = (SSL_METHOD *)0x1;
                goto LAB_0806b5fd;
              }
              bp = BIO_new_file(local_6c,"r");
              if (bp == (BIO *)0x0) goto LAB_0806bc1f;
              local_b0 = (SSL_METHOD *)
                         PEM_read_bio_DHparams(bp,(DH **)0x0,(undefined1 *)0x0,(void *)0x0);
              BIO_free(bp);
LAB_0806b52d:
              if (local_b0 == (SSL_METHOD *)0x0) goto LAB_0806bc1f;
              BIO_printf(bio_s_out,"Setting temp DH parameters\n");
LAB_0806b54f:
              pDVar27 = (DH *)0x0;
              BIO_ctrl(bio_s_out,0xb,0,(void *)0x0);
              SSL_CTX_ctrl(ctx,3,0,local_b0);
              if (ctx2 != (SSL_CTX *)0x0) {
                if ((local_6c == (char *)0x0) &&
                   (pDVar25 = (DH *)load_dh_param(), pDVar25 != (DH *)0x0)) {
                  BIO_printf(bio_s_out,"Setting temp DH parameters\n",ctx2,ctx2);
                  BIO_ctrl(bio_s_out,0xb,0,(void *)0x0);
                  DH_free((DH *)local_b0);
                  local_b0 = (SSL_METHOD *)pDVar25;
                }
                pDVar27 = (DH *)local_b0;
                SSL_CTX_ctrl(ctx2,3,0,local_b0);
              }
              DH_free((DH *)local_b0);
            }
            if (bVar7) {
LAB_0806b8ff:
              pDVar25 = local_b8;
              iVar9 = set_cert_key_stuff(ctx,local_b4,local_b8);
              local_b0 = (SSL_METHOD *)0x1;
              if ((iVar9 != 0) &&
                 ((ctx2 == (SSL_CTX *)0x0 ||
                  (pDVar25 = pkey, iVar9 = set_cert_key_stuff(ctx2,a,pkey), iVar9 != 0)))) {
                if (a_00 != (X509 *)0x0) {
                  pDVar25 = pkey_00;
                  iVar9 = set_cert_key_stuff(ctx,a_00,pkey_00);
                  local_b0 = (SSL_METHOD *)0x1;
                  if (iVar9 == 0) goto LAB_0806b5fd;
                }
                if ((!bVar8) &&
                   (SSL_CTX_set_tmp_rsa_callback(ctx,tmp_rsa_cb), ctx2 != (SSL_CTX *)0x0)) {
                  pDVar25 = extraout_EDX;
                  pDVar27 = extraout_EDX;
                  SSL_CTX_set_tmp_rsa_callback(ctx2,tmp_rsa_cb);
                }
                if (psk_key != (char *)0x0) {
                  if (s_debug != 0) {
                    BIO_printf(bio_s_out,"PSK key given or JPAKE in use, setting server callback\n",
                               pDVar25,pDVar27);
                  }
                  SSL_CTX_set_psk_server_callback(ctx,psk_server_cb);
                }
                iVar9 = SSL_CTX_use_psk_identity_hint(ctx,psk_identity_hint_18489);
                if (iVar9 == 0) {
                  pcVar23 = "error setting PSK identity hint to context\n";
                }
                else {
                  if ((cipher == (char *)0x0) ||
                     ((pDVar25 = (DH *)SSL_CTX_set_cipher_list(ctx,cipher), pDVar25 != (DH *)0x0 &&
                      ((ctx2 == (SSL_CTX *)0x0 ||
                       (pDVar25 = (DH *)SSL_CTX_set_cipher_list(ctx2,cipher), pDVar25 != (DH *)0x0))
                      )))) {
                    SSL_CTX_set_verify(ctx,s_server_verify,verify_callback);
                    SSL_CTX_set_session_id_context(ctx,(uchar *)&s_server_session_id_context,4);
                    SSL_CTX_set_cookie_generate_cb(ctx,generate_cookie_callback);
                    SSL_CTX_set_cookie_verify_cb(ctx,verify_cookie_callback);
                    if (ctx2 != (SSL_CTX *)0x0) {
                      SSL_CTX_set_verify(ctx2,s_server_verify,verify_callback);
                      SSL_CTX_set_session_id_context(ctx2,(uchar *)&s_server_session_id_context,4);
                      local_28 = bio_s_out;
                      SSL_CTX_callback_ctrl(ctx2,0x35,ssl_servername_cb);
                      SSL_CTX_ctrl(ctx2,0x36,0,&local_2c);
                      SSL_CTX_callback_ctrl(ctx,0x35,ssl_servername_cb);
                      SSL_CTX_ctrl(ctx,0x36,0,&local_2c);
                    }
                    if (local_70 == (char *)0x0) {
                      if (local_98 != (char *)0x0) {
                        psVar14 = SSL_load_client_CA_file(local_98);
                        SSL_CTX_set_client_CA_list(ctx,psVar14);
                        if (ctx2 != (SSL_CTX *)0x0) {
                          psVar14 = SSL_load_client_CA_file(local_98);
                          SSL_CTX_set_client_CA_list(ctx2,psVar14);
                        }
                      }
                    }
                    else {
                      srp_callback_parm._4_4_ = SRP_VBASE_new(local_58);
                      srp_callback_parm._8_4_ = 0;
                      srp_callback_parm._0_4_ = 0;
                      local_b0 = (SSL_METHOD *)SRP_VBASE_init(srp_callback_parm._4_4_,local_70);
                      if (local_b0 != (SSL_METHOD *)0x0) {
                        BIO_printf(bio_err,"Cannot initialize SRP verifier file \"%s\":ret=%d\n",
                                   local_70,local_b0);
                        goto LAB_0806b5fd;
                      }
                      pcVar26 = verify_callback;
                      SSL_CTX_set_verify(ctx,0,verify_callback);
                      SSL_CTX_set_srp_cb_arg(ctx,srp_callback_parm,pcVar26,local_b0);
                      SSL_CTX_set_srp_username_callback(ctx,ssl_srp_server_param_cb);
                    }
                    BIO_printf(bio_s_out,"ACCEPT\n");
                    BIO_ctrl(bio_s_out,0xb,0,(void *)0x0);
                    if (www == 0) {
                      pcVar26 = sv_body;
                    }
                    else {
                      pcVar26 = www_body;
                    }
                    do_server((int)local_48,local_a8,&accept_socket,pcVar26,local_ac);
                    print_stats();
                    local_b0 = (SSL_METHOD *)0x0;
                    goto LAB_0806b5fd;
                  }
                  pcVar23 = "error setting cipher list\n";
                }
LAB_0806b7e3:
                BIO_printf(bio_err,pcVar23,pDVar25);
                ERR_print_errors(bio_err);
                local_b0 = (SSL_METHOD *)0x1;
              }
            }
            else if (local_90 == (char *)0x0) {
              BIO_printf(bio_s_out,"Using default temp ECDH parameters\n");
              local_b0 = (SSL_METHOD *)EC_KEY_new_by_curve_name(0x19f);
              if (local_b0 != (SSL_METHOD *)0x0) {
LAB_0806b8af:
                pDVar27 = (DH *)0x0;
                BIO_ctrl(bio_s_out,0xb,0,(void *)0x0);
                SSL_CTX_ctrl(ctx,4,0,local_b0);
                if (ctx2 != (SSL_CTX *)0x0) {
                  pDVar27 = (DH *)local_b0;
                  SSL_CTX_ctrl(ctx2,4,0,local_b0);
                }
                EC_KEY_free((EC_KEY *)local_b0);
                goto LAB_0806b8ff;
              }
              BIO_printf(bio_err,"unable to create curve (nistp256)\n",0,0);
              local_b0 = (SSL_METHOD *)0x1;
            }
            else {
              iVar9 = OBJ_sn2nid(local_90);
              if (iVar9 == 0) {
                BIO_printf(bio_err,"unknown curve name (%s)\n",local_90);
                local_b0 = (SSL_METHOD *)0x1;
              }
              else {
                local_b0 = (SSL_METHOD *)EC_KEY_new_by_curve_name(iVar9);
                if (local_b0 != (SSL_METHOD *)0x0) {
                  BIO_printf(bio_s_out,"Setting temp ECDH parameters\n");
                  goto LAB_0806b8af;
                }
                BIO_printf(bio_err,"unable to create curve (%s)\n",local_90,0);
                local_b0 = (SSL_METHOD *)0x1;
              }
            }
          }
          else {
            if (s_dkey_file == (char *)0x0) {
              s_dkey_file = s_dcert_file;
            }
            pkey_00 = (DH *)load_key(bio_err,s_dkey_file,local_84,0,local_38,uVar10,
                                     "second certificate private key file");
            if (pkey_00 != (DH *)0x0) {
              a_00 = (X509 *)load_cert(bio_err,s_dcert_file,local_88,0,uVar10,
                                       "second server certificate file");
              if (a_00 != (X509 *)0x0) goto LAB_0806b132;
              goto LAB_0806bc96;
            }
            a_00 = (X509 *)0x0;
            ERR_print_errors(bio_err);
            local_b0 = (SSL_METHOD *)0x1;
          }
        }
        else {
          local_34 = next_protos_parse(&local_46,local_8c);
          if (local_34 != 0) {
            local_30 = (uint)local_46;
            goto LAB_0806b0bb;
          }
          pkey_00 = (DH *)0x0;
          a_00 = (X509 *)0x0;
          local_b0 = (SSL_METHOD *)0x1;
        }
LAB_0806b5fd:
        if (ctx != (SSL_CTX *)0x0) goto LAB_0806a72d;
        goto LAB_0806a739;
      }
      iVar16 = 6;
      pcVar23 = *local_50[0];
      pcVar20 = pcVar23;
      pcVar24 = "-port";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
LAB_0806a64b:
        param_1 = param_1 + -1;
        if (param_1 == 0) goto LAB_0806a9a0;
        ppcVar18 = local_50[0] + 1;
        local_50[0] = local_50[0] + 1;
        iVar16 = extract_port(*ppcVar18,&local_48);
joined_r0x0806a679:
        iVar9 = param_1;
        ppcVar18 = local_50[0];
        if (iVar16 == 0) goto LAB_0806a9a0;
LAB_0806a618:
        param_1 = iVar9 + -1;
        local_50[0] = ppcVar18 + 1;
        goto LAB_0806a629;
      }
      iVar16 = 8;
      pcVar20 = pcVar23;
      pcVar24 = "-accept";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) goto LAB_0806a64b;
      iVar16 = 8;
      pcVar20 = pcVar23;
      pcVar24 = "-verify";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        s_server_verify = 5;
        if (param_1 != 0) {
          ppcVar18 = local_50[0] + 1;
          local_50[0] = local_50[0] + 1;
          verify_depth = strtol(*ppcVar18,(char **)0x0,10);
          pcVar23 = "verify depth is %d\n";
LAB_0806a5f8:
          BIO_printf(bio_err,pcVar23,verify_depth);
          iVar9 = param_1;
          ppcVar18 = local_50[0];
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 8;
      pcVar20 = pcVar23;
      pcVar24 = "-Verify";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        s_server_verify = 7;
        if (param_1 != 0) {
          ppcVar18 = local_50[0] + 1;
          local_50[0] = local_50[0] + 1;
          verify_depth = strtol(*ppcVar18,(char **)0x0,10);
          pcVar23 = "verify depth is %d, must return a certificate\n";
          goto LAB_0806a5f8;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 9;
      pcVar20 = pcVar23;
      pcVar24 = "-context";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          local_ac = local_50[0][1];
          iVar9 = param_1;
          ppcVar18 = local_50[0] + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 6;
      pcVar20 = pcVar23;
      pcVar24 = "-cert";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          s_cert_file = local_50[0][1];
          iVar9 = param_1;
          ppcVar18 = local_50[0] + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 10;
      pcVar20 = pcVar23;
      pcVar24 = "-certform";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          ppcVar18 = local_50[0] + 1;
          local_50[0] = local_50[0] + 1;
          local_9c = str2fmt(*ppcVar18);
          iVar9 = param_1;
          ppcVar18 = local_50[0];
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 5;
      pcVar20 = pcVar23;
      pcVar24 = "-key";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          s_key_file = local_50[0][1];
          iVar9 = param_1;
          ppcVar18 = local_50[0] + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 9;
      pcVar20 = pcVar23;
      pcVar24 = "-keyform";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          ppcVar18 = local_50[0] + 1;
          local_50[0] = local_50[0] + 1;
          local_68 = str2fmt(*ppcVar18);
          iVar9 = param_1;
          ppcVar18 = local_50[0];
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 6;
      pcVar20 = pcVar23;
      pcVar24 = "-pass";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          local_b8 = (DH *)local_50[0][1];
          iVar9 = param_1;
          ppcVar18 = local_50[0] + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 9;
      pcVar20 = pcVar23;
      pcVar24 = "-dhparam";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          local_6c = local_50[0][1];
          iVar9 = param_1;
          ppcVar18 = local_50[0] + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 0xd;
      pcVar20 = pcVar23;
      pcVar24 = "-named_curve";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          local_90 = local_50[0][1];
          iVar9 = param_1;
          ppcVar18 = local_50[0] + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 0xb;
      pcVar20 = pcVar23;
      pcVar24 = "-dcertform";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          ppcVar18 = local_50[0] + 1;
          local_50[0] = local_50[0] + 1;
          local_88 = str2fmt(*ppcVar18);
          iVar9 = param_1;
          ppcVar18 = local_50[0];
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 7;
      pcVar20 = pcVar23;
      pcVar24 = "-dcert";
      do {
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          s_dcert_file = local_50[0][1];
          iVar9 = param_1;
          ppcVar18 = local_50[0] + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = 10;
      pcVar20 = pcVar23;
      pcVar24 = "-dkeyform";
      do {
        pcVar19 = pcVar20;
        if (iVar16 == 0) break;
        iVar16 = iVar16 + -1;
        pcVar19 = pcVar20 + (uint)bVar22 * -2 + 1;
        bVar21 = *pcVar20 == *pcVar24;
        pcVar20 = pcVar19;
        pcVar24 = pcVar24 + (uint)bVar22 * -2 + 1;
      } while (bVar21);
      if (bVar21) {
        param_1 = param_1 + -1;
        if (param_1 != 0) {
          ppcVar18 = local_50[0] + 1;
          local_50[0] = local_50[0] + 1;
          local_84 = str2fmt(*ppcVar18);
          iVar9 = param_1;
          ppcVar18 = local_50[0];
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = strcmp(pcVar23,"-dpass");
      if (iVar16 == 0) {
        param_1 = iVar9 + -1;
        if (param_1 != 0) {
          local_b4 = (X509 *)ppcVar18[1];
          iVar9 = param_1;
          ppcVar18 = ppcVar18 + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = strcmp(pcVar23,"-dkey");
      if (iVar16 == 0) {
        param_1 = iVar9 + -1;
        if (param_1 != 0) {
          s_dkey_file = ppcVar18[1];
          iVar9 = param_1;
          ppcVar18 = ppcVar18 + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      iVar16 = strcmp(pcVar23,"-nocert");
      if (iVar16 == 0) {
        bVar2 = true;
        goto LAB_0806a618;
      }
      iVar16 = strcmp(pcVar23,"-CApath");
      if (iVar16 == 0) {
        param_1 = iVar9 + -1;
        if (param_1 != 0) {
          local_80 = (DH *)ppcVar18[1];
          iVar9 = param_1;
          ppcVar18 = ppcVar18 + 1;
          goto LAB_0806a618;
        }
        goto LAB_0806a9a0;
      }
      pcVar24 = "-no_cache";
      pcVar20 = pcVar19;
      iVar16 = strcmp(pcVar23,"-no_cache");
      if (iVar16 == 0) {
        bVar5 = true;
        goto LAB_0806a618;
      }
      iVar9 = args_verify(local_50,&param_1,&local_40,bio_err,&local_44,pcVar24,pcVar19,pcVar20);
      ppcVar18 = local_50[0];
      if (iVar9 == 0) {
        pcVar23 = *local_50[0];
        iVar9 = strcmp(pcVar23,"-verify_return_error");
        if (iVar9 == 0) {
          verify_return_error = 1;
          iVar9 = param_1;
          goto LAB_0806a618;
        }
        iVar9 = strcmp(pcVar23,"-serverpref");
        if (iVar9 == 0) {
          local_a4 = local_a4 | 0x400000;
          iVar9 = param_1;
          goto LAB_0806a618;
        }
        iVar9 = strcmp(pcVar23,"-legacy_renegotiation");
        if (iVar9 == 0) {
          local_a4 = local_a4 | 0x40000;
          iVar9 = param_1;
          goto LAB_0806a618;
        }
        iVar9 = strcmp(pcVar23,"-cipher");
        if (iVar9 == 0) {
          param_1 = param_1 + -1;
          if (0 < param_1) {
            cipher = ppcVar18[1];
            iVar9 = param_1;
            ppcVar18 = ppcVar18 + 1;
            goto LAB_0806a618;
          }
        }
        else {
          iVar9 = strcmp(pcVar23,"-CAfile");
          if (iVar9 == 0) {
            param_1 = param_1 + -1;
            if (0 < param_1) {
              local_98 = ppcVar18[1];
              iVar9 = param_1;
              ppcVar18 = ppcVar18 + 1;
              goto LAB_0806a618;
            }
          }
          else {
            iVar9 = strcmp(pcVar23,"-nbio");
            if (iVar9 == 0) {
              s_nbio = 1;
              iVar9 = param_1;
              goto LAB_0806a618;
            }
            iVar9 = strcmp(pcVar23,"-nbio_test");
            if (iVar9 == 0) {
              s_nbio = 1;
              s_nbio_test = 1;
              iVar9 = param_1;
              goto LAB_0806a618;
            }
            iVar9 = strcmp(pcVar23,"-debug");
            if (iVar9 == 0) {
              s_debug = 1;
              iVar9 = param_1;
              goto LAB_0806a618;
            }
            iVar9 = strcmp(pcVar23,"-tlsextdebug");
            if (iVar9 == 0) {
              s_tlsextdebug = 1;
              iVar9 = param_1;
              goto LAB_0806a618;
            }
            iVar9 = strcmp(pcVar23,"-status");
            if (iVar9 == 0) {
              s_tlsextstatus = 1;
              iVar9 = param_1;
              goto LAB_0806a618;
            }
            iVar9 = strcmp(pcVar23,"-status_verbose");
            if (iVar9 == 0) {
              s_tlsextstatus = 1;
              tlscstatp._24_4_ = 1;
              iVar9 = param_1;
              goto LAB_0806a618;
            }
            iVar9 = strcmp(pcVar23,"-status_timeout");
            if (iVar9 == 0) {
              s_tlsextstatus = 1;
              param_1 = param_1 + -1;
              if (0 < param_1) {
                local_50[0] = ppcVar18 + 1;
                tlscstatp._16_4_ = strtol(ppcVar18[1],(char **)0x0,10);
                iVar9 = param_1;
                ppcVar18 = local_50[0];
                goto LAB_0806a618;
              }
            }
            else {
              iVar9 = strcmp(pcVar23,"-status_url");
              if (iVar9 == 0) {
                s_tlsextstatus = 1;
                param_1 = param_1 + -1;
                if (0 < param_1) {
                  local_50[0] = ppcVar18 + 1;
                  iVar16 = OCSP_parse_url(ppcVar18[1],(char **)tlscstatp,(char **)(tlscstatp + 8),
                                          (char **)(tlscstatp + 4),(int *)(tlscstatp + 0xc));
                  iVar9 = param_1;
                  ppcVar18 = local_50[0];
                  if (iVar16 != 0) goto LAB_0806a618;
                  BIO_printf(bio_err,"Error parsing URL\n",0,0);
                }
              }
              else {
                iVar9 = strcmp(pcVar23,"-msg");
                if (iVar9 == 0) {
                  s_msg = 1;
                  iVar9 = param_1;
                  goto LAB_0806a618;
                }
                iVar9 = strcmp(pcVar23,"-hack");
                if (iVar9 == 0) {
                  hack = 1;
                  iVar9 = param_1;
                  goto LAB_0806a618;
                }
                iVar9 = strcmp(pcVar23,"-state");
                if (iVar9 == 0) {
                  bVar4 = true;
                  iVar9 = param_1;
                  goto LAB_0806a618;
                }
                iVar9 = strcmp(pcVar23,"-crlf");
                if (iVar9 == 0) {
                  s_crlf = 1;
                  iVar9 = param_1;
                  goto LAB_0806a618;
                }
                iVar9 = strcmp(pcVar23,"-quiet");
                if (iVar9 == 0) {
                  s_quiet = (DH *)0x1;
                  iVar9 = param_1;
                  goto LAB_0806a618;
                }
                iVar9 = strcmp(pcVar23,"-bugs");
                if (iVar9 == 0) {
                  bVar3 = true;
                  iVar9 = param_1;
                  goto LAB_0806a618;
                }
                iVar9 = strcmp(pcVar23,"-no_tmp_rsa");
                if (iVar9 == 0) {
                  bVar8 = true;
                  iVar9 = param_1;
                  goto LAB_0806a618;
                }
                iVar9 = strcmp(pcVar23,"-no_dhe");
                if (iVar9 == 0) {
                  bVar6 = true;
                  iVar9 = param_1;
                  goto LAB_0806a618;
                }
                iVar9 = strcmp(pcVar23,"-no_ecdhe");
                if (iVar9 == 0) {
                  bVar7 = true;
                  iVar9 = param_1;
                  goto LAB_0806a618;
                }
                iVar9 = strcmp(pcVar23,"-psk_hint");
                if (iVar9 == 0) {
                  param_1 = param_1 + -1;
                  if (0 < param_1) {
                    psk_identity_hint_18489 = ppcVar18[1];
                    iVar9 = param_1;
                    ppcVar18 = ppcVar18 + 1;
                    goto LAB_0806a618;
                  }
                }
                else {
                  iVar9 = strcmp(pcVar23,"-psk");
                  if (iVar9 == 0) {
                    iVar9 = param_1 + -1;
                    param_1 = iVar9;
                    if (0 < iVar9) {
                      pcVar23 = ppcVar18[1];
                      uVar17 = 0xffffffff;
                      pcVar20 = pcVar23;
                      do {
                        if (uVar17 == 0) break;
                        uVar17 = uVar17 - 1;
                        cVar1 = *pcVar20;
                        pcVar20 = pcVar20 + (uint)bVar22 * -2 + 1;
                      } while (cVar1 != '\0');
                      psk_key = pcVar23;
                      local_50[0] = ppcVar18 + 1;
                      for (iVar16 = 0; ppcVar18 = ppcVar18 + 1, iVar16 != ~uVar17 - 1;
                          iVar16 = iVar16 + 1) {
                        ppuVar15 = __ctype_b_loc();
                        if ((*(byte *)((int)*ppuVar15 + (uint)(byte)pcVar23[iVar16] * 2 + 1) & 0x10)
                            == 0) {
                          BIO_printf(bio_err,"Not a hex number \'%s\'\n",pcVar23,*ppuVar15);
                          goto LAB_0806a9a0;
                        }
                      }
                      goto LAB_0806a618;
                    }
                  }
                  else {
                    iVar9 = strcmp(pcVar23,"-srpvfile");
                    if (iVar9 == 0) {
                      param_1 = param_1 + -1;
                      if (0 < param_1) {
                        local_50[0] = ppcVar18 + 1;
                        local_70 = ppcVar18[1];
                        local_b0 = TLSv1_server_method();
                        iVar9 = param_1;
                        ppcVar18 = local_50[0];
                        goto LAB_0806a618;
                      }
                    }
                    else {
                      iVar9 = strcmp(pcVar23,"-srpuserseed");
                      if (iVar9 == 0) {
                        param_1 = param_1 + -1;
                        if (0 < param_1) {
                          local_50[0] = ppcVar18 + 1;
                          local_58 = ppcVar18[1];
                          local_b0 = TLSv1_server_method();
                          iVar9 = param_1;
                          ppcVar18 = local_50[0];
                          goto LAB_0806a618;
                        }
                      }
                      else {
                        iVar9 = strcmp(pcVar23,"-www");
                        if (iVar9 == 0) {
                          www = 1;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-WWW");
                        if (iVar9 == 0) {
                          www = 2;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-HTTP");
                        if (iVar9 == 0) {
                          www = 3;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-no_ssl2");
                        if (iVar9 == 0) {
                          local_a4 = local_a4 | 0x1000000;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-no_ssl3");
                        if (iVar9 == 0) {
                          local_a4 = local_a4 | 0x2000000;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-no_tls1");
                        if (iVar9 == 0) {
                          local_a4 = local_a4 | 0x4000000;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-no_tls1_1");
                        if (iVar9 == 0) {
                          local_a4 = local_a4 | 0x10000000;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-no_tls1_2");
                        if (iVar9 == 0) {
                          local_a4 = local_a4 | 0x8000000;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-no_comp");
                        if (iVar9 == 0) {
                          local_a4 = local_a4 | 0x20000;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-no_ticket");
                        if (iVar9 == 0) {
                          local_a4 = local_a4 | 0x4000;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-ssl3");
                        if (iVar9 == 0) {
                          local_b0 = SSLv3_server_method();
                          iVar9 = param_1;
                          ppcVar18 = local_50[0];
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-tls1");
                        if (iVar9 == 0) {
                          local_b0 = TLSv1_server_method();
                          iVar9 = param_1;
                          ppcVar18 = local_50[0];
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-tls1_1");
                        if (iVar9 == 0) {
                          local_b0 = TLSv1_1_server_method();
                          iVar9 = param_1;
                          ppcVar18 = local_50[0];
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-tls1_2");
                        if (iVar9 == 0) {
                          local_b0 = TLSv1_2_server_method();
                          iVar9 = param_1;
                          ppcVar18 = local_50[0];
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-dtls1");
                        if (iVar9 == 0) {
                          local_b0 = DTLSv1_server_method();
                          local_a8 = 2;
                          iVar9 = param_1;
                          ppcVar18 = local_50[0];
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-timeout");
                        if (iVar9 == 0) {
                          enable_timeouts = 1;
                          iVar9 = param_1;
                          goto LAB_0806a618;
                        }
                        iVar9 = strcmp(pcVar23,"-mtu");
                        if (iVar9 == 0) {
                          param_1 = param_1 + -1;
                          if (0 < param_1) {
                            local_50[0] = ppcVar18 + 1;
                            socket_mtu = strtol(ppcVar18[1],(char **)0x0,10);
                            iVar9 = param_1;
                            ppcVar18 = local_50[0];
                            goto LAB_0806a618;
                          }
                        }
                        else {
                          iVar16 = strcmp(pcVar23,"-chain");
                          iVar9 = param_1;
                          if (iVar16 == 0) goto LAB_0806a618;
                          iVar9 = strcmp(pcVar23,"-id_prefix");
                          if (iVar9 == 0) {
                            param_1 = param_1 + -1;
                            if (0 < param_1) {
                              session_id_prefix = ppcVar18[1];
                              iVar9 = param_1;
                              ppcVar18 = ppcVar18 + 1;
                              goto LAB_0806a618;
                            }
                          }
                          else {
                            iVar9 = strcmp(pcVar23,"-engine");
                            if (iVar9 == 0) {
                              param_1 = param_1 + -1;
                              if (0 < param_1) {
                                engine_id = ppcVar18[1];
                                iVar9 = param_1;
                                ppcVar18 = ppcVar18 + 1;
                                goto LAB_0806a618;
                              }
                            }
                            else {
                              iVar9 = strcmp(pcVar23,"-rand");
                              if (iVar9 == 0) {
                                param_1 = param_1 + -1;
                                if (0 < param_1) {
                                  local_94 = ppcVar18[1];
                                  iVar9 = param_1;
                                  ppcVar18 = ppcVar18 + 1;
                                  goto LAB_0806a618;
                                }
                              }
                              else {
                                iVar9 = strcmp(pcVar23,"-servername");
                                if (iVar9 == 0) {
                                  param_1 = param_1 + -1;
                                  if (0 < param_1) {
                                    local_2c = ppcVar18[1];
                                    iVar9 = param_1;
                                    ppcVar18 = ppcVar18 + 1;
                                    goto LAB_0806a618;
                                  }
                                }
                                else {
                                  iVar9 = strcmp(pcVar23,"-servername_fatal");
                                  if (iVar9 == 0) {
                                    local_24 = 2;
                                    iVar9 = param_1;
                                    goto LAB_0806a618;
                                  }
                                  iVar9 = strcmp(pcVar23,"-cert2");
                                  if (iVar9 == 0) {
                                    param_1 = param_1 + -1;
                                    if (0 < param_1) {
                                      s_cert_file2 = ppcVar18[1];
                                      iVar9 = param_1;
                                      ppcVar18 = ppcVar18 + 1;
                                      goto LAB_0806a618;
                                    }
                                  }
                                  else {
                                    iVar9 = strcmp(pcVar23,"-key2");
                                    if (iVar9 == 0) {
                                      param_1 = param_1 + -1;
                                      if (0 < param_1) {
                                        s_key_file2 = ppcVar18[1];
                                        iVar9 = param_1;
                                        ppcVar18 = ppcVar18 + 1;
                                        goto LAB_0806a618;
                                      }
                                    }
                                    else {
                                      iVar9 = strcmp(pcVar23,"-nextprotoneg");
                                      if (iVar9 == 0) {
                                        param_1 = param_1 + -1;
                                        if (0 < param_1) {
                                          local_8c = ppcVar18[1];
                                          iVar9 = param_1;
                                          ppcVar18 = ppcVar18 + 1;
                                          goto LAB_0806a618;
                                        }
                                      }
                                      else {
                                        iVar9 = strcmp(pcVar23,"-use_srtp");
                                        if (iVar9 == 0) {
                                          param_1 = param_1 + -1;
                                          if (0 < param_1) {
                                            srtp_profiles = ppcVar18[1];
                                            iVar9 = param_1;
                                            ppcVar18 = ppcVar18 + 1;
                                            goto LAB_0806a618;
                                          }
                                        }
                                        else {
                                          iVar9 = strcmp(pcVar23,"-keymatexport");
                                          if (iVar9 == 0) {
                                            param_1 = param_1 + -1;
                                            if (0 < param_1) {
                                              keymatexportlabel = ppcVar18[1];
                                              iVar9 = param_1;
                                              ppcVar18 = ppcVar18 + 1;
                                              goto LAB_0806a618;
                                            }
                                          }
                                          else {
                                            iVar9 = strcmp(pcVar23,"-keymatexportlen");
                                            if (iVar9 == 0) {
                                              param_1 = param_1 + -1;
                                              if (0 < param_1) {
                                                local_50[0] = ppcVar18 + 1;
                                                keymatexportlen =
                                                     strtol(ppcVar18[1],(char **)0x0,10);
                                                iVar16 = keymatexportlen;
                                                goto joined_r0x0806a679;
                                              }
                                            }
                                            else {
                                              BIO_printf(bio_err,"unknown option %s\n",pcVar23,
                                                         ppcVar18);
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        goto LAB_0806a9a0;
      }
      if (local_40 != 0) goto LAB_0806a9a0;
    } while( true );
  }
LAB_0806a700:
  a = (X509 *)0x0;
  pkey = (DH *)0x0;
  if (ctx == (SSL_CTX *)0x0) {
    local_b0 = (SSL_METHOD *)0x1;
  }
  else {
    pkey_00 = (DH *)0x0;
    local_b8 = (DH *)0x0;
    a_00 = (X509 *)0x0;
    local_b4 = (X509 *)0x0;
    local_b0 = (SSL_METHOD *)0x1;
LAB_0806a72d:
    SSL_CTX_free(ctx);
LAB_0806a739:
    if (local_b4 != (X509 *)0x0) {
LAB_0806a741:
      X509_free(local_b4);
    }
    if (a_00 != (X509 *)0x0) {
      X509_free(a_00);
    }
    if (local_b8 != (DH *)0x0) {
LAB_0806a768:
      EVP_PKEY_free((EVP_PKEY *)local_b8);
    }
    if (pkey_00 != (DH *)0x0) {
      EVP_PKEY_free((EVP_PKEY *)pkey_00);
    }
  }
  if (local_3c != (void *)0x0) {
    CRYPTO_free(local_3c);
  }
  if (local_38 != (void *)0x0) {
    CRYPTO_free(local_38);
  }
  if (local_44 != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(local_44);
  }
  if (tlscstatp._0_4_ != (void *)0x0) {
    CRYPTO_free(tlscstatp._0_4_);
  }
  if (tlscstatp._8_4_ != (void *)0x0) {
    CRYPTO_free(tlscstatp._8_4_);
  }
  if (tlscstatp._4_4_ != (void *)0x0) {
    CRYPTO_free(tlscstatp._4_4_);
  }
  if (ctx2 != (SSL_CTX *)0x0) {
    SSL_CTX_free(ctx2);
  }
  if (a != (X509 *)0x0) {
    X509_free(a);
  }
  if (pkey != (DH *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)pkey);
  }
  if (bio_s_out != (BIO *)0x0) {
    BIO_free(bio_s_out);
    bio_s_out = (BIO *)0x0;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (int)local_b0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
LAB_0806a9a0:
  BIO_printf(bio_err,"usage: s_server [args ...]\n");
  BIO_printf(bio_err,"\n");
  BIO_printf(bio_err," -accept arg   - port to accept on (default is %d)\n",0x1151);
  BIO_printf(bio_err," -context arg  - set session ID context\n");
  BIO_printf(bio_err," -verify arg   - turn on peer certificate verification\n");
  BIO_printf(bio_err," -Verify arg   - turn on peer certificate verification, must have a cert.\n");
  BIO_printf(bio_err," -verify_return_error - return verification errors\n");
  BIO_printf(bio_err," -cert arg     - certificate file to use\n");
  BIO_printf(bio_err,"                 (default is %s)\n","server.pem");
  BIO_printf(bio_err,
             " -crl_check    - check the peer certificate has not been revoked by its CA.\n                 The CRL(s) are appended to the certificate file\n"
            );
  BIO_printf(bio_err,
             " -crl_check_all - check the peer certificate has not been revoked by its CA\n                 or any other CRL in the CA chain. CRL(s) are appened to the\n                 the certificate file.\n"
            );
  BIO_printf(bio_err," -certform arg - certificate format (PEM or DER) PEM default\n");
  BIO_printf(bio_err," -key arg      - Private Key file to use, in cert file if\n");
  BIO_printf(bio_err,"                 not specified (default is %s)\n","server.pem");
  BIO_printf(bio_err," -keyform arg  - key format (PEM, DER or ENGINE) PEM default\n");
  BIO_printf(bio_err," -pass arg     - private key file pass phrase source\n");
  BIO_printf(bio_err," -dcert arg    - second certificate file to use (usually for DSA)\n");
  BIO_printf(bio_err," -dcertform x  - second certificate format (PEM or DER) PEM default\n");
  BIO_printf(bio_err," -dkey arg     - second private key file to use (usually for DSA)\n");
  BIO_printf(bio_err," -dkeyform arg - second key format (PEM, DER or ENGINE) PEM default\n");
  BIO_printf(bio_err," -dpass arg    - second private key file pass phrase source\n");
  BIO_printf(bio_err," -dhparam arg  - DH parameter file to use, in cert file if not specified\n");
  BIO_printf(bio_err,"                 or a default set of parameters is used\n");
  BIO_printf(bio_err,
             " -named_curve arg  - Elliptic curve name to use for ephemeral ECDH keys.\n                 Use \"openssl ecparam -list_curves\" for all names\n                 (default is nistp256).\n"
            );
  BIO_printf(bio_err," -nbio         - Run with non-blocking IO\n");
  BIO_printf(bio_err," -nbio_test    - test with the non-blocking test bio\n");
  BIO_printf(bio_err," -crlf         - convert LF from terminal into CRLF\n");
  BIO_printf(bio_err," -debug        - Print more output\n");
  BIO_printf(bio_err," -msg          - Show protocol messages\n");
  BIO_printf(bio_err," -state        - Print the SSL states\n");
  BIO_printf(bio_err," -CApath arg   - PEM format directory of CA\'s\n");
  BIO_printf(bio_err," -CAfile arg   - PEM format file of CA\'s\n");
  BIO_printf(bio_err," -no_alt_chains - only ever use the first certificate chain found\n");
  BIO_printf(bio_err," -nocert       - Don\'t use any certificates (Anon-DH)\n");
  BIO_printf(bio_err," -cipher arg   - play with \'openssl ciphers\' to see what goes here\n");
  BIO_printf(bio_err," -serverpref   - Use server\'s cipher preferences\n");
  BIO_printf(bio_err," -quiet        - No server output\n");
  BIO_printf(bio_err," -no_tmp_rsa   - Do not generate a tmp RSA key\n");
  BIO_printf(bio_err," -psk_hint arg - PSK identity hint to use\n");
  BIO_printf(bio_err," -psk arg      - PSK in hex (without 0x)\n");
  BIO_printf(bio_err," -srpvfile file      - The verifier file for SRP\n");
  BIO_printf(bio_err," -srpuserseed string - A seed string for a default user salt.\n");
  BIO_printf(bio_err," -ssl2         - Just talk SSLv2\n");
  BIO_printf(bio_err," -ssl3         - Just talk SSLv3\n");
  BIO_printf(bio_err," -tls1_2       - Just talk TLSv1.2\n");
  BIO_printf(bio_err," -tls1_1       - Just talk TLSv1.1\n");
  BIO_printf(bio_err," -tls1         - Just talk TLSv1\n");
  BIO_printf(bio_err," -dtls1        - Just talk DTLSv1\n");
  BIO_printf(bio_err," -timeout      - Enable timeouts\n");
  BIO_printf(bio_err," -mtu          - Set link layer MTU\n");
  BIO_printf(bio_err," -chain        - Read a certificate chain\n");
  BIO_printf(bio_err," -no_ssl2      - Just disable SSLv2\n");
  BIO_printf(bio_err," -no_ssl3      - Just disable SSLv3\n");
  BIO_printf(bio_err," -no_tls1      - Just disable TLSv1\n");
  BIO_printf(bio_err," -no_tls1_1    - Just disable TLSv1.1\n");
  BIO_printf(bio_err," -no_tls1_2    - Just disable TLSv1.2\n");
  BIO_printf(bio_err," -no_dhe       - Disable ephemeral DH\n");
  BIO_printf(bio_err," -no_ecdhe     - Disable ephemeral ECDH\n");
  BIO_printf(bio_err," -bugs         - Turn on SSL bug compatibility\n");
  BIO_printf(bio_err," -hack         - workaround for early Netscape code\n");
  BIO_printf(bio_err," -www          - Respond to a \'GET /\' with a status page\n");
  BIO_printf(bio_err," -WWW          - Respond to a \'GET /<path> HTTP/1.0\' with file ./<path>\n");
  BIO_printf(bio_err," -HTTP         - Respond to a \'GET /<path> HTTP/1.0\' with file ./<path>\n");
  BIO_printf(bio_err,"                 with the assumption it contains a complete HTTP response.\n")
  ;
  BIO_printf(bio_err," -engine id    - Initialise and use the specified engine\n");
  BIO_printf(bio_err," -id_prefix arg - Generate SSL/TLS session IDs prefixed by \'arg\'\n");
  BIO_printf(bio_err," -rand file%cfile%c...\n",0x3a,0x3a);
  BIO_printf(bio_err," -servername host - servername for HostName TLS extension\n");
  BIO_printf(bio_err," -servername_fatal - on mismatch send fatal alert (default warning alert)\n");
  BIO_printf(bio_err," -cert2 arg    - certificate file to use for servername\n");
  BIO_printf(bio_err,"                 (default is %s)\n","server2.pem");
  BIO_printf(bio_err," -key2 arg     - Private Key file to use for servername, in cert file if\n");
  BIO_printf(bio_err,"                 not specified (default is %s)\n","server2.pem");
  BIO_printf(bio_err," -tlsextdebug  - hex dump of all TLS extensions received\n");
  BIO_printf(bio_err," -no_ticket    - disable use of RFC4507bis session tickets\n");
  BIO_printf(bio_err," -legacy_renegotiation - enable use of legacy renegotiation (dangerous)\n");
  BIO_printf(bio_err,
             " -nextprotoneg arg - set the advertised protocols for the NPN extension (comma-separated list)\n"
            );
  BIO_printf(bio_err,
             " -use_srtp profiles - Offer SRTP key management with a colon-separated profile list\n"
            );
  BIO_printf(bio_err," -keymatexport label   - Export keying material using label\n");
  BIO_printf(bio_err," -keymatexportlen len  - Export len bytes of keying material (default 20)\n");
  BIO_printf(bio_err," -status           - respond to certificate status requests\n");
  BIO_printf(bio_err," -status_verbose   - enable status request verbose printout\n");
  BIO_printf(bio_err," -status_timeout n - status request responder timeout\n");
  BIO_printf(bio_err," -status_url URL   - status request fallback URL\n");
  goto LAB_0806a700;
}

