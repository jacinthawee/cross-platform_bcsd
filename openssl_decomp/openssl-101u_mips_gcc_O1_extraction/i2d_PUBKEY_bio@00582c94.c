
int i2d_PUBKEY_bio(BIO *bp,EVP_PKEY *pkey)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582ca8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_PUBKEY_006a8e88,bp,pkey);
  return iVar1;
}

