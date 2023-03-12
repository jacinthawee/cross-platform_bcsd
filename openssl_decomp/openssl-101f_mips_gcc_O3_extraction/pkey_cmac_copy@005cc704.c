
bool pkey_cmac_copy(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (*(code *)PTR_CMAC_CTX_new_006aa638)();
  *(int *)(param_1 + 0x14) = iVar2;
  puVar1 = PTR_CMAC_CTX_copy_006aa628;
  if (iVar2 != 0) {
    uVar3 = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x24) = 0;
    iVar2 = (*(code *)puVar1)(iVar2,uVar3);
    return iVar2 != 0;
  }
  return false;
}

