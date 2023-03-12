
int X509_LOOKUP_by_fingerprint(X509_LOOKUP *ctx,int type,uchar *bytes,int len,X509_OBJECT *ret)

{
  int iVar1;
  _func_1841 *UNRECOVERED_JUMPTABLE;
  
  if ((ctx->method != (X509_LOOKUP_METHOD *)0x0) &&
     (UNRECOVERED_JUMPTABLE = ctx->method->get_by_fingerprint,
     UNRECOVERED_JUMPTABLE != (_func_1841 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000cb59e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,type,bytes,len,ret);
    return iVar1;
  }
  return 0;
}
