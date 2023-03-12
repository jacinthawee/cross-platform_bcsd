
int i2d_PKCS8_PRIV_KEY_INFO_bio(BIO *bp,PKCS8_PRIV_KEY_INFO *p8inf)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058596c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_PKCS8_PRIV_KEY_INFO_006a9fc0,bp,p8inf);
  return iVar1;
}

