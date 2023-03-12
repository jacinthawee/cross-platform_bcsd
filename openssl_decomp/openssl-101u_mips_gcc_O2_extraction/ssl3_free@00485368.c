
void ssl3_free(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x58) != 0)) {
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
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x348) != 0) {
      (*(code *)PTR_DH_free_006a7508)();
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x34c) != 0) {
      (*(code *)PTR_EC_KEY_free_006a71d4)();
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x36c) != 0) {
      (*(code *)PTR_sk_pop_free_006a7058)(*(int *)(iVar1 + 0x36c),PTR_X509_NAME_free_006a6ff8);
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x178) != 0) {
      (*(code *)PTR_BIO_free_006a6e70)();
      iVar1 = *(int *)(param_1 + 0x58);
    }
    if (*(int *)(iVar1 + 0x17c) != 0) {
      ssl3_free_digest_list(param_1);
    }
    (*(code *)PTR_SSL_SRP_CTX_free_006a80b4)(param_1);
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(*(undefined4 *)(param_1 + 0x58),0x424);
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}

