
uint ssl23_read_bytes(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x50);
  if (param_2 <= uVar1) {
    return param_2;
  }
  iVar2 = *(int *)(param_1 + 0x4c);
  do {
    *(undefined4 *)(param_1 + 0x18) = 3;
    uVar1 = BIO_read(*(BIO **)(param_1 + 0xc),(void *)(iVar2 + uVar1),param_2 - uVar1);
    if ((int)uVar1 < 1) {
      return uVar1;
    }
    *(undefined4 *)(param_1 + 0x18) = 1;
    uVar1 = *(int *)(param_1 + 0x50) + uVar1;
    *(uint *)(param_1 + 0x50) = uVar1;
  } while (uVar1 < param_2);
  return uVar1;
}

