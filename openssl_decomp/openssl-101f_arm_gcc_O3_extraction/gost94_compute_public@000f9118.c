
undefined4 gost94_compute_public(int param_1)

{
  BN_CTX *ctx;
  BIGNUM *r;
  
  ctx = BN_CTX_new();
  if (*(int *)(param_1 + 0x14) != 0) {
    r = BN_new();
    *(BIGNUM **)(param_1 + 0x18) = r;
    BN_mod_exp(r,*(BIGNUM **)(param_1 + 0x14),*(BIGNUM **)(param_1 + 0x1c),
               *(BIGNUM **)(param_1 + 0xc),ctx);
    BN_CTX_free(ctx);
    return 1;
  }
  ERR_GOST_error(0x6e,0x71,"gost_sign.c",200);
  return 0;
}

