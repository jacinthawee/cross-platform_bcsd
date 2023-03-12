
int ssl23_write_bytes(int param_1)

{
  int iVar1;
  int iVar2;
  int len;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x48);
  len = *(int *)(param_1 + 0x44);
  iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
  while( true ) {
    *(undefined4 *)(param_1 + 0x18) = 2;
    iVar2 = BIO_write(*(BIO **)(param_1 + 0x10),(void *)(iVar1 + iVar3),len);
    if (iVar2 < 1) {
      *(int *)(param_1 + 0x48) = iVar3;
      *(int *)(param_1 + 0x44) = len;
      return iVar2;
    }
    *(undefined4 *)(param_1 + 0x18) = 1;
    if (len == iVar2) break;
    len = len - iVar2;
    iVar3 = iVar3 + iVar2;
  }
  return iVar3 + len;
}

