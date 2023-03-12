
undefined4 aes_gcm_cleanup(int param_1)

{
  int iVar1;
  void *ptr;
  
  iVar1 = *(int *)(param_1 + 0x60);
  OPENSSL_cleanse((void *)(iVar1 + 0xfc),0x178);
  ptr = *(void **)(iVar1 + 0x274);
  if (ptr != (void *)(param_1 + 0x20)) {
    CRYPTO_free(ptr);
  }
  return 1;
}

