
undefined4
dtls1_retransmit_message(SSL *param_1,undefined2 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined uVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uchar *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  dtls1_state_st *pdVar11;
  undefined4 uVar12;
  BIO *pBVar13;
  ssl3_state_st *psVar14;
  BUF_MEM *pBVar15;
  int iVar16;
  dtls1_state_st *pdVar17;
  SSL_SESSION *pSVar18;
  undefined4 uVar19;
  EVP_MD_CTX *pEVar20;
  EVP_CIPHER_CTX *pEVar21;
  COMP_CTX *pCVar22;
  uint uVar23;
  EVP_MD_CTX *pEVar24;
  EVP_CIPHER_CTX *pEVar25;
  uint uVar26;
  void *ptr;
  undefined *puVar27;
  uint uVar28;
  SSL_SESSION *pSVar29;
  COMP_CTX *pCVar30;
  undefined4 local_34;
  uint local_30;
  
  puVar7 = PTR___stack_chk_guard_006aabf0;
  iVar9 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar10 = (*(code *)PTR_pqueue_find_006a93f4)(param_1->d1->sent_messages);
  puVar8 = PTR_memcpy_006aabf4;
  if (iVar10 == 0) {
    (*(code *)PTR___fprintf_chk_006aaa8c)
              (*(undefined4 *)PTR_stderr_006aac00,1,"retransmit:  message %d non-existant\n",param_2
              );
    uVar12 = 0;
    *param_4 = 0;
  }
  else {
    puVar27 = *(undefined **)(iVar10 + 8);
    pBVar15 = param_1->init_buf;
    *param_4 = 1;
    iVar10 = 0xc;
    if (*(int *)(puVar27 + 0x14) != 0) {
      iVar10 = 1;
    }
    (*(code *)puVar8)(pBVar15->data,*(undefined4 *)(puVar27 + 0x2c),iVar10 + *(int *)(puVar27 + 4));
    iVar16 = *(int *)(puVar27 + 4);
    uVar2 = *(undefined2 *)(puVar27 + 8);
    uVar26 = *(uint *)(puVar27 + 0x10);
    pdVar11 = param_1->d1;
    param_1->init_num = iVar10 + iVar16;
    uVar1 = *puVar27;
    *(int *)&(pdVar11->w_msg_hdr).seq = iVar16;
    *(undefined2 *)&(pdVar11->w_msg_hdr).frag_off = uVar2;
    (pdVar11->w_msg_hdr).frag_len = 0;
    *(undefined *)&(pdVar11->w_msg_hdr).msg_len = uVar1;
    pdVar17 = param_1->d1;
    pEVar25 = *(EVP_CIPHER_CTX **)(puVar27 + 0x18);
    pEVar24 = *(EVP_MD_CTX **)(puVar27 + 0x1c);
    pCVar22 = *(COMP_CTX **)(puVar27 + 0x20);
    uVar3 = pdVar17->w_epoch;
    pSVar18 = *(SSL_SESSION **)(puVar27 + 0x24);
    uVar4 = *(ushort *)(puVar27 + 0x28);
    uVar28 = uVar3 - 1;
    pEVar21 = param_1->enc_write_ctx;
    pEVar20 = param_1->write_hash;
    pCVar30 = param_1->compress;
    pSVar29 = param_1->session;
    (pdVar11->w_msg_hdr).is_ccs = uVar26;
    pdVar17->change_cipher_spec_ok = 1;
    param_1->enc_write_ctx = pEVar25;
    param_1->write_hash = pEVar24;
    param_1->compress = pCVar22;
    param_1->session = pSVar18;
    pdVar17->w_epoch = uVar4;
    if (uVar4 == uVar28) {
      psVar14 = param_1->s3;
      uVar12 = *(undefined4 *)(pdVar17->last_write_sequence + 4);
      uVar23 = *(uint *)pdVar17->last_write_sequence;
      uVar26 = (uint)(psVar14->write_sequence + 4) & 3;
      local_34 = *(undefined4 *)psVar14->write_sequence;
      uVar5 = (uint)(psVar14->write_sequence + 7) & 3;
      local_30 = (*(int *)(psVar14->write_sequence + 4 + -uVar26) << uVar26 * 8 |
                 (uint)pEVar24 & 0xffffffffU >> (4 - uVar26) * 8) & -1 << (uVar5 + 1) * 8 |
                 *(uint *)(psVar14->write_sequence + 7 + -uVar5) >> (3 - uVar5) * 8;
      uVar26 = (uint)psVar14->write_sequence & 3;
      puVar6 = psVar14->write_sequence + -uVar26;
      *(uint *)puVar6 = *(uint *)puVar6 & -1 << (4 - uVar26) * 8 | uVar23 >> uVar26 * 8;
      puVar6 = psVar14->write_sequence + 3;
      uVar26 = (uint)puVar6 & 3;
      *(uint *)(puVar6 + -uVar26) =
           *(uint *)(puVar6 + -uVar26) & 0xffffffffU >> (uVar26 + 1) * 8 |
           uVar23 << (3 - uVar26) * 8;
      *(undefined4 *)(psVar14->write_sequence + 4) = uVar12;
    }
    uVar12 = 0x14;
    if (*(int *)(puVar27 + 0x14) == 0) {
      uVar12 = 0x16;
    }
    uVar12 = dtls1_do_write(param_1,uVar12);
    uVar4 = *(ushort *)(puVar27 + 0x28);
    pdVar11 = param_1->d1;
    param_1->enc_write_ctx = pEVar21;
    param_1->write_hash = pEVar20;
    param_1->compress = pCVar30;
    param_1->session = pSVar29;
    pdVar11->w_epoch = uVar3;
    if (uVar28 == uVar4) {
      uVar28 = *(uint *)param_1->s3->write_sequence;
      uVar19 = *(undefined4 *)(param_1->s3->write_sequence + 4);
      uVar26 = (uint)pdVar11->last_write_sequence & 3;
      puVar6 = pdVar11->last_write_sequence + -uVar26;
      *(uint *)puVar6 = *(uint *)puVar6 & -1 << (4 - uVar26) * 8 | uVar28 >> uVar26 * 8;
      puVar6 = pdVar11->last_write_sequence + 3;
      uVar26 = (uint)puVar6 & 3;
      *(uint *)(puVar6 + -uVar26) =
           *(uint *)(puVar6 + -uVar26) & 0xffffffffU >> (uVar26 + 1) * 8 |
           uVar28 << (3 - uVar26) * 8;
      *(undefined4 *)(pdVar11->last_write_sequence + 4) = uVar19;
      psVar14 = param_1->s3;
      *(undefined4 *)psVar14->write_sequence = local_34;
      *(uint *)(psVar14->write_sequence + 4) = local_30;
      pdVar11 = param_1->d1;
    }
    pdVar11->change_cipher_spec_ok = 0;
    pBVar13 = SSL_get_wbio(param_1);
    (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar13,0xb,0,0);
  }
  if (iVar9 == *(int *)puVar7) {
    return uVar12;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar10 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*(int *)(iVar9 + 0x5c) + 0x248));
  while (iVar10 != 0) {
    ptr = *(void **)(iVar10 + 8);
    if (*(int *)((int)ptr + 0x14) != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a93f8)(*(undefined4 *)((int)ptr + 0x18));
      (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(*(undefined4 *)((int)ptr + 0x1c));
    }
    if (*(void **)((int)ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x2c));
    }
    if (*(void **)((int)ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x30));
    }
    CRYPTO_free(ptr);
    (*(code *)PTR_pitem_free_006a939c)(iVar10);
    iVar10 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*(int *)(iVar9 + 0x5c) + 0x248));
  }
  return 0;
}

