
void X509_LOOKUP_free(X509_LOOKUP *ctx)

{
  _func_1835 *p_Var1;
  
  if (ctx != (X509_LOOKUP *)0x0) {
    if ((ctx->method != (X509_LOOKUP_METHOD *)0x0) &&
       (p_Var1 = ctx->method->free, p_Var1 != (_func_1835 *)0x0)) {
      (*p_Var1)(ctx);
    }
                    /* WARNING: Could not recover jumptable at 0x0058079c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(ctx);
    return;
  }
  return;
}
