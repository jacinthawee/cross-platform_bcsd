
void COMP_CTX_free(COMP_CTX *ctx)

{
  _func_570 *p_Var1;
  
  if (ctx != (COMP_CTX *)0x0) {
    p_Var1 = ctx->meth->finish;
    if (p_Var1 != (_func_570 *)0x0) {
      (*p_Var1)(ctx);
    }
                    /* WARNING: Could not recover jumptable at 0x005aaff8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(ctx);
    return;
  }
  return;
}

