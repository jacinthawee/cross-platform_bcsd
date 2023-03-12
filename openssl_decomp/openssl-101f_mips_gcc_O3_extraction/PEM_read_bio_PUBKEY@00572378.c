
EVP_PKEY * PEM_read_bio_PUBKEY(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  EVP_PKEY *pEVar1;
  
  pEVar1 = (EVP_PKEY *)PEM_ASN1_read_bio(PTR_d2i_PUBKEY_006a9fa0,"PUBLIC KEY",bp,x,cb,u);
  return pEVar1;
}

