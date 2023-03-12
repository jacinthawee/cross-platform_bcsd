
int RSA_padding_add_PKCS1_type_1(uchar *to,int tlen,uchar *f,int fl)

{
  size_t __n;
  
  if (fl < tlen + -10) {
    *to = '\0';
    to[1] = '\x01';
    __n = (tlen + -3) - fl;
    memset(to + 2,0xff,__n);
    to[__n + 2] = '\0';
    memcpy(to + __n + 3,f,fl);
    return 1;
  }
  ERR_put_error(4,0x6c,0x6e,"rsa_pk1.c",0x49);
  return 0;
}

