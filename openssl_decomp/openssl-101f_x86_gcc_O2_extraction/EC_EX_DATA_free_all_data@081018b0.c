
void EC_EX_DATA_free_all_data(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *ptr;
  
  if (param_1 != (undefined4 *)0x0) {
    ptr = (undefined4 *)*param_1;
    while (ptr != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*ptr;
      (*(code *)ptr[3])(ptr[1]);
      CRYPTO_free(ptr);
      ptr = puVar1;
    }
    *param_1 = 0;
  }
  return;
}

