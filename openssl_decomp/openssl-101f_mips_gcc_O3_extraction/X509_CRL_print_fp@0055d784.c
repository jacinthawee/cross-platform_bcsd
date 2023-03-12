
int X509_CRL_print_fp(FILE *bp,X509_CRL *x)

{
  undefined4 uVar1;
  BIO *bp_00;
  int iVar2;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  bp_00 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (bp_00 != (BIO *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a7f18)(bp_00,0x6a,0,bp);
    iVar2 = X509_CRL_print(bp_00,x);
    (*(code *)PTR_BIO_free_006a7f70)(bp_00);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x93,7,"t_crl.c",0x4b);
  return 0;
}

