
int EVP_CIPHER_CTX_rand_key(EVP_CIPHER_CTX *ctx,uchar *key)

{
  _func_1094 *p_Var1;
  int iVar2;
  int line;
  
  if ((*(byte *)((int)&ctx->cipher->flags + 1) & 2) == 0) {
    iVar2 = RAND_bytes(key,ctx->key_len);
    return (uint)(0 < iVar2);
  }
  p_Var1 = ctx->cipher->ctrl;
  if (p_Var1 == (_func_1094 *)0x0) {
    line = 0x25a;
    iVar2 = 0x84;
  }
  else {
    iVar2 = (*p_Var1)(ctx,6,0,key);
    if (iVar2 != -1) {
      return iVar2;
    }
    line = 0x261;
    iVar2 = 0x85;
  }
  ERR_put_error(6,0x7c,iVar2,"evp_enc.c",line);
  return 0;
}

