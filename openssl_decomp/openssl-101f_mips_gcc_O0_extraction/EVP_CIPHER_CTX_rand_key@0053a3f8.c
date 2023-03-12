
int EVP_CIPHER_CTX_rand_key(EVP_CIPHER_CTX *ctx,uchar *key)

{
  int iVar1;
  int line;
  _func_1094 *p_Var2;
  
  if ((ctx->cipher->flags & 0x200) == 0) {
    iVar1 = RAND_bytes(key,ctx->key_len);
    return (uint)(0 < iVar1);
  }
  p_Var2 = ctx->cipher->ctrl;
  iVar1 = 0x84;
  if (p_Var2 == (_func_1094 *)0x0) {
    line = 0x272;
  }
  else {
    iVar1 = (*p_Var2)(ctx,6,0,key);
    if (iVar1 != -1) {
      return iVar1;
    }
    iVar1 = 0x85;
    line = 0x278;
  }
  ERR_put_error(6,0x7c,iVar1,"evp_enc.c",line);
  return 0;
}

