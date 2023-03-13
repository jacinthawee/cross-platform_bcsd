
bool dsa_missing_parameters(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if ((*(int *)(iVar1 + 0xc) != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
    return *(int *)(iVar1 + 0x14) == 0;
  }
  return true;
}

