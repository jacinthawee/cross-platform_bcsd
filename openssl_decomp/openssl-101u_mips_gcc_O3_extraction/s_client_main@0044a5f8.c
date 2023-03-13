
/* WARNING: Removing unreachable block (ram,0x0044c8e4) */
/* WARNING: Removing unreachable block (ram,0x0044cf2c) */
/* WARNING: Removing unreachable block (ram,0x0044cf44) */
/* WARNING: Removing unreachable block (ram,0x0044cf48) */
/* WARNING: Removing unreachable block (ram,0x0044c914) */
/* WARNING: Removing unreachable block (ram,0x0044c934) */
/* WARNING: Removing unreachable block (ram,0x0044c938) */
/* WARNING: Removing unreachable block (ram,0x0044c7e0) */
/* WARNING: Removing unreachable block (ram,0x0044cbec) */
/* WARNING: Removing unreachable block (ram,0x0044c594) */
/* WARNING: Removing unreachable block (ram,0x0044c610) */
/* WARNING: Removing unreachable block (ram,0x0044c700) */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined * s_client_main(int param_1,undefined4 *param_2)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  undefined *puVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  bool bVar11;
  int iVar12;
  byte *pbVar13;
  char *pcVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  undefined *puVar18;
  undefined *puVar19;
  undefined *puVar20;
  char *pcVar21;
  undefined4 *puVar22;
  byte *pbVar23;
  char *pcVar24;
  code *pcVar25;
  char *pcVar26;
  int local_res0 [4];
  undefined *local_24c;
  undefined4 *local_244;
  undefined *local_240;
  undefined *local_234;
  undefined4 *local_22c;
  int local_228;
  char *local_224;
  char *local_220;
  char *local_21c;
  undefined *local_218;
  char *local_214;
  char *local_210;
  int local_20c;
  int local_208;
  uint local_204;
  int local_200;
  int local_1fc;
  int local_1f8;
  int local_1f4;
  undefined4 *local_1f0;
  undefined4 local_1ec;
  char *local_1e8;
  uint *local_1e4;
  uint *local_1e0;
  int local_1dc;
  int local_1d8;
  undefined **local_1d4;
  undefined4 local_1d0;
  int local_1cc;
  int local_1c8;
  undefined **local_1c4;
  int local_1c0;
  undefined *local_1bc;
  char *local_1b8;
  char *local_1b4;
  int local_1b0;
  int local_1ac;
  undefined4 local_1a8;
  char *local_1a4;
  int local_1a0;
  undefined4 *local_19c;
  undefined *local_198;
  undefined4 *local_18c [2];
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
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  undefined4 local_140;
  undefined auStack_13c [16];
  uint auStack_12c [32];
  uint auStack_ac [32];
  int local_2c;
  
  puVar7 = PTR___stack_chk_guard_006a9ae8;
  puVar9 = (undefined4 *)PTR_bio_err_006a6e3c;
  local_182 = 0x1151;
  local_16c = 0x10;
  local_17c = "localhost";
  local_140 = 0x400;
  local_178 = 0;
  local_174 = 0;
  local_170 = 0;
  local_15c = 0;
  local_158 = 0;
  local_154 = 0;
  local_150 = 0;
  local_14c = 0;
  local_148 = 0;
  local_144 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_res0[0] = param_1;
  local_18c[0] = param_2;
  local_244 = (undefined4 *)(*(code *)PTR_SSLv23_client_method_006a7984)();
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  iVar12 = *puVar9;
  local_234 = &_gp_1;
  c_Pause = 0;
  c_quiet = 0;
  c_ign_eof = 0;
  local_240 = &_gp_1;
  local_22c = (undefined4 *)&_gp_1;
  c_debug = 0;
  c_msg = 0;
  c_showcerts = 0;
  if (iVar12 == 0) {
    iVar12 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
    *puVar9 = iVar12;
  }
  iVar12 = load_config(iVar12,0);
  if (iVar12 == 0) {
    puVar19 = (undefined *)0x0;
    puVar22 = (undefined4 *)0x0;
    pcVar24 = (char *)0x0;
    pcVar21 = (char *)0x0;
    puVar20 = (undefined *)0x0;
    pcVar26 = (char *)0x0;
  }
  else {
    local_220 = "-check_ss_sig";
    pcVar26 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x2000,"s_client.c",0x2c4);
    if ((pcVar26 == (char *)0x0) ||
       (puVar20 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x2000,"s_client.c",0x2c5),
       puVar20 == (undefined *)0x0)) {
      puVar20 = (undefined *)0x0;
    }
    else {
      pcVar21 = (char *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x2000,"s_client.c",0x2c6);
      puVar18 = PTR_verify_error_006a7988;
      puVar19 = PTR_verify_depth_006a7894;
      if (pcVar21 != (char *)0x0) {
        local_19c = (undefined4 *)0x0;
        local_1d0 = 0;
        local_198 = &_gp_1;
        local_res0[0] = local_res0[0] + -1;
        local_210 = PTR_verify_depth_006a7894;
        c_nbio = 0;
        local_1c0 = 0;
        *(undefined4 *)PTR_verify_depth_006a7894 = 0;
        local_18c[0] = local_18c[0] + 1;
        local_1a0 = 0;
        *(undefined4 *)puVar18 = 0;
        local_1a4 = (char *)0x0;
        local_200 = 0;
        local_1f8 = 0;
        local_1a8 = 2;
        local_208 = 0;
        local_1d4 = (undefined **)0x0;
        local_1e4 = (uint *)0x0;
        local_1e8 = (char *)0x0;
        local_1e0 = (uint *)0x0;
        local_228 = 0;
        local_1fc = 0;
        local_1ac = 0;
        local_1b0 = 0;
        local_1b4 = (char *)0x0;
        local_218 = (undefined *)0x0;
        local_1d8 = 0;
        local_1b8 = (char *)0x0;
        local_1c4 = (undefined **)0x0;
        local_1c8 = 0;
        local_1ec = 0;
        local_1dc = 3;
        local_1f4 = 3;
        local_1f0 = (undefined4 *)0x0;
        local_20c = 0;
        local_1bc = (undefined *)0x0;
        local_1cc = 0;
        local_204 = 0;
        local_224 = "-check_ss_sig";
        local_21c = "-verify";
        local_214 = "TBEX";
LAB_0044aa1c:
        puVar22 = local_18c[0];
        iVar12 = local_res0[0];
        if (local_res0[0] < 1) {
          puVar17 = (undefined4 *)&_gp_1;
          (*(code *)PTR_SSL_library_init_006a7898)();
          (*(code *)PTR_SSL_load_error_strings_006a7588)();
          next_proto._8_4_ = 0xffffffff;
          if (local_208 == 0) {
            next_proto._0_4_ = 0;
LAB_0044b408:
            uVar6 = setup_engine(*puVar9,local_1e8,1);
            if (local_1e4 == (uint *)0x0) {
              local_24c = (undefined *)0x0;
            }
            else {
              local_24c = (undefined *)(*(code *)PTR_ENGINE_by_id_006a6e9c)(local_1e4);
              if (local_24c == (undefined *)0x0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)PTR_bio_err_006a6e3c,"Error getting client auth engine\n")
                ;
                goto LAB_0044b714;
              }
            }
            puVar19 = PTR_bio_err_006a6e3c;
            iVar12 = app_passwd(*puVar9,local_1ec,0,&local_178,0);
            if (iVar12 != 0) {
              if (local_1f0 == (undefined4 *)0x0) {
                pcVar24 = (char *)0x0;
                if (local_20c != 0) {
                  puVar22 = (undefined4 *)
                            load_key(*(undefined4 *)puVar19,local_20c,local_1dc,0,local_178,uVar6,
                                     "client certificate private key file");
                  if (puVar22 != (undefined4 *)0x0) goto LAB_0044b4bc;
                  goto LAB_0044c3fc;
                }
                puVar22 = (undefined4 *)0x0;
              }
              else {
                puVar22 = (undefined4 *)
                          load_key(*(undefined4 *)puVar19,local_1f0,local_1dc,0,local_178,uVar6,
                                   "client certificate private key file");
                if (puVar22 == (undefined4 *)0x0) {
LAB_0044c3fc:
                  (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar9);
                  goto LAB_0044b714;
                }
                if (local_20c == 0) {
                  pcVar24 = (char *)0x0;
                }
                else {
LAB_0044b4bc:
                  pcVar24 = (char *)load_cert(*puVar9,local_20c,local_1f4,0,uVar6,
                                              "client certificate file");
                  if (pcVar24 == (char *)0x0) {
                    puVar19 = (undefined *)0x0;
                    (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)PTR_bio_err_006a6e3c);
                    goto LAB_0044a748;
                  }
                }
              }
              iVar12 = app_RAND_load_file(0,*puVar9,1);
              if (iVar12 == 0) {
                if (local_1e0 == (uint *)0x0) {
                  iVar12 = (*(code *)PTR_RAND_status_006a773c)();
                  if (iVar12 == 0) {
                    (*(code *)PTR_BIO_printf_006a6e38)
                              (*(undefined4 *)PTR_bio_err_006a6e3c,
                               "warning, not much extra random data, consider using the -rand option\n"
                              );
                  }
                }
                else {
LAB_0044b51c:
                  uVar16 = *puVar9;
                  uVar6 = app_RAND_load_files(local_1e0);
                  (*(code *)PTR_BIO_printf_006a6e38)(uVar16,"%ld semi-random bytes loaded\n",uVar6);
                }
              }
              else if (local_1e0 != (uint *)0x0) goto LAB_0044b51c;
              puVar18 = &_gp_1;
              if (bio_c_out == 0) {
                if (((c_quiet == 0) || (c_debug != 0)) || (c_msg != 0)) {
                  bio_c_out = (*(code *)PTR_BIO_new_fp_006a7248)
                                        (*(undefined4 *)PTR_stdout_006a99c8,0);
                }
                else {
                  uVar6 = (*(code *)PTR_BIO_s_null_006a7908)();
                  bio_c_out = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
                }
              }
              puVar4 = PTR_bio_err_006a6e3c;
              local_234 = PTR_bio_err_006a6e3c;
              local_22c = &local_154;
              iVar12 = app_passwd(*puVar9,local_1d0,0,local_22c,0);
              if (iVar12 == 0) {
                puVar19 = (undefined *)0x0;
                (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"Error getting password\n")
                ;
                goto LAB_0044a748;
              }
              puVar19 = (undefined *)(*(code *)PTR_SSL_CTX_new_006a78a0)(local_244);
              if (puVar19 == (undefined *)0x0) {
                (*(code *)PTR_ERR_print_errors_006a6e40)(*(undefined4 *)puVar4);
                goto LAB_0044a748;
              }
              if (local_174 != 0) {
                (*(code *)PTR_SSL_CTX_set1_param_006a78b8)(puVar19);
              }
              if (local_24c != (undefined *)0x0) {
                iVar12 = (*(code *)PTR_SSL_CTX_set_client_cert_engine_006a7990)(puVar19,local_24c);
                if (iVar12 == 0) {
                  (*(code *)PTR_BIO_puts_006a6f58)(*puVar9,"Error setting client auth engine\n");
                  (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar9);
                  (*(code *)PTR_ENGINE_free_006a6e84)(local_24c);
                  goto LAB_0044a748;
                }
                (*(code *)PTR_ENGINE_free_006a6e84)(local_24c);
              }
              if (*(int *)PTR_psk_key_006a7968 != 0) {
                if (c_debug != 0) {
                  (*(code *)PTR_BIO_printf_006a6e38)
                            (bio_c_out,"PSK key given or JPAKE in use, setting client callback\n");
                }
                (*(code *)PTR_SSL_CTX_set_psk_client_callback_006a7994)(puVar19,psk_client_cb);
              }
              if (srtp_profiles != 0) {
                (*(code *)PTR_SSL_CTX_set_tlsext_use_srtp_006a78ac)(puVar19);
              }
              if (local_1b4 == (char *)0x0) {
                (*(code *)PTR_SSL_CTX_ctrl_006a775c)(puVar19,0x20,local_204,0);
              }
              else {
                (*(code *)PTR_SSL_CTX_ctrl_006a775c)(puVar19,0x20,local_204 | 0x80000bff);
              }
              if (local_1cc != 0) {
                (*(code *)PTR_SSL_CTX_ctrl_006a775c)(puVar19,0x4d,local_1cc,0);
              }
              if (next_proto._0_4_ != 0) {
                (*(code *)PTR_SSL_CTX_set_next_proto_select_cb_006a7998)
                          (puVar19,next_proto_cb,next_proto);
              }
              if (local_1bc != (undefined *)0x0) {
                (*(code *)PTR_SSL_CTX_set_info_callback_006a78fc)
                          (puVar19,PTR_apps_ssl_info_callback_006a7900);
              }
              if ((local_1b8 != (char *)0x0) &&
                 (iVar12 = (*(code *)PTR_SSL_CTX_set_cipher_list_006a78d4)(puVar19,local_1b8),
                 iVar12 == 0)) {
                (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"error setting cipher list\n");
                (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar9);
                goto LAB_0044a748;
              }
              (*(code *)PTR_SSL_CTX_set_verify_006a78d8)
                        (puVar19,local_218,PTR_verify_callback_006a78dc);
              iVar12 = set_cert_key_stuff(puVar19,pcVar24,puVar22);
              if (iVar12 == 0) goto LAB_0044a748;
              if (((local_1c4 != (undefined **)0x0) || (local_1c8 != 0)) &&
                 (iVar12 = (*(code *)PTR_SSL_CTX_load_verify_locations_006a78b0)
                                     (puVar19,local_1c4,local_1c8), iVar12 == 0)) {
                (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar9);
              }
              iVar12 = (*(code *)PTR_SSL_CTX_set_default_verify_paths_006a78b4)(puVar19);
              if (iVar12 == 0) {
                (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar9);
              }
              if (local_1d4 != (undefined **)0x0) {
                local_15c = *puVar9;
                (*(code *)PTR_SSL_CTX_callback_ctrl_006a7824)(puVar19,0x35,ssl_servername_cb);
                (*(code *)PTR_SSL_CTX_ctrl_006a775c)(puVar19,0x36,0,&local_15c);
              }
              if (local_150 != 0) {
                if ((local_19c == (undefined4 *)0x0) &&
                   (iVar12 = (*(code *)PTR_SSL_CTX_set_srp_username_006a799c)(puVar19), iVar12 == 0)
                   ) {
                  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"Unable to set SRP username\n");
                  goto LAB_0044a748;
                }
                local_14c = c_msg;
                local_148 = c_debug;
                (*(code *)PTR_SSL_CTX_set_srp_cb_arg_006a7910)(puVar19,local_22c);
                (*(code *)PTR_SSL_CTX_set_srp_client_pwd_callback_006a79a0)
                          (puVar19,ssl_give_srp_client_pwd_cb);
                (*(code *)PTR_SSL_CTX_set_srp_strength_006a79a4)(puVar19,local_140);
                if (((c_msg != 0) || (c_debug != 0)) || (local_144 == 0)) {
                  (*(code *)PTR_SSL_CTX_set_srp_verify_param_callback_006a79a8)
                            (puVar19,ssl_srp_verify_param_cb);
                }
              }
              puVar10 = (undefined4 *)(*(code *)PTR_SSL_new_006a77e0)(puVar19);
              local_244 = puVar10;
              if (local_1f8 == 0) {
LAB_0044ba68:
                if (local_1a4 != (char *)0x0) {
                  (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x21,0x80,0);
                }
                if ((local_1d4 == (undefined **)0x0) ||
                   (iVar12 = (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x37,0,local_1d4), iVar12 != 0
                   )) {
                  local_21c = &_gp_1;
                  local_19c = &local_180;
                  local_20c = 1;
                  local_1f4 = 1;
                  local_1bc = &_gp_1;
                  local_218 = &_gp_1;
                  local_1b8 = "-check_ss_sig";
                  local_1b4 = "<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'";
                  local_1a4 = "/stream:features>";
                  local_1e8 = "STARTTLS";
                  local_24c = puVar20;
                  local_234 = puVar19;
                  local_22c = puVar22;
                  local_224 = pcVar24;
                  local_210 = pcVar26;
                  goto LAB_0044bb20;
                }
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*puVar9,"Unable to set TLS servername extension.\n");
              }
              else {
                iVar12 = (*(code *)PTR_BIO_new_file_006a6eac)(local_1f8,"r");
                if (iVar12 != 0) {
                  iVar8 = (*(code *)PTR_PEM_read_bio_SSL_SESSION_006a79ac)(iVar12,0,0,0);
                  (*(code *)PTR_BIO_free_006a6e70)(iVar12);
                  if (iVar8 != 0) {
                    (*(code *)PTR_SSL_set_session_006a79b0)(puVar10,iVar8);
                    (*(code *)PTR_SSL_SESSION_free_006a79b4)(iVar8);
                    goto LAB_0044ba68;
                  }
                }
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*puVar9,"Can\'t open session file %s\n",local_1f8);
              }
              (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar9);
              local_24c = (undefined *)0x1;
              goto LAB_0044c0b8;
            }
            (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar19,"Error getting password\n");
          }
          else {
            next_proto._0_4_ = next_protos_parse(0x6aa1c8,local_208);
            if (next_proto._0_4_ != 0) goto LAB_0044b408;
            (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"Error parsing -nextprotoneg argument\n");
          }
LAB_0044b714:
          puVar19 = (undefined *)0x0;
          puVar22 = (undefined4 *)0x0;
          pcVar24 = (char *)0x0;
          goto LAB_0044a748;
        }
        uVar6 = *local_18c[0];
        iVar8 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-host");
        if (iVar8 == 0) {
          local_res0[0] = iVar12 + -1;
          if (local_res0[0] == 0) goto LAB_0044abb8;
          local_17c = (char *)puVar22[1];
          puVar22 = puVar22 + 1;
          iVar12 = local_res0[0];
        }
        else {
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-port");
          if (iVar8 == 0) {
            local_res0[0] = iVar12 + -1;
            if (local_res0[0] != 0) {
              local_18c[0] = puVar22 + 1;
              local_182 = (*(code *)PTR_strtol_006a9958)(puVar22[1],0,10);
              puVar22 = local_18c[0];
              iVar12 = local_res0[0];
              if (local_182 != 0) goto LAB_0044aa58;
            }
            goto LAB_0044abb8;
          }
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-connect");
          if (iVar8 == 0) {
            local_res0[0] = iVar12 + -1;
            if (local_res0[0] != 0) {
              local_18c[0] = puVar22 + 1;
              iVar8 = extract_host_port(puVar22[1],&local_17c,0,&local_182);
              puVar22 = local_18c[0];
              iVar12 = local_res0[0];
              if (iVar8 != 0) goto LAB_0044aa58;
            }
            goto LAB_0044abb8;
          }
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-verify");
          if (iVar8 == 0) {
            local_res0[0] = iVar12 + -1;
            if (local_res0[0] != 0) {
              local_18c[0] = puVar22 + 1;
              uVar6 = (*(code *)PTR_strtol_006a9958)(puVar22[1],0,10);
              puVar18 = PTR_BIO_printf_006a6e38;
              uVar16 = *puVar9;
              *(undefined4 *)puVar19 = uVar6;
              (*(code *)puVar18)(uVar16,"verify depth is %d\n",uVar6);
              local_218 = (undefined *)0x1;
              puVar22 = local_18c[0];
              iVar12 = local_res0[0];
              goto LAB_0044aa58;
            }
            goto LAB_0044abb8;
          }
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-cert");
          if (iVar8 == 0) {
            local_res0[0] = iVar12 + -1;
            if (local_res0[0] != 0) {
              local_20c = puVar22[1];
              puVar22 = puVar22 + 1;
              iVar12 = local_res0[0];
              goto LAB_0044aa58;
            }
            goto LAB_0044abb8;
          }
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-sess_out");
          if (iVar8 == 0) {
            local_res0[0] = iVar12 + -1;
            if (local_res0[0] != 0) {
              local_200 = puVar22[1];
              puVar22 = puVar22 + 1;
              iVar12 = local_res0[0];
              goto LAB_0044aa58;
            }
            goto LAB_0044abb8;
          }
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-sess_in");
          if (iVar8 == 0) {
            local_res0[0] = iVar12 + -1;
            if (local_res0[0] != 0) {
              local_1f8 = puVar22[1];
              puVar22 = puVar22 + 1;
              iVar12 = local_res0[0];
              goto LAB_0044aa58;
            }
            goto LAB_0044abb8;
          }
          iVar8 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-certform");
          if (iVar8 == 0) {
            local_res0[0] = iVar12 + -1;
            if (local_res0[0] != 0) {
              local_18c[0] = puVar22 + 1;
              local_1f4 = str2fmt(puVar22[1]);
              puVar22 = local_18c[0];
              iVar12 = local_res0[0];
              goto LAB_0044aa58;
            }
            goto LAB_0044abb8;
          }
          iVar12 = args_verify(local_18c,local_res0,&local_170,*puVar9,&local_174);
          puVar22 = local_18c[0];
          if (iVar12 != 0) {
            if (local_170 != 0) goto LAB_0044abb8;
            goto LAB_0044aa1c;
          }
          uVar6 = *local_18c[0];
          iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-verify_return_error");
          if (iVar12 == 0) {
            *(undefined4 *)PTR_verify_return_error_006a7924 = 1;
            iVar12 = local_res0[0];
          }
          else {
            iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-prexit");
            if (iVar12 == 0) {
              local_228 = 1;
              iVar12 = local_res0[0];
              goto LAB_0044aa58;
            }
            iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-crlf");
            if (iVar12 == 0) {
              local_1b0 = 1;
              iVar12 = local_res0[0];
            }
            else {
              iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-quiet");
              if (iVar12 == 0) {
                c_quiet = 1;
                c_ign_eof = 1;
                iVar12 = local_res0[0];
              }
              else {
                iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-ign_eof");
                if (iVar12 == 0) {
                  c_ign_eof = 1;
                  iVar12 = local_res0[0];
                }
                else {
                  iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-no_ign_eof");
                  if (iVar12 == 0) {
                    c_ign_eof = 0;
                    iVar12 = local_res0[0];
                  }
                  else {
                    iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-pause");
                    if (iVar12 == 0) {
                      c_Pause = 1;
                      iVar12 = local_res0[0];
                    }
                    else {
                      iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-debug");
                      if (iVar12 == 0) {
                        c_debug = 1;
                        iVar12 = local_res0[0];
                      }
                      else {
                        iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-tlsextdebug");
                        if (iVar12 == 0) {
                          c_tlsextdebug = 1;
                          iVar12 = local_res0[0];
                        }
                        else {
                          iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-status");
                          if (iVar12 == 0) {
                            c_status_req = 1;
                            iVar12 = local_res0[0];
                          }
                          else {
                            iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,&DAT_0063b780);
                            if (iVar12 == 0) {
                              c_msg = 1;
                              iVar12 = local_res0[0];
                            }
                            else {
                              iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-showcerts");
                              if (iVar12 == 0) {
                                c_showcerts = 1;
                                iVar12 = local_res0[0];
                              }
                              else {
                                iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-nbio_test");
                                if (iVar12 == 0) {
                                  local_1ac = 1;
                                  iVar12 = local_res0[0];
                                }
                                else {
                                  iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-state");
                                  if (iVar12 == 0) {
                                    local_1bc = (undefined *)0x1;
                                    iVar12 = local_res0[0];
                                  }
                                  else {
                                    iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-psk_identity");
                                    if (iVar12 == 0) {
                                      local_res0[0] = local_res0[0] + -1;
                                      if (local_res0[0] < 1) goto LAB_0044abb8;
                                      psk_identity = (undefined *)puVar22[1];
                                      puVar22 = puVar22 + 1;
                                      iVar12 = local_res0[0];
                                    }
                                    else {
                                      iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,&DAT_0063b7d4);
                                      puVar18 = PTR_strlen_006a9a24;
                                      if (iVar12 == 0) {
                                        iVar12 = local_res0[0] + -1;
                                        local_res0[0] = iVar12;
                                        if (iVar12 < 1) goto LAB_0044abb8;
                                        pbVar23 = (byte *)puVar22[1];
                                        *(byte **)PTR_psk_key_006a7968 = pbVar23;
                                        local_18c[0] = puVar22 + 1;
                                        iVar8 = (*(code *)puVar18)(pbVar23);
                                        pbVar13 = pbVar23;
                                        while (puVar22 = puVar22 + 1, pbVar13 != pbVar23 + iVar8) {
                                          piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
                                          bVar2 = *pbVar13;
                                          pbVar13 = pbVar13 + 1;
                                          if ((*(ushort *)(*piVar3 + (uint)bVar2 * 2) & 0x10) == 0)
                                          {
                                            (*(code *)PTR_BIO_printf_006a6e38)
                                                      (*puVar9,"Not a hex number \'%s\'\n",pbVar23);
                                            goto LAB_0044abb8;
                                          }
                                        }
                                      }
                                      else {
                                        iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-srpuser");
                                        if (iVar12 == 0) {
                                          local_res0[0] = local_res0[0] + -1;
                                          if (local_res0[0] < 1) goto LAB_0044abb8;
                                          local_150 = puVar22[1];
                                          local_18c[0] = puVar22 + 1;
                                          pcVar25 = (code *)PTR_TLSv1_client_method_006a79cc;
                                        }
                                        else {
                                          iVar12 = (*(code *)PTR_strcmp_006a9b18)(uVar6,"-srppass");
                                          if (iVar12 == 0) {
                                            local_res0[0] = local_res0[0] + -1;
                                            if (local_res0[0] < 1) goto LAB_0044abb8;
                                            local_1d0 = puVar22[1];
                                            local_18c[0] = puVar22 + 1;
                                            pcVar25 = (code *)PTR_TLSv1_client_method_006a79cc;
                                          }
                                          else {
                                            iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                               (uVar6,"-srp_strength");
                                            if (iVar12 == 0) {
                                              local_res0[0] = local_res0[0] + -1;
                                              if (local_res0[0] < 1) goto LAB_0044abb8;
                                              local_18c[0] = puVar22 + 1;
                                              local_140 = (*(code *)PTR_strtol_006a9958)
                                                                    (puVar22[1],0,10);
                                              (*(code *)PTR_BIO_printf_006a6e38)
                                                        (*puVar9,"SRP minimal length for N is %d\n",
                                                         local_140);
                                              pcVar25 = (code *)PTR_TLSv1_client_method_006a79cc;
                                            }
                                            else {
                                              iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (uVar6,"-srp_lateuser");
                                              if (iVar12 == 0) {
                                                local_244 = (undefined4 *)
                                                            (*(code *)
                                                  PTR_TLSv1_client_method_006a79cc)();
                                                local_19c = (undefined4 *)0x1;
                                                puVar22 = local_18c[0];
                                                iVar12 = local_res0[0];
                                                goto LAB_0044aa58;
                                              }
                                              iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                 (uVar6,"-srp_moregroups");
                                              if (iVar12 == 0) {
                                                local_144 = 1;
                                                pcVar25 = (code *)PTR_TLSv1_client_method_006a79cc;
                                              }
                                              else {
                                                iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                   (uVar6,"-ssl3");
                                                pcVar25 = (code *)PTR_SSLv3_client_method_006a79d8;
                                                if (((iVar12 != 0) &&
                                                    (iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                        (uVar6,"-tls1_2"),
                                                    pcVar25 = (code *)
                                                  PTR_TLSv1_2_client_method_006a79dc, iVar12 != 0))
                                                  && ((iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                          (uVar6,"-tls1_1"),
                                                      pcVar25 = (code *)
                                                  PTR_TLSv1_1_client_method_006a79d4, iVar12 != 0 &&
                                                  (iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (uVar6,"-tls1"),
                                                  pcVar25 = (code *)PTR_TLSv1_client_method_006a79cc
                                                  , iVar12 != 0)))) {
                                                  iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                     (uVar6,"-dtls1");
                                                  if (iVar12 == 0) {
                                                    local_244 = (undefined4 *)
                                                                (*(code *)
                                                  PTR_DTLSv1_client_method_006a79d0)();
                                                  local_1a8 = 1;
                                                  puVar22 = local_18c[0];
                                                  iVar12 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar6,"-fallback_scsv");
                                                    if (iVar12 == 0) {
                                                      local_1a4 = (char *)0x1;
                                                      iVar12 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar6,"-timeout");
                                                      if (iVar12 == 0) {
                                                        local_1a0 = 1;
                                                        iVar12 = local_res0[0];
                                                        goto LAB_0044aa58;
                                                      }
                                                      iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar6,&DAT_0063b8b0);
                                                      if (iVar12 == 0) {
                                                        local_res0[0] = local_res0[0] + -1;
                                                        if (local_res0[0] < 1) goto LAB_0044abb8;
                                                        local_18c[0] = puVar22 + 1;
                                                        local_1c0 = (*(code *)PTR_strtol_006a9958)
                                                                              (puVar22[1],0,10);
                                                        puVar22 = local_18c[0];
                                                        iVar12 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar6,"-bugs");
                                                        if (iVar12 == 0) {
                                                          local_1b4 = (char *)0x1;
                                                          iVar12 = local_res0[0];
                                                        }
                                                        else {
                                                          iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (uVar6,"-keyform");
                                                          if (iVar12 == 0) {
                                                            local_res0[0] = local_res0[0] + -1;
                                                            if (local_res0[0] < 1)
                                                            goto LAB_0044abb8;
                                                            local_18c[0] = puVar22 + 1;
                                                            local_1dc = str2fmt(puVar22[1]);
                                                            puVar22 = local_18c[0];
                                                            iVar12 = local_res0[0];
                                                          }
                                                          else {
                                                            iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (uVar6,"-pass");
                                                            if (iVar12 == 0) {
                                                              local_res0[0] = local_res0[0] + -1;
                                                              if (local_res0[0] < 1)
                                                              goto LAB_0044abb8;
                                                              local_1ec = puVar22[1];
                                                              puVar22 = puVar22 + 1;
                                                              iVar12 = local_res0[0];
                                                            }
                                                            else {
                                                              iVar12 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(uVar6,&DAT_006326ec);
                                                              if (iVar12 == 0) {
                                                                local_res0[0] = local_res0[0] + -1;
                                                                if (local_res0[0] < 1)
                                                                goto LAB_0044abb8;
                                                                local_1f0 = (undefined4 *)puVar22[1]
                                                                ;
                                                                puVar22 = puVar22 + 1;
                                                                iVar12 = local_res0[0];
                                                              }
                                                              else {
                                                                iVar12 = (*(code *)
                                                  PTR_strcmp_006a9b18)(uVar6,"-reconnect");
                                                  if (iVar12 == 0) {
                                                    local_1d8 = 5;
                                                    iVar12 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar6,"-CApath");
                                                    if (iVar12 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      if (local_res0[0] < 1) goto LAB_0044abb8;
                                                      local_1c8 = puVar22[1];
                                                      puVar22 = puVar22 + 1;
                                                      iVar12 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar6,"-CAfile");
                                                      if (iVar12 == 0) {
                                                        local_res0[0] = local_res0[0] + -1;
                                                        if (local_res0[0] < 1) goto LAB_0044abb8;
                                                        local_1c4 = (undefined **)puVar22[1];
                                                        puVar22 = puVar22 + 1;
                                                        iVar12 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar6,"-no_tls1_2");
                                                        if (iVar12 == 0) {
                                                          local_204 = local_204 | 0x8000000;
                                                          iVar12 = local_res0[0];
                                                        }
                                                        else {
                                                          iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (uVar6,"-no_tls1_1");
                                                          if (iVar12 == 0) {
                                                            local_204 = local_204 | 0x10000000;
                                                            iVar12 = local_res0[0];
                                                          }
                                                          else {
                                                            iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (uVar6,"-no_tls1");
                                                            if (iVar12 == 0) {
                                                              local_204 = local_204 | 0x4000000;
                                                              iVar12 = local_res0[0];
                                                            }
                                                            else {
                                                              iVar12 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(uVar6,"-no_ssl3");
                                                              if (iVar12 == 0) {
                                                                local_204 = local_204 | 0x2000000;
                                                                iVar12 = local_res0[0];
                                                              }
                                                              else {
                                                                iVar12 = (*(code *)
                                                  PTR_strcmp_006a9b18)(uVar6,"-no_ssl2");
                                                  if (iVar12 == 0) {
                                                    local_204 = local_204 | 0x1000000;
                                                    iVar12 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar6,"-no_comp");
                                                    if (iVar12 == 0) {
                                                      local_204 = local_204 | 0x20000;
                                                      iVar12 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar6,"-no_ticket");
                                                      if (iVar12 == 0) {
                                                        local_204 = local_204 | 0x4000;
                                                        iVar12 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar6,"-nextprotoneg");
                                                        if (iVar12 == 0) {
                                                          local_res0[0] = local_res0[0] + -1;
                                                          if (local_res0[0] < 1) goto LAB_0044abb8;
                                                          local_208 = puVar22[1];
                                                          puVar22 = puVar22 + 1;
                                                          iVar12 = local_res0[0];
                                                        }
                                                        else {
                                                          iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (uVar6,"-serverpref");
                                                          if (iVar12 == 0) {
                                                            local_204 = local_204 | 0x400000;
                                                            iVar12 = local_res0[0];
                                                          }
                                                          else {
                                                            iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (uVar6,
                                                  "-legacy_renegotiation");
                                                  if (iVar12 == 0) {
                                                    local_204 = local_204 | 0x40000;
                                                    iVar12 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar6,
                                                  "-legacy_server_connect");
                                                  if (iVar12 == 0) {
                                                    local_204 = local_204 | 4;
                                                    iVar12 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar6,
                                                  "-no_legacy_server_connect");
                                                  if (iVar12 == 0) {
                                                    local_1cc = 4;
                                                    iVar12 = local_res0[0];
                                                  }
                                                  else {
                                                    iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar6,"-cipher");
                                                    if (iVar12 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      if (local_res0[0] < 1) goto LAB_0044abb8;
                                                      local_1b8 = (char *)puVar22[1];
                                                      puVar22 = puVar22 + 1;
                                                      iVar12 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar6,"-nbio");
                                                      if (iVar12 == 0) {
                                                        c_nbio = 1;
                                                        iVar12 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar6,"-starttls");
                                                        if (iVar12 == 0) {
                                                          iVar12 = local_res0[0] + -1;
                                                          local_res0[0] = iVar12;
                                                          if (iVar12 < 1) goto LAB_0044abb8;
                                                          pcVar24 = (char *)puVar22[1];
                                                          puVar22 = puVar22 + 1;
                                                          local_18c[0] = puVar22;
                                                          iVar8 = (*(code *)PTR_strcmp_006a9b18)
                                                                            (pcVar24,&DAT_0063d428);
                                                          if (iVar8 == 0) {
                                                            local_1fc = 1;
                                                          }
                                                          else {
                                                            iVar8 = (*(code *)PTR_strcmp_006a9b18)
                                                                              (pcVar24,&DAT_0063d430
                                                                              );
                                                            if (iVar8 == 0) {
                                                              local_1fc = 2;
                                                            }
                                                            else {
                                                              iVar8 = (*(code *)PTR_strcmp_006a9b18)
                                                                                (pcVar24,&
                                                  DAT_0063d438);
                                                  if (iVar8 == 0) {
                                                    local_1fc = 3;
                                                  }
                                                  else if ((((*pcVar24 == 'f') &&
                                                            (pcVar24[1] == 't')) &&
                                                           (pcVar24[2] == 'p')) &&
                                                          (pcVar24[3] == '\0')) {
                                                    local_1fc = 4;
                                                  }
                                                  else {
                                                    iVar8 = (*(code *)PTR_strcmp_006a9b18)
                                                                      (pcVar24,&DAT_0063d440);
                                                    if (iVar8 != 0) goto LAB_0044abb8;
                                                    local_1fc = 5;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                       (uVar6,"-engine");
                                                    if (iVar12 == 0) {
                                                      local_res0[0] = local_res0[0] + -1;
                                                      if (local_res0[0] < 1) goto LAB_0044abb8;
                                                      local_1e8 = (char *)puVar22[1];
                                                      puVar22 = puVar22 + 1;
                                                      iVar12 = local_res0[0];
                                                    }
                                                    else {
                                                      iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                         (uVar6,"-ssl_client_engine"
                                                                         );
                                                      if (iVar12 == 0) {
                                                        local_res0[0] = local_res0[0] + -1;
                                                        if (local_res0[0] < 1) goto LAB_0044abb8;
                                                        local_1e4 = (uint *)puVar22[1];
                                                        puVar22 = puVar22 + 1;
                                                        iVar12 = local_res0[0];
                                                      }
                                                      else {
                                                        iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                           (uVar6,"-rand");
                                                        if (iVar12 == 0) {
                                                          local_res0[0] = local_res0[0] + -1;
                                                          if (local_res0[0] < 1) goto LAB_0044abb8;
                                                          local_1e0 = (uint *)puVar22[1];
                                                          puVar22 = puVar22 + 1;
                                                          iVar12 = local_res0[0];
                                                        }
                                                        else {
                                                          iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                             (uVar6,"-servername");
                                                          if (iVar12 == 0) {
                                                            local_res0[0] = local_res0[0] + -1;
                                                            if (local_res0[0] < 1)
                                                            goto LAB_0044abb8;
                                                            local_1d4 = (undefined **)puVar22[1];
                                                            puVar22 = puVar22 + 1;
                                                            iVar12 = local_res0[0];
                                                          }
                                                          else {
                                                            iVar12 = (*(code *)PTR_strcmp_006a9b18)
                                                                               (uVar6,"-use_srtp");
                                                            if (iVar12 == 0) {
                                                              local_res0[0] = local_res0[0] + -1;
                                                              if (local_res0[0] < 1)
                                                              goto LAB_0044abb8;
                                                              srtp_profiles = puVar22[1];
                                                              puVar22 = puVar22 + 1;
                                                              iVar12 = local_res0[0];
                                                            }
                                                            else {
                                                              iVar12 = (*(code *)PTR_strcmp_006a9b18
                                                                       )(uVar6,"-keymatexport");
                                                              if (iVar12 == 0) {
                                                                local_res0[0] = local_res0[0] + -1;
                                                                if (local_res0[0] < 1)
                                                                goto LAB_0044abb8;
                                                                keymatexportlabel = puVar22[1];
                                                                puVar22 = puVar22 + 1;
                                                                iVar12 = local_res0[0];
                                                              }
                                                              else {
                                                                iVar12 = (*(code *)
                                                  PTR_strcmp_006a9b18)(uVar6,"-keymatexportlen");
                                                  if (iVar12 != 0) {
                                                    (*(code *)PTR_BIO_printf_006a6e38)
                                                              (*puVar9,"unknown option %s\n",uVar6);
                                                    goto LAB_0044abb8;
                                                  }
                                                  local_res0[0] = local_res0[0] + -1;
                                                  if (local_res0[0] < 1) goto LAB_0044abb8;
                                                  local_18c[0] = puVar22 + 1;
                                                  keymatexportlen =
                                                       (*(code *)PTR_strtol_006a9958)
                                                                 (puVar22[1],0,10);
                                                  puVar22 = local_18c[0];
                                                  iVar12 = local_res0[0];
                                                  if (keymatexportlen == 0) goto LAB_0044abb8;
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
                                                  goto LAB_0044aa58;
                                                }
                                              }
                                            }
                                          }
                                        }
                                        local_244 = (undefined4 *)(*pcVar25)();
                                        puVar22 = local_18c[0];
                                        iVar12 = local_res0[0];
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
LAB_0044aa58:
        local_res0[0] = iVar12 + -1;
        local_18c[0] = puVar22 + 1;
        goto LAB_0044aa1c;
      }
    }
    puVar19 = (undefined *)0x0;
    puVar22 = (undefined4 *)0x0;
    (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"out of memory\n");
    pcVar24 = (char *)0x0;
    pcVar21 = (char *)0x0;
  }
LAB_0044a748:
  puVar18 = &_gp_1;
  puVar17 = (undefined4 *)&_gp_1;
  local_24c = (undefined *)0x1;
  if (next_proto._0_4_ == 0) goto LAB_0044a768;
LAB_0044a75c:
  (*(code *)PTR_CRYPTO_free_006a6e88)();
LAB_0044a768:
  if (puVar19 != (undefined *)0x0) {
    (*(code *)PTR_SSL_CTX_free_006a7890)(puVar19);
  }
  do {
    if (pcVar24 != (char *)0x0) {
      (*(code *)PTR_X509_free_006a6e90)(pcVar24);
    }
    if (puVar22 != (undefined4 *)0x0) {
      (*(code *)PTR_EVP_PKEY_free_006a6e78)(puVar22);
    }
    if (local_178 != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_154);
    if (local_174 != 0) {
      (*(code *)PTR_X509_VERIFY_PARAM_free_006a72cc)();
    }
    if (pcVar26 != (char *)0x0) {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(pcVar26,0x2000);
      (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar26);
    }
    if (puVar20 != (undefined *)0x0) {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(puVar20,0x2000);
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar20);
    }
    if (pcVar21 != (char *)0x0) {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(pcVar21,0x2000);
      (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar21);
    }
    if (*(int *)(&DAT_ffffa1d8 + (int)puVar18) != 0) {
      (*(code *)PTR_BIO_free_006a6e70)();
      *(undefined4 *)(&DAT_ffffa1d8 + (int)puVar18) = 0;
    }
    if (local_2c == *(int *)puVar7) {
      return local_24c;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    puVar10 = puVar17;
    puVar18 = puVar20;
    pcVar14 = pcVar21;
switchD_0044cbd0_caseD_7:
    puVar20 = local_24c;
    (*(code *)PTR_memset_006a99f4)(local_1e4,0,0x80);
    (*(code *)PTR_memset_006a99f4)(local_1e0,0,0x80);
    iVar12 = (*(code *)PTR_SSL_version_006a77ec)(puVar10);
    if (iVar12 == 0xfeff) {
      local_1f0 = &local_164;
      iVar12 = (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x49,0,local_1f0);
      if (iVar12 == 0) goto LAB_0044be84;
    }
    else {
LAB_0044be84:
      local_1f0 = (undefined4 *)0x0;
    }
    uVar5 = (*(code *)PTR_SSL_state_006a7808)(puVar10);
    pcVar21 = local_214;
    if (((uVar5 & 0x3000) == 0) ||
       (iVar12 = (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0xc,0,0), iVar12 != 0)) {
      if (local_20c == 0) {
LAB_0044bf64:
        local_20c = 0;
        if (pcVar26 != (char *)0x0) {
          bVar11 = true;
          goto LAB_0044bf70;
        }
LAB_0044c7b4:
        puVar4 = PTR_stdin_006a9a14;
        if (puVar19 != (undefined *)0x0) {
          iVar12 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)PTR_stdin_006a9a14);
          uVar6 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)puVar4);
          iVar8 = (*(code *)PTR___fdelt_chk_006a9aa0)(uVar6);
          auStack_12c[iVar8] = 1 << (iVar12 % 0x20 & 0x1fU) | auStack_12c[iVar8];
        }
LAB_0044c7c4:
        if (pcVar26 != (char *)0x0) {
          iVar12 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
          uVar6 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
          iVar8 = (*(code *)PTR___fdelt_chk_006a9aa0)(uVar6);
          auStack_12c[iVar8] = auStack_12c[iVar8] | 1 << (iVar12 % 0x20 & 0x1fU);
        }
        goto LAB_0044c4b8;
      }
      if (local_200 == 0) {
LAB_0044bf0c:
        uVar6 = *(undefined4 *)(&DAT_ffffa1d8 + (int)puVar18);
      }
      else {
        iVar12 = (*(code *)PTR_BIO_new_file_006a6eac)(local_200,"w");
        if (iVar12 != 0) {
          uVar6 = (*(code *)PTR_SSL_get_session_006a77ac)(puVar10);
          (*(code *)PTR_PEM_write_bio_SSL_SESSION_006a77b0)(iVar12,uVar6);
          (*(code *)PTR_BIO_free_006a6e70)(iVar12);
          goto LAB_0044bf0c;
        }
        (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"Error writing session file %s\n",local_200);
        uVar6 = *(undefined4 *)(&DAT_ffffa1d8 + (int)puVar18);
      }
      print_stuff(uVar6,puVar10,local_1f4);
      if (local_1f4 == 1) {
        local_1f4 = 0;
      }
      if (local_1fc != 0) {
        (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"%s",local_214);
      }
      if (local_1d8 == 0) {
        local_1fc = 0;
        goto LAB_0044bf64;
      }
      local_1d8 = local_1d8 + -1;
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)(&DAT_ffffa1d8 + (int)local_218),
                 "drop connection and then reconnect\n");
      (*(code *)PTR_SSL_shutdown_006a79c4)(puVar10);
      (*(code *)PTR_SSL_set_connect_state_006a79bc)(puVar10);
      uVar6 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
      (*(code *)PTR_shutdown_006a995c)(uVar6,0);
      uVar6 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
      (*(code *)PTR_close_006a994c)(uVar6);
      local_20c = 0;
      local_1fc = 0;
LAB_0044bb20:
      puVar20 = local_24c;
      iVar12 = init_client(local_19c,local_17c,(int)local_182,local_1a8);
      puVar17 = (undefined4 *)local_21c;
      puVar18 = local_218;
      puVar19 = local_234;
      puVar22 = local_22c;
      pcVar24 = local_224;
      pcVar26 = local_210;
      if (iVar12 == 0) {
        puVar9 = (undefined4 *)*puVar9;
        puVar10 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
        uVar6 = *puVar10;
        pcVar14 = "connect:errno=%d\n";
LAB_0044ce14:
        (*(code *)PTR_BIO_printf_006a6e38)(puVar9,pcVar14,uVar6);
        (*(code *)PTR_shutdown_006a995c)(local_180,0);
        (*(code *)PTR_close_006a994c)(local_180);
        local_24c = (undefined *)0x1;
        goto LAB_0044c0b8;
      }
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)(&DAT_ffffa1d8 + (int)local_218),local_1b8 + -0x1fd4,local_180);
      if (*(int *)(local_198 + -0x5e08) != 0) {
        local_168 = 1;
        (*(code *)PTR_BIO_printf_006a6e38)
                  (*(undefined4 *)(&DAT_ffffa1d8 + (int)local_1bc),"turning on non blocking io\n");
        iVar12 = (*(code *)PTR_BIO_socket_ioctl_006a77dc)(local_180,0x667e,&local_168);
        if (iVar12 < 0) {
          (*(code *)PTR_ERR_print_errors_006a6e40)(*puVar9);
          local_24c = (undefined *)0x1;
          goto LAB_0044c0b8;
        }
      }
      if ((c_Pause & 1) != 0) {
        (*(code *)PTR_SSL_set_debug_006a7834)(puVar10,1);
      }
      iVar12 = (*(code *)PTR_SSL_version_006a77ec)(puVar10);
      pcVar14 = local_210;
      if (iVar12 == 0xfeff) {
        puVar4 = (undefined *)(*(code *)PTR_BIO_new_dgram_006a7840)(local_180,0);
        iVar12 = (*(code *)PTR_getsockname_006a9994)(local_180,auStack_13c,&local_16c);
        if (iVar12 < 0) {
          puVar9 = (undefined4 *)*puVar9;
          puVar10 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
          uVar6 = *puVar10;
          pcVar14 = "getsockname:errno=%d\n";
          goto LAB_0044ce14;
        }
        (*(code *)PTR_BIO_ctrl_006a6e18)(puVar4,0x20,1,auStack_13c);
        if (local_1a0 != 0) {
          local_164 = 0;
          local_160 = 250000;
          (*(code *)PTR_BIO_ctrl_006a6e18)(puVar4,0x21,0,&local_164);
          local_164 = 0;
          local_160 = 250000;
          (*(code *)PTR_BIO_ctrl_006a6e18)(puVar4,0x23,0,&local_164);
        }
        if (local_1c0 != 0) {
          iVar12 = (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x79,0,0);
          if (local_1c0 < iVar12) {
            uVar16 = *puVar9;
            uVar6 = (*(code *)PTR_SSL_ctrl_006a7788)(local_244,0x79,0,0);
            (*(code *)PTR_BIO_printf_006a6e38)(uVar16,"MTU too small. Must be at least %ld\n",uVar6)
            ;
          }
          else {
            (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x20,0x1000,0);
            iVar12 = (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x78,local_1c0,0);
            if (iVar12 != 0) goto LAB_0044bbc4;
            (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"Failed to set MTU\n");
          }
          (*(code *)PTR_BIO_free_006a6e70)(puVar4);
          local_24c = (undefined *)0x1;
          local_240 = puVar4;
          goto LAB_0044c040;
        }
        (*(code *)PTR_BIO_ctrl_006a6e18)(puVar4,0x27,0,0);
      }
      else {
        puVar4 = (undefined *)(*(code *)PTR_BIO_new_socket_006a77f0)(local_180,0);
      }
LAB_0044bbc4:
      if (local_1ac != 0) {
        uVar6 = (*(code *)PTR_BIO_f_nbio_test_006a77f4)();
        uVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
        puVar4 = (undefined *)(*(code *)PTR_BIO_push_006a74c4)(uVar6,puVar4);
      }
      if (c_debug != 0) {
        (*(code *)PTR_SSL_set_debug_006a7834)(puVar10,1);
        (*(code *)PTR_BIO_set_callback_006a74dc)(puVar4,PTR_bio_dump_callback_006a783c);
        (*(code *)PTR_BIO_set_callback_arg_006a74e4)
                  (puVar4,*(undefined4 *)(&DAT_ffffa1d8 + (int)local_218));
      }
      if (*(int *)(local_240 + -0x5e1c) != 0) {
        (*(code *)PTR_SSL_set_msg_callback_006a7800)(puVar10,PTR_msg_cb_006a7830);
        (*(code *)PTR_SSL_ctrl_006a7788)
                  (puVar10,0x10,0,*(undefined4 *)(&DAT_ffffa1d8 + (int)local_218));
      }
      if (c_tlsextdebug != 0) {
        (*(code *)PTR_SSL_callback_ctrl_006a7828)(puVar10,0x38,PTR_tlsext_cb_006a782c);
        (*(code *)PTR_SSL_ctrl_006a7788)
                  (puVar10,0x39,0,*(undefined4 *)(&DAT_ffffa1d8 + (int)local_218));
      }
      if (c_status_req != 0) {
        (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x41,1,0);
        (*(code *)PTR_SSL_CTX_callback_ctrl_006a7824)(local_234,0x3f,ocsp_resp_cb);
        (*(code *)PTR_SSL_CTX_ctrl_006a775c)
                  (local_234,0x40,0,*(undefined4 *)(&DAT_ffffa1d8 + (int)local_218));
      }
      (*(code *)PTR_SSL_set_bio_006a77f8)(puVar10,puVar4,puVar4);
      (*(code *)PTR_SSL_set_connect_state_006a79bc)(puVar10);
      iVar12 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
      local_1dc = iVar12 + 1;
      if (local_1fc == 1) {
        uVar6 = (*(code *)PTR_BIO_f_buffer_006a7854)();
        uVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
        (*(code *)PTR_BIO_push_006a74c4)(uVar6,puVar4);
        do {
          iVar12 = (*(code *)PTR_BIO_gets_006a74d4)(uVar6,pcVar21,0x2000);
          if (iVar12 < 4) break;
        } while (pcVar21[3] == '-');
        bVar11 = false;
        (*(code *)PTR_BIO_printf_006a6e38)(uVar6,"EHLO openssl.client.net\r\n");
        (*(code *)PTR_BIO_ctrl_006a6e18)(uVar6,0xb,0,0);
        do {
          iVar12 = (*(code *)PTR_BIO_gets_006a74d4)(uVar6,pcVar21,0x2000);
          iVar8 = (*(code *)PTR_strstr_006a9b1c)(pcVar21,local_1e8);
          if (iVar8 != 0) {
            bVar11 = true;
          }
        } while ((3 < iVar12) && (pcVar21[3] == '-'));
        (*(code *)PTR_BIO_ctrl_006a6e18)(uVar6,0xb,0,0);
        (*(code *)PTR_BIO_pop_006a79c8)(uVar6);
        (*(code *)PTR_BIO_free_006a6e70)(uVar6);
        if (!bVar11) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (*puVar9,"didn\'t found starttls in server response, try anyway...\n");
        }
        pcVar24 = "STARTTLS\r\n";
LAB_0044d1e4:
        (*(code *)PTR_BIO_printf_006a6e38)(puVar4,pcVar24);
        (*(code *)PTR_BIO_read_006a74c0)(puVar4,local_24c,0x2000);
      }
      else {
        if (local_1fc == 2) {
          (*(code *)PTR_BIO_read_006a74c0)(puVar4,pcVar21,0x2000);
          pcVar24 = "STLS\r\n";
          goto LAB_0044d1e4;
        }
        if (local_1fc == 3) {
          bVar11 = false;
          uVar6 = (*(code *)PTR_BIO_f_buffer_006a7854)();
          uVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
          (*(code *)PTR_BIO_push_006a74c4)(uVar6,puVar4);
          (*(code *)PTR_BIO_gets_006a74d4)(uVar6,pcVar21,0x2000);
          (*(code *)PTR_BIO_printf_006a6e38)(uVar6,". CAPABILITY\r\n");
          (*(code *)PTR_BIO_ctrl_006a6e18)(uVar6,0xb,0,0);
          do {
            iVar12 = (*(code *)PTR_BIO_gets_006a74d4)(uVar6,pcVar21,0x2000);
            iVar8 = (*(code *)PTR_strstr_006a9b1c)(pcVar21,local_1e8);
            if (iVar8 != 0) {
              bVar11 = true;
            }
          } while ((3 < iVar12) && (*pcVar21 != '.'));
          (*(code *)PTR_BIO_ctrl_006a6e18)(uVar6,0xb,0,0);
          (*(code *)PTR_BIO_pop_006a79c8)(uVar6);
          (*(code *)PTR_BIO_free_006a6e70)(uVar6);
          if (!bVar11) {
            (*(code *)PTR_BIO_printf_006a6e38)
                      (*puVar9,"didn\'t found STARTTLS in server response, try anyway...\n");
          }
          pcVar24 = ". STARTTLS\r\n";
          goto LAB_0044d1e4;
        }
        if (local_1fc == 4) {
          uVar6 = (*(code *)PTR_BIO_f_buffer_006a7854)();
          uVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar6);
          (*(code *)PTR_BIO_push_006a74c4)(uVar6,puVar4);
          do {
            iVar12 = (*(code *)PTR_BIO_gets_006a74d4)(uVar6,pcVar21,0x2000);
            if (iVar12 < 4) break;
          } while (pcVar21[3] == '-');
          (*(code *)PTR_BIO_ctrl_006a6e18)(uVar6,0xb,0,0);
          (*(code *)PTR_BIO_pop_006a79c8)(uVar6);
          (*(code *)PTR_BIO_free_006a6e70)(uVar6);
          pcVar24 = "AUTH TLS\r\n";
          goto LAB_0044d1e4;
        }
        if (local_1fc == 5) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (puVar4,
                     "<stream:stream xmlns:stream=\'http://etherx.jabber.org/streams\' xmlns=\'jabber:client\' to=\'%s\' version=\'1.0\'>"
                     ,local_17c);
          while( true ) {
            iVar12 = (*(code *)PTR_BIO_read_006a74c0)(puVar4,pcVar21,0x2000);
            pcVar21[iVar12] = '\0';
            iVar12 = (*(code *)PTR_strstr_006a9b1c)(pcVar21,local_1b4);
            if (iVar12 != 0) break;
            iVar12 = (*(code *)PTR_strstr_006a9b1c)(pcVar21,local_1a4);
            if (iVar12 != 0) goto LAB_0044d324;
          }
          (*(code *)PTR_BIO_printf_006a6e38)
                    (puVar4,"<starttls xmlns=\'urn:ietf:params:xml:ns:xmpp-tls\'/>");
          iVar12 = (*(code *)PTR_BIO_read_006a74c0)(puVar4,local_24c,0x2000);
          local_24c[iVar12] = 0;
          iVar12 = (*(code *)PTR_strstr_006a9b1c)(local_24c,"<proceed");
          if (iVar12 == 0) {
LAB_0044d324:
            local_24c = (undefined *)0x1;
            goto LAB_0044c040;
          }
          *pcVar21 = '\0';
        }
      }
      local_1e0 = auStack_ac;
      local_1f8 = 0;
      local_204 = 0;
      puVar19 = (undefined *)0x1;
      local_208 = 0;
      local_1e4 = auStack_12c;
      pcVar24 = (char *)0x1;
      local_1d4 = &switchD_0044bfe8::switchdataD_0063e320;
      puVar22 = (undefined4 *)0x0;
      local_1c4 = &switchD_0044cbd0::switchdataD_0063e33c;
      pcVar26 = (char *)0x1;
      local_214 = pcVar21;
      goto switchD_0044cbd0_caseD_7;
    }
    local_20c = 1;
    if (pcVar26 != (char *)0x0) {
      bVar11 = false;
LAB_0044bf70:
      iVar12 = (*(code *)PTR_SSL_pending_006a7804)(puVar10);
      if (iVar12 == 0) {
        if (bVar11) goto LAB_0044c7b4;
        goto LAB_0044c7c4;
      }
      iVar12 = (*(code *)PTR_SSL_version_006a77ec)(puVar10);
      if ((iVar12 == 0xfeff) &&
         (iVar12 = (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x4a,0,0), 0 < iVar12)) {
        bVar11 = true;
        goto LAB_0044c524;
      }
LAB_0044bfa4:
      uVar6 = (*(code *)PTR_SSL_read_006a7818)(puVar10,local_24c,0x400);
      uVar5 = (*(code *)PTR_SSL_get_error_006a77a0)(puVar10,uVar6);
      if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x0044bfe8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        puVar7 = (undefined *)(*(code *)local_1d4[uVar5])();
        return puVar7;
      }
      goto switchD_0044cbd0_caseD_7;
    }
LAB_0044c4b8:
    if (pcVar24 != (char *)0x0) {
      iVar12 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
      uVar6 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
      iVar8 = (*(code *)PTR___fdelt_chk_006a9aa0)(uVar6);
      auStack_ac[iVar8] = auStack_ac[iVar8] | 1 << (iVar12 % 0x20 & 0x1fU);
    }
    iVar12 = (*(code *)PTR_select_006a9ac4)(local_1dc,local_1e4,local_1e0,0,local_1f0);
    if (iVar12 < 0) {
      uVar6 = *puVar9;
      puVar9 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
      (*(code *)PTR_BIO_printf_006a6e38)(uVar6,"bad select %d\n",*puVar9);
      local_24c = (undefined *)0x1;
      goto LAB_0044c040;
    }
    iVar12 = (*(code *)PTR_SSL_version_006a77ec)(puVar10);
    if ((iVar12 == 0xfeff) &&
       (iVar12 = (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x4a,0,0), 0 < iVar12)) {
      bVar11 = false;
LAB_0044c524:
      (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"TIMEOUT occured\n");
      if (bVar11) goto LAB_0044bfa4;
    }
    uVar6 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
    iVar12 = (*(code *)PTR___fdelt_chk_006a9aa0)(uVar6);
    uVar5 = auStack_ac[iVar12];
    iVar12 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
    puVar4 = PTR_stdout_006a99c8;
    if ((1 << (iVar12 % 0x20 & 0x1fU) & uVar5) != 0) {
      uVar6 = (*(code *)PTR_SSL_write_006a7820)(puVar10,pcVar14 + local_208,puVar22);
      uVar5 = (*(code *)PTR_SSL_get_error_006a77a0)(puVar10,uVar6);
      if (uVar5 < 7) {
                    /* WARNING: Could not recover jumptable at 0x0044cbd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        puVar7 = (undefined *)(*(code *)local_1c4[uVar5])();
        return puVar7;
      }
      goto switchD_0044cbd0_caseD_7;
    }
    uVar6 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)PTR_stdout_006a99c8);
    iVar12 = (*(code *)PTR___fdelt_chk_006a9aa0)(uVar6);
    uVar5 = auStack_ac[iVar12];
    iVar12 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)puVar4);
    if ((1 << (iVar12 % 0x20 & 0x1fU) & uVar5) == 0) {
      uVar6 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
      iVar12 = (*(code *)PTR___fdelt_chk_006a9aa0)(uVar6);
      uVar15 = auStack_12c[iVar12];
      uVar5 = (*(code *)PTR_SSL_get_fd_006a79c0)(puVar10);
      puVar4 = PTR_stdin_006a9a14;
      if ((1 << (uVar5 & 0x1f) & uVar15) == 0) {
        uVar6 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)PTR_stdin_006a9a14);
        iVar12 = (*(code *)PTR___fdelt_chk_006a9aa0)(uVar6);
        uVar5 = auStack_12c[iVar12];
        iVar12 = (*(code *)PTR_fileno_006a99dc)(*(undefined4 *)puVar4);
        if ((1 << (iVar12 % 0x20 & 0x1fU) & uVar5) != 0) {
          if (local_1b0 == 0) {
            puVar22 = (undefined4 *)raw_read_stdin(pcVar14,0x2000);
          }
          else {
            puVar22 = (undefined4 *)raw_read_stdin(pcVar14,0x1000);
            iVar12 = 0;
            pcVar24 = pcVar14;
            while ((int)pcVar24 - (int)pcVar14 < (int)puVar22) {
              cVar1 = *pcVar24;
              pcVar24 = pcVar24 + 1;
              if (cVar1 == '\n') {
                iVar12 = iVar12 + 1;
              }
            }
            puVar19 = (undefined *)((int)puVar22 + -1);
            pcVar24 = pcVar14 + (int)puVar22;
            while (-1 < (int)puVar19) {
              pcVar14[(int)(puVar19 + iVar12)] = pcVar24[-1];
              if (pcVar24[-1] == '\n') {
                iVar12 = iVar12 + -1;
                puVar22 = (undefined4 *)((int)puVar22 + 1);
                puVar4 = puVar19 + iVar12;
                puVar19 = puVar19 + -1;
                pcVar14[(int)puVar4] = '\r';
                pcVar24 = pcVar24 + -1;
              }
              else {
                puVar19 = puVar19 + -1;
                pcVar24 = pcVar24 + -1;
              }
            }
            if (iVar12 != 0) {
              puVar7 = (undefined *)
                       (*(code *)PTR___assert_fail_006a993c)
                                 ("lf_num == 0",local_220 + -0x2d68,0x724,"s_client_main");
              return puVar7;
            }
          }
          pcVar24 = (char *)0x1;
          if (c_ign_eof == 0) {
            if (((int)puVar22 < 1) || (cVar1 = *pcVar14, cVar1 == 'Q')) {
              uVar6 = *puVar9;
              goto LAB_0044cee8;
            }
            if (cVar1 == 'R') {
              pcVar24 = (char *)0x1;
              puVar19 = (undefined *)0x0;
              (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"RENEGOTIATING\n");
              puVar22 = (undefined4 *)0x0;
              (*(code *)PTR_SSL_renegotiate_006a7848)(puVar10);
              goto switchD_0044cbd0_caseD_7;
            }
            if (cVar1 == 'B') {
              pcVar24 = (char *)0x1;
              puVar19 = (undefined *)0x0;
              (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"HEARTBEATING\n");
              puVar22 = (undefined4 *)0x0;
              (*(code *)PTR_SSL_ctrl_006a7788)(puVar10,0x55,0,0);
              goto switchD_0044cbd0_caseD_7;
            }
          }
          local_208 = 0;
          puVar19 = (undefined *)0x0;
        }
        goto switchD_0044cbd0_caseD_7;
      }
      goto LAB_0044bfa4;
    }
    iVar12 = raw_write_stdout(local_24c + local_1f8,local_204);
    if (0 < iVar12) {
      local_204 = local_204 - iVar12;
      local_1f8 = local_1f8 + iVar12;
      if ((int)local_204 < 1) {
        pcVar26 = (char *)0x1;
      }
      goto switchD_0044cbd0_caseD_7;
    }
    uVar6 = *(undefined4 *)(&DAT_ffffa1d8 + (int)puVar18);
LAB_0044cee8:
    (*(code *)PTR_BIO_printf_006a6e38)(uVar6,"DONE\n");
    local_24c = (undefined *)0x0;
LAB_0044c040:
    if (local_20c != 0) {
      print_stuff(*(undefined4 *)(&DAT_ffffa1d8 + (int)puVar18),local_244,local_1f4);
    }
    (*(code *)PTR_SSL_shutdown_006a79c4)(local_244);
    uVar6 = (*(code *)PTR_SSL_get_fd_006a79c0)(local_244);
    (*(code *)PTR_shutdown_006a995c)(uVar6,0);
    uVar6 = (*(code *)PTR_SSL_get_fd_006a79c0)(local_244);
    (*(code *)PTR_close_006a994c)(uVar6);
    puVar9 = local_244;
    puVar17 = (undefined4 *)local_21c;
    puVar19 = local_234;
    puVar22 = local_22c;
    pcVar24 = local_224;
    pcVar26 = pcVar14;
LAB_0044c0b8:
    if (local_244 != (undefined4 *)0x0) {
      if (local_228 != 0) {
        print_stuff(*(undefined4 *)(&DAT_ffffa1d8 + (int)puVar18),local_244,1);
      }
      (*(code *)PTR_SSL_free_006a7810)(local_244);
    }
    if (puVar17[-0x178f] != 0) goto LAB_0044a75c;
    (*(code *)PTR_SSL_CTX_free_006a7890)(puVar19);
  } while( true );
LAB_0044abb8:
  puVar22 = (undefined4 *)0x0;
  pcVar24 = (char *)0x0;
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"usage: s_client args\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -host host     - use -connect instead\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -port port     - use -connect instead\n");
  puVar19 = (undefined *)0x0;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -connect host:port - who to connect to (default is %s:%s)\n","localhost",
             &DAT_0063d4c4);
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -verify arg   - turn on peer certificate verification\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -verify_return_error - return verification errors\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -cert arg     - certificate file to use, PEM format assumed\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -certform arg - certificate format (PEM or DER) PEM default\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -key arg      - Private key file to use, in cert file if\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"                 not specified but cert file is.\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -keyform arg  - key format (PEM or DER) PEM default\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -pass arg     - private key file pass phrase source\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -CApath arg   - PEM format directory of CA\'s\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -CAfile arg   - PEM format file of CA\'s\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -no_alt_chains - only ever use the first certificate chain found\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -reconnect    - Drop and re-make the connection with the same Session-ID\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -pause        - sleep(1) after each read(2) and write(2) system call\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -prexit       - print session information even on connection failure\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -showcerts    - show all certificates in the chain\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -debug        - extra output\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -msg          - Show protocol messages\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -nbio_test    - more ssl protocol testing\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -state        - print the \'ssl\' states\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -nbio         - Run with non-blocking IO\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -crlf         - convert LF from terminal into CRLF\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -quiet        - no s_client output\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -ign_eof      - ignore input eof (default when -quiet)\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -no_ign_eof   - don\'t ignore input eof\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -psk_identity arg - PSK identity\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -psk arg      - PSK in hex (without 0x)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -srpuser user     - SRP authentification for \'user\'\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -srppass arg      - password for \'user\'\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -srp_lateuser     - SRP username into second ClientHello message\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -srp_moregroups   - Tolerate other than the known g N values.\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -srp_strength int - minimal length in bits for N (default %d).\n",0x400);
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -ssl2         - just use SSLv2\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -ssl3         - just use SSLv3\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -tls1_2       - just use TLSv1.2\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -tls1_1       - just use TLSv1.1\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -tls1         - just use TLSv1\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -dtls1        - just use DTLSv1\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -fallback_scsv - send TLS_FALLBACK_SCSV\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -mtu          - set the link layer MTU\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -no_tls1_2/-no_tls1_1/-no_tls1/-no_ssl3/-no_ssl2 - turn off that protocol\n")
  ;
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -bugs         - Switch on all SSL implementation bug workarounds\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -serverpref   - Use server\'s cipher preferences (only SSLv2)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -cipher       - preferred cipher to use, use the \'openssl ciphers\'\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"                 command to see what is available\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -starttls prot - use the STARTTLS command before starting TLS\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9,"                 for those protocols that support it, where\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9,"                 \'prot\' defines which one to assume.  Currently,\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9,"                 only \"smtp\", \"pop3\", \"imap\", \"ftp\" and \"xmpp\"\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9,"                 are supported.\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -engine id    - Initialise and use the specified engine\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -rand file%cfile%c...\n",0x3a,0x3a);
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -sess_out arg - file to write SSL session to\n");
  (*(code *)PTR_BIO_printf_006a6e38)(*puVar9," -sess_in arg  - file to read SSL session from\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -servername host  - Set TLS extension servername in ClientHello\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -tlsextdebug      - hex dump of all TLS extensions received\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -status           - request certificate status from server\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -no_ticket        - disable use of RFC4507bis session tickets\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9,
             " -nextprotoneg arg - enable NPN extension, considering named protocols supported (comma-separated list)\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -legacy_renegotiation - enable use of legacy renegotiation (dangerous)\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9,
             " -use_srtp profiles - Offer SRTP key management with a colon-separated profile list\n"
            );
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -keymatexport label   - Export keying material using label\n");
  (*(code *)PTR_BIO_printf_006a6e38)
            (*puVar9," -keymatexportlen len  - Export len bytes of keying material (default 20)\n");
  goto LAB_0044a748;
}

