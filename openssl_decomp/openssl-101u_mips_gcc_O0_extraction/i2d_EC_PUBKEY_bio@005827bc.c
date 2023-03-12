
int i2d_EC_PUBKEY_bio(BIO *bp,EC_KEY *eckey)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005827d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_EC_PUBKEY_006a8e80,bp,eckey);
  return iVar1;
}

