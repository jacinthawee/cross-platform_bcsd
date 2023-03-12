
int PEM_write_bio_PrivateKey
              (BIO *bp,EVP_PKEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  char acStack_7c [80];
  int local_2c;
  
  pEVar2 = x->ameth;
  local_2c = __TMC_END__;
  if ((pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) || (*(int *)(pEVar2 + 0x28) != 0)) {
    iVar1 = PEM_write_bio_PKCS8PrivateKey(bp,x,enc,(char *)kstr,klen,cb,u);
  }
  else {
    BIO_snprintf(acStack_7c,0x50,"%s PRIVATE KEY",*(undefined4 *)(pEVar2 + 0xc));
    iVar1 = PEM_ASN1_write_bio(i2d_PrivateKey + 1,acStack_7c,bp,x,enc,kstr,klen,cb,u);
  }
  if (local_2c == __TMC_END__) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

