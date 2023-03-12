
int RSA_padding_check_SSLv23(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  int iVar1;
  int iVar2;
  uchar *__src;
  int iVar4;
  size_t __n;
  bool bVar5;
  uchar *puVar3;
  
  if (fl < 10) {
    ERR_put_error(4,0x72,0x6f,"rsa_ssl.c",0x70);
  }
  else {
    if ((fl + 1 != rsa_len) || (*f != '\x02')) {
      ERR_put_error(4,0x72,0x6b,"rsa_ssl.c",0x74);
      return -1;
    }
    iVar2 = fl + -1;
    iVar4 = 0;
    __src = f + 1;
    do {
      puVar3 = __src;
      __src = puVar3 + 1;
      if (*puVar3 == '\0') break;
      iVar4 = iVar4 + 1;
    } while (__src != f + fl);
    bVar5 = SBORROW4(iVar4,iVar2);
    iVar1 = iVar4 - iVar2;
    if (iVar4 != iVar2) {
      bVar5 = SBORROW4(iVar4,7);
      iVar1 = iVar4 + -7;
    }
    if ((iVar4 == iVar2 || iVar4 == 7) || iVar1 < 0 != bVar5) {
      ERR_put_error(4,0x72,0x71,"rsa_ssl.c",0x80);
    }
    else if (((((puVar3[-8] == '\x03') && (puVar3[-7] == '\x03')) && (puVar3[-6] == '\x03')) &&
             ((puVar3[-5] == '\x03' && (puVar3[-4] == '\x03')))) &&
            ((puVar3[-3] == '\x03' && ((puVar3[-2] == '\x03' && (puVar3[-1] == '\x03')))))) {
      ERR_put_error(4,0x72,0x73,"rsa_ssl.c",0x88);
    }
    else {
      __n = iVar2 - (iVar4 + 1);
      if ((int)__n <= tlen) {
        memcpy(to,__src,__n);
        return __n;
      }
      ERR_put_error(4,0x72,0x6d,"rsa_ssl.c",0x8f);
    }
  }
  return -1;
}

