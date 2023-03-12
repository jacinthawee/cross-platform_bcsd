
int RSA_padding_add_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl)

{
  uchar uVar1;
  int iVar2;
  uchar *buf;
  uchar *buf_00;
  int num;
  uchar *puVar3;
  
  if (tlen + -10 <= fl) {
    ERR_put_error(4,0x6d,0x6e,"rsa_pk1.c",0x97);
    return 0;
  }
  num = (tlen + -3) - fl;
  buf = to + 2;
  *to = '\0';
  to[1] = '\x02';
  iVar2 = RAND_bytes(buf,num);
  if (iVar2 < 1) {
LAB_000978e4:
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
          if (iVar2 < 1) goto LAB_000978e4;
          uVar1 = *buf_00;
        }
        buf_00 = buf;
      } while (buf != puVar3);
    }
    *buf = '\0';
    memcpy(buf + 1,f,fl);
    iVar2 = 1;
  }
  return iVar2;
}

