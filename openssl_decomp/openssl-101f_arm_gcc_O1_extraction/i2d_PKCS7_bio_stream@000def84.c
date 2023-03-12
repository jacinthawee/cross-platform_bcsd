
int i2d_PKCS7_bio_stream(BIO *out,PKCS7 *p7,BIO *in,int flags)

{
  int iVar1;
  
  iVar1 = i2d_ASN1_bio_stream(out,(ASN1_VALUE *)p7,in,flags,(ASN1_ITEM *)&PKCS7_it);
  return iVar1;
}

