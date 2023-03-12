
undefined4 dtls1_retransmit_buffered_messages(SSL *param_1)

{
  undefined uVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined *puVar5;
  dtls1_state_st *pdVar6;
  EVP_CIPHER_CTX *pEVar7;
  EVP_MD_CTX *pEVar8;
  COMP_CTX *pCVar9;
  SSL_SESSION *pSVar10;
  ssl3_state_st *psVar11;
  pitem *ppVar12;
  int iVar13;
  dtls1_state_st *pdVar14;
  BIO *bp;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  int in_GS_OFFSET;
  undefined4 local_34;
  undefined4 local_30;
  pitem *local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = pqueue_iterator(param_1->d1->sent_messages);
  ppVar12 = pqueue_next(&local_2c);
  do {
    if (ppVar12 == (pitem *)0x0) {
      uVar15 = 1;
LAB_080bd465:
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        return uVar15;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    local_28 = 0;
    uVar16 = (uint)*(ushort *)((int)ppVar12->data + 8) * 2 - *(int *)((int)ppVar12->data + 0x14);
    local_24 = (uint)CONCAT11((char)uVar16,(char)(uVar16 >> 8)) << 0x10;
    ppVar12 = pqueue_find(param_1->d1->sent_messages,(uchar *)&local_28);
    if (ppVar12 == (pitem *)0x0) {
      __fprintf_chk(stderr,1,"retransmit:  message %d non-existant\n",uVar16 & 0xffff);
    }
    else {
      puVar5 = (undefined *)ppVar12->data;
      iVar17 = (-(uint)(*(int *)(puVar5 + 0x14) == 0) & 0xb) + 1;
      memcpy(param_1->init_buf->data,*(void **)(puVar5 + 0x2c),*(int *)(puVar5 + 4) + iVar17);
      iVar13 = *(int *)(puVar5 + 4);
      uVar16 = *(uint *)(puVar5 + 0x10);
      pdVar14 = param_1->d1;
      param_1->init_num = iVar17 + iVar13;
      uVar1 = *puVar5;
      uVar2 = *(undefined2 *)(puVar5 + 8);
      *(int *)&(pdVar14->w_msg_hdr).seq = iVar13;
      (pdVar14->w_msg_hdr).frag_len = 0;
      *(undefined *)&(pdVar14->w_msg_hdr).msg_len = uVar1;
      *(undefined2 *)&(pdVar14->w_msg_hdr).frag_off = uVar2;
      pdVar6 = param_1->d1;
      (pdVar14->w_msg_hdr).is_ccs = uVar16;
      pEVar7 = param_1->enc_write_ctx;
      uVar3 = pdVar6->w_epoch;
      pEVar8 = param_1->write_hash;
      pCVar9 = param_1->compress;
      pSVar10 = param_1->session;
      pdVar6->change_cipher_spec_ok = 1;
      param_1->enc_write_ctx = *(EVP_CIPHER_CTX **)(puVar5 + 0x18);
      param_1->write_hash = *(EVP_MD_CTX **)(puVar5 + 0x1c);
      param_1->compress = *(COMP_CTX **)(puVar5 + 0x20);
      param_1->session = *(SSL_SESSION **)(puVar5 + 0x24);
      uVar4 = *(ushort *)(puVar5 + 0x28);
      pdVar6->w_epoch = uVar4;
      uVar16 = uVar3 - 1;
      if (uVar4 == uVar16) {
        psVar11 = param_1->s3;
        local_30 = *(undefined4 *)(param_1->s3->write_sequence + 4);
        local_34 = *(undefined4 *)param_1->s3->write_sequence;
        uVar15 = *(undefined4 *)pdVar6->last_write_sequence;
        *(undefined4 *)(psVar11->write_sequence + 4) =
             *(undefined4 *)(pdVar6->last_write_sequence + 4);
        *(undefined4 *)psVar11->write_sequence = uVar15;
      }
      iVar13 = dtls1_do_write(param_1,(-(*(int *)(puVar5 + 0x14) == 0) & 2U) + 0x14);
      param_1->enc_write_ctx = pEVar7;
      param_1->write_hash = pEVar8;
      param_1->compress = pCVar9;
      param_1->session = pSVar10;
      pdVar14 = param_1->d1;
      pdVar14->w_epoch = uVar3;
      if (uVar16 == *(ushort *)(puVar5 + 0x28)) {
        uVar15 = *(undefined4 *)param_1->s3->write_sequence;
        *(undefined4 *)(pdVar14->last_write_sequence + 4) =
             *(undefined4 *)(param_1->s3->write_sequence + 4);
        *(undefined4 *)pdVar14->last_write_sequence = uVar15;
        psVar11 = param_1->s3;
        *(undefined4 *)(psVar11->write_sequence + 4) = local_30;
        *(undefined4 *)psVar11->write_sequence = local_34;
        pdVar14 = param_1->d1;
      }
      pdVar14->change_cipher_spec_ok = 0;
      bp = SSL_get_wbio(param_1);
      BIO_ctrl(bp,0xb,0,(void *)0x0);
      if (iVar13 < 1) {
        fwrite("dtls1_retransmit_message() failed\n",1,0x22,stderr);
        uVar15 = 0xffffffff;
        goto LAB_080bd465;
      }
    }
    ppVar12 = pqueue_next(&local_2c);
  } while( true );
}

