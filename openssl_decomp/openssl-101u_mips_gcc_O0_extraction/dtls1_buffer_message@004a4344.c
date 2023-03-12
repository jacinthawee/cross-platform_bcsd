
int dtls1_buffer_message(int *param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  char *ptr;
  void *pvVar6;
  BIO *pBVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  ushort uVar11;
  int iVar12;
  SSL *s;
  char *pcVar13;
  char *pcVar14;
  dtls1_state_st *pdVar15;
  undefined4 *puVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  undefined4 local_2c;
  uint local_28;
  SSL *local_24;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  if (param_1[0x12] != 0) {
    OpenSSLDie("d1_both.c",0x501,"s->init_off == 0");
  }
  puVar16 = (undefined4 *)0xb5;
  pcVar13 = "d1_both.c";
  iVar20 = param_1[0x11];
  ptr = (char *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
  if (ptr == (char *)0x0) {
LAB_004a4578:
    iVar20 = 0;
    goto LAB_004a44c0;
  }
  pvVar6 = (void *)0x0;
  if (iVar20 != 0) {
    puVar16 = (undefined4 *)0xba;
    pcVar13 = "d1_both.c";
    pvVar6 = CRYPTO_malloc(iVar20,"d1_both.c",0xba);
    if (pvVar6 == (void *)0x0) {
      CRYPTO_free(ptr);
      goto LAB_004a4578;
    }
  }
  puVar4 = PTR_memcpy_006a9aec;
  iVar20 = param_1[0xf];
  iVar17 = param_1[0x11];
  *(void **)(ptr + 0x2c) = pvVar6;
  *(undefined4 *)(ptr + 0x30) = 0;
  (*(code *)puVar4)(pvVar6,*(undefined4 *)(iVar20 + 4),iVar17);
  if (param_2 == 0) {
    iVar20 = param_1[0x17];
    iVar12 = *(int *)(iVar20 + 0x264);
    if (iVar12 + 0xc != param_1[0x11]) {
      iVar20 = 0x510;
      pcVar13 = "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num";
LAB_004a4408:
      OpenSSLDie("d1_both.c",iVar20,pcVar13);
      iVar20 = param_1[0x17];
      iVar12 = *(int *)(iVar20 + 0x264);
    }
  }
  else {
    iVar20 = param_1[0x17];
    iVar17 = 1;
    if (*param_1 != 0xfeff) {
      iVar17 = 3;
    }
    iVar12 = *(int *)(iVar20 + 0x264);
    if (iVar17 + iVar12 != param_1[0x11]) {
      iVar20 = 0x50d;
      pcVar13 = 
      "s->d1->w_msg_hdr.msg_len + ((s->version == DTLS1_VERSION) ? DTLS1_CCS_HEADER_LENGTH : 3) == (unsigned int)s->init_num"
      ;
      goto LAB_004a4408;
    }
  }
  uVar11 = *(ushort *)(iVar20 + 0x268);
  puVar16 = &local_2c;
  *(int *)(ptr + 4) = iVar12;
  puVar4 = PTR_pitem_new_006a829c;
  *(ushort *)(ptr + 8) = uVar11;
  cVar1 = *(char *)(iVar20 + 0x260);
  *(undefined4 *)(ptr + 0xc) = 0;
  *ptr = cVar1;
  iVar18 = param_1[0x23];
  iVar12 = param_1[0x24];
  iVar17 = param_1[0x25];
  iVar20 = param_1[0x30];
  uVar2 = *(undefined2 *)(param_1[0x17] + 0x20a);
  *(undefined4 *)(ptr + 0x10) = *(undefined4 *)(param_1[0x17] + 0x264);
  *(int *)(ptr + 0x14) = param_2;
  *(int *)(ptr + 0x18) = iVar18;
  *(int *)(ptr + 0x1c) = iVar12;
  *(int *)(ptr + 0x20) = iVar17;
  *(int *)(ptr + 0x24) = iVar20;
  *(undefined2 *)(ptr + 0x28) = uVar2;
  local_2c = 0;
  local_28 = (uint)uVar11 * 2 - param_2 & 0xffff;
  pcVar14 = ptr;
  pcVar13 = (char *)(*(code *)puVar4)(puVar16);
  if (pcVar13 == (char *)0x0) {
    pcVar13 = pcVar14;
    if (*(int *)(ptr + 0x14) != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a82dc)(*(undefined4 *)(ptr + 0x18));
      (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(*(undefined4 *)(ptr + 0x1c));
      pcVar13 = pcVar14;
    }
    if (*(void **)(ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 0x2c));
    }
    if (*(void **)(ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 0x30));
    }
    CRYPTO_free(ptr);
    iVar20 = 0;
  }
  else {
    (*(code *)PTR_pqueue_insert_006a82a0)(*(undefined4 *)(param_1[0x17] + 0x248));
    iVar20 = 1;
  }
LAB_004a44c0:
  if (local_24 == *(SSL **)puVar5) {
    return iVar20;
  }
  s = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((char *)s->state == pcVar13) {
    pcVar13 = s->init_buf->data;
    *pcVar13 = '\x01';
    pdVar15 = s->d1;
    iVar20 = s->version;
    uVar11 = pdVar15->next_handshake_write_seq;
    pdVar15->handshake_write_seq = uVar11;
    s->init_num = 1;
    if (iVar20 == 0x100) {
      pdVar15->next_handshake_write_seq = uVar11 + 1;
      pcVar13[1] = (char)(uVar11 >> 8);
      pcVar13[2] = (char)s->d1->handshake_write_seq;
      pdVar15 = s->d1;
      uVar11 = pdVar15->handshake_write_seq;
      s->init_num = s->init_num + 2;
    }
    s->init_off = 0;
    *(ushort *)&(pdVar15->w_msg_hdr).frag_len = uVar11;
    (pdVar15->w_msg_hdr).frag_off = 0;
    (pdVar15->w_msg_hdr).is_ccs = 0;
    *(undefined *)&(pdVar15->w_msg_hdr).seq = 1;
    (pdVar15->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    dtls1_buffer_message(s,1);
    s->state = (int)puVar16;
  }
  iVar20 = dtls1_query_mtu(s);
  if (iVar20 == 0) {
    return -1;
  }
  uVar19 = (s->d1->w_msg_hdr).msg_len;
  pBVar7 = SSL_get_wbio(s);
  iVar20 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar7,0x31,0,0);
  if (uVar19 < 0x100U - iVar20) {
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu(s)");
  }
  if (s->write_hash == (EVP_MD_CTX *)0x0) {
    iVar20 = 0;
  }
  else {
    uVar8 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
    iVar20 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar8);
  }
  if ((s->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar19 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)(s->enc_write_ctx->cipher), (uVar19 & 2) == 0
     )) {
    iVar17 = 0;
  }
  else {
    iVar17 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(s->enc_write_ctx->cipher);
    iVar17 = iVar17 << 1;
  }
  iVar12 = s->init_num;
  uVar19 = 0;
  s->rwstate = 1;
  bVar3 = true;
  while( true ) {
    while( true ) {
      if (iVar12 < 1) {
        return 0;
      }
      pBVar7 = SSL_get_wbio(s);
      iVar12 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar7,0xd,0,0);
      uVar9 = iVar20 + 0xd + iVar17 + iVar12;
      uVar10 = (s->d1->w_msg_hdr).msg_len;
      if ((uVar9 < uVar10) && (uVar10 = uVar10 - uVar9, 0xc < uVar10)) {
        uVar9 = s->init_num;
        if (uVar10 < (uint)s->init_num) {
          uVar9 = uVar10;
        }
      }
      else {
        pBVar7 = SSL_get_wbio(s);
        iVar12 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar7,0xb,0,0);
        if (iVar12 < 1) {
          s->rwstate = 2;
          return iVar12;
        }
        uVar9 = (s->d1->w_msg_hdr).msg_len;
        if (uVar9 <= iVar20 + iVar17 + 0x19U) {
          return -1;
        }
        uVar10 = (uVar9 - 0xd) - (iVar20 + iVar17);
        uVar9 = s->init_num;
        if (uVar10 < (uint)s->init_num) {
          uVar9 = uVar10;
        }
      }
      if ((int)uVar9 < 0) {
        uVar9 = 0x7fffffff;
      }
      uVar10 = dtls1_write_bytes(s,0x14,s->init_buf->data + s->init_off,uVar9);
      if ((int)uVar10 < 0) break;
      if (uVar9 != uVar10) {
        OpenSSLDie("d1_both.c",0x19f,"len == (unsigned int)ret");
      }
      if (uVar10 == s->init_num) {
        if (s->msg_callback != (_func_3150 *)0x0) {
          (*s->msg_callback)(1,s->version,0x14,s->init_buf->data,uVar10 + s->init_off,s,
                             s->msg_callback_arg);
        }
        s->init_off = 0;
        s->init_num = 0;
        return 1;
      }
      pdVar15 = s->d1;
      iVar12 = s->init_num - uVar10;
      uVar19 = uVar19 + (uVar10 - 0xc);
      s->init_num = iVar12;
      s->init_off = s->init_off + uVar10;
      (pdVar15->w_msg_hdr).is_ccs = uVar19;
      (pdVar15->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
    if (!bVar3) {
      return -1;
    }
    pBVar7 = SSL_get_wbio(s);
    iVar12 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar7,0x2b,0,0);
    if (iVar12 < 1) break;
    uVar9 = SSL_ctrl(s,0x20,0,(void *)0x0);
    if ((uVar9 & 0x1000) != 0) {
      return -1;
    }
    iVar12 = dtls1_query_mtu(s);
    if (iVar12 == 0) {
      return -1;
    }
    iVar12 = s->init_num;
    bVar3 = false;
  }
  return -1;
}

