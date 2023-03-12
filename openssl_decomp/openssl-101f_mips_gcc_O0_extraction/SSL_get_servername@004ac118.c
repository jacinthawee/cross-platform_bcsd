
int SSL_get_servername(int param_1,int param_2)

{
  if (param_2 != 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0xc0) != 0) && (*(int *)(param_1 + 0x120) == 0)) {
    return *(int *)(*(int *)(param_1 + 0xc0) + 0xd0);
  }
  return *(int *)(param_1 + 0x120);
}

