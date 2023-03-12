
uint ssl3_write_bytes(SSL *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  EVP_MD *pEVar2;
  COMP_CTX *ctx;
  uint uVar3;
  ulong uVar4;
  ssl3_state_st *psVar5;
  uchar uVar6;
  ssl3_state_st *psVar7;
  uchar *puVar8;
  int iVar9;
  uchar *__src;
  uint uVar10;
  ssl3_state_st *psVar11;
  uint __n;
  uchar *puVar12;
  uint uVar13;
  uchar *local_3c;
  int local_34;
  int local_30;
  int local_2c;
  
  psVar5 = param_1->s3;
  param_1->rwstate = 1;
  if ((int)psVar5->wnum < 0) {
    OpenSSLDie("s3_pkt.c",0x274,"s->s3->wnum <= INT_MAX");
    psVar5 = param_1->s3;
  }
  uVar13 = psVar5->wnum;
  psVar5->wnum = 0;
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    uVar1 = (*param_1->handshake_func)(param_1);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (uVar1 == 0) {
      ERR_put_error(0x14,0x9e,0xe5,"s3_pkt.c",0x27d);
      return 0xffffffff;
    }
  }
  if (param_4 < (int)uVar13) {
    ERR_put_error(0x14,0x9e,0x10f,"s3_pkt.c",0x28c);
    return 0xffffffff;
  }
  uVar1 = param_4 - uVar13;
  while( true ) {
    psVar5 = param_1->s3;
    __src = (uchar *)(param_3 + uVar13);
    uVar10 = (psVar5->wbuf).left;
    __n = param_1->client_version;
    if (uVar1 <= (uint)param_1->client_version) {
      __n = uVar1;
    }
    if (uVar10 == 0) break;
    uVar3 = ssl3_write_pending(param_1,param_2,__src,__n);
LAB_0004e5f8:
    if ((int)uVar3 < 1) goto LAB_0004e64e;
    if ((uVar1 == uVar3) || ((param_2 == 0x17 && ((int)(param_1->options << 0x1f) < 0)))) {
      param_1->s3->empty_fragment_done = 0;
      return uVar3 + uVar13;
    }
    uVar1 = uVar1 - uVar3;
    uVar13 = uVar13 + uVar3;
  }
  if ((psVar5->alert_dispatch != 0) &&
     (uVar3 = (*param_1->method->ssl_dispatch_alert)(param_1), (int)uVar3 < 1)) goto LAB_0004e64e;
  if (((psVar5->wbuf).buf != (uchar *)0x0) || (iVar9 = ssl3_setup_write_buffer(param_1), iVar9 != 0)
     ) {
    uVar3 = uVar10;
    if (__n == 0) goto LAB_0004e64e;
    psVar11 = param_1->s3;
    if (param_1->session == (SSL_SESSION *)0x0) {
LAB_0004e65e:
      if (param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
        local_34 = 0;
        goto LAB_0004e4a6;
      }
LAB_0004e664:
      local_34 = 0;
LAB_0004e4c4:
      puVar8 = (psVar5->wbuf).buf;
      local_2c = 0;
      uVar10 = 3U - (int)puVar8 & 7;
      (psVar5->wbuf).offset = uVar10;
      puVar8 = puVar8 + uVar10;
    }
    else {
      if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) goto LAB_0004e664;
      pEVar2 = EVP_MD_CTX_md(param_1->write_hash);
      if (pEVar2 == (EVP_MD *)0x0) goto LAB_0004e65e;
      pEVar2 = EVP_MD_CTX_md(param_1->write_hash);
      local_34 = EVP_MD_size(pEVar2);
      if (local_34 < 0) goto LAB_0004e61a;
LAB_0004e4a6:
      psVar7 = param_1->s3;
      if (psVar7->empty_fragment_done != 0) goto LAB_0004e4c4;
      if ((psVar7->need_empty_fragments == 0) || (param_2 != 0x17)) {
        psVar7->empty_fragment_done = 1;
        goto LAB_0004e4c4;
      }
      local_2c = do_ssl3_write(param_1,0x17,__src,0,1);
      if (local_2c < 1) goto LAB_0004e61a;
      if (0x55 < local_2c) {
        uVar3 = 0xffffffff;
        ERR_put_error(0x14,0x68,0x44,"s3_pkt.c",0x2fa);
        goto LAB_0004e64e;
      }
      puVar8 = (psVar5->wbuf).buf + (psVar5->wbuf).offset + local_2c;
      param_1->s3->empty_fragment_done = 1;
    }
    *puVar8 = (uchar)param_2;
    iVar9 = param_1->version;
    (psVar11->wrec).type = param_2;
    puVar8[1] = (uchar)((uint)iVar9 >> 8);
    if ((param_1->state == 0x1111) && (param_1->tlsext_hb_seq == 0)) {
      iVar9 = param_1->version;
      if ((iVar9 >> 8 != 3) || (iVar9 < 0x302)) goto LAB_0004e4fc;
      uVar6 = '\x01';
    }
    else {
      iVar9 = param_1->version;
LAB_0004e4fc:
      uVar6 = (uchar)iVar9;
    }
    local_3c = puVar8 + 3;
    puVar8[2] = uVar6;
    puVar12 = puVar8 + 5;
    if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) || (param_1->version < 0x302)) {
LAB_0004e51c:
      local_30 = 0;
    }
    else {
      uVar4 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx);
      if ((uVar4 & 0xf0007) == 2) {
        local_30 = EVP_CIPHER_CTX_iv_length(param_1->enc_write_ctx);
        if (local_30 < 2) goto LAB_0004e51c;
      }
      else {
        if ((uVar4 & 0xf0007) != 6) goto LAB_0004e51c;
        local_30 = 8;
      }
    }
    ctx = param_1->compress;
    (psVar11->wrec).length = __n;
    (psVar11->wrec).input = __src;
    (psVar11->wrec).data = puVar12 + local_30;
    if (ctx == (COMP_CTX *)0x0) {
      memcpy(puVar12 + local_30,__src,__n);
      (psVar11->wrec).input = (psVar11->wrec).data;
    }
    else {
      psVar7 = param_1->s3;
      uVar10 = COMP_compress_block(ctx,(psVar7->wrec).data,0x4400,(psVar7->wrec).input,
                                   (psVar7->wrec).length);
      if ((int)uVar10 < 0) {
        uVar3 = 0xffffffff;
        ERR_put_error(0x14,0x68,0x8d,"s3_pkt.c",0x348);
        goto LAB_0004e64e;
      }
      (psVar7->wrec).length = uVar10;
      (psVar7->wrec).input = (psVar7->wrec).data;
    }
    if (local_34 != 0) {
      iVar9 = (**(code **)(param_1->method->ssl3_enc + 4))
                        (param_1,puVar12 + local_30 + (psVar11->wrec).length,1);
      if (iVar9 < 0) goto LAB_0004e61a;
      (psVar11->wrec).length = (psVar11->wrec).length + local_34;
    }
    (psVar11->wrec).input = puVar12;
    (psVar11->wrec).data = puVar12;
    if (local_30 != 0) {
      (psVar11->wrec).length = (psVar11->wrec).length + local_30;
    }
    iVar9 = (**(code **)param_1->method->ssl3_enc)(param_1,1);
    if (0 < iVar9) {
      *local_3c = (uchar)((psVar11->wrec).length >> 8);
      puVar8[4] = (uchar)(psVar11->wrec).length;
      psVar7 = param_1->s3;
      uVar10 = (psVar11->wrec).length + 5;
      (psVar11->wrec).type = param_2;
      (psVar11->wrec).length = uVar10;
      (psVar5->wbuf).left = uVar10 + local_2c;
      psVar7->wpend_tot = __n;
      psVar7->wpend_buf = __src;
      psVar7->wpend_type = param_2;
      psVar7->wpend_ret = __n;
      uVar3 = ssl3_write_pending(param_1,param_2,__src,__n);
      goto LAB_0004e5f8;
    }
  }
LAB_0004e61a:
  uVar3 = 0xffffffff;
LAB_0004e64e:
  param_1->s3->wnum = uVar13;
  return uVar3;
}

