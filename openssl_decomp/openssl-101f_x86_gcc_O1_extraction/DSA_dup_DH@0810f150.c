
DH * DSA_dup_DH(DSA *r)

{
  DH *dh;
  BIGNUM *pBVar1;
  int iVar2;
  
  if (r == (DSA *)0x0) {
    return (DH *)0x0;
  }
  dh = DH_new();
  if (dh == (DH *)0x0) {
    return (DH *)0x0;
  }
  if (r->p != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(r->p);
    dh->p = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_0810f210;
  }
  if (r->q != (BIGNUM *)0x0) {
    iVar2 = BN_num_bits(r->q);
    dh->length = iVar2;
    pBVar1 = BN_dup(r->q);
    dh->q = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_0810f210;
  }
  if (r->g != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(r->g);
    dh->g = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_0810f210;
  }
  if (r->pub_key != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(r->pub_key);
    dh->pub_key = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) goto LAB_0810f210;
  }
  if (r->priv_key != (BIGNUM *)0x0) {
    pBVar1 = BN_dup(r->priv_key);
    dh->priv_key = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) {
LAB_0810f210:
      DH_free(dh);
      return (DH *)0x0;
    }
  }
  return dh;
}

