
long dtls1_send_change_cipher_spec(SSL *param_1,int param_2,int param_3)

{
  int iVar1;
  BIO *pBVar2;
  long lVar3;
  EVP_MD_CTX *ctx;
  EVP_MD *md;
  ulong uVar4;
  dtls1_state_st *pdVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  int iVar13;
  
  if (param_1->state == param_2) {
    pcVar6 = param_1->init_buf->data;
    *pcVar6 = '\x01';
    pdVar5 = param_1->d1;
    iVar1 = param_1->version;
    uVar11 = pdVar5->next_handshake_write_seq;
    pdVar5->handshake_write_seq = uVar11;
    param_1->init_num = 1;
    if (iVar1 == 0x100) {
      pdVar5->next_handshake_write_seq = uVar11 + 1;
      pcVar6[1] = (char)(uVar11 >> 8);
      pcVar6[2] = (char)param_1->d1->handshake_write_seq;
      pdVar5 = param_1->d1;
      uVar11 = pdVar5->handshake_write_seq;
      param_1->init_num = param_1->init_num + 2;
    }
    param_1->init_off = 0;
    (pdVar5->w_msg_hdr).frag_off = 0;
    (pdVar5->w_msg_hdr).is_ccs = 0;
    (pdVar5->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    *(ushort *)&(pdVar5->w_msg_hdr).frag_len = uVar11;
    *(undefined *)&(pdVar5->w_msg_hdr).seq = 1;
    dtls1_buffer_message(param_1,1);
    param_1->state = param_3;
  }
  iVar1 = dtls1_query_mtu(param_1);
  if (iVar1 == 0) {
    return -1;
  }
  uVar10 = (param_1->d1->w_msg_hdr).msg_len;
  pBVar2 = SSL_get_wbio(param_1);
  lVar3 = BIO_ctrl(pBVar2,0x31,0,(void *)0x0);
  if (uVar10 < 0x100U - lVar3) {
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu(s)");
  }
  ctx = param_1->write_hash;
  if (ctx != (EVP_MD_CTX *)0x0) {
    md = EVP_MD_CTX_md(ctx);
    ctx = (EVP_MD_CTX *)EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar4 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), -1 < (int)(uVar4 << 0x1e))) {
    iVar1 = 0;
  }
  else {
    iVar1 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    iVar1 = iVar1 << 1;
  }
  iVar7 = param_1->init_num;
  iVar13 = (int)&ctx->digest + iVar1;
  uVar12 = 1;
  uVar10 = 0;
  param_1->rwstate = 1;
  while( true ) {
    while( true ) {
      if (iVar7 < 1) {
        return 0;
      }
      pBVar2 = SSL_get_wbio(param_1);
      lVar3 = BIO_ctrl(pBVar2,0xd,0,(void *)0x0);
      uVar8 = (param_1->d1->w_msg_hdr).msg_len;
      uVar9 = (int)&ctx->md_data + lVar3 + iVar1 + 1;
      if ((uVar8 <= uVar9) || (uVar8 = uVar8 - uVar9, uVar8 < 0xd)) {
        pBVar2 = SSL_get_wbio(param_1);
        lVar3 = BIO_ctrl(pBVar2,0xb,0,(void *)0x0);
        if (lVar3 < 1) {
          param_1->rwstate = 2;
          return lVar3;
        }
        uVar9 = (param_1->d1->w_msg_hdr).msg_len;
        if (uVar9 <= iVar13 + 0x19U) {
          return -1;
        }
        uVar8 = (uVar9 - 0xd) - iVar13;
      }
      uVar9 = param_1->init_num;
      if (uVar8 <= (uint)param_1->init_num) {
        uVar9 = uVar8;
      }
      if ((int)uVar9 < 0) {
        uVar9 = 0x7fffffff;
      }
      uVar8 = dtls1_write_bytes(param_1,0x14,param_1->init_buf->data + param_1->init_off);
      if ((int)uVar8 < 0) break;
      if (uVar9 != uVar8) {
        OpenSSLDie("d1_both.c",0x19f,"len == (unsigned int)ret");
      }
      if (uVar8 == param_1->init_num) {
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,0x14,param_1->init_buf->data,uVar8 + param_1->init_off,
                     param_1,param_1->msg_callback_arg);
        }
        param_1->init_off = 0;
        param_1->init_num = 0;
        return 1;
      }
      iVar7 = param_1->init_num - uVar8;
      pdVar5 = param_1->d1;
      param_1->init_num = iVar7;
      uVar10 = uVar10 + (uVar8 - 0xc);
      param_1->init_off = uVar8 + param_1->init_off;
      (pdVar5->w_msg_hdr).is_ccs = uVar10;
      (pdVar5->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
    if (uVar12 == 0) {
      return -1;
    }
    pBVar2 = SSL_get_wbio(param_1);
    lVar3 = BIO_ctrl(pBVar2,0x2b,0,(void *)0x0);
    if (lVar3 < 1) break;
    uVar12 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    uVar12 = uVar12 & 0x1000;
    if (uVar12 != 0) {
      return -1;
    }
    iVar7 = dtls1_query_mtu(param_1);
    if (iVar7 == 0) {
      return -1;
    }
    iVar7 = param_1->init_num;
  }
  return -1;
}

