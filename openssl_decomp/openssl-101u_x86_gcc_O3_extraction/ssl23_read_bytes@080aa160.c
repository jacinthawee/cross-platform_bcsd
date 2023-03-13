
uint ssl23_read_bytes(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2;
  if (*(uint *)(param_1 + 0x50) < param_2) {
    iVar1 = *(int *)(param_1 + 0x4c);
    uVar2 = *(uint *)(param_1 + 0x50);
    do {
      *(undefined4 *)(param_1 + 0x18) = 3;
      uVar2 = BIO_read(*(BIO **)(param_1 + 0xc),(void *)(uVar2 + iVar1),param_2 - uVar2);
      if ((int)uVar2 < 1) {
        return uVar2;
      }
      uVar2 = uVar2 + *(int *)(param_1 + 0x50);
      *(undefined4 *)(param_1 + 0x18) = 1;
      *(uint *)(param_1 + 0x50) = uVar2;
    } while (uVar2 < param_2);
  }
  return uVar2;
}

