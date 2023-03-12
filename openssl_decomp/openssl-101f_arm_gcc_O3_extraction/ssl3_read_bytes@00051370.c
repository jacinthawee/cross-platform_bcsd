
void ssl3_read_bytes(SSL *param_1,int param_2,uchar *param_3,uint param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined4 uVar4;
  EVP_MD *pEVar5;
  uint *puVar6;
  int iVar7;
  BIO *pBVar8;
  uint uVar9;
  uchar *puVar10;
  ssl3_state_st *psVar11;
  uint uVar12;
  uchar *puVar13;
  int iVar14;
  ssl3_state_st *psVar15;
  _func_3152 *p_Var16;
  byte *pbVar17;
  uint uVar18;
  SSL_METHOD *pSVar19;
  ulong uVar20;
  uchar uVar21;
  SSL_SESSION *pSVar22;
  uchar *puVar23;
  uint uVar24;
  uint uVar25;
  _func_3150 *p_Var26;
  uchar *local_c8;
  _func_3152 *local_bc;
  undefined auStack_ac [64];
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __TMC_END__;
  if (((param_1->s3->rbuf).buf != (uchar *)0x0) || (iVar14 = ssl3_setup_read_buffer(), iVar14 != 0))
  {
    uVar12 = param_2 - 0x17;
    if (uVar12 != 0) {
      uVar12 = 1;
    }
    if (param_2 == 0 || param_2 == 0x17) {
      if (param_5 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = uVar12 & 1;
      }
      if (uVar12 == 0) {
        if (param_2 == 0x16) goto LAB_000513c2;
LAB_0005146c:
        if ((param_1->in_handshake == 0) && (uVar12 = SSL_state(param_1), (uVar12 & 0x3000) != 0)) {
          uVar12 = (*param_1->handshake_func)(param_1);
          if ((int)uVar12 < 0) goto LAB_000515f2;
          if (uVar12 == 0) {
            iVar14 = 0x3dd;
LAB_00051fce:
            ERR_put_error(0x14,0x94,0xe5,"s3_pkt.c",iVar14);
            uVar12 = 0xffffffff;
            goto LAB_000515f2;
          }
        }
        local_bc = (_func_3152 *)0x0;
        psVar11 = param_1->s3;
LAB_0005147e:
        uVar9 = (psVar11->rrec).length;
        param_1->rwstate = 1;
        if ((uVar9 == 0) || (psVar15 = psVar11, param_1->rstate == 0xf1)) {
          pSVar22 = param_1->session;
          uVar24 = param_1->references & 0x20;
          if (uVar24 == 0) {
            uVar25 = 0x4540;
          }
          else {
            if (psVar11->init_extra == 0) {
              ERR_put_error(0x14,0x8f,0x44,"s3_pkt.c",0x133);
              uVar12 = 0xffffffff;
              goto LAB_000515f2;
            }
            uVar25 = 0x8540;
            uVar24 = 0x4000;
          }
          do {
            if ((param_1->rstate != 0xf1) || (uVar12 = param_1->packet_length, uVar12 < 5)) {
              uVar12 = ssl3_read_n(param_1,5,(param_1->s3->rbuf).len,0);
              if ((int)uVar12 < 1) goto LAB_000515f2;
              pbVar17 = param_1->packet;
              param_1->rstate = 0xf1;
              iVar14 = param_1->max_cert_list;
              (psVar11->rrec).type = (uint)*pbVar17;
              bVar2 = pbVar17[1];
              bVar1 = pbVar17[2];
              uVar9 = (uint)CONCAT11(pbVar17[3],pbVar17[4]);
              (psVar11->rrec).length = uVar9;
              uVar3 = CONCAT11(bVar2,bVar1);
              if ((iVar14 == 0) && ((int)(short)uVar3 != param_1->version)) {
                ERR_put_error(0x14,0x8f,0x10b,"s3_pkt.c",0x151);
                if ((((param_1->version ^ (int)(short)uVar3) & 0xff00U) == 0) &&
                   ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0 &&
                    (param_1->write_hash == (EVP_MD_CTX *)0x0)))) {
                  param_1->version = (uint)uVar3;
                  uVar4 = 0x46;
                }
                else {
                  uVar4 = 0x46;
                }
                goto LAB_00051590;
              }
              if (bVar2 != 3) {
                ERR_put_error(0x14,0x8f,0x10b,"s3_pkt.c",0x15c);
                uVar12 = 0xffffffff;
                goto LAB_000515f2;
              }
              if ((param_1->s3->rbuf).len - 5 < uVar9) {
                ERR_put_error(0x14,0x8f,0xc6,"s3_pkt.c",0x163);
                uVar4 = 0x16;
                goto LAB_00051590;
              }
              uVar12 = param_1->packet_length;
            }
            if (uVar12 - 5 < uVar9) {
              uVar12 = ssl3_read_n(param_1,uVar9,uVar9,1);
              if ((int)uVar12 < 1) goto LAB_000515f2;
              uVar9 = (psVar11->rrec).length;
            }
            puVar10 = param_1->packet;
            param_1->rstate = 0xf0;
            (psVar11->rrec).input = puVar10 + 5;
            if (uVar25 < uVar9) {
              ERR_put_error(0x14,0x8f,0x96,"s3_pkt.c",0x18b);
              uVar4 = 0x16;
              goto LAB_00051590;
            }
            pSVar19 = param_1->method;
            (psVar11->rrec).data = puVar10 + 5;
            iVar14 = (**(code **)pSVar19->ssl3_enc)(param_1,0);
            if (iVar14 == 0) {
              ERR_put_error(0x14,0x8f,0x81,"s3_pkt.c",0x19a);
              uVar4 = 0x15;
              goto LAB_00051590;
            }
            if (((pSVar22 != (SSL_SESSION *)0x0) && (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)
                ) && (pEVar5 = EVP_MD_CTX_md(param_1->read_hash), pEVar5 != (EVP_MD *)0x0)) {
              pEVar5 = EVP_MD_CTX_md(param_1->read_hash);
              uVar12 = EVP_MD_size(pEVar5);
              if (0x40 < uVar12) {
                OpenSSLDie("s3_pkt.c",0x1ad,"mac_size <= EVP_MAX_MD_SIZE");
              }
              uVar9 = (psVar11->rrec).length + ((uint)(psVar11->rrec).type >> 8);
              if ((uVar9 < uVar12) ||
                 ((uVar20 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx), (uVar20 & 0xf0007) == 2 &&
                  (uVar9 < uVar12 + 1)))) {
                ERR_put_error(0x14,0x8f,0xa0,"s3_pkt.c",0x1bd);
                uVar4 = 0x32;
              }
              else {
                uVar20 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx);
                if ((uVar20 & 0xf0007) == 2) {
                  local_c8 = auStack_6c;
                  ssl3_cbc_copy_mac(local_c8,&psVar11->rrec,uVar12,uVar9);
                  uVar9 = 0;
                  (psVar11->rrec).length = (psVar11->rrec).length - uVar12;
                }
                else {
                  uVar9 = (psVar11->rrec).length - uVar12;
                  (psVar11->rrec).length = uVar9;
                  local_c8 = (psVar11->rrec).data + uVar9;
                  if (local_c8 == (uchar *)0x0) {
                    uVar9 = 1;
                  }
                  else {
                    uVar9 = 0;
                  }
                }
                uVar18 = (**(code **)(param_1->method->ssl3_enc + 4))(param_1,auStack_ac,0);
                if ((uVar9 | uVar18 >> 0x1f) == 0) {
                  iVar7 = CRYPTO_memcmp(auStack_ac,local_c8,uVar12);
                  if (iVar7 != 0) {
                    iVar14 = -1;
                  }
                }
                else {
                  iVar14 = -1;
                }
                if ((psVar11->rrec).length <= uVar12 + uVar24 + 0x4400) goto LAB_000517c6;
LAB_000517a8:
                ERR_put_error(0x14,0x8f,0x119,"s3_pkt.c",0x1e4);
                uVar4 = 0x14;
              }
              goto LAB_00051590;
            }
LAB_000517c6:
            if (iVar14 < 0) goto LAB_000517a8;
            if (param_1->expand != (COMP_CTX *)0x0) {
              if (uVar24 + 0x4400 < (psVar11->rrec).length) {
                ERR_put_error(0x14,0x8f,0x8c,"s3_pkt.c",0x1ee);
                uVar4 = 0x16;
                goto LAB_00051590;
              }
              psVar15 = param_1->s3;
              uVar12 = COMP_expand_block(param_1->expand,(psVar15->rrec).comp,0x4000,
                                         (psVar15->rrec).data,(psVar15->rrec).length);
              if ((int)uVar12 < 0) {
                ERR_put_error(0x14,0x8f,0x6b,"s3_pkt.c",500);
                uVar4 = 0x1e;
                goto LAB_00051590;
              }
              (psVar15->rrec).length = uVar12;
              (psVar15->rrec).data = (psVar15->rrec).comp;
            }
            uVar9 = (psVar11->rrec).length;
            if (uVar24 + 0x4000 < uVar9) {
              ERR_put_error(0x14,0x8f,0x92,"s3_pkt.c",0x1fc);
              uVar4 = 0x16;
              goto LAB_00051590;
            }
            (psVar11->rrec).off = 0;
            param_1->packet_length = 0;
          } while (uVar9 == 0);
          psVar15 = param_1->s3;
        }
        if ((psVar15->change_cipher_spec != 0) && ((psVar11->rrec).type != 0x16)) {
          ERR_put_error(0x14,0x94,0x91,"s3_pkt.c",0x3f8);
          uVar4 = 10;
          goto LAB_00051590;
        }
        uVar12 = param_1->shutdown & 2;
        if (uVar12 != 0) {
          (psVar11->rrec).length = 0;
          param_1->rwstate = 1;
          uVar12 = 0;
          goto LAB_000515f2;
        }
        iVar14 = (psVar11->rrec).type;
        if (iVar14 == param_2) {
          uVar12 = SSL_state(param_1);
          if ((((uVar12 & 0x3000) == 0) || (param_2 != 0x17)) ||
             (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) {
            uVar12 = param_4;
            if (0 < (int)param_4) {
              uVar12 = (psVar11->rrec).length;
              if (param_4 <= uVar12) {
                uVar12 = param_4;
              }
              memcpy(param_3,(psVar11->rrec).data + (psVar11->rrec).off,uVar12);
              if (param_5 == 0) {
                uVar9 = (psVar11->rrec).length - uVar12;
                (psVar11->rrec).length = uVar9;
                (psVar11->rrec).off = (psVar11->rrec).off + uVar12;
                if (uVar9 == 0) {
                  uVar20 = param_1->options;
                  param_1->rstate = 0xf0;
                  (psVar11->rrec).off = 0;
                  if ((int)(uVar20 << 0x1b) < 0) {
                    ssl3_release_read_buffer(param_1);
                  }
                }
              }
            }
            goto LAB_000515f2;
          }
          ERR_put_error(0x14,0x94,100,"s3_pkt.c",0x40e);
          uVar4 = 10;
          goto LAB_00051590;
        }
        if (iVar14 == 0x16) {
          puVar10 = psVar15->handshake_fragment;
          puVar6 = &psVar15->handshake_fragment_len;
          uVar24 = 4;
LAB_00051840:
          uVar18 = *puVar6;
          uVar25 = uVar24 - uVar18;
          if (uVar9 <= uVar24 - uVar18) {
            uVar25 = uVar9;
          }
          iVar14 = uVar25 - 1;
          if (uVar25 != 0) {
            do {
              puVar23 = (psVar11->rrec).data;
              *puVar6 = uVar18 + 1;
              iVar14 = iVar14 + -1;
              uVar9 = (psVar11->rrec).off;
              (psVar11->rrec).off = uVar9 + 1;
              puVar10[uVar18] = puVar23[uVar9];
              (psVar11->rrec).length = (psVar11->rrec).length - 1;
              uVar18 = *puVar6;
            } while (iVar14 != -1);
          }
          if (uVar24 <= uVar18) goto LAB_000514ee;
          goto LAB_00051882;
        }
        if (iVar14 == 0x15) {
          puVar10 = psVar15->alert_fragment;
          puVar6 = &psVar15->alert_fragment_len;
          uVar24 = 2;
          goto LAB_00051840;
        }
        if (iVar14 == 0x18) {
          tls1_process_heartbeat(param_1);
          (psVar11->rrec).length = 0;
          param_1->rwstate = 3;
          pBVar8 = SSL_get_rbio(param_1);
          BIO_clear_flags(pBVar8,0xf);
          pBVar8 = SSL_get_rbio(param_1);
          BIO_set_flags(pBVar8,9);
          uVar12 = 0xffffffff;
          goto LAB_000515f2;
        }
LAB_000514ee:
        if (param_1->server == 0) {
          psVar15 = param_1->s3;
          if ((((3 < psVar15->handshake_fragment_len) && (psVar15->handshake_fragment[0] == '\0'))
              && (param_1->session != (SSL_SESSION *)0x0)) &&
             (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)) {
            psVar15->handshake_fragment_len = 0;
            if ((*(uint *)psVar15->handshake_fragment & 0xffffff00) != 0) {
              ERR_put_error(0x14,0x94,0x69,"s3_pkt.c",0x472);
              uVar4 = 0x32;
              goto LAB_00051590;
            }
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (0,param_1->version,0x16,psVar15->handshake_fragment,4,param_1,
                         param_1->msg_callback_arg);
            }
            iVar14 = SSL_state(param_1);
            if (iVar14 == 3) {
              psVar11 = param_1->s3;
              if ((psVar11->flags << 0x1f < 0) || (psVar11->renegotiate != 0)) goto LAB_0005147e;
              ssl3_renegotiate(param_1);
              iVar14 = ssl3_renegotiate_check(param_1);
              if (iVar14 != 0) {
                uVar12 = (*param_1->handshake_func)(param_1);
                if ((int)uVar12 < 0) goto LAB_000515f2;
                if (uVar12 == 0) {
                  iVar14 = 0x484;
                  goto LAB_00051fce;
                }
                if ((int)(param_1->options << 0x1d) < 0) goto LAB_00051882;
                psVar11 = param_1->s3;
                if ((psVar11->rbuf).left == 0) {
                  param_1->rwstate = 3;
                  pBVar8 = SSL_get_rbio(param_1);
                  BIO_clear_flags(pBVar8,0xf);
                  BIO_set_flags(pBVar8,9);
                  uVar12 = 0xffffffff;
                  goto LAB_000515f2;
                }
                goto LAB_0005147e;
              }
            }
            goto LAB_00051882;
          }
        }
        else {
          iVar14 = SSL_state(param_1);
          psVar15 = param_1->s3;
          if ((((iVar14 == 3) && (psVar15->send_connection_binding == 0)) &&
              ((0x300 < param_1->version &&
               ((3 < psVar15->handshake_fragment_len && (psVar15->handshake_fragment[0] == '\x01')))
               ))) && ((param_1->session != (SSL_SESSION *)0x0 &&
                       ((*(int *)(param_1->session->krb5_client_princ + 0x24) != 0 &&
                        ((*(uint *)(param_1->psk_server_callback + 0xa4) & 0x40000) == 0)))))) {
            pSVar19 = param_1->method;
            (psVar11->rrec).length = 0;
            iVar14 = (**(code **)(pSVar19->ssl3_enc + 0x30))(100);
            if ((param_1->version == 0x300) && (iVar14 == 0x46)) {
              uVar21 = '(';
            }
            else {
              if (iVar14 < 0) goto LAB_00051882;
              uVar21 = (uchar)iVar14;
            }
            psVar15 = param_1->s3;
            psVar15->send_alert[0] = '\x01';
            psVar11 = param_1->s3;
            psVar15->alert_dispatch = 1;
            psVar11->send_alert[1] = uVar21;
            psVar11 = param_1->s3;
            if ((psVar11->wbuf).left == 0) {
              (*param_1->method->ssl_dispatch_alert)(param_1);
              psVar11 = param_1->s3;
            }
            goto LAB_0005147e;
          }
        }
        if (1 < psVar15->alert_fragment_len) {
          p_Var26 = param_1->msg_callback;
          uVar21 = psVar15->alert_fragment[0];
          psVar15->alert_fragment_len = 0;
          bVar2 = psVar15->alert_fragment[1];
          uVar9 = (uint)bVar2;
          if (p_Var26 != (_func_3150 *)0x0) {
            (*p_Var26)(0,param_1->version,0x15,psVar15->alert_fragment,2,param_1,
                       param_1->msg_callback_arg);
          }
          p_Var16 = param_1->info_callback;
          if (((param_1->info_callback != (_func_3152 *)0x0) ||
              (p_Var16 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
              *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
             (p_Var16 = local_bc, local_bc != (_func_3152 *)0x0)) {
            (*p_Var16)(param_1,0x4004,(int)CONCAT11(uVar21,bVar2));
            local_bc = p_Var16;
          }
          if (uVar21 != '\x01') {
            if (uVar21 != '\x02') {
              ERR_put_error(0x14,0x94,0xf6,"s3_pkt.c",0x4f2);
              uVar4 = 0x2f;
              goto LAB_00051590;
            }
            param_1->rwstate = 1;
            param_1->s3->fatal_alert = uVar9;
            ERR_put_error(0x14,0x94,uVar9 + 1000,"s3_pkt.c",0x4e8);
            BIO_snprintf((char *)auStack_6c,0x10,"%d",uVar9);
            ERR_add_error_data(2,"SSL alert number ",auStack_6c);
            param_1->shutdown = param_1->shutdown | 2;
            SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
            goto LAB_000515f2;
          }
          psVar11 = param_1->s3;
          psVar11->warn_alert = uVar9;
          if (uVar9 == 0) {
            param_1->shutdown = param_1->shutdown | 2;
            goto LAB_000515f2;
          }
          if (uVar9 == 100) goto code_r0x00051574;
          goto LAB_0005147e;
        }
        if (param_1->shutdown << 0x1f < 0) {
          param_1->rwstate = 1;
          (psVar11->rrec).length = 0;
          goto LAB_000515f2;
        }
        iVar14 = (psVar11->rrec).type;
        if (iVar14 == 0x14) {
          if ((((psVar11->rrec).length != 1) || ((psVar11->rrec).off != 0)) ||
             (puVar10 = (psVar11->rrec).data, *puVar10 != '\x01')) {
            ERR_put_error(0x14,0x94,0x67,"s3_pkt.c",0x508);
            uVar4 = 0x2f;
            goto LAB_00051590;
          }
          if ((psVar15->tmp).new_cipher == (SSL_CIPHER *)0x0) {
            ERR_put_error(0x14,0x94,0x85,"s3_pkt.c",0x510);
            uVar4 = 10;
            goto LAB_00051590;
          }
          p_Var26 = param_1->msg_callback;
          (psVar11->rrec).length = 0;
          if (p_Var26 != (_func_3150 *)0x0) {
            (*p_Var26)(0,param_1->version,0x14,puVar10,1,param_1,param_1->msg_callback_arg);
            psVar15 = param_1->s3;
          }
          psVar15->change_cipher_spec = 1;
          iVar14 = ssl3_do_change_cipher_spec(param_1);
          if (iVar14 == 0) goto LAB_00051c2a;
        }
        else {
          if ((psVar15->handshake_fragment_len < 4) || (param_1->in_handshake != 0)) {
            if (iVar14 < 0x14) {
LAB_00051c4c:
              if (param_1->version - 0x301U < 2) {
                (psVar11->rrec).length = 0;
                psVar11 = psVar15;
                goto LAB_0005147e;
              }
              iVar14 = 0x55b;
            }
            else {
              if (iVar14 < 0x17) {
                ERR_put_error(0x14,0x94,0x44,"s3_pkt.c",0x564);
                uVar4 = 10;
                goto LAB_00051590;
              }
              if (iVar14 != 0x17) goto LAB_00051c4c;
              if (((psVar15->in_read_app_data != 0) && (psVar15->total_renegotiations != 0)) &&
                 (((iVar14 = param_1->state, iVar14 << 0x13 < 0 && (iVar14 - 0x1110U < 0x11)) ||
                  ((iVar14 << 0x12 < 0 && (iVar14 - 0x2110U < 0x11)))))) {
                psVar15->in_read_app_data = 2;
                uVar12 = 0xffffffff;
                goto LAB_000515f2;
              }
              iVar14 = 0x581;
            }
            ERR_put_error(0x14,0x94,0xf5,"s3_pkt.c",iVar14);
            uVar4 = 10;
            goto LAB_00051590;
          }
          if (((param_1->state & 0xfffU) == 3) && (-1 < psVar15->flags << 0x1f)) {
            param_1->tlsext_hb_seq = 1;
            if (param_1->server == 0) {
              iVar14 = 0x1000;
            }
            else {
              iVar14 = 0x2000;
            }
            param_1->new_session = 1;
            param_1->state = iVar14;
          }
          uVar12 = (*param_1->handshake_func)(param_1);
          if ((int)uVar12 < 0) goto LAB_000515f2;
          if (uVar12 == 0) {
            iVar14 = 0x536;
            goto LAB_00051fce;
          }
          if (-1 < (int)(param_1->options << 0x1d)) {
            psVar11 = param_1->s3;
            if ((psVar11->rbuf).left == 0) {
              param_1->rwstate = 3;
              pBVar8 = SSL_get_rbio(param_1);
              BIO_clear_flags(pBVar8,0xf);
              BIO_set_flags(pBVar8,9);
              uVar12 = 0xffffffff;
              goto LAB_000515f2;
            }
            goto LAB_0005147e;
          }
        }
LAB_00051882:
        psVar11 = param_1->s3;
        goto LAB_0005147e;
      }
    }
    else if (param_2 == 0x16) {
      if (param_5 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = uVar12 & 1;
      }
      if (uVar12 == 0) {
LAB_000513c2:
        psVar11 = param_1->s3;
        if (psVar11->handshake_fragment_len != 0) {
          puVar10 = psVar11->handshake_fragment;
          if ((int)param_4 < 1) {
            uVar12 = 0;
LAB_00051410:
            psVar11->handshake_fragment[0] = *puVar10;
            if (1 < param_1->s3->handshake_fragment_len) {
              param_1->s3->handshake_fragment[1] = puVar10[1];
              if (2 < param_1->s3->handshake_fragment_len) {
                param_1->s3->handshake_fragment[2] = puVar10[2];
                if (3 < param_1->s3->handshake_fragment_len) {
                  param_1->s3->handshake_fragment[3] = puVar10[3];
                }
              }
            }
          }
          else {
            puVar23 = puVar10;
            do {
              puVar13 = puVar23 + 1;
              uVar12 = (int)puVar13 - (int)puVar10;
              *param_3 = *puVar23;
              psVar11 = param_1->s3;
              uVar9 = psVar11->handshake_fragment_len - 1;
              psVar11->handshake_fragment_len = uVar9;
              if (puVar13 == puVar10 + param_4) {
                puVar10 = puVar13;
                if (uVar9 != 0) goto LAB_00051410;
                break;
              }
              puVar23 = puVar13;
              param_3 = param_3 + 1;
            } while (uVar9 != 0);
          }
          goto LAB_000515f2;
        }
        goto LAB_0005146c;
      }
    }
    ERR_put_error(0x14,0x94,0x44,"s3_pkt.c",0x3bb);
    uVar12 = 0xffffffff;
    goto LAB_000515f2;
  }
  goto LAB_00051c2a;
code_r0x00051574:
  ERR_put_error(0x14,0x94,0x153,"s3_pkt.c",0x4da);
  uVar4 = 0x28;
LAB_00051590:
  iVar14 = (**(code **)(param_1->method->ssl3_enc + 0x30))(uVar4);
  if ((param_1->version == 0x300) && (iVar14 == 0x46)) {
    uVar21 = '(';
  }
  else {
    if (iVar14 < 0) goto LAB_00051c2a;
    uVar21 = (uchar)iVar14;
  }
  if (param_1->session != (SSL_SESSION *)0x0) {
    SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
  }
  psVar15 = param_1->s3;
  psVar15->send_alert[0] = '\x02';
  psVar11 = param_1->s3;
  psVar15->alert_dispatch = 1;
  psVar11->send_alert[1] = uVar21;
  if ((param_1->s3->wbuf).left == 0) {
    (*param_1->method->ssl_dispatch_alert)(param_1);
    uVar12 = 0xffffffff;
    goto LAB_000515f2;
  }
LAB_00051c2a:
  uVar12 = 0xffffffff;
LAB_000515f2:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar12);
  }
  return;
}

