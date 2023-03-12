
int X509_STORE_add_crl(X509_STORE *ctx,X509_CRL *x)

{
  undefined *puVar1;
  X509_OBJECT *x_00;
  X509_OBJECT *pXVar2;
  int iVar3;
  
  if (x == (X509_CRL *)0x0) {
    return 0;
  }
  x_00 = (X509_OBJECT *)(*(code *)PTR_CRYPTO_malloc_006a7008)(8,"x509_lu.c",0x16d);
  puVar1 = PTR_CRYPTO_lock_006a8144;
  if (x_00 != (X509_OBJECT *)0x0) {
    (x_00->data).crl = x;
    x_00->type = 2;
    (*(code *)puVar1)(9,0xb,"x509_lu.c",0x175);
    if (x_00->type == 1) {
      (*(code *)PTR_CRYPTO_add_lock_006a805c)
                (&((x_00->data).x509)->references,1,3,"x509_lu.c",0x18a);
      pXVar2 = X509_OBJECT_retrieve_match(ctx->objs,x_00);
    }
    else {
      if (x_00->type == 2) {
        (*(code *)PTR_CRYPTO_add_lock_006a805c)(&((x_00->data).x509)->valid,1,6,"x509_lu.c",0x18d);
      }
      pXVar2 = X509_OBJECT_retrieve_match(ctx->objs,x_00);
    }
    if (pXVar2 == (X509_OBJECT *)0x0) {
      iVar3 = 1;
      (*(code *)PTR_sk_push_006a6fa8)(ctx->objs,x_00);
    }
    else {
      if (x_00->type == 1) {
        (*(code *)PTR_X509_free_006a6e90)((x_00->data).ptr);
      }
      else if (x_00->type == 2) {
        (*(code *)PTR_X509_CRL_free_006a7060)((x_00->data).ptr);
      }
      iVar3 = 0;
      (*(code *)PTR_CRYPTO_free_006a6e88)(x_00);
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7d,0x65,"x509_lu.c",0x17c);
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(10,0xb,"x509_lu.c",0x181);
    return iVar3;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x7d,0x41,"x509_lu.c",0x16f);
  return 0;
}

