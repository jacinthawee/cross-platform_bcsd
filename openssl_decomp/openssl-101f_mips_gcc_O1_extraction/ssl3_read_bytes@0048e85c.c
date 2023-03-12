
uchar * ssl3_read_bytes(SSL *param_1,int param_2,uchar *param_3,uchar *param_4,int param_5)

{
  undefined2 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  ssl3_state_st *psVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  ssl3_enc_method *psVar10;
  SSL_METHOD *pSVar11;
  BIO *pBVar12;
  byte *pbVar13;
  uint uVar14;
  uchar *puVar15;
  int iVar16;
  uchar *puVar17;
  SSL_SESSION *pSVar18;
  uint uVar19;
  undefined4 uVar20;
  ssl3_state_st *psVar21;
  char *buf;
  uint *puVar22;
  uint uVar23;
  uchar uVar24;
  uchar *puVar25;
  uchar *puVar26;
  _func_3152 *p_Var27;
  _func_3150 *p_Var28;
  _func_3152 *local_c0;
  undefined auStack_ac [64];
  uchar auStack_6c [64];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  buf = (char *)param_4;
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar5 = ssl3_setup_read_buffer(), iVar5 == 0)) {
    puVar25 = (uchar *)0xffffffff;
  }
  else {
    if (param_2 == 0) {
      buf = "s\n";
      if (param_5 != 0) {
LAB_0048e8ec:
        uVar20 = 0x44;
        buf = "s3_pkt.c";
        uVar4 = 0x3bb;
        goto LAB_0048e8fc;
      }
    }
    else if (param_2 != 0x17) {
      if ((param_2 != 0x16) || (buf = "s\n", param_5 != 0)) goto LAB_0048e8ec;
      psVar21 = param_1->s3;
      if (psVar21->handshake_fragment_len != 0) {
        buf = (char *)psVar21->handshake_fragment;
        if ((int)param_4 < 1) {
          puVar25 = (uchar *)0x0;
LAB_0048f664:
          psVar21->handshake_fragment[0] = *buf;
          if (1 < param_1->s3->handshake_fragment_len) {
            param_1->s3->handshake_fragment[1] = ((uchar *)buf)[1];
            if (2 < param_1->s3->handshake_fragment_len) {
              param_1->s3->handshake_fragment[2] = ((uchar *)buf)[2];
              if (3 < param_1->s3->handshake_fragment_len) {
                param_1->s3->handshake_fragment[3] = ((uchar *)buf)[3];
              }
            }
          }
        }
        else {
          puVar26 = param_3;
          puVar17 = (uchar *)buf;
          do {
            buf = (char *)(puVar17 + 1);
            puVar15 = puVar26 + 1;
            puVar25 = puVar15 + -(int)param_3;
            *puVar26 = *puVar17;
            psVar21 = param_1->s3;
            uVar19 = psVar21->handshake_fragment_len - 1;
            psVar21->handshake_fragment_len = uVar19;
            if (puVar15 == param_3 + (int)param_4) {
              if (uVar19 != 0) goto LAB_0048f664;
              break;
            }
            puVar26 = puVar15;
            puVar17 = (uchar *)buf;
          } while (uVar19 != 0);
        }
        goto LAB_0048edc0;
      }
    }
    if ((param_1->in_handshake == 0) && (uVar19 = SSL_state(param_1), (uVar19 & 0x3000) != 0)) {
      puVar25 = (uchar *)(*param_1->handshake_func)(param_1);
      if ((int)puVar25 < 0) goto LAB_0048edc0;
      buf = "s\n";
      if (puVar25 == (uchar *)0x0) {
        uVar20 = 0xe5;
        buf = "s3_pkt.c";
        uVar4 = 0x3dd;
        goto LAB_0048e8fc;
      }
    }
    local_c0 = (_func_3152 *)0x0;
    psVar21 = param_1->s3;
LAB_0048e954:
    do {
      uVar19 = (psVar21->rrec).length;
      param_1->rwstate = 1;
      if ((uVar19 == 0) || (psVar6 = psVar21, param_1->rstate == 0xf1)) {
        pSVar18 = param_1->session;
        if ((param_1->references & 0x20U) == 0) {
          uVar23 = 0x4540;
          iVar5 = 0;
        }
        else {
          if (psVar21->init_extra == 0) {
            uVar20 = 0x44;
            uVar4 = 0x133;
LAB_0048f530:
            buf = "s3_pkt.c";
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8f,uVar20,"s3_pkt.c",uVar4);
            puVar25 = (uchar *)0xffffffff;
            goto LAB_0048edc0;
          }
          uVar23 = 0x8540;
          iVar5 = 0x4000;
        }
        uVar14 = iVar5 + 0x4400;
        do {
          if ((param_1->rstate != 0xf1) || (uVar7 = param_1->packet_length, uVar7 < 5)) {
            buf = (char *)0x0;
            puVar25 = (uchar *)ssl3_read_n(param_1,5,(param_1->s3->rbuf).len,0);
            if ((int)puVar25 < 1) goto LAB_0048edc0;
            pbVar13 = param_1->packet;
            iVar16 = param_1->max_cert_list;
            param_1->rstate = 0xf1;
            (psVar21->rrec).type = (uint)*pbVar13;
            uVar19 = (uint)*(ushort *)(pbVar13 + 3);
            uVar7 = (uint)*(short *)(pbVar13 + 1);
            (psVar21->rrec).length = uVar19;
            if ((iVar16 == 0) && (uVar7 != param_1->version)) {
              buf = "s3_pkt.c";
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8f,0x10b,"s3_pkt.c",0x151);
              if ((((uVar7 ^ param_1->version) & 0xff00) == 0) &&
                 ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0 &&
                  (param_1->write_hash == (EVP_MD_CTX *)0x0)))) {
                uVar4 = 0x46;
                param_1->version = uVar7 & 0xffff;
              }
              else {
                uVar4 = 0x46;
              }
              goto LAB_0048ed34;
            }
            if ((int)uVar7 >> 8 != 3) {
              uVar20 = 0x10b;
              uVar4 = 0x15c;
              goto LAB_0048f530;
            }
            if (uVar19 <= (param_1->s3->rbuf).len - 5) {
              uVar7 = param_1->packet_length;
              goto LAB_0048eb88;
            }
            uVar20 = 0xc6;
            uVar4 = 0x163;
LAB_0048ef30:
            buf = "s3_pkt.c";
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8f,uVar20,"s3_pkt.c",uVar4);
            iVar5 = (**(code **)(param_1->method->ssl3_enc + 0x30))(0x16);
            if (param_1->version == 0x300) {
LAB_0048ef64:
              if (iVar5 != 0x46) goto LAB_0048ed58;
              uVar24 = '(';
            }
            else {
LAB_0048ed58:
              uVar24 = (uchar)iVar5;
              if (iVar5 < 0) goto LAB_0048edb8;
            }
            pSVar18 = param_1->session;
            goto LAB_0048ed64;
          }
LAB_0048eb88:
          if (uVar7 - 5 < uVar19) {
            buf = (char *)0x1;
            puVar25 = (uchar *)ssl3_read_n(param_1,uVar19,uVar19,1);
            if ((int)puVar25 < 1) goto LAB_0048edc0;
            uVar19 = (psVar21->rrec).length;
            puVar25 = param_1->packet + 5;
            param_1->rstate = 0xf0;
            (psVar21->rrec).input = puVar25;
          }
          else {
            puVar25 = param_1->packet + 5;
            param_1->rstate = 0xf0;
            (psVar21->rrec).input = puVar25;
          }
          if (uVar23 < uVar19) {
            uVar20 = 0x96;
            uVar4 = 0x18b;
            goto LAB_0048ef30;
          }
          pSVar11 = param_1->method;
          (psVar21->rrec).data = puVar25;
          iVar16 = (**(code **)pSVar11->ssl3_enc)(param_1,0);
          if (iVar16 == 0) {
            buf = "s3_pkt.c";
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8f,0x81,"s3_pkt.c",0x19a);
            uVar4 = 0x15;
LAB_0048ed34:
            iVar5 = (**(code **)(param_1->method->ssl3_enc + 0x30))(uVar4);
            if (param_1->version == 0x300) goto LAB_0048ef64;
            goto LAB_0048ed58;
          }
          if (((pSVar18 != (SSL_SESSION *)0x0) && (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0))
             && (iVar8 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1->read_hash), iVar8 != 0)) {
            uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1->read_hash);
            uVar19 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar4);
            if (0x40 < uVar19) {
              (*(code *)PTR_OpenSSLDie_006a8d4c)("s3_pkt.c",0x1ad,"mac_size <= EVP_MAX_MD_SIZE");
            }
            uVar7 = ((uint)(psVar21->rrec).type >> 8) + (psVar21->rrec).length;
            if ((uVar7 < uVar19) ||
               ((uVar9 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a9230)(param_1->enc_read_ctx),
                (uVar9 & 0xf0007) == 2 && (uVar7 < uVar19 + 1)))) {
              buf = "s3_pkt.c";
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8f,0xa0,"s3_pkt.c",0x1bd);
              uVar4 = 0x32;
              goto LAB_0048ed34;
            }
            uVar9 = (*(code *)PTR_EVP_CIPHER_CTX_flags_006a9230)(param_1->enc_read_ctx);
            if ((uVar9 & 0xf0007) == 2) {
              puVar25 = auStack_6c;
              ssl3_cbc_copy_mac(puVar25,&psVar21->rrec,uVar19,uVar7);
              psVar10 = param_1->method->ssl3_enc;
              (psVar21->rrec).length = (psVar21->rrec).length - uVar19;
              iVar8 = (**(code **)(psVar10 + 4))(param_1,auStack_ac,0);
              if (-1 < iVar8) goto LAB_0048ece0;
LAB_0048ee50:
              iVar16 = -1;
              if ((psVar21->rrec).length <= uVar14 + uVar19) goto LAB_0048ee64;
            }
            else {
              puVar25 = (psVar21->rrec).data;
              psVar10 = param_1->method->ssl3_enc;
              uVar7 = (psVar21->rrec).length - uVar19;
              (psVar21->rrec).length = uVar7;
              iVar8 = (**(code **)(psVar10 + 4))(param_1,auStack_ac,0);
              if ((iVar8 < 0) || (puVar25 = puVar25 + uVar7, puVar25 == (uchar *)0x0))
              goto LAB_0048ee50;
LAB_0048ece0:
              iVar8 = (*(code *)PTR_CRYPTO_memcmp_006a9088)(auStack_ac,puVar25,uVar19);
              if (iVar8 != 0) goto LAB_0048ee50;
              if ((psVar21->rrec).length <= uVar14 + uVar19) goto LAB_0048ee64;
            }
LAB_0048ed10:
            buf = "s3_pkt.c";
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8f,0x119,"s3_pkt.c",0x1e4);
            uVar4 = 0x14;
            goto LAB_0048ed34;
          }
LAB_0048ee64:
          if (iVar16 < 0) goto LAB_0048ed10;
          if (param_1->expand != (COMP_CTX *)0x0) {
            if (uVar14 < (psVar21->rrec).length) {
              uVar20 = 0x8c;
              uVar4 = 0x1ee;
              goto LAB_0048ef30;
            }
            psVar6 = param_1->s3;
            uVar19 = (*(code *)PTR_COMP_expand_block_006a9240)
                               (param_1->expand,(psVar6->rrec).comp,0x4000,(psVar6->rrec).data,
                                (psVar6->rrec).length);
            if ((int)uVar19 < 0) {
              buf = "s3_pkt.c";
              (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x8f,0x6b,"s3_pkt.c",500);
              uVar4 = 0x1e;
              goto LAB_0048ed34;
            }
            (psVar6->rrec).length = uVar19;
            (psVar6->rrec).data = (psVar6->rrec).comp;
          }
          uVar19 = (psVar21->rrec).length;
          buf = "s\n";
          if (iVar5 + 0x4000U < uVar19) {
            uVar20 = 0x92;
            uVar4 = 0x1fc;
            goto LAB_0048ef30;
          }
          (psVar21->rrec).off = 0;
          param_1->packet_length = 0;
        } while (uVar19 == 0);
        psVar6 = param_1->s3;
      }
      if ((psVar6->change_cipher_spec != 0) && (buf = "s\n", (psVar21->rrec).type != 0x16)) {
        uVar20 = 0x91;
        uVar4 = 0x3f8;
        goto LAB_0048f570;
      }
      puVar25 = (uchar *)(param_1->shutdown & 2);
      if (puVar25 != (uchar *)0x0) {
        (psVar21->rrec).length = 0;
        param_1->rwstate = 1;
        puVar25 = (uchar *)0x0;
        goto LAB_0048edc0;
      }
      iVar5 = (psVar21->rrec).type;
      if (param_2 == iVar5) {
        uVar19 = SSL_state(param_1);
        if ((((uVar19 & 0x3000) != 0) && (param_2 == 0x17)) &&
           (buf = "s\n", param_1->enc_read_ctx == (EVP_CIPHER_CTX *)0x0)) {
          uVar20 = 100;
          uVar4 = 0x40e;
          goto LAB_0048f570;
        }
        puVar25 = param_4;
        if (0 < (int)param_4) {
          puVar25 = (uchar *)(psVar21->rrec).length;
          if (param_4 < puVar25) {
            puVar25 = param_4;
          }
          (*(code *)PTR_memcpy_006aabf4)(param_3,(psVar21->rrec).data + (psVar21->rrec).off,puVar25)
          ;
          if (param_5 == 0) {
            uVar19 = (psVar21->rrec).length - (int)puVar25;
            (psVar21->rrec).length = uVar19;
            (psVar21->rrec).off = (uint)(puVar25 + (psVar21->rrec).off);
            if (uVar19 == 0) {
              uVar19 = param_1->options;
              param_1->rstate = 0xf0;
              (psVar21->rrec).off = 0;
              if ((uVar19 & 0x10) != 0) {
                ssl3_release_read_buffer(param_1);
              }
            }
          }
        }
        goto LAB_0048edc0;
      }
      if (iVar5 == 0x16) {
        puVar26 = psVar6->handshake_fragment;
        uVar23 = 4;
        puVar22 = &psVar6->handshake_fragment_len;
LAB_0048f06c:
        uVar14 = *puVar22;
        if (uVar23 - uVar14 <= uVar19) {
          uVar19 = uVar23 - uVar14;
        }
        buf = (char *)(uVar19 - 1);
        if (uVar19 != 0) {
          do {
            puVar17 = (psVar21->rrec).data;
            buf = (char *)((uchar *)buf + -1);
            *puVar22 = uVar14 + 1;
            uVar19 = (psVar21->rrec).off;
            (psVar21->rrec).off = uVar19 + 1;
            puVar26[uVar14] = puVar17[uVar19];
            (psVar21->rrec).length = (psVar21->rrec).length - 1;
            uVar14 = *puVar22;
          } while ((uchar *)buf != (uchar *)0xffffffff);
        }
        if (uVar14 < uVar23) {
          psVar21 = param_1->s3;
          goto LAB_0048e954;
        }
      }
      else {
        if (iVar5 == 0x15) {
          puVar26 = psVar6->alert_fragment;
          uVar23 = 2;
          puVar22 = &psVar6->alert_fragment_len;
          goto LAB_0048f06c;
        }
        if (iVar5 == 0x18) {
          tls1_process_heartbeat(param_1);
          (psVar21->rrec).length = 0;
          param_1->rwstate = 3;
          pBVar12 = SSL_get_rbio(param_1);
          (*(code *)PTR_BIO_clear_flags_006a9260)(pBVar12,0xf);
          pBVar12 = SSL_get_rbio(param_1);
          (*(code *)PTR_BIO_set_flags_006a8660)(pBVar12,9);
          puVar25 = (uchar *)0xffffffff;
          goto LAB_0048edc0;
        }
      }
      if (param_1->server != 0) {
        iVar5 = (*(code *)PTR_SSL_state_006a88f4)(param_1);
        if (iVar5 == 3) {
          psVar6 = param_1->s3;
          if ((((((psVar6->send_connection_binding == 0) && (0x300 < param_1->version)) &&
                (3 < psVar6->handshake_fragment_len)) &&
               ((psVar6->handshake_fragment[0] == '\x01' && (param_1->session != (SSL_SESSION *)0x0)
                ))) && (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)) &&
             (-1 < *(int *)(param_1->psk_server_callback + 0xa4) << 0xd)) {
            pSVar11 = param_1->method;
            (psVar21->rrec).length = 0;
            iVar5 = (**(code **)(pSVar11->ssl3_enc + 0x30))(100);
            if ((param_1->version == 0x300) && (iVar5 == 0x46)) {
              uVar24 = '(';
            }
            else {
              uVar24 = (uchar)iVar5;
              if (iVar5 < 0) goto LAB_0048f03c;
            }
            psVar21 = param_1->s3;
            psVar21->send_alert[0] = '\x01';
            psVar21->alert_dispatch = 1;
            param_1->s3->send_alert[1] = uVar24;
            psVar21 = param_1->s3;
            if ((psVar21->wbuf).left == 0) {
              (*param_1->method->ssl_dispatch_alert)(param_1);
              psVar21 = param_1->s3;
            }
            goto LAB_0048e954;
          }
        }
        else {
          psVar6 = param_1->s3;
        }
LAB_0048e9e4:
        buf = (char *)psVar6->alert_fragment;
        if (psVar6->alert_fragment_len < 2) {
          if ((param_1->shutdown & 1U) != 0) {
            param_1->rwstate = 1;
            (psVar21->rrec).length = 0;
            goto LAB_0048edc0;
          }
          iVar5 = (psVar21->rrec).type;
          if (iVar5 != 0x14) {
            if ((psVar6->handshake_fragment_len < 4) || (param_1->in_handshake != 0)) {
              if (0x13 < iVar5) {
                if (iVar5 < 0x17) {
                  uVar20 = 0x44;
                  uVar4 = 0x564;
                  goto LAB_0048f570;
                }
                if (iVar5 == 0x17) {
                  if (((psVar6->in_read_app_data == 0) || (psVar6->total_renegotiations == 0)) ||
                     (((uVar19 = param_1->state, (uVar19 & 0x1000) == 0 || (0x10 < uVar19 - 0x1110))
                      && (((uVar19 & 0x2000) == 0 || (0x10 < uVar19 - 0x2110)))))) {
                    buf = "s3_pkt.c";
                    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x94,0xf5,"s3_pkt.c",0x581);
                    uVar4 = 10;
                    goto LAB_0048f584;
                  }
                  psVar6->in_read_app_data = 2;
                  puVar25 = (uchar *)0xffffffff;
                  goto LAB_0048edc0;
                }
              }
              buf = "s\n";
              if (1 < param_1->version - 0x301U) {
                uVar20 = 0xf5;
                uVar4 = 0x55b;
LAB_0048f570:
                buf = "s3_pkt.c";
                (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x94,uVar20,"s3_pkt.c",uVar4);
                uVar4 = 10;
                goto LAB_0048f584;
              }
              (psVar21->rrec).length = 0;
              psVar21 = psVar6;
            }
            else {
              if (((param_1->state & 0xfffU) == 3) && (iVar5 = 0x2000, (psVar6->flags & 1U) == 0)) {
                if (param_1->server == 0) {
                  iVar5 = 0x1000;
                }
                param_1->tlsext_hb_seq = 1;
                param_1->new_session = 1;
                param_1->state = iVar5;
              }
              puVar25 = (uchar *)(*param_1->handshake_func)(param_1);
              if ((int)puVar25 < 0) goto LAB_0048edc0;
              buf = "s\n";
              if (puVar25 == (uchar *)0x0) {
                uVar20 = 0xe5;
                buf = "s3_pkt.c";
                uVar4 = 0x536;
                goto LAB_0048e8fc;
              }
              if ((param_1->options & 4) != 0) goto LAB_0048f03c;
              psVar21 = param_1->s3;
              if ((psVar21->rbuf).left == 0) {
                param_1->rwstate = 3;
                goto LAB_0048f4b0;
              }
            }
            goto LAB_0048e954;
          }
          if ((((psVar21->rrec).length != 1) || ((psVar21->rrec).off != 0)) ||
             (buf = (char *)(psVar21->rrec).data, *buf != '\x01')) {
            uVar20 = 0x67;
            uVar4 = 0x508;
            goto LAB_0048f9e4;
          }
          uVar20 = 0x85;
          if ((psVar6->tmp).new_cipher == (SSL_CIPHER *)0x0) {
            uVar4 = 0x510;
            goto LAB_0048f570;
          }
          p_Var28 = param_1->msg_callback;
          (psVar21->rrec).length = 0;
          if (p_Var28 != (_func_3150 *)0x0) {
            (*p_Var28)(0,param_1->version,0x14,buf,1,param_1,param_1->msg_callback_arg);
            psVar6 = param_1->s3;
          }
          psVar6->change_cipher_spec = 1;
          iVar5 = ssl3_do_change_cipher_spec(param_1);
          if (iVar5 != 0) {
            psVar21 = param_1->s3;
            goto LAB_0048e954;
          }
        }
        else {
          p_Var28 = param_1->msg_callback;
          uVar1 = *(undefined2 *)psVar6->alert_fragment;
          uVar24 = psVar6->alert_fragment[0];
          puVar26 = (uchar *)(uint)psVar6->alert_fragment[1];
          psVar6->alert_fragment_len = 0;
          if (p_Var28 != (_func_3150 *)0x0) {
            (*p_Var28)(0,param_1->version,0x15,buf,2,param_1,param_1->msg_callback_arg);
          }
          p_Var27 = param_1->info_callback;
          if (((param_1->info_callback != (_func_3152 *)0x0) ||
              (p_Var27 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
              *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
             (p_Var27 = local_c0, local_c0 != (_func_3152 *)0x0)) {
            (*p_Var27)(param_1,0x4004,(int)uVar1);
            local_c0 = p_Var27;
          }
          puVar2 = PTR_ERR_put_error_006a9030;
          if (uVar24 == '\x01') {
            psVar21 = param_1->s3;
            psVar21->warn_alert = (int)puVar26;
            if (puVar26 == (uchar *)0x0) {
              param_1->shutdown = param_1->shutdown | 2;
              goto LAB_0048edc0;
            }
            if (puVar26 != &DAT_00000064) goto LAB_0048e954;
            buf = "s3_pkt.c";
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x94,0x153,"s3_pkt.c",0x4da);
            uVar4 = 0x28;
          }
          else {
            if (uVar24 == '\x02') {
              param_1->rwstate = 1;
              param_1->s3->fatal_alert = (int)puVar26;
              (*(code *)puVar2)(0x14,0x94,puVar26 + 1000,"s3_pkt.c",0x4e8);
              (*(code *)PTR_BIO_snprintf_006a8060)(auStack_6c,0x10,"%d",puVar26);
              (*(code *)PTR_ERR_add_error_data_006a9264)(2,"SSL alert number ",auStack_6c);
              puVar2 = PTR_SSL_CTX_remove_session_006a9250;
              param_1->shutdown = param_1->shutdown | 2;
              (*(code *)puVar2)(param_1->psk_server_callback,param_1->session);
              buf = (char *)puVar26;
              goto LAB_0048edc0;
            }
            uVar20 = 0xf6;
            uVar4 = 0x4f2;
LAB_0048f9e4:
            buf = "s3_pkt.c";
            (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x94,uVar20,"s3_pkt.c",uVar4);
            uVar4 = 0x2f;
          }
LAB_0048f584:
          iVar5 = (**(code **)(param_1->method->ssl3_enc + 0x30))(uVar4);
          if ((param_1->version == 0x300) && (uVar24 = '(', iVar5 == 0x46)) {
            pSVar18 = param_1->session;
          }
          else {
            uVar24 = (uchar)iVar5;
            if (iVar5 < 0) goto LAB_0048edb8;
            pSVar18 = param_1->session;
          }
LAB_0048ed64:
          if (pSVar18 != (SSL_SESSION *)0x0) {
            (*(code *)PTR_SSL_CTX_remove_session_006a9250)(param_1->psk_server_callback);
          }
          psVar21 = param_1->s3;
          psVar21->send_alert[0] = '\x02';
          psVar21->alert_dispatch = 1;
          param_1->s3->send_alert[1] = uVar24;
          puVar25 = (uchar *)0xffffffff;
          if ((param_1->s3->wbuf).left != 0) goto LAB_0048edc0;
          (*param_1->method->ssl_dispatch_alert)(param_1);
        }
LAB_0048edb8:
        puVar25 = (uchar *)0xffffffff;
        goto LAB_0048edc0;
      }
      psVar6 = param_1->s3;
      if (((psVar6->handshake_fragment_len < 4) || (psVar6->handshake_fragment[0] != '\0')) ||
         ((param_1->session == (SSL_SESSION *)0x0 ||
          (*(int *)(param_1->session->krb5_client_princ + 0x24) == 0)))) goto LAB_0048e9e4;
      psVar6->handshake_fragment_len = 0;
      if ((*(uint *)psVar6->handshake_fragment & 0xffffff) != 0) {
        buf = "s3_pkt.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x94,0x69,"s3_pkt.c",0x472);
        uVar4 = 0x32;
        goto LAB_0048f584;
      }
      buf = (char *)psVar6->handshake_fragment;
      if (param_1->msg_callback != (_func_3150 *)0x0) {
        (*param_1->msg_callback)(0,param_1->version,0x16,buf,4,param_1,param_1->msg_callback_arg);
      }
      iVar5 = (*(code *)PTR_SSL_state_006a88f4)(param_1);
      if (iVar5 != 3) {
LAB_0048f03c:
        psVar21 = param_1->s3;
        goto LAB_0048e954;
      }
      psVar21 = param_1->s3;
      if (((psVar21->flags & 1U) != 0) || (psVar21->renegotiate != 0)) goto LAB_0048e954;
      ssl3_renegotiate(param_1);
      iVar5 = ssl3_renegotiate_check(param_1);
      if (iVar5 == 0) goto LAB_0048f03c;
      puVar25 = (uchar *)(*param_1->handshake_func)(param_1);
      if ((int)puVar25 < 0) goto LAB_0048edc0;
      buf = "s\n";
      if (puVar25 == (uchar *)0x0) goto LAB_0048fa8c;
      if ((param_1->options & 4) != 0) goto LAB_0048f03c;
      psVar21 = param_1->s3;
    } while ((psVar21->rbuf).left != 0);
    param_1->rwstate = 3;
LAB_0048f4b0:
    buf = "s\n";
    pBVar12 = SSL_get_rbio(param_1);
    (*(code *)PTR_BIO_clear_flags_006a9260)(pBVar12,0xf);
    (*(code *)PTR_BIO_set_flags_006a8660)(pBVar12,9);
    puVar25 = (uchar *)0xffffffff;
  }
LAB_0048edc0:
  while (local_2c != *(int *)puVar3) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0048fa8c:
    uVar20 = 0xe5;
    buf = (char *)((uchar *)buf + 0x78a0);
    uVar4 = 0x484;
LAB_0048e8fc:
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x94,uVar20,buf,uVar4);
    puVar25 = (uchar *)0xffffffff;
  }
  return puVar25;
}

