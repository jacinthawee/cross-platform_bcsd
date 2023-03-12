
int dtls1_connect(SSL *param_1)

{
  byte bVar1;
  _func_3154 *p_Var2;
  SSL_CIPHER *pSVar3;
  ssl3_enc_method *psVar4;
  SSL_SESSION *pSVar5;
  SSL_COMP *pSVar6;
  byte *pbVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  ssl3_state_st *psVar11;
  BIO *pBVar12;
  long lVar13;
  BUF_MEM *str;
  uint uVar14;
  undefined4 *puVar15;
  dtls1_state_st *pdVar16;
  undefined4 *puVar17;
  int in_GS_OFFSET;
  byte bVar18;
  int iVar19;
  _func_3152 *local_34;
  time_t local_28;
  int local_24;
  int local_20;
  
  bVar18 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = time((time_t *)0x0);
  RAND_add(&local_28,4,0.0);
  ERR_clear_error();
  piVar8 = __errno_location();
  *piVar8 = 0;
  local_34 = param_1->info_callback;
  if (local_34 == (_func_3152 *)0x0) {
    local_34 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar9 = SSL_state(param_1);
  if (((uVar9 & 0x3000) == 0) || (uVar9 = SSL_state(param_1), (uVar9 & 0x4000) != 0)) {
    SSL_clear(param_1);
    uVar9 = param_1->tlsext_heartbeat;
  }
  else {
    uVar9 = param_1->tlsext_heartbeat;
  }
  if (uVar9 != 0) {
    dtls1_stop_timer(param_1);
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  do {
    iVar10 = param_1->state;
joined_r0x080b6d51:
    iVar19 = iVar10;
    if (0x1173 < iVar19) {
      if (iVar19 < 0x11d2) {
        if (iVar19 < 0x11d0) {
          if (iVar19 < 0x1192) {
            if (iVar19 < 0x1190) {
              if (1 < iVar19 - 0x1180U) goto LAB_080b7450;
              dtls1_start_timer(param_1);
              iVar10 = dtls1_send_client_key_exchange(param_1);
              if (0 < iVar10) {
                psVar11 = param_1->s3;
                if ((psVar11->tmp).cert_req == 1) {
                  param_1->state = 0x1190;
                }
                else {
                  param_1->state = 0x11a0;
                  psVar11->change_cipher_spec = 0;
                }
LAB_080b6ebc:
                param_1->init_num = 0;
                uVar9 = 0;
                goto LAB_080b6de8;
              }
            }
            else {
              dtls1_start_timer(param_1);
              iVar10 = dtls1_send_client_verify(param_1);
              if (0 < iVar10) {
                psVar11 = param_1->s3;
                param_1->state = 0x11a0;
                uVar9 = 0;
                param_1->init_num = 0;
                psVar11->change_cipher_spec = 0;
                goto LAB_080b6de8;
              }
            }
          }
          else {
            if (iVar19 < 0x11a0) goto LAB_080b7450;
            if (iVar19 < 0x11a2) {
              if (param_1->hit == 0) {
                dtls1_start_timer(param_1);
              }
              iVar10 = dtls1_send_change_cipher_spec(param_1,0x11a0,0x11a1);
              if (0 < iVar10) {
                pSVar5 = param_1->session;
                param_1->state = 0x11b0;
                param_1->init_num = 0;
                pSVar6 = (param_1->s3->tmp).new_compression;
                *(SSL_CIPHER **)(pSVar5->krb5_client_princ + 0x24) = (param_1->s3->tmp).new_cipher;
                if (pSVar6 == (SSL_COMP *)0x0) {
                  iVar10 = 0;
                }
                else {
                  iVar10 = pSVar6->id;
                }
                *(int *)(pSVar5->krb5_client_princ + 0x20) = iVar10;
                iVar10 = (**(code **)(param_1->method->ssl3_enc + 8))(param_1);
                if ((iVar10 == 0) ||
                   (iVar10 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12),
                   iVar10 == 0)) goto LAB_080b7874;
                dtls1_reset_seq_numbers(param_1,2);
                psVar11 = param_1->s3;
                uVar9 = 0;
                goto LAB_080b6de8;
              }
            }
            else {
              if (1 < iVar19 - 0x11b0U) goto LAB_080b7450;
              if (param_1->hit == 0) {
                dtls1_start_timer(param_1);
              }
              psVar4 = param_1->method->ssl3_enc;
              iVar10 = dtls1_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar4 + 0x20),
                                           *(undefined4 *)(psVar4 + 0x24));
              if (0 < iVar10) {
                psVar11 = param_1->s3;
                iVar10 = param_1->hit;
                param_1->state = 0x1100;
                uVar9 = psVar11->flags;
                uVar14 = uVar9 & 0xfffffffb;
                psVar11->flags = uVar14;
                if (iVar10 == 0) {
                  (psVar11->tmp).next_state =
                       (-(uint)(param_1->tlsext_ocsp_resplen == 0) & 0xfffffff0) + 0x11e0;
                }
                else {
                  (psVar11->tmp).next_state = 3;
                  if ((uVar9 & 2) != 0) {
                    param_1->state = 3;
                    psVar11->delay_buf_pop_ret = 0;
                    psVar11->flags = uVar14 | 4;
                  }
                }
                goto LAB_080b6ebc;
              }
            }
          }
        }
        else {
          param_1->d1->listen = 1;
          iVar10 = ssl3_get_finished(param_1,0x11d0,0x11d1);
          if (0 < iVar10) {
            dtls1_stop_timer(param_1);
            param_1->init_num = 0;
            uVar9 = 0;
            param_1->state = (-(uint)(param_1->hit == 0) & 0xffffee63) + 0x11a0;
            psVar11 = param_1->s3;
            goto LAB_080b6de8;
          }
        }
      }
      else if (iVar19 < 0x11f2) {
        if (iVar19 < 0x11f0) {
          if (1 < iVar19 - 0x11e0U) goto LAB_080b7450;
          iVar10 = ssl3_get_new_session_ticket(param_1);
          if (0 < iVar10) {
            param_1->state = 0x11d0;
            param_1->init_num = 0;
            uVar9 = 0;
            psVar11 = param_1->s3;
            goto LAB_080b6de8;
          }
        }
        else {
          iVar10 = ssl3_get_cert_status(param_1);
          if (0 < iVar10) {
            param_1->state = 0x1140;
            param_1->init_num = 0;
            uVar9 = 0;
            psVar11 = param_1->s3;
            goto LAB_080b6de8;
          }
        }
      }
      else {
        if ((iVar19 != 0x4000) && (iVar19 != 0x5000)) {
          if (iVar19 != 0x3004) goto LAB_080b7450;
          param_1->tlsext_hb_seq = 1;
          param_1->state = 0x1000;
          *(int *)(param_1->psk_server_callback + 0x38) =
               *(int *)(param_1->psk_server_callback + 0x38) + 1;
        }
LAB_080b721f:
        param_1->server = 0;
        if (local_34 != (_func_3152 *)0x0) {
          (*local_34)(param_1,0x10,1);
        }
        uVar9 = param_1->version & 0xff00;
        if ((uVar9 == 0xfe00) || (uVar9 == 0x100)) {
          param_1->type = 0x1000;
          if (param_1->init_buf == (BUF_MEM *)0x0) {
            str = BUF_MEM_new();
            if (str == (BUF_MEM *)0x0) goto LAB_080b7874;
            iVar10 = BUF_MEM_grow(str,0x4000);
            if (iVar10 == 0) {
              param_1->in_handshake = param_1->in_handshake + -1;
              BUF_MEM_free(str);
              iVar10 = -1;
              goto LAB_080b6fbe;
            }
            param_1->init_buf = str;
          }
          iVar10 = ssl3_setup_buffers(param_1);
          if ((iVar10 != 0) && (iVar10 = ssl_init_wbio_buffer(param_1,0), iVar10 != 0)) {
            psVar11 = param_1->s3;
            uVar9 = 0;
            param_1->state = 0x1110;
            *(int *)(param_1->psk_server_callback + 0x34) =
                 *(int *)(param_1->psk_server_callback + 0x34) + 1;
            param_1->init_num = 0;
            *(undefined4 *)psVar11->client_random = 0;
            *(undefined4 *)(psVar11->client_random + 0x1c) = 0;
            uVar14 = (uint)(psVar11->client_random + 4) & 0xfffffffc;
            do {
              *(undefined4 *)(uVar14 + uVar9) = 0;
              uVar9 = uVar9 + 4;
            } while (uVar9 < ((int)psVar11 + (0xe0 - uVar14) & 0xfffffffc));
            uVar9 = 0;
            param_1->d1->send_cookie = 0;
            param_1->hit = 0;
            psVar11 = param_1->s3;
            goto LAB_080b6de8;
          }
LAB_080b7874:
          iVar10 = -1;
        }
        else {
          iVar19 = 0xd6;
          iVar10 = 0x44;
LAB_080b7462:
          ERR_put_error(0x14,0xf9,iVar10,"d1_clnt.c",iVar19);
          iVar10 = -1;
        }
      }
LAB_080b6fba:
      param_1->in_handshake = param_1->in_handshake + -1;
LAB_080b6fbe:
      if (local_34 != (_func_3152 *)0x0) {
        (*local_34)(param_1,0x1002,iVar10);
      }
      if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return iVar10;
    }
    if (0x116f < iVar19) {
      dtls1_start_timer(param_1);
      iVar10 = dtls1_send_client_certificate(param_1);
      if (0 < iVar10) {
        param_1->state = 0x1180;
        param_1->init_num = 0;
        uVar9 = 0;
        psVar11 = param_1->s3;
        goto LAB_080b6de8;
      }
      goto LAB_080b6fba;
    }
    if (0x1127 < iVar19) {
      if (iVar19 < 0x1142) {
        if (iVar19 < 0x1140) {
          if (1 < iVar19 - 0x1130U) goto LAB_080b7450;
          iVar10 = ssl3_check_finished(param_1);
          if (0 < iVar10) {
            if (iVar10 == 2) {
              param_1->hit = 1;
              param_1->init_num = 0;
              uVar9 = 0;
              param_1->state = (-(uint)(param_1->tlsext_ocsp_resplen == 0) & 0xfffffff0) + 0x11e0;
              psVar11 = param_1->s3;
              goto LAB_080b6de8;
            }
            psVar11 = param_1->s3;
            pSVar3 = (psVar11->tmp).new_cipher;
            if (((*(byte *)&pSVar3->algorithm_auth & 4) == 0) &&
               ((*(byte *)((int)&pSVar3->algorithm_mkey + 1) & 1) == 0)) {
              iVar10 = ssl3_get_server_certificate(param_1);
              if (iVar10 < 1) goto LAB_080b6fba;
              if (param_1->tlsext_status_type == 0) {
                param_1->state = 0x1140;
                psVar11 = param_1->s3;
                uVar9 = 0;
              }
              else {
                param_1->state = 0x11f0;
                psVar11 = param_1->s3;
                uVar9 = 0;
              }
            }
            else {
              param_1->state = 0x1140;
              uVar9 = 1;
            }
            param_1->init_num = 0;
            goto LAB_080b6de8;
          }
        }
        else {
          iVar10 = ssl3_get_key_exchange(param_1);
          if (0 < iVar10) {
            param_1->state = 0x1150;
            param_1->init_num = 0;
            iVar10 = ssl3_check_cert_and_algorithm(param_1);
            if (iVar10 == 0) goto LAB_080b7874;
LAB_080b7696:
            psVar11 = param_1->s3;
            uVar9 = 0;
            goto LAB_080b6de8;
          }
        }
      }
      else {
        if (iVar19 < 0x1150) {
LAB_080b7450:
          iVar19 = 0x2e2;
          iVar10 = 0xff;
          goto LAB_080b7462;
        }
        if (iVar19 < 0x1152) {
          iVar10 = ssl3_get_certificate_request(param_1);
          if (0 < iVar10) {
            param_1->state = 0x1160;
            param_1->init_num = 0;
            uVar9 = 0;
            psVar11 = param_1->s3;
            goto LAB_080b6de8;
          }
        }
        else {
          if (1 < iVar19 - 0x1160U) goto LAB_080b7450;
          iVar10 = ssl3_get_server_done(param_1);
          if (0 < iVar10) {
            dtls1_stop_timer(param_1);
            psVar11 = param_1->s3;
            iVar10 = (-(uint)((psVar11->tmp).cert_req == 0) & 0x10) + 0x1170;
            (psVar11->tmp).next_state = iVar10;
            param_1->state = iVar10;
            uVar9 = 0;
            param_1->init_num = 0;
            goto LAB_080b6de8;
          }
        }
      }
      goto LAB_080b6fba;
    }
    if (iVar19 < 0x1126) {
      if (iVar19 == 0x1100) {
        param_1->rwstate = 2;
        lVar13 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar13) {
          psVar11 = param_1->s3;
          param_1->rwstate = 1;
          param_1->state = (psVar11->tmp).next_state;
          uVar9 = 0;
          goto LAB_080b6de8;
        }
        iVar10 = BIO_test_flags(param_1->wbio,8);
        if (iVar10 == 0) {
          param_1->rwstate = 1;
          param_1->state = (param_1->s3->tmp).next_state;
          iVar10 = -1;
          goto LAB_080b6fba;
        }
        goto LAB_080b7874;
      }
      if (iVar19 < 0x1101) {
        if ((iVar19 == 0x1000) || (iVar19 == 0x1003)) goto LAB_080b721f;
        if (iVar19 == 3) {
          ssl3_cleanup_key_block(param_1);
          if ((*(byte *)&param_1->s3->flags & 4) == 0) {
            ssl_free_wbio_buffer(param_1);
          }
          param_1->init_num = 0;
          param_1->tlsext_hb_seq = 0;
          param_1->new_session = 0;
          ssl_update_cache(param_1,1);
          p_Var2 = param_1->psk_server_callback;
          if (param_1->hit != 0) {
            piVar8 = (int *)(p_Var2 + 0x58);
            *piVar8 = *piVar8 + 1;
          }
          param_1->handshake_func = dtls1_connect;
          piVar8 = (int *)(p_Var2 + 0x3c);
          *piVar8 = *piVar8 + 1;
          if (local_34 != (_func_3152 *)0x0) {
            (*local_34)(param_1,0x20,1);
          }
          pdVar16 = param_1->d1;
          pdVar16->handshake_read_seq = 0;
          pdVar16->next_handshake_write_seq = 0;
          iVar10 = 1;
          goto LAB_080b6fba;
        }
      }
      else if (0x110f < iVar19) {
        if (iVar19 < 0x1112) {
          param_1->shutdown = 0;
          ssl3_init_finished_mac(param_1);
          dtls1_start_timer(param_1);
          iVar10 = dtls1_client_hello(param_1);
          if (0 < iVar10) {
            if (param_1->d1->send_cookie == 0) {
              param_1->state = 0x1120;
            }
            else {
              param_1->state = 0x1100;
              (param_1->s3->tmp).next_state = 0x1120;
            }
            param_1->init_num = 0;
            if (param_1->bbio == param_1->wbio) goto LAB_080b7696;
            pBVar12 = BIO_push(param_1->bbio,param_1->wbio);
            param_1->wbio = pBVar12;
            uVar9 = 0;
            psVar11 = param_1->s3;
            goto LAB_080b6de8;
          }
        }
        else {
          if (1 < iVar19 - 0x1120U) goto LAB_080b7450;
          iVar10 = ssl3_get_server_hello(param_1);
          if (0 < iVar10) {
            param_1->init_num = 0;
            uVar9 = 0;
            param_1->state = (-(uint)(param_1->hit == 0) & 0xffffff56) + 0x11d0;
            psVar11 = param_1->s3;
            goto LAB_080b6de8;
          }
        }
        goto LAB_080b6fba;
      }
      goto LAB_080b7450;
    }
    local_24 = 0;
    iVar10 = (*param_1->method->ssl_get_message)(param_1,0x1126,0x1127,-1,param_1->mode,&local_24);
    if (local_24 == 0) {
      if (iVar10 < 1) goto LAB_080b6fba;
    }
    else {
      psVar11 = param_1->s3;
      if ((psVar11->tmp).message_type == 3) {
        pbVar7 = (byte *)param_1->init_msg;
        if (((uint)*pbVar7 != param_1->version >> 8) || (pbVar7[1] != (byte)param_1->version)) {
          ERR_put_error(0x14,0xfb,0x10a,"d1_clnt.c",0x3a4);
          param_1->version = (uint)pbVar7[1] | param_1->version & 0xff00U;
          ssl3_send_alert(param_1,2,0x46);
          iVar10 = -1;
          goto LAB_080b6fba;
        }
        bVar1 = pbVar7[2];
        uVar9 = (uint)bVar1;
        pdVar16 = param_1->d1;
        if (uVar9 < 4) {
          if (uVar9 != 0) {
            pdVar16->cookie[0] = pbVar7[3];
            if ((bVar1 & 2) == 0) goto LAB_080b7766;
            *(undefined2 *)(pdVar16->cookie + (uVar9 - 2)) = *(undefined2 *)(pbVar7 + uVar9 + 1);
            pdVar16 = param_1->d1;
          }
        }
        else {
          *(undefined4 *)pdVar16->cookie = *(undefined4 *)(pbVar7 + 3);
          puVar17 = (undefined4 *)((uint)(pdVar16->cookie + 4) & 0xfffffffc);
          *(undefined4 *)(pdVar16->cookie + (uVar9 - 4)) = *(undefined4 *)(pbVar7 + (uVar9 - 1));
          iVar10 = (int)pdVar16->cookie - (int)puVar17;
          puVar15 = (undefined4 *)(pbVar7 + (3 - iVar10));
          for (uVar14 = iVar10 + uVar9 >> 2; uVar14 != 0; uVar14 = uVar14 - 1) {
            *puVar17 = *puVar15;
            puVar15 = puVar15 + (uint)bVar18 * -2 + 1;
            puVar17 = puVar17 + (uint)bVar18 * -2 + 1;
          }
LAB_080b7766:
          pdVar16 = param_1->d1;
        }
        pdVar16->cookie_len = uVar9;
        pdVar16->send_cookie = 1;
      }
      else {
        param_1->d1->send_cookie = 0;
        (psVar11->tmp).reuse_message = 1;
      }
    }
    dtls1_stop_timer(param_1);
    uVar14 = param_1->d1->send_cookie;
    param_1->init_num = 0;
    uVar9 = 0;
    param_1->state = (-(uint)(uVar14 == 0) & 0x20) + 0x1110;
    psVar11 = param_1->s3;
LAB_080b6de8:
  } while ((uVar9 | (psVar11->tmp).reuse_message) != 0);
  if ((param_1->ctx != (SSL_CTX *)0x0) &&
     (iVar10 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar10 < 1)) goto LAB_080b6fba;
  if (local_34 == (_func_3152 *)0x0) {
    iVar10 = param_1->state;
  }
  else {
    iVar10 = param_1->state;
    if (iVar10 != iVar19) {
      param_1->state = iVar19;
      (*local_34)(param_1,0x1001,1);
      param_1->state = iVar10;
    }
  }
  goto joined_r0x080b6d51;
}

