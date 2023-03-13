
uint dtls1_read_bytes(SSL *param_1,int param_2,void *param_3,uint param_4,int param_5)

{
  uint *puVar1;
  ushort *puVar2;
  uchar uVar3;
  short sVar4;
  uchar **ppuVar5;
  uchar *puVar6;
  _func_3150 *p_Var7;
  uint uVar8;
  ulong uVar9;
  uint uVar10;
  pitem *item;
  ssl3_state_st *psVar11;
  int iVar12;
  BIO *pBVar13;
  undefined4 uVar14;
  dtls1_state_st *pdVar15;
  uchar *puVar16;
  uchar *puVar17;
  ssl3_state_st *psVar18;
  _func_3152 *p_Var19;
  int in_GS_OFFSET;
  int line;
  SSL_CTX *pSVar20;
  uint local_6c;
  uint *local_68;
  _func_3152 *local_64;
  char local_5c [44];
  char local_30 [16];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((param_1->s3->rbuf).buf != (uchar *)0x0) ||
     (iVar12 = ssl3_setup_buffers(param_1), iVar12 != 0)) {
    if ((param_2 == 0) || (param_2 == 0x17)) {
      if ((param_5 != 0) && (param_2 != 0x17)) goto LAB_080b7368;
      if (param_2 == 0x16) goto LAB_080b6a56;
    }
    else {
      if ((param_2 != 0x16) || (param_5 != 0)) {
LAB_080b7368:
        iVar12 = 0x340;
LAB_080b7370:
        ERR_put_error(0x14,0x102,0x44,"d1_pkt.c",iVar12);
        goto LAB_080b7212;
      }
LAB_080b6a56:
      pdVar15 = param_1->d1;
      if (pdVar15->change_cipher_spec_ok != 0) {
        puVar17 = pdVar15->handshake_fragment + 8;
        if (0 < (int)param_4) {
          local_6c = 0;
          puVar16 = puVar17;
          do {
            *(uchar *)((int)param_3 + local_6c) = *puVar16;
            pdVar15 = param_1->d1;
            local_6c = local_6c + 1;
            uVar10 = pdVar15->change_cipher_spec_ok - 1;
            pdVar15->change_cipher_spec_ok = uVar10;
            if (puVar16 + 1 == puVar17 + param_4) {
              puVar17 = puVar17 + param_4;
              if (uVar10 != 0) goto LAB_080b6ac7;
              break;
            }
            puVar16 = puVar16 + 1;
          } while (uVar10 != 0);
          goto LAB_080b7219;
        }
        local_6c = 0;
LAB_080b6ac7:
        pdVar15->handshake_fragment[8] = *puVar17;
        if (1 < param_1->d1->change_cipher_spec_ok) {
          param_1->d1->handshake_fragment[9] = puVar17[1];
          if (2 < param_1->d1->change_cipher_spec_ok) {
            param_1->d1->handshake_fragment[10] = puVar17[2];
            if (3 < param_1->d1->change_cipher_spec_ok) {
              param_1->d1->handshake_fragment[0xb] = puVar17[3];
              if (4 < param_1->d1->change_cipher_spec_ok) {
                *(uchar *)&param_1->d1->handshake_fragment_len = puVar17[4];
                if (5 < param_1->d1->change_cipher_spec_ok) {
                  *(uchar *)((int)&param_1->d1->handshake_fragment_len + 1) = puVar17[5];
                  if (6 < param_1->d1->change_cipher_spec_ok) {
                    *(uchar *)((int)&param_1->d1->handshake_fragment_len + 2) = puVar17[6];
                    if (7 < param_1->d1->change_cipher_spec_ok) {
                      *(uchar *)((int)&param_1->d1->handshake_fragment_len + 3) = puVar17[7];
                      if (8 < param_1->d1->change_cipher_spec_ok) {
                        *(uchar *)&param_1->d1->retransmitting = puVar17[8];
                        if (9 < param_1->d1->change_cipher_spec_ok) {
                          *(uchar *)((int)&param_1->d1->retransmitting + 1) = puVar17[9];
                          if (10 < param_1->d1->change_cipher_spec_ok) {
                            *(uchar *)((int)&param_1->d1->retransmitting + 2) = puVar17[10];
                            if (0xb < param_1->d1->change_cipher_spec_ok) {
                              *(uchar *)((int)&param_1->d1->retransmitting + 3) = puVar17[0xb];
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
        if (local_6c != 0) goto LAB_080b7219;
      }
    }
    if ((param_1->in_handshake != 0) || (uVar10 = SSL_state(param_1), (uVar10 & 0x3000) == 0)) {
LAB_080b6c0d:
      local_64 = (_func_3152 *)0x0;
      psVar18 = param_1->s3;
LAB_080b6c37:
      param_1->rwstate = 1;
      if (((param_1->state == 3) && ((psVar18->rrec).length == 0)) &&
         (item = pqueue_pop((param_1->d1->buffered_app_data).q), item != (pitem *)0x0)) {
        ppuVar5 = (uchar **)item->data;
        psVar11 = param_1->s3;
        puVar17 = (psVar11->rbuf).buf;
        if (puVar17 != (uchar *)0x0) {
          CRYPTO_free(puVar17);
          psVar11 = param_1->s3;
        }
        param_1->packet = *ppuVar5;
        param_1->packet_length = (uint)ppuVar5[1];
        puVar17 = ppuVar5[5];
        puVar16 = ppuVar5[3];
        puVar6 = ppuVar5[2];
        (psVar11->rbuf).offset = (int)ppuVar5[4];
        (psVar11->rbuf).len = (size_t)puVar16;
        (psVar11->rbuf).buf = puVar6;
        (psVar11->rbuf).left = (int)puVar17;
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
        puVar17 = *ppuVar5;
        psVar11 = param_1->s3;
        *(undefined4 *)(psVar11->read_sequence + 2) = *(undefined4 *)(puVar17 + 5);
        *(undefined2 *)(psVar11->read_sequence + 6) = *(undefined2 *)(puVar17 + 9);
        CRYPTO_free(item->data);
        pitem_free(item);
        iVar12 = dtls1_handle_timeout(param_1);
        if (0 < iVar12) goto LAB_080b6c34;
LAB_080b6d48:
        if ((((psVar18->rrec).length == 0) || (param_1->rstate == 0xf1)) &&
           (iVar12 = dtls1_get_record(param_1), iVar12 < 1)) {
          local_6c = dtls1_read_failed(param_1,iVar12);
          if (0 < (int)local_6c) goto LAB_080b6c34;
          goto LAB_080b7219;
        }
        pdVar15 = param_1->d1;
        if (pdVar15->mtu == 0) {
          psVar11 = param_1->s3;
          if ((psVar11->change_cipher_spec == 0) || ((psVar18->rrec).type == 0x16))
          goto LAB_080b6e1b;
          iVar12 = pqueue_size((pdVar15->buffered_app_data).q);
          if ((iVar12 < 100) && (iVar12 = dtls1_buffer_record_isra_6_part_7(), iVar12 < 0)) {
            iVar12 = 0x3ab;
            goto LAB_080b7370;
          }
LAB_080b6d75:
          (psVar18->rrec).length = 0;
          psVar18 = param_1->s3;
          goto LAB_080b6c37;
        }
        if ((psVar18->rrec).type != 0x16) goto LAB_080b6d75;
        psVar11 = param_1->s3;
LAB_080b6e1b:
        local_6c = param_1->shutdown & 2;
        if (local_6c != 0) {
          (psVar18->rrec).length = 0;
          local_6c = 0;
          param_1->rwstate = 1;
          goto LAB_080b7219;
        }
        iVar12 = (psVar18->rrec).type;
        if (param_2 == iVar12) {
          uVar10 = SSL_state(param_1);
          if ((((uVar10 & 0x3000) == 0) || (param_2 != 0x17)) ||
             (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) {
            if ((int)param_4 < 1) {
              local_6c = param_4;
            }
            else {
              local_6c = (psVar18->rrec).length;
              if (param_4 < local_6c) {
                local_6c = param_4;
              }
              memcpy(param_3,(psVar18->rrec).data + (psVar18->rrec).off,local_6c);
              if (param_5 == 0) {
                puVar1 = &(psVar18->rrec).off;
                *puVar1 = *puVar1 + local_6c;
                uVar10 = (psVar18->rrec).length - local_6c;
                (psVar18->rrec).length = uVar10;
                if (uVar10 == 0) {
                  param_1->rstate = 0xf0;
                  (psVar18->rrec).off = 0;
                }
              }
            }
            goto LAB_080b7219;
          }
          line = 0x3c5;
          iVar12 = 100;
LAB_080b741f:
          ERR_put_error(0x14,0x102,iVar12,"d1_pkt.c",line);
          uVar14 = 10;
LAB_080b7433:
          ssl3_send_alert(param_1,2,uVar14);
          goto LAB_080b7212;
        }
        if (iVar12 != 0x16) {
          if (iVar12 == 0x15) {
            local_68 = (uint *)(pdVar15->handshake_fragment + 4);
            puVar17 = pdVar15->handshake_fragment + 2;
            uVar10 = 2;
            goto LAB_080b6f3d;
          }
          if (iVar12 == 0x18) {
            dtls1_process_heartbeat(param_1);
            (psVar18->rrec).length = 0;
            param_1->rwstate = 3;
            pBVar13 = SSL_get_rbio(param_1);
            BIO_clear_flags(pBVar13,0xf);
            pBVar13 = SSL_get_rbio(param_1);
            BIO_set_flags(pBVar13,9);
            local_6c = 0xffffffff;
          }
          else {
            if (iVar12 == 0x14) goto LAB_080b6e5e;
            if (iVar12 != 0x17) {
              line = 0x42c;
LAB_080b7640:
              iVar12 = 0xf5;
              goto LAB_080b741f;
            }
            psVar11->in_read_app_data = 2;
            pBVar13 = SSL_get_rbio(param_1);
            param_1->rwstate = 3;
            BIO_clear_flags(pBVar13,0xf);
            BIO_set_flags(pBVar13,9);
            local_6c = 0xffffffff;
          }
          goto LAB_080b7219;
        }
        local_68 = &pdVar15->change_cipher_spec_ok;
        puVar17 = pdVar15->handshake_fragment + 8;
        uVar10 = 0xc;
LAB_080b6f3d:
        if ((psVar18->rrec).length < uVar10) {
          param_1->rstate = 0xf0;
          (psVar18->rrec).length = 0;
          psVar18 = psVar11;
          goto LAB_080b6c37;
        }
        uVar8 = (psVar18->rrec).off;
        (psVar18->rrec).off = uVar8 + 1;
        *puVar17 = (psVar18->rrec).data[uVar8];
        uVar8 = (psVar18->rrec).off;
        puVar1 = &(psVar18->rrec).length;
        *puVar1 = *puVar1 - 1;
        (psVar18->rrec).off = uVar8 + 1;
        puVar17[1] = (psVar18->rrec).data[uVar8];
        puVar1 = &(psVar18->rrec).length;
        *puVar1 = *puVar1 - 1;
        if (uVar10 != 2) {
          uVar8 = (psVar18->rrec).off;
          (psVar18->rrec).off = uVar8 + 1;
          puVar17[2] = (psVar18->rrec).data[uVar8];
          puVar1 = &(psVar18->rrec).length;
          *puVar1 = *puVar1 - 1;
          if (uVar10 != 3) {
            uVar8 = (psVar18->rrec).off;
            (psVar18->rrec).off = uVar8 + 1;
            puVar17[3] = (psVar18->rrec).data[uVar8];
            puVar1 = &(psVar18->rrec).length;
            *puVar1 = *puVar1 - 1;
            if (uVar10 != 4) {
              uVar8 = (psVar18->rrec).off;
              (psVar18->rrec).off = uVar8 + 1;
              puVar17[4] = (psVar18->rrec).data[uVar8];
              puVar1 = &(psVar18->rrec).length;
              *puVar1 = *puVar1 - 1;
              if (uVar10 != 5) {
                uVar8 = (psVar18->rrec).off;
                (psVar18->rrec).off = uVar8 + 1;
                puVar17[5] = (psVar18->rrec).data[uVar8];
                puVar1 = &(psVar18->rrec).length;
                *puVar1 = *puVar1 - 1;
                if (uVar10 != 6) {
                  uVar8 = (psVar18->rrec).off;
                  (psVar18->rrec).off = uVar8 + 1;
                  puVar17[6] = (psVar18->rrec).data[uVar8];
                  puVar1 = &(psVar18->rrec).length;
                  *puVar1 = *puVar1 - 1;
                  if (uVar10 != 7) {
                    uVar8 = (psVar18->rrec).off;
                    (psVar18->rrec).off = uVar8 + 1;
                    puVar17[7] = (psVar18->rrec).data[uVar8];
                    puVar1 = &(psVar18->rrec).length;
                    *puVar1 = *puVar1 - 1;
                    if (uVar10 != 8) {
                      uVar8 = (psVar18->rrec).off;
                      (psVar18->rrec).off = uVar8 + 1;
                      puVar17[8] = (psVar18->rrec).data[uVar8];
                      puVar1 = &(psVar18->rrec).length;
                      *puVar1 = *puVar1 - 1;
                      if (uVar10 != 9) {
                        uVar8 = (psVar18->rrec).off;
                        (psVar18->rrec).off = uVar8 + 1;
                        puVar17[9] = (psVar18->rrec).data[uVar8];
                        puVar1 = &(psVar18->rrec).length;
                        *puVar1 = *puVar1 - 1;
                        if (uVar10 != 10) {
                          uVar8 = (psVar18->rrec).off;
                          (psVar18->rrec).off = uVar8 + 1;
                          puVar17[10] = (psVar18->rrec).data[uVar8];
                          puVar1 = &(psVar18->rrec).length;
                          *puVar1 = *puVar1 - 1;
                          if (uVar10 == 0xc) {
                            uVar8 = (psVar18->rrec).off;
                            (psVar18->rrec).off = uVar8 + 1;
                            puVar17[0xb] = (psVar18->rrec).data[uVar8];
                            puVar1 = &(psVar18->rrec).length;
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
        pdVar15 = param_1->d1;
LAB_080b6e5e:
        if (((param_1->server == 0) && (0xb < pdVar15->change_cipher_spec_ok)) &&
           ((pdVar15->handshake_fragment[8] == '\0' &&
            ((param_1->session != (SSL_SESSION *)0x0 &&
             (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)))))) {
          uVar10 = *(uint *)(pdVar15->handshake_fragment + 8);
          pdVar15->change_cipher_spec_ok = 0;
          if ((uVar10 & 0xffffff00) != 0) {
            ERR_put_error(0x14,0x102,0x69,"d1_pkt.c",0x45d);
            uVar14 = 0x32;
            goto LAB_080b7433;
          }
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0x16,pdVar15->handshake_fragment + 8,4,param_1,
                       param_1->msg_callback_arg);
          }
          iVar12 = SSL_state(param_1);
          if (iVar12 == 3) {
            psVar18 = param_1->s3;
            if (((*(byte *)&psVar18->flags & 1) != 0) || (psVar18->renegotiate != 0))
            goto LAB_080b6c37;
            puVar2 = &param_1->d1->handshake_read_seq;
            *puVar2 = *puVar2 + 1;
            param_1->new_session = 1;
            ssl3_renegotiate(param_1);
            iVar12 = ssl3_renegotiate_check(param_1);
            if (iVar12 != 0) {
              local_6c = (*param_1->handshake_func)(param_1);
              if ((int)local_6c < 0) goto LAB_080b7219;
              if (local_6c == 0) {
                ERR_put_error(0x14,0x102,0xe5,"d1_pkt.c",0x476);
                local_6c = 0xffffffff;
                goto LAB_080b7219;
              }
LAB_080b7303:
              if ((*(byte *)&param_1->options & 4) != 0) goto LAB_080b6c34;
              psVar18 = param_1->s3;
              if ((param_1->s3->rbuf).left == 0) {
                param_1->rwstate = 3;
                pBVar13 = SSL_get_rbio(param_1);
                BIO_clear_flags(pBVar13,0xf);
                BIO_set_flags(pBVar13,9);
                local_6c = 0xffffffff;
                goto LAB_080b7219;
              }
              goto LAB_080b6c37;
            }
          }
        }
        else {
          if (1 < *(uint *)(pdVar15->handshake_fragment + 4)) {
            p_Var7 = param_1->msg_callback;
            sVar4 = *(short *)(pdVar15->handshake_fragment + 2);
            uVar3 = pdVar15->handshake_fragment[2];
            uVar10 = (uint)pdVar15->handshake_fragment[3];
            *(undefined4 *)(pdVar15->handshake_fragment + 4) = 0;
            if (p_Var7 != (_func_3150 *)0x0) {
              (*p_Var7)(0,param_1->version,0x15,pdVar15->handshake_fragment + 2,2,param_1,
                        param_1->msg_callback_arg);
            }
            p_Var19 = param_1->info_callback;
            if (((param_1->info_callback != (_func_3152 *)0x0) ||
                (p_Var19 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
                *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
               (p_Var19 = local_64, local_64 != (_func_3152 *)0x0)) {
              (*p_Var19)(param_1,0x4004,(uint)(sVar4 << 8) | (uint)(byte)((ushort)sVar4 >> 8));
              local_64 = p_Var19;
            }
            if (uVar3 != '\x01') {
              if (uVar3 != '\x02') {
                ERR_put_error(0x14,0x102,0xf6,"d1_pkt.c",0x4e6);
                uVar14 = 0x2f;
                goto LAB_080b7433;
              }
              param_1->rwstate = 1;
              param_1->s3->fatal_alert = uVar10;
              ERR_put_error(0x14,0x102,uVar10 + 1000,"d1_pkt.c",0x4de);
              BIO_snprintf(local_30,0x10,"%d",uVar10);
              pSVar20 = (SSL_CTX *)0x2;
              ERR_add_error_data(2,"SSL alert number ",local_30);
              param_1->shutdown = param_1->shutdown | 2;
              SSL_CTX_remove_session(pSVar20,(SSL_SESSION *)param_1->psk_server_callback);
              goto LAB_080b7219;
            }
            psVar18 = param_1->s3;
            psVar18->warn_alert = uVar10;
            if (uVar10 == 0) goto code_r0x080b6f18;
            goto LAB_080b6c37;
          }
          if ((*(byte *)&param_1->shutdown & 1) != 0) {
            param_1->rwstate = 1;
            (psVar18->rrec).length = 0;
            goto LAB_080b7219;
          }
          iVar12 = (psVar18->rrec).type;
          if (iVar12 != 0x14) {
            if ((pdVar15->change_cipher_spec_ok < 0xc) || (param_1->in_handshake != 0)) {
              if (0x13 < iVar12) {
                if (iVar12 < 0x17) {
                  line = 0x588;
                  iVar12 = 0x44;
                  goto LAB_080b741f;
                }
                if (iVar12 == 0x17) {
                  psVar18 = param_1->s3;
                  if (((psVar18->in_read_app_data == 0) || (psVar18->total_renegotiations == 0)) ||
                     (((uVar10 = param_1->state, 0x10 < uVar10 - 0x1110 || ((uVar10 & 0x1000) == 0))
                      && ((0x10 < uVar10 - 0x2110 || ((uVar10 & 0x2000) == 0)))))) {
                    line = 0x5a0;
                    goto LAB_080b7640;
                  }
                  psVar18->in_read_app_data = 2;
                  goto LAB_080b7212;
                }
              }
              if (param_1->version == 0x301) goto LAB_080b6d75;
              line = 0x57d;
              goto LAB_080b7640;
            }
            dtls1_get_message_header((psVar18->rrec).data,local_5c);
            if ((psVar18->rrec).epoch != (uint)param_1->d1->r_epoch) goto LAB_080b6d75;
            if (local_5c[0] != '\x14') {
              if (((param_1->state & 0xfffU) == 3) && ((*(byte *)&param_1->s3->flags & 1) == 0)) {
                param_1->tlsext_hb_seq = 1;
                param_1->new_session = 1;
                param_1->state = (-(uint)(param_1->server == 0) & 0xfffff000) + 0x2000;
              }
              local_6c = (*param_1->handshake_func)(param_1);
              if ((int)local_6c < 0) goto LAB_080b7219;
              if (local_6c != 0) goto LAB_080b7303;
              iVar12 = 0x55c;
              goto LAB_080b73ed;
            }
            iVar12 = dtls1_check_timeout_num(param_1);
            if (iVar12 < 0) goto LAB_080b7212;
            dtls1_retransmit_buffered_messages(param_1);
            (psVar18->rrec).length = 0;
            psVar18 = param_1->s3;
            goto LAB_080b6c37;
          }
          dtls1_get_ccs_header((psVar18->rrec).data,local_5c);
          iVar12 = param_1->version;
          if ((((uint)(iVar12 == 0x100) * 2 + 1 != (psVar18->rrec).length) ||
              ((psVar18->rrec).off != 0)) || (puVar17 = (psVar18->rrec).data, *puVar17 != '\x01')) {
            ERR_put_error(0x14,0x102,0x67,"d1_pkt.c",0x505);
            goto LAB_080b7212;
          }
          p_Var7 = param_1->msg_callback;
          (psVar18->rrec).length = 0;
          if (p_Var7 != (_func_3150 *)0x0) {
            (*p_Var7)(0,iVar12,0x14,puVar17,1,param_1,param_1->msg_callback_arg);
          }
          if (param_1->d1[1].send_cookie == 0) goto LAB_080b6c34;
          param_1->d1[1].send_cookie = 0;
          param_1->s3->change_cipher_spec = 1;
          iVar12 = ssl3_do_change_cipher_spec(param_1);
          if (iVar12 == 0) goto LAB_080b7212;
          pdVar15 = param_1->d1;
          psVar18 = param_1->s3;
          uVar9 = (pdVar15->next_bitmap).map;
          pdVar15->r_epoch = pdVar15->r_epoch + 1;
          (pdVar15->bitmap).map = uVar9;
          *(undefined4 *)(pdVar15->bitmap).max_seq_num =
               *(undefined4 *)(pdVar15->next_bitmap).max_seq_num;
          *(undefined4 *)((pdVar15->bitmap).max_seq_num + 4) =
               *(undefined4 *)((pdVar15->next_bitmap).max_seq_num + 4);
          pdVar15 = param_1->d1;
          (pdVar15->next_bitmap).map = 0;
          *(undefined4 *)(pdVar15->next_bitmap).max_seq_num = 0;
          *(undefined4 *)((pdVar15->next_bitmap).max_seq_num + 4) = 0;
          dtls1_clear_received_buffer(param_1);
          *(undefined4 *)psVar18->read_sequence = 0;
          *(undefined4 *)(psVar18->read_sequence + 4) = 0;
          if (param_1->version == 0x100) {
            puVar2 = &param_1->d1->handshake_read_seq;
            *puVar2 = *puVar2 + 1;
          }
        }
      }
      else {
        iVar12 = dtls1_handle_timeout(param_1);
        if (iVar12 < 1) goto LAB_080b6d48;
      }
LAB_080b6c34:
      psVar18 = param_1->s3;
      goto LAB_080b6c37;
    }
    local_6c = (*param_1->handshake_func)(param_1);
    if ((int)local_6c < 0) goto LAB_080b7219;
    if (local_6c != 0) goto LAB_080b6c0d;
    iVar12 = 0x361;
LAB_080b73ed:
    ERR_put_error(0x14,0x102,0xe5,"d1_pkt.c",iVar12);
  }
LAB_080b7212:
  local_6c = 0xffffffff;
LAB_080b7219:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_6c;
code_r0x080b6f18:
  param_1->shutdown = param_1->shutdown | 2;
  goto LAB_080b7219;
}

