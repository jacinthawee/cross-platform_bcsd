
undefined4 gost_sign_keygen(int param_1)

{
  BIGNUM *pBVar1;
  BN_CTX *ctx;
  
  pBVar1 = BN_new();
  *(BIGNUM **)(param_1 + 0x1c) = pBVar1;
  BN_rand_range(pBVar1,*(BIGNUM **)(param_1 + 0x10));
  ctx = BN_CTX_new();
  if (*(int *)(param_1 + 0x14) != 0) {
    pBVar1 = BN_new();
    *(BIGNUM **)(param_1 + 0x18) = pBVar1;
    BN_mod_exp(pBVar1,*(BIGNUM **)(param_1 + 0x14),*(BIGNUM **)(param_1 + 0x1c),
               *(BIGNUM **)(param_1 + 0xc),ctx);
    BN_CTX_free(ctx);
    return 1;
  }
  ERR_GOST_error(0x6e,0x71,"gost_sign.c",200);
  return 0;
}

