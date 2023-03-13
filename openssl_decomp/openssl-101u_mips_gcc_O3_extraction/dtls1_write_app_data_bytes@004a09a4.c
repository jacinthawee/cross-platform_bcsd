
int dtls1_write_app_data_bytes(SSL *param_1,int param_2,uchar *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  COMP_CTX *pCVar5;
  int iVar6;
  ssl3_state_st *psVar7;
  uint uVar8;
  undefined4 uVar9;
  ssl3_state_st *psVar10;
  uchar *puVar11;
  uchar *puVar12;
  
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    iVar2 = (*param_1->handshake_func)(param_1);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (iVar2 == 0) {
      uVar9 = 0xe5;
      uVar3 = 0x5c2;
      goto LAB_004a0cf8;
    }
  }
  if ((int)param_4 < 0x4001) {
    param_1->rwstate = 1;
    if ((param_1->s3->wbuf).left != 0) {
      OpenSSLDie("d1_pkt.c",0x60f,"0");
      iVar2 = ssl3_write_pending(param_1,param_2,param_3,param_4);
      return iVar2;
    }
    if ((param_1->s3->alert_dispatch != 0) &&
       (iVar2 = (*param_1->method->ssl_dispatch_alert)(param_1), iVar2 < 1)) {
      return iVar2;
    }
    if (param_4 == 0) {
      return 0;
    }
    psVar10 = param_1->s3;
    if (((param_1->session == (SSL_SESSION *)0x0) ||
        (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) ||
       (iVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1->write_hash), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1->write_hash);
      iVar2 = (*(code *)PTR_EVP_MD_size_006a7e3c)(uVar3);
      if (iVar2 < 0) {
        return -1;
      }
    }
    puVar11 = (psVar10->wbuf).buf;
    *puVar11 = (uchar)param_2;
    iVar4 = param_1->version;
    (psVar10->wrec).type = param_2;
    puVar11[1] = (uchar)((uint)iVar4 >> 8);
    puVar11[2] = (uchar)param_1->version;
    puVar12 = puVar11 + 0xd;
    if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
       (uVar1 = (*(code *)PTR_EVP_CIPHER_flags_006a7544)(param_1->enc_write_ctx->cipher),
       (uVar1 & 2) == 0)) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(code *)PTR_EVP_CIPHER_block_size_006a80f0)(param_1->enc_write_ctx->cipher);
    }
    pCVar5 = param_1->compress;
    (psVar10->wrec).length = param_4;
    (psVar10->wrec).input = param_3;
    (psVar10->wrec).data = puVar12 + iVar4;
    if (pCVar5 == (COMP_CTX *)0x0) {
      (*(code *)PTR_memcpy_006a9aec)(puVar12 + iVar4,param_3,param_4);
      (psVar10->wrec).input = (psVar10->wrec).data;
    }
    else {
      iVar6 = ssl3_do_compress(param_1);
      if (iVar6 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xf5,0x8d,"d1_pkt.c",0x676);
        return -1;
      }
    }
    if (iVar2 != 0) {
      iVar6 = (**(code **)(param_1->method->ssl3_enc + 4))
                        (param_1,puVar12 + iVar4 + (psVar10->wrec).length,1);
      if (iVar6 < 0) {
        return -1;
      }
      (psVar10->wrec).length = (psVar10->wrec).length + iVar2;
    }
    (psVar10->wrec).input = puVar12;
    (psVar10->wrec).data = puVar12;
    if (iVar4 != 0) {
      iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(puVar12,iVar4);
      if (iVar2 < 1) {
        return -1;
      }
      (psVar10->wrec).length = (psVar10->wrec).length + iVar4;
    }
    iVar2 = (**(code **)param_1->method->ssl3_enc)(param_1,1);
    if (iVar2 < 1) {
      return -1;
    }
    puVar11[3] = (uchar)(param_1->d1->w_epoch >> 8);
    puVar11[4] = (uchar)param_1->d1->w_epoch;
    psVar7 = param_1->s3;
    uVar8 = *(uint *)(psVar7->write_sequence + 2);
    puVar12 = puVar11 + 5;
    uVar1 = (uint)puVar12 & 3;
    *(uint *)(puVar12 + -uVar1) =
         *(uint *)(puVar12 + -uVar1) & -1 << (4 - uVar1) * 8 | uVar8 >> uVar1 * 8;
    puVar12 = puVar11 + 8;
    uVar1 = (uint)puVar12 & 3;
    *(uint *)(puVar12 + -uVar1) =
         *(uint *)(puVar12 + -uVar1) & 0xffffffffU >> (uVar1 + 1) * 8 | uVar8 << (3 - uVar1) * 8;
    puVar11[9] = psVar7->write_sequence[6];
    puVar11[10] = psVar7->write_sequence[7];
    puVar11[0xb] = (uchar)((psVar10->wrec).length >> 8);
    puVar11[0xc] = (uchar)(psVar10->wrec).length;
    psVar7 = param_1->s3;
    (psVar10->wrec).type = param_2;
    (psVar10->wrec).length = (psVar10->wrec).length + 0xd;
    ssl3_record_sequence_update(psVar7->write_sequence);
    uVar1 = (psVar10->wrec).length;
    psVar7 = param_1->s3;
    (psVar10->wbuf).offset = 0;
    (psVar10->wbuf).left = uVar1;
    psVar7->wpend_tot = param_4;
    psVar7->wpend_buf = param_3;
    psVar7->wpend_type = param_2;
    psVar7->wpend_ret = param_4;
    iVar2 = ssl3_write_pending(param_1,param_2,param_3,param_4);
    return iVar2;
  }
  uVar9 = 0x14e;
  uVar3 = 0x5c8;
LAB_004a0cf8:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x10c,uVar9,"d1_pkt.c",uVar3);
  return -1;
}

