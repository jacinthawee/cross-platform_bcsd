
int i2d_DSA_PUBKEY_bio(BIO *bp,DSA *dsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005854c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_DSA_PUBKEY_006a9f90,bp,dsa);
  return iVar1;
}

