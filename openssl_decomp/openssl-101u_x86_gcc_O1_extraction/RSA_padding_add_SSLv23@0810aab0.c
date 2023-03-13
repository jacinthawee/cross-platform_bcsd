
int RSA_padding_add_SSLv23(uchar *to,int tlen,uchar *f,int fl)

{
  int iVar1;
  undefined4 *buf;
  int num;
  undefined4 *puVar2;
  
  if (tlen + -10 <= fl) {
    ERR_put_error(4,0x6e,0x6e,"rsa_ssl.c",0x49);
    return 0;
  }
  buf = (undefined4 *)(to + 2);
  *to = '\0';
  to[1] = '\x02';
  num = (tlen + -0xb) - fl;
  iVar1 = RAND_bytes((uchar *)buf,num);
  if (iVar1 < 1) {
LAB_0810ab50:
    iVar1 = 0;
  }
  else {
    puVar2 = buf;
    if (0 < num) {
      puVar2 = (undefined4 *)(num + (int)buf);
      do {
        while (*(char *)buf == '\0') {
          iVar1 = RAND_bytes((uchar *)buf,1);
          if (iVar1 < 1) goto LAB_0810ab50;
        }
        buf = (undefined4 *)((int)buf + 1);
      } while (buf != puVar2);
    }
    *puVar2 = 0x3030303;
    puVar2[1] = 0x3030303;
    *(undefined *)(puVar2 + 2) = 0;
    memcpy((void *)((int)puVar2 + 9),f,fl);
    iVar1 = 1;
  }
  return iVar1;
}

