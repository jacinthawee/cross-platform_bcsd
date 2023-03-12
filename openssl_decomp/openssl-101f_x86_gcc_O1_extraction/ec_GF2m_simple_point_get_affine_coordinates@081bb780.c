
int ec_GF2m_simple_point_get_affine_coordinates
              (EC_GROUP *param_1,EC_POINT *param_2,BIGNUM *param_3,BIGNUM *param_4)

{
  int iVar1;
  BIGNUM *pBVar2;
  int line;
  
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 == 0) {
    pBVar2 = BN_value_one();
    iVar1 = BN_cmp((BIGNUM *)(param_2 + 0x2c),pBVar2);
    if (iVar1 == 0) {
      if (param_3 != (BIGNUM *)0x0) {
        pBVar2 = BN_copy(param_3,(BIGNUM *)(param_2 + 4));
        if (pBVar2 == (BIGNUM *)0x0) {
          return 0;
        }
        BN_set_negative(param_3,0);
      }
      if (param_4 == (BIGNUM *)0x0) {
        iVar1 = 1;
      }
      else {
        pBVar2 = BN_copy(param_4,(BIGNUM *)(param_2 + 0x18));
        if (pBVar2 != (BIGNUM *)0x0) {
          iVar1 = 1;
          BN_set_negative(param_4,0);
        }
      }
      return iVar1;
    }
    line = 0x18e;
    iVar1 = 0x42;
  }
  else {
    line = 0x188;
    iVar1 = 0x6a;
  }
  ERR_put_error(0x10,0xa2,iVar1,"ec2_smpl.c",line);
  return 0;
}

