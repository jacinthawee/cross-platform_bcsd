
int s_client_main(int param_1,byte **param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  int iVar13;
  long lVar14;
  undefined4 uVar15;
  ENGINE *e;
  byte **ppbVar16;
  SSL_CTX *ctx;
  SSL *to;
  SSL_SESSION *bp;
  SSL_SESSION *pSVar17;
  BIO *pBVar18;
  BIO_METHOD *pBVar19;
  BIO *pBVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  long lVar24;
  int *piVar25;
  ushort **ppuVar26;
  byte **ppbVar27;
  byte **ppbVar28;
  byte **ppbVar29;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  byte **extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  int extraout_ECX_07;
  int extraout_ECX_08;
  uint uVar30;
  undefined4 extraout_ECX_09;
  byte **extraout_ECX_10;
  byte **extraout_ECX_11;
  byte **extraout_ECX_12;
  byte **extraout_ECX_13;
  undefined4 extraout_ECX_14;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  BIO *extraout_EDX_02;
  undefined4 extraout_EDX_03;
  byte **extraout_EDX_04;
  byte **extraout_EDX_05;
  byte **extraout_EDX_06;
  byte **extraout_EDX_07;
  byte **extraout_EDX_08;
  byte **extraout_EDX_09;
  X509 *a;
  byte **unaff_EBP;
  SSL_SESSION *ctx_00;
  bool bVar31;
  EVP_PKEY *pkey;
  byte **ppbVar32;
  int iVar33;
  __fd_mask *p_Var34;
  byte *pbVar35;
  byte **ppbVar36;
  int in_GS_OFFSET;
  bool bVar38;
  bool bVar39;
  byte bVar40;
  char *pcVar41;
  byte **ppbVar42;
  byte **__s1;
  char *local_210;
  char *local_20c;
  byte *local_208;
  SSL_METHOD *local_204;
  int local_1fc;
  byte *local_1f8;
  byte *local_1f4;
  byte *local_1f0;
  int local_1ec;
  uint local_1e8;
  SSL_SESSION *local_1e4;
  undefined4 local_1e0;
  byte *local_1dc;
  byte *local_1d8;
  byte *local_1d4;
  byte *local_1d0;
  byte *local_1cc;
  timeval *local_1c8;
  SSL_SESSION *local_1c4;
  byte *local_1c0;
  int local_1bc;
  byte *local_1b8;
  byte *local_1b4;
  int local_1b0;
  long local_1ac;
  byte *local_1a4;
  undefined4 local_194;
  byte **local_180 [2];
  short local_176;
  int local_174;
  byte *local_170;
  void *local_16c;
  SSL_CTX *local_168;
  int local_164;
  socklen_t local_160;
  undefined4 local_15c;
  timeval local_158;
  BIO *local_150;
  undefined4 local_14c;
  void *local_148;
  byte *local_144;
  int local_140;
  int local_13c;
  int local_138;
  byte **local_134;
  sockaddr local_130;
  fd_set local_120;
  fd_set local_a0;
  int local_20;
  byte **ppbVar37;
  
  bVar40 = 0;
  local_170 = (byte *)0x81f54a1;
  local_16c = (void *)0x0;
  local_168 = (SSL_CTX *)0x0;
  local_164 = 0;
  local_150 = (BIO *)0x0;
  local_180[0] = param_2;
  local_14c = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_160 = 0x10;
  local_148 = (void *)0x0;
  local_176 = 0x1151;
  local_144 = (byte *)0x0;
  local_140 = 0;
  local_13c = 0;
  local_138 = 0;
  local_134 = (byte **)0x400;
  local_204 = SSLv23_client_method();
  signal(0xd,(__sighandler_t)0x1);
  c_Pause = 0;
  c_quiet = (byte **)0x0;
  c_ign_eof = 0;
  c_debug = 0;
  c_msg = 0;
  c_showcerts = 0;
  if (bio_err == (BIO *)0x0) {
    bio_err = BIO_new_fp(stderr,0);
  }
  iVar13 = load_config(bio_err,0);
  if (iVar13 == 0) {
    ctx_00 = (SSL_SESSION *)0x0;
    pkey = (EVP_PKEY *)0x0;
    a = (X509 *)0x0;
    local_20c = (char *)0x0;
    local_210 = (char *)0x0;
    local_208 = (byte *)0x0;
  }
  else {
    local_208 = (byte *)CRYPTO_malloc(0x2000,"s_client.c",0x2c4);
    if ((local_208 == (byte *)0x0) ||
       (local_210 = (char *)CRYPTO_malloc(0x2000,"s_client.c",0x2c5), local_210 == (char *)0x0)) {
      local_210 = (char *)0x0;
    }
    else {
      ppbVar42 = (byte **)0x2c6;
      pcVar41 = "s_client.c";
      local_20c = (char *)CRYPTO_malloc(0x2000,"s_client.c",0x2c6);
      if (local_20c != (char *)0x0) {
        verify_depth = (byte **)0x0;
        verify_error = 0;
        c_nbio = 0;
        local_180[0] = local_180[0] + 1;
        bVar31 = false;
        param_1 = param_1 + -1;
        local_1c0 = (byte *)0x0;
        local_1ac = 0;
        bVar12 = false;
        bVar5 = false;
        local_1f0 = (byte *)0x0;
        local_1e4 = (SSL_SESSION *)0x0;
        local_1f4 = (byte *)0x0;
        local_1c4 = (SSL_SESSION *)0x0;
        local_1d0 = (byte *)0x0;
        local_1d4 = (byte *)0x0;
        local_1cc = (byte *)0x0;
        local_194 = 1;
        bVar7 = false;
        local_1ec = 0;
        bVar6 = false;
        bVar11 = false;
        bVar3 = false;
        local_1fc = 0;
        local_1b0 = 0;
        local_1a4 = (byte *)0x0;
        local_1b4 = (byte *)0x0;
        local_1b8 = (byte *)0x0;
        local_1d8 = (byte *)0x0;
        local_1c8 = (timeval *)0x3;
        local_1e0 = 3;
        local_1dc = (byte *)0x0;
        local_1f8 = (byte *)0x0;
        bVar4 = false;
        local_1bc = 0;
        local_1e8 = 0;
LAB_0806e353:
        bVar38 = false;
        bVar39 = param_1 == 0;
        if (param_1 < 1) {
          SSL_library_init();
          SSL_load_error_strings();
          next_proto._8_4_ = 0xffffffff;
          if (local_1f4 == (byte *)0x0) {
            next_proto._0_4_ = (void *)0x0;
          }
          else {
            next_proto._0_4_ = (void *)next_protos_parse(0x82fde7c,local_1f4);
            if (next_proto._0_4_ == (void *)0x0) {
              pcVar41 = "Error parsing -nextprotoneg argument\n";
              goto LAB_0806e93e;
            }
          }
          uVar15 = setup_engine(bio_err,local_1d4,1);
          if (local_1d0 == (byte *)0x0) {
            e = (ENGINE *)0x0;
          }
          else {
            e = ENGINE_by_id((char *)local_1d0);
            if (e == (ENGINE *)0x0) {
              pcVar41 = "Error getting client auth engine\n";
              goto LAB_0806e93e;
            }
          }
          iVar13 = app_passwd(bio_err,local_1d8,0,&local_16c,0);
          if (iVar13 == 0) {
            pcVar41 = "Error getting password\n";
            goto LAB_0806e93e;
          }
          if (local_1dc == (byte *)0x0) {
            if (local_1f8 != (byte *)0x0) {
              pkey = (EVP_PKEY *)
                     load_key(bio_err,local_1f8,local_1c8,0,local_16c,uVar15,
                              "client certificate private key file",local_1f8);
              if (pkey != (EVP_PKEY *)0x0) goto LAB_0806eb6f;
              goto LAB_0806faaa;
            }
            pkey = (EVP_PKEY *)0x0;
            a = (X509 *)0x0;
          }
          else {
            pkey = (EVP_PKEY *)
                   load_key(bio_err,local_1dc,local_1c8,0,local_16c,uVar15,
                            "client certificate private key file");
            if (pkey == (EVP_PKEY *)0x0) {
LAB_0806faaa:
              ctx_00 = (SSL_SESSION *)0x0;
              pkey = (EVP_PKEY *)0x0;
              a = (X509 *)0x0;
              ERR_print_errors(bio_err);
              goto LAB_0806e038;
            }
            if (local_1f8 == (byte *)0x0) {
              a = (X509 *)0x0;
            }
            else {
LAB_0806eb6f:
              a = (X509 *)load_cert(bio_err,local_1f8,local_1e0,0,uVar15,"client certificate file");
              if (a == (X509 *)0x0) {
                ctx_00 = (SSL_SESSION *)0x0;
                ERR_print_errors(bio_err);
                goto LAB_0806e038;
              }
            }
          }
          ppbVar42 = (byte **)0x1;
          pcVar41 = (char *)bio_err;
          iVar13 = app_RAND_load_file(0,bio_err,1);
          if (iVar13 == 0) {
            if (local_1cc == (byte *)0x0) {
              iVar13 = RAND_status();
              if (iVar13 == 0) {
                pcVar41 = "warning, not much extra random data, consider using the -rand option\n";
                BIO_printf(bio_err,
                           "warning, not much extra random data, consider using the -rand option\n",
                           unaff_EBP,unaff_EBP);
                ppbVar42 = unaff_EBP;
              }
            }
            else {
LAB_0806ebc3:
              ppbVar42 = (byte **)app_RAND_load_files(local_1cc);
              pcVar41 = "%ld semi-random bytes loaded\n";
              BIO_printf(bio_err,"%ld semi-random bytes loaded\n",ppbVar42);
            }
          }
          else if (local_1cc != (byte *)0x0) goto LAB_0806ebc3;
          if (bio_c_out == (BIO *)0x0) {
            if (((c_quiet == (byte **)0x0) || (c_debug != 0)) || (c_msg != 0)) {
              pcVar41 = (char *)0x0;
              ppbVar42 = c_quiet;
              bio_c_out = BIO_new_fp(stdout,0);
            }
            else {
              pBVar19 = BIO_s_null();
              bio_c_out = BIO_new(pBVar19);
            }
          }
          iVar13 = app_passwd(bio_err,local_1c0,0,&local_148,0,pcVar41,ppbVar42);
          if (iVar13 == 0) {
            ctx_00 = (SSL_SESSION *)0x0;
            BIO_printf(bio_err,"Error getting password\n");
            goto LAB_0806e038;
          }
          ctx_00 = (SSL_SESSION *)SSL_CTX_new(local_204);
          if (ctx_00 == (SSL_SESSION *)0x0) {
            ERR_print_errors(bio_err);
            goto LAB_0806e038;
          }
          ctx = local_168;
          if (local_168 != (SSL_CTX *)0x0) {
            ctx = (SSL_CTX *)SSL_CTX_set1_param((SSL_CTX *)ctx_00,(X509_VERIFY_PARAM *)local_168);
          }
          if (e != (ENGINE *)0x0) {
            iVar13 = SSL_CTX_set_client_cert_engine(ctx,(ENGINE *)ctx_00);
            if (iVar13 == 0) {
              BIO_puts(bio_err,"Error setting client auth engine\n");
              ERR_print_errors(bio_err);
              ENGINE_free(e);
              goto LAB_0806e038;
            }
            ENGINE_free(e);
          }
          if (psk_key != (byte **)0x0) {
            if (c_debug != 0) {
              BIO_printf(bio_c_out,"PSK key given or JPAKE in use, setting client callback\n",
                         c_debug,c_debug);
            }
            SSL_CTX_set_psk_client_callback((SSL_CTX *)ctx_00,psk_client_cb);
          }
          if (srtp_profiles != (byte *)0x0) {
            SSL_CTX_set_tlsext_use_srtp((SSL_CTX *)ctx_00,(char *)srtp_profiles);
          }
          if (bVar3) {
            SSL_CTX_ctrl((SSL_CTX *)ctx_00,0x20,local_1e8 | 0x80000bff,(void *)0x0);
          }
          else {
            SSL_CTX_ctrl((SSL_CTX *)ctx_00,0x20,local_1e8,(void *)0x0);
          }
          if (local_1bc != 0) {
            SSL_CTX_ctrl((SSL_CTX *)ctx_00,0x4d,local_1bc,(void *)0x0);
          }
          if (next_proto._0_4_ != (void *)0x0) {
            SSL_CTX_set_next_proto_select_cb((SSL_CTX *)ctx_00,next_proto_cb,next_proto);
          }
          if (bVar4) {
            SSL_CTX_set_info_callback((SSL_CTX *)ctx_00,apps_ssl_info_callback);
          }
          if ((local_1a4 != (byte *)0x0) &&
             (iVar13 = SSL_CTX_set_cipher_list((SSL_CTX *)ctx_00,(char *)local_1a4), iVar13 == 0)) {
            BIO_printf(bio_err,"error setting cipher list\n",0,0);
            ERR_print_errors(bio_err);
            goto LAB_0806e038;
          }
          SSL_CTX_set_verify((SSL_CTX *)ctx_00,local_1fc,verify_callback);
          iVar13 = set_cert_key_stuff(ctx_00,a,pkey);
          if (iVar13 == 0) goto LAB_0806e038;
          if (((local_1b4 != (byte *)0x0) || (local_1b8 != (byte *)0x0)) &&
             (iVar13 = SSL_CTX_load_verify_locations
                                 ((SSL_CTX *)ctx_00,(char *)local_1b4,(char *)local_1b8),
             iVar13 == 0)) {
            ERR_print_errors(bio_err);
          }
          iVar13 = SSL_CTX_set_default_verify_paths((SSL_CTX *)ctx_00);
          uVar15 = extraout_EDX;
          if (iVar13 == 0) {
            ERR_print_errors(bio_err);
            uVar15 = extraout_EDX_01;
          }
          if (local_1c4 != (SSL_SESSION *)0x0) {
            local_150 = bio_err;
            SSL_CTX_callback_ctrl((SSL_CTX *)ctx_00,0x35,ssl_servername_cb);
            SSL_CTX_ctrl((SSL_CTX *)ctx_00,0x36,0,&local_150);
            uVar15 = extraout_EDX_00;
          }
          pSVar17 = local_1c4;
          if (local_144 != (byte *)0x0) {
            if ((!bVar31) &&
               (iVar13 = SSL_CTX_set_srp_username(ctx_00,local_144,uVar15,uVar15), iVar13 == 0)) {
              BIO_printf(bio_err,"Unable to set SRP username\n",local_1c4,local_1c4);
              goto LAB_0806e038;
            }
            local_140 = c_msg;
            local_13c = c_debug;
            pSVar17 = ctx_00;
            SSL_CTX_set_srp_cb_arg(ctx_00,&local_148);
            SSL_CTX_set_srp_client_pwd_callback(ctx_00,ssl_give_srp_client_pwd_cb);
            SSL_CTX_set_srp_strength(ctx_00,local_134);
            if (((c_msg != 0) || (c_debug != 0)) || (local_138 == 0)) {
              SSL_CTX_set_srp_verify_param_callback(ctx_00,ssl_srp_verify_param_cb,c_msg,c_msg);
            }
          }
          to = SSL_new((SSL_CTX *)ctx_00);
          if (local_1e4 == (SSL_SESSION *)0x0) {
LAB_0806f045:
            if (bVar5) {
              SSL_ctrl(to,0x21,0x80,(void *)0x0);
            }
            if ((local_1c4 == (SSL_SESSION *)0x0) ||
               (lVar14 = SSL_ctrl(to,0x37,0,local_1c4), lVar14 != 0)) {
              bVar3 = true;
              bVar4 = true;
              goto LAB_0806f0a9;
            }
            pcVar41 = "Unable to set TLS servername extension.\n";
            local_1e4 = pSVar17;
            bp = pSVar17;
          }
          else {
            bp = (SSL_SESSION *)BIO_new_file((char *)local_1e4,"r");
            if (bp != (SSL_SESSION *)0x0) {
              pSVar17 = PEM_read_bio_SSL_SESSION
                                  ((BIO *)bp,(SSL_SESSION **)0x0,(undefined1 *)0x0,(void *)0x0);
              bp = (SSL_SESSION *)BIO_free((BIO *)bp);
              if (pSVar17 != (SSL_SESSION *)0x0) {
                SSL_set_session(to,pSVar17);
                SSL_SESSION_free(pSVar17);
                goto LAB_0806f045;
              }
            }
            pcVar41 = "Can\'t open session file %s\n";
          }
          iVar33 = 1;
          BIO_printf(bio_err,pcVar41,local_1e4,bp);
          ERR_print_errors(bio_err);
          goto LAB_0806f496;
        }
        iVar13 = 6;
        unaff_EBP = (byte **)*local_180[0];
        ppbVar29 = unaff_EBP;
        pbVar35 = (byte *)"-host";
        do {
          if (iVar13 == 0) break;
          iVar13 = iVar13 + -1;
          bVar38 = *(byte *)ppbVar29 < *pbVar35;
          bVar39 = *(byte *)ppbVar29 == *pbVar35;
          ppbVar29 = (byte **)((int)ppbVar29 + (uint)bVar40 * -2 + 1);
          pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
        } while (bVar39);
        bVar38 = (!bVar38 && !bVar39) == bVar38;
        if (bVar38) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0806e480;
          local_170 = local_180[0][1];
          iVar13 = param_1;
          ppbVar29 = local_180[0] + 1;
        }
        else {
          iVar13 = 6;
          ppbVar29 = unaff_EBP;
          pbVar35 = (byte *)"-port";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar38 = *(byte *)ppbVar29 == *pbVar35;
            ppbVar29 = (byte **)((int)ppbVar29 + (uint)bVar40 * -2 + 1);
            pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
          } while (bVar38);
          if (bVar38) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              ppbVar42 = (byte **)0xa;
              pcVar41 = (char *)0x0;
              ppbVar29 = local_180[0] + 1;
              local_180[0] = local_180[0] + 1;
              lVar14 = strtol((char *)*ppbVar29,(char **)0x0,10);
              local_176 = (short)lVar14;
              iVar13 = param_1;
              ppbVar29 = local_180[0];
              if (local_176 != 0) goto LAB_0806e33f;
            }
            goto LAB_0806e480;
          }
          iVar13 = 9;
          ppbVar29 = unaff_EBP;
          pbVar35 = (byte *)"-connect";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar38 = *(byte *)ppbVar29 == *pbVar35;
            ppbVar29 = (byte **)((int)ppbVar29 + (uint)bVar40 * -2 + 1);
            pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
          } while (bVar38);
          if (bVar38) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              ppbVar42 = (byte **)0x0;
              pcVar41 = (char *)&local_170;
              ppbVar29 = local_180[0] + 1;
              local_180[0] = local_180[0] + 1;
              iVar33 = extract_host_port(*ppbVar29,pcVar41,0,&local_176);
              iVar13 = param_1;
              ppbVar29 = local_180[0];
              if (iVar33 != 0) goto LAB_0806e33f;
            }
            goto LAB_0806e480;
          }
          iVar13 = 8;
          ppbVar29 = unaff_EBP;
          pbVar35 = (byte *)"-verify";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar38 = *(byte *)ppbVar29 == *pbVar35;
            ppbVar29 = (byte **)((int)ppbVar29 + (uint)bVar40 * -2 + 1);
            pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
          } while (bVar38);
          if (bVar38) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              ppbVar42 = local_180[0] + 1;
              local_180[0] = local_180[0] + 1;
              verify_depth = (byte **)strtol((char *)*ppbVar42,(char **)0x0,10);
              pcVar41 = "verify depth is %d\n";
              ppbVar42 = verify_depth;
              BIO_printf(bio_err,"verify depth is %d\n");
              local_1fc = 1;
              iVar13 = param_1;
              ppbVar29 = local_180[0];
              goto LAB_0806e33f;
            }
            goto LAB_0806e480;
          }
          iVar13 = 6;
          ppbVar29 = unaff_EBP;
          pbVar35 = (byte *)0x82072c9;
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar38 = *(byte *)ppbVar29 == *pbVar35;
            ppbVar29 = (byte **)((int)ppbVar29 + (uint)bVar40 * -2 + 1);
            pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
          } while (bVar38);
          if (bVar38) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              local_1f8 = local_180[0][1];
              iVar13 = param_1;
              ppbVar29 = local_180[0] + 1;
              goto LAB_0806e33f;
            }
            goto LAB_0806e480;
          }
          iVar13 = 10;
          ppbVar29 = unaff_EBP;
          pbVar35 = (byte *)"-sess_out";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar38 = *(byte *)ppbVar29 == *pbVar35;
            ppbVar29 = (byte **)((int)ppbVar29 + (uint)bVar40 * -2 + 1);
            pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
          } while (bVar38);
          if (bVar38) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              local_1f0 = local_180[0][1];
              iVar13 = param_1;
              ppbVar29 = local_180[0] + 1;
              goto LAB_0806e33f;
            }
            goto LAB_0806e480;
          }
          iVar13 = 9;
          ppbVar29 = unaff_EBP;
          pbVar35 = (byte *)"-sess_in";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar38 = *(byte *)ppbVar29 == *pbVar35;
            ppbVar29 = (byte **)((int)ppbVar29 + (uint)bVar40 * -2 + 1);
            pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
          } while (bVar38);
          if (bVar38) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              local_1e4 = (SSL_SESSION *)local_180[0][1];
              iVar13 = param_1;
              ppbVar29 = local_180[0] + 1;
              goto LAB_0806e33f;
            }
            goto LAB_0806e480;
          }
          iVar13 = 10;
          ppbVar29 = unaff_EBP;
          pbVar35 = (byte *)"-certform";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar38 = *(byte *)ppbVar29 == *pbVar35;
            ppbVar29 = (byte **)((int)ppbVar29 + (uint)bVar40 * -2 + 1);
            pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
          } while (bVar38);
          if (bVar38) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              ppbVar29 = local_180[0] + 1;
              local_180[0] = local_180[0] + 1;
              local_1e0 = str2fmt(*ppbVar29);
              iVar13 = param_1;
              ppbVar29 = local_180[0];
              goto LAB_0806e33f;
            }
            goto LAB_0806e480;
          }
          ppbVar16 = (byte **)args_verify(local_180,&param_1,&local_164,bio_err,&local_168,pcVar41,
                                          ppbVar42);
          ppbVar28 = local_180[0];
          bVar38 = ppbVar16 == (byte **)0x0;
          if (!bVar38) {
            if (local_164 != 0) goto LAB_0806e480;
            goto LAB_0806e353;
          }
          iVar13 = 0x15;
          __s1 = (byte **)*local_180[0];
          ppbVar29 = __s1;
          pbVar35 = (byte *)"-verify_return_error";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar38 = *(byte *)ppbVar29 == *pbVar35;
            ppbVar29 = (byte **)((int)ppbVar29 + (uint)bVar40 * -2 + 1);
            pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
          } while (bVar38);
          iVar13 = param_1;
          ppbVar29 = ppbVar28;
          if (bVar38) {
            verify_return_error = 1;
          }
          else {
            iVar33 = 8;
            ppbVar27 = __s1;
            pbVar35 = (byte *)"-prexit";
            do {
              if (iVar33 == 0) break;
              iVar33 = iVar33 + -1;
              bVar38 = *(byte *)ppbVar27 == *pbVar35;
              ppbVar27 = (byte **)((int)ppbVar27 + (uint)bVar40 * -2 + 1);
              pbVar35 = pbVar35 + (uint)bVar40 * -2 + 1;
            } while (bVar38);
            if (bVar38) {
              bVar7 = true;
              goto LAB_0806e33f;
            }
            iVar33 = 6;
            ppbVar27 = __s1;
            ppbVar37 = (byte **)&DAT_081f509f;
            do {
              ppbVar32 = ppbVar27;
              ppbVar36 = ppbVar37;
              if (iVar33 == 0) break;
              iVar33 = iVar33 + -1;
              ppbVar36 = (byte **)((int)ppbVar37 + (uint)bVar40 * -2 + 1);
              ppbVar32 = (byte **)((int)ppbVar27 + (uint)bVar40 * -2 + 1);
              bVar38 = *(byte *)ppbVar27 == *(byte *)ppbVar37;
              ppbVar27 = ppbVar32;
              ppbVar37 = ppbVar36;
            } while (bVar38);
            if (bVar38) {
              bVar11 = true;
            }
            else {
              pcVar41 = "-quiet";
              iVar13 = strcmp((char *)__s1,"-quiet");
              if (iVar13 == 0) {
                c_quiet = (byte **)0x1;
                c_ign_eof = 1;
                iVar13 = param_1;
                ppbVar42 = ppbVar16;
              }
              else {
                pcVar41 = "-ign_eof";
                ppbVar42 = ppbVar36;
                iVar13 = strcmp((char *)__s1,"-ign_eof");
                if (iVar13 == 0) {
                  c_ign_eof = 1;
                  iVar13 = param_1;
                }
                else {
                  pcVar41 = "-no_ign_eof";
                  ppbVar42 = ppbVar32;
                  iVar13 = strcmp((char *)__s1,"-no_ign_eof");
                  if (iVar13 == 0) {
                    c_ign_eof = 0;
                    iVar13 = param_1;
                  }
                  else {
                    pcVar41 = "-pause";
                    ppbVar42 = extraout_ECX_04;
                    iVar13 = strcmp((char *)__s1,"-pause");
                    if (iVar13 == 0) {
                      c_Pause = 1;
                      iVar13 = param_1;
                    }
                    else {
                      pcVar41 = &DAT_081ece03;
                      ppbVar42 = extraout_EDX_04;
                      ppbVar16 = (byte **)strcmp((char *)__s1,"-debug");
                      if (ppbVar16 == (byte **)0x0) {
                        c_debug = 1;
                        iVar13 = param_1;
                      }
                      else {
                        pcVar41 = "-tlsextdebug";
                        ppbVar42 = (byte **)strcmp((char *)__s1,"-tlsextdebug");
                        if (ppbVar42 == (byte **)0x0) {
                          c_tlsextdebug = 1;
                          iVar13 = param_1;
                          ppbVar42 = ppbVar16;
                        }
                        else {
                          pcVar41 = "-status";
                          ppbVar16 = (byte **)strcmp((char *)__s1,"-status");
                          if (ppbVar16 == (byte **)0x0) {
                            c_status_req = 1;
                            iVar13 = param_1;
                          }
                          else {
                            pcVar41 = &DAT_081f508d;
                            ppbVar42 = (byte **)strcmp((char *)__s1,"-msg");
                            if (ppbVar42 == (byte **)0x0) {
                              c_msg = 1;
                              iVar13 = param_1;
                              ppbVar42 = ppbVar16;
                            }
                            else {
                              pcVar41 = "-showcerts";
                              ppbVar16 = (byte **)strcmp((char *)__s1,"-showcerts");
                              if (ppbVar16 == (byte **)0x0) {
                                c_showcerts = 1;
                                iVar13 = param_1;
                              }
                              else {
                                pcVar41 = "-nbio_test";
                                ppbVar42 = (byte **)strcmp((char *)__s1,"-nbio_test");
                                if (ppbVar42 == (byte **)0x0) {
                                  bVar6 = true;
                                  iVar13 = param_1;
                                  ppbVar42 = ppbVar16;
                                }
                                else {
                                  pcVar41 = "-state";
                                  iVar13 = strcmp((char *)__s1,"-state");
                                  if (iVar13 == 0) {
                                    bVar4 = true;
                                    iVar13 = param_1;
                                  }
                                  else {
                                    pcVar41 = "-psk_identity";
                                    ppbVar42 = ppbVar36;
                                    iVar13 = strcmp((char *)__s1,"-psk_identity");
                                    if (iVar13 == 0) {
                                      param_1 = param_1 + -1;
                                      if (param_1 < 1) goto LAB_0806e480;
                                      psk_identity = ppbVar28[1];
                                      iVar13 = param_1;
                                      ppbVar29 = ppbVar28 + 1;
                                    }
                                    else {
                                      pcVar41 = &DAT_081f50d3;
                                      ppbVar42 = ppbVar32;
                                      iVar13 = strcmp((char *)__s1,"-psk");
                                      if (iVar13 == 0) {
                                        iVar13 = param_1 + -1;
                                        param_1 = iVar13;
                                        if (iVar13 < 1) goto LAB_0806e480;
                                        ppbVar29 = ppbVar28 + 1;
                                        ppbVar28 = (byte **)ppbVar28[1];
                                        uVar30 = 0xffffffff;
                                        ppbVar16 = ppbVar28;
                                        do {
                                          if (uVar30 == 0) break;
                                          uVar30 = uVar30 - 1;
                                          bVar1 = *(byte *)ppbVar16;
                                          ppbVar16 = (byte **)((int)ppbVar16 + (uint)bVar40 * -2 + 1
                                                              );
                                        } while (bVar1 != 0);
                                        psk_key = ppbVar28;
                                        local_180[0] = ppbVar29;
                                        for (iVar33 = 0; iVar33 != ~uVar30 - 1; iVar33 = iVar33 + 1)
                                        {
                                          ppuVar26 = __ctype_b_loc();
                                          if ((*(byte *)((int)*ppuVar26 +
                                                        (uint)*(byte *)((int)ppbVar28 + iVar33) * 2
                                                        + 1) & 0x10) == 0) {
                                            BIO_printf(bio_err,"Not a hex number \'%s\'\n",ppbVar28,
                                                       extraout_ECX_09);
                                            ppbVar42 = ppbVar28;
                                            goto LAB_0806e480;
                                          }
                                        }
                                      }
                                      else {
                                        pcVar41 = "-srpuser";
                                        ppbVar42 = extraout_EDX_05;
                                        ppbVar16 = (byte **)strcmp((char *)__s1,"-srpuser");
                                        if (ppbVar16 == (byte **)0x0) {
                                          param_1 = param_1 + -1;
                                          if (param_1 < 1) goto LAB_0806e480;
                                          local_180[0] = ppbVar28 + 1;
                                          local_144 = ppbVar28[1];
LAB_08070834:
                                          local_204 = TLSv1_client_method();
                                          iVar13 = param_1;
                                          ppbVar29 = local_180[0];
                                        }
                                        else {
                                          pcVar41 = "-srppass";
                                          ppbVar27 = (byte **)strcmp((char *)__s1,"-srppass");
                                          if (ppbVar27 == (byte **)0x0) {
                                            param_1 = param_1 + -1;
                                            ppbVar42 = ppbVar16;
                                            if (param_1 < 1) goto LAB_0806e480;
                                            local_180[0] = ppbVar28 + 1;
                                            local_1c0 = ppbVar28[1];
                                            local_204 = TLSv1_client_method();
                                            iVar13 = param_1;
                                            ppbVar29 = local_180[0];
                                            ppbVar42 = ppbVar16;
                                          }
                                          else {
                                            ppbVar42 = (byte **)strcmp((char *)__s1,"-srp_strength")
                                            ;
                                            if (ppbVar42 == (byte **)0x0) {
                                              param_1 = param_1 + -1;
                                              ppbVar42 = ppbVar27;
                                              if (param_1 < 1) goto LAB_0806e480;
                                              ppbVar29 = ppbVar28 + 1;
                                              local_180[0] = ppbVar29;
                                              ppbVar42 = (byte **)strtol((char *)ppbVar28[1],
                                                                         (char **)0x0,10);
                                              pcVar41 = "SRP minimal length for N is %d\n";
                                              local_134 = ppbVar42;
                                              BIO_printf(bio_err,"SRP minimal length for N is %d\n",
                                                         ppbVar42,ppbVar29);
                                              local_204 = TLSv1_client_method();
                                              iVar13 = param_1;
                                              ppbVar29 = local_180[0];
                                            }
                                            else {
                                              pcVar41 = "-srp_lateuser";
                                              ppbVar16 = (byte **)strcmp((char *)__s1,
                                                                         "-srp_lateuser");
                                              if (ppbVar16 == (byte **)0x0) {
                                                local_204 = TLSv1_client_method();
                                                bVar31 = true;
                                                iVar13 = param_1;
                                                ppbVar29 = local_180[0];
                                              }
                                              else {
                                                pcVar41 = "-srp_moregroups";
                                                ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                           "-srp_moregroups");
                                                if (ppbVar42 == (byte **)0x0) {
                                                  local_138 = 1;
                                                  local_204 = TLSv1_client_method();
                                                  iVar13 = param_1;
                                                  ppbVar29 = local_180[0];
                                                  ppbVar42 = ppbVar16;
                                                }
                                                else {
                                                  pcVar41 = "-ssl3";
                                                  iVar13 = strcmp((char *)__s1,"-ssl3");
                                                  if (iVar13 == 0) {
                                                    local_204 = SSLv3_client_method();
                                                    iVar13 = param_1;
                                                    ppbVar29 = local_180[0];
                                                  }
                                                  else {
                                                    pcVar41 = "-tls1_2";
                                                    ppbVar42 = ppbVar36;
                                                    iVar13 = strcmp((char *)__s1,"-tls1_2");
                                                    if (iVar13 == 0) {
                                                      local_204 = TLSv1_2_client_method();
                                                      iVar13 = param_1;
                                                      ppbVar29 = local_180[0];
                                                    }
                                                    else {
                                                      pcVar41 = "-tls1_1";
                                                      ppbVar42 = ppbVar32;
                                                      iVar13 = strcmp((char *)__s1,"-tls1_1");
                                                      if (iVar13 == 0) {
                                                        local_204 = TLSv1_1_client_method();
                                                        iVar13 = param_1;
                                                        ppbVar29 = local_180[0];
                                                      }
                                                      else {
                                                        pcVar41 = "-tls1";
                                                        ppbVar42 = extraout_ECX_10;
                                                        iVar13 = strcmp((char *)__s1,"-tls1");
                                                        if (iVar13 == 0) goto LAB_08070834;
                                                        pcVar41 = "-dtls1";
                                                        ppbVar42 = extraout_EDX_06;
                                                        ppbVar16 = (byte **)strcmp((char *)__s1,
                                                                                   "-dtls1");
                                                        if (ppbVar16 == (byte **)0x0) {
                                                          local_204 = DTLSv1_client_method();
                                                          local_194 = 2;
                                                          iVar13 = param_1;
                                                          ppbVar29 = local_180[0];
                                                        }
                                                        else {
                                                          pcVar41 = "-fallback_scsv";
                                                          ppbVar27 = (byte **)strcmp((char *)__s1,
                                                                                                                                                                          
                                                  "-fallback_scsv");
                                                  if (ppbVar27 == (byte **)0x0) {
                                                    bVar5 = true;
                                                    iVar13 = param_1;
                                                    ppbVar42 = ppbVar16;
                                                  }
                                                  else {
                                                    pcVar41 = "-timeout";
                                                    ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                               "-timeout");
                                                    if (ppbVar42 == (byte **)0x0) {
                                                      bVar12 = true;
                                                      iVar13 = param_1;
                                                      ppbVar42 = ppbVar27;
                                                    }
                                                    else {
                                                      ppbVar16 = (byte **)strcmp((char *)__s1,"-mtu"
                                                                                );
                                                      if (ppbVar16 == (byte **)0x0) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 < 1) goto LAB_0806e480;
                                                        local_180[0] = ppbVar28 + 1;
                                                        ppbVar42 = (byte **)0xa;
                                                        pcVar41 = (char *)0x0;
                                                        local_1ac = strtol((char *)ppbVar28[1],
                                                                           (char **)0x0,10);
                                                        iVar13 = param_1;
                                                        ppbVar29 = local_180[0];
                                                      }
                                                      else {
                                                        pcVar41 = "-bugs";
                                                        ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                                   "-bugs");
                                                        if (ppbVar42 == (byte **)0x0) {
                                                          bVar3 = true;
                                                          iVar13 = param_1;
                                                          ppbVar42 = ppbVar16;
                                                        }
                                                        else {
                                                          pcVar41 = "-keyform";
                                                          ppbVar16 = ppbVar42;
                                                          iVar13 = strcmp((char *)__s1,"-keyform");
                                                          if (iVar13 == 0) {
                                                            param_1 = param_1 + -1;
                                                            if (param_1 < 1) goto LAB_0806e480;
                                                            local_180[0] = ppbVar28 + 1;
                                                            local_1c8 = (timeval *)
                                                                        str2fmt(ppbVar28[1],pcVar41,
                                                                                ppbVar42,ppbVar16);
                                                            iVar13 = param_1;
                                                            ppbVar29 = local_180[0];
                                                          }
                                                          else {
                                                            pcVar41 = "-pass";
                                                            ppbVar42 = ppbVar36;
                                                            iVar13 = strcmp((char *)__s1,"-pass");
                                                            if (iVar13 == 0) {
                                                              param_1 = param_1 + -1;
                                                              if (param_1 < 1) goto LAB_0806e480;
                                                              local_1d8 = ppbVar28[1];
                                                              iVar13 = param_1;
                                                              ppbVar29 = ppbVar28 + 1;
                                                            }
                                                            else {
                                                              pcVar41 = "-key";
                                                              ppbVar42 = ppbVar32;
                                                              iVar13 = strcmp((char *)__s1,"-key");
                                                              if (iVar13 == 0) {
                                                                param_1 = param_1 + -1;
                                                                if (param_1 < 1) goto LAB_0806e480;
                                                                local_1dc = ppbVar28[1];
                                                                iVar13 = param_1;
                                                                ppbVar29 = ppbVar28 + 1;
                                                              }
                                                              else {
                                                                pcVar41 = "-reconnect";
                                                                ppbVar42 = extraout_ECX_11;
                                                                iVar13 = strcmp((char *)__s1,
                                                                                "-reconnect");
                                                                if (iVar13 == 0) {
                                                                  local_1b0 = 5;
                                                                  iVar13 = param_1;
                                                                }
                                                                else {
                                                                  pcVar41 = "-CApath";
                                                                  ppbVar42 = extraout_EDX_07;
                                                                  ppbVar16 = (byte **)strcmp((char *
                                                  )__s1,"-CApath");
                                                  if (ppbVar16 == (byte **)0x0) {
                                                    param_1 = param_1 + -1;
                                                    if (param_1 < 1) goto LAB_0806e480;
                                                    local_1b8 = ppbVar28[1];
                                                    iVar13 = param_1;
                                                    ppbVar29 = ppbVar28 + 1;
                                                  }
                                                  else {
                                                    pcVar41 = "-CAfile";
                                                    ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                               "-CAfile");
                                                    if (ppbVar42 == (byte **)0x0) {
                                                      param_1 = param_1 + -1;
                                                      ppbVar42 = ppbVar16;
                                                      if (param_1 < 1) goto LAB_0806e480;
                                                      local_1b4 = ppbVar28[1];
                                                      iVar13 = param_1;
                                                      ppbVar29 = ppbVar28 + 1;
                                                    }
                                                    else {
                                                      pcVar41 = "-no_tls1_2";
                                                      ppbVar16 = (byte **)strcmp((char *)__s1,
                                                                                 "-no_tls1_2");
                                                      if (ppbVar16 == (byte **)0x0) {
                                                        local_1e8 = local_1e8 | 0x8000000;
                                                        iVar13 = param_1;
                                                      }
                                                      else {
                                                        pcVar41 = "-no_tls1_1";
                                                        ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                                   "-no_tls1_1");
                                                        if (ppbVar42 == (byte **)0x0) {
                                                          local_1e8 = local_1e8 | 0x10000000;
                                                          iVar13 = param_1;
                                                          ppbVar42 = ppbVar16;
                                                        }
                                                        else {
                                                          pcVar41 = "-no_tls1";
                                                          ppbVar16 = (byte **)strcmp((char *)__s1,
                                                                                     "-no_tls1");
                                                          if (ppbVar16 == (byte **)0x0) {
                                                            local_1e8 = local_1e8 | 0x4000000;
                                                            iVar13 = param_1;
                                                          }
                                                          else {
                                                            pcVar41 = "-no_ssl3";
                                                            ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                                       "-no_ssl3");
                                                            if (ppbVar42 == (byte **)0x0) {
                                                              local_1e8 = local_1e8 | 0x2000000;
                                                              iVar13 = param_1;
                                                              ppbVar42 = ppbVar16;
                                                            }
                                                            else {
                                                              pcVar41 = "-no_ssl2";
                                                              iVar13 = strcmp((char *)__s1,
                                                                              "-no_ssl2");
                                                              if (iVar13 == 0) {
                                                                local_1e8 = local_1e8 | 0x1000000;
                                                                iVar13 = param_1;
                                                              }
                                                              else {
                                                                pcVar41 = "-no_comp";
                                                                ppbVar42 = ppbVar36;
                                                                iVar13 = strcmp((char *)__s1,
                                                                                "-no_comp");
                                                                if (iVar13 == 0) {
                                                                  local_1e8 = local_1e8 | 0x20000;
                                                                  iVar13 = param_1;
                                                                }
                                                                else {
                                                                  pcVar41 = "-no_ticket";
                                                                  ppbVar42 = ppbVar32;
                                                                  iVar13 = strcmp((char *)__s1,
                                                                                  "-no_ticket");
                                                                  if (iVar13 == 0) {
                                                                    local_1e8 = local_1e8 | 0x4000;
                                                                    iVar13 = param_1;
                                                                  }
                                                                  else {
                                                                    pcVar41 = "-nextprotoneg";
                                                                    ppbVar42 = extraout_ECX_12;
                                                                    iVar13 = strcmp((char *)__s1,
                                                                                    "-nextprotoneg")
                                                                    ;
                                                                    if (iVar13 == 0) {
                                                                      param_1 = param_1 + -1;
                                                                      if (param_1 < 1)
                                                                      goto LAB_0806e480;
                                                                      local_1f4 = ppbVar28[1];
                                                                      iVar13 = param_1;
                                                                      ppbVar29 = ppbVar28 + 1;
                                                                    }
                                                                    else {
                                                                      pcVar41 = "-serverpref";
                                                                      ppbVar16 = extraout_EDX_08;
                                                                      ppbVar42 = (byte **)strcmp((
                                                  char *)__s1,"-serverpref");
                                                  if (ppbVar42 == (byte **)0x0) {
                                                    local_1e8 = local_1e8 | 0x400000;
                                                    iVar13 = param_1;
                                                    ppbVar42 = ppbVar16;
                                                  }
                                                  else {
                                                    pcVar41 = "-legacy_renegotiation";
                                                    ppbVar16 = (byte **)strcmp((char *)__s1,
                                                                                                                                                              
                                                  "-legacy_renegotiation");
                                                  if (ppbVar16 == (byte **)0x0) {
                                                    local_1e8 = local_1e8 | 0x40000;
                                                    iVar13 = param_1;
                                                  }
                                                  else {
                                                    pcVar41 = "-legacy_server_connect";
                                                    ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                                                                                                              
                                                  "-legacy_server_connect");
                                                  if (ppbVar42 == (byte **)0x0) {
                                                    local_1e8 = local_1e8 | 4;
                                                    iVar13 = param_1;
                                                    ppbVar42 = ppbVar16;
                                                  }
                                                  else {
                                                    pcVar41 = "-no_legacy_server_connect";
                                                    ppbVar16 = (byte **)strcmp((char *)__s1,
                                                                                                                                                              
                                                  "-no_legacy_server_connect");
                                                  if (ppbVar16 == (byte **)0x0) {
                                                    local_1bc = 4;
                                                    iVar13 = param_1;
                                                  }
                                                  else {
                                                    pcVar41 = "-cipher";
                                                    ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                               "-cipher");
                                                    if (ppbVar42 == (byte **)0x0) {
                                                      param_1 = param_1 + -1;
                                                      ppbVar42 = ppbVar16;
                                                      if (param_1 < 1) goto LAB_0806e480;
                                                      local_1a4 = ppbVar28[1];
                                                      iVar13 = param_1;
                                                      ppbVar29 = ppbVar28 + 1;
                                                    }
                                                    else {
                                                      pcVar41 = "-nbio";
                                                      ppbVar16 = (byte **)strcmp((char *)__s1,
                                                                                 "-nbio");
                                                      if (ppbVar16 == (byte **)0x0) {
                                                        c_nbio = 1;
                                                        iVar13 = param_1;
                                                      }
                                                      else {
                                                        ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                                   "-starttls");
                                                        if (ppbVar42 == (byte **)0x0) {
                                                          iVar13 = param_1 + -1;
                                                          param_1 = iVar13;
                                                          ppbVar42 = ppbVar16;
                                                          if (iVar13 < 1) goto LAB_0806e480;
                                                          pbVar35 = ppbVar28[1];
                                                          ppbVar29 = ppbVar28 + 1;
                                                          pcVar41 = &DAT_081f559d;
                                                          local_180[0] = ppbVar29;
                                                          iVar33 = strcmp((char *)pbVar35,"smtp");
                                                          if (iVar33 == 0) {
                                                            local_1ec = 1;
                                                            ppbVar42 = ppbVar28;
                                                          }
                                                          else {
                                                            pcVar41 = &DAT_081f55a2;
                                                            ppbVar42 = extraout_ECX_13;
                                                            iVar33 = strcmp((char *)pbVar35,"pop3");
                                                            if (iVar33 == 0) {
                                                              local_1ec = 2;
                                                            }
                                                            else {
                                                              pcVar41 = &DAT_081f55a7;
                                                              ppbVar42 = extraout_EDX_09;
                                                              ppbVar28 = (byte **)strcmp((char *)
                                                  pbVar35,"imap");
                                                  if (ppbVar28 == (byte **)0x0) {
                                                    local_1ec = 3;
                                                  }
                                                  else if ((((*pbVar35 == 0x66) &&
                                                            (pbVar35[1] == 0x74)) &&
                                                           (pbVar35[2] == 0x70)) &&
                                                          (pbVar35[3] == 0)) {
                                                    local_1ec = 4;
                                                  }
                                                  else {
                                                    pcVar41 = &DAT_081f55ac;
                                                    iVar33 = strcmp((char *)pbVar35,"xmpp");
                                                    ppbVar42 = ppbVar28;
                                                    if (iVar33 != 0) goto LAB_0806e480;
                                                    local_1ec = 5;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    pcVar41 = "-engine";
                                                    ppbVar29 = (byte **)strcmp((char *)__s1,
                                                                               "-engine");
                                                    if (ppbVar29 == (byte **)0x0) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 < 1) goto LAB_0806e480;
                                                      local_1d4 = ppbVar28[1];
                                                      iVar13 = param_1;
                                                      ppbVar29 = ppbVar28 + 1;
                                                    }
                                                    else {
                                                      pcVar41 = "-ssl_client_engine";
                                                      ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                                                                                                                  
                                                  "-ssl_client_engine");
                                                  if (ppbVar42 == (byte **)0x0) {
                                                    param_1 = param_1 + -1;
                                                    ppbVar42 = ppbVar29;
                                                    if (param_1 < 1) goto LAB_0806e480;
                                                    local_1d0 = ppbVar28[1];
                                                    iVar13 = param_1;
                                                    ppbVar29 = ppbVar28 + 1;
                                                  }
                                                  else {
                                                    pcVar41 = "-rand";
                                                    ppbVar29 = (byte **)strcmp((char *)__s1,"-rand")
                                                    ;
                                                    if (ppbVar29 == (byte **)0x0) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 < 1) goto LAB_0806e480;
                                                      local_1cc = ppbVar28[1];
                                                      iVar13 = param_1;
                                                      ppbVar29 = ppbVar28 + 1;
                                                    }
                                                    else {
                                                      pcVar41 = "-servername";
                                                      ppbVar42 = (byte **)strcmp((char *)__s1,
                                                                                 "-servername");
                                                      if (ppbVar42 == (byte **)0x0) {
                                                        param_1 = param_1 + -1;
                                                        ppbVar42 = ppbVar29;
                                                        if (param_1 < 1) goto LAB_0806e480;
                                                        local_1c4 = (SSL_SESSION *)ppbVar28[1];
                                                        iVar13 = param_1;
                                                        ppbVar29 = ppbVar28 + 1;
                                                      }
                                                      else {
                                                        pcVar41 = "-use_srtp";
                                                        iVar13 = strcmp((char *)__s1,"-use_srtp");
                                                        if (iVar13 == 0) {
                                                          param_1 = param_1 + -1;
                                                          if (param_1 < 1) goto LAB_0806e480;
                                                          srtp_profiles = ppbVar28[1];
                                                          iVar13 = param_1;
                                                          ppbVar29 = ppbVar28 + 1;
                                                        }
                                                        else {
                                                          pcVar41 = "-keymatexport";
                                                          iVar13 = strcmp((char *)__s1,
                                                                          "-keymatexport");
                                                          if (iVar13 == 0) {
                                                            param_1 = param_1 + -1;
                                                            ppbVar42 = ppbVar36;
                                                            if (param_1 < 1) goto LAB_0806e480;
                                                            keymatexportlabel = ppbVar28[1];
                                                            iVar13 = param_1;
                                                            ppbVar29 = ppbVar28 + 1;
                                                          }
                                                          else {
                                                            iVar13 = strcmp((char *)__s1,
                                                                            "-keymatexportlen");
                                                            if (iVar13 != 0) {
                                                              BIO_printf(bio_err,
                                                  "unknown option %s\n",__s1,extraout_ECX_14);
                                                  ppbVar42 = __s1;
                                                  goto LAB_0806e480;
                                                  }
                                                  param_1 = param_1 + -1;
                                                  ppbVar42 = ppbVar32;
                                                  if (param_1 < 1) goto LAB_0806e480;
                                                  local_180[0] = ppbVar28 + 1;
                                                  ppbVar42 = (byte **)0xa;
                                                  pcVar41 = (char *)0x0;
                                                  keymatexportlen =
                                                       strtol((char *)ppbVar28[1],(char **)0x0,10);
                                                  iVar13 = param_1;
                                                  ppbVar29 = local_180[0];
                                                  if (keymatexportlen == 0) goto LAB_0806e480;
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
LAB_0806e33f:
        param_1 = iVar13 + -1;
        unaff_EBP = ppbVar29 + 1;
        local_180[0] = unaff_EBP;
        goto LAB_0806e353;
      }
    }
    ctx_00 = (SSL_SESSION *)0x0;
    pkey = (EVP_PKEY *)0x0;
    a = (X509 *)0x0;
    BIO_printf(bio_err,"out of memory\n");
    local_20c = (char *)0x0;
  }
LAB_0806e038:
  iVar33 = 1;
  if (next_proto._0_4_ != (void *)0x0) {
LAB_0806e046:
    CRYPTO_free(next_proto._0_4_);
  }
  if (ctx_00 != (SSL_SESSION *)0x0) {
LAB_0806e056:
    SSL_CTX_free((SSL_CTX *)ctx_00);
  }
  if (a != (X509 *)0x0) {
    X509_free(a);
  }
  if (pkey != (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey);
  }
  if (local_16c != (void *)0x0) {
    CRYPTO_free(local_16c);
  }
  CRYPTO_free(local_148);
  if (local_168 != (SSL_CTX *)0x0) {
    X509_VERIFY_PARAM_free((X509_VERIFY_PARAM *)local_168);
  }
  if (local_208 != (byte *)0x0) {
    OPENSSL_cleanse(local_208,0x2000);
    CRYPTO_free(local_208);
  }
  if (local_210 != (char *)0x0) {
    OPENSSL_cleanse(local_210,0x2000);
    CRYPTO_free(local_210);
  }
  if (local_20c != (char *)0x0) {
    OPENSSL_cleanse(local_20c,0x2000);
    CRYPTO_free(local_20c);
  }
  if (bio_c_out != (BIO *)0x0) {
    BIO_free(bio_c_out);
    bio_c_out = (BIO *)0x0;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar33;
LAB_0806f0a9:
  iVar13 = init_client(&local_174,local_170,(int)local_176,local_194);
  if (iVar13 == 0) {
    piVar25 = __errno_location();
    iVar13 = *piVar25;
    pcVar41 = "connect:errno=%d\n";
    pBVar18 = extraout_EDX_02;
LAB_0806fe85:
    iVar33 = 1;
    BIO_printf(bio_err,pcVar41,iVar13,pBVar18);
    shutdown(local_174,0);
    close(local_174);
  }
  else {
    iVar13 = BIO_printf(bio_c_out,"CONNECTED(%08X)\n",local_174,iVar13);
    if (c_nbio != 0) {
      local_15c = 1;
      BIO_printf(bio_c_out,"turning on non blocking io\n",iVar13,iVar13);
      iVar13 = BIO_socket_ioctl(local_174,0x5421,&local_15c);
      if (iVar13 < 0) {
        iVar33 = 1;
        ERR_print_errors(bio_err);
        goto LAB_0806f496;
      }
    }
    if ((c_Pause & 1) != 0) {
      SSL_set_debug(to,1);
    }
    iVar13 = SSL_version(to);
    if (iVar13 != 0xfeff) {
      pBVar18 = BIO_new_socket(local_174,0);
LAB_0806f142:
      if (bVar6) {
        pBVar19 = BIO_f_nbio_test();
        pBVar20 = BIO_new(pBVar19);
        pBVar18 = BIO_push(pBVar20,pBVar18);
      }
      if (c_debug != 0) {
        SSL_set_debug(to,1);
        BIO_set_callback(pBVar18,bio_dump_callback);
        BIO_set_callback_arg(pBVar18,(char *)bio_c_out);
      }
      if (c_msg != 0) {
        SSL_set_msg_callback(to,msg_cb);
        SSL_ctrl(to,0x10,0,bio_c_out);
      }
      if (c_tlsextdebug != 0) {
        SSL_callback_ctrl(to,0x38,tlsext_cb);
        SSL_ctrl(to,0x39,0,bio_c_out);
      }
      if (c_status_req != 0) {
        SSL_ctrl(to,0x41,1,(void *)0x0);
        SSL_CTX_callback_ctrl((SSL_CTX *)ctx_00,0x3f,ocsp_resp_cb);
        SSL_CTX_ctrl((SSL_CTX *)ctx_00,0x40,0,bio_c_out);
      }
      SSL_set_bio(to,pBVar18,pBVar18);
      SSL_set_connect_state(to);
      iVar13 = SSL_get_fd(to);
      if (local_1ec == 1) {
        pBVar19 = BIO_f_buffer();
        pBVar20 = BIO_new(pBVar19);
        BIO_push(pBVar20,pBVar18);
        do {
          iVar33 = BIO_gets(pBVar20,local_20c,0x2000);
          if (iVar33 < 4) break;
        } while (local_20c[3] == '-');
        BIO_printf(pBVar20,"EHLO openssl.client.net\r\n",extraout_ECX_06,extraout_ECX_06);
        BIO_ctrl(pBVar20,0xb,0,(void *)0x0);
        bVar31 = false;
        do {
          iVar33 = BIO_gets(pBVar20,local_20c,0x2000);
          pcVar41 = strstr(local_20c,"STARTTLS");
          if (pcVar41 != (char *)0x0) {
            bVar31 = true;
          }
        } while ((3 < iVar33) && (local_20c[3] == '-'));
        BIO_ctrl(pBVar20,0xb,0,(void *)0x0);
        BIO_pop(pBVar20);
        iVar33 = BIO_free(pBVar20);
        if (!bVar31) {
          iVar33 = BIO_printf(bio_err,"didn\'t found starttls in server response, try anyway...\n",
                              iVar33,iVar33);
        }
        pcVar41 = "STARTTLS\r\n";
        iVar22 = iVar33;
      }
      else if (local_1ec == 2) {
        iVar33 = 0x2000;
        iVar22 = extraout_ECX;
        BIO_read(pBVar18,local_20c,0x2000);
        pcVar41 = "STLS\r\n";
      }
      else if (local_1ec == 3) {
        pBVar19 = BIO_f_buffer();
        pBVar20 = BIO_new(pBVar19);
        BIO_push(pBVar20,pBVar18);
        BIO_gets(pBVar20,local_20c,0x2000);
        BIO_printf(pBVar20,". CAPABILITY\r\n");
        BIO_ctrl(pBVar20,0xb,0,(void *)0x0);
        bVar31 = false;
        do {
          iVar33 = BIO_gets(pBVar20,local_20c,0x2000);
          pcVar41 = strstr(local_20c,"STARTTLS");
          if (pcVar41 != (char *)0x0) {
            bVar31 = true;
          }
        } while ((3 < iVar33) && (*local_20c != '.'));
        BIO_ctrl(pBVar20,0xb,0,(void *)0x0);
        BIO_pop(pBVar20);
        BIO_free(pBVar20);
        iVar33 = extraout_ECX_07;
        if (!bVar31) {
          BIO_printf(bio_err,"didn\'t found STARTTLS in server response, try anyway...\n",0,0);
          iVar33 = extraout_ECX_08;
        }
        pcVar41 = ". STARTTLS\r\n";
        iVar22 = iVar33;
      }
      else {
        if (local_1ec != 4) {
          if (local_1ec != 5) goto LAB_0806f282;
          BIO_printf(pBVar18,
                     "<stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\' xmlns=\'jabber:client\' to=\'%s\' version=\'1.0\'>"
                     ,local_170,extraout_ECX);
          iVar33 = BIO_read(pBVar18,local_20c,0x2000);
          local_20c[iVar33] = '\0';
          while (pcVar41 = strstr(local_20c,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'"),
                pcVar41 == (char *)0x0) {
            pcVar41 = strstr(local_20c,"/stream:features>");
            if (pcVar41 != (char *)0x0) goto LAB_08070687;
            iVar33 = BIO_read(pBVar18,local_20c,0x2000);
            local_20c[iVar33] = '\0';
          }
          BIO_printf(pBVar18,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'/>",pcVar41,pcVar41
                    );
          iVar33 = BIO_read(pBVar18,local_210,0x2000);
          local_210[iVar33] = '\0';
          pcVar41 = strstr(local_210,"<proceed");
          if (pcVar41 != (char *)0x0) {
            *local_20c = '\0';
            goto LAB_0806f282;
          }
LAB_08070687:
          iVar33 = 1;
          goto LAB_0806f448;
        }
        pBVar19 = BIO_f_buffer();
        pBVar20 = BIO_new(pBVar19);
        BIO_push(pBVar20,pBVar18);
        do {
          iVar33 = BIO_gets(pBVar20,local_20c,0x2000);
          if (iVar33 < 4) break;
        } while (local_20c[3] == '-');
        iVar22 = 0;
        iVar33 = 0;
        BIO_ctrl(pBVar20,0xb,0,(void *)0x0);
        BIO_pop(pBVar20);
        BIO_free(pBVar20);
        pcVar41 = "AUTH TLS\r\n";
      }
      BIO_printf(pBVar18,pcVar41,iVar33,iVar22);
      BIO_read(pBVar18,local_210,0x2000);
LAB_0806f282:
      bVar31 = true;
      local_1d0 = (byte *)0x0;
      uVar30 = 0;
      local_1d8 = (byte *)0x0;
      local_1d4 = (byte *)0x0;
      bVar5 = true;
      bVar38 = true;
      bVar39 = false;
switchD_0806fe34_caseD_7:
      bVar10 = bVar39;
      bVar9 = bVar38;
      bVar8 = bVar5;
      iVar33 = 0x20;
      p_Var34 = local_120.fds_bits;
      for (; iVar33 != 0; iVar33 = iVar33 + -1) {
        *p_Var34 = 0;
        p_Var34 = p_Var34 + 1;
      }
      iVar33 = 0x20;
      p_Var34 = local_a0.fds_bits;
      for (; iVar33 != 0; iVar33 = iVar33 + -1) {
        *p_Var34 = 0;
        p_Var34 = p_Var34 + 1;
      }
      iVar33 = SSL_version(to);
      if (iVar33 == 0xfeff) {
        lVar14 = SSL_ctrl(to,0x49,0,&local_158);
        local_1c8 = &local_158;
        if (lVar14 == 0) goto LAB_0806f2ef;
      }
      else {
LAB_0806f2ef:
        local_1c8 = (timeval *)0x0;
      }
      uVar21 = SSL_state(to);
      bVar5 = bVar8;
      bVar38 = bVar9;
      bVar39 = bVar10;
      if (((uVar21 & 0x3000) != 0) && (lVar14 = SSL_ctrl(to,0xc,0,(void *)0x0), lVar14 == 0)) {
        bVar3 = true;
        if (bVar8) {
          p_Var34 = (__fd_mask *)0x0;
          goto LAB_0806f3c5;
        }
LAB_0806f778:
        if (bVar31) {
          iVar33 = SSL_get_fd(to);
          p_Var34 = (__fd_mask *)(1 << ((byte)(iVar33 % 0x20) & 0x1f));
          iVar33 = SSL_get_fd(to);
          iVar33 = __fdelt_chk(iVar33);
          local_a0.fds_bits[iVar33] = local_a0.fds_bits[iVar33] | (uint)p_Var34;
        }
        iVar33 = select(iVar13 + 1,&local_120,&local_a0,(fd_set *)0x0,local_1c8);
        if (iVar33 < 0) {
          piVar25 = __errno_location();
          iVar33 = 1;
          BIO_printf(bio_err,"bad select %d\n",*piVar25,p_Var34);
          goto LAB_0806f448;
        }
        iVar33 = SSL_version(to);
        if (iVar33 == 0xfeff) {
          bVar2 = false;
          lVar14 = SSL_ctrl(to,0x4a,0,(void *)0x0);
          uVar15 = extraout_ECX_01;
          if (0 < lVar14) goto LAB_0806f7d5;
        }
LAB_0806f7f2:
        iVar33 = SSL_get_fd(to);
        iVar33 = __fdelt_chk(iVar33);
        uVar21 = local_a0.fds_bits[iVar33];
        iVar33 = SSL_get_fd(to);
        if ((uVar21 >> (iVar33 % 0x20 & 0x1fU) & 1) != 0) goto LAB_0806fe0c;
        iVar33 = fileno(stdout);
        iVar33 = __fdelt_chk(iVar33);
        uVar21 = local_a0.fds_bits[iVar33];
        iVar33 = fileno(stdout);
        uVar23 = 1 << ((byte)(iVar33 % 0x20) & 0x1f);
        if ((uVar21 & uVar23) == 0) {
          iVar33 = SSL_get_fd(to);
          iVar33 = __fdelt_chk(iVar33);
          uVar21 = local_120.fds_bits[iVar33];
          iVar33 = SSL_get_fd(to);
          bVar40 = (byte)(iVar33 >> 0x1f);
          if ((uVar21 & 1 << (((char)iVar33 + (bVar40 >> 3) & 0x1f) - (bVar40 >> 3) & 0x1f)) != 0)
          goto LAB_0806f3f0;
          iVar33 = fileno(stdin);
          iVar33 = __fdelt_chk(iVar33);
          uVar21 = local_120.fds_bits[iVar33];
          iVar33 = fileno(stdin);
          iVar22 = iVar33 / 0x20;
          if ((uVar21 & 1 << ((byte)(iVar33 % 0x20) & 0x1f)) != 0) {
            if (bVar11) {
              uVar30 = raw_read_stdin(local_208,0x1000,iVar22,iVar22);
              uVar21 = 0;
              for (iVar33 = 0; uVar23 = uVar30, iVar33 < (int)uVar30; iVar33 = iVar33 + 1) {
                uVar21 = uVar21 + (local_208[iVar33] == 10);
              }
              while (uVar23 = uVar23 - 1, -1 < (int)uVar23) {
                local_208[uVar21 + uVar23] = local_208[uVar23];
                if (local_208[uVar23] == 10) {
                  uVar21 = uVar21 - 1;
                  uVar30 = uVar30 + 1;
                  local_208[uVar21 + uVar23] = 0xd;
                }
              }
              if (uVar21 != 0) {
                    /* WARNING: Subroutine does not return */
                __assert_fail("lf_num == 0","s_client.c",0x724,"s_client_main");
              }
            }
            else {
              uVar21 = raw_read_stdin(local_208,0x2000,iVar22,iVar22);
              uVar30 = uVar21;
            }
            if (c_ign_eof == 0) {
              if (0 < (int)uVar30) {
                bVar40 = *local_208;
                uVar21 = (uint)bVar40;
                if (bVar40 != 0x51) {
                  if (bVar40 == 0x52) {
                    bVar31 = true;
                    uVar30 = 0;
                    BIO_printf(bio_err,"RENEGOTIATING\n",uVar21,uVar21);
                    SSL_renegotiate(to);
                    bVar38 = false;
                  }
                  else {
                    if (bVar40 != 0x42) goto LAB_0806f9a7;
                    bVar31 = true;
                    uVar30 = 0;
                    BIO_printf(bio_err,"HEARTBEATING\n",uVar21,uVar21);
                    SSL_ctrl(to,0x55,0,(void *)0x0);
                    bVar38 = false;
                  }
                  goto switchD_0806fe34_caseD_7;
                }
              }
              iVar33 = 0;
              BIO_printf(bio_err,"DONE\n",uVar21,uVar21);
              goto LAB_0806f448;
            }
LAB_0806f9a7:
            bVar31 = true;
            local_1d4 = (byte *)0x0;
            bVar38 = false;
          }
        }
        else {
          iVar33 = raw_write_stdout(local_210 + (int)local_1d0,local_1d8,uVar23,uVar23);
          if (iVar33 < 1) {
            iVar33 = 0;
            BIO_printf(bio_c_out,"DONE\n",extraout_ECX_03,extraout_ECX_03);
            goto LAB_0806f448;
          }
          local_1d8 = (byte *)((int)local_1d8 - iVar33);
          local_1d0 = (byte *)((int)local_1d0 + iVar33);
          bVar5 = true;
          bVar39 = false;
          if (0 < (int)local_1d8) {
            bVar5 = bVar8;
            bVar39 = bVar10;
          }
        }
        goto switchD_0806fe34_caseD_7;
      }
      if (bVar3) {
        if (local_1f0 != (byte *)0x0) {
          pBVar18 = BIO_new_file((char *)local_1f0,"w");
          if (pBVar18 == (BIO *)0x0) {
            BIO_printf(bio_err,"Error writing session file %s\n",local_1f0,0);
          }
          else {
            pSVar17 = SSL_get_session(to);
            PEM_write_bio_SSL_SESSION(pBVar18,pSVar17);
            BIO_free(pBVar18);
          }
        }
        print_stuff();
        bVar3 = false;
        if (!bVar4) {
          bVar3 = bVar4;
        }
        bVar4 = bVar3;
        if (local_1ec != 0) {
          local_1ec = BIO_printf(bio_err,"%s",local_20c,local_1ec);
        }
        if (local_1b0 != 0) goto LAB_0807016e;
        local_1ec = 0;
      }
      bVar3 = false;
      p_Var34 = (__fd_mask *)0x1;
      bVar2 = bVar8;
      if (!bVar8) {
LAB_0806f6d6:
        if (bVar9) {
          iVar33 = fileno(stdin);
          iVar22 = fileno(stdin);
          p_Var34 = (__fd_mask *)__fdelt_chk(iVar22);
          local_120.fds_bits[(int)p_Var34] =
               local_120.fds_bits[(int)p_Var34] | 1 << ((byte)(iVar33 % 0x20) & 0x1f);
        }
        bVar3 = bVar2;
        if (bVar10) {
          iVar33 = fileno(stdout);
          p_Var34 = (__fd_mask *)(1 << ((byte)(iVar33 % 0x20) & 0x1f));
          iVar33 = fileno(stdout);
          iVar33 = __fdelt_chk(iVar33);
          local_a0.fds_bits[iVar33] = local_a0.fds_bits[iVar33] | (uint)p_Var34;
        }
LAB_0806f76c:
        if (bVar8) {
          iVar33 = SSL_get_fd(to);
          p_Var34 = (__fd_mask *)(1 << ((byte)(iVar33 % 0x20) & 0x1f));
          iVar33 = SSL_get_fd(to);
          iVar33 = __fdelt_chk(iVar33);
          local_120.fds_bits[iVar33] = local_120.fds_bits[iVar33] | (uint)p_Var34;
        }
        goto LAB_0806f778;
      }
LAB_0806f3c5:
      iVar33 = SSL_pending(to);
      if (iVar33 == 0) {
        bVar2 = bVar3;
        if (p_Var34 != (__fd_mask *)0x0) goto LAB_0806f6d6;
        goto LAB_0806f76c;
      }
      iVar33 = SSL_version(to);
      if (iVar33 == 0xfeff) {
        bVar2 = true;
        lVar14 = SSL_ctrl(to,0x4a,0,(void *)0x0);
        uVar15 = extraout_ECX_05;
        if (lVar14 < 1) goto LAB_0806f3f0;
LAB_0806f7d5:
        BIO_printf(bio_err,"TIMEOUT occured\n",uVar15,uVar15);
        if (!bVar2) goto LAB_0806f7f2;
      }
LAB_0806f3f0:
      iVar22 = SSL_read(to,local_210,0x400);
      iVar33 = SSL_get_error(to,iVar22);
      switch(iVar33) {
      case 0:
        if (iVar22 < 1) goto LAB_0807030a;
        local_1d0 = (byte *)0x0;
        local_1d8 = (byte *)iVar22;
        bVar5 = false;
        bVar39 = true;
        break;
      case 1:
        goto switchD_0806fe34_caseD_1;
      case 2:
        BIO_printf(bio_c_out,"read R BLOCK\n",iVar33,iVar33);
        bVar8 = (bool)(bVar9 | bVar31);
        if (!bVar8) {
          bVar31 = true;
        }
        bVar5 = true;
        bVar38 = false;
        bVar39 = false;
        if (bVar8) {
          bVar38 = bVar9;
        }
        break;
      case 3:
        pcVar41 = "read W BLOCK\n";
        goto LAB_0806f4ec;
      case 4:
        BIO_printf(bio_c_out,"read X BLOCK\n",iVar33,iVar33);
        break;
      case 5:
        piVar25 = __errno_location();
        iVar33 = *piVar25;
        BIO_printf(bio_err,"read:errno=%d\n",iVar33,piVar25);
        goto LAB_0806f448;
      case 6:
        iVar33 = 0;
        BIO_printf(bio_c_out,"closed\n",extraout_ECX_00,extraout_ECX_00);
        goto LAB_0806f448;
      }
      goto switchD_0806fe34_caseD_7;
    }
    pBVar18 = BIO_new_dgram(local_174,0);
    iVar13 = getsockname(local_174,&local_130,&local_160);
    if (iVar13 < 0) {
      piVar25 = __errno_location();
      iVar13 = *piVar25;
      pcVar41 = "getsockname:errno=%d\n";
      goto LAB_0806fe85;
    }
    BIO_ctrl(pBVar18,0x20,1,&local_130);
    if (bVar12) {
      local_158.tv_sec = 0;
      local_158.tv_usec = 250000;
      BIO_ctrl(pBVar18,0x21,0,&local_158);
      local_158.tv_sec = 0;
      local_158.tv_usec = 250000;
      BIO_ctrl(pBVar18,0x23,0,&local_158);
    }
    if (local_1ac == 0) {
      BIO_ctrl(pBVar18,0x27,0,(void *)0x0);
      goto LAB_0806f142;
    }
    lVar14 = SSL_ctrl(to,0x79,0,(void *)0x0);
    if (local_1ac < lVar14) {
      lVar14 = 0;
      lVar24 = SSL_ctrl(to,0x79,0,(void *)0x0);
      pcVar41 = "MTU too small. Must be at least %ld\n";
    }
    else {
      SSL_ctrl(to,0x20,0x1000,(void *)0x0);
      lVar24 = SSL_ctrl(to,0x78,local_1ac,(void *)0x0);
      if (lVar24 != 0) goto LAB_0806f142;
      pcVar41 = "Failed to set MTU\n";
      lVar14 = lVar24;
    }
    BIO_printf(bio_err,pcVar41,lVar24,lVar14);
    iVar33 = 1;
    BIO_free(pBVar18);
LAB_0806f448:
    if (bVar3) {
      print_stuff();
    }
    SSL_shutdown(to);
    iVar13 = SSL_get_fd(to);
    shutdown(iVar13,0);
    iVar13 = SSL_get_fd(to);
    close(iVar13);
  }
  goto LAB_0806f496;
LAB_0807016e:
  local_1b0 = local_1b0 + -1;
  BIO_printf(bio_c_out,"drop connection and then reconnect\n",local_1ec,local_1ec);
  SSL_shutdown(to);
  SSL_set_connect_state(to);
  iVar13 = SSL_get_fd(to);
  shutdown(iVar13,0);
  iVar13 = SSL_get_fd(to);
  close(iVar13);
  bVar3 = false;
  local_1ec = 0;
  goto LAB_0806f0a9;
LAB_0806fe0c:
  uVar21 = SSL_write(to,local_208 + (int)local_1d4,uVar30);
  iVar33 = SSL_get_error(to,uVar21);
  switch(iVar33) {
  case 0:
    local_1d4 = (byte *)((int)local_1d4 + uVar21);
    uVar30 = uVar30 - uVar21;
    if ((int)uVar21 < 1) {
LAB_0807030a:
      iVar33 = 1;
      goto LAB_0806f496;
    }
    bVar31 = 0 < (int)uVar30;
    bVar38 = (int)uVar30 < 1;
    break;
  case 1:
switchD_0806fe34_caseD_1:
    iVar33 = 1;
    ERR_print_errors(bio_err);
    goto LAB_0806f448;
  case 2:
    bVar31 = false;
    BIO_printf(bio_c_out,"write R BLOCK\n",iVar33,iVar33);
    bVar5 = true;
    bVar39 = false;
    break;
  case 3:
    pcVar41 = "write W BLOCK\n";
LAB_0806f4ec:
    bVar31 = true;
    BIO_printf(bio_c_out,pcVar41,iVar33,iVar33);
    bVar38 = false;
    break;
  case 4:
    BIO_printf(bio_c_out,"write X BLOCK\n",uVar21,uVar21);
    break;
  case 5:
    if ((uVar30 | uVar21) != 0) {
      piVar25 = __errno_location();
      iVar33 = 1;
      BIO_printf(bio_err,"write:errno=%d\n",*piVar25,extraout_EDX_03);
      goto LAB_0806f448;
    }
    bVar31 = false;
    uVar30 = 0;
    bVar38 = true;
    break;
  case 6:
    if (uVar30 != 0) {
      iVar33 = 0;
      BIO_printf(bio_c_out,"shutdown\n",extraout_ECX_02,extraout_ECX_02);
      goto LAB_0806f448;
    }
    bVar31 = false;
    bVar38 = true;
  }
  goto switchD_0806fe34_caseD_7;
LAB_0806f496:
  if (to != (SSL *)0x0) {
    if (bVar7) {
      print_stuff();
    }
    SSL_free(to);
  }
  if (next_proto._0_4_ != (void *)0x0) goto LAB_0806e046;
  goto LAB_0806e056;
LAB_0806e480:
  BIO_printf(bio_err,"usage: s_client args\n",ppbVar42);
  BIO_printf(bio_err,"\n");
  BIO_printf(bio_err," -host host     - use -connect instead\n");
  BIO_printf(bio_err," -port port     - use -connect instead\n");
  BIO_printf(bio_err," -connect host:port - who to connect to (default is %s:%s)\n","localhost",
             "4433");
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
  pcVar41 = " -keymatexportlen len  - Export len bytes of keying material (default 20)\n";
LAB_0806e93e:
  ctx_00 = (SSL_SESSION *)0x0;
  pkey = (EVP_PKEY *)0x0;
  a = (X509 *)0x0;
  BIO_printf(bio_err,pcVar41);
  goto LAB_0806e038;
}

