
int i2d_DSA_PUBKEY_bio(BIO *bp,DSA *dsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058271c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_DSA_PUBKEY_006a8e74,bp,dsa);
  return iVar1;
}

