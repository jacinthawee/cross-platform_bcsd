
int PEM_write_bio_PKCS7_stream(BIO *out,PKCS7 *p7,BIO *in,int flags)

{
  int iVar1;
  
  iVar1 = PEM_write_bio_ASN1_stream(out,(ASN1_VALUE *)p7,in,flags,"PKCS7",(ASN1_ITEM *)PKCS7_it);
  return iVar1;
}

