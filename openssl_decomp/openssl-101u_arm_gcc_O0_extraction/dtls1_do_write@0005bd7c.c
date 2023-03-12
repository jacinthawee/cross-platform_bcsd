
long dtls1_do_write(SSL *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  BIO *pBVar3;
  long lVar4;
  EVP_MD_CTX *ctx;
  EVP_MD *md;
  ulong uVar5;
  EVP_CIPHER_CTX *pEVar6;
  BUF_MEM *pBVar7;
  int iVar8;
  dtls1_state_st *pdVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  int iVar15;
  char *pcVar16;
  uint local_30;
  
  iVar2 = dtls1_query_mtu();
  if (iVar2 == 0) {
    return -1;
  }
  uVar13 = (param_1->d1->w_msg_hdr).msg_len;
  pBVar3 = SSL_get_wbio(param_1);
  lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
  if (uVar13 < 0x100U - lVar4) {
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu(s)");
  }
  if (((param_1->init_off == 0) && (param_2 == 0x16)) &&
     (param_1->init_num != (param_1->d1->w_msg_hdr).frag_off + 0xc)) {
    OpenSSLDie("d1_both.c",0x118,
               "s->init_num == (int)s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH");
  }
  ctx = param_1->write_hash;
  if (ctx != (EVP_MD_CTX *)0x0) {
    md = EVP_MD_CTX_md(ctx);
    ctx = (EVP_MD_CTX *)EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar5 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), -1 < (int)(uVar5 << 0x1e))) {
    iVar2 = 0;
  }
  else {
    iVar2 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    iVar2 = iVar2 << 1;
  }
  param_1->rwstate = 1;
  uVar13 = 1;
  iVar10 = param_1->init_num;
  iVar15 = (int)&ctx->digest + iVar2;
  local_30 = 0;
  do {
    if (iVar10 < 1) {
      return 0;
    }
    if ((param_2 == 0x16) && (iVar8 = param_1->init_off, iVar8 != 0)) {
      if (local_30 == 0) {
        local_30 = (param_1->d1->w_msg_hdr).is_ccs;
      }
      else {
        if (iVar8 < 0xd) {
          return -1;
        }
        param_1->init_off = iVar8 + -0xc;
        param_1->init_num = iVar10 + 0xc;
      }
    }
    pBVar3 = SSL_get_wbio(param_1);
    lVar4 = BIO_ctrl(pBVar3,0xd,0,(void *)0x0);
    pdVar9 = param_1->d1;
    uVar11 = (pdVar9->w_msg_hdr).msg_len;
    uVar12 = (int)&ctx->md_data + lVar4 + iVar2 + 1;
    if ((uVar12 < uVar11) && (uVar11 = uVar11 - uVar12, 0xc < uVar11)) {
      uVar12 = param_1->init_num;
      if (uVar11 <= (uint)param_1->init_num) {
        uVar12 = uVar11;
      }
      if ((int)uVar12 < 0) goto LAB_0005bf76;
LAB_0005be72:
      if (param_2 == 0x16) {
        if (uVar12 < 0xc) {
          return -1;
        }
        pEVar6 = (EVP_CIPHER_CTX *)(uVar12 - 0xc);
        goto LAB_0005be86;
      }
    }
    else {
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0xb,0,(void *)0x0);
      if (lVar4 < 1) {
        param_1->rwstate = 2;
        return lVar4;
      }
      pdVar9 = param_1->d1;
      uVar12 = (pdVar9->w_msg_hdr).msg_len;
      if (uVar12 <= iVar15 + 0x19U) {
        return -1;
      }
      uVar11 = (uVar12 - 0xd) - iVar15;
      uVar12 = param_1->init_num;
      if (uVar11 <= (uint)param_1->init_num) {
        uVar12 = uVar11;
      }
      if (-1 < (int)uVar12) goto LAB_0005be72;
LAB_0005bf76:
      uVar12 = 0x7fffffff;
      if (param_2 == 0x16) {
        pEVar6 = (EVP_CIPHER_CTX *)0x7ffffff3;
LAB_0005be86:
        (pdVar9->w_msg_hdr).saved_retransmit_state.enc_write_ctx = pEVar6;
        pBVar7 = param_1->init_buf;
        (pdVar9->w_msg_hdr).is_ccs = local_30;
        pdVar9 = param_1->d1;
        iVar10 = param_1->init_off;
        pcVar16 = pBVar7->data;
        pcVar16[iVar10] = *(char *)&(pdVar9->w_msg_hdr).seq;
        pcVar16[iVar10 + 1] = (char)*(undefined2 *)((int)&(pdVar9->w_msg_hdr).frag_off + 2);
        pcVar16[iVar10 + 2] = (char)((pdVar9->w_msg_hdr).frag_off >> 8);
        pcVar16[iVar10 + 3] = (char)(pdVar9->w_msg_hdr).frag_off;
        pcVar16[iVar10 + 4] = (char)((ushort)*(undefined2 *)&(pdVar9->w_msg_hdr).frag_len >> 8);
        pcVar16[iVar10 + 5] = (char)*(undefined2 *)&(pdVar9->w_msg_hdr).frag_len;
        pcVar16[iVar10 + 6] = (char)*(undefined2 *)((int)&(pdVar9->w_msg_hdr).is_ccs + 2);
        pcVar16[iVar10 + 7] = (char)((pdVar9->w_msg_hdr).is_ccs >> 8);
        pcVar16[iVar10 + 8] = (char)(pdVar9->w_msg_hdr).is_ccs;
        pcVar16[iVar10 + 9] =
             (char)*(undefined2 *)
                    ((int)&(pdVar9->w_msg_hdr).saved_retransmit_state.enc_write_ctx + 2);
        pcVar16[iVar10 + 10] =
             (char)((uint)(pdVar9->w_msg_hdr).saved_retransmit_state.enc_write_ctx >> 8);
        pcVar16[iVar10 + 0xb] = (char)(pdVar9->w_msg_hdr).saved_retransmit_state.enc_write_ctx;
      }
    }
    uVar11 = dtls1_write_bytes(param_1,param_2,param_1->init_buf->data + param_1->init_off,uVar12);
    if ((int)uVar11 < 0) {
      if (uVar13 == 0) {
        return -1;
      }
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0x2b,0,(void *)0x0);
      if (lVar4 < 1) {
        return -1;
      }
      uVar13 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      uVar13 = uVar13 & 0x1000;
      if (uVar13 != 0) {
        return -1;
      }
      iVar10 = dtls1_query_mtu(param_1);
      if (iVar10 == 0) {
        return -1;
      }
      iVar10 = param_1->init_num;
    }
    else {
      if (uVar11 != uVar12) {
        OpenSSLDie("d1_both.c",0x19f,"len == (unsigned int)ret");
      }
      if ((param_2 == 0x16) && (pdVar9 = param_1->d1, pdVar9->listen == 0)) {
        pcVar14 = param_1->init_buf->data;
        pcVar16 = pcVar14 + param_1->init_off;
        if ((local_30 == 0) && (param_1->version != 0x100)) {
          pcVar14[param_1->init_off] = *(char *)&(pdVar9->w_msg_hdr).seq;
          pcVar16[1] = (char)*(undefined2 *)((int)&(pdVar9->w_msg_hdr).frag_off + 2);
          pcVar16[2] = (char)((pdVar9->w_msg_hdr).frag_off >> 8);
          pcVar16[3] = (char)(pdVar9->w_msg_hdr).frag_off;
          pcVar16[4] = (char)((ushort)*(undefined2 *)&(pdVar9->w_msg_hdr).frag_len >> 8);
          uVar1 = *(undefined2 *)&(pdVar9->w_msg_hdr).frag_len;
          pcVar16[6] = '\0';
          pcVar16[7] = '\0';
          pcVar16[5] = (char)uVar1;
          pcVar16[8] = '\0';
          pcVar16[9] = (char)*(undefined2 *)((int)&(pdVar9->w_msg_hdr).frag_off + 2);
          pcVar16[10] = (char)((pdVar9->w_msg_hdr).frag_off >> 8);
          pcVar16[0xb] = (char)(pdVar9->w_msg_hdr).frag_off;
          uVar12 = uVar11;
        }
        else {
          pcVar16 = pcVar16 + 0xc;
          uVar12 = uVar11 - 0xc;
        }
        ssl3_finish_mac(param_1,pcVar16,uVar12);
        uVar12 = param_1->init_num;
      }
      else {
        uVar12 = param_1->init_num;
      }
      if (uVar12 == uVar11) {
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,param_2,param_1->init_buf->data,param_1->init_off + uVar11,
                     param_1,param_1->msg_callback_arg);
        }
        param_1->init_off = 0;
        param_1->init_num = 0;
        return 1;
      }
      pdVar9 = param_1->d1;
      iVar10 = uVar12 - uVar11;
      param_1->init_num = iVar10;
      local_30 = local_30 + (uVar11 - 0xc);
      param_1->init_off = param_1->init_off + uVar11;
      (pdVar9->w_msg_hdr).is_ccs = local_30;
      (pdVar9->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
  } while( true );
}

