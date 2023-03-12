
COMP_CTX * COMP_CTX_new(COMP_METHOD *meth)

{
  COMP_CTX *ctx;
  int iVar1;
  _func_569 *p_Var2;
  
  ctx = (COMP_CTX *)CRYPTO_malloc(0x1c,"comp_lib.c",0xb);
  if (ctx == (COMP_CTX *)0x0) {
    return (COMP_CTX *)0x0;
  }
  memset(ctx,0,0x1c);
  p_Var2 = meth->init;
  ctx->meth = meth;
  if (p_Var2 != (_func_569 *)0x0) {
    iVar1 = (*p_Var2)(ctx);
    if (iVar1 != 0) {
      return ctx;
    }
    CRYPTO_free(ctx);
    return (COMP_CTX *)0x0;
  }
  return ctx;
}

