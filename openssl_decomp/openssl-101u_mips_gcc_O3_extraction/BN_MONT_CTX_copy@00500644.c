
BN_MONT_CTX * BN_MONT_CTX_copy(BN_MONT_CTX *to,BN_MONT_CTX *from)

{
  BIGNUM *pBVar1;
  BN_MONT_CTX *pBVar2;
  int iVar3;
  
  if (to != from) {
    pBVar1 = BN_copy(&to->RR,&from->RR);
    if ((pBVar1 == (BIGNUM *)0x0) || (pBVar1 = BN_copy(&to->N,&from->N), pBVar1 == (BIGNUM *)0x0)) {
      pBVar2 = (BN_MONT_CTX *)0x0;
    }
    else {
      pBVar1 = BN_copy(&to->Ni,&from->Ni);
      pBVar2 = (BN_MONT_CTX *)0x0;
      if (pBVar1 != (BIGNUM *)0x0) {
        iVar3 = from->ri;
        to->n0[0] = from->n0[0];
        to->ri = iVar3;
        to->n0[1] = from->n0[1];
        pBVar2 = to;
      }
    }
    return pBVar2;
  }
  return to;
}

