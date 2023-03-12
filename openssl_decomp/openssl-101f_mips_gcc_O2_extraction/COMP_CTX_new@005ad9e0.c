
COMP_CTX * COMP_CTX_new(COMP_METHOD *meth)

{
  COMP_CTX *ctx;
  int iVar1;
  _func_569 *p_Var2;
  
  ctx = (COMP_CTX *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x1c,"comp_lib.c",0xb);
  if (ctx == (COMP_CTX *)0x0) {
    ctx = (COMP_CTX *)0x0;
  }
  else {
    (*(code *)PTR_memset_006aab00)(ctx,0,0x1c);
    p_Var2 = meth->init;
    ctx->meth = meth;
    if (p_Var2 != (_func_569 *)0x0) {
      iVar1 = (*p_Var2)(ctx);
      if (iVar1 == 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
        ctx = (COMP_CTX *)0x0;
      }
    }
  }
  return ctx;
}

