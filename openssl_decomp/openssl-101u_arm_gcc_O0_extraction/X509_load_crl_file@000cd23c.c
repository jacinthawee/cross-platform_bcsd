
int X509_load_crl_file(X509_LOOKUP *ctx,char *file,int type)

{
  BIO_METHOD *type_00;
  BIO *bp;
  long lVar1;
  ulong uVar2;
  X509_CRL *x;
  X509_CRL *pXVar3;
  X509_CRL *pXVar4;
  
  if (file == (char *)0x0) {
    return 1;
  }
  type_00 = BIO_s_file();
  bp = BIO_new(type_00);
  if ((bp == (BIO *)0x0) || (lVar1 = BIO_ctrl(bp,0x6c,3,file), lVar1 < 1)) {
    ERR_put_error(0xb,0x70,2,"by_file.c",0xc4);
    if (bp == (BIO *)0x0) {
      return 0;
    }
    pXVar4 = (X509_CRL *)0x0;
  }
  else if (type == 1) {
    pXVar4 = (X509_CRL *)0x0;
    while (x = PEM_read_bio_X509_CRL(bp,(X509_CRL **)0x0,(undefined1 *)0x0,(void *)0x0),
          x != (X509_CRL *)0x0) {
      pXVar4 = (X509_CRL *)((int)&pXVar4->crl + 1);
      pXVar3 = (X509_CRL *)X509_STORE_add_crl(ctx->store_ctx,x);
      if (pXVar3 == (X509_CRL *)0x0) goto LAB_000cd31a;
      X509_CRL_free(x);
    }
    uVar2 = ERR_peek_last_error();
    if (((uVar2 & 0xfff) == 0x6c) && (pXVar4 != (X509_CRL *)0x0)) {
      ERR_clear_error();
    }
    else {
      pXVar4 = (X509_CRL *)0x0;
      ERR_put_error(0xb,0x70,9,"by_file.c",0xd1);
    }
  }
  else if (type == 2) {
    x = d2i_X509_CRL_bio(bp,(X509_CRL **)0x0);
    if (x == (X509_CRL *)0x0) {
      ERR_put_error(0xb,0x70,0xd,"by_file.c",0xe0);
      pXVar4 = x;
    }
    else {
      pXVar3 = (X509_CRL *)X509_STORE_add_crl(ctx->store_ctx,x);
LAB_000cd31a:
      X509_CRL_free(x);
      pXVar4 = pXVar3;
    }
  }
  else {
    ERR_put_error(0xb,0x70,100,"by_file.c",0xe8);
    pXVar4 = (X509_CRL *)0x0;
  }
  BIO_free(bp);
  return (int)pXVar4;
}

