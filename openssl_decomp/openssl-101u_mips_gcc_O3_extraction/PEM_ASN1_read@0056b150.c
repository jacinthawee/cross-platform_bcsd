
void * PEM_ASN1_read(undefined1 *d2i,char *name,FILE *fp,void **x,undefined1 *cb,void *u)

{
  undefined4 uVar1;
  BIO *bp;
  void *pvVar2;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  bp = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (bp == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x66,7,"pem_lib.c",0xac);
    pvVar2 = (void *)0x0;
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(bp,0x6a,0,fp);
    pvVar2 = PEM_ASN1_read_bio(d2i,name,bp,x,cb,u);
    (*(code *)PTR_BIO_free_006a6e70)(bp);
  }
  return pvVar2;
}

