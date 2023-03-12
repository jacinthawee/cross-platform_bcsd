
int i2d_RSA_PUBKEY_bio(BIO *bp,RSA *rsa)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005853d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_RSA_PUBKEY_006a9f84,bp,rsa);
  return iVar1;
}

