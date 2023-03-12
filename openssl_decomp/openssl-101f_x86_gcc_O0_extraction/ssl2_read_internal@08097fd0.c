
size_t __regparm3 ssl2_read_internal(SSL *param_1_00,void *param_2,size_t param_3,int param_1)

{
  byte bVar1;
  uchar *puVar2;
  uint uVar3;
  int *piVar4;
  size_t sVar5;
  EVP_MD *md;
  int iVar6;
  uint uVar7;
  ushort *puVar8;
  uchar *puVar9;
  ssl2_state_st *psVar10;
  size_t sVar11;
  int in_GS_OFFSET;
  int line;
  undefined local_34 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  while( true ) {
    uVar3 = SSL_state(param_1_00);
    if (((uVar3 & 0x3000) != 0) && (param_1_00->in_handshake == 0)) {
      sVar5 = (*param_1_00->handshake_func)(param_1_00);
      if ((int)sVar5 < 0) goto LAB_08098308;
      if (sVar5 == 0) {
        line = 0x8e;
        iVar6 = 0xe5;
        goto LAB_0809837f;
      }
    }
    piVar4 = __errno_location();
    *piVar4 = 0;
    param_1_00->rwstate = 1;
    sVar5 = param_3;
    if ((int)param_3 < 1) goto LAB_08098308;
    psVar10 = param_1_00->s2;
    sVar11 = psVar10->ract_data_length;
    if (sVar11 != 0) break;
    if (param_1_00->rstate == 0xf0) {
      if (param_1_00->max_cert_list == 0) {
        sVar5 = read_n(0);
        if ((int)sVar5 < 1) goto LAB_08098308;
        puVar8 = (ushort *)param_1_00->packet;
      }
      else {
        sVar5 = read_n(0);
        if ((int)sVar5 < 1) goto LAB_08098308;
        puVar8 = (ushort *)param_1_00->packet;
        param_1_00->max_cert_list = 0;
        if ((-1 < (char)*(byte *)puVar8) ||
           ((*(byte *)(puVar8 + 1) != 1 && (*(byte *)(puVar8 + 1) != 4)))) {
          line = 0xbb;
          iVar6 = 0xaf;
          goto LAB_0809837f;
        }
      }
      psVar10 = param_1_00->s2;
      param_1_00->rstate = 0xf1;
      psVar10->escape = 0;
      uVar3 = (uint)(ushort)(*puVar8 << 8 | *puVar8 >> 8);
      psVar10->rlength = uVar3;
      if ((char)*(byte *)puVar8 < '\0') {
        uVar3 = uVar3 & 0x7fff;
        psVar10->three_byte_header = 0;
        sVar5 = 0;
        psVar10->rlength = uVar3;
      }
      else {
        uVar3 = uVar3 & 0x3fff;
        psVar10->three_byte_header = 1;
        sVar11 = 1;
        psVar10->rlength = uVar3;
        psVar10->escape = *(byte *)puVar8 >> 6 & 1;
        sVar5 = 1;
      }
    }
    else {
      if (param_1_00->rstate != 0xf1) {
        line = 0x12f;
        iVar6 = 0x7e;
        goto LAB_0809837f;
      }
      sVar5 = psVar10->three_byte_header;
      uVar3 = psVar10->rlength;
      sVar11 = sVar5;
    }
    if ((int)param_1_00->packet_length < (int)(uVar3 + 2 + sVar5)) {
      sVar5 = read_n(1);
      if ((int)sVar5 < 1) goto LAB_08098308;
      psVar10 = param_1_00->s2;
      sVar11 = psVar10->three_byte_header;
    }
    puVar2 = param_1_00->packet;
    param_1_00->rstate = 0xf0;
    if (sVar11 == 0) {
      puVar9 = puVar2 + 2;
      psVar10->padding = 0;
      if (psVar10->clear_text == 0) goto LAB_08098190;
      psVar10->mac_data = puVar9;
      psVar10->ract_data = puVar9;
LAB_08098013:
      psVar10->ract_data_length = psVar10->rlength;
    }
    else {
      puVar9 = puVar2 + 3;
      bVar1 = puVar2[2];
      psVar10->padding = (uint)bVar1;
      if (psVar10->clear_text != 0) {
        psVar10->mac_data = puVar9;
        psVar10->ract_data = puVar9;
        if (bVar1 == 0) goto LAB_08098013;
        line = 0xf3;
        iVar6 = 0x11b;
LAB_0809837f:
        ERR_put_error(0x14,0xec,iVar6,"s2_pkt.c",line);
        sVar5 = 0xffffffff;
LAB_08098308:
        if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return sVar5;
      }
LAB_08098190:
      md = EVP_MD_CTX_md(param_1_00->read_hash);
      uVar3 = EVP_MD_size(md);
      if ((int)uVar3 < 0) {
        sVar5 = 0xffffffff;
        goto LAB_08098308;
      }
      if (0x14 < (int)uVar3) {
        OpenSSLDie("s2_pkt.c",0xfc,"mac_size <= MAX_MAC_SIZE");
      }
      psVar10 = param_1_00->s2;
      psVar10->mac_data = puVar9;
      uVar7 = psVar10->rlength;
      psVar10->ract_data = puVar9 + uVar3;
      if (uVar7 < psVar10->padding + uVar3) {
        line = 0x101;
        iVar6 = 0x11b;
        goto LAB_0809837f;
      }
      psVar10->ract_data_length = uVar7;
      if ((psVar10->clear_text == 0) && (uVar3 <= uVar7)) {
        ssl2_enc(param_1_00,0);
        piVar4 = &param_1_00->s2->ract_data_length;
        *piVar4 = *piVar4 - uVar3;
        ssl2_mac(param_1_00,local_34,0);
        psVar10 = param_1_00->s2;
        psVar10->ract_data_length = psVar10->ract_data_length - psVar10->padding;
        iVar6 = CRYPTO_memcmp(local_34,psVar10->mac_data,uVar3);
        if ((iVar6 != 0) ||
           (uVar3 = param_1_00->s2->rlength,
           uVar7 = EVP_CIPHER_CTX_block_size(param_1_00->enc_read_ctx), uVar3 % uVar7 != 0)) {
          line = 0x113;
          iVar6 = 0x71;
          goto LAB_0809837f;
        }
        psVar10 = param_1_00->s2;
      }
    }
    psVar10->read_sequence = psVar10->read_sequence + 1;
  }
  if ((int)sVar11 < (int)param_3) {
    param_3 = sVar11;
  }
  memcpy(param_2,psVar10->ract_data,param_3);
  sVar5 = param_3;
  if (param_1 == 0) {
    psVar10 = param_1_00->s2;
    psVar10->ract_data = psVar10->ract_data + param_3;
    iVar6 = psVar10->ract_data_length - param_3;
    psVar10->ract_data_length = iVar6;
    if (iVar6 == 0) {
      param_1_00->rstate = 0xf0;
    }
  }
  goto LAB_08098308;
}

