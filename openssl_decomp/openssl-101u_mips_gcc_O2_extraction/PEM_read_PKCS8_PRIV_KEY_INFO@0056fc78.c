
PKCS8_PRIV_KEY_INFO *
PEM_read_PKCS8_PRIV_KEY_INFO(FILE *fp,PKCS8_PRIV_KEY_INFO **x,undefined1 *cb,void *u)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  
  pPVar1 = (PKCS8_PRIV_KEY_INFO *)
           PEM_ASN1_read(PTR_d2i_PKCS8_PRIV_KEY_INFO_006a8d40,"PRIVATE KEY",fp,x,cb,u);
  return pPVar1;
}

