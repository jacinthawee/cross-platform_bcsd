
int RSA_padding_add_SSLv23(uchar *to,int tlen,uchar *f,int fl)

{
  undefined *puVar1;
  int iVar2;
  uchar *buf;
  int num;
  uchar *puVar3;
  
  if (tlen + -10 <= fl) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x6e,0x6e,"rsa_ssl.c",0x49);
    return 0;
  }
  *to = '\0';
  num = (tlen + -0xb) - fl;
  buf = to + 2;
  to[1] = '\x02';
  iVar2 = RAND_bytes(buf,num);
  if (iVar2 < 1) {
LAB_0050fa68:
    iVar2 = 0;
  }
  else {
    puVar3 = buf;
    if (0 < num) {
      puVar3 = buf + num;
      do {
        while (*buf == '\0') {
          iVar2 = RAND_bytes(buf,1);
          if (iVar2 < 1) goto LAB_0050fa68;
        }
        buf = buf + 1;
      } while (buf != puVar3);
    }
    puVar1 = PTR_memcpy_006a9aec;
    puVar3[8] = '\0';
    *puVar3 = '\x03';
    puVar3[1] = '\x03';
    puVar3[2] = '\x03';
    puVar3[3] = '\x03';
    puVar3[4] = '\x03';
    puVar3[5] = '\x03';
    puVar3[6] = '\x03';
    puVar3[7] = '\x03';
    (*(code *)puVar1)(puVar3 + 9,f,fl);
    iVar2 = 1;
  }
  return iVar2;
}

