
int PEM_write_bio_ECPrivateKey
              (BIO *bp,EC_KEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio(PTR_i2d_ECPrivateKey_006a8e78,"EC PRIVATE KEY",bp,x,enc,kstr,klen,cb,u)
  ;
  return iVar1;
}
