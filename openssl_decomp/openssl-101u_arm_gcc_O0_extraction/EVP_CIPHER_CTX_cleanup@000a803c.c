
int EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX *a)

{
  int iVar1;
  _func_1091 *p_Var2;
  
  if (a->cipher != (EVP_CIPHER *)0x0) {
    p_Var2 = a->cipher->cleanup;
    if ((p_Var2 != (_func_1091 *)0x0) && (iVar1 = (*p_Var2)(a), iVar1 == 0)) {
      return 0;
    }
    if (a->cipher_data == (void *)0x0) goto LAB_000a8060;
    OPENSSL_cleanse(a->cipher_data,a->cipher->ctx_size);
  }
  if (a->cipher_data != (void *)0x0) {
    CRYPTO_free(a->cipher_data);
  }
LAB_000a8060:
  if (a->engine != (ENGINE *)0x0) {
    ENGINE_finish(a->engine);
  }
  memset(a,0,0x8c);
  return 1;
}

