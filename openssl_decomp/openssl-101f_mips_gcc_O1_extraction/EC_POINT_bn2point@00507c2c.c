
EC_POINT * EC_POINT_bn2point(EC_GROUP *param_1,BIGNUM *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  int iVar1;
  uchar *to;
  int iVar2;
  size_t len;
  
  iVar1 = BN_num_bits(param_2);
  iVar2 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  len = iVar2 >> 3;
  if ((len != 0) &&
     (to = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(len,"ec_print.c",99), to != (uchar *)0x0))
  {
    iVar2 = BN_bn2bin(param_2,to);
    if (iVar2 != 0) {
      if (param_3 == (EC_POINT *)0x0) {
        param_3 = EC_POINT_new(param_1);
        if (param_3 != (EC_POINT *)0x0) {
          iVar2 = EC_POINT_oct2point(param_1,param_3,to,len,param_4);
          if (iVar2 != 0) goto LAB_00507cf4;
          EC_POINT_clear_free(param_3);
        }
      }
      else {
        iVar2 = EC_POINT_oct2point(param_1,param_3,to,len,param_4);
        if (iVar2 != 0) {
LAB_00507cf4:
          (*(code *)PTR_CRYPTO_free_006a7f88)(to);
          return param_3;
        }
      }
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(to);
  }
  return (EC_POINT *)0x0;
}

