
int PEM_write_DHparams(FILE *fp,DH *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(PTR_i2d_DHparams_006a861c,"DH PARAMETERS",fp,x,(EVP_CIPHER *)0x0,
                         (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}
