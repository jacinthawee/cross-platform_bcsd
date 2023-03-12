
int i2o_ECPublicKey(EC_KEY *key,uchar **out)

{
  uchar *len;
  uchar *puVar1;
  
  if (key == (EC_KEY *)0x0) {
    ERR_put_error(0x10,0x97,0x43,"ec_asn1.c",0x510);
    return 0;
  }
  len = (uchar *)EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                    *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,
                                    (BN_CTX *)0x0);
  if (out != (uchar **)0x0 && len != (uchar *)0x0) {
    if (*out == (uchar *)0x0) {
      puVar1 = (uchar *)CRYPTO_malloc((int)len,"ec_asn1.c",0x51c);
      *out = puVar1;
      if (puVar1 == (uchar *)0x0) {
        ERR_put_error(0x10,0x97,0x41,"ec_asn1.c",0x51d);
        len = puVar1;
      }
      else {
        puVar1 = (uchar *)EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                             *(point_conversion_form_t *)(key + 0x14),puVar1,
                                             (size_t)len,(BN_CTX *)0x0);
        if (puVar1 == (uchar *)0x0) {
          ERR_put_error(0x10,0x97,0x10,"ec_asn1.c",0x524);
          CRYPTO_free(*out);
          *out = (uchar *)0x0;
          len = puVar1;
        }
      }
    }
    else {
      puVar1 = (uchar *)EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                           *(point_conversion_form_t *)(key + 0x14),*out,(size_t)len
                                           ,(BN_CTX *)0x0);
      if (puVar1 == (uchar *)0x0) {
        ERR_put_error(0x10,0x97,0x10,"ec_asn1.c",0x524);
        len = puVar1;
      }
      else {
        *out = *out + (int)len;
      }
    }
  }
  return (int)len;
}

