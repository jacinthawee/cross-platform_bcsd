
int s_client_main(int param_1,SSL_SESSION *param_2)

{
  _func_603 *__s1;
  bool bVar1;
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
  BIO_METHOD **ppBVar12;
  int iVar13;
  long lVar14;
  int iVar15;
  undefined4 uVar16;
  ENGINE *e;
  SSL_SESSION *pSVar17;
  SSL_CTX *ctx;
  SSL *to;
  BIO *pBVar18;
  uint uVar19;
  int iVar20;
  BIO_METHOD *pBVar21;
  BIO *pBVar22;
  X509 *pXVar23;
  int *piVar24;
  ushort **ppuVar25;
  SSL_SESSION *pSVar26;
  SSL_SESSION *pSVar27;
  SSL_SESSION *pSVar28;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  SSL_SESSION *extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  uint uVar29;
  undefined4 extraout_ECX_08;
  SSL_SESSION *extraout_ECX_09;
  SSL_SESSION *extraout_ECX_10;
  SSL_SESSION *extraout_ECX_11;
  SSL_SESSION *extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  X509 *pXVar30;
  SSL_SESSION *extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  SSL_SESSION *extraout_EDX_09;
  SSL_SESSION *extraout_EDX_10;
  SSL_SESSION *extraout_EDX_11;
  SSL_SESSION *extraout_EDX_12;
  SSL_SESSION *extraout_EDX_13;
  SSL_CTX *ctx_00;
  EVP_PKEY *pkey;
  X509 *a;
  BIO_METHOD *pBVar31;
  X509 *num;
  SSL_SESSION *pSVar32;
  __fd_mask *p_Var33;
  char *pcVar34;
  SSL_SESSION *pSVar35;
  int in_GS_OFFSET;
  bool bVar37;
  bool bVar38;
  byte bVar39;
  undefined8 uVar40;
  char *pcVar41;
  code *pcVar42;
  SSL_SESSION *pSVar43;
  SSL_SESSION *__s1_00;
  _func_603 **pp_Var44;
  char *local_20c;
  char *local_208;
  byte *local_204;
  SSL_METHOD *local_200;
  int local_1f8;
  _func_603 *local_1f4;
  _func_603 *local_1f0;
  _func_603 *local_1ec;
  int local_1e8;
  uint local_1e4;
  SSL_SESSION *local_1e0;
  undefined4 local_1dc;
  _func_603 *local_1d8;
  _func_603 *local_1d4;
  _func_603 *local_1d0;
  _func_603 *local_1cc;
  SSL_SESSION *local_1c8;
  timeval *local_1c4;
  _func_603 *local_1c0;
  _func_603 *local_1bc;
  int local_1b8;
  int local_1b4;
  int local_1b0;
  _func_603 *local_1a8;
  _func_603 *local_1a4;
  _func_603 *local_1a0;
  long local_18c;
  SSL_SESSION *local_180 [2];
  short local_176;
  int local_174;
  BIO *local_170;
  void *local_16c;
  SSL_CTX *local_168;
  int local_164;
  socklen_t local_160;
  undefined4 local_15c;
  timeval local_158;
  BIO *local_150;
  undefined4 local_14c;
  undefined4 local_148;
  _func_603 *local_144;
  int local_140;
  int local_13c;
  int local_138;
  SSL_SESSION *local_134;
  sockaddr local_130;
  fd_set local_120;
  fd_set local_a0;
  int local_20;
  SSL_SESSION *pSVar36;
  
  bVar39 = 0;
  local_170 = (BIO *)0x81f4e85;
  local_16c = (void *)0x0;
  local_168 = (SSL_CTX *)0x0;
  local_164 = 0;
  local_150 = (BIO *)0x0;
  local_180[0] = param_2;
  local_14c = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_160 = 0x10;
  local_148 = 0;
  local_176 = 0x1151;
  local_144 = (_func_603 *)0x0;
  local_140 = 0;
  local_13c = 0;
  local_138 = 0;
  local_134 = (SSL_SESSION *)0x400;
  local_200 = SSLv23_client_method();
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
  iVar13 = load_config(bio_err,0);
  if (iVar13 == 0) {
    ctx_00 = (SSL_CTX *)0x0;
    pkey = (EVP_PKEY *)0x0;
    a = (X509 *)0x0;
    local_208 = (char *)0x0;
    local_20c = (char *)0x0;
    local_204 = (byte *)0x0;
  }
  else {
    local_204 = (byte *)CRYPTO_malloc(0x2000,"s_client.c",0x285);
    if ((local_204 == (byte *)0x0) ||
       (local_20c = (char *)CRYPTO_malloc(0x2000,"s_client.c",0x286), local_20c == (char *)0x0)) {
      local_20c = (char *)0x0;
    }
    else {
      pSVar43 = (SSL_SESSION *)0x287;
      pcVar41 = "s_client.c";
      local_208 = (char *)CRYPTO_malloc(0x2000,"s_client.c",0x287);
      if (local_208 != (char *)0x0) {
        verify_depth = (SSL_SESSION *)0x0;
        verify_error = 0;
        c_nbio = 0;
        local_180[0] = (SSL_SESSION *)&local_180[0]->key_arg_length;
        bVar4 = false;
        param_1 = param_1 + -1;
        local_1bc = (_func_603 *)0x0;
        local_18c = 0;
        bVar11 = false;
        local_1ec = (_func_603 *)0x0;
        local_1e0 = (SSL_SESSION *)0x0;
        local_1f0 = (_func_603 *)0x0;
        local_1c0 = (_func_603 *)0x0;
        local_1cc = (_func_603 *)0x0;
        local_1d0 = (_func_603 *)0x0;
        local_1c8 = (SSL_SESSION *)0x0;
        local_1b0 = 1;
        bVar9 = false;
        local_1e8 = 0;
        bVar5 = false;
        bVar10 = false;
        bVar3 = false;
        local_1f8 = 0;
        local_1b4 = 0;
        local_1a0 = (_func_603 *)0x0;
        local_1a4 = (_func_603 *)0x0;
        local_1a8 = (_func_603 *)0x0;
        local_1d4 = (_func_603 *)0x0;
        local_1c4 = (timeval *)0x3;
        local_1dc = 3;
        local_1d8 = (_func_603 *)0x0;
        local_1f4 = (_func_603 *)0x0;
        bVar1 = false;
        local_1b8 = 0;
        local_1e4 = 0;
LAB_0806dcf3:
        bVar37 = false;
        bVar38 = param_1 == 0;
        if (param_1 < 1) {
          SSL_library_init();
          SSL_load_error_strings();
          next_proto._8_4_ = 0xffffffff;
          if (local_1f0 == (_func_603 *)0x0) {
            next_proto._0_4_ = (void *)0x0;
          }
          else {
            next_proto._0_4_ = (void *)next_protos_parse(0x82fbf9c,local_1f0);
            if (next_proto._0_4_ == (void *)0x0) {
              pcVar41 = "Error parsing -nextprotoneg argument\n";
              goto LAB_0806e28e;
            }
          }
          uVar16 = setup_engine(bio_err,local_1d0,1);
          if (local_1cc == (_func_603 *)0x0) {
            e = (ENGINE *)0x0;
          }
          else {
            e = ENGINE_by_id((char *)local_1cc);
            if (e == (ENGINE *)0x0) {
              pcVar41 = "Error getting client auth engine\n";
              goto LAB_0806e28e;
            }
          }
          uVar40 = app_passwd(bio_err,local_1d4,0,&local_16c,0);
          if ((int)uVar40 == 0) {
            pcVar41 = "Error getting password\n";
            goto LAB_0806e28e;
          }
          if (local_1d8 == (_func_603 *)0x0) {
            if (local_1f4 != (_func_603 *)0x0) {
              pkey = (EVP_PKEY *)
                     load_key(bio_err,local_1f4,local_1c4,0,local_16c,uVar16,
                              "client certificate private key file",(int)((ulonglong)uVar40 >> 0x20)
                             );
              if (pkey != (EVP_PKEY *)0x0) goto LAB_0806e4bf;
              goto LAB_0806f138;
            }
            pkey = (EVP_PKEY *)0x0;
            a = (X509 *)0x0;
          }
          else {
            pkey = (EVP_PKEY *)
                   load_key(bio_err,local_1d8,local_1c4,0,local_16c,uVar16,
                            "client certificate private key file");
            if (pkey == (EVP_PKEY *)0x0) {
LAB_0806f138:
              ctx_00 = (SSL_CTX *)0x0;
              pkey = (EVP_PKEY *)0x0;
              a = (X509 *)0x0;
              ERR_print_errors(bio_err);
              goto LAB_0806d9f7;
            }
            if (local_1f4 == (_func_603 *)0x0) {
              a = (X509 *)0x0;
            }
            else {
LAB_0806e4bf:
              a = (X509 *)load_cert(bio_err,local_1f4,local_1dc,0,uVar16,"client certificate file");
              if (a == (X509 *)0x0) {
                ctx_00 = (SSL_CTX *)0x0;
                ERR_print_errors(bio_err);
                goto LAB_0806d9f7;
              }
            }
          }
          iVar13 = 1;
          pcVar41 = (char *)bio_err;
          iVar15 = app_RAND_load_file(0,bio_err,1);
          if (iVar15 == 0) {
            if (local_1c8 == (SSL_SESSION *)0x0) {
              iVar15 = RAND_status();
              if (iVar15 == 0) {
                pcVar41 = "warning, not much extra random data, consider using the -rand option\n";
                BIO_printf(bio_err,
                           "warning, not much extra random data, consider using the -rand option\n",
                           0,0);
                iVar13 = iVar15;
              }
            }
            else {
LAB_0806e513:
              iVar13 = app_RAND_load_files(local_1c8);
              pcVar41 = "%ld semi-random bytes loaded\n";
              BIO_printf(bio_err,"%ld semi-random bytes loaded\n",iVar13);
            }
          }
          else if (local_1c8 != (SSL_SESSION *)0x0) goto LAB_0806e513;
          if (bio_c_out == (BIO *)0x0) {
            if (((c_quiet == 0) || (c_debug != 0)) || (c_msg != 0)) {
              pcVar41 = (char *)0x0;
              iVar13 = c_quiet;
              bio_c_out = BIO_new_fp(stdout,0);
            }
            else {
              pBVar21 = BIO_s_null();
              bio_c_out = BIO_new(pBVar21);
            }
          }
          iVar13 = app_passwd(bio_err,local_1bc,0,&local_148,0,pcVar41,iVar13);
          if (iVar13 == 0) {
            ctx_00 = (SSL_CTX *)0x0;
            BIO_printf(bio_err,"Error getting password\n");
            goto LAB_0806d9f7;
          }
          ctx_00 = SSL_CTX_new(local_200);
          if (ctx_00 == (SSL_CTX *)0x0) {
            ERR_print_errors(bio_err);
            goto LAB_0806d9f7;
          }
          ctx = local_168;
          uVar16 = extraout_EDX;
          if (local_168 != (SSL_CTX *)0x0) {
            ctx = (SSL_CTX *)SSL_CTX_set1_param(ctx_00,(X509_VERIFY_PARAM *)local_168);
            uVar16 = extraout_EDX_00;
          }
          if (e != (ENGINE *)0x0) {
            iVar13 = SSL_CTX_set_client_cert_engine(ctx,(ENGINE *)ctx_00);
            if (iVar13 == 0) {
              BIO_puts(bio_err,"Error setting client auth engine\n");
              ERR_print_errors(bio_err);
              ENGINE_free(e);
              goto LAB_0806d9f7;
            }
            ENGINE_free(e);
            uVar16 = extraout_EDX_01;
          }
          pcVar42 = (code *)psk_key;
          if (psk_key != (SSL_SESSION *)0x0) {
            if (c_debug != 0) {
              BIO_printf(bio_c_out,"PSK key given or JPAKE in use, setting client callback\n",uVar16
                         ,uVar16);
            }
            SSL_CTX_set_psk_client_callback(ctx_00,psk_client_cb);
          }
          if (srtp_profiles != (_func_603 *)0x0) {
            SSL_CTX_set_tlsext_use_srtp(ctx_00,(char *)srtp_profiles);
          }
          if (bVar3) {
            SSL_CTX_ctrl(ctx_00,0x20,local_1e4 | 0x80000bff,(void *)0x0);
          }
          else {
            SSL_CTX_ctrl(ctx_00,0x20,local_1e4,(void *)0x0);
          }
          if (local_1b8 != 0) {
            SSL_CTX_ctrl(ctx_00,0x4d,local_1b8,(void *)0x0);
          }
          if (local_1b0 == 2) {
            SSL_CTX_ctrl(ctx_00,0x29,1,(void *)0x0);
          }
          if (next_proto._0_4_ != (void *)0x0) {
            SSL_CTX_set_next_proto_select_cb(ctx_00,next_proto_cb,next_proto);
          }
          if (bVar1) {
            SSL_CTX_set_info_callback(ctx_00,apps_ssl_info_callback);
          }
          if ((local_1a0 != (_func_603 *)0x0) &&
             (iVar13 = SSL_CTX_set_cipher_list(ctx_00,(char *)local_1a0), iVar13 == 0)) {
            BIO_printf(bio_err,"error setting cipher list\n",0,0);
            ERR_print_errors(bio_err);
            goto LAB_0806d9f7;
          }
          SSL_CTX_set_verify(ctx_00,local_1f8,verify_callback);
          iVar13 = set_cert_key_stuff(ctx_00,a,pkey);
          if (iVar13 == 0) goto LAB_0806d9f7;
          iVar13 = SSL_CTX_load_verify_locations(ctx_00,(char *)local_1a4,(char *)local_1a8);
          if ((iVar13 == 0) ||
             (iVar13 = SSL_CTX_set_default_verify_paths(ctx_00), uVar16 = extraout_EDX_02,
             iVar13 == 0)) {
            ERR_print_errors(bio_err);
            uVar16 = extraout_EDX_04;
          }
          if (local_1c0 != (_func_603 *)0x0) {
            local_150 = bio_err;
            SSL_CTX_callback_ctrl(ctx_00,0x35,ssl_servername_cb);
            SSL_CTX_ctrl(ctx_00,0x36,0,&local_150);
            uVar16 = extraout_EDX_03;
          }
          if (local_144 != (_func_603 *)0x0) {
            if ((!bVar4) &&
               (iVar13 = SSL_CTX_set_srp_username(ctx_00,local_144,uVar16,uVar16), iVar13 == 0)) {
              BIO_printf(bio_err,"Unable to set SRP username\n",0,0);
              goto LAB_0806d9f7;
            }
            local_140 = c_msg;
            local_13c = c_debug;
            SSL_CTX_set_srp_cb_arg(ctx_00,&local_148,pcVar42,pcVar42);
            pcVar42 = ssl_give_srp_client_pwd_cb;
            SSL_CTX_set_srp_client_pwd_callback(ctx_00,ssl_give_srp_client_pwd_cb);
            SSL_CTX_set_srp_strength(ctx_00,local_134);
            if (((c_msg != 0) || (c_debug != 0)) || (local_138 == 0)) {
              SSL_CTX_set_srp_verify_param_callback
                        (ctx_00,ssl_srp_verify_param_cb,extraout_ECX,extraout_ECX);
            }
          }
          to = SSL_new(ctx_00);
          if (local_1e0 == (SSL_SESSION *)0x0) {
LAB_0806e99d:
            if ((local_1c0 == (_func_603 *)0x0) ||
               (lVar14 = SSL_ctrl(to,0x37,0,local_1c0), lVar14 != 0)) {
              bVar3 = true;
              local_1c8 = (SSL_SESSION *)0x1;
              num = a;
              goto LAB_0806e9e0;
            }
            pcVar41 = "Unable to set TLS servername extension.\n";
            local_1e0 = (SSL_SESSION *)pcVar42;
            pSVar43 = (SSL_SESSION *)pcVar42;
          }
          else {
            pSVar43 = (SSL_SESSION *)BIO_new_file((char *)local_1e0,"r");
            if (pSVar43 != (SSL_SESSION *)0x0) {
              pcVar42 = (code *)PEM_read_bio_SSL_SESSION
                                          ((BIO *)pSVar43,(SSL_SESSION **)0x0,(undefined1 *)0x0,
                                           (void *)0x0);
              pSVar43 = (SSL_SESSION *)BIO_free((BIO *)pSVar43);
              if ((SSL_SESSION *)pcVar42 != (SSL_SESSION *)0x0) {
                SSL_set_session(to,(SSL_SESSION *)pcVar42);
                SSL_SESSION_free((SSL_SESSION *)pcVar42);
                goto LAB_0806e99d;
              }
            }
            pcVar41 = "Can\'t open session file %s\n";
          }
          iVar13 = 1;
          BIO_printf(bio_err,pcVar41,local_1e0,pSVar43);
          ERR_print_errors(bio_err);
          goto LAB_0806ee92;
        }
        iVar13 = 6;
        pBVar21 = (BIO_METHOD *)local_180[0]->ssl_version;
        pBVar31 = pBVar21;
        pcVar42 = (code *)"-host";
        do {
          if (iVar13 == 0) break;
          iVar13 = iVar13 + -1;
          bVar37 = (byte)*(code *)&pBVar31->type < (byte)*pcVar42;
          bVar38 = *(code *)&pBVar31->type == *pcVar42;
          pBVar31 = (BIO_METHOD *)((int)pBVar31 + (uint)bVar39 * -2 + 1);
          pcVar42 = pcVar42 + (uint)bVar39 * -2 + 1;
        } while (bVar38);
        bVar37 = (!bVar37 && !bVar38) == bVar37;
        if (bVar37) {
          param_1 = param_1 + -1;
          if (param_1 == 0) goto LAB_0806de18;
          local_170 = (BIO *)local_180[0]->key_arg_length;
          iVar13 = param_1;
          pSVar28 = (SSL_SESSION *)&local_180[0]->key_arg_length;
        }
        else {
          iVar13 = 6;
          pBVar31 = pBVar21;
          pcVar42 = (code *)"-port";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar37 = *(code *)&pBVar31->type == *pcVar42;
            pBVar31 = (BIO_METHOD *)((int)pBVar31 + (uint)bVar39 * -2 + 1);
            pcVar42 = pcVar42 + (uint)bVar39 * -2 + 1;
          } while (bVar37);
          if (bVar37) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              pSVar43 = (SSL_SESSION *)0xa;
              pcVar41 = (char *)0x0;
              pp_Var44 = (_func_603 **)&local_180[0]->key_arg_length;
              local_180[0] = (SSL_SESSION *)&local_180[0]->key_arg_length;
              lVar14 = strtol((char *)*pp_Var44,(char **)0x0,10);
              local_176 = (short)lVar14;
              iVar13 = param_1;
              pSVar28 = local_180[0];
              if (local_176 != 0) goto LAB_0806dcdf;
            }
            goto LAB_0806de18;
          }
          iVar13 = 9;
          pBVar31 = pBVar21;
          pcVar42 = (code *)"-connect";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar37 = *(code *)&pBVar31->type == *pcVar42;
            pBVar31 = (BIO_METHOD *)((int)pBVar31 + (uint)bVar39 * -2 + 1);
            pcVar42 = pcVar42 + (uint)bVar39 * -2 + 1;
          } while (bVar37);
          if (bVar37) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              pSVar43 = (SSL_SESSION *)0x0;
              pcVar41 = (char *)&local_170;
              pp_Var44 = (_func_603 **)&local_180[0]->key_arg_length;
              local_180[0] = (SSL_SESSION *)&local_180[0]->key_arg_length;
              iVar15 = extract_host_port(*pp_Var44,pcVar41,0,&local_176);
              iVar13 = param_1;
              pSVar28 = local_180[0];
              if (iVar15 != 0) goto LAB_0806dcdf;
            }
            goto LAB_0806de18;
          }
          iVar13 = 8;
          pBVar31 = pBVar21;
          pcVar42 = (code *)"-verify";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar37 = *(code *)&pBVar31->type == *pcVar42;
            pBVar31 = (BIO_METHOD *)((int)pBVar31 + (uint)bVar39 * -2 + 1);
            pcVar42 = pcVar42 + (uint)bVar39 * -2 + 1;
          } while (bVar37);
          if (bVar37) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              pp_Var44 = (_func_603 **)&local_180[0]->key_arg_length;
              local_180[0] = (SSL_SESSION *)&local_180[0]->key_arg_length;
              verify_depth = (SSL_SESSION *)strtol((char *)*pp_Var44,(char **)0x0,10);
              pcVar41 = "verify depth is %d\n";
              pSVar43 = verify_depth;
              BIO_printf(bio_err,"verify depth is %d\n");
              local_1f8 = 1;
              iVar13 = param_1;
              pSVar28 = local_180[0];
              goto LAB_0806dcdf;
            }
            goto LAB_0806de18;
          }
          iVar13 = 6;
          pBVar31 = pBVar21;
          pcVar42 = (code *)0x8206f09;
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar37 = *(code *)&pBVar31->type == *pcVar42;
            pBVar31 = (BIO_METHOD *)((int)pBVar31 + (uint)bVar39 * -2 + 1);
            pcVar42 = pcVar42 + (uint)bVar39 * -2 + 1;
          } while (bVar37);
          if (bVar37) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              local_1f4 = (_func_603 *)local_180[0]->key_arg_length;
              iVar13 = param_1;
              pSVar28 = (SSL_SESSION *)&local_180[0]->key_arg_length;
              goto LAB_0806dcdf;
            }
            goto LAB_0806de18;
          }
          iVar13 = 10;
          pBVar31 = pBVar21;
          pcVar42 = (code *)"-sess_out";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar37 = *(code *)&pBVar31->type == *pcVar42;
            pBVar31 = (BIO_METHOD *)((int)pBVar31 + (uint)bVar39 * -2 + 1);
            pcVar42 = pcVar42 + (uint)bVar39 * -2 + 1;
          } while (bVar37);
          if (bVar37) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              local_1ec = (_func_603 *)local_180[0]->key_arg_length;
              iVar13 = param_1;
              pSVar28 = (SSL_SESSION *)&local_180[0]->key_arg_length;
              goto LAB_0806dcdf;
            }
            goto LAB_0806de18;
          }
          iVar13 = 9;
          pBVar31 = pBVar21;
          pcVar42 = (code *)"-sess_in";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar37 = *(code *)&pBVar31->type == *pcVar42;
            pBVar31 = (BIO_METHOD *)((int)pBVar31 + (uint)bVar39 * -2 + 1);
            pcVar42 = pcVar42 + (uint)bVar39 * -2 + 1;
          } while (bVar37);
          if (bVar37) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              local_1e0 = (SSL_SESSION *)local_180[0]->key_arg_length;
              iVar13 = param_1;
              pSVar28 = (SSL_SESSION *)&local_180[0]->key_arg_length;
              goto LAB_0806dcdf;
            }
            goto LAB_0806de18;
          }
          iVar13 = 10;
          pcVar42 = (code *)"-certform";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar37 = *(code *)&pBVar21->type == *pcVar42;
            pBVar21 = (BIO_METHOD *)((int)pBVar21 + (uint)bVar39 * -2 + 1);
            pcVar42 = pcVar42 + (uint)bVar39 * -2 + 1;
          } while (bVar37);
          if (bVar37) {
            param_1 = param_1 + -1;
            if (param_1 != 0) {
              pp_Var44 = (_func_603 **)&local_180[0]->key_arg_length;
              local_180[0] = (SSL_SESSION *)&local_180[0]->key_arg_length;
              local_1dc = str2fmt(*pp_Var44);
              iVar13 = param_1;
              pSVar28 = local_180[0];
              goto LAB_0806dcdf;
            }
            goto LAB_0806de18;
          }
          pSVar17 = (SSL_SESSION *)
                    args_verify(local_180,&param_1,&local_164,bio_err,&local_168,pcVar41,pSVar43);
          pSVar27 = local_180[0];
          bVar37 = pSVar17 == (SSL_SESSION *)0x0;
          if (!bVar37) {
            if (local_164 != 0) goto LAB_0806de18;
            goto LAB_0806dcf3;
          }
          iVar13 = 0x15;
          __s1_00 = (SSL_SESSION *)local_180[0]->ssl_version;
          pSVar28 = __s1_00;
          pcVar34 = "-verify_return_error";
          do {
            if (iVar13 == 0) break;
            iVar13 = iVar13 + -1;
            bVar37 = *(char *)&pSVar28->ssl_version == *pcVar34;
            pSVar28 = (SSL_SESSION *)((int)pSVar28 + (uint)bVar39 * -2 + 1);
            pcVar34 = pcVar34 + (uint)bVar39 * -2 + 1;
          } while (bVar37);
          iVar13 = param_1;
          pSVar28 = pSVar27;
          if (bVar37) {
            verify_return_error = 1;
          }
          else {
            iVar15 = 8;
            pSVar26 = __s1_00;
            pcVar34 = "-prexit";
            do {
              if (iVar15 == 0) break;
              iVar15 = iVar15 + -1;
              bVar37 = *(char *)&pSVar26->ssl_version == *pcVar34;
              pSVar26 = (SSL_SESSION *)((int)pSVar26 + (uint)bVar39 * -2 + 1);
              pcVar34 = pcVar34 + (uint)bVar39 * -2 + 1;
            } while (bVar37);
            if (bVar37) {
              bVar9 = true;
              goto LAB_0806dcdf;
            }
            iVar15 = 6;
            pSVar26 = __s1_00;
            pSVar36 = (SSL_SESSION *)&DAT_081f4a80;
            do {
              pSVar32 = pSVar26;
              pSVar35 = pSVar36;
              if (iVar15 == 0) break;
              iVar15 = iVar15 + -1;
              pSVar35 = (SSL_SESSION *)((int)pSVar36 + (uint)bVar39 * -2 + 1);
              pSVar32 = (SSL_SESSION *)((int)pSVar26 + (uint)bVar39 * -2 + 1);
              bVar37 = *(char *)&pSVar26->ssl_version == *(char *)&pSVar36->ssl_version;
              pSVar26 = pSVar32;
              pSVar36 = pSVar35;
            } while (bVar37);
            if (bVar37) {
              bVar10 = true;
            }
            else {
              pcVar41 = "-quiet";
              iVar13 = strcmp((char *)__s1_00,"-quiet");
              if (iVar13 == 0) {
                c_quiet = 1;
                c_ign_eof = 1;
                iVar13 = param_1;
                pSVar43 = pSVar17;
              }
              else {
                pcVar41 = "-ign_eof";
                pSVar43 = pSVar35;
                iVar13 = strcmp((char *)__s1_00,"-ign_eof");
                if (iVar13 == 0) {
                  c_ign_eof = 1;
                  iVar13 = param_1;
                }
                else {
                  pcVar41 = "-no_ign_eof";
                  pSVar43 = pSVar32;
                  iVar13 = strcmp((char *)__s1_00,"-no_ign_eof");
                  if (iVar13 == 0) {
                    c_ign_eof = 0;
                    iVar13 = param_1;
                  }
                  else {
                    pcVar41 = "-pause";
                    pSVar43 = extraout_ECX_05;
                    iVar13 = strcmp((char *)__s1_00,"-pause");
                    if (iVar13 == 0) {
                      c_Pause = 1;
                      iVar13 = param_1;
                    }
                    else {
                      pcVar41 = &DAT_081ecb03;
                      pSVar43 = extraout_EDX_05;
                      pSVar17 = (SSL_SESSION *)strcmp((char *)__s1_00,"-debug");
                      if (pSVar17 == (SSL_SESSION *)0x0) {
                        c_debug = 1;
                        iVar13 = param_1;
                      }
                      else {
                        pcVar41 = "-tlsextdebug";
                        pSVar43 = (SSL_SESSION *)strcmp((char *)__s1_00,"-tlsextdebug");
                        if (pSVar43 == (SSL_SESSION *)0x0) {
                          c_tlsextdebug = 1;
                          iVar13 = param_1;
                          pSVar43 = pSVar17;
                        }
                        else {
                          pcVar41 = "-status";
                          pSVar17 = (SSL_SESSION *)strcmp((char *)__s1_00,"-status");
                          if (pSVar17 == (SSL_SESSION *)0x0) {
                            c_status_req = 1;
                            iVar13 = param_1;
                          }
                          else {
                            pcVar41 = &DAT_081f4a6e;
                            pSVar43 = (SSL_SESSION *)strcmp((char *)__s1_00,"-msg");
                            if (pSVar43 == (SSL_SESSION *)0x0) {
                              c_msg = 1;
                              iVar13 = param_1;
                              pSVar43 = pSVar17;
                            }
                            else {
                              pcVar41 = "-showcerts";
                              pSVar17 = (SSL_SESSION *)strcmp((char *)__s1_00,"-showcerts");
                              if (pSVar17 == (SSL_SESSION *)0x0) {
                                c_showcerts = 1;
                                iVar13 = param_1;
                              }
                              else {
                                pcVar41 = "-nbio_test";
                                pSVar43 = (SSL_SESSION *)strcmp((char *)__s1_00,"-nbio_test");
                                if (pSVar43 == (SSL_SESSION *)0x0) {
                                  bVar5 = true;
                                  iVar13 = param_1;
                                  pSVar43 = pSVar17;
                                }
                                else {
                                  pcVar41 = "-state";
                                  iVar13 = strcmp((char *)__s1_00,"-state");
                                  if (iVar13 == 0) {
                                    bVar1 = true;
                                    iVar13 = param_1;
                                  }
                                  else {
                                    pcVar41 = "-psk_identity";
                                    pSVar43 = pSVar35;
                                    iVar13 = strcmp((char *)__s1_00,"-psk_identity");
                                    if (iVar13 == 0) {
                                      param_1 = param_1 + -1;
                                      if (param_1 < 1) goto LAB_0806de18;
                                      psk_identity = (undefined *)pSVar27->key_arg_length;
                                      iVar13 = param_1;
                                      pSVar28 = (SSL_SESSION *)&pSVar27->key_arg_length;
                                    }
                                    else {
                                      pcVar41 = &DAT_081f4ab4;
                                      pSVar43 = pSVar32;
                                      iVar13 = strcmp((char *)__s1_00,"-psk");
                                      if (iVar13 == 0) {
                                        iVar13 = param_1 + -1;
                                        param_1 = iVar13;
                                        if (iVar13 < 1) goto LAB_0806de18;
                                        pSVar28 = (SSL_SESSION *)&pSVar27->key_arg_length;
                                        pSVar27 = (SSL_SESSION *)pSVar27->key_arg_length;
                                        uVar29 = 0xffffffff;
                                        pSVar17 = pSVar27;
                                        do {
                                          if (uVar29 == 0) break;
                                          uVar29 = uVar29 - 1;
                                          ppBVar12 = (BIO_METHOD **)&pSVar17->ssl_version;
                                          pSVar17 = (SSL_SESSION *)
                                                    ((int)pSVar17 + (uint)bVar39 * -2 + 1);
                                        } while (*(char *)ppBVar12 != '\0');
                                        psk_key = pSVar27;
                                        local_180[0] = pSVar28;
                                        for (iVar15 = 0; iVar15 != ~uVar29 - 1; iVar15 = iVar15 + 1)
                                        {
                                          ppuVar25 = __ctype_b_loc();
                                          if ((*(byte *)((int)*ppuVar25 +
                                                        (uint)*(byte *)((int)pSVar27->key_arg +
                                                                       iVar15 + -8) * 2 + 1) & 0x10)
                                              == 0) {
                                            BIO_printf(bio_err,"Not a hex number \'%s\'\n",pSVar27,
                                                       extraout_ECX_08);
                                            pSVar43 = pSVar27;
                                            goto LAB_0806de18;
                                          }
                                        }
                                      }
                                      else {
                                        pcVar41 = "-srpuser";
                                        pSVar43 = extraout_EDX_09;
                                        pSVar17 = (SSL_SESSION *)strcmp((char *)__s1_00,"-srpuser");
                                        if (pSVar17 == (SSL_SESSION *)0x0) {
                                          param_1 = param_1 + -1;
                                          if (param_1 < 1) goto LAB_0806de18;
                                          local_180[0] = (SSL_SESSION *)&pSVar27->key_arg_length;
                                          local_144 = (_func_603 *)pSVar27->key_arg_length;
LAB_080700c0:
                                          local_200 = TLSv1_client_method();
                                          iVar13 = param_1;
                                          pSVar28 = local_180[0];
                                        }
                                        else {
                                          pcVar41 = "-srppass";
                                          pSVar26 = (SSL_SESSION *)
                                                    strcmp((char *)__s1_00,"-srppass");
                                          if (pSVar26 == (SSL_SESSION *)0x0) {
                                            param_1 = param_1 + -1;
                                            pSVar43 = pSVar17;
                                            if (param_1 < 1) goto LAB_0806de18;
                                            local_180[0] = (SSL_SESSION *)&pSVar27->key_arg_length;
                                            local_1bc = (_func_603 *)pSVar27->key_arg_length;
                                            local_200 = TLSv1_client_method();
                                            iVar13 = param_1;
                                            pSVar28 = local_180[0];
                                            pSVar43 = pSVar17;
                                          }
                                          else {
                                            pSVar43 = (SSL_SESSION *)
                                                      strcmp((char *)__s1_00,"-srp_strength");
                                            if (pSVar43 == (SSL_SESSION *)0x0) {
                                              param_1 = param_1 + -1;
                                              pSVar43 = pSVar26;
                                              if (param_1 < 1) goto LAB_0806de18;
                                              pp_Var44 = (_func_603 **)&pSVar27->key_arg_length;
                                              local_180[0] = (SSL_SESSION *)pp_Var44;
                                              pSVar43 = (SSL_SESSION *)
                                                        strtol((char *)pSVar27->key_arg_length,
                                                               (char **)0x0,10);
                                              pcVar41 = "SRP minimal length for N is %d\n";
                                              local_134 = pSVar43;
                                              BIO_printf(bio_err,"SRP minimal length for N is %d\n",
                                                         pSVar43,pp_Var44);
                                              local_200 = TLSv1_client_method();
                                              iVar13 = param_1;
                                              pSVar28 = local_180[0];
                                            }
                                            else {
                                              pcVar41 = "-srp_lateuser";
                                              pSVar17 = (SSL_SESSION *)
                                                        strcmp((char *)__s1_00,"-srp_lateuser");
                                              if (pSVar17 == (SSL_SESSION *)0x0) {
                                                local_200 = TLSv1_client_method();
                                                bVar4 = true;
                                                iVar13 = param_1;
                                                pSVar28 = local_180[0];
                                              }
                                              else {
                                                pcVar41 = "-srp_moregroups";
                                                pSVar43 = (SSL_SESSION *)
                                                          strcmp((char *)__s1_00,"-srp_moregroups");
                                                if (pSVar43 == (SSL_SESSION *)0x0) {
                                                  local_138 = 1;
                                                  local_200 = TLSv1_client_method();
                                                  iVar13 = param_1;
                                                  pSVar28 = local_180[0];
                                                  pSVar43 = pSVar17;
                                                }
                                                else {
                                                  pcVar41 = "-ssl2";
                                                  iVar13 = strcmp((char *)__s1_00,"-ssl2");
                                                  if (iVar13 == 0) {
                                                    local_200 = SSLv2_client_method();
                                                    iVar13 = param_1;
                                                    pSVar28 = local_180[0];
                                                  }
                                                  else {
                                                    pcVar41 = "-ssl3";
                                                    pSVar43 = pSVar35;
                                                    iVar13 = strcmp((char *)__s1_00,"-ssl3");
                                                    if (iVar13 == 0) {
                                                      local_200 = SSLv3_client_method();
                                                      iVar13 = param_1;
                                                      pSVar28 = local_180[0];
                                                    }
                                                    else {
                                                      pcVar41 = "-tls1_2";
                                                      pSVar43 = pSVar32;
                                                      iVar13 = strcmp((char *)__s1_00,"-tls1_2");
                                                      if (iVar13 == 0) {
                                                        local_200 = TLSv1_2_client_method();
                                                        iVar13 = param_1;
                                                        pSVar28 = local_180[0];
                                                      }
                                                      else {
                                                        pcVar41 = "-tls1_1";
                                                        pSVar43 = extraout_ECX_09;
                                                        iVar13 = strcmp((char *)__s1_00,"-tls1_1");
                                                        if (iVar13 == 0) {
                                                          local_200 = TLSv1_1_client_method();
                                                          iVar13 = param_1;
                                                          pSVar28 = local_180[0];
                                                        }
                                                        else {
                                                          pcVar41 = "-tls1";
                                                          pSVar43 = extraout_EDX_10;
                                                          pSVar17 = (SSL_SESSION *)
                                                                    strcmp((char *)__s1_00,"-tls1");
                                                          if (pSVar17 == (SSL_SESSION *)0x0)
                                                          goto LAB_080700c0;
                                                          pcVar41 = "-dtls1";
                                                          pSVar26 = (SSL_SESSION *)
                                                                    strcmp((char *)__s1_00,"-dtls1")
                                                          ;
                                                          if (pSVar26 == (SSL_SESSION *)0x0) {
                                                            local_200 = DTLSv1_client_method();
                                                            local_1b0 = 2;
                                                            iVar13 = param_1;
                                                            pSVar28 = local_180[0];
                                                            pSVar43 = pSVar17;
                                                          }
                                                          else {
                                                            pcVar41 = "-timeout";
                                                            pSVar43 = (SSL_SESSION *)
                                                                      strcmp((char *)__s1_00,
                                                                             "-timeout");
                                                            if (pSVar43 == (SSL_SESSION *)0x0) {
                                                              bVar11 = true;
                                                              iVar13 = param_1;
                                                              pSVar43 = pSVar26;
                                                            }
                                                            else {
                                                              pSVar17 = (SSL_SESSION *)
                                                                        strcmp((char *)__s1_00,
                                                                               "-mtu");
                                                              if (pSVar17 == (SSL_SESSION *)0x0) {
                                                                param_1 = param_1 + -1;
                                                                if (param_1 < 1) goto LAB_0806de18;
                                                                local_180[0] = (SSL_SESSION *)
                                                                               &pSVar27->
                                                  key_arg_length;
                                                  pSVar43 = (SSL_SESSION *)0xa;
                                                  pcVar41 = (char *)0x0;
                                                  local_18c = strtol((char *)pSVar27->key_arg_length
                                                                     ,(char **)0x0,10);
                                                  iVar13 = param_1;
                                                  pSVar28 = local_180[0];
                                                  }
                                                  else {
                                                    pcVar41 = "-bugs";
                                                    pSVar43 = (SSL_SESSION *)
                                                              strcmp((char *)__s1_00,"-bugs");
                                                    if (pSVar43 == (SSL_SESSION *)0x0) {
                                                      bVar3 = true;
                                                      iVar13 = param_1;
                                                      pSVar43 = pSVar17;
                                                    }
                                                    else {
                                                      pcVar41 = "-keyform";
                                                      pSVar17 = pSVar43;
                                                      iVar13 = strcmp((char *)__s1_00,"-keyform");
                                                      if (iVar13 == 0) {
                                                        param_1 = param_1 + -1;
                                                        if (param_1 < 1) goto LAB_0806de18;
                                                        local_180[0] = (SSL_SESSION *)
                                                                       &pSVar27->key_arg_length;
                                                        local_1c4 = (timeval *)
                                                                    str2fmt((_func_603 *)
                                                                            pSVar27->key_arg_length,
                                                                            pcVar41,pSVar43,pSVar17)
                                                        ;
                                                        iVar13 = param_1;
                                                        pSVar28 = local_180[0];
                                                      }
                                                      else {
                                                        pcVar41 = "-pass";
                                                        pSVar43 = pSVar35;
                                                        iVar13 = strcmp((char *)__s1_00,"-pass");
                                                        if (iVar13 == 0) {
                                                          param_1 = param_1 + -1;
                                                          if (param_1 < 1) goto LAB_0806de18;
                                                          local_1d4 = (_func_603 *)
                                                                      pSVar27->key_arg_length;
                                                          iVar13 = param_1;
                                                          pSVar28 = (SSL_SESSION *)
                                                                    &pSVar27->key_arg_length;
                                                        }
                                                        else {
                                                          pcVar41 = "-key";
                                                          pSVar43 = pSVar32;
                                                          iVar13 = strcmp((char *)__s1_00,"-key");
                                                          if (iVar13 == 0) {
                                                            param_1 = param_1 + -1;
                                                            if (param_1 < 1) goto LAB_0806de18;
                                                            local_1d8 = (_func_603 *)
                                                                        pSVar27->key_arg_length;
                                                            iVar13 = param_1;
                                                            pSVar28 = (SSL_SESSION *)
                                                                      &pSVar27->key_arg_length;
                                                          }
                                                          else {
                                                            pcVar41 = "-reconnect";
                                                            pSVar43 = extraout_ECX_10;
                                                            iVar13 = strcmp((char *)__s1_00,
                                                                            "-reconnect");
                                                            if (iVar13 == 0) {
                                                              local_1b4 = 5;
                                                              iVar13 = param_1;
                                                            }
                                                            else {
                                                              pcVar41 = "-CApath";
                                                              pSVar43 = extraout_EDX_11;
                                                              pSVar17 = (SSL_SESSION *)
                                                                        strcmp((char *)__s1_00,
                                                                               "-CApath");
                                                              if (pSVar17 == (SSL_SESSION *)0x0) {
                                                                param_1 = param_1 + -1;
                                                                if (param_1 < 1) goto LAB_0806de18;
                                                                local_1a8 = (_func_603 *)
                                                                            pSVar27->key_arg_length;
                                                                iVar13 = param_1;
                                                                pSVar28 = (SSL_SESSION *)
                                                                          &pSVar27->key_arg_length;
                                                              }
                                                              else {
                                                                pcVar41 = "-CAfile";
                                                                pSVar43 = (SSL_SESSION *)
                                                                          strcmp((char *)__s1_00,
                                                                                 "-CAfile");
                                                                if (pSVar43 == (SSL_SESSION *)0x0) {
                                                                  param_1 = param_1 + -1;
                                                                  pSVar43 = pSVar17;
                                                                  if (param_1 < 1)
                                                                  goto LAB_0806de18;
                                                                  local_1a4 = (_func_603 *)
                                                                              pSVar27->
                                                  key_arg_length;
                                                  iVar13 = param_1;
                                                  pSVar28 = (SSL_SESSION *)&pSVar27->key_arg_length;
                                                  }
                                                  else {
                                                    pcVar41 = "-no_tls1_2";
                                                    pSVar17 = (SSL_SESSION *)
                                                              strcmp((char *)__s1_00,"-no_tls1_2");
                                                    if (pSVar17 == (SSL_SESSION *)0x0) {
                                                      local_1e4 = local_1e4 | 0x8000000;
                                                      iVar13 = param_1;
                                                    }
                                                    else {
                                                      pcVar41 = "-no_tls1_1";
                                                      pSVar43 = (SSL_SESSION *)
                                                                strcmp((char *)__s1_00,"-no_tls1_1")
                                                      ;
                                                      if (pSVar43 == (SSL_SESSION *)0x0) {
                                                        local_1e4 = local_1e4 | 0x10000000;
                                                        iVar13 = param_1;
                                                        pSVar43 = pSVar17;
                                                      }
                                                      else {
                                                        pcVar41 = "-no_tls1";
                                                        pSVar17 = (SSL_SESSION *)
                                                                  strcmp((char *)__s1_00,"-no_tls1")
                                                        ;
                                                        if (pSVar17 == (SSL_SESSION *)0x0) {
                                                          local_1e4 = local_1e4 | 0x4000000;
                                                          iVar13 = param_1;
                                                        }
                                                        else {
                                                          pcVar41 = "-no_ssl3";
                                                          pSVar43 = (SSL_SESSION *)
                                                                    strcmp((char *)__s1_00,
                                                                           "-no_ssl3");
                                                          if (pSVar43 == (SSL_SESSION *)0x0) {
                                                            local_1e4 = local_1e4 | 0x2000000;
                                                            iVar13 = param_1;
                                                            pSVar43 = pSVar17;
                                                          }
                                                          else {
                                                            pcVar41 = "-no_ssl2";
                                                            iVar13 = strcmp((char *)__s1_00,
                                                                            "-no_ssl2");
                                                            if (iVar13 == 0) {
                                                              local_1e4 = local_1e4 | 0x1000000;
                                                              iVar13 = param_1;
                                                            }
                                                            else {
                                                              pcVar41 = "-no_comp";
                                                              pSVar43 = pSVar35;
                                                              iVar13 = strcmp((char *)__s1_00,
                                                                              "-no_comp");
                                                              if (iVar13 == 0) {
                                                                local_1e4 = local_1e4 | 0x20000;
                                                                iVar13 = param_1;
                                                              }
                                                              else {
                                                                pcVar41 = "-no_ticket";
                                                                pSVar43 = pSVar32;
                                                                iVar13 = strcmp((char *)__s1_00,
                                                                                "-no_ticket");
                                                                if (iVar13 == 0) {
                                                                  local_1e4 = local_1e4 | 0x4000;
                                                                  iVar13 = param_1;
                                                                }
                                                                else {
                                                                  pcVar41 = "-nextprotoneg";
                                                                  pSVar43 = extraout_ECX_11;
                                                                  iVar13 = strcmp((char *)__s1_00,
                                                                                  "-nextprotoneg");
                                                                  if (iVar13 == 0) {
                                                                    param_1 = param_1 + -1;
                                                                    if (param_1 < 1)
                                                                    goto LAB_0806de18;
                                                                    local_1f0 = (_func_603 *)
                                                                                pSVar27->
                                                  key_arg_length;
                                                  iVar13 = param_1;
                                                  pSVar28 = (SSL_SESSION *)&pSVar27->key_arg_length;
                                                  }
                                                  else {
                                                    pcVar41 = "-serverpref";
                                                    pSVar17 = extraout_EDX_12;
                                                    pSVar43 = (SSL_SESSION *)
                                                              strcmp((char *)__s1_00,"-serverpref");
                                                    if (pSVar43 == (SSL_SESSION *)0x0) {
                                                      local_1e4 = local_1e4 | 0x400000;
                                                      iVar13 = param_1;
                                                      pSVar43 = pSVar17;
                                                    }
                                                    else {
                                                      pcVar41 = "-legacy_renegotiation";
                                                      pSVar17 = (SSL_SESSION *)
                                                                strcmp((char *)__s1_00,
                                                                       "-legacy_renegotiation");
                                                      if (pSVar17 == (SSL_SESSION *)0x0) {
                                                        local_1e4 = local_1e4 | 0x40000;
                                                        iVar13 = param_1;
                                                      }
                                                      else {
                                                        pcVar41 = "-legacy_server_connect";
                                                        pSVar43 = (SSL_SESSION *)
                                                                  strcmp((char *)__s1_00,
                                                                         "-legacy_server_connect");
                                                        if (pSVar43 == (SSL_SESSION *)0x0) {
                                                          local_1e4 = local_1e4 | 4;
                                                          iVar13 = param_1;
                                                          pSVar43 = pSVar17;
                                                        }
                                                        else {
                                                          pcVar41 = "-no_legacy_server_connect";
                                                          pSVar17 = (SSL_SESSION *)
                                                                    strcmp((char *)__s1_00,
                                                                                                                                                      
                                                  "-no_legacy_server_connect");
                                                  if (pSVar17 == (SSL_SESSION *)0x0) {
                                                    local_1b8 = 4;
                                                    iVar13 = param_1;
                                                  }
                                                  else {
                                                    pcVar41 = "-cipher";
                                                    pSVar43 = (SSL_SESSION *)
                                                              strcmp((char *)__s1_00,"-cipher");
                                                    if (pSVar43 == (SSL_SESSION *)0x0) {
                                                      param_1 = param_1 + -1;
                                                      pSVar43 = pSVar17;
                                                      if (param_1 < 1) goto LAB_0806de18;
                                                      local_1a0 = (_func_603 *)
                                                                  pSVar27->key_arg_length;
                                                      iVar13 = param_1;
                                                      pSVar28 = (SSL_SESSION *)
                                                                &pSVar27->key_arg_length;
                                                    }
                                                    else {
                                                      pcVar41 = "-nbio";
                                                      pSVar17 = (SSL_SESSION *)
                                                                strcmp((char *)__s1_00,"-nbio");
                                                      if (pSVar17 == (SSL_SESSION *)0x0) {
                                                        c_nbio = 1;
                                                        iVar13 = param_1;
                                                      }
                                                      else {
                                                        pSVar43 = (SSL_SESSION *)
                                                                  strcmp((char *)__s1_00,"-starttls"
                                                                        );
                                                        if (pSVar43 == (SSL_SESSION *)0x0) {
                                                          iVar13 = param_1 + -1;
                                                          param_1 = iVar13;
                                                          pSVar43 = pSVar17;
                                                          if (iVar13 < 1) goto LAB_0806de18;
                                                          __s1 = (_func_603 *)
                                                                 pSVar27->key_arg_length;
                                                          pSVar28 = (SSL_SESSION *)
                                                                    &pSVar27->key_arg_length;
                                                          pcVar41 = &DAT_081f4f72;
                                                          local_180[0] = pSVar28;
                                                          iVar15 = strcmp((char *)__s1,"smtp");
                                                          if (iVar15 == 0) {
                                                            local_1e8 = 1;
                                                            pSVar43 = pSVar27;
                                                          }
                                                          else {
                                                            pcVar41 = &DAT_081f4f77;
                                                            pSVar43 = extraout_ECX_12;
                                                            iVar15 = strcmp((char *)__s1,"pop3");
                                                            if (iVar15 == 0) {
                                                              local_1e8 = 2;
                                                            }
                                                            else {
                                                              pcVar41 = &DAT_081f4f7c;
                                                              pSVar43 = extraout_EDX_13;
                                                              pSVar27 = (SSL_SESSION *)
                                                                        strcmp((char *)__s1,"imap");
                                                              if (pSVar27 == (SSL_SESSION *)0x0) {
                                                                local_1e8 = 3;
                                                              }
                                                              else if ((((*__s1 == (_func_603)0x66)
                                                                        && (__s1[1] ==
                                                                            (_func_603)0x74)) &&
                                                                       (__s1[2] == (_func_603)0x70))
                                                                      && (__s1[3] == (_func_603)0x0)
                                                                      ) {
                                                                local_1e8 = 4;
                                                              }
                                                              else {
                                                                pcVar41 = &DAT_081f4f81;
                                                                iVar15 = strcmp((char *)__s1,"xmpp")
                                                                ;
                                                                pSVar43 = pSVar27;
                                                                if (iVar15 != 0) goto LAB_0806de18;
                                                                local_1e8 = 5;
                                                              }
                                                            }
                                                          }
                                                        }
                                                        else {
                                                          pcVar41 = "-engine";
                                                          pSVar28 = (SSL_SESSION *)
                                                                    strcmp((char *)__s1_00,"-engine"
                                                                          );
                                                          if (pSVar28 == (SSL_SESSION *)0x0) {
                                                            param_1 = param_1 + -1;
                                                            if (param_1 < 1) goto LAB_0806de18;
                                                            local_1d0 = (_func_603 *)
                                                                        pSVar27->key_arg_length;
                                                            iVar13 = param_1;
                                                            pSVar28 = (SSL_SESSION *)
                                                                      &pSVar27->key_arg_length;
                                                          }
                                                          else {
                                                            pcVar41 = "-ssl_client_engine";
                                                            pSVar43 = (SSL_SESSION *)
                                                                      strcmp((char *)__s1_00,
                                                                             "-ssl_client_engine");
                                                            if (pSVar43 == (SSL_SESSION *)0x0) {
                                                              param_1 = param_1 + -1;
                                                              pSVar43 = pSVar28;
                                                              if (param_1 < 1) goto LAB_0806de18;
                                                              local_1cc = (_func_603 *)
                                                                          pSVar27->key_arg_length;
                                                              iVar13 = param_1;
                                                              pSVar28 = (SSL_SESSION *)
                                                                        &pSVar27->key_arg_length;
                                                            }
                                                            else {
                                                              pcVar41 = "-rand";
                                                              pSVar28 = (SSL_SESSION *)
                                                                        strcmp((char *)__s1_00,
                                                                               "-rand");
                                                              if (pSVar28 == (SSL_SESSION *)0x0) {
                                                                param_1 = param_1 + -1;
                                                                if (param_1 < 1) goto LAB_0806de18;
                                                                local_1c8 = (SSL_SESSION *)
                                                                            pSVar27->key_arg_length;
                                                                iVar13 = param_1;
                                                                pSVar28 = (SSL_SESSION *)
                                                                          &pSVar27->key_arg_length;
                                                              }
                                                              else {
                                                                pcVar41 = "-servername";
                                                                pSVar43 = (SSL_SESSION *)
                                                                          strcmp((char *)__s1_00,
                                                                                 "-servername");
                                                                if (pSVar43 == (SSL_SESSION *)0x0) {
                                                                  param_1 = param_1 + -1;
                                                                  pSVar43 = pSVar28;
                                                                  if (param_1 < 1)
                                                                  goto LAB_0806de18;
                                                                  local_1c0 = (_func_603 *)
                                                                              pSVar27->
                                                  key_arg_length;
                                                  iVar13 = param_1;
                                                  pSVar28 = (SSL_SESSION *)&pSVar27->key_arg_length;
                                                  }
                                                  else {
                                                    pcVar41 = "-use_srtp";
                                                    iVar13 = strcmp((char *)__s1_00,"-use_srtp");
                                                    if (iVar13 == 0) {
                                                      param_1 = param_1 + -1;
                                                      if (param_1 < 1) goto LAB_0806de18;
                                                      srtp_profiles =
                                                           (_func_603 *)pSVar27->key_arg_length;
                                                      iVar13 = param_1;
                                                      pSVar28 = (SSL_SESSION *)
                                                                &pSVar27->key_arg_length;
                                                    }
                                                    else {
                                                      pcVar41 = "-keymatexport";
                                                      iVar13 = strcmp((char *)__s1_00,
                                                                      "-keymatexport");
                                                      if (iVar13 == 0) {
                                                        param_1 = param_1 + -1;
                                                        pSVar43 = pSVar35;
                                                        if (param_1 < 1) goto LAB_0806de18;
                                                        keymatexportlabel =
                                                             (_func_603 *)pSVar27->key_arg_length;
                                                        iVar13 = param_1;
                                                        pSVar28 = (SSL_SESSION *)
                                                                  &pSVar27->key_arg_length;
                                                      }
                                                      else {
                                                        iVar13 = strcmp((char *)__s1_00,
                                                                        "-keymatexportlen");
                                                        if (iVar13 != 0) {
                                                          BIO_printf(bio_err,"unknown option %s\n",
                                                                     __s1_00,extraout_ECX_13);
                                                          pSVar43 = __s1_00;
                                                          goto LAB_0806de18;
                                                        }
                                                        param_1 = param_1 + -1;
                                                        pSVar43 = pSVar32;
                                                        if (param_1 < 1) goto LAB_0806de18;
                                                        local_180[0] = (SSL_SESSION *)
                                                                       &pSVar27->key_arg_length;
                                                        pSVar43 = (SSL_SESSION *)0xa;
                                                        pcVar41 = (char *)0x0;
                                                        keymatexportlen =
                                                             strtol((char *)pSVar27->key_arg_length,
                                                                    (char **)0x0,10);
                                                        iVar13 = param_1;
                                                        pSVar28 = local_180[0];
                                                        if (keymatexportlen == 0) goto LAB_0806de18;
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
LAB_0806dcdf:
        param_1 = iVar13 + -1;
        local_180[0] = (SSL_SESSION *)&pSVar28->key_arg_length;
        goto LAB_0806dcf3;
      }
    }
    ctx_00 = (SSL_CTX *)0x0;
    pkey = (EVP_PKEY *)0x0;
    a = (X509 *)0x0;
    BIO_printf(bio_err,"out of memory\n");
    local_208 = (char *)0x0;
  }
LAB_0806d9f7:
  iVar13 = 1;
  if (next_proto._0_4_ != (void *)0x0) {
LAB_0806da05:
    CRYPTO_free(next_proto._0_4_);
  }
  if (ctx_00 != (SSL_CTX *)0x0) {
LAB_0806da15:
    SSL_CTX_free(ctx_00);
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
  if (local_168 != (SSL_CTX *)0x0) {
    X509_VERIFY_PARAM_free((X509_VERIFY_PARAM *)local_168);
  }
  if (local_204 != (byte *)0x0) {
    OPENSSL_cleanse(local_204,0x2000);
    CRYPTO_free(local_204);
  }
  if (local_20c != (char *)0x0) {
    OPENSSL_cleanse(local_20c,0x2000);
    CRYPTO_free(local_20c);
  }
  if (local_208 != (char *)0x0) {
    OPENSSL_cleanse(local_208,0x2000);
    CRYPTO_free(local_208);
  }
  if (bio_c_out != (BIO *)0x0) {
    BIO_free(bio_c_out);
    bio_c_out = (BIO *)0x0;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar13;
LAB_0806e9e0:
  iVar13 = init_client(&local_174,local_170,(int)local_176,local_1b0);
  if (iVar13 == 0) goto LAB_0806fe8e;
  BIO_printf(bio_c_out,"CONNECTED(%08X)\n",local_174,pcVar42);
  if (c_nbio != 0) {
    local_15c = 1;
    BIO_printf(bio_c_out,"turning on non blocking io\n",num,num);
    iVar13 = BIO_socket_ioctl(local_174,0x5421,&local_15c);
    if (iVar13 < 0) {
      iVar13 = 1;
      ERR_print_errors(bio_err);
      goto LAB_0806ee92;
    }
  }
  if ((c_Pause & 1) != 0) {
    SSL_set_debug(to,1);
  }
  iVar13 = SSL_version(to);
  if (iVar13 == 0xfeff) {
    pBVar18 = BIO_new_dgram(local_174,0);
    iVar13 = getsockname(local_174,&local_130,&local_160);
    if (iVar13 < 0) {
      piVar24 = __errno_location();
      iVar13 = *piVar24;
      pcVar41 = "getsockname:errno=%d\n";
      uVar16 = extraout_EDX_07;
      goto LAB_0806fdee;
    }
    BIO_ctrl(pBVar18,0x20,1,&local_130);
    if (bVar11) {
      local_158.tv_sec = 0;
      local_158.tv_usec = 250000;
      BIO_ctrl(pBVar18,0x21,0,&local_158);
      local_158.tv_sec = 0;
      local_158.tv_usec = 250000;
      BIO_ctrl(pBVar18,0x23,0,&local_158);
    }
    if (local_18c < 0x1d) {
      BIO_ctrl(pBVar18,0x27,0,(void *)0x0);
    }
    else {
      SSL_ctrl(to,0x20,0x1000,(void *)0x0);
      SSL_ctrl(to,0x11,local_18c + -0x1c,(void *)0x0);
    }
  }
  else {
    pBVar18 = BIO_new_socket(local_174,0);
  }
  if (bVar5) {
    pBVar21 = BIO_f_nbio_test();
    pBVar22 = BIO_new(pBVar21);
    pBVar18 = BIO_push(pBVar22,pBVar18);
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
    SSL_CTX_callback_ctrl(ctx_00,0x3f,ocsp_resp_cb);
    SSL_CTX_ctrl(ctx_00,0x40,0,bio_c_out);
  }
  SSL_set_bio(to,pBVar18,pBVar18);
  SSL_set_connect_state(to);
  iVar13 = SSL_get_fd(to);
  if (local_1e8 == 1) {
    pBVar21 = BIO_f_buffer();
    pBVar22 = BIO_new(pBVar21);
    BIO_push(pBVar22,pBVar18);
    do {
      iVar15 = BIO_gets(pBVar22,local_208,0x2000);
      if (iVar15 < 4) break;
    } while (local_208[3] == '-');
    bVar1 = false;
    BIO_printf(pBVar22,"EHLO openssl.client.net\r\n",extraout_ECX_04,extraout_ECX_04);
    BIO_ctrl(pBVar22,0xb,0,(void *)0x0);
    do {
      iVar15 = BIO_gets(pBVar22,local_208,0x2000);
      pcVar41 = strstr(local_208,"STARTTLS");
      if (pcVar41 != (char *)0x0) {
        bVar1 = true;
      }
    } while ((3 < iVar15) && (local_208[3] == '-'));
    BIO_ctrl(pBVar22,0xb,0,(void *)0x0);
    BIO_pop(pBVar22);
    iVar15 = BIO_free(pBVar22);
    if (!bVar1) {
      iVar15 = BIO_printf(bio_err,"didn\'t found starttls in server response, try anyway...\n",
                          iVar15,iVar15);
    }
    pcVar41 = "STARTTLS\r\n";
    iVar20 = iVar15;
  }
  else if (local_1e8 == 2) {
    iVar15 = 0x2000;
    iVar20 = extraout_ECX_00;
    BIO_read(pBVar18,local_208,0x2000);
    pcVar41 = "STLS\r\n";
  }
  else if (local_1e8 == 3) {
    pBVar21 = BIO_f_buffer();
    pBVar22 = BIO_new(pBVar21);
    bVar1 = false;
    BIO_push(pBVar22,pBVar18);
    BIO_gets(pBVar22,local_208,0x2000);
    BIO_printf(pBVar22,". CAPABILITY\r\n");
    BIO_ctrl(pBVar22,0xb,0,(void *)0x0);
    do {
      iVar15 = BIO_gets(pBVar22,local_208,0x2000);
      pcVar41 = strstr(local_208,"STARTTLS");
      if (pcVar41 != (char *)0x0) {
        bVar1 = true;
      }
    } while ((3 < iVar15) && (*local_208 != '.'));
    BIO_ctrl(pBVar22,0xb,0,(void *)0x0);
    BIO_pop(pBVar22);
    iVar15 = BIO_free(pBVar22);
    if (!bVar1) {
      iVar15 = BIO_printf(bio_err,"didn\'t found STARTTLS in server response, try anyway...\n",
                          iVar15,iVar15);
    }
    pcVar41 = ". STARTTLS\r\n";
    iVar20 = iVar15;
  }
  else {
    if (local_1e8 != 4) {
      if (local_1e8 == 5) {
        BIO_printf(pBVar18,
                   "<stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\' xmlns=\'jabber:client\' to=\'%s\' version=\'1.0\'>"
                   ,local_170,iVar13 + 1);
        iVar15 = BIO_read(pBVar18,local_208,0x2000);
        local_208[iVar15] = '\0';
        while (pcVar41 = strstr(local_208,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'"),
              pcVar41 == (char *)0x0) {
          pcVar41 = strstr(local_208,"/stream:features>");
          if (pcVar41 != (char *)0x0) goto LAB_0806f481;
          iVar15 = BIO_read(pBVar18,local_208,0x2000);
          local_208[iVar15] = '\0';
        }
        BIO_printf(pBVar18,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'/>",pcVar41,pcVar41);
        iVar15 = BIO_read(pBVar18,local_20c,0x2000);
        local_20c[iVar15] = '\0';
        pcVar41 = strstr(local_20c,"<proceed");
        if (pcVar41 != (char *)0x0) {
          *local_208 = '\0';
          goto LAB_0806eb06;
        }
LAB_0806f481:
        iVar13 = 1;
LAB_0806ee52:
        if (bVar3) {
          print_stuff();
        }
        SSL_shutdown(to);
        iVar15 = SSL_get_fd(to);
        shutdown(iVar15,0);
        iVar15 = SSL_get_fd(to);
        close(iVar15);
        goto LAB_0806ee92;
      }
      goto LAB_0806eb06;
    }
    pBVar21 = BIO_f_buffer();
    pBVar22 = BIO_new(pBVar21);
    BIO_push(pBVar22,pBVar18);
    do {
      iVar15 = BIO_gets(pBVar22,local_208,0x2000);
      if (iVar15 < 4) break;
    } while (local_208[3] == '-');
    iVar20 = 0;
    iVar15 = 0;
    BIO_ctrl(pBVar22,0xb,0,(void *)0x0);
    BIO_pop(pBVar22);
    BIO_free(pBVar22);
    pcVar41 = "AUTH TLS\r\n";
  }
  BIO_printf(pBVar18,pcVar41,iVar15,iVar20);
  BIO_read(pBVar18,local_20c,0x2000);
LAB_0806eb06:
  bVar1 = true;
  local_1cc = (_func_603 *)0x0;
  num = (X509 *)0x0;
  local_1d4 = (_func_603 *)0x0;
  local_1d0 = (_func_603 *)0x0;
  bVar4 = true;
  bVar37 = true;
  bVar38 = false;
switchD_0806f92c_caseD_7:
  bVar8 = bVar38;
  bVar6 = bVar37;
  bVar7 = bVar4;
  iVar15 = 0x20;
  p_Var33 = local_120.fds_bits;
  for (; iVar15 != 0; iVar15 = iVar15 + -1) {
    *p_Var33 = 0;
    p_Var33 = p_Var33 + 1;
  }
  pSVar43 = (SSL_SESSION *)&local_a0;
  for (iVar15 = 0x20; iVar15 != 0; iVar15 = iVar15 + -1) {
    pSVar43->ssl_version = 0;
    pSVar43 = (SSL_SESSION *)&pSVar43->key_arg_length;
  }
  iVar15 = SSL_version(to);
  if (iVar15 == 0xfeff) {
    lVar14 = SSL_ctrl(to,0x49,0,&local_158);
    local_1c4 = &local_158;
    if (lVar14 == 0) goto LAB_0806eb73;
  }
  else {
LAB_0806eb73:
    local_1c4 = (timeval *)0x0;
  }
  uVar29 = SSL_state(to);
  bVar4 = bVar7;
  bVar37 = bVar6;
  bVar38 = bVar8;
  if (((uVar29 & 0x3000) != 0) && (lVar14 = SSL_ctrl(to,0xc,0,(void *)0x0), lVar14 == 0)) {
    pSVar43 = (SSL_SESSION *)0x0;
    bVar3 = true;
    if (bVar7) goto LAB_0806f1fa;
LAB_0806ec80:
    if (bVar1) {
      iVar15 = SSL_get_fd(to);
      pSVar43 = (SSL_SESSION *)(1 << ((byte)(iVar15 % 0x20) & 0x1f));
      iVar15 = SSL_get_fd(to);
      iVar15 = __fdelt_chk(iVar15);
      local_a0.fds_bits[iVar15] = local_a0.fds_bits[iVar15] | (uint)pSVar43;
    }
    iVar15 = select(iVar13 + 1,&local_120,&local_a0,(fd_set *)0x0,local_1c4);
    if (iVar15 < 0) {
      piVar24 = __errno_location();
      iVar13 = 1;
      BIO_printf(bio_err,"bad select %d\n",*piVar24,pSVar43);
      goto LAB_0806ee52;
    }
    iVar15 = SSL_version(to);
    if (iVar15 == 0xfeff) {
      bVar2 = false;
      lVar14 = SSL_ctrl(to,0x4a,0,(void *)0x0);
      uVar16 = extraout_ECX_01;
      if (0 < lVar14) goto LAB_0806ed11;
    }
LAB_0806ed2e:
    iVar15 = SSL_get_fd(to);
    iVar15 = __fdelt_chk(iVar15);
    uVar29 = local_a0.fds_bits[iVar15];
    iVar15 = SSL_get_fd(to);
    if ((uVar29 >> (iVar15 % 0x20 & 0x1fU) & 1) != 0) goto LAB_0806f904;
    iVar15 = fileno(stdout);
    iVar15 = __fdelt_chk(iVar15);
    uVar29 = local_a0.fds_bits[iVar15];
    iVar15 = fileno(stdout);
    uVar19 = 1 << ((byte)(iVar15 % 0x20) & 0x1f);
    if ((uVar29 & uVar19) == 0) {
      iVar15 = SSL_get_fd(to);
      iVar15 = __fdelt_chk(iVar15);
      uVar29 = local_120.fds_bits[iVar15];
      iVar15 = SSL_get_fd(to);
      if ((uVar29 & 1 << ((byte)(iVar15 % 0x20) & 0x1f)) != 0) goto LAB_0806edfa;
      iVar15 = fileno(stdin);
      iVar15 = __fdelt_chk(iVar15);
      uVar29 = local_120.fds_bits[iVar15];
      iVar15 = fileno(stdin);
      iVar20 = iVar15 / 0x20;
      if ((uVar29 & 1 << ((byte)(iVar15 % 0x20) & 0x1f)) != 0) {
        if (bVar10) {
          num = (X509 *)raw_read_stdin(local_204,0x1000,iVar20,iVar20);
          pXVar23 = (X509 *)0x0;
          for (iVar15 = 0; pXVar30 = num, iVar15 < (int)num; iVar15 = iVar15 + 1) {
            pXVar23 = (X509 *)(pXVar23->sha1_hash + ((local_204[iVar15] == 10) - 0x58));
          }
          while (pXVar30 = (X509 *)((int)&pXVar30[-1].aux + 3), -1 < (int)pXVar30) {
            (local_204 + (int)pXVar30)[(int)pXVar23] = local_204[(int)pXVar30];
            if (local_204[(int)pXVar30] == 10) {
              pXVar23 = (X509 *)((int)&pXVar23[-1].aux + 3);
              num = (X509 *)((int)&num->cert_info + 1);
              (local_204 + (int)pXVar30)[(int)pXVar23] = 0xd;
            }
          }
          if (pXVar23 != (X509 *)0x0) {
                    /* WARNING: Subroutine does not return */
            __assert_fail("lf_num == 0","s_client.c",0x738,"s_client_main");
          }
        }
        else {
          pXVar23 = (X509 *)raw_read_stdin(local_204,0x2000,iVar20,iVar20);
          num = pXVar23;
        }
        if (c_ign_eof == 0) {
          if (0 < (int)num) {
            bVar39 = *local_204;
            pXVar23 = (X509 *)(uint)bVar39;
            if (bVar39 != 0x51) {
              if (bVar39 == 0x52) {
                bVar1 = true;
                num = (X509 *)0x0;
                BIO_printf(bio_err,"RENEGOTIATING\n",pXVar23,pXVar23);
                SSL_renegotiate(to);
                bVar37 = false;
              }
              else {
                if (bVar39 != 0x42) goto LAB_0806fa8a;
                bVar1 = true;
                num = (X509 *)0x0;
                BIO_printf(bio_err,"HEARTBEATING\n",pXVar23,pXVar23);
                SSL_ctrl(to,0x55,0,(void *)0x0);
                bVar37 = false;
              }
              goto switchD_0806f92c_caseD_7;
            }
          }
          iVar13 = 0;
          BIO_printf(bio_err,"DONE\n",pXVar23,pXVar23);
          goto LAB_0806ee52;
        }
LAB_0806fa8a:
        bVar1 = true;
        local_1d0 = (_func_603 *)0x0;
        bVar37 = false;
      }
    }
    else {
      iVar15 = raw_write_stdout(local_20c + (int)local_1cc,local_1d4,uVar19,uVar19);
      if (iVar15 < 1) {
        iVar13 = 0;
        BIO_printf(bio_c_out,"DONE\n",extraout_ECX_06,extraout_ECX_06);
        goto LAB_0806ee52;
      }
      local_1d4 = (_func_603 *)((int)local_1d4 - iVar15);
      local_1cc = (_func_603 *)((int)local_1cc + iVar15);
      bVar4 = true;
      bVar38 = false;
      if (0 < (int)local_1d4) {
        bVar4 = bVar7;
        bVar38 = bVar8;
      }
    }
    goto switchD_0806f92c_caseD_7;
  }
  if (bVar3) {
    if (local_1ec != (_func_603 *)0x0) {
      pBVar18 = BIO_new_file((char *)local_1ec,"w");
      if (pBVar18 == (BIO *)0x0) {
        BIO_printf(bio_err,"Error writing session file %s\n",local_1ec,0);
      }
      else {
        pSVar43 = SSL_get_session(to);
        PEM_write_bio_SSL_SESSION(pBVar18,pSVar43);
        BIO_free(pBVar18);
      }
    }
    iVar15 = print_stuff();
    pSVar28 = (SSL_SESSION *)0x0;
    if (local_1c8 != (SSL_SESSION *)0x1) {
      pSVar28 = local_1c8;
    }
    if (local_1e8 != 0) {
      iVar15 = BIO_printf(bio_err,"%s",local_208,local_1c8);
    }
    if (local_1b4 != 0) goto LAB_0806f6fc;
    local_1e8 = 0;
    pSVar43 = local_1c8;
    local_1c8 = pSVar28;
  }
  bVar3 = false;
  if (!bVar7) {
LAB_0806ec2a:
    if (bVar6) {
      iVar15 = fileno(stdin);
      iVar20 = fileno(stdin);
      pSVar43 = (SSL_SESSION *)__fdelt_chk(iVar20);
      local_120.fds_bits[(int)pSVar43] =
           local_120.fds_bits[(int)pSVar43] | 1 << ((byte)(iVar15 % 0x20) & 0x1f);
    }
    if (bVar8) {
      iVar15 = fileno(stdout);
      pSVar43 = (SSL_SESSION *)(1 << ((byte)(iVar15 % 0x20) & 0x1f));
      iVar15 = fileno(stdout);
      iVar15 = __fdelt_chk(iVar15);
      local_a0.fds_bits[iVar15] = local_a0.fds_bits[iVar15] | (uint)pSVar43;
    }
LAB_0806ec40:
    if (bVar7) {
      iVar15 = SSL_get_fd(to);
      pSVar43 = (SSL_SESSION *)(1 << ((byte)(iVar15 % 0x20) & 0x1f));
      iVar15 = SSL_get_fd(to);
      iVar15 = __fdelt_chk(iVar15);
      local_120.fds_bits[iVar15] = local_120.fds_bits[iVar15] | (uint)pSVar43;
    }
    goto LAB_0806ec80;
  }
  pSVar43 = (SSL_SESSION *)0x1;
LAB_0806f1fa:
  iVar15 = SSL_pending(to);
  if (iVar15 == 0) {
    if (pSVar43 != (SSL_SESSION *)0x0) goto LAB_0806ec2a;
    goto LAB_0806ec40;
  }
  iVar15 = SSL_version(to);
  if (iVar15 == 0xfeff) {
    bVar2 = true;
    lVar14 = SSL_ctrl(to,0x4a,0,(void *)0x0);
    uVar16 = extraout_ECX_03;
    if (lVar14 < 1) goto LAB_0806edfa;
LAB_0806ed11:
    BIO_printf(bio_err,"TIMEOUT occured\n",uVar16,uVar16);
    if (!bVar2) goto LAB_0806ed2e;
  }
LAB_0806edfa:
  iVar20 = SSL_read(to,local_20c,0x400);
  iVar15 = SSL_get_error(to,iVar20);
  switch(iVar15) {
  case 0:
    if (iVar20 < 1) goto LAB_0806ff0a;
    local_1cc = (_func_603 *)0x0;
    local_1d4 = (_func_603 *)iVar20;
    bVar4 = false;
    bVar38 = true;
    break;
  case 1:
    goto switchD_0806f92c_caseD_1;
  case 2:
    BIO_printf(bio_c_out,"read R BLOCK\n",iVar15,iVar15);
    bVar7 = (bool)(bVar6 | bVar1);
    if (!bVar7) {
      bVar1 = true;
    }
    bVar4 = true;
    bVar37 = false;
    bVar38 = false;
    if (bVar7) {
      bVar37 = bVar6;
    }
    break;
  case 3:
    pcVar41 = "read W BLOCK\n";
    goto LAB_0806ef45;
  case 4:
    BIO_printf(bio_c_out,"read X BLOCK\n",iVar15,iVar15);
    break;
  case 5:
    piVar24 = __errno_location();
    iVar13 = *piVar24;
    BIO_printf(bio_err,"read:errno=%d\n",iVar13,piVar24);
    goto LAB_0806ee52;
  case 6:
    iVar13 = 0;
    BIO_printf(bio_c_out,"closed\n",extraout_ECX_02,extraout_ECX_02);
    goto LAB_0806ee52;
  }
  goto switchD_0806f92c_caseD_7;
LAB_0806fe8e:
  piVar24 = __errno_location();
  iVar13 = *piVar24;
  pcVar41 = "connect:errno=%d\n";
  uVar16 = extraout_EDX_08;
LAB_0806fdee:
  BIO_printf(bio_err,pcVar41,iVar13,uVar16);
  iVar13 = 1;
  shutdown(local_174,0);
  close(local_174);
LAB_0806ee92:
  if (to != (SSL *)0x0) {
    if (bVar9) {
      print_stuff();
    }
    SSL_free(to);
  }
  if (next_proto._0_4_ != (void *)0x0) goto LAB_0806da05;
  goto LAB_0806da15;
LAB_0806f6fc:
  local_1b4 = local_1b4 + -1;
  BIO_printf(bio_c_out,"drop connection and then reconnect\n",iVar15,iVar15);
  SSL_shutdown(to);
  SSL_set_connect_state(to);
  iVar13 = SSL_get_fd(to);
  shutdown(iVar13,0);
  iVar13 = SSL_get_fd(to);
  close(iVar13);
  bVar3 = false;
  local_1e8 = 0;
  pcVar42 = (code *)local_1c8;
  local_1c8 = pSVar28;
  goto LAB_0806e9e0;
LAB_0806f904:
  uVar29 = SSL_write(to,local_204 + (int)local_1d0,(int)num);
  iVar15 = SSL_get_error(to,uVar29);
  switch(iVar15) {
  case 0:
    local_1d0 = (_func_603 *)((int)local_1d0 + uVar29);
    num = (X509 *)((int)num - uVar29);
    if ((int)uVar29 < 1) {
LAB_0806ff0a:
      iVar13 = 1;
      goto LAB_0806ee92;
    }
    bVar1 = 0 < (int)num;
    bVar37 = (int)num < 1;
    break;
  case 1:
switchD_0806f92c_caseD_1:
    iVar13 = 1;
    ERR_print_errors(bio_err);
    goto LAB_0806ee52;
  case 2:
    bVar1 = false;
    BIO_printf(bio_c_out,"write R BLOCK\n",iVar15,iVar15);
    bVar4 = true;
    bVar38 = false;
    break;
  case 3:
    pcVar41 = "write W BLOCK\n";
LAB_0806ef45:
    bVar1 = true;
    BIO_printf(bio_c_out,pcVar41,iVar15,iVar15);
    bVar37 = false;
    break;
  case 4:
    BIO_printf(bio_c_out,"write X BLOCK\n",uVar29,uVar29);
    break;
  case 5:
    if (((uint)num | uVar29) != 0) {
      piVar24 = __errno_location();
      iVar13 = 1;
      BIO_printf(bio_err,"write:errno=%d\n",*piVar24,extraout_EDX_06);
      goto LAB_0806ee52;
    }
    bVar1 = false;
    num = (X509 *)0x0;
    bVar37 = true;
    break;
  case 6:
    if (num != (X509 *)0x0) {
      iVar13 = 0;
      BIO_printf(bio_c_out,"shutdown\n",extraout_ECX_07,extraout_ECX_07);
      goto LAB_0806ee52;
    }
    bVar1 = false;
    bVar37 = true;
  }
  goto switchD_0806f92c_caseD_7;
LAB_0806de18:
  BIO_printf(bio_err,"usage: s_client args\n",pSVar43);
  BIO_printf(bio_err,"\n");
  BIO_printf(bio_err," -host host     - use -connect instead\n");
  BIO_printf(bio_err," -port port     - use -connect instead\n");
  BIO_printf(bio_err," -connect host:port - who to connect to (default is %s:%s)\n","localhost",
             "4433");
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
  pcVar41 = " -keymatexportlen len  - Export len bytes of keying material (default 20)\n";
LAB_0806e28e:
  ctx_00 = (SSL_CTX *)0x0;
  pkey = (EVP_PKEY *)0x0;
  a = (X509 *)0x0;
  BIO_printf(bio_err,pcVar41);
  goto LAB_0806d9f7;
}

