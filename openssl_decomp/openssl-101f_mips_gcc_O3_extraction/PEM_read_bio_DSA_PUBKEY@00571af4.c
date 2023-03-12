
DSA * PEM_read_bio_DSA_PUBKEY(BIO *bp,DSA **x,undefined1 *cb,void *u)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)PEM_ASN1_read_bio(PTR_d2i_DSA_PUBKEY_006a9f8c,"PUBLIC KEY",bp,x,cb,u);
  return pDVar1;
}

