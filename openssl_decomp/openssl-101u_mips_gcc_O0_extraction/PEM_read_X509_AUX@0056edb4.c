
X509 * PEM_read_X509_AUX(FILE *fp,X509 **x,undefined1 *cb,void *u)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)PEM_ASN1_read(PTR_d2i_X509_AUX_006a8e08,"TRUSTED CERTIFICATE",fp,x,cb,u);
  return pXVar1;
}

