
void EC_GROUP_clear_free(EC_GROUP *group)

{
  undefined4 *puVar1;
  int *ptr;
  undefined4 *ptr_00;
  code *pcVar2;
  
  if (group != (EC_GROUP *)0x0) {
    pcVar2 = *(code **)(*(int *)group + 0x10);
    if ((pcVar2 != (code *)0x0) || (pcVar2 = *(code **)(*(int *)group + 0xc), pcVar2 != (code *)0x0)
       ) {
      (*pcVar2)(group);
    }
    ptr_00 = *(undefined4 **)(group + 0x44);
    while (ptr_00 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*ptr_00;
      (*(code *)ptr_00[4])(ptr_00[1]);
      CRYPTO_free(ptr_00);
      ptr_00 = puVar1;
    }
    ptr = *(int **)(group + 4);
    *(undefined4 *)(group + 0x44) = 0;
    if (ptr != (int *)0x0) {
      pcVar2 = *(code **)(*ptr + 0x30);
      if ((pcVar2 != (code *)0x0) || (pcVar2 = *(code **)(*ptr + 0x2c), pcVar2 != (code *)0x0)) {
        (*pcVar2)(ptr);
      }
      OPENSSL_cleanse(ptr,0x44);
      CRYPTO_free(ptr);
    }
    BN_clear_free((BIGNUM *)(group + 8));
    BN_clear_free((BIGNUM *)(group + 0x1c));
    if (*(void **)(group + 0x3c) != (void *)0x0) {
      OPENSSL_cleanse(*(void **)(group + 0x3c),*(size_t *)(group + 0x40));
      CRYPTO_free(*(void **)(group + 0x3c));
    }
    OPENSSL_cleanse(group,0xac);
    CRYPTO_free(group);
    return;
  }
  return;
}

