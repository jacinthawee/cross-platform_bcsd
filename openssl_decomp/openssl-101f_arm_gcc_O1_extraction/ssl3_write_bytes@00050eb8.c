
uint ssl3_write_bytes(SSL *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  EVP_MD *pEVar2;
  COMP_CTX *ctx;
  uint uVar3;
  ulong uVar4;
  uchar uVar5;
  ssl3_state_st *psVar6;
  uchar *puVar7;
  int iVar8;
  uchar *__src;
  ssl3_state_st *psVar9;
  uint __n;
  uint uVar10;
  uchar *puVar11;
  ssl3_state_st *psVar12;
  uint uVar13;
  uchar *local_3c;
  int local_34;
  int local_30;
  int local_2c;
  
  param_1->rwstate = 1;
  uVar13 = param_1->s3->wnum;
  param_1->s3->wnum = 0;
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    uVar1 = (*param_1->handshake_func)(param_1);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if (uVar1 == 0) {
      ERR_put_error(0x14,0x9e,0xe5,"s3_pkt.c",0x254);
      return 0xffffffff;
    }
  }
  uVar1 = param_4 - uVar13;
  do {
    psVar12 = param_1->s3;
    __src = (uchar *)(param_3 + uVar13);
    __n = param_1->client_version;
    if (uVar1 <= (uint)param_1->client_version) {
      __n = uVar1;
    }
    if (((psVar12->wbuf).buf == (uchar *)0x0) &&
       (iVar8 = ssl3_setup_write_buffer(param_1), iVar8 == 0)) {
LAB_00051200:
      psVar9 = param_1->s3;
      uVar10 = 0xffffffff;
LAB_000510ec:
      psVar9->wnum = uVar13;
      return uVar10;
    }
    uVar10 = (psVar12->wbuf).left;
    if (uVar10 == 0) {
      psVar9 = param_1->s3;
      if (psVar9->alert_dispatch != 0) {
        uVar3 = (*param_1->method->ssl_dispatch_alert)(param_1);
        if ((int)uVar3 < 1) {
          psVar9 = param_1->s3;
          uVar10 = uVar3;
          goto LAB_000510ec;
        }
        psVar9 = param_1->s3;
      }
      if (__n == 0) goto LAB_000510ec;
      if (param_1->session == (SSL_SESSION *)0x0) {
LAB_00051116:
        if (param_1->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
          local_34 = 0;
          goto LAB_00050f62;
        }
LAB_0005111c:
        local_34 = 0;
LAB_00050f80:
        puVar7 = (psVar12->wbuf).buf;
        local_2c = 0;
        uVar10 = 3U - (int)puVar7 & 7;
        (psVar12->wbuf).offset = uVar10;
        puVar7 = puVar7 + uVar10;
      }
      else {
        if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) goto LAB_0005111c;
        pEVar2 = EVP_MD_CTX_md(param_1->write_hash);
        if (pEVar2 == (EVP_MD *)0x0) goto LAB_00051116;
        pEVar2 = EVP_MD_CTX_md(param_1->write_hash);
        local_34 = EVP_MD_size(pEVar2);
        if (local_34 < 0) goto LAB_00051200;
LAB_00050f62:
        psVar6 = param_1->s3;
        if (psVar6->empty_fragment_done != 0) goto LAB_00050f80;
        if ((psVar6->need_empty_fragments == 0) || (param_2 != 0x17)) {
          psVar6->empty_fragment_done = 1;
          goto LAB_00050f80;
        }
        local_2c = do_ssl3_write(param_1,0x17,__src,0,1);
        if (local_2c < 1) goto LAB_00051200;
        if (0x55 < local_2c) {
          ERR_put_error(0x14,0x68,0x44,"s3_pkt.c",0x2c2);
          psVar9 = param_1->s3;
          uVar10 = 0xffffffff;
          goto LAB_000510ec;
        }
        iVar8 = (psVar12->wbuf).offset;
        puVar7 = (psVar12->wbuf).buf;
        param_1->s3->empty_fragment_done = 1;
        puVar7 = puVar7 + iVar8 + local_2c;
      }
      *puVar7 = (uchar)param_2;
      iVar8 = param_1->version;
      (psVar9->wrec).type = param_2;
      puVar7[1] = (uchar)((uint)iVar8 >> 8);
      if ((param_1->state == 0x1111) && (param_1->tlsext_hb_seq == 0)) {
        iVar8 = param_1->version;
        if ((iVar8 >> 8 != 3) || (iVar8 < 0x302)) goto LAB_00050fb8;
        uVar5 = '\x01';
      }
      else {
        iVar8 = param_1->version;
LAB_00050fb8:
        uVar5 = (uchar)iVar8;
      }
      local_3c = puVar7 + 3;
      puVar7[2] = uVar5;
      puVar11 = puVar7 + 5;
      if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) || (param_1->version < 0x302)) {
LAB_00050fd8:
        local_30 = 0;
      }
      else {
        uVar4 = EVP_CIPHER_CTX_flags(param_1->enc_write_ctx);
        if ((uVar4 & 0xf0007) == 2) {
          local_30 = EVP_CIPHER_CTX_iv_length(param_1->enc_write_ctx);
          if (local_30 < 2) goto LAB_00050fd8;
        }
        else {
          if ((uVar4 & 0xf0007) != 6) goto LAB_00050fd8;
          local_30 = 8;
        }
      }
      ctx = param_1->compress;
      (psVar9->wrec).length = __n;
      (psVar9->wrec).input = __src;
      (psVar9->wrec).data = puVar11 + local_30;
      if (ctx == (COMP_CTX *)0x0) {
        memcpy(puVar11 + local_30,__src,__n);
        (psVar9->wrec).input = (psVar9->wrec).data;
      }
      else {
        psVar6 = param_1->s3;
        uVar10 = COMP_compress_block(ctx,(psVar6->wrec).data,0x4400,(psVar6->wrec).input,
                                     (psVar6->wrec).length);
        if ((int)uVar10 < 0) {
          ERR_put_error(0x14,0x68,0x8d,"s3_pkt.c",0x318);
          psVar9 = param_1->s3;
          uVar10 = 0xffffffff;
          goto LAB_000510ec;
        }
        (psVar6->wrec).length = uVar10;
        (psVar6->wrec).input = (psVar6->wrec).data;
      }
      if (local_34 != 0) {
        iVar8 = (**(code **)(param_1->method->ssl3_enc + 4))
                          (param_1,puVar11 + local_30 + (psVar9->wrec).length,1);
        if (iVar8 < 0) goto LAB_00051200;
        (psVar9->wrec).length = (psVar9->wrec).length + local_34;
      }
      (psVar9->wrec).input = puVar11;
      (psVar9->wrec).data = puVar11;
      if (local_30 != 0) {
        (psVar9->wrec).length = (psVar9->wrec).length + local_30;
      }
      (**(code **)param_1->method->ssl3_enc)(param_1,1);
      *local_3c = (uchar)((psVar9->wrec).length >> 8);
      puVar7[4] = (uchar)(psVar9->wrec).length;
      psVar6 = param_1->s3;
      uVar10 = (psVar9->wrec).length + 5;
      (psVar9->wrec).type = param_2;
      (psVar9->wrec).length = uVar10;
      (psVar12->wbuf).left = uVar10 + local_2c;
      psVar6->wpend_tot = __n;
      psVar6->wpend_buf = __src;
      psVar6->wpend_type = param_2;
      psVar6->wpend_ret = __n;
      uVar10 = ssl3_write_pending(param_1,param_2,__src,__n);
    }
    else {
      uVar10 = ssl3_write_pending(param_1,param_2,__src,__n);
    }
    if ((int)uVar10 < 1) {
      psVar9 = param_1->s3;
      goto LAB_000510ec;
    }
    if ((uVar1 == uVar10) || ((param_2 == 0x17 && ((int)(param_1->options << 0x1f) < 0)))) {
      param_1->s3->empty_fragment_done = 0;
      return uVar10 + uVar13;
    }
    uVar1 = uVar1 - uVar10;
    uVar13 = uVar13 + uVar10;
  } while( true );
}

