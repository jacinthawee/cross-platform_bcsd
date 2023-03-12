
int dtls1_connect(SSL *param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ssl3_enc_method *psVar8;
  dtls1_state_st *pdVar9;
  SSL_SESSION *pSVar10;
  byte *pbVar11;
  BUF_MEM *pBVar12;
  SSL_CIPHER *pSVar13;
  SSL_COMP *pSVar14;
  SSL_METHOD *pSVar15;
  ssl3_state_st *psVar16;
  BIO *pBVar17;
  _func_3154 *p_Var18;
  uint uVar19;
  BIO *pBVar20;
  int iVar21;
  _func_3152 *p_Var22;
  undefined4 local_34;
  int local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_34 = (*(code *)PTR_time_006a9adc)(0);
  (*(code *)PTR_RAND_add_006a8004)(&local_34,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  puVar4 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  p_Var22 = param_1->info_callback;
  *puVar4 = 0;
  if (p_Var22 == (_func_3152 *)0x0) {
    p_Var22 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
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
LAB_0049c3ec:
  iVar21 = iVar6;
  if (0x1173 < iVar6) goto LAB_0049c4d4;
LAB_0049c3fc:
  puVar2 = PTR_BIO_ctrl_006a6e18;
  if (0x116f < iVar21) {
    dtls1_start_timer(param_1);
    iVar6 = dtls1_send_client_certificate(param_1);
    if (0 < iVar6) {
      psVar16 = param_1->s3;
      param_1->init_num = 0;
      param_1->state = 0x1180;
      goto LAB_0049c9cc;
    }
    goto LAB_0049c684;
  }
  if (iVar21 < 0x1128) {
    if (iVar21 < 0x1126) {
      if (iVar21 == 0x1100) {
        param_1->rwstate = 2;
        iVar6 = (*(code *)puVar2)(param_1->wbio,0xb,0,0);
        if (0 < iVar6) {
          psVar16 = param_1->s3;
          param_1->rwstate = 1;
          param_1->state = (psVar16->tmp).next_state;
          goto LAB_0049c9cc;
        }
        iVar6 = (*(code *)PTR_BIO_test_flags_006a7868)(param_1->wbio,8);
        if (iVar6 == 0) {
          iVar6 = -1;
          param_1->rwstate = 1;
          param_1->state = (param_1->s3->tmp).next_state;
        }
        else {
          iVar6 = -1;
        }
      }
      else if (iVar21 < 0x1101) {
        if (iVar21 == 0x1000) goto LAB_0049c910;
        if (iVar21 == 0x1003) goto LAB_0049c910;
        if (iVar21 != 3) goto LAB_0049cc54;
        ssl3_cleanup_key_block(param_1);
        if ((param_1->s3->flags & 4U) == 0) {
          ssl_free_wbio_buffer(param_1);
        }
        param_1->init_num = 0;
        param_1->tlsext_hb_seq = 0;
        param_1->new_session = 0;
        ssl_update_cache(param_1,1);
        p_Var18 = param_1->psk_server_callback;
        if (param_1->hit != 0) {
          *(int *)(p_Var18 + 0x58) = *(int *)(p_Var18 + 0x58) + 1;
        }
        iVar6 = *(int *)(p_Var18 + 0x3c);
        param_1->handshake_func = dtls1_connect;
        *(int *)(p_Var18 + 0x3c) = iVar6 + 1;
        if (p_Var22 != (_func_3152 *)0x0) {
          (*p_Var22)(param_1,0x20,1);
        }
        pdVar9 = param_1->d1;
        pdVar9->handshake_read_seq = 0;
        pdVar9->next_handshake_write_seq = 0;
        dtls1_clear_received_buffer(param_1);
        iVar6 = 1;
      }
      else {
        if (iVar21 != 0x1111) {
          if (iVar21 < 0x1112) {
            if (iVar21 == 0x1110) {
              param_1->shutdown = 0;
              ssl3_init_finished_mac(param_1);
              goto LAB_0049c44c;
            }
          }
          else if (iVar21 - 0x1120U < 2) {
            iVar6 = ssl3_get_server_hello(param_1);
            if (0 < iVar6) {
              if (param_1->hit == 0) {
                psVar16 = param_1->s3;
                param_1->init_num = 0;
                param_1->state = 0x1126;
              }
              else {
                param_1->state = 0x11d0;
                if (param_1->tlsext_ocsp_resplen != 0) {
                  param_1->state = 0x11e0;
                }
                psVar16 = param_1->s3;
                param_1->init_num = 0;
              }
              goto LAB_0049c9cc;
            }
            goto LAB_0049c684;
          }
          goto LAB_0049cc54;
        }
LAB_0049c44c:
        dtls1_start_timer(param_1);
        iVar6 = dtls1_client_hello(param_1);
        if (0 < iVar6) {
          if (param_1->d1->send_cookie == 0) {
            param_1->init_num = 0;
            param_1->state = 0x1120;
            if (param_1->bbio != param_1->wbio) goto LAB_0049c49c;
          }
          else {
            pBVar17 = param_1->bbio;
            pBVar20 = param_1->wbio;
            param_1->state = 0x1100;
            (param_1->s3->tmp).next_state = 0x1120;
            param_1->init_num = 0;
            if (pBVar17 != pBVar20) {
LAB_0049c49c:
              pBVar17 = (BIO *)(*(code *)PTR_BIO_push_006a74c4)();
              param_1->wbio = pBVar17;
              iVar6 = (param_1->s3->tmp).reuse_message;
              goto joined_r0x0049c4b8;
            }
          }
          goto LAB_0049cb38;
        }
      }
      goto LAB_0049c684;
    }
    local_30 = 0;
    iVar6 = (*param_1->method->ssl_get_message)(param_1,0x1126,0x1127,-1,param_1->mode,&local_30);
    if (local_30 != 0) {
      psVar16 = param_1->s3;
      if ((psVar16->tmp).message_type == 3) {
        pbVar11 = (byte *)param_1->init_msg;
        if (((uint)*pbVar11 != param_1->version >> 8) ||
           ((uint)pbVar11[1] != (param_1->version & 0xffU))) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xfb,0x10a,"d1_clnt.c",0x3b4);
          param_1->version = param_1->version & 0xff00U | (uint)pbVar11[1];
          ssl3_send_alert(param_1,2,0x46);
          goto LAB_0049cb80;
        }
        bVar1 = pbVar11[2];
        (*(code *)PTR_memcpy_006a9aec)(param_1->d1->cookie,pbVar11 + 3,(uint)bVar1);
        pdVar9 = param_1->d1;
        pdVar9->cookie_len = (uint)bVar1;
        pdVar9->send_cookie = 1;
      }
      else {
        param_1->d1->send_cookie = 0;
        (psVar16->tmp).reuse_message = 1;
      }
LAB_0049cd20:
      dtls1_stop_timer(param_1);
      iVar6 = 0x1130;
      psVar16 = param_1->s3;
      uVar5 = param_1->d1->send_cookie;
      param_1->init_num = 0;
      if (uVar5 != 0) {
        iVar6 = 0x1110;
      }
      param_1->state = iVar6;
LAB_0049c9cc:
      do {
        if ((psVar16->tmp).reuse_message == 0) goto LAB_0049c544;
        iVar21 = param_1->state;
        while( true ) {
          if (iVar21 < 0x1174) goto LAB_0049c3fc;
LAB_0049c4d4:
          if (0x11d1 < iVar21) {
            if (0x11f1 < iVar21) {
              if ((iVar21 == 0x4000) || (iVar21 == 0x5000)) goto LAB_0049c910;
              if (iVar21 == 0x3004) goto code_r0x0049c8f4;
              goto LAB_0049cc54;
            }
            if (iVar21 < 0x11f0) {
              if (1 < iVar21 - 0x11e0U) goto LAB_0049cc54;
              iVar6 = ssl3_get_new_session_ticket(param_1);
              if (iVar6 < 1) goto LAB_0049c684;
              psVar16 = param_1->s3;
              param_1->init_num = 0;
              param_1->state = 0x11d0;
            }
            else {
              iVar6 = ssl3_get_cert_status(param_1);
              if (iVar6 < 1) goto LAB_0049c684;
              psVar16 = param_1->s3;
              param_1->init_num = 0;
              param_1->state = 0x1140;
            }
            goto LAB_0049c9cc;
          }
          if (0x11cf < iVar21) {
            param_1->d1[1].send_cookie = 1;
            iVar6 = ssl3_get_finished(param_1,0x11d0,0x11d1);
            if (iVar6 < 1) goto LAB_0049c684;
            dtls1_stop_timer(param_1);
            iVar6 = 0x11a0;
            psVar16 = param_1->s3;
            if (param_1->hit == 0) {
              iVar6 = 3;
            }
            param_1->init_num = 0;
            param_1->state = iVar6;
            goto LAB_0049c9cc;
          }
          if (0x1191 < iVar21) {
            if (iVar21 < 0x11a0) goto LAB_0049cc54;
            if (iVar21 < 0x11a2) {
              if (param_1->hit == 0) {
                dtls1_start_timer(param_1);
              }
              iVar6 = dtls1_send_change_cipher_spec(param_1,0x11a0,0x11a1);
              if (iVar6 < 1) goto LAB_0049c684;
              pSVar10 = param_1->session;
              param_1->init_num = 0;
              param_1->state = 0x11b0;
              pSVar14 = (param_1->s3->tmp).new_compression;
              *(SSL_CIPHER **)(pSVar10->krb5_client_princ + 0x24) = (param_1->s3->tmp).new_cipher;
              if (pSVar14 == (SSL_COMP *)0x0) {
                iVar6 = 0;
              }
              else {
                iVar6 = pSVar14->id;
              }
              pSVar15 = param_1->method;
              *(int *)(pSVar10->krb5_client_princ + 0x20) = iVar6;
              iVar6 = (**(code **)(pSVar15->ssl3_enc + 8))(param_1);
              if ((iVar6 == 0) ||
                 (iVar6 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12), iVar6 == 0)
                 ) goto LAB_0049cb80;
              dtls1_reset_seq_numbers(param_1,2);
              psVar16 = param_1->s3;
            }
            else {
              if (1 < iVar21 - 0x11b0U) goto LAB_0049cc54;
              if (param_1->hit == 0) {
                dtls1_start_timer(param_1);
              }
              psVar8 = param_1->method->ssl3_enc;
              iVar6 = dtls1_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar8 + 0x20),
                                          *(undefined4 *)(psVar8 + 0x24));
              if (iVar6 < 1) goto LAB_0049c684;
              psVar16 = param_1->s3;
              iVar6 = param_1->hit;
              uVar19 = psVar16->flags;
              param_1->state = 0x1100;
              uVar5 = uVar19 & 0xfffffffb;
              psVar16->flags = uVar5;
              if (iVar6 == 0) {
                if (param_1->tlsext_ocsp_resplen == 0) {
                  (psVar16->tmp).next_state = 0x11d0;
                  param_1->init_num = 0;
                }
                else {
                  (psVar16->tmp).next_state = 0x11e0;
                  param_1->init_num = 0;
                }
              }
              else {
                (psVar16->tmp).next_state = 3;
                if ((uVar19 & 2) != 0) {
                  param_1->state = 3;
                  psVar16->delay_buf_pop_ret = 0;
                  psVar16->flags = uVar5 | 4;
                }
                param_1->init_num = 0;
              }
            }
            goto LAB_0049c9cc;
          }
          if (0x118f < iVar21) break;
          if (1 < iVar21 - 0x1180U) goto LAB_0049cc54;
          dtls1_start_timer(param_1);
          iVar6 = dtls1_send_client_key_exchange(param_1);
          if (iVar6 < 1) goto LAB_0049c684;
          iVar6 = (param_1->s3->tmp).cert_req;
          param_1->init_num = 0;
          iVar7 = 0x1190;
          if (iVar6 != 1) {
            iVar7 = 0x11a0;
          }
          param_1->state = iVar7;
          iVar6 = (param_1->s3->tmp).reuse_message;
joined_r0x0049c4b8:
          if (iVar6 == 0) {
LAB_0049c544:
            if ((param_1->ctx != (SSL_CTX *)0x0) &&
               (iVar6 = (*(code *)PTR_BIO_ctrl_006a6e18)(param_1->wbio,0xb,0,0), iVar6 < 1)) {
              iVar21 = param_1->in_handshake;
              goto LAB_0049c688;
            }
            if (p_Var22 != (_func_3152 *)0x0) {
              iVar7 = param_1->state;
              iVar6 = iVar21;
              if (iVar7 != iVar21) {
                param_1->state = iVar21;
                (*p_Var22)(param_1,0x1001,1);
                param_1->state = iVar7;
                iVar6 = iVar7;
              }
              goto LAB_0049c3ec;
            }
          }
          iVar21 = param_1->state;
        }
        dtls1_start_timer(param_1);
        iVar6 = dtls1_send_client_verify(param_1);
        if (iVar6 < 1) goto LAB_0049c684;
        psVar16 = param_1->s3;
        param_1->init_num = 0;
        param_1->state = 0x11a0;
      } while( true );
    }
    if (0 < iVar6) goto LAB_0049cd20;
    iVar21 = param_1->in_handshake;
  }
  else {
    if (iVar21 < 0x1142) {
      if (iVar21 < 0x1140) {
        if (1 < iVar21 - 0x1130U) goto LAB_0049cc54;
        pSVar13 = (param_1->s3->tmp).new_cipher;
        if (((pSVar13->algorithm_auth & 4) == 0) && ((pSVar13->algorithm_mkey & 0x100) == 0)) {
          iVar6 = ssl3_get_server_certificate(param_1);
          if (iVar6 < 1) goto LAB_0049c684;
          if (param_1->tlsext_status_type == 0) {
            iVar6 = 0x1140;
            param_1->state = 0x1140;
          }
          else {
            iVar6 = 0x11f0;
            param_1->state = 0x11f0;
          }
          param_1->init_num = 0;
          if ((param_1->s3->tmp).reuse_message == 0) goto LAB_0049c544;
          goto LAB_0049c3ec;
        }
        param_1->init_num = 0;
        iVar21 = 0x1140;
        param_1->state = 0x1140;
      }
      iVar6 = ssl3_get_key_exchange(param_1);
      if (0 < iVar6) {
        param_1->init_num = 0;
        param_1->state = 0x1150;
        iVar6 = ssl3_check_cert_and_algorithm(param_1);
        if (iVar6 != 0) {
LAB_0049cb38:
          psVar16 = param_1->s3;
          goto LAB_0049c9cc;
        }
LAB_0049cb80:
        iVar6 = -1;
        param_1->state = 5;
      }
    }
    else {
      if (iVar21 < 0x1150) {
LAB_0049cc54:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf9,0xff,"d1_clnt.c",0x2f8);
        iVar6 = -1;
        param_1->in_handshake = param_1->in_handshake + -1;
        goto LAB_0049c690;
      }
      if (iVar21 < 0x1152) {
        iVar6 = ssl3_get_certificate_request(param_1);
        if (0 < iVar6) {
          psVar16 = param_1->s3;
          param_1->init_num = 0;
          param_1->state = 0x1160;
          goto LAB_0049c9cc;
        }
      }
      else {
        if (1 < iVar21 - 0x1160U) goto LAB_0049cc54;
        iVar6 = ssl3_get_server_done(param_1);
        if (0 < iVar6) {
          dtls1_stop_timer(param_1);
          iVar6 = 0x1170;
          psVar16 = param_1->s3;
          if ((psVar16->tmp).cert_req == 0) {
            iVar6 = 0x1180;
          }
          (psVar16->tmp).next_state = iVar6;
          param_1->init_num = 0;
          param_1->state = iVar6;
          goto LAB_0049c9cc;
        }
      }
    }
LAB_0049c684:
    iVar21 = param_1->in_handshake;
  }
LAB_0049c688:
  param_1->in_handshake = iVar21 + -1;
LAB_0049c690:
  if (p_Var22 != (_func_3152 *)0x0) {
    (*p_Var22)(param_1,0x1002,iVar6);
  }
  if (local_2c == *(int *)puVar3) {
    return iVar6;
  }
  iVar6 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  while (iVar21 = (*(code *)PTR_pqueue_pop_006a827c)
                            (*(undefined4 *)(*(int *)(iVar6 + 0x5c) + 0x238)), iVar21 != 0) {
    iVar7 = *(int *)(iVar21 + 8);
    if (*(int *)(iVar7 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(int *)(iVar7 + 8));
      iVar7 = *(int *)(iVar21 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar7);
    (*(code *)PTR_pitem_free_006a8278)(iVar21);
  }
  while (iVar21 = (*(code *)PTR_pqueue_pop_006a827c)
                            (*(undefined4 *)(*(int *)(iVar6 + 0x5c) + 0x240)), iVar21 != 0) {
    iVar7 = *(int *)(iVar21 + 8);
    if (*(int *)(iVar7 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(int *)(iVar7 + 8));
      iVar7 = *(int *)(iVar21 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar7);
    (*(code *)PTR_pitem_free_006a8278)(iVar21);
  }
  while (iVar21 = (*(code *)PTR_pqueue_pop_006a827c)
                            (*(undefined4 *)(*(int *)(iVar6 + 0x5c) + 0x250)), iVar21 != 0) {
    iVar7 = *(int *)(iVar21 + 8);
    if (*(int *)(iVar7 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(int *)(iVar7 + 8));
      iVar7 = *(int *)(iVar21 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar7);
    (*(code *)PTR_pitem_free_006a8278)(iVar21);
  }
  while (iVar21 = (*(code *)PTR_pqueue_pop_006a827c)
                            (*(undefined4 *)(*(int *)(iVar6 + 0x5c) + 0x244)), iVar21 != 0) {
    dtls1_hm_fragment_free(*(undefined4 *)(iVar21 + 8));
    (*(code *)PTR_pitem_free_006a8278)(iVar21);
  }
  iVar21 = (*(code *)PTR_pqueue_pop_006a827c)(*(undefined4 *)(*(int *)(iVar6 + 0x5c) + 0x248));
  while (iVar21 != 0) {
    dtls1_hm_fragment_free(*(undefined4 *)(iVar21 + 8));
    (*(code *)PTR_pitem_free_006a8278)(iVar21);
    iVar21 = (*(code *)PTR_pqueue_pop_006a827c)(*(undefined4 *)(*(int *)(iVar6 + 0x5c) + 0x248));
  }
  return 0;
code_r0x0049c8f4:
  param_1->state = 0x1000;
  param_1->tlsext_hb_seq = 1;
  *(int *)(param_1->psk_server_callback + 0x38) = *(int *)(param_1->psk_server_callback + 0x38) + 1;
LAB_0049c910:
  param_1->server = 0;
  if (p_Var22 != (_func_3152 *)0x0) {
    (*p_Var22)(param_1,0x10,1);
  }
  uVar5 = param_1->version & 0xff00;
  if ((uVar5 != 0xfe00) && (uVar5 != 0x100)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf9,0x44,"d1_clnt.c",0xd5);
    iVar6 = -1;
    param_1->state = 5;
    goto LAB_0049c684;
  }
  param_1->type = 0x1000;
  if (param_1->init_buf == (BUF_MEM *)0x0) {
    pBVar12 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a749c)();
    if (pBVar12 == (BUF_MEM *)0x0) goto LAB_0049cb80;
    iVar6 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(pBVar12,0x4000);
    puVar2 = PTR_BUF_MEM_free_006a7494;
    if (iVar6 == 0) {
      param_1->state = 5;
      param_1->in_handshake = param_1->in_handshake + -1;
      (*(code *)puVar2)(pBVar12);
      iVar6 = -1;
      goto LAB_0049c690;
    }
    param_1->init_buf = pBVar12;
  }
  iVar6 = ssl3_setup_buffers(param_1);
  if ((iVar6 == 0) ||
     (iVar6 = ssl_init_wbio_buffer(param_1,0), puVar2 = PTR_memset_006a99f4, iVar6 == 0))
  goto LAB_0049cb80;
  psVar16 = param_1->s3;
  param_1->state = 0x1110;
  *(int *)(param_1->psk_server_callback + 0x34) = *(int *)(param_1->psk_server_callback + 0x34) + 1;
  param_1->init_num = 0;
  (*(code *)puVar2)(psVar16->client_random,0,0x20);
  pdVar9 = param_1->d1;
  psVar16 = param_1->s3;
  pdVar9->send_cookie = 0;
  param_1->hit = 0;
  pdVar9[1].send_cookie = 0;
  psVar16->change_cipher_spec = 0;
  goto LAB_0049c9cc;
}

