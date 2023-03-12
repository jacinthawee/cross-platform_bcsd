
DSA * d2i_DSA_PUBKEY_fp(FILE *fp,DSA **dsa)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_d2i_fp(DSA_new,d2i_DSA_PUBKEY,fp,dsa);
  return pDVar1;
}

