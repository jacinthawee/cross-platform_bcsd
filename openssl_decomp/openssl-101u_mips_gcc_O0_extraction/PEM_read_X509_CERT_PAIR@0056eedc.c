
X509_CERT_PAIR * PEM_read_X509_CERT_PAIR(FILE *fp,X509_CERT_PAIR **x,undefined1 *cb,void *u)

{
  X509_CERT_PAIR *pXVar1;
  
  pXVar1 = (X509_CERT_PAIR *)
           PEM_ASN1_read(PTR_d2i_X509_CERT_PAIR_006a8e90,"CERTIFICATE PAIR",fp,x,cb,u);
  return pXVar1;
}
