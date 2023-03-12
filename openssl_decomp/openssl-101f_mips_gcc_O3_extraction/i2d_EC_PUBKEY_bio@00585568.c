
int i2d_EC_PUBKEY_bio(BIO *bp,EC_KEY *eckey)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0058557c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_EC_PUBKEY_006a9f9c,bp,eckey);
  return iVar1;
}

