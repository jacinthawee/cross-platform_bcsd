
undefined4
dtls1_retransmit_message(SSL *param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined uVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined *puVar5;
  ulong uVar6;
  EVP_CIPHER_CTX *pEVar7;
  EVP_MD_CTX *pEVar8;
  COMP_CTX *pCVar9;
  SSL_SESSION *pSVar10;
  undefined4 uVar11;
  ssl3_state_st *psVar12;
  pitem *ppVar13;
  undefined4 uVar14;
  dtls1_state_st *pdVar15;
  BIO *bp;
  int iVar16;
  uint uVar17;
  int in_GS_OFFSET;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = 0;
  local_24 = (uint)CONCAT11((char)param_2,(char)(param_2 >> 8)) << 0x10;
  ppVar13 = pqueue_find(param_1->d1->sent_messages,(uchar *)&local_28);
  if (ppVar13 == (pitem *)0x0) {
    __fprintf_chk(stderr,1,"retransmit:  message %d non-existant\n",param_2 & 0xffff);
    *param_4 = 0;
    uVar14 = 0;
  }
  else {
    *param_4 = 1;
    puVar5 = (undefined *)ppVar13->data;
    iVar16 = (-(uint)(*(int *)(puVar5 + 0x14) == 0) & 0xb) + 1;
    memcpy(param_1->init_buf->data,*(void **)(puVar5 + 0x2c),*(int *)(puVar5 + 4) + iVar16);
    uVar6 = *(ulong *)(puVar5 + 4);
    pEVar7 = *(EVP_CIPHER_CTX **)(puVar5 + 0x10);
    pdVar15 = param_1->d1;
    param_1->init_num = iVar16 + uVar6;
    uVar2 = *(undefined2 *)(puVar5 + 8);
    uVar1 = *puVar5;
    (pdVar15->w_msg_hdr).saved_retransmit_state.enc_write_ctx = pEVar7;
    (pdVar15->w_msg_hdr).frag_off = uVar6;
    (pdVar15->w_msg_hdr).is_ccs = 0;
    *(undefined2 *)&(pdVar15->w_msg_hdr).frag_len = uVar2;
    *(undefined *)&(pdVar15->w_msg_hdr).seq = uVar1;
    pEVar7 = param_1->enc_write_ctx;
    pdVar15 = param_1->d1;
    pEVar8 = param_1->write_hash;
    uVar3 = pdVar15->w_epoch;
    pCVar9 = param_1->compress;
    uVar17 = uVar3 - 1;
    pSVar10 = param_1->session;
    pdVar15->listen = 1;
    param_1->enc_write_ctx = *(EVP_CIPHER_CTX **)(puVar5 + 0x18);
    param_1->write_hash = *(EVP_MD_CTX **)(puVar5 + 0x1c);
    param_1->compress = *(COMP_CTX **)(puVar5 + 0x20);
    param_1->session = *(SSL_SESSION **)(puVar5 + 0x24);
    uVar4 = *(ushort *)(puVar5 + 0x28);
    pdVar15->w_epoch = uVar4;
    if (uVar4 == uVar17) {
      psVar12 = param_1->s3;
      local_34 = *(undefined4 *)psVar12->write_sequence;
      local_30 = *(undefined4 *)(psVar12->write_sequence + 4);
      uVar14 = *(undefined4 *)pdVar15->last_write_sequence;
      *(undefined4 *)(psVar12->write_sequence + 4) =
           *(undefined4 *)(pdVar15->last_write_sequence + 4);
      *(undefined4 *)psVar12->write_sequence = uVar14;
    }
    uVar14 = dtls1_do_write(param_1,(-(*(int *)(puVar5 + 0x14) == 0) & 2U) + 0x14);
    uVar4 = *(ushort *)(puVar5 + 0x28);
    param_1->enc_write_ctx = pEVar7;
    param_1->write_hash = pEVar8;
    param_1->compress = pCVar9;
    param_1->session = pSVar10;
    pdVar15 = param_1->d1;
    pdVar15->w_epoch = uVar3;
    if (uVar17 == uVar4) {
      uVar11 = *(undefined4 *)(param_1->s3->write_sequence + 4);
      *(undefined4 *)pdVar15->last_write_sequence = *(undefined4 *)param_1->s3->write_sequence;
      *(undefined4 *)(pdVar15->last_write_sequence + 4) = uVar11;
      psVar12 = param_1->s3;
      *(undefined4 *)psVar12->write_sequence = local_34;
      *(undefined4 *)(psVar12->write_sequence + 4) = local_30;
      pdVar15 = param_1->d1;
    }
    pdVar15->listen = 0;
    bp = SSL_get_wbio(param_1);
    BIO_ctrl(bp,0xb,0,(void *)0x0);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar14;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

