
uint ssl2_write(SSL *param_1,int param_2,uint param_3)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  ssl2_state_st *psVar5;
  uint uVar6;
  uchar *__src;
  int iVar7;
  uchar *puVar8;
  EVP_MD *md;
  uint uVar9;
  uchar *puVar10;
  size_t sVar11;
  uint uVar12;
  int local_24;
  
  uVar3 = SSL_state(param_1);
  if (((uVar3 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    uVar3 = (*param_1->handshake_func)(param_1);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    if (uVar3 == 0) {
      ERR_put_error(0x14,0x7f,0xe5,"s2_pkt.c",0x1ad);
      return 0xffffffff;
    }
  }
  if ((param_1->error != 0) && (ssl2_write_error(param_1), param_1->error != 0)) {
    return 0xffffffff;
  }
  piVar4 = __errno_location();
  *piVar4 = 0;
  param_1->rwstate = 1;
  if ((int)param_3 < 1) {
    return param_3;
  }
  psVar5 = param_1->s2;
  uVar3 = psVar5->wnum;
  psVar5->wnum = 0;
  param_3 = param_3 - uVar3;
  do {
    __src = (uchar *)(uVar3 + param_2);
    if (psVar5->wpend_len == 0) {
      iVar7 = 3;
      local_24 = 0;
      sVar11 = param_3;
      if (psVar5->clear_text == 0) {
        md = EVP_MD_CTX_md(param_1->write_hash);
        local_24 = EVP_MD_size(md);
        if (local_24 < 0) {
          uVar6 = 0xffffffff;
          goto LAB_080987b3;
        }
        psVar5 = param_1->s2;
        if (psVar5->clear_text != 0) {
          iVar7 = local_24 + 3;
          goto LAB_08098640;
        }
        uVar9 = EVP_CIPHER_CTX_block_size(param_1->enc_read_ctx);
        psVar5 = param_1->s2;
        uVar6 = param_3 + local_24;
        iVar7 = psVar5->escape;
        if (0x3fff < uVar6) {
          if (iVar7 != 0) goto joined_r0x08098888;
          uVar12 = 0x7fff;
          if (uVar6 < 0x8000) {
            uVar12 = uVar6;
          }
          psVar5->three_byte_header = 0;
          iVar7 = local_24 + 3;
          sVar11 = (uVar12 - uVar12 % uVar9) - local_24;
          goto LAB_08098654;
        }
        if (uVar9 < 2) {
          if (iVar7 == 0) {
            psVar5->three_byte_header = 0;
            iVar7 = local_24 + 3;
            goto LAB_08098654;
          }
joined_r0x08098888:
          uVar12 = uVar6 % uVar9;
          if (uVar12 != 0) goto LAB_0809885d;
LAB_08098861:
          psVar5->three_byte_header = 1;
        }
        else {
          uVar12 = uVar6 % uVar9;
          if (uVar12 != 0) {
LAB_0809885d:
            uVar12 = uVar9 - uVar6 % uVar9;
          }
          if (iVar7 != 0) goto LAB_08098861;
          psVar5->three_byte_header = (uint)(uVar12 != 0);
        }
        psVar5->wlength = param_3;
        psVar5->padding = uVar12;
        puVar8 = psVar5->wbuf + local_24 + 3;
        psVar5->mac_data = psVar5->wbuf + 3;
        psVar5->wact_data = puVar8;
        memcpy(puVar8,__src,param_3);
        if (uVar12 != 0) {
          memset(param_1->s2->wact_data + param_3,0,uVar12);
        }
      }
      else {
LAB_08098640:
        psVar5->three_byte_header = 0;
        sVar11 = 0x7fff;
        if (param_3 < 0x8000) {
          sVar11 = param_3;
        }
LAB_08098654:
        psVar5->wlength = sVar11;
        psVar5->padding = 0;
        puVar8 = psVar5->wbuf + iVar7;
        psVar5->wact_data = puVar8;
        psVar5->mac_data = psVar5->wbuf + 3;
        uVar12 = 0;
        memcpy(puVar8,__src,sVar11);
      }
      psVar5 = param_1->s2;
      if (psVar5->clear_text == 0) {
        psVar5->wact_data_length = sVar11 + uVar12;
        ssl2_mac(param_1,psVar5->mac_data,1);
        puVar1 = &param_1->s2->wlength;
        *puVar1 = *puVar1 + uVar12 + local_24;
        ssl2_enc(param_1,1);
        psVar5 = param_1->s2;
      }
      psVar5->wpend_len = psVar5->wlength;
      puVar8 = psVar5->mac_data;
      bVar2 = (byte)(psVar5->wlength >> 8);
      if (psVar5->three_byte_header == 0) {
        puVar10 = puVar8 + -2;
        puVar8[-2] = bVar2 | 0x80;
        puVar8[-1] = (uchar)param_1->s2->wlength;
        psVar5 = param_1->s2;
        psVar5->wpend_len = psVar5->wpend_len + 2;
      }
      else {
        puVar10 = puVar8 + -3;
        bVar2 = bVar2 & 0x3f;
        puVar8[-3] = bVar2;
        psVar5 = param_1->s2;
        if (psVar5->escape != 0) {
          puVar8[-3] = bVar2 | 0x40;
          psVar5 = param_1->s2;
        }
        puVar8[-2] = (uchar)psVar5->wlength;
        puVar8[-1] = (uchar)param_1->s2->padding;
        psVar5 = param_1->s2;
        psVar5->wpend_len = psVar5->wpend_len + 3;
      }
      psVar5->write_sequence = psVar5->write_sequence + 1;
      psVar5->write_ptr = puVar10;
      psVar5->wpend_tot = param_3;
      psVar5->wpend_ret = sVar11;
      psVar5->wpend_buf = __src;
      psVar5->wpend_off = 0;
      uVar6 = write_pending();
    }
    else {
      uVar6 = write_pending();
    }
    if ((int)uVar6 < 1) {
LAB_080987b3:
      param_1->s2->wnum = uVar3;
      return uVar6;
    }
    if ((param_3 == uVar6) || ((*(byte *)&param_1->options & 1) != 0)) {
      return uVar6 + uVar3;
    }
    uVar3 = uVar3 + uVar6;
    param_3 = param_3 - uVar6;
    psVar5 = param_1->s2;
  } while( true );
}

