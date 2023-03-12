
int i2d_X509_bio(BIO *bp,X509 *x509)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00585130. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a8810)(PTR_X509_it_006aa0b4,bp,x509);
  return iVar1;
}

