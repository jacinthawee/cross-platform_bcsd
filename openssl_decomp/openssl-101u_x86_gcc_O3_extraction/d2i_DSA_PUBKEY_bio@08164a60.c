
DSA * d2i_DSA_PUBKEY_bio(BIO *bp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_bio(DSA_new,d2i_DSA_PUBKEY,bp,dsa);
  return pDVar1;
}

