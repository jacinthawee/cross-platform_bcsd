
NETSCAPE_SPKI * NETSCAPE_SPKI_b64_decode(char *str,int len)

{
  uchar *t;
  int len_00;
  NETSCAPE_SPKI *pNVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (len < 1) {
    len = strlen(str);
  }
  t = (uchar *)CRYPTO_malloc(len + 1,"x509spki.c",0x55);
  if (t == (uchar *)0x0) {
    ERR_put_error(0xb,0x81,0x41,"x509spki.c",0x56);
    pNVar1 = (NETSCAPE_SPKI *)0x0;
  }
  else {
    len_00 = EVP_DecodeBlock(t,(uchar *)str,len);
    if (len_00 < 0) {
      ERR_put_error(0xb,0x81,0x76,"x509spki.c",0x5c);
      CRYPTO_free(t);
      pNVar1 = (NETSCAPE_SPKI *)0x0;
    }
    else {
      local_14 = t;
      pNVar1 = d2i_NETSCAPE_SPKI((NETSCAPE_SPKI **)0x0,&local_14,len_00);
      CRYPTO_free(t);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pNVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

