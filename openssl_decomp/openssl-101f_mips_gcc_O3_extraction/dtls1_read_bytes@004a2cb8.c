
ssl3_state_st *
dtls1_read_bytes(SSL *param_1,int param_2,char *param_3,ssl3_state_st *param_4,int param_5)

{
  undefined *puVar1;
  char cVar2;
  undefined2 uVar3;
  uint *puVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  BIO *pBVar8;
  undefined4 uVar9;
  uchar *puVar10;
  SSL3_RECORD *pSVar11;
  char *pcVar12;
  uchar **ppuVar13;
  dtls1_state_st *pdVar14;
  uint uVar15;
  undefined4 uVar16;
  char *buf;
  ssl3_state_st *psVar17;
  uchar *puVar18;
  uchar *puVar19;
  uchar *puVar20;
  ssl3_state_st *psVar21;
  ssl3_state_st *psVar22;
  uchar **ppuVar23;
  _func_3150 *p_Var24;
  code *pcVar25;
  _func_3152 *local_74;
  _func_3152 *local_6c;
  char local_68 [44];
  undefined auStack_3c [16];
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  buf = (char *)param_4;
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar7 = ssl3_setup_buffers(), iVar7 == 0)) {
    psVar17 = (ssl3_state_st *)0xffffffff;
LAB_004a2ef0:
    while (local_2c != *(int *)puVar5) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_004a3d68:
      uVar16 = 0xe5;
      buf = (char *)((ssl3_state_st *)((int)buf + 0x7bc0))->send_alert;
      uVar9 = 0x42d;
LAB_004a35f4:
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x102,uVar16,buf,uVar9);
      psVar17 = (ssl3_state_st *)0xffffffff;
    }
    return psVar17;
  }
  if (param_2 == 0) {
    buf = "s\n";
    if (param_5 != 0) {
LAB_004a35e8:
      uVar16 = 0x44;
      buf = "d1_pkt.c";
      uVar9 = 0x2fc;
      goto LAB_004a35f4;
    }
  }
  else if (param_2 != 0x17) {
    buf = "s\n";
    if ((param_2 != 0x16) || (param_5 != 0)) goto LAB_004a35e8;
    pdVar14 = param_1->d1;
    if (pdVar14->retransmitting != 0) {
      psVar21 = (ssl3_state_st *)(pdVar14->handshake_fragment + 4);
      if ((int)param_4 < 1) {
        psVar17 = (ssl3_state_st *)0x0;
LAB_004a2dac:
        pdVar14->handshake_fragment[4] = *(uchar *)&psVar21->flags;
        buf = (char *)psVar21;
        if (1 < param_1->d1->retransmitting) {
          param_1->d1->handshake_fragment[5] = *(uchar *)((int)&psVar21->flags + 1);
          if (2 < param_1->d1->retransmitting) {
            param_1->d1->handshake_fragment[6] = *(uchar *)((int)&psVar21->flags + 2);
            if (3 < param_1->d1->retransmitting) {
              param_1->d1->handshake_fragment[7] = *(uchar *)((int)&psVar21->flags + 3);
              if (4 < param_1->d1->retransmitting) {
                param_1->d1->handshake_fragment[8] = *(uchar *)&psVar21->delay_buf_pop_ret;
                if (5 < param_1->d1->retransmitting) {
                  param_1->d1->handshake_fragment[9] =
                       *(uchar *)((int)&psVar21->delay_buf_pop_ret + 1);
                  if (6 < param_1->d1->retransmitting) {
                    param_1->d1->handshake_fragment[10] =
                         *(uchar *)((int)&psVar21->delay_buf_pop_ret + 2);
                    if (7 < param_1->d1->retransmitting) {
                      param_1->d1->handshake_fragment[0xb] =
                           *(uchar *)((int)&psVar21->delay_buf_pop_ret + 3);
                      if (8 < param_1->d1->retransmitting) {
                        *(uchar *)&param_1->d1->handshake_fragment_len = psVar21->read_sequence[0];
                        if (9 < param_1->d1->retransmitting) {
                          *(undefined *)((int)&param_1->d1->handshake_fragment_len + 1) =
                               *(undefined *)((int)psVar21->read_sequence + 1);
                          if (10 < param_1->d1->retransmitting) {
                            *(undefined *)((int)&param_1->d1->handshake_fragment_len + 2) =
                                 *(undefined *)((int)psVar21->read_sequence + 2);
                            if (0xb < param_1->d1->retransmitting) {
                              *(undefined *)((int)&param_1->d1->handshake_fragment_len + 3) =
                                   *(undefined *)((int)psVar21->read_sequence + 3);
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
        buf = (char *)((int)param_4->read_sequence + (int)((int)psVar21->read_sequence + -0x10));
        pcVar12 = param_3;
        do {
          psVar22 = (ssl3_state_st *)((int)&psVar21->flags + 1);
          psVar17 = (ssl3_state_st *)(pcVar12 + 1 + -(int)param_3);
          *pcVar12 = *(char *)&psVar21->flags;
          pdVar14 = param_1->d1;
          uVar6 = pdVar14->retransmitting - 1;
          pdVar14->retransmitting = uVar6;
          if (psVar22 == (ssl3_state_st *)buf) {
            psVar21 = (ssl3_state_st *)buf;
            if (uVar6 != 0) goto LAB_004a2dac;
            break;
          }
          psVar21 = psVar22;
          pcVar12 = pcVar12 + 1;
        } while (uVar6 != 0);
      }
      if (psVar17 != (ssl3_state_st *)0x0) goto LAB_004a2ef0;
    }
  }
  if ((param_1->in_handshake == 0) && (uVar6 = SSL_state(param_1), (uVar6 & 0x3000) != 0)) {
    psVar17 = (ssl3_state_st *)(*param_1->handshake_func)(param_1);
    if ((int)psVar17 < 0) goto LAB_004a2ef0;
    buf = "s\n";
    if (psVar17 == (ssl3_state_st *)0x0) {
      uVar16 = 0xe5;
      buf = "d1_pkt.c";
      uVar9 = 0x317;
      goto LAB_004a35f4;
    }
  }
  psVar21 = param_1->s3;
  local_6c = (_func_3152 *)0x0;
LAB_004a2f58:
  param_1->rwstate = 1;
  if (param_1->state == 3) goto LAB_004a2f88;
LAB_004a2f68:
  iVar7 = dtls1_handle_timeout(param_1);
  psVar22 = psVar21;
  if (iVar7 < 1) goto LAB_004a30fc;
LAB_004a2f78:
  psVar21 = param_1->s3;
  do {
    param_1->rwstate = 1;
    if (param_1->state != 3) goto LAB_004a2f68;
LAB_004a2f88:
    if (((psVar21->rrec).length != 0) ||
       (iVar7 = (*(code *)PTR_pqueue_pop_006a93a0)((param_1->d1->buffered_app_data).q), iVar7 == 0))
    goto LAB_004a2f68;
    psVar17 = param_1->s3;
    puVar10 = (psVar17->rbuf).buf;
    ppuVar23 = *(uchar ***)(iVar7 + 8);
    if (puVar10 != (uchar *)0x0) {
      CRYPTO_free(puVar10);
      psVar17 = param_1->s3;
    }
    puVar10 = ppuVar23[1];
    ppuVar13 = ppuVar23 + 6;
    param_1->packet = *ppuVar23;
    param_1->packet_length = (uint)puVar10;
    puVar19 = ppuVar23[3];
    puVar18 = ppuVar23[4];
    puVar10 = ppuVar23[5];
    (psVar17->rbuf).buf = ppuVar23[2];
    (psVar17->rbuf).len = (size_t)puVar19;
    (psVar17->rbuf).offset = (int)puVar18;
    (psVar17->rbuf).left = (int)puVar10;
    pSVar11 = &param_1->s3->rrec;
    do {
      puVar20 = *ppuVar13;
      puVar19 = ppuVar13[1];
      puVar18 = ppuVar13[2];
      puVar10 = ppuVar13[3];
      ppuVar13 = ppuVar13 + 4;
      pSVar11->type = (int)puVar20;
      pSVar11->length = (uint)puVar19;
      pSVar11->off = (uint)puVar18;
      pSVar11->data = puVar10;
      pSVar11 = (SSL3_RECORD *)&pSVar11->input;
    } while (ppuVar13 != ppuVar23 + 0xe);
    *(uchar **)pSVar11 = *ppuVar13;
    puVar10 = *ppuVar23;
    buf = (char *)param_1->s3;
    uVar15 = *(uint *)(puVar10 + 5);
    puVar1 = (undefined *)((int)((int)buf + 8) + 2);
    uVar6 = (uint)puVar1 & 3;
    puVar4 = (uint *)(puVar1 + -uVar6);
    *puVar4 = *puVar4 & -1 << (4 - uVar6) * 8 | uVar15 >> uVar6 * 8;
    puVar1 = (undefined *)((int)((int)buf + 8) + 5);
    uVar6 = (uint)puVar1 & 3;
    puVar4 = (uint *)(puVar1 + -uVar6);
    *puVar4 = *puVar4 & 0xffffffffU >> (uVar6 + 1) * 8 | uVar15 << (3 - uVar6) * 8;
    *(uchar *)((int)((int)buf + 8) + 6) = puVar10[9];
    *(uchar *)((int)((int)buf + 8) + 7) = puVar10[10];
    CRYPTO_free(*(void **)(iVar7 + 8));
    (*(code *)PTR_pitem_free_006a939c)(iVar7);
    iVar7 = dtls1_handle_timeout(param_1);
    psVar22 = psVar21;
    if (0 < iVar7) goto LAB_004a2f78;
LAB_004a30fc:
    if ((((psVar22->rrec).length == 0) || (param_1->rstate == 0xf1)) &&
       (iVar7 = dtls1_get_record(param_1), iVar7 < 1)) {
      psVar17 = (ssl3_state_st *)dtls1_read_failed(param_1,iVar7);
      if ((int)psVar17 < 1) goto LAB_004a2ef0;
      goto LAB_004a2f78;
    }
    pdVar14 = param_1->d1;
    if (pdVar14->mtu != 0) {
      if ((psVar22->rrec).type == 0x16) {
        psVar21 = param_1->s3;
        goto LAB_004a3140;
      }
LAB_004a3130:
      (psVar22->rrec).length = 0;
      psVar21 = param_1->s3;
      goto LAB_004a2f58;
    }
    psVar21 = param_1->s3;
    if ((psVar21->change_cipher_spec != 0) && ((psVar22->rrec).type != 0x16)) {
      dtls1_buffer_record_isra_6(param_1,&(pdVar14->buffered_app_data).q,(psVar22->rrec).seq_num);
      (psVar22->rrec).length = 0;
      psVar21 = param_1->s3;
      goto LAB_004a2f58;
    }
LAB_004a3140:
    psVar17 = (ssl3_state_st *)(param_1->shutdown & 2);
    if (psVar17 != (ssl3_state_st *)0x0) {
      (psVar22->rrec).length = 0;
      param_1->rwstate = 1;
      psVar17 = (ssl3_state_st *)0x0;
      goto LAB_004a2ef0;
    }
    iVar7 = (psVar22->rrec).type;
    if (param_2 == iVar7) {
      uVar6 = SSL_state(param_1);
      if ((((uVar6 & 0x3000) == 0) || (param_2 != 0x17)) ||
         (buf = "s\n", param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) {
        psVar17 = param_4;
        if (0 < (int)param_4) {
          psVar17 = (ssl3_state_st *)(psVar22->rrec).length;
          if (psVar17 <= param_4) {
            param_4 = psVar17;
          }
          (*(code *)PTR_memcpy_006aabf4)(param_3,(psVar22->rrec).data + (psVar22->rrec).off,param_4)
          ;
          psVar17 = param_4;
          if (param_5 == 0) {
            uVar6 = (psVar22->rrec).length - (int)param_4;
            (psVar22->rrec).length = uVar6;
            (psVar22->rrec).off = (int)param_4->read_sequence + ((psVar22->rrec).off - 8);
            if (uVar6 == 0) {
              param_1->rstate = 0xf0;
              (psVar22->rrec).off = 0;
            }
          }
        }
      }
      else {
        uVar16 = 100;
        uVar9 = 0x37a;
LAB_004a3a04:
        buf = "d1_pkt.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x102,uVar16,"d1_pkt.c",uVar9);
        uVar9 = 10;
LAB_004a3a1c:
        ssl3_send_alert(param_1,2,uVar9);
        psVar17 = (ssl3_state_st *)0xffffffff;
      }
      goto LAB_004a2ef0;
    }
    if (iVar7 != 0x16) {
      puVar10 = (uchar *)((int)&pdVar14->alert_fragment_len + 2);
      if (iVar7 == 0x15) {
        buf = (char *)pdVar14->handshake_fragment;
        uVar6 = 2;
        goto LAB_004a32c0;
      }
      if (iVar7 == 0x18) {
        dtls1_process_heartbeat(param_1);
        (psVar22->rrec).length = 0;
        param_1->rwstate = 3;
        pBVar8 = SSL_get_rbio(param_1);
        (*(code *)PTR_BIO_clear_flags_006a9260)(pBVar8,0xf);
        pBVar8 = SSL_get_rbio(param_1);
        (*(code *)PTR_BIO_set_flags_006a8660)(pBVar8,9);
        psVar17 = (ssl3_state_st *)0xffffffff;
      }
      else {
        if (iVar7 == 0x14) goto LAB_004a3184;
        buf = "s\n";
        if (iVar7 != 0x17) {
          uVar16 = 0xf5;
          uVar9 = 0x3e4;
          goto LAB_004a3a04;
        }
        psVar21->in_read_app_data = 2;
        pBVar8 = SSL_get_rbio(param_1);
        pcVar25 = (code *)PTR_BIO_clear_flags_006a9260;
        param_1->rwstate = 3;
LAB_004a3734:
        (*pcVar25)(pBVar8,0xf);
        (*(code *)PTR_BIO_set_flags_006a8660)(pBVar8,9);
LAB_004a3754:
        psVar17 = (ssl3_state_st *)0xffffffff;
      }
      goto LAB_004a2ef0;
    }
    puVar10 = pdVar14->handshake_fragment + 4;
    buf = (char *)&pdVar14->retransmitting;
    uVar6 = 0xc;
LAB_004a32c0:
    if ((psVar22->rrec).length < uVar6) {
      param_1->rstate = 0xf0;
      (psVar22->rrec).length = 0;
      goto LAB_004a2f58;
    }
    uVar15 = (psVar22->rrec).off;
    (psVar22->rrec).off = uVar15 + 1;
    *puVar10 = (psVar22->rrec).data[uVar15];
    uVar15 = (psVar22->rrec).off;
    psVar21 = (ssl3_state_st *)((psVar22->rrec).length - 1);
    (psVar22->rrec).length = (uint)psVar21;
    (psVar22->rrec).off = uVar15 + 1;
    puVar10[1] = (psVar22->rrec).data[uVar15];
    (psVar22->rrec).length = (psVar22->rrec).length - 1;
    if (uVar6 != 2) {
      psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
      (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
      puVar10[2] = (psVar22->rrec).data[(int)psVar21];
      (psVar22->rrec).length = (psVar22->rrec).length - 1;
      if (uVar6 != 3) {
        psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
        (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
        puVar10[3] = (psVar22->rrec).data[(int)psVar21];
        (psVar22->rrec).length = (psVar22->rrec).length - 1;
        if (uVar6 != 4) {
          psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
          (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
          puVar10[4] = (psVar22->rrec).data[(int)psVar21];
          (psVar22->rrec).length = (psVar22->rrec).length - 1;
          if (uVar6 != 5) {
            psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
            (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
            puVar10[5] = (psVar22->rrec).data[(int)psVar21];
            (psVar22->rrec).length = (psVar22->rrec).length - 1;
            if (uVar6 != 6) {
              psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
              (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
              puVar10[6] = (psVar22->rrec).data[(int)psVar21];
              (psVar22->rrec).length = (psVar22->rrec).length - 1;
              if (uVar6 != 7) {
                psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
                (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
                puVar10[7] = (psVar22->rrec).data[(int)psVar21];
                (psVar22->rrec).length = (psVar22->rrec).length - 1;
                if (uVar6 != 8) {
                  psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
                  (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
                  puVar10[8] = (psVar22->rrec).data[(int)psVar21];
                  (psVar22->rrec).length = (psVar22->rrec).length - 1;
                  if (uVar6 != 9) {
                    psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
                    (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
                    puVar10[9] = (psVar22->rrec).data[(int)psVar21];
                    (psVar22->rrec).length = (psVar22->rrec).length - 1;
                    if (uVar6 != 10) {
                      psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
                      (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
                      puVar10[10] = (psVar22->rrec).data[(int)psVar21];
                      (psVar22->rrec).length = (psVar22->rrec).length - 1;
                      if (uVar6 == 0xc) {
                        psVar21 = (ssl3_state_st *)(psVar22->rrec).off;
                        (psVar22->rrec).off = (uint)((int)&psVar21->flags + 1);
                        puVar10[0xb] = (psVar22->rrec).data[(int)psVar21];
                        (psVar22->rrec).length = (psVar22->rrec).length - 1;
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
    pdVar14 = param_1->d1;
    *(long *)buf = uVar6;
LAB_004a3184:
    if ((((param_1->server == 0) && (0xb < pdVar14->retransmitting)) &&
        (pdVar14->handshake_fragment[4] == '\0')) &&
       ((param_1->session != (SSL_SESSION *)0x0 &&
        (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)))) {
      uVar6 = *(uint *)(pdVar14->handshake_fragment + 4);
      pdVar14->retransmitting = 0;
      if ((uVar6 & 0xffffff) != 0) {
        uVar16 = 0x69;
        buf = "d1_pkt.c";
        uVar9 = 0x416;
        goto LAB_004a35f4;
      }
      buf = (char *)(pdVar14->handshake_fragment + 4);
      if (param_1->msg_callback != (_func_3150 *)0x0) {
        (*param_1->msg_callback)(0,param_1->version,0x16,buf,4,param_1,param_1->msg_callback_arg);
      }
      iVar7 = SSL_state(param_1);
      if (iVar7 == 3) {
        psVar21 = param_1->s3;
        if (((psVar21->flags & 1U) != 0) || (psVar21->renegotiate != 0)) goto LAB_004a2f58;
        param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
        param_1->new_session = 1;
        ssl3_renegotiate(param_1);
        iVar7 = ssl3_renegotiate_check(param_1);
        if (iVar7 != 0) {
          psVar17 = (ssl3_state_st *)(*param_1->handshake_func)(param_1);
          if ((int)psVar17 < 0) goto LAB_004a2ef0;
          buf = "s\n";
          if (psVar17 == (ssl3_state_st *)0x0) goto LAB_004a3d68;
          if ((param_1->options & 4) == 0) {
            psVar21 = param_1->s3;
            if ((psVar21->rbuf).left == 0) {
              param_1->rwstate = 3;
LAB_004a3718:
              buf = "s\n";
              pBVar8 = SSL_get_rbio(param_1);
              pcVar25 = (code *)PTR_BIO_clear_flags_006a9260;
              goto LAB_004a3734;
            }
            goto LAB_004a2f58;
          }
        }
      }
      goto LAB_004a2f78;
    }
    buf = (char *)((int)&pdVar14->alert_fragment_len + 2);
    if (1 < *(uint *)pdVar14->handshake_fragment) {
      p_Var24 = param_1->msg_callback;
      uVar3 = *(undefined2 *)((int)&pdVar14->alert_fragment_len + 2);
      cVar2 = *(char *)((int)&pdVar14->alert_fragment_len + 2);
      psVar22 = (ssl3_state_st *)(uint)*(byte *)((int)&pdVar14->alert_fragment_len + 3);
      *(undefined4 *)pdVar14->handshake_fragment = 0;
      if (p_Var24 != (_func_3150 *)0x0) {
        (*p_Var24)(0,param_1->version,0x15,buf,2,param_1,param_1->msg_callback_arg);
      }
      local_74 = param_1->info_callback;
      if ((local_74 == (_func_3152 *)0x0) &&
         (local_74 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
         local_74 == (_func_3152 *)0x0)) {
        if (local_6c != (_func_3152 *)0x0) {
          local_74 = local_6c;
          goto LAB_004a3210;
        }
      }
      else {
LAB_004a3210:
        (*local_74)(param_1,0x4004,(int)uVar3);
        local_6c = local_74;
      }
      puVar1 = PTR_ERR_put_error_006a9030;
      if (cVar2 == '\x01') {
        psVar21 = param_1->s3;
        psVar21->warn_alert = (int)psVar22;
        if (psVar22 != (ssl3_state_st *)0x0) goto LAB_004a2f58;
        param_1->shutdown = param_1->shutdown | 2;
      }
      else {
        if (cVar2 != '\x02') {
          buf = "d1_pkt.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x102,0xf6,"d1_pkt.c",0x49f);
          uVar9 = 0x2f;
          goto LAB_004a3a1c;
        }
        param_1->rwstate = 1;
        param_1->s3->fatal_alert = (int)psVar22;
        (*(code *)puVar1)(0x14,0x102,psVar22->previous_server_finished + 0x13,"d1_pkt.c",0x495);
        (*(code *)PTR_BIO_snprintf_006a8060)(auStack_3c,0x10,"%d",psVar22);
        (*(code *)PTR_ERR_add_error_data_006a9264)(2,"SSL alert number ",auStack_3c);
        param_1->shutdown = param_1->shutdown | 2;
        SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
        buf = (char *)psVar22;
      }
      goto LAB_004a2ef0;
    }
    if ((param_1->shutdown & 1U) != 0) {
      param_1->rwstate = 1;
      (psVar22->rrec).length = 0;
      goto LAB_004a2ef0;
    }
    iVar7 = (psVar22->rrec).type;
    if (iVar7 != 0x14) {
      if ((pdVar14->retransmitting < 0xc) || (param_1->in_handshake != 0)) {
        if (iVar7 < 0x14) {
LAB_004a3928:
          buf = "s\n";
          if (param_1->version == 0x301) goto LAB_004a3130;
          uVar16 = 0xf5;
          uVar9 = 0x539;
          goto LAB_004a3a04;
        }
        if (iVar7 < 0x17) {
          uVar16 = 0x44;
          uVar9 = 0x542;
          goto LAB_004a3a04;
        }
        if (iVar7 != 0x17) goto LAB_004a3928;
        psVar17 = param_1->s3;
        if (((psVar17->in_read_app_data == 0) || (psVar17->total_renegotiations == 0)) ||
           (((uVar6 = param_1->state, (uVar6 & 0x1000) == 0 || (0x10 < uVar6 - 0x1110)) &&
            (((uVar6 & 0x2000) == 0 || (0x10 < uVar6 - 0x2110)))))) {
          buf = "d1_pkt.c";
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x102,0xf5,"d1_pkt.c",0x55f);
          uVar9 = 10;
          goto LAB_004a3a1c;
        }
        psVar17->in_read_app_data = 2;
        psVar17 = (ssl3_state_st *)0xffffffff;
        goto LAB_004a2ef0;
      }
      dtls1_get_message_header((psVar22->rrec).data,local_68);
      if ((psVar22->rrec).epoch != (uint)param_1->d1->r_epoch) goto LAB_004a3130;
      if (local_68[0] == '\x14') {
        iVar7 = dtls1_check_timeout_num(param_1);
        if (iVar7 < 0) goto LAB_004a3754;
        dtls1_retransmit_buffered_messages(param_1);
        (psVar22->rrec).length = 0;
        psVar21 = param_1->s3;
        goto LAB_004a2f58;
      }
      if (((param_1->state & 0xfffU) == 3) && (iVar7 = 0x2000, (param_1->s3->flags & 1U) == 0)) {
        param_1->tlsext_hb_seq = 1;
        param_1->new_session = 1;
        if (param_1->server == 0) {
          iVar7 = 0x1000;
        }
        param_1->state = iVar7;
      }
      psVar17 = (ssl3_state_st *)(*param_1->handshake_func)(param_1);
      if ((int)psVar17 < 0) goto LAB_004a2ef0;
      buf = "s\n";
      if (psVar17 == (ssl3_state_st *)0x0) {
        uVar16 = 0xe5;
        buf = "d1_pkt.c";
        uVar9 = 0x516;
        goto LAB_004a35f4;
      }
      if ((param_1->options & 4) == 0) {
        psVar21 = param_1->s3;
        if ((psVar21->rbuf).left == 0) {
          param_1->rwstate = 3;
          goto LAB_004a3718;
        }
        goto LAB_004a2f58;
      }
      goto LAB_004a2f78;
    }
    dtls1_get_ccs_header((psVar22->rrec).data,local_68,psVar21,buf);
    uVar6 = 1;
    iVar7 = param_1->version;
    if (iVar7 == 0x100) {
      uVar6 = 3;
    }
    if (((uVar6 != (psVar22->rrec).length) || ((psVar22->rrec).off != 0)) ||
       (buf = (char *)(psVar22->rrec).data, *(char *)(long *)buf != '\x01')) {
      buf = "d1_pkt.c";
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x102,0x67,"d1_pkt.c",0x4be);
      psVar17 = (ssl3_state_st *)0xffffffff;
      goto LAB_004a2ef0;
    }
    p_Var24 = param_1->msg_callback;
    (psVar22->rrec).length = 0;
    if (p_Var24 != (_func_3150 *)0x0) {
      (*p_Var24)(0,iVar7,0x14,buf,1,param_1,param_1->msg_callback_arg);
    }
    if (param_1->d1->listen == 0) goto LAB_004a2f78;
    psVar17 = param_1->s3;
    param_1->d1->listen = 0;
    psVar17->change_cipher_spec = 1;
    iVar7 = ssl3_do_change_cipher_spec(param_1);
    if (iVar7 == 0) goto LAB_004a3754;
    pdVar14 = param_1->d1;
    psVar17 = param_1->s3;
    pdVar14->r_epoch = pdVar14->r_epoch + 1;
    uVar15 = (pdVar14->next_bitmap).map;
    uVar9 = *(undefined4 *)(pdVar14->next_bitmap).max_seq_num;
    buf = *(char **)((pdVar14->next_bitmap).max_seq_num + 4);
    uVar6 = (uint)&pdVar14->bitmap & 3;
    puVar4 = (uint *)((int)&pdVar14->bitmap - uVar6);
    *puVar4 = *puVar4 & -1 << (4 - uVar6) * 8 | uVar15 >> uVar6 * 8;
    puVar1 = (undefined *)((int)&(pdVar14->bitmap).map + 3);
    uVar6 = (uint)puVar1 & 3;
    puVar4 = (uint *)(puVar1 + -uVar6);
    *puVar4 = *puVar4 & 0xffffffffU >> (uVar6 + 1) * 8 | uVar15 << (3 - uVar6) * 8;
    *(undefined4 *)(pdVar14->bitmap).max_seq_num = uVar9;
    *(char **)((pdVar14->bitmap).max_seq_num + 4) = buf;
    pdVar14 = param_1->d1;
    *(undefined *)&(pdVar14->next_bitmap).map = 0;
    *(undefined *)((int)&(pdVar14->next_bitmap).map + 1) = 0;
    *(undefined *)((int)&(pdVar14->next_bitmap).map + 2) = 0;
    *(undefined *)((int)&(pdVar14->next_bitmap).map + 3) = 0;
    (pdVar14->next_bitmap).max_seq_num[0] = '\0';
    (pdVar14->next_bitmap).max_seq_num[1] = '\0';
    (pdVar14->next_bitmap).max_seq_num[2] = '\0';
    (pdVar14->next_bitmap).max_seq_num[3] = '\0';
    (pdVar14->next_bitmap).max_seq_num[4] = '\0';
    (pdVar14->next_bitmap).max_seq_num[5] = '\0';
    (pdVar14->next_bitmap).max_seq_num[6] = '\0';
    (pdVar14->next_bitmap).max_seq_num[7] = '\0';
    psVar17->read_sequence[0] = '\0';
    psVar17->read_sequence[1] = '\0';
    psVar17->read_sequence[2] = '\0';
    psVar17->read_sequence[3] = '\0';
    psVar17->read_sequence[4] = '\0';
    psVar17->read_sequence[5] = '\0';
    psVar17->read_sequence[6] = '\0';
    psVar17->read_sequence[7] = '\0';
    if (param_1->version != 0x100) goto LAB_004a2f78;
    psVar21 = param_1->s3;
    param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
  } while( true );
}

