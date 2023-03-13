
PKCS7 * SMIME_read_PKCS7(BIO *bio,BIO **bcont)

{
  PKCS7 *pPVar1;
  
  pPVar1 = (PKCS7 *)SMIME_read_ASN1(bio,bcont,(ASN1_ITEM *)PKCS7_it);
  return pPVar1;
}

