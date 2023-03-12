
int dtls1_accept(SSL *param_1)

{
  char *__dest;
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  ssl3_enc_method *psVar4;
  SSL_CIPHER *pSVar5;
  undefined4 uVar6;
  dtls1_state_st *pdVar7;
  int *piVar8;
  uint uVar9;
  int val;
  ssl3_state_st *psVar10;
  long lVar11;
  int iVar12;
  BUF_MEM *str;
  _func_3152 *p_Var13;
  int in_GS_OFFSET;
  bool bVar14;
  int iVar15;
  time_t local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = time((time_t *)0x0);
  RAND_add(&local_24,4,0.0);
  ERR_clear_error();
  piVar8 = __errno_location();
  p_Var13 = param_1->info_callback;
  *piVar8 = 0;
  if (p_Var13 == (_func_3152 *)0x0) {
    p_Var13 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  uVar1 = param_1->d1->mtu;
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar9 = SSL_state(param_1);
  if (((uVar9 & 0x3000) == 0) || (uVar9 = SSL_state(param_1), (uVar9 & 0x4000) != 0)) {
    SSL_clear(param_1);
  }
  param_1->d1->mtu = uVar1;
  if (param_1->cert == (cert_st *)0x0) {
    iVar12 = 0xb9;
    iVar15 = 0xb3;
LAB_080b5a71:
    val = -1;
    ERR_put_error(0x14,0xf6,iVar15,"d1_srvr.c",iVar12);
  }
  else {
    if (param_1->tlsext_heartbeat != 0) {
      dtls1_stop_timer(param_1);
      param_1->tlsext_heartbeat = 0;
      param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
    }
LAB_080b4c40:
    iVar15 = param_1->state;
    if (0x2171 < iVar15) goto LAB_080b4d58;
    while (iVar15 < 0x2170) {
      if (0x2121 < iVar15) {
        if (0x2141 < iVar15) {
          if (0x214f < iVar15) {
            if (iVar15 < 0x2152) {
              psVar10 = param_1->s3;
              pSVar5 = (psVar10->tmp).new_cipher;
              uVar9 = pSVar5->algorithm_mkey;
              bVar14 = (param_1->references & 0x200000U) != 0;
              (psVar10->tmp).use_rsa_tmp = (uint)bVar14;
              if ((bVar14) ||
                 ((((uVar9 & 0x100) != 0 && (*(int *)(param_1->psk_server_callback + 0x14c) != 0))
                  || ((uVar9 & 0x8e) != 0)))) {
LAB_080b53b0:
                dtls1_start_timer(param_1);
                val = dtls1_send_server_key_exchange(param_1);
                if (val < 1) goto LAB_080b4e60;
                psVar10 = param_1->s3;
                uVar9 = 0;
              }
              else if ((uVar9 & 1) == 0) {
                uVar9 = 1;
              }
              else {
                if (*(EVP_PKEY **)(param_1->cert + 0x34) == (EVP_PKEY *)0x0) goto LAB_080b53b0;
                uVar9 = 1;
                if ((*(byte *)&pSVar5->algo_strength & 2) != 0) {
                  iVar12 = EVP_PKEY_size(*(EVP_PKEY **)(param_1->cert + 0x34));
                  psVar10 = param_1->s3;
                  if ((int)((-(uint)((((psVar10->tmp).new_cipher)->algo_strength & 8) == 0) & 0x200)
                           + 0x200) < iVar12 * 8) goto LAB_080b53b0;
                }
              }
              param_1->state = 0x2160;
LAB_080b56ad:
              param_1->init_num = 0;
              goto LAB_080b4f90;
            }
            if (iVar15 - 0x2160U < 2) {
              uVar9 = param_1->verify_mode;
              if (((uVar9 & 1) == 0) ||
                 ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 && ((uVar9 & 4) != 0))))
              {
                psVar10 = param_1->s3;
LAB_080b56c3:
                (psVar10->tmp).cert_request = 0;
                uVar9 = 1;
                param_1->state = 0x2170;
                goto LAB_080b4f90;
              }
              psVar10 = param_1->s3;
              pSVar5 = (psVar10->tmp).new_cipher;
              uVar3 = pSVar5->algorithm_auth;
              if ((((uVar3 & 4) != 0) && ((uVar9 & 2) == 0)) ||
                 (((uVar3 & 0x20) != 0 || ((*(byte *)((int)&pSVar5->algorithm_mkey + 1) & 1) != 0)))
                 ) goto LAB_080b56c3;
              (psVar10->tmp).cert_request = 1;
              dtls1_start_timer(param_1);
              val = dtls1_send_certificate_request(param_1);
              if (0 < val) {
                param_1->state = 0x2170;
                goto LAB_080b4f10;
              }
              goto LAB_080b4e60;
            }
          }
          goto LAB_080b5400;
        }
        if (iVar15 < 0x2140) {
          if (iVar15 == 0x2122) {
            param_1->state = 3;
            psVar10 = param_1->s3;
            uVar9 = 0;
            goto LAB_080b4f90;
          }
          if (1 < iVar15 - 0x2130U) goto LAB_080b5400;
          param_1->tlsext_hb_seq = 2;
          dtls1_start_timer(param_1);
          val = dtls1_send_server_hello(param_1);
          if (0 < val) {
            if (param_1->hit != 0) goto LAB_080b4efc;
            param_1->state = 0x2140;
            goto LAB_080b4f10;
          }
        }
        else {
          psVar10 = param_1->s3;
          pSVar5 = (psVar10->tmp).new_cipher;
          if (((*(byte *)&pSVar5->algorithm_auth & 4) != 0) ||
             ((*(byte *)((int)&pSVar5->algorithm_mkey + 1) & 1) != 0)) {
            param_1->state = 0x2150;
            uVar9 = 1;
            goto LAB_080b56ad;
          }
          dtls1_start_timer(param_1);
          if (param_1->state == 0x2140) {
            iVar12 = ssl_get_server_send_cert(param_1);
            if ((iVar12 == 0) &&
               ((pSVar5 = (param_1->s3->tmp).new_cipher, pSVar5->algorithm_mkey != 0x10 ||
                (pSVar5->algorithm_auth != 0x20)))) {
              ERR_put_error(0x14,0x109,0x44,"d1_srvr.c",0x63a);
              val = 0;
              goto LAB_080b4e60;
            }
            iVar12 = dtls1_output_cert_chain(param_1,iVar12);
            param_1->state = 0x2141;
            param_1->init_num = iVar12;
            param_1->init_off = 0;
            dtls1_buffer_message(param_1,0);
          }
          val = dtls1_do_write(param_1,0x16);
          if (0 < val) {
            if (param_1->tlsext_status_type == 0) {
              param_1->state = 0x2150;
              psVar10 = param_1->s3;
              uVar9 = 0;
            }
            else {
              param_1->state = 0x2200;
              psVar10 = param_1->s3;
              uVar9 = 0;
            }
            goto LAB_080b56ad;
          }
        }
        goto LAB_080b4e60;
      }
      if (0x211f < iVar15) {
        param_1->shutdown = 0;
        dtls1_clear_record_buffer(param_1);
        dtls1_start_timer(param_1);
        if (param_1->state == 0x2120) {
          dtls1_set_message_header(param_1,param_1->init_buf->data,0,0,0,0);
          param_1->state = 0x2121;
          param_1->init_num = 0xc;
          param_1->init_off = 0;
        }
        val = dtls1_do_write(param_1,0x16);
        if (0 < val) {
          uVar9 = 0;
          (param_1->s3->tmp).next_state = 0x2110;
          param_1->state = 0x2100;
          param_1->init_num = 0;
          ssl3_init_finished_mac(param_1);
          psVar10 = param_1->s3;
          goto LAB_080b4f90;
        }
        goto LAB_080b4e60;
      }
      if (iVar15 == 0x2100) {
        param_1->rwstate = 2;
        lVar11 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar11) {
          psVar10 = param_1->s3;
          param_1->rwstate = 1;
          uVar9 = 0;
          param_1->state = (psVar10->tmp).next_state;
          goto LAB_080b4f90;
        }
        iVar15 = BIO_test_flags(param_1->wbio,8);
        if (iVar15 == 0) {
          param_1->rwstate = 1;
          param_1->state = (param_1->s3->tmp).next_state;
          val = -1;
        }
        else {
LAB_080b59cd:
          val = -1;
        }
        goto LAB_080b4e60;
      }
      if (iVar15 < 0x2101) {
        if (iVar15 == 0x2000) goto LAB_080b516e;
        if (iVar15 == 0x2003) goto LAB_080b516e;
        if (iVar15 != 3) goto LAB_080b5400;
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
          if (p_Var13 != (_func_3152 *)0x0) {
            (*p_Var13)(param_1,0x20,1);
          }
        }
        pdVar7 = param_1->d1;
        pdVar7->handshake_read_seq = 0;
        pdVar7->handshake_write_seq = 0;
        pdVar7->next_handshake_write_seq = 0;
        val = 1;
        goto LAB_080b4e60;
      }
      if (iVar15 < 0x2110) {
LAB_080b5400:
        ERR_put_error(0x14,0xf6,0xff,"d1_srvr.c",0x333);
        val = -1;
        goto LAB_080b4e60;
      }
      if (iVar15 < 0x2113) {
        param_1->shutdown = 0;
        val = ssl3_get_client_hello(param_1);
        if (0 < val) {
          dtls1_stop_timer(param_1);
          if ((val == 1) && (uVar9 = SSL_ctrl(param_1,0x20,0,(void *)0x0), (uVar9 & 0x2000) != 0)) {
            iVar12 = 0x2113;
          }
          else {
            iVar12 = 0x2130;
          }
          param_1->state = iVar12;
          param_1->init_num = 0;
          if (uVar1 == 0) {
LAB_080b52c3:
            psVar10 = param_1->s3;
            uVar9 = 0;
            goto LAB_080b4f90;
          }
          psVar10 = param_1->s3;
          uVar6 = *(undefined4 *)(psVar10->read_sequence + 4);
          *(undefined4 *)psVar10->write_sequence = *(undefined4 *)psVar10->read_sequence;
          *(undefined4 *)(psVar10->write_sequence + 4) = uVar6;
          if (param_1->state != 0x2130) goto LAB_080b52c3;
          pdVar7 = param_1->d1;
          pdVar7->mtu = 0;
          pdVar7->handshake_read_seq = 2;
          pdVar7->handshake_write_seq = 1;
          pdVar7->next_handshake_write_seq = 1;
          val = 2;
        }
        goto LAB_080b4e60;
      }
      if (0x2114 < iVar15) goto LAB_080b5400;
      if (iVar15 == 0x2113) {
        pcVar2 = param_1->init_buf->data;
        pcVar2[0xc] = (char)((uint)param_1->version >> 8);
        pcVar2[0xd] = (char)param_1->version;
        if ((*(code **)(param_1->psk_server_callback + 0x78) == (code *)0x0) ||
           (iVar12 = (**(code **)(param_1->psk_server_callback + 0x78))
                               (param_1,param_1->d1->cookie,&param_1->d1->cookie_len), iVar12 == 0))
        {
          ERR_put_error(0x14,0x108,0x44,"d1_srvr.c",900);
          val = 0;
          goto LAB_080b4e60;
        }
        __dest = pcVar2 + 0xf;
        pcVar2[0xe] = (char)param_1->d1->cookie_len;
        memcpy(__dest,param_1->d1->cookie,param_1->d1->cookie_len);
        uVar9 = param_1->d1->cookie_len;
        dtls1_set_message_header
                  (param_1,pcVar2,3,__dest + (uVar9 - (int)(pcVar2 + 0xc)),0,
                   __dest + (uVar9 - (int)(pcVar2 + 0xc)));
        param_1->state = 0x2114;
        param_1->init_off = 0;
        param_1->init_num = (int)(__dest + (uVar9 - (int)pcVar2));
      }
      val = dtls1_do_write(param_1,0x16);
      if (val < 1) goto LAB_080b4e60;
      uVar9 = 0;
      iVar12 = param_1->version;
      psVar10 = param_1->s3;
      param_1->state = 0x2100;
      (psVar10->tmp).next_state = 0x2110;
      if (iVar12 == 0x100) goto LAB_080b4f90;
      ssl3_init_finished_mac(param_1);
      uVar9 = (param_1->s3->tmp).reuse_message;
      iVar12 = iVar15;
      while( true ) {
        if (uVar9 != 0) goto LAB_080b4c40;
        if ((param_1->ctx != (SSL_CTX *)0x0) &&
           (val = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), val < 1)) goto LAB_080b4e60;
        if (p_Var13 == (_func_3152 *)0x0) {
          iVar15 = param_1->state;
        }
        else {
          iVar15 = param_1->state;
          if (iVar15 != iVar12) {
            param_1->state = iVar12;
            (*p_Var13)(param_1,0x2001,1);
            param_1->state = iVar15;
          }
        }
        if (iVar15 < 0x2172) break;
LAB_080b4d58:
        if (iVar15 < 0x21d2) {
          if (iVar15 < 0x21d0) {
            if (iVar15 < 0x2192) {
              if (iVar15 < 0x2190) {
                if (1 < iVar15 - 0x2180U) goto LAB_080b5400;
                val = ssl3_check_client_hello(param_1);
                if (val < 1) goto LAB_080b4e60;
                if (val == 2) {
                  uVar9 = 0;
                  dtls1_stop_timer(param_1);
                  param_1->state = 0x2112;
                  psVar10 = param_1->s3;
                }
                else {
                  val = ssl3_get_client_certificate(param_1);
                  if (val < 1) goto LAB_080b4e60;
                  param_1->init_num = 0;
                  param_1->state = 0x2190;
                  uVar9 = 0;
                  psVar10 = param_1->s3;
                }
              }
              else {
                val = ssl3_get_client_key_exchange(param_1);
                if (val < 1) goto LAB_080b4e60;
                param_1->state = 0x21a0;
                param_1->init_num = 0;
                if (val == 2) {
                  param_1->state = 0x21c0;
                  psVar10 = param_1->s3;
                  uVar9 = 0;
                }
                else {
                  uVar9 = 0;
                  (**(code **)(param_1->method->ssl3_enc + 0x1c))(param_1,4,&param_1->s3->tmp);
                  (**(code **)(param_1->method->ssl3_enc + 0x1c))
                            (param_1,0x40,(param_1->s3->tmp).cert_verify_md + 0x10);
                  psVar10 = param_1->s3;
                }
              }
            }
            else {
              if (iVar15 < 0x21a0) goto LAB_080b5400;
              if (iVar15 < 0x21a2) {
                param_1->d1->listen = 1;
                val = ssl3_get_cert_verify(param_1);
                if (val < 1) goto LAB_080b4e60;
                param_1->state = 0x21c0;
                param_1->init_num = 0;
                uVar9 = 0;
                psVar10 = param_1->s3;
              }
              else {
                if (1 < iVar15 - 0x21c0U) goto LAB_080b5400;
                param_1->d1->listen = 1;
                val = ssl3_get_finished(param_1,0x21c0,0x21c1);
                if (val < 1) goto LAB_080b4e60;
                dtls1_stop_timer(param_1);
                if (param_1->hit == 0) {
LAB_080b4efc:
                  param_1->state =
                       (-(uint)(param_1->tlsext_ocsp_resplen == 0) & 0xffffffe0) + 0x21f0;
                }
                else {
                  param_1->state = 3;
                }
LAB_080b4f10:
                param_1->init_num = 0;
                psVar10 = param_1->s3;
                uVar9 = 0;
              }
            }
          }
          else {
            *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) =
                 (param_1->s3->tmp).new_cipher;
            iVar12 = (**(code **)(param_1->method->ssl3_enc + 8))(param_1);
            if (iVar12 == 0) goto LAB_080b59cd;
            val = dtls1_send_change_cipher_spec(param_1,0x21d0,0x21d1);
            if (val < 1) goto LAB_080b4e60;
            param_1->state = 0x21e0;
            param_1->init_num = 0;
            iVar12 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
            if (iVar12 == 0) goto LAB_080b59cd;
            uVar9 = 0;
            dtls1_reset_seq_numbers(param_1,2);
            psVar10 = param_1->s3;
          }
        }
        else if (iVar15 < 0x2202) {
          if (iVar15 < 0x2200) {
            if (iVar15 < 0x21e0) goto LAB_080b5400;
            if (iVar15 < 0x21e2) {
              psVar4 = param_1->method->ssl3_enc;
              val = dtls1_send_finished(param_1,0x21e0,0x21e1,*(undefined4 *)(psVar4 + 0x28),
                                        *(undefined4 *)(psVar4 + 0x2c));
              if (val < 1) goto LAB_080b4e60;
              param_1->state = 0x2100;
              psVar10 = param_1->s3;
              if (param_1->hit == 0) {
                (psVar10->tmp).next_state = 3;
              }
              else {
                (psVar10->tmp).next_state = 0x21c0;
              }
              param_1->init_num = 0;
              uVar9 = 0;
            }
            else {
              if (1 < iVar15 - 0x21f0U) goto LAB_080b5400;
              val = dtls1_send_newsession_ticket(param_1);
              if (val < 1) goto LAB_080b4e60;
              psVar10 = param_1->s3;
              param_1->state = 0x21d0;
              uVar9 = 0;
              param_1->init_num = 0;
            }
          }
          else {
            val = ssl3_send_cert_status(param_1);
            if (val < 1) goto LAB_080b4e60;
            param_1->state = 0x2150;
            param_1->init_num = 0;
            uVar9 = 0;
            psVar10 = param_1->s3;
          }
        }
        else {
          if ((iVar15 != 0x4000) && (iVar15 != 0x6000)) {
            if (iVar15 != 0x3004) goto LAB_080b5400;
            param_1->tlsext_hb_seq = 1;
          }
LAB_080b516e:
          param_1->server = 1;
          if (p_Var13 != (_func_3152 *)0x0) {
            (*p_Var13)(param_1,0x10,1);
          }
          if ((param_1->version & 0xff00U) != 0xfe00) {
            iVar12 = 0xde;
            iVar15 = 0x44;
            goto LAB_080b5a71;
          }
          param_1->type = 0x2000;
          if (param_1->init_buf == (BUF_MEM *)0x0) {
            str = BUF_MEM_new();
            if ((str == (BUF_MEM *)0x0) || (iVar12 = BUF_MEM_grow(str,0x4000), iVar12 == 0))
            goto LAB_080b59cd;
            param_1->init_buf = str;
          }
          iVar12 = ssl3_setup_buffers(param_1);
          if (iVar12 == 0) goto LAB_080b59cd;
          param_1->init_num = 0;
          if (param_1->state == 0x3004) {
            uVar9 = 0;
            *(int *)(param_1->psk_server_callback + 0x44) =
                 *(int *)(param_1->psk_server_callback + 0x44) + 1;
            param_1->state = 0x2120;
            psVar10 = param_1->s3;
          }
          else {
            iVar12 = ssl_init_wbio_buffer(param_1,1);
            if (iVar12 == 0) goto LAB_080b59cd;
            uVar9 = 0;
            ssl3_init_finished_mac(param_1);
            param_1->state = 0x2110;
            *(int *)(param_1->psk_server_callback + 0x40) =
                 *(int *)(param_1->psk_server_callback + 0x40) + 1;
            psVar10 = param_1->s3;
          }
        }
LAB_080b4f90:
        uVar9 = uVar9 | (psVar10->tmp).reuse_message;
        iVar12 = iVar15;
      }
    }
    dtls1_start_timer(param_1);
    if (param_1->state == 0x2170) {
      dtls1_set_message_header(param_1,param_1->init_buf->data,0xe,0,0,0);
      param_1->state = 0x2171;
      param_1->init_num = 0xc;
      param_1->init_off = 0;
      dtls1_buffer_message(param_1,0);
    }
    val = dtls1_do_write(param_1,0x16);
    if (0 < val) {
      psVar10 = param_1->s3;
      uVar9 = 0;
      (psVar10->tmp).next_state = 0x2180;
      param_1->state = 0x2100;
      param_1->init_num = 0;
      goto LAB_080b4f90;
    }
LAB_080b4e60:
    param_1->in_handshake = param_1->in_handshake + -1;
    if (p_Var13 != (_func_3152 *)0x0) {
      (*p_Var13)(param_1,0x2002,val);
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return val;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

