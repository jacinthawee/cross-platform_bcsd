
void CMAC_CTX_cleanup(CMAC_CTX *ctx)

{
  (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)();
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(ctx + 0xcc,0x20);
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(ctx + 0x8c,0x20);
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(ctx + 0xac,0x20);
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(ctx + 0xec,0x20);
  *(undefined4 *)(ctx + 0x10c) = 0xffffffff;
  return;
}

