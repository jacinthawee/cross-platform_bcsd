
PKCS7 * PEM_read_PKCS7(FILE *fp,PKCS7 **x,undefined1 *cb,void *u)

{
  PKCS7 *pPVar1;
  
  pPVar1 = (PKCS7 *)PEM_ASN1_read(PTR_d2i_PKCS7_006a8e48,"PKCS7",fp,x,cb,u);
  return pPVar1;
}
