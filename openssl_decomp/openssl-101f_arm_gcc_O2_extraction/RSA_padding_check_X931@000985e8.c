
int RSA_padding_check_X931(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar uVar1;
  uchar *__src;
  uchar *puVar2;
  int iVar3;
  size_t __n;
  int iVar4;
  
  if ((rsa_len != fl) || (1 < *f - 0x6a)) {
    ERR_put_error(4,0x80,0x89,"rsa_x931.c",0x72);
    return -1;
  }
  if (*f == 0x6b) {
    iVar4 = rsa_len + -3;
    if (0 < iVar4) {
      if (f[1] != 0xba) {
        if (f[1] == 0xbb) {
          iVar3 = 0;
          puVar2 = f + 2;
          do {
            iVar3 = iVar3 + 1;
            __src = puVar2;
            if (iVar3 == iVar4) {
LAB_00098642:
              __n = iVar4 - iVar3;
              if (iVar3 != 0) goto LAB_00098606;
              goto LAB_00098648;
            }
            __src = puVar2 + 1;
            uVar1 = *puVar2;
            if (uVar1 == 0xba) goto LAB_00098642;
            puVar2 = __src;
          } while (uVar1 == 0xbb);
        }
        ERR_put_error(4,0x80,0x8a,"rsa_x931.c",0x81);
        return -1;
      }
    }
LAB_00098648:
    ERR_put_error(4,0x80,0x8a,"rsa_x931.c",0x8a);
    __n = 0xffffffff;
  }
  else {
    __src = f + 1;
    __n = rsa_len - 2;
LAB_00098606:
    if (__src[__n] == 0xcc) {
      memcpy(to,__src,__n);
    }
    else {
      ERR_put_error(4,0x80,0x8b,"rsa_x931.c",0x93);
      __n = 0xffffffff;
    }
  }
  return __n;
}
