
DSA * d2i_DSAPrivateKey_fp(FILE *fp,DSA **dsa)

{
  DSA *pDVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058264c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pDVar1 = (DSA *)(*(code *)PTR_ASN1_d2i_fp_006a8fb8)
                            (PTR_DSA_new_006a7528,PTR_d2i_DSAPrivateKey_006a8e20,fp,dsa);
  return pDVar1;
}

