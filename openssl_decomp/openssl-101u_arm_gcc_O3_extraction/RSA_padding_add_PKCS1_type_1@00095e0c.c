
int RSA_padding_add_PKCS1_type_1(uchar *to,int tlen,uchar *f,int fl)

{
  uchar *__s;
  size_t __n;
  
  if (fl < tlen + -10) {
    __n = (tlen + -3) - fl;
    __s = to + 2;
    *to = '\0';
    to[1] = '\x01';
    memset(__s,0xff,__n);
    __s[__n] = '\0';
    memcpy(__s + __n + 1,f,fl);
    return 1;
  }
  ERR_put_error(4,0x6c,0x6e,"rsa_pk1.c",0x4b);
  return 0;
}

