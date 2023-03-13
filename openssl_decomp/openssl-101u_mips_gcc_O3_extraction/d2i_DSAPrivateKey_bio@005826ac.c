
DSA * d2i_DSAPrivateKey_bio(BIO *bp,DSA **dsa)

{
  DSA *pDVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005826c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pDVar1 = (DSA *)(*(code *)PTR_ASN1_d2i_bio_006a71c4)
                            (PTR_DSA_new_006a7528,PTR_d2i_DSAPrivateKey_006a8e20,bp,dsa);
  return pDVar1;
}

