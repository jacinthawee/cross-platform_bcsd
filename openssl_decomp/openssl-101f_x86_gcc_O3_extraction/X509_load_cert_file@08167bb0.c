
int X509_load_cert_file(X509_LOOKUP *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  ulong uVar2;
  X509 *x;
  int iVar3;
  int iVar4;
  int line;
  
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
    line = 0x8e;
    iVar4 = 2;
  }
  else if (type == 1) {
    iVar3 = 0;
    while (x = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0),
          x != (X509 *)0x0) {
      iVar4 = X509_STORE_add_cert(ctx->store_ctx,x);
      if (iVar4 == 0) {
        iVar3 = 0;
        goto LAB_08167d25;
      }
      iVar3 = iVar3 + 1;
      X509_free(x);
    }
    uVar2 = ERR_peek_last_error();
    if (((uVar2 & 0xfff) == 0x6c) && (iVar3 != 0)) {
      ERR_clear_error();
      goto LAB_08167c24;
    }
    line = 0xa2;
    iVar4 = 9;
  }
  else if (type == 2) {
    x = d2i_X509_bio(bp,(X509 **)0x0);
    if (x != (X509 *)0x0) {
      iVar3 = X509_STORE_add_cert(ctx->store_ctx,x);
LAB_08167d25:
      X509_free(x);
      goto LAB_08167c24;
    }
    line = 0xb3;
    iVar4 = 0xd;
  }
  else {
    line = 0xbc;
    iVar4 = 100;
  }
  iVar3 = 0;
  ERR_put_error(0xb,0x6f,iVar4,"by_file.c",line);
LAB_08167c24:
  BIO_free(bp);
  return iVar3;
}

