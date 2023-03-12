
int ssl23_write_bytes(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0x48);
  iVar3 = *(int *)(param_1 + 0x44);
  iVar5 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
  while( true ) {
    puVar1 = PTR_BIO_write_006a6e14;
    *(undefined4 *)(param_1 + 0x18) = 2;
    iVar2 = (*(code *)puVar1)(*(undefined4 *)(param_1 + 0x10),iVar5 + iVar4,iVar3);
    if (iVar2 < 1) {
      *(int *)(param_1 + 0x48) = iVar4;
      *(int *)(param_1 + 0x44) = iVar3;
      return iVar2;
    }
    *(undefined4 *)(param_1 + 0x18) = 1;
    if (iVar3 == iVar2) break;
    iVar3 = iVar3 - iVar2;
    iVar4 = iVar4 + iVar2;
  }
  return iVar4 + iVar3;
}

