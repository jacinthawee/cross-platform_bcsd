
BIGNUM * EC_POINT_point2bn(EC_GROUP *param_1,EC_POINT *param_2,point_conversion_form_t form,
                          BIGNUM *param_4,BN_CTX *param_5)

{
  size_t len;
  uchar *buf;
  size_t sVar1;
  BIGNUM *pBVar2;
  
  len = EC_POINT_point2oct(param_1,param_2,form,(uchar *)0x0,0,param_5);
  if ((len != 0) &&
     (buf = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(len,"ec_print.c",0x49),
     buf != (uchar *)0x0)) {
    sVar1 = EC_POINT_point2oct(param_1,param_2,form,buf,len,param_5);
    if (sVar1 != 0) {
      pBVar2 = BN_bin2bn(buf,len,param_4);
      (*(code *)PTR_CRYPTO_free_006a7f88)(buf);
      return pBVar2;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(buf);
  }
  return (BIGNUM *)0x0;
}

