
int RSA_padding_check_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar uVar1;
  int iVar2;
  int iVar3;
  size_t __n;
  uchar *__src;
  uchar *puVar4;
  
  if ((fl + 1 != rsa_len) || (*f != '\x02')) {
    ERR_put_error(4,0x71,0x6b,"rsa_pk1.c",0xbe);
    return -1;
  }
  iVar2 = fl + -1;
  if (iVar2 < 1) {
    iVar3 = 0;
    __src = f + 1;
LAB_00097942:
    if (iVar3 == iVar2) {
      ERR_put_error(4,0x71,0x71,"rsa_pk1.c",0xcc);
      return -1;
    }
  }
  else {
    if (f[1] == '\0') goto LAB_000979b6;
    iVar3 = 0;
    puVar4 = f + 2;
    do {
      iVar3 = iVar3 + 1;
      __src = puVar4;
      if (iVar3 == iVar2) goto LAB_00097942;
      __src = puVar4 + 1;
      uVar1 = *puVar4;
      puVar4 = __src;
    } while (uVar1 != '\0');
  }
  if (7 < iVar3) {
    __n = iVar2 - (iVar3 + 1);
    if ((int)__n <= tlen) {
      memcpy(to,__src,__n);
      return __n;
    }
    ERR_put_error(4,0x71,0x6d,"rsa_pk1.c",0xd9);
    return -1;
  }
LAB_000979b6:
  ERR_put_error(4,0x71,0x67,"rsa_pk1.c",0xd2);
  return -1;
}

