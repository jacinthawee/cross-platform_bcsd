
int dtls1_send_client_certificate(SSL *param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uVar7;
  _func_3154 *p_Var8;
  ssl3_enc_method *psVar9;
  BIO *pBVar10;
  SSL_SESSION *pSVar11;
  undefined4 uVar12;
  byte *pbVar13;
  BUF_MEM *pBVar14;
  ssl3_state_st *psVar15;
  dtls1_state_st *pdVar16;
  SSL_CIPHER *pSVar17;
  SSL_COMP *pSVar18;
  SSL_METHOD *pSVar19;
  SSL *ssl;
  uint uVar20;
  undefined4 uVar21;
  int iVar22;
  uint unaff_s2;
  _func_3152 *p_Var23;
  int iVar24;
  undefined4 uStack_74;
  int iStack_70;
  int *piStack_6c;
  SSL *pSStack_68;
  undefined *puStack_64;
  uint uStack_60;
  X509 *local_1c;
  EVP_PKEY *local_18;
  SSL *local_14;
  
  puStack_64 = PTR___stack_chk_guard_006aabf0;
  iVar4 = param_1->state;
  local_1c = (X509 *)0x0;
  local_18 = (EVP_PKEY *)0x0;
  local_14 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  if (iVar4 == 0x1170) {
    if ((((int **)param_1->cert == (int **)0x0) || (piVar5 = *(int **)param_1->cert, *piVar5 == 0))
       || (piVar5[1] == 0)) {
      param_1->state = 0x1171;
      goto LAB_0049faac;
    }
LAB_0049fa48:
    psVar15 = param_1->s3;
LAB_0049fa4c:
    iVar4 = (psVar15->tmp).cert_req;
    param_1->state = 0x1173;
    if (iVar4 == 2) {
      uVar12 = 0;
    }
    else {
      uVar12 = **(undefined4 **)param_1->cert;
    }
    iVar4 = dtls1_output_cert_chain(param_1,uVar12);
    param_1->init_num = iVar4;
    param_1->init_off = 0;
    dtls1_buffer_message(param_1,0);
  }
  else {
    if (iVar4 == 0x1171) {
LAB_0049faac:
      unaff_s2 = ssl_do_client_cert_cb(param_1,&local_1c,&local_18);
      if ((int)unaff_s2 < 0) {
        iVar4 = -1;
        param_1->rwstate = 4;
        goto LAB_0049f9fc;
      }
      param_1->rwstate = 1;
      if (unaff_s2 == 1) {
        if ((local_18 == (EVP_PKEY *)0x0) || (local_1c == (X509 *)0x0)) {
          unaff_s2 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x105,0x6a,"d1_clnt.c");
        }
        else {
          param_1->state = 0x1171;
          iVar4 = SSL_use_certificate(param_1,local_1c);
          if (iVar4 == 0) {
            unaff_s2 = 0;
          }
          else {
            iVar4 = SSL_use_PrivateKey(param_1,local_18);
            unaff_s2 = (uint)(iVar4 != 0);
          }
        }
      }
      if (local_1c != (X509 *)0x0) {
        (*(code *)PTR_X509_free_006a7f90)();
      }
      if (local_18 != (EVP_PKEY *)0x0) {
        (*(code *)PTR_EVP_PKEY_free_006a7f78)();
      }
      if (unaff_s2 != 0) goto LAB_0049fa48;
      if (param_1->version == 0x300) {
        (param_1->s3->tmp).cert_req = 0;
        ssl3_send_alert(param_1,1,0x29);
        iVar4 = 1;
        goto LAB_0049f9fc;
      }
      psVar15 = param_1->s3;
      (psVar15->tmp).cert_req = 2;
      goto LAB_0049fa4c;
    }
    if (iVar4 == 0x1172) goto LAB_0049fa48;
  }
  iVar4 = dtls1_do_write(param_1,0x16);
LAB_0049f9fc:
  if (local_14 == *(SSL **)puStack_64) {
    return iVar4;
  }
  ssl = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  piStack_6c = *(int **)PTR___stack_chk_guard_006aabf0;
  pSStack_68 = param_1;
  uStack_60 = unaff_s2;
  uStack_74 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&uStack_74,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar6 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  p_Var23 = ssl->info_callback;
  *puVar6 = 0;
  if (p_Var23 == (_func_3152 *)0x0) {
    p_Var23 = *(_func_3152 **)(ssl->psk_server_callback + 0x9c);
  }
  ssl->in_handshake = ssl->in_handshake + 1;
  uVar7 = SSL_state(ssl);
  if (((uVar7 & 0x3000) == 0) || (uVar7 = SSL_state(ssl), (uVar7 & 0x4000) != 0)) {
    SSL_clear(ssl);
    uVar7 = ssl->tlsext_heartbeat;
  }
  else {
    uVar7 = ssl->tlsext_heartbeat;
  }
  if (uVar7 != 0) {
    dtls1_stop_timer(ssl);
    ssl->tlsext_heartbeat = 0;
    ssl->tlsext_hb_pending = ssl->tlsext_hb_pending + 1;
  }
  iVar4 = ssl->state;
LAB_0049fcf8:
  iVar22 = iVar4;
  if (0x1173 < iVar4) goto LAB_0049fd9c;
LAB_0049fd08:
  puVar2 = PTR_BIO_ctrl_006a7f18;
  if (0x116f < iVar22) {
    dtls1_start_timer(ssl);
    iVar4 = dtls1_send_client_certificate(ssl);
    if (0 < iVar4) {
      psVar15 = ssl->s3;
      ssl->init_num = 0;
      ssl->state = 0x1180;
      goto LAB_004a027c;
    }
    goto LAB_0049ff30;
  }
  if (0x1127 < iVar22) goto LAB_0049ff9c;
  if (iVar22 < 0x1126) {
    if (iVar22 == 0x1100) {
      ssl->rwstate = 2;
      iVar4 = (*(code *)puVar2)(ssl->wbio,0xb,0,0);
      if (0 < iVar4) {
        psVar15 = ssl->s3;
        ssl->rwstate = 1;
        ssl->state = (psVar15->tmp).next_state;
        goto LAB_004a027c;
      }
      iVar4 = (*(code *)PTR_BIO_test_flags_006a8954)(ssl->wbio,8);
      if (iVar4 != 0) goto LAB_004a06dc;
      iVar4 = -1;
      ssl->rwstate = 1;
      ssl->state = (ssl->s3->tmp).next_state;
    }
    else if (iVar22 < 0x1101) {
      if (iVar22 == 0x1000) goto LAB_004a01c8;
      if (iVar22 == 0x1003) goto LAB_004a01c8;
      if (iVar22 != 3) goto LAB_004a0404;
      ssl3_cleanup_key_block(ssl);
      if ((ssl->s3->flags & 4U) == 0) {
        ssl_free_wbio_buffer(ssl);
      }
      ssl->init_num = 0;
      ssl->tlsext_hb_seq = 0;
      ssl->new_session = 0;
      ssl_update_cache(ssl,1);
      if (ssl->hit == 0) {
        p_Var8 = ssl->psk_server_callback;
      }
      else {
        p_Var8 = ssl->psk_server_callback;
        *(int *)(p_Var8 + 0x58) = *(int *)(p_Var8 + 0x58) + 1;
      }
      iVar4 = *(int *)(p_Var8 + 0x3c);
      ssl->handshake_func = dtls1_connect;
      *(int *)(p_Var8 + 0x3c) = iVar4 + 1;
      if (p_Var23 != (_func_3152 *)0x0) {
        (*p_Var23)(ssl,0x20,1);
      }
      pdVar16 = ssl->d1;
      iVar4 = 1;
      pdVar16->handshake_read_seq = 0;
      pdVar16->next_handshake_write_seq = 0;
    }
    else {
      if (iVar22 < 0x1110) {
LAB_004a0404:
        uVar21 = 0xff;
        uVar12 = 0x2e2;
LAB_004a0410:
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf9,uVar21,"d1_clnt.c",uVar12);
        iVar4 = -1;
        ssl->in_handshake = ssl->in_handshake + -1;
        goto LAB_0049ff3c;
      }
      if (iVar22 < 0x1112) {
        ssl->shutdown = 0;
        ssl3_init_finished_mac(ssl);
        dtls1_start_timer(ssl);
        iVar4 = dtls1_client_hello(ssl);
        if (0 < iVar4) {
          if (ssl->d1->send_cookie == 0) {
            ssl->state = 0x1120;
          }
          else {
            ssl->state = 0x1100;
            (ssl->s3->tmp).next_state = 0x1120;
          }
          ssl->init_num = 0;
          if (ssl->bbio != ssl->wbio) {
            pBVar10 = (BIO *)(*(code *)PTR_BIO_push_006a85c0)();
            psVar15 = ssl->s3;
            ssl->wbio = pBVar10;
            goto LAB_004a027c;
          }
          goto LAB_004a0030;
        }
      }
      else {
        if (1 < iVar22 - 0x1120U) goto LAB_004a0404;
        iVar4 = ssl3_get_server_hello(ssl);
        if (0 < iVar4) {
          iVar4 = 0x11d0;
          ssl->init_num = 0;
          if (ssl->hit == 0) {
            iVar4 = 0x1126;
          }
          ssl->state = iVar4;
          if ((ssl->s3->tmp).reuse_message != 0) goto LAB_0049fd88;
          goto LAB_0049fe0c;
        }
      }
    }
    goto LAB_0049ff30;
  }
  iStack_70 = 0;
  iVar4 = (*ssl->method->ssl_get_message)(ssl,0x1126,0x1127,-1,ssl->mode,&iStack_70);
  if (iStack_70 != 0) {
    psVar15 = ssl->s3;
    if ((psVar15->tmp).message_type == 3) {
      pbVar13 = (byte *)ssl->init_msg;
      if (((uint)*pbVar13 != ssl->version >> 8) || ((uint)pbVar13[1] != (ssl->version & 0xffU))) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xfb,0x10a,"d1_clnt.c",0x3a4);
        ssl->version = ssl->version & 0xff00U | (uint)pbVar13[1];
        ssl3_send_alert(ssl,2,0x46);
        iVar4 = -1;
        goto LAB_0049ff30;
      }
      bVar1 = pbVar13[2];
      (*(code *)PTR_memcpy_006aabf4)(ssl->d1->cookie,pbVar13 + 3,(uint)bVar1);
      pdVar16 = ssl->d1;
      pdVar16->cookie_len = (uint)bVar1;
      pdVar16->send_cookie = 1;
    }
    else {
      ssl->d1->send_cookie = 0;
      (psVar15->tmp).reuse_message = 1;
    }
LAB_004a05c0:
    dtls1_stop_timer(ssl);
    iVar4 = 0x1130;
    psVar15 = ssl->s3;
    uVar7 = ssl->d1->send_cookie;
    ssl->init_num = 0;
    if (uVar7 != 0) {
      iVar4 = 0x1110;
    }
    ssl->state = iVar4;
LAB_004a027c:
    if ((psVar15->tmp).reuse_message == 0) goto LAB_0049fe0c;
    iVar22 = ssl->state;
    do {
      if (iVar22 < 0x1174) goto LAB_0049fd08;
LAB_0049fd9c:
      if (0x11d1 < iVar22) {
        if (iVar22 < 0x11f2) {
          if (iVar22 < 0x11f0) {
            if (1 < iVar22 - 0x11e0U) goto LAB_004a0404;
            iVar4 = ssl3_get_new_session_ticket(ssl);
            if (iVar4 < 1) goto LAB_0049ff30;
            psVar15 = ssl->s3;
            ssl->init_num = 0;
            ssl->state = 0x11d0;
          }
          else {
            iVar4 = ssl3_get_cert_status(ssl);
            if (iVar4 < 1) goto LAB_0049ff30;
            psVar15 = ssl->s3;
            ssl->init_num = 0;
            ssl->state = 0x1140;
          }
          goto LAB_004a027c;
        }
        if ((iVar22 == 0x4000) || (iVar22 == 0x5000)) goto LAB_004a01c8;
        if (iVar22 == 0x3004) goto code_r0x004a01ac;
        goto LAB_004a0404;
      }
      if (0x11cf < iVar22) {
        ssl->d1->listen = 1;
        iVar4 = ssl3_get_finished(ssl,0x11d0,0x11d1);
        if (iVar4 < 1) goto LAB_0049ff30;
        dtls1_stop_timer(ssl);
        iVar4 = 0x11a0;
        psVar15 = ssl->s3;
        if (ssl->hit == 0) {
          iVar4 = 3;
        }
        ssl->init_num = 0;
        ssl->state = iVar4;
        goto LAB_004a027c;
      }
      if (iVar22 < 0x1192) {
        if (0x118f < iVar22) goto LAB_004a0468;
        if (1 < iVar22 - 0x1180U) goto LAB_004a0404;
        dtls1_start_timer(ssl);
        iVar4 = dtls1_send_client_key_exchange(ssl);
        if (iVar4 < 1) goto LAB_0049ff30;
        psVar15 = ssl->s3;
        if ((psVar15->tmp).cert_req == 1) {
          ssl->init_num = 0;
          ssl->state = 0x1190;
        }
        else {
          ssl->state = 0x11a0;
          psVar15->change_cipher_spec = 0;
LAB_0049fdfc:
          ssl->init_num = 0;
        }
      }
      else {
        if (iVar22 < 0x11a0) goto LAB_004a0404;
        if (iVar22 < 0x11a2) {
          if (ssl->hit == 0) {
            dtls1_start_timer(ssl);
          }
          iVar4 = dtls1_send_change_cipher_spec(ssl,0x11a0,0x11a1);
          if (iVar4 < 1) goto LAB_0049ff30;
          pSVar11 = ssl->session;
          ssl->init_num = 0;
          ssl->state = 0x11b0;
          pSVar18 = (ssl->s3->tmp).new_compression;
          *(SSL_CIPHER **)(pSVar11->krb5_client_princ + 0x24) = (ssl->s3->tmp).new_cipher;
          if (pSVar18 == (SSL_COMP *)0x0) {
            iVar4 = 0;
          }
          else {
            iVar4 = pSVar18->id;
          }
          pSVar19 = ssl->method;
          *(int *)(pSVar11->krb5_client_princ + 0x20) = iVar4;
          iVar4 = (**(code **)(pSVar19->ssl3_enc + 8))(ssl);
          if ((iVar4 == 0) ||
             (iVar4 = (**(code **)(ssl->method->ssl3_enc + 0x10))(ssl,0x12), iVar4 == 0))
          goto LAB_004a06dc;
          dtls1_reset_seq_numbers(ssl,2);
          psVar15 = ssl->s3;
          goto LAB_004a027c;
        }
        if (1 < iVar22 - 0x11b0U) goto LAB_004a0404;
        if (ssl->hit == 0) {
          dtls1_start_timer(ssl);
        }
        psVar9 = ssl->method->ssl3_enc;
        iVar4 = dtls1_send_finished(ssl,0x11b0,0x11b1,*(undefined4 *)(psVar9 + 0x20),
                                    *(undefined4 *)(psVar9 + 0x24));
        if (iVar4 < 1) goto LAB_0049ff30;
        psVar15 = ssl->s3;
        iVar4 = ssl->hit;
        uVar20 = psVar15->flags;
        ssl->state = 0x1100;
        uVar7 = uVar20 & 0xfffffffb;
        psVar15->flags = uVar7;
        if (iVar4 == 0) {
          if (ssl->tlsext_ocsp_resplen == 0) {
            (psVar15->tmp).next_state = 0x11d0;
            ssl->init_num = 0;
          }
          else {
            (psVar15->tmp).next_state = 0x11e0;
            ssl->init_num = 0;
          }
        }
        else {
          (psVar15->tmp).next_state = 3;
          if ((uVar20 & 2) == 0) goto LAB_0049fdfc;
          ssl->state = 3;
          psVar15->delay_buf_pop_ret = 0;
          psVar15->flags = uVar7 | 4;
          ssl->init_num = 0;
        }
      }
      if ((psVar15->tmp).reuse_message == 0) {
LAB_0049fe0c:
        if ((ssl->ctx != (SSL_CTX *)0x0) &&
           (iVar4 = (*(code *)PTR_BIO_ctrl_006a7f18)(ssl->wbio,0xb,0,0), iVar4 < 1)) {
          iVar22 = ssl->in_handshake;
          goto LAB_0049ff34;
        }
        if (p_Var23 != (_func_3152 *)0x0) {
          iVar24 = ssl->state;
          iVar4 = iVar22;
          if (iVar24 != iVar22) {
            ssl->state = iVar22;
            (*p_Var23)(ssl,0x1001,1);
            ssl->state = iVar24;
            iVar4 = iVar24;
          }
          goto LAB_0049fcf8;
        }
      }
LAB_0049fd88:
      iVar22 = ssl->state;
    } while( true );
  }
  if (0 < iVar4) goto LAB_004a05c0;
  iVar22 = ssl->in_handshake;
  goto LAB_0049ff34;
code_r0x004a01ac:
  ssl->state = 0x1000;
  ssl->tlsext_hb_seq = 1;
  *(int *)(ssl->psk_server_callback + 0x38) = *(int *)(ssl->psk_server_callback + 0x38) + 1;
LAB_004a01c8:
  ssl->server = 0;
  if (p_Var23 != (_func_3152 *)0x0) {
    (*p_Var23)(ssl,0x10,1);
  }
  uVar7 = ssl->version & 0xff00;
  if ((uVar7 != 0xfe00) && (uVar7 != 0x100)) {
    uVar21 = 0x44;
    uVar12 = 0xd6;
    goto LAB_004a0410;
  }
  ssl->type = 0x1000;
  if (ssl->init_buf == (BUF_MEM *)0x0) {
    pBVar14 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a859c)();
    if (pBVar14 == (BUF_MEM *)0x0) goto LAB_004a06dc;
    iVar4 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(pBVar14,0x4000);
    puVar2 = PTR_BUF_MEM_free_006a8594;
    if (iVar4 == 0) {
      ssl->in_handshake = ssl->in_handshake + -1;
      (*(code *)puVar2)(pBVar14);
      iVar4 = -1;
      goto LAB_0049ff3c;
    }
    ssl->init_buf = pBVar14;
  }
  iVar4 = ssl3_setup_buffers(ssl);
  if ((iVar4 == 0) ||
     (iVar4 = ssl_init_wbio_buffer(ssl,0), puVar2 = PTR_memset_006aab00, iVar4 == 0))
  goto LAB_004a06dc;
  psVar15 = ssl->s3;
  ssl->state = 0x1110;
  *(int *)(ssl->psk_server_callback + 0x34) = *(int *)(ssl->psk_server_callback + 0x34) + 1;
  ssl->init_num = 0;
  (*(code *)puVar2)(psVar15->client_random,0,0x20);
  psVar15 = ssl->s3;
  ssl->d1->send_cookie = 0;
  ssl->hit = 0;
  goto LAB_004a027c;
LAB_004a0468:
  dtls1_start_timer(ssl);
  iVar4 = dtls1_send_client_verify(ssl);
  if (iVar4 < 1) goto LAB_0049ff30;
  psVar15 = ssl->s3;
  ssl->init_num = 0;
  ssl->state = 0x11a0;
  psVar15->change_cipher_spec = 0;
  goto LAB_004a027c;
LAB_0049ff9c:
  if (iVar22 < 0x1142) {
    if (iVar22 < 0x1140) {
      if (1 < iVar22 - 0x1130U) goto LAB_004a0404;
      iVar4 = ssl3_check_finished(ssl);
      if (0 < iVar4) {
        iVar24 = 0x11e0;
        if (iVar4 == 2) {
          psVar15 = ssl->s3;
          ssl->init_num = 0;
          if (ssl->tlsext_ocsp_resplen == 0) {
            iVar24 = 0x11d0;
          }
          ssl->hit = 1;
          ssl->state = iVar24;
          goto LAB_004a027c;
        }
        pSVar17 = (ssl->s3->tmp).new_cipher;
        if (((pSVar17->algorithm_auth & 4) != 0) || ((pSVar17->algorithm_mkey & 0x100) != 0)) {
          ssl->init_num = 0;
          iVar22 = 0x1140;
          ssl->state = 0x1140;
          goto LAB_0049fffc;
        }
        iVar4 = ssl3_get_server_certificate(ssl);
        if (iVar4 < 1) goto LAB_0049ff30;
        if (ssl->tlsext_status_type == 0) {
          iVar4 = 0x1140;
          ssl->state = 0x1140;
        }
        else {
          iVar4 = 0x11f0;
          ssl->state = 0x11f0;
        }
        ssl->init_num = 0;
        if ((ssl->s3->tmp).reuse_message == 0) goto LAB_0049fe0c;
        goto LAB_0049fcf8;
      }
    }
    else {
LAB_0049fffc:
      iVar4 = ssl3_get_key_exchange(ssl);
      if (0 < iVar4) {
        ssl->init_num = 0;
        ssl->state = 0x1150;
        iVar4 = ssl3_check_cert_and_algorithm(ssl);
        if (iVar4 != 0) {
LAB_004a0030:
          psVar15 = ssl->s3;
          goto LAB_004a027c;
        }
LAB_004a06dc:
        iVar4 = -1;
      }
    }
  }
  else {
    if (iVar22 < 0x1150) goto LAB_004a0404;
    if (iVar22 < 0x1152) {
      iVar4 = ssl3_get_certificate_request(ssl);
      if (0 < iVar4) {
        psVar15 = ssl->s3;
        ssl->init_num = 0;
        ssl->state = 0x1160;
        goto LAB_004a027c;
      }
    }
    else {
      if (1 < iVar22 - 0x1160U) goto LAB_004a0404;
      iVar4 = ssl3_get_server_done(ssl);
      if (0 < iVar4) {
        dtls1_stop_timer(ssl);
        iVar4 = 0x1170;
        psVar15 = ssl->s3;
        if ((psVar15->tmp).cert_req == 0) {
          iVar4 = 0x1180;
        }
        (psVar15->tmp).next_state = iVar4;
        ssl->init_num = 0;
        ssl->state = iVar4;
        goto LAB_004a027c;
      }
    }
  }
LAB_0049ff30:
  iVar22 = ssl->in_handshake;
LAB_0049ff34:
  ssl->in_handshake = iVar22 + -1;
LAB_0049ff3c:
  if (p_Var23 != (_func_3152 *)0x0) {
    (*p_Var23)(ssl,0x1002,iVar4);
  }
  if (piStack_6c != *(int **)puVar3) {
    piVar5 = piStack_6c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    while (iVar4 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar5 + 0x238)), iVar4 != 0)
    {
      iVar22 = *(int *)(iVar4 + 8);
      if (*(int *)(iVar22 + 8) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(int *)(iVar22 + 8));
        iVar22 = *(int *)(iVar4 + 8);
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar4);
    }
    while (iVar4 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar5 + 0x240)), iVar4 != 0)
    {
      iVar22 = *(int *)(iVar4 + 8);
      if (*(int *)(iVar22 + 8) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(int *)(iVar22 + 8));
        iVar22 = *(int *)(iVar4 + 8);
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar4);
    }
    while (iVar4 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar5 + 0x244)), iVar4 != 0)
    {
      iVar22 = *(int *)(iVar4 + 8);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar22 + 0x2c));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar4);
    }
    iVar4 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar5 + 0x248));
    if (iVar4 == 0) goto LAB_004a0aa8;
    do {
      iVar22 = *(int *)(iVar4 + 8);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar22 + 0x2c));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar4);
      iVar4 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar5 + 0x248));
    } while (iVar4 != 0);
    iVar4 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar5 + 0x250));
    while (iVar4 != 0) {
      iVar22 = *(int *)(iVar4 + 8);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar22 + 0x2c));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar4);
LAB_004a0aa8:
      iVar4 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar5 + 0x250));
    }
    return 0;
  }
  return iVar4;
}

