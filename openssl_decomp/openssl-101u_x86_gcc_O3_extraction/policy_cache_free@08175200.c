
void policy_cache_free(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      policy_data_free(*param_1);
    }
    if ((_STACK *)param_1[1] != (_STACK *)0x0) {
      sk_pop_free((_STACK *)param_1[1],policy_data_free);
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

