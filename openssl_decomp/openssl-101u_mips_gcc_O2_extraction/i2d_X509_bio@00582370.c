
int i2d_X509_bio(BIO *bp,X509 *x509)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582384. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a7720)(PTR_X509_it_006a8f9c,bp,x509);
  return iVar1;
}

