
void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX *a)

{
  int iVar1;
  _func_1091 *p_Var2;
  
  if (a == (EVP_CIPHER_CTX *)0x0) {
    return;
  }
  if (a->cipher == (EVP_CIPHER *)0x0) {
LAB_00536db8:
    if (a->cipher_data != (void *)0x0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
  }
  else {
    p_Var2 = a->cipher->cleanup;
    if (p_Var2 != (_func_1091 *)0x0) {
      iVar1 = (*p_Var2)(a);
      if (iVar1 == 0) goto LAB_00536e04;
    }
    if (a->cipher_data != (void *)0x0) {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(a->cipher_data,a->cipher->ctx_size);
      goto LAB_00536db8;
    }
  }
  if (a->engine != (ENGINE *)0x0) {
    ENGINE_finish(a->engine);
  }
  (*(code *)PTR_memset_006a99f4)(a,0,0x8c);
LAB_00536e04:
                    /* WARNING: Could not recover jumptable at 0x00536e14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(a);
  return;
}

