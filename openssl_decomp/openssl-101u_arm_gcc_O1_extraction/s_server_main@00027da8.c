
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int s_server_main(int param_1,char **param_2)

{
  byte *pbVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  X509 *pXVar8;
  int iVar9;
  undefined4 uVar10;
  X509 *pkey;
  X509 *a;
  SSL_CTX *pSVar11;
  BIO *pBVar12;
  DH *dh;
  EC_KEY *key;
  BIGNUM *pBVar13;
  BIO_METHOD *type;
  stack_st_X509_NAME *psVar14;
  DH *pDVar15;
  int iVar16;
  size_t sVar17;
  size_t sVar18;
  ushort **ppuVar19;
  char **ppcVar20;
  char *pcVar21;
  char *pcVar22;
  X509 *local_cc;
  X509 *local_c8;
  X509 *local_c4;
  undefined4 local_c0;
  SSL_METHOD *local_bc;
  char *local_b8;
  uint local_b4;
  X509 *local_b0;
  X509 *local_ac;
  int local_a8;
  undefined4 local_a4;
  char *local_a0;
  char *local_9c;
  char *local_94;
  char *local_90;
  undefined4 local_8c;
  char *local_88;
  undefined4 local_78;
  char *local_6c;
  char **local_68;
  int local_64;
  short local_60 [4];
  ushort local_58 [4];
  X509_VERIFY_PARAM *local_50;
  int local_4c;
  void *local_48;
  void *local_44;
  X509 *local_40;
  uint local_3c;
  char *local_34;
  BIO *local_30;
  undefined4 local_2c;
  
  local_60[0] = 0x1151;
  local_50 = (X509_VERIFY_PARAM *)0x0;
  local_4c = 0;
  local_48 = (void *)0x0;
  local_44 = (void *)0x0;
  local_34 = (char *)0x0;
  local_30 = (BIO *)0x0;
  local_2c = 1;
  local_68 = param_2;
  local_64 = param_1;
  local_bc = SSLv23_server_method();
  local_argc = local_64;
  local_argv = local_68;
  signal(0xd,(__sighandler_t)0x1);
  cipher = (char *)0x0;
  s_server_verify = 0;
  s_dcert_file = (X509 *)0x0;
  s_dkey_file = (X509 *)0x0;
  s_key_file = (char *)0x0;
  s_key_file2 = (char *)0x0;
  ctx2 = (SSL_CTX *)0x0;
  s_nbio = 0;
  s_nbio_test = 0;
  ctx = (SSL_CTX *)0x0;
  www = 0;
  bio_s_out = (BIO *)0x0;
  s_debug = 0;
  s_msg = 0;
  s_quiet = 0;
  hack = 0;
  engine_id = (char *)0x0;
  accept_socket = 0xffffffff;
  s_cert_file = s_server_pem_0012d824;
  s_cert_file2 = s_server2_pem_0012d830;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  pXVar8 = (X509 *)load_config(bio_err,0);
  if (pXVar8 != (X509 *)0x0) {
    local_64 = local_64 + -1;
    local_68 = local_68 + 1;
    local_c0 = 3;
    local_8c = 3;
    local_78 = 3;
    local_a4 = 3;
    local_a8 = 1;
    pcVar21 = (char *)0x0;
    verify_depth = 0;
    local_6c = (char *)0x0;
    s_nbio = 0;
    local_ac = (X509 *)0x0;
    s_nbio_test = 0;
    bVar4 = false;
    local_c8 = (X509 *)0x0;
    local_cc = (X509 *)0x0;
    local_9c = (char *)0x0;
    bVar3 = false;
    bVar6 = false;
    local_b0 = (X509 *)0x0;
    bVar5 = false;
    bVar7 = false;
    local_b4 = 0;
    bVar2 = false;
    local_90 = (char *)0x0;
    local_94 = (char *)0x0;
    local_b8 = (char *)0x0;
    local_a0 = (char *)0x0;
    local_88 = (char *)0x0;
LAB_00027f16:
    iVar16 = local_64;
    ppcVar20 = local_68;
    if (local_64 < 1) {
      if ((www == 0) || (local_a8 != 2)) {
        SSL_load_error_strings();
        SSL_library_init();
        uVar10 = setup_engine(bio_err,engine_id,1);
        local_cc = (X509 *)app_passwd(bio_err,local_cc,local_c8,&local_48,&local_44);
        if (local_cc != (X509 *)0x0) {
          if (s_key_file == (char *)0x0) {
            s_key_file = s_cert_file;
          }
          if (s_key_file2 == (char *)0x0) {
            s_key_file2 = s_cert_file2;
          }
          if (local_b0 == (X509 *)0x0) {
            local_c4 = (X509 *)load_key(bio_err,s_key_file,local_78,0,local_48,uVar10,
                                        "server certificate private key file");
            pXVar8 = local_b0;
            if (local_c4 == (X509 *)0x0) {
              iVar16 = 1;
              ERR_print_errors(bio_err);
              local_cc = local_b0;
              local_c8 = local_b0;
              pkey = local_b0;
              a = local_b0;
              goto LAB_00027fee;
            }
            local_c8 = (X509 *)load_cert(bio_err,s_cert_file,local_a4,0,uVar10,
                                         "server certificate file");
            if (local_c8 == (X509 *)0x0) {
              iVar16 = 1;
              ERR_print_errors(bio_err);
              pkey = local_b0;
              a = local_b0;
              local_cc = local_b0;
              goto LAB_00027fee;
            }
            if (local_34 == (char *)0x0) {
              local_cc = local_b0;
            }
            else {
              local_cc = (X509 *)load_key(bio_err,s_key_file2,local_78,0,local_48,uVar10,
                                          "second server certificate private key file");
              if (local_cc == (X509 *)0x0) {
                iVar16 = 1;
                ERR_print_errors(bio_err);
                pkey = local_b0;
                a = local_b0;
                goto LAB_00027fee;
              }
              pXVar8 = (X509 *)load_cert(bio_err,s_cert_file2,local_a4,0,uVar10,
                                         "second server certificate file");
              if (pXVar8 == (X509 *)0x0) {
                iVar16 = 1;
                ERR_print_errors(bio_err);
                pkey = local_b0;
                a = local_b0;
                goto LAB_00027fee;
              }
            }
          }
          else {
            local_cc = (X509 *)0x0;
            local_c4 = (X509 *)0x0;
            local_c8 = (X509 *)0x0;
            pXVar8 = (X509 *)0x0;
          }
          if (local_ac == (X509 *)0x0) {
            local_40 = local_ac;
          }
          else {
            local_40 = (X509 *)next_protos_parse(local_58,local_ac);
            if (local_40 == (X509 *)0x0) {
              iVar16 = 1;
              pkey = local_40;
              a = local_40;
              goto LAB_00027fee;
            }
            local_3c = (uint)local_58[0];
          }
          pkey = s_dcert_file;
          a = s_dcert_file;
          if (s_dcert_file != (X509 *)0x0) {
            if (s_dkey_file == (X509 *)0x0) {
              s_dkey_file = s_dcert_file;
            }
            pkey = (X509 *)load_key(bio_err,s_dkey_file,local_c0,0,local_44,uVar10,
                                    "second certificate private key file");
            if (pkey == (X509 *)0x0) {
              ERR_print_errors(bio_err);
              iVar16 = 1;
              a = pkey;
              goto LAB_00027fee;
            }
            a = (X509 *)load_cert(bio_err,s_dcert_file,local_8c,0,uVar10,
                                  "second server certificate file");
            if (a == (X509 *)0x0) {
              iVar16 = 1;
              ERR_print_errors(bio_err);
              goto LAB_00027fee;
            }
          }
          iVar16 = app_RAND_load_file(0,bio_err,1);
          pBVar12 = bio_err;
          if (iVar16 == 0) {
            if (local_9c == (char *)0x0) {
              iVar16 = RAND_status();
              if (iVar16 == 0) {
                BIO_printf(bio_err,
                           "warning, not much extra random data, consider using the -rand option\n")
                ;
              }
            }
            else {
LAB_00028748:
              uVar10 = app_RAND_load_files(local_9c);
              BIO_printf(pBVar12,"%ld semi-random bytes loaded\n",uVar10);
            }
          }
          else if (local_9c != (char *)0x0) goto LAB_00028748;
          if (bio_s_out == (BIO *)0x0) {
            if (((s_quiet == 0) || (s_debug != 0)) || (s_msg != 0)) {
              bio_s_out = BIO_new_fp(stdout,0);
            }
            else {
              type = BIO_s_null();
              bio_s_out = BIO_new(type);
            }
          }
          if (local_b0 != (X509 *)0x0) {
            s_cert_file = (undefined *)0x0;
            s_key_file = (char *)0x0;
            s_dcert_file = (X509 *)0x0;
            s_dkey_file = (X509 *)0x0;
            s_cert_file2 = (undefined *)0x0;
            s_key_file2 = (char *)0x0;
          }
          pSVar11 = SSL_CTX_new(local_bc);
          ctx = pSVar11;
          if (pSVar11 == (SSL_CTX *)0x0) goto LAB_00028f5e;
          if (session_id_prefix != (char *)0x0) {
            sVar17 = strlen(session_id_prefix);
            if (sVar17 < 0x20) {
              if (0xf < sVar17) {
                BIO_printf(bio_err,"warning: id_prefix is too long if you use SSLv2\n");
                pSVar11 = ctx;
              }
            }
            else {
              BIO_printf(bio_err,
                         "warning: id_prefix is too long, only one new session will be possible\n");
              pSVar11 = ctx;
            }
            iVar16 = SSL_CTX_set_generate_session_id(pSVar11,generate_session_id + 1);
            if (iVar16 != 0) {
              BIO_printf(bio_err,"id_prefix \'%s\' set.\n",session_id_prefix);
              goto LAB_000287e2;
            }
LAB_00028b9c:
            iVar16 = 1;
            BIO_printf(bio_err,"error setting \'id_prefix\'\n");
            ERR_print_errors(bio_err);
            goto LAB_00027fee;
          }
LAB_000287e2:
          SSL_CTX_set_quiet_shutdown(ctx,1);
          if (bVar2) {
            SSL_CTX_ctrl(ctx,0x20,-0x7ffff401,(void *)0x0);
          }
          if (hack != 0) {
            SSL_CTX_ctrl(ctx,0x20,0x40000000,(void *)0x0);
          }
          SSL_CTX_ctrl(ctx,0x20,local_b4,(void *)0x0);
          if (bVar3) {
            SSL_CTX_set_info_callback(ctx,apps_ssl_info_callback + 1);
          }
          if (bVar4) {
            SSL_CTX_ctrl(ctx,0x2c,0,(void *)0x0);
          }
          else {
            SSL_CTX_ctrl(ctx,0x2a,0x80,(void *)0x0);
          }
          if (srtp_profiles != (char *)0x0) {
            SSL_CTX_set_tlsext_use_srtp(ctx,srtp_profiles);
          }
          iVar16 = SSL_CTX_load_verify_locations(ctx,local_a0,local_88);
          if ((iVar16 == 0) || (iVar16 = SSL_CTX_set_default_verify_paths(ctx), iVar16 == 0)) {
            ERR_print_errors(bio_err);
          }
          if (local_50 != (X509_VERIFY_PARAM *)0x0) {
            SSL_CTX_set1_param(ctx,local_50);
          }
          if (pXVar8 == (X509 *)0x0) {
            if (ctx2 != (SSL_CTX *)0x0) goto LAB_00028888;
          }
          else {
            ctx2 = SSL_CTX_new(local_bc);
            if (ctx2 == (SSL_CTX *)0x0) goto LAB_00028f5e;
LAB_00028888:
            BIO_printf(bio_s_out,"Setting secondary ctx parameters\n");
            if (session_id_prefix != (char *)0x0) {
              sVar17 = strlen(session_id_prefix);
              if (sVar17 < 0x20) {
                if (0xf < sVar17) {
                  BIO_printf(bio_err,"warning: id_prefix is too long if you use SSLv2\n");
                }
              }
              else {
                BIO_printf(bio_err,
                           "warning: id_prefix is too long, only one new session will be possible\n"
                          );
              }
              iVar16 = SSL_CTX_set_generate_session_id(ctx2,generate_session_id + 1);
              if (iVar16 == 0) goto LAB_00028b9c;
              BIO_printf(bio_err,"id_prefix \'%s\' set.\n",session_id_prefix);
            }
            SSL_CTX_set_quiet_shutdown(ctx2,1);
            if (bVar2) {
              SSL_CTX_ctrl(ctx2,0x20,-0x7ffff401,(void *)0x0);
            }
            if (hack != 0) {
              SSL_CTX_ctrl(ctx2,0x20,0x40000000,(void *)0x0);
            }
            SSL_CTX_ctrl(ctx2,0x20,local_b4,(void *)0x0);
            if (bVar3) {
              SSL_CTX_set_info_callback(ctx2,apps_ssl_info_callback + 1);
            }
            if (bVar4) {
              SSL_CTX_ctrl(ctx2,0x2c,0,(void *)0x0);
            }
            else {
              SSL_CTX_ctrl(ctx2,0x2a,0x80,(void *)0x0);
            }
            iVar16 = SSL_CTX_load_verify_locations(ctx2,local_a0,local_88);
            if ((iVar16 == 0) || (iVar16 = SSL_CTX_set_default_verify_paths(ctx2), iVar16 == 0)) {
              ERR_print_errors(bio_err);
            }
            if (local_50 != (X509_VERIFY_PARAM *)0x0) {
              SSL_CTX_set1_param(ctx2,local_50);
            }
          }
          if (local_40 != (X509 *)0x0) {
            SSL_CTX_set_next_protos_advertised_cb(ctx,next_proto_cb + 1,&local_40);
          }
          if (!bVar5) {
            if (local_94 == (char *)0x0) {
              if (s_cert_file != (undefined *)0x0) {
                dh = (DH *)load_dh_param();
                goto LAB_000289b8;
              }
LAB_00028f18:
              BIO_printf(bio_s_out,"Using default temp DH parameters\n");
              dh = DH_new();
              if (dh != (DH *)0x0) {
                pBVar13 = BN_bin2bn(PTR_dh2048_p_00029074,0x100,(BIGNUM *)0x0);
                dh->p = pBVar13;
                pBVar13 = BN_bin2bn(PTR_dh2048_g_00029078,1,(BIGNUM *)0x0);
                dh->g = pBVar13;
                if ((dh->p != (BIGNUM *)0x0) && (pBVar13 != (BIGNUM *)0x0)) goto LAB_000289ce;
                DH_free(dh);
              }
LAB_00028f5e:
              iVar16 = 1;
              ERR_print_errors(bio_err);
              goto LAB_00027fee;
            }
            pBVar12 = BIO_new_file(local_94,"r");
            if (pBVar12 == (BIO *)0x0) goto LAB_00028f18;
            dh = PEM_read_bio_DHparams(pBVar12,(DH **)0x0,(undefined1 *)0x0,(void *)0x0);
            BIO_free(pBVar12);
LAB_000289b8:
            if (dh == (DH *)0x0) goto LAB_00028f18;
            BIO_printf(bio_s_out,"Setting temp DH parameters\n");
LAB_000289ce:
            BIO_ctrl(bio_s_out,0xb,0,(void *)0x0);
            SSL_CTX_ctrl(ctx,3,0,dh);
            if (ctx2 != (SSL_CTX *)0x0) {
              if ((local_94 == (char *)0x0) &&
                 (pDVar15 = (DH *)load_dh_param(s_cert_file2), pDVar15 != (DH *)0x0)) {
                BIO_printf(bio_s_out,"Setting temp DH parameters\n");
                BIO_ctrl(bio_s_out,0xb,0,(void *)0x0);
                DH_free(dh);
                dh = pDVar15;
              }
              SSL_CTX_ctrl(ctx2,3,0,dh);
            }
            DH_free(dh);
          }
          if (!bVar6) {
            if (local_90 == (char *)0x0) {
              BIO_printf(bio_s_out,"Using default temp ECDH parameters\n");
              key = EC_KEY_new_by_curve_name(0x19f);
              if (key == (EC_KEY *)0x0) {
                iVar16 = 1;
                BIO_printf(bio_err,"unable to create curve (nistp256)\n");
                goto LAB_00027fee;
              }
            }
            else {
              iVar16 = OBJ_sn2nid(local_90);
              if (iVar16 == 0) {
                BIO_printf(bio_err,"unknown curve name (%s)\n",local_90);
                iVar16 = 1;
                goto LAB_00027fee;
              }
              key = EC_KEY_new_by_curve_name(iVar16);
              if (key == (EC_KEY *)0x0) {
                BIO_printf(bio_err,"unable to create curve (%s)\n",local_90);
                iVar16 = 1;
                goto LAB_00027fee;
              }
              BIO_printf(bio_s_out,"Setting temp ECDH parameters\n");
            }
            BIO_ctrl(bio_s_out,0xb,0,(void *)0x0);
            SSL_CTX_ctrl(ctx,4,0,key);
            if (ctx2 != (SSL_CTX *)0x0) {
              SSL_CTX_ctrl(ctx2,4,0,key);
            }
            EC_KEY_free(key);
          }
          iVar16 = set_cert_key_stuff(ctx,local_c8,local_c4);
          if (((iVar16 == 0) ||
              ((ctx2 != (SSL_CTX *)0x0 &&
               (iVar16 = set_cert_key_stuff(ctx2,pXVar8,local_cc), iVar16 == 0)))) ||
             ((a != (X509 *)0x0 && (iVar16 = set_cert_key_stuff(ctx,a,pkey), iVar16 == 0)))) {
            iVar16 = 1;
            goto LAB_00027fee;
          }
          if ((!bVar7) && (SSL_CTX_set_tmp_rsa_callback(ctx,tmp_rsa_cb + 1), ctx2 != (SSL_CTX *)0x0)
             ) {
            SSL_CTX_set_tmp_rsa_callback(ctx2,tmp_rsa_cb + 1);
          }
          if (psk_key != (char *)0x0) {
            if (s_debug != 0) {
              BIO_printf(bio_s_out,"PSK key given or JPAKE in use, setting server callback\n");
            }
            SSL_CTX_set_psk_server_callback(ctx,psk_server_cb + 1);
          }
          iVar16 = SSL_CTX_use_psk_identity_hint(ctx,psk_identity_hint_21101);
          if (iVar16 == 0) {
            iVar16 = 1;
            BIO_printf(bio_err,"error setting PSK identity hint to context\n");
            ERR_print_errors(bio_err);
            goto LAB_00027fee;
          }
          if ((cipher != (char *)0x0) &&
             ((iVar16 = SSL_CTX_set_cipher_list(ctx,cipher), iVar16 == 0 ||
              ((ctx2 != (SSL_CTX *)0x0 &&
               (iVar16 = SSL_CTX_set_cipher_list(ctx2,cipher), iVar16 == 0)))))) {
            iVar16 = 1;
            BIO_printf(bio_err,"error setting cipher list\n");
            ERR_print_errors(bio_err);
            goto LAB_00027fee;
          }
          SSL_CTX_set_verify(ctx,s_server_verify,verify_callback + 1);
          SSL_CTX_set_session_id_context(ctx,PTR_s_server_session_id_context_00029070,4);
          SSL_CTX_set_cookie_generate_cb(ctx,generate_cookie_callback + 1);
          SSL_CTX_set_cookie_verify_cb(ctx,verify_cookie_callback + 1);
          if (ctx2 != (SSL_CTX *)0x0) {
            SSL_CTX_set_verify(ctx2,s_server_verify,verify_callback + 1);
            SSL_CTX_set_session_id_context(ctx2,PTR_s_server_session_id_context_00029070,4);
            local_30 = bio_s_out;
            SSL_CTX_callback_ctrl(ctx2,0x35,ssl_servername_cb + 1);
            SSL_CTX_ctrl(ctx2,0x36,0,&local_34);
            SSL_CTX_callback_ctrl(ctx,0x35,ssl_servername_cb + 1);
            SSL_CTX_ctrl(ctx,0x36,0,&local_34);
          }
          pSVar11 = ctx;
          if (pcVar21 == (char *)0x0) {
            if (local_a0 != (char *)0x0) {
              psVar14 = SSL_load_client_CA_file(local_a0);
              SSL_CTX_set_client_CA_list(pSVar11,psVar14);
              pSVar11 = ctx2;
              if (ctx2 != (SSL_CTX *)0x0) {
                psVar14 = SSL_load_client_CA_file(local_a0);
                SSL_CTX_set_client_CA_list(pSVar11,psVar14);
              }
            }
          }
          else {
            srp_callback_parm._4_4_ = SRP_VBASE_new(local_6c);
            srp_callback_parm._8_4_ = 0;
            srp_callback_parm._0_4_ = 0;
            iVar16 = SRP_VBASE_init(srp_callback_parm._4_4_,pcVar21);
            if (iVar16 != 0) {
              BIO_printf(bio_err,"Cannot initialize SRP verifier file \"%s\":ret=%d\n",pcVar21,
                         iVar16);
              goto LAB_00027fee;
            }
            SSL_CTX_set_verify(ctx,0,verify_callback + 1);
            SSL_CTX_set_srp_cb_arg(ctx,srp_callback_parm);
            SSL_CTX_set_srp_username_callback(ctx,0x27999);
          }
          BIO_printf(bio_s_out,"ACCEPT\n");
          BIO_ctrl(bio_s_out,0xb,0,(void *)0x0);
          if (www == 0) {
            do_server((int)local_60[0],local_a8,PTR_accept_socket_0002952c,0x2686d,local_b8);
          }
          else {
            do_server((int)local_60[0],local_a8,PTR_accept_socket_0002952c,0x270ed,local_b8);
          }
          iVar16 = 0;
          print_stats(bio_s_out,ctx);
          goto LAB_00027fee;
        }
        pcVar21 = "Error getting password\n";
      }
      else {
        pcVar21 = "Can\'t use -HTTP, -www or -WWW with DTLS\n";
        local_cc = (X509 *)0x0;
      }
      BIO_printf(bio_err,pcVar21);
      goto LAB_000285f8;
    }
    pcVar22 = *local_68;
    iVar9 = strcmp(pcVar22,"-port");
    if ((iVar9 == 0) || (iVar9 = strcmp(pcVar22,"-accept"), iVar9 == 0)) {
      local_64 = iVar16 + -1;
      if (local_64 == 0) goto LAB_00028130;
      local_68 = ppcVar20 + 1;
      iVar9 = extract_port(ppcVar20[1],local_60);
joined_r0x00027f56:
      ppcVar20 = local_68;
      iVar16 = local_64;
      if (iVar9 == 0) goto LAB_00028130;
    }
    else {
      iVar9 = strcmp(pcVar22,"-verify");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        s_server_verify = 5;
        if (local_64 != 0) {
          local_68 = ppcVar20 + 1;
          verify_depth = strtol(ppcVar20[1],(char **)0x0,10);
          BIO_printf(bio_err,"verify depth is %d\n",verify_depth);
          ppcVar20 = local_68;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-Verify");
      if (iVar9 == 0) {
        s_server_verify = 7;
        local_64 = local_64 + -1;
        if (0 < local_64) {
          local_68 = ppcVar20 + 1;
          verify_depth = strtol(ppcVar20[1],(char **)0x0,10);
          BIO_printf(bio_err,"verify depth is %d, must return a certificate\n",verify_depth);
          ppcVar20 = local_68;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-context");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_b8 = ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-cert");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          s_cert_file = ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-certform");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_68 = ppcVar20 + 1;
          local_a4 = str2fmt(ppcVar20[1]);
          ppcVar20 = local_68;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-key");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          s_key_file = ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-keyform");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_68 = ppcVar20 + 1;
          local_78 = str2fmt(ppcVar20[1]);
          ppcVar20 = local_68;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-pass");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_cc = (X509 *)ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-dhparam");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_94 = ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-named_curve");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_90 = ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-dcertform");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_68 = ppcVar20 + 1;
          local_8c = str2fmt(ppcVar20[1]);
          ppcVar20 = local_68;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-dcert");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          s_dcert_file = (X509 *)ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-dkeyform");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_68 = ppcVar20 + 1;
          local_c0 = str2fmt(ppcVar20[1]);
          ppcVar20 = local_68;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-dpass");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_c8 = (X509 *)ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-dkey");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          s_dkey_file = (X509 *)ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-nocert");
      if (iVar9 == 0) {
        local_b0 = (X509 *)0x1;
        goto LAB_00027f0a;
      }
      iVar9 = strcmp(pcVar22,"-CApath");
      if (iVar9 == 0) {
        local_64 = iVar16 + -1;
        if (local_64 != 0) {
          local_88 = ppcVar20[1];
          ppcVar20 = ppcVar20 + 1;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        goto LAB_00028130;
      }
      iVar9 = strcmp(pcVar22,"-no_cache");
      if (iVar9 == 0) {
        bVar4 = true;
        goto LAB_00027f0a;
      }
      iVar16 = args_verify(&local_68,&local_64,&local_4c,bio_err,&local_50);
      ppcVar20 = local_68;
      if (iVar16 != 0) {
        if (local_4c != 0) goto LAB_00028130;
        goto LAB_00027f16;
      }
      pcVar22 = *local_68;
      iVar16 = strcmp(pcVar22,"-verify_return_error");
      if (iVar16 == 0) {
        verify_return_error = 1;
        iVar16 = local_64;
      }
      else {
        iVar16 = strcmp(pcVar22,"-serverpref");
        if (iVar16 == 0) {
          local_b4 = local_b4 | 0x400000;
          iVar16 = local_64;
          goto LAB_00027f0a;
        }
        iVar16 = strcmp(pcVar22,"-legacy_renegotiation");
        if (iVar16 == 0) {
          local_b4 = local_b4 | 0x40000;
          iVar16 = local_64;
        }
        else {
          iVar16 = strcmp(pcVar22,"-cipher");
          if (iVar16 == 0) {
            local_64 = local_64 + -1;
            if (local_64 < 1) goto LAB_00028130;
            cipher = ppcVar20[1];
            ppcVar20 = ppcVar20 + 1;
            iVar16 = local_64;
          }
          else {
            iVar16 = strcmp(pcVar22,"-CAfile");
            if (iVar16 == 0) {
              local_64 = local_64 + -1;
              if (local_64 < 1) goto LAB_00028130;
              local_a0 = ppcVar20[1];
              ppcVar20 = ppcVar20 + 1;
              iVar16 = local_64;
            }
            else {
              iVar16 = strcmp(pcVar22,"-nbio");
              if (iVar16 == 0) {
                s_nbio = 1;
                iVar16 = local_64;
              }
              else {
                iVar16 = strcmp(pcVar22,"-nbio_test");
                if (iVar16 == 0) {
                  s_nbio = 1;
                  s_nbio_test = 1;
                  iVar16 = local_64;
                }
                else {
                  iVar16 = strcmp(pcVar22,"-debug");
                  if (iVar16 == 0) {
                    s_debug = 1;
                    iVar16 = local_64;
                  }
                  else {
                    iVar16 = strcmp(pcVar22,"-tlsextdebug");
                    if (iVar16 == 0) {
                      s_tlsextdebug = 1;
                      iVar16 = local_64;
                    }
                    else {
                      iVar16 = strcmp(pcVar22,"-status");
                      if (iVar16 == 0) {
                        s_tlsextstatus = 1;
                        iVar16 = local_64;
                      }
                      else {
                        iVar16 = strcmp(pcVar22,"-status_verbose");
                        if (iVar16 == 0) {
                          s_tlsextstatus = 1;
                          tlscstatp._24_4_ = 1;
                          iVar16 = local_64;
                        }
                        else {
                          iVar16 = strcmp(pcVar22,"-status_timeout");
                          if (iVar16 == 0) {
                            s_tlsextstatus = 1;
                            local_64 = local_64 + -1;
                            if (local_64 < 1) goto LAB_00028130;
                            local_68 = ppcVar20 + 1;
                            tlscstatp._16_4_ = strtol(ppcVar20[1],(char **)0x0,10);
                            ppcVar20 = local_68;
                            iVar16 = local_64;
                          }
                          else {
                            iVar16 = strcmp(pcVar22,"-status_url");
                            if (iVar16 == 0) {
                              s_tlsextstatus = 1;
                              local_64 = local_64 + -1;
                              if (local_64 < 1) goto LAB_00028130;
                              local_68 = ppcVar20 + 1;
                              iVar9 = OCSP_parse_url(ppcVar20[1],(char **)(DAT_0002812c + -3),
                                                     (char **)(DAT_0002812c + -1),
                                                     (char **)(DAT_0002812c + -2),DAT_0002812c);
                              ppcVar20 = local_68;
                              iVar16 = local_64;
                              if (iVar9 == 0) {
                                BIO_printf(bio_err,"Error parsing URL\n");
                                goto LAB_00028130;
                              }
                            }
                            else {
                              iVar16 = strcmp(pcVar22,"-msg");
                              if (iVar16 == 0) {
                                s_msg = 1;
                                iVar16 = local_64;
                              }
                              else {
                                iVar16 = strcmp(pcVar22,"-hack");
                                if (iVar16 == 0) {
                                  hack = 1;
                                  iVar16 = local_64;
                                }
                                else {
                                  iVar16 = strcmp(pcVar22,"-state");
                                  if (iVar16 == 0) {
                                    bVar3 = true;
                                    iVar16 = local_64;
                                  }
                                  else {
                                    iVar16 = strcmp(pcVar22,"-crlf");
                                    if (iVar16 == 0) {
                                      s_crlf = 1;
                                      iVar16 = local_64;
                                    }
                                    else {
                                      iVar16 = strcmp(pcVar22,"-quiet");
                                      if (iVar16 == 0) {
                                        s_quiet = 1;
                                        iVar16 = local_64;
                                      }
                                      else {
                                        iVar16 = strcmp(pcVar22,"-bugs");
                                        if (iVar16 == 0) {
                                          bVar2 = true;
                                          iVar16 = local_64;
                                        }
                                        else {
                                          iVar16 = strcmp(pcVar22,"-no_tmp_rsa");
                                          if (iVar16 == 0) {
                                            bVar7 = true;
                                            iVar16 = local_64;
                                          }
                                          else {
                                            iVar16 = strcmp(pcVar22,"-no_dhe");
                                            if (iVar16 == 0) {
                                              bVar5 = true;
                                              iVar16 = local_64;
                                            }
                                            else {
                                              iVar16 = strcmp(pcVar22,"-no_ecdhe");
                                              if (iVar16 == 0) {
                                                bVar6 = true;
                                                iVar16 = local_64;
                                              }
                                              else {
                                                iVar16 = strcmp(pcVar22,"-psk_hint");
                                                if (iVar16 == 0) {
                                                  local_64 = local_64 + -1;
                                                  if (local_64 < 1) goto LAB_00028130;
                                                  psk_identity_hint_21101 = ppcVar20[1];
                                                  ppcVar20 = ppcVar20 + 1;
                                                  iVar16 = local_64;
                                                }
                                                else {
                                                  sVar17 = strcmp(pcVar22,"-psk");
                                                  if (sVar17 == 0) {
                                                    iVar16 = local_64 + -1;
                                                    local_64 = iVar16;
                                                    if (iVar16 < 1) goto LAB_00028130;
                                                    pcVar22 = ppcVar20[1];
                                                    ppcVar20 = ppcVar20 + 1;
                                                    psk_key = pcVar22;
                                                    local_68 = ppcVar20;
                                                    sVar18 = strlen(pcVar22);
                                                    while (sVar17 != sVar18) {
                                                      ppuVar19 = __ctype_b_loc();
                                                      pbVar1 = (byte *)(pcVar22 + sVar17);
                                                      sVar17 = sVar17 + 1;
                                                      if (((*ppuVar19)[*pbVar1] & 0x1000) == 0) {
                                                        BIO_printf(bio_err,
                                                  "Not a hex number \'%s\'\n",pcVar22);
                                                  goto LAB_00028130;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar16 = strcmp(pcVar22,"-srpvfile");
                                                    if (iVar16 == 0) {
                                                      local_64 = local_64 + -1;
                                                      if (local_64 < 1) goto LAB_00028130;
                                                      pcVar21 = ppcVar20[1];
LAB_0002975e:
                                                      local_68 = ppcVar20 + 1;
                                                    }
                                                    else {
                                                      iVar16 = strcmp(pcVar22,"-srpuserseed");
                                                      if (iVar16 == 0) {
                                                        local_64 = local_64 + -1;
                                                        if (0 < local_64) {
                                                          local_6c = ppcVar20[1];
                                                          goto LAB_0002975e;
                                                        }
                                                        goto LAB_00028130;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-www");
                                                      if (iVar16 == 0) {
                                                        www = 1;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-WWW");
                                                      if (iVar16 == 0) {
                                                        www = 2;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-HTTP");
                                                      if (iVar16 == 0) {
                                                        www = 3;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-no_ssl2");
                                                      if (iVar16 == 0) {
                                                        local_b4 = local_b4 | 0x1000000;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-no_ssl3");
                                                      if (iVar16 == 0) {
                                                        local_b4 = local_b4 | 0x2000000;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-no_tls1");
                                                      if (iVar16 == 0) {
                                                        local_b4 = local_b4 | 0x4000000;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-no_tls1_1");
                                                      if (iVar16 == 0) {
                                                        local_b4 = local_b4 | 0x10000000;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-no_tls1_2");
                                                      if (iVar16 == 0) {
                                                        local_b4 = local_b4 | 0x8000000;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-no_comp");
                                                      if (iVar16 == 0) {
                                                        local_b4 = local_b4 | 0x20000;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-no_ticket");
                                                      if (iVar16 == 0) {
                                                        local_b4 = local_b4 | 0x4000;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-ssl3");
                                                      if (iVar16 == 0) {
                                                        local_bc = SSLv3_server_method();
                                                        ppcVar20 = local_68;
                                                        iVar16 = local_64;
                                                        goto LAB_00027f0a;
                                                      }
                                                      iVar16 = strcmp(pcVar22,"-tls1");
                                                      if (iVar16 != 0) {
                                                        iVar16 = strcmp(pcVar22,"-tls1_1");
                                                        if (iVar16 == 0) {
                                                          local_bc = TLSv1_1_server_method();
                                                          ppcVar20 = local_68;
                                                          iVar16 = local_64;
                                                        }
                                                        else {
                                                          iVar16 = strcmp(pcVar22,"-tls1_2");
                                                          if (iVar16 == 0) {
                                                            local_bc = TLSv1_2_server_method();
                                                            ppcVar20 = local_68;
                                                            iVar16 = local_64;
                                                          }
                                                          else {
                                                            iVar16 = strcmp(pcVar22,"-dtls1");
                                                            if (iVar16 == 0) {
                                                              local_bc = DTLSv1_server_method();
                                                              local_a8 = 2;
                                                              ppcVar20 = local_68;
                                                              iVar16 = local_64;
                                                            }
                                                            else {
                                                              iVar16 = strcmp(pcVar22,"-timeout");
                                                              if (iVar16 == 0) {
                                                                enable_timeouts = 1;
                                                                iVar16 = local_64;
                                                              }
                                                              else {
                                                                iVar16 = strcmp(pcVar22,"-mtu");
                                                                if (iVar16 == 0) {
                                                                  local_64 = local_64 + -1;
                                                                  if (0 < local_64) {
                                                                    local_68 = ppcVar20 + 1;
                                                                    socket_mtu = strtol(ppcVar20[1],
                                                                                        (char **)0x0
                                                                                        ,10);
                                                                    ppcVar20 = local_68;
                                                                    iVar16 = local_64;
                                                                    goto LAB_00027f0a;
                                                                  }
                                                                  goto LAB_00028130;
                                                                }
                                                                iVar16 = strcmp(pcVar22,"-chain");
                                                                if (iVar16 == 0) {
                                                                  cert_chain = 1;
                                                                  iVar16 = local_64;
                                                                }
                                                                else {
                                                                  iVar16 = strcmp(pcVar22,
                                                  "-id_prefix");
                                                  if (iVar16 == 0) {
                                                    local_64 = local_64 + -1;
                                                    if (local_64 < 1) goto LAB_00028130;
                                                    session_id_prefix = ppcVar20[1];
                                                    ppcVar20 = ppcVar20 + 1;
                                                    iVar16 = local_64;
                                                  }
                                                  else {
                                                    iVar16 = strcmp(pcVar22,"-engine");
                                                    if (iVar16 == 0) {
                                                      local_64 = local_64 + -1;
                                                      if (local_64 < 1) goto LAB_00028130;
                                                      engine_id = ppcVar20[1];
                                                      ppcVar20 = ppcVar20 + 1;
                                                      iVar16 = local_64;
                                                    }
                                                    else {
                                                      iVar16 = strcmp(pcVar22,"-rand");
                                                      if (iVar16 == 0) {
                                                        local_64 = local_64 + -1;
                                                        if (local_64 < 1) goto LAB_00028130;
                                                        local_9c = ppcVar20[1];
                                                        ppcVar20 = ppcVar20 + 1;
                                                        iVar16 = local_64;
                                                      }
                                                      else {
                                                        iVar16 = strcmp(pcVar22,"-servername");
                                                        if (iVar16 == 0) {
                                                          local_64 = local_64 + -1;
                                                          if (local_64 < 1) goto LAB_00028130;
                                                          local_34 = ppcVar20[1];
                                                          ppcVar20 = ppcVar20 + 1;
                                                          iVar16 = local_64;
                                                        }
                                                        else {
                                                          iVar16 = strcmp(pcVar22,
                                                  "-servername_fatal");
                                                  if (iVar16 == 0) {
                                                    local_2c = 2;
                                                    iVar16 = local_64;
                                                  }
                                                  else {
                                                    iVar16 = strcmp(pcVar22,"-cert2");
                                                    if (iVar16 == 0) {
                                                      local_64 = local_64 + -1;
                                                      if (local_64 < 1) goto LAB_00028130;
                                                      s_cert_file2 = ppcVar20[1];
                                                      ppcVar20 = ppcVar20 + 1;
                                                      iVar16 = local_64;
                                                    }
                                                    else {
                                                      iVar16 = strcmp(pcVar22,"-key2");
                                                      if (iVar16 == 0) {
                                                        local_64 = local_64 + -1;
                                                        if (local_64 < 1) goto LAB_00028130;
                                                        s_key_file2 = ppcVar20[1];
                                                        ppcVar20 = ppcVar20 + 1;
                                                        iVar16 = local_64;
                                                      }
                                                      else {
                                                        iVar16 = strcmp(pcVar22,"-nextprotoneg");
                                                        if (iVar16 == 0) {
                                                          local_64 = local_64 + -1;
                                                          if (local_64 < 1) goto LAB_00028130;
                                                          local_ac = (X509 *)ppcVar20[1];
                                                          ppcVar20 = ppcVar20 + 1;
                                                          iVar16 = local_64;
                                                        }
                                                        else {
                                                          iVar16 = strcmp(pcVar22,"-use_srtp");
                                                          if (iVar16 == 0) {
                                                            local_64 = local_64 + -1;
                                                            if (local_64 < 1) goto LAB_00028130;
                                                            srtp_profiles = ppcVar20[1];
                                                            ppcVar20 = ppcVar20 + 1;
                                                            iVar16 = local_64;
                                                          }
                                                          else {
                                                            iVar16 = strcmp(pcVar22,"-keymatexport")
                                                            ;
                                                            if (iVar16 != 0) {
                                                              iVar16 = strcmp(pcVar22,
                                                  "-keymatexportlen");
                                                  if (iVar16 == 0) {
                                                    local_64 = local_64 + -1;
                                                    if (0 < local_64) {
                                                      local_68 = ppcVar20 + 1;
                                                      keymatexportlen =
                                                           strtol(ppcVar20[1],(char **)0x0,10);
                                                      iVar9 = keymatexportlen;
                                                      goto joined_r0x00027f56;
                                                    }
                                                  }
                                                  else {
                                                    BIO_printf(bio_err,"unknown option %s\n",pcVar22
                                                              );
                                                  }
                                                  goto LAB_00028130;
                                                  }
                                                  local_64 = local_64 + -1;
                                                  if (local_64 < 1) goto LAB_00028130;
                                                  keymatexportlabel = ppcVar20[1];
                                                  ppcVar20 = ppcVar20 + 1;
                                                  iVar16 = local_64;
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
                                                  goto LAB_00027f0a;
                                                  }
                                                  }
                                                  local_bc = TLSv1_server_method();
                                                  ppcVar20 = local_68;
                                                  iVar16 = local_64;
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
LAB_00027f0a:
    local_64 = iVar16 + -1;
    local_68 = ppcVar20 + 1;
    goto LAB_00027f16;
  }
  iVar16 = 1;
  pkey = pXVar8;
  a = pXVar8;
  local_cc = pXVar8;
  local_c8 = pXVar8;
  local_c4 = pXVar8;
  goto LAB_00027fee;
LAB_00028130:
  BIO_printf(bio_err,"usage: s_server [args ...]\n");
  BIO_printf(bio_err,"\n");
  local_cc = (X509 *)0x0;
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
LAB_000285f8:
  iVar16 = 1;
  pXVar8 = local_cc;
  pkey = local_cc;
  a = local_cc;
  local_c8 = local_cc;
  local_c4 = local_cc;
LAB_00027fee:
  if (ctx != (SSL_CTX *)0x0) {
    SSL_CTX_free(ctx);
  }
  if (local_c8 != (X509 *)0x0) {
    X509_free(local_c8);
  }
  if (a != (X509 *)0x0) {
    X509_free(a);
  }
  if (local_c4 != (X509 *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)local_c4);
  }
  if (pkey != (X509 *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)pkey);
  }
  if (local_48 != (void *)0x0) {
    CRYPTO_free(local_48);
  }
  if (local_44 != (void *)0x0) {
    CRYPTO_free(local_44);
  }
  if (local_50 != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(local_50);
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
  if (pXVar8 != (X509 *)0x0) {
    X509_free(pXVar8);
  }
  if (local_cc != (X509 *)0x0) {
    EVP_PKEY_free((EVP_PKEY *)local_cc);
  }
  if (bio_s_out != (BIO *)0x0) {
    BIO_free(bio_s_out);
    bio_s_out = (BIO *)0x0;
  }
  return iVar16;
}

