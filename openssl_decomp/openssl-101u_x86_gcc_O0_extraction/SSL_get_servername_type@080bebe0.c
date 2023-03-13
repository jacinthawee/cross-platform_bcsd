
int SSL_get_servername_type(int param_1)

{
  if (*(int *)(param_1 + 0xc0) == 0) {
    return -1;
  }
  if (*(int *)(param_1 + 0x120) != 0) {
    return 0;
  }
  return -(uint)(*(int *)(*(int *)(param_1 + 0xc0) + 0xd0) == 0);
}

