
DSA * d2i_DSA_PUBKEY_bio(BIO *bp,DSA **dsa)

{
  DSA *pDVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582700. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pDVar1 = (DSA *)(*(code *)PTR_ASN1_d2i_bio_006a71c4)
                            (PTR_DSA_new_006a7528,PTR_d2i_DSA_PUBKEY_006a8e70,bp,dsa);
  return pDVar1;
}

