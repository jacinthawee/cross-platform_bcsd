
void dtls1_retransmit_message
               (SSL *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  pitem *ppVar4;
  BUF_MEM *pBVar5;
  BIO *bp;
  EVP_CIPHER_CTX *pEVar6;
  dtls1_state_st *pdVar7;
  undefined4 uVar8;
  COMP_CTX *pCVar9;
  SSL_SESSION *pSVar10;
  COMP_CTX *pCVar11;
  dtls1_state_st *pdVar12;
  ssl3_state_st *psVar13;
  undefined *puVar14;
  ulong uVar15;
  uint uVar16;
  SSL_SESSION *pSVar17;
  int iVar18;
  EVP_MD_CTX *pEVar19;
  EVP_MD_CTX *pEVar20;
  EVP_CIPHER_CTX *pEVar21;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  local_3c = 0;
  local_38 = (uint)CONCAT11((char)param_2,(char)((uint)param_2 >> 8)) << 0x10;
  ppVar4 = pqueue_find(param_1->d1->sent_messages,(uchar *)&local_3c);
  if (ppVar4 == (pitem *)0x0) {
    __fprintf_chk(stderr,1,"retransmit:  message %d non-existant\n",param_2);
    *param_4 = 0;
  }
  else {
    puVar14 = (undefined *)ppVar4->data;
    pBVar5 = param_1->init_buf;
    *param_4 = 1;
    if (*(int *)(puVar14 + 0x14) == 0) {
      iVar18 = 0xc;
    }
    else {
      iVar18 = 1;
    }
    memcpy(pBVar5->data,*(void **)(puVar14 + 0x2c),*(int *)(puVar14 + 4) + iVar18);
    uVar15 = *(ulong *)(puVar14 + 4);
    pdVar12 = param_1->d1;
    param_1->init_num = iVar18 + uVar15;
    uVar1 = *(undefined2 *)(puVar14 + 8);
    pEVar6 = *(EVP_CIPHER_CTX **)(puVar14 + 0x10);
    *(undefined *)&(pdVar12->w_msg_hdr).seq = *puVar14;
    pCVar9 = *(COMP_CTX **)(puVar14 + 0x20);
    (pdVar12->w_msg_hdr).saved_retransmit_state.enc_write_ctx = pEVar6;
    pdVar7 = param_1->d1;
    pSVar10 = *(SSL_SESSION **)(puVar14 + 0x24);
    pEVar21 = *(EVP_CIPHER_CTX **)(puVar14 + 0x18);
    pEVar20 = *(EVP_MD_CTX **)(puVar14 + 0x1c);
    uVar3 = pdVar7->w_epoch;
    (pdVar12->w_msg_hdr).frag_off = uVar15;
    uVar16 = uVar3 - 1;
    *(undefined2 *)&(pdVar12->w_msg_hdr).frag_len = uVar1;
    pCVar11 = param_1->compress;
    uVar2 = *(ushort *)(puVar14 + 0x28);
    (pdVar12->w_msg_hdr).is_ccs = 0;
    pEVar6 = param_1->enc_write_ctx;
    pEVar19 = param_1->write_hash;
    pSVar17 = param_1->session;
    pdVar7->listen = 1;
    param_1->enc_write_ctx = pEVar21;
    param_1->write_hash = pEVar20;
    param_1->compress = pCVar9;
    param_1->session = pSVar10;
    pdVar7->w_epoch = uVar2;
    if (uVar2 == uVar16) {
      psVar13 = param_1->s3;
      uVar8 = *(undefined4 *)(pdVar7->last_write_sequence + 4);
      local_34 = *(undefined4 *)psVar13->write_sequence;
      uStack_30 = *(undefined4 *)(psVar13->write_sequence + 4);
      *(undefined4 *)psVar13->write_sequence = *(undefined4 *)pdVar7->last_write_sequence;
      *(undefined4 *)(psVar13->write_sequence + 4) = uVar8;
    }
    if (*(int *)(puVar14 + 0x14) == 0) {
      uVar8 = 0x16;
    }
    else {
      uVar8 = 0x14;
    }
    ppVar4 = (pitem *)dtls1_do_write(param_1,uVar8);
    uVar2 = *(ushort *)(puVar14 + 0x28);
    pdVar7 = param_1->d1;
    param_1->write_hash = pEVar19;
    param_1->enc_write_ctx = pEVar6;
    param_1->compress = pCVar11;
    param_1->session = pSVar17;
    pdVar7->w_epoch = uVar3;
    if (uVar16 == uVar2) {
      uVar8 = *(undefined4 *)(param_1->s3->write_sequence + 4);
      *(undefined4 *)pdVar7->last_write_sequence = *(undefined4 *)param_1->s3->write_sequence;
      *(undefined4 *)(pdVar7->last_write_sequence + 4) = uVar8;
      psVar13 = param_1->s3;
      *(undefined4 *)psVar13->write_sequence = local_34;
      *(undefined4 *)(psVar13->write_sequence + 4) = uStack_30;
      pdVar7 = param_1->d1;
    }
    pdVar7->listen = 0;
    bp = SSL_get_wbio(param_1);
    BIO_ctrl(bp,0xb,0,(void *)0x0);
  }
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(ppVar4);
  }
  return;
}

