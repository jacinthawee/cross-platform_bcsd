
DH * DSA_dup_DH(DSA *r)

{
  undefined *puVar1;
  DH *dh;
  BIGNUM *pBVar2;
  long lVar3;
  
  if (r == (DSA *)0x0) {
    return (DH *)0x0;
  }
  dh = DH_new();
  if (dh == (DH *)0x0) {
    return (DH *)0x0;
  }
  if (r->p != (BIGNUM *)0x0) {
    pBVar2 = (BIGNUM *)(*(code *)PTR_BN_dup_006a8218)();
    dh->p = pBVar2;
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_005136c8;
  }
  if (r->q != (BIGNUM *)0x0) {
    lVar3 = (*(code *)PTR_BN_num_bits_006a71f4)();
    puVar1 = PTR_BN_dup_006a8218;
    pBVar2 = r->q;
    dh->length = lVar3;
    pBVar2 = (BIGNUM *)(*(code *)puVar1)(pBVar2);
    dh->q = pBVar2;
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_005136c8;
  }
  if (r->g != (BIGNUM *)0x0) {
    pBVar2 = (BIGNUM *)(*(code *)PTR_BN_dup_006a8218)();
    dh->g = pBVar2;
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_005136c8;
  }
  if (r->pub_key != (BIGNUM *)0x0) {
    pBVar2 = (BIGNUM *)(*(code *)PTR_BN_dup_006a8218)();
    dh->pub_key = pBVar2;
    if (pBVar2 == (BIGNUM *)0x0) goto LAB_005136c8;
  }
  if (r->priv_key != (BIGNUM *)0x0) {
    pBVar2 = (BIGNUM *)(*(code *)PTR_BN_dup_006a8218)();
    dh->priv_key = pBVar2;
    if (pBVar2 == (BIGNUM *)0x0) {
LAB_005136c8:
      DH_free(dh);
      return (DH *)0x0;
    }
  }
  return dh;
}

