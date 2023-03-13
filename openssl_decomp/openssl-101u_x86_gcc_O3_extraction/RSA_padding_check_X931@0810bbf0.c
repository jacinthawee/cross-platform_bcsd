
int RSA_padding_check_X931(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar uVar1;
  size_t __n;
  uchar *__src;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((rsa_len != fl) || (1 < (byte)(*f + 0x96))) {
    iVar5 = 0x70;
    iVar4 = 0x89;
    goto LAB_0810bcaf;
  }
  __src = f + 1;
  __n = rsa_len - 2;
  if (*f != 'k') {
LAB_0810bc20:
    if (__src[__n] == 0xcc) {
      memcpy(to,__src,__n);
      return __n;
    }
    iVar5 = 0x8b;
    iVar4 = 0x8b;
    goto LAB_0810bcaf;
  }
  iVar4 = rsa_len + -3;
  if (iVar4 < 1) {
LAB_0810bc94:
    iVar5 = 0x83;
  }
  else {
    if (f[1] == 0xba) goto LAB_0810bc94;
    if (f[1] == 0xbb) {
      iVar5 = 0;
      puVar2 = f + 2;
      do {
        iVar5 = iVar5 + 1;
        __src = puVar2;
        iVar3 = iVar4;
        if (iVar5 == iVar4) {
LAB_0810bc8c:
          __n = iVar4 - iVar3;
          if (iVar3 != 0) goto LAB_0810bc20;
          goto LAB_0810bc94;
        }
        __src = puVar2 + 1;
        uVar1 = *puVar2;
        iVar3 = iVar5;
        if (uVar1 == 0xba) goto LAB_0810bc8c;
        puVar2 = __src;
      } while (uVar1 == 0xbb);
    }
    iVar5 = 0x7b;
  }
  iVar4 = 0x8a;
LAB_0810bcaf:
  ERR_put_error(4,0x80,iVar4,"rsa_x931.c",iVar5);
  return -1;
}

