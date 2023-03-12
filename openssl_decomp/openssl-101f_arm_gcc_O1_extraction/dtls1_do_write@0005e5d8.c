
long dtls1_do_write(SSL *param_1,int param_2)

{
  undefined2 uVar1;
  EVP_MD_CTX *ctx;
  EVP_MD *md;
  ulong uVar2;
  BIO *pBVar3;
  long lVar4;
  char *pcVar5;
  BUF_MEM *pBVar6;
  int iVar7;
  uint uVar8;
  dtls1_state_st *pdVar9;
  uint uVar10;
  dtls1_state_st *pdVar11;
  int iVar12;
  uint uVar13;
  char *pcVar14;
  
  if (*(uint *)&param_1->d1->w_msg_hdr < 0xe4) {
    uVar10 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar10 & 0x1000) == 0) {
      pdVar11 = param_1->d1;
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0x28,0,(void *)0x0);
      pdVar9 = param_1->d1;
      *(long *)&pdVar11->w_msg_hdr = lVar4;
      if (0xe3 < *(uint *)&pdVar9->w_msg_hdr) goto LAB_0005e5ee;
      *(undefined4 *)&pdVar9->w_msg_hdr = 0x5c0;
      pBVar3 = SSL_get_wbio(param_1);
      BIO_ctrl(pBVar3,0x2a,*(long *)&param_1->d1->w_msg_hdr,(void *)0x0);
    }
    if (*(uint *)&param_1->d1->w_msg_hdr < 0xe4) {
      OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu()");
    }
  }
LAB_0005e5ee:
  if (((param_1->init_off == 0) && (param_2 == 0x16)) &&
     (param_1->init_num != *(int *)&(param_1->d1->w_msg_hdr).seq + 0xc)) {
    OpenSSLDie("d1_both.c",0x116,
               "s->init_num == (int)s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH");
  }
  ctx = param_1->write_hash;
  if (ctx != (EVP_MD_CTX *)0x0) {
    md = EVP_MD_CTX_md(ctx);
    ctx = (EVP_MD_CTX *)EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar2 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), -1 < (int)(uVar2 << 0x1e))) {
    iVar12 = 0;
  }
  else {
    iVar12 = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    iVar12 = iVar12 << 1;
  }
  iVar7 = param_1->init_num;
  uVar2 = 0;
  while( true ) {
    while( true ) {
      if (iVar7 == 0) {
        return 0;
      }
      iVar7 = *(int *)&param_1->d1->w_msg_hdr;
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0xd,0,(void *)0x0);
      uVar10 = ((-0xd - (int)ctx) - iVar12) + (iVar7 - lVar4);
      if ((int)uVar10 < 0xd) {
        pBVar3 = SSL_get_wbio(param_1);
        lVar4 = BIO_ctrl(pBVar3,0xb,0,(void *)0x0);
        if (lVar4 < 1) {
          return lVar4;
        }
        uVar8 = param_1->init_num;
        uVar10 = ((*(int *)&param_1->d1->w_msg_hdr + -0xd) - (int)ctx) - iVar12;
        uVar13 = uVar10;
        if ((int)uVar8 <= (int)uVar10) {
          uVar13 = uVar8;
        }
      }
      else {
        uVar8 = param_1->init_num;
        uVar13 = uVar10;
        if ((int)uVar8 <= (int)uVar10) {
          uVar13 = uVar8;
        }
      }
      if (param_2 == 0x16) {
        iVar7 = param_1->init_off;
        if (iVar7 != 0) {
          if (iVar7 < 0xd) {
            OpenSSLDie("d1_both.c",0x13e,"s->init_off > DTLS1_HM_HEADER_LENGTH");
            iVar7 = param_1->init_off;
            uVar8 = param_1->init_num;
          }
          uVar8 = uVar8 + 0xc;
          iVar7 = iVar7 + -0xc;
          param_1->init_num = uVar8;
          uVar13 = uVar10;
          if ((int)uVar8 <= (int)uVar10) {
            uVar13 = uVar8;
          }
          param_1->init_off = iVar7;
        }
        pdVar9 = param_1->d1;
        pBVar6 = param_1->init_buf;
        (pdVar9->w_msg_hdr).is_ccs = uVar13 - 0xc;
        (pdVar9->w_msg_hdr).frag_len = uVar2;
        pdVar9 = param_1->d1;
        pcVar5 = pBVar6->data;
        pcVar5[iVar7] = *(char *)&(pdVar9->w_msg_hdr).msg_len;
        pcVar5[iVar7 + 1] = (char)*(undefined2 *)&(pdVar9->w_msg_hdr).field_0xa;
        pcVar5[iVar7 + 2] = (char)((uint)*(undefined4 *)&(pdVar9->w_msg_hdr).seq >> 8);
        pcVar5[iVar7 + 3] = (char)*(undefined4 *)&(pdVar9->w_msg_hdr).seq;
        pcVar5[iVar7 + 4] = (char)((ushort)*(undefined2 *)&(pdVar9->w_msg_hdr).frag_off >> 8);
        pcVar5[iVar7 + 5] = (char)*(undefined2 *)&(pdVar9->w_msg_hdr).frag_off;
        pcVar5[iVar7 + 6] = (char)*(undefined2 *)((int)&(pdVar9->w_msg_hdr).frag_len + 2);
        pcVar5[iVar7 + 7] = (char)((pdVar9->w_msg_hdr).frag_len >> 8);
        pcVar5[iVar7 + 8] = (char)(pdVar9->w_msg_hdr).frag_len;
        pcVar5[iVar7 + 9] = (char)*(undefined2 *)((int)&(pdVar9->w_msg_hdr).is_ccs + 2);
        pcVar5[iVar7 + 10] = (char)((pdVar9->w_msg_hdr).is_ccs >> 8);
        pcVar5[iVar7 + 0xb] = (char)(pdVar9->w_msg_hdr).is_ccs;
        if (uVar13 < 0xc) {
          OpenSSLDie("d1_both.c",0x14d,"len >= DTLS1_HM_HEADER_LENGTH");
        }
      }
      uVar10 = dtls1_write_bytes(param_1,param_2,param_1->init_buf->data + param_1->init_off,uVar13)
      ;
      if (-1 < (int)uVar10) break;
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0x2b,0,(void *)0x0);
      if (lVar4 < 1) {
        return -1;
      }
      pdVar9 = param_1->d1;
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0x28,0,(void *)0x0);
      iVar7 = param_1->init_num;
      *(long *)&pdVar9->w_msg_hdr = lVar4;
    }
    if (uVar10 != uVar13) {
      OpenSSLDie("d1_both.c",0x166,"len == (unsigned int)ret");
    }
    if ((param_2 == 0x16) && (pdVar9 = param_1->d1, pdVar9->change_cipher_spec_ok == 0)) {
      pcVar14 = param_1->init_buf->data;
      pcVar5 = pcVar14 + param_1->init_off;
      if ((uVar2 == 0) && (param_1->version != 0x100)) {
        pcVar14[param_1->init_off] = *(char *)&(pdVar9->w_msg_hdr).msg_len;
        pcVar5[1] = (char)*(undefined2 *)&(pdVar9->w_msg_hdr).field_0xa;
        pcVar5[2] = (char)((uint)*(undefined4 *)&(pdVar9->w_msg_hdr).seq >> 8);
        pcVar5[3] = (char)*(undefined4 *)&(pdVar9->w_msg_hdr).seq;
        pcVar5[4] = (char)((ushort)*(undefined2 *)&(pdVar9->w_msg_hdr).frag_off >> 8);
        uVar1 = *(undefined2 *)&(pdVar9->w_msg_hdr).frag_off;
        pcVar5[6] = '\0';
        pcVar5[7] = '\0';
        pcVar5[5] = (char)uVar1;
        pcVar5[8] = '\0';
        pcVar5[9] = (char)*(undefined2 *)&(pdVar9->w_msg_hdr).field_0xa;
        pcVar5[10] = (char)((uint)*(undefined4 *)&(pdVar9->w_msg_hdr).seq >> 8);
        pcVar5[0xb] = (char)*(undefined4 *)&(pdVar9->w_msg_hdr).seq;
        uVar8 = uVar10;
      }
      else {
        pcVar5 = pcVar5 + 0xc;
        uVar8 = uVar10 - 0xc;
      }
      ssl3_finish_mac(param_1,pcVar5,uVar8);
      uVar8 = param_1->init_num;
    }
    else {
      uVar8 = param_1->init_num;
    }
    if (uVar8 == uVar10) break;
    iVar7 = uVar8 - uVar10;
    param_1->init_num = iVar7;
    uVar2 = uVar2 + (uVar10 - 0xc);
    param_1->init_off = uVar10 + param_1->init_off;
  }
  if (param_1->msg_callback != (_func_3150 *)0x0) {
    (*param_1->msg_callback)
              (1,param_1->version,param_2,param_1->init_buf->data,param_1->init_off + uVar10,param_1
               ,param_1->msg_callback_arg);
  }
  param_1->init_off = 0;
  param_1->init_num = 0;
  return 1;
}

