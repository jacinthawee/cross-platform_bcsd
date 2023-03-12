
int dtls1_do_write(SSL *param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  BIO *pBVar5;
  int iVar6;
  uint uVar7;
  dtls1_state_st *pdVar8;
  char *pcVar9;
  ulong uVar10;
  dtls1_state_st *pdVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  
  if (*(uint *)&param_1->d1->w_msg_hdr < 0xe4) {
    uVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar4 & 0x1000) == 0) {
      pdVar11 = param_1->d1;
      pBVar5 = SSL_get_wbio(param_1);
      uVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar5,0x28,0,0);
      pdVar8 = param_1->d1;
      *(undefined4 *)&pdVar11->w_msg_hdr = uVar2;
      if (0xe3 < *(uint *)&pdVar8->w_msg_hdr) goto LAB_004a5f68;
      *(undefined4 *)&pdVar8->w_msg_hdr = 0x5c0;
      pBVar5 = SSL_get_wbio(param_1);
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar5,0x2a,*(undefined4 *)&param_1->d1->w_msg_hdr,0);
    }
    if (*(uint *)&param_1->d1->w_msg_hdr < 0xe4) {
      OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu()");
    }
  }
LAB_004a5f68:
  if (((param_1->init_off == 0) && (param_2 == 0x16)) &&
     (param_1->init_num != *(int *)&(param_1->d1->w_msg_hdr).seq + 0xc)) {
    OpenSSLDie("d1_both.c",0x116,
               "s->init_num == (int)s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH");
  }
  if (param_1->write_hash == (EVP_MD_CTX *)0x0) {
    iVar3 = 0;
  }
  else {
    uVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
    iVar3 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar2);
  }
  if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar4 = (*(code *)PTR_EVP_CIPHER_flags_006a9270)(param_1->enc_write_ctx->cipher),
     (uVar4 & 2) == 0)) {
    iVar12 = 0;
  }
  else {
    iVar12 = (*(code *)PTR_EVP_CIPHER_block_size_006a921c)(param_1->enc_write_ctx->cipher);
    iVar12 = iVar12 << 1;
  }
  iVar6 = param_1->init_num;
  uVar10 = 0;
  while( true ) {
    while( true ) {
      if (iVar6 == 0) {
        return 0;
      }
      iVar13 = *(int *)&param_1->d1->w_msg_hdr;
      pBVar5 = SSL_get_wbio(param_1);
      iVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar5,0xd,0,0);
      uVar4 = ((-0xd - iVar3) - iVar12) + (iVar13 - iVar6);
      if ((int)uVar4 < 0xd) {
        pBVar5 = SSL_get_wbio(param_1);
        iVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar5,0xb,0,0);
        if (iVar6 < 1) {
          return iVar6;
        }
        uVar7 = param_1->init_num;
        uVar4 = ((*(int *)&param_1->d1->w_msg_hdr + -0xd) - iVar3) - iVar12;
        uVar14 = uVar4;
        if ((int)uVar7 <= (int)uVar4) {
          uVar14 = uVar7;
        }
      }
      else {
        uVar7 = param_1->init_num;
        uVar14 = uVar4;
        if ((int)uVar7 <= (int)uVar4) {
          uVar14 = uVar7;
        }
      }
      if (param_2 == 0x16) {
        iVar6 = param_1->init_off;
        if (iVar6 != 0) {
          if (iVar6 < 0xd) {
            OpenSSLDie("d1_both.c",0x13e,"s->init_off > DTLS1_HM_HEADER_LENGTH");
            iVar6 = param_1->init_off;
            uVar7 = param_1->init_num;
          }
          uVar7 = uVar7 + 0xc;
          iVar6 = iVar6 + -0xc;
          uVar14 = uVar4;
          if ((int)uVar7 <= (int)uVar4) {
            uVar14 = uVar7;
          }
          param_1->init_num = uVar7;
          param_1->init_off = iVar6;
        }
        pdVar8 = param_1->d1;
        pcVar9 = param_1->init_buf->data;
        (pdVar8->w_msg_hdr).frag_len = uVar10;
        pcVar9 = pcVar9 + iVar6;
        (pdVar8->w_msg_hdr).is_ccs = uVar14 - 0xc;
        *pcVar9 = *(char *)&(pdVar8->w_msg_hdr).msg_len;
        pcVar9[1] = (char)(pdVar8->w_msg_hdr).seq;
        pcVar9[2] = (char)((uint)*(undefined4 *)&(pdVar8->w_msg_hdr).seq >> 8);
        pcVar9[3] = (char)*(undefined4 *)&(pdVar8->w_msg_hdr).seq;
        pcVar9[4] = (char)((ushort)*(undefined2 *)&(pdVar8->w_msg_hdr).frag_off >> 8);
        pcVar9[5] = (char)*(undefined2 *)&(pdVar8->w_msg_hdr).frag_off;
        pcVar9[6] = (char)*(undefined2 *)&(pdVar8->w_msg_hdr).frag_len;
        pcVar9[7] = (char)((pdVar8->w_msg_hdr).frag_len >> 8);
        pcVar9[8] = (char)(pdVar8->w_msg_hdr).frag_len;
        pcVar9[9] = (char)*(undefined2 *)&(pdVar8->w_msg_hdr).is_ccs;
        pcVar9[10] = (char)((pdVar8->w_msg_hdr).is_ccs >> 8);
        pcVar9[0xb] = (char)(pdVar8->w_msg_hdr).is_ccs;
        if (uVar14 < 0xc) {
          OpenSSLDie("d1_both.c",0x14d,"len >= DTLS1_HM_HEADER_LENGTH");
        }
      }
      uVar4 = dtls1_write_bytes(param_1,param_2,param_1->init_buf->data + param_1->init_off,uVar14);
      if (-1 < (int)uVar4) break;
      pBVar5 = SSL_get_wbio(param_1);
      iVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar5,0x2b,0,0);
      if (iVar6 < 1) {
        return -1;
      }
      pdVar8 = param_1->d1;
      pBVar5 = SSL_get_wbio(param_1);
      uVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar5,0x28,0,0);
      iVar6 = param_1->init_num;
      *(undefined4 *)&pdVar8->w_msg_hdr = uVar2;
    }
    if (uVar14 != uVar4) {
      OpenSSLDie("d1_both.c",0x166,"len == (unsigned int)ret");
    }
    if ((param_2 == 0x16) && (pdVar8 = param_1->d1, pdVar8->change_cipher_spec_ok == 0)) {
      pcVar9 = param_1->init_buf->data + param_1->init_off;
      if ((uVar10 == 0) && (param_1->version != 0x100)) {
        *pcVar9 = *(char *)&(pdVar8->w_msg_hdr).msg_len;
        pcVar9[1] = (char)(pdVar8->w_msg_hdr).seq;
        pcVar9[2] = (char)((uint)*(undefined4 *)&(pdVar8->w_msg_hdr).seq >> 8);
        pcVar9[3] = (char)*(undefined4 *)&(pdVar8->w_msg_hdr).seq;
        pcVar9[4] = (char)((ushort)*(undefined2 *)&(pdVar8->w_msg_hdr).frag_off >> 8);
        uVar1 = *(undefined2 *)&(pdVar8->w_msg_hdr).frag_off;
        pcVar9[6] = '\0';
        pcVar9[7] = '\0';
        pcVar9[8] = '\0';
        pcVar9[5] = (char)uVar1;
        pcVar9[9] = (char)(pdVar8->w_msg_hdr).seq;
        pcVar9[10] = (char)((uint)*(undefined4 *)&(pdVar8->w_msg_hdr).seq >> 8);
        pcVar9[0xb] = (char)*(undefined4 *)&(pdVar8->w_msg_hdr).seq;
        uVar7 = uVar4;
      }
      else {
        pcVar9 = pcVar9 + 0xc;
        uVar7 = uVar4 - 0xc;
      }
      ssl3_finish_mac(param_1,pcVar9,uVar7);
      uVar7 = param_1->init_num;
    }
    else {
      uVar7 = param_1->init_num;
    }
    if (uVar4 == uVar7) break;
    iVar6 = uVar7 - uVar4;
    param_1->init_num = iVar6;
    uVar10 = uVar10 + (uVar4 - 0xc);
    param_1->init_off = param_1->init_off + uVar4;
  }
  if (param_1->msg_callback != (_func_3150 *)0x0) {
    (*param_1->msg_callback)
              (1,param_1->version,param_2,param_1->init_buf->data,uVar4 + param_1->init_off,param_1,
               param_1->msg_callback_arg);
  }
  param_1->init_off = 0;
  param_1->init_num = 0;
  return 1;
}

