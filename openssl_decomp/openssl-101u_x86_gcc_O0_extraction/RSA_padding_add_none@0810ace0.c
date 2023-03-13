
int RSA_padding_add_none(uchar *to,int tlen,uchar *f,int fl)

{
  int reason;
  int line;
  
  if (tlen < fl) {
    line = 0x45;
    reason = 0x6e;
  }
  else {
    if (tlen <= fl) {
      memcpy(to,f,fl);
      return 1;
    }
    line = 0x4a;
    reason = 0x7a;
  }
  ERR_put_error(4,0x6b,reason,"rsa_none.c",line);
  return 0;
}

