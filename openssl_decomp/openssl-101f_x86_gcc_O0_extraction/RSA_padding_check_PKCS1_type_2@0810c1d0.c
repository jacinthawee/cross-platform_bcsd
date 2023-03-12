
int RSA_padding_check_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  uchar uVar1;
  int iVar2;
  size_t __n;
  uchar *__src;
  uchar *puVar3;
  int iVar4;
  int iVar5;
  
  if ((fl + 1 == rsa_len) && (*f == '\x02')) {
    iVar2 = fl + -1;
    if (iVar2 < 1) {
      if (iVar2 == 0) {
LAB_0810c222:
        iVar5 = 0xcc;
        iVar2 = 0x71;
        goto LAB_0810c277;
      }
    }
    else if (f[1] != '\0') {
      puVar3 = f + 2;
      iVar5 = 0;
      do {
        iVar4 = iVar5;
        iVar5 = iVar4 + 1;
        if (iVar5 == iVar2) goto LAB_0810c222;
        __src = puVar3 + 1;
        uVar1 = *puVar3;
        puVar3 = __src;
      } while (uVar1 != '\0');
      if (7 < iVar5) {
        __n = iVar2 - (iVar4 + 2);
        if ((int)__n <= tlen) {
          memcpy(to,__src,__n);
          return __n;
        }
        iVar5 = 0xd9;
        iVar2 = 0x6d;
        goto LAB_0810c277;
      }
    }
    iVar5 = 0xd2;
    iVar2 = 0x67;
  }
  else {
    iVar5 = 0xbe;
    iVar2 = 0x6b;
  }
LAB_0810c277:
  ERR_put_error(4,0x71,iVar2,"rsa_pk1.c",iVar5);
  return -1;
}

