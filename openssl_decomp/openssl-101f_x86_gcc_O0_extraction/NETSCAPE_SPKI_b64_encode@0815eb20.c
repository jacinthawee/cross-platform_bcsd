
char * NETSCAPE_SPKI_b64_encode(NETSCAPE_SPKI *x)

{
  int num;
  uchar *f;
  uchar *t;
  int in_GS_OFFSET;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  num = i2d_NETSCAPE_SPKI(x,(uchar **)0x0);
  f = (uchar *)CRYPTO_malloc(num,"x509spki.c",0x6e);
  t = (uchar *)CRYPTO_malloc(num * 2,"x509spki.c",0x6f);
  if ((f == (uchar *)0x0) || (t == (uchar *)0x0)) {
    ERR_put_error(0xb,0x82,0x41,"x509spki.c",0x71);
    t = (uchar *)0x0;
  }
  else {
    local_24 = f;
    i2d_NETSCAPE_SPKI(x,&local_24);
    EVP_EncodeBlock(t,f,num);
    CRYPTO_free(f);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (char *)t;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

