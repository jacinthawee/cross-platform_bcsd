
int dtls1_connect(SSL *param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  _func_3154 *p_Var7;
  ssl3_enc_method *psVar8;
  BIO *pBVar9;
  SSL_SESSION *pSVar10;
  undefined4 uVar11;
  byte *pbVar12;
  BUF_MEM *pBVar13;
  ssl3_state_st *psVar14;
  dtls1_state_st *pdVar15;
  SSL_CIPHER *pSVar16;
  SSL_COMP *pSVar17;
  SSL_METHOD *pSVar18;
  uint uVar19;
  int *piVar20;
  undefined4 uVar21;
  int iVar22;
  _func_3152 *p_Var23;
  int iVar24;
  undefined4 local_34;
  int local_30;
  int *local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  local_34 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&local_34,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar4 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  p_Var23 = param_1->info_callback;
  *puVar4 = 0;
  if (p_Var23 == (_func_3152 *)0x0) {
    p_Var23 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar5 = SSL_state(param_1);
  if (((uVar5 & 0x3000) == 0) || (uVar5 = SSL_state(param_1), (uVar5 & 0x4000) != 0)) {
    SSL_clear(param_1);
    uVar5 = param_1->tlsext_heartbeat;
  }
  else {
    uVar5 = param_1->tlsext_heartbeat;
  }
  if (uVar5 != 0) {
    dtls1_stop_timer(param_1);
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  iVar6 = param_1->state;
LAB_0049fcf8:
  iVar22 = iVar6;
  if (0x1173 < iVar6) goto LAB_0049fd9c;
LAB_0049fd08:
  puVar2 = PTR_BIO_ctrl_006a7f18;
  if (0x116f < iVar22) {
    dtls1_start_timer(param_1);
    iVar6 = dtls1_send_client_certificate(param_1);
    if (0 < iVar6) {
      psVar14 = param_1->s3;
      param_1->init_num = 0;
      param_1->state = 0x1180;
      goto LAB_004a027c;
    }
    goto LAB_0049ff30;
  }
  if (0x1127 < iVar22) goto LAB_0049ff9c;
  if (iVar22 < 0x1126) {
    if (iVar22 == 0x1100) {
      param_1->rwstate = 2;
      iVar6 = (*(code *)puVar2)(param_1->wbio,0xb,0,0);
      if (0 < iVar6) {
        psVar14 = param_1->s3;
        param_1->rwstate = 1;
        param_1->state = (psVar14->tmp).next_state;
        goto LAB_004a027c;
      }
      iVar6 = (*(code *)PTR_BIO_test_flags_006a8954)(param_1->wbio,8);
      if (iVar6 != 0) goto LAB_004a06dc;
      iVar6 = -1;
      param_1->rwstate = 1;
      param_1->state = (param_1->s3->tmp).next_state;
    }
    else if (iVar22 < 0x1101) {
      if (iVar22 == 0x1000) goto LAB_004a01c8;
      if (iVar22 == 0x1003) goto LAB_004a01c8;
      if (iVar22 != 3) goto LAB_004a0404;
      ssl3_cleanup_key_block(param_1);
      if ((param_1->s3->flags & 4U) == 0) {
        ssl_free_wbio_buffer(param_1);
      }
      param_1->init_num = 0;
      param_1->tlsext_hb_seq = 0;
      param_1->new_session = 0;
      ssl_update_cache(param_1,1);
      if (param_1->hit == 0) {
        p_Var7 = param_1->psk_server_callback;
      }
      else {
        p_Var7 = param_1->psk_server_callback;
        *(int *)(p_Var7 + 0x58) = *(int *)(p_Var7 + 0x58) + 1;
      }
      iVar6 = *(int *)(p_Var7 + 0x3c);
      param_1->handshake_func = dtls1_connect;
      *(int *)(p_Var7 + 0x3c) = iVar6 + 1;
      if (p_Var23 != (_func_3152 *)0x0) {
        (*p_Var23)(param_1,0x20,1);
      }
      pdVar15 = param_1->d1;
      iVar6 = 1;
      pdVar15->handshake_read_seq = 0;
      pdVar15->next_handshake_write_seq = 0;
    }
    else {
      if (iVar22 < 0x1110) {
LAB_004a0404:
        uVar21 = 0xff;
        uVar11 = 0x2e2;
LAB_004a0410:
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf9,uVar21,"d1_clnt.c",uVar11);
        iVar6 = -1;
        param_1->in_handshake = param_1->in_handshake + -1;
        goto LAB_0049ff3c;
      }
      if (iVar22 < 0x1112) {
        param_1->shutdown = 0;
        ssl3_init_finished_mac(param_1);
        dtls1_start_timer(param_1);
        iVar6 = dtls1_client_hello(param_1);
        if (0 < iVar6) {
          if (param_1->d1->send_cookie == 0) {
            param_1->state = 0x1120;
          }
          else {
            param_1->state = 0x1100;
            (param_1->s3->tmp).next_state = 0x1120;
          }
          param_1->init_num = 0;
          if (param_1->bbio != param_1->wbio) {
            pBVar9 = (BIO *)(*(code *)PTR_BIO_push_006a85c0)();
            psVar14 = param_1->s3;
            param_1->wbio = pBVar9;
            goto LAB_004a027c;
          }
          goto LAB_004a0030;
        }
      }
      else {
        if (1 < iVar22 - 0x1120U) goto LAB_004a0404;
        iVar6 = ssl3_get_server_hello(param_1);
        if (0 < iVar6) {
          iVar6 = 0x11d0;
          param_1->init_num = 0;
          if (param_1->hit == 0) {
            iVar6 = 0x1126;
          }
          param_1->state = iVar6;
          if ((param_1->s3->tmp).reuse_message != 0) goto LAB_0049fd88;
          goto LAB_0049fe0c;
        }
      }
    }
    goto LAB_0049ff30;
  }
  local_30 = 0;
  iVar6 = (*param_1->method->ssl_get_message)(param_1,0x1126,0x1127,-1,param_1->mode,&local_30);
  if (local_30 != 0) {
    psVar14 = param_1->s3;
    if ((psVar14->tmp).message_type == 3) {
      pbVar12 = (byte *)param_1->init_msg;
      if (((uint)*pbVar12 != param_1->version >> 8) ||
         ((uint)pbVar12[1] != (param_1->version & 0xffU))) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xfb,0x10a,"d1_clnt.c",0x3a4);
        param_1->version = param_1->version & 0xff00U | (uint)pbVar12[1];
        ssl3_send_alert(param_1,2,0x46);
        iVar6 = -1;
        goto LAB_0049ff30;
      }
      bVar1 = pbVar12[2];
      (*(code *)PTR_memcpy_006aabf4)(param_1->d1->cookie,pbVar12 + 3,(uint)bVar1);
      pdVar15 = param_1->d1;
      pdVar15->cookie_len = (uint)bVar1;
      pdVar15->send_cookie = 1;
    }
    else {
      param_1->d1->send_cookie = 0;
      (psVar14->tmp).reuse_message = 1;
    }
LAB_004a05c0:
    dtls1_stop_timer(param_1);
    iVar6 = 0x1130;
    psVar14 = param_1->s3;
    uVar5 = param_1->d1->send_cookie;
    param_1->init_num = 0;
    if (uVar5 != 0) {
      iVar6 = 0x1110;
    }
    param_1->state = iVar6;
LAB_004a027c:
    if ((psVar14->tmp).reuse_message == 0) goto LAB_0049fe0c;
    iVar22 = param_1->state;
    do {
      if (iVar22 < 0x1174) goto LAB_0049fd08;
LAB_0049fd9c:
      if (0x11d1 < iVar22) {
        if (iVar22 < 0x11f2) {
          if (iVar22 < 0x11f0) {
            if (1 < iVar22 - 0x11e0U) goto LAB_004a0404;
            iVar6 = ssl3_get_new_session_ticket(param_1);
            if (iVar6 < 1) goto LAB_0049ff30;
            psVar14 = param_1->s3;
            param_1->init_num = 0;
            param_1->state = 0x11d0;
          }
          else {
            iVar6 = ssl3_get_cert_status(param_1);
            if (iVar6 < 1) goto LAB_0049ff30;
            psVar14 = param_1->s3;
            param_1->init_num = 0;
            param_1->state = 0x1140;
          }
          goto LAB_004a027c;
        }
        if ((iVar22 == 0x4000) || (iVar22 == 0x5000)) goto LAB_004a01c8;
        if (iVar22 == 0x3004) goto code_r0x004a01ac;
        goto LAB_004a0404;
      }
      if (0x11cf < iVar22) {
        param_1->d1->listen = 1;
        iVar6 = ssl3_get_finished(param_1,0x11d0,0x11d1);
        if (iVar6 < 1) goto LAB_0049ff30;
        dtls1_stop_timer(param_1);
        iVar6 = 0x11a0;
        psVar14 = param_1->s3;
        if (param_1->hit == 0) {
          iVar6 = 3;
        }
        param_1->init_num = 0;
        param_1->state = iVar6;
        goto LAB_004a027c;
      }
      if (iVar22 < 0x1192) {
        if (0x118f < iVar22) goto LAB_004a0468;
        if (1 < iVar22 - 0x1180U) goto LAB_004a0404;
        dtls1_start_timer(param_1);
        iVar6 = dtls1_send_client_key_exchange(param_1);
        if (iVar6 < 1) goto LAB_0049ff30;
        psVar14 = param_1->s3;
        if ((psVar14->tmp).cert_req == 1) {
          param_1->init_num = 0;
          param_1->state = 0x1190;
        }
        else {
          param_1->state = 0x11a0;
          psVar14->change_cipher_spec = 0;
LAB_0049fdfc:
          param_1->init_num = 0;
        }
      }
      else {
        if (iVar22 < 0x11a0) goto LAB_004a0404;
        if (iVar22 < 0x11a2) {
          if (param_1->hit == 0) {
            dtls1_start_timer(param_1);
          }
          iVar6 = dtls1_send_change_cipher_spec(param_1,0x11a0,0x11a1);
          if (iVar6 < 1) goto LAB_0049ff30;
          pSVar10 = param_1->session;
          param_1->init_num = 0;
          param_1->state = 0x11b0;
          pSVar17 = (param_1->s3->tmp).new_compression;
          *(SSL_CIPHER **)(pSVar10->krb5_client_princ + 0x24) = (param_1->s3->tmp).new_cipher;
          if (pSVar17 == (SSL_COMP *)0x0) {
            iVar6 = 0;
          }
          else {
            iVar6 = pSVar17->id;
          }
          pSVar18 = param_1->method;
          *(int *)(pSVar10->krb5_client_princ + 0x20) = iVar6;
          iVar6 = (**(code **)(pSVar18->ssl3_enc + 8))(param_1);
          if ((iVar6 == 0) ||
             (iVar6 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12), iVar6 == 0))
          goto LAB_004a06dc;
          dtls1_reset_seq_numbers(param_1,2);
          psVar14 = param_1->s3;
          goto LAB_004a027c;
        }
        if (1 < iVar22 - 0x11b0U) goto LAB_004a0404;
        if (param_1->hit == 0) {
          dtls1_start_timer(param_1);
        }
        psVar8 = param_1->method->ssl3_enc;
        iVar6 = dtls1_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar8 + 0x20),
                                    *(undefined4 *)(psVar8 + 0x24));
        if (iVar6 < 1) goto LAB_0049ff30;
        psVar14 = param_1->s3;
        iVar6 = param_1->hit;
        uVar19 = psVar14->flags;
        param_1->state = 0x1100;
        uVar5 = uVar19 & 0xfffffffb;
        psVar14->flags = uVar5;
        if (iVar6 == 0) {
          if (param_1->tlsext_ocsp_resplen == 0) {
            (psVar14->tmp).next_state = 0x11d0;
            param_1->init_num = 0;
          }
          else {
            (psVar14->tmp).next_state = 0x11e0;
            param_1->init_num = 0;
          }
        }
        else {
          (psVar14->tmp).next_state = 3;
          if ((uVar19 & 2) == 0) goto LAB_0049fdfc;
          param_1->state = 3;
          psVar14->delay_buf_pop_ret = 0;
          psVar14->flags = uVar5 | 4;
          param_1->init_num = 0;
        }
      }
      if ((psVar14->tmp).reuse_message == 0) {
LAB_0049fe0c:
        if ((param_1->ctx != (SSL_CTX *)0x0) &&
           (iVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(param_1->wbio,0xb,0,0), iVar6 < 1)) {
          iVar22 = param_1->in_handshake;
          goto LAB_0049ff34;
        }
        if (p_Var23 != (_func_3152 *)0x0) {
          iVar24 = param_1->state;
          iVar6 = iVar22;
          if (iVar24 != iVar22) {
            param_1->state = iVar22;
            (*p_Var23)(param_1,0x1001,1);
            param_1->state = iVar24;
            iVar6 = iVar24;
          }
          goto LAB_0049fcf8;
        }
      }
LAB_0049fd88:
      iVar22 = param_1->state;
    } while( true );
  }
  if (0 < iVar6) goto LAB_004a05c0;
  iVar22 = param_1->in_handshake;
  goto LAB_0049ff34;
code_r0x004a01ac:
  param_1->state = 0x1000;
  param_1->tlsext_hb_seq = 1;
  *(int *)(param_1->psk_server_callback + 0x38) = *(int *)(param_1->psk_server_callback + 0x38) + 1;
LAB_004a01c8:
  param_1->server = 0;
  if (p_Var23 != (_func_3152 *)0x0) {
    (*p_Var23)(param_1,0x10,1);
  }
  uVar5 = param_1->version & 0xff00;
  if ((uVar5 != 0xfe00) && (uVar5 != 0x100)) {
    uVar21 = 0x44;
    uVar11 = 0xd6;
    goto LAB_004a0410;
  }
  param_1->type = 0x1000;
  if (param_1->init_buf == (BUF_MEM *)0x0) {
    pBVar13 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a859c)();
    if (pBVar13 == (BUF_MEM *)0x0) goto LAB_004a06dc;
    iVar6 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(pBVar13,0x4000);
    puVar2 = PTR_BUF_MEM_free_006a8594;
    if (iVar6 == 0) {
      param_1->in_handshake = param_1->in_handshake + -1;
      (*(code *)puVar2)(pBVar13);
      iVar6 = -1;
      goto LAB_0049ff3c;
    }
    param_1->init_buf = pBVar13;
  }
  iVar6 = ssl3_setup_buffers(param_1);
  if ((iVar6 == 0) ||
     (iVar6 = ssl_init_wbio_buffer(param_1,0), puVar2 = PTR_memset_006aab00, iVar6 == 0))
  goto LAB_004a06dc;
  psVar14 = param_1->s3;
  param_1->state = 0x1110;
  *(int *)(param_1->psk_server_callback + 0x34) = *(int *)(param_1->psk_server_callback + 0x34) + 1;
  param_1->init_num = 0;
  (*(code *)puVar2)(psVar14->client_random,0,0x20);
  psVar14 = param_1->s3;
  param_1->d1->send_cookie = 0;
  param_1->hit = 0;
  goto LAB_004a027c;
LAB_004a0468:
  dtls1_start_timer(param_1);
  iVar6 = dtls1_send_client_verify(param_1);
  if (iVar6 < 1) goto LAB_0049ff30;
  psVar14 = param_1->s3;
  param_1->init_num = 0;
  param_1->state = 0x11a0;
  psVar14->change_cipher_spec = 0;
  goto LAB_004a027c;
LAB_0049ff9c:
  if (iVar22 < 0x1142) {
    if (iVar22 < 0x1140) {
      if (1 < iVar22 - 0x1130U) goto LAB_004a0404;
      iVar6 = ssl3_check_finished(param_1);
      if (0 < iVar6) {
        iVar24 = 0x11e0;
        if (iVar6 == 2) {
          psVar14 = param_1->s3;
          param_1->init_num = 0;
          if (param_1->tlsext_ocsp_resplen == 0) {
            iVar24 = 0x11d0;
          }
          param_1->hit = 1;
          param_1->state = iVar24;
          goto LAB_004a027c;
        }
        pSVar16 = (param_1->s3->tmp).new_cipher;
        if (((pSVar16->algorithm_auth & 4) != 0) || ((pSVar16->algorithm_mkey & 0x100) != 0)) {
          param_1->init_num = 0;
          iVar22 = 0x1140;
          param_1->state = 0x1140;
          goto LAB_0049fffc;
        }
        iVar6 = ssl3_get_server_certificate(param_1);
        if (iVar6 < 1) goto LAB_0049ff30;
        if (param_1->tlsext_status_type == 0) {
          iVar6 = 0x1140;
          param_1->state = 0x1140;
        }
        else {
          iVar6 = 0x11f0;
          param_1->state = 0x11f0;
        }
        param_1->init_num = 0;
        if ((param_1->s3->tmp).reuse_message == 0) goto LAB_0049fe0c;
        goto LAB_0049fcf8;
      }
    }
    else {
LAB_0049fffc:
      iVar6 = ssl3_get_key_exchange(param_1);
      if (0 < iVar6) {
        param_1->init_num = 0;
        param_1->state = 0x1150;
        iVar6 = ssl3_check_cert_and_algorithm(param_1);
        if (iVar6 != 0) {
LAB_004a0030:
          psVar14 = param_1->s3;
          goto LAB_004a027c;
        }
LAB_004a06dc:
        iVar6 = -1;
      }
    }
  }
  else {
    if (iVar22 < 0x1150) goto LAB_004a0404;
    if (iVar22 < 0x1152) {
      iVar6 = ssl3_get_certificate_request(param_1);
      if (0 < iVar6) {
        psVar14 = param_1->s3;
        param_1->init_num = 0;
        param_1->state = 0x1160;
        goto LAB_004a027c;
      }
    }
    else {
      if (1 < iVar22 - 0x1160U) goto LAB_004a0404;
      iVar6 = ssl3_get_server_done(param_1);
      if (0 < iVar6) {
        dtls1_stop_timer(param_1);
        iVar6 = 0x1170;
        psVar14 = param_1->s3;
        if ((psVar14->tmp).cert_req == 0) {
          iVar6 = 0x1180;
        }
        (psVar14->tmp).next_state = iVar6;
        param_1->init_num = 0;
        param_1->state = iVar6;
        goto LAB_004a027c;
      }
    }
  }
LAB_0049ff30:
  iVar22 = param_1->in_handshake;
LAB_0049ff34:
  param_1->in_handshake = iVar22 + -1;
LAB_0049ff3c:
  if (p_Var23 != (_func_3152 *)0x0) {
    (*p_Var23)(param_1,0x1002,iVar6);
  }
  if (local_2c != *(int **)puVar3) {
    piVar20 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    while (iVar6 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar20 + 0x238)), iVar6 != 0
          ) {
      iVar22 = *(int *)(iVar6 + 8);
      if (*(int *)(iVar22 + 8) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(int *)(iVar22 + 8));
        iVar22 = *(int *)(iVar6 + 8);
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar6);
    }
    while (iVar6 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar20 + 0x240)), iVar6 != 0
          ) {
      iVar22 = *(int *)(iVar6 + 8);
      if (*(int *)(iVar22 + 8) != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(*(int *)(iVar22 + 8));
        iVar22 = *(int *)(iVar6 + 8);
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar6);
    }
    while (iVar6 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar20 + 0x244)), iVar6 != 0
          ) {
      iVar22 = *(int *)(iVar6 + 8);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar22 + 0x2c));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar6);
    }
    iVar6 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar20 + 0x248));
    if (iVar6 == 0) goto LAB_004a0aa8;
    do {
      iVar22 = *(int *)(iVar6 + 8);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar22 + 0x2c));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar6);
      iVar6 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar20 + 0x248));
    } while (iVar6 != 0);
    iVar6 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar20 + 0x250));
    while (iVar6 != 0) {
      iVar22 = *(int *)(iVar6 + 8);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar22 + 0x2c));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
      (*(code *)PTR_pitem_free_006a939c)(iVar6);
LAB_004a0aa8:
      iVar6 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*piVar20 + 0x250));
    }
    return 0;
  }
  return iVar6;
}

