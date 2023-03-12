
int i2d_X509_CRL_bio(BIO *bp,X509_CRL *crl)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005823f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a7720)(PTR_X509_CRL_it_006a8fa4,bp,crl);
  return iVar1;
}

