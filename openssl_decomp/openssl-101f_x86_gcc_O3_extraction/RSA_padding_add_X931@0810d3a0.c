
int RSA_padding_add_X931(uchar *to,int tlen,uchar *f,int fl)

{
  uchar *__s;
  int iVar1;
  
  iVar1 = tlen - fl;
  if (iVar1 + -2 < 0) {
    ERR_put_error(4,0x7f,0x6e,"rsa_x931.c",0x50);
    iVar1 = -1;
  }
  else {
    if (iVar1 == 2) {
      *to = 'j';
    }
    else {
      __s = to + 1;
      *to = 'k';
      to = __s;
      if (iVar1 + -2 != 1) {
        to = __s + (iVar1 - 3U);
        memset(__s,0xbb,iVar1 - 3U);
      }
      *to = 0xba;
    }
    memcpy(to + 1,f,fl);
    (to + 1)[fl] = 0xcc;
    iVar1 = 1;
  }
  return iVar1;
}

