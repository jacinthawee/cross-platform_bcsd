
int X509_load_cert_crl_file(X509_LOOKUP *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  X509 *x;
  int iVar2;
  
  if (type == 1) {
    iVar2 = X509_load_cert_crl_file_part_0();
    return iVar2;
  }
  if (file == (char *)0x0) {
    return 1;
  }
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xb,0x6f,2,"by_file.c",0x8e);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    ERR_put_error(0xb,0x6f,2,"by_file.c",0x8e);
  }
  else if (type == 2) {
    x = d2i_X509_bio(bp,(X509 **)0x0);
    if (x != (X509 *)0x0) {
      iVar2 = X509_STORE_add_cert(ctx->store_ctx,x);
      X509_free(x);
      goto LAB_08168064;
    }
    ERR_put_error(0xb,0x6f,0xd,"by_file.c",0xb3);
  }
  else {
    ERR_put_error(0xb,0x6f,100,"by_file.c",0xbc);
  }
  iVar2 = 0;
LAB_08168064:
  BIO_free(bp);
  return iVar2;
}

