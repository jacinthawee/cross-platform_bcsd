
PKCS8_PRIV_KEY_INFO *
PEM_read_bio_PKCS8_PRIV_KEY_INFO(BIO *bp,PKCS8_PRIV_KEY_INFO **x,undefined1 *cb,void *u)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  
  pPVar1 = (PKCS8_PRIV_KEY_INFO *)
           PEM_ASN1_read_bio(PTR_d2i_PKCS8_PRIV_KEY_INFO_006a8d40,"PRIVATE KEY",bp,x,cb,u);
  return pPVar1;
}
