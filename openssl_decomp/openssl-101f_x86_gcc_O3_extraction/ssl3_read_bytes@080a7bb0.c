
uint ssl3_read_bytes(SSL *param_1,int param_2,void *param_3,uint param_4,int param_5)

{
  uint *puVar1;
  uchar uVar2;
  byte bVar3;
  short sVar4;
  SSL_SESSION *pSVar5;
  byte *pbVar6;
  SSL_METHOD *pSVar7;
  _func_3150 *p_Var8;
  ushort uVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  EVP_MD *pEVar13;
  uint uVar14;
  ulong uVar15;
  BIO *pBVar16;
  ssl3_state_st *psVar17;
  SSL_CTX *pSVar18;
  uchar *puVar19;
  uint uVar21;
  ssl3_state_st *psVar22;
  uint uVar23;
  uint *puVar24;
  _func_3152 *p_Var25;
  int in_GS_OFFSET;
  bool bVar26;
  int iVar27;
  uchar *local_d0;
  uint local_cc;
  uint local_c8;
  uchar *local_bc;
  _func_3152 *local_b4;
  undefined local_a0 [64];
  uchar local_60 [64];
  int local_20;
  uchar *puVar20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) &&
     (iVar11 = ssl3_setup_read_buffer(param_1), iVar11 == 0)) {
LAB_080a856c:
    local_cc = 0xffffffff;
    uVar10 = local_cc;
    goto LAB_080a7f2b;
  }
  if ((param_2 == 0) || (param_2 == 0x17)) {
    if ((param_5 == 0) || (param_2 == 0x17)) {
      if (param_2 == 0x16) goto LAB_080a7c2b;
      goto LAB_080a7d15;
    }
LAB_080a8660:
    iVar11 = 0x3bb;
    iVar27 = 0x44;
  }
  else {
    if ((param_2 != 0x16) || (param_5 != 0)) goto LAB_080a8660;
LAB_080a7c2b:
    psVar22 = param_1->s3;
    if (psVar22->handshake_fragment_len != 0) {
      puVar19 = psVar22->handshake_fragment;
      if ((int)param_4 < 1) {
        local_cc = 0;
LAB_080a7c97:
        psVar22->handshake_fragment[0] = *puVar19;
        uVar10 = local_cc;
        if (1 < param_1->s3->handshake_fragment_len) {
          param_1->s3->handshake_fragment[1] = puVar19[1];
          if (2 < param_1->s3->handshake_fragment_len) {
            param_1->s3->handshake_fragment[2] = puVar19[2];
            if (3 < param_1->s3->handshake_fragment_len) {
              param_1->s3->handshake_fragment[3] = puVar19[3];
            }
          }
        }
      }
      else {
        local_cc = 0;
        puVar20 = puVar19;
        do {
          puVar19 = puVar20 + 1;
          *(uchar *)((int)param_3 + local_cc) = *puVar20;
          psVar22 = param_1->s3;
          local_cc = local_cc + 1;
          uVar23 = psVar22->handshake_fragment_len - 1;
          psVar22->handshake_fragment_len = uVar23;
          uVar10 = local_cc;
          if (local_cc == param_4) {
            if (uVar23 != 0) goto LAB_080a7c97;
            break;
          }
          puVar20 = puVar19;
        } while (uVar23 != 0);
      }
      goto LAB_080a7f2b;
    }
LAB_080a7d15:
    if ((param_1->in_handshake != 0) || (uVar10 = SSL_state(param_1), (uVar10 & 0x3000) == 0)) {
LAB_080a7d20:
      local_b4 = (_func_3152 *)0x0;
      psVar22 = param_1->s3;
LAB_080a7d38:
      do {
        uVar10 = (psVar22->rrec).length;
        param_1->rwstate = 1;
        if ((uVar10 == 0) || (psVar17 = psVar22, param_1->rstate == 0xf1)) {
          pSVar5 = param_1->session;
          if ((*(byte *)&param_1->references & 0x20) == 0) {
            local_c8 = 0x4540;
            local_cc = 0;
          }
          else {
            if (psVar22->init_extra == 0) {
              iVar27 = 0x133;
              iVar11 = 0x44;
LAB_080a893e:
              ERR_put_error(0x14,0x8f,iVar11,"s3_pkt.c",iVar27);
              local_cc = 0xffffffff;
              uVar10 = local_cc;
              goto LAB_080a7f2b;
            }
            local_c8 = 0x8540;
            local_cc = 0x4000;
          }
          uVar23 = local_cc + 0x4400;
          do {
            if ((param_1->rstate != 0xf1) || (param_1->packet_length < 5)) {
              uVar10 = ssl3_read_n(param_1,5,(param_1->s3->rbuf).len,0);
              if ((int)uVar10 < 1) goto LAB_080a7f2b;
              pbVar6 = param_1->packet;
              param_1->rstate = 0xf1;
              iVar11 = param_1->max_cert_list;
              (psVar22->rrec).type = (uint)*pbVar6;
              bVar3 = pbVar6[1];
              uVar9 = CONCAT11(bVar3,pbVar6[2]);
              uVar10 = (uint)(ushort)(*(ushort *)(pbVar6 + 3) << 8 | *(ushort *)(pbVar6 + 3) >> 8);
              (psVar22->rrec).length = uVar10;
              if ((iVar11 == 0) && ((int)(short)uVar9 != param_1->version)) {
                ERR_put_error(0x14,0x8f,0x10b,"s3_pkt.c",0x151);
                uVar12 = 0x46;
                if ((((((int)(short)uVar9 ^ param_1->version) & 0xff00U) == 0) &&
                    (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) &&
                   (param_1->write_hash == (EVP_MD_CTX *)0x0)) {
                  param_1->version = (uint)uVar9;
                }
              }
              else {
                if (bVar3 != 3) {
                  iVar27 = 0x15c;
                  iVar11 = 0x10b;
                  goto LAB_080a893e;
                }
                if (uVar10 <= (param_1->s3->rbuf).len - 5) {
                  if (param_1->packet_length - 5 < uVar10) goto LAB_080a8274;
                  goto LAB_080a7fc0;
                }
                iVar27 = 0x163;
                iVar11 = 0xc6;
LAB_080a87c4:
                ERR_put_error(0x14,0x8f,iVar11,"s3_pkt.c",iVar27);
                uVar12 = 0x16;
              }
              goto LAB_080a7ea0;
            }
            uVar10 = (psVar22->rrec).length;
            if (param_1->packet_length - 5 < uVar10) {
LAB_080a8274:
              uVar10 = ssl3_read_n(param_1,uVar10,uVar10,1);
              if ((int)uVar10 < 1) goto LAB_080a7f2b;
              uVar10 = (psVar22->rrec).length;
            }
LAB_080a7fc0:
            puVar19 = param_1->packet;
            param_1->rstate = 0xf0;
            (psVar22->rrec).input = puVar19 + 5;
            if (local_c8 < uVar10) {
              iVar27 = 0x18b;
              iVar11 = 0x96;
              goto LAB_080a87c4;
            }
            pSVar7 = param_1->method;
            (psVar22->rrec).data = puVar19 + 5;
            iVar11 = (**(code **)pSVar7->ssl3_enc)(param_1,0);
            if (iVar11 == 0) {
              ERR_put_error(0x14,0x8f,0x81,"s3_pkt.c",0x19a);
              uVar12 = 0x15;
              goto LAB_080a7ea0;
            }
            if (((pSVar5 != (SSL_SESSION *)0x0) && (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0))
               && (pEVar13 = EVP_MD_CTX_md(param_1->read_hash), pEVar13 != (EVP_MD *)0x0)) {
              pEVar13 = EVP_MD_CTX_md(param_1->read_hash);
              uVar10 = EVP_MD_size(pEVar13);
              if (0x40 < uVar10) {
                OpenSSLDie("s3_pkt.c",0x1ad,"mac_size <= EVP_MAX_MD_SIZE");
              }
              uVar14 = ((uint)(psVar22->rrec).type >> 8) + (psVar22->rrec).length;
              if ((uVar14 < uVar10) ||
                 ((uVar15 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx), (uVar15 & 0xf0007) == 2 &&
                  (uVar14 < uVar10 + 1)))) {
                ERR_put_error(0x14,0x8f,0xa0,"s3_pkt.c",0x1bd);
                uVar12 = 0x32;
              }
              else {
                uVar15 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx);
                if ((uVar15 & 0xf0007) == 2) {
                  ssl3_cbc_copy_mac(local_60,&psVar22->rrec,uVar10,uVar14);
                  puVar24 = &(psVar22->rrec).length;
                  *puVar24 = *puVar24 - uVar10;
                  bVar26 = false;
                  local_bc = local_60;
                }
                else {
                  uVar14 = (psVar22->rrec).length - uVar10;
                  (psVar22->rrec).length = uVar14;
                  local_bc = (psVar22->rrec).data + uVar14;
                  bVar26 = local_bc == (uchar *)0x0;
                }
                iVar27 = (**(code **)(param_1->method->ssl3_enc + 4))(param_1,local_a0,0);
                if (((iVar27 < 0) || (bVar26)) ||
                   (iVar27 = CRYPTO_memcmp(local_a0,local_bc,uVar10), iVar27 != 0)) {
                  iVar11 = -1;
                }
                puVar24 = &(psVar22->rrec).length;
                if (*puVar24 < uVar10 + uVar23 || *puVar24 == uVar10 + uVar23) goto LAB_080a8140;
LAB_080a810e:
                ERR_put_error(0x14,0x8f,0x119,"s3_pkt.c",0x1e4);
                uVar12 = 0x14;
              }
              goto LAB_080a7ea0;
            }
LAB_080a8140:
            if (iVar11 < 0) goto LAB_080a810e;
            if (param_1->expand != (COMP_CTX *)0x0) {
              puVar24 = &(psVar22->rrec).length;
              if (uVar23 <= *puVar24 && *puVar24 != uVar23) {
                iVar27 = 0x1ee;
                iVar11 = 0x8c;
                goto LAB_080a87c4;
              }
              psVar17 = param_1->s3;
              uVar10 = COMP_expand_block(param_1->expand,(psVar17->rrec).comp,0x4000,
                                         (psVar17->rrec).data,(psVar17->rrec).length);
              if ((int)uVar10 < 0) {
                ERR_put_error(0x14,0x8f,0x6b,"s3_pkt.c",500);
                uVar12 = 0x1e;
                goto LAB_080a7ea0;
              }
              (psVar17->rrec).length = uVar10;
              (psVar17->rrec).data = (psVar17->rrec).comp;
            }
            uVar10 = (psVar22->rrec).length;
            if (local_cc + 0x4000 < uVar10) {
              iVar27 = 0x1fc;
              iVar11 = 0x92;
              goto LAB_080a87c4;
            }
            (psVar22->rrec).off = 0;
            param_1->packet_length = 0;
          } while (uVar10 == 0);
          psVar17 = param_1->s3;
        }
        if ((psVar17->change_cipher_spec != 0) && ((psVar22->rrec).type != 0x16)) {
          iVar27 = 0x3f8;
          iVar11 = 0x91;
          goto LAB_080a8984;
        }
        uVar10 = param_1->shutdown & 2;
        if (uVar10 != 0) {
          local_cc = 0;
          (psVar22->rrec).length = 0;
          param_1->rwstate = 1;
          uVar10 = local_cc;
          goto LAB_080a7f2b;
        }
        iVar11 = (psVar22->rrec).type;
        if (param_2 == iVar11) {
          uVar10 = SSL_state(param_1);
          if ((((uVar10 & 0x3000) != 0) && (param_2 == 0x17)) &&
             (param_1->enc_read_ctx == (EVP_CIPHER_CTX *)0x0)) {
            iVar27 = 0x40e;
            iVar11 = 100;
            goto LAB_080a8984;
          }
          if ((int)param_4 < 1) {
            local_cc = param_4;
            uVar10 = local_cc;
          }
          else {
            uVar10 = (psVar22->rrec).length;
            if (param_4 < uVar10) {
              uVar10 = param_4;
            }
            memcpy(param_3,(psVar22->rrec).data + (psVar22->rrec).off,uVar10);
            if (param_5 == 0) {
              puVar24 = &(psVar22->rrec).off;
              *puVar24 = *puVar24 + uVar10;
              uVar23 = (psVar22->rrec).length - uVar10;
              (psVar22->rrec).length = uVar23;
              if (uVar23 == 0) {
                bVar3 = *(byte *)&param_1->options;
                param_1->rstate = 0xf0;
                (psVar22->rrec).off = 0;
                if ((bVar3 & 0x10) != 0) {
                  ssl3_release_read_buffer(param_1);
                }
              }
            }
          }
          goto LAB_080a7f2b;
        }
        if (iVar11 == 0x16) {
          local_d0 = psVar17->handshake_fragment;
          local_c8 = 4;
          puVar24 = &psVar17->handshake_fragment_len;
LAB_080a8420:
          uVar14 = *puVar24;
          uVar23 = (psVar22->rrec).length;
          uVar21 = local_c8 - uVar14;
          if (uVar23 < local_c8 - uVar14) {
            uVar21 = uVar23;
          }
          iVar11 = uVar21 - 1;
          if (uVar21 != 0) {
            while( true ) {
              puVar19 = (psVar22->rrec).data;
              iVar11 = iVar11 + -1;
              *puVar24 = uVar14 + 1;
              uVar23 = (psVar22->rrec).off;
              (psVar22->rrec).off = uVar23 + 1;
              local_d0[uVar14] = puVar19[uVar23];
              puVar1 = &(psVar22->rrec).length;
              *puVar1 = *puVar1 - 1;
              if (iVar11 == -1) break;
              uVar14 = *puVar24;
            }
            uVar14 = *puVar24;
          }
          if (local_c8 <= uVar14) goto LAB_080a7db1;
          goto LAB_080a8486;
        }
        if (iVar11 == 0x15) {
          local_d0 = psVar17->alert_fragment;
          local_c8 = 2;
          puVar24 = &psVar17->alert_fragment_len;
          goto LAB_080a8420;
        }
        if (iVar11 == 0x18) {
          tls1_process_heartbeat(param_1);
          (psVar22->rrec).length = 0;
          param_1->rwstate = 3;
          pBVar16 = SSL_get_rbio(param_1);
          BIO_clear_flags(pBVar16,0xf);
          pBVar16 = SSL_get_rbio(param_1);
          BIO_set_flags(pBVar16,9);
          local_cc = 0xffffffff;
          uVar10 = local_cc;
          goto LAB_080a7f2b;
        }
LAB_080a7db1:
        if (param_1->server == 0) {
          psVar17 = param_1->s3;
          if ((((psVar17->handshake_fragment_len < 4) || (psVar17->handshake_fragment[0] != '\0'))
              || (param_1->session == (SSL_SESSION *)0x0)) ||
             (*(int *)(param_1->session->krb5_client_princ + 0x24) == 0)) goto LAB_080a7dd4;
          psVar17->handshake_fragment_len = 0;
          if ((*(uint *)psVar17->handshake_fragment & 0xffffff00) != 0) {
            ERR_put_error(0x14,0x94,0x69,"s3_pkt.c",0x472);
            uVar12 = 0x32;
            goto LAB_080a7ea0;
          }
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (0,param_1->version,0x16,psVar17->handshake_fragment,4,param_1,
                       param_1->msg_callback_arg);
          }
          iVar11 = SSL_state(param_1);
          if (iVar11 == 3) {
            psVar22 = param_1->s3;
            if (((*(byte *)&psVar22->flags & 1) != 0) || (psVar22->renegotiate != 0))
            goto LAB_080a7d38;
            ssl3_renegotiate(param_1);
            iVar11 = ssl3_renegotiate_check(param_1);
            if (iVar11 == 0) goto LAB_080a8486;
            uVar10 = (*param_1->handshake_func)(param_1);
            if ((int)uVar10 < 0) goto LAB_080a7f2b;
            if (uVar10 == 0) {
              iVar11 = 0x484;
              goto LAB_080a83a8;
            }
LAB_080a85fd:
            if ((*(byte *)&param_1->options & 4) == 0) {
              psVar22 = param_1->s3;
              if ((psVar22->rbuf).left == 0) {
                param_1->rwstate = 3;
                pBVar16 = SSL_get_rbio(param_1);
                BIO_clear_flags(pBVar16,0xf);
                BIO_set_flags(pBVar16,9);
                local_cc = 0xffffffff;
                uVar10 = local_cc;
                goto LAB_080a7f2b;
              }
              goto LAB_080a7d38;
            }
          }
LAB_080a8486:
          psVar22 = param_1->s3;
          goto LAB_080a7d38;
        }
        iVar11 = SSL_state(param_1);
        psVar17 = param_1->s3;
        if ((((((iVar11 == 3) && (psVar17->send_connection_binding == 0)) &&
              (0x300 < param_1->version)) &&
             ((3 < psVar17->handshake_fragment_len && (psVar17->handshake_fragment[0] == '\x01'))))
            && (param_1->session != (SSL_SESSION *)0x0)) &&
           ((*(int *)(param_1->session->krb5_client_princ + 0x24) != 0 &&
            (((byte)param_1->psk_server_callback[0xa6] & 4) == 0)))) {
          pSVar7 = param_1->method;
          (psVar22->rrec).length = 0;
          iVar11 = (**(code **)(pSVar7->ssl3_enc + 0x30))(100);
          if ((param_1->version == 0x300) && (iVar11 == 0x46)) {
            iVar11 = 0x28;
          }
          else if (iVar11 < 0) goto LAB_080a8486;
          psVar22 = param_1->s3;
          psVar22->send_alert[0] = '\x01';
          psVar22->alert_dispatch = 1;
          param_1->s3->send_alert[1] = (uchar)iVar11;
          psVar22 = param_1->s3;
          if ((psVar22->wbuf).left == 0) {
            (*param_1->method->ssl_dispatch_alert)(param_1);
            psVar22 = param_1->s3;
          }
          goto LAB_080a7d38;
        }
LAB_080a7dd4:
        if (psVar17->alert_fragment_len < 2) {
          if ((*(byte *)&param_1->shutdown & 1) != 0) {
            param_1->rwstate = 1;
            (psVar22->rrec).length = 0;
            goto LAB_080a7f2b;
          }
          iVar11 = (psVar22->rrec).type;
          if (iVar11 == 0x14) {
            if ((((psVar22->rrec).length != 1) || ((psVar22->rrec).off != 0)) ||
               (puVar19 = (psVar22->rrec).data, *puVar19 != '\x01')) {
              iVar27 = 0x508;
              iVar11 = 0x67;
              goto LAB_080a8cd9;
            }
            if ((psVar17->tmp).new_cipher != (SSL_CIPHER *)0x0) {
              p_Var8 = param_1->msg_callback;
              (psVar22->rrec).length = 0;
              if (p_Var8 != (_func_3150 *)0x0) {
                (*p_Var8)(0,param_1->version,0x14,puVar19,1,param_1,param_1->msg_callback_arg);
                psVar17 = param_1->s3;
              }
              psVar17->change_cipher_spec = 1;
              iVar11 = ssl3_do_change_cipher_spec(param_1);
              if (iVar11 != 0) goto LAB_080a8486;
              goto LAB_080a856c;
            }
            iVar27 = 0x510;
            iVar11 = 0x85;
          }
          else {
            if ((3 < psVar17->handshake_fragment_len) && (param_1->in_handshake == 0)) {
              if (((param_1->state & 0xfffU) == 3) && ((*(byte *)&psVar17->flags & 1) == 0)) {
                param_1->tlsext_hb_seq = 1;
                param_1->new_session = 1;
                param_1->state = (-(uint)(param_1->server == 0) & 0xfffff000) + 0x2000;
              }
              uVar10 = (*param_1->handshake_func)(param_1);
              if ((int)uVar10 < 0) goto LAB_080a7f2b;
              if (uVar10 != 0) goto LAB_080a85fd;
              iVar11 = 0x536;
              goto LAB_080a83a8;
            }
            if (iVar11 < 0x14) {
LAB_080a88f1:
              if (param_1->version - 0x301U < 2) {
                (psVar22->rrec).length = 0;
                psVar22 = psVar17;
                goto LAB_080a7d38;
              }
              iVar27 = 0x55b;
            }
            else {
              if (iVar11 < 0x17) {
                iVar27 = 0x564;
                iVar11 = 0x44;
                goto LAB_080a8984;
              }
              if (iVar11 != 0x17) goto LAB_080a88f1;
              if (((psVar17->in_read_app_data != 0) && (psVar17->total_renegotiations != 0)) &&
                 (((uVar10 = param_1->state, uVar10 - 0x1110 < 0x11 && ((uVar10 & 0x1000) != 0)) ||
                  ((uVar10 - 0x2110 < 0x11 && ((uVar10 & 0x2000) != 0)))))) {
                psVar17->in_read_app_data = 2;
                goto LAB_080a856c;
              }
              iVar27 = 0x581;
            }
            iVar11 = 0xf5;
          }
LAB_080a8984:
          ERR_put_error(0x14,0x94,iVar11,"s3_pkt.c",iVar27);
          uVar12 = 10;
          goto LAB_080a7ea0;
        }
        sVar4 = *(short *)psVar17->alert_fragment;
        uVar2 = psVar17->alert_fragment[0];
        uVar23 = (uint)psVar17->alert_fragment[1];
        psVar17->alert_fragment_len = 0;
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0x15,psVar17->alert_fragment,2,param_1,
                     param_1->msg_callback_arg);
        }
        p_Var25 = param_1->info_callback;
        if (((param_1->info_callback != (_func_3152 *)0x0) ||
            (p_Var25 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
            *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
           (p_Var25 = local_b4, local_b4 != (_func_3152 *)0x0)) {
          (*p_Var25)(param_1,0x4004,(uint)(sVar4 << 8) | (uint)(byte)((ushort)sVar4 >> 8));
          local_b4 = p_Var25;
        }
        if (uVar2 != '\x01') {
          if (uVar2 == '\x02') {
            param_1->rwstate = 1;
            param_1->s3->fatal_alert = uVar23;
            ERR_put_error(0x14,0x94,uVar23 + 1000,"s3_pkt.c",0x4e8);
            pSVar18 = (SSL_CTX *)BIO_snprintf((char *)local_60,0x10,"%d",uVar23);
            ERR_add_error_data(2,"SSL alert number ",local_60);
            param_1->shutdown = param_1->shutdown | 2;
            SSL_CTX_remove_session(pSVar18,(SSL_SESSION *)param_1->psk_server_callback);
            goto LAB_080a7f2b;
          }
          iVar27 = 0x4f2;
          iVar11 = 0xf6;
LAB_080a8cd9:
          ERR_put_error(0x14,0x94,iVar11,"s3_pkt.c",iVar27);
          uVar12 = 0x2f;
          goto LAB_080a7ea0;
        }
        psVar22 = param_1->s3;
        psVar22->warn_alert = uVar23;
        if (uVar23 == 0) {
          param_1->shutdown = param_1->shutdown | 2;
          goto LAB_080a7f2b;
        }
      } while (uVar23 != 100);
      ERR_put_error(0x14,0x94,0x153,"s3_pkt.c",0x4da);
      uVar12 = 0x28;
LAB_080a7ea0:
      iVar11 = (**(code **)(param_1->method->ssl3_enc + 0x30))(uVar12);
      if ((param_1->version == 0x300) && (iVar11 == 0x46)) {
        iVar11 = 0x28;
      }
      else if (iVar11 < 0) goto LAB_080a856c;
      if (param_1->session != (SSL_SESSION *)0x0) {
        SSL_CTX_remove_session
                  ((SSL_CTX *)param_1->session,(SSL_SESSION *)param_1->psk_server_callback);
      }
      psVar22 = param_1->s3;
      psVar22->send_alert[0] = '\x02';
      psVar22->alert_dispatch = 1;
      param_1->s3->send_alert[1] = (uchar)iVar11;
      if ((param_1->s3->wbuf).left == 0) {
        (*param_1->method->ssl_dispatch_alert)(param_1);
        local_cc = 0xffffffff;
        uVar10 = local_cc;
        goto LAB_080a7f2b;
      }
      goto LAB_080a856c;
    }
    uVar10 = (*param_1->handshake_func)(param_1);
    if ((int)uVar10 < 0) goto LAB_080a7f2b;
    if (uVar10 != 0) goto LAB_080a7d20;
    iVar11 = 0x3dd;
LAB_080a83a8:
    iVar27 = 0xe5;
  }
  ERR_put_error(0x14,0x94,iVar27,"s3_pkt.c",iVar11);
  local_cc = 0xffffffff;
  uVar10 = local_cc;
LAB_080a7f2b:
  local_cc = uVar10;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_cc;
}

