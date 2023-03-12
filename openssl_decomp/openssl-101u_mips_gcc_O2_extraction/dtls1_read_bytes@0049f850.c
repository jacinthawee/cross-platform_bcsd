
uint dtls1_read_bytes(SSL *param_1,int param_2,uchar *param_3,uint param_4,int param_5)

{
  undefined *puVar1;
  uchar uVar2;
  undefined2 uVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  BIO *pBVar7;
  uchar *puVar8;
  SSL3_RECORD *pSVar9;
  uchar **ppuVar10;
  dtls1_state_st *pdVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint *puVar15;
  uint uVar16;
  uchar *puVar17;
  uchar *puVar18;
  uchar *puVar19;
  ssl3_state_st *psVar20;
  ssl3_state_st *psVar21;
  uchar **ppuVar22;
  _func_3150 *p_Var23;
  code *pcVar24;
  _func_3152 *local_70;
  _func_3152 *local_6c;
  char local_68 [44];
  undefined auStack_3c [16];
  int local_2c;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar6 = ssl3_setup_buffers(), iVar6 == 0)) {
    uVar16 = 0xffffffff;
    goto LAB_004a038c;
  }
  if (param_2 == 0) {
    if (param_5 == 0) goto LAB_0049fa88;
LAB_004a0184:
    uVar13 = 0x44;
    uVar14 = 0x340;
  }
  else {
    if (param_2 == 0x17) goto LAB_0049fa88;
    if ((param_2 != 0x16) || (param_5 != 0)) goto LAB_004a0184;
    pdVar11 = param_1->d1;
    if (pdVar11->change_cipher_spec_ok == 0) {
LAB_0049fa88:
      iVar6 = param_1->in_handshake;
    }
    else {
      puVar8 = pdVar11->handshake_fragment + 8;
      if ((int)param_4 < 1) {
        uVar16 = 0;
LAB_0049f944:
        pdVar11->handshake_fragment[8] = *puVar8;
        if (1 < param_1->d1->change_cipher_spec_ok) {
          param_1->d1->handshake_fragment[9] = puVar8[1];
          if (2 < param_1->d1->change_cipher_spec_ok) {
            param_1->d1->handshake_fragment[10] = puVar8[2];
            if (3 < param_1->d1->change_cipher_spec_ok) {
              param_1->d1->handshake_fragment[0xb] = puVar8[3];
              if (4 < param_1->d1->change_cipher_spec_ok) {
                *(uchar *)&param_1->d1->handshake_fragment_len = puVar8[4];
                if (5 < param_1->d1->change_cipher_spec_ok) {
                  *(uchar *)((int)&param_1->d1->handshake_fragment_len + 1) = puVar8[5];
                  if (6 < param_1->d1->change_cipher_spec_ok) {
                    *(uchar *)((int)&param_1->d1->handshake_fragment_len + 2) = puVar8[6];
                    if (7 < param_1->d1->change_cipher_spec_ok) {
                      *(uchar *)((int)&param_1->d1->handshake_fragment_len + 3) = puVar8[7];
                      if (8 < param_1->d1->change_cipher_spec_ok) {
                        *(uchar *)&param_1->d1->retransmitting = puVar8[8];
                        if (9 < param_1->d1->change_cipher_spec_ok) {
                          *(uchar *)((int)&param_1->d1->retransmitting + 1) = puVar8[9];
                          if (10 < param_1->d1->change_cipher_spec_ok) {
                            *(uchar *)((int)&param_1->d1->retransmitting + 2) = puVar8[10];
                            if (0xb < param_1->d1->change_cipher_spec_ok) {
                              *(uchar *)((int)&param_1->d1->retransmitting + 3) = puVar8[0xb];
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
LAB_0049fa80:
        if (uVar16 != 0) goto LAB_004a038c;
        goto LAB_0049fa88;
      }
      puVar17 = puVar8;
      puVar18 = param_3;
      do {
        uVar16 = (int)(puVar18 + 1) - (int)param_3;
        *puVar18 = *puVar17;
        pdVar11 = param_1->d1;
        uVar5 = pdVar11->change_cipher_spec_ok - 1;
        pdVar11->change_cipher_spec_ok = uVar5;
        if (puVar17 + 1 == puVar8 + param_4) {
          puVar8 = puVar8 + param_4;
          if (uVar5 == 0) goto LAB_0049fa80;
          goto LAB_0049f944;
        }
        puVar17 = puVar17 + 1;
        puVar18 = puVar18 + 1;
      } while (uVar5 != 0);
      if (uVar16 != 0) goto LAB_004a038c;
      iVar6 = param_1->in_handshake;
    }
    if ((iVar6 != 0) || (uVar16 = SSL_state(param_1), (uVar16 & 0x3000) == 0)) {
LAB_0049fa94:
      psVar21 = param_1->s3;
      local_6c = (_func_3152 *)0x0;
LAB_0049faac:
      param_1->rwstate = 1;
      if (param_1->state == 3) goto LAB_0049fadc;
LAB_0049fabc:
      iVar6 = dtls1_handle_timeout(param_1);
      psVar20 = psVar21;
      if (iVar6 < 1) goto LAB_0049fc50;
LAB_0049facc:
      psVar21 = param_1->s3;
LAB_0049fad0:
      param_1->rwstate = 1;
      if (param_1->state != 3) goto LAB_0049fabc;
LAB_0049fadc:
      if (((psVar21->rrec).length != 0) ||
         (iVar6 = (*(code *)PTR_pqueue_pop_006a827c)((param_1->d1->buffered_app_data).q), iVar6 == 0
         )) goto LAB_0049fabc;
      psVar20 = param_1->s3;
      puVar8 = (psVar20->rbuf).buf;
      ppuVar22 = *(uchar ***)(iVar6 + 8);
      if (puVar8 != (uchar *)0x0) {
        CRYPTO_free(puVar8);
        psVar20 = param_1->s3;
      }
      puVar8 = ppuVar22[1];
      ppuVar10 = ppuVar22 + 6;
      param_1->packet = *ppuVar22;
      param_1->packet_length = (uint)puVar8;
      puVar18 = ppuVar22[3];
      puVar17 = ppuVar22[4];
      puVar8 = ppuVar22[5];
      (psVar20->rbuf).buf = ppuVar22[2];
      (psVar20->rbuf).len = (size_t)puVar18;
      (psVar20->rbuf).offset = (int)puVar17;
      (psVar20->rbuf).left = (int)puVar8;
      pSVar9 = &param_1->s3->rrec;
      do {
        puVar19 = *ppuVar10;
        puVar18 = ppuVar10[1];
        puVar17 = ppuVar10[2];
        puVar8 = ppuVar10[3];
        ppuVar10 = ppuVar10 + 4;
        pSVar9->type = (int)puVar19;
        pSVar9->length = (uint)puVar18;
        pSVar9->off = (uint)puVar17;
        pSVar9->data = puVar8;
        pSVar9 = (SSL3_RECORD *)&pSVar9->input;
      } while (ppuVar10 != ppuVar22 + 0xe);
      *(uchar **)pSVar9 = *ppuVar10;
      puVar17 = *ppuVar22;
      psVar20 = param_1->s3;
      uVar5 = *(uint *)(puVar17 + 5);
      puVar8 = psVar20->read_sequence + 2;
      uVar16 = (uint)puVar8 & 3;
      *(uint *)(puVar8 + -uVar16) =
           *(uint *)(puVar8 + -uVar16) & -1 << (4 - uVar16) * 8 | uVar5 >> uVar16 * 8;
      puVar8 = psVar20->read_sequence + 5;
      uVar16 = (uint)puVar8 & 3;
      *(uint *)(puVar8 + -uVar16) =
           *(uint *)(puVar8 + -uVar16) & 0xffffffffU >> (uVar16 + 1) * 8 | uVar5 << (3 - uVar16) * 8
      ;
      psVar20->read_sequence[6] = puVar17[9];
      psVar20->read_sequence[7] = puVar17[10];
      CRYPTO_free(*(void **)(iVar6 + 8));
      (*(code *)PTR_pitem_free_006a8278)(iVar6);
      iVar6 = dtls1_handle_timeout(param_1);
      psVar20 = psVar21;
      if (0 < iVar6) goto LAB_0049facc;
LAB_0049fc50:
      if ((((psVar20->rrec).length == 0) || (param_1->rstate == 0xf1)) &&
         (iVar6 = dtls1_get_record(param_1), iVar6 < 1)) {
        uVar16 = dtls1_read_failed(param_1,iVar6);
        if ((int)uVar16 < 1) goto LAB_004a038c;
        goto LAB_0049facc;
      }
      pdVar11 = param_1->d1;
      if (pdVar11->mtu == 0) {
        psVar21 = param_1->s3;
        if ((psVar21->change_cipher_spec == 0) || ((psVar20->rrec).type == 0x16)) goto LAB_0049fc94;
        iVar6 = (*(code *)PTR_pqueue_size_006a82ac)((pdVar11->buffered_app_data).q);
        if ((iVar6 < 100) &&
           (iVar6 = dtls1_buffer_record_isra_6_part_7
                              (param_1,&(pdVar11->buffered_app_data).q,(psVar20->rrec).seq_num),
           iVar6 < 0)) {
          uVar13 = 0x44;
          uVar14 = 0x3ab;
          goto LAB_0049fe38;
        }
      }
      else {
        if ((psVar20->rrec).type != 0x16) goto LAB_0049fc84;
        psVar21 = param_1->s3;
LAB_0049fc94:
        uVar16 = param_1->shutdown & 2;
        if (uVar16 != 0) {
          (psVar20->rrec).length = 0;
          param_1->rwstate = 1;
          uVar16 = 0;
          goto LAB_004a038c;
        }
        iVar6 = (psVar20->rrec).type;
        if (param_2 == iVar6) {
          uVar16 = SSL_state(param_1);
          if ((((uVar16 & 0x3000) != 0) && (param_2 == 0x17)) &&
             (param_1->enc_read_ctx == (EVP_CIPHER_CTX *)0x0)) {
            uVar13 = 100;
            uVar14 = 0x3c5;
            goto LAB_004a035c;
          }
          uVar16 = param_4;
          if (0 < (int)param_4) {
            uVar16 = (psVar20->rrec).length;
            if (uVar16 <= param_4) {
              param_4 = uVar16;
            }
            (*(code *)PTR_memcpy_006a9aec)
                      (param_3,(psVar20->rrec).data + (psVar20->rrec).off,param_4);
            uVar16 = param_4;
            if (param_5 == 0) {
              uVar5 = (psVar20->rrec).length - param_4;
              (psVar20->rrec).length = uVar5;
              (psVar20->rrec).off = (psVar20->rrec).off + param_4;
              if (uVar5 == 0) {
                param_1->rstate = 0xf0;
                (psVar20->rrec).off = 0;
              }
            }
          }
          goto LAB_004a038c;
        }
        if (iVar6 != 0x16) {
          puVar8 = pdVar11->handshake_fragment + 2;
          if (iVar6 == 0x15) {
            puVar15 = (uint *)(pdVar11->handshake_fragment + 4);
            uVar5 = 2;
            goto LAB_0049fe60;
          }
          if (iVar6 == 0x18) {
            dtls1_process_heartbeat(param_1);
            (psVar20->rrec).length = 0;
            param_1->rwstate = 3;
            pBVar7 = SSL_get_rbio(param_1);
            (*(code *)PTR_BIO_clear_flags_006a8138)(pBVar7,0xf);
            pBVar7 = SSL_get_rbio(param_1);
            (*(code *)PTR_BIO_set_flags_006a7570)(pBVar7,9);
            uVar16 = 0xffffffff;
          }
          else {
            if (iVar6 == 0x14) goto LAB_0049fcd8;
            if (iVar6 != 0x17) {
              uVar13 = 0xf5;
              uVar14 = 0x42c;
              goto LAB_004a035c;
            }
            psVar21->in_read_app_data = 2;
            pBVar7 = SSL_get_rbio(param_1);
            pcVar24 = (code *)PTR_BIO_clear_flags_006a8138;
            param_1->rwstate = 3;
LAB_004a02b8:
            (*pcVar24)(pBVar7,0xf);
            (*(code *)PTR_BIO_set_flags_006a7570)(pBVar7,9);
LAB_004a02d8:
            uVar16 = 0xffffffff;
          }
          goto LAB_004a038c;
        }
        puVar8 = pdVar11->handshake_fragment + 8;
        puVar15 = &pdVar11->change_cipher_spec_ok;
        uVar5 = 0xc;
LAB_0049fe60:
        if ((psVar20->rrec).length < uVar5) {
          param_1->rstate = 0xf0;
          (psVar20->rrec).length = 0;
          goto LAB_0049faac;
        }
        uVar12 = (psVar20->rrec).off;
        (psVar20->rrec).off = uVar12 + 1;
        *puVar8 = (psVar20->rrec).data[uVar12];
        uVar12 = (psVar20->rrec).off;
        (psVar20->rrec).length = (psVar20->rrec).length - 1;
        (psVar20->rrec).off = uVar12 + 1;
        puVar8[1] = (psVar20->rrec).data[uVar12];
        (psVar20->rrec).length = (psVar20->rrec).length - 1;
        if (uVar5 != 2) {
          uVar12 = (psVar20->rrec).off;
          (psVar20->rrec).off = uVar12 + 1;
          puVar8[2] = (psVar20->rrec).data[uVar12];
          (psVar20->rrec).length = (psVar20->rrec).length - 1;
          if (uVar5 != 3) {
            uVar12 = (psVar20->rrec).off;
            (psVar20->rrec).off = uVar12 + 1;
            puVar8[3] = (psVar20->rrec).data[uVar12];
            (psVar20->rrec).length = (psVar20->rrec).length - 1;
            if (uVar5 != 4) {
              uVar12 = (psVar20->rrec).off;
              (psVar20->rrec).off = uVar12 + 1;
              puVar8[4] = (psVar20->rrec).data[uVar12];
              (psVar20->rrec).length = (psVar20->rrec).length - 1;
              if (uVar5 != 5) {
                uVar12 = (psVar20->rrec).off;
                (psVar20->rrec).off = uVar12 + 1;
                puVar8[5] = (psVar20->rrec).data[uVar12];
                (psVar20->rrec).length = (psVar20->rrec).length - 1;
                if (uVar5 != 6) {
                  uVar12 = (psVar20->rrec).off;
                  (psVar20->rrec).off = uVar12 + 1;
                  puVar8[6] = (psVar20->rrec).data[uVar12];
                  (psVar20->rrec).length = (psVar20->rrec).length - 1;
                  if (uVar5 != 7) {
                    uVar12 = (psVar20->rrec).off;
                    (psVar20->rrec).off = uVar12 + 1;
                    puVar8[7] = (psVar20->rrec).data[uVar12];
                    (psVar20->rrec).length = (psVar20->rrec).length - 1;
                    if (uVar5 != 8) {
                      uVar12 = (psVar20->rrec).off;
                      (psVar20->rrec).off = uVar12 + 1;
                      puVar8[8] = (psVar20->rrec).data[uVar12];
                      (psVar20->rrec).length = (psVar20->rrec).length - 1;
                      if (uVar5 != 9) {
                        uVar12 = (psVar20->rrec).off;
                        (psVar20->rrec).off = uVar12 + 1;
                        puVar8[9] = (psVar20->rrec).data[uVar12];
                        (psVar20->rrec).length = (psVar20->rrec).length - 1;
                        if (uVar5 != 10) {
                          uVar12 = (psVar20->rrec).off;
                          (psVar20->rrec).off = uVar12 + 1;
                          puVar8[10] = (psVar20->rrec).data[uVar12];
                          (psVar20->rrec).length = (psVar20->rrec).length - 1;
                          if (uVar5 == 0xc) {
                            uVar12 = (psVar20->rrec).off;
                            (psVar20->rrec).off = uVar12 + 1;
                            puVar8[0xb] = (psVar20->rrec).data[uVar12];
                            (psVar20->rrec).length = (psVar20->rrec).length - 1;
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
        pdVar11 = param_1->d1;
        *puVar15 = uVar5;
LAB_0049fcd8:
        if ((((param_1->server == 0) && (0xb < pdVar11->change_cipher_spec_ok)) &&
            (pdVar11->handshake_fragment[8] == '\0')) &&
           ((param_1->session != (SSL_SESSION *)0x0 &&
            (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)))) {
          uVar16 = *(uint *)(pdVar11->handshake_fragment + 8);
          pdVar11->change_cipher_spec_ok = 0;
          if ((uVar16 & 0xffffff) != 0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x102,0x69,"d1_pkt.c",0x45d);
            uVar14 = 0x32;
            goto LAB_004a0374;
          }
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0x16,pdVar11->handshake_fragment + 8,4,param_1,
                       param_1->msg_callback_arg);
          }
          iVar6 = SSL_state(param_1);
          if (iVar6 == 3) {
            psVar21 = param_1->s3;
            if (((psVar21->flags & 1U) != 0) || (psVar21->renegotiate != 0)) goto LAB_0049faac;
            param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
            param_1->new_session = 1;
            ssl3_renegotiate(param_1);
            iVar6 = ssl3_renegotiate_check(param_1);
            if (iVar6 != 0) {
              uVar16 = (*param_1->handshake_func)(param_1);
              if ((int)uVar16 < 0) goto LAB_004a038c;
              if (uVar16 == 0) {
                uVar13 = 0xe5;
                uVar14 = 0x476;
                goto LAB_0049fe38;
              }
              if ((param_1->options & 4) == 0) {
                psVar21 = param_1->s3;
                if ((psVar21->rbuf).left == 0) {
                  param_1->rwstate = 3;
LAB_004a029c:
                  pBVar7 = SSL_get_rbio(param_1);
                  pcVar24 = (code *)PTR_BIO_clear_flags_006a8138;
                  goto LAB_004a02b8;
                }
                goto LAB_0049faac;
              }
            }
          }
          goto LAB_0049facc;
        }
        if (1 < *(uint *)(pdVar11->handshake_fragment + 4)) {
          p_Var23 = param_1->msg_callback;
          uVar3 = *(undefined2 *)(pdVar11->handshake_fragment + 2);
          uVar2 = pdVar11->handshake_fragment[2];
          uVar5 = (uint)pdVar11->handshake_fragment[3];
          *(undefined4 *)(pdVar11->handshake_fragment + 4) = 0;
          if (p_Var23 != (_func_3150 *)0x0) {
            (*p_Var23)(0,param_1->version,0x15,pdVar11->handshake_fragment + 2,2,param_1,
                       param_1->msg_callback_arg);
          }
          local_70 = param_1->info_callback;
          if ((local_70 == (_func_3152 *)0x0) &&
             (local_70 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
             local_70 == (_func_3152 *)0x0)) {
            if (local_6c != (_func_3152 *)0x0) {
              local_70 = local_6c;
              goto LAB_0049fd68;
            }
          }
          else {
LAB_0049fd68:
            (*local_70)(param_1,0x4004,(int)uVar3);
            local_6c = local_70;
          }
          puVar1 = PTR_ERR_put_error_006a7f34;
          if (uVar2 == '\x01') {
            psVar21 = param_1->s3;
            psVar21->warn_alert = uVar5;
            if (uVar5 != 0) goto LAB_0049faac;
            param_1->shutdown = param_1->shutdown | 2;
          }
          else {
            if (uVar2 != '\x02') goto LAB_004a0920;
            param_1->rwstate = 1;
            param_1->s3->fatal_alert = uVar5;
            (*(code *)puVar1)(0x14,0x102,uVar5 + 1000,"d1_pkt.c",0x4de);
            (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_3c,0x10,"%d",uVar5);
            (*(code *)PTR_ERR_add_error_data_006a813c)(2,"SSL alert number ",auStack_3c);
            param_1->shutdown = param_1->shutdown | 2;
            SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
          }
          goto LAB_004a038c;
        }
        if ((param_1->shutdown & 1U) != 0) {
          param_1->rwstate = 1;
          (psVar20->rrec).length = 0;
          goto LAB_004a038c;
        }
        iVar6 = (psVar20->rrec).type;
        if (iVar6 == 0x14) {
          dtls1_get_ccs_header((psVar20->rrec).data,local_68);
          uVar16 = 1;
          iVar6 = param_1->version;
          if (iVar6 == 0x100) {
            uVar16 = 3;
          }
          if (((uVar16 != (psVar20->rrec).length) || ((psVar20->rrec).off != 0)) ||
             (puVar8 = (psVar20->rrec).data, *puVar8 != '\x01')) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x102,0x67,"d1_pkt.c",0x505);
            uVar16 = 0xffffffff;
            goto LAB_004a038c;
          }
          p_Var23 = param_1->msg_callback;
          (psVar20->rrec).length = 0;
          if (p_Var23 != (_func_3150 *)0x0) {
            (*p_Var23)(0,iVar6,0x14,puVar8,1,param_1,param_1->msg_callback_arg);
          }
          if (param_1->d1[1].send_cookie == 0) goto LAB_0049facc;
          psVar21 = param_1->s3;
          param_1->d1[1].send_cookie = 0;
          psVar21->change_cipher_spec = 1;
          iVar6 = ssl3_do_change_cipher_spec(param_1);
          if (iVar6 == 0) goto LAB_004a02d8;
          pdVar11 = param_1->d1;
          psVar21 = param_1->s3;
          pdVar11->r_epoch = pdVar11->r_epoch + 1;
          uVar5 = (pdVar11->next_bitmap).map;
          uVar13 = *(undefined4 *)(pdVar11->next_bitmap).max_seq_num;
          uVar14 = *(undefined4 *)((pdVar11->next_bitmap).max_seq_num + 4);
          uVar16 = (uint)&pdVar11->bitmap & 3;
          puVar15 = (uint *)((int)&pdVar11->bitmap - uVar16);
          *puVar15 = *puVar15 & -1 << (4 - uVar16) * 8 | uVar5 >> uVar16 * 8;
          puVar1 = (undefined *)((int)&(pdVar11->bitmap).map + 3);
          uVar16 = (uint)puVar1 & 3;
          puVar15 = (uint *)(puVar1 + -uVar16);
          *puVar15 = *puVar15 & 0xffffffffU >> (uVar16 + 1) * 8 | uVar5 << (3 - uVar16) * 8;
          *(undefined4 *)(pdVar11->bitmap).max_seq_num = uVar13;
          *(undefined4 *)((pdVar11->bitmap).max_seq_num + 4) = uVar14;
          pdVar11 = param_1->d1;
          *(undefined *)&(pdVar11->next_bitmap).map = 0;
          *(undefined *)((int)&(pdVar11->next_bitmap).map + 1) = 0;
          *(undefined *)((int)&(pdVar11->next_bitmap).map + 2) = 0;
          *(undefined *)((int)&(pdVar11->next_bitmap).map + 3) = 0;
          (pdVar11->next_bitmap).max_seq_num[0] = '\0';
          (pdVar11->next_bitmap).max_seq_num[1] = '\0';
          (pdVar11->next_bitmap).max_seq_num[2] = '\0';
          (pdVar11->next_bitmap).max_seq_num[3] = '\0';
          (pdVar11->next_bitmap).max_seq_num[4] = '\0';
          (pdVar11->next_bitmap).max_seq_num[5] = '\0';
          (pdVar11->next_bitmap).max_seq_num[6] = '\0';
          (pdVar11->next_bitmap).max_seq_num[7] = '\0';
          dtls1_clear_received_buffer(param_1);
          psVar21->read_sequence[0] = '\0';
          psVar21->read_sequence[1] = '\0';
          psVar21->read_sequence[2] = '\0';
          psVar21->read_sequence[3] = '\0';
          psVar21->read_sequence[4] = '\0';
          psVar21->read_sequence[5] = '\0';
          psVar21->read_sequence[6] = '\0';
          psVar21->read_sequence[7] = '\0';
          if (param_1->version != 0x100) goto LAB_0049facc;
          psVar21 = param_1->s3;
          param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
          goto LAB_0049fad0;
        }
        if ((0xb < pdVar11->change_cipher_spec_ok) && (param_1->in_handshake == 0)) {
          dtls1_get_message_header((psVar20->rrec).data,local_68);
          if ((psVar20->rrec).epoch != (uint)param_1->d1->r_epoch) goto LAB_0049fc84;
          if (local_68[0] == '\x14') {
            iVar6 = dtls1_check_timeout_num(param_1);
            if (iVar6 < 0) goto LAB_004a02d8;
            dtls1_retransmit_buffered_messages(param_1);
            (psVar20->rrec).length = 0;
            psVar21 = param_1->s3;
            goto LAB_0049faac;
          }
          if (((param_1->state & 0xfffU) == 3) && (iVar6 = 0x2000, (param_1->s3->flags & 1U) == 0))
          {
            param_1->tlsext_hb_seq = 1;
            param_1->new_session = 1;
            if (param_1->server == 0) {
              iVar6 = 0x1000;
            }
            param_1->state = iVar6;
          }
          uVar16 = (*param_1->handshake_func)(param_1);
          if ((int)uVar16 < 0) goto LAB_004a038c;
          if (uVar16 == 0) {
            uVar13 = 0xe5;
            uVar14 = 0x55c;
            goto LAB_0049fe38;
          }
          if ((param_1->options & 4) == 0) {
            psVar21 = param_1->s3;
            if ((psVar21->rbuf).left == 0) {
              param_1->rwstate = 3;
              goto LAB_004a029c;
            }
            goto LAB_0049faac;
          }
          goto LAB_0049facc;
        }
        if (0x13 < iVar6) {
          if (iVar6 < 0x17) {
            uVar13 = 0x44;
            uVar14 = 0x588;
            goto LAB_004a035c;
          }
          if (iVar6 == 0x17) {
            psVar21 = param_1->s3;
            if (((psVar21->in_read_app_data == 0) || (psVar21->total_renegotiations == 0)) ||
               (((uVar16 = param_1->state, (uVar16 & 0x1000) == 0 || (0x10 < uVar16 - 0x1110)) &&
                (((uVar16 & 0x2000) == 0 || (0x10 < uVar16 - 0x2110)))))) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x102,0xf5,"d1_pkt.c",0x5a0);
              uVar14 = 10;
              goto LAB_004a0374;
            }
            psVar21->in_read_app_data = 2;
            uVar16 = 0xffffffff;
            goto LAB_004a038c;
          }
        }
        if (param_1->version != 0x301) {
          uVar13 = 0xf5;
          uVar14 = 0x57d;
LAB_004a035c:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x102,uVar13,"d1_pkt.c",uVar14);
          uVar14 = 10;
          goto LAB_004a0374;
        }
      }
LAB_0049fc84:
      (psVar20->rrec).length = 0;
      psVar21 = param_1->s3;
      goto LAB_0049faac;
    }
    uVar16 = (*param_1->handshake_func)(param_1);
    if ((int)uVar16 < 0) goto LAB_004a038c;
    if (uVar16 != 0) goto LAB_0049fa94;
    uVar13 = 0xe5;
    uVar14 = 0x361;
  }
LAB_0049fe38:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x102,uVar13,"d1_pkt.c",uVar14);
  uVar16 = 0xffffffff;
LAB_004a038c:
  while (local_2c != *(int *)puVar4) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_004a0920:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x102,0xf6,"d1_pkt.c",0x4e6);
    uVar14 = 0x2f;
LAB_004a0374:
    ssl3_send_alert(param_1,2,uVar14);
    uVar16 = 0xffffffff;
  }
  return uVar16;
}

