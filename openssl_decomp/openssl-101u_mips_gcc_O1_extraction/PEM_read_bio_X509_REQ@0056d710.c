
X509_REQ * PEM_read_bio_X509_REQ(BIO *bp,X509_REQ **x,undefined1 *cb,void *u)

{
  X509_REQ *pXVar1;
  
  pXVar1 = (X509_REQ *)PEM_ASN1_read_bio(PTR_d2i_X509_REQ_006a8e3c,"CERTIFICATE REQUEST",bp,x,cb,u);
  return pXVar1;
}
