
DSA * d2i_DSA_PUBKEY_fp(FILE *fp,DSA **dsa)

{
  DSA *pDVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pDVar1 = (DSA *)(*(code *)PTR_ASN1_d2i_fp_006aa0d0)
                            (PTR_DSA_new_006a8624,PTR_d2i_DSA_PUBKEY_006a9f8c,fp,dsa);
  return pDVar1;
}

