
DSA * d2i_DSAPrivateKey_fp(FILE *fp,DSA **dsa)

{
  DSA *pDVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005853f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pDVar1 = (DSA *)(*(code *)PTR_ASN1_d2i_fp_006aa0d0)
                            (PTR_DSA_new_006a8624,PTR_d2i_DSAPrivateKey_006a9f3c,fp,dsa);
  return pDVar1;
}

