
DSA * d2i_DSAPrivateKey_bio(BIO *bp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_bio(DSA_new,d2i_DSAPrivateKey,bp,dsa);
  return pDVar1;
}

