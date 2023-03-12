
BIGNUM * ec_GFp_mont_field_set_to_one(int param_1,BIGNUM *param_2)

{
  BIGNUM *pBVar1;
  
  if (*(BIGNUM **)(param_1 + 0xa4) != (BIGNUM *)0x0) {
    pBVar1 = BN_copy(param_2,*(BIGNUM **)(param_1 + 0xa4));
    if (pBVar1 != (BIGNUM *)0x0) {
      pBVar1 = (BIGNUM *)0x1;
    }
    return pBVar1;
  }
  ERR_put_error(0x10,0xd1,0x6f,"ecp_mont.c",0x12d);
  return (BIGNUM *)0x0;
}

