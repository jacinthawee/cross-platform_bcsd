
uint ssl3_write_bytes(SSL *param_1,int param_2,int param_3,int param_4)

{
  uchar *puVar1;
  uint *puVar2;
  ssl3_state_st *psVar3;
  ssl3_state_st *psVar4;
  uchar uVar5;
  ssl3_state_st *psVar6;
  uint uVar7;
  EVP_MD *pEVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint __n;
  uchar *__src;
  ulong uVar12;
  uchar *puVar13;
  int iVar14;
  uint local_3c;
  uchar *local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  psVar6 = param_1->s3;
  param_1->rwstate = 1;
  if ((int)psVar6->wnum < 0) {
    OpenSSLDie("s3_pkt.c",0x274,"s->s3->wnum <= INT_MAX");
    psVar6 = param_1->s3;
  }
  local_3c = psVar6->wnum;
  psVar6->wnum = 0;
  uVar7 = SSL_state(param_1);
  if (((uVar7 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    uVar7 = (*param_1->handshake_func)(param_1);
    if ((int)uVar7 < 0) {
      return uVar7;
    }
    if (uVar7 == 0) {
      iVar14 = 0x27d;
      iVar10 = 0xe5;
      goto LAB_080a426a;
    }
  }
  if ((int)local_3c <= param_4) {
    uVar7 = param_4 - local_3c;
    while( true ) {
      psVar6 = param_1->s3;
      uVar9 = (psVar6->wbuf).left;
      __n = param_1->client_version;
      if (uVar7 <= (uint)param_1->client_version) {
        __n = uVar7;
      }
      __src = (uchar *)(local_3c + param_3);
      if (uVar9 == 0) break;
LAB_080a3fb1:
      uVar11 = ssl3_write_pending(param_1,param_2,__src,__n);
      if ((int)uVar11 < 1) goto LAB_080a4073;
      if ((uVar7 == uVar11) || ((param_2 == 0x17 && ((*(byte *)&param_1->options & 1) != 0)))) {
        param_1->s3->empty_fragment_done = 0;
        return uVar11 + local_3c;
      }
      uVar7 = uVar7 - uVar11;
      local_3c = local_3c + uVar11;
    }
    if ((psVar6->alert_dispatch != 0) &&
       (uVar11 = (*param_1->method->ssl_dispatch_alert)(param_1), (int)uVar11 < 1))
    goto LAB_080a4073;
    if (((psVar6->wbuf).buf != (uchar *)0x0) ||
       (iVar10 = ssl3_setup_write_buffer(param_1), iVar10 != 0)) {
      uVar11 = uVar9;
      if (__n == 0) goto LAB_080a4073;
      psVar3 = param_1->s3;
      if (param_1->session == (SSL_SESSION *)0x0) {
LAB_080a4090:
        if (param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
          local_30 = 0;
          goto LAB_080a3ded;
        }
LAB_080a409a:
        local_30 = 0;
LAB_080a3e19:
        puVar13 = (psVar6->wbuf).buf;
        local_28 = 0;
        uVar9 = -(int)(puVar13 + 5) & 7;
        puVar13 = puVar13 + uVar9;
        (psVar6->wbuf).offset = uVar9;
LAB_080a3e37:
        *puVar13 = (uchar)param_2;
        (psVar3->wrec).type = param_2;
        puVar13[1] = (uchar)((uint)param_1->version >> 8);
        if ((param_1->state == 0x1111) && (param_1->tlsext_hb_seq == 0)) {
          iVar10 = param_1->version;
          if ((iVar10 >> 8 != 3) || (iVar10 < 0x302)) goto LAB_080a3e61;
          uVar5 = '\x01';
        }
        else {
          iVar10 = param_1->version;
LAB_080a3e61:
          uVar5 = (uchar)iVar10;
        }
        local_34 = puVar13 + 3;
        puVar13[2] = uVar5;
        puVar1 = puVar13 + 5;
        if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) || (param_1->version < 0x302)) {
LAB_080a3e89:
          local_2c = 0;
        }
        else {
          uVar12 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx);
          if ((uVar12 & 0xf0007) == 2) {
            local_2c = EVP_CIPHER_CTX_iv_length(param_1->enc_write_ctx);
            if (local_2c < 2) goto LAB_080a3e89;
          }
          else {
            if ((uVar12 & 0xf0007) != 6) goto LAB_080a3e89;
            local_2c = 8;
          }
        }
        (psVar3->wrec).data = puVar1 + local_2c;
        (psVar3->wrec).length = __n;
        (psVar3->wrec).input = __src;
        if (param_1->compress == (COMP_CTX *)0x0) {
          memcpy(puVar1 + local_2c,__src,__n);
          (psVar3->wrec).input = (psVar3->wrec).data;
        }
        else {
          psVar4 = param_1->s3;
          uVar9 = COMP_compress_block(param_1->compress,(psVar4->wrec).data,0x4400,
                                      (psVar4->wrec).input,(psVar4->wrec).length);
          if ((int)uVar9 < 0) {
            iVar14 = 0x348;
            iVar10 = 0x8d;
            goto LAB_080a41aa;
          }
          (psVar4->wrec).length = uVar9;
          (psVar4->wrec).input = (psVar4->wrec).data;
        }
        if (local_30 != 0) {
          iVar10 = (**(code **)(param_1->method->ssl3_enc + 4))
                             (param_1,puVar1 + local_2c + (psVar3->wrec).length,1);
          if (iVar10 < 0) goto LAB_080a41b6;
          puVar2 = &(psVar3->wrec).length;
          *puVar2 = *puVar2 + local_30;
        }
        (psVar3->wrec).input = puVar1;
        (psVar3->wrec).data = puVar1;
        if (local_2c != 0) {
          puVar2 = &(psVar3->wrec).length;
          *puVar2 = *puVar2 + local_2c;
        }
        iVar10 = (**(code **)param_1->method->ssl3_enc)(param_1,1);
        if (0 < iVar10) {
          *local_34 = (uchar)((psVar3->wrec).length >> 8);
          puVar13[4] = (uchar)(psVar3->wrec).length;
          (psVar3->wrec).type = param_2;
          uVar9 = (psVar3->wrec).length + 5;
          (psVar3->wrec).length = uVar9;
          (psVar6->wbuf).left = uVar9 + local_28;
          psVar6 = param_1->s3;
          psVar6->wpend_buf = __src;
          psVar6->wpend_type = param_2;
          psVar6->wpend_tot = __n;
          psVar6->wpend_ret = __n;
          goto LAB_080a3fb1;
        }
      }
      else {
        if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) goto LAB_080a409a;
        pEVar8 = EVP_MD_CTX_md(param_1->write_hash);
        if (pEVar8 == (EVP_MD *)0x0) goto LAB_080a4090;
        pEVar8 = EVP_MD_CTX_md(param_1->write_hash);
        local_30 = EVP_MD_size(pEVar8);
        if (local_30 < 0) goto LAB_080a41b6;
LAB_080a3ded:
        psVar4 = param_1->s3;
        if (psVar4->empty_fragment_done != 0) goto LAB_080a3e19;
        if ((psVar4->need_empty_fragments == 0) || (param_2 != 0x17)) {
          psVar4->empty_fragment_done = 1;
          goto LAB_080a3e19;
        }
        local_28 = do_ssl3_write(0,1);
        if (local_28 < 1) goto LAB_080a41b6;
        if (local_28 < 0x56) {
          param_1->s3->empty_fragment_done = 1;
          puVar13 = (psVar6->wbuf).buf + (psVar6->wbuf).offset + local_28;
          goto LAB_080a3e37;
        }
        iVar14 = 0x2fa;
        iVar10 = 0x44;
LAB_080a41aa:
        ERR_put_error(0x14,0x68,iVar10,"s3_pkt.c",iVar14);
      }
    }
LAB_080a41b6:
    uVar11 = 0xffffffff;
LAB_080a4073:
    param_1->s3->wnum = local_3c;
    return uVar11;
  }
  iVar14 = 0x28c;
  iVar10 = 0x10f;
LAB_080a426a:
  ERR_put_error(0x14,0x9e,iVar10,"s3_pkt.c",iVar14);
  return 0xffffffff;
}

