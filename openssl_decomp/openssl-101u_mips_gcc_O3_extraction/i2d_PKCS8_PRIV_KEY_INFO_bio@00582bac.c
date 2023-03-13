
int i2d_PKCS8_PRIV_KEY_INFO_bio(BIO *bp,PKCS8_PRIV_KEY_INFO *p8inf)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582bc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_PKCS8_PRIV_KEY_INFO_006a8ea4,bp,p8inf);
  return iVar1;
}

