
EVP_PKEY * PEM_read_PUBKEY(FILE *fp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)PEM_ASN1_read(PTR_d2i_PUBKEY_006a9fa0,"PUBLIC KEY",fp,x,cb,u);
  return pEVar1;
}

