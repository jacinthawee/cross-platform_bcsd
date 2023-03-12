
BIGNUM * gost94_compute_public(int param_1)

{
  BIGNUM *c;
  BIGNUM *r;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    c = (BIGNUM *)BN_CTX_new();
    if (c == (BIGNUM *)0x0) {
      ERR_GOST_error(0x6e,0x41,"gost_sign.c",0xee);
    }
    else {
      r = BN_new();
      *(BIGNUM **)(param_1 + 0x18) = r;
      if (r == (BIGNUM *)0x0) {
        ERR_GOST_error(0x6e,0x41,"gost_sign.c",0xf4);
        BN_CTX_free((BN_CTX *)c);
        c = r;
      }
      else {
        BN_mod_exp(r,*(BIGNUM **)(param_1 + 0x14),*(BIGNUM **)(param_1 + 0x1c),
                   *(BIGNUM **)(param_1 + 0xc),(BN_CTX *)c);
        BN_CTX_free((BN_CTX *)c);
        c = (BIGNUM *)0x1;
      }
    }
    return c;
  }
  ERR_GOST_error(0x6e,0x71,"gost_sign.c",0xe9);
  return (BIGNUM *)0x0;
}

