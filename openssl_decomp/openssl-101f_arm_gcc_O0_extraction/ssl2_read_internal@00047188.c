
void ssl2_read_internal(SSL *param_1,void *param_2,size_t param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  size_t __n;
  EVP_MD *md;
  ssl2_state_st *psVar3;
  int extraout_r1;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uchar *puVar7;
  size_t sVar8;
  uchar *puVar9;
  bool bVar10;
  undefined auStack_40 [20];
  int local_2c;
  
  local_2c = __TMC_END__;
LAB_000471ac:
  do {
    uVar1 = SSL_state(param_1);
    if (((uVar1 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
      __n = (*param_1->handshake_func)(param_1);
      if ((int)__n < 0) goto LAB_000472e2;
      if (__n == 0) {
        ERR_put_error(0x14,0xec,0xe5,"s2_pkt.c",0x8e);
        __n = 0xffffffff;
        goto LAB_000472e2;
      }
    }
    piVar2 = __errno_location();
    *piVar2 = 0;
    param_1->rwstate = 1;
    __n = param_3;
    if ((int)param_3 < 1) goto LAB_000472e2;
    psVar3 = param_1->s2;
    sVar8 = psVar3->ract_data_length;
    if (sVar8 != 0) {
      if ((int)sVar8 <= (int)param_3) {
        __n = sVar8;
      }
      memcpy(param_2,psVar3->ract_data,__n);
      if (param_4 == 0) {
        psVar3 = param_1->s2;
        iVar4 = psVar3->ract_data_length - __n;
        psVar3->ract_data_length = iVar4;
        psVar3->ract_data = psVar3->ract_data + __n;
        if (iVar4 == 0) {
          param_1->rstate = 0xf0;
        }
      }
      goto LAB_000472e2;
    }
    if (param_1->rstate == 0xf0) {
      if (param_1->max_cert_list == 0) {
        __n = read_n(param_1,2,0x8001);
        if ((int)__n < 1) goto LAB_000472e2;
        pbVar5 = param_1->packet;
      }
      else {
        __n = read_n(param_1,5,0x8001,0);
        if ((int)__n < 1) goto LAB_000472e2;
        pbVar5 = param_1->packet;
        param_1->max_cert_list = 0;
        if ((-1 < (char)*pbVar5) || (pbVar5[2] != 4 && pbVar5[2] != 1)) {
          ERR_put_error(0x14,0xec,0xaf,"s2_pkt.c",0xbb);
          __n = 0xffffffff;
          goto LAB_000472e2;
        }
      }
      psVar3 = param_1->s2;
      param_1->rstate = 0xf1;
      psVar3->escape = 0;
      uVar1 = (uint)CONCAT11(*pbVar5,pbVar5[1]);
      psVar3->rlength = uVar1;
      bVar10 = (char)*pbVar5 < '\0';
      if (!bVar10) {
        psVar3->three_byte_header = 1;
        uVar1 = uVar1 & 0x3fff;
      }
      if (bVar10) {
        uVar1 = uVar1 & 0x7fff;
        psVar3->three_byte_header = 0;
      }
      else {
        psVar3->rlength = uVar1;
        pbVar5 = (byte *)(((uint)*pbVar5 << 0x19) >> 0x1f);
      }
      if (bVar10) {
        psVar3->rlength = uVar1;
      }
      if (!bVar10) {
        psVar3->escape = (int)pbVar5;
      }
    }
    else if (param_1->rstate != 0xf1) {
      ERR_put_error(0x14,0xec,0x7e,"s2_pkt.c",0x12f);
      __n = 0xffffffff;
      goto LAB_000472e2;
    }
    uVar1 = psVar3->three_byte_header;
    iVar4 = psVar3->rlength + 2 + uVar1;
    if ((int)param_1->packet_length < iVar4) {
      iVar4 = iVar4 - param_1->packet_length;
      __n = read_n(param_1,iVar4,iVar4,1);
      if ((int)__n < 1) goto LAB_000472e2;
      psVar3 = param_1->s2;
      uVar1 = psVar3->three_byte_header;
    }
    puVar7 = param_1->packet;
    param_1->rstate = 0xf0;
    puVar9 = puVar7 + 2;
    if (uVar1 != 0) {
      uVar1 = (uint)puVar7[2];
      puVar9 = puVar7 + 3;
    }
    psVar3->padding = uVar1;
    if (psVar3->clear_text == 0) {
      md = EVP_MD_CTX_md(param_1->read_hash);
      uVar1 = EVP_MD_size(md);
      if ((int)uVar1 < 0) {
        __n = 0xffffffff;
        goto LAB_000472e2;
      }
      if (0x14 < (int)uVar1) {
        OpenSSLDie("s2_pkt.c",0xfc,"mac_size <= MAX_MAC_SIZE");
      }
      psVar3 = param_1->s2;
      uVar6 = psVar3->rlength;
      psVar3->mac_data = puVar9;
      psVar3->ract_data = puVar9 + uVar1;
      if (uVar6 < psVar3->padding + uVar1) {
        ERR_put_error(0x14,0xec,0x11b,"s2_pkt.c",0x101);
        __n = 0xffffffff;
        goto LAB_000472e2;
      }
      psVar3->ract_data_length = uVar6;
      if ((psVar3->clear_text == 0) && (uVar1 <= uVar6)) {
        ssl2_enc(param_1,0);
        param_1->s2->ract_data_length = param_1->s2->ract_data_length - uVar1;
        ssl2_mac(param_1,auStack_40,0);
        psVar3 = param_1->s2;
        psVar3->ract_data_length = psVar3->ract_data_length - psVar3->padding;
        iVar4 = CRYPTO_memcmp(auStack_40,psVar3->mac_data,uVar1);
        if (iVar4 != 0) {
LAB_00047492:
          ERR_put_error(0x14,0xec,0x71,"s2_pkt.c",0x113);
          __n = 0xffffffff;
LAB_000472e2:
          if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail(__n);
          }
          return;
        }
        uVar1 = param_1->s2->rlength;
        iVar4 = EVP_CIPHER_CTX_block_size(param_1->enc_read_ctx);
        __aeabi_uidivmod(uVar1,iVar4);
        if (extraout_r1 != 0) goto LAB_00047492;
        param_1->s2->read_sequence = param_1->s2->read_sequence + 1;
        goto LAB_000471ac;
      }
    }
    else {
      psVar3->mac_data = puVar9;
      psVar3->ract_data = puVar9;
      if (uVar1 != 0) {
        ERR_put_error(0x14,0xec,0x11b,"s2_pkt.c",0xf3);
        __n = 0xffffffff;
        goto LAB_000472e2;
      }
      psVar3->ract_data_length = psVar3->rlength;
    }
    psVar3->read_sequence = psVar3->read_sequence + 1;
  } while( true );
}

