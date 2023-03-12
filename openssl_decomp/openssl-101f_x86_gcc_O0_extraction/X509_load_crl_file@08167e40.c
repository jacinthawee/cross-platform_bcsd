
int X509_load_crl_file(X509_LOOKUP *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  ulong uVar2;
  X509_CRL *x;
  int iVar3;
  int iVar4;
  int line;
  
  if (file == (char *)0x0) {
    return 1;
  }
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xb,0x70,2,"by_file.c",0xd1);
    return 0;
  }
  lVar1 = BIO_ctrl(bp,0x6c,3,file);
  if (lVar1 < 1) {
    line = 0xd1;
    iVar4 = 2;
  }
  else if (type == 1) {
    iVar3 = 0;
    while (x = PEM_read_bio_X509_CRL(bp,(X509_CRL **)0x0,(undefined1 *)0x0,(void *)0x0),
          x != (X509_CRL *)0x0) {
      iVar4 = X509_STORE_add_crl(ctx->store_ctx,x);
      if (iVar4 == 0) {
        iVar3 = 0;
        goto LAB_08167fb5;
      }
      iVar3 = iVar3 + 1;
      X509_CRL_free(x);
    }
    uVar2 = ERR_peek_last_error();
    if (((uVar2 & 0xfff) == 0x6c) && (iVar3 != 0)) {
      ERR_clear_error();
      goto LAB_08167eb4;
    }
    line = 0xe5;
    iVar4 = 9;
  }
  else if (type == 2) {
    x = d2i_X509_CRL_bio(bp,(X509_CRL **)0x0);
    if (x != (X509_CRL *)0x0) {
      iVar3 = X509_STORE_add_crl(ctx->store_ctx,x);
LAB_08167fb5:
      X509_CRL_free(x);
      goto LAB_08167eb4;
    }
    line = 0xf6;
    iVar4 = 0xd;
  }
  else {
    line = 0xff;
    iVar4 = 100;
  }
  iVar3 = 0;
  ERR_put_error(0xb,0x70,iVar4,"by_file.c",line);
LAB_08167eb4:
  BIO_free(bp);
  return iVar3;
}

