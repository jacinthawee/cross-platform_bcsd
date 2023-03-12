
stack_st_X509_INFO * PEM_X509_INFO_read(FILE *fp,stack_st_X509_INFO *sk,undefined1 *cb,void *u)

{
  undefined4 uVar1;
  BIO *bp;
  stack_st_X509_INFO *psVar2;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  bp = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (bp == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x73,7,"pem_info.c",0x51);
    psVar2 = (stack_st_X509_INFO *)0x0;
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(bp,0x6a,0,fp);
    psVar2 = PEM_X509_INFO_read_bio(bp,sk,cb,u);
    (*(code *)PTR_BIO_free_006a6e70)(bp);
  }
  return psVar2;
}

