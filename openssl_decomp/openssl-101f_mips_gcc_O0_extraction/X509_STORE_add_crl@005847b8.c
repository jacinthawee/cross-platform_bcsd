
int X509_STORE_add_crl(X509_STORE *ctx,X509_CRL *x)

{
  undefined *puVar1;
  X509_OBJECT *x_00;
  X509_OBJECT *pXVar2;
  int iVar3;
  
  if (x == (X509_CRL *)0x0) {
    return 0;
  }
  x_00 = (X509_OBJECT *)(*(code *)PTR_CRYPTO_malloc_006a8108)(8,"x509_lu.c",0x175);
  puVar1 = PTR_CRYPTO_lock_006a926c;
  if (x_00 != (X509_OBJECT *)0x0) {
    (x_00->data).crl = x;
    x_00->type = 2;
    (*(code *)puVar1)(9,0xb,"x509_lu.c",0x17e);
    if (x_00->type == 1) {
      (*(code *)PTR_CRYPTO_add_lock_006a9080)
                (&((x_00->data).x509)->references,1,3,"x509_lu.c",0x195);
      pXVar2 = X509_OBJECT_retrieve_match(ctx->objs,x_00);
    }
    else {
      if (x_00->type == 2) {
        (*(code *)PTR_CRYPTO_add_lock_006a9080)(&((x_00->data).x509)->valid,1,6,"x509_lu.c",0x198);
      }
      pXVar2 = X509_OBJECT_retrieve_match(ctx->objs,x_00);
    }
    if (pXVar2 == (X509_OBJECT *)0x0) {
      iVar3 = 1;
      (*(code *)PTR_sk_push_006a80a8)(ctx->objs,x_00);
    }
    else {
      if (x_00->type == 1) {
        (*(code *)PTR_X509_free_006a7f90)((x_00->data).ptr);
      }
      else if (x_00->type == 2) {
        (*(code *)PTR_X509_CRL_free_006a8160)((x_00->data).ptr);
      }
      iVar3 = 0;
      (*(code *)PTR_CRYPTO_free_006a7f88)(x_00);
      (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x7d,0x65,"x509_lu.c",0x186);
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0xb,"x509_lu.c",0x18b);
    return iVar3;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x7d,0x41,"x509_lu.c",0x178);
  return 0;
}

