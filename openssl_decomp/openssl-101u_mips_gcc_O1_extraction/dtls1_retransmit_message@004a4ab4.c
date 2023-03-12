
/* WARNING: Removing unreachable block (ram,0x004a4d98) */
/* WARNING: Removing unreachable block (ram,0x004a4da4) */

int dtls1_retransmit_message(SSL *param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined2 uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uchar *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  dtls1_state_st *pdVar10;
  undefined4 uVar11;
  BIO *pBVar12;
  ssl3_state_st *psVar13;
  BUF_MEM *pBVar14;
  ulong uVar15;
  dtls1_state_st *pdVar16;
  SSL_SESSION *pSVar17;
  int iVar18;
  EVP_MD_CTX *pEVar19;
  uint uVar20;
  undefined uVar21;
  EVP_CIPHER_CTX *pEVar22;
  COMP_CTX *pCVar23;
  uint uVar24;
  EVP_MD_CTX *pEVar25;
  EVP_CIPHER_CTX *pEVar26;
  EVP_CIPHER_CTX *pEVar27;
  undefined *puVar28;
  uint uVar29;
  SSL_SESSION *pSVar30;
  COMP_CTX *pCVar31;
  undefined4 uStack_4c;
  undefined4 local_34;
  uint local_30;
  
  puVar6 = PTR___stack_chk_guard_006a9ae8;
  param_2 = param_2 & 0xffff;
  iVar8 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar9 = (*(code *)PTR_pqueue_find_006a82d8)(param_1->d1->sent_messages);
  puVar7 = PTR_memcpy_006a9aec;
  if (iVar9 == 0) {
    iVar18 = 1;
    uVar21 = 0xd8;
    (*(code *)PTR___fprintf_chk_006a9980)(*(undefined4 *)PTR_stderr_006a9af8,1);
    iVar9 = 0;
    *param_4 = 0;
  }
  else {
    puVar28 = *(undefined **)(iVar9 + 8);
    pBVar14 = param_1->init_buf;
    *param_4 = 1;
    iVar9 = 0xc;
    if (*(int *)(puVar28 + 0x14) != 0) {
      iVar9 = 1;
    }
    (*(code *)puVar7)(pBVar14->data,*(undefined4 *)(puVar28 + 0x2c),iVar9 + *(int *)(puVar28 + 4));
    uVar15 = *(ulong *)(puVar28 + 4);
    uVar1 = *(undefined2 *)(puVar28 + 8);
    pEVar27 = *(EVP_CIPHER_CTX **)(puVar28 + 0x10);
    pdVar10 = param_1->d1;
    param_1->init_num = iVar9 + uVar15;
    uVar21 = *puVar28;
    (pdVar10->w_msg_hdr).frag_off = uVar15;
    *(undefined2 *)&(pdVar10->w_msg_hdr).frag_len = uVar1;
    (pdVar10->w_msg_hdr).is_ccs = 0;
    *(undefined *)&(pdVar10->w_msg_hdr).seq = uVar21;
    pdVar16 = param_1->d1;
    pEVar26 = *(EVP_CIPHER_CTX **)(puVar28 + 0x18);
    pEVar25 = *(EVP_MD_CTX **)(puVar28 + 0x1c);
    pCVar23 = *(COMP_CTX **)(puVar28 + 0x20);
    uVar2 = pdVar16->w_epoch;
    pSVar17 = *(SSL_SESSION **)(puVar28 + 0x24);
    uVar3 = *(ushort *)(puVar28 + 0x28);
    uVar29 = uVar2 - 1;
    pEVar22 = param_1->enc_write_ctx;
    pEVar19 = param_1->write_hash;
    pCVar31 = param_1->compress;
    pSVar30 = param_1->session;
    (pdVar10->w_msg_hdr).saved_retransmit_state.enc_write_ctx = pEVar27;
    pdVar16->listen = 1;
    param_1->enc_write_ctx = pEVar26;
    param_1->write_hash = pEVar25;
    param_1->compress = pCVar23;
    param_1->session = pSVar17;
    pdVar16->w_epoch = uVar3;
    if (uVar3 == uVar29) {
      psVar13 = param_1->s3;
      uVar11 = *(undefined4 *)(pdVar16->last_write_sequence + 4);
      uVar24 = *(uint *)pdVar16->last_write_sequence;
      uVar20 = (uint)(psVar13->write_sequence + 4) & 3;
      local_34 = *(undefined4 *)psVar13->write_sequence;
      uVar4 = (uint)(psVar13->write_sequence + 7) & 3;
      local_30 = (*(int *)(psVar13->write_sequence + 4 + -uVar20) << uVar20 * 8 |
                 (uint)pEVar25 & 0xffffffffU >> (4 - uVar20) * 8) & -1 << (uVar4 + 1) * 8 |
                 *(uint *)(psVar13->write_sequence + 7 + -uVar4) >> (3 - uVar4) * 8;
      uVar20 = (uint)psVar13->write_sequence & 3;
      puVar5 = psVar13->write_sequence + -uVar20;
      *(uint *)puVar5 = *(uint *)puVar5 & -1 << (4 - uVar20) * 8 | uVar24 >> uVar20 * 8;
      puVar5 = psVar13->write_sequence + 3;
      uVar20 = (uint)puVar5 & 3;
      *(uint *)(puVar5 + -uVar20) =
           *(uint *)(puVar5 + -uVar20) & 0xffffffffU >> (uVar20 + 1) * 8 |
           uVar24 << (3 - uVar20) * 8;
      *(undefined4 *)(psVar13->write_sequence + 4) = uVar11;
    }
    uVar11 = 0x14;
    if (*(int *)(puVar28 + 0x14) == 0) {
      uVar11 = 0x16;
    }
    iVar9 = dtls1_do_write(param_1,uVar11);
    uVar3 = *(ushort *)(puVar28 + 0x28);
    pdVar10 = param_1->d1;
    param_1->enc_write_ctx = pEVar22;
    param_1->write_hash = pEVar19;
    param_1->compress = pCVar31;
    param_1->session = pSVar30;
    pdVar10->w_epoch = uVar2;
    if (uVar29 == uVar3) {
      uVar20 = *(uint *)param_1->s3->write_sequence;
      uVar11 = *(undefined4 *)(param_1->s3->write_sequence + 4);
      uVar29 = (uint)pdVar10->last_write_sequence & 3;
      puVar5 = pdVar10->last_write_sequence + -uVar29;
      *(uint *)puVar5 = *(uint *)puVar5 & -1 << (4 - uVar29) * 8 | uVar20 >> uVar29 * 8;
      puVar5 = pdVar10->last_write_sequence + 3;
      uVar29 = (uint)puVar5 & 3;
      *(uint *)(puVar5 + -uVar29) =
           *(uint *)(puVar5 + -uVar29) & 0xffffffffU >> (uVar29 + 1) * 8 |
           uVar20 << (3 - uVar29) * 8;
      *(undefined4 *)(pdVar10->last_write_sequence + 4) = uVar11;
      psVar13 = param_1->s3;
      *(undefined4 *)psVar13->write_sequence = local_34;
      *(uint *)(psVar13->write_sequence + 4) = local_30;
      pdVar10 = param_1->d1;
    }
    pdVar10->listen = 0;
    pBVar12 = SSL_get_wbio(param_1);
    param_2 = 0;
    uVar21 = 0;
    iVar18 = 0xb;
    (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar12,0xb);
  }
  if (iVar8 != *(int *)puVar6) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iVar8 = *(int *)(iVar8 + 0x5c);
    *(undefined *)(iVar8 + 0x260) = uVar21;
    *(uint *)(iVar8 + 0x264) = param_2;
    *(undefined **)(iVar8 + 0x26c) = &_gp;
    *(undefined2 *)(iVar8 + 0x268) = *(undefined2 *)(iVar8 + 0x224);
    *(undefined4 *)(iVar8 + 0x270) = uStack_4c;
    return iVar18 + 0xc;
  }
  return iVar9;
}

