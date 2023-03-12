
int PEM_write_DSAPrivateKey
              (FILE *fp,DSA *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write(PTR_i2d_DSAPrivateKey_006a9f88,"DSA PRIVATE KEY",fp,x,enc,kstr,klen,cb,u);
  return iVar1;
}

