
int PEM_write_PrivateKey
              (FILE *fp,EVP_PKEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  BIO *bp;
  BIO *pBVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  char acStack_74 [80];
  int local_24;
  
  local_24 = __stack_chk_guard;
  bp = BIO_new_fp(fp,0);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x8b,7,"pem_pkey.c",0xeb);
  }
  else {
    pEVar2 = x->ameth;
    if ((pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) || (*(int *)(pEVar2 + 0x28) != 0)) {
      pBVar1 = (BIO *)PEM_write_bio_PKCS8PrivateKey(bp,x,enc,(char *)kstr,klen,cb,u);
    }
    else {
      BIO_snprintf(acStack_74,0x50,"%s PRIVATE KEY",*(undefined4 *)(pEVar2 + 0xc));
      pBVar1 = (BIO *)PEM_ASN1_write_bio(i2d_PrivateKey + 1,acStack_74,bp,x,enc,kstr,klen,cb,u);
    }
    BIO_free(bp);
    bp = pBVar1;
  }
  if (local_24 == __stack_chk_guard) {
    return (int)bp;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

