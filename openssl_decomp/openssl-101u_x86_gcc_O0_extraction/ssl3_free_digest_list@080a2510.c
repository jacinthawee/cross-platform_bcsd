
void ssl3_free_digest_list(int param_1)

{
  void *ptr;
  int iVar1;
  
  ptr = *(void **)(*(int *)(param_1 + 0x58) + 0x17c);
  if (ptr != (void *)0x0) {
    iVar1 = 0;
    do {
      if (*(EVP_MD_CTX **)((int)ptr + iVar1) != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)ptr + iVar1));
        ptr = *(void **)(*(int *)(param_1 + 0x58) + 0x17c);
      }
      iVar1 = iVar1 + 4;
    } while (iVar1 != 0x18);
    CRYPTO_free(ptr);
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x17c) = 0;
  }
  return;
}

