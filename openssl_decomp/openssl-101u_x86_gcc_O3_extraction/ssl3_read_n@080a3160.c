
size_t ssl3_read_n(SSL *param_1,size_t param_2,size_t param_3,int param_4)

{
  byte bVar1;
  ssl3_state_st *psVar2;
  uint uVar3;
  BIO *b;
  int iVar4;
  uchar *puVar5;
  int *piVar6;
  size_t sVar7;
  uchar *__src;
  size_t __n;
  uint uVar8;
  size_t local_24;
  
  if ((int)param_2 < 1) {
    return param_2;
  }
  psVar2 = param_1->s3;
  puVar5 = (psVar2->rbuf).buf;
  if (puVar5 == (uchar *)0x0) {
    iVar4 = ssl3_setup_read_buffer(param_1);
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    puVar5 = (psVar2->rbuf).buf;
  }
  uVar8 = -(int)(puVar5 + 5) & 7;
  __n = (psVar2->rbuf).left;
  if (param_4 == 0) {
    if (__n == 0) {
      (psVar2->rbuf).offset = uVar8;
      param_1->packet = puVar5 + uVar8;
      param_1->packet_length = 0;
      iVar4 = SSL_version(param_1);
      if (iVar4 == 0xfeff) goto LAB_080a31e0;
      goto LAB_080a31c1;
    }
    if ((uVar8 == 0) || ((int)__n < 5)) {
      __src = puVar5 + (psVar2->rbuf).offset;
    }
    else {
      __src = puVar5 + (psVar2->rbuf).offset;
      if ((*__src == '\x17') &&
         (0x7f < (ushort)(*(ushort *)(__src + 3) << 8 | *(ushort *)(__src + 3) >> 8))) {
        memmove(puVar5 + uVar8,__src,__n);
        (psVar2->rbuf).offset = uVar8;
        __src = (psVar2->rbuf).buf + uVar8;
      }
    }
    param_1->packet = __src;
    param_1->packet_length = 0;
    iVar4 = SSL_version(param_1);
    if ((iVar4 != 0xfeff) && (iVar4 = SSL_version(param_1), iVar4 != 0x100)) goto LAB_080a31d8;
LAB_080a3428:
    if ((0 < (int)__n) && (iVar4 = 0, (int)__n < (int)param_2)) goto LAB_080a343a;
  }
  else {
    iVar4 = SSL_version(param_1);
    if (iVar4 == 0xfeff) {
LAB_080a3410:
      if ((__n == 0) && (param_4 != 0)) {
        return 0;
      }
      goto LAB_080a3428;
    }
LAB_080a31c1:
    iVar4 = SSL_version(param_1);
    if (iVar4 == 0x100) goto LAB_080a3410;
  }
LAB_080a31d8:
  if ((int)__n < (int)param_2) {
LAB_080a31e0:
    uVar3 = param_1->packet_length;
    puVar5 = (psVar2->rbuf).buf + uVar8;
    if (puVar5 == param_1->packet) {
      iVar4 = (psVar2->rbuf).offset;
    }
    else {
      memmove(puVar5,param_1->packet,__n + uVar3);
      iVar4 = uVar8 + uVar3;
      param_1->packet = puVar5;
      (psVar2->rbuf).offset = iVar4;
    }
    local_24 = (psVar2->rbuf).len - iVar4;
    if ((int)local_24 < (int)param_2) {
      ERR_put_error(0x14,0x95,0x44,"s3_pkt.c",0xd8);
      param_2 = 0xffffffff;
    }
    else {
      if (((param_1->read_ahead == 0) && (param_1->method->version != 0xfeff)) ||
         ((int)param_3 < (int)param_2)) {
        local_24 = param_2;
      }
      else if ((int)param_3 <= (int)local_24) {
        local_24 = param_3;
      }
      piVar6 = __errno_location();
LAB_080a3287:
      do {
        b = param_1->rbio;
        *piVar6 = 0;
        if (b == (BIO *)0x0) {
          ERR_put_error(0x14,0x95,0xd3,"s3_pkt.c",0xf3);
          sVar7 = 0xffffffff;
LAB_080a3396:
          bVar1 = *(byte *)&param_1->options;
          (psVar2->rbuf).left = __n;
          if ((bVar1 & 0x10) == 0) {
            return sVar7;
          }
          iVar4 = SSL_version(param_1);
          if (iVar4 == 0xfeff) {
            return sVar7;
          }
          iVar4 = SSL_version(param_1);
          if (iVar4 == 0x100) {
            return sVar7;
          }
          if (uVar3 + __n != 0) {
            return sVar7;
          }
          ssl3_release_read_buffer(param_1);
          return sVar7;
        }
        param_1->rwstate = 3;
        sVar7 = BIO_read(b,puVar5 + uVar3 + __n,local_24 - __n);
        if ((int)sVar7 < 1) goto LAB_080a3396;
        __n = __n + sVar7;
        iVar4 = SSL_version(param_1);
        if ((iVar4 == 0xfeff) || (iVar4 = SSL_version(param_1), iVar4 == 0x100)) {
          if ((int)__n < (int)param_2) {
            param_2 = __n;
          }
          if ((int)param_2 <= (int)__n) break;
          goto LAB_080a3287;
        }
      } while ((int)__n < (int)param_2);
      piVar6 = &(psVar2->rbuf).offset;
      *piVar6 = *piVar6 + param_2;
      (psVar2->rbuf).left = __n - param_2;
      param_1->packet_length = param_1->packet_length + param_2;
      param_1->rwstate = 1;
    }
    return param_2;
  }
  iVar4 = __n - param_2;
  __n = param_2;
LAB_080a343a:
  param_1->packet_length = param_1->packet_length + __n;
  (psVar2->rbuf).left = iVar4;
  piVar6 = &(psVar2->rbuf).offset;
  *piVar6 = *piVar6 + __n;
  return __n;
}

