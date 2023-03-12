
DSA * get_dsa1024(void)

{
  DSA *pDVar1;
  BIGNUM *pBVar2;
  
  pDVar1 = DSA_new();
  if (pDVar1 != (DSA *)0x0) {
    pBVar2 = BN_bin2bn(PTR_dsa1024_priv_0002c724,0x14,(BIGNUM *)0x0);
    pDVar1->priv_key = pBVar2;
    pBVar2 = BN_bin2bn(PTR_dsa1024_pub_0002c728,0x80,(BIGNUM *)0x0);
    pDVar1->pub_key = pBVar2;
    pBVar2 = BN_bin2bn(PTR_dsa1024_p_0002c72c,0x80,(BIGNUM *)0x0);
    pDVar1->p = pBVar2;
    pBVar2 = BN_bin2bn(PTR_dsa1024_q_0002c730,0x14,(BIGNUM *)0x0);
    pDVar1->q = pBVar2;
    pBVar2 = BN_bin2bn(PTR_dsa1024_g_0002c734,0x80,(BIGNUM *)0x0);
    pDVar1->g = pBVar2;
    if ((((pDVar1->priv_key != (BIGNUM *)0x0) && (pDVar1->pub_key != (BIGNUM *)0x0)) &&
        (pDVar1->p != (BIGNUM *)0x0)) && ((pDVar1->q != (BIGNUM *)0x0 && (pBVar2 != (BIGNUM *)0x0)))
       ) {
      return pDVar1;
    }
  }
  return (DSA *)0x0;
}
