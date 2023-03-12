
int X509_print_ex_fp(FILE *bp,X509 *x,ulong nmflag,ulong cflag)

{
  undefined4 uVar1;
  BIO *bp_00;
  int iVar2;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  bp_00 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (bp_00 != (BIO *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a6e18)(bp_00,0x6a,0,bp);
    iVar2 = X509_print_ex(bp_00,x,nmflag,cflag);
    (*(code *)PTR_BIO_free_006a6e70)(bp_00);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x76,7,"t_x509.c",0x5a);
  return 0;
}

