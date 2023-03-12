
DH * PEM_read_bio_DHparams(BIO *bp,DH **x,undefined1 *cb,void *u)

{
  DH *pDVar1;
  
  pDVar1 = (DH *)PEM_ASN1_read_bio(d2i_DHparams + 1,"DH PARAMETERS",bp,x,cb,u);
  return pDVar1;
}

