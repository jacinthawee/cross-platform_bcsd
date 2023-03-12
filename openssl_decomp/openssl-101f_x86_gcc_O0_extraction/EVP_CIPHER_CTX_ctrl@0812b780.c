
int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx,int type,int arg,void *ptr)

{
  _func_1094 *p_Var1;
  int iVar2;
  int line;
  
  if (ctx->cipher == (EVP_CIPHER *)0x0) {
    line = 0x26d;
    iVar2 = 0x83;
  }
  else {
    p_Var1 = ctx->cipher->ctrl;
    if (p_Var1 == (_func_1094 *)0x0) {
      line = 0x272;
      iVar2 = 0x84;
    }
    else {
      iVar2 = (*p_Var1)(ctx,type,arg,ptr);
      if (iVar2 != -1) {
        return iVar2;
      }
      line = 0x278;
      iVar2 = 0x85;
    }
  }
  ERR_put_error(6,0x7c,iVar2,"evp_enc.c",line);
  return 0;
}

