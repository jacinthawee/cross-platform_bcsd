
int COMP_expand_block(COMP_CTX *ctx,uchar *out,int olen,uchar *in,int ilen)

{
  _func_572 *p_Var1;
  int iVar2;
  
  p_Var1 = ctx->meth->expand;
  if (p_Var1 == (_func_572 *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = (*p_Var1)(ctx,out,olen,in,ilen);
    if (0 < iVar2) {
      ctx->expand_in = ctx->expand_in + ilen;
      ctx->expand_out = ctx->expand_out + iVar2;
    }
  }
  return iVar2;
}

