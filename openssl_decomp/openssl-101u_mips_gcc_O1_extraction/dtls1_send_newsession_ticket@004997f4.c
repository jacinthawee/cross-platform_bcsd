
undefined1 * dtls1_send_newsession_ticket(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  cert_st *pcVar8;
  ssl3_state_st *psVar9;
  int iVar10;
  ssl3_enc_method *psVar11;
  BUF_MEM *pBVar12;
  undefined4 uVar13;
  dtls1_state_st *pdVar14;
  SSL *ssl;
  SSL_CIPHER *pSVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  char *pcVar19;
  _func_3152 *p_Var20;
  undefined *unaff_s2;
  undefined *unaff_s3;
  int unaff_s4;
  uint uVar21;
  uchar *unaff_s5;
  uchar **unaff_s6;
  uchar *puVar22;
  undefined *unaff_s7;
  code *pcVar23;
  uchar *unaff_s8;
  int iVar24;
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
  
  puStack_1fc = PTR___stack_chk_guard_006a9ae8;
  local_1c0 = &_gp;
  local_2c = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  if (*(int *)(param_1 + 0x34) == 0x21f0) {
    unaff_s6 = *(uchar ***)(param_1 + 0x170);
    unaff_s4 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),(uchar **)0x0);
    if (((0xff00 < unaff_s4) ||
        (iVar16 = (**(code **)(local_1c0 + -0x7940))
                            (*(undefined4 *)(param_1 + 0x3c),unaff_s4 + 0x92), iVar16 == 0)) ||
       (unaff_s5 = (uchar *)(**(code **)(local_1c0 + -0x7dd8))(unaff_s4,"d1_srvr.c",0x695),
       unaff_s5 == (uchar *)0x0)) {
LAB_00499bcc:
      puVar5 = (undefined1 *)0xffffffff;
      goto LAB_00499860;
    }
    unaff_s2 = auStack_1a8;
    unaff_s3 = auStack_11c;
    local_1b4 = unaff_s5;
    i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),&local_1b4);
    local_1b4 = (uchar *)(*(int *)(*(int *)(param_1 + 0x3c) + 4) + 0xc);
    (**(code **)(local_1c0 + -0x737c))(unaff_s2);
    (**(code **)(local_1c0 + -0x73c4))(unaff_s3);
    if ((code *)unaff_s6[0x4e] == (code *)0x0) {
      iVar16 = (**(code **)(local_1c0 + -0x786c))(auStack_4c,0x10);
      if (iVar16 < 1) goto LAB_00499bbc;
      uVar13 = (**(code **)(local_1c0 + -0x7b38))();
      local_1c8 = auStack_4c;
      (**(code **)(local_1c0 + -0x7348))(unaff_s2,uVar13,0,unaff_s6 + 0x4a);
      uVar13 = (**(code **)(local_1c0 + -0x6de0))();
      local_1c8 = (undefined *)0x0;
      (**(code **)(local_1c0 + -0x7314))(unaff_s3,unaff_s6 + 0x46,0x10,uVar13);
      local_3c = unaff_s6[0x42];
      local_38 = unaff_s6[0x43];
      local_34 = unaff_s6[0x44];
      local_30 = unaff_s6[0x45];
    }
    else {
      local_1c4 = 1;
      local_1c8 = unaff_s3;
      iVar16 = (*(code *)unaff_s6[0x4e])(param_1,&local_3c,auStack_4c,unaff_s2);
      if (iVar16 < 0) {
LAB_00499bbc:
        unaff_s7 = auStack_4c;
        (**(code **)(local_1c0 + -0x7f58))(unaff_s5);
        goto LAB_00499bcc;
      }
    }
    unaff_s7 = auStack_4c;
    pcVar23 = *(code **)(local_1c0 + -0x6de8);
    *local_1b4 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xec);
    local_1b4[1] = (uchar)*(undefined2 *)(*(int *)(param_1 + 0xc0) + 0xec);
    local_1b4[2] = (uchar)((uint)*(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xec) >> 8);
    local_1b4[3] = (uchar)*(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xec);
    unaff_s8 = local_1b4 + 6;
    *(uchar **)(local_1b4 + 6) = local_3c;
    *(uchar **)(local_1b4 + 10) = local_38;
    *(uchar **)(local_1b4 + 0xe) = local_34;
    *(uchar **)(local_1b4 + 0x12) = local_30;
    puVar22 = local_1b4 + 0x16;
    local_1b4 = puVar22;
    uVar13 = (*pcVar23)(unaff_s2);
    unaff_s6 = &local_1b0;
    (**(code **)(local_1c0 + -0x52f4))(puVar22,unaff_s7,uVar13);
    iVar16 = (**(code **)(local_1c0 + -0x6de8))(unaff_s2);
    local_1b4 = local_1b4 + iVar16;
    local_1c8 = (undefined *)unaff_s4;
    (**(code **)(local_1c0 + -0x7340))(unaff_s2,local_1b4,unaff_s6,unaff_s5);
    local_1b4 = local_1b4 + (int)local_1b0;
    (**(code **)(local_1c0 + -0x6de4))(unaff_s2,local_1b4,unaff_s6);
    local_1b4 = local_1b4 + (int)local_1b0;
    (**(code **)(local_1c0 + -0x736c))(unaff_s2);
    (**(code **)(local_1c0 + -0x7310))(unaff_s3,unaff_s8,(int)local_1b4 - (int)unaff_s8);
    (**(code **)(local_1c0 + -0x730c))(unaff_s3,local_1b4,&local_1ac);
    (**(code **)(local_1c0 + -0x7304))(unaff_s3);
    iVar16 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
    pcVar23 = *(code **)(local_1c0 + -0x7f58);
    local_1b0 = local_1b4 + (local_1ac - iVar16);
    *(char *)(iVar16 + 0x11) = (char)(local_1b0 + -0x12);
    *(char *)(iVar16 + 0x10) = (char)((uint)(local_1b0 + -0x12) >> 8);
    *(uchar **)(param_1 + 0x44) = local_1b0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0x21f1;
    local_1b4 = (uchar *)(iVar16 + 0x12);
    (*pcVar23)(unaff_s5);
    local_1c4 = *(int *)(param_1 + 0x44) + -0xc;
    local_1c8 = (undefined *)0x0;
    dtls1_set_message_header(param_1,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 4),4,local_1c4);
    dtls1_buffer_message(param_1,0);
  }
  puVar5 = (undefined1 *)dtls1_do_write(param_1,0x16);
LAB_00499860:
  if (local_2c == *(SSL **)puStack_1fc) {
    return puVar5;
  }
  pcStack_1dc = dtls1_accept;
  ssl = local_2c;
  (**(code **)(local_1c0 + -0x5330))();
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  iStack_204 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_200 = param_1;
  puStack_1f8 = unaff_s2;
  puStack_1f4 = unaff_s3;
  iStack_1f0 = unaff_s4;
  puStack_1ec = unaff_s5;
  ppuStack_1e8 = unaff_s6;
  puStack_1e4 = unaff_s7;
  puStack_1e0 = unaff_s8;
  uStack_208 = (*(code *)PTR_time_006a9adc)(0);
  (*(code *)PTR_RAND_add_006a8004)(&uStack_208,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  puVar6 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  p_Var20 = ssl->info_callback;
  *puVar6 = 0;
  if (p_Var20 == (_func_3152 *)0x0) {
    p_Var20 = *(_func_3152 **)(ssl->psk_server_callback + 0x9c);
  }
  uVar21 = ssl->d1->mtu;
  ssl->in_handshake = ssl->in_handshake + 1;
  uVar7 = SSL_state(ssl);
  if (((uVar7 & 0x3000) == 0) || (uVar7 = SSL_state(ssl), (uVar7 & 0x4000) != 0)) {
    SSL_clear(ssl);
  }
  pcVar8 = ssl->cert;
  ssl->d1->mtu = uVar21;
  if (pcVar8 == (cert_st *)0x0) {
    uVar18 = 0xb3;
    uVar13 = 0xb9;
LAB_0049ac80:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf6,uVar18,"d1_srvr.c",uVar13);
    puVar5 = (undefined1 *)0xffffffff;
  }
  else {
    if (ssl->tlsext_heartbeat != 0) {
      dtls1_stop_timer(ssl);
      ssl->tlsext_heartbeat = 0;
      ssl->tlsext_hb_pending = ssl->tlsext_hb_pending + 1;
    }
    iVar16 = ssl->state;
LAB_00499dac:
    iVar24 = iVar16;
    if (0x2171 < iVar16) goto LAB_00499e74;
LAB_00499dbc:
    puVar3 = PTR_ssl3_get_client_hello_006a8238;
    puVar2 = PTR_BIO_ctrl_006a6e18;
    if (iVar24 < 0x2170) {
      if (0x2121 < iVar24) {
        if (iVar24 < 0x2142) {
          if (0x213f < iVar24) {
            psVar9 = ssl->s3;
            pSVar15 = (psVar9->tmp).new_cipher;
            if (((pSVar15->algorithm_auth & 4) != 0) || ((pSVar15->algorithm_mkey & 0x100) != 0)) {
              ssl->init_num = 0;
              bVar1 = true;
              ssl->state = 0x2150;
LAB_0049a4ec:
              if ((psVar9->tmp).reuse_message != 0) goto LAB_00499e60;
              if (bVar1) {
                iVar24 = ssl->state;
                goto LAB_00499e64;
              }
LAB_00499ee0:
              if ((ssl->ctx == (SSL_CTX *)0x0) ||
                 (puVar5 = (undefined1 *)(*(code *)PTR_BIO_ctrl_006a6e18)(ssl->wbio,0xb,0,0),
                 0 < (int)puVar5)) {
                if (p_Var20 == (_func_3152 *)0x0) {
LAB_00499e60:
                  iVar24 = ssl->state;
LAB_00499e64:
                  if (iVar24 < 0x2172) goto LAB_00499dbc;
LAB_00499e74:
                  if (iVar24 < 0x21d2) {
                    if (0x21cf < iVar24) {
                      pcVar23 = *(code **)(ssl->method->ssl3_enc + 8);
                      *(SSL_CIPHER **)(ssl->session->krb5_client_princ + 0x24) =
                           (ssl->s3->tmp).new_cipher;
                      iVar16 = (*pcVar23)(ssl);
                      if (iVar16 != 0) {
                        puVar5 = (undefined1 *)dtls1_send_change_cipher_spec(ssl,0x21d0,0x21d1);
                        if ((int)puVar5 < 1) goto LAB_00499fc0;
                        ssl->init_num = 0;
                        ssl->state = 0x21e0;
                        iVar16 = (**(code **)(ssl->method->ssl3_enc + 0x10))(ssl,0x22);
                        if (iVar16 != 0) {
                          dtls1_reset_seq_numbers(ssl,2);
                          psVar9 = ssl->s3;
                          goto LAB_0049a0f8;
                        }
                      }
LAB_0049ac60:
                      puVar5 = (undefined1 *)0xffffffff;
                      ssl->state = 5;
                      goto LAB_00499fc0;
                    }
                    if (iVar24 < 0x2192) {
                      if (iVar24 < 0x2190) {
                        if (1 < iVar24 - 0x2180U) goto LAB_0049a540;
                        puVar5 = (undefined1 *)(*(code *)PTR_ssl3_check_client_hello_006a8224)(ssl);
                        if ((int)puVar5 < 1) goto LAB_00499fc0;
                        if (puVar5 != (undefined1 *)0x2) goto code_r0x00499ebc;
                        dtls1_stop_timer(ssl);
                        psVar9 = ssl->s3;
                        ssl->state = 0x2112;
                      }
                      else {
                        puVar5 = (undefined1 *)ssl3_get_client_key_exchange(ssl);
                        if ((int)puVar5 < 1) goto LAB_00499fc0;
                        ssl->init_num = 0;
                        ssl->state = 0x21a0;
                        if (puVar5 == (undefined1 *)0x2) {
                          psVar9 = ssl->s3;
                          ssl->state = 0x21c0;
                        }
                        else {
                          (**(code **)(ssl->method->ssl3_enc + 0x1c))(ssl,4,&ssl->s3->tmp);
                          (**(code **)(ssl->method->ssl3_enc + 0x1c))
                                    (ssl,0x40,(ssl->s3->tmp).cert_verify_md + 0x10);
                          psVar9 = ssl->s3;
                        }
                      }
                    }
                    else {
                      if (iVar24 < 0x21a0) goto LAB_0049a540;
                      if (iVar24 < 0x21a2) {
                        puVar5 = (undefined1 *)ssl3_get_cert_verify(ssl);
                        if ((int)puVar5 < 1) goto LAB_00499fc0;
                        psVar9 = ssl->s3;
                        ssl->init_num = 0;
                        ssl->state = 0x21c0;
                      }
                      else {
                        if (1 < iVar24 - 0x21c0U) goto LAB_0049a540;
                        if (ssl->s3->change_cipher_spec == 0) {
                          ssl->d1[1].send_cookie = 1;
                        }
                        puVar5 = (undefined1 *)ssl3_get_finished(ssl,0x21c0,0x21c1);
                        if ((int)puVar5 < 1) goto LAB_00499fc0;
                        dtls1_stop_timer(ssl);
                        if (ssl->hit == 0) {
LAB_0049a084:
                          if (ssl->tlsext_ocsp_resplen == 0) {
                            ssl->init_num = 0;
                            ssl->state = 0x21d0;
                            psVar9 = ssl->s3;
                          }
                          else {
                            ssl->init_num = 0;
                            ssl->state = 0x21f0;
                            psVar9 = ssl->s3;
                          }
                        }
                        else {
                          ssl->init_num = 0;
                          ssl->state = 3;
                          psVar9 = ssl->s3;
                        }
                      }
                    }
                  }
                  else if (iVar24 < 0x2202) {
                    if (iVar24 < 0x2200) {
                      if (iVar24 < 0x21e0) goto LAB_0049a540;
                      if (iVar24 < 0x21e2) {
                        psVar11 = ssl->method->ssl3_enc;
                        puVar5 = (undefined1 *)
                                 dtls1_send_finished(ssl,0x21e0,0x21e1,
                                                     *(undefined4 *)(psVar11 + 0x28),
                                                     *(undefined4 *)(psVar11 + 0x2c));
                        if ((int)puVar5 < 1) goto LAB_00499fc0;
                        ssl->state = 0x2100;
                        if (ssl->hit == 0) {
                          psVar9 = ssl->s3;
                          (psVar9->tmp).next_state = 3;
                          ssl->init_num = 0;
                        }
                        else {
                          psVar9 = ssl->s3;
                          (psVar9->tmp).next_state = 0x21c0;
                          ssl->init_num = 0;
                        }
                      }
                      else {
                        if (1 < iVar24 - 0x21f0U) goto LAB_0049a540;
                        puVar5 = (undefined1 *)dtls1_send_newsession_ticket(ssl);
                        if ((int)puVar5 < 1) goto LAB_00499fc0;
                        psVar9 = ssl->s3;
                        ssl->init_num = 0;
                        ssl->state = 0x21d0;
                      }
                    }
                    else {
                      puVar5 = (undefined1 *)ssl3_send_cert_status(ssl);
                      if ((int)puVar5 < 1) goto LAB_00499fc0;
                      psVar9 = ssl->s3;
                      ssl->init_num = 0;
                      ssl->state = 0x2150;
                    }
                  }
                  else {
                    if ((iVar24 != 0x4000) && (iVar24 != 0x6000)) {
                      if (iVar24 != 0x3004) goto LAB_0049a540;
                      ssl->tlsext_hb_seq = 1;
                    }
LAB_0049a2e0:
                    ssl->server = 1;
                    if (p_Var20 != (_func_3152 *)0x0) {
                      (*p_Var20)(ssl,0x10,1);
                    }
                    if ((ssl->version & 0xff00U) != 0xfe00) {
                      uVar18 = 0x44;
                      uVar13 = 0xdb;
                      goto LAB_0049ac80;
                    }
                    ssl->type = 0x2000;
                    if (ssl->init_buf == (BUF_MEM *)0x0) {
                      pBVar12 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a749c)();
                      if (pBVar12 != (BUF_MEM *)0x0) {
                        iVar16 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(pBVar12,0x4000);
                        if (iVar16 != 0) {
                          ssl->init_buf = pBVar12;
                          goto LAB_0049a31c;
                        }
                        (*(code *)PTR_BUF_MEM_free_006a7494)(pBVar12);
                      }
                      goto LAB_0049ac60;
                    }
LAB_0049a31c:
                    iVar16 = ssl3_setup_buffers(ssl);
                    if (iVar16 == 0) goto LAB_0049ac60;
                    psVar9 = ssl->s3;
                    iVar16 = ssl->state;
                    ssl->init_num = 0;
                    ssl->d1[1].send_cookie = 0;
                    psVar9->change_cipher_spec = 0;
                    if (iVar16 != 0x3004) {
                      iVar16 = ssl_init_wbio_buffer(ssl,1);
                      if (iVar16 == 0) goto LAB_0049ac60;
                      ssl3_init_finished_mac(ssl);
                      ssl->state = 0x2110;
                      psVar9 = ssl->s3;
                      *(int *)(ssl->psk_server_callback + 0x40) =
                           *(int *)(ssl->psk_server_callback + 0x40) + 1;
                      goto LAB_0049a0f8;
                    }
                    if ((psVar9->send_connection_binding == 0) &&
                       ((ssl->references & 0x40000U) == 0)) {
                      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf6,0x152,"d1_srvr.c",0x116);
                      ssl3_send_alert(ssl,2,0x28);
                      puVar5 = (undefined1 *)0xffffffff;
                      ssl->state = 5;
                      goto LAB_00499fc0;
                    }
                    *(int *)(ssl->psk_server_callback + 0x44) =
                         *(int *)(ssl->psk_server_callback + 0x44) + 1;
                    ssl->state = 0x2120;
                  }
LAB_0049a0f8:
                  if ((psVar9->tmp).reuse_message == 0) goto LAB_00499ee0;
                  iVar24 = ssl->state;
                  goto LAB_00499e64;
                }
                iVar10 = ssl->state;
                iVar16 = iVar24;
                if (iVar10 != iVar24) {
                  ssl->state = iVar24;
                  (*p_Var20)(ssl,0x2001,1);
                  ssl->state = iVar10;
                  iVar16 = iVar10;
                }
                goto LAB_00499dac;
              }
              iVar16 = ssl->in_handshake;
              goto LAB_00499fc4;
            }
            dtls1_start_timer(ssl);
            if (ssl->state == 0x2140) {
              iVar16 = ssl_get_server_send_cert(ssl);
              if ((iVar16 == 0) &&
                 ((pSVar15 = (ssl->s3->tmp).new_cipher, pSVar15->algorithm_mkey != 0x10 ||
                  (pSVar15->algorithm_auth != 0x20)))) {
                uVar13 = 0x65f;
              }
              else {
                iVar16 = dtls1_output_cert_chain(ssl,iVar16);
                if (iVar16 != 0) {
                  ssl->init_num = iVar16;
                  ssl->init_off = 0;
                  ssl->state = 0x2141;
                  dtls1_buffer_message(ssl,0);
                  goto LAB_0049a8a8;
                }
                uVar13 = 0x666;
              }
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x109,0x44,"d1_srvr.c",uVar13);
              puVar5 = (undefined1 *)0x0;
            }
            else {
LAB_0049a8a8:
              puVar5 = (undefined1 *)dtls1_do_write(ssl,0x16);
              if (0 < (int)puVar5) {
                psVar9 = ssl->s3;
                if (ssl->tlsext_status_type == 0) {
                  ssl->init_num = 0;
                  bVar1 = false;
                  ssl->state = 0x2150;
                }
                else {
                  ssl->init_num = 0;
                  bVar1 = false;
                  ssl->state = 0x2200;
                }
                goto LAB_0049a4ec;
              }
            }
            goto LAB_00499fc0;
          }
          if (iVar24 == 0x2122) {
            psVar9 = ssl->s3;
            ssl->state = 3;
            goto LAB_0049a0f8;
          }
          if (iVar24 - 0x2130U < 2) {
            ssl->tlsext_hb_seq = 2;
            dtls1_start_timer(ssl);
            puVar5 = (undefined1 *)dtls1_send_server_hello(ssl);
            if (0 < (int)puVar5) {
              if (ssl->hit != 0) goto LAB_0049a084;
              ssl->init_num = 0;
              ssl->state = 0x2140;
              psVar9 = ssl->s3;
              goto LAB_0049a0f8;
            }
            goto LAB_00499fc0;
          }
        }
        else if (0x214f < iVar24) {
          if (iVar24 < 0x2152) {
            psVar9 = ssl->s3;
            pSVar15 = (psVar9->tmp).new_cipher;
            uVar7 = pSVar15->algorithm_mkey;
            (psVar9->tmp).use_rsa_tmp = 0;
            if ((((uVar7 & 0x100) == 0) || (*(int *)(ssl->psk_server_callback + 0x14c) == 0)) &&
               ((uVar7 & 0x88) == 0)) {
              bVar1 = true;
              if ((uVar7 & 1) != 0) {
                if (*(int *)(ssl->cert + 0x34) == 0) goto LAB_0049a4c0;
                bVar1 = true;
                if ((pSVar15->algo_strength & 2) != 0) {
                  iVar16 = (*(code *)PTR_EVP_PKEY_size_006a74f8)();
                  psVar9 = ssl->s3;
                  iVar10 = 0x200;
                  if ((((psVar9->tmp).new_cipher)->algo_strength & 8) == 0) {
                    iVar10 = 0x400;
                  }
                  if (iVar10 < iVar16 << 3) goto LAB_0049a4c0;
                  bVar1 = true;
                }
              }
            }
            else {
LAB_0049a4c0:
              dtls1_start_timer(ssl);
              puVar5 = (undefined1 *)dtls1_send_server_key_exchange(ssl);
              if ((int)puVar5 < 1) goto LAB_00499fc0;
              psVar9 = ssl->s3;
              bVar1 = false;
            }
            ssl->init_num = 0;
            ssl->state = 0x2160;
            goto LAB_0049a4ec;
          }
          if (iVar24 - 0x2160U < 2) {
            uVar7 = ssl->verify_mode;
            if (((uVar7 & 1) == 0) ||
               ((*(int *)(ssl->session->krb5_client_princ + 0xc) != 0 && ((uVar7 & 4) != 0)))) {
              psVar9 = ssl->s3;
            }
            else {
              psVar9 = ssl->s3;
              pSVar15 = (psVar9->tmp).new_cipher;
              uVar17 = pSVar15->algorithm_auth;
              if ((((uVar17 & 4) == 0) || ((uVar7 & 2) != 0)) &&
                 (((uVar17 & 0x20) == 0 && ((pSVar15->algorithm_mkey & 0x100) == 0)))) {
                (psVar9->tmp).cert_request = 1;
                dtls1_start_timer(ssl);
                puVar5 = (undefined1 *)dtls1_send_certificate_request(ssl);
                if (0 < (int)puVar5) {
                  psVar9 = ssl->s3;
                  ssl->init_num = 0;
                  ssl->state = 0x2170;
                  goto LAB_0049a0f8;
                }
                goto LAB_00499fc0;
              }
            }
            (psVar9->tmp).cert_request = 0;
            iVar24 = 0x2170;
            ssl->state = 0x2170;
            goto LAB_0049a7e8;
          }
        }
        goto LAB_0049a540;
      }
      if (iVar24 < 0x2120) {
        if (iVar24 == 0x2100) {
          ssl->rwstate = 2;
          iVar16 = (*(code *)puVar2)(ssl->wbio,0xb,0,0);
          if (0 < iVar16) {
            psVar9 = ssl->s3;
            ssl->rwstate = 1;
            ssl->state = (psVar9->tmp).next_state;
            goto LAB_0049a0f8;
          }
          iVar16 = (*(code *)PTR_BIO_test_flags_006a7868)(ssl->wbio,8);
          if (iVar16 == 0) {
            puVar5 = (undefined1 *)0xffffffff;
            ssl->rwstate = 1;
            ssl->state = (ssl->s3->tmp).next_state;
          }
          else {
            puVar5 = (undefined1 *)0xffffffff;
          }
        }
        else if (iVar24 < 0x2101) {
          if (iVar24 == 0x2000) goto LAB_0049a2e0;
          if (iVar24 == 0x2003) goto LAB_0049a2e0;
          if (iVar24 != 3) goto LAB_0049a540;
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
            if (p_Var20 != (_func_3152 *)0x0) {
              (*p_Var20)(ssl,0x20,1);
            }
          }
          pdVar14 = ssl->d1;
          pdVar14->handshake_read_seq = 0;
          pdVar14->handshake_write_seq = 0;
          pdVar14->next_handshake_write_seq = 0;
          dtls1_clear_received_buffer(ssl);
          puVar5 = (undefined1 *)0x1;
        }
        else if (iVar24 < 0x2110) {
LAB_0049a540:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf6,0xff,"d1_srvr.c",0x36b);
          puVar5 = (undefined1 *)0xffffffff;
        }
        else if (iVar24 < 0x2113) {
          ssl->shutdown = 0;
          puVar5 = (undefined1 *)(*(code *)puVar3)(ssl);
          if (0 < (int)puVar5) {
            dtls1_stop_timer(ssl);
            if ((puVar5 == (undefined1 *)0x1) &&
               (uVar7 = SSL_ctrl(ssl,0x20,0,(void *)0x0), (uVar7 & 0x2000) != 0)) {
              iVar16 = 0x2113;
            }
            else {
              iVar16 = 0x2130;
            }
            ssl->state = iVar16;
            ssl->init_num = 0;
            if (uVar21 == 0) {
              if ((ssl->s3->tmp).reuse_message == 0) goto LAB_00499ee0;
              goto LAB_00499dac;
            }
            psVar9 = ssl->s3;
            uVar17 = *(uint *)psVar9->read_sequence;
            uVar13 = *(undefined4 *)(psVar9->read_sequence + 4);
            uVar7 = (uint)psVar9->write_sequence & 3;
            puVar22 = psVar9->write_sequence + -uVar7;
            *(uint *)puVar22 = *(uint *)puVar22 & -1 << (4 - uVar7) * 8 | uVar17 >> uVar7 * 8;
            puVar22 = psVar9->write_sequence + 3;
            uVar7 = (uint)puVar22 & 3;
            *(uint *)(puVar22 + -uVar7) =
                 *(uint *)(puVar22 + -uVar7) & 0xffffffffU >> (uVar7 + 1) * 8 |
                 uVar17 << (3 - uVar7) * 8;
            *(undefined4 *)(psVar9->write_sequence + 4) = uVar13;
            if (ssl->state != 0x2130) {
              psVar9 = ssl->s3;
              goto LAB_0049a0f8;
            }
            pdVar14 = ssl->d1;
            puVar5 = (undefined1 *)0x2;
            pdVar14->mtu = 0;
            pdVar14->handshake_read_seq = 2;
            pdVar14->handshake_write_seq = 1;
            pdVar14->next_handshake_write_seq = 1;
          }
        }
        else {
          if (0x2114 < iVar24) goto LAB_0049a540;
          if (iVar24 == 0x2113) {
            pcVar19 = ssl->init_buf->data;
            pcVar19[0xc] = (char)((uint)ssl->version >> 8);
            pcVar19[0xd] = (char)ssl->version;
            if ((*(code **)(ssl->psk_server_callback + 0x78) == (code *)0x0) ||
               (iVar16 = (**(code **)(ssl->psk_server_callback + 0x78))
                                   (ssl,ssl->d1->cookie,&ssl->d1->cookie_len),
               puVar2 = PTR_memcpy_006a9aec, iVar16 == 0)) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x108,0x44,"d1_srvr.c",0x3b9);
              puVar5 = (undefined1 *)0x0;
              ssl->state = 5;
              goto LAB_00499fc0;
            }
            pcVar19[0xe] = (char)ssl->d1->cookie_len;
            iVar16 = (*(code *)puVar2)(pcVar19 + 0xf,ssl->d1->cookie,ssl->d1->cookie_len);
            iVar16 = iVar16 + ssl->d1->cookie_len;
            iVar10 = iVar16 - (int)(pcVar19 + 0xc);
            dtls1_set_message_header(ssl,pcVar19,3,iVar10,0,iVar10);
            ssl->init_off = 0;
            ssl->state = 0x2114;
            ssl->init_num = iVar16 - (int)pcVar19;
          }
          puVar5 = (undefined1 *)dtls1_do_write(ssl,0x16);
          if (0 < (int)puVar5) {
            psVar9 = ssl->s3;
            iVar16 = ssl->version;
            ssl->state = 0x2100;
            (psVar9->tmp).next_state = 0x2110;
            if (iVar16 == 0x100) goto LAB_0049a0f8;
            ssl3_init_finished_mac(ssl);
            iVar16 = (ssl->s3->tmp).reuse_message;
            goto joined_r0x00499e58;
          }
        }
      }
      else {
        ssl->shutdown = 0;
        dtls1_clear_sent_buffer(ssl);
        dtls1_start_timer(ssl);
        if (ssl->state == 0x2120) {
          dtls1_set_message_header(ssl,ssl->init_buf->data,0,0,0,0);
          ssl->init_off = 0;
          ssl->state = 0x2121;
          ssl->init_num = 0xc;
        }
        puVar5 = (undefined1 *)dtls1_do_write(ssl,0x16);
        if (0 < (int)puVar5) {
          (ssl->s3->tmp).next_state = 0x2110;
          ssl->init_num = 0;
          ssl->state = 0x2100;
          ssl3_init_finished_mac(ssl);
          psVar9 = ssl->s3;
          goto LAB_0049a0f8;
        }
      }
    }
    else {
LAB_0049a7e8:
      dtls1_start_timer(ssl);
      if (ssl->state == 0x2170) {
        dtls1_set_message_header(ssl,ssl->init_buf->data,0xe,0,0,0);
        ssl->init_off = 0;
        ssl->state = 0x2171;
        ssl->init_num = 0xc;
        dtls1_buffer_message(ssl,0);
      }
      puVar5 = (undefined1 *)dtls1_do_write(ssl,0x16);
      if (0 < (int)puVar5) {
        psVar9 = ssl->s3;
        (psVar9->tmp).next_state = 0x2180;
        ssl->init_num = 0;
        ssl->state = 0x2100;
        goto LAB_0049a0f8;
      }
    }
LAB_00499fc0:
    iVar16 = ssl->in_handshake;
LAB_00499fc4:
    ssl->in_handshake = iVar16 + -1;
    if (p_Var20 != (_func_3152 *)0x0) {
      (*p_Var20)(ssl,0x2002,(int)puVar5);
    }
  }
  if (iStack_204 == *(int *)puVar4) {
    return puVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((iStack_204 != 0xfeff) && (iStack_204 != 0x100)) {
    return (undefined1 *)0x0;
  }
  return DTLSv1_client_method_data_15875;
code_r0x00499ebc:
  psVar9 = ssl->s3;
  if ((psVar9->tmp).cert_request != 0) {
    puVar5 = (undefined1 *)ssl3_get_client_certificate(ssl);
    if ((int)puVar5 < 1) goto LAB_00499fc0;
    psVar9 = ssl->s3;
  }
  iVar16 = (psVar9->tmp).reuse_message;
  ssl->init_num = 0;
  ssl->state = 0x2190;
joined_r0x00499e58:
  if (iVar16 == 0) goto LAB_00499ee0;
  goto LAB_00499e60;
}

