
PKCS7 * PEM_read_bio_PKCS7(BIO *bp,PKCS7 **x,undefined1 *cb,void *u)

{
  PKCS7 *pPVar1;
  
  pPVar1 = (PKCS7 *)PEM_ASN1_read_bio(PTR_d2i_PKCS7_006a8e48,"PKCS7",bp,x,cb,u);
  return pPVar1;
}
