
EVP_PKEY * d2i_PrivateKey_fp(FILE *fp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582b48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EVP_PKEY *)
           (*(code *)PTR_ASN1_d2i_fp_006a8fb8)
                     (PTR_EVP_PKEY_new_006a7620,PTR_d2i_AutoPrivateKey_006a8fd0,fp,a);
  return pEVar1;
}

