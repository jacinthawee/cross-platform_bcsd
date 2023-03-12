
BN_MONT_CTX * BN_MONT_CTX_copy(BN_MONT_CTX *to,BN_MONT_CTX *from)

{
  BIGNUM *pBVar1;
  
  if (to != from) {
    pBVar1 = BN_copy(&to->RR,&from->RR);
    if (((pBVar1 != (BIGNUM *)0x0) && (pBVar1 = BN_copy(&to->N,&from->N), pBVar1 != (BIGNUM *)0x0))
       && (pBVar1 = BN_copy(&to->Ni,&from->Ni), pBVar1 != (BIGNUM *)0x0)) {
      to->ri = from->ri;
      to->n0[0] = from->n0[0];
      to->n0[1] = from->n0[1];
      return to;
    }
    to = (BN_MONT_CTX *)0x0;
  }
  return to;
}

