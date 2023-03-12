
void ssl3_free_digest_list(int param_1)

{
  EVP_MD_CTX **ppEVar1;
  void *ptr;
  int iVar2;
  
  ptr = *(void **)(*(int *)(param_1 + 0x58) + 0x17c);
  if (ptr != (void *)0x0) {
    iVar2 = 0;
    do {
      ppEVar1 = (EVP_MD_CTX **)((int)ptr + iVar2);
      iVar2 = iVar2 + 4;
      if (*ppEVar1 != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(*ppEVar1);
        ptr = *(void **)(*(int *)(param_1 + 0x58) + 0x17c);
      }
    } while (iVar2 != 0x18);
    CRYPTO_free(ptr);
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x17c) = 0;
  }
  return;
}

