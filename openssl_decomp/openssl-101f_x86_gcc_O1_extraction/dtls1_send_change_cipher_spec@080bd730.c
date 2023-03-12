
long dtls1_send_change_cipher_spec(SSL *param_1,int param_2,int param_3)

{
  char *pcVar1;
  EVP_MD *md;
  ulong uVar2;
  int iVar3;
  BIO *pBVar4;
  long lVar5;
  dtls1_state_st *pdVar6;
  uint uVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  int local_20;
  
  if (param_1->state == param_2) {
    pcVar1 = param_1->init_buf->data;
    *pcVar1 = '\x01';
    pdVar6 = param_1->d1;
    iVar10 = param_1->version;
    uVar8 = pdVar6->next_handshake_write_seq;
    pdVar6->handshake_write_seq = uVar8;
    param_1->init_num = 1;
    if (iVar10 == 0x100) {
      pdVar6->next_handshake_write_seq = uVar8 + 1;
      pcVar1[1] = (char)(uVar8 >> 8);
      pcVar1[2] = (char)param_1->d1->handshake_write_seq;
      pdVar6 = param_1->d1;
      param_1->init_num = param_1->init_num + 2;
      uVar8 = pdVar6->handshake_write_seq;
    }
    param_1->init_off = 0;
    *(undefined *)&(pdVar6->w_msg_hdr).msg_len = 1;
    *(undefined4 *)&(pdVar6->w_msg_hdr).seq = 0;
    *(ushort *)&(pdVar6->w_msg_hdr).frag_off = uVar8;
    (pdVar6->w_msg_hdr).frag_len = 0;
    (pdVar6->w_msg_hdr).is_ccs = 0;
    dtls1_buffer_message(param_1,1);
    param_1->state = param_3;
    uVar7 = *(uint *)&param_1->d1->w_msg_hdr;
  }
  else {
    uVar7 = *(uint *)&param_1->d1->w_msg_hdr;
  }
  if (uVar7 < 0xe4) {
    uVar7 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar7 & 0x1000) == 0) {
      pdVar6 = param_1->d1;
      pBVar4 = SSL_get_wbio(param_1);
      lVar5 = BIO_ctrl(pBVar4,0x28,0,(void *)0x0);
      *(long *)&pdVar6->w_msg_hdr = lVar5;
      if (0xe3 < *(uint *)&param_1->d1->w_msg_hdr) goto LAB_080bd75b;
      *(undefined4 *)&param_1->d1->w_msg_hdr = 0x5c0;
      pBVar4 = SSL_get_wbio(param_1);
      BIO_ctrl(pBVar4,0x2a,0x5c0,(void *)0x0);
    }
    if (*(uint *)&param_1->d1->w_msg_hdr < 0xe4) {
      OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu()");
    }
  }
LAB_080bd75b:
  local_20 = 0;
  if (param_1->write_hash != (EVP_MD_CTX *)0x0) {
    md = EVP_MD_CTX_md(param_1->write_hash);
    local_20 = EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar2 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), (uVar2 & 2) == 0)) {
    iVar10 = 0;
  }
  else {
    iVar10 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    iVar10 = iVar10 * 2;
  }
  iVar3 = param_1->init_num;
  do {
    if (iVar3 == 0) {
      return 0;
    }
    while( true ) {
      iVar3 = *(int *)&param_1->d1->w_msg_hdr;
      pBVar4 = SSL_get_wbio(param_1);
      lVar5 = BIO_ctrl(pBVar4,0xd,0,(void *)0x0);
      iVar9 = (iVar3 - lVar5) + ((-0xd - local_20) - iVar10);
      if (iVar9 < 0xd) {
        pBVar4 = SSL_get_wbio(param_1);
        lVar5 = BIO_ctrl(pBVar4,0xb,0,(void *)0x0);
        if (lVar5 < 1) {
          return lVar5;
        }
        iVar9 = ((*(int *)&param_1->d1->w_msg_hdr + -0xd) - local_20) - iVar10;
      }
      if (param_1->init_num <= iVar9) {
        iVar9 = param_1->init_num;
      }
      iVar3 = dtls1_write_bytes(param_1,0x14,param_1->init_buf->data + param_1->init_off,iVar9);
      if (-1 < iVar3) break;
      pBVar4 = SSL_get_wbio(param_1);
      lVar5 = BIO_ctrl(pBVar4,0x2b,0,(void *)0x0);
      if (lVar5 < 1) {
        return -1;
      }
      pdVar6 = param_1->d1;
      pBVar4 = SSL_get_wbio(param_1);
      lVar5 = BIO_ctrl(pBVar4,0x28,0,(void *)0x0);
      *(long *)&pdVar6->w_msg_hdr = lVar5;
      if (param_1->init_num == 0) {
        return 0;
      }
    }
    if (iVar3 != iVar9) {
      OpenSSLDie("d1_both.c",0x166,"len == (unsigned int)ret");
    }
    if (iVar3 == param_1->init_num) {
      if (param_1->msg_callback != (_func_3150 *)0x0) {
        (*param_1->msg_callback)
                  (1,param_1->version,0x14,param_1->init_buf->data,iVar3 + param_1->init_off,param_1
                   ,param_1->msg_callback_arg);
      }
      param_1->init_off = 0;
      param_1->init_num = 0;
      return 1;
    }
    param_1->init_off = param_1->init_off + iVar3;
    iVar3 = param_1->init_num - iVar3;
    param_1->init_num = iVar3;
  } while( true );
}

