
void by_dir_entry_free(void **param_1)

{
  if (*param_1 != (void *)0x0) {
    CRYPTO_free(*param_1);
  }
  if ((_STACK *)param_1[2] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)param_1[2],by_dir_hash_free);
  }
  CRYPTO_free(param_1);
  return;
}

