
undefined1 * dtls1_send_newsession_ticket(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  cert_st *pcVar7;
  ssl3_state_st *psVar8;
  int iVar9;
  ssl3_enc_method *psVar10;
  BUF_MEM *pBVar11;
  undefined4 uVar12;
  dtls1_state_st *pdVar13;
  SSL *ssl;
  SSL_CIPHER *pSVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  char *pcVar18;
  _func_3152 *p_Var19;
  undefined *unaff_s2;
  undefined *unaff_s3;
  int unaff_s4;
  uint uVar20;
  uchar *unaff_s5;
  uchar **unaff_s6;
  uchar *puVar21;
  undefined *unaff_s7;
  code *pcVar22;
  uchar *unaff_s8;
  int iVar23;
  undefined4 uStack_208;
  int iStack_204;
  int iStack_200;
  undefined *puStack_1fc;
  undefined *puStack_1f8;
  undefined *puStack_1f4;
  int iStack_1f0;
  uchar *puStack_1ec;
  uchar **ppuStack_1e8;
  undefined *puStack_1e4;
  uchar *puStack_1e0;
  code *pcStack_1dc;
  undefined *local_1c8;
  int local_1c4;
  undefined *local_1c0;
  uchar *local_1b4;
  uchar *local_1b0;
  int local_1ac;
  undefined auStack_1a8 [140];
  undefined auStack_11c [208];
  undefined auStack_4c [16];
  uchar *local_3c;
  uchar *local_38;
  uchar *local_34;
  uchar *local_30;
  SSL *local_2c;
  
  puStack_1fc = PTR___stack_chk_guard_006aabf0;
  local_1c0 = &_gp;
  local_2c = *(SSL **)PTR___stack_chk_guard_006aabf0;
  if (*(int *)(param_1 + 0x34) == 0x21f0) {
    unaff_s6 = *(uchar ***)(param_1 + 0x170);
    unaff_s4 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),(uchar **)0x0);
    if (((0xff00 < unaff_s4) ||
        (iVar15 = (**(code **)(local_1c0 + -0x7940))
                            (*(undefined4 *)(param_1 + 0x3c),unaff_s4 + 0x92), iVar15 == 0)) ||
       (unaff_s5 = (uchar *)(**(code **)(local_1c0 + -0x7dd8))(unaff_s4,"d1_srvr.c",0x66c),
       unaff_s5 == (uchar *)0x0)) {
LAB_0049d6a0:
      puVar4 = (undefined1 *)0xffffffff;
      goto LAB_0049d334;
    }
    unaff_s2 = auStack_1a8;
    unaff_s3 = auStack_11c;
    local_1b4 = unaff_s5;
    i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),&local_1b4);
    local_1b4 = (uchar *)(*(int *)(*(int *)(param_1 + 0x3c) + 4) + 0xc);
    (**(code **)(local_1c0 + -0x7390))(unaff_s2);
    (**(code **)(local_1c0 + -0x73d4))(unaff_s3);
    if ((code *)unaff_s6[0x4e] == (code *)0x0) {
      local_1c8 = auStack_4c;
      (**(code **)(local_1c0 + -0x787c))(local_1c8,0x10);
      uVar12 = (**(code **)(local_1c0 + -0x7b2c))();
      (**(code **)(local_1c0 + -0x735c))(unaff_s2,uVar12,0,unaff_s6 + 0x4a);
      uVar12 = (**(code **)(local_1c0 + -0x6d74))();
      local_1c8 = (undefined *)0x0;
      (**(code **)(local_1c0 + -0x7340))(unaff_s3,unaff_s6 + 0x46,0x10,uVar12);
      local_3c = unaff_s6[0x42];
      local_38 = unaff_s6[0x43];
      local_34 = unaff_s6[0x44];
      local_30 = unaff_s6[0x45];
    }
    else {
      unaff_s7 = auStack_4c;
      local_1c4 = 1;
      local_1c8 = unaff_s3;
      iVar15 = (*(code *)unaff_s6[0x4e])(param_1,&local_3c,unaff_s7,unaff_s2);
      if (iVar15 < 0) {
        (**(code **)(local_1c0 + -0x7f58))(unaff_s5);
        goto LAB_0049d6a0;
      }
    }
    unaff_s7 = auStack_4c;
    pcVar22 = *(code **)(local_1c0 + -0x6d7c);
    *local_1b4 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xec);
    local_1b4[1] = (uchar)*(undefined2 *)(*(int *)(param_1 + 0xc0) + 0xec);
    local_1b4[2] = (uchar)((uint)*(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xec) >> 8);
    local_1b4[3] = (uchar)*(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xec);
    unaff_s8 = local_1b4 + 6;
    *(uchar **)(local_1b4 + 6) = local_3c;
    *(uchar **)(local_1b4 + 10) = local_38;
    *(uchar **)(local_1b4 + 0xe) = local_34;
    *(uchar **)(local_1b4 + 0x12) = local_30;
    puVar21 = local_1b4 + 0x16;
    local_1b4 = puVar21;
    uVar12 = (*pcVar22)(unaff_s2);
    unaff_s6 = &local_1b0;
    (**(code **)(local_1c0 + -0x52ec))(puVar21,unaff_s7,uVar12);
    iVar15 = (**(code **)(local_1c0 + -0x6d7c))(unaff_s2);
    local_1b4 = local_1b4 + iVar15;
    local_1c8 = (undefined *)unaff_s4;
    (**(code **)(local_1c0 + -0x7354))(unaff_s2,local_1b4,unaff_s6,unaff_s5);
    local_1b4 = local_1b4 + (int)local_1b0;
    (**(code **)(local_1c0 + -0x6d78))(unaff_s2,local_1b4,unaff_s6);
    local_1b4 = local_1b4 + (int)local_1b0;
    (**(code **)(local_1c0 + -0x7380))(unaff_s2);
    (**(code **)(local_1c0 + -0x733c))(unaff_s3,unaff_s8,(int)local_1b4 - (int)unaff_s8);
    (**(code **)(local_1c0 + -0x7338))(unaff_s3,local_1b4,&local_1ac);
    (**(code **)(local_1c0 + -0x7334))(unaff_s3);
    iVar15 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
    pcVar22 = *(code **)(local_1c0 + -0x7f58);
    local_1b0 = local_1b4 + (local_1ac - iVar15);
    *(char *)(iVar15 + 0x11) = (char)(local_1b0 + -0x12);
    *(char *)(iVar15 + 0x10) = (char)((uint)(local_1b0 + -0x12) >> 8);
    *(uchar **)(param_1 + 0x44) = local_1b0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0x21f1;
    local_1b4 = (uchar *)(iVar15 + 0x12);
    (*pcVar22)(unaff_s5);
    local_1c4 = *(int *)(param_1 + 0x44) + -0xc;
    local_1c8 = (undefined *)0x0;
    dtls1_set_message_header(param_1,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 4),4,local_1c4);
    dtls1_buffer_message(param_1,0);
  }
  puVar4 = (undefined1 *)dtls1_do_write(param_1,0x16);
LAB_0049d334:
  if (local_2c == *(SSL **)puStack_1fc) {
    return puVar4;
  }
  pcStack_1dc = dtls1_accept;
  ssl = local_2c;
  (**(code **)(local_1c0 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iStack_204 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_200 = param_1;
  puStack_1f8 = unaff_s2;
  puStack_1f4 = unaff_s3;
  iStack_1f0 = unaff_s4;
  puStack_1ec = unaff_s5;
  ppuStack_1e8 = unaff_s6;
  puStack_1e4 = unaff_s7;
  puStack_1e0 = unaff_s8;
  uStack_208 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&uStack_208,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar5 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  p_Var19 = ssl->info_callback;
  *puVar5 = 0;
  if (p_Var19 == (_func_3152 *)0x0) {
    p_Var19 = *(_func_3152 **)(ssl->psk_server_callback + 0x9c);
  }
  uVar20 = ssl->d1->mtu;
  ssl->in_handshake = ssl->in_handshake + 1;
  uVar6 = SSL_state(ssl);
  if (((uVar6 & 0x3000) == 0) || (uVar6 = SSL_state(ssl), (uVar6 & 0x4000) != 0)) {
    SSL_clear(ssl);
  }
  pcVar7 = ssl->cert;
  ssl->d1->mtu = uVar20;
  if (pcVar7 == (cert_st *)0x0) {
    uVar17 = 0xb3;
    uVar12 = 0xb9;
LAB_0049e6a0:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf6,uVar17,"d1_srvr.c",uVar12);
    puVar4 = (undefined1 *)0xffffffff;
  }
  else {
    if (ssl->tlsext_heartbeat != 0) {
      dtls1_stop_timer(ssl);
      ssl->tlsext_heartbeat = 0;
      ssl->tlsext_hb_pending = ssl->tlsext_hb_pending + 1;
    }
    iVar15 = ssl->state;
LAB_0049d87c:
    iVar23 = iVar15;
    if (0x2171 < iVar15) goto LAB_0049d940;
LAB_0049d88c:
    puVar2 = PTR_BIO_ctrl_006a7f18;
    if (iVar23 < 0x2170) {
      if (iVar23 < 0x2122) {
        if (iVar23 < 0x2120) {
          if (iVar23 == 0x2100) {
            ssl->rwstate = 2;
            iVar15 = (*(code *)puVar2)(ssl->wbio,0xb,0,0);
            if (0 < iVar15) {
              psVar8 = ssl->s3;
              ssl->rwstate = 1;
              ssl->state = (psVar8->tmp).next_state;
              goto LAB_0049dbc4;
            }
            iVar15 = (*(code *)PTR_BIO_test_flags_006a8954)(ssl->wbio,8);
            if (iVar15 == 0) {
              puVar4 = (undefined1 *)0xffffffff;
              ssl->rwstate = 1;
              ssl->state = (ssl->s3->tmp).next_state;
            }
            else {
LAB_0049e628:
              puVar4 = (undefined1 *)0xffffffff;
            }
          }
          else if (iVar23 < 0x2101) {
            if (iVar23 == 0x2000) goto LAB_0049dd8c;
            if (iVar23 == 0x2003) goto LAB_0049dd8c;
            if (iVar23 != 3) goto LAB_0049e02c;
            ssl3_cleanup_key_block(ssl);
            ssl_free_wbio_buffer(ssl);
            ssl->init_num = 0;
            if (ssl->tlsext_hb_seq == 2) {
              ssl->tlsext_hb_seq = 0;
              ssl->new_session = 0;
              ssl_update_cache(ssl,2);
              *(int *)(ssl->psk_server_callback + 0x48) =
                   *(int *)(ssl->psk_server_callback + 0x48) + 1;
              ssl->handshake_func = dtls1_accept;
              if (p_Var19 != (_func_3152 *)0x0) {
                (*p_Var19)(ssl,0x20,1);
              }
            }
            pdVar13 = ssl->d1;
            puVar4 = (undefined1 *)0x1;
            pdVar13->handshake_read_seq = 0;
            pdVar13->handshake_write_seq = 0;
            pdVar13->next_handshake_write_seq = 0;
          }
          else if (iVar23 < 0x2110) {
LAB_0049e02c:
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf6,0xff,"d1_srvr.c",0x333);
            puVar4 = (undefined1 *)0xffffffff;
          }
          else if (iVar23 < 0x2113) {
            ssl->shutdown = 0;
            puVar4 = (undefined1 *)ssl3_get_client_hello(ssl);
            if (0 < (int)puVar4) {
              dtls1_stop_timer(ssl);
              if ((puVar4 == (undefined1 *)0x1) &&
                 (uVar6 = SSL_ctrl(ssl,0x20,0,(void *)0x0), (uVar6 & 0x2000) != 0)) {
                iVar15 = 0x2113;
              }
              else {
                iVar15 = 0x2130;
              }
              ssl->state = iVar15;
              ssl->init_num = 0;
              if (uVar20 == 0) {
                if ((ssl->s3->tmp).reuse_message == 0) goto LAB_0049d9b4;
                goto LAB_0049d87c;
              }
              psVar8 = ssl->s3;
              uVar16 = *(uint *)psVar8->read_sequence;
              uVar12 = *(undefined4 *)(psVar8->read_sequence + 4);
              uVar6 = (uint)psVar8->write_sequence & 3;
              puVar21 = psVar8->write_sequence + -uVar6;
              *(uint *)puVar21 = *(uint *)puVar21 & -1 << (4 - uVar6) * 8 | uVar16 >> uVar6 * 8;
              puVar21 = psVar8->write_sequence + 3;
              uVar6 = (uint)puVar21 & 3;
              *(uint *)(puVar21 + -uVar6) =
                   *(uint *)(puVar21 + -uVar6) & 0xffffffffU >> (uVar6 + 1) * 8 |
                   uVar16 << (3 - uVar6) * 8;
              *(undefined4 *)(psVar8->write_sequence + 4) = uVar12;
              if (ssl->state != 0x2130) {
                psVar8 = ssl->s3;
                goto LAB_0049dbc4;
              }
              pdVar13 = ssl->d1;
              puVar4 = (undefined1 *)0x2;
              pdVar13->mtu = 0;
              pdVar13->handshake_read_seq = 2;
              pdVar13->handshake_write_seq = 1;
              pdVar13->next_handshake_write_seq = 1;
            }
          }
          else {
            if (0x2114 < iVar23) goto LAB_0049e02c;
            if (iVar23 == 0x2113) {
              pcVar18 = ssl->init_buf->data;
              pcVar18[0xc] = (char)((uint)ssl->version >> 8);
              pcVar18[0xd] = (char)ssl->version;
              if ((*(code **)(ssl->psk_server_callback + 0x78) == (code *)0x0) ||
                 (iVar15 = (**(code **)(ssl->psk_server_callback + 0x78))
                                     (ssl,ssl->d1->cookie,&ssl->d1->cookie_len),
                 puVar2 = PTR_memcpy_006aabf4, iVar15 == 0)) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x108,0x44,"d1_srvr.c",900);
                puVar4 = (undefined1 *)0x0;
                goto LAB_0049da8c;
              }
              pcVar18[0xe] = (char)ssl->d1->cookie_len;
              iVar15 = (*(code *)puVar2)(pcVar18 + 0xf,ssl->d1->cookie,ssl->d1->cookie_len);
              iVar15 = iVar15 + ssl->d1->cookie_len;
              iVar9 = iVar15 - (int)(pcVar18 + 0xc);
              dtls1_set_message_header(ssl,pcVar18,3,iVar9,0,iVar9);
              ssl->init_off = 0;
              ssl->state = 0x2114;
              ssl->init_num = iVar15 - (int)pcVar18;
            }
            puVar4 = (undefined1 *)dtls1_do_write(ssl,0x16);
            if (0 < (int)puVar4) {
              psVar8 = ssl->s3;
              iVar15 = ssl->version;
              ssl->state = 0x2100;
              (psVar8->tmp).next_state = 0x2110;
              if (iVar15 != 0x100) {
                ssl3_init_finished_mac(ssl);
                iVar15 = (ssl->s3->tmp).reuse_message;
                goto joined_r0x0049d924;
              }
LAB_0049dbc4:
              do {
                if ((psVar8->tmp).reuse_message == 0) goto LAB_0049d9b4;
                iVar23 = ssl->state;
LAB_0049d930:
                while( true ) {
                  if (iVar23 < 0x2172) goto LAB_0049d88c;
LAB_0049d940:
                  if (0x21d1 < iVar23) {
                    if (0x2201 < iVar23) {
                      if ((iVar23 == 0x4000) || (iVar23 == 0x6000)) goto LAB_0049dd8c;
                      if (iVar23 == 0x3004) goto code_r0x0049dd84;
                      goto LAB_0049e02c;
                    }
                    if (0x21ff < iVar23) {
                      puVar4 = (undefined1 *)ssl3_send_cert_status(ssl);
                      if ((int)puVar4 < 1) goto LAB_0049da8c;
                      psVar8 = ssl->s3;
                      ssl->init_num = 0;
                      ssl->state = 0x2150;
                      goto LAB_0049dbc4;
                    }
                    if (iVar23 < 0x21e0) goto LAB_0049e02c;
                    if (iVar23 < 0x21e2) {
                      psVar10 = ssl->method->ssl3_enc;
                      puVar4 = (undefined1 *)
                               dtls1_send_finished(ssl,0x21e0,0x21e1,*(undefined4 *)(psVar10 + 0x28)
                                                   ,*(undefined4 *)(psVar10 + 0x2c));
                      if ((int)puVar4 < 1) goto LAB_0049da8c;
                      ssl->state = 0x2100;
                      if (ssl->hit == 0) {
                        psVar8 = ssl->s3;
                        (psVar8->tmp).next_state = 3;
                        ssl->init_num = 0;
                      }
                      else {
                        psVar8 = ssl->s3;
                        (psVar8->tmp).next_state = 0x21c0;
                        ssl->init_num = 0;
                      }
                    }
                    else {
                      if (1 < iVar23 - 0x21f0U) goto LAB_0049e02c;
                      puVar4 = (undefined1 *)dtls1_send_newsession_ticket(ssl);
                      if ((int)puVar4 < 1) goto LAB_0049da8c;
                      psVar8 = ssl->s3;
                      ssl->init_num = 0;
                      ssl->state = 0x21d0;
                    }
                    goto LAB_0049dbc4;
                  }
                  if (0x21cf < iVar23) {
                    pcVar22 = *(code **)(ssl->method->ssl3_enc + 8);
                    *(SSL_CIPHER **)(ssl->session->krb5_client_princ + 0x24) =
                         (ssl->s3->tmp).new_cipher;
                    iVar15 = (*pcVar22)(ssl);
                    if (iVar15 == 0) goto LAB_0049e628;
                    puVar4 = (undefined1 *)dtls1_send_change_cipher_spec(ssl,0x21d0,0x21d1);
                    if ((int)puVar4 < 1) goto LAB_0049da8c;
                    ssl->init_num = 0;
                    ssl->state = 0x21e0;
                    iVar15 = (**(code **)(ssl->method->ssl3_enc + 0x10))(ssl,0x22);
                    if (iVar15 == 0) goto LAB_0049e628;
                    dtls1_reset_seq_numbers(ssl,2);
                    psVar8 = ssl->s3;
                    goto LAB_0049dbc4;
                  }
                  if (0x2191 < iVar23) {
                    if (iVar23 < 0x21a0) goto LAB_0049e02c;
                    if (iVar23 < 0x21a2) {
                      ssl->d1->listen = 1;
                      puVar4 = (undefined1 *)ssl3_get_cert_verify(ssl);
                      if ((int)puVar4 < 1) goto LAB_0049da8c;
                      psVar8 = ssl->s3;
                      ssl->init_num = 0;
                      ssl->state = 0x21c0;
                    }
                    else {
                      if (1 < iVar23 - 0x21c0U) goto LAB_0049e02c;
                      ssl->d1->listen = 1;
                      puVar4 = (undefined1 *)ssl3_get_finished(ssl,0x21c0,0x21c1);
                      if ((int)puVar4 < 1) goto LAB_0049da8c;
                      dtls1_stop_timer(ssl);
                      if (ssl->hit == 0) {
LAB_0049db50:
                        if (ssl->tlsext_ocsp_resplen == 0) {
                          ssl->init_num = 0;
                          ssl->state = 0x21d0;
                          psVar8 = ssl->s3;
                        }
                        else {
                          ssl->init_num = 0;
                          ssl->state = 0x21f0;
                          psVar8 = ssl->s3;
                        }
                      }
                      else {
                        ssl->init_num = 0;
                        ssl->state = 3;
                        psVar8 = ssl->s3;
                      }
                    }
                    goto LAB_0049dbc4;
                  }
                  if (0x218f < iVar23) {
                    puVar4 = (undefined1 *)ssl3_get_client_key_exchange(ssl);
                    if ((int)puVar4 < 1) goto LAB_0049da8c;
                    ssl->init_num = 0;
                    ssl->state = 0x21a0;
                    if (puVar4 == (undefined1 *)0x2) {
                      psVar8 = ssl->s3;
                      ssl->state = 0x21c0;
                    }
                    else {
                      (**(code **)(ssl->method->ssl3_enc + 0x1c))(ssl,4,&ssl->s3->tmp);
                      (**(code **)(ssl->method->ssl3_enc + 0x1c))
                                (ssl,0x40,(ssl->s3->tmp).cert_verify_md + 0x10);
                      psVar8 = ssl->s3;
                    }
                    goto LAB_0049dbc4;
                  }
                  if (1 < iVar23 - 0x2180U) goto LAB_0049e02c;
                  puVar4 = (undefined1 *)ssl3_check_client_hello(ssl);
                  if ((int)puVar4 < 1) goto LAB_0049da8c;
                  if (puVar4 == (undefined1 *)0x2) break;
                  puVar4 = (undefined1 *)ssl3_get_client_certificate(ssl);
                  if ((int)puVar4 < 1) goto LAB_0049da8c;
                  ssl->init_num = 0;
                  ssl->state = 0x2190;
                  iVar15 = (ssl->s3->tmp).reuse_message;
joined_r0x0049d924:
                  if (iVar15 == 0) {
LAB_0049d9b4:
                    if ((ssl->ctx != (SSL_CTX *)0x0) &&
                       (puVar4 = (undefined1 *)(*(code *)PTR_BIO_ctrl_006a7f18)(ssl->wbio,0xb,0,0),
                       (int)puVar4 < 1)) {
                      iVar15 = ssl->in_handshake;
                      goto LAB_0049da90;
                    }
                    if (p_Var19 != (_func_3152 *)0x0) {
                      iVar9 = ssl->state;
                      iVar15 = iVar23;
                      if (iVar9 != iVar23) {
                        ssl->state = iVar23;
                        (*p_Var19)(ssl,0x2001,1);
                        ssl->state = iVar9;
                        iVar15 = iVar9;
                      }
                      goto LAB_0049d87c;
                    }
                  }
LAB_0049d92c:
                  iVar23 = ssl->state;
                }
                dtls1_stop_timer(ssl);
                psVar8 = ssl->s3;
                ssl->state = 0x2112;
              } while( true );
            }
          }
        }
        else {
          ssl->shutdown = 0;
          dtls1_clear_record_buffer(ssl);
          dtls1_start_timer(ssl);
          if (ssl->state == 0x2120) {
            dtls1_set_message_header(ssl,ssl->init_buf->data,0,0,0,0);
            ssl->init_off = 0;
            ssl->state = 0x2121;
            ssl->init_num = 0xc;
          }
          puVar4 = (undefined1 *)dtls1_do_write(ssl,0x16);
          if (0 < (int)puVar4) {
            (ssl->s3->tmp).next_state = 0x2110;
            ssl->init_num = 0;
            ssl->state = 0x2100;
            ssl3_init_finished_mac(ssl);
            psVar8 = ssl->s3;
            goto LAB_0049dbc4;
          }
        }
      }
      else {
        if (0x2141 < iVar23) {
          if (0x214f < iVar23) {
            if (iVar23 < 0x2152) {
              psVar8 = ssl->s3;
              pSVar14 = (psVar8->tmp).new_cipher;
              uVar6 = ssl->references & 0x200000;
              uVar16 = pSVar14->algorithm_mkey;
              (psVar8->tmp).use_rsa_tmp = (uint)(uVar6 != 0);
              if ((uVar6 == 0) &&
                 ((((uVar16 & 0x100) == 0 || (*(int *)(ssl->psk_server_callback + 0x14c) == 0)) &&
                  ((uVar16 & 0x8e) == 0)))) {
                bVar1 = true;
                if ((uVar16 & 1) != 0) {
                  if (*(int *)(ssl->cert + 0x34) == 0) goto LAB_0049dfd8;
                  bVar1 = true;
                  if ((pSVar14->algo_strength & 2) != 0) {
                    iVar15 = (*(code *)PTR_EVP_PKEY_size_006a85f4)();
                    psVar8 = ssl->s3;
                    iVar9 = 0x200;
                    if ((((psVar8->tmp).new_cipher)->algo_strength & 8) == 0) {
                      iVar9 = 0x400;
                    }
                    if (iVar9 < iVar15 << 3) goto LAB_0049dfd8;
                    bVar1 = true;
                  }
                }
              }
              else {
LAB_0049dfd8:
                dtls1_start_timer(ssl);
                puVar4 = (undefined1 *)dtls1_send_server_key_exchange(ssl);
                if ((int)puVar4 < 1) goto LAB_0049da8c;
                psVar8 = ssl->s3;
                bVar1 = false;
              }
              ssl->init_num = 0;
              ssl->state = 0x2160;
              goto LAB_0049e0b8;
            }
            if (iVar23 - 0x2160U < 2) {
              uVar6 = ssl->verify_mode;
              if (((uVar6 & 1) == 0) ||
                 ((*(int *)(ssl->session->krb5_client_princ + 0xc) != 0 && ((uVar6 & 4) != 0)))) {
                psVar8 = ssl->s3;
              }
              else {
                psVar8 = ssl->s3;
                pSVar14 = (psVar8->tmp).new_cipher;
                uVar16 = pSVar14->algorithm_auth;
                if ((((uVar16 & 4) == 0) || ((uVar6 & 2) != 0)) &&
                   (((uVar16 & 0x20) == 0 && ((pSVar14->algorithm_mkey & 0x100) == 0)))) {
                  (psVar8->tmp).cert_request = 1;
                  dtls1_start_timer(ssl);
                  puVar4 = (undefined1 *)dtls1_send_certificate_request(ssl);
                  if (0 < (int)puVar4) {
                    psVar8 = ssl->s3;
                    ssl->init_num = 0;
                    ssl->state = 0x2170;
                    goto LAB_0049dbc4;
                  }
                  goto LAB_0049da8c;
                }
              }
              (psVar8->tmp).cert_request = 0;
              iVar23 = 0x2170;
              ssl->state = 0x2170;
              goto LAB_0049e210;
            }
          }
          goto LAB_0049e02c;
        }
        if (0x213f < iVar23) {
          psVar8 = ssl->s3;
          pSVar14 = (psVar8->tmp).new_cipher;
          if (((pSVar14->algorithm_auth & 4) == 0) && ((pSVar14->algorithm_mkey & 0x100) == 0)) {
            dtls1_start_timer(ssl);
            if (ssl->state == 0x2140) {
              iVar15 = ssl_get_server_send_cert(ssl);
              if ((iVar15 == 0) &&
                 ((pSVar14 = (ssl->s3->tmp).new_cipher, pSVar14->algorithm_mkey != 0x10 ||
                  (pSVar14->algorithm_auth != 0x20)))) {
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x109,0x44,"d1_srvr.c",0x63a);
                puVar4 = (undefined1 *)0x0;
                goto LAB_0049da8c;
              }
              iVar15 = dtls1_output_cert_chain(ssl,iVar15);
              ssl->init_num = iVar15;
              ssl->init_off = 0;
              ssl->state = 0x2141;
              dtls1_buffer_message(ssl,0);
            }
            puVar4 = (undefined1 *)dtls1_do_write(ssl,0x16);
            if ((int)puVar4 < 1) goto LAB_0049da8c;
            psVar8 = ssl->s3;
            if (ssl->tlsext_status_type == 0) {
              bVar1 = false;
              ssl->state = 0x2150;
            }
            else {
              bVar1 = false;
              ssl->state = 0x2200;
            }
          }
          else {
            bVar1 = true;
            ssl->state = 0x2150;
          }
          ssl->init_num = 0;
LAB_0049e0b8:
          if ((psVar8->tmp).reuse_message != 0) goto LAB_0049d92c;
          if (!bVar1) goto LAB_0049d9b4;
          iVar23 = ssl->state;
          goto LAB_0049d930;
        }
        if (iVar23 == 0x2122) {
          psVar8 = ssl->s3;
          ssl->state = 3;
          goto LAB_0049dbc4;
        }
        if (1 < iVar23 - 0x2130U) goto LAB_0049e02c;
        ssl->tlsext_hb_seq = 2;
        dtls1_start_timer(ssl);
        puVar4 = (undefined1 *)dtls1_send_server_hello(ssl);
        if (0 < (int)puVar4) {
          if (ssl->hit != 0) goto LAB_0049db50;
          ssl->init_num = 0;
          ssl->state = 0x2140;
          psVar8 = ssl->s3;
          goto LAB_0049dbc4;
        }
      }
    }
    else {
LAB_0049e210:
      dtls1_start_timer(ssl);
      if (ssl->state == 0x2170) {
        dtls1_set_message_header(ssl,ssl->init_buf->data,0xe,0,0,0);
        ssl->init_off = 0;
        ssl->state = 0x2171;
        ssl->init_num = 0xc;
        dtls1_buffer_message(ssl,0);
      }
      puVar4 = (undefined1 *)dtls1_do_write(ssl,0x16);
      if (0 < (int)puVar4) {
        psVar8 = ssl->s3;
        (psVar8->tmp).next_state = 0x2180;
        ssl->init_num = 0;
        ssl->state = 0x2100;
        goto LAB_0049dbc4;
      }
    }
LAB_0049da8c:
    iVar15 = ssl->in_handshake;
LAB_0049da90:
    ssl->in_handshake = iVar15 + -1;
    if (p_Var19 != (_func_3152 *)0x0) {
      (*p_Var19)(ssl,0x2002,(int)puVar4);
    }
  }
  if (iStack_204 == *(int *)puVar3) {
    return puVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((iStack_204 != 0xfeff) && (iStack_204 != 0x100)) {
    return (undefined1 *)0x0;
  }
  return DTLSv1_client_method_data_15845;
code_r0x0049dd84:
  ssl->tlsext_hb_seq = 1;
LAB_0049dd8c:
  ssl->server = 1;
  if (p_Var19 != (_func_3152 *)0x0) {
    (*p_Var19)(ssl,0x10,1);
  }
  if ((ssl->version & 0xff00U) != 0xfe00) {
    uVar17 = 0x44;
    uVar12 = 0xde;
    goto LAB_0049e6a0;
  }
  ssl->type = 0x2000;
  if (ssl->init_buf == (BUF_MEM *)0x0) {
    pBVar11 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a859c)();
    if ((pBVar11 == (BUF_MEM *)0x0) ||
       (iVar15 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(pBVar11,0x4000), iVar15 == 0))
    goto LAB_0049e628;
    ssl->init_buf = pBVar11;
  }
  iVar15 = ssl3_setup_buffers(ssl);
  if (iVar15 == 0) goto LAB_0049e628;
  ssl->init_num = 0;
  if (ssl->state == 0x3004) {
    psVar8 = ssl->s3;
    *(int *)(ssl->psk_server_callback + 0x44) = *(int *)(ssl->psk_server_callback + 0x44) + 1;
    ssl->state = 0x2120;
  }
  else {
    iVar15 = ssl_init_wbio_buffer(ssl,1);
    if (iVar15 == 0) goto LAB_0049e628;
    ssl3_init_finished_mac(ssl);
    psVar8 = ssl->s3;
    ssl->state = 0x2110;
    *(int *)(ssl->psk_server_callback + 0x40) = *(int *)(ssl->psk_server_callback + 0x40) + 1;
  }
  goto LAB_0049dbc4;
}

