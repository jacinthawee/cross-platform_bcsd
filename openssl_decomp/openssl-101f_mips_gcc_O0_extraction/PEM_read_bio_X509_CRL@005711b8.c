
X509_CRL * PEM_read_bio_X509_CRL(BIO *bp,X509_CRL **x,undefined1 *cb,void *u)

{
  X509_CRL *pXVar1;
  
  pXVar1 = (X509_CRL *)PEM_ASN1_read_bio(PTR_d2i_X509_CRL_006a9f30,"X509 CRL",bp,x,cb,u);
  return pXVar1;
}
