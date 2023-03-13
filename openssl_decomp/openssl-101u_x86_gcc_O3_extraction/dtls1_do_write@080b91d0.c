
long dtls1_do_write(SSL *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  BUF_MEM *pBVar3;
  bool bVar4;
  int iVar5;
  BIO *pBVar6;
  long lVar7;
  EVP_MD *md;
  ulong uVar8;
  uint uVar9;
  EVP_CIPHER_CTX *pEVar10;
  uint uVar11;
  dtls1_state_st *pdVar12;
  char *pcVar13;
  uint uVar14;
  uint local_30;
  int local_24;
  int local_20;
  
  iVar5 = dtls1_query_mtu();
  if (iVar5 == 0) {
    return -1;
  }
  uVar14 = (param_1->d1->w_msg_hdr).msg_len;
  pBVar6 = SSL_get_wbio(param_1);
  lVar7 = BIO_ctrl(pBVar6,0x31,0,(void *)0x0);
  if (uVar14 < 0x100U - lVar7) {
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu(s)");
  }
  if (((param_1->init_off == 0) && (param_2 == 0x16)) &&
     (param_1->init_num != (param_1->d1->w_msg_hdr).frag_off + 0xc)) {
    OpenSSLDie("d1_both.c",0x118,
               "s->init_num == (int)s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH");
  }
  local_24 = 0;
  if (param_1->write_hash != (EVP_MD_CTX *)0x0) {
    md = EVP_MD_CTX_md(param_1->write_hash);
    local_24 = EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar8 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), (uVar8 & 2) == 0)) {
    local_20 = 0;
  }
  else {
    local_20 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    local_20 = local_20 * 2;
  }
  uVar14 = 0;
  iVar5 = param_1->init_num;
  param_1->rwstate = 1;
  bVar4 = true;
  do {
    if (iVar5 < 1) {
      return 0;
    }
    if ((param_2 == 0x16) && (iVar2 = param_1->init_off, iVar2 != 0)) {
      if (uVar14 == 0) {
        uVar14 = (param_1->d1->w_msg_hdr).is_ccs;
      }
      else {
        if (iVar2 < 0xd) {
          return -1;
        }
        param_1->init_off = iVar2 + -0xc;
        param_1->init_num = iVar5 + 0xc;
      }
    }
    pBVar6 = SSL_get_wbio(param_1);
    lVar7 = BIO_ctrl(pBVar6,0xd,0,(void *)0x0);
    pdVar12 = param_1->d1;
    uVar9 = lVar7 + local_24 + 0xd + local_20;
    local_30 = (pdVar12->w_msg_hdr).msg_len;
    if ((uVar9 < local_30) && (local_30 = local_30 - uVar9, 0xc < local_30)) {
      if ((uint)param_1->init_num < local_30) {
        local_30 = param_1->init_num;
      }
      if ((int)local_30 < 0) goto LAB_080b94bb;
LAB_080b9356:
      if (param_2 == 0x16) {
        if (local_30 < 0xc) {
          return -1;
        }
        pEVar10 = (EVP_CIPHER_CTX *)(local_30 - 0xc);
        goto LAB_080b9371;
      }
    }
    else {
      pBVar6 = SSL_get_wbio(param_1);
      lVar7 = BIO_ctrl(pBVar6,0xb,0,(void *)0x0);
      if (lVar7 < 1) {
        param_1->rwstate = 2;
        return lVar7;
      }
      pdVar12 = param_1->d1;
      uVar9 = (pdVar12->w_msg_hdr).msg_len;
      if (uVar9 <= local_24 + local_20 + 0x19U) {
        return -1;
      }
      local_30 = (uVar9 - 0xd) - (local_24 + local_20);
      if ((uint)param_1->init_num < local_30) {
        local_30 = param_1->init_num;
      }
      if (-1 < (int)local_30) goto LAB_080b9356;
LAB_080b94bb:
      local_30 = 0x7fffffff;
      if (param_2 == 0x16) {
        pEVar10 = (EVP_CIPHER_CTX *)0x7ffffff3;
LAB_080b9371:
        (pdVar12->w_msg_hdr).saved_retransmit_state.enc_write_ctx = pEVar10;
        pBVar3 = param_1->init_buf;
        iVar5 = param_1->init_off;
        (pdVar12->w_msg_hdr).is_ccs = uVar14;
        pcVar13 = pBVar3->data + iVar5;
        *pcVar13 = *(char *)&(pdVar12->w_msg_hdr).seq;
        pcVar13[1] = (char)*(undefined2 *)((int)&(pdVar12->w_msg_hdr).frag_off + 2);
        pcVar13[2] = (char)((pdVar12->w_msg_hdr).frag_off >> 8);
        pcVar13[3] = *(char *)&(pdVar12->w_msg_hdr).frag_off;
        pcVar13[4] = *(char *)((int)&(pdVar12->w_msg_hdr).frag_len + 1);
        pcVar13[5] = *(char *)&(pdVar12->w_msg_hdr).frag_len;
        pcVar13[6] = (char)*(undefined2 *)((int)&(pdVar12->w_msg_hdr).is_ccs + 2);
        pcVar13[7] = (char)((pdVar12->w_msg_hdr).is_ccs >> 8);
        pcVar13[8] = *(char *)&(pdVar12->w_msg_hdr).is_ccs;
        pcVar13[9] = (char)*(undefined2 *)
                            ((int)&(pdVar12->w_msg_hdr).saved_retransmit_state.enc_write_ctx + 2);
        pcVar13[10] = (char)((uint)(pdVar12->w_msg_hdr).saved_retransmit_state.enc_write_ctx >> 8);
        pcVar13[0xb] = (char)(pdVar12->w_msg_hdr).saved_retransmit_state.enc_write_ctx;
      }
    }
    uVar9 = dtls1_write_bytes(param_1,param_2,param_1->init_buf->data + param_1->init_off,local_30);
    if ((int)uVar9 < 0) {
      if (!bVar4) {
        return -1;
      }
      pBVar6 = SSL_get_wbio(param_1);
      lVar7 = BIO_ctrl(pBVar6,0x2b,0,(void *)0x0);
      if (lVar7 < 1) {
        return -1;
      }
      uVar9 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((uVar9 & 0x1000) != 0) {
        return -1;
      }
      iVar5 = dtls1_query_mtu();
      if (iVar5 == 0) {
        return -1;
      }
      iVar5 = param_1->init_num;
      bVar4 = false;
    }
    else {
      if (uVar9 != local_30) {
        OpenSSLDie("d1_both.c",0x19f,"len == (unsigned int)ret");
      }
      if ((param_2 == 0x16) && (pdVar12 = param_1->d1, pdVar12->listen == 0)) {
        pcVar13 = param_1->init_buf->data + param_1->init_off;
        if ((uVar14 == 0) && (param_1->version != 0x100)) {
          *pcVar13 = *(char *)&(pdVar12->w_msg_hdr).seq;
          pcVar13[1] = (char)*(undefined2 *)((int)&(pdVar12->w_msg_hdr).frag_off + 2);
          pcVar13[2] = (char)((pdVar12->w_msg_hdr).frag_off >> 8);
          pcVar13[3] = (char)(pdVar12->w_msg_hdr).frag_off;
          pcVar13[4] = *(char *)((int)&(pdVar12->w_msg_hdr).frag_len + 1);
          uVar1 = *(undefined2 *)&(pdVar12->w_msg_hdr).frag_len;
          pcVar13[6] = '\0';
          pcVar13[7] = '\0';
          pcVar13[8] = '\0';
          pcVar13[5] = (char)uVar1;
          pcVar13[9] = (char)*(undefined2 *)((int)&(pdVar12->w_msg_hdr).frag_off + 2);
          pcVar13[10] = (char)((pdVar12->w_msg_hdr).frag_off >> 8);
          pcVar13[0xb] = (char)(pdVar12->w_msg_hdr).frag_off;
          uVar11 = uVar9;
        }
        else {
          uVar11 = uVar9 - 0xc;
          pcVar13 = pcVar13 + 0xc;
        }
        ssl3_finish_mac(param_1,pcVar13,uVar11);
        uVar11 = param_1->init_num;
      }
      else {
        uVar11 = param_1->init_num;
      }
      if (uVar9 == uVar11) {
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,param_2,param_1->init_buf->data,uVar9 + param_1->init_off,
                     param_1,param_1->msg_callback_arg);
        }
        param_1->init_off = 0;
        param_1->init_num = 0;
        return 1;
      }
      pdVar12 = param_1->d1;
      iVar5 = uVar11 - uVar9;
      uVar14 = (uVar14 - 0xc) + uVar9;
      param_1->init_off = param_1->init_off + uVar9;
      param_1->init_num = iVar5;
      (pdVar12->w_msg_hdr).is_ccs = uVar14;
      (pdVar12->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
  } while( true );
}

