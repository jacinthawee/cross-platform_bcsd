
int PEM_write_bio_PrivateKey
              (BIO *bp,EVP_PKEY *x,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cb,void *u)

{
  EVP_PKEY_ASN1_METHOD *pEVar1;
  int iVar2;
  int in_GS_OFFSET;
  char local_70 [80];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pEVar1 = x->ameth;
  if ((pEVar1 == (EVP_PKEY_ASN1_METHOD *)0x0) || (*(int *)(pEVar1 + 0x28) != 0)) {
    iVar2 = PEM_write_bio_PKCS8PrivateKey(bp,x,enc,(char *)kstr,klen,cb,u);
  }
  else {
    BIO_snprintf(local_70,0x50,"%s PRIVATE KEY",*(undefined4 *)(pEVar1 + 0xc));
    iVar2 = PEM_ASN1_write_bio(i2d_PrivateKey,local_70,bp,x,enc,kstr,klen,cb,u);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
