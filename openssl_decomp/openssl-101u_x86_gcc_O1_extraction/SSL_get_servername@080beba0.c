
int SSL_get_servername(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x120);
  if (*(int *)(param_1 + 0xc0) != 0) {
    if (*(int *)(param_1 + 0x120) != 0) {
      return iVar1;
    }
    return *(int *)(*(int *)(param_1 + 0xc0) + 0xd0);
  }
  return iVar1;
}

