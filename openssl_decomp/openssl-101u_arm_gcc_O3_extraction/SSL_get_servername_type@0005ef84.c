
undefined4 SSL_get_servername_type(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xc0) == 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0x120) != 0) {
    return 0;
  }
  uVar1 = 0xffffffff;
  if (*(int *)(*(int *)(param_1 + 0xc0) + 0xd0) != 0) {
    uVar1 = 0;
  }
  return uVar1;
}

