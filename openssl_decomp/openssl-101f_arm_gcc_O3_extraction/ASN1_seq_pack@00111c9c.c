
uchar * ASN1_seq_pack(stack_st_OPENSSL_BLOCK *safes,undefined1 *i2d,uchar **buf,int *len)

{
  int num;
  uchar *puVar1;
  uchar *local_24;
  
  num = i2d_ASN1_SET(safes,(uchar **)0x0,i2d,0x10,0,0);
  if (num != 0) {
    puVar1 = (uchar *)CRYPTO_malloc(num,"asn_pack.c",0x5f);
    if (puVar1 == (uchar *)0x0) {
      ERR_put_error(0xd,0x7e,0x41,"asn_pack.c",0x60);
    }
    else {
      local_24 = puVar1;
      i2d_ASN1_SET(safes,&local_24,i2d,0x10,0,0);
      if (len != (int *)0x0) {
        *len = num;
      }
      if (buf != (uchar **)0x0) {
        *buf = puVar1;
      }
    }
    return puVar1;
  }
  ERR_put_error(0xd,0x7e,0x70,"asn_pack.c",0x5c);
  return (uchar *)0x0;
}

