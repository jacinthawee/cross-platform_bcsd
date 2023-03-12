
int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx,int type,int arg,void *ptr)

{
  int iVar1;
  int reason;
  _func_1094 *p_Var2;
  
  if (ctx->cipher == (EVP_CIPHER *)0x0) {
    reason = 0x83;
    iVar1 = 0x26d;
  }
  else {
    p_Var2 = ctx->cipher->ctrl;
    if (p_Var2 == (_func_1094 *)0x0) {
      reason = 0x84;
      iVar1 = 0x272;
    }
    else {
      iVar1 = (*p_Var2)(ctx,type,arg,ptr);
      if (iVar1 != -1) {
        return iVar1;
      }
      reason = 0x85;
      iVar1 = 0x278;
    }
  }
  ERR_put_error(6,0x7c,reason,"evp_enc.c",iVar1);
  return 0;
}

