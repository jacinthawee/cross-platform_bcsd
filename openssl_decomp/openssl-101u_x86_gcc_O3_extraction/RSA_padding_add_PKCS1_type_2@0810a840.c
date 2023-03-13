
int RSA_padding_add_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl)

{
  int iVar1;
  uchar *buf;
  int num;
  uchar *puVar2;
  
  if (tlen + -10 <= fl) {
    ERR_put_error(4,0x6d,0x6e,"rsa_pk1.c",0x99);
    return 0;
  }
  buf = to + 2;
  *to = '\0';
  to[1] = '\x02';
  num = (tlen + -3) - fl;
  iVar1 = RAND_bytes(buf,num);
  if (iVar1 < 1) {
LAB_0810a8c0:
    iVar1 = 0;
  }
  else {
    puVar2 = buf;
    if (0 < num) {
      puVar2 = buf + num;
      do {
        while (*buf == '\0') {
          iVar1 = RAND_bytes(buf,1);
          if (iVar1 < 1) goto LAB_0810a8c0;
        }
        buf = buf + 1;
      } while (buf != puVar2);
    }
    *puVar2 = '\0';
    memcpy(puVar2 + 1,f,fl);
    iVar1 = 1;
  }
  return iVar1;
}

