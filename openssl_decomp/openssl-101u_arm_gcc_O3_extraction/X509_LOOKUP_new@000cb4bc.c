
X509_LOOKUP * X509_LOOKUP_new(X509_LOOKUP_METHOD *method)

{
  X509_LOOKUP *ctx;
  int iVar1;
  _func_1834 *p_Var2;
  
  ctx = (X509_LOOKUP *)CRYPTO_malloc(0x14,"x509_lu.c",0x45);
  if (ctx != (X509_LOOKUP *)0x0) {
    p_Var2 = method->new_item;
    ctx->method = method;
    ctx->init = 0;
    ctx->skip = 0;
    ctx->method_data = (char *)0x0;
    ctx->store_ctx = (X509_STORE *)0x0;
    if (p_Var2 != (_func_1834 *)0x0) {
      iVar1 = (*p_Var2)(ctx);
      if (iVar1 != 0) {
        return ctx;
      }
      CRYPTO_free(ctx);
      return (X509_LOOKUP *)0x0;
    }
  }
  return ctx;
}
