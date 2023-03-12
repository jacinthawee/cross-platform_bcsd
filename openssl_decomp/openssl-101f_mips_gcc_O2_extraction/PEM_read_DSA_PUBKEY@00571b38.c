
DSA * PEM_read_DSA_PUBKEY(FILE *fp,DSA **x,undefined1 *cb,void *u)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)PEM_ASN1_read(PTR_d2i_DSA_PUBKEY_006a9f8c,"PUBLIC KEY",fp,x,cb,u);
  return pDVar1;
}

