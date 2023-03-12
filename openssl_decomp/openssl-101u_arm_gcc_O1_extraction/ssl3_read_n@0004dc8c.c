
size_t ssl3_read_n(SSL *param_1,size_t param_2,size_t param_3,int param_4)

{
  int *piVar1;
  uchar *__src;
  uchar *puVar2;
  int iVar3;
  BIO *b;
  ulong uVar4;
  size_t __n;
  ssl3_state_st *psVar5;
  uint uVar6;
  size_t sVar7;
  size_t sVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  
  if ((int)param_2 < 1) {
    return param_2;
  }
  psVar5 = param_1->s3;
  puVar2 = (psVar5->rbuf).buf;
  if (puVar2 == (uchar *)0x0) {
    iVar3 = ssl3_setup_read_buffer();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    puVar2 = (psVar5->rbuf).buf;
  }
  __n = (psVar5->rbuf).left;
  uVar6 = 3U - (int)puVar2 & 7;
  if (param_4 == 0) {
    if (__n != 0) {
      iVar3 = (psVar5->rbuf).offset;
      bVar11 = uVar6 != 0;
      uVar9 = uVar6;
      if (bVar11) {
        uVar9 = __n - 4;
      }
      bVar10 = bVar11 && SBORROW4(__n,4);
      if ((!bVar11 || __n == 4) || (int)uVar9 < 0 != bVar10) {
        puVar2 = puVar2 + iVar3;
      }
      __src = puVar2;
      if ((((!bVar11 || __n == 4) || (int)uVar9 < 0 != bVar10) ||
          (__src = puVar2 + iVar3, puVar2[iVar3] != '\x17')) || (CONCAT11(__src[3],__src[4]) < 0x80)
         ) {
        param_1->packet = __src;
        param_1->packet_length = 0;
        goto LAB_0004dce0;
      }
      memmove(puVar2 + uVar6,__src,__n);
      puVar2 = (psVar5->rbuf).buf;
    }
    (psVar5->rbuf).offset = uVar6;
    param_1->packet = puVar2 + uVar6;
    param_1->packet_length = 0;
  }
LAB_0004dce0:
  iVar3 = SSL_version(param_1);
  if ((iVar3 == 0xfeff) || (iVar3 = SSL_version(param_1), iVar3 == 0x100)) {
    if (param_4 != 0) {
      param_4 = 1;
    }
    if (__n != 0) {
      param_4 = 0;
    }
    if (param_4 != 0) {
      return 0;
    }
    bVar11 = param_2 == __n;
    sVar7 = param_2 - __n;
    if ((int)param_2 > (int)__n) {
      bVar11 = __n == 0;
      sVar7 = __n;
    }
    if (!bVar11 && (int)sVar7 < 0 == ((int)param_2 <= (int)__n && SBORROW4(param_2,__n)))
    goto LAB_0004dde6;
  }
  if ((int)__n < (int)param_2) {
    puVar2 = (psVar5->rbuf).buf + uVar6;
    uVar9 = param_1->packet_length;
    if (param_1->packet == puVar2) {
      iVar3 = (psVar5->rbuf).offset;
    }
    else {
      memmove(puVar2,param_1->packet,uVar9 + __n);
      iVar3 = uVar9 + uVar6;
      param_1->packet = puVar2;
      (psVar5->rbuf).offset = iVar3;
    }
    sVar7 = (psVar5->rbuf).len - iVar3;
    if ((int)sVar7 < (int)param_2) {
      ERR_put_error(0x14,0x95,0x44,"s3_pkt.c",0xd8);
      param_2 = 0xffffffff;
    }
    else {
      sVar8 = param_2;
      if (((param_1->read_ahead != 0) || (param_1->method->version == 0xfeff)) &&
         (((int)param_2 <= (int)param_3 && (sVar8 = sVar7, (int)param_3 <= (int)sVar7)))) {
        sVar8 = param_3;
      }
      piVar1 = __errno_location();
LAB_0004dd68:
      do {
        b = param_1->rbio;
        *piVar1 = 0;
        if (b == (BIO *)0x0) {
          ERR_put_error(0x14,0x95,0xd3,"s3_pkt.c",0xf3);
          sVar7 = 0xffffffff;
LAB_0004de30:
          uVar4 = param_1->options;
          (psVar5->rbuf).left = __n;
          if (((((int)(uVar4 << 0x1b) < 0) && (iVar3 = SSL_version(param_1), iVar3 != 0xfeff)) &&
              (iVar3 = SSL_version(param_1), iVar3 != 0x100)) && (uVar9 + __n == 0)) {
            ssl3_release_read_buffer(param_1);
            return sVar7;
          }
          return sVar7;
        }
        param_1->rwstate = 3;
        sVar7 = BIO_read(b,puVar2 + __n + uVar9,sVar8 - __n);
        if ((int)sVar7 < 1) goto LAB_0004de30;
        __n = __n + sVar7;
        iVar3 = SSL_version(param_1);
        if ((iVar3 != 0xfeff) && (iVar3 = SSL_version(param_1), iVar3 != 0x100)) {
          if ((int)param_2 <= (int)__n) break;
          goto LAB_0004dd68;
        }
        if ((int)__n <= (int)param_2) {
          param_2 = __n;
        }
      } while ((int)__n < (int)param_2);
      uVar6 = param_1->packet_length;
      (psVar5->rbuf).left = __n - param_2;
      (psVar5->rbuf).offset = (psVar5->rbuf).offset + param_2;
      param_1->packet_length = param_2 + uVar6;
      param_1->rwstate = 1;
    }
    return param_2;
  }
  param_4 = __n - param_2;
  __n = param_2;
LAB_0004dde6:
  iVar3 = (psVar5->rbuf).offset;
  param_1->packet_length = param_1->packet_length + __n;
  (psVar5->rbuf).left = param_4;
  (psVar5->rbuf).offset = __n + iVar3;
  return __n;
}

