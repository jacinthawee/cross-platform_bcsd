
DH * PEM_read_DHparams(FILE *fp,DH **x,undefined1 *cb,void *u)

{
  DH *pDVar1;
  
  pDVar1 = (DH *)PEM_ASN1_read(d2i_DHparams + 1,"DH PARAMETERS",fp,x,cb,u);
  return pDVar1;
}

