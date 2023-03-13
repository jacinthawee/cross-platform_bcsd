
int X509_STORE_add_cert(X509_STORE *ctx,X509 *x)

{
  X509_OBJECT *x_00;
  X509_OBJECT *pXVar1;
  int mode;
  int iVar2;
  
  iVar2 = 0;
  if (x != (X509 *)0x0) {
    x_00 = (X509_OBJECT *)CRYPTO_malloc(8,"x509_lu.c",0x14c);
    if (x_00 == (X509_OBJECT *)0x0) {
      ERR_put_error(0xb,0x7c,0x41,"x509_lu.c",0x14e);
    }
    else {
      x_00->type = 1;
      (x_00->data).x509 = x;
      CRYPTO_lock((int)x_00,9,(char *)0xb,(int)"x509_lu.c");
      if (x_00->type == 1) {
        CRYPTO_add_lock(&((x_00->data).x509)->references,1,3,"x509_lu.c",0x18a);
      }
      else if (x_00->type == 2) {
        CRYPTO_add_lock(&((x_00->data).x509)->valid,1,6,"x509_lu.c",0x18d);
      }
      pXVar1 = X509_OBJECT_retrieve_match(ctx->objs,x_00);
      if (pXVar1 == (X509_OBJECT *)0x0) {
        iVar2 = 1;
        mode = sk_push((_STACK *)ctx->objs,x_00);
      }
      else {
        mode = x_00->type;
        if (mode == 1) {
          X509_free((x_00->data).x509);
        }
        else if (mode == 2) {
          X509_CRL_free((x_00->data).crl);
        }
        iVar2 = 0;
        CRYPTO_free(x_00);
        ERR_put_error(0xb,0x7c,0x65,"x509_lu.c",0x15c);
      }
      CRYPTO_lock(mode,10,(char *)0xb,(int)"x509_lu.c");
    }
  }
  return iVar2;
}

