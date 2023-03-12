
EVP_PKEY * d2i_PUBKEY_fp(FILE *fp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582b84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EVP_PKEY *)
           (*(code *)PTR_ASN1_d2i_fp_006a8fb8)
                     (PTR_EVP_PKEY_new_006a7620,PTR_d2i_PUBKEY_006a8e84,fp,a);
  return pEVar1;
}

