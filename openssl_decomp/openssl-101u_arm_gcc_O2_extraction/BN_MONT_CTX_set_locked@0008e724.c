
BN_MONT_CTX * BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont,int lock,BIGNUM *mod,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *a;
  BN_MONT_CTX *pBVar2;
  BIGNUM *a_00;
  BIGNUM *a_01;
  
  CRYPTO_lock(5,lock,"bn_mont.c",0x20f);
  pBVar2 = *pmont;
  CRYPTO_lock(6,lock,"bn_mont.c",0x211);
  if (pBVar2 != (BN_MONT_CTX *)0x0) {
    return pBVar2;
  }
  pBVar2 = (BN_MONT_CTX *)CRYPTO_malloc(0x4c,"bn_mont.c",0x155);
  if (pBVar2 != (BN_MONT_CTX *)0x0) {
    a_01 = &pBVar2->N;
    a = &pBVar2->Ni;
    a_00 = &pBVar2->RR;
    pBVar2->ri = 0;
    BN_init(a_00);
    BN_init(a_01);
    BN_init(a);
    pBVar2->n0[1] = 0;
    pBVar2->n0[0] = 0;
    pBVar2->flags = 1;
    iVar1 = BN_MONT_CTX_set(pBVar2,mod,ctx);
    if (iVar1 != 0) {
      CRYPTO_lock(9,lock,"bn_mont.c",0x226);
      if (*pmont == (BN_MONT_CTX *)0x0) {
        *pmont = pBVar2;
      }
      else {
        BN_clear_free(a_00);
        BN_clear_free(a_01);
        BN_clear_free(a);
        if (pBVar2->flags << 0x1f < 0) {
          CRYPTO_free(pBVar2);
        }
        pBVar2 = *pmont;
      }
      CRYPTO_lock(10,lock,"bn_mont.c",0x22c);
      return pBVar2;
    }
    BN_clear_free(a_00);
    BN_clear_free(a_01);
    BN_clear_free(a);
    if (pBVar2->flags << 0x1f < 0) {
      CRYPTO_free(pBVar2);
      return (BN_MONT_CTX *)0x0;
    }
  }
  return (BN_MONT_CTX *)0x0;
}

