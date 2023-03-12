
int dtls1_send_change_cipher_spec(SSL *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  BIO *pBVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  char *pcVar7;
  int iVar8;
  dtls1_state_st *pdVar9;
  dtls1_state_st *pdVar10;
  int iVar11;
  int iVar12;
  
  if (param_1->state == param_2) {
    pcVar7 = param_1->init_buf->data;
    *pcVar7 = '\x01';
    pdVar9 = param_1->d1;
    iVar12 = param_1->version;
    uVar6 = pdVar9->next_handshake_write_seq;
    pdVar9->handshake_write_seq = uVar6;
    param_1->init_num = 1;
    if (iVar12 == 0x100) {
      pdVar9->next_handshake_write_seq = uVar6 + 1;
      pcVar7[1] = (char)(uVar6 >> 8);
      pcVar7[2] = (char)param_1->d1->handshake_write_seq;
      pdVar9 = param_1->d1;
      uVar6 = pdVar9->handshake_write_seq;
      param_1->init_num = param_1->init_num + 2;
    }
    param_1->init_off = 0;
    *(ushort *)&(pdVar9->w_msg_hdr).frag_off = uVar6;
    *(undefined4 *)&(pdVar9->w_msg_hdr).seq = 0;
    (pdVar9->w_msg_hdr).frag_len = 0;
    *(undefined *)&(pdVar9->w_msg_hdr).msg_len = 1;
    (pdVar9->w_msg_hdr).is_ccs = 0;
    dtls1_buffer_message(param_1,1);
    uVar2 = *(uint *)&param_1->d1->w_msg_hdr;
    param_1->state = param_3;
    if (uVar2 < 0xe4) goto LAB_004a79c0;
LAB_004a770c:
    iVar12 = 0;
    if (param_1->write_hash == (EVP_MD_CTX *)0x0) goto LAB_004a773c;
  }
  else {
    if (0xe3 < *(uint *)&param_1->d1->w_msg_hdr) goto LAB_004a770c;
LAB_004a79c0:
    uVar2 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar2 & 0x1000) == 0) {
      pdVar10 = param_1->d1;
      pBVar3 = SSL_get_wbio(param_1);
      uVar1 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar3,0x28,0,0);
      pdVar9 = param_1->d1;
      *(undefined4 *)&pdVar10->w_msg_hdr = uVar1;
      if (0xe3 < *(uint *)&pdVar9->w_msg_hdr) goto LAB_004a770c;
      *(undefined4 *)&pdVar9->w_msg_hdr = 0x5c0;
      pBVar3 = SSL_get_wbio(param_1);
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar3,0x2a,*(undefined4 *)&param_1->d1->w_msg_hdr,0);
    }
    if (0xe3 < *(uint *)&param_1->d1->w_msg_hdr) goto LAB_004a770c;
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu()");
    if (param_1->write_hash == (EVP_MD_CTX *)0x0) {
      iVar12 = 0;
      goto LAB_004a773c;
    }
  }
  uVar1 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
  iVar12 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar1);
LAB_004a773c:
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar2 = (*(code *)PTR_EVP_CIPHER_flags_006a9270)(param_1->enc_write_ctx->cipher),
     (uVar2 & 2) == 0)) {
    iVar11 = 0;
  }
  else {
    iVar11 = (*(code *)PTR_EVP_CIPHER_block_size_006a921c)(param_1->enc_write_ctx->cipher);
    iVar11 = iVar11 << 1;
  }
  iVar5 = param_1->init_num;
  while( true ) {
    while( true ) {
      if (iVar5 == 0) {
        return 0;
      }
      iVar8 = *(int *)&param_1->d1->w_msg_hdr;
      pBVar3 = SSL_get_wbio(param_1);
      iVar5 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar3,0xd,0,0);
      iVar5 = ((-0xd - iVar12) - iVar11) + (iVar8 - iVar5);
      if (iVar5 < 0xd) {
        pBVar3 = SSL_get_wbio(param_1);
        iVar5 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar3,0xb,0,0);
        if (iVar5 < 1) {
          return iVar5;
        }
        iVar5 = ((*(int *)&param_1->d1->w_msg_hdr + -0xd) - iVar12) - iVar11;
      }
      iVar8 = param_1->init_num;
      if (iVar5 < param_1->init_num) {
        iVar8 = iVar5;
      }
      iVar4 = dtls1_write_bytes(param_1,0x14,param_1->init_buf->data + param_1->init_off,iVar8);
      if (-1 < iVar4) break;
      pBVar3 = SSL_get_wbio(param_1);
      iVar5 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar3,0x2b,0,0);
      if (iVar5 < 1) {
        return -1;
      }
      pdVar9 = param_1->d1;
      pBVar3 = SSL_get_wbio(param_1);
      uVar1 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar3,0x28,0,0);
      iVar5 = param_1->init_num;
      *(undefined4 *)&pdVar9->w_msg_hdr = uVar1;
    }
    if (iVar4 != iVar8) {
      OpenSSLDie("d1_both.c",0x166,"len == (unsigned int)ret");
    }
    iVar5 = param_1->init_num - iVar4;
    if (iVar4 == param_1->init_num) break;
    param_1->init_num = iVar5;
    param_1->init_off = param_1->init_off + iVar4;
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

