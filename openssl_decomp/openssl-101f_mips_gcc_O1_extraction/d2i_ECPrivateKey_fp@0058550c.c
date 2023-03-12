
EC_KEY * d2i_ECPrivateKey_fp(FILE *fp,EC_KEY **eckey)

{
  EC_KEY *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585524. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EC_KEY *)
           (*(code *)PTR_ASN1_d2i_fp_006aa0d0)
                     (PTR_EC_KEY_new_006a82a8,PTR_d2i_ECPrivateKey_006a9f38,fp,eckey);
  return pEVar1;
}

