
char * NETSCAPE_SPKI_b64_encode(NETSCAPE_SPKI *x)

{
  int num;
  uchar *f;
  uchar *t;
  uchar *local_1c [2];
  
  num = i2d_NETSCAPE_SPKI(x,(uchar **)0x0);
  f = (uchar *)CRYPTO_malloc(num,"x509spki.c",0x6e);
  t = (uchar *)CRYPTO_malloc(num << 1,"x509spki.c",0x6f);
  if (f != (uchar *)0x0 && t != (uchar *)0x0) {
    local_1c[0] = f;
    i2d_NETSCAPE_SPKI(x,local_1c);
    EVP_EncodeBlock(t,f,num);
    CRYPTO_free(f);
    return (char *)t;
  }
  ERR_put_error(0xb,0x82,0x41,"x509spki.c",0x71);
  return (char *)0x0;
}

