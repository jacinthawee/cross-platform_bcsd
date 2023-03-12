
void dtls1_retransmit_buffered_messages(SSL *param_1)

{
  undefined uVar1;
  undefined2 uVar2;
  ushort uVar3;
  ushort uVar4;
  pitem *ppVar5;
  int iVar6;
  SSL_SESSION *pSVar7;
  BIO *bp;
  dtls1_state_st *pdVar8;
  undefined4 uVar9;
  dtls1_state_st *pdVar10;
  uint uVar11;
  EVP_CIPHER_CTX *pEVar12;
  EVP_MD_CTX *pEVar13;
  ssl3_state_st *psVar14;
  uint uVar15;
  undefined *puVar16;
  int iVar17;
  EVP_CIPHER_CTX *pEVar18;
  SSL_SESSION *pSVar19;
  COMP_CTX *pCVar20;
  EVP_MD_CTX *pEVar21;
  COMP_CTX *pCVar22;
  pitem *local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  int local_2c;
  
  local_2c = __TMC_END__;
  local_40 = pqueue_iterator(param_1->d1->sent_messages);
  ppVar5 = pqueue_next(&local_40);
  do {
    if (ppVar5 == (pitem *)0x0) {
      uVar9 = 1;
LAB_0005eeb8:
      if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(uVar9);
      }
      return;
    }
    local_3c = 0;
    uVar11 = (uint)*(ushort *)((int)ppVar5->data + 8) * 2 - *(int *)((int)ppVar5->data + 0x14);
    uVar15 = uVar11 & 0xffff;
    local_38 = (uint)CONCAT11((char)uVar11,(char)(uVar15 >> 8)) << 0x10;
    ppVar5 = pqueue_find(param_1->d1->sent_messages,(uchar *)&local_3c);
    if (ppVar5 == (pitem *)0x0) {
      __fprintf_chk(stderr,1,"retransmit:  message %d non-existant\n",uVar15);
    }
    else {
      puVar16 = (undefined *)ppVar5->data;
      if (*(int *)(puVar16 + 0x14) == 0) {
        iVar17 = 0xc;
      }
      else {
        iVar17 = 1;
      }
      memcpy(param_1->init_buf->data,*(void **)(puVar16 + 0x2c),*(int *)(puVar16 + 4) + iVar17);
      iVar6 = *(int *)(puVar16 + 4);
      uVar11 = *(uint *)(puVar16 + 0x10);
      pdVar10 = param_1->d1;
      param_1->init_num = iVar17 + iVar6;
      uVar1 = *puVar16;
      uVar2 = *(undefined2 *)(puVar16 + 8);
      (pdVar10->w_msg_hdr).is_ccs = uVar11;
      *(undefined *)&(pdVar10->w_msg_hdr).msg_len = uVar1;
      pEVar12 = param_1->enc_write_ctx;
      pdVar8 = param_1->d1;
      pEVar21 = *(EVP_MD_CTX **)(puVar16 + 0x1c);
      pEVar13 = param_1->write_hash;
      uVar3 = pdVar8->w_epoch;
      pEVar18 = *(EVP_CIPHER_CTX **)(puVar16 + 0x18);
      pCVar22 = *(COMP_CTX **)(puVar16 + 0x20);
      uVar11 = uVar3 - 1;
      *(int *)&(pdVar10->w_msg_hdr).seq = iVar6;
      pCVar20 = param_1->compress;
      pSVar7 = *(SSL_SESSION **)(puVar16 + 0x24);
      *(undefined2 *)&(pdVar10->w_msg_hdr).frag_off = uVar2;
      (pdVar10->w_msg_hdr).frag_len = 0;
      pSVar19 = param_1->session;
      pdVar8->change_cipher_spec_ok = 1;
      param_1->write_hash = pEVar21;
      uVar4 = *(ushort *)(puVar16 + 0x28);
      param_1->enc_write_ctx = pEVar18;
      param_1->compress = pCVar22;
      param_1->session = pSVar7;
      pdVar8->w_epoch = uVar4;
      if (uVar4 == uVar11) {
        psVar14 = param_1->s3;
        uVar9 = *(undefined4 *)(pdVar8->last_write_sequence + 4);
        local_34 = *(undefined4 *)psVar14->write_sequence;
        uStack_30 = *(undefined4 *)(psVar14->write_sequence + 4);
        *(undefined4 *)psVar14->write_sequence = *(undefined4 *)pdVar8->last_write_sequence;
        *(undefined4 *)(psVar14->write_sequence + 4) = uVar9;
      }
      if (*(int *)(puVar16 + 0x14) == 0) {
        uVar9 = 0x16;
      }
      else {
        uVar9 = 0x14;
      }
      iVar17 = dtls1_do_write(param_1,uVar9);
      uVar4 = *(ushort *)(puVar16 + 0x28);
      pdVar8 = param_1->d1;
      param_1->enc_write_ctx = pEVar12;
      param_1->compress = pCVar20;
      param_1->session = pSVar19;
      param_1->write_hash = pEVar13;
      pdVar8->w_epoch = uVar3;
      if (uVar11 == uVar4) {
        uVar9 = *(undefined4 *)(param_1->s3->write_sequence + 4);
        *(undefined4 *)pdVar8->last_write_sequence = *(undefined4 *)param_1->s3->write_sequence;
        *(undefined4 *)(pdVar8->last_write_sequence + 4) = uVar9;
        psVar14 = param_1->s3;
        *(undefined4 *)psVar14->write_sequence = local_34;
        *(undefined4 *)(psVar14->write_sequence + 4) = uStack_30;
        pdVar8 = param_1->d1;
      }
      pdVar8->change_cipher_spec_ok = 0;
      bp = SSL_get_wbio(param_1);
      BIO_ctrl(bp,0xb,0,(void *)0x0);
      if (iVar17 < 1) {
        fwrite("dtls1_retransmit_message() failed\n",1,0x22,stderr);
        uVar9 = 0xffffffff;
        goto LAB_0005eeb8;
      }
    }
    ppVar5 = pqueue_next(&local_40);
  } while( true );
}

