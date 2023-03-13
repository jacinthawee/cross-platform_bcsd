
int dtls1_retransmit_buffered_messages(SSL *param_1,int param_2)

{
  undefined uVar1;
  char cVar2;
  undefined2 uVar3;
  ushort uVar4;
  uchar *puVar5;
  bool bVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  BIO *pBVar10;
  dtls1_state_st *pdVar11;
  ssl3_state_st *psVar12;
  char *ptr;
  void *pvVar13;
  uint uVar14;
  ulong uVar15;
  dtls1_state_st *pdVar16;
  uint uVar17;
  ushort uVar18;
  int *piVar19;
  int iVar20;
  SSL *s;
  SSL_SESSION *pSVar21;
  undefined4 uVar22;
  char *pcVar23;
  char *pcVar24;
  undefined4 *puVar25;
  int iVar26;
  uint uVar27;
  COMP_CTX *pCVar28;
  int iVar29;
  EVP_MD_CTX *pEVar30;
  EVP_CIPHER_CTX *pEVar31;
  EVP_MD_CTX *unaff_s2;
  SSL_SESSION *unaff_s3;
  COMP_CTX *unaff_s4;
  char *unaff_s5;
  EVP_CIPHER_CTX *pEVar32;
  uint uVar33;
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
  local_4c = (int **)PTR___stack_chk_guard_006a9ae8;
  local_60 = &_gp;
  local_2c = *(int **)PTR___stack_chk_guard_006a9ae8;
  local_50 = puStack_88;
  local_40 = (*(code *)PTR_pqueue_iterator_006a82e8)(param_1->d1->sent_messages);
  iVar9 = (**(code **)(local_60 + -0x6af4))(puStack_88);
  if (iVar9 != 0) {
    local_48 = *(undefined4 **)(local_60 + -0x52e8);
    unaff_s5 = "-check_ss_sig";
    local_44 = "retransmit:  message %d non-existant\n";
    do {
      local_3c = 0;
      puStack_88 = (undefined4 *)
                   ((uint)*(ushort *)(*(int *)(iVar9 + 8) + 8) * 2 -
                   *(int *)(*(int *)(iVar9 + 8) + 0x14));
      local_38 = (uint)puStack_88 & 0xffff;
      iVar9 = (**(code **)(local_60 + -0x6b08))(param_1->d1->sent_messages,&local_3c);
      if (iVar9 == 0) {
        param_2 = 1;
        (**(code **)(local_60 + -0x5460))(*local_48,1,local_44,(uint)puStack_88 & 0xffff);
      }
      else {
        puStack_88 = *(undefined4 **)(iVar9 + 8);
        iVar9 = 0xc;
        if (puStack_88[5] != 0) {
          iVar9 = 1;
        }
        (**(code **)(local_60 + -0x52f4))
                  (param_1->init_buf->data,puStack_88[0xb],iVar9 + puStack_88[1]);
        uVar15 = puStack_88[1];
        uVar3 = *(undefined2 *)(puStack_88 + 2);
        pEVar32 = (EVP_CIPHER_CTX *)puStack_88[4];
        pdVar11 = param_1->d1;
        param_1->init_num = iVar9 + uVar15;
        uVar1 = *(undefined *)puStack_88;
        (pdVar11->w_msg_hdr).frag_off = uVar15;
        *(undefined2 *)&(pdVar11->w_msg_hdr).frag_len = uVar3;
        (pdVar11->w_msg_hdr).is_ccs = 0;
        *(undefined *)&(pdVar11->w_msg_hdr).seq = uVar1;
        pdVar16 = param_1->d1;
        pEVar31 = (EVP_CIPHER_CTX *)puStack_88[6];
        pEVar30 = (EVP_MD_CTX *)puStack_88[7];
        pCVar28 = (COMP_CTX *)puStack_88[8];
        uVar18 = pdVar16->w_epoch;
        pSVar21 = (SSL_SESSION *)puStack_88[9];
        uVar4 = *(ushort *)(puStack_88 + 10);
        uVar33 = uVar18 - 1;
        local_54 = param_1->enc_write_ctx;
        unaff_s2 = param_1->write_hash;
        unaff_s4 = param_1->compress;
        unaff_s3 = param_1->session;
        (pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx = pEVar32;
        pdVar16->listen = 1;
        param_1->enc_write_ctx = pEVar31;
        param_1->write_hash = pEVar30;
        param_1->compress = pCVar28;
        param_1->session = pSVar21;
        pdVar16->w_epoch = uVar4;
        if (uVar4 == uVar33) {
          psVar12 = param_1->s3;
          uVar22 = *(undefined4 *)(pdVar16->last_write_sequence + 4);
          uVar27 = *(uint *)pdVar16->last_write_sequence;
          uVar14 = (uint)(psVar12->write_sequence + 4) & 3;
          local_34 = *(undefined4 *)psVar12->write_sequence;
          uVar17 = (uint)(psVar12->write_sequence + 7) & 3;
          local_30 = (*(int *)(psVar12->write_sequence + 4 + -uVar14) << uVar14 * 8 |
                     (uint)pCVar28 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar17 + 1) * 8 |
                     *(uint *)(psVar12->write_sequence + 7 + -uVar17) >> (3 - uVar17) * 8;
          uVar14 = (uint)psVar12->write_sequence & 3;
          puVar5 = psVar12->write_sequence + -uVar14;
          *(uint *)puVar5 = *(uint *)puVar5 & -1 << (4 - uVar14) * 8 | uVar27 >> uVar14 * 8;
          puVar5 = psVar12->write_sequence + 3;
          uVar14 = (uint)puVar5 & 3;
          *(uint *)(puVar5 + -uVar14) =
               *(uint *)(puVar5 + -uVar14) & 0xffffffffU >> (uVar14 + 1) * 8 |
               uVar27 << (3 - uVar14) * 8;
          *(undefined4 *)(psVar12->write_sequence + 4) = uVar22;
        }
        uVar22 = 0x16;
        if (puStack_88[5] != 0) {
          uVar22 = 0x14;
        }
        unaff_s5 = (char *)dtls1_do_write(param_1,uVar22);
        pdVar11 = param_1->d1;
        uVar4 = *(ushort *)(puStack_88 + 10);
        param_1->enc_write_ctx = local_54;
        param_1->write_hash = unaff_s2;
        param_1->compress = unaff_s4;
        param_1->session = unaff_s3;
        pdVar11->w_epoch = uVar18;
        if (uVar33 == uVar4) {
          uVar14 = *(uint *)param_1->s3->write_sequence;
          uVar22 = *(undefined4 *)(param_1->s3->write_sequence + 4);
          uVar33 = (uint)pdVar11->last_write_sequence & 3;
          puVar5 = pdVar11->last_write_sequence + -uVar33;
          *(uint *)puVar5 = *(uint *)puVar5 & -1 << (4 - uVar33) * 8 | uVar14 >> uVar33 * 8;
          puVar5 = pdVar11->last_write_sequence + 3;
          uVar33 = (uint)puVar5 & 3;
          *(uint *)(puVar5 + -uVar33) =
               *(uint *)(puVar5 + -uVar33) & 0xffffffffU >> (uVar33 + 1) * 8 |
               uVar14 << (3 - uVar33) * 8;
          *(undefined4 *)(pdVar11->last_write_sequence + 4) = uVar22;
          psVar12 = param_1->s3;
          *(undefined4 *)psVar12->write_sequence = local_34;
          *(uint *)(psVar12->write_sequence + 4) = local_30;
          pdVar11 = param_1->d1;
        }
        pdVar11->listen = 0;
        pBVar10 = SSL_get_wbio(param_1);
        param_2 = 0xb;
        (**(code **)(local_60 + -0x7fc8))(pBVar10,0xb,0,0);
        if ((int)unaff_s5 < 1) {
          param_2 = 1;
          (**(code **)(local_60 + -0x536c))
                    ("dtls1_retransmit_message() failed\n",1,0x22,
                     **(undefined4 **)(local_60 + -0x52e8));
          iVar9 = -1;
          goto LAB_004a42a8;
        }
      }
      iVar9 = (**(code **)(local_60 + -0x6af4))(local_50);
    } while (iVar9 != 0);
  }
  iVar9 = 1;
LAB_004a42a8:
  if (local_2c == *local_4c) {
    return iVar9;
  }
  pcStack_74 = dtls1_buffer_message;
  piVar19 = local_2c;
  (**(code **)(local_60 + -0x5330))();
  puVar8 = PTR___stack_chk_guard_006a9ae8;
  pSStack_94 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  pSStack_8c = param_1;
  pEStack_84 = unaff_s2;
  pSStack_80 = unaff_s3;
  pCStack_7c = unaff_s4;
  pcStack_78 = unaff_s5;
  if (piVar19[0x12] != 0) {
    OpenSSLDie("d1_both.c",0x501,"s->init_off == 0");
  }
  puVar25 = (undefined4 *)0xb5;
  pcVar23 = "d1_both.c";
  iVar9 = piVar19[0x11];
  ptr = (char *)CRYPTO_malloc(0x34,"d1_both.c",0xb5);
  if (ptr == (char *)0x0) {
LAB_004a4578:
    iVar9 = 0;
    goto LAB_004a44c0;
  }
  pvVar13 = (void *)0x0;
  if (iVar9 != 0) {
    puVar25 = (undefined4 *)0xba;
    pcVar23 = "d1_both.c";
    pvVar13 = CRYPTO_malloc(iVar9,"d1_both.c",0xba);
    if (pvVar13 == (void *)0x0) {
      CRYPTO_free(ptr);
      goto LAB_004a4578;
    }
  }
  puVar7 = PTR_memcpy_006a9aec;
  iVar9 = piVar19[0xf];
  iVar26 = piVar19[0x11];
  *(void **)(ptr + 0x2c) = pvVar13;
  *(undefined4 *)(ptr + 0x30) = 0;
  (*(code *)puVar7)(pvVar13,*(undefined4 *)(iVar9 + 4),iVar26);
  if (param_2 == 0) {
    iVar9 = piVar19[0x17];
    iVar20 = *(int *)(iVar9 + 0x264);
    if (iVar20 + 0xc != piVar19[0x11]) {
      iVar9 = 0x510;
      pcVar23 = "s->d1->w_msg_hdr.msg_len + DTLS1_HM_HEADER_LENGTH == (unsigned int)s->init_num";
LAB_004a4408:
      OpenSSLDie("d1_both.c",iVar9,pcVar23);
      iVar9 = piVar19[0x17];
      iVar20 = *(int *)(iVar9 + 0x264);
    }
  }
  else {
    iVar9 = piVar19[0x17];
    iVar26 = 1;
    if (*piVar19 != 0xfeff) {
      iVar26 = 3;
    }
    iVar20 = *(int *)(iVar9 + 0x264);
    if (iVar26 + iVar20 != piVar19[0x11]) {
      iVar9 = 0x50d;
      pcVar23 = 
      "s->d1->w_msg_hdr.msg_len + ((s->version == DTLS1_VERSION) ? DTLS1_CCS_HEADER_LENGTH : 3) == (unsigned int)s->init_num"
      ;
      goto LAB_004a4408;
    }
  }
  uVar18 = *(ushort *)(iVar9 + 0x268);
  puVar25 = &uStack_9c;
  *(int *)(ptr + 4) = iVar20;
  puVar7 = PTR_pitem_new_006a829c;
  *(ushort *)(ptr + 8) = uVar18;
  cVar2 = *(char *)(iVar9 + 0x260);
  *(undefined4 *)(ptr + 0xc) = 0;
  *ptr = cVar2;
  iVar29 = piVar19[0x23];
  iVar20 = piVar19[0x24];
  iVar26 = piVar19[0x25];
  iVar9 = piVar19[0x30];
  uVar3 = *(undefined2 *)(piVar19[0x17] + 0x20a);
  *(undefined4 *)(ptr + 0x10) = *(undefined4 *)(piVar19[0x17] + 0x264);
  *(int *)(ptr + 0x14) = param_2;
  *(int *)(ptr + 0x18) = iVar29;
  *(int *)(ptr + 0x1c) = iVar20;
  *(int *)(ptr + 0x20) = iVar26;
  *(int *)(ptr + 0x24) = iVar9;
  *(undefined2 *)(ptr + 0x28) = uVar3;
  uStack_9c = 0;
  uStack_98 = (uint)uVar18 * 2 - param_2 & 0xffff;
  pcVar24 = ptr;
  pcVar23 = (char *)(*(code *)puVar7)(puVar25);
  if (pcVar23 == (char *)0x0) {
    pcVar23 = pcVar24;
    if (*(int *)(ptr + 0x14) != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a82dc)(*(undefined4 *)(ptr + 0x18));
      (*(code *)PTR_EVP_MD_CTX_destroy_006a8088)(*(undefined4 *)(ptr + 0x1c));
      pcVar23 = pcVar24;
    }
    if (*(void **)(ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 0x2c));
    }
    if (*(void **)(ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)(ptr + 0x30));
    }
    CRYPTO_free(ptr);
    iVar9 = 0;
  }
  else {
    (*(code *)PTR_pqueue_insert_006a82a0)(*(undefined4 *)(piVar19[0x17] + 0x248));
    iVar9 = 1;
  }
LAB_004a44c0:
  if (pSStack_94 == *(SSL **)puVar8) {
    return iVar9;
  }
  s = pSStack_94;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((char *)s->state == pcVar23) {
    pcVar23 = s->init_buf->data;
    *pcVar23 = '\x01';
    pdVar11 = s->d1;
    iVar9 = s->version;
    uVar18 = pdVar11->next_handshake_write_seq;
    pdVar11->handshake_write_seq = uVar18;
    s->init_num = 1;
    if (iVar9 == 0x100) {
      pdVar11->next_handshake_write_seq = uVar18 + 1;
      pcVar23[1] = (char)(uVar18 >> 8);
      pcVar23[2] = (char)s->d1->handshake_write_seq;
      pdVar11 = s->d1;
      uVar18 = pdVar11->handshake_write_seq;
      s->init_num = s->init_num + 2;
    }
    s->init_off = 0;
    *(ushort *)&(pdVar11->w_msg_hdr).frag_len = uVar18;
    (pdVar11->w_msg_hdr).frag_off = 0;
    (pdVar11->w_msg_hdr).is_ccs = 0;
    *(undefined *)&(pdVar11->w_msg_hdr).seq = 1;
    (pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    dtls1_buffer_message(s,1);
    s->state = (int)puVar25;
  }
  iVar9 = dtls1_query_mtu(s);
  if (iVar9 == 0) {
    return -1;
  }
  uVar33 = (s->d1->w_msg_hdr).msg_len;
  pBVar10 = SSL_get_wbio(s);
  iVar9 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar10,0x31,0,0);
  if (uVar33 < 0x100U - iVar9) {
    OpenSSLDie("d1_both.c",0x112,"s->d1->mtu >= dtls1_min_mtu(s)");
  }
  if (s->write_hash == (EVP_MD_CTX *)0x0) {
    iVar9 = 0;
  }
  else {
    uVar22 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
    iVar9 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar22);
  }
  if ((s->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
     (uVar33 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)(s->enc_write_ctx->cipher), (uVar33 & 2) == 0
     )) {
    iVar26 = 0;
  }
  else {
    iVar26 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(s->enc_write_ctx->cipher);
    iVar26 = iVar26 << 1;
  }
  iVar20 = s->init_num;
  uVar33 = 0;
  s->rwstate = 1;
  bVar6 = true;
  while( true ) {
    while( true ) {
      if (iVar20 < 1) {
        return 0;
      }
      pBVar10 = SSL_get_wbio(s);
      iVar20 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar10,0xd,0,0);
      uVar14 = iVar9 + 0xd + iVar26 + iVar20;
      uVar17 = (s->d1->w_msg_hdr).msg_len;
      if ((uVar14 < uVar17) && (uVar17 = uVar17 - uVar14, 0xc < uVar17)) {
        uVar14 = s->init_num;
        if (uVar17 < (uint)s->init_num) {
          uVar14 = uVar17;
        }
      }
      else {
        pBVar10 = SSL_get_wbio(s);
        iVar20 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar10,0xb,0,0);
        if (iVar20 < 1) {
          s->rwstate = 2;
          return iVar20;
        }
        uVar14 = (s->d1->w_msg_hdr).msg_len;
        if (uVar14 <= iVar9 + iVar26 + 0x19U) {
          return -1;
        }
        uVar17 = (uVar14 - 0xd) - (iVar9 + iVar26);
        uVar14 = s->init_num;
        if (uVar17 < (uint)s->init_num) {
          uVar14 = uVar17;
        }
      }
      if ((int)uVar14 < 0) {
        uVar14 = 0x7fffffff;
      }
      uVar17 = dtls1_write_bytes(s,0x14,s->init_buf->data + s->init_off,uVar14);
      if ((int)uVar17 < 0) break;
      if (uVar14 != uVar17) {
        OpenSSLDie("d1_both.c",0x19f,"len == (unsigned int)ret");
      }
      if (uVar17 == s->init_num) {
        if (s->msg_callback != (_func_3150 *)0x0) {
          (*s->msg_callback)(1,s->version,0x14,s->init_buf->data,uVar17 + s->init_off,s,
                             s->msg_callback_arg);
        }
        s->init_off = 0;
        s->init_num = 0;
        return 1;
      }
      pdVar11 = s->d1;
      iVar20 = s->init_num - uVar17;
      uVar33 = uVar33 + (uVar17 - 0xc);
      s->init_num = iVar20;
      s->init_off = s->init_off + uVar17;
      (pdVar11->w_msg_hdr).is_ccs = uVar33;
      (pdVar11->w_msg_hdr).saved_retransmit_state.enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
    }
    if (!bVar6) {
      return -1;
    }
    pBVar10 = SSL_get_wbio(s);
    iVar20 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar10,0x2b,0,0);
    if (iVar20 < 1) break;
    uVar14 = SSL_ctrl(s,0x20,0,(void *)0x0);
    if ((uVar14 & 0x1000) != 0) {
      return -1;
    }
    iVar20 = dtls1_query_mtu(s);
    if (iVar20 == 0) {
      return -1;
    }
    iVar20 = s->init_num;
    bVar6 = false;
  }
  return -1;
}

