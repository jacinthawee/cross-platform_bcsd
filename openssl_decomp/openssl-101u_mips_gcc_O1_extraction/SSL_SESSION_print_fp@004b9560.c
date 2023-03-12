
int SSL_SESSION_print_fp(FILE *fp,SSL_SESSION *ses)

{
  undefined4 uVar1;
  BIO *fp_00;
  int iVar2;
  
  uVar1 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  fp_00 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar1);
  if (fp_00 != (BIO *)0x0) {
    (*(code *)PTR_BIO_ctrl_006a6e18)(fp_00,0x6a,0,fp);
    iVar2 = SSL_SESSION_print(fp_00,ses);
    (*(code *)PTR_BIO_free_006a6e70)(fp_00);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xbe,7,"ssl_txt.c",0x60);
  return 0;
}

