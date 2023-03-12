
int PEM_write_ECPrivateKey
              (FILE *fp,EC_KEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(PTR_i2d_ECPrivateKey_006a9f94,"EC PRIVATE KEY",fp,x,enc,kstr,klen,cb,u);
  return iVar1;
}

