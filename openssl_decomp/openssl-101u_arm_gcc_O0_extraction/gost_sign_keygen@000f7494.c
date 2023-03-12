
BIGNUM * gost_sign_keygen(int param_1)

{
  BIGNUM *pBVar1;
  BIGNUM *r;
  
  pBVar1 = BN_new();
  *(BIGNUM **)(param_1 + 0x1c) = pBVar1;
  if (pBVar1 != (BIGNUM *)0x0) {
    BN_rand_range(pBVar1,*(BIGNUM **)(param_1 + 0x10));
    pBVar1 = *(BIGNUM **)(param_1 + 0x14);
    if (pBVar1 == (BIGNUM *)0x0) {
      ERR_GOST_error(0x6e,0x71,"gost_sign.c",0xe9);
    }
    else {
      pBVar1 = (BIGNUM *)BN_CTX_new();
      if (pBVar1 == (BIGNUM *)0x0) {
        ERR_GOST_error(0x6e,0x41,"gost_sign.c",0xee);
      }
      else {
        r = BN_new();
        *(BIGNUM **)(param_1 + 0x18) = r;
        if (r == (BIGNUM *)0x0) {
          ERR_GOST_error(0x6e,0x41,"gost_sign.c",0xf4);
          BN_CTX_free((BN_CTX *)pBVar1);
          pBVar1 = r;
        }
        else {
          BN_mod_exp(r,*(BIGNUM **)(param_1 + 0x14),*(BIGNUM **)(param_1 + 0x1c),
                     *(BIGNUM **)(param_1 + 0xc),(BN_CTX *)pBVar1);
          BN_CTX_free((BN_CTX *)pBVar1);
          pBVar1 = (BIGNUM *)0x1;
        }
      }
    }
    return pBVar1;
  }
  ERR_GOST_error(0x8e,0x41,"gost_sign.c",0x128);
  return (BIGNUM *)0x0;
}

