
int i2d_DSAPrivateKey_bio(BIO *bp,DSA *dsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058548c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_DSAPrivateKey_006a9f88,bp,dsa);
  return iVar1;
}
