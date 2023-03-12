
NETSCAPE_SPKI * NETSCAPE_SPKI_b64_decode(char *str,int len)

{
  NETSCAPE_SPKI *t;
  int len_00;
  NETSCAPE_SPKI *pNVar1;
  NETSCAPE_SPKI *local_14;
  
  if (len < 1) {
    len = strlen(str);
  }
  t = (NETSCAPE_SPKI *)CRYPTO_malloc(len + 1,"x509spki.c",0x55);
  if (t == (NETSCAPE_SPKI *)0x0) {
    ERR_put_error(0xb,0x81,0x41,"x509spki.c",0x56);
  }
  else {
    len_00 = EVP_DecodeBlock((uchar *)t,(uchar *)str,len);
    if (len_00 < 0) {
      ERR_put_error(0xb,0x81,0x76,"x509spki.c",0x5c);
      CRYPTO_free(t);
      t = (NETSCAPE_SPKI *)0x0;
    }
    else {
      local_14 = t;
      pNVar1 = d2i_NETSCAPE_SPKI((NETSCAPE_SPKI **)0x0,(uchar **)&local_14,len_00);
      CRYPTO_free(t);
      t = pNVar1;
    }
  }
  return t;
}

