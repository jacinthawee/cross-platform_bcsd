
int RSA_padding_add_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl)

{
  undefined *puVar1;
  int iVar2;
  uchar *buf;
  int num;
  uchar *puVar3;
  
  if (tlen + -10 <= fl) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x6d,0x6e,"rsa_pk1.c",0x97);
    return 0;
  }
  *to = '\0';
  num = (tlen + -3) - fl;
  buf = to + 2;
  to[1] = '\x02';
  iVar2 = RAND_bytes(buf,num);
  if (iVar2 < 1) {
LAB_00511848:
    iVar2 = 0;
  }
  else {
    puVar3 = buf;
    if (0 < num) {
      puVar3 = buf + num;
      do {
        while (*buf == '\0') {
          iVar2 = RAND_bytes(buf,1);
          if (iVar2 < 1) goto LAB_00511848;
        }
        buf = buf + 1;
      } while (buf != puVar3);
    }
    puVar1 = PTR_memcpy_006aabf4;
    *puVar3 = '\0';
    (*(code *)puVar1)(puVar3 + 1,f,fl);
    iVar2 = 1;
  }
  return iVar2;
}

