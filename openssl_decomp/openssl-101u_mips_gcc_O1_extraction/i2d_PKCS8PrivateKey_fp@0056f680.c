
int i2d_PKCS8PrivateKey_fp
              (FILE *fp,EVP_PKEY *x,EVP_CIPHER *enc,char *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_BIO_new_fp_006a7248)(fp,0);
  if (iVar1 != 0) {
    iVar2 = do_pk8pkey(iVar1,x,1,0xffffffff,enc,kstr,klen,cb,u);
    (*(code *)PTR_BIO_free_006a6e70)(iVar1);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(9,0x7d,7,"pem_pk8.c",0xe7);
  return 0;
}

