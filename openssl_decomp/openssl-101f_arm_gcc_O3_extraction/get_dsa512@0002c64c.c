
DSA * get_dsa512(void)

{
  DSA *pDVar1;
  BIGNUM *pBVar2;
  
  pDVar1 = DSA_new();
  if (pDVar1 != (DSA *)0x0) {
    pBVar2 = BN_bin2bn(&dsa512_priv,0x14,(BIGNUM *)0x0);
    pDVar1->priv_key = pBVar2;
    pBVar2 = BN_bin2bn(PTR_dsa512_pub_0002c6b4,0x41,(BIGNUM *)0x0);
    pDVar1->pub_key = pBVar2;
    pBVar2 = BN_bin2bn(PTR_dsa512_p_0002c6b8,0x40,(BIGNUM *)0x0);
    pDVar1->p = pBVar2;
    pBVar2 = BN_bin2bn(PTR_dsa512_q_0002c6bc,0x14,(BIGNUM *)0x0);
    pDVar1->q = pBVar2;
    pBVar2 = BN_bin2bn(PTR_dsa512_g_0002c6c0,0x40,(BIGNUM *)0x0);
    pDVar1->g = pBVar2;
    if ((((pDVar1->priv_key != (BIGNUM *)0x0) && (pDVar1->pub_key != (BIGNUM *)0x0)) &&
        (pDVar1->p != (BIGNUM *)0x0)) && ((pDVar1->q != (BIGNUM *)0x0 && (pBVar2 != (BIGNUM *)0x0)))
       ) {
      return pDVar1;
    }
  }
  return (DSA *)0x0;
}
