
int i2o_ECPublicKey(EC_KEY *key,uchar **out)

{
  size_t len;
  size_t sVar1;
  uchar *buf;
  
  if (key == (EC_KEY *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x97,0x43,"ec_asn1.c",0x586);
    return 0;
  }
  len = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                           *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,(BN_CTX *)0x0);
  if ((out == (uchar **)0x0) || (len == 0)) {
    return len;
  }
  if (*out == (uchar *)0x0) {
    buf = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(len,"ec_asn1.c",0x593);
    *out = buf;
    if (buf == (uchar *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x97,0x41,"ec_asn1.c",0x595);
      return 0;
    }
    sVar1 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                               *(point_conversion_form_t *)(key + 0x14),buf,len,(BN_CTX *)0x0);
    if (sVar1 != 0) {
      return len;
    }
  }
  else {
    sVar1 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                               *(point_conversion_form_t *)(key + 0x14),*out,len,(BN_CTX *)0x0);
    if (sVar1 != 0) {
      *out = *out + len;
      return len;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x97,0x10,"ec_asn1.c",0x59d);
  (*(code *)PTR_CRYPTO_free_006a7f88)(*out);
  *out = (uchar *)0x0;
  return 0;
}

