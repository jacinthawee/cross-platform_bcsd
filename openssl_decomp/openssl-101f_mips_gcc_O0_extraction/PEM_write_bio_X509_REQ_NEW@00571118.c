
int PEM_write_bio_X509_REQ_NEW(BIO *bp,X509_REQ *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio(PTR_i2d_X509_REQ_006a9f5c,"NEW CERTIFICATE REQUEST",bp,x,
                             (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}
