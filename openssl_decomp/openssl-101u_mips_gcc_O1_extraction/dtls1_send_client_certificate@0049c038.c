
int dtls1_send_client_certificate(SSL *param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  ssl3_enc_method *psVar9;
  dtls1_state_st *pdVar10;
  SSL_SESSION *pSVar11;
  byte *pbVar12;
  BUF_MEM *pBVar13;
  SSL_CIPHER *pSVar14;
  SSL_COMP *pSVar15;
  SSL_METHOD *pSVar16;
  ssl3_state_st *psVar17;
  SSL *ssl;
  BIO *pBVar18;
  _func_3154 *p_Var19;
  uint uVar20;
  undefined4 uVar21;
  BIO *pBVar22;
  int iVar23;
  uint unaff_s2;
  _func_3152 *p_Var24;
  undefined4 uStack_74;
  int iStack_70;
  int iStack_6c;
  SSL *pSStack_68;
  undefined *puStack_64;
  uint uStack_60;
  X509 *local_1c;
  EVP_PKEY *local_18;
  SSL *local_14;
  
  puStack_64 = PTR___stack_chk_guard_006a9ae8;
  iVar4 = param_1->state;
  local_1c = (X509 *)0x0;
  local_18 = (EVP_PKEY *)0x0;
  local_14 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  if (iVar4 == 0x1170) {
    if ((((int **)param_1->cert == (int **)0x0) || (piVar5 = *(int **)param_1->cert, *piVar5 == 0))
       || (piVar5[1] == 0)) {
      param_1->state = 0x1171;
      goto LAB_0049c150;
    }
LAB_0049c0f0:
    psVar17 = param_1->s3;
LAB_0049c0f4:
    iVar4 = (psVar17->tmp).cert_req;
    param_1->state = 0x1173;
    if (iVar4 == 2) {
      uVar21 = 0;
    }
    else {
      uVar21 = **(undefined4 **)param_1->cert;
    }
    iVar4 = dtls1_output_cert_chain(param_1,uVar21);
    if (iVar4 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x105,0x44,"d1_clnt.c");
      ssl3_send_alert(param_1,2,0x50);
      iVar4 = 0;
      goto LAB_0049c0a4;
    }
    param_1->init_num = iVar4;
    param_1->init_off = 0;
    dtls1_buffer_message(param_1,0);
  }
  else {
    if (iVar4 == 0x1171) {
LAB_0049c150:
      unaff_s2 = ssl_do_client_cert_cb(param_1,&local_1c,&local_18);
      if ((int)unaff_s2 < 0) {
        iVar4 = -1;
        param_1->rwstate = 4;
        goto LAB_0049c0a4;
      }
      param_1->rwstate = 1;
      if (unaff_s2 == 1) {
        if ((local_18 == (EVP_PKEY *)0x0) || (local_1c == (X509 *)0x0)) {
          unaff_s2 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x105,0x6a,"d1_clnt.c");
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
        (*(code *)PTR_X509_free_006a6e90)();
      }
      if (local_18 != (EVP_PKEY *)0x0) {
        (*(code *)PTR_EVP_PKEY_free_006a6e78)();
      }
      if (unaff_s2 != 0) goto LAB_0049c0f0;
      if (param_1->version == 0x300) {
        (param_1->s3->tmp).cert_req = 0;
        ssl3_send_alert(param_1,1,0x29);
        iVar4 = 1;
        goto LAB_0049c0a4;
      }
      psVar17 = param_1->s3;
      (psVar17->tmp).cert_req = 2;
      goto LAB_0049c0f4;
    }
    if (iVar4 == 0x1172) goto LAB_0049c0f0;
  }
  iVar4 = dtls1_do_write(param_1,0x16);
LAB_0049c0a4:
  if (local_14 == *(SSL **)puStack_64) {
    return iVar4;
  }
  ssl = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pSStack_68 = param_1;
  uStack_60 = unaff_s2;
  uStack_74 = (*(code *)PTR_time_006a9adc)(0);
  (*(code *)PTR_RAND_add_006a8004)(&uStack_74,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  puVar6 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  p_Var24 = ssl->info_callback;
  *puVar6 = 0;
  if (p_Var24 == (_func_3152 *)0x0) {
    p_Var24 = *(_func_3152 **)(ssl->psk_server_callback + 0x9c);
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
LAB_0049c3ec:
  iVar23 = iVar4;
  if (0x1173 < iVar4) goto LAB_0049c4d4;
LAB_0049c3fc:
  puVar2 = PTR_BIO_ctrl_006a6e18;
  if (0x116f < iVar23) {
    dtls1_start_timer(ssl);
    iVar4 = dtls1_send_client_certificate(ssl);
    if (0 < iVar4) {
      psVar17 = ssl->s3;
      ssl->init_num = 0;
      ssl->state = 0x1180;
      goto LAB_0049c9cc;
    }
    goto LAB_0049c684;
  }
  if (iVar23 < 0x1128) {
    if (iVar23 < 0x1126) {
      if (iVar23 == 0x1100) {
        ssl->rwstate = 2;
        iVar4 = (*(code *)puVar2)(ssl->wbio,0xb,0,0);
        if (0 < iVar4) {
          psVar17 = ssl->s3;
          ssl->rwstate = 1;
          ssl->state = (psVar17->tmp).next_state;
          goto LAB_0049c9cc;
        }
        iVar4 = (*(code *)PTR_BIO_test_flags_006a7868)(ssl->wbio,8);
        if (iVar4 == 0) {
          iVar4 = -1;
          ssl->rwstate = 1;
          ssl->state = (ssl->s3->tmp).next_state;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (iVar23 < 0x1101) {
        if (iVar23 == 0x1000) goto LAB_0049c910;
        if (iVar23 == 0x1003) goto LAB_0049c910;
        if (iVar23 != 3) goto LAB_0049cc54;
        ssl3_cleanup_key_block(ssl);
        if ((ssl->s3->flags & 4U) == 0) {
          ssl_free_wbio_buffer(ssl);
        }
        ssl->init_num = 0;
        ssl->tlsext_hb_seq = 0;
        ssl->new_session = 0;
        ssl_update_cache(ssl,1);
        p_Var19 = ssl->psk_server_callback;
        if (ssl->hit != 0) {
          *(int *)(p_Var19 + 0x58) = *(int *)(p_Var19 + 0x58) + 1;
        }
        iVar4 = *(int *)(p_Var19 + 0x3c);
        ssl->handshake_func = dtls1_connect;
        *(int *)(p_Var19 + 0x3c) = iVar4 + 1;
        if (p_Var24 != (_func_3152 *)0x0) {
          (*p_Var24)(ssl,0x20,1);
        }
        pdVar10 = ssl->d1;
        pdVar10->handshake_read_seq = 0;
        pdVar10->next_handshake_write_seq = 0;
        dtls1_clear_received_buffer(ssl);
        iVar4 = 1;
      }
      else {
        if (iVar23 != 0x1111) {
          if (iVar23 < 0x1112) {
            if (iVar23 == 0x1110) {
              ssl->shutdown = 0;
              ssl3_init_finished_mac(ssl);
              goto LAB_0049c44c;
            }
          }
          else if (iVar23 - 0x1120U < 2) {
            iVar4 = ssl3_get_server_hello(ssl);
            if (0 < iVar4) {
              if (ssl->hit == 0) {
                psVar17 = ssl->s3;
                ssl->init_num = 0;
                ssl->state = 0x1126;
              }
              else {
                ssl->state = 0x11d0;
                if (ssl->tlsext_ocsp_resplen != 0) {
                  ssl->state = 0x11e0;
                }
                psVar17 = ssl->s3;
                ssl->init_num = 0;
              }
              goto LAB_0049c9cc;
            }
            goto LAB_0049c684;
          }
          goto LAB_0049cc54;
        }
LAB_0049c44c:
        dtls1_start_timer(ssl);
        iVar4 = dtls1_client_hello(ssl);
        if (0 < iVar4) {
          if (ssl->d1->send_cookie == 0) {
            ssl->init_num = 0;
            ssl->state = 0x1120;
            if (ssl->bbio != ssl->wbio) goto LAB_0049c49c;
          }
          else {
            pBVar18 = ssl->bbio;
            pBVar22 = ssl->wbio;
            ssl->state = 0x1100;
            (ssl->s3->tmp).next_state = 0x1120;
            ssl->init_num = 0;
            if (pBVar18 != pBVar22) {
LAB_0049c49c:
              pBVar18 = (BIO *)(*(code *)PTR_BIO_push_006a74c4)();
              ssl->wbio = pBVar18;
              iVar4 = (ssl->s3->tmp).reuse_message;
              goto joined_r0x0049c4b8;
            }
          }
          goto LAB_0049cb38;
        }
      }
      goto LAB_0049c684;
    }
    iStack_70 = 0;
    iVar4 = (*ssl->method->ssl_get_message)(ssl,0x1126,0x1127,-1,ssl->mode,&iStack_70);
    if (iStack_70 != 0) {
      psVar17 = ssl->s3;
      if ((psVar17->tmp).message_type == 3) {
        pbVar12 = (byte *)ssl->init_msg;
        if (((uint)*pbVar12 != ssl->version >> 8) || ((uint)pbVar12[1] != (ssl->version & 0xffU))) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xfb,0x10a,"d1_clnt.c",0x3b4);
          ssl->version = ssl->version & 0xff00U | (uint)pbVar12[1];
          ssl3_send_alert(ssl,2,0x46);
          goto LAB_0049cb80;
        }
        bVar1 = pbVar12[2];
        (*(code *)PTR_memcpy_006a9aec)(ssl->d1->cookie,pbVar12 + 3,(uint)bVar1);
        pdVar10 = ssl->d1;
        pdVar10->cookie_len = (uint)bVar1;
        pdVar10->send_cookie = 1;
      }
      else {
        ssl->d1->send_cookie = 0;
        (psVar17->tmp).reuse_message = 1;
      }
LAB_0049cd20:
      dtls1_stop_timer(ssl);
      iVar4 = 0x1130;
      psVar17 = ssl->s3;
      uVar7 = ssl->d1->send_cookie;
      ssl->init_num = 0;
      if (uVar7 != 0) {
        iVar4 = 0x1110;
      }
      ssl->state = iVar4;
LAB_0049c9cc:
      do {
        if ((psVar17->tmp).reuse_message == 0) goto LAB_0049c544;
        iVar23 = ssl->state;
        while( true ) {
          if (iVar23 < 0x1174) goto LAB_0049c3fc;
LAB_0049c4d4:
          if (0x11d1 < iVar23) {
            if (0x11f1 < iVar23) {
              if ((iVar23 == 0x4000) || (iVar23 == 0x5000)) goto LAB_0049c910;
              if (iVar23 == 0x3004) goto code_r0x0049c8f4;
              goto LAB_0049cc54;
            }
            if (iVar23 < 0x11f0) {
              if (1 < iVar23 - 0x11e0U) goto LAB_0049cc54;
              iVar4 = ssl3_get_new_session_ticket(ssl);
              if (iVar4 < 1) goto LAB_0049c684;
              psVar17 = ssl->s3;
              ssl->init_num = 0;
              ssl->state = 0x11d0;
            }
            else {
              iVar4 = ssl3_get_cert_status(ssl);
              if (iVar4 < 1) goto LAB_0049c684;
              psVar17 = ssl->s3;
              ssl->init_num = 0;
              ssl->state = 0x1140;
            }
            goto LAB_0049c9cc;
          }
          if (0x11cf < iVar23) {
            ssl->d1[1].send_cookie = 1;
            iVar4 = ssl3_get_finished(ssl,0x11d0,0x11d1);
            if (iVar4 < 1) goto LAB_0049c684;
            dtls1_stop_timer(ssl);
            iVar4 = 0x11a0;
            psVar17 = ssl->s3;
            if (ssl->hit == 0) {
              iVar4 = 3;
            }
            ssl->init_num = 0;
            ssl->state = iVar4;
            goto LAB_0049c9cc;
          }
          if (0x1191 < iVar23) {
            if (iVar23 < 0x11a0) goto LAB_0049cc54;
            if (iVar23 < 0x11a2) {
              if (ssl->hit == 0) {
                dtls1_start_timer(ssl);
              }
              iVar4 = dtls1_send_change_cipher_spec(ssl,0x11a0,0x11a1);
              if (iVar4 < 1) goto LAB_0049c684;
              pSVar11 = ssl->session;
              ssl->init_num = 0;
              ssl->state = 0x11b0;
              pSVar15 = (ssl->s3->tmp).new_compression;
              *(SSL_CIPHER **)(pSVar11->krb5_client_princ + 0x24) = (ssl->s3->tmp).new_cipher;
              if (pSVar15 == (SSL_COMP *)0x0) {
                iVar4 = 0;
              }
              else {
                iVar4 = pSVar15->id;
              }
              pSVar16 = ssl->method;
              *(int *)(pSVar11->krb5_client_princ + 0x20) = iVar4;
              iVar4 = (**(code **)(pSVar16->ssl3_enc + 8))(ssl);
              if ((iVar4 == 0) ||
                 (iVar4 = (**(code **)(ssl->method->ssl3_enc + 0x10))(ssl,0x12), iVar4 == 0))
              goto LAB_0049cb80;
              dtls1_reset_seq_numbers(ssl,2);
              psVar17 = ssl->s3;
            }
            else {
              if (1 < iVar23 - 0x11b0U) goto LAB_0049cc54;
              if (ssl->hit == 0) {
                dtls1_start_timer(ssl);
              }
              psVar9 = ssl->method->ssl3_enc;
              iVar4 = dtls1_send_finished(ssl,0x11b0,0x11b1,*(undefined4 *)(psVar9 + 0x20),
                                          *(undefined4 *)(psVar9 + 0x24));
              if (iVar4 < 1) goto LAB_0049c684;
              psVar17 = ssl->s3;
              iVar4 = ssl->hit;
              uVar20 = psVar17->flags;
              ssl->state = 0x1100;
              uVar7 = uVar20 & 0xfffffffb;
              psVar17->flags = uVar7;
              if (iVar4 == 0) {
                if (ssl->tlsext_ocsp_resplen == 0) {
                  (psVar17->tmp).next_state = 0x11d0;
                  ssl->init_num = 0;
                }
                else {
                  (psVar17->tmp).next_state = 0x11e0;
                  ssl->init_num = 0;
                }
              }
              else {
                (psVar17->tmp).next_state = 3;
                if ((uVar20 & 2) != 0) {
                  ssl->state = 3;
                  psVar17->delay_buf_pop_ret = 0;
                  psVar17->flags = uVar7 | 4;
                }
                ssl->init_num = 0;
              }
            }
            goto LAB_0049c9cc;
          }
          if (0x118f < iVar23) break;
          if (1 < iVar23 - 0x1180U) goto LAB_0049cc54;
          dtls1_start_timer(ssl);
          iVar4 = dtls1_send_client_key_exchange(ssl);
          if (iVar4 < 1) goto LAB_0049c684;
          iVar4 = (ssl->s3->tmp).cert_req;
          ssl->init_num = 0;
          iVar8 = 0x1190;
          if (iVar4 != 1) {
            iVar8 = 0x11a0;
          }
          ssl->state = iVar8;
          iVar4 = (ssl->s3->tmp).reuse_message;
joined_r0x0049c4b8:
          if (iVar4 == 0) {
LAB_0049c544:
            if ((ssl->ctx != (SSL_CTX *)0x0) &&
               (iVar4 = (*(code *)PTR_BIO_ctrl_006a6e18)(ssl->wbio,0xb,0,0), iVar4 < 1)) {
              iVar23 = ssl->in_handshake;
              goto LAB_0049c688;
            }
            if (p_Var24 != (_func_3152 *)0x0) {
              iVar8 = ssl->state;
              iVar4 = iVar23;
              if (iVar8 != iVar23) {
                ssl->state = iVar23;
                (*p_Var24)(ssl,0x1001,1);
                ssl->state = iVar8;
                iVar4 = iVar8;
              }
              goto LAB_0049c3ec;
            }
          }
          iVar23 = ssl->state;
        }
        dtls1_start_timer(ssl);
        iVar4 = dtls1_send_client_verify(ssl);
        if (iVar4 < 1) goto LAB_0049c684;
        psVar17 = ssl->s3;
        ssl->init_num = 0;
        ssl->state = 0x11a0;
      } while( true );
    }
    if (0 < iVar4) goto LAB_0049cd20;
    iVar23 = ssl->in_handshake;
  }
  else {
    if (iVar23 < 0x1142) {
      if (iVar23 < 0x1140) {
        if (1 < iVar23 - 0x1130U) goto LAB_0049cc54;
        pSVar14 = (ssl->s3->tmp).new_cipher;
        if (((pSVar14->algorithm_auth & 4) == 0) && ((pSVar14->algorithm_mkey & 0x100) == 0)) {
          iVar4 = ssl3_get_server_certificate(ssl);
          if (iVar4 < 1) goto LAB_0049c684;
          if (ssl->tlsext_status_type == 0) {
            iVar4 = 0x1140;
            ssl->state = 0x1140;
          }
          else {
            iVar4 = 0x11f0;
            ssl->state = 0x11f0;
          }
          ssl->init_num = 0;
          if ((ssl->s3->tmp).reuse_message == 0) goto LAB_0049c544;
          goto LAB_0049c3ec;
        }
        ssl->init_num = 0;
        iVar23 = 0x1140;
        ssl->state = 0x1140;
      }
      iVar4 = ssl3_get_key_exchange(ssl);
      if (0 < iVar4) {
        ssl->init_num = 0;
        ssl->state = 0x1150;
        iVar4 = ssl3_check_cert_and_algorithm(ssl);
        if (iVar4 != 0) {
LAB_0049cb38:
          psVar17 = ssl->s3;
          goto LAB_0049c9cc;
        }
LAB_0049cb80:
        iVar4 = -1;
        ssl->state = 5;
      }
    }
    else {
      if (iVar23 < 0x1150) {
LAB_0049cc54:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf9,0xff,"d1_clnt.c",0x2f8);
        iVar4 = -1;
        ssl->in_handshake = ssl->in_handshake + -1;
        goto LAB_0049c690;
      }
      if (iVar23 < 0x1152) {
        iVar4 = ssl3_get_certificate_request(ssl);
        if (0 < iVar4) {
          psVar17 = ssl->s3;
          ssl->init_num = 0;
          ssl->state = 0x1160;
          goto LAB_0049c9cc;
        }
      }
      else {
        if (1 < iVar23 - 0x1160U) goto LAB_0049cc54;
        iVar4 = ssl3_get_server_done(ssl);
        if (0 < iVar4) {
          dtls1_stop_timer(ssl);
          iVar4 = 0x1170;
          psVar17 = ssl->s3;
          if ((psVar17->tmp).cert_req == 0) {
            iVar4 = 0x1180;
          }
          (psVar17->tmp).next_state = iVar4;
          ssl->init_num = 0;
          ssl->state = iVar4;
          goto LAB_0049c9cc;
        }
      }
    }
LAB_0049c684:
    iVar23 = ssl->in_handshake;
  }
LAB_0049c688:
  ssl->in_handshake = iVar23 + -1;
LAB_0049c690:
  if (p_Var24 != (_func_3152 *)0x0) {
    (*p_Var24)(ssl,0x1002,iVar4);
  }
  if (iStack_6c == *(int *)puVar3) {
    return iVar4;
  }
  iVar4 = iStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  while (iVar23 = (*(code *)PTR_pqueue_pop_006a827c)
                            (*(undefined4 *)(*(int *)(iVar4 + 0x5c) + 0x238)), iVar23 != 0) {
    iVar8 = *(int *)(iVar23 + 8);
    if (*(int *)(iVar8 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(int *)(iVar8 + 8));
      iVar8 = *(int *)(iVar23 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
    (*(code *)PTR_pitem_free_006a8278)(iVar23);
  }
  while (iVar23 = (*(code *)PTR_pqueue_pop_006a827c)
                            (*(undefined4 *)(*(int *)(iVar4 + 0x5c) + 0x240)), iVar23 != 0) {
    iVar8 = *(int *)(iVar23 + 8);
    if (*(int *)(iVar8 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(int *)(iVar8 + 8));
      iVar8 = *(int *)(iVar23 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
    (*(code *)PTR_pitem_free_006a8278)(iVar23);
  }
  while (iVar23 = (*(code *)PTR_pqueue_pop_006a827c)
                            (*(undefined4 *)(*(int *)(iVar4 + 0x5c) + 0x250)), iVar23 != 0) {
    iVar8 = *(int *)(iVar23 + 8);
    if (*(int *)(iVar8 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(int *)(iVar8 + 8));
      iVar8 = *(int *)(iVar23 + 8);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
    (*(code *)PTR_pitem_free_006a8278)(iVar23);
  }
  while (iVar23 = (*(code *)PTR_pqueue_pop_006a827c)
                            (*(undefined4 *)(*(int *)(iVar4 + 0x5c) + 0x244)), iVar23 != 0) {
    dtls1_hm_fragment_free(*(undefined4 *)(iVar23 + 8));
    (*(code *)PTR_pitem_free_006a8278)(iVar23);
  }
  iVar23 = (*(code *)PTR_pqueue_pop_006a827c)(*(undefined4 *)(*(int *)(iVar4 + 0x5c) + 0x248));
  while (iVar23 != 0) {
    dtls1_hm_fragment_free(*(undefined4 *)(iVar23 + 8));
    (*(code *)PTR_pitem_free_006a8278)(iVar23);
    iVar23 = (*(code *)PTR_pqueue_pop_006a827c)(*(undefined4 *)(*(int *)(iVar4 + 0x5c) + 0x248));
  }
  return 0;
code_r0x0049c8f4:
  ssl->state = 0x1000;
  ssl->tlsext_hb_seq = 1;
  *(int *)(ssl->psk_server_callback + 0x38) = *(int *)(ssl->psk_server_callback + 0x38) + 1;
LAB_0049c910:
  ssl->server = 0;
  if (p_Var24 != (_func_3152 *)0x0) {
    (*p_Var24)(ssl,0x10,1);
  }
  uVar7 = ssl->version & 0xff00;
  if ((uVar7 != 0xfe00) && (uVar7 != 0x100)) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf9,0x44,"d1_clnt.c",0xd5);
    iVar4 = -1;
    ssl->state = 5;
    goto LAB_0049c684;
  }
  ssl->type = 0x1000;
  if (ssl->init_buf == (BUF_MEM *)0x0) {
    pBVar13 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a749c)();
    if (pBVar13 == (BUF_MEM *)0x0) goto LAB_0049cb80;
    iVar4 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(pBVar13,0x4000);
    puVar2 = PTR_BUF_MEM_free_006a7494;
    if (iVar4 == 0) {
      ssl->state = 5;
      ssl->in_handshake = ssl->in_handshake + -1;
      (*(code *)puVar2)(pBVar13);
      iVar4 = -1;
      goto LAB_0049c690;
    }
    ssl->init_buf = pBVar13;
  }
  iVar4 = ssl3_setup_buffers(ssl);
  if ((iVar4 == 0) ||
     (iVar4 = ssl_init_wbio_buffer(ssl,0), puVar2 = PTR_memset_006a99f4, iVar4 == 0))
  goto LAB_0049cb80;
  psVar17 = ssl->s3;
  ssl->state = 0x1110;
  *(int *)(ssl->psk_server_callback + 0x34) = *(int *)(ssl->psk_server_callback + 0x34) + 1;
  ssl->init_num = 0;
  (*(code *)puVar2)(psVar17->client_random,0,0x20);
  pdVar10 = ssl->d1;
  psVar17 = ssl->s3;
  pdVar10->send_cookie = 0;
  ssl->hit = 0;
  pdVar10[1].send_cookie = 0;
  psVar17->change_cipher_spec = 0;
  goto LAB_0049c9cc;
}

