
void mackey_free_gost(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1 + 0x14));
    return;
  }
  return;
}
