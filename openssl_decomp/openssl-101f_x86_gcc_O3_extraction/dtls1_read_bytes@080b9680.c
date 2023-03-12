
size_t dtls1_read_bytes(SSL *param_1,int param_2,void *param_3,uint param_4,int param_5)

{
  uint *puVar1;
  ushort *puVar2;
  char cVar3;
  short sVar4;
  uchar **ppuVar5;
  uchar *puVar6;
  uint uVar7;
  _func_3150 *p_Var8;
  ulong uVar9;
  uint uVar10;
  pitem *item;
  ssl3_state_st *psVar11;
  int iVar12;
  dtls1_state_st *pdVar13;
  BIO *pBVar14;
  undefined4 uVar15;
  uchar *puVar16;
  _func_3152 *p_Var18;
  ssl3_state_st *psVar19;
  int in_GS_OFFSET;
  int iVar20;
  SSL_CTX *pSVar21;
  uint local_6c;
  uint *local_68;
  _func_3152 *local_64;
  char local_5c [44];
  char local_30 [16];
  int local_20;
  uchar *puVar17;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) &&
     (iVar12 = ssl3_setup_buffers(param_1), iVar12 == 0)) {
LAB_080b9e77:
    local_6c = 0xffffffff;
    goto LAB_080b9e80;
  }
  if ((param_2 == 0) || (param_2 == 0x17)) {
    if ((param_5 == 0) || (param_2 == 0x17)) {
      if (param_2 == 0x16) goto LAB_080b96e6;
      goto LAB_080b988a;
    }
LAB_080b9fc8:
    iVar20 = 0x2fc;
    iVar12 = 0x44;
  }
  else {
    if ((param_2 != 0x16) || (param_5 != 0)) goto LAB_080b9fc8;
LAB_080b96e6:
    pdVar13 = param_1->d1;
    if (pdVar13->retransmitting != 0) {
      puVar16 = pdVar13->handshake_fragment + 4;
      if ((int)param_4 < 1) {
        local_6c = 0;
LAB_080b9752:
        pdVar13->handshake_fragment[4] = *puVar16;
        if (1 < param_1->d1->retransmitting) {
          param_1->d1->handshake_fragment[5] = puVar16[1];
          if (2 < param_1->d1->retransmitting) {
            param_1->d1->handshake_fragment[6] = puVar16[2];
            if (3 < param_1->d1->retransmitting) {
              param_1->d1->handshake_fragment[7] = puVar16[3];
              if (4 < param_1->d1->retransmitting) {
                param_1->d1->handshake_fragment[8] = puVar16[4];
                if (5 < param_1->d1->retransmitting) {
                  param_1->d1->handshake_fragment[9] = puVar16[5];
                  if (6 < param_1->d1->retransmitting) {
                    param_1->d1->handshake_fragment[10] = puVar16[6];
                    if (7 < param_1->d1->retransmitting) {
                      param_1->d1->handshake_fragment[0xb] = puVar16[7];
                      if (8 < param_1->d1->retransmitting) {
                        *(uchar *)&param_1->d1->handshake_fragment_len = puVar16[8];
                        if (9 < param_1->d1->retransmitting) {
                          *(uchar *)((int)&param_1->d1->handshake_fragment_len + 1) = puVar16[9];
                          if (10 < param_1->d1->retransmitting) {
                            *(uchar *)((int)&param_1->d1->handshake_fragment_len + 2) = puVar16[10];
                            if (0xb < param_1->d1->retransmitting) {
                              *(uchar *)((int)&param_1->d1->handshake_fragment_len + 3) =
                                   puVar16[0xb];
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
        local_6c = 0;
        puVar17 = puVar16;
        do {
          puVar16 = puVar17 + 1;
          *(uchar *)((int)param_3 + local_6c) = *puVar17;
          pdVar13 = param_1->d1;
          local_6c = local_6c + 1;
          uVar10 = pdVar13->retransmitting - 1;
          pdVar13->retransmitting = uVar10;
          if (local_6c == param_4) {
            if (uVar10 == 0) goto LAB_080b9e80;
            local_6c = param_4;
            goto LAB_080b9752;
          }
          puVar17 = puVar16;
        } while (uVar10 != 0);
      }
      if (local_6c != 0) goto LAB_080b9e80;
    }
LAB_080b988a:
    if ((param_1->in_handshake != 0) || (uVar10 = SSL_state(param_1), (uVar10 & 0x3000) == 0)) {
LAB_080b9895:
      local_64 = (_func_3152 *)0x0;
      psVar19 = param_1->s3;
LAB_080b98bf:
      param_1->rwstate = 1;
      if (((param_1->state == 3) && ((psVar19->rrec).length == 0)) &&
         (item = pqueue_pop((param_1->d1->buffered_app_data).q), item != (pitem *)0x0)) {
        ppuVar5 = (uchar **)item->data;
        psVar11 = param_1->s3;
        puVar16 = (psVar11->rbuf).buf;
        if (puVar16 != (uchar *)0x0) {
          CRYPTO_free(puVar16);
          psVar11 = param_1->s3;
        }
        param_1->packet = *ppuVar5;
        param_1->packet_length = (uint)ppuVar5[1];
        puVar16 = ppuVar5[5];
        puVar17 = ppuVar5[3];
        puVar6 = ppuVar5[2];
        (psVar11->rbuf).offset = (int)ppuVar5[4];
        (psVar11->rbuf).len = (size_t)puVar17;
        (psVar11->rbuf).buf = puVar6;
        (psVar11->rbuf).left = (int)puVar16;
        psVar11 = param_1->s3;
        (psVar11->rrec).type = (int)ppuVar5[6];
        (psVar11->rrec).length = (uint)ppuVar5[7];
        (psVar11->rrec).off = (uint)ppuVar5[8];
        (psVar11->rrec).data = ppuVar5[9];
        (psVar11->rrec).input = ppuVar5[10];
        (psVar11->rrec).comp = ppuVar5[0xb];
        (psVar11->rrec).epoch = (ulong)ppuVar5[0xc];
        *(uchar **)(psVar11->rrec).seq_num = ppuVar5[0xd];
        *(uchar **)((psVar11->rrec).seq_num + 4) = ppuVar5[0xe];
        puVar16 = *ppuVar5;
        psVar11 = param_1->s3;
        *(undefined4 *)(psVar11->read_sequence + 2) = *(undefined4 *)(puVar16 + 5);
        *(undefined2 *)(psVar11->read_sequence + 6) = *(undefined2 *)(puVar16 + 9);
        CRYPTO_free(item->data);
        pitem_free(item);
        iVar12 = dtls1_handle_timeout(param_1);
        if (0 < iVar12) goto LAB_080b98bc;
LAB_080b99d0:
        if ((((psVar19->rrec).length == 0) || (param_1->rstate == 0xf1)) &&
           (iVar12 = dtls1_get_record(param_1), iVar12 < 1)) {
          local_6c = dtls1_read_failed(param_1,iVar12);
          if (0 < (int)local_6c) goto LAB_080b98bc;
          goto LAB_080b9e80;
        }
        pdVar13 = param_1->d1;
        if (pdVar13->mtu != 0) {
          if ((psVar19->rrec).type == 0x16) {
            psVar11 = param_1->s3;
            goto LAB_080b9a83;
          }
LAB_080b99fd:
          (psVar19->rrec).length = 0;
          psVar19 = param_1->s3;
          goto LAB_080b98bf;
        }
        psVar11 = param_1->s3;
        if ((psVar11->change_cipher_spec != 0) && ((psVar19->rrec).type != 0x16)) {
          dtls1_buffer_record_isra_6();
          (psVar19->rrec).length = 0;
          psVar19 = param_1->s3;
          goto LAB_080b98bf;
        }
LAB_080b9a83:
        local_6c = param_1->shutdown & 2;
        if (local_6c != 0) {
          (psVar19->rrec).length = 0;
          local_6c = 0;
          param_1->rwstate = 1;
          goto LAB_080b9e80;
        }
        iVar12 = (psVar19->rrec).type;
        if (param_2 == iVar12) {
          uVar10 = SSL_state(param_1);
          if ((((uVar10 & 0x3000) == 0) || (param_2 != 0x17)) ||
             (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) {
            if ((int)param_4 < 1) {
              local_6c = param_4;
            }
            else {
              local_6c = (psVar19->rrec).length;
              if (param_4 < local_6c) {
                local_6c = param_4;
              }
              memcpy(param_3,(psVar19->rrec).data + (psVar19->rrec).off,local_6c);
              if (param_5 == 0) {
                puVar1 = &(psVar19->rrec).off;
                *puVar1 = *puVar1 + local_6c;
                uVar10 = (psVar19->rrec).length - local_6c;
                (psVar19->rrec).length = uVar10;
                if (uVar10 == 0) {
                  param_1->rstate = 0xf0;
                  (psVar19->rrec).off = 0;
                }
              }
            }
          }
          else {
            iVar20 = 0x37a;
            iVar12 = 100;
LAB_080ba23f:
            ERR_put_error(0x14,0x102,iVar12,"d1_pkt.c",iVar20);
            uVar15 = 10;
LAB_080ba253:
            ssl3_send_alert(param_1,2,uVar15);
            local_6c = 0xffffffff;
          }
          goto LAB_080b9e80;
        }
        if (iVar12 != 0x16) {
          if (iVar12 == 0x15) {
            puVar16 = (uchar *)((int)&pdVar13->alert_fragment_len + 2);
            local_68 = (uint *)pdVar13->handshake_fragment;
            uVar10 = 2;
            goto LAB_080b9ba4;
          }
          if (iVar12 == 0x18) {
            dtls1_process_heartbeat(param_1);
            (psVar19->rrec).length = 0;
            param_1->rwstate = 3;
            pBVar14 = SSL_get_rbio(param_1);
            BIO_clear_flags(pBVar14,0xf);
            pBVar14 = SSL_get_rbio(param_1);
            BIO_set_flags(pBVar14,9);
            local_6c = 0xffffffff;
          }
          else {
            if (iVar12 == 0x14) goto LAB_080b9ac6;
            if (iVar12 != 0x17) {
              iVar20 = 0x3e4;
LAB_080ba27e:
              iVar12 = 0xf5;
              goto LAB_080ba23f;
            }
            psVar11->in_read_app_data = 2;
            pBVar14 = SSL_get_rbio(param_1);
            param_1->rwstate = 3;
            BIO_clear_flags(pBVar14,0xf);
            BIO_set_flags(pBVar14,9);
            local_6c = 0xffffffff;
          }
          goto LAB_080b9e80;
        }
        puVar16 = pdVar13->handshake_fragment + 4;
        local_68 = &pdVar13->retransmitting;
        uVar10 = 0xc;
LAB_080b9ba4:
        if ((psVar19->rrec).length < uVar10) {
          param_1->rstate = 0xf0;
          (psVar19->rrec).length = 0;
          psVar19 = psVar11;
          goto LAB_080b98bf;
        }
        uVar7 = (psVar19->rrec).off;
        (psVar19->rrec).off = uVar7 + 1;
        *puVar16 = (psVar19->rrec).data[uVar7];
        uVar7 = (psVar19->rrec).off;
        puVar1 = &(psVar19->rrec).length;
        *puVar1 = *puVar1 - 1;
        (psVar19->rrec).off = uVar7 + 1;
        puVar16[1] = (psVar19->rrec).data[uVar7];
        puVar1 = &(psVar19->rrec).length;
        *puVar1 = *puVar1 - 1;
        if (uVar10 != 2) {
          uVar7 = (psVar19->rrec).off;
          (psVar19->rrec).off = uVar7 + 1;
          puVar16[2] = (psVar19->rrec).data[uVar7];
          puVar1 = &(psVar19->rrec).length;
          *puVar1 = *puVar1 - 1;
          if (uVar10 != 3) {
            uVar7 = (psVar19->rrec).off;
            (psVar19->rrec).off = uVar7 + 1;
            puVar16[3] = (psVar19->rrec).data[uVar7];
            puVar1 = &(psVar19->rrec).length;
            *puVar1 = *puVar1 - 1;
            if (uVar10 != 4) {
              uVar7 = (psVar19->rrec).off;
              (psVar19->rrec).off = uVar7 + 1;
              puVar16[4] = (psVar19->rrec).data[uVar7];
              puVar1 = &(psVar19->rrec).length;
              *puVar1 = *puVar1 - 1;
              if (uVar10 != 5) {
                uVar7 = (psVar19->rrec).off;
                (psVar19->rrec).off = uVar7 + 1;
                puVar16[5] = (psVar19->rrec).data[uVar7];
                puVar1 = &(psVar19->rrec).length;
                *puVar1 = *puVar1 - 1;
                if (uVar10 != 6) {
                  uVar7 = (psVar19->rrec).off;
                  (psVar19->rrec).off = uVar7 + 1;
                  puVar16[6] = (psVar19->rrec).data[uVar7];
                  puVar1 = &(psVar19->rrec).length;
                  *puVar1 = *puVar1 - 1;
                  if (uVar10 != 7) {
                    uVar7 = (psVar19->rrec).off;
                    (psVar19->rrec).off = uVar7 + 1;
                    puVar16[7] = (psVar19->rrec).data[uVar7];
                    puVar1 = &(psVar19->rrec).length;
                    *puVar1 = *puVar1 - 1;
                    if (uVar10 != 8) {
                      uVar7 = (psVar19->rrec).off;
                      (psVar19->rrec).off = uVar7 + 1;
                      puVar16[8] = (psVar19->rrec).data[uVar7];
                      puVar1 = &(psVar19->rrec).length;
                      *puVar1 = *puVar1 - 1;
                      if (uVar10 != 9) {
                        uVar7 = (psVar19->rrec).off;
                        (psVar19->rrec).off = uVar7 + 1;
                        puVar16[9] = (psVar19->rrec).data[uVar7];
                        puVar1 = &(psVar19->rrec).length;
                        *puVar1 = *puVar1 - 1;
                        if (uVar10 != 10) {
                          uVar7 = (psVar19->rrec).off;
                          (psVar19->rrec).off = uVar7 + 1;
                          puVar16[10] = (psVar19->rrec).data[uVar7];
                          puVar1 = &(psVar19->rrec).length;
                          *puVar1 = *puVar1 - 1;
                          if (uVar10 == 0xc) {
                            uVar7 = (psVar19->rrec).off;
                            (psVar19->rrec).off = uVar7 + 1;
                            puVar16[0xb] = (psVar19->rrec).data[uVar7];
                            puVar1 = &(psVar19->rrec).length;
                            *puVar1 = *puVar1 - 1;
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
        *local_68 = uVar10;
        pdVar13 = param_1->d1;
LAB_080b9ac6:
        if (((param_1->server == 0) && (0xb < pdVar13->retransmitting)) &&
           ((pdVar13->handshake_fragment[4] == '\0' &&
            ((param_1->session != (SSL_SESSION *)0x0 &&
             (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)))))) {
          uVar10 = *(uint *)(pdVar13->handshake_fragment + 4);
          pdVar13->retransmitting = 0;
          if ((uVar10 & 0xffffff00) != 0) {
            iVar20 = 0x416;
            iVar12 = 0x69;
            goto LAB_080b9fd7;
          }
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0x16,pdVar13->handshake_fragment + 4,4,param_1,
                       param_1->msg_callback_arg);
          }
          iVar12 = SSL_state(param_1);
          if (iVar12 == 3) {
            psVar19 = param_1->s3;
            if (((*(byte *)&psVar19->flags & 1) != 0) || (psVar19->renegotiate != 0))
            goto LAB_080b98bf;
            puVar2 = &param_1->d1->handshake_read_seq;
            *puVar2 = *puVar2 + 1;
            param_1->new_session = 1;
            ssl3_renegotiate(param_1);
            iVar12 = ssl3_renegotiate_check(param_1);
            if (iVar12 != 0) {
              local_6c = (*param_1->handshake_func)(param_1);
              if ((int)local_6c < 0) goto LAB_080b9e80;
              if (local_6c == 0) {
                iVar20 = 0x42d;
                goto LAB_080ba055;
              }
LAB_080b9f69:
              if ((*(byte *)&param_1->options & 4) != 0) goto LAB_080b98bc;
              psVar19 = param_1->s3;
              if ((param_1->s3->rbuf).left == 0) {
                param_1->rwstate = 3;
                pBVar14 = SSL_get_rbio(param_1);
                BIO_clear_flags(pBVar14,0xf);
                BIO_set_flags(pBVar14,9);
                local_6c = 0xffffffff;
                goto LAB_080b9e80;
              }
              goto LAB_080b98bf;
            }
          }
        }
        else {
          if (1 < *(uint *)pdVar13->handshake_fragment) {
            sVar4 = *(short *)((int)&pdVar13->alert_fragment_len + 2);
            cVar3 = *(char *)((int)&pdVar13->alert_fragment_len + 2);
            uVar10 = (uint)*(byte *)((int)&pdVar13->alert_fragment_len + 3);
            *(undefined4 *)pdVar13->handshake_fragment = 0;
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,param_1->version,0x15,(void *)((int)&pdVar13->alert_fragment_len + 2),2,
                         param_1,param_1->msg_callback_arg);
            }
            p_Var18 = param_1->info_callback;
            if (((param_1->info_callback != (_func_3152 *)0x0) ||
                (p_Var18 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
               (p_Var18 = local_64, local_64 != (_func_3152 *)0x0)) {
              (*p_Var18)(param_1,0x4004,(uint)(sVar4 << 8) | (uint)(byte)((ushort)sVar4 >> 8));
              local_64 = p_Var18;
            }
            if (cVar3 != '\x01') {
              if (cVar3 != '\x02') {
                ERR_put_error(0x14,0x102,0xf6,"d1_pkt.c",0x49f);
                uVar15 = 0x2f;
                goto LAB_080ba253;
              }
              param_1->rwstate = 1;
              param_1->s3->fatal_alert = uVar10;
              ERR_put_error(0x14,0x102,uVar10 + 1000,"d1_pkt.c",0x495);
              BIO_snprintf(local_30,0x10,"%d",uVar10);
              pSVar21 = (SSL_CTX *)0x2;
              ERR_add_error_data(2,"SSL alert number ",local_30);
              param_1->shutdown = param_1->shutdown | 2;
              SSL_CTX_remove_session(pSVar21,(SSL_SESSION *)param_1->psk_server_callback);
              goto LAB_080b9e80;
            }
            psVar19 = param_1->s3;
            psVar19->warn_alert = uVar10;
            if (uVar10 == 0) goto code_r0x080b9b80;
            goto LAB_080b98bf;
          }
          if ((*(byte *)&param_1->shutdown & 1) != 0) {
            param_1->rwstate = 1;
            (psVar19->rrec).length = 0;
            goto LAB_080b9e80;
          }
          iVar12 = (psVar19->rrec).type;
          if (iVar12 != 0x14) {
            if ((pdVar13->retransmitting < 0xc) || (param_1->in_handshake != 0)) {
              if (0x13 < iVar12) {
                if (iVar12 < 0x17) {
                  iVar20 = 0x542;
                  iVar12 = 0x44;
                  goto LAB_080ba23f;
                }
                if (iVar12 == 0x17) {
                  psVar19 = param_1->s3;
                  if (((psVar19->in_read_app_data == 0) || (psVar19->total_renegotiations == 0)) ||
                     (((uVar10 = param_1->state, 0x10 < uVar10 - 0x1110 || ((uVar10 & 0x1000) == 0))
                      && (((uVar10 & 0x2000) == 0 || (0x10 < uVar10 - 0x2110)))))) {
                    iVar20 = 0x55f;
                    goto LAB_080ba27e;
                  }
                  psVar19->in_read_app_data = 2;
                  goto LAB_080b9e77;
                }
              }
              if (param_1->version == 0x301) goto LAB_080b99fd;
              iVar20 = 0x539;
              goto LAB_080ba27e;
            }
            dtls1_get_message_header((psVar19->rrec).data,local_5c);
            if ((psVar19->rrec).epoch != (uint)param_1->d1->r_epoch) goto LAB_080b99fd;
            if (local_5c[0] != '\x14') {
              if (((param_1->state & 0xfffU) == 3) && ((*(byte *)&param_1->s3->flags & 1) == 0)) {
                param_1->tlsext_hb_seq = 1;
                param_1->new_session = 1;
                param_1->state = (-(uint)(param_1->server == 0) & 0xfffff000) + 0x2000;
              }
              local_6c = (*param_1->handshake_func)(param_1);
              if ((int)local_6c < 0) goto LAB_080b9e80;
              if (local_6c != 0) goto LAB_080b9f69;
              iVar20 = 0x516;
              goto LAB_080ba055;
            }
            iVar12 = dtls1_check_timeout_num(param_1);
            if (iVar12 < 0) goto LAB_080b9e77;
            dtls1_retransmit_buffered_messages(param_1);
            (psVar19->rrec).length = 0;
            psVar19 = param_1->s3;
            goto LAB_080b98bf;
          }
          dtls1_get_ccs_header((psVar19->rrec).data,local_5c);
          iVar12 = param_1->version;
          if ((((uint)(iVar12 == 0x100) * 2 + 1 != (psVar19->rrec).length) ||
              ((psVar19->rrec).off != 0)) || (puVar16 = (psVar19->rrec).data, *puVar16 != '\x01')) {
            ERR_put_error(0x14,0x102,0x67,"d1_pkt.c",0x4be);
            goto LAB_080b9e77;
          }
          p_Var8 = param_1->msg_callback;
          (psVar19->rrec).length = 0;
          if (p_Var8 != (_func_3150 *)0x0) {
            (*p_Var8)(0,iVar12,0x14,puVar16,1,param_1,param_1->msg_callback_arg);
          }
          if (param_1->d1->listen == 0) goto LAB_080b98bc;
          param_1->d1->listen = 0;
          param_1->s3->change_cipher_spec = 1;
          iVar12 = ssl3_do_change_cipher_spec(param_1);
          if (iVar12 == 0) goto LAB_080b9e77;
          pdVar13 = param_1->d1;
          psVar19 = param_1->s3;
          uVar9 = (pdVar13->next_bitmap).map;
          pdVar13->r_epoch = pdVar13->r_epoch + 1;
          (pdVar13->bitmap).map = uVar9;
          *(undefined4 *)(pdVar13->bitmap).max_seq_num =
               *(undefined4 *)(pdVar13->next_bitmap).max_seq_num;
          *(undefined4 *)((pdVar13->bitmap).max_seq_num + 4) =
               *(undefined4 *)((pdVar13->next_bitmap).max_seq_num + 4);
          pdVar13 = param_1->d1;
          (pdVar13->next_bitmap).map = 0;
          *(undefined4 *)(pdVar13->next_bitmap).max_seq_num = 0;
          *(undefined4 *)((pdVar13->next_bitmap).max_seq_num + 4) = 0;
          *(undefined4 *)psVar19->read_sequence = 0;
          *(undefined4 *)(psVar19->read_sequence + 4) = 0;
          if (param_1->version == 0x100) {
            puVar2 = &param_1->d1->handshake_read_seq;
            *puVar2 = *puVar2 + 1;
          }
        }
      }
      else {
        iVar12 = dtls1_handle_timeout(param_1);
        if (iVar12 < 1) goto LAB_080b99d0;
      }
LAB_080b98bc:
      psVar19 = param_1->s3;
      goto LAB_080b98bf;
    }
    local_6c = (*param_1->handshake_func)(param_1);
    if ((int)local_6c < 0) goto LAB_080b9e80;
    if (local_6c != 0) goto LAB_080b9895;
    iVar20 = 0x317;
LAB_080ba055:
    iVar12 = 0xe5;
  }
LAB_080b9fd7:
  ERR_put_error(0x14,0x102,iVar12,"d1_pkt.c",iVar20);
  local_6c = 0xffffffff;
LAB_080b9e80:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_6c;
code_r0x080b9b80:
  param_1->shutdown = param_1->shutdown | 2;
  goto LAB_080b9e80;
}

