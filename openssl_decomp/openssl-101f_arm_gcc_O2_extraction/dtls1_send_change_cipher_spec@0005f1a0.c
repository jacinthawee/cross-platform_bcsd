
long dtls1_send_change_cipher_spec(SSL *param_1,int param_2,int param_3)

{
  EVP_MD_CTX *ctx;
  EVP_MD *md;
  ulong uVar1;
  BIO *pBVar2;
  long lVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  dtls1_state_st *pdVar9;
  ushort uVar10;
  dtls1_state_st *pdVar11;
  int iVar12;
  
  if (param_1->state == param_2) {
    pcVar5 = param_1->init_buf->data;
    *pcVar5 = '\x01';
    pdVar9 = param_1->d1;
    iVar12 = param_1->version;
    uVar10 = pdVar9->next_handshake_write_seq;
    pdVar9->handshake_write_seq = uVar10;
    param_1->init_num = 1;
    if (iVar12 == 0x100) {
      pdVar9->next_handshake_write_seq = uVar10 + 1;
      pcVar5[1] = (char)(uVar10 >> 8);
      pcVar5[2] = (char)param_1->d1->handshake_write_seq;
      pdVar9 = param_1->d1;
      uVar10 = pdVar9->handshake_write_seq;
      param_1->init_num = param_1->init_num + 2;
    }
    param_1->init_off = 0;
    *(undefined4 *)&(pdVar9->w_msg_hdr).seq = 0;
    (pdVar9->w_msg_hdr).frag_len = 0;
    (pdVar9->w_msg_hdr).is_ccs = 0;
    *(ushort *)&(pdVar9->w_msg_hdr).frag_off = uVar10;
    *(undefined *)&(pdVar9->w_msg_hdr).msg_len = 1;
    dtls1_buffer_message(param_1,1);
    param_1->state = param_3;
    uVar6 = *(uint *)&param_1->d1->w_msg_hdr;
  }
  else {
    uVar6 = *(uint *)&param_1->d1->w_msg_hdr;
  }
  if (uVar6 < 0xe4) {
    uVar6 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar6 & 0x1000) == 0) {
      pdVar11 = param_1->d1;
      pBVar2 = SSL_get_wbio(param_1);
      lVar3 = BIO_ctrl(pBVar2,0x28,0,(void *)0x0);
      pdVar9 = param_1->d1;
      *(long *)&pdVar11->w_msg_hdr = lVar3;
      if (0xe3 < *(uint *)&pdVar9->w_msg_hdr) goto LAB_0005f1bc;
      *(undefined4 *)&pdVar9->w_msg_hdr = 0x5c0;
      pBVar2 = SSL_get_wbio(param_1);
      BIO_ctrl(pBVar2,0x2a,*(long *)&param_1->d1->w_msg_hdr,(void *)0x0);
    }
    if (*(uint *)&param_1->d1->w_msg_hdr < 0xe4) {
      OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu()");
    }
  }
LAB_0005f1bc:
  ctx = param_1->write_hash;
  if (ctx != (EVP_MD_CTX *)0x0) {
    md = EVP_MD_CTX_md(ctx);
    ctx = (EVP_MD_CTX *)EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar1 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), -1 < (int)(uVar1 << 0x1e))) {
    iVar12 = 0;
  }
  else {
    iVar12 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    iVar12 = iVar12 << 1;
  }
  iVar7 = param_1->init_num;
  while( true ) {
    while( true ) {
      if (iVar7 == 0) {
        return 0;
      }
      iVar7 = *(int *)&param_1->d1->w_msg_hdr;
      pBVar2 = SSL_get_wbio(param_1);
      lVar3 = BIO_ctrl(pBVar2,0xd,0,(void *)0x0);
      iVar7 = ((-0xd - (int)ctx) - iVar12) + (iVar7 - lVar3);
      if (iVar7 < 0xd) {
        pBVar2 = SSL_get_wbio(param_1);
        lVar3 = BIO_ctrl(pBVar2,0xb,0,(void *)0x0);
        if (lVar3 < 1) {
          return lVar3;
        }
        iVar7 = ((*(int *)&param_1->d1->w_msg_hdr + -0xd) - (int)ctx) - iVar12;
      }
      iVar8 = param_1->init_num;
      if (iVar7 <= param_1->init_num) {
        iVar8 = iVar7;
      }
      iVar4 = dtls1_write_bytes(param_1,0x14,param_1->init_buf->data + param_1->init_off,iVar8);
      if (-1 < iVar4) break;
      pBVar2 = SSL_get_wbio(param_1);
      lVar3 = BIO_ctrl(pBVar2,0x2b,0,(void *)0x0);
      if (lVar3 < 1) {
        return -1;
      }
      pdVar9 = param_1->d1;
      pBVar2 = SSL_get_wbio(param_1);
      lVar3 = BIO_ctrl(pBVar2,0x28,0,(void *)0x0);
      iVar7 = param_1->init_num;
      *(long *)&pdVar9->w_msg_hdr = lVar3;
    }
    if (iVar4 != iVar8) {
      OpenSSLDie("d1_both.c",0x166,"len == (unsigned int)ret");
    }
    if (iVar4 == param_1->init_num) break;
    iVar7 = param_1->init_num - iVar4;
    param_1->init_num = iVar7;
    param_1->init_off = iVar4 + param_1->init_off;
  }
  if (param_1->msg_callback != (_func_3150 *)0x0) {
    (*param_1->msg_callback)
              (1,param_1->version,0x14,param_1->init_buf->data,iVar4 + param_1->init_off,param_1,
               param_1->msg_callback_arg);
  }
  param_1->init_off = 0;
  param_1->init_num = 0;
  return 1;
}

