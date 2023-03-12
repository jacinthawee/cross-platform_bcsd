
int COMP_compress_block(COMP_CTX *ctx,uchar *out,int olen,uchar *in,int ilen)

{
  _func_571 *p_Var1;
  int iVar2;
  
  p_Var1 = ctx->meth->compress;
  if (p_Var1 == (_func_571 *)0x0) {
    iVar2 = -1;
  }
  else {
    iVar2 = (*p_Var1)(ctx,out,olen,in,ilen);
    if (0 < iVar2) {
      ctx->compress_in = ctx->compress_in + ilen;
      ctx->compress_out = ctx->compress_out + iVar2;
    }
  }
  return iVar2;
}

