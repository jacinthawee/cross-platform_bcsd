
RSA * d2i_RSAPublicKey_bio(BIO *bp,RSA **rsa)

{
  RSA *pRVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585380. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar1 = (RSA *)(*(code *)PTR_ASN1_item_d2i_bio_006a8c64)(PTR_RSAPublicKey_it_006aa0cc,bp,rsa);
  return pRVar1;
}

