
RSA * d2i_RSAPrivateKey_bio(BIO *bp,RSA **rsa)

{
  RSA *pRVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058259c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pRVar1 = (RSA *)(*(code *)PTR_ASN1_item_d2i_bio_006a7b78)(PTR_RSAPrivateKey_it_006a8fb0,bp,rsa);
  return pRVar1;
}

