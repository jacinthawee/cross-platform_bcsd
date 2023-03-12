
PKCS7 * d2i_PKCS7_bio(BIO *bp,PKCS7 **p7)

{
  PKCS7 *pPVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005851f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pPVar1 = (PKCS7 *)(*(code *)PTR_ASN1_item_d2i_bio_006a8c64)(PTR_PKCS7_it_006aa0c0,bp,p7);
  return pPVar1;
}

