
void dtls1_clear_record_buffer(int param_1)

{
  int iVar1;
  void *ptr;
  
  iVar1 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x248));
  while (iVar1 != 0) {
    ptr = *(void **)(iVar1 + 8);
    if (*(int *)((int)ptr + 0x14) != 0) {
      (*(code *)PTR_EVP_CIPHER_CTX_free_006a93f8)(*(undefined4 *)((int)ptr + 0x18));
      (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)(*(undefined4 *)((int)ptr + 0x1c));
    }
    if (*(void **)((int)ptr + 0x2c) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x2c));
    }
    if (*(void **)((int)ptr + 0x30) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)ptr + 0x30));
    }
    CRYPTO_free(ptr);
    (*(code *)PTR_pitem_free_006a939c)(iVar1);
    iVar1 = (*(code *)PTR_pqueue_pop_006a93a0)(*(undefined4 *)(*(int *)(param_1 + 0x5c) + 0x248));
  }
  return;
}

