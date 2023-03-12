
int i2d_PKCS12_bio(BIO *bp,PKCS12 *p12)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005aab00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a7720)(PTR_PKCS12_it_006a9244,bp,p12);
  return iVar1;
}

