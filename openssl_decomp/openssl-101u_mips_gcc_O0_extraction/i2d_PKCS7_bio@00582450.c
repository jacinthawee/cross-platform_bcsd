
int i2d_PKCS7_bio(BIO *bp,PKCS7 *p7)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00582464. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_bio_006a7720)(PTR_PKCS7_it_006a8fa8,bp,p7);
  return iVar1;
}
