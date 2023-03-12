
int dtls1_connect(SSL *param_1)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  BIO *pBVar5;
  long lVar6;
  BUF_MEM *str;
  int iVar7;
  BIO *append;
  SSL_METHOD *pSVar8;
  uint uVar9;
  _func_3154 *p_Var10;
  SSL_CIPHER *pSVar11;
  SSL_COMP *pSVar12;
  dtls1_state_st *pdVar13;
  SSL_SESSION *pSVar14;
  ssl3_state_st *psVar15;
  int iVar16;
  ssl3_enc_method *psVar17;
  byte *pbVar18;
  _func_3152 *p_Var19;
  undefined4 in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  time_t local_30;
  int local_2c [2];
  
  local_30 = time((time_t *)0x0);
  RAND_add(&local_30,4,(double)CONCAT44(in_stack_ffffffcc,in_stack_ffffffc8));
  ERR_clear_error();
  piVar2 = __errno_location();
  p_Var19 = param_1->info_callback;
  *piVar2 = 0;
  if (p_Var19 == (_func_3152 *)0x0) {
    p_Var19 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
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
LAB_000588e6:
  iVar7 = iVar4;
  if (iVar7 < 0x1174) {
    iVar16 = 0x1170;
    if (0x116f < iVar7) {
      dtls1_start_timer(param_1);
      iVar4 = dtls1_send_client_certificate(param_1);
      if (0 < iVar4) {
        param_1->init_num = 0;
        psVar15 = param_1->s3;
        uVar3 = 0;
        param_1->state = 0x1180;
        goto LAB_00058cb8;
      }
      goto LAB_00058aa0;
    }
    if (0x1127 < iVar7) {
      if (iVar7 < 0x1142) {
        if (0x113f < iVar7) {
          iVar4 = ssl3_get_key_exchange(param_1);
          if (0 < iVar4) {
            param_1->init_num = 0;
            param_1->state = 0x1150;
            iVar4 = ssl3_check_cert_and_algorithm(param_1);
            if (iVar4 == 0) goto LAB_00058dc8;
            goto LAB_00058d98;
          }
          goto LAB_00058aa0;
        }
        if (iVar7 - 0x1130U < 2) {
          psVar15 = param_1->s3;
          pSVar11 = (psVar15->tmp).new_cipher;
          if (((int)(pSVar11->algorithm_auth << 0x1d) < 0) ||
             ((int)(pSVar11->algorithm_mkey << 0x17) < 0)) {
            uVar3 = 1;
            param_1->state = 0x1140;
          }
          else {
            iVar4 = ssl3_get_server_certificate(param_1);
            if (iVar4 < 1) goto LAB_00058aa0;
            if (param_1->tlsext_status_type == 0) {
              psVar15 = param_1->s3;
              param_1->state = 0x1140;
              uVar3 = 0;
            }
            else {
              psVar15 = param_1->s3;
              param_1->state = 0x11f0;
              uVar3 = 0;
            }
          }
LAB_00058c0e:
          param_1->init_num = 0;
          goto LAB_00058cb8;
        }
      }
      else if (0x114f < iVar7) {
        if (iVar7 < 0x1152) {
          iVar4 = ssl3_get_certificate_request(param_1);
          if (0 < iVar4) {
            param_1->init_num = 0;
            psVar15 = param_1->s3;
            uVar3 = 0;
            param_1->state = 0x1160;
            goto LAB_00058cb8;
          }
        }
        else {
          if (1 < iVar7 - 0x1160U) goto LAB_00058e8e;
          iVar4 = ssl3_get_server_done(param_1);
          if (0 < iVar4) {
            dtls1_stop_timer(param_1);
            psVar15 = param_1->s3;
            uVar3 = 0;
            if ((psVar15->tmp).cert_req == 0) {
              iVar16 = 0x1180;
            }
            (psVar15->tmp).next_state = iVar16;
            param_1->state = iVar16;
            goto LAB_00058c0e;
          }
        }
        goto LAB_00058aa0;
      }
      goto LAB_00058e8e;
    }
    if (iVar7 < 0x1126) {
      if (iVar7 == 0x1100) {
        param_1->rwstate = 2;
        lVar6 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar6) {
          psVar15 = param_1->s3;
          param_1->rwstate = 1;
          uVar3 = 0;
          param_1->state = (psVar15->tmp).next_state;
          goto LAB_00058cb8;
        }
        iVar7 = BIO_test_flags(param_1->wbio,8);
        iVar4 = -1;
        if (iVar7 == 0) {
          iVar4 = -1;
          param_1->rwstate = 1;
          param_1->state = (param_1->s3->tmp).next_state;
        }
        goto LAB_00058aa0;
      }
      if (iVar7 < 0x1101) goto LAB_00058a24;
      if (iVar7 != 0x1111) {
        if (iVar7 < 0x1112) {
          if (iVar7 == 0x1110) {
            param_1->shutdown = 0;
            ssl3_init_finished_mac(param_1);
            goto LAB_0005892e;
          }
          goto LAB_00058e8e;
        }
        if (iVar7 - 0x1120U < 2) {
          iVar4 = ssl3_get_server_hello(param_1);
          if (0 < iVar4) {
            if (param_1->hit == 0) {
              param_1->state = 0x1126;
            }
            else {
              param_1->state = 0x11d0;
              if (param_1->tlsext_ocsp_resplen != 0) {
                param_1->state = 0x11e0;
              }
            }
            param_1->init_num = 0;
            uVar3 = 0;
            psVar15 = param_1->s3;
            goto LAB_00058cb8;
          }
          goto LAB_00058aa0;
        }
        goto LAB_00058e8e;
      }
LAB_0005892e:
      dtls1_start_timer(param_1);
      iVar4 = dtls1_client_hello(param_1);
      if (iVar4 < 1) goto LAB_00058aa0;
      if (param_1->d1->send_cookie == 0) {
        pBVar5 = param_1->bbio;
        append = param_1->wbio;
        param_1->state = 0x1120;
        param_1->init_num = 0;
        if (pBVar5 == append) goto LAB_00058d98;
      }
      else {
        pBVar5 = param_1->bbio;
        param_1->state = 0x1100;
        append = param_1->wbio;
        (param_1->s3->tmp).next_state = 0x1120;
        param_1->init_num = 0;
        if (pBVar5 == append) {
LAB_00058d98:
          psVar15 = param_1->s3;
          uVar3 = 0;
          goto LAB_00058cb8;
        }
      }
      pBVar5 = BIO_push(pBVar5,append);
      uVar3 = (param_1->s3->tmp).reuse_message;
      param_1->wbio = pBVar5;
      goto joined_r0x00058978;
    }
    local_2c[0] = 0;
    iVar4 = (*param_1->method->ssl_get_message)(param_1,0x1126,0x1127,-1,param_1->mode,local_2c);
    if (local_2c[0] == 0) {
      if (iVar4 < 1) goto LAB_00058aa0;
    }
    else {
      psVar15 = param_1->s3;
      if ((psVar15->tmp).message_type == 3) {
        pbVar18 = (byte *)param_1->init_msg;
        if (((uint)*pbVar18 != param_1->version >> 8) ||
           ((uint)pbVar18[1] != (param_1->version & 0xffU))) {
          iVar4 = -1;
          ERR_put_error(0x14,0xfb,0x10a,"d1_clnt.c",0x3b4);
          param_1->version = param_1->version & 0xff00U | (uint)pbVar18[1];
          ssl3_send_alert(param_1,2,0x46);
          param_1->state = 5;
          goto LAB_00058aa0;
        }
        bVar1 = pbVar18[2];
        memcpy(param_1->d1->cookie,pbVar18 + 3,(uint)bVar1);
        pdVar13 = param_1->d1;
        pdVar13->cookie_len = (uint)bVar1;
        pdVar13->send_cookie = 1;
      }
      else {
        param_1->d1->send_cookie = 0;
        (psVar15->tmp).reuse_message = 1;
      }
    }
    dtls1_stop_timer(param_1);
    uVar3 = 0;
    psVar15 = param_1->s3;
    uVar9 = param_1->d1->send_cookie;
    param_1->init_num = 0;
    if (uVar9 == 0) {
      iVar4 = 0x1130;
    }
    else {
      iVar4 = 0x1110;
    }
    param_1->state = iVar4;
  }
  else if (iVar7 < 0x11d2) {
    if (iVar7 < 0x11d0) {
      if (iVar7 < 0x1192) {
        iVar16 = 0x1190;
        if (iVar7 < 0x1190) {
          if (1 < iVar7 - 0x1180U) goto LAB_00058e8e;
          dtls1_start_timer(param_1);
          iVar4 = dtls1_send_client_key_exchange(param_1);
          if (0 < iVar4) {
            psVar15 = param_1->s3;
            uVar3 = 0;
            iVar4 = (psVar15->tmp).cert_req;
            param_1->init_num = 0;
            if (iVar4 != 1) {
              iVar16 = 0x11a0;
            }
            param_1->state = iVar16;
            goto LAB_00058cb8;
          }
          goto LAB_00058aa0;
        }
        dtls1_start_timer(param_1);
        iVar4 = dtls1_send_client_verify(param_1);
        if (iVar4 < 1) goto LAB_00058aa0;
        param_1->init_num = 0;
        psVar15 = param_1->s3;
        uVar3 = 0;
        param_1->state = 0x11a0;
      }
      else {
        if (iVar7 < 0x11a0) goto LAB_00058e8e;
        if (iVar7 < 0x11a2) {
          if (param_1->hit == 0) {
            dtls1_start_timer(param_1);
          }
          iVar4 = dtls1_send_change_cipher_spec(param_1,0x11a0,0x11a1);
          if (iVar4 < 1) goto LAB_00058aa0;
          pSVar14 = param_1->session;
          param_1->init_num = 0;
          pSVar11 = (param_1->s3->tmp).new_cipher;
          pSVar12 = (param_1->s3->tmp).new_compression;
          param_1->state = 0x11b0;
          *(SSL_CIPHER **)(pSVar14->krb5_client_princ + 0x24) = pSVar11;
          if (pSVar12 != (SSL_COMP *)0x0) {
            pSVar12 = (SSL_COMP *)pSVar12->id;
          }
          pSVar8 = param_1->method;
          *(SSL_COMP **)(pSVar14->krb5_client_princ + 0x20) = pSVar12;
          iVar4 = (**(code **)(pSVar8->ssl3_enc + 8))(param_1);
          if ((iVar4 == 0) ||
             (iVar4 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12), iVar4 == 0))
          goto LAB_00058dc8;
          dtls1_reset_seq_numbers(param_1,2);
          psVar15 = param_1->s3;
          uVar3 = 0;
        }
        else {
          if (1 < iVar7 - 0x11b0U) goto LAB_00058e8e;
          if (param_1->hit == 0) {
            dtls1_start_timer(param_1);
          }
          psVar17 = param_1->method->ssl3_enc;
          iVar4 = dtls1_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar17 + 0x20),
                                      *(undefined4 *)(psVar17 + 0x24));
          if (iVar4 < 1) goto LAB_00058aa0;
          psVar15 = param_1->s3;
          iVar4 = param_1->hit;
          param_1->state = 0x1100;
          uVar9 = psVar15->flags;
          uVar3 = uVar9 & 0xfffffffb;
          psVar15->flags = uVar3;
          if (iVar4 == 0) {
            if (param_1->tlsext_ocsp_resplen == 0) {
              (psVar15->tmp).next_state = 0x11d0;
            }
            else {
              (psVar15->tmp).next_state = 0x11e0;
            }
          }
          else {
            (psVar15->tmp).next_state = 3;
            if ((int)(uVar9 << 0x1e) < 0) {
              param_1->state = 3;
              psVar15->flags = uVar3 | 4;
              psVar15->delay_buf_pop_ret = 0;
            }
          }
          param_1->init_num = 0;
          uVar3 = 0;
        }
      }
    }
    else {
      param_1->d1[1].send_cookie = 1;
      iVar4 = ssl3_get_finished(param_1);
      if (iVar4 < 1) goto LAB_00058aa0;
      dtls1_stop_timer(param_1);
      uVar3 = 0;
      param_1->init_num = 0;
      if (param_1->hit == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 0x11a0;
      }
      psVar15 = param_1->s3;
      param_1->state = iVar4;
    }
  }
  else {
    if (0x11f1 < iVar7) {
      if ((iVar7 != 0x4000) && (iVar7 != 0x5000)) {
        if (iVar7 != 0x3004) goto LAB_00058e8e;
        param_1->tlsext_hb_seq = 1;
        param_1->state = 0x1000;
        *(int *)(param_1->psk_server_callback + 0x38) =
             *(int *)(param_1->psk_server_callback + 0x38) + 1;
      }
LAB_00058c3e:
      param_1->server = 0;
      if (p_Var19 != (_func_3152 *)0x0) {
        (*p_Var19)(param_1,0x10,1);
      }
      uVar3 = param_1->version & 0xff00;
      if (uVar3 == 0x100 || uVar3 == 0xfe00) {
        param_1->type = 0x1000;
        if (param_1->init_buf == (BUF_MEM *)0x0) {
          str = BUF_MEM_new();
          if (str != (BUF_MEM *)0x0) {
            iVar4 = BUF_MEM_grow(str,0x4000);
            if (iVar4 != 0) {
              param_1->init_buf = str;
              goto LAB_00058c70;
            }
            param_1->state = 5;
            param_1->in_handshake = param_1->in_handshake + -1;
            BUF_MEM_free(str);
            iVar4 = -1;
            goto LAB_00058aa6;
          }
        }
        else {
LAB_00058c70:
          iVar4 = ssl3_setup_buffers(param_1);
          if ((iVar4 != 0) && (iVar4 = ssl_init_wbio_buffer(param_1,0), iVar4 != 0)) {
            psVar15 = param_1->s3;
            param_1->state = 0x1110;
            *(int *)(param_1->psk_server_callback + 0x34) =
                 *(int *)(param_1->psk_server_callback + 0x34) + 1;
            param_1->init_num = 0;
            memset(psVar15->client_random,0,0x20);
            pdVar13 = param_1->d1;
            psVar15 = param_1->s3;
            uVar3 = 0;
            pdVar13->send_cookie = 0;
            param_1->hit = 0;
            pdVar13[1].send_cookie = 0;
            psVar15->change_cipher_spec = 0;
            goto LAB_00058cb8;
          }
        }
LAB_00058dc8:
        iVar4 = -1;
        param_1->state = 5;
      }
      else {
        iVar4 = -1;
        ERR_put_error(0x14,0xf9,0x44,"d1_clnt.c",0xd5);
        param_1->state = 5;
      }
      goto LAB_00058aa0;
    }
    if (iVar7 < 0x11f0) {
      if (1 < iVar7 - 0x11e0U) goto LAB_00058e8e;
      iVar4 = ssl3_get_new_session_ticket(param_1);
      if (iVar4 < 1) goto LAB_00058aa0;
      param_1->init_num = 0;
      psVar15 = param_1->s3;
      uVar3 = 0;
      param_1->state = 0x11d0;
    }
    else {
      iVar4 = ssl3_get_cert_status(param_1);
      if (iVar4 < 1) goto LAB_00058aa0;
      param_1->init_num = 0;
      psVar15 = param_1->s3;
      uVar3 = 0;
      param_1->state = 0x1140;
    }
  }
LAB_00058cb8:
  uVar3 = uVar3 | (psVar15->tmp).reuse_message;
joined_r0x00058978:
  if (uVar3 == 0) {
    if ((param_1->ctx != (SSL_CTX *)0x0) &&
       (iVar4 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar4 < 1)) goto LAB_00058aa0;
    if (p_Var19 == (_func_3152 *)0x0) {
      iVar4 = param_1->state;
    }
    else {
      iVar4 = param_1->state;
      if (iVar7 != iVar4) {
        param_1->state = iVar7;
        (*p_Var19)(param_1,0x1001,1);
        param_1->state = iVar4;
      }
    }
  }
  else {
    iVar4 = param_1->state;
  }
  goto LAB_000588e6;
LAB_00058a24:
  if ((iVar7 == 0x1000) || (iVar7 == 0x1003)) goto LAB_00058c3e;
  if (iVar7 == 3) {
    ssl3_cleanup_key_block(param_1);
    if (-1 < param_1->s3->flags << 0x1d) {
      ssl_free_wbio_buffer(param_1);
    }
    param_1->init_num = 0;
    param_1->tlsext_hb_seq = 0;
    param_1->new_session = 0;
    ssl_update_cache(param_1,1);
    p_Var10 = param_1->psk_server_callback;
    if (param_1->hit != 0) {
      *(int *)(p_Var10 + 0x58) = *(int *)(p_Var10 + 0x58) + 1;
    }
    iVar4 = *(int *)(p_Var10 + 0x3c);
    param_1->handshake_func = dtls1_connect;
    *(int *)(p_Var10 + 0x3c) = iVar4 + 1;
    if (p_Var19 != (_func_3152 *)0x0) {
      (*p_Var19)(param_1,0x20,1);
    }
    pdVar13 = param_1->d1;
    iVar4 = 1;
    pdVar13->handshake_read_seq = 0;
    pdVar13->next_handshake_write_seq = 0;
    dtls1_clear_received_buffer(param_1);
LAB_00058aa0:
    param_1->in_handshake = param_1->in_handshake + -1;
LAB_00058aa6:
    if (p_Var19 != (_func_3152 *)0x0) {
      (*p_Var19)(param_1,0x1002,iVar4);
    }
    return iVar4;
  }
LAB_00058e8e:
  iVar4 = -1;
  ERR_put_error(0x14,0xf9,0xff,"d1_clnt.c",0x2f8);
  param_1->in_handshake = param_1->in_handshake + -1;
  goto LAB_00058aa6;
}

