
undefined4 ssl_cipher_id_cmp(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) != *(int *)(param_2 + 8)) {
    uVar1 = 0xffffffff;
    if (0 < *(int *)(param_1 + 8) - *(int *)(param_2 + 8)) {
      uVar1 = 1;
    }
    return uVar1;
  }
  return 0;
}

