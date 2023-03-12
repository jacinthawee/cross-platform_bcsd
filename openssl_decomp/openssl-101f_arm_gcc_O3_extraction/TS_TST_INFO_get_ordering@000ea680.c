
int TS_TST_INFO_get_ordering(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

