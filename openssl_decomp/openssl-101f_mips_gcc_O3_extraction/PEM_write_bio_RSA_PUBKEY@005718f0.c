
int PEM_write_bio_RSA_PUBKEY(BIO *bp,RSA *x)

{
  int iVar1;
  
  iVar1 = PEM_ASN1_write_bio(PTR_i2d_RSA_PUBKEY_006a9f84,"PUBLIC KEY",bp,x,(EVP_CIPHER *)0x0,
                             (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return iVar1;
}

