
int i2o_ECPublicKey(EC_KEY *key,uchar **out)

{
  size_t len;
  size_t sVar1;
  uchar *buf;
  int reason;
  int line;
  
  if (key == (EC_KEY *)0x0) {
    line = 0x586;
    reason = 0x43;
LAB_081070ff:
    ERR_put_error(0x10,0x97,reason,"ec_asn1.c",line);
    return 0;
  }
  len = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                           *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,(BN_CTX *)0x0);
  if ((out != (uchar **)0x0) && (len != 0)) {
    if (*out == (uchar *)0x0) {
      buf = (uchar *)CRYPTO_malloc(len,"ec_asn1.c",0x593);
      *out = buf;
      if (buf == (uchar *)0x0) {
        line = 0x595;
        reason = 0x41;
        goto LAB_081070ff;
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
    len = 0;
    ERR_put_error(0x10,0x97,0x10,"ec_asn1.c",0x59d);
    CRYPTO_free(*out);
    *out = (uchar *)0x0;
  }
  return len;
}

