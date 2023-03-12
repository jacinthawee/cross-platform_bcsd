
BN_MONT_CTX * BN_MONT_CTX_set_locked(BN_MONT_CTX **pmont,int lock,BIGNUM *mod,BN_CTX *ctx)

{
  BN_MONT_CTX *mont;
  int iVar1;
  BN_MONT_CTX *pBVar2;
  
  (*(code *)PTR_CRYPTO_lock_006a926c)(5,lock,"bn_mont.c",0x1e4);
  pBVar2 = *pmont;
  if (pBVar2 != (BN_MONT_CTX *)0x0) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(6,lock,"bn_mont.c",0x1fa);
    return pBVar2;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(6,lock,"bn_mont.c",0x1e7);
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,lock,"bn_mont.c",0x1e8);
  pBVar2 = *pmont;
  if (pBVar2 == (BN_MONT_CTX *)0x0) {
    mont = (BN_MONT_CTX *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x4c,"bn_mont.c",0x145);
    if (mont != (BN_MONT_CTX *)0x0) {
      mont->ri = 0;
      BN_init(&mont->RR);
      BN_init(&mont->N);
      BN_init(&mont->Ni);
      mont->n0[1] = 0;
      mont->n0[0] = 0;
      mont->flags = 1;
      iVar1 = BN_MONT_CTX_set(mont,mod,ctx);
      pBVar2 = mont;
      if (iVar1 == 0) {
        BN_MONT_CTX_free(mont);
        pBVar2 = *pmont;
        goto LAB_00502dfc;
      }
    }
    *pmont = pBVar2;
  }
LAB_00502dfc:
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,lock,"bn_mont.c",0x1f8);
  return pBVar2;
}

