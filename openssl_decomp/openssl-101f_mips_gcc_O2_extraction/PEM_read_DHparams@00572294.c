
DH * PEM_read_DHparams(FILE *fp,DH **x,undefined1 *cb,void *u)

{
  DH *pDVar1;
  
  pDVar1 = (DH *)PEM_ASN1_read(PTR_d2i_DHparams_006a8614,"DH PARAMETERS",fp,x,cb,u);
  return pDVar1;
}

