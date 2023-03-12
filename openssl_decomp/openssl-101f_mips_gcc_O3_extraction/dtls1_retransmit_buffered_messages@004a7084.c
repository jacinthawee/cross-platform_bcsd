
int dtls1_retransmit_buffered_messages(SSL *param_1,int param_2)

{
  undefined uVar1;
  undefined2 uVar2;
  ushort uVar3;
  uint uVar4;
  uchar *puVar5;
  undefined *puVar6;
  int iVar7;
  BIO *pBVar8;
  dtls1_state_st *pdVar9;
  ssl3_state_st *psVar10;
  undefined *ptr;
  void *pvVar11;
  undefined *puVar12;
  int iVar13;
  int iVar14;
  dtls1_state_st *pdVar15;
  int iVar16;
  ushort uVar17;
  int *piVar18;
  SSL *ssl;
  char *pcVar19;
  SSL_SESSION *pSVar20;
  undefined4 uVar21;
  undefined *puVar22;
  undefined4 *puVar23;
  uint uVar24;
  COMP_CTX *pCVar25;
  int iVar26;
  EVP_MD_CTX *pEVar27;
  EVP_CIPHER_CTX *pEVar28;
  EVP_MD_CTX *unaff_s2;
  SSL_SESSION *unaff_s3;
  COMP_CTX *unaff_s4;
  char *unaff_s5;
  uint uVar29;
  uint uVar30;
  undefined4 uStack_9c;
  uint uStack_98;
  SSL *pSStack_94;
  SSL *pSStack_8c;
  undefined4 *puStack_88;
  EVP_MD_CTX *pEStack_84;
  SSL_SESSION *pSStack_80;
  COMP_CTX *pCStack_7c;
  char *pcStack_78;
  code *pcStack_74;
  undefined *local_60;
  EVP_CIPHER_CTX *local_54;
  undefined4 *local_50;
  int **local_4c;
  undefined4 *local_48;
  char *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_34;
  uint local_30;
  int *local_2c;
  
  puStack_88 = &local_40;
  local_4c = (int **)PTR___stack_chk_guard_006aabf0;
  local_60 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  local_50 = puStack_88;
  local_40 = (*(code *)PTR_pqueue_iterator_006a9404)(param_1->d1->sent_messages);
  iVar7 = (**(code **)(local_60 + -0x6ad8))(puStack_88);
  if (iVar7 != 0) {
    local_48 = *(undefined4 **)(local_60 + -0x52e0);
    unaff_s5 = "s\n";
    local_44 = "retransmit:  message %d non-existant\n";
    do {
      local_3c = 0;
      puStack_88 = (undefined4 *)
                   ((uint)*(ushort *)(*(int *)(iVar7 + 8) + 8) * 2 -
                   *(int *)(*(int *)(iVar7 + 8) + 0x14));
      local_38 = (uint)puStack_88 & 0xffff;
      iVar7 = (**(code **)(local_60 + -0x6aec))(param_1->d1->sent_messages,&local_3c);
      if (iVar7 == 0) {
        param_2 = 1;
        (**(code **)(local_60 + -0x5454))(*local_48,1,local_44,(uint)puStack_88 & 0xffff);
      }
      else {
        puStack_88 = *(undefined4 **)(iVar7 + 8);
        iVar7 = 0xc;
        if (puStack_88[5] != 0) {
          iVar7 = 1;
        }
        (**(code **)(local_60 + -0x52ec))
                  (param_1->init_buf->data,puStack_88[0xb],iVar7 + puStack_88[1]);
        iVar14 = puStack_88[1];
        uVar2 = *(undefined2 *)(puStack_88 + 2);
        uVar29 = puStack_88[4];
        pdVar9 = param_1->d1;
        param_1->init_num = iVar7 + iVar14;
        uVar1 = *(undefined *)puStack_88;
        *(int *)&(pdVar9->w_msg_hdr).seq = iVar14;
        *(undefined2 *)&(pdVar9->w_msg_hdr).frag_off = uVar2;
        (pdVar9->w_msg_hdr).frag_len = 0;
        *(undefined *)&(pdVar9->w_msg_hdr).msg_len = uVar1;
        pdVar15 = param_1->d1;
        pEVar28 = (EVP_CIPHER_CTX *)puStack_88[6];
        pEVar27 = (EVP_MD_CTX *)puStack_88[7];
        pCVar25 = (COMP_CTX *)puStack_88[8];
        uVar17 = pdVar15->w_epoch;
        pSVar20 = (SSL_SESSION *)puStack_88[9];
        uVar3 = *(ushort *)(puStack_88 + 10);
        uVar30 = uVar17 - 1;
        local_54 = param_1->enc_write_ctx;
        unaff_s2 = param_1->write_hash;
        unaff_s4 = param_1->compress;
        unaff_s3 = param_1->session;
        (pdVar9->w_msg_hdr).is_ccs = uVar29;
        pdVar15->change_cipher_spec_ok = 1;
        param_1->enc_write_ctx = pEVar28;
        param_1->write_hash = pEVar27;
        param_1->compress = pCVar25;
        param_1->session = pSVar20;
        pdVar15->w_epoch = uVar3;
        if (uVar3 == uVar30) {
          psVar10 = param_1->s3;
          uVar21 = *(undefined4 *)(pdVar15->last_write_sequence + 4);
          uVar24 = *(uint *)pdVar15->last_write_sequence;
          uVar29 = (uint)(psVar10->write_sequence + 4) & 3;
          local_34 = *(undefined4 *)psVar10->write_sequence;
          uVar4 = (uint)(psVar10->write_sequence + 7) & 3;
          local_30 = (*(int *)(psVar10->write_sequence + 4 + -uVar29) << uVar29 * 8 |
                     (uint)pCVar25 & 0xffffffffU >> (4 - uVar29) * 8) & -1 << (uVar4 + 1) * 8 |
                     *(uint *)(psVar10->write_sequence + 7 + -uVar4) >> (3 - uVar4) * 8;
          uVar29 = (uint)psVar10->write_sequence & 3;
          puVar5 = psVar10->write_sequence + -uVar29;
          *(uint *)puVar5 = *(uint *)puVar5 & -1 << (4 - uVar29) * 8 | uVar24 >> uVar29 * 8;
          puVar5 = psVar10->write_sequence + 3;
          uVar29 = (uint)puVar5 & 3;
          *(uint *)(puVar5 + -uVar29) =
               *(uint *)(puVar5 + -uVar29) & 0xffffffffU >> (uVar29 + 1) * 8 |
               uVar24 << (3 - uVar29) * 8;
          *(undefined4 *)(psVar10->write_sequence + 4) = uVar21;
        }
        uVar21 = 0x16;
        if (puStack_88[5] != 0) {
          uVar21 = 0x14;
        }
        unaff_s5 = (char *)dtls1_do_write(param_1,uVar21);
        pdVar9 = param_1->d1;
        uVar3 = *(ushort *)(puStack_88 + 10);
        param_1->enc_write_ctx = local_54;
        param_1->write_hash = unaff_s2;
        param_1->compress = unaff_s4;
        param_1->session = unaff_s3;
        pdVar9->w_epoch = uVar17;
        if (uVar30 == uVar3) {
          uVar30 = *(uint *)param_1->s3->write_sequence;
          uVar21 = *(undefined4 *)(param_1->s3->write_sequence + 4);
          uVar29 = (uint)pdVar9->last_write_sequence & 3;
          puVar5 = pdVar9->last_write_sequence + -uVar29;
          *(uint *)puVar5 = *(uint *)puVar5 & -1 << (4 - uVar29) * 8 | uVar30 >> uVar29 * 8;
          puVar5 = pdVar9->last_write_sequence + 3;
          uVar29 = (uint)puVar5 & 3;
          *(uint *)(puVar5 + -uVar29) =
               *(uint *)(puVar5 + -uVar29) & 0xffffffffU >> (uVar29 + 1) * 8 |
               uVar30 << (3 - uVar29) * 8;
          *(undefined4 *)(pdVar9->last_write_sequence + 4) = uVar21;
          psVar10 = param_1->s3;
          *(undefined4 *)psVar10->write_sequence = local_34;
          *(uint *)(psVar10->write_sequence + 4) = local_30;
          pdVar9 = param_1->d1;
        }
        pdVar9->change_cipher_spec_ok = 0;
        pBVar8 = SSL_get_wbio(param_1);
        param_2 = 0xb;
        (**(code **)(local_60 + -0x7fc8))(pBVar8,0xb,0,0);
        if ((int)unaff_s5 < 1) {
          param_2 = 1;
          (**(code **)(local_60 + -0x5364))
                    ("dtls1_retransmit_message() failed\n",1,0x22,
                     **(undefined4 **)(local_60 + -0x52e0));
          iVar7 = -1;
          goto LAB_004a7354;
        }
      }
      iVar7 = (**(code **)(local_60 + -0x6ad8))(local_50);
    } while (iVar7 != 0);
  }
  iVar7 = 1;
LAB_004a7354:
  if (local_2c == *local_4c) {
    return iVar7;
  }
  pcStack_74 = dtls1_buffer_message;
  piVar18 = local_2c;
  (**(code **)(local_60 + -0x5328))();
  puVar6 = PTR___stack_chk_guard_006aabf0;
  pSStack_94 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  pSStack_8c = param_1;
  pEStack_84 = unaff_s2;
  pSStack_80 = unaff_s3;
  pCStack_7c = unaff_s4;
  pcStack_78 = unaff_s5;
  if (piVar18[0x12] != 0) {
    OpenSSLDie("d1_both.c",0x493,"s->init_off == 0");
  }
  iVar7 = piVar18[0x11];
  ptr = (undefined *)CRYPTO_malloc(0x34,"d1_both.c",0xb3);
  if (ptr == (undefined *)0x0) {
LAB_004a75d8:
    trap(0);
LAB_004a75e0:
    iVar7 = piVar18[0x17];
    iVar14 = *(int *)(iVar7 + 0x260);
    if (iVar14 + 0xc != piVar18[0x11]) {
      OpenSSLDie("d1_both.c",0x4a1,
                 "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num");
      iVar7 = piVar18[0x17];
      iVar14 = *(int *)(iVar7 + 0x260);
    }
  }
  else {
    pvVar11 = (void *)0x0;
    if ((iVar7 != 0) && (pvVar11 = CRYPTO_malloc(iVar7,"d1_both.c",0xb9), pvVar11 == (void *)0x0)) {
      CRYPTO_free(ptr);
      goto LAB_004a75d8;
    }
    puVar12 = PTR_memcpy_006aabf4;
    iVar7 = piVar18[0xf];
    iVar14 = piVar18[0x11];
    *(void **)(ptr + 0x2c) = pvVar11;
    *(undefined4 *)(ptr + 0x30) = 0;
    (*(code *)puVar12)(pvVar11,*(undefined4 *)(iVar7 + 4),iVar14);
    if (param_2 == 0) goto LAB_004a75e0;
    iVar7 = piVar18[0x17];
    iVar16 = 1;
    if (*piVar18 != 0xfeff) {
      iVar16 = 3;
    }
    iVar14 = *(int *)(iVar7 + 0x260);
    if (iVar16 + iVar14 != piVar18[0x11]) {
      OpenSSLDie("d1_both.c",0x49c,
                 "s->d1->w_msg_hdr.msg_len + ((s->version==DTLS1_VERSION)?DTLS1_CCS_HEADER_LENGTH:3) == (unsigned int)s->init_num"
                );
      iVar7 = piVar18[0x17];
      iVar14 = *(int *)(iVar7 + 0x260);
    }
  }
  uVar17 = *(ushort *)(iVar7 + 0x264);
  puVar23 = &uStack_9c;
  *(int *)(ptr + 4) = iVar14;
  puVar12 = PTR_pitem_new_006a93bc;
  *(ushort *)(ptr + 8) = uVar17;
  uVar1 = *(undefined *)(iVar7 + 0x25c);
  *(undefined4 *)(ptr + 0xc) = 0;
  *ptr = uVar1;
  iVar26 = piVar18[0x23];
  iVar16 = piVar18[0x24];
  iVar14 = piVar18[0x25];
  iVar7 = piVar18[0x30];
  uVar2 = *(undefined2 *)(piVar18[0x17] + 0x20a);
  *(undefined4 *)(ptr + 0x10) = *(undefined4 *)(piVar18[0x17] + 0x260);
  *(int *)(ptr + 0x14) = param_2;
  *(int *)(ptr + 0x18) = iVar26;
  *(int *)(ptr + 0x1c) = iVar16;
  *(int *)(ptr + 0x20) = iVar14;
  *(int *)(ptr + 0x24) = iVar7;
  *(undefined2 *)(ptr + 0x28) = uVar2;
  uStack_9c = 0;
  uStack_98 = (uint)uVar17 * 2 - param_2 & 0xffff;
  puVar22 = ptr;
  puVar12 = (undefined *)(*(code *)puVar12)(puVar23);
  if (puVar12 == (undefined *)0x0) {
    puVar12 = puVar22;
    if (*(int *)(ptr + 0x14) != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a93f8)(*(undefined4 *)(ptr + 0x18));
      (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(*(undefined4 *)(ptr + 0x1c));
      puVar12 = puVar22;
    }
    if (*(void **)(ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 0x2c));
    }
    if (*(void **)(ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 0x30));
    }
    CRYPTO_free(ptr);
    iVar7 = 0;
  }
  else {
    (*(code *)PTR_pqueue_insert_006a93c0)(*(undefined4 *)(piVar18[0x17] + 0x248));
    iVar7 = 1;
  }
  if (pSStack_94 == *(SSL **)puVar6) {
    return iVar7;
  }
  ssl = pSStack_94;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((undefined *)ssl->state == puVar12) {
    pcVar19 = ssl->init_buf->data;
    *pcVar19 = '\x01';
    pdVar9 = ssl->d1;
    iVar7 = ssl->version;
    uVar17 = pdVar9->next_handshake_write_seq;
    pdVar9->handshake_write_seq = uVar17;
    ssl->init_num = 1;
    if (iVar7 == 0x100) {
      pdVar9->next_handshake_write_seq = uVar17 + 1;
      pcVar19[1] = (char)(uVar17 >> 8);
      pcVar19[2] = (char)ssl->d1->handshake_write_seq;
      pdVar9 = ssl->d1;
      uVar17 = pdVar9->handshake_write_seq;
      ssl->init_num = ssl->init_num + 2;
    }
    ssl->init_off = 0;
    *(ushort *)&(pdVar9->w_msg_hdr).frag_off = uVar17;
    *(undefined4 *)&(pdVar9->w_msg_hdr).seq = 0;
    (pdVar9->w_msg_hdr).frag_len = 0;
    *(undefined *)&(pdVar9->w_msg_hdr).msg_len = 1;
    (pdVar9->w_msg_hdr).is_ccs = 0;
    dtls1_buffer_message(ssl,1);
    uVar29 = *(uint *)&ssl->d1->w_msg_hdr;
    ssl->state = (int)puVar23;
    if (uVar29 < 0xe4) goto LAB_004a79c0;
LAB_004a770c:
    iVar7 = 0;
    if (ssl->write_hash == (EVP_MD_CTX *)0x0) goto LAB_004a773c;
  }
  else {
    if (0xe3 < *(uint *)&ssl->d1->w_msg_hdr) goto LAB_004a770c;
LAB_004a79c0:
    uVar29 = SSL_ctrl(ssl,0x20,0,(void *)0x0);
    if ((uVar29 & 0x1000) == 0) {
      pdVar15 = ssl->d1;
      pBVar8 = SSL_get_wbio(ssl);
      uVar21 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0x28,0,0);
      pdVar9 = ssl->d1;
      *(undefined4 *)&pdVar15->w_msg_hdr = uVar21;
      if (0xe3 < *(uint *)&pdVar9->w_msg_hdr) goto LAB_004a770c;
      *(undefined4 *)&pdVar9->w_msg_hdr = 0x5c0;
      pBVar8 = SSL_get_wbio(ssl);
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0x2a,*(undefined4 *)&ssl->d1->w_msg_hdr,0);
    }
    if (0xe3 < *(uint *)&ssl->d1->w_msg_hdr) goto LAB_004a770c;
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu()");
    if (ssl->write_hash == (EVP_MD_CTX *)0x0) {
      iVar7 = 0;
      goto LAB_004a773c;
    }
  }
  uVar21 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
  iVar7 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar21);
LAB_004a773c:
  if ((ssl->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar29 = (*(code *)PTR_EVP_CIPHER_flags_006a9270)(ssl->enc_write_ctx->cipher),
     (uVar29 & 2) == 0)) {
    iVar14 = 0;
  }
  else {
    iVar14 = (*(code *)PTR_EVP_CIPHER_block_size_006a921c)(ssl->enc_write_ctx->cipher);
    iVar14 = iVar14 << 1;
  }
  iVar16 = ssl->init_num;
  while( true ) {
    while( true ) {
      if (iVar16 == 0) {
        return 0;
      }
      iVar26 = *(int *)&ssl->d1->w_msg_hdr;
      pBVar8 = SSL_get_wbio(ssl);
      iVar16 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0xd,0,0);
      iVar16 = ((-0xd - iVar7) - iVar14) + (iVar26 - iVar16);
      if (iVar16 < 0xd) {
        pBVar8 = SSL_get_wbio(ssl);
        iVar16 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0xb,0,0);
        if (iVar16 < 1) {
          return iVar16;
        }
        iVar16 = ((*(int *)&ssl->d1->w_msg_hdr + -0xd) - iVar7) - iVar14;
      }
      iVar26 = ssl->init_num;
      if (iVar16 < ssl->init_num) {
        iVar26 = iVar16;
      }
      iVar13 = dtls1_write_bytes(ssl,0x14,ssl->init_buf->data + ssl->init_off,iVar26);
      if (-1 < iVar13) break;
      pBVar8 = SSL_get_wbio(ssl);
      iVar16 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0x2b,0,0);
      if (iVar16 < 1) {
        return -1;
      }
      pdVar9 = ssl->d1;
      pBVar8 = SSL_get_wbio(ssl);
      uVar21 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar8,0x28,0,0);
      iVar16 = ssl->init_num;
      *(undefined4 *)&pdVar9->w_msg_hdr = uVar21;
    }
    if (iVar13 != iVar26) {
      OpenSSLDie("d1_both.c",0x166,"len == (unsigned int)ret");
    }
    iVar16 = ssl->init_num - iVar13;
    if (iVar13 == ssl->init_num) break;
    ssl->init_num = iVar16;
    ssl->init_off = ssl->init_off + iVar13;
  }
  if (ssl->msg_callback != (_func_3150 *)0x0) {
    (*ssl->msg_callback)
              (1,ssl->version,0x14,ssl->init_buf->data,iVar13 + ssl->init_off,ssl,
               ssl->msg_callback_arg);
  }
  ssl->init_off = 0;
  ssl->init_num = 0;
  return 1;
}

