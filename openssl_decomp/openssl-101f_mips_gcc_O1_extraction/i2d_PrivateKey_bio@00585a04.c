
int i2d_PrivateKey_bio(BIO *bp,EVP_PKEY *pkey)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a8298)(PTR_i2d_PrivateKey_006a9fcc,bp,pkey);
  return iVar1;
}

