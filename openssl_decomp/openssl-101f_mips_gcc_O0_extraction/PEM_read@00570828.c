
int PEM_read(FILE *fp,char **name,char **header,uchar **data,long *len)

{
  undefined4 uVar1;
  BIO *bp;
  int iVar2;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  bp = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (bp != (BIO *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a7f18)(bp,0x6a,0,fp);
    iVar2 = PEM_read_bio(bp,name,header,data,len);
    (*(code *)PTR_BIO_free_006a7f70)(bp);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(9,0x6c,7,"pem_lib.c",0x298);
  return 0;
}

