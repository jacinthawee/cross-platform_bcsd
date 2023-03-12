
EC_POINT * EC_POINT_hex2point(EC_GROUP *param_1,char *param_2,EC_POINT *param_3,BN_CTX *param_4)

{
  size_t len;
  BIGNUM *a;
  int iVar1;
  int iVar2;
  uchar *to;
  EC_POINT *p;
  BIGNUM *local_24;
  
  local_24 = (BIGNUM *)0x0;
  iVar1 = BN_hex2bn(&local_24,param_2);
  a = local_24;
  if (iVar1 == 0) {
    return (EC_POINT *)0x0;
  }
  iVar2 = BN_num_bits(local_24);
  iVar1 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar1 = iVar2 + 7;
  }
  len = iVar1 >> 3;
  if ((len == 0) || (to = (uchar *)CRYPTO_malloc(len,"ec_print.c",99), to == (uchar *)0x0)) {
    p = (EC_POINT *)0x0;
  }
  else {
    p = (EC_POINT *)BN_bn2bin(a,to);
    if (p == (EC_POINT *)0x0) {
      CRYPTO_free(to);
    }
    else {
      if (param_3 == (EC_POINT *)0x0) {
        p = EC_POINT_new(param_1);
        if ((p != (EC_POINT *)0x0) &&
           (iVar1 = EC_POINT_oct2point(param_1,p,to,len,param_4), iVar1 == 0)) {
          EC_POINT_clear_free(p);
          goto LAB_00092c3a;
        }
      }
      else {
        iVar1 = EC_POINT_oct2point(param_1,param_3,to,len,param_4);
        p = param_3;
        if (iVar1 == 0) {
LAB_00092c3a:
          CRYPTO_free(to);
          BN_clear_free(local_24);
          return (EC_POINT *)0x0;
        }
      }
      CRYPTO_free(to);
    }
  }
  BN_clear_free(local_24);
  return p;
}

