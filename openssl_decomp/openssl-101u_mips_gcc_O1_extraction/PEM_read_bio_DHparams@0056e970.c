
DH * PEM_read_bio_DHparams(BIO *bp,DH **x,undefined1 *cb,void *u)

{
  DH *pDVar1;
  
  pDVar1 = (DH *)PEM_ASN1_read_bio(PTR_d2i_DHparams_006a7518,"DH PARAMETERS",bp,x,cb,u);
  return pDVar1;
}

