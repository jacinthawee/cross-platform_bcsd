
int EVP_CIPHER_CTX_copy(EVP_CIPHER_CTX *out,EVP_CIPHER_CTX *in)

{
  int iVar1;
  void *__dest;
  _func_1091 *p_Var2;
  EVP_CIPHER *pEVar3;
  
  if ((in == (EVP_CIPHER_CTX *)0x0) || (in->cipher == (EVP_CIPHER *)0x0)) {
    ERR_put_error(6,0xa3,0x6f,"evp_enc.c",0x28b);
    return 0;
  }
  if ((in->engine != (ENGINE *)0x0) && (iVar1 = ENGINE_init(in->engine), iVar1 == 0)) {
    ERR_put_error(6,0xa3,0x26,"evp_enc.c",0x292);
    return 0;
  }
  if (out->cipher == (EVP_CIPHER *)0x0) {
LAB_000aade6:
    if (out->cipher_data != (void *)0x0) {
      CRYPTO_free(out->cipher_data);
    }
LAB_000aadee:
    if (out->engine != (ENGINE *)0x0) {
      ENGINE_finish(out->engine);
    }
    memset(out,0,0x8c);
  }
  else {
    p_Var2 = out->cipher->cleanup;
    if ((p_Var2 == (_func_1091 *)0x0) || (iVar1 = (*p_Var2)(out), iVar1 != 0)) {
      if (out->cipher_data != (void *)0x0) {
        OPENSSL_cleanse(out->cipher_data,out->cipher->ctx_size);
        goto LAB_000aade6;
      }
      goto LAB_000aadee;
    }
  }
  memcpy(out,in,0x8c);
  if (in->cipher_data != (void *)0x0) {
    pEVar3 = in->cipher;
    if (pEVar3->ctx_size == 0) goto LAB_000aae14;
    __dest = CRYPTO_malloc(pEVar3->ctx_size,"evp_enc.c",0x29c);
    out->cipher_data = __dest;
    if (__dest == (void *)0x0) {
      ERR_put_error(6,0xa3,0x41,"evp_enc.c",0x29f);
      return 0;
    }
    memcpy(__dest,in->cipher_data,in->cipher->ctx_size);
  }
  pEVar3 = in->cipher;
LAB_000aae14:
  if (-1 < (int)(pEVar3->flags << 0x15)) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x000aae36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*pEVar3->ctrl)(in,8,0,out);
  return iVar1;
}

