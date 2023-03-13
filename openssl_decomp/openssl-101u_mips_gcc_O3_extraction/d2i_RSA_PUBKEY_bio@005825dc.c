
RSA * d2i_RSA_PUBKEY_bio(BIO *bp,RSA **rsa)

{
  RSA *pRVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005825f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar1 = (RSA *)(*(code *)PTR_ASN1_d2i_bio_006a71c4)
                            (PTR_RSA_new_006a787c,PTR_d2i_RSA_PUBKEY_006a8e64,bp,rsa);
  return pRVar1;
}

