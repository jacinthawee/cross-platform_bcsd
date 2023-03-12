
void pkey_hmac_cleanup(int param_1)

{
  void *ptr;
  void *ptr_00;
  
  ptr = *(void **)(param_1 + 0x14);
  HMAC_CTX_cleanup((HMAC_CTX *)((int)ptr + 0x14));
  ptr_00 = *(void **)((int)ptr + 0xc);
  if (ptr_00 != (void *)0x0) {
    if (*(size_t *)((int)ptr + 4) != 0) {
      OPENSSL_cleanse(ptr_00,*(size_t *)((int)ptr + 4));
      ptr_00 = *(void **)((int)ptr + 0xc);
    }
    CRYPTO_free(ptr_00);
    *(undefined4 *)((int)ptr + 0xc) = 0;
  }
  CRYPTO_free(ptr);
  return;
}

