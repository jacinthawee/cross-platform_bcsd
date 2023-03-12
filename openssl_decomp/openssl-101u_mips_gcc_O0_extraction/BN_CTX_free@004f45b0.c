
void BN_CTX_free(BN_CTX *c)

{
  undefined *puVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *pBVar3;
  
  if (c != (BN_CTX *)0x0) {
    if (*(int *)(c + 0x1c) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(c + 0x14));
    }
    pBVar2 = *(BIGNUM **)c;
    while (pBVar2 != (BIGNUM *)0x0) {
      a = pBVar2;
      do {
        pBVar3 = a + 1;
        if (a->d != (ulong *)0x0) {
          BN_clear_free(a);
        }
        puVar1 = PTR_CRYPTO_free_006a6e88;
        a = pBVar3;
      } while (pBVar3 != pBVar2 + 0x10);
      *(undefined4 *)(c + 4) = *(undefined4 *)(*(int *)c + 0x144);
      (*(code *)puVar1)(*(int *)c);
      pBVar2 = *(BIGNUM **)(c + 4);
      *(BIGNUM **)c = pBVar2;
    }
                    /* WARNING: Could not recover jumptable at 0x004f4658. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(c);
    return;
  }
  return;
}

