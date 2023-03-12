
int i2d_RSAPublicKey_bio(BIO *bp,RSA *rsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005853bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a8810)(PTR_RSAPublicKey_it_006aa0cc,bp,rsa);
  return iVar1;
}

