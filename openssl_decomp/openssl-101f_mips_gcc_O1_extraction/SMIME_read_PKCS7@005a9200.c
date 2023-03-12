
PKCS7 * SMIME_read_PKCS7(BIO *bio,BIO **bcont)

{
  PKCS7 *pPVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005a920c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pPVar1 = (PKCS7 *)(*(code *)PTR_SMIME_read_ASN1_006aa2e0)(bio,bcont,PTR_PKCS7_it_006aa0c0);
  return pPVar1;
}

