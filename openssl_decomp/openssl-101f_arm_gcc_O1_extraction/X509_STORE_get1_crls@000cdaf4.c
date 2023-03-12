
stack_st_X509_CRL * X509_STORE_get1_crls(X509_STORE_CTX *st,X509_NAME *nm)

{
  _STACK *st_00;
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  X509_CRL *a;
  int local_2c;
  X509_OBJECT local_28;
  
  st_00 = sk_new_null();
  CRYPTO_lock(9,0xb,"x509_lu.c",0x220);
  x509_object_idx_cnt(st->ctx->objs,2,nm,&local_2c);
  CRYPTO_lock(10,0xb,"x509_lu.c",0x226);
  iVar1 = X509_STORE_get_by_subject(st,2,nm,&local_28);
  if (iVar1 == 0) {
    sk_free(st_00);
    return (stack_st_X509_CRL *)0x0;
  }
  if (local_28.type == 1) {
    X509_free(local_28.data.x509);
  }
  else if (local_28.type == 2) {
    X509_CRL_free(local_28.data.crl);
  }
  CRYPTO_lock(9,0xb,"x509_lu.c",0x22d);
  iVar1 = x509_object_idx_cnt(st->ctx->objs,2,nm,&local_2c);
  if (iVar1 < 0) {
    CRYPTO_lock(10,0xb,"x509_lu.c",0x231);
    sk_free(st_00);
    return (stack_st_X509_CRL *)0x0;
  }
  if (0 < local_2c) {
    iVar4 = 0;
    do {
      iVar3 = iVar4 + iVar1;
      iVar4 = iVar4 + 1;
      pvVar2 = sk_value((_STACK *)st->ctx->objs,iVar3);
      a = *(X509_CRL **)((int)pvVar2 + 4);
      CRYPTO_add_lock(&a->references,1,6,"x509_lu.c",0x23a);
      iVar3 = sk_push(st_00,a);
      if (iVar3 == 0) {
        CRYPTO_lock(10,0xb,"x509_lu.c",0x23d);
        X509_CRL_free(a);
        sk_pop_free(st_00,X509_CRL_free);
        return (stack_st_X509_CRL *)0x0;
      }
    } while (iVar4 < local_2c);
  }
  CRYPTO_lock(10,0xb,"x509_lu.c",0x243);
  return (stack_st_X509_CRL *)st_00;
}

