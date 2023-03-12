
int EVP_CIPHER_CTX_rand_key(EVP_CIPHER_CTX *ctx,uchar *key)

{
  int iVar1;
  _func_1094 *p_Var2;
  
  if ((int)(ctx->cipher->flags << 0x16) < 0) {
    p_Var2 = ctx->cipher->ctrl;
    if (p_Var2 == (_func_1094 *)0x0) {
      ERR_put_error(6,0x7c,0x84,"evp_enc.c",0x272);
    }
    else {
      p_Var2 = (_func_1094 *)(*p_Var2)(ctx,6,0,key);
      if (p_Var2 == (_func_1094 *)0xffffffff) {
        ERR_put_error(6,0x7c,0x85,"evp_enc.c",0x278);
        p_Var2 = (_func_1094 *)0x0;
      }
    }
  }
  else {
    iVar1 = RAND_bytes(key,ctx->key_len);
    if (iVar1 < 1) {
      p_Var2 = (_func_1094 *)0x0;
    }
    else {
      p_Var2 = (_func_1094 *)0x1;
    }
  }
  return (int)p_Var2;
}

