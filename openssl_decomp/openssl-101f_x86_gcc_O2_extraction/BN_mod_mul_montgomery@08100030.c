
int BN_mod_mul_montgomery(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_MONT_CTX *mont,BN_CTX *ctx)

{
  BIGNUM *r_00;
  int iVar1;
  uint uVar2;
  
  BN_CTX_start(ctx);
  r_00 = BN_CTX_get(ctx);
  if (r_00 != (BIGNUM *)0x0) {
    if (a == b) {
      iVar1 = BN_sqr(r_00,a,ctx);
    }
    else {
      iVar1 = BN_mul(r_00,a,b,ctx);
    }
    if (iVar1 != 0) {
      iVar1 = BN_from_montgomery_word();
      uVar2 = (uint)(iVar1 != 0);
      goto LAB_08100087;
    }
  }
  uVar2 = 0;
LAB_08100087:
  BN_CTX_end(ctx);
  return uVar2;
}

