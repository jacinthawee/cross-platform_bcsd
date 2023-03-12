
long dtls1_do_write(SSL *param_1,int param_2)

{
  undefined2 uVar1;
  dtls1_state_st *pdVar2;
  BUF_MEM *pBVar3;
  EVP_MD *md;
  ulong uVar4;
  BIO *pBVar5;
  long lVar6;
  int iVar7;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_2c;
  int local_20;
  
  if (*(uint *)&param_1->d1->w_msg_hdr < 0xe4) {
    uVar10 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar10 & 0x1000) == 0) {
      pdVar2 = param_1->d1;
      pBVar5 = SSL_get_wbio(param_1);
      lVar6 = BIO_ctrl(pBVar5,0x28,0,(void *)0x0);
      *(long *)&pdVar2->w_msg_hdr = lVar6;
      if (0xe3 < *(uint *)&param_1->d1->w_msg_hdr) goto LAB_080bc352;
      *(undefined4 *)&param_1->d1->w_msg_hdr = 0x5c0;
      pBVar5 = SSL_get_wbio(param_1);
      BIO_ctrl(pBVar5,0x2a,0x5c0,(void *)0x0);
    }
    if (*(uint *)&param_1->d1->w_msg_hdr < 0xe4) {
      OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu()");
    }
  }
LAB_080bc352:
  if (((param_1->init_off == 0) && (param_2 == 0x16)) &&
     (param_1->init_num != *(int *)&(param_1->d1->w_msg_hdr).seq + 0xc)) {
    OpenSSLDie("d1_both.c",0x116,
               "s->init_num == (int)s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH");
  }
  local_20 = 0;
  if (param_1->write_hash != (EVP_MD_CTX *)0x0) {
    md = EVP_MD_CTX_md(param_1->write_hash);
    local_20 = EVP_MD_size(md);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar4 = EVP_CIPHER_flags(param_1->enc_write_ctx->cipher), (uVar4 & 2) == 0)) {
    local_2c = 0;
  }
  else {
    local_2c = EVP_CIPHER_block_size(param_1->enc_write_ctx->cipher);
    local_2c = local_2c * 2;
  }
  iVar7 = param_1->init_num;
  uVar4 = 0;
  while( true ) {
    while( true ) {
      if (iVar7 == 0) {
        return 0;
      }
      iVar7 = *(int *)&param_1->d1->w_msg_hdr;
      pBVar5 = SSL_get_wbio(param_1);
      lVar6 = BIO_ctrl(pBVar5,0xd,0,(void *)0x0);
      uVar10 = ((-0xd - local_20) - local_2c) + (iVar7 - lVar6);
      if ((int)uVar10 < 0xd) {
        pBVar5 = SSL_get_wbio(param_1);
        lVar6 = BIO_ctrl(pBVar5,0xb,0,(void *)0x0);
        if (lVar6 < 1) {
          return lVar6;
        }
        uVar9 = param_1->init_num;
        uVar10 = ((*(int *)&param_1->d1->w_msg_hdr + -0xd) - local_20) - local_2c;
        uVar11 = uVar10;
        if ((int)uVar9 <= (int)uVar10) {
          uVar11 = uVar9;
        }
      }
      else {
        uVar9 = param_1->init_num;
        uVar11 = uVar10;
        if ((int)uVar9 <= (int)uVar10) {
          uVar11 = uVar9;
        }
      }
      if (param_2 == 0x16) {
        iVar7 = param_1->init_off;
        if (iVar7 != 0) {
          if (iVar7 < 0xd) {
            OpenSSLDie("d1_both.c",0x13e,"s->init_off > DTLS1_HM_HEADER_LENGTH");
            iVar7 = param_1->init_off;
            uVar9 = param_1->init_num;
          }
          uVar11 = uVar9 + 0xc;
          iVar7 = iVar7 + -0xc;
          param_1->init_off = iVar7;
          param_1->init_num = uVar11;
          if ((int)uVar10 < (int)uVar11) {
            uVar11 = uVar10;
          }
        }
        pdVar2 = param_1->d1;
        (pdVar2->w_msg_hdr).is_ccs = uVar11 - 0xc;
        pBVar3 = param_1->init_buf;
        (pdVar2->w_msg_hdr).frag_len = uVar4;
        pcVar8 = pBVar3->data + iVar7;
        *pcVar8 = *(char *)&(pdVar2->w_msg_hdr).msg_len;
        pcVar8[1] = (char)*(undefined2 *)&(pdVar2->w_msg_hdr).field_0xa;
        pcVar8[2] = (char)((uint)*(undefined4 *)&(pdVar2->w_msg_hdr).seq >> 8);
        pcVar8[3] = (char)*(undefined4 *)&(pdVar2->w_msg_hdr).seq;
        pcVar8[4] = *(char *)((int)&(pdVar2->w_msg_hdr).frag_off + 1);
        pcVar8[5] = (char)*(undefined2 *)&(pdVar2->w_msg_hdr).frag_off;
        pcVar8[6] = (char)*(undefined2 *)((int)&(pdVar2->w_msg_hdr).frag_len + 2);
        pcVar8[7] = (char)((pdVar2->w_msg_hdr).frag_len >> 8);
        pcVar8[8] = (char)(pdVar2->w_msg_hdr).frag_len;
        pcVar8[9] = (char)*(undefined2 *)((int)&(pdVar2->w_msg_hdr).is_ccs + 2);
        pcVar8[10] = (char)((pdVar2->w_msg_hdr).is_ccs >> 8);
        pcVar8[0xb] = (char)(pdVar2->w_msg_hdr).is_ccs;
        if (uVar11 < 0xc) {
          OpenSSLDie("d1_both.c",0x14d,"len >= DTLS1_HM_HEADER_LENGTH");
        }
      }
      uVar10 = dtls1_write_bytes(param_1,param_2,param_1->init_buf->data + param_1->init_off,uVar11)
      ;
      if (-1 < (int)uVar10) break;
      pBVar5 = SSL_get_wbio(param_1);
      lVar6 = BIO_ctrl(pBVar5,0x2b,0,(void *)0x0);
      if (lVar6 < 1) {
        return -1;
      }
      pdVar2 = param_1->d1;
      pBVar5 = SSL_get_wbio(param_1);
      lVar6 = BIO_ctrl(pBVar5,0x28,0,(void *)0x0);
      iVar7 = param_1->init_num;
      *(long *)&pdVar2->w_msg_hdr = lVar6;
    }
    if (uVar11 != uVar10) {
      OpenSSLDie("d1_both.c",0x166,"len == (unsigned int)ret");
    }
    if ((param_2 == 0x16) && (pdVar2 = param_1->d1, pdVar2->change_cipher_spec_ok == 0)) {
      pcVar8 = param_1->init_buf->data + param_1->init_off;
      if ((uVar4 == 0) && (param_1->version != 0x100)) {
        *pcVar8 = *(char *)&(pdVar2->w_msg_hdr).msg_len;
        pcVar8[1] = (char)*(undefined2 *)&(pdVar2->w_msg_hdr).field_0xa;
        pcVar8[2] = (char)((uint)*(undefined4 *)&(pdVar2->w_msg_hdr).seq >> 8);
        pcVar8[3] = (char)*(undefined4 *)&(pdVar2->w_msg_hdr).seq;
        pcVar8[4] = *(char *)((int)&(pdVar2->w_msg_hdr).frag_off + 1);
        uVar1 = *(undefined2 *)&(pdVar2->w_msg_hdr).frag_off;
        pcVar8[6] = '\0';
        pcVar8[7] = '\0';
        pcVar8[8] = '\0';
        pcVar8[5] = (char)uVar1;
        pcVar8[9] = (char)*(undefined2 *)&(pdVar2->w_msg_hdr).field_0xa;
        pcVar8[10] = (char)((uint)*(undefined4 *)&(pdVar2->w_msg_hdr).seq >> 8);
        pcVar8[0xb] = (char)*(undefined4 *)&(pdVar2->w_msg_hdr).seq;
        uVar11 = uVar10;
      }
      else {
        pcVar8 = pcVar8 + 0xc;
        uVar11 = uVar10 - 0xc;
      }
      ssl3_finish_mac(param_1,pcVar8,uVar11);
      uVar11 = param_1->init_num;
    }
    else {
      uVar11 = param_1->init_num;
    }
    if (uVar10 == uVar11) break;
    param_1->init_off = param_1->init_off + uVar10;
    iVar7 = uVar11 - uVar10;
    uVar4 = (uVar4 - 0xc) + uVar10;
    param_1->init_num = iVar7;
  }
  if (param_1->msg_callback != (_func_3150 *)0x0) {
    (*param_1->msg_callback)
              (1,param_1->version,param_2,param_1->init_buf->data,uVar10 + param_1->init_off,param_1
               ,param_1->msg_callback_arg);
  }
  param_1->init_off = 0;
  param_1->init_num = 0;
  return 1;
}

