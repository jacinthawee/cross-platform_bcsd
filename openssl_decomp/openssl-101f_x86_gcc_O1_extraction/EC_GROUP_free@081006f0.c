
void EC_GROUP_free(EC_GROUP *group)

{
  undefined4 *puVar1;
  int *ptr;
  undefined4 *ptr_00;
  
  if (group != (EC_GROUP *)0x0) {
    if (*(code **)(*(int *)group + 0xc) != (code *)0x0) {
      (**(code **)(*(int *)group + 0xc))(group);
    }
    ptr_00 = *(undefined4 **)(group + 0x44);
    while (ptr_00 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*ptr_00;
      (*(code *)ptr_00[3])(ptr_00[1]);
      CRYPTO_free(ptr_00);
      ptr_00 = puVar1;
    }
    ptr = *(int **)(group + 4);
    *(undefined4 *)(group + 0x44) = 0;
    if (ptr != (int *)0x0) {
      if (*(code **)(*ptr + 0x2c) != (code *)0x0) {
        (**(code **)(*ptr + 0x2c))(ptr);
      }
      CRYPTO_free(ptr);
    }
    BN_free((BIGNUM *)(group + 8));
    BN_free((BIGNUM *)(group + 0x1c));
    if (*(void **)(group + 0x3c) != (void *)0x0) {
      CRYPTO_free(*(void **)(group + 0x3c));
    }
    CRYPTO_free(group);
    return;
  }
  return;
}

