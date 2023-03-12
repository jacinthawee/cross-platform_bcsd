
uint ssl3_write_bytes(SSL *param_1,int param_2,int param_3,int param_4)

{
  uchar *puVar1;
  uint *puVar2;
  ssl3_state_st *psVar3;
  ssl3_state_st *psVar4;
  uchar uVar5;
  uint uVar6;
  uchar *__src;
  EVP_MD *pEVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  ulong uVar11;
  uchar *puVar12;
  ssl3_state_st *psVar13;
  int line;
  uint local_44;
  uint local_38;
  uchar *local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  param_1->rwstate = 1;
  local_38 = param_1->s3->wnum;
  param_1->s3->wnum = 0;
  uVar6 = SSL_state(param_1);
  if (((uVar6 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    uVar6 = (*param_1->handshake_func)(param_1);
    if (-1 < (int)uVar6) {
      if (uVar6 != 0) goto LAB_080a7512;
      uVar6 = 0xffffffff;
      ERR_put_error(0x14,0x9e,0xe5,"s3_pkt.c",0x254);
    }
    return uVar6;
  }
LAB_080a7512:
  local_44 = param_4 - local_38;
  do {
    psVar3 = param_1->s3;
    uVar6 = param_1->client_version;
    if (local_44 <= (uint)param_1->client_version) {
      uVar6 = local_44;
    }
    __src = (uchar *)(local_38 + param_3);
    if (((psVar3->wbuf).buf == (uchar *)0x0) &&
       (iVar10 = ssl3_setup_write_buffer(param_1), iVar10 == 0)) {
LAB_080a79ac:
      psVar13 = param_1->s3;
      uVar9 = 0xffffffff;
LAB_080a7842:
      psVar13->wnum = local_38;
      return uVar9;
    }
    uVar8 = (psVar3->wbuf).left;
    if (uVar8 == 0) {
      psVar13 = param_1->s3;
      if (psVar13->alert_dispatch != 0) {
        uVar9 = (*param_1->method->ssl_dispatch_alert)(param_1);
        psVar13 = param_1->s3;
        if ((int)uVar9 < 1) goto LAB_080a7842;
      }
      uVar9 = uVar8;
      if (uVar6 == 0) goto LAB_080a7842;
      if (param_1->session == (SSL_SESSION *)0x0) {
LAB_080a7860:
        if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) goto LAB_080a786a;
        local_30 = 0;
LAB_080a75d1:
        psVar4 = param_1->s3;
        if (psVar4->empty_fragment_done != 0) goto LAB_080a75fd;
        if ((psVar4->need_empty_fragments == 0) || (param_2 != 0x17)) {
          psVar4->empty_fragment_done = 1;
          goto LAB_080a75fd;
        }
        local_28 = do_ssl3_write(0,1);
        if (local_28 < 1) goto LAB_080a79ac;
        if (local_28 < 0x56) {
          param_1->s3->empty_fragment_done = 1;
          puVar12 = (psVar3->wbuf).buf + (psVar3->wbuf).offset + local_28;
          goto LAB_080a761b;
        }
        line = 0x2c2;
        iVar10 = 0x44;
LAB_080a794a:
        uVar9 = 0xffffffff;
        ERR_put_error(0x14,0x68,iVar10,"s3_pkt.c",line);
        psVar13 = param_1->s3;
        goto LAB_080a7842;
      }
      if (param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
        pEVar7 = EVP_MD_CTX_md(param_1->write_hash);
        if (pEVar7 == (EVP_MD *)0x0) goto LAB_080a7860;
        pEVar7 = EVP_MD_CTX_md(param_1->write_hash);
        local_30 = EVP_MD_size(pEVar7);
        if (local_30 < 0) goto LAB_080a79ac;
        goto LAB_080a75d1;
      }
LAB_080a786a:
      local_30 = 0;
LAB_080a75fd:
      puVar12 = (psVar3->wbuf).buf;
      local_28 = 0;
      uVar8 = -(int)(puVar12 + 5) & 7;
      puVar12 = puVar12 + uVar8;
      (psVar3->wbuf).offset = uVar8;
LAB_080a761b:
      *puVar12 = (uchar)param_2;
      (psVar13->wrec).type = param_2;
      puVar12[1] = (uchar)((uint)param_1->version >> 8);
      if ((param_1->state == 0x1111) && (param_1->tlsext_hb_seq == 0)) {
        iVar10 = param_1->version;
        if ((iVar10 >> 8 != 3) || (iVar10 < 0x302)) goto LAB_080a7643;
        uVar5 = '\x01';
      }
      else {
        iVar10 = param_1->version;
LAB_080a7643:
        uVar5 = (uchar)iVar10;
      }
      local_34 = puVar12 + 3;
      puVar12[2] = uVar5;
      puVar1 = puVar12 + 5;
      if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) || (param_1->version < 0x302)) {
LAB_080a766a:
        local_2c = 0;
      }
      else {
        uVar11 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx);
        if ((uVar11 & 0xf0007) == 2) {
          local_2c = EVP_CIPHER_CTX_iv_length(param_1->enc_write_ctx);
          if (local_2c < 2) goto LAB_080a766a;
        }
        else {
          if ((uVar11 & 0xf0007) != 6) goto LAB_080a766a;
          local_2c = 8;
        }
      }
      (psVar13->wrec).data = puVar1 + local_2c;
      (psVar13->wrec).length = uVar6;
      (psVar13->wrec).input = __src;
      if (param_1->compress == (COMP_CTX *)0x0) {
        memcpy(puVar1 + local_2c,__src,uVar6);
        (psVar13->wrec).input = (psVar13->wrec).data;
      }
      else {
        psVar4 = param_1->s3;
        uVar8 = COMP_compress_block(param_1->compress,(psVar4->wrec).data,0x4400,
                                    (psVar4->wrec).input,(psVar4->wrec).length);
        if ((int)uVar8 < 0) {
          line = 0x318;
          iVar10 = 0x8d;
          goto LAB_080a794a;
        }
        (psVar4->wrec).length = uVar8;
        (psVar4->wrec).input = (psVar4->wrec).data;
      }
      if (local_30 != 0) {
        iVar10 = (**(code **)(param_1->method->ssl3_enc + 4))
                           (param_1,puVar1 + local_2c + (psVar13->wrec).length,1);
        if (iVar10 < 0) goto LAB_080a79ac;
        puVar2 = &(psVar13->wrec).length;
        *puVar2 = *puVar2 + local_30;
      }
      (psVar13->wrec).input = puVar1;
      (psVar13->wrec).data = puVar1;
      if (local_2c != 0) {
        puVar2 = &(psVar13->wrec).length;
        *puVar2 = *puVar2 + local_2c;
      }
      (**(code **)param_1->method->ssl3_enc)(param_1,1);
      *local_34 = (uchar)((psVar13->wrec).length >> 8);
      puVar12[4] = (uchar)(psVar13->wrec).length;
      (psVar13->wrec).type = param_2;
      uVar8 = (psVar13->wrec).length + 5;
      (psVar13->wrec).length = uVar8;
      (psVar3->wbuf).left = uVar8 + local_28;
      psVar3 = param_1->s3;
      psVar3->wpend_buf = __src;
      psVar3->wpend_type = param_2;
      psVar3->wpend_tot = uVar6;
      psVar3->wpend_ret = uVar6;
      uVar9 = ssl3_write_pending(param_1,param_2,__src,uVar6);
    }
    else {
      uVar9 = ssl3_write_pending(param_1,param_2,__src,uVar6);
    }
    if ((int)uVar9 < 1) {
      psVar13 = param_1->s3;
      goto LAB_080a7842;
    }
    if ((local_44 == uVar9) || ((param_2 == 0x17 && ((*(byte *)&param_1->options & 1) != 0)))) {
      param_1->s3->empty_fragment_done = 0;
      return uVar9 + local_38;
    }
    local_44 = local_44 - uVar9;
    local_38 = local_38 + uVar9;
  } while( true );
}

