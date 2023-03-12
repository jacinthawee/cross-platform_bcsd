
int i2d_PKCS8_bio(BIO *bp,X509_SIG *p8)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582a40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_i2d_bio_006a7198)(PTR_i2d_X509_SIG_006a8734,bp,p8);
  return iVar1;
}

