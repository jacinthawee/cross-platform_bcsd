
void ssl3_read_bytes(SSL *param_1,int param_2,uchar *param_3,uint param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  EVP_MD *pEVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  BIO *pBVar9;
  uint uVar10;
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
  uchar *puVar24;
  _func_3150 *p_Var25;
  uint uVar26;
  uint local_d4;
  uchar *local_c4;
  _func_3152 *local_bc;
  undefined auStack_ac [64];
  uchar auStack_6c [64];
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar14 = ssl3_setup_read_buffer(), iVar14 == 0))
  {
LAB_0004f140:
    uVar12 = 0xffffffff;
    goto LAB_0004eb4e;
  }
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
    if (uVar12 != 0) goto LAB_0004f218;
    if (param_2 == 0x16) goto LAB_0004e91c;
  }
  else {
    if ((param_2 != 0x16) || (param_5 != 0)) {
LAB_0004f218:
      ERR_put_error(0x14,0x94,0x44,"s3_pkt.c",0x3eb);
      uVar12 = 0xffffffff;
      goto LAB_0004eb4e;
    }
LAB_0004e91c:
    psVar11 = param_1->s3;
    if (psVar11->handshake_fragment_len != 0) {
      puVar24 = psVar11->handshake_fragment;
      if ((int)param_4 < 1) {
        uVar12 = 0;
LAB_0004e96a:
        psVar11->handshake_fragment[0] = *puVar24;
        if (1 < param_1->s3->handshake_fragment_len) {
          param_1->s3->handshake_fragment[1] = puVar24[1];
          if (2 < param_1->s3->handshake_fragment_len) {
            param_1->s3->handshake_fragment[2] = puVar24[2];
            if (3 < param_1->s3->handshake_fragment_len) {
              param_1->s3->handshake_fragment[3] = puVar24[3];
            }
          }
        }
      }
      else {
        puVar23 = puVar24;
        do {
          puVar13 = puVar23 + 1;
          uVar12 = (int)puVar13 - (int)puVar24;
          *param_3 = *puVar23;
          psVar11 = param_1->s3;
          uVar10 = psVar11->handshake_fragment_len - 1;
          psVar11->handshake_fragment_len = uVar10;
          if (puVar13 == puVar24 + param_4) {
            puVar24 = puVar13;
            if (uVar10 != 0) goto LAB_0004e96a;
            break;
          }
          puVar23 = puVar13;
          param_3 = param_3 + 1;
        } while (uVar10 != 0);
      }
      goto LAB_0004eb4e;
    }
  }
  if ((param_1->in_handshake == 0) && (uVar12 = SSL_state(param_1), (uVar12 & 0x3000) != 0)) {
    uVar12 = (*param_1->handshake_func)(param_1);
    if (-1 < (int)uVar12) {
      if (uVar12 != 0) goto LAB_0004e9d0;
      iVar14 = 0x40e;
LAB_0004f5aa:
      ERR_put_error(0x14,0x94,0xe5,"s3_pkt.c",iVar14);
      uVar12 = 0xffffffff;
    }
LAB_0004eb4e:
    if (local_2c == __stack_chk_guard) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar12);
  }
LAB_0004e9d0:
  local_bc = (_func_3152 *)0x0;
  psVar11 = param_1->s3;
LAB_0004e9d8:
  uVar10 = (psVar11->rrec).length;
  param_1->rwstate = 1;
  if ((uVar10 != 0) && (psVar15 = psVar11, param_1->rstate != 0xf1)) goto LAB_0004e9f6;
  pSVar22 = param_1->session;
  uVar26 = param_1->references & 0x20;
  if (uVar26 == 0) {
    local_d4 = 0x4540;
  }
  else {
    if (psVar11->init_extra == 0) {
      ERR_put_error(0x14,0x8f,0x44,"s3_pkt.c",0x140);
      uVar12 = 0xffffffff;
      goto LAB_0004eb4e;
    }
    uVar26 = 0x4000;
    local_d4 = 0x8540;
  }
  iVar14 = 0x21;
  do {
    if ((param_1->rstate != 0xf1) || (uVar12 = param_1->packet_length, uVar12 < 5)) {
      uVar12 = ssl3_read_n(param_1,5,(param_1->s3->rbuf).len,0);
      if ((int)uVar12 < 1) goto LAB_0004eb4e;
      pbVar17 = param_1->packet;
      param_1->rstate = 0xf1;
      iVar4 = param_1->max_cert_list;
      (psVar11->rrec).type = (uint)*pbVar17;
      bVar2 = pbVar17[1];
      bVar1 = pbVar17[2];
      uVar10 = (uint)CONCAT11(pbVar17[3],pbVar17[4]);
      (psVar11->rrec).length = uVar10;
      uVar3 = CONCAT11(bVar2,bVar1);
      if ((iVar4 == 0) && ((int)(short)uVar3 != param_1->version)) {
        ERR_put_error(0x14,0x8f,0x10b,"s3_pkt.c",0x15c);
        if ((((param_1->version ^ (int)(short)uVar3) & 0xff00U) != 0) ||
           ((param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0 ||
            (param_1->write_hash != (EVP_MD_CTX *)0x0)))) goto LAB_0004eaee;
        if ((psVar11->rrec).type == 0x15) goto LAB_0004f140;
        param_1->version = (uint)uVar3;
        goto LAB_0004eaee;
      }
      if (bVar2 != 3) {
        ERR_put_error(0x14,0x8f,0x10b,"s3_pkt.c",0x174);
        uVar12 = 0xffffffff;
        goto LAB_0004eb4e;
      }
      if ((param_1->s3->rbuf).len - 5 < uVar10) {
        ERR_put_error(0x14,0x8f,0xc6,"s3_pkt.c",0x17a);
        goto LAB_0004eaee;
      }
      uVar12 = param_1->packet_length;
    }
    if (uVar12 - 5 < uVar10) {
      uVar12 = ssl3_read_n(param_1,uVar10,uVar10,1);
      if ((int)uVar12 < 1) goto LAB_0004eb4e;
      uVar10 = (psVar11->rrec).length;
    }
    puVar24 = param_1->packet;
    param_1->rstate = 0xf0;
    (psVar11->rrec).input = puVar24 + 5;
    if (local_d4 < uVar10) {
      ERR_put_error(0x14,0x8f,0x96,"s3_pkt.c",0x1a6);
      goto LAB_0004eaee;
    }
    pSVar19 = param_1->method;
    (psVar11->rrec).data = puVar24 + 5;
    iVar4 = (**(code **)pSVar19->ssl3_enc)(param_1,0);
    if (iVar4 == 0) {
      ERR_put_error(0x14,0x8f,0x81,"s3_pkt.c",0x1b6);
      goto LAB_0004eaee;
    }
    if (((pSVar22 != (SSL_SESSION *)0x0) && (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) &&
       (pEVar5 = EVP_MD_CTX_md(param_1->read_hash), pEVar5 != (EVP_MD *)0x0)) {
      pEVar5 = EVP_MD_CTX_md(param_1->read_hash);
      uVar12 = EVP_MD_size(pEVar5);
      if (0x40 < uVar12) {
        OpenSSLDie("s3_pkt.c",0x1ca,"mac_size <= EVP_MAX_MD_SIZE");
      }
      uVar10 = (psVar11->rrec).length + ((uint)(psVar11->rrec).type >> 8);
      if ((uVar10 < uVar12) ||
         ((uVar20 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx), (uVar20 & 0xf0007) == 2 &&
          (uVar10 < uVar12 + 1)))) {
        ERR_put_error(0x14,0x8f,0xa0,"s3_pkt.c",0x1dc);
      }
      else {
        uVar20 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx);
        if ((uVar20 & 0xf0007) == 2) {
          local_c4 = auStack_6c;
          ssl3_cbc_copy_mac(local_c4,&psVar11->rrec,uVar12,uVar10);
          uVar10 = 0;
          (psVar11->rrec).length = (psVar11->rrec).length - uVar12;
        }
        else {
          uVar10 = (psVar11->rrec).length - uVar12;
          (psVar11->rrec).length = uVar10;
          local_c4 = (psVar11->rrec).data + uVar10;
          if (local_c4 == (uchar *)0x0) {
            uVar10 = 1;
          }
          else {
            uVar10 = 0;
          }
        }
        uVar6 = (**(code **)(param_1->method->ssl3_enc + 4))(param_1,auStack_ac,0);
        if ((uVar10 | uVar6 >> 0x1f) == 0) {
          iVar8 = CRYPTO_memcmp(auStack_ac,local_c4,uVar12);
          if (iVar8 != 0) {
            iVar4 = -1;
          }
        }
        else {
          iVar4 = -1;
        }
        if ((psVar11->rrec).length <= uVar12 + uVar26 + 0x4400) goto LAB_0004ed2c;
LAB_0004ed0e:
        ERR_put_error(0x14,0x8f,0x119,"s3_pkt.c",0x206);
      }
      goto LAB_0004eaee;
    }
LAB_0004ed2c:
    if (iVar4 < 0) goto LAB_0004ed0e;
    if (param_1->expand != (COMP_CTX *)0x0) {
      if (uVar26 + 0x4400 < (psVar11->rrec).length) {
        ERR_put_error(0x14,0x8f,0x8c,"s3_pkt.c",0x20e);
        goto LAB_0004eaee;
      }
      psVar15 = param_1->s3;
      uVar12 = COMP_expand_block(param_1->expand,(psVar15->rrec).comp,0x4000,(psVar15->rrec).data,
                                 (psVar15->rrec).length);
      if ((int)uVar12 < 0) {
        ERR_put_error(0x14,0x8f,0x6b,"s3_pkt.c",0x213);
        goto LAB_0004eaee;
      }
      (psVar15->rrec).length = uVar12;
      (psVar15->rrec).data = (psVar15->rrec).comp;
    }
    uVar10 = (psVar11->rrec).length;
    if (uVar26 + 0x4000 < uVar10) {
      ERR_put_error(0x14,0x8f,0x92,"s3_pkt.c",0x21a);
      goto LAB_0004eaee;
    }
    (psVar11->rrec).off = 0;
    param_1->packet_length = 0;
    if (uVar10 != 0) break;
    iVar14 = iVar14 + -1;
    if (iVar14 == 0) {
      ERR_put_error(0x14,0x8f,0x12a,"s3_pkt.c",0x230);
      goto LAB_0004eaee;
    }
  } while( true );
  psVar15 = param_1->s3;
LAB_0004e9f6:
  if ((psVar15->change_cipher_spec != 0) && ((psVar11->rrec).type != 0x16)) {
    ERR_put_error(0x14,0x94,0x91,"s3_pkt.c",0x42a);
    goto LAB_0004eaee;
  }
  uVar12 = param_1->shutdown & 2;
  if (uVar12 != 0) {
    (psVar11->rrec).length = 0;
    param_1->rwstate = 1;
    uVar12 = 0;
    goto LAB_0004eb4e;
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
          uVar10 = (psVar11->rrec).length - uVar12;
          (psVar11->rrec).length = uVar10;
          (psVar11->rrec).off = (psVar11->rrec).off + uVar12;
          if (uVar10 == 0) {
            uVar20 = param_1->options;
            param_1->rstate = 0xf0;
            (psVar11->rrec).off = 0;
            if (((int)(uVar20 << 0x1b) < 0) && ((param_1->s3->rbuf).left == 0)) {
              ssl3_release_read_buffer(param_1);
            }
          }
        }
      }
      goto LAB_0004eb4e;
    }
    ERR_put_error(0x14,0x94,100,"s3_pkt.c",0x441);
    goto LAB_0004eaee;
  }
  if (iVar14 == 0x16) {
    puVar24 = psVar15->handshake_fragment;
    puVar7 = &psVar15->handshake_fragment_len;
    uVar26 = 4;
LAB_0004edc6:
    uVar18 = *puVar7;
    uVar6 = uVar26 - uVar18;
    if (uVar10 <= uVar26 - uVar18) {
      uVar6 = uVar10;
    }
    iVar14 = uVar6 - 1;
    if (uVar6 != 0) {
      do {
        puVar23 = (psVar11->rrec).data;
        *puVar7 = uVar18 + 1;
        iVar14 = iVar14 + -1;
        uVar10 = (psVar11->rrec).off;
        (psVar11->rrec).off = uVar10 + 1;
        puVar24[uVar18] = puVar23[uVar10];
        (psVar11->rrec).length = (psVar11->rrec).length - 1;
        uVar18 = *puVar7;
      } while (iVar14 != -1);
    }
    if (uVar18 < uVar26) goto LAB_0004ee06;
  }
  else {
    if (iVar14 == 0x15) {
      puVar24 = psVar15->alert_fragment;
      puVar7 = &psVar15->alert_fragment_len;
      uVar26 = 2;
      goto LAB_0004edc6;
    }
    if (iVar14 == 0x18) {
      tls1_process_heartbeat(param_1);
      (psVar11->rrec).length = 0;
      param_1->rwstate = 3;
      pBVar9 = SSL_get_rbio(param_1);
      BIO_clear_flags(pBVar9,0xf);
      pBVar9 = SSL_get_rbio(param_1);
      BIO_set_flags(pBVar9,9);
      uVar12 = 0xffffffff;
      goto LAB_0004eb4e;
    }
  }
  if (param_1->server == 0) {
    psVar15 = param_1->s3;
    if (((3 < psVar15->handshake_fragment_len) && (psVar15->handshake_fragment[0] == '\0')) &&
       ((param_1->session != (SSL_SESSION *)0x0 &&
        (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)))) {
      psVar15->handshake_fragment_len = 0;
      if ((*(uint *)psVar15->handshake_fragment & 0xffffff00) == 0) {
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0x16,psVar15->handshake_fragment,4,param_1,
                     param_1->msg_callback_arg);
        }
        iVar14 = SSL_state(param_1);
        if (iVar14 == 3) {
          psVar11 = param_1->s3;
          if ((psVar11->flags << 0x1f < 0) || (psVar11->renegotiate != 0)) goto LAB_0004e9d8;
          ssl3_renegotiate(param_1);
          iVar14 = ssl3_renegotiate_check(param_1);
          if (iVar14 != 0) {
            uVar12 = (*param_1->handshake_func)(param_1);
            if ((int)uVar12 < 0) goto LAB_0004eb4e;
            if (uVar12 == 0) {
              iVar14 = 0x4b4;
              goto LAB_0004f5aa;
            }
            if (-1 < (int)(param_1->options << 0x1d)) {
              psVar11 = param_1->s3;
              if ((psVar11->rbuf).left == 0) goto code_r0x0004eec4;
              goto LAB_0004e9d8;
            }
          }
        }
        goto LAB_0004ee06;
      }
      ERR_put_error(0x14,0x94,0x69,"s3_pkt.c",0x4a1);
      goto LAB_0004eaee;
    }
  }
  else {
    iVar14 = SSL_state(param_1);
    psVar15 = param_1->s3;
    if (((((iVar14 == 3) && (psVar15->send_connection_binding == 0)) && (0x300 < param_1->version))
        && ((3 < psVar15->handshake_fragment_len && (psVar15->handshake_fragment[0] == '\x01')))) &&
       ((param_1->session != (SSL_SESSION *)0x0 &&
        ((*(int *)(param_1->session->krb5_client_princ + 0x24) != 0 &&
         ((*(uint *)(param_1->psk_server_callback + 0xa4) & 0x40000) == 0)))))) {
      pSVar19 = param_1->method;
      (psVar11->rrec).length = 0;
      iVar14 = (**(code **)(pSVar19->ssl3_enc + 0x30))(100);
      if ((param_1->version == 0x300) && (iVar14 == 0x46)) {
        uVar21 = '(';
      }
      else {
        if (iVar14 < 0) goto LAB_0004ee06;
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
      goto LAB_0004e9d8;
    }
  }
  if (1 < psVar15->alert_fragment_len) {
    p_Var25 = param_1->msg_callback;
    uVar21 = psVar15->alert_fragment[0];
    psVar15->alert_fragment_len = 0;
    bVar2 = psVar15->alert_fragment[1];
    uVar10 = (uint)bVar2;
    if (p_Var25 != (_func_3150 *)0x0) {
      (*p_Var25)(0,param_1->version,0x15,psVar15->alert_fragment,2,param_1,param_1->msg_callback_arg
                );
    }
    p_Var16 = param_1->info_callback;
    if (((param_1->info_callback != (_func_3152 *)0x0) ||
        (p_Var16 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c),
        *(_func_3152 **)(param_1->psk_server_callback + 0x9c) != (_func_3152 *)0x0)) ||
       (p_Var16 = local_bc, local_bc != (_func_3152 *)0x0)) {
      (*p_Var16)(param_1,0x4004,(int)CONCAT11(uVar21,bVar2));
      local_bc = p_Var16;
    }
    if (uVar21 == '\x01') {
      psVar11 = param_1->s3;
      psVar11->warn_alert = uVar10;
      if (uVar10 == 0) {
        param_1->shutdown = param_1->shutdown | 2;
        goto LAB_0004eb4e;
      }
      if (uVar10 != 100) goto LAB_0004e9d8;
      ERR_put_error(0x14,0x94,0x153,"s3_pkt.c",0x508);
    }
    else {
      if (uVar21 == '\x02') {
        param_1->rwstate = 1;
        param_1->s3->fatal_alert = uVar10;
        ERR_put_error(0x14,0x94,uVar10 + 1000,"s3_pkt.c",0x514);
        BIO_snprintf((char *)auStack_6c,0x10,"%d",uVar10);
        ERR_add_error_data(2,"SSL alert number ",auStack_6c);
        param_1->shutdown = param_1->shutdown | 2;
        SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
        goto LAB_0004eb4e;
      }
      ERR_put_error(0x14,0x94,0xf6,"s3_pkt.c",0x51c);
    }
    goto LAB_0004eaee;
  }
  if (param_1->shutdown << 0x1f < 0) {
    param_1->rwstate = 1;
    (psVar11->rrec).length = 0;
    goto LAB_0004eb4e;
  }
  iVar14 = (psVar11->rrec).type;
  if (iVar14 == 0x14) {
    if ((((psVar11->rrec).length == 1) && ((psVar11->rrec).off == 0)) &&
       (puVar24 = (psVar11->rrec).data, *puVar24 == '\x01')) {
      if ((psVar15->tmp).new_cipher == (SSL_CIPHER *)0x0) {
        iVar14 = 0x539;
      }
      else {
        if (psVar15->flags << 0x18 < 0) {
          p_Var25 = param_1->msg_callback;
          psVar15->flags = psVar15->flags & 0xffffff7f;
          (psVar11->rrec).length = 0;
          if (p_Var25 != (_func_3150 *)0x0) {
            (*p_Var25)(0,param_1->version,0x14,puVar24,1,param_1,param_1->msg_callback_arg);
            psVar15 = param_1->s3;
          }
          psVar15->change_cipher_spec = 1;
          iVar14 = ssl3_do_change_cipher_spec(param_1);
          if (iVar14 == 0) goto LAB_0004f140;
          goto LAB_0004ee06;
        }
        iVar14 = 0x53f;
      }
      ERR_put_error(0x14,0x94,0x85,"s3_pkt.c",iVar14);
    }
    else {
      ERR_put_error(0x14,0x94,0x67,"s3_pkt.c",0x532);
    }
    goto LAB_0004eaee;
  }
  if ((3 < psVar15->handshake_fragment_len) && (param_1->in_handshake == 0)) {
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
    if ((int)uVar12 < 0) goto LAB_0004eb4e;
    if (uVar12 == 0) {
      iVar14 = 0x568;
      goto LAB_0004f5aa;
    }
    if (-1 < (int)(param_1->options << 0x1d)) {
      psVar11 = param_1->s3;
      if ((psVar11->rbuf).left == 0) {
        param_1->rwstate = 3;
        pBVar9 = SSL_get_rbio(param_1);
        BIO_clear_flags(pBVar9,0xf);
        BIO_set_flags(pBVar9,9);
        uVar12 = 0xffffffff;
        goto LAB_0004eb4e;
      }
      goto LAB_0004e9d8;
    }
LAB_0004ee06:
    psVar11 = param_1->s3;
    goto LAB_0004e9d8;
  }
  if (iVar14 < 0x14) {
LAB_0004f1fc:
    if (param_1->version - 0x301U < 2) {
      (psVar11->rrec).length = 0;
      psVar11 = psVar15;
      goto LAB_0004e9d8;
    }
    iVar14 = 0x58c;
  }
  else {
    if (iVar14 < 0x17) {
      ERR_put_error(0x14,0x94,0x44,"s3_pkt.c",0x597);
      goto LAB_0004eaee;
    }
    if (iVar14 != 0x17) goto LAB_0004f1fc;
    if (((psVar15->in_read_app_data != 0) && (psVar15->total_renegotiations != 0)) &&
       (((iVar14 = param_1->state, iVar14 << 0x13 < 0 && (iVar14 - 0x1110U < 0x11)) ||
        ((iVar14 << 0x12 < 0 && (iVar14 - 0x2110U < 0x11)))))) {
      psVar15->in_read_app_data = 2;
      uVar12 = 0xffffffff;
      goto LAB_0004eb4e;
    }
    iVar14 = 0x5af;
  }
  ERR_put_error(0x14,0x94,0xf5,"s3_pkt.c",iVar14);
LAB_0004eaee:
  iVar14 = (**(code **)(param_1->method->ssl3_enc + 0x30))();
  if ((param_1->version == 0x300) && (iVar14 == 0x46)) {
    uVar21 = '(';
  }
  else {
    if (iVar14 < 0) goto LAB_0004f140;
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
  if ((param_1->s3->wbuf).left != 0) goto LAB_0004f140;
  (*param_1->method->ssl_dispatch_alert)(param_1);
  uVar12 = 0xffffffff;
  goto LAB_0004eb4e;
code_r0x0004eec4:
  param_1->rwstate = 3;
  pBVar9 = SSL_get_rbio(param_1);
  BIO_clear_flags(pBVar9,0xf);
  BIO_set_flags(pBVar9,9);
  uVar12 = 0xffffffff;
  goto LAB_0004eb4e;
}

