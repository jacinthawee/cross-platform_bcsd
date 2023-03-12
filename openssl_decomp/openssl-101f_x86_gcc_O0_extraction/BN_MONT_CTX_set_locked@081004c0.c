
BN_MONT_CTX * __regparm1
BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont,int lock,BIGNUM *mod,BN_CTX *ctx)

{
  BN_MONT_CTX *mont;
  BN_MONT_CTX *pBVar1;
  BN_CTX *in_stack_00000010;
  
  CRYPTO_lock((int)pmont,5,(char *)mod,(int)"bn_mont.c");
  pBVar1 = *(BN_MONT_CTX **)lock;
  if (pBVar1 != (BN_MONT_CTX *)0x0) {
    CRYPTO_lock((int)pmont,6,(char *)mod,(int)"bn_mont.c");
    return pBVar1;
  }
  CRYPTO_lock((int)pmont,6,(char *)mod,(int)"bn_mont.c");
  CRYPTO_lock((int)pmont,9,(char *)mod,(int)"bn_mont.c");
  pBVar1 = *(BN_MONT_CTX **)lock;
  if (pBVar1 == (BN_MONT_CTX *)0x0) {
    mont = (BN_MONT_CTX *)CRYPTO_malloc(0x4c,"bn_mont.c",0x145);
    pmont = (BN_MONT_CTX **)mont;
    if (mont != (BN_MONT_CTX *)0x0) {
      mont->ri = 0;
      BN_init(&mont->RR);
      BN_init(&mont->N);
      BN_init(&mont->Ni);
      mont->n0[1] = 0;
      mont->n0[0] = 0;
      mont->flags = 1;
      pmont = (BN_MONT_CTX **)BN_MONT_CTX_set(mont,(BIGNUM *)ctx,in_stack_00000010);
      pBVar1 = mont;
      if ((BN_MONT_CTX *)pmont == (BN_MONT_CTX *)0x0) {
        BN_MONT_CTX_free(mont);
        pBVar1 = *(BN_MONT_CTX **)lock;
        goto LAB_0810053f;
      }
    }
    *(BN_MONT_CTX **)lock = pBVar1;
  }
LAB_0810053f:
  CRYPTO_lock((int)pmont,10,(char *)mod,(int)"bn_mont.c");
  return pBVar1;
}

