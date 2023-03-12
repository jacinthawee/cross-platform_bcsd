
int RSA_padding_check_PKCS1_type_1(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar *puVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  uchar uVar4;
  uchar *__src;
  
  if ((fl + 1 != rsa_len) || (__src = f + 1, *f != '\x01')) {
    ERR_put_error(4,0x70,0x6a,"rsa_pk1.c",100);
    return -1;
  }
  iVar2 = fl + -1;
  if (iVar2 < 1) {
    iVar3 = 0;
LAB_000977bc:
    if (iVar3 == iVar2) {
      ERR_put_error(4,0x70,0x71,"rsa_pk1.c",0x7a);
      return -1;
    }
  }
  else {
    uVar4 = f[1];
    if (uVar4 == 0xff) {
      iVar3 = 0;
      puVar1 = f + 2;
      do {
        __src = puVar1;
        iVar3 = iVar3 + 1;
        if (iVar3 == iVar2) goto LAB_000977bc;
        uVar4 = *__src;
        puVar1 = __src + 1;
      } while (uVar4 == 0xff);
    }
    else {
      iVar3 = 0;
    }
    if (uVar4 != '\0') {
      ERR_put_error(4,0x70,0x66,"rsa_pk1.c",0x71);
      return -1;
    }
    __src = __src + 1;
  }
  if (iVar3 < 8) {
    ERR_put_error(4,0x70,0x67,"rsa_pk1.c",0x80);
    __n = 0xffffffff;
  }
  else {
    __n = iVar2 - (iVar3 + 1);
    if (tlen < (int)__n) {
      ERR_put_error(4,0x70,0x6d,"rsa_pk1.c",0x87);
      __n = 0xffffffff;
    }
    else {
      memcpy(to,__src,__n);
    }
  }
  return __n;
}

