
uint ssl23_read_bytes(int param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0x50);
  if (param_2 <= uVar2) {
    return param_2;
  }
  iVar3 = *(int *)(param_1 + 0x4c);
  do {
    puVar1 = PTR_BIO_read_006a85bc;
    *(undefined4 *)(param_1 + 0x18) = 3;
    uVar2 = (*(code *)puVar1)(*(undefined4 *)(param_1 + 0xc),iVar3 + uVar2,param_2 - uVar2);
    if ((int)uVar2 < 1) {
      return uVar2;
    }
    *(undefined4 *)(param_1 + 0x18) = 1;
    uVar2 = uVar2 + *(int *)(param_1 + 0x50);
    *(uint *)(param_1 + 0x50) = uVar2;
  } while (uVar2 < param_2);
  return uVar2;
}

