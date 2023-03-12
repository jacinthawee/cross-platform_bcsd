
PKCS7 * SMIME_read_PKCS7(BIO *bio,BIO **bcont)

{
  PKCS7 *pPVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005a661c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pPVar1 = (PKCS7 *)(*(code *)PTR_SMIME_read_ASN1_006a91c4)(bio,bcont,PTR_PKCS7_it_006a8fa8);
  return pPVar1;
}

