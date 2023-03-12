
BN_CTX * ec_GF2m_simple_make_affine(EC_GROUP *param_1,EC_POINT *param_2,BN_CTX *param_3)

{
  BIGNUM *pBVar1;
  BIGNUM *b;
  int iVar2;
  BN_CTX *pBVar3;
  BN_CTX *c;
  
  if ((*(int *)(param_2 + 0x40) == 0) &&
     (pBVar3 = (BN_CTX *)EC_POINT_is_at_infinity(param_1,param_2), pBVar3 == (BN_CTX *)0x0)) {
    c = pBVar3;
    if ((param_3 != (BN_CTX *)0x0) ||
       (param_3 = BN_CTX_new(), c = param_3, param_3 != (BN_CTX *)0x0)) {
      BN_CTX_start(param_3);
      pBVar1 = BN_CTX_get(param_3);
      b = BN_CTX_get(param_3);
      if ((b == (BIGNUM *)0x0) ||
         (((iVar2 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_2,pBVar1,b,param_3),
           iVar2 == 0 || (pBVar1 = BN_copy((BIGNUM *)(param_2 + 4),pBVar1), pBVar1 == (BIGNUM *)0x0)
           ) || (pBVar1 = BN_copy((BIGNUM *)(param_2 + 0x18),b), pBVar1 == (BIGNUM *)0x0)))) {
        pBVar3 = (BN_CTX *)0x0;
      }
      else {
        pBVar3 = (BN_CTX *)BN_set_word((BIGNUM *)(param_2 + 0x2c),1);
        if (pBVar3 != (BN_CTX *)0x0) {
          pBVar3 = (BN_CTX *)0x1;
        }
      }
      BN_CTX_end(param_3);
      if (c != (BN_CTX *)0x0) {
        BN_CTX_free(c);
        return pBVar3;
      }
    }
  }
  else {
    pBVar3 = (BN_CTX *)0x1;
  }
  return pBVar3;
}

