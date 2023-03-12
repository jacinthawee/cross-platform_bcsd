
void dtls1_read_bytes(SSL *param_1,int param_2,uchar *param_3,uint param_4,int param_5)

{
  char cVar1;
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
  undefined4 uVar20;
  uchar **ppuVar21;
  ulong uVar22;
  uchar *puVar23;
  _func_3150 *p_Var24;
  uint *puVar25;
  ssl3_state_st *psVar26;
  _func_3152 *local_74;
  char local_68 [44];
  char acStack_3c [16];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar4 = ssl3_setup_buffers(), iVar4 == 0)) {
LAB_0005cfc8:
    uVar13 = 0xffffffff;
    goto LAB_0005ca06;
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
      if (param_2 == 0x16) goto LAB_0005c908;
LAB_0005ca34:
      if ((param_1->in_handshake != 0) || (uVar13 = SSL_state(param_1), (uVar13 & 0x3000) == 0)) {
LAB_0005ca3c:
        local_74 = (_func_3152 *)0x0;
        psVar19 = param_1->s3;
LAB_0005ca54:
        param_1->rwstate = 1;
        if (((param_1->state == 3) && ((psVar19->rrec).length == 0)) &&
           (item = pqueue_pop((param_1->d1->buffered_app_data).q), item != (pitem *)0x0)) {
          psVar26 = param_1->s3;
          ppuVar21 = (uchar **)item->data;
          puVar3 = (psVar26->rbuf).buf;
          if (puVar3 != (uchar *)0x0) {
            CRYPTO_free(puVar3);
            psVar26 = param_1->s3;
          }
          puVar3 = ppuVar21[1];
          param_1->packet = *ppuVar21;
          param_1->packet_length = (uint)puVar3;
          puVar23 = ppuVar21[3];
          puVar3 = ppuVar21[4];
          puVar8 = ppuVar21[5];
          (psVar26->rbuf).buf = ppuVar21[2];
          (psVar26->rbuf).len = (size_t)puVar23;
          (psVar26->rbuf).offset = (int)puVar3;
          (psVar26->rbuf).left = (int)puVar8;
          pSVar9 = &param_1->s3->rrec;
          ppuVar15 = ppuVar21 + 6;
          do {
            ppuVar16 = ppuVar15 + 4;
            puVar23 = ppuVar15[1];
            ppuVar10 = &pSVar9->input;
            puVar3 = ppuVar15[2];
            puVar8 = ppuVar15[3];
            pSVar9->type = (int)*ppuVar15;
            pSVar9->length = (uint)puVar23;
            pSVar9->off = (uint)puVar3;
            pSVar9->data = puVar8;
            pSVar9 = (SSL3_RECORD *)ppuVar10;
            ppuVar15 = ppuVar16;
          } while (ppuVar16 != ppuVar21 + 0xe);
          *ppuVar10 = *ppuVar16;
          puVar3 = *ppuVar21;
          psVar26 = param_1->s3;
          *(undefined4 *)(psVar26->read_sequence + 2) = *(undefined4 *)(puVar3 + 5);
          *(undefined2 *)(psVar26->read_sequence + 6) = *(undefined2 *)(puVar3 + 9);
          CRYPTO_free(item->data);
          pitem_free(item);
          iVar4 = dtls1_handle_timeout(param_1);
          if (0 < iVar4) goto LAB_0005ca52;
LAB_0005cb10:
          if ((((psVar19->rrec).length == 0) || (param_1->rstate == 0xf1)) &&
             (iVar4 = dtls1_get_record(param_1), iVar4 < 1)) {
            uVar13 = dtls1_read_failed(param_1);
            if (0 < (int)uVar13) goto LAB_0005ca52;
            goto LAB_0005ca06;
          }
          pdVar7 = param_1->d1;
          if ((pdVar7->mtu != 0) && ((psVar19->rrec).type != 0x16)) {
LAB_0005cb2c:
            (psVar19->rrec).length = 0;
            psVar19 = param_1->s3;
            goto LAB_0005ca54;
          }
          psVar26 = param_1->s3;
          if ((psVar26->change_cipher_spec != 0) && ((psVar19->rrec).type != 0x16)) {
            dtls1_buffer_record_isra_6
                      (param_1,&(pdVar7->buffered_app_data).q,(psVar19->rrec).seq_num);
            (psVar19->rrec).length = 0;
            psVar19 = param_1->s3;
            goto LAB_0005ca54;
          }
          uVar13 = param_1->shutdown & 2;
          if (uVar13 != 0) {
            (psVar19->rrec).length = 0;
            param_1->rwstate = 1;
            uVar13 = 0;
            goto LAB_0005ca06;
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
              ERR_put_error(0x14,0x102,100,"d1_pkt.c",0x37a);
              uVar12 = 10;
LAB_0005cf92:
              ssl3_send_alert(param_1,2,uVar12);
              uVar13 = 0xffffffff;
            }
            goto LAB_0005ca06;
          }
          if (iVar4 != 0x16) {
            if (iVar4 == 0x15) {
              puVar3 = (uchar *)((int)&pdVar7->alert_fragment_len + 2);
              puVar25 = (uint *)pdVar7->handshake_fragment;
              uVar6 = 2;
              goto LAB_0005cc38;
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
              if (iVar4 == 0x14) goto LAB_0005cbb6;
              if (iVar4 != 0x17) {
                iVar4 = 0x3e4;
LAB_0005cfa8:
                ERR_put_error(0x14,0x102,0xf5,"d1_pkt.c",iVar4);
                uVar12 = 10;
                goto LAB_0005cf92;
              }
              psVar26->in_read_app_data = 2;
              pBVar5 = SSL_get_rbio(param_1);
              param_1->rwstate = 3;
              BIO_clear_flags(pBVar5,0xf);
              BIO_set_flags(pBVar5,9);
              uVar13 = 0xffffffff;
            }
            goto LAB_0005ca06;
          }
          puVar3 = pdVar7->handshake_fragment + 4;
          puVar25 = &pdVar7->retransmitting;
          uVar6 = 0xc;
LAB_0005cc38:
          if ((psVar19->rrec).length < uVar6) {
            param_1->rstate = 0xf0;
            (psVar19->rrec).length = 0;
            psVar19 = psVar26;
            goto LAB_0005ca54;
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
          *puVar25 = uVar6;
LAB_0005cbb6:
          if (((param_1->server == 0) && (0xb < pdVar7->retransmitting)) &&
             ((pdVar7->handshake_fragment[4] == '\0' &&
              ((param_1->session != (SSL_SESSION *)0x0 &&
               (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)))))) {
            uVar13 = *(uint *)(pdVar7->handshake_fragment + 4);
            pdVar7->retransmitting = 0;
            if ((uVar13 & 0xffffff00) != 0) {
              ERR_put_error(0x14,0x102,0x69,"d1_pkt.c",0x416);
              uVar13 = 0xffffffff;
              goto LAB_0005ca06;
            }
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,param_1->version,0x16,pdVar7->handshake_fragment + 4,4,param_1,
                         param_1->msg_callback_arg);
            }
            iVar4 = SSL_state(param_1);
            if (iVar4 == 3) {
              psVar19 = param_1->s3;
              if ((psVar19->flags << 0x1f < 0) || (psVar19->renegotiate != 0)) goto LAB_0005ca54;
              param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
              param_1->new_session = 1;
              ssl3_renegotiate(param_1);
              iVar4 = ssl3_renegotiate_check(param_1);
              if (iVar4 == 0) goto LAB_0005ca52;
              uVar13 = (*param_1->handshake_func)(param_1);
              if ((int)uVar13 < 0) goto LAB_0005ca06;
              if (uVar13 == 0) {
                iVar4 = 0x42d;
                goto LAB_0005ce04;
              }
              if (-1 < (int)(param_1->options << 0x1d)) {
                psVar19 = param_1->s3;
                if ((param_1->s3->rbuf).left == 0) {
                  param_1->rwstate = 3;
                  pBVar5 = SSL_get_rbio(param_1);
                  BIO_clear_flags(pBVar5,0xf);
                  BIO_set_flags(pBVar5,9);
                  uVar13 = 0xffffffff;
                  goto LAB_0005ca06;
                }
                goto LAB_0005ca54;
              }
            }
          }
          else {
            if (1 < *(uint *)pdVar7->handshake_fragment) {
              p_Var24 = param_1->msg_callback;
              cVar1 = *(char *)((int)&pdVar7->alert_fragment_len + 2);
              *(undefined4 *)pdVar7->handshake_fragment = 0;
              bVar2 = *(byte *)((int)&pdVar7->alert_fragment_len + 3);
              uVar6 = (uint)bVar2;
              if (p_Var24 != (_func_3150 *)0x0) {
                (*p_Var24)(0,param_1->version,0x15,(void *)((int)&pdVar7->alert_fragment_len + 2),2,
                           param_1,param_1->msg_callback_arg);
              }
              p_Var17 = param_1->info_callback;
              if (((param_1->info_callback != (_func_3152 *)0x0) ||
                  (p_Var17 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                  *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
                 (p_Var17 = local_74, local_74 != (_func_3152 *)0x0)) {
                (*p_Var17)(param_1,0x4004,(int)CONCAT11(cVar1,bVar2));
                local_74 = p_Var17;
              }
              if (cVar1 != '\x01') {
                if (cVar1 != '\x02') {
                  ERR_put_error(0x14,0x102,0xf6,"d1_pkt.c",0x49f);
                  uVar12 = 0x2f;
                  goto LAB_0005cf92;
                }
                param_1->rwstate = 1;
                param_1->s3->fatal_alert = uVar6;
                ERR_put_error(0x14,0x102,uVar6 + 1000,"d1_pkt.c",0x495);
                BIO_snprintf(acStack_3c,0x10,"%d",uVar6);
                ERR_add_error_data(2,"SSL alert number ",acStack_3c);
                param_1->shutdown = param_1->shutdown | 2;
                SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
                goto LAB_0005ca06;
              }
              psVar19 = param_1->s3;
              psVar19->warn_alert = uVar6;
              if (uVar6 == 0) goto code_r0x0005cc2e;
              goto LAB_0005ca54;
            }
            if (param_1->shutdown << 0x1f < 0) {
              param_1->rwstate = 1;
              (psVar19->rrec).length = 0;
              goto LAB_0005ca06;
            }
            iVar4 = (psVar19->rrec).type;
            if (iVar4 != 0x14) {
              if ((pdVar7->retransmitting < 0xc) || (param_1->in_handshake != 0)) {
                if (0x13 < iVar4) {
                  if (iVar4 < 0x17) {
                    ERR_put_error(0x14,0x102,0x44,"d1_pkt.c",0x542);
                    uVar12 = 10;
                    goto LAB_0005cf92;
                  }
                  if (iVar4 == 0x17) {
                    psVar19 = param_1->s3;
                    if (((psVar19->in_read_app_data == 0) || (psVar19->total_renegotiations == 0))
                       || (((iVar4 = param_1->state, -1 < iVar4 << 0x13 || (0x10 < iVar4 - 0x1110U))
                           && ((-1 < iVar4 << 0x12 || (0x10 < iVar4 - 0x2110U)))))) {
                      iVar4 = 0x55f;
                      goto LAB_0005cfa8;
                    }
                    psVar19->in_read_app_data = 2;
                    uVar13 = 0xffffffff;
                    goto LAB_0005ca06;
                  }
                }
                if (param_1->version == 0x301) goto LAB_0005cb2c;
                iVar4 = 0x539;
                goto LAB_0005cfa8;
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
                  if ((int)uVar13 < 0) goto LAB_0005ca06;
                  if (uVar13 == 0) {
                    iVar4 = 0x516;
                    goto LAB_0005ce04;
                  }
                  if ((int)(param_1->options << 0x1d) < 0) goto LAB_0005ca52;
                  psVar19 = param_1->s3;
                  if ((param_1->s3->rbuf).left == 0) {
                    param_1->rwstate = 3;
                    pBVar5 = SSL_get_rbio(param_1);
                    BIO_clear_flags(pBVar5,0xf);
                    BIO_set_flags(pBVar5,9);
                    uVar13 = 0xffffffff;
                    goto LAB_0005ca06;
                  }
                  goto LAB_0005ca54;
                }
                iVar4 = dtls1_check_timeout_num(param_1);
                if (iVar4 < 0) goto LAB_0005cfc8;
                dtls1_retransmit_buffered_messages(param_1);
              }
              (psVar19->rrec).length = 0;
              psVar19 = param_1->s3;
              goto LAB_0005ca54;
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
              ERR_put_error(0x14,0x102,0x67,"d1_pkt.c",0x4be);
              goto LAB_0005cfc8;
            }
            p_Var24 = param_1->msg_callback;
            (psVar19->rrec).length = 0;
            if (p_Var24 != (_func_3150 *)0x0) {
              (*p_Var24)(0,iVar4,0x14,puVar3,1,param_1,param_1->msg_callback_arg);
            }
            if (param_1->d1->listen == 0) goto LAB_0005ca52;
            psVar19 = param_1->s3;
            param_1->d1->listen = 0;
            psVar19->change_cipher_spec = 1;
            iVar4 = ssl3_do_change_cipher_spec(param_1);
            if (iVar4 == 0) goto LAB_0005cfc8;
            pdVar7 = param_1->d1;
            psVar19 = param_1->s3;
            uVar22 = (pdVar7->next_bitmap).map;
            uVar12 = *(undefined4 *)((pdVar7->next_bitmap).max_seq_num + 4);
            pdVar7->r_epoch = pdVar7->r_epoch + 1;
            uVar20 = *(undefined4 *)(pdVar7->next_bitmap).max_seq_num;
            (pdVar7->bitmap).map = uVar22;
            *(undefined4 *)((pdVar7->bitmap).max_seq_num + 4) = uVar12;
            *(undefined4 *)(pdVar7->bitmap).max_seq_num = uVar20;
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
          if (iVar4 < 1) goto LAB_0005cb10;
        }
LAB_0005ca52:
        psVar19 = param_1->s3;
        goto LAB_0005ca54;
      }
      uVar13 = (*param_1->handshake_func)(param_1);
      if (-1 < (int)uVar13) {
        if (uVar13 != 0) goto LAB_0005ca3c;
        iVar4 = 0x317;
LAB_0005ce04:
        ERR_put_error(0x14,0x102,0xe5,"d1_pkt.c",iVar4);
        uVar13 = 0xffffffff;
      }
      goto LAB_0005ca06;
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
LAB_0005c908:
      pdVar7 = param_1->d1;
      if (pdVar7->retransmitting != 0) {
        puVar3 = pdVar7->handshake_fragment + 4;
        if ((int)param_4 < 1) {
          uVar13 = 0;
LAB_0005c94e:
          pdVar7->handshake_fragment[4] = *puVar3;
          if (1 < param_1->d1->retransmitting) {
            param_1->d1->handshake_fragment[5] = puVar3[1];
            if (2 < param_1->d1->retransmitting) {
              param_1->d1->handshake_fragment[6] = puVar3[2];
              if (3 < param_1->d1->retransmitting) {
                param_1->d1->handshake_fragment[7] = puVar3[3];
                if (4 < param_1->d1->retransmitting) {
                  param_1->d1->handshake_fragment[8] = puVar3[4];
                  if (5 < param_1->d1->retransmitting) {
                    param_1->d1->handshake_fragment[9] = puVar3[5];
                    if (6 < param_1->d1->retransmitting) {
                      param_1->d1->handshake_fragment[10] = puVar3[6];
                      if (7 < param_1->d1->retransmitting) {
                        param_1->d1->handshake_fragment[0xb] = puVar3[7];
                        if (8 < param_1->d1->retransmitting) {
                          *(uchar *)&param_1->d1->handshake_fragment_len = puVar3[8];
                          if (9 < param_1->d1->retransmitting) {
                            *(uchar *)((int)&param_1->d1->handshake_fragment_len + 1) = puVar3[9];
                            if (10 < param_1->d1->retransmitting) {
                              *(uchar *)((int)&param_1->d1->handshake_fragment_len + 2) = puVar3[10]
                              ;
                              if (0xb < param_1->d1->retransmitting) {
                                *(uchar *)((int)&param_1->d1->handshake_fragment_len + 3) =
                                     puVar3[0xb];
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
          puVar23 = puVar3;
          do {
            puVar14 = puVar23 + 1;
            uVar13 = (int)puVar14 - (int)puVar3;
            *puVar8 = *puVar23;
            pdVar7 = param_1->d1;
            uVar6 = pdVar7->retransmitting - 1;
            pdVar7->retransmitting = uVar6;
            if (puVar14 == puVar3 + param_4) {
              puVar3 = puVar14;
              if (uVar6 != 0) goto LAB_0005c94e;
              break;
            }
            puVar8 = puVar8 + 1;
            puVar23 = puVar14;
          } while (uVar6 != 0);
        }
        if (uVar13 != 0) goto LAB_0005ca06;
      }
      goto LAB_0005ca34;
    }
  }
  ERR_put_error(0x14,0x102,0x44,"d1_pkt.c",0x2fc);
  uVar13 = 0xffffffff;
LAB_0005ca06:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
code_r0x0005cc2e:
  param_1->shutdown = param_1->shutdown | 2;
  goto LAB_0005ca06;
}

