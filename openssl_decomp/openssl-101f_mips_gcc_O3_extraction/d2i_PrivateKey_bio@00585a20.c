
EVP_PKEY * d2i_PrivateKey_bio(BIO *bp,EVP_PKEY **a)

{
  EVP_PKEY *pEVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585a38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pEVar1 = (EVP_PKEY *)
           (*(code *)PTR_ASN1_d2i_bio_006a82c4)
                     (PTR_EVP_PKEY_new_006a8710,PTR_d2i_AutoPrivateKey_006aa0e8,bp,a);
  return pEVar1;
}

