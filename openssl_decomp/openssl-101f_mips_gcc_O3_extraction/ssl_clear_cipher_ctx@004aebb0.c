
void ssl_clear_cipher_ctx(int param_1)

{
  if (*(int *)(param_1 + 0x80) != 0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)();
    CRYPTO_free(*(void **)(param_1 + 0x80));
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  if (*(int *)(param_1 + 0x8c) != 0) {
    (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)();
    CRYPTO_free(*(void **)(param_1 + 0x8c));
    *(undefined4 *)(param_1 + 0x8c) = 0;
  }
  if (*(int *)(param_1 + 0x88) != 0) {
    (*(code *)PTR_COMP_CTX_free_006a9210)();
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  if (*(int *)(param_1 + 0x94) != 0) {
    (*(code *)PTR_COMP_CTX_free_006a9210)();
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  return;
}

