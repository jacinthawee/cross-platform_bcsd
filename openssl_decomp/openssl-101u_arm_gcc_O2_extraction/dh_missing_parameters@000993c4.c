
uint dh_missing_parameters(int param_1)

{
  uint uVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x14) + 8) != 0) {
    uVar1 = count_leading_zeroes(*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xc));
    return uVar1 >> 5;
  }
  return 1;
}

