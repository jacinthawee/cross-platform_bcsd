
int dtls1_connect(SSL *param_1)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  BIO *pBVar5;
  long lVar6;
  BUF_MEM *str;
  SSL_METHOD *pSVar7;
  uint uVar8;
  int iVar9;
  SSL_CIPHER *pSVar10;
  SSL_COMP *pSVar11;
  _func_3154 *p_Var12;
  dtls1_state_st *pdVar13;
  ssl3_state_st *psVar14;
  SSL_SESSION *pSVar15;
  int iVar16;
  ssl3_enc_method *psVar17;
  _func_3152 *p_Var18;
  byte *pbVar19;
  bool bVar20;
  undefined4 in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  time_t local_30;
  int local_2c [2];
  
  local_30 = time((time_t *)0x0);
  RAND_add(&local_30,4,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
  ERR_clear_error();
  piVar2 = __errno_location();
  p_Var18 = param_1->info_callback;
  *piVar2 = 0;
  if (p_Var18 == (_func_3152 *)0x0) {
    p_Var18 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar3 = SSL_state(param_1);
  if (((uVar3 & 0x3000) == 0) || (iVar4 = SSL_state(param_1), iVar4 << 0x11 < 0)) {
    SSL_clear(param_1);
    uVar3 = param_1->tlsext_heartbeat;
  }
  else {
    uVar3 = param_1->tlsext_heartbeat;
  }
  if (uVar3 != 0) {
    dtls1_stop_timer(param_1);
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  iVar4 = param_1->state;
LAB_0005afc6:
  iVar16 = iVar4;
  if (iVar16 < 0x1174) {
    if (0x116f < iVar16) {
      dtls1_start_timer(param_1);
      iVar4 = dtls1_send_client_certificate(param_1);
      if (0 < iVar4) {
        param_1->init_num = 0;
        psVar14 = param_1->s3;
        uVar3 = 0;
        param_1->state = 0x1180;
        goto LAB_0005b356;
      }
      goto LAB_0005b15c;
    }
    if (iVar16 < 0x1128) {
      if (0x1125 < iVar16) {
        local_2c[0] = 0;
        iVar4 = (*param_1->method->ssl_get_message)(param_1,0x1126,0x1127,-1,param_1->mode,local_2c)
        ;
        if (local_2c[0] == 0) {
          if (iVar4 < 1) goto LAB_0005b15c;
        }
        else {
          psVar14 = param_1->s3;
          if ((psVar14->tmp).message_type == 3) {
            pbVar19 = (byte *)param_1->init_msg;
            if (((uint)*pbVar19 != param_1->version >> 8) ||
               ((uint)pbVar19[1] != (param_1->version & 0xffU))) {
              ERR_put_error(0x14,0xfb,0x10a,"d1_clnt.c",0x3a4);
              iVar4 = -1;
              param_1->version = param_1->version & 0xff00U | (uint)pbVar19[1];
              ssl3_send_alert(param_1,2,0x46);
              goto LAB_0005b15c;
            }
            bVar1 = pbVar19[2];
            memcpy(param_1->d1->cookie,pbVar19 + 3,(uint)bVar1);
            pdVar13 = param_1->d1;
            pdVar13->cookie_len = (uint)bVar1;
            pdVar13->send_cookie = 1;
          }
          else {
            param_1->d1->send_cookie = 0;
            (psVar14->tmp).reuse_message = 1;
          }
        }
        dtls1_stop_timer(param_1);
        uVar3 = 0;
        psVar14 = param_1->s3;
        uVar8 = param_1->d1->send_cookie;
        param_1->init_num = 0;
        if (uVar8 == 0) {
          iVar4 = 0x1130;
        }
        else {
          iVar4 = 0x1110;
        }
        param_1->state = iVar4;
        goto LAB_0005b356;
      }
      if (iVar16 == 0x1100) {
        param_1->rwstate = 2;
        lVar6 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar6) {
          psVar14 = param_1->s3;
          param_1->rwstate = 1;
          uVar3 = 0;
          param_1->state = (psVar14->tmp).next_state;
          goto LAB_0005b356;
        }
        iVar4 = BIO_test_flags(param_1->wbio,8);
        if (iVar4 != 0) goto LAB_0005b682;
        iVar4 = -1;
        param_1->rwstate = 1;
        param_1->state = (param_1->s3->tmp).next_state;
        goto LAB_0005b15c;
      }
      if (iVar16 < 0x1101) {
        if ((iVar16 == 0x1000) || (iVar16 == 0x1003)) goto LAB_0005b2e6;
        if (iVar16 == 3) {
          ssl3_cleanup_key_block(param_1);
          if (-1 < param_1->s3->flags << 0x1d) {
            ssl_free_wbio_buffer(param_1);
          }
          param_1->init_num = 0;
          param_1->tlsext_hb_seq = 0;
          param_1->new_session = 0;
          ssl_update_cache(param_1,1);
          if (param_1->hit == 0) {
            p_Var12 = param_1->psk_server_callback;
          }
          else {
            p_Var12 = param_1->psk_server_callback;
            *(int *)(p_Var12 + 0x58) = *(int *)(p_Var12 + 0x58) + 1;
          }
          iVar4 = *(int *)(p_Var12 + 0x3c);
          param_1->handshake_func = dtls1_connect;
          *(int *)(p_Var12 + 0x3c) = iVar4 + 1;
          if (p_Var18 != (_func_3152 *)0x0) {
            (*p_Var18)(param_1,0x20,1);
          }
          pdVar13 = param_1->d1;
          iVar4 = 1;
          pdVar13->handshake_read_seq = 0;
          pdVar13->next_handshake_write_seq = 0;
LAB_0005b15c:
          param_1->in_handshake = param_1->in_handshake + -1;
LAB_0005b162:
          if (p_Var18 != (_func_3152 *)0x0) {
            (*p_Var18)(param_1,0x1002,iVar4);
          }
          return iVar4;
        }
LAB_0005b42e:
        iVar4 = -1;
        ERR_put_error(0x14,0xf9,0xff,"d1_clnt.c",0x2e2);
        param_1->in_handshake = param_1->in_handshake + -1;
        goto LAB_0005b162;
      }
      if (iVar16 < 0x1110) goto LAB_0005b42e;
      if (iVar16 < 0x1112) {
        param_1->shutdown = 0;
        ssl3_init_finished_mac(param_1);
        dtls1_start_timer(param_1);
        iVar4 = dtls1_client_hello(param_1);
        if (0 < iVar4) {
          if (param_1->d1->send_cookie == 0) {
            param_1->state = 0x1120;
          }
          else {
            param_1->state = 0x1100;
            (param_1->s3->tmp).next_state = 0x1120;
          }
          param_1->init_num = 0;
          if (param_1->bbio == param_1->wbio) goto LAB_0005b52c;
          pBVar5 = BIO_push(param_1->bbio,param_1->wbio);
          psVar14 = param_1->s3;
          uVar3 = 0;
          param_1->wbio = pBVar5;
          goto LAB_0005b356;
        }
        goto LAB_0005b15c;
      }
      if (1 < iVar16 - 0x1120U) goto LAB_0005b42e;
      iVar4 = ssl3_get_server_hello(param_1);
      if (iVar4 < 1) goto LAB_0005b15c;
      iVar4 = 0x11d0;
      param_1->init_num = 0;
      uVar3 = (param_1->s3->tmp).reuse_message;
      if (param_1->hit == 0) {
        iVar4 = 0x1126;
      }
      param_1->state = iVar4;
      goto joined_r0x0005b036;
    }
    if (iVar16 < 0x1142) {
      if (iVar16 < 0x1140) {
        if (1 < iVar16 - 0x1130U) goto LAB_0005b42e;
        iVar4 = ssl3_check_finished(param_1);
        if (iVar4 < 1) goto LAB_0005b15c;
        if (iVar4 == 2) {
          param_1->hit = 1;
          if (param_1->tlsext_ocsp_resplen == 0) {
            iVar4 = 0x11d0;
          }
          else {
            iVar4 = 0x11e0;
          }
          param_1->init_num = 0;
          param_1->state = iVar4;
          uVar3 = 0;
          psVar14 = param_1->s3;
          goto LAB_0005b356;
        }
        psVar14 = param_1->s3;
        pSVar10 = (psVar14->tmp).new_cipher;
        if (((int)(pSVar10->algorithm_auth << 0x1d) < 0) ||
           ((int)(pSVar10->algorithm_mkey << 0x17) < 0)) {
          uVar3 = 1;
          param_1->state = 0x1140;
        }
        else {
          iVar4 = ssl3_get_server_certificate(param_1);
          if (iVar4 < 1) goto LAB_0005b15c;
          uVar3 = param_1->tlsext_status_type;
          if (uVar3 == 0) {
            psVar14 = param_1->s3;
            param_1->state = 0x1140;
          }
          else {
            psVar14 = param_1->s3;
            param_1->state = 0x11f0;
            uVar3 = 0;
          }
        }
        param_1->init_num = 0;
      }
      else {
        iVar4 = ssl3_get_key_exchange(param_1);
        if (iVar4 < 1) goto LAB_0005b15c;
        param_1->init_num = 0;
        param_1->state = 0x1150;
        iVar4 = ssl3_check_cert_and_algorithm(param_1);
        if (iVar4 == 0) goto LAB_0005b682;
LAB_0005b52c:
        psVar14 = param_1->s3;
        uVar3 = 0;
      }
    }
    else {
      if (iVar16 < 0x1150) goto LAB_0005b42e;
      if (iVar16 < 0x1152) {
        iVar4 = ssl3_get_certificate_request(param_1);
        if (iVar4 < 1) goto LAB_0005b15c;
        param_1->init_num = 0;
        psVar14 = param_1->s3;
        uVar3 = 0;
        param_1->state = 0x1160;
      }
      else {
        if (1 < iVar16 - 0x1160U) goto LAB_0005b42e;
        iVar4 = ssl3_get_server_done(param_1);
        if (iVar4 < 1) goto LAB_0005b15c;
        dtls1_stop_timer(param_1);
        psVar14 = param_1->s3;
        iVar4 = 0x1170;
        uVar3 = 0;
        if ((psVar14->tmp).cert_req == 0) {
          iVar4 = 0x1180;
        }
        (psVar14->tmp).next_state = iVar4;
        param_1->state = iVar4;
        param_1->init_num = 0;
      }
    }
  }
  else if (iVar16 < 0x11d2) {
    if (iVar16 < 0x11d0) {
      if (0x1191 < iVar16) {
        if (0x119f < iVar16) {
          if (iVar16 < 0x11a2) {
            if (param_1->hit == 0) {
              dtls1_start_timer(param_1);
            }
            iVar4 = dtls1_send_change_cipher_spec(param_1,0x11a0,0x11a1);
            if (0 < iVar4) {
              pSVar15 = param_1->session;
              param_1->init_num = 0;
              pSVar10 = (param_1->s3->tmp).new_cipher;
              pSVar11 = (param_1->s3->tmp).new_compression;
              param_1->state = 0x11b0;
              *(SSL_CIPHER **)(pSVar15->krb5_client_princ + 0x24) = pSVar10;
              if (pSVar11 != (SSL_COMP *)0x0) {
                pSVar11 = (SSL_COMP *)pSVar11->id;
              }
              pSVar7 = param_1->method;
              *(SSL_COMP **)(pSVar15->krb5_client_princ + 0x20) = pSVar11;
              iVar4 = (**(code **)(pSVar7->ssl3_enc + 8))(param_1);
              if ((iVar4 == 0) ||
                 (iVar4 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12), iVar4 == 0)
                 ) goto LAB_0005b682;
              dtls1_reset_seq_numbers(param_1,2);
              psVar14 = param_1->s3;
              uVar3 = 0;
              goto LAB_0005b356;
            }
          }
          else {
            if (1 < iVar16 - 0x11b0U) goto LAB_0005b42e;
            if (param_1->hit == 0) {
              dtls1_start_timer(param_1);
            }
            psVar17 = param_1->method->ssl3_enc;
            iVar4 = dtls1_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar17 + 0x20),
                                        *(undefined4 *)(psVar17 + 0x24));
            if (0 < iVar4) {
              psVar14 = param_1->s3;
              iVar4 = param_1->hit;
              param_1->state = 0x1100;
              uVar8 = psVar14->flags;
              uVar3 = uVar8 & 0xfffffffb;
              psVar14->flags = uVar3;
              if (iVar4 == 0) {
                if (param_1->tlsext_ocsp_resplen == 0) {
                  (psVar14->tmp).next_state = 0x11d0;
                }
                else {
                  (psVar14->tmp).next_state = 0x11e0;
                }
              }
              else {
                (psVar14->tmp).next_state = 3;
                if ((int)(uVar8 << 0x1e) < 0) {
                  param_1->state = 3;
                  psVar14->flags = uVar3 | 4;
                  psVar14->delay_buf_pop_ret = 0;
                }
              }
              goto LAB_0005b0e4;
            }
          }
          goto LAB_0005b15c;
        }
        goto LAB_0005b42e;
      }
      if (iVar16 < 0x1190) {
        if (1 < iVar16 - 0x1180U) goto LAB_0005b42e;
        dtls1_start_timer(param_1);
        iVar4 = dtls1_send_client_key_exchange(param_1);
        iVar9 = 0x1190;
        if (iVar4 < 1) goto LAB_0005b15c;
        psVar14 = param_1->s3;
        bVar20 = (psVar14->tmp).cert_req == 1;
        if (bVar20) {
          param_1->state = 0x1190;
        }
        else {
          iVar9 = 0x11a0;
        }
        if (!bVar20) {
          param_1->state = iVar9;
        }
        if (!bVar20) {
          psVar14->change_cipher_spec = 0;
        }
LAB_0005b0e4:
        param_1->init_num = 0;
        uVar3 = 0;
      }
      else {
        dtls1_start_timer(param_1);
        iVar4 = dtls1_send_client_verify(param_1);
        if (iVar4 < 1) goto LAB_0005b15c;
        psVar14 = param_1->s3;
        param_1->init_num = 0;
        uVar3 = 0;
        param_1->state = 0x11a0;
        psVar14->change_cipher_spec = 0;
      }
    }
    else {
      param_1->d1->listen = 1;
      iVar4 = ssl3_get_finished(param_1);
      if (iVar4 < 1) goto LAB_0005b15c;
      dtls1_stop_timer(param_1);
      uVar3 = 0;
      param_1->init_num = 0;
      if (param_1->hit == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 0x11a0;
      }
      psVar14 = param_1->s3;
      param_1->state = iVar4;
    }
  }
  else if (iVar16 < 0x11f2) {
    if (iVar16 < 0x11f0) {
      if (1 < iVar16 - 0x11e0U) goto LAB_0005b42e;
      iVar4 = ssl3_get_new_session_ticket(param_1);
      if (iVar4 < 1) goto LAB_0005b15c;
      param_1->init_num = 0;
      psVar14 = param_1->s3;
      uVar3 = 0;
      param_1->state = 0x11d0;
    }
    else {
      iVar4 = ssl3_get_cert_status(param_1);
      if (iVar4 < 1) goto LAB_0005b15c;
      param_1->init_num = 0;
      psVar14 = param_1->s3;
      uVar3 = 0;
      param_1->state = 0x1140;
    }
  }
  else {
    if ((iVar16 != 0x4000) && (iVar16 != 0x5000)) {
      if (iVar16 != 0x3004) goto LAB_0005b42e;
      param_1->tlsext_hb_seq = 1;
      param_1->state = 0x1000;
      *(int *)(param_1->psk_server_callback + 0x38) =
           *(int *)(param_1->psk_server_callback + 0x38) + 1;
    }
LAB_0005b2e6:
    param_1->server = 0;
    if (p_Var18 != (_func_3152 *)0x0) {
      (*p_Var18)(param_1,0x10,1);
    }
    uVar3 = param_1->version & 0xff00;
    if (uVar3 != 0x100 && uVar3 != 0xfe00) {
      iVar4 = -1;
      ERR_put_error(0x14,0xf9,0x44,"d1_clnt.c",0xd6);
      goto LAB_0005b15c;
    }
    param_1->type = 0x1000;
    if (param_1->init_buf == (BUF_MEM *)0x0) {
      str = BUF_MEM_new();
      if (str == (BUF_MEM *)0x0) goto LAB_0005b682;
      iVar4 = BUF_MEM_grow(str,0x4000);
      if (iVar4 == 0) {
        iVar4 = -1;
        param_1->in_handshake = param_1->in_handshake + -1;
        BUF_MEM_free(str);
        goto LAB_0005b162;
      }
      param_1->init_buf = str;
    }
    iVar4 = ssl3_setup_buffers(param_1);
    if ((iVar4 == 0) || (iVar4 = ssl_init_wbio_buffer(param_1,0), iVar4 == 0)) {
LAB_0005b682:
      iVar4 = -1;
      goto LAB_0005b15c;
    }
    psVar14 = param_1->s3;
    param_1->state = 0x1110;
    *(int *)(param_1->psk_server_callback + 0x34) =
         *(int *)(param_1->psk_server_callback + 0x34) + 1;
    param_1->init_num = 0;
    memset(psVar14->client_random,0,0x20);
    uVar3 = 0;
    psVar14 = param_1->s3;
    param_1->d1->send_cookie = 0;
    param_1->hit = 0;
  }
LAB_0005b356:
  uVar3 = uVar3 | (psVar14->tmp).reuse_message;
joined_r0x0005b036:
  if (uVar3 == 0) {
    if ((param_1->ctx != (SSL_CTX *)0x0) &&
       (iVar4 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar4 < 1)) goto LAB_0005b15c;
    if (p_Var18 == (_func_3152 *)0x0) {
      iVar4 = param_1->state;
    }
    else {
      iVar4 = param_1->state;
      if (iVar16 != iVar4) {
        param_1->state = iVar16;
        (*p_Var18)(param_1,0x1001,1);
        param_1->state = iVar4;
      }
    }
  }
  else {
    iVar4 = param_1->state;
  }
  goto LAB_0005afc6;
}

