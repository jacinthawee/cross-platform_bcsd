
int RSA_padding_add_none(uchar *to,int tlen,uchar *f,int fl)

{
  if (tlen < fl) {
    ERR_put_error(4,0x6b,0x6e,"rsa_none.c",0x45);
    return 0;
  }
  if (tlen <= fl) {
    memcpy(to,f,fl);
    return 1;
  }
  ERR_put_error(4,0x6b,0x7a,"rsa_none.c",0x4a);
  return 0;
}

