
int i2o_ECPublicKey(EC_KEY *key,uchar **out)

{
  size_t len;
  size_t sVar1;
  undefined4 uVar2;
  uchar *buf;
  undefined4 uVar3;
  
  if (key == (EC_KEY *)0x0) {
    uVar3 = 0x43;
    uVar2 = 0x510;
LAB_00508d50:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x97,uVar3,"ec_asn1.c",uVar2);
    return 0;
  }
  len = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                           *(point_conversion_form_t *)(key + 0x14),(uchar *)0x0,0,(BN_CTX *)0x0);
  if ((out == (uchar **)0x0) || (len == 0)) {
    return len;
  }
  if (*out == (uchar *)0x0) {
    buf = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(len,"ec_asn1.c",0x51c);
    *out = buf;
    if (buf == (uchar *)0x0) {
      len = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x97,0x41,"ec_asn1.c",0x51d);
    }
    else {
      sVar1 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                                 *(point_conversion_form_t *)(key + 0x14),buf,len,(BN_CTX *)0x0);
      if (sVar1 == 0) {
        len = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x97,0x10,"ec_asn1.c",0x524);
        (*(code *)PTR_CRYPTO_free_006a6e88)(*out);
        *out = (uchar *)0x0;
      }
    }
  }
  else {
    sVar1 = EC_POINT_point2oct(*(EC_GROUP **)(key + 4),*(EC_POINT **)(key + 8),
                               *(point_conversion_form_t *)(key + 0x14),*out,len,(BN_CTX *)0x0);
    if (sVar1 == 0) {
      uVar3 = 0x10;
      uVar2 = 0x524;
      goto LAB_00508d50;
    }
    *out = *out + len;
  }
  return len;
}

