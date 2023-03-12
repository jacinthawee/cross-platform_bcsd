
int RSA_padding_add_SSLv23(uchar *to,int tlen,uchar *f,int fl)

{
  uchar uVar1;
  int iVar2;
  uchar *buf;
  uchar *buf_00;
  int num;
  uchar *puVar3;
  
  if (tlen + -10 <= fl) {
    ERR_put_error(4,0x6e,0x6e,"rsa_ssl.c",0x49);
    return 0;
  }
  num = (tlen + -0xb) - fl;
  buf = to + 2;
  *to = '\0';
  to[1] = '\x02';
  iVar2 = RAND_bytes(buf,num);
  if (iVar2 < 1) {
LAB_000961a2:
    iVar2 = 0;
  }
  else {
    if (0 < num) {
      puVar3 = buf + num;
      buf_00 = buf;
      do {
        buf = buf_00 + 1;
        uVar1 = *buf_00;
        while (uVar1 == '\0') {
          iVar2 = RAND_bytes(buf_00,1);
          if (iVar2 < 1) goto LAB_000961a2;
          uVar1 = *buf_00;
        }
        buf_00 = buf;
      } while (buf != puVar3);
    }
    memset(buf,3,8);
    buf[8] = '\0';
    memcpy(buf + 9,f,fl);
    iVar2 = 1;
  }
  return iVar2;
}

