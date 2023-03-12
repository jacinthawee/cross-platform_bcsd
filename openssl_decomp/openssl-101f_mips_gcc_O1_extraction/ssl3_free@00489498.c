
void ssl3_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    ssl3_cleanup_key_block();
    iVar1 = *(int *)(param_1 + 0x58);
    if (*(int *)(iVar1 + 0xec) != 0) {
      ssl3_release_read_buffer(param_1);
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0xfc) != 0) {
      ssl3_release_write_buffer(param_1);
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x120) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x348) != 0) {
      (*(code *)PTR_DH_free_006a8604)();
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x34c) != 0) {
      (*(code *)PTR_EC_KEY_free_006a82d8)();
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x36c) != 0) {
      (*(code *)PTR_sk_pop_free_006a8158)(*(int *)(iVar1 + 0x36c),PTR_X509_NAME_free_006a80f8);
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x178) != 0) {
      (*(code *)PTR_BIO_free_006a7f70)();
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x17c) != 0) {
      ssl3_free_digest_list(param_1);
    }
    (*(code *)PTR_SSL_SRP_CTX_free_006a91f0)(param_1);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(*(undefined4 *)(param_1 + 0x58),0x424);
    (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}

