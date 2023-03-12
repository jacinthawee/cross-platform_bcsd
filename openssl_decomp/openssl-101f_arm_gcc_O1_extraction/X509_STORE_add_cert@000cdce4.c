
int X509_STORE_add_cert(X509_STORE *ctx,X509 *x)

{
  X509_OBJECT *x_00;
  X509_OBJECT *pXVar1;
  int iVar2;
  
  if (x == (X509 *)0x0) {
    return 0;
  }
  x_00 = (X509_OBJECT *)CRYPTO_malloc(8,"x509_lu.c",0x154);
  if (x_00 != (X509_OBJECT *)0x0) {
    (x_00->data).x509 = x;
    x_00->type = 1;
    CRYPTO_lock(9,0xb,"x509_lu.c",0x15d);
    if (x_00->type == 1) {
      CRYPTO_add_lock(&((x_00->data).x509)->references,1,3,"x509_lu.c",0x195);
      pXVar1 = X509_OBJECT_retrieve_match(ctx->objs,x_00);
    }
    else {
      if (x_00->type == 2) {
        CRYPTO_add_lock(&((x_00->data).x509)->valid,1,6,"x509_lu.c",0x198);
      }
      pXVar1 = X509_OBJECT_retrieve_match(ctx->objs,x_00);
    }
    if (pXVar1 == (X509_OBJECT *)0x0) {
      sk_push((_STACK *)ctx->objs,x_00);
      iVar2 = 1;
    }
    else {
      if (x_00->type == 1) {
        X509_free((x_00->data).x509);
      }
      else if (x_00->type == 2) {
        X509_CRL_free((x_00->data).crl);
      }
      iVar2 = 0;
      CRYPTO_free(x_00);
      ERR_put_error(0xb,0x7c,0x65,"x509_lu.c",0x165);
    }
    CRYPTO_lock(10,0xb,"x509_lu.c",0x16a);
    return iVar2;
  }
  ERR_put_error(0xb,0x7c,0x41,"x509_lu.c",0x157);
  return 0;
}
