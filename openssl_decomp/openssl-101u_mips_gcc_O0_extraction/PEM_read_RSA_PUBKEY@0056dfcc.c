
RSA * PEM_read_RSA_PUBKEY(FILE *fp,RSA **x,undefined1 *cb,void *u)

{
  RSA *pRVar1;
  
  pRVar1 = (RSA *)PEM_ASN1_read(PTR_d2i_RSA_PUBKEY_006a8e64,"PUBLIC KEY",fp,x,cb,u);
  return pRVar1;
}

