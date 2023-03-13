
int dtls1_write_app_data_bytes(SSL *param_1,int param_2,uchar *param_3,size_t param_4)

{
  uchar *buf;
  uint *puVar1;
  ssl3_state_st *psVar2;
  uchar *puVar3;
  COMP_CTX *pCVar4;
  ssl3_state_st *psVar5;
  uint uVar6;
  EVP_MD *pEVar7;
  ulong uVar8;
  int iVar9;
  int line;
  int local_28;
  int local_24;
  
  uVar6 = SSL_state(param_1);
  if (((uVar6 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    iVar9 = (*param_1->handshake_func)(param_1);
    if (iVar9 < 0) {
      return iVar9;
    }
    if (iVar9 == 0) {
      line = 0x5c2;
      iVar9 = 0xe5;
      goto LAB_080b7c90;
    }
  }
  if ((int)param_4 < 0x4001) {
    param_1->rwstate = 1;
    if ((param_1->s3->wbuf).left != 0) {
      OpenSSLDie("d1_pkt.c",0x60f,"0");
      iVar9 = ssl3_write_pending();
      return iVar9;
    }
    if ((param_1->s3->alert_dispatch != 0) &&
       (iVar9 = (*param_1->method->ssl_dispatch_alert)(param_1), iVar9 < 1)) {
      return iVar9;
    }
    if (param_4 == 0) {
      return 0;
    }
    psVar2 = param_1->s3;
    if (((param_1->session == (SSL_SESSION *)0x0) ||
        (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) ||
       (pEVar7 = EVP_MD_CTX_md(param_1->write_hash), pEVar7 == (EVP_MD *)0x0)) {
      local_28 = 0;
    }
    else {
      pEVar7 = EVP_MD_CTX_md(param_1->write_hash);
      local_28 = EVP_MD_size(pEVar7);
      if (local_28 < 0) {
        return -1;
      }
    }
    puVar3 = (psVar2->wbuf).buf;
    *puVar3 = (uchar)param_2;
    iVar9 = param_1->version;
    buf = puVar3 + 0xd;
    (psVar2->wrec).type = param_2;
    puVar3[1] = (uchar)((uint)iVar9 >> 8);
    puVar3[2] = (uchar)param_1->version;
    if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
       (uVar8 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), (uVar8 & 2) == 0)) {
      local_24 = 0;
    }
    else {
      local_24 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    }
    (psVar2->wrec).length = param_4;
    (psVar2->wrec).input = param_3;
    pCVar4 = param_1->compress;
    (psVar2->wrec).data = buf + local_24;
    if (pCVar4 == (COMP_CTX *)0x0) {
      memcpy(buf + local_24,param_3,param_4);
      (psVar2->wrec).input = (psVar2->wrec).data;
    }
    else {
      iVar9 = ssl3_do_compress(param_1);
      if (iVar9 == 0) {
        ERR_put_error(0x14,0xf5,0x8d,"d1_pkt.c",0x676);
        return -1;
      }
    }
    if (local_28 != 0) {
      iVar9 = (**(code **)(param_1->method->ssl3_enc + 4))
                        (param_1,buf + local_24 + (psVar2->wrec).length,1);
      if (iVar9 < 0) {
        return -1;
      }
      puVar1 = &(psVar2->wrec).length;
      *puVar1 = *puVar1 + local_28;
    }
    (psVar2->wrec).input = buf;
    (psVar2->wrec).data = buf;
    if (local_24 != 0) {
      iVar9 = RAND_bytes(buf,local_24);
      if (iVar9 < 1) {
        return -1;
      }
      puVar1 = &(psVar2->wrec).length;
      *puVar1 = *puVar1 + local_24;
    }
    iVar9 = (**(code **)param_1->method->ssl3_enc)(param_1,1);
    if (iVar9 < 1) {
      return -1;
    }
    puVar3[3] = *(uchar *)((int)&param_1->d1->w_epoch + 1);
    puVar3[4] = (uchar)param_1->d1->w_epoch;
    psVar5 = param_1->s3;
    *(undefined4 *)(puVar3 + 5) = *(undefined4 *)(psVar5->write_sequence + 2);
    *(undefined2 *)(puVar3 + 9) = *(undefined2 *)(psVar5->write_sequence + 6);
    puVar3[0xb] = (uchar)((psVar2->wrec).length >> 8);
    puVar3[0xc] = (uchar)(psVar2->wrec).length;
    psVar5 = param_1->s3;
    puVar1 = &(psVar2->wrec).length;
    *puVar1 = *puVar1 + 0xd;
    (psVar2->wrec).type = param_2;
    ssl3_record_sequence_update(psVar5->write_sequence);
    uVar6 = (psVar2->wrec).length;
    (psVar2->wbuf).offset = 0;
    (psVar2->wbuf).left = uVar6;
    psVar2 = param_1->s3;
    psVar2->wpend_tot = param_4;
    psVar2->wpend_buf = param_3;
    psVar2->wpend_type = param_2;
    psVar2->wpend_ret = param_4;
    iVar9 = ssl3_write_pending();
    return iVar9;
  }
  line = 0x5c8;
  iVar9 = 0x14e;
LAB_080b7c90:
  ERR_put_error(0x14,0x10c,iVar9,"d1_pkt.c",line);
  return -1;
}

