
int ssl_get_ciphers_by_id(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x78) == 0) && (*(int *)(param_1 + 0xe4) != 0)) {
    return *(int *)(*(int *)(param_1 + 0xe4) + 8);
  }
  return *(int *)(param_1 + 0x78);
}

