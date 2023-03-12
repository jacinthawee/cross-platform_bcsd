
int i2d_X509_CRL_bio(BIO *bp,X509_CRL *crl)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005851a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a8810)(PTR_X509_CRL_it_006aa0bc,bp,crl);
  return iVar1;
}

