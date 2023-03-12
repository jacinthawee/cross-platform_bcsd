
size_t ssl3_read_n(SSL *param_1,size_t param_2,size_t param_3,int param_4)

{
  int *piVar1;
  uchar *__src;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  BIO *b;
  ulong uVar5;
  size_t __n;
  uint uVar6;
  size_t sVar7;
  size_t sVar8;
  uint uVar9;
  ssl3_state_st *psVar10;
  bool bVar11;
  bool bVar12;
  
  if ((int)param_2 < 1) {
    return param_2;
  }
  psVar10 = param_1->s3;
  puVar2 = (psVar10->rbuf).buf;
  if (puVar2 == (uchar *)0x0) {
    iVar4 = ssl3_setup_read_buffer();
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    puVar2 = (psVar10->rbuf).buf;
  }
  __n = (psVar10->rbuf).left;
  uVar6 = 3U - (int)puVar2 & 7;
  if (param_4 == 0) {
    if (__n != 0) {
      iVar4 = (psVar10->rbuf).offset;
      bVar12 = uVar6 != 0;
      uVar9 = uVar6;
      if (bVar12) {
        uVar9 = __n - 4;
      }
      bVar11 = bVar12 && SBORROW4(__n,4);
      if ((!bVar12 || __n == 4) || (int)uVar9 < 0 != bVar11) {
        puVar2 = puVar2 + iVar4;
      }
      __src = puVar2;
      if ((((!bVar12 || __n == 4) || (int)uVar9 < 0 != bVar11) ||
          (__src = puVar2 + iVar4, puVar2[iVar4] != '\x17')) || (CONCAT11(__src[3],__src[4]) < 0x80)
         ) {
        param_1->packet = __src;
        param_1->packet_length = 0;
        goto LAB_000507c8;
      }
      memmove(puVar2 + uVar6,__src,__n);
      puVar2 = (psVar10->rbuf).buf;
    }
    (psVar10->rbuf).offset = uVar6;
    param_1->packet = puVar2 + uVar6;
    param_1->packet_length = 0;
  }
LAB_000507c8:
  iVar4 = SSL_version(param_1);
  if ((iVar4 == 0xfeff) || (iVar4 = SSL_version(param_1), iVar4 == 0x100)) {
    bVar12 = param_2 == __n;
    sVar7 = param_2 - __n;
    if ((int)param_2 > (int)__n) {
      bVar12 = __n == 0;
      sVar7 = __n;
    }
    if (!bVar12 && (int)sVar7 < 0 == ((int)param_2 <= (int)__n && SBORROW4(param_2,__n))) {
      iVar4 = 0;
      goto LAB_000508b6;
    }
  }
  if ((int)__n < (int)param_2) {
    puVar2 = (psVar10->rbuf).buf + uVar6;
    uVar9 = param_1->packet_length;
    if (param_1->packet == puVar2) {
      iVar4 = (psVar10->rbuf).offset;
    }
    else {
      memmove(puVar2,param_1->packet,uVar9 + __n);
      iVar4 = uVar9 + uVar6;
      param_1->packet = puVar2;
      (psVar10->rbuf).offset = iVar4;
    }
    sVar7 = (psVar10->rbuf).len - iVar4;
    if ((int)sVar7 < (int)param_2) {
      ERR_put_error(0x14,0x95,0x44,"s3_pkt.c",0xd6);
      param_2 = 0xffffffff;
    }
    else {
      sVar8 = param_2;
      if (((param_1->read_ahead != 0) && ((int)param_2 <= (int)param_3)) &&
         (sVar8 = sVar7, (int)param_3 <= (int)sVar7)) {
        sVar8 = param_3;
      }
      piVar1 = __errno_location();
LAB_00050848:
      do {
        b = param_1->rbio;
        *piVar1 = 0;
        if (b == (BIO *)0x0) {
          ERR_put_error(0x14,0x95,0xd3,"s3_pkt.c",0xf3);
          sVar7 = 0xffffffff;
LAB_000508f4:
          uVar5 = param_1->options;
          (psVar10->rbuf).left = __n;
          if (((((int)(uVar5 << 0x1b) < 0) && (iVar4 = SSL_version(param_1), iVar4 != 0xfeff)) &&
              (iVar4 = SSL_version(param_1), iVar4 != 0x100)) && (uVar9 + __n == 0)) {
            ssl3_release_read_buffer(param_1);
            return sVar7;
          }
          return sVar7;
        }
        param_1->rwstate = 3;
        sVar7 = BIO_read(b,puVar2 + __n + uVar9,sVar8 - __n);
        if ((int)sVar7 < 1) goto LAB_000508f4;
        __n = __n + sVar7;
        iVar4 = SSL_version(param_1);
        if ((iVar4 != 0xfeff) && (iVar4 = SSL_version(param_1), iVar4 != 0x100)) {
          if ((int)param_2 <= (int)__n) break;
          goto LAB_00050848;
        }
        if ((int)__n <= (int)param_2) {
          param_2 = __n;
        }
      } while ((int)__n < (int)param_2);
      uVar6 = param_1->packet_length;
      (psVar10->rbuf).left = __n - param_2;
      (psVar10->rbuf).offset = (psVar10->rbuf).offset + param_2;
      param_1->packet_length = param_2 + uVar6;
      param_1->rwstate = 1;
    }
    return param_2;
  }
  iVar4 = __n - param_2;
  __n = param_2;
LAB_000508b6:
  iVar3 = (psVar10->rbuf).offset;
  param_1->packet_length = param_1->packet_length + __n;
  (psVar10->rbuf).left = iVar4;
  (psVar10->rbuf).offset = __n + iVar3;
  return __n;
}

