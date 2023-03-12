
int dtls1_buffer_message(int *param_1,int param_2)

{
  undefined uVar1;
  undefined2 uVar2;
  undefined *puVar3;
  undefined *ptr;
  void *pvVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint uVar7;
  BIO *pBVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  SSL *ssl;
  char *pcVar12;
  undefined *puVar13;
  int iVar14;
  undefined4 *puVar15;
  int iVar16;
  dtls1_state_st *pdVar17;
  dtls1_state_st *pdVar18;
  int iVar19;
  undefined4 local_2c;
  uint local_28;
  SSL *local_24;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  if (param_1[0x12] != 0) {
    OpenSSLDie("d1_both.c",0x493,"s->init_off == 0");
  }
  iVar19 = param_1[0x11];
  ptr = (undefined *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
  if (ptr == (undefined *)0x0) {
LAB_004a75d8:
    trap(0);
LAB_004a75e0:
    iVar19 = param_1[0x17];
    iVar14 = *(int *)(iVar19 + 0x260);
    if (iVar14 + 0xc != param_1[0x11]) {
      OpenSSLDie("d1_both.c",0x4a1,
                 "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num");
      iVar19 = param_1[0x17];
      iVar14 = *(int *)(iVar19 + 0x260);
    }
  }
  else {
    pvVar4 = (void *)0x0;
    if ((iVar19 != 0) && (pvVar4 = CRYPTO_malloc(iVar19,"d1_both.c",0xb9), pvVar4 == (void *)0x0)) {
      CRYPTO_free(ptr);
      goto LAB_004a75d8;
    }
    puVar5 = PTR_memcpy_006aabf4;
    iVar19 = param_1[0xf];
    iVar14 = param_1[0x11];
    *(void **)(ptr + 0x2c) = pvVar4;
    *(undefined4 *)(ptr + 0x30) = 0;
    (*(code *)puVar5)(pvVar4,*(undefined4 *)(iVar19 + 4),iVar14);
    if (param_2 == 0) goto LAB_004a75e0;
    iVar19 = param_1[0x17];
    iVar10 = 1;
    if (*param_1 != 0xfeff) {
      iVar10 = 3;
    }
    iVar14 = *(int *)(iVar19 + 0x260);
    if (iVar10 + iVar14 != param_1[0x11]) {
      OpenSSLDie("d1_both.c",0x49c,
                 "s->d1->w_msg_hdr.msg_len + ((s->version==DTLS1_VERSION)?DTLS1_CCS_HEADER_LENGTH:3) == (unsigned int)s->init_num"
                );
      iVar19 = param_1[0x17];
      iVar14 = *(int *)(iVar19 + 0x260);
    }
  }
  uVar11 = *(ushort *)(iVar19 + 0x264);
  puVar15 = &local_2c;
  *(int *)(ptr + 4) = iVar14;
  puVar5 = PTR_pitem_new_006a93bc;
  *(ushort *)(ptr + 8) = uVar11;
  uVar1 = *(undefined *)(iVar19 + 0x25c);
  *(undefined4 *)(ptr + 0xc) = 0;
  *ptr = uVar1;
  iVar16 = param_1[0x23];
  iVar10 = param_1[0x24];
  iVar14 = param_1[0x25];
  iVar19 = param_1[0x30];
  uVar2 = *(undefined2 *)(param_1[0x17] + 0x20a);
  *(undefined4 *)(ptr + 0x10) = *(undefined4 *)(param_1[0x17] + 0x260);
  *(int *)(ptr + 0x14) = param_2;
  *(int *)(ptr + 0x18) = iVar16;
  *(int *)(ptr + 0x1c) = iVar10;
  *(int *)(ptr + 0x20) = iVar14;
  *(int *)(ptr + 0x24) = iVar19;
  *(undefined2 *)(ptr + 0x28) = uVar2;
  local_2c = 0;
  local_28 = (uint)uVar11 * 2 - param_2 & 0xffff;
  puVar13 = ptr;
  puVar5 = (undefined *)(*(code *)puVar5)(puVar15);
  if (puVar5 == (undefined *)0x0) {
    puVar5 = puVar13;
    if (*(int *)(ptr + 0x14) != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a93f8)(*(undefined4 *)(ptr + 0x18));
      (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(*(undefined4 *)(ptr + 0x1c));
      puVar5 = puVar13;
    }
    if (*(void **)(ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 0x2c));
    }
    if (*(void **)(ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 0x30));
    }
    CRYPTO_free(ptr);
    iVar19 = 0;
  }
  else {
    (*(code *)PTR_pqueue_insert_006a93c0)(*(undefined4 *)(param_1[0x17] + 0x248));
    iVar19 = 1;
  }
  if (local_24 == *(SSL **)puVar3) {
    return iVar19;
  }
  ssl = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((undefined *)ssl->state == puVar5) {
    pcVar12 = ssl->init_buf->data;
    *pcVar12 = '\x01';
    pdVar17 = ssl->d1;
    iVar19 = ssl->version;
    uVar11 = pdVar17->next_handshake_write_seq;
    pdVar17->handshake_write_seq = uVar11;
    ssl->init_num = 1;
    if (iVar19 == 0x100) {
      pdVar17->next_handshake_write_seq = uVar11 + 1;
      pcVar12[1] = (char)(uVar11 >> 8);
      pcVar12[2] = (char)ssl->d1->handshake_write_seq;
      pdVar17 = ssl->d1;
      uVar11 = pdVar17->handshake_write_seq;
      ssl->init_num = ssl->init_num + 2;
    }
    ssl->init_off = 0;
    *(ushort *)&(pdVar17->w_msg_hdr).frag_off = uVar11;
    *(undefined4 *)&(pdVar17->w_msg_hdr).seq = 0;
    (pdVar17->w_msg_hdr).frag_len = 0;
    *(undefined *)&(pdVar17->w_msg_hdr).msg_len = 1;
    (pdVar17->w_msg_hdr).is_ccs = 0;
    dtls1_buffer_message(ssl,1);
    uVar7 = *(uint *)&ssl->d1->w_msg_hdr;
    ssl->state = (int)puVar15;
    if (uVar7 < 0xe4) goto LAB_004a79c0;
LAB_004a770c:
    iVar19 = 0;
    if (ssl->write_hash == (EVP_MD_CTX *)0x0) goto LAB_004a773c;
  }
  else {
    if (0xe3 < *(uint *)&ssl->d1->w_msg_hdr) goto LAB_004a770c;
LAB_004a79c0:
    uVar7 = SSL_ctrl(ssl,0x20,0,(void *)0x0);
    if ((uVar7 & 0x1000) == 0) {
      pdVar18 = ssl->d1;
      pBVar8 = SSL_get_wbio(ssl);
      uVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0x28,0,0);
      pdVar17 = ssl->d1;
      *(undefined4 *)&pdVar18->w_msg_hdr = uVar6;
      if (0xe3 < *(uint *)&pdVar17->w_msg_hdr) goto LAB_004a770c;
      *(undefined4 *)&pdVar17->w_msg_hdr = 0x5c0;
      pBVar8 = SSL_get_wbio(ssl);
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0x2a,*(undefined4 *)&ssl->d1->w_msg_hdr,0);
    }
    if (0xe3 < *(uint *)&ssl->d1->w_msg_hdr) goto LAB_004a770c;
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu()");
    if (ssl->write_hash == (EVP_MD_CTX *)0x0) {
      iVar19 = 0;
      goto LAB_004a773c;
    }
  }
  uVar6 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
  iVar19 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar6);
LAB_004a773c:
  if ((ssl->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar7 = (*(code *)PTR_EVP_CIPHER_flags_006a9270)(ssl->enc_write_ctx->cipher), (uVar7 & 2) == 0
     )) {
    iVar14 = 0;
  }
  else {
    iVar14 = (*(code *)PTR_EVP_CIPHER_block_size_006a921c)(ssl->enc_write_ctx->cipher);
    iVar14 = iVar14 << 1;
  }
  iVar10 = ssl->init_num;
  while( true ) {
    while( true ) {
      if (iVar10 == 0) {
        return 0;
      }
      iVar16 = *(int *)&ssl->d1->w_msg_hdr;
      pBVar8 = SSL_get_wbio(ssl);
      iVar10 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0xd,0,0);
      iVar10 = ((-0xd - iVar19) - iVar14) + (iVar16 - iVar10);
      if (iVar10 < 0xd) {
        pBVar8 = SSL_get_wbio(ssl);
        iVar10 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0xb,0,0);
        if (iVar10 < 1) {
          return iVar10;
        }
        iVar10 = ((*(int *)&ssl->d1->w_msg_hdr + -0xd) - iVar19) - iVar14;
      }
      iVar16 = ssl->init_num;
      if (iVar10 < ssl->init_num) {
        iVar16 = iVar10;
      }
      iVar9 = dtls1_write_bytes(ssl,0x14,ssl->init_buf->data + ssl->init_off,iVar16);
      if (-1 < iVar9) break;
      pBVar8 = SSL_get_wbio(ssl);
      iVar10 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0x2b,0,0);
      if (iVar10 < 1) {
        return -1;
      }
      pdVar17 = ssl->d1;
      pBVar8 = SSL_get_wbio(ssl);
      uVar6 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0x28,0,0);
      iVar10 = ssl->init_num;
      *(undefined4 *)&pdVar17->w_msg_hdr = uVar6;
    }
    if (iVar9 != iVar16) {
      OpenSSLDie("d1_both.c",0x166,"len == (unsigned int)ret");
    }
    iVar10 = ssl->init_num - iVar9;
    if (iVar9 == ssl->init_num) break;
    ssl->init_num = iVar10;
    ssl->init_off = ssl->init_off + iVar9;
  }
  if (ssl->msg_callback != (_func_3150 *)0x0) {
    (*ssl->msg_callback)
              (1,ssl->version,0x14,ssl->init_buf->data,iVar9 + ssl->init_off,ssl,
               ssl->msg_callback_arg);
  }
  ssl->init_off = 0;
  ssl->init_num = 0;
  return 1;
}

