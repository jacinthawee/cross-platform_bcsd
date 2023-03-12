
int ssl_get_algorithm2(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x24);
  if (**(int **)(param_1 + 8) != 0x303) {
    return iVar1;
  }
  if (iVar1 == 0xc030) {
    iVar1 = 0x20080;
  }
  return iVar1;
}

