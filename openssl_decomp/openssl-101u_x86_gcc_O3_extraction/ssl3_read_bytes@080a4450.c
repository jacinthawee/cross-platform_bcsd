
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
  uint uVar18;
  uchar *puVar19;
  ssl3_state_st *psVar21;
  uint *puVar22;
  _func_3152 *p_Var23;
  uint uVar24;
  int in_GS_OFFSET;
  bool bVar25;
  SSL_CTX *pSVar26;
  int iVar27;
  uchar *local_d4;
  uint local_d0;
  uint local_cc;
  int local_c4;
  uchar *local_bc;
  _func_3152 *local_b4;
  undefined local_a0 [64];
  uchar local_60 [64];
  int local_20;
  uchar *puVar20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) &&
     (iVar11 = ssl3_setup_read_buffer(param_1), iVar11 == 0)) {
LAB_080a4e71:
    local_d0 = 0xffffffff;
    uVar10 = local_d0;
  }
  else {
    if (((param_2 - 0x16U < 2) || (param_2 == 0)) && (param_5 == 0 || param_2 == 0x17)) {
      if ((param_2 == 0x16) && (psVar21 = param_1->s3, psVar21->handshake_fragment_len != 0)) {
        puVar19 = psVar21->handshake_fragment;
        if ((int)param_4 < 1) {
          local_d0 = 0;
LAB_080a4f2b:
          psVar21->handshake_fragment[0] = *puVar19;
          uVar10 = local_d0;
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
          local_d0 = 0;
          puVar20 = puVar19;
          do {
            puVar19 = puVar20 + 1;
            *(uchar *)((int)param_3 + local_d0) = *puVar20;
            psVar21 = param_1->s3;
            local_d0 = local_d0 + 1;
            uVar24 = psVar21->handshake_fragment_len - 1;
            psVar21->handshake_fragment_len = uVar24;
            uVar10 = local_d0;
            if (local_d0 == param_4) {
              if (uVar24 != 0) goto LAB_080a4f2b;
              break;
            }
            puVar20 = puVar19;
          } while (uVar24 != 0);
        }
        goto LAB_080a46eb;
      }
      if ((param_1->in_handshake != 0) || (uVar10 = SSL_state(param_1), (uVar10 & 0x3000) == 0)) {
LAB_080a44e2:
        local_b4 = (_func_3152 *)0x0;
        psVar21 = param_1->s3;
LAB_080a44f8:
        uVar10 = (psVar21->rrec).length;
        param_1->rwstate = 1;
        if ((uVar10 != 0) && (psVar17 = psVar21, param_1->rstate != 0xf1)) goto LAB_080a451c;
        pSVar5 = param_1->session;
        if ((*(byte *)&param_1->references & 0x20) == 0) {
          local_cc = 0x4540;
          local_d0 = 0;
        }
        else {
          if (psVar21->init_extra == 0) {
            iVar27 = 0x140;
            iVar11 = 0x44;
LAB_080a4e62:
            ERR_put_error(0x14,0x8f,iVar11,"s3_pkt.c",iVar27);
            goto LAB_080a4e71;
          }
          local_cc = 0x8540;
          local_d0 = 0x4000;
        }
        local_c4 = 0x21;
        uVar24 = local_d0 + 0x4400;
        do {
          if ((param_1->rstate != 0xf1) || (param_1->packet_length < 5)) {
            uVar10 = ssl3_read_n(param_1,5,(param_1->s3->rbuf).len,0);
            if ((int)uVar10 < 1) goto LAB_080a46eb;
            pbVar6 = param_1->packet;
            param_1->rstate = 0xf1;
            iVar11 = param_1->max_cert_list;
            (psVar21->rrec).type = (uint)*pbVar6;
            bVar3 = pbVar6[1];
            uVar9 = CONCAT11(bVar3,pbVar6[2]);
            uVar10 = (uint)(ushort)(*(ushort *)(pbVar6 + 3) << 8 | *(ushort *)(pbVar6 + 3) >> 8);
            (psVar21->rrec).length = uVar10;
            if ((iVar11 != 0) || ((int)(short)uVar9 == param_1->version)) {
              if (bVar3 != 3) {
                iVar27 = 0x174;
                iVar11 = 0x10b;
                goto LAB_080a4e62;
              }
              if (uVar10 <= (param_1->s3->rbuf).len - 5) {
                if (param_1->packet_length - 5 < uVar10) goto LAB_080a4a64;
                goto LAB_080a4780;
              }
              iVar27 = 0x17a;
              iVar11 = 0xc6;
LAB_080a515c:
              ERR_put_error(0x14,0x8f,iVar11,"s3_pkt.c",iVar27);
              uVar12 = 0x16;
              goto LAB_080a4660;
            }
            ERR_put_error(0x14,0x8f,0x10b,"s3_pkt.c",0x15c);
            if ((((char)((uint)param_1->version >> 8) == (char)((uint)(int)(short)uVar9 >> 8)) &&
                (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) &&
               (param_1->write_hash == (EVP_MD_CTX *)0x0)) {
              if ((psVar21->rrec).type == 0x15) goto LAB_080a4e71;
              uVar12 = 0x46;
              param_1->version = (uint)uVar9;
            }
            else {
              uVar12 = 0x46;
            }
            goto LAB_080a4660;
          }
          uVar10 = (psVar21->rrec).length;
          if (param_1->packet_length - 5 < uVar10) {
LAB_080a4a64:
            uVar10 = ssl3_read_n(param_1,uVar10,uVar10,1);
            if ((int)uVar10 < 1) goto LAB_080a46eb;
            uVar10 = (psVar21->rrec).length;
          }
LAB_080a4780:
          puVar19 = param_1->packet;
          param_1->rstate = 0xf0;
          (psVar21->rrec).input = puVar19 + 5;
          if (local_cc < uVar10) {
            iVar27 = 0x1a6;
            iVar11 = 0x96;
            goto LAB_080a515c;
          }
          pSVar7 = param_1->method;
          (psVar21->rrec).data = puVar19 + 5;
          iVar11 = (**(code **)pSVar7->ssl3_enc)(param_1,0);
          if (iVar11 == 0) {
            ERR_put_error(0x14,0x8f,0x81,"s3_pkt.c",0x1b6);
            uVar12 = 0x15;
            goto LAB_080a4660;
          }
          if (((pSVar5 != (SSL_SESSION *)0x0) && (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0))
             && (pEVar13 = EVP_MD_CTX_md(param_1->read_hash), pEVar13 != (EVP_MD *)0x0)) {
            pEVar13 = EVP_MD_CTX_md(param_1->read_hash);
            uVar10 = EVP_MD_size(pEVar13);
            if (0x40 < uVar10) {
              OpenSSLDie("s3_pkt.c",0x1ca,"mac_size <= EVP_MAX_MD_SIZE");
            }
            uVar14 = ((uint)(psVar21->rrec).type >> 8) + (psVar21->rrec).length;
            if ((uVar14 < uVar10) ||
               ((uVar15 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx), (uVar15 & 0xf0007) == 2 &&
                (uVar14 < uVar10 + 1)))) {
              ERR_put_error(0x14,0x8f,0xa0,"s3_pkt.c",0x1dc);
              uVar12 = 0x32;
            }
            else {
              uVar15 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx);
              if ((uVar15 & 0xf0007) == 2) {
                ssl3_cbc_copy_mac(local_60,&psVar21->rrec,uVar10,uVar14);
                puVar22 = &(psVar21->rrec).length;
                *puVar22 = *puVar22 - uVar10;
                bVar25 = false;
                local_bc = local_60;
              }
              else {
                uVar14 = (psVar21->rrec).length - uVar10;
                (psVar21->rrec).length = uVar14;
                local_bc = (psVar21->rrec).data + uVar14;
                bVar25 = local_bc == (uchar *)0x0;
              }
              iVar27 = (**(code **)(param_1->method->ssl3_enc + 4))(param_1,local_a0,0);
              if (((iVar27 < 0) || (bVar25)) ||
                 (iVar27 = CRYPTO_memcmp(local_a0,local_bc,uVar10), iVar27 != 0)) {
                iVar11 = -1;
              }
              puVar22 = &(psVar21->rrec).length;
              if (*puVar22 < uVar10 + uVar24 || *puVar22 == uVar10 + uVar24) goto LAB_080a4900;
LAB_080a48ce:
              ERR_put_error(0x14,0x8f,0x119,"s3_pkt.c",0x206);
              uVar12 = 0x14;
            }
            goto LAB_080a4660;
          }
LAB_080a4900:
          if (iVar11 < 0) goto LAB_080a48ce;
          if (param_1->expand != (COMP_CTX *)0x0) {
            puVar22 = &(psVar21->rrec).length;
            if (uVar24 <= *puVar22 && *puVar22 != uVar24) {
              iVar27 = 0x20e;
              iVar11 = 0x8c;
              goto LAB_080a515c;
            }
            psVar17 = param_1->s3;
            uVar10 = COMP_expand_block(param_1->expand,(psVar17->rrec).comp,0x4000,
                                       (psVar17->rrec).data,(psVar17->rrec).length);
            if ((int)uVar10 < 0) {
              ERR_put_error(0x14,0x8f,0x6b,"s3_pkt.c",0x213);
              uVar12 = 0x1e;
              goto LAB_080a4660;
            }
            (psVar17->rrec).length = uVar10;
            (psVar17->rrec).data = (psVar17->rrec).comp;
          }
          uVar10 = (psVar21->rrec).length;
          if (local_d0 + 0x4000 < uVar10) {
            iVar27 = 0x21a;
            iVar11 = 0x92;
            goto LAB_080a515c;
          }
          (psVar21->rrec).off = 0;
          param_1->packet_length = 0;
          if (uVar10 != 0) goto LAB_080a5208;
          local_c4 = local_c4 + -1;
          if (local_c4 == 0) {
            ERR_put_error(0x14,0x8f,0x12a,"s3_pkt.c",0x230);
            uVar12 = 10;
            goto LAB_080a4660;
          }
        } while( true );
      }
      uVar10 = (*param_1->handshake_func)(param_1);
      if ((int)uVar10 < 0) goto LAB_080a46eb;
      if (uVar10 != 0) goto LAB_080a44e2;
      iVar27 = 0x40e;
LAB_080a4b68:
      iVar11 = 0xe5;
    }
    else {
      iVar27 = 0x3eb;
      iVar11 = 0x44;
    }
    ERR_put_error(0x14,0x94,iVar11,"s3_pkt.c",iVar27);
    local_d0 = 0xffffffff;
    uVar10 = local_d0;
  }
LAB_080a46eb:
  local_d0 = uVar10;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_d0;
LAB_080a5208:
  psVar17 = param_1->s3;
LAB_080a451c:
  if ((psVar17->change_cipher_spec == 0) || ((psVar21->rrec).type == 0x16)) {
    uVar10 = param_1->shutdown & 2;
    if (uVar10 != 0) {
      local_d0 = 0;
      (psVar21->rrec).length = 0;
      param_1->rwstate = 1;
      uVar10 = local_d0;
      goto LAB_080a46eb;
    }
    iVar11 = (psVar21->rrec).type;
    if (param_2 != iVar11) {
      if (iVar11 == 0x16) {
        local_d4 = psVar17->handshake_fragment;
        local_cc = 4;
        puVar22 = &psVar17->handshake_fragment_len;
LAB_080a4bc8:
        uVar14 = *puVar22;
        uVar24 = (psVar21->rrec).length;
        uVar18 = local_cc - uVar14;
        if (uVar24 < local_cc - uVar14) {
          uVar18 = uVar24;
        }
        iVar11 = uVar18 - 1;
        if (uVar18 != 0) {
          while( true ) {
            puVar19 = (psVar21->rrec).data;
            iVar11 = iVar11 + -1;
            *puVar22 = uVar14 + 1;
            uVar24 = (psVar21->rrec).off;
            (psVar21->rrec).off = uVar24 + 1;
            local_d4[uVar14] = puVar19[uVar24];
            puVar1 = &(psVar21->rrec).length;
            *puVar1 = *puVar1 - 1;
            if (iVar11 == -1) break;
            uVar14 = *puVar22;
          }
          uVar14 = *puVar22;
        }
        if (uVar14 < local_cc) goto LAB_080a4c36;
      }
      else {
        if (iVar11 == 0x15) {
          local_d4 = psVar17->alert_fragment;
          local_cc = 2;
          puVar22 = &psVar17->alert_fragment_len;
          goto LAB_080a4bc8;
        }
        if (iVar11 == 0x18) {
          tls1_process_heartbeat(param_1);
          (psVar21->rrec).length = 0;
          param_1->rwstate = 3;
          pBVar16 = SSL_get_rbio(param_1);
          BIO_clear_flags(pBVar16,0xf);
          pBVar16 = SSL_get_rbio(param_1);
          BIO_set_flags(pBVar16,9);
          local_d0 = 0xffffffff;
          uVar10 = local_d0;
          goto LAB_080a46eb;
        }
      }
      if (param_1->server == 0) {
        psVar17 = param_1->s3;
        if (((psVar17->handshake_fragment_len < 4) || (psVar17->handshake_fragment[0] != '\0')) ||
           ((param_1->session == (SSL_SESSION *)0x0 ||
            (*(int *)(param_1->session->krb5_client_princ + 0x24) == 0)))) goto LAB_080a4594;
        psVar17->handshake_fragment_len = 0;
        if ((*(uint *)psVar17->handshake_fragment & 0xffffff00) != 0) {
          ERR_put_error(0x14,0x94,0x69,"s3_pkt.c",0x4a1);
          uVar12 = 0x32;
          goto LAB_080a4660;
        }
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0x16,psVar17->handshake_fragment,4,param_1,
                     param_1->msg_callback_arg);
        }
        iVar11 = SSL_state(param_1);
        if (iVar11 != 3) goto LAB_080a4c36;
        psVar21 = param_1->s3;
        if (((*(byte *)&psVar21->flags & 1) != 0) || (psVar21->renegotiate != 0)) goto LAB_080a44f8;
        ssl3_renegotiate(param_1);
        iVar11 = ssl3_renegotiate_check(param_1);
        if (iVar11 == 0) goto LAB_080a4c36;
        uVar10 = (*param_1->handshake_func)(param_1);
        if ((int)uVar10 < 0) goto LAB_080a46eb;
        if (uVar10 == 0) {
          iVar27 = 0x4b4;
          goto LAB_080a4b68;
        }
LAB_080a4df5:
        if ((*(byte *)&param_1->options & 4) == 0) {
          psVar21 = param_1->s3;
          if ((psVar21->rbuf).left == 0) goto code_r0x080a4e13;
          goto LAB_080a44f8;
        }
LAB_080a4c36:
        psVar21 = param_1->s3;
        goto LAB_080a44f8;
      }
      iVar11 = SSL_state(param_1);
      psVar17 = param_1->s3;
      if (((((iVar11 == 3) && (psVar17->send_connection_binding == 0)) && (0x300 < param_1->version)
           ) && ((3 < psVar17->handshake_fragment_len && (psVar17->handshake_fragment[0] == '\x01'))
                )) &&
         ((param_1->session != (SSL_SESSION *)0x0 &&
          ((*(int *)(param_1->session->krb5_client_princ + 0x24) != 0 &&
           (((byte)param_1->psk_server_callback[0xa6] & 4) == 0)))))) {
        pSVar7 = param_1->method;
        (psVar21->rrec).length = 0;
        iVar11 = (**(code **)(pSVar7->ssl3_enc + 0x30))(100);
        if ((param_1->version == 0x300) && (iVar11 == 0x46)) {
          iVar11 = 0x28;
        }
        else if (iVar11 < 0) goto LAB_080a4c36;
        psVar21 = param_1->s3;
        psVar21->send_alert[0] = '\x01';
        psVar21->alert_dispatch = 1;
        param_1->s3->send_alert[1] = (uchar)iVar11;
        psVar21 = param_1->s3;
        if ((psVar21->wbuf).left == 0) {
          (*param_1->method->ssl_dispatch_alert)(param_1);
          psVar21 = param_1->s3;
        }
        goto LAB_080a44f8;
      }
LAB_080a4594:
      if (psVar17->alert_fragment_len < 2) {
        if ((*(byte *)&param_1->shutdown & 1) != 0) {
          param_1->rwstate = 1;
          (psVar21->rrec).length = 0;
          goto LAB_080a46eb;
        }
        iVar11 = (psVar21->rrec).type;
        if (iVar11 != 0x14) {
          if ((3 < psVar17->handshake_fragment_len) && (param_1->in_handshake == 0)) {
            if (((param_1->state & 0xfffU) == 3) && ((*(byte *)&psVar17->flags & 1) == 0)) {
              param_1->tlsext_hb_seq = 1;
              param_1->new_session = 1;
              param_1->state = (-(uint)(param_1->server == 0) & 0xfffff000) + 0x2000;
            }
            uVar10 = (*param_1->handshake_func)(param_1);
            if ((int)uVar10 < 0) goto LAB_080a46eb;
            if (uVar10 == 0) {
              iVar27 = 0x568;
              goto LAB_080a4b68;
            }
            goto LAB_080a4df5;
          }
          if (iVar11 < 0x14) {
LAB_080a51a0:
            if (param_1->version - 0x301U < 2) {
              (psVar21->rrec).length = 0;
              psVar21 = psVar17;
              goto LAB_080a44f8;
            }
            iVar27 = 0x58c;
          }
          else {
            if (iVar11 < 0x17) {
              iVar27 = 0x597;
              iVar11 = 0x44;
              goto LAB_080a5253;
            }
            if (iVar11 != 0x17) goto LAB_080a51a0;
            if (((psVar17->in_read_app_data != 0) && (psVar17->total_renegotiations != 0)) &&
               (((uVar10 = param_1->state, uVar10 - 0x1110 < 0x11 && ((uVar10 & 0x1000) != 0)) ||
                (((uVar10 & 0x2000) != 0 && (uVar10 - 0x2110 < 0x11)))))) {
              psVar17->in_read_app_data = 2;
              local_d0 = 0xffffffff;
              uVar10 = local_d0;
              goto LAB_080a46eb;
            }
            iVar27 = 0x5af;
          }
          iVar11 = 0xf5;
          goto LAB_080a5253;
        }
        if ((((psVar21->rrec).length == 1) && ((psVar21->rrec).off == 0)) &&
           (puVar19 = (psVar21->rrec).data, *puVar19 == '\x01')) {
          if ((psVar17->tmp).new_cipher == (SSL_CIPHER *)0x0) {
            iVar27 = 0x539;
            iVar11 = 0x85;
          }
          else {
            if ((psVar17->flags & 0x80U) != 0) {
              psVar17->flags = psVar17->flags & 0xffffff7f;
              p_Var8 = param_1->msg_callback;
              (psVar21->rrec).length = 0;
              if (p_Var8 != (_func_3150 *)0x0) {
                (*p_Var8)(0,param_1->version,0x14,puVar19,1,param_1,param_1->msg_callback_arg);
                psVar17 = param_1->s3;
              }
              psVar17->change_cipher_spec = 1;
              iVar11 = ssl3_do_change_cipher_spec(param_1);
              if (iVar11 == 0) goto LAB_080a4e71;
              goto LAB_080a4c36;
            }
            iVar27 = 0x53f;
            iVar11 = 0x85;
          }
          goto LAB_080a5253;
        }
        iVar27 = 0x532;
        iVar11 = 0x67;
      }
      else {
        sVar4 = *(short *)psVar17->alert_fragment;
        uVar2 = psVar17->alert_fragment[0];
        uVar24 = (uint)psVar17->alert_fragment[1];
        psVar17->alert_fragment_len = 0;
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0x15,psVar17->alert_fragment,2,param_1,
                     param_1->msg_callback_arg);
        }
        p_Var23 = param_1->info_callback;
        if (((param_1->info_callback != (_func_3152 *)0x0) ||
            (p_Var23 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
            *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
           (p_Var23 = local_b4, local_b4 != (_func_3152 *)0x0)) {
          (*p_Var23)(param_1,0x4004,(uint)(sVar4 << 8) | (uint)(byte)((ushort)sVar4 >> 8));
          local_b4 = p_Var23;
        }
        if (uVar2 == '\x01') {
          psVar21 = param_1->s3;
          psVar21->warn_alert = uVar24;
          if (uVar24 == 0) {
            param_1->shutdown = param_1->shutdown | 2;
            goto LAB_080a46eb;
          }
          if (uVar24 != 100) goto LAB_080a44f8;
          ERR_put_error(0x14,0x94,0x153,"s3_pkt.c",0x508);
          uVar12 = 0x28;
          goto LAB_080a4660;
        }
        if (uVar2 == '\x02') {
          param_1->rwstate = 1;
          param_1->s3->fatal_alert = uVar24;
          ERR_put_error(0x14,0x94,uVar24 + 1000,"s3_pkt.c",0x514);
          BIO_snprintf((char *)local_60,0x10,"%d",uVar24);
          pSVar26 = (SSL_CTX *)0x2;
          ERR_add_error_data(2,"SSL alert number ",local_60);
          param_1->shutdown = param_1->shutdown | 2;
          SSL_CTX_remove_session(pSVar26,(SSL_SESSION *)param_1->psk_server_callback);
          goto LAB_080a46eb;
        }
        iVar27 = 0x51c;
        iVar11 = 0xf6;
      }
      ERR_put_error(0x14,0x94,iVar11,"s3_pkt.c",iVar27);
      uVar12 = 0x2f;
      goto LAB_080a4660;
    }
    uVar10 = SSL_state(param_1);
    if ((((uVar10 & 0x3000) == 0) || (param_2 != 0x17)) ||
       (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) {
      if ((int)param_4 < 1) {
        local_d0 = param_4;
        uVar10 = local_d0;
      }
      else {
        uVar10 = (psVar21->rrec).length;
        if (param_4 < uVar10) {
          uVar10 = param_4;
        }
        memcpy(param_3,(psVar21->rrec).data + (psVar21->rrec).off,uVar10);
        if (param_5 == 0) {
          puVar22 = &(psVar21->rrec).off;
          *puVar22 = *puVar22 + uVar10;
          uVar24 = (psVar21->rrec).length - uVar10;
          (psVar21->rrec).length = uVar24;
          if (uVar24 == 0) {
            bVar3 = *(byte *)&param_1->options;
            param_1->rstate = 0xf0;
            (psVar21->rrec).off = 0;
            if (((bVar3 & 0x10) != 0) && ((param_1->s3->rbuf).left == 0)) {
              ssl3_release_read_buffer(param_1);
            }
          }
        }
      }
      goto LAB_080a46eb;
    }
    iVar27 = 0x441;
    iVar11 = 100;
  }
  else {
    iVar27 = 0x42a;
    iVar11 = 0x91;
  }
LAB_080a5253:
  ERR_put_error(0x14,0x94,iVar11,"s3_pkt.c",iVar27);
  uVar12 = 10;
LAB_080a4660:
  iVar11 = (**(code **)(param_1->method->ssl3_enc + 0x30))(uVar12);
  if ((param_1->version == 0x300) && (iVar11 == 0x46)) {
    iVar11 = 0x28;
  }
  else if (iVar11 < 0) goto LAB_080a4e71;
  if (param_1->session != (SSL_SESSION *)0x0) {
    SSL_CTX_remove_session((SSL_CTX *)param_1->session,(SSL_SESSION *)param_1->psk_server_callback);
  }
  psVar21 = param_1->s3;
  psVar21->send_alert[0] = '\x02';
  psVar21->alert_dispatch = 1;
  param_1->s3->send_alert[1] = (uchar)iVar11;
  if ((param_1->s3->wbuf).left != 0) goto LAB_080a4e71;
  (*param_1->method->ssl_dispatch_alert)(param_1);
  local_d0 = 0xffffffff;
  uVar10 = local_d0;
  goto LAB_080a46eb;
code_r0x080a4e13:
  param_1->rwstate = 3;
  pBVar16 = SSL_get_rbio(param_1);
  BIO_clear_flags(pBVar16,0xf);
  BIO_set_flags(pBVar16,9);
  local_d0 = 0xffffffff;
  uVar10 = local_d0;
  goto LAB_080a46eb;
}

