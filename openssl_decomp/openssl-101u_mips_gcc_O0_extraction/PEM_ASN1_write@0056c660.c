
int PEM_ASN1_write(undefined1 *i2d,char *name,FILE *fp,void *x,EVP_CIPHER *enc,uchar *kstr,int klen,
                  undefined1 *callback,void *u)

{
  undefined4 uVar1;
  BIO *bp;
  int iVar2;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  bp = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (bp != (BIO *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a6e18)(bp,0x6a,0,fp);
    iVar2 = PEM_ASN1_write_bio(i2d,name,bp,x,enc,kstr,klen,callback,u);
    (*(code *)PTR_BIO_free_006a6e70)(bp);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(9,0x68,7,"pem_lib.c",0x143);
  return 0;
}

