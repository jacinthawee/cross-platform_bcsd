
int X509_LOOKUP_shutdown(X509_LOOKUP *ctx)

{
  _func_1837 *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  if (ctx->method == (X509_LOOKUP_METHOD *)0x0) {
    return 0;
  }
  UNRECOVERED_JUMPTABLE = ctx->method->shutdown;
  if (UNRECOVERED_JUMPTABLE != (_func_1837 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08163212. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx);
    return iVar1;
  }
  return 1;
}

