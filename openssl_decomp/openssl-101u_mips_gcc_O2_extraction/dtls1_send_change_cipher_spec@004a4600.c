
int dtls1_send_change_cipher_spec(SSL *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  BIO *pBVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  char *pcVar10;
  dtls1_state_st *pdVar11;
  uint uVar12;
  
  if (param_1->state == param_2) {
    pcVar10 = param_1->init_buf->data;
    *pcVar10 = '\x01';
    pdVar11 = param_1->d1;
    iVar2 = param_1->version;
    uVar9 = pdVar11->next_handshake_write_seq;
    pdVar11->handshake_write_seq = uVar9;
    param_1->init_num = 1;
    if (iVar2 == 0x100) {
      pdVar11->next_handshake_write_seq = uVar9 + 1;
      pcVar10[1] = (char)(uVar9 >> 8);
      pcVar10[2] = (char)param_1->d1->handshake_write_seq;
      pdVar11 = param_1->d1;
      uVar9 = pdVar11->handshake_write_seq;
      param_1->init_num = param_1->init_num + 2;
    }
    param_1->init_off = 0;
    *(ushort *)&(pdVar11->w_msg_hdr).frag_len = uVar9;
    (pdVar11->w_msg_hdr).frag_off = 0;
    (pdVar11->w_msg_hdr).is_ccs = 0;
    *(undefined *)&(pdVar11->w_msg_hdr).seq = 1;
    (pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    dtls1_buffer_message(param_1,1);
    param_1->state = param_3;
  }
  iVar2 = dtls1_query_mtu(param_1);
  if (iVar2 == 0) {
    return -1;
  }
  uVar12 = (param_1->d1->w_msg_hdr).msg_len;
  pBVar3 = SSL_get_wbio(param_1);
  iVar2 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar3,0x31,0,0);
  if (uVar12 < 0x100U - iVar2) {
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu(s)");
  }
  if (param_1->write_hash == (EVP_MD_CTX *)0x0) {
    iVar2 = 0;
  }
  else {
    uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
    iVar2 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar4);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar12 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)(param_1->enc_write_ctx->cipher),
     (uVar12 & 2) == 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(param_1->enc_write_ctx->cipher);
    iVar5 = iVar5 << 1;
  }
  iVar7 = param_1->init_num;
  uVar12 = 0;
  param_1->rwstate = 1;
  bVar1 = true;
  while( true ) {
    while( true ) {
      if (iVar7 < 1) {
        return 0;
      }
      pBVar3 = SSL_get_wbio(param_1);
      iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar3,0xd,0,0);
      uVar6 = iVar2 + 0xd + iVar5 + iVar7;
      uVar8 = (param_1->d1->w_msg_hdr).msg_len;
      if ((uVar6 < uVar8) && (uVar8 = uVar8 - uVar6, 0xc < uVar8)) {
        uVar6 = param_1->init_num;
        if (uVar8 < (uint)param_1->init_num) {
          uVar6 = uVar8;
        }
      }
      else {
        pBVar3 = SSL_get_wbio(param_1);
        iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar3,0xb,0,0);
        if (iVar7 < 1) {
          param_1->rwstate = 2;
          return iVar7;
        }
        uVar6 = (param_1->d1->w_msg_hdr).msg_len;
        if (uVar6 <= iVar2 + iVar5 + 0x19U) {
          return -1;
        }
        uVar8 = (uVar6 - 0xd) - (iVar2 + iVar5);
        uVar6 = param_1->init_num;
        if (uVar8 < (uint)param_1->init_num) {
          uVar6 = uVar8;
        }
      }
      if ((int)uVar6 < 0) {
        uVar6 = 0x7fffffff;
      }
      uVar8 = dtls1_write_bytes(param_1,0x14,param_1->init_buf->data + param_1->init_off,uVar6);
      if ((int)uVar8 < 0) break;
      if (uVar6 != uVar8) {
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
      pdVar11 = param_1->d1;
      iVar7 = param_1->init_num - uVar8;
      uVar12 = uVar12 + (uVar8 - 0xc);
      param_1->init_num = iVar7;
      param_1->init_off = param_1->init_off + uVar8;
      (pdVar11->w_msg_hdr).is_ccs = uVar12;
      (pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
    if (!bVar1) {
      return -1;
    }
    pBVar3 = SSL_get_wbio(param_1);
    iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar3,0x2b,0,0);
    if (iVar7 < 1) break;
    uVar6 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar6 & 0x1000) != 0) {
      return -1;
    }
    iVar7 = dtls1_query_mtu(param_1);
    if (iVar7 == 0) {
      return -1;
    }
    iVar7 = param_1->init_num;
    bVar1 = false;
  }
  return -1;
}

