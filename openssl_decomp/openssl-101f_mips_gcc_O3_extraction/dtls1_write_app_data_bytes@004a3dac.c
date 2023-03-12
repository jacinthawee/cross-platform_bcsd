
int dtls1_write_app_data_bytes(SSL *param_1,int param_2,uchar *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  COMP_CTX *pCVar5;
  ssl3_state_st *psVar6;
  uint uVar7;
  undefined4 uVar8;
  ssl3_state_st *psVar9;
  uchar *puVar10;
  uchar *puVar11;
  int local_2c;
  
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    iVar2 = (*param_1->handshake_func)(param_1);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (iVar2 == 0) {
      uVar8 = 0xe5;
      uVar3 = 0x57f;
      goto LAB_004a40d4;
    }
  }
  if ((int)param_4 < 0x4001) {
    param_1->rwstate = 1;
    if ((param_1->s3->wbuf).left != 0) {
      OpenSSLDie("d1_pkt.c",0x5cc,"0");
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
    psVar9 = param_1->s3;
    if (((param_1->session == (SSL_SESSION *)0x0) ||
        (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0)) ||
       (iVar2 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1->write_hash), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      uVar3 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1->write_hash);
      iVar2 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar3);
      if (iVar2 < 0) {
        return -1;
      }
    }
    puVar10 = (psVar9->wbuf).buf;
    *puVar10 = (uchar)param_2;
    iVar4 = param_1->version;
    (psVar9->wrec).type = param_2;
    puVar10[1] = (uchar)((uint)iVar4 >> 8);
    puVar10[2] = (uchar)param_1->version;
    puVar11 = puVar10 + 0xd;
    if ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) ||
       (uVar1 = (*(code *)PTR_EVP_CIPHER_flags_006a9270)(param_1->enc_write_ctx->cipher),
       (uVar1 & 2) == 0)) {
      local_2c = 0;
    }
    else {
      local_2c = (*(code *)PTR_EVP_CIPHER_block_size_006a921c)(param_1->enc_write_ctx->cipher);
    }
    pCVar5 = param_1->compress;
    (psVar9->wrec).length = param_4;
    (psVar9->wrec).input = param_3;
    (psVar9->wrec).data = puVar11 + local_2c;
    if (pCVar5 == (COMP_CTX *)0x0) {
      (*(code *)PTR_memcpy_006aabf4)(puVar11 + local_2c,param_3,param_4);
      (psVar9->wrec).input = (psVar9->wrec).data;
    }
    else {
      iVar4 = ssl3_do_compress(param_1);
      if (iVar4 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xf5,0x8d,"d1_pkt.c",0x632);
        return -1;
      }
    }
    if (iVar2 != 0) {
      iVar4 = (**(code **)(param_1->method->ssl3_enc + 4))
                        (param_1,puVar11 + local_2c + (psVar9->wrec).length,1);
      if (iVar4 < 0) {
        return -1;
      }
      (psVar9->wrec).length = (psVar9->wrec).length + iVar2;
    }
    (psVar9->wrec).input = puVar11;
    (psVar9->wrec).data = puVar11;
    if (local_2c != 0) {
      (*(code *)PTR_RAND_pseudo_bytes_006a8664)(puVar11,local_2c);
      (psVar9->wrec).length = (psVar9->wrec).length + local_2c;
    }
    (**(code **)param_1->method->ssl3_enc)(param_1,1);
    puVar10[3] = (uchar)(param_1->d1->w_epoch >> 8);
    puVar10[4] = (uchar)param_1->d1->w_epoch;
    psVar6 = param_1->s3;
    uVar7 = *(uint *)(psVar6->write_sequence + 2);
    puVar11 = puVar10 + 5;
    uVar1 = (uint)puVar11 & 3;
    *(uint *)(puVar11 + -uVar1) =
         *(uint *)(puVar11 + -uVar1) & -1 << (4 - uVar1) * 8 | uVar7 >> uVar1 * 8;
    puVar11 = puVar10 + 8;
    uVar1 = (uint)puVar11 & 3;
    *(uint *)(puVar11 + -uVar1) =
         *(uint *)(puVar11 + -uVar1) & 0xffffffffU >> (uVar1 + 1) * 8 | uVar7 << (3 - uVar1) * 8;
    puVar10[9] = psVar6->write_sequence[6];
    puVar10[10] = psVar6->write_sequence[7];
    puVar10[0xb] = (uchar)((psVar9->wrec).length >> 8);
    puVar10[0xc] = (uchar)(psVar9->wrec).length;
    psVar6 = param_1->s3;
    (psVar9->wrec).type = param_2;
    (psVar9->wrec).length = (psVar9->wrec).length + 0xd;
    ssl3_record_sequence_update(psVar6->write_sequence);
    uVar1 = (psVar9->wrec).length;
    psVar6 = param_1->s3;
    (psVar9->wbuf).offset = 0;
    (psVar9->wbuf).left = uVar1;
    psVar6->wpend_tot = param_4;
    psVar6->wpend_buf = param_3;
    psVar6->wpend_type = param_2;
    psVar6->wpend_ret = param_4;
    iVar2 = ssl3_write_pending(param_1,param_2,param_3,param_4);
    return iVar2;
  }
  uVar8 = 0x14e;
  uVar3 = 0x586;
LAB_004a40d4:
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x10c,uVar8,"d1_pkt.c",uVar3);
  return -1;
}

