
int i2d_ECPrivateKey_bio(BIO *bp,EC_KEY *eckey)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005855b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_ECPrivateKey_006a9f94,bp,eckey);
  return iVar1;
}

