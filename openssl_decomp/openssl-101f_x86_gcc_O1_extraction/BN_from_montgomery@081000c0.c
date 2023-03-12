
int BN_from_montgomery(BIGNUM *r,BIGNUM *a,BN_MONT_CTX *mont,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  if (pBVar1 != (BIGNUM *)0x0) {
    pBVar1 = BN_copy(pBVar1,a);
    if (pBVar1 != (BIGNUM *)0x0) {
      iVar2 = BN_from_montgomery_word();
      goto LAB_08100105;
    }
  }
  iVar2 = 0;
LAB_08100105:
  BN_CTX_end(ctx);
  return iVar2;
}

