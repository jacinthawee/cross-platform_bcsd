
void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX *a)

{
  int iVar1;
  _func_1091 *p_Var2;
  
  if (a == (EVP_CIPHER_CTX *)0x0) {
    return;
  }
  if (a->cipher == (EVP_CIPHER *)0x0) {
LAB_000a8016:
    if (a->cipher_data != (void *)0x0) {
      CRYPTO_free(a->cipher_data);
    }
  }
  else {
    p_Var2 = a->cipher->cleanup;
    if ((p_Var2 != (_func_1091 *)0x0) && (iVar1 = (*p_Var2)(a), iVar1 == 0)) goto LAB_000a8030;
    if (a->cipher_data != (void *)0x0) {
      OPENSSL_cleanse(a->cipher_data,a->cipher->ctx_size);
      goto LAB_000a8016;
    }
  }
  if (a->engine != (ENGINE *)0x0) {
    ENGINE_finish(a->engine);
  }
  memset(a,0,0x8c);
LAB_000a8030:
  CRYPTO_free(a);
  return;
}

