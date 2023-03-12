
int X509_LOOKUP_ctrl(X509_LOOKUP *ctx,int cmd,char *argc,long argl,char **ret)

{
  int iVar1;
  _func_1838 *UNRECOVERED_JUMPTABLE;
  
  if (ctx->method == (X509_LOOKUP_METHOD *)0x0) {
    return -1;
  }
  UNRECOVERED_JUMPTABLE = ctx->method->ctrl;
  if (UNRECOVERED_JUMPTABLE != (_func_1838 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00583600. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,cmd,argc,argl,ret);
    return iVar1;
  }
  return 1;
}

