
int dtls1_accept(SSL *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  BUF_MEM *str;
  void *pvVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  undefined4 uVar8;
  uint uVar9;
  cert_st *pcVar10;
  SSL_CIPHER *pSVar11;
  int iVar12;
  ssl3_state_st *psVar13;
  SSL_METHOD *pSVar14;
  dtls1_state_st *pdVar15;
  _func_3152 *p_Var16;
  char *pcVar17;
  ssl3_enc_method *psVar18;
  bool bVar19;
  undefined4 in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  time_t local_2c [2];
  
  local_2c[0] = time((time_t *)0x0);
  RAND_add(local_2c,4,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
  ERR_clear_error();
  piVar1 = __errno_location();
  p_Var16 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var16 == (_func_3152 *)0x0) {
    p_Var16 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  uVar9 = param_1->d1->mtu;
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) == 0) || (iVar3 = SSL_state(param_1), iVar3 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  pcVar10 = param_1->cert;
  param_1->d1->mtu = uVar9;
  if (pcVar10 == (cert_st *)0x0) {
    ERR_put_error(0x14,0xf6,0xb3,"d1_srvr.c",0xb9);
    return -1;
  }
  if (param_1->tlsext_heartbeat != 0) {
    dtls1_stop_timer(param_1);
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  iVar3 = param_1->state;
LAB_00057214:
  iVar6 = iVar3;
  if (iVar6 < 0x2172) {
    if (0x216f < iVar6) {
      dtls1_start_timer(param_1);
      if (param_1->state == 0x2170) {
        dtls1_set_message_header(param_1,param_1->init_buf->data,0xe,0,0,0);
        param_1->state = 0x2171;
        param_1->init_off = 0;
        param_1->init_num = 0xc;
        dtls1_buffer_message(param_1,0);
      }
      iVar3 = dtls1_do_write(param_1,0x16);
      if (0 < iVar3) {
        psVar13 = param_1->s3;
        uVar2 = 0;
        (psVar13->tmp).next_state = 0x2180;
        param_1->init_num = 0;
        param_1->state = 0x2100;
        goto LAB_00057440;
      }
      goto LAB_00057386;
    }
    if (iVar6 < 0x2122) {
      if (0x211f < iVar6) {
        param_1->shutdown = 0;
        dtls1_clear_sent_buffer(param_1);
        dtls1_start_timer(param_1);
        if (param_1->state == 0x2120) {
          dtls1_set_message_header(param_1,param_1->init_buf->data,0,0,0,0);
          param_1->state = 0x2121;
          param_1->init_off = 0;
          param_1->init_num = 0xc;
        }
        iVar3 = dtls1_do_write(param_1,0x16);
        if (0 < iVar3) {
          (param_1->s3->tmp).next_state = 0x2110;
          param_1->state = 0x2100;
          param_1->init_num = 0;
          ssl3_init_finished_mac(param_1);
          psVar13 = param_1->s3;
          uVar2 = 0;
          goto LAB_00057440;
        }
        goto LAB_00057386;
      }
      if (iVar6 == 0x2100) {
        param_1->rwstate = 2;
        lVar5 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar5) {
          psVar13 = param_1->s3;
          uVar2 = 0;
          param_1->rwstate = 1;
          param_1->state = (psVar13->tmp).next_state;
          goto LAB_00057440;
        }
        iVar6 = BIO_test_flags(param_1->wbio,8);
        iVar3 = -1;
        if (iVar6 == 0) {
          iVar3 = -1;
          param_1->rwstate = 1;
          param_1->state = (param_1->s3->tmp).next_state;
        }
        goto LAB_00057386;
      }
      if (iVar6 < 0x2101) {
        if ((iVar6 == 0x2000) || (iVar6 == 0x2003)) goto LAB_00057596;
        if (iVar6 == 3) {
          ssl3_cleanup_key_block(param_1);
          ssl_free_wbio_buffer(param_1);
          param_1->init_num = 0;
          if (param_1->tlsext_hb_seq == 2) {
            param_1->tlsext_hb_seq = 0;
            param_1->new_session = 0;
            ssl_update_cache(param_1,2);
            *(int *)(param_1->psk_server_callback + 0x48) =
                 *(int *)(param_1->psk_server_callback + 0x48) + 1;
            param_1->handshake_func = dtls1_accept;
            if (p_Var16 != (_func_3152 *)0x0) {
              (*p_Var16)(param_1,0x20,1);
            }
          }
          pdVar15 = param_1->d1;
          iVar3 = 1;
          pdVar15->handshake_read_seq = 0;
          pdVar15->handshake_write_seq = 0;
          pdVar15->next_handshake_write_seq = 0;
          dtls1_clear_received_buffer(param_1);
LAB_00057386:
          param_1->in_handshake = param_1->in_handshake + -1;
          if (p_Var16 == (_func_3152 *)0x0) {
            return iVar3;
          }
          (*p_Var16)(param_1,0x2002,iVar3);
          return iVar3;
        }
        goto LAB_00057700;
      }
      if (iVar6 < 0x2110) goto LAB_00057700;
      if (iVar6 < 0x2113) {
        param_1->shutdown = 0;
        iVar3 = ssl3_get_client_hello(param_1);
        if (0 < iVar3) {
          dtls1_stop_timer(param_1);
          if ((iVar3 == 1) && (lVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar5 << 0x12 < 0)) {
            iVar3 = 0x2113;
          }
          else {
            iVar3 = 0x2130;
          }
          param_1->state = iVar3;
          param_1->init_num = 0;
          if (uVar9 == 0) {
            psVar13 = param_1->s3;
            uVar2 = uVar9;
            goto LAB_00057440;
          }
          psVar13 = param_1->s3;
          uVar8 = *(undefined4 *)(psVar13->read_sequence + 4);
          *(undefined4 *)psVar13->write_sequence = *(undefined4 *)psVar13->read_sequence;
          *(undefined4 *)(psVar13->write_sequence + 4) = uVar8;
          if (param_1->state != 0x2130) goto LAB_000574a4;
          pdVar15 = param_1->d1;
          iVar3 = 2;
          pdVar15->mtu = 0;
          pdVar15->handshake_read_seq = 2;
          pdVar15->handshake_write_seq = 1;
          pdVar15->next_handshake_write_seq = 1;
        }
        goto LAB_00057386;
      }
      if (0x2114 < iVar6) goto LAB_00057700;
      if (iVar6 == 0x2113) {
        pcVar17 = param_1->init_buf->data;
        pcVar17[0xc] = (char)((uint)param_1->version >> 8);
        pcVar17[0xd] = (char)param_1->version;
        if ((*(code **)(param_1->psk_server_callback + 0x78) == (code *)0x0) ||
           (iVar3 = (**(code **)(param_1->psk_server_callback + 0x78))
                              (param_1,param_1->d1->cookie,&param_1->d1->cookie_len), iVar3 == 0)) {
          iVar3 = 0;
          ERR_put_error(0x14,0x108,0x44,"d1_srvr.c",0x3b9);
          param_1->state = 5;
          goto LAB_00057386;
        }
        pcVar17[0xe] = (char)param_1->d1->cookie_len;
        pvVar4 = memcpy(pcVar17 + 0xf,param_1->d1->cookie,param_1->d1->cookie_len);
        uVar2 = param_1->d1->cookie_len;
        iVar3 = (int)pvVar4 + (uVar2 - (int)(pcVar17 + 0xc));
        dtls1_set_message_header(param_1,pcVar17,3,iVar3,0,iVar3);
        param_1->init_off = 0;
        param_1->state = 0x2114;
        param_1->init_num = (int)pvVar4 + (uVar2 - (int)pcVar17);
      }
      iVar3 = dtls1_do_write(param_1,0x16);
      if (iVar3 < 1) goto LAB_00057386;
      uVar2 = param_1->version;
      psVar13 = param_1->s3;
      bVar19 = uVar2 == 0x100;
      param_1->state = 0x2100;
      if (bVar19) {
        uVar2 = 0;
      }
      (psVar13->tmp).next_state = 0x2110;
      if (bVar19) goto LAB_00057440;
      ssl3_init_finished_mac(param_1);
      uVar2 = (param_1->s3->tmp).reuse_message;
      goto joined_r0x000572a2;
    }
    if (0x2141 < iVar6) {
      if (0x214f < iVar6) {
        if (0x2151 < iVar6) {
          if (1 < iVar6 - 0x2160U) goto LAB_00057700;
          iVar3 = param_1->verify_mode;
          if ((iVar3 << 0x1f < 0) &&
             ((*(int *)(param_1->session->krb5_client_princ + 0xc) == 0 || (-1 < iVar3 << 0x1d)))) {
            psVar13 = param_1->s3;
            pSVar11 = (psVar13->tmp).new_cipher;
            uVar7 = pSVar11->algorithm_auth;
            if (((-1 < (int)(uVar7 << 0x1d)) || (iVar3 << 0x1e < 0)) &&
               ((-1 < (int)(uVar7 << 0x1a) && (uVar2 = pSVar11->algorithm_mkey & 0x100, uVar2 == 0))
               )) {
              (psVar13->tmp).cert_request = 1;
              dtls1_start_timer(param_1);
              iVar3 = dtls1_send_certificate_request(param_1);
              if (0 < iVar3) {
                param_1->init_num = 0;
                psVar13 = param_1->s3;
                param_1->state = 0x2170;
                goto LAB_00057440;
              }
              goto LAB_00057386;
            }
          }
          else {
            psVar13 = param_1->s3;
          }
          (psVar13->tmp).cert_request = 0;
          uVar2 = 1;
          param_1->state = 0x2170;
          goto LAB_00057440;
        }
        psVar13 = param_1->s3;
        pSVar11 = (psVar13->tmp).new_cipher;
        uVar2 = pSVar11->algorithm_mkey;
        (psVar13->tmp).use_rsa_tmp = 0;
        if ((((int)(uVar2 << 0x17) < 0) && (*(int *)(param_1->psk_server_callback + 0x14c) != 0)) ||
           ((uVar2 & 0x88) != 0)) {
LAB_000576bc:
          dtls1_start_timer(param_1);
          iVar3 = dtls1_send_server_key_exchange(param_1);
          if (iVar3 < 1) goto LAB_00057386;
          psVar13 = param_1->s3;
          uVar2 = 0;
        }
        else {
          if ((int)(uVar2 << 0x1f) < 0) {
            if (*(EVP_PKEY **)(param_1->cert + 0x34) == (EVP_PKEY *)0x0) goto LAB_000576bc;
            if ((int)(pSVar11->algo_strength << 0x1e) < 0) {
              iVar3 = EVP_PKEY_size(*(EVP_PKEY **)(param_1->cert + 0x34));
              psVar13 = param_1->s3;
              if ((((psVar13->tmp).new_cipher)->algo_strength & 8) == 0) {
                iVar12 = 0x400;
              }
              else {
                iVar12 = 0x200;
              }
              if (iVar12 + iVar3 * -8 < 0 != SBORROW4(iVar12,iVar3 * 8)) goto LAB_000576bc;
            }
          }
          uVar2 = 1;
        }
        param_1->init_num = 0;
        param_1->state = 0x2160;
        goto LAB_00057440;
      }
LAB_00057700:
      iVar3 = -1;
      ERR_put_error(0x14,0xf6,0xff,"d1_srvr.c",0x36b);
      goto LAB_00057386;
    }
    if (0x213f < iVar6) {
      psVar13 = param_1->s3;
      pSVar11 = (psVar13->tmp).new_cipher;
      if (((int)(pSVar11->algorithm_auth << 0x1d) < 0) ||
         ((int)(pSVar11->algorithm_mkey << 0x17) < 0)) {
        uVar2 = 1;
        param_1->state = 0x2150;
      }
      else {
        dtls1_start_timer(param_1);
        if (param_1->state == 0x2140) {
          iVar3 = ssl_get_server_send_cert(param_1);
          if ((iVar3 == 0) &&
             ((pSVar11 = (param_1->s3->tmp).new_cipher, pSVar11->algorithm_mkey != 0x10 ||
              (pSVar11->algorithm_auth != 0x20)))) {
            iVar6 = 0x65f;
          }
          else {
            iVar3 = dtls1_output_cert_chain(param_1,iVar3);
            if (iVar3 != 0) {
              param_1->init_num = iVar3;
              param_1->init_off = 0;
              param_1->state = 0x2141;
              dtls1_buffer_message(param_1,0);
              goto LAB_00057914;
            }
            iVar6 = 0x666;
          }
          iVar3 = 0;
          ERR_put_error(0x14,0x109,0x44,"d1_srvr.c",iVar6);
          goto LAB_00057386;
        }
LAB_00057914:
        iVar3 = dtls1_do_write(param_1,0x16);
        if (iVar3 < 1) goto LAB_00057386;
        uVar2 = param_1->tlsext_status_type;
        if (uVar2 == 0) {
          psVar13 = param_1->s3;
          param_1->state = 0x2150;
        }
        else {
          psVar13 = param_1->s3;
          param_1->state = 0x2200;
          uVar2 = 0;
        }
      }
      param_1->init_num = 0;
      goto LAB_00057440;
    }
    if (iVar6 != 0x2122) {
      if (1 < iVar6 - 0x2130U) goto LAB_00057700;
      param_1->tlsext_hb_seq = 2;
      dtls1_start_timer(param_1);
      iVar3 = dtls1_send_server_hello(param_1);
      if (0 < iVar3) {
        if (param_1->hit == 0) {
          param_1->state = 0x2140;
        }
        else {
LAB_000578c2:
          if (param_1->tlsext_ocsp_resplen == 0) {
            param_1->state = 0x21d0;
          }
          else {
            param_1->state = 0x21f0;
          }
        }
LAB_000574a0:
        param_1->init_num = 0;
LAB_000574a4:
        uVar2 = 0;
        psVar13 = param_1->s3;
        goto LAB_00057440;
      }
      goto LAB_00057386;
    }
    psVar13 = param_1->s3;
    param_1->state = 3;
    uVar2 = 0;
  }
  else if (iVar6 < 0x21d2) {
    if (0x21cf < iVar6) {
      pSVar14 = param_1->method;
      *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) = (param_1->s3->tmp).new_cipher;
      iVar3 = (**(code **)(pSVar14->ssl3_enc + 8))(param_1);
      if (iVar3 != 0) {
        iVar3 = dtls1_send_change_cipher_spec(param_1,0x21d0,0x21d1);
        if (0 < iVar3) {
          param_1->init_num = 0;
          param_1->state = 0x21e0;
          iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
          if (iVar3 != 0) {
            dtls1_reset_seq_numbers(param_1,2);
            psVar13 = param_1->s3;
            uVar2 = 0;
            goto LAB_00057440;
          }
          goto LAB_00057b52;
        }
        goto LAB_00057386;
      }
LAB_00057b52:
      iVar3 = -1;
      param_1->state = 5;
      goto LAB_00057386;
    }
    if (0x2191 < iVar6) {
      if (0x219f < iVar6) {
        if (iVar6 < 0x21a2) {
          iVar3 = ssl3_get_cert_verify(param_1);
          if (0 < iVar3) {
            param_1->init_num = 0;
            psVar13 = param_1->s3;
            uVar2 = 0;
            param_1->state = 0x21c0;
            goto LAB_00057440;
          }
        }
        else {
          if (1 < iVar6 - 0x21c0U) goto LAB_00057700;
          if (param_1->s3->change_cipher_spec == 0) {
            param_1->d1[1].send_cookie = 1;
          }
          iVar3 = ssl3_get_finished(param_1,0x21c0,0x21c1);
          if (0 < iVar3) {
            dtls1_stop_timer(param_1);
            if (param_1->hit == 0) goto LAB_000578c2;
            param_1->state = 3;
            goto LAB_000574a0;
          }
        }
        goto LAB_00057386;
      }
      goto LAB_00057700;
    }
    if (iVar6 < 0x2190) {
      if (1 < iVar6 - 0x2180U) goto LAB_00057700;
      iVar3 = ssl3_check_client_hello(param_1);
      if (iVar3 < 1) goto LAB_00057386;
      if (iVar3 == 2) {
        dtls1_stop_timer(param_1);
        psVar13 = param_1->s3;
        uVar2 = 0;
        param_1->state = 0x2112;
      }
      else {
        psVar13 = param_1->s3;
        if ((psVar13->tmp).cert_request != 0) {
          iVar3 = ssl3_get_client_certificate(param_1);
          if (iVar3 < 1) goto LAB_00057386;
          psVar13 = param_1->s3;
        }
        param_1->init_num = 0;
        uVar2 = 0;
        param_1->state = 0x2190;
      }
    }
    else {
      iVar3 = ssl3_get_client_key_exchange(param_1);
      if (iVar3 < 1) goto LAB_00057386;
      param_1->init_num = 0;
      param_1->state = 0x21a0;
      if (iVar3 == 2) {
        psVar13 = param_1->s3;
        param_1->state = 0x21c0;
        uVar2 = 0;
      }
      else {
        (**(code **)(param_1->method->ssl3_enc + 0x1c))(param_1,4,&param_1->s3->tmp);
        (**(code **)(param_1->method->ssl3_enc + 0x1c))
                  (param_1,0x40,(param_1->s3->tmp).cert_verify_md + 0x10);
        psVar13 = param_1->s3;
        uVar2 = 0;
      }
    }
  }
  else if (iVar6 < 0x2202) {
    if (iVar6 < 0x2200) {
      if (iVar6 < 0x21e0) goto LAB_00057700;
      if (iVar6 < 0x21e2) {
        psVar18 = param_1->method->ssl3_enc;
        iVar3 = dtls1_send_finished(param_1,0x21e0,0x21e1,*(undefined4 *)(psVar18 + 0x28),
                                    *(undefined4 *)(psVar18 + 0x2c));
        if (iVar3 < 1) goto LAB_00057386;
        param_1->state = 0x2100;
        if (param_1->hit == 0) {
          psVar13 = param_1->s3;
          (psVar13->tmp).next_state = 3;
        }
        else {
          psVar13 = param_1->s3;
          (psVar13->tmp).next_state = 0x21c0;
        }
        param_1->init_num = 0;
        uVar2 = 0;
      }
      else {
        if (1 < iVar6 - 0x21f0U) goto LAB_00057700;
        iVar3 = dtls1_send_newsession_ticket(param_1);
        if (iVar3 < 1) goto LAB_00057386;
        psVar13 = param_1->s3;
        uVar2 = 0;
        param_1->init_num = 0;
        param_1->state = 0x21d0;
      }
    }
    else {
      iVar3 = ssl3_send_cert_status(param_1);
      if (iVar3 < 1) goto LAB_00057386;
      param_1->init_num = 0;
      psVar13 = param_1->s3;
      uVar2 = 0;
      param_1->state = 0x2150;
    }
  }
  else {
    if ((iVar6 != 0x4000) && (iVar6 != 0x6000)) {
      if (iVar6 != 0x3004) goto LAB_00057700;
      param_1->tlsext_hb_seq = 1;
    }
LAB_00057596:
    param_1->server = 1;
    if (p_Var16 != (_func_3152 *)0x0) {
      (*p_Var16)(param_1,0x10,1);
    }
    if ((param_1->version & 0xff00U) != 0xfe00) {
      ERR_put_error(0x14,0xf6,0x44,"d1_srvr.c",0xdb);
      return -1;
    }
    param_1->type = 0x2000;
    if (param_1->init_buf == (BUF_MEM *)0x0) {
      str = BUF_MEM_new();
      if (str == (BUF_MEM *)0x0) goto LAB_00057b52;
      iVar3 = BUF_MEM_grow(str,0x4000);
      if (iVar3 == 0) {
        iVar3 = -1;
        BUF_MEM_free(str);
        param_1->state = 5;
        goto LAB_00057386;
      }
      param_1->init_buf = str;
    }
    iVar3 = ssl3_setup_buffers(param_1);
    if (iVar3 == 0) goto LAB_00057b52;
    iVar3 = param_1->state;
    psVar13 = param_1->s3;
    param_1->init_num = 0;
    param_1->d1[1].send_cookie = 0;
    psVar13->change_cipher_spec = 0;
    if (iVar3 == 0x3004) {
      if ((psVar13->send_connection_binding == 0) && (-1 < param_1->references << 0xd)) {
        iVar3 = -1;
        ERR_put_error(0x14,0xf6,0x152,"d1_srvr.c",0x116);
        ssl3_send_alert(param_1,2,0x28);
        param_1->state = 5;
        goto LAB_00057386;
      }
      uVar2 = 0;
      *(int *)(param_1->psk_server_callback + 0x44) =
           *(int *)(param_1->psk_server_callback + 0x44) + 1;
      param_1->state = 0x2120;
    }
    else {
      iVar3 = ssl_init_wbio_buffer(param_1,1);
      if (iVar3 == 0) goto LAB_00057b52;
      ssl3_init_finished_mac(param_1);
      uVar2 = 0;
      param_1->state = 0x2110;
      psVar13 = param_1->s3;
      *(int *)(param_1->psk_server_callback + 0x40) =
           *(int *)(param_1->psk_server_callback + 0x40) + 1;
    }
  }
LAB_00057440:
  uVar2 = uVar2 | (psVar13->tmp).reuse_message;
joined_r0x000572a2:
  if (uVar2 == 0) {
    if ((param_1->ctx != (SSL_CTX *)0x0) &&
       (iVar3 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar3 < 1)) goto LAB_00057386;
    if (p_Var16 == (_func_3152 *)0x0) {
      iVar3 = param_1->state;
    }
    else {
      iVar3 = param_1->state;
      if (iVar6 != iVar3) {
        param_1->state = iVar6;
        (*p_Var16)(param_1,0x2001,1);
        param_1->state = iVar3;
      }
    }
  }
  else {
    iVar3 = param_1->state;
  }
  goto LAB_00057214;
}

