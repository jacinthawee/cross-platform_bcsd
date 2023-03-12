
int dtls1_write_app_data_bytes(SSL *param_1,int param_2,uchar *param_3,size_t param_4)

{
  uint uVar1;
  EVP_MD *pEVar2;
  ulong uVar3;
  int iVar4;
  COMP_CTX *pCVar5;
  ssl3_state_st *psVar6;
  ssl3_state_st *psVar7;
  uchar *puVar8;
  uchar *buf;
  int local_30;
  int local_2c;
  
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    iVar4 = (*param_1->handshake_func)(param_1);
    if (iVar4 < 0) {
      return iVar4;
    }
    if (iVar4 == 0) {
      ERR_put_error(0x14,0x10c,0xe5,"d1_pkt.c",0x5c2);
      return -1;
    }
  }
  if (0x4000 < (int)param_4) {
    ERR_put_error(0x14,0x10c,0x14e,"d1_pkt.c",0x5c8);
    return -1;
  }
  param_1->rwstate = 1;
  if ((param_1->s3->wbuf).left == 0) {
    if ((param_1->s3->alert_dispatch != 0) &&
       (iVar4 = (*param_1->method->ssl_dispatch_alert)(param_1), iVar4 < 1)) {
      return iVar4;
    }
    if (param_4 == 0) {
      return 0;
    }
    psVar7 = param_1->s3;
    if (((param_1->session == (SSL_SESSION *)0x0) ||
        (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) ||
       (pEVar2 = EVP_MD_CTX_md(param_1->write_hash), pEVar2 == (EVP_MD *)0x0)) {
      local_2c = 0;
    }
    else {
      pEVar2 = EVP_MD_CTX_md(param_1->write_hash);
      local_2c = EVP_MD_size(pEVar2);
      if (local_2c < 0) {
        return -1;
      }
    }
    puVar8 = (psVar7->wbuf).buf;
    buf = puVar8 + 0xd;
    *puVar8 = (uchar)param_2;
    iVar4 = param_1->version;
    (psVar7->wrec).type = param_2;
    puVar8[1] = (uchar)((uint)iVar4 >> 8);
    puVar8[2] = (uchar)param_1->version;
    if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
       (uVar3 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), -1 < (int)(uVar3 << 0x1e))) {
      local_30 = 0;
    }
    else {
      local_30 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    }
    pCVar5 = param_1->compress;
    (psVar7->wrec).length = param_4;
    (psVar7->wrec).input = param_3;
    (psVar7->wrec).data = buf + local_30;
    if (pCVar5 == (COMP_CTX *)0x0) {
      memcpy(buf + local_30,param_3,param_4);
      (psVar7->wrec).input = (psVar7->wrec).data;
    }
    else {
      iVar4 = ssl3_do_compress(param_1);
      if (iVar4 == 0) {
        ERR_put_error(0x14,0xf5,0x8d,"d1_pkt.c",0x676);
        return -1;
      }
    }
    if (local_2c != 0) {
      iVar4 = (**(code **)(param_1->method->ssl3_enc + 4))
                        (param_1,buf + local_30 + (psVar7->wrec).length,1);
      if (iVar4 < 0) {
        return -1;
      }
      (psVar7->wrec).length = (psVar7->wrec).length + local_2c;
    }
    (psVar7->wrec).input = buf;
    (psVar7->wrec).data = buf;
    if (local_30 != 0) {
      iVar4 = RAND_bytes(buf,local_30);
      if (iVar4 < 1) {
        return -1;
      }
      (psVar7->wrec).length = (psVar7->wrec).length + local_30;
    }
    iVar4 = (**(code **)param_1->method->ssl3_enc)(param_1,1);
    if (iVar4 < 1) {
      return -1;
    }
    puVar8[3] = (uchar)(param_1->d1->w_epoch >> 8);
    puVar8[4] = (uchar)param_1->d1->w_epoch;
    psVar6 = param_1->s3;
    *(undefined4 *)(puVar8 + 5) = *(undefined4 *)(psVar6->write_sequence + 2);
    *(undefined2 *)(puVar8 + 9) = *(undefined2 *)(psVar6->write_sequence + 6);
    puVar8[0xb] = (uchar)((psVar7->wrec).length >> 8);
    puVar8[0xc] = (uchar)(psVar7->wrec).length;
    psVar6 = param_1->s3;
    (psVar7->wrec).type = param_2;
    (psVar7->wrec).length = (psVar7->wrec).length + 0xd;
    ssl3_record_sequence_update(psVar6->write_sequence);
    uVar1 = (psVar7->wrec).length;
    psVar6 = param_1->s3;
    (psVar7->wbuf).offset = 0;
    (psVar7->wbuf).left = uVar1;
    psVar6->wpend_tot = param_4;
    psVar6->wpend_buf = param_3;
    psVar6->wpend_type = param_2;
    psVar6->wpend_ret = param_4;
    iVar4 = ssl3_write_pending(param_1,param_2,param_3,param_4);
    return iVar4;
  }
  OpenSSLDie("d1_pkt.c",0x60f,"0");
  iVar4 = ssl3_write_pending(param_1,param_2,param_3,param_4);
  return iVar4;
}

