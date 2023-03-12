
int X509_CRL_print_fp(FILE *bp,X509_CRL *x)

{
  BIO_METHOD *type;
  BIO *bp_00;
  int iVar1;
  
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 != (BIO *)0x0) {
    BIO_ctrl(bp_00,0x6a,0,bp);
    iVar1 = X509_CRL_print(bp_00,x);
    BIO_free(bp_00);
    return iVar1;
  }
  ERR_put_error(0xb,0x93,7,"t_crl.c",0x4b);
  return 0;
}

