
X509 * PEM_read_bio_X509_AUX(BIO *bp,X509 **x,undefined1 *cb,void *u)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)PEM_ASN1_read_bio(PTR_d2i_X509_AUX_006a8e08,"TRUSTED CERTIFICATE",bp,x,cb,u);
  return pXVar1;
}

