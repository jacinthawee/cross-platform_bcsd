
uint ssl2_write(SSL *param_1,int param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uchar *puVar5;
  uchar *puVar6;
  EVP_MD *md;
  uint uVar7;
  uint uVar8;
  int extraout_r1;
  size_t extraout_r1_00;
  size_t sVar9;
  ssl2_state_st *psVar10;
  uchar *__src;
  size_t sVar11;
  size_t __n;
  uint uVar12;
  int local_30;
  
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    uVar2 = (*param_1->handshake_func)(param_1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (uVar2 == 0) {
      ERR_put_error(0x14,0x7f,0xe5,"s2_pkt.c",0x1ad);
      return 0xffffffff;
    }
  }
  if ((param_1->error != 0) && (ssl2_write_error(param_1), param_1->error != 0)) {
    return 0xffffffff;
  }
  piVar3 = __errno_location();
  *piVar3 = 0;
  param_1->rwstate = 1;
  if ((int)param_3 < 1) {
    return param_3;
  }
  psVar10 = param_1->s2;
  uVar2 = psVar10->wnum;
  psVar10->wnum = 0;
  param_3 = param_3 - uVar2;
  do {
    local_30 = psVar10->wpend_len;
    __src = (uchar *)(param_2 + uVar2);
    if (local_30 == 0) {
      sVar11 = param_3;
      if (psVar10->clear_text == 0) {
        md = EVP_MD_CTX_md(param_1->write_hash);
        local_30 = EVP_MD_size(md);
        if (local_30 < 0) {
          uVar8 = 0xffffffff;
          goto LAB_00047746;
        }
        psVar10 = param_1->s2;
        iVar4 = local_30 + 3;
        if (psVar10->clear_text != 0) goto LAB_00047646;
        uVar8 = EVP_CIPHER_CTX_block_size(param_1->enc_read_ctx);
        psVar10 = param_1->s2;
        iVar4 = psVar10->escape;
        uVar7 = local_30 + param_3;
        if (uVar7 < 0x4000) {
          if ((uVar8 < 2) && (iVar4 == 0)) {
            psVar10->three_byte_header = 0;
            iVar4 = local_30 + 3;
            goto LAB_00047654;
          }
        }
        else if (iVar4 == 0) {
          uVar12 = 0x7fff;
          if (uVar7 < 0x8000) {
            uVar12 = uVar7;
          }
          __aeabi_uidivmod(uVar12,uVar8);
          psVar10->three_byte_header = 0;
          iVar4 = local_30 + 3;
          sVar11 = (uVar12 - extraout_r1) - local_30;
          goto LAB_00047654;
        }
        __aeabi_uidivmod(uVar7,uVar8);
        __n = extraout_r1_00;
        if (extraout_r1_00 != 0) {
          __n = uVar8 - extraout_r1_00;
        }
        sVar9 = 1;
        if ((iVar4 == 0) && (sVar9 = __n, __n != 0)) {
          sVar9 = 1;
        }
        psVar10->three_byte_header = sVar9;
        puVar5 = psVar10->wbuf + local_30 + 3;
        psVar10->wlength = param_3;
        psVar10->padding = __n;
        psVar10->wact_data = puVar5;
        psVar10->mac_data = psVar10->wbuf + 3;
        memcpy(puVar5,__src,param_3);
        if (__n != 0) {
          memset(param_1->s2->wact_data + param_3,0,__n);
        }
      }
      else {
        iVar4 = 3;
LAB_00047646:
        psVar10->three_byte_header = 0;
        sVar11 = 0x7fff;
        if (param_3 < 0x8000) {
          sVar11 = param_3;
        }
LAB_00047654:
        psVar10->wlength = sVar11;
        puVar5 = psVar10->wbuf + iVar4;
        psVar10->padding = 0;
        psVar10->wact_data = puVar5;
        psVar10->mac_data = psVar10->wbuf + 3;
        __n = 0;
        memcpy(puVar5,__src,sVar11);
      }
      psVar10 = param_1->s2;
      if (psVar10->clear_text == 0) {
        psVar10->wact_data_length = __n + sVar11;
        ssl2_mac(param_1,psVar10->mac_data,1);
        param_1->s2->wlength = param_1->s2->wlength + __n + local_30;
        ssl2_enc(param_1,1);
        psVar10 = param_1->s2;
      }
      uVar8 = psVar10->wlength;
      psVar10->wpend_len = uVar8;
      puVar5 = psVar10->mac_data;
      if (psVar10->three_byte_header == 0) {
        puVar6 = puVar5 + -2;
        puVar5[-2] = (byte)(uVar8 >> 8) | 0x80;
        puVar5[-1] = (uchar)param_1->s2->wlength;
        psVar10 = param_1->s2;
        psVar10->wpend_len = psVar10->wpend_len + 2;
      }
      else {
        bVar1 = (byte)((uVar8 << 0x12) >> 0x18);
        puVar5[-3] = bVar1 >> 2;
        psVar10 = param_1->s2;
        puVar6 = puVar5 + -3;
        if (psVar10->escape != 0) {
          puVar5[-3] = bVar1 >> 2 | 0x40;
          psVar10 = param_1->s2;
        }
        puVar5[-2] = (uchar)psVar10->wlength;
        puVar5[-1] = (uchar)param_1->s2->padding;
        psVar10 = param_1->s2;
        psVar10->wpend_len = psVar10->wpend_len + 3;
      }
      psVar10->write_ptr = puVar6;
      psVar10->wpend_tot = param_3;
      psVar10->wpend_buf = __src;
      psVar10->wpend_ret = sVar11;
      psVar10->wpend_off = 0;
      psVar10->write_sequence = psVar10->write_sequence + 1;
      uVar8 = write_pending(param_1,__src,param_3);
    }
    else {
      uVar8 = write_pending(param_1,__src,param_3);
    }
    if ((int)uVar8 < 1) {
LAB_00047746:
      param_1->s2->wnum = uVar2;
      return uVar8;
    }
    if ((param_3 == uVar8) || ((int)(param_1->options << 0x1f) < 0)) {
      return uVar8 + uVar2;
    }
    psVar10 = param_1->s2;
    param_3 = param_3 - uVar8;
    uVar2 = uVar2 + uVar8;
  } while( true );
}

