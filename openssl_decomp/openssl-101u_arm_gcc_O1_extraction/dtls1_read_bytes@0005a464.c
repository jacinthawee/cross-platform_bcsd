
void dtls1_read_bytes(SSL *param_1,int param_2,uchar *param_3,uint param_4,int param_5)

{
  uchar uVar1;
  byte bVar2;
  pitem *item;
  uchar *puVar3;
  int iVar4;
  BIO *pBVar5;
  uint uVar6;
  dtls1_state_st *pdVar7;
  uchar *puVar8;
  SSL3_RECORD *pSVar9;
  uchar **ppuVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  uchar *puVar14;
  uchar **ppuVar15;
  uchar **ppuVar16;
  _func_3152 *p_Var17;
  uint uVar18;
  ssl3_state_st *psVar19;
  uchar **ppuVar20;
  undefined4 uVar21;
  uchar *puVar22;
  _func_3150 *p_Var23;
  uint *puVar24;
  ssl3_state_st *psVar25;
  ulong uVar26;
  _func_3152 *local_74;
  char local_68 [44];
  char acStack_3c [16];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar4 = ssl3_setup_buffers(), iVar4 == 0)) {
LAB_0005ab88:
    uVar13 = 0xffffffff;
    goto LAB_0005a5ba;
  }
  uVar13 = param_2 - 0x17;
  if (uVar13 != 0) {
    uVar13 = 1;
  }
  if (param_2 == 0 || param_2 == 0x17) {
    if (param_5 == 0) {
      uVar13 = 0;
    }
    else {
      uVar13 = uVar13 & 1;
    }
    if (uVar13 == 0) {
      if (param_2 == 0x16) goto LAB_0005a4bc;
LAB_0005a5e8:
      if ((param_1->in_handshake != 0) || (uVar13 = SSL_state(param_1), (uVar13 & 0x3000) == 0)) {
LAB_0005a5f0:
        local_74 = (_func_3152 *)0x0;
        psVar19 = param_1->s3;
LAB_0005a608:
        param_1->rwstate = 1;
        if (((param_1->state == 3) && ((psVar19->rrec).length == 0)) &&
           (item = pqueue_pop((param_1->d1->buffered_app_data).q), item != (pitem *)0x0)) {
          psVar25 = param_1->s3;
          ppuVar20 = (uchar **)item->data;
          puVar3 = (psVar25->rbuf).buf;
          if (puVar3 != (uchar *)0x0) {
            CRYPTO_free(puVar3);
            psVar25 = param_1->s3;
          }
          puVar3 = ppuVar20[1];
          param_1->packet = *ppuVar20;
          param_1->packet_length = (uint)puVar3;
          puVar22 = ppuVar20[3];
          puVar3 = ppuVar20[4];
          puVar8 = ppuVar20[5];
          (psVar25->rbuf).buf = ppuVar20[2];
          (psVar25->rbuf).len = (size_t)puVar22;
          (psVar25->rbuf).offset = (int)puVar3;
          (psVar25->rbuf).left = (int)puVar8;
          pSVar9 = &param_1->s3->rrec;
          ppuVar15 = ppuVar20 + 6;
          do {
            ppuVar16 = ppuVar15 + 4;
            puVar22 = ppuVar15[1];
            ppuVar10 = &pSVar9->input;
            puVar3 = ppuVar15[2];
            puVar8 = ppuVar15[3];
            pSVar9->type = (int)*ppuVar15;
            pSVar9->length = (uint)puVar22;
            pSVar9->off = (uint)puVar3;
            pSVar9->data = puVar8;
            pSVar9 = (SSL3_RECORD *)ppuVar10;
            ppuVar15 = ppuVar16;
          } while (ppuVar16 != ppuVar20 + 0xe);
          *ppuVar10 = *ppuVar16;
          puVar3 = *ppuVar20;
          psVar25 = param_1->s3;
          *(undefined4 *)(psVar25->read_sequence + 2) = *(undefined4 *)(puVar3 + 5);
          *(undefined2 *)(psVar25->read_sequence + 6) = *(undefined2 *)(puVar3 + 9);
          CRYPTO_free(item->data);
          pitem_free(item);
          iVar4 = dtls1_handle_timeout(param_1);
          if (0 < iVar4) goto LAB_0005a606;
LAB_0005a6c4:
          if ((((psVar19->rrec).length == 0) || (param_1->rstate == 0xf1)) &&
             (iVar4 = dtls1_get_record(param_1), iVar4 < 1)) {
            uVar13 = dtls1_read_failed(param_1);
            if (0 < (int)uVar13) goto LAB_0005a606;
            goto LAB_0005a5ba;
          }
          pdVar7 = param_1->d1;
          if ((pdVar7->mtu != 0) && ((psVar19->rrec).type != 0x16)) {
LAB_0005a6e0:
            (psVar19->rrec).length = 0;
            psVar19 = param_1->s3;
            goto LAB_0005a608;
          }
          psVar25 = param_1->s3;
          if ((psVar25->change_cipher_spec != 0) && ((psVar19->rrec).type != 0x16)) {
            iVar4 = dtls1_buffer_record_isra_6
                              (param_1,&(pdVar7->buffered_app_data).q,(psVar19->rrec).seq_num);
            if (-1 < iVar4) goto LAB_0005a6e0;
            iVar4 = 0x3ab;
            goto LAB_0005ab32;
          }
          uVar13 = param_1->shutdown & 2;
          if (uVar13 != 0) {
            (psVar19->rrec).length = 0;
            param_1->rwstate = 1;
            uVar13 = 0;
            goto LAB_0005a5ba;
          }
          iVar4 = (psVar19->rrec).type;
          if (iVar4 == param_2) {
            uVar13 = SSL_state(param_1);
            if ((((uVar13 & 0x3000) == 0) || (param_2 != 0x17)) ||
               (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) {
              uVar13 = param_4;
              if (0 < (int)param_4) {
                uVar13 = (psVar19->rrec).length;
                if (param_4 <= uVar13) {
                  uVar13 = param_4;
                }
                memcpy(param_3,(psVar19->rrec).data + (psVar19->rrec).off,uVar13);
                if (param_5 == 0) {
                  uVar6 = (psVar19->rrec).length - uVar13;
                  (psVar19->rrec).length = uVar6;
                  (psVar19->rrec).off = (psVar19->rrec).off + uVar13;
                  if (uVar6 == 0) {
                    param_1->rstate = 0xf0;
                    (psVar19->rrec).off = 0;
                  }
                }
              }
            }
            else {
              ERR_put_error(0x14,0x102,100,"d1_pkt.c",0x3c5);
              uVar12 = 10;
LAB_0005a9f2:
              ssl3_send_alert(param_1,2,uVar12);
              uVar13 = 0xffffffff;
            }
            goto LAB_0005a5ba;
          }
          if (iVar4 != 0x16) {
            if (iVar4 == 0x15) {
              puVar3 = pdVar7->handshake_fragment + 2;
              puVar24 = (uint *)(pdVar7->handshake_fragment + 4);
              uVar6 = 2;
              goto LAB_0005a7f2;
            }
            if (iVar4 == 0x18) {
              dtls1_process_heartbeat(param_1);
              (psVar19->rrec).length = 0;
              param_1->rwstate = 3;
              pBVar5 = SSL_get_rbio(param_1);
              BIO_clear_flags(pBVar5,0xf);
              pBVar5 = SSL_get_rbio(param_1);
              BIO_set_flags(pBVar5,9);
              uVar13 = 0xffffffff;
            }
            else {
              if (iVar4 == 0x14) goto LAB_0005a770;
              if (iVar4 != 0x17) {
                iVar4 = 0x42c;
LAB_0005ab68:
                ERR_put_error(0x14,0x102,0xf5,"d1_pkt.c",iVar4);
                uVar12 = 10;
                goto LAB_0005a9f2;
              }
              psVar25->in_read_app_data = 2;
              pBVar5 = SSL_get_rbio(param_1);
              param_1->rwstate = 3;
              BIO_clear_flags(pBVar5,0xf);
              BIO_set_flags(pBVar5,9);
              uVar13 = 0xffffffff;
            }
            goto LAB_0005a5ba;
          }
          puVar3 = pdVar7->handshake_fragment + 8;
          puVar24 = &pdVar7->change_cipher_spec_ok;
          uVar6 = 0xc;
LAB_0005a7f2:
          if ((psVar19->rrec).length < uVar6) {
            param_1->rstate = 0xf0;
            (psVar19->rrec).length = 0;
            psVar19 = psVar25;
            goto LAB_0005a608;
          }
          uVar18 = 0;
          do {
            uVar11 = (psVar19->rrec).off;
            (psVar19->rrec).off = uVar11 + 1;
            puVar3[uVar18] = (psVar19->rrec).data[uVar11];
            uVar18 = uVar18 + 1;
            (psVar19->rrec).length = (psVar19->rrec).length - 1;
          } while (uVar18 < uVar6);
          pdVar7 = param_1->d1;
          *puVar24 = uVar6;
LAB_0005a770:
          if (((param_1->server == 0) && (0xb < pdVar7->change_cipher_spec_ok)) &&
             ((pdVar7->handshake_fragment[8] == '\0' &&
              ((param_1->session != (SSL_SESSION *)0x0 &&
               (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)))))) {
            uVar13 = *(uint *)(pdVar7->handshake_fragment + 8);
            pdVar7->change_cipher_spec_ok = 0;
            if ((uVar13 & 0xffffff00) != 0) {
              ERR_put_error(0x14,0x102,0x69,"d1_pkt.c",0x45d);
              uVar12 = 0x32;
              goto LAB_0005a9f2;
            }
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,param_1->version,0x16,pdVar7->handshake_fragment + 8,4,param_1,
                         param_1->msg_callback_arg);
            }
            iVar4 = SSL_state(param_1);
            if (iVar4 == 3) {
              psVar19 = param_1->s3;
              if ((psVar19->flags << 0x1f < 0) || (psVar19->renegotiate != 0)) goto LAB_0005a608;
              param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
              param_1->new_session = 1;
              ssl3_renegotiate(param_1);
              iVar4 = ssl3_renegotiate_check(param_1);
              if (iVar4 == 0) goto LAB_0005a606;
              uVar13 = (*param_1->handshake_func)(param_1);
              if ((int)uVar13 < 0) goto LAB_0005a5ba;
              if (uVar13 == 0) {
                iVar4 = 0x476;
                goto LAB_0005a9be;
              }
              if (-1 < (int)(param_1->options << 0x1d)) {
                psVar19 = param_1->s3;
                if ((param_1->s3->rbuf).left == 0) {
                  param_1->rwstate = 3;
                  pBVar5 = SSL_get_rbio(param_1);
                  BIO_clear_flags(pBVar5,0xf);
                  BIO_set_flags(pBVar5,9);
                  uVar13 = 0xffffffff;
                  goto LAB_0005a5ba;
                }
                goto LAB_0005a608;
              }
            }
          }
          else {
            if (1 < *(uint *)(pdVar7->handshake_fragment + 4)) {
              p_Var23 = param_1->msg_callback;
              uVar1 = pdVar7->handshake_fragment[2];
              *(undefined4 *)(pdVar7->handshake_fragment + 4) = 0;
              bVar2 = pdVar7->handshake_fragment[3];
              uVar6 = (uint)bVar2;
              if (p_Var23 != (_func_3150 *)0x0) {
                (*p_Var23)(0,param_1->version,0x15,pdVar7->handshake_fragment + 2,2,param_1,
                           param_1->msg_callback_arg);
              }
              p_Var17 = param_1->info_callback;
              if (((param_1->info_callback != (_func_3152 *)0x0) ||
                  (p_Var17 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                  *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
                 (p_Var17 = local_74, local_74 != (_func_3152 *)0x0)) {
                (*p_Var17)(param_1,0x4004,(int)CONCAT11(uVar1,bVar2));
                local_74 = p_Var17;
              }
              if (uVar1 != '\x01') {
                if (uVar1 != '\x02') {
                  ERR_put_error(0x14,0x102,0xf6,"d1_pkt.c",0x4e6);
                  uVar12 = 0x2f;
                  goto LAB_0005a9f2;
                }
                param_1->rwstate = 1;
                param_1->s3->fatal_alert = uVar6;
                ERR_put_error(0x14,0x102,uVar6 + 1000,"d1_pkt.c",0x4de);
                BIO_snprintf(acStack_3c,0x10,"%d",uVar6);
                ERR_add_error_data(2,"SSL alert number ",acStack_3c);
                param_1->shutdown = param_1->shutdown | 2;
                SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
                goto LAB_0005a5ba;
              }
              psVar19 = param_1->s3;
              psVar19->warn_alert = uVar6;
              if (uVar6 == 0) goto code_r0x0005a7e8;
              goto LAB_0005a608;
            }
            if (param_1->shutdown << 0x1f < 0) {
              param_1->rwstate = 1;
              (psVar19->rrec).length = 0;
              goto LAB_0005a5ba;
            }
            iVar4 = (psVar19->rrec).type;
            if (iVar4 != 0x14) {
              if ((pdVar7->change_cipher_spec_ok < 0xc) || (param_1->in_handshake != 0)) {
                if (0x13 < iVar4) {
                  if (iVar4 < 0x17) {
                    ERR_put_error(0x14,0x102,0x44,"d1_pkt.c",0x588);
                    uVar12 = 10;
                    goto LAB_0005a9f2;
                  }
                  if (iVar4 == 0x17) {
                    psVar19 = param_1->s3;
                    if (((psVar19->in_read_app_data == 0) || (psVar19->total_renegotiations == 0))
                       || (((iVar4 = param_1->state, -1 < iVar4 << 0x13 || (0x10 < iVar4 - 0x1110U))
                           && ((-1 < iVar4 << 0x12 || (0x10 < iVar4 - 0x2110U)))))) {
                      iVar4 = 0x5a0;
                      goto LAB_0005ab68;
                    }
                    psVar19->in_read_app_data = 2;
                    uVar13 = 0xffffffff;
                    goto LAB_0005a5ba;
                  }
                }
                if (param_1->version == 0x301) goto LAB_0005a6e0;
                iVar4 = 0x57d;
                goto LAB_0005ab68;
              }
              dtls1_get_message_header((psVar19->rrec).data,local_68);
              if ((psVar19->rrec).epoch == (uint)param_1->d1->r_epoch) {
                if (local_68[0] != '\x14') {
                  if (((param_1->state & 0xfffU) == 3) && (-1 < param_1->s3->flags << 0x1f)) {
                    param_1->tlsext_hb_seq = 1;
                    if (param_1->server == 0) {
                      iVar4 = 0x1000;
                    }
                    else {
                      iVar4 = 0x2000;
                    }
                    param_1->new_session = 1;
                    param_1->state = iVar4;
                  }
                  uVar13 = (*param_1->handshake_func)(param_1);
                  if ((int)uVar13 < 0) goto LAB_0005a5ba;
                  if (uVar13 == 0) {
                    iVar4 = 0x55c;
                    goto LAB_0005a9be;
                  }
                  if ((int)(param_1->options << 0x1d) < 0) goto LAB_0005a606;
                  psVar19 = param_1->s3;
                  if ((param_1->s3->rbuf).left == 0) {
                    param_1->rwstate = 3;
                    pBVar5 = SSL_get_rbio(param_1);
                    BIO_clear_flags(pBVar5,0xf);
                    BIO_set_flags(pBVar5,9);
                    uVar13 = 0xffffffff;
                    goto LAB_0005a5ba;
                  }
                  goto LAB_0005a608;
                }
                iVar4 = dtls1_check_timeout_num(param_1);
                if (iVar4 < 0) goto LAB_0005ab88;
                dtls1_retransmit_buffered_messages(param_1);
              }
              (psVar19->rrec).length = 0;
              psVar19 = param_1->s3;
              goto LAB_0005a608;
            }
            dtls1_get_ccs_header((psVar19->rrec).data,local_68);
            iVar4 = param_1->version;
            if (iVar4 == 0x100) {
              uVar13 = 3;
            }
            else {
              uVar13 = 1;
            }
            if ((((psVar19->rrec).length != uVar13) || ((psVar19->rrec).off != 0)) ||
               (puVar3 = (psVar19->rrec).data, *puVar3 != '\x01')) {
              ERR_put_error(0x14,0x102,0x67,"d1_pkt.c",0x505);
              goto LAB_0005ab88;
            }
            p_Var23 = param_1->msg_callback;
            (psVar19->rrec).length = 0;
            if (p_Var23 != (_func_3150 *)0x0) {
              (*p_Var23)(0,iVar4,0x14,puVar3,1,param_1,param_1->msg_callback_arg);
            }
            if (param_1->d1[1].send_cookie == 0) goto LAB_0005a606;
            psVar19 = param_1->s3;
            param_1->d1[1].send_cookie = 0;
            psVar19->change_cipher_spec = 1;
            iVar4 = ssl3_do_change_cipher_spec(param_1);
            if (iVar4 == 0) goto LAB_0005ab88;
            pdVar7 = param_1->d1;
            psVar19 = param_1->s3;
            uVar26 = (pdVar7->next_bitmap).map;
            uVar12 = *(undefined4 *)((pdVar7->next_bitmap).max_seq_num + 4);
            pdVar7->r_epoch = pdVar7->r_epoch + 1;
            uVar21 = *(undefined4 *)(pdVar7->next_bitmap).max_seq_num;
            (pdVar7->bitmap).map = uVar26;
            *(undefined4 *)((pdVar7->bitmap).max_seq_num + 4) = uVar12;
            *(undefined4 *)(pdVar7->bitmap).max_seq_num = uVar21;
            pdVar7 = param_1->d1;
            *(undefined *)&(pdVar7->next_bitmap).map = 0;
            *(undefined *)((int)&(pdVar7->next_bitmap).map + 1) = 0;
            *(undefined *)((int)&(pdVar7->next_bitmap).map + 2) = 0;
            *(undefined *)((int)&(pdVar7->next_bitmap).map + 3) = 0;
            (pdVar7->next_bitmap).max_seq_num[0] = '\0';
            (pdVar7->next_bitmap).max_seq_num[1] = '\0';
            (pdVar7->next_bitmap).max_seq_num[2] = '\0';
            (pdVar7->next_bitmap).max_seq_num[3] = '\0';
            (pdVar7->next_bitmap).max_seq_num[4] = '\0';
            (pdVar7->next_bitmap).max_seq_num[5] = '\0';
            (pdVar7->next_bitmap).max_seq_num[6] = '\0';
            (pdVar7->next_bitmap).max_seq_num[7] = '\0';
            dtls1_clear_received_buffer(param_1);
            psVar19->read_sequence[0] = '\0';
            psVar19->read_sequence[1] = '\0';
            psVar19->read_sequence[2] = '\0';
            psVar19->read_sequence[3] = '\0';
            psVar19->read_sequence[4] = '\0';
            psVar19->read_sequence[5] = '\0';
            psVar19->read_sequence[6] = '\0';
            psVar19->read_sequence[7] = '\0';
            if (param_1->version == 0x100) {
              param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
            }
          }
        }
        else {
          iVar4 = dtls1_handle_timeout(param_1);
          if (iVar4 < 1) goto LAB_0005a6c4;
        }
LAB_0005a606:
        psVar19 = param_1->s3;
        goto LAB_0005a608;
      }
      uVar13 = (*param_1->handshake_func)(param_1);
      if (-1 < (int)uVar13) {
        if (uVar13 != 0) goto LAB_0005a5f0;
        iVar4 = 0x361;
LAB_0005a9be:
        ERR_put_error(0x14,0x102,0xe5,"d1_pkt.c",iVar4);
        uVar13 = 0xffffffff;
      }
      goto LAB_0005a5ba;
    }
  }
  else if (param_2 == 0x16) {
    if (param_5 == 0) {
      uVar13 = 0;
    }
    else {
      uVar13 = uVar13 & 1;
    }
    if (uVar13 == 0) {
LAB_0005a4bc:
      pdVar7 = param_1->d1;
      if (pdVar7->change_cipher_spec_ok != 0) {
        puVar3 = pdVar7->handshake_fragment + 8;
        if ((int)param_4 < 1) {
          uVar13 = 0;
LAB_0005a502:
          pdVar7->handshake_fragment[8] = *puVar3;
          if (1 < param_1->d1->change_cipher_spec_ok) {
            param_1->d1->handshake_fragment[9] = puVar3[1];
            if (2 < param_1->d1->change_cipher_spec_ok) {
              param_1->d1->handshake_fragment[10] = puVar3[2];
              if (3 < param_1->d1->change_cipher_spec_ok) {
                param_1->d1->handshake_fragment[0xb] = puVar3[3];
                if (4 < param_1->d1->change_cipher_spec_ok) {
                  *(uchar *)&param_1->d1->handshake_fragment_len = puVar3[4];
                  if (5 < param_1->d1->change_cipher_spec_ok) {
                    *(uchar *)((int)&param_1->d1->handshake_fragment_len + 1) = puVar3[5];
                    if (6 < param_1->d1->change_cipher_spec_ok) {
                      *(uchar *)((int)&param_1->d1->handshake_fragment_len + 2) = puVar3[6];
                      if (7 < param_1->d1->change_cipher_spec_ok) {
                        *(uchar *)((int)&param_1->d1->handshake_fragment_len + 3) = puVar3[7];
                        if (8 < param_1->d1->change_cipher_spec_ok) {
                          *(uchar *)&param_1->d1->retransmitting = puVar3[8];
                          if (9 < param_1->d1->change_cipher_spec_ok) {
                            *(uchar *)((int)&param_1->d1->retransmitting + 1) = puVar3[9];
                            if (10 < param_1->d1->change_cipher_spec_ok) {
                              *(uchar *)((int)&param_1->d1->retransmitting + 2) = puVar3[10];
                              if (0xb < param_1->d1->change_cipher_spec_ok) {
                                *(uchar *)((int)&param_1->d1->retransmitting + 3) = puVar3[0xb];
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else {
          puVar8 = param_3;
          puVar22 = puVar3;
          do {
            puVar14 = puVar22 + 1;
            uVar13 = (int)puVar14 - (int)puVar3;
            *puVar8 = *puVar22;
            pdVar7 = param_1->d1;
            uVar6 = pdVar7->change_cipher_spec_ok - 1;
            pdVar7->change_cipher_spec_ok = uVar6;
            if (puVar14 == puVar3 + param_4) {
              puVar3 = puVar14;
              if (uVar6 != 0) goto LAB_0005a502;
              break;
            }
            puVar8 = puVar8 + 1;
            puVar22 = puVar14;
          } while (uVar6 != 0);
        }
        if (uVar13 != 0) goto LAB_0005a5ba;
      }
      goto LAB_0005a5e8;
    }
  }
  iVar4 = 0x340;
LAB_0005ab32:
  ERR_put_error(0x14,0x102,0x44,"d1_pkt.c",iVar4);
  uVar13 = 0xffffffff;
LAB_0005a5ba:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
code_r0x0005a7e8:
  param_1->shutdown = param_1->shutdown | 2;
  goto LAB_0005a5ba;
}

