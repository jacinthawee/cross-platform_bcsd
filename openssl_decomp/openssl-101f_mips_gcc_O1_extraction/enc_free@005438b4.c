
undefined4 enc_free(int param_1)

{
  if (param_1 != 0) {
    EVP_CIPHER_CTX_cleanup((EVP_CIPHER_CTX *)(*(int *)(param_1 + 0x20) + 0x14));
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(*(undefined4 *)(param_1 + 0x20),0x10e4);
    (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 0;
}

