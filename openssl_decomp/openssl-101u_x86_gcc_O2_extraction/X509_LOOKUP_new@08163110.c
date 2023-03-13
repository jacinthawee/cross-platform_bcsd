
X509_LOOKUP * X509_LOOKUP_new(X509_LOOKUP_METHOD *method)

{
  _func_1834 *p_Var1;
  X509_LOOKUP *ctx;
  int iVar2;
  X509_LOOKUP *pXVar3;
  
  ctx = (X509_LOOKUP *)CRYPTO_malloc(0x14,"x509_lu.c",0x45);
  if (ctx == (X509_LOOKUP *)0x0) {
    pXVar3 = (X509_LOOKUP *)0x0;
  }
  else {
    p_Var1 = method->new_item;
    ctx->method = method;
    ctx->init = 0;
    ctx->skip = 0;
    ctx->method_data = (char *)0x0;
    ctx->store_ctx = (X509_STORE *)0x0;
    pXVar3 = ctx;
    if (p_Var1 != (_func_1834 *)0x0) {
      iVar2 = (*p_Var1)(ctx);
      if (iVar2 == 0) {
        pXVar3 = (X509_LOOKUP *)0x0;
        CRYPTO_free(ctx);
      }
    }
  }
  return pXVar3;
}

