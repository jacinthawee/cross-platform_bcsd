
int RSA_padding_check_PKCS1_type_1(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  size_t __n;
  int iVar1;
  uchar *puVar2;
  uchar uVar3;
  uchar *__src;
  int iVar4;
  
  if ((fl + 1 != rsa_len) || (puVar2 = f + 1, *f != '\x01')) {
    iVar1 = 0x67;
    iVar4 = 0x6a;
    goto LAB_0810a7dc;
  }
  iVar4 = fl + -1;
  if (iVar4 < 1) {
    if (iVar4 == 0) {
LAB_0810a7f5:
      iVar1 = 0x7d;
      iVar4 = 0x71;
      goto LAB_0810a7dc;
    }
  }
  else {
    uVar3 = f[1];
    __src = f + fl;
    iVar1 = 0;
    if (uVar3 == 0xff) {
      do {
        puVar2 = puVar2 + 1;
        iVar1 = iVar1 + 1;
        if (puVar2 == __src) {
          if (iVar4 != iVar1) goto LAB_0810a786;
          goto LAB_0810a7f5;
        }
        uVar3 = *puVar2;
      } while (uVar3 == 0xff);
    }
    else {
      iVar1 = 0;
    }
    if (uVar3 != '\0') {
      iVar1 = 0x74;
      iVar4 = 0x66;
      goto LAB_0810a7dc;
    }
    __src = puVar2 + 1;
LAB_0810a786:
    if (7 < iVar1) {
      __n = iVar4 - (iVar1 + 1);
      if ((int)__n <= tlen) {
        memcpy(to,__src,__n);
        return __n;
      }
      iVar1 = 0x89;
      iVar4 = 0x6d;
      goto LAB_0810a7dc;
    }
  }
  iVar1 = 0x83;
  iVar4 = 0x67;
LAB_0810a7dc:
  ERR_put_error(4,0x70,iVar4,"rsa_pk1.c",iVar1);
  return -1;
}

