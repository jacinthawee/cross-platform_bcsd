
int dtls1_do_write(SSL *param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  BIO *pBVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  dtls1_state_st *pdVar11;
  uint uVar12;
  BUF_MEM *pBVar13;
  char *pcVar14;
  uint uVar15;
  
  iVar4 = dtls1_query_mtu();
  if (iVar4 == 0) {
    return -1;
  }
  uVar15 = (param_1->d1->w_msg_hdr).msg_len;
  pBVar5 = SSL_get_wbio(param_1);
  iVar4 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar5,0x31,0,0);
  if (uVar15 < 0x100U - iVar4) {
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu(s)");
  }
  if (((param_1->init_off == 0) && (param_2 == 0x16)) &&
     (param_1->init_num != (param_1->d1->w_msg_hdr).frag_off + 0xc)) {
    OpenSSLDie("d1_both.c",0x118,
               "s->init_num == (int)s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH");
  }
  if (param_1->write_hash == (EVP_MD_CTX *)0x0) {
    iVar4 = 0;
  }
  else {
    uVar6 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
    iVar4 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar6);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar15 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)(param_1->enc_write_ctx->cipher),
     (uVar15 & 2) == 0)) {
    iVar7 = 0;
  }
  else {
    iVar7 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(param_1->enc_write_ctx->cipher);
    iVar7 = iVar7 << 1;
  }
  iVar10 = param_1->init_num;
  param_1->rwstate = 1;
  uVar15 = 0;
  bVar3 = true;
  do {
    if (iVar10 < 1) {
      return 0;
    }
    if ((param_2 == 0x16) && (iVar8 = param_1->init_off, iVar8 != 0)) {
      if (uVar15 == 0) {
        uVar15 = (param_1->d1->w_msg_hdr).is_ccs;
      }
      else {
        if (iVar8 < 0xd) {
          return -1;
        }
        param_1->init_off = iVar8 + -0xc;
        param_1->init_num = iVar10 + 0xc;
      }
    }
    pBVar5 = SSL_get_wbio(param_1);
    iVar10 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar5,0xd,0,0);
    pdVar11 = param_1->d1;
    uVar9 = iVar4 + 0xd + iVar7 + iVar10;
    uVar12 = (pdVar11->w_msg_hdr).msg_len;
    if ((uVar9 < uVar12) && (uVar12 = uVar12 - uVar9, 0xc < uVar12)) {
      uVar9 = param_1->init_num;
      if (uVar12 <= (uint)param_1->init_num) {
        uVar9 = uVar12;
      }
      if (-1 < (int)uVar9) goto LAB_004a27c0;
LAB_004a294c:
      uVar9 = 0x7fffffff;
      if (param_2 == 0x16) goto LAB_004a27d8;
    }
    else {
      pBVar5 = SSL_get_wbio(param_1);
      iVar10 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar5,0xb,0,0);
      if (iVar10 < 1) {
        param_1->rwstate = 2;
        return iVar10;
      }
      pdVar11 = param_1->d1;
      uVar9 = (pdVar11->w_msg_hdr).msg_len;
      if (uVar9 <= iVar4 + iVar7 + 0x19U) {
        return -1;
      }
      uVar12 = (uVar9 - 0xd) - (iVar4 + iVar7);
      uVar9 = param_1->init_num;
      if (uVar12 <= (uint)param_1->init_num) {
        uVar9 = uVar12;
      }
      if ((int)uVar9 < 0) goto LAB_004a294c;
LAB_004a27c0:
      if (param_2 == 0x16) {
        if (uVar9 < 0xc) {
          return -1;
        }
LAB_004a27d8:
        pBVar13 = param_1->init_buf;
        iVar10 = param_1->init_off;
        cVar1 = *(char *)&(pdVar11->w_msg_hdr).seq;
        (pdVar11->w_msg_hdr).is_ccs = uVar15;
        pcVar14 = pBVar13->data;
        (pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)(uVar9 - 0xc);
        pcVar14 = pcVar14 + iVar10;
        *pcVar14 = cVar1;
        pcVar14[1] = (char)*(undefined2 *)&(pdVar11->w_msg_hdr).frag_off;
        pcVar14[2] = (char)((pdVar11->w_msg_hdr).frag_off >> 8);
        pcVar14[3] = (char)(pdVar11->w_msg_hdr).frag_off;
        pcVar14[4] = (char)((ushort)*(undefined2 *)&(pdVar11->w_msg_hdr).frag_len >> 8);
        pcVar14[5] = (char)*(undefined2 *)&(pdVar11->w_msg_hdr).frag_len;
        pcVar14[6] = (char)*(undefined2 *)&(pdVar11->w_msg_hdr).is_ccs;
        pcVar14[7] = (char)((pdVar11->w_msg_hdr).is_ccs >> 8);
        pcVar14[8] = (char)(pdVar11->w_msg_hdr).is_ccs;
        pcVar14[9] = (char)*(undefined2 *)&(pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx
        ;
        pcVar14[10] = (char)((uint)(pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx >> 8);
        pcVar14[0xb] = (char)(pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx;
      }
    }
    uVar12 = dtls1_write_bytes(param_1,param_2,param_1->init_buf->data + param_1->init_off,uVar9);
    if ((int)uVar12 < 0) {
      if (!bVar3) {
        return -1;
      }
      pBVar5 = SSL_get_wbio(param_1);
      iVar10 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar5,0x2b,0,0);
      if (iVar10 < 1) {
        return -1;
      }
      uVar9 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((uVar9 & 0x1000) != 0) {
        return -1;
      }
      iVar10 = dtls1_query_mtu(param_1);
      if (iVar10 == 0) {
        return -1;
      }
      iVar10 = param_1->init_num;
      bVar3 = false;
    }
    else {
      if (uVar12 != uVar9) {
        OpenSSLDie("d1_both.c",0x19f,"len == (unsigned int)ret");
      }
      if ((param_2 == 0x16) && (pdVar11 = param_1->d1, pdVar11->listen == 0)) {
        pcVar14 = param_1->init_buf->data + param_1->init_off;
        if ((uVar15 == 0) && (param_1->version != 0x100)) {
          *pcVar14 = *(char *)&(pdVar11->w_msg_hdr).seq;
          pcVar14[1] = (char)*(undefined2 *)&(pdVar11->w_msg_hdr).frag_off;
          pcVar14[2] = (char)((pdVar11->w_msg_hdr).frag_off >> 8);
          pcVar14[3] = (char)(pdVar11->w_msg_hdr).frag_off;
          pcVar14[4] = (char)((ushort)*(undefined2 *)&(pdVar11->w_msg_hdr).frag_len >> 8);
          uVar2 = *(undefined2 *)&(pdVar11->w_msg_hdr).frag_len;
          pcVar14[6] = '\0';
          pcVar14[7] = '\0';
          pcVar14[8] = '\0';
          pcVar14[5] = (char)uVar2;
          pcVar14[9] = (char)*(undefined2 *)&(pdVar11->w_msg_hdr).frag_off;
          pcVar14[10] = (char)((pdVar11->w_msg_hdr).frag_off >> 8);
          pcVar14[0xb] = (char)(pdVar11->w_msg_hdr).frag_off;
          uVar9 = uVar12;
        }
        else {
          pcVar14 = pcVar14 + 0xc;
          uVar9 = uVar12 - 0xc;
        }
        ssl3_finish_mac(param_1,pcVar14,uVar9);
        uVar9 = param_1->init_num;
      }
      else {
        uVar9 = param_1->init_num;
      }
      if (uVar12 == uVar9) {
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,param_2,param_1->init_buf->data,uVar12 + param_1->init_off,
                     param_1,param_1->msg_callback_arg);
        }
        param_1->init_off = 0;
        param_1->init_num = 0;
        return 1;
      }
      pdVar11 = param_1->d1;
      iVar10 = uVar9 - uVar12;
      uVar15 = uVar15 + (uVar12 - 0xc);
      param_1->init_num = iVar10;
      param_1->init_off = param_1->init_off + uVar12;
      (pdVar11->w_msg_hdr).is_ccs = uVar15;
      (pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
  } while( true );
}

