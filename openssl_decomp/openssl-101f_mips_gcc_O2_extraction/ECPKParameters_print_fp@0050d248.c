
int ECPKParameters_print_fp(FILE *fp,EC_GROUP *x,int off)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x6a,0,fp);
    iVar1 = ECPKParameters_print(bp,x,off);
    BIO_free(bp);
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x96,7,"eck_prn.c",0x4e);
  return 0;
}

