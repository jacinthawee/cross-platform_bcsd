
uint dsa_missing_parameters(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if ((*(int *)(iVar2 + 0xc) != 0) && (*(int *)(iVar2 + 0x10) != 0)) {
    uVar1 = count_leading_zeroes(*(undefined4 *)(iVar2 + 0x14));
    return uVar1 >> 5;
  }
  return 1;
}

