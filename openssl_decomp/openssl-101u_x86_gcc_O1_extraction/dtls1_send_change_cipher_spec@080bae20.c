
long dtls1_send_change_cipher_spec(SSL *param_1,int param_2,int param_3)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  BIO *pBVar4;
  long lVar5;
  EVP_MD *md;
  ulong uVar6;
  uint uVar7;
  dtls1_state_st *pdVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  int local_24;
  int local_20;
  
  if (param_1->state == param_2) {
    pcVar1 = param_1->init_buf->data;
    *pcVar1 = '\x01';
    pdVar8 = param_1->d1;
    iVar3 = param_1->version;
    uVar9 = pdVar8->next_handshake_write_seq;
    pdVar8->handshake_write_seq = uVar9;
    param_1->init_num = 1;
    if (iVar3 == 0x100) {
      pdVar8->next_handshake_write_seq = uVar9 + 1;
      pcVar1[1] = (char)(uVar9 >> 8);
      pcVar1[2] = (char)param_1->d1->handshake_write_seq;
      pdVar8 = param_1->d1;
      param_1->init_num = param_1->init_num + 2;
      uVar9 = pdVar8->handshake_write_seq;
    }
    param_1->init_off = 0;
    *(undefined *)&(pdVar8->w_msg_hdr).seq = 1;
    (pdVar8->w_msg_hdr).frag_off = 0;
    *(ushort *)&(pdVar8->w_msg_hdr).frag_len = uVar9;
    (pdVar8->w_msg_hdr).is_ccs = 0;
    (pdVar8->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    dtls1_buffer_message(param_1,1);
    param_1->state = param_3;
  }
  iVar3 = dtls1_query_mtu();
  if (iVar3 == 0) {
    return -1;
  }
  uVar11 = (param_1->d1->w_msg_hdr).msg_len;
  pBVar4 = SSL_get_wbio(param_1);
  lVar5 = BIO_ctrl(pBVar4,0x31,0,(void *)0x0);
  if (uVar11 < 0x100U - lVar5) {
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu(s)");
  }
  local_24 = 0;
  if (param_1->write_hash != (EVP_MD_CTX *)0x0) {
    md = EVP_MD_CTX_md(param_1->write_hash);
    local_24 = EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar6 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), (uVar6 & 2) == 0)) {
    local_20 = 0;
  }
  else {
    local_20 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    local_20 = local_20 * 2;
  }
  uVar11 = 0;
  iVar3 = param_1->init_num;
  param_1->rwstate = 1;
  bVar2 = true;
  while( true ) {
    while( true ) {
      if (iVar3 < 1) {
        return 0;
      }
      pBVar4 = SSL_get_wbio(param_1);
      lVar5 = BIO_ctrl(pBVar4,0xd,0,(void *)0x0);
      uVar7 = lVar5 + local_24 + 0xd + local_20;
      uVar10 = (param_1->d1->w_msg_hdr).msg_len;
      if ((uVar7 < uVar10) && (uVar10 = uVar10 - uVar7, 0xc < uVar10)) {
        if ((uint)param_1->init_num <= uVar10) {
          uVar10 = param_1->init_num;
        }
      }
      else {
        pBVar4 = SSL_get_wbio(param_1);
        lVar5 = BIO_ctrl(pBVar4,0xb,0,(void *)0x0);
        if (lVar5 < 1) {
          param_1->rwstate = 2;
          return lVar5;
        }
        uVar10 = (param_1->d1->w_msg_hdr).msg_len;
        if (uVar10 <= local_24 + local_20 + 0x19U) {
          return -1;
        }
        uVar10 = (uVar10 - 0xd) - (local_24 + local_20);
        if ((uint)param_1->init_num <= uVar10) {
          uVar10 = param_1->init_num;
        }
      }
      if ((int)uVar10 < 0) {
        uVar10 = 0x7fffffff;
      }
      uVar7 = dtls1_write_bytes(param_1,0x14,param_1->init_buf->data + param_1->init_off,uVar10);
      if ((int)uVar7 < 0) break;
      if (uVar10 != uVar7) {
        OpenSSLDie("d1_both.c",0x19f,"len == (unsigned int)ret");
      }
      if (uVar7 == param_1->init_num) {
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,0x14,param_1->init_buf->data,uVar7 + param_1->init_off,
                     param_1,param_1->msg_callback_arg);
        }
        param_1->init_off = 0;
        param_1->init_num = 0;
        return 1;
      }
      param_1->init_off = param_1->init_off + uVar7;
      iVar3 = param_1->init_num - uVar7;
      uVar11 = (uVar11 - 0xc) + uVar7;
      pdVar8 = param_1->d1;
      param_1->init_num = iVar3;
      (pdVar8->w_msg_hdr).is_ccs = uVar11;
      (pdVar8->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
    if (!bVar2) {
      return -1;
    }
    pBVar4 = SSL_get_wbio(param_1);
    lVar5 = BIO_ctrl(pBVar4,0x2b,0,(void *)0x0);
    if (lVar5 < 1) break;
    uVar10 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar10 & 0x1000) != 0) {
      return -1;
    }
    iVar3 = dtls1_query_mtu();
    if (iVar3 == 0) {
      return -1;
    }
    iVar3 = param_1->init_num;
    bVar2 = false;
  }
  return -1;
}

